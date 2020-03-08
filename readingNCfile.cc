/**
    readingNCfile.cc
    Purpose: Reading signal arrays from the saved NetCDF files 

    Description: This module of the code reads the arrays of signals from the target directory. 


    @author Erfan Pirmorad
    @version 1.0 08/03/2020 
*/


#include "readingNCfile.h"
#include <rarray>
#include <rarrayio>
#include <fstream>
#include <string>
#include <netcdf>

using namespace netCDF;
using namespace std;

// Reading sample signals from the directory in which they were saved  
void readSample(rvector<std::complex<double>>& f, int number, double size){

	string file_path = "/scinet/course/phy1610/gwdata/";						
	string file_name = "detection";
	string file_number = number < 10 ? "0" +to_string(number) : to_string(number);
	string extension = ".nc";

	NcFile ncfile(file_path + file_name + file_number + extension, NcFile::read);
 	ncfile.getVar("f").getVar(f.data());
}

// Reading predicted signals from the directory in which they were saved  
void readPredict(rvector<std::complex<double>>& f, double size){

	string file_path = "/scinet/course/phy1610/gwdata/";
	string file_name = "GWprediction";
	string extension = ".nc";

	NcFile ncfile(file_path + file_name + extension, NcFile::read);
 	ncfile.getVar("f").getVar(f.data()); 
}

