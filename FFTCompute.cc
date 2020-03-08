/**
    FFTCompute.cc
    Purpose: computing FFT of signals 

    Description: This module of the code computes FFT of signal vectors by taking advantage of fftw library. 


    @author Erfan Pirmorad
    @version 1.0 08/03/2020 
*/

#include "FFTCompute.h"
#include <rarray>
#include <complex>
#include <fftw3.h>
#include <iostream>

using namespace std;

void computeFFT(const rvector<std::complex<double>>& f, rvector<std::complex<double>>& fhat){
    
    int n = f.size();
    fftw_complex *in, *out;

    complex<double> f_[n], fhat_[n];
    
    for(int i=0; i<n; i++)
         f_[i] = f[i];

    fftw_plan p = fftw_plan_dft_1d(n, (fftw_complex*) f_, (fftw_complex*) fhat_, FFTW_FORWARD, FFTW_ESTIMATE);
    fftw_execute(p);
    fftw_destroy_plan(p);
    fftw_free(in); fftw_free(out);

    for(int i=0; i<n; i++){
         fhat[i] = fhat_[i];
    }
}

