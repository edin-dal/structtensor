
#include <iostream>
#include <random>
#include <algorithm>
#include <chrono>

using namespace std;
using namespace std::chrono;

int main(int argc, char **argv){
    srand(0);


const int W = atoi(argv[1]);

double *A = new double[W];
for (size_t i = 0; i < W; ++i) {
int flag1 = 0 <= i && W > i;
if (flag1) {
A[i] = (double) 1.0;
} else {
A[i] = 0.0;
}
}

double **B = new double*[W];
for (size_t i = 0; i < W; ++i) {
B[i] = new double[W];
for (size_t j = 0; j < W; ++j) {
int flag2 = 0 <= i && W > i && 0 <= j && W > j && 0 == i && 0 <= j && W > j || 0 <= i && W > i && 0 <= j && W > j && 1 <= i && W > i && (i - 1) == j;
if (flag2) {
B[i][j] = (double) 1.0;
} else {
B[i][j] = 0.0;
}
}
}

double *C = new double[W];
for (size_t j = 0; j < W; ++j) {
int flag3 = 0 <= j && W > j;
if (flag3) {
C[j] = (double) 1.0;
} else {
C[j] = 0.0;
}
}

long time = 0, start, end;
start = duration_cast<microseconds>(system_clock::now().time_since_epoch()).count();



int i = 0;
if (0 < W) {
double tmp = 0.0;

auto &cm4 = B[i];

for (int j = 0; j < W; ++j) {


tmp += (cm4[j] * C[j]);
}
A[i] += tmp;
}



for (int i = 1; i < W; ++i) {
double tmp = 0.0;

auto &cm5 = B[i];




tmp += (cm5[(i - 1)] * C[(i - 1)]);
A[i] += tmp;
}

end = duration_cast<microseconds>(system_clock::now().time_since_epoch()).count();
time = end - start;
cout << time << endl;
cerr << A[0] << endl;
cerr << B[0][0] << endl;
cerr << C[0] << endl;
delete[] A;
for (size_t i0 = 0; i0 < W; ++i0) {
delete[] B[i0];
}
delete[] B;
delete[] C;
return 0;
}