#include "BridgeKernels.h"
#include "MemoryAccessMomenta.h"

#include <sstream>

using mgOnGpu::npar;  // the number of particles (external = initial + final)
using mgOnGpu::np4;   // the number of dimensions of 4-momenta (E,px,py,pz)

//============================================================================

#ifdef __CUDACC__
namespace mg5amcGpu
#else
namespace mg5amcCpu
#endif
{

  //--------------------------------------------------------------------------

  BridgeKernelBase::BridgeKernelBase( const BufferMomenta& momenta,         // input: momenta
                                      BufferMatrixElements& matrixElements, // output: matrix elements
                                      const size_t nevt )
    : MatrixElementKernelBase( momenta, matrixElements )
    , NumberOfEvents( nevt )
    , m_bridge( nevt, npar, np4, MemoryAccessMomenta::neppM, mgOnGpu::ncomb )
  {
    if ( m_momenta.isOnDevice() ) throw std::runtime_error( "BridgeKernelBase: momenta must be a host array" );
    if ( m_matrixElements.isOnDevice() ) throw std::runtime_error( "BridgeKernelBase: matrixElements must be a host array" );
    if ( this->nevt() != m_momenta.nevt() ) throw std::runtime_error( "BridgeKernelBase: nevt mismatch with momenta" );
    if ( this->nevt() != m_matrixElements.nevt() ) throw std::runtime_error( "BridgeKernelBase: nevt mismatch with matrixElements" );
  }

  //--------------------------------------------------------------------------

}

//============================================================================

#ifndef __CUDACC__
namespace mg5amcCpu
{  

  //--------------------------------------------------------------------------

  BridgeKernelHost::BridgeKernelHost( const BufferMomenta& momenta,         // input: momenta
                                      BufferMatrixElements& matrixElements, // output: matrix elements
                                      const size_t nevt )
    : BridgeKernelBase( momenta, matrixElements, nevt )
    , m_fortranMomenta( nevt )
  {
  }

  //--------------------------------------------------------------------------

  void BridgeKernelHost::computeGoodHelicities()
  {
    hst_transposeMomentaC2F( m_momenta.data(), m_fortranMomenta.data(), nevt(), npar, np4, MemoryAccessMomenta::neppM );
    constexpr bool goodHelOnly=true;
    m_bridge.cpu_sequence( m_fortranMomenta.data(), m_matrixElements.data(), goodHelOnly );
  }

  //--------------------------------------------------------------------------

  void BridgeKernelHost::computeMatrixElements()
  {
    hst_transposeMomentaC2F( m_momenta.data(), m_fortranMomenta.data(), nevt(), npar, np4, MemoryAccessMomenta::neppM );
    constexpr bool goodHelOnly=false;
    m_bridge.cpu_sequence( m_fortranMomenta.data(), m_matrixElements.data(), goodHelOnly );
  }

  //--------------------------------------------------------------------------

}
#endif

//============================================================================

#ifdef __CUDACC__
namespace mg5amcGpu
{

  //--------------------------------------------------------------------------

  BridgeKernelDevice::BridgeKernelDevice( const BufferMomenta& momenta,         // input: momenta
                                          BufferMatrixElements& matrixElements, // output: matrix elements
                                          const size_t gpublocks,
                                          const size_t gputhreads )
    : BridgeKernelBase( momenta, matrixElements, gpublocks*gputhreads )
    , m_fortranMomenta( nevt() )
    , m_gpublocks( gpublocks )
    , m_gputhreads( gputhreads )
  {
    if ( m_gpublocks == 0 ) throw std::runtime_error( "BridgeKernelDevice: gpublocks must be > 0" );
    if ( m_gputhreads == 0 ) throw std::runtime_error( "BridgeKernelDevice: gputhreads must be > 0" );
    m_bridge.set_gpugrid( gpublocks, gputhreads );
  }

  //--------------------------------------------------------------------------

  void BridgeKernelDevice::computeGoodHelicities()
  {
    hst_transposeMomentaC2F( m_momenta.data(), m_fortranMomenta.data(), nevt(), npar, np4, MemoryAccessMomenta::neppM );
    constexpr bool goodHelOnly=true;
    m_bridge.gpu_sequence( m_fortranMomenta.data(), m_matrixElements.data(), goodHelOnly );
  }

  //--------------------------------------------------------------------------

  void BridgeKernelDevice::computeMatrixElements()
  {
    hst_transposeMomentaC2F( m_momenta.data(), m_fortranMomenta.data(), nevt(), npar, np4, MemoryAccessMomenta::neppM );
    constexpr bool goodHelOnly=false;
    m_bridge.gpu_sequence( m_fortranMomenta.data(), m_matrixElements.data(), goodHelOnly );
  }

  //--------------------------------------------------------------------------

}
#endif

//============================================================================
