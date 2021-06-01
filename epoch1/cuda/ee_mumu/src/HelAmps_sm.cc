//==========================================================================
// This file has been automatically generated for C++ Standalone by
// MadGraph5_aMC@NLO v. 2.8.2, 2020-10-30
// By the MadGraph5_aMC@NLO Development Team
// Visit launchpad.net/madgraph5 and amcatnlo.web.cern.ch
//==========================================================================

#include "mgOnGpuConfig.h"
#include "mgOnGpuTypes.h"
#include "mgOnGpuVectors.h"
#include "HelAmps_sm.h"

#include <cassert>
#include <cmath>
#include <cstdlib>
#include <iomanip>
#include <iostream>

mgDebugDeclare();

namespace MG5_sm
{
  // Decode momentum AOSOA: compute address of fptype for the given particle, 4-momentum component and event
  // Return the fptype by reference (equivalent to returning its memory address)
  __device__
  inline const fptype& pIparIp4Ievt( const fptype* momenta1d, // input: momenta as AOSOA[npagM][npar][4][neppM]
                                     const int ipar,
                                     const int ip4,
                                     const int ievt )
  {
    using mgOnGpu::np4;
    using mgOnGpu::npar;
    constexpr int neppM = mgOnGpu::neppM; // AOSOA layout: constant at compile-time
    const int ipagM = ievt/neppM; // #event "M-page"
    const int ieppM = ievt%neppM; // #event in the current event M-page
    //printf( "%f\n", momenta1d[ipagM*npar*np4*neppM + ipar*np4*neppM + ip4*neppM + ieppM] );
    return momenta1d[ipagM*npar*np4*neppM + ipar*np4*neppM + ip4*neppM + ieppM]; // AOSOA[ipagM][ipar][ip4][ieppM]
  }

#ifndef __CUDACC__
  // Return a SIMD vector of fptype's for neppV events (for the given particle, 4-momentum component and event "V-page")
  // Return the vector by value: strictly speaking, this is only unavoidable for neppM<neppV (will use "if constexpr")
  // For neppM>=neppV (both being powers of 2), the momentum neppM-AOSOA is reinterpreted in terms of neppV-vectors:
  // it could also be returned by reference, but no performance degradation is observed when returning by value
  inline fptype_sv pIparIp4Ipag( const fptype* momenta1d, // input: momenta as AOSOA[npagM][npar][4][neppM]
                                 const int ipar,
                                 const int ip4,
                                 const int ipagV )
  {
    const int ievt0 = ipagV*neppV; // virtual event V-page ipagV contains neppV events [ievt0...ievt0+neppV-1]
    return *reinterpret_cast<const fptype_sv*>( &( pIparIp4Ievt( momenta1d, ipar, ip4, ievt0 ) ) );
  }
#endif

  //--------------------------------------------------------------------------

  __device__
  void ixxxxx( const fptype* allmomenta,    // input[(npar=4)*(np4=4)*nevt]
               const fptype fmass,
               const int nhel,              // input: -1 or +1 (helicity of fermion)
               const int nsf,               // input: +1 (particle) or -1 (antiparticle)
               cxtype_sv* fi,               // output: wavefunction[(nw6==6)]
#ifndef __CUDACC__
               const int ipagV,
#endif
               const int ipar )             // input: particle# out of npar
  {
    mgDebug( 0, __FUNCTION__ );
    // +++ START EVENT LOOP (where necessary) +++
    {
#ifdef __CUDACC__
      const int ievt = blockDim.x * blockIdx.x + threadIdx.x; // index of event (thread) in grid
      //printf( "ixxxxx: ievt=%d threadId=%d\n", ievt, threadIdx.x );
      // AV: copying by value (not by ref) seems faster in cuda, in spite of more registers used
      // AV: copying by value (not by ref) seems irrelevant, or slightly slower, in c++
      const fptype pvec1 = pIparIp4Ievt( allmomenta, ipar, 1, ievt );
      const fptype pvec2 = pIparIp4Ievt( allmomenta, ipar, 2, ievt );
      const fptype pvec3 = pIparIp4Ievt( allmomenta, ipar, 3, ievt );
      //const fptype pvec0 = fpsqrt( pvec1 * pvec1 + pvec2 * pvec2 + pvec3 * pvec3 ); // AV: BUG?! (NOT AS IN THE FORTRAN)
      const fptype pvec0 = pIparIp4Ievt( allmomenta, ipar, 0, ievt ); // AV: BUG FIX (DO AS IN THE FORTRAN)
#else
      //printf( "ixxxxx: ipagV=%d\n", ipagV );
      const fptype_sv pvec0 = pIparIp4Ipag( allmomenta, ipar, 0, ipagV );
      const fptype_sv pvec1 = pIparIp4Ipag( allmomenta, ipar, 1, ipagV );
      const fptype_sv pvec2 = pIparIp4Ipag( allmomenta, ipar, 2, ipagV );
      const fptype_sv pvec3 = pIparIp4Ipag( allmomenta, ipar, 3, ipagV );
#endif
      fi[0] = cxmake( -pvec0 * (fptype)nsf, -pvec3 * (fptype)nsf );
      fi[1] = cxmake( -pvec1 * (fptype)nsf, -pvec2 * (fptype)nsf );
      const int nh = nhel * nsf;
      if ( fmass != 0. )
      {
        const fptype_sv pp = fpmin( pvec0, fpsqrt( pvec1 * pvec1 + pvec2 * pvec2 + pvec3 * pvec3 ) );
#ifndef MGONGPU_CPPSIMD
        if ( pp == 0. )
        {
          // NB: Do not use "abs" for floats! It returns an integer with no build warning! Use std::abs!
          fptype sqm[2] = { fpsqrt( std::abs( fmass ) ), 0. }; // possibility of negative fermion masses
          //sqm[1] = ( fmass < 0. ? -abs( sqm[0] ) : abs( sqm[0] ) ); // AV: why abs here?
          sqm[1] = ( fmass < 0. ? -sqm[0] : sqm[0] ); // AV: removed an abs here
          const int ip = ( 1 + nh ) / 2; // NB: Fortran sqm(0:1) also has indexes 0,1 as in C++
          const int im = ( 1 - nh ) / 2; // NB: Fortran sqm(0:1) also has indexes 0,1 as in C++
          fi[2] = cxmake( ip * sqm[ip], 0 );          
          fi[3] = cxmake( im * nsf * sqm[ip], 0 );
          fi[4] = cxmake( ip * nsf * sqm[im], 0 );
          fi[5] = cxmake( im * sqm[im], 0 );
        }
        else
        {
          const fptype sf[2] = { fptype( 1 + nsf + ( 1 - nsf ) * nh ) * (fptype)0.5,
                                 fptype( 1 + nsf - ( 1 - nsf ) * nh ) * (fptype)0.5 };
          fptype omega[2] = { fpsqrt( pvec0 + pp ), 0. };
          omega[1] = fmass / omega[0];
          const int ip = ( 1 + nh ) / 2; // NB: Fortran is (3+nh)/2 because omega(2) has indexes 1,2 and not 0,1
          const int im = ( 1 - nh ) / 2; // NB: Fortran is (3-nh)/2 because omega(2) has indexes 1,2 and not 0,1
          const fptype sfomega[2] = { sf[0] * omega[ip], sf[1] * omega[im] };
          const fptype pp3 = fpmax( pp + pvec3, 0. );
          const cxtype chi[2] = { cxmake( fpsqrt ( pp3 * (fptype)0.5 / pp ), 0. ),
                                  ( pp3 == 0. ?
                                    cxmake( -nh, 0. ) :
                                    cxmake( nh * pvec1, pvec2 ) / fpsqrt( 2. * pp * pp3 ) ) };
          fi[2] = sfomega[0] * chi[im];
          fi[3] = sfomega[0] * chi[ip];
          fi[4] = sfomega[1] * chi[im];
          fi[5] = sfomega[1] * chi[ip];
        }
#else
        const int ip = ( 1 + nh ) / 2;
        const int im = ( 1 - nh ) / 2;
        // Branch A: pp == 0.
        // NB: Do not use "abs" for floats! It returns an integer with no build warning! Use std::abs!
        fptype sqm[2] = { fpsqrt( std::abs( fmass ) ), 0 }; // possibility of negative fermion masses (NB: SCALAR!)
        sqm[1] = ( fmass < 0 ? -sqm[0] : sqm[0] ); // AV: removed an abs here (as above)
        const cxtype fiA_2 = ip * sqm[ip]; // scalar cxtype: real part initialised from fptype, imag part = 0
        const cxtype fiA_3 = im * nsf * sqm[ip]; // scalar cxtype: real part initialised from fptype, imag part = 0
        const cxtype fiA_4 = ip * nsf * sqm[im]; // scalar cxtype: real part initialised from fptype, imag part = 0
        const cxtype fiA_5 = im * sqm[im]; // scalar cxtype: real part initialised from fptype, imag part = 0
        // Branch B: pp != 0.
        const fptype sf[2] = { fptype( 1 + nsf + ( 1 - nsf ) * nh ) * (fptype)0.5,
                               fptype( 1 + nsf - ( 1 - nsf ) * nh ) * (fptype)0.5 };
        fptype_v omega[2] = { fpsqrt( pvec0 + pp ), 0 };
        omega[1] = fmass / omega[0];
        const fptype_v sfomega[2] = { sf[0] * omega[ip], sf[1] * omega[im] };
        const fptype_v pp3 = fpmax( pp + pvec3, 0 );
        const cxtype_v chi[2] = { cxmake( fpsqrt ( pp3 * 0.5 / pp ), 0 ),
                                  cxternary( ( pp3 == 0. ),
                                             cxmake( -nh, 0 ),
                                             cxmake( (fptype)nh * pvec1, pvec2 ) / fpsqrt( 2. * pp * pp3 ) ) };
        const cxtype_v fiB_2 = sfomega[0] * chi[im];
        const cxtype_v fiB_3 = sfomega[0] * chi[ip];
        const cxtype_v fiB_4 = sfomega[1] * chi[im];
        const cxtype_v fiB_5 = sfomega[1] * chi[ip];
        // Choose between the results from branch A and branch B
        const bool_v mask = ( pp == 0. );
        fi[2] = cxternary( mask, fiA_2, fiB_2 );
        fi[3] = cxternary( mask, fiA_3, fiB_3 );
        fi[4] = cxternary( mask, fiA_4, fiB_4 );
        fi[5] = cxternary( mask, fiA_5, fiB_5 );
#endif
      }
      else
      {
        const fptype_sv sqp0p3 = fpternary( ( pvec1 == 0. and pvec2 == 0. and pvec3 < 0. ),
                                            fptype_sv{0}, fpsqrt( fpmax( pvec0 + pvec3, 0. ) ) * (fptype)nsf );
        const cxtype_sv chi[2] = { cxmake( sqp0p3, 0. ), cxternary( ( sqp0p3 == 0. ),
                                                                    cxmake( -(fptype)nhel * fpsqrt( 2. * pvec0 ), 0. ),
                                                                    cxmake( (fptype)nh * pvec1, pvec2 ) / sqp0p3 ) };
        if ( nh == 1 )
        {
          fi[2] = cxzero_sv();
          fi[3] = cxzero_sv();
          fi[4] = chi[0];
          fi[5] = chi[1];
        }
        else
        {
          fi[2] = chi[1];
          fi[3] = chi[0];
          fi[4] = cxzero_sv();
          fi[5] = cxzero_sv();
        }
      }
    }
    // +++ END EVENT LOOP (where necessary) +++
    mgDebug( 1, __FUNCTION__ );
    return;
  }

