
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
const int I = atoi(argv[4]);

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
B[i][j] = new double[P];
for (size_t k = 0; k < P; ++k) {
int flag2 = 0 <= i && M > i && 0 <= j && N > j && 0 <= k && P > k && i == I;
if (flag2) {
B[i][j][k] = (double) 1.0;
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
int flag3 = 0 <= i && M > i && 0 <= j && N > j && 0 <= k && P > k;
if (flag3) {
C[i][j][k] = (double) 1.0;
} else {
C[i][j][k] = 0.0;
}
}
}
}

long time = 0, start, end;
start = duration_cast<microseconds>(system_clock::now().time_since_epoch()).count();



int i = I;
if (i < M) {
auto &cm4 = A[i];

auto &cm5 = B[i];
auto &cm6 = C[i];

for (int j = 0; j < N; ++j) {
auto &cm7 = cm4[j];

auto &cm8 = cm5[j];
auto &cm9 = cm6[j];

for (int k = 0; k < P; ++k) {


cm7[k] += (cm8[k] * cm9[k]);
}
}
}

end = duration_cast<microseconds>(system_clock::now().time_since_epoch()).count();
time = end - start;
cout << time << endl;
cerr << A[0][0][0] << endl;
cerr << B[0][0][0] << endl;
cerr << C[0][0][0] << endl;
for (size_t i0 = 0; i0 < N; ++i0) {
for (size_t i1 = 0; i1 < P; ++i1) {
delete[] A[i0][i1];
}
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
for (size_t i0 = 0; i0 < N; ++i0) {
for (size_t i1 = 0; i1 < P; ++i1) {
delete[] C[i0][i1];
}
delete[] C[i0];
}
delete[] C;
return 0;
}