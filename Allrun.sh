#!/bin/sh

module load gcc rarray hdf5 netcdf fftw
export  LD_LIBRARY_PATH=${LD_LIBRARY_PATH}:/home/b/bussmann/perfan/src/openBlas/lib
make clean
make all
./signalDetector > signalRanking.dat