  //--------------------------------------------------------------------------

  __device__
  void ipzxxx( const fptype* allmomenta,    // input[(npar=4)*(np4=4)*nevt]
               //const fptype fmass,        // ASSUME fmass==0
               const int nhel,              // input: -1 or +1 (helicity of fermion)
               const int nsf,               // input: +1 (particle) or -1 (antiparticle)
               cxtype_sv* fi,               // output: wavefunction[(nw6==6)]
#ifndef __CUDACC__
               const int ipagV,
#endif
               const int ipar )             // input: particle# out of npar
  {
    // ASSUMPTIONS: (FMASS == 0) and (PX == PY == 0 and E == +PZ > 0)
    mgDebug( 0, __FUNCTION__ );
    // +++ START EVENT LOOP (where necessary) +++
    {
#ifdef __CUDACC__
      const int ievt = blockDim.x * blockIdx.x + threadIdx.x; // index of event (thread) in grid
      //printf( "ipzxxx: ievt=%d threadId=%d\n", ievt, threadIdx.x );
      // AV: copy by value (not by ref) as this seems faster in cuda for other functions
      const fptype pvec3 = pIparIp4Ievt( allmomenta, ipar, 3, ievt );
#else
      //printf( "ipzxxx: ipagV=%d\n", ipagV );
      const fptype_sv pvec3 = pIparIp4Ipag( allmomenta, ipar, 3, ipagV );
#endif
      fi[0] = cxmake( -pvec3 * (fptype)nsf, -pvec3 * (fptype)nsf );
      fi[1] = cxzero_sv();
      const int nh = nhel * nsf;
      const cxtype_sv sqp0p3 = cxmake( fpsqrt( 2. * pvec3 ) * (fptype)nsf, 0. );
      fi[2] = fi[1];
      if( nh == 1 )
      {
        fi[3] = fi[1];
        fi[4] = sqp0p3;
      }
      else
      {
        fi[3] = sqp0p3;
        fi[4] = fi[1];
      }
      fi[5] = fi[1];
    }
    // +++ END EVENT LOOP (where necessary) +++
    mgDebug( 1, __FUNCTION__ );
    return;
  }

  //--------------------------------------------------------------------------

  __device__
  void imzxxx( const fptype* allmomenta,    // input[(npar=4)*(np4=4)*nevt]
               //const fptype fmass,        // ASSUME fmass==0
               const int nhel,              // input: -1 or +1 (helicity of fermion)
               const int nsf,               // input: +1 (particle) or -1 (antiparticle)
               cxtype_sv* fi,               // output: wavefunction[(nw6==6)]
#ifndef __CUDACC__
               const int ipagV,
#endif
               const int ipar )             // input: particle# out of npar
  {
    // ASSUMPTIONS: (FMASS == 0) and (PX == PY == 0 and E == -PZ > 0)
    mgDebug( 0, __FUNCTION__ );
    // +++ START EVENT LOOP (where necessary) +++
    {
#ifdef __CUDACC__
      const int ievt = blockDim.x * blockIdx.x + threadIdx.x; // index of event (thread) in grid
      //printf( "imzxxx: ievt=%d threadId=%d\n", ievt, threadIdx.x );
      // AV: copying by value (not by ref) seems to give the same performance in both cuda and c++
      const fptype pvec3 = pIparIp4Ievt( allmomenta, ipar, 3, ievt );
#else
      //printf( "imzxxx: ipagV=%d\n", ipagV );
      const fptype_sv pvec3 = pIparIp4Ipag( allmomenta, ipar, 3, ipagV );
#endif
      fi[0] = cxmake( pvec3 * (fptype)nsf, -pvec3 * (fptype)nsf );
      fi[1] = cxzero_sv();
      const int nh = nhel * nsf;
      const cxtype_sv chi = cxmake( -(fptype)nhel * fpsqrt( -2. * pvec3 ), 0. );
      fi[3] = cxzero_sv();
      fi[4] = cxzero_sv();
      if ( nh == 1 )
      {
        fi[2] = cxzero_sv();
        fi[5] = chi;
      }
      else
      {
        fi[2] = chi;
        fi[5] = cxzero_sv();
      }
    }
    // +++ END EVENT LOOP (where necessary) +++
    mgDebug( 1, __FUNCTION__ );
    return;
  }

