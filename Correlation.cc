/**
    Correlation.cc
    Purpose: computing correlation of two signals 

    Description: This module of the code computes correlation of two signals that one of them is 
    sample signal and the other is the one unique predited signal. Cblas library is used to dot 
    product two verctors for computing correlation. 


    @author Erfan Pirmorad
    @version 1.0 08/03/2020 
*/

#include "Correlation.h"
#include <rarray>
#include <cblas.h>
#include <cmath>

double computeCorr(const rvector<double>& F, const rvector<double>& G ){

    int n = F.size();
    double* F_,* G_;
    F_ = new double[n];
    G_ = new double[n];
    double varF, varG, covFG;
    double Corr;

    for(int i=0; i<n; i++){
         F_[i] = F[i];
         G_[i] = G[i];
    }
    
    varF = cblas_ddot(n, F, 1, F, 1);
    varG = cblas_ddot(n, G, 1, G, 1);
    covFG = cblas_ddot(n, F, 1, G, 1);

    Corr  = covFG / sqrt(varF * varG);

    delete [] F_, G_;

    return Corr;  
}
