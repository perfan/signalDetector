# Makefile

CXX = g++
CXXFLAGS = -std=c++14 -O3 -march=native
NETCDF_LIB = ${SCINET_NETCDF_ROOT}/lib
NETCDF_INC = ${SCINET_NETCDF_ROOT}/include
OPENBLAS_LIB = /home/b/bussmann/perfan/src/openBlas/lib
OPENBLAS_INC = /home/b/bussmann/perfan/src/openBlas/include

all: signalDetector

signalDetector: sizeGet.o readingNCfile.o FFTCompute.o PowerSpectrum.o Correlation.o sorting.o signalDetector.o
	${CXX} -L${OPENBLAS_LIB} -L${NETCDF_LIB} sizeGet.o readingNCfile.o FFTCompute.o PowerSpectrum.o Correlation.o sorting.o signalDetector.o -o signalDetector -lnetcdf_c++4 -lfftw3 -lopenblas

signalDetector.o: signalDetector.cc
	${CXX} ${CXXFLAGS} signalDetector.cc -c -o signalDetector.o

sizeGet.o: sizeGet.cc sizeGet.h
	${CXX} ${CXXFLAGS} -I${NETCDF_INC} sizeGet.cc -c -o sizeGet.o

readingNCfile.o: readingNCfile.cc readingNCfile.h
	${CXX} ${CXXFLAGS} -I${NETCDF_INC} readingNCfile.cc -c -o readingNCfile.o

FFTCompute.o: FFTCompute.cc FFTCompute.h
	${CXX} ${CXXFLAGS} FFTCompute.cc -c -o FFTCompute.o

PowerSpectrum.o: PowerSpectrum.cc PowerSpectrum.h
	${CXX} ${CXXFLAGS} PowerSpectrum.cc -c -o PowerSpectrum.o

Correlation.o: Correlation.cc Correlation.h
	${CXX} ${CXXFLAGS} -I${OPENBLAS_INC} Correlation.cc -c -o Correlation.o

sorting.o: sorting.cc sorting.h
	${CXX} ${CXXFLAGS} sorting.cc -c -o sorting.o

clean:
	rm -rf *.o *.dat