  //--------------------------------------------------------------------------

  __device__
  void ixzxxx( const fptype* allmomenta,    // input[(npar=4)*(np4=4)*nevt]
               //const fptype fmass,        // ASSUME fmass==0
               const int nhel,              // input: -1 or +1 (helicity of fermion)
               const int nsf,               // input: +1 (particle) or -1 (antiparticle)
               cxtype_sv* fi,               // output: wavefunction[(nw6==6)]
#ifndef __CUDACC__
               const int ipagV,
#endif
               const int ipar )             // input: particle# out of npar
  {
    // ASSUMPTIONS: (FMASS == 0) and (PT > 0)
    mgDebug( 0, __FUNCTION__ );
    // +++ START EVENT LOOP (where necessary) +++
    {
#ifdef __CUDACC__
      const int ievt = blockDim.x * blockIdx.x + threadIdx.x; // index of event (thread) in grid
      //printf( "ixzxxx: ievt=%d threadId=%d\n", ievt, threadIdx.x );
      // AV: copying by value (not by ref) seems to give the same performance in both cuda and c++
      const fptype pvec0 = pIparIp4Ievt( allmomenta, ipar, 0, ievt );
      const fptype pvec1 = pIparIp4Ievt( allmomenta, ipar, 1, ievt );
      const fptype pvec2 = pIparIp4Ievt( allmomenta, ipar, 2, ievt );
      const fptype pvec3 = pIparIp4Ievt( allmomenta, ipar, 3, ievt );
#else
      //printf( "ixzxxx: ipagV=%d\n", ipagV );
      const fptype_sv pvec0 = pIparIp4Ipag( allmomenta, ipar, 0, ipagV );
      const fptype_sv pvec1 = pIparIp4Ipag( allmomenta, ipar, 1, ipagV );
      const fptype_sv pvec2 = pIparIp4Ipag( allmomenta, ipar, 2, ipagV );
      const fptype_sv pvec3 = pIparIp4Ipag( allmomenta, ipar, 3, ipagV );
#endif
      //fi[0] = cxmake( -pvec0 * nsf, -pvec2 * nsf ); // AV: BUG! not the same as ixxxxx
      //fi[1] = cxmake( -pvec0 * nsf, -pvec1 * nsf ); // AV: BUG! not the same as ixxxxx
      fi[0] = cxmake( -pvec0 * (fptype)nsf, -pvec3 * (fptype)nsf ); // AV: BUG FIX
      fi[1] = cxmake( -pvec1 * (fptype)nsf, -pvec2 * (fptype)nsf ); // AV: BUG FIX
      const int nh = nhel * nsf;
      //const float sqp0p3 = sqrtf( pvec0 + pvec3 ) * nsf; // AV: why force a float here?
      const fptype_sv sqp0p3 = fpsqrt( pvec0 + pvec3 ) * (fptype)nsf;
      const cxtype_sv chi0 = cxmake( sqp0p3, 0. );
      const cxtype_sv chi1 = cxmake( (fptype)nh * pvec1/sqp0p3, pvec2/sqp0p3 );
      if ( nh == 1 )
      {
        fi[2] = cxzero_sv();
        fi[3] = cxzero_sv();
        fi[4] = chi0;
        fi[5] = chi1;
      }
      else
      {
        fi[2] = chi1;
        fi[3] = chi0;
        fi[4] = cxzero_sv();
        fi[5] = cxzero_sv();
      }
    }
    // +++ END EVENT LOOP (where necessary) +++
    mgDebug( 1, __FUNCTION__ );
    return;
  }

  //--------------------------------------------------------------------------

