#ifndef FFTCOMPUTE_H
#define FFTCOMPUTE_H
#include <rarray>
#include <complex>
#include <fftw3.h>

void computeFFT(const rvector<std::complex<double>>& f, rvector<std::complex<double>>& fhat);

#endif

 
 