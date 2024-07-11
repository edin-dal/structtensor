
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
double *g = new double[N];
for (size_t i = 0; i < N; ++i) {
int flag2 = 0 <= i && N > i;
if (flag2) {
g[i] = (double) (rand() % 1000000) / 1e6;
} else {
g[i] = 0.0;
}
}
double **A = new double*[N];
for (size_t i = 0; i < N; ++i) {
A[i] = new double[N];

for (size_t j = 0; j < N; ++j) {
A[i][j] = 0.0;
}
}
double ***B = new double**[N];
for (size_t i = 0; i < N; ++i) {
B[i] = new double*[N];

for (size_t j = 0; j < N; ++j) {
B[i][j] = new double[N];

for (size_t k = 0; k < N; ++k) {
B[i][j][k] = 0.0;
}
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
double **D = new double*[N];
for (size_t i = 0; i < N; ++i) {
D[i] = new double[N];

for (size_t j = 0; j < N; ++j) {
D[i][j] = 0.0;
}
}
double ***E = new double**[N];
for (size_t i = 0; i < N; ++i) {
E[i] = new double*[N];

for (size_t j = 0; j < N; ++j) {
E[i][j] = new double[N];

for (size_t k = 0; k < N; ++k) {
E[i][j][k] = 0.0;
}
}
}
double ****F = new double***[N];
for (size_t i = 0; i < N; ++i) {
F[i] = new double**[N];

for (size_t j = 0; j < N; ++j) {
F[i][j] = new double*[N];

for (size_t k = 0; k < N; ++k) {
F[i][j][k] = new double[N];

for (size_t l = 0; l < N; ++l) {
F[i][j][k][l] = 0.0;
}
}
}
}
double **H = new double*[N];
for (size_t i = 0; i < N; ++i) {
H[i] = new double[N];

for (size_t j = 0; j < N; ++j) {
H[i][j] = 0.0;
}
}
double ***I = new double**[N];
for (size_t i = 0; i < N; ++i) {
I[i] = new double*[N];

for (size_t j = 0; j < N; ++j) {
I[i][j] = new double[N];

for (size_t k = 0; k < N; ++k) {
I[i][j][k] = 0.0;
}
}
}
double ****J = new double***[N];
for (size_t i = 0; i < N; ++i) {
J[i] = new double**[N];

for (size_t j = 0; j < N; ++j) {
J[i][j] = new double*[N];

for (size_t k = 0; k < N; ++k) {
J[i][j][k] = new double[N];

for (size_t l = 0; l < N; ++l) {
J[i][j][k][l] = 0.0;
}
}
}
}

long time_computation = 0, start_computation, end_computation;
start_computation = duration_cast<microseconds>(system_clock::now().time_since_epoch()).count();
for (int i = 0; i < N; ++i) {

for (int j = max({i, 0}); j < N; ++j) {

A[i][j] += (f[i] * f[j]);
}
}
for (int i = 0; i < N; ++i) {

for (int j = 0; j < N; ++j) {

for (int k = max({j, 0}); k < min({(i) + 1, N}); ++k) {

B[i][j][k] += (f[j] * f[k] * f[i]);
}
}
}
for (int i = 0; i < N; ++i) {

for (int j = 0; j < N; ++j) {

for (int k = max({j, 0}); k < N; ++k) {

for (int l = max({k, 0}); l < min({(i) + 1, N}); ++l) {

C[i][j][k][l] += (f[j] * f[k] * f[l] * f[i]);
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int j = max({i, 0}); j < N; ++j) {

D[i][j] += (g[i] * g[j]);
}
}
for (int i = 0; i < N; ++i) {

for (int j = 0; j < N; ++j) {

for (int k = max({j, 0}); k < min({(i) + 1, N}); ++k) {

E[i][j][k] += (g[j] * g[k] * g[i]);
}
}
}
for (int i = 0; i < N; ++i) {

for (int j = 0; j < N; ++j) {

for (int k = max({j, 0}); k < N; ++k) {

for (int l = max({k, 0}); l < min({(i) + 1, N}); ++l) {

F[i][j][k][l] += (g[j] * g[k] * g[l] * g[i]);
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int j = max({i, 0}); j < N; ++j) {

H[i][j] += (f[i] * f[j]);
}
}
for (int i = 0; i < N; ++i) {

for (int j = max({i, 0}); j < N; ++j) {

H[i][j] += (g[i] * g[j]);
}
}
for (int i = 0; i < N; ++i) {

for (int j = 0; j < N; ++j) {

for (int k = max({j, 0}); k < min({(i) + 1, N}); ++k) {

I[i][j][k] += (f[j] * f[k] * f[i]);
}
}
}
for (int i = 0; i < N; ++i) {

for (int j = 0; j < N; ++j) {

for (int k = max({j, 0}); k < min({(i) + 1, N}); ++k) {

I[i][j][k] += (g[j] * g[k] * g[i]);
}
}
}
for (int i = 0; i < N; ++i) {

for (int j = 0; j < N; ++j) {

for (int k = max({j, 0}); k < N; ++k) {

for (int l = max({k, 0}); l < min({(i) + 1, N}); ++l) {

J[i][j][k][l] += (f[j] * f[k] * f[l] * f[i]);
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int j = 0; j < N; ++j) {

for (int k = max({j, 0}); k < N; ++k) {

for (int l = max({k, 0}); l < min({(i) + 1, N}); ++l) {

J[i][j][k][l] += (g[j] * g[k] * g[l] * g[i]);
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
A[i][j] += A[ip][jp];
}
}
for (int i = 0; i < N; ++i) {

int kp = i;
for (int j = 0; j < min({(i) + 1, N}); ++j) {

for (int k = max({i, 0}); k < N; ++k) {

int jp = j;
int ip = k;
B[i][j][k] += B[ip][jp][kp];
}
}
}
for (int i = 0; i < N; ++i) {

int ip = i;
for (int j = 0; j < min({(i) + 1, N}); ++j) {

int kp = j;
for (int k = 0; k < min({(j) + 1, N}); ++k) {

int jp = k;
B[i][j][k] += B[ip][jp][kp];
}
}
}
for (int i = 0; i < N; ++i) {

int jp = i;
for (int j = max({i, 0}); j < N; ++j) {

for (int k = 0; k < min({(i) + 1, N}); ++k) {

int kp = j;
int ip = k;
B[i][j][k] += B[ip][jp][kp];
}
}
}
for (int i = 0; i < N; ++i) {

int kp = i;
for (int j = max({i, 0}); j < N; ++j) {

int ip = j;
for (int k = max({j, 0}); k < N; ++k) {

int jp = k;
B[i][j][k] += B[ip][jp][kp];
}
}
}
for (int i = 0; i < N; ++i) {

int jp = i;
for (int j = 0; j < N; ++j) {

int ip = j;
for (int k = max({i, 0}); k < min({(j) + 1, N}); ++k) {

int kp = k;
B[i][j][k] += B[ip][jp][kp];
}
}
}
for (int i = 0; i < N; ++i) {

for (int l = max({i, 0}); l < N; ++l) {

int lp = i;
int ip = l;
for (int j = 0; j < N; ++j) {

int jp = j;
for (int k = max({j, 0}); k < min({(i) + 1, N}); ++k) {

int kp = k;
C[i][j][k][l] += C[ip][jp][kp][lp];
}
}
}
}
for (int i = 0; i < N; ++i) {

int ip = i;
for (int k = 0; k < min({(i) + 1, N}); ++k) {

int lp = k;
for (int j = 0; j < N; ++j) {

for (int l = max({j, 0}); l < min({(k) + 1, N}); ++l) {

int jp = j;
int kp = l;
C[i][j][k][l] += C[ip][jp][kp][lp];
}
}
}
}
for (int i = 0; i < N; ++i) {

int kp = i;
for (int k = max({i, 0}); k < N; ++k) {

int lp = k;
for (int j = 0; j < N; ++j) {

for (int l = max({j, 0}); l < min({(i) + 1, N}); ++l) {

int jp = j;
int ip = l;
C[i][j][k][l] += C[ip][jp][kp][lp];
}
}
}
}
for (int i = 0; i < N; ++i) {

int lp = i;
for (int j = 0; j < min({(i) + 1, N}); ++j) {

for (int k = max({i, 0}); k < N; ++k) {

int jp = j;
for (int l = max({k, 0}); l < N; ++l) {

int ip = k;
int kp = l;
C[i][j][k][l] += C[ip][jp][kp][lp];
}
}
}
}
for (int i = 0; i < N; ++i) {

int kp = i;
for (int j = 0; j < min({(i) + 1, N}); ++j) {

int jp = j;
for (int k = 0; k < N; ++k) {

for (int l = max({i, 0}); l < min({(k) + 1, N}); ++l) {

int ip = k;
int lp = l;
C[i][j][k][l] += C[ip][jp][kp][lp];
}
}
}
}
for (int i = 0; i < N; ++i) {

int ip = i;
for (int j = 0; j < N; ++j) {

for (int l = max({j, 0}); l < min({(i) + 1, N}); ++l) {

int kp = j;
for (int k = 0; k < min({(j) + 1, N}); ++k) {

int lp = l;
int jp = k;
C[i][j][k][l] += C[ip][jp][kp][lp];
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int l = max({i, 0}); l < N; ++l) {

int lp = i;
for (int j = 0; j < min({(i) + 1, N}); ++j) {

int ip = l;
int kp = j;
for (int k = 0; k < min({(j) + 1, N}); ++k) {

int jp = k;
C[i][j][k][l] += C[ip][jp][kp][lp];
}
}
}
}
for (int i = 0; i < N; ++i) {

int ip = i;
for (int j = 0; j < min({(i) + 1, N}); ++j) {

int kp = j;
for (int k = 0; k < N; ++k) {

for (int l = max({k, 0}); l < min({(j) + 1, N}); ++l) {

int lp = k;
int jp = l;
C[i][j][k][l] += C[ip][jp][kp][lp];
}
}
}
}
for (int i = 0; i < N; ++i) {

int jp = i;
for (int j = max({i, 0}); j < N; ++j) {

int kp = j;
for (int k = 0; k < N; ++k) {

for (int l = max({k, 0}); l < min({(i) + 1, N}); ++l) {

int lp = k;
int ip = l;
C[i][j][k][l] += C[ip][jp][kp][lp];
}
}
}
}
for (int i = 0; i < N; ++i) {

int lp = i;
for (int j = max({i, 0}); j < N; ++j) {

for (int k = 0; k < min({(i) + 1, N}); ++k) {

for (int l = max({j, 0}); l < N; ++l) {

int kp = j;
int ip = k;
int jp = l;
C[i][j][k][l] += C[ip][jp][kp][lp];
}
}
}
}
for (int i = 0; i < N; ++i) {

int jp = i;
for (int k = 0; k < min({(i) + 1, N}); ++k) {

int ip = k;
for (int j = 0; j < N; ++j) {

for (int l = max({i, 0}); l < min({(j) + 1, N}); ++l) {

int kp = j;
int lp = l;
C[i][j][k][l] += C[ip][jp][kp][lp];
}
}
}
}
for (int i = 0; i < N; ++i) {

int ip = i;
for (int j = 0; j < N; ++j) {

for (int l = 0; l < min({(j) + 1, N}); ++l) {

int lp = j;
for (int k = max({j, 0}); k < min({(i) + 1, N}); ++k) {

int kp = l;
int jp = k;
C[i][j][k][l] += C[ip][jp][kp][lp];
}
}
}
}
for (int i = 0; i < N; ++i) {

int kp = i;
for (int j = 0; j < min({(i) + 1, N}); ++j) {

for (int k = max({i, 0}); k < N; ++k) {

for (int l = 0; l < min({(j) + 1, N}); ++l) {

int lp = j;
int jp = k;
int ip = l;
C[i][j][k][l] += C[ip][jp][kp][lp];
}
}
}
}
for (int i = 0; i < N; ++i) {

int ip = i;
for (int j = 0; j < min({(i) + 1, N}); ++j) {

int lp = j;
for (int k = 0; k < min({(j) + 1, N}); ++k) {

for (int l = 0; l < min({(k) + 1, N}); ++l) {

int kp = k;
int jp = l;
C[i][j][k][l] += C[ip][jp][kp][lp];
}
}
}
}
for (int i = 0; i < N; ++i) {

int jp = i;
for (int j = max({i, 0}); j < N; ++j) {

for (int k = 0; k < min({(i) + 1, N}); ++k) {

int lp = j;
for (int l = 0; l < min({(k) + 1, N}); ++l) {

int kp = k;
int ip = l;
C[i][j][k][l] += C[ip][jp][kp][lp];
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int l = 0; l < min({(i) + 1, N}); ++l) {

int kp = i;
for (int j = max({i, 0}); j < N; ++j) {

int jp = l;
int lp = j;
for (int k = max({j, 0}); k < N; ++k) {

int ip = k;
C[i][j][k][l] += C[ip][jp][kp][lp];
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int l = 0; l < min({(i) + 1, N}); ++l) {

int jp = i;
int kp = l;
for (int j = 0; j < N; ++j) {

int lp = j;
for (int k = max({i, 0}); k < min({(j) + 1, N}); ++k) {

int ip = k;
C[i][j][k][l] += C[ip][jp][kp][lp];
}
}
}
}
for (int i = 0; i < N; ++i) {

int lp = i;
for (int j = max({i, 0}); j < N; ++j) {

int ip = j;
for (int k = max({j, 0}); k < N; ++k) {

for (int l = max({k, 0}); l < N; ++l) {

int jp = k;
int kp = l;
C[i][j][k][l] += C[ip][jp][kp][lp];
}
}
}
}
for (int i = 0; i < N; ++i) {

int kp = i;
for (int j = max({i, 0}); j < N; ++j) {

int ip = j;
for (int k = 0; k < N; ++k) {

for (int l = max({j, 0}); l < min({(k) + 1, N}); ++l) {

int jp = k;
int lp = l;
C[i][j][k][l] += C[ip][jp][kp][lp];
}
}
}
}
for (int i = 0; i < N; ++i) {

int lp = i;
for (int j = 0; j < N; ++j) {

for (int l = max({j, 0}); l < N; ++l) {

int ip = j;
for (int k = max({i, 0}); k < min({(j) + 1, N}); ++k) {

int jp = l;
int kp = k;
C[i][j][k][l] += C[ip][jp][kp][lp];
}
}
}
}
for (int i = 0; i < N; ++i) {

int jp = i;
for (int k = max({i, 0}); k < N; ++k) {

int kp = k;
for (int j = 0; j < N; ++j) {

for (int l = max({k, 0}); l < min({(j) + 1, N}); ++l) {

int ip = j;
int lp = l;
C[i][j][k][l] += C[ip][jp][kp][lp];
}
}
}
}
for (int i = 0; i < N; ++i) {

int kp = i;
for (int j = 0; j < N; ++j) {

for (int l = max({i, 0}); l < min({(j) + 1, N}); ++l) {

int ip = j;
for (int k = max({j, 0}); k < N; ++k) {

int jp = l;
int lp = k;
C[i][j][k][l] += C[ip][jp][kp][lp];
}
}
}
}
for (int i = 0; i < N; ++i) {

int jp = i;
for (int j = 0; j < N; ++j) {

int ip = j;
for (int k = 0; k < min({(j) + 1, N}); ++k) {

for (int l = max({i, 0}); l < min({(k) + 1, N}); ++l) {

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
D[i][j] += D[ip][jp];
}
}
for (int i = 0; i < N; ++i) {

int kp = i;
for (int j = 0; j < min({(i) + 1, N}); ++j) {

for (int k = max({i, 0}); k < N; ++k) {

int jp = j;
int ip = k;
E[i][j][k] += E[ip][jp][kp];
}
}
}
for (int i = 0; i < N; ++i) {

int ip = i;
for (int j = 0; j < min({(i) + 1, N}); ++j) {

int kp = j;
for (int k = 0; k < min({(j) + 1, N}); ++k) {

int jp = k;
E[i][j][k] += E[ip][jp][kp];
}
}
}
for (int i = 0; i < N; ++i) {

int jp = i;
for (int j = max({i, 0}); j < N; ++j) {

for (int k = 0; k < min({(i) + 1, N}); ++k) {

int kp = j;
int ip = k;
E[i][j][k] += E[ip][jp][kp];
}
}
}
for (int i = 0; i < N; ++i) {

int kp = i;
for (int j = max({i, 0}); j < N; ++j) {

int ip = j;
for (int k = max({j, 0}); k < N; ++k) {

int jp = k;
E[i][j][k] += E[ip][jp][kp];
}
}
}
for (int i = 0; i < N; ++i) {

int jp = i;
for (int j = 0; j < N; ++j) {

int ip = j;
for (int k = max({i, 0}); k < min({(j) + 1, N}); ++k) {

int kp = k;
E[i][j][k] += E[ip][jp][kp];
}
}
}
for (int i = 0; i < N; ++i) {

for (int l = max({i, 0}); l < N; ++l) {

int lp = i;
int ip = l;
for (int j = 0; j < N; ++j) {

int jp = j;
for (int k = max({j, 0}); k < min({(i) + 1, N}); ++k) {

int kp = k;
F[i][j][k][l] += F[ip][jp][kp][lp];
}
}
}
}
for (int i = 0; i < N; ++i) {

int ip = i;
for (int k = 0; k < min({(i) + 1, N}); ++k) {

int lp = k;
for (int j = 0; j < N; ++j) {

for (int l = max({j, 0}); l < min({(k) + 1, N}); ++l) {

int jp = j;
int kp = l;
F[i][j][k][l] += F[ip][jp][kp][lp];
}
}
}
}
for (int i = 0; i < N; ++i) {

int kp = i;
for (int k = max({i, 0}); k < N; ++k) {

int lp = k;
for (int j = 0; j < N; ++j) {

for (int l = max({j, 0}); l < min({(i) + 1, N}); ++l) {

int jp = j;
int ip = l;
F[i][j][k][l] += F[ip][jp][kp][lp];
}
}
}
}
for (int i = 0; i < N; ++i) {

int lp = i;
for (int j = 0; j < min({(i) + 1, N}); ++j) {

for (int k = max({i, 0}); k < N; ++k) {

int jp = j;
for (int l = max({k, 0}); l < N; ++l) {

int ip = k;
int kp = l;
F[i][j][k][l] += F[ip][jp][kp][lp];
}
}
}
}
for (int i = 0; i < N; ++i) {

int kp = i;
for (int j = 0; j < min({(i) + 1, N}); ++j) {

int jp = j;
for (int k = 0; k < N; ++k) {

for (int l = max({i, 0}); l < min({(k) + 1, N}); ++l) {

int ip = k;
int lp = l;
F[i][j][k][l] += F[ip][jp][kp][lp];
}
}
}
}
for (int i = 0; i < N; ++i) {

int ip = i;
for (int j = 0; j < N; ++j) {

for (int l = max({j, 0}); l < min({(i) + 1, N}); ++l) {

int kp = j;
for (int k = 0; k < min({(j) + 1, N}); ++k) {

int lp = l;
int jp = k;
F[i][j][k][l] += F[ip][jp][kp][lp];
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int l = max({i, 0}); l < N; ++l) {

int lp = i;
for (int j = 0; j < min({(i) + 1, N}); ++j) {

int ip = l;
int kp = j;
for (int k = 0; k < min({(j) + 1, N}); ++k) {

int jp = k;
F[i][j][k][l] += F[ip][jp][kp][lp];
}
}
}
}
for (int i = 0; i < N; ++i) {

int ip = i;
for (int j = 0; j < min({(i) + 1, N}); ++j) {

int kp = j;
for (int k = 0; k < N; ++k) {

for (int l = max({k, 0}); l < min({(j) + 1, N}); ++l) {

int lp = k;
int jp = l;
F[i][j][k][l] += F[ip][jp][kp][lp];
}
}
}
}
for (int i = 0; i < N; ++i) {

int jp = i;
for (int j = max({i, 0}); j < N; ++j) {

int kp = j;
for (int k = 0; k < N; ++k) {

for (int l = max({k, 0}); l < min({(i) + 1, N}); ++l) {

int lp = k;
int ip = l;
F[i][j][k][l] += F[ip][jp][kp][lp];
}
}
}
}
for (int i = 0; i < N; ++i) {

int lp = i;
for (int j = max({i, 0}); j < N; ++j) {

for (int k = 0; k < min({(i) + 1, N}); ++k) {

for (int l = max({j, 0}); l < N; ++l) {

int kp = j;
int ip = k;
int jp = l;
F[i][j][k][l] += F[ip][jp][kp][lp];
}
}
}
}
for (int i = 0; i < N; ++i) {

int jp = i;
for (int k = 0; k < min({(i) + 1, N}); ++k) {

int ip = k;
for (int j = 0; j < N; ++j) {

for (int l = max({i, 0}); l < min({(j) + 1, N}); ++l) {

int kp = j;
int lp = l;
F[i][j][k][l] += F[ip][jp][kp][lp];
}
}
}
}
for (int i = 0; i < N; ++i) {

int ip = i;
for (int j = 0; j < N; ++j) {

for (int l = 0; l < min({(j) + 1, N}); ++l) {

int lp = j;
for (int k = max({j, 0}); k < min({(i) + 1, N}); ++k) {

int kp = l;
int jp = k;
F[i][j][k][l] += F[ip][jp][kp][lp];
}
}
}
}
for (int i = 0; i < N; ++i) {

int kp = i;
for (int j = 0; j < min({(i) + 1, N}); ++j) {

for (int k = max({i, 0}); k < N; ++k) {

for (int l = 0; l < min({(j) + 1, N}); ++l) {

int lp = j;
int jp = k;
int ip = l;
F[i][j][k][l] += F[ip][jp][kp][lp];
}
}
}
}
for (int i = 0; i < N; ++i) {

int ip = i;
for (int j = 0; j < min({(i) + 1, N}); ++j) {

int lp = j;
for (int k = 0; k < min({(j) + 1, N}); ++k) {

for (int l = 0; l < min({(k) + 1, N}); ++l) {

int kp = k;
int jp = l;
F[i][j][k][l] += F[ip][jp][kp][lp];
}
}
}
}
for (int i = 0; i < N; ++i) {

int jp = i;
for (int j = max({i, 0}); j < N; ++j) {

for (int k = 0; k < min({(i) + 1, N}); ++k) {

int lp = j;
for (int l = 0; l < min({(k) + 1, N}); ++l) {

int kp = k;
int ip = l;
F[i][j][k][l] += F[ip][jp][kp][lp];
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int l = 0; l < min({(i) + 1, N}); ++l) {

int kp = i;
for (int j = max({i, 0}); j < N; ++j) {

int jp = l;
int lp = j;
for (int k = max({j, 0}); k < N; ++k) {

int ip = k;
F[i][j][k][l] += F[ip][jp][kp][lp];
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int l = 0; l < min({(i) + 1, N}); ++l) {

int jp = i;
int kp = l;
for (int j = 0; j < N; ++j) {

int lp = j;
for (int k = max({i, 0}); k < min({(j) + 1, N}); ++k) {

int ip = k;
F[i][j][k][l] += F[ip][jp][kp][lp];
}
}
}
}
for (int i = 0; i < N; ++i) {

int lp = i;
for (int j = max({i, 0}); j < N; ++j) {

int ip = j;
for (int k = max({j, 0}); k < N; ++k) {

for (int l = max({k, 0}); l < N; ++l) {

int jp = k;
int kp = l;
F[i][j][k][l] += F[ip][jp][kp][lp];
}
}
}
}
for (int i = 0; i < N; ++i) {

int kp = i;
for (int j = max({i, 0}); j < N; ++j) {

int ip = j;
for (int k = 0; k < N; ++k) {

for (int l = max({j, 0}); l < min({(k) + 1, N}); ++l) {

int jp = k;
int lp = l;
F[i][j][k][l] += F[ip][jp][kp][lp];
}
}
}
}
for (int i = 0; i < N; ++i) {

int lp = i;
for (int j = 0; j < N; ++j) {

for (int l = max({j, 0}); l < N; ++l) {

int ip = j;
for (int k = max({i, 0}); k < min({(j) + 1, N}); ++k) {

int jp = l;
int kp = k;
F[i][j][k][l] += F[ip][jp][kp][lp];
}
}
}
}
for (int i = 0; i < N; ++i) {

int jp = i;
for (int k = max({i, 0}); k < N; ++k) {

int kp = k;
for (int j = 0; j < N; ++j) {

for (int l = max({k, 0}); l < min({(j) + 1, N}); ++l) {

int ip = j;
int lp = l;
F[i][j][k][l] += F[ip][jp][kp][lp];
}
}
}
}
for (int i = 0; i < N; ++i) {

int kp = i;
for (int j = 0; j < N; ++j) {

for (int l = max({i, 0}); l < min({(j) + 1, N}); ++l) {

int ip = j;
for (int k = max({j, 0}); k < N; ++k) {

int jp = l;
int lp = k;
F[i][j][k][l] += F[ip][jp][kp][lp];
}
}
}
}
for (int i = 0; i < N; ++i) {

int jp = i;
for (int j = 0; j < N; ++j) {

int ip = j;
for (int k = 0; k < min({(j) + 1, N}); ++k) {

for (int l = max({i, 0}); l < min({(k) + 1, N}); ++l) {

int lp = k;
int kp = l;
F[i][j][k][l] += F[ip][jp][kp][lp];
}
}
}
}
for (int i = 0; i < N; ++i) {

int jp = i;
for (int j = 0; j < min({i, N}); ++j) {

int ip = j;
H[i][j] += H[ip][jp];
}
}
for (int i = 0; i < N; ++i) {

int kp = i;
for (int j = 0; j < min({(i) + 1, N}); ++j) {

for (int k = max({i, 0}); k < N; ++k) {

int jp = j;
int ip = k;
I[i][j][k] += I[ip][jp][kp];
}
}
}
for (int i = 0; i < N; ++i) {

int ip = i;
for (int j = 0; j < min({(i) + 1, N}); ++j) {

int kp = j;
for (int k = 0; k < min({(j) + 1, N}); ++k) {

int jp = k;
I[i][j][k] += I[ip][jp][kp];
}
}
}
for (int i = 0; i < N; ++i) {

int jp = i;
for (int j = max({i, 0}); j < N; ++j) {

for (int k = 0; k < min({(i) + 1, N}); ++k) {

int kp = j;
int ip = k;
I[i][j][k] += I[ip][jp][kp];
}
}
}
for (int i = 0; i < N; ++i) {

int kp = i;
for (int j = max({i, 0}); j < N; ++j) {

int ip = j;
for (int k = max({j, 0}); k < N; ++k) {

int jp = k;
I[i][j][k] += I[ip][jp][kp];
}
}
}
for (int i = 0; i < N; ++i) {

int jp = i;
for (int j = 0; j < N; ++j) {

int ip = j;
for (int k = max({i, 0}); k < min({(j) + 1, N}); ++k) {

int kp = k;
I[i][j][k] += I[ip][jp][kp];
}
}
}
for (int i = 0; i < N; ++i) {

for (int l = max({i, 0}); l < N; ++l) {

int lp = i;
int ip = l;
for (int j = 0; j < N; ++j) {

int jp = j;
for (int k = max({j, 0}); k < min({(i) + 1, N}); ++k) {

int kp = k;
J[i][j][k][l] += J[ip][jp][kp][lp];
}
}
}
}
for (int i = 0; i < N; ++i) {

int ip = i;
for (int k = 0; k < min({(i) + 1, N}); ++k) {

int lp = k;
for (int j = 0; j < N; ++j) {

for (int l = max({j, 0}); l < min({(k) + 1, N}); ++l) {

int jp = j;
int kp = l;
J[i][j][k][l] += J[ip][jp][kp][lp];
}
}
}
}
for (int i = 0; i < N; ++i) {

int kp = i;
for (int k = max({i, 0}); k < N; ++k) {

int lp = k;
for (int j = 0; j < N; ++j) {

for (int l = max({j, 0}); l < min({(i) + 1, N}); ++l) {

int jp = j;
int ip = l;
J[i][j][k][l] += J[ip][jp][kp][lp];
}
}
}
}
for (int i = 0; i < N; ++i) {

int lp = i;
for (int j = 0; j < min({(i) + 1, N}); ++j) {

for (int k = max({i, 0}); k < N; ++k) {

int jp = j;
for (int l = max({k, 0}); l < N; ++l) {

int ip = k;
int kp = l;
J[i][j][k][l] += J[ip][jp][kp][lp];
}
}
}
}
for (int i = 0; i < N; ++i) {

int kp = i;
for (int j = 0; j < min({(i) + 1, N}); ++j) {

int jp = j;
for (int k = 0; k < N; ++k) {

for (int l = max({i, 0}); l < min({(k) + 1, N}); ++l) {

int ip = k;
int lp = l;
J[i][j][k][l] += J[ip][jp][kp][lp];
}
}
}
}
for (int i = 0; i < N; ++i) {

int ip = i;
for (int j = 0; j < N; ++j) {

for (int l = max({j, 0}); l < min({(i) + 1, N}); ++l) {

int kp = j;
for (int k = 0; k < min({(j) + 1, N}); ++k) {

int lp = l;
int jp = k;
J[i][j][k][l] += J[ip][jp][kp][lp];
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int l = max({i, 0}); l < N; ++l) {

int lp = i;
for (int j = 0; j < min({(i) + 1, N}); ++j) {

int ip = l;
int kp = j;
for (int k = 0; k < min({(j) + 1, N}); ++k) {

int jp = k;
J[i][j][k][l] += J[ip][jp][kp][lp];
}
}
}
}
for (int i = 0; i < N; ++i) {

int ip = i;
for (int j = 0; j < min({(i) + 1, N}); ++j) {

int kp = j;
for (int k = 0; k < N; ++k) {

for (int l = max({k, 0}); l < min({(j) + 1, N}); ++l) {

int lp = k;
int jp = l;
J[i][j][k][l] += J[ip][jp][kp][lp];
}
}
}
}
for (int i = 0; i < N; ++i) {

int jp = i;
for (int j = max({i, 0}); j < N; ++j) {

int kp = j;
for (int k = 0; k < N; ++k) {

for (int l = max({k, 0}); l < min({(i) + 1, N}); ++l) {

int lp = k;
int ip = l;
J[i][j][k][l] += J[ip][jp][kp][lp];
}
}
}
}
for (int i = 0; i < N; ++i) {

int lp = i;
for (int j = max({i, 0}); j < N; ++j) {

for (int k = 0; k < min({(i) + 1, N}); ++k) {

for (int l = max({j, 0}); l < N; ++l) {

int kp = j;
int ip = k;
int jp = l;
J[i][j][k][l] += J[ip][jp][kp][lp];
}
}
}
}
for (int i = 0; i < N; ++i) {

int jp = i;
for (int k = 0; k < min({(i) + 1, N}); ++k) {

int ip = k;
for (int j = 0; j < N; ++j) {

for (int l = max({i, 0}); l < min({(j) + 1, N}); ++l) {

int kp = j;
int lp = l;
J[i][j][k][l] += J[ip][jp][kp][lp];
}
}
}
}
for (int i = 0; i < N; ++i) {

int ip = i;
for (int j = 0; j < N; ++j) {

for (int l = 0; l < min({(j) + 1, N}); ++l) {

int lp = j;
for (int k = max({j, 0}); k < min({(i) + 1, N}); ++k) {

int kp = l;
int jp = k;
J[i][j][k][l] += J[ip][jp][kp][lp];
}
}
}
}
for (int i = 0; i < N; ++i) {

int kp = i;
for (int j = 0; j < min({(i) + 1, N}); ++j) {

for (int k = max({i, 0}); k < N; ++k) {

for (int l = 0; l < min({(j) + 1, N}); ++l) {

int lp = j;
int jp = k;
int ip = l;
J[i][j][k][l] += J[ip][jp][kp][lp];
}
}
}
}
for (int i = 0; i < N; ++i) {

int ip = i;
for (int j = 0; j < min({(i) + 1, N}); ++j) {

int lp = j;
for (int k = 0; k < min({(j) + 1, N}); ++k) {

for (int l = 0; l < min({(k) + 1, N}); ++l) {

int kp = k;
int jp = l;
J[i][j][k][l] += J[ip][jp][kp][lp];
}
}
}
}
for (int i = 0; i < N; ++i) {

int jp = i;
for (int j = max({i, 0}); j < N; ++j) {

for (int k = 0; k < min({(i) + 1, N}); ++k) {

int lp = j;
for (int l = 0; l < min({(k) + 1, N}); ++l) {

int kp = k;
int ip = l;
J[i][j][k][l] += J[ip][jp][kp][lp];
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int l = 0; l < min({(i) + 1, N}); ++l) {

int kp = i;
for (int j = max({i, 0}); j < N; ++j) {

int jp = l;
int lp = j;
for (int k = max({j, 0}); k < N; ++k) {

int ip = k;
J[i][j][k][l] += J[ip][jp][kp][lp];
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int l = 0; l < min({(i) + 1, N}); ++l) {

int jp = i;
int kp = l;
for (int j = 0; j < N; ++j) {

int lp = j;
for (int k = max({i, 0}); k < min({(j) + 1, N}); ++k) {

int ip = k;
J[i][j][k][l] += J[ip][jp][kp][lp];
}
}
}
}
for (int i = 0; i < N; ++i) {

int lp = i;
for (int j = max({i, 0}); j < N; ++j) {

int ip = j;
for (int k = max({j, 0}); k < N; ++k) {

for (int l = max({k, 0}); l < N; ++l) {

int jp = k;
int kp = l;
J[i][j][k][l] += J[ip][jp][kp][lp];
}
}
}
}
for (int i = 0; i < N; ++i) {

int kp = i;
for (int j = max({i, 0}); j < N; ++j) {

int ip = j;
for (int k = 0; k < N; ++k) {

for (int l = max({j, 0}); l < min({(k) + 1, N}); ++l) {

int jp = k;
int lp = l;
J[i][j][k][l] += J[ip][jp][kp][lp];
}
}
}
}
for (int i = 0; i < N; ++i) {

int lp = i;
for (int j = 0; j < N; ++j) {

for (int l = max({j, 0}); l < N; ++l) {

int ip = j;
for (int k = max({i, 0}); k < min({(j) + 1, N}); ++k) {

int jp = l;
int kp = k;
J[i][j][k][l] += J[ip][jp][kp][lp];
}
}
}
}
for (int i = 0; i < N; ++i) {

int jp = i;
for (int k = max({i, 0}); k < N; ++k) {

int kp = k;
for (int j = 0; j < N; ++j) {

for (int l = max({k, 0}); l < min({(j) + 1, N}); ++l) {

int ip = j;
int lp = l;
J[i][j][k][l] += J[ip][jp][kp][lp];
}
}
}
}
for (int i = 0; i < N; ++i) {

int kp = i;
for (int j = 0; j < N; ++j) {

for (int l = max({i, 0}); l < min({(j) + 1, N}); ++l) {

int ip = j;
for (int k = max({j, 0}); k < N; ++k) {

int jp = l;
int lp = k;
J[i][j][k][l] += J[ip][jp][kp][lp];
}
}
}
}
for (int i = 0; i < N; ++i) {

int jp = i;
for (int j = 0; j < N; ++j) {

int ip = j;
for (int k = 0; k < min({(j) + 1, N}); ++k) {

for (int l = max({i, 0}); l < min({(k) + 1, N}); ++l) {

int lp = k;
int kp = l;
J[i][j][k][l] += J[ip][jp][kp][lp];
}
}
}
}
end_reconstruction = duration_cast<microseconds>(system_clock::now().time_since_epoch()).count();
time_reconstruction = end_reconstruction - start_reconstruction;
cout << time_reconstruction << endl;
cerr << A[0][0] << endl;
cerr << f[0] << endl;
cerr << B[0][0][0] << endl;
cerr << C[0][0][0][0] << endl;
cerr << D[0][0] << endl;
cerr << g[0] << endl;
cerr << E[0][0][0] << endl;
cerr << F[0][0][0][0] << endl;
cerr << H[0][0] << endl;
cerr << I[0][0][0] << endl;
cerr << J[0][0][0][0] << endl;
for (size_t i0 = 0; i0 < N; ++i0) {delete[] A[i0];
}delete[] A;
delete[] f;
for (size_t i0 = 0; i0 < N; ++i0) {
for (size_t i1 = 0; i1 < N; ++i1) {delete[] B[i0][i1];
}
delete[] B[i0];
}delete[] B;
for (size_t i0 = 0; i0 < N; ++i0) {
for (size_t i1 = 0; i1 < N; ++i1) {
for (size_t i2 = 0; i2 < N; ++i2) {delete[] C[i0][i1][i2];
}
delete[] C[i0][i1];
}
delete[] C[i0];
}delete[] C;
for (size_t i0 = 0; i0 < N; ++i0) {delete[] D[i0];
}delete[] D;
delete[] g;
for (size_t i0 = 0; i0 < N; ++i0) {
for (size_t i1 = 0; i1 < N; ++i1) {delete[] E[i0][i1];
}
delete[] E[i0];
}delete[] E;
for (size_t i0 = 0; i0 < N; ++i0) {
for (size_t i1 = 0; i1 < N; ++i1) {
for (size_t i2 = 0; i2 < N; ++i2) {delete[] F[i0][i1][i2];
}
delete[] F[i0][i1];
}
delete[] F[i0];
}delete[] F;
for (size_t i0 = 0; i0 < N; ++i0) {delete[] H[i0];
}delete[] H;
for (size_t i0 = 0; i0 < N; ++i0) {
for (size_t i1 = 0; i1 < N; ++i1) {delete[] I[i0][i1];
}
delete[] I[i0];
}delete[] I;
for (size_t i0 = 0; i0 < N; ++i0) {
for (size_t i1 = 0; i1 < N; ++i1) {
for (size_t i2 = 0; i2 < N; ++i2) {delete[] J[i0][i1][i2];
}
delete[] J[i0][i1];
}
delete[] J[i0];
}delete[] J;
return 0;
}