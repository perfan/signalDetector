/**
    PowerSpectrum.cc
    Purpose: computing Power Spectrum of signals 

    Description: This module of the code computes PSD of a signal bu computing the norm of them.


    @author Erfan Pirmorad
    @version 1.0 08/03/2020 
*/

#include "PowerSpectrum.h"
#include <rarray>
#include <complex>
#include <iostream>

void computePSD(rvector<std::complex<double>>& f, rvector<double>& F){

    for (int i =1; i<f.size(); i++){
        F[i] = std::norm(f[i]) * std::norm(f[i]);
    }
}

