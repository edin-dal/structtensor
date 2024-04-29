
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

double *A = new double[M];
for (size_t i = 0; i < M; ++i) {
int flag1 = 0 <= i && M > i;
if (flag1) {
A[i] = (double) 1.0;
} else {
A[i] = 0.0;
}
}

double **B = new double*[M];
for (size_t i = 0; i < M; ++i) {
B[i] = new double[N];
for (size_t j = 0; j < N; ++j) {
int flag2 = 0 <= i && M > i && 0 <= j && N > j && i == j;
if (flag2) {
B[i][j] = (double) 1.0;
} else {
B[i][j] = 0.0;
}
}
}

double *C = new double[N];
for (size_t j = 0; j < N; ++j) {
int flag3 = 0 <= j && N > j;
if (flag3) {
C[j] = (double) 1.0;
} else {
C[j] = 0.0;
}
}

long time = 0, start, end;
start = duration_cast<microseconds>(system_clock::now().time_since_epoch()).count();



for (int i = 0; i < std::min({M, N}); ++i) {
double tmp = 0.0;

auto &cm4 = B[i];




tmp += (cm4[i] * C[i]);
A[i] += tmp;
}

end = duration_cast<microseconds>(system_clock::now().time_since_epoch()).count();
time = end - start;
cout << time << endl;
cerr << A[0] << endl;
cerr << B[0][0] << endl;
cerr << C[0] << endl;
delete[] A;
for (size_t i0 = 0; i0 < N; ++i0) {
delete[] B[i0];
}
delete[] B;
delete[] C;
return 0;
}