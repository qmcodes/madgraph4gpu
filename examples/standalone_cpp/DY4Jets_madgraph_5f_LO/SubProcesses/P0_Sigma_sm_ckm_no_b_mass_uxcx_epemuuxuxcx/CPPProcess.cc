//==========================================================================
// This file has been automatically generated for C++ Standalone by
// MadGraph5_aMC@NLO v. 2.7.0, 2020-01-20
// By the MadGraph5_aMC@NLO Development Team
// Visit launchpad.net/madgraph5 and amcatnlo.web.cern.ch
//==========================================================================

#include "CPPProcess.h"
#include "HelAmps_sm_ckm_no_b_mass.h"

using namespace MG5_sm_ckm_no_b_mass; 

//==========================================================================
// Class member functions for calculating the matrix elements for
// Process: u~ c~ > e+ e- u u~ u~ c~ WEIGHTED<=8 / h
// Process: u~ c~ > mu+ mu- u u~ u~ c~ WEIGHTED<=8 / h

//--------------------------------------------------------------------------
// Initialize process.

void CPPProcess::initProc(string param_card_name) 
{
  // Instantiate the model class and set parameters that stay fixed during run
  pars = Parameters_sm_ckm_no_b_mass::getInstance(); 
  SLHAReader slha(param_card_name); 
  pars->setIndependentParameters(slha); 
  pars->setIndependentCouplings(); 
  pars->printIndependentParameters(); 
  pars->printIndependentCouplings(); 
  // Set external particle masses for this matrix element
  mME.push_back(pars->ZERO); 
  mME.push_back(pars->ZERO); 
  mME.push_back(pars->ZERO); 
  mME.push_back(pars->ZERO); 
  mME.push_back(pars->ZERO); 
  mME.push_back(pars->ZERO); 
  mME.push_back(pars->ZERO); 
  mME.push_back(pars->ZERO); 
  jamp2[0] = new double[6]; 
}

//--------------------------------------------------------------------------
// Evaluate |M|^2, part independent of incoming flavour.

