
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
const int Q = atoi(argv[3]);
const int P = atoi(argv[4]);
double ***B = new double**[M];
for (size_t i = 0; i < M; ++i) {
B[i] = new double*[N];

for (size_t j = 0; j < N; ++j) {
B[i][j] = new double[Q];

for (size_t l = 0; l < Q; ++l) {
int flag170 = 0 <= i && M > i && 0 <= j && N > j && 0 <= l && Q > l && i == j;
if (flag170) {
B[i][j][l] = (double) (rand() % 1000000) / 1e6;
} else {
B[i][j][l] = 0.0;
}
}
}
}
double **C = new double*[P];
for (size_t k = 0; k < P; ++k) {
C[k] = new double[Q];

for (size_t l = 0; l < Q; ++l) {
int flag171 = 0 <= k && P > k && 0 <= l && Q > l;
if (flag171) {
C[k][l] = (double) (rand() % 1000000) / 1e6;
} else {
C[k][l] = 0.0;
}
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

long time_computation = 0, start_computation, end_computation;
start_computation = duration_cast<microseconds>(system_clock::now().time_since_epoch()).count();
for (int i = 0; i < min({M, N}); ++i) {

int j = i;
for (int k = 0; k < P; ++k) {

for (int l = 0; l < Q; ++l) {

A[i][j][k] += (B[i][i][l] * C[k][l]);
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
cerr << A[0][0][0] << endl;
cerr << B[0][0][0] << endl;
cerr << C[0][0] << endl;
for (size_t i0 = 0; i0 < N; ++i0) {
for (size_t i1 = 0; i1 < P; ++i1) {delete[] A[i0][i1];
}
delete[] A[i0];
}delete[] A;
for (size_t i0 = 0; i0 < N; ++i0) {
for (size_t i1 = 0; i1 < Q; ++i1) {delete[] B[i0][i1];
}
delete[] B[i0];
}delete[] B;
for (size_t i0 = 0; i0 < Q; ++i0) {delete[] C[i0];
}delete[] C;
return 0;
}