  __device__
  void vxxxxx( const fptype* allmomenta,    // input[(npar=4)*(np4=4)*nevt]
               const fptype vmass,
               const int nhel,              // input: -1, 0 (only if vmass!=0) or +1 (helicity of vector boson)
               const int nsv,               // input: +1 (final) or -1 (initial)
               cxtype_sv* vc,               // output: wavefunction[(nw6==6)]
#ifndef __CUDACC__
               const int ipagV,
#endif
               const int ipar )             // input: particle# out of npar
  {
    mgDebug( 0, __FUNCTION__ );
    // +++ START EVENT LOOP (where necessary) +++
    {
#ifdef __CUDACC__
      const int ievt = blockDim.x * blockIdx.x + threadIdx.x; // index of event (thread) in grid
      //printf( "vxxxxx: ievt=%d threadId=%d\n", ievt, threadIdx.x );
      // AV: copy by value (not by ref) as this seems faster in cuda for other functions
      const fptype pvec0 = pIparIp4Ievt( allmomenta, ipar, 0, ievt );
      const fptype pvec1 = pIparIp4Ievt( allmomenta, ipar, 1, ievt );
      const fptype pvec2 = pIparIp4Ievt( allmomenta, ipar, 2, ievt );
      const fptype pvec3 = pIparIp4Ievt( allmomenta, ipar, 3, ievt );
#else
      //printf( "vxxxxx: ipagV=%d\n", ipagV );
      const fptype_sv pvec0 = pIparIp4Ipag( allmomenta, ipar, 0, ipagV );
      const fptype_sv pvec1 = pIparIp4Ipag( allmomenta, ipar, 1, ipagV );
      const fptype_sv pvec2 = pIparIp4Ipag( allmomenta, ipar, 2, ipagV );
      const fptype_sv pvec3 = pIparIp4Ipag( allmomenta, ipar, 3, ipagV );
#endif
      const fptype sqh = fpsqrt( 0.5 ); // AV this is > 0!
      const fptype hel = nhel;
      vc[0] = cxmake( pvec0 * (fptype)nsv, pvec3 * (fptype)nsv );
      vc[1] = cxmake( pvec1 * (fptype)nsv, pvec2 * (fptype)nsv );
      if ( vmass != 0. )
      {
        const int nsvahl = nsv * std::abs( hel );
        const fptype_sv pt2 = ( pvec1 * pvec1 ) + ( pvec2 * pvec2 );
        const fptype_sv pp = fpmin( pvec0, fpsqrt( pt2 + ( pvec3 * pvec3 ) ) );
        const fptype_sv pt = fpmin( pp, fpsqrt( pt2 ) );
        const fptype hel0 = 1. - std::abs( hel );
#ifndef MGONGPU_CPPSIMD
        if ( pp == 0. )
        {
          vc[2] = cxmake( 0., 0. );
          vc[3] = cxmake( -hel * sqh, 0. );
          vc[4] = cxmake( 0., nsvahl * sqh );
          vc[5] = cxmake( hel0, 0. );
        }
        else
        {
          const fptype emp = pvec0 / ( vmass * pp );
          vc[2] = cxmake( hel0 * pp / vmass, 0. );
          vc[5] = cxmake( hel0 * pvec3 * emp + hel * pt / pp * sqh, 0. );
          if ( pt != 0. )
          {
            const fptype pzpt = pvec3 / ( pp * pt ) * sqh * hel;
            vc[3] = cxmake( hel0 * pvec1 * emp - pvec1 * pzpt, -nsvahl * pvec2 / pt * sqh );
            vc[4] = cxmake( hel0 * pvec2 * emp - pvec2 * pzpt, nsvahl * pvec1 / pt * sqh );
          }
          else
          {
            vc[3] = cxmake( -hel * sqh, 0. );
            // NB: Do not use "abs" for floats! It returns an integer with no build warning! Use std::abs!
            //vc[4] = cxmake( 0., nsvahl * ( pvec3 < 0. ? -std::abs( sqh ) : std::abs( sqh ) ) ); // AV: why abs here?
            vc[4] = cxmake( 0., nsvahl * ( pvec3 < 0. ? -sqh : sqh ) ); // AV: removed an abs here
          }
        }
#else
        // Branch A: pp == 0.
        const cxtype vcA_2 = cxmake( 0, 0 );
        const cxtype vcA_3 = cxmake( -hel * sqh, 0 );
        const cxtype vcA_4 = cxmake( 0, nsvahl * sqh );
        const cxtype vcA_5 = cxmake( hel0, 0 );
        // Branch B: pp != 0.
        const fptype_v emp = pvec0 / ( vmass * pp );
        const cxtype_v vcB_2 = cxmake( hel0 * pp / vmass, 0 );
        const cxtype_v vcB_5 = cxmake( hel0 * pvec3 * emp + hel * pt / pp * sqh, 0 );
        // Branch B1: pp != 0. and pt != 0.
        const fptype_v pzpt = pvec3 / ( pp * pt ) * sqh * hel;
        const cxtype_v vcB1_3 = cxmake( hel0 * pvec1 * emp - pvec1 * pzpt, -(fptype)nsvahl * pvec2 / pt * sqh );
        const cxtype_v vcB1_4 = cxmake( hel0 * pvec2 * emp - pvec2 * pzpt, (fptype)nsvahl * pvec1 / pt * sqh );
        // Branch B2: pp != 0. and pt == 0.
        const cxtype vcB2_3 = cxmake( -hel * sqh, 0. );
        const cxtype_v vcB2_4 = cxmake( 0., (fptype)nsvahl * fpternary( ( pvec3 < 0 ), -sqh, sqh ) ); // AV: removed an abs here
        // Choose between the results from branch A and branch B (and from branch B1 and branch B2)
        const bool_v mask = ( pp == 0. );
        const bool_v maskB = ( pt != 0. );
        vc[2] = cxternary( mask, vcA_2, vcB_2 );
        vc[3] = cxternary( mask, vcA_3, cxternary( maskB, vcB1_3, vcB2_3 ) );
        vc[4] = cxternary( mask, vcA_4, cxternary( maskB, vcB1_4, vcB2_4 ) );
        vc[5] = cxternary( mask, vcA_5, vcB_5 );
#endif
      }
      else
      {
        const fptype_sv& pp = pvec0; // NB: rewrite the following  as in Fortran, using pp instead of pvec0
        const fptype_sv pt = fpsqrt( ( pvec1 * pvec1 ) + ( pvec2 * pvec2 ) );
        vc[2] = cxzero_sv();
        vc[5] = cxmake( hel * pt / pp * sqh, 0. );
#ifndef MGONGPU_CPPSIMD
        if ( pt != 0. )
        {
          const fptype pzpt = pvec3 / ( pp * pt ) * sqh * hel;
          vc[3] = cxmake( -pvec1 * pzpt, -nsv * pvec2 / pt * sqh );
          vc[4] = cxmake( -pvec2 * pzpt, nsv * pvec1 / pt * sqh );
        }
        else
        {
          vc[3] = cxmake( -hel * sqh, 0. );
          // NB: Do not use "abs" for floats! It returns an integer with no build warning! Use std::abs!
          //vc[4] = cxmake( 0, nsv * ( pvec3 < 0. ? -std::abs( sqh ) : std::abs( sqh ) ) ); // AV why abs here?
          vc[4] = cxmake( 0., nsv * ( pvec3 < 0. ? -sqh : sqh ) ); // AV: removed an abs here
        }
#else
        // Branch A: pt != 0.
        const fptype_v pzpt = pvec3 / ( pp * pt ) * sqh * hel;
        const cxtype_v vcA_3 = cxmake( -pvec1 * pzpt, -(fptype)nsv * pvec2 / pt * sqh );
        const cxtype_v vcA_4 = cxmake( -pvec2 * pzpt, (fptype)nsv * pvec1 / pt * sqh );
        // Branch B: pt == 0.
        const cxtype vcB_3 = cxmake( -(fptype)hel * sqh, 0 );
        const cxtype_v vcB_4 = cxmake( 0, (fptype)nsv * fpternary( ( pvec3 < 0 ), -sqh, sqh ) ); // AV: removed an abs here
        // Choose between the results from branch A and branch B
        const bool_v mask = ( pt != 0. );
        vc[3] = cxternary( mask, vcA_3, vcB_3 );
        vc[4] = cxternary( mask, vcA_4, vcB_4 );
#endif
      }
    }
    // +++ END EVENT LOOP (where necessary) +++
    mgDebug( 1, __FUNCTION__ );
    return;
  }

  //--------------------------------------------------------------------------

  __device__
  void sxxxxx( const fptype* allmomenta,    // input[(npar=4)*(np4=4)*nevt]
               const fptype,                // WARNING: "smass" unused (missing in Fortran)
               const int,                   // WARNING: "nhel" unused (missing in Fortran) - scalar has no helicity
               const int nss,               // input: +1 (final) or -1 (initial)
               cxtype_sv sc[3],             // output: wavefunction[3] - not [6], this is for scalars
#ifndef __CUDACC__
               const int ipagV,
#endif
               const int ipar )             // input: particle# out of npar
  {
    mgDebug( 0, __FUNCTION__ );
    // +++ START EVENT LOOP (where necessary) +++
    {
#ifdef __CUDACC__
      const int ievt = blockDim.x * blockIdx.x + threadIdx.x; // index of event (thread) in grid
      //printf( "sxxxxx: ievt=%d threadId=%d\n", ievt, threadIdx.x );
      // AV: copy by value (not by ref) as this seems faster in cuda for other functions
      const fptype pvec0 = pIparIp4Ievt( allmomenta, ipar, 0, ievt );
      const fptype pvec1 = pIparIp4Ievt( allmomenta, ipar, 1, ievt );
      const fptype pvec2 = pIparIp4Ievt( allmomenta, ipar, 2, ievt );
      const fptype pvec3 = pIparIp4Ievt( allmomenta, ipar, 3, ievt );
#else
      //printf( "sxxxxx: ipagV=%d\n", ipagV );
      const fptype_sv pvec0 = pIparIp4Ipag( allmomenta, ipar, 0, ipagV );
      const fptype_sv pvec1 = pIparIp4Ipag( allmomenta, ipar, 1, ipagV );
      const fptype_sv pvec2 = pIparIp4Ipag( allmomenta, ipar, 2, ipagV );
      const fptype_sv pvec3 = pIparIp4Ipag( allmomenta, ipar, 3, ipagV );
#endif
      sc[2] = cxmake( 1 + fptype_sv{0}, 0 );
      sc[0] = cxmake( pvec0 * (fptype)nss, pvec3 * (fptype)nss );
      sc[1] = cxmake( pvec1 * (fptype)nss, pvec2 * (fptype)nss );
    }
    // +++ END EVENT LOOP (where necessary) +++
    mgDebug( 1, __FUNCTION__ );
    return;
  }

  //--------------------------------------------------------------------------