void CPPProcess::sigmaKin() 
{
  // Set the parameters which change event by event
  pars->setDependentParameters(); 
  pars->setDependentCouplings(); 
  static bool firsttime = true; 
  if (firsttime)
  {
    pars->printDependentParameters(); 
    pars->printDependentCouplings(); 
    firsttime = false; 
  }

  // Reset color flows
  for(int i = 0; i < 6; i++ )
    jamp2[0][i] = 0.; 

  // Local variables and constants
  const int ncomb = 256; 
  static bool goodhel[ncomb] = {ncomb * false}; 
  static int ntry = 0, sum_hel = 0, ngood = 0; 
  static int igood[ncomb]; 
  static int jhel; 
  std::complex<double> * * wfs; 
  double t[nprocesses]; 
  // Helicities for the process
  static const int helicities[ncomb][nexternal] = {{-1, -1, -1, -1, -1, -1, -1,
      -1}, {-1, -1, -1, -1, -1, -1, -1, 1}, {-1, -1, -1, -1, -1, -1, 1, -1},
      {-1, -1, -1, -1, -1, -1, 1, 1}, {-1, -1, -1, -1, -1, 1, -1, -1}, {-1, -1,
      -1, -1, -1, 1, -1, 1}, {-1, -1, -1, -1, -1, 1, 1, -1}, {-1, -1, -1, -1,
      -1, 1, 1, 1}, {-1, -1, -1, -1, 1, -1, -1, -1}, {-1, -1, -1, -1, 1, -1,
      -1, 1}, {-1, -1, -1, -1, 1, -1, 1, -1}, {-1, -1, -1, -1, 1, -1, 1, 1},
      {-1, -1, -1, -1, 1, 1, -1, -1}, {-1, -1, -1, -1, 1, 1, -1, 1}, {-1, -1,
      -1, -1, 1, 1, 1, -1}, {-1, -1, -1, -1, 1, 1, 1, 1}, {-1, -1, -1, 1, -1,
      -1, -1, -1}, {-1, -1, -1, 1, -1, -1, -1, 1}, {-1, -1, -1, 1, -1, -1, 1,
      -1}, {-1, -1, -1, 1, -1, -1, 1, 1}, {-1, -1, -1, 1, -1, 1, -1, -1}, {-1,
      -1, -1, 1, -1, 1, -1, 1}, {-1, -1, -1, 1, -1, 1, 1, -1}, {-1, -1, -1, 1,
      -1, 1, 1, 1}, {-1, -1, -1, 1, 1, -1, -1, -1}, {-1, -1, -1, 1, 1, -1, -1,
      1}, {-1, -1, -1, 1, 1, -1, 1, -1}, {-1, -1, -1, 1, 1, -1, 1, 1}, {-1, -1,
      -1, 1, 1, 1, -1, -1}, {-1, -1, -1, 1, 1, 1, -1, 1}, {-1, -1, -1, 1, 1, 1,
      1, -1}, {-1, -1, -1, 1, 1, 1, 1, 1}, {-1, -1, 1, -1, -1, -1, -1, -1},
      {-1, -1, 1, -1, -1, -1, -1, 1}, {-1, -1, 1, -1, -1, -1, 1, -1}, {-1, -1,
      1, -1, -1, -1, 1, 1}, {-1, -1, 1, -1, -1, 1, -1, -1}, {-1, -1, 1, -1, -1,
      1, -1, 1}, {-1, -1, 1, -1, -1, 1, 1, -1}, {-1, -1, 1, -1, -1, 1, 1, 1},
      {-1, -1, 1, -1, 1, -1, -1, -1}, {-1, -1, 1, -1, 1, -1, -1, 1}, {-1, -1,
      1, -1, 1, -1, 1, -1}, {-1, -1, 1, -1, 1, -1, 1, 1}, {-1, -1, 1, -1, 1, 1,
      -1, -1}, {-1, -1, 1, -1, 1, 1, -1, 1}, {-1, -1, 1, -1, 1, 1, 1, -1}, {-1,
      -1, 1, -1, 1, 1, 1, 1}, {-1, -1, 1, 1, -1, -1, -1, -1}, {-1, -1, 1, 1,
      -1, -1, -1, 1}, {-1, -1, 1, 1, -1, -1, 1, -1}, {-1, -1, 1, 1, -1, -1, 1,
      1}, {-1, -1, 1, 1, -1, 1, -1, -1}, {-1, -1, 1, 1, -1, 1, -1, 1}, {-1, -1,
      1, 1, -1, 1, 1, -1}, {-1, -1, 1, 1, -1, 1, 1, 1}, {-1, -1, 1, 1, 1, -1,
      -1, -1}, {-1, -1, 1, 1, 1, -1, -1, 1}, {-1, -1, 1, 1, 1, -1, 1, -1}, {-1,
      -1, 1, 1, 1, -1, 1, 1}, {-1, -1, 1, 1, 1, 1, -1, -1}, {-1, -1, 1, 1, 1,
      1, -1, 1}, {-1, -1, 1, 1, 1, 1, 1, -1}, {-1, -1, 1, 1, 1, 1, 1, 1}, {-1,
      1, -1, -1, -1, -1, -1, -1}, {-1, 1, -1, -1, -1, -1, -1, 1}, {-1, 1, -1,
      -1, -1, -1, 1, -1}, {-1, 1, -1, -1, -1, -1, 1, 1}, {-1, 1, -1, -1, -1, 1,
      -1, -1}, {-1, 1, -1, -1, -1, 1, -1, 1}, {-1, 1, -1, -1, -1, 1, 1, -1},
      {-1, 1, -1, -1, -1, 1, 1, 1}, {-1, 1, -1, -1, 1, -1, -1, -1}, {-1, 1, -1,
      -1, 1, -1, -1, 1}, {-1, 1, -1, -1, 1, -1, 1, -1}, {-1, 1, -1, -1, 1, -1,
      1, 1}, {-1, 1, -1, -1, 1, 1, -1, -1}, {-1, 1, -1, -1, 1, 1, -1, 1}, {-1,
      1, -1, -1, 1, 1, 1, -1}, {-1, 1, -1, -1, 1, 1, 1, 1}, {-1, 1, -1, 1, -1,
      -1, -1, -1}, {-1, 1, -1, 1, -1, -1, -1, 1}, {-1, 1, -1, 1, -1, -1, 1,
      -1}, {-1, 1, -1, 1, -1, -1, 1, 1}, {-1, 1, -1, 1, -1, 1, -1, -1}, {-1, 1,
      -1, 1, -1, 1, -1, 1}, {-1, 1, -1, 1, -1, 1, 1, -1}, {-1, 1, -1, 1, -1, 1,
      1, 1}, {-1, 1, -1, 1, 1, -1, -1, -1}, {-1, 1, -1, 1, 1, -1, -1, 1}, {-1,
      1, -1, 1, 1, -1, 1, -1}, {-1, 1, -1, 1, 1, -1, 1, 1}, {-1, 1, -1, 1, 1,
      1, -1, -1}, {-1, 1, -1, 1, 1, 1, -1, 1}, {-1, 1, -1, 1, 1, 1, 1, -1},
      {-1, 1, -1, 1, 1, 1, 1, 1}, {-1, 1, 1, -1, -1, -1, -1, -1}, {-1, 1, 1,
      -1, -1, -1, -1, 1}, {-1, 1, 1, -1, -1, -1, 1, -1}, {-1, 1, 1, -1, -1, -1,
      1, 1}, {-1, 1, 1, -1, -1, 1, -1, -1}, {-1, 1, 1, -1, -1, 1, -1, 1}, {-1,
      1, 1, -1, -1, 1, 1, -1}, {-1, 1, 1, -1, -1, 1, 1, 1}, {-1, 1, 1, -1, 1,
      -1, -1, -1}, {-1, 1, 1, -1, 1, -1, -1, 1}, {-1, 1, 1, -1, 1, -1, 1, -1},
      {-1, 1, 1, -1, 1, -1, 1, 1}, {-1, 1, 1, -1, 1, 1, -1, -1}, {-1, 1, 1, -1,
      1, 1, -1, 1}, {-1, 1, 1, -1, 1, 1, 1, -1}, {-1, 1, 1, -1, 1, 1, 1, 1},
      {-1, 1, 1, 1, -1, -1, -1, -1}, {-1, 1, 1, 1, -1, -1, -1, 1}, {-1, 1, 1,
      1, -1, -1, 1, -1}, {-1, 1, 1, 1, -1, -1, 1, 1}, {-1, 1, 1, 1, -1, 1, -1,
      -1}, {-1, 1, 1, 1, -1, 1, -1, 1}, {-1, 1, 1, 1, -1, 1, 1, -1}, {-1, 1, 1,
      1, -1, 1, 1, 1}, {-1, 1, 1, 1, 1, -1, -1, -1}, {-1, 1, 1, 1, 1, -1, -1,
      1}, {-1, 1, 1, 1, 1, -1, 1, -1}, {-1, 1, 1, 1, 1, -1, 1, 1}, {-1, 1, 1,
      1, 1, 1, -1, -1}, {-1, 1, 1, 1, 1, 1, -1, 1}, {-1, 1, 1, 1, 1, 1, 1, -1},
      {-1, 1, 1, 1, 1, 1, 1, 1}, {1, -1, -1, -1, -1, -1, -1, -1}, {1, -1, -1,
      -1, -1, -1, -1, 1}, {1, -1, -1, -1, -1, -1, 1, -1}, {1, -1, -1, -1, -1,
      -1, 1, 1}, {1, -1, -1, -1, -1, 1, -1, -1}, {1, -1, -1, -1, -1, 1, -1, 1},
      {1, -1, -1, -1, -1, 1, 1, -1}, {1, -1, -1, -1, -1, 1, 1, 1}, {1, -1, -1,
      -1, 1, -1, -1, -1}, {1, -1, -1, -1, 1, -1, -1, 1}, {1, -1, -1, -1, 1, -1,
      1, -1}, {1, -1, -1, -1, 1, -1, 1, 1}, {1, -1, -1, -1, 1, 1, -1, -1}, {1,
      -1, -1, -1, 1, 1, -1, 1}, {1, -1, -1, -1, 1, 1, 1, -1}, {1, -1, -1, -1,
      1, 1, 1, 1}, {1, -1, -1, 1, -1, -1, -1, -1}, {1, -1, -1, 1, -1, -1, -1,
      1}, {1, -1, -1, 1, -1, -1, 1, -1}, {1, -1, -1, 1, -1, -1, 1, 1}, {1, -1,
      -1, 1, -1, 1, -1, -1}, {1, -1, -1, 1, -1, 1, -1, 1}, {1, -1, -1, 1, -1,
      1, 1, -1}, {1, -1, -1, 1, -1, 1, 1, 1}, {1, -1, -1, 1, 1, -1, -1, -1},
      {1, -1, -1, 1, 1, -1, -1, 1}, {1, -1, -1, 1, 1, -1, 1, -1}, {1, -1, -1,
      1, 1, -1, 1, 1}, {1, -1, -1, 1, 1, 1, -1, -1}, {1, -1, -1, 1, 1, 1, -1,
      1}, {1, -1, -1, 1, 1, 1, 1, -1}, {1, -1, -1, 1, 1, 1, 1, 1}, {1, -1, 1,
      -1, -1, -1, -1, -1}, {1, -1, 1, -1, -1, -1, -1, 1}, {1, -1, 1, -1, -1,
      -1, 1, -1}, {1, -1, 1, -1, -1, -1, 1, 1}, {1, -1, 1, -1, -1, 1, -1, -1},
      {1, -1, 1, -1, -1, 1, -1, 1}, {1, -1, 1, -1, -1, 1, 1, -1}, {1, -1, 1,
      -1, -1, 1, 1, 1}, {1, -1, 1, -1, 1, -1, -1, -1}, {1, -1, 1, -1, 1, -1,
      -1, 1}, {1, -1, 1, -1, 1, -1, 1, -1}, {1, -1, 1, -1, 1, -1, 1, 1}, {1,
      -1, 1, -1, 1, 1, -1, -1}, {1, -1, 1, -1, 1, 1, -1, 1}, {1, -1, 1, -1, 1,
      1, 1, -1}, {1, -1, 1, -1, 1, 1, 1, 1}, {1, -1, 1, 1, -1, -1, -1, -1}, {1,
      -1, 1, 1, -1, -1, -1, 1}, {1, -1, 1, 1, -1, -1, 1, -1}, {1, -1, 1, 1, -1,
      -1, 1, 1}, {1, -1, 1, 1, -1, 1, -1, -1}, {1, -1, 1, 1, -1, 1, -1, 1}, {1,
      -1, 1, 1, -1, 1, 1, -1}, {1, -1, 1, 1, -1, 1, 1, 1}, {1, -1, 1, 1, 1, -1,
      -1, -1}, {1, -1, 1, 1, 1, -1, -1, 1}, {1, -1, 1, 1, 1, -1, 1, -1}, {1,
      -1, 1, 1, 1, -1, 1, 1}, {1, -1, 1, 1, 1, 1, -1, -1}, {1, -1, 1, 1, 1, 1,
      -1, 1}, {1, -1, 1, 1, 1, 1, 1, -1}, {1, -1, 1, 1, 1, 1, 1, 1}, {1, 1, -1,
      -1, -1, -1, -1, -1}, {1, 1, -1, -1, -1, -1, -1, 1}, {1, 1, -1, -1, -1,
      -1, 1, -1}, {1, 1, -1, -1, -1, -1, 1, 1}, {1, 1, -1, -1, -1, 1, -1, -1},
      {1, 1, -1, -1, -1, 1, -1, 1}, {1, 1, -1, -1, -1, 1, 1, -1}, {1, 1, -1,
      -1, -1, 1, 1, 1}, {1, 1, -1, -1, 1, -1, -1, -1}, {1, 1, -1, -1, 1, -1,
      -1, 1}, {1, 1, -1, -1, 1, -1, 1, -1}, {1, 1, -1, -1, 1, -1, 1, 1}, {1, 1,
      -1, -1, 1, 1, -1, -1}, {1, 1, -1, -1, 1, 1, -1, 1}, {1, 1, -1, -1, 1, 1,
      1, -1}, {1, 1, -1, -1, 1, 1, 1, 1}, {1, 1, -1, 1, -1, -1, -1, -1}, {1, 1,
      -1, 1, -1, -1, -1, 1}, {1, 1, -1, 1, -1, -1, 1, -1}, {1, 1, -1, 1, -1,
      -1, 1, 1}, {1, 1, -1, 1, -1, 1, -1, -1}, {1, 1, -1, 1, -1, 1, -1, 1}, {1,
      1, -1, 1, -1, 1, 1, -1}, {1, 1, -1, 1, -1, 1, 1, 1}, {1, 1, -1, 1, 1, -1,
      -1, -1}, {1, 1, -1, 1, 1, -1, -1, 1}, {1, 1, -1, 1, 1, -1, 1, -1}, {1, 1,
      -1, 1, 1, -1, 1, 1}, {1, 1, -1, 1, 1, 1, -1, -1}, {1, 1, -1, 1, 1, 1, -1,
      1}, {1, 1, -1, 1, 1, 1, 1, -1}, {1, 1, -1, 1, 1, 1, 1, 1}, {1, 1, 1, -1,
      -1, -1, -1, -1}, {1, 1, 1, -1, -1, -1, -1, 1}, {1, 1, 1, -1, -1, -1, 1,
      -1}, {1, 1, 1, -1, -1, -1, 1, 1}, {1, 1, 1, -1, -1, 1, -1, -1}, {1, 1, 1,
      -1, -1, 1, -1, 1}, {1, 1, 1, -1, -1, 1, 1, -1}, {1, 1, 1, -1, -1, 1, 1,
      1}, {1, 1, 1, -1, 1, -1, -1, -1}, {1, 1, 1, -1, 1, -1, -1, 1}, {1, 1, 1,
      -1, 1, -1, 1, -1}, {1, 1, 1, -1, 1, -1, 1, 1}, {1, 1, 1, -1, 1, 1, -1,
      -1}, {1, 1, 1, -1, 1, 1, -1, 1}, {1, 1, 1, -1, 1, 1, 1, -1}, {1, 1, 1,
      -1, 1, 1, 1, 1}, {1, 1, 1, 1, -1, -1, -1, -1}, {1, 1, 1, 1, -1, -1, -1,
      1}, {1, 1, 1, 1, -1, -1, 1, -1}, {1, 1, 1, 1, -1, -1, 1, 1}, {1, 1, 1, 1,
      -1, 1, -1, -1}, {1, 1, 1, 1, -1, 1, -1, 1}, {1, 1, 1, 1, -1, 1, 1, -1},
      {1, 1, 1, 1, -1, 1, 1, 1}, {1, 1, 1, 1, 1, -1, -1, -1}, {1, 1, 1, 1, 1,
      -1, -1, 1}, {1, 1, 1, 1, 1, -1, 1, -1}, {1, 1, 1, 1, 1, -1, 1, 1}, {1, 1,
      1, 1, 1, 1, -1, -1}, {1, 1, 1, 1, 1, 1, -1, 1}, {1, 1, 1, 1, 1, 1, 1,
      -1}, {1, 1, 1, 1, 1, 1, 1, 1}};
  // Denominators: spins, colors and identical particles
  const int denominators[nprocesses] = {72, 72}; 

  ntry = ntry + 1; 

  // Reset the matrix elements
  for(int i = 0; i < nprocesses; i++ )
  {
    matrix_element[i] = 0.; 
  }
  // Define permutation
  int perm[nexternal]; 
  for(int i = 0; i < nexternal; i++ )
  {
    perm[i] = i; 
  }

  if (sum_hel == 0 || ntry < 10)
  {
    // Calculate the matrix element for all helicities
    for(int ihel = 0; ihel < ncomb; ihel++ )
    {
      if (goodhel[ihel] || ntry < 2)
      {
        calculate_wavefunctions(perm, helicities[ihel]); 
        t[0] = matrix_uxcx_epemuuxuxcx_no_h(); 
        // Mirror initial state momenta for mirror process
        perm[0] = 1; 
        perm[1] = 0; 
        // Calculate wavefunctions
        calculate_wavefunctions(perm, helicities[ihel]); 
        // Mirror back
        perm[0] = 0; 
        perm[1] = 1; 
        // Calculate matrix elements
        t[1] = matrix_uxcx_epemuuxuxcx_no_h(); 
        double tsum = 0; 
        for(int iproc = 0; iproc < nprocesses; iproc++ )
        {
          matrix_element[iproc] += t[iproc]; 
          tsum += t[iproc]; 
        }
        // Store which helicities give non-zero result
        if (tsum != 0. && !goodhel[ihel])
        {
          goodhel[ihel] = true; 
          ngood++; 
          igood[ngood] = ihel; 
        }
      }
    }
    jhel = 0; 
    sum_hel = min(sum_hel, ngood); 
  }
  else
  {
    // Only use the "good" helicities
    for(int j = 0; j < sum_hel; j++ )
    {
      jhel++; 
      if (jhel >= ngood)
        jhel = 0; 
      double hwgt = double(ngood)/double(sum_hel); 
      int ihel = igood[jhel]; 
      calculate_wavefunctions(perm, helicities[ihel]); 
      t[0] = matrix_uxcx_epemuuxuxcx_no_h(); 
      // Mirror initial state momenta for mirror process
      perm[0] = 1; 
      perm[1] = 0; 
      // Calculate wavefunctions
      calculate_wavefunctions(perm, helicities[ihel]); 
      // Mirror back
      perm[0] = 0; 
      perm[1] = 1; 
      // Calculate matrix elements
      t[1] = matrix_uxcx_epemuuxuxcx_no_h(); 
      for(int iproc = 0; iproc < nprocesses; iproc++ )
      {
        matrix_element[iproc] += t[iproc] * hwgt; 
      }
    }
  }

  for (int i = 0; i < nprocesses; i++ )
    matrix_element[i] /= denominators[i]; 



}

