
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

double **A = new double*[M];
for (size_t i = 0; i < M; ++i) {
A[i] = new double[Q];
for (size_t j = 0; j < Q; ++j) {
int flag1 = 0 <= i && M > i && 0 <= j && Q > j;
if (flag1) {
A[i][j] = (double) 1.0;
} else {
A[i][j] = 0.0;
}
}
}

double ***B = new double**[M];
for (size_t i = 0; i < M; ++i) {
B[i] = new double*[N];
for (size_t k = 0; k < N; ++k) {
B[i][k] = new double[P];
for (size_t l = 0; l < P; ++l) {
int flag2 = 0 <= i && M > i && 0 <= k && N > k && 0 <= l && P > l && i == k && k == l && i == l;
if (flag2) {
B[i][k][l] = (double) 1.0;
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
int flag3 = 0 <= k && N > k && 0 <= j && Q > j;
if (flag3) {
C[k][j] = (double) 1.0;
} else {
C[k][j] = 0.0;
}
}
}

double **D = new double*[P];
for (size_t l = 0; l < P; ++l) {
D[l] = new double[Q];
for (size_t j = 0; j < Q; ++j) {
int flag4 = 0 <= l && P > l && 0 <= j && Q > j && j == l;
if (flag4) {
D[l][j] = (double) 1.0;
} else {
D[l][j] = 0.0;
}
}
}

long time = 0, start, end;
start = duration_cast<microseconds>(system_clock::now().time_since_epoch()).count();



for (int i = 0; i < std::min({P, Q, M, N}); ++i) {
auto &cm5 = A[i];

auto &cm6 = B[i];


double tmp = 0.0;




auto &cm7 = cm6[i];
auto &cm8 = C[i];




tmp += (cm7[i] * D[i][i] * cm8[i]);
}

end = duration_cast<microseconds>(system_clock::now().time_since_epoch()).count();
time = end - start;
cout << time << endl;
cerr << A[0][0] << endl;
cerr << B[0][0][0] << endl;
cerr << C[0][0] << endl;
cerr << D[0][0] << endl;
for (size_t i0 = 0; i0 < Q; ++i0) {
delete[] A[i0];
}
delete[] A;
for (size_t i0 = 0; i0 < N; ++i0) {
for (size_t i1 = 0; i1 < P; ++i1) {
delete[] B[i0][i1];
}
delete[] B[i0];
}
delete[] B;
for (size_t i0 = 0; i0 < Q; ++i0) {
delete[] C[i0];
}
delete[] C;
for (size_t i0 = 0; i0 < Q; ++i0) {
delete[] D[i0];
}
delete[] D;
return 0;
}