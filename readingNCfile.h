#ifndef READINGNCFILE_H
#define READINGNCFILE_H
#include <rarray>
#include <complex>

void readSample(rvector<std::complex<double>>& f, int number, double size);
void readPredict(rvector<std::complex<double>>& f, double size);

#endif