//--------------------------------------------------------------------------
// Evaluate |M|^2, including incoming flavour dependence.

double CPPProcess::sigmaHat() 
{
  // Select between the different processes
  if(id1 == -2 && id2 == -4)
  {
    // Add matrix elements for processes with beams (-2, -4)
    return matrix_element[0] * 2; 
  }
  else if(id1 == -4 && id2 == -2)
  {
    // Add matrix elements for processes with beams (-4, -2)
    return matrix_element[1] * 2; 
  }
  else
  {
    // Return 0 if not correct initial state assignment
    return 0.; 
  }
}

//==========================================================================
// Private class member functions

//--------------------------------------------------------------------------
// Evaluate |M|^2 for each subprocess

void CPPProcess::calculate_wavefunctions(const int perm[], const int hel[])
{
  // Calculate wavefunctions for all processes
  int i, j; 

  // Calculate all wavefunctions
  oxxxxx(p[perm[0]], mME[0], hel[0], -1, w[0]); 
  oxxxxx(p[perm[1]], mME[1], hel[1], -1, w[1]); 
  ixxxxx(p[perm[2]], mME[2], hel[2], -1, w[2]); 
  oxxxxx(p[perm[3]], mME[3], hel[3], +1, w[3]); 
  oxxxxx(p[perm[4]], mME[4], hel[4], +1, w[4]); 
  ixxxxx(p[perm[5]], mME[5], hel[5], -1, w[5]); 
  ixxxxx(p[perm[6]], mME[6], hel[6], -1, w[6]); 
  ixxxxx(p[perm[7]], mME[7], hel[7], -1, w[7]); 
  FFV1P0_3(w[5], w[0], pars->GC_11, pars->ZERO, pars->ZERO, w[8]); 
  FFV1P0_3(w[6], w[4], pars->GC_11, pars->ZERO, pars->ZERO, w[9]); 
  FFV1P0_3(w[2], w[3], pars->GC_3, pars->ZERO, pars->ZERO, w[10]); 
  VVV1P0_1(w[8], w[9], pars->GC_10, pars->ZERO, pars->ZERO, w[11]); 
  FFV1_1(w[1], w[10], pars->GC_2, pars->ZERO, pars->ZERO, w[12]); 
  FFV1_2(w[7], w[10], pars->GC_2, pars->ZERO, pars->ZERO, w[13]); 
  FFV1_1(w[1], w[8], pars->GC_11, pars->ZERO, pars->ZERO, w[14]); 
  FFV1_2(w[7], w[9], pars->GC_11, pars->ZERO, pars->ZERO, w[15]); 
  FFV1_2(w[7], w[8], pars->GC_11, pars->ZERO, pars->ZERO, w[16]); 
  FFV1_1(w[1], w[9], pars->GC_11, pars->ZERO, pars->ZERO, w[17]); 
  FFV2_4_3(w[2], w[3], -pars->GC_51, pars->GC_59, pars->mdl_MZ, pars->mdl_WZ,
      w[18]);
  FFV2_5_1(w[1], w[18], pars->GC_51, pars->GC_58, pars->ZERO, pars->ZERO,
      w[19]);
  FFV2_5_2(w[7], w[18], pars->GC_51, pars->GC_58, pars->ZERO, pars->ZERO,
      w[20]);
  FFV1_2(w[6], w[8], pars->GC_11, pars->ZERO, pars->ZERO, w[21]); 
  FFV1P0_3(w[21], w[4], pars->GC_11, pars->ZERO, pars->ZERO, w[22]); 
  FFV1_1(w[4], w[8], pars->GC_11, pars->ZERO, pars->ZERO, w[23]); 
  FFV1P0_3(w[6], w[23], pars->GC_11, pars->ZERO, pars->ZERO, w[24]); 
  FFV1_2(w[6], w[10], pars->GC_2, pars->ZERO, pars->ZERO, w[25]); 
  FFV1P0_3(w[7], w[14], pars->GC_11, pars->ZERO, pars->ZERO, w[26]); 
  FFV1_1(w[4], w[10], pars->GC_2, pars->ZERO, pars->ZERO, w[27]); 
  FFV1P0_3(w[16], w[1], pars->GC_11, pars->ZERO, pars->ZERO, w[28]); 
  FFV2_5_2(w[6], w[18], pars->GC_51, pars->GC_58, pars->ZERO, pars->ZERO,
      w[29]);
  FFV2_5_1(w[4], w[18], pars->GC_51, pars->GC_58, pars->ZERO, pars->ZERO,
      w[30]);
  FFV1P0_3(w[7], w[1], pars->GC_11, pars->ZERO, pars->ZERO, w[31]); 
  FFV1_1(w[4], w[31], pars->GC_11, pars->ZERO, pars->ZERO, w[32]); 
  FFV1_2(w[6], w[31], pars->GC_11, pars->ZERO, pars->ZERO, w[33]); 
  VVV1P0_1(w[8], w[31], pars->GC_10, pars->ZERO, pars->ZERO, w[34]); 
  FFV1P0_3(w[5], w[4], pars->GC_11, pars->ZERO, pars->ZERO, w[35]); 
  FFV1P0_3(w[6], w[0], pars->GC_11, pars->ZERO, pars->ZERO, w[36]); 
  VVV1P0_1(w[35], w[36], pars->GC_10, pars->ZERO, pars->ZERO, w[37]); 
  FFV1_1(w[1], w[35], pars->GC_11, pars->ZERO, pars->ZERO, w[38]); 
  FFV1_2(w[7], w[36], pars->GC_11, pars->ZERO, pars->ZERO, w[39]); 
  FFV1_2(w[7], w[35], pars->GC_11, pars->ZERO, pars->ZERO, w[40]); 
  FFV1_1(w[1], w[36], pars->GC_11, pars->ZERO, pars->ZERO, w[41]); 
  FFV1_2(w[6], w[35], pars->GC_11, pars->ZERO, pars->ZERO, w[42]); 
  FFV1P0_3(w[42], w[0], pars->GC_11, pars->ZERO, pars->ZERO, w[43]); 
  FFV1_1(w[0], w[35], pars->GC_11, pars->ZERO, pars->ZERO, w[44]); 
  FFV1P0_3(w[6], w[44], pars->GC_11, pars->ZERO, pars->ZERO, w[45]); 
  FFV1P0_3(w[7], w[38], pars->GC_11, pars->ZERO, pars->ZERO, w[46]); 
  FFV1_1(w[0], w[10], pars->GC_2, pars->ZERO, pars->ZERO, w[47]); 
  FFV1P0_3(w[40], w[1], pars->GC_11, pars->ZERO, pars->ZERO, w[48]); 
  FFV2_5_1(w[0], w[18], pars->GC_51, pars->GC_58, pars->ZERO, pars->ZERO,
      w[49]);
  FFV1_1(w[0], w[31], pars->GC_11, pars->ZERO, pars->ZERO, w[50]); 
  VVV1P0_1(w[35], w[31], pars->GC_10, pars->ZERO, pars->ZERO, w[51]); 
  FFV1_2(w[5], w[36], pars->GC_11, pars->ZERO, pars->ZERO, w[52]); 
  FFV1P0_3(w[52], w[4], pars->GC_11, pars->ZERO, pars->ZERO, w[53]); 
  FFV1_2(w[5], w[10], pars->GC_2, pars->ZERO, pars->ZERO, w[54]); 
  FFV1P0_3(w[54], w[4], pars->GC_11, pars->ZERO, pars->ZERO, w[55]); 
  FFV1_1(w[4], w[36], pars->GC_11, pars->ZERO, pars->ZERO, w[56]); 
  FFV1P0_3(w[5], w[56], pars->GC_11, pars->ZERO, pars->ZERO, w[57]); 
  FFV1P0_3(w[5], w[27], pars->GC_11, pars->ZERO, pars->ZERO, w[58]); 
  FFV2_5_2(w[5], w[18], pars->GC_51, pars->GC_58, pars->ZERO, pars->ZERO,
      w[59]);
  FFV1P0_3(w[59], w[4], pars->GC_11, pars->ZERO, pars->ZERO, w[60]); 
  FFV1P0_3(w[5], w[30], pars->GC_11, pars->ZERO, pars->ZERO, w[61]); 
  VVV1P0_1(w[36], w[31], pars->GC_10, pars->ZERO, pars->ZERO, w[62]); 
  FFV1_2(w[5], w[31], pars->GC_11, pars->ZERO, pars->ZERO, w[63]); 
  FFV1_2(w[5], w[9], pars->GC_11, pars->ZERO, pars->ZERO, w[64]); 
  FFV1P0_3(w[64], w[0], pars->GC_11, pars->ZERO, pars->ZERO, w[65]); 
  FFV1P0_3(w[54], w[0], pars->GC_11, pars->ZERO, pars->ZERO, w[66]); 
  FFV1_1(w[0], w[9], pars->GC_11, pars->ZERO, pars->ZERO, w[67]); 
  FFV1P0_3(w[5], w[67], pars->GC_11, pars->ZERO, pars->ZERO, w[68]); 
  FFV1P0_3(w[5], w[47], pars->GC_11, pars->ZERO, pars->ZERO, w[69]); 
  FFV1P0_3(w[59], w[0], pars->GC_11, pars->ZERO, pars->ZERO, w[70]); 
  FFV1P0_3(w[5], w[49], pars->GC_11, pars->ZERO, pars->ZERO, w[71]); 
  VVV1P0_1(w[9], w[31], pars->GC_10, pars->ZERO, pars->ZERO, w[72]); 
  FFV1P0_3(w[63], w[0], pars->GC_11, pars->ZERO, pars->ZERO, w[73]); 
  FFV1P0_3(w[63], w[4], pars->GC_11, pars->ZERO, pars->ZERO, w[74]); 
  FFV1P0_3(w[5], w[50], pars->GC_11, pars->ZERO, pars->ZERO, w[75]); 
  FFV1P0_3(w[5], w[32], pars->GC_11, pars->ZERO, pars->ZERO, w[76]); 

  // Calculate all amplitudes
  // Amplitude(s) for diagram number 0
  FFV1_0(w[7], w[12], w[11], pars->GC_11, amp[0]); 
  FFV1_0(w[13], w[1], w[11], pars->GC_11, amp[1]); 
  FFV1_0(w[15], w[14], w[10], pars->GC_2, amp[2]); 
  FFV1_0(w[13], w[14], w[9], pars->GC_11, amp[3]); 
  FFV1_0(w[16], w[17], w[10], pars->GC_2, amp[4]); 
  FFV1_0(w[16], w[12], w[9], pars->GC_11, amp[5]); 
  FFV1_0(w[13], w[17], w[8], pars->GC_11, amp[6]); 
  FFV1_0(w[15], w[12], w[8], pars->GC_11, amp[7]); 
  FFV1_0(w[7], w[19], w[11], pars->GC_11, amp[8]); 
  FFV1_0(w[20], w[1], w[11], pars->GC_11, amp[9]); 
  FFV2_5_0(w[15], w[14], w[18], pars->GC_51, pars->GC_58, amp[10]); 
  FFV1_0(w[20], w[14], w[9], pars->GC_11, amp[11]); 
  FFV2_5_0(w[16], w[17], w[18], pars->GC_51, pars->GC_58, amp[12]); 
  FFV1_0(w[16], w[19], w[9], pars->GC_11, amp[13]); 
  FFV1_0(w[20], w[17], w[8], pars->GC_11, amp[14]); 
  FFV1_0(w[15], w[19], w[8], pars->GC_11, amp[15]); 
  FFV1_0(w[7], w[12], w[22], pars->GC_11, amp[16]); 
  FFV1_0(w[13], w[1], w[22], pars->GC_11, amp[17]); 
  FFV1_0(w[7], w[12], w[24], pars->GC_11, amp[18]); 
  FFV1_0(w[13], w[1], w[24], pars->GC_11, amp[19]); 
  FFV1_0(w[25], w[4], w[26], pars->GC_11, amp[20]); 
  FFV1_0(w[6], w[27], w[26], pars->GC_11, amp[21]); 
  FFV1_0(w[25], w[4], w[28], pars->GC_11, amp[22]); 
  FFV1_0(w[6], w[27], w[28], pars->GC_11, amp[23]); 
  FFV1_0(w[7], w[19], w[22], pars->GC_11, amp[24]); 
  FFV1_0(w[20], w[1], w[22], pars->GC_11, amp[25]); 
  FFV1_0(w[7], w[19], w[24], pars->GC_11, amp[26]); 
  FFV1_0(w[20], w[1], w[24], pars->GC_11, amp[27]); 
  FFV1_0(w[29], w[4], w[26], pars->GC_11, amp[28]); 
  FFV1_0(w[6], w[30], w[26], pars->GC_11, amp[29]); 
  FFV1_0(w[29], w[4], w[28], pars->GC_11, amp[30]); 
  FFV1_0(w[6], w[30], w[28], pars->GC_11, amp[31]); 
  FFV1_0(w[21], w[27], w[31], pars->GC_11, amp[32]); 
  FFV1_0(w[21], w[32], w[10], pars->GC_2, amp[33]); 
  FFV1_0(w[25], w[23], w[31], pars->GC_11, amp[34]); 
  FFV1_0(w[33], w[23], w[10], pars->GC_2, amp[35]); 
  FFV1_0(w[25], w[4], w[34], pars->GC_11, amp[36]); 
  FFV1_0(w[6], w[27], w[34], pars->GC_11, amp[37]); 
  FFV1_0(w[25], w[32], w[8], pars->GC_11, amp[38]); 
  FFV1_0(w[33], w[27], w[8], pars->GC_11, amp[39]); 
  FFV1_0(w[21], w[30], w[31], pars->GC_11, amp[40]); 
  FFV2_5_0(w[21], w[32], w[18], pars->GC_51, pars->GC_58, amp[41]); 
  FFV1_0(w[29], w[23], w[31], pars->GC_11, amp[42]); 
  FFV2_5_0(w[33], w[23], w[18], pars->GC_51, pars->GC_58, amp[43]); 
  FFV1_0(w[29], w[4], w[34], pars->GC_11, amp[44]); 
  FFV1_0(w[6], w[30], w[34], pars->GC_11, amp[45]); 
  FFV1_0(w[29], w[32], w[8], pars->GC_11, amp[46]); 
  FFV1_0(w[33], w[30], w[8], pars->GC_11, amp[47]); 
  FFV1_0(w[7], w[12], w[37], pars->GC_11, amp[48]); 
  FFV1_0(w[13], w[1], w[37], pars->GC_11, amp[49]); 
  FFV1_0(w[39], w[38], w[10], pars->GC_2, amp[50]); 
  FFV1_0(w[13], w[38], w[36], pars->GC_11, amp[51]); 
  FFV1_0(w[40], w[41], w[10], pars->GC_2, amp[52]); 
  FFV1_0(w[40], w[12], w[36], pars->GC_11, amp[53]); 
  FFV1_0(w[13], w[41], w[35], pars->GC_11, amp[54]); 
  FFV1_0(w[39], w[12], w[35], pars->GC_11, amp[55]); 
  FFV1_0(w[7], w[19], w[37], pars->GC_11, amp[56]); 
  FFV1_0(w[20], w[1], w[37], pars->GC_11, amp[57]); 
  FFV2_5_0(w[39], w[38], w[18], pars->GC_51, pars->GC_58, amp[58]); 
  FFV1_0(w[20], w[38], w[36], pars->GC_11, amp[59]); 
  FFV2_5_0(w[40], w[41], w[18], pars->GC_51, pars->GC_58, amp[60]); 
  FFV1_0(w[40], w[19], w[36], pars->GC_11, amp[61]); 
  FFV1_0(w[20], w[41], w[35], pars->GC_11, amp[62]); 
  FFV1_0(w[39], w[19], w[35], pars->GC_11, amp[63]); 
  FFV1_0(w[7], w[12], w[43], pars->GC_11, amp[64]); 
  FFV1_0(w[13], w[1], w[43], pars->GC_11, amp[65]); 
  FFV1_0(w[7], w[12], w[45], pars->GC_11, amp[66]); 
  FFV1_0(w[13], w[1], w[45], pars->GC_11, amp[67]); 
  FFV1_0(w[25], w[0], w[46], pars->GC_11, amp[68]); 
  FFV1_0(w[6], w[47], w[46], pars->GC_11, amp[69]); 
  FFV1_0(w[25], w[0], w[48], pars->GC_11, amp[70]); 
  FFV1_0(w[6], w[47], w[48], pars->GC_11, amp[71]); 
  FFV1_0(w[7], w[19], w[43], pars->GC_11, amp[72]); 
  FFV1_0(w[20], w[1], w[43], pars->GC_11, amp[73]); 
  FFV1_0(w[7], w[19], w[45], pars->GC_11, amp[74]); 
  FFV1_0(w[20], w[1], w[45], pars->GC_11, amp[75]); 
  FFV1_0(w[29], w[0], w[46], pars->GC_11, amp[76]); 
  FFV1_0(w[6], w[49], w[46], pars->GC_11, amp[77]); 
  FFV1_0(w[29], w[0], w[48], pars->GC_11, amp[78]); 
  FFV1_0(w[6], w[49], w[48], pars->GC_11, amp[79]); 
  FFV1_0(w[42], w[47], w[31], pars->GC_11, amp[80]); 
  FFV1_0(w[42], w[50], w[10], pars->GC_2, amp[81]); 
  FFV1_0(w[25], w[44], w[31], pars->GC_11, amp[82]); 
  FFV1_0(w[33], w[44], w[10], pars->GC_2, amp[83]); 
  FFV1_0(w[25], w[0], w[51], pars->GC_11, amp[84]); 
  FFV1_0(w[6], w[47], w[51], pars->GC_11, amp[85]); 
  FFV1_0(w[25], w[50], w[35], pars->GC_11, amp[86]); 
  FFV1_0(w[33], w[47], w[35], pars->GC_11, amp[87]); 
  FFV1_0(w[42], w[49], w[31], pars->GC_11, amp[88]); 
  FFV2_5_0(w[42], w[50], w[18], pars->GC_51, pars->GC_58, amp[89]); 
  FFV1_0(w[29], w[44], w[31], pars->GC_11, amp[90]); 
  FFV2_5_0(w[33], w[44], w[18], pars->GC_51, pars->GC_58, amp[91]); 
  FFV1_0(w[29], w[0], w[51], pars->GC_11, amp[92]); 
  FFV1_0(w[6], w[49], w[51], pars->GC_11, amp[93]); 
  FFV1_0(w[29], w[50], w[35], pars->GC_11, amp[94]); 
  FFV1_0(w[33], w[49], w[35], pars->GC_11, amp[95]); 
  FFV1_0(w[7], w[12], w[53], pars->GC_11, amp[96]); 
  FFV1_0(w[13], w[1], w[53], pars->GC_11, amp[97]); 
  FFV1_0(w[7], w[41], w[55], pars->GC_11, amp[98]); 
  FFV1_0(w[39], w[1], w[55], pars->GC_11, amp[99]); 
  FFV1_0(w[7], w[12], w[57], pars->GC_11, amp[100]); 
  FFV1_0(w[13], w[1], w[57], pars->GC_11, amp[101]); 
  FFV1_0(w[7], w[41], w[58], pars->GC_11, amp[102]); 
  FFV1_0(w[39], w[1], w[58], pars->GC_11, amp[103]); 
  FFV1_0(w[7], w[19], w[53], pars->GC_11, amp[104]); 
  FFV1_0(w[20], w[1], w[53], pars->GC_11, amp[105]); 
  FFV1_0(w[7], w[41], w[60], pars->GC_11, amp[106]); 
  FFV1_0(w[39], w[1], w[60], pars->GC_11, amp[107]); 
  FFV1_0(w[7], w[19], w[57], pars->GC_11, amp[108]); 
  FFV1_0(w[20], w[1], w[57], pars->GC_11, amp[109]); 
  FFV1_0(w[7], w[41], w[61], pars->GC_11, amp[110]); 
  FFV1_0(w[39], w[1], w[61], pars->GC_11, amp[111]); 
  FFV1_0(w[52], w[27], w[31], pars->GC_11, amp[112]); 
  FFV1_0(w[52], w[32], w[10], pars->GC_2, amp[113]); 
  FFV1_0(w[54], w[56], w[31], pars->GC_11, amp[114]); 
  FFV1_0(w[54], w[4], w[62], pars->GC_11, amp[115]); 
  FFV1_0(w[54], w[32], w[36], pars->GC_11, amp[116]); 
  FFV1_0(w[63], w[56], w[10], pars->GC_2, amp[117]); 
  FFV1_0(w[63], w[27], w[36], pars->GC_11, amp[118]); 
  FFV1_0(w[5], w[27], w[62], pars->GC_11, amp[119]); 
  FFV1_0(w[52], w[30], w[31], pars->GC_11, amp[120]); 
  FFV2_5_0(w[52], w[32], w[18], pars->GC_51, pars->GC_58, amp[121]); 
  FFV1_0(w[59], w[56], w[31], pars->GC_11, amp[122]); 
  FFV1_0(w[59], w[4], w[62], pars->GC_11, amp[123]); 
  FFV1_0(w[59], w[32], w[36], pars->GC_11, amp[124]); 
  FFV2_5_0(w[63], w[56], w[18], pars->GC_51, pars->GC_58, amp[125]); 
  FFV1_0(w[63], w[30], w[36], pars->GC_11, amp[126]); 
  FFV1_0(w[5], w[30], w[62], pars->GC_11, amp[127]); 
  FFV1_0(w[7], w[12], w[65], pars->GC_11, amp[128]); 
  FFV1_0(w[13], w[1], w[65], pars->GC_11, amp[129]); 
  FFV1_0(w[7], w[17], w[66], pars->GC_11, amp[130]); 
  FFV1_0(w[15], w[1], w[66], pars->GC_11, amp[131]); 
  FFV1_0(w[7], w[12], w[68], pars->GC_11, amp[132]); 
  FFV1_0(w[13], w[1], w[68], pars->GC_11, amp[133]); 
  FFV1_0(w[7], w[17], w[69], pars->GC_11, amp[134]); 
  FFV1_0(w[15], w[1], w[69], pars->GC_11, amp[135]); 
  FFV1_0(w[7], w[19], w[65], pars->GC_11, amp[136]); 
  FFV1_0(w[20], w[1], w[65], pars->GC_11, amp[137]); 
  FFV1_0(w[7], w[17], w[70], pars->GC_11, amp[138]); 
  FFV1_0(w[15], w[1], w[70], pars->GC_11, amp[139]); 
  FFV1_0(w[7], w[19], w[68], pars->GC_11, amp[140]); 
  FFV1_0(w[20], w[1], w[68], pars->GC_11, amp[141]); 
  FFV1_0(w[7], w[17], w[71], pars->GC_11, amp[142]); 
  FFV1_0(w[15], w[1], w[71], pars->GC_11, amp[143]); 
  FFV1_0(w[64], w[47], w[31], pars->GC_11, amp[144]); 
  FFV1_0(w[64], w[50], w[10], pars->GC_2, amp[145]); 
  FFV1_0(w[54], w[67], w[31], pars->GC_11, amp[146]); 
  FFV1_0(w[54], w[0], w[72], pars->GC_11, amp[147]); 
  FFV1_0(w[54], w[50], w[9], pars->GC_11, amp[148]); 
  FFV1_0(w[63], w[67], w[10], pars->GC_2, amp[149]); 
  FFV1_0(w[63], w[47], w[9], pars->GC_11, amp[150]); 
  FFV1_0(w[5], w[47], w[72], pars->GC_11, amp[151]); 
  FFV1_0(w[64], w[49], w[31], pars->GC_11, amp[152]); 
  FFV2_5_0(w[64], w[50], w[18], pars->GC_51, pars->GC_58, amp[153]); 
  FFV1_0(w[59], w[67], w[31], pars->GC_11, amp[154]); 
  FFV1_0(w[59], w[0], w[72], pars->GC_11, amp[155]); 
  FFV1_0(w[59], w[50], w[9], pars->GC_11, amp[156]); 
  FFV2_5_0(w[63], w[67], w[18], pars->GC_51, pars->GC_58, amp[157]); 
  FFV1_0(w[63], w[49], w[9], pars->GC_11, amp[158]); 
  FFV1_0(w[5], w[49], w[72], pars->GC_11, amp[159]); 
  FFV1_0(w[33], w[4], w[66], pars->GC_11, amp[160]); 
  FFV1_0(w[33], w[0], w[55], pars->GC_11, amp[161]); 
  FFV1_0(w[6], w[50], w[55], pars->GC_11, amp[162]); 
  FFV1_0(w[6], w[32], w[66], pars->GC_11, amp[163]); 
  FFV1_0(w[25], w[4], w[73], pars->GC_11, amp[164]); 
  FFV1_0(w[25], w[0], w[74], pars->GC_11, amp[165]); 
  FFV1_0(w[6], w[47], w[74], pars->GC_11, amp[166]); 
  FFV1_0(w[6], w[27], w[73], pars->GC_11, amp[167]); 
  FFV1_0(w[25], w[4], w[75], pars->GC_11, amp[168]); 
  FFV1_0(w[25], w[0], w[76], pars->GC_11, amp[169]); 
  FFV1_0(w[33], w[4], w[69], pars->GC_11, amp[170]); 
  FFV1_0(w[33], w[0], w[58], pars->GC_11, amp[171]); 
  FFV1_0(w[6], w[32], w[69], pars->GC_11, amp[172]); 
  FFV1_0(w[6], w[47], w[76], pars->GC_11, amp[173]); 
  FFV1_0(w[6], w[50], w[58], pars->GC_11, amp[174]); 
  FFV1_0(w[6], w[27], w[75], pars->GC_11, amp[175]); 
  FFV1_0(w[33], w[4], w[70], pars->GC_11, amp[176]); 
  FFV1_0(w[33], w[0], w[60], pars->GC_11, amp[177]); 
  FFV1_0(w[6], w[50], w[60], pars->GC_11, amp[178]); 
  FFV1_0(w[6], w[32], w[70], pars->GC_11, amp[179]); 
  FFV1_0(w[29], w[4], w[73], pars->GC_11, amp[180]); 
  FFV1_0(w[29], w[0], w[74], pars->GC_11, amp[181]); 
  FFV1_0(w[6], w[49], w[74], pars->GC_11, amp[182]); 
  FFV1_0(w[6], w[30], w[73], pars->GC_11, amp[183]); 
  FFV1_0(w[29], w[4], w[75], pars->GC_11, amp[184]); 
  FFV1_0(w[29], w[0], w[76], pars->GC_11, amp[185]); 
  FFV1_0(w[33], w[4], w[71], pars->GC_11, amp[186]); 
  FFV1_0(w[33], w[0], w[61], pars->GC_11, amp[187]); 
  FFV1_0(w[6], w[32], w[71], pars->GC_11, amp[188]); 
  FFV1_0(w[6], w[49], w[76], pars->GC_11, amp[189]); 
  FFV1_0(w[6], w[50], w[61], pars->GC_11, amp[190]); 
  FFV1_0(w[6], w[30], w[75], pars->GC_11, amp[191]); 

}
double CPPProcess::matrix_uxcx_epemuuxuxcx_no_h() 
{
  int i, j; 
  // Local variables
  const int ngraphs = 192; 
  const int ncolor = 6; 
  std::complex<double> ztemp; 
  std::complex<double> jamp[ncolor]; 
  // The color matrix;
  static const double denom[ncolor] = {1, 1, 1, 1, 1, 1}; 
  static const double cf[ncolor][ncolor] = {{27, 9, 9, 3, 3, 9}, {9, 27, 3, 9,
      9, 3}, {9, 3, 27, 9, 9, 3}, {3, 9, 9, 27, 3, 9}, {3, 9, 9, 3, 27, 9}, {9,
      3, 3, 9, 9, 27}};

  // Calculate color flows
  jamp[0] = +1./4. * (+1./3. * amp[2] + 1./3. * amp[3] + 1./3. * amp[4] + 1./3.
      * amp[5] + 1./3. * amp[6] + 1./3. * amp[7] + 1./3. * amp[10] + 1./3. *
      amp[11] + 1./3. * amp[12] + 1./3. * amp[13] + 1./3. * amp[14] + 1./3. *
      amp[15] + 1./3. * amp[16] + 1./3. * amp[17] + 1./3. * amp[18] + 1./3. *
      amp[19] + 1./3. * amp[20] + 1./3. * amp[21] + 1./3. * amp[22] + 1./3. *
      amp[23] + 1./3. * amp[24] + 1./3. * amp[25] + 1./3. * amp[26] + 1./3. *
      amp[27] + 1./3. * amp[28] + 1./3. * amp[29] + 1./3. * amp[30] + 1./3. *
      amp[31] + 1./3. * amp[32] + 1./3. * amp[33] + 1./3. * amp[34] + 1./3. *
      amp[35] + 1./3. * amp[38] + 1./3. * amp[39] + 1./3. * amp[40] + 1./3. *
      amp[41] + 1./3. * amp[42] + 1./3. * amp[43] + 1./3. * amp[46] + 1./3. *
      amp[47] + std::complex<double> (0, 1) * amp[48] + std::complex<double>
      (0, 1) * amp[49] + amp[52] + amp[53] + amp[54] + std::complex<double> (0,
      1) * amp[56] + std::complex<double> (0, 1) * amp[57] + amp[60] + amp[61]
      + amp[62] + amp[66] + amp[67] + amp[70] + amp[71] + amp[74] + amp[75] +
      amp[78] + amp[79] + amp[82] + amp[83] - std::complex<double> (0, 1) *
      amp[84] - std::complex<double> (0, 1) * amp[85] + amp[87] + amp[90] +
      amp[91] - std::complex<double> (0, 1) * amp[92] - std::complex<double>
      (0, 1) * amp[93] + amp[95] + amp[96] + amp[97] + amp[98] + amp[102] +
      amp[104] + amp[105] + amp[106] + amp[110] + amp[112] + amp[113] +
      std::complex<double> (0, 1) * amp[115] + amp[116] + std::complex<double>
      (0, 1) * amp[119] + amp[120] + amp[121] + std::complex<double> (0, 1) *
      amp[123] + amp[124] + std::complex<double> (0, 1) * amp[127] + 1./3. *
      amp[130] + 1./3. * amp[131] + 1./3. * amp[134] + 1./3. * amp[135] + 1./3.
      * amp[138] + 1./3. * amp[139] + 1./3. * amp[142] + 1./3. * amp[143] +
      1./3. * amp[160] + amp[161] + 1./3. * amp[163] + amp[169] + 1./3. *
      amp[170] + amp[171] + 1./3. * amp[172] + amp[173] + 1./3. * amp[176] +
      amp[177] + 1./3. * amp[179] + amp[185] + 1./3. * amp[186] + amp[187] +
      1./3. * amp[188] + amp[189]);
  jamp[1] = +1./4. * (-1./9. * amp[2] - 1./9. * amp[3] - 1./9. * amp[4] - 1./9.
      * amp[5] - 1./9. * amp[6] - 1./9. * amp[7] - 1./9. * amp[10] - 1./9. *
      amp[11] - 1./9. * amp[12] - 1./9. * amp[13] - 1./9. * amp[14] - 1./9. *
      amp[15] - 1./9. * amp[16] - 1./9. * amp[17] - 1./9. * amp[18] - 1./9. *
      amp[19] - 1./9. * amp[20] - 1./9. * amp[21] - 1./9. * amp[22] - 1./9. *
      amp[23] - 1./9. * amp[24] - 1./9. * amp[25] - 1./9. * amp[26] - 1./9. *
      amp[27] - 1./9. * amp[28] - 1./9. * amp[29] - 1./9. * amp[30] - 1./9. *
      amp[31] - 1./9. * amp[32] - 1./9. * amp[33] - 1./9. * amp[34] - 1./9. *
      amp[35] - 1./9. * amp[38] - 1./9. * amp[39] - 1./9. * amp[40] - 1./9. *
      amp[41] - 1./9. * amp[42] - 1./9. * amp[43] - 1./9. * amp[46] - 1./9. *
      amp[47] - 1./3. * amp[64] - 1./3. * amp[65] - 1./3. * amp[66] - 1./3. *
      amp[67] - 1./3. * amp[72] - 1./3. * amp[73] - 1./3. * amp[74] - 1./3. *
      amp[75] - 1./3. * amp[80] - 1./3. * amp[81] - 1./3. * amp[82] - 1./3. *
      amp[83] - 1./3. * amp[86] - 1./3. * amp[87] - 1./3. * amp[88] - 1./3. *
      amp[89] - 1./3. * amp[90] - 1./3. * amp[91] - 1./3. * amp[94] - 1./3. *
      amp[95] - 1./3. * amp[96] - 1./3. * amp[97] - 1./3. * amp[100] - 1./3. *
      amp[101] - 1./3. * amp[104] - 1./3. * amp[105] - 1./3. * amp[108] - 1./3.
      * amp[109] - 1./3. * amp[112] - 1./3. * amp[113] - 1./3. * amp[114] -
      1./3. * amp[116] - 1./3. * amp[117] - 1./3. * amp[118] - 1./3. * amp[120]
      - 1./3. * amp[121] - 1./3. * amp[122] - 1./3. * amp[124] - 1./3. *
      amp[125] - 1./3. * amp[126] - 1./9. * amp[128] - 1./9. * amp[129] - 1./9.
      * amp[130] - 1./9. * amp[131] - 1./9. * amp[132] - 1./9. * amp[133] -
      1./9. * amp[134] - 1./9. * amp[135] - 1./9. * amp[136] - 1./9. * amp[137]
      - 1./9. * amp[138] - 1./9. * amp[139] - 1./9. * amp[140] - 1./9. *
      amp[141] - 1./9. * amp[142] - 1./9. * amp[143] - 1./9. * amp[144] - 1./9.
      * amp[145] - 1./9. * amp[146] - 1./9. * amp[148] - 1./9. * amp[149] -
      1./9. * amp[150] - 1./9. * amp[152] - 1./9. * amp[153] - 1./9. * amp[154]
      - 1./9. * amp[156] - 1./9. * amp[157] - 1./9. * amp[158] - 1./9. *
      amp[160] - 1./3. * amp[161] - 1./3. * amp[162] - 1./9. * amp[163] - 1./9.
      * amp[164] - 1./3. * amp[165] - 1./3. * amp[166] - 1./9. * amp[167] -
      1./9. * amp[168] - 1./3. * amp[169] - 1./9. * amp[170] - 1./3. * amp[171]
      - 1./9. * amp[172] - 1./3. * amp[173] - 1./3. * amp[174] - 1./9. *
      amp[175] - 1./9. * amp[176] - 1./3. * amp[177] - 1./3. * amp[178] - 1./9.
      * amp[179] - 1./9. * amp[180] - 1./3. * amp[181] - 1./3. * amp[182] -
      1./9. * amp[183] - 1./9. * amp[184] - 1./3. * amp[185] - 1./9. * amp[186]
      - 1./3. * amp[187] - 1./9. * amp[188] - 1./3. * amp[189] - 1./3. *
      amp[190] - 1./9. * amp[191]);
  jamp[2] = +1./4. * (+std::complex<double> (0, 1) * amp[0] +
      std::complex<double> (0, 1) * amp[1] - amp[2] - amp[3] - amp[7] +
      std::complex<double> (0, 1) * amp[8] + std::complex<double> (0, 1) *
      amp[9] - amp[10] - amp[11] - amp[15] - amp[16] - amp[17] - amp[20] -
      amp[21] - amp[24] - amp[25] - amp[28] - amp[29] - amp[32] - amp[33] -
      std::complex<double> (0, 1) * amp[36] - std::complex<double> (0, 1) *
      amp[37] - amp[38] - amp[40] - amp[41] - std::complex<double> (0, 1) *
      amp[44] - std::complex<double> (0, 1) * amp[45] - amp[46] - 1./3. *
      amp[50] - 1./3. * amp[51] - 1./3. * amp[52] - 1./3. * amp[53] - 1./3. *
      amp[54] - 1./3. * amp[55] - 1./3. * amp[58] - 1./3. * amp[59] - 1./3. *
      amp[60] - 1./3. * amp[61] - 1./3. * amp[62] - 1./3. * amp[63] - 1./3. *
      amp[68] - 1./3. * amp[69] - 1./3. * amp[70] - 1./3. * amp[71] - 1./3. *
      amp[76] - 1./3. * amp[77] - 1./3. * amp[78] - 1./3. * amp[79] - 1./3. *
      amp[96] - 1./3. * amp[97] - 1./3. * amp[98] - 1./3. * amp[99] - 1./3. *
      amp[100] - 1./3. * amp[101] - 1./3. * amp[102] - 1./3. * amp[103] - 1./3.
      * amp[104] - 1./3. * amp[105] - 1./3. * amp[106] - 1./3. * amp[107] -
      1./3. * amp[108] - 1./3. * amp[109] - 1./3. * amp[110] - 1./3. * amp[111]
      - 1./3. * amp[112] - 1./3. * amp[113] - 1./3. * amp[114] - 1./3. *
      amp[116] - 1./3. * amp[117] - 1./3. * amp[118] - 1./3. * amp[120] - 1./3.
      * amp[121] - 1./3. * amp[122] - 1./3. * amp[124] - 1./3. * amp[125] -
      1./3. * amp[126] - amp[131] - amp[132] - amp[133] - amp[135] - amp[139] -
      amp[140] - amp[141] - amp[143] - amp[146] + std::complex<double> (0, 1) *
      amp[147] - amp[149] - amp[150] + std::complex<double> (0, 1) * amp[151] -
      amp[154] + std::complex<double> (0, 1) * amp[155] - amp[157] - amp[158] +
      std::complex<double> (0, 1) * amp[159] - amp[163] - amp[164] - 1./3. *
      amp[165] - 1./3. * amp[166] - amp[167] - 1./3. * amp[169] - amp[172] -
      1./3. * amp[173] - amp[179] - amp[180] - 1./3. * amp[181] - 1./3. *
      amp[182] - amp[183] - 1./3. * amp[185] - amp[188] - 1./3. * amp[189]);
  jamp[3] = +1./4. * (+1./3. * amp[16] + 1./3. * amp[17] + 1./3. * amp[18] +
      1./3. * amp[19] + 1./3. * amp[24] + 1./3. * amp[25] + 1./3. * amp[26] +
      1./3. * amp[27] + 1./3. * amp[32] + 1./3. * amp[33] + 1./3. * amp[34] +
      1./3. * amp[35] + 1./3. * amp[38] + 1./3. * amp[39] + 1./3. * amp[40] +
      1./3. * amp[41] + 1./3. * amp[42] + 1./3. * amp[43] + 1./3. * amp[46] +
      1./3. * amp[47] + 1./9. * amp[50] + 1./9. * amp[51] + 1./9. * amp[52] +
      1./9. * amp[53] + 1./9. * amp[54] + 1./9. * amp[55] + 1./9. * amp[58] +
      1./9. * amp[59] + 1./9. * amp[60] + 1./9. * amp[61] + 1./9. * amp[62] +
      1./9. * amp[63] + 1./9. * amp[64] + 1./9. * amp[65] + 1./9. * amp[66] +
      1./9. * amp[67] + 1./9. * amp[68] + 1./9. * amp[69] + 1./9. * amp[70] +
      1./9. * amp[71] + 1./9. * amp[72] + 1./9. * amp[73] + 1./9. * amp[74] +
      1./9. * amp[75] + 1./9. * amp[76] + 1./9. * amp[77] + 1./9. * amp[78] +
      1./9. * amp[79] + 1./9. * amp[80] + 1./9. * amp[81] + 1./9. * amp[82] +
      1./9. * amp[83] + 1./9. * amp[86] + 1./9. * amp[87] + 1./9. * amp[88] +
      1./9. * amp[89] + 1./9. * amp[90] + 1./9. * amp[91] + 1./9. * amp[94] +
      1./9. * amp[95] + 1./9. * amp[96] + 1./9. * amp[97] + 1./9. * amp[98] +
      1./9. * amp[99] + 1./9. * amp[100] + 1./9. * amp[101] + 1./9. * amp[102]
      + 1./9. * amp[103] + 1./9. * amp[104] + 1./9. * amp[105] + 1./9. *
      amp[106] + 1./9. * amp[107] + 1./9. * amp[108] + 1./9. * amp[109] + 1./9.
      * amp[110] + 1./9. * amp[111] + 1./9. * amp[112] + 1./9. * amp[113] +
      1./9. * amp[114] + 1./9. * amp[116] + 1./9. * amp[117] + 1./9. * amp[118]
      + 1./9. * amp[120] + 1./9. * amp[121] + 1./9. * amp[122] + 1./9. *
      amp[124] + 1./9. * amp[125] + 1./9. * amp[126] + 1./3. * amp[128] + 1./3.
      * amp[129] + 1./3. * amp[132] + 1./3. * amp[133] + 1./3. * amp[136] +
      1./3. * amp[137] + 1./3. * amp[140] + 1./3. * amp[141] + 1./3. * amp[144]
      + 1./3. * amp[145] + 1./3. * amp[146] + 1./3. * amp[148] + 1./3. *
      amp[149] + 1./3. * amp[150] + 1./3. * amp[152] + 1./3. * amp[153] + 1./3.
      * amp[154] + 1./3. * amp[156] + 1./3. * amp[157] + 1./3. * amp[158] +
      1./3. * amp[160] + 1./9. * amp[161] + 1./9. * amp[162] + 1./3. * amp[163]
      + 1./3. * amp[164] + 1./9. * amp[165] + 1./9. * amp[166] + 1./3. *
      amp[167] + 1./3. * amp[168] + 1./9. * amp[169] + 1./3. * amp[170] + 1./9.
      * amp[171] + 1./3. * amp[172] + 1./9. * amp[173] + 1./9. * amp[174] +
      1./3. * amp[175] + 1./3. * amp[176] + 1./9. * amp[177] + 1./9. * amp[178]
      + 1./3. * amp[179] + 1./3. * amp[180] + 1./9. * amp[181] + 1./9. *
      amp[182] + 1./3. * amp[183] + 1./3. * amp[184] + 1./9. * amp[185] + 1./3.
      * amp[186] + 1./9. * amp[187] + 1./3. * amp[188] + 1./9. * amp[189] +
      1./9. * amp[190] + 1./3. * amp[191]);
  jamp[4] = +1./4. * (+1./3. * amp[2] + 1./3. * amp[3] + 1./3. * amp[4] + 1./3.
      * amp[5] + 1./3. * amp[6] + 1./3. * amp[7] + 1./3. * amp[10] + 1./3. *
      amp[11] + 1./3. * amp[12] + 1./3. * amp[13] + 1./3. * amp[14] + 1./3. *
      amp[15] + 1./3. * amp[20] + 1./3. * amp[21] + 1./3. * amp[22] + 1./3. *
      amp[23] + 1./3. * amp[28] + 1./3. * amp[29] + 1./3. * amp[30] + 1./3. *
      amp[31] - std::complex<double> (0, 1) * amp[48] - std::complex<double>
      (0, 1) * amp[49] + amp[50] + amp[51] + amp[55] - std::complex<double> (0,
      1) * amp[56] - std::complex<double> (0, 1) * amp[57] + amp[58] + amp[59]
      + amp[63] + amp[64] + amp[65] + amp[68] + amp[69] + amp[72] + amp[73] +
      amp[76] + amp[77] + amp[80] + amp[81] + std::complex<double> (0, 1) *
      amp[84] + std::complex<double> (0, 1) * amp[85] + amp[86] + amp[88] +
      amp[89] + std::complex<double> (0, 1) * amp[92] + std::complex<double>
      (0, 1) * amp[93] + amp[94] + amp[99] + amp[100] + amp[101] + amp[103] +
      amp[107] + amp[108] + amp[109] + amp[111] + amp[114] -
      std::complex<double> (0, 1) * amp[115] + amp[117] + amp[118] -
      std::complex<double> (0, 1) * amp[119] + amp[122] - std::complex<double>
      (0, 1) * amp[123] + amp[125] + amp[126] - std::complex<double> (0, 1) *
      amp[127] + 1./3. * amp[128] + 1./3. * amp[129] + 1./3. * amp[130] + 1./3.
      * amp[131] + 1./3. * amp[132] + 1./3. * amp[133] + 1./3. * amp[134] +
      1./3. * amp[135] + 1./3. * amp[136] + 1./3. * amp[137] + 1./3. * amp[138]
      + 1./3. * amp[139] + 1./3. * amp[140] + 1./3. * amp[141] + 1./3. *
      amp[142] + 1./3. * amp[143] + 1./3. * amp[144] + 1./3. * amp[145] + 1./3.
      * amp[146] + 1./3. * amp[148] + 1./3. * amp[149] + 1./3. * amp[150] +
      1./3. * amp[152] + 1./3. * amp[153] + 1./3. * amp[154] + 1./3. * amp[156]
      + 1./3. * amp[157] + 1./3. * amp[158] + amp[162] + 1./3. * amp[164] +
      amp[165] + amp[166] + 1./3. * amp[167] + 1./3. * amp[168] + amp[174] +
      1./3. * amp[175] + amp[178] + 1./3. * amp[180] + amp[181] + amp[182] +
      1./3. * amp[183] + 1./3. * amp[184] + amp[190] + 1./3. * amp[191]);
  jamp[5] = +1./4. * (-std::complex<double> (0, 1) * amp[0] -
      std::complex<double> (0, 1) * amp[1] - amp[4] - amp[5] - amp[6] -
      std::complex<double> (0, 1) * amp[8] - std::complex<double> (0, 1) *
      amp[9] - amp[12] - amp[13] - amp[14] - amp[18] - amp[19] - amp[22] -
      amp[23] - amp[26] - amp[27] - amp[30] - amp[31] - amp[34] - amp[35] +
      std::complex<double> (0, 1) * amp[36] + std::complex<double> (0, 1) *
      amp[37] - amp[39] - amp[42] - amp[43] + std::complex<double> (0, 1) *
      amp[44] + std::complex<double> (0, 1) * amp[45] - amp[47] - 1./3. *
      amp[50] - 1./3. * amp[51] - 1./3. * amp[52] - 1./3. * amp[53] - 1./3. *
      amp[54] - 1./3. * amp[55] - 1./3. * amp[58] - 1./3. * amp[59] - 1./3. *
      amp[60] - 1./3. * amp[61] - 1./3. * amp[62] - 1./3. * amp[63] - 1./3. *
      amp[64] - 1./3. * amp[65] - 1./3. * amp[66] - 1./3. * amp[67] - 1./3. *
      amp[68] - 1./3. * amp[69] - 1./3. * amp[70] - 1./3. * amp[71] - 1./3. *
      amp[72] - 1./3. * amp[73] - 1./3. * amp[74] - 1./3. * amp[75] - 1./3. *
      amp[76] - 1./3. * amp[77] - 1./3. * amp[78] - 1./3. * amp[79] - 1./3. *
      amp[80] - 1./3. * amp[81] - 1./3. * amp[82] - 1./3. * amp[83] - 1./3. *
      amp[86] - 1./3. * amp[87] - 1./3. * amp[88] - 1./3. * amp[89] - 1./3. *
      amp[90] - 1./3. * amp[91] - 1./3. * amp[94] - 1./3. * amp[95] - 1./3. *
      amp[98] - 1./3. * amp[99] - 1./3. * amp[102] - 1./3. * amp[103] - 1./3. *
      amp[106] - 1./3. * amp[107] - 1./3. * amp[110] - 1./3. * amp[111] -
      amp[128] - amp[129] - amp[130] - amp[134] - amp[136] - amp[137] -
      amp[138] - amp[142] - amp[144] - amp[145] - std::complex<double> (0, 1) *
      amp[147] - amp[148] - std::complex<double> (0, 1) * amp[151] - amp[152] -
      amp[153] - std::complex<double> (0, 1) * amp[155] - amp[156] -
      std::complex<double> (0, 1) * amp[159] - amp[160] - 1./3. * amp[161] -
      1./3. * amp[162] - amp[168] - amp[170] - 1./3. * amp[171] - 1./3. *
      amp[174] - amp[175] - amp[176] - 1./3. * amp[177] - 1./3. * amp[178] -
      amp[184] - amp[186] - 1./3. * amp[187] - 1./3. * amp[190] - amp[191]);

  // Sum and square the color flows to get the matrix element
  double matrix = 0; 
  for(i = 0; i < ncolor; i++ )
  {
    ztemp = 0.; 
    for(j = 0; j < ncolor; j++ )
      ztemp = ztemp + cf[i][j] * jamp[j]; 
    matrix = matrix + real(ztemp * conj(jamp[i]))/denom[i]; 
  }

  // Store the leading color flows for choice of color
  for(i = 0; i < ncolor; i++ )
    jamp2[0][i] += real(jamp[i] * conj(jamp[i])); 

  return matrix; 
}