  __device__
  void oxxxxx( const fptype* allmomenta,    // input[(npar=4)*(np4=4)*nevt]
               const fptype fmass,
               const int nhel,              // input: -1 or +1 (helicity of fermion)
               const int nsf,               // input: +1 (particle) or -1 (antiparticle)
               cxtype_sv* fo,               // output: wavefunction[(nw6==6)]
#ifndef __CUDACC__
               const int ipagV,
#endif
               const int ipar )             // input: particle# out of npar
  {
    mgDebug( 0, __FUNCTION__ );
    // +++ START EVENT LOOP (where necessary) +++
    {
#ifdef __CUDACC__
      const int ievt = blockDim.x * blockIdx.x + threadIdx.x; // index of event (thread) in grid
      //printf( "oxxxxx: ievt=%d threadId=%d\n", ievt, threadIdx.x );
      // AV: copying by value (not by ref) seems faster in cuda, in spite of more registers used
      // AV: copying by value (not by ref) seems irrelevant, or slightly faster, in c++
      const fptype pvec0 = pIparIp4Ievt( allmomenta, ipar, 0, ievt );
      const fptype pvec1 = pIparIp4Ievt( allmomenta, ipar, 1, ievt );
      const fptype pvec2 = pIparIp4Ievt( allmomenta, ipar, 2, ievt );
      const fptype pvec3 = pIparIp4Ievt( allmomenta, ipar, 3, ievt );
#else
      //printf( "oxxxxx: ipagV=%d\n", ipagV );
      const fptype_sv pvec0 = pIparIp4Ipag( allmomenta, ipar, 0, ipagV );
      const fptype_sv pvec1 = pIparIp4Ipag( allmomenta, ipar, 1, ipagV );
      const fptype_sv pvec2 = pIparIp4Ipag( allmomenta, ipar, 2, ipagV );
      const fptype_sv pvec3 = pIparIp4Ipag( allmomenta, ipar, 3, ipagV );
#endif
      fo[0] = cxmake( pvec0 * (fptype)nsf, pvec3 * (fptype)nsf );
      fo[1] = cxmake( pvec1 * (fptype)nsf, pvec2 * (fptype)nsf );
      const int nh = nhel * nsf;
      if ( fmass != 0. )
      {
        const fptype_sv pp = fpmin( pvec0, fpsqrt( ( pvec1 * pvec1 ) + ( pvec2 * pvec2 ) + ( pvec3 * pvec3 ) ) );
#ifndef MGONGPU_CPPSIMD
        if ( pp == 0. )
        {
          // NB: Do not use "abs" for floats! It returns an integer with no build warning! Use std::abs!
          fptype sqm[2] = { fpsqrt( std::abs( fmass ) ), 0. }; // possibility of negative fermion masses
          //sqm[1] = ( fmass < 0. ? -abs( sqm[0] ) : abs( sqm[0] ) ); // AV: why abs here?
          sqm[1] = ( fmass < 0. ? -sqm[0] : sqm[0] ); // AV: removed an abs here
          const int ip = -( ( 1 - nh ) / 2 ) * nhel; // NB: Fortran sqm(0:1) also has indexes 0,1 as in C++
          const int im = ( 1 + nh ) / 2 * nhel; // NB: Fortran sqm(0:1) also has indexes 0,1 as in C++
          fo[2] = cxmake( im * sqm[std::abs( ip )], 0 );
          fo[3] = cxmake( ip * nsf * sqm[std::abs( ip )], 0 );
          fo[4] = cxmake( im * nsf * sqm[std::abs( im )], 0 );
          fo[5] = cxmake( ip * sqm[std::abs( im )], 0 );
        }
        else
        {
          const fptype sf[2] = { fptype( 1 + nsf + ( 1 - nsf ) * nh ) * (fptype)0.5,
                                 fptype( 1 + nsf - ( 1 - nsf ) * nh ) * (fptype)0.5 };
          fptype omega[2] = { fpsqrt( pvec0 + pp ), 0. };
          omega[1] = fmass / omega[0];
          const int ip = ( 1 + nh ) / 2; // NB: Fortran is (3+nh)/2 because omega(2) has indexes 1,2 and not 0,1
          const int im = ( 1 - nh ) / 2; // NB: Fortran is (3-nh)/2 because omega(2) has indexes 1,2 and not 0,1
          const fptype sfomeg[2] = { sf[0] * omega[ip], sf[1] * omega[im] };
          const fptype pp3 = fpmax( pp + pvec3, 0. );
          const cxtype chi[2] = { cxmake( fpsqrt( pp3 * (fptype)0.5 / pp ), 0. ),
                                  ( ( pp3 == 0. ) ? cxmake( -nh, 0. )
                                    : cxmake( nh * pvec1, -pvec2 ) / fpsqrt( 2. * pp * pp3 ) ) };
          fo[2] = sfomeg[1] * chi[im];
          fo[3] = sfomeg[1] * chi[ip];
          fo[4] = sfomeg[0] * chi[im];
          fo[5] = sfomeg[0] * chi[ip];
        }
#else
        // Branch A: pp == 0.
        // NB: Do not use "abs" for floats! It returns an integer with no build warning! Use std::abs!
        fptype sqm[2] = { fpsqrt( std::abs( fmass ) ), 0 }; // possibility of negative fermion masses
        sqm[1] = ( fmass < 0 ? -sqm[0] : sqm[0] ); // AV: removed an abs here (as above)
        const int ipA = -( ( 1 - nh ) / 2 ) * nhel;
        const int imA = ( 1 + nh ) / 2 * nhel;
        const cxtype foA_2 = imA * sqm[std::abs( ipA )];
        const cxtype foA_3 = ipA * nsf * sqm[std::abs( ipA )];
        const cxtype foA_4 = imA * nsf * sqm[std::abs( imA )];
        const cxtype foA_5 = ipA * sqm[std::abs( imA )];
        // Branch B: pp != 0.
        const fptype sf[2] = { fptype( 1 + nsf + ( 1 - nsf ) * nh ) * (fptype)0.5,
                               fptype( 1 + nsf - ( 1 - nsf ) * nh ) * (fptype)0.5 };
        fptype_v omega[2] = { fpsqrt( pvec0 + pp ), 0 };
        omega[1] = fmass / omega[0];
        const int ipB = ( 1 + nh ) / 2;
        const int imB = ( 1 - nh ) / 2;
        const fptype_v sfomeg[2] = { sf[0] * omega[ipB], sf[1] * omega[imB] };
        const fptype_v pp3 = fpmax( pp + pvec3, 0. );
        const cxtype_v chi[2] = { cxmake( fpsqrt( pp3 * 0.5 / pp ), 0. ),
                                  ( cxternary( ( pp3 == 0. ),
                                               cxmake( -nh, 0. ),
                                               cxmake( (fptype)nh * pvec1, -pvec2 ) / fpsqrt( 2. * pp * pp3 ) ) ) };
        const cxtype_v foB_2 = sfomeg[1] * chi[imB];
        const cxtype_v foB_3 = sfomeg[1] * chi[ipB];
        const cxtype_v foB_4 = sfomeg[0] * chi[imB];
        const cxtype_v foB_5 = sfomeg[0] * chi[ipB];
        // Choose between the results from branch A and branch B
        const bool_v mask = ( pp == 0. );
        fo[2] = cxternary( mask, foA_2, foB_2 );
        fo[3] = cxternary( mask, foA_3, foB_3 );
        fo[4] = cxternary( mask, foA_4, foB_4 );
        fo[5] = cxternary( mask, foA_5, foB_5 );
#endif
      }
      else
      {
        const fptype_sv sqp0p3 = fpternary( ( pvec1 == 0. ) and ( pvec2 == 0. ) and ( pvec3 < 0. ),
                                            0, fpsqrt( fpmax( pvec0 + pvec3, 0. ) ) * (fptype)nsf );
        const cxtype_sv chi[2] = { cxmake( sqp0p3, 0. ),
                                   cxternary( ( sqp0p3 == 0. ),
                                              cxmake( -nhel, 0. ) * fpsqrt( 2. * pvec0 ),
                                              cxmake( (fptype)nh * pvec1, -pvec2 ) / sqp0p3 ) };
        if ( nh == 1 )
        {
          fo[2] = chi[0];
          fo[3] = chi[1];
          fo[4] = cxzero_sv();
          fo[5] = cxzero_sv();
        }
        else
        {
          fo[2] = cxzero_sv();
          fo[3] = cxzero_sv();
          fo[4] = chi[1];
          fo[5] = chi[0];
        }
      }
    }
    // +++ END EVENT LOOP (where necessary) +++
    mgDebug( 1, __FUNCTION__ );
    return;
  }

