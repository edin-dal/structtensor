
#include <iostream>
#include <random>
#include <algorithm>
#include <chrono>

using namespace std;
using namespace std::chrono;

extern "C"
void fn(double ** A, double * f, double *** B, double **** C, int N) {


long time_computation = 0, start_computation, end_computation;
start_computation = duration_cast<microseconds>(system_clock::now().time_since_epoch()).count();
for (int i = 0; i < N; ++i) {

for (int j = max({i, 0}); j < N; ++j) {

A[i][j] = (f[i] * f[j]);
}
}
for (int i = 0; i < N; ++i) {

for (int j = 0; j < N; ++j) {

for (int k = max({j, 0}); k < min({(i) + 1, N}); ++k) {

B[i][j][k] = (f[j] * f[k] * f[i]);
}
}
}
for (int i = 0; i < N; ++i) {

for (int j = 0; j < N; ++j) {

for (int k = max({j, 0}); k < N; ++k) {

for (int l = max({k, 0}); l < min({(i) + 1, N}); ++l) {

C[i][j][k][l] = (f[j] * f[k] * f[l] * f[i]);
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
A[i][j] = A[ip][jp];
}
}
for (int i = 0; i < N; ++i) {

int kp = i;
for (int j = 0; j < min({(i) + 1, N}); ++j) {

for (int k = max({i, 0}); k < N; ++k) {

int jp = j;
int ip = k;
B[i][j][k] = B[ip][jp][kp];
}
}
}
for (int i = 0; i < N; ++i) {

int ip = i;
for (int j = 0; j < min({(i) + 1, N}); ++j) {

int kp = j;
for (int k = 0; k < min({(j) + 1, N}); ++k) {

int jp = k;
B[i][j][k] = B[ip][jp][kp];
}
}
}
for (int i = 0; i < N; ++i) {

int jp = i;
for (int j = max({i, 0}); j < N; ++j) {

for (int k = 0; k < min({(i) + 1, N}); ++k) {

int kp = j;
int ip = k;
B[i][j][k] = B[ip][jp][kp];
}
}
}
for (int i = 0; i < N; ++i) {

int kp = i;
for (int j = max({i, 0}); j < N; ++j) {

int ip = j;
for (int k = max({j, 0}); k < N; ++k) {

int jp = k;
B[i][j][k] = B[ip][jp][kp];
}
}
}
for (int i = 0; i < N; ++i) {

int jp = i;
for (int j = 0; j < N; ++j) {

int ip = j;
for (int k = max({i, 0}); k < min({(j) + 1, N}); ++k) {

int kp = k;
B[i][j][k] = B[ip][jp][kp];
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
C[i][j][k][l] = C[ip][jp][kp][lp];
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
C[i][j][k][l] = C[ip][jp][kp][lp];
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
C[i][j][k][l] = C[ip][jp][kp][lp];
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
C[i][j][k][l] = C[ip][jp][kp][lp];
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
C[i][j][k][l] = C[ip][jp][kp][lp];
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
C[i][j][k][l] = C[ip][jp][kp][lp];
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
C[i][j][k][l] = C[ip][jp][kp][lp];
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
C[i][j][k][l] = C[ip][jp][kp][lp];
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
C[i][j][k][l] = C[ip][jp][kp][lp];
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
C[i][j][k][l] = C[ip][jp][kp][lp];
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
C[i][j][k][l] = C[ip][jp][kp][lp];
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
C[i][j][k][l] = C[ip][jp][kp][lp];
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
C[i][j][k][l] = C[ip][jp][kp][lp];
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
C[i][j][k][l] = C[ip][jp][kp][lp];
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
C[i][j][k][l] = C[ip][jp][kp][lp];
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
C[i][j][k][l] = C[ip][jp][kp][lp];
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
C[i][j][k][l] = C[ip][jp][kp][lp];
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
C[i][j][k][l] = C[ip][jp][kp][lp];
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
C[i][j][k][l] = C[ip][jp][kp][lp];
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
C[i][j][k][l] = C[ip][jp][kp][lp];
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
C[i][j][k][l] = C[ip][jp][kp][lp];
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
C[i][j][k][l] = C[ip][jp][kp][lp];
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
C[i][j][k][l] = C[ip][jp][kp][lp];
}
}
}
}
end_reconstruction = duration_cast<microseconds>(system_clock::now().time_since_epoch()).count();
time_reconstruction = end_reconstruction - start_reconstruction;
cout << time_reconstruction << endl;

}