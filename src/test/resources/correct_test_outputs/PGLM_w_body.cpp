
#include <iostream>
#include <random>
#include <algorithm>
#include <chrono>

using namespace std;
using namespace std::chrono;

int main(int argc, char **argv){
    srand(0);


const int W = atoi(argv[1]);
double **B = new double*[W];
for (size_t i = 0; i < W; ++i) {
B[i] = new double[W];

for (size_t j = 0; j < W; ++j) {
int flag1 = 0 <= i && W > i && 0 <= j && W > j && 0 == i && 0 <= j && W > j || 0 <= i && W > i && 0 <= j && W > j && 1 <= i && W > i && (i - 1) == j;
if (flag1) {
B[i][j] = (double) (rand() % 1000000) / 1e6;
} else {
B[i][j] = 0.0;
}
}
}
double *C = new double[W];
for (size_t j = 0; j < W; ++j) {
int flag2 = 0 <= j && W > j;
if (flag2) {
C[j] = (double) (rand() % 1000000) / 1e6;
} else {
C[j] = 0.0;
}
}
double *A = new double[W];
for (size_t i = 0; i < W; ++i) {
A[i] = 0.0;
}

long time_computation = 0, start_computation, end_computation;
start_computation = duration_cast<microseconds>(system_clock::now().time_since_epoch()).count();
{
int i = 0;
if (i >= 0 && i < W) {
for (int j = 0; j < W; ++j) {

A[i] += (B[i][j] * C[j]);
}
}
}
{
for (int i = max({0, 1}); i < W; ++i) {

int j = (i - 1);
if (j >= 0 && j < W) {
A[i] += (B[i][j] * C[j]);
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
cerr << A[0] << endl;
cerr << B[0][0] << endl;
cerr << C[0] << endl;
delete[] A;
for (size_t i0 = 0; i0 < W; ++i0) {delete[] B[i0];
}delete[] B;
delete[] C;
return 0;
}