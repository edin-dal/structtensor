
#include <iostream>
#include <random>
#include <algorithm>
#include <chrono>

using namespace std;
using namespace std::chrono;

int main(int argc, char **argv){
    srand(0);


const int N = atoi(argv[1]);
double *t = new double[N];
for (size_t i = 0; i < N; ++i) {
int flag1 = 0 <= i && N > i;
if (flag1) {
t[i] = (double) (rand() % 1000000) / 1e6;
} else {
t[i] = 0.0;
}
}
double *f = new double[N];
for (size_t i = 0; i < N; ++i) {
int flag2 = 0 <= i && N > i;
if (flag2) {
f[i] = (double) (rand() % 1000000) / 1e6;
} else {
f[i] = 0.0;
}
}
double p = 0.0;
double **A = new double*[N];
for (size_t i = 0; i < N; ++i) {
A[i] = new double[N];

for (size_t j = 0; j < N; ++j) {
A[i][j] = 0.0;
}
}

long time_computation = 0, start_computation, end_computation;
start_computation = duration_cast<microseconds>(system_clock::now().time_since_epoch()).count();
for (int i = 0; i < N; ++i) {

p += t[i];
}
for (int i = 0; i < N; ++i) {

for (int j = 0; j < min({(i) + 1, N}); ++j) {

for (int i5 = 0; i5 < N; ++i5) {

A[i][j] += (f[j] * f[i] * t[i5]);
}
}
}
end_computation = duration_cast<microseconds>(system_clock::now().time_since_epoch()).count();
time_computation = end_computation - start_computation;
cout << time_computation << endl;
long time_reconstruction = 0, start_reconstruction, end_reconstruction;
start_reconstruction = duration_cast<microseconds>(system_clock::now().time_since_epoch()).count();

for (int i = 0; i < N; ++i) {

int jp = i;
for (int j = max({(i) + 1, 0}); j < N; ++j) {

int ip = j;
A[i][j] = A[ip][jp];
}
}
end_reconstruction = duration_cast<microseconds>(system_clock::now().time_since_epoch()).count();
time_reconstruction = end_reconstruction - start_reconstruction;
cout << time_reconstruction << endl;
cerr << p << endl;
cerr << t[0] << endl;
cerr << A[0][0] << endl;
cerr << f[0] << endl;
delete[] t;
for (size_t i0 = 0; i0 < N; ++i0) {delete[] A[i0];
}delete[] A;
delete[] f;
return 0;
}