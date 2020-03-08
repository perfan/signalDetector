/**
    sorting.cc
    Purpose: Sorting the correlation of related to each signal file 

    Description: This part was designed to sort all of the calculated correlations and rank them.

    @author Erfan Pirmorad
    @version 1.0 08/03/2020 
*/


#include "sorting.h"
#include <bits/stdc++.h> 
#include <iostream>
#include <string>

using namespace std; 
  
void sortArray(double arr[], int n) 
{ 
  
    // Vector to store element 
    // with respective present index 
    vector<pair<double, double> > vp; 
  
    // Inserting element in pair vector 
    // to keep track of previous indexes 
    for (int i = 1; i <= n; ++i) { 
        vp.push_back(make_pair(arr[i], i)); 
    } 
  
    // Sorting pair vector 
    sort(vp.begin(), vp.end()); 
  
    // Displaying sorted element 
    // with previous indexes 
    // corresponding to each element 
    
    cout << left << setw(25) << "File name" << setw(25) << "Correlation Value" << setw(25) << "Ranking with respect to Correlation" << endl; 
    string filenumber;
    int j;
    for (int i = 1; i < n; i++) { 
        j = 33 - i;
        filenumber = vp[j].second < 10 ? "0" + to_string((int)vp[j].second) : to_string((int)vp[j].second);
        cout << left << setw(25) << "detection" + filenumber << setw(25) << vp[j].first << setw(25) << i << endl; 
    } 
} 