/**
    signalDetector.cc
    Purpose: Calculate the correlation of sample and predicted signal

    Description: This prject is designed to import deifferent signals from NetCDF files as well as the main
    signal then computes Fourier Transform of all signals by using FFT Method. Having computed Power Spectrum
    of all signals, correlation of the signals will be computed and finally the all of the sample signals 
    will be ranked in terms of how strongly they are correlated to the Predicted signal.

    @author Erfan Pirmorad
    @version 1.0 08/03/2020 
*/

#include <iostream>
#include <string>
#include <rarray>
#include "sizeGet.h"
#include "readingNCfile.h"
#include "FFTCompute.h"
#include "PowerSpectrum.h"
#include "Correlation.h"
#include "sorting.h"

using namespace std;

// Main driver function of signalDetector.cc

int main(int argc, char *argv[])
{
    // ====================== parameters  ==================== //    

    int total_fileNumber = 32;                                  // Total Number of files in which the sample signals were saved
    double size = sizeGetter();                                 // Size of the time-series signals in sample signals
    double* Correlations;                                       // Correlation array in which the correlation of each signal will be saved
    Correlations = new double[total_fileNumber+1];              
    
    // ===================== define arrays  ================== //
    
    rvector<std::complex<double>> f_predict(size);              // Complex rvector of prediction signal
    rvector<std::complex<double>> f_predict_hat(size);          // Complex rvector of Fourier transforeed prediction signal
    rvector<std::complex<double>> f(size);                      // Complex rvector of sample signals
    rvector<std::complex<double>> f_hat(size);                  // Complex rvector of Fourier transforeed sample signals
    rvector<double> F(size);                                    // Real rvector of sample signals Power Spectrum
    rvector<double> G(size);                                    // Real rvector of predicted signals Power Spectrum

    // ===================== Working with Predicted Signal ================== //

    readPredict(f_predict, size);                               // reading the predicted signal
    computeFFT(f_predict, f_predict_hat);                       // computing FFT of predicted signal
    computePSD(f_predict_hat, G);                               // computing PS of predicted signal
    
    // ===================== Working with Sample Signal ================== //    

    for (int fileNumber = 1; fileNumber <= total_fileNumber; fileNumber++) {
        
        readSample(f, fileNumber, size);                        // reading the sample signal
        computeFFT(f, f_hat);                                   // computing FFT of sample signal
        computePSD(f_hat, F);                                   // computing PS of sample signal
        Correlations[fileNumber] = computeCorr(F, G);           // saving Correlation value
    }
    sortArray(Correlations, total_fileNumber+1);                // Ranking and Printing in terms of correlation
    delete [] Correlations;
    return 0;
}             

