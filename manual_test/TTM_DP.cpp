
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

double ***A = new double**[M];
for (size_t i = 0; i < M; ++i) {
A[i] = new double*[N];
for (size_t j = 0; j < N; ++j) {
A[i][j] = new double[P];
for (size_t k = 0; k < P; ++k) {
int flag1 = 0 <= i && M > i && 0 <= j && N > j && 0 <= k && P > k;
if (flag1) {
A[i][j][k] = (double) 1.0;
} else {
A[i][j][k] = 0.0;
}
}
}
}

double ***B = new double**[M];
for (size_t i = 0; i < M; ++i) {
B[i] = new double*[N];
for (size_t j = 0; j < N; ++j) {
B[i][j] = new double[Q];
for (size_t l = 0; l < Q; ++l) {
int flag2 = 0 <= i && M > i && 0 <= j && N > j && 0 <= l && Q > l && i == j;
if (flag2) {
B[i][j][l] = (double) 1.0;
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
int flag3 = 0 <= k && P > k && 0 <= l && Q > l;
if (flag3) {
C[k][l] = (double) 1.0;
} else {
C[k][l] = 0.0;
}
}
}

long time = 0, start, end;
start = duration_cast<microseconds>(system_clock::now().time_since_epoch()).count();



for (int i = 0; i < std::min({M, N}); ++i) {
auto &cm4 = A[i];

auto &cm5 = B[i];


auto &cm6 = cm4[i];

auto &cm7 = cm5[i];

for (int k = 0; k < P; ++k) {
double tmp = 0.0;

auto &cm8 = C[k];

for (int l = 0; l < Q; ++l) {


tmp += (cm8[l] * cm7[l]);
}
cm6[k] += tmp;
}
}

end = duration_cast<microseconds>(system_clock::now().time_since_epoch()).count();
time = end - start;
cout << time << endl;
cerr << A[0][0][0] << endl;
cerr << B[0][0][0] << endl;
cerr << C[0][0] << endl;
for (size_t i0 = 0; i0 < N; ++i0) {
for (size_t i1 = 0; i1 < P; ++i1) {
delete[] A[i0][i1];
}
delete[] A[i0];
}
delete[] A;
for (size_t i0 = 0; i0 < N; ++i0) {
for (size_t i1 = 0; i1 < Q; ++i1) {
delete[] B[i0][i1];
}
delete[] B[i0];
}
delete[] B;
for (size_t i0 = 0; i0 < Q; ++i0) {
delete[] C[i0];
}
delete[] C;
return 0;
}