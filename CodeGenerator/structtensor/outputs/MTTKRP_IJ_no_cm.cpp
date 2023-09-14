
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
const int J = atoi(argv[6]);

double ***B = new double**[M];
for (size_t i0 = 0; i0 < M; ++i0) {
B[i0] = new double*[N];
for (size_t i1 = 0; i1 < N; ++i1) {
B[i0][i1] = new double[P];
for (size_t i2 = 0; i2 < P; ++i2) {
if (i0 == I) {
B[i0][i1][i2] = (double) (rand() % 1000000) / 1e6;
} else {
B[i0][i1][i2] = 0.0;
}
}
}
}

double **C = new double*[N];
for (size_t i0 = 0; i0 < N; ++i0) {
C[i0] = new double[Q];
for (size_t i1 = 0; i1 < Q; ++i1) {
if (1) {
C[i0][i1] = (double) (rand() % 1000000) / 1e6;
} else {
C[i0][i1] = 0.0;
}
}
}

double **D = new double*[P];
for (size_t i0 = 0; i0 < P; ++i0) {
D[i0] = new double[Q];
for (size_t i1 = 0; i1 < Q; ++i1) {
if (i1 == I) {
D[i0][i1] = (double) (rand() % 1000000) / 1e6;
} else {
D[i0][i1] = 0.0;
}
}
}

double **A = new double*[M];
for (size_t i0 = 0; i0 < M; ++i0) {
A[i0] = new double[Q];
for (size_t i1 = 0; i1 < Q; ++i1) {
if (0) {
A[i0][i1] = (double) (rand() % 1000000) / 1e6;
} else {
A[i0][i1] = 0.0;
}
}
}

long time = 0, start, end;
start = duration_cast<microseconds>(system_clock::now().time_since_epoch()).count();



int i = I;
if (i < M) {
int j = J;
if (j < Q) {
for (int k = 0; k < N; ++k) {
for (int l = 0; l < P; ++l) {
A[i][j] += (C[k][j] * B[i][k][l] * D[l][j]);
}
}
}
}

end = duration_cast<microseconds>(system_clock::now().time_since_epoch()).count();
time = end - start;
cout << time;
cerr << A[M - 1][Q - 1] << endl;
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