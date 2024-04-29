
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

double ***B = new double**[N];
for (size_t i = 0; i < N; ++i) {
B[i] = new double*[N];
for (size_t j = 0; j < N; ++j) {
B[i][j] = new double[N];
for (size_t k = 0; k < N; ++k) {
int flag3 = 0 <= i && N > i && 0 <= j && N > j && 0 <= k && N > k;
if (flag3) {
B[i][j][k] = (double) 1.0;
} else {
B[i][j][k] = 0.0;
}
}
}
}

double ****C = new double***[N];
for (size_t i = 0; i < N; ++i) {
C[i] = new double**[N];
for (size_t j = 0; j < N; ++j) {
C[i][j] = new double*[N];
for (size_t k = 0; k < N; ++k) {
C[i][j][k] = new double[N];
for (size_t l = 0; l < N; ++l) {
int flag4 = 0 <= i && N > i && 0 <= j && N > j && 0 <= k && N > k && 0 <= l && N > l;
if (flag4) {
C[i][j][k][l] = (double) 1.0;
} else {
C[i][j][k][l] = 0.0;
}
}
}
}
}

long time = 0, start, end;
start = duration_cast<microseconds>(system_clock::now().time_since_epoch()).count();



for (int i = 0; i < N; ++i) {
auto &cm5 = A[i];

auto &cm6 = f[i];

for (int j = i; j < N; ++j) {


cm5[j] += (f[j] * cm6);
}
}




for (int i = 0; i < N; ++i) {
auto &cm9 = B[i];

auto &cm10 = f[i];

for (int j = 0; j < N; ++j) {
auto &cm11 = cm9[j];

auto &cm12 = f[j];

for (int k = j; k < std::min({N, (i + 1)}); ++k) {


cm11[k] += (f[k] * cm12 * cm10);
}
}
}




for (int i = 0; i < N; ++i) {
auto &cm33 = C[i];

auto &cm34 = f[i];

for (int j = 0; j < N; ++j) {
auto &cm35 = cm33[j];

auto &cm36 = f[j];

for (int k = j; k < N; ++k) {
auto &cm37 = cm35[k];

auto &cm38 = f[k];

for (int l = k; l < std::min({N, (i + 1)}); ++l) {


cm37[l] += (cm38 * cm34 * f[l] * cm36);
}
}
}
}

end = duration_cast<microseconds>(system_clock::now().time_since_epoch()).count();
time = end - start;
cout << time << endl;
cerr << A[0][0] << endl;
cerr << f[0] << endl;
cerr << f[0] << endl;
cerr << B[0][0][0] << endl;
cerr << f[0] << endl;
cerr << C[0][0][0][0] << endl;
cerr << f[0] << endl;
for (size_t i0 = 0; i0 < N; ++i0) {
delete[] A[i0];
}
delete[] A;
delete[] f;
for (size_t i0 = 0; i0 < N; ++i0) {
for (size_t i1 = 0; i1 < N; ++i1) {
delete[] B[i0][i1];
}
delete[] B[i0];
}
delete[] B;
for (size_t i0 = 0; i0 < N; ++i0) {
for (size_t i1 = 0; i1 < N; ++i1) {
for (size_t i2 = 0; i2 < N; ++i2) {
delete[] C[i0][i1][i2];
}
delete[] C[i0][i1];
}
delete[] C[i0];
}
delete[] C;
return 0;
}