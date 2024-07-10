
#include <iostream>
#include <random>
#include <algorithm>
#include <chrono>

using namespace std;
using namespace std::chrono;

int main(int argc, char **argv){
    srand(0);


const int N = atoi(argv[1]);
double *f = new double[N];
for (size_t i = 0; i < N; ++i) {
int flag1 = 0 <= i && N > i;
if (flag1) {
f[i] = (double) (rand() % 1000000) / 1e6;
} else {
f[i] = 0.0;
}
}
double *t = new double[N];
for (size_t i = 0; i < N; ++i) {
int flag2 = 0 <= i && N > i;
if (flag2) {
t[i] = (double) (rand() % 1000000) / 1e6;
} else {
t[i] = 0.0;
}
}
double ****C = new double***[N];
for (size_t i = 0; i < N; ++i) {
C[i] = new double**[N];

for (size_t j = 0; j < N; ++j) {
C[i][j] = new double*[N];

for (size_t k = 0; k < N; ++k) {
C[i][j][k] = new double[N];

for (size_t l = 0; l < N; ++l) {
C[i][j][k][l] = 0.0;
}
}
}
}

long time_computation = 0, start_computation, end_computation;
start_computation = duration_cast<microseconds>(system_clock::now().time_since_epoch()).count();
for (int i = 0; i < N; ++i) {

for (int j = max({i, 0}); j < N; ++j) {

for (int k = 0; k < N; ++k) {

for (int l = max({k, 0}); l < N; ++l) {

C[i][j][k][l] += (f[i] * f[j] * t[k] * t[l]);
}
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
for (int j = 0; j < min({i, N}); ++j) {

int ip = j;
for (int k = 0; k < N; ++k) {

for (int l = 0; l < min({k, N}); ++l) {

int lp = k;
int kp = l;
C[i][j][k][l] += C[ip][jp][kp][lp];
}
}
}
}
for (int i = 0; i < N; ++i) {

int ip = i;
for (int j = max({i, 0}); j < N; ++j) {

int jp = j;
for (int k = 0; k < N; ++k) {

for (int l = 0; l < min({k, N}); ++l) {

int lp = k;
int kp = l;
C[i][j][k][l] += C[ip][jp][kp][lp];
}
}
}
}
for (int i = 0; i < N; ++i) {

int jp = i;
for (int j = 0; j < min({i, N}); ++j) {

int ip = j;
for (int k = 0; k < N; ++k) {

for (int l = max({k, 0}); l < N; ++l) {

int kp = k;
int lp = l;
C[i][j][k][l] += C[ip][jp][kp][lp];
}
}
}
}
end_reconstruction = duration_cast<microseconds>(system_clock::now().time_since_epoch()).count();
time_reconstruction = end_reconstruction - start_reconstruction;
cout << time_reconstruction << endl;
cerr << C[0][0][0][0] << endl;
delete[] f;
delete[] t;
for (size_t i0 = 0; i0 < N; ++i0) {
for (size_t i1 = 0; i1 < N; ++i1) {
for (size_t i2 = 0; i2 < N; ++i2) {delete[] C[i0][i1][i2];
}
delete[] C[i0][i1];
}
delete[] C[i0];
}delete[] C;
for (size_t i0 = 0; i0 < N; ++i0) {delete[] B[i0];
}delete[] B;
return 0;
}