
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
double **B = new double*[M];
for (size_t i = 0; i < M; ++i) {
B[i] = new double[N];

for (size_t j = 0; j < N; ++j) {
int flag16 = 0 <= i && M > i && 0 <= j && N > j && i == j;
if (flag16) {
B[i][j] = (double) (rand() % 1000000) / 1e6;
} else {
B[i][j] = 0.0;
}
}
}
double *C = new double[N];
for (size_t j = 0; j < N; ++j) {
int flag17 = 0 <= j && N > j;
if (flag17) {
C[j] = (double) (rand() % 1000000) / 1e6;
} else {
C[j] = 0.0;
}
}
double *A = new double[M];
for (size_t i = 0; i < M; ++i) {
A[i] = 0.0;
}

long time_computation = 0, start_computation, end_computation;
start_computation = duration_cast<microseconds>(system_clock::now().time_since_epoch()).count();
for (int i = 0; i < min({M, N}); ++i) {

A[i] += (B[i][i] * C[i]);
}
end_computation = duration_cast<microseconds>(system_clock::now().time_since_epoch()).count();
time_computation = end_computation - start_computation;
cout << time_computation << endl;
long time_reconstruction = 0, start_reconstruction, end_reconstruction;
start_reconstruction = duration_cast<microseconds>(system_clock::now().time_since_epoch()).count();

end_reconstruction = duration_cast<microseconds>(system_clock::now().time_since_epoch()).count();
time_reconstruction = end_reconstruction - start_reconstruction;
cout << time_reconstruction << endl;
cerr << A[0] << endl;
cerr << B[0][0] << endl;
cerr << C[0] << endl;
delete[] A;
for (size_t i0 = 0; i0 < N; ++i0) {delete[] B[i0];
}delete[] B;
delete[] C;
return 0;
}