  //--------------------------------------------------------------------------

  __device__
  void opzxxx( const fptype* allmomenta,    // input[(npar=4)*(np4=4)*nevt]
               const int nhel,              // input: -1 or +1 (helicity of fermion)
               const int nsf,               // input: +1 (particle) or -1 (antiparticle)
               cxtype_sv* fo,               // output: wavefunction[(nw6==6)]
#ifndef __CUDACC__
               const int ipagV,
#endif
               const int ipar )             // input: particle# out of npar
  {
    // ASSUMPTIONS: (FMASS == 0) and (PX == PY == 0 and E == +PZ > 0)
    mgDebug( 0, __FUNCTION__ );
    // +++ START EVENT LOOP (where necessary) +++
    {
#ifdef __CUDACC__
      const int ievt = blockDim.x * blockIdx.x + threadIdx.x; // index of event (thread) in grid
      //printf( "opzxxx: ievt=%d threadId=%d\n", ievt, threadIdx.x );
      // AV: copying by value (not by ref) seems to give the same performance in both cuda and c++
      const fptype pvec3 = pIparIp4Ievt( allmomenta, ipar, 3, ievt );
#else
      //printf( "opzxxx: ipagV=%d\n", ipagV );
      const fptype_sv pvec3 = pIparIp4Ipag( allmomenta, ipar, 3, ipagV );
#endif
      fo[0] = cxmake( pvec3 * (fptype)nsf, pvec3 * (fptype)nsf );
      fo[1] = cxzero_sv();
      const int nh = nhel * nsf;
      const cxtype_sv csqp0p3 = cxmake( fpsqrt( 2. * pvec3 ) * (fptype)nsf, 0. );
      fo[3] = cxzero_sv();
      fo[4] = cxzero_sv();
      if ( nh == 1 )
      {
        fo[2] = csqp0p3;
        fo[5] = cxzero_sv();
      }
      else
      {
        fo[2] = cxzero_sv();
        fo[5] = csqp0p3;
      }
    }
    // +++ END EVENT LOOP (where necessary) +++
    mgDebug( 1, __FUNCTION__ );
    return;
  }

  //--------------------------------------------------------------------------

  __device__
  void omzxxx( const fptype* allmomenta,    // input[(npar=4)*(np4=4)*nevt]
               const int nhel,              // input: -1 or +1 (helicity of fermion)
               const int nsf,               // input: +1 (particle) or -1 (antiparticle)
               cxtype_sv* fo,               // output: wavefunction[(nw6==6)]
#ifndef __CUDACC__
               const int ipagV,
#endif
               const int ipar )             // input: particle# out of npar
  {
    // ASSUMPTIONS: (FMASS == 0) and (PX == PY == 0 and E == -PZ > 0)
    mgDebug( 0, __FUNCTION__ );
    // +++ START EVENT LOOP (where necessary) +++
    {
#ifdef __CUDACC__
      const int ievt = blockDim.x * blockIdx.x + threadIdx.x; // index of event (thread) in grid
      //printf( "ipzxxx: ievt=%d threadId=%d\n", ievt, threadIdx.x );
      // AV: copy by value (not by ref) as this seems faster in cuda for other functions
      const fptype pvec3 = pIparIp4Ievt( allmomenta, ipar, 3, ievt );
#else
      //printf( "ipzxxx: ipagV=%d\n", ipagV );
      const fptype_sv pvec3 = pIparIp4Ipag( allmomenta, ipar, 3, ipagV );
#endif
      fo[0] = cxmake( -pvec3 * (fptype)nsf, pvec3 * (fptype)nsf ); // remember pvec0 == -pvec3
      fo[1] = cxzero_sv();
      const int nh = nhel * nsf;
      const cxtype_sv chi1 = cxmake( -nhel, 0. ) * fpsqrt( -2. * pvec3 );
      if ( nh == 1 )
      {
        fo[2] = cxzero_sv();
        fo[3] = chi1;
        fo[4] = cxzero_sv();
        fo[5] = cxzero_sv();
      }
      else
      {
        fo[2] = cxzero_sv();
        fo[3] = cxzero_sv();
        fo[4] = chi1;
        //fo[5] = chi1; // AV: BUG!
        fo[5] = cxzero_sv(); // AV: BUG FIX
      }
    }
    // +++ END EVENT LOOP (where necessary) +++
    mgDebug( 1, __FUNCTION__ );
    return;
  }

  //--------------------------------------------------------------------------

  __device__
  void oxzxxx( const fptype* allmomenta,    // input[(npar=4)*(np4=4)*nevt]
               //const fptype fmass,        // ASSUME fmass==0
               const int nhel,              // input: -1 or +1 (helicity of fermion)
               const int nsf,               // input: +1 (particle) or -1 (antiparticle)
               cxtype_sv* fo,               // output: wavefunction[(nw6==6)]
#ifndef __CUDACC__
               const int ipagV,
#endif
               const int ipar )             // input: particle# out of npar
  {
    // ASSUMPTIONS: (FMASS == 0) and (PT > 0)
    mgDebug( 0, __FUNCTION__ );
    // +++ START EVENT LOOP (where necessary) +++
    {
#ifdef __CUDACC__
      const int ievt = blockDim.x * blockIdx.x + threadIdx.x; // index of event (thread) in grid
      //printf( "oxzxxx: ievt=%d threadId=%d\n", ievt, threadIdx.x );
      // AV: copying by value (not by ref) seems to give the same performance in both cuda and c++
      const fptype pvec0 = pIparIp4Ievt( allmomenta, ipar, 0, ievt );
      const fptype pvec1 = pIparIp4Ievt( allmomenta, ipar, 1, ievt );
      const fptype pvec2 = pIparIp4Ievt( allmomenta, ipar, 2, ievt );
      const fptype pvec3 = pIparIp4Ievt( allmomenta, ipar, 3, ievt );
#else
      //printf( "oxzxxx: ipagV=%d\n", ipagV );
      const fptype_sv pvec0 = pIparIp4Ipag( allmomenta, ipar, 0, ipagV );
      const fptype_sv pvec1 = pIparIp4Ipag( allmomenta, ipar, 1, ipagV );
      const fptype_sv pvec2 = pIparIp4Ipag( allmomenta, ipar, 2, ipagV );
      const fptype_sv pvec3 = pIparIp4Ipag( allmomenta, ipar, 3, ipagV );
#endif
      fo[0] = cxmake( pvec0 * (fptype)nsf, pvec3 * (fptype)nsf );
      fo[1] = cxmake( pvec1 * (fptype)nsf, pvec2 * (fptype)nsf );
      const int nh = nhel * nsf;
      //const float sqp0p3 = sqrtf( pvec0 + pvec3 ) * nsf; // AV: why force a float here?
      const fptype_sv sqp0p3 = fpsqrt( pvec0 + pvec3 ) * (fptype)nsf;
      const cxtype_sv chi0 = cxmake( sqp0p3, 0. );
      const cxtype_sv chi1 = cxmake( (fptype)nh * pvec1 / sqp0p3, -pvec2 / sqp0p3 );
      if ( nh == 1 )
      {
        fo[2] = chi0;
        fo[3] = chi1;
        fo[4] = cxzero_sv();
        fo[5] = cxzero_sv();
      }
      else
      {
        fo[2] = cxzero_sv();
        fo[3] = cxzero_sv();
        fo[4] = chi1;
        fo[5] = chi0;
      }
    }
    // +++ END EVENT LOOP (where necessary) +++
    mgDebug( 1, __FUNCTION__ );
    return;
  }

