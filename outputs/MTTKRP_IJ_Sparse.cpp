
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

double *B = new double[N * P];
for (size_t i0 = 0; i0 < N; ++i0) {
for (size_t i1 = 0; i1 < P; ++i1) {
if (1) {
B[i0 * P + i1] = (double) (rand() % 1000000) / 1e6;
} else {
B[i0 * P + i1] = 0.0;
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

double *D = new double[P];
for (size_t i0 = 0; i0 < P; ++i0) {
if (1) {
D[i0] = (double) (rand() % 1000000) / 1e6;
} else {
D[i0] = 0.0;
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
auto &cm2 = A[i];


int j = J;
if (j < Q) {
double tmp = 0.0;


for (int k = 0; k < N; ++k) {

auto &cm3 = C[k];

for (int l = 0; l < P; ++l) {


tmp += (cm3[j] * B[((k * P) + l)] * D[l]);
}
}
cm2[j] += tmp;
}
}

end = duration_cast<microseconds>(system_clock::now().time_since_epoch()).count();
time = end - start;
cout << time << endl;
cerr << A[M - 1][Q - 1] << endl;
delete[] A;
delete[] B;
delete[] C;
delete[] D;
return 0;
}