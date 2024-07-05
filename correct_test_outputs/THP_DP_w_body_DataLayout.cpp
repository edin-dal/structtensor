
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
double ***B = new double**[M];
for (size_t i = 0; i < M; ++i) {
B[i] = new double*[N];

for (size_t j = 0; j < N; ++j) {
B[i][j] = new double[P];

for (size_t k = 0; k < P; ++k) {
int flag127 = 0 <= i && M > i && 0 <= j && N > j && 0 <= k && P > k && i == j;
if (flag127) {
B[i][j][k] = (double) (rand() % 1000000) / 1e6;
} else {
B[i][j][k] = 0.0;
}
}
}
}
double ***C = new double**[M];
for (size_t i = 0; i < M; ++i) {
C[i] = new double*[N];

for (size_t j = 0; j < N; ++j) {
C[i][j] = new double[P];

for (size_t k = 0; k < P; ++k) {
int flag128 = 0 <= i && M > i && 0 <= j && N > j && 0 <= k && P > k;
if (flag128) {
C[i][j][k] = (double) (rand() % 1000000) / 1e6;
} else {
C[i][j][k] = 0.0;
}
}
}
}
double **B2 = new double*[M];
for (size_t i = 0; i < M; ++i) {
B2[i] = new double[P];

for (size_t k = 0; k < P; ++k) {
B2[i][k] = 0.0;
}
}
double ***A = new double**[M];
for (size_t i = 0; i < M; ++i) {
A[i] = new double*[N];

for (size_t j = 0; j < N; ++j) {
A[i][j] = new double[P];

for (size_t k = 0; k < P; ++k) {
A[i][j][k] = 0.0;
}
}
}
for (int i = 0; i < min({M, N}); ++i) {

for (int k = 0; k < P; ++k) {

B2[i][k] += B[i][i][k];
}
}
long time_computation = 0, start_computation, end_computation;
start_computation = duration_cast<microseconds>(system_clock::now().time_since_epoch()).count();
for (int i = 0; i < min({M, N}); ++i) {

int j = i;
for (int k = 0; k < P; ++k) {

A[i][j][k] += (B2[i][k] * C[i][i][k]);
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
cerr << B2[0][0] << endl;
cerr << B[0][0][0] << endl;
cerr << A[0][0][0] << endl;
cerr << C[0][0][0] << endl;
for (size_t i0 = 0; i0 < P; ++i0) {delete[] B2[i0];
}delete[] B2;
for (size_t i0 = 0; i0 < N; ++i0) {
for (size_t i1 = 0; i1 < P; ++i1) {delete[] B[i0][i1];
}
delete[] B[i0];
}delete[] B;
for (size_t i0 = 0; i0 < N; ++i0) {
for (size_t i1 = 0; i1 < P; ++i1) {delete[] A[i0][i1];
}
delete[] A[i0];
}delete[] A;
for (size_t i0 = 0; i0 < N; ++i0) {
for (size_t i1 = 0; i1 < P; ++i1) {delete[] C[i0][i1];
}
delete[] C[i0];
}delete[] C;
return 0;
}