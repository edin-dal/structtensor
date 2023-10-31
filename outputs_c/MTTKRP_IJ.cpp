
#include <iostream>
#include <random>
#include <algorithm>
#include <chrono>

using namespace std;
using namespace std::chrono;

int main(int argc, char **argv){
    srand(0);


const int N = atoi(argv[1]);
const int J = atoi(argv[2]);
const int M = atoi(argv[3]);
const int I = atoi(argv[4]);
const int Q = atoi(argv[5]);
const int P = atoi(argv[6]);

double **A = new double*[M];
for (size_t i = 0; i < M; ++i) {
A[i] = new double[Q];
for (size_t j = 0; j < Q; ++j) {
int flag2 = 0;
if (flag2) {
A[i][j] = (double) (rand() % 1000000) / 1e6;
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
int flag3 = 0 <= i && M > i && 0 <= k && N > k && 0 <= l && P > l && i == I;
if (flag3) {
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
int flag4 = 0 <= k && N > k && 0 <= j && Q > j;
if (flag4) {
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
int flag5 = 0 <= l && P > l && 0 <= j && Q > j && j == J;
if (flag5) {
D[l][j] = (double) (rand() % 1000000) / 1e6;
} else {
D[l][j] = 0.0;
}
}
}

long time = 0, start, end;
start = duration_cast<microseconds>(system_clock::now().time_since_epoch()).count();



for (int i = 0; i < M; ++i) {
auto &cm7 = A[i];

auto &cm8 = B[i];

for (int j = 0; j < Q; ++j) {
double tmp = 0.0;


for (int k = 0; k < N; ++k) {

auto &cm9 = C[k];
auto &cm10 = cm8[k];

for (int l = 0; l < P; ++l) {


tmp += (cm9[j] * cm10[l] * D[l][j]);
}
}
cm7[j] += tmp;
}
}

end = duration_cast<microseconds>(system_clock::now().time_since_epoch()).count();
time = end - start;
cout << time << endl;
cerr << A[0][0] << endl;
cerr << B[0][0][0] << endl;
cerr << C[0][0] << endl;
cerr << D[0][0] << endl;
cerr << B[0][0][0] << endl;
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