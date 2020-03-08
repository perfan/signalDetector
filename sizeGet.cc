/**
    sorting.cc
    Purpose: Getting the size of time series signals from the parent directory 

    @author Erfan Pirmorad
    @version 1.0 08/03/2020 
*/

#include "sizeGet.h"
#include <fstream>
#include <string>
#include <netcdf>

using namespace netCDF;
using namespace std;

int sizeGetter(){

	string file_path = "/scinet/course/phy1610/gwdata/";
	string file_name = "GWprediction";
	string extension = ".nc";
	double size;

	NcFile ncfile(file_path + file_name + extension, NcFile::read);
	size = ncfile.getDim("nt").getSize();
    return size;

}

