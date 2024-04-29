
#include <iostream>
#include <random>
#include <algorithm>
#include <chrono>

using namespace std;
using namespace std::chrono;

int main(int argc, char **argv){
    srand(0);


const int N = atoi(argv[1]);

double **A = new double*[N];
for (size_t i = 0; i < N; ++i) {
A[i] = new double[N];
for (size_t j = 0; j < N; ++j) {
int flag1 = 0 <= i && N > i && 0 <= j && N > j;
if (flag1) {
A[i][j] = (double) 1.0;
} else {
A[i][j] = 0.0;
}
}
}

double *f = new double[N];
for (size_t i = 0; i < N; ++i) {
int flag2 = 0 <= i && N > i;
if (flag2) {
f[i] = (double) 1.0;
} else {
f[i] = 0.0;
}
}

double **B = new double*[N];
for (size_t i = 0; i < N; ++i) {
B[i] = new double[N];
for (size_t j = 0; j < N; ++j) {
int flag3 = 0 <= i && N > i && 0 <= j && N > j;
if (flag3) {
B[i][j] = (double) 1.0;
} else {
B[i][j] = 0.0;
}
}
}

double *g = new double[N];
for (size_t i = 0; i < N; ++i) {
int flag4 = 0 <= i && N > i;
if (flag4) {
g[i] = (double) 1.0;
} else {
g[i] = 0.0;
}
}

double **C = new double*[N];
for (size_t i = 0; i < N; ++i) {
C[i] = new double[N];
for (size_t j = 0; j < N; ++j) {
int flag5 = 0 <= i && N > i && 0 <= j && N > j;
if (flag5) {
C[i][j] = (double) 1.0;
} else {
C[i][j] = 0.0;
}
}
}

long time = 0, start, end;
start = duration_cast<microseconds>(system_clock::now().time_since_epoch()).count();



for (int i = 0; i < N; ++i) {
auto &cm6 = A[i];

auto &cm7 = f[i];

for (int j = i; j < N; ++j) {


cm6[j] += (f[j] * cm7);
}
}




for (int i = 0; i < N; ++i) {
auto &cm10 = B[i];

auto &cm11 = g[i];

for (int j = i; j < N; ++j) {


cm10[j] += (cm11 * g[j]);
}
}




for (int i = 0; i < N; ++i) {
auto &cm14 = C[i];

auto &cm15 = f[i];
auto &cm16 = g[i];

for (int j = i; j < N; ++j) {
double tmp = 0.0;



tmp += (f[j] * cm15);

tmp += (cm16 * g[j]);

cm14[j] += tmp;
}
}

end = duration_cast<microseconds>(system_clock::now().time_since_epoch()).count();
time = end - start;
cout << time << endl;
cerr << A[0][0] << endl;
cerr << f[0] << endl;
cerr << f[0] << endl;
cerr << B[0][0] << endl;
cerr << g[0] << endl;
cerr << g[0] << endl;
cerr << C[0][0] << endl;
for (size_t i0 = 0; i0 < N; ++i0) {
delete[] A[i0];
}
delete[] A;
delete[] f;
for (size_t i0 = 0; i0 < N; ++i0) {
delete[] B[i0];
}
delete[] B;
delete[] g;
for (size_t i0 = 0; i0 < N; ++i0) {
delete[] C[i0];
}
delete[] C;
return 0;
}