  //--------------------------------------------------------------------------

  __device__
  void FFV1_0( const cxtype_sv F1[],   // input: wavefunction1[6]
               const cxtype_sv F2[],   // input: wavefunction2[6]
               const cxtype_sv V3[],   // input: wavefunction3[6]
               const cxtype COUP,
               cxtype_sv* vertex )     // output: amplitude
  {
    mgDebug( 0, __FUNCTION__ );
    const cxtype cI = cxmake( 0., 1. );
    const cxtype_sv TMP0 = (F1[2] * (F2[4] * (V3[2] + V3[5]) + F2[5] * (V3[3] + cI * (V3[4]))) +
                            (F1[3] * (F2[4] * (V3[3] - cI * (V3[4])) + F2[5] * (V3[2] - V3[5])) +
                             (F1[4] * (F2[2] * (V3[2] - V3[5]) - F2[3] * (V3[3] + cI * (V3[4]))) +
                              F1[5] * (F2[2] * (-V3[3] + cI * (V3[4])) + F2[3] * (V3[2] + V3[5])))));
    (*vertex) = COUP * - cI * TMP0;
    mgDebug( 1, __FUNCTION__ );
    return;
  }

  //--------------------------------------------------------------------------

  __device__
  void FFV1P0_3( const cxtype_sv F1[],     // input: wavefunction1[6]
                 const cxtype_sv F2[],     // input: wavefunction2[6]
                 const cxtype COUP,
                 const fptype M3,
                 const fptype W3,
                 cxtype_sv V3[] )          // output: wavefunction3[6]
  {
    mgDebug( 0, __FUNCTION__ );
    const cxtype cI = cxmake( 0., 1. );
    V3[0] = +F1[0] + F2[0];
    V3[1] = +F1[1] + F2[1];
    const fptype_sv P3[4] = { -cxreal( V3[0] ), -cxreal( V3[1] ), -cximag( V3[1] ), -cximag( V3[0] ) };
    const cxtype_sv denom = COUP/((P3[0] * P3[0]) - (P3[1] * P3[1]) - (P3[2] * P3[2]) - (P3[3] * P3[3]) - M3 * (M3 - cI * W3));
    V3[2] = denom * (-cI) * (F1[2] * F2[4] + F1[3] * F2[5] + F1[4] * F2[2] + F1[5] * F2[3]);
    V3[3] = denom * (-cI) * (-F1[2] * F2[5] - F1[3] * F2[4] + F1[4] * F2[3] + F1[5] * F2[2]);
    V3[4] = denom * (-cI) * (-cI * (F1[2] * F2[5] + F1[5] * F2[2]) + cI * (F1[3] * F2[4] + F1[4] * F2[3]));
    V3[5] = denom * (-cI) * (-F1[2] * F2[4] - F1[5] * F2[3] + F1[3] * F2[5] + F1[4] * F2[2]);
    mgDebug( 1, __FUNCTION__ );
    return;
  }

  //--------------------------------------------------------------------------

  __device__
  void FFV2_0( const cxtype_sv F1[],   // input: wavefunction1[6]
               const cxtype_sv F2[],   // input: wavefunction2[6]
               const cxtype_sv V3[],   // input: wavefunction3[6]
               const cxtype COUP,
               cxtype_sv* vertex )     // output: amplitude
  {
    mgDebug( 0, __FUNCTION__ );
    const cxtype cI = cxmake( 0., 1. );
    const cxtype_sv TMP1 = (F1[2] * (F2[4] * (V3[2] + V3[5]) + F2[5] * (V3[3] + cI * (V3[4]))) +
                            F1[3] * (F2[4] * (V3[3] - cI * (V3[4])) + F2[5] * (V3[2] - V3[5])));
    (*vertex) = COUP * - cI * TMP1;
    mgDebug( 1, __FUNCTION__ );
    return;
  }

  //--------------------------------------------------------------------------

  __device__
  void FFV2_3( const cxtype_sv F1[],   // input: wavefunction1[6]
               const cxtype_sv F2[],   // input: wavefunction2[6]
               const cxtype COUP,
               const fptype M3,
               const fptype W3,
               cxtype_sv V3[] )        // output: wavefunction3[6]
  {
    mgDebug( 0, __FUNCTION__ );
    const cxtype cI = cxmake( 0., 1. );
    const fptype OM3 = ( M3 != 0. ? 1. / ( M3 * M3 ) : 0. );
    V3[0] = +F1[0] + F2[0];
    V3[1] = +F1[1] + F2[1];
    const fptype_sv P3[4] = { -cxreal( V3[0] ), -cxreal( V3[1] ), -cximag( V3[1] ), -cximag( V3[0] ) };
    const cxtype_sv TMP2 = (F1[2] * (F2[4] * (P3[0] + P3[3]) + F2[5] * (P3[1] + cI * (P3[2]))) +
                            F1[3] * (F2[4] * (P3[1] - cI * (P3[2])) + F2[5] * (P3[0] - P3[3])));
    const cxtype_sv denom = COUP/((P3[0] * P3[0]) - (P3[1] * P3[1]) - (P3[2] * P3[2]) - (P3[3] * P3[3]) - M3 * (M3 - cI * W3));
    V3[2] = denom * (-cI) * (F1[2] * F2[4] + F1[3] * F2[5] - P3[0] * OM3 * TMP2);
    V3[3] = denom * (-cI) * (-F1[2] * F2[5] - F1[3] * F2[4] - P3[1] * OM3 * TMP2);
    V3[4] = denom * (-cI) * (-cI * (F1[2] * F2[5]) + cI * (F1[3] * F2[4]) - P3[2] * OM3 * TMP2);
    V3[5] = denom * (-cI) * (-F1[2] * F2[4] - P3[3] * OM3 * TMP2 + F1[3] * F2[5]);
    mgDebug( 1, __FUNCTION__ );
    return;
  }

  //--------------------------------------------------------------------------

  __device__
  void FFV4_0( const cxtype_sv F1[],   // input: wavefunction1[6]
               const cxtype_sv F2[],   // input: wavefunction2[6]
               const cxtype_sv V3[],   // input: wavefunction3[6]
               const cxtype COUP,
               cxtype_sv* vertex )     // output: amplitude
  {
    mgDebug( 0, __FUNCTION__ );
    const cxtype cI = cxmake( 0., 1. );
    constexpr fptype one( 1. );
    constexpr fptype two( 2. );
    const cxtype_sv TMP3 = (F1[2] * (F2[4] * (V3[2] + V3[5]) + F2[5] * (V3[3] + cI * (V3[4]))) +
                            F1[3] * (F2[4] * (V3[3] - cI * (V3[4])) + F2[5] * (V3[2] - V3[5])));
    const cxtype_sv TMP4 = (F1[4] * (F2[2] * (V3[2] - V3[5]) - F2[3] * (V3[3] + cI * (V3[4]))) +
                            F1[5] * (F2[2] * (-V3[3] + cI * (V3[4])) + F2[3] * (V3[2] + V3[5])));
    (*vertex) = COUP * (-one) * (+cI * (TMP3) + two * cI * (TMP4));
    mgDebug( 1, __FUNCTION__ );
    return;
  }

  //--------------------------------------------------------------------------

