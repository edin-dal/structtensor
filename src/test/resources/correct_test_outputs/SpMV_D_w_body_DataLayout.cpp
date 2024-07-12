
#include <iostream>
#include <random>
#include <algorithm>
#include <chrono>

using namespace std;
using namespace std::chrono;

int main(int argc, char **argv){
    srand(0);


const int N = atoi(argv[1]);
const int M = atoi(argv[2]);
double **B = new double*[M];
for (size_t i = 0; i < M; ++i) {
B[i] = new double[N];

for (size_t j = 0; j < N; ++j) {
int flag1 = 0 <= i && M > i && 0 <= j && N > j && i == j;
if (flag1) {
B[i][j] = (double) (rand() % 1000000) / 1e6;
} else {
B[i][j] = 0.0;
}
}
}
double *C = new double[N];
for (size_t j = 0; j < N; ++j) {
int flag2 = 0 <= j && N > j;
if (flag2) {
C[j] = (double) (rand() % 1000000) / 1e6;
} else {
C[j] = 0.0;
}
}
double *B2 = new double[M];
for (size_t i = 0; i < M; ++i) {
B2[i] = 0.0;
}
double *A = new double[M];
for (size_t i = 0; i < M; ++i) {
A[i] = 0.0;
}
for (int i = 0; i < min({M, N}); ++i) {

B2[i] = B[i][i];
}
long time_computation = 0, start_computation, end_computation;
start_computation = duration_cast<microseconds>(system_clock::now().time_since_epoch()).count();
for (int i = 0; i < min({M, N}); ++i) {

A[i] = (B2[i] * C[i]);
}
end_computation = duration_cast<microseconds>(system_clock::now().time_since_epoch()).count();
time_computation = end_computation - start_computation;
cout << time_computation << endl;
long time_reconstruction = 0, start_reconstruction, end_reconstruction;
start_reconstruction = duration_cast<microseconds>(system_clock::now().time_since_epoch()).count();

end_reconstruction = duration_cast<microseconds>(system_clock::now().time_since_epoch()).count();
time_reconstruction = end_reconstruction - start_reconstruction;
cout << time_reconstruction << endl;
cerr << B2[0] << endl;
cerr << B[0][0] << endl;
cerr << A[0] << endl;
cerr << C[0] << endl;
delete[] B2;
for (size_t i0 = 0; i0 < M; ++i0) {delete[] B[i0];
}delete[] B;
delete[] A;
delete[] C;
return 0;
}