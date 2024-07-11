
#include <iostream>
#include <random>
#include <algorithm>
#include <chrono>

using namespace std;
using namespace std::chrono;

int main(int argc, char **argv){
    srand(0);


const int N = atoi(argv[1]);
double **B = new double*[N];
for (size_t i = 0; i < N; ++i) {
B[i] = new double[N];

for (size_t j = 0; j < N; ++j) {
int flag1 = 0 <= i && N > i && 0 <= j && N > j && i == j;
if (flag1) {
B[i][j] = (double) (rand() % 1000000) / 1e6;
} else {
B[i][j] = 0.0;
}
}
}
double f = (double) (rand() % 1000000) / 1e6;
double **A = new double*[N];
for (size_t i = 0; i < N; ++i) {
A[i] = new double[N];

for (size_t j = 0; j < N; ++j) {
A[i][j] = 0.0;
}
}
double **C = new double*[N];
for (size_t i = 0; i < N; ++i) {
C[i] = new double[N];

for (size_t j = 0; j < N; ++j) {
C[i][j] = 0.0;
}
}
double **X = new double*[N];
for (size_t i = 0; i < N; ++i) {
X[i] = new double[N];

for (size_t j = 0; j < N; ++j) {
X[i][j] = 0.0;
}
}
double **D = new double*[N];
for (size_t i = 0; i < N; ++i) {
D[i] = new double[N];

for (size_t j = 0; j < N; ++j) {
D[i][j] = 0.0;
}
}

long time_computation = 0, start_computation, end_computation;
start_computation = duration_cast<microseconds>(system_clock::now().time_since_epoch()).count();
for (int i = 0; i < N; ++i) {

int j = i;
A[i][j] += (1. / f * 1. / 5 * 1. / B[i][i]);
}
for (int i = 0; i < N; ++i) {

int j = i;
C[i][j] += (f * 5 * B[i][i]);
}
for (int i = 0; i < N; ++i) {

int j = i;
X[i][j] += (1. / f * 1. / 5 * 1. / B[i][i]);
}
for (int i = 0; i < N; ++i) {

int j = i;
D[i][j] += (B[i][i] * 1. / B[i][i]);
}
end_computation = duration_cast<microseconds>(system_clock::now().time_since_epoch()).count();
time_computation = end_computation - start_computation;
cout << time_computation << endl;
long time_reconstruction = 0, start_reconstruction, end_reconstruction;
start_reconstruction = duration_cast<microseconds>(system_clock::now().time_since_epoch()).count();




end_reconstruction = duration_cast<microseconds>(system_clock::now().time_since_epoch()).count();
time_reconstruction = end_reconstruction - start_reconstruction;
cout << time_reconstruction << endl;
cerr << A[0][0] << endl;
cerr << B[0][0] << endl;
cerr << 5 << endl;
cerr << f << endl;
cerr << C[0][0] << endl;
cerr << X[0][0] << endl;
cerr << D[0][0] << endl;
for (size_t i0 = 0; i0 < N; ++i0) {delete[] A[i0];
}delete[] A;
for (size_t i0 = 0; i0 < N; ++i0) {delete[] B[i0];
}delete[] B;
for (size_t i0 = 0; i0 < N; ++i0) {delete[] C[i0];
}delete[] C;
for (size_t i0 = 0; i0 < N; ++i0) {delete[] X[i0];
}delete[] X;
for (size_t i0 = 0; i0 < N; ++i0) {delete[] D[i0];
}delete[] D;
return 0;
}