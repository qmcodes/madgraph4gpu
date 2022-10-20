//==========================================================================
// This file has been automatically generated for C++ Standalone by
// MadGraph5_aMC@NLO v. 3.4.0_lo_vect, 2022-05-06
// By the MadGraph5_aMC@NLO Development Team
// Visit launchpad.net/madgraph5 and amcatnlo.web.cern.ch
//==========================================================================

#include <algorithm>
#include <iostream>
#include "mgOnGpuTypes.h"
#include "mgOnGpuConfig.h"

#include "CPPProcess.h"
#include "HelAmps_sm.h"
//==========================================================================
// Class member functions for calculating the matrix elements for
// Process: g g > t t~ g g g WEIGHTED<=5 @1

//--------------------------------------------------------------------------

  // Evaluate |M|^2 for each subprocess
  // NB: calculate_wavefunctions ADDS |M|^2 for a given ihel to the running sum of |M|^2 over helicities for the given event(s)
template <typename mom_t, typename ipc_t, typename ipd_t>
KOKKOS_INLINE_FUNCTION fptype calculate_wavefunctions(
  const mom_t& allmomenta, // input: momenta
#ifdef MGONGPU_SUPPORTS_MULTICHANNEL
  fptype& allNumerators,   // output: multichannel numerators, running_sum_over_helicities
  fptype& allDenominators, // output: multichannel denominators, running_sum_over_helicities
  const unsigned int channelId,         // input: multichannel channel id (1 to #diagrams); 0 to disable channel enhancement
#endif
  const short*  __restrict__ cHel,
  const ipc_t& COUPs,
  const ipd_t& cIPD
  )
{
  using namespace MG5_sm;
  fptype allMEs = 0;
  // The number of colors
  constexpr int ncolor = 120;

  // Local TEMPORARY variables for a subset of Feynman diagrams in the given event (ievt)
  // [NB these variables are reused several times (and re-initialised each time) within the same event or event page]
  cxtype w[mgOnGpu::nwf][mgOnGpu::nw6]; // particle wavefunctions within Feynman diagrams (nw6 is often 6, the dimension of spin 1/2 or spin 1 particles)
  cxtype amp[1]; // invariant amplitude for one given Feynman diagram

  // Local variables for the given event (ievt)
  cxtype jamp[ncolor] = {}; // sum of the invariant amplitudes for all Feynman diagrams in the event or event page

  // === Calculate wavefunctions and amplitudes for all diagrams in all processes - Loop over nevt events ===

  // Reset color flows (reset jamp) at the beginning of a new event or event page
  for( int i=0; i<ncolor; i++ ){ jamp[i] = cxmake( 0, 0 ); }

  // *** DIAGRAM 1 OF 1240 ***

  // Wavefunction(s) for diagram number 1
  vxxxxx(Kokkos::subview(allmomenta, 0, Kokkos::ALL), 0., cHel[0], -1, w[0]);

  vxxxxx(Kokkos::subview(allmomenta, 1, Kokkos::ALL), 0., cHel[1], -1, w[1]);

  oxxxxx(Kokkos::subview(allmomenta, 2, Kokkos::ALL), cIPD[0], cHel[2], +1, w[2]);

  ixxxxx(Kokkos::subview(allmomenta, 3, Kokkos::ALL), cIPD[0], cHel[3], -1, w[3]);

  vxxxxx(Kokkos::subview(allmomenta, 4, Kokkos::ALL), 0., cHel[4], +1, w[4]);

  vxxxxx(Kokkos::subview(allmomenta, 5, Kokkos::ALL), 0., cHel[5], +1, w[5]);

  vxxxxx(Kokkos::subview(allmomenta, 6, Kokkos::ALL), 0., cHel[6], +1, w[6]);

  VVV1P0_1( w[0], w[1], COUPs[0], 0., 0., w[7] );
  FFV1P0_3( w[3], w[2], COUPs[1], 0., 0., w[8] );
  VVV1P0_1( w[7], w[4], COUPs[0], 0., 0., w[9] );
  VVV1P0_1( w[8], w[5], COUPs[0], 0., 0., w[10] );

  // Amplitude(s) for diagram number 1
  VVV1_0( w[9], w[10], w[6], COUPs[0], &amp[0] );
#ifdef MGONGPU_SUPPORTS_MULTICHANNEL
  if( channelId == 1 ) allNumerators[0] += cxabs2( amp[0] );
  if( channelId != 0 ) allDenominators[0] += cxabs2( amp[0] );
#endif
  jamp[1] -= amp[0];
  jamp[25] += amp[0];
  jamp[49] += amp[0];
  jamp[55] -= amp[0];
  jamp[72] += amp[0];
  jamp[78] -= amp[0];
  jamp[84] -= amp[0];
  jamp[86] += amp[0];
  jamp[90] -= amp[0];
  jamp[92] += amp[0];
  jamp[94] += amp[0];
  jamp[95] -= amp[0];
  jamp[96] += amp[0];
  jamp[102] -= amp[0];
  jamp[108] -= amp[0];
  jamp[110] += amp[0];

  // *** DIAGRAM 2 OF 1240 ***

  // Wavefunction(s) for diagram number 2
  VVV1P0_1( w[8], w[6], COUPs[0], 0., 0., w[11] );

  // Amplitude(s) for diagram number 2
  VVV1_0( w[9], w[11], w[5], COUPs[0], &amp[0] );
#ifdef MGONGPU_SUPPORTS_MULTICHANNEL
  if( channelId == 2 ) allNumerators[0] += cxabs2( amp[0] );
  if( channelId != 0 ) allDenominators[0] += cxabs2( amp[0] );
#endif
  jamp[0] -= amp[0];
  jamp[24] += amp[0];
  jamp[48] += amp[0];
  jamp[54] -= amp[0];
  jamp[72] += amp[0];
  jamp[78] -= amp[0];
  jamp[84] -= amp[0];
  jamp[86] += amp[0];
  jamp[96] += amp[0];
  jamp[102] -= amp[0];
  jamp[108] -= amp[0];
  jamp[110] += amp[0];
  jamp[114] -= amp[0];
  jamp[116] += amp[0];
  jamp[118] += amp[0];
  jamp[119] -= amp[0];

  // *** DIAGRAM 3 OF 1240 ***

  // Wavefunction(s) for diagram number 3
  // (none)

  // Amplitude(s) for diagram number 3
  VVVV1_0( w[8], w[5], w[6], w[9], COUPs[2], &amp[0] );
  jamp[1] -= amp[0];
  jamp[25] += amp[0];
  jamp[49] += amp[0];
  jamp[55] -= amp[0];
  jamp[72] += amp[0];
  jamp[78] -= amp[0];
  jamp[84] -= amp[0];
  jamp[86] += amp[0];
  jamp[90] -= amp[0];
  jamp[92] += amp[0];
  jamp[94] += amp[0];
  jamp[95] -= amp[0];
  jamp[96] += amp[0];
  jamp[102] -= amp[0];
  jamp[108] -= amp[0];
  jamp[110] += amp[0];
  VVVV3_0( w[8], w[5], w[6], w[9], COUPs[2], &amp[0] );
  jamp[0] -= amp[0];
  jamp[24] += amp[0];
  jamp[48] += amp[0];
  jamp[54] -= amp[0];
  jamp[72] += amp[0];
  jamp[78] -= amp[0];
  jamp[84] -= amp[0];
  jamp[86] += amp[0];
  jamp[96] += amp[0];
  jamp[102] -= amp[0];
  jamp[108] -= amp[0];
  jamp[110] += amp[0];
  jamp[114] -= amp[0];
  jamp[116] += amp[0];
  jamp[118] += amp[0];
  jamp[119] -= amp[0];
  VVVV4_0( w[8], w[5], w[6], w[9], COUPs[2], &amp[0] );
  jamp[0] -= amp[0];
  jamp[1] += amp[0];
  jamp[24] += amp[0];
  jamp[25] -= amp[0];
  jamp[48] += amp[0];
  jamp[49] -= amp[0];
  jamp[54] -= amp[0];
  jamp[55] += amp[0];
  jamp[90] += amp[0];
  jamp[92] -= amp[0];
  jamp[94] -= amp[0];
  jamp[95] += amp[0];
  jamp[114] -= amp[0];
  jamp[116] += amp[0];
  jamp[118] += amp[0];
  jamp[119] -= amp[0];

  // *** DIAGRAM 4 OF 1240 ***

  // Wavefunction(s) for diagram number 4
  VVV1P0_1( w[7], w[5], COUPs[0], 0., 0., w[12] );
  VVV1P0_1( w[8], w[4], COUPs[0], 0., 0., w[13] );

  // Amplitude(s) for diagram number 4
  VVV1_0( w[12], w[13], w[6], COUPs[0], &amp[0] );
#ifdef MGONGPU_SUPPORTS_MULTICHANNEL
  if( channelId == 4 ) allNumerators[0] += cxabs2( amp[0] );
  if( channelId != 0 ) allDenominators[0] += cxabs2( amp[0] );
#endif
  jamp[3] -= amp[0];
  jamp[27] += amp[0];
  jamp[48] += amp[0];
  jamp[54] -= amp[0];
  jamp[60] -= amp[0];
  jamp[62] += amp[0];
  jamp[66] -= amp[0];
  jamp[68] += amp[0];
  jamp[70] += amp[0];
  jamp[71] -= amp[0];
  jamp[73] += amp[0];
  jamp[79] -= amp[0];
  jamp[97] += amp[0];
  jamp[103] -= amp[0];
  jamp[114] -= amp[0];
  jamp[116] += amp[0];

  // *** DIAGRAM 5 OF 1240 ***

  // Wavefunction(s) for diagram number 5
  // (none)

  // Amplitude(s) for diagram number 5
  VVV1_0( w[12], w[11], w[4], COUPs[0], &amp[0] );
#ifdef MGONGPU_SUPPORTS_MULTICHANNEL
  if( channelId == 5 ) allNumerators[0] += cxabs2( amp[0] );
  if( channelId != 0 ) allDenominators[0] += cxabs2( amp[0] );
#endif
  jamp[2] -= amp[0];
  jamp[26] += amp[0];
  jamp[48] += amp[0];
  jamp[54] -= amp[0];
  jamp[60] -= amp[0];
  jamp[62] += amp[0];
  jamp[72] += amp[0];
  jamp[78] -= amp[0];
  jamp[97] += amp[0];
  jamp[103] -= amp[0];
  jamp[108] -= amp[0];
  jamp[110] += amp[0];
  jamp[112] += amp[0];
  jamp[113] -= amp[0];
  jamp[114] -= amp[0];
  jamp[116] += amp[0];

  // *** DIAGRAM 6 OF 1240 ***

  // Wavefunction(s) for diagram number 6
  // (none)

  // Amplitude(s) for diagram number 6
  VVVV1_0( w[8], w[4], w[6], w[12], COUPs[2], &amp[0] );
  jamp[3] -= amp[0];
  jamp[27] += amp[0];
  jamp[48] += amp[0];
  jamp[54] -= amp[0];
  jamp[60] -= amp[0];
  jamp[62] += amp[0];
  jamp[66] -= amp[0];
  jamp[68] += amp[0];
  jamp[70] += amp[0];
  jamp[71] -= amp[0];
  jamp[73] += amp[0];
  jamp[79] -= amp[0];
  jamp[97] += amp[0];
  jamp[103] -= amp[0];
  jamp[114] -= amp[0];
  jamp[116] += amp[0];
  VVVV3_0( w[8], w[4], w[6], w[12], COUPs[2], &amp[0] );
  jamp[2] -= amp[0];
  jamp[26] += amp[0];
  jamp[48] += amp[0];
  jamp[54] -= amp[0];
  jamp[60] -= amp[0];
  jamp[62] += amp[0];
  jamp[72] += amp[0];
  jamp[78] -= amp[0];
  jamp[97] += amp[0];
  jamp[103] -= amp[0];
  jamp[108] -= amp[0];
  jamp[110] += amp[0];
  jamp[112] += amp[0];
  jamp[113] -= amp[0];
  jamp[114] -= amp[0];
  jamp[116] += amp[0];
  VVVV4_0( w[8], w[4], w[6], w[12], COUPs[2], &amp[0] );
  jamp[2] -= amp[0];
  jamp[3] += amp[0];
  jamp[26] += amp[0];
  jamp[27] -= amp[0];
  jamp[66] += amp[0];
  jamp[68] -= amp[0];
  jamp[70] -= amp[0];
  jamp[71] += amp[0];
  jamp[72] += amp[0];
  jamp[73] -= amp[0];
  jamp[78] -= amp[0];
  jamp[79] += amp[0];
  jamp[108] -= amp[0];
  jamp[110] += amp[0];
  jamp[112] += amp[0];
  jamp[113] -= amp[0];

  // *** DIAGRAM 7 OF 1240 ***

  // Wavefunction(s) for diagram number 7
  VVV1P0_1( w[7], w[6], COUPs[0], 0., 0., w[14] );

  // Amplitude(s) for diagram number 7
  VVV1_0( w[14], w[13], w[5], COUPs[0], &amp[0] );
#ifdef MGONGPU_SUPPORTS_MULTICHANNEL
  if( channelId == 7 ) allNumerators[0] += cxabs2( amp[0] );
  if( channelId != 0 ) allDenominators[0] += cxabs2( amp[0] );
#endif
  jamp[5] -= amp[0];
  jamp[29] += amp[0];
  jamp[49] += amp[0];
  jamp[55] -= amp[0];
  jamp[60] -= amp[0];
  jamp[62] += amp[0];
  jamp[64] += amp[0];
  jamp[65] -= amp[0];
  jamp[66] -= amp[0];
  jamp[68] += amp[0];
  jamp[73] += amp[0];
  jamp[79] -= amp[0];
  jamp[90] -= amp[0];
  jamp[92] += amp[0];
  jamp[97] += amp[0];
  jamp[103] -= amp[0];

  // *** DIAGRAM 8 OF 1240 ***

  // Wavefunction(s) for diagram number 8
  // (none)

  // Amplitude(s) for diagram number 8
  VVV1_0( w[14], w[10], w[4], COUPs[0], &amp[0] );
#ifdef MGONGPU_SUPPORTS_MULTICHANNEL
  if( channelId == 8 ) allNumerators[0] += cxabs2( amp[0] );
  if( channelId != 0 ) allDenominators[0] += cxabs2( amp[0] );
#endif
  jamp[4] -= amp[0];
  jamp[28] += amp[0];
  jamp[49] += amp[0];
  jamp[55] -= amp[0];
  jamp[66] -= amp[0];
  jamp[68] += amp[0];
  jamp[73] += amp[0];
  jamp[79] -= amp[0];
  jamp[84] -= amp[0];
  jamp[86] += amp[0];
  jamp[88] += amp[0];
  jamp[89] -= amp[0];
  jamp[90] -= amp[0];
  jamp[92] += amp[0];
  jamp[96] += amp[0];
  jamp[102] -= amp[0];

  // *** DIAGRAM 9 OF 1240 ***

  // Wavefunction(s) for diagram number 9
  // (none)

  // Amplitude(s) for diagram number 9
  VVVV1_0( w[8], w[4], w[5], w[14], COUPs[2], &amp[0] );
  jamp[5] -= amp[0];
  jamp[29] += amp[0];
  jamp[49] += amp[0];
  jamp[55] -= amp[0];
  jamp[60] -= amp[0];
  jamp[62] += amp[0];
  jamp[64] += amp[0];
  jamp[65] -= amp[0];
  jamp[66] -= amp[0];
  jamp[68] += amp[0];
  jamp[73] += amp[0];
  jamp[79] -= amp[0];
  jamp[90] -= amp[0];
  jamp[92] += amp[0];
  jamp[97] += amp[0];
  jamp[103] -= amp[0];
  VVVV3_0( w[8], w[4], w[5], w[14], COUPs[2], &amp[0] );
  jamp[4] -= amp[0];
  jamp[28] += amp[0];
  jamp[49] += amp[0];
  jamp[55] -= amp[0];
  jamp[66] -= amp[0];
  jamp[68] += amp[0];
  jamp[73] += amp[0];
  jamp[79] -= amp[0];
  jamp[84] -= amp[0];
  jamp[86] += amp[0];
  jamp[88] += amp[0];
  jamp[89] -= amp[0];
  jamp[90] -= amp[0];
  jamp[92] += amp[0];
  jamp[96] += amp[0];
  jamp[102] -= amp[0];
  VVVV4_0( w[8], w[4], w[5], w[14], COUPs[2], &amp[0] );
  jamp[4] -= amp[0];
  jamp[5] += amp[0];
  jamp[28] += amp[0];
  jamp[29] -= amp[0];
  jamp[60] += amp[0];
  jamp[62] -= amp[0];
  jamp[64] -= amp[0];
  jamp[65] += amp[0];
  jamp[84] -= amp[0];
  jamp[86] += amp[0];
  jamp[88] += amp[0];
  jamp[89] -= amp[0];
  jamp[96] += amp[0];
  jamp[97] -= amp[0];
  jamp[102] -= amp[0];
  jamp[103] += amp[0];

  // *** DIAGRAM 10 OF 1240 ***

  // Wavefunction(s) for diagram number 10
  VVVV1P0_1( w[7], w[4], w[5], COUPs[2], 0., 0., w[15] );
  VVVV3P0_1( w[7], w[4], w[5], COUPs[2], 0., 0., w[16] );
  VVVV4P0_1( w[7], w[4], w[5], COUPs[2], 0., 0., w[17] );

  // Amplitude(s) for diagram number 10
  VVV1_0( w[8], w[6], w[15], COUPs[0], &amp[0] );
  jamp[0] += amp[0];
  jamp[2] -= amp[0];
  jamp[24] -= amp[0];
  jamp[26] += amp[0];
  jamp[60] -= amp[0];
  jamp[62] += amp[0];
  jamp[84] += amp[0];
  jamp[86] -= amp[0];
  jamp[96] -= amp[0];
  jamp[97] += amp[0];
  jamp[102] += amp[0];
  jamp[103] -= amp[0];
  jamp[112] += amp[0];
  jamp[113] -= amp[0];
  jamp[118] -= amp[0];
  jamp[119] += amp[0];
  VVV1_0( w[8], w[6], w[16], COUPs[0], &amp[0] );
  jamp[2] -= amp[0];
  jamp[26] += amp[0];
  jamp[48] += amp[0];
  jamp[54] -= amp[0];
  jamp[60] -= amp[0];
  jamp[62] += amp[0];
  jamp[72] += amp[0];
  jamp[78] -= amp[0];
  jamp[97] += amp[0];
  jamp[103] -= amp[0];
  jamp[108] -= amp[0];
  jamp[110] += amp[0];
  jamp[112] += amp[0];
  jamp[113] -= amp[0];
  jamp[114] -= amp[0];
  jamp[116] += amp[0];
  VVV1_0( w[8], w[6], w[17], COUPs[0], &amp[0] );
  jamp[0] -= amp[0];
  jamp[24] += amp[0];
  jamp[48] += amp[0];
  jamp[54] -= amp[0];
  jamp[72] += amp[0];
  jamp[78] -= amp[0];
  jamp[84] -= amp[0];
  jamp[86] += amp[0];
  jamp[96] += amp[0];
  jamp[102] -= amp[0];
  jamp[108] -= amp[0];
  jamp[110] += amp[0];
  jamp[114] -= amp[0];
  jamp[116] += amp[0];
  jamp[118] += amp[0];
  jamp[119] -= amp[0];

  // *** DIAGRAM 11 OF 1240 ***

  // Wavefunction(s) for diagram number 11
  VVVV1P0_1( w[7], w[4], w[6], COUPs[2], 0., 0., w[18] );
  VVVV3P0_1( w[7], w[4], w[6], COUPs[2], 0., 0., w[19] );
  VVVV4P0_1( w[7], w[4], w[6], COUPs[2], 0., 0., w[20] );

  // Amplitude(s) for diagram number 11
  VVV1_0( w[8], w[5], w[18], COUPs[0], &amp[0] );
  jamp[1] += amp[0];
  jamp[4] -= amp[0];
  jamp[25] -= amp[0];
  jamp[28] += amp[0];
  jamp[66] -= amp[0];
  jamp[68] += amp[0];
  jamp[72] -= amp[0];
  jamp[73] += amp[0];
  jamp[78] += amp[0];
  jamp[79] -= amp[0];
  jamp[88] += amp[0];
  jamp[89] -= amp[0];
  jamp[94] -= amp[0];
  jamp[95] += amp[0];
  jamp[108] += amp[0];
  jamp[110] -= amp[0];
  VVV1_0( w[8], w[5], w[19], COUPs[0], &amp[0] );
  jamp[4] -= amp[0];
  jamp[28] += amp[0];
  jamp[49] += amp[0];
  jamp[55] -= amp[0];
  jamp[66] -= amp[0];
  jamp[68] += amp[0];
  jamp[73] += amp[0];
  jamp[79] -= amp[0];
  jamp[84] -= amp[0];
  jamp[86] += amp[0];
  jamp[88] += amp[0];
  jamp[89] -= amp[0];
  jamp[90] -= amp[0];
  jamp[92] += amp[0];
  jamp[96] += amp[0];
  jamp[102] -= amp[0];
  VVV1_0( w[8], w[5], w[20], COUPs[0], &amp[0] );
  jamp[1] -= amp[0];
  jamp[25] += amp[0];
  jamp[49] += amp[0];
  jamp[55] -= amp[0];
  jamp[72] += amp[0];
  jamp[78] -= amp[0];
  jamp[84] -= amp[0];
  jamp[86] += amp[0];
  jamp[90] -= amp[0];
  jamp[92] += amp[0];
  jamp[94] += amp[0];
  jamp[95] -= amp[0];
  jamp[96] += amp[0];
  jamp[102] -= amp[0];
  jamp[108] -= amp[0];
  jamp[110] += amp[0];

  // *** DIAGRAM 12 OF 1240 ***

  // Wavefunction(s) for diagram number 12
  VVVV1P0_1( w[7], w[5], w[6], COUPs[2], 0., 0., w[21] );
  VVVV3P0_1( w[7], w[5], w[6], COUPs[2], 0., 0., w[22] );
  VVVV4P0_1( w[7], w[5], w[6], COUPs[2], 0., 0., w[23] );

  // Amplitude(s) for diagram number 12
  VVV1_0( w[8], w[4], w[21], COUPs[0], &amp[0] );
  jamp[3] += amp[0];
  jamp[5] -= amp[0];
  jamp[27] -= amp[0];
  jamp[29] += amp[0];
  jamp[48] -= amp[0];
  jamp[49] += amp[0];
  jamp[54] += amp[0];
  jamp[55] -= amp[0];
  jamp[64] += amp[0];
  jamp[65] -= amp[0];
  jamp[70] -= amp[0];
  jamp[71] += amp[0];
  jamp[90] -= amp[0];
  jamp[92] += amp[0];
  jamp[114] += amp[0];
  jamp[116] -= amp[0];
  VVV1_0( w[8], w[4], w[22], COUPs[0], &amp[0] );
  jamp[5] -= amp[0];
  jamp[29] += amp[0];
  jamp[49] += amp[0];
  jamp[55] -= amp[0];
  jamp[60] -= amp[0];
  jamp[62] += amp[0];
  jamp[64] += amp[0];
  jamp[65] -= amp[0];
  jamp[66] -= amp[0];
  jamp[68] += amp[0];
  jamp[73] += amp[0];
  jamp[79] -= amp[0];
  jamp[90] -= amp[0];
  jamp[92] += amp[0];
  jamp[97] += amp[0];
  jamp[103] -= amp[0];
  VVV1_0( w[8], w[4], w[23], COUPs[0], &amp[0] );
  jamp[3] -= amp[0];
  jamp[27] += amp[0];
  jamp[48] += amp[0];
  jamp[54] -= amp[0];
  jamp[60] -= amp[0];
  jamp[62] += amp[0];
  jamp[66] -= amp[0];
  jamp[68] += amp[0];
  jamp[70] += amp[0];
  jamp[71] -= amp[0];
  jamp[73] += amp[0];
  jamp[79] -= amp[0];
  jamp[97] += amp[0];
  jamp[103] -= amp[0];
  jamp[114] -= amp[0];
  jamp[116] += amp[0];

  // *** DIAGRAM 13 OF 1240 ***

  // Wavefunction(s) for diagram number 13
  VVV1P0_1( w[4], w[5], COUPs[0], 0., 0., w[24] );

  // Amplitude(s) for diagram number 13
  VVVV1_0( w[7], w[8], w[24], w[6], COUPs[2], &amp[0] );
  jamp[0] += amp[0];
  jamp[2] -= amp[0];
  jamp[4] -= amp[0];
  jamp[5] += amp[0];
  jamp[24] -= amp[0];
  jamp[26] += amp[0];
  jamp[28] += amp[0];
  jamp[29] -= amp[0];
  jamp[64] -= amp[0];
  jamp[65] += amp[0];
  jamp[88] += amp[0];
  jamp[89] -= amp[0];
  jamp[112] += amp[0];
  jamp[113] -= amp[0];
  jamp[118] -= amp[0];
  jamp[119] += amp[0];
  VVVV3_0( w[7], w[8], w[24], w[6], COUPs[2], &amp[0] );
  jamp[0] += amp[0];
  jamp[2] -= amp[0];
  jamp[24] -= amp[0];
  jamp[26] += amp[0];
  jamp[60] -= amp[0];
  jamp[62] += amp[0];
  jamp[84] += amp[0];
  jamp[86] -= amp[0];
  jamp[96] -= amp[0];
  jamp[97] += amp[0];
  jamp[102] += amp[0];
  jamp[103] -= amp[0];
  jamp[112] += amp[0];
  jamp[113] -= amp[0];
  jamp[118] -= amp[0];
  jamp[119] += amp[0];
  VVVV4_0( w[7], w[8], w[24], w[6], COUPs[2], &amp[0] );
  jamp[4] += amp[0];
  jamp[5] -= amp[0];
  jamp[28] -= amp[0];
  jamp[29] += amp[0];
  jamp[60] -= amp[0];
  jamp[62] += amp[0];
  jamp[64] += amp[0];
  jamp[65] -= amp[0];
  jamp[84] += amp[0];
  jamp[86] -= amp[0];
  jamp[88] -= amp[0];
  jamp[89] += amp[0];
  jamp[96] -= amp[0];
  jamp[97] += amp[0];
  jamp[102] += amp[0];
  jamp[103] -= amp[0];

  // *** DIAGRAM 14 OF 1240 ***

  // Wavefunction(s) for diagram number 14
  VVV1P0_1( w[7], w[8], COUPs[0], 0., 0., w[25] );

  // Amplitude(s) for diagram number 14
  VVV1_0( w[24], w[6], w[25], COUPs[0], &amp[0] );
#ifdef MGONGPU_SUPPORTS_MULTICHANNEL
  if( channelId == 14 ) allNumerators[0] += cxabs2( amp[0] );
  if( channelId != 0 ) allDenominators[0] += cxabs2( amp[0] );
#endif
  jamp[0] += amp[0];
  jamp[2] -= amp[0];
  jamp[4] -= amp[0];
  jamp[5] += amp[0];
  jamp[24] -= amp[0];
  jamp[26] += amp[0];
  jamp[28] += amp[0];
  jamp[29] -= amp[0];
  jamp[64] -= amp[0];
  jamp[65] += amp[0];
  jamp[88] += amp[0];
  jamp[89] -= amp[0];
  jamp[112] += amp[0];
  jamp[113] -= amp[0];
  jamp[118] -= amp[0];
  jamp[119] += amp[0];

  // *** DIAGRAM 15 OF 1240 ***

  // Wavefunction(s) for diagram number 15
  VVV1P0_1( w[7], w[24], COUPs[0], 0., 0., w[26] );

  // Amplitude(s) for diagram number 15
  VVV1_0( w[8], w[6], w[26], COUPs[0], &amp[0] );
#ifdef MGONGPU_SUPPORTS_MULTICHANNEL
  if( channelId == 15 ) allNumerators[0] += cxabs2( amp[0] );
  if( channelId != 0 ) allDenominators[0] += cxabs2( amp[0] );
#endif
  jamp[0] += amp[0];
  jamp[2] -= amp[0];
  jamp[24] -= amp[0];
  jamp[26] += amp[0];
  jamp[60] -= amp[0];
  jamp[62] += amp[0];
  jamp[84] += amp[0];
  jamp[86] -= amp[0];
  jamp[96] -= amp[0];
  jamp[97] += amp[0];
  jamp[102] += amp[0];
  jamp[103] -= amp[0];
  jamp[112] += amp[0];
  jamp[113] -= amp[0];
  jamp[118] -= amp[0];
  jamp[119] += amp[0];

  // *** DIAGRAM 16 OF 1240 ***

  // Wavefunction(s) for diagram number 16
  // (none)

  // Amplitude(s) for diagram number 16
  VVV1_0( w[8], w[24], w[14], COUPs[0], &amp[0] );
#ifdef MGONGPU_SUPPORTS_MULTICHANNEL
  if( channelId == 16 ) allNumerators[0] += cxabs2( amp[0] );
  if( channelId != 0 ) allDenominators[0] += cxabs2( amp[0] );
#endif
  jamp[4] += amp[0];
  jamp[5] -= amp[0];
  jamp[28] -= amp[0];
  jamp[29] += amp[0];
  jamp[60] -= amp[0];
  jamp[62] += amp[0];
  jamp[64] += amp[0];
  jamp[65] -= amp[0];
  jamp[84] += amp[0];
  jamp[86] -= amp[0];
  jamp[88] -= amp[0];
  jamp[89] += amp[0];
  jamp[96] -= amp[0];
  jamp[97] += amp[0];
  jamp[102] += amp[0];
  jamp[103] -= amp[0];

  // *** DIAGRAM 17 OF 1240 ***

  // Wavefunction(s) for diagram number 17
  VVV1P0_1( w[4], w[6], COUPs[0], 0., 0., w[27] );

  // Amplitude(s) for diagram number 17
  VVVV1_0( w[7], w[8], w[27], w[5], COUPs[2], &amp[0] );
  jamp[1] += amp[0];
  jamp[2] -= amp[0];
  jamp[3] += amp[0];
  jamp[4] -= amp[0];
  jamp[25] -= amp[0];
  jamp[26] += amp[0];
  jamp[27] -= amp[0];
  jamp[28] += amp[0];
  jamp[70] -= amp[0];
  jamp[71] += amp[0];
  jamp[88] += amp[0];
  jamp[89] -= amp[0];
  jamp[94] -= amp[0];
  jamp[95] += amp[0];
  jamp[112] += amp[0];
  jamp[113] -= amp[0];
  VVVV3_0( w[7], w[8], w[27], w[5], COUPs[2], &amp[0] );
  jamp[1] += amp[0];
  jamp[4] -= amp[0];
  jamp[25] -= amp[0];
  jamp[28] += amp[0];
  jamp[66] -= amp[0];
  jamp[68] += amp[0];
  jamp[72] -= amp[0];
  jamp[73] += amp[0];
  jamp[78] += amp[0];
  jamp[79] -= amp[0];
  jamp[88] += amp[0];
  jamp[89] -= amp[0];
  jamp[94] -= amp[0];
  jamp[95] += amp[0];
  jamp[108] += amp[0];
  jamp[110] -= amp[0];
  VVVV4_0( w[7], w[8], w[27], w[5], COUPs[2], &amp[0] );
  jamp[2] += amp[0];
  jamp[3] -= amp[0];
  jamp[26] -= amp[0];
  jamp[27] += amp[0];
  jamp[66] -= amp[0];
  jamp[68] += amp[0];
  jamp[70] += amp[0];
  jamp[71] -= amp[0];
  jamp[72] -= amp[0];
  jamp[73] += amp[0];
  jamp[78] += amp[0];
  jamp[79] -= amp[0];
  jamp[108] += amp[0];
  jamp[110] -= amp[0];
  jamp[112] -= amp[0];
  jamp[113] += amp[0];

  // *** DIAGRAM 18 OF 1240 ***

  // Wavefunction(s) for diagram number 18
  // (none)

  // Amplitude(s) for diagram number 18
  VVV1_0( w[27], w[5], w[25], COUPs[0], &amp[0] );
#ifdef MGONGPU_SUPPORTS_MULTICHANNEL
  if( channelId == 18 ) allNumerators[0] += cxabs2( amp[0] );
  if( channelId != 0 ) allDenominators[0] += cxabs2( amp[0] );
#endif
  jamp[1] += amp[0];
  jamp[2] -= amp[0];
  jamp[3] += amp[0];
  jamp[4] -= amp[0];
  jamp[25] -= amp[0];
  jamp[26] += amp[0];
  jamp[27] -= amp[0];
  jamp[28] += amp[0];
  jamp[70] -= amp[0];
  jamp[71] += amp[0];
  jamp[88] += amp[0];
  jamp[89] -= amp[0];
  jamp[94] -= amp[0];
  jamp[95] += amp[0];
  jamp[112] += amp[0];
  jamp[113] -= amp[0];

  // *** DIAGRAM 19 OF 1240 ***

  // Wavefunction(s) for diagram number 19
  VVV1P0_1( w[7], w[27], COUPs[0], 0., 0., w[28] );

  // Amplitude(s) for diagram number 19
  VVV1_0( w[8], w[5], w[28], COUPs[0], &amp[0] );
#ifdef MGONGPU_SUPPORTS_MULTICHANNEL
  if( channelId == 19 ) allNumerators[0] += cxabs2( amp[0] );
  if( channelId != 0 ) allDenominators[0] += cxabs2( amp[0] );
#endif
  jamp[1] += amp[0];
  jamp[4] -= amp[0];
  jamp[25] -= amp[0];
  jamp[28] += amp[0];
  jamp[66] -= amp[0];
  jamp[68] += amp[0];
  jamp[72] -= amp[0];
  jamp[73] += amp[0];
  jamp[78] += amp[0];
  jamp[79] -= amp[0];
  jamp[88] += amp[0];
  jamp[89] -= amp[0];
  jamp[94] -= amp[0];
  jamp[95] += amp[0];
  jamp[108] += amp[0];
  jamp[110] -= amp[0];

  // *** DIAGRAM 20 OF 1240 ***

  // Wavefunction(s) for diagram number 20
  // (none)

  // Amplitude(s) for diagram number 20
  VVV1_0( w[8], w[27], w[12], COUPs[0], &amp[0] );
#ifdef MGONGPU_SUPPORTS_MULTICHANNEL
  if( channelId == 20 ) allNumerators[0] += cxabs2( amp[0] );
  if( channelId != 0 ) allDenominators[0] += cxabs2( amp[0] );
#endif
  jamp[2] += amp[0];
  jamp[3] -= amp[0];
  jamp[26] -= amp[0];
  jamp[27] += amp[0];
  jamp[66] -= amp[0];
  jamp[68] += amp[0];
  jamp[70] += amp[0];
  jamp[71] -= amp[0];
  jamp[72] -= amp[0];
  jamp[73] += amp[0];
  jamp[78] += amp[0];
  jamp[79] -= amp[0];
  jamp[108] += amp[0];
  jamp[110] -= amp[0];
  jamp[112] -= amp[0];
  jamp[113] += amp[0];

  // *** DIAGRAM 21 OF 1240 ***

  // Wavefunction(s) for diagram number 21
  VVV1P0_1( w[5], w[6], COUPs[0], 0., 0., w[29] );

  // Amplitude(s) for diagram number 21
  VVVV1_0( w[7], w[8], w[4], w[29], COUPs[2], &amp[0] );
  jamp[0] += amp[0];
  jamp[1] -= amp[0];
  jamp[3] -= amp[0];
  jamp[5] += amp[0];
  jamp[24] -= amp[0];
  jamp[25] += amp[0];
  jamp[27] += amp[0];
  jamp[29] -= amp[0];
  jamp[64] -= amp[0];
  jamp[65] += amp[0];
  jamp[70] += amp[0];
  jamp[71] -= amp[0];
  jamp[94] += amp[0];
  jamp[95] -= amp[0];
  jamp[118] -= amp[0];
  jamp[119] += amp[0];
  VVVV3_0( w[7], w[8], w[4], w[29], COUPs[2], &amp[0] );
  jamp[0] += amp[0];
  jamp[1] -= amp[0];
  jamp[24] -= amp[0];
  jamp[25] += amp[0];
  jamp[48] -= amp[0];
  jamp[49] += amp[0];
  jamp[54] += amp[0];
  jamp[55] -= amp[0];
  jamp[90] -= amp[0];
  jamp[92] += amp[0];
  jamp[94] += amp[0];
  jamp[95] -= amp[0];
  jamp[114] += amp[0];
  jamp[116] -= amp[0];
  jamp[118] -= amp[0];
  jamp[119] += amp[0];
  VVVV4_0( w[7], w[8], w[4], w[29], COUPs[2], &amp[0] );
  jamp[3] += amp[0];
  jamp[5] -= amp[0];
  jamp[27] -= amp[0];
  jamp[29] += amp[0];
  jamp[48] -= amp[0];
  jamp[49] += amp[0];
  jamp[54] += amp[0];
  jamp[55] -= amp[0];
  jamp[64] += amp[0];
  jamp[65] -= amp[0];
  jamp[70] -= amp[0];
  jamp[71] += amp[0];
  jamp[90] -= amp[0];
  jamp[92] += amp[0];
  jamp[114] += amp[0];
  jamp[116] -= amp[0];

  // *** DIAGRAM 22 OF 1240 ***

  // Wavefunction(s) for diagram number 22
  // (none)

  // Amplitude(s) for diagram number 22
  VVV1_0( w[4], w[29], w[25], COUPs[0], &amp[0] );
#ifdef MGONGPU_SUPPORTS_MULTICHANNEL
  if( channelId == 22 ) allNumerators[0] += cxabs2( amp[0] );
  if( channelId != 0 ) allDenominators[0] += cxabs2( amp[0] );
#endif
  jamp[0] += amp[0];
  jamp[1] -= amp[0];
  jamp[3] -= amp[0];
  jamp[5] += amp[0];
  jamp[24] -= amp[0];
  jamp[25] += amp[0];
  jamp[27] += amp[0];
  jamp[29] -= amp[0];
  jamp[64] -= amp[0];
  jamp[65] += amp[0];
  jamp[70] += amp[0];
  jamp[71] -= amp[0];
  jamp[94] += amp[0];
  jamp[95] -= amp[0];
  jamp[118] -= amp[0];
  jamp[119] += amp[0];

  // *** DIAGRAM 23 OF 1240 ***

  // Wavefunction(s) for diagram number 23
  // (none)

  // Amplitude(s) for diagram number 23
  VVV1_0( w[8], w[29], w[9], COUPs[0], &amp[0] );
#ifdef MGONGPU_SUPPORTS_MULTICHANNEL
  if( channelId == 23 ) allNumerators[0] += cxabs2( amp[0] );
  if( channelId != 0 ) allDenominators[0] += cxabs2( amp[0] );
#endif
  jamp[0] += amp[0];
  jamp[1] -= amp[0];
  jamp[24] -= amp[0];
  jamp[25] += amp[0];
  jamp[48] -= amp[0];
  jamp[49] += amp[0];
  jamp[54] += amp[0];
  jamp[55] -= amp[0];
  jamp[90] -= amp[0];
  jamp[92] += amp[0];
  jamp[94] += amp[0];
  jamp[95] -= amp[0];
  jamp[114] += amp[0];
  jamp[116] -= amp[0];
  jamp[118] -= amp[0];
  jamp[119] += amp[0];

  // *** DIAGRAM 24 OF 1240 ***

  // Wavefunction(s) for diagram number 24
  VVV1P0_1( w[7], w[29], COUPs[0], 0., 0., w[25] );

  // Amplitude(s) for diagram number 24
  VVV1_0( w[8], w[4], w[25], COUPs[0], &amp[0] );
#ifdef MGONGPU_SUPPORTS_MULTICHANNEL
  if( channelId == 24 ) allNumerators[0] += cxabs2( amp[0] );
  if( channelId != 0 ) allDenominators[0] += cxabs2( amp[0] );
#endif
  jamp[3] += amp[0];
  jamp[5] -= amp[0];
  jamp[27] -= amp[0];
  jamp[29] += amp[0];
  jamp[48] -= amp[0];
  jamp[49] += amp[0];
  jamp[54] += amp[0];
  jamp[55] -= amp[0];
  jamp[64] += amp[0];
  jamp[65] -= amp[0];
  jamp[70] -= amp[0];
  jamp[71] += amp[0];
  jamp[90] -= amp[0];
  jamp[92] += amp[0];
  jamp[114] += amp[0];
  jamp[116] -= amp[0];

  // *** DIAGRAM 25 OF 1240 ***

  // Wavefunction(s) for diagram number 25
  VVVV1P0_1( w[4], w[5], w[6], COUPs[2], 0., 0., w[30] );
  VVVV3P0_1( w[4], w[5], w[6], COUPs[2], 0., 0., w[31] );
  VVVV4P0_1( w[4], w[5], w[6], COUPs[2], 0., 0., w[32] );

  // Amplitude(s) for diagram number 25
  VVV1_0( w[7], w[8], w[30], COUPs[0], &amp[0] );
  jamp[0] += amp[0];
  jamp[1] -= amp[0];
  jamp[3] -= amp[0];
  jamp[5] += amp[0];
  jamp[24] -= amp[0];
  jamp[25] += amp[0];
  jamp[27] += amp[0];
  jamp[29] -= amp[0];
  jamp[64] -= amp[0];
  jamp[65] += amp[0];
  jamp[70] += amp[0];
  jamp[71] -= amp[0];
  jamp[94] += amp[0];
  jamp[95] -= amp[0];
  jamp[118] -= amp[0];
  jamp[119] += amp[0];
  VVV1_0( w[7], w[8], w[31], COUPs[0], &amp[0] );
  jamp[1] -= amp[0];
  jamp[2] += amp[0];
  jamp[3] -= amp[0];
  jamp[4] += amp[0];
  jamp[25] += amp[0];
  jamp[26] -= amp[0];
  jamp[27] += amp[0];
  jamp[28] -= amp[0];
  jamp[70] += amp[0];
  jamp[71] -= amp[0];
  jamp[88] -= amp[0];
  jamp[89] += amp[0];
  jamp[94] += amp[0];
  jamp[95] -= amp[0];
  jamp[112] -= amp[0];
  jamp[113] += amp[0];
  VVV1_0( w[7], w[8], w[32], COUPs[0], &amp[0] );
  jamp[0] -= amp[0];
  jamp[2] += amp[0];
  jamp[4] += amp[0];
  jamp[5] -= amp[0];
  jamp[24] += amp[0];
  jamp[26] -= amp[0];
  jamp[28] -= amp[0];
  jamp[29] += amp[0];
  jamp[64] += amp[0];
  jamp[65] -= amp[0];
  jamp[88] -= amp[0];
  jamp[89] += amp[0];
  jamp[112] -= amp[0];
  jamp[113] += amp[0];
  jamp[118] += amp[0];
  jamp[119] -= amp[0];

  // *** DIAGRAM 26 OF 1240 ***

  // Wavefunction(s) for diagram number 26
  FFV1_1( w[2], w[4], COUPs[1], cIPD[0], cIPD[1], w[33] );
  FFV1_2( w[3], w[7], COUPs[1], cIPD[0], cIPD[1], w[34] );
  FFV1_1( w[33], w[5], COUPs[1], cIPD[0], cIPD[1], w[35] );

  // Amplitude(s) for diagram number 26
  FFV1_0( w[34], w[35], w[6], COUPs[1], &amp[0] );
#ifdef MGONGPU_SUPPORTS_MULTICHANNEL
  if( channelId == 26 ) allNumerators[0] += cxabs2( amp[0] );
  if( channelId != 0 ) allDenominators[0] += cxabs2( amp[0] );
#endif
  jamp[64] += cxtype( 0, 1 ) * amp[0];
  jamp[65] -= cxtype( 0, 1 ) * amp[0];

  // *** DIAGRAM 27 OF 1240 ***

  // Wavefunction(s) for diagram number 27
  FFV1_1( w[33], w[6], COUPs[1], cIPD[0], cIPD[1], w[36] );

  // Amplitude(s) for diagram number 27
  FFV1_0( w[34], w[36], w[5], COUPs[1], &amp[0] );
#ifdef MGONGPU_SUPPORTS_MULTICHANNEL
  if( channelId == 27 ) allNumerators[0] += cxabs2( amp[0] );
  if( channelId != 0 ) allDenominators[0] += cxabs2( amp[0] );
#endif
  jamp[70] += cxtype( 0, 1 ) * amp[0];
  jamp[71] -= cxtype( 0, 1 ) * amp[0];

  // *** DIAGRAM 28 OF 1240 ***

  // Wavefunction(s) for diagram number 28
  FFV1P0_3( w[3], w[33], COUPs[1], 0., 0., w[37] );

  // Amplitude(s) for diagram number 28
  VVV1_0( w[12], w[37], w[6], COUPs[0], &amp[0] );
#ifdef MGONGPU_SUPPORTS_MULTICHANNEL
  if( channelId == 28 ) allNumerators[0] += cxabs2( amp[0] );
  if( channelId != 0 ) allDenominators[0] += cxabs2( amp[0] );
#endif
  jamp[48] += cxtype( 0, 1 ) * amp[0];
  jamp[54] -= cxtype( 0, 1 ) * amp[0];
  jamp[60] -= cxtype( 0, 1 ) * amp[0];
  jamp[62] += cxtype( 0, 1 ) * amp[0];
  jamp[66] -= cxtype( 0, 1 ) * amp[0];
  jamp[68] += cxtype( 0, 1 ) * amp[0];
  jamp[70] += cxtype( 0, 1 ) * amp[0];
  jamp[71] -= cxtype( 0, 1 ) * amp[0];

  // *** DIAGRAM 29 OF 1240 ***

  // Wavefunction(s) for diagram number 29
  // (none)

  // Amplitude(s) for diagram number 29
  FFV1_0( w[3], w[36], w[12], COUPs[1], &amp[0] );
#ifdef MGONGPU_SUPPORTS_MULTICHANNEL
  if( channelId == 29 ) allNumerators[0] += cxabs2( amp[0] );
  if( channelId != 0 ) allDenominators[0] += cxabs2( amp[0] );
#endif
  jamp[66] += amp[0];
  jamp[68] -= amp[0];
  jamp[70] -= amp[0];
  jamp[71] += amp[0];

  // *** DIAGRAM 30 OF 1240 ***

  // Wavefunction(s) for diagram number 30
  // (none)

  // Amplitude(s) for diagram number 30
  VVV1_0( w[14], w[37], w[5], COUPs[0], &amp[0] );
#ifdef MGONGPU_SUPPORTS_MULTICHANNEL
  if( channelId == 30 ) allNumerators[0] += cxabs2( amp[0] );
  if( channelId != 0 ) allDenominators[0] += cxabs2( amp[0] );
#endif
  jamp[49] += cxtype( 0, 1 ) * amp[0];
  jamp[55] -= cxtype( 0, 1 ) * amp[0];
  jamp[60] -= cxtype( 0, 1 ) * amp[0];
  jamp[62] += cxtype( 0, 1 ) * amp[0];
  jamp[64] += cxtype( 0, 1 ) * amp[0];
  jamp[65] -= cxtype( 0, 1 ) * amp[0];
  jamp[66] -= cxtype( 0, 1 ) * amp[0];
  jamp[68] += cxtype( 0, 1 ) * amp[0];

  // *** DIAGRAM 31 OF 1240 ***

  // Wavefunction(s) for diagram number 31
  // (none)

  // Amplitude(s) for diagram number 31
  FFV1_0( w[3], w[35], w[14], COUPs[1], &amp[0] );
#ifdef MGONGPU_SUPPORTS_MULTICHANNEL
  if( channelId == 31 ) allNumerators[0] += cxabs2( amp[0] );
  if( channelId != 0 ) allDenominators[0] += cxabs2( amp[0] );
#endif
  jamp[60] += amp[0];
  jamp[62] -= amp[0];
  jamp[64] -= amp[0];
  jamp[65] += amp[0];

  // *** DIAGRAM 32 OF 1240 ***

  // Wavefunction(s) for diagram number 32
  // (none)

  // Amplitude(s) for diagram number 32
  FFV1_0( w[3], w[33], w[21], COUPs[1], &amp[0] );
  jamp[48] -= cxtype( 0, 1 ) * amp[0];
  jamp[49] += cxtype( 0, 1 ) * amp[0];
  jamp[54] += cxtype( 0, 1 ) * amp[0];
  jamp[55] -= cxtype( 0, 1 ) * amp[0];
  jamp[64] += cxtype( 0, 1 ) * amp[0];
  jamp[65] -= cxtype( 0, 1 ) * amp[0];
  jamp[70] -= cxtype( 0, 1 ) * amp[0];
  jamp[71] += cxtype( 0, 1 ) * amp[0];
  FFV1_0( w[3], w[33], w[22], COUPs[1], &amp[0] );
  jamp[49] += cxtype( 0, 1 ) * amp[0];
  jamp[55] -= cxtype( 0, 1 ) * amp[0];
  jamp[60] -= cxtype( 0, 1 ) * amp[0];
  jamp[62] += cxtype( 0, 1 ) * amp[0];
  jamp[64] += cxtype( 0, 1 ) * amp[0];
  jamp[65] -= cxtype( 0, 1 ) * amp[0];
  jamp[66] -= cxtype( 0, 1 ) * amp[0];
  jamp[68] += cxtype( 0, 1 ) * amp[0];
  FFV1_0( w[3], w[33], w[23], COUPs[1], &amp[0] );
  jamp[48] += cxtype( 0, 1 ) * amp[0];
  jamp[54] -= cxtype( 0, 1 ) * amp[0];
  jamp[60] -= cxtype( 0, 1 ) * amp[0];
  jamp[62] += cxtype( 0, 1 ) * amp[0];
  jamp[66] -= cxtype( 0, 1 ) * amp[0];
  jamp[68] += cxtype( 0, 1 ) * amp[0];
  jamp[70] += cxtype( 0, 1 ) * amp[0];
  jamp[71] -= cxtype( 0, 1 ) * amp[0];

  // *** DIAGRAM 33 OF 1240 ***

  // Wavefunction(s) for diagram number 33
  FFV1_2( w[3], w[5], COUPs[1], cIPD[0], cIPD[1], w[38] );
  FFV1_1( w[33], w[7], COUPs[1], cIPD[0], cIPD[1], w[39] );

  // Amplitude(s) for diagram number 33
  FFV1_0( w[38], w[39], w[6], COUPs[1], &amp[0] );
#ifdef MGONGPU_SUPPORTS_MULTICHANNEL
  if( channelId == 33 ) allNumerators[0] += cxabs2( amp[0] );
  if( channelId != 0 ) allDenominators[0] += cxabs2( amp[0] );
#endif
  jamp[49] += cxtype( 0, 1 ) * amp[0];
  jamp[55] -= cxtype( 0, 1 ) * amp[0];

  // *** DIAGRAM 34 OF 1240 ***

  // Wavefunction(s) for diagram number 34
  FFV1_2( w[38], w[7], COUPs[1], cIPD[0], cIPD[1], w[40] );

  // Amplitude(s) for diagram number 34
  FFV1_0( w[40], w[33], w[6], COUPs[1], &amp[0] );
#ifdef MGONGPU_SUPPORTS_MULTICHANNEL
  if( channelId == 34 ) allNumerators[0] += cxabs2( amp[0] );
  if( channelId != 0 ) allDenominators[0] += cxabs2( amp[0] );
#endif
  jamp[66] += cxtype( 0, 1 ) * amp[0];
  jamp[68] -= cxtype( 0, 1 ) * amp[0];

  // *** DIAGRAM 35 OF 1240 ***

  // Wavefunction(s) for diagram number 35
  // (none)

  // Amplitude(s) for diagram number 35
  FFV1_0( w[38], w[33], w[14], COUPs[1], &amp[0] );
#ifdef MGONGPU_SUPPORTS_MULTICHANNEL
  if( channelId == 35 ) allNumerators[0] += cxabs2( amp[0] );
  if( channelId != 0 ) allDenominators[0] += cxabs2( amp[0] );
#endif
  jamp[49] += amp[0];
  jamp[55] -= amp[0];
  jamp[66] -= amp[0];
  jamp[68] += amp[0];

  // *** DIAGRAM 36 OF 1240 ***

  // Wavefunction(s) for diagram number 36
  FFV1_2( w[3], w[6], COUPs[1], cIPD[0], cIPD[1], w[41] );

  // Amplitude(s) for diagram number 36
  FFV1_0( w[41], w[39], w[5], COUPs[1], &amp[0] );
#ifdef MGONGPU_SUPPORTS_MULTICHANNEL
  if( channelId == 36 ) allNumerators[0] += cxabs2( amp[0] );
  if( channelId != 0 ) allDenominators[0] += cxabs2( amp[0] );
#endif
  jamp[48] += cxtype( 0, 1 ) * amp[0];
  jamp[54] -= cxtype( 0, 1 ) * amp[0];

  // *** DIAGRAM 37 OF 1240 ***

  // Wavefunction(s) for diagram number 37
  FFV1_2( w[41], w[7], COUPs[1], cIPD[0], cIPD[1], w[42] );

  // Amplitude(s) for diagram number 37
  FFV1_0( w[42], w[33], w[5], COUPs[1], &amp[0] );
#ifdef MGONGPU_SUPPORTS_MULTICHANNEL
  if( channelId == 37 ) allNumerators[0] += cxabs2( amp[0] );
  if( channelId != 0 ) allDenominators[0] += cxabs2( amp[0] );
#endif
  jamp[60] += cxtype( 0, 1 ) * amp[0];
  jamp[62] -= cxtype( 0, 1 ) * amp[0];

  // *** DIAGRAM 38 OF 1240 ***

  // Wavefunction(s) for diagram number 38
  // (none)

  // Amplitude(s) for diagram number 38
  FFV1_0( w[41], w[33], w[12], COUPs[1], &amp[0] );
#ifdef MGONGPU_SUPPORTS_MULTICHANNEL
  if( channelId == 38 ) allNumerators[0] += cxabs2( amp[0] );
  if( channelId != 0 ) allDenominators[0] += cxabs2( amp[0] );
#endif
  jamp[48] += amp[0];
  jamp[54] -= amp[0];
  jamp[60] -= amp[0];
  jamp[62] += amp[0];

  // *** DIAGRAM 39 OF 1240 ***

  // Wavefunction(s) for diagram number 39
  // (none)

  // Amplitude(s) for diagram number 39
  FFV1_0( w[3], w[39], w[29], COUPs[1], &amp[0] );
#ifdef MGONGPU_SUPPORTS_MULTICHANNEL
  if( channelId == 39 ) allNumerators[0] += cxabs2( amp[0] );
  if( channelId != 0 ) allDenominators[0] += cxabs2( amp[0] );
#endif
  jamp[48] += amp[0];
  jamp[49] -= amp[0];
  jamp[54] -= amp[0];
  jamp[55] += amp[0];

  // *** DIAGRAM 40 OF 1240 ***

  // Wavefunction(s) for diagram number 40
  // (none)

  // Amplitude(s) for diagram number 40
  FFV1_0( w[34], w[33], w[29], COUPs[1], &amp[0] );
#ifdef MGONGPU_SUPPORTS_MULTICHANNEL
  if( channelId == 40 ) allNumerators[0] += cxabs2( amp[0] );
  if( channelId != 0 ) allDenominators[0] += cxabs2( amp[0] );
#endif
  jamp[64] += amp[0];
  jamp[65] -= amp[0];
  jamp[70] -= amp[0];
  jamp[71] += amp[0];

  // *** DIAGRAM 41 OF 1240 ***

  // Wavefunction(s) for diagram number 41
  // (none)

  // Amplitude(s) for diagram number 41
  FFV1_0( w[3], w[33], w[25], COUPs[1], &amp[0] );
#ifdef MGONGPU_SUPPORTS_MULTICHANNEL
  if( channelId == 41 ) allNumerators[0] += cxabs2( amp[0] );
  if( channelId != 0 ) allDenominators[0] += cxabs2( amp[0] );
#endif
  jamp[48] -= cxtype( 0, 1 ) * amp[0];
  jamp[49] += cxtype( 0, 1 ) * amp[0];
  jamp[54] += cxtype( 0, 1 ) * amp[0];
  jamp[55] -= cxtype( 0, 1 ) * amp[0];
  jamp[64] += cxtype( 0, 1 ) * amp[0];
  jamp[65] -= cxtype( 0, 1 ) * amp[0];
  jamp[70] -= cxtype( 0, 1 ) * amp[0];
  jamp[71] += cxtype( 0, 1 ) * amp[0];

  // *** DIAGRAM 42 OF 1240 ***

  // Wavefunction(s) for diagram number 42
  FFV1_1( w[2], w[5], COUPs[1], cIPD[0], cIPD[1], w[39] );
  FFV1_1( w[39], w[4], COUPs[1], cIPD[0], cIPD[1], w[43] );

  // Amplitude(s) for diagram number 42
  FFV1_0( w[34], w[43], w[6], COUPs[1], &amp[0] );
#ifdef MGONGPU_SUPPORTS_MULTICHANNEL
  if( channelId == 42 ) allNumerators[0] += cxabs2( amp[0] );
  if( channelId != 0 ) allDenominators[0] += cxabs2( amp[0] );
#endif
  jamp[88] += cxtype( 0, 1 ) * amp[0];
  jamp[89] -= cxtype( 0, 1 ) * amp[0];

  // *** DIAGRAM 43 OF 1240 ***

  // Wavefunction(s) for diagram number 43
  FFV1_1( w[39], w[6], COUPs[1], cIPD[0], cIPD[1], w[44] );

  // Amplitude(s) for diagram number 43
  FFV1_0( w[34], w[44], w[4], COUPs[1], &amp[0] );
#ifdef MGONGPU_SUPPORTS_MULTICHANNEL
  if( channelId == 43 ) allNumerators[0] += cxabs2( amp[0] );
  if( channelId != 0 ) allDenominators[0] += cxabs2( amp[0] );
#endif
  jamp[94] += cxtype( 0, 1 ) * amp[0];
  jamp[95] -= cxtype( 0, 1 ) * amp[0];

  // *** DIAGRAM 44 OF 1240 ***

  // Wavefunction(s) for diagram number 44
  FFV1P0_3( w[3], w[39], COUPs[1], 0., 0., w[45] );

  // Amplitude(s) for diagram number 44
  VVV1_0( w[9], w[45], w[6], COUPs[0], &amp[0] );
#ifdef MGONGPU_SUPPORTS_MULTICHANNEL
  if( channelId == 44 ) allNumerators[0] += cxabs2( amp[0] );
  if( channelId != 0 ) allDenominators[0] += cxabs2( amp[0] );
#endif
  jamp[72] += cxtype( 0, 1 ) * amp[0];
  jamp[78] -= cxtype( 0, 1 ) * amp[0];
  jamp[84] -= cxtype( 0, 1 ) * amp[0];
  jamp[86] += cxtype( 0, 1 ) * amp[0];
  jamp[90] -= cxtype( 0, 1 ) * amp[0];
  jamp[92] += cxtype( 0, 1 ) * amp[0];
  jamp[94] += cxtype( 0, 1 ) * amp[0];
  jamp[95] -= cxtype( 0, 1 ) * amp[0];

  // *** DIAGRAM 45 OF 1240 ***

  // Wavefunction(s) for diagram number 45
  // (none)

  // Amplitude(s) for diagram number 45
  FFV1_0( w[3], w[44], w[9], COUPs[1], &amp[0] );
#ifdef MGONGPU_SUPPORTS_MULTICHANNEL
  if( channelId == 45 ) allNumerators[0] += cxabs2( amp[0] );
  if( channelId != 0 ) allDenominators[0] += cxabs2( amp[0] );
#endif
  jamp[90] += amp[0];
  jamp[92] -= amp[0];
  jamp[94] -= amp[0];
  jamp[95] += amp[0];

  // *** DIAGRAM 46 OF 1240 ***

  // Wavefunction(s) for diagram number 46
  // (none)

  // Amplitude(s) for diagram number 46
  VVV1_0( w[14], w[45], w[4], COUPs[0], &amp[0] );
#ifdef MGONGPU_SUPPORTS_MULTICHANNEL
  if( channelId == 46 ) allNumerators[0] += cxabs2( amp[0] );
  if( channelId != 0 ) allDenominators[0] += cxabs2( amp[0] );
#endif
  jamp[73] += cxtype( 0, 1 ) * amp[0];
  jamp[79] -= cxtype( 0, 1 ) * amp[0];
  jamp[84] -= cxtype( 0, 1 ) * amp[0];
  jamp[86] += cxtype( 0, 1 ) * amp[0];
  jamp[88] += cxtype( 0, 1 ) * amp[0];
  jamp[89] -= cxtype( 0, 1 ) * amp[0];
  jamp[90] -= cxtype( 0, 1 ) * amp[0];
  jamp[92] += cxtype( 0, 1 ) * amp[0];

  // *** DIAGRAM 47 OF 1240 ***

  // Wavefunction(s) for diagram number 47
  // (none)

  // Amplitude(s) for diagram number 47
  FFV1_0( w[3], w[43], w[14], COUPs[1], &amp[0] );
#ifdef MGONGPU_SUPPORTS_MULTICHANNEL
  if( channelId == 47 ) allNumerators[0] += cxabs2( amp[0] );
  if( channelId != 0 ) allDenominators[0] += cxabs2( amp[0] );
#endif
  jamp[84] += amp[0];
  jamp[86] -= amp[0];
  jamp[88] -= amp[0];
  jamp[89] += amp[0];

  // *** DIAGRAM 48 OF 1240 ***

  // Wavefunction(s) for diagram number 48
  // (none)

  // Amplitude(s) for diagram number 48
  FFV1_0( w[3], w[39], w[18], COUPs[1], &amp[0] );
  jamp[72] -= cxtype( 0, 1 ) * amp[0];
  jamp[73] += cxtype( 0, 1 ) * amp[0];
  jamp[78] += cxtype( 0, 1 ) * amp[0];
  jamp[79] -= cxtype( 0, 1 ) * amp[0];
  jamp[88] += cxtype( 0, 1 ) * amp[0];
  jamp[89] -= cxtype( 0, 1 ) * amp[0];
  jamp[94] -= cxtype( 0, 1 ) * amp[0];
  jamp[95] += cxtype( 0, 1 ) * amp[0];
  FFV1_0( w[3], w[39], w[19], COUPs[1], &amp[0] );
  jamp[73] += cxtype( 0, 1 ) * amp[0];
  jamp[79] -= cxtype( 0, 1 ) * amp[0];
  jamp[84] -= cxtype( 0, 1 ) * amp[0];
  jamp[86] += cxtype( 0, 1 ) * amp[0];
  jamp[88] += cxtype( 0, 1 ) * amp[0];
  jamp[89] -= cxtype( 0, 1 ) * amp[0];
  jamp[90] -= cxtype( 0, 1 ) * amp[0];
  jamp[92] += cxtype( 0, 1 ) * amp[0];
  FFV1_0( w[3], w[39], w[20], COUPs[1], &amp[0] );
  jamp[72] += cxtype( 0, 1 ) * amp[0];
  jamp[78] -= cxtype( 0, 1 ) * amp[0];
  jamp[84] -= cxtype( 0, 1 ) * amp[0];
  jamp[86] += cxtype( 0, 1 ) * amp[0];
  jamp[90] -= cxtype( 0, 1 ) * amp[0];
  jamp[92] += cxtype( 0, 1 ) * amp[0];
  jamp[94] += cxtype( 0, 1 ) * amp[0];
  jamp[95] -= cxtype( 0, 1 ) * amp[0];

  // *** DIAGRAM 49 OF 1240 ***

  // Wavefunction(s) for diagram number 49
  FFV1_2( w[3], w[4], COUPs[1], cIPD[0], cIPD[1], w[46] );
  FFV1_1( w[39], w[7], COUPs[1], cIPD[0], cIPD[1], w[47] );

  // Amplitude(s) for diagram number 49
  FFV1_0( w[46], w[47], w[6], COUPs[1], &amp[0] );
#ifdef MGONGPU_SUPPORTS_MULTICHANNEL
  if( channelId == 49 ) allNumerators[0] += cxabs2( amp[0] );
  if( channelId != 0 ) allDenominators[0] += cxabs2( amp[0] );
#endif
  jamp[73] += cxtype( 0, 1 ) * amp[0];
  jamp[79] -= cxtype( 0, 1 ) * amp[0];

  // *** DIAGRAM 50 OF 1240 ***

  // Wavefunction(s) for diagram number 50
  FFV1_2( w[46], w[7], COUPs[1], cIPD[0], cIPD[1], w[48] );

  // Amplitude(s) for diagram number 50
  FFV1_0( w[48], w[39], w[6], COUPs[1], &amp[0] );
#ifdef MGONGPU_SUPPORTS_MULTICHANNEL
  if( channelId == 50 ) allNumerators[0] += cxabs2( amp[0] );
  if( channelId != 0 ) allDenominators[0] += cxabs2( amp[0] );
#endif
  jamp[90] += cxtype( 0, 1 ) * amp[0];
  jamp[92] -= cxtype( 0, 1 ) * amp[0];

  // *** DIAGRAM 51 OF 1240 ***

  // Wavefunction(s) for diagram number 51
  // (none)

  // Amplitude(s) for diagram number 51
  FFV1_0( w[46], w[39], w[14], COUPs[1], &amp[0] );
#ifdef MGONGPU_SUPPORTS_MULTICHANNEL
  if( channelId == 51 ) allNumerators[0] += cxabs2( amp[0] );
  if( channelId != 0 ) allDenominators[0] += cxabs2( amp[0] );
#endif
  jamp[73] += amp[0];
  jamp[79] -= amp[0];
  jamp[90] -= amp[0];
  jamp[92] += amp[0];

  // *** DIAGRAM 52 OF 1240 ***

  // Wavefunction(s) for diagram number 52
  // (none)

  // Amplitude(s) for diagram number 52
  FFV1_0( w[41], w[47], w[4], COUPs[1], &amp[0] );
#ifdef MGONGPU_SUPPORTS_MULTICHANNEL
  if( channelId == 52 ) allNumerators[0] += cxabs2( amp[0] );
  if( channelId != 0 ) allDenominators[0] += cxabs2( amp[0] );
#endif
  jamp[72] += cxtype( 0, 1 ) * amp[0];
  jamp[78] -= cxtype( 0, 1 ) * amp[0];

  // *** DIAGRAM 53 OF 1240 ***

  // Wavefunction(s) for diagram number 53
  // (none)

  // Amplitude(s) for diagram number 53
  FFV1_0( w[42], w[39], w[4], COUPs[1], &amp[0] );
#ifdef MGONGPU_SUPPORTS_MULTICHANNEL
  if( channelId == 53 ) allNumerators[0] += cxabs2( amp[0] );
  if( channelId != 0 ) allDenominators[0] += cxabs2( amp[0] );
#endif
  jamp[84] += cxtype( 0, 1 ) * amp[0];
  jamp[86] -= cxtype( 0, 1 ) * amp[0];

  // *** DIAGRAM 54 OF 1240 ***

  // Wavefunction(s) for diagram number 54
  // (none)

  // Amplitude(s) for diagram number 54
  FFV1_0( w[41], w[39], w[9], COUPs[1], &amp[0] );
#ifdef MGONGPU_SUPPORTS_MULTICHANNEL
  if( channelId == 54 ) allNumerators[0] += cxabs2( amp[0] );
  if( channelId != 0 ) allDenominators[0] += cxabs2( amp[0] );
#endif
  jamp[72] += amp[0];
  jamp[78] -= amp[0];
  jamp[84] -= amp[0];
  jamp[86] += amp[0];

  // *** DIAGRAM 55 OF 1240 ***

  // Wavefunction(s) for diagram number 55
  // (none)

  // Amplitude(s) for diagram number 55
  FFV1_0( w[3], w[47], w[27], COUPs[1], &amp[0] );
#ifdef MGONGPU_SUPPORTS_MULTICHANNEL
  if( channelId == 55 ) allNumerators[0] += cxabs2( amp[0] );
  if( channelId != 0 ) allDenominators[0] += cxabs2( amp[0] );
#endif
  jamp[72] += amp[0];
  jamp[73] -= amp[0];
  jamp[78] -= amp[0];
  jamp[79] += amp[0];

  // *** DIAGRAM 56 OF 1240 ***

  // Wavefunction(s) for diagram number 56
  // (none)

  // Amplitude(s) for diagram number 56
  FFV1_0( w[34], w[39], w[27], COUPs[1], &amp[0] );
#ifdef MGONGPU_SUPPORTS_MULTICHANNEL
  if( channelId == 56 ) allNumerators[0] += cxabs2( amp[0] );
  if( channelId != 0 ) allDenominators[0] += cxabs2( amp[0] );
#endif
  jamp[88] += amp[0];
  jamp[89] -= amp[0];
  jamp[94] -= amp[0];
  jamp[95] += amp[0];

  // *** DIAGRAM 57 OF 1240 ***

  // Wavefunction(s) for diagram number 57
  // (none)

  // Amplitude(s) for diagram number 57
  FFV1_0( w[3], w[39], w[28], COUPs[1], &amp[0] );
#ifdef MGONGPU_SUPPORTS_MULTICHANNEL
  if( channelId == 57 ) allNumerators[0] += cxabs2( amp[0] );
  if( channelId != 0 ) allDenominators[0] += cxabs2( amp[0] );
#endif
  jamp[72] -= cxtype( 0, 1 ) * amp[0];
  jamp[73] += cxtype( 0, 1 ) * amp[0];
  jamp[78] += cxtype( 0, 1 ) * amp[0];
  jamp[79] -= cxtype( 0, 1 ) * amp[0];
  jamp[88] += cxtype( 0, 1 ) * amp[0];
  jamp[89] -= cxtype( 0, 1 ) * amp[0];
  jamp[94] -= cxtype( 0, 1 ) * amp[0];
  jamp[95] += cxtype( 0, 1 ) * amp[0];

  // *** DIAGRAM 58 OF 1240 ***

  // Wavefunction(s) for diagram number 58
  FFV1_1( w[2], w[6], COUPs[1], cIPD[0], cIPD[1], w[47] );
  FFV1_1( w[47], w[4], COUPs[1], cIPD[0], cIPD[1], w[49] );

  // Amplitude(s) for diagram number 58
  FFV1_0( w[34], w[49], w[5], COUPs[1], &amp[0] );
#ifdef MGONGPU_SUPPORTS_MULTICHANNEL
  if( channelId == 58 ) allNumerators[0] += cxabs2( amp[0] );
  if( channelId != 0 ) allDenominators[0] += cxabs2( amp[0] );
#endif
  jamp[112] += cxtype( 0, 1 ) * amp[0];
  jamp[113] -= cxtype( 0, 1 ) * amp[0];

  // *** DIAGRAM 59 OF 1240 ***

  // Wavefunction(s) for diagram number 59
  FFV1_1( w[47], w[5], COUPs[1], cIPD[0], cIPD[1], w[50] );

  // Amplitude(s) for diagram number 59
  FFV1_0( w[34], w[50], w[4], COUPs[1], &amp[0] );
#ifdef MGONGPU_SUPPORTS_MULTICHANNEL
  if( channelId == 59 ) allNumerators[0] += cxabs2( amp[0] );
  if( channelId != 0 ) allDenominators[0] += cxabs2( amp[0] );
#endif
  jamp[118] += cxtype( 0, 1 ) * amp[0];
  jamp[119] -= cxtype( 0, 1 ) * amp[0];

  // *** DIAGRAM 60 OF 1240 ***

  // Wavefunction(s) for diagram number 60
  FFV1P0_3( w[3], w[47], COUPs[1], 0., 0., w[51] );

  // Amplitude(s) for diagram number 60
  VVV1_0( w[9], w[51], w[5], COUPs[0], &amp[0] );
#ifdef MGONGPU_SUPPORTS_MULTICHANNEL
  if( channelId == 60 ) allNumerators[0] += cxabs2( amp[0] );
  if( channelId != 0 ) allDenominators[0] += cxabs2( amp[0] );
#endif
  jamp[96] += cxtype( 0, 1 ) * amp[0];
  jamp[102] -= cxtype( 0, 1 ) * amp[0];
  jamp[108] -= cxtype( 0, 1 ) * amp[0];
  jamp[110] += cxtype( 0, 1 ) * amp[0];
  jamp[114] -= cxtype( 0, 1 ) * amp[0];
  jamp[116] += cxtype( 0, 1 ) * amp[0];
  jamp[118] += cxtype( 0, 1 ) * amp[0];
  jamp[119] -= cxtype( 0, 1 ) * amp[0];

  // *** DIAGRAM 61 OF 1240 ***

  // Wavefunction(s) for diagram number 61
  // (none)

  // Amplitude(s) for diagram number 61
  FFV1_0( w[3], w[50], w[9], COUPs[1], &amp[0] );
#ifdef MGONGPU_SUPPORTS_MULTICHANNEL
  if( channelId == 61 ) allNumerators[0] += cxabs2( amp[0] );
  if( channelId != 0 ) allDenominators[0] += cxabs2( amp[0] );
#endif
  jamp[114] += amp[0];
  jamp[116] -= amp[0];
  jamp[118] -= amp[0];
  jamp[119] += amp[0];

  // *** DIAGRAM 62 OF 1240 ***

  // Wavefunction(s) for diagram number 62
  // (none)

  // Amplitude(s) for diagram number 62
  VVV1_0( w[12], w[51], w[4], COUPs[0], &amp[0] );
#ifdef MGONGPU_SUPPORTS_MULTICHANNEL
  if( channelId == 62 ) allNumerators[0] += cxabs2( amp[0] );
  if( channelId != 0 ) allDenominators[0] += cxabs2( amp[0] );
#endif
  jamp[97] += cxtype( 0, 1 ) * amp[0];
  jamp[103] -= cxtype( 0, 1 ) * amp[0];
  jamp[108] -= cxtype( 0, 1 ) * amp[0];
  jamp[110] += cxtype( 0, 1 ) * amp[0];
  jamp[112] += cxtype( 0, 1 ) * amp[0];
  jamp[113] -= cxtype( 0, 1 ) * amp[0];
  jamp[114] -= cxtype( 0, 1 ) * amp[0];
  jamp[116] += cxtype( 0, 1 ) * amp[0];

  // *** DIAGRAM 63 OF 1240 ***

  // Wavefunction(s) for diagram number 63
  // (none)

  // Amplitude(s) for diagram number 63
  FFV1_0( w[3], w[49], w[12], COUPs[1], &amp[0] );
#ifdef MGONGPU_SUPPORTS_MULTICHANNEL
  if( channelId == 63 ) allNumerators[0] += cxabs2( amp[0] );
  if( channelId != 0 ) allDenominators[0] += cxabs2( amp[0] );
#endif
  jamp[108] += amp[0];
  jamp[110] -= amp[0];
  jamp[112] -= amp[0];
  jamp[113] += amp[0];

  // *** DIAGRAM 64 OF 1240 ***

  // Wavefunction(s) for diagram number 64
  // (none)

  // Amplitude(s) for diagram number 64
  FFV1_0( w[3], w[47], w[15], COUPs[1], &amp[0] );
  jamp[96] -= cxtype( 0, 1 ) * amp[0];
  jamp[97] += cxtype( 0, 1 ) * amp[0];
  jamp[102] += cxtype( 0, 1 ) * amp[0];
  jamp[103] -= cxtype( 0, 1 ) * amp[0];
  jamp[112] += cxtype( 0, 1 ) * amp[0];
  jamp[113] -= cxtype( 0, 1 ) * amp[0];
  jamp[118] -= cxtype( 0, 1 ) * amp[0];
  jamp[119] += cxtype( 0, 1 ) * amp[0];
  FFV1_0( w[3], w[47], w[16], COUPs[1], &amp[0] );
  jamp[97] += cxtype( 0, 1 ) * amp[0];
  jamp[103] -= cxtype( 0, 1 ) * amp[0];
  jamp[108] -= cxtype( 0, 1 ) * amp[0];
  jamp[110] += cxtype( 0, 1 ) * amp[0];
  jamp[112] += cxtype( 0, 1 ) * amp[0];
  jamp[113] -= cxtype( 0, 1 ) * amp[0];
  jamp[114] -= cxtype( 0, 1 ) * amp[0];
  jamp[116] += cxtype( 0, 1 ) * amp[0];
  FFV1_0( w[3], w[47], w[17], COUPs[1], &amp[0] );
  jamp[96] += cxtype( 0, 1 ) * amp[0];
  jamp[102] -= cxtype( 0, 1 ) * amp[0];
  jamp[108] -= cxtype( 0, 1 ) * amp[0];
  jamp[110] += cxtype( 0, 1 ) * amp[0];
  jamp[114] -= cxtype( 0, 1 ) * amp[0];
  jamp[116] += cxtype( 0, 1 ) * amp[0];
  jamp[118] += cxtype( 0, 1 ) * amp[0];
  jamp[119] -= cxtype( 0, 1 ) * amp[0];

  // *** DIAGRAM 65 OF 1240 ***

  // Wavefunction(s) for diagram number 65
  FFV1_1( w[47], w[7], COUPs[1], cIPD[0], cIPD[1], w[52] );

  // Amplitude(s) for diagram number 65
  FFV1_0( w[46], w[52], w[5], COUPs[1], &amp[0] );
#ifdef MGONGPU_SUPPORTS_MULTICHANNEL
  if( channelId == 65 ) allNumerators[0] += cxabs2( amp[0] );
  if( channelId != 0 ) allDenominators[0] += cxabs2( amp[0] );
#endif
  jamp[97] += cxtype( 0, 1 ) * amp[0];
  jamp[103] -= cxtype( 0, 1 ) * amp[0];

  // *** DIAGRAM 66 OF 1240 ***

  // Wavefunction(s) for diagram number 66
  // (none)

  // Amplitude(s) for diagram number 66
  FFV1_0( w[48], w[47], w[5], COUPs[1], &amp[0] );
#ifdef MGONGPU_SUPPORTS_MULTICHANNEL
  if( channelId == 66 ) allNumerators[0] += cxabs2( amp[0] );
  if( channelId != 0 ) allDenominators[0] += cxabs2( amp[0] );
#endif
  jamp[114] += cxtype( 0, 1 ) * amp[0];
  jamp[116] -= cxtype( 0, 1 ) * amp[0];

  // *** DIAGRAM 67 OF 1240 ***

  // Wavefunction(s) for diagram number 67
  // (none)

  // Amplitude(s) for diagram number 67
  FFV1_0( w[46], w[47], w[12], COUPs[1], &amp[0] );
#ifdef MGONGPU_SUPPORTS_MULTICHANNEL
  if( channelId == 67 ) allNumerators[0] += cxabs2( amp[0] );
  if( channelId != 0 ) allDenominators[0] += cxabs2( amp[0] );
#endif
  jamp[97] += amp[0];
  jamp[103] -= amp[0];
  jamp[114] -= amp[0];
  jamp[116] += amp[0];

  // *** DIAGRAM 68 OF 1240 ***

  // Wavefunction(s) for diagram number 68
  // (none)

  // Amplitude(s) for diagram number 68
  FFV1_0( w[38], w[52], w[4], COUPs[1], &amp[0] );
#ifdef MGONGPU_SUPPORTS_MULTICHANNEL
  if( channelId == 68 ) allNumerators[0] += cxabs2( amp[0] );
  if( channelId != 0 ) allDenominators[0] += cxabs2( amp[0] );
#endif
  jamp[96] += cxtype( 0, 1 ) * amp[0];
  jamp[102] -= cxtype( 0, 1 ) * amp[0];

  // *** DIAGRAM 69 OF 1240 ***

  // Wavefunction(s) for diagram number 69
  // (none)

  // Amplitude(s) for diagram number 69
  FFV1_0( w[40], w[47], w[4], COUPs[1], &amp[0] );
#ifdef MGONGPU_SUPPORTS_MULTICHANNEL
  if( channelId == 69 ) allNumerators[0] += cxabs2( amp[0] );
  if( channelId != 0 ) allDenominators[0] += cxabs2( amp[0] );
#endif
  jamp[108] += cxtype( 0, 1 ) * amp[0];
  jamp[110] -= cxtype( 0, 1 ) * amp[0];

  // *** DIAGRAM 70 OF 1240 ***

  // Wavefunction(s) for diagram number 70
  // (none)

  // Amplitude(s) for diagram number 70
  FFV1_0( w[38], w[47], w[9], COUPs[1], &amp[0] );
#ifdef MGONGPU_SUPPORTS_MULTICHANNEL
  if( channelId == 70 ) allNumerators[0] += cxabs2( amp[0] );
  if( channelId != 0 ) allDenominators[0] += cxabs2( amp[0] );
#endif
  jamp[96] += amp[0];
  jamp[102] -= amp[0];
  jamp[108] -= amp[0];
  jamp[110] += amp[0];

  // *** DIAGRAM 71 OF 1240 ***

  // Wavefunction(s) for diagram number 71
  // (none)

  // Amplitude(s) for diagram number 71
  FFV1_0( w[3], w[52], w[24], COUPs[1], &amp[0] );
#ifdef MGONGPU_SUPPORTS_MULTICHANNEL
  if( channelId == 71 ) allNumerators[0] += cxabs2( amp[0] );
  if( channelId != 0 ) allDenominators[0] += cxabs2( amp[0] );
#endif
  jamp[96] += amp[0];
  jamp[97] -= amp[0];
  jamp[102] -= amp[0];
  jamp[103] += amp[0];

  // *** DIAGRAM 72 OF 1240 ***

  // Wavefunction(s) for diagram number 72
  // (none)

  // Amplitude(s) for diagram number 72
  FFV1_0( w[34], w[47], w[24], COUPs[1], &amp[0] );
#ifdef MGONGPU_SUPPORTS_MULTICHANNEL
  if( channelId == 72 ) allNumerators[0] += cxabs2( amp[0] );
  if( channelId != 0 ) allDenominators[0] += cxabs2( amp[0] );
#endif
  jamp[112] += amp[0];
  jamp[113] -= amp[0];
  jamp[118] -= amp[0];
  jamp[119] += amp[0];

  // *** DIAGRAM 73 OF 1240 ***

  // Wavefunction(s) for diagram number 73
  // (none)

  // Amplitude(s) for diagram number 73
  FFV1_0( w[3], w[47], w[26], COUPs[1], &amp[0] );
#ifdef MGONGPU_SUPPORTS_MULTICHANNEL
  if( channelId == 73 ) allNumerators[0] += cxabs2( amp[0] );
  if( channelId != 0 ) allDenominators[0] += cxabs2( amp[0] );
#endif
  jamp[96] -= cxtype( 0, 1 ) * amp[0];
  jamp[97] += cxtype( 0, 1 ) * amp[0];
  jamp[102] += cxtype( 0, 1 ) * amp[0];
  jamp[103] -= cxtype( 0, 1 ) * amp[0];
  jamp[112] += cxtype( 0, 1 ) * amp[0];
  jamp[113] -= cxtype( 0, 1 ) * amp[0];
  jamp[118] -= cxtype( 0, 1 ) * amp[0];
  jamp[119] += cxtype( 0, 1 ) * amp[0];

  // *** DIAGRAM 74 OF 1240 ***

  // Wavefunction(s) for diagram number 74
  FFV1_1( w[2], w[7], COUPs[1], cIPD[0], cIPD[1], w[52] );
  FFV1_2( w[46], w[5], COUPs[1], cIPD[0], cIPD[1], w[7] );

  // Amplitude(s) for diagram number 74
  FFV1_0( w[7], w[52], w[6], COUPs[1], &amp[0] );
#ifdef MGONGPU_SUPPORTS_MULTICHANNEL
  if( channelId == 74 ) allNumerators[0] += cxabs2( amp[0] );
  if( channelId != 0 ) allDenominators[0] += cxabs2( amp[0] );
#endif
  jamp[5] += cxtype( 0, 1 ) * amp[0];
  jamp[29] -= cxtype( 0, 1 ) * amp[0];

  // *** DIAGRAM 75 OF 1240 ***

  // Wavefunction(s) for diagram number 75
  FFV1_2( w[46], w[6], COUPs[1], cIPD[0], cIPD[1], w[53] );

  // Amplitude(s) for diagram number 75
  FFV1_0( w[53], w[52], w[5], COUPs[1], &amp[0] );
#ifdef MGONGPU_SUPPORTS_MULTICHANNEL
  if( channelId == 75 ) allNumerators[0] += cxabs2( amp[0] );
  if( channelId != 0 ) allDenominators[0] += cxabs2( amp[0] );
#endif
  jamp[3] += cxtype( 0, 1 ) * amp[0];
  jamp[27] -= cxtype( 0, 1 ) * amp[0];

  // *** DIAGRAM 76 OF 1240 ***

  // Wavefunction(s) for diagram number 76
  FFV1P0_3( w[46], w[2], COUPs[1], 0., 0., w[54] );

  // Amplitude(s) for diagram number 76
  VVV1_0( w[12], w[54], w[6], COUPs[0], &amp[0] );
#ifdef MGONGPU_SUPPORTS_MULTICHANNEL
  if( channelId == 76 ) allNumerators[0] += cxabs2( amp[0] );
  if( channelId != 0 ) allDenominators[0] += cxabs2( amp[0] );
#endif
  jamp[3] += cxtype( 0, 1 ) * amp[0];
  jamp[27] -= cxtype( 0, 1 ) * amp[0];
  jamp[73] -= cxtype( 0, 1 ) * amp[0];
  jamp[79] += cxtype( 0, 1 ) * amp[0];
  jamp[97] -= cxtype( 0, 1 ) * amp[0];
  jamp[103] += cxtype( 0, 1 ) * amp[0];
  jamp[114] += cxtype( 0, 1 ) * amp[0];
  jamp[116] -= cxtype( 0, 1 ) * amp[0];

  // *** DIAGRAM 77 OF 1240 ***

  // Wavefunction(s) for diagram number 77
  // (none)

  // Amplitude(s) for diagram number 77
  FFV1_0( w[53], w[2], w[12], COUPs[1], &amp[0] );
#ifdef MGONGPU_SUPPORTS_MULTICHANNEL
  if( channelId == 77 ) allNumerators[0] += cxabs2( amp[0] );
  if( channelId != 0 ) allDenominators[0] += cxabs2( amp[0] );
#endif
  jamp[3] += amp[0];
  jamp[27] -= amp[0];
  jamp[73] -= amp[0];
  jamp[79] += amp[0];

  // *** DIAGRAM 78 OF 1240 ***

  // Wavefunction(s) for diagram number 78
  // (none)

  // Amplitude(s) for diagram number 78
  VVV1_0( w[14], w[54], w[5], COUPs[0], &amp[0] );
#ifdef MGONGPU_SUPPORTS_MULTICHANNEL
  if( channelId == 78 ) allNumerators[0] += cxabs2( amp[0] );
  if( channelId != 0 ) allDenominators[0] += cxabs2( amp[0] );
#endif
  jamp[5] += cxtype( 0, 1 ) * amp[0];
  jamp[29] -= cxtype( 0, 1 ) * amp[0];
  jamp[73] -= cxtype( 0, 1 ) * amp[0];
  jamp[79] += cxtype( 0, 1 ) * amp[0];
  jamp[90] += cxtype( 0, 1 ) * amp[0];
  jamp[92] -= cxtype( 0, 1 ) * amp[0];
  jamp[97] -= cxtype( 0, 1 ) * amp[0];
  jamp[103] += cxtype( 0, 1 ) * amp[0];

  // *** DIAGRAM 79 OF 1240 ***

  // Wavefunction(s) for diagram number 79
  // (none)

  // Amplitude(s) for diagram number 79
  FFV1_0( w[7], w[2], w[14], COUPs[1], &amp[0] );
#ifdef MGONGPU_SUPPORTS_MULTICHANNEL
  if( channelId == 79 ) allNumerators[0] += cxabs2( amp[0] );
  if( channelId != 0 ) allDenominators[0] += cxabs2( amp[0] );
#endif
  jamp[5] += amp[0];
  jamp[29] -= amp[0];
  jamp[97] -= amp[0];
  jamp[103] += amp[0];

  // *** DIAGRAM 80 OF 1240 ***

  // Wavefunction(s) for diagram number 80
  // (none)

  // Amplitude(s) for diagram number 80
  FFV1_0( w[46], w[2], w[21], COUPs[1], &amp[0] );
  jamp[3] -= cxtype( 0, 1 ) * amp[0];
  jamp[5] += cxtype( 0, 1 ) * amp[0];
  jamp[27] += cxtype( 0, 1 ) * amp[0];
  jamp[29] -= cxtype( 0, 1 ) * amp[0];
  jamp[90] += cxtype( 0, 1 ) * amp[0];
  jamp[92] -= cxtype( 0, 1 ) * amp[0];
  jamp[114] -= cxtype( 0, 1 ) * amp[0];
  jamp[116] += cxtype( 0, 1 ) * amp[0];
  FFV1_0( w[46], w[2], w[22], COUPs[1], &amp[0] );
  jamp[5] += cxtype( 0, 1 ) * amp[0];
  jamp[29] -= cxtype( 0, 1 ) * amp[0];
  jamp[73] -= cxtype( 0, 1 ) * amp[0];
  jamp[79] += cxtype( 0, 1 ) * amp[0];
  jamp[90] += cxtype( 0, 1 ) * amp[0];
  jamp[92] -= cxtype( 0, 1 ) * amp[0];
  jamp[97] -= cxtype( 0, 1 ) * amp[0];
  jamp[103] += cxtype( 0, 1 ) * amp[0];
  FFV1_0( w[46], w[2], w[23], COUPs[1], &amp[0] );
  jamp[3] += cxtype( 0, 1 ) * amp[0];
  jamp[27] -= cxtype( 0, 1 ) * amp[0];
  jamp[73] -= cxtype( 0, 1 ) * amp[0];
  jamp[79] += cxtype( 0, 1 ) * amp[0];
  jamp[97] -= cxtype( 0, 1 ) * amp[0];
  jamp[103] += cxtype( 0, 1 ) * amp[0];
  jamp[114] += cxtype( 0, 1 ) * amp[0];
  jamp[116] -= cxtype( 0, 1 ) * amp[0];

  // *** DIAGRAM 81 OF 1240 ***

  // Wavefunction(s) for diagram number 81
  // (none)

  // Amplitude(s) for diagram number 81
  FFV1_0( w[46], w[52], w[29], COUPs[1], &amp[0] );
#ifdef MGONGPU_SUPPORTS_MULTICHANNEL
  if( channelId == 81 ) allNumerators[0] += cxabs2( amp[0] );
  if( channelId != 0 ) allDenominators[0] += cxabs2( amp[0] );
#endif
  jamp[3] += amp[0];
  jamp[5] -= amp[0];
  jamp[27] -= amp[0];
  jamp[29] += amp[0];

  // *** DIAGRAM 82 OF 1240 ***

  // Wavefunction(s) for diagram number 82
  // (none)

  // Amplitude(s) for diagram number 82
  FFV1_0( w[48], w[2], w[29], COUPs[1], &amp[0] );
#ifdef MGONGPU_SUPPORTS_MULTICHANNEL
  if( channelId == 82 ) allNumerators[0] += cxabs2( amp[0] );
  if( channelId != 0 ) allDenominators[0] += cxabs2( amp[0] );
#endif
  jamp[90] += amp[0];
  jamp[92] -= amp[0];
  jamp[114] -= amp[0];
  jamp[116] += amp[0];

  // *** DIAGRAM 83 OF 1240 ***

  // Wavefunction(s) for diagram number 83
  // (none)

  // Amplitude(s) for diagram number 83
  FFV1_0( w[46], w[2], w[25], COUPs[1], &amp[0] );
#ifdef MGONGPU_SUPPORTS_MULTICHANNEL
  if( channelId == 83 ) allNumerators[0] += cxabs2( amp[0] );
  if( channelId != 0 ) allDenominators[0] += cxabs2( amp[0] );
#endif
  jamp[3] -= cxtype( 0, 1 ) * amp[0];
  jamp[5] += cxtype( 0, 1 ) * amp[0];
  jamp[27] += cxtype( 0, 1 ) * amp[0];
  jamp[29] -= cxtype( 0, 1 ) * amp[0];
  jamp[90] += cxtype( 0, 1 ) * amp[0];
  jamp[92] -= cxtype( 0, 1 ) * amp[0];
  jamp[114] -= cxtype( 0, 1 ) * amp[0];
  jamp[116] += cxtype( 0, 1 ) * amp[0];

  // *** DIAGRAM 84 OF 1240 ***

  // Wavefunction(s) for diagram number 84
  FFV1_2( w[38], w[4], COUPs[1], cIPD[0], cIPD[1], w[25] );

  // Amplitude(s) for diagram number 84
  FFV1_0( w[25], w[52], w[6], COUPs[1], &amp[0] );
#ifdef MGONGPU_SUPPORTS_MULTICHANNEL
  if( channelId == 84 ) allNumerators[0] += cxabs2( amp[0] );
  if( channelId != 0 ) allDenominators[0] += cxabs2( amp[0] );
#endif
  jamp[4] += cxtype( 0, 1 ) * amp[0];
  jamp[28] -= cxtype( 0, 1 ) * amp[0];

  // *** DIAGRAM 85 OF 1240 ***

  // Wavefunction(s) for diagram number 85
  FFV1_2( w[38], w[6], COUPs[1], cIPD[0], cIPD[1], w[48] );

  // Amplitude(s) for diagram number 85
  FFV1_0( w[48], w[52], w[4], COUPs[1], &amp[0] );
#ifdef MGONGPU_SUPPORTS_MULTICHANNEL
  if( channelId == 85 ) allNumerators[0] += cxabs2( amp[0] );
  if( channelId != 0 ) allDenominators[0] += cxabs2( amp[0] );
#endif
  jamp[1] += cxtype( 0, 1 ) * amp[0];
  jamp[25] -= cxtype( 0, 1 ) * amp[0];

  // *** DIAGRAM 86 OF 1240 ***

  // Wavefunction(s) for diagram number 86
  FFV1P0_3( w[38], w[2], COUPs[1], 0., 0., w[23] );

  // Amplitude(s) for diagram number 86
  VVV1_0( w[9], w[23], w[6], COUPs[0], &amp[0] );
#ifdef MGONGPU_SUPPORTS_MULTICHANNEL
  if( channelId == 86 ) allNumerators[0] += cxabs2( amp[0] );
  if( channelId != 0 ) allDenominators[0] += cxabs2( amp[0] );
#endif
  jamp[1] += cxtype( 0, 1 ) * amp[0];
  jamp[25] -= cxtype( 0, 1 ) * amp[0];
  jamp[49] -= cxtype( 0, 1 ) * amp[0];
  jamp[55] += cxtype( 0, 1 ) * amp[0];
  jamp[96] -= cxtype( 0, 1 ) * amp[0];
  jamp[102] += cxtype( 0, 1 ) * amp[0];
  jamp[108] += cxtype( 0, 1 ) * amp[0];
  jamp[110] -= cxtype( 0, 1 ) * amp[0];

  // *** DIAGRAM 87 OF 1240 ***

  // Wavefunction(s) for diagram number 87
  // (none)

  // Amplitude(s) for diagram number 87
  FFV1_0( w[48], w[2], w[9], COUPs[1], &amp[0] );
#ifdef MGONGPU_SUPPORTS_MULTICHANNEL
  if( channelId == 87 ) allNumerators[0] += cxabs2( amp[0] );
  if( channelId != 0 ) allDenominators[0] += cxabs2( amp[0] );
#endif
  jamp[1] += amp[0];
  jamp[25] -= amp[0];
  jamp[49] -= amp[0];
  jamp[55] += amp[0];

  // *** DIAGRAM 88 OF 1240 ***

  // Wavefunction(s) for diagram number 88
  // (none)

  // Amplitude(s) for diagram number 88
  VVV1_0( w[14], w[23], w[4], COUPs[0], &amp[0] );
#ifdef MGONGPU_SUPPORTS_MULTICHANNEL
  if( channelId == 88 ) allNumerators[0] += cxabs2( amp[0] );
  if( channelId != 0 ) allDenominators[0] += cxabs2( amp[0] );
#endif
  jamp[4] += cxtype( 0, 1 ) * amp[0];
  jamp[28] -= cxtype( 0, 1 ) * amp[0];
  jamp[49] -= cxtype( 0, 1 ) * amp[0];
  jamp[55] += cxtype( 0, 1 ) * amp[0];
  jamp[66] += cxtype( 0, 1 ) * amp[0];
  jamp[68] -= cxtype( 0, 1 ) * amp[0];
  jamp[96] -= cxtype( 0, 1 ) * amp[0];
  jamp[102] += cxtype( 0, 1 ) * amp[0];

  // *** DIAGRAM 89 OF 1240 ***

  // Wavefunction(s) for diagram number 89
  // (none)

  // Amplitude(s) for diagram number 89
  FFV1_0( w[25], w[2], w[14], COUPs[1], &amp[0] );
#ifdef MGONGPU_SUPPORTS_MULTICHANNEL
  if( channelId == 89 ) allNumerators[0] += cxabs2( amp[0] );
  if( channelId != 0 ) allDenominators[0] += cxabs2( amp[0] );
#endif
  jamp[4] += amp[0];
  jamp[28] -= amp[0];
  jamp[96] -= amp[0];
  jamp[102] += amp[0];

  // *** DIAGRAM 90 OF 1240 ***

  // Wavefunction(s) for diagram number 90
  // (none)

  // Amplitude(s) for diagram number 90
  FFV1_0( w[38], w[2], w[18], COUPs[1], &amp[0] );
  jamp[1] -= cxtype( 0, 1 ) * amp[0];
  jamp[4] += cxtype( 0, 1 ) * amp[0];
  jamp[25] += cxtype( 0, 1 ) * amp[0];
  jamp[28] -= cxtype( 0, 1 ) * amp[0];
  jamp[66] += cxtype( 0, 1 ) * amp[0];
  jamp[68] -= cxtype( 0, 1 ) * amp[0];
  jamp[108] -= cxtype( 0, 1 ) * amp[0];
  jamp[110] += cxtype( 0, 1 ) * amp[0];
  FFV1_0( w[38], w[2], w[19], COUPs[1], &amp[0] );
  jamp[4] += cxtype( 0, 1 ) * amp[0];
  jamp[28] -= cxtype( 0, 1 ) * amp[0];
  jamp[49] -= cxtype( 0, 1 ) * amp[0];
  jamp[55] += cxtype( 0, 1 ) * amp[0];
  jamp[66] += cxtype( 0, 1 ) * amp[0];
  jamp[68] -= cxtype( 0, 1 ) * amp[0];
  jamp[96] -= cxtype( 0, 1 ) * amp[0];
  jamp[102] += cxtype( 0, 1 ) * amp[0];
  FFV1_0( w[38], w[2], w[20], COUPs[1], &amp[0] );
  jamp[1] += cxtype( 0, 1 ) * amp[0];
  jamp[25] -= cxtype( 0, 1 ) * amp[0];
  jamp[49] -= cxtype( 0, 1 ) * amp[0];
  jamp[55] += cxtype( 0, 1 ) * amp[0];
  jamp[96] -= cxtype( 0, 1 ) * amp[0];
  jamp[102] += cxtype( 0, 1 ) * amp[0];
  jamp[108] += cxtype( 0, 1 ) * amp[0];
  jamp[110] -= cxtype( 0, 1 ) * amp[0];

  // *** DIAGRAM 91 OF 1240 ***

  // Wavefunction(s) for diagram number 91
  // (none)

  // Amplitude(s) for diagram number 91
  FFV1_0( w[38], w[52], w[27], COUPs[1], &amp[0] );
#ifdef MGONGPU_SUPPORTS_MULTICHANNEL
  if( channelId == 91 ) allNumerators[0] += cxabs2( amp[0] );
  if( channelId != 0 ) allDenominators[0] += cxabs2( amp[0] );
#endif
  jamp[1] += amp[0];
  jamp[4] -= amp[0];
  jamp[25] -= amp[0];
  jamp[28] += amp[0];

  // *** DIAGRAM 92 OF 1240 ***

  // Wavefunction(s) for diagram number 92
  // (none)

  // Amplitude(s) for diagram number 92
  FFV1_0( w[40], w[2], w[27], COUPs[1], &amp[0] );
#ifdef MGONGPU_SUPPORTS_MULTICHANNEL
  if( channelId == 92 ) allNumerators[0] += cxabs2( amp[0] );
  if( channelId != 0 ) allDenominators[0] += cxabs2( amp[0] );
#endif
  jamp[66] += amp[0];
  jamp[68] -= amp[0];
  jamp[108] -= amp[0];
  jamp[110] += amp[0];

  // *** DIAGRAM 93 OF 1240 ***

  // Wavefunction(s) for diagram number 93
  // (none)

  // Amplitude(s) for diagram number 93
  FFV1_0( w[38], w[2], w[28], COUPs[1], &amp[0] );
#ifdef MGONGPU_SUPPORTS_MULTICHANNEL
  if( channelId == 93 ) allNumerators[0] += cxabs2( amp[0] );
  if( channelId != 0 ) allDenominators[0] += cxabs2( amp[0] );
#endif
  jamp[1] -= cxtype( 0, 1 ) * amp[0];
  jamp[4] += cxtype( 0, 1 ) * amp[0];
  jamp[25] += cxtype( 0, 1 ) * amp[0];
  jamp[28] -= cxtype( 0, 1 ) * amp[0];
  jamp[66] += cxtype( 0, 1 ) * amp[0];
  jamp[68] -= cxtype( 0, 1 ) * amp[0];
  jamp[108] -= cxtype( 0, 1 ) * amp[0];
  jamp[110] += cxtype( 0, 1 ) * amp[0];

  // *** DIAGRAM 94 OF 1240 ***

  // Wavefunction(s) for diagram number 94
  FFV1_2( w[41], w[4], COUPs[1], cIPD[0], cIPD[1], w[28] );

  // Amplitude(s) for diagram number 94
  FFV1_0( w[28], w[52], w[5], COUPs[1], &amp[0] );
#ifdef MGONGPU_SUPPORTS_MULTICHANNEL
  if( channelId == 94 ) allNumerators[0] += cxabs2( amp[0] );
  if( channelId != 0 ) allDenominators[0] += cxabs2( amp[0] );
#endif
  jamp[2] += cxtype( 0, 1 ) * amp[0];
  jamp[26] -= cxtype( 0, 1 ) * amp[0];

  // *** DIAGRAM 95 OF 1240 ***

  // Wavefunction(s) for diagram number 95
  FFV1_2( w[41], w[5], COUPs[1], cIPD[0], cIPD[1], w[40] );

  // Amplitude(s) for diagram number 95
  FFV1_0( w[40], w[52], w[4], COUPs[1], &amp[0] );
#ifdef MGONGPU_SUPPORTS_MULTICHANNEL
  if( channelId == 95 ) allNumerators[0] += cxabs2( amp[0] );
  if( channelId != 0 ) allDenominators[0] += cxabs2( amp[0] );
#endif
  jamp[0] += cxtype( 0, 1 ) * amp[0];
  jamp[24] -= cxtype( 0, 1 ) * amp[0];

  // *** DIAGRAM 96 OF 1240 ***

  // Wavefunction(s) for diagram number 96
  FFV1P0_3( w[41], w[2], COUPs[1], 0., 0., w[20] );

  // Amplitude(s) for diagram number 96
  VVV1_0( w[9], w[20], w[5], COUPs[0], &amp[0] );
#ifdef MGONGPU_SUPPORTS_MULTICHANNEL
  if( channelId == 96 ) allNumerators[0] += cxabs2( amp[0] );
  if( channelId != 0 ) allDenominators[0] += cxabs2( amp[0] );
#endif
  jamp[0] += cxtype( 0, 1 ) * amp[0];
  jamp[24] -= cxtype( 0, 1 ) * amp[0];
  jamp[48] -= cxtype( 0, 1 ) * amp[0];
  jamp[54] += cxtype( 0, 1 ) * amp[0];
  jamp[72] -= cxtype( 0, 1 ) * amp[0];
  jamp[78] += cxtype( 0, 1 ) * amp[0];
  jamp[84] += cxtype( 0, 1 ) * amp[0];
  jamp[86] -= cxtype( 0, 1 ) * amp[0];

  // *** DIAGRAM 97 OF 1240 ***

  // Wavefunction(s) for diagram number 97
  // (none)

  // Amplitude(s) for diagram number 97
  FFV1_0( w[40], w[2], w[9], COUPs[1], &amp[0] );
#ifdef MGONGPU_SUPPORTS_MULTICHANNEL
  if( channelId == 97 ) allNumerators[0] += cxabs2( amp[0] );
  if( channelId != 0 ) allDenominators[0] += cxabs2( amp[0] );
#endif
  jamp[0] += amp[0];
  jamp[24] -= amp[0];
  jamp[48] -= amp[0];
  jamp[54] += amp[0];

  // *** DIAGRAM 98 OF 1240 ***

  // Wavefunction(s) for diagram number 98
  // (none)

  // Amplitude(s) for diagram number 98
  VVV1_0( w[12], w[20], w[4], COUPs[0], &amp[0] );
#ifdef MGONGPU_SUPPORTS_MULTICHANNEL
  if( channelId == 98 ) allNumerators[0] += cxabs2( amp[0] );
  if( channelId != 0 ) allDenominators[0] += cxabs2( amp[0] );
#endif
  jamp[2] += cxtype( 0, 1 ) * amp[0];
  jamp[26] -= cxtype( 0, 1 ) * amp[0];
  jamp[48] -= cxtype( 0, 1 ) * amp[0];
  jamp[54] += cxtype( 0, 1 ) * amp[0];
  jamp[60] += cxtype( 0, 1 ) * amp[0];
  jamp[62] -= cxtype( 0, 1 ) * amp[0];
  jamp[72] -= cxtype( 0, 1 ) * amp[0];
  jamp[78] += cxtype( 0, 1 ) * amp[0];

  // *** DIAGRAM 99 OF 1240 ***

  // Wavefunction(s) for diagram number 99
  // (none)

  // Amplitude(s) for diagram number 99
  FFV1_0( w[28], w[2], w[12], COUPs[1], &amp[0] );
#ifdef MGONGPU_SUPPORTS_MULTICHANNEL
  if( channelId == 99 ) allNumerators[0] += cxabs2( amp[0] );
  if( channelId != 0 ) allDenominators[0] += cxabs2( amp[0] );
#endif
  jamp[2] += amp[0];
  jamp[26] -= amp[0];
  jamp[72] -= amp[0];
  jamp[78] += amp[0];

  // *** DIAGRAM 100 OF 1240 ***

  // Wavefunction(s) for diagram number 100
  // (none)

  // Amplitude(s) for diagram number 100
  FFV1_0( w[41], w[2], w[15], COUPs[1], &amp[0] );
  jamp[0] -= cxtype( 0, 1 ) * amp[0];
  jamp[2] += cxtype( 0, 1 ) * amp[0];
  jamp[24] += cxtype( 0, 1 ) * amp[0];
  jamp[26] -= cxtype( 0, 1 ) * amp[0];
  jamp[60] += cxtype( 0, 1 ) * amp[0];
  jamp[62] -= cxtype( 0, 1 ) * amp[0];
  jamp[84] -= cxtype( 0, 1 ) * amp[0];
  jamp[86] += cxtype( 0, 1 ) * amp[0];
  FFV1_0( w[41], w[2], w[16], COUPs[1], &amp[0] );
  jamp[2] += cxtype( 0, 1 ) * amp[0];
  jamp[26] -= cxtype( 0, 1 ) * amp[0];
  jamp[48] -= cxtype( 0, 1 ) * amp[0];
  jamp[54] += cxtype( 0, 1 ) * amp[0];
  jamp[60] += cxtype( 0, 1 ) * amp[0];
  jamp[62] -= cxtype( 0, 1 ) * amp[0];
  jamp[72] -= cxtype( 0, 1 ) * amp[0];
  jamp[78] += cxtype( 0, 1 ) * amp[0];
  FFV1_0( w[41], w[2], w[17], COUPs[1], &amp[0] );
  jamp[0] += cxtype( 0, 1 ) * amp[0];
  jamp[24] -= cxtype( 0, 1 ) * amp[0];
  jamp[48] -= cxtype( 0, 1 ) * amp[0];
  jamp[54] += cxtype( 0, 1 ) * amp[0];
  jamp[72] -= cxtype( 0, 1 ) * amp[0];
  jamp[78] += cxtype( 0, 1 ) * amp[0];
  jamp[84] += cxtype( 0, 1 ) * amp[0];
  jamp[86] -= cxtype( 0, 1 ) * amp[0];

  // *** DIAGRAM 101 OF 1240 ***

  // Wavefunction(s) for diagram number 101
  // (none)

  // Amplitude(s) for diagram number 101
  FFV1_0( w[41], w[52], w[24], COUPs[1], &amp[0] );
#ifdef MGONGPU_SUPPORTS_MULTICHANNEL
  if( channelId == 101 ) allNumerators[0] += cxabs2( amp[0] );
  if( channelId != 0 ) allDenominators[0] += cxabs2( amp[0] );
#endif
  jamp[0] += amp[0];
  jamp[2] -= amp[0];
  jamp[24] -= amp[0];
  jamp[26] += amp[0];

  // *** DIAGRAM 102 OF 1240 ***

  // Wavefunction(s) for diagram number 102
  // (none)

  // Amplitude(s) for diagram number 102
  FFV1_0( w[42], w[2], w[24], COUPs[1], &amp[0] );
#ifdef MGONGPU_SUPPORTS_MULTICHANNEL
  if( channelId == 102 ) allNumerators[0] += cxabs2( amp[0] );
  if( channelId != 0 ) allDenominators[0] += cxabs2( amp[0] );
#endif
  jamp[60] += amp[0];
  jamp[62] -= amp[0];
  jamp[84] -= amp[0];
  jamp[86] += amp[0];

  // *** DIAGRAM 103 OF 1240 ***

  // Wavefunction(s) for diagram number 103
  // (none)

  // Amplitude(s) for diagram number 103
  FFV1_0( w[41], w[2], w[26], COUPs[1], &amp[0] );
#ifdef MGONGPU_SUPPORTS_MULTICHANNEL
  if( channelId == 103 ) allNumerators[0] += cxabs2( amp[0] );
  if( channelId != 0 ) allDenominators[0] += cxabs2( amp[0] );
#endif
  jamp[0] -= cxtype( 0, 1 ) * amp[0];
  jamp[2] += cxtype( 0, 1 ) * amp[0];
  jamp[24] += cxtype( 0, 1 ) * amp[0];
  jamp[26] -= cxtype( 0, 1 ) * amp[0];
  jamp[60] += cxtype( 0, 1 ) * amp[0];
  jamp[62] -= cxtype( 0, 1 ) * amp[0];
  jamp[84] -= cxtype( 0, 1 ) * amp[0];
  jamp[86] += cxtype( 0, 1 ) * amp[0];

  // *** DIAGRAM 104 OF 1240 ***

  // Wavefunction(s) for diagram number 104
  FFV1_2( w[3], w[24], COUPs[1], cIPD[0], cIPD[1], w[26] );

  // Amplitude(s) for diagram number 104
  FFV1_0( w[26], w[52], w[6], COUPs[1], &amp[0] );
#ifdef MGONGPU_SUPPORTS_MULTICHANNEL
  if( channelId == 104 ) allNumerators[0] += cxabs2( amp[0] );
  if( channelId != 0 ) allDenominators[0] += cxabs2( amp[0] );
#endif
  jamp[4] += amp[0];
  jamp[5] -= amp[0];
  jamp[28] -= amp[0];
  jamp[29] += amp[0];

  // *** DIAGRAM 105 OF 1240 ***

  // Wavefunction(s) for diagram number 105
  VVV1P0_1( w[24], w[6], COUPs[0], 0., 0., w[42] );

  // Amplitude(s) for diagram number 105
  FFV1_0( w[3], w[52], w[42], COUPs[1], &amp[0] );
#ifdef MGONGPU_SUPPORTS_MULTICHANNEL
  if( channelId == 105 ) allNumerators[0] += cxabs2( amp[0] );
  if( channelId != 0 ) allDenominators[0] += cxabs2( amp[0] );
#endif
  jamp[0] -= cxtype( 0, 1 ) * amp[0];
  jamp[2] += cxtype( 0, 1 ) * amp[0];
  jamp[4] += cxtype( 0, 1 ) * amp[0];
  jamp[5] -= cxtype( 0, 1 ) * amp[0];
  jamp[24] += cxtype( 0, 1 ) * amp[0];
  jamp[26] -= cxtype( 0, 1 ) * amp[0];
  jamp[28] -= cxtype( 0, 1 ) * amp[0];
  jamp[29] += cxtype( 0, 1 ) * amp[0];

  // *** DIAGRAM 106 OF 1240 ***

  // Wavefunction(s) for diagram number 106
  FFV1_1( w[2], w[24], COUPs[1], cIPD[0], cIPD[1], w[17] );

  // Amplitude(s) for diagram number 106
  FFV1_0( w[34], w[17], w[6], COUPs[1], &amp[0] );
#ifdef MGONGPU_SUPPORTS_MULTICHANNEL
  if( channelId == 106 ) allNumerators[0] += cxabs2( amp[0] );
  if( channelId != 0 ) allDenominators[0] += cxabs2( amp[0] );
#endif
  jamp[64] += amp[0];
  jamp[65] -= amp[0];
  jamp[88] -= amp[0];
  jamp[89] += amp[0];

  // *** DIAGRAM 107 OF 1240 ***

  // Wavefunction(s) for diagram number 107
  // (none)

  // Amplitude(s) for diagram number 107
  FFV1_0( w[34], w[2], w[42], COUPs[1], &amp[0] );
#ifdef MGONGPU_SUPPORTS_MULTICHANNEL
  if( channelId == 107 ) allNumerators[0] += cxabs2( amp[0] );
  if( channelId != 0 ) allDenominators[0] += cxabs2( amp[0] );
#endif
  jamp[64] -= cxtype( 0, 1 ) * amp[0];
  jamp[65] += cxtype( 0, 1 ) * amp[0];
  jamp[88] += cxtype( 0, 1 ) * amp[0];
  jamp[89] -= cxtype( 0, 1 ) * amp[0];
  jamp[112] += cxtype( 0, 1 ) * amp[0];
  jamp[113] -= cxtype( 0, 1 ) * amp[0];
  jamp[118] -= cxtype( 0, 1 ) * amp[0];
  jamp[119] += cxtype( 0, 1 ) * amp[0];

  // *** DIAGRAM 108 OF 1240 ***

  // Wavefunction(s) for diagram number 108
  // (none)

  // Amplitude(s) for diagram number 108
  FFV1_0( w[3], w[17], w[14], COUPs[1], &amp[0] );
#ifdef MGONGPU_SUPPORTS_MULTICHANNEL
  if( channelId == 108 ) allNumerators[0] += cxabs2( amp[0] );
  if( channelId != 0 ) allDenominators[0] += cxabs2( amp[0] );
#endif
  jamp[60] -= cxtype( 0, 1 ) * amp[0];
  jamp[62] += cxtype( 0, 1 ) * amp[0];
  jamp[64] += cxtype( 0, 1 ) * amp[0];
  jamp[65] -= cxtype( 0, 1 ) * amp[0];
  jamp[84] += cxtype( 0, 1 ) * amp[0];
  jamp[86] -= cxtype( 0, 1 ) * amp[0];
  jamp[88] -= cxtype( 0, 1 ) * amp[0];
  jamp[89] += cxtype( 0, 1 ) * amp[0];

  // *** DIAGRAM 109 OF 1240 ***

  // Wavefunction(s) for diagram number 109
  // (none)

  // Amplitude(s) for diagram number 109
  FFV1_0( w[26], w[2], w[14], COUPs[1], &amp[0] );
#ifdef MGONGPU_SUPPORTS_MULTICHANNEL
  if( channelId == 109 ) allNumerators[0] += cxabs2( amp[0] );
  if( channelId != 0 ) allDenominators[0] += cxabs2( amp[0] );
#endif
  jamp[4] -= cxtype( 0, 1 ) * amp[0];
  jamp[5] += cxtype( 0, 1 ) * amp[0];
  jamp[28] += cxtype( 0, 1 ) * amp[0];
  jamp[29] -= cxtype( 0, 1 ) * amp[0];
  jamp[96] += cxtype( 0, 1 ) * amp[0];
  jamp[97] -= cxtype( 0, 1 ) * amp[0];
  jamp[102] -= cxtype( 0, 1 ) * amp[0];
  jamp[103] += cxtype( 0, 1 ) * amp[0];

  // *** DIAGRAM 110 OF 1240 ***

  // Wavefunction(s) for diagram number 110
  FFV1_2( w[3], w[27], COUPs[1], cIPD[0], cIPD[1], w[14] );

  // Amplitude(s) for diagram number 110
  FFV1_0( w[14], w[52], w[5], COUPs[1], &amp[0] );
#ifdef MGONGPU_SUPPORTS_MULTICHANNEL
  if( channelId == 110 ) allNumerators[0] += cxabs2( amp[0] );
  if( channelId != 0 ) allDenominators[0] += cxabs2( amp[0] );
#endif
  jamp[2] += amp[0];
  jamp[3] -= amp[0];
  jamp[26] -= amp[0];
  jamp[27] += amp[0];

  // *** DIAGRAM 111 OF 1240 ***

  // Wavefunction(s) for diagram number 111
  VVV1P0_1( w[27], w[5], COUPs[0], 0., 0., w[16] );

  // Amplitude(s) for diagram number 111
  FFV1_0( w[3], w[52], w[16], COUPs[1], &amp[0] );
#ifdef MGONGPU_SUPPORTS_MULTICHANNEL
  if( channelId == 111 ) allNumerators[0] += cxabs2( amp[0] );
  if( channelId != 0 ) allDenominators[0] += cxabs2( amp[0] );
#endif
  jamp[1] -= cxtype( 0, 1 ) * amp[0];
  jamp[2] += cxtype( 0, 1 ) * amp[0];
  jamp[3] -= cxtype( 0, 1 ) * amp[0];
  jamp[4] += cxtype( 0, 1 ) * amp[0];
  jamp[25] += cxtype( 0, 1 ) * amp[0];
  jamp[26] -= cxtype( 0, 1 ) * amp[0];
  jamp[27] += cxtype( 0, 1 ) * amp[0];
  jamp[28] -= cxtype( 0, 1 ) * amp[0];

  // *** DIAGRAM 112 OF 1240 ***

  // Wavefunction(s) for diagram number 112
  FFV1_1( w[2], w[27], COUPs[1], cIPD[0], cIPD[1], w[15] );

  // Amplitude(s) for diagram number 112
  FFV1_0( w[34], w[15], w[5], COUPs[1], &amp[0] );
#ifdef MGONGPU_SUPPORTS_MULTICHANNEL
  if( channelId == 112 ) allNumerators[0] += cxabs2( amp[0] );
  if( channelId != 0 ) allDenominators[0] += cxabs2( amp[0] );
#endif
  jamp[70] += amp[0];
  jamp[71] -= amp[0];
  jamp[112] -= amp[0];
  jamp[113] += amp[0];

  // *** DIAGRAM 113 OF 1240 ***

  // Wavefunction(s) for diagram number 113
  // (none)

  // Amplitude(s) for diagram number 113
  FFV1_0( w[34], w[2], w[16], COUPs[1], &amp[0] );
#ifdef MGONGPU_SUPPORTS_MULTICHANNEL
  if( channelId == 113 ) allNumerators[0] += cxabs2( amp[0] );
  if( channelId != 0 ) allDenominators[0] += cxabs2( amp[0] );
#endif
  jamp[70] -= cxtype( 0, 1 ) * amp[0];
  jamp[71] += cxtype( 0, 1 ) * amp[0];
  jamp[88] += cxtype( 0, 1 ) * amp[0];
  jamp[89] -= cxtype( 0, 1 ) * amp[0];
  jamp[94] -= cxtype( 0, 1 ) * amp[0];
  jamp[95] += cxtype( 0, 1 ) * amp[0];
  jamp[112] += cxtype( 0, 1 ) * amp[0];
  jamp[113] -= cxtype( 0, 1 ) * amp[0];

  // *** DIAGRAM 114 OF 1240 ***

  // Wavefunction(s) for diagram number 114
  // (none)

  // Amplitude(s) for diagram number 114
  FFV1_0( w[3], w[15], w[12], COUPs[1], &amp[0] );
#ifdef MGONGPU_SUPPORTS_MULTICHANNEL
  if( channelId == 114 ) allNumerators[0] += cxabs2( amp[0] );
  if( channelId != 0 ) allDenominators[0] += cxabs2( amp[0] );
#endif
  jamp[66] -= cxtype( 0, 1 ) * amp[0];
  jamp[68] += cxtype( 0, 1 ) * amp[0];
  jamp[70] += cxtype( 0, 1 ) * amp[0];
  jamp[71] -= cxtype( 0, 1 ) * amp[0];
  jamp[108] += cxtype( 0, 1 ) * amp[0];
  jamp[110] -= cxtype( 0, 1 ) * amp[0];
  jamp[112] -= cxtype( 0, 1 ) * amp[0];
  jamp[113] += cxtype( 0, 1 ) * amp[0];

  // *** DIAGRAM 115 OF 1240 ***

  // Wavefunction(s) for diagram number 115
  // (none)

  // Amplitude(s) for diagram number 115
  FFV1_0( w[14], w[2], w[12], COUPs[1], &amp[0] );
#ifdef MGONGPU_SUPPORTS_MULTICHANNEL
  if( channelId == 115 ) allNumerators[0] += cxabs2( amp[0] );
  if( channelId != 0 ) allDenominators[0] += cxabs2( amp[0] );
#endif
  jamp[2] -= cxtype( 0, 1 ) * amp[0];
  jamp[3] += cxtype( 0, 1 ) * amp[0];
  jamp[26] += cxtype( 0, 1 ) * amp[0];
  jamp[27] -= cxtype( 0, 1 ) * amp[0];
  jamp[72] += cxtype( 0, 1 ) * amp[0];
  jamp[73] -= cxtype( 0, 1 ) * amp[0];
  jamp[78] -= cxtype( 0, 1 ) * amp[0];
  jamp[79] += cxtype( 0, 1 ) * amp[0];

  // *** DIAGRAM 116 OF 1240 ***

  // Wavefunction(s) for diagram number 116
  FFV1_2( w[3], w[29], COUPs[1], cIPD[0], cIPD[1], w[12] );

  // Amplitude(s) for diagram number 116
  FFV1_0( w[12], w[52], w[4], COUPs[1], &amp[0] );
#ifdef MGONGPU_SUPPORTS_MULTICHANNEL
  if( channelId == 116 ) allNumerators[0] += cxabs2( amp[0] );
  if( channelId != 0 ) allDenominators[0] += cxabs2( amp[0] );
#endif
  jamp[0] += amp[0];
  jamp[1] -= amp[0];
  jamp[24] -= amp[0];
  jamp[25] += amp[0];

  // *** DIAGRAM 117 OF 1240 ***

  // Wavefunction(s) for diagram number 117
  VVV1P0_1( w[4], w[29], COUPs[0], 0., 0., w[19] );

  // Amplitude(s) for diagram number 117
  FFV1_0( w[3], w[52], w[19], COUPs[1], &amp[0] );
#ifdef MGONGPU_SUPPORTS_MULTICHANNEL
  if( channelId == 117 ) allNumerators[0] += cxabs2( amp[0] );
  if( channelId != 0 ) allDenominators[0] += cxabs2( amp[0] );
#endif
  jamp[0] -= cxtype( 0, 1 ) * amp[0];
  jamp[1] += cxtype( 0, 1 ) * amp[0];
  jamp[3] += cxtype( 0, 1 ) * amp[0];
  jamp[5] -= cxtype( 0, 1 ) * amp[0];
  jamp[24] += cxtype( 0, 1 ) * amp[0];
  jamp[25] -= cxtype( 0, 1 ) * amp[0];
  jamp[27] -= cxtype( 0, 1 ) * amp[0];
  jamp[29] += cxtype( 0, 1 ) * amp[0];

  // *** DIAGRAM 118 OF 1240 ***

  // Wavefunction(s) for diagram number 118
  FFV1_1( w[2], w[29], COUPs[1], cIPD[0], cIPD[1], w[18] );

  // Amplitude(s) for diagram number 118
  FFV1_0( w[34], w[18], w[4], COUPs[1], &amp[0] );
#ifdef MGONGPU_SUPPORTS_MULTICHANNEL
  if( channelId == 118 ) allNumerators[0] += cxabs2( amp[0] );
  if( channelId != 0 ) allDenominators[0] += cxabs2( amp[0] );
#endif
  jamp[94] += amp[0];
  jamp[95] -= amp[0];
  jamp[118] -= amp[0];
  jamp[119] += amp[0];

  // *** DIAGRAM 119 OF 1240 ***

  // Wavefunction(s) for diagram number 119
  // (none)

  // Amplitude(s) for diagram number 119
  FFV1_0( w[34], w[2], w[19], COUPs[1], &amp[0] );
#ifdef MGONGPU_SUPPORTS_MULTICHANNEL
  if( channelId == 119 ) allNumerators[0] += cxabs2( amp[0] );
  if( channelId != 0 ) allDenominators[0] += cxabs2( amp[0] );
#endif
  jamp[64] -= cxtype( 0, 1 ) * amp[0];
  jamp[65] += cxtype( 0, 1 ) * amp[0];
  jamp[70] += cxtype( 0, 1 ) * amp[0];
  jamp[71] -= cxtype( 0, 1 ) * amp[0];
  jamp[94] += cxtype( 0, 1 ) * amp[0];
  jamp[95] -= cxtype( 0, 1 ) * amp[0];
  jamp[118] -= cxtype( 0, 1 ) * amp[0];
  jamp[119] += cxtype( 0, 1 ) * amp[0];

  // *** DIAGRAM 120 OF 1240 ***

  // Wavefunction(s) for diagram number 120
  // (none)

  // Amplitude(s) for diagram number 120
  FFV1_0( w[3], w[18], w[9], COUPs[1], &amp[0] );
#ifdef MGONGPU_SUPPORTS_MULTICHANNEL
  if( channelId == 120 ) allNumerators[0] += cxabs2( amp[0] );
  if( channelId != 0 ) allDenominators[0] += cxabs2( amp[0] );
#endif
  jamp[90] -= cxtype( 0, 1 ) * amp[0];
  jamp[92] += cxtype( 0, 1 ) * amp[0];
  jamp[94] += cxtype( 0, 1 ) * amp[0];
  jamp[95] -= cxtype( 0, 1 ) * amp[0];
  jamp[114] += cxtype( 0, 1 ) * amp[0];
  jamp[116] -= cxtype( 0, 1 ) * amp[0];
  jamp[118] -= cxtype( 0, 1 ) * amp[0];
  jamp[119] += cxtype( 0, 1 ) * amp[0];

  // *** DIAGRAM 121 OF 1240 ***

  // Wavefunction(s) for diagram number 121
  // (none)

  // Amplitude(s) for diagram number 121
  FFV1_0( w[12], w[2], w[9], COUPs[1], &amp[0] );
#ifdef MGONGPU_SUPPORTS_MULTICHANNEL
  if( channelId == 121 ) allNumerators[0] += cxabs2( amp[0] );
  if( channelId != 0 ) allDenominators[0] += cxabs2( amp[0] );
#endif
  jamp[0] -= cxtype( 0, 1 ) * amp[0];
  jamp[1] += cxtype( 0, 1 ) * amp[0];
  jamp[24] += cxtype( 0, 1 ) * amp[0];
  jamp[25] -= cxtype( 0, 1 ) * amp[0];
  jamp[48] += cxtype( 0, 1 ) * amp[0];
  jamp[49] -= cxtype( 0, 1 ) * amp[0];
  jamp[54] -= cxtype( 0, 1 ) * amp[0];
  jamp[55] += cxtype( 0, 1 ) * amp[0];

  // *** DIAGRAM 122 OF 1240 ***

  // Wavefunction(s) for diagram number 122
  // (none)

  // Amplitude(s) for diagram number 122
  FFV1_0( w[3], w[52], w[30], COUPs[1], &amp[0] );
  jamp[0] -= cxtype( 0, 1 ) * amp[0];
  jamp[1] += cxtype( 0, 1 ) * amp[0];
  jamp[3] += cxtype( 0, 1 ) * amp[0];
  jamp[5] -= cxtype( 0, 1 ) * amp[0];
  jamp[24] += cxtype( 0, 1 ) * amp[0];
  jamp[25] -= cxtype( 0, 1 ) * amp[0];
  jamp[27] -= cxtype( 0, 1 ) * amp[0];
  jamp[29] += cxtype( 0, 1 ) * amp[0];
  FFV1_0( w[3], w[52], w[31], COUPs[1], &amp[0] );
  jamp[1] += cxtype( 0, 1 ) * amp[0];
  jamp[2] -= cxtype( 0, 1 ) * amp[0];
  jamp[3] += cxtype( 0, 1 ) * amp[0];
  jamp[4] -= cxtype( 0, 1 ) * amp[0];
  jamp[25] -= cxtype( 0, 1 ) * amp[0];
  jamp[26] += cxtype( 0, 1 ) * amp[0];
  jamp[27] -= cxtype( 0, 1 ) * amp[0];
  jamp[28] += cxtype( 0, 1 ) * amp[0];
  FFV1_0( w[3], w[52], w[32], COUPs[1], &amp[0] );
  jamp[0] += cxtype( 0, 1 ) * amp[0];
  jamp[2] -= cxtype( 0, 1 ) * amp[0];
  jamp[4] -= cxtype( 0, 1 ) * amp[0];
  jamp[5] += cxtype( 0, 1 ) * amp[0];
  jamp[24] -= cxtype( 0, 1 ) * amp[0];
  jamp[26] += cxtype( 0, 1 ) * amp[0];
  jamp[28] += cxtype( 0, 1 ) * amp[0];
  jamp[29] -= cxtype( 0, 1 ) * amp[0];

  // *** DIAGRAM 123 OF 1240 ***

  // Wavefunction(s) for diagram number 123
  // (none)

  // Amplitude(s) for diagram number 123
  FFV1_0( w[34], w[2], w[30], COUPs[1], &amp[0] );
  jamp[64] -= cxtype( 0, 1 ) * amp[0];
  jamp[65] += cxtype( 0, 1 ) * amp[0];
  jamp[70] += cxtype( 0, 1 ) * amp[0];
  jamp[71] -= cxtype( 0, 1 ) * amp[0];
  jamp[94] += cxtype( 0, 1 ) * amp[0];
  jamp[95] -= cxtype( 0, 1 ) * amp[0];
  jamp[118] -= cxtype( 0, 1 ) * amp[0];
  jamp[119] += cxtype( 0, 1 ) * amp[0];
  FFV1_0( w[34], w[2], w[31], COUPs[1], &amp[0] );
  jamp[70] += cxtype( 0, 1 ) * amp[0];
  jamp[71] -= cxtype( 0, 1 ) * amp[0];
  jamp[88] -= cxtype( 0, 1 ) * amp[0];
  jamp[89] += cxtype( 0, 1 ) * amp[0];
  jamp[94] += cxtype( 0, 1 ) * amp[0];
  jamp[95] -= cxtype( 0, 1 ) * amp[0];
  jamp[112] -= cxtype( 0, 1 ) * amp[0];
  jamp[113] += cxtype( 0, 1 ) * amp[0];
  FFV1_0( w[34], w[2], w[32], COUPs[1], &amp[0] );
  jamp[64] += cxtype( 0, 1 ) * amp[0];
  jamp[65] -= cxtype( 0, 1 ) * amp[0];
  jamp[88] -= cxtype( 0, 1 ) * amp[0];
  jamp[89] += cxtype( 0, 1 ) * amp[0];
  jamp[112] -= cxtype( 0, 1 ) * amp[0];
  jamp[113] += cxtype( 0, 1 ) * amp[0];
  jamp[118] += cxtype( 0, 1 ) * amp[0];
  jamp[119] -= cxtype( 0, 1 ) * amp[0];

  // *** DIAGRAM 124 OF 1240 ***

  // Wavefunction(s) for diagram number 124
  FFV1_1( w[2], w[0], COUPs[1], cIPD[0], cIPD[1], w[34] );
  FFV1_2( w[3], w[1], COUPs[1], cIPD[0], cIPD[1], w[52] );
  FFV1_1( w[34], w[4], COUPs[1], cIPD[0], cIPD[1], w[9] );
  FFV1_2( w[52], w[5], COUPs[1], cIPD[0], cIPD[1], w[22] );

  // Amplitude(s) for diagram number 124
  FFV1_0( w[22], w[9], w[6], COUPs[1], &amp[0] );
#ifdef MGONGPU_SUPPORTS_MULTICHANNEL
  if( channelId == 124 ) allNumerators[0] += cxabs2( amp[0] );
  if( channelId != 0 ) allDenominators[0] += cxabs2( amp[0] );
#endif
  jamp[11] -= amp[0];

  // *** DIAGRAM 125 OF 1240 ***

  // Wavefunction(s) for diagram number 125
  FFV1_2( w[52], w[6], COUPs[1], cIPD[0], cIPD[1], w[21] );

  // Amplitude(s) for diagram number 125
  FFV1_0( w[21], w[9], w[5], COUPs[1], &amp[0] );
#ifdef MGONGPU_SUPPORTS_MULTICHANNEL
  if( channelId == 125 ) allNumerators[0] += cxabs2( amp[0] );
  if( channelId != 0 ) allDenominators[0] += cxabs2( amp[0] );
#endif
  jamp[9] -= amp[0];

  // *** DIAGRAM 126 OF 1240 ***

  // Wavefunction(s) for diagram number 126
  FFV1_1( w[34], w[5], COUPs[1], cIPD[0], cIPD[1], w[55] );
  FFV1_2( w[52], w[4], COUPs[1], cIPD[0], cIPD[1], w[56] );

  // Amplitude(s) for diagram number 126
  FFV1_0( w[56], w[55], w[6], COUPs[1], &amp[0] );
#ifdef MGONGPU_SUPPORTS_MULTICHANNEL
  if( channelId == 126 ) allNumerators[0] += cxabs2( amp[0] );
  if( channelId != 0 ) allDenominators[0] += cxabs2( amp[0] );
#endif
  jamp[17] -= amp[0];

  // *** DIAGRAM 127 OF 1240 ***

  // Wavefunction(s) for diagram number 127
  // (none)

  // Amplitude(s) for diagram number 127
  FFV1_0( w[21], w[55], w[4], COUPs[1], &amp[0] );
#ifdef MGONGPU_SUPPORTS_MULTICHANNEL
  if( channelId == 127 ) allNumerators[0] += cxabs2( amp[0] );
  if( channelId != 0 ) allDenominators[0] += cxabs2( amp[0] );
#endif
  jamp[15] -= amp[0];

  // *** DIAGRAM 128 OF 1240 ***

  // Wavefunction(s) for diagram number 128
  FFV1_1( w[34], w[6], COUPs[1], cIPD[0], cIPD[1], w[57] );

  // Amplitude(s) for diagram number 128
  FFV1_0( w[56], w[57], w[5], COUPs[1], &amp[0] );
#ifdef MGONGPU_SUPPORTS_MULTICHANNEL
  if( channelId == 128 ) allNumerators[0] += cxabs2( amp[0] );
  if( channelId != 0 ) allDenominators[0] += cxabs2( amp[0] );
#endif
  jamp[23] -= amp[0];

  // *** DIAGRAM 129 OF 1240 ***

  // Wavefunction(s) for diagram number 129
  // (none)

  // Amplitude(s) for diagram number 129
  FFV1_0( w[22], w[57], w[4], COUPs[1], &amp[0] );
#ifdef MGONGPU_SUPPORTS_MULTICHANNEL
  if( channelId == 129 ) allNumerators[0] += cxabs2( amp[0] );
  if( channelId != 0 ) allDenominators[0] += cxabs2( amp[0] );
#endif
  jamp[21] -= amp[0];

  // *** DIAGRAM 130 OF 1240 ***

  // Wavefunction(s) for diagram number 130
  FFV1P0_3( w[52], w[34], COUPs[1], 0., 0., w[58] );

  // Amplitude(s) for diagram number 130
  VVV1_0( w[24], w[6], w[58], COUPs[0], &amp[0] );
#ifdef MGONGPU_SUPPORTS_MULTICHANNEL
  if( channelId == 130 ) allNumerators[0] += cxabs2( amp[0] );
  if( channelId != 0 ) allDenominators[0] += cxabs2( amp[0] );
#endif
  jamp[9] += amp[0];
  jamp[15] -= amp[0];
  jamp[21] -= amp[0];
  jamp[23] += amp[0];

  // *** DIAGRAM 131 OF 1240 ***

  // Wavefunction(s) for diagram number 131
  FFV1_1( w[34], w[24], COUPs[1], cIPD[0], cIPD[1], w[59] );

  // Amplitude(s) for diagram number 131
  FFV1_0( w[52], w[59], w[6], COUPs[1], &amp[0] );
#ifdef MGONGPU_SUPPORTS_MULTICHANNEL
  if( channelId == 131 ) allNumerators[0] += cxabs2( amp[0] );
  if( channelId != 0 ) allDenominators[0] += cxabs2( amp[0] );
#endif
  jamp[9] += cxtype( 0, 1 ) * amp[0];
  jamp[15] -= cxtype( 0, 1 ) * amp[0];

  // *** DIAGRAM 132 OF 1240 ***

  // Wavefunction(s) for diagram number 132
  // (none)

  // Amplitude(s) for diagram number 132
  FFV1_0( w[52], w[57], w[24], COUPs[1], &amp[0] );
#ifdef MGONGPU_SUPPORTS_MULTICHANNEL
  if( channelId == 132 ) allNumerators[0] += cxabs2( amp[0] );
  if( channelId != 0 ) allDenominators[0] += cxabs2( amp[0] );
#endif
  jamp[21] += cxtype( 0, 1 ) * amp[0];
  jamp[23] -= cxtype( 0, 1 ) * amp[0];

  // *** DIAGRAM 133 OF 1240 ***

  // Wavefunction(s) for diagram number 133
  // (none)

  // Amplitude(s) for diagram number 133
  VVV1_0( w[27], w[5], w[58], COUPs[0], &amp[0] );
#ifdef MGONGPU_SUPPORTS_MULTICHANNEL
  if( channelId == 133 ) allNumerators[0] += cxabs2( amp[0] );
  if( channelId != 0 ) allDenominators[0] += cxabs2( amp[0] );
#endif
  jamp[11] += amp[0];
  jamp[15] -= amp[0];
  jamp[17] += amp[0];
  jamp[21] -= amp[0];

  // *** DIAGRAM 134 OF 1240 ***

  // Wavefunction(s) for diagram number 134
  FFV1_1( w[34], w[27], COUPs[1], cIPD[0], cIPD[1], w[60] );

  // Amplitude(s) for diagram number 134
  FFV1_0( w[52], w[60], w[5], COUPs[1], &amp[0] );
#ifdef MGONGPU_SUPPORTS_MULTICHANNEL
  if( channelId == 134 ) allNumerators[0] += cxabs2( amp[0] );
  if( channelId != 0 ) allDenominators[0] += cxabs2( amp[0] );
#endif
  jamp[11] += cxtype( 0, 1 ) * amp[0];
  jamp[21] -= cxtype( 0, 1 ) * amp[0];

  // *** DIAGRAM 135 OF 1240 ***

  // Wavefunction(s) for diagram number 135
  // (none)

  // Amplitude(s) for diagram number 135
  FFV1_0( w[52], w[55], w[27], COUPs[1], &amp[0] );
#ifdef MGONGPU_SUPPORTS_MULTICHANNEL
  if( channelId == 135 ) allNumerators[0] += cxabs2( amp[0] );
  if( channelId != 0 ) allDenominators[0] += cxabs2( amp[0] );
#endif
  jamp[15] += cxtype( 0, 1 ) * amp[0];
  jamp[17] -= cxtype( 0, 1 ) * amp[0];

  // *** DIAGRAM 136 OF 1240 ***

  // Wavefunction(s) for diagram number 136
  // (none)

  // Amplitude(s) for diagram number 136
  VVV1_0( w[4], w[29], w[58], COUPs[0], &amp[0] );
#ifdef MGONGPU_SUPPORTS_MULTICHANNEL
  if( channelId == 136 ) allNumerators[0] += cxabs2( amp[0] );
  if( channelId != 0 ) allDenominators[0] += cxabs2( amp[0] );
#endif
  jamp[9] += amp[0];
  jamp[11] -= amp[0];
  jamp[17] -= amp[0];
  jamp[23] += amp[0];

  // *** DIAGRAM 137 OF 1240 ***

  // Wavefunction(s) for diagram number 137
  // (none)

  // Amplitude(s) for diagram number 137
  FFV1_0( w[52], w[9], w[29], COUPs[1], &amp[0] );
#ifdef MGONGPU_SUPPORTS_MULTICHANNEL
  if( channelId == 137 ) allNumerators[0] += cxabs2( amp[0] );
  if( channelId != 0 ) allDenominators[0] += cxabs2( amp[0] );
#endif
  jamp[9] += cxtype( 0, 1 ) * amp[0];
  jamp[11] -= cxtype( 0, 1 ) * amp[0];

  // *** DIAGRAM 138 OF 1240 ***

  // Wavefunction(s) for diagram number 138
  FFV1_1( w[34], w[29], COUPs[1], cIPD[0], cIPD[1], w[58] );

  // Amplitude(s) for diagram number 138
  FFV1_0( w[52], w[58], w[4], COUPs[1], &amp[0] );
#ifdef MGONGPU_SUPPORTS_MULTICHANNEL
  if( channelId == 138 ) allNumerators[0] += cxabs2( amp[0] );
  if( channelId != 0 ) allDenominators[0] += cxabs2( amp[0] );
#endif
  jamp[17] += cxtype( 0, 1 ) * amp[0];
  jamp[23] -= cxtype( 0, 1 ) * amp[0];

  // *** DIAGRAM 139 OF 1240 ***

  // Wavefunction(s) for diagram number 139
  // (none)

  // Amplitude(s) for diagram number 139
  FFV1_0( w[52], w[34], w[30], COUPs[1], &amp[0] );
  jamp[9] += amp[0];
  jamp[11] -= amp[0];
  jamp[17] -= amp[0];
  jamp[23] += amp[0];
  FFV1_0( w[52], w[34], w[31], COUPs[1], &amp[0] );
  jamp[11] -= amp[0];
  jamp[15] += amp[0];
  jamp[17] -= amp[0];
  jamp[21] += amp[0];
  FFV1_0( w[52], w[34], w[32], COUPs[1], &amp[0] );
  jamp[9] -= amp[0];
  jamp[15] += amp[0];
  jamp[21] += amp[0];
  jamp[23] -= amp[0];

  // *** DIAGRAM 140 OF 1240 ***

  // Wavefunction(s) for diagram number 140
  VVV1P0_1( w[1], w[4], COUPs[0], 0., 0., w[61] );
  FFV1P0_3( w[3], w[34], COUPs[1], 0., 0., w[62] );
  VVV1P0_1( w[61], w[5], COUPs[0], 0., 0., w[63] );

  // Amplitude(s) for diagram number 140
  VVV1_0( w[62], w[63], w[6], COUPs[0], &amp[0] );
#ifdef MGONGPU_SUPPORTS_MULTICHANNEL
  if( channelId == 140 ) allNumerators[0] += cxabs2( amp[0] );
  if( channelId != 0 ) allDenominators[0] += cxabs2( amp[0] );
#endif
  jamp[0] -= cxtype( 0, 1 ) * amp[0];
  jamp[6] += cxtype( 0, 1 ) * amp[0];
  jamp[12] += cxtype( 0, 1 ) * amp[0];
  jamp[14] -= cxtype( 0, 1 ) * amp[0];
  jamp[18] += cxtype( 0, 1 ) * amp[0];
  jamp[20] -= cxtype( 0, 1 ) * amp[0];
  jamp[22] -= cxtype( 0, 1 ) * amp[0];
  jamp[23] += cxtype( 0, 1 ) * amp[0];

  // *** DIAGRAM 141 OF 1240 ***

  // Wavefunction(s) for diagram number 141
  VVV1P0_1( w[61], w[6], COUPs[0], 0., 0., w[64] );

  // Amplitude(s) for diagram number 141
  VVV1_0( w[62], w[64], w[5], COUPs[0], &amp[0] );
#ifdef MGONGPU_SUPPORTS_MULTICHANNEL
  if( channelId == 141 ) allNumerators[0] += cxabs2( amp[0] );
  if( channelId != 0 ) allDenominators[0] += cxabs2( amp[0] );
#endif
  jamp[1] -= cxtype( 0, 1 ) * amp[0];
  jamp[7] += cxtype( 0, 1 ) * amp[0];
  jamp[12] += cxtype( 0, 1 ) * amp[0];
  jamp[14] -= cxtype( 0, 1 ) * amp[0];
  jamp[16] -= cxtype( 0, 1 ) * amp[0];
  jamp[17] += cxtype( 0, 1 ) * amp[0];
  jamp[18] += cxtype( 0, 1 ) * amp[0];
  jamp[20] -= cxtype( 0, 1 ) * amp[0];

  // *** DIAGRAM 142 OF 1240 ***

  // Wavefunction(s) for diagram number 142
  // (none)

  // Amplitude(s) for diagram number 142
  VVVV1_0( w[61], w[5], w[6], w[62], COUPs[2], &amp[0] );
  jamp[0] -= cxtype( 0, 1 ) * amp[0];
  jamp[6] += cxtype( 0, 1 ) * amp[0];
  jamp[12] += cxtype( 0, 1 ) * amp[0];
  jamp[14] -= cxtype( 0, 1 ) * amp[0];
  jamp[18] += cxtype( 0, 1 ) * amp[0];
  jamp[20] -= cxtype( 0, 1 ) * amp[0];
  jamp[22] -= cxtype( 0, 1 ) * amp[0];
  jamp[23] += cxtype( 0, 1 ) * amp[0];
  VVVV3_0( w[61], w[5], w[6], w[62], COUPs[2], &amp[0] );
  jamp[1] -= cxtype( 0, 1 ) * amp[0];
  jamp[7] += cxtype( 0, 1 ) * amp[0];
  jamp[12] += cxtype( 0, 1 ) * amp[0];
  jamp[14] -= cxtype( 0, 1 ) * amp[0];
  jamp[16] -= cxtype( 0, 1 ) * amp[0];
  jamp[17] += cxtype( 0, 1 ) * amp[0];
  jamp[18] += cxtype( 0, 1 ) * amp[0];
  jamp[20] -= cxtype( 0, 1 ) * amp[0];
  VVVV4_0( w[61], w[5], w[6], w[62], COUPs[2], &amp[0] );
  jamp[0] += cxtype( 0, 1 ) * amp[0];
  jamp[1] -= cxtype( 0, 1 ) * amp[0];
  jamp[6] -= cxtype( 0, 1 ) * amp[0];
  jamp[7] += cxtype( 0, 1 ) * amp[0];
  jamp[16] -= cxtype( 0, 1 ) * amp[0];
  jamp[17] += cxtype( 0, 1 ) * amp[0];
  jamp[22] += cxtype( 0, 1 ) * amp[0];
  jamp[23] -= cxtype( 0, 1 ) * amp[0];

  // *** DIAGRAM 143 OF 1240 ***

  // Wavefunction(s) for diagram number 143
  FFV1_2( w[3], w[61], COUPs[1], cIPD[0], cIPD[1], w[65] );

  // Amplitude(s) for diagram number 143
  FFV1_0( w[65], w[55], w[6], COUPs[1], &amp[0] );
#ifdef MGONGPU_SUPPORTS_MULTICHANNEL
  if( channelId == 143 ) allNumerators[0] += cxabs2( amp[0] );
  if( channelId != 0 ) allDenominators[0] += cxabs2( amp[0] );
#endif
  jamp[16] += cxtype( 0, 1 ) * amp[0];
  jamp[17] -= cxtype( 0, 1 ) * amp[0];

  // *** DIAGRAM 144 OF 1240 ***

  // Wavefunction(s) for diagram number 144
  // (none)

  // Amplitude(s) for diagram number 144
  FFV1_0( w[3], w[55], w[64], COUPs[1], &amp[0] );
#ifdef MGONGPU_SUPPORTS_MULTICHANNEL
  if( channelId == 144 ) allNumerators[0] += cxabs2( amp[0] );
  if( channelId != 0 ) allDenominators[0] += cxabs2( amp[0] );
#endif
  jamp[12] += amp[0];
  jamp[14] -= amp[0];
  jamp[16] -= amp[0];
  jamp[17] += amp[0];

  // *** DIAGRAM 145 OF 1240 ***

  // Wavefunction(s) for diagram number 145
  // (none)

  // Amplitude(s) for diagram number 145
  FFV1_0( w[65], w[57], w[5], COUPs[1], &amp[0] );
#ifdef MGONGPU_SUPPORTS_MULTICHANNEL
  if( channelId == 145 ) allNumerators[0] += cxabs2( amp[0] );
  if( channelId != 0 ) allDenominators[0] += cxabs2( amp[0] );
#endif
  jamp[22] += cxtype( 0, 1 ) * amp[0];
  jamp[23] -= cxtype( 0, 1 ) * amp[0];

  // *** DIAGRAM 146 OF 1240 ***

  // Wavefunction(s) for diagram number 146
  // (none)

  // Amplitude(s) for diagram number 146
  FFV1_0( w[3], w[57], w[63], COUPs[1], &amp[0] );
#ifdef MGONGPU_SUPPORTS_MULTICHANNEL
  if( channelId == 146 ) allNumerators[0] += cxabs2( amp[0] );
  if( channelId != 0 ) allDenominators[0] += cxabs2( amp[0] );
#endif
  jamp[18] += amp[0];
  jamp[20] -= amp[0];
  jamp[22] -= amp[0];
  jamp[23] += amp[0];

  // *** DIAGRAM 147 OF 1240 ***

  // Wavefunction(s) for diagram number 147
  FFV1_1( w[34], w[61], COUPs[1], cIPD[0], cIPD[1], w[66] );

  // Amplitude(s) for diagram number 147
  FFV1_0( w[38], w[66], w[6], COUPs[1], &amp[0] );
#ifdef MGONGPU_SUPPORTS_MULTICHANNEL
  if( channelId == 147 ) allNumerators[0] += cxabs2( amp[0] );
  if( channelId != 0 ) allDenominators[0] += cxabs2( amp[0] );
#endif
  jamp[1] += cxtype( 0, 1 ) * amp[0];
  jamp[7] -= cxtype( 0, 1 ) * amp[0];

  // *** DIAGRAM 148 OF 1240 ***

  // Wavefunction(s) for diagram number 148
  FFV1P0_3( w[38], w[34], COUPs[1], 0., 0., w[67] );

  // Amplitude(s) for diagram number 148
  VVV1_0( w[61], w[6], w[67], COUPs[0], &amp[0] );
#ifdef MGONGPU_SUPPORTS_MULTICHANNEL
  if( channelId == 148 ) allNumerators[0] += cxabs2( amp[0] );
  if( channelId != 0 ) allDenominators[0] += cxabs2( amp[0] );
#endif
  jamp[1] += amp[0];
  jamp[7] -= amp[0];
  jamp[18] -= amp[0];
  jamp[20] += amp[0];

  // *** DIAGRAM 149 OF 1240 ***

  // Wavefunction(s) for diagram number 149
  // (none)

  // Amplitude(s) for diagram number 149
  FFV1_0( w[38], w[57], w[61], COUPs[1], &amp[0] );
#ifdef MGONGPU_SUPPORTS_MULTICHANNEL
  if( channelId == 149 ) allNumerators[0] += cxabs2( amp[0] );
  if( channelId != 0 ) allDenominators[0] += cxabs2( amp[0] );
#endif
  jamp[18] += cxtype( 0, 1 ) * amp[0];
  jamp[20] -= cxtype( 0, 1 ) * amp[0];

  // *** DIAGRAM 150 OF 1240 ***

  // Wavefunction(s) for diagram number 150
  // (none)

  // Amplitude(s) for diagram number 150
  FFV1_0( w[41], w[66], w[5], COUPs[1], &amp[0] );
#ifdef MGONGPU_SUPPORTS_MULTICHANNEL
  if( channelId == 150 ) allNumerators[0] += cxabs2( amp[0] );
  if( channelId != 0 ) allDenominators[0] += cxabs2( amp[0] );
#endif
  jamp[0] += cxtype( 0, 1 ) * amp[0];
  jamp[6] -= cxtype( 0, 1 ) * amp[0];

  // *** DIAGRAM 151 OF 1240 ***

  // Wavefunction(s) for diagram number 151
  FFV1P0_3( w[41], w[34], COUPs[1], 0., 0., w[68] );

  // Amplitude(s) for diagram number 151
  VVV1_0( w[61], w[5], w[68], COUPs[0], &amp[0] );
#ifdef MGONGPU_SUPPORTS_MULTICHANNEL
  if( channelId == 151 ) allNumerators[0] += cxabs2( amp[0] );
  if( channelId != 0 ) allDenominators[0] += cxabs2( amp[0] );
#endif
  jamp[0] += amp[0];
  jamp[6] -= amp[0];
  jamp[12] -= amp[0];
  jamp[14] += amp[0];

  // *** DIAGRAM 152 OF 1240 ***

  // Wavefunction(s) for diagram number 152
  // (none)

  // Amplitude(s) for diagram number 152
  FFV1_0( w[41], w[55], w[61], COUPs[1], &amp[0] );
#ifdef MGONGPU_SUPPORTS_MULTICHANNEL
  if( channelId == 152 ) allNumerators[0] += cxabs2( amp[0] );
  if( channelId != 0 ) allDenominators[0] += cxabs2( amp[0] );
#endif
  jamp[12] += cxtype( 0, 1 ) * amp[0];
  jamp[14] -= cxtype( 0, 1 ) * amp[0];

  // *** DIAGRAM 153 OF 1240 ***

  // Wavefunction(s) for diagram number 153
  // (none)

  // Amplitude(s) for diagram number 153
  FFV1_0( w[3], w[66], w[29], COUPs[1], &amp[0] );
#ifdef MGONGPU_SUPPORTS_MULTICHANNEL
  if( channelId == 153 ) allNumerators[0] += cxabs2( amp[0] );
  if( channelId != 0 ) allDenominators[0] += cxabs2( amp[0] );
#endif
  jamp[0] += amp[0];
  jamp[1] -= amp[0];
  jamp[6] -= amp[0];
  jamp[7] += amp[0];

  // *** DIAGRAM 154 OF 1240 ***

  // Wavefunction(s) for diagram number 154
  // (none)

  // Amplitude(s) for diagram number 154
  VVV1_0( w[61], w[29], w[62], COUPs[0], &amp[0] );
#ifdef MGONGPU_SUPPORTS_MULTICHANNEL
  if( channelId == 154 ) allNumerators[0] += cxabs2( amp[0] );
  if( channelId != 0 ) allDenominators[0] += cxabs2( amp[0] );
#endif
  jamp[0] -= cxtype( 0, 1 ) * amp[0];
  jamp[1] += cxtype( 0, 1 ) * amp[0];
  jamp[6] += cxtype( 0, 1 ) * amp[0];
  jamp[7] -= cxtype( 0, 1 ) * amp[0];
  jamp[16] += cxtype( 0, 1 ) * amp[0];
  jamp[17] -= cxtype( 0, 1 ) * amp[0];
  jamp[22] -= cxtype( 0, 1 ) * amp[0];
  jamp[23] += cxtype( 0, 1 ) * amp[0];

  // *** DIAGRAM 155 OF 1240 ***

  // Wavefunction(s) for diagram number 155
  // (none)

  // Amplitude(s) for diagram number 155
  FFV1_0( w[3], w[58], w[61], COUPs[1], &amp[0] );
#ifdef MGONGPU_SUPPORTS_MULTICHANNEL
  if( channelId == 155 ) allNumerators[0] += cxabs2( amp[0] );
  if( channelId != 0 ) allDenominators[0] += cxabs2( amp[0] );
#endif
  jamp[16] += amp[0];
  jamp[17] -= amp[0];
  jamp[22] -= amp[0];
  jamp[23] += amp[0];

  // *** DIAGRAM 156 OF 1240 ***

  // Wavefunction(s) for diagram number 156
  VVV1P0_1( w[1], w[5], COUPs[0], 0., 0., w[66] );
  VVV1P0_1( w[66], w[4], COUPs[0], 0., 0., w[69] );

  // Amplitude(s) for diagram number 156
  VVV1_0( w[62], w[69], w[6], COUPs[0], &amp[0] );
#ifdef MGONGPU_SUPPORTS_MULTICHANNEL
  if( channelId == 156 ) allNumerators[0] += cxabs2( amp[0] );
  if( channelId != 0 ) allDenominators[0] += cxabs2( amp[0] );
#endif
  jamp[2] -= cxtype( 0, 1 ) * amp[0];
  jamp[6] += cxtype( 0, 1 ) * amp[0];
  jamp[8] -= cxtype( 0, 1 ) * amp[0];
  jamp[12] += cxtype( 0, 1 ) * amp[0];
  jamp[19] += cxtype( 0, 1 ) * amp[0];
  jamp[20] -= cxtype( 0, 1 ) * amp[0];
  jamp[21] += cxtype( 0, 1 ) * amp[0];
  jamp[22] -= cxtype( 0, 1 ) * amp[0];

  // *** DIAGRAM 157 OF 1240 ***

  // Wavefunction(s) for diagram number 157
  VVV1P0_1( w[66], w[6], COUPs[0], 0., 0., w[70] );

  // Amplitude(s) for diagram number 157
  VVV1_0( w[62], w[70], w[4], COUPs[0], &amp[0] );
#ifdef MGONGPU_SUPPORTS_MULTICHANNEL
  if( channelId == 157 ) allNumerators[0] += cxabs2( amp[0] );
  if( channelId != 0 ) allDenominators[0] += cxabs2( amp[0] );
#endif
  jamp[3] -= cxtype( 0, 1 ) * amp[0];
  jamp[6] += cxtype( 0, 1 ) * amp[0];
  jamp[8] -= cxtype( 0, 1 ) * amp[0];
  jamp[10] -= cxtype( 0, 1 ) * amp[0];
  jamp[11] += cxtype( 0, 1 ) * amp[0];
  jamp[13] += cxtype( 0, 1 ) * amp[0];
  jamp[19] += cxtype( 0, 1 ) * amp[0];
  jamp[22] -= cxtype( 0, 1 ) * amp[0];

  // *** DIAGRAM 158 OF 1240 ***

  // Wavefunction(s) for diagram number 158
  // (none)

  // Amplitude(s) for diagram number 158
  VVVV1_0( w[66], w[4], w[6], w[62], COUPs[2], &amp[0] );
  jamp[2] -= cxtype( 0, 1 ) * amp[0];
  jamp[6] += cxtype( 0, 1 ) * amp[0];
  jamp[8] -= cxtype( 0, 1 ) * amp[0];
  jamp[12] += cxtype( 0, 1 ) * amp[0];
  jamp[19] += cxtype( 0, 1 ) * amp[0];
  jamp[20] -= cxtype( 0, 1 ) * amp[0];
  jamp[21] += cxtype( 0, 1 ) * amp[0];
  jamp[22] -= cxtype( 0, 1 ) * amp[0];
  VVVV3_0( w[66], w[4], w[6], w[62], COUPs[2], &amp[0] );
  jamp[3] -= cxtype( 0, 1 ) * amp[0];
  jamp[6] += cxtype( 0, 1 ) * amp[0];
  jamp[8] -= cxtype( 0, 1 ) * amp[0];
  jamp[10] -= cxtype( 0, 1 ) * amp[0];
  jamp[11] += cxtype( 0, 1 ) * amp[0];
  jamp[13] += cxtype( 0, 1 ) * amp[0];
  jamp[19] += cxtype( 0, 1 ) * amp[0];
  jamp[22] -= cxtype( 0, 1 ) * amp[0];
  VVVV4_0( w[66], w[4], w[6], w[62], COUPs[2], &amp[0] );
  jamp[2] += cxtype( 0, 1 ) * amp[0];
  jamp[3] -= cxtype( 0, 1 ) * amp[0];
  jamp[10] -= cxtype( 0, 1 ) * amp[0];
  jamp[11] += cxtype( 0, 1 ) * amp[0];
  jamp[12] -= cxtype( 0, 1 ) * amp[0];
  jamp[13] += cxtype( 0, 1 ) * amp[0];
  jamp[20] += cxtype( 0, 1 ) * amp[0];
  jamp[21] -= cxtype( 0, 1 ) * amp[0];

  // *** DIAGRAM 159 OF 1240 ***

  // Wavefunction(s) for diagram number 159
  FFV1_2( w[3], w[66], COUPs[1], cIPD[0], cIPD[1], w[71] );

  // Amplitude(s) for diagram number 159
  FFV1_0( w[71], w[9], w[6], COUPs[1], &amp[0] );
#ifdef MGONGPU_SUPPORTS_MULTICHANNEL
  if( channelId == 159 ) allNumerators[0] += cxabs2( amp[0] );
  if( channelId != 0 ) allDenominators[0] += cxabs2( amp[0] );
#endif
  jamp[10] += cxtype( 0, 1 ) * amp[0];
  jamp[11] -= cxtype( 0, 1 ) * amp[0];

  // *** DIAGRAM 160 OF 1240 ***

  // Wavefunction(s) for diagram number 160
  // (none)

  // Amplitude(s) for diagram number 160
  FFV1_0( w[3], w[9], w[70], COUPs[1], &amp[0] );
#ifdef MGONGPU_SUPPORTS_MULTICHANNEL
  if( channelId == 160 ) allNumerators[0] += cxabs2( amp[0] );
  if( channelId != 0 ) allDenominators[0] += cxabs2( amp[0] );
#endif
  jamp[6] += amp[0];
  jamp[8] -= amp[0];
  jamp[10] -= amp[0];
  jamp[11] += amp[0];

  // *** DIAGRAM 161 OF 1240 ***

  // Wavefunction(s) for diagram number 161
  // (none)

  // Amplitude(s) for diagram number 161
  FFV1_0( w[71], w[57], w[4], COUPs[1], &amp[0] );
#ifdef MGONGPU_SUPPORTS_MULTICHANNEL
  if( channelId == 161 ) allNumerators[0] += cxabs2( amp[0] );
  if( channelId != 0 ) allDenominators[0] += cxabs2( amp[0] );
#endif
  jamp[20] += cxtype( 0, 1 ) * amp[0];
  jamp[21] -= cxtype( 0, 1 ) * amp[0];

  // *** DIAGRAM 162 OF 1240 ***

  // Wavefunction(s) for diagram number 162
  // (none)

  // Amplitude(s) for diagram number 162
  FFV1_0( w[3], w[57], w[69], COUPs[1], &amp[0] );
#ifdef MGONGPU_SUPPORTS_MULTICHANNEL
  if( channelId == 162 ) allNumerators[0] += cxabs2( amp[0] );
  if( channelId != 0 ) allDenominators[0] += cxabs2( amp[0] );
#endif
  jamp[19] += amp[0];
  jamp[20] -= amp[0];
  jamp[21] += amp[0];
  jamp[22] -= amp[0];

  // *** DIAGRAM 163 OF 1240 ***

  // Wavefunction(s) for diagram number 163
  FFV1_1( w[34], w[66], COUPs[1], cIPD[0], cIPD[1], w[72] );

  // Amplitude(s) for diagram number 163
  FFV1_0( w[46], w[72], w[6], COUPs[1], &amp[0] );
#ifdef MGONGPU_SUPPORTS_MULTICHANNEL
  if( channelId == 163 ) allNumerators[0] += cxabs2( amp[0] );
  if( channelId != 0 ) allDenominators[0] += cxabs2( amp[0] );
#endif
  jamp[3] += cxtype( 0, 1 ) * amp[0];
  jamp[13] -= cxtype( 0, 1 ) * amp[0];

  // *** DIAGRAM 164 OF 1240 ***

  // Wavefunction(s) for diagram number 164
  FFV1P0_3( w[46], w[34], COUPs[1], 0., 0., w[73] );

  // Amplitude(s) for diagram number 164
  VVV1_0( w[66], w[6], w[73], COUPs[0], &amp[0] );
#ifdef MGONGPU_SUPPORTS_MULTICHANNEL
  if( channelId == 164 ) allNumerators[0] += cxabs2( amp[0] );
  if( channelId != 0 ) allDenominators[0] += cxabs2( amp[0] );
#endif
  jamp[3] += amp[0];
  jamp[13] -= amp[0];
  jamp[19] -= amp[0];
  jamp[22] += amp[0];

  // *** DIAGRAM 165 OF 1240 ***

  // Wavefunction(s) for diagram number 165
  // (none)

  // Amplitude(s) for diagram number 165
  FFV1_0( w[46], w[57], w[66], COUPs[1], &amp[0] );
#ifdef MGONGPU_SUPPORTS_MULTICHANNEL
  if( channelId == 165 ) allNumerators[0] += cxabs2( amp[0] );
  if( channelId != 0 ) allDenominators[0] += cxabs2( amp[0] );
#endif
  jamp[19] += cxtype( 0, 1 ) * amp[0];
  jamp[22] -= cxtype( 0, 1 ) * amp[0];

  // *** DIAGRAM 166 OF 1240 ***

  // Wavefunction(s) for diagram number 166
  // (none)

  // Amplitude(s) for diagram number 166
  FFV1_0( w[41], w[72], w[4], COUPs[1], &amp[0] );
#ifdef MGONGPU_SUPPORTS_MULTICHANNEL
  if( channelId == 166 ) allNumerators[0] += cxabs2( amp[0] );
  if( channelId != 0 ) allDenominators[0] += cxabs2( amp[0] );
#endif
  jamp[2] += cxtype( 0, 1 ) * amp[0];
  jamp[12] -= cxtype( 0, 1 ) * amp[0];

  // *** DIAGRAM 167 OF 1240 ***

  // Wavefunction(s) for diagram number 167
  // (none)

  // Amplitude(s) for diagram number 167
  VVV1_0( w[66], w[4], w[68], COUPs[0], &amp[0] );
#ifdef MGONGPU_SUPPORTS_MULTICHANNEL
  if( channelId == 167 ) allNumerators[0] += cxabs2( amp[0] );
  if( channelId != 0 ) allDenominators[0] += cxabs2( amp[0] );
#endif
  jamp[2] += amp[0];
  jamp[6] -= amp[0];
  jamp[8] += amp[0];
  jamp[12] -= amp[0];

  // *** DIAGRAM 168 OF 1240 ***

  // Wavefunction(s) for diagram number 168
  // (none)

  // Amplitude(s) for diagram number 168
  FFV1_0( w[41], w[9], w[66], COUPs[1], &amp[0] );
#ifdef MGONGPU_SUPPORTS_MULTICHANNEL
  if( channelId == 168 ) allNumerators[0] += cxabs2( amp[0] );
  if( channelId != 0 ) allDenominators[0] += cxabs2( amp[0] );
#endif
  jamp[6] += cxtype( 0, 1 ) * amp[0];
  jamp[8] -= cxtype( 0, 1 ) * amp[0];

  // *** DIAGRAM 169 OF 1240 ***

  // Wavefunction(s) for diagram number 169
  // (none)

  // Amplitude(s) for diagram number 169
  FFV1_0( w[3], w[72], w[27], COUPs[1], &amp[0] );
#ifdef MGONGPU_SUPPORTS_MULTICHANNEL
  if( channelId == 169 ) allNumerators[0] += cxabs2( amp[0] );
  if( channelId != 0 ) allDenominators[0] += cxabs2( amp[0] );
#endif
  jamp[2] += amp[0];
  jamp[3] -= amp[0];
  jamp[12] -= amp[0];
  jamp[13] += amp[0];

  // *** DIAGRAM 170 OF 1240 ***

  // Wavefunction(s) for diagram number 170
  // (none)

  // Amplitude(s) for diagram number 170
  VVV1_0( w[66], w[27], w[62], COUPs[0], &amp[0] );
#ifdef MGONGPU_SUPPORTS_MULTICHANNEL
  if( channelId == 170 ) allNumerators[0] += cxabs2( amp[0] );
  if( channelId != 0 ) allDenominators[0] += cxabs2( amp[0] );
#endif
  jamp[2] -= cxtype( 0, 1 ) * amp[0];
  jamp[3] += cxtype( 0, 1 ) * amp[0];
  jamp[10] += cxtype( 0, 1 ) * amp[0];
  jamp[11] -= cxtype( 0, 1 ) * amp[0];
  jamp[12] += cxtype( 0, 1 ) * amp[0];
  jamp[13] -= cxtype( 0, 1 ) * amp[0];
  jamp[20] -= cxtype( 0, 1 ) * amp[0];
  jamp[21] += cxtype( 0, 1 ) * amp[0];

  // *** DIAGRAM 171 OF 1240 ***

  // Wavefunction(s) for diagram number 171
  // (none)

  // Amplitude(s) for diagram number 171
  FFV1_0( w[3], w[60], w[66], COUPs[1], &amp[0] );
#ifdef MGONGPU_SUPPORTS_MULTICHANNEL
  if( channelId == 171 ) allNumerators[0] += cxabs2( amp[0] );
  if( channelId != 0 ) allDenominators[0] += cxabs2( amp[0] );
#endif
  jamp[10] += amp[0];
  jamp[11] -= amp[0];
  jamp[20] -= amp[0];
  jamp[21] += amp[0];

  // *** DIAGRAM 172 OF 1240 ***

  // Wavefunction(s) for diagram number 172
  VVV1P0_1( w[1], w[6], COUPs[0], 0., 0., w[72] );
  VVV1P0_1( w[72], w[4], COUPs[0], 0., 0., w[74] );

  // Amplitude(s) for diagram number 172
  VVV1_0( w[62], w[74], w[5], COUPs[0], &amp[0] );
#ifdef MGONGPU_SUPPORTS_MULTICHANNEL
  if( channelId == 172 ) allNumerators[0] += cxabs2( amp[0] );
  if( channelId != 0 ) allDenominators[0] += cxabs2( amp[0] );
#endif
  jamp[4] -= cxtype( 0, 1 ) * amp[0];
  jamp[7] += cxtype( 0, 1 ) * amp[0];
  jamp[10] -= cxtype( 0, 1 ) * amp[0];
  jamp[13] += cxtype( 0, 1 ) * amp[0];
  jamp[14] -= cxtype( 0, 1 ) * amp[0];
  jamp[15] += cxtype( 0, 1 ) * amp[0];
  jamp[16] -= cxtype( 0, 1 ) * amp[0];
  jamp[18] += cxtype( 0, 1 ) * amp[0];

  // *** DIAGRAM 173 OF 1240 ***

  // Wavefunction(s) for diagram number 173
  VVV1P0_1( w[72], w[5], COUPs[0], 0., 0., w[75] );

  // Amplitude(s) for diagram number 173
  VVV1_0( w[62], w[75], w[4], COUPs[0], &amp[0] );
#ifdef MGONGPU_SUPPORTS_MULTICHANNEL
  if( channelId == 173 ) allNumerators[0] += cxabs2( amp[0] );
  if( channelId != 0 ) allDenominators[0] += cxabs2( amp[0] );
#endif
  jamp[5] -= cxtype( 0, 1 ) * amp[0];
  jamp[7] += cxtype( 0, 1 ) * amp[0];
  jamp[8] -= cxtype( 0, 1 ) * amp[0];
  jamp[9] += cxtype( 0, 1 ) * amp[0];
  jamp[10] -= cxtype( 0, 1 ) * amp[0];
  jamp[13] += cxtype( 0, 1 ) * amp[0];
  jamp[16] -= cxtype( 0, 1 ) * amp[0];
  jamp[19] += cxtype( 0, 1 ) * amp[0];

  // *** DIAGRAM 174 OF 1240 ***

  // Wavefunction(s) for diagram number 174
  // (none)

  // Amplitude(s) for diagram number 174
  VVVV1_0( w[72], w[4], w[5], w[62], COUPs[2], &amp[0] );
  jamp[4] -= cxtype( 0, 1 ) * amp[0];
  jamp[7] += cxtype( 0, 1 ) * amp[0];
  jamp[10] -= cxtype( 0, 1 ) * amp[0];
  jamp[13] += cxtype( 0, 1 ) * amp[0];
  jamp[14] -= cxtype( 0, 1 ) * amp[0];
  jamp[15] += cxtype( 0, 1 ) * amp[0];
  jamp[16] -= cxtype( 0, 1 ) * amp[0];
  jamp[18] += cxtype( 0, 1 ) * amp[0];
  VVVV3_0( w[72], w[4], w[5], w[62], COUPs[2], &amp[0] );
  jamp[5] -= cxtype( 0, 1 ) * amp[0];
  jamp[7] += cxtype( 0, 1 ) * amp[0];
  jamp[8] -= cxtype( 0, 1 ) * amp[0];
  jamp[9] += cxtype( 0, 1 ) * amp[0];
  jamp[10] -= cxtype( 0, 1 ) * amp[0];
  jamp[13] += cxtype( 0, 1 ) * amp[0];
  jamp[16] -= cxtype( 0, 1 ) * amp[0];
  jamp[19] += cxtype( 0, 1 ) * amp[0];
  VVVV4_0( w[72], w[4], w[5], w[62], COUPs[2], &amp[0] );
  jamp[4] += cxtype( 0, 1 ) * amp[0];
  jamp[5] -= cxtype( 0, 1 ) * amp[0];
  jamp[8] -= cxtype( 0, 1 ) * amp[0];
  jamp[9] += cxtype( 0, 1 ) * amp[0];
  jamp[14] += cxtype( 0, 1 ) * amp[0];
  jamp[15] -= cxtype( 0, 1 ) * amp[0];
  jamp[18] -= cxtype( 0, 1 ) * amp[0];
  jamp[19] += cxtype( 0, 1 ) * amp[0];

  // *** DIAGRAM 175 OF 1240 ***

  // Wavefunction(s) for diagram number 175
  FFV1_2( w[3], w[72], COUPs[1], cIPD[0], cIPD[1], w[76] );

  // Amplitude(s) for diagram number 175
  FFV1_0( w[76], w[9], w[5], COUPs[1], &amp[0] );
#ifdef MGONGPU_SUPPORTS_MULTICHANNEL
  if( channelId == 175 ) allNumerators[0] += cxabs2( amp[0] );
  if( channelId != 0 ) allDenominators[0] += cxabs2( amp[0] );
#endif
  jamp[8] += cxtype( 0, 1 ) * amp[0];
  jamp[9] -= cxtype( 0, 1 ) * amp[0];

  // *** DIAGRAM 176 OF 1240 ***

  // Wavefunction(s) for diagram number 176
  // (none)

  // Amplitude(s) for diagram number 176
  FFV1_0( w[3], w[9], w[75], COUPs[1], &amp[0] );
#ifdef MGONGPU_SUPPORTS_MULTICHANNEL
  if( channelId == 176 ) allNumerators[0] += cxabs2( amp[0] );
  if( channelId != 0 ) allDenominators[0] += cxabs2( amp[0] );
#endif
  jamp[7] += amp[0];
  jamp[8] -= amp[0];
  jamp[9] += amp[0];
  jamp[10] -= amp[0];

  // *** DIAGRAM 177 OF 1240 ***

  // Wavefunction(s) for diagram number 177
  // (none)

  // Amplitude(s) for diagram number 177
  FFV1_0( w[76], w[55], w[4], COUPs[1], &amp[0] );
#ifdef MGONGPU_SUPPORTS_MULTICHANNEL
  if( channelId == 177 ) allNumerators[0] += cxabs2( amp[0] );
  if( channelId != 0 ) allDenominators[0] += cxabs2( amp[0] );
#endif
  jamp[14] += cxtype( 0, 1 ) * amp[0];
  jamp[15] -= cxtype( 0, 1 ) * amp[0];

  // *** DIAGRAM 178 OF 1240 ***

  // Wavefunction(s) for diagram number 178
  // (none)

  // Amplitude(s) for diagram number 178
  FFV1_0( w[3], w[55], w[74], COUPs[1], &amp[0] );
#ifdef MGONGPU_SUPPORTS_MULTICHANNEL
  if( channelId == 178 ) allNumerators[0] += cxabs2( amp[0] );
  if( channelId != 0 ) allDenominators[0] += cxabs2( amp[0] );
#endif
  jamp[13] += amp[0];
  jamp[14] -= amp[0];
  jamp[15] += amp[0];
  jamp[16] -= amp[0];

  // *** DIAGRAM 179 OF 1240 ***

  // Wavefunction(s) for diagram number 179
  FFV1_1( w[34], w[72], COUPs[1], cIPD[0], cIPD[1], w[77] );

  // Amplitude(s) for diagram number 179
  FFV1_0( w[46], w[77], w[5], COUPs[1], &amp[0] );
#ifdef MGONGPU_SUPPORTS_MULTICHANNEL
  if( channelId == 179 ) allNumerators[0] += cxabs2( amp[0] );
  if( channelId != 0 ) allDenominators[0] += cxabs2( amp[0] );
#endif
  jamp[5] += cxtype( 0, 1 ) * amp[0];
  jamp[19] -= cxtype( 0, 1 ) * amp[0];

  // *** DIAGRAM 180 OF 1240 ***

  // Wavefunction(s) for diagram number 180
  // (none)

  // Amplitude(s) for diagram number 180
  VVV1_0( w[72], w[5], w[73], COUPs[0], &amp[0] );
#ifdef MGONGPU_SUPPORTS_MULTICHANNEL
  if( channelId == 180 ) allNumerators[0] += cxabs2( amp[0] );
  if( channelId != 0 ) allDenominators[0] += cxabs2( amp[0] );
#endif
  jamp[5] += amp[0];
  jamp[13] -= amp[0];
  jamp[16] += amp[0];
  jamp[19] -= amp[0];

  // *** DIAGRAM 181 OF 1240 ***

  // Wavefunction(s) for diagram number 181
  // (none)

  // Amplitude(s) for diagram number 181
  FFV1_0( w[46], w[55], w[72], COUPs[1], &amp[0] );
#ifdef MGONGPU_SUPPORTS_MULTICHANNEL
  if( channelId == 181 ) allNumerators[0] += cxabs2( amp[0] );
  if( channelId != 0 ) allDenominators[0] += cxabs2( amp[0] );
#endif
  jamp[13] += cxtype( 0, 1 ) * amp[0];
  jamp[16] -= cxtype( 0, 1 ) * amp[0];

  // *** DIAGRAM 182 OF 1240 ***

  // Wavefunction(s) for diagram number 182
  // (none)

  // Amplitude(s) for diagram number 182
  FFV1_0( w[38], w[77], w[4], COUPs[1], &amp[0] );
#ifdef MGONGPU_SUPPORTS_MULTICHANNEL
  if( channelId == 182 ) allNumerators[0] += cxabs2( amp[0] );
  if( channelId != 0 ) allDenominators[0] += cxabs2( amp[0] );
#endif
  jamp[4] += cxtype( 0, 1 ) * amp[0];
  jamp[18] -= cxtype( 0, 1 ) * amp[0];

  // *** DIAGRAM 183 OF 1240 ***

  // Wavefunction(s) for diagram number 183
  // (none)

  // Amplitude(s) for diagram number 183
  VVV1_0( w[72], w[4], w[67], COUPs[0], &amp[0] );
#ifdef MGONGPU_SUPPORTS_MULTICHANNEL
  if( channelId == 183 ) allNumerators[0] += cxabs2( amp[0] );
  if( channelId != 0 ) allDenominators[0] += cxabs2( amp[0] );
#endif
  jamp[4] += amp[0];
  jamp[7] -= amp[0];
  jamp[10] += amp[0];
  jamp[18] -= amp[0];

  // *** DIAGRAM 184 OF 1240 ***

  // Wavefunction(s) for diagram number 184
  // (none)

  // Amplitude(s) for diagram number 184
  FFV1_0( w[38], w[9], w[72], COUPs[1], &amp[0] );
#ifdef MGONGPU_SUPPORTS_MULTICHANNEL
  if( channelId == 184 ) allNumerators[0] += cxabs2( amp[0] );
  if( channelId != 0 ) allDenominators[0] += cxabs2( amp[0] );
#endif
  jamp[7] += cxtype( 0, 1 ) * amp[0];
  jamp[10] -= cxtype( 0, 1 ) * amp[0];

  // *** DIAGRAM 185 OF 1240 ***

  // Wavefunction(s) for diagram number 185
  // (none)

  // Amplitude(s) for diagram number 185
  FFV1_0( w[3], w[77], w[24], COUPs[1], &amp[0] );
#ifdef MGONGPU_SUPPORTS_MULTICHANNEL
  if( channelId == 185 ) allNumerators[0] += cxabs2( amp[0] );
  if( channelId != 0 ) allDenominators[0] += cxabs2( amp[0] );
#endif
  jamp[4] += amp[0];
  jamp[5] -= amp[0];
  jamp[18] -= amp[0];
  jamp[19] += amp[0];

  // *** DIAGRAM 186 OF 1240 ***

  // Wavefunction(s) for diagram number 186
  // (none)

  // Amplitude(s) for diagram number 186
  VVV1_0( w[72], w[24], w[62], COUPs[0], &amp[0] );
#ifdef MGONGPU_SUPPORTS_MULTICHANNEL
  if( channelId == 186 ) allNumerators[0] += cxabs2( amp[0] );
  if( channelId != 0 ) allDenominators[0] += cxabs2( amp[0] );
#endif
  jamp[4] -= cxtype( 0, 1 ) * amp[0];
  jamp[5] += cxtype( 0, 1 ) * amp[0];
  jamp[8] += cxtype( 0, 1 ) * amp[0];
  jamp[9] -= cxtype( 0, 1 ) * amp[0];
  jamp[14] -= cxtype( 0, 1 ) * amp[0];
  jamp[15] += cxtype( 0, 1 ) * amp[0];
  jamp[18] += cxtype( 0, 1 ) * amp[0];
  jamp[19] -= cxtype( 0, 1 ) * amp[0];

  // *** DIAGRAM 187 OF 1240 ***

  // Wavefunction(s) for diagram number 187
  // (none)

  // Amplitude(s) for diagram number 187
  FFV1_0( w[3], w[59], w[72], COUPs[1], &amp[0] );
#ifdef MGONGPU_SUPPORTS_MULTICHANNEL
  if( channelId == 187 ) allNumerators[0] += cxabs2( amp[0] );
  if( channelId != 0 ) allDenominators[0] += cxabs2( amp[0] );
#endif
  jamp[8] += amp[0];
  jamp[9] -= amp[0];
  jamp[14] -= amp[0];
  jamp[15] += amp[0];

  // *** DIAGRAM 188 OF 1240 ***

  // Wavefunction(s) for diagram number 188
  FFV1_1( w[34], w[1], COUPs[1], cIPD[0], cIPD[1], w[77] );

  // Amplitude(s) for diagram number 188
  FFV1_0( w[7], w[77], w[6], COUPs[1], &amp[0] );
#ifdef MGONGPU_SUPPORTS_MULTICHANNEL
  if( channelId == 188 ) allNumerators[0] += cxabs2( amp[0] );
  if( channelId != 0 ) allDenominators[0] += cxabs2( amp[0] );
#endif
  jamp[5] -= amp[0];

  // *** DIAGRAM 189 OF 1240 ***

  // Wavefunction(s) for diagram number 189
  // (none)

  // Amplitude(s) for diagram number 189
  FFV1_0( w[53], w[77], w[5], COUPs[1], &amp[0] );
#ifdef MGONGPU_SUPPORTS_MULTICHANNEL
  if( channelId == 189 ) allNumerators[0] += cxabs2( amp[0] );
  if( channelId != 0 ) allDenominators[0] += cxabs2( amp[0] );
#endif
  jamp[3] -= amp[0];

  // *** DIAGRAM 190 OF 1240 ***

  // Wavefunction(s) for diagram number 190
  FFV1_2( w[46], w[1], COUPs[1], cIPD[0], cIPD[1], w[78] );

  // Amplitude(s) for diagram number 190
  FFV1_0( w[78], w[55], w[6], COUPs[1], &amp[0] );
#ifdef MGONGPU_SUPPORTS_MULTICHANNEL
  if( channelId == 190 ) allNumerators[0] += cxabs2( amp[0] );
  if( channelId != 0 ) allDenominators[0] += cxabs2( amp[0] );
#endif
  jamp[16] -= amp[0];

  // *** DIAGRAM 191 OF 1240 ***

  // Wavefunction(s) for diagram number 191
  // (none)

  // Amplitude(s) for diagram number 191
  FFV1_0( w[53], w[55], w[1], COUPs[1], &amp[0] );
#ifdef MGONGPU_SUPPORTS_MULTICHANNEL
  if( channelId == 191 ) allNumerators[0] += cxabs2( amp[0] );
  if( channelId != 0 ) allDenominators[0] += cxabs2( amp[0] );
#endif
  jamp[13] -= amp[0];

  // *** DIAGRAM 192 OF 1240 ***

  // Wavefunction(s) for diagram number 192
  // (none)

  // Amplitude(s) for diagram number 192
  FFV1_0( w[78], w[57], w[5], COUPs[1], &amp[0] );
#ifdef MGONGPU_SUPPORTS_MULTICHANNEL
  if( channelId == 192 ) allNumerators[0] += cxabs2( amp[0] );
  if( channelId != 0 ) allDenominators[0] += cxabs2( amp[0] );
#endif
  jamp[22] -= amp[0];

  // *** DIAGRAM 193 OF 1240 ***

  // Wavefunction(s) for diagram number 193
  // (none)

  // Amplitude(s) for diagram number 193
  FFV1_0( w[7], w[57], w[1], COUPs[1], &amp[0] );
#ifdef MGONGPU_SUPPORTS_MULTICHANNEL
  if( channelId == 193 ) allNumerators[0] += cxabs2( amp[0] );
  if( channelId != 0 ) allDenominators[0] += cxabs2( amp[0] );
#endif
  jamp[19] -= amp[0];

  // *** DIAGRAM 194 OF 1240 ***

  // Wavefunction(s) for diagram number 194
  // (none)

  // Amplitude(s) for diagram number 194
  FFV1_0( w[46], w[77], w[29], COUPs[1], &amp[0] );
#ifdef MGONGPU_SUPPORTS_MULTICHANNEL
  if( channelId == 194 ) allNumerators[0] += cxabs2( amp[0] );
  if( channelId != 0 ) allDenominators[0] += cxabs2( amp[0] );
#endif
  jamp[3] += cxtype( 0, 1 ) * amp[0];
  jamp[5] -= cxtype( 0, 1 ) * amp[0];

  // *** DIAGRAM 195 OF 1240 ***

  // Wavefunction(s) for diagram number 195
  // (none)

  // Amplitude(s) for diagram number 195
  VVV1_0( w[1], w[29], w[73], COUPs[0], &amp[0] );
#ifdef MGONGPU_SUPPORTS_MULTICHANNEL
  if( channelId == 195 ) allNumerators[0] += cxabs2( amp[0] );
  if( channelId != 0 ) allDenominators[0] += cxabs2( amp[0] );
#endif
  jamp[3] += amp[0];
  jamp[5] -= amp[0];
  jamp[16] -= amp[0];
  jamp[22] += amp[0];

  // *** DIAGRAM 196 OF 1240 ***

  // Wavefunction(s) for diagram number 196
  // (none)

  // Amplitude(s) for diagram number 196
  FFV1_0( w[46], w[58], w[1], COUPs[1], &amp[0] );
#ifdef MGONGPU_SUPPORTS_MULTICHANNEL
  if( channelId == 196 ) allNumerators[0] += cxabs2( amp[0] );
  if( channelId != 0 ) allDenominators[0] += cxabs2( amp[0] );
#endif
  jamp[16] += cxtype( 0, 1 ) * amp[0];
  jamp[22] -= cxtype( 0, 1 ) * amp[0];

  // *** DIAGRAM 197 OF 1240 ***

  // Wavefunction(s) for diagram number 197
  // (none)

  // Amplitude(s) for diagram number 197
  FFV1_0( w[25], w[77], w[6], COUPs[1], &amp[0] );
#ifdef MGONGPU_SUPPORTS_MULTICHANNEL
  if( channelId == 197 ) allNumerators[0] += cxabs2( amp[0] );
  if( channelId != 0 ) allDenominators[0] += cxabs2( amp[0] );
#endif
  jamp[4] -= amp[0];

  // *** DIAGRAM 198 OF 1240 ***

  // Wavefunction(s) for diagram number 198
  // (none)

  // Amplitude(s) for diagram number 198
  FFV1_0( w[48], w[77], w[4], COUPs[1], &amp[0] );
#ifdef MGONGPU_SUPPORTS_MULTICHANNEL
  if( channelId == 198 ) allNumerators[0] += cxabs2( amp[0] );
  if( channelId != 0 ) allDenominators[0] += cxabs2( amp[0] );
#endif
  jamp[1] -= amp[0];

  // *** DIAGRAM 199 OF 1240 ***

  // Wavefunction(s) for diagram number 199
  FFV1_2( w[38], w[1], COUPs[1], cIPD[0], cIPD[1], w[58] );

  // Amplitude(s) for diagram number 199
  FFV1_0( w[58], w[9], w[6], COUPs[1], &amp[0] );
#ifdef MGONGPU_SUPPORTS_MULTICHANNEL
  if( channelId == 199 ) allNumerators[0] += cxabs2( amp[0] );
  if( channelId != 0 ) allDenominators[0] += cxabs2( amp[0] );
#endif
  jamp[10] -= amp[0];

  // *** DIAGRAM 200 OF 1240 ***

  // Wavefunction(s) for diagram number 200
  // (none)

  // Amplitude(s) for diagram number 200
  FFV1_0( w[48], w[9], w[1], COUPs[1], &amp[0] );
#ifdef MGONGPU_SUPPORTS_MULTICHANNEL
  if( channelId == 200 ) allNumerators[0] += cxabs2( amp[0] );
  if( channelId != 0 ) allDenominators[0] += cxabs2( amp[0] );
#endif
  jamp[7] -= amp[0];

  // *** DIAGRAM 201 OF 1240 ***

  // Wavefunction(s) for diagram number 201
  // (none)

  // Amplitude(s) for diagram number 201
  FFV1_0( w[58], w[57], w[4], COUPs[1], &amp[0] );
#ifdef MGONGPU_SUPPORTS_MULTICHANNEL
  if( channelId == 201 ) allNumerators[0] += cxabs2( amp[0] );
  if( channelId != 0 ) allDenominators[0] += cxabs2( amp[0] );
#endif
  jamp[20] -= amp[0];

  // *** DIAGRAM 202 OF 1240 ***

  // Wavefunction(s) for diagram number 202
  // (none)

  // Amplitude(s) for diagram number 202
  FFV1_0( w[25], w[57], w[1], COUPs[1], &amp[0] );
#ifdef MGONGPU_SUPPORTS_MULTICHANNEL
  if( channelId == 202 ) allNumerators[0] += cxabs2( amp[0] );
  if( channelId != 0 ) allDenominators[0] += cxabs2( amp[0] );
#endif
  jamp[18] -= amp[0];

  // *** DIAGRAM 203 OF 1240 ***

  // Wavefunction(s) for diagram number 203
  // (none)

  // Amplitude(s) for diagram number 203
  FFV1_0( w[38], w[77], w[27], COUPs[1], &amp[0] );
#ifdef MGONGPU_SUPPORTS_MULTICHANNEL
  if( channelId == 203 ) allNumerators[0] += cxabs2( amp[0] );
  if( channelId != 0 ) allDenominators[0] += cxabs2( amp[0] );
#endif
  jamp[1] += cxtype( 0, 1 ) * amp[0];
  jamp[4] -= cxtype( 0, 1 ) * amp[0];

  // *** DIAGRAM 204 OF 1240 ***

  // Wavefunction(s) for diagram number 204
  // (none)

  // Amplitude(s) for diagram number 204
  VVV1_0( w[1], w[27], w[67], COUPs[0], &amp[0] );
#ifdef MGONGPU_SUPPORTS_MULTICHANNEL
  if( channelId == 204 ) allNumerators[0] += cxabs2( amp[0] );
  if( channelId != 0 ) allDenominators[0] += cxabs2( amp[0] );
#endif
  jamp[1] += amp[0];
  jamp[4] -= amp[0];
  jamp[10] -= amp[0];
  jamp[20] += amp[0];

  // *** DIAGRAM 205 OF 1240 ***

  // Wavefunction(s) for diagram number 205
  // (none)

  // Amplitude(s) for diagram number 205
  FFV1_0( w[38], w[60], w[1], COUPs[1], &amp[0] );
#ifdef MGONGPU_SUPPORTS_MULTICHANNEL
  if( channelId == 205 ) allNumerators[0] += cxabs2( amp[0] );
  if( channelId != 0 ) allDenominators[0] += cxabs2( amp[0] );
#endif
  jamp[10] += cxtype( 0, 1 ) * amp[0];
  jamp[20] -= cxtype( 0, 1 ) * amp[0];

  // *** DIAGRAM 206 OF 1240 ***

  // Wavefunction(s) for diagram number 206
  // (none)

  // Amplitude(s) for diagram number 206
  FFV1_0( w[28], w[77], w[5], COUPs[1], &amp[0] );
#ifdef MGONGPU_SUPPORTS_MULTICHANNEL
  if( channelId == 206 ) allNumerators[0] += cxabs2( amp[0] );
  if( channelId != 0 ) allDenominators[0] += cxabs2( amp[0] );
#endif
  jamp[2] -= amp[0];

  // *** DIAGRAM 207 OF 1240 ***

  // Wavefunction(s) for diagram number 207
  // (none)

  // Amplitude(s) for diagram number 207
  FFV1_0( w[40], w[77], w[4], COUPs[1], &amp[0] );
#ifdef MGONGPU_SUPPORTS_MULTICHANNEL
  if( channelId == 207 ) allNumerators[0] += cxabs2( amp[0] );
  if( channelId != 0 ) allDenominators[0] += cxabs2( amp[0] );
#endif
  jamp[0] -= amp[0];

  // *** DIAGRAM 208 OF 1240 ***

  // Wavefunction(s) for diagram number 208
  FFV1_2( w[41], w[1], COUPs[1], cIPD[0], cIPD[1], w[60] );

  // Amplitude(s) for diagram number 208
  FFV1_0( w[60], w[9], w[5], COUPs[1], &amp[0] );
#ifdef MGONGPU_SUPPORTS_MULTICHANNEL
  if( channelId == 208 ) allNumerators[0] += cxabs2( amp[0] );
  if( channelId != 0 ) allDenominators[0] += cxabs2( amp[0] );
#endif
  jamp[8] -= amp[0];

  // *** DIAGRAM 209 OF 1240 ***

  // Wavefunction(s) for diagram number 209
  // (none)

  // Amplitude(s) for diagram number 209
  FFV1_0( w[40], w[9], w[1], COUPs[1], &amp[0] );
#ifdef MGONGPU_SUPPORTS_MULTICHANNEL
  if( channelId == 209 ) allNumerators[0] += cxabs2( amp[0] );
  if( channelId != 0 ) allDenominators[0] += cxabs2( amp[0] );
#endif
  jamp[6] -= amp[0];

  // *** DIAGRAM 210 OF 1240 ***

  // Wavefunction(s) for diagram number 210
  // (none)

  // Amplitude(s) for diagram number 210
  FFV1_0( w[60], w[55], w[4], COUPs[1], &amp[0] );
#ifdef MGONGPU_SUPPORTS_MULTICHANNEL
  if( channelId == 210 ) allNumerators[0] += cxabs2( amp[0] );
  if( channelId != 0 ) allDenominators[0] += cxabs2( amp[0] );
#endif
  jamp[14] -= amp[0];

  // *** DIAGRAM 211 OF 1240 ***

  // Wavefunction(s) for diagram number 211
  // (none)

  // Amplitude(s) for diagram number 211
  FFV1_0( w[28], w[55], w[1], COUPs[1], &amp[0] );
#ifdef MGONGPU_SUPPORTS_MULTICHANNEL
  if( channelId == 211 ) allNumerators[0] += cxabs2( amp[0] );
  if( channelId != 0 ) allDenominators[0] += cxabs2( amp[0] );
#endif
  jamp[12] -= amp[0];

  // *** DIAGRAM 212 OF 1240 ***

  // Wavefunction(s) for diagram number 212
  // (none)

  // Amplitude(s) for diagram number 212
  FFV1_0( w[41], w[77], w[24], COUPs[1], &amp[0] );
#ifdef MGONGPU_SUPPORTS_MULTICHANNEL
  if( channelId == 212 ) allNumerators[0] += cxabs2( amp[0] );
  if( channelId != 0 ) allDenominators[0] += cxabs2( amp[0] );
#endif
  jamp[0] += cxtype( 0, 1 ) * amp[0];
  jamp[2] -= cxtype( 0, 1 ) * amp[0];

  // *** DIAGRAM 213 OF 1240 ***

  // Wavefunction(s) for diagram number 213
  // (none)

  // Amplitude(s) for diagram number 213
  VVV1_0( w[1], w[24], w[68], COUPs[0], &amp[0] );
#ifdef MGONGPU_SUPPORTS_MULTICHANNEL
  if( channelId == 213 ) allNumerators[0] += cxabs2( amp[0] );
  if( channelId != 0 ) allDenominators[0] += cxabs2( amp[0] );
#endif
  jamp[0] += amp[0];
  jamp[2] -= amp[0];
  jamp[8] -= amp[0];
  jamp[14] += amp[0];

  // *** DIAGRAM 214 OF 1240 ***

  // Wavefunction(s) for diagram number 214
  // (none)

  // Amplitude(s) for diagram number 214
  FFV1_0( w[41], w[59], w[1], COUPs[1], &amp[0] );
#ifdef MGONGPU_SUPPORTS_MULTICHANNEL
  if( channelId == 214 ) allNumerators[0] += cxabs2( amp[0] );
  if( channelId != 0 ) allDenominators[0] += cxabs2( amp[0] );
#endif
  jamp[8] += cxtype( 0, 1 ) * amp[0];
  jamp[14] -= cxtype( 0, 1 ) * amp[0];

  // *** DIAGRAM 215 OF 1240 ***

  // Wavefunction(s) for diagram number 215
  // (none)

  // Amplitude(s) for diagram number 215
  FFV1_0( w[26], w[77], w[6], COUPs[1], &amp[0] );
#ifdef MGONGPU_SUPPORTS_MULTICHANNEL
  if( channelId == 215 ) allNumerators[0] += cxabs2( amp[0] );
  if( channelId != 0 ) allDenominators[0] += cxabs2( amp[0] );
#endif
  jamp[4] += cxtype( 0, 1 ) * amp[0];
  jamp[5] -= cxtype( 0, 1 ) * amp[0];

  // *** DIAGRAM 216 OF 1240 ***

  // Wavefunction(s) for diagram number 216
  // (none)

  // Amplitude(s) for diagram number 216
  FFV1_0( w[3], w[77], w[42], COUPs[1], &amp[0] );
#ifdef MGONGPU_SUPPORTS_MULTICHANNEL
  if( channelId == 216 ) allNumerators[0] += cxabs2( amp[0] );
  if( channelId != 0 ) allDenominators[0] += cxabs2( amp[0] );
#endif
  jamp[0] += amp[0];
  jamp[2] -= amp[0];
  jamp[4] -= amp[0];
  jamp[5] += amp[0];

  // *** DIAGRAM 217 OF 1240 ***

  // Wavefunction(s) for diagram number 217
  VVV1P0_1( w[1], w[24], COUPs[0], 0., 0., w[59] );

  // Amplitude(s) for diagram number 217
  VVV1_0( w[62], w[59], w[6], COUPs[0], &amp[0] );
#ifdef MGONGPU_SUPPORTS_MULTICHANNEL
  if( channelId == 217 ) allNumerators[0] += cxabs2( amp[0] );
  if( channelId != 0 ) allDenominators[0] += cxabs2( amp[0] );
#endif
  jamp[0] -= cxtype( 0, 1 ) * amp[0];
  jamp[2] += cxtype( 0, 1 ) * amp[0];
  jamp[8] += cxtype( 0, 1 ) * amp[0];
  jamp[14] -= cxtype( 0, 1 ) * amp[0];
  jamp[18] += cxtype( 0, 1 ) * amp[0];
  jamp[19] -= cxtype( 0, 1 ) * amp[0];
  jamp[21] -= cxtype( 0, 1 ) * amp[0];
  jamp[23] += cxtype( 0, 1 ) * amp[0];

  // *** DIAGRAM 218 OF 1240 ***

  // Wavefunction(s) for diagram number 218
  // (none)

  // Amplitude(s) for diagram number 218
  VVV1_0( w[62], w[1], w[42], COUPs[0], &amp[0] );
#ifdef MGONGPU_SUPPORTS_MULTICHANNEL
  if( channelId == 218 ) allNumerators[0] += cxabs2( amp[0] );
  if( channelId != 0 ) allDenominators[0] += cxabs2( amp[0] );
#endif
  jamp[0] -= cxtype( 0, 1 ) * amp[0];
  jamp[2] += cxtype( 0, 1 ) * amp[0];
  jamp[4] += cxtype( 0, 1 ) * amp[0];
  jamp[5] -= cxtype( 0, 1 ) * amp[0];
  jamp[9] += cxtype( 0, 1 ) * amp[0];
  jamp[15] -= cxtype( 0, 1 ) * amp[0];
  jamp[21] -= cxtype( 0, 1 ) * amp[0];
  jamp[23] += cxtype( 0, 1 ) * amp[0];

  // *** DIAGRAM 219 OF 1240 ***

  // Wavefunction(s) for diagram number 219
  // (none)

  // Amplitude(s) for diagram number 219
  VVVV1_0( w[1], w[24], w[6], w[62], COUPs[2], &amp[0] );
  jamp[0] -= cxtype( 0, 1 ) * amp[0];
  jamp[2] += cxtype( 0, 1 ) * amp[0];
  jamp[8] += cxtype( 0, 1 ) * amp[0];
  jamp[14] -= cxtype( 0, 1 ) * amp[0];
  jamp[18] += cxtype( 0, 1 ) * amp[0];
  jamp[19] -= cxtype( 0, 1 ) * amp[0];
  jamp[21] -= cxtype( 0, 1 ) * amp[0];
  jamp[23] += cxtype( 0, 1 ) * amp[0];
  VVVV3_0( w[1], w[24], w[6], w[62], COUPs[2], &amp[0] );
  jamp[4] -= cxtype( 0, 1 ) * amp[0];
  jamp[5] += cxtype( 0, 1 ) * amp[0];
  jamp[8] += cxtype( 0, 1 ) * amp[0];
  jamp[9] -= cxtype( 0, 1 ) * amp[0];
  jamp[14] -= cxtype( 0, 1 ) * amp[0];
  jamp[15] += cxtype( 0, 1 ) * amp[0];
  jamp[18] += cxtype( 0, 1 ) * amp[0];
  jamp[19] -= cxtype( 0, 1 ) * amp[0];
  VVVV4_0( w[1], w[24], w[6], w[62], COUPs[2], &amp[0] );
  jamp[0] += cxtype( 0, 1 ) * amp[0];
  jamp[2] -= cxtype( 0, 1 ) * amp[0];
  jamp[4] -= cxtype( 0, 1 ) * amp[0];
  jamp[5] += cxtype( 0, 1 ) * amp[0];
  jamp[9] -= cxtype( 0, 1 ) * amp[0];
  jamp[15] += cxtype( 0, 1 ) * amp[0];
  jamp[21] += cxtype( 0, 1 ) * amp[0];
  jamp[23] -= cxtype( 0, 1 ) * amp[0];

  // *** DIAGRAM 220 OF 1240 ***

  // Wavefunction(s) for diagram number 220
  // (none)

  // Amplitude(s) for diagram number 220
  FFV1_0( w[3], w[57], w[59], COUPs[1], &amp[0] );
#ifdef MGONGPU_SUPPORTS_MULTICHANNEL
  if( channelId == 220 ) allNumerators[0] += cxabs2( amp[0] );
  if( channelId != 0 ) allDenominators[0] += cxabs2( amp[0] );
#endif
  jamp[18] += amp[0];
  jamp[19] -= amp[0];
  jamp[21] -= amp[0];
  jamp[23] += amp[0];

  // *** DIAGRAM 221 OF 1240 ***

  // Wavefunction(s) for diagram number 221
  // (none)

  // Amplitude(s) for diagram number 221
  FFV1_0( w[26], w[57], w[1], COUPs[1], &amp[0] );
#ifdef MGONGPU_SUPPORTS_MULTICHANNEL
  if( channelId == 221 ) allNumerators[0] += cxabs2( amp[0] );
  if( channelId != 0 ) allDenominators[0] += cxabs2( amp[0] );
#endif
  jamp[18] += cxtype( 0, 1 ) * amp[0];
  jamp[19] -= cxtype( 0, 1 ) * amp[0];

  // *** DIAGRAM 222 OF 1240 ***

  // Wavefunction(s) for diagram number 222
  // (none)

  // Amplitude(s) for diagram number 222
  FFV1_0( w[14], w[77], w[5], COUPs[1], &amp[0] );
#ifdef MGONGPU_SUPPORTS_MULTICHANNEL
  if( channelId == 222 ) allNumerators[0] += cxabs2( amp[0] );
  if( channelId != 0 ) allDenominators[0] += cxabs2( amp[0] );
#endif
  jamp[2] += cxtype( 0, 1 ) * amp[0];
  jamp[3] -= cxtype( 0, 1 ) * amp[0];

  // *** DIAGRAM 223 OF 1240 ***

  // Wavefunction(s) for diagram number 223
  // (none)

  // Amplitude(s) for diagram number 223
  FFV1_0( w[3], w[77], w[16], COUPs[1], &amp[0] );
#ifdef MGONGPU_SUPPORTS_MULTICHANNEL
  if( channelId == 223 ) allNumerators[0] += cxabs2( amp[0] );
  if( channelId != 0 ) allDenominators[0] += cxabs2( amp[0] );
#endif
  jamp[1] += amp[0];
  jamp[2] -= amp[0];
  jamp[3] += amp[0];
  jamp[4] -= amp[0];

  // *** DIAGRAM 224 OF 1240 ***

  // Wavefunction(s) for diagram number 224
  VVV1P0_1( w[1], w[27], COUPs[0], 0., 0., w[68] );

  // Amplitude(s) for diagram number 224
  VVV1_0( w[62], w[68], w[5], COUPs[0], &amp[0] );
#ifdef MGONGPU_SUPPORTS_MULTICHANNEL
  if( channelId == 224 ) allNumerators[0] += cxabs2( amp[0] );
  if( channelId != 0 ) allDenominators[0] += cxabs2( amp[0] );
#endif
  jamp[1] -= cxtype( 0, 1 ) * amp[0];
  jamp[4] += cxtype( 0, 1 ) * amp[0];
  jamp[10] += cxtype( 0, 1 ) * amp[0];
  jamp[12] += cxtype( 0, 1 ) * amp[0];
  jamp[13] -= cxtype( 0, 1 ) * amp[0];
  jamp[15] -= cxtype( 0, 1 ) * amp[0];
  jamp[17] += cxtype( 0, 1 ) * amp[0];
  jamp[20] -= cxtype( 0, 1 ) * amp[0];

  // *** DIAGRAM 225 OF 1240 ***

  // Wavefunction(s) for diagram number 225
  // (none)

  // Amplitude(s) for diagram number 225
  VVV1_0( w[62], w[1], w[16], COUPs[0], &amp[0] );
#ifdef MGONGPU_SUPPORTS_MULTICHANNEL
  if( channelId == 225 ) allNumerators[0] += cxabs2( amp[0] );
  if( channelId != 0 ) allDenominators[0] += cxabs2( amp[0] );
#endif
  jamp[1] -= cxtype( 0, 1 ) * amp[0];
  jamp[2] += cxtype( 0, 1 ) * amp[0];
  jamp[3] -= cxtype( 0, 1 ) * amp[0];
  jamp[4] += cxtype( 0, 1 ) * amp[0];
  jamp[11] += cxtype( 0, 1 ) * amp[0];
  jamp[15] -= cxtype( 0, 1 ) * amp[0];
  jamp[17] += cxtype( 0, 1 ) * amp[0];
  jamp[21] -= cxtype( 0, 1 ) * amp[0];

  // *** DIAGRAM 226 OF 1240 ***

  // Wavefunction(s) for diagram number 226
  // (none)

  // Amplitude(s) for diagram number 226
  VVVV1_0( w[1], w[27], w[5], w[62], COUPs[2], &amp[0] );
  jamp[1] -= cxtype( 0, 1 ) * amp[0];
  jamp[4] += cxtype( 0, 1 ) * amp[0];
  jamp[10] += cxtype( 0, 1 ) * amp[0];
  jamp[12] += cxtype( 0, 1 ) * amp[0];
  jamp[13] -= cxtype( 0, 1 ) * amp[0];
  jamp[15] -= cxtype( 0, 1 ) * amp[0];
  jamp[17] += cxtype( 0, 1 ) * amp[0];
  jamp[20] -= cxtype( 0, 1 ) * amp[0];
  VVVV3_0( w[1], w[27], w[5], w[62], COUPs[2], &amp[0] );
  jamp[2] -= cxtype( 0, 1 ) * amp[0];
  jamp[3] += cxtype( 0, 1 ) * amp[0];
  jamp[10] += cxtype( 0, 1 ) * amp[0];
  jamp[11] -= cxtype( 0, 1 ) * amp[0];
  jamp[12] += cxtype( 0, 1 ) * amp[0];
  jamp[13] -= cxtype( 0, 1 ) * amp[0];
  jamp[20] -= cxtype( 0, 1 ) * amp[0];
  jamp[21] += cxtype( 0, 1 ) * amp[0];
  VVVV4_0( w[1], w[27], w[5], w[62], COUPs[2], &amp[0] );
  jamp[1] += cxtype( 0, 1 ) * amp[0];
  jamp[2] -= cxtype( 0, 1 ) * amp[0];
  jamp[3] += cxtype( 0, 1 ) * amp[0];
  jamp[4] -= cxtype( 0, 1 ) * amp[0];
  jamp[11] -= cxtype( 0, 1 ) * amp[0];
  jamp[15] += cxtype( 0, 1 ) * amp[0];
  jamp[17] -= cxtype( 0, 1 ) * amp[0];
  jamp[21] += cxtype( 0, 1 ) * amp[0];

  // *** DIAGRAM 227 OF 1240 ***

  // Wavefunction(s) for diagram number 227
  // (none)

  // Amplitude(s) for diagram number 227
  FFV1_0( w[3], w[55], w[68], COUPs[1], &amp[0] );
#ifdef MGONGPU_SUPPORTS_MULTICHANNEL
  if( channelId == 227 ) allNumerators[0] += cxabs2( amp[0] );
  if( channelId != 0 ) allDenominators[0] += cxabs2( amp[0] );
#endif
  jamp[12] += amp[0];
  jamp[13] -= amp[0];
  jamp[15] -= amp[0];
  jamp[17] += amp[0];

  // *** DIAGRAM 228 OF 1240 ***

  // Wavefunction(s) for diagram number 228
  // (none)

  // Amplitude(s) for diagram number 228
  FFV1_0( w[14], w[55], w[1], COUPs[1], &amp[0] );
#ifdef MGONGPU_SUPPORTS_MULTICHANNEL
  if( channelId == 228 ) allNumerators[0] += cxabs2( amp[0] );
  if( channelId != 0 ) allDenominators[0] += cxabs2( amp[0] );
#endif
  jamp[12] += cxtype( 0, 1 ) * amp[0];
  jamp[13] -= cxtype( 0, 1 ) * amp[0];

  // *** DIAGRAM 229 OF 1240 ***

  // Wavefunction(s) for diagram number 229
  // (none)

  // Amplitude(s) for diagram number 229
  FFV1_0( w[12], w[77], w[4], COUPs[1], &amp[0] );
#ifdef MGONGPU_SUPPORTS_MULTICHANNEL
  if( channelId == 229 ) allNumerators[0] += cxabs2( amp[0] );
  if( channelId != 0 ) allDenominators[0] += cxabs2( amp[0] );
#endif
  jamp[0] += cxtype( 0, 1 ) * amp[0];
  jamp[1] -= cxtype( 0, 1 ) * amp[0];

  // *** DIAGRAM 230 OF 1240 ***

  // Wavefunction(s) for diagram number 230
  // (none)

  // Amplitude(s) for diagram number 230
  FFV1_0( w[3], w[77], w[19], COUPs[1], &amp[0] );
#ifdef MGONGPU_SUPPORTS_MULTICHANNEL
  if( channelId == 230 ) allNumerators[0] += cxabs2( amp[0] );
  if( channelId != 0 ) allDenominators[0] += cxabs2( amp[0] );
#endif
  jamp[0] += amp[0];
  jamp[1] -= amp[0];
  jamp[3] -= amp[0];
  jamp[5] += amp[0];

  // *** DIAGRAM 231 OF 1240 ***

  // Wavefunction(s) for diagram number 231
  VVV1P0_1( w[1], w[29], COUPs[0], 0., 0., w[67] );

  // Amplitude(s) for diagram number 231
  VVV1_0( w[62], w[67], w[4], COUPs[0], &amp[0] );
#ifdef MGONGPU_SUPPORTS_MULTICHANNEL
  if( channelId == 231 ) allNumerators[0] += cxabs2( amp[0] );
  if( channelId != 0 ) allDenominators[0] += cxabs2( amp[0] );
#endif
  jamp[3] -= cxtype( 0, 1 ) * amp[0];
  jamp[5] += cxtype( 0, 1 ) * amp[0];
  jamp[6] += cxtype( 0, 1 ) * amp[0];
  jamp[7] -= cxtype( 0, 1 ) * amp[0];
  jamp[9] -= cxtype( 0, 1 ) * amp[0];
  jamp[11] += cxtype( 0, 1 ) * amp[0];
  jamp[16] += cxtype( 0, 1 ) * amp[0];
  jamp[22] -= cxtype( 0, 1 ) * amp[0];

  // *** DIAGRAM 232 OF 1240 ***

  // Wavefunction(s) for diagram number 232
  // (none)

  // Amplitude(s) for diagram number 232
  VVV1_0( w[62], w[1], w[19], COUPs[0], &amp[0] );
#ifdef MGONGPU_SUPPORTS_MULTICHANNEL
  if( channelId == 232 ) allNumerators[0] += cxabs2( amp[0] );
  if( channelId != 0 ) allDenominators[0] += cxabs2( amp[0] );
#endif
  jamp[0] -= cxtype( 0, 1 ) * amp[0];
  jamp[1] += cxtype( 0, 1 ) * amp[0];
  jamp[3] += cxtype( 0, 1 ) * amp[0];
  jamp[5] -= cxtype( 0, 1 ) * amp[0];
  jamp[9] += cxtype( 0, 1 ) * amp[0];
  jamp[11] -= cxtype( 0, 1 ) * amp[0];
  jamp[17] -= cxtype( 0, 1 ) * amp[0];
  jamp[23] += cxtype( 0, 1 ) * amp[0];

  // *** DIAGRAM 233 OF 1240 ***

  // Wavefunction(s) for diagram number 233
  // (none)

  // Amplitude(s) for diagram number 233
  VVVV1_0( w[1], w[4], w[29], w[62], COUPs[2], &amp[0] );
  jamp[0] -= cxtype( 0, 1 ) * amp[0];
  jamp[1] += cxtype( 0, 1 ) * amp[0];
  jamp[6] += cxtype( 0, 1 ) * amp[0];
  jamp[7] -= cxtype( 0, 1 ) * amp[0];
  jamp[16] += cxtype( 0, 1 ) * amp[0];
  jamp[17] -= cxtype( 0, 1 ) * amp[0];
  jamp[22] -= cxtype( 0, 1 ) * amp[0];
  jamp[23] += cxtype( 0, 1 ) * amp[0];
  VVVV3_0( w[1], w[4], w[29], w[62], COUPs[2], &amp[0] );
  jamp[3] -= cxtype( 0, 1 ) * amp[0];
  jamp[5] += cxtype( 0, 1 ) * amp[0];
  jamp[6] += cxtype( 0, 1 ) * amp[0];
  jamp[7] -= cxtype( 0, 1 ) * amp[0];
  jamp[9] -= cxtype( 0, 1 ) * amp[0];
  jamp[11] += cxtype( 0, 1 ) * amp[0];
  jamp[16] += cxtype( 0, 1 ) * amp[0];
  jamp[22] -= cxtype( 0, 1 ) * amp[0];
  VVVV4_0( w[1], w[4], w[29], w[62], COUPs[2], &amp[0] );
  jamp[0] += cxtype( 0, 1 ) * amp[0];
  jamp[1] -= cxtype( 0, 1 ) * amp[0];
  jamp[3] -= cxtype( 0, 1 ) * amp[0];
  jamp[5] += cxtype( 0, 1 ) * amp[0];
  jamp[9] -= cxtype( 0, 1 ) * amp[0];
  jamp[11] += cxtype( 0, 1 ) * amp[0];
  jamp[17] += cxtype( 0, 1 ) * amp[0];
  jamp[23] -= cxtype( 0, 1 ) * amp[0];

  // *** DIAGRAM 234 OF 1240 ***

  // Wavefunction(s) for diagram number 234
  // (none)

  // Amplitude(s) for diagram number 234
  FFV1_0( w[3], w[9], w[67], COUPs[1], &amp[0] );
#ifdef MGONGPU_SUPPORTS_MULTICHANNEL
  if( channelId == 234 ) allNumerators[0] += cxabs2( amp[0] );
  if( channelId != 0 ) allDenominators[0] += cxabs2( amp[0] );
#endif
  jamp[6] += amp[0];
  jamp[7] -= amp[0];
  jamp[9] -= amp[0];
  jamp[11] += amp[0];

  // *** DIAGRAM 235 OF 1240 ***

  // Wavefunction(s) for diagram number 235
  // (none)

  // Amplitude(s) for diagram number 235
  FFV1_0( w[12], w[9], w[1], COUPs[1], &amp[0] );
#ifdef MGONGPU_SUPPORTS_MULTICHANNEL
  if( channelId == 235 ) allNumerators[0] += cxabs2( amp[0] );
  if( channelId != 0 ) allDenominators[0] += cxabs2( amp[0] );
#endif
  jamp[6] += cxtype( 0, 1 ) * amp[0];
  jamp[7] -= cxtype( 0, 1 ) * amp[0];

  // *** DIAGRAM 236 OF 1240 ***

  // Wavefunction(s) for diagram number 236
  VVVV1P0_1( w[1], w[4], w[5], COUPs[2], 0., 0., w[73] );
  VVVV3P0_1( w[1], w[4], w[5], COUPs[2], 0., 0., w[79] );
  VVVV4P0_1( w[1], w[4], w[5], COUPs[2], 0., 0., w[80] );

  // Amplitude(s) for diagram number 236
  VVV1_0( w[73], w[6], w[62], COUPs[0], &amp[0] );
  jamp[0] -= cxtype( 0, 1 ) * amp[0];
  jamp[2] += cxtype( 0, 1 ) * amp[0];
  jamp[8] += cxtype( 0, 1 ) * amp[0];
  jamp[14] -= cxtype( 0, 1 ) * amp[0];
  jamp[18] += cxtype( 0, 1 ) * amp[0];
  jamp[19] -= cxtype( 0, 1 ) * amp[0];
  jamp[21] -= cxtype( 0, 1 ) * amp[0];
  jamp[23] += cxtype( 0, 1 ) * amp[0];
  VVV1_0( w[79], w[6], w[62], COUPs[0], &amp[0] );
  jamp[2] += cxtype( 0, 1 ) * amp[0];
  jamp[6] -= cxtype( 0, 1 ) * amp[0];
  jamp[8] += cxtype( 0, 1 ) * amp[0];
  jamp[12] -= cxtype( 0, 1 ) * amp[0];
  jamp[19] -= cxtype( 0, 1 ) * amp[0];
  jamp[20] += cxtype( 0, 1 ) * amp[0];
  jamp[21] -= cxtype( 0, 1 ) * amp[0];
  jamp[22] += cxtype( 0, 1 ) * amp[0];
  VVV1_0( w[80], w[6], w[62], COUPs[0], &amp[0] );
  jamp[0] += cxtype( 0, 1 ) * amp[0];
  jamp[6] -= cxtype( 0, 1 ) * amp[0];
  jamp[12] -= cxtype( 0, 1 ) * amp[0];
  jamp[14] += cxtype( 0, 1 ) * amp[0];
  jamp[18] -= cxtype( 0, 1 ) * amp[0];
  jamp[20] += cxtype( 0, 1 ) * amp[0];
  jamp[22] += cxtype( 0, 1 ) * amp[0];
  jamp[23] -= cxtype( 0, 1 ) * amp[0];

  // *** DIAGRAM 237 OF 1240 ***

  // Wavefunction(s) for diagram number 237
  // (none)

  // Amplitude(s) for diagram number 237
  FFV1_0( w[3], w[57], w[73], COUPs[1], &amp[0] );
  jamp[18] += amp[0];
  jamp[19] -= amp[0];
  jamp[21] -= amp[0];
  jamp[23] += amp[0];
  FFV1_0( w[3], w[57], w[79], COUPs[1], &amp[0] );
  jamp[19] -= amp[0];
  jamp[20] += amp[0];
  jamp[21] -= amp[0];
  jamp[22] += amp[0];
  FFV1_0( w[3], w[57], w[80], COUPs[1], &amp[0] );
  jamp[18] -= amp[0];
  jamp[20] += amp[0];
  jamp[22] += amp[0];
  jamp[23] -= amp[0];

  // *** DIAGRAM 238 OF 1240 ***

  // Wavefunction(s) for diagram number 238
  // (none)

  // Amplitude(s) for diagram number 238
  FFV1_0( w[41], w[34], w[73], COUPs[1], &amp[0] );
  jamp[0] += amp[0];
  jamp[2] -= amp[0];
  jamp[8] -= amp[0];
  jamp[14] += amp[0];
  FFV1_0( w[41], w[34], w[79], COUPs[1], &amp[0] );
  jamp[2] -= amp[0];
  jamp[6] += amp[0];
  jamp[8] -= amp[0];
  jamp[12] += amp[0];
  FFV1_0( w[41], w[34], w[80], COUPs[1], &amp[0] );
  jamp[0] -= amp[0];
  jamp[6] += amp[0];
  jamp[12] += amp[0];
  jamp[14] -= amp[0];

  // *** DIAGRAM 239 OF 1240 ***

  // Wavefunction(s) for diagram number 239
  VVVV1P0_1( w[1], w[4], w[6], COUPs[2], 0., 0., w[57] );
  VVVV3P0_1( w[1], w[4], w[6], COUPs[2], 0., 0., w[81] );
  VVVV4P0_1( w[1], w[4], w[6], COUPs[2], 0., 0., w[82] );

  // Amplitude(s) for diagram number 239
  VVV1_0( w[57], w[5], w[62], COUPs[0], &amp[0] );
  jamp[1] -= cxtype( 0, 1 ) * amp[0];
  jamp[4] += cxtype( 0, 1 ) * amp[0];
  jamp[10] += cxtype( 0, 1 ) * amp[0];
  jamp[12] += cxtype( 0, 1 ) * amp[0];
  jamp[13] -= cxtype( 0, 1 ) * amp[0];
  jamp[15] -= cxtype( 0, 1 ) * amp[0];
  jamp[17] += cxtype( 0, 1 ) * amp[0];
  jamp[20] -= cxtype( 0, 1 ) * amp[0];
  VVV1_0( w[81], w[5], w[62], COUPs[0], &amp[0] );
  jamp[4] += cxtype( 0, 1 ) * amp[0];
  jamp[7] -= cxtype( 0, 1 ) * amp[0];
  jamp[10] += cxtype( 0, 1 ) * amp[0];
  jamp[13] -= cxtype( 0, 1 ) * amp[0];
  jamp[14] += cxtype( 0, 1 ) * amp[0];
  jamp[15] -= cxtype( 0, 1 ) * amp[0];
  jamp[16] += cxtype( 0, 1 ) * amp[0];
  jamp[18] -= cxtype( 0, 1 ) * amp[0];
  VVV1_0( w[82], w[5], w[62], COUPs[0], &amp[0] );
  jamp[1] += cxtype( 0, 1 ) * amp[0];
  jamp[7] -= cxtype( 0, 1 ) * amp[0];
  jamp[12] -= cxtype( 0, 1 ) * amp[0];
  jamp[14] += cxtype( 0, 1 ) * amp[0];
  jamp[16] += cxtype( 0, 1 ) * amp[0];
  jamp[17] -= cxtype( 0, 1 ) * amp[0];
  jamp[18] -= cxtype( 0, 1 ) * amp[0];
  jamp[20] += cxtype( 0, 1 ) * amp[0];

  // *** DIAGRAM 240 OF 1240 ***

  // Wavefunction(s) for diagram number 240
  // (none)

  // Amplitude(s) for diagram number 240
  FFV1_0( w[3], w[55], w[57], COUPs[1], &amp[0] );
  jamp[12] += amp[0];
  jamp[13] -= amp[0];
  jamp[15] -= amp[0];
  jamp[17] += amp[0];
  FFV1_0( w[3], w[55], w[81], COUPs[1], &amp[0] );
  jamp[13] -= amp[0];
  jamp[14] += amp[0];
  jamp[15] -= amp[0];
  jamp[16] += amp[0];
  FFV1_0( w[3], w[55], w[82], COUPs[1], &amp[0] );
  jamp[12] -= amp[0];
  jamp[14] += amp[0];
  jamp[16] += amp[0];
  jamp[17] -= amp[0];

  // *** DIAGRAM 241 OF 1240 ***

  // Wavefunction(s) for diagram number 241
  // (none)

  // Amplitude(s) for diagram number 241
  FFV1_0( w[38], w[34], w[57], COUPs[1], &amp[0] );
  jamp[1] += amp[0];
  jamp[4] -= amp[0];
  jamp[10] -= amp[0];
  jamp[20] += amp[0];
  FFV1_0( w[38], w[34], w[81], COUPs[1], &amp[0] );
  jamp[4] -= amp[0];
  jamp[7] += amp[0];
  jamp[10] -= amp[0];
  jamp[18] += amp[0];
  FFV1_0( w[38], w[34], w[82], COUPs[1], &amp[0] );
  jamp[1] -= amp[0];
  jamp[7] += amp[0];
  jamp[18] += amp[0];
  jamp[20] -= amp[0];

  // *** DIAGRAM 242 OF 1240 ***

  // Wavefunction(s) for diagram number 242
  VVVV1P0_1( w[1], w[5], w[6], COUPs[2], 0., 0., w[55] );
  VVVV3P0_1( w[1], w[5], w[6], COUPs[2], 0., 0., w[83] );
  VVVV4P0_1( w[1], w[5], w[6], COUPs[2], 0., 0., w[84] );

  // Amplitude(s) for diagram number 242
  VVV1_0( w[55], w[4], w[62], COUPs[0], &amp[0] );
  jamp[3] -= cxtype( 0, 1 ) * amp[0];
  jamp[5] += cxtype( 0, 1 ) * amp[0];
  jamp[6] += cxtype( 0, 1 ) * amp[0];
  jamp[7] -= cxtype( 0, 1 ) * amp[0];
  jamp[9] -= cxtype( 0, 1 ) * amp[0];
  jamp[11] += cxtype( 0, 1 ) * amp[0];
  jamp[16] += cxtype( 0, 1 ) * amp[0];
  jamp[22] -= cxtype( 0, 1 ) * amp[0];
  VVV1_0( w[83], w[4], w[62], COUPs[0], &amp[0] );
  jamp[5] += cxtype( 0, 1 ) * amp[0];
  jamp[7] -= cxtype( 0, 1 ) * amp[0];
  jamp[8] += cxtype( 0, 1 ) * amp[0];
  jamp[9] -= cxtype( 0, 1 ) * amp[0];
  jamp[10] += cxtype( 0, 1 ) * amp[0];
  jamp[13] -= cxtype( 0, 1 ) * amp[0];
  jamp[16] += cxtype( 0, 1 ) * amp[0];
  jamp[19] -= cxtype( 0, 1 ) * amp[0];
  VVV1_0( w[84], w[4], w[62], COUPs[0], &amp[0] );
  jamp[3] += cxtype( 0, 1 ) * amp[0];
  jamp[6] -= cxtype( 0, 1 ) * amp[0];
  jamp[8] += cxtype( 0, 1 ) * amp[0];
  jamp[10] += cxtype( 0, 1 ) * amp[0];
  jamp[11] -= cxtype( 0, 1 ) * amp[0];
  jamp[13] -= cxtype( 0, 1 ) * amp[0];
  jamp[19] -= cxtype( 0, 1 ) * amp[0];
  jamp[22] += cxtype( 0, 1 ) * amp[0];

  // *** DIAGRAM 243 OF 1240 ***

  // Wavefunction(s) for diagram number 243
  // (none)

  // Amplitude(s) for diagram number 243
  FFV1_0( w[3], w[9], w[55], COUPs[1], &amp[0] );
  jamp[6] += amp[0];
  jamp[7] -= amp[0];
  jamp[9] -= amp[0];
  jamp[11] += amp[0];
  FFV1_0( w[3], w[9], w[83], COUPs[1], &amp[0] );
  jamp[7] -= amp[0];
  jamp[8] += amp[0];
  jamp[9] -= amp[0];
  jamp[10] += amp[0];
  FFV1_0( w[3], w[9], w[84], COUPs[1], &amp[0] );
  jamp[6] -= amp[0];
  jamp[8] += amp[0];
  jamp[10] += amp[0];
  jamp[11] -= amp[0];

  // *** DIAGRAM 244 OF 1240 ***

  // Wavefunction(s) for diagram number 244
  // (none)

  // Amplitude(s) for diagram number 244
  FFV1_0( w[46], w[34], w[55], COUPs[1], &amp[0] );
  jamp[3] += amp[0];
  jamp[5] -= amp[0];
  jamp[16] -= amp[0];
  jamp[22] += amp[0];
  FFV1_0( w[46], w[34], w[83], COUPs[1], &amp[0] );
  jamp[5] -= amp[0];
  jamp[13] += amp[0];
  jamp[16] -= amp[0];
  jamp[19] += amp[0];
  FFV1_0( w[46], w[34], w[84], COUPs[1], &amp[0] );
  jamp[3] -= amp[0];
  jamp[13] += amp[0];
  jamp[19] += amp[0];
  jamp[22] -= amp[0];

  // *** DIAGRAM 245 OF 1240 ***

  // Wavefunction(s) for diagram number 245
  // (none)

  // Amplitude(s) for diagram number 245
  FFV1_0( w[3], w[77], w[30], COUPs[1], &amp[0] );
  jamp[0] += amp[0];
  jamp[1] -= amp[0];
  jamp[3] -= amp[0];
  jamp[5] += amp[0];
  FFV1_0( w[3], w[77], w[31], COUPs[1], &amp[0] );
  jamp[1] -= amp[0];
  jamp[2] += amp[0];
  jamp[3] -= amp[0];
  jamp[4] += amp[0];
  FFV1_0( w[3], w[77], w[32], COUPs[1], &amp[0] );
  jamp[0] -= amp[0];
  jamp[2] += amp[0];
  jamp[4] += amp[0];
  jamp[5] -= amp[0];

  // *** DIAGRAM 246 OF 1240 ***

  // Wavefunction(s) for diagram number 246
  // (none)

  // Amplitude(s) for diagram number 246
  VVV1_0( w[1], w[30], w[62], COUPs[0], &amp[0] );
  jamp[0] -= cxtype( 0, 1 ) * amp[0];
  jamp[1] += cxtype( 0, 1 ) * amp[0];
  jamp[3] += cxtype( 0, 1 ) * amp[0];
  jamp[5] -= cxtype( 0, 1 ) * amp[0];
  jamp[9] += cxtype( 0, 1 ) * amp[0];
  jamp[11] -= cxtype( 0, 1 ) * amp[0];
  jamp[17] -= cxtype( 0, 1 ) * amp[0];
  jamp[23] += cxtype( 0, 1 ) * amp[0];
  VVV1_0( w[1], w[31], w[62], COUPs[0], &amp[0] );
  jamp[1] += cxtype( 0, 1 ) * amp[0];
  jamp[2] -= cxtype( 0, 1 ) * amp[0];
  jamp[3] += cxtype( 0, 1 ) * amp[0];
  jamp[4] -= cxtype( 0, 1 ) * amp[0];
  jamp[11] -= cxtype( 0, 1 ) * amp[0];
  jamp[15] += cxtype( 0, 1 ) * amp[0];
  jamp[17] -= cxtype( 0, 1 ) * amp[0];
  jamp[21] += cxtype( 0, 1 ) * amp[0];
  VVV1_0( w[1], w[32], w[62], COUPs[0], &amp[0] );
  jamp[0] += cxtype( 0, 1 ) * amp[0];
  jamp[2] -= cxtype( 0, 1 ) * amp[0];
  jamp[4] -= cxtype( 0, 1 ) * amp[0];
  jamp[5] += cxtype( 0, 1 ) * amp[0];
  jamp[9] -= cxtype( 0, 1 ) * amp[0];
  jamp[15] += cxtype( 0, 1 ) * amp[0];
  jamp[21] += cxtype( 0, 1 ) * amp[0];
  jamp[23] -= cxtype( 0, 1 ) * amp[0];

  // *** DIAGRAM 247 OF 1240 ***

  // Wavefunction(s) for diagram number 247
  FFV1_2( w[3], w[0], COUPs[1], cIPD[0], cIPD[1], w[62] );
  FFV1_1( w[2], w[1], COUPs[1], cIPD[0], cIPD[1], w[77] );
  FFV1_2( w[62], w[4], COUPs[1], cIPD[0], cIPD[1], w[34] );
  FFV1_1( w[77], w[5], COUPs[1], cIPD[0], cIPD[1], w[9] );

  // Amplitude(s) for diagram number 247
  FFV1_0( w[34], w[9], w[6], COUPs[1], &amp[0] );
#ifdef MGONGPU_SUPPORTS_MULTICHANNEL
  if( channelId == 247 ) allNumerators[0] += cxabs2( amp[0] );
  if( channelId != 0 ) allDenominators[0] += cxabs2( amp[0] );
#endif
  jamp[41] -= amp[0];

  // *** DIAGRAM 248 OF 1240 ***

  // Wavefunction(s) for diagram number 248
  FFV1_1( w[77], w[6], COUPs[1], cIPD[0], cIPD[1], w[85] );

  // Amplitude(s) for diagram number 248
  FFV1_0( w[34], w[85], w[5], COUPs[1], &amp[0] );
#ifdef MGONGPU_SUPPORTS_MULTICHANNEL
  if( channelId == 248 ) allNumerators[0] += cxabs2( amp[0] );
  if( channelId != 0 ) allDenominators[0] += cxabs2( amp[0] );
#endif
  jamp[47] -= amp[0];

  // *** DIAGRAM 249 OF 1240 ***

  // Wavefunction(s) for diagram number 249
  FFV1_2( w[62], w[5], COUPs[1], cIPD[0], cIPD[1], w[86] );
  FFV1_1( w[77], w[4], COUPs[1], cIPD[0], cIPD[1], w[87] );

  // Amplitude(s) for diagram number 249
  FFV1_0( w[86], w[87], w[6], COUPs[1], &amp[0] );
#ifdef MGONGPU_SUPPORTS_MULTICHANNEL
  if( channelId == 249 ) allNumerators[0] += cxabs2( amp[0] );
  if( channelId != 0 ) allDenominators[0] += cxabs2( amp[0] );
#endif
  jamp[35] -= amp[0];

  // *** DIAGRAM 250 OF 1240 ***

  // Wavefunction(s) for diagram number 250
  // (none)

  // Amplitude(s) for diagram number 250
  FFV1_0( w[86], w[85], w[4], COUPs[1], &amp[0] );
#ifdef MGONGPU_SUPPORTS_MULTICHANNEL
  if( channelId == 250 ) allNumerators[0] += cxabs2( amp[0] );
  if( channelId != 0 ) allDenominators[0] += cxabs2( amp[0] );
#endif
  jamp[45] -= amp[0];

  // *** DIAGRAM 251 OF 1240 ***

  // Wavefunction(s) for diagram number 251
  FFV1_2( w[62], w[6], COUPs[1], cIPD[0], cIPD[1], w[88] );

  // Amplitude(s) for diagram number 251
  FFV1_0( w[88], w[87], w[5], COUPs[1], &amp[0] );
#ifdef MGONGPU_SUPPORTS_MULTICHANNEL
  if( channelId == 251 ) allNumerators[0] += cxabs2( amp[0] );
  if( channelId != 0 ) allDenominators[0] += cxabs2( amp[0] );
#endif
  jamp[33] -= amp[0];

  // *** DIAGRAM 252 OF 1240 ***

  // Wavefunction(s) for diagram number 252
  // (none)

  // Amplitude(s) for diagram number 252
  FFV1_0( w[88], w[9], w[4], COUPs[1], &amp[0] );
#ifdef MGONGPU_SUPPORTS_MULTICHANNEL
  if( channelId == 252 ) allNumerators[0] += cxabs2( amp[0] );
  if( channelId != 0 ) allDenominators[0] += cxabs2( amp[0] );
#endif
  jamp[39] -= amp[0];

  // *** DIAGRAM 253 OF 1240 ***

  // Wavefunction(s) for diagram number 253
  FFV1P0_3( w[62], w[77], COUPs[1], 0., 0., w[89] );

  // Amplitude(s) for diagram number 253
  VVV1_0( w[24], w[6], w[89], COUPs[0], &amp[0] );
#ifdef MGONGPU_SUPPORTS_MULTICHANNEL
  if( channelId == 253 ) allNumerators[0] += cxabs2( amp[0] );
  if( channelId != 0 ) allDenominators[0] += cxabs2( amp[0] );
#endif
  jamp[33] += amp[0];
  jamp[39] -= amp[0];
  jamp[45] -= amp[0];
  jamp[47] += amp[0];

  // *** DIAGRAM 254 OF 1240 ***

  // Wavefunction(s) for diagram number 254
  FFV1_2( w[62], w[24], COUPs[1], cIPD[0], cIPD[1], w[90] );

  // Amplitude(s) for diagram number 254
  FFV1_0( w[90], w[77], w[6], COUPs[1], &amp[0] );
#ifdef MGONGPU_SUPPORTS_MULTICHANNEL
  if( channelId == 254 ) allNumerators[0] += cxabs2( amp[0] );
  if( channelId != 0 ) allDenominators[0] += cxabs2( amp[0] );
#endif
  jamp[45] += cxtype( 0, 1 ) * amp[0];
  jamp[47] -= cxtype( 0, 1 ) * amp[0];

  // *** DIAGRAM 255 OF 1240 ***

  // Wavefunction(s) for diagram number 255
  // (none)

  // Amplitude(s) for diagram number 255
  FFV1_0( w[88], w[77], w[24], COUPs[1], &amp[0] );
#ifdef MGONGPU_SUPPORTS_MULTICHANNEL
  if( channelId == 255 ) allNumerators[0] += cxabs2( amp[0] );
  if( channelId != 0 ) allDenominators[0] += cxabs2( amp[0] );
#endif
  jamp[33] += cxtype( 0, 1 ) * amp[0];
  jamp[39] -= cxtype( 0, 1 ) * amp[0];

  // *** DIAGRAM 256 OF 1240 ***

  // Wavefunction(s) for diagram number 256
  // (none)

  // Amplitude(s) for diagram number 256
  VVV1_0( w[27], w[5], w[89], COUPs[0], &amp[0] );
#ifdef MGONGPU_SUPPORTS_MULTICHANNEL
  if( channelId == 256 ) allNumerators[0] += cxabs2( amp[0] );
  if( channelId != 0 ) allDenominators[0] += cxabs2( amp[0] );
#endif
  jamp[35] += amp[0];
  jamp[39] -= amp[0];
  jamp[41] += amp[0];
  jamp[45] -= amp[0];

  // *** DIAGRAM 257 OF 1240 ***

  // Wavefunction(s) for diagram number 257
  FFV1_2( w[62], w[27], COUPs[1], cIPD[0], cIPD[1], w[91] );

  // Amplitude(s) for diagram number 257
  FFV1_0( w[91], w[77], w[5], COUPs[1], &amp[0] );
#ifdef MGONGPU_SUPPORTS_MULTICHANNEL
  if( channelId == 257 ) allNumerators[0] += cxabs2( amp[0] );
  if( channelId != 0 ) allDenominators[0] += cxabs2( amp[0] );
#endif
  jamp[39] += cxtype( 0, 1 ) * amp[0];
  jamp[41] -= cxtype( 0, 1 ) * amp[0];

  // *** DIAGRAM 258 OF 1240 ***

  // Wavefunction(s) for diagram number 258
  // (none)

  // Amplitude(s) for diagram number 258
  FFV1_0( w[86], w[77], w[27], COUPs[1], &amp[0] );
#ifdef MGONGPU_SUPPORTS_MULTICHANNEL
  if( channelId == 258 ) allNumerators[0] += cxabs2( amp[0] );
  if( channelId != 0 ) allDenominators[0] += cxabs2( amp[0] );
#endif
  jamp[35] += cxtype( 0, 1 ) * amp[0];
  jamp[45] -= cxtype( 0, 1 ) * amp[0];

  // *** DIAGRAM 259 OF 1240 ***

  // Wavefunction(s) for diagram number 259
  // (none)

  // Amplitude(s) for diagram number 259
  VVV1_0( w[4], w[29], w[89], COUPs[0], &amp[0] );
#ifdef MGONGPU_SUPPORTS_MULTICHANNEL
  if( channelId == 259 ) allNumerators[0] += cxabs2( amp[0] );
  if( channelId != 0 ) allDenominators[0] += cxabs2( amp[0] );
#endif
  jamp[33] += amp[0];
  jamp[35] -= amp[0];
  jamp[41] -= amp[0];
  jamp[47] += amp[0];

  // *** DIAGRAM 260 OF 1240 ***

  // Wavefunction(s) for diagram number 260
  // (none)

  // Amplitude(s) for diagram number 260
  FFV1_0( w[34], w[77], w[29], COUPs[1], &amp[0] );
#ifdef MGONGPU_SUPPORTS_MULTICHANNEL
  if( channelId == 260 ) allNumerators[0] += cxabs2( amp[0] );
  if( channelId != 0 ) allDenominators[0] += cxabs2( amp[0] );
#endif
  jamp[41] += cxtype( 0, 1 ) * amp[0];
  jamp[47] -= cxtype( 0, 1 ) * amp[0];

  // *** DIAGRAM 261 OF 1240 ***

  // Wavefunction(s) for diagram number 261
  FFV1_2( w[62], w[29], COUPs[1], cIPD[0], cIPD[1], w[89] );

  // Amplitude(s) for diagram number 261
  FFV1_0( w[89], w[77], w[4], COUPs[1], &amp[0] );
#ifdef MGONGPU_SUPPORTS_MULTICHANNEL
  if( channelId == 261 ) allNumerators[0] += cxabs2( amp[0] );
  if( channelId != 0 ) allDenominators[0] += cxabs2( amp[0] );
#endif
  jamp[33] += cxtype( 0, 1 ) * amp[0];
  jamp[35] -= cxtype( 0, 1 ) * amp[0];

  // *** DIAGRAM 262 OF 1240 ***

  // Wavefunction(s) for diagram number 262
  // (none)

  // Amplitude(s) for diagram number 262
  FFV1_0( w[62], w[77], w[30], COUPs[1], &amp[0] );
  jamp[33] += amp[0];
  jamp[35] -= amp[0];
  jamp[41] -= amp[0];
  jamp[47] += amp[0];
  FFV1_0( w[62], w[77], w[31], COUPs[1], &amp[0] );
  jamp[35] -= amp[0];
  jamp[39] += amp[0];
  jamp[41] -= amp[0];
  jamp[45] += amp[0];
  FFV1_0( w[62], w[77], w[32], COUPs[1], &amp[0] );
  jamp[33] -= amp[0];
  jamp[39] += amp[0];
  jamp[45] += amp[0];
  jamp[47] -= amp[0];

  // *** DIAGRAM 263 OF 1240 ***

  // Wavefunction(s) for diagram number 263
  FFV1P0_3( w[62], w[2], COUPs[1], 0., 0., w[92] );

  // Amplitude(s) for diagram number 263
  VVV1_0( w[92], w[63], w[6], COUPs[0], &amp[0] );
#ifdef MGONGPU_SUPPORTS_MULTICHANNEL
  if( channelId == 263 ) allNumerators[0] += cxabs2( amp[0] );
  if( channelId != 0 ) allDenominators[0] += cxabs2( amp[0] );
#endif
  jamp[33] -= cxtype( 0, 1 ) * amp[0];
  jamp[57] += cxtype( 0, 1 ) * amp[0];
  jamp[81] += cxtype( 0, 1 ) * amp[0];
  jamp[87] -= cxtype( 0, 1 ) * amp[0];
  jamp[105] += cxtype( 0, 1 ) * amp[0];
  jamp[111] -= cxtype( 0, 1 ) * amp[0];
  jamp[117] -= cxtype( 0, 1 ) * amp[0];
  jamp[119] += cxtype( 0, 1 ) * amp[0];

  // *** DIAGRAM 264 OF 1240 ***

  // Wavefunction(s) for diagram number 264
  // (none)

  // Amplitude(s) for diagram number 264
  VVV1_0( w[92], w[64], w[5], COUPs[0], &amp[0] );
#ifdef MGONGPU_SUPPORTS_MULTICHANNEL
  if( channelId == 264 ) allNumerators[0] += cxabs2( amp[0] );
  if( channelId != 0 ) allDenominators[0] += cxabs2( amp[0] );
#endif
  jamp[35] -= cxtype( 0, 1 ) * amp[0];
  jamp[59] += cxtype( 0, 1 ) * amp[0];
  jamp[81] += cxtype( 0, 1 ) * amp[0];
  jamp[87] -= cxtype( 0, 1 ) * amp[0];
  jamp[93] -= cxtype( 0, 1 ) * amp[0];
  jamp[95] += cxtype( 0, 1 ) * amp[0];
  jamp[105] += cxtype( 0, 1 ) * amp[0];
  jamp[111] -= cxtype( 0, 1 ) * amp[0];

  // *** DIAGRAM 265 OF 1240 ***

  // Wavefunction(s) for diagram number 265
  // (none)

  // Amplitude(s) for diagram number 265
  VVVV1_0( w[61], w[5], w[6], w[92], COUPs[2], &amp[0] );
  jamp[33] -= cxtype( 0, 1 ) * amp[0];
  jamp[57] += cxtype( 0, 1 ) * amp[0];
  jamp[81] += cxtype( 0, 1 ) * amp[0];
  jamp[87] -= cxtype( 0, 1 ) * amp[0];
  jamp[105] += cxtype( 0, 1 ) * amp[0];
  jamp[111] -= cxtype( 0, 1 ) * amp[0];
  jamp[117] -= cxtype( 0, 1 ) * amp[0];
  jamp[119] += cxtype( 0, 1 ) * amp[0];
  VVVV3_0( w[61], w[5], w[6], w[92], COUPs[2], &amp[0] );
  jamp[35] -= cxtype( 0, 1 ) * amp[0];
  jamp[59] += cxtype( 0, 1 ) * amp[0];
  jamp[81] += cxtype( 0, 1 ) * amp[0];
  jamp[87] -= cxtype( 0, 1 ) * amp[0];
  jamp[93] -= cxtype( 0, 1 ) * amp[0];
  jamp[95] += cxtype( 0, 1 ) * amp[0];
  jamp[105] += cxtype( 0, 1 ) * amp[0];
  jamp[111] -= cxtype( 0, 1 ) * amp[0];
  VVVV4_0( w[61], w[5], w[6], w[92], COUPs[2], &amp[0] );
  jamp[33] += cxtype( 0, 1 ) * amp[0];
  jamp[35] -= cxtype( 0, 1 ) * amp[0];
  jamp[57] -= cxtype( 0, 1 ) * amp[0];
  jamp[59] += cxtype( 0, 1 ) * amp[0];
  jamp[93] -= cxtype( 0, 1 ) * amp[0];
  jamp[95] += cxtype( 0, 1 ) * amp[0];
  jamp[117] += cxtype( 0, 1 ) * amp[0];
  jamp[119] -= cxtype( 0, 1 ) * amp[0];

  // *** DIAGRAM 266 OF 1240 ***

  // Wavefunction(s) for diagram number 266
  FFV1_1( w[2], w[61], COUPs[1], cIPD[0], cIPD[1], w[93] );

  // Amplitude(s) for diagram number 266
  FFV1_0( w[86], w[93], w[6], COUPs[1], &amp[0] );
#ifdef MGONGPU_SUPPORTS_MULTICHANNEL
  if( channelId == 266 ) allNumerators[0] += cxabs2( amp[0] );
  if( channelId != 0 ) allDenominators[0] += cxabs2( amp[0] );
#endif
  jamp[35] += cxtype( 0, 1 ) * amp[0];
  jamp[59] -= cxtype( 0, 1 ) * amp[0];

  // *** DIAGRAM 267 OF 1240 ***

  // Wavefunction(s) for diagram number 267
  // (none)

  // Amplitude(s) for diagram number 267
  FFV1_0( w[86], w[2], w[64], COUPs[1], &amp[0] );
#ifdef MGONGPU_SUPPORTS_MULTICHANNEL
  if( channelId == 267 ) allNumerators[0] += cxabs2( amp[0] );
  if( channelId != 0 ) allDenominators[0] += cxabs2( amp[0] );
#endif
  jamp[35] += amp[0];
  jamp[59] -= amp[0];
  jamp[105] -= amp[0];
  jamp[111] += amp[0];

  // *** DIAGRAM 268 OF 1240 ***

  // Wavefunction(s) for diagram number 268
  // (none)

  // Amplitude(s) for diagram number 268
  FFV1_0( w[88], w[93], w[5], COUPs[1], &amp[0] );
#ifdef MGONGPU_SUPPORTS_MULTICHANNEL
  if( channelId == 268 ) allNumerators[0] += cxabs2( amp[0] );
  if( channelId != 0 ) allDenominators[0] += cxabs2( amp[0] );
#endif
  jamp[33] += cxtype( 0, 1 ) * amp[0];
  jamp[57] -= cxtype( 0, 1 ) * amp[0];

  // *** DIAGRAM 269 OF 1240 ***

  // Wavefunction(s) for diagram number 269
  // (none)

  // Amplitude(s) for diagram number 269
  FFV1_0( w[88], w[2], w[63], COUPs[1], &amp[0] );
#ifdef MGONGPU_SUPPORTS_MULTICHANNEL
  if( channelId == 269 ) allNumerators[0] += cxabs2( amp[0] );
  if( channelId != 0 ) allDenominators[0] += cxabs2( amp[0] );
#endif
  jamp[33] += amp[0];
  jamp[57] -= amp[0];
  jamp[81] -= amp[0];
  jamp[87] += amp[0];

  // *** DIAGRAM 270 OF 1240 ***

  // Wavefunction(s) for diagram number 270
  FFV1_2( w[62], w[61], COUPs[1], cIPD[0], cIPD[1], w[94] );

  // Amplitude(s) for diagram number 270
  FFV1_0( w[94], w[39], w[6], COUPs[1], &amp[0] );
#ifdef MGONGPU_SUPPORTS_MULTICHANNEL
  if( channelId == 270 ) allNumerators[0] += cxabs2( amp[0] );
  if( channelId != 0 ) allDenominators[0] += cxabs2( amp[0] );
#endif
  jamp[93] += cxtype( 0, 1 ) * amp[0];
  jamp[95] -= cxtype( 0, 1 ) * amp[0];

  // *** DIAGRAM 271 OF 1240 ***

  // Wavefunction(s) for diagram number 271
  FFV1P0_3( w[62], w[39], COUPs[1], 0., 0., w[95] );

  // Amplitude(s) for diagram number 271
  VVV1_0( w[61], w[6], w[95], COUPs[0], &amp[0] );
#ifdef MGONGPU_SUPPORTS_MULTICHANNEL
  if( channelId == 271 ) allNumerators[0] += cxabs2( amp[0] );
  if( channelId != 0 ) allDenominators[0] += cxabs2( amp[0] );
#endif
  jamp[81] += amp[0];
  jamp[87] -= amp[0];
  jamp[93] -= amp[0];
  jamp[95] += amp[0];

  // *** DIAGRAM 272 OF 1240 ***

  // Wavefunction(s) for diagram number 272
  // (none)

  // Amplitude(s) for diagram number 272
  FFV1_0( w[88], w[39], w[61], COUPs[1], &amp[0] );
#ifdef MGONGPU_SUPPORTS_MULTICHANNEL
  if( channelId == 272 ) allNumerators[0] += cxabs2( amp[0] );
  if( channelId != 0 ) allDenominators[0] += cxabs2( amp[0] );
#endif
  jamp[81] += cxtype( 0, 1 ) * amp[0];
  jamp[87] -= cxtype( 0, 1 ) * amp[0];

  // *** DIAGRAM 273 OF 1240 ***

  // Wavefunction(s) for diagram number 273
  // (none)

  // Amplitude(s) for diagram number 273
  FFV1_0( w[94], w[47], w[5], COUPs[1], &amp[0] );
#ifdef MGONGPU_SUPPORTS_MULTICHANNEL
  if( channelId == 273 ) allNumerators[0] += cxabs2( amp[0] );
  if( channelId != 0 ) allDenominators[0] += cxabs2( amp[0] );
#endif
  jamp[117] += cxtype( 0, 1 ) * amp[0];
  jamp[119] -= cxtype( 0, 1 ) * amp[0];

  // *** DIAGRAM 274 OF 1240 ***

  // Wavefunction(s) for diagram number 274
  FFV1P0_3( w[62], w[47], COUPs[1], 0., 0., w[96] );

  // Amplitude(s) for diagram number 274
  VVV1_0( w[61], w[5], w[96], COUPs[0], &amp[0] );
#ifdef MGONGPU_SUPPORTS_MULTICHANNEL
  if( channelId == 274 ) allNumerators[0] += cxabs2( amp[0] );
  if( channelId != 0 ) allDenominators[0] += cxabs2( amp[0] );
#endif
  jamp[105] += amp[0];
  jamp[111] -= amp[0];
  jamp[117] -= amp[0];
  jamp[119] += amp[0];

  // *** DIAGRAM 275 OF 1240 ***

  // Wavefunction(s) for diagram number 275
  // (none)

  // Amplitude(s) for diagram number 275
  FFV1_0( w[86], w[47], w[61], COUPs[1], &amp[0] );
#ifdef MGONGPU_SUPPORTS_MULTICHANNEL
  if( channelId == 275 ) allNumerators[0] += cxabs2( amp[0] );
  if( channelId != 0 ) allDenominators[0] += cxabs2( amp[0] );
#endif
  jamp[105] += cxtype( 0, 1 ) * amp[0];
  jamp[111] -= cxtype( 0, 1 ) * amp[0];

  // *** DIAGRAM 276 OF 1240 ***

  // Wavefunction(s) for diagram number 276
  // (none)

  // Amplitude(s) for diagram number 276
  FFV1_0( w[94], w[2], w[29], COUPs[1], &amp[0] );
#ifdef MGONGPU_SUPPORTS_MULTICHANNEL
  if( channelId == 276 ) allNumerators[0] += cxabs2( amp[0] );
  if( channelId != 0 ) allDenominators[0] += cxabs2( amp[0] );
#endif
  jamp[93] += amp[0];
  jamp[95] -= amp[0];
  jamp[117] -= amp[0];
  jamp[119] += amp[0];

  // *** DIAGRAM 277 OF 1240 ***

  // Wavefunction(s) for diagram number 277
  // (none)

  // Amplitude(s) for diagram number 277
  VVV1_0( w[61], w[29], w[92], COUPs[0], &amp[0] );
#ifdef MGONGPU_SUPPORTS_MULTICHANNEL
  if( channelId == 277 ) allNumerators[0] += cxabs2( amp[0] );
  if( channelId != 0 ) allDenominators[0] += cxabs2( amp[0] );
#endif
  jamp[33] -= cxtype( 0, 1 ) * amp[0];
  jamp[35] += cxtype( 0, 1 ) * amp[0];
  jamp[57] += cxtype( 0, 1 ) * amp[0];
  jamp[59] -= cxtype( 0, 1 ) * amp[0];
  jamp[93] += cxtype( 0, 1 ) * amp[0];
  jamp[95] -= cxtype( 0, 1 ) * amp[0];
  jamp[117] -= cxtype( 0, 1 ) * amp[0];
  jamp[119] += cxtype( 0, 1 ) * amp[0];

  // *** DIAGRAM 278 OF 1240 ***

  // Wavefunction(s) for diagram number 278
  // (none)

  // Amplitude(s) for diagram number 278
  FFV1_0( w[89], w[2], w[61], COUPs[1], &amp[0] );
#ifdef MGONGPU_SUPPORTS_MULTICHANNEL
  if( channelId == 278 ) allNumerators[0] += cxabs2( amp[0] );
  if( channelId != 0 ) allDenominators[0] += cxabs2( amp[0] );
#endif
  jamp[33] += amp[0];
  jamp[35] -= amp[0];
  jamp[57] -= amp[0];
  jamp[59] += amp[0];

  // *** DIAGRAM 279 OF 1240 ***

  // Wavefunction(s) for diagram number 279
  // (none)

  // Amplitude(s) for diagram number 279
  VVV1_0( w[92], w[69], w[6], COUPs[0], &amp[0] );
#ifdef MGONGPU_SUPPORTS_MULTICHANNEL
  if( channelId == 279 ) allNumerators[0] += cxabs2( amp[0] );
  if( channelId != 0 ) allDenominators[0] += cxabs2( amp[0] );
#endif
  jamp[39] -= cxtype( 0, 1 ) * amp[0];
  jamp[57] += cxtype( 0, 1 ) * amp[0];
  jamp[63] -= cxtype( 0, 1 ) * amp[0];
  jamp[81] += cxtype( 0, 1 ) * amp[0];
  jamp[107] += cxtype( 0, 1 ) * amp[0];
  jamp[111] -= cxtype( 0, 1 ) * amp[0];
  jamp[113] += cxtype( 0, 1 ) * amp[0];
  jamp[117] -= cxtype( 0, 1 ) * amp[0];

  // *** DIAGRAM 280 OF 1240 ***

  // Wavefunction(s) for diagram number 280
  // (none)

  // Amplitude(s) for diagram number 280
  VVV1_0( w[92], w[70], w[4], COUPs[0], &amp[0] );
#ifdef MGONGPU_SUPPORTS_MULTICHANNEL
  if( channelId == 280 ) allNumerators[0] += cxabs2( amp[0] );
  if( channelId != 0 ) allDenominators[0] += cxabs2( amp[0] );
#endif
  jamp[41] -= cxtype( 0, 1 ) * amp[0];
  jamp[57] += cxtype( 0, 1 ) * amp[0];
  jamp[63] -= cxtype( 0, 1 ) * amp[0];
  jamp[69] -= cxtype( 0, 1 ) * amp[0];
  jamp[71] += cxtype( 0, 1 ) * amp[0];
  jamp[83] += cxtype( 0, 1 ) * amp[0];
  jamp[107] += cxtype( 0, 1 ) * amp[0];
  jamp[117] -= cxtype( 0, 1 ) * amp[0];

  // *** DIAGRAM 281 OF 1240 ***

  // Wavefunction(s) for diagram number 281
  // (none)

  // Amplitude(s) for diagram number 281
  VVVV1_0( w[66], w[4], w[6], w[92], COUPs[2], &amp[0] );
  jamp[39] -= cxtype( 0, 1 ) * amp[0];
  jamp[57] += cxtype( 0, 1 ) * amp[0];
  jamp[63] -= cxtype( 0, 1 ) * amp[0];
  jamp[81] += cxtype( 0, 1 ) * amp[0];
  jamp[107] += cxtype( 0, 1 ) * amp[0];
  jamp[111] -= cxtype( 0, 1 ) * amp[0];
  jamp[113] += cxtype( 0, 1 ) * amp[0];
  jamp[117] -= cxtype( 0, 1 ) * amp[0];
  VVVV3_0( w[66], w[4], w[6], w[92], COUPs[2], &amp[0] );
  jamp[41] -= cxtype( 0, 1 ) * amp[0];
  jamp[57] += cxtype( 0, 1 ) * amp[0];
  jamp[63] -= cxtype( 0, 1 ) * amp[0];
  jamp[69] -= cxtype( 0, 1 ) * amp[0];
  jamp[71] += cxtype( 0, 1 ) * amp[0];
  jamp[83] += cxtype( 0, 1 ) * amp[0];
  jamp[107] += cxtype( 0, 1 ) * amp[0];
  jamp[117] -= cxtype( 0, 1 ) * amp[0];
  VVVV4_0( w[66], w[4], w[6], w[92], COUPs[2], &amp[0] );
  jamp[39] += cxtype( 0, 1 ) * amp[0];
  jamp[41] -= cxtype( 0, 1 ) * amp[0];
  jamp[69] -= cxtype( 0, 1 ) * amp[0];
  jamp[71] += cxtype( 0, 1 ) * amp[0];
  jamp[81] -= cxtype( 0, 1 ) * amp[0];
  jamp[83] += cxtype( 0, 1 ) * amp[0];
  jamp[111] += cxtype( 0, 1 ) * amp[0];
  jamp[113] -= cxtype( 0, 1 ) * amp[0];

  // *** DIAGRAM 282 OF 1240 ***

  // Wavefunction(s) for diagram number 282
  FFV1_1( w[2], w[66], COUPs[1], cIPD[0], cIPD[1], w[94] );

  // Amplitude(s) for diagram number 282
  FFV1_0( w[34], w[94], w[6], COUPs[1], &amp[0] );
#ifdef MGONGPU_SUPPORTS_MULTICHANNEL
  if( channelId == 282 ) allNumerators[0] += cxabs2( amp[0] );
  if( channelId != 0 ) allDenominators[0] += cxabs2( amp[0] );
#endif
  jamp[41] += cxtype( 0, 1 ) * amp[0];
  jamp[83] -= cxtype( 0, 1 ) * amp[0];

  // *** DIAGRAM 283 OF 1240 ***

  // Wavefunction(s) for diagram number 283
  // (none)

  // Amplitude(s) for diagram number 283
  FFV1_0( w[34], w[2], w[70], COUPs[1], &amp[0] );
#ifdef MGONGPU_SUPPORTS_MULTICHANNEL
  if( channelId == 283 ) allNumerators[0] += cxabs2( amp[0] );
  if( channelId != 0 ) allDenominators[0] += cxabs2( amp[0] );
#endif
  jamp[41] += amp[0];
  jamp[83] -= amp[0];
  jamp[107] -= amp[0];
  jamp[117] += amp[0];

  // *** DIAGRAM 284 OF 1240 ***

  // Wavefunction(s) for diagram number 284
  // (none)

  // Amplitude(s) for diagram number 284
  FFV1_0( w[88], w[94], w[4], COUPs[1], &amp[0] );
#ifdef MGONGPU_SUPPORTS_MULTICHANNEL
  if( channelId == 284 ) allNumerators[0] += cxabs2( amp[0] );
  if( channelId != 0 ) allDenominators[0] += cxabs2( amp[0] );
#endif
  jamp[39] += cxtype( 0, 1 ) * amp[0];
  jamp[81] -= cxtype( 0, 1 ) * amp[0];

  // *** DIAGRAM 285 OF 1240 ***

  // Wavefunction(s) for diagram number 285
  // (none)

  // Amplitude(s) for diagram number 285
  FFV1_0( w[88], w[2], w[69], COUPs[1], &amp[0] );
#ifdef MGONGPU_SUPPORTS_MULTICHANNEL
  if( channelId == 285 ) allNumerators[0] += cxabs2( amp[0] );
  if( channelId != 0 ) allDenominators[0] += cxabs2( amp[0] );
#endif
  jamp[39] += amp[0];
  jamp[57] -= amp[0];
  jamp[63] += amp[0];
  jamp[81] -= amp[0];

  // *** DIAGRAM 286 OF 1240 ***

  // Wavefunction(s) for diagram number 286
  FFV1_2( w[62], w[66], COUPs[1], cIPD[0], cIPD[1], w[97] );

  // Amplitude(s) for diagram number 286
  FFV1_0( w[97], w[33], w[6], COUPs[1], &amp[0] );
#ifdef MGONGPU_SUPPORTS_MULTICHANNEL
  if( channelId == 286 ) allNumerators[0] += cxabs2( amp[0] );
  if( channelId != 0 ) allDenominators[0] += cxabs2( amp[0] );
#endif
  jamp[69] += cxtype( 0, 1 ) * amp[0];
  jamp[71] -= cxtype( 0, 1 ) * amp[0];

  // *** DIAGRAM 287 OF 1240 ***

  // Wavefunction(s) for diagram number 287
  FFV1P0_3( w[62], w[33], COUPs[1], 0., 0., w[98] );

  // Amplitude(s) for diagram number 287
  VVV1_0( w[66], w[6], w[98], COUPs[0], &amp[0] );
#ifdef MGONGPU_SUPPORTS_MULTICHANNEL
  if( channelId == 287 ) allNumerators[0] += cxabs2( amp[0] );
  if( channelId != 0 ) allDenominators[0] += cxabs2( amp[0] );
#endif
  jamp[57] += amp[0];
  jamp[63] -= amp[0];
  jamp[69] -= amp[0];
  jamp[71] += amp[0];

  // *** DIAGRAM 288 OF 1240 ***

  // Wavefunction(s) for diagram number 288
  // (none)

  // Amplitude(s) for diagram number 288
  FFV1_0( w[88], w[33], w[66], COUPs[1], &amp[0] );
#ifdef MGONGPU_SUPPORTS_MULTICHANNEL
  if( channelId == 288 ) allNumerators[0] += cxabs2( amp[0] );
  if( channelId != 0 ) allDenominators[0] += cxabs2( amp[0] );
#endif
  jamp[57] += cxtype( 0, 1 ) * amp[0];
  jamp[63] -= cxtype( 0, 1 ) * amp[0];

  // *** DIAGRAM 289 OF 1240 ***

  // Wavefunction(s) for diagram number 289
  // (none)

  // Amplitude(s) for diagram number 289
  FFV1_0( w[97], w[47], w[4], COUPs[1], &amp[0] );
#ifdef MGONGPU_SUPPORTS_MULTICHANNEL
  if( channelId == 289 ) allNumerators[0] += cxabs2( amp[0] );
  if( channelId != 0 ) allDenominators[0] += cxabs2( amp[0] );
#endif
  jamp[111] += cxtype( 0, 1 ) * amp[0];
  jamp[113] -= cxtype( 0, 1 ) * amp[0];

  // *** DIAGRAM 290 OF 1240 ***

  // Wavefunction(s) for diagram number 290
  // (none)

  // Amplitude(s) for diagram number 290
  VVV1_0( w[66], w[4], w[96], COUPs[0], &amp[0] );
#ifdef MGONGPU_SUPPORTS_MULTICHANNEL
  if( channelId == 290 ) allNumerators[0] += cxabs2( amp[0] );
  if( channelId != 0 ) allDenominators[0] += cxabs2( amp[0] );
#endif
  jamp[107] += amp[0];
  jamp[111] -= amp[0];
  jamp[113] += amp[0];
  jamp[117] -= amp[0];

  // *** DIAGRAM 291 OF 1240 ***

  // Wavefunction(s) for diagram number 291
  // (none)

  // Amplitude(s) for diagram number 291
  FFV1_0( w[34], w[47], w[66], COUPs[1], &amp[0] );
#ifdef MGONGPU_SUPPORTS_MULTICHANNEL
  if( channelId == 291 ) allNumerators[0] += cxabs2( amp[0] );
  if( channelId != 0 ) allDenominators[0] += cxabs2( amp[0] );
#endif
  jamp[107] += cxtype( 0, 1 ) * amp[0];
  jamp[117] -= cxtype( 0, 1 ) * amp[0];

  // *** DIAGRAM 292 OF 1240 ***

  // Wavefunction(s) for diagram number 292
  // (none)

  // Amplitude(s) for diagram number 292
  FFV1_0( w[97], w[2], w[27], COUPs[1], &amp[0] );
#ifdef MGONGPU_SUPPORTS_MULTICHANNEL
  if( channelId == 292 ) allNumerators[0] += cxabs2( amp[0] );
  if( channelId != 0 ) allDenominators[0] += cxabs2( amp[0] );
#endif
  jamp[69] += amp[0];
  jamp[71] -= amp[0];
  jamp[111] -= amp[0];
  jamp[113] += amp[0];

  // *** DIAGRAM 293 OF 1240 ***

  // Wavefunction(s) for diagram number 293
  // (none)

  // Amplitude(s) for diagram number 293
  VVV1_0( w[66], w[27], w[92], COUPs[0], &amp[0] );
#ifdef MGONGPU_SUPPORTS_MULTICHANNEL
  if( channelId == 293 ) allNumerators[0] += cxabs2( amp[0] );
  if( channelId != 0 ) allDenominators[0] += cxabs2( amp[0] );
#endif
  jamp[39] -= cxtype( 0, 1 ) * amp[0];
  jamp[41] += cxtype( 0, 1 ) * amp[0];
  jamp[69] += cxtype( 0, 1 ) * amp[0];
  jamp[71] -= cxtype( 0, 1 ) * amp[0];
  jamp[81] += cxtype( 0, 1 ) * amp[0];
  jamp[83] -= cxtype( 0, 1 ) * amp[0];
  jamp[111] -= cxtype( 0, 1 ) * amp[0];
  jamp[113] += cxtype( 0, 1 ) * amp[0];

  // *** DIAGRAM 294 OF 1240 ***

  // Wavefunction(s) for diagram number 294
  // (none)

  // Amplitude(s) for diagram number 294
  FFV1_0( w[91], w[2], w[66], COUPs[1], &amp[0] );
#ifdef MGONGPU_SUPPORTS_MULTICHANNEL
  if( channelId == 294 ) allNumerators[0] += cxabs2( amp[0] );
  if( channelId != 0 ) allDenominators[0] += cxabs2( amp[0] );
#endif
  jamp[39] += amp[0];
  jamp[41] -= amp[0];
  jamp[81] -= amp[0];
  jamp[83] += amp[0];

  // *** DIAGRAM 295 OF 1240 ***

  // Wavefunction(s) for diagram number 295
  // (none)

  // Amplitude(s) for diagram number 295
  VVV1_0( w[92], w[74], w[5], COUPs[0], &amp[0] );
#ifdef MGONGPU_SUPPORTS_MULTICHANNEL
  if( channelId == 295 ) allNumerators[0] += cxabs2( amp[0] );
  if( channelId != 0 ) allDenominators[0] += cxabs2( amp[0] );
#endif
  jamp[45] -= cxtype( 0, 1 ) * amp[0];
  jamp[59] += cxtype( 0, 1 ) * amp[0];
  jamp[69] -= cxtype( 0, 1 ) * amp[0];
  jamp[83] += cxtype( 0, 1 ) * amp[0];
  jamp[87] -= cxtype( 0, 1 ) * amp[0];
  jamp[89] += cxtype( 0, 1 ) * amp[0];
  jamp[93] -= cxtype( 0, 1 ) * amp[0];
  jamp[105] += cxtype( 0, 1 ) * amp[0];

  // *** DIAGRAM 296 OF 1240 ***

  // Wavefunction(s) for diagram number 296
  // (none)

  // Amplitude(s) for diagram number 296
  VVV1_0( w[92], w[75], w[4], COUPs[0], &amp[0] );
#ifdef MGONGPU_SUPPORTS_MULTICHANNEL
  if( channelId == 296 ) allNumerators[0] += cxabs2( amp[0] );
  if( channelId != 0 ) allDenominators[0] += cxabs2( amp[0] );
#endif
  jamp[47] -= cxtype( 0, 1 ) * amp[0];
  jamp[59] += cxtype( 0, 1 ) * amp[0];
  jamp[63] -= cxtype( 0, 1 ) * amp[0];
  jamp[65] += cxtype( 0, 1 ) * amp[0];
  jamp[69] -= cxtype( 0, 1 ) * amp[0];
  jamp[83] += cxtype( 0, 1 ) * amp[0];
  jamp[93] -= cxtype( 0, 1 ) * amp[0];
  jamp[107] += cxtype( 0, 1 ) * amp[0];

  // *** DIAGRAM 297 OF 1240 ***

  // Wavefunction(s) for diagram number 297
  // (none)

  // Amplitude(s) for diagram number 297
  VVVV1_0( w[72], w[4], w[5], w[92], COUPs[2], &amp[0] );
  jamp[45] -= cxtype( 0, 1 ) * amp[0];
  jamp[59] += cxtype( 0, 1 ) * amp[0];
  jamp[69] -= cxtype( 0, 1 ) * amp[0];
  jamp[83] += cxtype( 0, 1 ) * amp[0];
  jamp[87] -= cxtype( 0, 1 ) * amp[0];
  jamp[89] += cxtype( 0, 1 ) * amp[0];
  jamp[93] -= cxtype( 0, 1 ) * amp[0];
  jamp[105] += cxtype( 0, 1 ) * amp[0];
  VVVV3_0( w[72], w[4], w[5], w[92], COUPs[2], &amp[0] );
  jamp[47] -= cxtype( 0, 1 ) * amp[0];
  jamp[59] += cxtype( 0, 1 ) * amp[0];
  jamp[63] -= cxtype( 0, 1 ) * amp[0];
  jamp[65] += cxtype( 0, 1 ) * amp[0];
  jamp[69] -= cxtype( 0, 1 ) * amp[0];
  jamp[83] += cxtype( 0, 1 ) * amp[0];
  jamp[93] -= cxtype( 0, 1 ) * amp[0];
  jamp[107] += cxtype( 0, 1 ) * amp[0];
  VVVV4_0( w[72], w[4], w[5], w[92], COUPs[2], &amp[0] );
  jamp[45] += cxtype( 0, 1 ) * amp[0];
  jamp[47] -= cxtype( 0, 1 ) * amp[0];
  jamp[63] -= cxtype( 0, 1 ) * amp[0];
  jamp[65] += cxtype( 0, 1 ) * amp[0];
  jamp[87] += cxtype( 0, 1 ) * amp[0];
  jamp[89] -= cxtype( 0, 1 ) * amp[0];
  jamp[105] -= cxtype( 0, 1 ) * amp[0];
  jamp[107] += cxtype( 0, 1 ) * amp[0];

  // *** DIAGRAM 298 OF 1240 ***

  // Wavefunction(s) for diagram number 298
  FFV1_1( w[2], w[72], COUPs[1], cIPD[0], cIPD[1], w[97] );

  // Amplitude(s) for diagram number 298
  FFV1_0( w[34], w[97], w[5], COUPs[1], &amp[0] );
#ifdef MGONGPU_SUPPORTS_MULTICHANNEL
  if( channelId == 298 ) allNumerators[0] += cxabs2( amp[0] );
  if( channelId != 0 ) allDenominators[0] += cxabs2( amp[0] );
#endif
  jamp[47] += cxtype( 0, 1 ) * amp[0];
  jamp[107] -= cxtype( 0, 1 ) * amp[0];

  // *** DIAGRAM 299 OF 1240 ***

  // Wavefunction(s) for diagram number 299
  // (none)

  // Amplitude(s) for diagram number 299
  FFV1_0( w[34], w[2], w[75], COUPs[1], &amp[0] );
#ifdef MGONGPU_SUPPORTS_MULTICHANNEL
  if( channelId == 299 ) allNumerators[0] += cxabs2( amp[0] );
  if( channelId != 0 ) allDenominators[0] += cxabs2( amp[0] );
#endif
  jamp[47] += amp[0];
  jamp[83] -= amp[0];
  jamp[93] += amp[0];
  jamp[107] -= amp[0];

  // *** DIAGRAM 300 OF 1240 ***

  // Wavefunction(s) for diagram number 300
  // (none)

  // Amplitude(s) for diagram number 300
  FFV1_0( w[86], w[97], w[4], COUPs[1], &amp[0] );
#ifdef MGONGPU_SUPPORTS_MULTICHANNEL
  if( channelId == 300 ) allNumerators[0] += cxabs2( amp[0] );
  if( channelId != 0 ) allDenominators[0] += cxabs2( amp[0] );
#endif
  jamp[45] += cxtype( 0, 1 ) * amp[0];
  jamp[105] -= cxtype( 0, 1 ) * amp[0];

  // *** DIAGRAM 301 OF 1240 ***

  // Wavefunction(s) for diagram number 301
  // (none)

  // Amplitude(s) for diagram number 301
  FFV1_0( w[86], w[2], w[74], COUPs[1], &amp[0] );
#ifdef MGONGPU_SUPPORTS_MULTICHANNEL
  if( channelId == 301 ) allNumerators[0] += cxabs2( amp[0] );
  if( channelId != 0 ) allDenominators[0] += cxabs2( amp[0] );
#endif
  jamp[45] += amp[0];
  jamp[59] -= amp[0];
  jamp[69] += amp[0];
  jamp[105] -= amp[0];

  // *** DIAGRAM 302 OF 1240 ***

  // Wavefunction(s) for diagram number 302
  FFV1_2( w[62], w[72], COUPs[1], cIPD[0], cIPD[1], w[99] );

  // Amplitude(s) for diagram number 302
  FFV1_0( w[99], w[33], w[5], COUPs[1], &amp[0] );
#ifdef MGONGPU_SUPPORTS_MULTICHANNEL
  if( channelId == 302 ) allNumerators[0] += cxabs2( amp[0] );
  if( channelId != 0 ) allDenominators[0] += cxabs2( amp[0] );
#endif
  jamp[63] += cxtype( 0, 1 ) * amp[0];
  jamp[65] -= cxtype( 0, 1 ) * amp[0];

  // *** DIAGRAM 303 OF 1240 ***

  // Wavefunction(s) for diagram number 303
  // (none)

  // Amplitude(s) for diagram number 303
  VVV1_0( w[72], w[5], w[98], COUPs[0], &amp[0] );
#ifdef MGONGPU_SUPPORTS_MULTICHANNEL
  if( channelId == 303 ) allNumerators[0] += cxabs2( amp[0] );
  if( channelId != 0 ) allDenominators[0] += cxabs2( amp[0] );
#endif
  jamp[59] += amp[0];
  jamp[63] -= amp[0];
  jamp[65] += amp[0];
  jamp[69] -= amp[0];

  // *** DIAGRAM 304 OF 1240 ***

  // Wavefunction(s) for diagram number 304
  // (none)

  // Amplitude(s) for diagram number 304
  FFV1_0( w[86], w[33], w[72], COUPs[1], &amp[0] );
#ifdef MGONGPU_SUPPORTS_MULTICHANNEL
  if( channelId == 304 ) allNumerators[0] += cxabs2( amp[0] );
  if( channelId != 0 ) allDenominators[0] += cxabs2( amp[0] );
#endif
  jamp[59] += cxtype( 0, 1 ) * amp[0];
  jamp[69] -= cxtype( 0, 1 ) * amp[0];

  // *** DIAGRAM 305 OF 1240 ***

  // Wavefunction(s) for diagram number 305
  // (none)

  // Amplitude(s) for diagram number 305
  FFV1_0( w[99], w[39], w[4], COUPs[1], &amp[0] );
#ifdef MGONGPU_SUPPORTS_MULTICHANNEL
  if( channelId == 305 ) allNumerators[0] += cxabs2( amp[0] );
  if( channelId != 0 ) allDenominators[0] += cxabs2( amp[0] );
#endif
  jamp[87] += cxtype( 0, 1 ) * amp[0];
  jamp[89] -= cxtype( 0, 1 ) * amp[0];

  // *** DIAGRAM 306 OF 1240 ***

  // Wavefunction(s) for diagram number 306
  // (none)

  // Amplitude(s) for diagram number 306
  VVV1_0( w[72], w[4], w[95], COUPs[0], &amp[0] );
#ifdef MGONGPU_SUPPORTS_MULTICHANNEL
  if( channelId == 306 ) allNumerators[0] += cxabs2( amp[0] );
  if( channelId != 0 ) allDenominators[0] += cxabs2( amp[0] );
#endif
  jamp[83] += amp[0];
  jamp[87] -= amp[0];
  jamp[89] += amp[0];
  jamp[93] -= amp[0];

  // *** DIAGRAM 307 OF 1240 ***

  // Wavefunction(s) for diagram number 307
  // (none)

  // Amplitude(s) for diagram number 307
  FFV1_0( w[34], w[39], w[72], COUPs[1], &amp[0] );
#ifdef MGONGPU_SUPPORTS_MULTICHANNEL
  if( channelId == 307 ) allNumerators[0] += cxabs2( amp[0] );
  if( channelId != 0 ) allDenominators[0] += cxabs2( amp[0] );
#endif
  jamp[83] += cxtype( 0, 1 ) * amp[0];
  jamp[93] -= cxtype( 0, 1 ) * amp[0];

  // *** DIAGRAM 308 OF 1240 ***

  // Wavefunction(s) for diagram number 308
  // (none)

  // Amplitude(s) for diagram number 308
  FFV1_0( w[99], w[2], w[24], COUPs[1], &amp[0] );
#ifdef MGONGPU_SUPPORTS_MULTICHANNEL
  if( channelId == 308 ) allNumerators[0] += cxabs2( amp[0] );
  if( channelId != 0 ) allDenominators[0] += cxabs2( amp[0] );
#endif
  jamp[63] += amp[0];
  jamp[65] -= amp[0];
  jamp[87] -= amp[0];
  jamp[89] += amp[0];

  // *** DIAGRAM 309 OF 1240 ***

  // Wavefunction(s) for diagram number 309
  // (none)

  // Amplitude(s) for diagram number 309
  VVV1_0( w[72], w[24], w[92], COUPs[0], &amp[0] );
#ifdef MGONGPU_SUPPORTS_MULTICHANNEL
  if( channelId == 309 ) allNumerators[0] += cxabs2( amp[0] );
  if( channelId != 0 ) allDenominators[0] += cxabs2( amp[0] );
#endif
  jamp[45] -= cxtype( 0, 1 ) * amp[0];
  jamp[47] += cxtype( 0, 1 ) * amp[0];
  jamp[63] += cxtype( 0, 1 ) * amp[0];
  jamp[65] -= cxtype( 0, 1 ) * amp[0];
  jamp[87] -= cxtype( 0, 1 ) * amp[0];
  jamp[89] += cxtype( 0, 1 ) * amp[0];
  jamp[105] += cxtype( 0, 1 ) * amp[0];
  jamp[107] -= cxtype( 0, 1 ) * amp[0];

  // *** DIAGRAM 310 OF 1240 ***

  // Wavefunction(s) for diagram number 310
  // (none)

  // Amplitude(s) for diagram number 310
  FFV1_0( w[90], w[2], w[72], COUPs[1], &amp[0] );
#ifdef MGONGPU_SUPPORTS_MULTICHANNEL
  if( channelId == 310 ) allNumerators[0] += cxabs2( amp[0] );
  if( channelId != 0 ) allDenominators[0] += cxabs2( amp[0] );
#endif
  jamp[45] += amp[0];
  jamp[47] -= amp[0];
  jamp[105] -= amp[0];
  jamp[107] += amp[0];

  // *** DIAGRAM 311 OF 1240 ***

  // Wavefunction(s) for diagram number 311
  FFV1_2( w[62], w[1], COUPs[1], cIPD[0], cIPD[1], w[99] );

  // Amplitude(s) for diagram number 311
  FFV1_0( w[99], w[35], w[6], COUPs[1], &amp[0] );
#ifdef MGONGPU_SUPPORTS_MULTICHANNEL
  if( channelId == 311 ) allNumerators[0] += cxabs2( amp[0] );
  if( channelId != 0 ) allDenominators[0] += cxabs2( amp[0] );
#endif
  jamp[65] -= amp[0];

  // *** DIAGRAM 312 OF 1240 ***

  // Wavefunction(s) for diagram number 312
  // (none)

  // Amplitude(s) for diagram number 312
  FFV1_0( w[99], w[36], w[5], COUPs[1], &amp[0] );
#ifdef MGONGPU_SUPPORTS_MULTICHANNEL
  if( channelId == 312 ) allNumerators[0] += cxabs2( amp[0] );
  if( channelId != 0 ) allDenominators[0] += cxabs2( amp[0] );
#endif
  jamp[71] -= amp[0];

  // *** DIAGRAM 313 OF 1240 ***

  // Wavefunction(s) for diagram number 313
  FFV1_1( w[33], w[1], COUPs[1], cIPD[0], cIPD[1], w[100] );

  // Amplitude(s) for diagram number 313
  FFV1_0( w[86], w[100], w[6], COUPs[1], &amp[0] );
#ifdef MGONGPU_SUPPORTS_MULTICHANNEL
  if( channelId == 313 ) allNumerators[0] += cxabs2( amp[0] );
  if( channelId != 0 ) allDenominators[0] += cxabs2( amp[0] );
#endif
  jamp[59] -= amp[0];

  // *** DIAGRAM 314 OF 1240 ***

  // Wavefunction(s) for diagram number 314
  // (none)

  // Amplitude(s) for diagram number 314
  FFV1_0( w[86], w[36], w[1], COUPs[1], &amp[0] );
#ifdef MGONGPU_SUPPORTS_MULTICHANNEL
  if( channelId == 314 ) allNumerators[0] += cxabs2( amp[0] );
  if( channelId != 0 ) allDenominators[0] += cxabs2( amp[0] );
#endif
  jamp[69] -= amp[0];

  // *** DIAGRAM 315 OF 1240 ***

  // Wavefunction(s) for diagram number 315
  // (none)

  // Amplitude(s) for diagram number 315
  FFV1_0( w[88], w[100], w[5], COUPs[1], &amp[0] );
#ifdef MGONGPU_SUPPORTS_MULTICHANNEL
  if( channelId == 315 ) allNumerators[0] += cxabs2( amp[0] );
  if( channelId != 0 ) allDenominators[0] += cxabs2( amp[0] );
#endif
  jamp[57] -= amp[0];

  // *** DIAGRAM 316 OF 1240 ***

  // Wavefunction(s) for diagram number 316
  // (none)

  // Amplitude(s) for diagram number 316
  FFV1_0( w[88], w[35], w[1], COUPs[1], &amp[0] );
#ifdef MGONGPU_SUPPORTS_MULTICHANNEL
  if( channelId == 316 ) allNumerators[0] += cxabs2( amp[0] );
  if( channelId != 0 ) allDenominators[0] += cxabs2( amp[0] );
#endif
  jamp[63] -= amp[0];

  // *** DIAGRAM 317 OF 1240 ***

  // Wavefunction(s) for diagram number 317
  // (none)

  // Amplitude(s) for diagram number 317
  FFV1_0( w[99], w[33], w[29], COUPs[1], &amp[0] );
#ifdef MGONGPU_SUPPORTS_MULTICHANNEL
  if( channelId == 317 ) allNumerators[0] += cxabs2( amp[0] );
  if( channelId != 0 ) allDenominators[0] += cxabs2( amp[0] );
#endif
  jamp[65] += cxtype( 0, 1 ) * amp[0];
  jamp[71] -= cxtype( 0, 1 ) * amp[0];

  // *** DIAGRAM 318 OF 1240 ***

  // Wavefunction(s) for diagram number 318
  // (none)

  // Amplitude(s) for diagram number 318
  VVV1_0( w[1], w[29], w[98], COUPs[0], &amp[0] );
#ifdef MGONGPU_SUPPORTS_MULTICHANNEL
  if( channelId == 318 ) allNumerators[0] += cxabs2( amp[0] );
  if( channelId != 0 ) allDenominators[0] += cxabs2( amp[0] );
#endif
  jamp[57] += amp[0];
  jamp[59] -= amp[0];
  jamp[65] -= amp[0];
  jamp[71] += amp[0];

  // *** DIAGRAM 319 OF 1240 ***

  // Wavefunction(s) for diagram number 319
  // (none)

  // Amplitude(s) for diagram number 319
  FFV1_0( w[89], w[33], w[1], COUPs[1], &amp[0] );
#ifdef MGONGPU_SUPPORTS_MULTICHANNEL
  if( channelId == 319 ) allNumerators[0] += cxabs2( amp[0] );
  if( channelId != 0 ) allDenominators[0] += cxabs2( amp[0] );
#endif
  jamp[57] += cxtype( 0, 1 ) * amp[0];
  jamp[59] -= cxtype( 0, 1 ) * amp[0];

  // *** DIAGRAM 320 OF 1240 ***

  // Wavefunction(s) for diagram number 320
  // (none)

  // Amplitude(s) for diagram number 320
  FFV1_0( w[99], w[43], w[6], COUPs[1], &amp[0] );
#ifdef MGONGPU_SUPPORTS_MULTICHANNEL
  if( channelId == 320 ) allNumerators[0] += cxabs2( amp[0] );
  if( channelId != 0 ) allDenominators[0] += cxabs2( amp[0] );
#endif
  jamp[89] -= amp[0];

  // *** DIAGRAM 321 OF 1240 ***

  // Wavefunction(s) for diagram number 321
  // (none)

  // Amplitude(s) for diagram number 321
  FFV1_0( w[99], w[44], w[4], COUPs[1], &amp[0] );
#ifdef MGONGPU_SUPPORTS_MULTICHANNEL
  if( channelId == 321 ) allNumerators[0] += cxabs2( amp[0] );
  if( channelId != 0 ) allDenominators[0] += cxabs2( amp[0] );
#endif
  jamp[95] -= amp[0];

  // *** DIAGRAM 322 OF 1240 ***

  // Wavefunction(s) for diagram number 322
  FFV1_1( w[39], w[1], COUPs[1], cIPD[0], cIPD[1], w[89] );

  // Amplitude(s) for diagram number 322
  FFV1_0( w[34], w[89], w[6], COUPs[1], &amp[0] );
#ifdef MGONGPU_SUPPORTS_MULTICHANNEL
  if( channelId == 322 ) allNumerators[0] += cxabs2( amp[0] );
  if( channelId != 0 ) allDenominators[0] += cxabs2( amp[0] );
#endif
  jamp[83] -= amp[0];

  // *** DIAGRAM 323 OF 1240 ***

  // Wavefunction(s) for diagram number 323
  // (none)

  // Amplitude(s) for diagram number 323
  FFV1_0( w[34], w[44], w[1], COUPs[1], &amp[0] );
#ifdef MGONGPU_SUPPORTS_MULTICHANNEL
  if( channelId == 323 ) allNumerators[0] += cxabs2( amp[0] );
  if( channelId != 0 ) allDenominators[0] += cxabs2( amp[0] );
#endif
  jamp[93] -= amp[0];

  // *** DIAGRAM 324 OF 1240 ***

  // Wavefunction(s) for diagram number 324
  // (none)

  // Amplitude(s) for diagram number 324
  FFV1_0( w[88], w[89], w[4], COUPs[1], &amp[0] );
#ifdef MGONGPU_SUPPORTS_MULTICHANNEL
  if( channelId == 324 ) allNumerators[0] += cxabs2( amp[0] );
  if( channelId != 0 ) allDenominators[0] += cxabs2( amp[0] );
#endif
  jamp[81] -= amp[0];

  // *** DIAGRAM 325 OF 1240 ***

  // Wavefunction(s) for diagram number 325
  // (none)

  // Amplitude(s) for diagram number 325
  FFV1_0( w[88], w[43], w[1], COUPs[1], &amp[0] );
#ifdef MGONGPU_SUPPORTS_MULTICHANNEL
  if( channelId == 325 ) allNumerators[0] += cxabs2( amp[0] );
  if( channelId != 0 ) allDenominators[0] += cxabs2( amp[0] );
#endif
  jamp[87] -= amp[0];

  // *** DIAGRAM 326 OF 1240 ***

  // Wavefunction(s) for diagram number 326
  // (none)

  // Amplitude(s) for diagram number 326
  FFV1_0( w[99], w[39], w[27], COUPs[1], &amp[0] );
#ifdef MGONGPU_SUPPORTS_MULTICHANNEL
  if( channelId == 326 ) allNumerators[0] += cxabs2( amp[0] );
  if( channelId != 0 ) allDenominators[0] += cxabs2( amp[0] );
#endif
  jamp[89] += cxtype( 0, 1 ) * amp[0];
  jamp[95] -= cxtype( 0, 1 ) * amp[0];

  // *** DIAGRAM 327 OF 1240 ***

  // Wavefunction(s) for diagram number 327
  // (none)

  // Amplitude(s) for diagram number 327
  VVV1_0( w[1], w[27], w[95], COUPs[0], &amp[0] );
#ifdef MGONGPU_SUPPORTS_MULTICHANNEL
  if( channelId == 327 ) allNumerators[0] += cxabs2( amp[0] );
  if( channelId != 0 ) allDenominators[0] += cxabs2( amp[0] );
#endif
  jamp[81] += amp[0];
  jamp[83] -= amp[0];
  jamp[89] -= amp[0];
  jamp[95] += amp[0];

  // *** DIAGRAM 328 OF 1240 ***

  // Wavefunction(s) for diagram number 328
  // (none)

  // Amplitude(s) for diagram number 328
  FFV1_0( w[91], w[39], w[1], COUPs[1], &amp[0] );
#ifdef MGONGPU_SUPPORTS_MULTICHANNEL
  if( channelId == 328 ) allNumerators[0] += cxabs2( amp[0] );
  if( channelId != 0 ) allDenominators[0] += cxabs2( amp[0] );
#endif
  jamp[81] += cxtype( 0, 1 ) * amp[0];
  jamp[83] -= cxtype( 0, 1 ) * amp[0];

  // *** DIAGRAM 329 OF 1240 ***

  // Wavefunction(s) for diagram number 329
  // (none)

  // Amplitude(s) for diagram number 329
  FFV1_0( w[99], w[49], w[5], COUPs[1], &amp[0] );
#ifdef MGONGPU_SUPPORTS_MULTICHANNEL
  if( channelId == 329 ) allNumerators[0] += cxabs2( amp[0] );
  if( channelId != 0 ) allDenominators[0] += cxabs2( amp[0] );
#endif
  jamp[113] -= amp[0];

  // *** DIAGRAM 330 OF 1240 ***

  // Wavefunction(s) for diagram number 330
  // (none)

  // Amplitude(s) for diagram number 330
  FFV1_0( w[99], w[50], w[4], COUPs[1], &amp[0] );
#ifdef MGONGPU_SUPPORTS_MULTICHANNEL
  if( channelId == 330 ) allNumerators[0] += cxabs2( amp[0] );
  if( channelId != 0 ) allDenominators[0] += cxabs2( amp[0] );
#endif
  jamp[119] -= amp[0];

  // *** DIAGRAM 331 OF 1240 ***

  // Wavefunction(s) for diagram number 331
  FFV1_1( w[47], w[1], COUPs[1], cIPD[0], cIPD[1], w[91] );

  // Amplitude(s) for diagram number 331
  FFV1_0( w[34], w[91], w[5], COUPs[1], &amp[0] );
#ifdef MGONGPU_SUPPORTS_MULTICHANNEL
  if( channelId == 331 ) allNumerators[0] += cxabs2( amp[0] );
  if( channelId != 0 ) allDenominators[0] += cxabs2( amp[0] );
#endif
  jamp[107] -= amp[0];

  // *** DIAGRAM 332 OF 1240 ***

  // Wavefunction(s) for diagram number 332
  // (none)

  // Amplitude(s) for diagram number 332
  FFV1_0( w[34], w[50], w[1], COUPs[1], &amp[0] );
#ifdef MGONGPU_SUPPORTS_MULTICHANNEL
  if( channelId == 332 ) allNumerators[0] += cxabs2( amp[0] );
  if( channelId != 0 ) allDenominators[0] += cxabs2( amp[0] );
#endif
  jamp[117] -= amp[0];

  // *** DIAGRAM 333 OF 1240 ***

  // Wavefunction(s) for diagram number 333
  // (none)

  // Amplitude(s) for diagram number 333
  FFV1_0( w[86], w[91], w[4], COUPs[1], &amp[0] );
#ifdef MGONGPU_SUPPORTS_MULTICHANNEL
  if( channelId == 333 ) allNumerators[0] += cxabs2( amp[0] );
  if( channelId != 0 ) allDenominators[0] += cxabs2( amp[0] );
#endif
  jamp[105] -= amp[0];

  // *** DIAGRAM 334 OF 1240 ***

  // Wavefunction(s) for diagram number 334
  // (none)

  // Amplitude(s) for diagram number 334
  FFV1_0( w[86], w[49], w[1], COUPs[1], &amp[0] );
#ifdef MGONGPU_SUPPORTS_MULTICHANNEL
  if( channelId == 334 ) allNumerators[0] += cxabs2( amp[0] );
  if( channelId != 0 ) allDenominators[0] += cxabs2( amp[0] );
#endif
  jamp[111] -= amp[0];

  // *** DIAGRAM 335 OF 1240 ***

  // Wavefunction(s) for diagram number 335
  // (none)

  // Amplitude(s) for diagram number 335
  FFV1_0( w[99], w[47], w[24], COUPs[1], &amp[0] );
#ifdef MGONGPU_SUPPORTS_MULTICHANNEL
  if( channelId == 335 ) allNumerators[0] += cxabs2( amp[0] );
  if( channelId != 0 ) allDenominators[0] += cxabs2( amp[0] );
#endif
  jamp[113] += cxtype( 0, 1 ) * amp[0];
  jamp[119] -= cxtype( 0, 1 ) * amp[0];

  // *** DIAGRAM 336 OF 1240 ***

  // Wavefunction(s) for diagram number 336
  // (none)

  // Amplitude(s) for diagram number 336
  VVV1_0( w[1], w[24], w[96], COUPs[0], &amp[0] );
#ifdef MGONGPU_SUPPORTS_MULTICHANNEL
  if( channelId == 336 ) allNumerators[0] += cxabs2( amp[0] );
  if( channelId != 0 ) allDenominators[0] += cxabs2( amp[0] );
#endif
  jamp[105] += amp[0];
  jamp[107] -= amp[0];
  jamp[113] -= amp[0];
  jamp[119] += amp[0];

  // *** DIAGRAM 337 OF 1240 ***

  // Wavefunction(s) for diagram number 337
  // (none)

  // Amplitude(s) for diagram number 337
  FFV1_0( w[90], w[47], w[1], COUPs[1], &amp[0] );
#ifdef MGONGPU_SUPPORTS_MULTICHANNEL
  if( channelId == 337 ) allNumerators[0] += cxabs2( amp[0] );
  if( channelId != 0 ) allDenominators[0] += cxabs2( amp[0] );
#endif
  jamp[105] += cxtype( 0, 1 ) * amp[0];
  jamp[107] -= cxtype( 0, 1 ) * amp[0];

  // *** DIAGRAM 338 OF 1240 ***

  // Wavefunction(s) for diagram number 338
  // (none)

  // Amplitude(s) for diagram number 338
  FFV1_0( w[99], w[17], w[6], COUPs[1], &amp[0] );
#ifdef MGONGPU_SUPPORTS_MULTICHANNEL
  if( channelId == 338 ) allNumerators[0] += cxabs2( amp[0] );
  if( channelId != 0 ) allDenominators[0] += cxabs2( amp[0] );
#endif
  jamp[65] += cxtype( 0, 1 ) * amp[0];
  jamp[89] -= cxtype( 0, 1 ) * amp[0];

  // *** DIAGRAM 339 OF 1240 ***

  // Wavefunction(s) for diagram number 339
  // (none)

  // Amplitude(s) for diagram number 339
  FFV1_0( w[99], w[2], w[42], COUPs[1], &amp[0] );
#ifdef MGONGPU_SUPPORTS_MULTICHANNEL
  if( channelId == 339 ) allNumerators[0] += cxabs2( amp[0] );
  if( channelId != 0 ) allDenominators[0] += cxabs2( amp[0] );
#endif
  jamp[65] += amp[0];
  jamp[89] -= amp[0];
  jamp[113] -= amp[0];
  jamp[119] += amp[0];

  // *** DIAGRAM 340 OF 1240 ***

  // Wavefunction(s) for diagram number 340
  // (none)

  // Amplitude(s) for diagram number 340
  VVV1_0( w[92], w[59], w[6], COUPs[0], &amp[0] );
#ifdef MGONGPU_SUPPORTS_MULTICHANNEL
  if( channelId == 340 ) allNumerators[0] += cxabs2( amp[0] );
  if( channelId != 0 ) allDenominators[0] += cxabs2( amp[0] );
#endif
  jamp[33] -= cxtype( 0, 1 ) * amp[0];
  jamp[39] += cxtype( 0, 1 ) * amp[0];
  jamp[63] += cxtype( 0, 1 ) * amp[0];
  jamp[87] -= cxtype( 0, 1 ) * amp[0];
  jamp[105] += cxtype( 0, 1 ) * amp[0];
  jamp[107] -= cxtype( 0, 1 ) * amp[0];
  jamp[113] -= cxtype( 0, 1 ) * amp[0];
  jamp[119] += cxtype( 0, 1 ) * amp[0];

  // *** DIAGRAM 341 OF 1240 ***

  // Wavefunction(s) for diagram number 341
  // (none)

  // Amplitude(s) for diagram number 341
  VVV1_0( w[92], w[1], w[42], COUPs[0], &amp[0] );
#ifdef MGONGPU_SUPPORTS_MULTICHANNEL
  if( channelId == 341 ) allNumerators[0] += cxabs2( amp[0] );
  if( channelId != 0 ) allDenominators[0] += cxabs2( amp[0] );
#endif
  jamp[33] -= cxtype( 0, 1 ) * amp[0];
  jamp[39] += cxtype( 0, 1 ) * amp[0];
  jamp[45] += cxtype( 0, 1 ) * amp[0];
  jamp[47] -= cxtype( 0, 1 ) * amp[0];
  jamp[65] += cxtype( 0, 1 ) * amp[0];
  jamp[89] -= cxtype( 0, 1 ) * amp[0];
  jamp[113] -= cxtype( 0, 1 ) * amp[0];
  jamp[119] += cxtype( 0, 1 ) * amp[0];

  // *** DIAGRAM 342 OF 1240 ***

  // Wavefunction(s) for diagram number 342
  // (none)

  // Amplitude(s) for diagram number 342
  VVVV1_0( w[1], w[24], w[6], w[92], COUPs[2], &amp[0] );
  jamp[33] -= cxtype( 0, 1 ) * amp[0];
  jamp[39] += cxtype( 0, 1 ) * amp[0];
  jamp[63] += cxtype( 0, 1 ) * amp[0];
  jamp[87] -= cxtype( 0, 1 ) * amp[0];
  jamp[105] += cxtype( 0, 1 ) * amp[0];
  jamp[107] -= cxtype( 0, 1 ) * amp[0];
  jamp[113] -= cxtype( 0, 1 ) * amp[0];
  jamp[119] += cxtype( 0, 1 ) * amp[0];
  VVVV3_0( w[1], w[24], w[6], w[92], COUPs[2], &amp[0] );
  jamp[45] -= cxtype( 0, 1 ) * amp[0];
  jamp[47] += cxtype( 0, 1 ) * amp[0];
  jamp[63] += cxtype( 0, 1 ) * amp[0];
  jamp[65] -= cxtype( 0, 1 ) * amp[0];
  jamp[87] -= cxtype( 0, 1 ) * amp[0];
  jamp[89] += cxtype( 0, 1 ) * amp[0];
  jamp[105] += cxtype( 0, 1 ) * amp[0];
  jamp[107] -= cxtype( 0, 1 ) * amp[0];
  VVVV4_0( w[1], w[24], w[6], w[92], COUPs[2], &amp[0] );
  jamp[33] += cxtype( 0, 1 ) * amp[0];
  jamp[39] -= cxtype( 0, 1 ) * amp[0];
  jamp[45] -= cxtype( 0, 1 ) * amp[0];
  jamp[47] += cxtype( 0, 1 ) * amp[0];
  jamp[65] -= cxtype( 0, 1 ) * amp[0];
  jamp[89] += cxtype( 0, 1 ) * amp[0];
  jamp[113] += cxtype( 0, 1 ) * amp[0];
  jamp[119] -= cxtype( 0, 1 ) * amp[0];

  // *** DIAGRAM 343 OF 1240 ***

  // Wavefunction(s) for diagram number 343
  // (none)

  // Amplitude(s) for diagram number 343
  FFV1_0( w[88], w[2], w[59], COUPs[1], &amp[0] );
#ifdef MGONGPU_SUPPORTS_MULTICHANNEL
  if( channelId == 343 ) allNumerators[0] += cxabs2( amp[0] );
  if( channelId != 0 ) allDenominators[0] += cxabs2( amp[0] );
#endif
  jamp[33] += amp[0];
  jamp[39] -= amp[0];
  jamp[63] -= amp[0];
  jamp[87] += amp[0];

  // *** DIAGRAM 344 OF 1240 ***

  // Wavefunction(s) for diagram number 344
  // (none)

  // Amplitude(s) for diagram number 344
  FFV1_0( w[88], w[17], w[1], COUPs[1], &amp[0] );
#ifdef MGONGPU_SUPPORTS_MULTICHANNEL
  if( channelId == 344 ) allNumerators[0] += cxabs2( amp[0] );
  if( channelId != 0 ) allDenominators[0] += cxabs2( amp[0] );
#endif
  jamp[63] += cxtype( 0, 1 ) * amp[0];
  jamp[87] -= cxtype( 0, 1 ) * amp[0];

  // *** DIAGRAM 345 OF 1240 ***

  // Wavefunction(s) for diagram number 345
  // (none)

  // Amplitude(s) for diagram number 345
  FFV1_0( w[99], w[15], w[5], COUPs[1], &amp[0] );
#ifdef MGONGPU_SUPPORTS_MULTICHANNEL
  if( channelId == 345 ) allNumerators[0] += cxabs2( amp[0] );
  if( channelId != 0 ) allDenominators[0] += cxabs2( amp[0] );
#endif
  jamp[71] += cxtype( 0, 1 ) * amp[0];
  jamp[113] -= cxtype( 0, 1 ) * amp[0];

  // *** DIAGRAM 346 OF 1240 ***

  // Wavefunction(s) for diagram number 346
  // (none)

  // Amplitude(s) for diagram number 346
  FFV1_0( w[99], w[2], w[16], COUPs[1], &amp[0] );
#ifdef MGONGPU_SUPPORTS_MULTICHANNEL
  if( channelId == 346 ) allNumerators[0] += cxabs2( amp[0] );
  if( channelId != 0 ) allDenominators[0] += cxabs2( amp[0] );
#endif
  jamp[71] += amp[0];
  jamp[89] -= amp[0];
  jamp[95] += amp[0];
  jamp[113] -= amp[0];

  // *** DIAGRAM 347 OF 1240 ***

  // Wavefunction(s) for diagram number 347
  // (none)

  // Amplitude(s) for diagram number 347
  VVV1_0( w[92], w[68], w[5], COUPs[0], &amp[0] );
#ifdef MGONGPU_SUPPORTS_MULTICHANNEL
  if( channelId == 347 ) allNumerators[0] += cxabs2( amp[0] );
  if( channelId != 0 ) allDenominators[0] += cxabs2( amp[0] );
#endif
  jamp[35] -= cxtype( 0, 1 ) * amp[0];
  jamp[45] += cxtype( 0, 1 ) * amp[0];
  jamp[69] += cxtype( 0, 1 ) * amp[0];
  jamp[81] += cxtype( 0, 1 ) * amp[0];
  jamp[83] -= cxtype( 0, 1 ) * amp[0];
  jamp[89] -= cxtype( 0, 1 ) * amp[0];
  jamp[95] += cxtype( 0, 1 ) * amp[0];
  jamp[111] -= cxtype( 0, 1 ) * amp[0];

  // *** DIAGRAM 348 OF 1240 ***

  // Wavefunction(s) for diagram number 348
  // (none)

  // Amplitude(s) for diagram number 348
  VVV1_0( w[92], w[1], w[16], COUPs[0], &amp[0] );
#ifdef MGONGPU_SUPPORTS_MULTICHANNEL
  if( channelId == 348 ) allNumerators[0] += cxabs2( amp[0] );
  if( channelId != 0 ) allDenominators[0] += cxabs2( amp[0] );
#endif
  jamp[35] -= cxtype( 0, 1 ) * amp[0];
  jamp[39] += cxtype( 0, 1 ) * amp[0];
  jamp[41] -= cxtype( 0, 1 ) * amp[0];
  jamp[45] += cxtype( 0, 1 ) * amp[0];
  jamp[71] += cxtype( 0, 1 ) * amp[0];
  jamp[89] -= cxtype( 0, 1 ) * amp[0];
  jamp[95] += cxtype( 0, 1 ) * amp[0];
  jamp[113] -= cxtype( 0, 1 ) * amp[0];

  // *** DIAGRAM 349 OF 1240 ***

  // Wavefunction(s) for diagram number 349
  // (none)

  // Amplitude(s) for diagram number 349
  VVVV1_0( w[1], w[27], w[5], w[92], COUPs[2], &amp[0] );
  jamp[35] -= cxtype( 0, 1 ) * amp[0];
  jamp[45] += cxtype( 0, 1 ) * amp[0];
  jamp[69] += cxtype( 0, 1 ) * amp[0];
  jamp[81] += cxtype( 0, 1 ) * amp[0];
  jamp[83] -= cxtype( 0, 1 ) * amp[0];
  jamp[89] -= cxtype( 0, 1 ) * amp[0];
  jamp[95] += cxtype( 0, 1 ) * amp[0];
  jamp[111] -= cxtype( 0, 1 ) * amp[0];
  VVVV3_0( w[1], w[27], w[5], w[92], COUPs[2], &amp[0] );
  jamp[39] -= cxtype( 0, 1 ) * amp[0];
  jamp[41] += cxtype( 0, 1 ) * amp[0];
  jamp[69] += cxtype( 0, 1 ) * amp[0];
  jamp[71] -= cxtype( 0, 1 ) * amp[0];
  jamp[81] += cxtype( 0, 1 ) * amp[0];
  jamp[83] -= cxtype( 0, 1 ) * amp[0];
  jamp[111] -= cxtype( 0, 1 ) * amp[0];
  jamp[113] += cxtype( 0, 1 ) * amp[0];
  VVVV4_0( w[1], w[27], w[5], w[92], COUPs[2], &amp[0] );
  jamp[35] += cxtype( 0, 1 ) * amp[0];
  jamp[39] -= cxtype( 0, 1 ) * amp[0];
  jamp[41] += cxtype( 0, 1 ) * amp[0];
  jamp[45] -= cxtype( 0, 1 ) * amp[0];
  jamp[71] -= cxtype( 0, 1 ) * amp[0];
  jamp[89] += cxtype( 0, 1 ) * amp[0];
  jamp[95] -= cxtype( 0, 1 ) * amp[0];
  jamp[113] += cxtype( 0, 1 ) * amp[0];

  // *** DIAGRAM 350 OF 1240 ***

  // Wavefunction(s) for diagram number 350
  // (none)

  // Amplitude(s) for diagram number 350
  FFV1_0( w[86], w[2], w[68], COUPs[1], &amp[0] );
#ifdef MGONGPU_SUPPORTS_MULTICHANNEL
  if( channelId == 350 ) allNumerators[0] += cxabs2( amp[0] );
  if( channelId != 0 ) allDenominators[0] += cxabs2( amp[0] );
#endif
  jamp[35] += amp[0];
  jamp[45] -= amp[0];
  jamp[69] -= amp[0];
  jamp[111] += amp[0];

  // *** DIAGRAM 351 OF 1240 ***

  // Wavefunction(s) for diagram number 351
  // (none)

  // Amplitude(s) for diagram number 351
  FFV1_0( w[86], w[15], w[1], COUPs[1], &amp[0] );
#ifdef MGONGPU_SUPPORTS_MULTICHANNEL
  if( channelId == 351 ) allNumerators[0] += cxabs2( amp[0] );
  if( channelId != 0 ) allDenominators[0] += cxabs2( amp[0] );
#endif
  jamp[69] += cxtype( 0, 1 ) * amp[0];
  jamp[111] -= cxtype( 0, 1 ) * amp[0];

  // *** DIAGRAM 352 OF 1240 ***

  // Wavefunction(s) for diagram number 352
  // (none)

  // Amplitude(s) for diagram number 352
  FFV1_0( w[99], w[18], w[4], COUPs[1], &amp[0] );
#ifdef MGONGPU_SUPPORTS_MULTICHANNEL
  if( channelId == 352 ) allNumerators[0] += cxabs2( amp[0] );
  if( channelId != 0 ) allDenominators[0] += cxabs2( amp[0] );
#endif
  jamp[95] += cxtype( 0, 1 ) * amp[0];
  jamp[119] -= cxtype( 0, 1 ) * amp[0];

  // *** DIAGRAM 353 OF 1240 ***

  // Wavefunction(s) for diagram number 353
  // (none)

  // Amplitude(s) for diagram number 353
  FFV1_0( w[99], w[2], w[19], COUPs[1], &amp[0] );
#ifdef MGONGPU_SUPPORTS_MULTICHANNEL
  if( channelId == 353 ) allNumerators[0] += cxabs2( amp[0] );
  if( channelId != 0 ) allDenominators[0] += cxabs2( amp[0] );
#endif
  jamp[65] += amp[0];
  jamp[71] -= amp[0];
  jamp[95] -= amp[0];
  jamp[119] += amp[0];

  // *** DIAGRAM 354 OF 1240 ***

  // Wavefunction(s) for diagram number 354
  // (none)

  // Amplitude(s) for diagram number 354
  VVV1_0( w[92], w[67], w[4], COUPs[0], &amp[0] );
#ifdef MGONGPU_SUPPORTS_MULTICHANNEL
  if( channelId == 354 ) allNumerators[0] += cxabs2( amp[0] );
  if( channelId != 0 ) allDenominators[0] += cxabs2( amp[0] );
#endif
  jamp[41] -= cxtype( 0, 1 ) * amp[0];
  jamp[47] += cxtype( 0, 1 ) * amp[0];
  jamp[57] += cxtype( 0, 1 ) * amp[0];
  jamp[59] -= cxtype( 0, 1 ) * amp[0];
  jamp[65] -= cxtype( 0, 1 ) * amp[0];
  jamp[71] += cxtype( 0, 1 ) * amp[0];
  jamp[93] += cxtype( 0, 1 ) * amp[0];
  jamp[117] -= cxtype( 0, 1 ) * amp[0];

  // *** DIAGRAM 355 OF 1240 ***

  // Wavefunction(s) for diagram number 355
  // (none)

  // Amplitude(s) for diagram number 355
  VVV1_0( w[92], w[1], w[19], COUPs[0], &amp[0] );
#ifdef MGONGPU_SUPPORTS_MULTICHANNEL
  if( channelId == 355 ) allNumerators[0] += cxabs2( amp[0] );
  if( channelId != 0 ) allDenominators[0] += cxabs2( amp[0] );
#endif
  jamp[33] -= cxtype( 0, 1 ) * amp[0];
  jamp[35] += cxtype( 0, 1 ) * amp[0];
  jamp[41] += cxtype( 0, 1 ) * amp[0];
  jamp[47] -= cxtype( 0, 1 ) * amp[0];
  jamp[65] += cxtype( 0, 1 ) * amp[0];
  jamp[71] -= cxtype( 0, 1 ) * amp[0];
  jamp[95] -= cxtype( 0, 1 ) * amp[0];
  jamp[119] += cxtype( 0, 1 ) * amp[0];

  // *** DIAGRAM 356 OF 1240 ***

  // Wavefunction(s) for diagram number 356
  // (none)

  // Amplitude(s) for diagram number 356
  VVVV1_0( w[1], w[4], w[29], w[92], COUPs[2], &amp[0] );
  jamp[33] -= cxtype( 0, 1 ) * amp[0];
  jamp[35] += cxtype( 0, 1 ) * amp[0];
  jamp[57] += cxtype( 0, 1 ) * amp[0];
  jamp[59] -= cxtype( 0, 1 ) * amp[0];
  jamp[93] += cxtype( 0, 1 ) * amp[0];
  jamp[95] -= cxtype( 0, 1 ) * amp[0];
  jamp[117] -= cxtype( 0, 1 ) * amp[0];
  jamp[119] += cxtype( 0, 1 ) * amp[0];
  VVVV3_0( w[1], w[4], w[29], w[92], COUPs[2], &amp[0] );
  jamp[41] -= cxtype( 0, 1 ) * amp[0];
  jamp[47] += cxtype( 0, 1 ) * amp[0];
  jamp[57] += cxtype( 0, 1 ) * amp[0];
  jamp[59] -= cxtype( 0, 1 ) * amp[0];
  jamp[65] -= cxtype( 0, 1 ) * amp[0];
  jamp[71] += cxtype( 0, 1 ) * amp[0];
  jamp[93] += cxtype( 0, 1 ) * amp[0];
  jamp[117] -= cxtype( 0, 1 ) * amp[0];
  VVVV4_0( w[1], w[4], w[29], w[92], COUPs[2], &amp[0] );
  jamp[33] += cxtype( 0, 1 ) * amp[0];
  jamp[35] -= cxtype( 0, 1 ) * amp[0];
  jamp[41] -= cxtype( 0, 1 ) * amp[0];
  jamp[47] += cxtype( 0, 1 ) * amp[0];
  jamp[65] -= cxtype( 0, 1 ) * amp[0];
  jamp[71] += cxtype( 0, 1 ) * amp[0];
  jamp[95] += cxtype( 0, 1 ) * amp[0];
  jamp[119] -= cxtype( 0, 1 ) * amp[0];

  // *** DIAGRAM 357 OF 1240 ***

  // Wavefunction(s) for diagram number 357
  // (none)

  // Amplitude(s) for diagram number 357
  FFV1_0( w[34], w[2], w[67], COUPs[1], &amp[0] );
#ifdef MGONGPU_SUPPORTS_MULTICHANNEL
  if( channelId == 357 ) allNumerators[0] += cxabs2( amp[0] );
  if( channelId != 0 ) allDenominators[0] += cxabs2( amp[0] );
#endif
  jamp[41] += amp[0];
  jamp[47] -= amp[0];
  jamp[93] -= amp[0];
  jamp[117] += amp[0];

  // *** DIAGRAM 358 OF 1240 ***

  // Wavefunction(s) for diagram number 358
  // (none)

  // Amplitude(s) for diagram number 358
  FFV1_0( w[34], w[18], w[1], COUPs[1], &amp[0] );
#ifdef MGONGPU_SUPPORTS_MULTICHANNEL
  if( channelId == 358 ) allNumerators[0] += cxabs2( amp[0] );
  if( channelId != 0 ) allDenominators[0] += cxabs2( amp[0] );
#endif
  jamp[93] += cxtype( 0, 1 ) * amp[0];
  jamp[117] -= cxtype( 0, 1 ) * amp[0];

  // *** DIAGRAM 359 OF 1240 ***

  // Wavefunction(s) for diagram number 359
  // (none)

  // Amplitude(s) for diagram number 359
  VVV1_0( w[73], w[6], w[92], COUPs[0], &amp[0] );
  jamp[33] -= cxtype( 0, 1 ) * amp[0];
  jamp[39] += cxtype( 0, 1 ) * amp[0];
  jamp[63] += cxtype( 0, 1 ) * amp[0];
  jamp[87] -= cxtype( 0, 1 ) * amp[0];
  jamp[105] += cxtype( 0, 1 ) * amp[0];
  jamp[107] -= cxtype( 0, 1 ) * amp[0];
  jamp[113] -= cxtype( 0, 1 ) * amp[0];
  jamp[119] += cxtype( 0, 1 ) * amp[0];
  VVV1_0( w[79], w[6], w[92], COUPs[0], &amp[0] );
  jamp[39] += cxtype( 0, 1 ) * amp[0];
  jamp[57] -= cxtype( 0, 1 ) * amp[0];
  jamp[63] += cxtype( 0, 1 ) * amp[0];
  jamp[81] -= cxtype( 0, 1 ) * amp[0];
  jamp[107] -= cxtype( 0, 1 ) * amp[0];
  jamp[111] += cxtype( 0, 1 ) * amp[0];
  jamp[113] -= cxtype( 0, 1 ) * amp[0];
  jamp[117] += cxtype( 0, 1 ) * amp[0];
  VVV1_0( w[80], w[6], w[92], COUPs[0], &amp[0] );
  jamp[33] += cxtype( 0, 1 ) * amp[0];
  jamp[57] -= cxtype( 0, 1 ) * amp[0];
  jamp[81] -= cxtype( 0, 1 ) * amp[0];
  jamp[87] += cxtype( 0, 1 ) * amp[0];
  jamp[105] -= cxtype( 0, 1 ) * amp[0];
  jamp[111] += cxtype( 0, 1 ) * amp[0];
  jamp[117] += cxtype( 0, 1 ) * amp[0];
  jamp[119] -= cxtype( 0, 1 ) * amp[0];

  // *** DIAGRAM 360 OF 1240 ***

  // Wavefunction(s) for diagram number 360
  // (none)

  // Amplitude(s) for diagram number 360
  FFV1_0( w[88], w[2], w[73], COUPs[1], &amp[0] );
  jamp[33] += amp[0];
  jamp[39] -= amp[0];
  jamp[63] -= amp[0];
  jamp[87] += amp[0];
  FFV1_0( w[88], w[2], w[79], COUPs[1], &amp[0] );
  jamp[39] -= amp[0];
  jamp[57] += amp[0];
  jamp[63] -= amp[0];
  jamp[81] += amp[0];
  FFV1_0( w[88], w[2], w[80], COUPs[1], &amp[0] );
  jamp[33] -= amp[0];
  jamp[57] += amp[0];
  jamp[81] += amp[0];
  jamp[87] -= amp[0];

  // *** DIAGRAM 361 OF 1240 ***

  // Wavefunction(s) for diagram number 361
  // (none)

  // Amplitude(s) for diagram number 361
  FFV1_0( w[62], w[47], w[73], COUPs[1], &amp[0] );
  jamp[105] += amp[0];
  jamp[107] -= amp[0];
  jamp[113] -= amp[0];
  jamp[119] += amp[0];
  FFV1_0( w[62], w[47], w[79], COUPs[1], &amp[0] );
  jamp[107] -= amp[0];
  jamp[111] += amp[0];
  jamp[113] -= amp[0];
  jamp[117] += amp[0];
  FFV1_0( w[62], w[47], w[80], COUPs[1], &amp[0] );
  jamp[105] -= amp[0];
  jamp[111] += amp[0];
  jamp[117] += amp[0];
  jamp[119] -= amp[0];

  // *** DIAGRAM 362 OF 1240 ***

  // Wavefunction(s) for diagram number 362
  // (none)

  // Amplitude(s) for diagram number 362
  VVV1_0( w[57], w[5], w[92], COUPs[0], &amp[0] );
  jamp[35] -= cxtype( 0, 1 ) * amp[0];
  jamp[45] += cxtype( 0, 1 ) * amp[0];
  jamp[69] += cxtype( 0, 1 ) * amp[0];
  jamp[81] += cxtype( 0, 1 ) * amp[0];
  jamp[83] -= cxtype( 0, 1 ) * amp[0];
  jamp[89] -= cxtype( 0, 1 ) * amp[0];
  jamp[95] += cxtype( 0, 1 ) * amp[0];
  jamp[111] -= cxtype( 0, 1 ) * amp[0];
  VVV1_0( w[81], w[5], w[92], COUPs[0], &amp[0] );
  jamp[45] += cxtype( 0, 1 ) * amp[0];
  jamp[59] -= cxtype( 0, 1 ) * amp[0];
  jamp[69] += cxtype( 0, 1 ) * amp[0];
  jamp[83] -= cxtype( 0, 1 ) * amp[0];
  jamp[87] += cxtype( 0, 1 ) * amp[0];
  jamp[89] -= cxtype( 0, 1 ) * amp[0];
  jamp[93] += cxtype( 0, 1 ) * amp[0];
  jamp[105] -= cxtype( 0, 1 ) * amp[0];
  VVV1_0( w[82], w[5], w[92], COUPs[0], &amp[0] );
  jamp[35] += cxtype( 0, 1 ) * amp[0];
  jamp[59] -= cxtype( 0, 1 ) * amp[0];
  jamp[81] -= cxtype( 0, 1 ) * amp[0];
  jamp[87] += cxtype( 0, 1 ) * amp[0];
  jamp[93] += cxtype( 0, 1 ) * amp[0];
  jamp[95] -= cxtype( 0, 1 ) * amp[0];
  jamp[105] -= cxtype( 0, 1 ) * amp[0];
  jamp[111] += cxtype( 0, 1 ) * amp[0];

  // *** DIAGRAM 363 OF 1240 ***

  // Wavefunction(s) for diagram number 363
  // (none)

  // Amplitude(s) for diagram number 363
  FFV1_0( w[86], w[2], w[57], COUPs[1], &amp[0] );
  jamp[35] += amp[0];
  jamp[45] -= amp[0];
  jamp[69] -= amp[0];
  jamp[111] += amp[0];
  FFV1_0( w[86], w[2], w[81], COUPs[1], &amp[0] );
  jamp[45] -= amp[0];
  jamp[59] += amp[0];
  jamp[69] -= amp[0];
  jamp[105] += amp[0];
  FFV1_0( w[86], w[2], w[82], COUPs[1], &amp[0] );
  jamp[35] -= amp[0];
  jamp[59] += amp[0];
  jamp[105] += amp[0];
  jamp[111] -= amp[0];

  // *** DIAGRAM 364 OF 1240 ***

  // Wavefunction(s) for diagram number 364
  // (none)

  // Amplitude(s) for diagram number 364
  FFV1_0( w[62], w[39], w[57], COUPs[1], &amp[0] );
  jamp[81] += amp[0];
  jamp[83] -= amp[0];
  jamp[89] -= amp[0];
  jamp[95] += amp[0];
  FFV1_0( w[62], w[39], w[81], COUPs[1], &amp[0] );
  jamp[83] -= amp[0];
  jamp[87] += amp[0];
  jamp[89] -= amp[0];
  jamp[93] += amp[0];
  FFV1_0( w[62], w[39], w[82], COUPs[1], &amp[0] );
  jamp[81] -= amp[0];
  jamp[87] += amp[0];
  jamp[93] += amp[0];
  jamp[95] -= amp[0];

  // *** DIAGRAM 365 OF 1240 ***

  // Wavefunction(s) for diagram number 365
  // (none)

  // Amplitude(s) for diagram number 365
  VVV1_0( w[55], w[4], w[92], COUPs[0], &amp[0] );
  jamp[41] -= cxtype( 0, 1 ) * amp[0];
  jamp[47] += cxtype( 0, 1 ) * amp[0];
  jamp[57] += cxtype( 0, 1 ) * amp[0];
  jamp[59] -= cxtype( 0, 1 ) * amp[0];
  jamp[65] -= cxtype( 0, 1 ) * amp[0];
  jamp[71] += cxtype( 0, 1 ) * amp[0];
  jamp[93] += cxtype( 0, 1 ) * amp[0];
  jamp[117] -= cxtype( 0, 1 ) * amp[0];
  VVV1_0( w[83], w[4], w[92], COUPs[0], &amp[0] );
  jamp[47] += cxtype( 0, 1 ) * amp[0];
  jamp[59] -= cxtype( 0, 1 ) * amp[0];
  jamp[63] += cxtype( 0, 1 ) * amp[0];
  jamp[65] -= cxtype( 0, 1 ) * amp[0];
  jamp[69] += cxtype( 0, 1 ) * amp[0];
  jamp[83] -= cxtype( 0, 1 ) * amp[0];
  jamp[93] += cxtype( 0, 1 ) * amp[0];
  jamp[107] -= cxtype( 0, 1 ) * amp[0];
  VVV1_0( w[84], w[4], w[92], COUPs[0], &amp[0] );
  jamp[41] += cxtype( 0, 1 ) * amp[0];
  jamp[57] -= cxtype( 0, 1 ) * amp[0];
  jamp[63] += cxtype( 0, 1 ) * amp[0];
  jamp[69] += cxtype( 0, 1 ) * amp[0];
  jamp[71] -= cxtype( 0, 1 ) * amp[0];
  jamp[83] -= cxtype( 0, 1 ) * amp[0];
  jamp[107] -= cxtype( 0, 1 ) * amp[0];
  jamp[117] += cxtype( 0, 1 ) * amp[0];

  // *** DIAGRAM 366 OF 1240 ***

  // Wavefunction(s) for diagram number 366
  // (none)

  // Amplitude(s) for diagram number 366
  FFV1_0( w[34], w[2], w[55], COUPs[1], &amp[0] );
  jamp[41] += amp[0];
  jamp[47] -= amp[0];
  jamp[93] -= amp[0];
  jamp[117] += amp[0];
  FFV1_0( w[34], w[2], w[83], COUPs[1], &amp[0] );
  jamp[47] -= amp[0];
  jamp[83] += amp[0];
  jamp[93] -= amp[0];
  jamp[107] += amp[0];
  FFV1_0( w[34], w[2], w[84], COUPs[1], &amp[0] );
  jamp[41] -= amp[0];
  jamp[83] += amp[0];
  jamp[107] += amp[0];
  jamp[117] -= amp[0];

  // *** DIAGRAM 367 OF 1240 ***

  // Wavefunction(s) for diagram number 367
  // (none)

  // Amplitude(s) for diagram number 367
  FFV1_0( w[62], w[33], w[55], COUPs[1], &amp[0] );
  jamp[57] += amp[0];
  jamp[59] -= amp[0];
  jamp[65] -= amp[0];
  jamp[71] += amp[0];
  FFV1_0( w[62], w[33], w[83], COUPs[1], &amp[0] );
  jamp[59] -= amp[0];
  jamp[63] += amp[0];
  jamp[65] -= amp[0];
  jamp[69] += amp[0];
  FFV1_0( w[62], w[33], w[84], COUPs[1], &amp[0] );
  jamp[57] -= amp[0];
  jamp[63] += amp[0];
  jamp[69] += amp[0];
  jamp[71] -= amp[0];

  // *** DIAGRAM 368 OF 1240 ***

  // Wavefunction(s) for diagram number 368
  // (none)

  // Amplitude(s) for diagram number 368
  FFV1_0( w[99], w[2], w[30], COUPs[1], &amp[0] );
  jamp[65] += amp[0];
  jamp[71] -= amp[0];
  jamp[95] -= amp[0];
  jamp[119] += amp[0];
  FFV1_0( w[99], w[2], w[31], COUPs[1], &amp[0] );
  jamp[71] -= amp[0];
  jamp[89] += amp[0];
  jamp[95] -= amp[0];
  jamp[113] += amp[0];
  FFV1_0( w[99], w[2], w[32], COUPs[1], &amp[0] );
  jamp[65] -= amp[0];
  jamp[89] += amp[0];
  jamp[113] += amp[0];
  jamp[119] -= amp[0];

  // *** DIAGRAM 369 OF 1240 ***

  // Wavefunction(s) for diagram number 369
  // (none)

  // Amplitude(s) for diagram number 369
  VVV1_0( w[1], w[30], w[92], COUPs[0], &amp[0] );
  jamp[33] -= cxtype( 0, 1 ) * amp[0];
  jamp[35] += cxtype( 0, 1 ) * amp[0];
  jamp[41] += cxtype( 0, 1 ) * amp[0];
  jamp[47] -= cxtype( 0, 1 ) * amp[0];
  jamp[65] += cxtype( 0, 1 ) * amp[0];
  jamp[71] -= cxtype( 0, 1 ) * amp[0];
  jamp[95] -= cxtype( 0, 1 ) * amp[0];
  jamp[119] += cxtype( 0, 1 ) * amp[0];
  VVV1_0( w[1], w[31], w[92], COUPs[0], &amp[0] );
  jamp[35] += cxtype( 0, 1 ) * amp[0];
  jamp[39] -= cxtype( 0, 1 ) * amp[0];
  jamp[41] += cxtype( 0, 1 ) * amp[0];
  jamp[45] -= cxtype( 0, 1 ) * amp[0];
  jamp[71] -= cxtype( 0, 1 ) * amp[0];
  jamp[89] += cxtype( 0, 1 ) * amp[0];
  jamp[95] -= cxtype( 0, 1 ) * amp[0];
  jamp[113] += cxtype( 0, 1 ) * amp[0];
  VVV1_0( w[1], w[32], w[92], COUPs[0], &amp[0] );
  jamp[33] += cxtype( 0, 1 ) * amp[0];
  jamp[39] -= cxtype( 0, 1 ) * amp[0];
  jamp[45] -= cxtype( 0, 1 ) * amp[0];
  jamp[47] += cxtype( 0, 1 ) * amp[0];
  jamp[65] -= cxtype( 0, 1 ) * amp[0];
  jamp[89] += cxtype( 0, 1 ) * amp[0];
  jamp[113] += cxtype( 0, 1 ) * amp[0];
  jamp[119] -= cxtype( 0, 1 ) * amp[0];

  // *** DIAGRAM 370 OF 1240 ***

  // Wavefunction(s) for diagram number 370
  VVV1P0_1( w[0], w[4], COUPs[0], 0., 0., w[92] );
  FFV1_2( w[3], w[92], COUPs[1], cIPD[0], cIPD[1], w[99] );

  // Amplitude(s) for diagram number 370
  FFV1_0( w[99], w[9], w[6], COUPs[1], &amp[0] );
#ifdef MGONGPU_SUPPORTS_MULTICHANNEL
  if( channelId == 370 ) allNumerators[0] += cxabs2( amp[0] );
  if( channelId != 0 ) allDenominators[0] += cxabs2( amp[0] );
#endif
  jamp[40] += cxtype( 0, 1 ) * amp[0];
  jamp[41] -= cxtype( 0, 1 ) * amp[0];

  // *** DIAGRAM 371 OF 1240 ***

  // Wavefunction(s) for diagram number 371
  // (none)

  // Amplitude(s) for diagram number 371
  FFV1_0( w[99], w[85], w[5], COUPs[1], &amp[0] );
#ifdef MGONGPU_SUPPORTS_MULTICHANNEL
  if( channelId == 371 ) allNumerators[0] += cxabs2( amp[0] );
  if( channelId != 0 ) allDenominators[0] += cxabs2( amp[0] );
#endif
  jamp[46] += cxtype( 0, 1 ) * amp[0];
  jamp[47] -= cxtype( 0, 1 ) * amp[0];

  // *** DIAGRAM 372 OF 1240 ***

  // Wavefunction(s) for diagram number 372
  VVV1P0_1( w[92], w[5], COUPs[0], 0., 0., w[62] );
  FFV1P0_3( w[3], w[77], COUPs[1], 0., 0., w[34] );

  // Amplitude(s) for diagram number 372
  VVV1_0( w[62], w[34], w[6], COUPs[0], &amp[0] );
#ifdef MGONGPU_SUPPORTS_MULTICHANNEL
  if( channelId == 372 ) allNumerators[0] += cxabs2( amp[0] );
  if( channelId != 0 ) allDenominators[0] += cxabs2( amp[0] );
#endif
  jamp[24] += cxtype( 0, 1 ) * amp[0];
  jamp[30] -= cxtype( 0, 1 ) * amp[0];
  jamp[36] -= cxtype( 0, 1 ) * amp[0];
  jamp[38] += cxtype( 0, 1 ) * amp[0];
  jamp[42] -= cxtype( 0, 1 ) * amp[0];
  jamp[44] += cxtype( 0, 1 ) * amp[0];
  jamp[46] += cxtype( 0, 1 ) * amp[0];
  jamp[47] -= cxtype( 0, 1 ) * amp[0];

  // *** DIAGRAM 373 OF 1240 ***

  // Wavefunction(s) for diagram number 373
  // (none)

  // Amplitude(s) for diagram number 373
  FFV1_0( w[3], w[85], w[62], COUPs[1], &amp[0] );
#ifdef MGONGPU_SUPPORTS_MULTICHANNEL
  if( channelId == 373 ) allNumerators[0] += cxabs2( amp[0] );
  if( channelId != 0 ) allDenominators[0] += cxabs2( amp[0] );
#endif
  jamp[42] += amp[0];
  jamp[44] -= amp[0];
  jamp[46] -= amp[0];
  jamp[47] += amp[0];

  // *** DIAGRAM 374 OF 1240 ***

  // Wavefunction(s) for diagram number 374
  VVV1P0_1( w[92], w[6], COUPs[0], 0., 0., w[86] );

  // Amplitude(s) for diagram number 374
  VVV1_0( w[86], w[34], w[5], COUPs[0], &amp[0] );
#ifdef MGONGPU_SUPPORTS_MULTICHANNEL
  if( channelId == 374 ) allNumerators[0] += cxabs2( amp[0] );
  if( channelId != 0 ) allDenominators[0] += cxabs2( amp[0] );
#endif
  jamp[25] += cxtype( 0, 1 ) * amp[0];
  jamp[31] -= cxtype( 0, 1 ) * amp[0];
  jamp[36] -= cxtype( 0, 1 ) * amp[0];
  jamp[38] += cxtype( 0, 1 ) * amp[0];
  jamp[40] += cxtype( 0, 1 ) * amp[0];
  jamp[41] -= cxtype( 0, 1 ) * amp[0];
  jamp[42] -= cxtype( 0, 1 ) * amp[0];
  jamp[44] += cxtype( 0, 1 ) * amp[0];

  // *** DIAGRAM 375 OF 1240 ***

  // Wavefunction(s) for diagram number 375
  // (none)

  // Amplitude(s) for diagram number 375
  FFV1_0( w[3], w[9], w[86], COUPs[1], &amp[0] );
#ifdef MGONGPU_SUPPORTS_MULTICHANNEL
  if( channelId == 375 ) allNumerators[0] += cxabs2( amp[0] );
  if( channelId != 0 ) allDenominators[0] += cxabs2( amp[0] );
#endif
  jamp[36] += amp[0];
  jamp[38] -= amp[0];
  jamp[40] -= amp[0];
  jamp[41] += amp[0];

  // *** DIAGRAM 376 OF 1240 ***

  // Wavefunction(s) for diagram number 376
  VVVV1P0_1( w[92], w[5], w[6], COUPs[2], 0., 0., w[88] );
  VVVV3P0_1( w[92], w[5], w[6], COUPs[2], 0., 0., w[90] );
  VVVV4P0_1( w[92], w[5], w[6], COUPs[2], 0., 0., w[96] );

  // Amplitude(s) for diagram number 376
  FFV1_0( w[3], w[77], w[88], COUPs[1], &amp[0] );
  jamp[24] -= cxtype( 0, 1 ) * amp[0];
  jamp[25] += cxtype( 0, 1 ) * amp[0];
  jamp[30] += cxtype( 0, 1 ) * amp[0];
  jamp[31] -= cxtype( 0, 1 ) * amp[0];
  jamp[40] += cxtype( 0, 1 ) * amp[0];
  jamp[41] -= cxtype( 0, 1 ) * amp[0];
  jamp[46] -= cxtype( 0, 1 ) * amp[0];
  jamp[47] += cxtype( 0, 1 ) * amp[0];
  FFV1_0( w[3], w[77], w[90], COUPs[1], &amp[0] );
  jamp[25] += cxtype( 0, 1 ) * amp[0];
  jamp[31] -= cxtype( 0, 1 ) * amp[0];
  jamp[36] -= cxtype( 0, 1 ) * amp[0];
  jamp[38] += cxtype( 0, 1 ) * amp[0];
  jamp[40] += cxtype( 0, 1 ) * amp[0];
  jamp[41] -= cxtype( 0, 1 ) * amp[0];
  jamp[42] -= cxtype( 0, 1 ) * amp[0];
  jamp[44] += cxtype( 0, 1 ) * amp[0];
  FFV1_0( w[3], w[77], w[96], COUPs[1], &amp[0] );
  jamp[24] += cxtype( 0, 1 ) * amp[0];
  jamp[30] -= cxtype( 0, 1 ) * amp[0];
  jamp[36] -= cxtype( 0, 1 ) * amp[0];
  jamp[38] += cxtype( 0, 1 ) * amp[0];
  jamp[42] -= cxtype( 0, 1 ) * amp[0];
  jamp[44] += cxtype( 0, 1 ) * amp[0];
  jamp[46] += cxtype( 0, 1 ) * amp[0];
  jamp[47] -= cxtype( 0, 1 ) * amp[0];

  // *** DIAGRAM 377 OF 1240 ***

  // Wavefunction(s) for diagram number 377
  FFV1_1( w[77], w[92], COUPs[1], cIPD[0], cIPD[1], w[95] );

  // Amplitude(s) for diagram number 377
  FFV1_0( w[38], w[95], w[6], COUPs[1], &amp[0] );
#ifdef MGONGPU_SUPPORTS_MULTICHANNEL
  if( channelId == 377 ) allNumerators[0] += cxabs2( amp[0] );
  if( channelId != 0 ) allDenominators[0] += cxabs2( amp[0] );
#endif
  jamp[25] += cxtype( 0, 1 ) * amp[0];
  jamp[31] -= cxtype( 0, 1 ) * amp[0];

  // *** DIAGRAM 378 OF 1240 ***

  // Wavefunction(s) for diagram number 378
  FFV1_2( w[38], w[92], COUPs[1], cIPD[0], cIPD[1], w[98] );

  // Amplitude(s) for diagram number 378
  FFV1_0( w[98], w[77], w[6], COUPs[1], &amp[0] );
#ifdef MGONGPU_SUPPORTS_MULTICHANNEL
  if( channelId == 378 ) allNumerators[0] += cxabs2( amp[0] );
  if( channelId != 0 ) allDenominators[0] += cxabs2( amp[0] );
#endif
  jamp[42] += cxtype( 0, 1 ) * amp[0];
  jamp[44] -= cxtype( 0, 1 ) * amp[0];

  // *** DIAGRAM 379 OF 1240 ***

  // Wavefunction(s) for diagram number 379
  // (none)

  // Amplitude(s) for diagram number 379
  FFV1_0( w[38], w[77], w[86], COUPs[1], &amp[0] );
#ifdef MGONGPU_SUPPORTS_MULTICHANNEL
  if( channelId == 379 ) allNumerators[0] += cxabs2( amp[0] );
  if( channelId != 0 ) allDenominators[0] += cxabs2( amp[0] );
#endif
  jamp[25] += amp[0];
  jamp[31] -= amp[0];
  jamp[42] -= amp[0];
  jamp[44] += amp[0];

  // *** DIAGRAM 380 OF 1240 ***

  // Wavefunction(s) for diagram number 380
  // (none)

  // Amplitude(s) for diagram number 380
  FFV1_0( w[41], w[95], w[5], COUPs[1], &amp[0] );
#ifdef MGONGPU_SUPPORTS_MULTICHANNEL
  if( channelId == 380 ) allNumerators[0] += cxabs2( amp[0] );
  if( channelId != 0 ) allDenominators[0] += cxabs2( amp[0] );
#endif
  jamp[24] += cxtype( 0, 1 ) * amp[0];
  jamp[30] -= cxtype( 0, 1 ) * amp[0];

  // *** DIAGRAM 381 OF 1240 ***

  // Wavefunction(s) for diagram number 381
  FFV1_2( w[41], w[92], COUPs[1], cIPD[0], cIPD[1], w[101] );

  // Amplitude(s) for diagram number 381
  FFV1_0( w[101], w[77], w[5], COUPs[1], &amp[0] );
#ifdef MGONGPU_SUPPORTS_MULTICHANNEL
  if( channelId == 381 ) allNumerators[0] += cxabs2( amp[0] );
  if( channelId != 0 ) allDenominators[0] += cxabs2( amp[0] );
#endif
  jamp[36] += cxtype( 0, 1 ) * amp[0];
  jamp[38] -= cxtype( 0, 1 ) * amp[0];

  // *** DIAGRAM 382 OF 1240 ***

  // Wavefunction(s) for diagram number 382
  // (none)

  // Amplitude(s) for diagram number 382
  FFV1_0( w[41], w[77], w[62], COUPs[1], &amp[0] );
#ifdef MGONGPU_SUPPORTS_MULTICHANNEL
  if( channelId == 382 ) allNumerators[0] += cxabs2( amp[0] );
  if( channelId != 0 ) allDenominators[0] += cxabs2( amp[0] );
#endif
  jamp[24] += amp[0];
  jamp[30] -= amp[0];
  jamp[36] -= amp[0];
  jamp[38] += amp[0];

  // *** DIAGRAM 383 OF 1240 ***

  // Wavefunction(s) for diagram number 383
  // (none)

  // Amplitude(s) for diagram number 383
  FFV1_0( w[3], w[95], w[29], COUPs[1], &amp[0] );
#ifdef MGONGPU_SUPPORTS_MULTICHANNEL
  if( channelId == 383 ) allNumerators[0] += cxabs2( amp[0] );
  if( channelId != 0 ) allDenominators[0] += cxabs2( amp[0] );
#endif
  jamp[24] += amp[0];
  jamp[25] -= amp[0];
  jamp[30] -= amp[0];
  jamp[31] += amp[0];

  // *** DIAGRAM 384 OF 1240 ***

  // Wavefunction(s) for diagram number 384
  // (none)

  // Amplitude(s) for diagram number 384
  FFV1_0( w[99], w[77], w[29], COUPs[1], &amp[0] );
#ifdef MGONGPU_SUPPORTS_MULTICHANNEL
  if( channelId == 384 ) allNumerators[0] += cxabs2( amp[0] );
  if( channelId != 0 ) allDenominators[0] += cxabs2( amp[0] );
#endif
  jamp[40] += amp[0];
  jamp[41] -= amp[0];
  jamp[46] -= amp[0];
  jamp[47] += amp[0];

  // *** DIAGRAM 385 OF 1240 ***

  // Wavefunction(s) for diagram number 385
  VVV1P0_1( w[92], w[29], COUPs[0], 0., 0., w[95] );

  // Amplitude(s) for diagram number 385
  FFV1_0( w[3], w[77], w[95], COUPs[1], &amp[0] );
#ifdef MGONGPU_SUPPORTS_MULTICHANNEL
  if( channelId == 385 ) allNumerators[0] += cxabs2( amp[0] );
  if( channelId != 0 ) allDenominators[0] += cxabs2( amp[0] );
#endif
  jamp[24] -= cxtype( 0, 1 ) * amp[0];
  jamp[25] += cxtype( 0, 1 ) * amp[0];
  jamp[30] += cxtype( 0, 1 ) * amp[0];
  jamp[31] -= cxtype( 0, 1 ) * amp[0];
  jamp[40] += cxtype( 0, 1 ) * amp[0];
  jamp[41] -= cxtype( 0, 1 ) * amp[0];
  jamp[46] -= cxtype( 0, 1 ) * amp[0];
  jamp[47] += cxtype( 0, 1 ) * amp[0];

  // *** DIAGRAM 386 OF 1240 ***

  // Wavefunction(s) for diagram number 386
  FFV1_1( w[2], w[92], COUPs[1], cIPD[0], cIPD[1], w[102] );

  // Amplitude(s) for diagram number 386
  FFV1_0( w[22], w[102], w[6], COUPs[1], &amp[0] );
#ifdef MGONGPU_SUPPORTS_MULTICHANNEL
  if( channelId == 386 ) allNumerators[0] += cxabs2( amp[0] );
  if( channelId != 0 ) allDenominators[0] += cxabs2( amp[0] );
#endif
  jamp[11] += cxtype( 0, 1 ) * amp[0];
  jamp[53] -= cxtype( 0, 1 ) * amp[0];

  // *** DIAGRAM 387 OF 1240 ***

  // Wavefunction(s) for diagram number 387
  // (none)

  // Amplitude(s) for diagram number 387
  FFV1_0( w[21], w[102], w[5], COUPs[1], &amp[0] );
#ifdef MGONGPU_SUPPORTS_MULTICHANNEL
  if( channelId == 387 ) allNumerators[0] += cxabs2( amp[0] );
  if( channelId != 0 ) allDenominators[0] += cxabs2( amp[0] );
#endif
  jamp[9] += cxtype( 0, 1 ) * amp[0];
  jamp[51] -= cxtype( 0, 1 ) * amp[0];

  // *** DIAGRAM 388 OF 1240 ***

  // Wavefunction(s) for diagram number 388
  FFV1P0_3( w[52], w[2], COUPs[1], 0., 0., w[103] );

  // Amplitude(s) for diagram number 388
  VVV1_0( w[62], w[103], w[6], COUPs[0], &amp[0] );
#ifdef MGONGPU_SUPPORTS_MULTICHANNEL
  if( channelId == 388 ) allNumerators[0] += cxabs2( amp[0] );
  if( channelId != 0 ) allDenominators[0] += cxabs2( amp[0] );
#endif
  jamp[9] += cxtype( 0, 1 ) * amp[0];
  jamp[51] -= cxtype( 0, 1 ) * amp[0];
  jamp[75] -= cxtype( 0, 1 ) * amp[0];
  jamp[85] += cxtype( 0, 1 ) * amp[0];
  jamp[99] -= cxtype( 0, 1 ) * amp[0];
  jamp[109] += cxtype( 0, 1 ) * amp[0];
  jamp[115] += cxtype( 0, 1 ) * amp[0];
  jamp[118] -= cxtype( 0, 1 ) * amp[0];

  // *** DIAGRAM 389 OF 1240 ***

  // Wavefunction(s) for diagram number 389
  // (none)

  // Amplitude(s) for diagram number 389
  FFV1_0( w[21], w[2], w[62], COUPs[1], &amp[0] );
#ifdef MGONGPU_SUPPORTS_MULTICHANNEL
  if( channelId == 389 ) allNumerators[0] += cxabs2( amp[0] );
  if( channelId != 0 ) allDenominators[0] += cxabs2( amp[0] );
#endif
  jamp[9] += amp[0];
  jamp[51] -= amp[0];
  jamp[75] -= amp[0];
  jamp[85] += amp[0];

  // *** DIAGRAM 390 OF 1240 ***

  // Wavefunction(s) for diagram number 390
  // (none)

  // Amplitude(s) for diagram number 390
  VVV1_0( w[86], w[103], w[5], COUPs[0], &amp[0] );
#ifdef MGONGPU_SUPPORTS_MULTICHANNEL
  if( channelId == 390 ) allNumerators[0] += cxabs2( amp[0] );
  if( channelId != 0 ) allDenominators[0] += cxabs2( amp[0] );
#endif
  jamp[11] += cxtype( 0, 1 ) * amp[0];
  jamp[53] -= cxtype( 0, 1 ) * amp[0];
  jamp[75] -= cxtype( 0, 1 ) * amp[0];
  jamp[85] += cxtype( 0, 1 ) * amp[0];
  jamp[91] += cxtype( 0, 1 ) * amp[0];
  jamp[94] -= cxtype( 0, 1 ) * amp[0];
  jamp[99] -= cxtype( 0, 1 ) * amp[0];
  jamp[109] += cxtype( 0, 1 ) * amp[0];

  // *** DIAGRAM 391 OF 1240 ***

  // Wavefunction(s) for diagram number 391
  // (none)

  // Amplitude(s) for diagram number 391
  FFV1_0( w[22], w[2], w[86], COUPs[1], &amp[0] );
#ifdef MGONGPU_SUPPORTS_MULTICHANNEL
  if( channelId == 391 ) allNumerators[0] += cxabs2( amp[0] );
  if( channelId != 0 ) allDenominators[0] += cxabs2( amp[0] );
#endif
  jamp[11] += amp[0];
  jamp[53] -= amp[0];
  jamp[99] -= amp[0];
  jamp[109] += amp[0];

  // *** DIAGRAM 392 OF 1240 ***

  // Wavefunction(s) for diagram number 392
  // (none)

  // Amplitude(s) for diagram number 392
  FFV1_0( w[52], w[2], w[88], COUPs[1], &amp[0] );
  jamp[9] -= cxtype( 0, 1 ) * amp[0];
  jamp[11] += cxtype( 0, 1 ) * amp[0];
  jamp[51] += cxtype( 0, 1 ) * amp[0];
  jamp[53] -= cxtype( 0, 1 ) * amp[0];
  jamp[91] += cxtype( 0, 1 ) * amp[0];
  jamp[94] -= cxtype( 0, 1 ) * amp[0];
  jamp[115] -= cxtype( 0, 1 ) * amp[0];
  jamp[118] += cxtype( 0, 1 ) * amp[0];
  FFV1_0( w[52], w[2], w[90], COUPs[1], &amp[0] );
  jamp[11] += cxtype( 0, 1 ) * amp[0];
  jamp[53] -= cxtype( 0, 1 ) * amp[0];
  jamp[75] -= cxtype( 0, 1 ) * amp[0];
  jamp[85] += cxtype( 0, 1 ) * amp[0];
  jamp[91] += cxtype( 0, 1 ) * amp[0];
  jamp[94] -= cxtype( 0, 1 ) * amp[0];
  jamp[99] -= cxtype( 0, 1 ) * amp[0];
  jamp[109] += cxtype( 0, 1 ) * amp[0];
  FFV1_0( w[52], w[2], w[96], COUPs[1], &amp[0] );
  jamp[9] += cxtype( 0, 1 ) * amp[0];
  jamp[51] -= cxtype( 0, 1 ) * amp[0];
  jamp[75] -= cxtype( 0, 1 ) * amp[0];
  jamp[85] += cxtype( 0, 1 ) * amp[0];
  jamp[99] -= cxtype( 0, 1 ) * amp[0];
  jamp[109] += cxtype( 0, 1 ) * amp[0];
  jamp[115] += cxtype( 0, 1 ) * amp[0];
  jamp[118] -= cxtype( 0, 1 ) * amp[0];

  // *** DIAGRAM 393 OF 1240 ***

  // Wavefunction(s) for diagram number 393
  FFV1_2( w[52], w[92], COUPs[1], cIPD[0], cIPD[1], w[104] );

  // Amplitude(s) for diagram number 393
  FFV1_0( w[104], w[39], w[6], COUPs[1], &amp[0] );
#ifdef MGONGPU_SUPPORTS_MULTICHANNEL
  if( channelId == 393 ) allNumerators[0] += cxabs2( amp[0] );
  if( channelId != 0 ) allDenominators[0] += cxabs2( amp[0] );
#endif
  jamp[91] += cxtype( 0, 1 ) * amp[0];
  jamp[94] -= cxtype( 0, 1 ) * amp[0];

  // *** DIAGRAM 394 OF 1240 ***

  // Wavefunction(s) for diagram number 394
  FFV1_1( w[39], w[92], COUPs[1], cIPD[0], cIPD[1], w[105] );

  // Amplitude(s) for diagram number 394
  FFV1_0( w[52], w[105], w[6], COUPs[1], &amp[0] );
#ifdef MGONGPU_SUPPORTS_MULTICHANNEL
  if( channelId == 394 ) allNumerators[0] += cxabs2( amp[0] );
  if( channelId != 0 ) allDenominators[0] += cxabs2( amp[0] );
#endif
  jamp[75] += cxtype( 0, 1 ) * amp[0];
  jamp[85] -= cxtype( 0, 1 ) * amp[0];

  // *** DIAGRAM 395 OF 1240 ***

  // Wavefunction(s) for diagram number 395
  // (none)

  // Amplitude(s) for diagram number 395
  FFV1_0( w[52], w[39], w[86], COUPs[1], &amp[0] );
#ifdef MGONGPU_SUPPORTS_MULTICHANNEL
  if( channelId == 395 ) allNumerators[0] += cxabs2( amp[0] );
  if( channelId != 0 ) allDenominators[0] += cxabs2( amp[0] );
#endif
  jamp[75] += amp[0];
  jamp[85] -= amp[0];
  jamp[91] -= amp[0];
  jamp[94] += amp[0];

  // *** DIAGRAM 396 OF 1240 ***

  // Wavefunction(s) for diagram number 396
  // (none)

  // Amplitude(s) for diagram number 396
  FFV1_0( w[104], w[47], w[5], COUPs[1], &amp[0] );
#ifdef MGONGPU_SUPPORTS_MULTICHANNEL
  if( channelId == 396 ) allNumerators[0] += cxabs2( amp[0] );
  if( channelId != 0 ) allDenominators[0] += cxabs2( amp[0] );
#endif
  jamp[115] += cxtype( 0, 1 ) * amp[0];
  jamp[118] -= cxtype( 0, 1 ) * amp[0];

  // *** DIAGRAM 397 OF 1240 ***

  // Wavefunction(s) for diagram number 397
  FFV1_1( w[47], w[92], COUPs[1], cIPD[0], cIPD[1], w[106] );

  // Amplitude(s) for diagram number 397
  FFV1_0( w[52], w[106], w[5], COUPs[1], &amp[0] );
#ifdef MGONGPU_SUPPORTS_MULTICHANNEL
  if( channelId == 397 ) allNumerators[0] += cxabs2( amp[0] );
  if( channelId != 0 ) allDenominators[0] += cxabs2( amp[0] );
#endif
  jamp[99] += cxtype( 0, 1 ) * amp[0];
  jamp[109] -= cxtype( 0, 1 ) * amp[0];

  // *** DIAGRAM 398 OF 1240 ***

  // Wavefunction(s) for diagram number 398
  // (none)

  // Amplitude(s) for diagram number 398
  FFV1_0( w[52], w[47], w[62], COUPs[1], &amp[0] );
#ifdef MGONGPU_SUPPORTS_MULTICHANNEL
  if( channelId == 398 ) allNumerators[0] += cxabs2( amp[0] );
  if( channelId != 0 ) allDenominators[0] += cxabs2( amp[0] );
#endif
  jamp[99] += amp[0];
  jamp[109] -= amp[0];
  jamp[115] -= amp[0];
  jamp[118] += amp[0];

  // *** DIAGRAM 399 OF 1240 ***

  // Wavefunction(s) for diagram number 399
  // (none)

  // Amplitude(s) for diagram number 399
  FFV1_0( w[104], w[2], w[29], COUPs[1], &amp[0] );
#ifdef MGONGPU_SUPPORTS_MULTICHANNEL
  if( channelId == 399 ) allNumerators[0] += cxabs2( amp[0] );
  if( channelId != 0 ) allDenominators[0] += cxabs2( amp[0] );
#endif
  jamp[91] += amp[0];
  jamp[94] -= amp[0];
  jamp[115] -= amp[0];
  jamp[118] += amp[0];

  // *** DIAGRAM 400 OF 1240 ***

  // Wavefunction(s) for diagram number 400
  // (none)

  // Amplitude(s) for diagram number 400
  FFV1_0( w[52], w[102], w[29], COUPs[1], &amp[0] );
#ifdef MGONGPU_SUPPORTS_MULTICHANNEL
  if( channelId == 400 ) allNumerators[0] += cxabs2( amp[0] );
  if( channelId != 0 ) allDenominators[0] += cxabs2( amp[0] );
#endif
  jamp[9] += amp[0];
  jamp[11] -= amp[0];
  jamp[51] -= amp[0];
  jamp[53] += amp[0];

  // *** DIAGRAM 401 OF 1240 ***

  // Wavefunction(s) for diagram number 401
  // (none)

  // Amplitude(s) for diagram number 401
  FFV1_0( w[52], w[2], w[95], COUPs[1], &amp[0] );
#ifdef MGONGPU_SUPPORTS_MULTICHANNEL
  if( channelId == 401 ) allNumerators[0] += cxabs2( amp[0] );
  if( channelId != 0 ) allDenominators[0] += cxabs2( amp[0] );
#endif
  jamp[9] -= cxtype( 0, 1 ) * amp[0];
  jamp[11] += cxtype( 0, 1 ) * amp[0];
  jamp[51] += cxtype( 0, 1 ) * amp[0];
  jamp[53] -= cxtype( 0, 1 ) * amp[0];
  jamp[91] += cxtype( 0, 1 ) * amp[0];
  jamp[94] -= cxtype( 0, 1 ) * amp[0];
  jamp[115] -= cxtype( 0, 1 ) * amp[0];
  jamp[118] += cxtype( 0, 1 ) * amp[0];

  // *** DIAGRAM 402 OF 1240 ***

  // Wavefunction(s) for diagram number 402
  // (none)

  // Amplitude(s) for diagram number 402
  FFV1_0( w[71], w[102], w[6], COUPs[1], &amp[0] );
#ifdef MGONGPU_SUPPORTS_MULTICHANNEL
  if( channelId == 402 ) allNumerators[0] += cxabs2( amp[0] );
  if( channelId != 0 ) allDenominators[0] += cxabs2( amp[0] );
#endif
  jamp[10] += amp[0];
  jamp[11] -= amp[0];
  jamp[52] -= amp[0];
  jamp[53] += amp[0];

  // *** DIAGRAM 403 OF 1240 ***

  // Wavefunction(s) for diagram number 403
  // (none)

  // Amplitude(s) for diagram number 403
  FFV1_0( w[3], w[102], w[70], COUPs[1], &amp[0] );
#ifdef MGONGPU_SUPPORTS_MULTICHANNEL
  if( channelId == 403 ) allNumerators[0] += cxabs2( amp[0] );
  if( channelId != 0 ) allDenominators[0] += cxabs2( amp[0] );
#endif
  jamp[6] -= cxtype( 0, 1 ) * amp[0];
  jamp[8] += cxtype( 0, 1 ) * amp[0];
  jamp[10] += cxtype( 0, 1 ) * amp[0];
  jamp[11] -= cxtype( 0, 1 ) * amp[0];
  jamp[48] += cxtype( 0, 1 ) * amp[0];
  jamp[50] -= cxtype( 0, 1 ) * amp[0];
  jamp[52] -= cxtype( 0, 1 ) * amp[0];
  jamp[53] += cxtype( 0, 1 ) * amp[0];

  // *** DIAGRAM 404 OF 1240 ***

  // Wavefunction(s) for diagram number 404
  // (none)

  // Amplitude(s) for diagram number 404
  FFV1_0( w[99], w[94], w[6], COUPs[1], &amp[0] );
#ifdef MGONGPU_SUPPORTS_MULTICHANNEL
  if( channelId == 404 ) allNumerators[0] += cxabs2( amp[0] );
  if( channelId != 0 ) allDenominators[0] += cxabs2( amp[0] );
#endif
  jamp[40] += amp[0];
  jamp[41] -= amp[0];
  jamp[82] -= amp[0];
  jamp[83] += amp[0];

  // *** DIAGRAM 405 OF 1240 ***

  // Wavefunction(s) for diagram number 405
  // (none)

  // Amplitude(s) for diagram number 405
  FFV1_0( w[99], w[2], w[70], COUPs[1], &amp[0] );
#ifdef MGONGPU_SUPPORTS_MULTICHANNEL
  if( channelId == 405 ) allNumerators[0] += cxabs2( amp[0] );
  if( channelId != 0 ) allDenominators[0] += cxabs2( amp[0] );
#endif
  jamp[40] -= cxtype( 0, 1 ) * amp[0];
  jamp[41] += cxtype( 0, 1 ) * amp[0];
  jamp[82] += cxtype( 0, 1 ) * amp[0];
  jamp[83] -= cxtype( 0, 1 ) * amp[0];
  jamp[106] += cxtype( 0, 1 ) * amp[0];
  jamp[107] -= cxtype( 0, 1 ) * amp[0];
  jamp[116] -= cxtype( 0, 1 ) * amp[0];
  jamp[117] += cxtype( 0, 1 ) * amp[0];

  // *** DIAGRAM 406 OF 1240 ***

  // Wavefunction(s) for diagram number 406
  // (none)

  // Amplitude(s) for diagram number 406
  FFV1_0( w[3], w[94], w[86], COUPs[1], &amp[0] );
#ifdef MGONGPU_SUPPORTS_MULTICHANNEL
  if( channelId == 406 ) allNumerators[0] += cxabs2( amp[0] );
  if( channelId != 0 ) allDenominators[0] += cxabs2( amp[0] );
#endif
  jamp[36] -= cxtype( 0, 1 ) * amp[0];
  jamp[38] += cxtype( 0, 1 ) * amp[0];
  jamp[40] += cxtype( 0, 1 ) * amp[0];
  jamp[41] -= cxtype( 0, 1 ) * amp[0];
  jamp[78] += cxtype( 0, 1 ) * amp[0];
  jamp[80] -= cxtype( 0, 1 ) * amp[0];
  jamp[82] -= cxtype( 0, 1 ) * amp[0];
  jamp[83] += cxtype( 0, 1 ) * amp[0];

  // *** DIAGRAM 407 OF 1240 ***

  // Wavefunction(s) for diagram number 407
  // (none)

  // Amplitude(s) for diagram number 407
  FFV1_0( w[71], w[2], w[86], COUPs[1], &amp[0] );
#ifdef MGONGPU_SUPPORTS_MULTICHANNEL
  if( channelId == 407 ) allNumerators[0] += cxabs2( amp[0] );
  if( channelId != 0 ) allDenominators[0] += cxabs2( amp[0] );
#endif
  jamp[10] -= cxtype( 0, 1 ) * amp[0];
  jamp[11] += cxtype( 0, 1 ) * amp[0];
  jamp[52] += cxtype( 0, 1 ) * amp[0];
  jamp[53] -= cxtype( 0, 1 ) * amp[0];
  jamp[98] += cxtype( 0, 1 ) * amp[0];
  jamp[99] -= cxtype( 0, 1 ) * amp[0];
  jamp[108] -= cxtype( 0, 1 ) * amp[0];
  jamp[109] += cxtype( 0, 1 ) * amp[0];

  // *** DIAGRAM 408 OF 1240 ***

  // Wavefunction(s) for diagram number 408
  // (none)

  // Amplitude(s) for diagram number 408
  VVVV1_0( w[92], w[66], w[8], w[6], COUPs[2], &amp[0] );
  jamp[6] += amp[0];
  jamp[8] -= amp[0];
  jamp[36] -= amp[0];
  jamp[38] += amp[0];
  jamp[48] -= amp[0];
  jamp[50] += amp[0];
  jamp[78] += amp[0];
  jamp[80] -= amp[0];
  jamp[98] -= amp[0];
  jamp[99] += amp[0];
  jamp[106] += amp[0];
  jamp[107] -= amp[0];
  jamp[108] += amp[0];
  jamp[109] -= amp[0];
  jamp[116] -= amp[0];
  jamp[117] += amp[0];
  VVVV3_0( w[92], w[66], w[8], w[6], COUPs[2], &amp[0] );
  jamp[6] += amp[0];
  jamp[8] -= amp[0];
  jamp[10] -= amp[0];
  jamp[11] += amp[0];
  jamp[40] -= amp[0];
  jamp[41] += amp[0];
  jamp[48] -= amp[0];
  jamp[50] += amp[0];
  jamp[52] += amp[0];
  jamp[53] -= amp[0];
  jamp[82] += amp[0];
  jamp[83] -= amp[0];
  jamp[106] += amp[0];
  jamp[107] -= amp[0];
  jamp[116] -= amp[0];
  jamp[117] += amp[0];
  VVVV4_0( w[92], w[66], w[8], w[6], COUPs[2], &amp[0] );
  jamp[10] -= amp[0];
  jamp[11] += amp[0];
  jamp[36] += amp[0];
  jamp[38] -= amp[0];
  jamp[40] -= amp[0];
  jamp[41] += amp[0];
  jamp[52] += amp[0];
  jamp[53] -= amp[0];
  jamp[78] -= amp[0];
  jamp[80] += amp[0];
  jamp[82] += amp[0];
  jamp[83] -= amp[0];
  jamp[98] += amp[0];
  jamp[99] -= amp[0];
  jamp[108] -= amp[0];
  jamp[109] += amp[0];

  // *** DIAGRAM 409 OF 1240 ***

  // Wavefunction(s) for diagram number 409
  VVV1P0_1( w[92], w[66], COUPs[0], 0., 0., w[104] );

  // Amplitude(s) for diagram number 409
  VVV1_0( w[8], w[6], w[104], COUPs[0], &amp[0] );
#ifdef MGONGPU_SUPPORTS_MULTICHANNEL
  if( channelId == 409 ) allNumerators[0] += cxabs2( amp[0] );
  if( channelId != 0 ) allDenominators[0] += cxabs2( amp[0] );
#endif
  jamp[6] += amp[0];
  jamp[8] -= amp[0];
  jamp[36] -= amp[0];
  jamp[38] += amp[0];
  jamp[48] -= amp[0];
  jamp[50] += amp[0];
  jamp[78] += amp[0];
  jamp[80] -= amp[0];
  jamp[98] -= amp[0];
  jamp[99] += amp[0];
  jamp[106] += amp[0];
  jamp[107] -= amp[0];
  jamp[108] += amp[0];
  jamp[109] -= amp[0];
  jamp[116] -= amp[0];
  jamp[117] += amp[0];

  // *** DIAGRAM 410 OF 1240 ***

  // Wavefunction(s) for diagram number 410
  VVV1P0_1( w[92], w[8], COUPs[0], 0., 0., w[107] );

  // Amplitude(s) for diagram number 410
  VVV1_0( w[66], w[6], w[107], COUPs[0], &amp[0] );
#ifdef MGONGPU_SUPPORTS_MULTICHANNEL
  if( channelId == 410 ) allNumerators[0] += cxabs2( amp[0] );
  if( channelId != 0 ) allDenominators[0] += cxabs2( amp[0] );
#endif
  jamp[6] += amp[0];
  jamp[8] -= amp[0];
  jamp[10] -= amp[0];
  jamp[11] += amp[0];
  jamp[40] -= amp[0];
  jamp[41] += amp[0];
  jamp[48] -= amp[0];
  jamp[50] += amp[0];
  jamp[52] += amp[0];
  jamp[53] -= amp[0];
  jamp[82] += amp[0];
  jamp[83] -= amp[0];
  jamp[106] += amp[0];
  jamp[107] -= amp[0];
  jamp[116] -= amp[0];
  jamp[117] += amp[0];

  // *** DIAGRAM 411 OF 1240 ***

  // Wavefunction(s) for diagram number 411
  // (none)

  // Amplitude(s) for diagram number 411
  VVV1_0( w[66], w[8], w[86], COUPs[0], &amp[0] );
#ifdef MGONGPU_SUPPORTS_MULTICHANNEL
  if( channelId == 411 ) allNumerators[0] += cxabs2( amp[0] );
  if( channelId != 0 ) allDenominators[0] += cxabs2( amp[0] );
#endif
  jamp[10] -= amp[0];
  jamp[11] += amp[0];
  jamp[36] += amp[0];
  jamp[38] -= amp[0];
  jamp[40] -= amp[0];
  jamp[41] += amp[0];
  jamp[52] += amp[0];
  jamp[53] -= amp[0];
  jamp[78] -= amp[0];
  jamp[80] += amp[0];
  jamp[82] += amp[0];
  jamp[83] -= amp[0];
  jamp[98] += amp[0];
  jamp[99] -= amp[0];
  jamp[108] -= amp[0];
  jamp[109] += amp[0];

  // *** DIAGRAM 412 OF 1240 ***

  // Wavefunction(s) for diagram number 412
  // (none)

  // Amplitude(s) for diagram number 412
  FFV1_0( w[3], w[47], w[104], COUPs[1], &amp[0] );
#ifdef MGONGPU_SUPPORTS_MULTICHANNEL
  if( channelId == 412 ) allNumerators[0] += cxabs2( amp[0] );
  if( channelId != 0 ) allDenominators[0] += cxabs2( amp[0] );
#endif
  jamp[98] -= cxtype( 0, 1 ) * amp[0];
  jamp[99] += cxtype( 0, 1 ) * amp[0];
  jamp[106] += cxtype( 0, 1 ) * amp[0];
  jamp[107] -= cxtype( 0, 1 ) * amp[0];
  jamp[108] += cxtype( 0, 1 ) * amp[0];
  jamp[109] -= cxtype( 0, 1 ) * amp[0];
  jamp[116] -= cxtype( 0, 1 ) * amp[0];
  jamp[117] += cxtype( 0, 1 ) * amp[0];

  // *** DIAGRAM 413 OF 1240 ***

  // Wavefunction(s) for diagram number 413
  // (none)

  // Amplitude(s) for diagram number 413
  FFV1_0( w[3], w[106], w[66], COUPs[1], &amp[0] );
#ifdef MGONGPU_SUPPORTS_MULTICHANNEL
  if( channelId == 413 ) allNumerators[0] += cxabs2( amp[0] );
  if( channelId != 0 ) allDenominators[0] += cxabs2( amp[0] );
#endif
  jamp[98] += amp[0];
  jamp[99] -= amp[0];
  jamp[108] -= amp[0];
  jamp[109] += amp[0];

  // *** DIAGRAM 414 OF 1240 ***

  // Wavefunction(s) for diagram number 414
  // (none)

  // Amplitude(s) for diagram number 414
  FFV1_0( w[99], w[47], w[66], COUPs[1], &amp[0] );
#ifdef MGONGPU_SUPPORTS_MULTICHANNEL
  if( channelId == 414 ) allNumerators[0] += cxabs2( amp[0] );
  if( channelId != 0 ) allDenominators[0] += cxabs2( amp[0] );
#endif
  jamp[106] += amp[0];
  jamp[107] -= amp[0];
  jamp[116] -= amp[0];
  jamp[117] += amp[0];

  // *** DIAGRAM 415 OF 1240 ***

  // Wavefunction(s) for diagram number 415
  // (none)

  // Amplitude(s) for diagram number 415
  FFV1_0( w[41], w[2], w[104], COUPs[1], &amp[0] );
#ifdef MGONGPU_SUPPORTS_MULTICHANNEL
  if( channelId == 415 ) allNumerators[0] += cxabs2( amp[0] );
  if( channelId != 0 ) allDenominators[0] += cxabs2( amp[0] );
#endif
  jamp[6] -= cxtype( 0, 1 ) * amp[0];
  jamp[8] += cxtype( 0, 1 ) * amp[0];
  jamp[36] += cxtype( 0, 1 ) * amp[0];
  jamp[38] -= cxtype( 0, 1 ) * amp[0];
  jamp[48] += cxtype( 0, 1 ) * amp[0];
  jamp[50] -= cxtype( 0, 1 ) * amp[0];
  jamp[78] -= cxtype( 0, 1 ) * amp[0];
  jamp[80] += cxtype( 0, 1 ) * amp[0];

  // *** DIAGRAM 416 OF 1240 ***

  // Wavefunction(s) for diagram number 416
  // (none)

  // Amplitude(s) for diagram number 416
  FFV1_0( w[41], w[102], w[66], COUPs[1], &amp[0] );
#ifdef MGONGPU_SUPPORTS_MULTICHANNEL
  if( channelId == 416 ) allNumerators[0] += cxabs2( amp[0] );
  if( channelId != 0 ) allDenominators[0] += cxabs2( amp[0] );
#endif
  jamp[6] += amp[0];
  jamp[8] -= amp[0];
  jamp[48] -= amp[0];
  jamp[50] += amp[0];

  // *** DIAGRAM 417 OF 1240 ***

  // Wavefunction(s) for diagram number 417
  // (none)

  // Amplitude(s) for diagram number 417
  FFV1_0( w[101], w[2], w[66], COUPs[1], &amp[0] );
#ifdef MGONGPU_SUPPORTS_MULTICHANNEL
  if( channelId == 417 ) allNumerators[0] += cxabs2( amp[0] );
  if( channelId != 0 ) allDenominators[0] += cxabs2( amp[0] );
#endif
  jamp[36] += amp[0];
  jamp[38] -= amp[0];
  jamp[78] -= amp[0];
  jamp[80] += amp[0];

  // *** DIAGRAM 418 OF 1240 ***

  // Wavefunction(s) for diagram number 418
  // (none)

  // Amplitude(s) for diagram number 418
  FFV1_0( w[76], w[102], w[5], COUPs[1], &amp[0] );
#ifdef MGONGPU_SUPPORTS_MULTICHANNEL
  if( channelId == 418 ) allNumerators[0] += cxabs2( amp[0] );
  if( channelId != 0 ) allDenominators[0] += cxabs2( amp[0] );
#endif
  jamp[8] += amp[0];
  jamp[9] -= amp[0];
  jamp[50] -= amp[0];
  jamp[51] += amp[0];

  // *** DIAGRAM 419 OF 1240 ***

  // Wavefunction(s) for diagram number 419
  // (none)

  // Amplitude(s) for diagram number 419
  FFV1_0( w[3], w[102], w[75], COUPs[1], &amp[0] );
#ifdef MGONGPU_SUPPORTS_MULTICHANNEL
  if( channelId == 419 ) allNumerators[0] += cxabs2( amp[0] );
  if( channelId != 0 ) allDenominators[0] += cxabs2( amp[0] );
#endif
  jamp[7] -= cxtype( 0, 1 ) * amp[0];
  jamp[8] += cxtype( 0, 1 ) * amp[0];
  jamp[9] -= cxtype( 0, 1 ) * amp[0];
  jamp[10] += cxtype( 0, 1 ) * amp[0];
  jamp[49] += cxtype( 0, 1 ) * amp[0];
  jamp[50] -= cxtype( 0, 1 ) * amp[0];
  jamp[51] += cxtype( 0, 1 ) * amp[0];
  jamp[52] -= cxtype( 0, 1 ) * amp[0];

  // *** DIAGRAM 420 OF 1240 ***

  // Wavefunction(s) for diagram number 420
  // (none)

  // Amplitude(s) for diagram number 420
  FFV1_0( w[99], w[97], w[5], COUPs[1], &amp[0] );
#ifdef MGONGPU_SUPPORTS_MULTICHANNEL
  if( channelId == 420 ) allNumerators[0] += cxabs2( amp[0] );
  if( channelId != 0 ) allDenominators[0] += cxabs2( amp[0] );
#endif
  jamp[46] += amp[0];
  jamp[47] -= amp[0];
  jamp[106] -= amp[0];
  jamp[107] += amp[0];

  // *** DIAGRAM 421 OF 1240 ***

  // Wavefunction(s) for diagram number 421
  // (none)

  // Amplitude(s) for diagram number 421
  FFV1_0( w[99], w[2], w[75], COUPs[1], &amp[0] );
#ifdef MGONGPU_SUPPORTS_MULTICHANNEL
  if( channelId == 421 ) allNumerators[0] += cxabs2( amp[0] );
  if( channelId != 0 ) allDenominators[0] += cxabs2( amp[0] );
#endif
  jamp[46] -= cxtype( 0, 1 ) * amp[0];
  jamp[47] += cxtype( 0, 1 ) * amp[0];
  jamp[82] += cxtype( 0, 1 ) * amp[0];
  jamp[83] -= cxtype( 0, 1 ) * amp[0];
  jamp[92] -= cxtype( 0, 1 ) * amp[0];
  jamp[93] += cxtype( 0, 1 ) * amp[0];
  jamp[106] += cxtype( 0, 1 ) * amp[0];
  jamp[107] -= cxtype( 0, 1 ) * amp[0];

  // *** DIAGRAM 422 OF 1240 ***

  // Wavefunction(s) for diagram number 422
  // (none)

  // Amplitude(s) for diagram number 422
  FFV1_0( w[3], w[97], w[62], COUPs[1], &amp[0] );
#ifdef MGONGPU_SUPPORTS_MULTICHANNEL
  if( channelId == 422 ) allNumerators[0] += cxabs2( amp[0] );
  if( channelId != 0 ) allDenominators[0] += cxabs2( amp[0] );
#endif
  jamp[42] -= cxtype( 0, 1 ) * amp[0];
  jamp[44] += cxtype( 0, 1 ) * amp[0];
  jamp[46] += cxtype( 0, 1 ) * amp[0];
  jamp[47] -= cxtype( 0, 1 ) * amp[0];
  jamp[102] += cxtype( 0, 1 ) * amp[0];
  jamp[104] -= cxtype( 0, 1 ) * amp[0];
  jamp[106] -= cxtype( 0, 1 ) * amp[0];
  jamp[107] += cxtype( 0, 1 ) * amp[0];

  // *** DIAGRAM 423 OF 1240 ***

  // Wavefunction(s) for diagram number 423
  // (none)

  // Amplitude(s) for diagram number 423
  FFV1_0( w[76], w[2], w[62], COUPs[1], &amp[0] );
#ifdef MGONGPU_SUPPORTS_MULTICHANNEL
  if( channelId == 423 ) allNumerators[0] += cxabs2( amp[0] );
  if( channelId != 0 ) allDenominators[0] += cxabs2( amp[0] );
#endif
  jamp[8] -= cxtype( 0, 1 ) * amp[0];
  jamp[9] += cxtype( 0, 1 ) * amp[0];
  jamp[50] += cxtype( 0, 1 ) * amp[0];
  jamp[51] -= cxtype( 0, 1 ) * amp[0];
  jamp[74] += cxtype( 0, 1 ) * amp[0];
  jamp[75] -= cxtype( 0, 1 ) * amp[0];
  jamp[84] -= cxtype( 0, 1 ) * amp[0];
  jamp[85] += cxtype( 0, 1 ) * amp[0];

  // *** DIAGRAM 424 OF 1240 ***

  // Wavefunction(s) for diagram number 424
  // (none)

  // Amplitude(s) for diagram number 424
  VVVV1_0( w[92], w[72], w[8], w[5], COUPs[2], &amp[0] );
  jamp[7] += amp[0];
  jamp[10] -= amp[0];
  jamp[42] -= amp[0];
  jamp[44] += amp[0];
  jamp[49] -= amp[0];
  jamp[52] += amp[0];
  jamp[74] -= amp[0];
  jamp[75] += amp[0];
  jamp[82] += amp[0];
  jamp[83] -= amp[0];
  jamp[84] += amp[0];
  jamp[85] -= amp[0];
  jamp[92] -= amp[0];
  jamp[93] += amp[0];
  jamp[102] += amp[0];
  jamp[104] -= amp[0];
  VVVV3_0( w[92], w[72], w[8], w[5], COUPs[2], &amp[0] );
  jamp[7] += amp[0];
  jamp[8] -= amp[0];
  jamp[9] += amp[0];
  jamp[10] -= amp[0];
  jamp[46] -= amp[0];
  jamp[47] += amp[0];
  jamp[49] -= amp[0];
  jamp[50] += amp[0];
  jamp[51] -= amp[0];
  jamp[52] += amp[0];
  jamp[82] += amp[0];
  jamp[83] -= amp[0];
  jamp[92] -= amp[0];
  jamp[93] += amp[0];
  jamp[106] += amp[0];
  jamp[107] -= amp[0];
  VVVV4_0( w[92], w[72], w[8], w[5], COUPs[2], &amp[0] );
  jamp[8] -= amp[0];
  jamp[9] += amp[0];
  jamp[42] += amp[0];
  jamp[44] -= amp[0];
  jamp[46] -= amp[0];
  jamp[47] += amp[0];
  jamp[50] += amp[0];
  jamp[51] -= amp[0];
  jamp[74] += amp[0];
  jamp[75] -= amp[0];
  jamp[84] -= amp[0];
  jamp[85] += amp[0];
  jamp[102] -= amp[0];
  jamp[104] += amp[0];
  jamp[106] += amp[0];
  jamp[107] -= amp[0];

  // *** DIAGRAM 425 OF 1240 ***

  // Wavefunction(s) for diagram number 425
  VVV1P0_1( w[92], w[72], COUPs[0], 0., 0., w[104] );

  // Amplitude(s) for diagram number 425
  VVV1_0( w[8], w[5], w[104], COUPs[0], &amp[0] );
#ifdef MGONGPU_SUPPORTS_MULTICHANNEL
  if( channelId == 425 ) allNumerators[0] += cxabs2( amp[0] );
  if( channelId != 0 ) allDenominators[0] += cxabs2( amp[0] );
#endif
  jamp[7] += amp[0];
  jamp[10] -= amp[0];
  jamp[42] -= amp[0];
  jamp[44] += amp[0];
  jamp[49] -= amp[0];
  jamp[52] += amp[0];
  jamp[74] -= amp[0];
  jamp[75] += amp[0];
  jamp[82] += amp[0];
  jamp[83] -= amp[0];
  jamp[84] += amp[0];
  jamp[85] -= amp[0];
  jamp[92] -= amp[0];
  jamp[93] += amp[0];
  jamp[102] += amp[0];
  jamp[104] -= amp[0];

  // *** DIAGRAM 426 OF 1240 ***

  // Wavefunction(s) for diagram number 426
  // (none)

  // Amplitude(s) for diagram number 426
  VVV1_0( w[72], w[5], w[107], COUPs[0], &amp[0] );
#ifdef MGONGPU_SUPPORTS_MULTICHANNEL
  if( channelId == 426 ) allNumerators[0] += cxabs2( amp[0] );
  if( channelId != 0 ) allDenominators[0] += cxabs2( amp[0] );
#endif
  jamp[7] += amp[0];
  jamp[8] -= amp[0];
  jamp[9] += amp[0];
  jamp[10] -= amp[0];
  jamp[46] -= amp[0];
  jamp[47] += amp[0];
  jamp[49] -= amp[0];
  jamp[50] += amp[0];
  jamp[51] -= amp[0];
  jamp[52] += amp[0];
  jamp[82] += amp[0];
  jamp[83] -= amp[0];
  jamp[92] -= amp[0];
  jamp[93] += amp[0];
  jamp[106] += amp[0];
  jamp[107] -= amp[0];

  // *** DIAGRAM 427 OF 1240 ***

  // Wavefunction(s) for diagram number 427
  // (none)

  // Amplitude(s) for diagram number 427
  VVV1_0( w[72], w[8], w[62], COUPs[0], &amp[0] );
#ifdef MGONGPU_SUPPORTS_MULTICHANNEL
  if( channelId == 427 ) allNumerators[0] += cxabs2( amp[0] );
  if( channelId != 0 ) allDenominators[0] += cxabs2( amp[0] );
#endif
  jamp[8] -= amp[0];
  jamp[9] += amp[0];
  jamp[42] += amp[0];
  jamp[44] -= amp[0];
  jamp[46] -= amp[0];
  jamp[47] += amp[0];
  jamp[50] += amp[0];
  jamp[51] -= amp[0];
  jamp[74] += amp[0];
  jamp[75] -= amp[0];
  jamp[84] -= amp[0];
  jamp[85] += amp[0];
  jamp[102] -= amp[0];
  jamp[104] += amp[0];
  jamp[106] += amp[0];
  jamp[107] -= amp[0];

  // *** DIAGRAM 428 OF 1240 ***

  // Wavefunction(s) for diagram number 428
  // (none)

  // Amplitude(s) for diagram number 428
  FFV1_0( w[3], w[39], w[104], COUPs[1], &amp[0] );
#ifdef MGONGPU_SUPPORTS_MULTICHANNEL
  if( channelId == 428 ) allNumerators[0] += cxabs2( amp[0] );
  if( channelId != 0 ) allDenominators[0] += cxabs2( amp[0] );
#endif
  jamp[74] -= cxtype( 0, 1 ) * amp[0];
  jamp[75] += cxtype( 0, 1 ) * amp[0];
  jamp[82] += cxtype( 0, 1 ) * amp[0];
  jamp[83] -= cxtype( 0, 1 ) * amp[0];
  jamp[84] += cxtype( 0, 1 ) * amp[0];
  jamp[85] -= cxtype( 0, 1 ) * amp[0];
  jamp[92] -= cxtype( 0, 1 ) * amp[0];
  jamp[93] += cxtype( 0, 1 ) * amp[0];

  // *** DIAGRAM 429 OF 1240 ***

  // Wavefunction(s) for diagram number 429
  // (none)

  // Amplitude(s) for diagram number 429
  FFV1_0( w[3], w[105], w[72], COUPs[1], &amp[0] );
#ifdef MGONGPU_SUPPORTS_MULTICHANNEL
  if( channelId == 429 ) allNumerators[0] += cxabs2( amp[0] );
  if( channelId != 0 ) allDenominators[0] += cxabs2( amp[0] );
#endif
  jamp[74] += amp[0];
  jamp[75] -= amp[0];
  jamp[84] -= amp[0];
  jamp[85] += amp[0];

  // *** DIAGRAM 430 OF 1240 ***

  // Wavefunction(s) for diagram number 430
  // (none)

  // Amplitude(s) for diagram number 430
  FFV1_0( w[99], w[39], w[72], COUPs[1], &amp[0] );
#ifdef MGONGPU_SUPPORTS_MULTICHANNEL
  if( channelId == 430 ) allNumerators[0] += cxabs2( amp[0] );
  if( channelId != 0 ) allDenominators[0] += cxabs2( amp[0] );
#endif
  jamp[82] += amp[0];
  jamp[83] -= amp[0];
  jamp[92] -= amp[0];
  jamp[93] += amp[0];

  // *** DIAGRAM 431 OF 1240 ***

  // Wavefunction(s) for diagram number 431
  // (none)

  // Amplitude(s) for diagram number 431
  FFV1_0( w[38], w[2], w[104], COUPs[1], &amp[0] );
#ifdef MGONGPU_SUPPORTS_MULTICHANNEL
  if( channelId == 431 ) allNumerators[0] += cxabs2( amp[0] );
  if( channelId != 0 ) allDenominators[0] += cxabs2( amp[0] );
#endif
  jamp[7] -= cxtype( 0, 1 ) * amp[0];
  jamp[10] += cxtype( 0, 1 ) * amp[0];
  jamp[42] += cxtype( 0, 1 ) * amp[0];
  jamp[44] -= cxtype( 0, 1 ) * amp[0];
  jamp[49] += cxtype( 0, 1 ) * amp[0];
  jamp[52] -= cxtype( 0, 1 ) * amp[0];
  jamp[102] -= cxtype( 0, 1 ) * amp[0];
  jamp[104] += cxtype( 0, 1 ) * amp[0];

  // *** DIAGRAM 432 OF 1240 ***

  // Wavefunction(s) for diagram number 432
  // (none)

  // Amplitude(s) for diagram number 432
  FFV1_0( w[38], w[102], w[72], COUPs[1], &amp[0] );
#ifdef MGONGPU_SUPPORTS_MULTICHANNEL
  if( channelId == 432 ) allNumerators[0] += cxabs2( amp[0] );
  if( channelId != 0 ) allDenominators[0] += cxabs2( amp[0] );
#endif
  jamp[7] += amp[0];
  jamp[10] -= amp[0];
  jamp[49] -= amp[0];
  jamp[52] += amp[0];

  // *** DIAGRAM 433 OF 1240 ***

  // Wavefunction(s) for diagram number 433
  // (none)

  // Amplitude(s) for diagram number 433
  FFV1_0( w[98], w[2], w[72], COUPs[1], &amp[0] );
#ifdef MGONGPU_SUPPORTS_MULTICHANNEL
  if( channelId == 433 ) allNumerators[0] += cxabs2( amp[0] );
  if( channelId != 0 ) allDenominators[0] += cxabs2( amp[0] );
#endif
  jamp[42] += amp[0];
  jamp[44] -= amp[0];
  jamp[102] -= amp[0];
  jamp[104] += amp[0];

  // *** DIAGRAM 434 OF 1240 ***

  // Wavefunction(s) for diagram number 434
  VVV1P0_1( w[92], w[1], COUPs[0], 0., 0., w[104] );

  // Amplitude(s) for diagram number 434
  VVV1_0( w[104], w[10], w[6], COUPs[0], &amp[0] );
#ifdef MGONGPU_SUPPORTS_MULTICHANNEL
  if( channelId == 434 ) allNumerators[0] += cxabs2( amp[0] );
  if( channelId != 0 ) allDenominators[0] += cxabs2( amp[0] );
#endif
  jamp[7] -= amp[0];
  jamp[25] += amp[0];
  jamp[31] -= amp[0];
  jamp[49] += amp[0];
  jamp[74] += amp[0];
  jamp[78] -= amp[0];
  jamp[80] += amp[0];
  jamp[84] -= amp[0];
  jamp[91] -= amp[0];
  jamp[92] += amp[0];
  jamp[93] -= amp[0];
  jamp[94] += amp[0];
  jamp[98] += amp[0];
  jamp[102] -= amp[0];
  jamp[104] += amp[0];
  jamp[108] -= amp[0];

  // *** DIAGRAM 435 OF 1240 ***

  // Wavefunction(s) for diagram number 435
  // (none)

  // Amplitude(s) for diagram number 435
  VVV1_0( w[104], w[11], w[5], COUPs[0], &amp[0] );
#ifdef MGONGPU_SUPPORTS_MULTICHANNEL
  if( channelId == 435 ) allNumerators[0] += cxabs2( amp[0] );
  if( channelId != 0 ) allDenominators[0] += cxabs2( amp[0] );
#endif
  jamp[6] -= amp[0];
  jamp[24] += amp[0];
  jamp[30] -= amp[0];
  jamp[48] += amp[0];
  jamp[74] += amp[0];
  jamp[78] -= amp[0];
  jamp[80] += amp[0];
  jamp[84] -= amp[0];
  jamp[98] += amp[0];
  jamp[102] -= amp[0];
  jamp[104] += amp[0];
  jamp[108] -= amp[0];
  jamp[115] -= amp[0];
  jamp[116] += amp[0];
  jamp[117] -= amp[0];
  jamp[118] += amp[0];

  // *** DIAGRAM 436 OF 1240 ***

  // Wavefunction(s) for diagram number 436
  // (none)

  // Amplitude(s) for diagram number 436
  VVVV1_0( w[8], w[5], w[6], w[104], COUPs[2], &amp[0] );
  jamp[7] -= amp[0];
  jamp[25] += amp[0];
  jamp[31] -= amp[0];
  jamp[49] += amp[0];
  jamp[74] += amp[0];
  jamp[78] -= amp[0];
  jamp[80] += amp[0];
  jamp[84] -= amp[0];
  jamp[91] -= amp[0];
  jamp[92] += amp[0];
  jamp[93] -= amp[0];
  jamp[94] += amp[0];
  jamp[98] += amp[0];
  jamp[102] -= amp[0];
  jamp[104] += amp[0];
  jamp[108] -= amp[0];
  VVVV3_0( w[8], w[5], w[6], w[104], COUPs[2], &amp[0] );
  jamp[6] -= amp[0];
  jamp[24] += amp[0];
  jamp[30] -= amp[0];
  jamp[48] += amp[0];
  jamp[74] += amp[0];
  jamp[78] -= amp[0];
  jamp[80] += amp[0];
  jamp[84] -= amp[0];
  jamp[98] += amp[0];
  jamp[102] -= amp[0];
  jamp[104] += amp[0];
  jamp[108] -= amp[0];
  jamp[115] -= amp[0];
  jamp[116] += amp[0];
  jamp[117] -= amp[0];
  jamp[118] += amp[0];
  VVVV4_0( w[8], w[5], w[6], w[104], COUPs[2], &amp[0] );
  jamp[6] -= amp[0];
  jamp[7] += amp[0];
  jamp[24] += amp[0];
  jamp[25] -= amp[0];
  jamp[30] -= amp[0];
  jamp[31] += amp[0];
  jamp[48] += amp[0];
  jamp[49] -= amp[0];
  jamp[91] += amp[0];
  jamp[92] -= amp[0];
  jamp[93] += amp[0];
  jamp[94] -= amp[0];
  jamp[115] -= amp[0];
  jamp[116] += amp[0];
  jamp[117] -= amp[0];
  jamp[118] += amp[0];

  // *** DIAGRAM 437 OF 1240 ***

  // Wavefunction(s) for diagram number 437
  VVV1P0_1( w[1], w[8], COUPs[0], 0., 0., w[108] );

  // Amplitude(s) for diagram number 437
  VVV1_0( w[62], w[108], w[6], COUPs[0], &amp[0] );
#ifdef MGONGPU_SUPPORTS_MULTICHANNEL
  if( channelId == 437 ) allNumerators[0] += cxabs2( amp[0] );
  if( channelId != 0 ) allDenominators[0] += cxabs2( amp[0] );
#endif
  jamp[9] += amp[0];
  jamp[24] -= amp[0];
  jamp[30] += amp[0];
  jamp[36] += amp[0];
  jamp[38] -= amp[0];
  jamp[42] += amp[0];
  jamp[44] -= amp[0];
  jamp[46] -= amp[0];
  jamp[47] += amp[0];
  jamp[51] -= amp[0];
  jamp[75] -= amp[0];
  jamp[85] += amp[0];
  jamp[99] -= amp[0];
  jamp[109] += amp[0];
  jamp[115] += amp[0];
  jamp[118] -= amp[0];

  // *** DIAGRAM 438 OF 1240 ***

  // Wavefunction(s) for diagram number 438
  // (none)

  // Amplitude(s) for diagram number 438
  VVV1_0( w[62], w[1], w[11], COUPs[0], &amp[0] );
#ifdef MGONGPU_SUPPORTS_MULTICHANNEL
  if( channelId == 438 ) allNumerators[0] += cxabs2( amp[0] );
  if( channelId != 0 ) allDenominators[0] += cxabs2( amp[0] );
#endif
  jamp[8] += amp[0];
  jamp[24] -= amp[0];
  jamp[30] += amp[0];
  jamp[36] += amp[0];
  jamp[38] -= amp[0];
  jamp[50] -= amp[0];
  jamp[74] -= amp[0];
  jamp[84] += amp[0];
  jamp[99] -= amp[0];
  jamp[102] += amp[0];
  jamp[104] -= amp[0];
  jamp[106] -= amp[0];
  jamp[107] += amp[0];
  jamp[109] += amp[0];
  jamp[115] += amp[0];
  jamp[118] -= amp[0];

  // *** DIAGRAM 439 OF 1240 ***

  // Wavefunction(s) for diagram number 439
  // (none)

  // Amplitude(s) for diagram number 439
  VVVV1_0( w[1], w[8], w[6], w[62], COUPs[2], &amp[0] );
  jamp[9] += amp[0];
  jamp[24] -= amp[0];
  jamp[30] += amp[0];
  jamp[36] += amp[0];
  jamp[38] -= amp[0];
  jamp[42] += amp[0];
  jamp[44] -= amp[0];
  jamp[46] -= amp[0];
  jamp[47] += amp[0];
  jamp[51] -= amp[0];
  jamp[75] -= amp[0];
  jamp[85] += amp[0];
  jamp[99] -= amp[0];
  jamp[109] += amp[0];
  jamp[115] += amp[0];
  jamp[118] -= amp[0];
  VVVV3_0( w[1], w[8], w[6], w[62], COUPs[2], &amp[0] );
  jamp[8] -= amp[0];
  jamp[9] += amp[0];
  jamp[42] += amp[0];
  jamp[44] -= amp[0];
  jamp[46] -= amp[0];
  jamp[47] += amp[0];
  jamp[50] += amp[0];
  jamp[51] -= amp[0];
  jamp[74] += amp[0];
  jamp[75] -= amp[0];
  jamp[84] -= amp[0];
  jamp[85] += amp[0];
  jamp[102] -= amp[0];
  jamp[104] += amp[0];
  jamp[106] += amp[0];
  jamp[107] -= amp[0];
  VVVV4_0( w[1], w[8], w[6], w[62], COUPs[2], &amp[0] );
  jamp[8] -= amp[0];
  jamp[24] += amp[0];
  jamp[30] -= amp[0];
  jamp[36] -= amp[0];
  jamp[38] += amp[0];
  jamp[50] += amp[0];
  jamp[74] += amp[0];
  jamp[84] -= amp[0];
  jamp[99] += amp[0];
  jamp[102] -= amp[0];
  jamp[104] += amp[0];
  jamp[106] += amp[0];
  jamp[107] -= amp[0];
  jamp[109] -= amp[0];
  jamp[115] -= amp[0];
  jamp[118] += amp[0];

  // *** DIAGRAM 440 OF 1240 ***

  // Wavefunction(s) for diagram number 440
  // (none)

  // Amplitude(s) for diagram number 440
  VVV1_0( w[86], w[108], w[5], COUPs[0], &amp[0] );
#ifdef MGONGPU_SUPPORTS_MULTICHANNEL
  if( channelId == 440 ) allNumerators[0] += cxabs2( amp[0] );
  if( channelId != 0 ) allDenominators[0] += cxabs2( amp[0] );
#endif
  jamp[11] += amp[0];
  jamp[25] -= amp[0];
  jamp[31] += amp[0];
  jamp[36] += amp[0];
  jamp[38] -= amp[0];
  jamp[40] -= amp[0];
  jamp[41] += amp[0];
  jamp[42] += amp[0];
  jamp[44] -= amp[0];
  jamp[53] -= amp[0];
  jamp[75] -= amp[0];
  jamp[85] += amp[0];
  jamp[91] += amp[0];
  jamp[94] -= amp[0];
  jamp[99] -= amp[0];
  jamp[109] += amp[0];

  // *** DIAGRAM 441 OF 1240 ***

  // Wavefunction(s) for diagram number 441
  // (none)

  // Amplitude(s) for diagram number 441
  VVV1_0( w[86], w[1], w[10], COUPs[0], &amp[0] );
#ifdef MGONGPU_SUPPORTS_MULTICHANNEL
  if( channelId == 441 ) allNumerators[0] += cxabs2( amp[0] );
  if( channelId != 0 ) allDenominators[0] += cxabs2( amp[0] );
#endif
  jamp[10] += amp[0];
  jamp[25] -= amp[0];
  jamp[31] += amp[0];
  jamp[42] += amp[0];
  jamp[44] -= amp[0];
  jamp[52] -= amp[0];
  jamp[75] -= amp[0];
  jamp[78] += amp[0];
  jamp[80] -= amp[0];
  jamp[82] -= amp[0];
  jamp[83] += amp[0];
  jamp[85] += amp[0];
  jamp[91] += amp[0];
  jamp[94] -= amp[0];
  jamp[98] -= amp[0];
  jamp[108] += amp[0];

  // *** DIAGRAM 442 OF 1240 ***

  // Wavefunction(s) for diagram number 442
  // (none)

  // Amplitude(s) for diagram number 442
  VVVV1_0( w[1], w[8], w[5], w[86], COUPs[2], &amp[0] );
  jamp[11] += amp[0];
  jamp[25] -= amp[0];
  jamp[31] += amp[0];
  jamp[36] += amp[0];
  jamp[38] -= amp[0];
  jamp[40] -= amp[0];
  jamp[41] += amp[0];
  jamp[42] += amp[0];
  jamp[44] -= amp[0];
  jamp[53] -= amp[0];
  jamp[75] -= amp[0];
  jamp[85] += amp[0];
  jamp[91] += amp[0];
  jamp[94] -= amp[0];
  jamp[99] -= amp[0];
  jamp[109] += amp[0];
  VVVV3_0( w[1], w[8], w[5], w[86], COUPs[2], &amp[0] );
  jamp[10] -= amp[0];
  jamp[11] += amp[0];
  jamp[36] += amp[0];
  jamp[38] -= amp[0];
  jamp[40] -= amp[0];
  jamp[41] += amp[0];
  jamp[52] += amp[0];
  jamp[53] -= amp[0];
  jamp[78] -= amp[0];
  jamp[80] += amp[0];
  jamp[82] += amp[0];
  jamp[83] -= amp[0];
  jamp[98] += amp[0];
  jamp[99] -= amp[0];
  jamp[108] -= amp[0];
  jamp[109] += amp[0];
  VVVV4_0( w[1], w[8], w[5], w[86], COUPs[2], &amp[0] );
  jamp[10] -= amp[0];
  jamp[25] += amp[0];
  jamp[31] -= amp[0];
  jamp[42] -= amp[0];
  jamp[44] += amp[0];
  jamp[52] += amp[0];
  jamp[75] += amp[0];
  jamp[78] -= amp[0];
  jamp[80] += amp[0];
  jamp[82] += amp[0];
  jamp[83] -= amp[0];
  jamp[85] -= amp[0];
  jamp[91] -= amp[0];
  jamp[94] += amp[0];
  jamp[98] += amp[0];
  jamp[108] -= amp[0];

  // *** DIAGRAM 443 OF 1240 ***

  // Wavefunction(s) for diagram number 443
  VVVV1P0_1( w[92], w[1], w[5], COUPs[2], 0., 0., w[109] );
  VVVV3P0_1( w[92], w[1], w[5], COUPs[2], 0., 0., w[110] );
  VVVV4P0_1( w[92], w[1], w[5], COUPs[2], 0., 0., w[111] );

  // Amplitude(s) for diagram number 443
  VVV1_0( w[8], w[6], w[109], COUPs[0], &amp[0] );
  jamp[6] += amp[0];
  jamp[8] -= amp[0];
  jamp[36] -= amp[0];
  jamp[38] += amp[0];
  jamp[48] -= amp[0];
  jamp[50] += amp[0];
  jamp[78] += amp[0];
  jamp[80] -= amp[0];
  jamp[98] -= amp[0];
  jamp[99] += amp[0];
  jamp[106] += amp[0];
  jamp[107] -= amp[0];
  jamp[108] += amp[0];
  jamp[109] -= amp[0];
  jamp[116] -= amp[0];
  jamp[117] += amp[0];
  VVV1_0( w[8], w[6], w[110], COUPs[0], &amp[0] );
  jamp[8] -= amp[0];
  jamp[24] += amp[0];
  jamp[30] -= amp[0];
  jamp[36] -= amp[0];
  jamp[38] += amp[0];
  jamp[50] += amp[0];
  jamp[74] += amp[0];
  jamp[84] -= amp[0];
  jamp[99] += amp[0];
  jamp[102] -= amp[0];
  jamp[104] += amp[0];
  jamp[106] += amp[0];
  jamp[107] -= amp[0];
  jamp[109] -= amp[0];
  jamp[115] -= amp[0];
  jamp[118] += amp[0];
  VVV1_0( w[8], w[6], w[111], COUPs[0], &amp[0] );
  jamp[6] -= amp[0];
  jamp[24] += amp[0];
  jamp[30] -= amp[0];
  jamp[48] += amp[0];
  jamp[74] += amp[0];
  jamp[78] -= amp[0];
  jamp[80] += amp[0];
  jamp[84] -= amp[0];
  jamp[98] += amp[0];
  jamp[102] -= amp[0];
  jamp[104] += amp[0];
  jamp[108] -= amp[0];
  jamp[115] -= amp[0];
  jamp[116] += amp[0];
  jamp[117] -= amp[0];
  jamp[118] += amp[0];

  // *** DIAGRAM 444 OF 1240 ***

  // Wavefunction(s) for diagram number 444
  VVVV1P0_1( w[92], w[1], w[6], COUPs[2], 0., 0., w[112] );
  VVVV3P0_1( w[92], w[1], w[6], COUPs[2], 0., 0., w[113] );
  VVVV4P0_1( w[92], w[1], w[6], COUPs[2], 0., 0., w[114] );

  // Amplitude(s) for diagram number 444
  VVV1_0( w[8], w[5], w[112], COUPs[0], &amp[0] );
  jamp[7] += amp[0];
  jamp[10] -= amp[0];
  jamp[42] -= amp[0];
  jamp[44] += amp[0];
  jamp[49] -= amp[0];
  jamp[52] += amp[0];
  jamp[74] -= amp[0];
  jamp[75] += amp[0];
  jamp[82] += amp[0];
  jamp[83] -= amp[0];
  jamp[84] += amp[0];
  jamp[85] -= amp[0];
  jamp[92] -= amp[0];
  jamp[93] += amp[0];
  jamp[102] += amp[0];
  jamp[104] -= amp[0];
  VVV1_0( w[8], w[5], w[113], COUPs[0], &amp[0] );
  jamp[10] -= amp[0];
  jamp[25] += amp[0];
  jamp[31] -= amp[0];
  jamp[42] -= amp[0];
  jamp[44] += amp[0];
  jamp[52] += amp[0];
  jamp[75] += amp[0];
  jamp[78] -= amp[0];
  jamp[80] += amp[0];
  jamp[82] += amp[0];
  jamp[83] -= amp[0];
  jamp[85] -= amp[0];
  jamp[91] -= amp[0];
  jamp[94] += amp[0];
  jamp[98] += amp[0];
  jamp[108] -= amp[0];
  VVV1_0( w[8], w[5], w[114], COUPs[0], &amp[0] );
  jamp[7] -= amp[0];
  jamp[25] += amp[0];
  jamp[31] -= amp[0];
  jamp[49] += amp[0];
  jamp[74] += amp[0];
  jamp[78] -= amp[0];
  jamp[80] += amp[0];
  jamp[84] -= amp[0];
  jamp[91] -= amp[0];
  jamp[92] += amp[0];
  jamp[93] -= amp[0];
  jamp[94] += amp[0];
  jamp[98] += amp[0];
  jamp[102] -= amp[0];
  jamp[104] += amp[0];
  jamp[108] -= amp[0];

  // *** DIAGRAM 445 OF 1240 ***

  // Wavefunction(s) for diagram number 445
  // (none)

  // Amplitude(s) for diagram number 445
  VVV1_0( w[1], w[8], w[88], COUPs[0], &amp[0] );
  jamp[9] -= amp[0];
  jamp[11] += amp[0];
  jamp[24] += amp[0];
  jamp[25] -= amp[0];
  jamp[30] -= amp[0];
  jamp[31] += amp[0];
  jamp[40] -= amp[0];
  jamp[41] += amp[0];
  jamp[46] += amp[0];
  jamp[47] -= amp[0];
  jamp[51] += amp[0];
  jamp[53] -= amp[0];
  jamp[91] += amp[0];
  jamp[94] -= amp[0];
  jamp[115] -= amp[0];
  jamp[118] += amp[0];
  VVV1_0( w[1], w[8], w[90], COUPs[0], &amp[0] );
  jamp[11] += amp[0];
  jamp[25] -= amp[0];
  jamp[31] += amp[0];
  jamp[36] += amp[0];
  jamp[38] -= amp[0];
  jamp[40] -= amp[0];
  jamp[41] += amp[0];
  jamp[42] += amp[0];
  jamp[44] -= amp[0];
  jamp[53] -= amp[0];
  jamp[75] -= amp[0];
  jamp[85] += amp[0];
  jamp[91] += amp[0];
  jamp[94] -= amp[0];
  jamp[99] -= amp[0];
  jamp[109] += amp[0];
  VVV1_0( w[1], w[8], w[96], COUPs[0], &amp[0] );
  jamp[9] += amp[0];
  jamp[24] -= amp[0];
  jamp[30] += amp[0];
  jamp[36] += amp[0];
  jamp[38] -= amp[0];
  jamp[42] += amp[0];
  jamp[44] -= amp[0];
  jamp[46] -= amp[0];
  jamp[47] += amp[0];
  jamp[51] -= amp[0];
  jamp[75] -= amp[0];
  jamp[85] += amp[0];
  jamp[99] -= amp[0];
  jamp[109] += amp[0];
  jamp[115] += amp[0];
  jamp[118] -= amp[0];

  // *** DIAGRAM 446 OF 1240 ***

  // Wavefunction(s) for diagram number 446
  // (none)

  // Amplitude(s) for diagram number 446
  VVVV1_0( w[92], w[1], w[8], w[29], COUPs[2], &amp[0] );
  jamp[6] += amp[0];
  jamp[7] -= amp[0];
  jamp[24] -= amp[0];
  jamp[25] += amp[0];
  jamp[30] += amp[0];
  jamp[31] -= amp[0];
  jamp[48] -= amp[0];
  jamp[49] += amp[0];
  jamp[91] -= amp[0];
  jamp[92] += amp[0];
  jamp[93] -= amp[0];
  jamp[94] += amp[0];
  jamp[115] += amp[0];
  jamp[116] -= amp[0];
  jamp[117] += amp[0];
  jamp[118] -= amp[0];
  VVVV3_0( w[92], w[1], w[8], w[29], COUPs[2], &amp[0] );
  jamp[6] += amp[0];
  jamp[7] -= amp[0];
  jamp[9] -= amp[0];
  jamp[11] += amp[0];
  jamp[40] -= amp[0];
  jamp[41] += amp[0];
  jamp[46] += amp[0];
  jamp[47] -= amp[0];
  jamp[48] -= amp[0];
  jamp[49] += amp[0];
  jamp[51] += amp[0];
  jamp[53] -= amp[0];
  jamp[92] += amp[0];
  jamp[93] -= amp[0];
  jamp[116] -= amp[0];
  jamp[117] += amp[0];
  VVVV4_0( w[92], w[1], w[8], w[29], COUPs[2], &amp[0] );
  jamp[9] -= amp[0];
  jamp[11] += amp[0];
  jamp[24] += amp[0];
  jamp[25] -= amp[0];
  jamp[30] -= amp[0];
  jamp[31] += amp[0];
  jamp[40] -= amp[0];
  jamp[41] += amp[0];
  jamp[46] += amp[0];
  jamp[47] -= amp[0];
  jamp[51] += amp[0];
  jamp[53] -= amp[0];
  jamp[91] += amp[0];
  jamp[94] -= amp[0];
  jamp[115] -= amp[0];
  jamp[118] += amp[0];

  // *** DIAGRAM 447 OF 1240 ***

  // Wavefunction(s) for diagram number 447
  // (none)

  // Amplitude(s) for diagram number 447
  VVV1_0( w[8], w[29], w[104], COUPs[0], &amp[0] );
#ifdef MGONGPU_SUPPORTS_MULTICHANNEL
  if( channelId == 447 ) allNumerators[0] += cxabs2( amp[0] );
  if( channelId != 0 ) allDenominators[0] += cxabs2( amp[0] );
#endif
  jamp[6] += amp[0];
  jamp[7] -= amp[0];
  jamp[24] -= amp[0];
  jamp[25] += amp[0];
  jamp[30] += amp[0];
  jamp[31] -= amp[0];
  jamp[48] -= amp[0];
  jamp[49] += amp[0];
  jamp[91] -= amp[0];
  jamp[92] += amp[0];
  jamp[93] -= amp[0];
  jamp[94] += amp[0];
  jamp[115] += amp[0];
  jamp[116] -= amp[0];
  jamp[117] += amp[0];
  jamp[118] -= amp[0];

  // *** DIAGRAM 448 OF 1240 ***

  // Wavefunction(s) for diagram number 448
  // (none)

  // Amplitude(s) for diagram number 448
  VVV1_0( w[1], w[29], w[107], COUPs[0], &amp[0] );
#ifdef MGONGPU_SUPPORTS_MULTICHANNEL
  if( channelId == 448 ) allNumerators[0] += cxabs2( amp[0] );
  if( channelId != 0 ) allDenominators[0] += cxabs2( amp[0] );
#endif
  jamp[6] += amp[0];
  jamp[7] -= amp[0];
  jamp[9] -= amp[0];
  jamp[11] += amp[0];
  jamp[40] -= amp[0];
  jamp[41] += amp[0];
  jamp[46] += amp[0];
  jamp[47] -= amp[0];
  jamp[48] -= amp[0];
  jamp[49] += amp[0];
  jamp[51] += amp[0];
  jamp[53] -= amp[0];
  jamp[92] += amp[0];
  jamp[93] -= amp[0];
  jamp[116] -= amp[0];
  jamp[117] += amp[0];

  // *** DIAGRAM 449 OF 1240 ***

  // Wavefunction(s) for diagram number 449
  // (none)

  // Amplitude(s) for diagram number 449
  VVV1_0( w[1], w[8], w[95], COUPs[0], &amp[0] );
#ifdef MGONGPU_SUPPORTS_MULTICHANNEL
  if( channelId == 449 ) allNumerators[0] += cxabs2( amp[0] );
  if( channelId != 0 ) allDenominators[0] += cxabs2( amp[0] );
#endif
  jamp[9] -= amp[0];
  jamp[11] += amp[0];
  jamp[24] += amp[0];
  jamp[25] -= amp[0];
  jamp[30] -= amp[0];
  jamp[31] += amp[0];
  jamp[40] -= amp[0];
  jamp[41] += amp[0];
  jamp[46] += amp[0];
  jamp[47] -= amp[0];
  jamp[51] += amp[0];
  jamp[53] -= amp[0];
  jamp[91] += amp[0];
  jamp[94] -= amp[0];
  jamp[115] -= amp[0];
  jamp[118] += amp[0];

  // *** DIAGRAM 450 OF 1240 ***

  // Wavefunction(s) for diagram number 450
  // (none)

  // Amplitude(s) for diagram number 450
  VVV1_0( w[104], w[45], w[6], COUPs[0], &amp[0] );
#ifdef MGONGPU_SUPPORTS_MULTICHANNEL
  if( channelId == 450 ) allNumerators[0] += cxabs2( amp[0] );
  if( channelId != 0 ) allDenominators[0] += cxabs2( amp[0] );
#endif
  jamp[74] += cxtype( 0, 1 ) * amp[0];
  jamp[78] -= cxtype( 0, 1 ) * amp[0];
  jamp[80] += cxtype( 0, 1 ) * amp[0];
  jamp[84] -= cxtype( 0, 1 ) * amp[0];
  jamp[91] -= cxtype( 0, 1 ) * amp[0];
  jamp[92] += cxtype( 0, 1 ) * amp[0];
  jamp[93] -= cxtype( 0, 1 ) * amp[0];
  jamp[94] += cxtype( 0, 1 ) * amp[0];

  // *** DIAGRAM 451 OF 1240 ***

  // Wavefunction(s) for diagram number 451
  // (none)

  // Amplitude(s) for diagram number 451
  FFV1_0( w[3], w[44], w[104], COUPs[1], &amp[0] );
#ifdef MGONGPU_SUPPORTS_MULTICHANNEL
  if( channelId == 451 ) allNumerators[0] += cxabs2( amp[0] );
  if( channelId != 0 ) allDenominators[0] += cxabs2( amp[0] );
#endif
  jamp[91] += amp[0];
  jamp[92] -= amp[0];
  jamp[93] += amp[0];
  jamp[94] -= amp[0];

  // *** DIAGRAM 452 OF 1240 ***

  // Wavefunction(s) for diagram number 452
  // (none)

  // Amplitude(s) for diagram number 452
  FFV1_0( w[99], w[89], w[6], COUPs[1], &amp[0] );
#ifdef MGONGPU_SUPPORTS_MULTICHANNEL
  if( channelId == 452 ) allNumerators[0] += cxabs2( amp[0] );
  if( channelId != 0 ) allDenominators[0] += cxabs2( amp[0] );
#endif
  jamp[82] += cxtype( 0, 1 ) * amp[0];
  jamp[83] -= cxtype( 0, 1 ) * amp[0];

  // *** DIAGRAM 453 OF 1240 ***

  // Wavefunction(s) for diagram number 453
  // (none)

  // Amplitude(s) for diagram number 453
  FFV1_0( w[99], w[44], w[1], COUPs[1], &amp[0] );
#ifdef MGONGPU_SUPPORTS_MULTICHANNEL
  if( channelId == 453 ) allNumerators[0] += cxabs2( amp[0] );
  if( channelId != 0 ) allDenominators[0] += cxabs2( amp[0] );
#endif
  jamp[92] += cxtype( 0, 1 ) * amp[0];
  jamp[93] -= cxtype( 0, 1 ) * amp[0];

  // *** DIAGRAM 454 OF 1240 ***

  // Wavefunction(s) for diagram number 454
  // (none)

  // Amplitude(s) for diagram number 454
  FFV1_0( w[3], w[89], w[86], COUPs[1], &amp[0] );
#ifdef MGONGPU_SUPPORTS_MULTICHANNEL
  if( channelId == 454 ) allNumerators[0] += cxabs2( amp[0] );
  if( channelId != 0 ) allDenominators[0] += cxabs2( amp[0] );
#endif
  jamp[78] += amp[0];
  jamp[80] -= amp[0];
  jamp[82] -= amp[0];
  jamp[83] += amp[0];

  // *** DIAGRAM 455 OF 1240 ***

  // Wavefunction(s) for diagram number 455
  // (none)

  // Amplitude(s) for diagram number 455
  VVV1_0( w[86], w[1], w[45], COUPs[0], &amp[0] );
#ifdef MGONGPU_SUPPORTS_MULTICHANNEL
  if( channelId == 455 ) allNumerators[0] += cxabs2( amp[0] );
  if( channelId != 0 ) allDenominators[0] += cxabs2( amp[0] );
#endif
  jamp[75] -= cxtype( 0, 1 ) * amp[0];
  jamp[78] += cxtype( 0, 1 ) * amp[0];
  jamp[80] -= cxtype( 0, 1 ) * amp[0];
  jamp[82] -= cxtype( 0, 1 ) * amp[0];
  jamp[83] += cxtype( 0, 1 ) * amp[0];
  jamp[85] += cxtype( 0, 1 ) * amp[0];
  jamp[91] += cxtype( 0, 1 ) * amp[0];
  jamp[94] -= cxtype( 0, 1 ) * amp[0];

  // *** DIAGRAM 456 OF 1240 ***

  // Wavefunction(s) for diagram number 456
  // (none)

  // Amplitude(s) for diagram number 456
  FFV1_0( w[3], w[39], w[112], COUPs[1], &amp[0] );
  jamp[74] -= cxtype( 0, 1 ) * amp[0];
  jamp[75] += cxtype( 0, 1 ) * amp[0];
  jamp[82] += cxtype( 0, 1 ) * amp[0];
  jamp[83] -= cxtype( 0, 1 ) * amp[0];
  jamp[84] += cxtype( 0, 1 ) * amp[0];
  jamp[85] -= cxtype( 0, 1 ) * amp[0];
  jamp[92] -= cxtype( 0, 1 ) * amp[0];
  jamp[93] += cxtype( 0, 1 ) * amp[0];
  FFV1_0( w[3], w[39], w[113], COUPs[1], &amp[0] );
  jamp[75] += cxtype( 0, 1 ) * amp[0];
  jamp[78] -= cxtype( 0, 1 ) * amp[0];
  jamp[80] += cxtype( 0, 1 ) * amp[0];
  jamp[82] += cxtype( 0, 1 ) * amp[0];
  jamp[83] -= cxtype( 0, 1 ) * amp[0];
  jamp[85] -= cxtype( 0, 1 ) * amp[0];
  jamp[91] -= cxtype( 0, 1 ) * amp[0];
  jamp[94] += cxtype( 0, 1 ) * amp[0];
  FFV1_0( w[3], w[39], w[114], COUPs[1], &amp[0] );
  jamp[74] += cxtype( 0, 1 ) * amp[0];
  jamp[78] -= cxtype( 0, 1 ) * amp[0];
  jamp[80] += cxtype( 0, 1 ) * amp[0];
  jamp[84] -= cxtype( 0, 1 ) * amp[0];
  jamp[91] -= cxtype( 0, 1 ) * amp[0];
  jamp[92] += cxtype( 0, 1 ) * amp[0];
  jamp[93] -= cxtype( 0, 1 ) * amp[0];
  jamp[94] += cxtype( 0, 1 ) * amp[0];

  // *** DIAGRAM 457 OF 1240 ***

  // Wavefunction(s) for diagram number 457
  // (none)

  // Amplitude(s) for diagram number 457
  FFV1_0( w[41], w[39], w[104], COUPs[1], &amp[0] );
#ifdef MGONGPU_SUPPORTS_MULTICHANNEL
  if( channelId == 457 ) allNumerators[0] += cxabs2( amp[0] );
  if( channelId != 0 ) allDenominators[0] += cxabs2( amp[0] );
#endif
  jamp[74] += amp[0];
  jamp[78] -= amp[0];
  jamp[80] += amp[0];
  jamp[84] -= amp[0];

  // *** DIAGRAM 458 OF 1240 ***

  // Wavefunction(s) for diagram number 458
  // (none)

  // Amplitude(s) for diagram number 458
  FFV1_0( w[41], w[105], w[1], COUPs[1], &amp[0] );
#ifdef MGONGPU_SUPPORTS_MULTICHANNEL
  if( channelId == 458 ) allNumerators[0] += cxabs2( amp[0] );
  if( channelId != 0 ) allDenominators[0] += cxabs2( amp[0] );
#endif
  jamp[74] += cxtype( 0, 1 ) * amp[0];
  jamp[84] -= cxtype( 0, 1 ) * amp[0];

  // *** DIAGRAM 459 OF 1240 ***

  // Wavefunction(s) for diagram number 459
  // (none)

  // Amplitude(s) for diagram number 459
  FFV1_0( w[101], w[39], w[1], COUPs[1], &amp[0] );
#ifdef MGONGPU_SUPPORTS_MULTICHANNEL
  if( channelId == 459 ) allNumerators[0] += cxabs2( amp[0] );
  if( channelId != 0 ) allDenominators[0] += cxabs2( amp[0] );
#endif
  jamp[78] += cxtype( 0, 1 ) * amp[0];
  jamp[80] -= cxtype( 0, 1 ) * amp[0];

  // *** DIAGRAM 460 OF 1240 ***

  // Wavefunction(s) for diagram number 460
  // (none)

  // Amplitude(s) for diagram number 460
  VVV1_0( w[104], w[51], w[5], COUPs[0], &amp[0] );
#ifdef MGONGPU_SUPPORTS_MULTICHANNEL
  if( channelId == 460 ) allNumerators[0] += cxabs2( amp[0] );
  if( channelId != 0 ) allDenominators[0] += cxabs2( amp[0] );
#endif
  jamp[98] += cxtype( 0, 1 ) * amp[0];
  jamp[102] -= cxtype( 0, 1 ) * amp[0];
  jamp[104] += cxtype( 0, 1 ) * amp[0];
  jamp[108] -= cxtype( 0, 1 ) * amp[0];
  jamp[115] -= cxtype( 0, 1 ) * amp[0];
  jamp[116] += cxtype( 0, 1 ) * amp[0];
  jamp[117] -= cxtype( 0, 1 ) * amp[0];
  jamp[118] += cxtype( 0, 1 ) * amp[0];

  // *** DIAGRAM 461 OF 1240 ***

  // Wavefunction(s) for diagram number 461
  // (none)

  // Amplitude(s) for diagram number 461
  FFV1_0( w[3], w[50], w[104], COUPs[1], &amp[0] );
#ifdef MGONGPU_SUPPORTS_MULTICHANNEL
  if( channelId == 461 ) allNumerators[0] += cxabs2( amp[0] );
  if( channelId != 0 ) allDenominators[0] += cxabs2( amp[0] );
#endif
  jamp[115] += amp[0];
  jamp[116] -= amp[0];
  jamp[117] += amp[0];
  jamp[118] -= amp[0];

  // *** DIAGRAM 462 OF 1240 ***

  // Wavefunction(s) for diagram number 462
  // (none)

  // Amplitude(s) for diagram number 462
  FFV1_0( w[99], w[91], w[5], COUPs[1], &amp[0] );
#ifdef MGONGPU_SUPPORTS_MULTICHANNEL
  if( channelId == 462 ) allNumerators[0] += cxabs2( amp[0] );
  if( channelId != 0 ) allDenominators[0] += cxabs2( amp[0] );
#endif
  jamp[106] += cxtype( 0, 1 ) * amp[0];
  jamp[107] -= cxtype( 0, 1 ) * amp[0];

  // *** DIAGRAM 463 OF 1240 ***

  // Wavefunction(s) for diagram number 463
  // (none)

  // Amplitude(s) for diagram number 463
  FFV1_0( w[99], w[50], w[1], COUPs[1], &amp[0] );
#ifdef MGONGPU_SUPPORTS_MULTICHANNEL
  if( channelId == 463 ) allNumerators[0] += cxabs2( amp[0] );
  if( channelId != 0 ) allDenominators[0] += cxabs2( amp[0] );
#endif
  jamp[116] += cxtype( 0, 1 ) * amp[0];
  jamp[117] -= cxtype( 0, 1 ) * amp[0];

  // *** DIAGRAM 464 OF 1240 ***

  // Wavefunction(s) for diagram number 464
  // (none)

  // Amplitude(s) for diagram number 464
  FFV1_0( w[3], w[91], w[62], COUPs[1], &amp[0] );
#ifdef MGONGPU_SUPPORTS_MULTICHANNEL
  if( channelId == 464 ) allNumerators[0] += cxabs2( amp[0] );
  if( channelId != 0 ) allDenominators[0] += cxabs2( amp[0] );
#endif
  jamp[102] += amp[0];
  jamp[104] -= amp[0];
  jamp[106] -= amp[0];
  jamp[107] += amp[0];

  // *** DIAGRAM 465 OF 1240 ***

  // Wavefunction(s) for diagram number 465
  // (none)

  // Amplitude(s) for diagram number 465
  VVV1_0( w[62], w[1], w[51], COUPs[0], &amp[0] );
#ifdef MGONGPU_SUPPORTS_MULTICHANNEL
  if( channelId == 465 ) allNumerators[0] += cxabs2( amp[0] );
  if( channelId != 0 ) allDenominators[0] += cxabs2( amp[0] );
#endif
  jamp[99] -= cxtype( 0, 1 ) * amp[0];
  jamp[102] += cxtype( 0, 1 ) * amp[0];
  jamp[104] -= cxtype( 0, 1 ) * amp[0];
  jamp[106] -= cxtype( 0, 1 ) * amp[0];
  jamp[107] += cxtype( 0, 1 ) * amp[0];
  jamp[109] += cxtype( 0, 1 ) * amp[0];
  jamp[115] += cxtype( 0, 1 ) * amp[0];
  jamp[118] -= cxtype( 0, 1 ) * amp[0];

  // *** DIAGRAM 466 OF 1240 ***

  // Wavefunction(s) for diagram number 466
  // (none)

  // Amplitude(s) for diagram number 466
  FFV1_0( w[3], w[47], w[109], COUPs[1], &amp[0] );
  jamp[98] -= cxtype( 0, 1 ) * amp[0];
  jamp[99] += cxtype( 0, 1 ) * amp[0];
  jamp[106] += cxtype( 0, 1 ) * amp[0];
  jamp[107] -= cxtype( 0, 1 ) * amp[0];
  jamp[108] += cxtype( 0, 1 ) * amp[0];
  jamp[109] -= cxtype( 0, 1 ) * amp[0];
  jamp[116] -= cxtype( 0, 1 ) * amp[0];
  jamp[117] += cxtype( 0, 1 ) * amp[0];
  FFV1_0( w[3], w[47], w[110], COUPs[1], &amp[0] );
  jamp[99] += cxtype( 0, 1 ) * amp[0];
  jamp[102] -= cxtype( 0, 1 ) * amp[0];
  jamp[104] += cxtype( 0, 1 ) * amp[0];
  jamp[106] += cxtype( 0, 1 ) * amp[0];
  jamp[107] -= cxtype( 0, 1 ) * amp[0];
  jamp[109] -= cxtype( 0, 1 ) * amp[0];
  jamp[115] -= cxtype( 0, 1 ) * amp[0];
  jamp[118] += cxtype( 0, 1 ) * amp[0];
  FFV1_0( w[3], w[47], w[111], COUPs[1], &amp[0] );
  jamp[98] += cxtype( 0, 1 ) * amp[0];
  jamp[102] -= cxtype( 0, 1 ) * amp[0];
  jamp[104] += cxtype( 0, 1 ) * amp[0];
  jamp[108] -= cxtype( 0, 1 ) * amp[0];
  jamp[115] -= cxtype( 0, 1 ) * amp[0];
  jamp[116] += cxtype( 0, 1 ) * amp[0];
  jamp[117] -= cxtype( 0, 1 ) * amp[0];
  jamp[118] += cxtype( 0, 1 ) * amp[0];

  // *** DIAGRAM 467 OF 1240 ***

  // Wavefunction(s) for diagram number 467
  // (none)

  // Amplitude(s) for diagram number 467
  FFV1_0( w[38], w[47], w[104], COUPs[1], &amp[0] );
#ifdef MGONGPU_SUPPORTS_MULTICHANNEL
  if( channelId == 467 ) allNumerators[0] += cxabs2( amp[0] );
  if( channelId != 0 ) allDenominators[0] += cxabs2( amp[0] );
#endif
  jamp[98] += amp[0];
  jamp[102] -= amp[0];
  jamp[104] += amp[0];
  jamp[108] -= amp[0];

  // *** DIAGRAM 468 OF 1240 ***

  // Wavefunction(s) for diagram number 468
  // (none)

  // Amplitude(s) for diagram number 468
  FFV1_0( w[38], w[106], w[1], COUPs[1], &amp[0] );
#ifdef MGONGPU_SUPPORTS_MULTICHANNEL
  if( channelId == 468 ) allNumerators[0] += cxabs2( amp[0] );
  if( channelId != 0 ) allDenominators[0] += cxabs2( amp[0] );
#endif
  jamp[98] += cxtype( 0, 1 ) * amp[0];
  jamp[108] -= cxtype( 0, 1 ) * amp[0];

  // *** DIAGRAM 469 OF 1240 ***

  // Wavefunction(s) for diagram number 469
  // (none)

  // Amplitude(s) for diagram number 469
  FFV1_0( w[98], w[47], w[1], COUPs[1], &amp[0] );
#ifdef MGONGPU_SUPPORTS_MULTICHANNEL
  if( channelId == 469 ) allNumerators[0] += cxabs2( amp[0] );
  if( channelId != 0 ) allDenominators[0] += cxabs2( amp[0] );
#endif
  jamp[102] += cxtype( 0, 1 ) * amp[0];
  jamp[104] -= cxtype( 0, 1 ) * amp[0];

  // *** DIAGRAM 470 OF 1240 ***

  // Wavefunction(s) for diagram number 470
  // (none)

  // Amplitude(s) for diagram number 470
  VVV1_0( w[104], w[23], w[6], COUPs[0], &amp[0] );
#ifdef MGONGPU_SUPPORTS_MULTICHANNEL
  if( channelId == 470 ) allNumerators[0] += cxabs2( amp[0] );
  if( channelId != 0 ) allDenominators[0] += cxabs2( amp[0] );
#endif
  jamp[7] += cxtype( 0, 1 ) * amp[0];
  jamp[25] -= cxtype( 0, 1 ) * amp[0];
  jamp[31] += cxtype( 0, 1 ) * amp[0];
  jamp[49] -= cxtype( 0, 1 ) * amp[0];
  jamp[98] -= cxtype( 0, 1 ) * amp[0];
  jamp[102] += cxtype( 0, 1 ) * amp[0];
  jamp[104] -= cxtype( 0, 1 ) * amp[0];
  jamp[108] += cxtype( 0, 1 ) * amp[0];

  // *** DIAGRAM 471 OF 1240 ***

  // Wavefunction(s) for diagram number 471
  // (none)

  // Amplitude(s) for diagram number 471
  FFV1_0( w[48], w[2], w[104], COUPs[1], &amp[0] );
#ifdef MGONGPU_SUPPORTS_MULTICHANNEL
  if( channelId == 471 ) allNumerators[0] += cxabs2( amp[0] );
  if( channelId != 0 ) allDenominators[0] += cxabs2( amp[0] );
#endif
  jamp[7] += amp[0];
  jamp[25] -= amp[0];
  jamp[31] += amp[0];
  jamp[49] -= amp[0];

  // *** DIAGRAM 472 OF 1240 ***

  // Wavefunction(s) for diagram number 472
  // (none)

  // Amplitude(s) for diagram number 472
  FFV1_0( w[58], w[102], w[6], COUPs[1], &amp[0] );
#ifdef MGONGPU_SUPPORTS_MULTICHANNEL
  if( channelId == 472 ) allNumerators[0] += cxabs2( amp[0] );
  if( channelId != 0 ) allDenominators[0] += cxabs2( amp[0] );
#endif
  jamp[10] += cxtype( 0, 1 ) * amp[0];
  jamp[52] -= cxtype( 0, 1 ) * amp[0];

  // *** DIAGRAM 473 OF 1240 ***

  // Wavefunction(s) for diagram number 473
  // (none)

  // Amplitude(s) for diagram number 473
  FFV1_0( w[48], w[102], w[1], COUPs[1], &amp[0] );
#ifdef MGONGPU_SUPPORTS_MULTICHANNEL
  if( channelId == 473 ) allNumerators[0] += cxabs2( amp[0] );
  if( channelId != 0 ) allDenominators[0] += cxabs2( amp[0] );
#endif
  jamp[7] += cxtype( 0, 1 ) * amp[0];
  jamp[49] -= cxtype( 0, 1 ) * amp[0];

  // *** DIAGRAM 474 OF 1240 ***

  // Wavefunction(s) for diagram number 474
  // (none)

  // Amplitude(s) for diagram number 474
  FFV1_0( w[58], w[2], w[86], COUPs[1], &amp[0] );
#ifdef MGONGPU_SUPPORTS_MULTICHANNEL
  if( channelId == 474 ) allNumerators[0] += cxabs2( amp[0] );
  if( channelId != 0 ) allDenominators[0] += cxabs2( amp[0] );
#endif
  jamp[10] += amp[0];
  jamp[52] -= amp[0];
  jamp[98] -= amp[0];
  jamp[108] += amp[0];

  // *** DIAGRAM 475 OF 1240 ***

  // Wavefunction(s) for diagram number 475
  // (none)

  // Amplitude(s) for diagram number 475
  VVV1_0( w[86], w[1], w[23], COUPs[0], &amp[0] );
#ifdef MGONGPU_SUPPORTS_MULTICHANNEL
  if( channelId == 475 ) allNumerators[0] += cxabs2( amp[0] );
  if( channelId != 0 ) allDenominators[0] += cxabs2( amp[0] );
#endif
  jamp[10] -= cxtype( 0, 1 ) * amp[0];
  jamp[25] += cxtype( 0, 1 ) * amp[0];
  jamp[31] -= cxtype( 0, 1 ) * amp[0];
  jamp[42] -= cxtype( 0, 1 ) * amp[0];
  jamp[44] += cxtype( 0, 1 ) * amp[0];
  jamp[52] += cxtype( 0, 1 ) * amp[0];
  jamp[98] += cxtype( 0, 1 ) * amp[0];
  jamp[108] -= cxtype( 0, 1 ) * amp[0];

  // *** DIAGRAM 476 OF 1240 ***

  // Wavefunction(s) for diagram number 476
  // (none)

  // Amplitude(s) for diagram number 476
  FFV1_0( w[38], w[2], w[112], COUPs[1], &amp[0] );
  jamp[7] -= cxtype( 0, 1 ) * amp[0];
  jamp[10] += cxtype( 0, 1 ) * amp[0];
  jamp[42] += cxtype( 0, 1 ) * amp[0];
  jamp[44] -= cxtype( 0, 1 ) * amp[0];
  jamp[49] += cxtype( 0, 1 ) * amp[0];
  jamp[52] -= cxtype( 0, 1 ) * amp[0];
  jamp[102] -= cxtype( 0, 1 ) * amp[0];
  jamp[104] += cxtype( 0, 1 ) * amp[0];
  FFV1_0( w[38], w[2], w[113], COUPs[1], &amp[0] );
  jamp[10] += cxtype( 0, 1 ) * amp[0];
  jamp[25] -= cxtype( 0, 1 ) * amp[0];
  jamp[31] += cxtype( 0, 1 ) * amp[0];
  jamp[42] += cxtype( 0, 1 ) * amp[0];
  jamp[44] -= cxtype( 0, 1 ) * amp[0];
  jamp[52] -= cxtype( 0, 1 ) * amp[0];
  jamp[98] -= cxtype( 0, 1 ) * amp[0];
  jamp[108] += cxtype( 0, 1 ) * amp[0];
  FFV1_0( w[38], w[2], w[114], COUPs[1], &amp[0] );
  jamp[7] += cxtype( 0, 1 ) * amp[0];
  jamp[25] -= cxtype( 0, 1 ) * amp[0];
  jamp[31] += cxtype( 0, 1 ) * amp[0];
  jamp[49] -= cxtype( 0, 1 ) * amp[0];
  jamp[98] -= cxtype( 0, 1 ) * amp[0];
  jamp[102] += cxtype( 0, 1 ) * amp[0];
  jamp[104] -= cxtype( 0, 1 ) * amp[0];
  jamp[108] += cxtype( 0, 1 ) * amp[0];

  // *** DIAGRAM 477 OF 1240 ***

  // Wavefunction(s) for diagram number 477
  // (none)

  // Amplitude(s) for diagram number 477
  VVV1_0( w[104], w[20], w[5], COUPs[0], &amp[0] );
#ifdef MGONGPU_SUPPORTS_MULTICHANNEL
  if( channelId == 477 ) allNumerators[0] += cxabs2( amp[0] );
  if( channelId != 0 ) allDenominators[0] += cxabs2( amp[0] );
#endif
  jamp[6] += cxtype( 0, 1 ) * amp[0];
  jamp[24] -= cxtype( 0, 1 ) * amp[0];
  jamp[30] += cxtype( 0, 1 ) * amp[0];
  jamp[48] -= cxtype( 0, 1 ) * amp[0];
  jamp[74] -= cxtype( 0, 1 ) * amp[0];
  jamp[78] += cxtype( 0, 1 ) * amp[0];
  jamp[80] -= cxtype( 0, 1 ) * amp[0];
  jamp[84] += cxtype( 0, 1 ) * amp[0];

  // *** DIAGRAM 478 OF 1240 ***

  // Wavefunction(s) for diagram number 478
  // (none)

  // Amplitude(s) for diagram number 478
  FFV1_0( w[40], w[2], w[104], COUPs[1], &amp[0] );
#ifdef MGONGPU_SUPPORTS_MULTICHANNEL
  if( channelId == 478 ) allNumerators[0] += cxabs2( amp[0] );
  if( channelId != 0 ) allDenominators[0] += cxabs2( amp[0] );
#endif
  jamp[6] += amp[0];
  jamp[24] -= amp[0];
  jamp[30] += amp[0];
  jamp[48] -= amp[0];

  // *** DIAGRAM 479 OF 1240 ***

  // Wavefunction(s) for diagram number 479
  // (none)

  // Amplitude(s) for diagram number 479
  FFV1_0( w[60], w[102], w[5], COUPs[1], &amp[0] );
#ifdef MGONGPU_SUPPORTS_MULTICHANNEL
  if( channelId == 479 ) allNumerators[0] += cxabs2( amp[0] );
  if( channelId != 0 ) allDenominators[0] += cxabs2( amp[0] );
#endif
  jamp[8] += cxtype( 0, 1 ) * amp[0];
  jamp[50] -= cxtype( 0, 1 ) * amp[0];

  // *** DIAGRAM 480 OF 1240 ***

  // Wavefunction(s) for diagram number 480
  // (none)

  // Amplitude(s) for diagram number 480
  FFV1_0( w[40], w[102], w[1], COUPs[1], &amp[0] );
#ifdef MGONGPU_SUPPORTS_MULTICHANNEL
  if( channelId == 480 ) allNumerators[0] += cxabs2( amp[0] );
  if( channelId != 0 ) allDenominators[0] += cxabs2( amp[0] );
#endif
  jamp[6] += cxtype( 0, 1 ) * amp[0];
  jamp[48] -= cxtype( 0, 1 ) * amp[0];

  // *** DIAGRAM 481 OF 1240 ***

  // Wavefunction(s) for diagram number 481
  // (none)

  // Amplitude(s) for diagram number 481
  FFV1_0( w[60], w[2], w[62], COUPs[1], &amp[0] );
#ifdef MGONGPU_SUPPORTS_MULTICHANNEL
  if( channelId == 481 ) allNumerators[0] += cxabs2( amp[0] );
  if( channelId != 0 ) allDenominators[0] += cxabs2( amp[0] );
#endif
  jamp[8] += amp[0];
  jamp[50] -= amp[0];
  jamp[74] -= amp[0];
  jamp[84] += amp[0];

  // *** DIAGRAM 482 OF 1240 ***

  // Wavefunction(s) for diagram number 482
  // (none)

  // Amplitude(s) for diagram number 482
  VVV1_0( w[62], w[1], w[20], COUPs[0], &amp[0] );
#ifdef MGONGPU_SUPPORTS_MULTICHANNEL
  if( channelId == 482 ) allNumerators[0] += cxabs2( amp[0] );
  if( channelId != 0 ) allDenominators[0] += cxabs2( amp[0] );
#endif
  jamp[8] -= cxtype( 0, 1 ) * amp[0];
  jamp[24] += cxtype( 0, 1 ) * amp[0];
  jamp[30] -= cxtype( 0, 1 ) * amp[0];
  jamp[36] -= cxtype( 0, 1 ) * amp[0];
  jamp[38] += cxtype( 0, 1 ) * amp[0];
  jamp[50] += cxtype( 0, 1 ) * amp[0];
  jamp[74] += cxtype( 0, 1 ) * amp[0];
  jamp[84] -= cxtype( 0, 1 ) * amp[0];

  // *** DIAGRAM 483 OF 1240 ***

  // Wavefunction(s) for diagram number 483
  // (none)

  // Amplitude(s) for diagram number 483
  FFV1_0( w[41], w[2], w[109], COUPs[1], &amp[0] );
  jamp[6] -= cxtype( 0, 1 ) * amp[0];
  jamp[8] += cxtype( 0, 1 ) * amp[0];
  jamp[36] += cxtype( 0, 1 ) * amp[0];
  jamp[38] -= cxtype( 0, 1 ) * amp[0];
  jamp[48] += cxtype( 0, 1 ) * amp[0];
  jamp[50] -= cxtype( 0, 1 ) * amp[0];
  jamp[78] -= cxtype( 0, 1 ) * amp[0];
  jamp[80] += cxtype( 0, 1 ) * amp[0];
  FFV1_0( w[41], w[2], w[110], COUPs[1], &amp[0] );
  jamp[8] += cxtype( 0, 1 ) * amp[0];
  jamp[24] -= cxtype( 0, 1 ) * amp[0];
  jamp[30] += cxtype( 0, 1 ) * amp[0];
  jamp[36] += cxtype( 0, 1 ) * amp[0];
  jamp[38] -= cxtype( 0, 1 ) * amp[0];
  jamp[50] -= cxtype( 0, 1 ) * amp[0];
  jamp[74] -= cxtype( 0, 1 ) * amp[0];
  jamp[84] += cxtype( 0, 1 ) * amp[0];
  FFV1_0( w[41], w[2], w[111], COUPs[1], &amp[0] );
  jamp[6] += cxtype( 0, 1 ) * amp[0];
  jamp[24] -= cxtype( 0, 1 ) * amp[0];
  jamp[30] += cxtype( 0, 1 ) * amp[0];
  jamp[48] -= cxtype( 0, 1 ) * amp[0];
  jamp[74] -= cxtype( 0, 1 ) * amp[0];
  jamp[78] += cxtype( 0, 1 ) * amp[0];
  jamp[80] -= cxtype( 0, 1 ) * amp[0];
  jamp[84] += cxtype( 0, 1 ) * amp[0];

  // *** DIAGRAM 484 OF 1240 ***

  // Wavefunction(s) for diagram number 484
  // (none)

  // Amplitude(s) for diagram number 484
  FFV1_0( w[3], w[18], w[104], COUPs[1], &amp[0] );
#ifdef MGONGPU_SUPPORTS_MULTICHANNEL
  if( channelId == 484 ) allNumerators[0] += cxabs2( amp[0] );
  if( channelId != 0 ) allDenominators[0] += cxabs2( amp[0] );
#endif
  jamp[91] -= cxtype( 0, 1 ) * amp[0];
  jamp[92] += cxtype( 0, 1 ) * amp[0];
  jamp[93] -= cxtype( 0, 1 ) * amp[0];
  jamp[94] += cxtype( 0, 1 ) * amp[0];
  jamp[115] += cxtype( 0, 1 ) * amp[0];
  jamp[116] -= cxtype( 0, 1 ) * amp[0];
  jamp[117] += cxtype( 0, 1 ) * amp[0];
  jamp[118] -= cxtype( 0, 1 ) * amp[0];

  // *** DIAGRAM 485 OF 1240 ***

  // Wavefunction(s) for diagram number 485
  // (none)

  // Amplitude(s) for diagram number 485
  FFV1_0( w[12], w[2], w[104], COUPs[1], &amp[0] );
#ifdef MGONGPU_SUPPORTS_MULTICHANNEL
  if( channelId == 485 ) allNumerators[0] += cxabs2( amp[0] );
  if( channelId != 0 ) allDenominators[0] += cxabs2( amp[0] );
#endif
  jamp[6] -= cxtype( 0, 1 ) * amp[0];
  jamp[7] += cxtype( 0, 1 ) * amp[0];
  jamp[24] += cxtype( 0, 1 ) * amp[0];
  jamp[25] -= cxtype( 0, 1 ) * amp[0];
  jamp[30] -= cxtype( 0, 1 ) * amp[0];
  jamp[31] += cxtype( 0, 1 ) * amp[0];
  jamp[48] += cxtype( 0, 1 ) * amp[0];
  jamp[49] -= cxtype( 0, 1 ) * amp[0];

  // *** DIAGRAM 486 OF 1240 ***

  // Wavefunction(s) for diagram number 486
  // (none)

  // Amplitude(s) for diagram number 486
  FFV1_0( w[3], w[102], w[67], COUPs[1], &amp[0] );
#ifdef MGONGPU_SUPPORTS_MULTICHANNEL
  if( channelId == 486 ) allNumerators[0] += cxabs2( amp[0] );
  if( channelId != 0 ) allDenominators[0] += cxabs2( amp[0] );
#endif
  jamp[6] -= cxtype( 0, 1 ) * amp[0];
  jamp[7] += cxtype( 0, 1 ) * amp[0];
  jamp[9] += cxtype( 0, 1 ) * amp[0];
  jamp[11] -= cxtype( 0, 1 ) * amp[0];
  jamp[48] += cxtype( 0, 1 ) * amp[0];
  jamp[49] -= cxtype( 0, 1 ) * amp[0];
  jamp[51] -= cxtype( 0, 1 ) * amp[0];
  jamp[53] += cxtype( 0, 1 ) * amp[0];

  // *** DIAGRAM 487 OF 1240 ***

  // Wavefunction(s) for diagram number 487
  // (none)

  // Amplitude(s) for diagram number 487
  FFV1_0( w[12], w[102], w[1], COUPs[1], &amp[0] );
#ifdef MGONGPU_SUPPORTS_MULTICHANNEL
  if( channelId == 487 ) allNumerators[0] += cxabs2( amp[0] );
  if( channelId != 0 ) allDenominators[0] += cxabs2( amp[0] );
#endif
  jamp[6] += amp[0];
  jamp[7] -= amp[0];
  jamp[48] -= amp[0];
  jamp[49] += amp[0];

  // *** DIAGRAM 488 OF 1240 ***

  // Wavefunction(s) for diagram number 488
  // (none)

  // Amplitude(s) for diagram number 488
  FFV1_0( w[99], w[2], w[67], COUPs[1], &amp[0] );
#ifdef MGONGPU_SUPPORTS_MULTICHANNEL
  if( channelId == 488 ) allNumerators[0] += cxabs2( amp[0] );
  if( channelId != 0 ) allDenominators[0] += cxabs2( amp[0] );
#endif
  jamp[40] -= cxtype( 0, 1 ) * amp[0];
  jamp[41] += cxtype( 0, 1 ) * amp[0];
  jamp[46] += cxtype( 0, 1 ) * amp[0];
  jamp[47] -= cxtype( 0, 1 ) * amp[0];
  jamp[92] += cxtype( 0, 1 ) * amp[0];
  jamp[93] -= cxtype( 0, 1 ) * amp[0];
  jamp[116] -= cxtype( 0, 1 ) * amp[0];
  jamp[117] += cxtype( 0, 1 ) * amp[0];

  // *** DIAGRAM 489 OF 1240 ***

  // Wavefunction(s) for diagram number 489
  // (none)

  // Amplitude(s) for diagram number 489
  FFV1_0( w[99], w[18], w[1], COUPs[1], &amp[0] );
#ifdef MGONGPU_SUPPORTS_MULTICHANNEL
  if( channelId == 489 ) allNumerators[0] += cxabs2( amp[0] );
  if( channelId != 0 ) allDenominators[0] += cxabs2( amp[0] );
#endif
  jamp[92] += amp[0];
  jamp[93] -= amp[0];
  jamp[116] -= amp[0];
  jamp[117] += amp[0];

  // *** DIAGRAM 490 OF 1240 ***

  // Wavefunction(s) for diagram number 490
  // (none)

  // Amplitude(s) for diagram number 490
  FFV1_0( w[3], w[102], w[55], COUPs[1], &amp[0] );
  jamp[6] -= cxtype( 0, 1 ) * amp[0];
  jamp[7] += cxtype( 0, 1 ) * amp[0];
  jamp[9] += cxtype( 0, 1 ) * amp[0];
  jamp[11] -= cxtype( 0, 1 ) * amp[0];
  jamp[48] += cxtype( 0, 1 ) * amp[0];
  jamp[49] -= cxtype( 0, 1 ) * amp[0];
  jamp[51] -= cxtype( 0, 1 ) * amp[0];
  jamp[53] += cxtype( 0, 1 ) * amp[0];
  FFV1_0( w[3], w[102], w[83], COUPs[1], &amp[0] );
  jamp[7] += cxtype( 0, 1 ) * amp[0];
  jamp[8] -= cxtype( 0, 1 ) * amp[0];
  jamp[9] += cxtype( 0, 1 ) * amp[0];
  jamp[10] -= cxtype( 0, 1 ) * amp[0];
  jamp[49] -= cxtype( 0, 1 ) * amp[0];
  jamp[50] += cxtype( 0, 1 ) * amp[0];
  jamp[51] -= cxtype( 0, 1 ) * amp[0];
  jamp[52] += cxtype( 0, 1 ) * amp[0];
  FFV1_0( w[3], w[102], w[84], COUPs[1], &amp[0] );
  jamp[6] += cxtype( 0, 1 ) * amp[0];
  jamp[8] -= cxtype( 0, 1 ) * amp[0];
  jamp[10] -= cxtype( 0, 1 ) * amp[0];
  jamp[11] += cxtype( 0, 1 ) * amp[0];
  jamp[48] -= cxtype( 0, 1 ) * amp[0];
  jamp[50] += cxtype( 0, 1 ) * amp[0];
  jamp[52] += cxtype( 0, 1 ) * amp[0];
  jamp[53] -= cxtype( 0, 1 ) * amp[0];

  // *** DIAGRAM 491 OF 1240 ***

  // Wavefunction(s) for diagram number 491
  // (none)

  // Amplitude(s) for diagram number 491
  FFV1_0( w[99], w[2], w[55], COUPs[1], &amp[0] );
  jamp[40] -= cxtype( 0, 1 ) * amp[0];
  jamp[41] += cxtype( 0, 1 ) * amp[0];
  jamp[46] += cxtype( 0, 1 ) * amp[0];
  jamp[47] -= cxtype( 0, 1 ) * amp[0];
  jamp[92] += cxtype( 0, 1 ) * amp[0];
  jamp[93] -= cxtype( 0, 1 ) * amp[0];
  jamp[116] -= cxtype( 0, 1 ) * amp[0];
  jamp[117] += cxtype( 0, 1 ) * amp[0];
  FFV1_0( w[99], w[2], w[83], COUPs[1], &amp[0] );
  jamp[46] += cxtype( 0, 1 ) * amp[0];
  jamp[47] -= cxtype( 0, 1 ) * amp[0];
  jamp[82] -= cxtype( 0, 1 ) * amp[0];
  jamp[83] += cxtype( 0, 1 ) * amp[0];
  jamp[92] += cxtype( 0, 1 ) * amp[0];
  jamp[93] -= cxtype( 0, 1 ) * amp[0];
  jamp[106] -= cxtype( 0, 1 ) * amp[0];
  jamp[107] += cxtype( 0, 1 ) * amp[0];
  FFV1_0( w[99], w[2], w[84], COUPs[1], &amp[0] );
  jamp[40] += cxtype( 0, 1 ) * amp[0];
  jamp[41] -= cxtype( 0, 1 ) * amp[0];
  jamp[82] -= cxtype( 0, 1 ) * amp[0];
  jamp[83] += cxtype( 0, 1 ) * amp[0];
  jamp[106] -= cxtype( 0, 1 ) * amp[0];
  jamp[107] += cxtype( 0, 1 ) * amp[0];
  jamp[116] += cxtype( 0, 1 ) * amp[0];
  jamp[117] -= cxtype( 0, 1 ) * amp[0];

  // *** DIAGRAM 492 OF 1240 ***

  // Wavefunction(s) for diagram number 492
  // (none)

  // Amplitude(s) for diagram number 492
  VVV1_0( w[92], w[55], w[8], COUPs[0], &amp[0] );
  jamp[6] -= amp[0];
  jamp[7] += amp[0];
  jamp[9] += amp[0];
  jamp[11] -= amp[0];
  jamp[40] += amp[0];
  jamp[41] -= amp[0];
  jamp[46] -= amp[0];
  jamp[47] += amp[0];
  jamp[48] += amp[0];
  jamp[49] -= amp[0];
  jamp[51] -= amp[0];
  jamp[53] += amp[0];
  jamp[92] -= amp[0];
  jamp[93] += amp[0];
  jamp[116] += amp[0];
  jamp[117] -= amp[0];
  VVV1_0( w[92], w[83], w[8], COUPs[0], &amp[0] );
  jamp[7] += amp[0];
  jamp[8] -= amp[0];
  jamp[9] += amp[0];
  jamp[10] -= amp[0];
  jamp[46] -= amp[0];
  jamp[47] += amp[0];
  jamp[49] -= amp[0];
  jamp[50] += amp[0];
  jamp[51] -= amp[0];
  jamp[52] += amp[0];
  jamp[82] += amp[0];
  jamp[83] -= amp[0];
  jamp[92] -= amp[0];
  jamp[93] += amp[0];
  jamp[106] += amp[0];
  jamp[107] -= amp[0];
  VVV1_0( w[92], w[84], w[8], COUPs[0], &amp[0] );
  jamp[6] += amp[0];
  jamp[8] -= amp[0];
  jamp[10] -= amp[0];
  jamp[11] += amp[0];
  jamp[40] -= amp[0];
  jamp[41] += amp[0];
  jamp[48] -= amp[0];
  jamp[50] += amp[0];
  jamp[52] += amp[0];
  jamp[53] -= amp[0];
  jamp[82] += amp[0];
  jamp[83] -= amp[0];
  jamp[106] += amp[0];
  jamp[107] -= amp[0];
  jamp[116] -= amp[0];
  jamp[117] += amp[0];

  // *** DIAGRAM 493 OF 1240 ***

  // Wavefunction(s) for diagram number 493
  VVV1P0_1( w[0], w[5], COUPs[0], 0., 0., w[92] );
  FFV1_2( w[3], w[92], COUPs[1], cIPD[0], cIPD[1], w[99] );

  // Amplitude(s) for diagram number 493
  FFV1_0( w[99], w[87], w[6], COUPs[1], &amp[0] );
#ifdef MGONGPU_SUPPORTS_MULTICHANNEL
  if( channelId == 493 ) allNumerators[0] += cxabs2( amp[0] );
  if( channelId != 0 ) allDenominators[0] += cxabs2( amp[0] );
#endif
  jamp[34] += cxtype( 0, 1 ) * amp[0];
  jamp[35] -= cxtype( 0, 1 ) * amp[0];

  // *** DIAGRAM 494 OF 1240 ***

  // Wavefunction(s) for diagram number 494
  // (none)

  // Amplitude(s) for diagram number 494
  FFV1_0( w[99], w[85], w[4], COUPs[1], &amp[0] );
#ifdef MGONGPU_SUPPORTS_MULTICHANNEL
  if( channelId == 494 ) allNumerators[0] += cxabs2( amp[0] );
  if( channelId != 0 ) allDenominators[0] += cxabs2( amp[0] );
#endif
  jamp[44] += cxtype( 0, 1 ) * amp[0];
  jamp[45] -= cxtype( 0, 1 ) * amp[0];

  // *** DIAGRAM 495 OF 1240 ***

  // Wavefunction(s) for diagram number 495
  VVV1P0_1( w[92], w[4], COUPs[0], 0., 0., w[102] );

  // Amplitude(s) for diagram number 495
  VVV1_0( w[102], w[34], w[6], COUPs[0], &amp[0] );
#ifdef MGONGPU_SUPPORTS_MULTICHANNEL
  if( channelId == 495 ) allNumerators[0] += cxabs2( amp[0] );
  if( channelId != 0 ) allDenominators[0] += cxabs2( amp[0] );
#endif
  jamp[26] += cxtype( 0, 1 ) * amp[0];
  jamp[30] -= cxtype( 0, 1 ) * amp[0];
  jamp[32] += cxtype( 0, 1 ) * amp[0];
  jamp[36] -= cxtype( 0, 1 ) * amp[0];
  jamp[43] -= cxtype( 0, 1 ) * amp[0];
  jamp[44] += cxtype( 0, 1 ) * amp[0];
  jamp[45] -= cxtype( 0, 1 ) * amp[0];
  jamp[46] += cxtype( 0, 1 ) * amp[0];

  // *** DIAGRAM 496 OF 1240 ***

  // Wavefunction(s) for diagram number 496
  // (none)

  // Amplitude(s) for diagram number 496
  FFV1_0( w[3], w[85], w[102], COUPs[1], &amp[0] );
#ifdef MGONGPU_SUPPORTS_MULTICHANNEL
  if( channelId == 496 ) allNumerators[0] += cxabs2( amp[0] );
  if( channelId != 0 ) allDenominators[0] += cxabs2( amp[0] );
#endif
  jamp[43] += amp[0];
  jamp[44] -= amp[0];
  jamp[45] += amp[0];
  jamp[46] -= amp[0];

  // *** DIAGRAM 497 OF 1240 ***

  // Wavefunction(s) for diagram number 497
  VVV1P0_1( w[92], w[6], COUPs[0], 0., 0., w[104] );

  // Amplitude(s) for diagram number 497
  VVV1_0( w[104], w[34], w[4], COUPs[0], &amp[0] );
#ifdef MGONGPU_SUPPORTS_MULTICHANNEL
  if( channelId == 497 ) allNumerators[0] += cxabs2( amp[0] );
  if( channelId != 0 ) allDenominators[0] += cxabs2( amp[0] );
#endif
  jamp[27] += cxtype( 0, 1 ) * amp[0];
  jamp[30] -= cxtype( 0, 1 ) * amp[0];
  jamp[32] += cxtype( 0, 1 ) * amp[0];
  jamp[34] += cxtype( 0, 1 ) * amp[0];
  jamp[35] -= cxtype( 0, 1 ) * amp[0];
  jamp[37] -= cxtype( 0, 1 ) * amp[0];
  jamp[43] -= cxtype( 0, 1 ) * amp[0];
  jamp[46] += cxtype( 0, 1 ) * amp[0];

  // *** DIAGRAM 498 OF 1240 ***

  // Wavefunction(s) for diagram number 498
  // (none)

  // Amplitude(s) for diagram number 498
  FFV1_0( w[3], w[87], w[104], COUPs[1], &amp[0] );
#ifdef MGONGPU_SUPPORTS_MULTICHANNEL
  if( channelId == 498 ) allNumerators[0] += cxabs2( amp[0] );
  if( channelId != 0 ) allDenominators[0] += cxabs2( amp[0] );
#endif
  jamp[30] += amp[0];
  jamp[32] -= amp[0];
  jamp[34] -= amp[0];
  jamp[35] += amp[0];

  // *** DIAGRAM 499 OF 1240 ***

  // Wavefunction(s) for diagram number 499
  VVVV1P0_1( w[92], w[4], w[6], COUPs[2], 0., 0., w[111] );
  VVVV3P0_1( w[92], w[4], w[6], COUPs[2], 0., 0., w[110] );
  VVVV4P0_1( w[92], w[4], w[6], COUPs[2], 0., 0., w[109] );

  // Amplitude(s) for diagram number 499
  FFV1_0( w[3], w[77], w[111], COUPs[1], &amp[0] );
  jamp[26] -= cxtype( 0, 1 ) * amp[0];
  jamp[27] += cxtype( 0, 1 ) * amp[0];
  jamp[34] += cxtype( 0, 1 ) * amp[0];
  jamp[35] -= cxtype( 0, 1 ) * amp[0];
  jamp[36] += cxtype( 0, 1 ) * amp[0];
  jamp[37] -= cxtype( 0, 1 ) * amp[0];
  jamp[44] -= cxtype( 0, 1 ) * amp[0];
  jamp[45] += cxtype( 0, 1 ) * amp[0];
  FFV1_0( w[3], w[77], w[110], COUPs[1], &amp[0] );
  jamp[27] += cxtype( 0, 1 ) * amp[0];
  jamp[30] -= cxtype( 0, 1 ) * amp[0];
  jamp[32] += cxtype( 0, 1 ) * amp[0];
  jamp[34] += cxtype( 0, 1 ) * amp[0];
  jamp[35] -= cxtype( 0, 1 ) * amp[0];
  jamp[37] -= cxtype( 0, 1 ) * amp[0];
  jamp[43] -= cxtype( 0, 1 ) * amp[0];
  jamp[46] += cxtype( 0, 1 ) * amp[0];
  FFV1_0( w[3], w[77], w[109], COUPs[1], &amp[0] );
  jamp[26] += cxtype( 0, 1 ) * amp[0];
  jamp[30] -= cxtype( 0, 1 ) * amp[0];
  jamp[32] += cxtype( 0, 1 ) * amp[0];
  jamp[36] -= cxtype( 0, 1 ) * amp[0];
  jamp[43] -= cxtype( 0, 1 ) * amp[0];
  jamp[44] += cxtype( 0, 1 ) * amp[0];
  jamp[45] -= cxtype( 0, 1 ) * amp[0];
  jamp[46] += cxtype( 0, 1 ) * amp[0];

  // *** DIAGRAM 500 OF 1240 ***

  // Wavefunction(s) for diagram number 500
  FFV1_1( w[77], w[92], COUPs[1], cIPD[0], cIPD[1], w[62] );

  // Amplitude(s) for diagram number 500
  FFV1_0( w[46], w[62], w[6], COUPs[1], &amp[0] );
#ifdef MGONGPU_SUPPORTS_MULTICHANNEL
  if( channelId == 500 ) allNumerators[0] += cxabs2( amp[0] );
  if( channelId != 0 ) allDenominators[0] += cxabs2( amp[0] );
#endif
  jamp[27] += cxtype( 0, 1 ) * amp[0];
  jamp[37] -= cxtype( 0, 1 ) * amp[0];

  // *** DIAGRAM 501 OF 1240 ***

  // Wavefunction(s) for diagram number 501
  FFV1_2( w[46], w[92], COUPs[1], cIPD[0], cIPD[1], w[114] );

  // Amplitude(s) for diagram number 501
  FFV1_0( w[114], w[77], w[6], COUPs[1], &amp[0] );
#ifdef MGONGPU_SUPPORTS_MULTICHANNEL
  if( channelId == 501 ) allNumerators[0] += cxabs2( amp[0] );
  if( channelId != 0 ) allDenominators[0] += cxabs2( amp[0] );
#endif
  jamp[43] += cxtype( 0, 1 ) * amp[0];
  jamp[46] -= cxtype( 0, 1 ) * amp[0];

  // *** DIAGRAM 502 OF 1240 ***

  // Wavefunction(s) for diagram number 502
  // (none)

  // Amplitude(s) for diagram number 502
  FFV1_0( w[46], w[77], w[104], COUPs[1], &amp[0] );
#ifdef MGONGPU_SUPPORTS_MULTICHANNEL
  if( channelId == 502 ) allNumerators[0] += cxabs2( amp[0] );
  if( channelId != 0 ) allDenominators[0] += cxabs2( amp[0] );
#endif
  jamp[27] += amp[0];
  jamp[37] -= amp[0];
  jamp[43] -= amp[0];
  jamp[46] += amp[0];

  // *** DIAGRAM 503 OF 1240 ***

  // Wavefunction(s) for diagram number 503
  // (none)

  // Amplitude(s) for diagram number 503
  FFV1_0( w[41], w[62], w[4], COUPs[1], &amp[0] );
#ifdef MGONGPU_SUPPORTS_MULTICHANNEL
  if( channelId == 503 ) allNumerators[0] += cxabs2( amp[0] );
  if( channelId != 0 ) allDenominators[0] += cxabs2( amp[0] );
#endif
  jamp[26] += cxtype( 0, 1 ) * amp[0];
  jamp[36] -= cxtype( 0, 1 ) * amp[0];

  // *** DIAGRAM 504 OF 1240 ***

  // Wavefunction(s) for diagram number 504
  FFV1_2( w[41], w[92], COUPs[1], cIPD[0], cIPD[1], w[113] );

  // Amplitude(s) for diagram number 504
  FFV1_0( w[113], w[77], w[4], COUPs[1], &amp[0] );
#ifdef MGONGPU_SUPPORTS_MULTICHANNEL
  if( channelId == 504 ) allNumerators[0] += cxabs2( amp[0] );
  if( channelId != 0 ) allDenominators[0] += cxabs2( amp[0] );
#endif
  jamp[30] += cxtype( 0, 1 ) * amp[0];
  jamp[32] -= cxtype( 0, 1 ) * amp[0];

  // *** DIAGRAM 505 OF 1240 ***

  // Wavefunction(s) for diagram number 505
  // (none)

  // Amplitude(s) for diagram number 505
  FFV1_0( w[41], w[77], w[102], COUPs[1], &amp[0] );
#ifdef MGONGPU_SUPPORTS_MULTICHANNEL
  if( channelId == 505 ) allNumerators[0] += cxabs2( amp[0] );
  if( channelId != 0 ) allDenominators[0] += cxabs2( amp[0] );
#endif
  jamp[26] += amp[0];
  jamp[30] -= amp[0];
  jamp[32] += amp[0];
  jamp[36] -= amp[0];

  // *** DIAGRAM 506 OF 1240 ***

  // Wavefunction(s) for diagram number 506
  // (none)

  // Amplitude(s) for diagram number 506
  FFV1_0( w[3], w[62], w[27], COUPs[1], &amp[0] );
#ifdef MGONGPU_SUPPORTS_MULTICHANNEL
  if( channelId == 506 ) allNumerators[0] += cxabs2( amp[0] );
  if( channelId != 0 ) allDenominators[0] += cxabs2( amp[0] );
#endif
  jamp[26] += amp[0];
  jamp[27] -= amp[0];
  jamp[36] -= amp[0];
  jamp[37] += amp[0];

  // *** DIAGRAM 507 OF 1240 ***

  // Wavefunction(s) for diagram number 507
  // (none)

  // Amplitude(s) for diagram number 507
  FFV1_0( w[99], w[77], w[27], COUPs[1], &amp[0] );
#ifdef MGONGPU_SUPPORTS_MULTICHANNEL
  if( channelId == 507 ) allNumerators[0] += cxabs2( amp[0] );
  if( channelId != 0 ) allDenominators[0] += cxabs2( amp[0] );
#endif
  jamp[34] += amp[0];
  jamp[35] -= amp[0];
  jamp[44] -= amp[0];
  jamp[45] += amp[0];

  // *** DIAGRAM 508 OF 1240 ***

  // Wavefunction(s) for diagram number 508
  VVV1P0_1( w[92], w[27], COUPs[0], 0., 0., w[62] );

  // Amplitude(s) for diagram number 508
  FFV1_0( w[3], w[77], w[62], COUPs[1], &amp[0] );
#ifdef MGONGPU_SUPPORTS_MULTICHANNEL
  if( channelId == 508 ) allNumerators[0] += cxabs2( amp[0] );
  if( channelId != 0 ) allDenominators[0] += cxabs2( amp[0] );
#endif
  jamp[26] -= cxtype( 0, 1 ) * amp[0];
  jamp[27] += cxtype( 0, 1 ) * amp[0];
  jamp[34] += cxtype( 0, 1 ) * amp[0];
  jamp[35] -= cxtype( 0, 1 ) * amp[0];
  jamp[36] += cxtype( 0, 1 ) * amp[0];
  jamp[37] -= cxtype( 0, 1 ) * amp[0];
  jamp[44] -= cxtype( 0, 1 ) * amp[0];
  jamp[45] += cxtype( 0, 1 ) * amp[0];

  // *** DIAGRAM 509 OF 1240 ***

  // Wavefunction(s) for diagram number 509
  FFV1_1( w[2], w[92], COUPs[1], cIPD[0], cIPD[1], w[112] );

  // Amplitude(s) for diagram number 509
  FFV1_0( w[56], w[112], w[6], COUPs[1], &amp[0] );
#ifdef MGONGPU_SUPPORTS_MULTICHANNEL
  if( channelId == 509 ) allNumerators[0] += cxabs2( amp[0] );
  if( channelId != 0 ) allDenominators[0] += cxabs2( amp[0] );
#endif
  jamp[17] += cxtype( 0, 1 ) * amp[0];
  jamp[77] -= cxtype( 0, 1 ) * amp[0];

  // *** DIAGRAM 510 OF 1240 ***

  // Wavefunction(s) for diagram number 510
  // (none)

  // Amplitude(s) for diagram number 510
  FFV1_0( w[21], w[112], w[4], COUPs[1], &amp[0] );
#ifdef MGONGPU_SUPPORTS_MULTICHANNEL
  if( channelId == 510 ) allNumerators[0] += cxabs2( amp[0] );
  if( channelId != 0 ) allDenominators[0] += cxabs2( amp[0] );
#endif
  jamp[15] += cxtype( 0, 1 ) * amp[0];
  jamp[75] -= cxtype( 0, 1 ) * amp[0];

  // *** DIAGRAM 511 OF 1240 ***

  // Wavefunction(s) for diagram number 511
  // (none)

  // Amplitude(s) for diagram number 511
  VVV1_0( w[102], w[103], w[6], COUPs[0], &amp[0] );
#ifdef MGONGPU_SUPPORTS_MULTICHANNEL
  if( channelId == 511 ) allNumerators[0] += cxabs2( amp[0] );
  if( channelId != 0 ) allDenominators[0] += cxabs2( amp[0] );
#endif
  jamp[15] += cxtype( 0, 1 ) * amp[0];
  jamp[51] -= cxtype( 0, 1 ) * amp[0];
  jamp[61] += cxtype( 0, 1 ) * amp[0];
  jamp[75] -= cxtype( 0, 1 ) * amp[0];
  jamp[101] -= cxtype( 0, 1 ) * amp[0];
  jamp[109] += cxtype( 0, 1 ) * amp[0];
  jamp[112] -= cxtype( 0, 1 ) * amp[0];
  jamp[115] += cxtype( 0, 1 ) * amp[0];

  // *** DIAGRAM 512 OF 1240 ***

  // Wavefunction(s) for diagram number 512
  // (none)

  // Amplitude(s) for diagram number 512
  FFV1_0( w[21], w[2], w[102], COUPs[1], &amp[0] );
#ifdef MGONGPU_SUPPORTS_MULTICHANNEL
  if( channelId == 512 ) allNumerators[0] += cxabs2( amp[0] );
  if( channelId != 0 ) allDenominators[0] += cxabs2( amp[0] );
#endif
  jamp[15] += amp[0];
  jamp[51] -= amp[0];
  jamp[61] += amp[0];
  jamp[75] -= amp[0];

  // *** DIAGRAM 513 OF 1240 ***

  // Wavefunction(s) for diagram number 513
  // (none)

  // Amplitude(s) for diagram number 513
  VVV1_0( w[104], w[103], w[4], COUPs[0], &amp[0] );
#ifdef MGONGPU_SUPPORTS_MULTICHANNEL
  if( channelId == 513 ) allNumerators[0] += cxabs2( amp[0] );
  if( channelId != 0 ) allDenominators[0] += cxabs2( amp[0] );
#endif
  jamp[17] += cxtype( 0, 1 ) * amp[0];
  jamp[51] -= cxtype( 0, 1 ) * amp[0];
  jamp[61] += cxtype( 0, 1 ) * amp[0];
  jamp[67] += cxtype( 0, 1 ) * amp[0];
  jamp[70] -= cxtype( 0, 1 ) * amp[0];
  jamp[77] -= cxtype( 0, 1 ) * amp[0];
  jamp[101] -= cxtype( 0, 1 ) * amp[0];
  jamp[115] += cxtype( 0, 1 ) * amp[0];

  // *** DIAGRAM 514 OF 1240 ***

  // Wavefunction(s) for diagram number 514
  // (none)

  // Amplitude(s) for diagram number 514
  FFV1_0( w[56], w[2], w[104], COUPs[1], &amp[0] );
#ifdef MGONGPU_SUPPORTS_MULTICHANNEL
  if( channelId == 514 ) allNumerators[0] += cxabs2( amp[0] );
  if( channelId != 0 ) allDenominators[0] += cxabs2( amp[0] );
#endif
  jamp[17] += amp[0];
  jamp[77] -= amp[0];
  jamp[101] -= amp[0];
  jamp[115] += amp[0];

  // *** DIAGRAM 515 OF 1240 ***

  // Wavefunction(s) for diagram number 515
  // (none)

  // Amplitude(s) for diagram number 515
  FFV1_0( w[52], w[2], w[111], COUPs[1], &amp[0] );
  jamp[15] -= cxtype( 0, 1 ) * amp[0];
  jamp[17] += cxtype( 0, 1 ) * amp[0];
  jamp[67] += cxtype( 0, 1 ) * amp[0];
  jamp[70] -= cxtype( 0, 1 ) * amp[0];
  jamp[75] += cxtype( 0, 1 ) * amp[0];
  jamp[77] -= cxtype( 0, 1 ) * amp[0];
  jamp[109] -= cxtype( 0, 1 ) * amp[0];
  jamp[112] += cxtype( 0, 1 ) * amp[0];
  FFV1_0( w[52], w[2], w[110], COUPs[1], &amp[0] );
  jamp[17] += cxtype( 0, 1 ) * amp[0];
  jamp[51] -= cxtype( 0, 1 ) * amp[0];
  jamp[61] += cxtype( 0, 1 ) * amp[0];
  jamp[67] += cxtype( 0, 1 ) * amp[0];
  jamp[70] -= cxtype( 0, 1 ) * amp[0];
  jamp[77] -= cxtype( 0, 1 ) * amp[0];
  jamp[101] -= cxtype( 0, 1 ) * amp[0];
  jamp[115] += cxtype( 0, 1 ) * amp[0];
  FFV1_0( w[52], w[2], w[109], COUPs[1], &amp[0] );
  jamp[15] += cxtype( 0, 1 ) * amp[0];
  jamp[51] -= cxtype( 0, 1 ) * amp[0];
  jamp[61] += cxtype( 0, 1 ) * amp[0];
  jamp[75] -= cxtype( 0, 1 ) * amp[0];
  jamp[101] -= cxtype( 0, 1 ) * amp[0];
  jamp[109] += cxtype( 0, 1 ) * amp[0];
  jamp[112] -= cxtype( 0, 1 ) * amp[0];
  jamp[115] += cxtype( 0, 1 ) * amp[0];

  // *** DIAGRAM 516 OF 1240 ***

  // Wavefunction(s) for diagram number 516
  FFV1_2( w[52], w[92], COUPs[1], cIPD[0], cIPD[1], w[86] );

  // Amplitude(s) for diagram number 516
  FFV1_0( w[86], w[33], w[6], COUPs[1], &amp[0] );
#ifdef MGONGPU_SUPPORTS_MULTICHANNEL
  if( channelId == 516 ) allNumerators[0] += cxabs2( amp[0] );
  if( channelId != 0 ) allDenominators[0] += cxabs2( amp[0] );
#endif
  jamp[67] += cxtype( 0, 1 ) * amp[0];
  jamp[70] -= cxtype( 0, 1 ) * amp[0];

  // *** DIAGRAM 517 OF 1240 ***

  // Wavefunction(s) for diagram number 517
  FFV1_1( w[33], w[92], COUPs[1], cIPD[0], cIPD[1], w[98] );

  // Amplitude(s) for diagram number 517
  FFV1_0( w[52], w[98], w[6], COUPs[1], &amp[0] );
#ifdef MGONGPU_SUPPORTS_MULTICHANNEL
  if( channelId == 517 ) allNumerators[0] += cxabs2( amp[0] );
  if( channelId != 0 ) allDenominators[0] += cxabs2( amp[0] );
#endif
  jamp[51] += cxtype( 0, 1 ) * amp[0];
  jamp[61] -= cxtype( 0, 1 ) * amp[0];

  // *** DIAGRAM 518 OF 1240 ***

  // Wavefunction(s) for diagram number 518
  // (none)

  // Amplitude(s) for diagram number 518
  FFV1_0( w[52], w[33], w[104], COUPs[1], &amp[0] );
#ifdef MGONGPU_SUPPORTS_MULTICHANNEL
  if( channelId == 518 ) allNumerators[0] += cxabs2( amp[0] );
  if( channelId != 0 ) allDenominators[0] += cxabs2( amp[0] );
#endif
  jamp[51] += amp[0];
  jamp[61] -= amp[0];
  jamp[67] -= amp[0];
  jamp[70] += amp[0];

  // *** DIAGRAM 519 OF 1240 ***

  // Wavefunction(s) for diagram number 519
  // (none)

  // Amplitude(s) for diagram number 519
  FFV1_0( w[86], w[47], w[4], COUPs[1], &amp[0] );
#ifdef MGONGPU_SUPPORTS_MULTICHANNEL
  if( channelId == 519 ) allNumerators[0] += cxabs2( amp[0] );
  if( channelId != 0 ) allDenominators[0] += cxabs2( amp[0] );
#endif
  jamp[109] += cxtype( 0, 1 ) * amp[0];
  jamp[112] -= cxtype( 0, 1 ) * amp[0];

  // *** DIAGRAM 520 OF 1240 ***

  // Wavefunction(s) for diagram number 520
  FFV1_1( w[47], w[92], COUPs[1], cIPD[0], cIPD[1], w[106] );

  // Amplitude(s) for diagram number 520
  FFV1_0( w[52], w[106], w[4], COUPs[1], &amp[0] );
#ifdef MGONGPU_SUPPORTS_MULTICHANNEL
  if( channelId == 520 ) allNumerators[0] += cxabs2( amp[0] );
  if( channelId != 0 ) allDenominators[0] += cxabs2( amp[0] );
#endif
  jamp[101] += cxtype( 0, 1 ) * amp[0];
  jamp[115] -= cxtype( 0, 1 ) * amp[0];

  // *** DIAGRAM 521 OF 1240 ***

  // Wavefunction(s) for diagram number 521
  // (none)

  // Amplitude(s) for diagram number 521
  FFV1_0( w[52], w[47], w[102], COUPs[1], &amp[0] );
#ifdef MGONGPU_SUPPORTS_MULTICHANNEL
  if( channelId == 521 ) allNumerators[0] += cxabs2( amp[0] );
  if( channelId != 0 ) allDenominators[0] += cxabs2( amp[0] );
#endif
  jamp[101] += amp[0];
  jamp[109] -= amp[0];
  jamp[112] += amp[0];
  jamp[115] -= amp[0];

  // *** DIAGRAM 522 OF 1240 ***

  // Wavefunction(s) for diagram number 522
  // (none)

  // Amplitude(s) for diagram number 522
  FFV1_0( w[86], w[2], w[27], COUPs[1], &amp[0] );
#ifdef MGONGPU_SUPPORTS_MULTICHANNEL
  if( channelId == 522 ) allNumerators[0] += cxabs2( amp[0] );
  if( channelId != 0 ) allDenominators[0] += cxabs2( amp[0] );
#endif
  jamp[67] += amp[0];
  jamp[70] -= amp[0];
  jamp[109] -= amp[0];
  jamp[112] += amp[0];

  // *** DIAGRAM 523 OF 1240 ***

  // Wavefunction(s) for diagram number 523
  // (none)

  // Amplitude(s) for diagram number 523
  FFV1_0( w[52], w[112], w[27], COUPs[1], &amp[0] );
#ifdef MGONGPU_SUPPORTS_MULTICHANNEL
  if( channelId == 523 ) allNumerators[0] += cxabs2( amp[0] );
  if( channelId != 0 ) allDenominators[0] += cxabs2( amp[0] );
#endif
  jamp[15] += amp[0];
  jamp[17] -= amp[0];
  jamp[75] -= amp[0];
  jamp[77] += amp[0];

  // *** DIAGRAM 524 OF 1240 ***

  // Wavefunction(s) for diagram number 524
  // (none)

  // Amplitude(s) for diagram number 524
  FFV1_0( w[52], w[2], w[62], COUPs[1], &amp[0] );
#ifdef MGONGPU_SUPPORTS_MULTICHANNEL
  if( channelId == 524 ) allNumerators[0] += cxabs2( amp[0] );
  if( channelId != 0 ) allDenominators[0] += cxabs2( amp[0] );
#endif
  jamp[15] -= cxtype( 0, 1 ) * amp[0];
  jamp[17] += cxtype( 0, 1 ) * amp[0];
  jamp[67] += cxtype( 0, 1 ) * amp[0];
  jamp[70] -= cxtype( 0, 1 ) * amp[0];
  jamp[75] += cxtype( 0, 1 ) * amp[0];
  jamp[77] -= cxtype( 0, 1 ) * amp[0];
  jamp[109] -= cxtype( 0, 1 ) * amp[0];
  jamp[112] += cxtype( 0, 1 ) * amp[0];

  // *** DIAGRAM 525 OF 1240 ***

  // Wavefunction(s) for diagram number 525
  // (none)

  // Amplitude(s) for diagram number 525
  FFV1_0( w[65], w[112], w[6], COUPs[1], &amp[0] );
#ifdef MGONGPU_SUPPORTS_MULTICHANNEL
  if( channelId == 525 ) allNumerators[0] += cxabs2( amp[0] );
  if( channelId != 0 ) allDenominators[0] += cxabs2( amp[0] );
#endif
  jamp[16] += amp[0];
  jamp[17] -= amp[0];
  jamp[76] -= amp[0];
  jamp[77] += amp[0];

  // *** DIAGRAM 526 OF 1240 ***

  // Wavefunction(s) for diagram number 526
  // (none)

  // Amplitude(s) for diagram number 526
  FFV1_0( w[3], w[112], w[64], COUPs[1], &amp[0] );
#ifdef MGONGPU_SUPPORTS_MULTICHANNEL
  if( channelId == 526 ) allNumerators[0] += cxabs2( amp[0] );
  if( channelId != 0 ) allDenominators[0] += cxabs2( amp[0] );
#endif
  jamp[12] -= cxtype( 0, 1 ) * amp[0];
  jamp[14] += cxtype( 0, 1 ) * amp[0];
  jamp[16] += cxtype( 0, 1 ) * amp[0];
  jamp[17] -= cxtype( 0, 1 ) * amp[0];
  jamp[72] += cxtype( 0, 1 ) * amp[0];
  jamp[74] -= cxtype( 0, 1 ) * amp[0];
  jamp[76] -= cxtype( 0, 1 ) * amp[0];
  jamp[77] += cxtype( 0, 1 ) * amp[0];

  // *** DIAGRAM 527 OF 1240 ***

  // Wavefunction(s) for diagram number 527
  // (none)

  // Amplitude(s) for diagram number 527
  FFV1_0( w[99], w[93], w[6], COUPs[1], &amp[0] );
#ifdef MGONGPU_SUPPORTS_MULTICHANNEL
  if( channelId == 527 ) allNumerators[0] += cxabs2( amp[0] );
  if( channelId != 0 ) allDenominators[0] += cxabs2( amp[0] );
#endif
  jamp[34] += amp[0];
  jamp[35] -= amp[0];
  jamp[58] -= amp[0];
  jamp[59] += amp[0];

  // *** DIAGRAM 528 OF 1240 ***

  // Wavefunction(s) for diagram number 528
  // (none)

  // Amplitude(s) for diagram number 528
  FFV1_0( w[99], w[2], w[64], COUPs[1], &amp[0] );
#ifdef MGONGPU_SUPPORTS_MULTICHANNEL
  if( channelId == 528 ) allNumerators[0] += cxabs2( amp[0] );
  if( channelId != 0 ) allDenominators[0] += cxabs2( amp[0] );
#endif
  jamp[34] -= cxtype( 0, 1 ) * amp[0];
  jamp[35] += cxtype( 0, 1 ) * amp[0];
  jamp[58] += cxtype( 0, 1 ) * amp[0];
  jamp[59] -= cxtype( 0, 1 ) * amp[0];
  jamp[104] += cxtype( 0, 1 ) * amp[0];
  jamp[105] -= cxtype( 0, 1 ) * amp[0];
  jamp[110] -= cxtype( 0, 1 ) * amp[0];
  jamp[111] += cxtype( 0, 1 ) * amp[0];

  // *** DIAGRAM 529 OF 1240 ***

  // Wavefunction(s) for diagram number 529
  // (none)

  // Amplitude(s) for diagram number 529
  FFV1_0( w[3], w[93], w[104], COUPs[1], &amp[0] );
#ifdef MGONGPU_SUPPORTS_MULTICHANNEL
  if( channelId == 529 ) allNumerators[0] += cxabs2( amp[0] );
  if( channelId != 0 ) allDenominators[0] += cxabs2( amp[0] );
#endif
  jamp[30] -= cxtype( 0, 1 ) * amp[0];
  jamp[32] += cxtype( 0, 1 ) * amp[0];
  jamp[34] += cxtype( 0, 1 ) * amp[0];
  jamp[35] -= cxtype( 0, 1 ) * amp[0];
  jamp[54] += cxtype( 0, 1 ) * amp[0];
  jamp[56] -= cxtype( 0, 1 ) * amp[0];
  jamp[58] -= cxtype( 0, 1 ) * amp[0];
  jamp[59] += cxtype( 0, 1 ) * amp[0];

  // *** DIAGRAM 530 OF 1240 ***

  // Wavefunction(s) for diagram number 530
  // (none)

  // Amplitude(s) for diagram number 530
  FFV1_0( w[65], w[2], w[104], COUPs[1], &amp[0] );
#ifdef MGONGPU_SUPPORTS_MULTICHANNEL
  if( channelId == 530 ) allNumerators[0] += cxabs2( amp[0] );
  if( channelId != 0 ) allDenominators[0] += cxabs2( amp[0] );
#endif
  jamp[16] -= cxtype( 0, 1 ) * amp[0];
  jamp[17] += cxtype( 0, 1 ) * amp[0];
  jamp[76] += cxtype( 0, 1 ) * amp[0];
  jamp[77] -= cxtype( 0, 1 ) * amp[0];
  jamp[100] += cxtype( 0, 1 ) * amp[0];
  jamp[101] -= cxtype( 0, 1 ) * amp[0];
  jamp[114] -= cxtype( 0, 1 ) * amp[0];
  jamp[115] += cxtype( 0, 1 ) * amp[0];

  // *** DIAGRAM 531 OF 1240 ***

  // Wavefunction(s) for diagram number 531
  // (none)

  // Amplitude(s) for diagram number 531
  VVVV1_0( w[92], w[61], w[8], w[6], COUPs[2], &amp[0] );
  jamp[12] += amp[0];
  jamp[14] -= amp[0];
  jamp[30] -= amp[0];
  jamp[32] += amp[0];
  jamp[54] += amp[0];
  jamp[56] -= amp[0];
  jamp[72] -= amp[0];
  jamp[74] += amp[0];
  jamp[100] -= amp[0];
  jamp[101] += amp[0];
  jamp[104] += amp[0];
  jamp[105] -= amp[0];
  jamp[110] -= amp[0];
  jamp[111] += amp[0];
  jamp[114] += amp[0];
  jamp[115] -= amp[0];
  VVVV3_0( w[92], w[61], w[8], w[6], COUPs[2], &amp[0] );
  jamp[12] += amp[0];
  jamp[14] -= amp[0];
  jamp[16] -= amp[0];
  jamp[17] += amp[0];
  jamp[34] -= amp[0];
  jamp[35] += amp[0];
  jamp[58] += amp[0];
  jamp[59] -= amp[0];
  jamp[72] -= amp[0];
  jamp[74] += amp[0];
  jamp[76] += amp[0];
  jamp[77] -= amp[0];
  jamp[104] += amp[0];
  jamp[105] -= amp[0];
  jamp[110] -= amp[0];
  jamp[111] += amp[0];
  VVVV4_0( w[92], w[61], w[8], w[6], COUPs[2], &amp[0] );
  jamp[16] -= amp[0];
  jamp[17] += amp[0];
  jamp[30] += amp[0];
  jamp[32] -= amp[0];
  jamp[34] -= amp[0];
  jamp[35] += amp[0];
  jamp[54] -= amp[0];
  jamp[56] += amp[0];
  jamp[58] += amp[0];
  jamp[59] -= amp[0];
  jamp[76] += amp[0];
  jamp[77] -= amp[0];
  jamp[100] += amp[0];
  jamp[101] -= amp[0];
  jamp[114] -= amp[0];
  jamp[115] += amp[0];

  // *** DIAGRAM 532 OF 1240 ***

  // Wavefunction(s) for diagram number 532
  VVV1P0_1( w[92], w[61], COUPs[0], 0., 0., w[86] );

  // Amplitude(s) for diagram number 532
  VVV1_0( w[8], w[6], w[86], COUPs[0], &amp[0] );
#ifdef MGONGPU_SUPPORTS_MULTICHANNEL
  if( channelId == 532 ) allNumerators[0] += cxabs2( amp[0] );
  if( channelId != 0 ) allDenominators[0] += cxabs2( amp[0] );
#endif
  jamp[12] += amp[0];
  jamp[14] -= amp[0];
  jamp[30] -= amp[0];
  jamp[32] += amp[0];
  jamp[54] += amp[0];
  jamp[56] -= amp[0];
  jamp[72] -= amp[0];
  jamp[74] += amp[0];
  jamp[100] -= amp[0];
  jamp[101] += amp[0];
  jamp[104] += amp[0];
  jamp[105] -= amp[0];
  jamp[110] -= amp[0];
  jamp[111] += amp[0];
  jamp[114] += amp[0];
  jamp[115] -= amp[0];

  // *** DIAGRAM 533 OF 1240 ***

  // Wavefunction(s) for diagram number 533
  VVV1P0_1( w[92], w[8], COUPs[0], 0., 0., w[101] );

  // Amplitude(s) for diagram number 533
  VVV1_0( w[61], w[6], w[101], COUPs[0], &amp[0] );
#ifdef MGONGPU_SUPPORTS_MULTICHANNEL
  if( channelId == 533 ) allNumerators[0] += cxabs2( amp[0] );
  if( channelId != 0 ) allDenominators[0] += cxabs2( amp[0] );
#endif
  jamp[12] += amp[0];
  jamp[14] -= amp[0];
  jamp[16] -= amp[0];
  jamp[17] += amp[0];
  jamp[34] -= amp[0];
  jamp[35] += amp[0];
  jamp[58] += amp[0];
  jamp[59] -= amp[0];
  jamp[72] -= amp[0];
  jamp[74] += amp[0];
  jamp[76] += amp[0];
  jamp[77] -= amp[0];
  jamp[104] += amp[0];
  jamp[105] -= amp[0];
  jamp[110] -= amp[0];
  jamp[111] += amp[0];

  // *** DIAGRAM 534 OF 1240 ***

  // Wavefunction(s) for diagram number 534
  // (none)

  // Amplitude(s) for diagram number 534
  VVV1_0( w[61], w[8], w[104], COUPs[0], &amp[0] );
#ifdef MGONGPU_SUPPORTS_MULTICHANNEL
  if( channelId == 534 ) allNumerators[0] += cxabs2( amp[0] );
  if( channelId != 0 ) allDenominators[0] += cxabs2( amp[0] );
#endif
  jamp[16] -= amp[0];
  jamp[17] += amp[0];
  jamp[30] += amp[0];
  jamp[32] -= amp[0];
  jamp[34] -= amp[0];
  jamp[35] += amp[0];
  jamp[54] -= amp[0];
  jamp[56] += amp[0];
  jamp[58] += amp[0];
  jamp[59] -= amp[0];
  jamp[76] += amp[0];
  jamp[77] -= amp[0];
  jamp[100] += amp[0];
  jamp[101] -= amp[0];
  jamp[114] -= amp[0];
  jamp[115] += amp[0];

  // *** DIAGRAM 535 OF 1240 ***

  // Wavefunction(s) for diagram number 535
  // (none)

  // Amplitude(s) for diagram number 535
  FFV1_0( w[3], w[47], w[86], COUPs[1], &amp[0] );
#ifdef MGONGPU_SUPPORTS_MULTICHANNEL
  if( channelId == 535 ) allNumerators[0] += cxabs2( amp[0] );
  if( channelId != 0 ) allDenominators[0] += cxabs2( amp[0] );
#endif
  jamp[100] -= cxtype( 0, 1 ) * amp[0];
  jamp[101] += cxtype( 0, 1 ) * amp[0];
  jamp[104] += cxtype( 0, 1 ) * amp[0];
  jamp[105] -= cxtype( 0, 1 ) * amp[0];
  jamp[110] -= cxtype( 0, 1 ) * amp[0];
  jamp[111] += cxtype( 0, 1 ) * amp[0];
  jamp[114] += cxtype( 0, 1 ) * amp[0];
  jamp[115] -= cxtype( 0, 1 ) * amp[0];

  // *** DIAGRAM 536 OF 1240 ***

  // Wavefunction(s) for diagram number 536
  // (none)

  // Amplitude(s) for diagram number 536
  FFV1_0( w[3], w[106], w[61], COUPs[1], &amp[0] );
#ifdef MGONGPU_SUPPORTS_MULTICHANNEL
  if( channelId == 536 ) allNumerators[0] += cxabs2( amp[0] );
  if( channelId != 0 ) allDenominators[0] += cxabs2( amp[0] );
#endif
  jamp[100] += amp[0];
  jamp[101] -= amp[0];
  jamp[114] -= amp[0];
  jamp[115] += amp[0];

  // *** DIAGRAM 537 OF 1240 ***

  // Wavefunction(s) for diagram number 537
  // (none)

  // Amplitude(s) for diagram number 537
  FFV1_0( w[99], w[47], w[61], COUPs[1], &amp[0] );
#ifdef MGONGPU_SUPPORTS_MULTICHANNEL
  if( channelId == 537 ) allNumerators[0] += cxabs2( amp[0] );
  if( channelId != 0 ) allDenominators[0] += cxabs2( amp[0] );
#endif
  jamp[104] += amp[0];
  jamp[105] -= amp[0];
  jamp[110] -= amp[0];
  jamp[111] += amp[0];

  // *** DIAGRAM 538 OF 1240 ***

  // Wavefunction(s) for diagram number 538
  // (none)

  // Amplitude(s) for diagram number 538
  FFV1_0( w[41], w[2], w[86], COUPs[1], &amp[0] );
#ifdef MGONGPU_SUPPORTS_MULTICHANNEL
  if( channelId == 538 ) allNumerators[0] += cxabs2( amp[0] );
  if( channelId != 0 ) allDenominators[0] += cxabs2( amp[0] );
#endif
  jamp[12] -= cxtype( 0, 1 ) * amp[0];
  jamp[14] += cxtype( 0, 1 ) * amp[0];
  jamp[30] += cxtype( 0, 1 ) * amp[0];
  jamp[32] -= cxtype( 0, 1 ) * amp[0];
  jamp[54] -= cxtype( 0, 1 ) * amp[0];
  jamp[56] += cxtype( 0, 1 ) * amp[0];
  jamp[72] += cxtype( 0, 1 ) * amp[0];
  jamp[74] -= cxtype( 0, 1 ) * amp[0];

  // *** DIAGRAM 539 OF 1240 ***

  // Wavefunction(s) for diagram number 539
  // (none)

  // Amplitude(s) for diagram number 539
  FFV1_0( w[41], w[112], w[61], COUPs[1], &amp[0] );
#ifdef MGONGPU_SUPPORTS_MULTICHANNEL
  if( channelId == 539 ) allNumerators[0] += cxabs2( amp[0] );
  if( channelId != 0 ) allDenominators[0] += cxabs2( amp[0] );
#endif
  jamp[12] += amp[0];
  jamp[14] -= amp[0];
  jamp[72] -= amp[0];
  jamp[74] += amp[0];

  // *** DIAGRAM 540 OF 1240 ***

  // Wavefunction(s) for diagram number 540
  // (none)

  // Amplitude(s) for diagram number 540
  FFV1_0( w[113], w[2], w[61], COUPs[1], &amp[0] );
#ifdef MGONGPU_SUPPORTS_MULTICHANNEL
  if( channelId == 540 ) allNumerators[0] += cxabs2( amp[0] );
  if( channelId != 0 ) allDenominators[0] += cxabs2( amp[0] );
#endif
  jamp[30] += amp[0];
  jamp[32] -= amp[0];
  jamp[54] -= amp[0];
  jamp[56] += amp[0];

  // *** DIAGRAM 541 OF 1240 ***

  // Wavefunction(s) for diagram number 541
  // (none)

  // Amplitude(s) for diagram number 541
  FFV1_0( w[76], w[112], w[4], COUPs[1], &amp[0] );
#ifdef MGONGPU_SUPPORTS_MULTICHANNEL
  if( channelId == 541 ) allNumerators[0] += cxabs2( amp[0] );
  if( channelId != 0 ) allDenominators[0] += cxabs2( amp[0] );
#endif
  jamp[14] += amp[0];
  jamp[15] -= amp[0];
  jamp[74] -= amp[0];
  jamp[75] += amp[0];

  // *** DIAGRAM 542 OF 1240 ***

  // Wavefunction(s) for diagram number 542
  // (none)

  // Amplitude(s) for diagram number 542
  FFV1_0( w[3], w[112], w[74], COUPs[1], &amp[0] );
#ifdef MGONGPU_SUPPORTS_MULTICHANNEL
  if( channelId == 542 ) allNumerators[0] += cxabs2( amp[0] );
  if( channelId != 0 ) allDenominators[0] += cxabs2( amp[0] );
#endif
  jamp[13] -= cxtype( 0, 1 ) * amp[0];
  jamp[14] += cxtype( 0, 1 ) * amp[0];
  jamp[15] -= cxtype( 0, 1 ) * amp[0];
  jamp[16] += cxtype( 0, 1 ) * amp[0];
  jamp[73] += cxtype( 0, 1 ) * amp[0];
  jamp[74] -= cxtype( 0, 1 ) * amp[0];
  jamp[75] += cxtype( 0, 1 ) * amp[0];
  jamp[76] -= cxtype( 0, 1 ) * amp[0];

  // *** DIAGRAM 543 OF 1240 ***

  // Wavefunction(s) for diagram number 543
  // (none)

  // Amplitude(s) for diagram number 543
  FFV1_0( w[99], w[97], w[4], COUPs[1], &amp[0] );
#ifdef MGONGPU_SUPPORTS_MULTICHANNEL
  if( channelId == 543 ) allNumerators[0] += cxabs2( amp[0] );
  if( channelId != 0 ) allDenominators[0] += cxabs2( amp[0] );
#endif
  jamp[44] += amp[0];
  jamp[45] -= amp[0];
  jamp[104] -= amp[0];
  jamp[105] += amp[0];

  // *** DIAGRAM 544 OF 1240 ***

  // Wavefunction(s) for diagram number 544
  // (none)

  // Amplitude(s) for diagram number 544
  FFV1_0( w[99], w[2], w[74], COUPs[1], &amp[0] );
#ifdef MGONGPU_SUPPORTS_MULTICHANNEL
  if( channelId == 544 ) allNumerators[0] += cxabs2( amp[0] );
  if( channelId != 0 ) allDenominators[0] += cxabs2( amp[0] );
#endif
  jamp[44] -= cxtype( 0, 1 ) * amp[0];
  jamp[45] += cxtype( 0, 1 ) * amp[0];
  jamp[58] += cxtype( 0, 1 ) * amp[0];
  jamp[59] -= cxtype( 0, 1 ) * amp[0];
  jamp[68] -= cxtype( 0, 1 ) * amp[0];
  jamp[69] += cxtype( 0, 1 ) * amp[0];
  jamp[104] += cxtype( 0, 1 ) * amp[0];
  jamp[105] -= cxtype( 0, 1 ) * amp[0];

  // *** DIAGRAM 545 OF 1240 ***

  // Wavefunction(s) for diagram number 545
  // (none)

  // Amplitude(s) for diagram number 545
  FFV1_0( w[3], w[97], w[102], COUPs[1], &amp[0] );
#ifdef MGONGPU_SUPPORTS_MULTICHANNEL
  if( channelId == 545 ) allNumerators[0] += cxabs2( amp[0] );
  if( channelId != 0 ) allDenominators[0] += cxabs2( amp[0] );
#endif
  jamp[43] -= cxtype( 0, 1 ) * amp[0];
  jamp[44] += cxtype( 0, 1 ) * amp[0];
  jamp[45] -= cxtype( 0, 1 ) * amp[0];
  jamp[46] += cxtype( 0, 1 ) * amp[0];
  jamp[103] += cxtype( 0, 1 ) * amp[0];
  jamp[104] -= cxtype( 0, 1 ) * amp[0];
  jamp[105] += cxtype( 0, 1 ) * amp[0];
  jamp[106] -= cxtype( 0, 1 ) * amp[0];

  // *** DIAGRAM 546 OF 1240 ***

  // Wavefunction(s) for diagram number 546
  // (none)

  // Amplitude(s) for diagram number 546
  FFV1_0( w[76], w[2], w[102], COUPs[1], &amp[0] );
#ifdef MGONGPU_SUPPORTS_MULTICHANNEL
  if( channelId == 546 ) allNumerators[0] += cxabs2( amp[0] );
  if( channelId != 0 ) allDenominators[0] += cxabs2( amp[0] );
#endif
  jamp[14] -= cxtype( 0, 1 ) * amp[0];
  jamp[15] += cxtype( 0, 1 ) * amp[0];
  jamp[50] += cxtype( 0, 1 ) * amp[0];
  jamp[51] -= cxtype( 0, 1 ) * amp[0];
  jamp[60] -= cxtype( 0, 1 ) * amp[0];
  jamp[61] += cxtype( 0, 1 ) * amp[0];
  jamp[74] += cxtype( 0, 1 ) * amp[0];
  jamp[75] -= cxtype( 0, 1 ) * amp[0];

  // *** DIAGRAM 547 OF 1240 ***

  // Wavefunction(s) for diagram number 547
  // (none)

  // Amplitude(s) for diagram number 547
  VVVV1_0( w[92], w[72], w[8], w[4], COUPs[2], &amp[0] );
  jamp[13] += amp[0];
  jamp[16] -= amp[0];
  jamp[43] -= amp[0];
  jamp[46] += amp[0];
  jamp[50] -= amp[0];
  jamp[51] += amp[0];
  jamp[58] += amp[0];
  jamp[59] -= amp[0];
  jamp[60] += amp[0];
  jamp[61] -= amp[0];
  jamp[68] -= amp[0];
  jamp[69] += amp[0];
  jamp[73] -= amp[0];
  jamp[76] += amp[0];
  jamp[103] += amp[0];
  jamp[106] -= amp[0];
  VVVV3_0( w[92], w[72], w[8], w[4], COUPs[2], &amp[0] );
  jamp[13] += amp[0];
  jamp[14] -= amp[0];
  jamp[15] += amp[0];
  jamp[16] -= amp[0];
  jamp[44] -= amp[0];
  jamp[45] += amp[0];
  jamp[58] += amp[0];
  jamp[59] -= amp[0];
  jamp[68] -= amp[0];
  jamp[69] += amp[0];
  jamp[73] -= amp[0];
  jamp[74] += amp[0];
  jamp[75] -= amp[0];
  jamp[76] += amp[0];
  jamp[104] += amp[0];
  jamp[105] -= amp[0];
  VVVV4_0( w[92], w[72], w[8], w[4], COUPs[2], &amp[0] );
  jamp[14] -= amp[0];
  jamp[15] += amp[0];
  jamp[43] += amp[0];
  jamp[44] -= amp[0];
  jamp[45] += amp[0];
  jamp[46] -= amp[0];
  jamp[50] += amp[0];
  jamp[51] -= amp[0];
  jamp[60] -= amp[0];
  jamp[61] += amp[0];
  jamp[74] += amp[0];
  jamp[75] -= amp[0];
  jamp[103] -= amp[0];
  jamp[104] += amp[0];
  jamp[105] -= amp[0];
  jamp[106] += amp[0];

  // *** DIAGRAM 548 OF 1240 ***

  // Wavefunction(s) for diagram number 548
  VVV1P0_1( w[92], w[72], COUPs[0], 0., 0., w[86] );

  // Amplitude(s) for diagram number 548
  VVV1_0( w[8], w[4], w[86], COUPs[0], &amp[0] );
#ifdef MGONGPU_SUPPORTS_MULTICHANNEL
  if( channelId == 548 ) allNumerators[0] += cxabs2( amp[0] );
  if( channelId != 0 ) allDenominators[0] += cxabs2( amp[0] );
#endif
  jamp[13] += amp[0];
  jamp[16] -= amp[0];
  jamp[43] -= amp[0];
  jamp[46] += amp[0];
  jamp[50] -= amp[0];
  jamp[51] += amp[0];
  jamp[58] += amp[0];
  jamp[59] -= amp[0];
  jamp[60] += amp[0];
  jamp[61] -= amp[0];
  jamp[68] -= amp[0];
  jamp[69] += amp[0];
  jamp[73] -= amp[0];
  jamp[76] += amp[0];
  jamp[103] += amp[0];
  jamp[106] -= amp[0];

  // *** DIAGRAM 549 OF 1240 ***

  // Wavefunction(s) for diagram number 549
  // (none)

  // Amplitude(s) for diagram number 549
  VVV1_0( w[72], w[4], w[101], COUPs[0], &amp[0] );
#ifdef MGONGPU_SUPPORTS_MULTICHANNEL
  if( channelId == 549 ) allNumerators[0] += cxabs2( amp[0] );
  if( channelId != 0 ) allDenominators[0] += cxabs2( amp[0] );
#endif
  jamp[13] += amp[0];
  jamp[14] -= amp[0];
  jamp[15] += amp[0];
  jamp[16] -= amp[0];
  jamp[44] -= amp[0];
  jamp[45] += amp[0];
  jamp[58] += amp[0];
  jamp[59] -= amp[0];
  jamp[68] -= amp[0];
  jamp[69] += amp[0];
  jamp[73] -= amp[0];
  jamp[74] += amp[0];
  jamp[75] -= amp[0];
  jamp[76] += amp[0];
  jamp[104] += amp[0];
  jamp[105] -= amp[0];

  // *** DIAGRAM 550 OF 1240 ***

  // Wavefunction(s) for diagram number 550
  // (none)

  // Amplitude(s) for diagram number 550
  VVV1_0( w[72], w[8], w[102], COUPs[0], &amp[0] );
#ifdef MGONGPU_SUPPORTS_MULTICHANNEL
  if( channelId == 550 ) allNumerators[0] += cxabs2( amp[0] );
  if( channelId != 0 ) allDenominators[0] += cxabs2( amp[0] );
#endif
  jamp[14] -= amp[0];
  jamp[15] += amp[0];
  jamp[43] += amp[0];
  jamp[44] -= amp[0];
  jamp[45] += amp[0];
  jamp[46] -= amp[0];
  jamp[50] += amp[0];
  jamp[51] -= amp[0];
  jamp[60] -= amp[0];
  jamp[61] += amp[0];
  jamp[74] += amp[0];
  jamp[75] -= amp[0];
  jamp[103] -= amp[0];
  jamp[104] += amp[0];
  jamp[105] -= amp[0];
  jamp[106] += amp[0];

  // *** DIAGRAM 551 OF 1240 ***

  // Wavefunction(s) for diagram number 551
  // (none)

  // Amplitude(s) for diagram number 551
  FFV1_0( w[3], w[33], w[86], COUPs[1], &amp[0] );
#ifdef MGONGPU_SUPPORTS_MULTICHANNEL
  if( channelId == 551 ) allNumerators[0] += cxabs2( amp[0] );
  if( channelId != 0 ) allDenominators[0] += cxabs2( amp[0] );
#endif
  jamp[50] -= cxtype( 0, 1 ) * amp[0];
  jamp[51] += cxtype( 0, 1 ) * amp[0];
  jamp[58] += cxtype( 0, 1 ) * amp[0];
  jamp[59] -= cxtype( 0, 1 ) * amp[0];
  jamp[60] += cxtype( 0, 1 ) * amp[0];
  jamp[61] -= cxtype( 0, 1 ) * amp[0];
  jamp[68] -= cxtype( 0, 1 ) * amp[0];
  jamp[69] += cxtype( 0, 1 ) * amp[0];

  // *** DIAGRAM 552 OF 1240 ***

  // Wavefunction(s) for diagram number 552
  // (none)

  // Amplitude(s) for diagram number 552
  FFV1_0( w[3], w[98], w[72], COUPs[1], &amp[0] );
#ifdef MGONGPU_SUPPORTS_MULTICHANNEL
  if( channelId == 552 ) allNumerators[0] += cxabs2( amp[0] );
  if( channelId != 0 ) allDenominators[0] += cxabs2( amp[0] );
#endif
  jamp[50] += amp[0];
  jamp[51] -= amp[0];
  jamp[60] -= amp[0];
  jamp[61] += amp[0];

  // *** DIAGRAM 553 OF 1240 ***

  // Wavefunction(s) for diagram number 553
  // (none)

  // Amplitude(s) for diagram number 553
  FFV1_0( w[99], w[33], w[72], COUPs[1], &amp[0] );
#ifdef MGONGPU_SUPPORTS_MULTICHANNEL
  if( channelId == 553 ) allNumerators[0] += cxabs2( amp[0] );
  if( channelId != 0 ) allDenominators[0] += cxabs2( amp[0] );
#endif
  jamp[58] += amp[0];
  jamp[59] -= amp[0];
  jamp[68] -= amp[0];
  jamp[69] += amp[0];

  // *** DIAGRAM 554 OF 1240 ***

  // Wavefunction(s) for diagram number 554
  // (none)

  // Amplitude(s) for diagram number 554
  FFV1_0( w[46], w[2], w[86], COUPs[1], &amp[0] );
#ifdef MGONGPU_SUPPORTS_MULTICHANNEL
  if( channelId == 554 ) allNumerators[0] += cxabs2( amp[0] );
  if( channelId != 0 ) allDenominators[0] += cxabs2( amp[0] );
#endif
  jamp[13] -= cxtype( 0, 1 ) * amp[0];
  jamp[16] += cxtype( 0, 1 ) * amp[0];
  jamp[43] += cxtype( 0, 1 ) * amp[0];
  jamp[46] -= cxtype( 0, 1 ) * amp[0];
  jamp[73] += cxtype( 0, 1 ) * amp[0];
  jamp[76] -= cxtype( 0, 1 ) * amp[0];
  jamp[103] -= cxtype( 0, 1 ) * amp[0];
  jamp[106] += cxtype( 0, 1 ) * amp[0];

  // *** DIAGRAM 555 OF 1240 ***

  // Wavefunction(s) for diagram number 555
  // (none)

  // Amplitude(s) for diagram number 555
  FFV1_0( w[46], w[112], w[72], COUPs[1], &amp[0] );
#ifdef MGONGPU_SUPPORTS_MULTICHANNEL
  if( channelId == 555 ) allNumerators[0] += cxabs2( amp[0] );
  if( channelId != 0 ) allDenominators[0] += cxabs2( amp[0] );
#endif
  jamp[13] += amp[0];
  jamp[16] -= amp[0];
  jamp[73] -= amp[0];
  jamp[76] += amp[0];

  // *** DIAGRAM 556 OF 1240 ***

  // Wavefunction(s) for diagram number 556
  // (none)

  // Amplitude(s) for diagram number 556
  FFV1_0( w[114], w[2], w[72], COUPs[1], &amp[0] );
#ifdef MGONGPU_SUPPORTS_MULTICHANNEL
  if( channelId == 556 ) allNumerators[0] += cxabs2( amp[0] );
  if( channelId != 0 ) allDenominators[0] += cxabs2( amp[0] );
#endif
  jamp[43] += amp[0];
  jamp[46] -= amp[0];
  jamp[103] -= amp[0];
  jamp[106] += amp[0];

  // *** DIAGRAM 557 OF 1240 ***

  // Wavefunction(s) for diagram number 557
  VVV1P0_1( w[92], w[1], COUPs[0], 0., 0., w[86] );

  // Amplitude(s) for diagram number 557
  VVV1_0( w[86], w[13], w[6], COUPs[0], &amp[0] );
#ifdef MGONGPU_SUPPORTS_MULTICHANNEL
  if( channelId == 557 ) allNumerators[0] += cxabs2( amp[0] );
  if( channelId != 0 ) allDenominators[0] += cxabs2( amp[0] );
#endif
  jamp[13] -= amp[0];
  jamp[27] += amp[0];
  jamp[37] -= amp[0];
  jamp[50] += amp[0];
  jamp[54] -= amp[0];
  jamp[56] += amp[0];
  jamp[60] -= amp[0];
  jamp[67] -= amp[0];
  jamp[68] += amp[0];
  jamp[69] -= amp[0];
  jamp[70] += amp[0];
  jamp[73] += amp[0];
  jamp[100] += amp[0];
  jamp[103] -= amp[0];
  jamp[106] += amp[0];
  jamp[114] -= amp[0];

  // *** DIAGRAM 558 OF 1240 ***

  // Wavefunction(s) for diagram number 558
  // (none)

  // Amplitude(s) for diagram number 558
  VVV1_0( w[86], w[11], w[4], COUPs[0], &amp[0] );
#ifdef MGONGPU_SUPPORTS_MULTICHANNEL
  if( channelId == 558 ) allNumerators[0] += cxabs2( amp[0] );
  if( channelId != 0 ) allDenominators[0] += cxabs2( amp[0] );
#endif
  jamp[12] -= amp[0];
  jamp[26] += amp[0];
  jamp[36] -= amp[0];
  jamp[50] += amp[0];
  jamp[54] -= amp[0];
  jamp[56] += amp[0];
  jamp[60] -= amp[0];
  jamp[72] += amp[0];
  jamp[100] += amp[0];
  jamp[103] -= amp[0];
  jamp[106] += amp[0];
  jamp[109] -= amp[0];
  jamp[110] += amp[0];
  jamp[111] -= amp[0];
  jamp[112] += amp[0];
  jamp[114] -= amp[0];

  // *** DIAGRAM 559 OF 1240 ***

  // Wavefunction(s) for diagram number 559
  // (none)

  // Amplitude(s) for diagram number 559
  VVVV1_0( w[8], w[4], w[6], w[86], COUPs[2], &amp[0] );
  jamp[13] -= amp[0];
  jamp[27] += amp[0];
  jamp[37] -= amp[0];
  jamp[50] += amp[0];
  jamp[54] -= amp[0];
  jamp[56] += amp[0];
  jamp[60] -= amp[0];
  jamp[67] -= amp[0];
  jamp[68] += amp[0];
  jamp[69] -= amp[0];
  jamp[70] += amp[0];
  jamp[73] += amp[0];
  jamp[100] += amp[0];
  jamp[103] -= amp[0];
  jamp[106] += amp[0];
  jamp[114] -= amp[0];
  VVVV3_0( w[8], w[4], w[6], w[86], COUPs[2], &amp[0] );
  jamp[12] -= amp[0];
  jamp[26] += amp[0];
  jamp[36] -= amp[0];
  jamp[50] += amp[0];
  jamp[54] -= amp[0];
  jamp[56] += amp[0];
  jamp[60] -= amp[0];
  jamp[72] += amp[0];
  jamp[100] += amp[0];
  jamp[103] -= amp[0];
  jamp[106] += amp[0];
  jamp[109] -= amp[0];
  jamp[110] += amp[0];
  jamp[111] -= amp[0];
  jamp[112] += amp[0];
  jamp[114] -= amp[0];
  VVVV4_0( w[8], w[4], w[6], w[86], COUPs[2], &amp[0] );
  jamp[12] -= amp[0];
  jamp[13] += amp[0];
  jamp[26] += amp[0];
  jamp[27] -= amp[0];
  jamp[36] -= amp[0];
  jamp[37] += amp[0];
  jamp[67] += amp[0];
  jamp[68] -= amp[0];
  jamp[69] += amp[0];
  jamp[70] -= amp[0];
  jamp[72] += amp[0];
  jamp[73] -= amp[0];
  jamp[109] -= amp[0];
  jamp[110] += amp[0];
  jamp[111] -= amp[0];
  jamp[112] += amp[0];

  // *** DIAGRAM 560 OF 1240 ***

  // Wavefunction(s) for diagram number 560
  // (none)

  // Amplitude(s) for diagram number 560
  VVV1_0( w[102], w[108], w[6], COUPs[0], &amp[0] );
#ifdef MGONGPU_SUPPORTS_MULTICHANNEL
  if( channelId == 560 ) allNumerators[0] += cxabs2( amp[0] );
  if( channelId != 0 ) allDenominators[0] += cxabs2( amp[0] );
#endif
  jamp[15] += amp[0];
  jamp[26] -= amp[0];
  jamp[30] += amp[0];
  jamp[32] -= amp[0];
  jamp[36] += amp[0];
  jamp[43] += amp[0];
  jamp[44] -= amp[0];
  jamp[45] += amp[0];
  jamp[46] -= amp[0];
  jamp[51] -= amp[0];
  jamp[61] += amp[0];
  jamp[75] -= amp[0];
  jamp[101] -= amp[0];
  jamp[109] += amp[0];
  jamp[112] -= amp[0];
  jamp[115] += amp[0];

  // *** DIAGRAM 561 OF 1240 ***

  // Wavefunction(s) for diagram number 561
  // (none)

  // Amplitude(s) for diagram number 561
  VVV1_0( w[102], w[1], w[11], COUPs[0], &amp[0] );
#ifdef MGONGPU_SUPPORTS_MULTICHANNEL
  if( channelId == 561 ) allNumerators[0] += cxabs2( amp[0] );
  if( channelId != 0 ) allDenominators[0] += cxabs2( amp[0] );
#endif
  jamp[14] += amp[0];
  jamp[26] -= amp[0];
  jamp[30] += amp[0];
  jamp[32] -= amp[0];
  jamp[36] += amp[0];
  jamp[50] -= amp[0];
  jamp[60] += amp[0];
  jamp[74] -= amp[0];
  jamp[101] -= amp[0];
  jamp[103] += amp[0];
  jamp[104] -= amp[0];
  jamp[105] += amp[0];
  jamp[106] -= amp[0];
  jamp[109] += amp[0];
  jamp[112] -= amp[0];
  jamp[115] += amp[0];

  // *** DIAGRAM 562 OF 1240 ***

  // Wavefunction(s) for diagram number 562
  // (none)

  // Amplitude(s) for diagram number 562
  VVVV1_0( w[1], w[8], w[6], w[102], COUPs[2], &amp[0] );
  jamp[15] += amp[0];
  jamp[26] -= amp[0];
  jamp[30] += amp[0];
  jamp[32] -= amp[0];
  jamp[36] += amp[0];
  jamp[43] += amp[0];
  jamp[44] -= amp[0];
  jamp[45] += amp[0];
  jamp[46] -= amp[0];
  jamp[51] -= amp[0];
  jamp[61] += amp[0];
  jamp[75] -= amp[0];
  jamp[101] -= amp[0];
  jamp[109] += amp[0];
  jamp[112] -= amp[0];
  jamp[115] += amp[0];
  VVVV3_0( w[1], w[8], w[6], w[102], COUPs[2], &amp[0] );
  jamp[14] -= amp[0];
  jamp[15] += amp[0];
  jamp[43] += amp[0];
  jamp[44] -= amp[0];
  jamp[45] += amp[0];
  jamp[46] -= amp[0];
  jamp[50] += amp[0];
  jamp[51] -= amp[0];
  jamp[60] -= amp[0];
  jamp[61] += amp[0];
  jamp[74] += amp[0];
  jamp[75] -= amp[0];
  jamp[103] -= amp[0];
  jamp[104] += amp[0];
  jamp[105] -= amp[0];
  jamp[106] += amp[0];
  VVVV4_0( w[1], w[8], w[6], w[102], COUPs[2], &amp[0] );
  jamp[14] -= amp[0];
  jamp[26] += amp[0];
  jamp[30] -= amp[0];
  jamp[32] += amp[0];
  jamp[36] -= amp[0];
  jamp[50] += amp[0];
  jamp[60] -= amp[0];
  jamp[74] += amp[0];
  jamp[101] += amp[0];
  jamp[103] -= amp[0];
  jamp[104] += amp[0];
  jamp[105] -= amp[0];
  jamp[106] += amp[0];
  jamp[109] -= amp[0];
  jamp[112] += amp[0];
  jamp[115] -= amp[0];

  // *** DIAGRAM 563 OF 1240 ***

  // Wavefunction(s) for diagram number 563
  // (none)

  // Amplitude(s) for diagram number 563
  VVV1_0( w[104], w[108], w[4], COUPs[0], &amp[0] );
#ifdef MGONGPU_SUPPORTS_MULTICHANNEL
  if( channelId == 563 ) allNumerators[0] += cxabs2( amp[0] );
  if( channelId != 0 ) allDenominators[0] += cxabs2( amp[0] );
#endif
  jamp[17] += amp[0];
  jamp[27] -= amp[0];
  jamp[30] += amp[0];
  jamp[32] -= amp[0];
  jamp[34] -= amp[0];
  jamp[35] += amp[0];
  jamp[37] += amp[0];
  jamp[43] += amp[0];
  jamp[46] -= amp[0];
  jamp[51] -= amp[0];
  jamp[61] += amp[0];
  jamp[67] += amp[0];
  jamp[70] -= amp[0];
  jamp[77] -= amp[0];
  jamp[101] -= amp[0];
  jamp[115] += amp[0];

  // *** DIAGRAM 564 OF 1240 ***

  // Wavefunction(s) for diagram number 564
  // (none)

  // Amplitude(s) for diagram number 564
  VVV1_0( w[104], w[1], w[13], COUPs[0], &amp[0] );
#ifdef MGONGPU_SUPPORTS_MULTICHANNEL
  if( channelId == 564 ) allNumerators[0] += cxabs2( amp[0] );
  if( channelId != 0 ) allDenominators[0] += cxabs2( amp[0] );
#endif
  jamp[16] += amp[0];
  jamp[27] -= amp[0];
  jamp[37] += amp[0];
  jamp[43] += amp[0];
  jamp[46] -= amp[0];
  jamp[51] -= amp[0];
  jamp[54] += amp[0];
  jamp[56] -= amp[0];
  jamp[58] -= amp[0];
  jamp[59] += amp[0];
  jamp[61] += amp[0];
  jamp[67] += amp[0];
  jamp[70] -= amp[0];
  jamp[76] -= amp[0];
  jamp[100] -= amp[0];
  jamp[114] += amp[0];

  // *** DIAGRAM 565 OF 1240 ***

  // Wavefunction(s) for diagram number 565
  // (none)

  // Amplitude(s) for diagram number 565
  VVVV1_0( w[1], w[8], w[4], w[104], COUPs[2], &amp[0] );
  jamp[17] += amp[0];
  jamp[27] -= amp[0];
  jamp[30] += amp[0];
  jamp[32] -= amp[0];
  jamp[34] -= amp[0];
  jamp[35] += amp[0];
  jamp[37] += amp[0];
  jamp[43] += amp[0];
  jamp[46] -= amp[0];
  jamp[51] -= amp[0];
  jamp[61] += amp[0];
  jamp[67] += amp[0];
  jamp[70] -= amp[0];
  jamp[77] -= amp[0];
  jamp[101] -= amp[0];
  jamp[115] += amp[0];
  VVVV3_0( w[1], w[8], w[4], w[104], COUPs[2], &amp[0] );
  jamp[16] -= amp[0];
  jamp[17] += amp[0];
  jamp[30] += amp[0];
  jamp[32] -= amp[0];
  jamp[34] -= amp[0];
  jamp[35] += amp[0];
  jamp[54] -= amp[0];
  jamp[56] += amp[0];
  jamp[58] += amp[0];
  jamp[59] -= amp[0];
  jamp[76] += amp[0];
  jamp[77] -= amp[0];
  jamp[100] += amp[0];
  jamp[101] -= amp[0];
  jamp[114] -= amp[0];
  jamp[115] += amp[0];
  VVVV4_0( w[1], w[8], w[4], w[104], COUPs[2], &amp[0] );
  jamp[16] -= amp[0];
  jamp[27] += amp[0];
  jamp[37] -= amp[0];
  jamp[43] -= amp[0];
  jamp[46] += amp[0];
  jamp[51] += amp[0];
  jamp[54] -= amp[0];
  jamp[56] += amp[0];
  jamp[58] += amp[0];
  jamp[59] -= amp[0];
  jamp[61] -= amp[0];
  jamp[67] -= amp[0];
  jamp[70] += amp[0];
  jamp[76] += amp[0];
  jamp[100] += amp[0];
  jamp[114] -= amp[0];

  // *** DIAGRAM 566 OF 1240 ***

  // Wavefunction(s) for diagram number 566
  VVVV1P0_1( w[92], w[1], w[4], COUPs[2], 0., 0., w[105] );
  VVVV3P0_1( w[92], w[1], w[4], COUPs[2], 0., 0., w[95] );
  VVVV4P0_1( w[92], w[1], w[4], COUPs[2], 0., 0., w[107] );

  // Amplitude(s) for diagram number 566
  VVV1_0( w[8], w[6], w[105], COUPs[0], &amp[0] );
  jamp[12] += amp[0];
  jamp[14] -= amp[0];
  jamp[30] -= amp[0];
  jamp[32] += amp[0];
  jamp[54] += amp[0];
  jamp[56] -= amp[0];
  jamp[72] -= amp[0];
  jamp[74] += amp[0];
  jamp[100] -= amp[0];
  jamp[101] += amp[0];
  jamp[104] += amp[0];
  jamp[105] -= amp[0];
  jamp[110] -= amp[0];
  jamp[111] += amp[0];
  jamp[114] += amp[0];
  jamp[115] -= amp[0];
  VVV1_0( w[8], w[6], w[95], COUPs[0], &amp[0] );
  jamp[14] -= amp[0];
  jamp[26] += amp[0];
  jamp[30] -= amp[0];
  jamp[32] += amp[0];
  jamp[36] -= amp[0];
  jamp[50] += amp[0];
  jamp[60] -= amp[0];
  jamp[74] += amp[0];
  jamp[101] += amp[0];
  jamp[103] -= amp[0];
  jamp[104] += amp[0];
  jamp[105] -= amp[0];
  jamp[106] += amp[0];
  jamp[109] -= amp[0];
  jamp[112] += amp[0];
  jamp[115] -= amp[0];
  VVV1_0( w[8], w[6], w[107], COUPs[0], &amp[0] );
  jamp[12] -= amp[0];
  jamp[26] += amp[0];
  jamp[36] -= amp[0];
  jamp[50] += amp[0];
  jamp[54] -= amp[0];
  jamp[56] += amp[0];
  jamp[60] -= amp[0];
  jamp[72] += amp[0];
  jamp[100] += amp[0];
  jamp[103] -= amp[0];
  jamp[106] += amp[0];
  jamp[109] -= amp[0];
  jamp[110] += amp[0];
  jamp[111] -= amp[0];
  jamp[112] += amp[0];
  jamp[114] -= amp[0];

  // *** DIAGRAM 567 OF 1240 ***

  // Wavefunction(s) for diagram number 567
  VVVV1P0_1( w[92], w[1], w[6], COUPs[2], 0., 0., w[96] );
  VVVV3P0_1( w[92], w[1], w[6], COUPs[2], 0., 0., w[90] );
  VVVV4P0_1( w[92], w[1], w[6], COUPs[2], 0., 0., w[88] );

  // Amplitude(s) for diagram number 567
  VVV1_0( w[8], w[4], w[96], COUPs[0], &amp[0] );
  jamp[13] += amp[0];
  jamp[16] -= amp[0];
  jamp[43] -= amp[0];
  jamp[46] += amp[0];
  jamp[50] -= amp[0];
  jamp[51] += amp[0];
  jamp[58] += amp[0];
  jamp[59] -= amp[0];
  jamp[60] += amp[0];
  jamp[61] -= amp[0];
  jamp[68] -= amp[0];
  jamp[69] += amp[0];
  jamp[73] -= amp[0];
  jamp[76] += amp[0];
  jamp[103] += amp[0];
  jamp[106] -= amp[0];
  VVV1_0( w[8], w[4], w[90], COUPs[0], &amp[0] );
  jamp[16] -= amp[0];
  jamp[27] += amp[0];
  jamp[37] -= amp[0];
  jamp[43] -= amp[0];
  jamp[46] += amp[0];
  jamp[51] += amp[0];
  jamp[54] -= amp[0];
  jamp[56] += amp[0];
  jamp[58] += amp[0];
  jamp[59] -= amp[0];
  jamp[61] -= amp[0];
  jamp[67] -= amp[0];
  jamp[70] += amp[0];
  jamp[76] += amp[0];
  jamp[100] += amp[0];
  jamp[114] -= amp[0];
  VVV1_0( w[8], w[4], w[88], COUPs[0], &amp[0] );
  jamp[13] -= amp[0];
  jamp[27] += amp[0];
  jamp[37] -= amp[0];
  jamp[50] += amp[0];
  jamp[54] -= amp[0];
  jamp[56] += amp[0];
  jamp[60] -= amp[0];
  jamp[67] -= amp[0];
  jamp[68] += amp[0];
  jamp[69] -= amp[0];
  jamp[70] += amp[0];
  jamp[73] += amp[0];
  jamp[100] += amp[0];
  jamp[103] -= amp[0];
  jamp[106] += amp[0];
  jamp[114] -= amp[0];

  // *** DIAGRAM 568 OF 1240 ***

  // Wavefunction(s) for diagram number 568
  // (none)

  // Amplitude(s) for diagram number 568
  VVV1_0( w[1], w[8], w[111], COUPs[0], &amp[0] );
  jamp[15] -= amp[0];
  jamp[17] += amp[0];
  jamp[26] += amp[0];
  jamp[27] -= amp[0];
  jamp[34] -= amp[0];
  jamp[35] += amp[0];
  jamp[36] -= amp[0];
  jamp[37] += amp[0];
  jamp[44] += amp[0];
  jamp[45] -= amp[0];
  jamp[67] += amp[0];
  jamp[70] -= amp[0];
  jamp[75] += amp[0];
  jamp[77] -= amp[0];
  jamp[109] -= amp[0];
  jamp[112] += amp[0];
  VVV1_0( w[1], w[8], w[110], COUPs[0], &amp[0] );
  jamp[17] += amp[0];
  jamp[27] -= amp[0];
  jamp[30] += amp[0];
  jamp[32] -= amp[0];
  jamp[34] -= amp[0];
  jamp[35] += amp[0];
  jamp[37] += amp[0];
  jamp[43] += amp[0];
  jamp[46] -= amp[0];
  jamp[51] -= amp[0];
  jamp[61] += amp[0];
  jamp[67] += amp[0];
  jamp[70] -= amp[0];
  jamp[77] -= amp[0];
  jamp[101] -= amp[0];
  jamp[115] += amp[0];
  VVV1_0( w[1], w[8], w[109], COUPs[0], &amp[0] );
  jamp[15] += amp[0];
  jamp[26] -= amp[0];
  jamp[30] += amp[0];
  jamp[32] -= amp[0];
  jamp[36] += amp[0];
  jamp[43] += amp[0];
  jamp[44] -= amp[0];
  jamp[45] += amp[0];
  jamp[46] -= amp[0];
  jamp[51] -= amp[0];
  jamp[61] += amp[0];
  jamp[75] -= amp[0];
  jamp[101] -= amp[0];
  jamp[109] += amp[0];
  jamp[112] -= amp[0];
  jamp[115] += amp[0];

  // *** DIAGRAM 569 OF 1240 ***

  // Wavefunction(s) for diagram number 569
  // (none)

  // Amplitude(s) for diagram number 569
  VVVV1_0( w[92], w[1], w[8], w[27], COUPs[2], &amp[0] );
  jamp[12] += amp[0];
  jamp[13] -= amp[0];
  jamp[26] -= amp[0];
  jamp[27] += amp[0];
  jamp[36] += amp[0];
  jamp[37] -= amp[0];
  jamp[67] -= amp[0];
  jamp[68] += amp[0];
  jamp[69] -= amp[0];
  jamp[70] += amp[0];
  jamp[72] -= amp[0];
  jamp[73] += amp[0];
  jamp[109] += amp[0];
  jamp[110] -= amp[0];
  jamp[111] += amp[0];
  jamp[112] -= amp[0];
  VVVV3_0( w[92], w[1], w[8], w[27], COUPs[2], &amp[0] );
  jamp[12] += amp[0];
  jamp[13] -= amp[0];
  jamp[15] -= amp[0];
  jamp[17] += amp[0];
  jamp[34] -= amp[0];
  jamp[35] += amp[0];
  jamp[44] += amp[0];
  jamp[45] -= amp[0];
  jamp[68] += amp[0];
  jamp[69] -= amp[0];
  jamp[72] -= amp[0];
  jamp[73] += amp[0];
  jamp[75] += amp[0];
  jamp[77] -= amp[0];
  jamp[110] -= amp[0];
  jamp[111] += amp[0];
  VVVV4_0( w[92], w[1], w[8], w[27], COUPs[2], &amp[0] );
  jamp[15] -= amp[0];
  jamp[17] += amp[0];
  jamp[26] += amp[0];
  jamp[27] -= amp[0];
  jamp[34] -= amp[0];
  jamp[35] += amp[0];
  jamp[36] -= amp[0];
  jamp[37] += amp[0];
  jamp[44] += amp[0];
  jamp[45] -= amp[0];
  jamp[67] += amp[0];
  jamp[70] -= amp[0];
  jamp[75] += amp[0];
  jamp[77] -= amp[0];
  jamp[109] -= amp[0];
  jamp[112] += amp[0];

  // *** DIAGRAM 570 OF 1240 ***

  // Wavefunction(s) for diagram number 570
  // (none)

  // Amplitude(s) for diagram number 570
  VVV1_0( w[8], w[27], w[86], COUPs[0], &amp[0] );
#ifdef MGONGPU_SUPPORTS_MULTICHANNEL
  if( channelId == 570 ) allNumerators[0] += cxabs2( amp[0] );
  if( channelId != 0 ) allDenominators[0] += cxabs2( amp[0] );
#endif
  jamp[12] += amp[0];
  jamp[13] -= amp[0];
  jamp[26] -= amp[0];
  jamp[27] += amp[0];
  jamp[36] += amp[0];
  jamp[37] -= amp[0];
  jamp[67] -= amp[0];
  jamp[68] += amp[0];
  jamp[69] -= amp[0];
  jamp[70] += amp[0];
  jamp[72] -= amp[0];
  jamp[73] += amp[0];
  jamp[109] += amp[0];
  jamp[110] -= amp[0];
  jamp[111] += amp[0];
  jamp[112] -= amp[0];

  // *** DIAGRAM 571 OF 1240 ***

  // Wavefunction(s) for diagram number 571
  // (none)

  // Amplitude(s) for diagram number 571
  VVV1_0( w[1], w[27], w[101], COUPs[0], &amp[0] );
#ifdef MGONGPU_SUPPORTS_MULTICHANNEL
  if( channelId == 571 ) allNumerators[0] += cxabs2( amp[0] );
  if( channelId != 0 ) allDenominators[0] += cxabs2( amp[0] );
#endif
  jamp[12] += amp[0];
  jamp[13] -= amp[0];
  jamp[15] -= amp[0];
  jamp[17] += amp[0];
  jamp[34] -= amp[0];
  jamp[35] += amp[0];
  jamp[44] += amp[0];
  jamp[45] -= amp[0];
  jamp[68] += amp[0];
  jamp[69] -= amp[0];
  jamp[72] -= amp[0];
  jamp[73] += amp[0];
  jamp[75] += amp[0];
  jamp[77] -= amp[0];
  jamp[110] -= amp[0];
  jamp[111] += amp[0];

  // *** DIAGRAM 572 OF 1240 ***

  // Wavefunction(s) for diagram number 572
  // (none)

  // Amplitude(s) for diagram number 572
  VVV1_0( w[1], w[8], w[62], COUPs[0], &amp[0] );
#ifdef MGONGPU_SUPPORTS_MULTICHANNEL
  if( channelId == 572 ) allNumerators[0] += cxabs2( amp[0] );
  if( channelId != 0 ) allDenominators[0] += cxabs2( amp[0] );
#endif
  jamp[15] -= amp[0];
  jamp[17] += amp[0];
  jamp[26] += amp[0];
  jamp[27] -= amp[0];
  jamp[34] -= amp[0];
  jamp[35] += amp[0];
  jamp[36] -= amp[0];
  jamp[37] += amp[0];
  jamp[44] += amp[0];
  jamp[45] -= amp[0];
  jamp[67] += amp[0];
  jamp[70] -= amp[0];
  jamp[75] += amp[0];
  jamp[77] -= amp[0];
  jamp[109] -= amp[0];
  jamp[112] += amp[0];

  // *** DIAGRAM 573 OF 1240 ***

  // Wavefunction(s) for diagram number 573
  // (none)

  // Amplitude(s) for diagram number 573
  VVV1_0( w[86], w[37], w[6], COUPs[0], &amp[0] );
#ifdef MGONGPU_SUPPORTS_MULTICHANNEL
  if( channelId == 573 ) allNumerators[0] += cxabs2( amp[0] );
  if( channelId != 0 ) allDenominators[0] += cxabs2( amp[0] );
#endif
  jamp[50] += cxtype( 0, 1 ) * amp[0];
  jamp[54] -= cxtype( 0, 1 ) * amp[0];
  jamp[56] += cxtype( 0, 1 ) * amp[0];
  jamp[60] -= cxtype( 0, 1 ) * amp[0];
  jamp[67] -= cxtype( 0, 1 ) * amp[0];
  jamp[68] += cxtype( 0, 1 ) * amp[0];
  jamp[69] -= cxtype( 0, 1 ) * amp[0];
  jamp[70] += cxtype( 0, 1 ) * amp[0];

  // *** DIAGRAM 574 OF 1240 ***

  // Wavefunction(s) for diagram number 574
  // (none)

  // Amplitude(s) for diagram number 574
  FFV1_0( w[3], w[36], w[86], COUPs[1], &amp[0] );
#ifdef MGONGPU_SUPPORTS_MULTICHANNEL
  if( channelId == 574 ) allNumerators[0] += cxabs2( amp[0] );
  if( channelId != 0 ) allDenominators[0] += cxabs2( amp[0] );
#endif
  jamp[67] += amp[0];
  jamp[68] -= amp[0];
  jamp[69] += amp[0];
  jamp[70] -= amp[0];

  // *** DIAGRAM 575 OF 1240 ***

  // Wavefunction(s) for diagram number 575
  // (none)

  // Amplitude(s) for diagram number 575
  FFV1_0( w[99], w[100], w[6], COUPs[1], &amp[0] );
#ifdef MGONGPU_SUPPORTS_MULTICHANNEL
  if( channelId == 575 ) allNumerators[0] += cxabs2( amp[0] );
  if( channelId != 0 ) allDenominators[0] += cxabs2( amp[0] );
#endif
  jamp[58] += cxtype( 0, 1 ) * amp[0];
  jamp[59] -= cxtype( 0, 1 ) * amp[0];

  // *** DIAGRAM 576 OF 1240 ***

  // Wavefunction(s) for diagram number 576
  // (none)

  // Amplitude(s) for diagram number 576
  FFV1_0( w[99], w[36], w[1], COUPs[1], &amp[0] );
#ifdef MGONGPU_SUPPORTS_MULTICHANNEL
  if( channelId == 576 ) allNumerators[0] += cxabs2( amp[0] );
  if( channelId != 0 ) allDenominators[0] += cxabs2( amp[0] );
#endif
  jamp[68] += cxtype( 0, 1 ) * amp[0];
  jamp[69] -= cxtype( 0, 1 ) * amp[0];

  // *** DIAGRAM 577 OF 1240 ***

  // Wavefunction(s) for diagram number 577
  // (none)

  // Amplitude(s) for diagram number 577
  FFV1_0( w[3], w[100], w[104], COUPs[1], &amp[0] );
#ifdef MGONGPU_SUPPORTS_MULTICHANNEL
  if( channelId == 577 ) allNumerators[0] += cxabs2( amp[0] );
  if( channelId != 0 ) allDenominators[0] += cxabs2( amp[0] );
#endif
  jamp[54] += amp[0];
  jamp[56] -= amp[0];
  jamp[58] -= amp[0];
  jamp[59] += amp[0];

  // *** DIAGRAM 578 OF 1240 ***

  // Wavefunction(s) for diagram number 578
  // (none)

  // Amplitude(s) for diagram number 578
  VVV1_0( w[104], w[1], w[37], COUPs[0], &amp[0] );
#ifdef MGONGPU_SUPPORTS_MULTICHANNEL
  if( channelId == 578 ) allNumerators[0] += cxabs2( amp[0] );
  if( channelId != 0 ) allDenominators[0] += cxabs2( amp[0] );
#endif
  jamp[51] -= cxtype( 0, 1 ) * amp[0];
  jamp[54] += cxtype( 0, 1 ) * amp[0];
  jamp[56] -= cxtype( 0, 1 ) * amp[0];
  jamp[58] -= cxtype( 0, 1 ) * amp[0];
  jamp[59] += cxtype( 0, 1 ) * amp[0];
  jamp[61] += cxtype( 0, 1 ) * amp[0];
  jamp[67] += cxtype( 0, 1 ) * amp[0];
  jamp[70] -= cxtype( 0, 1 ) * amp[0];

  // *** DIAGRAM 579 OF 1240 ***

  // Wavefunction(s) for diagram number 579
  // (none)

  // Amplitude(s) for diagram number 579
  FFV1_0( w[3], w[33], w[96], COUPs[1], &amp[0] );
  jamp[50] -= cxtype( 0, 1 ) * amp[0];
  jamp[51] += cxtype( 0, 1 ) * amp[0];
  jamp[58] += cxtype( 0, 1 ) * amp[0];
  jamp[59] -= cxtype( 0, 1 ) * amp[0];
  jamp[60] += cxtype( 0, 1 ) * amp[0];
  jamp[61] -= cxtype( 0, 1 ) * amp[0];
  jamp[68] -= cxtype( 0, 1 ) * amp[0];
  jamp[69] += cxtype( 0, 1 ) * amp[0];
  FFV1_0( w[3], w[33], w[90], COUPs[1], &amp[0] );
  jamp[51] += cxtype( 0, 1 ) * amp[0];
  jamp[54] -= cxtype( 0, 1 ) * amp[0];
  jamp[56] += cxtype( 0, 1 ) * amp[0];
  jamp[58] += cxtype( 0, 1 ) * amp[0];
  jamp[59] -= cxtype( 0, 1 ) * amp[0];
  jamp[61] -= cxtype( 0, 1 ) * amp[0];
  jamp[67] -= cxtype( 0, 1 ) * amp[0];
  jamp[70] += cxtype( 0, 1 ) * amp[0];
  FFV1_0( w[3], w[33], w[88], COUPs[1], &amp[0] );
  jamp[50] += cxtype( 0, 1 ) * amp[0];
  jamp[54] -= cxtype( 0, 1 ) * amp[0];
  jamp[56] += cxtype( 0, 1 ) * amp[0];
  jamp[60] -= cxtype( 0, 1 ) * amp[0];
  jamp[67] -= cxtype( 0, 1 ) * amp[0];
  jamp[68] += cxtype( 0, 1 ) * amp[0];
  jamp[69] -= cxtype( 0, 1 ) * amp[0];
  jamp[70] += cxtype( 0, 1 ) * amp[0];

  // *** DIAGRAM 580 OF 1240 ***

  // Wavefunction(s) for diagram number 580
  // (none)

  // Amplitude(s) for diagram number 580
  FFV1_0( w[41], w[33], w[86], COUPs[1], &amp[0] );
#ifdef MGONGPU_SUPPORTS_MULTICHANNEL
  if( channelId == 580 ) allNumerators[0] += cxabs2( amp[0] );
  if( channelId != 0 ) allDenominators[0] += cxabs2( amp[0] );
#endif
  jamp[50] += amp[0];
  jamp[54] -= amp[0];
  jamp[56] += amp[0];
  jamp[60] -= amp[0];

  // *** DIAGRAM 581 OF 1240 ***

  // Wavefunction(s) for diagram number 581
  // (none)

  // Amplitude(s) for diagram number 581
  FFV1_0( w[41], w[98], w[1], COUPs[1], &amp[0] );
#ifdef MGONGPU_SUPPORTS_MULTICHANNEL
  if( channelId == 581 ) allNumerators[0] += cxabs2( amp[0] );
  if( channelId != 0 ) allDenominators[0] += cxabs2( amp[0] );
#endif
  jamp[50] += cxtype( 0, 1 ) * amp[0];
  jamp[60] -= cxtype( 0, 1 ) * amp[0];

  // *** DIAGRAM 582 OF 1240 ***

  // Wavefunction(s) for diagram number 582
  // (none)

  // Amplitude(s) for diagram number 582
  FFV1_0( w[113], w[33], w[1], COUPs[1], &amp[0] );
#ifdef MGONGPU_SUPPORTS_MULTICHANNEL
  if( channelId == 582 ) allNumerators[0] += cxabs2( amp[0] );
  if( channelId != 0 ) allDenominators[0] += cxabs2( amp[0] );
#endif
  jamp[54] += cxtype( 0, 1 ) * amp[0];
  jamp[56] -= cxtype( 0, 1 ) * amp[0];

  // *** DIAGRAM 583 OF 1240 ***

  // Wavefunction(s) for diagram number 583
  // (none)

  // Amplitude(s) for diagram number 583
  VVV1_0( w[86], w[51], w[4], COUPs[0], &amp[0] );
#ifdef MGONGPU_SUPPORTS_MULTICHANNEL
  if( channelId == 583 ) allNumerators[0] += cxabs2( amp[0] );
  if( channelId != 0 ) allDenominators[0] += cxabs2( amp[0] );
#endif
  jamp[100] += cxtype( 0, 1 ) * amp[0];
  jamp[103] -= cxtype( 0, 1 ) * amp[0];
  jamp[106] += cxtype( 0, 1 ) * amp[0];
  jamp[109] -= cxtype( 0, 1 ) * amp[0];
  jamp[110] += cxtype( 0, 1 ) * amp[0];
  jamp[111] -= cxtype( 0, 1 ) * amp[0];
  jamp[112] += cxtype( 0, 1 ) * amp[0];
  jamp[114] -= cxtype( 0, 1 ) * amp[0];

  // *** DIAGRAM 584 OF 1240 ***

  // Wavefunction(s) for diagram number 584
  // (none)

  // Amplitude(s) for diagram number 584
  FFV1_0( w[3], w[49], w[86], COUPs[1], &amp[0] );
#ifdef MGONGPU_SUPPORTS_MULTICHANNEL
  if( channelId == 584 ) allNumerators[0] += cxabs2( amp[0] );
  if( channelId != 0 ) allDenominators[0] += cxabs2( amp[0] );
#endif
  jamp[109] += amp[0];
  jamp[110] -= amp[0];
  jamp[111] += amp[0];
  jamp[112] -= amp[0];

  // *** DIAGRAM 585 OF 1240 ***

  // Wavefunction(s) for diagram number 585
  // (none)

  // Amplitude(s) for diagram number 585
  FFV1_0( w[99], w[91], w[4], COUPs[1], &amp[0] );
#ifdef MGONGPU_SUPPORTS_MULTICHANNEL
  if( channelId == 585 ) allNumerators[0] += cxabs2( amp[0] );
  if( channelId != 0 ) allDenominators[0] += cxabs2( amp[0] );
#endif
  jamp[104] += cxtype( 0, 1 ) * amp[0];
  jamp[105] -= cxtype( 0, 1 ) * amp[0];

  // *** DIAGRAM 586 OF 1240 ***

  // Wavefunction(s) for diagram number 586
  // (none)

  // Amplitude(s) for diagram number 586
  FFV1_0( w[99], w[49], w[1], COUPs[1], &amp[0] );
#ifdef MGONGPU_SUPPORTS_MULTICHANNEL
  if( channelId == 586 ) allNumerators[0] += cxabs2( amp[0] );
  if( channelId != 0 ) allDenominators[0] += cxabs2( amp[0] );
#endif
  jamp[110] += cxtype( 0, 1 ) * amp[0];
  jamp[111] -= cxtype( 0, 1 ) * amp[0];

  // *** DIAGRAM 587 OF 1240 ***

  // Wavefunction(s) for diagram number 587
  // (none)

  // Amplitude(s) for diagram number 587
  FFV1_0( w[3], w[91], w[102], COUPs[1], &amp[0] );
#ifdef MGONGPU_SUPPORTS_MULTICHANNEL
  if( channelId == 587 ) allNumerators[0] += cxabs2( amp[0] );
  if( channelId != 0 ) allDenominators[0] += cxabs2( amp[0] );
#endif
  jamp[103] += amp[0];
  jamp[104] -= amp[0];
  jamp[105] += amp[0];
  jamp[106] -= amp[0];

  // *** DIAGRAM 588 OF 1240 ***

  // Wavefunction(s) for diagram number 588
  // (none)

  // Amplitude(s) for diagram number 588
  VVV1_0( w[102], w[1], w[51], COUPs[0], &amp[0] );
#ifdef MGONGPU_SUPPORTS_MULTICHANNEL
  if( channelId == 588 ) allNumerators[0] += cxabs2( amp[0] );
  if( channelId != 0 ) allDenominators[0] += cxabs2( amp[0] );
#endif
  jamp[101] -= cxtype( 0, 1 ) * amp[0];
  jamp[103] += cxtype( 0, 1 ) * amp[0];
  jamp[104] -= cxtype( 0, 1 ) * amp[0];
  jamp[105] += cxtype( 0, 1 ) * amp[0];
  jamp[106] -= cxtype( 0, 1 ) * amp[0];
  jamp[109] += cxtype( 0, 1 ) * amp[0];
  jamp[112] -= cxtype( 0, 1 ) * amp[0];
  jamp[115] += cxtype( 0, 1 ) * amp[0];

  // *** DIAGRAM 589 OF 1240 ***

  // Wavefunction(s) for diagram number 589
  // (none)

  // Amplitude(s) for diagram number 589
  FFV1_0( w[3], w[47], w[105], COUPs[1], &amp[0] );
  jamp[100] -= cxtype( 0, 1 ) * amp[0];
  jamp[101] += cxtype( 0, 1 ) * amp[0];
  jamp[104] += cxtype( 0, 1 ) * amp[0];
  jamp[105] -= cxtype( 0, 1 ) * amp[0];
  jamp[110] -= cxtype( 0, 1 ) * amp[0];
  jamp[111] += cxtype( 0, 1 ) * amp[0];
  jamp[114] += cxtype( 0, 1 ) * amp[0];
  jamp[115] -= cxtype( 0, 1 ) * amp[0];
  FFV1_0( w[3], w[47], w[95], COUPs[1], &amp[0] );
  jamp[101] += cxtype( 0, 1 ) * amp[0];
  jamp[103] -= cxtype( 0, 1 ) * amp[0];
  jamp[104] += cxtype( 0, 1 ) * amp[0];
  jamp[105] -= cxtype( 0, 1 ) * amp[0];
  jamp[106] += cxtype( 0, 1 ) * amp[0];
  jamp[109] -= cxtype( 0, 1 ) * amp[0];
  jamp[112] += cxtype( 0, 1 ) * amp[0];
  jamp[115] -= cxtype( 0, 1 ) * amp[0];
  FFV1_0( w[3], w[47], w[107], COUPs[1], &amp[0] );
  jamp[100] += cxtype( 0, 1 ) * amp[0];
  jamp[103] -= cxtype( 0, 1 ) * amp[0];
  jamp[106] += cxtype( 0, 1 ) * amp[0];
  jamp[109] -= cxtype( 0, 1 ) * amp[0];
  jamp[110] += cxtype( 0, 1 ) * amp[0];
  jamp[111] -= cxtype( 0, 1 ) * amp[0];
  jamp[112] += cxtype( 0, 1 ) * amp[0];
  jamp[114] -= cxtype( 0, 1 ) * amp[0];

  // *** DIAGRAM 590 OF 1240 ***

  // Wavefunction(s) for diagram number 590
  // (none)

  // Amplitude(s) for diagram number 590
  FFV1_0( w[46], w[47], w[86], COUPs[1], &amp[0] );
#ifdef MGONGPU_SUPPORTS_MULTICHANNEL
  if( channelId == 590 ) allNumerators[0] += cxabs2( amp[0] );
  if( channelId != 0 ) allDenominators[0] += cxabs2( amp[0] );
#endif
  jamp[100] += amp[0];
  jamp[103] -= amp[0];
  jamp[106] += amp[0];
  jamp[114] -= amp[0];

  // *** DIAGRAM 591 OF 1240 ***

  // Wavefunction(s) for diagram number 591
  // (none)

  // Amplitude(s) for diagram number 591
  FFV1_0( w[46], w[106], w[1], COUPs[1], &amp[0] );
#ifdef MGONGPU_SUPPORTS_MULTICHANNEL
  if( channelId == 591 ) allNumerators[0] += cxabs2( amp[0] );
  if( channelId != 0 ) allDenominators[0] += cxabs2( amp[0] );
#endif
  jamp[100] += cxtype( 0, 1 ) * amp[0];
  jamp[114] -= cxtype( 0, 1 ) * amp[0];

  // *** DIAGRAM 592 OF 1240 ***

  // Wavefunction(s) for diagram number 592
  // (none)

  // Amplitude(s) for diagram number 592
  FFV1_0( w[114], w[47], w[1], COUPs[1], &amp[0] );
#ifdef MGONGPU_SUPPORTS_MULTICHANNEL
  if( channelId == 592 ) allNumerators[0] += cxabs2( amp[0] );
  if( channelId != 0 ) allDenominators[0] += cxabs2( amp[0] );
#endif
  jamp[103] += cxtype( 0, 1 ) * amp[0];
  jamp[106] -= cxtype( 0, 1 ) * amp[0];

  // *** DIAGRAM 593 OF 1240 ***

  // Wavefunction(s) for diagram number 593
  // (none)

  // Amplitude(s) for diagram number 593
  VVV1_0( w[86], w[54], w[6], COUPs[0], &amp[0] );
#ifdef MGONGPU_SUPPORTS_MULTICHANNEL
  if( channelId == 593 ) allNumerators[0] += cxabs2( amp[0] );
  if( channelId != 0 ) allDenominators[0] += cxabs2( amp[0] );
#endif
  jamp[13] += cxtype( 0, 1 ) * amp[0];
  jamp[27] -= cxtype( 0, 1 ) * amp[0];
  jamp[37] += cxtype( 0, 1 ) * amp[0];
  jamp[73] -= cxtype( 0, 1 ) * amp[0];
  jamp[100] -= cxtype( 0, 1 ) * amp[0];
  jamp[103] += cxtype( 0, 1 ) * amp[0];
  jamp[106] -= cxtype( 0, 1 ) * amp[0];
  jamp[114] += cxtype( 0, 1 ) * amp[0];

  // *** DIAGRAM 594 OF 1240 ***

  // Wavefunction(s) for diagram number 594
  // (none)

  // Amplitude(s) for diagram number 594
  FFV1_0( w[53], w[2], w[86], COUPs[1], &amp[0] );
#ifdef MGONGPU_SUPPORTS_MULTICHANNEL
  if( channelId == 594 ) allNumerators[0] += cxabs2( amp[0] );
  if( channelId != 0 ) allDenominators[0] += cxabs2( amp[0] );
#endif
  jamp[13] += amp[0];
  jamp[27] -= amp[0];
  jamp[37] += amp[0];
  jamp[73] -= amp[0];

  // *** DIAGRAM 595 OF 1240 ***

  // Wavefunction(s) for diagram number 595
  // (none)

  // Amplitude(s) for diagram number 595
  FFV1_0( w[78], w[112], w[6], COUPs[1], &amp[0] );
#ifdef MGONGPU_SUPPORTS_MULTICHANNEL
  if( channelId == 595 ) allNumerators[0] += cxabs2( amp[0] );
  if( channelId != 0 ) allDenominators[0] += cxabs2( amp[0] );
#endif
  jamp[16] += cxtype( 0, 1 ) * amp[0];
  jamp[76] -= cxtype( 0, 1 ) * amp[0];

  // *** DIAGRAM 596 OF 1240 ***

  // Wavefunction(s) for diagram number 596
  // (none)

  // Amplitude(s) for diagram number 596
  FFV1_0( w[53], w[112], w[1], COUPs[1], &amp[0] );
#ifdef MGONGPU_SUPPORTS_MULTICHANNEL
  if( channelId == 596 ) allNumerators[0] += cxabs2( amp[0] );
  if( channelId != 0 ) allDenominators[0] += cxabs2( amp[0] );
#endif
  jamp[13] += cxtype( 0, 1 ) * amp[0];
  jamp[73] -= cxtype( 0, 1 ) * amp[0];

  // *** DIAGRAM 597 OF 1240 ***

  // Wavefunction(s) for diagram number 597
  // (none)

  // Amplitude(s) for diagram number 597
  FFV1_0( w[78], w[2], w[104], COUPs[1], &amp[0] );
#ifdef MGONGPU_SUPPORTS_MULTICHANNEL
  if( channelId == 597 ) allNumerators[0] += cxabs2( amp[0] );
  if( channelId != 0 ) allDenominators[0] += cxabs2( amp[0] );
#endif
  jamp[16] += amp[0];
  jamp[76] -= amp[0];
  jamp[100] -= amp[0];
  jamp[114] += amp[0];

  // *** DIAGRAM 598 OF 1240 ***

  // Wavefunction(s) for diagram number 598
  // (none)

  // Amplitude(s) for diagram number 598
  VVV1_0( w[104], w[1], w[54], COUPs[0], &amp[0] );
#ifdef MGONGPU_SUPPORTS_MULTICHANNEL
  if( channelId == 598 ) allNumerators[0] += cxabs2( amp[0] );
  if( channelId != 0 ) allDenominators[0] += cxabs2( amp[0] );
#endif
  jamp[16] -= cxtype( 0, 1 ) * amp[0];
  jamp[27] += cxtype( 0, 1 ) * amp[0];
  jamp[37] -= cxtype( 0, 1 ) * amp[0];
  jamp[43] -= cxtype( 0, 1 ) * amp[0];
  jamp[46] += cxtype( 0, 1 ) * amp[0];
  jamp[76] += cxtype( 0, 1 ) * amp[0];
  jamp[100] += cxtype( 0, 1 ) * amp[0];
  jamp[114] -= cxtype( 0, 1 ) * amp[0];

  // *** DIAGRAM 599 OF 1240 ***

  // Wavefunction(s) for diagram number 599
  // (none)

  // Amplitude(s) for diagram number 599
  FFV1_0( w[46], w[2], w[96], COUPs[1], &amp[0] );
  jamp[13] -= cxtype( 0, 1 ) * amp[0];
  jamp[16] += cxtype( 0, 1 ) * amp[0];
  jamp[43] += cxtype( 0, 1 ) * amp[0];
  jamp[46] -= cxtype( 0, 1 ) * amp[0];
  jamp[73] += cxtype( 0, 1 ) * amp[0];
  jamp[76] -= cxtype( 0, 1 ) * amp[0];
  jamp[103] -= cxtype( 0, 1 ) * amp[0];
  jamp[106] += cxtype( 0, 1 ) * amp[0];
  FFV1_0( w[46], w[2], w[90], COUPs[1], &amp[0] );
  jamp[16] += cxtype( 0, 1 ) * amp[0];
  jamp[27] -= cxtype( 0, 1 ) * amp[0];
  jamp[37] += cxtype( 0, 1 ) * amp[0];
  jamp[43] += cxtype( 0, 1 ) * amp[0];
  jamp[46] -= cxtype( 0, 1 ) * amp[0];
  jamp[76] -= cxtype( 0, 1 ) * amp[0];
  jamp[100] -= cxtype( 0, 1 ) * amp[0];
  jamp[114] += cxtype( 0, 1 ) * amp[0];
  FFV1_0( w[46], w[2], w[88], COUPs[1], &amp[0] );
  jamp[13] += cxtype( 0, 1 ) * amp[0];
  jamp[27] -= cxtype( 0, 1 ) * amp[0];
  jamp[37] += cxtype( 0, 1 ) * amp[0];
  jamp[73] -= cxtype( 0, 1 ) * amp[0];
  jamp[100] -= cxtype( 0, 1 ) * amp[0];
  jamp[103] += cxtype( 0, 1 ) * amp[0];
  jamp[106] -= cxtype( 0, 1 ) * amp[0];
  jamp[114] += cxtype( 0, 1 ) * amp[0];

  // *** DIAGRAM 600 OF 1240 ***

  // Wavefunction(s) for diagram number 600
  // (none)

  // Amplitude(s) for diagram number 600
  VVV1_0( w[86], w[20], w[4], COUPs[0], &amp[0] );
#ifdef MGONGPU_SUPPORTS_MULTICHANNEL
  if( channelId == 600 ) allNumerators[0] += cxabs2( amp[0] );
  if( channelId != 0 ) allDenominators[0] += cxabs2( amp[0] );
#endif
  jamp[12] += cxtype( 0, 1 ) * amp[0];
  jamp[26] -= cxtype( 0, 1 ) * amp[0];
  jamp[36] += cxtype( 0, 1 ) * amp[0];
  jamp[50] -= cxtype( 0, 1 ) * amp[0];
  jamp[54] += cxtype( 0, 1 ) * amp[0];
  jamp[56] -= cxtype( 0, 1 ) * amp[0];
  jamp[60] += cxtype( 0, 1 ) * amp[0];
  jamp[72] -= cxtype( 0, 1 ) * amp[0];

  // *** DIAGRAM 601 OF 1240 ***

  // Wavefunction(s) for diagram number 601
  // (none)

  // Amplitude(s) for diagram number 601
  FFV1_0( w[28], w[2], w[86], COUPs[1], &amp[0] );
#ifdef MGONGPU_SUPPORTS_MULTICHANNEL
  if( channelId == 601 ) allNumerators[0] += cxabs2( amp[0] );
  if( channelId != 0 ) allDenominators[0] += cxabs2( amp[0] );
#endif
  jamp[12] += amp[0];
  jamp[26] -= amp[0];
  jamp[36] += amp[0];
  jamp[72] -= amp[0];

  // *** DIAGRAM 602 OF 1240 ***

  // Wavefunction(s) for diagram number 602
  // (none)

  // Amplitude(s) for diagram number 602
  FFV1_0( w[60], w[112], w[4], COUPs[1], &amp[0] );
#ifdef MGONGPU_SUPPORTS_MULTICHANNEL
  if( channelId == 602 ) allNumerators[0] += cxabs2( amp[0] );
  if( channelId != 0 ) allDenominators[0] += cxabs2( amp[0] );
#endif
  jamp[14] += cxtype( 0, 1 ) * amp[0];
  jamp[74] -= cxtype( 0, 1 ) * amp[0];

  // *** DIAGRAM 603 OF 1240 ***

  // Wavefunction(s) for diagram number 603
  // (none)

  // Amplitude(s) for diagram number 603
  FFV1_0( w[28], w[112], w[1], COUPs[1], &amp[0] );
#ifdef MGONGPU_SUPPORTS_MULTICHANNEL
  if( channelId == 603 ) allNumerators[0] += cxabs2( amp[0] );
  if( channelId != 0 ) allDenominators[0] += cxabs2( amp[0] );
#endif
  jamp[12] += cxtype( 0, 1 ) * amp[0];
  jamp[72] -= cxtype( 0, 1 ) * amp[0];

  // *** DIAGRAM 604 OF 1240 ***

  // Wavefunction(s) for diagram number 604
  // (none)

  // Amplitude(s) for diagram number 604
  FFV1_0( w[60], w[2], w[102], COUPs[1], &amp[0] );
#ifdef MGONGPU_SUPPORTS_MULTICHANNEL
  if( channelId == 604 ) allNumerators[0] += cxabs2( amp[0] );
  if( channelId != 0 ) allDenominators[0] += cxabs2( amp[0] );
#endif
  jamp[14] += amp[0];
  jamp[50] -= amp[0];
  jamp[60] += amp[0];
  jamp[74] -= amp[0];

  // *** DIAGRAM 605 OF 1240 ***

  // Wavefunction(s) for diagram number 605
  // (none)

  // Amplitude(s) for diagram number 605
  VVV1_0( w[102], w[1], w[20], COUPs[0], &amp[0] );
#ifdef MGONGPU_SUPPORTS_MULTICHANNEL
  if( channelId == 605 ) allNumerators[0] += cxabs2( amp[0] );
  if( channelId != 0 ) allDenominators[0] += cxabs2( amp[0] );
#endif
  jamp[14] -= cxtype( 0, 1 ) * amp[0];
  jamp[26] += cxtype( 0, 1 ) * amp[0];
  jamp[30] -= cxtype( 0, 1 ) * amp[0];
  jamp[32] += cxtype( 0, 1 ) * amp[0];
  jamp[36] -= cxtype( 0, 1 ) * amp[0];
  jamp[50] += cxtype( 0, 1 ) * amp[0];
  jamp[60] -= cxtype( 0, 1 ) * amp[0];
  jamp[74] += cxtype( 0, 1 ) * amp[0];

  // *** DIAGRAM 606 OF 1240 ***

  // Wavefunction(s) for diagram number 606
  // (none)

  // Amplitude(s) for diagram number 606
  FFV1_0( w[41], w[2], w[105], COUPs[1], &amp[0] );
  jamp[12] -= cxtype( 0, 1 ) * amp[0];
  jamp[14] += cxtype( 0, 1 ) * amp[0];
  jamp[30] += cxtype( 0, 1 ) * amp[0];
  jamp[32] -= cxtype( 0, 1 ) * amp[0];
  jamp[54] -= cxtype( 0, 1 ) * amp[0];
  jamp[56] += cxtype( 0, 1 ) * amp[0];
  jamp[72] += cxtype( 0, 1 ) * amp[0];
  jamp[74] -= cxtype( 0, 1 ) * amp[0];
  FFV1_0( w[41], w[2], w[95], COUPs[1], &amp[0] );
  jamp[14] += cxtype( 0, 1 ) * amp[0];
  jamp[26] -= cxtype( 0, 1 ) * amp[0];
  jamp[30] += cxtype( 0, 1 ) * amp[0];
  jamp[32] -= cxtype( 0, 1 ) * amp[0];
  jamp[36] += cxtype( 0, 1 ) * amp[0];
  jamp[50] -= cxtype( 0, 1 ) * amp[0];
  jamp[60] += cxtype( 0, 1 ) * amp[0];
  jamp[74] -= cxtype( 0, 1 ) * amp[0];
  FFV1_0( w[41], w[2], w[107], COUPs[1], &amp[0] );
  jamp[12] += cxtype( 0, 1 ) * amp[0];
  jamp[26] -= cxtype( 0, 1 ) * amp[0];
  jamp[36] += cxtype( 0, 1 ) * amp[0];
  jamp[50] -= cxtype( 0, 1 ) * amp[0];
  jamp[54] += cxtype( 0, 1 ) * amp[0];
  jamp[56] -= cxtype( 0, 1 ) * amp[0];
  jamp[60] += cxtype( 0, 1 ) * amp[0];
  jamp[72] -= cxtype( 0, 1 ) * amp[0];

  // *** DIAGRAM 607 OF 1240 ***

  // Wavefunction(s) for diagram number 607
  // (none)

  // Amplitude(s) for diagram number 607
  FFV1_0( w[3], w[15], w[86], COUPs[1], &amp[0] );
#ifdef MGONGPU_SUPPORTS_MULTICHANNEL
  if( channelId == 607 ) allNumerators[0] += cxabs2( amp[0] );
  if( channelId != 0 ) allDenominators[0] += cxabs2( amp[0] );
#endif
  jamp[67] -= cxtype( 0, 1 ) * amp[0];
  jamp[68] += cxtype( 0, 1 ) * amp[0];
  jamp[69] -= cxtype( 0, 1 ) * amp[0];
  jamp[70] += cxtype( 0, 1 ) * amp[0];
  jamp[109] += cxtype( 0, 1 ) * amp[0];
  jamp[110] -= cxtype( 0, 1 ) * amp[0];
  jamp[111] += cxtype( 0, 1 ) * amp[0];
  jamp[112] -= cxtype( 0, 1 ) * amp[0];

  // *** DIAGRAM 608 OF 1240 ***

  // Wavefunction(s) for diagram number 608
  // (none)

  // Amplitude(s) for diagram number 608
  FFV1_0( w[14], w[2], w[86], COUPs[1], &amp[0] );
#ifdef MGONGPU_SUPPORTS_MULTICHANNEL
  if( channelId == 608 ) allNumerators[0] += cxabs2( amp[0] );
  if( channelId != 0 ) allDenominators[0] += cxabs2( amp[0] );
#endif
  jamp[12] -= cxtype( 0, 1 ) * amp[0];
  jamp[13] += cxtype( 0, 1 ) * amp[0];
  jamp[26] += cxtype( 0, 1 ) * amp[0];
  jamp[27] -= cxtype( 0, 1 ) * amp[0];
  jamp[36] -= cxtype( 0, 1 ) * amp[0];
  jamp[37] += cxtype( 0, 1 ) * amp[0];
  jamp[72] += cxtype( 0, 1 ) * amp[0];
  jamp[73] -= cxtype( 0, 1 ) * amp[0];

  // *** DIAGRAM 609 OF 1240 ***

  // Wavefunction(s) for diagram number 609
  // (none)

  // Amplitude(s) for diagram number 609
  FFV1_0( w[3], w[112], w[68], COUPs[1], &amp[0] );
#ifdef MGONGPU_SUPPORTS_MULTICHANNEL
  if( channelId == 609 ) allNumerators[0] += cxabs2( amp[0] );
  if( channelId != 0 ) allDenominators[0] += cxabs2( amp[0] );
#endif
  jamp[12] -= cxtype( 0, 1 ) * amp[0];
  jamp[13] += cxtype( 0, 1 ) * amp[0];
  jamp[15] += cxtype( 0, 1 ) * amp[0];
  jamp[17] -= cxtype( 0, 1 ) * amp[0];
  jamp[72] += cxtype( 0, 1 ) * amp[0];
  jamp[73] -= cxtype( 0, 1 ) * amp[0];
  jamp[75] -= cxtype( 0, 1 ) * amp[0];
  jamp[77] += cxtype( 0, 1 ) * amp[0];

  // *** DIAGRAM 610 OF 1240 ***

  // Wavefunction(s) for diagram number 610
  // (none)

  // Amplitude(s) for diagram number 610
  FFV1_0( w[14], w[112], w[1], COUPs[1], &amp[0] );
#ifdef MGONGPU_SUPPORTS_MULTICHANNEL
  if( channelId == 610 ) allNumerators[0] += cxabs2( amp[0] );
  if( channelId != 0 ) allDenominators[0] += cxabs2( amp[0] );
#endif
  jamp[12] += amp[0];
  jamp[13] -= amp[0];
  jamp[72] -= amp[0];
  jamp[73] += amp[0];

  // *** DIAGRAM 611 OF 1240 ***

  // Wavefunction(s) for diagram number 611
  // (none)

  // Amplitude(s) for diagram number 611
  FFV1_0( w[99], w[2], w[68], COUPs[1], &amp[0] );
#ifdef MGONGPU_SUPPORTS_MULTICHANNEL
  if( channelId == 611 ) allNumerators[0] += cxabs2( amp[0] );
  if( channelId != 0 ) allDenominators[0] += cxabs2( amp[0] );
#endif
  jamp[34] -= cxtype( 0, 1 ) * amp[0];
  jamp[35] += cxtype( 0, 1 ) * amp[0];
  jamp[44] += cxtype( 0, 1 ) * amp[0];
  jamp[45] -= cxtype( 0, 1 ) * amp[0];
  jamp[68] += cxtype( 0, 1 ) * amp[0];
  jamp[69] -= cxtype( 0, 1 ) * amp[0];
  jamp[110] -= cxtype( 0, 1 ) * amp[0];
  jamp[111] += cxtype( 0, 1 ) * amp[0];

  // *** DIAGRAM 612 OF 1240 ***

  // Wavefunction(s) for diagram number 612
  // (none)

  // Amplitude(s) for diagram number 612
  FFV1_0( w[99], w[15], w[1], COUPs[1], &amp[0] );
#ifdef MGONGPU_SUPPORTS_MULTICHANNEL
  if( channelId == 612 ) allNumerators[0] += cxabs2( amp[0] );
  if( channelId != 0 ) allDenominators[0] += cxabs2( amp[0] );
#endif
  jamp[68] += amp[0];
  jamp[69] -= amp[0];
  jamp[110] -= amp[0];
  jamp[111] += amp[0];

  // *** DIAGRAM 613 OF 1240 ***

  // Wavefunction(s) for diagram number 613
  // (none)

  // Amplitude(s) for diagram number 613
  FFV1_0( w[3], w[112], w[57], COUPs[1], &amp[0] );
  jamp[12] -= cxtype( 0, 1 ) * amp[0];
  jamp[13] += cxtype( 0, 1 ) * amp[0];
  jamp[15] += cxtype( 0, 1 ) * amp[0];
  jamp[17] -= cxtype( 0, 1 ) * amp[0];
  jamp[72] += cxtype( 0, 1 ) * amp[0];
  jamp[73] -= cxtype( 0, 1 ) * amp[0];
  jamp[75] -= cxtype( 0, 1 ) * amp[0];
  jamp[77] += cxtype( 0, 1 ) * amp[0];
  FFV1_0( w[3], w[112], w[81], COUPs[1], &amp[0] );
  jamp[13] += cxtype( 0, 1 ) * amp[0];
  jamp[14] -= cxtype( 0, 1 ) * amp[0];
  jamp[15] += cxtype( 0, 1 ) * amp[0];
  jamp[16] -= cxtype( 0, 1 ) * amp[0];
  jamp[73] -= cxtype( 0, 1 ) * amp[0];
  jamp[74] += cxtype( 0, 1 ) * amp[0];
  jamp[75] -= cxtype( 0, 1 ) * amp[0];
  jamp[76] += cxtype( 0, 1 ) * amp[0];
  FFV1_0( w[3], w[112], w[82], COUPs[1], &amp[0] );
  jamp[12] += cxtype( 0, 1 ) * amp[0];
  jamp[14] -= cxtype( 0, 1 ) * amp[0];
  jamp[16] -= cxtype( 0, 1 ) * amp[0];
  jamp[17] += cxtype( 0, 1 ) * amp[0];
  jamp[72] -= cxtype( 0, 1 ) * amp[0];
  jamp[74] += cxtype( 0, 1 ) * amp[0];
  jamp[76] += cxtype( 0, 1 ) * amp[0];
  jamp[77] -= cxtype( 0, 1 ) * amp[0];

  // *** DIAGRAM 614 OF 1240 ***

  // Wavefunction(s) for diagram number 614
  // (none)

  // Amplitude(s) for diagram number 614
  FFV1_0( w[99], w[2], w[57], COUPs[1], &amp[0] );
  jamp[34] -= cxtype( 0, 1 ) * amp[0];
  jamp[35] += cxtype( 0, 1 ) * amp[0];
  jamp[44] += cxtype( 0, 1 ) * amp[0];
  jamp[45] -= cxtype( 0, 1 ) * amp[0];
  jamp[68] += cxtype( 0, 1 ) * amp[0];
  jamp[69] -= cxtype( 0, 1 ) * amp[0];
  jamp[110] -= cxtype( 0, 1 ) * amp[0];
  jamp[111] += cxtype( 0, 1 ) * amp[0];
  FFV1_0( w[99], w[2], w[81], COUPs[1], &amp[0] );
  jamp[44] += cxtype( 0, 1 ) * amp[0];
  jamp[45] -= cxtype( 0, 1 ) * amp[0];
  jamp[58] -= cxtype( 0, 1 ) * amp[0];
  jamp[59] += cxtype( 0, 1 ) * amp[0];
  jamp[68] += cxtype( 0, 1 ) * amp[0];
  jamp[69] -= cxtype( 0, 1 ) * amp[0];
  jamp[104] -= cxtype( 0, 1 ) * amp[0];
  jamp[105] += cxtype( 0, 1 ) * amp[0];
  FFV1_0( w[99], w[2], w[82], COUPs[1], &amp[0] );
  jamp[34] += cxtype( 0, 1 ) * amp[0];
  jamp[35] -= cxtype( 0, 1 ) * amp[0];
  jamp[58] -= cxtype( 0, 1 ) * amp[0];
  jamp[59] += cxtype( 0, 1 ) * amp[0];
  jamp[104] -= cxtype( 0, 1 ) * amp[0];
  jamp[105] += cxtype( 0, 1 ) * amp[0];
  jamp[110] += cxtype( 0, 1 ) * amp[0];
  jamp[111] -= cxtype( 0, 1 ) * amp[0];

  // *** DIAGRAM 615 OF 1240 ***

  // Wavefunction(s) for diagram number 615
  // (none)

  // Amplitude(s) for diagram number 615
  VVV1_0( w[92], w[57], w[8], COUPs[0], &amp[0] );
  jamp[12] -= amp[0];
  jamp[13] += amp[0];
  jamp[15] += amp[0];
  jamp[17] -= amp[0];
  jamp[34] += amp[0];
  jamp[35] -= amp[0];
  jamp[44] -= amp[0];
  jamp[45] += amp[0];
  jamp[68] -= amp[0];
  jamp[69] += amp[0];
  jamp[72] += amp[0];
  jamp[73] -= amp[0];
  jamp[75] -= amp[0];
  jamp[77] += amp[0];
  jamp[110] += amp[0];
  jamp[111] -= amp[0];
  VVV1_0( w[92], w[81], w[8], COUPs[0], &amp[0] );
  jamp[13] += amp[0];
  jamp[14] -= amp[0];
  jamp[15] += amp[0];
  jamp[16] -= amp[0];
  jamp[44] -= amp[0];
  jamp[45] += amp[0];
  jamp[58] += amp[0];
  jamp[59] -= amp[0];
  jamp[68] -= amp[0];
  jamp[69] += amp[0];
  jamp[73] -= amp[0];
  jamp[74] += amp[0];
  jamp[75] -= amp[0];
  jamp[76] += amp[0];
  jamp[104] += amp[0];
  jamp[105] -= amp[0];
  VVV1_0( w[92], w[82], w[8], COUPs[0], &amp[0] );
  jamp[12] += amp[0];
  jamp[14] -= amp[0];
  jamp[16] -= amp[0];
  jamp[17] += amp[0];
  jamp[34] -= amp[0];
  jamp[35] += amp[0];
  jamp[58] += amp[0];
  jamp[59] -= amp[0];
  jamp[72] -= amp[0];
  jamp[74] += amp[0];
  jamp[76] += amp[0];
  jamp[77] -= amp[0];
  jamp[104] += amp[0];
  jamp[105] -= amp[0];
  jamp[110] -= amp[0];
  jamp[111] += amp[0];

  // *** DIAGRAM 616 OF 1240 ***

  // Wavefunction(s) for diagram number 616
  VVV1P0_1( w[0], w[6], COUPs[0], 0., 0., w[92] );
  FFV1_2( w[3], w[92], COUPs[1], cIPD[0], cIPD[1], w[99] );

  // Amplitude(s) for diagram number 616
  FFV1_0( w[99], w[87], w[5], COUPs[1], &amp[0] );
#ifdef MGONGPU_SUPPORTS_MULTICHANNEL
  if( channelId == 616 ) allNumerators[0] += cxabs2( amp[0] );
  if( channelId != 0 ) allDenominators[0] += cxabs2( amp[0] );
#endif
  jamp[32] += cxtype( 0, 1 ) * amp[0];
  jamp[33] -= cxtype( 0, 1 ) * amp[0];

  // *** DIAGRAM 617 OF 1240 ***

  // Wavefunction(s) for diagram number 617
  // (none)

  // Amplitude(s) for diagram number 617
  FFV1_0( w[99], w[9], w[4], COUPs[1], &amp[0] );
#ifdef MGONGPU_SUPPORTS_MULTICHANNEL
  if( channelId == 617 ) allNumerators[0] += cxabs2( amp[0] );
  if( channelId != 0 ) allDenominators[0] += cxabs2( amp[0] );
#endif
  jamp[38] += cxtype( 0, 1 ) * amp[0];
  jamp[39] -= cxtype( 0, 1 ) * amp[0];

  // *** DIAGRAM 618 OF 1240 ***

  // Wavefunction(s) for diagram number 618
  VVV1P0_1( w[92], w[4], COUPs[0], 0., 0., w[112] );

  // Amplitude(s) for diagram number 618
  VVV1_0( w[112], w[34], w[5], COUPs[0], &amp[0] );
#ifdef MGONGPU_SUPPORTS_MULTICHANNEL
  if( channelId == 618 ) allNumerators[0] += cxabs2( amp[0] );
  if( channelId != 0 ) allDenominators[0] += cxabs2( amp[0] );
#endif
  jamp[28] += cxtype( 0, 1 ) * amp[0];
  jamp[31] -= cxtype( 0, 1 ) * amp[0];
  jamp[34] += cxtype( 0, 1 ) * amp[0];
  jamp[37] -= cxtype( 0, 1 ) * amp[0];
  jamp[38] += cxtype( 0, 1 ) * amp[0];
  jamp[39] -= cxtype( 0, 1 ) * amp[0];
  jamp[40] += cxtype( 0, 1 ) * amp[0];
  jamp[42] -= cxtype( 0, 1 ) * amp[0];

  // *** DIAGRAM 619 OF 1240 ***

  // Wavefunction(s) for diagram number 619
  // (none)

  // Amplitude(s) for diagram number 619
  FFV1_0( w[3], w[9], w[112], COUPs[1], &amp[0] );
#ifdef MGONGPU_SUPPORTS_MULTICHANNEL
  if( channelId == 619 ) allNumerators[0] += cxabs2( amp[0] );
  if( channelId != 0 ) allDenominators[0] += cxabs2( amp[0] );
#endif
  jamp[37] += amp[0];
  jamp[38] -= amp[0];
  jamp[39] += amp[0];
  jamp[40] -= amp[0];

  // *** DIAGRAM 620 OF 1240 ***

  // Wavefunction(s) for diagram number 620
  VVV1P0_1( w[92], w[5], COUPs[0], 0., 0., w[86] );

  // Amplitude(s) for diagram number 620
  VVV1_0( w[86], w[34], w[4], COUPs[0], &amp[0] );
#ifdef MGONGPU_SUPPORTS_MULTICHANNEL
  if( channelId == 620 ) allNumerators[0] += cxabs2( amp[0] );
  if( channelId != 0 ) allDenominators[0] += cxabs2( amp[0] );
#endif
  jamp[29] += cxtype( 0, 1 ) * amp[0];
  jamp[31] -= cxtype( 0, 1 ) * amp[0];
  jamp[32] += cxtype( 0, 1 ) * amp[0];
  jamp[33] -= cxtype( 0, 1 ) * amp[0];
  jamp[34] += cxtype( 0, 1 ) * amp[0];
  jamp[37] -= cxtype( 0, 1 ) * amp[0];
  jamp[40] += cxtype( 0, 1 ) * amp[0];
  jamp[43] -= cxtype( 0, 1 ) * amp[0];

  // *** DIAGRAM 621 OF 1240 ***

  // Wavefunction(s) for diagram number 621
  // (none)

  // Amplitude(s) for diagram number 621
  FFV1_0( w[3], w[87], w[86], COUPs[1], &amp[0] );
#ifdef MGONGPU_SUPPORTS_MULTICHANNEL
  if( channelId == 621 ) allNumerators[0] += cxabs2( amp[0] );
  if( channelId != 0 ) allDenominators[0] += cxabs2( amp[0] );
#endif
  jamp[31] += amp[0];
  jamp[32] -= amp[0];
  jamp[33] += amp[0];
  jamp[34] -= amp[0];

  // *** DIAGRAM 622 OF 1240 ***

  // Wavefunction(s) for diagram number 622
  VVVV1P0_1( w[92], w[4], w[5], COUPs[2], 0., 0., w[107] );
  VVVV3P0_1( w[92], w[4], w[5], COUPs[2], 0., 0., w[95] );
  VVVV4P0_1( w[92], w[4], w[5], COUPs[2], 0., 0., w[105] );

  // Amplitude(s) for diagram number 622
  FFV1_0( w[3], w[77], w[107], COUPs[1], &amp[0] );
  jamp[28] -= cxtype( 0, 1 ) * amp[0];
  jamp[29] += cxtype( 0, 1 ) * amp[0];
  jamp[32] += cxtype( 0, 1 ) * amp[0];
  jamp[33] -= cxtype( 0, 1 ) * amp[0];
  jamp[38] -= cxtype( 0, 1 ) * amp[0];
  jamp[39] += cxtype( 0, 1 ) * amp[0];
  jamp[42] += cxtype( 0, 1 ) * amp[0];
  jamp[43] -= cxtype( 0, 1 ) * amp[0];
  FFV1_0( w[3], w[77], w[95], COUPs[1], &amp[0] );
  jamp[29] += cxtype( 0, 1 ) * amp[0];
  jamp[31] -= cxtype( 0, 1 ) * amp[0];
  jamp[32] += cxtype( 0, 1 ) * amp[0];
  jamp[33] -= cxtype( 0, 1 ) * amp[0];
  jamp[34] += cxtype( 0, 1 ) * amp[0];
  jamp[37] -= cxtype( 0, 1 ) * amp[0];
  jamp[40] += cxtype( 0, 1 ) * amp[0];
  jamp[43] -= cxtype( 0, 1 ) * amp[0];
  FFV1_0( w[3], w[77], w[105], COUPs[1], &amp[0] );
  jamp[28] += cxtype( 0, 1 ) * amp[0];
  jamp[31] -= cxtype( 0, 1 ) * amp[0];
  jamp[34] += cxtype( 0, 1 ) * amp[0];
  jamp[37] -= cxtype( 0, 1 ) * amp[0];
  jamp[38] += cxtype( 0, 1 ) * amp[0];
  jamp[39] -= cxtype( 0, 1 ) * amp[0];
  jamp[40] += cxtype( 0, 1 ) * amp[0];
  jamp[42] -= cxtype( 0, 1 ) * amp[0];

  // *** DIAGRAM 623 OF 1240 ***

  // Wavefunction(s) for diagram number 623
  FFV1_1( w[77], w[92], COUPs[1], cIPD[0], cIPD[1], w[102] );

  // Amplitude(s) for diagram number 623
  FFV1_0( w[46], w[102], w[5], COUPs[1], &amp[0] );
#ifdef MGONGPU_SUPPORTS_MULTICHANNEL
  if( channelId == 623 ) allNumerators[0] += cxabs2( amp[0] );
  if( channelId != 0 ) allDenominators[0] += cxabs2( amp[0] );
#endif
  jamp[29] += cxtype( 0, 1 ) * amp[0];
  jamp[43] -= cxtype( 0, 1 ) * amp[0];

  // *** DIAGRAM 624 OF 1240 ***

  // Wavefunction(s) for diagram number 624
  FFV1_2( w[46], w[92], COUPs[1], cIPD[0], cIPD[1], w[88] );

  // Amplitude(s) for diagram number 624
  FFV1_0( w[88], w[77], w[5], COUPs[1], &amp[0] );
#ifdef MGONGPU_SUPPORTS_MULTICHANNEL
  if( channelId == 624 ) allNumerators[0] += cxabs2( amp[0] );
  if( channelId != 0 ) allDenominators[0] += cxabs2( amp[0] );
#endif
  jamp[37] += cxtype( 0, 1 ) * amp[0];
  jamp[40] -= cxtype( 0, 1 ) * amp[0];

  // *** DIAGRAM 625 OF 1240 ***

  // Wavefunction(s) for diagram number 625
  // (none)

  // Amplitude(s) for diagram number 625
  FFV1_0( w[46], w[77], w[86], COUPs[1], &amp[0] );
#ifdef MGONGPU_SUPPORTS_MULTICHANNEL
  if( channelId == 625 ) allNumerators[0] += cxabs2( amp[0] );
  if( channelId != 0 ) allDenominators[0] += cxabs2( amp[0] );
#endif
  jamp[29] += amp[0];
  jamp[37] -= amp[0];
  jamp[40] += amp[0];
  jamp[43] -= amp[0];

  // *** DIAGRAM 626 OF 1240 ***

  // Wavefunction(s) for diagram number 626
  // (none)

  // Amplitude(s) for diagram number 626
  FFV1_0( w[38], w[102], w[4], COUPs[1], &amp[0] );
#ifdef MGONGPU_SUPPORTS_MULTICHANNEL
  if( channelId == 626 ) allNumerators[0] += cxabs2( amp[0] );
  if( channelId != 0 ) allDenominators[0] += cxabs2( amp[0] );
#endif
  jamp[28] += cxtype( 0, 1 ) * amp[0];
  jamp[42] -= cxtype( 0, 1 ) * amp[0];

  // *** DIAGRAM 627 OF 1240 ***

  // Wavefunction(s) for diagram number 627
  FFV1_2( w[38], w[92], COUPs[1], cIPD[0], cIPD[1], w[90] );

  // Amplitude(s) for diagram number 627
  FFV1_0( w[90], w[77], w[4], COUPs[1], &amp[0] );
#ifdef MGONGPU_SUPPORTS_MULTICHANNEL
  if( channelId == 627 ) allNumerators[0] += cxabs2( amp[0] );
  if( channelId != 0 ) allDenominators[0] += cxabs2( amp[0] );
#endif
  jamp[31] += cxtype( 0, 1 ) * amp[0];
  jamp[34] -= cxtype( 0, 1 ) * amp[0];

  // *** DIAGRAM 628 OF 1240 ***

  // Wavefunction(s) for diagram number 628
  // (none)

  // Amplitude(s) for diagram number 628
  FFV1_0( w[38], w[77], w[112], COUPs[1], &amp[0] );
#ifdef MGONGPU_SUPPORTS_MULTICHANNEL
  if( channelId == 628 ) allNumerators[0] += cxabs2( amp[0] );
  if( channelId != 0 ) allDenominators[0] += cxabs2( amp[0] );
#endif
  jamp[28] += amp[0];
  jamp[31] -= amp[0];
  jamp[34] += amp[0];
  jamp[42] -= amp[0];

  // *** DIAGRAM 629 OF 1240 ***

  // Wavefunction(s) for diagram number 629
  // (none)

  // Amplitude(s) for diagram number 629
  FFV1_0( w[3], w[102], w[24], COUPs[1], &amp[0] );
#ifdef MGONGPU_SUPPORTS_MULTICHANNEL
  if( channelId == 629 ) allNumerators[0] += cxabs2( amp[0] );
  if( channelId != 0 ) allDenominators[0] += cxabs2( amp[0] );
#endif
  jamp[28] += amp[0];
  jamp[29] -= amp[0];
  jamp[42] -= amp[0];
  jamp[43] += amp[0];

  // *** DIAGRAM 630 OF 1240 ***

  // Wavefunction(s) for diagram number 630
  // (none)

  // Amplitude(s) for diagram number 630
  FFV1_0( w[99], w[77], w[24], COUPs[1], &amp[0] );
#ifdef MGONGPU_SUPPORTS_MULTICHANNEL
  if( channelId == 630 ) allNumerators[0] += cxabs2( amp[0] );
  if( channelId != 0 ) allDenominators[0] += cxabs2( amp[0] );
#endif
  jamp[32] += amp[0];
  jamp[33] -= amp[0];
  jamp[38] -= amp[0];
  jamp[39] += amp[0];

  // *** DIAGRAM 631 OF 1240 ***

  // Wavefunction(s) for diagram number 631
  VVV1P0_1( w[92], w[24], COUPs[0], 0., 0., w[102] );

  // Amplitude(s) for diagram number 631
  FFV1_0( w[3], w[77], w[102], COUPs[1], &amp[0] );
#ifdef MGONGPU_SUPPORTS_MULTICHANNEL
  if( channelId == 631 ) allNumerators[0] += cxabs2( amp[0] );
  if( channelId != 0 ) allDenominators[0] += cxabs2( amp[0] );
#endif
  jamp[28] -= cxtype( 0, 1 ) * amp[0];
  jamp[29] += cxtype( 0, 1 ) * amp[0];
  jamp[32] += cxtype( 0, 1 ) * amp[0];
  jamp[33] -= cxtype( 0, 1 ) * amp[0];
  jamp[38] -= cxtype( 0, 1 ) * amp[0];
  jamp[39] += cxtype( 0, 1 ) * amp[0];
  jamp[42] += cxtype( 0, 1 ) * amp[0];
  jamp[43] -= cxtype( 0, 1 ) * amp[0];

  // *** DIAGRAM 632 OF 1240 ***

  // Wavefunction(s) for diagram number 632
  FFV1_1( w[2], w[92], COUPs[1], cIPD[0], cIPD[1], w[96] );

  // Amplitude(s) for diagram number 632
  FFV1_0( w[56], w[96], w[5], COUPs[1], &amp[0] );
#ifdef MGONGPU_SUPPORTS_MULTICHANNEL
  if( channelId == 632 ) allNumerators[0] += cxabs2( amp[0] );
  if( channelId != 0 ) allDenominators[0] += cxabs2( amp[0] );
#endif
  jamp[23] += cxtype( 0, 1 ) * amp[0];
  jamp[101] -= cxtype( 0, 1 ) * amp[0];

  // *** DIAGRAM 633 OF 1240 ***

  // Wavefunction(s) for diagram number 633
  // (none)

  // Amplitude(s) for diagram number 633
  FFV1_0( w[22], w[96], w[4], COUPs[1], &amp[0] );
#ifdef MGONGPU_SUPPORTS_MULTICHANNEL
  if( channelId == 633 ) allNumerators[0] += cxabs2( amp[0] );
  if( channelId != 0 ) allDenominators[0] += cxabs2( amp[0] );
#endif
  jamp[21] += cxtype( 0, 1 ) * amp[0];
  jamp[99] -= cxtype( 0, 1 ) * amp[0];

  // *** DIAGRAM 634 OF 1240 ***

  // Wavefunction(s) for diagram number 634
  // (none)

  // Amplitude(s) for diagram number 634
  VVV1_0( w[112], w[103], w[5], COUPs[0], &amp[0] );
#ifdef MGONGPU_SUPPORTS_MULTICHANNEL
  if( channelId == 634 ) allNumerators[0] += cxabs2( amp[0] );
  if( channelId != 0 ) allDenominators[0] += cxabs2( amp[0] );
#endif
  jamp[21] += cxtype( 0, 1 ) * amp[0];
  jamp[53] -= cxtype( 0, 1 ) * amp[0];
  jamp[67] += cxtype( 0, 1 ) * amp[0];
  jamp[77] -= cxtype( 0, 1 ) * amp[0];
  jamp[85] += cxtype( 0, 1 ) * amp[0];
  jamp[88] -= cxtype( 0, 1 ) * amp[0];
  jamp[91] += cxtype( 0, 1 ) * amp[0];
  jamp[99] -= cxtype( 0, 1 ) * amp[0];

  // *** DIAGRAM 635 OF 1240 ***

  // Wavefunction(s) for diagram number 635
  // (none)

  // Amplitude(s) for diagram number 635
  FFV1_0( w[22], w[2], w[112], COUPs[1], &amp[0] );
#ifdef MGONGPU_SUPPORTS_MULTICHANNEL
  if( channelId == 635 ) allNumerators[0] += cxabs2( amp[0] );
  if( channelId != 0 ) allDenominators[0] += cxabs2( amp[0] );
#endif
  jamp[21] += amp[0];
  jamp[53] -= amp[0];
  jamp[67] += amp[0];
  jamp[99] -= amp[0];

  // *** DIAGRAM 636 OF 1240 ***

  // Wavefunction(s) for diagram number 636
  // (none)

  // Amplitude(s) for diagram number 636
  VVV1_0( w[86], w[103], w[4], COUPs[0], &amp[0] );
#ifdef MGONGPU_SUPPORTS_MULTICHANNEL
  if( channelId == 636 ) allNumerators[0] += cxabs2( amp[0] );
  if( channelId != 0 ) allDenominators[0] += cxabs2( amp[0] );
#endif
  jamp[23] += cxtype( 0, 1 ) * amp[0];
  jamp[53] -= cxtype( 0, 1 ) * amp[0];
  jamp[61] += cxtype( 0, 1 ) * amp[0];
  jamp[64] -= cxtype( 0, 1 ) * amp[0];
  jamp[67] += cxtype( 0, 1 ) * amp[0];
  jamp[77] -= cxtype( 0, 1 ) * amp[0];
  jamp[91] += cxtype( 0, 1 ) * amp[0];
  jamp[101] -= cxtype( 0, 1 ) * amp[0];

  // *** DIAGRAM 637 OF 1240 ***

  // Wavefunction(s) for diagram number 637
  // (none)

  // Amplitude(s) for diagram number 637
  FFV1_0( w[56], w[2], w[86], COUPs[1], &amp[0] );
#ifdef MGONGPU_SUPPORTS_MULTICHANNEL
  if( channelId == 637 ) allNumerators[0] += cxabs2( amp[0] );
  if( channelId != 0 ) allDenominators[0] += cxabs2( amp[0] );
#endif
  jamp[23] += amp[0];
  jamp[77] -= amp[0];
  jamp[91] += amp[0];
  jamp[101] -= amp[0];

  // *** DIAGRAM 638 OF 1240 ***

  // Wavefunction(s) for diagram number 638
  // (none)

  // Amplitude(s) for diagram number 638
  FFV1_0( w[52], w[2], w[107], COUPs[1], &amp[0] );
  jamp[21] -= cxtype( 0, 1 ) * amp[0];
  jamp[23] += cxtype( 0, 1 ) * amp[0];
  jamp[61] += cxtype( 0, 1 ) * amp[0];
  jamp[64] -= cxtype( 0, 1 ) * amp[0];
  jamp[85] -= cxtype( 0, 1 ) * amp[0];
  jamp[88] += cxtype( 0, 1 ) * amp[0];
  jamp[99] += cxtype( 0, 1 ) * amp[0];
  jamp[101] -= cxtype( 0, 1 ) * amp[0];
  FFV1_0( w[52], w[2], w[95], COUPs[1], &amp[0] );
  jamp[23] += cxtype( 0, 1 ) * amp[0];
  jamp[53] -= cxtype( 0, 1 ) * amp[0];
  jamp[61] += cxtype( 0, 1 ) * amp[0];
  jamp[64] -= cxtype( 0, 1 ) * amp[0];
  jamp[67] += cxtype( 0, 1 ) * amp[0];
  jamp[77] -= cxtype( 0, 1 ) * amp[0];
  jamp[91] += cxtype( 0, 1 ) * amp[0];
  jamp[101] -= cxtype( 0, 1 ) * amp[0];
  FFV1_0( w[52], w[2], w[105], COUPs[1], &amp[0] );
  jamp[21] += cxtype( 0, 1 ) * amp[0];
  jamp[53] -= cxtype( 0, 1 ) * amp[0];
  jamp[67] += cxtype( 0, 1 ) * amp[0];
  jamp[77] -= cxtype( 0, 1 ) * amp[0];
  jamp[85] += cxtype( 0, 1 ) * amp[0];
  jamp[88] -= cxtype( 0, 1 ) * amp[0];
  jamp[91] += cxtype( 0, 1 ) * amp[0];
  jamp[99] -= cxtype( 0, 1 ) * amp[0];

  // *** DIAGRAM 639 OF 1240 ***

  // Wavefunction(s) for diagram number 639
  FFV1_2( w[52], w[92], COUPs[1], cIPD[0], cIPD[1], w[104] );

  // Amplitude(s) for diagram number 639
  FFV1_0( w[104], w[33], w[5], COUPs[1], &amp[0] );
#ifdef MGONGPU_SUPPORTS_MULTICHANNEL
  if( channelId == 639 ) allNumerators[0] += cxabs2( amp[0] );
  if( channelId != 0 ) allDenominators[0] += cxabs2( amp[0] );
#endif
  jamp[61] += cxtype( 0, 1 ) * amp[0];
  jamp[64] -= cxtype( 0, 1 ) * amp[0];

  // *** DIAGRAM 640 OF 1240 ***

  // Wavefunction(s) for diagram number 640
  FFV1_1( w[33], w[92], COUPs[1], cIPD[0], cIPD[1], w[114] );

  // Amplitude(s) for diagram number 640
  FFV1_0( w[52], w[114], w[5], COUPs[1], &amp[0] );
#ifdef MGONGPU_SUPPORTS_MULTICHANNEL
  if( channelId == 640 ) allNumerators[0] += cxabs2( amp[0] );
  if( channelId != 0 ) allDenominators[0] += cxabs2( amp[0] );
#endif
  jamp[53] += cxtype( 0, 1 ) * amp[0];
  jamp[67] -= cxtype( 0, 1 ) * amp[0];

  // *** DIAGRAM 641 OF 1240 ***

  // Wavefunction(s) for diagram number 641
  // (none)

  // Amplitude(s) for diagram number 641
  FFV1_0( w[52], w[33], w[86], COUPs[1], &amp[0] );
#ifdef MGONGPU_SUPPORTS_MULTICHANNEL
  if( channelId == 641 ) allNumerators[0] += cxabs2( amp[0] );
  if( channelId != 0 ) allDenominators[0] += cxabs2( amp[0] );
#endif
  jamp[53] += amp[0];
  jamp[61] -= amp[0];
  jamp[64] += amp[0];
  jamp[67] -= amp[0];

  // *** DIAGRAM 642 OF 1240 ***

  // Wavefunction(s) for diagram number 642
  // (none)

  // Amplitude(s) for diagram number 642
  FFV1_0( w[104], w[39], w[4], COUPs[1], &amp[0] );
#ifdef MGONGPU_SUPPORTS_MULTICHANNEL
  if( channelId == 642 ) allNumerators[0] += cxabs2( amp[0] );
  if( channelId != 0 ) allDenominators[0] += cxabs2( amp[0] );
#endif
  jamp[85] += cxtype( 0, 1 ) * amp[0];
  jamp[88] -= cxtype( 0, 1 ) * amp[0];

  // *** DIAGRAM 643 OF 1240 ***

  // Wavefunction(s) for diagram number 643
  FFV1_1( w[39], w[92], COUPs[1], cIPD[0], cIPD[1], w[106] );

  // Amplitude(s) for diagram number 643
  FFV1_0( w[52], w[106], w[4], COUPs[1], &amp[0] );
#ifdef MGONGPU_SUPPORTS_MULTICHANNEL
  if( channelId == 643 ) allNumerators[0] += cxabs2( amp[0] );
  if( channelId != 0 ) allDenominators[0] += cxabs2( amp[0] );
#endif
  jamp[77] += cxtype( 0, 1 ) * amp[0];
  jamp[91] -= cxtype( 0, 1 ) * amp[0];

  // *** DIAGRAM 644 OF 1240 ***

  // Wavefunction(s) for diagram number 644
  // (none)

  // Amplitude(s) for diagram number 644
  FFV1_0( w[52], w[39], w[112], COUPs[1], &amp[0] );
#ifdef MGONGPU_SUPPORTS_MULTICHANNEL
  if( channelId == 644 ) allNumerators[0] += cxabs2( amp[0] );
  if( channelId != 0 ) allDenominators[0] += cxabs2( amp[0] );
#endif
  jamp[77] += amp[0];
  jamp[85] -= amp[0];
  jamp[88] += amp[0];
  jamp[91] -= amp[0];

  // *** DIAGRAM 645 OF 1240 ***

  // Wavefunction(s) for diagram number 645
  // (none)

  // Amplitude(s) for diagram number 645
  FFV1_0( w[104], w[2], w[24], COUPs[1], &amp[0] );
#ifdef MGONGPU_SUPPORTS_MULTICHANNEL
  if( channelId == 645 ) allNumerators[0] += cxabs2( amp[0] );
  if( channelId != 0 ) allDenominators[0] += cxabs2( amp[0] );
#endif
  jamp[61] += amp[0];
  jamp[64] -= amp[0];
  jamp[85] -= amp[0];
  jamp[88] += amp[0];

  // *** DIAGRAM 646 OF 1240 ***

  // Wavefunction(s) for diagram number 646
  // (none)

  // Amplitude(s) for diagram number 646
  FFV1_0( w[52], w[96], w[24], COUPs[1], &amp[0] );
#ifdef MGONGPU_SUPPORTS_MULTICHANNEL
  if( channelId == 646 ) allNumerators[0] += cxabs2( amp[0] );
  if( channelId != 0 ) allDenominators[0] += cxabs2( amp[0] );
#endif
  jamp[21] += amp[0];
  jamp[23] -= amp[0];
  jamp[99] -= amp[0];
  jamp[101] += amp[0];

  // *** DIAGRAM 647 OF 1240 ***

  // Wavefunction(s) for diagram number 647
  // (none)

  // Amplitude(s) for diagram number 647
  FFV1_0( w[52], w[2], w[102], COUPs[1], &amp[0] );
#ifdef MGONGPU_SUPPORTS_MULTICHANNEL
  if( channelId == 647 ) allNumerators[0] += cxabs2( amp[0] );
  if( channelId != 0 ) allDenominators[0] += cxabs2( amp[0] );
#endif
  jamp[21] -= cxtype( 0, 1 ) * amp[0];
  jamp[23] += cxtype( 0, 1 ) * amp[0];
  jamp[61] += cxtype( 0, 1 ) * amp[0];
  jamp[64] -= cxtype( 0, 1 ) * amp[0];
  jamp[85] -= cxtype( 0, 1 ) * amp[0];
  jamp[88] += cxtype( 0, 1 ) * amp[0];
  jamp[99] += cxtype( 0, 1 ) * amp[0];
  jamp[101] -= cxtype( 0, 1 ) * amp[0];

  // *** DIAGRAM 648 OF 1240 ***

  // Wavefunction(s) for diagram number 648
  // (none)

  // Amplitude(s) for diagram number 648
  FFV1_0( w[65], w[96], w[5], COUPs[1], &amp[0] );
#ifdef MGONGPU_SUPPORTS_MULTICHANNEL
  if( channelId == 648 ) allNumerators[0] += cxabs2( amp[0] );
  if( channelId != 0 ) allDenominators[0] += cxabs2( amp[0] );
#endif
  jamp[22] += amp[0];
  jamp[23] -= amp[0];
  jamp[100] -= amp[0];
  jamp[101] += amp[0];

  // *** DIAGRAM 649 OF 1240 ***

  // Wavefunction(s) for diagram number 649
  // (none)

  // Amplitude(s) for diagram number 649
  FFV1_0( w[3], w[96], w[63], COUPs[1], &amp[0] );
#ifdef MGONGPU_SUPPORTS_MULTICHANNEL
  if( channelId == 649 ) allNumerators[0] += cxabs2( amp[0] );
  if( channelId != 0 ) allDenominators[0] += cxabs2( amp[0] );
#endif
  jamp[18] -= cxtype( 0, 1 ) * amp[0];
  jamp[20] += cxtype( 0, 1 ) * amp[0];
  jamp[22] += cxtype( 0, 1 ) * amp[0];
  jamp[23] -= cxtype( 0, 1 ) * amp[0];
  jamp[96] += cxtype( 0, 1 ) * amp[0];
  jamp[98] -= cxtype( 0, 1 ) * amp[0];
  jamp[100] -= cxtype( 0, 1 ) * amp[0];
  jamp[101] += cxtype( 0, 1 ) * amp[0];

  // *** DIAGRAM 650 OF 1240 ***

  // Wavefunction(s) for diagram number 650
  // (none)

  // Amplitude(s) for diagram number 650
  FFV1_0( w[99], w[93], w[5], COUPs[1], &amp[0] );
#ifdef MGONGPU_SUPPORTS_MULTICHANNEL
  if( channelId == 650 ) allNumerators[0] += cxabs2( amp[0] );
  if( channelId != 0 ) allDenominators[0] += cxabs2( amp[0] );
#endif
  jamp[32] += amp[0];
  jamp[33] -= amp[0];
  jamp[56] -= amp[0];
  jamp[57] += amp[0];

  // *** DIAGRAM 651 OF 1240 ***

  // Wavefunction(s) for diagram number 651
  // (none)

  // Amplitude(s) for diagram number 651
  FFV1_0( w[99], w[2], w[63], COUPs[1], &amp[0] );
#ifdef MGONGPU_SUPPORTS_MULTICHANNEL
  if( channelId == 651 ) allNumerators[0] += cxabs2( amp[0] );
  if( channelId != 0 ) allDenominators[0] += cxabs2( amp[0] );
#endif
  jamp[32] -= cxtype( 0, 1 ) * amp[0];
  jamp[33] += cxtype( 0, 1 ) * amp[0];
  jamp[56] += cxtype( 0, 1 ) * amp[0];
  jamp[57] -= cxtype( 0, 1 ) * amp[0];
  jamp[80] += cxtype( 0, 1 ) * amp[0];
  jamp[81] -= cxtype( 0, 1 ) * amp[0];
  jamp[86] -= cxtype( 0, 1 ) * amp[0];
  jamp[87] += cxtype( 0, 1 ) * amp[0];

  // *** DIAGRAM 652 OF 1240 ***

  // Wavefunction(s) for diagram number 652
  // (none)

  // Amplitude(s) for diagram number 652
  FFV1_0( w[3], w[93], w[86], COUPs[1], &amp[0] );
#ifdef MGONGPU_SUPPORTS_MULTICHANNEL
  if( channelId == 652 ) allNumerators[0] += cxabs2( amp[0] );
  if( channelId != 0 ) allDenominators[0] += cxabs2( amp[0] );
#endif
  jamp[31] -= cxtype( 0, 1 ) * amp[0];
  jamp[32] += cxtype( 0, 1 ) * amp[0];
  jamp[33] -= cxtype( 0, 1 ) * amp[0];
  jamp[34] += cxtype( 0, 1 ) * amp[0];
  jamp[55] += cxtype( 0, 1 ) * amp[0];
  jamp[56] -= cxtype( 0, 1 ) * amp[0];
  jamp[57] += cxtype( 0, 1 ) * amp[0];
  jamp[58] -= cxtype( 0, 1 ) * amp[0];

  // *** DIAGRAM 653 OF 1240 ***

  // Wavefunction(s) for diagram number 653
  // (none)

  // Amplitude(s) for diagram number 653
  FFV1_0( w[65], w[2], w[86], COUPs[1], &amp[0] );
#ifdef MGONGPU_SUPPORTS_MULTICHANNEL
  if( channelId == 653 ) allNumerators[0] += cxabs2( amp[0] );
  if( channelId != 0 ) allDenominators[0] += cxabs2( amp[0] );
#endif
  jamp[22] -= cxtype( 0, 1 ) * amp[0];
  jamp[23] += cxtype( 0, 1 ) * amp[0];
  jamp[76] += cxtype( 0, 1 ) * amp[0];
  jamp[77] -= cxtype( 0, 1 ) * amp[0];
  jamp[90] -= cxtype( 0, 1 ) * amp[0];
  jamp[91] += cxtype( 0, 1 ) * amp[0];
  jamp[100] += cxtype( 0, 1 ) * amp[0];
  jamp[101] -= cxtype( 0, 1 ) * amp[0];

  // *** DIAGRAM 654 OF 1240 ***

  // Wavefunction(s) for diagram number 654
  // (none)

  // Amplitude(s) for diagram number 654
  VVVV1_0( w[92], w[61], w[8], w[5], COUPs[2], &amp[0] );
  jamp[18] += amp[0];
  jamp[20] -= amp[0];
  jamp[31] -= amp[0];
  jamp[34] += amp[0];
  jamp[55] += amp[0];
  jamp[58] -= amp[0];
  jamp[76] -= amp[0];
  jamp[77] += amp[0];
  jamp[80] += amp[0];
  jamp[81] -= amp[0];
  jamp[86] -= amp[0];
  jamp[87] += amp[0];
  jamp[90] += amp[0];
  jamp[91] -= amp[0];
  jamp[96] -= amp[0];
  jamp[98] += amp[0];
  VVVV3_0( w[92], w[61], w[8], w[5], COUPs[2], &amp[0] );
  jamp[18] += amp[0];
  jamp[20] -= amp[0];
  jamp[22] -= amp[0];
  jamp[23] += amp[0];
  jamp[32] -= amp[0];
  jamp[33] += amp[0];
  jamp[56] += amp[0];
  jamp[57] -= amp[0];
  jamp[80] += amp[0];
  jamp[81] -= amp[0];
  jamp[86] -= amp[0];
  jamp[87] += amp[0];
  jamp[96] -= amp[0];
  jamp[98] += amp[0];
  jamp[100] += amp[0];
  jamp[101] -= amp[0];
  VVVV4_0( w[92], w[61], w[8], w[5], COUPs[2], &amp[0] );
  jamp[22] -= amp[0];
  jamp[23] += amp[0];
  jamp[31] += amp[0];
  jamp[32] -= amp[0];
  jamp[33] += amp[0];
  jamp[34] -= amp[0];
  jamp[55] -= amp[0];
  jamp[56] += amp[0];
  jamp[57] -= amp[0];
  jamp[58] += amp[0];
  jamp[76] += amp[0];
  jamp[77] -= amp[0];
  jamp[90] -= amp[0];
  jamp[91] += amp[0];
  jamp[100] += amp[0];
  jamp[101] -= amp[0];

  // *** DIAGRAM 655 OF 1240 ***

  // Wavefunction(s) for diagram number 655
  VVV1P0_1( w[92], w[61], COUPs[0], 0., 0., w[104] );

  // Amplitude(s) for diagram number 655
  VVV1_0( w[8], w[5], w[104], COUPs[0], &amp[0] );
#ifdef MGONGPU_SUPPORTS_MULTICHANNEL
  if( channelId == 655 ) allNumerators[0] += cxabs2( amp[0] );
  if( channelId != 0 ) allDenominators[0] += cxabs2( amp[0] );
#endif
  jamp[18] += amp[0];
  jamp[20] -= amp[0];
  jamp[31] -= amp[0];
  jamp[34] += amp[0];
  jamp[55] += amp[0];
  jamp[58] -= amp[0];
  jamp[76] -= amp[0];
  jamp[77] += amp[0];
  jamp[80] += amp[0];
  jamp[81] -= amp[0];
  jamp[86] -= amp[0];
  jamp[87] += amp[0];
  jamp[90] += amp[0];
  jamp[91] -= amp[0];
  jamp[96] -= amp[0];
  jamp[98] += amp[0];

  // *** DIAGRAM 656 OF 1240 ***

  // Wavefunction(s) for diagram number 656
  VVV1P0_1( w[92], w[8], COUPs[0], 0., 0., w[113] );

  // Amplitude(s) for diagram number 656
  VVV1_0( w[61], w[5], w[113], COUPs[0], &amp[0] );
#ifdef MGONGPU_SUPPORTS_MULTICHANNEL
  if( channelId == 656 ) allNumerators[0] += cxabs2( amp[0] );
  if( channelId != 0 ) allDenominators[0] += cxabs2( amp[0] );
#endif
  jamp[18] += amp[0];
  jamp[20] -= amp[0];
  jamp[22] -= amp[0];
  jamp[23] += amp[0];
  jamp[32] -= amp[0];
  jamp[33] += amp[0];
  jamp[56] += amp[0];
  jamp[57] -= amp[0];
  jamp[80] += amp[0];
  jamp[81] -= amp[0];
  jamp[86] -= amp[0];
  jamp[87] += amp[0];
  jamp[96] -= amp[0];
  jamp[98] += amp[0];
  jamp[100] += amp[0];
  jamp[101] -= amp[0];

  // *** DIAGRAM 657 OF 1240 ***

  // Wavefunction(s) for diagram number 657
  // (none)

  // Amplitude(s) for diagram number 657
  VVV1_0( w[61], w[8], w[86], COUPs[0], &amp[0] );
#ifdef MGONGPU_SUPPORTS_MULTICHANNEL
  if( channelId == 657 ) allNumerators[0] += cxabs2( amp[0] );
  if( channelId != 0 ) allDenominators[0] += cxabs2( amp[0] );
#endif
  jamp[22] -= amp[0];
  jamp[23] += amp[0];
  jamp[31] += amp[0];
  jamp[32] -= amp[0];
  jamp[33] += amp[0];
  jamp[34] -= amp[0];
  jamp[55] -= amp[0];
  jamp[56] += amp[0];
  jamp[57] -= amp[0];
  jamp[58] += amp[0];
  jamp[76] += amp[0];
  jamp[77] -= amp[0];
  jamp[90] -= amp[0];
  jamp[91] += amp[0];
  jamp[100] += amp[0];
  jamp[101] -= amp[0];

  // *** DIAGRAM 658 OF 1240 ***

  // Wavefunction(s) for diagram number 658
  // (none)

  // Amplitude(s) for diagram number 658
  FFV1_0( w[3], w[39], w[104], COUPs[1], &amp[0] );
#ifdef MGONGPU_SUPPORTS_MULTICHANNEL
  if( channelId == 658 ) allNumerators[0] += cxabs2( amp[0] );
  if( channelId != 0 ) allDenominators[0] += cxabs2( amp[0] );
#endif
  jamp[76] -= cxtype( 0, 1 ) * amp[0];
  jamp[77] += cxtype( 0, 1 ) * amp[0];
  jamp[80] += cxtype( 0, 1 ) * amp[0];
  jamp[81] -= cxtype( 0, 1 ) * amp[0];
  jamp[86] -= cxtype( 0, 1 ) * amp[0];
  jamp[87] += cxtype( 0, 1 ) * amp[0];
  jamp[90] += cxtype( 0, 1 ) * amp[0];
  jamp[91] -= cxtype( 0, 1 ) * amp[0];

  // *** DIAGRAM 659 OF 1240 ***

  // Wavefunction(s) for diagram number 659
  // (none)

  // Amplitude(s) for diagram number 659
  FFV1_0( w[3], w[106], w[61], COUPs[1], &amp[0] );
#ifdef MGONGPU_SUPPORTS_MULTICHANNEL
  if( channelId == 659 ) allNumerators[0] += cxabs2( amp[0] );
  if( channelId != 0 ) allDenominators[0] += cxabs2( amp[0] );
#endif
  jamp[76] += amp[0];
  jamp[77] -= amp[0];
  jamp[90] -= amp[0];
  jamp[91] += amp[0];

  // *** DIAGRAM 660 OF 1240 ***

  // Wavefunction(s) for diagram number 660
  // (none)

  // Amplitude(s) for diagram number 660
  FFV1_0( w[99], w[39], w[61], COUPs[1], &amp[0] );
#ifdef MGONGPU_SUPPORTS_MULTICHANNEL
  if( channelId == 660 ) allNumerators[0] += cxabs2( amp[0] );
  if( channelId != 0 ) allDenominators[0] += cxabs2( amp[0] );
#endif
  jamp[80] += amp[0];
  jamp[81] -= amp[0];
  jamp[86] -= amp[0];
  jamp[87] += amp[0];

  // *** DIAGRAM 661 OF 1240 ***

  // Wavefunction(s) for diagram number 661
  // (none)

  // Amplitude(s) for diagram number 661
  FFV1_0( w[38], w[2], w[104], COUPs[1], &amp[0] );
#ifdef MGONGPU_SUPPORTS_MULTICHANNEL
  if( channelId == 661 ) allNumerators[0] += cxabs2( amp[0] );
  if( channelId != 0 ) allDenominators[0] += cxabs2( amp[0] );
#endif
  jamp[18] -= cxtype( 0, 1 ) * amp[0];
  jamp[20] += cxtype( 0, 1 ) * amp[0];
  jamp[31] += cxtype( 0, 1 ) * amp[0];
  jamp[34] -= cxtype( 0, 1 ) * amp[0];
  jamp[55] -= cxtype( 0, 1 ) * amp[0];
  jamp[58] += cxtype( 0, 1 ) * amp[0];
  jamp[96] += cxtype( 0, 1 ) * amp[0];
  jamp[98] -= cxtype( 0, 1 ) * amp[0];

  // *** DIAGRAM 662 OF 1240 ***

  // Wavefunction(s) for diagram number 662
  // (none)

  // Amplitude(s) for diagram number 662
  FFV1_0( w[38], w[96], w[61], COUPs[1], &amp[0] );
#ifdef MGONGPU_SUPPORTS_MULTICHANNEL
  if( channelId == 662 ) allNumerators[0] += cxabs2( amp[0] );
  if( channelId != 0 ) allDenominators[0] += cxabs2( amp[0] );
#endif
  jamp[18] += amp[0];
  jamp[20] -= amp[0];
  jamp[96] -= amp[0];
  jamp[98] += amp[0];

  // *** DIAGRAM 663 OF 1240 ***

  // Wavefunction(s) for diagram number 663
  // (none)

  // Amplitude(s) for diagram number 663
  FFV1_0( w[90], w[2], w[61], COUPs[1], &amp[0] );
#ifdef MGONGPU_SUPPORTS_MULTICHANNEL
  if( channelId == 663 ) allNumerators[0] += cxabs2( amp[0] );
  if( channelId != 0 ) allDenominators[0] += cxabs2( amp[0] );
#endif
  jamp[31] += amp[0];
  jamp[34] -= amp[0];
  jamp[55] -= amp[0];
  jamp[58] += amp[0];

  // *** DIAGRAM 664 OF 1240 ***

  // Wavefunction(s) for diagram number 664
  // (none)

  // Amplitude(s) for diagram number 664
  FFV1_0( w[71], w[96], w[4], COUPs[1], &amp[0] );
#ifdef MGONGPU_SUPPORTS_MULTICHANNEL
  if( channelId == 664 ) allNumerators[0] += cxabs2( amp[0] );
  if( channelId != 0 ) allDenominators[0] += cxabs2( amp[0] );
#endif
  jamp[20] += amp[0];
  jamp[21] -= amp[0];
  jamp[98] -= amp[0];
  jamp[99] += amp[0];

  // *** DIAGRAM 665 OF 1240 ***

  // Wavefunction(s) for diagram number 665
  // (none)

  // Amplitude(s) for diagram number 665
  FFV1_0( w[3], w[96], w[69], COUPs[1], &amp[0] );
#ifdef MGONGPU_SUPPORTS_MULTICHANNEL
  if( channelId == 665 ) allNumerators[0] += cxabs2( amp[0] );
  if( channelId != 0 ) allDenominators[0] += cxabs2( amp[0] );
#endif
  jamp[19] -= cxtype( 0, 1 ) * amp[0];
  jamp[20] += cxtype( 0, 1 ) * amp[0];
  jamp[21] -= cxtype( 0, 1 ) * amp[0];
  jamp[22] += cxtype( 0, 1 ) * amp[0];
  jamp[97] += cxtype( 0, 1 ) * amp[0];
  jamp[98] -= cxtype( 0, 1 ) * amp[0];
  jamp[99] += cxtype( 0, 1 ) * amp[0];
  jamp[100] -= cxtype( 0, 1 ) * amp[0];

  // *** DIAGRAM 666 OF 1240 ***

  // Wavefunction(s) for diagram number 666
  // (none)

  // Amplitude(s) for diagram number 666
  FFV1_0( w[99], w[94], w[4], COUPs[1], &amp[0] );
#ifdef MGONGPU_SUPPORTS_MULTICHANNEL
  if( channelId == 666 ) allNumerators[0] += cxabs2( amp[0] );
  if( channelId != 0 ) allDenominators[0] += cxabs2( amp[0] );
#endif
  jamp[38] += amp[0];
  jamp[39] -= amp[0];
  jamp[80] -= amp[0];
  jamp[81] += amp[0];

  // *** DIAGRAM 667 OF 1240 ***

  // Wavefunction(s) for diagram number 667
  // (none)

  // Amplitude(s) for diagram number 667
  FFV1_0( w[99], w[2], w[69], COUPs[1], &amp[0] );
#ifdef MGONGPU_SUPPORTS_MULTICHANNEL
  if( channelId == 667 ) allNumerators[0] += cxabs2( amp[0] );
  if( channelId != 0 ) allDenominators[0] += cxabs2( amp[0] );
#endif
  jamp[38] -= cxtype( 0, 1 ) * amp[0];
  jamp[39] += cxtype( 0, 1 ) * amp[0];
  jamp[56] += cxtype( 0, 1 ) * amp[0];
  jamp[57] -= cxtype( 0, 1 ) * amp[0];
  jamp[62] -= cxtype( 0, 1 ) * amp[0];
  jamp[63] += cxtype( 0, 1 ) * amp[0];
  jamp[80] += cxtype( 0, 1 ) * amp[0];
  jamp[81] -= cxtype( 0, 1 ) * amp[0];

  // *** DIAGRAM 668 OF 1240 ***

  // Wavefunction(s) for diagram number 668
  // (none)

  // Amplitude(s) for diagram number 668
  FFV1_0( w[3], w[94], w[112], COUPs[1], &amp[0] );
#ifdef MGONGPU_SUPPORTS_MULTICHANNEL
  if( channelId == 668 ) allNumerators[0] += cxabs2( amp[0] );
  if( channelId != 0 ) allDenominators[0] += cxabs2( amp[0] );
#endif
  jamp[37] -= cxtype( 0, 1 ) * amp[0];
  jamp[38] += cxtype( 0, 1 ) * amp[0];
  jamp[39] -= cxtype( 0, 1 ) * amp[0];
  jamp[40] += cxtype( 0, 1 ) * amp[0];
  jamp[79] += cxtype( 0, 1 ) * amp[0];
  jamp[80] -= cxtype( 0, 1 ) * amp[0];
  jamp[81] += cxtype( 0, 1 ) * amp[0];
  jamp[82] -= cxtype( 0, 1 ) * amp[0];

  // *** DIAGRAM 669 OF 1240 ***

  // Wavefunction(s) for diagram number 669
  // (none)

  // Amplitude(s) for diagram number 669
  FFV1_0( w[71], w[2], w[112], COUPs[1], &amp[0] );
#ifdef MGONGPU_SUPPORTS_MULTICHANNEL
  if( channelId == 669 ) allNumerators[0] += cxabs2( amp[0] );
  if( channelId != 0 ) allDenominators[0] += cxabs2( amp[0] );
#endif
  jamp[20] -= cxtype( 0, 1 ) * amp[0];
  jamp[21] += cxtype( 0, 1 ) * amp[0];
  jamp[52] += cxtype( 0, 1 ) * amp[0];
  jamp[53] -= cxtype( 0, 1 ) * amp[0];
  jamp[66] -= cxtype( 0, 1 ) * amp[0];
  jamp[67] += cxtype( 0, 1 ) * amp[0];
  jamp[98] += cxtype( 0, 1 ) * amp[0];
  jamp[99] -= cxtype( 0, 1 ) * amp[0];

  // *** DIAGRAM 670 OF 1240 ***

  // Wavefunction(s) for diagram number 670
  // (none)

  // Amplitude(s) for diagram number 670
  VVVV1_0( w[92], w[66], w[8], w[4], COUPs[2], &amp[0] );
  jamp[19] += amp[0];
  jamp[22] -= amp[0];
  jamp[37] -= amp[0];
  jamp[40] += amp[0];
  jamp[52] -= amp[0];
  jamp[53] += amp[0];
  jamp[56] += amp[0];
  jamp[57] -= amp[0];
  jamp[62] -= amp[0];
  jamp[63] += amp[0];
  jamp[66] += amp[0];
  jamp[67] -= amp[0];
  jamp[79] += amp[0];
  jamp[82] -= amp[0];
  jamp[97] -= amp[0];
  jamp[100] += amp[0];
  VVVV3_0( w[92], w[66], w[8], w[4], COUPs[2], &amp[0] );
  jamp[19] += amp[0];
  jamp[20] -= amp[0];
  jamp[21] += amp[0];
  jamp[22] -= amp[0];
  jamp[38] -= amp[0];
  jamp[39] += amp[0];
  jamp[56] += amp[0];
  jamp[57] -= amp[0];
  jamp[62] -= amp[0];
  jamp[63] += amp[0];
  jamp[80] += amp[0];
  jamp[81] -= amp[0];
  jamp[97] -= amp[0];
  jamp[98] += amp[0];
  jamp[99] -= amp[0];
  jamp[100] += amp[0];
  VVVV4_0( w[92], w[66], w[8], w[4], COUPs[2], &amp[0] );
  jamp[20] -= amp[0];
  jamp[21] += amp[0];
  jamp[37] += amp[0];
  jamp[38] -= amp[0];
  jamp[39] += amp[0];
  jamp[40] -= amp[0];
  jamp[52] += amp[0];
  jamp[53] -= amp[0];
  jamp[66] -= amp[0];
  jamp[67] += amp[0];
  jamp[79] -= amp[0];
  jamp[80] += amp[0];
  jamp[81] -= amp[0];
  jamp[82] += amp[0];
  jamp[98] += amp[0];
  jamp[99] -= amp[0];

  // *** DIAGRAM 671 OF 1240 ***

  // Wavefunction(s) for diagram number 671
  VVV1P0_1( w[92], w[66], COUPs[0], 0., 0., w[104] );

  // Amplitude(s) for diagram number 671
  VVV1_0( w[8], w[4], w[104], COUPs[0], &amp[0] );
#ifdef MGONGPU_SUPPORTS_MULTICHANNEL
  if( channelId == 671 ) allNumerators[0] += cxabs2( amp[0] );
  if( channelId != 0 ) allDenominators[0] += cxabs2( amp[0] );
#endif
  jamp[19] += amp[0];
  jamp[22] -= amp[0];
  jamp[37] -= amp[0];
  jamp[40] += amp[0];
  jamp[52] -= amp[0];
  jamp[53] += amp[0];
  jamp[56] += amp[0];
  jamp[57] -= amp[0];
  jamp[62] -= amp[0];
  jamp[63] += amp[0];
  jamp[66] += amp[0];
  jamp[67] -= amp[0];
  jamp[79] += amp[0];
  jamp[82] -= amp[0];
  jamp[97] -= amp[0];
  jamp[100] += amp[0];

  // *** DIAGRAM 672 OF 1240 ***

  // Wavefunction(s) for diagram number 672
  // (none)

  // Amplitude(s) for diagram number 672
  VVV1_0( w[66], w[4], w[113], COUPs[0], &amp[0] );
#ifdef MGONGPU_SUPPORTS_MULTICHANNEL
  if( channelId == 672 ) allNumerators[0] += cxabs2( amp[0] );
  if( channelId != 0 ) allDenominators[0] += cxabs2( amp[0] );
#endif
  jamp[19] += amp[0];
  jamp[20] -= amp[0];
  jamp[21] += amp[0];
  jamp[22] -= amp[0];
  jamp[38] -= amp[0];
  jamp[39] += amp[0];
  jamp[56] += amp[0];
  jamp[57] -= amp[0];
  jamp[62] -= amp[0];
  jamp[63] += amp[0];
  jamp[80] += amp[0];
  jamp[81] -= amp[0];
  jamp[97] -= amp[0];
  jamp[98] += amp[0];
  jamp[99] -= amp[0];
  jamp[100] += amp[0];

  // *** DIAGRAM 673 OF 1240 ***

  // Wavefunction(s) for diagram number 673
  // (none)

  // Amplitude(s) for diagram number 673
  VVV1_0( w[66], w[8], w[112], COUPs[0], &amp[0] );
#ifdef MGONGPU_SUPPORTS_MULTICHANNEL
  if( channelId == 673 ) allNumerators[0] += cxabs2( amp[0] );
  if( channelId != 0 ) allDenominators[0] += cxabs2( amp[0] );
#endif
  jamp[20] -= amp[0];
  jamp[21] += amp[0];
  jamp[37] += amp[0];
  jamp[38] -= amp[0];
  jamp[39] += amp[0];
  jamp[40] -= amp[0];
  jamp[52] += amp[0];
  jamp[53] -= amp[0];
  jamp[66] -= amp[0];
  jamp[67] += amp[0];
  jamp[79] -= amp[0];
  jamp[80] += amp[0];
  jamp[81] -= amp[0];
  jamp[82] += amp[0];
  jamp[98] += amp[0];
  jamp[99] -= amp[0];

  // *** DIAGRAM 674 OF 1240 ***

  // Wavefunction(s) for diagram number 674
  // (none)

  // Amplitude(s) for diagram number 674
  FFV1_0( w[3], w[33], w[104], COUPs[1], &amp[0] );
#ifdef MGONGPU_SUPPORTS_MULTICHANNEL
  if( channelId == 674 ) allNumerators[0] += cxabs2( amp[0] );
  if( channelId != 0 ) allDenominators[0] += cxabs2( amp[0] );
#endif
  jamp[52] -= cxtype( 0, 1 ) * amp[0];
  jamp[53] += cxtype( 0, 1 ) * amp[0];
  jamp[56] += cxtype( 0, 1 ) * amp[0];
  jamp[57] -= cxtype( 0, 1 ) * amp[0];
  jamp[62] -= cxtype( 0, 1 ) * amp[0];
  jamp[63] += cxtype( 0, 1 ) * amp[0];
  jamp[66] += cxtype( 0, 1 ) * amp[0];
  jamp[67] -= cxtype( 0, 1 ) * amp[0];

  // *** DIAGRAM 675 OF 1240 ***

  // Wavefunction(s) for diagram number 675
  // (none)

  // Amplitude(s) for diagram number 675
  FFV1_0( w[3], w[114], w[66], COUPs[1], &amp[0] );
#ifdef MGONGPU_SUPPORTS_MULTICHANNEL
  if( channelId == 675 ) allNumerators[0] += cxabs2( amp[0] );
  if( channelId != 0 ) allDenominators[0] += cxabs2( amp[0] );
#endif
  jamp[52] += amp[0];
  jamp[53] -= amp[0];
  jamp[66] -= amp[0];
  jamp[67] += amp[0];

  // *** DIAGRAM 676 OF 1240 ***

  // Wavefunction(s) for diagram number 676
  // (none)

  // Amplitude(s) for diagram number 676
  FFV1_0( w[99], w[33], w[66], COUPs[1], &amp[0] );
#ifdef MGONGPU_SUPPORTS_MULTICHANNEL
  if( channelId == 676 ) allNumerators[0] += cxabs2( amp[0] );
  if( channelId != 0 ) allDenominators[0] += cxabs2( amp[0] );
#endif
  jamp[56] += amp[0];
  jamp[57] -= amp[0];
  jamp[62] -= amp[0];
  jamp[63] += amp[0];

  // *** DIAGRAM 677 OF 1240 ***

  // Wavefunction(s) for diagram number 677
  // (none)

  // Amplitude(s) for diagram number 677
  FFV1_0( w[46], w[2], w[104], COUPs[1], &amp[0] );
#ifdef MGONGPU_SUPPORTS_MULTICHANNEL
  if( channelId == 677 ) allNumerators[0] += cxabs2( amp[0] );
  if( channelId != 0 ) allDenominators[0] += cxabs2( amp[0] );
#endif
  jamp[19] -= cxtype( 0, 1 ) * amp[0];
  jamp[22] += cxtype( 0, 1 ) * amp[0];
  jamp[37] += cxtype( 0, 1 ) * amp[0];
  jamp[40] -= cxtype( 0, 1 ) * amp[0];
  jamp[79] -= cxtype( 0, 1 ) * amp[0];
  jamp[82] += cxtype( 0, 1 ) * amp[0];
  jamp[97] += cxtype( 0, 1 ) * amp[0];
  jamp[100] -= cxtype( 0, 1 ) * amp[0];

  // *** DIAGRAM 678 OF 1240 ***

  // Wavefunction(s) for diagram number 678
  // (none)

  // Amplitude(s) for diagram number 678
  FFV1_0( w[46], w[96], w[66], COUPs[1], &amp[0] );
#ifdef MGONGPU_SUPPORTS_MULTICHANNEL
  if( channelId == 678 ) allNumerators[0] += cxabs2( amp[0] );
  if( channelId != 0 ) allDenominators[0] += cxabs2( amp[0] );
#endif
  jamp[19] += amp[0];
  jamp[22] -= amp[0];
  jamp[97] -= amp[0];
  jamp[100] += amp[0];

  // *** DIAGRAM 679 OF 1240 ***

  // Wavefunction(s) for diagram number 679
  // (none)

  // Amplitude(s) for diagram number 679
  FFV1_0( w[88], w[2], w[66], COUPs[1], &amp[0] );
#ifdef MGONGPU_SUPPORTS_MULTICHANNEL
  if( channelId == 679 ) allNumerators[0] += cxabs2( amp[0] );
  if( channelId != 0 ) allDenominators[0] += cxabs2( amp[0] );
#endif
  jamp[37] += amp[0];
  jamp[40] -= amp[0];
  jamp[79] -= amp[0];
  jamp[82] += amp[0];

  // *** DIAGRAM 680 OF 1240 ***

  // Wavefunction(s) for diagram number 680
  VVV1P0_1( w[92], w[1], COUPs[0], 0., 0., w[104] );

  // Amplitude(s) for diagram number 680
  VVV1_0( w[104], w[13], w[5], COUPs[0], &amp[0] );
#ifdef MGONGPU_SUPPORTS_MULTICHANNEL
  if( channelId == 680 ) allNumerators[0] += cxabs2( amp[0] );
  if( channelId != 0 ) allDenominators[0] += cxabs2( amp[0] );
#endif
  jamp[19] -= amp[0];
  jamp[29] += amp[0];
  jamp[43] -= amp[0];
  jamp[52] += amp[0];
  jamp[55] -= amp[0];
  jamp[58] += amp[0];
  jamp[61] -= amp[0];
  jamp[62] += amp[0];
  jamp[63] -= amp[0];
  jamp[64] += amp[0];
  jamp[66] -= amp[0];
  jamp[76] += amp[0];
  jamp[79] -= amp[0];
  jamp[82] += amp[0];
  jamp[90] -= amp[0];
  jamp[97] += amp[0];

  // *** DIAGRAM 681 OF 1240 ***

  // Wavefunction(s) for diagram number 681
  // (none)

  // Amplitude(s) for diagram number 681
  VVV1_0( w[104], w[10], w[4], COUPs[0], &amp[0] );
#ifdef MGONGPU_SUPPORTS_MULTICHANNEL
  if( channelId == 681 ) allNumerators[0] += cxabs2( amp[0] );
  if( channelId != 0 ) allDenominators[0] += cxabs2( amp[0] );
#endif
  jamp[18] -= amp[0];
  jamp[28] += amp[0];
  jamp[42] -= amp[0];
  jamp[52] += amp[0];
  jamp[55] -= amp[0];
  jamp[58] += amp[0];
  jamp[66] -= amp[0];
  jamp[76] += amp[0];
  jamp[79] -= amp[0];
  jamp[82] += amp[0];
  jamp[85] -= amp[0];
  jamp[86] += amp[0];
  jamp[87] -= amp[0];
  jamp[88] += amp[0];
  jamp[90] -= amp[0];
  jamp[96] += amp[0];

  // *** DIAGRAM 682 OF 1240 ***

  // Wavefunction(s) for diagram number 682
  // (none)

  // Amplitude(s) for diagram number 682
  VVVV1_0( w[8], w[4], w[5], w[104], COUPs[2], &amp[0] );
  jamp[19] -= amp[0];
  jamp[29] += amp[0];
  jamp[43] -= amp[0];
  jamp[52] += amp[0];
  jamp[55] -= amp[0];
  jamp[58] += amp[0];
  jamp[61] -= amp[0];
  jamp[62] += amp[0];
  jamp[63] -= amp[0];
  jamp[64] += amp[0];
  jamp[66] -= amp[0];
  jamp[76] += amp[0];
  jamp[79] -= amp[0];
  jamp[82] += amp[0];
  jamp[90] -= amp[0];
  jamp[97] += amp[0];
  VVVV3_0( w[8], w[4], w[5], w[104], COUPs[2], &amp[0] );
  jamp[18] -= amp[0];
  jamp[28] += amp[0];
  jamp[42] -= amp[0];
  jamp[52] += amp[0];
  jamp[55] -= amp[0];
  jamp[58] += amp[0];
  jamp[66] -= amp[0];
  jamp[76] += amp[0];
  jamp[79] -= amp[0];
  jamp[82] += amp[0];
  jamp[85] -= amp[0];
  jamp[86] += amp[0];
  jamp[87] -= amp[0];
  jamp[88] += amp[0];
  jamp[90] -= amp[0];
  jamp[96] += amp[0];
  VVVV4_0( w[8], w[4], w[5], w[104], COUPs[2], &amp[0] );
  jamp[18] -= amp[0];
  jamp[19] += amp[0];
  jamp[28] += amp[0];
  jamp[29] -= amp[0];
  jamp[42] -= amp[0];
  jamp[43] += amp[0];
  jamp[61] += amp[0];
  jamp[62] -= amp[0];
  jamp[63] += amp[0];
  jamp[64] -= amp[0];
  jamp[85] -= amp[0];
  jamp[86] += amp[0];
  jamp[87] -= amp[0];
  jamp[88] += amp[0];
  jamp[96] += amp[0];
  jamp[97] -= amp[0];

  // *** DIAGRAM 683 OF 1240 ***

  // Wavefunction(s) for diagram number 683
  // (none)

  // Amplitude(s) for diagram number 683
  VVV1_0( w[112], w[108], w[5], COUPs[0], &amp[0] );
#ifdef MGONGPU_SUPPORTS_MULTICHANNEL
  if( channelId == 683 ) allNumerators[0] += cxabs2( amp[0] );
  if( channelId != 0 ) allDenominators[0] += cxabs2( amp[0] );
#endif
  jamp[21] += amp[0];
  jamp[28] -= amp[0];
  jamp[31] += amp[0];
  jamp[34] -= amp[0];
  jamp[37] += amp[0];
  jamp[38] -= amp[0];
  jamp[39] += amp[0];
  jamp[40] -= amp[0];
  jamp[42] += amp[0];
  jamp[53] -= amp[0];
  jamp[67] += amp[0];
  jamp[77] -= amp[0];
  jamp[85] += amp[0];
  jamp[88] -= amp[0];
  jamp[91] += amp[0];
  jamp[99] -= amp[0];

  // *** DIAGRAM 684 OF 1240 ***

  // Wavefunction(s) for diagram number 684
  // (none)

  // Amplitude(s) for diagram number 684
  VVV1_0( w[112], w[1], w[10], COUPs[0], &amp[0] );
#ifdef MGONGPU_SUPPORTS_MULTICHANNEL
  if( channelId == 684 ) allNumerators[0] += cxabs2( amp[0] );
  if( channelId != 0 ) allDenominators[0] += cxabs2( amp[0] );
#endif
  jamp[20] += amp[0];
  jamp[28] -= amp[0];
  jamp[31] += amp[0];
  jamp[34] -= amp[0];
  jamp[42] += amp[0];
  jamp[52] -= amp[0];
  jamp[66] += amp[0];
  jamp[77] -= amp[0];
  jamp[79] += amp[0];
  jamp[80] -= amp[0];
  jamp[81] += amp[0];
  jamp[82] -= amp[0];
  jamp[85] += amp[0];
  jamp[88] -= amp[0];
  jamp[91] += amp[0];
  jamp[98] -= amp[0];

  // *** DIAGRAM 685 OF 1240 ***

  // Wavefunction(s) for diagram number 685
  // (none)

  // Amplitude(s) for diagram number 685
  VVVV1_0( w[1], w[8], w[5], w[112], COUPs[2], &amp[0] );
  jamp[21] += amp[0];
  jamp[28] -= amp[0];
  jamp[31] += amp[0];
  jamp[34] -= amp[0];
  jamp[37] += amp[0];
  jamp[38] -= amp[0];
  jamp[39] += amp[0];
  jamp[40] -= amp[0];
  jamp[42] += amp[0];
  jamp[53] -= amp[0];
  jamp[67] += amp[0];
  jamp[77] -= amp[0];
  jamp[85] += amp[0];
  jamp[88] -= amp[0];
  jamp[91] += amp[0];
  jamp[99] -= amp[0];
  VVVV3_0( w[1], w[8], w[5], w[112], COUPs[2], &amp[0] );
  jamp[20] -= amp[0];
  jamp[21] += amp[0];
  jamp[37] += amp[0];
  jamp[38] -= amp[0];
  jamp[39] += amp[0];
  jamp[40] -= amp[0];
  jamp[52] += amp[0];
  jamp[53] -= amp[0];
  jamp[66] -= amp[0];
  jamp[67] += amp[0];
  jamp[79] -= amp[0];
  jamp[80] += amp[0];
  jamp[81] -= amp[0];
  jamp[82] += amp[0];
  jamp[98] += amp[0];
  jamp[99] -= amp[0];
  VVVV4_0( w[1], w[8], w[5], w[112], COUPs[2], &amp[0] );
  jamp[20] -= amp[0];
  jamp[28] += amp[0];
  jamp[31] -= amp[0];
  jamp[34] += amp[0];
  jamp[42] -= amp[0];
  jamp[52] += amp[0];
  jamp[66] -= amp[0];
  jamp[77] += amp[0];
  jamp[79] -= amp[0];
  jamp[80] += amp[0];
  jamp[81] -= amp[0];
  jamp[82] += amp[0];
  jamp[85] -= amp[0];
  jamp[88] += amp[0];
  jamp[91] -= amp[0];
  jamp[98] += amp[0];

  // *** DIAGRAM 686 OF 1240 ***

  // Wavefunction(s) for diagram number 686
  // (none)

  // Amplitude(s) for diagram number 686
  VVV1_0( w[86], w[108], w[4], COUPs[0], &amp[0] );
#ifdef MGONGPU_SUPPORTS_MULTICHANNEL
  if( channelId == 686 ) allNumerators[0] += cxabs2( amp[0] );
  if( channelId != 0 ) allDenominators[0] += cxabs2( amp[0] );
#endif
  jamp[23] += amp[0];
  jamp[29] -= amp[0];
  jamp[31] += amp[0];
  jamp[32] -= amp[0];
  jamp[33] += amp[0];
  jamp[34] -= amp[0];
  jamp[37] += amp[0];
  jamp[40] -= amp[0];
  jamp[43] += amp[0];
  jamp[53] -= amp[0];
  jamp[61] += amp[0];
  jamp[64] -= amp[0];
  jamp[67] += amp[0];
  jamp[77] -= amp[0];
  jamp[91] += amp[0];
  jamp[101] -= amp[0];

  // *** DIAGRAM 687 OF 1240 ***

  // Wavefunction(s) for diagram number 687
  // (none)

  // Amplitude(s) for diagram number 687
  VVV1_0( w[86], w[1], w[13], COUPs[0], &amp[0] );
#ifdef MGONGPU_SUPPORTS_MULTICHANNEL
  if( channelId == 687 ) allNumerators[0] += cxabs2( amp[0] );
  if( channelId != 0 ) allDenominators[0] += cxabs2( amp[0] );
#endif
  jamp[22] += amp[0];
  jamp[29] -= amp[0];
  jamp[37] += amp[0];
  jamp[40] -= amp[0];
  jamp[43] += amp[0];
  jamp[53] -= amp[0];
  jamp[55] += amp[0];
  jamp[56] -= amp[0];
  jamp[57] += amp[0];
  jamp[58] -= amp[0];
  jamp[61] += amp[0];
  jamp[64] -= amp[0];
  jamp[67] += amp[0];
  jamp[76] -= amp[0];
  jamp[90] += amp[0];
  jamp[100] -= amp[0];

  // *** DIAGRAM 688 OF 1240 ***

  // Wavefunction(s) for diagram number 688
  // (none)

  // Amplitude(s) for diagram number 688
  VVVV1_0( w[1], w[8], w[4], w[86], COUPs[2], &amp[0] );
  jamp[23] += amp[0];
  jamp[29] -= amp[0];
  jamp[31] += amp[0];
  jamp[32] -= amp[0];
  jamp[33] += amp[0];
  jamp[34] -= amp[0];
  jamp[37] += amp[0];
  jamp[40] -= amp[0];
  jamp[43] += amp[0];
  jamp[53] -= amp[0];
  jamp[61] += amp[0];
  jamp[64] -= amp[0];
  jamp[67] += amp[0];
  jamp[77] -= amp[0];
  jamp[91] += amp[0];
  jamp[101] -= amp[0];
  VVVV3_0( w[1], w[8], w[4], w[86], COUPs[2], &amp[0] );
  jamp[22] -= amp[0];
  jamp[23] += amp[0];
  jamp[31] += amp[0];
  jamp[32] -= amp[0];
  jamp[33] += amp[0];
  jamp[34] -= amp[0];
  jamp[55] -= amp[0];
  jamp[56] += amp[0];
  jamp[57] -= amp[0];
  jamp[58] += amp[0];
  jamp[76] += amp[0];
  jamp[77] -= amp[0];
  jamp[90] -= amp[0];
  jamp[91] += amp[0];
  jamp[100] += amp[0];
  jamp[101] -= amp[0];
  VVVV4_0( w[1], w[8], w[4], w[86], COUPs[2], &amp[0] );
  jamp[22] -= amp[0];
  jamp[29] += amp[0];
  jamp[37] -= amp[0];
  jamp[40] += amp[0];
  jamp[43] -= amp[0];
  jamp[53] += amp[0];
  jamp[55] -= amp[0];
  jamp[56] += amp[0];
  jamp[57] -= amp[0];
  jamp[58] += amp[0];
  jamp[61] -= amp[0];
  jamp[64] += amp[0];
  jamp[67] -= amp[0];
  jamp[76] += amp[0];
  jamp[90] -= amp[0];
  jamp[100] += amp[0];

  // *** DIAGRAM 689 OF 1240 ***

  // Wavefunction(s) for diagram number 689
  VVVV1P0_1( w[92], w[1], w[4], COUPs[2], 0., 0., w[98] );
  VVVV3P0_1( w[92], w[1], w[4], COUPs[2], 0., 0., w[62] );
  VVVV4P0_1( w[92], w[1], w[4], COUPs[2], 0., 0., w[101] );

  // Amplitude(s) for diagram number 689
  VVV1_0( w[8], w[5], w[98], COUPs[0], &amp[0] );
  jamp[18] += amp[0];
  jamp[20] -= amp[0];
  jamp[31] -= amp[0];
  jamp[34] += amp[0];
  jamp[55] += amp[0];
  jamp[58] -= amp[0];
  jamp[76] -= amp[0];
  jamp[77] += amp[0];
  jamp[80] += amp[0];
  jamp[81] -= amp[0];
  jamp[86] -= amp[0];
  jamp[87] += amp[0];
  jamp[90] += amp[0];
  jamp[91] -= amp[0];
  jamp[96] -= amp[0];
  jamp[98] += amp[0];
  VVV1_0( w[8], w[5], w[62], COUPs[0], &amp[0] );
  jamp[20] -= amp[0];
  jamp[28] += amp[0];
  jamp[31] -= amp[0];
  jamp[34] += amp[0];
  jamp[42] -= amp[0];
  jamp[52] += amp[0];
  jamp[66] -= amp[0];
  jamp[77] += amp[0];
  jamp[79] -= amp[0];
  jamp[80] += amp[0];
  jamp[81] -= amp[0];
  jamp[82] += amp[0];
  jamp[85] -= amp[0];
  jamp[88] += amp[0];
  jamp[91] -= amp[0];
  jamp[98] += amp[0];
  VVV1_0( w[8], w[5], w[101], COUPs[0], &amp[0] );
  jamp[18] -= amp[0];
  jamp[28] += amp[0];
  jamp[42] -= amp[0];
  jamp[52] += amp[0];
  jamp[55] -= amp[0];
  jamp[58] += amp[0];
  jamp[66] -= amp[0];
  jamp[76] += amp[0];
  jamp[79] -= amp[0];
  jamp[82] += amp[0];
  jamp[85] -= amp[0];
  jamp[86] += amp[0];
  jamp[87] -= amp[0];
  jamp[88] += amp[0];
  jamp[90] -= amp[0];
  jamp[96] += amp[0];

  // *** DIAGRAM 690 OF 1240 ***

  // Wavefunction(s) for diagram number 690
  VVVV1P0_1( w[92], w[1], w[5], COUPs[2], 0., 0., w[109] );
  VVVV3P0_1( w[92], w[1], w[5], COUPs[2], 0., 0., w[110] );
  VVVV4P0_1( w[92], w[1], w[5], COUPs[2], 0., 0., w[111] );

  // Amplitude(s) for diagram number 690
  VVV1_0( w[8], w[4], w[109], COUPs[0], &amp[0] );
  jamp[19] += amp[0];
  jamp[22] -= amp[0];
  jamp[37] -= amp[0];
  jamp[40] += amp[0];
  jamp[52] -= amp[0];
  jamp[53] += amp[0];
  jamp[56] += amp[0];
  jamp[57] -= amp[0];
  jamp[62] -= amp[0];
  jamp[63] += amp[0];
  jamp[66] += amp[0];
  jamp[67] -= amp[0];
  jamp[79] += amp[0];
  jamp[82] -= amp[0];
  jamp[97] -= amp[0];
  jamp[100] += amp[0];
  VVV1_0( w[8], w[4], w[110], COUPs[0], &amp[0] );
  jamp[22] -= amp[0];
  jamp[29] += amp[0];
  jamp[37] -= amp[0];
  jamp[40] += amp[0];
  jamp[43] -= amp[0];
  jamp[53] += amp[0];
  jamp[55] -= amp[0];
  jamp[56] += amp[0];
  jamp[57] -= amp[0];
  jamp[58] += amp[0];
  jamp[61] -= amp[0];
  jamp[64] += amp[0];
  jamp[67] -= amp[0];
  jamp[76] += amp[0];
  jamp[90] -= amp[0];
  jamp[100] += amp[0];
  VVV1_0( w[8], w[4], w[111], COUPs[0], &amp[0] );
  jamp[19] -= amp[0];
  jamp[29] += amp[0];
  jamp[43] -= amp[0];
  jamp[52] += amp[0];
  jamp[55] -= amp[0];
  jamp[58] += amp[0];
  jamp[61] -= amp[0];
  jamp[62] += amp[0];
  jamp[63] -= amp[0];
  jamp[64] += amp[0];
  jamp[66] -= amp[0];
  jamp[76] += amp[0];
  jamp[79] -= amp[0];
  jamp[82] += amp[0];
  jamp[90] -= amp[0];
  jamp[97] += amp[0];

  // *** DIAGRAM 691 OF 1240 ***

  // Wavefunction(s) for diagram number 691
  // (none)

  // Amplitude(s) for diagram number 691
  VVV1_0( w[1], w[8], w[107], COUPs[0], &amp[0] );
  jamp[21] -= amp[0];
  jamp[23] += amp[0];
  jamp[28] += amp[0];
  jamp[29] -= amp[0];
  jamp[32] -= amp[0];
  jamp[33] += amp[0];
  jamp[38] += amp[0];
  jamp[39] -= amp[0];
  jamp[42] -= amp[0];
  jamp[43] += amp[0];
  jamp[61] += amp[0];
  jamp[64] -= amp[0];
  jamp[85] -= amp[0];
  jamp[88] += amp[0];
  jamp[99] += amp[0];
  jamp[101] -= amp[0];
  VVV1_0( w[1], w[8], w[95], COUPs[0], &amp[0] );
  jamp[23] += amp[0];
  jamp[29] -= amp[0];
  jamp[31] += amp[0];
  jamp[32] -= amp[0];
  jamp[33] += amp[0];
  jamp[34] -= amp[0];
  jamp[37] += amp[0];
  jamp[40] -= amp[0];
  jamp[43] += amp[0];
  jamp[53] -= amp[0];
  jamp[61] += amp[0];
  jamp[64] -= amp[0];
  jamp[67] += amp[0];
  jamp[77] -= amp[0];
  jamp[91] += amp[0];
  jamp[101] -= amp[0];
  VVV1_0( w[1], w[8], w[105], COUPs[0], &amp[0] );
  jamp[21] += amp[0];
  jamp[28] -= amp[0];
  jamp[31] += amp[0];
  jamp[34] -= amp[0];
  jamp[37] += amp[0];
  jamp[38] -= amp[0];
  jamp[39] += amp[0];
  jamp[40] -= amp[0];
  jamp[42] += amp[0];
  jamp[53] -= amp[0];
  jamp[67] += amp[0];
  jamp[77] -= amp[0];
  jamp[85] += amp[0];
  jamp[88] -= amp[0];
  jamp[91] += amp[0];
  jamp[99] -= amp[0];

  // *** DIAGRAM 692 OF 1240 ***

  // Wavefunction(s) for diagram number 692
  // (none)

  // Amplitude(s) for diagram number 692
  VVVV1_0( w[92], w[1], w[8], w[24], COUPs[2], &amp[0] );
  jamp[18] += amp[0];
  jamp[19] -= amp[0];
  jamp[28] -= amp[0];
  jamp[29] += amp[0];
  jamp[42] += amp[0];
  jamp[43] -= amp[0];
  jamp[61] -= amp[0];
  jamp[62] += amp[0];
  jamp[63] -= amp[0];
  jamp[64] += amp[0];
  jamp[85] += amp[0];
  jamp[86] -= amp[0];
  jamp[87] += amp[0];
  jamp[88] -= amp[0];
  jamp[96] -= amp[0];
  jamp[97] += amp[0];
  VVVV3_0( w[92], w[1], w[8], w[24], COUPs[2], &amp[0] );
  jamp[18] += amp[0];
  jamp[19] -= amp[0];
  jamp[21] -= amp[0];
  jamp[23] += amp[0];
  jamp[32] -= amp[0];
  jamp[33] += amp[0];
  jamp[38] += amp[0];
  jamp[39] -= amp[0];
  jamp[62] += amp[0];
  jamp[63] -= amp[0];
  jamp[86] -= amp[0];
  jamp[87] += amp[0];
  jamp[96] -= amp[0];
  jamp[97] += amp[0];
  jamp[99] += amp[0];
  jamp[101] -= amp[0];
  VVVV4_0( w[92], w[1], w[8], w[24], COUPs[2], &amp[0] );
  jamp[21] -= amp[0];
  jamp[23] += amp[0];
  jamp[28] += amp[0];
  jamp[29] -= amp[0];
  jamp[32] -= amp[0];
  jamp[33] += amp[0];
  jamp[38] += amp[0];
  jamp[39] -= amp[0];
  jamp[42] -= amp[0];
  jamp[43] += amp[0];
  jamp[61] += amp[0];
  jamp[64] -= amp[0];
  jamp[85] -= amp[0];
  jamp[88] += amp[0];
  jamp[99] += amp[0];
  jamp[101] -= amp[0];

  // *** DIAGRAM 693 OF 1240 ***

  // Wavefunction(s) for diagram number 693
  // (none)

  // Amplitude(s) for diagram number 693
  VVV1_0( w[8], w[24], w[104], COUPs[0], &amp[0] );
#ifdef MGONGPU_SUPPORTS_MULTICHANNEL
  if( channelId == 693 ) allNumerators[0] += cxabs2( amp[0] );
  if( channelId != 0 ) allDenominators[0] += cxabs2( amp[0] );
#endif
  jamp[18] += amp[0];
  jamp[19] -= amp[0];
  jamp[28] -= amp[0];
  jamp[29] += amp[0];
  jamp[42] += amp[0];
  jamp[43] -= amp[0];
  jamp[61] -= amp[0];
  jamp[62] += amp[0];
  jamp[63] -= amp[0];
  jamp[64] += amp[0];
  jamp[85] += amp[0];
  jamp[86] -= amp[0];
  jamp[87] += amp[0];
  jamp[88] -= amp[0];
  jamp[96] -= amp[0];
  jamp[97] += amp[0];

  // *** DIAGRAM 694 OF 1240 ***

  // Wavefunction(s) for diagram number 694
  // (none)

  // Amplitude(s) for diagram number 694
  VVV1_0( w[1], w[24], w[113], COUPs[0], &amp[0] );
#ifdef MGONGPU_SUPPORTS_MULTICHANNEL
  if( channelId == 694 ) allNumerators[0] += cxabs2( amp[0] );
  if( channelId != 0 ) allDenominators[0] += cxabs2( amp[0] );
#endif
  jamp[18] += amp[0];
  jamp[19] -= amp[0];
  jamp[21] -= amp[0];
  jamp[23] += amp[0];
  jamp[32] -= amp[0];
  jamp[33] += amp[0];
  jamp[38] += amp[0];
  jamp[39] -= amp[0];
  jamp[62] += amp[0];
  jamp[63] -= amp[0];
  jamp[86] -= amp[0];
  jamp[87] += amp[0];
  jamp[96] -= amp[0];
  jamp[97] += amp[0];
  jamp[99] += amp[0];
  jamp[101] -= amp[0];

  // *** DIAGRAM 695 OF 1240 ***

  // Wavefunction(s) for diagram number 695
  // (none)

  // Amplitude(s) for diagram number 695
  VVV1_0( w[1], w[8], w[102], COUPs[0], &amp[0] );
#ifdef MGONGPU_SUPPORTS_MULTICHANNEL
  if( channelId == 695 ) allNumerators[0] += cxabs2( amp[0] );
  if( channelId != 0 ) allDenominators[0] += cxabs2( amp[0] );
#endif
  jamp[21] -= amp[0];
  jamp[23] += amp[0];
  jamp[28] += amp[0];
  jamp[29] -= amp[0];
  jamp[32] -= amp[0];
  jamp[33] += amp[0];
  jamp[38] += amp[0];
  jamp[39] -= amp[0];
  jamp[42] -= amp[0];
  jamp[43] += amp[0];
  jamp[61] += amp[0];
  jamp[64] -= amp[0];
  jamp[85] -= amp[0];
  jamp[88] += amp[0];
  jamp[99] += amp[0];
  jamp[101] -= amp[0];

  // *** DIAGRAM 696 OF 1240 ***

  // Wavefunction(s) for diagram number 696
  // (none)

  // Amplitude(s) for diagram number 696
  VVV1_0( w[104], w[37], w[5], COUPs[0], &amp[0] );
#ifdef MGONGPU_SUPPORTS_MULTICHANNEL
  if( channelId == 696 ) allNumerators[0] += cxabs2( amp[0] );
  if( channelId != 0 ) allDenominators[0] += cxabs2( amp[0] );
#endif
  jamp[52] += cxtype( 0, 1 ) * amp[0];
  jamp[55] -= cxtype( 0, 1 ) * amp[0];
  jamp[58] += cxtype( 0, 1 ) * amp[0];
  jamp[61] -= cxtype( 0, 1 ) * amp[0];
  jamp[62] += cxtype( 0, 1 ) * amp[0];
  jamp[63] -= cxtype( 0, 1 ) * amp[0];
  jamp[64] += cxtype( 0, 1 ) * amp[0];
  jamp[66] -= cxtype( 0, 1 ) * amp[0];

  // *** DIAGRAM 697 OF 1240 ***

  // Wavefunction(s) for diagram number 697
  // (none)

  // Amplitude(s) for diagram number 697
  FFV1_0( w[3], w[35], w[104], COUPs[1], &amp[0] );
#ifdef MGONGPU_SUPPORTS_MULTICHANNEL
  if( channelId == 697 ) allNumerators[0] += cxabs2( amp[0] );
  if( channelId != 0 ) allDenominators[0] += cxabs2( amp[0] );
#endif
  jamp[61] += amp[0];
  jamp[62] -= amp[0];
  jamp[63] += amp[0];
  jamp[64] -= amp[0];

  // *** DIAGRAM 698 OF 1240 ***

  // Wavefunction(s) for diagram number 698
  // (none)

  // Amplitude(s) for diagram number 698
  FFV1_0( w[99], w[100], w[5], COUPs[1], &amp[0] );
#ifdef MGONGPU_SUPPORTS_MULTICHANNEL
  if( channelId == 698 ) allNumerators[0] += cxabs2( amp[0] );
  if( channelId != 0 ) allDenominators[0] += cxabs2( amp[0] );
#endif
  jamp[56] += cxtype( 0, 1 ) * amp[0];
  jamp[57] -= cxtype( 0, 1 ) * amp[0];

  // *** DIAGRAM 699 OF 1240 ***

  // Wavefunction(s) for diagram number 699
  // (none)

  // Amplitude(s) for diagram number 699
  FFV1_0( w[99], w[35], w[1], COUPs[1], &amp[0] );
#ifdef MGONGPU_SUPPORTS_MULTICHANNEL
  if( channelId == 699 ) allNumerators[0] += cxabs2( amp[0] );
  if( channelId != 0 ) allDenominators[0] += cxabs2( amp[0] );
#endif
  jamp[62] += cxtype( 0, 1 ) * amp[0];
  jamp[63] -= cxtype( 0, 1 ) * amp[0];

  // *** DIAGRAM 700 OF 1240 ***

  // Wavefunction(s) for diagram number 700
  // (none)

  // Amplitude(s) for diagram number 700
  FFV1_0( w[3], w[100], w[86], COUPs[1], &amp[0] );
#ifdef MGONGPU_SUPPORTS_MULTICHANNEL
  if( channelId == 700 ) allNumerators[0] += cxabs2( amp[0] );
  if( channelId != 0 ) allDenominators[0] += cxabs2( amp[0] );
#endif
  jamp[55] += amp[0];
  jamp[56] -= amp[0];
  jamp[57] += amp[0];
  jamp[58] -= amp[0];

  // *** DIAGRAM 701 OF 1240 ***

  // Wavefunction(s) for diagram number 701
  // (none)

  // Amplitude(s) for diagram number 701
  VVV1_0( w[86], w[1], w[37], COUPs[0], &amp[0] );
#ifdef MGONGPU_SUPPORTS_MULTICHANNEL
  if( channelId == 701 ) allNumerators[0] += cxabs2( amp[0] );
  if( channelId != 0 ) allDenominators[0] += cxabs2( amp[0] );
#endif
  jamp[53] -= cxtype( 0, 1 ) * amp[0];
  jamp[55] += cxtype( 0, 1 ) * amp[0];
  jamp[56] -= cxtype( 0, 1 ) * amp[0];
  jamp[57] += cxtype( 0, 1 ) * amp[0];
  jamp[58] -= cxtype( 0, 1 ) * amp[0];
  jamp[61] += cxtype( 0, 1 ) * amp[0];
  jamp[64] -= cxtype( 0, 1 ) * amp[0];
  jamp[67] += cxtype( 0, 1 ) * amp[0];

  // *** DIAGRAM 702 OF 1240 ***

  // Wavefunction(s) for diagram number 702
  // (none)

  // Amplitude(s) for diagram number 702
  FFV1_0( w[3], w[33], w[109], COUPs[1], &amp[0] );
  jamp[52] -= cxtype( 0, 1 ) * amp[0];
  jamp[53] += cxtype( 0, 1 ) * amp[0];
  jamp[56] += cxtype( 0, 1 ) * amp[0];
  jamp[57] -= cxtype( 0, 1 ) * amp[0];
  jamp[62] -= cxtype( 0, 1 ) * amp[0];
  jamp[63] += cxtype( 0, 1 ) * amp[0];
  jamp[66] += cxtype( 0, 1 ) * amp[0];
  jamp[67] -= cxtype( 0, 1 ) * amp[0];
  FFV1_0( w[3], w[33], w[110], COUPs[1], &amp[0] );
  jamp[53] += cxtype( 0, 1 ) * amp[0];
  jamp[55] -= cxtype( 0, 1 ) * amp[0];
  jamp[56] += cxtype( 0, 1 ) * amp[0];
  jamp[57] -= cxtype( 0, 1 ) * amp[0];
  jamp[58] += cxtype( 0, 1 ) * amp[0];
  jamp[61] -= cxtype( 0, 1 ) * amp[0];
  jamp[64] += cxtype( 0, 1 ) * amp[0];
  jamp[67] -= cxtype( 0, 1 ) * amp[0];
  FFV1_0( w[3], w[33], w[111], COUPs[1], &amp[0] );
  jamp[52] += cxtype( 0, 1 ) * amp[0];
  jamp[55] -= cxtype( 0, 1 ) * amp[0];
  jamp[58] += cxtype( 0, 1 ) * amp[0];
  jamp[61] -= cxtype( 0, 1 ) * amp[0];
  jamp[62] += cxtype( 0, 1 ) * amp[0];
  jamp[63] -= cxtype( 0, 1 ) * amp[0];
  jamp[64] += cxtype( 0, 1 ) * amp[0];
  jamp[66] -= cxtype( 0, 1 ) * amp[0];

  // *** DIAGRAM 703 OF 1240 ***

  // Wavefunction(s) for diagram number 703
  // (none)

  // Amplitude(s) for diagram number 703
  FFV1_0( w[38], w[33], w[104], COUPs[1], &amp[0] );
#ifdef MGONGPU_SUPPORTS_MULTICHANNEL
  if( channelId == 703 ) allNumerators[0] += cxabs2( amp[0] );
  if( channelId != 0 ) allDenominators[0] += cxabs2( amp[0] );
#endif
  jamp[52] += amp[0];
  jamp[55] -= amp[0];
  jamp[58] += amp[0];
  jamp[66] -= amp[0];

  // *** DIAGRAM 704 OF 1240 ***

  // Wavefunction(s) for diagram number 704
  // (none)

  // Amplitude(s) for diagram number 704
  FFV1_0( w[38], w[114], w[1], COUPs[1], &amp[0] );
#ifdef MGONGPU_SUPPORTS_MULTICHANNEL
  if( channelId == 704 ) allNumerators[0] += cxabs2( amp[0] );
  if( channelId != 0 ) allDenominators[0] += cxabs2( amp[0] );
#endif
  jamp[52] += cxtype( 0, 1 ) * amp[0];
  jamp[66] -= cxtype( 0, 1 ) * amp[0];

  // *** DIAGRAM 705 OF 1240 ***

  // Wavefunction(s) for diagram number 705
  // (none)

  // Amplitude(s) for diagram number 705
  FFV1_0( w[90], w[33], w[1], COUPs[1], &amp[0] );
#ifdef MGONGPU_SUPPORTS_MULTICHANNEL
  if( channelId == 705 ) allNumerators[0] += cxabs2( amp[0] );
  if( channelId != 0 ) allDenominators[0] += cxabs2( amp[0] );
#endif
  jamp[55] += cxtype( 0, 1 ) * amp[0];
  jamp[58] -= cxtype( 0, 1 ) * amp[0];

  // *** DIAGRAM 706 OF 1240 ***

  // Wavefunction(s) for diagram number 706
  // (none)

  // Amplitude(s) for diagram number 706
  VVV1_0( w[104], w[45], w[4], COUPs[0], &amp[0] );
#ifdef MGONGPU_SUPPORTS_MULTICHANNEL
  if( channelId == 706 ) allNumerators[0] += cxabs2( amp[0] );
  if( channelId != 0 ) allDenominators[0] += cxabs2( amp[0] );
#endif
  jamp[76] += cxtype( 0, 1 ) * amp[0];
  jamp[79] -= cxtype( 0, 1 ) * amp[0];
  jamp[82] += cxtype( 0, 1 ) * amp[0];
  jamp[85] -= cxtype( 0, 1 ) * amp[0];
  jamp[86] += cxtype( 0, 1 ) * amp[0];
  jamp[87] -= cxtype( 0, 1 ) * amp[0];
  jamp[88] += cxtype( 0, 1 ) * amp[0];
  jamp[90] -= cxtype( 0, 1 ) * amp[0];

  // *** DIAGRAM 707 OF 1240 ***

  // Wavefunction(s) for diagram number 707
  // (none)

  // Amplitude(s) for diagram number 707
  FFV1_0( w[3], w[43], w[104], COUPs[1], &amp[0] );
#ifdef MGONGPU_SUPPORTS_MULTICHANNEL
  if( channelId == 707 ) allNumerators[0] += cxabs2( amp[0] );
  if( channelId != 0 ) allDenominators[0] += cxabs2( amp[0] );
#endif
  jamp[85] += amp[0];
  jamp[86] -= amp[0];
  jamp[87] += amp[0];
  jamp[88] -= amp[0];

  // *** DIAGRAM 708 OF 1240 ***

  // Wavefunction(s) for diagram number 708
  // (none)

  // Amplitude(s) for diagram number 708
  FFV1_0( w[99], w[89], w[4], COUPs[1], &amp[0] );
#ifdef MGONGPU_SUPPORTS_MULTICHANNEL
  if( channelId == 708 ) allNumerators[0] += cxabs2( amp[0] );
  if( channelId != 0 ) allDenominators[0] += cxabs2( amp[0] );
#endif
  jamp[80] += cxtype( 0, 1 ) * amp[0];
  jamp[81] -= cxtype( 0, 1 ) * amp[0];

  // *** DIAGRAM 709 OF 1240 ***

  // Wavefunction(s) for diagram number 709
  // (none)

  // Amplitude(s) for diagram number 709
  FFV1_0( w[99], w[43], w[1], COUPs[1], &amp[0] );
#ifdef MGONGPU_SUPPORTS_MULTICHANNEL
  if( channelId == 709 ) allNumerators[0] += cxabs2( amp[0] );
  if( channelId != 0 ) allDenominators[0] += cxabs2( amp[0] );
#endif
  jamp[86] += cxtype( 0, 1 ) * amp[0];
  jamp[87] -= cxtype( 0, 1 ) * amp[0];

  // *** DIAGRAM 710 OF 1240 ***

  // Wavefunction(s) for diagram number 710
  // (none)

  // Amplitude(s) for diagram number 710
  FFV1_0( w[3], w[89], w[112], COUPs[1], &amp[0] );
#ifdef MGONGPU_SUPPORTS_MULTICHANNEL
  if( channelId == 710 ) allNumerators[0] += cxabs2( amp[0] );
  if( channelId != 0 ) allDenominators[0] += cxabs2( amp[0] );
#endif
  jamp[79] += amp[0];
  jamp[80] -= amp[0];
  jamp[81] += amp[0];
  jamp[82] -= amp[0];

  // *** DIAGRAM 711 OF 1240 ***

  // Wavefunction(s) for diagram number 711
  // (none)

  // Amplitude(s) for diagram number 711
  VVV1_0( w[112], w[1], w[45], COUPs[0], &amp[0] );
#ifdef MGONGPU_SUPPORTS_MULTICHANNEL
  if( channelId == 711 ) allNumerators[0] += cxabs2( amp[0] );
  if( channelId != 0 ) allDenominators[0] += cxabs2( amp[0] );
#endif
  jamp[77] -= cxtype( 0, 1 ) * amp[0];
  jamp[79] += cxtype( 0, 1 ) * amp[0];
  jamp[80] -= cxtype( 0, 1 ) * amp[0];
  jamp[81] += cxtype( 0, 1 ) * amp[0];
  jamp[82] -= cxtype( 0, 1 ) * amp[0];
  jamp[85] += cxtype( 0, 1 ) * amp[0];
  jamp[88] -= cxtype( 0, 1 ) * amp[0];
  jamp[91] += cxtype( 0, 1 ) * amp[0];

  // *** DIAGRAM 712 OF 1240 ***

  // Wavefunction(s) for diagram number 712
  // (none)

  // Amplitude(s) for diagram number 712
  FFV1_0( w[3], w[39], w[98], COUPs[1], &amp[0] );
  jamp[76] -= cxtype( 0, 1 ) * amp[0];
  jamp[77] += cxtype( 0, 1 ) * amp[0];
  jamp[80] += cxtype( 0, 1 ) * amp[0];
  jamp[81] -= cxtype( 0, 1 ) * amp[0];
  jamp[86] -= cxtype( 0, 1 ) * amp[0];
  jamp[87] += cxtype( 0, 1 ) * amp[0];
  jamp[90] += cxtype( 0, 1 ) * amp[0];
  jamp[91] -= cxtype( 0, 1 ) * amp[0];
  FFV1_0( w[3], w[39], w[62], COUPs[1], &amp[0] );
  jamp[77] += cxtype( 0, 1 ) * amp[0];
  jamp[79] -= cxtype( 0, 1 ) * amp[0];
  jamp[80] += cxtype( 0, 1 ) * amp[0];
  jamp[81] -= cxtype( 0, 1 ) * amp[0];
  jamp[82] += cxtype( 0, 1 ) * amp[0];
  jamp[85] -= cxtype( 0, 1 ) * amp[0];
  jamp[88] += cxtype( 0, 1 ) * amp[0];
  jamp[91] -= cxtype( 0, 1 ) * amp[0];
  FFV1_0( w[3], w[39], w[101], COUPs[1], &amp[0] );
  jamp[76] += cxtype( 0, 1 ) * amp[0];
  jamp[79] -= cxtype( 0, 1 ) * amp[0];
  jamp[82] += cxtype( 0, 1 ) * amp[0];
  jamp[85] -= cxtype( 0, 1 ) * amp[0];
  jamp[86] += cxtype( 0, 1 ) * amp[0];
  jamp[87] -= cxtype( 0, 1 ) * amp[0];
  jamp[88] += cxtype( 0, 1 ) * amp[0];
  jamp[90] -= cxtype( 0, 1 ) * amp[0];

  // *** DIAGRAM 713 OF 1240 ***

  // Wavefunction(s) for diagram number 713
  // (none)

  // Amplitude(s) for diagram number 713
  FFV1_0( w[46], w[39], w[104], COUPs[1], &amp[0] );
#ifdef MGONGPU_SUPPORTS_MULTICHANNEL
  if( channelId == 713 ) allNumerators[0] += cxabs2( amp[0] );
  if( channelId != 0 ) allDenominators[0] += cxabs2( amp[0] );
#endif
  jamp[76] += amp[0];
  jamp[79] -= amp[0];
  jamp[82] += amp[0];
  jamp[90] -= amp[0];

  // *** DIAGRAM 714 OF 1240 ***

  // Wavefunction(s) for diagram number 714
  // (none)

  // Amplitude(s) for diagram number 714
  FFV1_0( w[46], w[106], w[1], COUPs[1], &amp[0] );
#ifdef MGONGPU_SUPPORTS_MULTICHANNEL
  if( channelId == 714 ) allNumerators[0] += cxabs2( amp[0] );
  if( channelId != 0 ) allDenominators[0] += cxabs2( amp[0] );
#endif
  jamp[76] += cxtype( 0, 1 ) * amp[0];
  jamp[90] -= cxtype( 0, 1 ) * amp[0];

  // *** DIAGRAM 715 OF 1240 ***

  // Wavefunction(s) for diagram number 715
  // (none)

  // Amplitude(s) for diagram number 715
  FFV1_0( w[88], w[39], w[1], COUPs[1], &amp[0] );
#ifdef MGONGPU_SUPPORTS_MULTICHANNEL
  if( channelId == 715 ) allNumerators[0] += cxabs2( amp[0] );
  if( channelId != 0 ) allDenominators[0] += cxabs2( amp[0] );
#endif
  jamp[79] += cxtype( 0, 1 ) * amp[0];
  jamp[82] -= cxtype( 0, 1 ) * amp[0];

  // *** DIAGRAM 716 OF 1240 ***

  // Wavefunction(s) for diagram number 716
  // (none)

  // Amplitude(s) for diagram number 716
  VVV1_0( w[104], w[54], w[5], COUPs[0], &amp[0] );
#ifdef MGONGPU_SUPPORTS_MULTICHANNEL
  if( channelId == 716 ) allNumerators[0] += cxabs2( amp[0] );
  if( channelId != 0 ) allDenominators[0] += cxabs2( amp[0] );
#endif
  jamp[19] += cxtype( 0, 1 ) * amp[0];
  jamp[29] -= cxtype( 0, 1 ) * amp[0];
  jamp[43] += cxtype( 0, 1 ) * amp[0];
  jamp[76] -= cxtype( 0, 1 ) * amp[0];
  jamp[79] += cxtype( 0, 1 ) * amp[0];
  jamp[82] -= cxtype( 0, 1 ) * amp[0];
  jamp[90] += cxtype( 0, 1 ) * amp[0];
  jamp[97] -= cxtype( 0, 1 ) * amp[0];

  // *** DIAGRAM 717 OF 1240 ***

  // Wavefunction(s) for diagram number 717
  // (none)

  // Amplitude(s) for diagram number 717
  FFV1_0( w[7], w[2], w[104], COUPs[1], &amp[0] );
#ifdef MGONGPU_SUPPORTS_MULTICHANNEL
  if( channelId == 717 ) allNumerators[0] += cxabs2( amp[0] );
  if( channelId != 0 ) allDenominators[0] += cxabs2( amp[0] );
#endif
  jamp[19] += amp[0];
  jamp[29] -= amp[0];
  jamp[43] += amp[0];
  jamp[97] -= amp[0];

  // *** DIAGRAM 718 OF 1240 ***

  // Wavefunction(s) for diagram number 718
  // (none)

  // Amplitude(s) for diagram number 718
  FFV1_0( w[78], w[96], w[5], COUPs[1], &amp[0] );
#ifdef MGONGPU_SUPPORTS_MULTICHANNEL
  if( channelId == 718 ) allNumerators[0] += cxabs2( amp[0] );
  if( channelId != 0 ) allDenominators[0] += cxabs2( amp[0] );
#endif
  jamp[22] += cxtype( 0, 1 ) * amp[0];
  jamp[100] -= cxtype( 0, 1 ) * amp[0];

  // *** DIAGRAM 719 OF 1240 ***

  // Wavefunction(s) for diagram number 719
  // (none)

  // Amplitude(s) for diagram number 719
  FFV1_0( w[7], w[96], w[1], COUPs[1], &amp[0] );
#ifdef MGONGPU_SUPPORTS_MULTICHANNEL
  if( channelId == 719 ) allNumerators[0] += cxabs2( amp[0] );
  if( channelId != 0 ) allDenominators[0] += cxabs2( amp[0] );
#endif
  jamp[19] += cxtype( 0, 1 ) * amp[0];
  jamp[97] -= cxtype( 0, 1 ) * amp[0];

  // *** DIAGRAM 720 OF 1240 ***

  // Wavefunction(s) for diagram number 720
  // (none)

  // Amplitude(s) for diagram number 720
  FFV1_0( w[78], w[2], w[86], COUPs[1], &amp[0] );
#ifdef MGONGPU_SUPPORTS_MULTICHANNEL
  if( channelId == 720 ) allNumerators[0] += cxabs2( amp[0] );
  if( channelId != 0 ) allDenominators[0] += cxabs2( amp[0] );
#endif
  jamp[22] += amp[0];
  jamp[76] -= amp[0];
  jamp[90] += amp[0];
  jamp[100] -= amp[0];

  // *** DIAGRAM 721 OF 1240 ***

  // Wavefunction(s) for diagram number 721
  // (none)

  // Amplitude(s) for diagram number 721
  VVV1_0( w[86], w[1], w[54], COUPs[0], &amp[0] );
#ifdef MGONGPU_SUPPORTS_MULTICHANNEL
  if( channelId == 721 ) allNumerators[0] += cxabs2( amp[0] );
  if( channelId != 0 ) allDenominators[0] += cxabs2( amp[0] );
#endif
  jamp[22] -= cxtype( 0, 1 ) * amp[0];
  jamp[29] += cxtype( 0, 1 ) * amp[0];
  jamp[37] -= cxtype( 0, 1 ) * amp[0];
  jamp[40] += cxtype( 0, 1 ) * amp[0];
  jamp[43] -= cxtype( 0, 1 ) * amp[0];
  jamp[76] += cxtype( 0, 1 ) * amp[0];
  jamp[90] -= cxtype( 0, 1 ) * amp[0];
  jamp[100] += cxtype( 0, 1 ) * amp[0];

  // *** DIAGRAM 722 OF 1240 ***

  // Wavefunction(s) for diagram number 722
  // (none)

  // Amplitude(s) for diagram number 722
  FFV1_0( w[46], w[2], w[109], COUPs[1], &amp[0] );
  jamp[19] -= cxtype( 0, 1 ) * amp[0];
  jamp[22] += cxtype( 0, 1 ) * amp[0];
  jamp[37] += cxtype( 0, 1 ) * amp[0];
  jamp[40] -= cxtype( 0, 1 ) * amp[0];
  jamp[79] -= cxtype( 0, 1 ) * amp[0];
  jamp[82] += cxtype( 0, 1 ) * amp[0];
  jamp[97] += cxtype( 0, 1 ) * amp[0];
  jamp[100] -= cxtype( 0, 1 ) * amp[0];
  FFV1_0( w[46], w[2], w[110], COUPs[1], &amp[0] );
  jamp[22] += cxtype( 0, 1 ) * amp[0];
  jamp[29] -= cxtype( 0, 1 ) * amp[0];
  jamp[37] += cxtype( 0, 1 ) * amp[0];
  jamp[40] -= cxtype( 0, 1 ) * amp[0];
  jamp[43] += cxtype( 0, 1 ) * amp[0];
  jamp[76] -= cxtype( 0, 1 ) * amp[0];
  jamp[90] += cxtype( 0, 1 ) * amp[0];
  jamp[100] -= cxtype( 0, 1 ) * amp[0];
  FFV1_0( w[46], w[2], w[111], COUPs[1], &amp[0] );
  jamp[19] += cxtype( 0, 1 ) * amp[0];
  jamp[29] -= cxtype( 0, 1 ) * amp[0];
  jamp[43] += cxtype( 0, 1 ) * amp[0];
  jamp[76] -= cxtype( 0, 1 ) * amp[0];
  jamp[79] += cxtype( 0, 1 ) * amp[0];
  jamp[82] -= cxtype( 0, 1 ) * amp[0];
  jamp[90] += cxtype( 0, 1 ) * amp[0];
  jamp[97] -= cxtype( 0, 1 ) * amp[0];

  // *** DIAGRAM 723 OF 1240 ***

  // Wavefunction(s) for diagram number 723
  // (none)

  // Amplitude(s) for diagram number 723
  VVV1_0( w[104], w[23], w[4], COUPs[0], &amp[0] );
#ifdef MGONGPU_SUPPORTS_MULTICHANNEL
  if( channelId == 723 ) allNumerators[0] += cxabs2( amp[0] );
  if( channelId != 0 ) allDenominators[0] += cxabs2( amp[0] );
#endif
  jamp[18] += cxtype( 0, 1 ) * amp[0];
  jamp[28] -= cxtype( 0, 1 ) * amp[0];
  jamp[42] += cxtype( 0, 1 ) * amp[0];
  jamp[52] -= cxtype( 0, 1 ) * amp[0];
  jamp[55] += cxtype( 0, 1 ) * amp[0];
  jamp[58] -= cxtype( 0, 1 ) * amp[0];
  jamp[66] += cxtype( 0, 1 ) * amp[0];
  jamp[96] -= cxtype( 0, 1 ) * amp[0];

  // *** DIAGRAM 724 OF 1240 ***

  // Wavefunction(s) for diagram number 724
  // (none)

  // Amplitude(s) for diagram number 724
  FFV1_0( w[25], w[2], w[104], COUPs[1], &amp[0] );
#ifdef MGONGPU_SUPPORTS_MULTICHANNEL
  if( channelId == 724 ) allNumerators[0] += cxabs2( amp[0] );
  if( channelId != 0 ) allDenominators[0] += cxabs2( amp[0] );
#endif
  jamp[18] += amp[0];
  jamp[28] -= amp[0];
  jamp[42] += amp[0];
  jamp[96] -= amp[0];

  // *** DIAGRAM 725 OF 1240 ***

  // Wavefunction(s) for diagram number 725
  // (none)

  // Amplitude(s) for diagram number 725
  FFV1_0( w[58], w[96], w[4], COUPs[1], &amp[0] );
#ifdef MGONGPU_SUPPORTS_MULTICHANNEL
  if( channelId == 725 ) allNumerators[0] += cxabs2( amp[0] );
  if( channelId != 0 ) allDenominators[0] += cxabs2( amp[0] );
#endif
  jamp[20] += cxtype( 0, 1 ) * amp[0];
  jamp[98] -= cxtype( 0, 1 ) * amp[0];

  // *** DIAGRAM 726 OF 1240 ***

  // Wavefunction(s) for diagram number 726
  // (none)

  // Amplitude(s) for diagram number 726
  FFV1_0( w[25], w[96], w[1], COUPs[1], &amp[0] );
#ifdef MGONGPU_SUPPORTS_MULTICHANNEL
  if( channelId == 726 ) allNumerators[0] += cxabs2( amp[0] );
  if( channelId != 0 ) allDenominators[0] += cxabs2( amp[0] );
#endif
  jamp[18] += cxtype( 0, 1 ) * amp[0];
  jamp[96] -= cxtype( 0, 1 ) * amp[0];

  // *** DIAGRAM 727 OF 1240 ***

  // Wavefunction(s) for diagram number 727
  // (none)

  // Amplitude(s) for diagram number 727
  FFV1_0( w[58], w[2], w[112], COUPs[1], &amp[0] );
#ifdef MGONGPU_SUPPORTS_MULTICHANNEL
  if( channelId == 727 ) allNumerators[0] += cxabs2( amp[0] );
  if( channelId != 0 ) allDenominators[0] += cxabs2( amp[0] );
#endif
  jamp[20] += amp[0];
  jamp[52] -= amp[0];
  jamp[66] += amp[0];
  jamp[98] -= amp[0];

  // *** DIAGRAM 728 OF 1240 ***

  // Wavefunction(s) for diagram number 728
  // (none)

  // Amplitude(s) for diagram number 728
  VVV1_0( w[112], w[1], w[23], COUPs[0], &amp[0] );
#ifdef MGONGPU_SUPPORTS_MULTICHANNEL
  if( channelId == 728 ) allNumerators[0] += cxabs2( amp[0] );
  if( channelId != 0 ) allDenominators[0] += cxabs2( amp[0] );
#endif
  jamp[20] -= cxtype( 0, 1 ) * amp[0];
  jamp[28] += cxtype( 0, 1 ) * amp[0];
  jamp[31] -= cxtype( 0, 1 ) * amp[0];
  jamp[34] += cxtype( 0, 1 ) * amp[0];
  jamp[42] -= cxtype( 0, 1 ) * amp[0];
  jamp[52] += cxtype( 0, 1 ) * amp[0];
  jamp[66] -= cxtype( 0, 1 ) * amp[0];
  jamp[98] += cxtype( 0, 1 ) * amp[0];

  // *** DIAGRAM 729 OF 1240 ***

  // Wavefunction(s) for diagram number 729
  // (none)

  // Amplitude(s) for diagram number 729
  FFV1_0( w[38], w[2], w[98], COUPs[1], &amp[0] );
  jamp[18] -= cxtype( 0, 1 ) * amp[0];
  jamp[20] += cxtype( 0, 1 ) * amp[0];
  jamp[31] += cxtype( 0, 1 ) * amp[0];
  jamp[34] -= cxtype( 0, 1 ) * amp[0];
  jamp[55] -= cxtype( 0, 1 ) * amp[0];
  jamp[58] += cxtype( 0, 1 ) * amp[0];
  jamp[96] += cxtype( 0, 1 ) * amp[0];
  jamp[98] -= cxtype( 0, 1 ) * amp[0];
  FFV1_0( w[38], w[2], w[62], COUPs[1], &amp[0] );
  jamp[20] += cxtype( 0, 1 ) * amp[0];
  jamp[28] -= cxtype( 0, 1 ) * amp[0];
  jamp[31] += cxtype( 0, 1 ) * amp[0];
  jamp[34] -= cxtype( 0, 1 ) * amp[0];
  jamp[42] += cxtype( 0, 1 ) * amp[0];
  jamp[52] -= cxtype( 0, 1 ) * amp[0];
  jamp[66] += cxtype( 0, 1 ) * amp[0];
  jamp[98] -= cxtype( 0, 1 ) * amp[0];
  FFV1_0( w[38], w[2], w[101], COUPs[1], &amp[0] );
  jamp[18] += cxtype( 0, 1 ) * amp[0];
  jamp[28] -= cxtype( 0, 1 ) * amp[0];
  jamp[42] += cxtype( 0, 1 ) * amp[0];
  jamp[52] -= cxtype( 0, 1 ) * amp[0];
  jamp[55] += cxtype( 0, 1 ) * amp[0];
  jamp[58] -= cxtype( 0, 1 ) * amp[0];
  jamp[66] += cxtype( 0, 1 ) * amp[0];
  jamp[96] -= cxtype( 0, 1 ) * amp[0];

  // *** DIAGRAM 730 OF 1240 ***

  // Wavefunction(s) for diagram number 730
  // (none)

  // Amplitude(s) for diagram number 730
  FFV1_0( w[3], w[17], w[104], COUPs[1], &amp[0] );
#ifdef MGONGPU_SUPPORTS_MULTICHANNEL
  if( channelId == 730 ) allNumerators[0] += cxabs2( amp[0] );
  if( channelId != 0 ) allDenominators[0] += cxabs2( amp[0] );
#endif
  jamp[61] -= cxtype( 0, 1 ) * amp[0];
  jamp[62] += cxtype( 0, 1 ) * amp[0];
  jamp[63] -= cxtype( 0, 1 ) * amp[0];
  jamp[64] += cxtype( 0, 1 ) * amp[0];
  jamp[85] += cxtype( 0, 1 ) * amp[0];
  jamp[86] -= cxtype( 0, 1 ) * amp[0];
  jamp[87] += cxtype( 0, 1 ) * amp[0];
  jamp[88] -= cxtype( 0, 1 ) * amp[0];

  // *** DIAGRAM 731 OF 1240 ***

  // Wavefunction(s) for diagram number 731
  // (none)

  // Amplitude(s) for diagram number 731
  FFV1_0( w[26], w[2], w[104], COUPs[1], &amp[0] );
#ifdef MGONGPU_SUPPORTS_MULTICHANNEL
  if( channelId == 731 ) allNumerators[0] += cxabs2( amp[0] );
  if( channelId != 0 ) allDenominators[0] += cxabs2( amp[0] );
#endif
  jamp[18] -= cxtype( 0, 1 ) * amp[0];
  jamp[19] += cxtype( 0, 1 ) * amp[0];
  jamp[28] += cxtype( 0, 1 ) * amp[0];
  jamp[29] -= cxtype( 0, 1 ) * amp[0];
  jamp[42] -= cxtype( 0, 1 ) * amp[0];
  jamp[43] += cxtype( 0, 1 ) * amp[0];
  jamp[96] += cxtype( 0, 1 ) * amp[0];
  jamp[97] -= cxtype( 0, 1 ) * amp[0];

  // *** DIAGRAM 732 OF 1240 ***

  // Wavefunction(s) for diagram number 732
  // (none)

  // Amplitude(s) for diagram number 732
  FFV1_0( w[3], w[96], w[59], COUPs[1], &amp[0] );
#ifdef MGONGPU_SUPPORTS_MULTICHANNEL
  if( channelId == 732 ) allNumerators[0] += cxabs2( amp[0] );
  if( channelId != 0 ) allDenominators[0] += cxabs2( amp[0] );
#endif
  jamp[18] -= cxtype( 0, 1 ) * amp[0];
  jamp[19] += cxtype( 0, 1 ) * amp[0];
  jamp[21] += cxtype( 0, 1 ) * amp[0];
  jamp[23] -= cxtype( 0, 1 ) * amp[0];
  jamp[96] += cxtype( 0, 1 ) * amp[0];
  jamp[97] -= cxtype( 0, 1 ) * amp[0];
  jamp[99] -= cxtype( 0, 1 ) * amp[0];
  jamp[101] += cxtype( 0, 1 ) * amp[0];

  // *** DIAGRAM 733 OF 1240 ***

  // Wavefunction(s) for diagram number 733
  // (none)

  // Amplitude(s) for diagram number 733
  FFV1_0( w[26], w[96], w[1], COUPs[1], &amp[0] );
#ifdef MGONGPU_SUPPORTS_MULTICHANNEL
  if( channelId == 733 ) allNumerators[0] += cxabs2( amp[0] );
  if( channelId != 0 ) allDenominators[0] += cxabs2( amp[0] );
#endif
  jamp[18] += amp[0];
  jamp[19] -= amp[0];
  jamp[96] -= amp[0];
  jamp[97] += amp[0];

  // *** DIAGRAM 734 OF 1240 ***

  // Wavefunction(s) for diagram number 734
  // (none)

  // Amplitude(s) for diagram number 734
  FFV1_0( w[99], w[2], w[59], COUPs[1], &amp[0] );
#ifdef MGONGPU_SUPPORTS_MULTICHANNEL
  if( channelId == 734 ) allNumerators[0] += cxabs2( amp[0] );
  if( channelId != 0 ) allDenominators[0] += cxabs2( amp[0] );
#endif
  jamp[32] -= cxtype( 0, 1 ) * amp[0];
  jamp[33] += cxtype( 0, 1 ) * amp[0];
  jamp[38] += cxtype( 0, 1 ) * amp[0];
  jamp[39] -= cxtype( 0, 1 ) * amp[0];
  jamp[62] += cxtype( 0, 1 ) * amp[0];
  jamp[63] -= cxtype( 0, 1 ) * amp[0];
  jamp[86] -= cxtype( 0, 1 ) * amp[0];
  jamp[87] += cxtype( 0, 1 ) * amp[0];

  // *** DIAGRAM 735 OF 1240 ***

  // Wavefunction(s) for diagram number 735
  // (none)

  // Amplitude(s) for diagram number 735
  FFV1_0( w[99], w[17], w[1], COUPs[1], &amp[0] );
#ifdef MGONGPU_SUPPORTS_MULTICHANNEL
  if( channelId == 735 ) allNumerators[0] += cxabs2( amp[0] );
  if( channelId != 0 ) allDenominators[0] += cxabs2( amp[0] );
#endif
  jamp[62] += amp[0];
  jamp[63] -= amp[0];
  jamp[86] -= amp[0];
  jamp[87] += amp[0];

  // *** DIAGRAM 736 OF 1240 ***

  // Wavefunction(s) for diagram number 736
  // (none)

  // Amplitude(s) for diagram number 736
  FFV1_0( w[3], w[96], w[73], COUPs[1], &amp[0] );
  jamp[18] -= cxtype( 0, 1 ) * amp[0];
  jamp[19] += cxtype( 0, 1 ) * amp[0];
  jamp[21] += cxtype( 0, 1 ) * amp[0];
  jamp[23] -= cxtype( 0, 1 ) * amp[0];
  jamp[96] += cxtype( 0, 1 ) * amp[0];
  jamp[97] -= cxtype( 0, 1 ) * amp[0];
  jamp[99] -= cxtype( 0, 1 ) * amp[0];
  jamp[101] += cxtype( 0, 1 ) * amp[0];
  FFV1_0( w[3], w[96], w[79], COUPs[1], &amp[0] );
  jamp[19] += cxtype( 0, 1 ) * amp[0];
  jamp[20] -= cxtype( 0, 1 ) * amp[0];
  jamp[21] += cxtype( 0, 1 ) * amp[0];
  jamp[22] -= cxtype( 0, 1 ) * amp[0];
  jamp[97] -= cxtype( 0, 1 ) * amp[0];
  jamp[98] += cxtype( 0, 1 ) * amp[0];
  jamp[99] -= cxtype( 0, 1 ) * amp[0];
  jamp[100] += cxtype( 0, 1 ) * amp[0];
  FFV1_0( w[3], w[96], w[80], COUPs[1], &amp[0] );
  jamp[18] += cxtype( 0, 1 ) * amp[0];
  jamp[20] -= cxtype( 0, 1 ) * amp[0];
  jamp[22] -= cxtype( 0, 1 ) * amp[0];
  jamp[23] += cxtype( 0, 1 ) * amp[0];
  jamp[96] -= cxtype( 0, 1 ) * amp[0];
  jamp[98] += cxtype( 0, 1 ) * amp[0];
  jamp[100] += cxtype( 0, 1 ) * amp[0];
  jamp[101] -= cxtype( 0, 1 ) * amp[0];

  // *** DIAGRAM 737 OF 1240 ***

  // Wavefunction(s) for diagram number 737
  // (none)

  // Amplitude(s) for diagram number 737
  FFV1_0( w[99], w[2], w[73], COUPs[1], &amp[0] );
  jamp[32] -= cxtype( 0, 1 ) * amp[0];
  jamp[33] += cxtype( 0, 1 ) * amp[0];
  jamp[38] += cxtype( 0, 1 ) * amp[0];
  jamp[39] -= cxtype( 0, 1 ) * amp[0];
  jamp[62] += cxtype( 0, 1 ) * amp[0];
  jamp[63] -= cxtype( 0, 1 ) * amp[0];
  jamp[86] -= cxtype( 0, 1 ) * amp[0];
  jamp[87] += cxtype( 0, 1 ) * amp[0];
  FFV1_0( w[99], w[2], w[79], COUPs[1], &amp[0] );
  jamp[38] += cxtype( 0, 1 ) * amp[0];
  jamp[39] -= cxtype( 0, 1 ) * amp[0];
  jamp[56] -= cxtype( 0, 1 ) * amp[0];
  jamp[57] += cxtype( 0, 1 ) * amp[0];
  jamp[62] += cxtype( 0, 1 ) * amp[0];
  jamp[63] -= cxtype( 0, 1 ) * amp[0];
  jamp[80] -= cxtype( 0, 1 ) * amp[0];
  jamp[81] += cxtype( 0, 1 ) * amp[0];
  FFV1_0( w[99], w[2], w[80], COUPs[1], &amp[0] );
  jamp[32] += cxtype( 0, 1 ) * amp[0];
  jamp[33] -= cxtype( 0, 1 ) * amp[0];
  jamp[56] -= cxtype( 0, 1 ) * amp[0];
  jamp[57] += cxtype( 0, 1 ) * amp[0];
  jamp[80] -= cxtype( 0, 1 ) * amp[0];
  jamp[81] += cxtype( 0, 1 ) * amp[0];
  jamp[86] += cxtype( 0, 1 ) * amp[0];
  jamp[87] -= cxtype( 0, 1 ) * amp[0];

  // *** DIAGRAM 738 OF 1240 ***

  // Wavefunction(s) for diagram number 738
  // (none)

  // Amplitude(s) for diagram number 738
  VVV1_0( w[92], w[73], w[8], COUPs[0], &amp[0] );
  jamp[18] -= amp[0];
  jamp[19] += amp[0];
  jamp[21] += amp[0];
  jamp[23] -= amp[0];
  jamp[32] += amp[0];
  jamp[33] -= amp[0];
  jamp[38] -= amp[0];
  jamp[39] += amp[0];
  jamp[62] -= amp[0];
  jamp[63] += amp[0];
  jamp[86] += amp[0];
  jamp[87] -= amp[0];
  jamp[96] += amp[0];
  jamp[97] -= amp[0];
  jamp[99] -= amp[0];
  jamp[101] += amp[0];
  VVV1_0( w[92], w[79], w[8], COUPs[0], &amp[0] );
  jamp[19] += amp[0];
  jamp[20] -= amp[0];
  jamp[21] += amp[0];
  jamp[22] -= amp[0];
  jamp[38] -= amp[0];
  jamp[39] += amp[0];
  jamp[56] += amp[0];
  jamp[57] -= amp[0];
  jamp[62] -= amp[0];
  jamp[63] += amp[0];
  jamp[80] += amp[0];
  jamp[81] -= amp[0];
  jamp[97] -= amp[0];
  jamp[98] += amp[0];
  jamp[99] -= amp[0];
  jamp[100] += amp[0];
  VVV1_0( w[92], w[80], w[8], COUPs[0], &amp[0] );
  jamp[18] += amp[0];
  jamp[20] -= amp[0];
  jamp[22] -= amp[0];
  jamp[23] += amp[0];
  jamp[32] -= amp[0];
  jamp[33] += amp[0];
  jamp[56] += amp[0];
  jamp[57] -= amp[0];
  jamp[80] += amp[0];
  jamp[81] -= amp[0];
  jamp[86] -= amp[0];
  jamp[87] += amp[0];
  jamp[96] -= amp[0];
  jamp[98] += amp[0];
  jamp[100] += amp[0];
  jamp[101] -= amp[0];

  // *** DIAGRAM 739 OF 1240 ***

  // Wavefunction(s) for diagram number 739
  FFV1_1( w[77], w[0], COUPs[1], cIPD[0], cIPD[1], w[92] );

  // Amplitude(s) for diagram number 739
  FFV1_0( w[7], w[92], w[6], COUPs[1], &amp[0] );
#ifdef MGONGPU_SUPPORTS_MULTICHANNEL
  if( channelId == 739 ) allNumerators[0] += cxabs2( amp[0] );
  if( channelId != 0 ) allDenominators[0] += cxabs2( amp[0] );
#endif
  jamp[29] -= amp[0];

  // *** DIAGRAM 740 OF 1240 ***

  // Wavefunction(s) for diagram number 740
  // (none)

  // Amplitude(s) for diagram number 740
  FFV1_0( w[53], w[92], w[5], COUPs[1], &amp[0] );
#ifdef MGONGPU_SUPPORTS_MULTICHANNEL
  if( channelId == 740 ) allNumerators[0] += cxabs2( amp[0] );
  if( channelId != 0 ) allDenominators[0] += cxabs2( amp[0] );
#endif
  jamp[27] -= amp[0];

  // *** DIAGRAM 741 OF 1240 ***

  // Wavefunction(s) for diagram number 741
  FFV1_2( w[46], w[0], COUPs[1], cIPD[0], cIPD[1], w[99] );

  // Amplitude(s) for diagram number 741
  FFV1_0( w[99], w[9], w[6], COUPs[1], &amp[0] );
#ifdef MGONGPU_SUPPORTS_MULTICHANNEL
  if( channelId == 741 ) allNumerators[0] += cxabs2( amp[0] );
  if( channelId != 0 ) allDenominators[0] += cxabs2( amp[0] );
#endif
  jamp[40] -= amp[0];

  // *** DIAGRAM 742 OF 1240 ***

  // Wavefunction(s) for diagram number 742
  // (none)

  // Amplitude(s) for diagram number 742
  FFV1_0( w[99], w[85], w[5], COUPs[1], &amp[0] );
#ifdef MGONGPU_SUPPORTS_MULTICHANNEL
  if( channelId == 742 ) allNumerators[0] += cxabs2( amp[0] );
  if( channelId != 0 ) allDenominators[0] += cxabs2( amp[0] );
#endif
  jamp[46] -= amp[0];

  // *** DIAGRAM 743 OF 1240 ***

  // Wavefunction(s) for diagram number 743
  // (none)

  // Amplitude(s) for diagram number 743
  FFV1_0( w[53], w[9], w[0], COUPs[1], &amp[0] );
#ifdef MGONGPU_SUPPORTS_MULTICHANNEL
  if( channelId == 743 ) allNumerators[0] += cxabs2( amp[0] );
  if( channelId != 0 ) allDenominators[0] += cxabs2( amp[0] );
#endif
  jamp[37] -= amp[0];

  // *** DIAGRAM 744 OF 1240 ***

  // Wavefunction(s) for diagram number 744
  // (none)

  // Amplitude(s) for diagram number 744
  FFV1_0( w[7], w[85], w[0], COUPs[1], &amp[0] );
#ifdef MGONGPU_SUPPORTS_MULTICHANNEL
  if( channelId == 744 ) allNumerators[0] += cxabs2( amp[0] );
  if( channelId != 0 ) allDenominators[0] += cxabs2( amp[0] );
#endif
  jamp[43] -= amp[0];

  // *** DIAGRAM 745 OF 1240 ***

  // Wavefunction(s) for diagram number 745
  // (none)

  // Amplitude(s) for diagram number 745
  FFV1_0( w[46], w[92], w[29], COUPs[1], &amp[0] );
#ifdef MGONGPU_SUPPORTS_MULTICHANNEL
  if( channelId == 745 ) allNumerators[0] += cxabs2( amp[0] );
  if( channelId != 0 ) allDenominators[0] += cxabs2( amp[0] );
#endif
  jamp[27] += cxtype( 0, 1 ) * amp[0];
  jamp[29] -= cxtype( 0, 1 ) * amp[0];

  // *** DIAGRAM 746 OF 1240 ***

  // Wavefunction(s) for diagram number 746
  // (none)

  // Amplitude(s) for diagram number 746
  FFV1_0( w[99], w[77], w[29], COUPs[1], &amp[0] );
#ifdef MGONGPU_SUPPORTS_MULTICHANNEL
  if( channelId == 746 ) allNumerators[0] += cxabs2( amp[0] );
  if( channelId != 0 ) allDenominators[0] += cxabs2( amp[0] );
#endif
  jamp[40] += cxtype( 0, 1 ) * amp[0];
  jamp[46] -= cxtype( 0, 1 ) * amp[0];

  // *** DIAGRAM 747 OF 1240 ***

  // Wavefunction(s) for diagram number 747
  VVV1P0_1( w[0], w[29], COUPs[0], 0., 0., w[96] );

  // Amplitude(s) for diagram number 747
  FFV1_0( w[46], w[77], w[96], COUPs[1], &amp[0] );
#ifdef MGONGPU_SUPPORTS_MULTICHANNEL
  if( channelId == 747 ) allNumerators[0] += cxabs2( amp[0] );
  if( channelId != 0 ) allDenominators[0] += cxabs2( amp[0] );
#endif
  jamp[27] += amp[0];
  jamp[29] -= amp[0];
  jamp[40] -= amp[0];
  jamp[46] += amp[0];

  // *** DIAGRAM 748 OF 1240 ***

  // Wavefunction(s) for diagram number 748
  // (none)

  // Amplitude(s) for diagram number 748
  FFV1_0( w[25], w[92], w[6], COUPs[1], &amp[0] );
#ifdef MGONGPU_SUPPORTS_MULTICHANNEL
  if( channelId == 748 ) allNumerators[0] += cxabs2( amp[0] );
  if( channelId != 0 ) allDenominators[0] += cxabs2( amp[0] );
#endif
  jamp[28] -= amp[0];

  // *** DIAGRAM 749 OF 1240 ***

  // Wavefunction(s) for diagram number 749
  // (none)

  // Amplitude(s) for diagram number 749
  FFV1_0( w[48], w[92], w[4], COUPs[1], &amp[0] );
#ifdef MGONGPU_SUPPORTS_MULTICHANNEL
  if( channelId == 749 ) allNumerators[0] += cxabs2( amp[0] );
  if( channelId != 0 ) allDenominators[0] += cxabs2( amp[0] );
#endif
  jamp[25] -= amp[0];

  // *** DIAGRAM 750 OF 1240 ***

  // Wavefunction(s) for diagram number 750
  FFV1_2( w[38], w[0], COUPs[1], cIPD[0], cIPD[1], w[104] );

  // Amplitude(s) for diagram number 750
  FFV1_0( w[104], w[87], w[6], COUPs[1], &amp[0] );
#ifdef MGONGPU_SUPPORTS_MULTICHANNEL
  if( channelId == 750 ) allNumerators[0] += cxabs2( amp[0] );
  if( channelId != 0 ) allDenominators[0] += cxabs2( amp[0] );
#endif
  jamp[34] -= amp[0];

  // *** DIAGRAM 751 OF 1240 ***

  // Wavefunction(s) for diagram number 751
  // (none)

  // Amplitude(s) for diagram number 751
  FFV1_0( w[104], w[85], w[4], COUPs[1], &amp[0] );
#ifdef MGONGPU_SUPPORTS_MULTICHANNEL
  if( channelId == 751 ) allNumerators[0] += cxabs2( amp[0] );
  if( channelId != 0 ) allDenominators[0] += cxabs2( amp[0] );
#endif
  jamp[44] -= amp[0];

  // *** DIAGRAM 752 OF 1240 ***

  // Wavefunction(s) for diagram number 752
  // (none)

  // Amplitude(s) for diagram number 752
  FFV1_0( w[48], w[87], w[0], COUPs[1], &amp[0] );
#ifdef MGONGPU_SUPPORTS_MULTICHANNEL
  if( channelId == 752 ) allNumerators[0] += cxabs2( amp[0] );
  if( channelId != 0 ) allDenominators[0] += cxabs2( amp[0] );
#endif
  jamp[31] -= amp[0];

  // *** DIAGRAM 753 OF 1240 ***

  // Wavefunction(s) for diagram number 753
  // (none)

  // Amplitude(s) for diagram number 753
  FFV1_0( w[25], w[85], w[0], COUPs[1], &amp[0] );
#ifdef MGONGPU_SUPPORTS_MULTICHANNEL
  if( channelId == 753 ) allNumerators[0] += cxabs2( amp[0] );
  if( channelId != 0 ) allDenominators[0] += cxabs2( amp[0] );
#endif
  jamp[42] -= amp[0];

  // *** DIAGRAM 754 OF 1240 ***

  // Wavefunction(s) for diagram number 754
  // (none)

  // Amplitude(s) for diagram number 754
  FFV1_0( w[38], w[92], w[27], COUPs[1], &amp[0] );
#ifdef MGONGPU_SUPPORTS_MULTICHANNEL
  if( channelId == 754 ) allNumerators[0] += cxabs2( amp[0] );
  if( channelId != 0 ) allDenominators[0] += cxabs2( amp[0] );
#endif
  jamp[25] += cxtype( 0, 1 ) * amp[0];
  jamp[28] -= cxtype( 0, 1 ) * amp[0];

  // *** DIAGRAM 755 OF 1240 ***

  // Wavefunction(s) for diagram number 755
  // (none)

  // Amplitude(s) for diagram number 755
  FFV1_0( w[104], w[77], w[27], COUPs[1], &amp[0] );
#ifdef MGONGPU_SUPPORTS_MULTICHANNEL
  if( channelId == 755 ) allNumerators[0] += cxabs2( amp[0] );
  if( channelId != 0 ) allDenominators[0] += cxabs2( amp[0] );
#endif
  jamp[34] += cxtype( 0, 1 ) * amp[0];
  jamp[44] -= cxtype( 0, 1 ) * amp[0];

  // *** DIAGRAM 756 OF 1240 ***

  // Wavefunction(s) for diagram number 756
  VVV1P0_1( w[0], w[27], COUPs[0], 0., 0., w[101] );

  // Amplitude(s) for diagram number 756
  FFV1_0( w[38], w[77], w[101], COUPs[1], &amp[0] );
#ifdef MGONGPU_SUPPORTS_MULTICHANNEL
  if( channelId == 756 ) allNumerators[0] += cxabs2( amp[0] );
  if( channelId != 0 ) allDenominators[0] += cxabs2( amp[0] );
#endif
  jamp[25] += amp[0];
  jamp[28] -= amp[0];
  jamp[34] -= amp[0];
  jamp[44] += amp[0];

  // *** DIAGRAM 757 OF 1240 ***

  // Wavefunction(s) for diagram number 757
  // (none)

  // Amplitude(s) for diagram number 757
  FFV1_0( w[28], w[92], w[5], COUPs[1], &amp[0] );
#ifdef MGONGPU_SUPPORTS_MULTICHANNEL
  if( channelId == 757 ) allNumerators[0] += cxabs2( amp[0] );
  if( channelId != 0 ) allDenominators[0] += cxabs2( amp[0] );
#endif
  jamp[26] -= amp[0];

  // *** DIAGRAM 758 OF 1240 ***

  // Wavefunction(s) for diagram number 758
  // (none)

  // Amplitude(s) for diagram number 758
  FFV1_0( w[40], w[92], w[4], COUPs[1], &amp[0] );
#ifdef MGONGPU_SUPPORTS_MULTICHANNEL
  if( channelId == 758 ) allNumerators[0] += cxabs2( amp[0] );
  if( channelId != 0 ) allDenominators[0] += cxabs2( amp[0] );
#endif
  jamp[24] -= amp[0];

  // *** DIAGRAM 759 OF 1240 ***

  // Wavefunction(s) for diagram number 759
  FFV1_2( w[41], w[0], COUPs[1], cIPD[0], cIPD[1], w[62] );

  // Amplitude(s) for diagram number 759
  FFV1_0( w[62], w[87], w[5], COUPs[1], &amp[0] );
#ifdef MGONGPU_SUPPORTS_MULTICHANNEL
  if( channelId == 759 ) allNumerators[0] += cxabs2( amp[0] );
  if( channelId != 0 ) allDenominators[0] += cxabs2( amp[0] );
#endif
  jamp[32] -= amp[0];

  // *** DIAGRAM 760 OF 1240 ***

  // Wavefunction(s) for diagram number 760
  // (none)

  // Amplitude(s) for diagram number 760
  FFV1_0( w[62], w[9], w[4], COUPs[1], &amp[0] );
#ifdef MGONGPU_SUPPORTS_MULTICHANNEL
  if( channelId == 760 ) allNumerators[0] += cxabs2( amp[0] );
  if( channelId != 0 ) allDenominators[0] += cxabs2( amp[0] );
#endif
  jamp[38] -= amp[0];

  // *** DIAGRAM 761 OF 1240 ***

  // Wavefunction(s) for diagram number 761
  // (none)

  // Amplitude(s) for diagram number 761
  FFV1_0( w[40], w[87], w[0], COUPs[1], &amp[0] );
#ifdef MGONGPU_SUPPORTS_MULTICHANNEL
  if( channelId == 761 ) allNumerators[0] += cxabs2( amp[0] );
  if( channelId != 0 ) allDenominators[0] += cxabs2( amp[0] );
#endif
  jamp[30] -= amp[0];

  // *** DIAGRAM 762 OF 1240 ***

  // Wavefunction(s) for diagram number 762
  // (none)

  // Amplitude(s) for diagram number 762
  FFV1_0( w[28], w[9], w[0], COUPs[1], &amp[0] );
#ifdef MGONGPU_SUPPORTS_MULTICHANNEL
  if( channelId == 762 ) allNumerators[0] += cxabs2( amp[0] );
  if( channelId != 0 ) allDenominators[0] += cxabs2( amp[0] );
#endif
  jamp[36] -= amp[0];

  // *** DIAGRAM 763 OF 1240 ***

  // Wavefunction(s) for diagram number 763
  // (none)

  // Amplitude(s) for diagram number 763
  FFV1_0( w[41], w[92], w[24], COUPs[1], &amp[0] );
#ifdef MGONGPU_SUPPORTS_MULTICHANNEL
  if( channelId == 763 ) allNumerators[0] += cxabs2( amp[0] );
  if( channelId != 0 ) allDenominators[0] += cxabs2( amp[0] );
#endif
  jamp[24] += cxtype( 0, 1 ) * amp[0];
  jamp[26] -= cxtype( 0, 1 ) * amp[0];

  // *** DIAGRAM 764 OF 1240 ***

  // Wavefunction(s) for diagram number 764
  // (none)

  // Amplitude(s) for diagram number 764
  FFV1_0( w[62], w[77], w[24], COUPs[1], &amp[0] );
#ifdef MGONGPU_SUPPORTS_MULTICHANNEL
  if( channelId == 764 ) allNumerators[0] += cxabs2( amp[0] );
  if( channelId != 0 ) allDenominators[0] += cxabs2( amp[0] );
#endif
  jamp[32] += cxtype( 0, 1 ) * amp[0];
  jamp[38] -= cxtype( 0, 1 ) * amp[0];

  // *** DIAGRAM 765 OF 1240 ***

  // Wavefunction(s) for diagram number 765
  VVV1P0_1( w[0], w[24], COUPs[0], 0., 0., w[98] );

  // Amplitude(s) for diagram number 765
  FFV1_0( w[41], w[77], w[98], COUPs[1], &amp[0] );
#ifdef MGONGPU_SUPPORTS_MULTICHANNEL
  if( channelId == 765 ) allNumerators[0] += cxabs2( amp[0] );
  if( channelId != 0 ) allDenominators[0] += cxabs2( amp[0] );
#endif
  jamp[24] += amp[0];
  jamp[26] -= amp[0];
  jamp[32] -= amp[0];
  jamp[38] += amp[0];

  // *** DIAGRAM 766 OF 1240 ***

  // Wavefunction(s) for diagram number 766
  // (none)

  // Amplitude(s) for diagram number 766
  FFV1_0( w[26], w[92], w[6], COUPs[1], &amp[0] );
#ifdef MGONGPU_SUPPORTS_MULTICHANNEL
  if( channelId == 766 ) allNumerators[0] += cxabs2( amp[0] );
  if( channelId != 0 ) allDenominators[0] += cxabs2( amp[0] );
#endif
  jamp[28] += cxtype( 0, 1 ) * amp[0];
  jamp[29] -= cxtype( 0, 1 ) * amp[0];

  // *** DIAGRAM 767 OF 1240 ***

  // Wavefunction(s) for diagram number 767
  // (none)

  // Amplitude(s) for diagram number 767
  FFV1_0( w[3], w[92], w[42], COUPs[1], &amp[0] );
#ifdef MGONGPU_SUPPORTS_MULTICHANNEL
  if( channelId == 767 ) allNumerators[0] += cxabs2( amp[0] );
  if( channelId != 0 ) allDenominators[0] += cxabs2( amp[0] );
#endif
  jamp[24] += amp[0];
  jamp[26] -= amp[0];
  jamp[28] -= amp[0];
  jamp[29] += amp[0];

  // *** DIAGRAM 768 OF 1240 ***

  // Wavefunction(s) for diagram number 768
  // (none)

  // Amplitude(s) for diagram number 768
  VVV1_0( w[98], w[34], w[6], COUPs[0], &amp[0] );
#ifdef MGONGPU_SUPPORTS_MULTICHANNEL
  if( channelId == 768 ) allNumerators[0] += cxabs2( amp[0] );
  if( channelId != 0 ) allDenominators[0] += cxabs2( amp[0] );
#endif
  jamp[24] += cxtype( 0, 1 ) * amp[0];
  jamp[26] -= cxtype( 0, 1 ) * amp[0];
  jamp[32] -= cxtype( 0, 1 ) * amp[0];
  jamp[38] += cxtype( 0, 1 ) * amp[0];
  jamp[42] -= cxtype( 0, 1 ) * amp[0];
  jamp[43] += cxtype( 0, 1 ) * amp[0];
  jamp[45] += cxtype( 0, 1 ) * amp[0];
  jamp[47] -= cxtype( 0, 1 ) * amp[0];

  // *** DIAGRAM 769 OF 1240 ***

  // Wavefunction(s) for diagram number 769
  // (none)

  // Amplitude(s) for diagram number 769
  FFV1_0( w[3], w[85], w[98], COUPs[1], &amp[0] );
#ifdef MGONGPU_SUPPORTS_MULTICHANNEL
  if( channelId == 769 ) allNumerators[0] += cxabs2( amp[0] );
  if( channelId != 0 ) allDenominators[0] += cxabs2( amp[0] );
#endif
  jamp[42] += amp[0];
  jamp[43] -= amp[0];
  jamp[45] -= amp[0];
  jamp[47] += amp[0];

  // *** DIAGRAM 770 OF 1240 ***

  // Wavefunction(s) for diagram number 770
  // (none)

  // Amplitude(s) for diagram number 770
  VVV1_0( w[0], w[34], w[42], COUPs[0], &amp[0] );
#ifdef MGONGPU_SUPPORTS_MULTICHANNEL
  if( channelId == 770 ) allNumerators[0] += cxabs2( amp[0] );
  if( channelId != 0 ) allDenominators[0] += cxabs2( amp[0] );
#endif
  jamp[24] += cxtype( 0, 1 ) * amp[0];
  jamp[26] -= cxtype( 0, 1 ) * amp[0];
  jamp[28] -= cxtype( 0, 1 ) * amp[0];
  jamp[29] += cxtype( 0, 1 ) * amp[0];
  jamp[33] -= cxtype( 0, 1 ) * amp[0];
  jamp[39] += cxtype( 0, 1 ) * amp[0];
  jamp[45] += cxtype( 0, 1 ) * amp[0];
  jamp[47] -= cxtype( 0, 1 ) * amp[0];

  // *** DIAGRAM 771 OF 1240 ***

  // Wavefunction(s) for diagram number 771
  // (none)

  // Amplitude(s) for diagram number 771
  FFV1_0( w[26], w[85], w[0], COUPs[1], &amp[0] );
#ifdef MGONGPU_SUPPORTS_MULTICHANNEL
  if( channelId == 771 ) allNumerators[0] += cxabs2( amp[0] );
  if( channelId != 0 ) allDenominators[0] += cxabs2( amp[0] );
#endif
  jamp[42] += cxtype( 0, 1 ) * amp[0];
  jamp[43] -= cxtype( 0, 1 ) * amp[0];

  // *** DIAGRAM 772 OF 1240 ***

  // Wavefunction(s) for diagram number 772
  VVVV1P0_1( w[0], w[24], w[6], COUPs[2], 0., 0., w[85] );
  VVVV3P0_1( w[0], w[24], w[6], COUPs[2], 0., 0., w[112] );
  VVVV4P0_1( w[0], w[24], w[6], COUPs[2], 0., 0., w[111] );

  // Amplitude(s) for diagram number 772
  FFV1_0( w[3], w[77], w[85], COUPs[1], &amp[0] );
  jamp[24] -= cxtype( 0, 1 ) * amp[0];
  jamp[26] += cxtype( 0, 1 ) * amp[0];
  jamp[28] += cxtype( 0, 1 ) * amp[0];
  jamp[29] -= cxtype( 0, 1 ) * amp[0];
  jamp[33] += cxtype( 0, 1 ) * amp[0];
  jamp[39] -= cxtype( 0, 1 ) * amp[0];
  jamp[45] -= cxtype( 0, 1 ) * amp[0];
  jamp[47] += cxtype( 0, 1 ) * amp[0];
  FFV1_0( w[3], w[77], w[112], COUPs[1], &amp[0] );
  jamp[28] += cxtype( 0, 1 ) * amp[0];
  jamp[29] -= cxtype( 0, 1 ) * amp[0];
  jamp[32] -= cxtype( 0, 1 ) * amp[0];
  jamp[33] += cxtype( 0, 1 ) * amp[0];
  jamp[38] += cxtype( 0, 1 ) * amp[0];
  jamp[39] -= cxtype( 0, 1 ) * amp[0];
  jamp[42] -= cxtype( 0, 1 ) * amp[0];
  jamp[43] += cxtype( 0, 1 ) * amp[0];
  FFV1_0( w[3], w[77], w[111], COUPs[1], &amp[0] );
  jamp[24] += cxtype( 0, 1 ) * amp[0];
  jamp[26] -= cxtype( 0, 1 ) * amp[0];
  jamp[32] -= cxtype( 0, 1 ) * amp[0];
  jamp[38] += cxtype( 0, 1 ) * amp[0];
  jamp[42] -= cxtype( 0, 1 ) * amp[0];
  jamp[43] += cxtype( 0, 1 ) * amp[0];
  jamp[45] += cxtype( 0, 1 ) * amp[0];
  jamp[47] -= cxtype( 0, 1 ) * amp[0];

  // *** DIAGRAM 773 OF 1240 ***

  // Wavefunction(s) for diagram number 773
  // (none)

  // Amplitude(s) for diagram number 773
  FFV1_0( w[14], w[92], w[5], COUPs[1], &amp[0] );
#ifdef MGONGPU_SUPPORTS_MULTICHANNEL
  if( channelId == 773 ) allNumerators[0] += cxabs2( amp[0] );
  if( channelId != 0 ) allDenominators[0] += cxabs2( amp[0] );
#endif
  jamp[26] += cxtype( 0, 1 ) * amp[0];
  jamp[27] -= cxtype( 0, 1 ) * amp[0];

  // *** DIAGRAM 774 OF 1240 ***

  // Wavefunction(s) for diagram number 774
  // (none)

  // Amplitude(s) for diagram number 774
  FFV1_0( w[3], w[92], w[16], COUPs[1], &amp[0] );
#ifdef MGONGPU_SUPPORTS_MULTICHANNEL
  if( channelId == 774 ) allNumerators[0] += cxabs2( amp[0] );
  if( channelId != 0 ) allDenominators[0] += cxabs2( amp[0] );
#endif
  jamp[25] += amp[0];
  jamp[26] -= amp[0];
  jamp[27] += amp[0];
  jamp[28] -= amp[0];

  // *** DIAGRAM 775 OF 1240 ***

  // Wavefunction(s) for diagram number 775
  // (none)

  // Amplitude(s) for diagram number 775
  VVV1_0( w[101], w[34], w[5], COUPs[0], &amp[0] );
#ifdef MGONGPU_SUPPORTS_MULTICHANNEL
  if( channelId == 775 ) allNumerators[0] += cxabs2( amp[0] );
  if( channelId != 0 ) allDenominators[0] += cxabs2( amp[0] );
#endif
  jamp[25] += cxtype( 0, 1 ) * amp[0];
  jamp[28] -= cxtype( 0, 1 ) * amp[0];
  jamp[34] -= cxtype( 0, 1 ) * amp[0];
  jamp[36] -= cxtype( 0, 1 ) * amp[0];
  jamp[37] += cxtype( 0, 1 ) * amp[0];
  jamp[39] += cxtype( 0, 1 ) * amp[0];
  jamp[41] -= cxtype( 0, 1 ) * amp[0];
  jamp[44] += cxtype( 0, 1 ) * amp[0];

  // *** DIAGRAM 776 OF 1240 ***

  // Wavefunction(s) for diagram number 776
  // (none)

  // Amplitude(s) for diagram number 776
  FFV1_0( w[3], w[9], w[101], COUPs[1], &amp[0] );
#ifdef MGONGPU_SUPPORTS_MULTICHANNEL
  if( channelId == 776 ) allNumerators[0] += cxabs2( amp[0] );
  if( channelId != 0 ) allDenominators[0] += cxabs2( amp[0] );
#endif
  jamp[36] += amp[0];
  jamp[37] -= amp[0];
  jamp[39] -= amp[0];
  jamp[41] += amp[0];

  // *** DIAGRAM 777 OF 1240 ***

  // Wavefunction(s) for diagram number 777
  // (none)

  // Amplitude(s) for diagram number 777
  VVV1_0( w[0], w[34], w[16], COUPs[0], &amp[0] );
#ifdef MGONGPU_SUPPORTS_MULTICHANNEL
  if( channelId == 777 ) allNumerators[0] += cxabs2( amp[0] );
  if( channelId != 0 ) allDenominators[0] += cxabs2( amp[0] );
#endif
  jamp[25] += cxtype( 0, 1 ) * amp[0];
  jamp[26] -= cxtype( 0, 1 ) * amp[0];
  jamp[27] += cxtype( 0, 1 ) * amp[0];
  jamp[28] -= cxtype( 0, 1 ) * amp[0];
  jamp[35] -= cxtype( 0, 1 ) * amp[0];
  jamp[39] += cxtype( 0, 1 ) * amp[0];
  jamp[41] -= cxtype( 0, 1 ) * amp[0];
  jamp[45] += cxtype( 0, 1 ) * amp[0];

  // *** DIAGRAM 778 OF 1240 ***

  // Wavefunction(s) for diagram number 778
  // (none)

  // Amplitude(s) for diagram number 778
  FFV1_0( w[14], w[9], w[0], COUPs[1], &amp[0] );
#ifdef MGONGPU_SUPPORTS_MULTICHANNEL
  if( channelId == 778 ) allNumerators[0] += cxabs2( amp[0] );
  if( channelId != 0 ) allDenominators[0] += cxabs2( amp[0] );
#endif
  jamp[36] += cxtype( 0, 1 ) * amp[0];
  jamp[37] -= cxtype( 0, 1 ) * amp[0];

  // *** DIAGRAM 779 OF 1240 ***

  // Wavefunction(s) for diagram number 779
  VVVV1P0_1( w[0], w[27], w[5], COUPs[2], 0., 0., w[9] );
  VVVV3P0_1( w[0], w[27], w[5], COUPs[2], 0., 0., w[110] );
  VVVV4P0_1( w[0], w[27], w[5], COUPs[2], 0., 0., w[109] );

  // Amplitude(s) for diagram number 779
  FFV1_0( w[3], w[77], w[9], COUPs[1], &amp[0] );
  jamp[25] -= cxtype( 0, 1 ) * amp[0];
  jamp[26] += cxtype( 0, 1 ) * amp[0];
  jamp[27] -= cxtype( 0, 1 ) * amp[0];
  jamp[28] += cxtype( 0, 1 ) * amp[0];
  jamp[35] += cxtype( 0, 1 ) * amp[0];
  jamp[39] -= cxtype( 0, 1 ) * amp[0];
  jamp[41] += cxtype( 0, 1 ) * amp[0];
  jamp[45] -= cxtype( 0, 1 ) * amp[0];
  FFV1_0( w[3], w[77], w[110], COUPs[1], &amp[0] );
  jamp[26] += cxtype( 0, 1 ) * amp[0];
  jamp[27] -= cxtype( 0, 1 ) * amp[0];
  jamp[34] -= cxtype( 0, 1 ) * amp[0];
  jamp[35] += cxtype( 0, 1 ) * amp[0];
  jamp[36] -= cxtype( 0, 1 ) * amp[0];
  jamp[37] += cxtype( 0, 1 ) * amp[0];
  jamp[44] += cxtype( 0, 1 ) * amp[0];
  jamp[45] -= cxtype( 0, 1 ) * amp[0];
  FFV1_0( w[3], w[77], w[109], COUPs[1], &amp[0] );
  jamp[25] += cxtype( 0, 1 ) * amp[0];
  jamp[28] -= cxtype( 0, 1 ) * amp[0];
  jamp[34] -= cxtype( 0, 1 ) * amp[0];
  jamp[36] -= cxtype( 0, 1 ) * amp[0];
  jamp[37] += cxtype( 0, 1 ) * amp[0];
  jamp[39] += cxtype( 0, 1 ) * amp[0];
  jamp[41] -= cxtype( 0, 1 ) * amp[0];
  jamp[44] += cxtype( 0, 1 ) * amp[0];

  // *** DIAGRAM 780 OF 1240 ***

  // Wavefunction(s) for diagram number 780
  // (none)

  // Amplitude(s) for diagram number 780
  FFV1_0( w[12], w[92], w[4], COUPs[1], &amp[0] );
#ifdef MGONGPU_SUPPORTS_MULTICHANNEL
  if( channelId == 780 ) allNumerators[0] += cxabs2( amp[0] );
  if( channelId != 0 ) allDenominators[0] += cxabs2( amp[0] );
#endif
  jamp[24] += cxtype( 0, 1 ) * amp[0];
  jamp[25] -= cxtype( 0, 1 ) * amp[0];

  // *** DIAGRAM 781 OF 1240 ***

  // Wavefunction(s) for diagram number 781
  // (none)

  // Amplitude(s) for diagram number 781
  FFV1_0( w[3], w[92], w[19], COUPs[1], &amp[0] );
#ifdef MGONGPU_SUPPORTS_MULTICHANNEL
  if( channelId == 781 ) allNumerators[0] += cxabs2( amp[0] );
  if( channelId != 0 ) allDenominators[0] += cxabs2( amp[0] );
#endif
  jamp[24] += amp[0];
  jamp[25] -= amp[0];
  jamp[27] -= amp[0];
  jamp[29] += amp[0];

  // *** DIAGRAM 782 OF 1240 ***

  // Wavefunction(s) for diagram number 782
  // (none)

  // Amplitude(s) for diagram number 782
  VVV1_0( w[96], w[34], w[4], COUPs[0], &amp[0] );
#ifdef MGONGPU_SUPPORTS_MULTICHANNEL
  if( channelId == 782 ) allNumerators[0] += cxabs2( amp[0] );
  if( channelId != 0 ) allDenominators[0] += cxabs2( amp[0] );
#endif
  jamp[27] += cxtype( 0, 1 ) * amp[0];
  jamp[29] -= cxtype( 0, 1 ) * amp[0];
  jamp[30] -= cxtype( 0, 1 ) * amp[0];
  jamp[31] += cxtype( 0, 1 ) * amp[0];
  jamp[33] += cxtype( 0, 1 ) * amp[0];
  jamp[35] -= cxtype( 0, 1 ) * amp[0];
  jamp[40] -= cxtype( 0, 1 ) * amp[0];
  jamp[46] += cxtype( 0, 1 ) * amp[0];

  // *** DIAGRAM 783 OF 1240 ***

  // Wavefunction(s) for diagram number 783
  // (none)

  // Amplitude(s) for diagram number 783
  FFV1_0( w[3], w[87], w[96], COUPs[1], &amp[0] );
#ifdef MGONGPU_SUPPORTS_MULTICHANNEL
  if( channelId == 783 ) allNumerators[0] += cxabs2( amp[0] );
  if( channelId != 0 ) allDenominators[0] += cxabs2( amp[0] );
#endif
  jamp[30] += amp[0];
  jamp[31] -= amp[0];
  jamp[33] -= amp[0];
  jamp[35] += amp[0];

  // *** DIAGRAM 784 OF 1240 ***

  // Wavefunction(s) for diagram number 784
  // (none)

  // Amplitude(s) for diagram number 784
  VVV1_0( w[0], w[34], w[19], COUPs[0], &amp[0] );
#ifdef MGONGPU_SUPPORTS_MULTICHANNEL
  if( channelId == 784 ) allNumerators[0] += cxabs2( amp[0] );
  if( channelId != 0 ) allDenominators[0] += cxabs2( amp[0] );
#endif
  jamp[24] += cxtype( 0, 1 ) * amp[0];
  jamp[25] -= cxtype( 0, 1 ) * amp[0];
  jamp[27] -= cxtype( 0, 1 ) * amp[0];
  jamp[29] += cxtype( 0, 1 ) * amp[0];
  jamp[33] -= cxtype( 0, 1 ) * amp[0];
  jamp[35] += cxtype( 0, 1 ) * amp[0];
  jamp[41] += cxtype( 0, 1 ) * amp[0];
  jamp[47] -= cxtype( 0, 1 ) * amp[0];

  // *** DIAGRAM 785 OF 1240 ***

  // Wavefunction(s) for diagram number 785
  // (none)

  // Amplitude(s) for diagram number 785
  FFV1_0( w[12], w[87], w[0], COUPs[1], &amp[0] );
#ifdef MGONGPU_SUPPORTS_MULTICHANNEL
  if( channelId == 785 ) allNumerators[0] += cxabs2( amp[0] );
  if( channelId != 0 ) allDenominators[0] += cxabs2( amp[0] );
#endif
  jamp[30] += cxtype( 0, 1 ) * amp[0];
  jamp[31] -= cxtype( 0, 1 ) * amp[0];

  // *** DIAGRAM 786 OF 1240 ***

  // Wavefunction(s) for diagram number 786
  VVVV1P0_1( w[0], w[4], w[29], COUPs[2], 0., 0., w[87] );
  VVVV3P0_1( w[0], w[4], w[29], COUPs[2], 0., 0., w[34] );
  VVVV4P0_1( w[0], w[4], w[29], COUPs[2], 0., 0., w[86] );

  // Amplitude(s) for diagram number 786
  FFV1_0( w[3], w[77], w[87], COUPs[1], &amp[0] );
  jamp[24] -= cxtype( 0, 1 ) * amp[0];
  jamp[25] += cxtype( 0, 1 ) * amp[0];
  jamp[27] += cxtype( 0, 1 ) * amp[0];
  jamp[29] -= cxtype( 0, 1 ) * amp[0];
  jamp[33] += cxtype( 0, 1 ) * amp[0];
  jamp[35] -= cxtype( 0, 1 ) * amp[0];
  jamp[41] -= cxtype( 0, 1 ) * amp[0];
  jamp[47] += cxtype( 0, 1 ) * amp[0];
  FFV1_0( w[3], w[77], w[34], COUPs[1], &amp[0] );
  jamp[27] += cxtype( 0, 1 ) * amp[0];
  jamp[29] -= cxtype( 0, 1 ) * amp[0];
  jamp[30] -= cxtype( 0, 1 ) * amp[0];
  jamp[31] += cxtype( 0, 1 ) * amp[0];
  jamp[33] += cxtype( 0, 1 ) * amp[0];
  jamp[35] -= cxtype( 0, 1 ) * amp[0];
  jamp[40] -= cxtype( 0, 1 ) * amp[0];
  jamp[46] += cxtype( 0, 1 ) * amp[0];
  FFV1_0( w[3], w[77], w[86], COUPs[1], &amp[0] );
  jamp[24] += cxtype( 0, 1 ) * amp[0];
  jamp[25] -= cxtype( 0, 1 ) * amp[0];
  jamp[30] -= cxtype( 0, 1 ) * amp[0];
  jamp[31] += cxtype( 0, 1 ) * amp[0];
  jamp[40] -= cxtype( 0, 1 ) * amp[0];
  jamp[41] += cxtype( 0, 1 ) * amp[0];
  jamp[46] += cxtype( 0, 1 ) * amp[0];
  jamp[47] -= cxtype( 0, 1 ) * amp[0];

  // *** DIAGRAM 787 OF 1240 ***

  // Wavefunction(s) for diagram number 787
  // (none)

  // Amplitude(s) for diagram number 787
  FFV1_0( w[3], w[92], w[30], COUPs[1], &amp[0] );
  jamp[24] += amp[0];
  jamp[25] -= amp[0];
  jamp[27] -= amp[0];
  jamp[29] += amp[0];
  FFV1_0( w[3], w[92], w[31], COUPs[1], &amp[0] );
  jamp[25] -= amp[0];
  jamp[26] += amp[0];
  jamp[27] -= amp[0];
  jamp[28] += amp[0];
  FFV1_0( w[3], w[92], w[32], COUPs[1], &amp[0] );
  jamp[24] -= amp[0];
  jamp[26] += amp[0];
  jamp[28] += amp[0];
  jamp[29] -= amp[0];

  // *** DIAGRAM 788 OF 1240 ***

  // Wavefunction(s) for diagram number 788
  VVV1P0_1( w[0], w[30], COUPs[0], 0., 0., w[92] );
  VVV1P0_1( w[0], w[31], COUPs[0], 0., 0., w[88] );
  VVV1P0_1( w[0], w[32], COUPs[0], 0., 0., w[106] );

  // Amplitude(s) for diagram number 788
  FFV1_0( w[3], w[77], w[92], COUPs[1], &amp[0] );
  jamp[24] -= cxtype( 0, 1 ) * amp[0];
  jamp[25] += cxtype( 0, 1 ) * amp[0];
  jamp[27] += cxtype( 0, 1 ) * amp[0];
  jamp[29] -= cxtype( 0, 1 ) * amp[0];
  jamp[33] += cxtype( 0, 1 ) * amp[0];
  jamp[35] -= cxtype( 0, 1 ) * amp[0];
  jamp[41] -= cxtype( 0, 1 ) * amp[0];
  jamp[47] += cxtype( 0, 1 ) * amp[0];
  FFV1_0( w[3], w[77], w[88], COUPs[1], &amp[0] );
  jamp[25] += cxtype( 0, 1 ) * amp[0];
  jamp[26] -= cxtype( 0, 1 ) * amp[0];
  jamp[27] += cxtype( 0, 1 ) * amp[0];
  jamp[28] -= cxtype( 0, 1 ) * amp[0];
  jamp[35] -= cxtype( 0, 1 ) * amp[0];
  jamp[39] += cxtype( 0, 1 ) * amp[0];
  jamp[41] -= cxtype( 0, 1 ) * amp[0];
  jamp[45] += cxtype( 0, 1 ) * amp[0];
  FFV1_0( w[3], w[77], w[106], COUPs[1], &amp[0] );
  jamp[24] += cxtype( 0, 1 ) * amp[0];
  jamp[26] -= cxtype( 0, 1 ) * amp[0];
  jamp[28] -= cxtype( 0, 1 ) * amp[0];
  jamp[29] += cxtype( 0, 1 ) * amp[0];
  jamp[33] -= cxtype( 0, 1 ) * amp[0];
  jamp[39] += cxtype( 0, 1 ) * amp[0];
  jamp[45] += cxtype( 0, 1 ) * amp[0];
  jamp[47] -= cxtype( 0, 1 ) * amp[0];

  // *** DIAGRAM 789 OF 1240 ***

  // Wavefunction(s) for diagram number 789
  FFV1_2( w[52], w[0], COUPs[1], cIPD[0], cIPD[1], w[90] );

  // Amplitude(s) for diagram number 789
  FFV1_0( w[90], w[35], w[6], COUPs[1], &amp[0] );
#ifdef MGONGPU_SUPPORTS_MULTICHANNEL
  if( channelId == 789 ) allNumerators[0] += cxabs2( amp[0] );
  if( channelId != 0 ) allDenominators[0] += cxabs2( amp[0] );
#endif
  jamp[64] -= amp[0];

  // *** DIAGRAM 790 OF 1240 ***

  // Wavefunction(s) for diagram number 790
  // (none)

  // Amplitude(s) for diagram number 790
  FFV1_0( w[90], w[36], w[5], COUPs[1], &amp[0] );
#ifdef MGONGPU_SUPPORTS_MULTICHANNEL
  if( channelId == 790 ) allNumerators[0] += cxabs2( amp[0] );
  if( channelId != 0 ) allDenominators[0] += cxabs2( amp[0] );
#endif
  jamp[70] -= amp[0];

  // *** DIAGRAM 791 OF 1240 ***

  // Wavefunction(s) for diagram number 791
  FFV1_1( w[33], w[0], COUPs[1], cIPD[0], cIPD[1], w[114] );

  // Amplitude(s) for diagram number 791
  FFV1_0( w[22], w[114], w[6], COUPs[1], &amp[0] );
#ifdef MGONGPU_SUPPORTS_MULTICHANNEL
  if( channelId == 791 ) allNumerators[0] += cxabs2( amp[0] );
  if( channelId != 0 ) allDenominators[0] += cxabs2( amp[0] );
#endif
  jamp[53] -= amp[0];

  // *** DIAGRAM 792 OF 1240 ***

  // Wavefunction(s) for diagram number 792
  // (none)

  // Amplitude(s) for diagram number 792
  FFV1_0( w[21], w[114], w[5], COUPs[1], &amp[0] );
#ifdef MGONGPU_SUPPORTS_MULTICHANNEL
  if( channelId == 792 ) allNumerators[0] += cxabs2( amp[0] );
  if( channelId != 0 ) allDenominators[0] += cxabs2( amp[0] );
#endif
  jamp[51] -= amp[0];

  // *** DIAGRAM 793 OF 1240 ***

  // Wavefunction(s) for diagram number 793
  // (none)

  // Amplitude(s) for diagram number 793
  FFV1_0( w[22], w[36], w[0], COUPs[1], &amp[0] );
#ifdef MGONGPU_SUPPORTS_MULTICHANNEL
  if( channelId == 793 ) allNumerators[0] += cxabs2( amp[0] );
  if( channelId != 0 ) allDenominators[0] += cxabs2( amp[0] );
#endif
  jamp[67] -= amp[0];

  // *** DIAGRAM 794 OF 1240 ***

  // Wavefunction(s) for diagram number 794
  // (none)

  // Amplitude(s) for diagram number 794
  FFV1_0( w[21], w[35], w[0], COUPs[1], &amp[0] );
#ifdef MGONGPU_SUPPORTS_MULTICHANNEL
  if( channelId == 794 ) allNumerators[0] += cxabs2( amp[0] );
  if( channelId != 0 ) allDenominators[0] += cxabs2( amp[0] );
#endif
  jamp[61] -= amp[0];

  // *** DIAGRAM 795 OF 1240 ***

  // Wavefunction(s) for diagram number 795
  // (none)

  // Amplitude(s) for diagram number 795
  FFV1_0( w[90], w[33], w[29], COUPs[1], &amp[0] );
#ifdef MGONGPU_SUPPORTS_MULTICHANNEL
  if( channelId == 795 ) allNumerators[0] += cxabs2( amp[0] );
  if( channelId != 0 ) allDenominators[0] += cxabs2( amp[0] );
#endif
  jamp[64] += cxtype( 0, 1 ) * amp[0];
  jamp[70] -= cxtype( 0, 1 ) * amp[0];

  // *** DIAGRAM 796 OF 1240 ***

  // Wavefunction(s) for diagram number 796
  // (none)

  // Amplitude(s) for diagram number 796
  FFV1_0( w[52], w[114], w[29], COUPs[1], &amp[0] );
#ifdef MGONGPU_SUPPORTS_MULTICHANNEL
  if( channelId == 796 ) allNumerators[0] += cxabs2( amp[0] );
  if( channelId != 0 ) allDenominators[0] += cxabs2( amp[0] );
#endif
  jamp[51] += cxtype( 0, 1 ) * amp[0];
  jamp[53] -= cxtype( 0, 1 ) * amp[0];

  // *** DIAGRAM 797 OF 1240 ***

  // Wavefunction(s) for diagram number 797
  // (none)

  // Amplitude(s) for diagram number 797
  FFV1_0( w[52], w[33], w[96], COUPs[1], &amp[0] );
#ifdef MGONGPU_SUPPORTS_MULTICHANNEL
  if( channelId == 797 ) allNumerators[0] += cxabs2( amp[0] );
  if( channelId != 0 ) allDenominators[0] += cxabs2( amp[0] );
#endif
  jamp[51] += amp[0];
  jamp[53] -= amp[0];
  jamp[64] -= amp[0];
  jamp[70] += amp[0];

  // *** DIAGRAM 798 OF 1240 ***

  // Wavefunction(s) for diagram number 798
  // (none)

  // Amplitude(s) for diagram number 798
  FFV1_0( w[90], w[43], w[6], COUPs[1], &amp[0] );
#ifdef MGONGPU_SUPPORTS_MULTICHANNEL
  if( channelId == 798 ) allNumerators[0] += cxabs2( amp[0] );
  if( channelId != 0 ) allDenominators[0] += cxabs2( amp[0] );
#endif
  jamp[88] -= amp[0];

  // *** DIAGRAM 799 OF 1240 ***

  // Wavefunction(s) for diagram number 799
  // (none)

  // Amplitude(s) for diagram number 799
  FFV1_0( w[90], w[44], w[4], COUPs[1], &amp[0] );
#ifdef MGONGPU_SUPPORTS_MULTICHANNEL
  if( channelId == 799 ) allNumerators[0] += cxabs2( amp[0] );
  if( channelId != 0 ) allDenominators[0] += cxabs2( amp[0] );
#endif
  jamp[94] -= amp[0];

  // *** DIAGRAM 800 OF 1240 ***

  // Wavefunction(s) for diagram number 800
  FFV1_1( w[39], w[0], COUPs[1], cIPD[0], cIPD[1], w[102] );

  // Amplitude(s) for diagram number 800
  FFV1_0( w[56], w[102], w[6], COUPs[1], &amp[0] );
#ifdef MGONGPU_SUPPORTS_MULTICHANNEL
  if( channelId == 800 ) allNumerators[0] += cxabs2( amp[0] );
  if( channelId != 0 ) allDenominators[0] += cxabs2( amp[0] );
#endif
  jamp[77] -= amp[0];

  // *** DIAGRAM 801 OF 1240 ***

  // Wavefunction(s) for diagram number 801
  // (none)

  // Amplitude(s) for diagram number 801
  FFV1_0( w[21], w[102], w[4], COUPs[1], &amp[0] );
#ifdef MGONGPU_SUPPORTS_MULTICHANNEL
  if( channelId == 801 ) allNumerators[0] += cxabs2( amp[0] );
  if( channelId != 0 ) allDenominators[0] += cxabs2( amp[0] );
#endif
  jamp[75] -= amp[0];

  // *** DIAGRAM 802 OF 1240 ***

  // Wavefunction(s) for diagram number 802
  // (none)

  // Amplitude(s) for diagram number 802
  FFV1_0( w[56], w[44], w[0], COUPs[1], &amp[0] );
#ifdef MGONGPU_SUPPORTS_MULTICHANNEL
  if( channelId == 802 ) allNumerators[0] += cxabs2( amp[0] );
  if( channelId != 0 ) allDenominators[0] += cxabs2( amp[0] );
#endif
  jamp[91] -= amp[0];

  // *** DIAGRAM 803 OF 1240 ***

  // Wavefunction(s) for diagram number 803
  // (none)

  // Amplitude(s) for diagram number 803
  FFV1_0( w[21], w[43], w[0], COUPs[1], &amp[0] );
#ifdef MGONGPU_SUPPORTS_MULTICHANNEL
  if( channelId == 803 ) allNumerators[0] += cxabs2( amp[0] );
  if( channelId != 0 ) allDenominators[0] += cxabs2( amp[0] );
#endif
  jamp[85] -= amp[0];

  // *** DIAGRAM 804 OF 1240 ***

  // Wavefunction(s) for diagram number 804
  // (none)

  // Amplitude(s) for diagram number 804
  FFV1_0( w[90], w[39], w[27], COUPs[1], &amp[0] );
#ifdef MGONGPU_SUPPORTS_MULTICHANNEL
  if( channelId == 804 ) allNumerators[0] += cxabs2( amp[0] );
  if( channelId != 0 ) allDenominators[0] += cxabs2( amp[0] );
#endif
  jamp[88] += cxtype( 0, 1 ) * amp[0];
  jamp[94] -= cxtype( 0, 1 ) * amp[0];

  // *** DIAGRAM 805 OF 1240 ***

  // Wavefunction(s) for diagram number 805
  // (none)

  // Amplitude(s) for diagram number 805
  FFV1_0( w[52], w[102], w[27], COUPs[1], &amp[0] );
#ifdef MGONGPU_SUPPORTS_MULTICHANNEL
  if( channelId == 805 ) allNumerators[0] += cxabs2( amp[0] );
  if( channelId != 0 ) allDenominators[0] += cxabs2( amp[0] );
#endif
  jamp[75] += cxtype( 0, 1 ) * amp[0];
  jamp[77] -= cxtype( 0, 1 ) * amp[0];

  // *** DIAGRAM 806 OF 1240 ***

  // Wavefunction(s) for diagram number 806
  // (none)

  // Amplitude(s) for diagram number 806
  FFV1_0( w[52], w[39], w[101], COUPs[1], &amp[0] );
#ifdef MGONGPU_SUPPORTS_MULTICHANNEL
  if( channelId == 806 ) allNumerators[0] += cxabs2( amp[0] );
  if( channelId != 0 ) allDenominators[0] += cxabs2( amp[0] );
#endif
  jamp[75] += amp[0];
  jamp[77] -= amp[0];
  jamp[88] -= amp[0];
  jamp[94] += amp[0];

  // *** DIAGRAM 807 OF 1240 ***

  // Wavefunction(s) for diagram number 807
  // (none)

  // Amplitude(s) for diagram number 807
  FFV1_0( w[90], w[49], w[5], COUPs[1], &amp[0] );
#ifdef MGONGPU_SUPPORTS_MULTICHANNEL
  if( channelId == 807 ) allNumerators[0] += cxabs2( amp[0] );
  if( channelId != 0 ) allDenominators[0] += cxabs2( amp[0] );
#endif
  jamp[112] -= amp[0];

  // *** DIAGRAM 808 OF 1240 ***

  // Wavefunction(s) for diagram number 808
  // (none)

  // Amplitude(s) for diagram number 808
  FFV1_0( w[90], w[50], w[4], COUPs[1], &amp[0] );
#ifdef MGONGPU_SUPPORTS_MULTICHANNEL
  if( channelId == 808 ) allNumerators[0] += cxabs2( amp[0] );
  if( channelId != 0 ) allDenominators[0] += cxabs2( amp[0] );
#endif
  jamp[118] -= amp[0];

  // *** DIAGRAM 809 OF 1240 ***

  // Wavefunction(s) for diagram number 809
  FFV1_1( w[47], w[0], COUPs[1], cIPD[0], cIPD[1], w[113] );

  // Amplitude(s) for diagram number 809
  FFV1_0( w[56], w[113], w[5], COUPs[1], &amp[0] );
#ifdef MGONGPU_SUPPORTS_MULTICHANNEL
  if( channelId == 809 ) allNumerators[0] += cxabs2( amp[0] );
  if( channelId != 0 ) allDenominators[0] += cxabs2( amp[0] );
#endif
  jamp[101] -= amp[0];

  // *** DIAGRAM 810 OF 1240 ***

  // Wavefunction(s) for diagram number 810
  // (none)

  // Amplitude(s) for diagram number 810
  FFV1_0( w[22], w[113], w[4], COUPs[1], &amp[0] );
#ifdef MGONGPU_SUPPORTS_MULTICHANNEL
  if( channelId == 810 ) allNumerators[0] += cxabs2( amp[0] );
  if( channelId != 0 ) allDenominators[0] += cxabs2( amp[0] );
#endif
  jamp[99] -= amp[0];

  // *** DIAGRAM 811 OF 1240 ***

  // Wavefunction(s) for diagram number 811
  // (none)

  // Amplitude(s) for diagram number 811
  FFV1_0( w[56], w[50], w[0], COUPs[1], &amp[0] );
#ifdef MGONGPU_SUPPORTS_MULTICHANNEL
  if( channelId == 811 ) allNumerators[0] += cxabs2( amp[0] );
  if( channelId != 0 ) allDenominators[0] += cxabs2( amp[0] );
#endif
  jamp[115] -= amp[0];

  // *** DIAGRAM 812 OF 1240 ***

  // Wavefunction(s) for diagram number 812
  // (none)

  // Amplitude(s) for diagram number 812
  FFV1_0( w[22], w[49], w[0], COUPs[1], &amp[0] );
#ifdef MGONGPU_SUPPORTS_MULTICHANNEL
  if( channelId == 812 ) allNumerators[0] += cxabs2( amp[0] );
  if( channelId != 0 ) allDenominators[0] += cxabs2( amp[0] );
#endif
  jamp[109] -= amp[0];

  // *** DIAGRAM 813 OF 1240 ***

  // Wavefunction(s) for diagram number 813
  // (none)

  // Amplitude(s) for diagram number 813
  FFV1_0( w[90], w[47], w[24], COUPs[1], &amp[0] );
#ifdef MGONGPU_SUPPORTS_MULTICHANNEL
  if( channelId == 813 ) allNumerators[0] += cxabs2( amp[0] );
  if( channelId != 0 ) allDenominators[0] += cxabs2( amp[0] );
#endif
  jamp[112] += cxtype( 0, 1 ) * amp[0];
  jamp[118] -= cxtype( 0, 1 ) * amp[0];

  // *** DIAGRAM 814 OF 1240 ***

  // Wavefunction(s) for diagram number 814
  // (none)

  // Amplitude(s) for diagram number 814
  FFV1_0( w[52], w[113], w[24], COUPs[1], &amp[0] );
#ifdef MGONGPU_SUPPORTS_MULTICHANNEL
  if( channelId == 814 ) allNumerators[0] += cxabs2( amp[0] );
  if( channelId != 0 ) allDenominators[0] += cxabs2( amp[0] );
#endif
  jamp[99] += cxtype( 0, 1 ) * amp[0];
  jamp[101] -= cxtype( 0, 1 ) * amp[0];

  // *** DIAGRAM 815 OF 1240 ***

  // Wavefunction(s) for diagram number 815
  // (none)

  // Amplitude(s) for diagram number 815
  FFV1_0( w[52], w[47], w[98], COUPs[1], &amp[0] );
#ifdef MGONGPU_SUPPORTS_MULTICHANNEL
  if( channelId == 815 ) allNumerators[0] += cxabs2( amp[0] );
  if( channelId != 0 ) allDenominators[0] += cxabs2( amp[0] );
#endif
  jamp[99] += amp[0];
  jamp[101] -= amp[0];
  jamp[112] -= amp[0];
  jamp[118] += amp[0];

  // *** DIAGRAM 816 OF 1240 ***

  // Wavefunction(s) for diagram number 816
  // (none)

  // Amplitude(s) for diagram number 816
  FFV1_0( w[90], w[17], w[6], COUPs[1], &amp[0] );
#ifdef MGONGPU_SUPPORTS_MULTICHANNEL
  if( channelId == 816 ) allNumerators[0] += cxabs2( amp[0] );
  if( channelId != 0 ) allDenominators[0] += cxabs2( amp[0] );
#endif
  jamp[64] += cxtype( 0, 1 ) * amp[0];
  jamp[88] -= cxtype( 0, 1 ) * amp[0];

  // *** DIAGRAM 817 OF 1240 ***

  // Wavefunction(s) for diagram number 817
  // (none)

  // Amplitude(s) for diagram number 817
  FFV1_0( w[90], w[2], w[42], COUPs[1], &amp[0] );
#ifdef MGONGPU_SUPPORTS_MULTICHANNEL
  if( channelId == 817 ) allNumerators[0] += cxabs2( amp[0] );
  if( channelId != 0 ) allDenominators[0] += cxabs2( amp[0] );
#endif
  jamp[64] += amp[0];
  jamp[88] -= amp[0];
  jamp[112] -= amp[0];
  jamp[118] += amp[0];

  // *** DIAGRAM 818 OF 1240 ***

  // Wavefunction(s) for diagram number 818
  // (none)

  // Amplitude(s) for diagram number 818
  VVV1_0( w[98], w[103], w[6], COUPs[0], &amp[0] );
#ifdef MGONGPU_SUPPORTS_MULTICHANNEL
  if( channelId == 818 ) allNumerators[0] += cxabs2( amp[0] );
  if( channelId != 0 ) allDenominators[0] += cxabs2( amp[0] );
#endif
  jamp[9] += cxtype( 0, 1 ) * amp[0];
  jamp[15] -= cxtype( 0, 1 ) * amp[0];
  jamp[61] -= cxtype( 0, 1 ) * amp[0];
  jamp[85] += cxtype( 0, 1 ) * amp[0];
  jamp[99] -= cxtype( 0, 1 ) * amp[0];
  jamp[101] += cxtype( 0, 1 ) * amp[0];
  jamp[112] += cxtype( 0, 1 ) * amp[0];
  jamp[118] -= cxtype( 0, 1 ) * amp[0];

  // *** DIAGRAM 819 OF 1240 ***

  // Wavefunction(s) for diagram number 819
  // (none)

  // Amplitude(s) for diagram number 819
  FFV1_0( w[21], w[2], w[98], COUPs[1], &amp[0] );
#ifdef MGONGPU_SUPPORTS_MULTICHANNEL
  if( channelId == 819 ) allNumerators[0] += cxabs2( amp[0] );
  if( channelId != 0 ) allDenominators[0] += cxabs2( amp[0] );
#endif
  jamp[9] += amp[0];
  jamp[15] -= amp[0];
  jamp[61] -= amp[0];
  jamp[85] += amp[0];

  // *** DIAGRAM 820 OF 1240 ***

  // Wavefunction(s) for diagram number 820
  // (none)

  // Amplitude(s) for diagram number 820
  VVV1_0( w[0], w[103], w[42], COUPs[0], &amp[0] );
#ifdef MGONGPU_SUPPORTS_MULTICHANNEL
  if( channelId == 820 ) allNumerators[0] += cxabs2( amp[0] );
  if( channelId != 0 ) allDenominators[0] += cxabs2( amp[0] );
#endif
  jamp[9] += cxtype( 0, 1 ) * amp[0];
  jamp[15] -= cxtype( 0, 1 ) * amp[0];
  jamp[21] -= cxtype( 0, 1 ) * amp[0];
  jamp[23] += cxtype( 0, 1 ) * amp[0];
  jamp[64] -= cxtype( 0, 1 ) * amp[0];
  jamp[88] += cxtype( 0, 1 ) * amp[0];
  jamp[112] += cxtype( 0, 1 ) * amp[0];
  jamp[118] -= cxtype( 0, 1 ) * amp[0];

  // *** DIAGRAM 821 OF 1240 ***

  // Wavefunction(s) for diagram number 821
  // (none)

  // Amplitude(s) for diagram number 821
  FFV1_0( w[21], w[17], w[0], COUPs[1], &amp[0] );
#ifdef MGONGPU_SUPPORTS_MULTICHANNEL
  if( channelId == 821 ) allNumerators[0] += cxabs2( amp[0] );
  if( channelId != 0 ) allDenominators[0] += cxabs2( amp[0] );
#endif
  jamp[61] += cxtype( 0, 1 ) * amp[0];
  jamp[85] -= cxtype( 0, 1 ) * amp[0];

  // *** DIAGRAM 822 OF 1240 ***

  // Wavefunction(s) for diagram number 822
  // (none)

  // Amplitude(s) for diagram number 822
  FFV1_0( w[52], w[2], w[85], COUPs[1], &amp[0] );
  jamp[9] -= cxtype( 0, 1 ) * amp[0];
  jamp[15] += cxtype( 0, 1 ) * amp[0];
  jamp[21] += cxtype( 0, 1 ) * amp[0];
  jamp[23] -= cxtype( 0, 1 ) * amp[0];
  jamp[64] += cxtype( 0, 1 ) * amp[0];
  jamp[88] -= cxtype( 0, 1 ) * amp[0];
  jamp[112] -= cxtype( 0, 1 ) * amp[0];
  jamp[118] += cxtype( 0, 1 ) * amp[0];
  FFV1_0( w[52], w[2], w[112], COUPs[1], &amp[0] );
  jamp[21] += cxtype( 0, 1 ) * amp[0];
  jamp[23] -= cxtype( 0, 1 ) * amp[0];
  jamp[61] -= cxtype( 0, 1 ) * amp[0];
  jamp[64] += cxtype( 0, 1 ) * amp[0];
  jamp[85] += cxtype( 0, 1 ) * amp[0];
  jamp[88] -= cxtype( 0, 1 ) * amp[0];
  jamp[99] -= cxtype( 0, 1 ) * amp[0];
  jamp[101] += cxtype( 0, 1 ) * amp[0];
  FFV1_0( w[52], w[2], w[111], COUPs[1], &amp[0] );
  jamp[9] += cxtype( 0, 1 ) * amp[0];
  jamp[15] -= cxtype( 0, 1 ) * amp[0];
  jamp[61] -= cxtype( 0, 1 ) * amp[0];
  jamp[85] += cxtype( 0, 1 ) * amp[0];
  jamp[99] -= cxtype( 0, 1 ) * amp[0];
  jamp[101] += cxtype( 0, 1 ) * amp[0];
  jamp[112] += cxtype( 0, 1 ) * amp[0];
  jamp[118] -= cxtype( 0, 1 ) * amp[0];

  // *** DIAGRAM 823 OF 1240 ***

  // Wavefunction(s) for diagram number 823
  // (none)

  // Amplitude(s) for diagram number 823
  FFV1_0( w[90], w[15], w[5], COUPs[1], &amp[0] );
#ifdef MGONGPU_SUPPORTS_MULTICHANNEL
  if( channelId == 823 ) allNumerators[0] += cxabs2( amp[0] );
  if( channelId != 0 ) allDenominators[0] += cxabs2( amp[0] );
#endif
  jamp[70] += cxtype( 0, 1 ) * amp[0];
  jamp[112] -= cxtype( 0, 1 ) * amp[0];

  // *** DIAGRAM 824 OF 1240 ***

  // Wavefunction(s) for diagram number 824
  // (none)

  // Amplitude(s) for diagram number 824
  FFV1_0( w[90], w[2], w[16], COUPs[1], &amp[0] );
#ifdef MGONGPU_SUPPORTS_MULTICHANNEL
  if( channelId == 824 ) allNumerators[0] += cxabs2( amp[0] );
  if( channelId != 0 ) allDenominators[0] += cxabs2( amp[0] );
#endif
  jamp[70] += amp[0];
  jamp[88] -= amp[0];
  jamp[94] += amp[0];
  jamp[112] -= amp[0];

  // *** DIAGRAM 825 OF 1240 ***

  // Wavefunction(s) for diagram number 825
  // (none)

  // Amplitude(s) for diagram number 825
  VVV1_0( w[101], w[103], w[5], COUPs[0], &amp[0] );
#ifdef MGONGPU_SUPPORTS_MULTICHANNEL
  if( channelId == 825 ) allNumerators[0] += cxabs2( amp[0] );
  if( channelId != 0 ) allDenominators[0] += cxabs2( amp[0] );
#endif
  jamp[11] += cxtype( 0, 1 ) * amp[0];
  jamp[21] -= cxtype( 0, 1 ) * amp[0];
  jamp[67] -= cxtype( 0, 1 ) * amp[0];
  jamp[75] -= cxtype( 0, 1 ) * amp[0];
  jamp[77] += cxtype( 0, 1 ) * amp[0];
  jamp[88] += cxtype( 0, 1 ) * amp[0];
  jamp[94] -= cxtype( 0, 1 ) * amp[0];
  jamp[109] += cxtype( 0, 1 ) * amp[0];

  // *** DIAGRAM 826 OF 1240 ***

  // Wavefunction(s) for diagram number 826
  // (none)

  // Amplitude(s) for diagram number 826
  FFV1_0( w[22], w[2], w[101], COUPs[1], &amp[0] );
#ifdef MGONGPU_SUPPORTS_MULTICHANNEL
  if( channelId == 826 ) allNumerators[0] += cxabs2( amp[0] );
  if( channelId != 0 ) allDenominators[0] += cxabs2( amp[0] );
#endif
  jamp[11] += amp[0];
  jamp[21] -= amp[0];
  jamp[67] -= amp[0];
  jamp[109] += amp[0];

  // *** DIAGRAM 827 OF 1240 ***

  // Wavefunction(s) for diagram number 827
  // (none)

  // Amplitude(s) for diagram number 827
  VVV1_0( w[0], w[103], w[16], COUPs[0], &amp[0] );
#ifdef MGONGPU_SUPPORTS_MULTICHANNEL
  if( channelId == 827 ) allNumerators[0] += cxabs2( amp[0] );
  if( channelId != 0 ) allDenominators[0] += cxabs2( amp[0] );
#endif
  jamp[11] += cxtype( 0, 1 ) * amp[0];
  jamp[15] -= cxtype( 0, 1 ) * amp[0];
  jamp[17] += cxtype( 0, 1 ) * amp[0];
  jamp[21] -= cxtype( 0, 1 ) * amp[0];
  jamp[70] -= cxtype( 0, 1 ) * amp[0];
  jamp[88] += cxtype( 0, 1 ) * amp[0];
  jamp[94] -= cxtype( 0, 1 ) * amp[0];
  jamp[112] += cxtype( 0, 1 ) * amp[0];

  // *** DIAGRAM 828 OF 1240 ***

  // Wavefunction(s) for diagram number 828
  // (none)

  // Amplitude(s) for diagram number 828
  FFV1_0( w[22], w[15], w[0], COUPs[1], &amp[0] );
#ifdef MGONGPU_SUPPORTS_MULTICHANNEL
  if( channelId == 828 ) allNumerators[0] += cxabs2( amp[0] );
  if( channelId != 0 ) allDenominators[0] += cxabs2( amp[0] );
#endif
  jamp[67] += cxtype( 0, 1 ) * amp[0];
  jamp[109] -= cxtype( 0, 1 ) * amp[0];

  // *** DIAGRAM 829 OF 1240 ***

  // Wavefunction(s) for diagram number 829
  // (none)

  // Amplitude(s) for diagram number 829
  FFV1_0( w[52], w[2], w[9], COUPs[1], &amp[0] );
  jamp[11] -= cxtype( 0, 1 ) * amp[0];
  jamp[15] += cxtype( 0, 1 ) * amp[0];
  jamp[17] -= cxtype( 0, 1 ) * amp[0];
  jamp[21] += cxtype( 0, 1 ) * amp[0];
  jamp[70] += cxtype( 0, 1 ) * amp[0];
  jamp[88] -= cxtype( 0, 1 ) * amp[0];
  jamp[94] += cxtype( 0, 1 ) * amp[0];
  jamp[112] -= cxtype( 0, 1 ) * amp[0];
  FFV1_0( w[52], w[2], w[110], COUPs[1], &amp[0] );
  jamp[15] += cxtype( 0, 1 ) * amp[0];
  jamp[17] -= cxtype( 0, 1 ) * amp[0];
  jamp[67] -= cxtype( 0, 1 ) * amp[0];
  jamp[70] += cxtype( 0, 1 ) * amp[0];
  jamp[75] -= cxtype( 0, 1 ) * amp[0];
  jamp[77] += cxtype( 0, 1 ) * amp[0];
  jamp[109] += cxtype( 0, 1 ) * amp[0];
  jamp[112] -= cxtype( 0, 1 ) * amp[0];
  FFV1_0( w[52], w[2], w[109], COUPs[1], &amp[0] );
  jamp[11] += cxtype( 0, 1 ) * amp[0];
  jamp[21] -= cxtype( 0, 1 ) * amp[0];
  jamp[67] -= cxtype( 0, 1 ) * amp[0];
  jamp[75] -= cxtype( 0, 1 ) * amp[0];
  jamp[77] += cxtype( 0, 1 ) * amp[0];
  jamp[88] += cxtype( 0, 1 ) * amp[0];
  jamp[94] -= cxtype( 0, 1 ) * amp[0];
  jamp[109] += cxtype( 0, 1 ) * amp[0];

  // *** DIAGRAM 830 OF 1240 ***

  // Wavefunction(s) for diagram number 830
  // (none)

  // Amplitude(s) for diagram number 830
  FFV1_0( w[90], w[18], w[4], COUPs[1], &amp[0] );
#ifdef MGONGPU_SUPPORTS_MULTICHANNEL
  if( channelId == 830 ) allNumerators[0] += cxabs2( amp[0] );
  if( channelId != 0 ) allDenominators[0] += cxabs2( amp[0] );
#endif
  jamp[94] += cxtype( 0, 1 ) * amp[0];
  jamp[118] -= cxtype( 0, 1 ) * amp[0];

  // *** DIAGRAM 831 OF 1240 ***

  // Wavefunction(s) for diagram number 831
  // (none)

  // Amplitude(s) for diagram number 831
  FFV1_0( w[90], w[2], w[19], COUPs[1], &amp[0] );
#ifdef MGONGPU_SUPPORTS_MULTICHANNEL
  if( channelId == 831 ) allNumerators[0] += cxabs2( amp[0] );
  if( channelId != 0 ) allDenominators[0] += cxabs2( amp[0] );
#endif
  jamp[64] += amp[0];
  jamp[70] -= amp[0];
  jamp[94] -= amp[0];
  jamp[118] += amp[0];

  // *** DIAGRAM 832 OF 1240 ***

  // Wavefunction(s) for diagram number 832
  // (none)

  // Amplitude(s) for diagram number 832
  VVV1_0( w[96], w[103], w[4], COUPs[0], &amp[0] );
#ifdef MGONGPU_SUPPORTS_MULTICHANNEL
  if( channelId == 832 ) allNumerators[0] += cxabs2( amp[0] );
  if( channelId != 0 ) allDenominators[0] += cxabs2( amp[0] );
#endif
  jamp[17] += cxtype( 0, 1 ) * amp[0];
  jamp[23] -= cxtype( 0, 1 ) * amp[0];
  jamp[51] -= cxtype( 0, 1 ) * amp[0];
  jamp[53] += cxtype( 0, 1 ) * amp[0];
  jamp[64] += cxtype( 0, 1 ) * amp[0];
  jamp[70] -= cxtype( 0, 1 ) * amp[0];
  jamp[91] -= cxtype( 0, 1 ) * amp[0];
  jamp[115] += cxtype( 0, 1 ) * amp[0];

  // *** DIAGRAM 833 OF 1240 ***

  // Wavefunction(s) for diagram number 833
  // (none)

  // Amplitude(s) for diagram number 833
  FFV1_0( w[56], w[2], w[96], COUPs[1], &amp[0] );
#ifdef MGONGPU_SUPPORTS_MULTICHANNEL
  if( channelId == 833 ) allNumerators[0] += cxabs2( amp[0] );
  if( channelId != 0 ) allDenominators[0] += cxabs2( amp[0] );
#endif
  jamp[17] += amp[0];
  jamp[23] -= amp[0];
  jamp[91] -= amp[0];
  jamp[115] += amp[0];

  // *** DIAGRAM 834 OF 1240 ***

  // Wavefunction(s) for diagram number 834
  // (none)

  // Amplitude(s) for diagram number 834
  VVV1_0( w[0], w[103], w[19], COUPs[0], &amp[0] );
#ifdef MGONGPU_SUPPORTS_MULTICHANNEL
  if( channelId == 834 ) allNumerators[0] += cxabs2( amp[0] );
  if( channelId != 0 ) allDenominators[0] += cxabs2( amp[0] );
#endif
  jamp[9] += cxtype( 0, 1 ) * amp[0];
  jamp[11] -= cxtype( 0, 1 ) * amp[0];
  jamp[17] -= cxtype( 0, 1 ) * amp[0];
  jamp[23] += cxtype( 0, 1 ) * amp[0];
  jamp[64] -= cxtype( 0, 1 ) * amp[0];
  jamp[70] += cxtype( 0, 1 ) * amp[0];
  jamp[94] += cxtype( 0, 1 ) * amp[0];
  jamp[118] -= cxtype( 0, 1 ) * amp[0];

  // *** DIAGRAM 835 OF 1240 ***

  // Wavefunction(s) for diagram number 835
  // (none)

  // Amplitude(s) for diagram number 835
  FFV1_0( w[56], w[18], w[0], COUPs[1], &amp[0] );
#ifdef MGONGPU_SUPPORTS_MULTICHANNEL
  if( channelId == 835 ) allNumerators[0] += cxabs2( amp[0] );
  if( channelId != 0 ) allDenominators[0] += cxabs2( amp[0] );
#endif
  jamp[91] += cxtype( 0, 1 ) * amp[0];
  jamp[115] -= cxtype( 0, 1 ) * amp[0];

  // *** DIAGRAM 836 OF 1240 ***

  // Wavefunction(s) for diagram number 836
  // (none)

  // Amplitude(s) for diagram number 836
  FFV1_0( w[52], w[2], w[87], COUPs[1], &amp[0] );
  jamp[9] -= cxtype( 0, 1 ) * amp[0];
  jamp[11] += cxtype( 0, 1 ) * amp[0];
  jamp[17] += cxtype( 0, 1 ) * amp[0];
  jamp[23] -= cxtype( 0, 1 ) * amp[0];
  jamp[64] += cxtype( 0, 1 ) * amp[0];
  jamp[70] -= cxtype( 0, 1 ) * amp[0];
  jamp[94] -= cxtype( 0, 1 ) * amp[0];
  jamp[118] += cxtype( 0, 1 ) * amp[0];
  FFV1_0( w[52], w[2], w[34], COUPs[1], &amp[0] );
  jamp[17] += cxtype( 0, 1 ) * amp[0];
  jamp[23] -= cxtype( 0, 1 ) * amp[0];
  jamp[51] -= cxtype( 0, 1 ) * amp[0];
  jamp[53] += cxtype( 0, 1 ) * amp[0];
  jamp[64] += cxtype( 0, 1 ) * amp[0];
  jamp[70] -= cxtype( 0, 1 ) * amp[0];
  jamp[91] -= cxtype( 0, 1 ) * amp[0];
  jamp[115] += cxtype( 0, 1 ) * amp[0];
  FFV1_0( w[52], w[2], w[86], COUPs[1], &amp[0] );
  jamp[9] += cxtype( 0, 1 ) * amp[0];
  jamp[11] -= cxtype( 0, 1 ) * amp[0];
  jamp[51] -= cxtype( 0, 1 ) * amp[0];
  jamp[53] += cxtype( 0, 1 ) * amp[0];
  jamp[91] -= cxtype( 0, 1 ) * amp[0];
  jamp[94] += cxtype( 0, 1 ) * amp[0];
  jamp[115] += cxtype( 0, 1 ) * amp[0];
  jamp[118] -= cxtype( 0, 1 ) * amp[0];

  // *** DIAGRAM 837 OF 1240 ***

  // Wavefunction(s) for diagram number 837
  // (none)

  // Amplitude(s) for diagram number 837
  FFV1_0( w[90], w[2], w[30], COUPs[1], &amp[0] );
  jamp[64] += amp[0];
  jamp[70] -= amp[0];
  jamp[94] -= amp[0];
  jamp[118] += amp[0];
  FFV1_0( w[90], w[2], w[31], COUPs[1], &amp[0] );
  jamp[70] -= amp[0];
  jamp[88] += amp[0];
  jamp[94] -= amp[0];
  jamp[112] += amp[0];
  FFV1_0( w[90], w[2], w[32], COUPs[1], &amp[0] );
  jamp[64] -= amp[0];
  jamp[88] += amp[0];
  jamp[112] += amp[0];
  jamp[118] -= amp[0];

  // *** DIAGRAM 838 OF 1240 ***

  // Wavefunction(s) for diagram number 838
  // (none)

  // Amplitude(s) for diagram number 838
  FFV1_0( w[52], w[2], w[92], COUPs[1], &amp[0] );
  jamp[9] -= cxtype( 0, 1 ) * amp[0];
  jamp[11] += cxtype( 0, 1 ) * amp[0];
  jamp[17] += cxtype( 0, 1 ) * amp[0];
  jamp[23] -= cxtype( 0, 1 ) * amp[0];
  jamp[64] += cxtype( 0, 1 ) * amp[0];
  jamp[70] -= cxtype( 0, 1 ) * amp[0];
  jamp[94] -= cxtype( 0, 1 ) * amp[0];
  jamp[118] += cxtype( 0, 1 ) * amp[0];
  FFV1_0( w[52], w[2], w[88], COUPs[1], &amp[0] );
  jamp[11] += cxtype( 0, 1 ) * amp[0];
  jamp[15] -= cxtype( 0, 1 ) * amp[0];
  jamp[17] += cxtype( 0, 1 ) * amp[0];
  jamp[21] -= cxtype( 0, 1 ) * amp[0];
  jamp[70] -= cxtype( 0, 1 ) * amp[0];
  jamp[88] += cxtype( 0, 1 ) * amp[0];
  jamp[94] -= cxtype( 0, 1 ) * amp[0];
  jamp[112] += cxtype( 0, 1 ) * amp[0];
  FFV1_0( w[52], w[2], w[106], COUPs[1], &amp[0] );
  jamp[9] += cxtype( 0, 1 ) * amp[0];
  jamp[15] -= cxtype( 0, 1 ) * amp[0];
  jamp[21] -= cxtype( 0, 1 ) * amp[0];
  jamp[23] += cxtype( 0, 1 ) * amp[0];
  jamp[64] -= cxtype( 0, 1 ) * amp[0];
  jamp[88] += cxtype( 0, 1 ) * amp[0];
  jamp[112] += cxtype( 0, 1 ) * amp[0];
  jamp[118] -= cxtype( 0, 1 ) * amp[0];

  // *** DIAGRAM 839 OF 1240 ***

  // Wavefunction(s) for diagram number 839
  VVV1P0_1( w[0], w[61], COUPs[0], 0., 0., w[90] );

  // Amplitude(s) for diagram number 839
  VVV1_0( w[90], w[10], w[6], COUPs[0], &amp[0] );
#ifdef MGONGPU_SUPPORTS_MULTICHANNEL
  if( channelId == 839 ) allNumerators[0] += cxabs2( amp[0] );
  if( channelId != 0 ) allDenominators[0] += cxabs2( amp[0] );
#endif
  jamp[1] -= amp[0];
  jamp[7] += amp[0];
  jamp[31] += amp[0];
  jamp[55] -= amp[0];
  jamp[72] += amp[0];
  jamp[74] -= amp[0];
  jamp[80] -= amp[0];
  jamp[86] += amp[0];
  jamp[90] -= amp[0];
  jamp[91] += amp[0];
  jamp[93] += amp[0];
  jamp[95] -= amp[0];
  jamp[96] += amp[0];
  jamp[98] -= amp[0];
  jamp[104] -= amp[0];
  jamp[110] += amp[0];

  // *** DIAGRAM 840 OF 1240 ***

  // Wavefunction(s) for diagram number 840
  // (none)

  // Amplitude(s) for diagram number 840
  VVV1_0( w[90], w[11], w[5], COUPs[0], &amp[0] );
#ifdef MGONGPU_SUPPORTS_MULTICHANNEL
  if( channelId == 840 ) allNumerators[0] += cxabs2( amp[0] );
  if( channelId != 0 ) allDenominators[0] += cxabs2( amp[0] );
#endif
  jamp[0] -= amp[0];
  jamp[6] += amp[0];
  jamp[30] += amp[0];
  jamp[54] -= amp[0];
  jamp[72] += amp[0];
  jamp[74] -= amp[0];
  jamp[80] -= amp[0];
  jamp[86] += amp[0];
  jamp[96] += amp[0];
  jamp[98] -= amp[0];
  jamp[104] -= amp[0];
  jamp[110] += amp[0];
  jamp[114] -= amp[0];
  jamp[115] += amp[0];
  jamp[117] += amp[0];
  jamp[119] -= amp[0];

  // *** DIAGRAM 841 OF 1240 ***

  // Wavefunction(s) for diagram number 841
  // (none)

  // Amplitude(s) for diagram number 841
  VVVV1_0( w[8], w[5], w[6], w[90], COUPs[2], &amp[0] );
  jamp[1] -= amp[0];
  jamp[7] += amp[0];
  jamp[31] += amp[0];
  jamp[55] -= amp[0];
  jamp[72] += amp[0];
  jamp[74] -= amp[0];
  jamp[80] -= amp[0];
  jamp[86] += amp[0];
  jamp[90] -= amp[0];
  jamp[91] += amp[0];
  jamp[93] += amp[0];
  jamp[95] -= amp[0];
  jamp[96] += amp[0];
  jamp[98] -= amp[0];
  jamp[104] -= amp[0];
  jamp[110] += amp[0];
  VVVV3_0( w[8], w[5], w[6], w[90], COUPs[2], &amp[0] );
  jamp[0] -= amp[0];
  jamp[6] += amp[0];
  jamp[30] += amp[0];
  jamp[54] -= amp[0];
  jamp[72] += amp[0];
  jamp[74] -= amp[0];
  jamp[80] -= amp[0];
  jamp[86] += amp[0];
  jamp[96] += amp[0];
  jamp[98] -= amp[0];
  jamp[104] -= amp[0];
  jamp[110] += amp[0];
  jamp[114] -= amp[0];
  jamp[115] += amp[0];
  jamp[117] += amp[0];
  jamp[119] -= amp[0];
  VVVV4_0( w[8], w[5], w[6], w[90], COUPs[2], &amp[0] );
  jamp[0] -= amp[0];
  jamp[1] += amp[0];
  jamp[6] += amp[0];
  jamp[7] -= amp[0];
  jamp[30] += amp[0];
  jamp[31] -= amp[0];
  jamp[54] -= amp[0];
  jamp[55] += amp[0];
  jamp[90] += amp[0];
  jamp[91] -= amp[0];
  jamp[93] -= amp[0];
  jamp[95] += amp[0];
  jamp[114] -= amp[0];
  jamp[115] += amp[0];
  jamp[117] += amp[0];
  jamp[119] -= amp[0];

  // *** DIAGRAM 842 OF 1240 ***

  // Wavefunction(s) for diagram number 842
  VVV1P0_1( w[0], w[8], COUPs[0], 0., 0., w[56] );

  // Amplitude(s) for diagram number 842
  VVV1_0( w[56], w[63], w[6], COUPs[0], &amp[0] );
#ifdef MGONGPU_SUPPORTS_MULTICHANNEL
  if( channelId == 842 ) allNumerators[0] += cxabs2( amp[0] );
  if( channelId != 0 ) allDenominators[0] += cxabs2( amp[0] );
#endif
  jamp[0] += amp[0];
  jamp[6] -= amp[0];
  jamp[12] -= amp[0];
  jamp[14] += amp[0];
  jamp[18] -= amp[0];
  jamp[20] += amp[0];
  jamp[22] += amp[0];
  jamp[23] -= amp[0];
  jamp[33] -= amp[0];
  jamp[57] += amp[0];
  jamp[81] += amp[0];
  jamp[87] -= amp[0];
  jamp[105] += amp[0];
  jamp[111] -= amp[0];
  jamp[117] -= amp[0];
  jamp[119] += amp[0];

  // *** DIAGRAM 843 OF 1240 ***

  // Wavefunction(s) for diagram number 843
  // (none)

  // Amplitude(s) for diagram number 843
  VVV1_0( w[56], w[64], w[5], COUPs[0], &amp[0] );
#ifdef MGONGPU_SUPPORTS_MULTICHANNEL
  if( channelId == 843 ) allNumerators[0] += cxabs2( amp[0] );
  if( channelId != 0 ) allDenominators[0] += cxabs2( amp[0] );
#endif
  jamp[1] += amp[0];
  jamp[7] -= amp[0];
  jamp[12] -= amp[0];
  jamp[14] += amp[0];
  jamp[16] += amp[0];
  jamp[17] -= amp[0];
  jamp[18] -= amp[0];
  jamp[20] += amp[0];
  jamp[35] -= amp[0];
  jamp[59] += amp[0];
  jamp[81] += amp[0];
  jamp[87] -= amp[0];
  jamp[93] -= amp[0];
  jamp[95] += amp[0];
  jamp[105] += amp[0];
  jamp[111] -= amp[0];

  // *** DIAGRAM 844 OF 1240 ***

  // Wavefunction(s) for diagram number 844
  // (none)

  // Amplitude(s) for diagram number 844
  VVVV1_0( w[61], w[5], w[6], w[56], COUPs[2], &amp[0] );
  jamp[0] += amp[0];
  jamp[6] -= amp[0];
  jamp[12] -= amp[0];
  jamp[14] += amp[0];
  jamp[18] -= amp[0];
  jamp[20] += amp[0];
  jamp[22] += amp[0];
  jamp[23] -= amp[0];
  jamp[33] -= amp[0];
  jamp[57] += amp[0];
  jamp[81] += amp[0];
  jamp[87] -= amp[0];
  jamp[105] += amp[0];
  jamp[111] -= amp[0];
  jamp[117] -= amp[0];
  jamp[119] += amp[0];
  VVVV3_0( w[61], w[5], w[6], w[56], COUPs[2], &amp[0] );
  jamp[1] += amp[0];
  jamp[7] -= amp[0];
  jamp[12] -= amp[0];
  jamp[14] += amp[0];
  jamp[16] += amp[0];
  jamp[17] -= amp[0];
  jamp[18] -= amp[0];
  jamp[20] += amp[0];
  jamp[35] -= amp[0];
  jamp[59] += amp[0];
  jamp[81] += amp[0];
  jamp[87] -= amp[0];
  jamp[93] -= amp[0];
  jamp[95] += amp[0];
  jamp[105] += amp[0];
  jamp[111] -= amp[0];
  VVVV4_0( w[61], w[5], w[6], w[56], COUPs[2], &amp[0] );
  jamp[0] -= amp[0];
  jamp[1] += amp[0];
  jamp[6] += amp[0];
  jamp[7] -= amp[0];
  jamp[16] += amp[0];
  jamp[17] -= amp[0];
  jamp[22] -= amp[0];
  jamp[23] += amp[0];
  jamp[33] += amp[0];
  jamp[35] -= amp[0];
  jamp[57] -= amp[0];
  jamp[59] += amp[0];
  jamp[93] -= amp[0];
  jamp[95] += amp[0];
  jamp[117] += amp[0];
  jamp[119] -= amp[0];

  // *** DIAGRAM 845 OF 1240 ***

  // Wavefunction(s) for diagram number 845
  // (none)

  // Amplitude(s) for diagram number 845
  VVV1_0( w[0], w[63], w[11], COUPs[0], &amp[0] );
#ifdef MGONGPU_SUPPORTS_MULTICHANNEL
  if( channelId == 845 ) allNumerators[0] += cxabs2( amp[0] );
  if( channelId != 0 ) allDenominators[0] += cxabs2( amp[0] );
#endif
  jamp[0] += amp[0];
  jamp[6] -= amp[0];
  jamp[12] -= amp[0];
  jamp[14] += amp[0];
  jamp[32] -= amp[0];
  jamp[56] += amp[0];
  jamp[80] += amp[0];
  jamp[86] -= amp[0];
  jamp[96] -= amp[0];
  jamp[98] += amp[0];
  jamp[100] += amp[0];
  jamp[101] -= amp[0];
  jamp[105] += amp[0];
  jamp[111] -= amp[0];
  jamp[117] -= amp[0];
  jamp[119] += amp[0];

  // *** DIAGRAM 846 OF 1240 ***

  // Wavefunction(s) for diagram number 846
  // (none)

  // Amplitude(s) for diagram number 846
  VVV1_0( w[0], w[64], w[10], COUPs[0], &amp[0] );
#ifdef MGONGPU_SUPPORTS_MULTICHANNEL
  if( channelId == 846 ) allNumerators[0] += cxabs2( amp[0] );
  if( channelId != 0 ) allDenominators[0] += cxabs2( amp[0] );
#endif
  jamp[1] += amp[0];
  jamp[7] -= amp[0];
  jamp[18] -= amp[0];
  jamp[20] += amp[0];
  jamp[34] -= amp[0];
  jamp[58] += amp[0];
  jamp[72] -= amp[0];
  jamp[74] += amp[0];
  jamp[76] += amp[0];
  jamp[77] -= amp[0];
  jamp[81] += amp[0];
  jamp[87] -= amp[0];
  jamp[93] -= amp[0];
  jamp[95] += amp[0];
  jamp[104] += amp[0];
  jamp[110] -= amp[0];

  // *** DIAGRAM 847 OF 1240 ***

  // Wavefunction(s) for diagram number 847
  VVVV1P0_1( w[0], w[61], w[5], COUPs[2], 0., 0., w[103] );
  VVVV3P0_1( w[0], w[61], w[5], COUPs[2], 0., 0., w[22] );
  VVVV4P0_1( w[0], w[61], w[5], COUPs[2], 0., 0., w[21] );

  // Amplitude(s) for diagram number 847
  VVV1_0( w[8], w[6], w[103], COUPs[0], &amp[0] );
  jamp[0] += amp[0];
  jamp[6] -= amp[0];
  jamp[12] -= amp[0];
  jamp[14] += amp[0];
  jamp[32] -= amp[0];
  jamp[56] += amp[0];
  jamp[80] += amp[0];
  jamp[86] -= amp[0];
  jamp[96] -= amp[0];
  jamp[98] += amp[0];
  jamp[100] += amp[0];
  jamp[101] -= amp[0];
  jamp[105] += amp[0];
  jamp[111] -= amp[0];
  jamp[117] -= amp[0];
  jamp[119] += amp[0];
  VVV1_0( w[8], w[6], w[22], COUPs[0], &amp[0] );
  jamp[12] -= amp[0];
  jamp[14] += amp[0];
  jamp[30] += amp[0];
  jamp[32] -= amp[0];
  jamp[54] -= amp[0];
  jamp[56] += amp[0];
  jamp[72] += amp[0];
  jamp[74] -= amp[0];
  jamp[100] += amp[0];
  jamp[101] -= amp[0];
  jamp[104] -= amp[0];
  jamp[105] += amp[0];
  jamp[110] += amp[0];
  jamp[111] -= amp[0];
  jamp[114] -= amp[0];
  jamp[115] += amp[0];
  VVV1_0( w[8], w[6], w[21], COUPs[0], &amp[0] );
  jamp[0] -= amp[0];
  jamp[6] += amp[0];
  jamp[30] += amp[0];
  jamp[54] -= amp[0];
  jamp[72] += amp[0];
  jamp[74] -= amp[0];
  jamp[80] -= amp[0];
  jamp[86] += amp[0];
  jamp[96] += amp[0];
  jamp[98] -= amp[0];
  jamp[104] -= amp[0];
  jamp[110] += amp[0];
  jamp[114] -= amp[0];
  jamp[115] += amp[0];
  jamp[117] += amp[0];
  jamp[119] -= amp[0];

  // *** DIAGRAM 848 OF 1240 ***

  // Wavefunction(s) for diagram number 848
  VVVV1P0_1( w[0], w[61], w[6], COUPs[2], 0., 0., w[105] );
  VVVV3P0_1( w[0], w[61], w[6], COUPs[2], 0., 0., w[95] );
  VVVV4P0_1( w[0], w[61], w[6], COUPs[2], 0., 0., w[107] );

  // Amplitude(s) for diagram number 848
  VVV1_0( w[8], w[5], w[105], COUPs[0], &amp[0] );
  jamp[1] += amp[0];
  jamp[7] -= amp[0];
  jamp[18] -= amp[0];
  jamp[20] += amp[0];
  jamp[34] -= amp[0];
  jamp[58] += amp[0];
  jamp[72] -= amp[0];
  jamp[74] += amp[0];
  jamp[76] += amp[0];
  jamp[77] -= amp[0];
  jamp[81] += amp[0];
  jamp[87] -= amp[0];
  jamp[93] -= amp[0];
  jamp[95] += amp[0];
  jamp[104] += amp[0];
  jamp[110] -= amp[0];
  VVV1_0( w[8], w[5], w[95], COUPs[0], &amp[0] );
  jamp[18] -= amp[0];
  jamp[20] += amp[0];
  jamp[31] += amp[0];
  jamp[34] -= amp[0];
  jamp[55] -= amp[0];
  jamp[58] += amp[0];
  jamp[76] += amp[0];
  jamp[77] -= amp[0];
  jamp[80] -= amp[0];
  jamp[81] += amp[0];
  jamp[86] += amp[0];
  jamp[87] -= amp[0];
  jamp[90] -= amp[0];
  jamp[91] += amp[0];
  jamp[96] += amp[0];
  jamp[98] -= amp[0];
  VVV1_0( w[8], w[5], w[107], COUPs[0], &amp[0] );
  jamp[1] -= amp[0];
  jamp[7] += amp[0];
  jamp[31] += amp[0];
  jamp[55] -= amp[0];
  jamp[72] += amp[0];
  jamp[74] -= amp[0];
  jamp[80] -= amp[0];
  jamp[86] += amp[0];
  jamp[90] -= amp[0];
  jamp[91] += amp[0];
  jamp[93] += amp[0];
  jamp[95] -= amp[0];
  jamp[96] += amp[0];
  jamp[98] -= amp[0];
  jamp[104] -= amp[0];
  jamp[110] += amp[0];

  // *** DIAGRAM 849 OF 1240 ***

  // Wavefunction(s) for diagram number 849
  VVVV1P0_1( w[0], w[8], w[5], COUPs[2], 0., 0., w[115] );
  VVVV3P0_1( w[0], w[8], w[5], COUPs[2], 0., 0., w[116] );
  VVVV4P0_1( w[0], w[8], w[5], COUPs[2], 0., 0., w[117] );

  // Amplitude(s) for diagram number 849
  VVV1_0( w[61], w[6], w[115], COUPs[0], &amp[0] );
  jamp[1] -= amp[0];
  jamp[7] += amp[0];
  jamp[18] += amp[0];
  jamp[20] -= amp[0];
  jamp[34] += amp[0];
  jamp[58] -= amp[0];
  jamp[72] += amp[0];
  jamp[74] -= amp[0];
  jamp[76] -= amp[0];
  jamp[77] += amp[0];
  jamp[81] -= amp[0];
  jamp[87] += amp[0];
  jamp[93] += amp[0];
  jamp[95] -= amp[0];
  jamp[104] -= amp[0];
  jamp[110] += amp[0];
  VVV1_0( w[61], w[6], w[116], COUPs[0], &amp[0] );
  jamp[12] -= amp[0];
  jamp[14] += amp[0];
  jamp[16] += amp[0];
  jamp[17] -= amp[0];
  jamp[34] += amp[0];
  jamp[35] -= amp[0];
  jamp[58] -= amp[0];
  jamp[59] += amp[0];
  jamp[72] += amp[0];
  jamp[74] -= amp[0];
  jamp[76] -= amp[0];
  jamp[77] += amp[0];
  jamp[104] -= amp[0];
  jamp[105] += amp[0];
  jamp[110] += amp[0];
  jamp[111] -= amp[0];
  VVV1_0( w[61], w[6], w[117], COUPs[0], &amp[0] );
  jamp[1] += amp[0];
  jamp[7] -= amp[0];
  jamp[12] -= amp[0];
  jamp[14] += amp[0];
  jamp[16] += amp[0];
  jamp[17] -= amp[0];
  jamp[18] -= amp[0];
  jamp[20] += amp[0];
  jamp[35] -= amp[0];
  jamp[59] += amp[0];
  jamp[81] += amp[0];
  jamp[87] -= amp[0];
  jamp[93] -= amp[0];
  jamp[95] += amp[0];
  jamp[105] += amp[0];
  jamp[111] -= amp[0];

  // *** DIAGRAM 850 OF 1240 ***

  // Wavefunction(s) for diagram number 850
  VVVV1P0_1( w[0], w[8], w[6], COUPs[2], 0., 0., w[118] );
  VVVV3P0_1( w[0], w[8], w[6], COUPs[2], 0., 0., w[119] );
  VVVV4P0_1( w[0], w[8], w[6], COUPs[2], 0., 0., w[120] );

  // Amplitude(s) for diagram number 850
  VVV1_0( w[61], w[5], w[118], COUPs[0], &amp[0] );
  jamp[0] -= amp[0];
  jamp[6] += amp[0];
  jamp[12] += amp[0];
  jamp[14] -= amp[0];
  jamp[32] += amp[0];
  jamp[56] -= amp[0];
  jamp[80] -= amp[0];
  jamp[86] += amp[0];
  jamp[96] += amp[0];
  jamp[98] -= amp[0];
  jamp[100] -= amp[0];
  jamp[101] += amp[0];
  jamp[105] -= amp[0];
  jamp[111] += amp[0];
  jamp[117] += amp[0];
  jamp[119] -= amp[0];
  VVV1_0( w[61], w[5], w[119], COUPs[0], &amp[0] );
  jamp[18] -= amp[0];
  jamp[20] += amp[0];
  jamp[22] += amp[0];
  jamp[23] -= amp[0];
  jamp[32] += amp[0];
  jamp[33] -= amp[0];
  jamp[56] -= amp[0];
  jamp[57] += amp[0];
  jamp[80] -= amp[0];
  jamp[81] += amp[0];
  jamp[86] += amp[0];
  jamp[87] -= amp[0];
  jamp[96] += amp[0];
  jamp[98] -= amp[0];
  jamp[100] -= amp[0];
  jamp[101] += amp[0];
  VVV1_0( w[61], w[5], w[120], COUPs[0], &amp[0] );
  jamp[0] += amp[0];
  jamp[6] -= amp[0];
  jamp[12] -= amp[0];
  jamp[14] += amp[0];
  jamp[18] -= amp[0];
  jamp[20] += amp[0];
  jamp[22] += amp[0];
  jamp[23] -= amp[0];
  jamp[33] -= amp[0];
  jamp[57] += amp[0];
  jamp[81] += amp[0];
  jamp[87] -= amp[0];
  jamp[105] += amp[0];
  jamp[111] -= amp[0];
  jamp[117] -= amp[0];
  jamp[119] += amp[0];

  // *** DIAGRAM 851 OF 1240 ***

  // Wavefunction(s) for diagram number 851
  // (none)

  // Amplitude(s) for diagram number 851
  VVVV1_0( w[0], w[61], w[8], w[29], COUPs[2], &amp[0] );
  jamp[0] += amp[0];
  jamp[1] -= amp[0];
  jamp[6] -= amp[0];
  jamp[7] += amp[0];
  jamp[30] -= amp[0];
  jamp[31] += amp[0];
  jamp[54] += amp[0];
  jamp[55] -= amp[0];
  jamp[90] -= amp[0];
  jamp[91] += amp[0];
  jamp[93] += amp[0];
  jamp[95] -= amp[0];
  jamp[114] += amp[0];
  jamp[115] -= amp[0];
  jamp[117] -= amp[0];
  jamp[119] += amp[0];
  VVVV3_0( w[0], w[61], w[8], w[29], COUPs[2], &amp[0] );
  jamp[0] += amp[0];
  jamp[1] -= amp[0];
  jamp[6] -= amp[0];
  jamp[7] += amp[0];
  jamp[16] -= amp[0];
  jamp[17] += amp[0];
  jamp[22] += amp[0];
  jamp[23] -= amp[0];
  jamp[33] -= amp[0];
  jamp[35] += amp[0];
  jamp[57] += amp[0];
  jamp[59] -= amp[0];
  jamp[93] += amp[0];
  jamp[95] -= amp[0];
  jamp[117] -= amp[0];
  jamp[119] += amp[0];
  VVVV4_0( w[0], w[61], w[8], w[29], COUPs[2], &amp[0] );
  jamp[16] -= amp[0];
  jamp[17] += amp[0];
  jamp[22] += amp[0];
  jamp[23] -= amp[0];
  jamp[30] += amp[0];
  jamp[31] -= amp[0];
  jamp[33] -= amp[0];
  jamp[35] += amp[0];
  jamp[54] -= amp[0];
  jamp[55] += amp[0];
  jamp[57] += amp[0];
  jamp[59] -= amp[0];
  jamp[90] += amp[0];
  jamp[91] -= amp[0];
  jamp[114] -= amp[0];
  jamp[115] += amp[0];

  // *** DIAGRAM 852 OF 1240 ***

  // Wavefunction(s) for diagram number 852
  // (none)

  // Amplitude(s) for diagram number 852
  VVV1_0( w[8], w[29], w[90], COUPs[0], &amp[0] );
#ifdef MGONGPU_SUPPORTS_MULTICHANNEL
  if( channelId == 852 ) allNumerators[0] += cxabs2( amp[0] );
  if( channelId != 0 ) allDenominators[0] += cxabs2( amp[0] );
#endif
  jamp[0] += amp[0];
  jamp[1] -= amp[0];
  jamp[6] -= amp[0];
  jamp[7] += amp[0];
  jamp[30] -= amp[0];
  jamp[31] += amp[0];
  jamp[54] += amp[0];
  jamp[55] -= amp[0];
  jamp[90] -= amp[0];
  jamp[91] += amp[0];
  jamp[93] += amp[0];
  jamp[95] -= amp[0];
  jamp[114] += amp[0];
  jamp[115] -= amp[0];
  jamp[117] -= amp[0];
  jamp[119] += amp[0];

  // *** DIAGRAM 853 OF 1240 ***

  // Wavefunction(s) for diagram number 853
  // (none)

  // Amplitude(s) for diagram number 853
  VVV1_0( w[61], w[29], w[56], COUPs[0], &amp[0] );
#ifdef MGONGPU_SUPPORTS_MULTICHANNEL
  if( channelId == 853 ) allNumerators[0] += cxabs2( amp[0] );
  if( channelId != 0 ) allDenominators[0] += cxabs2( amp[0] );
#endif
  jamp[0] += amp[0];
  jamp[1] -= amp[0];
  jamp[6] -= amp[0];
  jamp[7] += amp[0];
  jamp[16] -= amp[0];
  jamp[17] += amp[0];
  jamp[22] += amp[0];
  jamp[23] -= amp[0];
  jamp[33] -= amp[0];
  jamp[35] += amp[0];
  jamp[57] += amp[0];
  jamp[59] -= amp[0];
  jamp[93] += amp[0];
  jamp[95] -= amp[0];
  jamp[117] -= amp[0];
  jamp[119] += amp[0];

  // *** DIAGRAM 854 OF 1240 ***

  // Wavefunction(s) for diagram number 854
  // (none)

  // Amplitude(s) for diagram number 854
  VVV1_0( w[61], w[8], w[96], COUPs[0], &amp[0] );
#ifdef MGONGPU_SUPPORTS_MULTICHANNEL
  if( channelId == 854 ) allNumerators[0] += cxabs2( amp[0] );
  if( channelId != 0 ) allDenominators[0] += cxabs2( amp[0] );
#endif
  jamp[16] -= amp[0];
  jamp[17] += amp[0];
  jamp[22] += amp[0];
  jamp[23] -= amp[0];
  jamp[30] += amp[0];
  jamp[31] -= amp[0];
  jamp[33] -= amp[0];
  jamp[35] += amp[0];
  jamp[54] -= amp[0];
  jamp[55] += amp[0];
  jamp[57] += amp[0];
  jamp[59] -= amp[0];
  jamp[90] += amp[0];
  jamp[91] -= amp[0];
  jamp[114] -= amp[0];
  jamp[115] += amp[0];

  // *** DIAGRAM 855 OF 1240 ***

  // Wavefunction(s) for diagram number 855
  // (none)

  // Amplitude(s) for diagram number 855
  VVV1_0( w[90], w[45], w[6], COUPs[0], &amp[0] );
#ifdef MGONGPU_SUPPORTS_MULTICHANNEL
  if( channelId == 855 ) allNumerators[0] += cxabs2( amp[0] );
  if( channelId != 0 ) allDenominators[0] += cxabs2( amp[0] );
#endif
  jamp[72] += cxtype( 0, 1 ) * amp[0];
  jamp[74] -= cxtype( 0, 1 ) * amp[0];
  jamp[80] -= cxtype( 0, 1 ) * amp[0];
  jamp[86] += cxtype( 0, 1 ) * amp[0];
  jamp[90] -= cxtype( 0, 1 ) * amp[0];
  jamp[91] += cxtype( 0, 1 ) * amp[0];
  jamp[93] += cxtype( 0, 1 ) * amp[0];
  jamp[95] -= cxtype( 0, 1 ) * amp[0];

  // *** DIAGRAM 856 OF 1240 ***

  // Wavefunction(s) for diagram number 856
  // (none)

  // Amplitude(s) for diagram number 856
  FFV1_0( w[3], w[44], w[90], COUPs[1], &amp[0] );
#ifdef MGONGPU_SUPPORTS_MULTICHANNEL
  if( channelId == 856 ) allNumerators[0] += cxabs2( amp[0] );
  if( channelId != 0 ) allDenominators[0] += cxabs2( amp[0] );
#endif
  jamp[90] += amp[0];
  jamp[91] -= amp[0];
  jamp[93] -= amp[0];
  jamp[95] += amp[0];

  // *** DIAGRAM 857 OF 1240 ***

  // Wavefunction(s) for diagram number 857
  // (none)

  // Amplitude(s) for diagram number 857
  FFV1_0( w[65], w[102], w[6], COUPs[1], &amp[0] );
#ifdef MGONGPU_SUPPORTS_MULTICHANNEL
  if( channelId == 857 ) allNumerators[0] += cxabs2( amp[0] );
  if( channelId != 0 ) allDenominators[0] += cxabs2( amp[0] );
#endif
  jamp[76] += cxtype( 0, 1 ) * amp[0];
  jamp[77] -= cxtype( 0, 1 ) * amp[0];

  // *** DIAGRAM 858 OF 1240 ***

  // Wavefunction(s) for diagram number 858
  // (none)

  // Amplitude(s) for diagram number 858
  FFV1_0( w[3], w[102], w[64], COUPs[1], &amp[0] );
#ifdef MGONGPU_SUPPORTS_MULTICHANNEL
  if( channelId == 858 ) allNumerators[0] += cxabs2( amp[0] );
  if( channelId != 0 ) allDenominators[0] += cxabs2( amp[0] );
#endif
  jamp[72] += amp[0];
  jamp[74] -= amp[0];
  jamp[76] -= amp[0];
  jamp[77] += amp[0];

  // *** DIAGRAM 859 OF 1240 ***

  // Wavefunction(s) for diagram number 859
  // (none)

  // Amplitude(s) for diagram number 859
  FFV1_0( w[65], w[44], w[0], COUPs[1], &amp[0] );
#ifdef MGONGPU_SUPPORTS_MULTICHANNEL
  if( channelId == 859 ) allNumerators[0] += cxabs2( amp[0] );
  if( channelId != 0 ) allDenominators[0] += cxabs2( amp[0] );
#endif
  jamp[90] += cxtype( 0, 1 ) * amp[0];
  jamp[91] -= cxtype( 0, 1 ) * amp[0];

  // *** DIAGRAM 860 OF 1240 ***

  // Wavefunction(s) for diagram number 860
  // (none)

  // Amplitude(s) for diagram number 860
  VVV1_0( w[0], w[64], w[45], COUPs[0], &amp[0] );
#ifdef MGONGPU_SUPPORTS_MULTICHANNEL
  if( channelId == 860 ) allNumerators[0] += cxabs2( amp[0] );
  if( channelId != 0 ) allDenominators[0] += cxabs2( amp[0] );
#endif
  jamp[72] -= cxtype( 0, 1 ) * amp[0];
  jamp[74] += cxtype( 0, 1 ) * amp[0];
  jamp[76] += cxtype( 0, 1 ) * amp[0];
  jamp[77] -= cxtype( 0, 1 ) * amp[0];
  jamp[81] += cxtype( 0, 1 ) * amp[0];
  jamp[87] -= cxtype( 0, 1 ) * amp[0];
  jamp[93] -= cxtype( 0, 1 ) * amp[0];
  jamp[95] += cxtype( 0, 1 ) * amp[0];

  // *** DIAGRAM 861 OF 1240 ***

  // Wavefunction(s) for diagram number 861
  // (none)

  // Amplitude(s) for diagram number 861
  FFV1_0( w[3], w[39], w[105], COUPs[1], &amp[0] );
  jamp[72] -= cxtype( 0, 1 ) * amp[0];
  jamp[74] += cxtype( 0, 1 ) * amp[0];
  jamp[76] += cxtype( 0, 1 ) * amp[0];
  jamp[77] -= cxtype( 0, 1 ) * amp[0];
  jamp[81] += cxtype( 0, 1 ) * amp[0];
  jamp[87] -= cxtype( 0, 1 ) * amp[0];
  jamp[93] -= cxtype( 0, 1 ) * amp[0];
  jamp[95] += cxtype( 0, 1 ) * amp[0];
  FFV1_0( w[3], w[39], w[95], COUPs[1], &amp[0] );
  jamp[76] += cxtype( 0, 1 ) * amp[0];
  jamp[77] -= cxtype( 0, 1 ) * amp[0];
  jamp[80] -= cxtype( 0, 1 ) * amp[0];
  jamp[81] += cxtype( 0, 1 ) * amp[0];
  jamp[86] += cxtype( 0, 1 ) * amp[0];
  jamp[87] -= cxtype( 0, 1 ) * amp[0];
  jamp[90] -= cxtype( 0, 1 ) * amp[0];
  jamp[91] += cxtype( 0, 1 ) * amp[0];
  FFV1_0( w[3], w[39], w[107], COUPs[1], &amp[0] );
  jamp[72] += cxtype( 0, 1 ) * amp[0];
  jamp[74] -= cxtype( 0, 1 ) * amp[0];
  jamp[80] -= cxtype( 0, 1 ) * amp[0];
  jamp[86] += cxtype( 0, 1 ) * amp[0];
  jamp[90] -= cxtype( 0, 1 ) * amp[0];
  jamp[91] += cxtype( 0, 1 ) * amp[0];
  jamp[93] += cxtype( 0, 1 ) * amp[0];
  jamp[95] -= cxtype( 0, 1 ) * amp[0];

  // *** DIAGRAM 862 OF 1240 ***

  // Wavefunction(s) for diagram number 862
  // (none)

  // Amplitude(s) for diagram number 862
  FFV1_0( w[41], w[39], w[90], COUPs[1], &amp[0] );
#ifdef MGONGPU_SUPPORTS_MULTICHANNEL
  if( channelId == 862 ) allNumerators[0] += cxabs2( amp[0] );
  if( channelId != 0 ) allDenominators[0] += cxabs2( amp[0] );
#endif
  jamp[72] += amp[0];
  jamp[74] -= amp[0];
  jamp[80] -= amp[0];
  jamp[86] += amp[0];

  // *** DIAGRAM 863 OF 1240 ***

  // Wavefunction(s) for diagram number 863
  // (none)

  // Amplitude(s) for diagram number 863
  FFV1_0( w[41], w[102], w[61], COUPs[1], &amp[0] );
#ifdef MGONGPU_SUPPORTS_MULTICHANNEL
  if( channelId == 863 ) allNumerators[0] += cxabs2( amp[0] );
  if( channelId != 0 ) allDenominators[0] += cxabs2( amp[0] );
#endif
  jamp[72] += cxtype( 0, 1 ) * amp[0];
  jamp[74] -= cxtype( 0, 1 ) * amp[0];

  // *** DIAGRAM 864 OF 1240 ***

  // Wavefunction(s) for diagram number 864
  // (none)

  // Amplitude(s) for diagram number 864
  FFV1_0( w[62], w[39], w[61], COUPs[1], &amp[0] );
#ifdef MGONGPU_SUPPORTS_MULTICHANNEL
  if( channelId == 864 ) allNumerators[0] += cxabs2( amp[0] );
  if( channelId != 0 ) allDenominators[0] += cxabs2( amp[0] );
#endif
  jamp[80] += cxtype( 0, 1 ) * amp[0];
  jamp[86] -= cxtype( 0, 1 ) * amp[0];

  // *** DIAGRAM 865 OF 1240 ***

  // Wavefunction(s) for diagram number 865
  // (none)

  // Amplitude(s) for diagram number 865
  VVV1_0( w[90], w[51], w[5], COUPs[0], &amp[0] );
#ifdef MGONGPU_SUPPORTS_MULTICHANNEL
  if( channelId == 865 ) allNumerators[0] += cxabs2( amp[0] );
  if( channelId != 0 ) allDenominators[0] += cxabs2( amp[0] );
#endif
  jamp[96] += cxtype( 0, 1 ) * amp[0];
  jamp[98] -= cxtype( 0, 1 ) * amp[0];
  jamp[104] -= cxtype( 0, 1 ) * amp[0];
  jamp[110] += cxtype( 0, 1 ) * amp[0];
  jamp[114] -= cxtype( 0, 1 ) * amp[0];
  jamp[115] += cxtype( 0, 1 ) * amp[0];
  jamp[117] += cxtype( 0, 1 ) * amp[0];
  jamp[119] -= cxtype( 0, 1 ) * amp[0];

  // *** DIAGRAM 866 OF 1240 ***

  // Wavefunction(s) for diagram number 866
  // (none)

  // Amplitude(s) for diagram number 866
  FFV1_0( w[3], w[50], w[90], COUPs[1], &amp[0] );
#ifdef MGONGPU_SUPPORTS_MULTICHANNEL
  if( channelId == 866 ) allNumerators[0] += cxabs2( amp[0] );
  if( channelId != 0 ) allDenominators[0] += cxabs2( amp[0] );
#endif
  jamp[114] += amp[0];
  jamp[115] -= amp[0];
  jamp[117] -= amp[0];
  jamp[119] += amp[0];

  // *** DIAGRAM 867 OF 1240 ***

  // Wavefunction(s) for diagram number 867
  // (none)

  // Amplitude(s) for diagram number 867
  FFV1_0( w[65], w[113], w[5], COUPs[1], &amp[0] );
#ifdef MGONGPU_SUPPORTS_MULTICHANNEL
  if( channelId == 867 ) allNumerators[0] += cxabs2( amp[0] );
  if( channelId != 0 ) allDenominators[0] += cxabs2( amp[0] );
#endif
  jamp[100] += cxtype( 0, 1 ) * amp[0];
  jamp[101] -= cxtype( 0, 1 ) * amp[0];

  // *** DIAGRAM 868 OF 1240 ***

  // Wavefunction(s) for diagram number 868
  // (none)

  // Amplitude(s) for diagram number 868
  FFV1_0( w[3], w[113], w[63], COUPs[1], &amp[0] );
#ifdef MGONGPU_SUPPORTS_MULTICHANNEL
  if( channelId == 868 ) allNumerators[0] += cxabs2( amp[0] );
  if( channelId != 0 ) allDenominators[0] += cxabs2( amp[0] );
#endif
  jamp[96] += amp[0];
  jamp[98] -= amp[0];
  jamp[100] -= amp[0];
  jamp[101] += amp[0];

  // *** DIAGRAM 869 OF 1240 ***

  // Wavefunction(s) for diagram number 869
  // (none)

  // Amplitude(s) for diagram number 869
  FFV1_0( w[65], w[50], w[0], COUPs[1], &amp[0] );
#ifdef MGONGPU_SUPPORTS_MULTICHANNEL
  if( channelId == 869 ) allNumerators[0] += cxabs2( amp[0] );
  if( channelId != 0 ) allDenominators[0] += cxabs2( amp[0] );
#endif
  jamp[114] += cxtype( 0, 1 ) * amp[0];
  jamp[115] -= cxtype( 0, 1 ) * amp[0];

  // *** DIAGRAM 870 OF 1240 ***

  // Wavefunction(s) for diagram number 870
  // (none)

  // Amplitude(s) for diagram number 870
  VVV1_0( w[0], w[63], w[51], COUPs[0], &amp[0] );
#ifdef MGONGPU_SUPPORTS_MULTICHANNEL
  if( channelId == 870 ) allNumerators[0] += cxabs2( amp[0] );
  if( channelId != 0 ) allDenominators[0] += cxabs2( amp[0] );
#endif
  jamp[96] -= cxtype( 0, 1 ) * amp[0];
  jamp[98] += cxtype( 0, 1 ) * amp[0];
  jamp[100] += cxtype( 0, 1 ) * amp[0];
  jamp[101] -= cxtype( 0, 1 ) * amp[0];
  jamp[105] += cxtype( 0, 1 ) * amp[0];
  jamp[111] -= cxtype( 0, 1 ) * amp[0];
  jamp[117] -= cxtype( 0, 1 ) * amp[0];
  jamp[119] += cxtype( 0, 1 ) * amp[0];

  // *** DIAGRAM 871 OF 1240 ***

  // Wavefunction(s) for diagram number 871
  // (none)

  // Amplitude(s) for diagram number 871
  FFV1_0( w[3], w[47], w[103], COUPs[1], &amp[0] );
  jamp[96] -= cxtype( 0, 1 ) * amp[0];
  jamp[98] += cxtype( 0, 1 ) * amp[0];
  jamp[100] += cxtype( 0, 1 ) * amp[0];
  jamp[101] -= cxtype( 0, 1 ) * amp[0];
  jamp[105] += cxtype( 0, 1 ) * amp[0];
  jamp[111] -= cxtype( 0, 1 ) * amp[0];
  jamp[117] -= cxtype( 0, 1 ) * amp[0];
  jamp[119] += cxtype( 0, 1 ) * amp[0];
  FFV1_0( w[3], w[47], w[22], COUPs[1], &amp[0] );
  jamp[100] += cxtype( 0, 1 ) * amp[0];
  jamp[101] -= cxtype( 0, 1 ) * amp[0];
  jamp[104] -= cxtype( 0, 1 ) * amp[0];
  jamp[105] += cxtype( 0, 1 ) * amp[0];
  jamp[110] += cxtype( 0, 1 ) * amp[0];
  jamp[111] -= cxtype( 0, 1 ) * amp[0];
  jamp[114] -= cxtype( 0, 1 ) * amp[0];
  jamp[115] += cxtype( 0, 1 ) * amp[0];
  FFV1_0( w[3], w[47], w[21], COUPs[1], &amp[0] );
  jamp[96] += cxtype( 0, 1 ) * amp[0];
  jamp[98] -= cxtype( 0, 1 ) * amp[0];
  jamp[104] -= cxtype( 0, 1 ) * amp[0];
  jamp[110] += cxtype( 0, 1 ) * amp[0];
  jamp[114] -= cxtype( 0, 1 ) * amp[0];
  jamp[115] += cxtype( 0, 1 ) * amp[0];
  jamp[117] += cxtype( 0, 1 ) * amp[0];
  jamp[119] -= cxtype( 0, 1 ) * amp[0];

  // *** DIAGRAM 872 OF 1240 ***

  // Wavefunction(s) for diagram number 872
  // (none)

  // Amplitude(s) for diagram number 872
  FFV1_0( w[38], w[47], w[90], COUPs[1], &amp[0] );
#ifdef MGONGPU_SUPPORTS_MULTICHANNEL
  if( channelId == 872 ) allNumerators[0] += cxabs2( amp[0] );
  if( channelId != 0 ) allDenominators[0] += cxabs2( amp[0] );
#endif
  jamp[96] += amp[0];
  jamp[98] -= amp[0];
  jamp[104] -= amp[0];
  jamp[110] += amp[0];

  // *** DIAGRAM 873 OF 1240 ***

  // Wavefunction(s) for diagram number 873
  // (none)

  // Amplitude(s) for diagram number 873
  FFV1_0( w[38], w[113], w[61], COUPs[1], &amp[0] );
#ifdef MGONGPU_SUPPORTS_MULTICHANNEL
  if( channelId == 873 ) allNumerators[0] += cxabs2( amp[0] );
  if( channelId != 0 ) allDenominators[0] += cxabs2( amp[0] );
#endif
  jamp[96] += cxtype( 0, 1 ) * amp[0];
  jamp[98] -= cxtype( 0, 1 ) * amp[0];

  // *** DIAGRAM 874 OF 1240 ***

  // Wavefunction(s) for diagram number 874
  // (none)

  // Amplitude(s) for diagram number 874
  FFV1_0( w[104], w[47], w[61], COUPs[1], &amp[0] );
#ifdef MGONGPU_SUPPORTS_MULTICHANNEL
  if( channelId == 874 ) allNumerators[0] += cxabs2( amp[0] );
  if( channelId != 0 ) allDenominators[0] += cxabs2( amp[0] );
#endif
  jamp[104] += cxtype( 0, 1 ) * amp[0];
  jamp[110] -= cxtype( 0, 1 ) * amp[0];

  // *** DIAGRAM 875 OF 1240 ***

  // Wavefunction(s) for diagram number 875
  // (none)

  // Amplitude(s) for diagram number 875
  VVV1_0( w[90], w[23], w[6], COUPs[0], &amp[0] );
#ifdef MGONGPU_SUPPORTS_MULTICHANNEL
  if( channelId == 875 ) allNumerators[0] += cxabs2( amp[0] );
  if( channelId != 0 ) allDenominators[0] += cxabs2( amp[0] );
#endif
  jamp[1] += cxtype( 0, 1 ) * amp[0];
  jamp[7] -= cxtype( 0, 1 ) * amp[0];
  jamp[31] -= cxtype( 0, 1 ) * amp[0];
  jamp[55] += cxtype( 0, 1 ) * amp[0];
  jamp[96] -= cxtype( 0, 1 ) * amp[0];
  jamp[98] += cxtype( 0, 1 ) * amp[0];
  jamp[104] += cxtype( 0, 1 ) * amp[0];
  jamp[110] -= cxtype( 0, 1 ) * amp[0];

  // *** DIAGRAM 876 OF 1240 ***

  // Wavefunction(s) for diagram number 876
  // (none)

  // Amplitude(s) for diagram number 876
  FFV1_0( w[48], w[2], w[90], COUPs[1], &amp[0] );
#ifdef MGONGPU_SUPPORTS_MULTICHANNEL
  if( channelId == 876 ) allNumerators[0] += cxabs2( amp[0] );
  if( channelId != 0 ) allDenominators[0] += cxabs2( amp[0] );
#endif
  jamp[1] += amp[0];
  jamp[7] -= amp[0];
  jamp[31] -= amp[0];
  jamp[55] += amp[0];

  // *** DIAGRAM 877 OF 1240 ***

  // Wavefunction(s) for diagram number 877
  // (none)

  // Amplitude(s) for diagram number 877
  FFV1_0( w[104], w[93], w[6], COUPs[1], &amp[0] );
#ifdef MGONGPU_SUPPORTS_MULTICHANNEL
  if( channelId == 877 ) allNumerators[0] += cxabs2( amp[0] );
  if( channelId != 0 ) allDenominators[0] += cxabs2( amp[0] );
#endif
  jamp[34] += cxtype( 0, 1 ) * amp[0];
  jamp[58] -= cxtype( 0, 1 ) * amp[0];

  // *** DIAGRAM 878 OF 1240 ***

  // Wavefunction(s) for diagram number 878
  // (none)

  // Amplitude(s) for diagram number 878
  FFV1_0( w[104], w[2], w[64], COUPs[1], &amp[0] );
#ifdef MGONGPU_SUPPORTS_MULTICHANNEL
  if( channelId == 878 ) allNumerators[0] += cxabs2( amp[0] );
  if( channelId != 0 ) allDenominators[0] += cxabs2( amp[0] );
#endif
  jamp[34] += amp[0];
  jamp[58] -= amp[0];
  jamp[104] -= amp[0];
  jamp[110] += amp[0];

  // *** DIAGRAM 879 OF 1240 ***

  // Wavefunction(s) for diagram number 879
  // (none)

  // Amplitude(s) for diagram number 879
  FFV1_0( w[48], w[93], w[0], COUPs[1], &amp[0] );
#ifdef MGONGPU_SUPPORTS_MULTICHANNEL
  if( channelId == 879 ) allNumerators[0] += cxabs2( amp[0] );
  if( channelId != 0 ) allDenominators[0] += cxabs2( amp[0] );
#endif
  jamp[31] += cxtype( 0, 1 ) * amp[0];
  jamp[55] -= cxtype( 0, 1 ) * amp[0];

  // *** DIAGRAM 880 OF 1240 ***

  // Wavefunction(s) for diagram number 880
  // (none)

  // Amplitude(s) for diagram number 880
  VVV1_0( w[0], w[64], w[23], COUPs[0], &amp[0] );
#ifdef MGONGPU_SUPPORTS_MULTICHANNEL
  if( channelId == 880 ) allNumerators[0] += cxabs2( amp[0] );
  if( channelId != 0 ) allDenominators[0] += cxabs2( amp[0] );
#endif
  jamp[1] -= cxtype( 0, 1 ) * amp[0];
  jamp[7] += cxtype( 0, 1 ) * amp[0];
  jamp[18] += cxtype( 0, 1 ) * amp[0];
  jamp[20] -= cxtype( 0, 1 ) * amp[0];
  jamp[34] += cxtype( 0, 1 ) * amp[0];
  jamp[58] -= cxtype( 0, 1 ) * amp[0];
  jamp[104] -= cxtype( 0, 1 ) * amp[0];
  jamp[110] += cxtype( 0, 1 ) * amp[0];

  // *** DIAGRAM 881 OF 1240 ***

  // Wavefunction(s) for diagram number 881
  // (none)

  // Amplitude(s) for diagram number 881
  FFV1_0( w[38], w[2], w[105], COUPs[1], &amp[0] );
  jamp[1] -= cxtype( 0, 1 ) * amp[0];
  jamp[7] += cxtype( 0, 1 ) * amp[0];
  jamp[18] += cxtype( 0, 1 ) * amp[0];
  jamp[20] -= cxtype( 0, 1 ) * amp[0];
  jamp[34] += cxtype( 0, 1 ) * amp[0];
  jamp[58] -= cxtype( 0, 1 ) * amp[0];
  jamp[104] -= cxtype( 0, 1 ) * amp[0];
  jamp[110] += cxtype( 0, 1 ) * amp[0];
  FFV1_0( w[38], w[2], w[95], COUPs[1], &amp[0] );
  jamp[18] += cxtype( 0, 1 ) * amp[0];
  jamp[20] -= cxtype( 0, 1 ) * amp[0];
  jamp[31] -= cxtype( 0, 1 ) * amp[0];
  jamp[34] += cxtype( 0, 1 ) * amp[0];
  jamp[55] += cxtype( 0, 1 ) * amp[0];
  jamp[58] -= cxtype( 0, 1 ) * amp[0];
  jamp[96] -= cxtype( 0, 1 ) * amp[0];
  jamp[98] += cxtype( 0, 1 ) * amp[0];
  FFV1_0( w[38], w[2], w[107], COUPs[1], &amp[0] );
  jamp[1] += cxtype( 0, 1 ) * amp[0];
  jamp[7] -= cxtype( 0, 1 ) * amp[0];
  jamp[31] -= cxtype( 0, 1 ) * amp[0];
  jamp[55] += cxtype( 0, 1 ) * amp[0];
  jamp[96] -= cxtype( 0, 1 ) * amp[0];
  jamp[98] += cxtype( 0, 1 ) * amp[0];
  jamp[104] += cxtype( 0, 1 ) * amp[0];
  jamp[110] -= cxtype( 0, 1 ) * amp[0];

  // *** DIAGRAM 882 OF 1240 ***

  // Wavefunction(s) for diagram number 882
  // (none)

  // Amplitude(s) for diagram number 882
  VVV1_0( w[90], w[20], w[5], COUPs[0], &amp[0] );
#ifdef MGONGPU_SUPPORTS_MULTICHANNEL
  if( channelId == 882 ) allNumerators[0] += cxabs2( amp[0] );
  if( channelId != 0 ) allDenominators[0] += cxabs2( amp[0] );
#endif
  jamp[0] += cxtype( 0, 1 ) * amp[0];
  jamp[6] -= cxtype( 0, 1 ) * amp[0];
  jamp[30] -= cxtype( 0, 1 ) * amp[0];
  jamp[54] += cxtype( 0, 1 ) * amp[0];
  jamp[72] -= cxtype( 0, 1 ) * amp[0];
  jamp[74] += cxtype( 0, 1 ) * amp[0];
  jamp[80] += cxtype( 0, 1 ) * amp[0];
  jamp[86] -= cxtype( 0, 1 ) * amp[0];

  // *** DIAGRAM 883 OF 1240 ***

  // Wavefunction(s) for diagram number 883
  // (none)

  // Amplitude(s) for diagram number 883
  FFV1_0( w[40], w[2], w[90], COUPs[1], &amp[0] );
#ifdef MGONGPU_SUPPORTS_MULTICHANNEL
  if( channelId == 883 ) allNumerators[0] += cxabs2( amp[0] );
  if( channelId != 0 ) allDenominators[0] += cxabs2( amp[0] );
#endif
  jamp[0] += amp[0];
  jamp[6] -= amp[0];
  jamp[30] -= amp[0];
  jamp[54] += amp[0];

  // *** DIAGRAM 884 OF 1240 ***

  // Wavefunction(s) for diagram number 884
  // (none)

  // Amplitude(s) for diagram number 884
  FFV1_0( w[62], w[93], w[5], COUPs[1], &amp[0] );
#ifdef MGONGPU_SUPPORTS_MULTICHANNEL
  if( channelId == 884 ) allNumerators[0] += cxabs2( amp[0] );
  if( channelId != 0 ) allDenominators[0] += cxabs2( amp[0] );
#endif
  jamp[32] += cxtype( 0, 1 ) * amp[0];
  jamp[56] -= cxtype( 0, 1 ) * amp[0];

  // *** DIAGRAM 885 OF 1240 ***

  // Wavefunction(s) for diagram number 885
  // (none)

  // Amplitude(s) for diagram number 885
  FFV1_0( w[62], w[2], w[63], COUPs[1], &amp[0] );
#ifdef MGONGPU_SUPPORTS_MULTICHANNEL
  if( channelId == 885 ) allNumerators[0] += cxabs2( amp[0] );
  if( channelId != 0 ) allDenominators[0] += cxabs2( amp[0] );
#endif
  jamp[32] += amp[0];
  jamp[56] -= amp[0];
  jamp[80] -= amp[0];
  jamp[86] += amp[0];

  // *** DIAGRAM 886 OF 1240 ***

  // Wavefunction(s) for diagram number 886
  // (none)

  // Amplitude(s) for diagram number 886
  FFV1_0( w[40], w[93], w[0], COUPs[1], &amp[0] );
#ifdef MGONGPU_SUPPORTS_MULTICHANNEL
  if( channelId == 886 ) allNumerators[0] += cxabs2( amp[0] );
  if( channelId != 0 ) allDenominators[0] += cxabs2( amp[0] );
#endif
  jamp[30] += cxtype( 0, 1 ) * amp[0];
  jamp[54] -= cxtype( 0, 1 ) * amp[0];

  // *** DIAGRAM 887 OF 1240 ***

  // Wavefunction(s) for diagram number 887
  // (none)

  // Amplitude(s) for diagram number 887
  VVV1_0( w[0], w[63], w[20], COUPs[0], &amp[0] );
#ifdef MGONGPU_SUPPORTS_MULTICHANNEL
  if( channelId == 887 ) allNumerators[0] += cxabs2( amp[0] );
  if( channelId != 0 ) allDenominators[0] += cxabs2( amp[0] );
#endif
  jamp[0] -= cxtype( 0, 1 ) * amp[0];
  jamp[6] += cxtype( 0, 1 ) * amp[0];
  jamp[12] += cxtype( 0, 1 ) * amp[0];
  jamp[14] -= cxtype( 0, 1 ) * amp[0];
  jamp[32] += cxtype( 0, 1 ) * amp[0];
  jamp[56] -= cxtype( 0, 1 ) * amp[0];
  jamp[80] -= cxtype( 0, 1 ) * amp[0];
  jamp[86] += cxtype( 0, 1 ) * amp[0];

  // *** DIAGRAM 888 OF 1240 ***

  // Wavefunction(s) for diagram number 888
  // (none)

  // Amplitude(s) for diagram number 888
  FFV1_0( w[41], w[2], w[103], COUPs[1], &amp[0] );
  jamp[0] -= cxtype( 0, 1 ) * amp[0];
  jamp[6] += cxtype( 0, 1 ) * amp[0];
  jamp[12] += cxtype( 0, 1 ) * amp[0];
  jamp[14] -= cxtype( 0, 1 ) * amp[0];
  jamp[32] += cxtype( 0, 1 ) * amp[0];
  jamp[56] -= cxtype( 0, 1 ) * amp[0];
  jamp[80] -= cxtype( 0, 1 ) * amp[0];
  jamp[86] += cxtype( 0, 1 ) * amp[0];
  FFV1_0( w[41], w[2], w[22], COUPs[1], &amp[0] );
  jamp[12] += cxtype( 0, 1 ) * amp[0];
  jamp[14] -= cxtype( 0, 1 ) * amp[0];
  jamp[30] -= cxtype( 0, 1 ) * amp[0];
  jamp[32] += cxtype( 0, 1 ) * amp[0];
  jamp[54] += cxtype( 0, 1 ) * amp[0];
  jamp[56] -= cxtype( 0, 1 ) * amp[0];
  jamp[72] -= cxtype( 0, 1 ) * amp[0];
  jamp[74] += cxtype( 0, 1 ) * amp[0];
  FFV1_0( w[41], w[2], w[21], COUPs[1], &amp[0] );
  jamp[0] += cxtype( 0, 1 ) * amp[0];
  jamp[6] -= cxtype( 0, 1 ) * amp[0];
  jamp[30] -= cxtype( 0, 1 ) * amp[0];
  jamp[54] += cxtype( 0, 1 ) * amp[0];
  jamp[72] -= cxtype( 0, 1 ) * amp[0];
  jamp[74] += cxtype( 0, 1 ) * amp[0];
  jamp[80] += cxtype( 0, 1 ) * amp[0];
  jamp[86] -= cxtype( 0, 1 ) * amp[0];

  // *** DIAGRAM 889 OF 1240 ***

  // Wavefunction(s) for diagram number 889
  // (none)

  // Amplitude(s) for diagram number 889
  FFV1_0( w[3], w[18], w[90], COUPs[1], &amp[0] );
#ifdef MGONGPU_SUPPORTS_MULTICHANNEL
  if( channelId == 889 ) allNumerators[0] += cxabs2( amp[0] );
  if( channelId != 0 ) allDenominators[0] += cxabs2( amp[0] );
#endif
  jamp[90] -= cxtype( 0, 1 ) * amp[0];
  jamp[91] += cxtype( 0, 1 ) * amp[0];
  jamp[93] += cxtype( 0, 1 ) * amp[0];
  jamp[95] -= cxtype( 0, 1 ) * amp[0];
  jamp[114] += cxtype( 0, 1 ) * amp[0];
  jamp[115] -= cxtype( 0, 1 ) * amp[0];
  jamp[117] -= cxtype( 0, 1 ) * amp[0];
  jamp[119] += cxtype( 0, 1 ) * amp[0];

  // *** DIAGRAM 890 OF 1240 ***

  // Wavefunction(s) for diagram number 890
  // (none)

  // Amplitude(s) for diagram number 890
  FFV1_0( w[12], w[2], w[90], COUPs[1], &amp[0] );
#ifdef MGONGPU_SUPPORTS_MULTICHANNEL
  if( channelId == 890 ) allNumerators[0] += cxabs2( amp[0] );
  if( channelId != 0 ) allDenominators[0] += cxabs2( amp[0] );
#endif
  jamp[0] -= cxtype( 0, 1 ) * amp[0];
  jamp[1] += cxtype( 0, 1 ) * amp[0];
  jamp[6] += cxtype( 0, 1 ) * amp[0];
  jamp[7] -= cxtype( 0, 1 ) * amp[0];
  jamp[30] += cxtype( 0, 1 ) * amp[0];
  jamp[31] -= cxtype( 0, 1 ) * amp[0];
  jamp[54] -= cxtype( 0, 1 ) * amp[0];
  jamp[55] += cxtype( 0, 1 ) * amp[0];

  // *** DIAGRAM 891 OF 1240 ***

  // Wavefunction(s) for diagram number 891
  // (none)

  // Amplitude(s) for diagram number 891
  FFV1_0( w[3], w[93], w[96], COUPs[1], &amp[0] );
#ifdef MGONGPU_SUPPORTS_MULTICHANNEL
  if( channelId == 891 ) allNumerators[0] += cxabs2( amp[0] );
  if( channelId != 0 ) allDenominators[0] += cxabs2( amp[0] );
#endif
  jamp[30] -= cxtype( 0, 1 ) * amp[0];
  jamp[31] += cxtype( 0, 1 ) * amp[0];
  jamp[33] += cxtype( 0, 1 ) * amp[0];
  jamp[35] -= cxtype( 0, 1 ) * amp[0];
  jamp[54] += cxtype( 0, 1 ) * amp[0];
  jamp[55] -= cxtype( 0, 1 ) * amp[0];
  jamp[57] -= cxtype( 0, 1 ) * amp[0];
  jamp[59] += cxtype( 0, 1 ) * amp[0];

  // *** DIAGRAM 892 OF 1240 ***

  // Wavefunction(s) for diagram number 892
  // (none)

  // Amplitude(s) for diagram number 892
  FFV1_0( w[65], w[2], w[96], COUPs[1], &amp[0] );
#ifdef MGONGPU_SUPPORTS_MULTICHANNEL
  if( channelId == 892 ) allNumerators[0] += cxabs2( amp[0] );
  if( channelId != 0 ) allDenominators[0] += cxabs2( amp[0] );
#endif
  jamp[16] -= cxtype( 0, 1 ) * amp[0];
  jamp[17] += cxtype( 0, 1 ) * amp[0];
  jamp[22] += cxtype( 0, 1 ) * amp[0];
  jamp[23] -= cxtype( 0, 1 ) * amp[0];
  jamp[90] += cxtype( 0, 1 ) * amp[0];
  jamp[91] -= cxtype( 0, 1 ) * amp[0];
  jamp[114] -= cxtype( 0, 1 ) * amp[0];
  jamp[115] += cxtype( 0, 1 ) * amp[0];

  // *** DIAGRAM 893 OF 1240 ***

  // Wavefunction(s) for diagram number 893
  // (none)

  // Amplitude(s) for diagram number 893
  FFV1_0( w[12], w[93], w[0], COUPs[1], &amp[0] );
#ifdef MGONGPU_SUPPORTS_MULTICHANNEL
  if( channelId == 893 ) allNumerators[0] += cxabs2( amp[0] );
  if( channelId != 0 ) allDenominators[0] += cxabs2( amp[0] );
#endif
  jamp[30] += amp[0];
  jamp[31] -= amp[0];
  jamp[54] -= amp[0];
  jamp[55] += amp[0];

  // *** DIAGRAM 894 OF 1240 ***

  // Wavefunction(s) for diagram number 894
  // (none)

  // Amplitude(s) for diagram number 894
  FFV1_0( w[65], w[18], w[0], COUPs[1], &amp[0] );
#ifdef MGONGPU_SUPPORTS_MULTICHANNEL
  if( channelId == 894 ) allNumerators[0] += cxabs2( amp[0] );
  if( channelId != 0 ) allDenominators[0] += cxabs2( amp[0] );
#endif
  jamp[90] += amp[0];
  jamp[91] -= amp[0];
  jamp[114] -= amp[0];
  jamp[115] += amp[0];

  // *** DIAGRAM 895 OF 1240 ***

  // Wavefunction(s) for diagram number 895
  VVV1P0_1( w[0], w[66], COUPs[0], 0., 0., w[65] );

  // Amplitude(s) for diagram number 895
  VVV1_0( w[65], w[13], w[6], COUPs[0], &amp[0] );
#ifdef MGONGPU_SUPPORTS_MULTICHANNEL
  if( channelId == 895 ) allNumerators[0] += cxabs2( amp[0] );
  if( channelId != 0 ) allDenominators[0] += cxabs2( amp[0] );
#endif
  jamp[3] -= amp[0];
  jamp[13] += amp[0];
  jamp[37] += amp[0];
  jamp[48] += amp[0];
  jamp[50] -= amp[0];
  jamp[56] -= amp[0];
  jamp[62] += amp[0];
  jamp[66] -= amp[0];
  jamp[67] += amp[0];
  jamp[69] += amp[0];
  jamp[71] -= amp[0];
  jamp[79] -= amp[0];
  jamp[97] += amp[0];
  jamp[100] -= amp[0];
  jamp[106] -= amp[0];
  jamp[116] += amp[0];

  // *** DIAGRAM 896 OF 1240 ***

  // Wavefunction(s) for diagram number 896
  // (none)

  // Amplitude(s) for diagram number 896
  VVV1_0( w[65], w[11], w[4], COUPs[0], &amp[0] );
#ifdef MGONGPU_SUPPORTS_MULTICHANNEL
  if( channelId == 896 ) allNumerators[0] += cxabs2( amp[0] );
  if( channelId != 0 ) allDenominators[0] += cxabs2( amp[0] );
#endif
  jamp[2] -= amp[0];
  jamp[12] += amp[0];
  jamp[36] += amp[0];
  jamp[48] += amp[0];
  jamp[50] -= amp[0];
  jamp[56] -= amp[0];
  jamp[62] += amp[0];
  jamp[78] -= amp[0];
  jamp[97] += amp[0];
  jamp[100] -= amp[0];
  jamp[106] -= amp[0];
  jamp[108] -= amp[0];
  jamp[109] += amp[0];
  jamp[111] += amp[0];
  jamp[113] -= amp[0];
  jamp[116] += amp[0];

  // *** DIAGRAM 897 OF 1240 ***

  // Wavefunction(s) for diagram number 897
  // (none)

  // Amplitude(s) for diagram number 897
  VVVV1_0( w[8], w[4], w[6], w[65], COUPs[2], &amp[0] );
  jamp[3] -= amp[0];
  jamp[13] += amp[0];
  jamp[37] += amp[0];
  jamp[48] += amp[0];
  jamp[50] -= amp[0];
  jamp[56] -= amp[0];
  jamp[62] += amp[0];
  jamp[66] -= amp[0];
  jamp[67] += amp[0];
  jamp[69] += amp[0];
  jamp[71] -= amp[0];
  jamp[79] -= amp[0];
  jamp[97] += amp[0];
  jamp[100] -= amp[0];
  jamp[106] -= amp[0];
  jamp[116] += amp[0];
  VVVV3_0( w[8], w[4], w[6], w[65], COUPs[2], &amp[0] );
  jamp[2] -= amp[0];
  jamp[12] += amp[0];
  jamp[36] += amp[0];
  jamp[48] += amp[0];
  jamp[50] -= amp[0];
  jamp[56] -= amp[0];
  jamp[62] += amp[0];
  jamp[78] -= amp[0];
  jamp[97] += amp[0];
  jamp[100] -= amp[0];
  jamp[106] -= amp[0];
  jamp[108] -= amp[0];
  jamp[109] += amp[0];
  jamp[111] += amp[0];
  jamp[113] -= amp[0];
  jamp[116] += amp[0];
  VVVV4_0( w[8], w[4], w[6], w[65], COUPs[2], &amp[0] );
  jamp[2] -= amp[0];
  jamp[3] += amp[0];
  jamp[12] += amp[0];
  jamp[13] -= amp[0];
  jamp[36] += amp[0];
  jamp[37] -= amp[0];
  jamp[66] += amp[0];
  jamp[67] -= amp[0];
  jamp[69] -= amp[0];
  jamp[71] += amp[0];
  jamp[78] -= amp[0];
  jamp[79] += amp[0];
  jamp[108] -= amp[0];
  jamp[109] += amp[0];
  jamp[111] += amp[0];
  jamp[113] -= amp[0];

  // *** DIAGRAM 898 OF 1240 ***

  // Wavefunction(s) for diagram number 898
  // (none)

  // Amplitude(s) for diagram number 898
  VVV1_0( w[56], w[69], w[6], COUPs[0], &amp[0] );
#ifdef MGONGPU_SUPPORTS_MULTICHANNEL
  if( channelId == 898 ) allNumerators[0] += cxabs2( amp[0] );
  if( channelId != 0 ) allDenominators[0] += cxabs2( amp[0] );
#endif
  jamp[2] += amp[0];
  jamp[6] -= amp[0];
  jamp[8] += amp[0];
  jamp[12] -= amp[0];
  jamp[19] -= amp[0];
  jamp[20] += amp[0];
  jamp[21] -= amp[0];
  jamp[22] += amp[0];
  jamp[39] -= amp[0];
  jamp[57] += amp[0];
  jamp[63] -= amp[0];
  jamp[81] += amp[0];
  jamp[107] += amp[0];
  jamp[111] -= amp[0];
  jamp[113] += amp[0];
  jamp[117] -= amp[0];

  // *** DIAGRAM 899 OF 1240 ***

  // Wavefunction(s) for diagram number 899
  // (none)

  // Amplitude(s) for diagram number 899
  VVV1_0( w[56], w[70], w[4], COUPs[0], &amp[0] );
#ifdef MGONGPU_SUPPORTS_MULTICHANNEL
  if( channelId == 899 ) allNumerators[0] += cxabs2( amp[0] );
  if( channelId != 0 ) allDenominators[0] += cxabs2( amp[0] );
#endif
  jamp[3] += amp[0];
  jamp[6] -= amp[0];
  jamp[8] += amp[0];
  jamp[10] += amp[0];
  jamp[11] -= amp[0];
  jamp[13] -= amp[0];
  jamp[19] -= amp[0];
  jamp[22] += amp[0];
  jamp[41] -= amp[0];
  jamp[57] += amp[0];
  jamp[63] -= amp[0];
  jamp[69] -= amp[0];
  jamp[71] += amp[0];
  jamp[83] += amp[0];
  jamp[107] += amp[0];
  jamp[117] -= amp[0];

  // *** DIAGRAM 900 OF 1240 ***

  // Wavefunction(s) for diagram number 900
  // (none)

  // Amplitude(s) for diagram number 900
  VVVV1_0( w[66], w[4], w[6], w[56], COUPs[2], &amp[0] );
  jamp[2] += amp[0];
  jamp[6] -= amp[0];
  jamp[8] += amp[0];
  jamp[12] -= amp[0];
  jamp[19] -= amp[0];
  jamp[20] += amp[0];
  jamp[21] -= amp[0];
  jamp[22] += amp[0];
  jamp[39] -= amp[0];
  jamp[57] += amp[0];
  jamp[63] -= amp[0];
  jamp[81] += amp[0];
  jamp[107] += amp[0];
  jamp[111] -= amp[0];
  jamp[113] += amp[0];
  jamp[117] -= amp[0];
  VVVV3_0( w[66], w[4], w[6], w[56], COUPs[2], &amp[0] );
  jamp[3] += amp[0];
  jamp[6] -= amp[0];
  jamp[8] += amp[0];
  jamp[10] += amp[0];
  jamp[11] -= amp[0];
  jamp[13] -= amp[0];
  jamp[19] -= amp[0];
  jamp[22] += amp[0];
  jamp[41] -= amp[0];
  jamp[57] += amp[0];
  jamp[63] -= amp[0];
  jamp[69] -= amp[0];
  jamp[71] += amp[0];
  jamp[83] += amp[0];
  jamp[107] += amp[0];
  jamp[117] -= amp[0];
  VVVV4_0( w[66], w[4], w[6], w[56], COUPs[2], &amp[0] );
  jamp[2] -= amp[0];
  jamp[3] += amp[0];
  jamp[10] += amp[0];
  jamp[11] -= amp[0];
  jamp[12] += amp[0];
  jamp[13] -= amp[0];
  jamp[20] -= amp[0];
  jamp[21] += amp[0];
  jamp[39] += amp[0];
  jamp[41] -= amp[0];
  jamp[69] -= amp[0];
  jamp[71] += amp[0];
  jamp[81] -= amp[0];
  jamp[83] += amp[0];
  jamp[111] += amp[0];
  jamp[113] -= amp[0];

  // *** DIAGRAM 901 OF 1240 ***

  // Wavefunction(s) for diagram number 901
  // (none)

  // Amplitude(s) for diagram number 901
  VVV1_0( w[0], w[69], w[11], COUPs[0], &amp[0] );
#ifdef MGONGPU_SUPPORTS_MULTICHANNEL
  if( channelId == 901 ) allNumerators[0] += cxabs2( amp[0] );
  if( channelId != 0 ) allDenominators[0] += cxabs2( amp[0] );
#endif
  jamp[2] += amp[0];
  jamp[6] -= amp[0];
  jamp[8] += amp[0];
  jamp[12] -= amp[0];
  jamp[38] -= amp[0];
  jamp[56] += amp[0];
  jamp[62] -= amp[0];
  jamp[80] += amp[0];
  jamp[97] -= amp[0];
  jamp[98] += amp[0];
  jamp[99] -= amp[0];
  jamp[100] += amp[0];
  jamp[107] += amp[0];
  jamp[111] -= amp[0];
  jamp[113] += amp[0];
  jamp[117] -= amp[0];

  // *** DIAGRAM 902 OF 1240 ***

  // Wavefunction(s) for diagram number 902
  // (none)

  // Amplitude(s) for diagram number 902
  VVV1_0( w[0], w[70], w[13], COUPs[0], &amp[0] );
#ifdef MGONGPU_SUPPORTS_MULTICHANNEL
  if( channelId == 902 ) allNumerators[0] += cxabs2( amp[0] );
  if( channelId != 0 ) allDenominators[0] += cxabs2( amp[0] );
#endif
  jamp[3] += amp[0];
  jamp[13] -= amp[0];
  jamp[19] -= amp[0];
  jamp[22] += amp[0];
  jamp[40] -= amp[0];
  jamp[48] -= amp[0];
  jamp[50] += amp[0];
  jamp[52] += amp[0];
  jamp[53] -= amp[0];
  jamp[57] += amp[0];
  jamp[63] -= amp[0];
  jamp[69] -= amp[0];
  jamp[71] += amp[0];
  jamp[82] += amp[0];
  jamp[106] += amp[0];
  jamp[116] -= amp[0];

  // *** DIAGRAM 903 OF 1240 ***

  // Wavefunction(s) for diagram number 903
  VVVV1P0_1( w[0], w[66], w[4], COUPs[2], 0., 0., w[93] );
  VVVV3P0_1( w[0], w[66], w[4], COUPs[2], 0., 0., w[90] );
  VVVV4P0_1( w[0], w[66], w[4], COUPs[2], 0., 0., w[21] );

  // Amplitude(s) for diagram number 903
  VVV1_0( w[8], w[6], w[93], COUPs[0], &amp[0] );
  jamp[2] += amp[0];
  jamp[6] -= amp[0];
  jamp[8] += amp[0];
  jamp[12] -= amp[0];
  jamp[38] -= amp[0];
  jamp[56] += amp[0];
  jamp[62] -= amp[0];
  jamp[80] += amp[0];
  jamp[97] -= amp[0];
  jamp[98] += amp[0];
  jamp[99] -= amp[0];
  jamp[100] += amp[0];
  jamp[107] += amp[0];
  jamp[111] -= amp[0];
  jamp[113] += amp[0];
  jamp[117] -= amp[0];
  VVV1_0( w[8], w[6], w[90], COUPs[0], &amp[0] );
  jamp[6] -= amp[0];
  jamp[8] += amp[0];
  jamp[36] += amp[0];
  jamp[38] -= amp[0];
  jamp[48] += amp[0];
  jamp[50] -= amp[0];
  jamp[78] -= amp[0];
  jamp[80] += amp[0];
  jamp[98] += amp[0];
  jamp[99] -= amp[0];
  jamp[106] -= amp[0];
  jamp[107] += amp[0];
  jamp[108] -= amp[0];
  jamp[109] += amp[0];
  jamp[116] += amp[0];
  jamp[117] -= amp[0];
  VVV1_0( w[8], w[6], w[21], COUPs[0], &amp[0] );
  jamp[2] -= amp[0];
  jamp[12] += amp[0];
  jamp[36] += amp[0];
  jamp[48] += amp[0];
  jamp[50] -= amp[0];
  jamp[56] -= amp[0];
  jamp[62] += amp[0];
  jamp[78] -= amp[0];
  jamp[97] += amp[0];
  jamp[100] -= amp[0];
  jamp[106] -= amp[0];
  jamp[108] -= amp[0];
  jamp[109] += amp[0];
  jamp[111] += amp[0];
  jamp[113] -= amp[0];
  jamp[116] += amp[0];

  // *** DIAGRAM 904 OF 1240 ***

  // Wavefunction(s) for diagram number 904
  VVVV1P0_1( w[0], w[66], w[6], COUPs[2], 0., 0., w[22] );
  VVVV3P0_1( w[0], w[66], w[6], COUPs[2], 0., 0., w[103] );
  VVVV4P0_1( w[0], w[66], w[6], COUPs[2], 0., 0., w[63] );

  // Amplitude(s) for diagram number 904
  VVV1_0( w[8], w[4], w[22], COUPs[0], &amp[0] );
  jamp[3] += amp[0];
  jamp[13] -= amp[0];
  jamp[19] -= amp[0];
  jamp[22] += amp[0];
  jamp[40] -= amp[0];
  jamp[48] -= amp[0];
  jamp[50] += amp[0];
  jamp[52] += amp[0];
  jamp[53] -= amp[0];
  jamp[57] += amp[0];
  jamp[63] -= amp[0];
  jamp[69] -= amp[0];
  jamp[71] += amp[0];
  jamp[82] += amp[0];
  jamp[106] += amp[0];
  jamp[116] -= amp[0];
  VVV1_0( w[8], w[4], w[103], COUPs[0], &amp[0] );
  jamp[19] -= amp[0];
  jamp[22] += amp[0];
  jamp[37] += amp[0];
  jamp[40] -= amp[0];
  jamp[52] += amp[0];
  jamp[53] -= amp[0];
  jamp[56] -= amp[0];
  jamp[57] += amp[0];
  jamp[62] += amp[0];
  jamp[63] -= amp[0];
  jamp[66] -= amp[0];
  jamp[67] += amp[0];
  jamp[79] -= amp[0];
  jamp[82] += amp[0];
  jamp[97] += amp[0];
  jamp[100] -= amp[0];
  VVV1_0( w[8], w[4], w[63], COUPs[0], &amp[0] );
  jamp[3] -= amp[0];
  jamp[13] += amp[0];
  jamp[37] += amp[0];
  jamp[48] += amp[0];
  jamp[50] -= amp[0];
  jamp[56] -= amp[0];
  jamp[62] += amp[0];
  jamp[66] -= amp[0];
  jamp[67] += amp[0];
  jamp[69] += amp[0];
  jamp[71] -= amp[0];
  jamp[79] -= amp[0];
  jamp[97] += amp[0];
  jamp[100] -= amp[0];
  jamp[106] -= amp[0];
  jamp[116] += amp[0];

  // *** DIAGRAM 905 OF 1240 ***

  // Wavefunction(s) for diagram number 905
  VVVV1P0_1( w[0], w[8], w[4], COUPs[2], 0., 0., w[107] );
  VVVV3P0_1( w[0], w[8], w[4], COUPs[2], 0., 0., w[95] );
  VVVV4P0_1( w[0], w[8], w[4], COUPs[2], 0., 0., w[105] );

  // Amplitude(s) for diagram number 905
  VVV1_0( w[66], w[6], w[107], COUPs[0], &amp[0] );
  jamp[3] -= amp[0];
  jamp[13] += amp[0];
  jamp[19] += amp[0];
  jamp[22] -= amp[0];
  jamp[40] += amp[0];
  jamp[48] += amp[0];
  jamp[50] -= amp[0];
  jamp[52] -= amp[0];
  jamp[53] += amp[0];
  jamp[57] -= amp[0];
  jamp[63] += amp[0];
  jamp[69] += amp[0];
  jamp[71] -= amp[0];
  jamp[82] -= amp[0];
  jamp[106] -= amp[0];
  jamp[116] += amp[0];
  VVV1_0( w[66], w[6], w[95], COUPs[0], &amp[0] );
  jamp[6] -= amp[0];
  jamp[8] += amp[0];
  jamp[10] += amp[0];
  jamp[11] -= amp[0];
  jamp[40] += amp[0];
  jamp[41] -= amp[0];
  jamp[48] += amp[0];
  jamp[50] -= amp[0];
  jamp[52] -= amp[0];
  jamp[53] += amp[0];
  jamp[82] -= amp[0];
  jamp[83] += amp[0];
  jamp[106] -= amp[0];
  jamp[107] += amp[0];
  jamp[116] += amp[0];
  jamp[117] -= amp[0];
  VVV1_0( w[66], w[6], w[105], COUPs[0], &amp[0] );
  jamp[3] += amp[0];
  jamp[6] -= amp[0];
  jamp[8] += amp[0];
  jamp[10] += amp[0];
  jamp[11] -= amp[0];
  jamp[13] -= amp[0];
  jamp[19] -= amp[0];
  jamp[22] += amp[0];
  jamp[41] -= amp[0];
  jamp[57] += amp[0];
  jamp[63] -= amp[0];
  jamp[69] -= amp[0];
  jamp[71] += amp[0];
  jamp[83] += amp[0];
  jamp[107] += amp[0];
  jamp[117] -= amp[0];

  // *** DIAGRAM 906 OF 1240 ***

  // Wavefunction(s) for diagram number 906
  // (none)

  // Amplitude(s) for diagram number 906
  VVV1_0( w[66], w[4], w[118], COUPs[0], &amp[0] );
  jamp[2] -= amp[0];
  jamp[6] += amp[0];
  jamp[8] -= amp[0];
  jamp[12] += amp[0];
  jamp[38] += amp[0];
  jamp[56] -= amp[0];
  jamp[62] += amp[0];
  jamp[80] -= amp[0];
  jamp[97] += amp[0];
  jamp[98] -= amp[0];
  jamp[99] += amp[0];
  jamp[100] -= amp[0];
  jamp[107] -= amp[0];
  jamp[111] += amp[0];
  jamp[113] -= amp[0];
  jamp[117] += amp[0];
  VVV1_0( w[66], w[4], w[119], COUPs[0], &amp[0] );
  jamp[19] -= amp[0];
  jamp[20] += amp[0];
  jamp[21] -= amp[0];
  jamp[22] += amp[0];
  jamp[38] += amp[0];
  jamp[39] -= amp[0];
  jamp[56] -= amp[0];
  jamp[57] += amp[0];
  jamp[62] += amp[0];
  jamp[63] -= amp[0];
  jamp[80] -= amp[0];
  jamp[81] += amp[0];
  jamp[97] += amp[0];
  jamp[98] -= amp[0];
  jamp[99] += amp[0];
  jamp[100] -= amp[0];
  VVV1_0( w[66], w[4], w[120], COUPs[0], &amp[0] );
  jamp[2] += amp[0];
  jamp[6] -= amp[0];
  jamp[8] += amp[0];
  jamp[12] -= amp[0];
  jamp[19] -= amp[0];
  jamp[20] += amp[0];
  jamp[21] -= amp[0];
  jamp[22] += amp[0];
  jamp[39] -= amp[0];
  jamp[57] += amp[0];
  jamp[63] -= amp[0];
  jamp[81] += amp[0];
  jamp[107] += amp[0];
  jamp[111] -= amp[0];
  jamp[113] += amp[0];
  jamp[117] -= amp[0];

  // *** DIAGRAM 907 OF 1240 ***

  // Wavefunction(s) for diagram number 907
  // (none)

  // Amplitude(s) for diagram number 907
  VVVV1_0( w[0], w[66], w[8], w[27], COUPs[2], &amp[0] );
  jamp[2] += amp[0];
  jamp[3] -= amp[0];
  jamp[12] -= amp[0];
  jamp[13] += amp[0];
  jamp[36] -= amp[0];
  jamp[37] += amp[0];
  jamp[66] -= amp[0];
  jamp[67] += amp[0];
  jamp[69] += amp[0];
  jamp[71] -= amp[0];
  jamp[78] += amp[0];
  jamp[79] -= amp[0];
  jamp[108] += amp[0];
  jamp[109] -= amp[0];
  jamp[111] -= amp[0];
  jamp[113] += amp[0];
  VVVV3_0( w[0], w[66], w[8], w[27], COUPs[2], &amp[0] );
  jamp[2] += amp[0];
  jamp[3] -= amp[0];
  jamp[10] -= amp[0];
  jamp[11] += amp[0];
  jamp[12] -= amp[0];
  jamp[13] += amp[0];
  jamp[20] += amp[0];
  jamp[21] -= amp[0];
  jamp[39] -= amp[0];
  jamp[41] += amp[0];
  jamp[69] += amp[0];
  jamp[71] -= amp[0];
  jamp[81] += amp[0];
  jamp[83] -= amp[0];
  jamp[111] -= amp[0];
  jamp[113] += amp[0];
  VVVV4_0( w[0], w[66], w[8], w[27], COUPs[2], &amp[0] );
  jamp[10] -= amp[0];
  jamp[11] += amp[0];
  jamp[20] += amp[0];
  jamp[21] -= amp[0];
  jamp[36] += amp[0];
  jamp[37] -= amp[0];
  jamp[39] -= amp[0];
  jamp[41] += amp[0];
  jamp[66] += amp[0];
  jamp[67] -= amp[0];
  jamp[78] -= amp[0];
  jamp[79] += amp[0];
  jamp[81] += amp[0];
  jamp[83] -= amp[0];
  jamp[108] -= amp[0];
  jamp[109] += amp[0];

  // *** DIAGRAM 908 OF 1240 ***

  // Wavefunction(s) for diagram number 908
  // (none)

  // Amplitude(s) for diagram number 908
  VVV1_0( w[8], w[27], w[65], COUPs[0], &amp[0] );
#ifdef MGONGPU_SUPPORTS_MULTICHANNEL
  if( channelId == 908 ) allNumerators[0] += cxabs2( amp[0] );
  if( channelId != 0 ) allDenominators[0] += cxabs2( amp[0] );
#endif
  jamp[2] += amp[0];
  jamp[3] -= amp[0];
  jamp[12] -= amp[0];
  jamp[13] += amp[0];
  jamp[36] -= amp[0];
  jamp[37] += amp[0];
  jamp[66] -= amp[0];
  jamp[67] += amp[0];
  jamp[69] += amp[0];
  jamp[71] -= amp[0];
  jamp[78] += amp[0];
  jamp[79] -= amp[0];
  jamp[108] += amp[0];
  jamp[109] -= amp[0];
  jamp[111] -= amp[0];
  jamp[113] += amp[0];

  // *** DIAGRAM 909 OF 1240 ***

  // Wavefunction(s) for diagram number 909
  // (none)

  // Amplitude(s) for diagram number 909
  VVV1_0( w[66], w[27], w[56], COUPs[0], &amp[0] );
#ifdef MGONGPU_SUPPORTS_MULTICHANNEL
  if( channelId == 909 ) allNumerators[0] += cxabs2( amp[0] );
  if( channelId != 0 ) allDenominators[0] += cxabs2( amp[0] );
#endif
  jamp[2] += amp[0];
  jamp[3] -= amp[0];
  jamp[10] -= amp[0];
  jamp[11] += amp[0];
  jamp[12] -= amp[0];
  jamp[13] += amp[0];
  jamp[20] += amp[0];
  jamp[21] -= amp[0];
  jamp[39] -= amp[0];
  jamp[41] += amp[0];
  jamp[69] += amp[0];
  jamp[71] -= amp[0];
  jamp[81] += amp[0];
  jamp[83] -= amp[0];
  jamp[111] -= amp[0];
  jamp[113] += amp[0];

  // *** DIAGRAM 910 OF 1240 ***

  // Wavefunction(s) for diagram number 910
  // (none)

  // Amplitude(s) for diagram number 910
  VVV1_0( w[66], w[8], w[101], COUPs[0], &amp[0] );
#ifdef MGONGPU_SUPPORTS_MULTICHANNEL
  if( channelId == 910 ) allNumerators[0] += cxabs2( amp[0] );
  if( channelId != 0 ) allDenominators[0] += cxabs2( amp[0] );
#endif
  jamp[10] -= amp[0];
  jamp[11] += amp[0];
  jamp[20] += amp[0];
  jamp[21] -= amp[0];
  jamp[36] += amp[0];
  jamp[37] -= amp[0];
  jamp[39] -= amp[0];
  jamp[41] += amp[0];
  jamp[66] += amp[0];
  jamp[67] -= amp[0];
  jamp[78] -= amp[0];
  jamp[79] += amp[0];
  jamp[81] += amp[0];
  jamp[83] -= amp[0];
  jamp[108] -= amp[0];
  jamp[109] += amp[0];

  // *** DIAGRAM 911 OF 1240 ***

  // Wavefunction(s) for diagram number 911
  // (none)

  // Amplitude(s) for diagram number 911
  VVV1_0( w[65], w[37], w[6], COUPs[0], &amp[0] );
#ifdef MGONGPU_SUPPORTS_MULTICHANNEL
  if( channelId == 911 ) allNumerators[0] += cxabs2( amp[0] );
  if( channelId != 0 ) allDenominators[0] += cxabs2( amp[0] );
#endif
  jamp[48] += cxtype( 0, 1 ) * amp[0];
  jamp[50] -= cxtype( 0, 1 ) * amp[0];
  jamp[56] -= cxtype( 0, 1 ) * amp[0];
  jamp[62] += cxtype( 0, 1 ) * amp[0];
  jamp[66] -= cxtype( 0, 1 ) * amp[0];
  jamp[67] += cxtype( 0, 1 ) * amp[0];
  jamp[69] += cxtype( 0, 1 ) * amp[0];
  jamp[71] -= cxtype( 0, 1 ) * amp[0];

  // *** DIAGRAM 912 OF 1240 ***

  // Wavefunction(s) for diagram number 912
  // (none)

  // Amplitude(s) for diagram number 912
  FFV1_0( w[3], w[36], w[65], COUPs[1], &amp[0] );
#ifdef MGONGPU_SUPPORTS_MULTICHANNEL
  if( channelId == 912 ) allNumerators[0] += cxabs2( amp[0] );
  if( channelId != 0 ) allDenominators[0] += cxabs2( amp[0] );
#endif
  jamp[66] += amp[0];
  jamp[67] -= amp[0];
  jamp[69] -= amp[0];
  jamp[71] += amp[0];

  // *** DIAGRAM 913 OF 1240 ***

  // Wavefunction(s) for diagram number 913
  // (none)

  // Amplitude(s) for diagram number 913
  FFV1_0( w[71], w[114], w[6], COUPs[1], &amp[0] );
#ifdef MGONGPU_SUPPORTS_MULTICHANNEL
  if( channelId == 913 ) allNumerators[0] += cxabs2( amp[0] );
  if( channelId != 0 ) allDenominators[0] += cxabs2( amp[0] );
#endif
  jamp[52] += cxtype( 0, 1 ) * amp[0];
  jamp[53] -= cxtype( 0, 1 ) * amp[0];

  // *** DIAGRAM 914 OF 1240 ***

  // Wavefunction(s) for diagram number 914
  // (none)

  // Amplitude(s) for diagram number 914
  FFV1_0( w[3], w[114], w[70], COUPs[1], &amp[0] );
#ifdef MGONGPU_SUPPORTS_MULTICHANNEL
  if( channelId == 914 ) allNumerators[0] += cxabs2( amp[0] );
  if( channelId != 0 ) allDenominators[0] += cxabs2( amp[0] );
#endif
  jamp[48] += amp[0];
  jamp[50] -= amp[0];
  jamp[52] -= amp[0];
  jamp[53] += amp[0];

  // *** DIAGRAM 915 OF 1240 ***

  // Wavefunction(s) for diagram number 915
  // (none)

  // Amplitude(s) for diagram number 915
  FFV1_0( w[71], w[36], w[0], COUPs[1], &amp[0] );
#ifdef MGONGPU_SUPPORTS_MULTICHANNEL
  if( channelId == 915 ) allNumerators[0] += cxabs2( amp[0] );
  if( channelId != 0 ) allDenominators[0] += cxabs2( amp[0] );
#endif
  jamp[66] += cxtype( 0, 1 ) * amp[0];
  jamp[67] -= cxtype( 0, 1 ) * amp[0];

  // *** DIAGRAM 916 OF 1240 ***

  // Wavefunction(s) for diagram number 916
  // (none)

  // Amplitude(s) for diagram number 916
  VVV1_0( w[0], w[70], w[37], COUPs[0], &amp[0] );
#ifdef MGONGPU_SUPPORTS_MULTICHANNEL
  if( channelId == 916 ) allNumerators[0] += cxabs2( amp[0] );
  if( channelId != 0 ) allDenominators[0] += cxabs2( amp[0] );
#endif
  jamp[48] -= cxtype( 0, 1 ) * amp[0];
  jamp[50] += cxtype( 0, 1 ) * amp[0];
  jamp[52] += cxtype( 0, 1 ) * amp[0];
  jamp[53] -= cxtype( 0, 1 ) * amp[0];
  jamp[57] += cxtype( 0, 1 ) * amp[0];
  jamp[63] -= cxtype( 0, 1 ) * amp[0];
  jamp[69] -= cxtype( 0, 1 ) * amp[0];
  jamp[71] += cxtype( 0, 1 ) * amp[0];

  // *** DIAGRAM 917 OF 1240 ***

  // Wavefunction(s) for diagram number 917
  // (none)

  // Amplitude(s) for diagram number 917
  FFV1_0( w[3], w[33], w[22], COUPs[1], &amp[0] );
  jamp[48] -= cxtype( 0, 1 ) * amp[0];
  jamp[50] += cxtype( 0, 1 ) * amp[0];
  jamp[52] += cxtype( 0, 1 ) * amp[0];
  jamp[53] -= cxtype( 0, 1 ) * amp[0];
  jamp[57] += cxtype( 0, 1 ) * amp[0];
  jamp[63] -= cxtype( 0, 1 ) * amp[0];
  jamp[69] -= cxtype( 0, 1 ) * amp[0];
  jamp[71] += cxtype( 0, 1 ) * amp[0];
  FFV1_0( w[3], w[33], w[103], COUPs[1], &amp[0] );
  jamp[52] += cxtype( 0, 1 ) * amp[0];
  jamp[53] -= cxtype( 0, 1 ) * amp[0];
  jamp[56] -= cxtype( 0, 1 ) * amp[0];
  jamp[57] += cxtype( 0, 1 ) * amp[0];
  jamp[62] += cxtype( 0, 1 ) * amp[0];
  jamp[63] -= cxtype( 0, 1 ) * amp[0];
  jamp[66] -= cxtype( 0, 1 ) * amp[0];
  jamp[67] += cxtype( 0, 1 ) * amp[0];
  FFV1_0( w[3], w[33], w[63], COUPs[1], &amp[0] );
  jamp[48] += cxtype( 0, 1 ) * amp[0];
  jamp[50] -= cxtype( 0, 1 ) * amp[0];
  jamp[56] -= cxtype( 0, 1 ) * amp[0];
  jamp[62] += cxtype( 0, 1 ) * amp[0];
  jamp[66] -= cxtype( 0, 1 ) * amp[0];
  jamp[67] += cxtype( 0, 1 ) * amp[0];
  jamp[69] += cxtype( 0, 1 ) * amp[0];
  jamp[71] -= cxtype( 0, 1 ) * amp[0];

  // *** DIAGRAM 918 OF 1240 ***

  // Wavefunction(s) for diagram number 918
  // (none)

  // Amplitude(s) for diagram number 918
  FFV1_0( w[41], w[33], w[65], COUPs[1], &amp[0] );
#ifdef MGONGPU_SUPPORTS_MULTICHANNEL
  if( channelId == 918 ) allNumerators[0] += cxabs2( amp[0] );
  if( channelId != 0 ) allDenominators[0] += cxabs2( amp[0] );
#endif
  jamp[48] += amp[0];
  jamp[50] -= amp[0];
  jamp[56] -= amp[0];
  jamp[62] += amp[0];

  // *** DIAGRAM 919 OF 1240 ***

  // Wavefunction(s) for diagram number 919
  // (none)

  // Amplitude(s) for diagram number 919
  FFV1_0( w[41], w[114], w[66], COUPs[1], &amp[0] );
#ifdef MGONGPU_SUPPORTS_MULTICHANNEL
  if( channelId == 919 ) allNumerators[0] += cxabs2( amp[0] );
  if( channelId != 0 ) allDenominators[0] += cxabs2( amp[0] );
#endif
  jamp[48] += cxtype( 0, 1 ) * amp[0];
  jamp[50] -= cxtype( 0, 1 ) * amp[0];

  // *** DIAGRAM 920 OF 1240 ***

  // Wavefunction(s) for diagram number 920
  // (none)

  // Amplitude(s) for diagram number 920
  FFV1_0( w[62], w[33], w[66], COUPs[1], &amp[0] );
#ifdef MGONGPU_SUPPORTS_MULTICHANNEL
  if( channelId == 920 ) allNumerators[0] += cxabs2( amp[0] );
  if( channelId != 0 ) allDenominators[0] += cxabs2( amp[0] );
#endif
  jamp[56] += cxtype( 0, 1 ) * amp[0];
  jamp[62] -= cxtype( 0, 1 ) * amp[0];

  // *** DIAGRAM 921 OF 1240 ***

  // Wavefunction(s) for diagram number 921
  // (none)

  // Amplitude(s) for diagram number 921
  VVV1_0( w[65], w[51], w[4], COUPs[0], &amp[0] );
#ifdef MGONGPU_SUPPORTS_MULTICHANNEL
  if( channelId == 921 ) allNumerators[0] += cxabs2( amp[0] );
  if( channelId != 0 ) allDenominators[0] += cxabs2( amp[0] );
#endif
  jamp[97] += cxtype( 0, 1 ) * amp[0];
  jamp[100] -= cxtype( 0, 1 ) * amp[0];
  jamp[106] -= cxtype( 0, 1 ) * amp[0];
  jamp[108] -= cxtype( 0, 1 ) * amp[0];
  jamp[109] += cxtype( 0, 1 ) * amp[0];
  jamp[111] += cxtype( 0, 1 ) * amp[0];
  jamp[113] -= cxtype( 0, 1 ) * amp[0];
  jamp[116] += cxtype( 0, 1 ) * amp[0];

  // *** DIAGRAM 922 OF 1240 ***

  // Wavefunction(s) for diagram number 922
  // (none)

  // Amplitude(s) for diagram number 922
  FFV1_0( w[3], w[49], w[65], COUPs[1], &amp[0] );
#ifdef MGONGPU_SUPPORTS_MULTICHANNEL
  if( channelId == 922 ) allNumerators[0] += cxabs2( amp[0] );
  if( channelId != 0 ) allDenominators[0] += cxabs2( amp[0] );
#endif
  jamp[108] += amp[0];
  jamp[109] -= amp[0];
  jamp[111] -= amp[0];
  jamp[113] += amp[0];

  // *** DIAGRAM 923 OF 1240 ***

  // Wavefunction(s) for diagram number 923
  // (none)

  // Amplitude(s) for diagram number 923
  FFV1_0( w[71], w[113], w[4], COUPs[1], &amp[0] );
#ifdef MGONGPU_SUPPORTS_MULTICHANNEL
  if( channelId == 923 ) allNumerators[0] += cxabs2( amp[0] );
  if( channelId != 0 ) allDenominators[0] += cxabs2( amp[0] );
#endif
  jamp[98] += cxtype( 0, 1 ) * amp[0];
  jamp[99] -= cxtype( 0, 1 ) * amp[0];

  // *** DIAGRAM 924 OF 1240 ***

  // Wavefunction(s) for diagram number 924
  // (none)

  // Amplitude(s) for diagram number 924
  FFV1_0( w[3], w[113], w[69], COUPs[1], &amp[0] );
#ifdef MGONGPU_SUPPORTS_MULTICHANNEL
  if( channelId == 924 ) allNumerators[0] += cxabs2( amp[0] );
  if( channelId != 0 ) allDenominators[0] += cxabs2( amp[0] );
#endif
  jamp[97] += amp[0];
  jamp[98] -= amp[0];
  jamp[99] += amp[0];
  jamp[100] -= amp[0];

  // *** DIAGRAM 925 OF 1240 ***

  // Wavefunction(s) for diagram number 925
  // (none)

  // Amplitude(s) for diagram number 925
  FFV1_0( w[71], w[49], w[0], COUPs[1], &amp[0] );
#ifdef MGONGPU_SUPPORTS_MULTICHANNEL
  if( channelId == 925 ) allNumerators[0] += cxabs2( amp[0] );
  if( channelId != 0 ) allDenominators[0] += cxabs2( amp[0] );
#endif
  jamp[108] += cxtype( 0, 1 ) * amp[0];
  jamp[109] -= cxtype( 0, 1 ) * amp[0];

  // *** DIAGRAM 926 OF 1240 ***

  // Wavefunction(s) for diagram number 926
  // (none)

  // Amplitude(s) for diagram number 926
  VVV1_0( w[0], w[69], w[51], COUPs[0], &amp[0] );
#ifdef MGONGPU_SUPPORTS_MULTICHANNEL
  if( channelId == 926 ) allNumerators[0] += cxabs2( amp[0] );
  if( channelId != 0 ) allDenominators[0] += cxabs2( amp[0] );
#endif
  jamp[97] -= cxtype( 0, 1 ) * amp[0];
  jamp[98] += cxtype( 0, 1 ) * amp[0];
  jamp[99] -= cxtype( 0, 1 ) * amp[0];
  jamp[100] += cxtype( 0, 1 ) * amp[0];
  jamp[107] += cxtype( 0, 1 ) * amp[0];
  jamp[111] -= cxtype( 0, 1 ) * amp[0];
  jamp[113] += cxtype( 0, 1 ) * amp[0];
  jamp[117] -= cxtype( 0, 1 ) * amp[0];

  // *** DIAGRAM 927 OF 1240 ***

  // Wavefunction(s) for diagram number 927
  // (none)

  // Amplitude(s) for diagram number 927
  FFV1_0( w[3], w[47], w[93], COUPs[1], &amp[0] );
  jamp[97] -= cxtype( 0, 1 ) * amp[0];
  jamp[98] += cxtype( 0, 1 ) * amp[0];
  jamp[99] -= cxtype( 0, 1 ) * amp[0];
  jamp[100] += cxtype( 0, 1 ) * amp[0];
  jamp[107] += cxtype( 0, 1 ) * amp[0];
  jamp[111] -= cxtype( 0, 1 ) * amp[0];
  jamp[113] += cxtype( 0, 1 ) * amp[0];
  jamp[117] -= cxtype( 0, 1 ) * amp[0];
  FFV1_0( w[3], w[47], w[90], COUPs[1], &amp[0] );
  jamp[98] += cxtype( 0, 1 ) * amp[0];
  jamp[99] -= cxtype( 0, 1 ) * amp[0];
  jamp[106] -= cxtype( 0, 1 ) * amp[0];
  jamp[107] += cxtype( 0, 1 ) * amp[0];
  jamp[108] -= cxtype( 0, 1 ) * amp[0];
  jamp[109] += cxtype( 0, 1 ) * amp[0];
  jamp[116] += cxtype( 0, 1 ) * amp[0];
  jamp[117] -= cxtype( 0, 1 ) * amp[0];
  FFV1_0( w[3], w[47], w[21], COUPs[1], &amp[0] );
  jamp[97] += cxtype( 0, 1 ) * amp[0];
  jamp[100] -= cxtype( 0, 1 ) * amp[0];
  jamp[106] -= cxtype( 0, 1 ) * amp[0];
  jamp[108] -= cxtype( 0, 1 ) * amp[0];
  jamp[109] += cxtype( 0, 1 ) * amp[0];
  jamp[111] += cxtype( 0, 1 ) * amp[0];
  jamp[113] -= cxtype( 0, 1 ) * amp[0];
  jamp[116] += cxtype( 0, 1 ) * amp[0];

  // *** DIAGRAM 928 OF 1240 ***

  // Wavefunction(s) for diagram number 928
  // (none)

  // Amplitude(s) for diagram number 928
  FFV1_0( w[46], w[47], w[65], COUPs[1], &amp[0] );
#ifdef MGONGPU_SUPPORTS_MULTICHANNEL
  if( channelId == 928 ) allNumerators[0] += cxabs2( amp[0] );
  if( channelId != 0 ) allDenominators[0] += cxabs2( amp[0] );
#endif
  jamp[97] += amp[0];
  jamp[100] -= amp[0];
  jamp[106] -= amp[0];
  jamp[116] += amp[0];

  // *** DIAGRAM 929 OF 1240 ***

  // Wavefunction(s) for diagram number 929
  // (none)

  // Amplitude(s) for diagram number 929
  FFV1_0( w[46], w[113], w[66], COUPs[1], &amp[0] );
#ifdef MGONGPU_SUPPORTS_MULTICHANNEL
  if( channelId == 929 ) allNumerators[0] += cxabs2( amp[0] );
  if( channelId != 0 ) allDenominators[0] += cxabs2( amp[0] );
#endif
  jamp[97] += cxtype( 0, 1 ) * amp[0];
  jamp[100] -= cxtype( 0, 1 ) * amp[0];

  // *** DIAGRAM 930 OF 1240 ***

  // Wavefunction(s) for diagram number 930
  // (none)

  // Amplitude(s) for diagram number 930
  FFV1_0( w[99], w[47], w[66], COUPs[1], &amp[0] );
#ifdef MGONGPU_SUPPORTS_MULTICHANNEL
  if( channelId == 930 ) allNumerators[0] += cxabs2( amp[0] );
  if( channelId != 0 ) allDenominators[0] += cxabs2( amp[0] );
#endif
  jamp[106] += cxtype( 0, 1 ) * amp[0];
  jamp[116] -= cxtype( 0, 1 ) * amp[0];

  // *** DIAGRAM 931 OF 1240 ***

  // Wavefunction(s) for diagram number 931
  // (none)

  // Amplitude(s) for diagram number 931
  VVV1_0( w[65], w[54], w[6], COUPs[0], &amp[0] );
#ifdef MGONGPU_SUPPORTS_MULTICHANNEL
  if( channelId == 931 ) allNumerators[0] += cxabs2( amp[0] );
  if( channelId != 0 ) allDenominators[0] += cxabs2( amp[0] );
#endif
  jamp[3] += cxtype( 0, 1 ) * amp[0];
  jamp[13] -= cxtype( 0, 1 ) * amp[0];
  jamp[37] -= cxtype( 0, 1 ) * amp[0];
  jamp[79] += cxtype( 0, 1 ) * amp[0];
  jamp[97] -= cxtype( 0, 1 ) * amp[0];
  jamp[100] += cxtype( 0, 1 ) * amp[0];
  jamp[106] += cxtype( 0, 1 ) * amp[0];
  jamp[116] -= cxtype( 0, 1 ) * amp[0];

  // *** DIAGRAM 932 OF 1240 ***

  // Wavefunction(s) for diagram number 932
  // (none)

  // Amplitude(s) for diagram number 932
  FFV1_0( w[53], w[2], w[65], COUPs[1], &amp[0] );
#ifdef MGONGPU_SUPPORTS_MULTICHANNEL
  if( channelId == 932 ) allNumerators[0] += cxabs2( amp[0] );
  if( channelId != 0 ) allDenominators[0] += cxabs2( amp[0] );
#endif
  jamp[3] += amp[0];
  jamp[13] -= amp[0];
  jamp[37] -= amp[0];
  jamp[79] += amp[0];

  // *** DIAGRAM 933 OF 1240 ***

  // Wavefunction(s) for diagram number 933
  // (none)

  // Amplitude(s) for diagram number 933
  FFV1_0( w[99], w[94], w[6], COUPs[1], &amp[0] );
#ifdef MGONGPU_SUPPORTS_MULTICHANNEL
  if( channelId == 933 ) allNumerators[0] += cxabs2( amp[0] );
  if( channelId != 0 ) allDenominators[0] += cxabs2( amp[0] );
#endif
  jamp[40] += cxtype( 0, 1 ) * amp[0];
  jamp[82] -= cxtype( 0, 1 ) * amp[0];

  // *** DIAGRAM 934 OF 1240 ***

  // Wavefunction(s) for diagram number 934
  // (none)

  // Amplitude(s) for diagram number 934
  FFV1_0( w[99], w[2], w[70], COUPs[1], &amp[0] );
#ifdef MGONGPU_SUPPORTS_MULTICHANNEL
  if( channelId == 934 ) allNumerators[0] += cxabs2( amp[0] );
  if( channelId != 0 ) allDenominators[0] += cxabs2( amp[0] );
#endif
  jamp[40] += amp[0];
  jamp[82] -= amp[0];
  jamp[106] -= amp[0];
  jamp[116] += amp[0];

  // *** DIAGRAM 935 OF 1240 ***

  // Wavefunction(s) for diagram number 935
  // (none)

  // Amplitude(s) for diagram number 935
  FFV1_0( w[53], w[94], w[0], COUPs[1], &amp[0] );
#ifdef MGONGPU_SUPPORTS_MULTICHANNEL
  if( channelId == 935 ) allNumerators[0] += cxabs2( amp[0] );
  if( channelId != 0 ) allDenominators[0] += cxabs2( amp[0] );
#endif
  jamp[37] += cxtype( 0, 1 ) * amp[0];
  jamp[79] -= cxtype( 0, 1 ) * amp[0];

  // *** DIAGRAM 936 OF 1240 ***

  // Wavefunction(s) for diagram number 936
  // (none)

  // Amplitude(s) for diagram number 936
  VVV1_0( w[0], w[70], w[54], COUPs[0], &amp[0] );
#ifdef MGONGPU_SUPPORTS_MULTICHANNEL
  if( channelId == 936 ) allNumerators[0] += cxabs2( amp[0] );
  if( channelId != 0 ) allDenominators[0] += cxabs2( amp[0] );
#endif
  jamp[3] -= cxtype( 0, 1 ) * amp[0];
  jamp[13] += cxtype( 0, 1 ) * amp[0];
  jamp[19] += cxtype( 0, 1 ) * amp[0];
  jamp[22] -= cxtype( 0, 1 ) * amp[0];
  jamp[40] += cxtype( 0, 1 ) * amp[0];
  jamp[82] -= cxtype( 0, 1 ) * amp[0];
  jamp[106] -= cxtype( 0, 1 ) * amp[0];
  jamp[116] += cxtype( 0, 1 ) * amp[0];

  // *** DIAGRAM 937 OF 1240 ***

  // Wavefunction(s) for diagram number 937
  // (none)

  // Amplitude(s) for diagram number 937
  FFV1_0( w[46], w[2], w[22], COUPs[1], &amp[0] );
  jamp[3] -= cxtype( 0, 1 ) * amp[0];
  jamp[13] += cxtype( 0, 1 ) * amp[0];
  jamp[19] += cxtype( 0, 1 ) * amp[0];
  jamp[22] -= cxtype( 0, 1 ) * amp[0];
  jamp[40] += cxtype( 0, 1 ) * amp[0];
  jamp[82] -= cxtype( 0, 1 ) * amp[0];
  jamp[106] -= cxtype( 0, 1 ) * amp[0];
  jamp[116] += cxtype( 0, 1 ) * amp[0];
  FFV1_0( w[46], w[2], w[103], COUPs[1], &amp[0] );
  jamp[19] += cxtype( 0, 1 ) * amp[0];
  jamp[22] -= cxtype( 0, 1 ) * amp[0];
  jamp[37] -= cxtype( 0, 1 ) * amp[0];
  jamp[40] += cxtype( 0, 1 ) * amp[0];
  jamp[79] += cxtype( 0, 1 ) * amp[0];
  jamp[82] -= cxtype( 0, 1 ) * amp[0];
  jamp[97] -= cxtype( 0, 1 ) * amp[0];
  jamp[100] += cxtype( 0, 1 ) * amp[0];
  FFV1_0( w[46], w[2], w[63], COUPs[1], &amp[0] );
  jamp[3] += cxtype( 0, 1 ) * amp[0];
  jamp[13] -= cxtype( 0, 1 ) * amp[0];
  jamp[37] -= cxtype( 0, 1 ) * amp[0];
  jamp[79] += cxtype( 0, 1 ) * amp[0];
  jamp[97] -= cxtype( 0, 1 ) * amp[0];
  jamp[100] += cxtype( 0, 1 ) * amp[0];
  jamp[106] += cxtype( 0, 1 ) * amp[0];
  jamp[116] -= cxtype( 0, 1 ) * amp[0];

  // *** DIAGRAM 938 OF 1240 ***

  // Wavefunction(s) for diagram number 938
  // (none)

  // Amplitude(s) for diagram number 938
  VVV1_0( w[65], w[20], w[4], COUPs[0], &amp[0] );
#ifdef MGONGPU_SUPPORTS_MULTICHANNEL
  if( channelId == 938 ) allNumerators[0] += cxabs2( amp[0] );
  if( channelId != 0 ) allDenominators[0] += cxabs2( amp[0] );
#endif
  jamp[2] += cxtype( 0, 1 ) * amp[0];
  jamp[12] -= cxtype( 0, 1 ) * amp[0];
  jamp[36] -= cxtype( 0, 1 ) * amp[0];
  jamp[48] -= cxtype( 0, 1 ) * amp[0];
  jamp[50] += cxtype( 0, 1 ) * amp[0];
  jamp[56] += cxtype( 0, 1 ) * amp[0];
  jamp[62] -= cxtype( 0, 1 ) * amp[0];
  jamp[78] += cxtype( 0, 1 ) * amp[0];

  // *** DIAGRAM 939 OF 1240 ***

  // Wavefunction(s) for diagram number 939
  // (none)

  // Amplitude(s) for diagram number 939
  FFV1_0( w[28], w[2], w[65], COUPs[1], &amp[0] );
#ifdef MGONGPU_SUPPORTS_MULTICHANNEL
  if( channelId == 939 ) allNumerators[0] += cxabs2( amp[0] );
  if( channelId != 0 ) allDenominators[0] += cxabs2( amp[0] );
#endif
  jamp[2] += amp[0];
  jamp[12] -= amp[0];
  jamp[36] -= amp[0];
  jamp[78] += amp[0];

  // *** DIAGRAM 940 OF 1240 ***

  // Wavefunction(s) for diagram number 940
  // (none)

  // Amplitude(s) for diagram number 940
  FFV1_0( w[62], w[94], w[4], COUPs[1], &amp[0] );
#ifdef MGONGPU_SUPPORTS_MULTICHANNEL
  if( channelId == 940 ) allNumerators[0] += cxabs2( amp[0] );
  if( channelId != 0 ) allDenominators[0] += cxabs2( amp[0] );
#endif
  jamp[38] += cxtype( 0, 1 ) * amp[0];
  jamp[80] -= cxtype( 0, 1 ) * amp[0];

  // *** DIAGRAM 941 OF 1240 ***

  // Wavefunction(s) for diagram number 941
  // (none)

  // Amplitude(s) for diagram number 941
  FFV1_0( w[62], w[2], w[69], COUPs[1], &amp[0] );
#ifdef MGONGPU_SUPPORTS_MULTICHANNEL
  if( channelId == 941 ) allNumerators[0] += cxabs2( amp[0] );
  if( channelId != 0 ) allDenominators[0] += cxabs2( amp[0] );
#endif
  jamp[38] += amp[0];
  jamp[56] -= amp[0];
  jamp[62] += amp[0];
  jamp[80] -= amp[0];

  // *** DIAGRAM 942 OF 1240 ***

  // Wavefunction(s) for diagram number 942
  // (none)

  // Amplitude(s) for diagram number 942
  FFV1_0( w[28], w[94], w[0], COUPs[1], &amp[0] );
#ifdef MGONGPU_SUPPORTS_MULTICHANNEL
  if( channelId == 942 ) allNumerators[0] += cxabs2( amp[0] );
  if( channelId != 0 ) allDenominators[0] += cxabs2( amp[0] );
#endif
  jamp[36] += cxtype( 0, 1 ) * amp[0];
  jamp[78] -= cxtype( 0, 1 ) * amp[0];

  // *** DIAGRAM 943 OF 1240 ***

  // Wavefunction(s) for diagram number 943
  // (none)

  // Amplitude(s) for diagram number 943
  VVV1_0( w[0], w[69], w[20], COUPs[0], &amp[0] );
#ifdef MGONGPU_SUPPORTS_MULTICHANNEL
  if( channelId == 943 ) allNumerators[0] += cxabs2( amp[0] );
  if( channelId != 0 ) allDenominators[0] += cxabs2( amp[0] );
#endif
  jamp[2] -= cxtype( 0, 1 ) * amp[0];
  jamp[6] += cxtype( 0, 1 ) * amp[0];
  jamp[8] -= cxtype( 0, 1 ) * amp[0];
  jamp[12] += cxtype( 0, 1 ) * amp[0];
  jamp[38] += cxtype( 0, 1 ) * amp[0];
  jamp[56] -= cxtype( 0, 1 ) * amp[0];
  jamp[62] += cxtype( 0, 1 ) * amp[0];
  jamp[80] -= cxtype( 0, 1 ) * amp[0];

  // *** DIAGRAM 944 OF 1240 ***

  // Wavefunction(s) for diagram number 944
  // (none)

  // Amplitude(s) for diagram number 944
  FFV1_0( w[41], w[2], w[93], COUPs[1], &amp[0] );
  jamp[2] -= cxtype( 0, 1 ) * amp[0];
  jamp[6] += cxtype( 0, 1 ) * amp[0];
  jamp[8] -= cxtype( 0, 1 ) * amp[0];
  jamp[12] += cxtype( 0, 1 ) * amp[0];
  jamp[38] += cxtype( 0, 1 ) * amp[0];
  jamp[56] -= cxtype( 0, 1 ) * amp[0];
  jamp[62] += cxtype( 0, 1 ) * amp[0];
  jamp[80] -= cxtype( 0, 1 ) * amp[0];
  FFV1_0( w[41], w[2], w[90], COUPs[1], &amp[0] );
  jamp[6] += cxtype( 0, 1 ) * amp[0];
  jamp[8] -= cxtype( 0, 1 ) * amp[0];
  jamp[36] -= cxtype( 0, 1 ) * amp[0];
  jamp[38] += cxtype( 0, 1 ) * amp[0];
  jamp[48] -= cxtype( 0, 1 ) * amp[0];
  jamp[50] += cxtype( 0, 1 ) * amp[0];
  jamp[78] += cxtype( 0, 1 ) * amp[0];
  jamp[80] -= cxtype( 0, 1 ) * amp[0];
  FFV1_0( w[41], w[2], w[21], COUPs[1], &amp[0] );
  jamp[2] += cxtype( 0, 1 ) * amp[0];
  jamp[12] -= cxtype( 0, 1 ) * amp[0];
  jamp[36] -= cxtype( 0, 1 ) * amp[0];
  jamp[48] -= cxtype( 0, 1 ) * amp[0];
  jamp[50] += cxtype( 0, 1 ) * amp[0];
  jamp[56] += cxtype( 0, 1 ) * amp[0];
  jamp[62] -= cxtype( 0, 1 ) * amp[0];
  jamp[78] += cxtype( 0, 1 ) * amp[0];

  // *** DIAGRAM 945 OF 1240 ***

  // Wavefunction(s) for diagram number 945
  // (none)

  // Amplitude(s) for diagram number 945
  FFV1_0( w[3], w[15], w[65], COUPs[1], &amp[0] );
#ifdef MGONGPU_SUPPORTS_MULTICHANNEL
  if( channelId == 945 ) allNumerators[0] += cxabs2( amp[0] );
  if( channelId != 0 ) allDenominators[0] += cxabs2( amp[0] );
#endif
  jamp[66] -= cxtype( 0, 1 ) * amp[0];
  jamp[67] += cxtype( 0, 1 ) * amp[0];
  jamp[69] += cxtype( 0, 1 ) * amp[0];
  jamp[71] -= cxtype( 0, 1 ) * amp[0];
  jamp[108] += cxtype( 0, 1 ) * amp[0];
  jamp[109] -= cxtype( 0, 1 ) * amp[0];
  jamp[111] -= cxtype( 0, 1 ) * amp[0];
  jamp[113] += cxtype( 0, 1 ) * amp[0];

  // *** DIAGRAM 946 OF 1240 ***

  // Wavefunction(s) for diagram number 946
  // (none)

  // Amplitude(s) for diagram number 946
  FFV1_0( w[14], w[2], w[65], COUPs[1], &amp[0] );
#ifdef MGONGPU_SUPPORTS_MULTICHANNEL
  if( channelId == 946 ) allNumerators[0] += cxabs2( amp[0] );
  if( channelId != 0 ) allDenominators[0] += cxabs2( amp[0] );
#endif
  jamp[2] -= cxtype( 0, 1 ) * amp[0];
  jamp[3] += cxtype( 0, 1 ) * amp[0];
  jamp[12] += cxtype( 0, 1 ) * amp[0];
  jamp[13] -= cxtype( 0, 1 ) * amp[0];
  jamp[36] += cxtype( 0, 1 ) * amp[0];
  jamp[37] -= cxtype( 0, 1 ) * amp[0];
  jamp[78] -= cxtype( 0, 1 ) * amp[0];
  jamp[79] += cxtype( 0, 1 ) * amp[0];

  // *** DIAGRAM 947 OF 1240 ***

  // Wavefunction(s) for diagram number 947
  // (none)

  // Amplitude(s) for diagram number 947
  FFV1_0( w[3], w[94], w[101], COUPs[1], &amp[0] );
#ifdef MGONGPU_SUPPORTS_MULTICHANNEL
  if( channelId == 947 ) allNumerators[0] += cxabs2( amp[0] );
  if( channelId != 0 ) allDenominators[0] += cxabs2( amp[0] );
#endif
  jamp[36] -= cxtype( 0, 1 ) * amp[0];
  jamp[37] += cxtype( 0, 1 ) * amp[0];
  jamp[39] += cxtype( 0, 1 ) * amp[0];
  jamp[41] -= cxtype( 0, 1 ) * amp[0];
  jamp[78] += cxtype( 0, 1 ) * amp[0];
  jamp[79] -= cxtype( 0, 1 ) * amp[0];
  jamp[81] -= cxtype( 0, 1 ) * amp[0];
  jamp[83] += cxtype( 0, 1 ) * amp[0];

  // *** DIAGRAM 948 OF 1240 ***

  // Wavefunction(s) for diagram number 948
  // (none)

  // Amplitude(s) for diagram number 948
  FFV1_0( w[71], w[2], w[101], COUPs[1], &amp[0] );
#ifdef MGONGPU_SUPPORTS_MULTICHANNEL
  if( channelId == 948 ) allNumerators[0] += cxabs2( amp[0] );
  if( channelId != 0 ) allDenominators[0] += cxabs2( amp[0] );
#endif
  jamp[10] -= cxtype( 0, 1 ) * amp[0];
  jamp[11] += cxtype( 0, 1 ) * amp[0];
  jamp[20] += cxtype( 0, 1 ) * amp[0];
  jamp[21] -= cxtype( 0, 1 ) * amp[0];
  jamp[66] += cxtype( 0, 1 ) * amp[0];
  jamp[67] -= cxtype( 0, 1 ) * amp[0];
  jamp[108] -= cxtype( 0, 1 ) * amp[0];
  jamp[109] += cxtype( 0, 1 ) * amp[0];

  // *** DIAGRAM 949 OF 1240 ***

  // Wavefunction(s) for diagram number 949
  // (none)

  // Amplitude(s) for diagram number 949
  FFV1_0( w[14], w[94], w[0], COUPs[1], &amp[0] );
#ifdef MGONGPU_SUPPORTS_MULTICHANNEL
  if( channelId == 949 ) allNumerators[0] += cxabs2( amp[0] );
  if( channelId != 0 ) allDenominators[0] += cxabs2( amp[0] );
#endif
  jamp[36] += amp[0];
  jamp[37] -= amp[0];
  jamp[78] -= amp[0];
  jamp[79] += amp[0];

  // *** DIAGRAM 950 OF 1240 ***

  // Wavefunction(s) for diagram number 950
  // (none)

  // Amplitude(s) for diagram number 950
  FFV1_0( w[71], w[15], w[0], COUPs[1], &amp[0] );
#ifdef MGONGPU_SUPPORTS_MULTICHANNEL
  if( channelId == 950 ) allNumerators[0] += cxabs2( amp[0] );
  if( channelId != 0 ) allDenominators[0] += cxabs2( amp[0] );
#endif
  jamp[66] += amp[0];
  jamp[67] -= amp[0];
  jamp[108] -= amp[0];
  jamp[109] += amp[0];

  // *** DIAGRAM 951 OF 1240 ***

  // Wavefunction(s) for diagram number 951
  VVV1P0_1( w[0], w[72], COUPs[0], 0., 0., w[71] );

  // Amplitude(s) for diagram number 951
  VVV1_0( w[71], w[13], w[5], COUPs[0], &amp[0] );
#ifdef MGONGPU_SUPPORTS_MULTICHANNEL
  if( channelId == 951 ) allNumerators[0] += cxabs2( amp[0] );
  if( channelId != 0 ) allDenominators[0] += cxabs2( amp[0] );
#endif
  jamp[5] -= amp[0];
  jamp[19] += amp[0];
  jamp[43] += amp[0];
  jamp[49] += amp[0];
  jamp[52] -= amp[0];
  jamp[58] -= amp[0];
  jamp[60] -= amp[0];
  jamp[61] += amp[0];
  jamp[63] += amp[0];
  jamp[65] -= amp[0];
  jamp[68] += amp[0];
  jamp[73] += amp[0];
  jamp[76] -= amp[0];
  jamp[82] -= amp[0];
  jamp[92] += amp[0];
  jamp[103] -= amp[0];

  // *** DIAGRAM 952 OF 1240 ***

  // Wavefunction(s) for diagram number 952
  // (none)

  // Amplitude(s) for diagram number 952
  VVV1_0( w[71], w[10], w[4], COUPs[0], &amp[0] );
#ifdef MGONGPU_SUPPORTS_MULTICHANNEL
  if( channelId == 952 ) allNumerators[0] += cxabs2( amp[0] );
  if( channelId != 0 ) allDenominators[0] += cxabs2( amp[0] );
#endif
  jamp[4] -= amp[0];
  jamp[18] += amp[0];
  jamp[42] += amp[0];
  jamp[49] += amp[0];
  jamp[52] -= amp[0];
  jamp[58] -= amp[0];
  jamp[68] += amp[0];
  jamp[73] += amp[0];
  jamp[76] -= amp[0];
  jamp[82] -= amp[0];
  jamp[84] -= amp[0];
  jamp[85] += amp[0];
  jamp[87] += amp[0];
  jamp[89] -= amp[0];
  jamp[92] += amp[0];
  jamp[102] -= amp[0];

  // *** DIAGRAM 953 OF 1240 ***

  // Wavefunction(s) for diagram number 953
  // (none)

  // Amplitude(s) for diagram number 953
  VVVV1_0( w[8], w[4], w[5], w[71], COUPs[2], &amp[0] );
  jamp[5] -= amp[0];
  jamp[19] += amp[0];
  jamp[43] += amp[0];
  jamp[49] += amp[0];
  jamp[52] -= amp[0];
  jamp[58] -= amp[0];
  jamp[60] -= amp[0];
  jamp[61] += amp[0];
  jamp[63] += amp[0];
  jamp[65] -= amp[0];
  jamp[68] += amp[0];
  jamp[73] += amp[0];
  jamp[76] -= amp[0];
  jamp[82] -= amp[0];
  jamp[92] += amp[0];
  jamp[103] -= amp[0];
  VVVV3_0( w[8], w[4], w[5], w[71], COUPs[2], &amp[0] );
  jamp[4] -= amp[0];
  jamp[18] += amp[0];
  jamp[42] += amp[0];
  jamp[49] += amp[0];
  jamp[52] -= amp[0];
  jamp[58] -= amp[0];
  jamp[68] += amp[0];
  jamp[73] += amp[0];
  jamp[76] -= amp[0];
  jamp[82] -= amp[0];
  jamp[84] -= amp[0];
  jamp[85] += amp[0];
  jamp[87] += amp[0];
  jamp[89] -= amp[0];
  jamp[92] += amp[0];
  jamp[102] -= amp[0];
  VVVV4_0( w[8], w[4], w[5], w[71], COUPs[2], &amp[0] );
  jamp[4] -= amp[0];
  jamp[5] += amp[0];
  jamp[18] += amp[0];
  jamp[19] -= amp[0];
  jamp[42] += amp[0];
  jamp[43] -= amp[0];
  jamp[60] += amp[0];
  jamp[61] -= amp[0];
  jamp[63] -= amp[0];
  jamp[65] += amp[0];
  jamp[84] -= amp[0];
  jamp[85] += amp[0];
  jamp[87] += amp[0];
  jamp[89] -= amp[0];
  jamp[102] -= amp[0];
  jamp[103] += amp[0];

  // *** DIAGRAM 954 OF 1240 ***

  // Wavefunction(s) for diagram number 954
  // (none)

  // Amplitude(s) for diagram number 954
  VVV1_0( w[56], w[74], w[5], COUPs[0], &amp[0] );
#ifdef MGONGPU_SUPPORTS_MULTICHANNEL
  if( channelId == 954 ) allNumerators[0] += cxabs2( amp[0] );
  if( channelId != 0 ) allDenominators[0] += cxabs2( amp[0] );
#endif
  jamp[4] += amp[0];
  jamp[7] -= amp[0];
  jamp[10] += amp[0];
  jamp[13] -= amp[0];
  jamp[14] += amp[0];
  jamp[15] -= amp[0];
  jamp[16] += amp[0];
  jamp[18] -= amp[0];
  jamp[45] -= amp[0];
  jamp[59] += amp[0];
  jamp[69] -= amp[0];
  jamp[83] += amp[0];
  jamp[87] -= amp[0];
  jamp[89] += amp[0];
  jamp[93] -= amp[0];
  jamp[105] += amp[0];

  // *** DIAGRAM 955 OF 1240 ***

  // Wavefunction(s) for diagram number 955
  // (none)

  // Amplitude(s) for diagram number 955
  VVV1_0( w[56], w[75], w[4], COUPs[0], &amp[0] );
#ifdef MGONGPU_SUPPORTS_MULTICHANNEL
  if( channelId == 955 ) allNumerators[0] += cxabs2( amp[0] );
  if( channelId != 0 ) allDenominators[0] += cxabs2( amp[0] );
#endif
  jamp[5] += amp[0];
  jamp[7] -= amp[0];
  jamp[8] += amp[0];
  jamp[9] -= amp[0];
  jamp[10] += amp[0];
  jamp[13] -= amp[0];
  jamp[16] += amp[0];
  jamp[19] -= amp[0];
  jamp[47] -= amp[0];
  jamp[59] += amp[0];
  jamp[63] -= amp[0];
  jamp[65] += amp[0];
  jamp[69] -= amp[0];
  jamp[83] += amp[0];
  jamp[93] -= amp[0];
  jamp[107] += amp[0];

  // *** DIAGRAM 956 OF 1240 ***

  // Wavefunction(s) for diagram number 956
  // (none)

  // Amplitude(s) for diagram number 956
  VVVV1_0( w[72], w[4], w[5], w[56], COUPs[2], &amp[0] );
  jamp[4] += amp[0];
  jamp[7] -= amp[0];
  jamp[10] += amp[0];
  jamp[13] -= amp[0];
  jamp[14] += amp[0];
  jamp[15] -= amp[0];
  jamp[16] += amp[0];
  jamp[18] -= amp[0];
  jamp[45] -= amp[0];
  jamp[59] += amp[0];
  jamp[69] -= amp[0];
  jamp[83] += amp[0];
  jamp[87] -= amp[0];
  jamp[89] += amp[0];
  jamp[93] -= amp[0];
  jamp[105] += amp[0];
  VVVV3_0( w[72], w[4], w[5], w[56], COUPs[2], &amp[0] );
  jamp[5] += amp[0];
  jamp[7] -= amp[0];
  jamp[8] += amp[0];
  jamp[9] -= amp[0];
  jamp[10] += amp[0];
  jamp[13] -= amp[0];
  jamp[16] += amp[0];
  jamp[19] -= amp[0];
  jamp[47] -= amp[0];
  jamp[59] += amp[0];
  jamp[63] -= amp[0];
  jamp[65] += amp[0];
  jamp[69] -= amp[0];
  jamp[83] += amp[0];
  jamp[93] -= amp[0];
  jamp[107] += amp[0];
  VVVV4_0( w[72], w[4], w[5], w[56], COUPs[2], &amp[0] );
  jamp[4] -= amp[0];
  jamp[5] += amp[0];
  jamp[8] += amp[0];
  jamp[9] -= amp[0];
  jamp[14] -= amp[0];
  jamp[15] += amp[0];
  jamp[18] += amp[0];
  jamp[19] -= amp[0];
  jamp[45] += amp[0];
  jamp[47] -= amp[0];
  jamp[63] -= amp[0];
  jamp[65] += amp[0];
  jamp[87] += amp[0];
  jamp[89] -= amp[0];
  jamp[105] -= amp[0];
  jamp[107] += amp[0];

  // *** DIAGRAM 957 OF 1240 ***

  // Wavefunction(s) for diagram number 957
  // (none)

  // Amplitude(s) for diagram number 957
  VVV1_0( w[0], w[74], w[10], COUPs[0], &amp[0] );
#ifdef MGONGPU_SUPPORTS_MULTICHANNEL
  if( channelId == 957 ) allNumerators[0] += cxabs2( amp[0] );
  if( channelId != 0 ) allDenominators[0] += cxabs2( amp[0] );
#endif
  jamp[4] += amp[0];
  jamp[7] -= amp[0];
  jamp[10] += amp[0];
  jamp[18] -= amp[0];
  jamp[44] -= amp[0];
  jamp[58] += amp[0];
  jamp[68] -= amp[0];
  jamp[73] -= amp[0];
  jamp[74] += amp[0];
  jamp[75] -= amp[0];
  jamp[76] += amp[0];
  jamp[83] += amp[0];
  jamp[87] -= amp[0];
  jamp[89] += amp[0];
  jamp[93] -= amp[0];
  jamp[104] += amp[0];

  // *** DIAGRAM 958 OF 1240 ***

  // Wavefunction(s) for diagram number 958
  // (none)

  // Amplitude(s) for diagram number 958
  VVV1_0( w[0], w[75], w[13], COUPs[0], &amp[0] );
#ifdef MGONGPU_SUPPORTS_MULTICHANNEL
  if( channelId == 958 ) allNumerators[0] += cxabs2( amp[0] );
  if( channelId != 0 ) allDenominators[0] += cxabs2( amp[0] );
#endif
  jamp[5] += amp[0];
  jamp[13] -= amp[0];
  jamp[16] += amp[0];
  jamp[19] -= amp[0];
  jamp[46] -= amp[0];
  jamp[49] -= amp[0];
  jamp[50] += amp[0];
  jamp[51] -= amp[0];
  jamp[52] += amp[0];
  jamp[59] += amp[0];
  jamp[63] -= amp[0];
  jamp[65] += amp[0];
  jamp[69] -= amp[0];
  jamp[82] += amp[0];
  jamp[92] -= amp[0];
  jamp[106] += amp[0];

  // *** DIAGRAM 959 OF 1240 ***

  // Wavefunction(s) for diagram number 959
  VVVV1P0_1( w[0], w[72], w[4], COUPs[2], 0., 0., w[94] );
  VVVV3P0_1( w[0], w[72], w[4], COUPs[2], 0., 0., w[65] );
  VVVV4P0_1( w[0], w[72], w[4], COUPs[2], 0., 0., w[21] );

  // Amplitude(s) for diagram number 959
  VVV1_0( w[8], w[5], w[94], COUPs[0], &amp[0] );
  jamp[4] += amp[0];
  jamp[7] -= amp[0];
  jamp[10] += amp[0];
  jamp[18] -= amp[0];
  jamp[44] -= amp[0];
  jamp[58] += amp[0];
  jamp[68] -= amp[0];
  jamp[73] -= amp[0];
  jamp[74] += amp[0];
  jamp[75] -= amp[0];
  jamp[76] += amp[0];
  jamp[83] += amp[0];
  jamp[87] -= amp[0];
  jamp[89] += amp[0];
  jamp[93] -= amp[0];
  jamp[104] += amp[0];
  VVV1_0( w[8], w[5], w[65], COUPs[0], &amp[0] );
  jamp[7] -= amp[0];
  jamp[10] += amp[0];
  jamp[42] += amp[0];
  jamp[44] -= amp[0];
  jamp[49] += amp[0];
  jamp[52] -= amp[0];
  jamp[74] += amp[0];
  jamp[75] -= amp[0];
  jamp[82] -= amp[0];
  jamp[83] += amp[0];
  jamp[84] -= amp[0];
  jamp[85] += amp[0];
  jamp[92] += amp[0];
  jamp[93] -= amp[0];
  jamp[102] -= amp[0];
  jamp[104] += amp[0];
  VVV1_0( w[8], w[5], w[21], COUPs[0], &amp[0] );
  jamp[4] -= amp[0];
  jamp[18] += amp[0];
  jamp[42] += amp[0];
  jamp[49] += amp[0];
  jamp[52] -= amp[0];
  jamp[58] -= amp[0];
  jamp[68] += amp[0];
  jamp[73] += amp[0];
  jamp[76] -= amp[0];
  jamp[82] -= amp[0];
  jamp[84] -= amp[0];
  jamp[85] += amp[0];
  jamp[87] += amp[0];
  jamp[89] -= amp[0];
  jamp[92] += amp[0];
  jamp[102] -= amp[0];

  // *** DIAGRAM 960 OF 1240 ***

  // Wavefunction(s) for diagram number 960
  VVVV1P0_1( w[0], w[72], w[5], COUPs[2], 0., 0., w[90] );
  VVVV3P0_1( w[0], w[72], w[5], COUPs[2], 0., 0., w[93] );
  VVVV4P0_1( w[0], w[72], w[5], COUPs[2], 0., 0., w[69] );

  // Amplitude(s) for diagram number 960
  VVV1_0( w[8], w[4], w[90], COUPs[0], &amp[0] );
  jamp[5] += amp[0];
  jamp[13] -= amp[0];
  jamp[16] += amp[0];
  jamp[19] -= amp[0];
  jamp[46] -= amp[0];
  jamp[49] -= amp[0];
  jamp[50] += amp[0];
  jamp[51] -= amp[0];
  jamp[52] += amp[0];
  jamp[59] += amp[0];
  jamp[63] -= amp[0];
  jamp[65] += amp[0];
  jamp[69] -= amp[0];
  jamp[82] += amp[0];
  jamp[92] -= amp[0];
  jamp[106] += amp[0];
  VVV1_0( w[8], w[4], w[93], COUPs[0], &amp[0] );
  jamp[13] -= amp[0];
  jamp[16] += amp[0];
  jamp[43] += amp[0];
  jamp[46] -= amp[0];
  jamp[50] += amp[0];
  jamp[51] -= amp[0];
  jamp[58] -= amp[0];
  jamp[59] += amp[0];
  jamp[60] -= amp[0];
  jamp[61] += amp[0];
  jamp[68] += amp[0];
  jamp[69] -= amp[0];
  jamp[73] += amp[0];
  jamp[76] -= amp[0];
  jamp[103] -= amp[0];
  jamp[106] += amp[0];
  VVV1_0( w[8], w[4], w[69], COUPs[0], &amp[0] );
  jamp[5] -= amp[0];
  jamp[19] += amp[0];
  jamp[43] += amp[0];
  jamp[49] += amp[0];
  jamp[52] -= amp[0];
  jamp[58] -= amp[0];
  jamp[60] -= amp[0];
  jamp[61] += amp[0];
  jamp[63] += amp[0];
  jamp[65] -= amp[0];
  jamp[68] += amp[0];
  jamp[73] += amp[0];
  jamp[76] -= amp[0];
  jamp[82] -= amp[0];
  jamp[92] += amp[0];
  jamp[103] -= amp[0];

  // *** DIAGRAM 961 OF 1240 ***

  // Wavefunction(s) for diagram number 961
  // (none)

  // Amplitude(s) for diagram number 961
  VVV1_0( w[72], w[5], w[107], COUPs[0], &amp[0] );
  jamp[5] -= amp[0];
  jamp[13] += amp[0];
  jamp[16] -= amp[0];
  jamp[19] += amp[0];
  jamp[46] += amp[0];
  jamp[49] += amp[0];
  jamp[50] -= amp[0];
  jamp[51] += amp[0];
  jamp[52] -= amp[0];
  jamp[59] -= amp[0];
  jamp[63] += amp[0];
  jamp[65] -= amp[0];
  jamp[69] += amp[0];
  jamp[82] -= amp[0];
  jamp[92] += amp[0];
  jamp[106] -= amp[0];
  VVV1_0( w[72], w[5], w[95], COUPs[0], &amp[0] );
  jamp[7] -= amp[0];
  jamp[8] += amp[0];
  jamp[9] -= amp[0];
  jamp[10] += amp[0];
  jamp[46] += amp[0];
  jamp[47] -= amp[0];
  jamp[49] += amp[0];
  jamp[50] -= amp[0];
  jamp[51] += amp[0];
  jamp[52] -= amp[0];
  jamp[82] -= amp[0];
  jamp[83] += amp[0];
  jamp[92] += amp[0];
  jamp[93] -= amp[0];
  jamp[106] -= amp[0];
  jamp[107] += amp[0];
  VVV1_0( w[72], w[5], w[105], COUPs[0], &amp[0] );
  jamp[5] += amp[0];
  jamp[7] -= amp[0];
  jamp[8] += amp[0];
  jamp[9] -= amp[0];
  jamp[10] += amp[0];
  jamp[13] -= amp[0];
  jamp[16] += amp[0];
  jamp[19] -= amp[0];
  jamp[47] -= amp[0];
  jamp[59] += amp[0];
  jamp[63] -= amp[0];
  jamp[65] += amp[0];
  jamp[69] -= amp[0];
  jamp[83] += amp[0];
  jamp[93] -= amp[0];
  jamp[107] += amp[0];

  // *** DIAGRAM 962 OF 1240 ***

  // Wavefunction(s) for diagram number 962
  // (none)

  // Amplitude(s) for diagram number 962
  VVV1_0( w[72], w[4], w[115], COUPs[0], &amp[0] );
  jamp[4] -= amp[0];
  jamp[7] += amp[0];
  jamp[10] -= amp[0];
  jamp[18] += amp[0];
  jamp[44] += amp[0];
  jamp[58] -= amp[0];
  jamp[68] += amp[0];
  jamp[73] += amp[0];
  jamp[74] -= amp[0];
  jamp[75] += amp[0];
  jamp[76] -= amp[0];
  jamp[83] -= amp[0];
  jamp[87] += amp[0];
  jamp[89] -= amp[0];
  jamp[93] += amp[0];
  jamp[104] -= amp[0];
  VVV1_0( w[72], w[4], w[116], COUPs[0], &amp[0] );
  jamp[13] -= amp[0];
  jamp[14] += amp[0];
  jamp[15] -= amp[0];
  jamp[16] += amp[0];
  jamp[44] += amp[0];
  jamp[45] -= amp[0];
  jamp[58] -= amp[0];
  jamp[59] += amp[0];
  jamp[68] += amp[0];
  jamp[69] -= amp[0];
  jamp[73] += amp[0];
  jamp[74] -= amp[0];
  jamp[75] += amp[0];
  jamp[76] -= amp[0];
  jamp[104] -= amp[0];
  jamp[105] += amp[0];
  VVV1_0( w[72], w[4], w[117], COUPs[0], &amp[0] );
  jamp[4] += amp[0];
  jamp[7] -= amp[0];
  jamp[10] += amp[0];
  jamp[13] -= amp[0];
  jamp[14] += amp[0];
  jamp[15] -= amp[0];
  jamp[16] += amp[0];
  jamp[18] -= amp[0];
  jamp[45] -= amp[0];
  jamp[59] += amp[0];
  jamp[69] -= amp[0];
  jamp[83] += amp[0];
  jamp[87] -= amp[0];
  jamp[89] += amp[0];
  jamp[93] -= amp[0];
  jamp[105] += amp[0];

  // *** DIAGRAM 963 OF 1240 ***

  // Wavefunction(s) for diagram number 963
  // (none)

  // Amplitude(s) for diagram number 963
  VVVV1_0( w[0], w[72], w[8], w[24], COUPs[2], &amp[0] );
  jamp[4] += amp[0];
  jamp[5] -= amp[0];
  jamp[18] -= amp[0];
  jamp[19] += amp[0];
  jamp[42] -= amp[0];
  jamp[43] += amp[0];
  jamp[60] -= amp[0];
  jamp[61] += amp[0];
  jamp[63] += amp[0];
  jamp[65] -= amp[0];
  jamp[84] += amp[0];
  jamp[85] -= amp[0];
  jamp[87] -= amp[0];
  jamp[89] += amp[0];
  jamp[102] += amp[0];
  jamp[103] -= amp[0];
  VVVV3_0( w[0], w[72], w[8], w[24], COUPs[2], &amp[0] );
  jamp[4] += amp[0];
  jamp[5] -= amp[0];
  jamp[8] -= amp[0];
  jamp[9] += amp[0];
  jamp[14] += amp[0];
  jamp[15] -= amp[0];
  jamp[18] -= amp[0];
  jamp[19] += amp[0];
  jamp[45] -= amp[0];
  jamp[47] += amp[0];
  jamp[63] += amp[0];
  jamp[65] -= amp[0];
  jamp[87] -= amp[0];
  jamp[89] += amp[0];
  jamp[105] += amp[0];
  jamp[107] -= amp[0];
  VVVV4_0( w[0], w[72], w[8], w[24], COUPs[2], &amp[0] );
  jamp[8] -= amp[0];
  jamp[9] += amp[0];
  jamp[14] += amp[0];
  jamp[15] -= amp[0];
  jamp[42] += amp[0];
  jamp[43] -= amp[0];
  jamp[45] -= amp[0];
  jamp[47] += amp[0];
  jamp[60] += amp[0];
  jamp[61] -= amp[0];
  jamp[84] -= amp[0];
  jamp[85] += amp[0];
  jamp[102] -= amp[0];
  jamp[103] += amp[0];
  jamp[105] += amp[0];
  jamp[107] -= amp[0];

  // *** DIAGRAM 964 OF 1240 ***

  // Wavefunction(s) for diagram number 964
  // (none)

  // Amplitude(s) for diagram number 964
  VVV1_0( w[8], w[24], w[71], COUPs[0], &amp[0] );
#ifdef MGONGPU_SUPPORTS_MULTICHANNEL
  if( channelId == 964 ) allNumerators[0] += cxabs2( amp[0] );
  if( channelId != 0 ) allDenominators[0] += cxabs2( amp[0] );
#endif
  jamp[4] += amp[0];
  jamp[5] -= amp[0];
  jamp[18] -= amp[0];
  jamp[19] += amp[0];
  jamp[42] -= amp[0];
  jamp[43] += amp[0];
  jamp[60] -= amp[0];
  jamp[61] += amp[0];
  jamp[63] += amp[0];
  jamp[65] -= amp[0];
  jamp[84] += amp[0];
  jamp[85] -= amp[0];
  jamp[87] -= amp[0];
  jamp[89] += amp[0];
  jamp[102] += amp[0];
  jamp[103] -= amp[0];

  // *** DIAGRAM 965 OF 1240 ***

  // Wavefunction(s) for diagram number 965
  // (none)

  // Amplitude(s) for diagram number 965
  VVV1_0( w[72], w[24], w[56], COUPs[0], &amp[0] );
#ifdef MGONGPU_SUPPORTS_MULTICHANNEL
  if( channelId == 965 ) allNumerators[0] += cxabs2( amp[0] );
  if( channelId != 0 ) allDenominators[0] += cxabs2( amp[0] );
#endif
  jamp[4] += amp[0];
  jamp[5] -= amp[0];
  jamp[8] -= amp[0];
  jamp[9] += amp[0];
  jamp[14] += amp[0];
  jamp[15] -= amp[0];
  jamp[18] -= amp[0];
  jamp[19] += amp[0];
  jamp[45] -= amp[0];
  jamp[47] += amp[0];
  jamp[63] += amp[0];
  jamp[65] -= amp[0];
  jamp[87] -= amp[0];
  jamp[89] += amp[0];
  jamp[105] += amp[0];
  jamp[107] -= amp[0];

  // *** DIAGRAM 966 OF 1240 ***

  // Wavefunction(s) for diagram number 966
  // (none)

  // Amplitude(s) for diagram number 966
  VVV1_0( w[72], w[8], w[98], COUPs[0], &amp[0] );
#ifdef MGONGPU_SUPPORTS_MULTICHANNEL
  if( channelId == 966 ) allNumerators[0] += cxabs2( amp[0] );
  if( channelId != 0 ) allDenominators[0] += cxabs2( amp[0] );
#endif
  jamp[8] -= amp[0];
  jamp[9] += amp[0];
  jamp[14] += amp[0];
  jamp[15] -= amp[0];
  jamp[42] += amp[0];
  jamp[43] -= amp[0];
  jamp[45] -= amp[0];
  jamp[47] += amp[0];
  jamp[60] += amp[0];
  jamp[61] -= amp[0];
  jamp[84] -= amp[0];
  jamp[85] += amp[0];
  jamp[102] -= amp[0];
  jamp[103] += amp[0];
  jamp[105] += amp[0];
  jamp[107] -= amp[0];

  // *** DIAGRAM 967 OF 1240 ***

  // Wavefunction(s) for diagram number 967
  // (none)

  // Amplitude(s) for diagram number 967
  VVV1_0( w[71], w[37], w[5], COUPs[0], &amp[0] );
#ifdef MGONGPU_SUPPORTS_MULTICHANNEL
  if( channelId == 967 ) allNumerators[0] += cxabs2( amp[0] );
  if( channelId != 0 ) allDenominators[0] += cxabs2( amp[0] );
#endif
  jamp[49] += cxtype( 0, 1 ) * amp[0];
  jamp[52] -= cxtype( 0, 1 ) * amp[0];
  jamp[58] -= cxtype( 0, 1 ) * amp[0];
  jamp[60] -= cxtype( 0, 1 ) * amp[0];
  jamp[61] += cxtype( 0, 1 ) * amp[0];
  jamp[63] += cxtype( 0, 1 ) * amp[0];
  jamp[65] -= cxtype( 0, 1 ) * amp[0];
  jamp[68] += cxtype( 0, 1 ) * amp[0];

  // *** DIAGRAM 968 OF 1240 ***

  // Wavefunction(s) for diagram number 968
  // (none)

  // Amplitude(s) for diagram number 968
  FFV1_0( w[3], w[35], w[71], COUPs[1], &amp[0] );
#ifdef MGONGPU_SUPPORTS_MULTICHANNEL
  if( channelId == 968 ) allNumerators[0] += cxabs2( amp[0] );
  if( channelId != 0 ) allDenominators[0] += cxabs2( amp[0] );
#endif
  jamp[60] += amp[0];
  jamp[61] -= amp[0];
  jamp[63] -= amp[0];
  jamp[65] += amp[0];

  // *** DIAGRAM 969 OF 1240 ***

  // Wavefunction(s) for diagram number 969
  // (none)

  // Amplitude(s) for diagram number 969
  FFV1_0( w[76], w[114], w[5], COUPs[1], &amp[0] );
#ifdef MGONGPU_SUPPORTS_MULTICHANNEL
  if( channelId == 969 ) allNumerators[0] += cxabs2( amp[0] );
  if( channelId != 0 ) allDenominators[0] += cxabs2( amp[0] );
#endif
  jamp[50] += cxtype( 0, 1 ) * amp[0];
  jamp[51] -= cxtype( 0, 1 ) * amp[0];

  // *** DIAGRAM 970 OF 1240 ***

  // Wavefunction(s) for diagram number 970
  // (none)

  // Amplitude(s) for diagram number 970
  FFV1_0( w[3], w[114], w[75], COUPs[1], &amp[0] );
#ifdef MGONGPU_SUPPORTS_MULTICHANNEL
  if( channelId == 970 ) allNumerators[0] += cxabs2( amp[0] );
  if( channelId != 0 ) allDenominators[0] += cxabs2( amp[0] );
#endif
  jamp[49] += amp[0];
  jamp[50] -= amp[0];
  jamp[51] += amp[0];
  jamp[52] -= amp[0];

  // *** DIAGRAM 971 OF 1240 ***

  // Wavefunction(s) for diagram number 971
  // (none)

  // Amplitude(s) for diagram number 971
  FFV1_0( w[76], w[35], w[0], COUPs[1], &amp[0] );
#ifdef MGONGPU_SUPPORTS_MULTICHANNEL
  if( channelId == 971 ) allNumerators[0] += cxabs2( amp[0] );
  if( channelId != 0 ) allDenominators[0] += cxabs2( amp[0] );
#endif
  jamp[60] += cxtype( 0, 1 ) * amp[0];
  jamp[61] -= cxtype( 0, 1 ) * amp[0];

  // *** DIAGRAM 972 OF 1240 ***

  // Wavefunction(s) for diagram number 972
  // (none)

  // Amplitude(s) for diagram number 972
  VVV1_0( w[0], w[75], w[37], COUPs[0], &amp[0] );
#ifdef MGONGPU_SUPPORTS_MULTICHANNEL
  if( channelId == 972 ) allNumerators[0] += cxabs2( amp[0] );
  if( channelId != 0 ) allDenominators[0] += cxabs2( amp[0] );
#endif
  jamp[49] -= cxtype( 0, 1 ) * amp[0];
  jamp[50] += cxtype( 0, 1 ) * amp[0];
  jamp[51] -= cxtype( 0, 1 ) * amp[0];
  jamp[52] += cxtype( 0, 1 ) * amp[0];
  jamp[59] += cxtype( 0, 1 ) * amp[0];
  jamp[63] -= cxtype( 0, 1 ) * amp[0];
  jamp[65] += cxtype( 0, 1 ) * amp[0];
  jamp[69] -= cxtype( 0, 1 ) * amp[0];

  // *** DIAGRAM 973 OF 1240 ***

  // Wavefunction(s) for diagram number 973
  // (none)

  // Amplitude(s) for diagram number 973
  FFV1_0( w[3], w[33], w[90], COUPs[1], &amp[0] );
  jamp[49] -= cxtype( 0, 1 ) * amp[0];
  jamp[50] += cxtype( 0, 1 ) * amp[0];
  jamp[51] -= cxtype( 0, 1 ) * amp[0];
  jamp[52] += cxtype( 0, 1 ) * amp[0];
  jamp[59] += cxtype( 0, 1 ) * amp[0];
  jamp[63] -= cxtype( 0, 1 ) * amp[0];
  jamp[65] += cxtype( 0, 1 ) * amp[0];
  jamp[69] -= cxtype( 0, 1 ) * amp[0];
  FFV1_0( w[3], w[33], w[93], COUPs[1], &amp[0] );
  jamp[50] += cxtype( 0, 1 ) * amp[0];
  jamp[51] -= cxtype( 0, 1 ) * amp[0];
  jamp[58] -= cxtype( 0, 1 ) * amp[0];
  jamp[59] += cxtype( 0, 1 ) * amp[0];
  jamp[60] -= cxtype( 0, 1 ) * amp[0];
  jamp[61] += cxtype( 0, 1 ) * amp[0];
  jamp[68] += cxtype( 0, 1 ) * amp[0];
  jamp[69] -= cxtype( 0, 1 ) * amp[0];
  FFV1_0( w[3], w[33], w[69], COUPs[1], &amp[0] );
  jamp[49] += cxtype( 0, 1 ) * amp[0];
  jamp[52] -= cxtype( 0, 1 ) * amp[0];
  jamp[58] -= cxtype( 0, 1 ) * amp[0];
  jamp[60] -= cxtype( 0, 1 ) * amp[0];
  jamp[61] += cxtype( 0, 1 ) * amp[0];
  jamp[63] += cxtype( 0, 1 ) * amp[0];
  jamp[65] -= cxtype( 0, 1 ) * amp[0];
  jamp[68] += cxtype( 0, 1 ) * amp[0];

  // *** DIAGRAM 974 OF 1240 ***

  // Wavefunction(s) for diagram number 974
  // (none)

  // Amplitude(s) for diagram number 974
  FFV1_0( w[38], w[33], w[71], COUPs[1], &amp[0] );
#ifdef MGONGPU_SUPPORTS_MULTICHANNEL
  if( channelId == 974 ) allNumerators[0] += cxabs2( amp[0] );
  if( channelId != 0 ) allDenominators[0] += cxabs2( amp[0] );
#endif
  jamp[49] += amp[0];
  jamp[52] -= amp[0];
  jamp[58] -= amp[0];
  jamp[68] += amp[0];

  // *** DIAGRAM 975 OF 1240 ***

  // Wavefunction(s) for diagram number 975
  // (none)

  // Amplitude(s) for diagram number 975
  FFV1_0( w[38], w[114], w[72], COUPs[1], &amp[0] );
#ifdef MGONGPU_SUPPORTS_MULTICHANNEL
  if( channelId == 975 ) allNumerators[0] += cxabs2( amp[0] );
  if( channelId != 0 ) allDenominators[0] += cxabs2( amp[0] );
#endif
  jamp[49] += cxtype( 0, 1 ) * amp[0];
  jamp[52] -= cxtype( 0, 1 ) * amp[0];

  // *** DIAGRAM 976 OF 1240 ***

  // Wavefunction(s) for diagram number 976
  // (none)

  // Amplitude(s) for diagram number 976
  FFV1_0( w[104], w[33], w[72], COUPs[1], &amp[0] );
#ifdef MGONGPU_SUPPORTS_MULTICHANNEL
  if( channelId == 976 ) allNumerators[0] += cxabs2( amp[0] );
  if( channelId != 0 ) allDenominators[0] += cxabs2( amp[0] );
#endif
  jamp[58] += cxtype( 0, 1 ) * amp[0];
  jamp[68] -= cxtype( 0, 1 ) * amp[0];

  // *** DIAGRAM 977 OF 1240 ***

  // Wavefunction(s) for diagram number 977
  // (none)

  // Amplitude(s) for diagram number 977
  VVV1_0( w[71], w[45], w[4], COUPs[0], &amp[0] );
#ifdef MGONGPU_SUPPORTS_MULTICHANNEL
  if( channelId == 977 ) allNumerators[0] += cxabs2( amp[0] );
  if( channelId != 0 ) allDenominators[0] += cxabs2( amp[0] );
#endif
  jamp[73] += cxtype( 0, 1 ) * amp[0];
  jamp[76] -= cxtype( 0, 1 ) * amp[0];
  jamp[82] -= cxtype( 0, 1 ) * amp[0];
  jamp[84] -= cxtype( 0, 1 ) * amp[0];
  jamp[85] += cxtype( 0, 1 ) * amp[0];
  jamp[87] += cxtype( 0, 1 ) * amp[0];
  jamp[89] -= cxtype( 0, 1 ) * amp[0];
  jamp[92] += cxtype( 0, 1 ) * amp[0];

  // *** DIAGRAM 978 OF 1240 ***

  // Wavefunction(s) for diagram number 978
  // (none)

  // Amplitude(s) for diagram number 978
  FFV1_0( w[3], w[43], w[71], COUPs[1], &amp[0] );
#ifdef MGONGPU_SUPPORTS_MULTICHANNEL
  if( channelId == 978 ) allNumerators[0] += cxabs2( amp[0] );
  if( channelId != 0 ) allDenominators[0] += cxabs2( amp[0] );
#endif
  jamp[84] += amp[0];
  jamp[85] -= amp[0];
  jamp[87] -= amp[0];
  jamp[89] += amp[0];

  // *** DIAGRAM 979 OF 1240 ***

  // Wavefunction(s) for diagram number 979
  // (none)

  // Amplitude(s) for diagram number 979
  FFV1_0( w[76], w[102], w[4], COUPs[1], &amp[0] );
#ifdef MGONGPU_SUPPORTS_MULTICHANNEL
  if( channelId == 979 ) allNumerators[0] += cxabs2( amp[0] );
  if( channelId != 0 ) allDenominators[0] += cxabs2( amp[0] );
#endif
  jamp[74] += cxtype( 0, 1 ) * amp[0];
  jamp[75] -= cxtype( 0, 1 ) * amp[0];

  // *** DIAGRAM 980 OF 1240 ***

  // Wavefunction(s) for diagram number 980
  // (none)

  // Amplitude(s) for diagram number 980
  FFV1_0( w[3], w[102], w[74], COUPs[1], &amp[0] );
#ifdef MGONGPU_SUPPORTS_MULTICHANNEL
  if( channelId == 980 ) allNumerators[0] += cxabs2( amp[0] );
  if( channelId != 0 ) allDenominators[0] += cxabs2( amp[0] );
#endif
  jamp[73] += amp[0];
  jamp[74] -= amp[0];
  jamp[75] += amp[0];
  jamp[76] -= amp[0];

  // *** DIAGRAM 981 OF 1240 ***

  // Wavefunction(s) for diagram number 981
  // (none)

  // Amplitude(s) for diagram number 981
  FFV1_0( w[76], w[43], w[0], COUPs[1], &amp[0] );
#ifdef MGONGPU_SUPPORTS_MULTICHANNEL
  if( channelId == 981 ) allNumerators[0] += cxabs2( amp[0] );
  if( channelId != 0 ) allDenominators[0] += cxabs2( amp[0] );
#endif
  jamp[84] += cxtype( 0, 1 ) * amp[0];
  jamp[85] -= cxtype( 0, 1 ) * amp[0];

  // *** DIAGRAM 982 OF 1240 ***

  // Wavefunction(s) for diagram number 982
  // (none)

  // Amplitude(s) for diagram number 982
  VVV1_0( w[0], w[74], w[45], COUPs[0], &amp[0] );
#ifdef MGONGPU_SUPPORTS_MULTICHANNEL
  if( channelId == 982 ) allNumerators[0] += cxabs2( amp[0] );
  if( channelId != 0 ) allDenominators[0] += cxabs2( amp[0] );
#endif
  jamp[73] -= cxtype( 0, 1 ) * amp[0];
  jamp[74] += cxtype( 0, 1 ) * amp[0];
  jamp[75] -= cxtype( 0, 1 ) * amp[0];
  jamp[76] += cxtype( 0, 1 ) * amp[0];
  jamp[83] += cxtype( 0, 1 ) * amp[0];
  jamp[87] -= cxtype( 0, 1 ) * amp[0];
  jamp[89] += cxtype( 0, 1 ) * amp[0];
  jamp[93] -= cxtype( 0, 1 ) * amp[0];

  // *** DIAGRAM 983 OF 1240 ***

  // Wavefunction(s) for diagram number 983
  // (none)

  // Amplitude(s) for diagram number 983
  FFV1_0( w[3], w[39], w[94], COUPs[1], &amp[0] );
  jamp[73] -= cxtype( 0, 1 ) * amp[0];
  jamp[74] += cxtype( 0, 1 ) * amp[0];
  jamp[75] -= cxtype( 0, 1 ) * amp[0];
  jamp[76] += cxtype( 0, 1 ) * amp[0];
  jamp[83] += cxtype( 0, 1 ) * amp[0];
  jamp[87] -= cxtype( 0, 1 ) * amp[0];
  jamp[89] += cxtype( 0, 1 ) * amp[0];
  jamp[93] -= cxtype( 0, 1 ) * amp[0];
  FFV1_0( w[3], w[39], w[65], COUPs[1], &amp[0] );
  jamp[74] += cxtype( 0, 1 ) * amp[0];
  jamp[75] -= cxtype( 0, 1 ) * amp[0];
  jamp[82] -= cxtype( 0, 1 ) * amp[0];
  jamp[83] += cxtype( 0, 1 ) * amp[0];
  jamp[84] -= cxtype( 0, 1 ) * amp[0];
  jamp[85] += cxtype( 0, 1 ) * amp[0];
  jamp[92] += cxtype( 0, 1 ) * amp[0];
  jamp[93] -= cxtype( 0, 1 ) * amp[0];
  FFV1_0( w[3], w[39], w[21], COUPs[1], &amp[0] );
  jamp[73] += cxtype( 0, 1 ) * amp[0];
  jamp[76] -= cxtype( 0, 1 ) * amp[0];
  jamp[82] -= cxtype( 0, 1 ) * amp[0];
  jamp[84] -= cxtype( 0, 1 ) * amp[0];
  jamp[85] += cxtype( 0, 1 ) * amp[0];
  jamp[87] += cxtype( 0, 1 ) * amp[0];
  jamp[89] -= cxtype( 0, 1 ) * amp[0];
  jamp[92] += cxtype( 0, 1 ) * amp[0];

  // *** DIAGRAM 984 OF 1240 ***

  // Wavefunction(s) for diagram number 984
  // (none)

  // Amplitude(s) for diagram number 984
  FFV1_0( w[46], w[39], w[71], COUPs[1], &amp[0] );
#ifdef MGONGPU_SUPPORTS_MULTICHANNEL
  if( channelId == 984 ) allNumerators[0] += cxabs2( amp[0] );
  if( channelId != 0 ) allDenominators[0] += cxabs2( amp[0] );
#endif
  jamp[73] += amp[0];
  jamp[76] -= amp[0];
  jamp[82] -= amp[0];
  jamp[92] += amp[0];

  // *** DIAGRAM 985 OF 1240 ***

  // Wavefunction(s) for diagram number 985
  // (none)

  // Amplitude(s) for diagram number 985
  FFV1_0( w[46], w[102], w[72], COUPs[1], &amp[0] );
#ifdef MGONGPU_SUPPORTS_MULTICHANNEL
  if( channelId == 985 ) allNumerators[0] += cxabs2( amp[0] );
  if( channelId != 0 ) allDenominators[0] += cxabs2( amp[0] );
#endif
  jamp[73] += cxtype( 0, 1 ) * amp[0];
  jamp[76] -= cxtype( 0, 1 ) * amp[0];

  // *** DIAGRAM 986 OF 1240 ***

  // Wavefunction(s) for diagram number 986
  // (none)

  // Amplitude(s) for diagram number 986
  FFV1_0( w[99], w[39], w[72], COUPs[1], &amp[0] );
#ifdef MGONGPU_SUPPORTS_MULTICHANNEL
  if( channelId == 986 ) allNumerators[0] += cxabs2( amp[0] );
  if( channelId != 0 ) allDenominators[0] += cxabs2( amp[0] );
#endif
  jamp[82] += cxtype( 0, 1 ) * amp[0];
  jamp[92] -= cxtype( 0, 1 ) * amp[0];

  // *** DIAGRAM 987 OF 1240 ***

  // Wavefunction(s) for diagram number 987
  // (none)

  // Amplitude(s) for diagram number 987
  VVV1_0( w[71], w[54], w[5], COUPs[0], &amp[0] );
#ifdef MGONGPU_SUPPORTS_MULTICHANNEL
  if( channelId == 987 ) allNumerators[0] += cxabs2( amp[0] );
  if( channelId != 0 ) allDenominators[0] += cxabs2( amp[0] );
#endif
  jamp[5] += cxtype( 0, 1 ) * amp[0];
  jamp[19] -= cxtype( 0, 1 ) * amp[0];
  jamp[43] -= cxtype( 0, 1 ) * amp[0];
  jamp[73] -= cxtype( 0, 1 ) * amp[0];
  jamp[76] += cxtype( 0, 1 ) * amp[0];
  jamp[82] += cxtype( 0, 1 ) * amp[0];
  jamp[92] -= cxtype( 0, 1 ) * amp[0];
  jamp[103] += cxtype( 0, 1 ) * amp[0];

  // *** DIAGRAM 988 OF 1240 ***

  // Wavefunction(s) for diagram number 988
  // (none)

  // Amplitude(s) for diagram number 988
  FFV1_0( w[7], w[2], w[71], COUPs[1], &amp[0] );
#ifdef MGONGPU_SUPPORTS_MULTICHANNEL
  if( channelId == 988 ) allNumerators[0] += cxabs2( amp[0] );
  if( channelId != 0 ) allDenominators[0] += cxabs2( amp[0] );
#endif
  jamp[5] += amp[0];
  jamp[19] -= amp[0];
  jamp[43] -= amp[0];
  jamp[103] += amp[0];

  // *** DIAGRAM 989 OF 1240 ***

  // Wavefunction(s) for diagram number 989
  // (none)

  // Amplitude(s) for diagram number 989
  FFV1_0( w[99], w[97], w[5], COUPs[1], &amp[0] );
#ifdef MGONGPU_SUPPORTS_MULTICHANNEL
  if( channelId == 989 ) allNumerators[0] += cxabs2( amp[0] );
  if( channelId != 0 ) allDenominators[0] += cxabs2( amp[0] );
#endif
  jamp[46] += cxtype( 0, 1 ) * amp[0];
  jamp[106] -= cxtype( 0, 1 ) * amp[0];

  // *** DIAGRAM 990 OF 1240 ***

  // Wavefunction(s) for diagram number 990
  // (none)

  // Amplitude(s) for diagram number 990
  FFV1_0( w[99], w[2], w[75], COUPs[1], &amp[0] );
#ifdef MGONGPU_SUPPORTS_MULTICHANNEL
  if( channelId == 990 ) allNumerators[0] += cxabs2( amp[0] );
  if( channelId != 0 ) allDenominators[0] += cxabs2( amp[0] );
#endif
  jamp[46] += amp[0];
  jamp[82] -= amp[0];
  jamp[92] += amp[0];
  jamp[106] -= amp[0];

  // *** DIAGRAM 991 OF 1240 ***

  // Wavefunction(s) for diagram number 991
  // (none)

  // Amplitude(s) for diagram number 991
  FFV1_0( w[7], w[97], w[0], COUPs[1], &amp[0] );
#ifdef MGONGPU_SUPPORTS_MULTICHANNEL
  if( channelId == 991 ) allNumerators[0] += cxabs2( amp[0] );
  if( channelId != 0 ) allDenominators[0] += cxabs2( amp[0] );
#endif
  jamp[43] += cxtype( 0, 1 ) * amp[0];
  jamp[103] -= cxtype( 0, 1 ) * amp[0];

  // *** DIAGRAM 992 OF 1240 ***

  // Wavefunction(s) for diagram number 992
  // (none)

  // Amplitude(s) for diagram number 992
  VVV1_0( w[0], w[75], w[54], COUPs[0], &amp[0] );
#ifdef MGONGPU_SUPPORTS_MULTICHANNEL
  if( channelId == 992 ) allNumerators[0] += cxabs2( amp[0] );
  if( channelId != 0 ) allDenominators[0] += cxabs2( amp[0] );
#endif
  jamp[5] -= cxtype( 0, 1 ) * amp[0];
  jamp[13] += cxtype( 0, 1 ) * amp[0];
  jamp[16] -= cxtype( 0, 1 ) * amp[0];
  jamp[19] += cxtype( 0, 1 ) * amp[0];
  jamp[46] += cxtype( 0, 1 ) * amp[0];
  jamp[82] -= cxtype( 0, 1 ) * amp[0];
  jamp[92] += cxtype( 0, 1 ) * amp[0];
  jamp[106] -= cxtype( 0, 1 ) * amp[0];

  // *** DIAGRAM 993 OF 1240 ***

  // Wavefunction(s) for diagram number 993
  // (none)

  // Amplitude(s) for diagram number 993
  FFV1_0( w[46], w[2], w[90], COUPs[1], &amp[0] );
  jamp[5] -= cxtype( 0, 1 ) * amp[0];
  jamp[13] += cxtype( 0, 1 ) * amp[0];
  jamp[16] -= cxtype( 0, 1 ) * amp[0];
  jamp[19] += cxtype( 0, 1 ) * amp[0];
  jamp[46] += cxtype( 0, 1 ) * amp[0];
  jamp[82] -= cxtype( 0, 1 ) * amp[0];
  jamp[92] += cxtype( 0, 1 ) * amp[0];
  jamp[106] -= cxtype( 0, 1 ) * amp[0];
  FFV1_0( w[46], w[2], w[93], COUPs[1], &amp[0] );
  jamp[13] += cxtype( 0, 1 ) * amp[0];
  jamp[16] -= cxtype( 0, 1 ) * amp[0];
  jamp[43] -= cxtype( 0, 1 ) * amp[0];
  jamp[46] += cxtype( 0, 1 ) * amp[0];
  jamp[73] -= cxtype( 0, 1 ) * amp[0];
  jamp[76] += cxtype( 0, 1 ) * amp[0];
  jamp[103] += cxtype( 0, 1 ) * amp[0];
  jamp[106] -= cxtype( 0, 1 ) * amp[0];
  FFV1_0( w[46], w[2], w[69], COUPs[1], &amp[0] );
  jamp[5] += cxtype( 0, 1 ) * amp[0];
  jamp[19] -= cxtype( 0, 1 ) * amp[0];
  jamp[43] -= cxtype( 0, 1 ) * amp[0];
  jamp[73] -= cxtype( 0, 1 ) * amp[0];
  jamp[76] += cxtype( 0, 1 ) * amp[0];
  jamp[82] += cxtype( 0, 1 ) * amp[0];
  jamp[92] -= cxtype( 0, 1 ) * amp[0];
  jamp[103] += cxtype( 0, 1 ) * amp[0];

  // *** DIAGRAM 994 OF 1240 ***

  // Wavefunction(s) for diagram number 994
  // (none)

  // Amplitude(s) for diagram number 994
  VVV1_0( w[71], w[23], w[4], COUPs[0], &amp[0] );
#ifdef MGONGPU_SUPPORTS_MULTICHANNEL
  if( channelId == 994 ) allNumerators[0] += cxabs2( amp[0] );
  if( channelId != 0 ) allDenominators[0] += cxabs2( amp[0] );
#endif
  jamp[4] += cxtype( 0, 1 ) * amp[0];
  jamp[18] -= cxtype( 0, 1 ) * amp[0];
  jamp[42] -= cxtype( 0, 1 ) * amp[0];
  jamp[49] -= cxtype( 0, 1 ) * amp[0];
  jamp[52] += cxtype( 0, 1 ) * amp[0];
  jamp[58] += cxtype( 0, 1 ) * amp[0];
  jamp[68] -= cxtype( 0, 1 ) * amp[0];
  jamp[102] += cxtype( 0, 1 ) * amp[0];

  // *** DIAGRAM 995 OF 1240 ***

  // Wavefunction(s) for diagram number 995
  // (none)

  // Amplitude(s) for diagram number 995
  FFV1_0( w[25], w[2], w[71], COUPs[1], &amp[0] );
#ifdef MGONGPU_SUPPORTS_MULTICHANNEL
  if( channelId == 995 ) allNumerators[0] += cxabs2( amp[0] );
  if( channelId != 0 ) allDenominators[0] += cxabs2( amp[0] );
#endif
  jamp[4] += amp[0];
  jamp[18] -= amp[0];
  jamp[42] -= amp[0];
  jamp[102] += amp[0];

  // *** DIAGRAM 996 OF 1240 ***

  // Wavefunction(s) for diagram number 996
  // (none)

  // Amplitude(s) for diagram number 996
  FFV1_0( w[104], w[97], w[4], COUPs[1], &amp[0] );
#ifdef MGONGPU_SUPPORTS_MULTICHANNEL
  if( channelId == 996 ) allNumerators[0] += cxabs2( amp[0] );
  if( channelId != 0 ) allDenominators[0] += cxabs2( amp[0] );
#endif
  jamp[44] += cxtype( 0, 1 ) * amp[0];
  jamp[104] -= cxtype( 0, 1 ) * amp[0];

  // *** DIAGRAM 997 OF 1240 ***

  // Wavefunction(s) for diagram number 997
  // (none)

  // Amplitude(s) for diagram number 997
  FFV1_0( w[104], w[2], w[74], COUPs[1], &amp[0] );
#ifdef MGONGPU_SUPPORTS_MULTICHANNEL
  if( channelId == 997 ) allNumerators[0] += cxabs2( amp[0] );
  if( channelId != 0 ) allDenominators[0] += cxabs2( amp[0] );
#endif
  jamp[44] += amp[0];
  jamp[58] -= amp[0];
  jamp[68] += amp[0];
  jamp[104] -= amp[0];

  // *** DIAGRAM 998 OF 1240 ***

  // Wavefunction(s) for diagram number 998
  // (none)

  // Amplitude(s) for diagram number 998
  FFV1_0( w[25], w[97], w[0], COUPs[1], &amp[0] );
#ifdef MGONGPU_SUPPORTS_MULTICHANNEL
  if( channelId == 998 ) allNumerators[0] += cxabs2( amp[0] );
  if( channelId != 0 ) allDenominators[0] += cxabs2( amp[0] );
#endif
  jamp[42] += cxtype( 0, 1 ) * amp[0];
  jamp[102] -= cxtype( 0, 1 ) * amp[0];

  // *** DIAGRAM 999 OF 1240 ***

  // Wavefunction(s) for diagram number 999
  // (none)

  // Amplitude(s) for diagram number 999
  VVV1_0( w[0], w[74], w[23], COUPs[0], &amp[0] );
#ifdef MGONGPU_SUPPORTS_MULTICHANNEL
  if( channelId == 999 ) allNumerators[0] += cxabs2( amp[0] );
  if( channelId != 0 ) allDenominators[0] += cxabs2( amp[0] );
#endif
  jamp[4] -= cxtype( 0, 1 ) * amp[0];
  jamp[7] += cxtype( 0, 1 ) * amp[0];
  jamp[10] -= cxtype( 0, 1 ) * amp[0];
  jamp[18] += cxtype( 0, 1 ) * amp[0];
  jamp[44] += cxtype( 0, 1 ) * amp[0];
  jamp[58] -= cxtype( 0, 1 ) * amp[0];
  jamp[68] += cxtype( 0, 1 ) * amp[0];
  jamp[104] -= cxtype( 0, 1 ) * amp[0];

  // *** DIAGRAM 1000 OF 1240 ***

  // Wavefunction(s) for diagram number 1000
  // (none)

  // Amplitude(s) for diagram number 1000
  FFV1_0( w[38], w[2], w[94], COUPs[1], &amp[0] );
  jamp[4] -= cxtype( 0, 1 ) * amp[0];
  jamp[7] += cxtype( 0, 1 ) * amp[0];
  jamp[10] -= cxtype( 0, 1 ) * amp[0];
  jamp[18] += cxtype( 0, 1 ) * amp[0];
  jamp[44] += cxtype( 0, 1 ) * amp[0];
  jamp[58] -= cxtype( 0, 1 ) * amp[0];
  jamp[68] += cxtype( 0, 1 ) * amp[0];
  jamp[104] -= cxtype( 0, 1 ) * amp[0];
  FFV1_0( w[38], w[2], w[65], COUPs[1], &amp[0] );
  jamp[7] += cxtype( 0, 1 ) * amp[0];
  jamp[10] -= cxtype( 0, 1 ) * amp[0];
  jamp[42] -= cxtype( 0, 1 ) * amp[0];
  jamp[44] += cxtype( 0, 1 ) * amp[0];
  jamp[49] -= cxtype( 0, 1 ) * amp[0];
  jamp[52] += cxtype( 0, 1 ) * amp[0];
  jamp[102] += cxtype( 0, 1 ) * amp[0];
  jamp[104] -= cxtype( 0, 1 ) * amp[0];
  FFV1_0( w[38], w[2], w[21], COUPs[1], &amp[0] );
  jamp[4] += cxtype( 0, 1 ) * amp[0];
  jamp[18] -= cxtype( 0, 1 ) * amp[0];
  jamp[42] -= cxtype( 0, 1 ) * amp[0];
  jamp[49] -= cxtype( 0, 1 ) * amp[0];
  jamp[52] += cxtype( 0, 1 ) * amp[0];
  jamp[58] += cxtype( 0, 1 ) * amp[0];
  jamp[68] -= cxtype( 0, 1 ) * amp[0];
  jamp[102] += cxtype( 0, 1 ) * amp[0];

  // *** DIAGRAM 1001 OF 1240 ***

  // Wavefunction(s) for diagram number 1001
  // (none)

  // Amplitude(s) for diagram number 1001
  FFV1_0( w[3], w[17], w[71], COUPs[1], &amp[0] );
#ifdef MGONGPU_SUPPORTS_MULTICHANNEL
  if( channelId == 1001 ) allNumerators[0] += cxabs2( amp[0] );
  if( channelId != 0 ) allDenominators[0] += cxabs2( amp[0] );
#endif
  jamp[60] -= cxtype( 0, 1 ) * amp[0];
  jamp[61] += cxtype( 0, 1 ) * amp[0];
  jamp[63] += cxtype( 0, 1 ) * amp[0];
  jamp[65] -= cxtype( 0, 1 ) * amp[0];
  jamp[84] += cxtype( 0, 1 ) * amp[0];
  jamp[85] -= cxtype( 0, 1 ) * amp[0];
  jamp[87] -= cxtype( 0, 1 ) * amp[0];
  jamp[89] += cxtype( 0, 1 ) * amp[0];

  // *** DIAGRAM 1002 OF 1240 ***

  // Wavefunction(s) for diagram number 1002
  // (none)

  // Amplitude(s) for diagram number 1002
  FFV1_0( w[26], w[2], w[71], COUPs[1], &amp[0] );
#ifdef MGONGPU_SUPPORTS_MULTICHANNEL
  if( channelId == 1002 ) allNumerators[0] += cxabs2( amp[0] );
  if( channelId != 0 ) allDenominators[0] += cxabs2( amp[0] );
#endif
  jamp[4] -= cxtype( 0, 1 ) * amp[0];
  jamp[5] += cxtype( 0, 1 ) * amp[0];
  jamp[18] += cxtype( 0, 1 ) * amp[0];
  jamp[19] -= cxtype( 0, 1 ) * amp[0];
  jamp[42] += cxtype( 0, 1 ) * amp[0];
  jamp[43] -= cxtype( 0, 1 ) * amp[0];
  jamp[102] -= cxtype( 0, 1 ) * amp[0];
  jamp[103] += cxtype( 0, 1 ) * amp[0];

  // *** DIAGRAM 1003 OF 1240 ***

  // Wavefunction(s) for diagram number 1003
  // (none)

  // Amplitude(s) for diagram number 1003
  FFV1_0( w[3], w[97], w[98], COUPs[1], &amp[0] );
#ifdef MGONGPU_SUPPORTS_MULTICHANNEL
  if( channelId == 1003 ) allNumerators[0] += cxabs2( amp[0] );
  if( channelId != 0 ) allDenominators[0] += cxabs2( amp[0] );
#endif
  jamp[42] -= cxtype( 0, 1 ) * amp[0];
  jamp[43] += cxtype( 0, 1 ) * amp[0];
  jamp[45] += cxtype( 0, 1 ) * amp[0];
  jamp[47] -= cxtype( 0, 1 ) * amp[0];
  jamp[102] += cxtype( 0, 1 ) * amp[0];
  jamp[103] -= cxtype( 0, 1 ) * amp[0];
  jamp[105] -= cxtype( 0, 1 ) * amp[0];
  jamp[107] += cxtype( 0, 1 ) * amp[0];

  // *** DIAGRAM 1004 OF 1240 ***

  // Wavefunction(s) for diagram number 1004
  // (none)

  // Amplitude(s) for diagram number 1004
  FFV1_0( w[76], w[2], w[98], COUPs[1], &amp[0] );
#ifdef MGONGPU_SUPPORTS_MULTICHANNEL
  if( channelId == 1004 ) allNumerators[0] += cxabs2( amp[0] );
  if( channelId != 0 ) allDenominators[0] += cxabs2( amp[0] );
#endif
  jamp[8] -= cxtype( 0, 1 ) * amp[0];
  jamp[9] += cxtype( 0, 1 ) * amp[0];
  jamp[14] += cxtype( 0, 1 ) * amp[0];
  jamp[15] -= cxtype( 0, 1 ) * amp[0];
  jamp[60] += cxtype( 0, 1 ) * amp[0];
  jamp[61] -= cxtype( 0, 1 ) * amp[0];
  jamp[84] -= cxtype( 0, 1 ) * amp[0];
  jamp[85] += cxtype( 0, 1 ) * amp[0];

  // *** DIAGRAM 1005 OF 1240 ***

  // Wavefunction(s) for diagram number 1005
  // (none)

  // Amplitude(s) for diagram number 1005
  FFV1_0( w[26], w[97], w[0], COUPs[1], &amp[0] );
#ifdef MGONGPU_SUPPORTS_MULTICHANNEL
  if( channelId == 1005 ) allNumerators[0] += cxabs2( amp[0] );
  if( channelId != 0 ) allDenominators[0] += cxabs2( amp[0] );
#endif
  jamp[42] += amp[0];
  jamp[43] -= amp[0];
  jamp[102] -= amp[0];
  jamp[103] += amp[0];

  // *** DIAGRAM 1006 OF 1240 ***

  // Wavefunction(s) for diagram number 1006
  // (none)

  // Amplitude(s) for diagram number 1006
  FFV1_0( w[76], w[17], w[0], COUPs[1], &amp[0] );
#ifdef MGONGPU_SUPPORTS_MULTICHANNEL
  if( channelId == 1006 ) allNumerators[0] += cxabs2( amp[0] );
  if( channelId != 0 ) allDenominators[0] += cxabs2( amp[0] );
#endif
  jamp[60] += amp[0];
  jamp[61] -= amp[0];
  jamp[84] -= amp[0];
  jamp[85] += amp[0];

  // *** DIAGRAM 1007 OF 1240 ***

  // Wavefunction(s) for diagram number 1007
  // (none)

  // Amplitude(s) for diagram number 1007
  VVV1_0( w[56], w[59], w[6], COUPs[0], &amp[0] );
#ifdef MGONGPU_SUPPORTS_MULTICHANNEL
  if( channelId == 1007 ) allNumerators[0] += cxabs2( amp[0] );
  if( channelId != 0 ) allDenominators[0] += cxabs2( amp[0] );
#endif
  jamp[0] += amp[0];
  jamp[2] -= amp[0];
  jamp[8] -= amp[0];
  jamp[14] += amp[0];
  jamp[18] -= amp[0];
  jamp[19] += amp[0];
  jamp[21] += amp[0];
  jamp[23] -= amp[0];
  jamp[33] -= amp[0];
  jamp[39] += amp[0];
  jamp[63] += amp[0];
  jamp[87] -= amp[0];
  jamp[105] += amp[0];
  jamp[107] -= amp[0];
  jamp[113] -= amp[0];
  jamp[119] += amp[0];

  // *** DIAGRAM 1008 OF 1240 ***

  // Wavefunction(s) for diagram number 1008
  // (none)

  // Amplitude(s) for diagram number 1008
  VVV1_0( w[56], w[1], w[42], COUPs[0], &amp[0] );
#ifdef MGONGPU_SUPPORTS_MULTICHANNEL
  if( channelId == 1008 ) allNumerators[0] += cxabs2( amp[0] );
  if( channelId != 0 ) allDenominators[0] += cxabs2( amp[0] );
#endif
  jamp[0] += amp[0];
  jamp[2] -= amp[0];
  jamp[4] -= amp[0];
  jamp[5] += amp[0];
  jamp[9] -= amp[0];
  jamp[15] += amp[0];
  jamp[21] += amp[0];
  jamp[23] -= amp[0];
  jamp[33] -= amp[0];
  jamp[39] += amp[0];
  jamp[45] += amp[0];
  jamp[47] -= amp[0];
  jamp[65] += amp[0];
  jamp[89] -= amp[0];
  jamp[113] -= amp[0];
  jamp[119] += amp[0];

  // *** DIAGRAM 1009 OF 1240 ***

  // Wavefunction(s) for diagram number 1009
  // (none)

  // Amplitude(s) for diagram number 1009
  VVVV1_0( w[1], w[24], w[6], w[56], COUPs[2], &amp[0] );
  jamp[0] += amp[0];
  jamp[2] -= amp[0];
  jamp[8] -= amp[0];
  jamp[14] += amp[0];
  jamp[18] -= amp[0];
  jamp[19] += amp[0];
  jamp[21] += amp[0];
  jamp[23] -= amp[0];
  jamp[33] -= amp[0];
  jamp[39] += amp[0];
  jamp[63] += amp[0];
  jamp[87] -= amp[0];
  jamp[105] += amp[0];
  jamp[107] -= amp[0];
  jamp[113] -= amp[0];
  jamp[119] += amp[0];
  VVVV3_0( w[1], w[24], w[6], w[56], COUPs[2], &amp[0] );
  jamp[4] += amp[0];
  jamp[5] -= amp[0];
  jamp[8] -= amp[0];
  jamp[9] += amp[0];
  jamp[14] += amp[0];
  jamp[15] -= amp[0];
  jamp[18] -= amp[0];
  jamp[19] += amp[0];
  jamp[45] -= amp[0];
  jamp[47] += amp[0];
  jamp[63] += amp[0];
  jamp[65] -= amp[0];
  jamp[87] -= amp[0];
  jamp[89] += amp[0];
  jamp[105] += amp[0];
  jamp[107] -= amp[0];
  VVVV4_0( w[1], w[24], w[6], w[56], COUPs[2], &amp[0] );
  jamp[0] -= amp[0];
  jamp[2] += amp[0];
  jamp[4] += amp[0];
  jamp[5] -= amp[0];
  jamp[9] += amp[0];
  jamp[15] -= amp[0];
  jamp[21] -= amp[0];
  jamp[23] += amp[0];
  jamp[33] += amp[0];
  jamp[39] -= amp[0];
  jamp[45] -= amp[0];
  jamp[47] += amp[0];
  jamp[65] -= amp[0];
  jamp[89] += amp[0];
  jamp[113] += amp[0];
  jamp[119] -= amp[0];

  // *** DIAGRAM 1010 OF 1240 ***

  // Wavefunction(s) for diagram number 1010
  // (none)

  // Amplitude(s) for diagram number 1010
  VVV1_0( w[98], w[108], w[6], COUPs[0], &amp[0] );
#ifdef MGONGPU_SUPPORTS_MULTICHANNEL
  if( channelId == 1010 ) allNumerators[0] += cxabs2( amp[0] );
  if( channelId != 0 ) allDenominators[0] += cxabs2( amp[0] );
#endif
  jamp[9] += amp[0];
  jamp[15] -= amp[0];
  jamp[24] -= amp[0];
  jamp[26] += amp[0];
  jamp[32] += amp[0];
  jamp[38] -= amp[0];
  jamp[42] += amp[0];
  jamp[43] -= amp[0];
  jamp[45] -= amp[0];
  jamp[47] += amp[0];
  jamp[61] -= amp[0];
  jamp[85] += amp[0];
  jamp[99] -= amp[0];
  jamp[101] += amp[0];
  jamp[112] += amp[0];
  jamp[118] -= amp[0];

  // *** DIAGRAM 1011 OF 1240 ***

  // Wavefunction(s) for diagram number 1011
  // (none)

  // Amplitude(s) for diagram number 1011
  VVV1_0( w[98], w[1], w[11], COUPs[0], &amp[0] );
#ifdef MGONGPU_SUPPORTS_MULTICHANNEL
  if( channelId == 1011 ) allNumerators[0] += cxabs2( amp[0] );
  if( channelId != 0 ) allDenominators[0] += cxabs2( amp[0] );
#endif
  jamp[8] += amp[0];
  jamp[14] -= amp[0];
  jamp[24] -= amp[0];
  jamp[26] += amp[0];
  jamp[32] += amp[0];
  jamp[38] -= amp[0];
  jamp[60] -= amp[0];
  jamp[84] += amp[0];
  jamp[99] -= amp[0];
  jamp[101] += amp[0];
  jamp[102] += amp[0];
  jamp[103] -= amp[0];
  jamp[105] -= amp[0];
  jamp[107] += amp[0];
  jamp[112] += amp[0];
  jamp[118] -= amp[0];

  // *** DIAGRAM 1012 OF 1240 ***

  // Wavefunction(s) for diagram number 1012
  // (none)

  // Amplitude(s) for diagram number 1012
  VVVV1_0( w[1], w[8], w[6], w[98], COUPs[2], &amp[0] );
  jamp[9] += amp[0];
  jamp[15] -= amp[0];
  jamp[24] -= amp[0];
  jamp[26] += amp[0];
  jamp[32] += amp[0];
  jamp[38] -= amp[0];
  jamp[42] += amp[0];
  jamp[43] -= amp[0];
  jamp[45] -= amp[0];
  jamp[47] += amp[0];
  jamp[61] -= amp[0];
  jamp[85] += amp[0];
  jamp[99] -= amp[0];
  jamp[101] += amp[0];
  jamp[112] += amp[0];
  jamp[118] -= amp[0];
  VVVV3_0( w[1], w[8], w[6], w[98], COUPs[2], &amp[0] );
  jamp[8] -= amp[0];
  jamp[9] += amp[0];
  jamp[14] += amp[0];
  jamp[15] -= amp[0];
  jamp[42] += amp[0];
  jamp[43] -= amp[0];
  jamp[45] -= amp[0];
  jamp[47] += amp[0];
  jamp[60] += amp[0];
  jamp[61] -= amp[0];
  jamp[84] -= amp[0];
  jamp[85] += amp[0];
  jamp[102] -= amp[0];
  jamp[103] += amp[0];
  jamp[105] += amp[0];
  jamp[107] -= amp[0];
  VVVV4_0( w[1], w[8], w[6], w[98], COUPs[2], &amp[0] );
  jamp[8] -= amp[0];
  jamp[14] += amp[0];
  jamp[24] += amp[0];
  jamp[26] -= amp[0];
  jamp[32] -= amp[0];
  jamp[38] += amp[0];
  jamp[60] += amp[0];
  jamp[84] -= amp[0];
  jamp[99] += amp[0];
  jamp[101] -= amp[0];
  jamp[102] -= amp[0];
  jamp[103] += amp[0];
  jamp[105] += amp[0];
  jamp[107] -= amp[0];
  jamp[112] -= amp[0];
  jamp[118] += amp[0];

  // *** DIAGRAM 1013 OF 1240 ***

  // Wavefunction(s) for diagram number 1013
  // (none)

  // Amplitude(s) for diagram number 1013
  VVV1_0( w[0], w[108], w[42], COUPs[0], &amp[0] );
#ifdef MGONGPU_SUPPORTS_MULTICHANNEL
  if( channelId == 1013 ) allNumerators[0] += cxabs2( amp[0] );
  if( channelId != 0 ) allDenominators[0] += cxabs2( amp[0] );
#endif
  jamp[9] += amp[0];
  jamp[15] -= amp[0];
  jamp[21] -= amp[0];
  jamp[23] += amp[0];
  jamp[24] -= amp[0];
  jamp[26] += amp[0];
  jamp[28] += amp[0];
  jamp[29] -= amp[0];
  jamp[33] += amp[0];
  jamp[39] -= amp[0];
  jamp[45] -= amp[0];
  jamp[47] += amp[0];
  jamp[64] -= amp[0];
  jamp[88] += amp[0];
  jamp[112] += amp[0];
  jamp[118] -= amp[0];

  // *** DIAGRAM 1014 OF 1240 ***

  // Wavefunction(s) for diagram number 1014
  // (none)

  // Amplitude(s) for diagram number 1014
  VVV1_0( w[0], w[59], w[11], COUPs[0], &amp[0] );
#ifdef MGONGPU_SUPPORTS_MULTICHANNEL
  if( channelId == 1014 ) allNumerators[0] += cxabs2( amp[0] );
  if( channelId != 0 ) allDenominators[0] += cxabs2( amp[0] );
#endif
  jamp[0] += amp[0];
  jamp[2] -= amp[0];
  jamp[8] -= amp[0];
  jamp[14] += amp[0];
  jamp[32] -= amp[0];
  jamp[38] += amp[0];
  jamp[62] += amp[0];
  jamp[86] -= amp[0];
  jamp[96] -= amp[0];
  jamp[97] += amp[0];
  jamp[99] += amp[0];
  jamp[101] -= amp[0];
  jamp[105] += amp[0];
  jamp[107] -= amp[0];
  jamp[113] -= amp[0];
  jamp[119] += amp[0];

  // *** DIAGRAM 1015 OF 1240 ***

  // Wavefunction(s) for diagram number 1015
  VVVV1P0_1( w[0], w[1], w[8], COUPs[2], 0., 0., w[11] );
  VVVV3P0_1( w[0], w[1], w[8], COUPs[2], 0., 0., w[42] );
  VVVV4P0_1( w[0], w[1], w[8], COUPs[2], 0., 0., w[76] );

  // Amplitude(s) for diagram number 1015
  VVV1_0( w[24], w[6], w[11], COUPs[0], &amp[0] );
  jamp[9] += amp[0];
  jamp[15] -= amp[0];
  jamp[21] -= amp[0];
  jamp[23] += amp[0];
  jamp[24] -= amp[0];
  jamp[26] += amp[0];
  jamp[28] += amp[0];
  jamp[29] -= amp[0];
  jamp[33] += amp[0];
  jamp[39] -= amp[0];
  jamp[45] -= amp[0];
  jamp[47] += amp[0];
  jamp[64] -= amp[0];
  jamp[88] += amp[0];
  jamp[112] += amp[0];
  jamp[118] -= amp[0];
  VVV1_0( w[24], w[6], w[42], COUPs[0], &amp[0] );
  jamp[0] -= amp[0];
  jamp[2] += amp[0];
  jamp[4] += amp[0];
  jamp[5] -= amp[0];
  jamp[9] += amp[0];
  jamp[15] -= amp[0];
  jamp[21] -= amp[0];
  jamp[23] += amp[0];
  jamp[33] += amp[0];
  jamp[39] -= amp[0];
  jamp[45] -= amp[0];
  jamp[47] += amp[0];
  jamp[65] -= amp[0];
  jamp[89] += amp[0];
  jamp[113] += amp[0];
  jamp[119] -= amp[0];
  VVV1_0( w[24], w[6], w[76], COUPs[0], &amp[0] );
  jamp[0] -= amp[0];
  jamp[2] += amp[0];
  jamp[4] += amp[0];
  jamp[5] -= amp[0];
  jamp[24] += amp[0];
  jamp[26] -= amp[0];
  jamp[28] -= amp[0];
  jamp[29] += amp[0];
  jamp[64] += amp[0];
  jamp[65] -= amp[0];
  jamp[88] -= amp[0];
  jamp[89] += amp[0];
  jamp[112] -= amp[0];
  jamp[113] += amp[0];
  jamp[118] += amp[0];
  jamp[119] -= amp[0];

  // *** DIAGRAM 1016 OF 1240 ***

  // Wavefunction(s) for diagram number 1016
  VVVV1P0_1( w[0], w[1], w[24], COUPs[2], 0., 0., w[97] );
  VVVV3P0_1( w[0], w[1], w[24], COUPs[2], 0., 0., w[71] );
  VVVV4P0_1( w[0], w[1], w[24], COUPs[2], 0., 0., w[21] );

  // Amplitude(s) for diagram number 1016
  VVV1_0( w[8], w[6], w[97], COUPs[0], &amp[0] );
  jamp[0] += amp[0];
  jamp[2] -= amp[0];
  jamp[8] -= amp[0];
  jamp[14] += amp[0];
  jamp[32] -= amp[0];
  jamp[38] += amp[0];
  jamp[62] += amp[0];
  jamp[86] -= amp[0];
  jamp[96] -= amp[0];
  jamp[97] += amp[0];
  jamp[99] += amp[0];
  jamp[101] -= amp[0];
  jamp[105] += amp[0];
  jamp[107] -= amp[0];
  jamp[113] -= amp[0];
  jamp[119] += amp[0];
  VVV1_0( w[8], w[6], w[71], COUPs[0], &amp[0] );
  jamp[8] -= amp[0];
  jamp[14] += amp[0];
  jamp[24] += amp[0];
  jamp[26] -= amp[0];
  jamp[32] -= amp[0];
  jamp[38] += amp[0];
  jamp[60] += amp[0];
  jamp[84] -= amp[0];
  jamp[99] += amp[0];
  jamp[101] -= amp[0];
  jamp[102] -= amp[0];
  jamp[103] += amp[0];
  jamp[105] += amp[0];
  jamp[107] -= amp[0];
  jamp[112] -= amp[0];
  jamp[118] += amp[0];
  VVV1_0( w[8], w[6], w[21], COUPs[0], &amp[0] );
  jamp[0] -= amp[0];
  jamp[2] += amp[0];
  jamp[24] += amp[0];
  jamp[26] -= amp[0];
  jamp[60] += amp[0];
  jamp[62] -= amp[0];
  jamp[84] -= amp[0];
  jamp[86] += amp[0];
  jamp[96] += amp[0];
  jamp[97] -= amp[0];
  jamp[102] -= amp[0];
  jamp[103] += amp[0];
  jamp[112] -= amp[0];
  jamp[113] += amp[0];
  jamp[118] += amp[0];
  jamp[119] -= amp[0];

  // *** DIAGRAM 1017 OF 1240 ***

  // Wavefunction(s) for diagram number 1017
  // (none)

  // Amplitude(s) for diagram number 1017
  VVV1_0( w[1], w[24], w[118], COUPs[0], &amp[0] );
  jamp[0] -= amp[0];
  jamp[2] += amp[0];
  jamp[8] += amp[0];
  jamp[14] -= amp[0];
  jamp[32] += amp[0];
  jamp[38] -= amp[0];
  jamp[62] -= amp[0];
  jamp[86] += amp[0];
  jamp[96] += amp[0];
  jamp[97] -= amp[0];
  jamp[99] -= amp[0];
  jamp[101] += amp[0];
  jamp[105] -= amp[0];
  jamp[107] += amp[0];
  jamp[113] += amp[0];
  jamp[119] -= amp[0];
  VVV1_0( w[1], w[24], w[119], COUPs[0], &amp[0] );
  jamp[18] -= amp[0];
  jamp[19] += amp[0];
  jamp[21] += amp[0];
  jamp[23] -= amp[0];
  jamp[32] += amp[0];
  jamp[33] -= amp[0];
  jamp[38] -= amp[0];
  jamp[39] += amp[0];
  jamp[62] -= amp[0];
  jamp[63] += amp[0];
  jamp[86] += amp[0];
  jamp[87] -= amp[0];
  jamp[96] += amp[0];
  jamp[97] -= amp[0];
  jamp[99] -= amp[0];
  jamp[101] += amp[0];
  VVV1_0( w[1], w[24], w[120], COUPs[0], &amp[0] );
  jamp[0] += amp[0];
  jamp[2] -= amp[0];
  jamp[8] -= amp[0];
  jamp[14] += amp[0];
  jamp[18] -= amp[0];
  jamp[19] += amp[0];
  jamp[21] += amp[0];
  jamp[23] -= amp[0];
  jamp[33] -= amp[0];
  jamp[39] += amp[0];
  jamp[63] += amp[0];
  jamp[87] -= amp[0];
  jamp[105] += amp[0];
  jamp[107] -= amp[0];
  jamp[113] -= amp[0];
  jamp[119] += amp[0];

  // *** DIAGRAM 1018 OF 1240 ***

  // Wavefunction(s) for diagram number 1018
  // (none)

  // Amplitude(s) for diagram number 1018
  VVV1_0( w[1], w[8], w[85], COUPs[0], &amp[0] );
  jamp[9] -= amp[0];
  jamp[15] += amp[0];
  jamp[21] += amp[0];
  jamp[23] -= amp[0];
  jamp[24] += amp[0];
  jamp[26] -= amp[0];
  jamp[28] -= amp[0];
  jamp[29] += amp[0];
  jamp[33] -= amp[0];
  jamp[39] += amp[0];
  jamp[45] += amp[0];
  jamp[47] -= amp[0];
  jamp[64] += amp[0];
  jamp[88] -= amp[0];
  jamp[112] -= amp[0];
  jamp[118] += amp[0];
  VVV1_0( w[1], w[8], w[112], COUPs[0], &amp[0] );
  jamp[21] += amp[0];
  jamp[23] -= amp[0];
  jamp[28] -= amp[0];
  jamp[29] += amp[0];
  jamp[32] += amp[0];
  jamp[33] -= amp[0];
  jamp[38] -= amp[0];
  jamp[39] += amp[0];
  jamp[42] += amp[0];
  jamp[43] -= amp[0];
  jamp[61] -= amp[0];
  jamp[64] += amp[0];
  jamp[85] += amp[0];
  jamp[88] -= amp[0];
  jamp[99] -= amp[0];
  jamp[101] += amp[0];
  VVV1_0( w[1], w[8], w[111], COUPs[0], &amp[0] );
  jamp[9] += amp[0];
  jamp[15] -= amp[0];
  jamp[24] -= amp[0];
  jamp[26] += amp[0];
  jamp[32] += amp[0];
  jamp[38] -= amp[0];
  jamp[42] += amp[0];
  jamp[43] -= amp[0];
  jamp[45] -= amp[0];
  jamp[47] += amp[0];
  jamp[61] -= amp[0];
  jamp[85] += amp[0];
  jamp[99] -= amp[0];
  jamp[101] += amp[0];
  jamp[112] += amp[0];
  jamp[118] -= amp[0];

  // *** DIAGRAM 1019 OF 1240 ***

  // Wavefunction(s) for diagram number 1019
  // (none)

  // Amplitude(s) for diagram number 1019
  VVV1_0( w[56], w[68], w[5], COUPs[0], &amp[0] );
#ifdef MGONGPU_SUPPORTS_MULTICHANNEL
  if( channelId == 1019 ) allNumerators[0] += cxabs2( amp[0] );
  if( channelId != 0 ) allDenominators[0] += cxabs2( amp[0] );
#endif
  jamp[1] += amp[0];
  jamp[4] -= amp[0];
  jamp[10] -= amp[0];
  jamp[12] -= amp[0];
  jamp[13] += amp[0];
  jamp[15] += amp[0];
  jamp[17] -= amp[0];
  jamp[20] += amp[0];
  jamp[35] -= amp[0];
  jamp[45] += amp[0];
  jamp[69] += amp[0];
  jamp[81] += amp[0];
  jamp[83] -= amp[0];
  jamp[89] -= amp[0];
  jamp[95] += amp[0];
  jamp[111] -= amp[0];

  // *** DIAGRAM 1020 OF 1240 ***

  // Wavefunction(s) for diagram number 1020
  // (none)

  // Amplitude(s) for diagram number 1020
  VVV1_0( w[56], w[1], w[16], COUPs[0], &amp[0] );
#ifdef MGONGPU_SUPPORTS_MULTICHANNEL
  if( channelId == 1020 ) allNumerators[0] += cxabs2( amp[0] );
  if( channelId != 0 ) allDenominators[0] += cxabs2( amp[0] );
#endif
  jamp[1] += amp[0];
  jamp[2] -= amp[0];
  jamp[3] += amp[0];
  jamp[4] -= amp[0];
  jamp[11] -= amp[0];
  jamp[15] += amp[0];
  jamp[17] -= amp[0];
  jamp[21] += amp[0];
  jamp[35] -= amp[0];
  jamp[39] += amp[0];
  jamp[41] -= amp[0];
  jamp[45] += amp[0];
  jamp[71] += amp[0];
  jamp[89] -= amp[0];
  jamp[95] += amp[0];
  jamp[113] -= amp[0];

  // *** DIAGRAM 1021 OF 1240 ***

  // Wavefunction(s) for diagram number 1021
  // (none)

  // Amplitude(s) for diagram number 1021
  VVVV1_0( w[1], w[27], w[5], w[56], COUPs[2], &amp[0] );
  jamp[1] += amp[0];
  jamp[4] -= amp[0];
  jamp[10] -= amp[0];
  jamp[12] -= amp[0];
  jamp[13] += amp[0];
  jamp[15] += amp[0];
  jamp[17] -= amp[0];
  jamp[20] += amp[0];
  jamp[35] -= amp[0];
  jamp[45] += amp[0];
  jamp[69] += amp[0];
  jamp[81] += amp[0];
  jamp[83] -= amp[0];
  jamp[89] -= amp[0];
  jamp[95] += amp[0];
  jamp[111] -= amp[0];
  VVVV3_0( w[1], w[27], w[5], w[56], COUPs[2], &amp[0] );
  jamp[2] += amp[0];
  jamp[3] -= amp[0];
  jamp[10] -= amp[0];
  jamp[11] += amp[0];
  jamp[12] -= amp[0];
  jamp[13] += amp[0];
  jamp[20] += amp[0];
  jamp[21] -= amp[0];
  jamp[39] -= amp[0];
  jamp[41] += amp[0];
  jamp[69] += amp[0];
  jamp[71] -= amp[0];
  jamp[81] += amp[0];
  jamp[83] -= amp[0];
  jamp[111] -= amp[0];
  jamp[113] += amp[0];
  VVVV4_0( w[1], w[27], w[5], w[56], COUPs[2], &amp[0] );
  jamp[1] -= amp[0];
  jamp[2] += amp[0];
  jamp[3] -= amp[0];
  jamp[4] += amp[0];
  jamp[11] += amp[0];
  jamp[15] -= amp[0];
  jamp[17] += amp[0];
  jamp[21] -= amp[0];
  jamp[35] += amp[0];
  jamp[39] -= amp[0];
  jamp[41] += amp[0];
  jamp[45] -= amp[0];
  jamp[71] -= amp[0];
  jamp[89] += amp[0];
  jamp[95] -= amp[0];
  jamp[113] += amp[0];

  // *** DIAGRAM 1022 OF 1240 ***

  // Wavefunction(s) for diagram number 1022
  // (none)

  // Amplitude(s) for diagram number 1022
  VVV1_0( w[101], w[108], w[5], COUPs[0], &amp[0] );
#ifdef MGONGPU_SUPPORTS_MULTICHANNEL
  if( channelId == 1022 ) allNumerators[0] += cxabs2( amp[0] );
  if( channelId != 0 ) allDenominators[0] += cxabs2( amp[0] );
#endif
  jamp[11] += amp[0];
  jamp[21] -= amp[0];
  jamp[25] -= amp[0];
  jamp[28] += amp[0];
  jamp[34] += amp[0];
  jamp[36] += amp[0];
  jamp[37] -= amp[0];
  jamp[39] -= amp[0];
  jamp[41] += amp[0];
  jamp[44] -= amp[0];
  jamp[67] -= amp[0];
  jamp[75] -= amp[0];
  jamp[77] += amp[0];
  jamp[88] += amp[0];
  jamp[94] -= amp[0];
  jamp[109] += amp[0];

  // *** DIAGRAM 1023 OF 1240 ***

  // Wavefunction(s) for diagram number 1023
  // (none)

  // Amplitude(s) for diagram number 1023
  VVV1_0( w[101], w[1], w[10], COUPs[0], &amp[0] );
#ifdef MGONGPU_SUPPORTS_MULTICHANNEL
  if( channelId == 1023 ) allNumerators[0] += cxabs2( amp[0] );
  if( channelId != 0 ) allDenominators[0] += cxabs2( amp[0] );
#endif
  jamp[10] += amp[0];
  jamp[20] -= amp[0];
  jamp[25] -= amp[0];
  jamp[28] += amp[0];
  jamp[34] += amp[0];
  jamp[44] -= amp[0];
  jamp[66] -= amp[0];
  jamp[75] -= amp[0];
  jamp[77] += amp[0];
  jamp[78] += amp[0];
  jamp[79] -= amp[0];
  jamp[81] -= amp[0];
  jamp[83] += amp[0];
  jamp[88] += amp[0];
  jamp[94] -= amp[0];
  jamp[108] += amp[0];

  // *** DIAGRAM 1024 OF 1240 ***

  // Wavefunction(s) for diagram number 1024
  // (none)

  // Amplitude(s) for diagram number 1024
  VVVV1_0( w[1], w[8], w[5], w[101], COUPs[2], &amp[0] );
  jamp[11] += amp[0];
  jamp[21] -= amp[0];
  jamp[25] -= amp[0];
  jamp[28] += amp[0];
  jamp[34] += amp[0];
  jamp[36] += amp[0];
  jamp[37] -= amp[0];
  jamp[39] -= amp[0];
  jamp[41] += amp[0];
  jamp[44] -= amp[0];
  jamp[67] -= amp[0];
  jamp[75] -= amp[0];
  jamp[77] += amp[0];
  jamp[88] += amp[0];
  jamp[94] -= amp[0];
  jamp[109] += amp[0];
  VVVV3_0( w[1], w[8], w[5], w[101], COUPs[2], &amp[0] );
  jamp[10] -= amp[0];
  jamp[11] += amp[0];
  jamp[20] += amp[0];
  jamp[21] -= amp[0];
  jamp[36] += amp[0];
  jamp[37] -= amp[0];
  jamp[39] -= amp[0];
  jamp[41] += amp[0];
  jamp[66] += amp[0];
  jamp[67] -= amp[0];
  jamp[78] -= amp[0];
  jamp[79] += amp[0];
  jamp[81] += amp[0];
  jamp[83] -= amp[0];
  jamp[108] -= amp[0];
  jamp[109] += amp[0];
  VVVV4_0( w[1], w[8], w[5], w[101], COUPs[2], &amp[0] );
  jamp[10] -= amp[0];
  jamp[20] += amp[0];
  jamp[25] += amp[0];
  jamp[28] -= amp[0];
  jamp[34] -= amp[0];
  jamp[44] += amp[0];
  jamp[66] += amp[0];
  jamp[75] += amp[0];
  jamp[77] -= amp[0];
  jamp[78] -= amp[0];
  jamp[79] += amp[0];
  jamp[81] += amp[0];
  jamp[83] -= amp[0];
  jamp[88] -= amp[0];
  jamp[94] += amp[0];
  jamp[108] -= amp[0];

  // *** DIAGRAM 1025 OF 1240 ***

  // Wavefunction(s) for diagram number 1025
  // (none)

  // Amplitude(s) for diagram number 1025
  VVV1_0( w[0], w[108], w[16], COUPs[0], &amp[0] );
#ifdef MGONGPU_SUPPORTS_MULTICHANNEL
  if( channelId == 1025 ) allNumerators[0] += cxabs2( amp[0] );
  if( channelId != 0 ) allDenominators[0] += cxabs2( amp[0] );
#endif
  jamp[11] += amp[0];
  jamp[15] -= amp[0];
  jamp[17] += amp[0];
  jamp[21] -= amp[0];
  jamp[25] -= amp[0];
  jamp[26] += amp[0];
  jamp[27] -= amp[0];
  jamp[28] += amp[0];
  jamp[35] += amp[0];
  jamp[39] -= amp[0];
  jamp[41] += amp[0];
  jamp[45] -= amp[0];
  jamp[70] -= amp[0];
  jamp[88] += amp[0];
  jamp[94] -= amp[0];
  jamp[112] += amp[0];

  // *** DIAGRAM 1026 OF 1240 ***

  // Wavefunction(s) for diagram number 1026
  // (none)

  // Amplitude(s) for diagram number 1026
  VVV1_0( w[0], w[68], w[10], COUPs[0], &amp[0] );
#ifdef MGONGPU_SUPPORTS_MULTICHANNEL
  if( channelId == 1026 ) allNumerators[0] += cxabs2( amp[0] );
  if( channelId != 0 ) allDenominators[0] += cxabs2( amp[0] );
#endif
  jamp[1] += amp[0];
  jamp[4] -= amp[0];
  jamp[10] -= amp[0];
  jamp[20] += amp[0];
  jamp[34] -= amp[0];
  jamp[44] += amp[0];
  jamp[68] += amp[0];
  jamp[72] -= amp[0];
  jamp[73] += amp[0];
  jamp[75] += amp[0];
  jamp[77] -= amp[0];
  jamp[81] += amp[0];
  jamp[83] -= amp[0];
  jamp[89] -= amp[0];
  jamp[95] += amp[0];
  jamp[110] -= amp[0];

  // *** DIAGRAM 1027 OF 1240 ***

  // Wavefunction(s) for diagram number 1027
  // (none)

  // Amplitude(s) for diagram number 1027
  VVV1_0( w[27], w[5], w[11], COUPs[0], &amp[0] );
  jamp[11] += amp[0];
  jamp[15] -= amp[0];
  jamp[17] += amp[0];
  jamp[21] -= amp[0];
  jamp[25] -= amp[0];
  jamp[26] += amp[0];
  jamp[27] -= amp[0];
  jamp[28] += amp[0];
  jamp[35] += amp[0];
  jamp[39] -= amp[0];
  jamp[41] += amp[0];
  jamp[45] -= amp[0];
  jamp[70] -= amp[0];
  jamp[88] += amp[0];
  jamp[94] -= amp[0];
  jamp[112] += amp[0];
  VVV1_0( w[27], w[5], w[42], COUPs[0], &amp[0] );
  jamp[1] -= amp[0];
  jamp[2] += amp[0];
  jamp[3] -= amp[0];
  jamp[4] += amp[0];
  jamp[11] += amp[0];
  jamp[15] -= amp[0];
  jamp[17] += amp[0];
  jamp[21] -= amp[0];
  jamp[35] += amp[0];
  jamp[39] -= amp[0];
  jamp[41] += amp[0];
  jamp[45] -= amp[0];
  jamp[71] -= amp[0];
  jamp[89] += amp[0];
  jamp[95] -= amp[0];
  jamp[113] += amp[0];
  VVV1_0( w[27], w[5], w[76], COUPs[0], &amp[0] );
  jamp[1] -= amp[0];
  jamp[2] += amp[0];
  jamp[3] -= amp[0];
  jamp[4] += amp[0];
  jamp[25] += amp[0];
  jamp[26] -= amp[0];
  jamp[27] += amp[0];
  jamp[28] -= amp[0];
  jamp[70] += amp[0];
  jamp[71] -= amp[0];
  jamp[88] -= amp[0];
  jamp[89] += amp[0];
  jamp[94] += amp[0];
  jamp[95] -= amp[0];
  jamp[112] -= amp[0];
  jamp[113] += amp[0];

  // *** DIAGRAM 1028 OF 1240 ***

  // Wavefunction(s) for diagram number 1028
  VVVV1P0_1( w[0], w[1], w[27], COUPs[2], 0., 0., w[10] );
  VVVV3P0_1( w[0], w[1], w[27], COUPs[2], 0., 0., w[16] );
  VVVV4P0_1( w[0], w[1], w[27], COUPs[2], 0., 0., w[111] );

  // Amplitude(s) for diagram number 1028
  VVV1_0( w[8], w[5], w[10], COUPs[0], &amp[0] );
  jamp[1] += amp[0];
  jamp[4] -= amp[0];
  jamp[10] -= amp[0];
  jamp[20] += amp[0];
  jamp[34] -= amp[0];
  jamp[44] += amp[0];
  jamp[68] += amp[0];
  jamp[72] -= amp[0];
  jamp[73] += amp[0];
  jamp[75] += amp[0];
  jamp[77] -= amp[0];
  jamp[81] += amp[0];
  jamp[83] -= amp[0];
  jamp[89] -= amp[0];
  jamp[95] += amp[0];
  jamp[110] -= amp[0];
  VVV1_0( w[8], w[5], w[16], COUPs[0], &amp[0] );
  jamp[10] -= amp[0];
  jamp[20] += amp[0];
  jamp[25] += amp[0];
  jamp[28] -= amp[0];
  jamp[34] -= amp[0];
  jamp[44] += amp[0];
  jamp[66] += amp[0];
  jamp[75] += amp[0];
  jamp[77] -= amp[0];
  jamp[78] -= amp[0];
  jamp[79] += amp[0];
  jamp[81] += amp[0];
  jamp[83] -= amp[0];
  jamp[88] -= amp[0];
  jamp[94] += amp[0];
  jamp[108] -= amp[0];
  VVV1_0( w[8], w[5], w[111], COUPs[0], &amp[0] );
  jamp[1] -= amp[0];
  jamp[4] += amp[0];
  jamp[25] += amp[0];
  jamp[28] -= amp[0];
  jamp[66] += amp[0];
  jamp[68] -= amp[0];
  jamp[72] += amp[0];
  jamp[73] -= amp[0];
  jamp[78] -= amp[0];
  jamp[79] += amp[0];
  jamp[88] -= amp[0];
  jamp[89] += amp[0];
  jamp[94] += amp[0];
  jamp[95] -= amp[0];
  jamp[108] -= amp[0];
  jamp[110] += amp[0];

  // *** DIAGRAM 1029 OF 1240 ***

  // Wavefunction(s) for diagram number 1029
  // (none)

  // Amplitude(s) for diagram number 1029
  VVV1_0( w[1], w[27], w[115], COUPs[0], &amp[0] );
  jamp[1] -= amp[0];
  jamp[4] += amp[0];
  jamp[10] += amp[0];
  jamp[20] -= amp[0];
  jamp[34] += amp[0];
  jamp[44] -= amp[0];
  jamp[68] -= amp[0];
  jamp[72] += amp[0];
  jamp[73] -= amp[0];
  jamp[75] -= amp[0];
  jamp[77] += amp[0];
  jamp[81] -= amp[0];
  jamp[83] += amp[0];
  jamp[89] += amp[0];
  jamp[95] -= amp[0];
  jamp[110] += amp[0];
  VVV1_0( w[1], w[27], w[116], COUPs[0], &amp[0] );
  jamp[12] -= amp[0];
  jamp[13] += amp[0];
  jamp[15] += amp[0];
  jamp[17] -= amp[0];
  jamp[34] += amp[0];
  jamp[35] -= amp[0];
  jamp[44] -= amp[0];
  jamp[45] += amp[0];
  jamp[68] -= amp[0];
  jamp[69] += amp[0];
  jamp[72] += amp[0];
  jamp[73] -= amp[0];
  jamp[75] -= amp[0];
  jamp[77] += amp[0];
  jamp[110] += amp[0];
  jamp[111] -= amp[0];
  VVV1_0( w[1], w[27], w[117], COUPs[0], &amp[0] );
  jamp[1] += amp[0];
  jamp[4] -= amp[0];
  jamp[10] -= amp[0];
  jamp[12] -= amp[0];
  jamp[13] += amp[0];
  jamp[15] += amp[0];
  jamp[17] -= amp[0];
  jamp[20] += amp[0];
  jamp[35] -= amp[0];
  jamp[45] += amp[0];
  jamp[69] += amp[0];
  jamp[81] += amp[0];
  jamp[83] -= amp[0];
  jamp[89] -= amp[0];
  jamp[95] += amp[0];
  jamp[111] -= amp[0];

  // *** DIAGRAM 1030 OF 1240 ***

  // Wavefunction(s) for diagram number 1030
  // (none)

  // Amplitude(s) for diagram number 1030
  VVV1_0( w[1], w[8], w[9], COUPs[0], &amp[0] );
  jamp[11] -= amp[0];
  jamp[15] += amp[0];
  jamp[17] -= amp[0];
  jamp[21] += amp[0];
  jamp[25] += amp[0];
  jamp[26] -= amp[0];
  jamp[27] += amp[0];
  jamp[28] -= amp[0];
  jamp[35] -= amp[0];
  jamp[39] += amp[0];
  jamp[41] -= amp[0];
  jamp[45] += amp[0];
  jamp[70] += amp[0];
  jamp[88] -= amp[0];
  jamp[94] += amp[0];
  jamp[112] -= amp[0];
  VVV1_0( w[1], w[8], w[110], COUPs[0], &amp[0] );
  jamp[15] += amp[0];
  jamp[17] -= amp[0];
  jamp[26] -= amp[0];
  jamp[27] += amp[0];
  jamp[34] += amp[0];
  jamp[35] -= amp[0];
  jamp[36] += amp[0];
  jamp[37] -= amp[0];
  jamp[44] -= amp[0];
  jamp[45] += amp[0];
  jamp[67] -= amp[0];
  jamp[70] += amp[0];
  jamp[75] -= amp[0];
  jamp[77] += amp[0];
  jamp[109] += amp[0];
  jamp[112] -= amp[0];
  VVV1_0( w[1], w[8], w[109], COUPs[0], &amp[0] );
  jamp[11] += amp[0];
  jamp[21] -= amp[0];
  jamp[25] -= amp[0];
  jamp[28] += amp[0];
  jamp[34] += amp[0];
  jamp[36] += amp[0];
  jamp[37] -= amp[0];
  jamp[39] -= amp[0];
  jamp[41] += amp[0];
  jamp[44] -= amp[0];
  jamp[67] -= amp[0];
  jamp[75] -= amp[0];
  jamp[77] += amp[0];
  jamp[88] += amp[0];
  jamp[94] -= amp[0];
  jamp[109] += amp[0];

  // *** DIAGRAM 1031 OF 1240 ***

  // Wavefunction(s) for diagram number 1031
  // (none)

  // Amplitude(s) for diagram number 1031
  VVV1_0( w[56], w[67], w[4], COUPs[0], &amp[0] );
#ifdef MGONGPU_SUPPORTS_MULTICHANNEL
  if( channelId == 1031 ) allNumerators[0] += cxabs2( amp[0] );
  if( channelId != 0 ) allDenominators[0] += cxabs2( amp[0] );
#endif
  jamp[3] += amp[0];
  jamp[5] -= amp[0];
  jamp[6] -= amp[0];
  jamp[7] += amp[0];
  jamp[9] += amp[0];
  jamp[11] -= amp[0];
  jamp[16] -= amp[0];
  jamp[22] += amp[0];
  jamp[41] -= amp[0];
  jamp[47] += amp[0];
  jamp[57] += amp[0];
  jamp[59] -= amp[0];
  jamp[65] -= amp[0];
  jamp[71] += amp[0];
  jamp[93] += amp[0];
  jamp[117] -= amp[0];

  // *** DIAGRAM 1032 OF 1240 ***

  // Wavefunction(s) for diagram number 1032
  // (none)

  // Amplitude(s) for diagram number 1032
  VVV1_0( w[56], w[1], w[19], COUPs[0], &amp[0] );
#ifdef MGONGPU_SUPPORTS_MULTICHANNEL
  if( channelId == 1032 ) allNumerators[0] += cxabs2( amp[0] );
  if( channelId != 0 ) allDenominators[0] += cxabs2( amp[0] );
#endif
  jamp[0] += amp[0];
  jamp[1] -= amp[0];
  jamp[3] -= amp[0];
  jamp[5] += amp[0];
  jamp[9] -= amp[0];
  jamp[11] += amp[0];
  jamp[17] += amp[0];
  jamp[23] -= amp[0];
  jamp[33] -= amp[0];
  jamp[35] += amp[0];
  jamp[41] += amp[0];
  jamp[47] -= amp[0];
  jamp[65] += amp[0];
  jamp[71] -= amp[0];
  jamp[95] -= amp[0];
  jamp[119] += amp[0];

  // *** DIAGRAM 1033 OF 1240 ***

  // Wavefunction(s) for diagram number 1033
  // (none)

  // Amplitude(s) for diagram number 1033
  VVVV1_0( w[1], w[4], w[29], w[56], COUPs[2], &amp[0] );
  jamp[0] += amp[0];
  jamp[1] -= amp[0];
  jamp[6] -= amp[0];
  jamp[7] += amp[0];
  jamp[16] -= amp[0];
  jamp[17] += amp[0];
  jamp[22] += amp[0];
  jamp[23] -= amp[0];
  jamp[33] -= amp[0];
  jamp[35] += amp[0];
  jamp[57] += amp[0];
  jamp[59] -= amp[0];
  jamp[93] += amp[0];
  jamp[95] -= amp[0];
  jamp[117] -= amp[0];
  jamp[119] += amp[0];
  VVVV3_0( w[1], w[4], w[29], w[56], COUPs[2], &amp[0] );
  jamp[3] += amp[0];
  jamp[5] -= amp[0];
  jamp[6] -= amp[0];
  jamp[7] += amp[0];
  jamp[9] += amp[0];
  jamp[11] -= amp[0];
  jamp[16] -= amp[0];
  jamp[22] += amp[0];
  jamp[41] -= amp[0];
  jamp[47] += amp[0];
  jamp[57] += amp[0];
  jamp[59] -= amp[0];
  jamp[65] -= amp[0];
  jamp[71] += amp[0];
  jamp[93] += amp[0];
  jamp[117] -= amp[0];
  VVVV4_0( w[1], w[4], w[29], w[56], COUPs[2], &amp[0] );
  jamp[0] -= amp[0];
  jamp[1] += amp[0];
  jamp[3] += amp[0];
  jamp[5] -= amp[0];
  jamp[9] += amp[0];
  jamp[11] -= amp[0];
  jamp[17] -= amp[0];
  jamp[23] += amp[0];
  jamp[33] += amp[0];
  jamp[35] -= amp[0];
  jamp[41] -= amp[0];
  jamp[47] += amp[0];
  jamp[65] -= amp[0];
  jamp[71] += amp[0];
  jamp[95] += amp[0];
  jamp[119] -= amp[0];

  // *** DIAGRAM 1034 OF 1240 ***

  // Wavefunction(s) for diagram number 1034
  // (none)

  // Amplitude(s) for diagram number 1034
  VVV1_0( w[96], w[108], w[4], COUPs[0], &amp[0] );
#ifdef MGONGPU_SUPPORTS_MULTICHANNEL
  if( channelId == 1034 ) allNumerators[0] += cxabs2( amp[0] );
  if( channelId != 0 ) allDenominators[0] += cxabs2( amp[0] );
#endif
  jamp[17] += amp[0];
  jamp[23] -= amp[0];
  jamp[27] -= amp[0];
  jamp[29] += amp[0];
  jamp[30] += amp[0];
  jamp[31] -= amp[0];
  jamp[33] -= amp[0];
  jamp[35] += amp[0];
  jamp[40] += amp[0];
  jamp[46] -= amp[0];
  jamp[51] -= amp[0];
  jamp[53] += amp[0];
  jamp[64] += amp[0];
  jamp[70] -= amp[0];
  jamp[91] -= amp[0];
  jamp[115] += amp[0];

  // *** DIAGRAM 1035 OF 1240 ***

  // Wavefunction(s) for diagram number 1035
  // (none)

  // Amplitude(s) for diagram number 1035
  VVV1_0( w[96], w[1], w[13], COUPs[0], &amp[0] );
#ifdef MGONGPU_SUPPORTS_MULTICHANNEL
  if( channelId == 1035 ) allNumerators[0] += cxabs2( amp[0] );
  if( channelId != 0 ) allDenominators[0] += cxabs2( amp[0] );
#endif
  jamp[16] += amp[0];
  jamp[22] -= amp[0];
  jamp[27] -= amp[0];
  jamp[29] += amp[0];
  jamp[40] += amp[0];
  jamp[46] -= amp[0];
  jamp[51] -= amp[0];
  jamp[53] += amp[0];
  jamp[54] += amp[0];
  jamp[55] -= amp[0];
  jamp[57] -= amp[0];
  jamp[59] += amp[0];
  jamp[64] += amp[0];
  jamp[70] -= amp[0];
  jamp[90] -= amp[0];
  jamp[114] += amp[0];

  // *** DIAGRAM 1036 OF 1240 ***

  // Wavefunction(s) for diagram number 1036
  // (none)

  // Amplitude(s) for diagram number 1036
  VVVV1_0( w[1], w[8], w[4], w[96], COUPs[2], &amp[0] );
  jamp[17] += amp[0];
  jamp[23] -= amp[0];
  jamp[27] -= amp[0];
  jamp[29] += amp[0];
  jamp[30] += amp[0];
  jamp[31] -= amp[0];
  jamp[33] -= amp[0];
  jamp[35] += amp[0];
  jamp[40] += amp[0];
  jamp[46] -= amp[0];
  jamp[51] -= amp[0];
  jamp[53] += amp[0];
  jamp[64] += amp[0];
  jamp[70] -= amp[0];
  jamp[91] -= amp[0];
  jamp[115] += amp[0];
  VVVV3_0( w[1], w[8], w[4], w[96], COUPs[2], &amp[0] );
  jamp[16] -= amp[0];
  jamp[17] += amp[0];
  jamp[22] += amp[0];
  jamp[23] -= amp[0];
  jamp[30] += amp[0];
  jamp[31] -= amp[0];
  jamp[33] -= amp[0];
  jamp[35] += amp[0];
  jamp[54] -= amp[0];
  jamp[55] += amp[0];
  jamp[57] += amp[0];
  jamp[59] -= amp[0];
  jamp[90] += amp[0];
  jamp[91] -= amp[0];
  jamp[114] -= amp[0];
  jamp[115] += amp[0];
  VVVV4_0( w[1], w[8], w[4], w[96], COUPs[2], &amp[0] );
  jamp[16] -= amp[0];
  jamp[22] += amp[0];
  jamp[27] += amp[0];
  jamp[29] -= amp[0];
  jamp[40] -= amp[0];
  jamp[46] += amp[0];
  jamp[51] += amp[0];
  jamp[53] -= amp[0];
  jamp[54] -= amp[0];
  jamp[55] += amp[0];
  jamp[57] += amp[0];
  jamp[59] -= amp[0];
  jamp[64] -= amp[0];
  jamp[70] += amp[0];
  jamp[90] += amp[0];
  jamp[114] -= amp[0];

  // *** DIAGRAM 1037 OF 1240 ***

  // Wavefunction(s) for diagram number 1037
  // (none)

  // Amplitude(s) for diagram number 1037
  VVV1_0( w[0], w[108], w[19], COUPs[0], &amp[0] );
#ifdef MGONGPU_SUPPORTS_MULTICHANNEL
  if( channelId == 1037 ) allNumerators[0] += cxabs2( amp[0] );
  if( channelId != 0 ) allDenominators[0] += cxabs2( amp[0] );
#endif
  jamp[9] += amp[0];
  jamp[11] -= amp[0];
  jamp[17] -= amp[0];
  jamp[23] += amp[0];
  jamp[24] -= amp[0];
  jamp[25] += amp[0];
  jamp[27] += amp[0];
  jamp[29] -= amp[0];
  jamp[33] += amp[0];
  jamp[35] -= amp[0];
  jamp[41] -= amp[0];
  jamp[47] += amp[0];
  jamp[64] -= amp[0];
  jamp[70] += amp[0];
  jamp[94] += amp[0];
  jamp[118] -= amp[0];

  // *** DIAGRAM 1038 OF 1240 ***

  // Wavefunction(s) for diagram number 1038
  // (none)

  // Amplitude(s) for diagram number 1038
  VVV1_0( w[0], w[67], w[13], COUPs[0], &amp[0] );
#ifdef MGONGPU_SUPPORTS_MULTICHANNEL
  if( channelId == 1038 ) allNumerators[0] += cxabs2( amp[0] );
  if( channelId != 0 ) allDenominators[0] += cxabs2( amp[0] );
#endif
  jamp[3] += amp[0];
  jamp[5] -= amp[0];
  jamp[16] -= amp[0];
  jamp[22] += amp[0];
  jamp[40] -= amp[0];
  jamp[46] += amp[0];
  jamp[48] -= amp[0];
  jamp[49] += amp[0];
  jamp[51] += amp[0];
  jamp[53] -= amp[0];
  jamp[57] += amp[0];
  jamp[59] -= amp[0];
  jamp[65] -= amp[0];
  jamp[71] += amp[0];
  jamp[92] += amp[0];
  jamp[116] -= amp[0];

  // *** DIAGRAM 1039 OF 1240 ***

  // Wavefunction(s) for diagram number 1039
  // (none)

  // Amplitude(s) for diagram number 1039
  VVV1_0( w[4], w[29], w[11], COUPs[0], &amp[0] );
  jamp[9] += amp[0];
  jamp[11] -= amp[0];
  jamp[17] -= amp[0];
  jamp[23] += amp[0];
  jamp[24] -= amp[0];
  jamp[25] += amp[0];
  jamp[27] += amp[0];
  jamp[29] -= amp[0];
  jamp[33] += amp[0];
  jamp[35] -= amp[0];
  jamp[41] -= amp[0];
  jamp[47] += amp[0];
  jamp[64] -= amp[0];
  jamp[70] += amp[0];
  jamp[94] += amp[0];
  jamp[118] -= amp[0];
  VVV1_0( w[4], w[29], w[42], COUPs[0], &amp[0] );
  jamp[0] -= amp[0];
  jamp[1] += amp[0];
  jamp[3] += amp[0];
  jamp[5] -= amp[0];
  jamp[9] += amp[0];
  jamp[11] -= amp[0];
  jamp[17] -= amp[0];
  jamp[23] += amp[0];
  jamp[33] += amp[0];
  jamp[35] -= amp[0];
  jamp[41] -= amp[0];
  jamp[47] += amp[0];
  jamp[65] -= amp[0];
  jamp[71] += amp[0];
  jamp[95] += amp[0];
  jamp[119] -= amp[0];
  VVV1_0( w[4], w[29], w[76], COUPs[0], &amp[0] );
  jamp[0] -= amp[0];
  jamp[1] += amp[0];
  jamp[3] += amp[0];
  jamp[5] -= amp[0];
  jamp[24] += amp[0];
  jamp[25] -= amp[0];
  jamp[27] -= amp[0];
  jamp[29] += amp[0];
  jamp[64] += amp[0];
  jamp[65] -= amp[0];
  jamp[70] -= amp[0];
  jamp[71] += amp[0];
  jamp[94] -= amp[0];
  jamp[95] += amp[0];
  jamp[118] += amp[0];
  jamp[119] -= amp[0];

  // *** DIAGRAM 1040 OF 1240 ***

  // Wavefunction(s) for diagram number 1040
  VVVV1P0_1( w[0], w[1], w[29], COUPs[2], 0., 0., w[76] );
  VVVV3P0_1( w[0], w[1], w[29], COUPs[2], 0., 0., w[42] );
  VVVV4P0_1( w[0], w[1], w[29], COUPs[2], 0., 0., w[11] );

  // Amplitude(s) for diagram number 1040
  VVV1_0( w[8], w[4], w[76], COUPs[0], &amp[0] );
  jamp[3] += amp[0];
  jamp[5] -= amp[0];
  jamp[16] -= amp[0];
  jamp[22] += amp[0];
  jamp[40] -= amp[0];
  jamp[46] += amp[0];
  jamp[48] -= amp[0];
  jamp[49] += amp[0];
  jamp[51] += amp[0];
  jamp[53] -= amp[0];
  jamp[57] += amp[0];
  jamp[59] -= amp[0];
  jamp[65] -= amp[0];
  jamp[71] += amp[0];
  jamp[92] += amp[0];
  jamp[116] -= amp[0];
  VVV1_0( w[8], w[4], w[42], COUPs[0], &amp[0] );
  jamp[16] -= amp[0];
  jamp[22] += amp[0];
  jamp[27] += amp[0];
  jamp[29] -= amp[0];
  jamp[40] -= amp[0];
  jamp[46] += amp[0];
  jamp[51] += amp[0];
  jamp[53] -= amp[0];
  jamp[54] -= amp[0];
  jamp[55] += amp[0];
  jamp[57] += amp[0];
  jamp[59] -= amp[0];
  jamp[64] -= amp[0];
  jamp[70] += amp[0];
  jamp[90] += amp[0];
  jamp[114] -= amp[0];
  VVV1_0( w[8], w[4], w[11], COUPs[0], &amp[0] );
  jamp[3] -= amp[0];
  jamp[5] += amp[0];
  jamp[27] += amp[0];
  jamp[29] -= amp[0];
  jamp[48] += amp[0];
  jamp[49] -= amp[0];
  jamp[54] -= amp[0];
  jamp[55] += amp[0];
  jamp[64] -= amp[0];
  jamp[65] += amp[0];
  jamp[70] += amp[0];
  jamp[71] -= amp[0];
  jamp[90] += amp[0];
  jamp[92] -= amp[0];
  jamp[114] -= amp[0];
  jamp[116] += amp[0];

  // *** DIAGRAM 1041 OF 1240 ***

  // Wavefunction(s) for diagram number 1041
  // (none)

  // Amplitude(s) for diagram number 1041
  VVV1_0( w[1], w[29], w[107], COUPs[0], &amp[0] );
  jamp[3] -= amp[0];
  jamp[5] += amp[0];
  jamp[16] += amp[0];
  jamp[22] -= amp[0];
  jamp[40] += amp[0];
  jamp[46] -= amp[0];
  jamp[48] += amp[0];
  jamp[49] -= amp[0];
  jamp[51] -= amp[0];
  jamp[53] += amp[0];
  jamp[57] -= amp[0];
  jamp[59] += amp[0];
  jamp[65] += amp[0];
  jamp[71] -= amp[0];
  jamp[92] -= amp[0];
  jamp[116] += amp[0];
  VVV1_0( w[1], w[29], w[95], COUPs[0], &amp[0] );
  jamp[6] -= amp[0];
  jamp[7] += amp[0];
  jamp[9] += amp[0];
  jamp[11] -= amp[0];
  jamp[40] += amp[0];
  jamp[41] -= amp[0];
  jamp[46] -= amp[0];
  jamp[47] += amp[0];
  jamp[48] += amp[0];
  jamp[49] -= amp[0];
  jamp[51] -= amp[0];
  jamp[53] += amp[0];
  jamp[92] -= amp[0];
  jamp[93] += amp[0];
  jamp[116] += amp[0];
  jamp[117] -= amp[0];
  VVV1_0( w[1], w[29], w[105], COUPs[0], &amp[0] );
  jamp[3] += amp[0];
  jamp[5] -= amp[0];
  jamp[6] -= amp[0];
  jamp[7] += amp[0];
  jamp[9] += amp[0];
  jamp[11] -= amp[0];
  jamp[16] -= amp[0];
  jamp[22] += amp[0];
  jamp[41] -= amp[0];
  jamp[47] += amp[0];
  jamp[57] += amp[0];
  jamp[59] -= amp[0];
  jamp[65] -= amp[0];
  jamp[71] += amp[0];
  jamp[93] += amp[0];
  jamp[117] -= amp[0];

  // *** DIAGRAM 1042 OF 1240 ***

  // Wavefunction(s) for diagram number 1042
  // (none)

  // Amplitude(s) for diagram number 1042
  VVV1_0( w[1], w[8], w[87], COUPs[0], &amp[0] );
  jamp[9] -= amp[0];
  jamp[11] += amp[0];
  jamp[17] += amp[0];
  jamp[23] -= amp[0];
  jamp[24] += amp[0];
  jamp[25] -= amp[0];
  jamp[27] -= amp[0];
  jamp[29] += amp[0];
  jamp[33] -= amp[0];
  jamp[35] += amp[0];
  jamp[41] += amp[0];
  jamp[47] -= amp[0];
  jamp[64] += amp[0];
  jamp[70] -= amp[0];
  jamp[94] -= amp[0];
  jamp[118] += amp[0];
  VVV1_0( w[1], w[8], w[34], COUPs[0], &amp[0] );
  jamp[17] += amp[0];
  jamp[23] -= amp[0];
  jamp[27] -= amp[0];
  jamp[29] += amp[0];
  jamp[30] += amp[0];
  jamp[31] -= amp[0];
  jamp[33] -= amp[0];
  jamp[35] += amp[0];
  jamp[40] += amp[0];
  jamp[46] -= amp[0];
  jamp[51] -= amp[0];
  jamp[53] += amp[0];
  jamp[64] += amp[0];
  jamp[70] -= amp[0];
  jamp[91] -= amp[0];
  jamp[115] += amp[0];
  VVV1_0( w[1], w[8], w[86], COUPs[0], &amp[0] );
  jamp[9] += amp[0];
  jamp[11] -= amp[0];
  jamp[24] -= amp[0];
  jamp[25] += amp[0];
  jamp[30] += amp[0];
  jamp[31] -= amp[0];
  jamp[40] += amp[0];
  jamp[41] -= amp[0];
  jamp[46] -= amp[0];
  jamp[47] += amp[0];
  jamp[51] -= amp[0];
  jamp[53] += amp[0];
  jamp[91] -= amp[0];
  jamp[94] += amp[0];
  jamp[115] += amp[0];
  jamp[118] -= amp[0];

  // *** DIAGRAM 1043 OF 1240 ***

  // Wavefunction(s) for diagram number 1043
  // (none)

  // Amplitude(s) for diagram number 1043
  VVVV1_0( w[0], w[1], w[8], w[30], COUPs[2], &amp[0] );
  jamp[0] += amp[0];
  jamp[1] -= amp[0];
  jamp[3] -= amp[0];
  jamp[5] += amp[0];
  jamp[24] -= amp[0];
  jamp[25] += amp[0];
  jamp[27] += amp[0];
  jamp[29] -= amp[0];
  jamp[64] -= amp[0];
  jamp[65] += amp[0];
  jamp[70] += amp[0];
  jamp[71] -= amp[0];
  jamp[94] += amp[0];
  jamp[95] -= amp[0];
  jamp[118] -= amp[0];
  jamp[119] += amp[0];
  VVVV3_0( w[0], w[1], w[8], w[30], COUPs[2], &amp[0] );
  jamp[0] += amp[0];
  jamp[1] -= amp[0];
  jamp[3] -= amp[0];
  jamp[5] += amp[0];
  jamp[9] -= amp[0];
  jamp[11] += amp[0];
  jamp[17] += amp[0];
  jamp[23] -= amp[0];
  jamp[33] -= amp[0];
  jamp[35] += amp[0];
  jamp[41] += amp[0];
  jamp[47] -= amp[0];
  jamp[65] += amp[0];
  jamp[71] -= amp[0];
  jamp[95] -= amp[0];
  jamp[119] += amp[0];
  VVVV4_0( w[0], w[1], w[8], w[30], COUPs[2], &amp[0] );
  jamp[9] -= amp[0];
  jamp[11] += amp[0];
  jamp[17] += amp[0];
  jamp[23] -= amp[0];
  jamp[24] += amp[0];
  jamp[25] -= amp[0];
  jamp[27] -= amp[0];
  jamp[29] += amp[0];
  jamp[33] -= amp[0];
  jamp[35] += amp[0];
  jamp[41] += amp[0];
  jamp[47] -= amp[0];
  jamp[64] += amp[0];
  jamp[70] -= amp[0];
  jamp[94] -= amp[0];
  jamp[118] += amp[0];
  VVVV1_0( w[0], w[1], w[8], w[31], COUPs[2], &amp[0] );
  jamp[1] -= amp[0];
  jamp[2] += amp[0];
  jamp[3] -= amp[0];
  jamp[4] += amp[0];
  jamp[25] += amp[0];
  jamp[26] -= amp[0];
  jamp[27] += amp[0];
  jamp[28] -= amp[0];
  jamp[70] += amp[0];
  jamp[71] -= amp[0];
  jamp[88] -= amp[0];
  jamp[89] += amp[0];
  jamp[94] += amp[0];
  jamp[95] -= amp[0];
  jamp[112] -= amp[0];
  jamp[113] += amp[0];
  VVVV3_0( w[0], w[1], w[8], w[31], COUPs[2], &amp[0] );
  jamp[1] -= amp[0];
  jamp[2] += amp[0];
  jamp[3] -= amp[0];
  jamp[4] += amp[0];
  jamp[11] += amp[0];
  jamp[15] -= amp[0];
  jamp[17] += amp[0];
  jamp[21] -= amp[0];
  jamp[35] += amp[0];
  jamp[39] -= amp[0];
  jamp[41] += amp[0];
  jamp[45] -= amp[0];
  jamp[71] -= amp[0];
  jamp[89] += amp[0];
  jamp[95] -= amp[0];
  jamp[113] += amp[0];
  VVVV4_0( w[0], w[1], w[8], w[31], COUPs[2], &amp[0] );
  jamp[11] += amp[0];
  jamp[15] -= amp[0];
  jamp[17] += amp[0];
  jamp[21] -= amp[0];
  jamp[25] -= amp[0];
  jamp[26] += amp[0];
  jamp[27] -= amp[0];
  jamp[28] += amp[0];
  jamp[35] += amp[0];
  jamp[39] -= amp[0];
  jamp[41] += amp[0];
  jamp[45] -= amp[0];
  jamp[70] -= amp[0];
  jamp[88] += amp[0];
  jamp[94] -= amp[0];
  jamp[112] += amp[0];
  VVVV1_0( w[0], w[1], w[8], w[32], COUPs[2], &amp[0] );
  jamp[0] -= amp[0];
  jamp[2] += amp[0];
  jamp[4] += amp[0];
  jamp[5] -= amp[0];
  jamp[24] += amp[0];
  jamp[26] -= amp[0];
  jamp[28] -= amp[0];
  jamp[29] += amp[0];
  jamp[64] += amp[0];
  jamp[65] -= amp[0];
  jamp[88] -= amp[0];
  jamp[89] += amp[0];
  jamp[112] -= amp[0];
  jamp[113] += amp[0];
  jamp[118] += amp[0];
  jamp[119] -= amp[0];
  VVVV3_0( w[0], w[1], w[8], w[32], COUPs[2], &amp[0] );
  jamp[0] -= amp[0];
  jamp[2] += amp[0];
  jamp[4] += amp[0];
  jamp[5] -= amp[0];
  jamp[9] += amp[0];
  jamp[15] -= amp[0];
  jamp[21] -= amp[0];
  jamp[23] += amp[0];
  jamp[33] += amp[0];
  jamp[39] -= amp[0];
  jamp[45] -= amp[0];
  jamp[47] += amp[0];
  jamp[65] -= amp[0];
  jamp[89] += amp[0];
  jamp[113] += amp[0];
  jamp[119] -= amp[0];
  VVVV4_0( w[0], w[1], w[8], w[32], COUPs[2], &amp[0] );
  jamp[9] += amp[0];
  jamp[15] -= amp[0];
  jamp[21] -= amp[0];
  jamp[23] += amp[0];
  jamp[24] -= amp[0];
  jamp[26] += amp[0];
  jamp[28] += amp[0];
  jamp[29] -= amp[0];
  jamp[33] += amp[0];
  jamp[39] -= amp[0];
  jamp[45] -= amp[0];
  jamp[47] += amp[0];
  jamp[64] -= amp[0];
  jamp[88] += amp[0];
  jamp[112] += amp[0];
  jamp[118] -= amp[0];

  // *** DIAGRAM 1044 OF 1240 ***

  // Wavefunction(s) for diagram number 1044
  // (none)

  // Amplitude(s) for diagram number 1044
  VVV1_0( w[1], w[30], w[56], COUPs[0], &amp[0] );
  jamp[0] += amp[0];
  jamp[1] -= amp[0];
  jamp[3] -= amp[0];
  jamp[5] += amp[0];
  jamp[9] -= amp[0];
  jamp[11] += amp[0];
  jamp[17] += amp[0];
  jamp[23] -= amp[0];
  jamp[33] -= amp[0];
  jamp[35] += amp[0];
  jamp[41] += amp[0];
  jamp[47] -= amp[0];
  jamp[65] += amp[0];
  jamp[71] -= amp[0];
  jamp[95] -= amp[0];
  jamp[119] += amp[0];
  VVV1_0( w[1], w[31], w[56], COUPs[0], &amp[0] );
  jamp[1] -= amp[0];
  jamp[2] += amp[0];
  jamp[3] -= amp[0];
  jamp[4] += amp[0];
  jamp[11] += amp[0];
  jamp[15] -= amp[0];
  jamp[17] += amp[0];
  jamp[21] -= amp[0];
  jamp[35] += amp[0];
  jamp[39] -= amp[0];
  jamp[41] += amp[0];
  jamp[45] -= amp[0];
  jamp[71] -= amp[0];
  jamp[89] += amp[0];
  jamp[95] -= amp[0];
  jamp[113] += amp[0];
  VVV1_0( w[1], w[32], w[56], COUPs[0], &amp[0] );
  jamp[0] -= amp[0];
  jamp[2] += amp[0];
  jamp[4] += amp[0];
  jamp[5] -= amp[0];
  jamp[9] += amp[0];
  jamp[15] -= amp[0];
  jamp[21] -= amp[0];
  jamp[23] += amp[0];
  jamp[33] += amp[0];
  jamp[39] -= amp[0];
  jamp[45] -= amp[0];
  jamp[47] += amp[0];
  jamp[65] -= amp[0];
  jamp[89] += amp[0];
  jamp[113] += amp[0];
  jamp[119] -= amp[0];

  // *** DIAGRAM 1045 OF 1240 ***

  // Wavefunction(s) for diagram number 1045
  // (none)

  // Amplitude(s) for diagram number 1045
  VVV1_0( w[1], w[8], w[92], COUPs[0], &amp[0] );
  jamp[9] -= amp[0];
  jamp[11] += amp[0];
  jamp[17] += amp[0];
  jamp[23] -= amp[0];
  jamp[24] += amp[0];
  jamp[25] -= amp[0];
  jamp[27] -= amp[0];
  jamp[29] += amp[0];
  jamp[33] -= amp[0];
  jamp[35] += amp[0];
  jamp[41] += amp[0];
  jamp[47] -= amp[0];
  jamp[64] += amp[0];
  jamp[70] -= amp[0];
  jamp[94] -= amp[0];
  jamp[118] += amp[0];
  VVV1_0( w[1], w[8], w[88], COUPs[0], &amp[0] );
  jamp[11] += amp[0];
  jamp[15] -= amp[0];
  jamp[17] += amp[0];
  jamp[21] -= amp[0];
  jamp[25] -= amp[0];
  jamp[26] += amp[0];
  jamp[27] -= amp[0];
  jamp[28] += amp[0];
  jamp[35] += amp[0];
  jamp[39] -= amp[0];
  jamp[41] += amp[0];
  jamp[45] -= amp[0];
  jamp[70] -= amp[0];
  jamp[88] += amp[0];
  jamp[94] -= amp[0];
  jamp[112] += amp[0];
  VVV1_0( w[1], w[8], w[106], COUPs[0], &amp[0] );
  jamp[9] += amp[0];
  jamp[15] -= amp[0];
  jamp[21] -= amp[0];
  jamp[23] += amp[0];
  jamp[24] -= amp[0];
  jamp[26] += amp[0];
  jamp[28] += amp[0];
  jamp[29] -= amp[0];
  jamp[33] += amp[0];
  jamp[39] -= amp[0];
  jamp[45] -= amp[0];
  jamp[47] += amp[0];
  jamp[64] -= amp[0];
  jamp[88] += amp[0];
  jamp[112] += amp[0];
  jamp[118] -= amp[0];

  // *** DIAGRAM 1046 OF 1240 ***

  // Wavefunction(s) for diagram number 1046
  // (none)

  // Amplitude(s) for diagram number 1046
  FFV1_0( w[58], w[114], w[6], COUPs[1], &amp[0] );
#ifdef MGONGPU_SUPPORTS_MULTICHANNEL
  if( channelId == 1046 ) allNumerators[0] += cxabs2( amp[0] );
  if( channelId != 0 ) allDenominators[0] += cxabs2( amp[0] );
#endif
  jamp[52] -= amp[0];

  // *** DIAGRAM 1047 OF 1240 ***

  // Wavefunction(s) for diagram number 1047
  // (none)

  // Amplitude(s) for diagram number 1047
  FFV1_0( w[48], w[114], w[1], COUPs[1], &amp[0] );
#ifdef MGONGPU_SUPPORTS_MULTICHANNEL
  if( channelId == 1047 ) allNumerators[0] += cxabs2( amp[0] );
  if( channelId != 0 ) allDenominators[0] += cxabs2( amp[0] );
#endif
  jamp[49] -= amp[0];

  // *** DIAGRAM 1048 OF 1240 ***

  // Wavefunction(s) for diagram number 1048
  // (none)

  // Amplitude(s) for diagram number 1048
  FFV1_0( w[104], w[100], w[6], COUPs[1], &amp[0] );
#ifdef MGONGPU_SUPPORTS_MULTICHANNEL
  if( channelId == 1048 ) allNumerators[0] += cxabs2( amp[0] );
  if( channelId != 0 ) allDenominators[0] += cxabs2( amp[0] );
#endif
  jamp[58] -= amp[0];

  // *** DIAGRAM 1049 OF 1240 ***

  // Wavefunction(s) for diagram number 1049
  // (none)

  // Amplitude(s) for diagram number 1049
  FFV1_0( w[104], w[36], w[1], COUPs[1], &amp[0] );
#ifdef MGONGPU_SUPPORTS_MULTICHANNEL
  if( channelId == 1049 ) allNumerators[0] += cxabs2( amp[0] );
  if( channelId != 0 ) allDenominators[0] += cxabs2( amp[0] );
#endif
  jamp[68] -= amp[0];

  // *** DIAGRAM 1050 OF 1240 ***

  // Wavefunction(s) for diagram number 1050
  // (none)

  // Amplitude(s) for diagram number 1050
  FFV1_0( w[48], w[100], w[0], COUPs[1], &amp[0] );
#ifdef MGONGPU_SUPPORTS_MULTICHANNEL
  if( channelId == 1050 ) allNumerators[0] += cxabs2( amp[0] );
  if( channelId != 0 ) allDenominators[0] += cxabs2( amp[0] );
#endif
  jamp[55] -= amp[0];

  // *** DIAGRAM 1051 OF 1240 ***

  // Wavefunction(s) for diagram number 1051
  // (none)

  // Amplitude(s) for diagram number 1051
  FFV1_0( w[58], w[36], w[0], COUPs[1], &amp[0] );
#ifdef MGONGPU_SUPPORTS_MULTICHANNEL
  if( channelId == 1051 ) allNumerators[0] += cxabs2( amp[0] );
  if( channelId != 0 ) allDenominators[0] += cxabs2( amp[0] );
#endif
  jamp[66] -= amp[0];

  // *** DIAGRAM 1052 OF 1240 ***

  // Wavefunction(s) for diagram number 1052
  // (none)

  // Amplitude(s) for diagram number 1052
  FFV1_0( w[60], w[114], w[5], COUPs[1], &amp[0] );
#ifdef MGONGPU_SUPPORTS_MULTICHANNEL
  if( channelId == 1052 ) allNumerators[0] += cxabs2( amp[0] );
  if( channelId != 0 ) allDenominators[0] += cxabs2( amp[0] );
#endif
  jamp[50] -= amp[0];

  // *** DIAGRAM 1053 OF 1240 ***

  // Wavefunction(s) for diagram number 1053
  // (none)

  // Amplitude(s) for diagram number 1053
  FFV1_0( w[40], w[114], w[1], COUPs[1], &amp[0] );
#ifdef MGONGPU_SUPPORTS_MULTICHANNEL
  if( channelId == 1053 ) allNumerators[0] += cxabs2( amp[0] );
  if( channelId != 0 ) allDenominators[0] += cxabs2( amp[0] );
#endif
  jamp[48] -= amp[0];

  // *** DIAGRAM 1054 OF 1240 ***

  // Wavefunction(s) for diagram number 1054
  // (none)

  // Amplitude(s) for diagram number 1054
  FFV1_0( w[62], w[100], w[5], COUPs[1], &amp[0] );
#ifdef MGONGPU_SUPPORTS_MULTICHANNEL
  if( channelId == 1054 ) allNumerators[0] += cxabs2( amp[0] );
  if( channelId != 0 ) allDenominators[0] += cxabs2( amp[0] );
#endif
  jamp[56] -= amp[0];

  // *** DIAGRAM 1055 OF 1240 ***

  // Wavefunction(s) for diagram number 1055
  // (none)

  // Amplitude(s) for diagram number 1055
  FFV1_0( w[62], w[35], w[1], COUPs[1], &amp[0] );
#ifdef MGONGPU_SUPPORTS_MULTICHANNEL
  if( channelId == 1055 ) allNumerators[0] += cxabs2( amp[0] );
  if( channelId != 0 ) allDenominators[0] += cxabs2( amp[0] );
#endif
  jamp[62] -= amp[0];

  // *** DIAGRAM 1056 OF 1240 ***

  // Wavefunction(s) for diagram number 1056
  // (none)

  // Amplitude(s) for diagram number 1056
  FFV1_0( w[40], w[100], w[0], COUPs[1], &amp[0] );
#ifdef MGONGPU_SUPPORTS_MULTICHANNEL
  if( channelId == 1056 ) allNumerators[0] += cxabs2( amp[0] );
  if( channelId != 0 ) allDenominators[0] += cxabs2( amp[0] );
#endif
  jamp[54] -= amp[0];

  // *** DIAGRAM 1057 OF 1240 ***

  // Wavefunction(s) for diagram number 1057
  // (none)

  // Amplitude(s) for diagram number 1057
  FFV1_0( w[60], w[35], w[0], COUPs[1], &amp[0] );
#ifdef MGONGPU_SUPPORTS_MULTICHANNEL
  if( channelId == 1057 ) allNumerators[0] += cxabs2( amp[0] );
  if( channelId != 0 ) allDenominators[0] += cxabs2( amp[0] );
#endif
  jamp[60] -= amp[0];

  // *** DIAGRAM 1058 OF 1240 ***

  // Wavefunction(s) for diagram number 1058
  // (none)

  // Amplitude(s) for diagram number 1058
  FFV1_0( w[3], w[114], w[67], COUPs[1], &amp[0] );
#ifdef MGONGPU_SUPPORTS_MULTICHANNEL
  if( channelId == 1058 ) allNumerators[0] += cxabs2( amp[0] );
  if( channelId != 0 ) allDenominators[0] += cxabs2( amp[0] );
#endif
  jamp[48] += amp[0];
  jamp[49] -= amp[0];
  jamp[51] -= amp[0];
  jamp[53] += amp[0];

  // *** DIAGRAM 1059 OF 1240 ***

  // Wavefunction(s) for diagram number 1059
  // (none)

  // Amplitude(s) for diagram number 1059
  FFV1_0( w[12], w[114], w[1], COUPs[1], &amp[0] );
#ifdef MGONGPU_SUPPORTS_MULTICHANNEL
  if( channelId == 1059 ) allNumerators[0] += cxabs2( amp[0] );
  if( channelId != 0 ) allDenominators[0] += cxabs2( amp[0] );
#endif
  jamp[48] += cxtype( 0, 1 ) * amp[0];
  jamp[49] -= cxtype( 0, 1 ) * amp[0];

  // *** DIAGRAM 1060 OF 1240 ***

  // Wavefunction(s) for diagram number 1060
  // (none)

  // Amplitude(s) for diagram number 1060
  FFV1_0( w[3], w[100], w[96], COUPs[1], &amp[0] );
#ifdef MGONGPU_SUPPORTS_MULTICHANNEL
  if( channelId == 1060 ) allNumerators[0] += cxabs2( amp[0] );
  if( channelId != 0 ) allDenominators[0] += cxabs2( amp[0] );
#endif
  jamp[54] += amp[0];
  jamp[55] -= amp[0];
  jamp[57] -= amp[0];
  jamp[59] += amp[0];

  // *** DIAGRAM 1061 OF 1240 ***

  // Wavefunction(s) for diagram number 1061
  // (none)

  // Amplitude(s) for diagram number 1061
  VVV1_0( w[96], w[1], w[37], COUPs[0], &amp[0] );
#ifdef MGONGPU_SUPPORTS_MULTICHANNEL
  if( channelId == 1061 ) allNumerators[0] += cxabs2( amp[0] );
  if( channelId != 0 ) allDenominators[0] += cxabs2( amp[0] );
#endif
  jamp[51] -= cxtype( 0, 1 ) * amp[0];
  jamp[53] += cxtype( 0, 1 ) * amp[0];
  jamp[54] += cxtype( 0, 1 ) * amp[0];
  jamp[55] -= cxtype( 0, 1 ) * amp[0];
  jamp[57] -= cxtype( 0, 1 ) * amp[0];
  jamp[59] += cxtype( 0, 1 ) * amp[0];
  jamp[64] += cxtype( 0, 1 ) * amp[0];
  jamp[70] -= cxtype( 0, 1 ) * amp[0];

  // *** DIAGRAM 1062 OF 1240 ***

  // Wavefunction(s) for diagram number 1062
  // (none)

  // Amplitude(s) for diagram number 1062
  FFV1_0( w[12], w[100], w[0], COUPs[1], &amp[0] );
#ifdef MGONGPU_SUPPORTS_MULTICHANNEL
  if( channelId == 1062 ) allNumerators[0] += cxabs2( amp[0] );
  if( channelId != 0 ) allDenominators[0] += cxabs2( amp[0] );
#endif
  jamp[54] += cxtype( 0, 1 ) * amp[0];
  jamp[55] -= cxtype( 0, 1 ) * amp[0];

  // *** DIAGRAM 1063 OF 1240 ***

  // Wavefunction(s) for diagram number 1063
  // (none)

  // Amplitude(s) for diagram number 1063
  VVV1_0( w[0], w[67], w[37], COUPs[0], &amp[0] );
#ifdef MGONGPU_SUPPORTS_MULTICHANNEL
  if( channelId == 1063 ) allNumerators[0] += cxabs2( amp[0] );
  if( channelId != 0 ) allDenominators[0] += cxabs2( amp[0] );
#endif
  jamp[48] -= cxtype( 0, 1 ) * amp[0];
  jamp[49] += cxtype( 0, 1 ) * amp[0];
  jamp[51] += cxtype( 0, 1 ) * amp[0];
  jamp[53] -= cxtype( 0, 1 ) * amp[0];
  jamp[57] += cxtype( 0, 1 ) * amp[0];
  jamp[59] -= cxtype( 0, 1 ) * amp[0];
  jamp[65] -= cxtype( 0, 1 ) * amp[0];
  jamp[71] += cxtype( 0, 1 ) * amp[0];

  // *** DIAGRAM 1064 OF 1240 ***

  // Wavefunction(s) for diagram number 1064
  // (none)

  // Amplitude(s) for diagram number 1064
  FFV1_0( w[3], w[33], w[76], COUPs[1], &amp[0] );
  jamp[48] -= cxtype( 0, 1 ) * amp[0];
  jamp[49] += cxtype( 0, 1 ) * amp[0];
  jamp[51] += cxtype( 0, 1 ) * amp[0];
  jamp[53] -= cxtype( 0, 1 ) * amp[0];
  jamp[57] += cxtype( 0, 1 ) * amp[0];
  jamp[59] -= cxtype( 0, 1 ) * amp[0];
  jamp[65] -= cxtype( 0, 1 ) * amp[0];
  jamp[71] += cxtype( 0, 1 ) * amp[0];
  FFV1_0( w[3], w[33], w[42], COUPs[1], &amp[0] );
  jamp[51] += cxtype( 0, 1 ) * amp[0];
  jamp[53] -= cxtype( 0, 1 ) * amp[0];
  jamp[54] -= cxtype( 0, 1 ) * amp[0];
  jamp[55] += cxtype( 0, 1 ) * amp[0];
  jamp[57] += cxtype( 0, 1 ) * amp[0];
  jamp[59] -= cxtype( 0, 1 ) * amp[0];
  jamp[64] -= cxtype( 0, 1 ) * amp[0];
  jamp[70] += cxtype( 0, 1 ) * amp[0];
  FFV1_0( w[3], w[33], w[11], COUPs[1], &amp[0] );
  jamp[48] += cxtype( 0, 1 ) * amp[0];
  jamp[49] -= cxtype( 0, 1 ) * amp[0];
  jamp[54] -= cxtype( 0, 1 ) * amp[0];
  jamp[55] += cxtype( 0, 1 ) * amp[0];
  jamp[64] -= cxtype( 0, 1 ) * amp[0];
  jamp[65] += cxtype( 0, 1 ) * amp[0];
  jamp[70] += cxtype( 0, 1 ) * amp[0];
  jamp[71] -= cxtype( 0, 1 ) * amp[0];

  // *** DIAGRAM 1065 OF 1240 ***

  // Wavefunction(s) for diagram number 1065
  // (none)

  // Amplitude(s) for diagram number 1065
  FFV1_0( w[78], w[102], w[6], COUPs[1], &amp[0] );
#ifdef MGONGPU_SUPPORTS_MULTICHANNEL
  if( channelId == 1065 ) allNumerators[0] += cxabs2( amp[0] );
  if( channelId != 0 ) allDenominators[0] += cxabs2( amp[0] );
#endif
  jamp[76] -= amp[0];

  // *** DIAGRAM 1066 OF 1240 ***

  // Wavefunction(s) for diagram number 1066
  // (none)

  // Amplitude(s) for diagram number 1066
  FFV1_0( w[53], w[102], w[1], COUPs[1], &amp[0] );
#ifdef MGONGPU_SUPPORTS_MULTICHANNEL
  if( channelId == 1066 ) allNumerators[0] += cxabs2( amp[0] );
  if( channelId != 0 ) allDenominators[0] += cxabs2( amp[0] );
#endif
  jamp[73] -= amp[0];

  // *** DIAGRAM 1067 OF 1240 ***

  // Wavefunction(s) for diagram number 1067
  // (none)

  // Amplitude(s) for diagram number 1067
  FFV1_0( w[99], w[89], w[6], COUPs[1], &amp[0] );
#ifdef MGONGPU_SUPPORTS_MULTICHANNEL
  if( channelId == 1067 ) allNumerators[0] += cxabs2( amp[0] );
  if( channelId != 0 ) allDenominators[0] += cxabs2( amp[0] );
#endif
  jamp[82] -= amp[0];

  // *** DIAGRAM 1068 OF 1240 ***

  // Wavefunction(s) for diagram number 1068
  // (none)

  // Amplitude(s) for diagram number 1068
  FFV1_0( w[99], w[44], w[1], COUPs[1], &amp[0] );
#ifdef MGONGPU_SUPPORTS_MULTICHANNEL
  if( channelId == 1068 ) allNumerators[0] += cxabs2( amp[0] );
  if( channelId != 0 ) allDenominators[0] += cxabs2( amp[0] );
#endif
  jamp[92] -= amp[0];

  // *** DIAGRAM 1069 OF 1240 ***

  // Wavefunction(s) for diagram number 1069
  // (none)

  // Amplitude(s) for diagram number 1069
  FFV1_0( w[53], w[89], w[0], COUPs[1], &amp[0] );
#ifdef MGONGPU_SUPPORTS_MULTICHANNEL
  if( channelId == 1069 ) allNumerators[0] += cxabs2( amp[0] );
  if( channelId != 0 ) allDenominators[0] += cxabs2( amp[0] );
#endif
  jamp[79] -= amp[0];

  // *** DIAGRAM 1070 OF 1240 ***

  // Wavefunction(s) for diagram number 1070
  // (none)

  // Amplitude(s) for diagram number 1070
  FFV1_0( w[78], w[44], w[0], COUPs[1], &amp[0] );
#ifdef MGONGPU_SUPPORTS_MULTICHANNEL
  if( channelId == 1070 ) allNumerators[0] += cxabs2( amp[0] );
  if( channelId != 0 ) allDenominators[0] += cxabs2( amp[0] );
#endif
  jamp[90] -= amp[0];

  // *** DIAGRAM 1071 OF 1240 ***

  // Wavefunction(s) for diagram number 1071
  // (none)

  // Amplitude(s) for diagram number 1071
  FFV1_0( w[60], w[102], w[4], COUPs[1], &amp[0] );
#ifdef MGONGPU_SUPPORTS_MULTICHANNEL
  if( channelId == 1071 ) allNumerators[0] += cxabs2( amp[0] );
  if( channelId != 0 ) allDenominators[0] += cxabs2( amp[0] );
#endif
  jamp[74] -= amp[0];

  // *** DIAGRAM 1072 OF 1240 ***

  // Wavefunction(s) for diagram number 1072
  // (none)

  // Amplitude(s) for diagram number 1072
  FFV1_0( w[28], w[102], w[1], COUPs[1], &amp[0] );
#ifdef MGONGPU_SUPPORTS_MULTICHANNEL
  if( channelId == 1072 ) allNumerators[0] += cxabs2( amp[0] );
  if( channelId != 0 ) allDenominators[0] += cxabs2( amp[0] );
#endif
  jamp[72] -= amp[0];

  // *** DIAGRAM 1073 OF 1240 ***

  // Wavefunction(s) for diagram number 1073
  // (none)

  // Amplitude(s) for diagram number 1073
  FFV1_0( w[62], w[89], w[4], COUPs[1], &amp[0] );
#ifdef MGONGPU_SUPPORTS_MULTICHANNEL
  if( channelId == 1073 ) allNumerators[0] += cxabs2( amp[0] );
  if( channelId != 0 ) allDenominators[0] += cxabs2( amp[0] );
#endif
  jamp[80] -= amp[0];

  // *** DIAGRAM 1074 OF 1240 ***

  // Wavefunction(s) for diagram number 1074
  // (none)

  // Amplitude(s) for diagram number 1074
  FFV1_0( w[62], w[43], w[1], COUPs[1], &amp[0] );
#ifdef MGONGPU_SUPPORTS_MULTICHANNEL
  if( channelId == 1074 ) allNumerators[0] += cxabs2( amp[0] );
  if( channelId != 0 ) allDenominators[0] += cxabs2( amp[0] );
#endif
  jamp[86] -= amp[0];

  // *** DIAGRAM 1075 OF 1240 ***

  // Wavefunction(s) for diagram number 1075
  // (none)

  // Amplitude(s) for diagram number 1075
  FFV1_0( w[28], w[89], w[0], COUPs[1], &amp[0] );
#ifdef MGONGPU_SUPPORTS_MULTICHANNEL
  if( channelId == 1075 ) allNumerators[0] += cxabs2( amp[0] );
  if( channelId != 0 ) allDenominators[0] += cxabs2( amp[0] );
#endif
  jamp[78] -= amp[0];

  // *** DIAGRAM 1076 OF 1240 ***

  // Wavefunction(s) for diagram number 1076
  // (none)

  // Amplitude(s) for diagram number 1076
  FFV1_0( w[60], w[43], w[0], COUPs[1], &amp[0] );
#ifdef MGONGPU_SUPPORTS_MULTICHANNEL
  if( channelId == 1076 ) allNumerators[0] += cxabs2( amp[0] );
  if( channelId != 0 ) allDenominators[0] += cxabs2( amp[0] );
#endif
  jamp[84] -= amp[0];

  // *** DIAGRAM 1077 OF 1240 ***

  // Wavefunction(s) for diagram number 1077
  // (none)

  // Amplitude(s) for diagram number 1077
  FFV1_0( w[3], w[102], w[68], COUPs[1], &amp[0] );
#ifdef MGONGPU_SUPPORTS_MULTICHANNEL
  if( channelId == 1077 ) allNumerators[0] += cxabs2( amp[0] );
  if( channelId != 0 ) allDenominators[0] += cxabs2( amp[0] );
#endif
  jamp[72] += amp[0];
  jamp[73] -= amp[0];
  jamp[75] -= amp[0];
  jamp[77] += amp[0];

  // *** DIAGRAM 1078 OF 1240 ***

  // Wavefunction(s) for diagram number 1078
  // (none)

  // Amplitude(s) for diagram number 1078
  FFV1_0( w[14], w[102], w[1], COUPs[1], &amp[0] );
#ifdef MGONGPU_SUPPORTS_MULTICHANNEL
  if( channelId == 1078 ) allNumerators[0] += cxabs2( amp[0] );
  if( channelId != 0 ) allDenominators[0] += cxabs2( amp[0] );
#endif
  jamp[72] += cxtype( 0, 1 ) * amp[0];
  jamp[73] -= cxtype( 0, 1 ) * amp[0];

  // *** DIAGRAM 1079 OF 1240 ***

  // Wavefunction(s) for diagram number 1079
  // (none)

  // Amplitude(s) for diagram number 1079
  FFV1_0( w[3], w[89], w[101], COUPs[1], &amp[0] );
#ifdef MGONGPU_SUPPORTS_MULTICHANNEL
  if( channelId == 1079 ) allNumerators[0] += cxabs2( amp[0] );
  if( channelId != 0 ) allDenominators[0] += cxabs2( amp[0] );
#endif
  jamp[78] += amp[0];
  jamp[79] -= amp[0];
  jamp[81] -= amp[0];
  jamp[83] += amp[0];

  // *** DIAGRAM 1080 OF 1240 ***

  // Wavefunction(s) for diagram number 1080
  // (none)

  // Amplitude(s) for diagram number 1080
  VVV1_0( w[101], w[1], w[45], COUPs[0], &amp[0] );
#ifdef MGONGPU_SUPPORTS_MULTICHANNEL
  if( channelId == 1080 ) allNumerators[0] += cxabs2( amp[0] );
  if( channelId != 0 ) allDenominators[0] += cxabs2( amp[0] );
#endif
  jamp[75] -= cxtype( 0, 1 ) * amp[0];
  jamp[77] += cxtype( 0, 1 ) * amp[0];
  jamp[78] += cxtype( 0, 1 ) * amp[0];
  jamp[79] -= cxtype( 0, 1 ) * amp[0];
  jamp[81] -= cxtype( 0, 1 ) * amp[0];
  jamp[83] += cxtype( 0, 1 ) * amp[0];
  jamp[88] += cxtype( 0, 1 ) * amp[0];
  jamp[94] -= cxtype( 0, 1 ) * amp[0];

  // *** DIAGRAM 1081 OF 1240 ***

  // Wavefunction(s) for diagram number 1081
  // (none)

  // Amplitude(s) for diagram number 1081
  FFV1_0( w[14], w[89], w[0], COUPs[1], &amp[0] );
#ifdef MGONGPU_SUPPORTS_MULTICHANNEL
  if( channelId == 1081 ) allNumerators[0] += cxabs2( amp[0] );
  if( channelId != 0 ) allDenominators[0] += cxabs2( amp[0] );
#endif
  jamp[78] += cxtype( 0, 1 ) * amp[0];
  jamp[79] -= cxtype( 0, 1 ) * amp[0];

  // *** DIAGRAM 1082 OF 1240 ***

  // Wavefunction(s) for diagram number 1082
  // (none)

  // Amplitude(s) for diagram number 1082
  VVV1_0( w[0], w[68], w[45], COUPs[0], &amp[0] );
#ifdef MGONGPU_SUPPORTS_MULTICHANNEL
  if( channelId == 1082 ) allNumerators[0] += cxabs2( amp[0] );
  if( channelId != 0 ) allDenominators[0] += cxabs2( amp[0] );
#endif
  jamp[72] -= cxtype( 0, 1 ) * amp[0];
  jamp[73] += cxtype( 0, 1 ) * amp[0];
  jamp[75] += cxtype( 0, 1 ) * amp[0];
  jamp[77] -= cxtype( 0, 1 ) * amp[0];
  jamp[81] += cxtype( 0, 1 ) * amp[0];
  jamp[83] -= cxtype( 0, 1 ) * amp[0];
  jamp[89] -= cxtype( 0, 1 ) * amp[0];
  jamp[95] += cxtype( 0, 1 ) * amp[0];

  // *** DIAGRAM 1083 OF 1240 ***

  // Wavefunction(s) for diagram number 1083
  // (none)

  // Amplitude(s) for diagram number 1083
  FFV1_0( w[3], w[39], w[10], COUPs[1], &amp[0] );
  jamp[72] -= cxtype( 0, 1 ) * amp[0];
  jamp[73] += cxtype( 0, 1 ) * amp[0];
  jamp[75] += cxtype( 0, 1 ) * amp[0];
  jamp[77] -= cxtype( 0, 1 ) * amp[0];
  jamp[81] += cxtype( 0, 1 ) * amp[0];
  jamp[83] -= cxtype( 0, 1 ) * amp[0];
  jamp[89] -= cxtype( 0, 1 ) * amp[0];
  jamp[95] += cxtype( 0, 1 ) * amp[0];
  FFV1_0( w[3], w[39], w[16], COUPs[1], &amp[0] );
  jamp[75] += cxtype( 0, 1 ) * amp[0];
  jamp[77] -= cxtype( 0, 1 ) * amp[0];
  jamp[78] -= cxtype( 0, 1 ) * amp[0];
  jamp[79] += cxtype( 0, 1 ) * amp[0];
  jamp[81] += cxtype( 0, 1 ) * amp[0];
  jamp[83] -= cxtype( 0, 1 ) * amp[0];
  jamp[88] -= cxtype( 0, 1 ) * amp[0];
  jamp[94] += cxtype( 0, 1 ) * amp[0];
  FFV1_0( w[3], w[39], w[111], COUPs[1], &amp[0] );
  jamp[72] += cxtype( 0, 1 ) * amp[0];
  jamp[73] -= cxtype( 0, 1 ) * amp[0];
  jamp[78] -= cxtype( 0, 1 ) * amp[0];
  jamp[79] += cxtype( 0, 1 ) * amp[0];
  jamp[88] -= cxtype( 0, 1 ) * amp[0];
  jamp[89] += cxtype( 0, 1 ) * amp[0];
  jamp[94] += cxtype( 0, 1 ) * amp[0];
  jamp[95] -= cxtype( 0, 1 ) * amp[0];

  // *** DIAGRAM 1084 OF 1240 ***

  // Wavefunction(s) for diagram number 1084
  // (none)

  // Amplitude(s) for diagram number 1084
  FFV1_0( w[78], w[113], w[5], COUPs[1], &amp[0] );
#ifdef MGONGPU_SUPPORTS_MULTICHANNEL
  if( channelId == 1084 ) allNumerators[0] += cxabs2( amp[0] );
  if( channelId != 0 ) allDenominators[0] += cxabs2( amp[0] );
#endif
  jamp[100] -= amp[0];

  // *** DIAGRAM 1085 OF 1240 ***

  // Wavefunction(s) for diagram number 1085
  // (none)

  // Amplitude(s) for diagram number 1085
  FFV1_0( w[7], w[113], w[1], COUPs[1], &amp[0] );
#ifdef MGONGPU_SUPPORTS_MULTICHANNEL
  if( channelId == 1085 ) allNumerators[0] += cxabs2( amp[0] );
  if( channelId != 0 ) allDenominators[0] += cxabs2( amp[0] );
#endif
  jamp[97] -= amp[0];

  // *** DIAGRAM 1086 OF 1240 ***

  // Wavefunction(s) for diagram number 1086
  // (none)

  // Amplitude(s) for diagram number 1086
  FFV1_0( w[99], w[91], w[5], COUPs[1], &amp[0] );
#ifdef MGONGPU_SUPPORTS_MULTICHANNEL
  if( channelId == 1086 ) allNumerators[0] += cxabs2( amp[0] );
  if( channelId != 0 ) allDenominators[0] += cxabs2( amp[0] );
#endif
  jamp[106] -= amp[0];

  // *** DIAGRAM 1087 OF 1240 ***

  // Wavefunction(s) for diagram number 1087
  // (none)

  // Amplitude(s) for diagram number 1087
  FFV1_0( w[99], w[50], w[1], COUPs[1], &amp[0] );
#ifdef MGONGPU_SUPPORTS_MULTICHANNEL
  if( channelId == 1087 ) allNumerators[0] += cxabs2( amp[0] );
  if( channelId != 0 ) allDenominators[0] += cxabs2( amp[0] );
#endif
  jamp[116] -= amp[0];

  // *** DIAGRAM 1088 OF 1240 ***

  // Wavefunction(s) for diagram number 1088
  // (none)

  // Amplitude(s) for diagram number 1088
  FFV1_0( w[7], w[91], w[0], COUPs[1], &amp[0] );
#ifdef MGONGPU_SUPPORTS_MULTICHANNEL
  if( channelId == 1088 ) allNumerators[0] += cxabs2( amp[0] );
  if( channelId != 0 ) allDenominators[0] += cxabs2( amp[0] );
#endif
  jamp[103] -= amp[0];

  // *** DIAGRAM 1089 OF 1240 ***

  // Wavefunction(s) for diagram number 1089
  // (none)

  // Amplitude(s) for diagram number 1089
  FFV1_0( w[78], w[50], w[0], COUPs[1], &amp[0] );
#ifdef MGONGPU_SUPPORTS_MULTICHANNEL
  if( channelId == 1089 ) allNumerators[0] += cxabs2( amp[0] );
  if( channelId != 0 ) allDenominators[0] += cxabs2( amp[0] );
#endif
  jamp[114] -= amp[0];

  // *** DIAGRAM 1090 OF 1240 ***

  // Wavefunction(s) for diagram number 1090
  // (none)

  // Amplitude(s) for diagram number 1090
  FFV1_0( w[58], w[113], w[4], COUPs[1], &amp[0] );
#ifdef MGONGPU_SUPPORTS_MULTICHANNEL
  if( channelId == 1090 ) allNumerators[0] += cxabs2( amp[0] );
  if( channelId != 0 ) allDenominators[0] += cxabs2( amp[0] );
#endif
  jamp[98] -= amp[0];

  // *** DIAGRAM 1091 OF 1240 ***

  // Wavefunction(s) for diagram number 1091
  // (none)

  // Amplitude(s) for diagram number 1091
  FFV1_0( w[25], w[113], w[1], COUPs[1], &amp[0] );
#ifdef MGONGPU_SUPPORTS_MULTICHANNEL
  if( channelId == 1091 ) allNumerators[0] += cxabs2( amp[0] );
  if( channelId != 0 ) allDenominators[0] += cxabs2( amp[0] );
#endif
  jamp[96] -= amp[0];

  // *** DIAGRAM 1092 OF 1240 ***

  // Wavefunction(s) for diagram number 1092
  // (none)

  // Amplitude(s) for diagram number 1092
  FFV1_0( w[104], w[91], w[4], COUPs[1], &amp[0] );
#ifdef MGONGPU_SUPPORTS_MULTICHANNEL
  if( channelId == 1092 ) allNumerators[0] += cxabs2( amp[0] );
  if( channelId != 0 ) allDenominators[0] += cxabs2( amp[0] );
#endif
  jamp[104] -= amp[0];

  // *** DIAGRAM 1093 OF 1240 ***

  // Wavefunction(s) for diagram number 1093
  // (none)

  // Amplitude(s) for diagram number 1093
  FFV1_0( w[104], w[49], w[1], COUPs[1], &amp[0] );
#ifdef MGONGPU_SUPPORTS_MULTICHANNEL
  if( channelId == 1093 ) allNumerators[0] += cxabs2( amp[0] );
  if( channelId != 0 ) allDenominators[0] += cxabs2( amp[0] );
#endif
  jamp[110] -= amp[0];

  // *** DIAGRAM 1094 OF 1240 ***

  // Wavefunction(s) for diagram number 1094
  // (none)

  // Amplitude(s) for diagram number 1094
  FFV1_0( w[25], w[91], w[0], COUPs[1], &amp[0] );
#ifdef MGONGPU_SUPPORTS_MULTICHANNEL
  if( channelId == 1094 ) allNumerators[0] += cxabs2( amp[0] );
  if( channelId != 0 ) allDenominators[0] += cxabs2( amp[0] );
#endif
  jamp[102] -= amp[0];

  // *** DIAGRAM 1095 OF 1240 ***

  // Wavefunction(s) for diagram number 1095
  // (none)

  // Amplitude(s) for diagram number 1095
  FFV1_0( w[58], w[49], w[0], COUPs[1], &amp[0] );
#ifdef MGONGPU_SUPPORTS_MULTICHANNEL
  if( channelId == 1095 ) allNumerators[0] += cxabs2( amp[0] );
  if( channelId != 0 ) allDenominators[0] += cxabs2( amp[0] );
#endif
  jamp[108] -= amp[0];

  // *** DIAGRAM 1096 OF 1240 ***

  // Wavefunction(s) for diagram number 1096
  // (none)

  // Amplitude(s) for diagram number 1096
  FFV1_0( w[3], w[113], w[59], COUPs[1], &amp[0] );
#ifdef MGONGPU_SUPPORTS_MULTICHANNEL
  if( channelId == 1096 ) allNumerators[0] += cxabs2( amp[0] );
  if( channelId != 0 ) allDenominators[0] += cxabs2( amp[0] );
#endif
  jamp[96] += amp[0];
  jamp[97] -= amp[0];
  jamp[99] -= amp[0];
  jamp[101] += amp[0];

  // *** DIAGRAM 1097 OF 1240 ***

  // Wavefunction(s) for diagram number 1097
  // (none)

  // Amplitude(s) for diagram number 1097
  FFV1_0( w[26], w[113], w[1], COUPs[1], &amp[0] );
#ifdef MGONGPU_SUPPORTS_MULTICHANNEL
  if( channelId == 1097 ) allNumerators[0] += cxabs2( amp[0] );
  if( channelId != 0 ) allDenominators[0] += cxabs2( amp[0] );
#endif
  jamp[96] += cxtype( 0, 1 ) * amp[0];
  jamp[97] -= cxtype( 0, 1 ) * amp[0];

  // *** DIAGRAM 1098 OF 1240 ***

  // Wavefunction(s) for diagram number 1098
  // (none)

  // Amplitude(s) for diagram number 1098
  FFV1_0( w[3], w[91], w[98], COUPs[1], &amp[0] );
#ifdef MGONGPU_SUPPORTS_MULTICHANNEL
  if( channelId == 1098 ) allNumerators[0] += cxabs2( amp[0] );
  if( channelId != 0 ) allDenominators[0] += cxabs2( amp[0] );
#endif
  jamp[102] += amp[0];
  jamp[103] -= amp[0];
  jamp[105] -= amp[0];
  jamp[107] += amp[0];

  // *** DIAGRAM 1099 OF 1240 ***

  // Wavefunction(s) for diagram number 1099
  // (none)

  // Amplitude(s) for diagram number 1099
  VVV1_0( w[98], w[1], w[51], COUPs[0], &amp[0] );
#ifdef MGONGPU_SUPPORTS_MULTICHANNEL
  if( channelId == 1099 ) allNumerators[0] += cxabs2( amp[0] );
  if( channelId != 0 ) allDenominators[0] += cxabs2( amp[0] );
#endif
  jamp[99] -= cxtype( 0, 1 ) * amp[0];
  jamp[101] += cxtype( 0, 1 ) * amp[0];
  jamp[102] += cxtype( 0, 1 ) * amp[0];
  jamp[103] -= cxtype( 0, 1 ) * amp[0];
  jamp[105] -= cxtype( 0, 1 ) * amp[0];
  jamp[107] += cxtype( 0, 1 ) * amp[0];
  jamp[112] += cxtype( 0, 1 ) * amp[0];
  jamp[118] -= cxtype( 0, 1 ) * amp[0];

  // *** DIAGRAM 1100 OF 1240 ***

  // Wavefunction(s) for diagram number 1100
  // (none)

  // Amplitude(s) for diagram number 1100
  FFV1_0( w[26], w[91], w[0], COUPs[1], &amp[0] );
#ifdef MGONGPU_SUPPORTS_MULTICHANNEL
  if( channelId == 1100 ) allNumerators[0] += cxabs2( amp[0] );
  if( channelId != 0 ) allDenominators[0] += cxabs2( amp[0] );
#endif
  jamp[102] += cxtype( 0, 1 ) * amp[0];
  jamp[103] -= cxtype( 0, 1 ) * amp[0];

  // *** DIAGRAM 1101 OF 1240 ***

  // Wavefunction(s) for diagram number 1101
  // (none)

  // Amplitude(s) for diagram number 1101
  VVV1_0( w[0], w[59], w[51], COUPs[0], &amp[0] );
#ifdef MGONGPU_SUPPORTS_MULTICHANNEL
  if( channelId == 1101 ) allNumerators[0] += cxabs2( amp[0] );
  if( channelId != 0 ) allDenominators[0] += cxabs2( amp[0] );
#endif
  jamp[96] -= cxtype( 0, 1 ) * amp[0];
  jamp[97] += cxtype( 0, 1 ) * amp[0];
  jamp[99] += cxtype( 0, 1 ) * amp[0];
  jamp[101] -= cxtype( 0, 1 ) * amp[0];
  jamp[105] += cxtype( 0, 1 ) * amp[0];
  jamp[107] -= cxtype( 0, 1 ) * amp[0];
  jamp[113] -= cxtype( 0, 1 ) * amp[0];
  jamp[119] += cxtype( 0, 1 ) * amp[0];

  // *** DIAGRAM 1102 OF 1240 ***

  // Wavefunction(s) for diagram number 1102
  // (none)

  // Amplitude(s) for diagram number 1102
  FFV1_0( w[3], w[47], w[97], COUPs[1], &amp[0] );
  jamp[96] -= cxtype( 0, 1 ) * amp[0];
  jamp[97] += cxtype( 0, 1 ) * amp[0];
  jamp[99] += cxtype( 0, 1 ) * amp[0];
  jamp[101] -= cxtype( 0, 1 ) * amp[0];
  jamp[105] += cxtype( 0, 1 ) * amp[0];
  jamp[107] -= cxtype( 0, 1 ) * amp[0];
  jamp[113] -= cxtype( 0, 1 ) * amp[0];
  jamp[119] += cxtype( 0, 1 ) * amp[0];
  FFV1_0( w[3], w[47], w[71], COUPs[1], &amp[0] );
  jamp[99] += cxtype( 0, 1 ) * amp[0];
  jamp[101] -= cxtype( 0, 1 ) * amp[0];
  jamp[102] -= cxtype( 0, 1 ) * amp[0];
  jamp[103] += cxtype( 0, 1 ) * amp[0];
  jamp[105] += cxtype( 0, 1 ) * amp[0];
  jamp[107] -= cxtype( 0, 1 ) * amp[0];
  jamp[112] -= cxtype( 0, 1 ) * amp[0];
  jamp[118] += cxtype( 0, 1 ) * amp[0];
  FFV1_0( w[3], w[47], w[21], COUPs[1], &amp[0] );
  jamp[96] += cxtype( 0, 1 ) * amp[0];
  jamp[97] -= cxtype( 0, 1 ) * amp[0];
  jamp[102] -= cxtype( 0, 1 ) * amp[0];
  jamp[103] += cxtype( 0, 1 ) * amp[0];
  jamp[112] -= cxtype( 0, 1 ) * amp[0];
  jamp[113] += cxtype( 0, 1 ) * amp[0];
  jamp[118] += cxtype( 0, 1 ) * amp[0];
  jamp[119] -= cxtype( 0, 1 ) * amp[0];

  // *** DIAGRAM 1103 OF 1240 ***

  // Wavefunction(s) for diagram number 1103
  // (none)

  // Amplitude(s) for diagram number 1103
  FFV1_0( w[99], w[2], w[67], COUPs[1], &amp[0] );
#ifdef MGONGPU_SUPPORTS_MULTICHANNEL
  if( channelId == 1103 ) allNumerators[0] += cxabs2( amp[0] );
  if( channelId != 0 ) allDenominators[0] += cxabs2( amp[0] );
#endif
  jamp[40] += amp[0];
  jamp[46] -= amp[0];
  jamp[92] -= amp[0];
  jamp[116] += amp[0];

  // *** DIAGRAM 1104 OF 1240 ***

  // Wavefunction(s) for diagram number 1104
  // (none)

  // Amplitude(s) for diagram number 1104
  FFV1_0( w[99], w[18], w[1], COUPs[1], &amp[0] );
#ifdef MGONGPU_SUPPORTS_MULTICHANNEL
  if( channelId == 1104 ) allNumerators[0] += cxabs2( amp[0] );
  if( channelId != 0 ) allDenominators[0] += cxabs2( amp[0] );
#endif
  jamp[92] += cxtype( 0, 1 ) * amp[0];
  jamp[116] -= cxtype( 0, 1 ) * amp[0];

  // *** DIAGRAM 1105 OF 1240 ***

  // Wavefunction(s) for diagram number 1105
  // (none)

  // Amplitude(s) for diagram number 1105
  FFV1_0( w[78], w[2], w[96], COUPs[1], &amp[0] );
#ifdef MGONGPU_SUPPORTS_MULTICHANNEL
  if( channelId == 1105 ) allNumerators[0] += cxabs2( amp[0] );
  if( channelId != 0 ) allDenominators[0] += cxabs2( amp[0] );
#endif
  jamp[16] += amp[0];
  jamp[22] -= amp[0];
  jamp[90] -= amp[0];
  jamp[114] += amp[0];

  // *** DIAGRAM 1106 OF 1240 ***

  // Wavefunction(s) for diagram number 1106
  // (none)

  // Amplitude(s) for diagram number 1106
  VVV1_0( w[96], w[1], w[54], COUPs[0], &amp[0] );
#ifdef MGONGPU_SUPPORTS_MULTICHANNEL
  if( channelId == 1106 ) allNumerators[0] += cxabs2( amp[0] );
  if( channelId != 0 ) allDenominators[0] += cxabs2( amp[0] );
#endif
  jamp[16] -= cxtype( 0, 1 ) * amp[0];
  jamp[22] += cxtype( 0, 1 ) * amp[0];
  jamp[27] += cxtype( 0, 1 ) * amp[0];
  jamp[29] -= cxtype( 0, 1 ) * amp[0];
  jamp[40] -= cxtype( 0, 1 ) * amp[0];
  jamp[46] += cxtype( 0, 1 ) * amp[0];
  jamp[90] += cxtype( 0, 1 ) * amp[0];
  jamp[114] -= cxtype( 0, 1 ) * amp[0];

  // *** DIAGRAM 1107 OF 1240 ***

  // Wavefunction(s) for diagram number 1107
  // (none)

  // Amplitude(s) for diagram number 1107
  FFV1_0( w[78], w[18], w[0], COUPs[1], &amp[0] );
#ifdef MGONGPU_SUPPORTS_MULTICHANNEL
  if( channelId == 1107 ) allNumerators[0] += cxabs2( amp[0] );
  if( channelId != 0 ) allDenominators[0] += cxabs2( amp[0] );
#endif
  jamp[90] += cxtype( 0, 1 ) * amp[0];
  jamp[114] -= cxtype( 0, 1 ) * amp[0];

  // *** DIAGRAM 1108 OF 1240 ***

  // Wavefunction(s) for diagram number 1108
  // (none)

  // Amplitude(s) for diagram number 1108
  VVV1_0( w[0], w[67], w[54], COUPs[0], &amp[0] );
#ifdef MGONGPU_SUPPORTS_MULTICHANNEL
  if( channelId == 1108 ) allNumerators[0] += cxabs2( amp[0] );
  if( channelId != 0 ) allDenominators[0] += cxabs2( amp[0] );
#endif
  jamp[3] -= cxtype( 0, 1 ) * amp[0];
  jamp[5] += cxtype( 0, 1 ) * amp[0];
  jamp[16] += cxtype( 0, 1 ) * amp[0];
  jamp[22] -= cxtype( 0, 1 ) * amp[0];
  jamp[40] += cxtype( 0, 1 ) * amp[0];
  jamp[46] -= cxtype( 0, 1 ) * amp[0];
  jamp[92] -= cxtype( 0, 1 ) * amp[0];
  jamp[116] += cxtype( 0, 1 ) * amp[0];

  // *** DIAGRAM 1109 OF 1240 ***

  // Wavefunction(s) for diagram number 1109
  // (none)

  // Amplitude(s) for diagram number 1109
  FFV1_0( w[46], w[2], w[76], COUPs[1], &amp[0] );
  jamp[3] -= cxtype( 0, 1 ) * amp[0];
  jamp[5] += cxtype( 0, 1 ) * amp[0];
  jamp[16] += cxtype( 0, 1 ) * amp[0];
  jamp[22] -= cxtype( 0, 1 ) * amp[0];
  jamp[40] += cxtype( 0, 1 ) * amp[0];
  jamp[46] -= cxtype( 0, 1 ) * amp[0];
  jamp[92] -= cxtype( 0, 1 ) * amp[0];
  jamp[116] += cxtype( 0, 1 ) * amp[0];
  FFV1_0( w[46], w[2], w[42], COUPs[1], &amp[0] );
  jamp[16] += cxtype( 0, 1 ) * amp[0];
  jamp[22] -= cxtype( 0, 1 ) * amp[0];
  jamp[27] -= cxtype( 0, 1 ) * amp[0];
  jamp[29] += cxtype( 0, 1 ) * amp[0];
  jamp[40] += cxtype( 0, 1 ) * amp[0];
  jamp[46] -= cxtype( 0, 1 ) * amp[0];
  jamp[90] -= cxtype( 0, 1 ) * amp[0];
  jamp[114] += cxtype( 0, 1 ) * amp[0];
  FFV1_0( w[46], w[2], w[11], COUPs[1], &amp[0] );
  jamp[3] += cxtype( 0, 1 ) * amp[0];
  jamp[5] -= cxtype( 0, 1 ) * amp[0];
  jamp[27] -= cxtype( 0, 1 ) * amp[0];
  jamp[29] += cxtype( 0, 1 ) * amp[0];
  jamp[90] -= cxtype( 0, 1 ) * amp[0];
  jamp[92] += cxtype( 0, 1 ) * amp[0];
  jamp[114] += cxtype( 0, 1 ) * amp[0];
  jamp[116] -= cxtype( 0, 1 ) * amp[0];

  // *** DIAGRAM 1110 OF 1240 ***

  // Wavefunction(s) for diagram number 1110
  // (none)

  // Amplitude(s) for diagram number 1110
  FFV1_0( w[104], w[2], w[68], COUPs[1], &amp[0] );
#ifdef MGONGPU_SUPPORTS_MULTICHANNEL
  if( channelId == 1110 ) allNumerators[0] += cxabs2( amp[0] );
  if( channelId != 0 ) allDenominators[0] += cxabs2( amp[0] );
#endif
  jamp[34] += amp[0];
  jamp[44] -= amp[0];
  jamp[68] -= amp[0];
  jamp[110] += amp[0];

  // *** DIAGRAM 1111 OF 1240 ***

  // Wavefunction(s) for diagram number 1111
  // (none)

  // Amplitude(s) for diagram number 1111
  FFV1_0( w[104], w[15], w[1], COUPs[1], &amp[0] );
#ifdef MGONGPU_SUPPORTS_MULTICHANNEL
  if( channelId == 1111 ) allNumerators[0] += cxabs2( amp[0] );
  if( channelId != 0 ) allDenominators[0] += cxabs2( amp[0] );
#endif
  jamp[68] += cxtype( 0, 1 ) * amp[0];
  jamp[110] -= cxtype( 0, 1 ) * amp[0];

  // *** DIAGRAM 1112 OF 1240 ***

  // Wavefunction(s) for diagram number 1112
  // (none)

  // Amplitude(s) for diagram number 1112
  FFV1_0( w[58], w[2], w[101], COUPs[1], &amp[0] );
#ifdef MGONGPU_SUPPORTS_MULTICHANNEL
  if( channelId == 1112 ) allNumerators[0] += cxabs2( amp[0] );
  if( channelId != 0 ) allDenominators[0] += cxabs2( amp[0] );
#endif
  jamp[10] += amp[0];
  jamp[20] -= amp[0];
  jamp[66] -= amp[0];
  jamp[108] += amp[0];

  // *** DIAGRAM 1113 OF 1240 ***

  // Wavefunction(s) for diagram number 1113
  // (none)

  // Amplitude(s) for diagram number 1113
  VVV1_0( w[101], w[1], w[23], COUPs[0], &amp[0] );
#ifdef MGONGPU_SUPPORTS_MULTICHANNEL
  if( channelId == 1113 ) allNumerators[0] += cxabs2( amp[0] );
  if( channelId != 0 ) allDenominators[0] += cxabs2( amp[0] );
#endif
  jamp[10] -= cxtype( 0, 1 ) * amp[0];
  jamp[20] += cxtype( 0, 1 ) * amp[0];
  jamp[25] += cxtype( 0, 1 ) * amp[0];
  jamp[28] -= cxtype( 0, 1 ) * amp[0];
  jamp[34] -= cxtype( 0, 1 ) * amp[0];
  jamp[44] += cxtype( 0, 1 ) * amp[0];
  jamp[66] += cxtype( 0, 1 ) * amp[0];
  jamp[108] -= cxtype( 0, 1 ) * amp[0];

  // *** DIAGRAM 1114 OF 1240 ***

  // Wavefunction(s) for diagram number 1114
  // (none)

  // Amplitude(s) for diagram number 1114
  FFV1_0( w[58], w[15], w[0], COUPs[1], &amp[0] );
#ifdef MGONGPU_SUPPORTS_MULTICHANNEL
  if( channelId == 1114 ) allNumerators[0] += cxabs2( amp[0] );
  if( channelId != 0 ) allDenominators[0] += cxabs2( amp[0] );
#endif
  jamp[66] += cxtype( 0, 1 ) * amp[0];
  jamp[108] -= cxtype( 0, 1 ) * amp[0];

  // *** DIAGRAM 1115 OF 1240 ***

  // Wavefunction(s) for diagram number 1115
  // (none)

  // Amplitude(s) for diagram number 1115
  VVV1_0( w[0], w[68], w[23], COUPs[0], &amp[0] );
#ifdef MGONGPU_SUPPORTS_MULTICHANNEL
  if( channelId == 1115 ) allNumerators[0] += cxabs2( amp[0] );
  if( channelId != 0 ) allDenominators[0] += cxabs2( amp[0] );
#endif
  jamp[1] -= cxtype( 0, 1 ) * amp[0];
  jamp[4] += cxtype( 0, 1 ) * amp[0];
  jamp[10] += cxtype( 0, 1 ) * amp[0];
  jamp[20] -= cxtype( 0, 1 ) * amp[0];
  jamp[34] += cxtype( 0, 1 ) * amp[0];
  jamp[44] -= cxtype( 0, 1 ) * amp[0];
  jamp[68] -= cxtype( 0, 1 ) * amp[0];
  jamp[110] += cxtype( 0, 1 ) * amp[0];

  // *** DIAGRAM 1116 OF 1240 ***

  // Wavefunction(s) for diagram number 1116
  // (none)

  // Amplitude(s) for diagram number 1116
  FFV1_0( w[38], w[2], w[10], COUPs[1], &amp[0] );
  jamp[1] -= cxtype( 0, 1 ) * amp[0];
  jamp[4] += cxtype( 0, 1 ) * amp[0];
  jamp[10] += cxtype( 0, 1 ) * amp[0];
  jamp[20] -= cxtype( 0, 1 ) * amp[0];
  jamp[34] += cxtype( 0, 1 ) * amp[0];
  jamp[44] -= cxtype( 0, 1 ) * amp[0];
  jamp[68] -= cxtype( 0, 1 ) * amp[0];
  jamp[110] += cxtype( 0, 1 ) * amp[0];
  FFV1_0( w[38], w[2], w[16], COUPs[1], &amp[0] );
  jamp[10] += cxtype( 0, 1 ) * amp[0];
  jamp[20] -= cxtype( 0, 1 ) * amp[0];
  jamp[25] -= cxtype( 0, 1 ) * amp[0];
  jamp[28] += cxtype( 0, 1 ) * amp[0];
  jamp[34] += cxtype( 0, 1 ) * amp[0];
  jamp[44] -= cxtype( 0, 1 ) * amp[0];
  jamp[66] -= cxtype( 0, 1 ) * amp[0];
  jamp[108] += cxtype( 0, 1 ) * amp[0];
  FFV1_0( w[38], w[2], w[111], COUPs[1], &amp[0] );
  jamp[1] += cxtype( 0, 1 ) * amp[0];
  jamp[4] -= cxtype( 0, 1 ) * amp[0];
  jamp[25] -= cxtype( 0, 1 ) * amp[0];
  jamp[28] += cxtype( 0, 1 ) * amp[0];
  jamp[66] -= cxtype( 0, 1 ) * amp[0];
  jamp[68] += cxtype( 0, 1 ) * amp[0];
  jamp[108] += cxtype( 0, 1 ) * amp[0];
  jamp[110] -= cxtype( 0, 1 ) * amp[0];

  // *** DIAGRAM 1117 OF 1240 ***

  // Wavefunction(s) for diagram number 1117
  // (none)

  // Amplitude(s) for diagram number 1117
  FFV1_0( w[62], w[2], w[59], COUPs[1], &amp[0] );
#ifdef MGONGPU_SUPPORTS_MULTICHANNEL
  if( channelId == 1117 ) allNumerators[0] += cxabs2( amp[0] );
  if( channelId != 0 ) allDenominators[0] += cxabs2( amp[0] );
#endif
  jamp[32] += amp[0];
  jamp[38] -= amp[0];
  jamp[62] -= amp[0];
  jamp[86] += amp[0];

  // *** DIAGRAM 1118 OF 1240 ***

  // Wavefunction(s) for diagram number 1118
  // (none)

  // Amplitude(s) for diagram number 1118
  FFV1_0( w[62], w[17], w[1], COUPs[1], &amp[0] );
#ifdef MGONGPU_SUPPORTS_MULTICHANNEL
  if( channelId == 1118 ) allNumerators[0] += cxabs2( amp[0] );
  if( channelId != 0 ) allDenominators[0] += cxabs2( amp[0] );
#endif
  jamp[62] += cxtype( 0, 1 ) * amp[0];
  jamp[86] -= cxtype( 0, 1 ) * amp[0];

  // *** DIAGRAM 1119 OF 1240 ***

  // Wavefunction(s) for diagram number 1119
  // (none)

  // Amplitude(s) for diagram number 1119
  FFV1_0( w[60], w[2], w[98], COUPs[1], &amp[0] );
#ifdef MGONGPU_SUPPORTS_MULTICHANNEL
  if( channelId == 1119 ) allNumerators[0] += cxabs2( amp[0] );
  if( channelId != 0 ) allDenominators[0] += cxabs2( amp[0] );
#endif
  jamp[8] += amp[0];
  jamp[14] -= amp[0];
  jamp[60] -= amp[0];
  jamp[84] += amp[0];

  // *** DIAGRAM 1120 OF 1240 ***

  // Wavefunction(s) for diagram number 1120
  // (none)

  // Amplitude(s) for diagram number 1120
  VVV1_0( w[98], w[1], w[20], COUPs[0], &amp[0] );
#ifdef MGONGPU_SUPPORTS_MULTICHANNEL
  if( channelId == 1120 ) allNumerators[0] += cxabs2( amp[0] );
  if( channelId != 0 ) allDenominators[0] += cxabs2( amp[0] );
#endif
  jamp[8] -= cxtype( 0, 1 ) * amp[0];
  jamp[14] += cxtype( 0, 1 ) * amp[0];
  jamp[24] += cxtype( 0, 1 ) * amp[0];
  jamp[26] -= cxtype( 0, 1 ) * amp[0];
  jamp[32] -= cxtype( 0, 1 ) * amp[0];
  jamp[38] += cxtype( 0, 1 ) * amp[0];
  jamp[60] += cxtype( 0, 1 ) * amp[0];
  jamp[84] -= cxtype( 0, 1 ) * amp[0];

  // *** DIAGRAM 1121 OF 1240 ***

  // Wavefunction(s) for diagram number 1121
  // (none)

  // Amplitude(s) for diagram number 1121
  FFV1_0( w[60], w[17], w[0], COUPs[1], &amp[0] );
#ifdef MGONGPU_SUPPORTS_MULTICHANNEL
  if( channelId == 1121 ) allNumerators[0] += cxabs2( amp[0] );
  if( channelId != 0 ) allDenominators[0] += cxabs2( amp[0] );
#endif
  jamp[60] += cxtype( 0, 1 ) * amp[0];
  jamp[84] -= cxtype( 0, 1 ) * amp[0];

  // *** DIAGRAM 1122 OF 1240 ***

  // Wavefunction(s) for diagram number 1122
  // (none)

  // Amplitude(s) for diagram number 1122
  VVV1_0( w[0], w[59], w[20], COUPs[0], &amp[0] );
#ifdef MGONGPU_SUPPORTS_MULTICHANNEL
  if( channelId == 1122 ) allNumerators[0] += cxabs2( amp[0] );
  if( channelId != 0 ) allDenominators[0] += cxabs2( amp[0] );
#endif
  jamp[0] -= cxtype( 0, 1 ) * amp[0];
  jamp[2] += cxtype( 0, 1 ) * amp[0];
  jamp[8] += cxtype( 0, 1 ) * amp[0];
  jamp[14] -= cxtype( 0, 1 ) * amp[0];
  jamp[32] += cxtype( 0, 1 ) * amp[0];
  jamp[38] -= cxtype( 0, 1 ) * amp[0];
  jamp[62] -= cxtype( 0, 1 ) * amp[0];
  jamp[86] += cxtype( 0, 1 ) * amp[0];

  // *** DIAGRAM 1123 OF 1240 ***

  // Wavefunction(s) for diagram number 1123
  // (none)

  // Amplitude(s) for diagram number 1123
  FFV1_0( w[41], w[2], w[97], COUPs[1], &amp[0] );
  jamp[0] -= cxtype( 0, 1 ) * amp[0];
  jamp[2] += cxtype( 0, 1 ) * amp[0];
  jamp[8] += cxtype( 0, 1 ) * amp[0];
  jamp[14] -= cxtype( 0, 1 ) * amp[0];
  jamp[32] += cxtype( 0, 1 ) * amp[0];
  jamp[38] -= cxtype( 0, 1 ) * amp[0];
  jamp[62] -= cxtype( 0, 1 ) * amp[0];
  jamp[86] += cxtype( 0, 1 ) * amp[0];
  FFV1_0( w[41], w[2], w[71], COUPs[1], &amp[0] );
  jamp[8] += cxtype( 0, 1 ) * amp[0];
  jamp[14] -= cxtype( 0, 1 ) * amp[0];
  jamp[24] -= cxtype( 0, 1 ) * amp[0];
  jamp[26] += cxtype( 0, 1 ) * amp[0];
  jamp[32] += cxtype( 0, 1 ) * amp[0];
  jamp[38] -= cxtype( 0, 1 ) * amp[0];
  jamp[60] -= cxtype( 0, 1 ) * amp[0];
  jamp[84] += cxtype( 0, 1 ) * amp[0];
  FFV1_0( w[41], w[2], w[21], COUPs[1], &amp[0] );
  jamp[0] += cxtype( 0, 1 ) * amp[0];
  jamp[2] -= cxtype( 0, 1 ) * amp[0];
  jamp[24] -= cxtype( 0, 1 ) * amp[0];
  jamp[26] += cxtype( 0, 1 ) * amp[0];
  jamp[60] -= cxtype( 0, 1 ) * amp[0];
  jamp[62] += cxtype( 0, 1 ) * amp[0];
  jamp[84] += cxtype( 0, 1 ) * amp[0];
  jamp[86] -= cxtype( 0, 1 ) * amp[0];

  // *** DIAGRAM 1124 OF 1240 ***

  // Wavefunction(s) for diagram number 1124
  VVVV1P0_1( w[0], w[1], w[4], COUPs[2], 0., 0., w[21] );
  VVVV3P0_1( w[0], w[1], w[4], COUPs[2], 0., 0., w[71] );
  VVVV4P0_1( w[0], w[1], w[4], COUPs[2], 0., 0., w[97] );

  // Amplitude(s) for diagram number 1124
  VVVV1_0( w[21], w[8], w[5], w[6], COUPs[2], &amp[0] );
  jamp[0] += amp[0];
  jamp[1] -= amp[0];
  jamp[6] -= amp[0];
  jamp[7] += amp[0];
  jamp[30] -= amp[0];
  jamp[31] += amp[0];
  jamp[54] += amp[0];
  jamp[55] -= amp[0];
  jamp[90] -= amp[0];
  jamp[91] += amp[0];
  jamp[93] += amp[0];
  jamp[95] -= amp[0];
  jamp[114] += amp[0];
  jamp[115] -= amp[0];
  jamp[117] -= amp[0];
  jamp[119] += amp[0];
  VVVV3_0( w[21], w[8], w[5], w[6], COUPs[2], &amp[0] );
  jamp[0] += amp[0];
  jamp[6] -= amp[0];
  jamp[30] -= amp[0];
  jamp[54] += amp[0];
  jamp[72] -= amp[0];
  jamp[74] += amp[0];
  jamp[80] += amp[0];
  jamp[86] -= amp[0];
  jamp[96] -= amp[0];
  jamp[98] += amp[0];
  jamp[104] += amp[0];
  jamp[110] -= amp[0];
  jamp[114] += amp[0];
  jamp[115] -= amp[0];
  jamp[117] -= amp[0];
  jamp[119] += amp[0];
  VVVV4_0( w[21], w[8], w[5], w[6], COUPs[2], &amp[0] );
  jamp[1] += amp[0];
  jamp[7] -= amp[0];
  jamp[31] -= amp[0];
  jamp[55] += amp[0];
  jamp[72] -= amp[0];
  jamp[74] += amp[0];
  jamp[80] += amp[0];
  jamp[86] -= amp[0];
  jamp[90] += amp[0];
  jamp[91] -= amp[0];
  jamp[93] -= amp[0];
  jamp[95] += amp[0];
  jamp[96] -= amp[0];
  jamp[98] += amp[0];
  jamp[104] += amp[0];
  jamp[110] -= amp[0];
  VVVV1_0( w[71], w[8], w[5], w[6], COUPs[2], &amp[0] );
  jamp[6] -= amp[0];
  jamp[7] += amp[0];
  jamp[24] += amp[0];
  jamp[25] -= amp[0];
  jamp[30] -= amp[0];
  jamp[31] += amp[0];
  jamp[48] += amp[0];
  jamp[49] -= amp[0];
  jamp[91] += amp[0];
  jamp[92] -= amp[0];
  jamp[93] += amp[0];
  jamp[94] -= amp[0];
  jamp[115] -= amp[0];
  jamp[116] += amp[0];
  jamp[117] -= amp[0];
  jamp[118] += amp[0];
  VVVV3_0( w[71], w[8], w[5], w[6], COUPs[2], &amp[0] );
  jamp[6] -= amp[0];
  jamp[24] += amp[0];
  jamp[30] -= amp[0];
  jamp[48] += amp[0];
  jamp[74] += amp[0];
  jamp[78] -= amp[0];
  jamp[80] += amp[0];
  jamp[84] -= amp[0];
  jamp[98] += amp[0];
  jamp[102] -= amp[0];
  jamp[104] += amp[0];
  jamp[108] -= amp[0];
  jamp[115] -= amp[0];
  jamp[116] += amp[0];
  jamp[117] -= amp[0];
  jamp[118] += amp[0];
  VVVV4_0( w[71], w[8], w[5], w[6], COUPs[2], &amp[0] );
  jamp[7] -= amp[0];
  jamp[25] += amp[0];
  jamp[31] -= amp[0];
  jamp[49] += amp[0];
  jamp[74] += amp[0];
  jamp[78] -= amp[0];
  jamp[80] += amp[0];
  jamp[84] -= amp[0];
  jamp[91] -= amp[0];
  jamp[92] += amp[0];
  jamp[93] -= amp[0];
  jamp[94] += amp[0];
  jamp[98] += amp[0];
  jamp[102] -= amp[0];
  jamp[104] += amp[0];
  jamp[108] -= amp[0];
  VVVV1_0( w[97], w[8], w[5], w[6], COUPs[2], &amp[0] );
  jamp[0] -= amp[0];
  jamp[1] += amp[0];
  jamp[24] += amp[0];
  jamp[25] -= amp[0];
  jamp[48] += amp[0];
  jamp[49] -= amp[0];
  jamp[54] -= amp[0];
  jamp[55] += amp[0];
  jamp[90] += amp[0];
  jamp[92] -= amp[0];
  jamp[94] -= amp[0];
  jamp[95] += amp[0];
  jamp[114] -= amp[0];
  jamp[116] += amp[0];
  jamp[118] += amp[0];
  jamp[119] -= amp[0];
  VVVV3_0( w[97], w[8], w[5], w[6], COUPs[2], &amp[0] );
  jamp[0] -= amp[0];
  jamp[24] += amp[0];
  jamp[48] += amp[0];
  jamp[54] -= amp[0];
  jamp[72] += amp[0];
  jamp[78] -= amp[0];
  jamp[84] -= amp[0];
  jamp[86] += amp[0];
  jamp[96] += amp[0];
  jamp[102] -= amp[0];
  jamp[108] -= amp[0];
  jamp[110] += amp[0];
  jamp[114] -= amp[0];
  jamp[116] += amp[0];
  jamp[118] += amp[0];
  jamp[119] -= amp[0];
  VVVV4_0( w[97], w[8], w[5], w[6], COUPs[2], &amp[0] );
  jamp[1] -= amp[0];
  jamp[25] += amp[0];
  jamp[49] += amp[0];
  jamp[55] -= amp[0];
  jamp[72] += amp[0];
  jamp[78] -= amp[0];
  jamp[84] -= amp[0];
  jamp[86] += amp[0];
  jamp[90] -= amp[0];
  jamp[92] += amp[0];
  jamp[94] += amp[0];
  jamp[95] -= amp[0];
  jamp[96] += amp[0];
  jamp[102] -= amp[0];
  jamp[108] -= amp[0];
  jamp[110] += amp[0];

  // *** DIAGRAM 1125 OF 1240 ***

  // Wavefunction(s) for diagram number 1125
  VVV1P0_1( w[21], w[5], COUPs[0], 0., 0., w[59] );
  VVV1P0_1( w[71], w[5], COUPs[0], 0., 0., w[20] );
  VVV1P0_1( w[97], w[5], COUPs[0], 0., 0., w[60] );

  // Amplitude(s) for diagram number 1125
  VVV1_0( w[8], w[6], w[59], COUPs[0], &amp[0] );
  jamp[0] += amp[0];
  jamp[6] -= amp[0];
  jamp[30] -= amp[0];
  jamp[54] += amp[0];
  jamp[72] -= amp[0];
  jamp[74] += amp[0];
  jamp[80] += amp[0];
  jamp[86] -= amp[0];
  jamp[96] -= amp[0];
  jamp[98] += amp[0];
  jamp[104] += amp[0];
  jamp[110] -= amp[0];
  jamp[114] += amp[0];
  jamp[115] -= amp[0];
  jamp[117] -= amp[0];
  jamp[119] += amp[0];
  VVV1_0( w[8], w[6], w[20], COUPs[0], &amp[0] );
  jamp[6] -= amp[0];
  jamp[24] += amp[0];
  jamp[30] -= amp[0];
  jamp[48] += amp[0];
  jamp[74] += amp[0];
  jamp[78] -= amp[0];
  jamp[80] += amp[0];
  jamp[84] -= amp[0];
  jamp[98] += amp[0];
  jamp[102] -= amp[0];
  jamp[104] += amp[0];
  jamp[108] -= amp[0];
  jamp[115] -= amp[0];
  jamp[116] += amp[0];
  jamp[117] -= amp[0];
  jamp[118] += amp[0];
  VVV1_0( w[8], w[6], w[60], COUPs[0], &amp[0] );
  jamp[0] -= amp[0];
  jamp[24] += amp[0];
  jamp[48] += amp[0];
  jamp[54] -= amp[0];
  jamp[72] += amp[0];
  jamp[78] -= amp[0];
  jamp[84] -= amp[0];
  jamp[86] += amp[0];
  jamp[96] += amp[0];
  jamp[102] -= amp[0];
  jamp[108] -= amp[0];
  jamp[110] += amp[0];
  jamp[114] -= amp[0];
  jamp[116] += amp[0];
  jamp[118] += amp[0];
  jamp[119] -= amp[0];

  // *** DIAGRAM 1126 OF 1240 ***

  // Wavefunction(s) for diagram number 1126
  VVV1P0_1( w[21], w[6], COUPs[0], 0., 0., w[17] );
  VVV1P0_1( w[71], w[6], COUPs[0], 0., 0., w[98] );
  VVV1P0_1( w[97], w[6], COUPs[0], 0., 0., w[111] );

  // Amplitude(s) for diagram number 1126
  VVV1_0( w[8], w[5], w[17], COUPs[0], &amp[0] );
  jamp[1] += amp[0];
  jamp[7] -= amp[0];
  jamp[31] -= amp[0];
  jamp[55] += amp[0];
  jamp[72] -= amp[0];
  jamp[74] += amp[0];
  jamp[80] += amp[0];
  jamp[86] -= amp[0];
  jamp[90] += amp[0];
  jamp[91] -= amp[0];
  jamp[93] -= amp[0];
  jamp[95] += amp[0];
  jamp[96] -= amp[0];
  jamp[98] += amp[0];
  jamp[104] += amp[0];
  jamp[110] -= amp[0];
  VVV1_0( w[8], w[5], w[98], COUPs[0], &amp[0] );
  jamp[7] -= amp[0];
  jamp[25] += amp[0];
  jamp[31] -= amp[0];
  jamp[49] += amp[0];
  jamp[74] += amp[0];
  jamp[78] -= amp[0];
  jamp[80] += amp[0];
  jamp[84] -= amp[0];
  jamp[91] -= amp[0];
  jamp[92] += amp[0];
  jamp[93] -= amp[0];
  jamp[94] += amp[0];
  jamp[98] += amp[0];
  jamp[102] -= amp[0];
  jamp[104] += amp[0];
  jamp[108] -= amp[0];
  VVV1_0( w[8], w[5], w[111], COUPs[0], &amp[0] );
  jamp[1] -= amp[0];
  jamp[25] += amp[0];
  jamp[49] += amp[0];
  jamp[55] -= amp[0];
  jamp[72] += amp[0];
  jamp[78] -= amp[0];
  jamp[84] -= amp[0];
  jamp[86] += amp[0];
  jamp[90] -= amp[0];
  jamp[92] += amp[0];
  jamp[94] += amp[0];
  jamp[95] -= amp[0];
  jamp[96] += amp[0];
  jamp[102] -= amp[0];
  jamp[108] -= amp[0];
  jamp[110] += amp[0];

  // *** DIAGRAM 1127 OF 1240 ***

  // Wavefunction(s) for diagram number 1127
  // (none)

  // Amplitude(s) for diagram number 1127
  VVV1_0( w[21], w[8], w[29], COUPs[0], &amp[0] );
  jamp[0] += amp[0];
  jamp[1] -= amp[0];
  jamp[6] -= amp[0];
  jamp[7] += amp[0];
  jamp[30] -= amp[0];
  jamp[31] += amp[0];
  jamp[54] += amp[0];
  jamp[55] -= amp[0];
  jamp[90] -= amp[0];
  jamp[91] += amp[0];
  jamp[93] += amp[0];
  jamp[95] -= amp[0];
  jamp[114] += amp[0];
  jamp[115] -= amp[0];
  jamp[117] -= amp[0];
  jamp[119] += amp[0];
  VVV1_0( w[71], w[8], w[29], COUPs[0], &amp[0] );
  jamp[6] -= amp[0];
  jamp[7] += amp[0];
  jamp[24] += amp[0];
  jamp[25] -= amp[0];
  jamp[30] -= amp[0];
  jamp[31] += amp[0];
  jamp[48] += amp[0];
  jamp[49] -= amp[0];
  jamp[91] += amp[0];
  jamp[92] -= amp[0];
  jamp[93] += amp[0];
  jamp[94] -= amp[0];
  jamp[115] -= amp[0];
  jamp[116] += amp[0];
  jamp[117] -= amp[0];
  jamp[118] += amp[0];
  VVV1_0( w[97], w[8], w[29], COUPs[0], &amp[0] );
  jamp[0] -= amp[0];
  jamp[1] += amp[0];
  jamp[24] += amp[0];
  jamp[25] -= amp[0];
  jamp[48] += amp[0];
  jamp[49] -= amp[0];
  jamp[54] -= amp[0];
  jamp[55] += amp[0];
  jamp[90] += amp[0];
  jamp[92] -= amp[0];
  jamp[94] -= amp[0];
  jamp[95] += amp[0];
  jamp[114] -= amp[0];
  jamp[116] += amp[0];
  jamp[118] += amp[0];
  jamp[119] -= amp[0];

  // *** DIAGRAM 1128 OF 1240 ***

  // Wavefunction(s) for diagram number 1128
  FFV1_2( w[3], w[21], COUPs[1], cIPD[0], cIPD[1], w[16] );
  FFV1_2( w[3], w[71], COUPs[1], cIPD[0], cIPD[1], w[10] );
  FFV1_2( w[3], w[97], COUPs[1], cIPD[0], cIPD[1], w[68] );

  // Amplitude(s) for diagram number 1128
  FFV1_0( w[16], w[39], w[6], COUPs[1], &amp[0] );
  jamp[90] += amp[0];
  jamp[91] -= amp[0];
  jamp[93] -= amp[0];
  jamp[95] += amp[0];
  FFV1_0( w[10], w[39], w[6], COUPs[1], &amp[0] );
  jamp[91] -= amp[0];
  jamp[92] += amp[0];
  jamp[93] -= amp[0];
  jamp[94] += amp[0];
  FFV1_0( w[68], w[39], w[6], COUPs[1], &amp[0] );
  jamp[90] -= amp[0];
  jamp[92] += amp[0];
  jamp[94] += amp[0];
  jamp[95] -= amp[0];

  // *** DIAGRAM 1129 OF 1240 ***

  // Wavefunction(s) for diagram number 1129
  // (none)

  // Amplitude(s) for diagram number 1129
  FFV1_0( w[3], w[39], w[17], COUPs[1], &amp[0] );
  jamp[72] -= cxtype( 0, 1 ) * amp[0];
  jamp[74] += cxtype( 0, 1 ) * amp[0];
  jamp[80] += cxtype( 0, 1 ) * amp[0];
  jamp[86] -= cxtype( 0, 1 ) * amp[0];
  jamp[90] += cxtype( 0, 1 ) * amp[0];
  jamp[91] -= cxtype( 0, 1 ) * amp[0];
  jamp[93] -= cxtype( 0, 1 ) * amp[0];
  jamp[95] += cxtype( 0, 1 ) * amp[0];
  FFV1_0( w[3], w[39], w[98], COUPs[1], &amp[0] );
  jamp[74] += cxtype( 0, 1 ) * amp[0];
  jamp[78] -= cxtype( 0, 1 ) * amp[0];
  jamp[80] += cxtype( 0, 1 ) * amp[0];
  jamp[84] -= cxtype( 0, 1 ) * amp[0];
  jamp[91] -= cxtype( 0, 1 ) * amp[0];
  jamp[92] += cxtype( 0, 1 ) * amp[0];
  jamp[93] -= cxtype( 0, 1 ) * amp[0];
  jamp[94] += cxtype( 0, 1 ) * amp[0];
  FFV1_0( w[3], w[39], w[111], COUPs[1], &amp[0] );
  jamp[72] += cxtype( 0, 1 ) * amp[0];
  jamp[78] -= cxtype( 0, 1 ) * amp[0];
  jamp[84] -= cxtype( 0, 1 ) * amp[0];
  jamp[86] += cxtype( 0, 1 ) * amp[0];
  jamp[90] -= cxtype( 0, 1 ) * amp[0];
  jamp[92] += cxtype( 0, 1 ) * amp[0];
  jamp[94] += cxtype( 0, 1 ) * amp[0];
  jamp[95] -= cxtype( 0, 1 ) * amp[0];

  // *** DIAGRAM 1130 OF 1240 ***

  // Wavefunction(s) for diagram number 1130
  // (none)

  // Amplitude(s) for diagram number 1130
  FFV1_0( w[41], w[39], w[21], COUPs[1], &amp[0] );
  jamp[72] += amp[0];
  jamp[74] -= amp[0];
  jamp[80] -= amp[0];
  jamp[86] += amp[0];
  FFV1_0( w[41], w[39], w[71], COUPs[1], &amp[0] );
  jamp[74] -= amp[0];
  jamp[78] += amp[0];
  jamp[80] -= amp[0];
  jamp[84] += amp[0];
  FFV1_0( w[41], w[39], w[97], COUPs[1], &amp[0] );
  jamp[72] -= amp[0];
  jamp[78] += amp[0];
  jamp[84] += amp[0];
  jamp[86] -= amp[0];

  // *** DIAGRAM 1131 OF 1240 ***

  // Wavefunction(s) for diagram number 1131
  // (none)

  // Amplitude(s) for diagram number 1131
  FFV1_0( w[16], w[47], w[5], COUPs[1], &amp[0] );
  jamp[114] += amp[0];
  jamp[115] -= amp[0];
  jamp[117] -= amp[0];
  jamp[119] += amp[0];
  FFV1_0( w[10], w[47], w[5], COUPs[1], &amp[0] );
  jamp[115] -= amp[0];
  jamp[116] += amp[0];
  jamp[117] -= amp[0];
  jamp[118] += amp[0];
  FFV1_0( w[68], w[47], w[5], COUPs[1], &amp[0] );
  jamp[114] -= amp[0];
  jamp[116] += amp[0];
  jamp[118] += amp[0];
  jamp[119] -= amp[0];

  // *** DIAGRAM 1132 OF 1240 ***

  // Wavefunction(s) for diagram number 1132
  // (none)

  // Amplitude(s) for diagram number 1132
  FFV1_0( w[3], w[47], w[59], COUPs[1], &amp[0] );
  jamp[96] -= cxtype( 0, 1 ) * amp[0];
  jamp[98] += cxtype( 0, 1 ) * amp[0];
  jamp[104] += cxtype( 0, 1 ) * amp[0];
  jamp[110] -= cxtype( 0, 1 ) * amp[0];
  jamp[114] += cxtype( 0, 1 ) * amp[0];
  jamp[115] -= cxtype( 0, 1 ) * amp[0];
  jamp[117] -= cxtype( 0, 1 ) * amp[0];
  jamp[119] += cxtype( 0, 1 ) * amp[0];
  FFV1_0( w[3], w[47], w[20], COUPs[1], &amp[0] );
  jamp[98] += cxtype( 0, 1 ) * amp[0];
  jamp[102] -= cxtype( 0, 1 ) * amp[0];
  jamp[104] += cxtype( 0, 1 ) * amp[0];
  jamp[108] -= cxtype( 0, 1 ) * amp[0];
  jamp[115] -= cxtype( 0, 1 ) * amp[0];
  jamp[116] += cxtype( 0, 1 ) * amp[0];
  jamp[117] -= cxtype( 0, 1 ) * amp[0];
  jamp[118] += cxtype( 0, 1 ) * amp[0];
  FFV1_0( w[3], w[47], w[60], COUPs[1], &amp[0] );
  jamp[96] += cxtype( 0, 1 ) * amp[0];
  jamp[102] -= cxtype( 0, 1 ) * amp[0];
  jamp[108] -= cxtype( 0, 1 ) * amp[0];
  jamp[110] += cxtype( 0, 1 ) * amp[0];
  jamp[114] -= cxtype( 0, 1 ) * amp[0];
  jamp[116] += cxtype( 0, 1 ) * amp[0];
  jamp[118] += cxtype( 0, 1 ) * amp[0];
  jamp[119] -= cxtype( 0, 1 ) * amp[0];

  // *** DIAGRAM 1133 OF 1240 ***

  // Wavefunction(s) for diagram number 1133
  // (none)

  // Amplitude(s) for diagram number 1133
  FFV1_0( w[38], w[47], w[21], COUPs[1], &amp[0] );
  jamp[96] += amp[0];
  jamp[98] -= amp[0];
  jamp[104] -= amp[0];
  jamp[110] += amp[0];
  FFV1_0( w[38], w[47], w[71], COUPs[1], &amp[0] );
  jamp[98] -= amp[0];
  jamp[102] += amp[0];
  jamp[104] -= amp[0];
  jamp[108] += amp[0];
  FFV1_0( w[38], w[47], w[97], COUPs[1], &amp[0] );
  jamp[96] -= amp[0];
  jamp[102] += amp[0];
  jamp[108] += amp[0];
  jamp[110] -= amp[0];

  // *** DIAGRAM 1134 OF 1240 ***

  // Wavefunction(s) for diagram number 1134
  FFV1_1( w[2], w[21], COUPs[1], cIPD[0], cIPD[1], w[23] );
  FFV1_1( w[2], w[71], COUPs[1], cIPD[0], cIPD[1], w[21] );
  FFV1_1( w[2], w[97], COUPs[1], cIPD[0], cIPD[1], w[71] );

  // Amplitude(s) for diagram number 1134
  FFV1_0( w[38], w[23], w[6], COUPs[1], &amp[0] );
  jamp[1] += amp[0];
  jamp[7] -= amp[0];
  jamp[31] -= amp[0];
  jamp[55] += amp[0];
  FFV1_0( w[38], w[21], w[6], COUPs[1], &amp[0] );
  jamp[7] -= amp[0];
  jamp[25] += amp[0];
  jamp[31] -= amp[0];
  jamp[49] += amp[0];
  FFV1_0( w[38], w[71], w[6], COUPs[1], &amp[0] );
  jamp[1] -= amp[0];
  jamp[25] += amp[0];
  jamp[49] += amp[0];
  jamp[55] -= amp[0];

  // *** DIAGRAM 1135 OF 1240 ***

  // Wavefunction(s) for diagram number 1135
  // (none)

  // Amplitude(s) for diagram number 1135
  FFV1_0( w[38], w[2], w[17], COUPs[1], &amp[0] );
  jamp[1] -= cxtype( 0, 1 ) * amp[0];
  jamp[7] += cxtype( 0, 1 ) * amp[0];
  jamp[31] += cxtype( 0, 1 ) * amp[0];
  jamp[55] -= cxtype( 0, 1 ) * amp[0];
  jamp[96] += cxtype( 0, 1 ) * amp[0];
  jamp[98] -= cxtype( 0, 1 ) * amp[0];
  jamp[104] -= cxtype( 0, 1 ) * amp[0];
  jamp[110] += cxtype( 0, 1 ) * amp[0];
  FFV1_0( w[38], w[2], w[98], COUPs[1], &amp[0] );
  jamp[7] += cxtype( 0, 1 ) * amp[0];
  jamp[25] -= cxtype( 0, 1 ) * amp[0];
  jamp[31] += cxtype( 0, 1 ) * amp[0];
  jamp[49] -= cxtype( 0, 1 ) * amp[0];
  jamp[98] -= cxtype( 0, 1 ) * amp[0];
  jamp[102] += cxtype( 0, 1 ) * amp[0];
  jamp[104] -= cxtype( 0, 1 ) * amp[0];
  jamp[108] += cxtype( 0, 1 ) * amp[0];
  FFV1_0( w[38], w[2], w[111], COUPs[1], &amp[0] );
  jamp[1] += cxtype( 0, 1 ) * amp[0];
  jamp[25] -= cxtype( 0, 1 ) * amp[0];
  jamp[49] -= cxtype( 0, 1 ) * amp[0];
  jamp[55] += cxtype( 0, 1 ) * amp[0];
  jamp[96] -= cxtype( 0, 1 ) * amp[0];
  jamp[102] += cxtype( 0, 1 ) * amp[0];
  jamp[108] += cxtype( 0, 1 ) * amp[0];
  jamp[110] -= cxtype( 0, 1 ) * amp[0];

  // *** DIAGRAM 1136 OF 1240 ***

  // Wavefunction(s) for diagram number 1136
  // (none)

  // Amplitude(s) for diagram number 1136
  FFV1_0( w[41], w[23], w[5], COUPs[1], &amp[0] );
  jamp[0] += amp[0];
  jamp[6] -= amp[0];
  jamp[30] -= amp[0];
  jamp[54] += amp[0];
  FFV1_0( w[41], w[21], w[5], COUPs[1], &amp[0] );
  jamp[6] -= amp[0];
  jamp[24] += amp[0];
  jamp[30] -= amp[0];
  jamp[48] += amp[0];
  FFV1_0( w[41], w[71], w[5], COUPs[1], &amp[0] );
  jamp[0] -= amp[0];
  jamp[24] += amp[0];
  jamp[48] += amp[0];
  jamp[54] -= amp[0];

  // *** DIAGRAM 1137 OF 1240 ***

  // Wavefunction(s) for diagram number 1137
  // (none)

  // Amplitude(s) for diagram number 1137
  FFV1_0( w[41], w[2], w[59], COUPs[1], &amp[0] );
  jamp[0] -= cxtype( 0, 1 ) * amp[0];
  jamp[6] += cxtype( 0, 1 ) * amp[0];
  jamp[30] += cxtype( 0, 1 ) * amp[0];
  jamp[54] -= cxtype( 0, 1 ) * amp[0];
  jamp[72] += cxtype( 0, 1 ) * amp[0];
  jamp[74] -= cxtype( 0, 1 ) * amp[0];
  jamp[80] -= cxtype( 0, 1 ) * amp[0];
  jamp[86] += cxtype( 0, 1 ) * amp[0];
  FFV1_0( w[41], w[2], w[20], COUPs[1], &amp[0] );
  jamp[6] += cxtype( 0, 1 ) * amp[0];
  jamp[24] -= cxtype( 0, 1 ) * amp[0];
  jamp[30] += cxtype( 0, 1 ) * amp[0];
  jamp[48] -= cxtype( 0, 1 ) * amp[0];
  jamp[74] -= cxtype( 0, 1 ) * amp[0];
  jamp[78] += cxtype( 0, 1 ) * amp[0];
  jamp[80] -= cxtype( 0, 1 ) * amp[0];
  jamp[84] += cxtype( 0, 1 ) * amp[0];
  FFV1_0( w[41], w[2], w[60], COUPs[1], &amp[0] );
  jamp[0] += cxtype( 0, 1 ) * amp[0];
  jamp[24] -= cxtype( 0, 1 ) * amp[0];
  jamp[48] -= cxtype( 0, 1 ) * amp[0];
  jamp[54] += cxtype( 0, 1 ) * amp[0];
  jamp[72] -= cxtype( 0, 1 ) * amp[0];
  jamp[78] += cxtype( 0, 1 ) * amp[0];
  jamp[84] += cxtype( 0, 1 ) * amp[0];
  jamp[86] -= cxtype( 0, 1 ) * amp[0];

  // *** DIAGRAM 1138 OF 1240 ***

  // Wavefunction(s) for diagram number 1138
  // (none)

  // Amplitude(s) for diagram number 1138
  FFV1_0( w[3], w[23], w[29], COUPs[1], &amp[0] );
  jamp[0] -= cxtype( 0, 1 ) * amp[0];
  jamp[1] += cxtype( 0, 1 ) * amp[0];
  jamp[6] += cxtype( 0, 1 ) * amp[0];
  jamp[7] -= cxtype( 0, 1 ) * amp[0];
  jamp[30] += cxtype( 0, 1 ) * amp[0];
  jamp[31] -= cxtype( 0, 1 ) * amp[0];
  jamp[54] -= cxtype( 0, 1 ) * amp[0];
  jamp[55] += cxtype( 0, 1 ) * amp[0];
  FFV1_0( w[3], w[21], w[29], COUPs[1], &amp[0] );
  jamp[6] += cxtype( 0, 1 ) * amp[0];
  jamp[7] -= cxtype( 0, 1 ) * amp[0];
  jamp[24] -= cxtype( 0, 1 ) * amp[0];
  jamp[25] += cxtype( 0, 1 ) * amp[0];
  jamp[30] += cxtype( 0, 1 ) * amp[0];
  jamp[31] -= cxtype( 0, 1 ) * amp[0];
  jamp[48] -= cxtype( 0, 1 ) * amp[0];
  jamp[49] += cxtype( 0, 1 ) * amp[0];
  FFV1_0( w[3], w[71], w[29], COUPs[1], &amp[0] );
  jamp[0] += cxtype( 0, 1 ) * amp[0];
  jamp[1] -= cxtype( 0, 1 ) * amp[0];
  jamp[24] -= cxtype( 0, 1 ) * amp[0];
  jamp[25] += cxtype( 0, 1 ) * amp[0];
  jamp[48] -= cxtype( 0, 1 ) * amp[0];
  jamp[49] += cxtype( 0, 1 ) * amp[0];
  jamp[54] += cxtype( 0, 1 ) * amp[0];
  jamp[55] -= cxtype( 0, 1 ) * amp[0];

  // *** DIAGRAM 1139 OF 1240 ***

  // Wavefunction(s) for diagram number 1139
  // (none)

  // Amplitude(s) for diagram number 1139
  FFV1_0( w[16], w[2], w[29], COUPs[1], &amp[0] );
  jamp[90] -= cxtype( 0, 1 ) * amp[0];
  jamp[91] += cxtype( 0, 1 ) * amp[0];
  jamp[93] += cxtype( 0, 1 ) * amp[0];
  jamp[95] -= cxtype( 0, 1 ) * amp[0];
  jamp[114] += cxtype( 0, 1 ) * amp[0];
  jamp[115] -= cxtype( 0, 1 ) * amp[0];
  jamp[117] -= cxtype( 0, 1 ) * amp[0];
  jamp[119] += cxtype( 0, 1 ) * amp[0];
  FFV1_0( w[10], w[2], w[29], COUPs[1], &amp[0] );
  jamp[91] += cxtype( 0, 1 ) * amp[0];
  jamp[92] -= cxtype( 0, 1 ) * amp[0];
  jamp[93] += cxtype( 0, 1 ) * amp[0];
  jamp[94] -= cxtype( 0, 1 ) * amp[0];
  jamp[115] -= cxtype( 0, 1 ) * amp[0];
  jamp[116] += cxtype( 0, 1 ) * amp[0];
  jamp[117] -= cxtype( 0, 1 ) * amp[0];
  jamp[118] += cxtype( 0, 1 ) * amp[0];
  FFV1_0( w[68], w[2], w[29], COUPs[1], &amp[0] );
  jamp[90] += cxtype( 0, 1 ) * amp[0];
  jamp[92] -= cxtype( 0, 1 ) * amp[0];
  jamp[94] -= cxtype( 0, 1 ) * amp[0];
  jamp[95] += cxtype( 0, 1 ) * amp[0];
  jamp[114] -= cxtype( 0, 1 ) * amp[0];
  jamp[116] += cxtype( 0, 1 ) * amp[0];
  jamp[118] += cxtype( 0, 1 ) * amp[0];
  jamp[119] -= cxtype( 0, 1 ) * amp[0];

  // *** DIAGRAM 1140 OF 1240 ***

  // Wavefunction(s) for diagram number 1140
  VVVV1P0_1( w[0], w[1], w[5], COUPs[2], 0., 0., w[68] );
  VVVV3P0_1( w[0], w[1], w[5], COUPs[2], 0., 0., w[29] );
  VVVV4P0_1( w[0], w[1], w[5], COUPs[2], 0., 0., w[10] );

  // Amplitude(s) for diagram number 1140
  VVVV1_0( w[68], w[8], w[4], w[6], COUPs[2], &amp[0] );
  jamp[2] += amp[0];
  jamp[3] -= amp[0];
  jamp[12] -= amp[0];
  jamp[13] += amp[0];
  jamp[36] -= amp[0];
  jamp[37] += amp[0];
  jamp[66] -= amp[0];
  jamp[67] += amp[0];
  jamp[69] += amp[0];
  jamp[71] -= amp[0];
  jamp[78] += amp[0];
  jamp[79] -= amp[0];
  jamp[108] += amp[0];
  jamp[109] -= amp[0];
  jamp[111] -= amp[0];
  jamp[113] += amp[0];
  VVVV3_0( w[68], w[8], w[4], w[6], COUPs[2], &amp[0] );
  jamp[2] += amp[0];
  jamp[12] -= amp[0];
  jamp[36] -= amp[0];
  jamp[48] -= amp[0];
  jamp[50] += amp[0];
  jamp[56] += amp[0];
  jamp[62] -= amp[0];
  jamp[78] += amp[0];
  jamp[97] -= amp[0];
  jamp[100] += amp[0];
  jamp[106] += amp[0];
  jamp[108] += amp[0];
  jamp[109] -= amp[0];
  jamp[111] -= amp[0];
  jamp[113] += amp[0];
  jamp[116] -= amp[0];
  VVVV4_0( w[68], w[8], w[4], w[6], COUPs[2], &amp[0] );
  jamp[3] += amp[0];
  jamp[13] -= amp[0];
  jamp[37] -= amp[0];
  jamp[48] -= amp[0];
  jamp[50] += amp[0];
  jamp[56] += amp[0];
  jamp[62] -= amp[0];
  jamp[66] += amp[0];
  jamp[67] -= amp[0];
  jamp[69] -= amp[0];
  jamp[71] += amp[0];
  jamp[79] += amp[0];
  jamp[97] -= amp[0];
  jamp[100] += amp[0];
  jamp[106] += amp[0];
  jamp[116] -= amp[0];
  VVVV1_0( w[29], w[8], w[4], w[6], COUPs[2], &amp[0] );
  jamp[12] -= amp[0];
  jamp[13] += amp[0];
  jamp[26] += amp[0];
  jamp[27] -= amp[0];
  jamp[36] -= amp[0];
  jamp[37] += amp[0];
  jamp[67] += amp[0];
  jamp[68] -= amp[0];
  jamp[69] += amp[0];
  jamp[70] -= amp[0];
  jamp[72] += amp[0];
  jamp[73] -= amp[0];
  jamp[109] -= amp[0];
  jamp[110] += amp[0];
  jamp[111] -= amp[0];
  jamp[112] += amp[0];
  VVVV3_0( w[29], w[8], w[4], w[6], COUPs[2], &amp[0] );
  jamp[12] -= amp[0];
  jamp[26] += amp[0];
  jamp[36] -= amp[0];
  jamp[50] += amp[0];
  jamp[54] -= amp[0];
  jamp[56] += amp[0];
  jamp[60] -= amp[0];
  jamp[72] += amp[0];
  jamp[100] += amp[0];
  jamp[103] -= amp[0];
  jamp[106] += amp[0];
  jamp[109] -= amp[0];
  jamp[110] += amp[0];
  jamp[111] -= amp[0];
  jamp[112] += amp[0];
  jamp[114] -= amp[0];
  VVVV4_0( w[29], w[8], w[4], w[6], COUPs[2], &amp[0] );
  jamp[13] -= amp[0];
  jamp[27] += amp[0];
  jamp[37] -= amp[0];
  jamp[50] += amp[0];
  jamp[54] -= amp[0];
  jamp[56] += amp[0];
  jamp[60] -= amp[0];
  jamp[67] -= amp[0];
  jamp[68] += amp[0];
  jamp[69] -= amp[0];
  jamp[70] += amp[0];
  jamp[73] += amp[0];
  jamp[100] += amp[0];
  jamp[103] -= amp[0];
  jamp[106] += amp[0];
  jamp[114] -= amp[0];
  VVVV1_0( w[10], w[8], w[4], w[6], COUPs[2], &amp[0] );
  jamp[2] -= amp[0];
  jamp[3] += amp[0];
  jamp[26] += amp[0];
  jamp[27] -= amp[0];
  jamp[66] += amp[0];
  jamp[68] -= amp[0];
  jamp[70] -= amp[0];
  jamp[71] += amp[0];
  jamp[72] += amp[0];
  jamp[73] -= amp[0];
  jamp[78] -= amp[0];
  jamp[79] += amp[0];
  jamp[108] -= amp[0];
  jamp[110] += amp[0];
  jamp[112] += amp[0];
  jamp[113] -= amp[0];
  VVVV3_0( w[10], w[8], w[4], w[6], COUPs[2], &amp[0] );
  jamp[2] -= amp[0];
  jamp[26] += amp[0];
  jamp[48] += amp[0];
  jamp[54] -= amp[0];
  jamp[60] -= amp[0];
  jamp[62] += amp[0];
  jamp[72] += amp[0];
  jamp[78] -= amp[0];
  jamp[97] += amp[0];
  jamp[103] -= amp[0];
  jamp[108] -= amp[0];
  jamp[110] += amp[0];
  jamp[112] += amp[0];
  jamp[113] -= amp[0];
  jamp[114] -= amp[0];
  jamp[116] += amp[0];
  VVVV4_0( w[10], w[8], w[4], w[6], COUPs[2], &amp[0] );
  jamp[3] -= amp[0];
  jamp[27] += amp[0];
  jamp[48] += amp[0];
  jamp[54] -= amp[0];
  jamp[60] -= amp[0];
  jamp[62] += amp[0];
  jamp[66] -= amp[0];
  jamp[68] += amp[0];
  jamp[70] += amp[0];
  jamp[71] -= amp[0];
  jamp[73] += amp[0];
  jamp[79] -= amp[0];
  jamp[97] += amp[0];
  jamp[103] -= amp[0];
  jamp[114] -= amp[0];
  jamp[116] += amp[0];

  // *** DIAGRAM 1141 OF 1240 ***

  // Wavefunction(s) for diagram number 1141
  VVV1P0_1( w[68], w[4], COUPs[0], 0., 0., w[16] );
  VVV1P0_1( w[29], w[4], COUPs[0], 0., 0., w[71] );
  VVV1P0_1( w[10], w[4], COUPs[0], 0., 0., w[21] );

  // Amplitude(s) for diagram number 1141
  VVV1_0( w[8], w[6], w[16], COUPs[0], &amp[0] );
  jamp[2] += amp[0];
  jamp[12] -= amp[0];
  jamp[36] -= amp[0];
  jamp[48] -= amp[0];
  jamp[50] += amp[0];
  jamp[56] += amp[0];
  jamp[62] -= amp[0];
  jamp[78] += amp[0];
  jamp[97] -= amp[0];
  jamp[100] += amp[0];
  jamp[106] += amp[0];
  jamp[108] += amp[0];
  jamp[109] -= amp[0];
  jamp[111] -= amp[0];
  jamp[113] += amp[0];
  jamp[116] -= amp[0];
  VVV1_0( w[8], w[6], w[71], COUPs[0], &amp[0] );
  jamp[12] -= amp[0];
  jamp[26] += amp[0];
  jamp[36] -= amp[0];
  jamp[50] += amp[0];
  jamp[54] -= amp[0];
  jamp[56] += amp[0];
  jamp[60] -= amp[0];
  jamp[72] += amp[0];
  jamp[100] += amp[0];
  jamp[103] -= amp[0];
  jamp[106] += amp[0];
  jamp[109] -= amp[0];
  jamp[110] += amp[0];
  jamp[111] -= amp[0];
  jamp[112] += amp[0];
  jamp[114] -= amp[0];
  VVV1_0( w[8], w[6], w[21], COUPs[0], &amp[0] );
  jamp[2] -= amp[0];
  jamp[26] += amp[0];
  jamp[48] += amp[0];
  jamp[54] -= amp[0];
  jamp[60] -= amp[0];
  jamp[62] += amp[0];
  jamp[72] += amp[0];
  jamp[78] -= amp[0];
  jamp[97] += amp[0];
  jamp[103] -= amp[0];
  jamp[108] -= amp[0];
  jamp[110] += amp[0];
  jamp[112] += amp[0];
  jamp[113] -= amp[0];
  jamp[114] -= amp[0];
  jamp[116] += amp[0];

  // *** DIAGRAM 1142 OF 1240 ***

  // Wavefunction(s) for diagram number 1142
  VVV1P0_1( w[68], w[6], COUPs[0], 0., 0., w[23] );
  VVV1P0_1( w[29], w[6], COUPs[0], 0., 0., w[60] );
  VVV1P0_1( w[10], w[6], COUPs[0], 0., 0., w[20] );

  // Amplitude(s) for diagram number 1142
  VVV1_0( w[8], w[4], w[23], COUPs[0], &amp[0] );
  jamp[3] += amp[0];
  jamp[13] -= amp[0];
  jamp[37] -= amp[0];
  jamp[48] -= amp[0];
  jamp[50] += amp[0];
  jamp[56] += amp[0];
  jamp[62] -= amp[0];
  jamp[66] += amp[0];
  jamp[67] -= amp[0];
  jamp[69] -= amp[0];
  jamp[71] += amp[0];
  jamp[79] += amp[0];
  jamp[97] -= amp[0];
  jamp[100] += amp[0];
  jamp[106] += amp[0];
  jamp[116] -= amp[0];
  VVV1_0( w[8], w[4], w[60], COUPs[0], &amp[0] );
  jamp[13] -= amp[0];
  jamp[27] += amp[0];
  jamp[37] -= amp[0];
  jamp[50] += amp[0];
  jamp[54] -= amp[0];
  jamp[56] += amp[0];
  jamp[60] -= amp[0];
  jamp[67] -= amp[0];
  jamp[68] += amp[0];
  jamp[69] -= amp[0];
  jamp[70] += amp[0];
  jamp[73] += amp[0];
  jamp[100] += amp[0];
  jamp[103] -= amp[0];
  jamp[106] += amp[0];
  jamp[114] -= amp[0];
  VVV1_0( w[8], w[4], w[20], COUPs[0], &amp[0] );
  jamp[3] -= amp[0];
  jamp[27] += amp[0];
  jamp[48] += amp[0];
  jamp[54] -= amp[0];
  jamp[60] -= amp[0];
  jamp[62] += amp[0];
  jamp[66] -= amp[0];
  jamp[68] += amp[0];
  jamp[70] += amp[0];
  jamp[71] -= amp[0];
  jamp[73] += amp[0];
  jamp[79] -= amp[0];
  jamp[97] += amp[0];
  jamp[103] -= amp[0];
  jamp[114] -= amp[0];
  jamp[116] += amp[0];

  // *** DIAGRAM 1143 OF 1240 ***

  // Wavefunction(s) for diagram number 1143
  // (none)

  // Amplitude(s) for diagram number 1143
  VVV1_0( w[68], w[8], w[27], COUPs[0], &amp[0] );
  jamp[2] += amp[0];
  jamp[3] -= amp[0];
  jamp[12] -= amp[0];
  jamp[13] += amp[0];
  jamp[36] -= amp[0];
  jamp[37] += amp[0];
  jamp[66] -= amp[0];
  jamp[67] += amp[0];
  jamp[69] += amp[0];
  jamp[71] -= amp[0];
  jamp[78] += amp[0];
  jamp[79] -= amp[0];
  jamp[108] += amp[0];
  jamp[109] -= amp[0];
  jamp[111] -= amp[0];
  jamp[113] += amp[0];
  VVV1_0( w[29], w[8], w[27], COUPs[0], &amp[0] );
  jamp[12] -= amp[0];
  jamp[13] += amp[0];
  jamp[26] += amp[0];
  jamp[27] -= amp[0];
  jamp[36] -= amp[0];
  jamp[37] += amp[0];
  jamp[67] += amp[0];
  jamp[68] -= amp[0];
  jamp[69] += amp[0];
  jamp[70] -= amp[0];
  jamp[72] += amp[0];
  jamp[73] -= amp[0];
  jamp[109] -= amp[0];
  jamp[110] += amp[0];
  jamp[111] -= amp[0];
  jamp[112] += amp[0];
  VVV1_0( w[10], w[8], w[27], COUPs[0], &amp[0] );
  jamp[2] -= amp[0];
  jamp[3] += amp[0];
  jamp[26] += amp[0];
  jamp[27] -= amp[0];
  jamp[66] += amp[0];
  jamp[68] -= amp[0];
  jamp[70] -= amp[0];
  jamp[71] += amp[0];
  jamp[72] += amp[0];
  jamp[73] -= amp[0];
  jamp[78] -= amp[0];
  jamp[79] += amp[0];
  jamp[108] -= amp[0];
  jamp[110] += amp[0];
  jamp[112] += amp[0];
  jamp[113] -= amp[0];

  // *** DIAGRAM 1144 OF 1240 ***

  // Wavefunction(s) for diagram number 1144
  FFV1_2( w[3], w[68], COUPs[1], cIPD[0], cIPD[1], w[59] );
  FFV1_2( w[3], w[29], COUPs[1], cIPD[0], cIPD[1], w[111] );
  FFV1_2( w[3], w[10], COUPs[1], cIPD[0], cIPD[1], w[98] );

  // Amplitude(s) for diagram number 1144
  FFV1_0( w[59], w[33], w[6], COUPs[1], &amp[0] );
  jamp[66] += amp[0];
  jamp[67] -= amp[0];
  jamp[69] -= amp[0];
  jamp[71] += amp[0];
  FFV1_0( w[111], w[33], w[6], COUPs[1], &amp[0] );
  jamp[67] -= amp[0];
  jamp[68] += amp[0];
  jamp[69] -= amp[0];
  jamp[70] += amp[0];
  FFV1_0( w[98], w[33], w[6], COUPs[1], &amp[0] );
  jamp[66] -= amp[0];
  jamp[68] += amp[0];
  jamp[70] += amp[0];
  jamp[71] -= amp[0];

  // *** DIAGRAM 1145 OF 1240 ***

  // Wavefunction(s) for diagram number 1145
  // (none)

  // Amplitude(s) for diagram number 1145
  FFV1_0( w[3], w[33], w[23], COUPs[1], &amp[0] );
  jamp[48] -= cxtype( 0, 1 ) * amp[0];
  jamp[50] += cxtype( 0, 1 ) * amp[0];
  jamp[56] += cxtype( 0, 1 ) * amp[0];
  jamp[62] -= cxtype( 0, 1 ) * amp[0];
  jamp[66] += cxtype( 0, 1 ) * amp[0];
  jamp[67] -= cxtype( 0, 1 ) * amp[0];
  jamp[69] -= cxtype( 0, 1 ) * amp[0];
  jamp[71] += cxtype( 0, 1 ) * amp[0];
  FFV1_0( w[3], w[33], w[60], COUPs[1], &amp[0] );
  jamp[50] += cxtype( 0, 1 ) * amp[0];
  jamp[54] -= cxtype( 0, 1 ) * amp[0];
  jamp[56] += cxtype( 0, 1 ) * amp[0];
  jamp[60] -= cxtype( 0, 1 ) * amp[0];
  jamp[67] -= cxtype( 0, 1 ) * amp[0];
  jamp[68] += cxtype( 0, 1 ) * amp[0];
  jamp[69] -= cxtype( 0, 1 ) * amp[0];
  jamp[70] += cxtype( 0, 1 ) * amp[0];
  FFV1_0( w[3], w[33], w[20], COUPs[1], &amp[0] );
  jamp[48] += cxtype( 0, 1 ) * amp[0];
  jamp[54] -= cxtype( 0, 1 ) * amp[0];
  jamp[60] -= cxtype( 0, 1 ) * amp[0];
  jamp[62] += cxtype( 0, 1 ) * amp[0];
  jamp[66] -= cxtype( 0, 1 ) * amp[0];
  jamp[68] += cxtype( 0, 1 ) * amp[0];
  jamp[70] += cxtype( 0, 1 ) * amp[0];
  jamp[71] -= cxtype( 0, 1 ) * amp[0];

  // *** DIAGRAM 1146 OF 1240 ***

  // Wavefunction(s) for diagram number 1146
  // (none)

  // Amplitude(s) for diagram number 1146
  FFV1_0( w[41], w[33], w[68], COUPs[1], &amp[0] );
  jamp[48] += amp[0];
  jamp[50] -= amp[0];
  jamp[56] -= amp[0];
  jamp[62] += amp[0];
  FFV1_0( w[41], w[33], w[29], COUPs[1], &amp[0] );
  jamp[50] -= amp[0];
  jamp[54] += amp[0];
  jamp[56] -= amp[0];
  jamp[60] += amp[0];
  FFV1_0( w[41], w[33], w[10], COUPs[1], &amp[0] );
  jamp[48] -= amp[0];
  jamp[54] += amp[0];
  jamp[60] += amp[0];
  jamp[62] -= amp[0];

  // *** DIAGRAM 1147 OF 1240 ***

  // Wavefunction(s) for diagram number 1147
  // (none)

  // Amplitude(s) for diagram number 1147
  FFV1_0( w[59], w[47], w[4], COUPs[1], &amp[0] );
  jamp[108] += amp[0];
  jamp[109] -= amp[0];
  jamp[111] -= amp[0];
  jamp[113] += amp[0];
  FFV1_0( w[111], w[47], w[4], COUPs[1], &amp[0] );
  jamp[109] -= amp[0];
  jamp[110] += amp[0];
  jamp[111] -= amp[0];
  jamp[112] += amp[0];
  FFV1_0( w[98], w[47], w[4], COUPs[1], &amp[0] );
  jamp[108] -= amp[0];
  jamp[110] += amp[0];
  jamp[112] += amp[0];
  jamp[113] -= amp[0];

  // *** DIAGRAM 1148 OF 1240 ***

  // Wavefunction(s) for diagram number 1148
  // (none)

  // Amplitude(s) for diagram number 1148
  FFV1_0( w[3], w[47], w[16], COUPs[1], &amp[0] );
  jamp[97] -= cxtype( 0, 1 ) * amp[0];
  jamp[100] += cxtype( 0, 1 ) * amp[0];
  jamp[106] += cxtype( 0, 1 ) * amp[0];
  jamp[108] += cxtype( 0, 1 ) * amp[0];
  jamp[109] -= cxtype( 0, 1 ) * amp[0];
  jamp[111] -= cxtype( 0, 1 ) * amp[0];
  jamp[113] += cxtype( 0, 1 ) * amp[0];
  jamp[116] -= cxtype( 0, 1 ) * amp[0];
  FFV1_0( w[3], w[47], w[71], COUPs[1], &amp[0] );
  jamp[100] += cxtype( 0, 1 ) * amp[0];
  jamp[103] -= cxtype( 0, 1 ) * amp[0];
  jamp[106] += cxtype( 0, 1 ) * amp[0];
  jamp[109] -= cxtype( 0, 1 ) * amp[0];
  jamp[110] += cxtype( 0, 1 ) * amp[0];
  jamp[111] -= cxtype( 0, 1 ) * amp[0];
  jamp[112] += cxtype( 0, 1 ) * amp[0];
  jamp[114] -= cxtype( 0, 1 ) * amp[0];
  FFV1_0( w[3], w[47], w[21], COUPs[1], &amp[0] );
  jamp[97] += cxtype( 0, 1 ) * amp[0];
  jamp[103] -= cxtype( 0, 1 ) * amp[0];
  jamp[108] -= cxtype( 0, 1 ) * amp[0];
  jamp[110] += cxtype( 0, 1 ) * amp[0];
  jamp[112] += cxtype( 0, 1 ) * amp[0];
  jamp[113] -= cxtype( 0, 1 ) * amp[0];
  jamp[114] -= cxtype( 0, 1 ) * amp[0];
  jamp[116] += cxtype( 0, 1 ) * amp[0];

  // *** DIAGRAM 1149 OF 1240 ***

  // Wavefunction(s) for diagram number 1149
  // (none)

  // Amplitude(s) for diagram number 1149
  FFV1_0( w[46], w[47], w[68], COUPs[1], &amp[0] );
  jamp[97] += amp[0];
  jamp[100] -= amp[0];
  jamp[106] -= amp[0];
  jamp[116] += amp[0];
  FFV1_0( w[46], w[47], w[29], COUPs[1], &amp[0] );
  jamp[100] -= amp[0];
  jamp[103] += amp[0];
  jamp[106] -= amp[0];
  jamp[114] += amp[0];
  FFV1_0( w[46], w[47], w[10], COUPs[1], &amp[0] );
  jamp[97] -= amp[0];
  jamp[103] += amp[0];
  jamp[114] += amp[0];
  jamp[116] -= amp[0];

  // *** DIAGRAM 1150 OF 1240 ***

  // Wavefunction(s) for diagram number 1150
  FFV1_1( w[2], w[68], COUPs[1], cIPD[0], cIPD[1], w[17] );
  FFV1_1( w[2], w[29], COUPs[1], cIPD[0], cIPD[1], w[68] );
  FFV1_1( w[2], w[10], COUPs[1], cIPD[0], cIPD[1], w[29] );

  // Amplitude(s) for diagram number 1150
  FFV1_0( w[46], w[17], w[6], COUPs[1], &amp[0] );
  jamp[3] += amp[0];
  jamp[13] -= amp[0];
  jamp[37] -= amp[0];
  jamp[79] += amp[0];
  FFV1_0( w[46], w[68], w[6], COUPs[1], &amp[0] );
  jamp[13] -= amp[0];
  jamp[27] += amp[0];
  jamp[37] -= amp[0];
  jamp[73] += amp[0];
  FFV1_0( w[46], w[29], w[6], COUPs[1], &amp[0] );
  jamp[3] -= amp[0];
  jamp[27] += amp[0];
  jamp[73] += amp[0];
  jamp[79] -= amp[0];

  // *** DIAGRAM 1151 OF 1240 ***

  // Wavefunction(s) for diagram number 1151
  // (none)

  // Amplitude(s) for diagram number 1151
  FFV1_0( w[46], w[2], w[23], COUPs[1], &amp[0] );
  jamp[3] -= cxtype( 0, 1 ) * amp[0];
  jamp[13] += cxtype( 0, 1 ) * amp[0];
  jamp[37] += cxtype( 0, 1 ) * amp[0];
  jamp[79] -= cxtype( 0, 1 ) * amp[0];
  jamp[97] += cxtype( 0, 1 ) * amp[0];
  jamp[100] -= cxtype( 0, 1 ) * amp[0];
  jamp[106] -= cxtype( 0, 1 ) * amp[0];
  jamp[116] += cxtype( 0, 1 ) * amp[0];
  FFV1_0( w[46], w[2], w[60], COUPs[1], &amp[0] );
  jamp[13] += cxtype( 0, 1 ) * amp[0];
  jamp[27] -= cxtype( 0, 1 ) * amp[0];
  jamp[37] += cxtype( 0, 1 ) * amp[0];
  jamp[73] -= cxtype( 0, 1 ) * amp[0];
  jamp[100] -= cxtype( 0, 1 ) * amp[0];
  jamp[103] += cxtype( 0, 1 ) * amp[0];
  jamp[106] -= cxtype( 0, 1 ) * amp[0];
  jamp[114] += cxtype( 0, 1 ) * amp[0];
  FFV1_0( w[46], w[2], w[20], COUPs[1], &amp[0] );
  jamp[3] += cxtype( 0, 1 ) * amp[0];
  jamp[27] -= cxtype( 0, 1 ) * amp[0];
  jamp[73] -= cxtype( 0, 1 ) * amp[0];
  jamp[79] += cxtype( 0, 1 ) * amp[0];
  jamp[97] -= cxtype( 0, 1 ) * amp[0];
  jamp[103] += cxtype( 0, 1 ) * amp[0];
  jamp[114] += cxtype( 0, 1 ) * amp[0];
  jamp[116] -= cxtype( 0, 1 ) * amp[0];

  // *** DIAGRAM 1152 OF 1240 ***

  // Wavefunction(s) for diagram number 1152
  // (none)

  // Amplitude(s) for diagram number 1152
  FFV1_0( w[41], w[17], w[4], COUPs[1], &amp[0] );
  jamp[2] += amp[0];
  jamp[12] -= amp[0];
  jamp[36] -= amp[0];
  jamp[78] += amp[0];
  FFV1_0( w[41], w[68], w[4], COUPs[1], &amp[0] );
  jamp[12] -= amp[0];
  jamp[26] += amp[0];
  jamp[36] -= amp[0];
  jamp[72] += amp[0];
  FFV1_0( w[41], w[29], w[4], COUPs[1], &amp[0] );
  jamp[2] -= amp[0];
  jamp[26] += amp[0];
  jamp[72] += amp[0];
  jamp[78] -= amp[0];

  // *** DIAGRAM 1153 OF 1240 ***

  // Wavefunction(s) for diagram number 1153
  // (none)

  // Amplitude(s) for diagram number 1153
  FFV1_0( w[41], w[2], w[16], COUPs[1], &amp[0] );
  jamp[2] -= cxtype( 0, 1 ) * amp[0];
  jamp[12] += cxtype( 0, 1 ) * amp[0];
  jamp[36] += cxtype( 0, 1 ) * amp[0];
  jamp[48] += cxtype( 0, 1 ) * amp[0];
  jamp[50] -= cxtype( 0, 1 ) * amp[0];
  jamp[56] -= cxtype( 0, 1 ) * amp[0];
  jamp[62] += cxtype( 0, 1 ) * amp[0];
  jamp[78] -= cxtype( 0, 1 ) * amp[0];
  FFV1_0( w[41], w[2], w[71], COUPs[1], &amp[0] );
  jamp[12] += cxtype( 0, 1 ) * amp[0];
  jamp[26] -= cxtype( 0, 1 ) * amp[0];
  jamp[36] += cxtype( 0, 1 ) * amp[0];
  jamp[50] -= cxtype( 0, 1 ) * amp[0];
  jamp[54] += cxtype( 0, 1 ) * amp[0];
  jamp[56] -= cxtype( 0, 1 ) * amp[0];
  jamp[60] += cxtype( 0, 1 ) * amp[0];
  jamp[72] -= cxtype( 0, 1 ) * amp[0];
  FFV1_0( w[41], w[2], w[21], COUPs[1], &amp[0] );
  jamp[2] += cxtype( 0, 1 ) * amp[0];
  jamp[26] -= cxtype( 0, 1 ) * amp[0];
  jamp[48] -= cxtype( 0, 1 ) * amp[0];
  jamp[54] += cxtype( 0, 1 ) * amp[0];
  jamp[60] += cxtype( 0, 1 ) * amp[0];
  jamp[62] -= cxtype( 0, 1 ) * amp[0];
  jamp[72] -= cxtype( 0, 1 ) * amp[0];
  jamp[78] += cxtype( 0, 1 ) * amp[0];

  // *** DIAGRAM 1154 OF 1240 ***

  // Wavefunction(s) for diagram number 1154
  // (none)

  // Amplitude(s) for diagram number 1154
  FFV1_0( w[3], w[17], w[27], COUPs[1], &amp[0] );
  jamp[2] -= cxtype( 0, 1 ) * amp[0];
  jamp[3] += cxtype( 0, 1 ) * amp[0];
  jamp[12] += cxtype( 0, 1 ) * amp[0];
  jamp[13] -= cxtype( 0, 1 ) * amp[0];
  jamp[36] += cxtype( 0, 1 ) * amp[0];
  jamp[37] -= cxtype( 0, 1 ) * amp[0];
  jamp[78] -= cxtype( 0, 1 ) * amp[0];
  jamp[79] += cxtype( 0, 1 ) * amp[0];
  FFV1_0( w[3], w[68], w[27], COUPs[1], &amp[0] );
  jamp[12] += cxtype( 0, 1 ) * amp[0];
  jamp[13] -= cxtype( 0, 1 ) * amp[0];
  jamp[26] -= cxtype( 0, 1 ) * amp[0];
  jamp[27] += cxtype( 0, 1 ) * amp[0];
  jamp[36] += cxtype( 0, 1 ) * amp[0];
  jamp[37] -= cxtype( 0, 1 ) * amp[0];
  jamp[72] -= cxtype( 0, 1 ) * amp[0];
  jamp[73] += cxtype( 0, 1 ) * amp[0];
  FFV1_0( w[3], w[29], w[27], COUPs[1], &amp[0] );
  jamp[2] += cxtype( 0, 1 ) * amp[0];
  jamp[3] -= cxtype( 0, 1 ) * amp[0];
  jamp[26] -= cxtype( 0, 1 ) * amp[0];
  jamp[27] += cxtype( 0, 1 ) * amp[0];
  jamp[72] -= cxtype( 0, 1 ) * amp[0];
  jamp[73] += cxtype( 0, 1 ) * amp[0];
  jamp[78] += cxtype( 0, 1 ) * amp[0];
  jamp[79] -= cxtype( 0, 1 ) * amp[0];

  // *** DIAGRAM 1155 OF 1240 ***

  // Wavefunction(s) for diagram number 1155
  // (none)

  // Amplitude(s) for diagram number 1155
  FFV1_0( w[59], w[2], w[27], COUPs[1], &amp[0] );
  jamp[66] -= cxtype( 0, 1 ) * amp[0];
  jamp[67] += cxtype( 0, 1 ) * amp[0];
  jamp[69] += cxtype( 0, 1 ) * amp[0];
  jamp[71] -= cxtype( 0, 1 ) * amp[0];
  jamp[108] += cxtype( 0, 1 ) * amp[0];
  jamp[109] -= cxtype( 0, 1 ) * amp[0];
  jamp[111] -= cxtype( 0, 1 ) * amp[0];
  jamp[113] += cxtype( 0, 1 ) * amp[0];
  FFV1_0( w[111], w[2], w[27], COUPs[1], &amp[0] );
  jamp[67] += cxtype( 0, 1 ) * amp[0];
  jamp[68] -= cxtype( 0, 1 ) * amp[0];
  jamp[69] += cxtype( 0, 1 ) * amp[0];
  jamp[70] -= cxtype( 0, 1 ) * amp[0];
  jamp[109] -= cxtype( 0, 1 ) * amp[0];
  jamp[110] += cxtype( 0, 1 ) * amp[0];
  jamp[111] -= cxtype( 0, 1 ) * amp[0];
  jamp[112] += cxtype( 0, 1 ) * amp[0];
  FFV1_0( w[98], w[2], w[27], COUPs[1], &amp[0] );
  jamp[66] += cxtype( 0, 1 ) * amp[0];
  jamp[68] -= cxtype( 0, 1 ) * amp[0];
  jamp[70] -= cxtype( 0, 1 ) * amp[0];
  jamp[71] += cxtype( 0, 1 ) * amp[0];
  jamp[108] -= cxtype( 0, 1 ) * amp[0];
  jamp[110] += cxtype( 0, 1 ) * amp[0];
  jamp[112] += cxtype( 0, 1 ) * amp[0];
  jamp[113] -= cxtype( 0, 1 ) * amp[0];

  // *** DIAGRAM 1156 OF 1240 ***

  // Wavefunction(s) for diagram number 1156
  VVVV1P0_1( w[0], w[1], w[6], COUPs[2], 0., 0., w[98] );
  VVVV3P0_1( w[0], w[1], w[6], COUPs[2], 0., 0., w[27] );
  VVVV4P0_1( w[0], w[1], w[6], COUPs[2], 0., 0., w[111] );

  // Amplitude(s) for diagram number 1156
  VVVV1_0( w[98], w[8], w[4], w[5], COUPs[2], &amp[0] );
  jamp[4] += amp[0];
  jamp[5] -= amp[0];
  jamp[18] -= amp[0];
  jamp[19] += amp[0];
  jamp[42] -= amp[0];
  jamp[43] += amp[0];
  jamp[60] -= amp[0];
  jamp[61] += amp[0];
  jamp[63] += amp[0];
  jamp[65] -= amp[0];
  jamp[84] += amp[0];
  jamp[85] -= amp[0];
  jamp[87] -= amp[0];
  jamp[89] += amp[0];
  jamp[102] += amp[0];
  jamp[103] -= amp[0];
  VVVV3_0( w[98], w[8], w[4], w[5], COUPs[2], &amp[0] );
  jamp[4] += amp[0];
  jamp[18] -= amp[0];
  jamp[42] -= amp[0];
  jamp[49] -= amp[0];
  jamp[52] += amp[0];
  jamp[58] += amp[0];
  jamp[68] -= amp[0];
  jamp[73] -= amp[0];
  jamp[76] += amp[0];
  jamp[82] += amp[0];
  jamp[84] += amp[0];
  jamp[85] -= amp[0];
  jamp[87] -= amp[0];
  jamp[89] += amp[0];
  jamp[92] -= amp[0];
  jamp[102] += amp[0];
  VVVV4_0( w[98], w[8], w[4], w[5], COUPs[2], &amp[0] );
  jamp[5] += amp[0];
  jamp[19] -= amp[0];
  jamp[43] -= amp[0];
  jamp[49] -= amp[0];
  jamp[52] += amp[0];
  jamp[58] += amp[0];
  jamp[60] += amp[0];
  jamp[61] -= amp[0];
  jamp[63] -= amp[0];
  jamp[65] += amp[0];
  jamp[68] -= amp[0];
  jamp[73] -= amp[0];
  jamp[76] += amp[0];
  jamp[82] += amp[0];
  jamp[92] -= amp[0];
  jamp[103] += amp[0];
  VVVV1_0( w[27], w[8], w[4], w[5], COUPs[2], &amp[0] );
  jamp[18] -= amp[0];
  jamp[19] += amp[0];
  jamp[28] += amp[0];
  jamp[29] -= amp[0];
  jamp[42] -= amp[0];
  jamp[43] += amp[0];
  jamp[61] += amp[0];
  jamp[62] -= amp[0];
  jamp[63] += amp[0];
  jamp[64] -= amp[0];
  jamp[85] -= amp[0];
  jamp[86] += amp[0];
  jamp[87] -= amp[0];
  jamp[88] += amp[0];
  jamp[96] += amp[0];
  jamp[97] -= amp[0];
  VVVV3_0( w[27], w[8], w[4], w[5], COUPs[2], &amp[0] );
  jamp[18] -= amp[0];
  jamp[28] += amp[0];
  jamp[42] -= amp[0];
  jamp[52] += amp[0];
  jamp[55] -= amp[0];
  jamp[58] += amp[0];
  jamp[66] -= amp[0];
  jamp[76] += amp[0];
  jamp[79] -= amp[0];
  jamp[82] += amp[0];
  jamp[85] -= amp[0];
  jamp[86] += amp[0];
  jamp[87] -= amp[0];
  jamp[88] += amp[0];
  jamp[90] -= amp[0];
  jamp[96] += amp[0];
  VVVV4_0( w[27], w[8], w[4], w[5], COUPs[2], &amp[0] );
  jamp[19] -= amp[0];
  jamp[29] += amp[0];
  jamp[43] -= amp[0];
  jamp[52] += amp[0];
  jamp[55] -= amp[0];
  jamp[58] += amp[0];
  jamp[61] -= amp[0];
  jamp[62] += amp[0];
  jamp[63] -= amp[0];
  jamp[64] += amp[0];
  jamp[66] -= amp[0];
  jamp[76] += amp[0];
  jamp[79] -= amp[0];
  jamp[82] += amp[0];
  jamp[90] -= amp[0];
  jamp[97] += amp[0];
  VVVV1_0( w[111], w[8], w[4], w[5], COUPs[2], &amp[0] );
  jamp[4] -= amp[0];
  jamp[5] += amp[0];
  jamp[28] += amp[0];
  jamp[29] -= amp[0];
  jamp[60] += amp[0];
  jamp[62] -= amp[0];
  jamp[64] -= amp[0];
  jamp[65] += amp[0];
  jamp[84] -= amp[0];
  jamp[86] += amp[0];
  jamp[88] += amp[0];
  jamp[89] -= amp[0];
  jamp[96] += amp[0];
  jamp[97] -= amp[0];
  jamp[102] -= amp[0];
  jamp[103] += amp[0];
  VVVV3_0( w[111], w[8], w[4], w[5], COUPs[2], &amp[0] );
  jamp[4] -= amp[0];
  jamp[28] += amp[0];
  jamp[49] += amp[0];
  jamp[55] -= amp[0];
  jamp[66] -= amp[0];
  jamp[68] += amp[0];
  jamp[73] += amp[0];
  jamp[79] -= amp[0];
  jamp[84] -= amp[0];
  jamp[86] += amp[0];
  jamp[88] += amp[0];
  jamp[89] -= amp[0];
  jamp[90] -= amp[0];
  jamp[92] += amp[0];
  jamp[96] += amp[0];
  jamp[102] -= amp[0];
  VVVV4_0( w[111], w[8], w[4], w[5], COUPs[2], &amp[0] );
  jamp[5] -= amp[0];
  jamp[29] += amp[0];
  jamp[49] += amp[0];
  jamp[55] -= amp[0];
  jamp[60] -= amp[0];
  jamp[62] += amp[0];
  jamp[64] += amp[0];
  jamp[65] -= amp[0];
  jamp[66] -= amp[0];
  jamp[68] += amp[0];
  jamp[73] += amp[0];
  jamp[79] -= amp[0];
  jamp[90] -= amp[0];
  jamp[92] += amp[0];
  jamp[97] += amp[0];
  jamp[103] -= amp[0];

  // *** DIAGRAM 1157 OF 1240 ***

  // Wavefunction(s) for diagram number 1157
  VVV1P0_1( w[98], w[4], COUPs[0], 0., 0., w[59] );
  VVV1P0_1( w[27], w[4], COUPs[0], 0., 0., w[29] );
  VVV1P0_1( w[111], w[4], COUPs[0], 0., 0., w[68] );

  // Amplitude(s) for diagram number 1157
  VVV1_0( w[8], w[5], w[59], COUPs[0], &amp[0] );
  jamp[4] += amp[0];
  jamp[18] -= amp[0];
  jamp[42] -= amp[0];
  jamp[49] -= amp[0];
  jamp[52] += amp[0];
  jamp[58] += amp[0];
  jamp[68] -= amp[0];
  jamp[73] -= amp[0];
  jamp[76] += amp[0];
  jamp[82] += amp[0];
  jamp[84] += amp[0];
  jamp[85] -= amp[0];
  jamp[87] -= amp[0];
  jamp[89] += amp[0];
  jamp[92] -= amp[0];
  jamp[102] += amp[0];
  VVV1_0( w[8], w[5], w[29], COUPs[0], &amp[0] );
  jamp[18] -= amp[0];
  jamp[28] += amp[0];
  jamp[42] -= amp[0];
  jamp[52] += amp[0];
  jamp[55] -= amp[0];
  jamp[58] += amp[0];
  jamp[66] -= amp[0];
  jamp[76] += amp[0];
  jamp[79] -= amp[0];
  jamp[82] += amp[0];
  jamp[85] -= amp[0];
  jamp[86] += amp[0];
  jamp[87] -= amp[0];
  jamp[88] += amp[0];
  jamp[90] -= amp[0];
  jamp[96] += amp[0];
  VVV1_0( w[8], w[5], w[68], COUPs[0], &amp[0] );
  jamp[4] -= amp[0];
  jamp[28] += amp[0];
  jamp[49] += amp[0];
  jamp[55] -= amp[0];
  jamp[66] -= amp[0];
  jamp[68] += amp[0];
  jamp[73] += amp[0];
  jamp[79] -= amp[0];
  jamp[84] -= amp[0];
  jamp[86] += amp[0];
  jamp[88] += amp[0];
  jamp[89] -= amp[0];
  jamp[90] -= amp[0];
  jamp[92] += amp[0];
  jamp[96] += amp[0];
  jamp[102] -= amp[0];

  // *** DIAGRAM 1158 OF 1240 ***

  // Wavefunction(s) for diagram number 1158
  VVV1P0_1( w[98], w[5], COUPs[0], 0., 0., w[17] );
  VVV1P0_1( w[27], w[5], COUPs[0], 0., 0., w[21] );
  VVV1P0_1( w[111], w[5], COUPs[0], 0., 0., w[71] );

  // Amplitude(s) for diagram number 1158
  VVV1_0( w[8], w[4], w[17], COUPs[0], &amp[0] );
  jamp[5] += amp[0];
  jamp[19] -= amp[0];
  jamp[43] -= amp[0];
  jamp[49] -= amp[0];
  jamp[52] += amp[0];
  jamp[58] += amp[0];
  jamp[60] += amp[0];
  jamp[61] -= amp[0];
  jamp[63] -= amp[0];
  jamp[65] += amp[0];
  jamp[68] -= amp[0];
  jamp[73] -= amp[0];
  jamp[76] += amp[0];
  jamp[82] += amp[0];
  jamp[92] -= amp[0];
  jamp[103] += amp[0];
  VVV1_0( w[8], w[4], w[21], COUPs[0], &amp[0] );
  jamp[19] -= amp[0];
  jamp[29] += amp[0];
  jamp[43] -= amp[0];
  jamp[52] += amp[0];
  jamp[55] -= amp[0];
  jamp[58] += amp[0];
  jamp[61] -= amp[0];
  jamp[62] += amp[0];
  jamp[63] -= amp[0];
  jamp[64] += amp[0];
  jamp[66] -= amp[0];
  jamp[76] += amp[0];
  jamp[79] -= amp[0];
  jamp[82] += amp[0];
  jamp[90] -= amp[0];
  jamp[97] += amp[0];
  VVV1_0( w[8], w[4], w[71], COUPs[0], &amp[0] );
  jamp[5] -= amp[0];
  jamp[29] += amp[0];
  jamp[49] += amp[0];
  jamp[55] -= amp[0];
  jamp[60] -= amp[0];
  jamp[62] += amp[0];
  jamp[64] += amp[0];
  jamp[65] -= amp[0];
  jamp[66] -= amp[0];
  jamp[68] += amp[0];
  jamp[73] += amp[0];
  jamp[79] -= amp[0];
  jamp[90] -= amp[0];
  jamp[92] += amp[0];
  jamp[97] += amp[0];
  jamp[103] -= amp[0];

  // *** DIAGRAM 1159 OF 1240 ***

  // Wavefunction(s) for diagram number 1159
  // (none)

  // Amplitude(s) for diagram number 1159
  VVV1_0( w[98], w[8], w[24], COUPs[0], &amp[0] );
  jamp[4] += amp[0];
  jamp[5] -= amp[0];
  jamp[18] -= amp[0];
  jamp[19] += amp[0];
  jamp[42] -= amp[0];
  jamp[43] += amp[0];
  jamp[60] -= amp[0];
  jamp[61] += amp[0];
  jamp[63] += amp[0];
  jamp[65] -= amp[0];
  jamp[84] += amp[0];
  jamp[85] -= amp[0];
  jamp[87] -= amp[0];
  jamp[89] += amp[0];
  jamp[102] += amp[0];
  jamp[103] -= amp[0];
  VVV1_0( w[27], w[8], w[24], COUPs[0], &amp[0] );
  jamp[18] -= amp[0];
  jamp[19] += amp[0];
  jamp[28] += amp[0];
  jamp[29] -= amp[0];
  jamp[42] -= amp[0];
  jamp[43] += amp[0];
  jamp[61] += amp[0];
  jamp[62] -= amp[0];
  jamp[63] += amp[0];
  jamp[64] -= amp[0];
  jamp[85] -= amp[0];
  jamp[86] += amp[0];
  jamp[87] -= amp[0];
  jamp[88] += amp[0];
  jamp[96] += amp[0];
  jamp[97] -= amp[0];
  VVV1_0( w[111], w[8], w[24], COUPs[0], &amp[0] );
  jamp[4] -= amp[0];
  jamp[5] += amp[0];
  jamp[28] += amp[0];
  jamp[29] -= amp[0];
  jamp[60] += amp[0];
  jamp[62] -= amp[0];
  jamp[64] -= amp[0];
  jamp[65] += amp[0];
  jamp[84] -= amp[0];
  jamp[86] += amp[0];
  jamp[88] += amp[0];
  jamp[89] -= amp[0];
  jamp[96] += amp[0];
  jamp[97] -= amp[0];
  jamp[102] -= amp[0];
  jamp[103] += amp[0];

  // *** DIAGRAM 1160 OF 1240 ***

  // Wavefunction(s) for diagram number 1160
  FFV1_2( w[3], w[98], COUPs[1], cIPD[0], cIPD[1], w[16] );
  FFV1_2( w[3], w[27], COUPs[1], cIPD[0], cIPD[1], w[20] );
  FFV1_2( w[3], w[111], COUPs[1], cIPD[0], cIPD[1], w[60] );

  // Amplitude(s) for diagram number 1160
  FFV1_0( w[16], w[33], w[5], COUPs[1], &amp[0] );
  jamp[60] += amp[0];
  jamp[61] -= amp[0];
  jamp[63] -= amp[0];
  jamp[65] += amp[0];
  FFV1_0( w[20], w[33], w[5], COUPs[1], &amp[0] );
  jamp[61] -= amp[0];
  jamp[62] += amp[0];
  jamp[63] -= amp[0];
  jamp[64] += amp[0];
  FFV1_0( w[60], w[33], w[5], COUPs[1], &amp[0] );
  jamp[60] -= amp[0];
  jamp[62] += amp[0];
  jamp[64] += amp[0];
  jamp[65] -= amp[0];

  // *** DIAGRAM 1161 OF 1240 ***

  // Wavefunction(s) for diagram number 1161
  // (none)

  // Amplitude(s) for diagram number 1161
  FFV1_0( w[3], w[33], w[17], COUPs[1], &amp[0] );
  jamp[49] -= cxtype( 0, 1 ) * amp[0];
  jamp[52] += cxtype( 0, 1 ) * amp[0];
  jamp[58] += cxtype( 0, 1 ) * amp[0];
  jamp[60] += cxtype( 0, 1 ) * amp[0];
  jamp[61] -= cxtype( 0, 1 ) * amp[0];
  jamp[63] -= cxtype( 0, 1 ) * amp[0];
  jamp[65] += cxtype( 0, 1 ) * amp[0];
  jamp[68] -= cxtype( 0, 1 ) * amp[0];
  FFV1_0( w[3], w[33], w[21], COUPs[1], &amp[0] );
  jamp[52] += cxtype( 0, 1 ) * amp[0];
  jamp[55] -= cxtype( 0, 1 ) * amp[0];
  jamp[58] += cxtype( 0, 1 ) * amp[0];
  jamp[61] -= cxtype( 0, 1 ) * amp[0];
  jamp[62] += cxtype( 0, 1 ) * amp[0];
  jamp[63] -= cxtype( 0, 1 ) * amp[0];
  jamp[64] += cxtype( 0, 1 ) * amp[0];
  jamp[66] -= cxtype( 0, 1 ) * amp[0];
  FFV1_0( w[3], w[33], w[71], COUPs[1], &amp[0] );
  jamp[49] += cxtype( 0, 1 ) * amp[0];
  jamp[55] -= cxtype( 0, 1 ) * amp[0];
  jamp[60] -= cxtype( 0, 1 ) * amp[0];
  jamp[62] += cxtype( 0, 1 ) * amp[0];
  jamp[64] += cxtype( 0, 1 ) * amp[0];
  jamp[65] -= cxtype( 0, 1 ) * amp[0];
  jamp[66] -= cxtype( 0, 1 ) * amp[0];
  jamp[68] += cxtype( 0, 1 ) * amp[0];

  // *** DIAGRAM 1162 OF 1240 ***

  // Wavefunction(s) for diagram number 1162
  // (none)

  // Amplitude(s) for diagram number 1162
  FFV1_0( w[38], w[33], w[98], COUPs[1], &amp[0] );
  jamp[49] += amp[0];
  jamp[52] -= amp[0];
  jamp[58] -= amp[0];
  jamp[68] += amp[0];
  FFV1_0( w[38], w[33], w[27], COUPs[1], &amp[0] );
  jamp[52] -= amp[0];
  jamp[55] += amp[0];
  jamp[58] -= amp[0];
  jamp[66] += amp[0];
  FFV1_0( w[38], w[33], w[111], COUPs[1], &amp[0] );
  jamp[49] -= amp[0];
  jamp[55] += amp[0];
  jamp[66] += amp[0];
  jamp[68] -= amp[0];

  // *** DIAGRAM 1163 OF 1240 ***

  // Wavefunction(s) for diagram number 1163
  // (none)

  // Amplitude(s) for diagram number 1163
  FFV1_0( w[16], w[39], w[4], COUPs[1], &amp[0] );
  jamp[84] += amp[0];
  jamp[85] -= amp[0];
  jamp[87] -= amp[0];
  jamp[89] += amp[0];
  FFV1_0( w[20], w[39], w[4], COUPs[1], &amp[0] );
  jamp[85] -= amp[0];
  jamp[86] += amp[0];
  jamp[87] -= amp[0];
  jamp[88] += amp[0];
  FFV1_0( w[60], w[39], w[4], COUPs[1], &amp[0] );
  jamp[84] -= amp[0];
  jamp[86] += amp[0];
  jamp[88] += amp[0];
  jamp[89] -= amp[0];

  // *** DIAGRAM 1164 OF 1240 ***

  // Wavefunction(s) for diagram number 1164
  // (none)

  // Amplitude(s) for diagram number 1164
  FFV1_0( w[3], w[39], w[59], COUPs[1], &amp[0] );
  jamp[73] -= cxtype( 0, 1 ) * amp[0];
  jamp[76] += cxtype( 0, 1 ) * amp[0];
  jamp[82] += cxtype( 0, 1 ) * amp[0];
  jamp[84] += cxtype( 0, 1 ) * amp[0];
  jamp[85] -= cxtype( 0, 1 ) * amp[0];
  jamp[87] -= cxtype( 0, 1 ) * amp[0];
  jamp[89] += cxtype( 0, 1 ) * amp[0];
  jamp[92] -= cxtype( 0, 1 ) * amp[0];
  FFV1_0( w[3], w[39], w[29], COUPs[1], &amp[0] );
  jamp[76] += cxtype( 0, 1 ) * amp[0];
  jamp[79] -= cxtype( 0, 1 ) * amp[0];
  jamp[82] += cxtype( 0, 1 ) * amp[0];
  jamp[85] -= cxtype( 0, 1 ) * amp[0];
  jamp[86] += cxtype( 0, 1 ) * amp[0];
  jamp[87] -= cxtype( 0, 1 ) * amp[0];
  jamp[88] += cxtype( 0, 1 ) * amp[0];
  jamp[90] -= cxtype( 0, 1 ) * amp[0];
  FFV1_0( w[3], w[39], w[68], COUPs[1], &amp[0] );
  jamp[73] += cxtype( 0, 1 ) * amp[0];
  jamp[79] -= cxtype( 0, 1 ) * amp[0];
  jamp[84] -= cxtype( 0, 1 ) * amp[0];
  jamp[86] += cxtype( 0, 1 ) * amp[0];
  jamp[88] += cxtype( 0, 1 ) * amp[0];
  jamp[89] -= cxtype( 0, 1 ) * amp[0];
  jamp[90] -= cxtype( 0, 1 ) * amp[0];
  jamp[92] += cxtype( 0, 1 ) * amp[0];

  // *** DIAGRAM 1165 OF 1240 ***

  // Wavefunction(s) for diagram number 1165
  // (none)

  // Amplitude(s) for diagram number 1165
  FFV1_0( w[46], w[39], w[98], COUPs[1], &amp[0] );
  jamp[73] += amp[0];
  jamp[76] -= amp[0];
  jamp[82] -= amp[0];
  jamp[92] += amp[0];
  FFV1_0( w[46], w[39], w[27], COUPs[1], &amp[0] );
  jamp[76] -= amp[0];
  jamp[79] += amp[0];
  jamp[82] -= amp[0];
  jamp[90] += amp[0];
  FFV1_0( w[46], w[39], w[111], COUPs[1], &amp[0] );
  jamp[73] -= amp[0];
  jamp[79] += amp[0];
  jamp[90] += amp[0];
  jamp[92] -= amp[0];

  // *** DIAGRAM 1166 OF 1240 ***

  // Wavefunction(s) for diagram number 1166
  FFV1_1( w[2], w[98], COUPs[1], cIPD[0], cIPD[1], w[23] );
  FFV1_1( w[2], w[27], COUPs[1], cIPD[0], cIPD[1], w[98] );
  FFV1_1( w[2], w[111], COUPs[1], cIPD[0], cIPD[1], w[27] );

  // Amplitude(s) for diagram number 1166
  FFV1_0( w[46], w[23], w[5], COUPs[1], &amp[0] );
  jamp[5] += amp[0];
  jamp[19] -= amp[0];
  jamp[43] -= amp[0];
  jamp[103] += amp[0];
  FFV1_0( w[46], w[98], w[5], COUPs[1], &amp[0] );
  jamp[19] -= amp[0];
  jamp[29] += amp[0];
  jamp[43] -= amp[0];
  jamp[97] += amp[0];
  FFV1_0( w[46], w[27], w[5], COUPs[1], &amp[0] );
  jamp[5] -= amp[0];
  jamp[29] += amp[0];
  jamp[97] += amp[0];
  jamp[103] -= amp[0];

  // *** DIAGRAM 1167 OF 1240 ***

  // Wavefunction(s) for diagram number 1167
  // (none)

  // Amplitude(s) for diagram number 1167
  FFV1_0( w[46], w[2], w[17], COUPs[1], &amp[0] );
  jamp[5] -= cxtype( 0, 1 ) * amp[0];
  jamp[19] += cxtype( 0, 1 ) * amp[0];
  jamp[43] += cxtype( 0, 1 ) * amp[0];
  jamp[73] += cxtype( 0, 1 ) * amp[0];
  jamp[76] -= cxtype( 0, 1 ) * amp[0];
  jamp[82] -= cxtype( 0, 1 ) * amp[0];
  jamp[92] += cxtype( 0, 1 ) * amp[0];
  jamp[103] -= cxtype( 0, 1 ) * amp[0];
  FFV1_0( w[46], w[2], w[21], COUPs[1], &amp[0] );
  jamp[19] += cxtype( 0, 1 ) * amp[0];
  jamp[29] -= cxtype( 0, 1 ) * amp[0];
  jamp[43] += cxtype( 0, 1 ) * amp[0];
  jamp[76] -= cxtype( 0, 1 ) * amp[0];
  jamp[79] += cxtype( 0, 1 ) * amp[0];
  jamp[82] -= cxtype( 0, 1 ) * amp[0];
  jamp[90] += cxtype( 0, 1 ) * amp[0];
  jamp[97] -= cxtype( 0, 1 ) * amp[0];
  FFV1_0( w[46], w[2], w[71], COUPs[1], &amp[0] );
  jamp[5] += cxtype( 0, 1 ) * amp[0];
  jamp[29] -= cxtype( 0, 1 ) * amp[0];
  jamp[73] -= cxtype( 0, 1 ) * amp[0];
  jamp[79] += cxtype( 0, 1 ) * amp[0];
  jamp[90] += cxtype( 0, 1 ) * amp[0];
  jamp[92] -= cxtype( 0, 1 ) * amp[0];
  jamp[97] -= cxtype( 0, 1 ) * amp[0];
  jamp[103] += cxtype( 0, 1 ) * amp[0];

  // *** DIAGRAM 1168 OF 1240 ***

  // Wavefunction(s) for diagram number 1168
  // (none)

  // Amplitude(s) for diagram number 1168
  FFV1_0( w[38], w[23], w[4], COUPs[1], &amp[0] );
  jamp[4] += amp[0];
  jamp[18] -= amp[0];
  jamp[42] -= amp[0];
  jamp[102] += amp[0];
  FFV1_0( w[38], w[98], w[4], COUPs[1], &amp[0] );
  jamp[18] -= amp[0];
  jamp[28] += amp[0];
  jamp[42] -= amp[0];
  jamp[96] += amp[0];
  FFV1_0( w[38], w[27], w[4], COUPs[1], &amp[0] );
  jamp[4] -= amp[0];
  jamp[28] += amp[0];
  jamp[96] += amp[0];
  jamp[102] -= amp[0];

  // *** DIAGRAM 1169 OF 1240 ***

  // Wavefunction(s) for diagram number 1169
  // (none)

  // Amplitude(s) for diagram number 1169
  FFV1_0( w[38], w[2], w[59], COUPs[1], &amp[0] );
  jamp[4] -= cxtype( 0, 1 ) * amp[0];
  jamp[18] += cxtype( 0, 1 ) * amp[0];
  jamp[42] += cxtype( 0, 1 ) * amp[0];
  jamp[49] += cxtype( 0, 1 ) * amp[0];
  jamp[52] -= cxtype( 0, 1 ) * amp[0];
  jamp[58] -= cxtype( 0, 1 ) * amp[0];
  jamp[68] += cxtype( 0, 1 ) * amp[0];
  jamp[102] -= cxtype( 0, 1 ) * amp[0];
  FFV1_0( w[38], w[2], w[29], COUPs[1], &amp[0] );
  jamp[18] += cxtype( 0, 1 ) * amp[0];
  jamp[28] -= cxtype( 0, 1 ) * amp[0];
  jamp[42] += cxtype( 0, 1 ) * amp[0];
  jamp[52] -= cxtype( 0, 1 ) * amp[0];
  jamp[55] += cxtype( 0, 1 ) * amp[0];
  jamp[58] -= cxtype( 0, 1 ) * amp[0];
  jamp[66] += cxtype( 0, 1 ) * amp[0];
  jamp[96] -= cxtype( 0, 1 ) * amp[0];
  FFV1_0( w[38], w[2], w[68], COUPs[1], &amp[0] );
  jamp[4] += cxtype( 0, 1 ) * amp[0];
  jamp[28] -= cxtype( 0, 1 ) * amp[0];
  jamp[49] -= cxtype( 0, 1 ) * amp[0];
  jamp[55] += cxtype( 0, 1 ) * amp[0];
  jamp[66] += cxtype( 0, 1 ) * amp[0];
  jamp[68] -= cxtype( 0, 1 ) * amp[0];
  jamp[96] -= cxtype( 0, 1 ) * amp[0];
  jamp[102] += cxtype( 0, 1 ) * amp[0];

  // *** DIAGRAM 1170 OF 1240 ***

  // Wavefunction(s) for diagram number 1170
  // (none)

  // Amplitude(s) for diagram number 1170
  FFV1_0( w[3], w[23], w[24], COUPs[1], &amp[0] );
  jamp[4] -= cxtype( 0, 1 ) * amp[0];
  jamp[5] += cxtype( 0, 1 ) * amp[0];
  jamp[18] += cxtype( 0, 1 ) * amp[0];
  jamp[19] -= cxtype( 0, 1 ) * amp[0];
  jamp[42] += cxtype( 0, 1 ) * amp[0];
  jamp[43] -= cxtype( 0, 1 ) * amp[0];
  jamp[102] -= cxtype( 0, 1 ) * amp[0];
  jamp[103] += cxtype( 0, 1 ) * amp[0];
  FFV1_0( w[3], w[98], w[24], COUPs[1], &amp[0] );
  jamp[18] += cxtype( 0, 1 ) * amp[0];
  jamp[19] -= cxtype( 0, 1 ) * amp[0];
  jamp[28] -= cxtype( 0, 1 ) * amp[0];
  jamp[29] += cxtype( 0, 1 ) * amp[0];
  jamp[42] += cxtype( 0, 1 ) * amp[0];
  jamp[43] -= cxtype( 0, 1 ) * amp[0];
  jamp[96] -= cxtype( 0, 1 ) * amp[0];
  jamp[97] += cxtype( 0, 1 ) * amp[0];
  FFV1_0( w[3], w[27], w[24], COUPs[1], &amp[0] );
  jamp[4] += cxtype( 0, 1 ) * amp[0];
  jamp[5] -= cxtype( 0, 1 ) * amp[0];
  jamp[28] -= cxtype( 0, 1 ) * amp[0];
  jamp[29] += cxtype( 0, 1 ) * amp[0];
  jamp[96] -= cxtype( 0, 1 ) * amp[0];
  jamp[97] += cxtype( 0, 1 ) * amp[0];
  jamp[102] += cxtype( 0, 1 ) * amp[0];
  jamp[103] -= cxtype( 0, 1 ) * amp[0];

  // *** DIAGRAM 1171 OF 1240 ***

  // Wavefunction(s) for diagram number 1171
  // (none)

  // Amplitude(s) for diagram number 1171
  FFV1_0( w[16], w[2], w[24], COUPs[1], &amp[0] );
  jamp[60] -= cxtype( 0, 1 ) * amp[0];
  jamp[61] += cxtype( 0, 1 ) * amp[0];
  jamp[63] += cxtype( 0, 1 ) * amp[0];
  jamp[65] -= cxtype( 0, 1 ) * amp[0];
  jamp[84] += cxtype( 0, 1 ) * amp[0];
  jamp[85] -= cxtype( 0, 1 ) * amp[0];
  jamp[87] -= cxtype( 0, 1 ) * amp[0];
  jamp[89] += cxtype( 0, 1 ) * amp[0];
  FFV1_0( w[20], w[2], w[24], COUPs[1], &amp[0] );
  jamp[61] += cxtype( 0, 1 ) * amp[0];
  jamp[62] -= cxtype( 0, 1 ) * amp[0];
  jamp[63] += cxtype( 0, 1 ) * amp[0];
  jamp[64] -= cxtype( 0, 1 ) * amp[0];
  jamp[85] -= cxtype( 0, 1 ) * amp[0];
  jamp[86] += cxtype( 0, 1 ) * amp[0];
  jamp[87] -= cxtype( 0, 1 ) * amp[0];
  jamp[88] += cxtype( 0, 1 ) * amp[0];
  FFV1_0( w[60], w[2], w[24], COUPs[1], &amp[0] );
  jamp[60] += cxtype( 0, 1 ) * amp[0];
  jamp[62] -= cxtype( 0, 1 ) * amp[0];
  jamp[64] -= cxtype( 0, 1 ) * amp[0];
  jamp[65] += cxtype( 0, 1 ) * amp[0];
  jamp[84] -= cxtype( 0, 1 ) * amp[0];
  jamp[86] += cxtype( 0, 1 ) * amp[0];
  jamp[88] += cxtype( 0, 1 ) * amp[0];
  jamp[89] -= cxtype( 0, 1 ) * amp[0];

  // *** DIAGRAM 1172 OF 1240 ***

  // Wavefunction(s) for diagram number 1172
  VVVV1P0_1( w[0], w[4], w[5], COUPs[2], 0., 0., w[60] );
  VVVV3P0_1( w[0], w[4], w[5], COUPs[2], 0., 0., w[24] );
  VVVV4P0_1( w[0], w[4], w[5], COUPs[2], 0., 0., w[20] );
  FFV1_2( w[3], w[60], COUPs[1], cIPD[0], cIPD[1], w[16] );
  FFV1_2( w[3], w[24], COUPs[1], cIPD[0], cIPD[1], w[27] );
  FFV1_2( w[3], w[20], COUPs[1], cIPD[0], cIPD[1], w[98] );

  // Amplitude(s) for diagram number 1172
  FFV1_0( w[16], w[77], w[6], COUPs[1], &amp[0] );
  jamp[42] += amp[0];
  jamp[43] -= amp[0];
  jamp[45] -= amp[0];
  jamp[47] += amp[0];
  FFV1_0( w[27], w[77], w[6], COUPs[1], &amp[0] );
  jamp[43] -= amp[0];
  jamp[44] += amp[0];
  jamp[45] -= amp[0];
  jamp[46] += amp[0];
  FFV1_0( w[98], w[77], w[6], COUPs[1], &amp[0] );
  jamp[42] -= amp[0];
  jamp[44] += amp[0];
  jamp[46] += amp[0];
  jamp[47] -= amp[0];

  // *** DIAGRAM 1173 OF 1240 ***

  // Wavefunction(s) for diagram number 1173
  VVV1P0_1( w[60], w[6], COUPs[0], 0., 0., w[23] );
  VVV1P0_1( w[24], w[6], COUPs[0], 0., 0., w[68] );
  VVV1P0_1( w[20], w[6], COUPs[0], 0., 0., w[29] );

  // Amplitude(s) for diagram number 1173
  FFV1_0( w[3], w[77], w[23], COUPs[1], &amp[0] );
  jamp[24] -= cxtype( 0, 1 ) * amp[0];
  jamp[26] += cxtype( 0, 1 ) * amp[0];
  jamp[32] += cxtype( 0, 1 ) * amp[0];
  jamp[38] -= cxtype( 0, 1 ) * amp[0];
  jamp[42] += cxtype( 0, 1 ) * amp[0];
  jamp[43] -= cxtype( 0, 1 ) * amp[0];
  jamp[45] -= cxtype( 0, 1 ) * amp[0];
  jamp[47] += cxtype( 0, 1 ) * amp[0];
  FFV1_0( w[3], w[77], w[68], COUPs[1], &amp[0] );
  jamp[26] += cxtype( 0, 1 ) * amp[0];
  jamp[30] -= cxtype( 0, 1 ) * amp[0];
  jamp[32] += cxtype( 0, 1 ) * amp[0];
  jamp[36] -= cxtype( 0, 1 ) * amp[0];
  jamp[43] -= cxtype( 0, 1 ) * amp[0];
  jamp[44] += cxtype( 0, 1 ) * amp[0];
  jamp[45] -= cxtype( 0, 1 ) * amp[0];
  jamp[46] += cxtype( 0, 1 ) * amp[0];
  FFV1_0( w[3], w[77], w[29], COUPs[1], &amp[0] );
  jamp[24] += cxtype( 0, 1 ) * amp[0];
  jamp[30] -= cxtype( 0, 1 ) * amp[0];
  jamp[36] -= cxtype( 0, 1 ) * amp[0];
  jamp[38] += cxtype( 0, 1 ) * amp[0];
  jamp[42] -= cxtype( 0, 1 ) * amp[0];
  jamp[44] += cxtype( 0, 1 ) * amp[0];
  jamp[46] += cxtype( 0, 1 ) * amp[0];
  jamp[47] -= cxtype( 0, 1 ) * amp[0];

  // *** DIAGRAM 1174 OF 1240 ***

  // Wavefunction(s) for diagram number 1174
  // (none)

  // Amplitude(s) for diagram number 1174
  FFV1_0( w[41], w[77], w[60], COUPs[1], &amp[0] );
  jamp[24] += amp[0];
  jamp[26] -= amp[0];
  jamp[32] -= amp[0];
  jamp[38] += amp[0];
  FFV1_0( w[41], w[77], w[24], COUPs[1], &amp[0] );
  jamp[26] -= amp[0];
  jamp[30] += amp[0];
  jamp[32] -= amp[0];
  jamp[36] += amp[0];
  FFV1_0( w[41], w[77], w[20], COUPs[1], &amp[0] );
  jamp[24] -= amp[0];
  jamp[30] += amp[0];
  jamp[36] += amp[0];
  jamp[38] -= amp[0];

  // *** DIAGRAM 1175 OF 1240 ***

  // Wavefunction(s) for diagram number 1175
  FFV1_1( w[2], w[60], COUPs[1], cIPD[0], cIPD[1], w[59] );
  FFV1_1( w[2], w[24], COUPs[1], cIPD[0], cIPD[1], w[71] );
  FFV1_1( w[2], w[20], COUPs[1], cIPD[0], cIPD[1], w[21] );

  // Amplitude(s) for diagram number 1175
  FFV1_0( w[52], w[59], w[6], COUPs[1], &amp[0] );
  jamp[9] += amp[0];
  jamp[15] -= amp[0];
  jamp[61] -= amp[0];
  jamp[85] += amp[0];
  FFV1_0( w[52], w[71], w[6], COUPs[1], &amp[0] );
  jamp[15] -= amp[0];
  jamp[51] += amp[0];
  jamp[61] -= amp[0];
  jamp[75] += amp[0];
  FFV1_0( w[52], w[21], w[6], COUPs[1], &amp[0] );
  jamp[9] -= amp[0];
  jamp[51] += amp[0];
  jamp[75] += amp[0];
  jamp[85] -= amp[0];

  // *** DIAGRAM 1176 OF 1240 ***

  // Wavefunction(s) for diagram number 1176
  // (none)

  // Amplitude(s) for diagram number 1176
  FFV1_0( w[52], w[2], w[23], COUPs[1], &amp[0] );
  jamp[9] -= cxtype( 0, 1 ) * amp[0];
  jamp[15] += cxtype( 0, 1 ) * amp[0];
  jamp[61] += cxtype( 0, 1 ) * amp[0];
  jamp[85] -= cxtype( 0, 1 ) * amp[0];
  jamp[99] += cxtype( 0, 1 ) * amp[0];
  jamp[101] -= cxtype( 0, 1 ) * amp[0];
  jamp[112] -= cxtype( 0, 1 ) * amp[0];
  jamp[118] += cxtype( 0, 1 ) * amp[0];
  FFV1_0( w[52], w[2], w[68], COUPs[1], &amp[0] );
  jamp[15] += cxtype( 0, 1 ) * amp[0];
  jamp[51] -= cxtype( 0, 1 ) * amp[0];
  jamp[61] += cxtype( 0, 1 ) * amp[0];
  jamp[75] -= cxtype( 0, 1 ) * amp[0];
  jamp[101] -= cxtype( 0, 1 ) * amp[0];
  jamp[109] += cxtype( 0, 1 ) * amp[0];
  jamp[112] -= cxtype( 0, 1 ) * amp[0];
  jamp[115] += cxtype( 0, 1 ) * amp[0];
  FFV1_0( w[52], w[2], w[29], COUPs[1], &amp[0] );
  jamp[9] += cxtype( 0, 1 ) * amp[0];
  jamp[51] -= cxtype( 0, 1 ) * amp[0];
  jamp[75] -= cxtype( 0, 1 ) * amp[0];
  jamp[85] += cxtype( 0, 1 ) * amp[0];
  jamp[99] -= cxtype( 0, 1 ) * amp[0];
  jamp[109] += cxtype( 0, 1 ) * amp[0];
  jamp[115] += cxtype( 0, 1 ) * amp[0];
  jamp[118] -= cxtype( 0, 1 ) * amp[0];

  // *** DIAGRAM 1177 OF 1240 ***

  // Wavefunction(s) for diagram number 1177
  // (none)

  // Amplitude(s) for diagram number 1177
  FFV1_0( w[52], w[47], w[60], COUPs[1], &amp[0] );
  jamp[99] += amp[0];
  jamp[101] -= amp[0];
  jamp[112] -= amp[0];
  jamp[118] += amp[0];
  FFV1_0( w[52], w[47], w[24], COUPs[1], &amp[0] );
  jamp[101] -= amp[0];
  jamp[109] += amp[0];
  jamp[112] -= amp[0];
  jamp[115] += amp[0];
  FFV1_0( w[52], w[47], w[20], COUPs[1], &amp[0] );
  jamp[99] -= amp[0];
  jamp[109] += amp[0];
  jamp[115] += amp[0];
  jamp[118] -= amp[0];

  // *** DIAGRAM 1178 OF 1240 ***

  // Wavefunction(s) for diagram number 1178
  // (none)

  // Amplitude(s) for diagram number 1178
  FFV1_0( w[3], w[59], w[72], COUPs[1], &amp[0] );
  jamp[8] -= cxtype( 0, 1 ) * amp[0];
  jamp[9] += cxtype( 0, 1 ) * amp[0];
  jamp[14] += cxtype( 0, 1 ) * amp[0];
  jamp[15] -= cxtype( 0, 1 ) * amp[0];
  jamp[60] += cxtype( 0, 1 ) * amp[0];
  jamp[61] -= cxtype( 0, 1 ) * amp[0];
  jamp[84] -= cxtype( 0, 1 ) * amp[0];
  jamp[85] += cxtype( 0, 1 ) * amp[0];
  FFV1_0( w[3], w[71], w[72], COUPs[1], &amp[0] );
  jamp[14] += cxtype( 0, 1 ) * amp[0];
  jamp[15] -= cxtype( 0, 1 ) * amp[0];
  jamp[50] -= cxtype( 0, 1 ) * amp[0];
  jamp[51] += cxtype( 0, 1 ) * amp[0];
  jamp[60] += cxtype( 0, 1 ) * amp[0];
  jamp[61] -= cxtype( 0, 1 ) * amp[0];
  jamp[74] -= cxtype( 0, 1 ) * amp[0];
  jamp[75] += cxtype( 0, 1 ) * amp[0];
  FFV1_0( w[3], w[21], w[72], COUPs[1], &amp[0] );
  jamp[8] += cxtype( 0, 1 ) * amp[0];
  jamp[9] -= cxtype( 0, 1 ) * amp[0];
  jamp[50] -= cxtype( 0, 1 ) * amp[0];
  jamp[51] += cxtype( 0, 1 ) * amp[0];
  jamp[74] -= cxtype( 0, 1 ) * amp[0];
  jamp[75] += cxtype( 0, 1 ) * amp[0];
  jamp[84] += cxtype( 0, 1 ) * amp[0];
  jamp[85] -= cxtype( 0, 1 ) * amp[0];

  // *** DIAGRAM 1179 OF 1240 ***

  // Wavefunction(s) for diagram number 1179
  // (none)

  // Amplitude(s) for diagram number 1179
  FFV1_0( w[16], w[2], w[72], COUPs[1], &amp[0] );
  jamp[42] -= cxtype( 0, 1 ) * amp[0];
  jamp[43] += cxtype( 0, 1 ) * amp[0];
  jamp[45] += cxtype( 0, 1 ) * amp[0];
  jamp[47] -= cxtype( 0, 1 ) * amp[0];
  jamp[102] += cxtype( 0, 1 ) * amp[0];
  jamp[103] -= cxtype( 0, 1 ) * amp[0];
  jamp[105] -= cxtype( 0, 1 ) * amp[0];
  jamp[107] += cxtype( 0, 1 ) * amp[0];
  FFV1_0( w[27], w[2], w[72], COUPs[1], &amp[0] );
  jamp[43] += cxtype( 0, 1 ) * amp[0];
  jamp[44] -= cxtype( 0, 1 ) * amp[0];
  jamp[45] += cxtype( 0, 1 ) * amp[0];
  jamp[46] -= cxtype( 0, 1 ) * amp[0];
  jamp[103] -= cxtype( 0, 1 ) * amp[0];
  jamp[104] += cxtype( 0, 1 ) * amp[0];
  jamp[105] -= cxtype( 0, 1 ) * amp[0];
  jamp[106] += cxtype( 0, 1 ) * amp[0];
  FFV1_0( w[98], w[2], w[72], COUPs[1], &amp[0] );
  jamp[42] += cxtype( 0, 1 ) * amp[0];
  jamp[44] -= cxtype( 0, 1 ) * amp[0];
  jamp[46] -= cxtype( 0, 1 ) * amp[0];
  jamp[47] += cxtype( 0, 1 ) * amp[0];
  jamp[102] -= cxtype( 0, 1 ) * amp[0];
  jamp[104] += cxtype( 0, 1 ) * amp[0];
  jamp[106] += cxtype( 0, 1 ) * amp[0];
  jamp[107] -= cxtype( 0, 1 ) * amp[0];

  // *** DIAGRAM 1180 OF 1240 ***

  // Wavefunction(s) for diagram number 1180
  // (none)

  // Amplitude(s) for diagram number 1180
  VVV1_0( w[60], w[72], w[8], COUPs[0], &amp[0] );
  jamp[8] -= amp[0];
  jamp[9] += amp[0];
  jamp[14] += amp[0];
  jamp[15] -= amp[0];
  jamp[42] += amp[0];
  jamp[43] -= amp[0];
  jamp[45] -= amp[0];
  jamp[47] += amp[0];
  jamp[60] += amp[0];
  jamp[61] -= amp[0];
  jamp[84] -= amp[0];
  jamp[85] += amp[0];
  jamp[102] -= amp[0];
  jamp[103] += amp[0];
  jamp[105] += amp[0];
  jamp[107] -= amp[0];
  VVV1_0( w[24], w[72], w[8], COUPs[0], &amp[0] );
  jamp[14] += amp[0];
  jamp[15] -= amp[0];
  jamp[43] -= amp[0];
  jamp[44] += amp[0];
  jamp[45] -= amp[0];
  jamp[46] += amp[0];
  jamp[50] -= amp[0];
  jamp[51] += amp[0];
  jamp[60] += amp[0];
  jamp[61] -= amp[0];
  jamp[74] -= amp[0];
  jamp[75] += amp[0];
  jamp[103] += amp[0];
  jamp[104] -= amp[0];
  jamp[105] += amp[0];
  jamp[106] -= amp[0];
  VVV1_0( w[20], w[72], w[8], COUPs[0], &amp[0] );
  jamp[8] += amp[0];
  jamp[9] -= amp[0];
  jamp[42] -= amp[0];
  jamp[44] += amp[0];
  jamp[46] += amp[0];
  jamp[47] -= amp[0];
  jamp[50] -= amp[0];
  jamp[51] += amp[0];
  jamp[74] -= amp[0];
  jamp[75] += amp[0];
  jamp[84] += amp[0];
  jamp[85] -= amp[0];
  jamp[102] += amp[0];
  jamp[104] -= amp[0];
  jamp[106] -= amp[0];
  jamp[107] += amp[0];

  // *** DIAGRAM 1181 OF 1240 ***

  // Wavefunction(s) for diagram number 1181
  // (none)

  // Amplitude(s) for diagram number 1181
  VVVV1_0( w[60], w[1], w[8], w[6], COUPs[2], &amp[0] );
  jamp[8] += amp[0];
  jamp[14] -= amp[0];
  jamp[24] -= amp[0];
  jamp[26] += amp[0];
  jamp[32] += amp[0];
  jamp[38] -= amp[0];
  jamp[60] -= amp[0];
  jamp[84] += amp[0];
  jamp[99] -= amp[0];
  jamp[101] += amp[0];
  jamp[102] += amp[0];
  jamp[103] -= amp[0];
  jamp[105] -= amp[0];
  jamp[107] += amp[0];
  jamp[112] += amp[0];
  jamp[118] -= amp[0];
  VVVV3_0( w[60], w[1], w[8], w[6], COUPs[2], &amp[0] );
  jamp[8] += amp[0];
  jamp[9] -= amp[0];
  jamp[14] -= amp[0];
  jamp[15] += amp[0];
  jamp[42] -= amp[0];
  jamp[43] += amp[0];
  jamp[45] += amp[0];
  jamp[47] -= amp[0];
  jamp[60] -= amp[0];
  jamp[61] += amp[0];
  jamp[84] += amp[0];
  jamp[85] -= amp[0];
  jamp[102] += amp[0];
  jamp[103] -= amp[0];
  jamp[105] -= amp[0];
  jamp[107] += amp[0];
  VVVV4_0( w[60], w[1], w[8], w[6], COUPs[2], &amp[0] );
  jamp[9] -= amp[0];
  jamp[15] += amp[0];
  jamp[24] += amp[0];
  jamp[26] -= amp[0];
  jamp[32] -= amp[0];
  jamp[38] += amp[0];
  jamp[42] -= amp[0];
  jamp[43] += amp[0];
  jamp[45] += amp[0];
  jamp[47] -= amp[0];
  jamp[61] += amp[0];
  jamp[85] -= amp[0];
  jamp[99] += amp[0];
  jamp[101] -= amp[0];
  jamp[112] -= amp[0];
  jamp[118] += amp[0];
  VVVV1_0( w[24], w[1], w[8], w[6], COUPs[2], &amp[0] );
  jamp[14] -= amp[0];
  jamp[26] += amp[0];
  jamp[30] -= amp[0];
  jamp[32] += amp[0];
  jamp[36] -= amp[0];
  jamp[50] += amp[0];
  jamp[60] -= amp[0];
  jamp[74] += amp[0];
  jamp[101] += amp[0];
  jamp[103] -= amp[0];
  jamp[104] += amp[0];
  jamp[105] -= amp[0];
  jamp[106] += amp[0];
  jamp[109] -= amp[0];
  jamp[112] += amp[0];
  jamp[115] -= amp[0];
  VVVV3_0( w[24], w[1], w[8], w[6], COUPs[2], &amp[0] );
  jamp[14] -= amp[0];
  jamp[15] += amp[0];
  jamp[43] += amp[0];
  jamp[44] -= amp[0];
  jamp[45] += amp[0];
  jamp[46] -= amp[0];
  jamp[50] += amp[0];
  jamp[51] -= amp[0];
  jamp[60] -= amp[0];
  jamp[61] += amp[0];
  jamp[74] += amp[0];
  jamp[75] -= amp[0];
  jamp[103] -= amp[0];
  jamp[104] += amp[0];
  jamp[105] -= amp[0];
  jamp[106] += amp[0];
  VVVV4_0( w[24], w[1], w[8], w[6], COUPs[2], &amp[0] );
  jamp[15] += amp[0];
  jamp[26] -= amp[0];
  jamp[30] += amp[0];
  jamp[32] -= amp[0];
  jamp[36] += amp[0];
  jamp[43] += amp[0];
  jamp[44] -= amp[0];
  jamp[45] += amp[0];
  jamp[46] -= amp[0];
  jamp[51] -= amp[0];
  jamp[61] += amp[0];
  jamp[75] -= amp[0];
  jamp[101] -= amp[0];
  jamp[109] += amp[0];
  jamp[112] -= amp[0];
  jamp[115] += amp[0];
  VVVV1_0( w[20], w[1], w[8], w[6], COUPs[2], &amp[0] );
  jamp[8] -= amp[0];
  jamp[24] += amp[0];
  jamp[30] -= amp[0];
  jamp[36] -= amp[0];
  jamp[38] += amp[0];
  jamp[50] += amp[0];
  jamp[74] += amp[0];
  jamp[84] -= amp[0];
  jamp[99] += amp[0];
  jamp[102] -= amp[0];
  jamp[104] += amp[0];
  jamp[106] += amp[0];
  jamp[107] -= amp[0];
  jamp[109] -= amp[0];
  jamp[115] -= amp[0];
  jamp[118] += amp[0];
  VVVV3_0( w[20], w[1], w[8], w[6], COUPs[2], &amp[0] );
  jamp[8] -= amp[0];
  jamp[9] += amp[0];
  jamp[42] += amp[0];
  jamp[44] -= amp[0];
  jamp[46] -= amp[0];
  jamp[47] += amp[0];
  jamp[50] += amp[0];
  jamp[51] -= amp[0];
  jamp[74] += amp[0];
  jamp[75] -= amp[0];
  jamp[84] -= amp[0];
  jamp[85] += amp[0];
  jamp[102] -= amp[0];
  jamp[104] += amp[0];
  jamp[106] += amp[0];
  jamp[107] -= amp[0];
  VVVV4_0( w[20], w[1], w[8], w[6], COUPs[2], &amp[0] );
  jamp[9] += amp[0];
  jamp[24] -= amp[0];
  jamp[30] += amp[0];
  jamp[36] += amp[0];
  jamp[38] -= amp[0];
  jamp[42] += amp[0];
  jamp[44] -= amp[0];
  jamp[46] -= amp[0];
  jamp[47] += amp[0];
  jamp[51] -= amp[0];
  jamp[75] -= amp[0];
  jamp[85] += amp[0];
  jamp[99] -= amp[0];
  jamp[109] += amp[0];
  jamp[115] += amp[0];
  jamp[118] -= amp[0];

  // *** DIAGRAM 1182 OF 1240 ***

  // Wavefunction(s) for diagram number 1182
  VVV1P0_1( w[60], w[1], COUPs[0], 0., 0., w[72] );
  VVV1P0_1( w[24], w[1], COUPs[0], 0., 0., w[60] );
  VVV1P0_1( w[20], w[1], COUPs[0], 0., 0., w[24] );

  // Amplitude(s) for diagram number 1182
  VVV1_0( w[8], w[6], w[72], COUPs[0], &amp[0] );
  jamp[8] += amp[0];
  jamp[14] -= amp[0];
  jamp[24] -= amp[0];
  jamp[26] += amp[0];
  jamp[32] += amp[0];
  jamp[38] -= amp[0];
  jamp[60] -= amp[0];
  jamp[84] += amp[0];
  jamp[99] -= amp[0];
  jamp[101] += amp[0];
  jamp[102] += amp[0];
  jamp[103] -= amp[0];
  jamp[105] -= amp[0];
  jamp[107] += amp[0];
  jamp[112] += amp[0];
  jamp[118] -= amp[0];
  VVV1_0( w[8], w[6], w[60], COUPs[0], &amp[0] );
  jamp[14] -= amp[0];
  jamp[26] += amp[0];
  jamp[30] -= amp[0];
  jamp[32] += amp[0];
  jamp[36] -= amp[0];
  jamp[50] += amp[0];
  jamp[60] -= amp[0];
  jamp[74] += amp[0];
  jamp[101] += amp[0];
  jamp[103] -= amp[0];
  jamp[104] += amp[0];
  jamp[105] -= amp[0];
  jamp[106] += amp[0];
  jamp[109] -= amp[0];
  jamp[112] += amp[0];
  jamp[115] -= amp[0];
  VVV1_0( w[8], w[6], w[24], COUPs[0], &amp[0] );
  jamp[8] -= amp[0];
  jamp[24] += amp[0];
  jamp[30] -= amp[0];
  jamp[36] -= amp[0];
  jamp[38] += amp[0];
  jamp[50] += amp[0];
  jamp[74] += amp[0];
  jamp[84] -= amp[0];
  jamp[99] += amp[0];
  jamp[102] -= amp[0];
  jamp[104] += amp[0];
  jamp[106] += amp[0];
  jamp[107] -= amp[0];
  jamp[109] -= amp[0];
  jamp[115] -= amp[0];
  jamp[118] += amp[0];

  // *** DIAGRAM 1183 OF 1240 ***

  // Wavefunction(s) for diagram number 1183
  // (none)

  // Amplitude(s) for diagram number 1183
  VVV1_0( w[1], w[8], w[23], COUPs[0], &amp[0] );
  jamp[9] -= amp[0];
  jamp[15] += amp[0];
  jamp[24] += amp[0];
  jamp[26] -= amp[0];
  jamp[32] -= amp[0];
  jamp[38] += amp[0];
  jamp[42] -= amp[0];
  jamp[43] += amp[0];
  jamp[45] += amp[0];
  jamp[47] -= amp[0];
  jamp[61] += amp[0];
  jamp[85] -= amp[0];
  jamp[99] += amp[0];
  jamp[101] -= amp[0];
  jamp[112] -= amp[0];
  jamp[118] += amp[0];
  VVV1_0( w[1], w[8], w[68], COUPs[0], &amp[0] );
  jamp[15] += amp[0];
  jamp[26] -= amp[0];
  jamp[30] += amp[0];
  jamp[32] -= amp[0];
  jamp[36] += amp[0];
  jamp[43] += amp[0];
  jamp[44] -= amp[0];
  jamp[45] += amp[0];
  jamp[46] -= amp[0];
  jamp[51] -= amp[0];
  jamp[61] += amp[0];
  jamp[75] -= amp[0];
  jamp[101] -= amp[0];
  jamp[109] += amp[0];
  jamp[112] -= amp[0];
  jamp[115] += amp[0];
  VVV1_0( w[1], w[8], w[29], COUPs[0], &amp[0] );
  jamp[9] += amp[0];
  jamp[24] -= amp[0];
  jamp[30] += amp[0];
  jamp[36] += amp[0];
  jamp[38] -= amp[0];
  jamp[42] += amp[0];
  jamp[44] -= amp[0];
  jamp[46] -= amp[0];
  jamp[47] += amp[0];
  jamp[51] -= amp[0];
  jamp[75] -= amp[0];
  jamp[85] += amp[0];
  jamp[99] -= amp[0];
  jamp[109] += amp[0];
  jamp[115] += amp[0];
  jamp[118] -= amp[0];

  // *** DIAGRAM 1184 OF 1240 ***

  // Wavefunction(s) for diagram number 1184
  // (none)

  // Amplitude(s) for diagram number 1184
  FFV1_0( w[3], w[47], w[72], COUPs[1], &amp[0] );
  jamp[99] -= cxtype( 0, 1 ) * amp[0];
  jamp[101] += cxtype( 0, 1 ) * amp[0];
  jamp[102] += cxtype( 0, 1 ) * amp[0];
  jamp[103] -= cxtype( 0, 1 ) * amp[0];
  jamp[105] -= cxtype( 0, 1 ) * amp[0];
  jamp[107] += cxtype( 0, 1 ) * amp[0];
  jamp[112] += cxtype( 0, 1 ) * amp[0];
  jamp[118] -= cxtype( 0, 1 ) * amp[0];
  FFV1_0( w[3], w[47], w[60], COUPs[1], &amp[0] );
  jamp[101] += cxtype( 0, 1 ) * amp[0];
  jamp[103] -= cxtype( 0, 1 ) * amp[0];
  jamp[104] += cxtype( 0, 1 ) * amp[0];
  jamp[105] -= cxtype( 0, 1 ) * amp[0];
  jamp[106] += cxtype( 0, 1 ) * amp[0];
  jamp[109] -= cxtype( 0, 1 ) * amp[0];
  jamp[112] += cxtype( 0, 1 ) * amp[0];
  jamp[115] -= cxtype( 0, 1 ) * amp[0];
  FFV1_0( w[3], w[47], w[24], COUPs[1], &amp[0] );
  jamp[99] += cxtype( 0, 1 ) * amp[0];
  jamp[102] -= cxtype( 0, 1 ) * amp[0];
  jamp[104] += cxtype( 0, 1 ) * amp[0];
  jamp[106] += cxtype( 0, 1 ) * amp[0];
  jamp[107] -= cxtype( 0, 1 ) * amp[0];
  jamp[109] -= cxtype( 0, 1 ) * amp[0];
  jamp[115] -= cxtype( 0, 1 ) * amp[0];
  jamp[118] += cxtype( 0, 1 ) * amp[0];

  // *** DIAGRAM 1185 OF 1240 ***

  // Wavefunction(s) for diagram number 1185
  // (none)

  // Amplitude(s) for diagram number 1185
  FFV1_0( w[16], w[47], w[1], COUPs[1], &amp[0] );
  jamp[102] += amp[0];
  jamp[103] -= amp[0];
  jamp[105] -= amp[0];
  jamp[107] += amp[0];
  FFV1_0( w[27], w[47], w[1], COUPs[1], &amp[0] );
  jamp[103] -= amp[0];
  jamp[104] += amp[0];
  jamp[105] -= amp[0];
  jamp[106] += amp[0];
  FFV1_0( w[98], w[47], w[1], COUPs[1], &amp[0] );
  jamp[102] -= amp[0];
  jamp[104] += amp[0];
  jamp[106] += amp[0];
  jamp[107] -= amp[0];

  // *** DIAGRAM 1186 OF 1240 ***

  // Wavefunction(s) for diagram number 1186
  // (none)

  // Amplitude(s) for diagram number 1186
  FFV1_0( w[41], w[2], w[72], COUPs[1], &amp[0] );
  jamp[8] -= cxtype( 0, 1 ) * amp[0];
  jamp[14] += cxtype( 0, 1 ) * amp[0];
  jamp[24] += cxtype( 0, 1 ) * amp[0];
  jamp[26] -= cxtype( 0, 1 ) * amp[0];
  jamp[32] -= cxtype( 0, 1 ) * amp[0];
  jamp[38] += cxtype( 0, 1 ) * amp[0];
  jamp[60] += cxtype( 0, 1 ) * amp[0];
  jamp[84] -= cxtype( 0, 1 ) * amp[0];
  FFV1_0( w[41], w[2], w[60], COUPs[1], &amp[0] );
  jamp[14] += cxtype( 0, 1 ) * amp[0];
  jamp[26] -= cxtype( 0, 1 ) * amp[0];
  jamp[30] += cxtype( 0, 1 ) * amp[0];
  jamp[32] -= cxtype( 0, 1 ) * amp[0];
  jamp[36] += cxtype( 0, 1 ) * amp[0];
  jamp[50] -= cxtype( 0, 1 ) * amp[0];
  jamp[60] += cxtype( 0, 1 ) * amp[0];
  jamp[74] -= cxtype( 0, 1 ) * amp[0];
  FFV1_0( w[41], w[2], w[24], COUPs[1], &amp[0] );
  jamp[8] += cxtype( 0, 1 ) * amp[0];
  jamp[24] -= cxtype( 0, 1 ) * amp[0];
  jamp[30] += cxtype( 0, 1 ) * amp[0];
  jamp[36] += cxtype( 0, 1 ) * amp[0];
  jamp[38] -= cxtype( 0, 1 ) * amp[0];
  jamp[50] -= cxtype( 0, 1 ) * amp[0];
  jamp[74] -= cxtype( 0, 1 ) * amp[0];
  jamp[84] += cxtype( 0, 1 ) * amp[0];

  // *** DIAGRAM 1187 OF 1240 ***

  // Wavefunction(s) for diagram number 1187
  // (none)

  // Amplitude(s) for diagram number 1187
  FFV1_0( w[41], w[59], w[1], COUPs[1], &amp[0] );
  jamp[8] += amp[0];
  jamp[14] -= amp[0];
  jamp[60] -= amp[0];
  jamp[84] += amp[0];
  FFV1_0( w[41], w[71], w[1], COUPs[1], &amp[0] );
  jamp[14] -= amp[0];
  jamp[50] += amp[0];
  jamp[60] -= amp[0];
  jamp[74] += amp[0];
  FFV1_0( w[41], w[21], w[1], COUPs[1], &amp[0] );
  jamp[8] -= amp[0];
  jamp[50] += amp[0];
  jamp[74] += amp[0];
  jamp[84] -= amp[0];

  // *** DIAGRAM 1188 OF 1240 ***

  // Wavefunction(s) for diagram number 1188
  VVVV1P0_1( w[0], w[4], w[6], COUPs[2], 0., 0., w[21] );
  VVVV3P0_1( w[0], w[4], w[6], COUPs[2], 0., 0., w[71] );
  VVVV4P0_1( w[0], w[4], w[6], COUPs[2], 0., 0., w[59] );
  FFV1_2( w[3], w[21], COUPs[1], cIPD[0], cIPD[1], w[24] );
  FFV1_2( w[3], w[71], COUPs[1], cIPD[0], cIPD[1], w[60] );
  FFV1_2( w[3], w[59], COUPs[1], cIPD[0], cIPD[1], w[72] );

  // Amplitude(s) for diagram number 1188
  FFV1_0( w[24], w[77], w[5], COUPs[1], &amp[0] );
  jamp[36] += amp[0];
  jamp[37] -= amp[0];
  jamp[39] -= amp[0];
  jamp[41] += amp[0];
  FFV1_0( w[60], w[77], w[5], COUPs[1], &amp[0] );
  jamp[37] -= amp[0];
  jamp[38] += amp[0];
  jamp[39] -= amp[0];
  jamp[40] += amp[0];
  FFV1_0( w[72], w[77], w[5], COUPs[1], &amp[0] );
  jamp[36] -= amp[0];
  jamp[38] += amp[0];
  jamp[40] += amp[0];
  jamp[41] -= amp[0];

  // *** DIAGRAM 1189 OF 1240 ***

  // Wavefunction(s) for diagram number 1189
  VVV1P0_1( w[21], w[5], COUPs[0], 0., 0., w[98] );
  VVV1P0_1( w[71], w[5], COUPs[0], 0., 0., w[27] );
  VVV1P0_1( w[59], w[5], COUPs[0], 0., 0., w[16] );

  // Amplitude(s) for diagram number 1189
  FFV1_0( w[3], w[77], w[98], COUPs[1], &amp[0] );
  jamp[25] -= cxtype( 0, 1 ) * amp[0];
  jamp[28] += cxtype( 0, 1 ) * amp[0];
  jamp[34] += cxtype( 0, 1 ) * amp[0];
  jamp[36] += cxtype( 0, 1 ) * amp[0];
  jamp[37] -= cxtype( 0, 1 ) * amp[0];
  jamp[39] -= cxtype( 0, 1 ) * amp[0];
  jamp[41] += cxtype( 0, 1 ) * amp[0];
  jamp[44] -= cxtype( 0, 1 ) * amp[0];
  FFV1_0( w[3], w[77], w[27], COUPs[1], &amp[0] );
  jamp[28] += cxtype( 0, 1 ) * amp[0];
  jamp[31] -= cxtype( 0, 1 ) * amp[0];
  jamp[34] += cxtype( 0, 1 ) * amp[0];
  jamp[37] -= cxtype( 0, 1 ) * amp[0];
  jamp[38] += cxtype( 0, 1 ) * amp[0];
  jamp[39] -= cxtype( 0, 1 ) * amp[0];
  jamp[40] += cxtype( 0, 1 ) * amp[0];
  jamp[42] -= cxtype( 0, 1 ) * amp[0];
  FFV1_0( w[3], w[77], w[16], COUPs[1], &amp[0] );
  jamp[25] += cxtype( 0, 1 ) * amp[0];
  jamp[31] -= cxtype( 0, 1 ) * amp[0];
  jamp[36] -= cxtype( 0, 1 ) * amp[0];
  jamp[38] += cxtype( 0, 1 ) * amp[0];
  jamp[40] += cxtype( 0, 1 ) * amp[0];
  jamp[41] -= cxtype( 0, 1 ) * amp[0];
  jamp[42] -= cxtype( 0, 1 ) * amp[0];
  jamp[44] += cxtype( 0, 1 ) * amp[0];

  // *** DIAGRAM 1190 OF 1240 ***

  // Wavefunction(s) for diagram number 1190
  // (none)

  // Amplitude(s) for diagram number 1190
  FFV1_0( w[38], w[77], w[21], COUPs[1], &amp[0] );
  jamp[25] += amp[0];
  jamp[28] -= amp[0];
  jamp[34] -= amp[0];
  jamp[44] += amp[0];
  FFV1_0( w[38], w[77], w[71], COUPs[1], &amp[0] );
  jamp[28] -= amp[0];
  jamp[31] += amp[0];
  jamp[34] -= amp[0];
  jamp[42] += amp[0];
  FFV1_0( w[38], w[77], w[59], COUPs[1], &amp[0] );
  jamp[25] -= amp[0];
  jamp[31] += amp[0];
  jamp[42] += amp[0];
  jamp[44] -= amp[0];

  // *** DIAGRAM 1191 OF 1240 ***

  // Wavefunction(s) for diagram number 1191
  FFV1_1( w[2], w[21], COUPs[1], cIPD[0], cIPD[1], w[29] );
  FFV1_1( w[2], w[71], COUPs[1], cIPD[0], cIPD[1], w[68] );
  FFV1_1( w[2], w[59], COUPs[1], cIPD[0], cIPD[1], w[23] );

  // Amplitude(s) for diagram number 1191
  FFV1_0( w[52], w[29], w[5], COUPs[1], &amp[0] );
  jamp[11] += amp[0];
  jamp[21] -= amp[0];
  jamp[67] -= amp[0];
  jamp[109] += amp[0];
  FFV1_0( w[52], w[68], w[5], COUPs[1], &amp[0] );
  jamp[21] -= amp[0];
  jamp[53] += amp[0];
  jamp[67] -= amp[0];
  jamp[99] += amp[0];
  FFV1_0( w[52], w[23], w[5], COUPs[1], &amp[0] );
  jamp[11] -= amp[0];
  jamp[53] += amp[0];
  jamp[99] += amp[0];
  jamp[109] -= amp[0];

  // *** DIAGRAM 1192 OF 1240 ***

  // Wavefunction(s) for diagram number 1192
  // (none)

  // Amplitude(s) for diagram number 1192
  FFV1_0( w[52], w[2], w[98], COUPs[1], &amp[0] );
  jamp[11] -= cxtype( 0, 1 ) * amp[0];
  jamp[21] += cxtype( 0, 1 ) * amp[0];
  jamp[67] += cxtype( 0, 1 ) * amp[0];
  jamp[75] += cxtype( 0, 1 ) * amp[0];
  jamp[77] -= cxtype( 0, 1 ) * amp[0];
  jamp[88] -= cxtype( 0, 1 ) * amp[0];
  jamp[94] += cxtype( 0, 1 ) * amp[0];
  jamp[109] -= cxtype( 0, 1 ) * amp[0];
  FFV1_0( w[52], w[2], w[27], COUPs[1], &amp[0] );
  jamp[21] += cxtype( 0, 1 ) * amp[0];
  jamp[53] -= cxtype( 0, 1 ) * amp[0];
  jamp[67] += cxtype( 0, 1 ) * amp[0];
  jamp[77] -= cxtype( 0, 1 ) * amp[0];
  jamp[85] += cxtype( 0, 1 ) * amp[0];
  jamp[88] -= cxtype( 0, 1 ) * amp[0];
  jamp[91] += cxtype( 0, 1 ) * amp[0];
  jamp[99] -= cxtype( 0, 1 ) * amp[0];
  FFV1_0( w[52], w[2], w[16], COUPs[1], &amp[0] );
  jamp[11] += cxtype( 0, 1 ) * amp[0];
  jamp[53] -= cxtype( 0, 1 ) * amp[0];
  jamp[75] -= cxtype( 0, 1 ) * amp[0];
  jamp[85] += cxtype( 0, 1 ) * amp[0];
  jamp[91] += cxtype( 0, 1 ) * amp[0];
  jamp[94] -= cxtype( 0, 1 ) * amp[0];
  jamp[99] -= cxtype( 0, 1 ) * amp[0];
  jamp[109] += cxtype( 0, 1 ) * amp[0];

  // *** DIAGRAM 1193 OF 1240 ***

  // Wavefunction(s) for diagram number 1193
  // (none)

  // Amplitude(s) for diagram number 1193
  FFV1_0( w[52], w[39], w[21], COUPs[1], &amp[0] );
  jamp[75] += amp[0];
  jamp[77] -= amp[0];
  jamp[88] -= amp[0];
  jamp[94] += amp[0];
  FFV1_0( w[52], w[39], w[71], COUPs[1], &amp[0] );
  jamp[77] -= amp[0];
  jamp[85] += amp[0];
  jamp[88] -= amp[0];
  jamp[91] += amp[0];
  FFV1_0( w[52], w[39], w[59], COUPs[1], &amp[0] );
  jamp[75] -= amp[0];
  jamp[85] += amp[0];
  jamp[91] += amp[0];
  jamp[94] -= amp[0];

  // *** DIAGRAM 1194 OF 1240 ***

  // Wavefunction(s) for diagram number 1194
  // (none)

  // Amplitude(s) for diagram number 1194
  FFV1_0( w[3], w[29], w[66], COUPs[1], &amp[0] );
  jamp[10] -= cxtype( 0, 1 ) * amp[0];
  jamp[11] += cxtype( 0, 1 ) * amp[0];
  jamp[20] += cxtype( 0, 1 ) * amp[0];
  jamp[21] -= cxtype( 0, 1 ) * amp[0];
  jamp[66] += cxtype( 0, 1 ) * amp[0];
  jamp[67] -= cxtype( 0, 1 ) * amp[0];
  jamp[108] -= cxtype( 0, 1 ) * amp[0];
  jamp[109] += cxtype( 0, 1 ) * amp[0];
  FFV1_0( w[3], w[68], w[66], COUPs[1], &amp[0] );
  jamp[20] += cxtype( 0, 1 ) * amp[0];
  jamp[21] -= cxtype( 0, 1 ) * amp[0];
  jamp[52] -= cxtype( 0, 1 ) * amp[0];
  jamp[53] += cxtype( 0, 1 ) * amp[0];
  jamp[66] += cxtype( 0, 1 ) * amp[0];
  jamp[67] -= cxtype( 0, 1 ) * amp[0];
  jamp[98] -= cxtype( 0, 1 ) * amp[0];
  jamp[99] += cxtype( 0, 1 ) * amp[0];
  FFV1_0( w[3], w[23], w[66], COUPs[1], &amp[0] );
  jamp[10] += cxtype( 0, 1 ) * amp[0];
  jamp[11] -= cxtype( 0, 1 ) * amp[0];
  jamp[52] -= cxtype( 0, 1 ) * amp[0];
  jamp[53] += cxtype( 0, 1 ) * amp[0];
  jamp[98] -= cxtype( 0, 1 ) * amp[0];
  jamp[99] += cxtype( 0, 1 ) * amp[0];
  jamp[108] += cxtype( 0, 1 ) * amp[0];
  jamp[109] -= cxtype( 0, 1 ) * amp[0];

  // *** DIAGRAM 1195 OF 1240 ***

  // Wavefunction(s) for diagram number 1195
  // (none)

  // Amplitude(s) for diagram number 1195
  FFV1_0( w[24], w[2], w[66], COUPs[1], &amp[0] );
  jamp[36] -= cxtype( 0, 1 ) * amp[0];
  jamp[37] += cxtype( 0, 1 ) * amp[0];
  jamp[39] += cxtype( 0, 1 ) * amp[0];
  jamp[41] -= cxtype( 0, 1 ) * amp[0];
  jamp[78] += cxtype( 0, 1 ) * amp[0];
  jamp[79] -= cxtype( 0, 1 ) * amp[0];
  jamp[81] -= cxtype( 0, 1 ) * amp[0];
  jamp[83] += cxtype( 0, 1 ) * amp[0];
  FFV1_0( w[60], w[2], w[66], COUPs[1], &amp[0] );
  jamp[37] += cxtype( 0, 1 ) * amp[0];
  jamp[38] -= cxtype( 0, 1 ) * amp[0];
  jamp[39] += cxtype( 0, 1 ) * amp[0];
  jamp[40] -= cxtype( 0, 1 ) * amp[0];
  jamp[79] -= cxtype( 0, 1 ) * amp[0];
  jamp[80] += cxtype( 0, 1 ) * amp[0];
  jamp[81] -= cxtype( 0, 1 ) * amp[0];
  jamp[82] += cxtype( 0, 1 ) * amp[0];
  FFV1_0( w[72], w[2], w[66], COUPs[1], &amp[0] );
  jamp[36] += cxtype( 0, 1 ) * amp[0];
  jamp[38] -= cxtype( 0, 1 ) * amp[0];
  jamp[40] -= cxtype( 0, 1 ) * amp[0];
  jamp[41] += cxtype( 0, 1 ) * amp[0];
  jamp[78] -= cxtype( 0, 1 ) * amp[0];
  jamp[80] += cxtype( 0, 1 ) * amp[0];
  jamp[82] += cxtype( 0, 1 ) * amp[0];
  jamp[83] -= cxtype( 0, 1 ) * amp[0];

  // *** DIAGRAM 1196 OF 1240 ***

  // Wavefunction(s) for diagram number 1196
  // (none)

  // Amplitude(s) for diagram number 1196
  VVV1_0( w[21], w[66], w[8], COUPs[0], &amp[0] );
  jamp[10] -= amp[0];
  jamp[11] += amp[0];
  jamp[20] += amp[0];
  jamp[21] -= amp[0];
  jamp[36] += amp[0];
  jamp[37] -= amp[0];
  jamp[39] -= amp[0];
  jamp[41] += amp[0];
  jamp[66] += amp[0];
  jamp[67] -= amp[0];
  jamp[78] -= amp[0];
  jamp[79] += amp[0];
  jamp[81] += amp[0];
  jamp[83] -= amp[0];
  jamp[108] -= amp[0];
  jamp[109] += amp[0];
  VVV1_0( w[71], w[66], w[8], COUPs[0], &amp[0] );
  jamp[20] += amp[0];
  jamp[21] -= amp[0];
  jamp[37] -= amp[0];
  jamp[38] += amp[0];
  jamp[39] -= amp[0];
  jamp[40] += amp[0];
  jamp[52] -= amp[0];
  jamp[53] += amp[0];
  jamp[66] += amp[0];
  jamp[67] -= amp[0];
  jamp[79] += amp[0];
  jamp[80] -= amp[0];
  jamp[81] += amp[0];
  jamp[82] -= amp[0];
  jamp[98] -= amp[0];
  jamp[99] += amp[0];
  VVV1_0( w[59], w[66], w[8], COUPs[0], &amp[0] );
  jamp[10] += amp[0];
  jamp[11] -= amp[0];
  jamp[36] -= amp[0];
  jamp[38] += amp[0];
  jamp[40] += amp[0];
  jamp[41] -= amp[0];
  jamp[52] -= amp[0];
  jamp[53] += amp[0];
  jamp[78] += amp[0];
  jamp[80] -= amp[0];
  jamp[82] -= amp[0];
  jamp[83] += amp[0];
  jamp[98] -= amp[0];
  jamp[99] += amp[0];
  jamp[108] += amp[0];
  jamp[109] -= amp[0];

  // *** DIAGRAM 1197 OF 1240 ***

  // Wavefunction(s) for diagram number 1197
  // (none)

  // Amplitude(s) for diagram number 1197
  VVVV1_0( w[21], w[1], w[8], w[5], COUPs[2], &amp[0] );
  jamp[10] += amp[0];
  jamp[20] -= amp[0];
  jamp[25] -= amp[0];
  jamp[28] += amp[0];
  jamp[34] += amp[0];
  jamp[44] -= amp[0];
  jamp[66] -= amp[0];
  jamp[75] -= amp[0];
  jamp[77] += amp[0];
  jamp[78] += amp[0];
  jamp[79] -= amp[0];
  jamp[81] -= amp[0];
  jamp[83] += amp[0];
  jamp[88] += amp[0];
  jamp[94] -= amp[0];
  jamp[108] += amp[0];
  VVVV3_0( w[21], w[1], w[8], w[5], COUPs[2], &amp[0] );
  jamp[10] += amp[0];
  jamp[11] -= amp[0];
  jamp[20] -= amp[0];
  jamp[21] += amp[0];
  jamp[36] -= amp[0];
  jamp[37] += amp[0];
  jamp[39] += amp[0];
  jamp[41] -= amp[0];
  jamp[66] -= amp[0];
  jamp[67] += amp[0];
  jamp[78] += amp[0];
  jamp[79] -= amp[0];
  jamp[81] -= amp[0];
  jamp[83] += amp[0];
  jamp[108] += amp[0];
  jamp[109] -= amp[0];
  VVVV4_0( w[21], w[1], w[8], w[5], COUPs[2], &amp[0] );
  jamp[11] -= amp[0];
  jamp[21] += amp[0];
  jamp[25] += amp[0];
  jamp[28] -= amp[0];
  jamp[34] -= amp[0];
  jamp[36] -= amp[0];
  jamp[37] += amp[0];
  jamp[39] += amp[0];
  jamp[41] -= amp[0];
  jamp[44] += amp[0];
  jamp[67] += amp[0];
  jamp[75] += amp[0];
  jamp[77] -= amp[0];
  jamp[88] -= amp[0];
  jamp[94] += amp[0];
  jamp[109] -= amp[0];
  VVVV1_0( w[71], w[1], w[8], w[5], COUPs[2], &amp[0] );
  jamp[20] -= amp[0];
  jamp[28] += amp[0];
  jamp[31] -= amp[0];
  jamp[34] += amp[0];
  jamp[42] -= amp[0];
  jamp[52] += amp[0];
  jamp[66] -= amp[0];
  jamp[77] += amp[0];
  jamp[79] -= amp[0];
  jamp[80] += amp[0];
  jamp[81] -= amp[0];
  jamp[82] += amp[0];
  jamp[85] -= amp[0];
  jamp[88] += amp[0];
  jamp[91] -= amp[0];
  jamp[98] += amp[0];
  VVVV3_0( w[71], w[1], w[8], w[5], COUPs[2], &amp[0] );
  jamp[20] -= amp[0];
  jamp[21] += amp[0];
  jamp[37] += amp[0];
  jamp[38] -= amp[0];
  jamp[39] += amp[0];
  jamp[40] -= amp[0];
  jamp[52] += amp[0];
  jamp[53] -= amp[0];
  jamp[66] -= amp[0];
  jamp[67] += amp[0];
  jamp[79] -= amp[0];
  jamp[80] += amp[0];
  jamp[81] -= amp[0];
  jamp[82] += amp[0];
  jamp[98] += amp[0];
  jamp[99] -= amp[0];
  VVVV4_0( w[71], w[1], w[8], w[5], COUPs[2], &amp[0] );
  jamp[21] += amp[0];
  jamp[28] -= amp[0];
  jamp[31] += amp[0];
  jamp[34] -= amp[0];
  jamp[37] += amp[0];
  jamp[38] -= amp[0];
  jamp[39] += amp[0];
  jamp[40] -= amp[0];
  jamp[42] += amp[0];
  jamp[53] -= amp[0];
  jamp[67] += amp[0];
  jamp[77] -= amp[0];
  jamp[85] += amp[0];
  jamp[88] -= amp[0];
  jamp[91] += amp[0];
  jamp[99] -= amp[0];
  VVVV1_0( w[59], w[1], w[8], w[5], COUPs[2], &amp[0] );
  jamp[10] -= amp[0];
  jamp[25] += amp[0];
  jamp[31] -= amp[0];
  jamp[42] -= amp[0];
  jamp[44] += amp[0];
  jamp[52] += amp[0];
  jamp[75] += amp[0];
  jamp[78] -= amp[0];
  jamp[80] += amp[0];
  jamp[82] += amp[0];
  jamp[83] -= amp[0];
  jamp[85] -= amp[0];
  jamp[91] -= amp[0];
  jamp[94] += amp[0];
  jamp[98] += amp[0];
  jamp[108] -= amp[0];
  VVVV3_0( w[59], w[1], w[8], w[5], COUPs[2], &amp[0] );
  jamp[10] -= amp[0];
  jamp[11] += amp[0];
  jamp[36] += amp[0];
  jamp[38] -= amp[0];
  jamp[40] -= amp[0];
  jamp[41] += amp[0];
  jamp[52] += amp[0];
  jamp[53] -= amp[0];
  jamp[78] -= amp[0];
  jamp[80] += amp[0];
  jamp[82] += amp[0];
  jamp[83] -= amp[0];
  jamp[98] += amp[0];
  jamp[99] -= amp[0];
  jamp[108] -= amp[0];
  jamp[109] += amp[0];
  VVVV4_0( w[59], w[1], w[8], w[5], COUPs[2], &amp[0] );
  jamp[11] += amp[0];
  jamp[25] -= amp[0];
  jamp[31] += amp[0];
  jamp[36] += amp[0];
  jamp[38] -= amp[0];
  jamp[40] -= amp[0];
  jamp[41] += amp[0];
  jamp[42] += amp[0];
  jamp[44] -= amp[0];
  jamp[53] -= amp[0];
  jamp[75] -= amp[0];
  jamp[85] += amp[0];
  jamp[91] += amp[0];
  jamp[94] -= amp[0];
  jamp[99] -= amp[0];
  jamp[109] += amp[0];

  // *** DIAGRAM 1198 OF 1240 ***

  // Wavefunction(s) for diagram number 1198
  VVV1P0_1( w[21], w[1], COUPs[0], 0., 0., w[66] );
  VVV1P0_1( w[71], w[1], COUPs[0], 0., 0., w[21] );
  VVV1P0_1( w[59], w[1], COUPs[0], 0., 0., w[71] );

  // Amplitude(s) for diagram number 1198
  VVV1_0( w[8], w[5], w[66], COUPs[0], &amp[0] );
  jamp[10] += amp[0];
  jamp[20] -= amp[0];
  jamp[25] -= amp[0];
  jamp[28] += amp[0];
  jamp[34] += amp[0];
  jamp[44] -= amp[0];
  jamp[66] -= amp[0];
  jamp[75] -= amp[0];
  jamp[77] += amp[0];
  jamp[78] += amp[0];
  jamp[79] -= amp[0];
  jamp[81] -= amp[0];
  jamp[83] += amp[0];
  jamp[88] += amp[0];
  jamp[94] -= amp[0];
  jamp[108] += amp[0];
  VVV1_0( w[8], w[5], w[21], COUPs[0], &amp[0] );
  jamp[20] -= amp[0];
  jamp[28] += amp[0];
  jamp[31] -= amp[0];
  jamp[34] += amp[0];
  jamp[42] -= amp[0];
  jamp[52] += amp[0];
  jamp[66] -= amp[0];
  jamp[77] += amp[0];
  jamp[79] -= amp[0];
  jamp[80] += amp[0];
  jamp[81] -= amp[0];
  jamp[82] += amp[0];
  jamp[85] -= amp[0];
  jamp[88] += amp[0];
  jamp[91] -= amp[0];
  jamp[98] += amp[0];
  VVV1_0( w[8], w[5], w[71], COUPs[0], &amp[0] );
  jamp[10] -= amp[0];
  jamp[25] += amp[0];
  jamp[31] -= amp[0];
  jamp[42] -= amp[0];
  jamp[44] += amp[0];
  jamp[52] += amp[0];
  jamp[75] += amp[0];
  jamp[78] -= amp[0];
  jamp[80] += amp[0];
  jamp[82] += amp[0];
  jamp[83] -= amp[0];
  jamp[85] -= amp[0];
  jamp[91] -= amp[0];
  jamp[94] += amp[0];
  jamp[98] += amp[0];
  jamp[108] -= amp[0];

  // *** DIAGRAM 1199 OF 1240 ***

  // Wavefunction(s) for diagram number 1199
  // (none)

  // Amplitude(s) for diagram number 1199
  VVV1_0( w[1], w[8], w[98], COUPs[0], &amp[0] );
  jamp[11] -= amp[0];
  jamp[21] += amp[0];
  jamp[25] += amp[0];
  jamp[28] -= amp[0];
  jamp[34] -= amp[0];
  jamp[36] -= amp[0];
  jamp[37] += amp[0];
  jamp[39] += amp[0];
  jamp[41] -= amp[0];
  jamp[44] += amp[0];
  jamp[67] += amp[0];
  jamp[75] += amp[0];
  jamp[77] -= amp[0];
  jamp[88] -= amp[0];
  jamp[94] += amp[0];
  jamp[109] -= amp[0];
  VVV1_0( w[1], w[8], w[27], COUPs[0], &amp[0] );
  jamp[21] += amp[0];
  jamp[28] -= amp[0];
  jamp[31] += amp[0];
  jamp[34] -= amp[0];
  jamp[37] += amp[0];
  jamp[38] -= amp[0];
  jamp[39] += amp[0];
  jamp[40] -= amp[0];
  jamp[42] += amp[0];
  jamp[53] -= amp[0];
  jamp[67] += amp[0];
  jamp[77] -= amp[0];
  jamp[85] += amp[0];
  jamp[88] -= amp[0];
  jamp[91] += amp[0];
  jamp[99] -= amp[0];
  VVV1_0( w[1], w[8], w[16], COUPs[0], &amp[0] );
  jamp[11] += amp[0];
  jamp[25] -= amp[0];
  jamp[31] += amp[0];
  jamp[36] += amp[0];
  jamp[38] -= amp[0];
  jamp[40] -= amp[0];
  jamp[41] += amp[0];
  jamp[42] += amp[0];
  jamp[44] -= amp[0];
  jamp[53] -= amp[0];
  jamp[75] -= amp[0];
  jamp[85] += amp[0];
  jamp[91] += amp[0];
  jamp[94] -= amp[0];
  jamp[99] -= amp[0];
  jamp[109] += amp[0];

  // *** DIAGRAM 1200 OF 1240 ***

  // Wavefunction(s) for diagram number 1200
  // (none)

  // Amplitude(s) for diagram number 1200
  FFV1_0( w[3], w[39], w[66], COUPs[1], &amp[0] );
  jamp[75] -= cxtype( 0, 1 ) * amp[0];
  jamp[77] += cxtype( 0, 1 ) * amp[0];
  jamp[78] += cxtype( 0, 1 ) * amp[0];
  jamp[79] -= cxtype( 0, 1 ) * amp[0];
  jamp[81] -= cxtype( 0, 1 ) * amp[0];
  jamp[83] += cxtype( 0, 1 ) * amp[0];
  jamp[88] += cxtype( 0, 1 ) * amp[0];
  jamp[94] -= cxtype( 0, 1 ) * amp[0];
  FFV1_0( w[3], w[39], w[21], COUPs[1], &amp[0] );
  jamp[77] += cxtype( 0, 1 ) * amp[0];
  jamp[79] -= cxtype( 0, 1 ) * amp[0];
  jamp[80] += cxtype( 0, 1 ) * amp[0];
  jamp[81] -= cxtype( 0, 1 ) * amp[0];
  jamp[82] += cxtype( 0, 1 ) * amp[0];
  jamp[85] -= cxtype( 0, 1 ) * amp[0];
  jamp[88] += cxtype( 0, 1 ) * amp[0];
  jamp[91] -= cxtype( 0, 1 ) * amp[0];
  FFV1_0( w[3], w[39], w[71], COUPs[1], &amp[0] );
  jamp[75] += cxtype( 0, 1 ) * amp[0];
  jamp[78] -= cxtype( 0, 1 ) * amp[0];
  jamp[80] += cxtype( 0, 1 ) * amp[0];
  jamp[82] += cxtype( 0, 1 ) * amp[0];
  jamp[83] -= cxtype( 0, 1 ) * amp[0];
  jamp[85] -= cxtype( 0, 1 ) * amp[0];
  jamp[91] -= cxtype( 0, 1 ) * amp[0];
  jamp[94] += cxtype( 0, 1 ) * amp[0];

  // *** DIAGRAM 1201 OF 1240 ***

  // Wavefunction(s) for diagram number 1201
  // (none)

  // Amplitude(s) for diagram number 1201
  FFV1_0( w[24], w[39], w[1], COUPs[1], &amp[0] );
  jamp[78] += amp[0];
  jamp[79] -= amp[0];
  jamp[81] -= amp[0];
  jamp[83] += amp[0];
  FFV1_0( w[60], w[39], w[1], COUPs[1], &amp[0] );
  jamp[79] -= amp[0];
  jamp[80] += amp[0];
  jamp[81] -= amp[0];
  jamp[82] += amp[0];
  FFV1_0( w[72], w[39], w[1], COUPs[1], &amp[0] );
  jamp[78] -= amp[0];
  jamp[80] += amp[0];
  jamp[82] += amp[0];
  jamp[83] -= amp[0];

  // *** DIAGRAM 1202 OF 1240 ***

  // Wavefunction(s) for diagram number 1202
  // (none)

  // Amplitude(s) for diagram number 1202
  FFV1_0( w[38], w[2], w[66], COUPs[1], &amp[0] );
  jamp[10] -= cxtype( 0, 1 ) * amp[0];
  jamp[20] += cxtype( 0, 1 ) * amp[0];
  jamp[25] += cxtype( 0, 1 ) * amp[0];
  jamp[28] -= cxtype( 0, 1 ) * amp[0];
  jamp[34] -= cxtype( 0, 1 ) * amp[0];
  jamp[44] += cxtype( 0, 1 ) * amp[0];
  jamp[66] += cxtype( 0, 1 ) * amp[0];
  jamp[108] -= cxtype( 0, 1 ) * amp[0];
  FFV1_0( w[38], w[2], w[21], COUPs[1], &amp[0] );
  jamp[20] += cxtype( 0, 1 ) * amp[0];
  jamp[28] -= cxtype( 0, 1 ) * amp[0];
  jamp[31] += cxtype( 0, 1 ) * amp[0];
  jamp[34] -= cxtype( 0, 1 ) * amp[0];
  jamp[42] += cxtype( 0, 1 ) * amp[0];
  jamp[52] -= cxtype( 0, 1 ) * amp[0];
  jamp[66] += cxtype( 0, 1 ) * amp[0];
  jamp[98] -= cxtype( 0, 1 ) * amp[0];
  FFV1_0( w[38], w[2], w[71], COUPs[1], &amp[0] );
  jamp[10] += cxtype( 0, 1 ) * amp[0];
  jamp[25] -= cxtype( 0, 1 ) * amp[0];
  jamp[31] += cxtype( 0, 1 ) * amp[0];
  jamp[42] += cxtype( 0, 1 ) * amp[0];
  jamp[44] -= cxtype( 0, 1 ) * amp[0];
  jamp[52] -= cxtype( 0, 1 ) * amp[0];
  jamp[98] -= cxtype( 0, 1 ) * amp[0];
  jamp[108] += cxtype( 0, 1 ) * amp[0];

  // *** DIAGRAM 1203 OF 1240 ***

  // Wavefunction(s) for diagram number 1203
  // (none)

  // Amplitude(s) for diagram number 1203
  FFV1_0( w[38], w[29], w[1], COUPs[1], &amp[0] );
  jamp[10] += amp[0];
  jamp[20] -= amp[0];
  jamp[66] -= amp[0];
  jamp[108] += amp[0];
  FFV1_0( w[38], w[68], w[1], COUPs[1], &amp[0] );
  jamp[20] -= amp[0];
  jamp[52] += amp[0];
  jamp[66] -= amp[0];
  jamp[98] += amp[0];
  FFV1_0( w[38], w[23], w[1], COUPs[1], &amp[0] );
  jamp[10] -= amp[0];
  jamp[52] += amp[0];
  jamp[98] += amp[0];
  jamp[108] -= amp[0];

  // *** DIAGRAM 1204 OF 1240 ***

  // Wavefunction(s) for diagram number 1204
  VVVV1P0_1( w[0], w[5], w[6], COUPs[2], 0., 0., w[23] );
  VVVV3P0_1( w[0], w[5], w[6], COUPs[2], 0., 0., w[68] );
  VVVV4P0_1( w[0], w[5], w[6], COUPs[2], 0., 0., w[29] );
  FFV1_2( w[3], w[23], COUPs[1], cIPD[0], cIPD[1], w[71] );
  FFV1_2( w[3], w[68], COUPs[1], cIPD[0], cIPD[1], w[21] );
  FFV1_2( w[3], w[29], COUPs[1], cIPD[0], cIPD[1], w[66] );

  // Amplitude(s) for diagram number 1204
  FFV1_0( w[71], w[77], w[4], COUPs[1], &amp[0] );
  jamp[30] += amp[0];
  jamp[31] -= amp[0];
  jamp[33] -= amp[0];
  jamp[35] += amp[0];
  FFV1_0( w[21], w[77], w[4], COUPs[1], &amp[0] );
  jamp[31] -= amp[0];
  jamp[32] += amp[0];
  jamp[33] -= amp[0];
  jamp[34] += amp[0];
  FFV1_0( w[66], w[77], w[4], COUPs[1], &amp[0] );
  jamp[30] -= amp[0];
  jamp[32] += amp[0];
  jamp[34] += amp[0];
  jamp[35] -= amp[0];

  // *** DIAGRAM 1205 OF 1240 ***

  // Wavefunction(s) for diagram number 1205
  VVV1P0_1( w[23], w[4], COUPs[0], 0., 0., w[72] );
  VVV1P0_1( w[68], w[4], COUPs[0], 0., 0., w[60] );
  VVV1P0_1( w[29], w[4], COUPs[0], 0., 0., w[24] );

  // Amplitude(s) for diagram number 1205
  FFV1_0( w[3], w[77], w[72], COUPs[1], &amp[0] );
  jamp[27] -= cxtype( 0, 1 ) * amp[0];
  jamp[29] += cxtype( 0, 1 ) * amp[0];
  jamp[30] += cxtype( 0, 1 ) * amp[0];
  jamp[31] -= cxtype( 0, 1 ) * amp[0];
  jamp[33] -= cxtype( 0, 1 ) * amp[0];
  jamp[35] += cxtype( 0, 1 ) * amp[0];
  jamp[40] += cxtype( 0, 1 ) * amp[0];
  jamp[46] -= cxtype( 0, 1 ) * amp[0];
  FFV1_0( w[3], w[77], w[60], COUPs[1], &amp[0] );
  jamp[29] += cxtype( 0, 1 ) * amp[0];
  jamp[31] -= cxtype( 0, 1 ) * amp[0];
  jamp[32] += cxtype( 0, 1 ) * amp[0];
  jamp[33] -= cxtype( 0, 1 ) * amp[0];
  jamp[34] += cxtype( 0, 1 ) * amp[0];
  jamp[37] -= cxtype( 0, 1 ) * amp[0];
  jamp[40] += cxtype( 0, 1 ) * amp[0];
  jamp[43] -= cxtype( 0, 1 ) * amp[0];
  FFV1_0( w[3], w[77], w[24], COUPs[1], &amp[0] );
  jamp[27] += cxtype( 0, 1 ) * amp[0];
  jamp[30] -= cxtype( 0, 1 ) * amp[0];
  jamp[32] += cxtype( 0, 1 ) * amp[0];
  jamp[34] += cxtype( 0, 1 ) * amp[0];
  jamp[35] -= cxtype( 0, 1 ) * amp[0];
  jamp[37] -= cxtype( 0, 1 ) * amp[0];
  jamp[43] -= cxtype( 0, 1 ) * amp[0];
  jamp[46] += cxtype( 0, 1 ) * amp[0];

  // *** DIAGRAM 1206 OF 1240 ***

  // Wavefunction(s) for diagram number 1206
  // (none)

  // Amplitude(s) for diagram number 1206
  FFV1_0( w[46], w[77], w[23], COUPs[1], &amp[0] );
  jamp[27] += amp[0];
  jamp[29] -= amp[0];
  jamp[40] -= amp[0];
  jamp[46] += amp[0];
  FFV1_0( w[46], w[77], w[68], COUPs[1], &amp[0] );
  jamp[29] -= amp[0];
  jamp[37] += amp[0];
  jamp[40] -= amp[0];
  jamp[43] += amp[0];
  FFV1_0( w[46], w[77], w[29], COUPs[1], &amp[0] );
  jamp[27] -= amp[0];
  jamp[37] += amp[0];
  jamp[43] += amp[0];
  jamp[46] -= amp[0];

  // *** DIAGRAM 1207 OF 1240 ***

  // Wavefunction(s) for diagram number 1207
  FFV1_1( w[2], w[23], COUPs[1], cIPD[0], cIPD[1], w[77] );
  FFV1_1( w[2], w[68], COUPs[1], cIPD[0], cIPD[1], w[16] );
  FFV1_1( w[2], w[29], COUPs[1], cIPD[0], cIPD[1], w[27] );

  // Amplitude(s) for diagram number 1207
  FFV1_0( w[52], w[77], w[4], COUPs[1], &amp[0] );
  jamp[17] += amp[0];
  jamp[23] -= amp[0];
  jamp[91] -= amp[0];
  jamp[115] += amp[0];
  FFV1_0( w[52], w[16], w[4], COUPs[1], &amp[0] );
  jamp[23] -= amp[0];
  jamp[77] += amp[0];
  jamp[91] -= amp[0];
  jamp[101] += amp[0];
  FFV1_0( w[52], w[27], w[4], COUPs[1], &amp[0] );
  jamp[17] -= amp[0];
  jamp[77] += amp[0];
  jamp[101] += amp[0];
  jamp[115] -= amp[0];

  // *** DIAGRAM 1208 OF 1240 ***

  // Wavefunction(s) for diagram number 1208
  // (none)

  // Amplitude(s) for diagram number 1208
  FFV1_0( w[52], w[2], w[72], COUPs[1], &amp[0] );
  jamp[17] -= cxtype( 0, 1 ) * amp[0];
  jamp[23] += cxtype( 0, 1 ) * amp[0];
  jamp[51] += cxtype( 0, 1 ) * amp[0];
  jamp[53] -= cxtype( 0, 1 ) * amp[0];
  jamp[64] -= cxtype( 0, 1 ) * amp[0];
  jamp[70] += cxtype( 0, 1 ) * amp[0];
  jamp[91] += cxtype( 0, 1 ) * amp[0];
  jamp[115] -= cxtype( 0, 1 ) * amp[0];
  FFV1_0( w[52], w[2], w[60], COUPs[1], &amp[0] );
  jamp[23] += cxtype( 0, 1 ) * amp[0];
  jamp[53] -= cxtype( 0, 1 ) * amp[0];
  jamp[61] += cxtype( 0, 1 ) * amp[0];
  jamp[64] -= cxtype( 0, 1 ) * amp[0];
  jamp[67] += cxtype( 0, 1 ) * amp[0];
  jamp[77] -= cxtype( 0, 1 ) * amp[0];
  jamp[91] += cxtype( 0, 1 ) * amp[0];
  jamp[101] -= cxtype( 0, 1 ) * amp[0];
  FFV1_0( w[52], w[2], w[24], COUPs[1], &amp[0] );
  jamp[17] += cxtype( 0, 1 ) * amp[0];
  jamp[51] -= cxtype( 0, 1 ) * amp[0];
  jamp[61] += cxtype( 0, 1 ) * amp[0];
  jamp[67] += cxtype( 0, 1 ) * amp[0];
  jamp[70] -= cxtype( 0, 1 ) * amp[0];
  jamp[77] -= cxtype( 0, 1 ) * amp[0];
  jamp[101] -= cxtype( 0, 1 ) * amp[0];
  jamp[115] += cxtype( 0, 1 ) * amp[0];

  // *** DIAGRAM 1209 OF 1240 ***

  // Wavefunction(s) for diagram number 1209
  // (none)

  // Amplitude(s) for diagram number 1209
  FFV1_0( w[52], w[33], w[23], COUPs[1], &amp[0] );
  jamp[51] += amp[0];
  jamp[53] -= amp[0];
  jamp[64] -= amp[0];
  jamp[70] += amp[0];
  FFV1_0( w[52], w[33], w[68], COUPs[1], &amp[0] );
  jamp[53] -= amp[0];
  jamp[61] += amp[0];
  jamp[64] -= amp[0];
  jamp[67] += amp[0];
  FFV1_0( w[52], w[33], w[29], COUPs[1], &amp[0] );
  jamp[51] -= amp[0];
  jamp[61] += amp[0];
  jamp[67] += amp[0];
  jamp[70] -= amp[0];

  // *** DIAGRAM 1210 OF 1240 ***

  // Wavefunction(s) for diagram number 1210
  // (none)

  // Amplitude(s) for diagram number 1210
  FFV1_0( w[3], w[77], w[61], COUPs[1], &amp[0] );
  jamp[16] -= cxtype( 0, 1 ) * amp[0];
  jamp[17] += cxtype( 0, 1 ) * amp[0];
  jamp[22] += cxtype( 0, 1 ) * amp[0];
  jamp[23] -= cxtype( 0, 1 ) * amp[0];
  jamp[90] += cxtype( 0, 1 ) * amp[0];
  jamp[91] -= cxtype( 0, 1 ) * amp[0];
  jamp[114] -= cxtype( 0, 1 ) * amp[0];
  jamp[115] += cxtype( 0, 1 ) * amp[0];
  FFV1_0( w[3], w[16], w[61], COUPs[1], &amp[0] );
  jamp[22] += cxtype( 0, 1 ) * amp[0];
  jamp[23] -= cxtype( 0, 1 ) * amp[0];
  jamp[76] -= cxtype( 0, 1 ) * amp[0];
  jamp[77] += cxtype( 0, 1 ) * amp[0];
  jamp[90] += cxtype( 0, 1 ) * amp[0];
  jamp[91] -= cxtype( 0, 1 ) * amp[0];
  jamp[100] -= cxtype( 0, 1 ) * amp[0];
  jamp[101] += cxtype( 0, 1 ) * amp[0];
  FFV1_0( w[3], w[27], w[61], COUPs[1], &amp[0] );
  jamp[16] += cxtype( 0, 1 ) * amp[0];
  jamp[17] -= cxtype( 0, 1 ) * amp[0];
  jamp[76] -= cxtype( 0, 1 ) * amp[0];
  jamp[77] += cxtype( 0, 1 ) * amp[0];
  jamp[100] -= cxtype( 0, 1 ) * amp[0];
  jamp[101] += cxtype( 0, 1 ) * amp[0];
  jamp[114] += cxtype( 0, 1 ) * amp[0];
  jamp[115] -= cxtype( 0, 1 ) * amp[0];

  // *** DIAGRAM 1211 OF 1240 ***

  // Wavefunction(s) for diagram number 1211
  // (none)

  // Amplitude(s) for diagram number 1211
  FFV1_0( w[71], w[2], w[61], COUPs[1], &amp[0] );
  jamp[30] -= cxtype( 0, 1 ) * amp[0];
  jamp[31] += cxtype( 0, 1 ) * amp[0];
  jamp[33] += cxtype( 0, 1 ) * amp[0];
  jamp[35] -= cxtype( 0, 1 ) * amp[0];
  jamp[54] += cxtype( 0, 1 ) * amp[0];
  jamp[55] -= cxtype( 0, 1 ) * amp[0];
  jamp[57] -= cxtype( 0, 1 ) * amp[0];
  jamp[59] += cxtype( 0, 1 ) * amp[0];
  FFV1_0( w[21], w[2], w[61], COUPs[1], &amp[0] );
  jamp[31] += cxtype( 0, 1 ) * amp[0];
  jamp[32] -= cxtype( 0, 1 ) * amp[0];
  jamp[33] += cxtype( 0, 1 ) * amp[0];
  jamp[34] -= cxtype( 0, 1 ) * amp[0];
  jamp[55] -= cxtype( 0, 1 ) * amp[0];
  jamp[56] += cxtype( 0, 1 ) * amp[0];
  jamp[57] -= cxtype( 0, 1 ) * amp[0];
  jamp[58] += cxtype( 0, 1 ) * amp[0];
  FFV1_0( w[66], w[2], w[61], COUPs[1], &amp[0] );
  jamp[30] += cxtype( 0, 1 ) * amp[0];
  jamp[32] -= cxtype( 0, 1 ) * amp[0];
  jamp[34] -= cxtype( 0, 1 ) * amp[0];
  jamp[35] += cxtype( 0, 1 ) * amp[0];
  jamp[54] -= cxtype( 0, 1 ) * amp[0];
  jamp[56] += cxtype( 0, 1 ) * amp[0];
  jamp[58] += cxtype( 0, 1 ) * amp[0];
  jamp[59] -= cxtype( 0, 1 ) * amp[0];

  // *** DIAGRAM 1212 OF 1240 ***

  // Wavefunction(s) for diagram number 1212
  // (none)

  // Amplitude(s) for diagram number 1212
  VVV1_0( w[23], w[61], w[8], COUPs[0], &amp[0] );
  jamp[16] -= amp[0];
  jamp[17] += amp[0];
  jamp[22] += amp[0];
  jamp[23] -= amp[0];
  jamp[30] += amp[0];
  jamp[31] -= amp[0];
  jamp[33] -= amp[0];
  jamp[35] += amp[0];
  jamp[54] -= amp[0];
  jamp[55] += amp[0];
  jamp[57] += amp[0];
  jamp[59] -= amp[0];
  jamp[90] += amp[0];
  jamp[91] -= amp[0];
  jamp[114] -= amp[0];
  jamp[115] += amp[0];
  VVV1_0( w[68], w[61], w[8], COUPs[0], &amp[0] );
  jamp[22] += amp[0];
  jamp[23] -= amp[0];
  jamp[31] -= amp[0];
  jamp[32] += amp[0];
  jamp[33] -= amp[0];
  jamp[34] += amp[0];
  jamp[55] += amp[0];
  jamp[56] -= amp[0];
  jamp[57] += amp[0];
  jamp[58] -= amp[0];
  jamp[76] -= amp[0];
  jamp[77] += amp[0];
  jamp[90] += amp[0];
  jamp[91] -= amp[0];
  jamp[100] -= amp[0];
  jamp[101] += amp[0];
  VVV1_0( w[29], w[61], w[8], COUPs[0], &amp[0] );
  jamp[16] += amp[0];
  jamp[17] -= amp[0];
  jamp[30] -= amp[0];
  jamp[32] += amp[0];
  jamp[34] += amp[0];
  jamp[35] -= amp[0];
  jamp[54] += amp[0];
  jamp[56] -= amp[0];
  jamp[58] -= amp[0];
  jamp[59] += amp[0];
  jamp[76] -= amp[0];
  jamp[77] += amp[0];
  jamp[100] -= amp[0];
  jamp[101] += amp[0];
  jamp[114] += amp[0];
  jamp[115] -= amp[0];

  // *** DIAGRAM 1213 OF 1240 ***

  // Wavefunction(s) for diagram number 1213
  // (none)

  // Amplitude(s) for diagram number 1213
  VVVV1_0( w[23], w[1], w[8], w[4], COUPs[2], &amp[0] );
  jamp[16] += amp[0];
  jamp[22] -= amp[0];
  jamp[27] -= amp[0];
  jamp[29] += amp[0];
  jamp[40] += amp[0];
  jamp[46] -= amp[0];
  jamp[51] -= amp[0];
  jamp[53] += amp[0];
  jamp[54] += amp[0];
  jamp[55] -= amp[0];
  jamp[57] -= amp[0];
  jamp[59] += amp[0];
  jamp[64] += amp[0];
  jamp[70] -= amp[0];
  jamp[90] -= amp[0];
  jamp[114] += amp[0];
  VVVV3_0( w[23], w[1], w[8], w[4], COUPs[2], &amp[0] );
  jamp[16] += amp[0];
  jamp[17] -= amp[0];
  jamp[22] -= amp[0];
  jamp[23] += amp[0];
  jamp[30] -= amp[0];
  jamp[31] += amp[0];
  jamp[33] += amp[0];
  jamp[35] -= amp[0];
  jamp[54] += amp[0];
  jamp[55] -= amp[0];
  jamp[57] -= amp[0];
  jamp[59] += amp[0];
  jamp[90] -= amp[0];
  jamp[91] += amp[0];
  jamp[114] += amp[0];
  jamp[115] -= amp[0];
  VVVV4_0( w[23], w[1], w[8], w[4], COUPs[2], &amp[0] );
  jamp[17] -= amp[0];
  jamp[23] += amp[0];
  jamp[27] += amp[0];
  jamp[29] -= amp[0];
  jamp[30] -= amp[0];
  jamp[31] += amp[0];
  jamp[33] += amp[0];
  jamp[35] -= amp[0];
  jamp[40] -= amp[0];
  jamp[46] += amp[0];
  jamp[51] += amp[0];
  jamp[53] -= amp[0];
  jamp[64] -= amp[0];
  jamp[70] += amp[0];
  jamp[91] += amp[0];
  jamp[115] -= amp[0];
  VVVV1_0( w[68], w[1], w[8], w[4], COUPs[2], &amp[0] );
  jamp[22] -= amp[0];
  jamp[29] += amp[0];
  jamp[37] -= amp[0];
  jamp[40] += amp[0];
  jamp[43] -= amp[0];
  jamp[53] += amp[0];
  jamp[55] -= amp[0];
  jamp[56] += amp[0];
  jamp[57] -= amp[0];
  jamp[58] += amp[0];
  jamp[61] -= amp[0];
  jamp[64] += amp[0];
  jamp[67] -= amp[0];
  jamp[76] += amp[0];
  jamp[90] -= amp[0];
  jamp[100] += amp[0];
  VVVV3_0( w[68], w[1], w[8], w[4], COUPs[2], &amp[0] );
  jamp[22] -= amp[0];
  jamp[23] += amp[0];
  jamp[31] += amp[0];
  jamp[32] -= amp[0];
  jamp[33] += amp[0];
  jamp[34] -= amp[0];
  jamp[55] -= amp[0];
  jamp[56] += amp[0];
  jamp[57] -= amp[0];
  jamp[58] += amp[0];
  jamp[76] += amp[0];
  jamp[77] -= amp[0];
  jamp[90] -= amp[0];
  jamp[91] += amp[0];
  jamp[100] += amp[0];
  jamp[101] -= amp[0];
  VVVV4_0( w[68], w[1], w[8], w[4], COUPs[2], &amp[0] );
  jamp[23] += amp[0];
  jamp[29] -= amp[0];
  jamp[31] += amp[0];
  jamp[32] -= amp[0];
  jamp[33] += amp[0];
  jamp[34] -= amp[0];
  jamp[37] += amp[0];
  jamp[40] -= amp[0];
  jamp[43] += amp[0];
  jamp[53] -= amp[0];
  jamp[61] += amp[0];
  jamp[64] -= amp[0];
  jamp[67] += amp[0];
  jamp[77] -= amp[0];
  jamp[91] += amp[0];
  jamp[101] -= amp[0];
  VVVV1_0( w[29], w[1], w[8], w[4], COUPs[2], &amp[0] );
  jamp[16] -= amp[0];
  jamp[27] += amp[0];
  jamp[37] -= amp[0];
  jamp[43] -= amp[0];
  jamp[46] += amp[0];
  jamp[51] += amp[0];
  jamp[54] -= amp[0];
  jamp[56] += amp[0];
  jamp[58] += amp[0];
  jamp[59] -= amp[0];
  jamp[61] -= amp[0];
  jamp[67] -= amp[0];
  jamp[70] += amp[0];
  jamp[76] += amp[0];
  jamp[100] += amp[0];
  jamp[114] -= amp[0];
  VVVV3_0( w[29], w[1], w[8], w[4], COUPs[2], &amp[0] );
  jamp[16] -= amp[0];
  jamp[17] += amp[0];
  jamp[30] += amp[0];
  jamp[32] -= amp[0];
  jamp[34] -= amp[0];
  jamp[35] += amp[0];
  jamp[54] -= amp[0];
  jamp[56] += amp[0];
  jamp[58] += amp[0];
  jamp[59] -= amp[0];
  jamp[76] += amp[0];
  jamp[77] -= amp[0];
  jamp[100] += amp[0];
  jamp[101] -= amp[0];
  jamp[114] -= amp[0];
  jamp[115] += amp[0];
  VVVV4_0( w[29], w[1], w[8], w[4], COUPs[2], &amp[0] );
  jamp[17] += amp[0];
  jamp[27] -= amp[0];
  jamp[30] += amp[0];
  jamp[32] -= amp[0];
  jamp[34] -= amp[0];
  jamp[35] += amp[0];
  jamp[37] += amp[0];
  jamp[43] += amp[0];
  jamp[46] -= amp[0];
  jamp[51] -= amp[0];
  jamp[61] += amp[0];
  jamp[67] += amp[0];
  jamp[70] -= amp[0];
  jamp[77] -= amp[0];
  jamp[101] -= amp[0];
  jamp[115] += amp[0];

  // *** DIAGRAM 1214 OF 1240 ***

  // Wavefunction(s) for diagram number 1214
  VVV1P0_1( w[23], w[1], COUPs[0], 0., 0., w[61] );
  VVV1P0_1( w[68], w[1], COUPs[0], 0., 0., w[23] );
  VVV1P0_1( w[29], w[1], COUPs[0], 0., 0., w[68] );

  // Amplitude(s) for diagram number 1214
  VVV1_0( w[8], w[4], w[61], COUPs[0], &amp[0] );
  jamp[16] += amp[0];
  jamp[22] -= amp[0];
  jamp[27] -= amp[0];
  jamp[29] += amp[0];
  jamp[40] += amp[0];
  jamp[46] -= amp[0];
  jamp[51] -= amp[0];
  jamp[53] += amp[0];
  jamp[54] += amp[0];
  jamp[55] -= amp[0];
  jamp[57] -= amp[0];
  jamp[59] += amp[0];
  jamp[64] += amp[0];
  jamp[70] -= amp[0];
  jamp[90] -= amp[0];
  jamp[114] += amp[0];
  VVV1_0( w[8], w[4], w[23], COUPs[0], &amp[0] );
  jamp[22] -= amp[0];
  jamp[29] += amp[0];
  jamp[37] -= amp[0];
  jamp[40] += amp[0];
  jamp[43] -= amp[0];
  jamp[53] += amp[0];
  jamp[55] -= amp[0];
  jamp[56] += amp[0];
  jamp[57] -= amp[0];
  jamp[58] += amp[0];
  jamp[61] -= amp[0];
  jamp[64] += amp[0];
  jamp[67] -= amp[0];
  jamp[76] += amp[0];
  jamp[90] -= amp[0];
  jamp[100] += amp[0];
  VVV1_0( w[8], w[4], w[68], COUPs[0], &amp[0] );
  jamp[16] -= amp[0];
  jamp[27] += amp[0];
  jamp[37] -= amp[0];
  jamp[43] -= amp[0];
  jamp[46] += amp[0];
  jamp[51] += amp[0];
  jamp[54] -= amp[0];
  jamp[56] += amp[0];
  jamp[58] += amp[0];
  jamp[59] -= amp[0];
  jamp[61] -= amp[0];
  jamp[67] -= amp[0];
  jamp[70] += amp[0];
  jamp[76] += amp[0];
  jamp[100] += amp[0];
  jamp[114] -= amp[0];

  // *** DIAGRAM 1215 OF 1240 ***

  // Wavefunction(s) for diagram number 1215
  // (none)

  // Amplitude(s) for diagram number 1215
  VVV1_0( w[1], w[8], w[72], COUPs[0], &amp[0] );
  jamp[17] -= amp[0];
  jamp[23] += amp[0];
  jamp[27] += amp[0];
  jamp[29] -= amp[0];
  jamp[30] -= amp[0];
  jamp[31] += amp[0];
  jamp[33] += amp[0];
  jamp[35] -= amp[0];
  jamp[40] -= amp[0];
  jamp[46] += amp[0];
  jamp[51] += amp[0];
  jamp[53] -= amp[0];
  jamp[64] -= amp[0];
  jamp[70] += amp[0];
  jamp[91] += amp[0];
  jamp[115] -= amp[0];
  VVV1_0( w[1], w[8], w[60], COUPs[0], &amp[0] );
  jamp[23] += amp[0];
  jamp[29] -= amp[0];
  jamp[31] += amp[0];
  jamp[32] -= amp[0];
  jamp[33] += amp[0];
  jamp[34] -= amp[0];
  jamp[37] += amp[0];
  jamp[40] -= amp[0];
  jamp[43] += amp[0];
  jamp[53] -= amp[0];
  jamp[61] += amp[0];
  jamp[64] -= amp[0];
  jamp[67] += amp[0];
  jamp[77] -= amp[0];
  jamp[91] += amp[0];
  jamp[101] -= amp[0];
  VVV1_0( w[1], w[8], w[24], COUPs[0], &amp[0] );
  jamp[17] += amp[0];
  jamp[27] -= amp[0];
  jamp[30] += amp[0];
  jamp[32] -= amp[0];
  jamp[34] -= amp[0];
  jamp[35] += amp[0];
  jamp[37] += amp[0];
  jamp[43] += amp[0];
  jamp[46] -= amp[0];
  jamp[51] -= amp[0];
  jamp[61] += amp[0];
  jamp[67] += amp[0];
  jamp[70] -= amp[0];
  jamp[77] -= amp[0];
  jamp[101] -= amp[0];
  jamp[115] += amp[0];

  // *** DIAGRAM 1216 OF 1240 ***

  // Wavefunction(s) for diagram number 1216
  // (none)

  // Amplitude(s) for diagram number 1216
  FFV1_0( w[3], w[33], w[61], COUPs[1], &amp[0] );
  jamp[51] -= cxtype( 0, 1 ) * amp[0];
  jamp[53] += cxtype( 0, 1 ) * amp[0];
  jamp[54] += cxtype( 0, 1 ) * amp[0];
  jamp[55] -= cxtype( 0, 1 ) * amp[0];
  jamp[57] -= cxtype( 0, 1 ) * amp[0];
  jamp[59] += cxtype( 0, 1 ) * amp[0];
  jamp[64] += cxtype( 0, 1 ) * amp[0];
  jamp[70] -= cxtype( 0, 1 ) * amp[0];
  FFV1_0( w[3], w[33], w[23], COUPs[1], &amp[0] );
  jamp[53] += cxtype( 0, 1 ) * amp[0];
  jamp[55] -= cxtype( 0, 1 ) * amp[0];
  jamp[56] += cxtype( 0, 1 ) * amp[0];
  jamp[57] -= cxtype( 0, 1 ) * amp[0];
  jamp[58] += cxtype( 0, 1 ) * amp[0];
  jamp[61] -= cxtype( 0, 1 ) * amp[0];
  jamp[64] += cxtype( 0, 1 ) * amp[0];
  jamp[67] -= cxtype( 0, 1 ) * amp[0];
  FFV1_0( w[3], w[33], w[68], COUPs[1], &amp[0] );
  jamp[51] += cxtype( 0, 1 ) * amp[0];
  jamp[54] -= cxtype( 0, 1 ) * amp[0];
  jamp[56] += cxtype( 0, 1 ) * amp[0];
  jamp[58] += cxtype( 0, 1 ) * amp[0];
  jamp[59] -= cxtype( 0, 1 ) * amp[0];
  jamp[61] -= cxtype( 0, 1 ) * amp[0];
  jamp[67] -= cxtype( 0, 1 ) * amp[0];
  jamp[70] += cxtype( 0, 1 ) * amp[0];

  // *** DIAGRAM 1217 OF 1240 ***

  // Wavefunction(s) for diagram number 1217
  // (none)

  // Amplitude(s) for diagram number 1217
  FFV1_0( w[71], w[33], w[1], COUPs[1], &amp[0] );
  jamp[54] += amp[0];
  jamp[55] -= amp[0];
  jamp[57] -= amp[0];
  jamp[59] += amp[0];
  FFV1_0( w[21], w[33], w[1], COUPs[1], &amp[0] );
  jamp[55] -= amp[0];
  jamp[56] += amp[0];
  jamp[57] -= amp[0];
  jamp[58] += amp[0];
  FFV1_0( w[66], w[33], w[1], COUPs[1], &amp[0] );
  jamp[54] -= amp[0];
  jamp[56] += amp[0];
  jamp[58] += amp[0];
  jamp[59] -= amp[0];

  // *** DIAGRAM 1218 OF 1240 ***

  // Wavefunction(s) for diagram number 1218
  // (none)

  // Amplitude(s) for diagram number 1218
  FFV1_0( w[46], w[2], w[61], COUPs[1], &amp[0] );
  jamp[16] -= cxtype( 0, 1 ) * amp[0];
  jamp[22] += cxtype( 0, 1 ) * amp[0];
  jamp[27] += cxtype( 0, 1 ) * amp[0];
  jamp[29] -= cxtype( 0, 1 ) * amp[0];
  jamp[40] -= cxtype( 0, 1 ) * amp[0];
  jamp[46] += cxtype( 0, 1 ) * amp[0];
  jamp[90] += cxtype( 0, 1 ) * amp[0];
  jamp[114] -= cxtype( 0, 1 ) * amp[0];
  FFV1_0( w[46], w[2], w[23], COUPs[1], &amp[0] );
  jamp[22] += cxtype( 0, 1 ) * amp[0];
  jamp[29] -= cxtype( 0, 1 ) * amp[0];
  jamp[37] += cxtype( 0, 1 ) * amp[0];
  jamp[40] -= cxtype( 0, 1 ) * amp[0];
  jamp[43] += cxtype( 0, 1 ) * amp[0];
  jamp[76] -= cxtype( 0, 1 ) * amp[0];
  jamp[90] += cxtype( 0, 1 ) * amp[0];
  jamp[100] -= cxtype( 0, 1 ) * amp[0];
  FFV1_0( w[46], w[2], w[68], COUPs[1], &amp[0] );
  jamp[16] += cxtype( 0, 1 ) * amp[0];
  jamp[27] -= cxtype( 0, 1 ) * amp[0];
  jamp[37] += cxtype( 0, 1 ) * amp[0];
  jamp[43] += cxtype( 0, 1 ) * amp[0];
  jamp[46] -= cxtype( 0, 1 ) * amp[0];
  jamp[76] -= cxtype( 0, 1 ) * amp[0];
  jamp[100] -= cxtype( 0, 1 ) * amp[0];
  jamp[114] += cxtype( 0, 1 ) * amp[0];

  // *** DIAGRAM 1219 OF 1240 ***

  // Wavefunction(s) for diagram number 1219
  // (none)

  // Amplitude(s) for diagram number 1219
  FFV1_0( w[46], w[77], w[1], COUPs[1], &amp[0] );
  jamp[16] += amp[0];
  jamp[22] -= amp[0];
  jamp[90] -= amp[0];
  jamp[114] += amp[0];
  FFV1_0( w[46], w[16], w[1], COUPs[1], &amp[0] );
  jamp[22] -= amp[0];
  jamp[76] += amp[0];
  jamp[90] -= amp[0];
  jamp[100] += amp[0];
  FFV1_0( w[46], w[27], w[1], COUPs[1], &amp[0] );
  jamp[16] -= amp[0];
  jamp[76] += amp[0];
  jamp[100] += amp[0];
  jamp[114] -= amp[0];

  // *** DIAGRAM 1220 OF 1240 ***

  // Wavefunction(s) for diagram number 1220
  // (none)

  // Amplitude(s) for diagram number 1220
  VVVV1_0( w[0], w[73], w[8], w[6], COUPs[2], &amp[0] );
  jamp[0] += amp[0];
  jamp[2] -= amp[0];
  jamp[8] -= amp[0];
  jamp[14] += amp[0];
  jamp[32] -= amp[0];
  jamp[38] += amp[0];
  jamp[62] += amp[0];
  jamp[86] -= amp[0];
  jamp[96] -= amp[0];
  jamp[97] += amp[0];
  jamp[99] += amp[0];
  jamp[101] -= amp[0];
  jamp[105] += amp[0];
  jamp[107] -= amp[0];
  jamp[113] -= amp[0];
  jamp[119] += amp[0];
  VVVV3_0( w[0], w[73], w[8], w[6], COUPs[2], &amp[0] );
  jamp[0] += amp[0];
  jamp[2] -= amp[0];
  jamp[8] -= amp[0];
  jamp[14] += amp[0];
  jamp[18] -= amp[0];
  jamp[19] += amp[0];
  jamp[21] += amp[0];
  jamp[23] -= amp[0];
  jamp[33] -= amp[0];
  jamp[39] += amp[0];
  jamp[63] += amp[0];
  jamp[87] -= amp[0];
  jamp[105] += amp[0];
  jamp[107] -= amp[0];
  jamp[113] -= amp[0];
  jamp[119] += amp[0];
  VVVV4_0( w[0], w[73], w[8], w[6], COUPs[2], &amp[0] );
  jamp[18] -= amp[0];
  jamp[19] += amp[0];
  jamp[21] += amp[0];
  jamp[23] -= amp[0];
  jamp[32] += amp[0];
  jamp[33] -= amp[0];
  jamp[38] -= amp[0];
  jamp[39] += amp[0];
  jamp[62] -= amp[0];
  jamp[63] += amp[0];
  jamp[86] += amp[0];
  jamp[87] -= amp[0];
  jamp[96] += amp[0];
  jamp[97] -= amp[0];
  jamp[99] -= amp[0];
  jamp[101] += amp[0];
  VVVV1_0( w[0], w[79], w[8], w[6], COUPs[2], &amp[0] );
  jamp[2] -= amp[0];
  jamp[6] += amp[0];
  jamp[8] -= amp[0];
  jamp[12] += amp[0];
  jamp[38] += amp[0];
  jamp[56] -= amp[0];
  jamp[62] += amp[0];
  jamp[80] -= amp[0];
  jamp[97] += amp[0];
  jamp[98] -= amp[0];
  jamp[99] += amp[0];
  jamp[100] -= amp[0];
  jamp[107] -= amp[0];
  jamp[111] += amp[0];
  jamp[113] -= amp[0];
  jamp[117] += amp[0];
  VVVV3_0( w[0], w[79], w[8], w[6], COUPs[2], &amp[0] );
  jamp[2] -= amp[0];
  jamp[6] += amp[0];
  jamp[8] -= amp[0];
  jamp[12] += amp[0];
  jamp[19] += amp[0];
  jamp[20] -= amp[0];
  jamp[21] += amp[0];
  jamp[22] -= amp[0];
  jamp[39] += amp[0];
  jamp[57] -= amp[0];
  jamp[63] += amp[0];
  jamp[81] -= amp[0];
  jamp[107] -= amp[0];
  jamp[111] += amp[0];
  jamp[113] -= amp[0];
  jamp[117] += amp[0];
  VVVV4_0( w[0], w[79], w[8], w[6], COUPs[2], &amp[0] );
  jamp[19] += amp[0];
  jamp[20] -= amp[0];
  jamp[21] += amp[0];
  jamp[22] -= amp[0];
  jamp[38] -= amp[0];
  jamp[39] += amp[0];
  jamp[56] += amp[0];
  jamp[57] -= amp[0];
  jamp[62] -= amp[0];
  jamp[63] += amp[0];
  jamp[80] += amp[0];
  jamp[81] -= amp[0];
  jamp[97] -= amp[0];
  jamp[98] += amp[0];
  jamp[99] -= amp[0];
  jamp[100] += amp[0];
  VVVV1_0( w[0], w[80], w[8], w[6], COUPs[2], &amp[0] );
  jamp[0] -= amp[0];
  jamp[6] += amp[0];
  jamp[12] += amp[0];
  jamp[14] -= amp[0];
  jamp[32] += amp[0];
  jamp[56] -= amp[0];
  jamp[80] -= amp[0];
  jamp[86] += amp[0];
  jamp[96] += amp[0];
  jamp[98] -= amp[0];
  jamp[100] -= amp[0];
  jamp[101] += amp[0];
  jamp[105] -= amp[0];
  jamp[111] += amp[0];
  jamp[117] += amp[0];
  jamp[119] -= amp[0];
  VVVV3_0( w[0], w[80], w[8], w[6], COUPs[2], &amp[0] );
  jamp[0] -= amp[0];
  jamp[6] += amp[0];
  jamp[12] += amp[0];
  jamp[14] -= amp[0];
  jamp[18] += amp[0];
  jamp[20] -= amp[0];
  jamp[22] -= amp[0];
  jamp[23] += amp[0];
  jamp[33] += amp[0];
  jamp[57] -= amp[0];
  jamp[81] -= amp[0];
  jamp[87] += amp[0];
  jamp[105] -= amp[0];
  jamp[111] += amp[0];
  jamp[117] += amp[0];
  jamp[119] -= amp[0];
  VVVV4_0( w[0], w[80], w[8], w[6], COUPs[2], &amp[0] );
  jamp[18] += amp[0];
  jamp[20] -= amp[0];
  jamp[22] -= amp[0];
  jamp[23] += amp[0];
  jamp[32] -= amp[0];
  jamp[33] += amp[0];
  jamp[56] += amp[0];
  jamp[57] -= amp[0];
  jamp[80] += amp[0];
  jamp[81] -= amp[0];
  jamp[86] -= amp[0];
  jamp[87] += amp[0];
  jamp[96] -= amp[0];
  jamp[98] += amp[0];
  jamp[100] += amp[0];
  jamp[101] -= amp[0];

  // *** DIAGRAM 1221 OF 1240 ***

  // Wavefunction(s) for diagram number 1221
  VVV1P0_1( w[0], w[73], COUPs[0], 0., 0., w[27] );
  VVV1P0_1( w[0], w[79], COUPs[0], 0., 0., w[1] );
  VVV1P0_1( w[0], w[80], COUPs[0], 0., 0., w[16] );

  // Amplitude(s) for diagram number 1221
  VVV1_0( w[8], w[6], w[27], COUPs[0], &amp[0] );
  jamp[0] += amp[0];
  jamp[2] -= amp[0];
  jamp[8] -= amp[0];
  jamp[14] += amp[0];
  jamp[32] -= amp[0];
  jamp[38] += amp[0];
  jamp[62] += amp[0];
  jamp[86] -= amp[0];
  jamp[96] -= amp[0];
  jamp[97] += amp[0];
  jamp[99] += amp[0];
  jamp[101] -= amp[0];
  jamp[105] += amp[0];
  jamp[107] -= amp[0];
  jamp[113] -= amp[0];
  jamp[119] += amp[0];
  VVV1_0( w[8], w[6], w[1], COUPs[0], &amp[0] );
  jamp[2] -= amp[0];
  jamp[6] += amp[0];
  jamp[8] -= amp[0];
  jamp[12] += amp[0];
  jamp[38] += amp[0];
  jamp[56] -= amp[0];
  jamp[62] += amp[0];
  jamp[80] -= amp[0];
  jamp[97] += amp[0];
  jamp[98] -= amp[0];
  jamp[99] += amp[0];
  jamp[100] -= amp[0];
  jamp[107] -= amp[0];
  jamp[111] += amp[0];
  jamp[113] -= amp[0];
  jamp[117] += amp[0];
  VVV1_0( w[8], w[6], w[16], COUPs[0], &amp[0] );
  jamp[0] -= amp[0];
  jamp[6] += amp[0];
  jamp[12] += amp[0];
  jamp[14] -= amp[0];
  jamp[32] += amp[0];
  jamp[56] -= amp[0];
  jamp[80] -= amp[0];
  jamp[86] += amp[0];
  jamp[96] += amp[0];
  jamp[98] -= amp[0];
  jamp[100] -= amp[0];
  jamp[101] += amp[0];
  jamp[105] -= amp[0];
  jamp[111] += amp[0];
  jamp[117] += amp[0];
  jamp[119] -= amp[0];

  // *** DIAGRAM 1222 OF 1240 ***

  // Wavefunction(s) for diagram number 1222
  // (none)

  // Amplitude(s) for diagram number 1222
  VVV1_0( w[73], w[6], w[56], COUPs[0], &amp[0] );
  jamp[0] += amp[0];
  jamp[2] -= amp[0];
  jamp[8] -= amp[0];
  jamp[14] += amp[0];
  jamp[18] -= amp[0];
  jamp[19] += amp[0];
  jamp[21] += amp[0];
  jamp[23] -= amp[0];
  jamp[33] -= amp[0];
  jamp[39] += amp[0];
  jamp[63] += amp[0];
  jamp[87] -= amp[0];
  jamp[105] += amp[0];
  jamp[107] -= amp[0];
  jamp[113] -= amp[0];
  jamp[119] += amp[0];
  VVV1_0( w[79], w[6], w[56], COUPs[0], &amp[0] );
  jamp[2] -= amp[0];
  jamp[6] += amp[0];
  jamp[8] -= amp[0];
  jamp[12] += amp[0];
  jamp[19] += amp[0];
  jamp[20] -= amp[0];
  jamp[21] += amp[0];
  jamp[22] -= amp[0];
  jamp[39] += amp[0];
  jamp[57] -= amp[0];
  jamp[63] += amp[0];
  jamp[81] -= amp[0];
  jamp[107] -= amp[0];
  jamp[111] += amp[0];
  jamp[113] -= amp[0];
  jamp[117] += amp[0];
  VVV1_0( w[80], w[6], w[56], COUPs[0], &amp[0] );
  jamp[0] -= amp[0];
  jamp[6] += amp[0];
  jamp[12] += amp[0];
  jamp[14] -= amp[0];
  jamp[18] += amp[0];
  jamp[20] -= amp[0];
  jamp[22] -= amp[0];
  jamp[23] += amp[0];
  jamp[33] += amp[0];
  jamp[57] -= amp[0];
  jamp[81] -= amp[0];
  jamp[87] += amp[0];
  jamp[105] -= amp[0];
  jamp[111] += amp[0];
  jamp[117] += amp[0];
  jamp[119] -= amp[0];

  // *** DIAGRAM 1223 OF 1240 ***

  // Wavefunction(s) for diagram number 1223
  // (none)

  // Amplitude(s) for diagram number 1223
  FFV1_0( w[3], w[47], w[27], COUPs[1], &amp[0] );
  jamp[96] -= cxtype( 0, 1 ) * amp[0];
  jamp[97] += cxtype( 0, 1 ) * amp[0];
  jamp[99] += cxtype( 0, 1 ) * amp[0];
  jamp[101] -= cxtype( 0, 1 ) * amp[0];
  jamp[105] += cxtype( 0, 1 ) * amp[0];
  jamp[107] -= cxtype( 0, 1 ) * amp[0];
  jamp[113] -= cxtype( 0, 1 ) * amp[0];
  jamp[119] += cxtype( 0, 1 ) * amp[0];
  FFV1_0( w[3], w[47], w[1], COUPs[1], &amp[0] );
  jamp[97] += cxtype( 0, 1 ) * amp[0];
  jamp[98] -= cxtype( 0, 1 ) * amp[0];
  jamp[99] += cxtype( 0, 1 ) * amp[0];
  jamp[100] -= cxtype( 0, 1 ) * amp[0];
  jamp[107] -= cxtype( 0, 1 ) * amp[0];
  jamp[111] += cxtype( 0, 1 ) * amp[0];
  jamp[113] -= cxtype( 0, 1 ) * amp[0];
  jamp[117] += cxtype( 0, 1 ) * amp[0];
  FFV1_0( w[3], w[47], w[16], COUPs[1], &amp[0] );
  jamp[96] += cxtype( 0, 1 ) * amp[0];
  jamp[98] -= cxtype( 0, 1 ) * amp[0];
  jamp[100] -= cxtype( 0, 1 ) * amp[0];
  jamp[101] += cxtype( 0, 1 ) * amp[0];
  jamp[105] -= cxtype( 0, 1 ) * amp[0];
  jamp[111] += cxtype( 0, 1 ) * amp[0];
  jamp[117] += cxtype( 0, 1 ) * amp[0];
  jamp[119] -= cxtype( 0, 1 ) * amp[0];

  // *** DIAGRAM 1224 OF 1240 ***

  // Wavefunction(s) for diagram number 1224
  // (none)

  // Amplitude(s) for diagram number 1224
  FFV1_0( w[3], w[113], w[73], COUPs[1], &amp[0] );
  jamp[96] += amp[0];
  jamp[97] -= amp[0];
  jamp[99] -= amp[0];
  jamp[101] += amp[0];
  FFV1_0( w[3], w[113], w[79], COUPs[1], &amp[0] );
  jamp[97] -= amp[0];
  jamp[98] += amp[0];
  jamp[99] -= amp[0];
  jamp[100] += amp[0];
  FFV1_0( w[3], w[113], w[80], COUPs[1], &amp[0] );
  jamp[96] -= amp[0];
  jamp[98] += amp[0];
  jamp[100] += amp[0];
  jamp[101] -= amp[0];

  // *** DIAGRAM 1225 OF 1240 ***

  // Wavefunction(s) for diagram number 1225
  // (none)

  // Amplitude(s) for diagram number 1225
  FFV1_0( w[41], w[2], w[27], COUPs[1], &amp[0] );
  jamp[0] -= cxtype( 0, 1 ) * amp[0];
  jamp[2] += cxtype( 0, 1 ) * amp[0];
  jamp[8] += cxtype( 0, 1 ) * amp[0];
  jamp[14] -= cxtype( 0, 1 ) * amp[0];
  jamp[32] += cxtype( 0, 1 ) * amp[0];
  jamp[38] -= cxtype( 0, 1 ) * amp[0];
  jamp[62] -= cxtype( 0, 1 ) * amp[0];
  jamp[86] += cxtype( 0, 1 ) * amp[0];
  FFV1_0( w[41], w[2], w[1], COUPs[1], &amp[0] );
  jamp[2] += cxtype( 0, 1 ) * amp[0];
  jamp[6] -= cxtype( 0, 1 ) * amp[0];
  jamp[8] += cxtype( 0, 1 ) * amp[0];
  jamp[12] -= cxtype( 0, 1 ) * amp[0];
  jamp[38] -= cxtype( 0, 1 ) * amp[0];
  jamp[56] += cxtype( 0, 1 ) * amp[0];
  jamp[62] -= cxtype( 0, 1 ) * amp[0];
  jamp[80] += cxtype( 0, 1 ) * amp[0];
  FFV1_0( w[41], w[2], w[16], COUPs[1], &amp[0] );
  jamp[0] += cxtype( 0, 1 ) * amp[0];
  jamp[6] -= cxtype( 0, 1 ) * amp[0];
  jamp[12] -= cxtype( 0, 1 ) * amp[0];
  jamp[14] += cxtype( 0, 1 ) * amp[0];
  jamp[32] -= cxtype( 0, 1 ) * amp[0];
  jamp[56] += cxtype( 0, 1 ) * amp[0];
  jamp[80] += cxtype( 0, 1 ) * amp[0];
  jamp[86] -= cxtype( 0, 1 ) * amp[0];

  // *** DIAGRAM 1226 OF 1240 ***

  // Wavefunction(s) for diagram number 1226
  // (none)

  // Amplitude(s) for diagram number 1226
  FFV1_0( w[62], w[2], w[73], COUPs[1], &amp[0] );
  jamp[32] += amp[0];
  jamp[38] -= amp[0];
  jamp[62] -= amp[0];
  jamp[86] += amp[0];
  FFV1_0( w[62], w[2], w[79], COUPs[1], &amp[0] );
  jamp[38] -= amp[0];
  jamp[56] += amp[0];
  jamp[62] -= amp[0];
  jamp[80] += amp[0];
  FFV1_0( w[62], w[2], w[80], COUPs[1], &amp[0] );
  jamp[32] -= amp[0];
  jamp[56] += amp[0];
  jamp[80] += amp[0];
  jamp[86] -= amp[0];

  // *** DIAGRAM 1227 OF 1240 ***

  // Wavefunction(s) for diagram number 1227
  // (none)

  // Amplitude(s) for diagram number 1227
  VVVV1_0( w[0], w[57], w[8], w[5], COUPs[2], &amp[0] );
  jamp[1] += amp[0];
  jamp[4] -= amp[0];
  jamp[10] -= amp[0];
  jamp[20] += amp[0];
  jamp[34] -= amp[0];
  jamp[44] += amp[0];
  jamp[68] += amp[0];
  jamp[72] -= amp[0];
  jamp[73] += amp[0];
  jamp[75] += amp[0];
  jamp[77] -= amp[0];
  jamp[81] += amp[0];
  jamp[83] -= amp[0];
  jamp[89] -= amp[0];
  jamp[95] += amp[0];
  jamp[110] -= amp[0];
  VVVV3_0( w[0], w[57], w[8], w[5], COUPs[2], &amp[0] );
  jamp[1] += amp[0];
  jamp[4] -= amp[0];
  jamp[10] -= amp[0];
  jamp[12] -= amp[0];
  jamp[13] += amp[0];
  jamp[15] += amp[0];
  jamp[17] -= amp[0];
  jamp[20] += amp[0];
  jamp[35] -= amp[0];
  jamp[45] += amp[0];
  jamp[69] += amp[0];
  jamp[81] += amp[0];
  jamp[83] -= amp[0];
  jamp[89] -= amp[0];
  jamp[95] += amp[0];
  jamp[111] -= amp[0];
  VVVV4_0( w[0], w[57], w[8], w[5], COUPs[2], &amp[0] );
  jamp[12] -= amp[0];
  jamp[13] += amp[0];
  jamp[15] += amp[0];
  jamp[17] -= amp[0];
  jamp[34] += amp[0];
  jamp[35] -= amp[0];
  jamp[44] -= amp[0];
  jamp[45] += amp[0];
  jamp[68] -= amp[0];
  jamp[69] += amp[0];
  jamp[72] += amp[0];
  jamp[73] -= amp[0];
  jamp[75] -= amp[0];
  jamp[77] += amp[0];
  jamp[110] += amp[0];
  jamp[111] -= amp[0];
  VVVV1_0( w[0], w[81], w[8], w[5], COUPs[2], &amp[0] );
  jamp[4] -= amp[0];
  jamp[7] += amp[0];
  jamp[10] -= amp[0];
  jamp[18] += amp[0];
  jamp[44] += amp[0];
  jamp[58] -= amp[0];
  jamp[68] += amp[0];
  jamp[73] += amp[0];
  jamp[74] -= amp[0];
  jamp[75] += amp[0];
  jamp[76] -= amp[0];
  jamp[83] -= amp[0];
  jamp[87] += amp[0];
  jamp[89] -= amp[0];
  jamp[93] += amp[0];
  jamp[104] -= amp[0];
  VVVV3_0( w[0], w[81], w[8], w[5], COUPs[2], &amp[0] );
  jamp[4] -= amp[0];
  jamp[7] += amp[0];
  jamp[10] -= amp[0];
  jamp[13] += amp[0];
  jamp[14] -= amp[0];
  jamp[15] += amp[0];
  jamp[16] -= amp[0];
  jamp[18] += amp[0];
  jamp[45] += amp[0];
  jamp[59] -= amp[0];
  jamp[69] += amp[0];
  jamp[83] -= amp[0];
  jamp[87] += amp[0];
  jamp[89] -= amp[0];
  jamp[93] += amp[0];
  jamp[105] -= amp[0];
  VVVV4_0( w[0], w[81], w[8], w[5], COUPs[2], &amp[0] );
  jamp[13] += amp[0];
  jamp[14] -= amp[0];
  jamp[15] += amp[0];
  jamp[16] -= amp[0];
  jamp[44] -= amp[0];
  jamp[45] += amp[0];
  jamp[58] += amp[0];
  jamp[59] -= amp[0];
  jamp[68] -= amp[0];
  jamp[69] += amp[0];
  jamp[73] -= amp[0];
  jamp[74] += amp[0];
  jamp[75] -= amp[0];
  jamp[76] += amp[0];
  jamp[104] += amp[0];
  jamp[105] -= amp[0];
  VVVV1_0( w[0], w[82], w[8], w[5], COUPs[2], &amp[0] );
  jamp[1] -= amp[0];
  jamp[7] += amp[0];
  jamp[18] += amp[0];
  jamp[20] -= amp[0];
  jamp[34] += amp[0];
  jamp[58] -= amp[0];
  jamp[72] += amp[0];
  jamp[74] -= amp[0];
  jamp[76] -= amp[0];
  jamp[77] += amp[0];
  jamp[81] -= amp[0];
  jamp[87] += amp[0];
  jamp[93] += amp[0];
  jamp[95] -= amp[0];
  jamp[104] -= amp[0];
  jamp[110] += amp[0];
  VVVV3_0( w[0], w[82], w[8], w[5], COUPs[2], &amp[0] );
  jamp[1] -= amp[0];
  jamp[7] += amp[0];
  jamp[12] += amp[0];
  jamp[14] -= amp[0];
  jamp[16] -= amp[0];
  jamp[17] += amp[0];
  jamp[18] += amp[0];
  jamp[20] -= amp[0];
  jamp[35] += amp[0];
  jamp[59] -= amp[0];
  jamp[81] -= amp[0];
  jamp[87] += amp[0];
  jamp[93] += amp[0];
  jamp[95] -= amp[0];
  jamp[105] -= amp[0];
  jamp[111] += amp[0];
  VVVV4_0( w[0], w[82], w[8], w[5], COUPs[2], &amp[0] );
  jamp[12] += amp[0];
  jamp[14] -= amp[0];
  jamp[16] -= amp[0];
  jamp[17] += amp[0];
  jamp[34] -= amp[0];
  jamp[35] += amp[0];
  jamp[58] += amp[0];
  jamp[59] -= amp[0];
  jamp[72] -= amp[0];
  jamp[74] += amp[0];
  jamp[76] += amp[0];
  jamp[77] -= amp[0];
  jamp[104] += amp[0];
  jamp[105] -= amp[0];
  jamp[110] -= amp[0];
  jamp[111] += amp[0];

  // *** DIAGRAM 1228 OF 1240 ***

  // Wavefunction(s) for diagram number 1228
  VVV1P0_1( w[0], w[57], COUPs[0], 0., 0., w[62] );
  VVV1P0_1( w[0], w[81], COUPs[0], 0., 0., w[80] );
  VVV1P0_1( w[0], w[82], COUPs[0], 0., 0., w[79] );

  // Amplitude(s) for diagram number 1228
  VVV1_0( w[8], w[5], w[62], COUPs[0], &amp[0] );
  jamp[1] += amp[0];
  jamp[4] -= amp[0];
  jamp[10] -= amp[0];
  jamp[20] += amp[0];
  jamp[34] -= amp[0];
  jamp[44] += amp[0];
  jamp[68] += amp[0];
  jamp[72] -= amp[0];
  jamp[73] += amp[0];
  jamp[75] += amp[0];
  jamp[77] -= amp[0];
  jamp[81] += amp[0];
  jamp[83] -= amp[0];
  jamp[89] -= amp[0];
  jamp[95] += amp[0];
  jamp[110] -= amp[0];
  VVV1_0( w[8], w[5], w[80], COUPs[0], &amp[0] );
  jamp[4] -= amp[0];
  jamp[7] += amp[0];
  jamp[10] -= amp[0];
  jamp[18] += amp[0];
  jamp[44] += amp[0];
  jamp[58] -= amp[0];
  jamp[68] += amp[0];
  jamp[73] += amp[0];
  jamp[74] -= amp[0];
  jamp[75] += amp[0];
  jamp[76] -= amp[0];
  jamp[83] -= amp[0];
  jamp[87] += amp[0];
  jamp[89] -= amp[0];
  jamp[93] += amp[0];
  jamp[104] -= amp[0];
  VVV1_0( w[8], w[5], w[79], COUPs[0], &amp[0] );
  jamp[1] -= amp[0];
  jamp[7] += amp[0];
  jamp[18] += amp[0];
  jamp[20] -= amp[0];
  jamp[34] += amp[0];
  jamp[58] -= amp[0];
  jamp[72] += amp[0];
  jamp[74] -= amp[0];
  jamp[76] -= amp[0];
  jamp[77] += amp[0];
  jamp[81] -= amp[0];
  jamp[87] += amp[0];
  jamp[93] += amp[0];
  jamp[95] -= amp[0];
  jamp[104] -= amp[0];
  jamp[110] += amp[0];

  // *** DIAGRAM 1229 OF 1240 ***

  // Wavefunction(s) for diagram number 1229
  // (none)

  // Amplitude(s) for diagram number 1229
  VVV1_0( w[57], w[5], w[56], COUPs[0], &amp[0] );
  jamp[1] += amp[0];
  jamp[4] -= amp[0];
  jamp[10] -= amp[0];
  jamp[12] -= amp[0];
  jamp[13] += amp[0];
  jamp[15] += amp[0];
  jamp[17] -= amp[0];
  jamp[20] += amp[0];
  jamp[35] -= amp[0];
  jamp[45] += amp[0];
  jamp[69] += amp[0];
  jamp[81] += amp[0];
  jamp[83] -= amp[0];
  jamp[89] -= amp[0];
  jamp[95] += amp[0];
  jamp[111] -= amp[0];
  VVV1_0( w[81], w[5], w[56], COUPs[0], &amp[0] );
  jamp[4] -= amp[0];
  jamp[7] += amp[0];
  jamp[10] -= amp[0];
  jamp[13] += amp[0];
  jamp[14] -= amp[0];
  jamp[15] += amp[0];
  jamp[16] -= amp[0];
  jamp[18] += amp[0];
  jamp[45] += amp[0];
  jamp[59] -= amp[0];
  jamp[69] += amp[0];
  jamp[83] -= amp[0];
  jamp[87] += amp[0];
  jamp[89] -= amp[0];
  jamp[93] += amp[0];
  jamp[105] -= amp[0];
  VVV1_0( w[82], w[5], w[56], COUPs[0], &amp[0] );
  jamp[1] -= amp[0];
  jamp[7] += amp[0];
  jamp[12] += amp[0];
  jamp[14] -= amp[0];
  jamp[16] -= amp[0];
  jamp[17] += amp[0];
  jamp[18] += amp[0];
  jamp[20] -= amp[0];
  jamp[35] += amp[0];
  jamp[59] -= amp[0];
  jamp[81] -= amp[0];
  jamp[87] += amp[0];
  jamp[93] += amp[0];
  jamp[95] -= amp[0];
  jamp[105] -= amp[0];
  jamp[111] += amp[0];

  // *** DIAGRAM 1230 OF 1240 ***

  // Wavefunction(s) for diagram number 1230
  // (none)

  // Amplitude(s) for diagram number 1230
  FFV1_0( w[3], w[39], w[62], COUPs[1], &amp[0] );
  jamp[72] -= cxtype( 0, 1 ) * amp[0];
  jamp[73] += cxtype( 0, 1 ) * amp[0];
  jamp[75] += cxtype( 0, 1 ) * amp[0];
  jamp[77] -= cxtype( 0, 1 ) * amp[0];
  jamp[81] += cxtype( 0, 1 ) * amp[0];
  jamp[83] -= cxtype( 0, 1 ) * amp[0];
  jamp[89] -= cxtype( 0, 1 ) * amp[0];
  jamp[95] += cxtype( 0, 1 ) * amp[0];
  FFV1_0( w[3], w[39], w[80], COUPs[1], &amp[0] );
  jamp[73] += cxtype( 0, 1 ) * amp[0];
  jamp[74] -= cxtype( 0, 1 ) * amp[0];
  jamp[75] += cxtype( 0, 1 ) * amp[0];
  jamp[76] -= cxtype( 0, 1 ) * amp[0];
  jamp[83] -= cxtype( 0, 1 ) * amp[0];
  jamp[87] += cxtype( 0, 1 ) * amp[0];
  jamp[89] -= cxtype( 0, 1 ) * amp[0];
  jamp[93] += cxtype( 0, 1 ) * amp[0];
  FFV1_0( w[3], w[39], w[79], COUPs[1], &amp[0] );
  jamp[72] += cxtype( 0, 1 ) * amp[0];
  jamp[74] -= cxtype( 0, 1 ) * amp[0];
  jamp[76] -= cxtype( 0, 1 ) * amp[0];
  jamp[77] += cxtype( 0, 1 ) * amp[0];
  jamp[81] -= cxtype( 0, 1 ) * amp[0];
  jamp[87] += cxtype( 0, 1 ) * amp[0];
  jamp[93] += cxtype( 0, 1 ) * amp[0];
  jamp[95] -= cxtype( 0, 1 ) * amp[0];

  // *** DIAGRAM 1231 OF 1240 ***

  // Wavefunction(s) for diagram number 1231
  // (none)

  // Amplitude(s) for diagram number 1231
  FFV1_0( w[3], w[102], w[57], COUPs[1], &amp[0] );
  jamp[72] += amp[0];
  jamp[73] -= amp[0];
  jamp[75] -= amp[0];
  jamp[77] += amp[0];
  FFV1_0( w[3], w[102], w[81], COUPs[1], &amp[0] );
  jamp[73] -= amp[0];
  jamp[74] += amp[0];
  jamp[75] -= amp[0];
  jamp[76] += amp[0];
  FFV1_0( w[3], w[102], w[82], COUPs[1], &amp[0] );
  jamp[72] -= amp[0];
  jamp[74] += amp[0];
  jamp[76] += amp[0];
  jamp[77] -= amp[0];

  // *** DIAGRAM 1232 OF 1240 ***

  // Wavefunction(s) for diagram number 1232
  // (none)

  // Amplitude(s) for diagram number 1232
  FFV1_0( w[38], w[2], w[62], COUPs[1], &amp[0] );
  jamp[1] -= cxtype( 0, 1 ) * amp[0];
  jamp[4] += cxtype( 0, 1 ) * amp[0];
  jamp[10] += cxtype( 0, 1 ) * amp[0];
  jamp[20] -= cxtype( 0, 1 ) * amp[0];
  jamp[34] += cxtype( 0, 1 ) * amp[0];
  jamp[44] -= cxtype( 0, 1 ) * amp[0];
  jamp[68] -= cxtype( 0, 1 ) * amp[0];
  jamp[110] += cxtype( 0, 1 ) * amp[0];
  FFV1_0( w[38], w[2], w[80], COUPs[1], &amp[0] );
  jamp[4] += cxtype( 0, 1 ) * amp[0];
  jamp[7] -= cxtype( 0, 1 ) * amp[0];
  jamp[10] += cxtype( 0, 1 ) * amp[0];
  jamp[18] -= cxtype( 0, 1 ) * amp[0];
  jamp[44] -= cxtype( 0, 1 ) * amp[0];
  jamp[58] += cxtype( 0, 1 ) * amp[0];
  jamp[68] -= cxtype( 0, 1 ) * amp[0];
  jamp[104] += cxtype( 0, 1 ) * amp[0];
  FFV1_0( w[38], w[2], w[79], COUPs[1], &amp[0] );
  jamp[1] += cxtype( 0, 1 ) * amp[0];
  jamp[7] -= cxtype( 0, 1 ) * amp[0];
  jamp[18] -= cxtype( 0, 1 ) * amp[0];
  jamp[20] += cxtype( 0, 1 ) * amp[0];
  jamp[34] -= cxtype( 0, 1 ) * amp[0];
  jamp[58] += cxtype( 0, 1 ) * amp[0];
  jamp[104] += cxtype( 0, 1 ) * amp[0];
  jamp[110] -= cxtype( 0, 1 ) * amp[0];

  // *** DIAGRAM 1233 OF 1240 ***

  // Wavefunction(s) for diagram number 1233
  // (none)

  // Amplitude(s) for diagram number 1233
  FFV1_0( w[104], w[2], w[57], COUPs[1], &amp[0] );
  jamp[34] += amp[0];
  jamp[44] -= amp[0];
  jamp[68] -= amp[0];
  jamp[110] += amp[0];
  FFV1_0( w[104], w[2], w[81], COUPs[1], &amp[0] );
  jamp[44] -= amp[0];
  jamp[58] += amp[0];
  jamp[68] -= amp[0];
  jamp[104] += amp[0];
  FFV1_0( w[104], w[2], w[82], COUPs[1], &amp[0] );
  jamp[34] -= amp[0];
  jamp[58] += amp[0];
  jamp[104] += amp[0];
  jamp[110] -= amp[0];

  // *** DIAGRAM 1234 OF 1240 ***

  // Wavefunction(s) for diagram number 1234
  // (none)

  // Amplitude(s) for diagram number 1234
  VVVV1_0( w[0], w[55], w[8], w[4], COUPs[2], &amp[0] );
  jamp[3] += amp[0];
  jamp[5] -= amp[0];
  jamp[16] -= amp[0];
  jamp[22] += amp[0];
  jamp[40] -= amp[0];
  jamp[46] += amp[0];
  jamp[48] -= amp[0];
  jamp[49] += amp[0];
  jamp[51] += amp[0];
  jamp[53] -= amp[0];
  jamp[57] += amp[0];
  jamp[59] -= amp[0];
  jamp[65] -= amp[0];
  jamp[71] += amp[0];
  jamp[92] += amp[0];
  jamp[116] -= amp[0];
  VVVV3_0( w[0], w[55], w[8], w[4], COUPs[2], &amp[0] );
  jamp[3] += amp[0];
  jamp[5] -= amp[0];
  jamp[6] -= amp[0];
  jamp[7] += amp[0];
  jamp[9] += amp[0];
  jamp[11] -= amp[0];
  jamp[16] -= amp[0];
  jamp[22] += amp[0];
  jamp[41] -= amp[0];
  jamp[47] += amp[0];
  jamp[57] += amp[0];
  jamp[59] -= amp[0];
  jamp[65] -= amp[0];
  jamp[71] += amp[0];
  jamp[93] += amp[0];
  jamp[117] -= amp[0];
  VVVV4_0( w[0], w[55], w[8], w[4], COUPs[2], &amp[0] );
  jamp[6] -= amp[0];
  jamp[7] += amp[0];
  jamp[9] += amp[0];
  jamp[11] -= amp[0];
  jamp[40] += amp[0];
  jamp[41] -= amp[0];
  jamp[46] -= amp[0];
  jamp[47] += amp[0];
  jamp[48] += amp[0];
  jamp[49] -= amp[0];
  jamp[51] -= amp[0];
  jamp[53] += amp[0];
  jamp[92] -= amp[0];
  jamp[93] += amp[0];
  jamp[116] += amp[0];
  jamp[117] -= amp[0];
  VVVV1_0( w[0], w[83], w[8], w[4], COUPs[2], &amp[0] );
  jamp[5] -= amp[0];
  jamp[13] += amp[0];
  jamp[16] -= amp[0];
  jamp[19] += amp[0];
  jamp[46] += amp[0];
  jamp[49] += amp[0];
  jamp[50] -= amp[0];
  jamp[51] += amp[0];
  jamp[52] -= amp[0];
  jamp[59] -= amp[0];
  jamp[63] += amp[0];
  jamp[65] -= amp[0];
  jamp[69] += amp[0];
  jamp[82] -= amp[0];
  jamp[92] += amp[0];
  jamp[106] -= amp[0];
  VVVV3_0( w[0], w[83], w[8], w[4], COUPs[2], &amp[0] );
  jamp[5] -= amp[0];
  jamp[7] += amp[0];
  jamp[8] -= amp[0];
  jamp[9] += amp[0];
  jamp[10] -= amp[0];
  jamp[13] += amp[0];
  jamp[16] -= amp[0];
  jamp[19] += amp[0];
  jamp[47] += amp[0];
  jamp[59] -= amp[0];
  jamp[63] += amp[0];
  jamp[65] -= amp[0];
  jamp[69] += amp[0];
  jamp[83] -= amp[0];
  jamp[93] += amp[0];
  jamp[107] -= amp[0];
  VVVV4_0( w[0], w[83], w[8], w[4], COUPs[2], &amp[0] );
  jamp[7] += amp[0];
  jamp[8] -= amp[0];
  jamp[9] += amp[0];
  jamp[10] -= amp[0];
  jamp[46] -= amp[0];
  jamp[47] += amp[0];
  jamp[49] -= amp[0];
  jamp[50] += amp[0];
  jamp[51] -= amp[0];
  jamp[52] += amp[0];
  jamp[82] += amp[0];
  jamp[83] -= amp[0];
  jamp[92] -= amp[0];
  jamp[93] += amp[0];
  jamp[106] += amp[0];
  jamp[107] -= amp[0];
  VVVV1_0( w[0], w[84], w[8], w[4], COUPs[2], &amp[0] );
  jamp[3] -= amp[0];
  jamp[13] += amp[0];
  jamp[19] += amp[0];
  jamp[22] -= amp[0];
  jamp[40] += amp[0];
  jamp[48] += amp[0];
  jamp[50] -= amp[0];
  jamp[52] -= amp[0];
  jamp[53] += amp[0];
  jamp[57] -= amp[0];
  jamp[63] += amp[0];
  jamp[69] += amp[0];
  jamp[71] -= amp[0];
  jamp[82] -= amp[0];
  jamp[106] -= amp[0];
  jamp[116] += amp[0];
  VVVV3_0( w[0], w[84], w[8], w[4], COUPs[2], &amp[0] );
  jamp[3] -= amp[0];
  jamp[6] += amp[0];
  jamp[8] -= amp[0];
  jamp[10] -= amp[0];
  jamp[11] += amp[0];
  jamp[13] += amp[0];
  jamp[19] += amp[0];
  jamp[22] -= amp[0];
  jamp[41] += amp[0];
  jamp[57] -= amp[0];
  jamp[63] += amp[0];
  jamp[69] += amp[0];
  jamp[71] -= amp[0];
  jamp[83] -= amp[0];
  jamp[107] -= amp[0];
  jamp[117] += amp[0];
  VVVV4_0( w[0], w[84], w[8], w[4], COUPs[2], &amp[0] );
  jamp[6] += amp[0];
  jamp[8] -= amp[0];
  jamp[10] -= amp[0];
  jamp[11] += amp[0];
  jamp[40] -= amp[0];
  jamp[41] += amp[0];
  jamp[48] -= amp[0];
  jamp[50] += amp[0];
  jamp[52] += amp[0];
  jamp[53] -= amp[0];
  jamp[82] += amp[0];
  jamp[83] -= amp[0];
  jamp[106] += amp[0];
  jamp[107] -= amp[0];
  jamp[116] -= amp[0];
  jamp[117] += amp[0];

  // *** DIAGRAM 1235 OF 1240 ***

  // Wavefunction(s) for diagram number 1235
  VVV1P0_1( w[0], w[55], COUPs[0], 0., 0., w[104] );
  VVV1P0_1( w[0], w[83], COUPs[0], 0., 0., w[82] );
  VVV1P0_1( w[0], w[84], COUPs[0], 0., 0., w[81] );

  // Amplitude(s) for diagram number 1235
  VVV1_0( w[8], w[4], w[104], COUPs[0], &amp[0] );
  jamp[3] += amp[0];
  jamp[5] -= amp[0];
  jamp[16] -= amp[0];
  jamp[22] += amp[0];
  jamp[40] -= amp[0];
  jamp[46] += amp[0];
  jamp[48] -= amp[0];
  jamp[49] += amp[0];
  jamp[51] += amp[0];
  jamp[53] -= amp[0];
  jamp[57] += amp[0];
  jamp[59] -= amp[0];
  jamp[65] -= amp[0];
  jamp[71] += amp[0];
  jamp[92] += amp[0];
  jamp[116] -= amp[0];
  VVV1_0( w[8], w[4], w[82], COUPs[0], &amp[0] );
  jamp[5] -= amp[0];
  jamp[13] += amp[0];
  jamp[16] -= amp[0];
  jamp[19] += amp[0];
  jamp[46] += amp[0];
  jamp[49] += amp[0];
  jamp[50] -= amp[0];
  jamp[51] += amp[0];
  jamp[52] -= amp[0];
  jamp[59] -= amp[0];
  jamp[63] += amp[0];
  jamp[65] -= amp[0];
  jamp[69] += amp[0];
  jamp[82] -= amp[0];
  jamp[92] += amp[0];
  jamp[106] -= amp[0];
  VVV1_0( w[8], w[4], w[81], COUPs[0], &amp[0] );
  jamp[3] -= amp[0];
  jamp[13] += amp[0];
  jamp[19] += amp[0];
  jamp[22] -= amp[0];
  jamp[40] += amp[0];
  jamp[48] += amp[0];
  jamp[50] -= amp[0];
  jamp[52] -= amp[0];
  jamp[53] += amp[0];
  jamp[57] -= amp[0];
  jamp[63] += amp[0];
  jamp[69] += amp[0];
  jamp[71] -= amp[0];
  jamp[82] -= amp[0];
  jamp[106] -= amp[0];
  jamp[116] += amp[0];

  // *** DIAGRAM 1236 OF 1240 ***

  // Wavefunction(s) for diagram number 1236
  // (none)

  // Amplitude(s) for diagram number 1236
  VVV1_0( w[55], w[4], w[56], COUPs[0], &amp[0] );
  jamp[3] += amp[0];
  jamp[5] -= amp[0];
  jamp[6] -= amp[0];
  jamp[7] += amp[0];
  jamp[9] += amp[0];
  jamp[11] -= amp[0];
  jamp[16] -= amp[0];
  jamp[22] += amp[0];
  jamp[41] -= amp[0];
  jamp[47] += amp[0];
  jamp[57] += amp[0];
  jamp[59] -= amp[0];
  jamp[65] -= amp[0];
  jamp[71] += amp[0];
  jamp[93] += amp[0];
  jamp[117] -= amp[0];
  VVV1_0( w[83], w[4], w[56], COUPs[0], &amp[0] );
  jamp[5] -= amp[0];
  jamp[7] += amp[0];
  jamp[8] -= amp[0];
  jamp[9] += amp[0];
  jamp[10] -= amp[0];
  jamp[13] += amp[0];
  jamp[16] -= amp[0];
  jamp[19] += amp[0];
  jamp[47] += amp[0];
  jamp[59] -= amp[0];
  jamp[63] += amp[0];
  jamp[65] -= amp[0];
  jamp[69] += amp[0];
  jamp[83] -= amp[0];
  jamp[93] += amp[0];
  jamp[107] -= amp[0];
  VVV1_0( w[84], w[4], w[56], COUPs[0], &amp[0] );
  jamp[3] -= amp[0];
  jamp[6] += amp[0];
  jamp[8] -= amp[0];
  jamp[10] -= amp[0];
  jamp[11] += amp[0];
  jamp[13] += amp[0];
  jamp[19] += amp[0];
  jamp[22] -= amp[0];
  jamp[41] += amp[0];
  jamp[57] -= amp[0];
  jamp[63] += amp[0];
  jamp[69] += amp[0];
  jamp[71] -= amp[0];
  jamp[83] -= amp[0];
  jamp[107] -= amp[0];
  jamp[117] += amp[0];

  // *** DIAGRAM 1237 OF 1240 ***

  // Wavefunction(s) for diagram number 1237
  // (none)

  // Amplitude(s) for diagram number 1237
  FFV1_0( w[3], w[33], w[104], COUPs[1], &amp[0] );
  jamp[48] -= cxtype( 0, 1 ) * amp[0];
  jamp[49] += cxtype( 0, 1 ) * amp[0];
  jamp[51] += cxtype( 0, 1 ) * amp[0];
  jamp[53] -= cxtype( 0, 1 ) * amp[0];
  jamp[57] += cxtype( 0, 1 ) * amp[0];
  jamp[59] -= cxtype( 0, 1 ) * amp[0];
  jamp[65] -= cxtype( 0, 1 ) * amp[0];
  jamp[71] += cxtype( 0, 1 ) * amp[0];
  FFV1_0( w[3], w[33], w[82], COUPs[1], &amp[0] );
  jamp[49] += cxtype( 0, 1 ) * amp[0];
  jamp[50] -= cxtype( 0, 1 ) * amp[0];
  jamp[51] += cxtype( 0, 1 ) * amp[0];
  jamp[52] -= cxtype( 0, 1 ) * amp[0];
  jamp[59] -= cxtype( 0, 1 ) * amp[0];
  jamp[63] += cxtype( 0, 1 ) * amp[0];
  jamp[65] -= cxtype( 0, 1 ) * amp[0];
  jamp[69] += cxtype( 0, 1 ) * amp[0];
  FFV1_0( w[3], w[33], w[81], COUPs[1], &amp[0] );
  jamp[48] += cxtype( 0, 1 ) * amp[0];
  jamp[50] -= cxtype( 0, 1 ) * amp[0];
  jamp[52] -= cxtype( 0, 1 ) * amp[0];
  jamp[53] += cxtype( 0, 1 ) * amp[0];
  jamp[57] -= cxtype( 0, 1 ) * amp[0];
  jamp[63] += cxtype( 0, 1 ) * amp[0];
  jamp[69] += cxtype( 0, 1 ) * amp[0];
  jamp[71] -= cxtype( 0, 1 ) * amp[0];

  // *** DIAGRAM 1238 OF 1240 ***

  // Wavefunction(s) for diagram number 1238
  // (none)

  // Amplitude(s) for diagram number 1238
  FFV1_0( w[3], w[114], w[55], COUPs[1], &amp[0] );
  jamp[48] += amp[0];
  jamp[49] -= amp[0];
  jamp[51] -= amp[0];
  jamp[53] += amp[0];
  FFV1_0( w[3], w[114], w[83], COUPs[1], &amp[0] );
  jamp[49] -= amp[0];
  jamp[50] += amp[0];
  jamp[51] -= amp[0];
  jamp[52] += amp[0];
  FFV1_0( w[3], w[114], w[84], COUPs[1], &amp[0] );
  jamp[48] -= amp[0];
  jamp[50] += amp[0];
  jamp[52] += amp[0];
  jamp[53] -= amp[0];

  // *** DIAGRAM 1239 OF 1240 ***

  // Wavefunction(s) for diagram number 1239
  // (none)

  // Amplitude(s) for diagram number 1239
  FFV1_0( w[46], w[2], w[104], COUPs[1], &amp[0] );
  jamp[3] -= cxtype( 0, 1 ) * amp[0];
  jamp[5] += cxtype( 0, 1 ) * amp[0];
  jamp[16] += cxtype( 0, 1 ) * amp[0];
  jamp[22] -= cxtype( 0, 1 ) * amp[0];
  jamp[40] += cxtype( 0, 1 ) * amp[0];
  jamp[46] -= cxtype( 0, 1 ) * amp[0];
  jamp[92] -= cxtype( 0, 1 ) * amp[0];
  jamp[116] += cxtype( 0, 1 ) * amp[0];
  FFV1_0( w[46], w[2], w[82], COUPs[1], &amp[0] );
  jamp[5] += cxtype( 0, 1 ) * amp[0];
  jamp[13] -= cxtype( 0, 1 ) * amp[0];
  jamp[16] += cxtype( 0, 1 ) * amp[0];
  jamp[19] -= cxtype( 0, 1 ) * amp[0];
  jamp[46] -= cxtype( 0, 1 ) * amp[0];
  jamp[82] += cxtype( 0, 1 ) * amp[0];
  jamp[92] -= cxtype( 0, 1 ) * amp[0];
  jamp[106] += cxtype( 0, 1 ) * amp[0];
  FFV1_0( w[46], w[2], w[81], COUPs[1], &amp[0] );
  jamp[3] += cxtype( 0, 1 ) * amp[0];
  jamp[13] -= cxtype( 0, 1 ) * amp[0];
  jamp[19] -= cxtype( 0, 1 ) * amp[0];
  jamp[22] += cxtype( 0, 1 ) * amp[0];
  jamp[40] -= cxtype( 0, 1 ) * amp[0];
  jamp[82] += cxtype( 0, 1 ) * amp[0];
  jamp[106] += cxtype( 0, 1 ) * amp[0];
  jamp[116] -= cxtype( 0, 1 ) * amp[0];

  // *** DIAGRAM 1240 OF 1240 ***

  // Wavefunction(s) for diagram number 1240
  // (none)

  // Amplitude(s) for diagram number 1240
  FFV1_0( w[99], w[2], w[55], COUPs[1], &amp[0] );
  jamp[40] += amp[0];
  jamp[46] -= amp[0];
  jamp[92] -= amp[0];
  jamp[116] += amp[0];
  FFV1_0( w[99], w[2], w[83], COUPs[1], &amp[0] );
  jamp[46] -= amp[0];
  jamp[82] += amp[0];
  jamp[92] -= amp[0];
  jamp[106] += amp[0];
  FFV1_0( w[99], w[2], w[84], COUPs[1], &amp[0] );
  jamp[40] -= amp[0];
  jamp[82] += amp[0];
  jamp[106] += amp[0];
  jamp[116] -= amp[0];

  // *** COLOR ALGEBRA BELOW ***
  // (This method used to be called CPPProcess::matrix_1_gg_ttxggg()?)

  // The color matrix

      // The color denominators (initialize all array elements, with ncolor=120)
      // [NB do keep 'static' for these constexpr arrays, see issue #283]
      static constexpr fptype denom[ncolor] = { 324, 324, 324, 324, 324, 324, 324, 324, 324, 324, 324, 324, 324, 324, 324, 324, 324, 324, 324, 324, 324, 324, 324, 324, 324, 324, 324, 324, 324, 324, 324, 324, 324, 324, 324, 324, 324, 324, 324, 324, 324, 324, 324, 324, 324, 324, 324, 324, 324, 324, 324, 324, 324, 324, 324, 324, 324, 324, 324, 324, 324, 324, 324, 324, 324, 324, 324, 324, 324, 324, 324, 324, 324, 324, 324, 324, 324, 324, 324, 324, 324, 324, 324, 324, 324, 324, 324, 324, 324, 324, 324, 324, 324, 324, 324, 324, 324, 324, 324, 324, 324, 324, 324, 324, 324, 324, 324, 324, 324, 324, 324, 324, 324, 324, 324, 324, 324, 324, 324, 324 }; // 1-D array[120]

      // The color matrix (initialize all array elements, with ncolor=120)
      // [NB do keep 'static' for these constexpr arrays, see issue #283]
      static constexpr fptype cf[ncolor][ncolor] = {
        { 4096, -512, -512, 64, 64, 640, -512, 64, 64, -8, -8, -80, 64, -8, 640, -80, 568, 496, -8, -80, -80, 496, 496, -224, -512, 64, 64, -8, -8, -80, 64, -8, -8, 1, 1, 10, -8, 1, -80, 10, -71, -62, 1, 10, 10, -62, -62, 28, 64, -8, -8, 1, 1, 10, 640, -80, -80, 10, 10, 100, 568, -71, 496, -62, 505, 514, -71, 19, -62, -53, -134, -44, -8, 1, -80, 10, -71, -62, -80, 10, 496, -62, 19, -53, 496, -62, -224, 28, -134, -44, 505, -134, -134, 442, 442, -116, 1, 10, 10, -62, -62, 28, 10, 100, -62, 514, -53, -44, -62, -53, 28, -44, 442, -116, 514, -44, -44, -116, -116, 136 },
        { -512, 4096, 64, 640, -512, 64, 64, -512, -8, -80, 64, -8, -8, -80, -80, 496, 496, -224, 64, -8, 640, -80, 568, 496, 64, -512, -8, -80, 64, -8, -8, 64, 1, 10, -8, 1, 1, 10, 10, -62, -62, 28, -8, 1, -80, 10, -71, -62, -8, 64, 1, 10, -8, 1, -80, 640, 10, 100, -80, 10, -71, 19, -62, -53, -134, -44, 568, -71, 496, -62, 505, 514, 1, 10, 10, -62, -62, 28, 10, 100, -62, 514, -53, -44, -62, -53, 28, -44, 442, -116, 514, -44, -44, -116, -116, 136, -8, 1, -80, 10, -71, -62, -80, 10, 496, -62, 19, -53, 496, -62, -224, 28, -134, -44, 505, -134, -134, 442, 442, -116 },
        { -512, 64, 4096, -512, 640, 64, 64, -8, 640, -80, 568, 496, -512, 64, 64, -8, -8, -80, -80, -8, 496, -224, -80, 496, 64, -8, -512, 64, -80, -8, -8, 1, -80, 10, -71, -62, 64, -8, -8, 1, 1, 10, 10, 1, -62, 28, 10, -62, -8, 1, -80, 10, -71, -62, -80, 10, 496, -62, 19, -53, 496, -62, -224, 28, -134, -44, 505, -134, -134, 442, 442, -116, 64, -8, -8, 1, 1, 10, 640, -80, -80, 10, 10, 100, 568, -71, 496, -62, 505, 514, -71, 19, -62, -53, -134, -44, 10, 1, -62, 28, 10, -62, 100, 10, -53, -44, -62, 514, 514, -44, -44, -116, -116, 136, -62, -53, 28, -44, 442, -116 },
        { 64, 640, -512, 4096, 64, -512, -8, -80, -80, 496, 496, -224, 64, -512, -8, -80, 64, -8, -8, 64, 568, 496, 640, -80, -8, -80, 64, -512, -8, 64, 1, 10, 10, -62, -62, 28, -8, 64, 1, 10, -8, 1, 1, -8, -71, -62, -80, 10, 1, 10, 10, -62, -62, 28, 10, 100, -62, 514, -53, -44, -62, -53, 28, -44, 442, -116, 514, -44, -44, -116, -116, 136, -8, 64, 1, 10, -8, 1, -80, 640, 10, 100, -80, 10, -71, 19, -62, -53, -134, -44, 568, -71, 496, -62, 505, 514, 1, -8, -71, -62, -80, 10, 10, -80, 19, -53, 496, -62, 505, -134, -134, 442, 442, -116, 496, -62, -224, 28, -134, -44 },
        { 64, -512, 640, 64, 4096, -512, -8, 64, 568, 496, 640, -80, -80, -8, 496, -224, -80, 496, -512, 64, 64, -8, -8, -80, -8, 64, -80, -8, -512, 64, 1, -8, -71, -62, -80, 10, 10, 1, -62, 28, 10, -62, 64, -8, -8, 1, 1, 10, 1, -8, -71, -62, -80, 10, 10, -80, 19, -53, 496, -62, 505, -134, -134, 442, 442, -116, 496, -62, -224, 28, -134, -44, 10, 1, -62, 28, 10, -62, 100, 10, -53, -44, -62, 514, 514, -44, -44, -116, -116, 136, -62, -53, 28, -44, 442, -116, 64, -8, -8, 1, 1, 10, 640, -80, -80, 10, 10, 100, 568, -71, 496, -62, 505, 514, -71, 19, -62, -53, -134, -44 },
        { 640, 64, 64, -512, -512, 4096, -80, -8, 496, -224, -80, 496, -8, 64, 568, 496, 640, -80, 64, -512, -8, -80, 64, -8, -80, -8, -8, 64, 64, -512, 10, 1, -62, 28, 10, -62, 1, -8, -71, -62, -80, 10, -8, 64, 1, 10, -8, 1, 10, 1, -62, 28, 10, -62, 100, 10, -53, -44, -62, 514, 514, -44, -44, -116, -116, 136, -62, -53, 28, -44, 442, -116, 1, -8, -71, -62, -80, 10, 10, -80, 19, -53, 496, -62, 505, -134, -134, 442, 442, -116, 496, -62, -224, 28, -134, -44, -8, 64, 1, 10, -8, 1, -80, 640, 10, 100, -80, 10, -71, 19, -62, -53, -134, -44, 568, -71, 496, -62, 505, 514 },
        { -512, 64, 64, -8, -8, -80, 4096, -512, -512, 64, 64, 640, 640, -80, 64, -8, 496, 568, -80, 496, -8, -80, -224, 496, 64, -8, -8, 1, 1, 10, 640, -80, -80, 10, 10, 100, 568, -71, 496, -62, 505, 514, -71, 19, -62, -53, -134, -44, -512, 64, 64, -8, -8, -80, 64, -8, -8, 1, 1, 10, -8, 1, -80, 10, -71, -62, 1, 10, 10, -62, -62, 28, -80, 10, -8, 1, -62, -71, 496, -62, -224, 28, -134, -44, -80, 10, 496, -62, 19, -53, -134, 505, 442, -116, -134, 442, 10, -62, 1, 10, 28, -62, -62, -53, 28, -44, 442, -116, 10, 100, -62, 514, -53, -44, -44, 514, -116, 136, -44, -116 },
        { 64, -512, -8, -80, 64, -8, -512, 4096, 64, 640, -512, 64, -80, 496, -8, -80, -224, 496, 640, -80, 64, -8, 496, 568, -8, 64, 1, 10, -8, 1, -80, 640, 10, 100, -80, 10, -71, 19, -62, -53, -134, -44, 568, -71, 496, -62, 505, 514, 64, -512, -8, -80, 64, -8, -8, 64, 1, 10, -8, 1, 1, 10, 10, -62, -62, 28, -8, 1, -80, 10, -71, -62, 10, -62, 1, 10, 28, -62, -62, -53, 28, -44, 442, -116, 10, 100, -62, 514, -53, -44, -44, 514, -116, 136, -44, -116, -80, 10, -8, 1, -62, -71, 496, -62, -224, 28, -134, -44, -80, 10, 496, -62, 19, -53, -134, 505, 442, -116, -134, 442 },
        { 64, -8, 640, -80, 568, 496, -512, 64, 4096, -512, 640, 64, 64, -8, -512, 64, -80, -8, 496, -224, -80, -8, 496, -80, -8, 1, -80, 10, -71, -62, -80, 10, 496, -62, 19, -53, 496, -62, -224, 28, -134, -44, 505, -134, -134, 442, 442, -116, 64, -8, -512, 64, -80, -8, -8, 1, -80, 10, -71, -62, 64, -8, -8, 1, 1, 10, 10, 1, -62, 28, 10, -62, -8, 1, 64, -8, 10, 1, 568, -71, 496, -62, 505, 514, 640, -80, -80, 10, 10, 100, 19, -71, -134, -44, -62, -53, -62, 28, 10, 1, -62, 10, 514, -44, -44, -116, -116, 136, 100, 10, -53, -44, -62, 514, -53, -62, 442, -116, 28, -44 },
        { -8, -80, -80, 496, 496, -224, 64, 640, -512, 4096, 64, -512, -8, -80, 64, -512, -8, 64, 568, 496, -8, 64, -80, 640, 1, 10, 10, -62, -62, 28, 10, 100, -62, 514, -53, -44, -62, -53, 28, -44, 442, -116, 514, -44, -44, -116, -116, 136, -8, -80, 64, -512, -8, 64, 1, 10, 10, -62, -62, 28, -8, 64, 1, 10, -8, 1, 1, -8, -71, -62, -80, 10, 1, 10, -8, 64, 1, -8, -71, 19, -62, -53, -134, -44, -80, 640, 10, 100, -80, 10, -71, 568, 505, 514, 496, -62, -71, -62, 1, -8, 10, -80, 505, -134, -134, 442, 442, -116, 10, -80, 19, -53, 496, -62, -62, 496, -134, -44, -224, 28 },
        { -8, 64, 568, 496, 640, -80, 64, -512, 640, 64, 4096, -512, 496, -224, -80, -8, 496, -80, 64, -8, -512, 64, -80, -8, 1, -8, -71, -62, -80, 10, 10, -80, 19, -53, 496, -62, 505, -134, -134, 442, 442, -116, 496, -62, -224, 28, -134, -44, -8, 64, -80, -8, -512, 64, 1, -8, -71, -62, -80, 10, 10, 1, -62, 28, 10, -62, 64, -8, -8, 1, 1, 10, -62, 28, 10, 1, -62, 10, 514, -44, -44, -116, -116, 136, 100, 10, -53, -44, -62, 514, -53, -62, 442, -116, 28, -44, -8, 1, 64, -8, 10, 1, 568, -71, 496, -62, 505, 514, 640, -80, -80, 10, 10, 100, 19, -71, -134, -44, -62, -53 },
        { -80, -8, 496, -224, -80, 496, 640, 64, 64, -512, -512, 4096, 568, 496, -8, 64, -80, 640, -8, -80, 64, -512, -8, 64, 10, 1, -62, 28, 10, -62, 100, 10, -53, -44, -62, 514, 514, -44, -44, -116, -116, 136, -62, -53, 28, -44, 442, -116, -80, -8, -8, 64, 64, -512, 10, 1, -62, 28, 10, -62, 1, -8, -71, -62, -80, 10, -8, 64, 1, 10, -8, 1, -71, -62, 1, -8, 10, -80, 505, -134, -134, 442, 442, -116, 10, -80, 19, -53, 496, -62, -62, 496, -134, -44, -224, 28, 1, 10, -8, 64, 1, -8, -71, 19, -62, -53, -134, -44, -80, 640, 10, 100, -80, 10, -71, 568, 505, 514, 496, -62 },
        { 64, -8, -512, 64, -80, -8, 640, -80, 64, -8, 496, 568, 4096, -512, -512, 64, 64, 640, 496, -80, -224, 496, -8, -80, -8, 1, 64, -8, 10, 1, 568, -71, 496, -62, 505, 514, 640, -80, -80, 10, 10, 100, 19, -71, -134, -44, -62, -53, -80, 10, -8, 1, -62, -71, 496, -62, -224, 28, -134, -44, -80, 10, 496, -62, 19, -53, -134, 505, 442, -116, -134, 442, -512, 64, 64, -8, -8, -80, 64, -8, -8, 1, 1, 10, -8, 1, -80, 10, -71, -62, 1, 10, 10, -62, -62, 28, -62, 10, 28, -62, 1, 10, -53, -62, 442, -116, 28, -44, -44, 514, -116, 136, -44, -116, 10, 100, -62, 514, -53, -44 },
        { -8, -80, 64, -512, -8, 64, -80, 496, -8, -80, -224, 496, -512, 4096, 64, 640, -512, 64, -80, 640, 496, 568, 64, -8, 1, 10, -8, 64, 1, -8, -71, 19, -62, -53, -134, -44, -80, 640, 10, 100, -80, 10, -71, 568, 505, 514, 496, -62, 10, -62, 1, 10, 28, -62, -62, -53, 28, -44, 442, -116, 10, 100, -62, 514, -53, -44, -44, 514, -116, 136, -44, -116, 64, -512, -8, -80, 64, -8, -8, 64, 1, 10, -8, 1, 1, 10, 10, -62, -62, 28, -8, 1, -80, 10, -71, -62, 10, -80, -62, -71, -8, 1, -62, 496, -134, -44, -224, 28, -134, 505, 442, -116, -134, 442, -80, 10, 496, -62, 19, -53 },
        { 640, -80, 64, -8, 496, 568, 64, -8, -512, 64, -80, -8, -512, 64, 4096, -512, 640, 64, -224, 496, 496, -80, -80, -8, -80, 10, -8, 1, -62, -71, 496, -62, -224, 28, -134, -44, -80, 10, 496, -62, 19, -53, -134, 505, 442, -116, -134, 442, -8, 1, 64, -8, 10, 1, 568, -71, 496, -62, 505, 514, 640, -80, -80, 10, 10, 100, 19, -71, -134, -44, -62, -53, 64, -8, -512, 64, -80, -8, -8, 1, -80, 10, -71, -62, 64, -8, -8, 1, 1, 10, 10, 1, -62, 28, 10, -62, 28, -62, -62, 10, 10, 1, -44, 514, -116, 136, -44, -116, -53, -62, 442, -116, 28, -44, 100, 10, -53, -44, -62, 514 },
        { -80, 496, -8, -80, -224, 496, -8, -80, 64, -512, -8, 64, 64, 640, -512, 4096, 64, -512, 496, 568, -80, 640, -8, 64, 10, -62, 1, 10, 28, -62, -62, -53, 28, -44, 442, -116, 10, 100, -62, 514, -53, -44, -44, 514, -116, 136, -44, -116, 1, 10, -8, 64, 1, -8, -71, 19, -62, -53, -134, -44, -80, 640, 10, 100, -80, 10, -71, 568, 505, 514, 496, -62, -8, -80, 64, -512, -8, 64, 1, 10, 10, -62, -62, 28, -8, 64, 1, 10, -8, 1, 1, -8, -71, -62, -80, 10, -62, -71, 10, -80, 1, -8, -134, 505, 442, -116, -134, 442, -62, 496, -134, -44, -224, 28, 10, -80, 19, -53, 496, -62 },
        { 568, 496, -8, 64, -80, 640, 496, -224, -80, -8, 496, -80, 64, -512, 640, 64, 4096, -512, -8, 64, -80, -8, -512, 64, -71, -62, 1, -8, 10, -80, 505, -134, -134, 442, 442, -116, 10, -80, 19, -53, 496, -62, -62, 496, -134, -44, -224, 28, -62, 28, 10, 1, -62, 10, 514, -44, -44, -116, -116, 136, 100, 10, -53, -44, -62, 514, -53, -62, 442, -116, 28, -44, -8, 64, -80, -8, -512, 64, 1, -8, -71, -62, -80, 10, 10, 1, -62, 28, 10, -62, 64, -8, -8, 1, 1, 10, 1, -8, 10, 1, 64, -8, -71, 568, 505, 514, 496, -62, 19, -71, -134, -44, -62, -53, 640, -80, -80, 10, 10, 100 },
        { 496, -224, -80, -8, 496, -80, 568, 496, -8, 64, -80, 640, 640, 64, 64, -512, -512, 4096, -80, -8, -8, 64, 64, -512, -62, 28, 10, 1, -62, 10, 514, -44, -44, -116, -116, 136, 100, 10, -53, -44, -62, 514, -53, -62, 442, -116, 28, -44, -71, -62, 1, -8, 10, -80, 505, -134, -134, 442, 442, -116, 10, -80, 19, -53, 496, -62, -62, 496, -134, -44, -224, 28, -80, -8, -8, 64, 64, -512, 10, 1, -62, 28, 10, -62, 1, -8, -71, -62, -80, 10, -8, 64, 1, 10, -8, 1, 10, 1, 1, -8, -8, 64, 19, -71, -134, -44, -62, -53, -71, 568, 505, 514, 496, -62, -80, 640, 10, 100, -80, 10 },
        { -8, 64, -80, -8, -512, 64, -80, 640, 496, 568, 64, -8, 496, -80, -224, 496, -8, -80, 4096, -512, -512, 64, 64, 640, 1, -8, 10, 1, 64, -8, -71, 568, 505, 514, 496, -62, 19, -71, -134, -44, -62, -53, 640, -80, -80, 10, 10, 100, 10, -80, -62, -71, -8, 1, -62, 496, -134, -44, -224, 28, -134, 505, 442, -116, -134, 442, -80, 10, 496, -62, 19, -53, -62, 10, 28, -62, 1, 10, -53, -62, 442, -116, 28, -44, -44, 514, -116, 136, -44, -116, 10, 100, -62, 514, -53, -44, -512, 64, 64, -8, -8, -80, 64, -8, -8, 1, 1, 10, -8, 1, -80, 10, -71, -62, 1, 10, 10, -62, -62, 28 },
        { -80, -8, -8, 64, 64, -512, 496, -80, -224, 496, -8, -80, -80, 640, 496, 568, 64, -8, -512, 4096, 64, 640, -512, 64, 10, 1, 1, -8, -8, 64, 19, -71, -134, -44, -62, -53, -71, 568, 505, 514, 496, -62, -80, 640, 10, 100, -80, 10, -62, 10, 28, -62, 1, 10, -53, -62, 442, -116, 28, -44, -44, 514, -116, 136, -44, -116, 10, 100, -62, 514, -53, -44, 10, -80, -62, -71, -8, 1, -62, 496, -134, -44, -224, 28, -134, 505, 442, -116, -134, 442, -80, 10, 496, -62, 19, -53, 64, -512, -8, -80, 64, -8, -8, 64, 1, 10, -8, 1, 1, 10, 10, -62, -62, 28, -8, 1, -80, 10, -71, -62 },
        { -80, 640, 496, 568, 64, -8, -8, 64, -80, -8, -512, 64, -224, 496, 496, -80, -80, -8, -512, 64, 4096, -512, 640, 64, 10, -80, -62, -71, -8, 1, -62, 496, -134, -44, -224, 28, -134, 505, 442, -116, -134, 442, -80, 10, 496, -62, 19, -53, 1, -8, 10, 1, 64, -8, -71, 568, 505, 514, 496, -62, 19, -71, -134, -44, -62, -53, 640, -80, -80, 10, 10, 100, 28, -62, -62, 10, 10, 1, -44, 514, -116, 136, -44, -116, -53, -62, 442, -116, 28, -44, 100, 10, -53, -44, -62, 514, 64, -8, -512, 64, -80, -8, -8, 1, -80, 10, -71, -62, 64, -8, -8, 1, 1, 10, 10, 1, -62, 28, 10, -62 },
        { 496, -80, -224, 496, -8, -80, -80, -8, -8, 64, 64, -512, 496, 568, -80, 640, -8, 64, 64, 640, -512, 4096, 64, -512, -62, 10, 28, -62, 1, 10, -53, -62, 442, -116, 28, -44, -44, 514, -116, 136, -44, -116, 10, 100, -62, 514, -53, -44, 10, 1, 1, -8, -8, 64, 19, -71, -134, -44, -62, -53, -71, 568, 505, 514, 496, -62, -80, 640, 10, 100, -80, 10, -62, -71, 10, -80, 1, -8, -134, 505, 442, -116, -134, 442, -62, 496, -134, -44, -224, 28, 10, -80, 19, -53, 496, -62, -8, -80, 64, -512, -8, 64, 1, 10, 10, -62, -62, 28, -8, 64, 1, 10, -8, 1, 1, -8, -71, -62, -80, 10 },
        { 496, 568, -80, 640, -8, 64, -224, 496, 496, -80, -80, -8, -8, 64, -80, -8, -512, 64, 64, -512, 640, 64, 4096, -512, -62, -71, 10, -80, 1, -8, -134, 505, 442, -116, -134, 442, -62, 496, -134, -44, -224, 28, 10, -80, 19, -53, 496, -62, 28, -62, -62, 10, 10, 1, -44, 514, -116, 136, -44, -116, -53, -62, 442, -116, 28, -44, 100, 10, -53, -44, -62, 514, 1, -8, 10, 1, 64, -8, -71, 568, 505, 514, 496, -62, 19, -71, -134, -44, -62, -53, 640, -80, -80, 10, 10, 100, -8, 64, -80, -8, -512, 64, 1, -8, -71, -62, -80, 10, 10, 1, -62, 28, 10, -62, 64, -8, -8, 1, 1, 10 },
        { -224, 496, 496, -80, -80, -8, 496, 568, -80, 640, -8, 64, -80, -8, -8, 64, 64, -512, 640, 64, 64, -512, -512, 4096, 28, -62, -62, 10, 10, 1, -44, 514, -116, 136, -44, -116, -53, -62, 442, -116, 28, -44, 100, 10, -53, -44, -62, 514, -62, -71, 10, -80, 1, -8, -134, 505, 442, -116, -134, 442, -62, 496, -134, -44, -224, 28, 10, -80, 19, -53, 496, -62, 10, 1, 1, -8, -8, 64, 19, -71, -134, -44, -62, -53, -71, 568, 505, 514, 496, -62, -80, 640, 10, 100, -80, 10, -80, -8, -8, 64, 64, -512, 10, 1, -62, 28, 10, -62, 1, -8, -71, -62, -80, 10, -8, 64, 1, 10, -8, 1 },
        { -512, 64, 64, -8, -8, -80, 64, -8, -8, 1, 1, 10, -8, 1, -80, 10, -71, -62, 1, 10, 10, -62, -62, 28, 4096, -512, -512, 64, 64, 640, -512, 64, 64, -8, -8, -80, 64, -8, 640, -80, 568, 496, -8, -80, -80, 496, 496, -224, 640, -80, -80, 10, 10, 100, 64, -8, -8, 1, 1, 10, 496, -62, 568, -71, 514, 505, -62, -53, -71, 19, -44, -134, -80, 10, 496, -62, 19, -53, -8, 1, -80, 10, -71, -62, -224, 28, 496, -62, -44, -134, -134, 442, 505, -134, -116, 442, 10, 100, -62, 514, -53, -44, 1, 10, 10, -62, -62, 28, 28, -44, -62, -53, -116, 442, -44, -116, 514, -44, 136, -116 },
        { 64, -512, -8, -80, 64, -8, -8, 64, 1, 10, -8, 1, 1, 10, 10, -62, -62, 28, -8, 1, -80, 10, -71, -62, -512, 4096, 64, 640, -512, 64, 64, -512, -8, -80, 64, -8, -8, -80, -80, 496, 496, -224, 64, -8, 640, -80, 568, 496, -80, 640, 10, 100, -80, 10, -8, 64, 1, 10, -8, 1, -62, -53, -71, 19, -44, -134, 496, -62, 568, -71, 514, 505, 10, 100, -62, 514, -53, -44, 1, 10, 10, -62, -62, 28, 28, -44, -62, -53, -116, 442, -44, -116, 514, -44, 136, -116, -80, 10, 496, -62, 19, -53, -8, 1, -80, 10, -71, -62, -224, 28, 496, -62, -44, -134, -134, 442, 505, -134, -116, 442 },
        { 64, -8, -512, 64, -80, -8, -8, 1, -80, 10, -71, -62, 64, -8, -8, 1, 1, 10, 10, 1, -62, 28, 10, -62, -512, 64, 4096, -512, 640, 64, 64, -8, 640, -80, 568, 496, -512, 64, 64, -8, -8, -80, -80, -8, 496, -224, -80, 496, -80, 10, 496, -62, 19, -53, -8, 1, -80, 10, -71, -62, -224, 28, 496, -62, -44, -134, -134, 442, 505, -134, -116, 442, 640, -80, -80, 10, 10, 100, 64, -8, -8, 1, 1, 10, 496, -62, 568, -71, 514, 505, -62, -53, -71, 19, -44, -134, 100, 10, -53, -44, -62, 514, 10, 1, -62, 28, 10, -62, -44, -116, 514, -44, 136, -116, 28, -44, -62, -53, -116, 442 },
        { -8, -80, 64, -512, -8, 64, 1, 10, 10, -62, -62, 28, -8, 64, 1, 10, -8, 1, 1, -8, -71, -62, -80, 10, 64, 640, -512, 4096, 64, -512, -8, -80, -80, 496, 496, -224, 64, -512, -8, -80, 64, -8, -8, 64, 568, 496, 640, -80, 10, 100, -62, 514, -53, -44, 1, 10, 10, -62, -62, 28, 28, -44, -62, -53, -116, 442, -44, -116, 514, -44, 136, -116, -80, 640, 10, 100, -80, 10, -8, 64, 1, 10, -8, 1, -62, -53, -71, 19, -44, -134, 496, -62, 568, -71, 514, 505, 10, -80, 19, -53, 496, -62, 1, -8, -71, -62, -80, 10, -134, 442, 505, -134, -116, 442, -224, 28, 496, -62, -44, -134 },
        { -8, 64, -80, -8, -512, 64, 1, -8, -71, -62, -80, 10, 10, 1, -62, 28, 10, -62, 64, -8, -8, 1, 1, 10, 64, -512, 640, 64, 4096, -512, -8, 64, 568, 496, 640, -80, -80, -8, 496, -224, -80, 496, -512, 64, 64, -8, -8, -80, 10, -80, 19, -53, 496, -62, 1, -8, -71, -62, -80, 10, -134, 442, 505, -134, -116, 442, -224, 28, 496, -62, -44, -134, 100, 10, -53, -44, -62, 514, 10, 1, -62, 28, 10, -62, -44, -116, 514, -44, 136, -116, 28, -44, -62, -53, -116, 442, 640, -80, -80, 10, 10, 100, 64, -8, -8, 1, 1, 10, 496, -62, 568, -71, 514, 505, -62, -53, -71, 19, -44, -134 },
        { -80, -8, -8, 64, 64, -512, 10, 1, -62, 28, 10, -62, 1, -8, -71, -62, -80, 10, -8, 64, 1, 10, -8, 1, 640, 64, 64, -512, -512, 4096, -80, -8, 496, -224, -80, 496, -8, 64, 568, 496, 640, -80, 64, -512, -8, -80, 64, -8, 100, 10, -53, -44, -62, 514, 10, 1, -62, 28, 10, -62, -44, -116, 514, -44, 136, -116, 28, -44, -62, -53, -116, 442, 10, -80, 19, -53, 496, -62, 1, -8, -71, -62, -80, 10, -134, 442, 505, -134, -116, 442, -224, 28, 496, -62, -44, -134, -80, 640, 10, 100, -80, 10, -8, 64, 1, 10, -8, 1, -62, -53, -71, 19, -44, -134, 496, -62, 568, -71, 514, 505 },
        { 64, -8, -8, 1, 1, 10, 640, -80, -80, 10, 10, 100, 568, -71, 496, -62, 505, 514, -71, 19, -62, -53, -134, -44, -512, 64, 64, -8, -8, -80, 4096, -512, -512, 64, 64, 640, 640, -80, 64, -8, 496, 568, -80, 496, -8, -80, -224, 496, 64, -8, -8, 1, 1, 10, -512, 64, 64, -8, -8, -80, -80, 10, -8, 1, -62, -71, 10, -62, 1, 10, 28, -62, 496, -62, -224, 28, -134, -44, -80, 10, -8, 1, -62, -71, 496, -62, -80, 10, -53, 19, 442, -116, -134, 505, 442, -134, -62, -53, 28, -44, 442, -116, 10, -62, 1, 10, 28, -62, -62, 514, 10, 100, -44, -53, -116, 136, -44, 514, -116, -44 },
        { -8, 64, 1, 10, -8, 1, -80, 640, 10, 100, -80, 10, -71, 19, -62, -53, -134, -44, 568, -71, 496, -62, 505, 514, 64, -512, -8, -80, 64, -8, -512, 4096, 64, 640, -512, 64, -80, 496, -8, -80, -224, 496, 640, -80, 64, -8, 496, 568, -8, 64, 1, 10, -8, 1, 64, -512, -8, -80, 64, -8, 10, -62, 1, 10, 28, -62, -80, 10, -8, 1, -62, -71, -62, -53, 28, -44, 442, -116, 10, -62, 1, 10, 28, -62, -62, 514, 10, 100, -44, -53, -116, 136, -44, 514, -116, -44, 496, -62, -224, 28, -134, -44, -80, 10, -8, 1, -62, -71, 496, -62, -80, 10, -53, 19, 442, -116, -134, 505, 442, -134 },
        { -8, 1, -80, 10, -71, -62, -80, 10, 496, -62, 19, -53, 496, -62, -224, 28, -134, -44, 505, -134, -134, 442, 442, -116, 64, -8, 640, -80, 568, 496, -512, 64, 4096, -512, 640, 64, 64, -8, -512, 64, -80, -8, 496, -224, -80, -8, 496, -80, -8, 1, -80, 10, -71, -62, 64, -8, -512, 64, -80, -8, -8, 1, 64, -8, 10, 1, -62, 28, 10, 1, -62, 10, 568, -71, 496, -62, 505, 514, -8, 1, 64, -8, 10, 1, -80, 10, 640, -80, 100, 10, -134, -44, 19, -71, -53, -62, 514, -44, -44, -116, -116, 136, -62, 28, 10, 1, -62, 10, -53, -44, 100, 10, 514, -62, 442, -116, -53, -62, -44, 28 },
        { 1, 10, 10, -62, -62, 28, 10, 100, -62, 514, -53, -44, -62, -53, 28, -44, 442, -116, 514, -44, -44, -116, -116, 136, -8, -80, -80, 496, 496, -224, 64, 640, -512, 4096, 64, -512, -8, -80, 64, -512, -8, 64, 568, 496, -8, 64, -80, 640, 1, 10, 10, -62, -62, 28, -8, -80, 64, -512, -8, 64, 1, 10, -8, 64, 1, -8, -71, -62, 1, -8, 10, -80, -71, 19, -62, -53, -134, -44, 1, 10, -8, 64, 1, -8, 10, 100, -80, 640, 10, -80, 505, 514, -71, 568, -62, 496, 505, -134, -134, 442, 442, -116, -71, -62, 1, -8, 10, -80, 19, -53, 10, -80, -62, 496, -134, -44, -62, 496, 28, -224 },
        { 1, -8, -71, -62, -80, 10, 10, -80, 19, -53, 496, -62, 505, -134, -134, 442, 442, -116, 496, -62, -224, 28, -134, -44, -8, 64, 568, 496, 640, -80, 64, -512, 640, 64, 4096, -512, 496, -224, -80, -8, 496, -80, 64, -8, -512, 64, -80, -8, 1, -8, -71, -62, -80, 10, -8, 64, -80, -8, -512, 64, -62, 28, 10, 1, -62, 10, -8, 1, 64, -8, 10, 1, 514, -44, -44, -116, -116, 136, -62, 28, 10, 1, -62, 10, -53, -44, 100, 10, 514, -62, 442, -116, -53, -62, -44, 28, 568, -71, 496, -62, 505, 514, -8, 1, 64, -8, 10, 1, -80, 10, 640, -80, 100, 10, -134, -44, 19, -71, -53, -62 },
        { 10, 1, -62, 28, 10, -62, 100, 10, -53, -44, -62, 514, 514, -44, -44, -116, -116, 136, -62, -53, 28, -44, 442, -116, -80, -8, 496, -224, -80, 496, 640, 64, 64, -512, -512, 4096, 568, 496, -8, 64, -80, 640, -8, -80, 64, -512, -8, 64, 10, 1, -62, 28, 10, -62, -80, -8, -8, 64, 64, -512, -71, -62, 1, -8, 10, -80, 1, 10, -8, 64, 1, -8, 505, -134, -134, 442, 442, -116, -71, -62, 1, -8, 10, -80, 19, -53, 10, -80, -62, 496, -134, -44, -62, 496, 28, -224, -71, 19, -62, -53, -134, -44, 1, 10, -8, 64, 1, -8, 10, 100, -80, 640, 10, -80, 505, 514, -71, 568, -62, 496 },
        { -8, 1, 64, -8, 10, 1, 568, -71, 496, -62, 505, 514, 640, -80, -80, 10, 10, 100, 19, -71, -134, -44, -62, -53, 64, -8, -512, 64, -80, -8, 640, -80, 64, -8, 496, 568, 4096, -512, -512, 64, 64, 640, 496, -80, -224, 496, -8, -80, 496, -62, -224, 28, -134, -44, -80, 10, -8, 1, -62, -71, 496, -62, -80, 10, -53, 19, 442, -116, -134, 505, 442, -134, 64, -8, -8, 1, 1, 10, -512, 64, 64, -8, -8, -80, -80, 10, -8, 1, -62, -71, 10, -62, 1, 10, 28, -62, -53, -62, 442, -116, 28, -44, -62, 10, 28, -62, 1, 10, -116, 136, -44, 514, -116, -44, -62, 514, 10, 100, -44, -53 },
        { 1, 10, -8, 64, 1, -8, -71, 19, -62, -53, -134, -44, -80, 640, 10, 100, -80, 10, -71, 568, 505, 514, 496, -62, -8, -80, 64, -512, -8, 64, -80, 496, -8, -80, -224, 496, -512, 4096, 64, 640, -512, 64, -80, 640, 496, 568, 64, -8, -62, -53, 28, -44, 442, -116, 10, -62, 1, 10, 28, -62, -62, 514, 10, 100, -44, -53, -116, 136, -44, 514, -116, -44, -8, 64, 1, 10, -8, 1, 64, -512, -8, -80, 64, -8, 10, -62, 1, 10, 28, -62, -80, 10, -8, 1, -62, -71, -62, 496, -134, -44, -224, 28, 10, -80, -62, -71, -8, 1, 442, -116, -134, 505, 442, -134, 496, -62, -80, 10, -53, 19 },
        { -80, 10, -8, 1, -62, -71, 496, -62, -224, 28, -134, -44, -80, 10, 496, -62, 19, -53, -134, 505, 442, -116, -134, 442, 640, -80, 64, -8, 496, 568, 64, -8, -512, 64, -80, -8, -512, 64, 4096, -512, 640, 64, -224, 496, 496, -80, -80, -8, 568, -71, 496, -62, 505, 514, -8, 1, 64, -8, 10, 1, -80, 10, 640, -80, 100, 10, -134, -44, 19, -71, -53, -62, -8, 1, -80, 10, -71, -62, 64, -8, -512, 64, -80, -8, -8, 1, 64, -8, 10, 1, -62, 28, 10, 1, -62, 10, -44, 514, -116, 136, -44, -116, 28, -62, -62, 10, 10, 1, 442, -116, -53, -62, -44, 28, -53, -44, 100, 10, 514, -62 },
        { 10, -62, 1, 10, 28, -62, -62, -53, 28, -44, 442, -116, 10, 100, -62, 514, -53, -44, -44, 514, -116, 136, -44, -116, -80, 496, -8, -80, -224, 496, -8, -80, 64, -512, -8, 64, 64, 640, -512, 4096, 64, -512, 496, 568, -80, 640, -8, 64, -71, 19, -62, -53, -134, -44, 1, 10, -8, 64, 1, -8, 10, 100, -80, 640, 10, -80, 505, 514, -71, 568, -62, 496, 1, 10, 10, -62, -62, 28, -8, -80, 64, -512, -8, 64, 1, 10, -8, 64, 1, -8, -71, -62, 1, -8, 10, -80, -134, 505, 442, -116, -134, 442, -62, -71, 10, -80, 1, -8, -134, -44, -62, 496, 28, -224, 19, -53, 10, -80, -62, 496 },
        { -71, -62, 1, -8, 10, -80, 505, -134, -134, 442, 442, -116, 10, -80, 19, -53, 496, -62, -62, 496, -134, -44, -224, 28, 568, 496, -8, 64, -80, 640, 496, -224, -80, -8, 496, -80, 64, -512, 640, 64, 4096, -512, -8, 64, -80, -8, -512, 64, 514, -44, -44, -116, -116, 136, -62, 28, 10, 1, -62, 10, -53, -44, 100, 10, 514, -62, 442, -116, -53, -62, -44, 28, 1, -8, -71, -62, -80, 10, -8, 64, -80, -8, -512, 64, -62, 28, 10, 1, -62, 10, -8, 1, 64, -8, 10, 1, -71, 568, 505, 514, 496, -62, 1, -8, 10, 1, 64, -8, -134, -44, 19, -71, -53, -62, -80, 10, 640, -80, 100, 10 },
        { -62, 28, 10, 1, -62, 10, 514, -44, -44, -116, -116, 136, 100, 10, -53, -44, -62, 514, -53, -62, 442, -116, 28, -44, 496, -224, -80, -8, 496, -80, 568, 496, -8, 64, -80, 640, 640, 64, 64, -512, -512, 4096, -80, -8, -8, 64, 64, -512, 505, -134, -134, 442, 442, -116, -71, -62, 1, -8, 10, -80, 19, -53, 10, -80, -62, 496, -134, -44, -62, 496, 28, -224, 10, 1, -62, 28, 10, -62, -80, -8, -8, 64, 64, -512, -71, -62, 1, -8, 10, -80, 1, 10, -8, 64, 1, -8, 19, -71, -134, -44, -62, -53, 10, 1, 1, -8, -8, 64, 505, 514, -71, 568, -62, 496, 10, 100, -80, 640, 10, -80 },
        { 1, -8, 10, 1, 64, -8, -71, 568, 505, 514, 496, -62, 19, -71, -134, -44, -62, -53, 640, -80, -80, 10, 10, 100, -8, 64, -80, -8, -512, 64, -80, 640, 496, 568, 64, -8, 496, -80, -224, 496, -8, -80, 4096, -512, -512, 64, 64, 640, -62, 496, -134, -44, -224, 28, 10, -80, -62, -71, -8, 1, 442, -116, -134, 505, 442, -134, 496, -62, -80, 10, -53, 19, -53, -62, 442, -116, 28, -44, -62, 10, 28, -62, 1, 10, -116, 136, -44, 514, -116, -44, -62, 514, 10, 100, -44, -53, 64, -8, -8, 1, 1, 10, -512, 64, 64, -8, -8, -80, -80, 10, -8, 1, -62, -71, 10, -62, 1, 10, 28, -62 },
        { 10, 1, 1, -8, -8, 64, 19, -71, -134, -44, -62, -53, -71, 568, 505, 514, 496, -62, -80, 640, 10, 100, -80, 10, -80, -8, -8, 64, 64, -512, 496, -80, -224, 496, -8, -80, -80, 640, 496, 568, 64, -8, -512, 4096, 64, 640, -512, 64, -53, -62, 442, -116, 28, -44, -62, 10, 28, -62, 1, 10, -116, 136, -44, 514, -116, -44, -62, 514, 10, 100, -44, -53, -62, 496, -134, -44, -224, 28, 10, -80, -62, -71, -8, 1, 442, -116, -134, 505, 442, -134, 496, -62, -80, 10, -53, 19, -8, 64, 1, 10, -8, 1, 64, -512, -8, -80, 64, -8, 10, -62, 1, 10, 28, -62, -80, 10, -8, 1, -62, -71 },
        { 10, -80, -62, -71, -8, 1, -62, 496, -134, -44, -224, 28, -134, 505, 442, -116, -134, 442, -80, 10, 496, -62, 19, -53, -80, 640, 496, 568, 64, -8, -8, 64, -80, -8, -512, 64, -224, 496, 496, -80, -80, -8, -512, 64, 4096, -512, 640, 64, -71, 568, 505, 514, 496, -62, 1, -8, 10, 1, 64, -8, -134, -44, 19, -71, -53, -62, -80, 10, 640, -80, 100, 10, -44, 514, -116, 136, -44, -116, 28, -62, -62, 10, 10, 1, 442, -116, -53, -62, -44, 28, -53, -44, 100, 10, 514, -62, -8, 1, -80, 10, -71, -62, 64, -8, -512, 64, -80, -8, -8, 1, 64, -8, 10, 1, -62, 28, 10, 1, -62, 10 },
        { -62, 10, 28, -62, 1, 10, -53, -62, 442, -116, 28, -44, -44, 514, -116, 136, -44, -116, 10, 100, -62, 514, -53, -44, 496, -80, -224, 496, -8, -80, -80, -8, -8, 64, 64, -512, 496, 568, -80, 640, -8, 64, 64, 640, -512, 4096, 64, -512, 19, -71, -134, -44, -62, -53, 10, 1, 1, -8, -8, 64, 505, 514, -71, 568, -62, 496, 10, 100, -80, 640, 10, -80, -134, 505, 442, -116, -134, 442, -62, -71, 10, -80, 1, -8, -134, -44, -62, 496, 28, -224, 19, -53, 10, -80, -62, 496, 1, 10, 10, -62, -62, 28, -8, -80, 64, -512, -8, 64, 1, 10, -8, 64, 1, -8, -71, -62, 1, -8, 10, -80 },
        { -62, -71, 10, -80, 1, -8, -134, 505, 442, -116, -134, 442, -62, 496, -134, -44, -224, 28, 10, -80, 19, -53, 496, -62, 496, 568, -80, 640, -8, 64, -224, 496, 496, -80, -80, -8, -8, 64, -80, -8, -512, 64, 64, -512, 640, 64, 4096, -512, -44, 514, -116, 136, -44, -116, 28, -62, -62, 10, 10, 1, 442, -116, -53, -62, -44, 28, -53, -44, 100, 10, 514, -62, -71, 568, 505, 514, 496, -62, 1, -8, 10, 1, 64, -8, -134, -44, 19, -71, -53, -62, -80, 10, 640, -80, 100, 10, 1, -8, -71, -62, -80, 10, -8, 64, -80, -8, -512, 64, -62, 28, 10, 1, -62, 10, -8, 1, 64, -8, 10, 1 },
        { 28, -62, -62, 10, 10, 1, -44, 514, -116, 136, -44, -116, -53, -62, 442, -116, 28, -44, 100, 10, -53, -44, -62, 514, -224, 496, 496, -80, -80, -8, 496, 568, -80, 640, -8, 64, -80, -8, -8, 64, 64, -512, 640, 64, 64, -512, -512, 4096, -134, 505, 442, -116, -134, 442, -62, -71, 10, -80, 1, -8, -134, -44, -62, 496, 28, -224, 19, -53, 10, -80, -62, 496, 19, -71, -134, -44, -62, -53, 10, 1, 1, -8, -8, 64, 505, 514, -71, 568, -62, 496, 10, 100, -80, 640, 10, -80, 10, 1, -62, 28, 10, -62, -80, -8, -8, 64, 64, -512, -71, -62, 1, -8, 10, -80, 1, 10, -8, 64, 1, -8 },
        { 64, -8, -8, 1, 1, 10, -512, 64, 64, -8, -8, -80, -80, 10, -8, 1, -62, -71, 10, -62, 1, 10, 28, -62, 640, -80, -80, 10, 10, 100, 64, -8, -8, 1, 1, 10, 496, -62, 568, -71, 514, 505, -62, -53, -71, 19, -44, -134, 4096, -512, -512, 64, 64, 640, -512, 64, 64, -8, -8, -80, 64, -8, 640, -80, 568, 496, -8, -80, -80, 496, 496, -224, 496, -62, -80, 10, -53, 19, -224, 28, 496, -62, -44, -134, -8, 1, -80, 10, -71, -62, 442, -134, -116, 442, 505, -134, -62, 514, 10, 100, -44, -53, 28, -44, -62, -53, -116, 442, 1, 10, 10, -62, -62, 28, -116, -44, 136, -116, 514, -44 },
        { -8, 64, 1, 10, -8, 1, 64, -512, -8, -80, 64, -8, 10, -62, 1, 10, 28, -62, -80, 10, -8, 1, -62, -71, -80, 640, 10, 100, -80, 10, -8, 64, 1, 10, -8, 1, -62, -53, -71, 19, -44, -134, 496, -62, 568, -71, 514, 505, -512, 4096, 64, 640, -512, 64, 64, -512, -8, -80, 64, -8, -8, -80, -80, 496, 496, -224, 64, -8, 640, -80, 568, 496, -62, 514, 10, 100, -44, -53, 28, -44, -62, -53, -116, 442, 1, 10, 10, -62, -62, 28, -116, -44, 136, -116, 514, -44, 496, -62, -80, 10, -53, 19, -224, 28, 496, -62, -44, -134, -8, 1, -80, 10, -71, -62, 442, -134, -116, 442, 505, -134 },
        { -8, 1, -80, 10, -71, -62, 64, -8, -512, 64, -80, -8, -8, 1, 64, -8, 10, 1, -62, 28, 10, 1, -62, 10, -80, 10, 496, -62, 19, -53, -8, 1, -80, 10, -71, -62, -224, 28, 496, -62, -44, -134, -134, 442, 505, -134, -116, 442, -512, 64, 4096, -512, 640, 64, 64, -8, 640, -80, 568, 496, -512, 64, 64, -8, -8, -80, -80, -8, 496, -224, -80, 496, -80, 10, 640, -80, 100, 10, 496, -62, 568, -71, 514, 505, 64, -8, -8, 1, 1, 10, -53, -62, -44, -134, -71, 19, -53, -44, 100, 10, 514, -62, -44, -116, 514, -44, 136, -116, 10, 1, -62, 28, 10, -62, -44, 28, -116, 442, -62, -53 },
        { 1, 10, 10, -62, -62, 28, -8, -80, 64, -512, -8, 64, 1, 10, -8, 64, 1, -8, -71, -62, 1, -8, 10, -80, 10, 100, -62, 514, -53, -44, 1, 10, 10, -62, -62, 28, 28, -44, -62, -53, -116, 442, -44, -116, 514, -44, 136, -116, 64, 640, -512, 4096, 64, -512, -8, -80, -80, 496, 496, -224, 64, -512, -8, -80, 64, -8, -8, 64, 568, 496, 640, -80, 10, 100, -80, 640, 10, -80, -62, -53, -71, 19, -44, -134, -8, 64, 1, 10, -8, 1, -62, 496, 514, 505, 568, -71, 19, -53, 10, -80, -62, 496, -134, 442, 505, -134, -116, 442, 1, -8, -71, -62, -80, 10, 28, -224, -44, -134, 496, -62 },
        { 1, -8, -71, -62, -80, 10, -8, 64, -80, -8, -512, 64, -62, 28, 10, 1, -62, 10, -8, 1, 64, -8, 10, 1, 10, -80, 19, -53, 496, -62, 1, -8, -71, -62, -80, 10, -134, 442, 505, -134, -116, 442, -224, 28, 496, -62, -44, -134, 64, -512, 640, 64, 4096, -512, -8, 64, 568, 496, 640, -80, -80, -8, 496, -224, -80, 496, -512, 64, 64, -8, -8, -80, -53, -44, 100, 10, 514, -62, -44, -116, 514, -44, 136, -116, 10, 1, -62, 28, 10, -62, -44, 28, -116, 442, -62, -53, -80, 10, 640, -80, 100, 10, 496, -62, 568, -71, 514, 505, 64, -8, -8, 1, 1, 10, -53, -62, -44, -134, -71, 19 },
        { 10, 1, -62, 28, 10, -62, -80, -8, -8, 64, 64, -512, -71, -62, 1, -8, 10, -80, 1, 10, -8, 64, 1, -8, 100, 10, -53, -44, -62, 514, 10, 1, -62, 28, 10, -62, -44, -116, 514, -44, 136, -116, 28, -44, -62, -53, -116, 442, 640, 64, 64, -512, -512, 4096, -80, -8, 496, -224, -80, 496, -8, 64, 568, 496, 640, -80, 64, -512, -8, -80, 64, -8, 19, -53, 10, -80, -62, 496, -134, 442, 505, -134, -116, 442, 1, -8, -71, -62, -80, 10, 28, -224, -44, -134, 496, -62, 10, 100, -80, 640, 10, -80, -62, -53, -71, 19, -44, -134, -8, 64, 1, 10, -8, 1, -62, 496, 514, 505, 568, -71 },
        { 640, -80, -80, 10, 10, 100, 64, -8, -8, 1, 1, 10, 496, -62, 568, -71, 514, 505, -62, -53, -71, 19, -44, -134, 64, -8, -8, 1, 1, 10, -512, 64, 64, -8, -8, -80, -80, 10, -8, 1, -62, -71, 10, -62, 1, 10, 28, -62, -512, 64, 64, -8, -8, -80, 4096, -512, -512, 64, 64, 640, 640, -80, 64, -8, 496, 568, -80, 496, -8, -80, -224, 496, -224, 28, 496, -62, -44, -134, 496, -62, -80, 10, -53, 19, -80, 10, -8, 1, -62, -71, -116, 442, 442, -134, -134, 505, 28, -44, -62, -53, -116, 442, -62, 514, 10, 100, -44, -53, 10, -62, 1, 10, 28, -62, 136, -116, -116, -44, -44, 514 },
        { -80, 640, 10, 100, -80, 10, -8, 64, 1, 10, -8, 1, -62, -53, -71, 19, -44, -134, 496, -62, 568, -71, 514, 505, -8, 64, 1, 10, -8, 1, 64, -512, -8, -80, 64, -8, 10, -62, 1, 10, 28, -62, -80, 10, -8, 1, -62, -71, 64, -512, -8, -80, 64, -8, -512, 4096, 64, 640, -512, 64, -80, 496, -8, -80, -224, 496, 640, -80, 64, -8, 496, 568, 28, -44, -62, -53, -116, 442, -62, 514, 10, 100, -44, -53, 10, -62, 1, 10, 28, -62, 136, -116, -116, -44, -44, 514, -224, 28, 496, -62, -44, -134, 496, -62, -80, 10, -53, 19, -80, 10, -8, 1, -62, -71, -116, 442, 442, -134, -134, 505 },
        { -80, 10, 496, -62, 19, -53, -8, 1, -80, 10, -71, -62, -224, 28, 496, -62, -44, -134, -134, 442, 505, -134, -116, 442, -8, 1, -80, 10, -71, -62, 64, -8, -512, 64, -80, -8, -8, 1, 64, -8, 10, 1, -62, 28, 10, 1, -62, 10, 64, -8, 640, -80, 568, 496, -512, 64, 4096, -512, 640, 64, 64, -8, -512, 64, -80, -8, 496, -224, -80, -8, 496, -80, 496, -62, 568, -71, 514, 505, -80, 10, 640, -80, 100, 10, -8, 1, 64, -8, 10, 1, -44, -134, -53, -62, 19, -71, -44, -116, 514, -44, 136, -116, -53, -44, 100, 10, 514, -62, -62, 28, 10, 1, -62, 10, -116, 442, -44, 28, -53, -62 },
        { 10, 100, -62, 514, -53, -44, 1, 10, 10, -62, -62, 28, 28, -44, -62, -53, -116, 442, -44, -116, 514, -44, 136, -116, 1, 10, 10, -62, -62, 28, -8, -80, 64, -512, -8, 64, 1, 10, -8, 64, 1, -8, -71, -62, 1, -8, 10, -80, -8, -80, -80, 496, 496, -224, 64, 640, -512, 4096, 64, -512, -8, -80, 64, -512, -8, 64, 568, 496, -8, 64, -80, 640, -62, -53, -71, 19, -44, -134, 10, 100, -80, 640, 10, -80, 1, 10, -8, 64, 1, -8, 514, 505, -62, 496, -71, 568, -134, 442, 505, -134, -116, 442, 19, -53, 10, -80, -62, 496, -71, -62, 1, -8, 10, -80, -44, -134, 28, -224, -62, 496 },
        { 10, -80, 19, -53, 496, -62, 1, -8, -71, -62, -80, 10, -134, 442, 505, -134, -116, 442, -224, 28, 496, -62, -44, -134, 1, -8, -71, -62, -80, 10, -8, 64, -80, -8, -512, 64, -62, 28, 10, 1, -62, 10, -8, 1, 64, -8, 10, 1, -8, 64, 568, 496, 640, -80, 64, -512, 640, 64, 4096, -512, 496, -224, -80, -8, 496, -80, 64, -8, -512, 64, -80, -8, -44, -116, 514, -44, 136, -116, -53, -44, 100, 10, 514, -62, -62, 28, 10, 1, -62, 10, -116, 442, -44, 28, -53, -62, 496, -62, 568, -71, 514, 505, -80, 10, 640, -80, 100, 10, -8, 1, 64, -8, 10, 1, -44, -134, -53, -62, 19, -71 },
        { 100, 10, -53, -44, -62, 514, 10, 1, -62, 28, 10, -62, -44, -116, 514, -44, 136, -116, 28, -44, -62, -53, -116, 442, 10, 1, -62, 28, 10, -62, -80, -8, -8, 64, 64, -512, -71, -62, 1, -8, 10, -80, 1, 10, -8, 64, 1, -8, -80, -8, 496, -224, -80, 496, 640, 64, 64, -512, -512, 4096, 568, 496, -8, 64, -80, 640, -8, -80, 64, -512, -8, 64, -134, 442, 505, -134, -116, 442, 19, -53, 10, -80, -62, 496, -71, -62, 1, -8, 10, -80, -44, -134, 28, -224, -62, 496, -62, -53, -71, 19, -44, -134, 10, 100, -80, 640, 10, -80, 1, 10, -8, 64, 1, -8, 514, 505, -62, 496, -71, 568 },
        { 568, -71, 496, -62, 505, 514, -8, 1, 64, -8, 10, 1, -80, 10, 640, -80, 100, 10, -134, -44, 19, -71, -53, -62, 496, -62, -224, 28, -134, -44, -80, 10, -8, 1, -62, -71, 496, -62, -80, 10, -53, 19, 442, -116, -134, 505, 442, -134, 64, -8, -512, 64, -80, -8, 640, -80, 64, -8, 496, 568, 4096, -512, -512, 64, 64, 640, 496, -80, -224, 496, -8, -80, -8, 1, 64, -8, 10, 1, -80, 10, -8, 1, -62, -71, -512, 64, 64, -8, -8, -80, -62, 10, 28, -62, 1, 10, 442, -116, -53, -62, -44, 28, -116, 136, -44, 514, -116, -44, -62, 10, 28, -62, 1, 10, 514, -62, -44, -53, 10, 100 },
        { -71, 19, -62, -53, -134, -44, 1, 10, -8, 64, 1, -8, 10, 100, -80, 640, 10, -80, 505, 514, -71, 568, -62, 496, -62, -53, 28, -44, 442, -116, 10, -62, 1, 10, 28, -62, -62, 514, 10, 100, -44, -53, -116, 136, -44, 514, -116, -44, -8, -80, 64, -512, -8, 64, -80, 496, -8, -80, -224, 496, -512, 4096, 64, 640, -512, 64, -80, 640, 496, 568, 64, -8, 1, 10, -8, 64, 1, -8, 10, -62, 1, 10, 28, -62, 64, -512, -8, -80, 64, -8, 10, -80, -62, -71, -8, 1, -134, -44, -62, 496, 28, -224, 442, -116, -134, 505, 442, -134, 10, -80, -62, -71, -8, 1, -62, 496, -53, 19, -80, 10 },
        { 496, -62, -224, 28, -134, -44, -80, 10, -8, 1, -62, -71, 496, -62, -80, 10, -53, 19, 442, -116, -134, 505, 442, -134, 568, -71, 496, -62, 505, 514, -8, 1, 64, -8, 10, 1, -80, 10, 640, -80, 100, 10, -134, -44, 19, -71, -53, -62, 640, -80, 64, -8, 496, 568, 64, -8, -512, 64, -80, -8, -512, 64, 4096, -512, 640, 64, -224, 496, 496, -80, -80, -8, -80, 10, -8, 1, -62, -71, -8, 1, 64, -8, 10, 1, 64, -8, -512, 64, -80, -8, 28, -62, -62, 10, 10, 1, -116, 136, -44, 514, -116, -44, 442, -116, -53, -62, -44, 28, 28, -62, -62, 10, 10, 1, -44, -53, 514, -62, 100, 10 },
        { -62, -53, 28, -44, 442, -116, 10, -62, 1, 10, 28, -62, -62, 514, 10, 100, -44, -53, -116, 136, -44, 514, -116, -44, -71, 19, -62, -53, -134, -44, 1, 10, -8, 64, 1, -8, 10, 100, -80, 640, 10, -80, 505, 514, -71, 568, -62, 496, -80, 496, -8, -80, -224, 496, -8, -80, 64, -512, -8, 64, 64, 640, -512, 4096, 64, -512, 496, 568, -80, 640, -8, 64, 10, -62, 1, 10, 28, -62, 1, 10, -8, 64, 1, -8, -8, -80, 64, -512, -8, 64, -62, -71, 10, -80, 1, -8, 442, -116, -134, 505, 442, -134, -134, -44, -62, 496, 28, -224, -62, -71, 10, -80, 1, -8, -53, 19, -62, 496, 10, -80 },
        { 505, -134, -134, 442, 442, -116, -71, -62, 1, -8, 10, -80, 19, -53, 10, -80, -62, 496, -134, -44, -62, 496, 28, -224, 514, -44, -44, -116, -116, 136, -62, 28, 10, 1, -62, 10, -53, -44, 100, 10, 514, -62, 442, -116, -53, -62, -44, 28, 568, 496, -8, 64, -80, 640, 496, -224, -80, -8, 496, -80, 64, -512, 640, 64, 4096, -512, -8, 64, -80, -8, -512, 64, -71, -62, 1, -8, 10, -80, -62, 28, 10, 1, -62, 10, -8, 64, -80, -8, -512, 64, 1, -8, 10, 1, 64, -8, 505, 514, -71, 568, -62, 496, -134, -44, 19, -71, -53, -62, 1, -8, 10, 1, 64, -8, 10, -80, 100, 10, 640, -80 },
        { 514, -44, -44, -116, -116, 136, -62, 28, 10, 1, -62, 10, -53, -44, 100, 10, 514, -62, 442, -116, -53, -62, -44, 28, 505, -134, -134, 442, 442, -116, -71, -62, 1, -8, 10, -80, 19, -53, 10, -80, -62, 496, -134, -44, -62, 496, 28, -224, 496, -224, -80, -8, 496, -80, 568, 496, -8, 64, -80, 640, 640, 64, 64, -512, -512, 4096, -80, -8, -8, 64, 64, -512, -62, 28, 10, 1, -62, 10, -71, -62, 1, -8, 10, -80, -80, -8, -8, 64, 64, -512, 10, 1, 1, -8, -8, 64, -134, -44, 19, -71, -53, -62, 505, 514, -71, 568, -62, 496, 10, 1, 1, -8, -8, 64, 100, 10, 10, -80, -80, 640 },
        { -71, 568, 505, 514, 496, -62, 1, -8, 10, 1, 64, -8, -134, -44, 19, -71, -53, -62, -80, 10, 640, -80, 100, 10, -62, 496, -134, -44, -224, 28, 10, -80, -62, -71, -8, 1, 442, -116, -134, 505, 442, -134, 496, -62, -80, 10, -53, 19, -8, 64, -80, -8, -512, 64, -80, 640, 496, 568, 64, -8, 496, -80, -224, 496, -8, -80, 4096, -512, -512, 64, 64, 640, 442, -116, -53, -62, -44, 28, -116, 136, -44, 514, -116, -44, -62, 10, 28, -62, 1, 10, 514, -62, -44, -53, 10, 100, -8, 1, 64, -8, 10, 1, -80, 10, -8, 1, -62, -71, -512, 64, 64, -8, -8, -80, -62, 10, 28, -62, 1, 10 },
        { 19, -71, -134, -44, -62, -53, 10, 1, 1, -8, -8, 64, 505, 514, -71, 568, -62, 496, 10, 100, -80, 640, 10, -80, -53, -62, 442, -116, 28, -44, -62, 10, 28, -62, 1, 10, -116, 136, -44, 514, -116, -44, -62, 514, 10, 100, -44, -53, -80, -8, -8, 64, 64, -512, 496, -80, -224, 496, -8, -80, -80, 640, 496, 568, 64, -8, -512, 4096, 64, 640, -512, 64, -134, -44, -62, 496, 28, -224, 442, -116, -134, 505, 442, -134, 10, -80, -62, -71, -8, 1, -62, 496, -53, 19, -80, 10, 1, 10, -8, 64, 1, -8, 10, -62, 1, 10, 28, -62, 64, -512, -8, -80, 64, -8, 10, -80, -62, -71, -8, 1 },
        { -62, 496, -134, -44, -224, 28, 10, -80, -62, -71, -8, 1, 442, -116, -134, 505, 442, -134, 496, -62, -80, 10, -53, 19, -71, 568, 505, 514, 496, -62, 1, -8, 10, 1, 64, -8, -134, -44, 19, -71, -53, -62, -80, 10, 640, -80, 100, 10, -80, 640, 496, 568, 64, -8, -8, 64, -80, -8, -512, 64, -224, 496, 496, -80, -80, -8, -512, 64, 4096, -512, 640, 64, -116, 136, -44, 514, -116, -44, 442, -116, -53, -62, -44, 28, 28, -62, -62, 10, 10, 1, -44, -53, 514, -62, 100, 10, -80, 10, -8, 1, -62, -71, -8, 1, 64, -8, 10, 1, 64, -8, -512, 64, -80, -8, 28, -62, -62, 10, 10, 1 },
        { -53, -62, 442, -116, 28, -44, -62, 10, 28, -62, 1, 10, -116, 136, -44, 514, -116, -44, -62, 514, 10, 100, -44, -53, 19, -71, -134, -44, -62, -53, 10, 1, 1, -8, -8, 64, 505, 514, -71, 568, -62, 496, 10, 100, -80, 640, 10, -80, 496, -80, -224, 496, -8, -80, -80, -8, -8, 64, 64, -512, 496, 568, -80, 640, -8, 64, 64, 640, -512, 4096, 64, -512, 442, -116, -134, 505, 442, -134, -134, -44, -62, 496, 28, -224, -62, -71, 10, -80, 1, -8, -53, 19, -62, 496, 10, -80, 10, -62, 1, 10, 28, -62, 1, 10, -8, 64, 1, -8, -8, -80, 64, -512, -8, 64, -62, -71, 10, -80, 1, -8 },
        { -134, 505, 442, -116, -134, 442, -62, -71, 10, -80, 1, -8, -134, -44, -62, 496, 28, -224, 19, -53, 10, -80, -62, 496, -44, 514, -116, 136, -44, -116, 28, -62, -62, 10, 10, 1, 442, -116, -53, -62, -44, 28, -53, -44, 100, 10, 514, -62, 496, 568, -80, 640, -8, 64, -224, 496, 496, -80, -80, -8, -8, 64, -80, -8, -512, 64, 64, -512, 640, 64, 4096, -512, 505, 514, -71, 568, -62, 496, -134, -44, 19, -71, -53, -62, 1, -8, 10, 1, 64, -8, 10, -80, 100, 10, 640, -80, -71, -62, 1, -8, 10, -80, -62, 28, 10, 1, -62, 10, -8, 64, -80, -8, -512, 64, 1, -8, 10, 1, 64, -8 },
        { -44, 514, -116, 136, -44, -116, 28, -62, -62, 10, 10, 1, 442, -116, -53, -62, -44, 28, -53, -44, 100, 10, 514, -62, -134, 505, 442, -116, -134, 442, -62, -71, 10, -80, 1, -8, -134, -44, -62, 496, 28, -224, 19, -53, 10, -80, -62, 496, -224, 496, 496, -80, -80, -8, 496, 568, -80, 640, -8, 64, -80, -8, -8, 64, 64, -512, 640, 64, 64, -512, -512, 4096, -134, -44, 19, -71, -53, -62, 505, 514, -71, 568, -62, 496, 10, 1, 1, -8, -8, 64, 100, 10, 10, -80, -80, 640, -62, 28, 10, 1, -62, 10, -71, -62, 1, -8, 10, -80, -80, -8, -8, 64, 64, -512, 10, 1, 1, -8, -8, 64 },
        { -8, 1, 64, -8, 10, 1, -80, 10, -8, 1, -62, -71, -512, 64, 64, -8, -8, -80, -62, 10, 28, -62, 1, 10, -80, 10, 640, -80, 100, 10, 496, -62, 568, -71, 514, 505, 64, -8, -8, 1, 1, 10, -53, -62, -44, -134, -71, 19, 496, -62, -80, 10, -53, 19, -224, 28, 496, -62, -44, -134, -8, 1, -80, 10, -71, -62, 442, -134, -116, 442, 505, -134, 4096, -512, -512, 64, 64, 640, -512, 64, 64, -8, -8, -80, 64, -8, 640, -80, 568, 496, -8, -80, -80, 496, 496, -224, 514, -62, -44, -53, 10, 100, -44, 28, -116, 442, -62, -53, -116, -44, 136, -116, 514, -44, 1, 10, 10, -62, -62, 28 },
        { 1, 10, -8, 64, 1, -8, 10, -62, 1, 10, 28, -62, 64, -512, -8, -80, 64, -8, 10, -80, -62, -71, -8, 1, 10, 100, -80, 640, 10, -80, -62, -53, -71, 19, -44, -134, -8, 64, 1, 10, -8, 1, -62, 496, 514, 505, 568, -71, -62, 514, 10, 100, -44, -53, 28, -44, -62, -53, -116, 442, 1, 10, 10, -62, -62, 28, -116, -44, 136, -116, 514, -44, -512, 4096, 64, 640, -512, 64, 64, -512, -8, -80, 64, -8, -8, -80, -80, 496, 496, -224, 64, -8, 640, -80, 568, 496, -62, 496, -53, 19, -80, 10, 28, -224, -44, -134, 496, -62, 442, -134, -116, 442, 505, -134, -8, 1, -80, 10, -71, -62 },
        { -80, 10, -8, 1, -62, -71, -8, 1, 64, -8, 10, 1, 64, -8, -512, 64, -80, -8, 28, -62, -62, 10, 10, 1, 496, -62, -80, 10, -53, 19, -224, 28, 496, -62, -44, -134, -8, 1, -80, 10, -71, -62, 442, -134, -116, 442, 505, -134, -80, 10, 640, -80, 100, 10, 496, -62, 568, -71, 514, 505, 64, -8, -8, 1, 1, 10, -53, -62, -44, -134, -71, 19, -512, 64, 4096, -512, 640, 64, 64, -8, 640, -80, 568, 496, -512, 64, 64, -8, -8, -80, -80, -8, 496, -224, -80, 496, -44, -53, 514, -62, 100, 10, -116, -44, 136, -116, 514, -44, -44, 28, -116, 442, -62, -53, 10, 1, -62, 28, 10, -62 },
        { 10, -62, 1, 10, 28, -62, 1, 10, -8, 64, 1, -8, -8, -80, 64, -512, -8, 64, -62, -71, 10, -80, 1, -8, -62, 514, 10, 100, -44, -53, 28, -44, -62, -53, -116, 442, 1, 10, 10, -62, -62, 28, -116, -44, 136, -116, 514, -44, 10, 100, -80, 640, 10, -80, -62, -53, -71, 19, -44, -134, -8, 64, 1, 10, -8, 1, -62, 496, 514, 505, 568, -71, 64, 640, -512, 4096, 64, -512, -8, -80, -80, 496, 496, -224, 64, -512, -8, -80, 64, -8, -8, 64, 568, 496, 640, -80, -53, 19, -62, 496, 10, -80, 442, -134, -116, 442, 505, -134, 28, -224, -44, -134, 496, -62, 1, -8, -71, -62, -80, 10 },
        { -71, -62, 1, -8, 10, -80, -62, 28, 10, 1, -62, 10, -8, 64, -80, -8, -512, 64, 1, -8, 10, 1, 64, -8, 19, -53, 10, -80, -62, 496, -134, 442, 505, -134, -116, 442, 1, -8, -71, -62, -80, 10, 28, -224, -44, -134, 496, -62, -53, -44, 100, 10, 514, -62, -44, -116, 514, -44, 136, -116, 10, 1, -62, 28, 10, -62, -44, 28, -116, 442, -62, -53, 64, -512, 640, 64, 4096, -512, -8, 64, 568, 496, 640, -80, -80, -8, 496, -224, -80, 496, -512, 64, 64, -8, -8, -80, 10, -80, 100, 10, 640, -80, -62, 496, 514, 505, 568, -71, -53, -62, -44, -134, -71, 19, 64, -8, -8, 1, 1, 10 },
        { -62, 28, 10, 1, -62, 10, -71, -62, 1, -8, 10, -80, -80, -8, -8, 64, 64, -512, 10, 1, 1, -8, -8, 64, -53, -44, 100, 10, 514, -62, -44, -116, 514, -44, 136, -116, 10, 1, -62, 28, 10, -62, -44, 28, -116, 442, -62, -53, 19, -53, 10, -80, -62, 496, -134, 442, 505, -134, -116, 442, 1, -8, -71, -62, -80, 10, 28, -224, -44, -134, 496, -62, 640, 64, 64, -512, -512, 4096, -80, -8, 496, -224, -80, 496, -8, 64, 568, 496, 640, -80, 64, -512, -8, -80, 64, -8, 100, 10, 10, -80, -80, 640, -53, -62, -44, -134, -71, 19, -62, 496, 514, 505, 568, -71, -8, 64, 1, 10, -8, 1 },
        { -80, 10, 640, -80, 100, 10, 496, -62, 568, -71, 514, 505, 64, -8, -8, 1, 1, 10, -53, -62, -44, -134, -71, 19, -8, 1, 64, -8, 10, 1, -80, 10, -8, 1, -62, -71, -512, 64, 64, -8, -8, -80, -62, 10, 28, -62, 1, 10, -224, 28, 496, -62, -44, -134, 496, -62, -80, 10, -53, 19, -80, 10, -8, 1, -62, -71, -116, 442, 442, -134, -134, 505, -512, 64, 64, -8, -8, -80, 4096, -512, -512, 64, 64, 640, 640, -80, 64, -8, 496, 568, -80, 496, -8, -80, -224, 496, -44, 28, -116, 442, -62, -53, 514, -62, -44, -53, 10, 100, 136, -116, -116, -44, -44, 514, 10, -62, 1, 10, 28, -62 },
        { 10, 100, -80, 640, 10, -80, -62, -53, -71, 19, -44, -134, -8, 64, 1, 10, -8, 1, -62, 496, 514, 505, 568, -71, 1, 10, -8, 64, 1, -8, 10, -62, 1, 10, 28, -62, 64, -512, -8, -80, 64, -8, 10, -80, -62, -71, -8, 1, 28, -44, -62, -53, -116, 442, -62, 514, 10, 100, -44, -53, 10, -62, 1, 10, 28, -62, 136, -116, -116, -44, -44, 514, 64, -512, -8, -80, 64, -8, -512, 4096, 64, 640, -512, 64, -80, 496, -8, -80, -224, 496, 640, -80, 64, -8, 496, 568, 28, -224, -44, -134, 496, -62, -62, 496, -53, 19, -80, 10, -116, 442, 442, -134, -134, 505, -80, 10, -8, 1, -62, -71 },
        { 496, -62, -80, 10, -53, 19, -224, 28, 496, -62, -44, -134, -8, 1, -80, 10, -71, -62, 442, -134, -116, 442, 505, -134, -80, 10, -8, 1, -62, -71, -8, 1, 64, -8, 10, 1, 64, -8, -512, 64, -80, -8, 28, -62, -62, 10, 10, 1, 496, -62, 568, -71, 514, 505, -80, 10, 640, -80, 100, 10, -8, 1, 64, -8, 10, 1, -44, -134, -53, -62, 19, -71, 64, -8, 640, -80, 568, 496, -512, 64, 4096, -512, 640, 64, 64, -8, -512, 64, -80, -8, 496, -224, -80, -8, 496, -80, -116, -44, 136, -116, 514, -44, -44, -53, 514, -62, 100, 10, -116, 442, -44, 28, -53, -62, -62, 28, 10, 1, -62, 10 },
        { -62, 514, 10, 100, -44, -53, 28, -44, -62, -53, -116, 442, 1, 10, 10, -62, -62, 28, -116, -44, 136, -116, 514, -44, 10, -62, 1, 10, 28, -62, 1, 10, -8, 64, 1, -8, -8, -80, 64, -512, -8, 64, -62, -71, 10, -80, 1, -8, -62, -53, -71, 19, -44, -134, 10, 100, -80, 640, 10, -80, 1, 10, -8, 64, 1, -8, 514, 505, -62, 496, -71, 568, -8, -80, -80, 496, 496, -224, 64, 640, -512, 4096, 64, -512, -8, -80, 64, -512, -8, 64, 568, 496, -8, 64, -80, 640, 442, -134, -116, 442, 505, -134, -53, 19, -62, 496, 10, -80, -44, -134, 28, -224, -62, 496, -71, -62, 1, -8, 10, -80 },
        { 19, -53, 10, -80, -62, 496, -134, 442, 505, -134, -116, 442, 1, -8, -71, -62, -80, 10, 28, -224, -44, -134, 496, -62, -71, -62, 1, -8, 10, -80, -62, 28, 10, 1, -62, 10, -8, 64, -80, -8, -512, 64, 1, -8, 10, 1, 64, -8, -44, -116, 514, -44, 136, -116, -53, -44, 100, 10, 514, -62, -62, 28, 10, 1, -62, 10, -116, 442, -44, 28, -53, -62, -8, 64, 568, 496, 640, -80, 64, -512, 640, 64, 4096, -512, 496, -224, -80, -8, 496, -80, 64, -8, -512, 64, -80, -8, -62, 496, 514, 505, 568, -71, 10, -80, 100, 10, 640, -80, -44, -134, -53, -62, 19, -71, -8, 1, 64, -8, 10, 1 },
        { -53, -44, 100, 10, 514, -62, -44, -116, 514, -44, 136, -116, 10, 1, -62, 28, 10, -62, -44, 28, -116, 442, -62, -53, -62, 28, 10, 1, -62, 10, -71, -62, 1, -8, 10, -80, -80, -8, -8, 64, 64, -512, 10, 1, 1, -8, -8, 64, -134, 442, 505, -134, -116, 442, 19, -53, 10, -80, -62, 496, -71, -62, 1, -8, 10, -80, -44, -134, 28, -224, -62, 496, -80, -8, 496, -224, -80, 496, 640, 64, 64, -512, -512, 4096, 568, 496, -8, 64, -80, 640, -8, -80, 64, -512, -8, 64, -53, -62, -44, -134, -71, 19, 100, 10, 10, -80, -80, 640, 514, 505, -62, 496, -71, 568, 1, 10, -8, 64, 1, -8 },
        { 496, -62, 568, -71, 514, 505, -80, 10, 640, -80, 100, 10, -8, 1, 64, -8, 10, 1, -44, -134, -53, -62, 19, -71, -224, 28, 496, -62, -44, -134, 496, -62, -80, 10, -53, 19, -80, 10, -8, 1, -62, -71, -116, 442, 442, -134, -134, 505, -8, 1, 64, -8, 10, 1, -80, 10, -8, 1, -62, -71, -512, 64, 64, -8, -8, -80, -62, 10, 28, -62, 1, 10, 64, -8, -512, 64, -80, -8, 640, -80, 64, -8, 496, 568, 4096, -512, -512, 64, 64, 640, 496, -80, -224, 496, -8, -80, -116, 442, -44, 28, -53, -62, 136, -116, -116, -44, -44, 514, 514, -62, -44, -53, 10, 100, -62, 10, 28, -62, 1, 10 },
        { -62, -53, -71, 19, -44, -134, 10, 100, -80, 640, 10, -80, 1, 10, -8, 64, 1, -8, 514, 505, -62, 496, -71, 568, 28, -44, -62, -53, -116, 442, -62, 514, 10, 100, -44, -53, 10, -62, 1, 10, 28, -62, 136, -116, -116, -44, -44, 514, 1, 10, -8, 64, 1, -8, 10, -62, 1, 10, 28, -62, 64, -512, -8, -80, 64, -8, 10, -80, -62, -71, -8, 1, -8, -80, 64, -512, -8, 64, -80, 496, -8, -80, -224, 496, -512, 4096, 64, 640, -512, 64, -80, 640, 496, 568, 64, -8, -44, -134, 28, -224, -62, 496, -116, 442, 442, -134, -134, 505, -62, 496, -53, 19, -80, 10, 10, -80, -62, -71, -8, 1 },
        { -224, 28, 496, -62, -44, -134, 496, -62, -80, 10, -53, 19, -80, 10, -8, 1, -62, -71, -116, 442, 442, -134, -134, 505, 496, -62, 568, -71, 514, 505, -80, 10, 640, -80, 100, 10, -8, 1, 64, -8, 10, 1, -44, -134, -53, -62, 19, -71, -80, 10, -8, 1, -62, -71, -8, 1, 64, -8, 10, 1, 64, -8, -512, 64, -80, -8, 28, -62, -62, 10, 10, 1, 640, -80, 64, -8, 496, 568, 64, -8, -512, 64, -80, -8, -512, 64, 4096, -512, 640, 64, -224, 496, 496, -80, -80, -8, 136, -116, -116, -44, -44, 514, -116, 442, -44, 28, -53, -62, -44, -53, 514, -62, 100, 10, 28, -62, -62, 10, 10, 1 },
        { 28, -44, -62, -53, -116, 442, -62, 514, 10, 100, -44, -53, 10, -62, 1, 10, 28, -62, 136, -116, -116, -44, -44, 514, -62, -53, -71, 19, -44, -134, 10, 100, -80, 640, 10, -80, 1, 10, -8, 64, 1, -8, 514, 505, -62, 496, -71, 568, 10, -62, 1, 10, 28, -62, 1, 10, -8, 64, 1, -8, -8, -80, 64, -512, -8, 64, -62, -71, 10, -80, 1, -8, -80, 496, -8, -80, -224, 496, -8, -80, 64, -512, -8, 64, 64, 640, -512, 4096, 64, -512, 496, 568, -80, 640, -8, 64, -116, 442, 442, -134, -134, 505, -44, -134, 28, -224, -62, 496, -53, 19, -62, 496, 10, -80, -62, -71, 10, -80, 1, -8 },
        { -134, 442, 505, -134, -116, 442, 19, -53, 10, -80, -62, 496, -71, -62, 1, -8, 10, -80, -44, -134, 28, -224, -62, 496, -44, -116, 514, -44, 136, -116, -53, -44, 100, 10, 514, -62, -62, 28, 10, 1, -62, 10, -116, 442, -44, 28, -53, -62, -71, -62, 1, -8, 10, -80, -62, 28, 10, 1, -62, 10, -8, 64, -80, -8, -512, 64, 1, -8, 10, 1, 64, -8, 568, 496, -8, 64, -80, 640, 496, -224, -80, -8, 496, -80, 64, -512, 640, 64, 4096, -512, -8, 64, -80, -8, -512, 64, 514, 505, -62, 496, -71, 568, -44, -134, -53, -62, 19, -71, 10, -80, 100, 10, 640, -80, 1, -8, 10, 1, 64, -8 },
        { -44, -116, 514, -44, 136, -116, -53, -44, 100, 10, 514, -62, -62, 28, 10, 1, -62, 10, -116, 442, -44, 28, -53, -62, -134, 442, 505, -134, -116, 442, 19, -53, 10, -80, -62, 496, -71, -62, 1, -8, 10, -80, -44, -134, 28, -224, -62, 496, -62, 28, 10, 1, -62, 10, -71, -62, 1, -8, 10, -80, -80, -8, -8, 64, 64, -512, 10, 1, 1, -8, -8, 64, 496, -224, -80, -8, 496, -80, 568, 496, -8, 64, -80, 640, 640, 64, 64, -512, -512, 4096, -80, -8, -8, 64, 64, -512, -44, -134, -53, -62, 19, -71, 514, 505, -62, 496, -71, 568, 100, 10, 10, -80, -80, 640, 10, 1, 1, -8, -8, 64 },
        { 505, 514, -71, 568, -62, 496, -134, -44, 19, -71, -53, -62, 1, -8, 10, 1, 64, -8, 10, -80, 100, 10, 640, -80, -134, -44, -62, 496, 28, -224, 442, -116, -134, 505, 442, -134, 10, -80, -62, -71, -8, 1, -62, 496, -53, 19, -80, 10, 442, -116, -53, -62, -44, 28, -116, 136, -44, 514, -116, -44, -62, 10, 28, -62, 1, 10, 514, -62, -44, -53, 10, 100, -8, 64, -80, -8, -512, 64, -80, 640, 496, 568, 64, -8, 496, -80, -224, 496, -8, -80, 4096, -512, -512, 64, 64, 640, 1, -8, 10, 1, 64, -8, 10, -80, -62, -71, -8, 1, -62, 10, 28, -62, 1, 10, -512, 64, 64, -8, -8, -80 },
        { -134, -44, 19, -71, -53, -62, 505, 514, -71, 568, -62, 496, 10, 1, 1, -8, -8, 64, 100, 10, 10, -80, -80, 640, 442, -116, -53, -62, -44, 28, -116, 136, -44, 514, -116, -44, -62, 10, 28, -62, 1, 10, 514, -62, -44, -53, 10, 100, -134, -44, -62, 496, 28, -224, 442, -116, -134, 505, 442, -134, 10, -80, -62, -71, -8, 1, -62, 496, -53, 19, -80, 10, -80, -8, -8, 64, 64, -512, 496, -80, -224, 496, -8, -80, -80, 640, 496, 568, 64, -8, -512, 4096, 64, 640, -512, 64, 10, 1, 1, -8, -8, 64, -62, 10, 28, -62, 1, 10, 10, -80, -62, -71, -8, 1, 64, -512, -8, -80, 64, -8 },
        { -134, -44, -62, 496, 28, -224, 442, -116, -134, 505, 442, -134, 10, -80, -62, -71, -8, 1, -62, 496, -53, 19, -80, 10, 505, 514, -71, 568, -62, 496, -134, -44, 19, -71, -53, -62, 1, -8, 10, 1, 64, -8, 10, -80, 100, 10, 640, -80, -116, 136, -44, 514, -116, -44, 442, -116, -53, -62, -44, 28, 28, -62, -62, 10, 10, 1, -44, -53, 514, -62, 100, 10, -80, 640, 496, 568, 64, -8, -8, 64, -80, -8, -512, 64, -224, 496, 496, -80, -80, -8, -512, 64, 4096, -512, 640, 64, 10, -80, -62, -71, -8, 1, 1, -8, 10, 1, 64, -8, 28, -62, -62, 10, 10, 1, 64, -8, -512, 64, -80, -8 },
        { 442, -116, -53, -62, -44, 28, -116, 136, -44, 514, -116, -44, -62, 10, 28, -62, 1, 10, 514, -62, -44, -53, 10, 100, -134, -44, 19, -71, -53, -62, 505, 514, -71, 568, -62, 496, 10, 1, 1, -8, -8, 64, 100, 10, 10, -80, -80, 640, 442, -116, -134, 505, 442, -134, -134, -44, -62, 496, 28, -224, -62, -71, 10, -80, 1, -8, -53, 19, -62, 496, 10, -80, 496, -80, -224, 496, -8, -80, -80, -8, -8, 64, 64, -512, 496, 568, -80, 640, -8, 64, 64, 640, -512, 4096, 64, -512, -62, 10, 28, -62, 1, 10, 10, 1, 1, -8, -8, 64, -62, -71, 10, -80, 1, -8, -8, -80, 64, -512, -8, 64 },
        { 442, -116, -134, 505, 442, -134, -134, -44, -62, 496, 28, -224, -62, -71, 10, -80, 1, -8, -53, 19, -62, 496, 10, -80, -116, 136, -44, 514, -116, -44, 442, -116, -53, -62, -44, 28, 28, -62, -62, 10, 10, 1, -44, -53, 514, -62, 100, 10, 505, 514, -71, 568, -62, 496, -134, -44, 19, -71, -53, -62, 1, -8, 10, 1, 64, -8, 10, -80, 100, 10, 640, -80, 496, 568, -80, 640, -8, 64, -224, 496, 496, -80, -80, -8, -8, 64, -80, -8, -512, 64, 64, -512, 640, 64, 4096, -512, -62, -71, 10, -80, 1, -8, 28, -62, -62, 10, 10, 1, 1, -8, 10, 1, 64, -8, -8, 64, -80, -8, -512, 64 },
        { -116, 136, -44, 514, -116, -44, 442, -116, -53, -62, -44, 28, 28, -62, -62, 10, 10, 1, -44, -53, 514, -62, 100, 10, 442, -116, -134, 505, 442, -134, -134, -44, -62, 496, 28, -224, -62, -71, 10, -80, 1, -8, -53, 19, -62, 496, 10, -80, -134, -44, 19, -71, -53, -62, 505, 514, -71, 568, -62, 496, 10, 1, 1, -8, -8, 64, 100, 10, 10, -80, -80, 640, -224, 496, 496, -80, -80, -8, 496, 568, -80, 640, -8, 64, -80, -8, -8, 64, 64, -512, 640, 64, 64, -512, -512, 4096, 28, -62, -62, 10, 10, 1, -62, -71, 10, -80, 1, -8, 10, 1, 1, -8, -8, 64, -80, -8, -8, 64, 64, -512 },
        { 1, -8, 10, 1, 64, -8, 10, -80, -62, -71, -8, 1, -62, 10, 28, -62, 1, 10, -512, 64, 64, -8, -8, -80, 10, -80, 100, 10, 640, -80, -62, 496, 514, 505, 568, -71, -53, -62, -44, -134, -71, 19, 64, -8, -8, 1, 1, 10, -62, 496, -53, 19, -80, 10, 28, -224, -44, -134, 496, -62, 442, -134, -116, 442, 505, -134, -8, 1, -80, 10, -71, -62, 514, -62, -44, -53, 10, 100, -44, 28, -116, 442, -62, -53, -116, -44, 136, -116, 514, -44, 1, 10, 10, -62, -62, 28, 4096, -512, -512, 64, 64, 640, -512, 64, 64, -8, -8, -80, 64, -8, 640, -80, 568, 496, -8, -80, -80, 496, 496, -224 },
        { 10, 1, 1, -8, -8, 64, -62, 10, 28, -62, 1, 10, 10, -80, -62, -71, -8, 1, 64, -512, -8, -80, 64, -8, 100, 10, 10, -80, -80, 640, -53, -62, -44, -134, -71, 19, -62, 496, 514, 505, 568, -71, -8, 64, 1, 10, -8, 1, 514, -62, -44, -53, 10, 100, -44, 28, -116, 442, -62, -53, -116, -44, 136, -116, 514, -44, 1, 10, 10, -62, -62, 28, -62, 496, -53, 19, -80, 10, 28, -224, -44, -134, 496, -62, 442, -134, -116, 442, 505, -134, -8, 1, -80, 10, -71, -62, -512, 4096, 64, 640, -512, 64, 64, -512, -8, -80, 64, -8, -8, -80, -80, 496, 496, -224, 64, -8, 640, -80, 568, 496 },
        { 10, -80, -62, -71, -8, 1, 1, -8, 10, 1, 64, -8, 28, -62, -62, 10, 10, 1, 64, -8, -512, 64, -80, -8, -62, 496, -53, 19, -80, 10, 28, -224, -44, -134, 496, -62, 442, -134, -116, 442, 505, -134, -8, 1, -80, 10, -71, -62, 10, -80, 100, 10, 640, -80, -62, 496, 514, 505, 568, -71, -53, -62, -44, -134, -71, 19, 64, -8, -8, 1, 1, 10, -44, -53, 514, -62, 100, 10, -116, -44, 136, -116, 514, -44, -44, 28, -116, 442, -62, -53, 10, 1, -62, 28, 10, -62, -512, 64, 4096, -512, 640, 64, 64, -8, 640, -80, 568, 496, -512, 64, 64, -8, -8, -80, -80, -8, 496, -224, -80, 496 },
        { -62, 10, 28, -62, 1, 10, 10, 1, 1, -8, -8, 64, -62, -71, 10, -80, 1, -8, -8, -80, 64, -512, -8, 64, 514, -62, -44, -53, 10, 100, -44, 28, -116, 442, -62, -53, -116, -44, 136, -116, 514, -44, 1, 10, 10, -62, -62, 28, 100, 10, 10, -80, -80, 640, -53, -62, -44, -134, -71, 19, -62, 496, 514, 505, 568, -71, -8, 64, 1, 10, -8, 1, -53, 19, -62, 496, 10, -80, 442, -134, -116, 442, 505, -134, 28, -224, -44, -134, 496, -62, 1, -8, -71, -62, -80, 10, 64, 640, -512, 4096, 64, -512, -8, -80, -80, 496, 496, -224, 64, -512, -8, -80, 64, -8, -8, 64, 568, 496, 640, -80 },
        { -62, -71, 10, -80, 1, -8, 28, -62, -62, 10, 10, 1, 1, -8, 10, 1, 64, -8, -8, 64, -80, -8, -512, 64, -53, 19, -62, 496, 10, -80, 442, -134, -116, 442, 505, -134, 28, -224, -44, -134, 496, -62, 1, -8, -71, -62, -80, 10, -44, -53, 514, -62, 100, 10, -116, -44, 136, -116, 514, -44, -44, 28, -116, 442, -62, -53, 10, 1, -62, 28, 10, -62, 10, -80, 100, 10, 640, -80, -62, 496, 514, 505, 568, -71, -53, -62, -44, -134, -71, 19, 64, -8, -8, 1, 1, 10, 64, -512, 640, 64, 4096, -512, -8, 64, 568, 496, 640, -80, -80, -8, 496, -224, -80, 496, -512, 64, 64, -8, -8, -80 },
        { 28, -62, -62, 10, 10, 1, -62, -71, 10, -80, 1, -8, 10, 1, 1, -8, -8, 64, -80, -8, -8, 64, 64, -512, -44, -53, 514, -62, 100, 10, -116, -44, 136, -116, 514, -44, -44, 28, -116, 442, -62, -53, 10, 1, -62, 28, 10, -62, -53, 19, -62, 496, 10, -80, 442, -134, -116, 442, 505, -134, 28, -224, -44, -134, 496, -62, 1, -8, -71, -62, -80, 10, 100, 10, 10, -80, -80, 640, -53, -62, -44, -134, -71, 19, -62, 496, 514, 505, 568, -71, -8, 64, 1, 10, -8, 1, 640, 64, 64, -512, -512, 4096, -80, -8, 496, -224, -80, 496, -8, 64, 568, 496, 640, -80, 64, -512, -8, -80, 64, -8 },
        { 10, -80, 100, 10, 640, -80, -62, 496, 514, 505, 568, -71, -53, -62, -44, -134, -71, 19, 64, -8, -8, 1, 1, 10, 1, -8, 10, 1, 64, -8, 10, -80, -62, -71, -8, 1, -62, 10, 28, -62, 1, 10, -512, 64, 64, -8, -8, -80, 28, -224, -44, -134, 496, -62, -62, 496, -53, 19, -80, 10, -116, 442, 442, -134, -134, 505, -80, 10, -8, 1, -62, -71, -44, 28, -116, 442, -62, -53, 514, -62, -44, -53, 10, 100, 136, -116, -116, -44, -44, 514, 10, -62, 1, 10, 28, -62, -512, 64, 64, -8, -8, -80, 4096, -512, -512, 64, 64, 640, 640, -80, 64, -8, 496, 568, -80, 496, -8, -80, -224, 496 },
        { 100, 10, 10, -80, -80, 640, -53, -62, -44, -134, -71, 19, -62, 496, 514, 505, 568, -71, -8, 64, 1, 10, -8, 1, 10, 1, 1, -8, -8, 64, -62, 10, 28, -62, 1, 10, 10, -80, -62, -71, -8, 1, 64, -512, -8, -80, 64, -8, -44, 28, -116, 442, -62, -53, 514, -62, -44, -53, 10, 100, 136, -116, -116, -44, -44, 514, 10, -62, 1, 10, 28, -62, 28, -224, -44, -134, 496, -62, -62, 496, -53, 19, -80, 10, -116, 442, 442, -134, -134, 505, -80, 10, -8, 1, -62, -71, 64, -512, -8, -80, 64, -8, -512, 4096, 64, 640, -512, 64, -80, 496, -8, -80, -224, 496, 640, -80, 64, -8, 496, 568 },
        { -62, 496, -53, 19, -80, 10, 28, -224, -44, -134, 496, -62, 442, -134, -116, 442, 505, -134, -8, 1, -80, 10, -71, -62, 10, -80, -62, -71, -8, 1, 1, -8, 10, 1, 64, -8, 28, -62, -62, 10, 10, 1, 64, -8, -512, 64, -80, -8, -62, 496, 514, 505, 568, -71, 10, -80, 100, 10, 640, -80, -44, -134, -53, -62, 19, -71, -8, 1, 64, -8, 10, 1, -116, -44, 136, -116, 514, -44, -44, -53, 514, -62, 100, 10, -116, 442, -44, 28, -53, -62, -62, 28, 10, 1, -62, 10, 64, -8, 640, -80, 568, 496, -512, 64, 4096, -512, 640, 64, 64, -8, -512, 64, -80, -8, 496, -224, -80, -8, 496, -80 },
        { 514, -62, -44, -53, 10, 100, -44, 28, -116, 442, -62, -53, -116, -44, 136, -116, 514, -44, 1, 10, 10, -62, -62, 28, -62, 10, 28, -62, 1, 10, 10, 1, 1, -8, -8, 64, -62, -71, 10, -80, 1, -8, -8, -80, 64, -512, -8, 64, -53, -62, -44, -134, -71, 19, 100, 10, 10, -80, -80, 640, 514, 505, -62, 496, -71, 568, 1, 10, -8, 64, 1, -8, 442, -134, -116, 442, 505, -134, -53, 19, -62, 496, 10, -80, -44, -134, 28, -224, -62, 496, -71, -62, 1, -8, 10, -80, -8, -80, -80, 496, 496, -224, 64, 640, -512, 4096, 64, -512, -8, -80, 64, -512, -8, 64, 568, 496, -8, 64, -80, 640 },
        { -53, 19, -62, 496, 10, -80, 442, -134, -116, 442, 505, -134, 28, -224, -44, -134, 496, -62, 1, -8, -71, -62, -80, 10, -62, -71, 10, -80, 1, -8, 28, -62, -62, 10, 10, 1, 1, -8, 10, 1, 64, -8, -8, 64, -80, -8, -512, 64, -116, -44, 136, -116, 514, -44, -44, -53, 514, -62, 100, 10, -116, 442, -44, 28, -53, -62, -62, 28, 10, 1, -62, 10, -62, 496, 514, 505, 568, -71, 10, -80, 100, 10, 640, -80, -44, -134, -53, -62, 19, -71, -8, 1, 64, -8, 10, 1, -8, 64, 568, 496, 640, -80, 64, -512, 640, 64, 4096, -512, 496, -224, -80, -8, 496, -80, 64, -8, -512, 64, -80, -8 },
        { -44, -53, 514, -62, 100, 10, -116, -44, 136, -116, 514, -44, -44, 28, -116, 442, -62, -53, 10, 1, -62, 28, 10, -62, 28, -62, -62, 10, 10, 1, -62, -71, 10, -80, 1, -8, 10, 1, 1, -8, -8, 64, -80, -8, -8, 64, 64, -512, 442, -134, -116, 442, 505, -134, -53, 19, -62, 496, 10, -80, -44, -134, 28, -224, -62, 496, -71, -62, 1, -8, 10, -80, -53, -62, -44, -134, -71, 19, 100, 10, 10, -80, -80, 640, 514, 505, -62, 496, -71, 568, 1, 10, -8, 64, 1, -8, -80, -8, 496, -224, -80, 496, 640, 64, 64, -512, -512, 4096, 568, 496, -8, 64, -80, 640, -8, -80, 64, -512, -8, 64 },
        { -62, 496, 514, 505, 568, -71, 10, -80, 100, 10, 640, -80, -44, -134, -53, -62, 19, -71, -8, 1, 64, -8, 10, 1, 28, -224, -44, -134, 496, -62, -62, 496, -53, 19, -80, 10, -116, 442, 442, -134, -134, 505, -80, 10, -8, 1, -62, -71, 1, -8, 10, 1, 64, -8, 10, -80, -62, -71, -8, 1, -62, 10, 28, -62, 1, 10, -512, 64, 64, -8, -8, -80, -116, 442, -44, 28, -53, -62, 136, -116, -116, -44, -44, 514, 514, -62, -44, -53, 10, 100, -62, 10, 28, -62, 1, 10, 64, -8, -512, 64, -80, -8, 640, -80, 64, -8, 496, 568, 4096, -512, -512, 64, 64, 640, 496, -80, -224, 496, -8, -80 },
        { -53, -62, -44, -134, -71, 19, 100, 10, 10, -80, -80, 640, 514, 505, -62, 496, -71, 568, 1, 10, -8, 64, 1, -8, -44, 28, -116, 442, -62, -53, 514, -62, -44, -53, 10, 100, 136, -116, -116, -44, -44, 514, 10, -62, 1, 10, 28, -62, 10, 1, 1, -8, -8, 64, -62, 10, 28, -62, 1, 10, 10, -80, -62, -71, -8, 1, 64, -512, -8, -80, 64, -8, -44, -134, 28, -224, -62, 496, -116, 442, 442, -134, -134, 505, -62, 496, -53, 19, -80, 10, 10, -80, -62, -71, -8, 1, -8, -80, 64, -512, -8, 64, -80, 496, -8, -80, -224, 496, -512, 4096, 64, 640, -512, 64, -80, 640, 496, 568, 64, -8 },
        { 28, -224, -44, -134, 496, -62, -62, 496, -53, 19, -80, 10, -116, 442, 442, -134, -134, 505, -80, 10, -8, 1, -62, -71, -62, 496, 514, 505, 568, -71, 10, -80, 100, 10, 640, -80, -44, -134, -53, -62, 19, -71, -8, 1, 64, -8, 10, 1, 10, -80, -62, -71, -8, 1, 1, -8, 10, 1, 64, -8, 28, -62, -62, 10, 10, 1, 64, -8, -512, 64, -80, -8, 136, -116, -116, -44, -44, 514, -116, 442, -44, 28, -53, -62, -44, -53, 514, -62, 100, 10, 28, -62, -62, 10, 10, 1, 640, -80, 64, -8, 496, 568, 64, -8, -512, 64, -80, -8, -512, 64, 4096, -512, 640, 64, -224, 496, 496, -80, -80, -8 },
        { -44, 28, -116, 442, -62, -53, 514, -62, -44, -53, 10, 100, 136, -116, -116, -44, -44, 514, 10, -62, 1, 10, 28, -62, -53, -62, -44, -134, -71, 19, 100, 10, 10, -80, -80, 640, 514, 505, -62, 496, -71, 568, 1, 10, -8, 64, 1, -8, -62, 10, 28, -62, 1, 10, 10, 1, 1, -8, -8, 64, -62, -71, 10, -80, 1, -8, -8, -80, 64, -512, -8, 64, -116, 442, 442, -134, -134, 505, -44, -134, 28, -224, -62, 496, -53, 19, -62, 496, 10, -80, -62, -71, 10, -80, 1, -8, -80, 496, -8, -80, -224, 496, -8, -80, 64, -512, -8, 64, 64, 640, -512, 4096, 64, -512, 496, 568, -80, 640, -8, 64 },
        { 442, -134, -116, 442, 505, -134, -53, 19, -62, 496, 10, -80, -44, -134, 28, -224, -62, 496, -71, -62, 1, -8, 10, -80, -116, -44, 136, -116, 514, -44, -44, -53, 514, -62, 100, 10, -116, 442, -44, 28, -53, -62, -62, 28, 10, 1, -62, 10, -62, -71, 10, -80, 1, -8, 28, -62, -62, 10, 10, 1, 1, -8, 10, 1, 64, -8, -8, 64, -80, -8, -512, 64, 514, 505, -62, 496, -71, 568, -44, -134, -53, -62, 19, -71, 10, -80, 100, 10, 640, -80, 1, -8, 10, 1, 64, -8, 568, 496, -8, 64, -80, 640, 496, -224, -80, -8, 496, -80, 64, -512, 640, 64, 4096, -512, -8, 64, -80, -8, -512, 64 },
        { -116, -44, 136, -116, 514, -44, -44, -53, 514, -62, 100, 10, -116, 442, -44, 28, -53, -62, -62, 28, 10, 1, -62, 10, 442, -134, -116, 442, 505, -134, -53, 19, -62, 496, 10, -80, -44, -134, 28, -224, -62, 496, -71, -62, 1, -8, 10, -80, 28, -62, -62, 10, 10, 1, -62, -71, 10, -80, 1, -8, 10, 1, 1, -8, -8, 64, -80, -8, -8, 64, 64, -512, -44, -134, -53, -62, 19, -71, 514, 505, -62, 496, -71, 568, 100, 10, 10, -80, -80, 640, 10, 1, 1, -8, -8, 64, 496, -224, -80, -8, 496, -80, 568, 496, -8, 64, -80, 640, 640, 64, 64, -512, -512, 4096, -80, -8, -8, 64, 64, -512 },
        { 514, 505, -62, 496, -71, 568, -44, -134, -53, -62, 19, -71, 10, -80, 100, 10, 640, -80, 1, -8, 10, 1, 64, -8, -44, -134, 28, -224, -62, 496, -116, 442, 442, -134, -134, 505, -62, 496, -53, 19, -80, 10, 10, -80, -62, -71, -8, 1, -116, 442, -44, 28, -53, -62, 136, -116, -116, -44, -44, 514, 514, -62, -44, -53, 10, 100, -62, 10, 28, -62, 1, 10, 1, -8, 10, 1, 64, -8, 10, -80, -62, -71, -8, 1, -62, 10, 28, -62, 1, 10, -512, 64, 64, -8, -8, -80, -8, 64, -80, -8, -512, 64, -80, 640, 496, 568, 64, -8, 496, -80, -224, 496, -8, -80, 4096, -512, -512, 64, 64, 640 },
        { -44, -134, -53, -62, 19, -71, 514, 505, -62, 496, -71, 568, 100, 10, 10, -80, -80, 640, 10, 1, 1, -8, -8, 64, -116, 442, -44, 28, -53, -62, 136, -116, -116, -44, -44, 514, 514, -62, -44, -53, 10, 100, -62, 10, 28, -62, 1, 10, -44, -134, 28, -224, -62, 496, -116, 442, 442, -134, -134, 505, -62, 496, -53, 19, -80, 10, 10, -80, -62, -71, -8, 1, 10, 1, 1, -8, -8, 64, -62, 10, 28, -62, 1, 10, 10, -80, -62, -71, -8, 1, 64, -512, -8, -80, 64, -8, -80, -8, -8, 64, 64, -512, 496, -80, -224, 496, -8, -80, -80, 640, 496, 568, 64, -8, -512, 4096, 64, 640, -512, 64 },
        { -44, -134, 28, -224, -62, 496, -116, 442, 442, -134, -134, 505, -62, 496, -53, 19, -80, 10, 10, -80, -62, -71, -8, 1, 514, 505, -62, 496, -71, 568, -44, -134, -53, -62, 19, -71, 10, -80, 100, 10, 640, -80, 1, -8, 10, 1, 64, -8, 136, -116, -116, -44, -44, 514, -116, 442, -44, 28, -53, -62, -44, -53, 514, -62, 100, 10, 28, -62, -62, 10, 10, 1, 10, -80, -62, -71, -8, 1, 1, -8, 10, 1, 64, -8, 28, -62, -62, 10, 10, 1, 64, -8, -512, 64, -80, -8, -80, 640, 496, 568, 64, -8, -8, 64, -80, -8, -512, 64, -224, 496, 496, -80, -80, -8, -512, 64, 4096, -512, 640, 64 },
        { -116, 442, -44, 28, -53, -62, 136, -116, -116, -44, -44, 514, 514, -62, -44, -53, 10, 100, -62, 10, 28, -62, 1, 10, -44, -134, -53, -62, 19, -71, 514, 505, -62, 496, -71, 568, 100, 10, 10, -80, -80, 640, 10, 1, 1, -8, -8, 64, -116, 442, 442, -134, -134, 505, -44, -134, 28, -224, -62, 496, -53, 19, -62, 496, 10, -80, -62, -71, 10, -80, 1, -8, -62, 10, 28, -62, 1, 10, 10, 1, 1, -8, -8, 64, -62, -71, 10, -80, 1, -8, -8, -80, 64, -512, -8, 64, 496, -80, -224, 496, -8, -80, -80, -8, -8, 64, 64, -512, 496, 568, -80, 640, -8, 64, 64, 640, -512, 4096, 64, -512 },
        { -116, 442, 442, -134, -134, 505, -44, -134, 28, -224, -62, 496, -53, 19, -62, 496, 10, -80, -62, -71, 10, -80, 1, -8, 136, -116, -116, -44, -44, 514, -116, 442, -44, 28, -53, -62, -44, -53, 514, -62, 100, 10, 28, -62, -62, 10, 10, 1, 514, 505, -62, 496, -71, 568, -44, -134, -53, -62, 19, -71, 10, -80, 100, 10, 640, -80, 1, -8, 10, 1, 64, -8, -62, -71, 10, -80, 1, -8, 28, -62, -62, 10, 10, 1, 1, -8, 10, 1, 64, -8, -8, 64, -80, -8, -512, 64, 496, 568, -80, 640, -8, 64, -224, 496, 496, -80, -80, -8, -8, 64, -80, -8, -512, 64, 64, -512, 640, 64, 4096, -512 },
        { 136, -116, -116, -44, -44, 514, -116, 442, -44, 28, -53, -62, -44, -53, 514, -62, 100, 10, 28, -62, -62, 10, 10, 1, -116, 442, 442, -134, -134, 505, -44, -134, 28, -224, -62, 496, -53, 19, -62, 496, 10, -80, -62, -71, 10, -80, 1, -8, -44, -134, -53, -62, 19, -71, 514, 505, -62, 496, -71, 568, 100, 10, 10, -80, -80, 640, 10, 1, 1, -8, -8, 64, 28, -62, -62, 10, 10, 1, -62, -71, 10, -80, 1, -8, 10, 1, 1, -8, -8, 64, -80, -8, -8, 64, 64, -512, -224, 496, 496, -80, -80, -8, 496, 568, -80, 640, -8, 64, -80, -8, -8, 64, 64, -512, 640, 64, 64, -512, -512, 4096 } }; // 2-D array[120][120]

  // Sum and square the color flows to get the matrix element
  // (compute |M|^2 by squaring |M|, taking into account colours)
  fptype deltaMEs = { 0 }; // all zeros
  for( int icol = 0; icol < ncolor; icol++ )
  {
    cxtype ztemp = cxmake( 0, 0 );
    for( int jcol = 0; jcol < ncolor; jcol++ )
      ztemp += cf[icol][jcol] * jamp[jcol];
    deltaMEs += cxreal( ztemp * cxconj( jamp[icol] ) ) / denom[icol];
  }

  // *** STORE THE RESULTS ***

  // Store the leading color flows for choice of color
  // (NB: jamp2 must be an array of fptype)
  // for( int icol = 0; icol < ncolor; icol++ )
  // jamp2[0][icol] += cxreal( jamp[icol]*cxconj( jamp[icol] ) );

  // NB: calculate_wavefunctions ADDS |M|^2 for a given ihel to the running sum of |M|^2 over helicities for the given event(s)
  // FIXME: assume process.nprocesses == 1 for the moment (eventually: need a loop over processes here?)
  allMEs += deltaMEs;
  //printf( "calculate_wavefunction: %6d %2d %f\n", ievt, ihel, allMEs[ievt] );


  return allMEs;
}

//--------------------------------------------------------------------------

CPPProcess::CPPProcess(
    bool verbose, bool debug): 
      m_verbose(verbose),m_debug(debug),
      m_cIPC("cIPC",independentCouplings::nicoup), m_hIPC("hIPC",independentCouplings::nicoup), 
      m_cIPD("cIPD",mgOnGpu::nparams), m_hIPD("hIPD",mgOnGpu::nparams)
{}

//--------------------------------------------------------------------------

// Initialize process (with parameters read from user cards)
void CPPProcess::initProc( const std::string& param_card_name )
{
  // Instantiate the model class and set parameters that stay fixed during run
  m_pars = Parameters_sm::getInstance();
  SLHAReader slha( param_card_name, m_verbose );
  m_pars->setIndependentParameters( slha );
  m_pars->setIndependentCouplings();
  //m_pars->setDependentParameters();
  //m_pars->setDependentCouplings();
  if ( m_verbose )
  {
    m_pars->printIndependentParameters();
    m_pars->printIndependentCouplings();
    //m_pars->printDependentParameters();
    //m_pars->printDependentCouplings();
  }
  // Set external particle masses for this matrix element
  m_masses.push_back( m_pars->ZERO );
  m_masses.push_back( m_pars->ZERO );
  m_masses.push_back( m_pars->mdl_MT );
  m_masses.push_back( m_pars->mdl_MT );
  m_masses.push_back( m_pars->ZERO );
  m_masses.push_back( m_pars->ZERO );
  m_masses.push_back( m_pars->ZERO );
  // Read physics parameters like masses and couplings from user configuration files (static: initialize once)
  //m_tIPC[...] = ... ; // nicoup=0
  m_hIPD[0] = (fptype)m_pars->mdl_MT;
  m_hIPD[1] = (fptype)m_pars->mdl_WT;
  Kokkos::deep_copy(m_cIPD,m_hIPD);

}

//--------------------------------------------------------------------------
template <typename mom_t, typename igh_t, typename ngh_t, 
          typename gs_t, typename idc_t, typename idp_t>
void sigmaKin_setup(
    const mom_t& momenta,
    const igh_t& iGoodHel,
    const ngh_t& nGoodHel,
    const gs_t& Gs,
    const idc_t& indep_couplings,
    const idp_t& cIPD,
    const int& league_size,
    const int& team_size)
{
  Kokkos::View<int*,Kokkos::DefaultExecutionSpace> isGoodHel("isGoodHel",mgOnGpu::ncomb); // has to be constant index, but should be `ncomb`

  using member_type = typename Kokkos::TeamPolicy<Kokkos::DefaultExecutionSpace>::member_type;
  Kokkos::TeamPolicy<Kokkos::DefaultExecutionSpace> policy( league_size, team_size );
  Kokkos::parallel_for(__func__,policy, 
  KOKKOS_LAMBDA(const member_type& team_member){
    const int ievt = team_member.league_rank() * team_member.team_size() + team_member.team_rank();

    // Load helicities into local (private) memory
    auto cHel = helicities<short>;
    cxtype cIPC[dependentCouplings::ndcoup + independentCouplings::nicoup];

#if MGONGPU_NDCOUP > 0
    dependentCouplings::set_couplings_from_G(cIPC, Gs[ievt]); 
#endif

#if MGONGPU_NICOUP > 0
    for (size_t i = 0; i < independentCouplings::nicoup; i++) {
        cIPC[dependentCouplings::ndcoup + i] = indep_couplings[i];
    }
#endif


    auto local_mom = Kokkos::subview(momenta,ievt,Kokkos::ALL,Kokkos::ALL);
    for (int ihel = 0;ihel < mgOnGpu::ncomb;++ihel)
    {
      auto local_cHel = cHel[ihel];
      #ifdef MGONGPU_SUPPORTS_MULTICHANNEL
          constexpr unsigned int channelId = 0; // disable single-diagram channel enhancement
          fptype all_numerators = 0.0;
          fptype all_denominators = 0.0;
          auto allMEs = calculate_wavefunctions(local_mom, &all_numerators, &all_denominators, channelId, local_cHel, cIPC, cIPD);
      #else
          auto allMEs = calculate_wavefunctions(local_mom, local_cHel, cIPC, cIPD);
      #endif

      if (allMEs != 0)
      {
        isGoodHel(ihel) = true;
      }
    }
  });

  Kokkos::parallel_for(__func__,Kokkos::RangePolicy<Kokkos::DefaultExecutionSpace>(0,1),
  KOKKOS_LAMBDA(const int& i){
    for(int ihel=0;ihel < mgOnGpu::ncomb;++ihel){

      if(isGoodHel(ihel)){
        iGoodHel(nGoodHel(0)) = ihel;
        nGoodHel(0)++;
      }

    }
  });
}


//--------------------------------------------------------------------------
// Evaluate |M|^2, part independent of incoming flavour.
template <typename mom_t, typename igh_t, typename ngh_t, 
          typename gs_t, typename idc_t, typename idp_t,
          typename out_t>
void sigmaKin(
    const mom_t& momenta,
#ifdef MGONGPU_SUPPORTS_MULTICHANNEL
    const unsigned int channelId,          // input: multichannel channel id (1 to #diagrams); 0 to disable channel enhancement
#endif
    const igh_t& iGoodHel,
    const ngh_t& nGoodHel,
    const gs_t& Gs,
    const idc_t& indep_couplings,
    const idp_t& cIPD,
    const int& league_size,
    const int& team_size,
    const out_t& allMEs)
{
  using member_type = typename Kokkos::TeamPolicy<Kokkos::DefaultExecutionSpace>::member_type;
  Kokkos::TeamPolicy<Kokkos::DefaultExecutionSpace> policy( league_size, team_size );
  Kokkos::parallel_for(__func__,policy, 
  KOKKOS_LAMBDA(const member_type& team_member){

    const int ievt = team_member.league_rank() * team_member.team_size() + team_member.team_rank();
    
    
    // Denominators: spins, colors and identical particles
    constexpr int denominators = 1536; // FIXME: assume process.nprocesses == 1 for the moment (eventually denominators[nprocesses]?)

    // Load helicities into local (private) memory
    auto cHel = helicities<short>;
    cxtype cIPC[dependentCouplings::ndcoup + independentCouplings::nicoup];

#if MGONGPU_NDCOUP > 0
    dependentCouplings::set_couplings_from_G(cIPC, Gs[ievt]); 
#endif

#if MGONGPU_NICOUP > 0
    for (size_t i = 0; i < independentCouplings::nicoup; i++) {
        cIPC[dependentCouplings::ndcoup + i] = indep_couplings[i];
    }
#endif

    allMEs[ievt] = 0;
#ifdef MGONGPU_SUPPORTS_MULTICHANNEL
    fptype allNumerators = 0;
    fptype allDenominators = 0;
#endif

    // PART 1 - HELICITY LOOP: CALCULATE WAVEFUNCTIONS
    // (in both CUDA and C++, using precomputed good helicities)
    // FIXME: assume process.nprocesses == 1 for the moment (eventually: need a loop over processes here?)
    auto local_mom = Kokkos::subview(momenta,ievt,Kokkos::ALL,Kokkos::ALL);
    for (int ighel = 0;ighel < nGoodHel(0);++ighel)
    {
      auto local_cHel = cHel[iGoodHel(ighel)];
#ifdef MGONGPU_SUPPORTS_MULTICHANNEL
      allMEs[ievt] += calculate_wavefunctions(local_mom, &allNumerators, &allDenominators, channelId, local_cHel, cIPC, cIPD);
#else
      allMEs[ievt] += calculate_wavefunctions(local_mom, local_cHel, cIPC, cIPD);
#endif
    }
    // PART 2 - FINALISATION (after calculate_wavefunctions)
    // Get the final |M|^2 as an average over helicities/colors of the running sum of |M|^2 over helicities for the given event
    // [NB 'sum over final spins, average over initial spins', eg see
    // https://www.uzh.ch/cmsssl/physik/dam/jcr:2e24b7b1-f4d7-4160-817e-47b13dbf1d7c/Handout_4_2016-UZH.pdf]
    // FIXME: assume process.nprocesses == 1 for the moment (eventually: need a loop over processes here?)
    
#ifdef MGONGPU_SUPPORTS_MULTICHANNEL
    if( channelId > 0 ) allMEs[ievt] *= allNumerators / allDenominators; // FIXME (#343): assume nprocesses == 1
#endif
    allMEs[ievt] /= (fptype)denominators;

  });// end parallel for

}


//==========================================================================
// Private class member functions

//--------------------------------------------------------------------------


