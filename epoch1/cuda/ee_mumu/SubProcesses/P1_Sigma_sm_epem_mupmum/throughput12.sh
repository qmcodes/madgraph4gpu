#!/bin/bash

clang=0
if [ "$(basename ${CXX})" == "clang++" ]; then 
  clang=1
fi

omp=0
if [ "$1" == "-omp" ]; then
  omp=1
  shift
fi

avxall=0
if [ "$1" == "-avxall" ]; then
  if [ "$clang" == "0" ]; then
    avxall=1
  else
    echo "WARNING! option '-avxall' is ignored for clang builds"
  fi
  shift
fi

if [ "$1" != "" ]; then
  echo "Usage: $0 [-omp] [-avxall]"
  exit 1
fi

exes=
exes="$exes ../../../../../epoch1/cuda/ee_mumu/SubProcesses/P1_Sigma_sm_epem_mupmum/build.none/check.exe"
exes="$exes ../../../../../epoch1/cuda/ee_mumu/SubProcesses/P1_Sigma_sm_epem_mupmum/build.none/gcheck.exe"
if [ "${avxall}" == "1" ]; then 
  exes="$exes ../../../../../epoch1/cuda/ee_mumu/SubProcesses/P1_Sigma_sm_epem_mupmum/build.sse4/check.exe"
  exes="$exes ../../../../../epoch1/cuda/ee_mumu/SubProcesses/P1_Sigma_sm_epem_mupmum/build.avx2/check.exe"
fi
if [ "$clang" == "0" ]; then
  exes="$exes ../../../../../epoch1/cuda/ee_mumu/SubProcesses/P1_Sigma_sm_epem_mupmum/build.512y/check.exe"
fi
if [ "${avxall}" == "1" ]; then 
  exes="$exes ../../../../../epoch1/cuda/ee_mumu/SubProcesses/P1_Sigma_sm_epem_mupmum/build.512z/check.exe"
fi
exes="$exes ../../../../../epoch2/cuda/ee_mumu/SubProcesses/P1_Sigma_sm_epem_mupmum/check.exe"
exes="$exes ../../../../../epoch2/cuda/ee_mumu/SubProcesses/P1_Sigma_sm_epem_mupmum/gcheck.exe"

export USEBUILDDIR=1
pushd ../../../../../epoch1/cuda/ee_mumu/SubProcesses/P1_Sigma_sm_epem_mupmum >& /dev/null
  pwd
  make AVX=none
  if [ "${avxall}" == "1" ]; then make AVX=sse4; fi
  if [ "${avxall}" == "1" ]; then make AVX=avx2; fi
  if [ "$clang" == "0" ]; then make AVX=512y; fi
  if [ "${avxall}" == "1" ]; then make AVX=512z; fi
popd >& /dev/null

pushd ../../../../../epoch2/cuda/ee_mumu/SubProcesses/P1_Sigma_sm_epem_mupmum >& /dev/null
  pwd
  make
popd >& /dev/null

pattern="Process|fptype_sv|OMP threads|EvtsPerSec\[Matrix|MeanMatrix|FP precision|TOTAL       :"
if [ "$clang" != "0" ]; then pattern="${pattern}|compiler"; fi
pattern="(${pattern})"

for exe in $exes; do
  echo "-------------------------------------------------------------------------"
  unset OMP_NUM_THREADS
  # For TIMEFORMAT see https://www.gnu.org/software/bash/manual/html_node/Bash-Variables.html
  TIMEFORMAT=$'real\t%3lR' && time $exe -p 2048 256 12 2>&1 | egrep "$pattern"
  if [ "${exe%%/check*}" != "${exe}" ]; then 
    obj=${exe%%/check*}/CPPProcess.o; ./simdSymSummary.sh -stripdir ${obj}
    if [ "${omp}" == "1" ]; then 
      echo "-------------------------------------------------------------------------"
      export OMP_NUM_THREADS=$(nproc --all)
      TIMEFORMAT=$'real\t%3lR' && time $exe -p 2048 256 12 2>&1 | egrep "$pattern"
    fi
  elif [ "${exe%%/gcheck*}" != "${exe}" ]; then 
    ###sudo LD_LIBRARY_PATH=${LD_LIBRARY_PATH} $(which ncu) --metrics launch__registers_per_thread --target-processes all -k "sigmaKinE" --kernel-regex-base mangled --print-kernel-base mangled $exe -p 2048 256 1 | egrep '(sigmaKin|registers)' | tr "\n" " " | awk '{print $1, $2, $3, $15, $17}'
    $(which ncu) --metrics launch__registers_per_thread --target-processes all -k "sigmaKinE" --kernel-regex-base mangled --print-kernel-base mangled $exe -p 2048 256 1 | egrep '(sigmaKin|registers)' | tr "\n" " " | awk '{print $1, $2, $3, $15, $17}'
  fi
done
echo "-------------------------------------------------------------------------"