  __device__
  void FFV4_3( const cxtype_sv F1[],   // input: wavefunction1[6]
               const cxtype_sv F2[],   // input: wavefunction2[6]
               const cxtype_sv COUP,
               const fptype M3,
               const fptype W3,
               cxtype_sv V3[] )        // output: wavefunction3[6]
  {
    mgDebug( 0, __FUNCTION__ );
    const cxtype cI = cxmake( 0., 1. );
    constexpr fptype two( 2. );
    constexpr fptype half( 1. / 2. );
    const fptype OM3 = ( M3 != 0. ? 1. / ( M3 * M3 ) : 0. );
    V3[0] = +F1[0] + F2[0];
    V3[1] = +F1[1] + F2[1];
    const fptype_sv P3[4] = { -cxreal( V3[0] ), -cxreal( V3[1] ), -cximag( V3[1] ), -cximag( V3[0] ) };
    const cxtype_sv TMP5 = (F1[4] * (F2[2] * (P3[0] - P3[3]) - F2[3] * (P3[1] + cI * (P3[2]))) +
                            F1[5] * (F2[2] * (-P3[1] + cI * (P3[2])) + F2[3] * (P3[0] + P3[3])));
    const cxtype_sv TMP2 = (F1[2] * (F2[4] * (P3[0] + P3[3]) + F2[5] * (P3[1] + cI * (P3[2]))) +
                            F1[3] * (F2[4] * (P3[1] - cI * (P3[2])) + F2[5] * (P3[0] - P3[3])));
    const cxtype_sv denom = COUP/((P3[0] * P3[0]) - (P3[1] * P3[1]) - (P3[2] * P3[2]) - (P3[3] * P3[3]) - M3 * (M3 - cI * W3));
    V3[2] = denom * (-two * cI) * (OM3 * - half * P3[0] * (TMP2 + two * (TMP5)) +
                                  (+half * (F1[2] * F2[4] + F1[3] * F2[5]) + F1[4] * F2[2] + F1[5] * F2[3]));
    V3[3] = denom * (-two * cI) * (OM3 * - half * P3[1] * (TMP2 + two * (TMP5)) +
                                  (-half * (F1[2] * F2[5] + F1[3] * F2[4]) + F1[4] * F2[3] + F1[5] * F2[2]));
    V3[4] = denom * two * cI * (OM3 * half * P3[2] * (TMP2 + two * (TMP5)) +
                               (+half * cI * (F1[2] * F2[5]) - half * cI * (F1[3] * F2[4]) - cI *
                                (F1[4] * F2[3]) + cI * (F1[5] * F2[2])));
    V3[5] = denom * two * cI * (OM3 * half * P3[3] * (TMP2 + two * (TMP5)) +
                               (+half * (F1[2] * F2[4]) - half * (F1[3] * F2[5]) - F1[4] * F2[2] + F1[5] * F2[3]));
    mgDebug( 1, __FUNCTION__ );
    return;
  }

  //--------------------------------------------------------------------------

  __device__
  void FFV2_4_0( const cxtype_sv F1[],   // input: wavefunction1[6]
                 const cxtype_sv F2[],   // input: wavefunction2[6]
                 const cxtype_sv V3[],   // input: wavefunction3[6]
                 const cxtype COUP1,
                 const cxtype COUP2,
                 cxtype_sv* vertex )     // output: amplitude
  {
    mgDebug( 0, __FUNCTION__ );
    const cxtype cI = cxmake( 0., 1. );
    constexpr fptype one( 1. );
    constexpr fptype two( 2. );
    // Note: inverting the order and computing TMP4 before TMP3 has increased C++ speed by ~1%
    const cxtype_sv TMP4 = (F1[4] * (F2[2] * (V3[2] - V3[5]) - F2[3] * (V3[3] + cI * (V3[4]))) +
                            F1[5] * (F2[2] * (-V3[3] + cI * (V3[4])) + F2[3] * (V3[2] + V3[5])));
    const cxtype_sv TMP3 = (F1[2] * (F2[4] * (V3[2] + V3[5]) + F2[5] * (V3[3] + cI * (V3[4]))) +
                            F1[3] * (F2[4] * (V3[3] - cI * (V3[4])) + F2[5] * (V3[2] - V3[5])));
    (*vertex) = ( -one ) * (COUP2 * (+cI * (TMP3) + two * cI * (TMP4)) + cI * (TMP3 * COUP1));
    mgDebug( 1, __FUNCTION__ );
    return;
  }

  //--------------------------------------------------------------------------

  __device__
  void FFV2_4_3( const cxtype_sv F1[],   // input: wavefunction1[6]
                 const cxtype_sv F2[],   // input: wavefunction2[6]
                 const cxtype COUP1,
                 const cxtype COUP2,
                 const fptype M3,
                 const fptype W3,
                 cxtype_sv V3[] )        // output: wavefunction3[6]
  {
    mgDebug( 0, __FUNCTION__ );
    const cxtype cI = cxmake( 0., 1. );
    constexpr fptype one( 1. );
    constexpr fptype two( 2. );
    constexpr fptype half( 1. / 2. );
    const fptype OM3 = ( M3 != 0. ? 1. / ( M3 * M3 ) : 0. );
    V3[0] = +F1[0] + F2[0];
    V3[1] = +F1[1] + F2[1];
    const fptype_sv P3[4] = { -cxreal( V3[0] ), -cxreal( V3[1] ), -cximag( V3[1] ), -cximag( V3[0] ) };
    // Note: inverting the order and computing TMP2 before TMP5 has increased C++ speed by ~0.5%
    const cxtype_sv TMP2 = (F1[2] * (F2[4] * (P3[0] + P3[3]) + F2[5] * (P3[1] + cI * (P3[2]))) +
                            F1[3] * (F2[4] * (P3[1] - cI * (P3[2])) + F2[5] * (P3[0] - P3[3])));
    const cxtype_sv TMP5 = (F1[4] * (F2[2] * (P3[0] - P3[3]) - F2[3] * (P3[1] + cI * (P3[2]))) +
                            F1[5] * (F2[2] * (-P3[1] + cI * (P3[2])) + F2[3] * (P3[0] + P3[3])));
    const cxtype_sv denom = one/((P3[0] * P3[0]) - (P3[1] * P3[1]) - (P3[2] * P3[2]) - (P3[3] * P3[3]) - M3 * (M3 - cI * W3));
    V3[2] = denom * (-two * cI) *
      (COUP2 * (OM3 * - half * P3[0] * (TMP2 + two * (TMP5)) +
                (+half * (F1[2] * F2[4] + F1[3] * F2[5]) + F1[4] * F2[2] + F1[5] * F2[3])) +
       half * (COUP1 * (F1[2] * F2[4] + F1[3] * F2[5] - P3[0] * OM3 * TMP2)));
    V3[3] = denom * (-two * cI) *
      (COUP2 * (OM3 * - half * P3[1] * (TMP2 + two * (TMP5)) +
                (-half * (F1[2] * F2[5] + F1[3] * F2[4]) + F1[4] * F2[3] + F1[5] * F2[2])) -
       half * (COUP1 * (F1[2] * F2[5] + F1[3] * F2[4] + P3[1] * OM3 * TMP2)));
    V3[4] = denom * cI *
      (COUP2 * (OM3 * P3[2] * (TMP2 + two * (TMP5)) +
                (+cI * (F1[2] * F2[5]) - cI * (F1[3] * F2[4]) - two * cI * (F1[4] * F2[3]) + two * cI * (F1[5] * F2[2]))) +
       COUP1 * (+cI * (F1[2] * F2[5]) - cI * (F1[3] * F2[4]) + P3[2] * OM3 * TMP2));
    V3[5] = denom * two * cI *
      (COUP2 * (OM3 * half * P3[3] * (TMP2 + two * (TMP5)) +
                (+half * (F1[2] * F2[4]) - half * (F1[3] * F2[5]) - F1[4] * F2[2] + F1[5] * F2[3])) +
       half * (COUP1 * (F1[2] * F2[4] + P3[3] * OM3 * TMP2 - F1[3] * F2[5])));
    mgDebug( 1, __FUNCTION__ );
    return;
  }

} // end namespace
