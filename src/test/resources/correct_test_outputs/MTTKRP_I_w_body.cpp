
#include <iostream>
#include <random>
#include <algorithm>
#include <chrono>

using namespace std;
using namespace std::chrono;

int main(int argc, char **argv){
    srand(0);


const int M = atoi(argv[1]);
const int N = atoi(argv[2]);
const int P = atoi(argv[3]);
const int Q = atoi(argv[4]);
const int I = atoi(argv[5]);
double ***B = new double**[M];
for (size_t i = 0; i < M; ++i) {
B[i] = new double*[N];

for (size_t k = 0; k < N; ++k) {
B[i][k] = new double[P];

for (size_t l = 0; l < P; ++l) {
int flag1 = 0 <= i && M > i && 0 <= k && N > k && 0 <= l && P > l && i == I;
if (flag1) {
B[i][k][l] = (double) (rand() % 1000000) / 1e6;
} else {
B[i][k][l] = 0.0;
}
}
}
}
double **C = new double*[N];
for (size_t k = 0; k < N; ++k) {
C[k] = new double[Q];

for (size_t j = 0; j < Q; ++j) {
int flag2 = 0 <= k && N > k && 0 <= j && Q > j;
if (flag2) {
C[k][j] = (double) (rand() % 1000000) / 1e6;
} else {
C[k][j] = 0.0;
}
}
}
double **D = new double*[P];
for (size_t l = 0; l < P; ++l) {
D[l] = new double[Q];

for (size_t j = 0; j < Q; ++j) {
int flag3 = 0 <= l && P > l && 0 <= j && Q > j;
if (flag3) {
D[l][j] = (double) (rand() % 1000000) / 1e6;
} else {
D[l][j] = 0.0;
}
}
}
double **A = new double*[M];
for (size_t i = 0; i < M; ++i) {
A[i] = new double[Q];

for (size_t j = 0; j < Q; ++j) {
A[i][j] = 0.0;
}
}

long time_computation = 0, start_computation, end_computation;
start_computation = duration_cast<microseconds>(system_clock::now().time_since_epoch()).count();
int i = I;
if (i >= 0 && i < M) {
for (int j = 0; j < Q; ++j) {

for (int k = 0; k < N; ++k) {

for (int l = 0; l < P; ++l) {

A[i][j] += (B[i][k][l] * C[k][j] * D[l][j]);
}
}
}
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
cerr << B[0][0][0] << endl;
cerr << C[0][0] << endl;
cerr << D[0][0] << endl;
for (size_t i0 = 0; i0 < M; ++i0) {delete[] A[i0];
}delete[] A;
for (size_t i0 = 0; i0 < M; ++i0) {
for (size_t i1 = 0; i1 < N; ++i1) {delete[] B[i0][i1];
}
delete[] B[i0];
}delete[] B;
for (size_t i0 = 0; i0 < N; ++i0) {delete[] C[i0];
}delete[] C;
for (size_t i0 = 0; i0 < P; ++i0) {delete[] D[i0];
}delete[] D;
return 0;
}