
#include <iostream>
#include <random>
#include <algorithm>
#include <chrono>

using namespace std;
using namespace std::chrono;

extern "C"
void fn(double ** A, double * f, double *** B, double **** C, double ***** D, double ****** E, double ** F, double * g, double *** G, double **** H, double ***** I, double ****** J, double ** K, double *** L, double **** M, double ***** P, double ****** O, int N) {


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

for (int j = 0; j < N; ++j) {

for (int k = max({j, 0}); k < N; ++k) {

for (int l = max({k, 0}); l < N; ++l) {

for (int s = max({l, 0}); s < min({(i) + 1, N}); ++s) {

D[i][j][k][l][s] += (f[j] * f[k] * f[l] * f[s] * f[i]);
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int j = 0; j < N; ++j) {

for (int k = max({j, 0}); k < N; ++k) {

for (int l = max({k, 0}); l < N; ++l) {

for (int s = max({l, 0}); s < N; ++s) {

for (int t = max({s, 0}); t < min({(i) + 1, N}); ++t) {

E[i][j][k][l][s][t] += (f[j] * f[k] * f[l] * f[s] * f[t] * f[i]);
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int j = max({i, 0}); j < N; ++j) {

F[i][j] += (g[i] * g[j]);
}
}
for (int i = 0; i < N; ++i) {

for (int j = 0; j < N; ++j) {

for (int k = max({j, 0}); k < min({(i) + 1, N}); ++k) {

G[i][j][k] += (g[j] * g[k] * g[i]);
}
}
}
for (int i = 0; i < N; ++i) {

for (int j = 0; j < N; ++j) {

for (int k = max({j, 0}); k < N; ++k) {

for (int l = max({k, 0}); l < min({(i) + 1, N}); ++l) {

H[i][j][k][l] += (g[j] * g[k] * g[l] * g[i]);
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int j = 0; j < N; ++j) {

for (int k = max({j, 0}); k < N; ++k) {

for (int l = max({k, 0}); l < N; ++l) {

for (int s = max({l, 0}); s < min({(i) + 1, N}); ++s) {

I[i][j][k][l][s] += (g[j] * g[k] * g[l] * g[s] * g[i]);
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int j = 0; j < N; ++j) {

for (int k = max({j, 0}); k < N; ++k) {

for (int l = max({k, 0}); l < N; ++l) {

for (int s = max({l, 0}); s < N; ++s) {

for (int t = max({s, 0}); t < min({(i) + 1, N}); ++t) {

J[i][j][k][l][s][t] += (g[j] * g[k] * g[l] * g[s] * g[t] * g[i]);
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int j = max({i, 0}); j < N; ++j) {

K[i][j] += (f[i] * f[j]);
}
}
for (int i = 0; i < N; ++i) {

for (int j = max({i, 0}); j < N; ++j) {

K[i][j] += (g[i] * g[j]);
}
}
for (int i = 0; i < N; ++i) {

for (int j = 0; j < N; ++j) {

for (int k = max({j, 0}); k < min({(i) + 1, N}); ++k) {

L[i][j][k] += (f[j] * f[k] * f[i]);
}
}
}
for (int i = 0; i < N; ++i) {

for (int j = 0; j < N; ++j) {

for (int k = max({j, 0}); k < min({(i) + 1, N}); ++k) {

L[i][j][k] += (g[j] * g[k] * g[i]);
}
}
}
for (int i = 0; i < N; ++i) {

for (int j = 0; j < N; ++j) {

for (int k = max({j, 0}); k < N; ++k) {

for (int l = max({k, 0}); l < min({(i) + 1, N}); ++l) {

M[i][j][k][l] += (f[j] * f[k] * f[l] * f[i]);
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int j = 0; j < N; ++j) {

for (int k = max({j, 0}); k < N; ++k) {

for (int l = max({k, 0}); l < min({(i) + 1, N}); ++l) {

M[i][j][k][l] += (g[j] * g[k] * g[l] * g[i]);
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int j = 0; j < N; ++j) {

for (int k = max({j, 0}); k < N; ++k) {

for (int l = max({k, 0}); l < N; ++l) {

for (int s = max({l, 0}); s < min({(i) + 1, N}); ++s) {

P[i][j][k][l][s] += (f[j] * f[k] * f[l] * f[s] * f[i]);
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int j = 0; j < N; ++j) {

for (int k = max({j, 0}); k < N; ++k) {

for (int l = max({k, 0}); l < N; ++l) {

for (int s = max({l, 0}); s < min({(i) + 1, N}); ++s) {

P[i][j][k][l][s] += (g[j] * g[k] * g[l] * g[s] * g[i]);
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int j = 0; j < N; ++j) {

for (int k = max({j, 0}); k < N; ++k) {

for (int l = max({k, 0}); l < N; ++l) {

for (int s = max({l, 0}); s < N; ++s) {

for (int t = max({s, 0}); t < min({(i) + 1, N}); ++t) {

O[i][j][k][l][s][t] += (f[j] * f[k] * f[l] * f[s] * f[t] * f[i]);
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int j = 0; j < N; ++j) {

for (int k = max({j, 0}); k < N; ++k) {

for (int l = max({k, 0}); l < N; ++l) {

for (int s = max({l, 0}); s < N; ++s) {

for (int t = max({s, 0}); t < min({(i) + 1, N}); ++t) {

O[i][j][k][l][s][t] += (g[j] * g[k] * g[l] * g[s] * g[t] * g[i]);
}
}
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

for (int j = 0; j < min({i, N}); ++j) {



A[i][j] += A[ip][jp];
}
}
for (int i = 0; i < N; ++i) {

for (int j = 0; j < min({(i) + 1, N}); ++j) {

for (int k = max({i, 0}); k < N; ++k) {




B[i][j][k] += B[ip][jp][kp];
}
}
}
for (int i = 0; i < N; ++i) {

for (int j = 0; j < min({(i) + 1, N}); ++j) {

for (int k = 0; k < min({(j) + 1, N}); ++k) {




B[i][j][k] += B[ip][jp][kp];
}
}
}
for (int i = 0; i < N; ++i) {

for (int j = max({i, 0}); j < N; ++j) {

for (int k = 0; k < min({(i) + 1, N}); ++k) {




B[i][j][k] += B[ip][jp][kp];
}
}
}
for (int i = 0; i < N; ++i) {

for (int j = max({i, 0}); j < N; ++j) {

for (int k = max({j, 0}); k < N; ++k) {




B[i][j][k] += B[ip][jp][kp];
}
}
}
for (int i = 0; i < N; ++i) {

for (int j = 0; j < N; ++j) {

for (int k = max({i, 0}); k < min({(j) + 1, N}); ++k) {




B[i][j][k] += B[ip][jp][kp];
}
}
}
for (int i = 0; i < N; ++i) {

for (int l = max({i, 0}); l < N; ++l) {

for (int j = 0; j < N; ++j) {

for (int k = max({j, 0}); k < min({(i) + 1, N}); ++k) {





C[i][j][k][l] += C[ip][jp][kp][lp];
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int j = 0; j < N; ++j) {

for (int k = 0; k < min({(i) + 1, N}); ++k) {

for (int l = max({j, 0}); l < min({(k) + 1, N}); ++l) {





C[i][j][k][l] += C[ip][jp][kp][lp];
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int j = 0; j < N; ++j) {

for (int k = max({i, 0}); k < N; ++k) {

for (int l = max({j, 0}); l < min({(i) + 1, N}); ++l) {





C[i][j][k][l] += C[ip][jp][kp][lp];
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int j = 0; j < min({(i) + 1, N}); ++j) {

for (int k = max({i, 0}); k < N; ++k) {

for (int l = max({k, 0}); l < N; ++l) {





C[i][j][k][l] += C[ip][jp][kp][lp];
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int j = 0; j < min({(i) + 1, N}); ++j) {

for (int k = 0; k < N; ++k) {

for (int l = max({i, 0}); l < min({(k) + 1, N}); ++l) {





C[i][j][k][l] += C[ip][jp][kp][lp];
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int j = 0; j < N; ++j) {

for (int l = max({j, 0}); l < min({(i) + 1, N}); ++l) {

for (int k = 0; k < min({(j) + 1, N}); ++k) {





C[i][j][k][l] += C[ip][jp][kp][lp];
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int l = max({i, 0}); l < N; ++l) {

for (int j = 0; j < min({(i) + 1, N}); ++j) {

for (int k = 0; k < min({(j) + 1, N}); ++k) {





C[i][j][k][l] += C[ip][jp][kp][lp];
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int j = 0; j < min({(i) + 1, N}); ++j) {

for (int k = 0; k < N; ++k) {

for (int l = max({k, 0}); l < min({(j) + 1, N}); ++l) {





C[i][j][k][l] += C[ip][jp][kp][lp];
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int j = max({i, 0}); j < N; ++j) {

for (int k = 0; k < N; ++k) {

for (int l = max({k, 0}); l < min({(i) + 1, N}); ++l) {





C[i][j][k][l] += C[ip][jp][kp][lp];
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int j = max({i, 0}); j < N; ++j) {

for (int k = 0; k < min({(i) + 1, N}); ++k) {

for (int l = max({j, 0}); l < N; ++l) {





C[i][j][k][l] += C[ip][jp][kp][lp];
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int j = 0; j < N; ++j) {

for (int k = 0; k < min({(i) + 1, N}); ++k) {

for (int l = max({i, 0}); l < min({(j) + 1, N}); ++l) {





C[i][j][k][l] += C[ip][jp][kp][lp];
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int j = 0; j < N; ++j) {

for (int l = 0; l < min({(j) + 1, N}); ++l) {

for (int k = max({j, 0}); k < min({(i) + 1, N}); ++k) {





C[i][j][k][l] += C[ip][jp][kp][lp];
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int j = 0; j < min({(i) + 1, N}); ++j) {

for (int k = max({i, 0}); k < N; ++k) {

for (int l = 0; l < min({(j) + 1, N}); ++l) {





C[i][j][k][l] += C[ip][jp][kp][lp];
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int j = 0; j < min({(i) + 1, N}); ++j) {

for (int k = 0; k < min({(j) + 1, N}); ++k) {

for (int l = 0; l < min({(k) + 1, N}); ++l) {





C[i][j][k][l] += C[ip][jp][kp][lp];
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int j = max({i, 0}); j < N; ++j) {

for (int k = 0; k < min({(i) + 1, N}); ++k) {

for (int l = 0; l < min({(k) + 1, N}); ++l) {





C[i][j][k][l] += C[ip][jp][kp][lp];
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int l = 0; l < min({(i) + 1, N}); ++l) {

for (int j = max({i, 0}); j < N; ++j) {

for (int k = max({j, 0}); k < N; ++k) {





C[i][j][k][l] += C[ip][jp][kp][lp];
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int l = 0; l < min({(i) + 1, N}); ++l) {

for (int j = 0; j < N; ++j) {

for (int k = max({i, 0}); k < min({(j) + 1, N}); ++k) {





C[i][j][k][l] += C[ip][jp][kp][lp];
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int j = max({i, 0}); j < N; ++j) {

for (int k = max({j, 0}); k < N; ++k) {

for (int l = max({k, 0}); l < N; ++l) {





C[i][j][k][l] += C[ip][jp][kp][lp];
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int j = max({i, 0}); j < N; ++j) {

for (int k = 0; k < N; ++k) {

for (int l = max({j, 0}); l < min({(k) + 1, N}); ++l) {





C[i][j][k][l] += C[ip][jp][kp][lp];
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int j = 0; j < N; ++j) {

for (int l = max({j, 0}); l < N; ++l) {

for (int k = max({i, 0}); k < min({(j) + 1, N}); ++k) {





C[i][j][k][l] += C[ip][jp][kp][lp];
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int j = 0; j < N; ++j) {

for (int k = max({i, 0}); k < N; ++k) {

for (int l = max({k, 0}); l < min({(j) + 1, N}); ++l) {





C[i][j][k][l] += C[ip][jp][kp][lp];
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int j = 0; j < N; ++j) {

for (int l = max({i, 0}); l < min({(j) + 1, N}); ++l) {

for (int k = max({j, 0}); k < N; ++k) {





C[i][j][k][l] += C[ip][jp][kp][lp];
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int j = 0; j < N; ++j) {

for (int k = 0; k < min({(j) + 1, N}); ++k) {

for (int l = max({i, 0}); l < min({(k) + 1, N}); ++l) {





C[i][j][k][l] += C[ip][jp][kp][lp];
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int s = max({i, 0}); s < N; ++s) {

for (int j = 0; j < N; ++j) {

for (int k = max({j, 0}); k < N; ++k) {

for (int l = max({k, 0}); l < min({(i) + 1, N}); ++l) {






D[i][j][k][l][s] += D[ip][jp][kp][lp][sp];
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int l = 0; l < min({(i) + 1, N}); ++l) {

for (int j = 0; j < N; ++j) {

for (int k = max({j, 0}); k < N; ++k) {

for (int s = max({k, 0}); s < min({(l) + 1, N}); ++s) {






D[i][j][k][l][s] += D[ip][jp][kp][lp][sp];
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int l = max({i, 0}); l < N; ++l) {

for (int j = 0; j < N; ++j) {

for (int k = max({j, 0}); k < N; ++k) {

for (int s = max({k, 0}); s < min({(i) + 1, N}); ++s) {






D[i][j][k][l][s] += D[ip][jp][kp][lp][sp];
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int l = max({i, 0}); l < N; ++l) {

for (int s = max({l, 0}); s < N; ++s) {

for (int j = 0; j < N; ++j) {

for (int k = max({j, 0}); k < min({(i) + 1, N}); ++k) {






D[i][j][k][l][s] += D[ip][jp][kp][lp][sp];
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int j = 0; j < N; ++j) {

for (int k = max({j, 0}); k < min({(i) + 1, N}); ++k) {

for (int l = 0; l < N; ++l) {

for (int s = max({i, 0}); s < min({(l) + 1, N}); ++s) {






D[i][j][k][l][s] += D[ip][jp][kp][lp][sp];
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int j = 0; j < N; ++j) {

for (int k = 0; k < N; ++k) {

for (int s = max({k, 0}); s < min({(i) + 1, N}); ++s) {

for (int l = max({j, 0}); l < min({(k) + 1, N}); ++l) {






D[i][j][k][l][s] += D[ip][jp][kp][lp][sp];
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int s = max({i, 0}); s < N; ++s) {

for (int k = 0; k < min({(i) + 1, N}); ++k) {

for (int j = 0; j < N; ++j) {

for (int l = max({j, 0}); l < min({(k) + 1, N}); ++l) {






D[i][j][k][l][s] += D[ip][jp][kp][lp][sp];
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int j = 0; j < N; ++j) {

for (int k = 0; k < min({(i) + 1, N}); ++k) {

for (int l = max({j, 0}); l < N; ++l) {

for (int s = max({l, 0}); s < min({(k) + 1, N}); ++s) {






D[i][j][k][l][s] += D[ip][jp][kp][lp][sp];
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int j = 0; j < N; ++j) {

for (int k = max({i, 0}); k < N; ++k) {

for (int l = max({j, 0}); l < N; ++l) {

for (int s = max({l, 0}); s < min({(i) + 1, N}); ++s) {






D[i][j][k][l][s] += D[ip][jp][kp][lp][sp];
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int j = 0; j < N; ++j) {

for (int k = max({i, 0}); k < N; ++k) {

for (int l = max({j, 0}); l < min({(i) + 1, N}); ++l) {

for (int s = max({k, 0}); s < N; ++s) {






D[i][j][k][l][s] += D[ip][jp][kp][lp][sp];
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int j = 0; j < N; ++j) {

for (int l = max({j, 0}); l < min({(i) + 1, N}); ++l) {

for (int k = 0; k < N; ++k) {

for (int s = max({i, 0}); s < min({(k) + 1, N}); ++s) {






D[i][j][k][l][s] += D[ip][jp][kp][lp][sp];
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int j = 0; j < N; ++j) {

for (int k = 0; k < N; ++k) {

for (int s = max({j, 0}); s < min({(k) + 1, N}); ++s) {

for (int l = max({k, 0}); l < min({(i) + 1, N}); ++l) {






D[i][j][k][l][s] += D[ip][jp][kp][lp][sp];
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int l = max({i, 0}); l < N; ++l) {

for (int k = 0; k < min({(i) + 1, N}); ++k) {

for (int j = 0; j < N; ++j) {

for (int s = max({j, 0}); s < min({(k) + 1, N}); ++s) {






D[i][j][k][l][s] += D[ip][jp][kp][lp][sp];
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int j = 0; j < N; ++j) {

for (int k = 0; k < min({(i) + 1, N}); ++k) {

for (int l = 0; l < min({(k) + 1, N}); ++l) {

for (int s = max({j, 0}); s < min({(l) + 1, N}); ++s) {






D[i][j][k][l][s] += D[ip][jp][kp][lp][sp];
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int l = 0; l < min({(i) + 1, N}); ++l) {

for (int k = max({i, 0}); k < N; ++k) {

for (int j = 0; j < N; ++j) {

for (int s = max({j, 0}); s < min({(l) + 1, N}); ++s) {






D[i][j][k][l][s] += D[ip][jp][kp][lp][sp];
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int j = 0; j < N; ++j) {

for (int k = max({i, 0}); k < N; ++k) {

for (int s = max({j, 0}); s < min({(i) + 1, N}); ++s) {

for (int l = max({k, 0}); l < N; ++l) {






D[i][j][k][l][s] += D[ip][jp][kp][lp][sp];
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int j = 0; j < N; ++j) {

for (int s = max({j, 0}); s < min({(i) + 1, N}); ++s) {

for (int k = 0; k < N; ++k) {

for (int l = max({i, 0}); l < min({(k) + 1, N}); ++l) {






D[i][j][k][l][s] += D[ip][jp][kp][lp][sp];
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int j = 0; j < min({(i) + 1, N}); ++j) {

for (int k = max({i, 0}); k < N; ++k) {

for (int l = max({k, 0}); l < N; ++l) {

for (int s = max({l, 0}); s < N; ++s) {






D[i][j][k][l][s] += D[ip][jp][kp][lp][sp];
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int j = 0; j < min({(i) + 1, N}); ++j) {

for (int k = max({i, 0}); k < N; ++k) {

for (int l = 0; l < N; ++l) {

for (int s = max({k, 0}); s < min({(l) + 1, N}); ++s) {






D[i][j][k][l][s] += D[ip][jp][kp][lp][sp];
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int j = 0; j < min({(i) + 1, N}); ++j) {

for (int k = 0; k < N; ++k) {

for (int s = max({k, 0}); s < N; ++s) {

for (int l = max({i, 0}); l < min({(k) + 1, N}); ++l) {






D[i][j][k][l][s] += D[ip][jp][kp][lp][sp];
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int l = max({i, 0}); l < N; ++l) {

for (int j = 0; j < min({(i) + 1, N}); ++j) {

for (int k = 0; k < N; ++k) {

for (int s = max({l, 0}); s < min({(k) + 1, N}); ++s) {






D[i][j][k][l][s] += D[ip][jp][kp][lp][sp];
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int j = 0; j < min({(i) + 1, N}); ++j) {

for (int k = 0; k < N; ++k) {

for (int s = max({i, 0}); s < min({(k) + 1, N}); ++s) {

for (int l = max({k, 0}); l < N; ++l) {






D[i][j][k][l][s] += D[ip][jp][kp][lp][sp];
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int j = 0; j < min({(i) + 1, N}); ++j) {

for (int k = 0; k < N; ++k) {

for (int l = 0; l < min({(k) + 1, N}); ++l) {

for (int s = max({i, 0}); s < min({(l) + 1, N}); ++s) {






D[i][j][k][l][s] += D[ip][jp][kp][lp][sp];
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int j = 0; j < N; ++j) {

for (int l = max({j, 0}); l < N; ++l) {

for (int k = 0; k < min({(j) + 1, N}); ++k) {

for (int s = max({l, 0}); s < min({(i) + 1, N}); ++s) {






D[i][j][k][l][s] += D[ip][jp][kp][lp][sp];
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int s = max({i, 0}); s < N; ++s) {

for (int j = 0; j < N; ++j) {

for (int l = max({j, 0}); l < min({(i) + 1, N}); ++l) {

for (int k = 0; k < min({(j) + 1, N}); ++k) {






D[i][j][k][l][s] += D[ip][jp][kp][lp][sp];
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int l = 0; l < min({(i) + 1, N}); ++l) {

for (int j = 0; j < N; ++j) {

for (int s = max({j, 0}); s < min({(l) + 1, N}); ++s) {

for (int k = 0; k < min({(j) + 1, N}); ++k) {






D[i][j][k][l][s] += D[ip][jp][kp][lp][sp];
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int l = max({i, 0}); l < N; ++l) {

for (int j = 0; j < N; ++j) {

for (int s = max({j, 0}); s < min({(i) + 1, N}); ++s) {

for (int k = 0; k < min({(j) + 1, N}); ++k) {






D[i][j][k][l][s] += D[ip][jp][kp][lp][sp];
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int l = max({i, 0}); l < N; ++l) {

for (int j = 0; j < min({(i) + 1, N}); ++j) {

for (int s = max({l, 0}); s < N; ++s) {

for (int k = 0; k < min({(j) + 1, N}); ++k) {






D[i][j][k][l][s] += D[ip][jp][kp][lp][sp];
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int j = 0; j < min({(i) + 1, N}); ++j) {

for (int k = 0; k < min({(j) + 1, N}); ++k) {

for (int l = 0; l < N; ++l) {

for (int s = max({i, 0}); s < min({(l) + 1, N}); ++s) {






D[i][j][k][l][s] += D[ip][jp][kp][lp][sp];
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int j = 0; j < N; ++j) {

for (int s = max({j, 0}); s < min({(i) + 1, N}); ++s) {

for (int k = 0; k < N; ++k) {

for (int l = max({k, 0}); l < min({(j) + 1, N}); ++l) {






D[i][j][k][l][s] += D[ip][jp][kp][lp][sp];
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int s = max({i, 0}); s < N; ++s) {

for (int j = 0; j < min({(i) + 1, N}); ++j) {

for (int k = 0; k < N; ++k) {

for (int l = max({k, 0}); l < min({(j) + 1, N}); ++l) {






D[i][j][k][l][s] += D[ip][jp][kp][lp][sp];
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int j = 0; j < min({(i) + 1, N}); ++j) {

for (int k = 0; k < N; ++k) {

for (int l = max({k, 0}); l < N; ++l) {

for (int s = max({l, 0}); s < min({(j) + 1, N}); ++s) {






D[i][j][k][l][s] += D[ip][jp][kp][lp][sp];
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int j = max({i, 0}); j < N; ++j) {

for (int k = 0; k < N; ++k) {

for (int l = max({k, 0}); l < N; ++l) {

for (int s = max({l, 0}); s < min({(i) + 1, N}); ++s) {






D[i][j][k][l][s] += D[ip][jp][kp][lp][sp];
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int j = max({i, 0}); j < N; ++j) {

for (int s = max({j, 0}); s < N; ++s) {

for (int k = 0; k < N; ++k) {

for (int l = max({k, 0}); l < min({(i) + 1, N}); ++l) {






D[i][j][k][l][s] += D[ip][jp][kp][lp][sp];
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int j = 0; j < N; ++j) {

for (int s = max({i, 0}); s < min({(j) + 1, N}); ++s) {

for (int k = 0; k < N; ++k) {

for (int l = max({k, 0}); l < min({(i) + 1, N}); ++l) {






D[i][j][k][l][s] += D[ip][jp][kp][lp][sp];
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int j = 0; j < N; ++j) {

for (int l = max({j, 0}); l < min({(i) + 1, N}); ++l) {

for (int k = 0; k < N; ++k) {

for (int s = max({k, 0}); s < min({(j) + 1, N}); ++s) {






D[i][j][k][l][s] += D[ip][jp][kp][lp][sp];
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int l = max({i, 0}); l < N; ++l) {

for (int j = 0; j < min({(i) + 1, N}); ++j) {

for (int k = 0; k < N; ++k) {

for (int s = max({k, 0}); s < min({(j) + 1, N}); ++s) {






D[i][j][k][l][s] += D[ip][jp][kp][lp][sp];
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int j = 0; j < min({(i) + 1, N}); ++j) {

for (int l = 0; l < min({(j) + 1, N}); ++l) {

for (int k = 0; k < N; ++k) {

for (int s = max({k, 0}); s < min({(l) + 1, N}); ++s) {






D[i][j][k][l][s] += D[ip][jp][kp][lp][sp];
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int l = 0; l < min({(i) + 1, N}); ++l) {

for (int j = max({i, 0}); j < N; ++j) {

for (int k = 0; k < N; ++k) {

for (int s = max({k, 0}); s < min({(l) + 1, N}); ++s) {






D[i][j][k][l][s] += D[ip][jp][kp][lp][sp];
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int j = max({i, 0}); j < N; ++j) {

for (int l = max({j, 0}); l < N; ++l) {

for (int k = 0; k < N; ++k) {

for (int s = max({k, 0}); s < min({(i) + 1, N}); ++s) {






D[i][j][k][l][s] += D[ip][jp][kp][lp][sp];
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int j = 0; j < N; ++j) {

for (int l = max({i, 0}); l < min({(j) + 1, N}); ++l) {

for (int k = 0; k < N; ++k) {

for (int s = max({k, 0}); s < min({(i) + 1, N}); ++s) {






D[i][j][k][l][s] += D[ip][jp][kp][lp][sp];
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int j = max({i, 0}); j < N; ++j) {

for (int k = 0; k < min({(i) + 1, N}); ++k) {

for (int l = max({j, 0}); l < N; ++l) {

for (int s = max({l, 0}); s < N; ++s) {






D[i][j][k][l][s] += D[ip][jp][kp][lp][sp];
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int j = max({i, 0}); j < N; ++j) {

for (int k = 0; k < min({(i) + 1, N}); ++k) {

for (int l = 0; l < N; ++l) {

for (int s = max({j, 0}); s < min({(l) + 1, N}); ++s) {






D[i][j][k][l][s] += D[ip][jp][kp][lp][sp];
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int j = 0; j < N; ++j) {

for (int k = 0; k < min({(i) + 1, N}); ++k) {

for (int s = max({j, 0}); s < N; ++s) {

for (int l = max({i, 0}); l < min({(j) + 1, N}); ++l) {






D[i][j][k][l][s] += D[ip][jp][kp][lp][sp];
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int l = max({i, 0}); l < N; ++l) {

for (int k = 0; k < min({(i) + 1, N}); ++k) {

for (int j = 0; j < N; ++j) {

for (int s = max({l, 0}); s < min({(j) + 1, N}); ++s) {






D[i][j][k][l][s] += D[ip][jp][kp][lp][sp];
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int j = 0; j < N; ++j) {

for (int k = 0; k < min({(i) + 1, N}); ++k) {

for (int s = max({i, 0}); s < min({(j) + 1, N}); ++s) {

for (int l = max({j, 0}); l < N; ++l) {






D[i][j][k][l][s] += D[ip][jp][kp][lp][sp];
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int j = 0; j < N; ++j) {

for (int k = 0; k < min({(i) + 1, N}); ++k) {

for (int l = 0; l < min({(j) + 1, N}); ++l) {

for (int s = max({i, 0}); s < min({(l) + 1, N}); ++s) {






D[i][j][k][l][s] += D[ip][jp][kp][lp][sp];
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int j = 0; j < N; ++j) {

for (int l = 0; l < min({(j) + 1, N}); ++l) {

for (int k = max({j, 0}); k < N; ++k) {

for (int s = max({k, 0}); s < min({(i) + 1, N}); ++s) {






D[i][j][k][l][s] += D[ip][jp][kp][lp][sp];
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int s = max({i, 0}); s < N; ++s) {

for (int j = 0; j < N; ++j) {

for (int l = 0; l < min({(j) + 1, N}); ++l) {

for (int k = max({j, 0}); k < min({(i) + 1, N}); ++k) {






D[i][j][k][l][s] += D[ip][jp][kp][lp][sp];
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int j = 0; j < N; ++j) {

for (int k = 0; k < min({(i) + 1, N}); ++k) {

for (int l = 0; l < min({(j) + 1, N}); ++l) {

for (int s = max({j, 0}); s < min({(k) + 1, N}); ++s) {






D[i][j][k][l][s] += D[ip][jp][kp][lp][sp];
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int j = 0; j < N; ++j) {

for (int k = max({i, 0}); k < N; ++k) {

for (int s = max({j, 0}); s < min({(i) + 1, N}); ++s) {

for (int l = 0; l < min({(j) + 1, N}); ++l) {






D[i][j][k][l][s] += D[ip][jp][kp][lp][sp];
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int j = 0; j < min({(i) + 1, N}); ++j) {

for (int k = max({i, 0}); k < N; ++k) {

for (int l = 0; l < min({(j) + 1, N}); ++l) {

for (int s = max({k, 0}); s < N; ++s) {






D[i][j][k][l][s] += D[ip][jp][kp][lp][sp];
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int j = 0; j < min({(i) + 1, N}); ++j) {

for (int l = 0; l < min({(j) + 1, N}); ++l) {

for (int k = 0; k < N; ++k) {

for (int s = max({i, 0}); s < min({(k) + 1, N}); ++s) {






D[i][j][k][l][s] += D[ip][jp][kp][lp][sp];
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int j = 0; j < N; ++j) {

for (int s = max({j, 0}); s < min({(i) + 1, N}); ++s) {

for (int k = 0; k < min({(j) + 1, N}); ++k) {

for (int l = 0; l < min({(k) + 1, N}); ++l) {






D[i][j][k][l][s] += D[ip][jp][kp][lp][sp];
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int s = max({i, 0}); s < N; ++s) {

for (int j = 0; j < min({(i) + 1, N}); ++j) {

for (int k = 0; k < min({(j) + 1, N}); ++k) {

for (int l = 0; l < min({(k) + 1, N}); ++l) {






D[i][j][k][l][s] += D[ip][jp][kp][lp][sp];
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int j = 0; j < min({(i) + 1, N}); ++j) {

for (int k = 0; k < N; ++k) {

for (int s = max({k, 0}); s < min({(j) + 1, N}); ++s) {

for (int l = 0; l < min({(k) + 1, N}); ++l) {






D[i][j][k][l][s] += D[ip][jp][kp][lp][sp];
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int j = max({i, 0}); j < N; ++j) {

for (int k = 0; k < N; ++k) {

for (int s = max({k, 0}); s < min({(i) + 1, N}); ++s) {

for (int l = 0; l < min({(k) + 1, N}); ++l) {






D[i][j][k][l][s] += D[ip][jp][kp][lp][sp];
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int j = max({i, 0}); j < N; ++j) {

for (int k = 0; k < min({(i) + 1, N}); ++k) {

for (int s = max({j, 0}); s < N; ++s) {

for (int l = 0; l < min({(k) + 1, N}); ++l) {






D[i][j][k][l][s] += D[ip][jp][kp][lp][sp];
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int j = 0; j < N; ++j) {

for (int k = 0; k < min({(i) + 1, N}); ++k) {

for (int s = max({i, 0}); s < min({(j) + 1, N}); ++s) {

for (int l = 0; l < min({(k) + 1, N}); ++l) {






D[i][j][k][l][s] += D[ip][jp][kp][lp][sp];
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int j = 0; j < N; ++j) {

for (int k = max({j, 0}); k < min({(i) + 1, N}); ++k) {

for (int l = 0; l < N; ++l) {

for (int s = max({l, 0}); s < min({(j) + 1, N}); ++s) {






D[i][j][k][l][s] += D[ip][jp][kp][lp][sp];
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int j = 0; j < min({(i) + 1, N}); ++j) {

for (int k = max({i, 0}); k < N; ++k) {

for (int l = 0; l < N; ++l) {

for (int s = max({l, 0}); s < min({(j) + 1, N}); ++s) {






D[i][j][k][l][s] += D[ip][jp][kp][lp][sp];
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int j = 0; j < min({(i) + 1, N}); ++j) {

for (int k = 0; k < min({(j) + 1, N}); ++k) {

for (int l = 0; l < N; ++l) {

for (int s = max({l, 0}); s < min({(k) + 1, N}); ++s) {






D[i][j][k][l][s] += D[ip][jp][kp][lp][sp];
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int j = max({i, 0}); j < N; ++j) {

for (int k = 0; k < min({(i) + 1, N}); ++k) {

for (int l = 0; l < N; ++l) {

for (int s = max({l, 0}); s < min({(k) + 1, N}); ++s) {






D[i][j][k][l][s] += D[ip][jp][kp][lp][sp];
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int j = max({i, 0}); j < N; ++j) {

for (int k = max({j, 0}); k < N; ++k) {

for (int l = 0; l < N; ++l) {

for (int s = max({l, 0}); s < min({(i) + 1, N}); ++s) {






D[i][j][k][l][s] += D[ip][jp][kp][lp][sp];
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int j = 0; j < N; ++j) {

for (int k = max({i, 0}); k < min({(j) + 1, N}); ++k) {

for (int l = 0; l < N; ++l) {

for (int s = max({l, 0}); s < min({(i) + 1, N}); ++s) {






D[i][j][k][l][s] += D[ip][jp][kp][lp][sp];
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int l = 0; l < min({(i) + 1, N}); ++l) {

for (int j = max({i, 0}); j < N; ++j) {

for (int k = max({j, 0}); k < N; ++k) {

for (int s = max({k, 0}); s < N; ++s) {






D[i][j][k][l][s] += D[ip][jp][kp][lp][sp];
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int l = 0; l < min({(i) + 1, N}); ++l) {

for (int j = max({i, 0}); j < N; ++j) {

for (int k = 0; k < N; ++k) {

for (int s = max({j, 0}); s < min({(k) + 1, N}); ++s) {






D[i][j][k][l][s] += D[ip][jp][kp][lp][sp];
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int l = 0; l < min({(i) + 1, N}); ++l) {

for (int j = 0; j < N; ++j) {

for (int s = max({j, 0}); s < N; ++s) {

for (int k = max({i, 0}); k < min({(j) + 1, N}); ++k) {






D[i][j][k][l][s] += D[ip][jp][kp][lp][sp];
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int l = 0; l < min({(i) + 1, N}); ++l) {

for (int k = max({i, 0}); k < N; ++k) {

for (int j = 0; j < N; ++j) {

for (int s = max({k, 0}); s < min({(j) + 1, N}); ++s) {






D[i][j][k][l][s] += D[ip][jp][kp][lp][sp];
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int l = 0; l < min({(i) + 1, N}); ++l) {

for (int j = 0; j < N; ++j) {

for (int s = max({i, 0}); s < min({(j) + 1, N}); ++s) {

for (int k = max({j, 0}); k < N; ++k) {






D[i][j][k][l][s] += D[ip][jp][kp][lp][sp];
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int l = 0; l < min({(i) + 1, N}); ++l) {

for (int j = 0; j < N; ++j) {

for (int k = 0; k < min({(j) + 1, N}); ++k) {

for (int s = max({i, 0}); s < min({(k) + 1, N}); ++s) {






D[i][j][k][l][s] += D[ip][jp][kp][lp][sp];
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int j = 0; j < N; ++j) {

for (int s = 0; s < min({(j) + 1, N}); ++s) {

for (int k = max({j, 0}); k < N; ++k) {

for (int l = max({k, 0}); l < min({(i) + 1, N}); ++l) {






D[i][j][k][l][s] += D[ip][jp][kp][lp][sp];
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int l = max({i, 0}); l < N; ++l) {

for (int j = 0; j < N; ++j) {

for (int s = 0; s < min({(j) + 1, N}); ++s) {

for (int k = max({j, 0}); k < min({(i) + 1, N}); ++k) {






D[i][j][k][l][s] += D[ip][jp][kp][lp][sp];
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int j = 0; j < N; ++j) {

for (int k = 0; k < min({(i) + 1, N}); ++k) {

for (int s = 0; s < min({(j) + 1, N}); ++s) {

for (int l = max({j, 0}); l < min({(k) + 1, N}); ++l) {






D[i][j][k][l][s] += D[ip][jp][kp][lp][sp];
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int j = 0; j < N; ++j) {

for (int k = max({i, 0}); k < N; ++k) {

for (int s = 0; s < min({(j) + 1, N}); ++s) {

for (int l = max({j, 0}); l < min({(i) + 1, N}); ++l) {






D[i][j][k][l][s] += D[ip][jp][kp][lp][sp];
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int j = 0; j < min({(i) + 1, N}); ++j) {

for (int k = max({i, 0}); k < N; ++k) {

for (int s = 0; s < min({(j) + 1, N}); ++s) {

for (int l = max({k, 0}); l < N; ++l) {






D[i][j][k][l][s] += D[ip][jp][kp][lp][sp];
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int j = 0; j < min({(i) + 1, N}); ++j) {

for (int s = 0; s < min({(j) + 1, N}); ++s) {

for (int k = 0; k < N; ++k) {

for (int l = max({i, 0}); l < min({(k) + 1, N}); ++l) {






D[i][j][k][l][s] += D[ip][jp][kp][lp][sp];
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int j = 0; j < N; ++j) {

for (int l = max({j, 0}); l < min({(i) + 1, N}); ++l) {

for (int k = 0; k < min({(j) + 1, N}); ++k) {

for (int s = 0; s < min({(k) + 1, N}); ++s) {






D[i][j][k][l][s] += D[ip][jp][kp][lp][sp];
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int l = max({i, 0}); l < N; ++l) {

for (int j = 0; j < min({(i) + 1, N}); ++j) {

for (int k = 0; k < min({(j) + 1, N}); ++k) {

for (int s = 0; s < min({(k) + 1, N}); ++s) {






D[i][j][k][l][s] += D[ip][jp][kp][lp][sp];
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int j = 0; j < min({(i) + 1, N}); ++j) {

for (int k = 0; k < N; ++k) {

for (int s = 0; s < min({(k) + 1, N}); ++s) {

for (int l = max({k, 0}); l < min({(j) + 1, N}); ++l) {






D[i][j][k][l][s] += D[ip][jp][kp][lp][sp];
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int j = max({i, 0}); j < N; ++j) {

for (int k = 0; k < N; ++k) {

for (int s = 0; s < min({(k) + 1, N}); ++s) {

for (int l = max({k, 0}); l < min({(i) + 1, N}); ++l) {






D[i][j][k][l][s] += D[ip][jp][kp][lp][sp];
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int j = max({i, 0}); j < N; ++j) {

for (int k = 0; k < min({(i) + 1, N}); ++k) {

for (int l = max({j, 0}); l < N; ++l) {

for (int s = 0; s < min({(k) + 1, N}); ++s) {






D[i][j][k][l][s] += D[ip][jp][kp][lp][sp];
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int j = 0; j < N; ++j) {

for (int k = 0; k < min({(i) + 1, N}); ++k) {

for (int l = max({i, 0}); l < min({(j) + 1, N}); ++l) {

for (int s = 0; s < min({(k) + 1, N}); ++s) {






D[i][j][k][l][s] += D[ip][jp][kp][lp][sp];
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int j = 0; j < N; ++j) {

for (int l = 0; l < min({(j) + 1, N}); ++l) {

for (int k = max({j, 0}); k < min({(i) + 1, N}); ++k) {

for (int s = 0; s < min({(l) + 1, N}); ++s) {






D[i][j][k][l][s] += D[ip][jp][kp][lp][sp];
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int j = 0; j < min({(i) + 1, N}); ++j) {

for (int k = max({i, 0}); k < N; ++k) {

for (int l = 0; l < min({(j) + 1, N}); ++l) {

for (int s = 0; s < min({(l) + 1, N}); ++s) {






D[i][j][k][l][s] += D[ip][jp][kp][lp][sp];
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int j = 0; j < min({(i) + 1, N}); ++j) {

for (int k = 0; k < min({(j) + 1, N}); ++k) {

for (int l = 0; l < min({(k) + 1, N}); ++l) {

for (int s = 0; s < min({(l) + 1, N}); ++s) {






D[i][j][k][l][s] += D[ip][jp][kp][lp][sp];
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int j = max({i, 0}); j < N; ++j) {

for (int k = 0; k < min({(i) + 1, N}); ++k) {

for (int l = 0; l < min({(k) + 1, N}); ++l) {

for (int s = 0; s < min({(l) + 1, N}); ++s) {






D[i][j][k][l][s] += D[ip][jp][kp][lp][sp];
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int l = 0; l < min({(i) + 1, N}); ++l) {

for (int j = max({i, 0}); j < N; ++j) {

for (int s = 0; s < min({(l) + 1, N}); ++s) {

for (int k = max({j, 0}); k < N; ++k) {






D[i][j][k][l][s] += D[ip][jp][kp][lp][sp];
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int l = 0; l < min({(i) + 1, N}); ++l) {

for (int s = 0; s < min({(l) + 1, N}); ++s) {

for (int j = 0; j < N; ++j) {

for (int k = max({i, 0}); k < min({(j) + 1, N}); ++k) {






D[i][j][k][l][s] += D[ip][jp][kp][lp][sp];
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int s = 0; s < min({(i) + 1, N}); ++s) {

for (int j = max({i, 0}); j < N; ++j) {

for (int k = max({j, 0}); k < N; ++k) {

for (int l = max({k, 0}); l < N; ++l) {






D[i][j][k][l][s] += D[ip][jp][kp][lp][sp];
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int s = 0; s < min({(i) + 1, N}); ++s) {

for (int j = max({i, 0}); j < N; ++j) {

for (int k = 0; k < N; ++k) {

for (int l = max({j, 0}); l < min({(k) + 1, N}); ++l) {






D[i][j][k][l][s] += D[ip][jp][kp][lp][sp];
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int s = 0; s < min({(i) + 1, N}); ++s) {

for (int j = 0; j < N; ++j) {

for (int l = max({j, 0}); l < N; ++l) {

for (int k = max({i, 0}); k < min({(j) + 1, N}); ++k) {






D[i][j][k][l][s] += D[ip][jp][kp][lp][sp];
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int s = 0; s < min({(i) + 1, N}); ++s) {

for (int k = max({i, 0}); k < N; ++k) {

for (int j = 0; j < N; ++j) {

for (int l = max({k, 0}); l < min({(j) + 1, N}); ++l) {






D[i][j][k][l][s] += D[ip][jp][kp][lp][sp];
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int s = 0; s < min({(i) + 1, N}); ++s) {

for (int j = 0; j < N; ++j) {

for (int l = max({i, 0}); l < min({(j) + 1, N}); ++l) {

for (int k = max({j, 0}); k < N; ++k) {






D[i][j][k][l][s] += D[ip][jp][kp][lp][sp];
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int s = 0; s < min({(i) + 1, N}); ++s) {

for (int j = 0; j < N; ++j) {

for (int k = 0; k < min({(j) + 1, N}); ++k) {

for (int l = max({i, 0}); l < min({(k) + 1, N}); ++l) {






D[i][j][k][l][s] += D[ip][jp][kp][lp][sp];
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int j = max({i, 0}); j < N; ++j) {

for (int k = max({j, 0}); k < N; ++k) {

for (int l = max({k, 0}); l < N; ++l) {

for (int s = max({l, 0}); s < N; ++s) {






D[i][j][k][l][s] += D[ip][jp][kp][lp][sp];
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int j = max({i, 0}); j < N; ++j) {

for (int k = max({j, 0}); k < N; ++k) {

for (int l = 0; l < N; ++l) {

for (int s = max({k, 0}); s < min({(l) + 1, N}); ++s) {






D[i][j][k][l][s] += D[ip][jp][kp][lp][sp];
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int j = max({i, 0}); j < N; ++j) {

for (int k = 0; k < N; ++k) {

for (int s = max({k, 0}); s < N; ++s) {

for (int l = max({j, 0}); l < min({(k) + 1, N}); ++l) {






D[i][j][k][l][s] += D[ip][jp][kp][lp][sp];
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int j = max({i, 0}); j < N; ++j) {

for (int l = max({j, 0}); l < N; ++l) {

for (int k = 0; k < N; ++k) {

for (int s = max({l, 0}); s < min({(k) + 1, N}); ++s) {






D[i][j][k][l][s] += D[ip][jp][kp][lp][sp];
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int j = max({i, 0}); j < N; ++j) {

for (int k = 0; k < N; ++k) {

for (int s = max({j, 0}); s < min({(k) + 1, N}); ++s) {

for (int l = max({k, 0}); l < N; ++l) {






D[i][j][k][l][s] += D[ip][jp][kp][lp][sp];
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int j = max({i, 0}); j < N; ++j) {

for (int k = 0; k < N; ++k) {

for (int l = 0; l < min({(k) + 1, N}); ++l) {

for (int s = max({j, 0}); s < min({(l) + 1, N}); ++s) {






D[i][j][k][l][s] += D[ip][jp][kp][lp][sp];
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int j = 0; j < N; ++j) {

for (int l = max({j, 0}); l < N; ++l) {

for (int k = max({i, 0}); k < min({(j) + 1, N}); ++k) {

for (int s = max({l, 0}); s < N; ++s) {






D[i][j][k][l][s] += D[ip][jp][kp][lp][sp];
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int j = 0; j < N; ++j) {

for (int k = max({i, 0}); k < min({(j) + 1, N}); ++k) {

for (int l = 0; l < N; ++l) {

for (int s = max({j, 0}); s < min({(l) + 1, N}); ++s) {






D[i][j][k][l][s] += D[ip][jp][kp][lp][sp];
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int j = 0; j < N; ++j) {

for (int k = max({i, 0}); k < N; ++k) {

for (int s = max({j, 0}); s < N; ++s) {

for (int l = max({k, 0}); l < min({(j) + 1, N}); ++l) {






D[i][j][k][l][s] += D[ip][jp][kp][lp][sp];
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int j = 0; j < N; ++j) {

for (int k = max({i, 0}); k < N; ++k) {

for (int l = max({k, 0}); l < N; ++l) {

for (int s = max({l, 0}); s < min({(j) + 1, N}); ++s) {






D[i][j][k][l][s] += D[ip][jp][kp][lp][sp];
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int j = 0; j < N; ++j) {

for (int k = max({i, 0}); k < N; ++k) {

for (int l = max({j, 0}); l < N; ++l) {

for (int s = max({k, 0}); s < min({(j) + 1, N}); ++s) {






D[i][j][k][l][s] += D[ip][jp][kp][lp][sp];
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int j = 0; j < N; ++j) {

for (int k = max({i, 0}); k < N; ++k) {

for (int l = 0; l < min({(j) + 1, N}); ++l) {

for (int s = max({k, 0}); s < min({(l) + 1, N}); ++s) {






D[i][j][k][l][s] += D[ip][jp][kp][lp][sp];
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int j = 0; j < N; ++j) {

for (int l = max({i, 0}); l < min({(j) + 1, N}); ++l) {

for (int k = max({j, 0}); k < N; ++k) {

for (int s = max({k, 0}); s < N; ++s) {






D[i][j][k][l][s] += D[ip][jp][kp][lp][sp];
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int j = 0; j < N; ++j) {

for (int l = max({i, 0}); l < min({(j) + 1, N}); ++l) {

for (int k = 0; k < N; ++k) {

for (int s = max({j, 0}); s < min({(k) + 1, N}); ++s) {






D[i][j][k][l][s] += D[ip][jp][kp][lp][sp];
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int j = 0; j < N; ++j) {

for (int s = max({j, 0}); s < N; ++s) {

for (int k = 0; k < min({(j) + 1, N}); ++k) {

for (int l = max({i, 0}); l < min({(k) + 1, N}); ++l) {






D[i][j][k][l][s] += D[ip][jp][kp][lp][sp];
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int j = 0; j < N; ++j) {

for (int k = 0; k < N; ++k) {

for (int s = max({k, 0}); s < min({(j) + 1, N}); ++s) {

for (int l = max({i, 0}); l < min({(k) + 1, N}); ++l) {






D[i][j][k][l][s] += D[ip][jp][kp][lp][sp];
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int l = max({i, 0}); l < N; ++l) {

for (int j = 0; j < N; ++j) {

for (int s = max({l, 0}); s < min({(j) + 1, N}); ++s) {

for (int k = max({j, 0}); k < N; ++k) {






D[i][j][k][l][s] += D[ip][jp][kp][lp][sp];
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int l = max({i, 0}); l < N; ++l) {

for (int j = 0; j < N; ++j) {

for (int k = 0; k < min({(j) + 1, N}); ++k) {

for (int s = max({l, 0}); s < min({(k) + 1, N}); ++s) {






D[i][j][k][l][s] += D[ip][jp][kp][lp][sp];
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int j = 0; j < N; ++j) {

for (int s = max({i, 0}); s < min({(j) + 1, N}); ++s) {

for (int k = max({j, 0}); k < N; ++k) {

for (int l = max({k, 0}); l < N; ++l) {






D[i][j][k][l][s] += D[ip][jp][kp][lp][sp];
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int j = 0; j < N; ++j) {

for (int s = max({i, 0}); s < min({(j) + 1, N}); ++s) {

for (int k = 0; k < N; ++k) {

for (int l = max({j, 0}); l < min({(k) + 1, N}); ++l) {






D[i][j][k][l][s] += D[ip][jp][kp][lp][sp];
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int j = 0; j < N; ++j) {

for (int l = max({j, 0}); l < N; ++l) {

for (int k = 0; k < min({(j) + 1, N}); ++k) {

for (int s = max({i, 0}); s < min({(k) + 1, N}); ++s) {






D[i][j][k][l][s] += D[ip][jp][kp][lp][sp];
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int j = 0; j < N; ++j) {

for (int k = 0; k < N; ++k) {

for (int s = max({i, 0}); s < min({(k) + 1, N}); ++s) {

for (int l = max({k, 0}); l < min({(j) + 1, N}); ++l) {






D[i][j][k][l][s] += D[ip][jp][kp][lp][sp];
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int j = 0; j < N; ++j) {

for (int l = 0; l < min({(j) + 1, N}); ++l) {

for (int k = max({j, 0}); k < N; ++k) {

for (int s = max({i, 0}); s < min({(l) + 1, N}); ++s) {






D[i][j][k][l][s] += D[ip][jp][kp][lp][sp];
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int j = 0; j < N; ++j) {

for (int k = 0; k < min({(j) + 1, N}); ++k) {

for (int l = 0; l < min({(k) + 1, N}); ++l) {

for (int s = max({i, 0}); s < min({(l) + 1, N}); ++s) {






D[i][j][k][l][s] += D[ip][jp][kp][lp][sp];
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int t = max({i, 0}); t < N; ++t) {

for (int j = 0; j < N; ++j) {

for (int k = max({j, 0}); k < N; ++k) {

for (int l = max({k, 0}); l < N; ++l) {

for (int s = max({l, 0}); s < min({(i) + 1, N}); ++s) {







E[i][j][k][l][s][t] += E[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int s = 0; s < min({(i) + 1, N}); ++s) {

for (int j = 0; j < N; ++j) {

for (int k = max({j, 0}); k < N; ++k) {

for (int l = max({k, 0}); l < N; ++l) {

for (int t = max({l, 0}); t < min({(s) + 1, N}); ++t) {







E[i][j][k][l][s][t] += E[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int s = max({i, 0}); s < N; ++s) {

for (int j = 0; j < N; ++j) {

for (int k = max({j, 0}); k < N; ++k) {

for (int l = max({k, 0}); l < N; ++l) {

for (int t = max({l, 0}); t < min({(i) + 1, N}); ++t) {







E[i][j][k][l][s][t] += E[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int s = max({i, 0}); s < N; ++s) {

for (int t = max({s, 0}); t < N; ++t) {

for (int j = 0; j < N; ++j) {

for (int k = max({j, 0}); k < N; ++k) {

for (int l = max({k, 0}); l < min({(i) + 1, N}); ++l) {







E[i][j][k][l][s][t] += E[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int j = 0; j < N; ++j) {

for (int k = max({j, 0}); k < N; ++k) {

for (int l = max({k, 0}); l < min({(i) + 1, N}); ++l) {

for (int s = 0; s < N; ++s) {

for (int t = max({i, 0}); t < min({(s) + 1, N}); ++t) {







E[i][j][k][l][s][t] += E[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int j = 0; j < N; ++j) {

for (int k = max({j, 0}); k < N; ++k) {

for (int l = 0; l < N; ++l) {

for (int s = max({k, 0}); s < min({(l) + 1, N}); ++s) {

for (int t = max({l, 0}); t < min({(i) + 1, N}); ++t) {







E[i][j][k][l][s][t] += E[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int t = max({i, 0}); t < N; ++t) {

for (int l = 0; l < min({(i) + 1, N}); ++l) {

for (int j = 0; j < N; ++j) {

for (int k = max({j, 0}); k < N; ++k) {

for (int s = max({k, 0}); s < min({(l) + 1, N}); ++s) {







E[i][j][k][l][s][t] += E[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int l = 0; l < min({(i) + 1, N}); ++l) {

for (int j = 0; j < N; ++j) {

for (int k = max({j, 0}); k < N; ++k) {

for (int s = max({k, 0}); s < N; ++s) {

for (int t = max({s, 0}); t < min({(l) + 1, N}); ++t) {







E[i][j][k][l][s][t] += E[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int l = max({i, 0}); l < N; ++l) {

for (int j = 0; j < N; ++j) {

for (int k = max({j, 0}); k < N; ++k) {

for (int s = max({k, 0}); s < N; ++s) {

for (int t = max({s, 0}); t < min({(i) + 1, N}); ++t) {







E[i][j][k][l][s][t] += E[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int l = max({i, 0}); l < N; ++l) {

for (int t = max({l, 0}); t < N; ++t) {

for (int j = 0; j < N; ++j) {

for (int k = max({j, 0}); k < N; ++k) {

for (int s = max({k, 0}); s < min({(i) + 1, N}); ++s) {







E[i][j][k][l][s][t] += E[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int j = 0; j < N; ++j) {

for (int k = max({j, 0}); k < N; ++k) {

for (int s = max({k, 0}); s < min({(i) + 1, N}); ++s) {

for (int l = 0; l < N; ++l) {

for (int t = max({i, 0}); t < min({(l) + 1, N}); ++t) {







E[i][j][k][l][s][t] += E[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int j = 0; j < N; ++j) {

for (int k = max({j, 0}); k < N; ++k) {

for (int l = 0; l < N; ++l) {

for (int s = max({l, 0}); s < min({(i) + 1, N}); ++s) {

for (int t = max({k, 0}); t < min({(l) + 1, N}); ++t) {







E[i][j][k][l][s][t] += E[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int s = max({i, 0}); s < N; ++s) {

for (int l = 0; l < min({(i) + 1, N}); ++l) {

for (int j = 0; j < N; ++j) {

for (int k = max({j, 0}); k < N; ++k) {

for (int t = max({k, 0}); t < min({(l) + 1, N}); ++t) {







E[i][j][k][l][s][t] += E[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int l = 0; l < min({(i) + 1, N}); ++l) {

for (int s = 0; s < min({(l) + 1, N}); ++s) {

for (int j = 0; j < N; ++j) {

for (int k = max({j, 0}); k < N; ++k) {

for (int t = max({k, 0}); t < min({(s) + 1, N}); ++t) {







E[i][j][k][l][s][t] += E[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int s = 0; s < min({(i) + 1, N}); ++s) {

for (int l = max({i, 0}); l < N; ++l) {

for (int j = 0; j < N; ++j) {

for (int k = max({j, 0}); k < N; ++k) {

for (int t = max({k, 0}); t < min({(s) + 1, N}); ++t) {







E[i][j][k][l][s][t] += E[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int l = max({i, 0}); l < N; ++l) {

for (int s = max({l, 0}); s < N; ++s) {

for (int j = 0; j < N; ++j) {

for (int k = max({j, 0}); k < N; ++k) {

for (int t = max({k, 0}); t < min({(i) + 1, N}); ++t) {







E[i][j][k][l][s][t] += E[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int j = 0; j < N; ++j) {

for (int k = max({j, 0}); k < N; ++k) {

for (int t = max({k, 0}); t < min({(i) + 1, N}); ++t) {

for (int l = 0; l < N; ++l) {

for (int s = max({i, 0}); s < min({(l) + 1, N}); ++s) {







E[i][j][k][l][s][t] += E[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int l = max({i, 0}); l < N; ++l) {

for (int s = max({l, 0}); s < N; ++s) {

for (int t = max({s, 0}); t < N; ++t) {

for (int j = 0; j < N; ++j) {

for (int k = max({j, 0}); k < min({(i) + 1, N}); ++k) {







E[i][j][k][l][s][t] += E[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int l = max({i, 0}); l < N; ++l) {

for (int j = 0; j < N; ++j) {

for (int k = max({j, 0}); k < min({(i) + 1, N}); ++k) {

for (int s = 0; s < N; ++s) {

for (int t = max({l, 0}); t < min({(s) + 1, N}); ++t) {







E[i][j][k][l][s][t] += E[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int j = 0; j < N; ++j) {

for (int k = max({j, 0}); k < min({(i) + 1, N}); ++k) {

for (int l = 0; l < N; ++l) {

for (int s = max({i, 0}); s < min({(l) + 1, N}); ++s) {

for (int t = max({l, 0}); t < N; ++t) {







E[i][j][k][l][s][t] += E[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int s = max({i, 0}); s < N; ++s) {

for (int j = 0; j < N; ++j) {

for (int k = max({j, 0}); k < min({(i) + 1, N}); ++k) {

for (int l = 0; l < N; ++l) {

for (int t = max({s, 0}); t < min({(l) + 1, N}); ++t) {







E[i][j][k][l][s][t] += E[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int j = 0; j < N; ++j) {

for (int k = max({j, 0}); k < min({(i) + 1, N}); ++k) {

for (int l = 0; l < N; ++l) {

for (int s = max({l, 0}); s < N; ++s) {

for (int t = max({i, 0}); t < min({(l) + 1, N}); ++t) {







E[i][j][k][l][s][t] += E[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int j = 0; j < N; ++j) {

for (int k = max({j, 0}); k < min({(i) + 1, N}); ++k) {

for (int l = 0; l < N; ++l) {

for (int s = 0; s < min({(l) + 1, N}); ++s) {

for (int t = max({i, 0}); t < min({(s) + 1, N}); ++t) {







E[i][j][k][l][s][t] += E[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int j = 0; j < N; ++j) {

for (int k = 0; k < N; ++k) {

for (int s = max({k, 0}); s < N; ++s) {

for (int l = max({j, 0}); l < min({(k) + 1, N}); ++l) {

for (int t = max({s, 0}); t < min({(i) + 1, N}); ++t) {







E[i][j][k][l][s][t] += E[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int t = max({i, 0}); t < N; ++t) {

for (int j = 0; j < N; ++j) {

for (int k = 0; k < N; ++k) {

for (int s = max({k, 0}); s < min({(i) + 1, N}); ++s) {

for (int l = max({j, 0}); l < min({(k) + 1, N}); ++l) {







E[i][j][k][l][s][t] += E[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int s = 0; s < min({(i) + 1, N}); ++s) {

for (int j = 0; j < N; ++j) {

for (int k = 0; k < N; ++k) {

for (int t = max({k, 0}); t < min({(s) + 1, N}); ++t) {

for (int l = max({j, 0}); l < min({(k) + 1, N}); ++l) {







E[i][j][k][l][s][t] += E[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int s = max({i, 0}); s < N; ++s) {

for (int j = 0; j < N; ++j) {

for (int k = 0; k < N; ++k) {

for (int t = max({k, 0}); t < min({(i) + 1, N}); ++t) {

for (int l = max({j, 0}); l < min({(k) + 1, N}); ++l) {







E[i][j][k][l][s][t] += E[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int s = max({i, 0}); s < N; ++s) {

for (int k = 0; k < min({(i) + 1, N}); ++k) {

for (int t = max({s, 0}); t < N; ++t) {

for (int j = 0; j < N; ++j) {

for (int l = max({j, 0}); l < min({(k) + 1, N}); ++l) {







E[i][j][k][l][s][t] += E[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int j = 0; j < N; ++j) {

for (int k = 0; k < min({(i) + 1, N}); ++k) {

for (int l = max({j, 0}); l < min({(k) + 1, N}); ++l) {

for (int s = 0; s < N; ++s) {

for (int t = max({i, 0}); t < min({(s) + 1, N}); ++t) {







E[i][j][k][l][s][t] += E[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int j = 0; j < N; ++j) {

for (int l = max({j, 0}); l < N; ++l) {

for (int k = 0; k < N; ++k) {

for (int s = max({l, 0}); s < min({(k) + 1, N}); ++s) {

for (int t = max({k, 0}); t < min({(i) + 1, N}); ++t) {







E[i][j][k][l][s][t] += E[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int t = max({i, 0}); t < N; ++t) {

for (int k = 0; k < min({(i) + 1, N}); ++k) {

for (int j = 0; j < N; ++j) {

for (int l = max({j, 0}); l < N; ++l) {

for (int s = max({l, 0}); s < min({(k) + 1, N}); ++s) {







E[i][j][k][l][s][t] += E[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int j = 0; j < N; ++j) {

for (int k = 0; k < min({(i) + 1, N}); ++k) {

for (int l = max({j, 0}); l < N; ++l) {

for (int s = max({l, 0}); s < N; ++s) {

for (int t = max({s, 0}); t < min({(k) + 1, N}); ++t) {







E[i][j][k][l][s][t] += E[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int j = 0; j < N; ++j) {

for (int k = max({i, 0}); k < N; ++k) {

for (int l = max({j, 0}); l < N; ++l) {

for (int s = max({l, 0}); s < N; ++s) {

for (int t = max({s, 0}); t < min({(i) + 1, N}); ++t) {







E[i][j][k][l][s][t] += E[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int j = 0; j < N; ++j) {

for (int k = max({i, 0}); k < N; ++k) {

for (int l = max({j, 0}); l < N; ++l) {

for (int t = max({k, 0}); t < N; ++t) {

for (int s = max({l, 0}); s < min({(i) + 1, N}); ++s) {







E[i][j][k][l][s][t] += E[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int j = 0; j < N; ++j) {

for (int l = max({j, 0}); l < N; ++l) {

for (int s = max({l, 0}); s < min({(i) + 1, N}); ++s) {

for (int k = 0; k < N; ++k) {

for (int t = max({i, 0}); t < min({(k) + 1, N}); ++t) {







E[i][j][k][l][s][t] += E[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int j = 0; j < N; ++j) {

for (int l = max({j, 0}); l < N; ++l) {

for (int k = 0; k < N; ++k) {

for (int s = max({k, 0}); s < min({(i) + 1, N}); ++s) {

for (int t = max({l, 0}); t < min({(k) + 1, N}); ++t) {







E[i][j][k][l][s][t] += E[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int s = max({i, 0}); s < N; ++s) {

for (int k = 0; k < min({(i) + 1, N}); ++k) {

for (int j = 0; j < N; ++j) {

for (int l = max({j, 0}); l < N; ++l) {

for (int t = max({l, 0}); t < min({(k) + 1, N}); ++t) {







E[i][j][k][l][s][t] += E[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int j = 0; j < N; ++j) {

for (int k = 0; k < min({(i) + 1, N}); ++k) {

for (int l = max({j, 0}); l < N; ++l) {

for (int s = 0; s < min({(k) + 1, N}); ++s) {

for (int t = max({l, 0}); t < min({(s) + 1, N}); ++t) {







E[i][j][k][l][s][t] += E[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int s = 0; s < min({(i) + 1, N}); ++s) {

for (int k = max({i, 0}); k < N; ++k) {

for (int j = 0; j < N; ++j) {

for (int l = max({j, 0}); l < N; ++l) {

for (int t = max({l, 0}); t < min({(s) + 1, N}); ++t) {







E[i][j][k][l][s][t] += E[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int j = 0; j < N; ++j) {

for (int k = max({i, 0}); k < N; ++k) {

for (int l = max({j, 0}); l < N; ++l) {

for (int s = max({k, 0}); s < N; ++s) {

for (int t = max({l, 0}); t < min({(i) + 1, N}); ++t) {







E[i][j][k][l][s][t] += E[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int j = 0; j < N; ++j) {

for (int l = max({j, 0}); l < N; ++l) {

for (int t = max({l, 0}); t < min({(i) + 1, N}); ++t) {

for (int k = 0; k < N; ++k) {

for (int s = max({i, 0}); s < min({(k) + 1, N}); ++s) {







E[i][j][k][l][s][t] += E[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int j = 0; j < N; ++j) {

for (int k = max({i, 0}); k < N; ++k) {

for (int l = max({j, 0}); l < min({(i) + 1, N}); ++l) {

for (int s = max({k, 0}); s < N; ++s) {

for (int t = max({s, 0}); t < N; ++t) {







E[i][j][k][l][s][t] += E[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int j = 0; j < N; ++j) {

for (int k = max({i, 0}); k < N; ++k) {

for (int l = max({j, 0}); l < min({(i) + 1, N}); ++l) {

for (int s = 0; s < N; ++s) {

for (int t = max({k, 0}); t < min({(s) + 1, N}); ++t) {







E[i][j][k][l][s][t] += E[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int j = 0; j < N; ++j) {

for (int l = max({j, 0}); l < min({(i) + 1, N}); ++l) {

for (int k = 0; k < N; ++k) {

for (int s = max({i, 0}); s < min({(k) + 1, N}); ++s) {

for (int t = max({k, 0}); t < N; ++t) {







E[i][j][k][l][s][t] += E[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int s = max({i, 0}); s < N; ++s) {

for (int j = 0; j < N; ++j) {

for (int l = max({j, 0}); l < min({(i) + 1, N}); ++l) {

for (int k = 0; k < N; ++k) {

for (int t = max({s, 0}); t < min({(k) + 1, N}); ++t) {







E[i][j][k][l][s][t] += E[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int j = 0; j < N; ++j) {

for (int l = max({j, 0}); l < min({(i) + 1, N}); ++l) {

for (int k = 0; k < N; ++k) {

for (int s = max({k, 0}); s < N; ++s) {

for (int t = max({i, 0}); t < min({(k) + 1, N}); ++t) {







E[i][j][k][l][s][t] += E[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int j = 0; j < N; ++j) {

for (int l = max({j, 0}); l < min({(i) + 1, N}); ++l) {

for (int k = 0; k < N; ++k) {

for (int s = 0; s < min({(k) + 1, N}); ++s) {

for (int t = max({i, 0}); t < min({(s) + 1, N}); ++t) {







E[i][j][k][l][s][t] += E[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int j = 0; j < N; ++j) {

for (int k = 0; k < N; ++k) {

for (int s = max({j, 0}); s < min({(k) + 1, N}); ++s) {

for (int l = max({k, 0}); l < N; ++l) {

for (int t = max({l, 0}); t < min({(i) + 1, N}); ++t) {







E[i][j][k][l][s][t] += E[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int t = max({i, 0}); t < N; ++t) {

for (int j = 0; j < N; ++j) {

for (int k = 0; k < N; ++k) {

for (int s = max({j, 0}); s < min({(k) + 1, N}); ++s) {

for (int l = max({k, 0}); l < min({(i) + 1, N}); ++l) {







E[i][j][k][l][s][t] += E[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int l = 0; l < min({(i) + 1, N}); ++l) {

for (int j = 0; j < N; ++j) {

for (int k = 0; k < N; ++k) {

for (int s = max({j, 0}); s < min({(k) + 1, N}); ++s) {

for (int t = max({k, 0}); t < min({(l) + 1, N}); ++t) {







E[i][j][k][l][s][t] += E[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int l = max({i, 0}); l < N; ++l) {

for (int j = 0; j < N; ++j) {

for (int k = 0; k < N; ++k) {

for (int s = max({j, 0}); s < min({(k) + 1, N}); ++s) {

for (int t = max({k, 0}); t < min({(i) + 1, N}); ++t) {







E[i][j][k][l][s][t] += E[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int l = max({i, 0}); l < N; ++l) {

for (int k = 0; k < min({(i) + 1, N}); ++k) {

for (int t = max({l, 0}); t < N; ++t) {

for (int j = 0; j < N; ++j) {

for (int s = max({j, 0}); s < min({(k) + 1, N}); ++s) {







E[i][j][k][l][s][t] += E[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int j = 0; j < N; ++j) {

for (int k = 0; k < min({(i) + 1, N}); ++k) {

for (int s = max({j, 0}); s < min({(k) + 1, N}); ++s) {

for (int l = 0; l < N; ++l) {

for (int t = max({i, 0}); t < min({(l) + 1, N}); ++t) {







E[i][j][k][l][s][t] += E[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int j = 0; j < N; ++j) {

for (int k = 0; k < N; ++k) {

for (int t = max({k, 0}); t < min({(i) + 1, N}); ++t) {

for (int l = 0; l < min({(k) + 1, N}); ++l) {

for (int s = max({j, 0}); s < min({(l) + 1, N}); ++s) {







E[i][j][k][l][s][t] += E[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int t = max({i, 0}); t < N; ++t) {

for (int k = 0; k < min({(i) + 1, N}); ++k) {

for (int l = 0; l < min({(k) + 1, N}); ++l) {

for (int j = 0; j < N; ++j) {

for (int s = max({j, 0}); s < min({(l) + 1, N}); ++s) {







E[i][j][k][l][s][t] += E[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int j = 0; j < N; ++j) {

for (int k = 0; k < min({(i) + 1, N}); ++k) {

for (int l = 0; l < N; ++l) {

for (int s = max({j, 0}); s < min({(l) + 1, N}); ++s) {

for (int t = max({l, 0}); t < min({(k) + 1, N}); ++t) {







E[i][j][k][l][s][t] += E[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int j = 0; j < N; ++j) {

for (int k = max({i, 0}); k < N; ++k) {

for (int l = 0; l < N; ++l) {

for (int s = max({j, 0}); s < min({(l) + 1, N}); ++s) {

for (int t = max({l, 0}); t < min({(i) + 1, N}); ++t) {







E[i][j][k][l][s][t] += E[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int l = 0; l < min({(i) + 1, N}); ++l) {

for (int k = max({i, 0}); k < N; ++k) {

for (int t = max({k, 0}); t < N; ++t) {

for (int j = 0; j < N; ++j) {

for (int s = max({j, 0}); s < min({(l) + 1, N}); ++s) {







E[i][j][k][l][s][t] += E[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int l = 0; l < min({(i) + 1, N}); ++l) {

for (int j = 0; j < N; ++j) {

for (int s = max({j, 0}); s < min({(l) + 1, N}); ++s) {

for (int k = 0; k < N; ++k) {

for (int t = max({i, 0}); t < min({(k) + 1, N}); ++t) {







E[i][j][k][l][s][t] += E[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int j = 0; j < N; ++j) {

for (int s = max({j, 0}); s < N; ++s) {

for (int k = 0; k < N; ++k) {

for (int t = max({s, 0}); t < min({(k) + 1, N}); ++t) {

for (int l = max({k, 0}); l < min({(i) + 1, N}); ++l) {







E[i][j][k][l][s][t] += E[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int l = max({i, 0}); l < N; ++l) {

for (int k = 0; k < min({(i) + 1, N}); ++k) {

for (int j = 0; j < N; ++j) {

for (int s = max({j, 0}); s < N; ++s) {

for (int t = max({s, 0}); t < min({(k) + 1, N}); ++t) {







E[i][j][k][l][s][t] += E[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int j = 0; j < N; ++j) {

for (int k = 0; k < min({(i) + 1, N}); ++k) {

for (int s = max({j, 0}); s < N; ++s) {

for (int l = 0; l < min({(k) + 1, N}); ++l) {

for (int t = max({s, 0}); t < min({(l) + 1, N}); ++t) {







E[i][j][k][l][s][t] += E[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int l = 0; l < min({(i) + 1, N}); ++l) {

for (int k = max({i, 0}); k < N; ++k) {

for (int j = 0; j < N; ++j) {

for (int s = max({j, 0}); s < N; ++s) {

for (int t = max({s, 0}); t < min({(l) + 1, N}); ++t) {







E[i][j][k][l][s][t] += E[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int j = 0; j < N; ++j) {

for (int k = max({i, 0}); k < N; ++k) {

for (int s = max({j, 0}); s < N; ++s) {

for (int l = max({k, 0}); l < N; ++l) {

for (int t = max({s, 0}); t < min({(i) + 1, N}); ++t) {







E[i][j][k][l][s][t] += E[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int j = 0; j < N; ++j) {

for (int s = max({j, 0}); s < N; ++s) {

for (int t = max({s, 0}); t < min({(i) + 1, N}); ++t) {

for (int k = 0; k < N; ++k) {

for (int l = max({i, 0}); l < min({(k) + 1, N}); ++l) {







E[i][j][k][l][s][t] += E[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int j = 0; j < N; ++j) {

for (int k = max({i, 0}); k < N; ++k) {

for (int s = max({j, 0}); s < min({(i) + 1, N}); ++s) {

for (int l = max({k, 0}); l < N; ++l) {

for (int t = max({l, 0}); t < N; ++t) {







E[i][j][k][l][s][t] += E[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int j = 0; j < N; ++j) {

for (int k = max({i, 0}); k < N; ++k) {

for (int s = max({j, 0}); s < min({(i) + 1, N}); ++s) {

for (int l = 0; l < N; ++l) {

for (int t = max({k, 0}); t < min({(l) + 1, N}); ++t) {







E[i][j][k][l][s][t] += E[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int j = 0; j < N; ++j) {

for (int s = max({j, 0}); s < min({(i) + 1, N}); ++s) {

for (int k = 0; k < N; ++k) {

for (int t = max({k, 0}); t < N; ++t) {

for (int l = max({i, 0}); l < min({(k) + 1, N}); ++l) {







E[i][j][k][l][s][t] += E[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int l = max({i, 0}); l < N; ++l) {

for (int j = 0; j < N; ++j) {

for (int s = max({j, 0}); s < min({(i) + 1, N}); ++s) {

for (int k = 0; k < N; ++k) {

for (int t = max({l, 0}); t < min({(k) + 1, N}); ++t) {







E[i][j][k][l][s][t] += E[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int j = 0; j < N; ++j) {

for (int s = max({j, 0}); s < min({(i) + 1, N}); ++s) {

for (int k = 0; k < N; ++k) {

for (int t = max({i, 0}); t < min({(k) + 1, N}); ++t) {

for (int l = max({k, 0}); l < N; ++l) {







E[i][j][k][l][s][t] += E[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int j = 0; j < N; ++j) {

for (int s = max({j, 0}); s < min({(i) + 1, N}); ++s) {

for (int k = 0; k < N; ++k) {

for (int l = 0; l < min({(k) + 1, N}); ++l) {

for (int t = max({i, 0}); t < min({(l) + 1, N}); ++t) {







E[i][j][k][l][s][t] += E[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int j = 0; j < N; ++j) {

for (int k = 0; k < N; ++k) {

for (int t = max({j, 0}); t < min({(k) + 1, N}); ++t) {

for (int l = max({k, 0}); l < N; ++l) {

for (int s = max({l, 0}); s < min({(i) + 1, N}); ++s) {







E[i][j][k][l][s][t] += E[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int s = max({i, 0}); s < N; ++s) {

for (int j = 0; j < N; ++j) {

for (int k = 0; k < N; ++k) {

for (int t = max({j, 0}); t < min({(k) + 1, N}); ++t) {

for (int l = max({k, 0}); l < min({(i) + 1, N}); ++l) {







E[i][j][k][l][s][t] += E[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int l = 0; l < min({(i) + 1, N}); ++l) {

for (int j = 0; j < N; ++j) {

for (int k = 0; k < N; ++k) {

for (int s = max({k, 0}); s < min({(l) + 1, N}); ++s) {

for (int t = max({j, 0}); t < min({(k) + 1, N}); ++t) {







E[i][j][k][l][s][t] += E[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int l = max({i, 0}); l < N; ++l) {

for (int j = 0; j < N; ++j) {

for (int k = 0; k < N; ++k) {

for (int s = max({k, 0}); s < min({(i) + 1, N}); ++s) {

for (int t = max({j, 0}); t < min({(k) + 1, N}); ++t) {







E[i][j][k][l][s][t] += E[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int l = max({i, 0}); l < N; ++l) {

for (int k = 0; k < min({(i) + 1, N}); ++k) {

for (int s = max({l, 0}); s < N; ++s) {

for (int j = 0; j < N; ++j) {

for (int t = max({j, 0}); t < min({(k) + 1, N}); ++t) {







E[i][j][k][l][s][t] += E[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int j = 0; j < N; ++j) {

for (int k = 0; k < min({(i) + 1, N}); ++k) {

for (int t = max({j, 0}); t < min({(k) + 1, N}); ++t) {

for (int l = 0; l < N; ++l) {

for (int s = max({i, 0}); s < min({(l) + 1, N}); ++s) {







E[i][j][k][l][s][t] += E[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int j = 0; j < N; ++j) {

for (int k = 0; k < N; ++k) {

for (int s = max({k, 0}); s < min({(i) + 1, N}); ++s) {

for (int l = 0; l < min({(k) + 1, N}); ++l) {

for (int t = max({j, 0}); t < min({(l) + 1, N}); ++t) {







E[i][j][k][l][s][t] += E[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int s = max({i, 0}); s < N; ++s) {

for (int k = 0; k < min({(i) + 1, N}); ++k) {

for (int l = 0; l < min({(k) + 1, N}); ++l) {

for (int j = 0; j < N; ++j) {

for (int t = max({j, 0}); t < min({(l) + 1, N}); ++t) {







E[i][j][k][l][s][t] += E[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int j = 0; j < N; ++j) {

for (int k = 0; k < min({(i) + 1, N}); ++k) {

for (int l = 0; l < N; ++l) {

for (int s = max({l, 0}); s < min({(k) + 1, N}); ++s) {

for (int t = max({j, 0}); t < min({(l) + 1, N}); ++t) {







E[i][j][k][l][s][t] += E[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int j = 0; j < N; ++j) {

for (int k = max({i, 0}); k < N; ++k) {

for (int l = 0; l < N; ++l) {

for (int s = max({l, 0}); s < min({(i) + 1, N}); ++s) {

for (int t = max({j, 0}); t < min({(l) + 1, N}); ++t) {







E[i][j][k][l][s][t] += E[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int l = 0; l < min({(i) + 1, N}); ++l) {

for (int k = max({i, 0}); k < N; ++k) {

for (int s = max({k, 0}); s < N; ++s) {

for (int j = 0; j < N; ++j) {

for (int t = max({j, 0}); t < min({(l) + 1, N}); ++t) {







E[i][j][k][l][s][t] += E[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int l = 0; l < min({(i) + 1, N}); ++l) {

for (int j = 0; j < N; ++j) {

for (int t = max({j, 0}); t < min({(l) + 1, N}); ++t) {

for (int k = 0; k < N; ++k) {

for (int s = max({i, 0}); s < min({(k) + 1, N}); ++s) {







E[i][j][k][l][s][t] += E[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int j = 0; j < N; ++j) {

for (int k = 0; k < N; ++k) {

for (int s = 0; s < min({(k) + 1, N}); ++s) {

for (int l = max({k, 0}); l < min({(i) + 1, N}); ++l) {

for (int t = max({j, 0}); t < min({(s) + 1, N}); ++t) {







E[i][j][k][l][s][t] += E[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int l = max({i, 0}); l < N; ++l) {

for (int k = 0; k < min({(i) + 1, N}); ++k) {

for (int s = 0; s < min({(k) + 1, N}); ++s) {

for (int j = 0; j < N; ++j) {

for (int t = max({j, 0}); t < min({(s) + 1, N}); ++t) {







E[i][j][k][l][s][t] += E[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int j = 0; j < N; ++j) {

for (int k = 0; k < min({(i) + 1, N}); ++k) {

for (int l = 0; l < min({(k) + 1, N}); ++l) {

for (int s = 0; s < min({(l) + 1, N}); ++s) {

for (int t = max({j, 0}); t < min({(s) + 1, N}); ++t) {







E[i][j][k][l][s][t] += E[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int l = 0; l < min({(i) + 1, N}); ++l) {

for (int k = max({i, 0}); k < N; ++k) {

for (int s = 0; s < min({(l) + 1, N}); ++s) {

for (int j = 0; j < N; ++j) {

for (int t = max({j, 0}); t < min({(s) + 1, N}); ++t) {







E[i][j][k][l][s][t] += E[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int s = 0; s < min({(i) + 1, N}); ++s) {

for (int k = max({i, 0}); k < N; ++k) {

for (int l = max({k, 0}); l < N; ++l) {

for (int j = 0; j < N; ++j) {

for (int t = max({j, 0}); t < min({(s) + 1, N}); ++t) {







E[i][j][k][l][s][t] += E[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int s = 0; s < min({(i) + 1, N}); ++s) {

for (int j = 0; j < N; ++j) {

for (int t = max({j, 0}); t < min({(s) + 1, N}); ++t) {

for (int k = 0; k < N; ++k) {

for (int l = max({i, 0}); l < min({(k) + 1, N}); ++l) {







E[i][j][k][l][s][t] += E[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int j = 0; j < N; ++j) {

for (int k = max({i, 0}); k < N; ++k) {

for (int t = max({j, 0}); t < min({(i) + 1, N}); ++t) {

for (int l = max({k, 0}); l < N; ++l) {

for (int s = max({l, 0}); s < N; ++s) {







E[i][j][k][l][s][t] += E[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int j = 0; j < N; ++j) {

for (int k = max({i, 0}); k < N; ++k) {

for (int t = max({j, 0}); t < min({(i) + 1, N}); ++t) {

for (int l = 0; l < N; ++l) {

for (int s = max({k, 0}); s < min({(l) + 1, N}); ++s) {







E[i][j][k][l][s][t] += E[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int j = 0; j < N; ++j) {

for (int t = max({j, 0}); t < min({(i) + 1, N}); ++t) {

for (int k = 0; k < N; ++k) {

for (int s = max({k, 0}); s < N; ++s) {

for (int l = max({i, 0}); l < min({(k) + 1, N}); ++l) {







E[i][j][k][l][s][t] += E[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int l = max({i, 0}); l < N; ++l) {

for (int j = 0; j < N; ++j) {

for (int t = max({j, 0}); t < min({(i) + 1, N}); ++t) {

for (int k = 0; k < N; ++k) {

for (int s = max({l, 0}); s < min({(k) + 1, N}); ++s) {







E[i][j][k][l][s][t] += E[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int j = 0; j < N; ++j) {

for (int t = max({j, 0}); t < min({(i) + 1, N}); ++t) {

for (int k = 0; k < N; ++k) {

for (int s = max({i, 0}); s < min({(k) + 1, N}); ++s) {

for (int l = max({k, 0}); l < N; ++l) {







E[i][j][k][l][s][t] += E[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int j = 0; j < N; ++j) {

for (int t = max({j, 0}); t < min({(i) + 1, N}); ++t) {

for (int k = 0; k < N; ++k) {

for (int l = 0; l < min({(k) + 1, N}); ++l) {

for (int s = max({i, 0}); s < min({(l) + 1, N}); ++s) {







E[i][j][k][l][s][t] += E[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int j = 0; j < min({(i) + 1, N}); ++j) {

for (int k = max({i, 0}); k < N; ++k) {

for (int l = max({k, 0}); l < N; ++l) {

for (int s = max({l, 0}); s < N; ++s) {

for (int t = max({s, 0}); t < N; ++t) {







E[i][j][k][l][s][t] += E[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int j = 0; j < min({(i) + 1, N}); ++j) {

for (int k = max({i, 0}); k < N; ++k) {

for (int l = max({k, 0}); l < N; ++l) {

for (int s = 0; s < N; ++s) {

for (int t = max({l, 0}); t < min({(s) + 1, N}); ++t) {







E[i][j][k][l][s][t] += E[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int j = 0; j < min({(i) + 1, N}); ++j) {

for (int k = max({i, 0}); k < N; ++k) {

for (int l = 0; l < N; ++l) {

for (int s = max({k, 0}); s < min({(l) + 1, N}); ++s) {

for (int t = max({l, 0}); t < N; ++t) {







E[i][j][k][l][s][t] += E[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int j = 0; j < min({(i) + 1, N}); ++j) {

for (int k = max({i, 0}); k < N; ++k) {

for (int s = max({k, 0}); s < N; ++s) {

for (int l = 0; l < N; ++l) {

for (int t = max({s, 0}); t < min({(l) + 1, N}); ++t) {







E[i][j][k][l][s][t] += E[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int j = 0; j < min({(i) + 1, N}); ++j) {

for (int k = max({i, 0}); k < N; ++k) {

for (int l = 0; l < N; ++l) {

for (int s = max({l, 0}); s < N; ++s) {

for (int t = max({k, 0}); t < min({(l) + 1, N}); ++t) {







E[i][j][k][l][s][t] += E[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int j = 0; j < min({(i) + 1, N}); ++j) {

for (int k = max({i, 0}); k < N; ++k) {

for (int l = 0; l < N; ++l) {

for (int s = 0; s < min({(l) + 1, N}); ++s) {

for (int t = max({k, 0}); t < min({(s) + 1, N}); ++t) {







E[i][j][k][l][s][t] += E[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int j = 0; j < min({(i) + 1, N}); ++j) {

for (int k = 0; k < N; ++k) {

for (int s = max({k, 0}); s < N; ++s) {

for (int l = max({i, 0}); l < min({(k) + 1, N}); ++l) {

for (int t = max({s, 0}); t < N; ++t) {







E[i][j][k][l][s][t] += E[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int j = 0; j < min({(i) + 1, N}); ++j) {

for (int k = 0; k < N; ++k) {

for (int l = max({i, 0}); l < min({(k) + 1, N}); ++l) {

for (int s = 0; s < N; ++s) {

for (int t = max({k, 0}); t < min({(s) + 1, N}); ++t) {







E[i][j][k][l][s][t] += E[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int l = max({i, 0}); l < N; ++l) {

for (int j = 0; j < min({(i) + 1, N}); ++j) {

for (int k = 0; k < N; ++k) {

for (int s = max({l, 0}); s < min({(k) + 1, N}); ++s) {

for (int t = max({k, 0}); t < N; ++t) {







E[i][j][k][l][s][t] += E[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int l = max({i, 0}); l < N; ++l) {

for (int j = 0; j < min({(i) + 1, N}); ++j) {

for (int s = max({l, 0}); s < N; ++s) {

for (int k = 0; k < N; ++k) {

for (int t = max({s, 0}); t < min({(k) + 1, N}); ++t) {







E[i][j][k][l][s][t] += E[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int l = max({i, 0}); l < N; ++l) {

for (int j = 0; j < min({(i) + 1, N}); ++j) {

for (int k = 0; k < N; ++k) {

for (int s = max({k, 0}); s < N; ++s) {

for (int t = max({l, 0}); t < min({(k) + 1, N}); ++t) {







E[i][j][k][l][s][t] += E[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int l = max({i, 0}); l < N; ++l) {

for (int j = 0; j < min({(i) + 1, N}); ++j) {

for (int k = 0; k < N; ++k) {

for (int s = 0; s < min({(k) + 1, N}); ++s) {

for (int t = max({l, 0}); t < min({(s) + 1, N}); ++t) {







E[i][j][k][l][s][t] += E[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int j = 0; j < min({(i) + 1, N}); ++j) {

for (int k = 0; k < N; ++k) {

for (int s = max({i, 0}); s < min({(k) + 1, N}); ++s) {

for (int l = max({k, 0}); l < N; ++l) {

for (int t = max({l, 0}); t < N; ++t) {







E[i][j][k][l][s][t] += E[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int j = 0; j < min({(i) + 1, N}); ++j) {

for (int k = 0; k < N; ++k) {

for (int s = max({i, 0}); s < min({(k) + 1, N}); ++s) {

for (int l = 0; l < N; ++l) {

for (int t = max({k, 0}); t < min({(l) + 1, N}); ++t) {







E[i][j][k][l][s][t] += E[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int j = 0; j < min({(i) + 1, N}); ++j) {

for (int k = 0; k < N; ++k) {

for (int t = max({k, 0}); t < N; ++t) {

for (int l = 0; l < min({(k) + 1, N}); ++l) {

for (int s = max({i, 0}); s < min({(l) + 1, N}); ++s) {







E[i][j][k][l][s][t] += E[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int j = 0; j < min({(i) + 1, N}); ++j) {

for (int k = 0; k < N; ++k) {

for (int l = 0; l < N; ++l) {

for (int s = max({i, 0}); s < min({(l) + 1, N}); ++s) {

for (int t = max({l, 0}); t < min({(k) + 1, N}); ++t) {







E[i][j][k][l][s][t] += E[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int s = max({i, 0}); s < N; ++s) {

for (int j = 0; j < min({(i) + 1, N}); ++j) {

for (int k = 0; k < N; ++k) {

for (int t = max({s, 0}); t < min({(k) + 1, N}); ++t) {

for (int l = max({k, 0}); l < N; ++l) {







E[i][j][k][l][s][t] += E[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int s = max({i, 0}); s < N; ++s) {

for (int j = 0; j < min({(i) + 1, N}); ++j) {

for (int k = 0; k < N; ++k) {

for (int l = 0; l < min({(k) + 1, N}); ++l) {

for (int t = max({s, 0}); t < min({(l) + 1, N}); ++t) {







E[i][j][k][l][s][t] += E[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int j = 0; j < min({(i) + 1, N}); ++j) {

for (int k = 0; k < N; ++k) {

for (int t = max({i, 0}); t < min({(k) + 1, N}); ++t) {

for (int l = max({k, 0}); l < N; ++l) {

for (int s = max({l, 0}); s < N; ++s) {







E[i][j][k][l][s][t] += E[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int j = 0; j < min({(i) + 1, N}); ++j) {

for (int k = 0; k < N; ++k) {

for (int t = max({i, 0}); t < min({(k) + 1, N}); ++t) {

for (int l = 0; l < N; ++l) {

for (int s = max({k, 0}); s < min({(l) + 1, N}); ++s) {







E[i][j][k][l][s][t] += E[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int j = 0; j < min({(i) + 1, N}); ++j) {

for (int k = 0; k < N; ++k) {

for (int s = max({k, 0}); s < N; ++s) {

for (int l = 0; l < min({(k) + 1, N}); ++l) {

for (int t = max({i, 0}); t < min({(l) + 1, N}); ++t) {







E[i][j][k][l][s][t] += E[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int j = 0; j < min({(i) + 1, N}); ++j) {

for (int k = 0; k < N; ++k) {

for (int l = 0; l < N; ++l) {

for (int s = max({l, 0}); s < min({(k) + 1, N}); ++s) {

for (int t = max({i, 0}); t < min({(l) + 1, N}); ++t) {







E[i][j][k][l][s][t] += E[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int j = 0; j < min({(i) + 1, N}); ++j) {

for (int k = 0; k < N; ++k) {

for (int s = 0; s < min({(k) + 1, N}); ++s) {

for (int l = max({k, 0}); l < N; ++l) {

for (int t = max({i, 0}); t < min({(s) + 1, N}); ++t) {







E[i][j][k][l][s][t] += E[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int j = 0; j < min({(i) + 1, N}); ++j) {

for (int k = 0; k < N; ++k) {

for (int l = 0; l < min({(k) + 1, N}); ++l) {

for (int s = 0; s < min({(l) + 1, N}); ++s) {

for (int t = max({i, 0}); t < min({(s) + 1, N}); ++t) {







E[i][j][k][l][s][t] += E[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int j = 0; j < N; ++j) {

for (int l = max({j, 0}); l < N; ++l) {

for (int k = 0; k < min({(j) + 1, N}); ++k) {

for (int s = max({l, 0}); s < N; ++s) {

for (int t = max({s, 0}); t < min({(i) + 1, N}); ++t) {







E[i][j][k][l][s][t] += E[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int t = max({i, 0}); t < N; ++t) {

for (int j = 0; j < N; ++j) {

for (int l = max({j, 0}); l < N; ++l) {

for (int k = 0; k < min({(j) + 1, N}); ++k) {

for (int s = max({l, 0}); s < min({(i) + 1, N}); ++s) {







E[i][j][k][l][s][t] += E[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int s = 0; s < min({(i) + 1, N}); ++s) {

for (int j = 0; j < N; ++j) {

for (int l = max({j, 0}); l < N; ++l) {

for (int k = 0; k < min({(j) + 1, N}); ++k) {

for (int t = max({l, 0}); t < min({(s) + 1, N}); ++t) {







E[i][j][k][l][s][t] += E[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int s = max({i, 0}); s < N; ++s) {

for (int j = 0; j < N; ++j) {

for (int l = max({j, 0}); l < N; ++l) {

for (int k = 0; k < min({(j) + 1, N}); ++k) {

for (int t = max({l, 0}); t < min({(i) + 1, N}); ++t) {







E[i][j][k][l][s][t] += E[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int s = max({i, 0}); s < N; ++s) {

for (int t = max({s, 0}); t < N; ++t) {

for (int j = 0; j < N; ++j) {

for (int l = max({j, 0}); l < min({(i) + 1, N}); ++l) {

for (int k = 0; k < min({(j) + 1, N}); ++k) {







E[i][j][k][l][s][t] += E[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int j = 0; j < N; ++j) {

for (int l = max({j, 0}); l < min({(i) + 1, N}); ++l) {

for (int k = 0; k < min({(j) + 1, N}); ++k) {

for (int s = 0; s < N; ++s) {

for (int t = max({i, 0}); t < min({(s) + 1, N}); ++t) {







E[i][j][k][l][s][t] += E[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int j = 0; j < N; ++j) {

for (int k = 0; k < min({(j) + 1, N}); ++k) {

for (int l = 0; l < N; ++l) {

for (int s = max({j, 0}); s < min({(l) + 1, N}); ++s) {

for (int t = max({l, 0}); t < min({(i) + 1, N}); ++t) {







E[i][j][k][l][s][t] += E[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int t = max({i, 0}); t < N; ++t) {

for (int l = 0; l < min({(i) + 1, N}); ++l) {

for (int j = 0; j < N; ++j) {

for (int s = max({j, 0}); s < min({(l) + 1, N}); ++s) {

for (int k = 0; k < min({(j) + 1, N}); ++k) {







E[i][j][k][l][s][t] += E[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int l = 0; l < min({(i) + 1, N}); ++l) {

for (int j = 0; j < N; ++j) {

for (int s = max({j, 0}); s < N; ++s) {

for (int k = 0; k < min({(j) + 1, N}); ++k) {

for (int t = max({s, 0}); t < min({(l) + 1, N}); ++t) {







E[i][j][k][l][s][t] += E[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int l = max({i, 0}); l < N; ++l) {

for (int j = 0; j < N; ++j) {

for (int s = max({j, 0}); s < N; ++s) {

for (int k = 0; k < min({(j) + 1, N}); ++k) {

for (int t = max({s, 0}); t < min({(i) + 1, N}); ++t) {







E[i][j][k][l][s][t] += E[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int l = max({i, 0}); l < N; ++l) {

for (int t = max({l, 0}); t < N; ++t) {

for (int j = 0; j < N; ++j) {

for (int s = max({j, 0}); s < min({(i) + 1, N}); ++s) {

for (int k = 0; k < min({(j) + 1, N}); ++k) {







E[i][j][k][l][s][t] += E[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int j = 0; j < N; ++j) {

for (int s = max({j, 0}); s < min({(i) + 1, N}); ++s) {

for (int k = 0; k < min({(j) + 1, N}); ++k) {

for (int l = 0; l < N; ++l) {

for (int t = max({i, 0}); t < min({(l) + 1, N}); ++t) {







E[i][j][k][l][s][t] += E[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int j = 0; j < N; ++j) {

for (int k = 0; k < min({(j) + 1, N}); ++k) {

for (int l = 0; l < N; ++l) {

for (int s = max({l, 0}); s < min({(i) + 1, N}); ++s) {

for (int t = max({j, 0}); t < min({(l) + 1, N}); ++t) {







E[i][j][k][l][s][t] += E[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int s = max({i, 0}); s < N; ++s) {

for (int l = 0; l < min({(i) + 1, N}); ++l) {

for (int j = 0; j < N; ++j) {

for (int t = max({j, 0}); t < min({(l) + 1, N}); ++t) {

for (int k = 0; k < min({(j) + 1, N}); ++k) {







E[i][j][k][l][s][t] += E[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int l = 0; l < min({(i) + 1, N}); ++l) {

for (int s = 0; s < min({(l) + 1, N}); ++s) {

for (int j = 0; j < N; ++j) {

for (int t = max({j, 0}); t < min({(s) + 1, N}); ++t) {

for (int k = 0; k < min({(j) + 1, N}); ++k) {







E[i][j][k][l][s][t] += E[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int s = 0; s < min({(i) + 1, N}); ++s) {

for (int l = max({i, 0}); l < N; ++l) {

for (int j = 0; j < N; ++j) {

for (int t = max({j, 0}); t < min({(s) + 1, N}); ++t) {

for (int k = 0; k < min({(j) + 1, N}); ++k) {







E[i][j][k][l][s][t] += E[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int l = max({i, 0}); l < N; ++l) {

for (int s = max({l, 0}); s < N; ++s) {

for (int j = 0; j < N; ++j) {

for (int t = max({j, 0}); t < min({(i) + 1, N}); ++t) {

for (int k = 0; k < min({(j) + 1, N}); ++k) {







E[i][j][k][l][s][t] += E[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int j = 0; j < N; ++j) {

for (int t = max({j, 0}); t < min({(i) + 1, N}); ++t) {

for (int k = 0; k < min({(j) + 1, N}); ++k) {

for (int l = 0; l < N; ++l) {

for (int s = max({i, 0}); s < min({(l) + 1, N}); ++s) {







E[i][j][k][l][s][t] += E[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int l = max({i, 0}); l < N; ++l) {

for (int j = 0; j < min({(i) + 1, N}); ++j) {

for (int s = max({l, 0}); s < N; ++s) {

for (int k = 0; k < min({(j) + 1, N}); ++k) {

for (int t = max({s, 0}); t < N; ++t) {







E[i][j][k][l][s][t] += E[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int l = max({i, 0}); l < N; ++l) {

for (int j = 0; j < min({(i) + 1, N}); ++j) {

for (int k = 0; k < min({(j) + 1, N}); ++k) {

for (int s = 0; s < N; ++s) {

for (int t = max({l, 0}); t < min({(s) + 1, N}); ++t) {







E[i][j][k][l][s][t] += E[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int j = 0; j < min({(i) + 1, N}); ++j) {

for (int k = 0; k < min({(j) + 1, N}); ++k) {

for (int l = 0; l < N; ++l) {

for (int s = max({i, 0}); s < min({(l) + 1, N}); ++s) {

for (int t = max({l, 0}); t < N; ++t) {







E[i][j][k][l][s][t] += E[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int s = max({i, 0}); s < N; ++s) {

for (int j = 0; j < min({(i) + 1, N}); ++j) {

for (int k = 0; k < min({(j) + 1, N}); ++k) {

for (int l = 0; l < N; ++l) {

for (int t = max({s, 0}); t < min({(l) + 1, N}); ++t) {







E[i][j][k][l][s][t] += E[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int j = 0; j < min({(i) + 1, N}); ++j) {

for (int k = 0; k < min({(j) + 1, N}); ++k) {

for (int l = 0; l < N; ++l) {

for (int s = max({l, 0}); s < N; ++s) {

for (int t = max({i, 0}); t < min({(l) + 1, N}); ++t) {







E[i][j][k][l][s][t] += E[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int j = 0; j < min({(i) + 1, N}); ++j) {

for (int k = 0; k < min({(j) + 1, N}); ++k) {

for (int l = 0; l < N; ++l) {

for (int s = 0; s < min({(l) + 1, N}); ++s) {

for (int t = max({i, 0}); t < min({(s) + 1, N}); ++t) {







E[i][j][k][l][s][t] += E[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int j = 0; j < N; ++j) {

for (int s = max({j, 0}); s < N; ++s) {

for (int t = max({s, 0}); t < min({(i) + 1, N}); ++t) {

for (int k = 0; k < N; ++k) {

for (int l = max({k, 0}); l < min({(j) + 1, N}); ++l) {







E[i][j][k][l][s][t] += E[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int t = max({i, 0}); t < N; ++t) {

for (int j = 0; j < N; ++j) {

for (int s = max({j, 0}); s < min({(i) + 1, N}); ++s) {

for (int k = 0; k < N; ++k) {

for (int l = max({k, 0}); l < min({(j) + 1, N}); ++l) {







E[i][j][k][l][s][t] += E[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int s = 0; s < min({(i) + 1, N}); ++s) {

for (int j = 0; j < N; ++j) {

for (int t = max({j, 0}); t < min({(s) + 1, N}); ++t) {

for (int k = 0; k < N; ++k) {

for (int l = max({k, 0}); l < min({(j) + 1, N}); ++l) {







E[i][j][k][l][s][t] += E[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int s = max({i, 0}); s < N; ++s) {

for (int j = 0; j < N; ++j) {

for (int t = max({j, 0}); t < min({(i) + 1, N}); ++t) {

for (int k = 0; k < N; ++k) {

for (int l = max({k, 0}); l < min({(j) + 1, N}); ++l) {







E[i][j][k][l][s][t] += E[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int s = max({i, 0}); s < N; ++s) {

for (int j = 0; j < min({(i) + 1, N}); ++j) {

for (int t = max({s, 0}); t < N; ++t) {

for (int k = 0; k < N; ++k) {

for (int l = max({k, 0}); l < min({(j) + 1, N}); ++l) {







E[i][j][k][l][s][t] += E[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int j = 0; j < min({(i) + 1, N}); ++j) {

for (int k = 0; k < N; ++k) {

for (int l = max({k, 0}); l < min({(j) + 1, N}); ++l) {

for (int s = 0; s < N; ++s) {

for (int t = max({i, 0}); t < min({(s) + 1, N}); ++t) {







E[i][j][k][l][s][t] += E[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int j = 0; j < N; ++j) {

for (int t = max({j, 0}); t < min({(i) + 1, N}); ++t) {

for (int k = 0; k < N; ++k) {

for (int l = max({k, 0}); l < N; ++l) {

for (int s = max({l, 0}); s < min({(j) + 1, N}); ++s) {







E[i][j][k][l][s][t] += E[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int t = max({i, 0}); t < N; ++t) {

for (int j = 0; j < min({(i) + 1, N}); ++j) {

for (int k = 0; k < N; ++k) {

for (int l = max({k, 0}); l < N; ++l) {

for (int s = max({l, 0}); s < min({(j) + 1, N}); ++s) {







E[i][j][k][l][s][t] += E[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int j = 0; j < min({(i) + 1, N}); ++j) {

for (int k = 0; k < N; ++k) {

for (int l = max({k, 0}); l < N; ++l) {

for (int s = max({l, 0}); s < N; ++s) {

for (int t = max({s, 0}); t < min({(j) + 1, N}); ++t) {







E[i][j][k][l][s][t] += E[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int j = max({i, 0}); j < N; ++j) {

for (int k = 0; k < N; ++k) {

for (int l = max({k, 0}); l < N; ++l) {

for (int s = max({l, 0}); s < N; ++s) {

for (int t = max({s, 0}); t < min({(i) + 1, N}); ++t) {







E[i][j][k][l][s][t] += E[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int j = max({i, 0}); j < N; ++j) {

for (int t = max({j, 0}); t < N; ++t) {

for (int k = 0; k < N; ++k) {

for (int l = max({k, 0}); l < N; ++l) {

for (int s = max({l, 0}); s < min({(i) + 1, N}); ++s) {







E[i][j][k][l][s][t] += E[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int j = 0; j < N; ++j) {

for (int t = max({i, 0}); t < min({(j) + 1, N}); ++t) {

for (int k = 0; k < N; ++k) {

for (int l = max({k, 0}); l < N; ++l) {

for (int s = max({l, 0}); s < min({(i) + 1, N}); ++s) {







E[i][j][k][l][s][t] += E[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int j = 0; j < N; ++j) {

for (int s = max({j, 0}); s < min({(i) + 1, N}); ++s) {

for (int k = 0; k < N; ++k) {

for (int l = max({k, 0}); l < N; ++l) {

for (int t = max({l, 0}); t < min({(j) + 1, N}); ++t) {







E[i][j][k][l][s][t] += E[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int s = max({i, 0}); s < N; ++s) {

for (int j = 0; j < min({(i) + 1, N}); ++j) {

for (int k = 0; k < N; ++k) {

for (int l = max({k, 0}); l < N; ++l) {

for (int t = max({l, 0}); t < min({(j) + 1, N}); ++t) {







E[i][j][k][l][s][t] += E[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int j = 0; j < min({(i) + 1, N}); ++j) {

for (int s = 0; s < min({(j) + 1, N}); ++s) {

for (int k = 0; k < N; ++k) {

for (int l = max({k, 0}); l < N; ++l) {

for (int t = max({l, 0}); t < min({(s) + 1, N}); ++t) {







E[i][j][k][l][s][t] += E[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int s = 0; s < min({(i) + 1, N}); ++s) {

for (int j = max({i, 0}); j < N; ++j) {

for (int k = 0; k < N; ++k) {

for (int l = max({k, 0}); l < N; ++l) {

for (int t = max({l, 0}); t < min({(s) + 1, N}); ++t) {







E[i][j][k][l][s][t] += E[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int j = max({i, 0}); j < N; ++j) {

for (int s = max({j, 0}); s < N; ++s) {

for (int k = 0; k < N; ++k) {

for (int l = max({k, 0}); l < N; ++l) {

for (int t = max({l, 0}); t < min({(i) + 1, N}); ++t) {







E[i][j][k][l][s][t] += E[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int j = 0; j < N; ++j) {

for (int s = max({i, 0}); s < min({(j) + 1, N}); ++s) {

for (int k = 0; k < N; ++k) {

for (int l = max({k, 0}); l < N; ++l) {

for (int t = max({l, 0}); t < min({(i) + 1, N}); ++t) {







E[i][j][k][l][s][t] += E[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int j = max({i, 0}); j < N; ++j) {

for (int s = max({j, 0}); s < N; ++s) {

for (int t = max({s, 0}); t < N; ++t) {

for (int k = 0; k < N; ++k) {

for (int l = max({k, 0}); l < min({(i) + 1, N}); ++l) {







E[i][j][k][l][s][t] += E[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int j = max({i, 0}); j < N; ++j) {

for (int k = 0; k < N; ++k) {

for (int l = max({k, 0}); l < min({(i) + 1, N}); ++l) {

for (int s = 0; s < N; ++s) {

for (int t = max({j, 0}); t < min({(s) + 1, N}); ++t) {







E[i][j][k][l][s][t] += E[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int j = 0; j < N; ++j) {

for (int s = max({i, 0}); s < min({(j) + 1, N}); ++s) {

for (int t = max({j, 0}); t < N; ++t) {

for (int k = 0; k < N; ++k) {

for (int l = max({k, 0}); l < min({(i) + 1, N}); ++l) {







E[i][j][k][l][s][t] += E[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int s = max({i, 0}); s < N; ++s) {

for (int j = 0; j < N; ++j) {

for (int t = max({s, 0}); t < min({(j) + 1, N}); ++t) {

for (int k = 0; k < N; ++k) {

for (int l = max({k, 0}); l < min({(i) + 1, N}); ++l) {







E[i][j][k][l][s][t] += E[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int j = 0; j < N; ++j) {

for (int s = max({j, 0}); s < N; ++s) {

for (int t = max({i, 0}); t < min({(j) + 1, N}); ++t) {

for (int k = 0; k < N; ++k) {

for (int l = max({k, 0}); l < min({(i) + 1, N}); ++l) {







E[i][j][k][l][s][t] += E[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int j = 0; j < N; ++j) {

for (int s = 0; s < min({(j) + 1, N}); ++s) {

for (int t = max({i, 0}); t < min({(s) + 1, N}); ++t) {

for (int k = 0; k < N; ++k) {

for (int l = max({k, 0}); l < min({(i) + 1, N}); ++l) {







E[i][j][k][l][s][t] += E[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int j = 0; j < N; ++j) {

for (int l = max({j, 0}); l < N; ++l) {

for (int t = max({l, 0}); t < min({(i) + 1, N}); ++t) {

for (int k = 0; k < N; ++k) {

for (int s = max({k, 0}); s < min({(j) + 1, N}); ++s) {







E[i][j][k][l][s][t] += E[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int t = max({i, 0}); t < N; ++t) {

for (int j = 0; j < N; ++j) {

for (int l = max({j, 0}); l < min({(i) + 1, N}); ++l) {

for (int k = 0; k < N; ++k) {

for (int s = max({k, 0}); s < min({(j) + 1, N}); ++s) {







E[i][j][k][l][s][t] += E[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int l = 0; l < min({(i) + 1, N}); ++l) {

for (int j = 0; j < N; ++j) {

for (int t = max({j, 0}); t < min({(l) + 1, N}); ++t) {

for (int k = 0; k < N; ++k) {

for (int s = max({k, 0}); s < min({(j) + 1, N}); ++s) {







E[i][j][k][l][s][t] += E[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int l = max({i, 0}); l < N; ++l) {

for (int j = 0; j < N; ++j) {

for (int t = max({j, 0}); t < min({(i) + 1, N}); ++t) {

for (int k = 0; k < N; ++k) {

for (int s = max({k, 0}); s < min({(j) + 1, N}); ++s) {







E[i][j][k][l][s][t] += E[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int l = max({i, 0}); l < N; ++l) {

for (int j = 0; j < min({(i) + 1, N}); ++j) {

for (int t = max({l, 0}); t < N; ++t) {

for (int k = 0; k < N; ++k) {

for (int s = max({k, 0}); s < min({(j) + 1, N}); ++s) {







E[i][j][k][l][s][t] += E[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int j = 0; j < min({(i) + 1, N}); ++j) {

for (int k = 0; k < N; ++k) {

for (int s = max({k, 0}); s < min({(j) + 1, N}); ++s) {

for (int l = 0; l < N; ++l) {

for (int t = max({i, 0}); t < min({(l) + 1, N}); ++t) {







E[i][j][k][l][s][t] += E[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int j = 0; j < N; ++j) {

for (int t = max({j, 0}); t < min({(i) + 1, N}); ++t) {

for (int l = 0; l < min({(j) + 1, N}); ++l) {

for (int k = 0; k < N; ++k) {

for (int s = max({k, 0}); s < min({(l) + 1, N}); ++s) {







E[i][j][k][l][s][t] += E[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int t = max({i, 0}); t < N; ++t) {

for (int j = 0; j < min({(i) + 1, N}); ++j) {

for (int l = 0; l < min({(j) + 1, N}); ++l) {

for (int k = 0; k < N; ++k) {

for (int s = max({k, 0}); s < min({(l) + 1, N}); ++s) {







E[i][j][k][l][s][t] += E[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int j = 0; j < min({(i) + 1, N}); ++j) {

for (int k = 0; k < N; ++k) {

for (int l = 0; l < N; ++l) {

for (int s = max({k, 0}); s < min({(l) + 1, N}); ++s) {

for (int t = max({l, 0}); t < min({(j) + 1, N}); ++t) {







E[i][j][k][l][s][t] += E[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int j = max({i, 0}); j < N; ++j) {

for (int k = 0; k < N; ++k) {

for (int l = 0; l < N; ++l) {

for (int s = max({k, 0}); s < min({(l) + 1, N}); ++s) {

for (int t = max({l, 0}); t < min({(i) + 1, N}); ++t) {







E[i][j][k][l][s][t] += E[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int l = 0; l < min({(i) + 1, N}); ++l) {

for (int j = max({i, 0}); j < N; ++j) {

for (int t = max({j, 0}); t < N; ++t) {

for (int k = 0; k < N; ++k) {

for (int s = max({k, 0}); s < min({(l) + 1, N}); ++s) {







E[i][j][k][l][s][t] += E[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int l = 0; l < min({(i) + 1, N}); ++l) {

for (int j = 0; j < N; ++j) {

for (int t = max({i, 0}); t < min({(j) + 1, N}); ++t) {

for (int k = 0; k < N; ++k) {

for (int s = max({k, 0}); s < min({(l) + 1, N}); ++s) {







E[i][j][k][l][s][t] += E[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int j = 0; j < N; ++j) {

for (int l = max({j, 0}); l < min({(i) + 1, N}); ++l) {

for (int k = 0; k < N; ++k) {

for (int s = max({k, 0}); s < N; ++s) {

for (int t = max({s, 0}); t < min({(j) + 1, N}); ++t) {







E[i][j][k][l][s][t] += E[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int l = max({i, 0}); l < N; ++l) {

for (int j = 0; j < min({(i) + 1, N}); ++j) {

for (int k = 0; k < N; ++k) {

for (int s = max({k, 0}); s < N; ++s) {

for (int t = max({s, 0}); t < min({(j) + 1, N}); ++t) {







E[i][j][k][l][s][t] += E[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int j = 0; j < min({(i) + 1, N}); ++j) {

for (int l = 0; l < min({(j) + 1, N}); ++l) {

for (int k = 0; k < N; ++k) {

for (int s = max({k, 0}); s < N; ++s) {

for (int t = max({s, 0}); t < min({(l) + 1, N}); ++t) {







E[i][j][k][l][s][t] += E[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int l = 0; l < min({(i) + 1, N}); ++l) {

for (int j = max({i, 0}); j < N; ++j) {

for (int k = 0; k < N; ++k) {

for (int s = max({k, 0}); s < N; ++s) {

for (int t = max({s, 0}); t < min({(l) + 1, N}); ++t) {







E[i][j][k][l][s][t] += E[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int j = max({i, 0}); j < N; ++j) {

for (int l = max({j, 0}); l < N; ++l) {

for (int k = 0; k < N; ++k) {

for (int s = max({k, 0}); s < N; ++s) {

for (int t = max({s, 0}); t < min({(i) + 1, N}); ++t) {







E[i][j][k][l][s][t] += E[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int j = 0; j < N; ++j) {

for (int l = max({i, 0}); l < min({(j) + 1, N}); ++l) {

for (int k = 0; k < N; ++k) {

for (int s = max({k, 0}); s < N; ++s) {

for (int t = max({s, 0}); t < min({(i) + 1, N}); ++t) {







E[i][j][k][l][s][t] += E[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int j = max({i, 0}); j < N; ++j) {

for (int l = max({j, 0}); l < N; ++l) {

for (int t = max({l, 0}); t < N; ++t) {

for (int k = 0; k < N; ++k) {

for (int s = max({k, 0}); s < min({(i) + 1, N}); ++s) {







E[i][j][k][l][s][t] += E[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int j = max({i, 0}); j < N; ++j) {

for (int k = 0; k < N; ++k) {

for (int s = max({k, 0}); s < min({(i) + 1, N}); ++s) {

for (int l = 0; l < N; ++l) {

for (int t = max({j, 0}); t < min({(l) + 1, N}); ++t) {







E[i][j][k][l][s][t] += E[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int j = 0; j < N; ++j) {

for (int t = max({j, 0}); t < N; ++t) {

for (int l = max({i, 0}); l < min({(j) + 1, N}); ++l) {

for (int k = 0; k < N; ++k) {

for (int s = max({k, 0}); s < min({(i) + 1, N}); ++s) {







E[i][j][k][l][s][t] += E[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int l = max({i, 0}); l < N; ++l) {

for (int j = 0; j < N; ++j) {

for (int t = max({l, 0}); t < min({(j) + 1, N}); ++t) {

for (int k = 0; k < N; ++k) {

for (int s = max({k, 0}); s < min({(i) + 1, N}); ++s) {







E[i][j][k][l][s][t] += E[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int j = 0; j < N; ++j) {

for (int t = max({i, 0}); t < min({(j) + 1, N}); ++t) {

for (int l = max({j, 0}); l < N; ++l) {

for (int k = 0; k < N; ++k) {

for (int s = max({k, 0}); s < min({(i) + 1, N}); ++s) {







E[i][j][k][l][s][t] += E[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int j = 0; j < N; ++j) {

for (int l = 0; l < min({(j) + 1, N}); ++l) {

for (int t = max({i, 0}); t < min({(l) + 1, N}); ++t) {

for (int k = 0; k < N; ++k) {

for (int s = max({k, 0}); s < min({(i) + 1, N}); ++s) {







E[i][j][k][l][s][t] += E[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int j = 0; j < N; ++j) {

for (int l = max({j, 0}); l < N; ++l) {

for (int s = max({l, 0}); s < min({(i) + 1, N}); ++s) {

for (int k = 0; k < N; ++k) {

for (int t = max({k, 0}); t < min({(j) + 1, N}); ++t) {







E[i][j][k][l][s][t] += E[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int s = max({i, 0}); s < N; ++s) {

for (int j = 0; j < N; ++j) {

for (int l = max({j, 0}); l < min({(i) + 1, N}); ++l) {

for (int k = 0; k < N; ++k) {

for (int t = max({k, 0}); t < min({(j) + 1, N}); ++t) {







E[i][j][k][l][s][t] += E[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int l = 0; l < min({(i) + 1, N}); ++l) {

for (int j = 0; j < N; ++j) {

for (int s = max({j, 0}); s < min({(l) + 1, N}); ++s) {

for (int k = 0; k < N; ++k) {

for (int t = max({k, 0}); t < min({(j) + 1, N}); ++t) {







E[i][j][k][l][s][t] += E[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int l = max({i, 0}); l < N; ++l) {

for (int j = 0; j < N; ++j) {

for (int s = max({j, 0}); s < min({(i) + 1, N}); ++s) {

for (int k = 0; k < N; ++k) {

for (int t = max({k, 0}); t < min({(j) + 1, N}); ++t) {







E[i][j][k][l][s][t] += E[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int l = max({i, 0}); l < N; ++l) {

for (int j = 0; j < min({(i) + 1, N}); ++j) {

for (int s = max({l, 0}); s < N; ++s) {

for (int k = 0; k < N; ++k) {

for (int t = max({k, 0}); t < min({(j) + 1, N}); ++t) {







E[i][j][k][l][s][t] += E[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int j = 0; j < min({(i) + 1, N}); ++j) {

for (int k = 0; k < N; ++k) {

for (int t = max({k, 0}); t < min({(j) + 1, N}); ++t) {

for (int l = 0; l < N; ++l) {

for (int s = max({i, 0}); s < min({(l) + 1, N}); ++s) {







E[i][j][k][l][s][t] += E[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int j = 0; j < N; ++j) {

for (int s = max({j, 0}); s < min({(i) + 1, N}); ++s) {

for (int l = 0; l < min({(j) + 1, N}); ++l) {

for (int k = 0; k < N; ++k) {

for (int t = max({k, 0}); t < min({(l) + 1, N}); ++t) {







E[i][j][k][l][s][t] += E[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int s = max({i, 0}); s < N; ++s) {

for (int j = 0; j < min({(i) + 1, N}); ++j) {

for (int l = 0; l < min({(j) + 1, N}); ++l) {

for (int k = 0; k < N; ++k) {

for (int t = max({k, 0}); t < min({(l) + 1, N}); ++t) {







E[i][j][k][l][s][t] += E[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int j = 0; j < min({(i) + 1, N}); ++j) {

for (int k = 0; k < N; ++k) {

for (int l = 0; l < N; ++l) {

for (int s = max({l, 0}); s < min({(j) + 1, N}); ++s) {

for (int t = max({k, 0}); t < min({(l) + 1, N}); ++t) {







E[i][j][k][l][s][t] += E[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int j = max({i, 0}); j < N; ++j) {

for (int k = 0; k < N; ++k) {

for (int l = 0; l < N; ++l) {

for (int s = max({l, 0}); s < min({(i) + 1, N}); ++s) {

for (int t = max({k, 0}); t < min({(l) + 1, N}); ++t) {







E[i][j][k][l][s][t] += E[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int l = 0; l < min({(i) + 1, N}); ++l) {

for (int j = max({i, 0}); j < N; ++j) {

for (int s = max({j, 0}); s < N; ++s) {

for (int k = 0; k < N; ++k) {

for (int t = max({k, 0}); t < min({(l) + 1, N}); ++t) {







E[i][j][k][l][s][t] += E[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int l = 0; l < min({(i) + 1, N}); ++l) {

for (int j = 0; j < N; ++j) {

for (int s = max({i, 0}); s < min({(j) + 1, N}); ++s) {

for (int k = 0; k < N; ++k) {

for (int t = max({k, 0}); t < min({(l) + 1, N}); ++t) {







E[i][j][k][l][s][t] += E[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int j = 0; j < N; ++j) {

for (int s = 0; s < min({(j) + 1, N}); ++s) {

for (int l = max({j, 0}); l < min({(i) + 1, N}); ++l) {

for (int k = 0; k < N; ++k) {

for (int t = max({k, 0}); t < min({(s) + 1, N}); ++t) {







E[i][j][k][l][s][t] += E[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int l = max({i, 0}); l < N; ++l) {

for (int j = 0; j < min({(i) + 1, N}); ++j) {

for (int s = 0; s < min({(j) + 1, N}); ++s) {

for (int k = 0; k < N; ++k) {

for (int t = max({k, 0}); t < min({(s) + 1, N}); ++t) {







E[i][j][k][l][s][t] += E[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int j = 0; j < min({(i) + 1, N}); ++j) {

for (int l = 0; l < min({(j) + 1, N}); ++l) {

for (int s = 0; s < min({(l) + 1, N}); ++s) {

for (int k = 0; k < N; ++k) {

for (int t = max({k, 0}); t < min({(s) + 1, N}); ++t) {







E[i][j][k][l][s][t] += E[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int l = 0; l < min({(i) + 1, N}); ++l) {

for (int j = max({i, 0}); j < N; ++j) {

for (int s = 0; s < min({(l) + 1, N}); ++s) {

for (int k = 0; k < N; ++k) {

for (int t = max({k, 0}); t < min({(s) + 1, N}); ++t) {







E[i][j][k][l][s][t] += E[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int s = 0; s < min({(i) + 1, N}); ++s) {

for (int j = max({i, 0}); j < N; ++j) {

for (int l = max({j, 0}); l < N; ++l) {

for (int k = 0; k < N; ++k) {

for (int t = max({k, 0}); t < min({(s) + 1, N}); ++t) {







E[i][j][k][l][s][t] += E[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int s = 0; s < min({(i) + 1, N}); ++s) {

for (int j = 0; j < N; ++j) {

for (int l = max({i, 0}); l < min({(j) + 1, N}); ++l) {

for (int k = 0; k < N; ++k) {

for (int t = max({k, 0}); t < min({(s) + 1, N}); ++t) {







E[i][j][k][l][s][t] += E[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int j = max({i, 0}); j < N; ++j) {

for (int l = max({j, 0}); l < N; ++l) {

for (int s = max({l, 0}); s < N; ++s) {

for (int k = 0; k < N; ++k) {

for (int t = max({k, 0}); t < min({(i) + 1, N}); ++t) {







E[i][j][k][l][s][t] += E[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int j = max({i, 0}); j < N; ++j) {

for (int k = 0; k < N; ++k) {

for (int t = max({k, 0}); t < min({(i) + 1, N}); ++t) {

for (int l = 0; l < N; ++l) {

for (int s = max({j, 0}); s < min({(l) + 1, N}); ++s) {







E[i][j][k][l][s][t] += E[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int j = 0; j < N; ++j) {

for (int s = max({j, 0}); s < N; ++s) {

for (int l = max({i, 0}); l < min({(j) + 1, N}); ++l) {

for (int k = 0; k < N; ++k) {

for (int t = max({k, 0}); t < min({(i) + 1, N}); ++t) {







E[i][j][k][l][s][t] += E[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int l = max({i, 0}); l < N; ++l) {

for (int j = 0; j < N; ++j) {

for (int s = max({l, 0}); s < min({(j) + 1, N}); ++s) {

for (int k = 0; k < N; ++k) {

for (int t = max({k, 0}); t < min({(i) + 1, N}); ++t) {







E[i][j][k][l][s][t] += E[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int j = 0; j < N; ++j) {

for (int s = max({i, 0}); s < min({(j) + 1, N}); ++s) {

for (int l = max({j, 0}); l < N; ++l) {

for (int k = 0; k < N; ++k) {

for (int t = max({k, 0}); t < min({(i) + 1, N}); ++t) {







E[i][j][k][l][s][t] += E[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int j = 0; j < N; ++j) {

for (int l = 0; l < min({(j) + 1, N}); ++l) {

for (int s = max({i, 0}); s < min({(l) + 1, N}); ++s) {

for (int k = 0; k < N; ++k) {

for (int t = max({k, 0}); t < min({(i) + 1, N}); ++t) {







E[i][j][k][l][s][t] += E[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int j = max({i, 0}); j < N; ++j) {

for (int k = 0; k < min({(i) + 1, N}); ++k) {

for (int l = max({j, 0}); l < N; ++l) {

for (int s = max({l, 0}); s < N; ++s) {

for (int t = max({s, 0}); t < N; ++t) {







E[i][j][k][l][s][t] += E[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int j = max({i, 0}); j < N; ++j) {

for (int k = 0; k < min({(i) + 1, N}); ++k) {

for (int l = max({j, 0}); l < N; ++l) {

for (int s = 0; s < N; ++s) {

for (int t = max({l, 0}); t < min({(s) + 1, N}); ++t) {







E[i][j][k][l][s][t] += E[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int j = max({i, 0}); j < N; ++j) {

for (int k = 0; k < min({(i) + 1, N}); ++k) {

for (int l = 0; l < N; ++l) {

for (int s = max({j, 0}); s < min({(l) + 1, N}); ++s) {

for (int t = max({l, 0}); t < N; ++t) {







E[i][j][k][l][s][t] += E[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int j = max({i, 0}); j < N; ++j) {

for (int k = 0; k < min({(i) + 1, N}); ++k) {

for (int s = max({j, 0}); s < N; ++s) {

for (int l = 0; l < N; ++l) {

for (int t = max({s, 0}); t < min({(l) + 1, N}); ++t) {







E[i][j][k][l][s][t] += E[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int j = max({i, 0}); j < N; ++j) {

for (int k = 0; k < min({(i) + 1, N}); ++k) {

for (int l = 0; l < N; ++l) {

for (int s = max({l, 0}); s < N; ++s) {

for (int t = max({j, 0}); t < min({(l) + 1, N}); ++t) {







E[i][j][k][l][s][t] += E[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int j = max({i, 0}); j < N; ++j) {

for (int k = 0; k < min({(i) + 1, N}); ++k) {

for (int l = 0; l < N; ++l) {

for (int s = 0; s < min({(l) + 1, N}); ++s) {

for (int t = max({j, 0}); t < min({(s) + 1, N}); ++t) {







E[i][j][k][l][s][t] += E[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int j = 0; j < N; ++j) {

for (int k = 0; k < min({(i) + 1, N}); ++k) {

for (int s = max({j, 0}); s < N; ++s) {

for (int l = max({i, 0}); l < min({(j) + 1, N}); ++l) {

for (int t = max({s, 0}); t < N; ++t) {







E[i][j][k][l][s][t] += E[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int j = 0; j < N; ++j) {

for (int k = 0; k < min({(i) + 1, N}); ++k) {

for (int l = max({i, 0}); l < min({(j) + 1, N}); ++l) {

for (int s = 0; s < N; ++s) {

for (int t = max({j, 0}); t < min({(s) + 1, N}); ++t) {







E[i][j][k][l][s][t] += E[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int l = max({i, 0}); l < N; ++l) {

for (int k = 0; k < min({(i) + 1, N}); ++k) {

for (int j = 0; j < N; ++j) {

for (int s = max({l, 0}); s < min({(j) + 1, N}); ++s) {

for (int t = max({j, 0}); t < N; ++t) {







E[i][j][k][l][s][t] += E[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int l = max({i, 0}); l < N; ++l) {

for (int k = 0; k < min({(i) + 1, N}); ++k) {

for (int s = max({l, 0}); s < N; ++s) {

for (int j = 0; j < N; ++j) {

for (int t = max({s, 0}); t < min({(j) + 1, N}); ++t) {







E[i][j][k][l][s][t] += E[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int l = max({i, 0}); l < N; ++l) {

for (int k = 0; k < min({(i) + 1, N}); ++k) {

for (int j = 0; j < N; ++j) {

for (int s = max({j, 0}); s < N; ++s) {

for (int t = max({l, 0}); t < min({(j) + 1, N}); ++t) {







E[i][j][k][l][s][t] += E[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int l = max({i, 0}); l < N; ++l) {

for (int k = 0; k < min({(i) + 1, N}); ++k) {

for (int j = 0; j < N; ++j) {

for (int s = 0; s < min({(j) + 1, N}); ++s) {

for (int t = max({l, 0}); t < min({(s) + 1, N}); ++t) {







E[i][j][k][l][s][t] += E[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int j = 0; j < N; ++j) {

for (int k = 0; k < min({(i) + 1, N}); ++k) {

for (int s = max({i, 0}); s < min({(j) + 1, N}); ++s) {

for (int l = max({j, 0}); l < N; ++l) {

for (int t = max({l, 0}); t < N; ++t) {







E[i][j][k][l][s][t] += E[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int j = 0; j < N; ++j) {

for (int k = 0; k < min({(i) + 1, N}); ++k) {

for (int s = max({i, 0}); s < min({(j) + 1, N}); ++s) {

for (int l = 0; l < N; ++l) {

for (int t = max({j, 0}); t < min({(l) + 1, N}); ++t) {







E[i][j][k][l][s][t] += E[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int j = 0; j < N; ++j) {

for (int k = 0; k < min({(i) + 1, N}); ++k) {

for (int t = max({j, 0}); t < N; ++t) {

for (int l = 0; l < min({(j) + 1, N}); ++l) {

for (int s = max({i, 0}); s < min({(l) + 1, N}); ++s) {







E[i][j][k][l][s][t] += E[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int j = 0; j < N; ++j) {

for (int k = 0; k < min({(i) + 1, N}); ++k) {

for (int l = 0; l < N; ++l) {

for (int s = max({i, 0}); s < min({(l) + 1, N}); ++s) {

for (int t = max({l, 0}); t < min({(j) + 1, N}); ++t) {







E[i][j][k][l][s][t] += E[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int s = max({i, 0}); s < N; ++s) {

for (int k = 0; k < min({(i) + 1, N}); ++k) {

for (int j = 0; j < N; ++j) {

for (int t = max({s, 0}); t < min({(j) + 1, N}); ++t) {

for (int l = max({j, 0}); l < N; ++l) {







E[i][j][k][l][s][t] += E[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int s = max({i, 0}); s < N; ++s) {

for (int k = 0; k < min({(i) + 1, N}); ++k) {

for (int j = 0; j < N; ++j) {

for (int l = 0; l < min({(j) + 1, N}); ++l) {

for (int t = max({s, 0}); t < min({(l) + 1, N}); ++t) {







E[i][j][k][l][s][t] += E[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int j = 0; j < N; ++j) {

for (int k = 0; k < min({(i) + 1, N}); ++k) {

for (int t = max({i, 0}); t < min({(j) + 1, N}); ++t) {

for (int l = max({j, 0}); l < N; ++l) {

for (int s = max({l, 0}); s < N; ++s) {







E[i][j][k][l][s][t] += E[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int j = 0; j < N; ++j) {

for (int k = 0; k < min({(i) + 1, N}); ++k) {

for (int t = max({i, 0}); t < min({(j) + 1, N}); ++t) {

for (int l = 0; l < N; ++l) {

for (int s = max({j, 0}); s < min({(l) + 1, N}); ++s) {







E[i][j][k][l][s][t] += E[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int j = 0; j < N; ++j) {

for (int k = 0; k < min({(i) + 1, N}); ++k) {

for (int s = max({j, 0}); s < N; ++s) {

for (int l = 0; l < min({(j) + 1, N}); ++l) {

for (int t = max({i, 0}); t < min({(l) + 1, N}); ++t) {







E[i][j][k][l][s][t] += E[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int j = 0; j < N; ++j) {

for (int k = 0; k < min({(i) + 1, N}); ++k) {

for (int l = 0; l < N; ++l) {

for (int s = max({l, 0}); s < min({(j) + 1, N}); ++s) {

for (int t = max({i, 0}); t < min({(l) + 1, N}); ++t) {







E[i][j][k][l][s][t] += E[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int j = 0; j < N; ++j) {

for (int k = 0; k < min({(i) + 1, N}); ++k) {

for (int s = 0; s < min({(j) + 1, N}); ++s) {

for (int l = max({j, 0}); l < N; ++l) {

for (int t = max({i, 0}); t < min({(s) + 1, N}); ++t) {







E[i][j][k][l][s][t] += E[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int j = 0; j < N; ++j) {

for (int k = 0; k < min({(i) + 1, N}); ++k) {

for (int l = 0; l < min({(j) + 1, N}); ++l) {

for (int s = 0; s < min({(l) + 1, N}); ++s) {

for (int t = max({i, 0}); t < min({(s) + 1, N}); ++t) {







E[i][j][k][l][s][t] += E[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int j = 0; j < N; ++j) {

for (int l = 0; l < min({(j) + 1, N}); ++l) {

for (int k = max({j, 0}); k < N; ++k) {

for (int s = max({k, 0}); s < N; ++s) {

for (int t = max({s, 0}); t < min({(i) + 1, N}); ++t) {







E[i][j][k][l][s][t] += E[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int t = max({i, 0}); t < N; ++t) {

for (int j = 0; j < N; ++j) {

for (int l = 0; l < min({(j) + 1, N}); ++l) {

for (int k = max({j, 0}); k < N; ++k) {

for (int s = max({k, 0}); s < min({(i) + 1, N}); ++s) {







E[i][j][k][l][s][t] += E[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int s = 0; s < min({(i) + 1, N}); ++s) {

for (int j = 0; j < N; ++j) {

for (int l = 0; l < min({(j) + 1, N}); ++l) {

for (int k = max({j, 0}); k < N; ++k) {

for (int t = max({k, 0}); t < min({(s) + 1, N}); ++t) {







E[i][j][k][l][s][t] += E[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int s = max({i, 0}); s < N; ++s) {

for (int j = 0; j < N; ++j) {

for (int l = 0; l < min({(j) + 1, N}); ++l) {

for (int k = max({j, 0}); k < N; ++k) {

for (int t = max({k, 0}); t < min({(i) + 1, N}); ++t) {







E[i][j][k][l][s][t] += E[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int s = max({i, 0}); s < N; ++s) {

for (int t = max({s, 0}); t < N; ++t) {

for (int j = 0; j < N; ++j) {

for (int l = 0; l < min({(j) + 1, N}); ++l) {

for (int k = max({j, 0}); k < min({(i) + 1, N}); ++k) {







E[i][j][k][l][s][t] += E[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int j = 0; j < N; ++j) {

for (int l = 0; l < min({(j) + 1, N}); ++l) {

for (int k = max({j, 0}); k < min({(i) + 1, N}); ++k) {

for (int s = 0; s < N; ++s) {

for (int t = max({i, 0}); t < min({(s) + 1, N}); ++t) {







E[i][j][k][l][s][t] += E[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int j = 0; j < N; ++j) {

for (int l = 0; l < min({(j) + 1, N}); ++l) {

for (int k = 0; k < N; ++k) {

for (int s = max({j, 0}); s < min({(k) + 1, N}); ++s) {

for (int t = max({k, 0}); t < min({(i) + 1, N}); ++t) {







E[i][j][k][l][s][t] += E[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int t = max({i, 0}); t < N; ++t) {

for (int k = 0; k < min({(i) + 1, N}); ++k) {

for (int j = 0; j < N; ++j) {

for (int s = max({j, 0}); s < min({(k) + 1, N}); ++s) {

for (int l = 0; l < min({(j) + 1, N}); ++l) {







E[i][j][k][l][s][t] += E[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int j = 0; j < N; ++j) {

for (int k = 0; k < min({(i) + 1, N}); ++k) {

for (int s = max({j, 0}); s < N; ++s) {

for (int l = 0; l < min({(j) + 1, N}); ++l) {

for (int t = max({s, 0}); t < min({(k) + 1, N}); ++t) {







E[i][j][k][l][s][t] += E[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int j = 0; j < N; ++j) {

for (int k = max({i, 0}); k < N; ++k) {

for (int s = max({j, 0}); s < N; ++s) {

for (int l = 0; l < min({(j) + 1, N}); ++l) {

for (int t = max({s, 0}); t < min({(i) + 1, N}); ++t) {







E[i][j][k][l][s][t] += E[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int j = 0; j < N; ++j) {

for (int k = max({i, 0}); k < N; ++k) {

for (int s = max({j, 0}); s < min({(i) + 1, N}); ++s) {

for (int l = 0; l < min({(j) + 1, N}); ++l) {

for (int t = max({k, 0}); t < N; ++t) {







E[i][j][k][l][s][t] += E[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int j = 0; j < N; ++j) {

for (int s = max({j, 0}); s < min({(i) + 1, N}); ++s) {

for (int l = 0; l < min({(j) + 1, N}); ++l) {

for (int k = 0; k < N; ++k) {

for (int t = max({i, 0}); t < min({(k) + 1, N}); ++t) {







E[i][j][k][l][s][t] += E[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int j = 0; j < N; ++j) {

for (int l = 0; l < min({(j) + 1, N}); ++l) {

for (int k = 0; k < N; ++k) {

for (int s = max({k, 0}); s < min({(i) + 1, N}); ++s) {

for (int t = max({j, 0}); t < min({(k) + 1, N}); ++t) {







E[i][j][k][l][s][t] += E[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int s = max({i, 0}); s < N; ++s) {

for (int k = 0; k < min({(i) + 1, N}); ++k) {

for (int j = 0; j < N; ++j) {

for (int t = max({j, 0}); t < min({(k) + 1, N}); ++t) {

for (int l = 0; l < min({(j) + 1, N}); ++l) {







E[i][j][k][l][s][t] += E[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int j = 0; j < N; ++j) {

for (int k = 0; k < min({(i) + 1, N}); ++k) {

for (int l = 0; l < min({(j) + 1, N}); ++l) {

for (int s = 0; s < min({(k) + 1, N}); ++s) {

for (int t = max({j, 0}); t < min({(s) + 1, N}); ++t) {







E[i][j][k][l][s][t] += E[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int s = 0; s < min({(i) + 1, N}); ++s) {

for (int k = max({i, 0}); k < N; ++k) {

for (int j = 0; j < N; ++j) {

for (int t = max({j, 0}); t < min({(s) + 1, N}); ++t) {

for (int l = 0; l < min({(j) + 1, N}); ++l) {







E[i][j][k][l][s][t] += E[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int j = 0; j < N; ++j) {

for (int k = max({i, 0}); k < N; ++k) {

for (int t = max({j, 0}); t < min({(i) + 1, N}); ++t) {

for (int l = 0; l < min({(j) + 1, N}); ++l) {

for (int s = max({k, 0}); s < N; ++s) {







E[i][j][k][l][s][t] += E[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int j = 0; j < N; ++j) {

for (int t = max({j, 0}); t < min({(i) + 1, N}); ++t) {

for (int l = 0; l < min({(j) + 1, N}); ++l) {

for (int k = 0; k < N; ++k) {

for (int s = max({i, 0}); s < min({(k) + 1, N}); ++s) {







E[i][j][k][l][s][t] += E[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int j = 0; j < min({(i) + 1, N}); ++j) {

for (int k = max({i, 0}); k < N; ++k) {

for (int l = 0; l < min({(j) + 1, N}); ++l) {

for (int s = max({k, 0}); s < N; ++s) {

for (int t = max({s, 0}); t < N; ++t) {







E[i][j][k][l][s][t] += E[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int j = 0; j < min({(i) + 1, N}); ++j) {

for (int k = max({i, 0}); k < N; ++k) {

for (int l = 0; l < min({(j) + 1, N}); ++l) {

for (int s = 0; s < N; ++s) {

for (int t = max({k, 0}); t < min({(s) + 1, N}); ++t) {







E[i][j][k][l][s][t] += E[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int j = 0; j < min({(i) + 1, N}); ++j) {

for (int l = 0; l < min({(j) + 1, N}); ++l) {

for (int k = 0; k < N; ++k) {

for (int s = max({i, 0}); s < min({(k) + 1, N}); ++s) {

for (int t = max({k, 0}); t < N; ++t) {







E[i][j][k][l][s][t] += E[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int s = max({i, 0}); s < N; ++s) {

for (int j = 0; j < min({(i) + 1, N}); ++j) {

for (int l = 0; l < min({(j) + 1, N}); ++l) {

for (int k = 0; k < N; ++k) {

for (int t = max({s, 0}); t < min({(k) + 1, N}); ++t) {







E[i][j][k][l][s][t] += E[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int j = 0; j < min({(i) + 1, N}); ++j) {

for (int l = 0; l < min({(j) + 1, N}); ++l) {

for (int k = 0; k < N; ++k) {

for (int s = max({k, 0}); s < N; ++s) {

for (int t = max({i, 0}); t < min({(k) + 1, N}); ++t) {







E[i][j][k][l][s][t] += E[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int j = 0; j < min({(i) + 1, N}); ++j) {

for (int l = 0; l < min({(j) + 1, N}); ++l) {

for (int k = 0; k < N; ++k) {

for (int s = 0; s < min({(k) + 1, N}); ++s) {

for (int t = max({i, 0}); t < min({(s) + 1, N}); ++t) {







E[i][j][k][l][s][t] += E[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int j = 0; j < N; ++j) {

for (int s = max({j, 0}); s < N; ++s) {

for (int k = 0; k < min({(j) + 1, N}); ++k) {

for (int t = max({s, 0}); t < min({(i) + 1, N}); ++t) {

for (int l = 0; l < min({(k) + 1, N}); ++l) {







E[i][j][k][l][s][t] += E[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int t = max({i, 0}); t < N; ++t) {

for (int j = 0; j < N; ++j) {

for (int s = max({j, 0}); s < min({(i) + 1, N}); ++s) {

for (int k = 0; k < min({(j) + 1, N}); ++k) {

for (int l = 0; l < min({(k) + 1, N}); ++l) {







E[i][j][k][l][s][t] += E[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int s = 0; s < min({(i) + 1, N}); ++s) {

for (int j = 0; j < N; ++j) {

for (int t = max({j, 0}); t < min({(s) + 1, N}); ++t) {

for (int k = 0; k < min({(j) + 1, N}); ++k) {

for (int l = 0; l < min({(k) + 1, N}); ++l) {







E[i][j][k][l][s][t] += E[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int s = max({i, 0}); s < N; ++s) {

for (int j = 0; j < N; ++j) {

for (int t = max({j, 0}); t < min({(i) + 1, N}); ++t) {

for (int k = 0; k < min({(j) + 1, N}); ++k) {

for (int l = 0; l < min({(k) + 1, N}); ++l) {







E[i][j][k][l][s][t] += E[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int s = max({i, 0}); s < N; ++s) {

for (int j = 0; j < min({(i) + 1, N}); ++j) {

for (int t = max({s, 0}); t < N; ++t) {

for (int k = 0; k < min({(j) + 1, N}); ++k) {

for (int l = 0; l < min({(k) + 1, N}); ++l) {







E[i][j][k][l][s][t] += E[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int j = 0; j < min({(i) + 1, N}); ++j) {

for (int k = 0; k < min({(j) + 1, N}); ++k) {

for (int l = 0; l < min({(k) + 1, N}); ++l) {

for (int s = 0; s < N; ++s) {

for (int t = max({i, 0}); t < min({(s) + 1, N}); ++t) {







E[i][j][k][l][s][t] += E[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int j = 0; j < N; ++j) {

for (int t = max({j, 0}); t < min({(i) + 1, N}); ++t) {

for (int k = 0; k < N; ++k) {

for (int s = max({k, 0}); s < min({(j) + 1, N}); ++s) {

for (int l = 0; l < min({(k) + 1, N}); ++l) {







E[i][j][k][l][s][t] += E[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int t = max({i, 0}); t < N; ++t) {

for (int j = 0; j < min({(i) + 1, N}); ++j) {

for (int k = 0; k < N; ++k) {

for (int s = max({k, 0}); s < min({(j) + 1, N}); ++s) {

for (int l = 0; l < min({(k) + 1, N}); ++l) {







E[i][j][k][l][s][t] += E[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int j = 0; j < min({(i) + 1, N}); ++j) {

for (int k = 0; k < N; ++k) {

for (int s = max({k, 0}); s < N; ++s) {

for (int l = 0; l < min({(k) + 1, N}); ++l) {

for (int t = max({s, 0}); t < min({(j) + 1, N}); ++t) {







E[i][j][k][l][s][t] += E[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int j = max({i, 0}); j < N; ++j) {

for (int k = 0; k < N; ++k) {

for (int s = max({k, 0}); s < N; ++s) {

for (int l = 0; l < min({(k) + 1, N}); ++l) {

for (int t = max({s, 0}); t < min({(i) + 1, N}); ++t) {







E[i][j][k][l][s][t] += E[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int j = max({i, 0}); j < N; ++j) {

for (int t = max({j, 0}); t < N; ++t) {

for (int k = 0; k < N; ++k) {

for (int s = max({k, 0}); s < min({(i) + 1, N}); ++s) {

for (int l = 0; l < min({(k) + 1, N}); ++l) {







E[i][j][k][l][s][t] += E[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int j = 0; j < N; ++j) {

for (int t = max({i, 0}); t < min({(j) + 1, N}); ++t) {

for (int k = 0; k < N; ++k) {

for (int s = max({k, 0}); s < min({(i) + 1, N}); ++s) {

for (int l = 0; l < min({(k) + 1, N}); ++l) {







E[i][j][k][l][s][t] += E[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int j = 0; j < N; ++j) {

for (int s = max({j, 0}); s < min({(i) + 1, N}); ++s) {

for (int k = 0; k < N; ++k) {

for (int t = max({k, 0}); t < min({(j) + 1, N}); ++t) {

for (int l = 0; l < min({(k) + 1, N}); ++l) {







E[i][j][k][l][s][t] += E[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int s = max({i, 0}); s < N; ++s) {

for (int j = 0; j < min({(i) + 1, N}); ++j) {

for (int k = 0; k < N; ++k) {

for (int t = max({k, 0}); t < min({(j) + 1, N}); ++t) {

for (int l = 0; l < min({(k) + 1, N}); ++l) {







E[i][j][k][l][s][t] += E[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int j = 0; j < min({(i) + 1, N}); ++j) {

for (int s = 0; s < min({(j) + 1, N}); ++s) {

for (int k = 0; k < N; ++k) {

for (int t = max({k, 0}); t < min({(s) + 1, N}); ++t) {

for (int l = 0; l < min({(k) + 1, N}); ++l) {







E[i][j][k][l][s][t] += E[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int s = 0; s < min({(i) + 1, N}); ++s) {

for (int j = max({i, 0}); j < N; ++j) {

for (int k = 0; k < N; ++k) {

for (int t = max({k, 0}); t < min({(s) + 1, N}); ++t) {

for (int l = 0; l < min({(k) + 1, N}); ++l) {







E[i][j][k][l][s][t] += E[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int j = max({i, 0}); j < N; ++j) {

for (int s = max({j, 0}); s < N; ++s) {

for (int k = 0; k < N; ++k) {

for (int t = max({k, 0}); t < min({(i) + 1, N}); ++t) {

for (int l = 0; l < min({(k) + 1, N}); ++l) {







E[i][j][k][l][s][t] += E[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int j = 0; j < N; ++j) {

for (int s = max({i, 0}); s < min({(j) + 1, N}); ++s) {

for (int k = 0; k < N; ++k) {

for (int t = max({k, 0}); t < min({(i) + 1, N}); ++t) {

for (int l = 0; l < min({(k) + 1, N}); ++l) {







E[i][j][k][l][s][t] += E[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int j = max({i, 0}); j < N; ++j) {

for (int k = 0; k < min({(i) + 1, N}); ++k) {

for (int s = max({j, 0}); s < N; ++s) {

for (int l = 0; l < min({(k) + 1, N}); ++l) {

for (int t = max({s, 0}); t < N; ++t) {







E[i][j][k][l][s][t] += E[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int j = max({i, 0}); j < N; ++j) {

for (int k = 0; k < min({(i) + 1, N}); ++k) {

for (int l = 0; l < min({(k) + 1, N}); ++l) {

for (int s = 0; s < N; ++s) {

for (int t = max({j, 0}); t < min({(s) + 1, N}); ++t) {







E[i][j][k][l][s][t] += E[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int j = 0; j < N; ++j) {

for (int k = 0; k < min({(i) + 1, N}); ++k) {

for (int s = max({i, 0}); s < min({(j) + 1, N}); ++s) {

for (int t = max({j, 0}); t < N; ++t) {

for (int l = 0; l < min({(k) + 1, N}); ++l) {







E[i][j][k][l][s][t] += E[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int s = max({i, 0}); s < N; ++s) {

for (int k = 0; k < min({(i) + 1, N}); ++k) {

for (int l = 0; l < min({(k) + 1, N}); ++l) {

for (int j = 0; j < N; ++j) {

for (int t = max({s, 0}); t < min({(j) + 1, N}); ++t) {







E[i][j][k][l][s][t] += E[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int j = 0; j < N; ++j) {

for (int k = 0; k < min({(i) + 1, N}); ++k) {

for (int s = max({j, 0}); s < N; ++s) {

for (int t = max({i, 0}); t < min({(j) + 1, N}); ++t) {

for (int l = 0; l < min({(k) + 1, N}); ++l) {







E[i][j][k][l][s][t] += E[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int j = 0; j < N; ++j) {

for (int k = 0; k < min({(i) + 1, N}); ++k) {

for (int s = 0; s < min({(j) + 1, N}); ++s) {

for (int l = 0; l < min({(k) + 1, N}); ++l) {

for (int t = max({i, 0}); t < min({(s) + 1, N}); ++t) {







E[i][j][k][l][s][t] += E[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int j = 0; j < N; ++j) {

for (int k = max({j, 0}); k < N; ++k) {

for (int t = max({k, 0}); t < min({(i) + 1, N}); ++t) {

for (int l = 0; l < N; ++l) {

for (int s = max({l, 0}); s < min({(j) + 1, N}); ++s) {







E[i][j][k][l][s][t] += E[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int t = max({i, 0}); t < N; ++t) {

for (int j = 0; j < N; ++j) {

for (int k = max({j, 0}); k < min({(i) + 1, N}); ++k) {

for (int l = 0; l < N; ++l) {

for (int s = max({l, 0}); s < min({(j) + 1, N}); ++s) {







E[i][j][k][l][s][t] += E[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int j = 0; j < N; ++j) {

for (int k = 0; k < min({(i) + 1, N}); ++k) {

for (int t = max({j, 0}); t < min({(k) + 1, N}); ++t) {

for (int l = 0; l < N; ++l) {

for (int s = max({l, 0}); s < min({(j) + 1, N}); ++s) {







E[i][j][k][l][s][t] += E[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int j = 0; j < N; ++j) {

for (int k = max({i, 0}); k < N; ++k) {

for (int t = max({j, 0}); t < min({(i) + 1, N}); ++t) {

for (int l = 0; l < N; ++l) {

for (int s = max({l, 0}); s < min({(j) + 1, N}); ++s) {







E[i][j][k][l][s][t] += E[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int j = 0; j < min({(i) + 1, N}); ++j) {

for (int k = max({i, 0}); k < N; ++k) {

for (int t = max({k, 0}); t < N; ++t) {

for (int l = 0; l < N; ++l) {

for (int s = max({l, 0}); s < min({(j) + 1, N}); ++s) {







E[i][j][k][l][s][t] += E[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int j = 0; j < min({(i) + 1, N}); ++j) {

for (int k = 0; k < N; ++k) {

for (int t = max({i, 0}); t < min({(k) + 1, N}); ++t) {

for (int l = 0; l < N; ++l) {

for (int s = max({l, 0}); s < min({(j) + 1, N}); ++s) {







E[i][j][k][l][s][t] += E[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int j = 0; j < N; ++j) {

for (int t = max({j, 0}); t < min({(i) + 1, N}); ++t) {

for (int k = 0; k < min({(j) + 1, N}); ++k) {

for (int l = 0; l < N; ++l) {

for (int s = max({l, 0}); s < min({(k) + 1, N}); ++s) {







E[i][j][k][l][s][t] += E[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int t = max({i, 0}); t < N; ++t) {

for (int j = 0; j < min({(i) + 1, N}); ++j) {

for (int k = 0; k < min({(j) + 1, N}); ++k) {

for (int l = 0; l < N; ++l) {

for (int s = max({l, 0}); s < min({(k) + 1, N}); ++s) {







E[i][j][k][l][s][t] += E[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int j = 0; j < min({(i) + 1, N}); ++j) {

for (int k = 0; k < N; ++k) {

for (int t = max({k, 0}); t < min({(j) + 1, N}); ++t) {

for (int l = 0; l < N; ++l) {

for (int s = max({l, 0}); s < min({(k) + 1, N}); ++s) {







E[i][j][k][l][s][t] += E[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int j = max({i, 0}); j < N; ++j) {

for (int k = 0; k < N; ++k) {

for (int t = max({k, 0}); t < min({(i) + 1, N}); ++t) {

for (int l = 0; l < N; ++l) {

for (int s = max({l, 0}); s < min({(k) + 1, N}); ++s) {







E[i][j][k][l][s][t] += E[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int j = max({i, 0}); j < N; ++j) {

for (int k = 0; k < min({(i) + 1, N}); ++k) {

for (int t = max({j, 0}); t < N; ++t) {

for (int l = 0; l < N; ++l) {

for (int s = max({l, 0}); s < min({(k) + 1, N}); ++s) {







E[i][j][k][l][s][t] += E[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int j = 0; j < N; ++j) {

for (int k = 0; k < min({(i) + 1, N}); ++k) {

for (int t = max({i, 0}); t < min({(j) + 1, N}); ++t) {

for (int l = 0; l < N; ++l) {

for (int s = max({l, 0}); s < min({(k) + 1, N}); ++s) {







E[i][j][k][l][s][t] += E[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int j = 0; j < N; ++j) {

for (int k = max({j, 0}); k < min({(i) + 1, N}); ++k) {

for (int l = 0; l < N; ++l) {

for (int s = max({l, 0}); s < N; ++s) {

for (int t = max({s, 0}); t < min({(j) + 1, N}); ++t) {







E[i][j][k][l][s][t] += E[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int j = 0; j < min({(i) + 1, N}); ++j) {

for (int k = max({i, 0}); k < N; ++k) {

for (int l = 0; l < N; ++l) {

for (int s = max({l, 0}); s < N; ++s) {

for (int t = max({s, 0}); t < min({(j) + 1, N}); ++t) {







E[i][j][k][l][s][t] += E[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int j = 0; j < min({(i) + 1, N}); ++j) {

for (int k = 0; k < min({(j) + 1, N}); ++k) {

for (int l = 0; l < N; ++l) {

for (int s = max({l, 0}); s < N; ++s) {

for (int t = max({s, 0}); t < min({(k) + 1, N}); ++t) {







E[i][j][k][l][s][t] += E[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int j = max({i, 0}); j < N; ++j) {

for (int k = 0; k < min({(i) + 1, N}); ++k) {

for (int l = 0; l < N; ++l) {

for (int s = max({l, 0}); s < N; ++s) {

for (int t = max({s, 0}); t < min({(k) + 1, N}); ++t) {







E[i][j][k][l][s][t] += E[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int j = max({i, 0}); j < N; ++j) {

for (int k = max({j, 0}); k < N; ++k) {

for (int l = 0; l < N; ++l) {

for (int s = max({l, 0}); s < N; ++s) {

for (int t = max({s, 0}); t < min({(i) + 1, N}); ++t) {







E[i][j][k][l][s][t] += E[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int j = 0; j < N; ++j) {

for (int k = max({i, 0}); k < min({(j) + 1, N}); ++k) {

for (int l = 0; l < N; ++l) {

for (int s = max({l, 0}); s < N; ++s) {

for (int t = max({s, 0}); t < min({(i) + 1, N}); ++t) {







E[i][j][k][l][s][t] += E[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int j = max({i, 0}); j < N; ++j) {

for (int k = max({j, 0}); k < N; ++k) {

for (int t = max({k, 0}); t < N; ++t) {

for (int l = 0; l < N; ++l) {

for (int s = max({l, 0}); s < min({(i) + 1, N}); ++s) {







E[i][j][k][l][s][t] += E[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int j = max({i, 0}); j < N; ++j) {

for (int k = 0; k < N; ++k) {

for (int t = max({j, 0}); t < min({(k) + 1, N}); ++t) {

for (int l = 0; l < N; ++l) {

for (int s = max({l, 0}); s < min({(i) + 1, N}); ++s) {







E[i][j][k][l][s][t] += E[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int j = 0; j < N; ++j) {

for (int t = max({j, 0}); t < N; ++t) {

for (int k = max({i, 0}); k < min({(j) + 1, N}); ++k) {

for (int l = 0; l < N; ++l) {

for (int s = max({l, 0}); s < min({(i) + 1, N}); ++s) {







E[i][j][k][l][s][t] += E[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int j = 0; j < N; ++j) {

for (int k = max({i, 0}); k < N; ++k) {

for (int t = max({k, 0}); t < min({(j) + 1, N}); ++t) {

for (int l = 0; l < N; ++l) {

for (int s = max({l, 0}); s < min({(i) + 1, N}); ++s) {







E[i][j][k][l][s][t] += E[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int j = 0; j < N; ++j) {

for (int t = max({i, 0}); t < min({(j) + 1, N}); ++t) {

for (int k = max({j, 0}); k < N; ++k) {

for (int l = 0; l < N; ++l) {

for (int s = max({l, 0}); s < min({(i) + 1, N}); ++s) {







E[i][j][k][l][s][t] += E[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int j = 0; j < N; ++j) {

for (int k = 0; k < min({(j) + 1, N}); ++k) {

for (int t = max({i, 0}); t < min({(k) + 1, N}); ++t) {

for (int l = 0; l < N; ++l) {

for (int s = max({l, 0}); s < min({(i) + 1, N}); ++s) {







E[i][j][k][l][s][t] += E[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int j = 0; j < N; ++j) {

for (int k = max({j, 0}); k < N; ++k) {

for (int s = max({k, 0}); s < min({(i) + 1, N}); ++s) {

for (int l = 0; l < N; ++l) {

for (int t = max({l, 0}); t < min({(j) + 1, N}); ++t) {







E[i][j][k][l][s][t] += E[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int s = max({i, 0}); s < N; ++s) {

for (int j = 0; j < N; ++j) {

for (int k = max({j, 0}); k < min({(i) + 1, N}); ++k) {

for (int l = 0; l < N; ++l) {

for (int t = max({l, 0}); t < min({(j) + 1, N}); ++t) {







E[i][j][k][l][s][t] += E[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int j = 0; j < N; ++j) {

for (int k = 0; k < min({(i) + 1, N}); ++k) {

for (int s = max({j, 0}); s < min({(k) + 1, N}); ++s) {

for (int l = 0; l < N; ++l) {

for (int t = max({l, 0}); t < min({(j) + 1, N}); ++t) {







E[i][j][k][l][s][t] += E[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int j = 0; j < N; ++j) {

for (int k = max({i, 0}); k < N; ++k) {

for (int s = max({j, 0}); s < min({(i) + 1, N}); ++s) {

for (int l = 0; l < N; ++l) {

for (int t = max({l, 0}); t < min({(j) + 1, N}); ++t) {







E[i][j][k][l][s][t] += E[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int j = 0; j < min({(i) + 1, N}); ++j) {

for (int k = max({i, 0}); k < N; ++k) {

for (int s = max({k, 0}); s < N; ++s) {

for (int l = 0; l < N; ++l) {

for (int t = max({l, 0}); t < min({(j) + 1, N}); ++t) {







E[i][j][k][l][s][t] += E[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int j = 0; j < min({(i) + 1, N}); ++j) {

for (int k = 0; k < N; ++k) {

for (int s = max({i, 0}); s < min({(k) + 1, N}); ++s) {

for (int l = 0; l < N; ++l) {

for (int t = max({l, 0}); t < min({(j) + 1, N}); ++t) {







E[i][j][k][l][s][t] += E[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int j = 0; j < N; ++j) {

for (int s = max({j, 0}); s < min({(i) + 1, N}); ++s) {

for (int k = 0; k < min({(j) + 1, N}); ++k) {

for (int l = 0; l < N; ++l) {

for (int t = max({l, 0}); t < min({(k) + 1, N}); ++t) {







E[i][j][k][l][s][t] += E[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int s = max({i, 0}); s < N; ++s) {

for (int j = 0; j < min({(i) + 1, N}); ++j) {

for (int k = 0; k < min({(j) + 1, N}); ++k) {

for (int l = 0; l < N; ++l) {

for (int t = max({l, 0}); t < min({(k) + 1, N}); ++t) {







E[i][j][k][l][s][t] += E[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int j = 0; j < min({(i) + 1, N}); ++j) {

for (int k = 0; k < N; ++k) {

for (int s = max({k, 0}); s < min({(j) + 1, N}); ++s) {

for (int l = 0; l < N; ++l) {

for (int t = max({l, 0}); t < min({(k) + 1, N}); ++t) {







E[i][j][k][l][s][t] += E[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int j = max({i, 0}); j < N; ++j) {

for (int k = 0; k < N; ++k) {

for (int s = max({k, 0}); s < min({(i) + 1, N}); ++s) {

for (int l = 0; l < N; ++l) {

for (int t = max({l, 0}); t < min({(k) + 1, N}); ++t) {







E[i][j][k][l][s][t] += E[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int j = max({i, 0}); j < N; ++j) {

for (int k = 0; k < min({(i) + 1, N}); ++k) {

for (int s = max({j, 0}); s < N; ++s) {

for (int l = 0; l < N; ++l) {

for (int t = max({l, 0}); t < min({(k) + 1, N}); ++t) {







E[i][j][k][l][s][t] += E[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int j = 0; j < N; ++j) {

for (int k = 0; k < min({(i) + 1, N}); ++k) {

for (int s = max({i, 0}); s < min({(j) + 1, N}); ++s) {

for (int l = 0; l < N; ++l) {

for (int t = max({l, 0}); t < min({(k) + 1, N}); ++t) {







E[i][j][k][l][s][t] += E[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int j = 0; j < N; ++j) {

for (int s = 0; s < min({(j) + 1, N}); ++s) {

for (int k = max({j, 0}); k < min({(i) + 1, N}); ++k) {

for (int l = 0; l < N; ++l) {

for (int t = max({l, 0}); t < min({(s) + 1, N}); ++t) {







E[i][j][k][l][s][t] += E[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int j = 0; j < min({(i) + 1, N}); ++j) {

for (int k = max({i, 0}); k < N; ++k) {

for (int s = 0; s < min({(j) + 1, N}); ++s) {

for (int l = 0; l < N; ++l) {

for (int t = max({l, 0}); t < min({(s) + 1, N}); ++t) {







E[i][j][k][l][s][t] += E[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int j = 0; j < min({(i) + 1, N}); ++j) {

for (int k = 0; k < min({(j) + 1, N}); ++k) {

for (int s = 0; s < min({(k) + 1, N}); ++s) {

for (int l = 0; l < N; ++l) {

for (int t = max({l, 0}); t < min({(s) + 1, N}); ++t) {







E[i][j][k][l][s][t] += E[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int j = max({i, 0}); j < N; ++j) {

for (int k = 0; k < min({(i) + 1, N}); ++k) {

for (int s = 0; s < min({(k) + 1, N}); ++s) {

for (int l = 0; l < N; ++l) {

for (int t = max({l, 0}); t < min({(s) + 1, N}); ++t) {







E[i][j][k][l][s][t] += E[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int s = 0; s < min({(i) + 1, N}); ++s) {

for (int j = max({i, 0}); j < N; ++j) {

for (int k = max({j, 0}); k < N; ++k) {

for (int l = 0; l < N; ++l) {

for (int t = max({l, 0}); t < min({(s) + 1, N}); ++t) {







E[i][j][k][l][s][t] += E[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int s = 0; s < min({(i) + 1, N}); ++s) {

for (int j = 0; j < N; ++j) {

for (int k = max({i, 0}); k < min({(j) + 1, N}); ++k) {

for (int l = 0; l < N; ++l) {

for (int t = max({l, 0}); t < min({(s) + 1, N}); ++t) {







E[i][j][k][l][s][t] += E[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int j = max({i, 0}); j < N; ++j) {

for (int k = max({j, 0}); k < N; ++k) {

for (int s = max({k, 0}); s < N; ++s) {

for (int l = 0; l < N; ++l) {

for (int t = max({l, 0}); t < min({(i) + 1, N}); ++t) {







E[i][j][k][l][s][t] += E[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int j = max({i, 0}); j < N; ++j) {

for (int k = 0; k < N; ++k) {

for (int s = max({j, 0}); s < min({(k) + 1, N}); ++s) {

for (int l = 0; l < N; ++l) {

for (int t = max({l, 0}); t < min({(i) + 1, N}); ++t) {







E[i][j][k][l][s][t] += E[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int j = 0; j < N; ++j) {

for (int s = max({j, 0}); s < N; ++s) {

for (int k = max({i, 0}); k < min({(j) + 1, N}); ++k) {

for (int l = 0; l < N; ++l) {

for (int t = max({l, 0}); t < min({(i) + 1, N}); ++t) {







E[i][j][k][l][s][t] += E[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int j = 0; j < N; ++j) {

for (int k = max({i, 0}); k < N; ++k) {

for (int s = max({k, 0}); s < min({(j) + 1, N}); ++s) {

for (int l = 0; l < N; ++l) {

for (int t = max({l, 0}); t < min({(i) + 1, N}); ++t) {







E[i][j][k][l][s][t] += E[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int j = 0; j < N; ++j) {

for (int s = max({i, 0}); s < min({(j) + 1, N}); ++s) {

for (int k = max({j, 0}); k < N; ++k) {

for (int l = 0; l < N; ++l) {

for (int t = max({l, 0}); t < min({(i) + 1, N}); ++t) {







E[i][j][k][l][s][t] += E[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int j = 0; j < N; ++j) {

for (int k = 0; k < min({(j) + 1, N}); ++k) {

for (int s = max({i, 0}); s < min({(k) + 1, N}); ++s) {

for (int l = 0; l < N; ++l) {

for (int t = max({l, 0}); t < min({(i) + 1, N}); ++t) {







E[i][j][k][l][s][t] += E[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int l = 0; l < min({(i) + 1, N}); ++l) {

for (int j = max({i, 0}); j < N; ++j) {

for (int k = max({j, 0}); k < N; ++k) {

for (int s = max({k, 0}); s < N; ++s) {

for (int t = max({s, 0}); t < N; ++t) {







E[i][j][k][l][s][t] += E[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int l = 0; l < min({(i) + 1, N}); ++l) {

for (int j = max({i, 0}); j < N; ++j) {

for (int k = max({j, 0}); k < N; ++k) {

for (int s = 0; s < N; ++s) {

for (int t = max({k, 0}); t < min({(s) + 1, N}); ++t) {







E[i][j][k][l][s][t] += E[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int l = 0; l < min({(i) + 1, N}); ++l) {

for (int j = max({i, 0}); j < N; ++j) {

for (int k = 0; k < N; ++k) {

for (int s = max({j, 0}); s < min({(k) + 1, N}); ++s) {

for (int t = max({k, 0}); t < N; ++t) {







E[i][j][k][l][s][t] += E[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int l = 0; l < min({(i) + 1, N}); ++l) {

for (int j = max({i, 0}); j < N; ++j) {

for (int s = max({j, 0}); s < N; ++s) {

for (int k = 0; k < N; ++k) {

for (int t = max({s, 0}); t < min({(k) + 1, N}); ++t) {







E[i][j][k][l][s][t] += E[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int l = 0; l < min({(i) + 1, N}); ++l) {

for (int j = max({i, 0}); j < N; ++j) {

for (int k = 0; k < N; ++k) {

for (int s = max({k, 0}); s < N; ++s) {

for (int t = max({j, 0}); t < min({(k) + 1, N}); ++t) {







E[i][j][k][l][s][t] += E[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int l = 0; l < min({(i) + 1, N}); ++l) {

for (int j = max({i, 0}); j < N; ++j) {

for (int k = 0; k < N; ++k) {

for (int s = 0; s < min({(k) + 1, N}); ++s) {

for (int t = max({j, 0}); t < min({(s) + 1, N}); ++t) {







E[i][j][k][l][s][t] += E[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int l = 0; l < min({(i) + 1, N}); ++l) {

for (int j = 0; j < N; ++j) {

for (int s = max({j, 0}); s < N; ++s) {

for (int k = max({i, 0}); k < min({(j) + 1, N}); ++k) {

for (int t = max({s, 0}); t < N; ++t) {







E[i][j][k][l][s][t] += E[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int l = 0; l < min({(i) + 1, N}); ++l) {

for (int j = 0; j < N; ++j) {

for (int k = max({i, 0}); k < min({(j) + 1, N}); ++k) {

for (int s = 0; s < N; ++s) {

for (int t = max({j, 0}); t < min({(s) + 1, N}); ++t) {







E[i][j][k][l][s][t] += E[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int l = 0; l < min({(i) + 1, N}); ++l) {

for (int k = max({i, 0}); k < N; ++k) {

for (int j = 0; j < N; ++j) {

for (int s = max({k, 0}); s < min({(j) + 1, N}); ++s) {

for (int t = max({j, 0}); t < N; ++t) {







E[i][j][k][l][s][t] += E[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int l = 0; l < min({(i) + 1, N}); ++l) {

for (int k = max({i, 0}); k < N; ++k) {

for (int s = max({k, 0}); s < N; ++s) {

for (int j = 0; j < N; ++j) {

for (int t = max({s, 0}); t < min({(j) + 1, N}); ++t) {







E[i][j][k][l][s][t] += E[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int l = 0; l < min({(i) + 1, N}); ++l) {

for (int k = max({i, 0}); k < N; ++k) {

for (int j = 0; j < N; ++j) {

for (int s = max({j, 0}); s < N; ++s) {

for (int t = max({k, 0}); t < min({(j) + 1, N}); ++t) {







E[i][j][k][l][s][t] += E[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int l = 0; l < min({(i) + 1, N}); ++l) {

for (int k = max({i, 0}); k < N; ++k) {

for (int j = 0; j < N; ++j) {

for (int s = 0; s < min({(j) + 1, N}); ++s) {

for (int t = max({k, 0}); t < min({(s) + 1, N}); ++t) {







E[i][j][k][l][s][t] += E[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int l = 0; l < min({(i) + 1, N}); ++l) {

for (int j = 0; j < N; ++j) {

for (int s = max({i, 0}); s < min({(j) + 1, N}); ++s) {

for (int k = max({j, 0}); k < N; ++k) {

for (int t = max({k, 0}); t < N; ++t) {







E[i][j][k][l][s][t] += E[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int l = 0; l < min({(i) + 1, N}); ++l) {

for (int j = 0; j < N; ++j) {

for (int s = max({i, 0}); s < min({(j) + 1, N}); ++s) {

for (int k = 0; k < N; ++k) {

for (int t = max({j, 0}); t < min({(k) + 1, N}); ++t) {







E[i][j][k][l][s][t] += E[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int l = 0; l < min({(i) + 1, N}); ++l) {

for (int j = 0; j < N; ++j) {

for (int t = max({j, 0}); t < N; ++t) {

for (int k = 0; k < min({(j) + 1, N}); ++k) {

for (int s = max({i, 0}); s < min({(k) + 1, N}); ++s) {







E[i][j][k][l][s][t] += E[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int l = 0; l < min({(i) + 1, N}); ++l) {

for (int j = 0; j < N; ++j) {

for (int k = 0; k < N; ++k) {

for (int s = max({i, 0}); s < min({(k) + 1, N}); ++s) {

for (int t = max({k, 0}); t < min({(j) + 1, N}); ++t) {







E[i][j][k][l][s][t] += E[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int s = max({i, 0}); s < N; ++s) {

for (int l = 0; l < min({(i) + 1, N}); ++l) {

for (int j = 0; j < N; ++j) {

for (int t = max({s, 0}); t < min({(j) + 1, N}); ++t) {

for (int k = max({j, 0}); k < N; ++k) {







E[i][j][k][l][s][t] += E[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int s = max({i, 0}); s < N; ++s) {

for (int l = 0; l < min({(i) + 1, N}); ++l) {

for (int j = 0; j < N; ++j) {

for (int k = 0; k < min({(j) + 1, N}); ++k) {

for (int t = max({s, 0}); t < min({(k) + 1, N}); ++t) {







E[i][j][k][l][s][t] += E[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int l = 0; l < min({(i) + 1, N}); ++l) {

for (int j = 0; j < N; ++j) {

for (int t = max({i, 0}); t < min({(j) + 1, N}); ++t) {

for (int k = max({j, 0}); k < N; ++k) {

for (int s = max({k, 0}); s < N; ++s) {







E[i][j][k][l][s][t] += E[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int l = 0; l < min({(i) + 1, N}); ++l) {

for (int j = 0; j < N; ++j) {

for (int t = max({i, 0}); t < min({(j) + 1, N}); ++t) {

for (int k = 0; k < N; ++k) {

for (int s = max({j, 0}); s < min({(k) + 1, N}); ++s) {







E[i][j][k][l][s][t] += E[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int l = 0; l < min({(i) + 1, N}); ++l) {

for (int j = 0; j < N; ++j) {

for (int s = max({j, 0}); s < N; ++s) {

for (int k = 0; k < min({(j) + 1, N}); ++k) {

for (int t = max({i, 0}); t < min({(k) + 1, N}); ++t) {







E[i][j][k][l][s][t] += E[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int l = 0; l < min({(i) + 1, N}); ++l) {

for (int j = 0; j < N; ++j) {

for (int k = 0; k < N; ++k) {

for (int s = max({k, 0}); s < min({(j) + 1, N}); ++s) {

for (int t = max({i, 0}); t < min({(k) + 1, N}); ++t) {







E[i][j][k][l][s][t] += E[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int l = 0; l < min({(i) + 1, N}); ++l) {

for (int j = 0; j < N; ++j) {

for (int s = 0; s < min({(j) + 1, N}); ++s) {

for (int k = max({j, 0}); k < N; ++k) {

for (int t = max({i, 0}); t < min({(s) + 1, N}); ++t) {







E[i][j][k][l][s][t] += E[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int l = 0; l < min({(i) + 1, N}); ++l) {

for (int j = 0; j < N; ++j) {

for (int k = 0; k < min({(j) + 1, N}); ++k) {

for (int s = 0; s < min({(k) + 1, N}); ++s) {

for (int t = max({i, 0}); t < min({(s) + 1, N}); ++t) {







E[i][j][k][l][s][t] += E[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int j = 0; j < N; ++j) {

for (int s = 0; s < min({(j) + 1, N}); ++s) {

for (int k = max({j, 0}); k < N; ++k) {

for (int l = max({k, 0}); l < N; ++l) {

for (int t = max({l, 0}); t < min({(i) + 1, N}); ++t) {







E[i][j][k][l][s][t] += E[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int t = max({i, 0}); t < N; ++t) {

for (int j = 0; j < N; ++j) {

for (int s = 0; s < min({(j) + 1, N}); ++s) {

for (int k = max({j, 0}); k < N; ++k) {

for (int l = max({k, 0}); l < min({(i) + 1, N}); ++l) {







E[i][j][k][l][s][t] += E[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int l = 0; l < min({(i) + 1, N}); ++l) {

for (int j = 0; j < N; ++j) {

for (int s = 0; s < min({(j) + 1, N}); ++s) {

for (int k = max({j, 0}); k < N; ++k) {

for (int t = max({k, 0}); t < min({(l) + 1, N}); ++t) {







E[i][j][k][l][s][t] += E[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int l = max({i, 0}); l < N; ++l) {

for (int j = 0; j < N; ++j) {

for (int s = 0; s < min({(j) + 1, N}); ++s) {

for (int k = max({j, 0}); k < N; ++k) {

for (int t = max({k, 0}); t < min({(i) + 1, N}); ++t) {







E[i][j][k][l][s][t] += E[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int l = max({i, 0}); l < N; ++l) {

for (int t = max({l, 0}); t < N; ++t) {

for (int j = 0; j < N; ++j) {

for (int s = 0; s < min({(j) + 1, N}); ++s) {

for (int k = max({j, 0}); k < min({(i) + 1, N}); ++k) {







E[i][j][k][l][s][t] += E[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int j = 0; j < N; ++j) {

for (int s = 0; s < min({(j) + 1, N}); ++s) {

for (int k = max({j, 0}); k < min({(i) + 1, N}); ++k) {

for (int l = 0; l < N; ++l) {

for (int t = max({i, 0}); t < min({(l) + 1, N}); ++t) {







E[i][j][k][l][s][t] += E[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int j = 0; j < N; ++j) {

for (int s = 0; s < min({(j) + 1, N}); ++s) {

for (int k = 0; k < N; ++k) {

for (int t = max({k, 0}); t < min({(i) + 1, N}); ++t) {

for (int l = max({j, 0}); l < min({(k) + 1, N}); ++l) {







E[i][j][k][l][s][t] += E[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int t = max({i, 0}); t < N; ++t) {

for (int k = 0; k < min({(i) + 1, N}); ++k) {

for (int j = 0; j < N; ++j) {

for (int s = 0; s < min({(j) + 1, N}); ++s) {

for (int l = max({j, 0}); l < min({(k) + 1, N}); ++l) {







E[i][j][k][l][s][t] += E[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int j = 0; j < N; ++j) {

for (int k = 0; k < min({(i) + 1, N}); ++k) {

for (int s = 0; s < min({(j) + 1, N}); ++s) {

for (int l = max({j, 0}); l < N; ++l) {

for (int t = max({l, 0}); t < min({(k) + 1, N}); ++t) {







E[i][j][k][l][s][t] += E[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int j = 0; j < N; ++j) {

for (int k = max({i, 0}); k < N; ++k) {

for (int s = 0; s < min({(j) + 1, N}); ++s) {

for (int l = max({j, 0}); l < N; ++l) {

for (int t = max({l, 0}); t < min({(i) + 1, N}); ++t) {







E[i][j][k][l][s][t] += E[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int j = 0; j < N; ++j) {

for (int k = max({i, 0}); k < N; ++k) {

for (int s = 0; s < min({(j) + 1, N}); ++s) {

for (int l = max({j, 0}); l < min({(i) + 1, N}); ++l) {

for (int t = max({k, 0}); t < N; ++t) {







E[i][j][k][l][s][t] += E[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int j = 0; j < N; ++j) {

for (int s = 0; s < min({(j) + 1, N}); ++s) {

for (int l = max({j, 0}); l < min({(i) + 1, N}); ++l) {

for (int k = 0; k < N; ++k) {

for (int t = max({i, 0}); t < min({(k) + 1, N}); ++t) {







E[i][j][k][l][s][t] += E[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int j = 0; j < N; ++j) {

for (int s = 0; s < min({(j) + 1, N}); ++s) {

for (int k = 0; k < N; ++k) {

for (int t = max({j, 0}); t < min({(k) + 1, N}); ++t) {

for (int l = max({k, 0}); l < min({(i) + 1, N}); ++l) {







E[i][j][k][l][s][t] += E[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int l = max({i, 0}); l < N; ++l) {

for (int k = 0; k < min({(i) + 1, N}); ++k) {

for (int j = 0; j < N; ++j) {

for (int s = 0; s < min({(j) + 1, N}); ++s) {

for (int t = max({j, 0}); t < min({(k) + 1, N}); ++t) {







E[i][j][k][l][s][t] += E[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int j = 0; j < N; ++j) {

for (int k = 0; k < min({(i) + 1, N}); ++k) {

for (int s = 0; s < min({(j) + 1, N}); ++s) {

for (int l = 0; l < min({(k) + 1, N}); ++l) {

for (int t = max({j, 0}); t < min({(l) + 1, N}); ++t) {







E[i][j][k][l][s][t] += E[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int l = 0; l < min({(i) + 1, N}); ++l) {

for (int k = max({i, 0}); k < N; ++k) {

for (int j = 0; j < N; ++j) {

for (int s = 0; s < min({(j) + 1, N}); ++s) {

for (int t = max({j, 0}); t < min({(l) + 1, N}); ++t) {







E[i][j][k][l][s][t] += E[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int j = 0; j < N; ++j) {

for (int k = max({i, 0}); k < N; ++k) {

for (int s = 0; s < min({(j) + 1, N}); ++s) {

for (int t = max({j, 0}); t < min({(i) + 1, N}); ++t) {

for (int l = max({k, 0}); l < N; ++l) {







E[i][j][k][l][s][t] += E[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int j = 0; j < N; ++j) {

for (int s = 0; s < min({(j) + 1, N}); ++s) {

for (int t = max({j, 0}); t < min({(i) + 1, N}); ++t) {

for (int k = 0; k < N; ++k) {

for (int l = max({i, 0}); l < min({(k) + 1, N}); ++l) {







E[i][j][k][l][s][t] += E[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int j = 0; j < min({(i) + 1, N}); ++j) {

for (int k = max({i, 0}); k < N; ++k) {

for (int s = 0; s < min({(j) + 1, N}); ++s) {

for (int l = max({k, 0}); l < N; ++l) {

for (int t = max({l, 0}); t < N; ++t) {







E[i][j][k][l][s][t] += E[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int j = 0; j < min({(i) + 1, N}); ++j) {

for (int k = max({i, 0}); k < N; ++k) {

for (int s = 0; s < min({(j) + 1, N}); ++s) {

for (int l = 0; l < N; ++l) {

for (int t = max({k, 0}); t < min({(l) + 1, N}); ++t) {







E[i][j][k][l][s][t] += E[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int j = 0; j < min({(i) + 1, N}); ++j) {

for (int s = 0; s < min({(j) + 1, N}); ++s) {

for (int k = 0; k < N; ++k) {

for (int t = max({k, 0}); t < N; ++t) {

for (int l = max({i, 0}); l < min({(k) + 1, N}); ++l) {







E[i][j][k][l][s][t] += E[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int l = max({i, 0}); l < N; ++l) {

for (int j = 0; j < min({(i) + 1, N}); ++j) {

for (int s = 0; s < min({(j) + 1, N}); ++s) {

for (int k = 0; k < N; ++k) {

for (int t = max({l, 0}); t < min({(k) + 1, N}); ++t) {







E[i][j][k][l][s][t] += E[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int j = 0; j < min({(i) + 1, N}); ++j) {

for (int s = 0; s < min({(j) + 1, N}); ++s) {

for (int k = 0; k < N; ++k) {

for (int t = max({i, 0}); t < min({(k) + 1, N}); ++t) {

for (int l = max({k, 0}); l < N; ++l) {







E[i][j][k][l][s][t] += E[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int j = 0; j < min({(i) + 1, N}); ++j) {

for (int s = 0; s < min({(j) + 1, N}); ++s) {

for (int k = 0; k < N; ++k) {

for (int l = 0; l < min({(k) + 1, N}); ++l) {

for (int t = max({i, 0}); t < min({(l) + 1, N}); ++t) {







E[i][j][k][l][s][t] += E[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int j = 0; j < N; ++j) {

for (int l = max({j, 0}); l < N; ++l) {

for (int k = 0; k < min({(j) + 1, N}); ++k) {

for (int t = max({l, 0}); t < min({(i) + 1, N}); ++t) {

for (int s = 0; s < min({(k) + 1, N}); ++s) {







E[i][j][k][l][s][t] += E[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int t = max({i, 0}); t < N; ++t) {

for (int j = 0; j < N; ++j) {

for (int l = max({j, 0}); l < min({(i) + 1, N}); ++l) {

for (int k = 0; k < min({(j) + 1, N}); ++k) {

for (int s = 0; s < min({(k) + 1, N}); ++s) {







E[i][j][k][l][s][t] += E[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int l = 0; l < min({(i) + 1, N}); ++l) {

for (int j = 0; j < N; ++j) {

for (int t = max({j, 0}); t < min({(l) + 1, N}); ++t) {

for (int k = 0; k < min({(j) + 1, N}); ++k) {

for (int s = 0; s < min({(k) + 1, N}); ++s) {







E[i][j][k][l][s][t] += E[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int l = max({i, 0}); l < N; ++l) {

for (int j = 0; j < N; ++j) {

for (int t = max({j, 0}); t < min({(i) + 1, N}); ++t) {

for (int k = 0; k < min({(j) + 1, N}); ++k) {

for (int s = 0; s < min({(k) + 1, N}); ++s) {







E[i][j][k][l][s][t] += E[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int l = max({i, 0}); l < N; ++l) {

for (int j = 0; j < min({(i) + 1, N}); ++j) {

for (int t = max({l, 0}); t < N; ++t) {

for (int k = 0; k < min({(j) + 1, N}); ++k) {

for (int s = 0; s < min({(k) + 1, N}); ++s) {







E[i][j][k][l][s][t] += E[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int j = 0; j < min({(i) + 1, N}); ++j) {

for (int k = 0; k < min({(j) + 1, N}); ++k) {

for (int s = 0; s < min({(k) + 1, N}); ++s) {

for (int l = 0; l < N; ++l) {

for (int t = max({i, 0}); t < min({(l) + 1, N}); ++t) {







E[i][j][k][l][s][t] += E[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int j = 0; j < N; ++j) {

for (int t = max({j, 0}); t < min({(i) + 1, N}); ++t) {

for (int k = 0; k < N; ++k) {

for (int s = 0; s < min({(k) + 1, N}); ++s) {

for (int l = max({k, 0}); l < min({(j) + 1, N}); ++l) {







E[i][j][k][l][s][t] += E[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int t = max({i, 0}); t < N; ++t) {

for (int j = 0; j < min({(i) + 1, N}); ++j) {

for (int k = 0; k < N; ++k) {

for (int s = 0; s < min({(k) + 1, N}); ++s) {

for (int l = max({k, 0}); l < min({(j) + 1, N}); ++l) {







E[i][j][k][l][s][t] += E[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int j = 0; j < min({(i) + 1, N}); ++j) {

for (int k = 0; k < N; ++k) {

for (int s = 0; s < min({(k) + 1, N}); ++s) {

for (int l = max({k, 0}); l < N; ++l) {

for (int t = max({l, 0}); t < min({(j) + 1, N}); ++t) {







E[i][j][k][l][s][t] += E[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int j = max({i, 0}); j < N; ++j) {

for (int k = 0; k < N; ++k) {

for (int s = 0; s < min({(k) + 1, N}); ++s) {

for (int l = max({k, 0}); l < N; ++l) {

for (int t = max({l, 0}); t < min({(i) + 1, N}); ++t) {







E[i][j][k][l][s][t] += E[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int j = max({i, 0}); j < N; ++j) {

for (int t = max({j, 0}); t < N; ++t) {

for (int k = 0; k < N; ++k) {

for (int s = 0; s < min({(k) + 1, N}); ++s) {

for (int l = max({k, 0}); l < min({(i) + 1, N}); ++l) {







E[i][j][k][l][s][t] += E[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int j = 0; j < N; ++j) {

for (int t = max({i, 0}); t < min({(j) + 1, N}); ++t) {

for (int k = 0; k < N; ++k) {

for (int s = 0; s < min({(k) + 1, N}); ++s) {

for (int l = max({k, 0}); l < min({(i) + 1, N}); ++l) {







E[i][j][k][l][s][t] += E[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int j = 0; j < N; ++j) {

for (int l = max({j, 0}); l < min({(i) + 1, N}); ++l) {

for (int k = 0; k < N; ++k) {

for (int s = 0; s < min({(k) + 1, N}); ++s) {

for (int t = max({k, 0}); t < min({(j) + 1, N}); ++t) {







E[i][j][k][l][s][t] += E[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int l = max({i, 0}); l < N; ++l) {

for (int j = 0; j < min({(i) + 1, N}); ++j) {

for (int k = 0; k < N; ++k) {

for (int s = 0; s < min({(k) + 1, N}); ++s) {

for (int t = max({k, 0}); t < min({(j) + 1, N}); ++t) {







E[i][j][k][l][s][t] += E[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int j = 0; j < min({(i) + 1, N}); ++j) {

for (int l = 0; l < min({(j) + 1, N}); ++l) {

for (int k = 0; k < N; ++k) {

for (int s = 0; s < min({(k) + 1, N}); ++s) {

for (int t = max({k, 0}); t < min({(l) + 1, N}); ++t) {







E[i][j][k][l][s][t] += E[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int l = 0; l < min({(i) + 1, N}); ++l) {

for (int j = max({i, 0}); j < N; ++j) {

for (int k = 0; k < N; ++k) {

for (int s = 0; s < min({(k) + 1, N}); ++s) {

for (int t = max({k, 0}); t < min({(l) + 1, N}); ++t) {







E[i][j][k][l][s][t] += E[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int j = max({i, 0}); j < N; ++j) {

for (int l = max({j, 0}); l < N; ++l) {

for (int k = 0; k < N; ++k) {

for (int s = 0; s < min({(k) + 1, N}); ++s) {

for (int t = max({k, 0}); t < min({(i) + 1, N}); ++t) {







E[i][j][k][l][s][t] += E[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int j = 0; j < N; ++j) {

for (int l = max({i, 0}); l < min({(j) + 1, N}); ++l) {

for (int k = 0; k < N; ++k) {

for (int s = 0; s < min({(k) + 1, N}); ++s) {

for (int t = max({k, 0}); t < min({(i) + 1, N}); ++t) {







E[i][j][k][l][s][t] += E[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int j = max({i, 0}); j < N; ++j) {

for (int k = 0; k < min({(i) + 1, N}); ++k) {

for (int l = max({j, 0}); l < N; ++l) {

for (int s = 0; s < min({(k) + 1, N}); ++s) {

for (int t = max({l, 0}); t < N; ++t) {







E[i][j][k][l][s][t] += E[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int j = max({i, 0}); j < N; ++j) {

for (int k = 0; k < min({(i) + 1, N}); ++k) {

for (int s = 0; s < min({(k) + 1, N}); ++s) {

for (int l = 0; l < N; ++l) {

for (int t = max({j, 0}); t < min({(l) + 1, N}); ++t) {







E[i][j][k][l][s][t] += E[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int j = 0; j < N; ++j) {

for (int k = 0; k < min({(i) + 1, N}); ++k) {

for (int t = max({j, 0}); t < N; ++t) {

for (int l = max({i, 0}); l < min({(j) + 1, N}); ++l) {

for (int s = 0; s < min({(k) + 1, N}); ++s) {







E[i][j][k][l][s][t] += E[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int l = max({i, 0}); l < N; ++l) {

for (int k = 0; k < min({(i) + 1, N}); ++k) {

for (int s = 0; s < min({(k) + 1, N}); ++s) {

for (int j = 0; j < N; ++j) {

for (int t = max({l, 0}); t < min({(j) + 1, N}); ++t) {







E[i][j][k][l][s][t] += E[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int j = 0; j < N; ++j) {

for (int k = 0; k < min({(i) + 1, N}); ++k) {

for (int t = max({i, 0}); t < min({(j) + 1, N}); ++t) {

for (int l = max({j, 0}); l < N; ++l) {

for (int s = 0; s < min({(k) + 1, N}); ++s) {







E[i][j][k][l][s][t] += E[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int j = 0; j < N; ++j) {

for (int k = 0; k < min({(i) + 1, N}); ++k) {

for (int l = 0; l < min({(j) + 1, N}); ++l) {

for (int s = 0; s < min({(k) + 1, N}); ++s) {

for (int t = max({i, 0}); t < min({(l) + 1, N}); ++t) {







E[i][j][k][l][s][t] += E[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int j = 0; j < N; ++j) {

for (int l = 0; l < min({(j) + 1, N}); ++l) {

for (int k = max({j, 0}); k < N; ++k) {

for (int s = 0; s < min({(l) + 1, N}); ++s) {

for (int t = max({k, 0}); t < min({(i) + 1, N}); ++t) {







E[i][j][k][l][s][t] += E[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int t = max({i, 0}); t < N; ++t) {

for (int j = 0; j < N; ++j) {

for (int l = 0; l < min({(j) + 1, N}); ++l) {

for (int k = max({j, 0}); k < min({(i) + 1, N}); ++k) {

for (int s = 0; s < min({(l) + 1, N}); ++s) {







E[i][j][k][l][s][t] += E[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int j = 0; j < N; ++j) {

for (int k = 0; k < min({(i) + 1, N}); ++k) {

for (int l = 0; l < min({(j) + 1, N}); ++l) {

for (int t = max({j, 0}); t < min({(k) + 1, N}); ++t) {

for (int s = 0; s < min({(l) + 1, N}); ++s) {







E[i][j][k][l][s][t] += E[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int j = 0; j < N; ++j) {

for (int k = max({i, 0}); k < N; ++k) {

for (int t = max({j, 0}); t < min({(i) + 1, N}); ++t) {

for (int l = 0; l < min({(j) + 1, N}); ++l) {

for (int s = 0; s < min({(l) + 1, N}); ++s) {







E[i][j][k][l][s][t] += E[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int j = 0; j < min({(i) + 1, N}); ++j) {

for (int k = max({i, 0}); k < N; ++k) {

for (int l = 0; l < min({(j) + 1, N}); ++l) {

for (int t = max({k, 0}); t < N; ++t) {

for (int s = 0; s < min({(l) + 1, N}); ++s) {







E[i][j][k][l][s][t] += E[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int j = 0; j < min({(i) + 1, N}); ++j) {

for (int l = 0; l < min({(j) + 1, N}); ++l) {

for (int s = 0; s < min({(l) + 1, N}); ++s) {

for (int k = 0; k < N; ++k) {

for (int t = max({i, 0}); t < min({(k) + 1, N}); ++t) {







E[i][j][k][l][s][t] += E[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int j = 0; j < N; ++j) {

for (int t = max({j, 0}); t < min({(i) + 1, N}); ++t) {

for (int k = 0; k < min({(j) + 1, N}); ++k) {

for (int l = 0; l < min({(k) + 1, N}); ++l) {

for (int s = 0; s < min({(l) + 1, N}); ++s) {







E[i][j][k][l][s][t] += E[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int t = max({i, 0}); t < N; ++t) {

for (int j = 0; j < min({(i) + 1, N}); ++j) {

for (int k = 0; k < min({(j) + 1, N}); ++k) {

for (int l = 0; l < min({(k) + 1, N}); ++l) {

for (int s = 0; s < min({(l) + 1, N}); ++s) {







E[i][j][k][l][s][t] += E[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int j = 0; j < min({(i) + 1, N}); ++j) {

for (int k = 0; k < N; ++k) {

for (int t = max({k, 0}); t < min({(j) + 1, N}); ++t) {

for (int l = 0; l < min({(k) + 1, N}); ++l) {

for (int s = 0; s < min({(l) + 1, N}); ++s) {







E[i][j][k][l][s][t] += E[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int j = max({i, 0}); j < N; ++j) {

for (int k = 0; k < N; ++k) {

for (int t = max({k, 0}); t < min({(i) + 1, N}); ++t) {

for (int l = 0; l < min({(k) + 1, N}); ++l) {

for (int s = 0; s < min({(l) + 1, N}); ++s) {







E[i][j][k][l][s][t] += E[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int j = max({i, 0}); j < N; ++j) {

for (int k = 0; k < min({(i) + 1, N}); ++k) {

for (int t = max({j, 0}); t < N; ++t) {

for (int l = 0; l < min({(k) + 1, N}); ++l) {

for (int s = 0; s < min({(l) + 1, N}); ++s) {







E[i][j][k][l][s][t] += E[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int j = 0; j < N; ++j) {

for (int k = 0; k < min({(i) + 1, N}); ++k) {

for (int t = max({i, 0}); t < min({(j) + 1, N}); ++t) {

for (int l = 0; l < min({(k) + 1, N}); ++l) {

for (int s = 0; s < min({(l) + 1, N}); ++s) {







E[i][j][k][l][s][t] += E[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int j = 0; j < N; ++j) {

for (int k = max({j, 0}); k < min({(i) + 1, N}); ++k) {

for (int l = 0; l < N; ++l) {

for (int s = 0; s < min({(l) + 1, N}); ++s) {

for (int t = max({l, 0}); t < min({(j) + 1, N}); ++t) {







E[i][j][k][l][s][t] += E[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int j = 0; j < min({(i) + 1, N}); ++j) {

for (int k = max({i, 0}); k < N; ++k) {

for (int l = 0; l < N; ++l) {

for (int s = 0; s < min({(l) + 1, N}); ++s) {

for (int t = max({l, 0}); t < min({(j) + 1, N}); ++t) {







E[i][j][k][l][s][t] += E[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int j = 0; j < min({(i) + 1, N}); ++j) {

for (int k = 0; k < min({(j) + 1, N}); ++k) {

for (int l = 0; l < N; ++l) {

for (int s = 0; s < min({(l) + 1, N}); ++s) {

for (int t = max({l, 0}); t < min({(k) + 1, N}); ++t) {







E[i][j][k][l][s][t] += E[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int j = max({i, 0}); j < N; ++j) {

for (int k = 0; k < min({(i) + 1, N}); ++k) {

for (int l = 0; l < N; ++l) {

for (int s = 0; s < min({(l) + 1, N}); ++s) {

for (int t = max({l, 0}); t < min({(k) + 1, N}); ++t) {







E[i][j][k][l][s][t] += E[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int j = max({i, 0}); j < N; ++j) {

for (int k = max({j, 0}); k < N; ++k) {

for (int l = 0; l < N; ++l) {

for (int s = 0; s < min({(l) + 1, N}); ++s) {

for (int t = max({l, 0}); t < min({(i) + 1, N}); ++t) {







E[i][j][k][l][s][t] += E[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int j = 0; j < N; ++j) {

for (int k = max({i, 0}); k < min({(j) + 1, N}); ++k) {

for (int l = 0; l < N; ++l) {

for (int s = 0; s < min({(l) + 1, N}); ++s) {

for (int t = max({l, 0}); t < min({(i) + 1, N}); ++t) {







E[i][j][k][l][s][t] += E[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int l = 0; l < min({(i) + 1, N}); ++l) {

for (int j = max({i, 0}); j < N; ++j) {

for (int s = 0; s < min({(l) + 1, N}); ++s) {

for (int k = max({j, 0}); k < N; ++k) {

for (int t = max({k, 0}); t < N; ++t) {







E[i][j][k][l][s][t] += E[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int l = 0; l < min({(i) + 1, N}); ++l) {

for (int j = max({i, 0}); j < N; ++j) {

for (int s = 0; s < min({(l) + 1, N}); ++s) {

for (int k = 0; k < N; ++k) {

for (int t = max({j, 0}); t < min({(k) + 1, N}); ++t) {







E[i][j][k][l][s][t] += E[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int l = 0; l < min({(i) + 1, N}); ++l) {

for (int s = 0; s < min({(l) + 1, N}); ++s) {

for (int j = 0; j < N; ++j) {

for (int t = max({j, 0}); t < N; ++t) {

for (int k = max({i, 0}); k < min({(j) + 1, N}); ++k) {







E[i][j][k][l][s][t] += E[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int l = 0; l < min({(i) + 1, N}); ++l) {

for (int k = max({i, 0}); k < N; ++k) {

for (int s = 0; s < min({(l) + 1, N}); ++s) {

for (int j = 0; j < N; ++j) {

for (int t = max({k, 0}); t < min({(j) + 1, N}); ++t) {







E[i][j][k][l][s][t] += E[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int l = 0; l < min({(i) + 1, N}); ++l) {

for (int s = 0; s < min({(l) + 1, N}); ++s) {

for (int j = 0; j < N; ++j) {

for (int t = max({i, 0}); t < min({(j) + 1, N}); ++t) {

for (int k = max({j, 0}); k < N; ++k) {







E[i][j][k][l][s][t] += E[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int l = 0; l < min({(i) + 1, N}); ++l) {

for (int s = 0; s < min({(l) + 1, N}); ++s) {

for (int j = 0; j < N; ++j) {

for (int k = 0; k < min({(j) + 1, N}); ++k) {

for (int t = max({i, 0}); t < min({(k) + 1, N}); ++t) {







E[i][j][k][l][s][t] += E[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int j = 0; j < N; ++j) {

for (int k = max({j, 0}); k < N; ++k) {

for (int l = max({k, 0}); l < min({(i) + 1, N}); ++l) {

for (int s = 0; s < N; ++s) {

for (int t = max({s, 0}); t < min({(j) + 1, N}); ++t) {







E[i][j][k][l][s][t] += E[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int l = max({i, 0}); l < N; ++l) {

for (int j = 0; j < N; ++j) {

for (int k = max({j, 0}); k < min({(i) + 1, N}); ++k) {

for (int s = 0; s < N; ++s) {

for (int t = max({s, 0}); t < min({(j) + 1, N}); ++t) {







E[i][j][k][l][s][t] += E[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int j = 0; j < N; ++j) {

for (int k = 0; k < min({(i) + 1, N}); ++k) {

for (int l = max({j, 0}); l < min({(k) + 1, N}); ++l) {

for (int s = 0; s < N; ++s) {

for (int t = max({s, 0}); t < min({(j) + 1, N}); ++t) {







E[i][j][k][l][s][t] += E[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int j = 0; j < N; ++j) {

for (int k = max({i, 0}); k < N; ++k) {

for (int l = max({j, 0}); l < min({(i) + 1, N}); ++l) {

for (int s = 0; s < N; ++s) {

for (int t = max({s, 0}); t < min({(j) + 1, N}); ++t) {







E[i][j][k][l][s][t] += E[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int j = 0; j < min({(i) + 1, N}); ++j) {

for (int k = max({i, 0}); k < N; ++k) {

for (int l = max({k, 0}); l < N; ++l) {

for (int s = 0; s < N; ++s) {

for (int t = max({s, 0}); t < min({(j) + 1, N}); ++t) {







E[i][j][k][l][s][t] += E[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int j = 0; j < min({(i) + 1, N}); ++j) {

for (int k = 0; k < N; ++k) {

for (int l = max({i, 0}); l < min({(k) + 1, N}); ++l) {

for (int s = 0; s < N; ++s) {

for (int t = max({s, 0}); t < min({(j) + 1, N}); ++t) {







E[i][j][k][l][s][t] += E[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int j = 0; j < N; ++j) {

for (int l = max({j, 0}); l < min({(i) + 1, N}); ++l) {

for (int k = 0; k < min({(j) + 1, N}); ++k) {

for (int s = 0; s < N; ++s) {

for (int t = max({s, 0}); t < min({(k) + 1, N}); ++t) {







E[i][j][k][l][s][t] += E[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int l = max({i, 0}); l < N; ++l) {

for (int j = 0; j < min({(i) + 1, N}); ++j) {

for (int k = 0; k < min({(j) + 1, N}); ++k) {

for (int s = 0; s < N; ++s) {

for (int t = max({s, 0}); t < min({(k) + 1, N}); ++t) {







E[i][j][k][l][s][t] += E[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int j = 0; j < min({(i) + 1, N}); ++j) {

for (int k = 0; k < N; ++k) {

for (int l = max({k, 0}); l < min({(j) + 1, N}); ++l) {

for (int s = 0; s < N; ++s) {

for (int t = max({s, 0}); t < min({(k) + 1, N}); ++t) {







E[i][j][k][l][s][t] += E[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int j = max({i, 0}); j < N; ++j) {

for (int k = 0; k < N; ++k) {

for (int l = max({k, 0}); l < min({(i) + 1, N}); ++l) {

for (int s = 0; s < N; ++s) {

for (int t = max({s, 0}); t < min({(k) + 1, N}); ++t) {







E[i][j][k][l][s][t] += E[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int j = max({i, 0}); j < N; ++j) {

for (int k = 0; k < min({(i) + 1, N}); ++k) {

for (int l = max({j, 0}); l < N; ++l) {

for (int s = 0; s < N; ++s) {

for (int t = max({s, 0}); t < min({(k) + 1, N}); ++t) {







E[i][j][k][l][s][t] += E[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int j = 0; j < N; ++j) {

for (int k = 0; k < min({(i) + 1, N}); ++k) {

for (int l = max({i, 0}); l < min({(j) + 1, N}); ++l) {

for (int s = 0; s < N; ++s) {

for (int t = max({s, 0}); t < min({(k) + 1, N}); ++t) {







E[i][j][k][l][s][t] += E[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int j = 0; j < N; ++j) {

for (int l = 0; l < min({(j) + 1, N}); ++l) {

for (int k = max({j, 0}); k < min({(i) + 1, N}); ++k) {

for (int s = 0; s < N; ++s) {

for (int t = max({s, 0}); t < min({(l) + 1, N}); ++t) {







E[i][j][k][l][s][t] += E[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int j = 0; j < min({(i) + 1, N}); ++j) {

for (int k = max({i, 0}); k < N; ++k) {

for (int l = 0; l < min({(j) + 1, N}); ++l) {

for (int s = 0; s < N; ++s) {

for (int t = max({s, 0}); t < min({(l) + 1, N}); ++t) {







E[i][j][k][l][s][t] += E[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int j = 0; j < min({(i) + 1, N}); ++j) {

for (int k = 0; k < min({(j) + 1, N}); ++k) {

for (int l = 0; l < min({(k) + 1, N}); ++l) {

for (int s = 0; s < N; ++s) {

for (int t = max({s, 0}); t < min({(l) + 1, N}); ++t) {







E[i][j][k][l][s][t] += E[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int j = max({i, 0}); j < N; ++j) {

for (int k = 0; k < min({(i) + 1, N}); ++k) {

for (int l = 0; l < min({(k) + 1, N}); ++l) {

for (int s = 0; s < N; ++s) {

for (int t = max({s, 0}); t < min({(l) + 1, N}); ++t) {







E[i][j][k][l][s][t] += E[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int l = 0; l < min({(i) + 1, N}); ++l) {

for (int j = max({i, 0}); j < N; ++j) {

for (int k = max({j, 0}); k < N; ++k) {

for (int s = 0; s < N; ++s) {

for (int t = max({s, 0}); t < min({(l) + 1, N}); ++t) {







E[i][j][k][l][s][t] += E[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int l = 0; l < min({(i) + 1, N}); ++l) {

for (int j = 0; j < N; ++j) {

for (int k = max({i, 0}); k < min({(j) + 1, N}); ++k) {

for (int s = 0; s < N; ++s) {

for (int t = max({s, 0}); t < min({(l) + 1, N}); ++t) {







E[i][j][k][l][s][t] += E[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int j = max({i, 0}); j < N; ++j) {

for (int k = max({j, 0}); k < N; ++k) {

for (int l = max({k, 0}); l < N; ++l) {

for (int s = 0; s < N; ++s) {

for (int t = max({s, 0}); t < min({(i) + 1, N}); ++t) {







E[i][j][k][l][s][t] += E[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int j = max({i, 0}); j < N; ++j) {

for (int k = 0; k < N; ++k) {

for (int l = max({j, 0}); l < min({(k) + 1, N}); ++l) {

for (int s = 0; s < N; ++s) {

for (int t = max({s, 0}); t < min({(i) + 1, N}); ++t) {







E[i][j][k][l][s][t] += E[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int j = 0; j < N; ++j) {

for (int l = max({j, 0}); l < N; ++l) {

for (int k = max({i, 0}); k < min({(j) + 1, N}); ++k) {

for (int s = 0; s < N; ++s) {

for (int t = max({s, 0}); t < min({(i) + 1, N}); ++t) {







E[i][j][k][l][s][t] += E[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int j = 0; j < N; ++j) {

for (int k = max({i, 0}); k < N; ++k) {

for (int l = max({k, 0}); l < min({(j) + 1, N}); ++l) {

for (int s = 0; s < N; ++s) {

for (int t = max({s, 0}); t < min({(i) + 1, N}); ++t) {







E[i][j][k][l][s][t] += E[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int j = 0; j < N; ++j) {

for (int l = max({i, 0}); l < min({(j) + 1, N}); ++l) {

for (int k = max({j, 0}); k < N; ++k) {

for (int s = 0; s < N; ++s) {

for (int t = max({s, 0}); t < min({(i) + 1, N}); ++t) {







E[i][j][k][l][s][t] += E[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int j = 0; j < N; ++j) {

for (int k = 0; k < min({(j) + 1, N}); ++k) {

for (int l = max({i, 0}); l < min({(k) + 1, N}); ++l) {

for (int s = 0; s < N; ++s) {

for (int t = max({s, 0}); t < min({(i) + 1, N}); ++t) {







E[i][j][k][l][s][t] += E[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int s = 0; s < min({(i) + 1, N}); ++s) {

for (int j = max({i, 0}); j < N; ++j) {

for (int k = max({j, 0}); k < N; ++k) {

for (int l = max({k, 0}); l < N; ++l) {

for (int t = max({l, 0}); t < N; ++t) {







E[i][j][k][l][s][t] += E[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int s = 0; s < min({(i) + 1, N}); ++s) {

for (int j = max({i, 0}); j < N; ++j) {

for (int k = max({j, 0}); k < N; ++k) {

for (int l = 0; l < N; ++l) {

for (int t = max({k, 0}); t < min({(l) + 1, N}); ++t) {







E[i][j][k][l][s][t] += E[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int s = 0; s < min({(i) + 1, N}); ++s) {

for (int j = max({i, 0}); j < N; ++j) {

for (int k = 0; k < N; ++k) {

for (int t = max({k, 0}); t < N; ++t) {

for (int l = max({j, 0}); l < min({(k) + 1, N}); ++l) {







E[i][j][k][l][s][t] += E[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int s = 0; s < min({(i) + 1, N}); ++s) {

for (int j = max({i, 0}); j < N; ++j) {

for (int l = max({j, 0}); l < N; ++l) {

for (int k = 0; k < N; ++k) {

for (int t = max({l, 0}); t < min({(k) + 1, N}); ++t) {







E[i][j][k][l][s][t] += E[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int s = 0; s < min({(i) + 1, N}); ++s) {

for (int j = max({i, 0}); j < N; ++j) {

for (int k = 0; k < N; ++k) {

for (int t = max({j, 0}); t < min({(k) + 1, N}); ++t) {

for (int l = max({k, 0}); l < N; ++l) {







E[i][j][k][l][s][t] += E[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int s = 0; s < min({(i) + 1, N}); ++s) {

for (int j = max({i, 0}); j < N; ++j) {

for (int k = 0; k < N; ++k) {

for (int l = 0; l < min({(k) + 1, N}); ++l) {

for (int t = max({j, 0}); t < min({(l) + 1, N}); ++t) {







E[i][j][k][l][s][t] += E[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int s = 0; s < min({(i) + 1, N}); ++s) {

for (int j = 0; j < N; ++j) {

for (int l = max({j, 0}); l < N; ++l) {

for (int k = max({i, 0}); k < min({(j) + 1, N}); ++k) {

for (int t = max({l, 0}); t < N; ++t) {







E[i][j][k][l][s][t] += E[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int s = 0; s < min({(i) + 1, N}); ++s) {

for (int j = 0; j < N; ++j) {

for (int k = max({i, 0}); k < min({(j) + 1, N}); ++k) {

for (int l = 0; l < N; ++l) {

for (int t = max({j, 0}); t < min({(l) + 1, N}); ++t) {







E[i][j][k][l][s][t] += E[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int s = 0; s < min({(i) + 1, N}); ++s) {

for (int k = max({i, 0}); k < N; ++k) {

for (int j = 0; j < N; ++j) {

for (int t = max({j, 0}); t < N; ++t) {

for (int l = max({k, 0}); l < min({(j) + 1, N}); ++l) {







E[i][j][k][l][s][t] += E[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int s = 0; s < min({(i) + 1, N}); ++s) {

for (int k = max({i, 0}); k < N; ++k) {

for (int l = max({k, 0}); l < N; ++l) {

for (int j = 0; j < N; ++j) {

for (int t = max({l, 0}); t < min({(j) + 1, N}); ++t) {







E[i][j][k][l][s][t] += E[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int s = 0; s < min({(i) + 1, N}); ++s) {

for (int k = max({i, 0}); k < N; ++k) {

for (int j = 0; j < N; ++j) {

for (int t = max({k, 0}); t < min({(j) + 1, N}); ++t) {

for (int l = max({j, 0}); l < N; ++l) {







E[i][j][k][l][s][t] += E[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int s = 0; s < min({(i) + 1, N}); ++s) {

for (int k = max({i, 0}); k < N; ++k) {

for (int j = 0; j < N; ++j) {

for (int l = 0; l < min({(j) + 1, N}); ++l) {

for (int t = max({k, 0}); t < min({(l) + 1, N}); ++t) {







E[i][j][k][l][s][t] += E[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int s = 0; s < min({(i) + 1, N}); ++s) {

for (int j = 0; j < N; ++j) {

for (int l = max({i, 0}); l < min({(j) + 1, N}); ++l) {

for (int k = max({j, 0}); k < N; ++k) {

for (int t = max({k, 0}); t < N; ++t) {







E[i][j][k][l][s][t] += E[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int s = 0; s < min({(i) + 1, N}); ++s) {

for (int j = 0; j < N; ++j) {

for (int l = max({i, 0}); l < min({(j) + 1, N}); ++l) {

for (int k = 0; k < N; ++k) {

for (int t = max({j, 0}); t < min({(k) + 1, N}); ++t) {







E[i][j][k][l][s][t] += E[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int s = 0; s < min({(i) + 1, N}); ++s) {

for (int j = 0; j < N; ++j) {

for (int t = max({j, 0}); t < N; ++t) {

for (int k = 0; k < min({(j) + 1, N}); ++k) {

for (int l = max({i, 0}); l < min({(k) + 1, N}); ++l) {







E[i][j][k][l][s][t] += E[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int s = 0; s < min({(i) + 1, N}); ++s) {

for (int j = 0; j < N; ++j) {

for (int k = 0; k < N; ++k) {

for (int t = max({k, 0}); t < min({(j) + 1, N}); ++t) {

for (int l = max({i, 0}); l < min({(k) + 1, N}); ++l) {







E[i][j][k][l][s][t] += E[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int s = 0; s < min({(i) + 1, N}); ++s) {

for (int l = max({i, 0}); l < N; ++l) {

for (int j = 0; j < N; ++j) {

for (int t = max({l, 0}); t < min({(j) + 1, N}); ++t) {

for (int k = max({j, 0}); k < N; ++k) {







E[i][j][k][l][s][t] += E[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int s = 0; s < min({(i) + 1, N}); ++s) {

for (int l = max({i, 0}); l < N; ++l) {

for (int j = 0; j < N; ++j) {

for (int k = 0; k < min({(j) + 1, N}); ++k) {

for (int t = max({l, 0}); t < min({(k) + 1, N}); ++t) {







E[i][j][k][l][s][t] += E[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int s = 0; s < min({(i) + 1, N}); ++s) {

for (int j = 0; j < N; ++j) {

for (int t = max({i, 0}); t < min({(j) + 1, N}); ++t) {

for (int k = max({j, 0}); k < N; ++k) {

for (int l = max({k, 0}); l < N; ++l) {







E[i][j][k][l][s][t] += E[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int s = 0; s < min({(i) + 1, N}); ++s) {

for (int j = 0; j < N; ++j) {

for (int t = max({i, 0}); t < min({(j) + 1, N}); ++t) {

for (int k = 0; k < N; ++k) {

for (int l = max({j, 0}); l < min({(k) + 1, N}); ++l) {







E[i][j][k][l][s][t] += E[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int s = 0; s < min({(i) + 1, N}); ++s) {

for (int j = 0; j < N; ++j) {

for (int l = max({j, 0}); l < N; ++l) {

for (int k = 0; k < min({(j) + 1, N}); ++k) {

for (int t = max({i, 0}); t < min({(k) + 1, N}); ++t) {







E[i][j][k][l][s][t] += E[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int s = 0; s < min({(i) + 1, N}); ++s) {

for (int j = 0; j < N; ++j) {

for (int k = 0; k < N; ++k) {

for (int t = max({i, 0}); t < min({(k) + 1, N}); ++t) {

for (int l = max({k, 0}); l < min({(j) + 1, N}); ++l) {







E[i][j][k][l][s][t] += E[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int s = 0; s < min({(i) + 1, N}); ++s) {

for (int j = 0; j < N; ++j) {

for (int l = 0; l < min({(j) + 1, N}); ++l) {

for (int k = max({j, 0}); k < N; ++k) {

for (int t = max({i, 0}); t < min({(l) + 1, N}); ++t) {







E[i][j][k][l][s][t] += E[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int s = 0; s < min({(i) + 1, N}); ++s) {

for (int j = 0; j < N; ++j) {

for (int k = 0; k < min({(j) + 1, N}); ++k) {

for (int l = 0; l < min({(k) + 1, N}); ++l) {

for (int t = max({i, 0}); t < min({(l) + 1, N}); ++t) {







E[i][j][k][l][s][t] += E[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int j = 0; j < N; ++j) {

for (int t = 0; t < min({(j) + 1, N}); ++t) {

for (int k = max({j, 0}); k < N; ++k) {

for (int l = max({k, 0}); l < N; ++l) {

for (int s = max({l, 0}); s < min({(i) + 1, N}); ++s) {







E[i][j][k][l][s][t] += E[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int s = max({i, 0}); s < N; ++s) {

for (int j = 0; j < N; ++j) {

for (int t = 0; t < min({(j) + 1, N}); ++t) {

for (int k = max({j, 0}); k < N; ++k) {

for (int l = max({k, 0}); l < min({(i) + 1, N}); ++l) {







E[i][j][k][l][s][t] += E[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int l = 0; l < min({(i) + 1, N}); ++l) {

for (int j = 0; j < N; ++j) {

for (int t = 0; t < min({(j) + 1, N}); ++t) {

for (int k = max({j, 0}); k < N; ++k) {

for (int s = max({k, 0}); s < min({(l) + 1, N}); ++s) {







E[i][j][k][l][s][t] += E[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int l = max({i, 0}); l < N; ++l) {

for (int j = 0; j < N; ++j) {

for (int t = 0; t < min({(j) + 1, N}); ++t) {

for (int k = max({j, 0}); k < N; ++k) {

for (int s = max({k, 0}); s < min({(i) + 1, N}); ++s) {







E[i][j][k][l][s][t] += E[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int l = max({i, 0}); l < N; ++l) {

for (int s = max({l, 0}); s < N; ++s) {

for (int j = 0; j < N; ++j) {

for (int t = 0; t < min({(j) + 1, N}); ++t) {

for (int k = max({j, 0}); k < min({(i) + 1, N}); ++k) {







E[i][j][k][l][s][t] += E[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int j = 0; j < N; ++j) {

for (int t = 0; t < min({(j) + 1, N}); ++t) {

for (int k = max({j, 0}); k < min({(i) + 1, N}); ++k) {

for (int l = 0; l < N; ++l) {

for (int s = max({i, 0}); s < min({(l) + 1, N}); ++s) {







E[i][j][k][l][s][t] += E[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int j = 0; j < N; ++j) {

for (int t = 0; t < min({(j) + 1, N}); ++t) {

for (int k = 0; k < N; ++k) {

for (int s = max({k, 0}); s < min({(i) + 1, N}); ++s) {

for (int l = max({j, 0}); l < min({(k) + 1, N}); ++l) {







E[i][j][k][l][s][t] += E[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int s = max({i, 0}); s < N; ++s) {

for (int k = 0; k < min({(i) + 1, N}); ++k) {

for (int j = 0; j < N; ++j) {

for (int t = 0; t < min({(j) + 1, N}); ++t) {

for (int l = max({j, 0}); l < min({(k) + 1, N}); ++l) {







E[i][j][k][l][s][t] += E[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int j = 0; j < N; ++j) {

for (int k = 0; k < min({(i) + 1, N}); ++k) {

for (int t = 0; t < min({(j) + 1, N}); ++t) {

for (int l = max({j, 0}); l < N; ++l) {

for (int s = max({l, 0}); s < min({(k) + 1, N}); ++s) {







E[i][j][k][l][s][t] += E[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int j = 0; j < N; ++j) {

for (int k = max({i, 0}); k < N; ++k) {

for (int t = 0; t < min({(j) + 1, N}); ++t) {

for (int l = max({j, 0}); l < N; ++l) {

for (int s = max({l, 0}); s < min({(i) + 1, N}); ++s) {







E[i][j][k][l][s][t] += E[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int j = 0; j < N; ++j) {

for (int k = max({i, 0}); k < N; ++k) {

for (int t = 0; t < min({(j) + 1, N}); ++t) {

for (int l = max({j, 0}); l < min({(i) + 1, N}); ++l) {

for (int s = max({k, 0}); s < N; ++s) {







E[i][j][k][l][s][t] += E[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int j = 0; j < N; ++j) {

for (int t = 0; t < min({(j) + 1, N}); ++t) {

for (int l = max({j, 0}); l < min({(i) + 1, N}); ++l) {

for (int k = 0; k < N; ++k) {

for (int s = max({i, 0}); s < min({(k) + 1, N}); ++s) {







E[i][j][k][l][s][t] += E[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int j = 0; j < N; ++j) {

for (int t = 0; t < min({(j) + 1, N}); ++t) {

for (int k = 0; k < N; ++k) {

for (int s = max({j, 0}); s < min({(k) + 1, N}); ++s) {

for (int l = max({k, 0}); l < min({(i) + 1, N}); ++l) {







E[i][j][k][l][s][t] += E[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int l = max({i, 0}); l < N; ++l) {

for (int k = 0; k < min({(i) + 1, N}); ++k) {

for (int j = 0; j < N; ++j) {

for (int s = max({j, 0}); s < min({(k) + 1, N}); ++s) {

for (int t = 0; t < min({(j) + 1, N}); ++t) {







E[i][j][k][l][s][t] += E[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int j = 0; j < N; ++j) {

for (int k = 0; k < min({(i) + 1, N}); ++k) {

for (int t = 0; t < min({(j) + 1, N}); ++t) {

for (int l = 0; l < min({(k) + 1, N}); ++l) {

for (int s = max({j, 0}); s < min({(l) + 1, N}); ++s) {







E[i][j][k][l][s][t] += E[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int l = 0; l < min({(i) + 1, N}); ++l) {

for (int k = max({i, 0}); k < N; ++k) {

for (int j = 0; j < N; ++j) {

for (int s = max({j, 0}); s < min({(l) + 1, N}); ++s) {

for (int t = 0; t < min({(j) + 1, N}); ++t) {







E[i][j][k][l][s][t] += E[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int j = 0; j < N; ++j) {

for (int k = max({i, 0}); k < N; ++k) {

for (int s = max({j, 0}); s < min({(i) + 1, N}); ++s) {

for (int t = 0; t < min({(j) + 1, N}); ++t) {

for (int l = max({k, 0}); l < N; ++l) {







E[i][j][k][l][s][t] += E[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int j = 0; j < N; ++j) {

for (int s = max({j, 0}); s < min({(i) + 1, N}); ++s) {

for (int t = 0; t < min({(j) + 1, N}); ++t) {

for (int k = 0; k < N; ++k) {

for (int l = max({i, 0}); l < min({(k) + 1, N}); ++l) {







E[i][j][k][l][s][t] += E[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int j = 0; j < min({(i) + 1, N}); ++j) {

for (int k = max({i, 0}); k < N; ++k) {

for (int t = 0; t < min({(j) + 1, N}); ++t) {

for (int l = max({k, 0}); l < N; ++l) {

for (int s = max({l, 0}); s < N; ++s) {







E[i][j][k][l][s][t] += E[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int j = 0; j < min({(i) + 1, N}); ++j) {

for (int k = max({i, 0}); k < N; ++k) {

for (int t = 0; t < min({(j) + 1, N}); ++t) {

for (int l = 0; l < N; ++l) {

for (int s = max({k, 0}); s < min({(l) + 1, N}); ++s) {







E[i][j][k][l][s][t] += E[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int j = 0; j < min({(i) + 1, N}); ++j) {

for (int t = 0; t < min({(j) + 1, N}); ++t) {

for (int k = 0; k < N; ++k) {

for (int s = max({k, 0}); s < N; ++s) {

for (int l = max({i, 0}); l < min({(k) + 1, N}); ++l) {







E[i][j][k][l][s][t] += E[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int l = max({i, 0}); l < N; ++l) {

for (int j = 0; j < min({(i) + 1, N}); ++j) {

for (int t = 0; t < min({(j) + 1, N}); ++t) {

for (int k = 0; k < N; ++k) {

for (int s = max({l, 0}); s < min({(k) + 1, N}); ++s) {







E[i][j][k][l][s][t] += E[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int j = 0; j < min({(i) + 1, N}); ++j) {

for (int t = 0; t < min({(j) + 1, N}); ++t) {

for (int k = 0; k < N; ++k) {

for (int s = max({i, 0}); s < min({(k) + 1, N}); ++s) {

for (int l = max({k, 0}); l < N; ++l) {







E[i][j][k][l][s][t] += E[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int j = 0; j < min({(i) + 1, N}); ++j) {

for (int t = 0; t < min({(j) + 1, N}); ++t) {

for (int k = 0; k < N; ++k) {

for (int l = 0; l < min({(k) + 1, N}); ++l) {

for (int s = max({i, 0}); s < min({(l) + 1, N}); ++s) {







E[i][j][k][l][s][t] += E[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int j = 0; j < N; ++j) {

for (int l = max({j, 0}); l < N; ++l) {

for (int k = 0; k < min({(j) + 1, N}); ++k) {

for (int s = max({l, 0}); s < min({(i) + 1, N}); ++s) {

for (int t = 0; t < min({(k) + 1, N}); ++t) {







E[i][j][k][l][s][t] += E[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int s = max({i, 0}); s < N; ++s) {

for (int j = 0; j < N; ++j) {

for (int l = max({j, 0}); l < min({(i) + 1, N}); ++l) {

for (int k = 0; k < min({(j) + 1, N}); ++k) {

for (int t = 0; t < min({(k) + 1, N}); ++t) {







E[i][j][k][l][s][t] += E[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int l = 0; l < min({(i) + 1, N}); ++l) {

for (int j = 0; j < N; ++j) {

for (int s = max({j, 0}); s < min({(l) + 1, N}); ++s) {

for (int k = 0; k < min({(j) + 1, N}); ++k) {

for (int t = 0; t < min({(k) + 1, N}); ++t) {







E[i][j][k][l][s][t] += E[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int l = max({i, 0}); l < N; ++l) {

for (int j = 0; j < N; ++j) {

for (int s = max({j, 0}); s < min({(i) + 1, N}); ++s) {

for (int k = 0; k < min({(j) + 1, N}); ++k) {

for (int t = 0; t < min({(k) + 1, N}); ++t) {







E[i][j][k][l][s][t] += E[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int l = max({i, 0}); l < N; ++l) {

for (int j = 0; j < min({(i) + 1, N}); ++j) {

for (int s = max({l, 0}); s < N; ++s) {

for (int k = 0; k < min({(j) + 1, N}); ++k) {

for (int t = 0; t < min({(k) + 1, N}); ++t) {







E[i][j][k][l][s][t] += E[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int j = 0; j < min({(i) + 1, N}); ++j) {

for (int k = 0; k < min({(j) + 1, N}); ++k) {

for (int t = 0; t < min({(k) + 1, N}); ++t) {

for (int l = 0; l < N; ++l) {

for (int s = max({i, 0}); s < min({(l) + 1, N}); ++s) {







E[i][j][k][l][s][t] += E[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int j = 0; j < N; ++j) {

for (int s = max({j, 0}); s < min({(i) + 1, N}); ++s) {

for (int k = 0; k < N; ++k) {

for (int t = 0; t < min({(k) + 1, N}); ++t) {

for (int l = max({k, 0}); l < min({(j) + 1, N}); ++l) {







E[i][j][k][l][s][t] += E[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int s = max({i, 0}); s < N; ++s) {

for (int j = 0; j < min({(i) + 1, N}); ++j) {

for (int k = 0; k < N; ++k) {

for (int t = 0; t < min({(k) + 1, N}); ++t) {

for (int l = max({k, 0}); l < min({(j) + 1, N}); ++l) {







E[i][j][k][l][s][t] += E[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int j = 0; j < min({(i) + 1, N}); ++j) {

for (int k = 0; k < N; ++k) {

for (int t = 0; t < min({(k) + 1, N}); ++t) {

for (int l = max({k, 0}); l < N; ++l) {

for (int s = max({l, 0}); s < min({(j) + 1, N}); ++s) {







E[i][j][k][l][s][t] += E[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int j = max({i, 0}); j < N; ++j) {

for (int k = 0; k < N; ++k) {

for (int t = 0; t < min({(k) + 1, N}); ++t) {

for (int l = max({k, 0}); l < N; ++l) {

for (int s = max({l, 0}); s < min({(i) + 1, N}); ++s) {







E[i][j][k][l][s][t] += E[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int j = max({i, 0}); j < N; ++j) {

for (int s = max({j, 0}); s < N; ++s) {

for (int k = 0; k < N; ++k) {

for (int t = 0; t < min({(k) + 1, N}); ++t) {

for (int l = max({k, 0}); l < min({(i) + 1, N}); ++l) {







E[i][j][k][l][s][t] += E[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int j = 0; j < N; ++j) {

for (int s = max({i, 0}); s < min({(j) + 1, N}); ++s) {

for (int k = 0; k < N; ++k) {

for (int t = 0; t < min({(k) + 1, N}); ++t) {

for (int l = max({k, 0}); l < min({(i) + 1, N}); ++l) {







E[i][j][k][l][s][t] += E[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int j = 0; j < N; ++j) {

for (int l = max({j, 0}); l < min({(i) + 1, N}); ++l) {

for (int k = 0; k < N; ++k) {

for (int s = max({k, 0}); s < min({(j) + 1, N}); ++s) {

for (int t = 0; t < min({(k) + 1, N}); ++t) {







E[i][j][k][l][s][t] += E[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int l = max({i, 0}); l < N; ++l) {

for (int j = 0; j < min({(i) + 1, N}); ++j) {

for (int k = 0; k < N; ++k) {

for (int s = max({k, 0}); s < min({(j) + 1, N}); ++s) {

for (int t = 0; t < min({(k) + 1, N}); ++t) {







E[i][j][k][l][s][t] += E[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int j = 0; j < min({(i) + 1, N}); ++j) {

for (int l = 0; l < min({(j) + 1, N}); ++l) {

for (int k = 0; k < N; ++k) {

for (int s = max({k, 0}); s < min({(l) + 1, N}); ++s) {

for (int t = 0; t < min({(k) + 1, N}); ++t) {







E[i][j][k][l][s][t] += E[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int l = 0; l < min({(i) + 1, N}); ++l) {

for (int j = max({i, 0}); j < N; ++j) {

for (int k = 0; k < N; ++k) {

for (int s = max({k, 0}); s < min({(l) + 1, N}); ++s) {

for (int t = 0; t < min({(k) + 1, N}); ++t) {







E[i][j][k][l][s][t] += E[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int j = max({i, 0}); j < N; ++j) {

for (int l = max({j, 0}); l < N; ++l) {

for (int k = 0; k < N; ++k) {

for (int s = max({k, 0}); s < min({(i) + 1, N}); ++s) {

for (int t = 0; t < min({(k) + 1, N}); ++t) {







E[i][j][k][l][s][t] += E[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int j = 0; j < N; ++j) {

for (int l = max({i, 0}); l < min({(j) + 1, N}); ++l) {

for (int k = 0; k < N; ++k) {

for (int s = max({k, 0}); s < min({(i) + 1, N}); ++s) {

for (int t = 0; t < min({(k) + 1, N}); ++t) {







E[i][j][k][l][s][t] += E[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int j = max({i, 0}); j < N; ++j) {

for (int k = 0; k < min({(i) + 1, N}); ++k) {

for (int l = max({j, 0}); l < N; ++l) {

for (int t = 0; t < min({(k) + 1, N}); ++t) {

for (int s = max({l, 0}); s < N; ++s) {







E[i][j][k][l][s][t] += E[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int j = max({i, 0}); j < N; ++j) {

for (int k = 0; k < min({(i) + 1, N}); ++k) {

for (int t = 0; t < min({(k) + 1, N}); ++t) {

for (int l = 0; l < N; ++l) {

for (int s = max({j, 0}); s < min({(l) + 1, N}); ++s) {







E[i][j][k][l][s][t] += E[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int j = 0; j < N; ++j) {

for (int k = 0; k < min({(i) + 1, N}); ++k) {

for (int s = max({j, 0}); s < N; ++s) {

for (int l = max({i, 0}); l < min({(j) + 1, N}); ++l) {

for (int t = 0; t < min({(k) + 1, N}); ++t) {







E[i][j][k][l][s][t] += E[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int l = max({i, 0}); l < N; ++l) {

for (int k = 0; k < min({(i) + 1, N}); ++k) {

for (int t = 0; t < min({(k) + 1, N}); ++t) {

for (int j = 0; j < N; ++j) {

for (int s = max({l, 0}); s < min({(j) + 1, N}); ++s) {







E[i][j][k][l][s][t] += E[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int j = 0; j < N; ++j) {

for (int k = 0; k < min({(i) + 1, N}); ++k) {

for (int s = max({i, 0}); s < min({(j) + 1, N}); ++s) {

for (int l = max({j, 0}); l < N; ++l) {

for (int t = 0; t < min({(k) + 1, N}); ++t) {







E[i][j][k][l][s][t] += E[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int j = 0; j < N; ++j) {

for (int k = 0; k < min({(i) + 1, N}); ++k) {

for (int l = 0; l < min({(j) + 1, N}); ++l) {

for (int t = 0; t < min({(k) + 1, N}); ++t) {

for (int s = max({i, 0}); s < min({(l) + 1, N}); ++s) {







E[i][j][k][l][s][t] += E[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int j = 0; j < N; ++j) {

for (int l = 0; l < min({(j) + 1, N}); ++l) {

for (int k = max({j, 0}); k < N; ++k) {

for (int t = 0; t < min({(l) + 1, N}); ++t) {

for (int s = max({k, 0}); s < min({(i) + 1, N}); ++s) {







E[i][j][k][l][s][t] += E[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int s = max({i, 0}); s < N; ++s) {

for (int j = 0; j < N; ++j) {

for (int l = 0; l < min({(j) + 1, N}); ++l) {

for (int k = max({j, 0}); k < min({(i) + 1, N}); ++k) {

for (int t = 0; t < min({(l) + 1, N}); ++t) {







E[i][j][k][l][s][t] += E[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int j = 0; j < N; ++j) {

for (int k = 0; k < min({(i) + 1, N}); ++k) {

for (int l = 0; l < min({(j) + 1, N}); ++l) {

for (int s = max({j, 0}); s < min({(k) + 1, N}); ++s) {

for (int t = 0; t < min({(l) + 1, N}); ++t) {







E[i][j][k][l][s][t] += E[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int j = 0; j < N; ++j) {

for (int k = max({i, 0}); k < N; ++k) {

for (int s = max({j, 0}); s < min({(i) + 1, N}); ++s) {

for (int l = 0; l < min({(j) + 1, N}); ++l) {

for (int t = 0; t < min({(l) + 1, N}); ++t) {







E[i][j][k][l][s][t] += E[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int j = 0; j < min({(i) + 1, N}); ++j) {

for (int k = max({i, 0}); k < N; ++k) {

for (int l = 0; l < min({(j) + 1, N}); ++l) {

for (int s = max({k, 0}); s < N; ++s) {

for (int t = 0; t < min({(l) + 1, N}); ++t) {







E[i][j][k][l][s][t] += E[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int j = 0; j < min({(i) + 1, N}); ++j) {

for (int l = 0; l < min({(j) + 1, N}); ++l) {

for (int t = 0; t < min({(l) + 1, N}); ++t) {

for (int k = 0; k < N; ++k) {

for (int s = max({i, 0}); s < min({(k) + 1, N}); ++s) {







E[i][j][k][l][s][t] += E[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int j = 0; j < N; ++j) {

for (int s = max({j, 0}); s < min({(i) + 1, N}); ++s) {

for (int k = 0; k < min({(j) + 1, N}); ++k) {

for (int l = 0; l < min({(k) + 1, N}); ++l) {

for (int t = 0; t < min({(l) + 1, N}); ++t) {







E[i][j][k][l][s][t] += E[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int s = max({i, 0}); s < N; ++s) {

for (int j = 0; j < min({(i) + 1, N}); ++j) {

for (int k = 0; k < min({(j) + 1, N}); ++k) {

for (int l = 0; l < min({(k) + 1, N}); ++l) {

for (int t = 0; t < min({(l) + 1, N}); ++t) {







E[i][j][k][l][s][t] += E[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int j = 0; j < min({(i) + 1, N}); ++j) {

for (int k = 0; k < N; ++k) {

for (int s = max({k, 0}); s < min({(j) + 1, N}); ++s) {

for (int l = 0; l < min({(k) + 1, N}); ++l) {

for (int t = 0; t < min({(l) + 1, N}); ++t) {







E[i][j][k][l][s][t] += E[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int j = max({i, 0}); j < N; ++j) {

for (int k = 0; k < N; ++k) {

for (int s = max({k, 0}); s < min({(i) + 1, N}); ++s) {

for (int l = 0; l < min({(k) + 1, N}); ++l) {

for (int t = 0; t < min({(l) + 1, N}); ++t) {







E[i][j][k][l][s][t] += E[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int j = max({i, 0}); j < N; ++j) {

for (int k = 0; k < min({(i) + 1, N}); ++k) {

for (int s = max({j, 0}); s < N; ++s) {

for (int l = 0; l < min({(k) + 1, N}); ++l) {

for (int t = 0; t < min({(l) + 1, N}); ++t) {







E[i][j][k][l][s][t] += E[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int j = 0; j < N; ++j) {

for (int k = 0; k < min({(i) + 1, N}); ++k) {

for (int s = max({i, 0}); s < min({(j) + 1, N}); ++s) {

for (int l = 0; l < min({(k) + 1, N}); ++l) {

for (int t = 0; t < min({(l) + 1, N}); ++t) {







E[i][j][k][l][s][t] += E[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int j = 0; j < N; ++j) {

for (int k = max({j, 0}); k < min({(i) + 1, N}); ++k) {

for (int l = 0; l < N; ++l) {

for (int s = max({l, 0}); s < min({(j) + 1, N}); ++s) {

for (int t = 0; t < min({(l) + 1, N}); ++t) {







E[i][j][k][l][s][t] += E[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int j = 0; j < min({(i) + 1, N}); ++j) {

for (int k = max({i, 0}); k < N; ++k) {

for (int l = 0; l < N; ++l) {

for (int s = max({l, 0}); s < min({(j) + 1, N}); ++s) {

for (int t = 0; t < min({(l) + 1, N}); ++t) {







E[i][j][k][l][s][t] += E[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int j = 0; j < min({(i) + 1, N}); ++j) {

for (int k = 0; k < min({(j) + 1, N}); ++k) {

for (int l = 0; l < N; ++l) {

for (int s = max({l, 0}); s < min({(k) + 1, N}); ++s) {

for (int t = 0; t < min({(l) + 1, N}); ++t) {







E[i][j][k][l][s][t] += E[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int j = max({i, 0}); j < N; ++j) {

for (int k = 0; k < min({(i) + 1, N}); ++k) {

for (int l = 0; l < N; ++l) {

for (int s = max({l, 0}); s < min({(k) + 1, N}); ++s) {

for (int t = 0; t < min({(l) + 1, N}); ++t) {







E[i][j][k][l][s][t] += E[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int j = max({i, 0}); j < N; ++j) {

for (int k = max({j, 0}); k < N; ++k) {

for (int l = 0; l < N; ++l) {

for (int s = max({l, 0}); s < min({(i) + 1, N}); ++s) {

for (int t = 0; t < min({(l) + 1, N}); ++t) {







E[i][j][k][l][s][t] += E[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int j = 0; j < N; ++j) {

for (int k = max({i, 0}); k < min({(j) + 1, N}); ++k) {

for (int l = 0; l < N; ++l) {

for (int s = max({l, 0}); s < min({(i) + 1, N}); ++s) {

for (int t = 0; t < min({(l) + 1, N}); ++t) {







E[i][j][k][l][s][t] += E[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int l = 0; l < min({(i) + 1, N}); ++l) {

for (int j = max({i, 0}); j < N; ++j) {

for (int t = 0; t < min({(l) + 1, N}); ++t) {

for (int k = max({j, 0}); k < N; ++k) {

for (int s = max({k, 0}); s < N; ++s) {







E[i][j][k][l][s][t] += E[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int l = 0; l < min({(i) + 1, N}); ++l) {

for (int j = max({i, 0}); j < N; ++j) {

for (int t = 0; t < min({(l) + 1, N}); ++t) {

for (int k = 0; k < N; ++k) {

for (int s = max({j, 0}); s < min({(k) + 1, N}); ++s) {







E[i][j][k][l][s][t] += E[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int l = 0; l < min({(i) + 1, N}); ++l) {

for (int t = 0; t < min({(l) + 1, N}); ++t) {

for (int j = 0; j < N; ++j) {

for (int s = max({j, 0}); s < N; ++s) {

for (int k = max({i, 0}); k < min({(j) + 1, N}); ++k) {







E[i][j][k][l][s][t] += E[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int l = 0; l < min({(i) + 1, N}); ++l) {

for (int k = max({i, 0}); k < N; ++k) {

for (int t = 0; t < min({(l) + 1, N}); ++t) {

for (int j = 0; j < N; ++j) {

for (int s = max({k, 0}); s < min({(j) + 1, N}); ++s) {







E[i][j][k][l][s][t] += E[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int l = 0; l < min({(i) + 1, N}); ++l) {

for (int t = 0; t < min({(l) + 1, N}); ++t) {

for (int j = 0; j < N; ++j) {

for (int s = max({i, 0}); s < min({(j) + 1, N}); ++s) {

for (int k = max({j, 0}); k < N; ++k) {







E[i][j][k][l][s][t] += E[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int l = 0; l < min({(i) + 1, N}); ++l) {

for (int t = 0; t < min({(l) + 1, N}); ++t) {

for (int j = 0; j < N; ++j) {

for (int k = 0; k < min({(j) + 1, N}); ++k) {

for (int s = max({i, 0}); s < min({(k) + 1, N}); ++s) {







E[i][j][k][l][s][t] += E[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int j = 0; j < N; ++j) {

for (int s = 0; s < min({(j) + 1, N}); ++s) {

for (int k = max({j, 0}); k < N; ++k) {

for (int t = 0; t < min({(s) + 1, N}); ++t) {

for (int l = max({k, 0}); l < min({(i) + 1, N}); ++l) {







E[i][j][k][l][s][t] += E[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int l = max({i, 0}); l < N; ++l) {

for (int j = 0; j < N; ++j) {

for (int s = 0; s < min({(j) + 1, N}); ++s) {

for (int k = max({j, 0}); k < min({(i) + 1, N}); ++k) {

for (int t = 0; t < min({(s) + 1, N}); ++t) {







E[i][j][k][l][s][t] += E[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int j = 0; j < N; ++j) {

for (int k = 0; k < min({(i) + 1, N}); ++k) {

for (int s = 0; s < min({(j) + 1, N}); ++s) {

for (int l = max({j, 0}); l < min({(k) + 1, N}); ++l) {

for (int t = 0; t < min({(s) + 1, N}); ++t) {







E[i][j][k][l][s][t] += E[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int j = 0; j < N; ++j) {

for (int k = max({i, 0}); k < N; ++k) {

for (int s = 0; s < min({(j) + 1, N}); ++s) {

for (int l = max({j, 0}); l < min({(i) + 1, N}); ++l) {

for (int t = 0; t < min({(s) + 1, N}); ++t) {







E[i][j][k][l][s][t] += E[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int j = 0; j < min({(i) + 1, N}); ++j) {

for (int k = max({i, 0}); k < N; ++k) {

for (int s = 0; s < min({(j) + 1, N}); ++s) {

for (int l = max({k, 0}); l < N; ++l) {

for (int t = 0; t < min({(s) + 1, N}); ++t) {







E[i][j][k][l][s][t] += E[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int j = 0; j < min({(i) + 1, N}); ++j) {

for (int s = 0; s < min({(j) + 1, N}); ++s) {

for (int t = 0; t < min({(s) + 1, N}); ++t) {

for (int k = 0; k < N; ++k) {

for (int l = max({i, 0}); l < min({(k) + 1, N}); ++l) {







E[i][j][k][l][s][t] += E[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int j = 0; j < N; ++j) {

for (int l = max({j, 0}); l < min({(i) + 1, N}); ++l) {

for (int k = 0; k < min({(j) + 1, N}); ++k) {

for (int s = 0; s < min({(k) + 1, N}); ++s) {

for (int t = 0; t < min({(s) + 1, N}); ++t) {







E[i][j][k][l][s][t] += E[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int l = max({i, 0}); l < N; ++l) {

for (int j = 0; j < min({(i) + 1, N}); ++j) {

for (int k = 0; k < min({(j) + 1, N}); ++k) {

for (int s = 0; s < min({(k) + 1, N}); ++s) {

for (int t = 0; t < min({(s) + 1, N}); ++t) {







E[i][j][k][l][s][t] += E[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int j = 0; j < min({(i) + 1, N}); ++j) {

for (int k = 0; k < N; ++k) {

for (int s = 0; s < min({(k) + 1, N}); ++s) {

for (int l = max({k, 0}); l < min({(j) + 1, N}); ++l) {

for (int t = 0; t < min({(s) + 1, N}); ++t) {







E[i][j][k][l][s][t] += E[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int j = max({i, 0}); j < N; ++j) {

for (int k = 0; k < N; ++k) {

for (int s = 0; s < min({(k) + 1, N}); ++s) {

for (int l = max({k, 0}); l < min({(i) + 1, N}); ++l) {

for (int t = 0; t < min({(s) + 1, N}); ++t) {







E[i][j][k][l][s][t] += E[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int j = max({i, 0}); j < N; ++j) {

for (int k = 0; k < min({(i) + 1, N}); ++k) {

for (int l = max({j, 0}); l < N; ++l) {

for (int s = 0; s < min({(k) + 1, N}); ++s) {

for (int t = 0; t < min({(s) + 1, N}); ++t) {







E[i][j][k][l][s][t] += E[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int j = 0; j < N; ++j) {

for (int k = 0; k < min({(i) + 1, N}); ++k) {

for (int l = max({i, 0}); l < min({(j) + 1, N}); ++l) {

for (int s = 0; s < min({(k) + 1, N}); ++s) {

for (int t = 0; t < min({(s) + 1, N}); ++t) {







E[i][j][k][l][s][t] += E[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int j = 0; j < N; ++j) {

for (int l = 0; l < min({(j) + 1, N}); ++l) {

for (int k = max({j, 0}); k < min({(i) + 1, N}); ++k) {

for (int s = 0; s < min({(l) + 1, N}); ++s) {

for (int t = 0; t < min({(s) + 1, N}); ++t) {







E[i][j][k][l][s][t] += E[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int j = 0; j < min({(i) + 1, N}); ++j) {

for (int k = max({i, 0}); k < N; ++k) {

for (int l = 0; l < min({(j) + 1, N}); ++l) {

for (int s = 0; s < min({(l) + 1, N}); ++s) {

for (int t = 0; t < min({(s) + 1, N}); ++t) {







E[i][j][k][l][s][t] += E[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int j = 0; j < min({(i) + 1, N}); ++j) {

for (int k = 0; k < min({(j) + 1, N}); ++k) {

for (int l = 0; l < min({(k) + 1, N}); ++l) {

for (int s = 0; s < min({(l) + 1, N}); ++s) {

for (int t = 0; t < min({(s) + 1, N}); ++t) {







E[i][j][k][l][s][t] += E[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int j = max({i, 0}); j < N; ++j) {

for (int k = 0; k < min({(i) + 1, N}); ++k) {

for (int l = 0; l < min({(k) + 1, N}); ++l) {

for (int s = 0; s < min({(l) + 1, N}); ++s) {

for (int t = 0; t < min({(s) + 1, N}); ++t) {







E[i][j][k][l][s][t] += E[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int l = 0; l < min({(i) + 1, N}); ++l) {

for (int j = max({i, 0}); j < N; ++j) {

for (int s = 0; s < min({(l) + 1, N}); ++s) {

for (int k = max({j, 0}); k < N; ++k) {

for (int t = 0; t < min({(s) + 1, N}); ++t) {







E[i][j][k][l][s][t] += E[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int l = 0; l < min({(i) + 1, N}); ++l) {

for (int s = 0; s < min({(l) + 1, N}); ++s) {

for (int t = 0; t < min({(s) + 1, N}); ++t) {

for (int j = 0; j < N; ++j) {

for (int k = max({i, 0}); k < min({(j) + 1, N}); ++k) {







E[i][j][k][l][s][t] += E[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int s = 0; s < min({(i) + 1, N}); ++s) {

for (int j = max({i, 0}); j < N; ++j) {

for (int t = 0; t < min({(s) + 1, N}); ++t) {

for (int k = max({j, 0}); k < N; ++k) {

for (int l = max({k, 0}); l < N; ++l) {







E[i][j][k][l][s][t] += E[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int s = 0; s < min({(i) + 1, N}); ++s) {

for (int j = max({i, 0}); j < N; ++j) {

for (int t = 0; t < min({(s) + 1, N}); ++t) {

for (int k = 0; k < N; ++k) {

for (int l = max({j, 0}); l < min({(k) + 1, N}); ++l) {







E[i][j][k][l][s][t] += E[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int s = 0; s < min({(i) + 1, N}); ++s) {

for (int t = 0; t < min({(s) + 1, N}); ++t) {

for (int j = 0; j < N; ++j) {

for (int l = max({j, 0}); l < N; ++l) {

for (int k = max({i, 0}); k < min({(j) + 1, N}); ++k) {







E[i][j][k][l][s][t] += E[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int s = 0; s < min({(i) + 1, N}); ++s) {

for (int k = max({i, 0}); k < N; ++k) {

for (int t = 0; t < min({(s) + 1, N}); ++t) {

for (int j = 0; j < N; ++j) {

for (int l = max({k, 0}); l < min({(j) + 1, N}); ++l) {







E[i][j][k][l][s][t] += E[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int s = 0; s < min({(i) + 1, N}); ++s) {

for (int t = 0; t < min({(s) + 1, N}); ++t) {

for (int j = 0; j < N; ++j) {

for (int l = max({i, 0}); l < min({(j) + 1, N}); ++l) {

for (int k = max({j, 0}); k < N; ++k) {







E[i][j][k][l][s][t] += E[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int s = 0; s < min({(i) + 1, N}); ++s) {

for (int t = 0; t < min({(s) + 1, N}); ++t) {

for (int j = 0; j < N; ++j) {

for (int k = 0; k < min({(j) + 1, N}); ++k) {

for (int l = max({i, 0}); l < min({(k) + 1, N}); ++l) {







E[i][j][k][l][s][t] += E[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int t = 0; t < min({(i) + 1, N}); ++t) {

for (int j = max({i, 0}); j < N; ++j) {

for (int k = max({j, 0}); k < N; ++k) {

for (int l = max({k, 0}); l < N; ++l) {

for (int s = max({l, 0}); s < N; ++s) {







E[i][j][k][l][s][t] += E[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int t = 0; t < min({(i) + 1, N}); ++t) {

for (int j = max({i, 0}); j < N; ++j) {

for (int k = max({j, 0}); k < N; ++k) {

for (int l = 0; l < N; ++l) {

for (int s = max({k, 0}); s < min({(l) + 1, N}); ++s) {







E[i][j][k][l][s][t] += E[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int t = 0; t < min({(i) + 1, N}); ++t) {

for (int j = max({i, 0}); j < N; ++j) {

for (int k = 0; k < N; ++k) {

for (int s = max({k, 0}); s < N; ++s) {

for (int l = max({j, 0}); l < min({(k) + 1, N}); ++l) {







E[i][j][k][l][s][t] += E[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int t = 0; t < min({(i) + 1, N}); ++t) {

for (int j = max({i, 0}); j < N; ++j) {

for (int l = max({j, 0}); l < N; ++l) {

for (int k = 0; k < N; ++k) {

for (int s = max({l, 0}); s < min({(k) + 1, N}); ++s) {







E[i][j][k][l][s][t] += E[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int t = 0; t < min({(i) + 1, N}); ++t) {

for (int j = max({i, 0}); j < N; ++j) {

for (int k = 0; k < N; ++k) {

for (int s = max({j, 0}); s < min({(k) + 1, N}); ++s) {

for (int l = max({k, 0}); l < N; ++l) {







E[i][j][k][l][s][t] += E[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int t = 0; t < min({(i) + 1, N}); ++t) {

for (int j = max({i, 0}); j < N; ++j) {

for (int k = 0; k < N; ++k) {

for (int l = 0; l < min({(k) + 1, N}); ++l) {

for (int s = max({j, 0}); s < min({(l) + 1, N}); ++s) {







E[i][j][k][l][s][t] += E[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int t = 0; t < min({(i) + 1, N}); ++t) {

for (int j = 0; j < N; ++j) {

for (int l = max({j, 0}); l < N; ++l) {

for (int k = max({i, 0}); k < min({(j) + 1, N}); ++k) {

for (int s = max({l, 0}); s < N; ++s) {







E[i][j][k][l][s][t] += E[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int t = 0; t < min({(i) + 1, N}); ++t) {

for (int j = 0; j < N; ++j) {

for (int k = max({i, 0}); k < min({(j) + 1, N}); ++k) {

for (int l = 0; l < N; ++l) {

for (int s = max({j, 0}); s < min({(l) + 1, N}); ++s) {







E[i][j][k][l][s][t] += E[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int t = 0; t < min({(i) + 1, N}); ++t) {

for (int k = max({i, 0}); k < N; ++k) {

for (int j = 0; j < N; ++j) {

for (int s = max({j, 0}); s < N; ++s) {

for (int l = max({k, 0}); l < min({(j) + 1, N}); ++l) {







E[i][j][k][l][s][t] += E[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int t = 0; t < min({(i) + 1, N}); ++t) {

for (int k = max({i, 0}); k < N; ++k) {

for (int l = max({k, 0}); l < N; ++l) {

for (int j = 0; j < N; ++j) {

for (int s = max({l, 0}); s < min({(j) + 1, N}); ++s) {







E[i][j][k][l][s][t] += E[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int t = 0; t < min({(i) + 1, N}); ++t) {

for (int k = max({i, 0}); k < N; ++k) {

for (int j = 0; j < N; ++j) {

for (int s = max({k, 0}); s < min({(j) + 1, N}); ++s) {

for (int l = max({j, 0}); l < N; ++l) {







E[i][j][k][l][s][t] += E[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int t = 0; t < min({(i) + 1, N}); ++t) {

for (int k = max({i, 0}); k < N; ++k) {

for (int j = 0; j < N; ++j) {

for (int l = 0; l < min({(j) + 1, N}); ++l) {

for (int s = max({k, 0}); s < min({(l) + 1, N}); ++s) {







E[i][j][k][l][s][t] += E[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int t = 0; t < min({(i) + 1, N}); ++t) {

for (int j = 0; j < N; ++j) {

for (int l = max({i, 0}); l < min({(j) + 1, N}); ++l) {

for (int k = max({j, 0}); k < N; ++k) {

for (int s = max({k, 0}); s < N; ++s) {







E[i][j][k][l][s][t] += E[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int t = 0; t < min({(i) + 1, N}); ++t) {

for (int j = 0; j < N; ++j) {

for (int l = max({i, 0}); l < min({(j) + 1, N}); ++l) {

for (int k = 0; k < N; ++k) {

for (int s = max({j, 0}); s < min({(k) + 1, N}); ++s) {







E[i][j][k][l][s][t] += E[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int t = 0; t < min({(i) + 1, N}); ++t) {

for (int j = 0; j < N; ++j) {

for (int s = max({j, 0}); s < N; ++s) {

for (int k = 0; k < min({(j) + 1, N}); ++k) {

for (int l = max({i, 0}); l < min({(k) + 1, N}); ++l) {







E[i][j][k][l][s][t] += E[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int t = 0; t < min({(i) + 1, N}); ++t) {

for (int j = 0; j < N; ++j) {

for (int k = 0; k < N; ++k) {

for (int s = max({k, 0}); s < min({(j) + 1, N}); ++s) {

for (int l = max({i, 0}); l < min({(k) + 1, N}); ++l) {







E[i][j][k][l][s][t] += E[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int t = 0; t < min({(i) + 1, N}); ++t) {

for (int l = max({i, 0}); l < N; ++l) {

for (int j = 0; j < N; ++j) {

for (int s = max({l, 0}); s < min({(j) + 1, N}); ++s) {

for (int k = max({j, 0}); k < N; ++k) {







E[i][j][k][l][s][t] += E[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int t = 0; t < min({(i) + 1, N}); ++t) {

for (int l = max({i, 0}); l < N; ++l) {

for (int j = 0; j < N; ++j) {

for (int k = 0; k < min({(j) + 1, N}); ++k) {

for (int s = max({l, 0}); s < min({(k) + 1, N}); ++s) {







E[i][j][k][l][s][t] += E[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int t = 0; t < min({(i) + 1, N}); ++t) {

for (int j = 0; j < N; ++j) {

for (int s = max({i, 0}); s < min({(j) + 1, N}); ++s) {

for (int k = max({j, 0}); k < N; ++k) {

for (int l = max({k, 0}); l < N; ++l) {







E[i][j][k][l][s][t] += E[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int t = 0; t < min({(i) + 1, N}); ++t) {

for (int j = 0; j < N; ++j) {

for (int s = max({i, 0}); s < min({(j) + 1, N}); ++s) {

for (int k = 0; k < N; ++k) {

for (int l = max({j, 0}); l < min({(k) + 1, N}); ++l) {







E[i][j][k][l][s][t] += E[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int t = 0; t < min({(i) + 1, N}); ++t) {

for (int j = 0; j < N; ++j) {

for (int l = max({j, 0}); l < N; ++l) {

for (int k = 0; k < min({(j) + 1, N}); ++k) {

for (int s = max({i, 0}); s < min({(k) + 1, N}); ++s) {







E[i][j][k][l][s][t] += E[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int t = 0; t < min({(i) + 1, N}); ++t) {

for (int j = 0; j < N; ++j) {

for (int k = 0; k < N; ++k) {

for (int s = max({i, 0}); s < min({(k) + 1, N}); ++s) {

for (int l = max({k, 0}); l < min({(j) + 1, N}); ++l) {







E[i][j][k][l][s][t] += E[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int t = 0; t < min({(i) + 1, N}); ++t) {

for (int j = 0; j < N; ++j) {

for (int l = 0; l < min({(j) + 1, N}); ++l) {

for (int k = max({j, 0}); k < N; ++k) {

for (int s = max({i, 0}); s < min({(l) + 1, N}); ++s) {







E[i][j][k][l][s][t] += E[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int t = 0; t < min({(i) + 1, N}); ++t) {

for (int j = 0; j < N; ++j) {

for (int k = 0; k < min({(j) + 1, N}); ++k) {

for (int l = 0; l < min({(k) + 1, N}); ++l) {

for (int s = max({i, 0}); s < min({(l) + 1, N}); ++s) {







E[i][j][k][l][s][t] += E[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int j = max({i, 0}); j < N; ++j) {

for (int k = max({j, 0}); k < N; ++k) {

for (int l = max({k, 0}); l < N; ++l) {

for (int s = max({l, 0}); s < N; ++s) {

for (int t = max({s, 0}); t < N; ++t) {







E[i][j][k][l][s][t] += E[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int j = max({i, 0}); j < N; ++j) {

for (int k = max({j, 0}); k < N; ++k) {

for (int l = max({k, 0}); l < N; ++l) {

for (int s = 0; s < N; ++s) {

for (int t = max({l, 0}); t < min({(s) + 1, N}); ++t) {







E[i][j][k][l][s][t] += E[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int j = max({i, 0}); j < N; ++j) {

for (int k = max({j, 0}); k < N; ++k) {

for (int l = 0; l < N; ++l) {

for (int s = max({k, 0}); s < min({(l) + 1, N}); ++s) {

for (int t = max({l, 0}); t < N; ++t) {







E[i][j][k][l][s][t] += E[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int j = max({i, 0}); j < N; ++j) {

for (int k = max({j, 0}); k < N; ++k) {

for (int s = max({k, 0}); s < N; ++s) {

for (int l = 0; l < N; ++l) {

for (int t = max({s, 0}); t < min({(l) + 1, N}); ++t) {







E[i][j][k][l][s][t] += E[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int j = max({i, 0}); j < N; ++j) {

for (int k = max({j, 0}); k < N; ++k) {

for (int l = 0; l < N; ++l) {

for (int s = max({l, 0}); s < N; ++s) {

for (int t = max({k, 0}); t < min({(l) + 1, N}); ++t) {







E[i][j][k][l][s][t] += E[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int j = max({i, 0}); j < N; ++j) {

for (int k = max({j, 0}); k < N; ++k) {

for (int l = 0; l < N; ++l) {

for (int s = 0; s < min({(l) + 1, N}); ++s) {

for (int t = max({k, 0}); t < min({(s) + 1, N}); ++t) {







E[i][j][k][l][s][t] += E[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int j = max({i, 0}); j < N; ++j) {

for (int k = 0; k < N; ++k) {

for (int s = max({k, 0}); s < N; ++s) {

for (int l = max({j, 0}); l < min({(k) + 1, N}); ++l) {

for (int t = max({s, 0}); t < N; ++t) {







E[i][j][k][l][s][t] += E[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int j = max({i, 0}); j < N; ++j) {

for (int k = 0; k < N; ++k) {

for (int l = max({j, 0}); l < min({(k) + 1, N}); ++l) {

for (int s = 0; s < N; ++s) {

for (int t = max({k, 0}); t < min({(s) + 1, N}); ++t) {







E[i][j][k][l][s][t] += E[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int j = max({i, 0}); j < N; ++j) {

for (int l = max({j, 0}); l < N; ++l) {

for (int k = 0; k < N; ++k) {

for (int s = max({l, 0}); s < min({(k) + 1, N}); ++s) {

for (int t = max({k, 0}); t < N; ++t) {







E[i][j][k][l][s][t] += E[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int j = max({i, 0}); j < N; ++j) {

for (int l = max({j, 0}); l < N; ++l) {

for (int s = max({l, 0}); s < N; ++s) {

for (int k = 0; k < N; ++k) {

for (int t = max({s, 0}); t < min({(k) + 1, N}); ++t) {







E[i][j][k][l][s][t] += E[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int j = max({i, 0}); j < N; ++j) {

for (int l = max({j, 0}); l < N; ++l) {

for (int k = 0; k < N; ++k) {

for (int s = max({k, 0}); s < N; ++s) {

for (int t = max({l, 0}); t < min({(k) + 1, N}); ++t) {







E[i][j][k][l][s][t] += E[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int j = max({i, 0}); j < N; ++j) {

for (int l = max({j, 0}); l < N; ++l) {

for (int k = 0; k < N; ++k) {

for (int s = 0; s < min({(k) + 1, N}); ++s) {

for (int t = max({l, 0}); t < min({(s) + 1, N}); ++t) {







E[i][j][k][l][s][t] += E[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int j = max({i, 0}); j < N; ++j) {

for (int k = 0; k < N; ++k) {

for (int s = max({j, 0}); s < min({(k) + 1, N}); ++s) {

for (int l = max({k, 0}); l < N; ++l) {

for (int t = max({l, 0}); t < N; ++t) {







E[i][j][k][l][s][t] += E[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int j = max({i, 0}); j < N; ++j) {

for (int k = 0; k < N; ++k) {

for (int s = max({j, 0}); s < min({(k) + 1, N}); ++s) {

for (int l = 0; l < N; ++l) {

for (int t = max({k, 0}); t < min({(l) + 1, N}); ++t) {







E[i][j][k][l][s][t] += E[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int j = max({i, 0}); j < N; ++j) {

for (int k = 0; k < N; ++k) {

for (int t = max({k, 0}); t < N; ++t) {

for (int l = 0; l < min({(k) + 1, N}); ++l) {

for (int s = max({j, 0}); s < min({(l) + 1, N}); ++s) {







E[i][j][k][l][s][t] += E[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int j = max({i, 0}); j < N; ++j) {

for (int k = 0; k < N; ++k) {

for (int l = 0; l < N; ++l) {

for (int s = max({j, 0}); s < min({(l) + 1, N}); ++s) {

for (int t = max({l, 0}); t < min({(k) + 1, N}); ++t) {







E[i][j][k][l][s][t] += E[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int j = max({i, 0}); j < N; ++j) {

for (int s = max({j, 0}); s < N; ++s) {

for (int k = 0; k < N; ++k) {

for (int t = max({s, 0}); t < min({(k) + 1, N}); ++t) {

for (int l = max({k, 0}); l < N; ++l) {







E[i][j][k][l][s][t] += E[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int j = max({i, 0}); j < N; ++j) {

for (int s = max({j, 0}); s < N; ++s) {

for (int k = 0; k < N; ++k) {

for (int l = 0; l < min({(k) + 1, N}); ++l) {

for (int t = max({s, 0}); t < min({(l) + 1, N}); ++t) {







E[i][j][k][l][s][t] += E[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int j = max({i, 0}); j < N; ++j) {

for (int k = 0; k < N; ++k) {

for (int t = max({j, 0}); t < min({(k) + 1, N}); ++t) {

for (int l = max({k, 0}); l < N; ++l) {

for (int s = max({l, 0}); s < N; ++s) {







E[i][j][k][l][s][t] += E[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int j = max({i, 0}); j < N; ++j) {

for (int k = 0; k < N; ++k) {

for (int t = max({j, 0}); t < min({(k) + 1, N}); ++t) {

for (int l = 0; l < N; ++l) {

for (int s = max({k, 0}); s < min({(l) + 1, N}); ++s) {







E[i][j][k][l][s][t] += E[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int j = max({i, 0}); j < N; ++j) {

for (int k = 0; k < N; ++k) {

for (int s = max({k, 0}); s < N; ++s) {

for (int l = 0; l < min({(k) + 1, N}); ++l) {

for (int t = max({j, 0}); t < min({(l) + 1, N}); ++t) {







E[i][j][k][l][s][t] += E[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int j = max({i, 0}); j < N; ++j) {

for (int k = 0; k < N; ++k) {

for (int l = 0; l < N; ++l) {

for (int s = max({l, 0}); s < min({(k) + 1, N}); ++s) {

for (int t = max({j, 0}); t < min({(l) + 1, N}); ++t) {







E[i][j][k][l][s][t] += E[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int j = max({i, 0}); j < N; ++j) {

for (int k = 0; k < N; ++k) {

for (int s = 0; s < min({(k) + 1, N}); ++s) {

for (int l = max({k, 0}); l < N; ++l) {

for (int t = max({j, 0}); t < min({(s) + 1, N}); ++t) {







E[i][j][k][l][s][t] += E[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int j = max({i, 0}); j < N; ++j) {

for (int k = 0; k < N; ++k) {

for (int l = 0; l < min({(k) + 1, N}); ++l) {

for (int s = 0; s < min({(l) + 1, N}); ++s) {

for (int t = max({j, 0}); t < min({(s) + 1, N}); ++t) {







E[i][j][k][l][s][t] += E[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int j = 0; j < N; ++j) {

for (int l = max({j, 0}); l < N; ++l) {

for (int k = max({i, 0}); k < min({(j) + 1, N}); ++k) {

for (int s = max({l, 0}); s < N; ++s) {

for (int t = max({s, 0}); t < N; ++t) {







E[i][j][k][l][s][t] += E[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int j = 0; j < N; ++j) {

for (int l = max({j, 0}); l < N; ++l) {

for (int k = max({i, 0}); k < min({(j) + 1, N}); ++k) {

for (int s = 0; s < N; ++s) {

for (int t = max({l, 0}); t < min({(s) + 1, N}); ++t) {







E[i][j][k][l][s][t] += E[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int j = 0; j < N; ++j) {

for (int k = max({i, 0}); k < min({(j) + 1, N}); ++k) {

for (int l = 0; l < N; ++l) {

for (int s = max({j, 0}); s < min({(l) + 1, N}); ++s) {

for (int t = max({l, 0}); t < N; ++t) {







E[i][j][k][l][s][t] += E[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int j = 0; j < N; ++j) {

for (int s = max({j, 0}); s < N; ++s) {

for (int k = max({i, 0}); k < min({(j) + 1, N}); ++k) {

for (int l = 0; l < N; ++l) {

for (int t = max({s, 0}); t < min({(l) + 1, N}); ++t) {







E[i][j][k][l][s][t] += E[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int j = 0; j < N; ++j) {

for (int k = max({i, 0}); k < min({(j) + 1, N}); ++k) {

for (int l = 0; l < N; ++l) {

for (int s = max({l, 0}); s < N; ++s) {

for (int t = max({j, 0}); t < min({(l) + 1, N}); ++t) {







E[i][j][k][l][s][t] += E[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int j = 0; j < N; ++j) {

for (int k = max({i, 0}); k < min({(j) + 1, N}); ++k) {

for (int l = 0; l < N; ++l) {

for (int s = 0; s < min({(l) + 1, N}); ++s) {

for (int t = max({j, 0}); t < min({(s) + 1, N}); ++t) {







E[i][j][k][l][s][t] += E[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int j = 0; j < N; ++j) {

for (int k = max({i, 0}); k < N; ++k) {

for (int s = max({j, 0}); s < N; ++s) {

for (int l = max({k, 0}); l < min({(j) + 1, N}); ++l) {

for (int t = max({s, 0}); t < N; ++t) {







E[i][j][k][l][s][t] += E[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int j = 0; j < N; ++j) {

for (int k = max({i, 0}); k < N; ++k) {

for (int l = max({k, 0}); l < min({(j) + 1, N}); ++l) {

for (int s = 0; s < N; ++s) {

for (int t = max({j, 0}); t < min({(s) + 1, N}); ++t) {







E[i][j][k][l][s][t] += E[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int j = 0; j < N; ++j) {

for (int k = max({i, 0}); k < N; ++k) {

for (int t = max({j, 0}); t < N; ++t) {

for (int l = max({k, 0}); l < N; ++l) {

for (int s = max({l, 0}); s < min({(j) + 1, N}); ++s) {







E[i][j][k][l][s][t] += E[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int j = 0; j < N; ++j) {

for (int k = max({i, 0}); k < N; ++k) {

for (int l = max({k, 0}); l < N; ++l) {

for (int s = max({l, 0}); s < N; ++s) {

for (int t = max({s, 0}); t < min({(j) + 1, N}); ++t) {







E[i][j][k][l][s][t] += E[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int j = 0; j < N; ++j) {

for (int k = max({i, 0}); k < N; ++k) {

for (int s = max({j, 0}); s < N; ++s) {

for (int l = max({k, 0}); l < N; ++l) {

for (int t = max({l, 0}); t < min({(j) + 1, N}); ++t) {







E[i][j][k][l][s][t] += E[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int j = 0; j < N; ++j) {

for (int k = max({i, 0}); k < N; ++k) {

for (int s = 0; s < min({(j) + 1, N}); ++s) {

for (int l = max({k, 0}); l < N; ++l) {

for (int t = max({l, 0}); t < min({(s) + 1, N}); ++t) {







E[i][j][k][l][s][t] += E[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int j = 0; j < N; ++j) {

for (int k = max({i, 0}); k < N; ++k) {

for (int l = max({j, 0}); l < N; ++l) {

for (int s = max({k, 0}); s < min({(j) + 1, N}); ++s) {

for (int t = max({l, 0}); t < N; ++t) {







E[i][j][k][l][s][t] += E[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int j = 0; j < N; ++j) {

for (int k = max({i, 0}); k < N; ++k) {

for (int s = max({k, 0}); s < min({(j) + 1, N}); ++s) {

for (int l = 0; l < N; ++l) {

for (int t = max({j, 0}); t < min({(l) + 1, N}); ++t) {







E[i][j][k][l][s][t] += E[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int j = 0; j < N; ++j) {

for (int k = max({i, 0}); k < N; ++k) {

for (int t = max({j, 0}); t < N; ++t) {

for (int l = 0; l < min({(j) + 1, N}); ++l) {

for (int s = max({k, 0}); s < min({(l) + 1, N}); ++s) {







E[i][j][k][l][s][t] += E[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int j = 0; j < N; ++j) {

for (int k = max({i, 0}); k < N; ++k) {

for (int l = 0; l < N; ++l) {

for (int s = max({k, 0}); s < min({(l) + 1, N}); ++s) {

for (int t = max({l, 0}); t < min({(j) + 1, N}); ++t) {







E[i][j][k][l][s][t] += E[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int j = 0; j < N; ++j) {

for (int k = max({i, 0}); k < N; ++k) {

for (int l = max({j, 0}); l < N; ++l) {

for (int s = max({k, 0}); s < N; ++s) {

for (int t = max({s, 0}); t < min({(j) + 1, N}); ++t) {







E[i][j][k][l][s][t] += E[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int j = 0; j < N; ++j) {

for (int k = max({i, 0}); k < N; ++k) {

for (int l = 0; l < min({(j) + 1, N}); ++l) {

for (int s = max({k, 0}); s < N; ++s) {

for (int t = max({s, 0}); t < min({(l) + 1, N}); ++t) {







E[i][j][k][l][s][t] += E[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int j = 0; j < N; ++j) {

for (int k = max({i, 0}); k < N; ++k) {

for (int l = max({j, 0}); l < N; ++l) {

for (int t = max({k, 0}); t < min({(j) + 1, N}); ++t) {

for (int s = max({l, 0}); s < N; ++s) {







E[i][j][k][l][s][t] += E[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int j = 0; j < N; ++j) {

for (int k = max({i, 0}); k < N; ++k) {

for (int t = max({k, 0}); t < min({(j) + 1, N}); ++t) {

for (int l = 0; l < N; ++l) {

for (int s = max({j, 0}); s < min({(l) + 1, N}); ++s) {







E[i][j][k][l][s][t] += E[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int j = 0; j < N; ++j) {

for (int k = max({i, 0}); k < N; ++k) {

for (int s = max({j, 0}); s < N; ++s) {

for (int l = 0; l < min({(j) + 1, N}); ++l) {

for (int t = max({k, 0}); t < min({(l) + 1, N}); ++t) {







E[i][j][k][l][s][t] += E[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int j = 0; j < N; ++j) {

for (int k = max({i, 0}); k < N; ++k) {

for (int l = 0; l < N; ++l) {

for (int s = max({l, 0}); s < min({(j) + 1, N}); ++s) {

for (int t = max({k, 0}); t < min({(l) + 1, N}); ++t) {







E[i][j][k][l][s][t] += E[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int j = 0; j < N; ++j) {

for (int k = max({i, 0}); k < N; ++k) {

for (int s = 0; s < min({(j) + 1, N}); ++s) {

for (int l = max({j, 0}); l < N; ++l) {

for (int t = max({k, 0}); t < min({(s) + 1, N}); ++t) {







E[i][j][k][l][s][t] += E[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int j = 0; j < N; ++j) {

for (int k = max({i, 0}); k < N; ++k) {

for (int l = 0; l < min({(j) + 1, N}); ++l) {

for (int s = 0; s < min({(l) + 1, N}); ++s) {

for (int t = max({k, 0}); t < min({(s) + 1, N}); ++t) {







E[i][j][k][l][s][t] += E[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int j = 0; j < N; ++j) {

for (int l = max({i, 0}); l < min({(j) + 1, N}); ++l) {

for (int k = max({j, 0}); k < N; ++k) {

for (int s = max({k, 0}); s < N; ++s) {

for (int t = max({s, 0}); t < N; ++t) {







E[i][j][k][l][s][t] += E[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int j = 0; j < N; ++j) {

for (int l = max({i, 0}); l < min({(j) + 1, N}); ++l) {

for (int k = max({j, 0}); k < N; ++k) {

for (int s = 0; s < N; ++s) {

for (int t = max({k, 0}); t < min({(s) + 1, N}); ++t) {







E[i][j][k][l][s][t] += E[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int j = 0; j < N; ++j) {

for (int l = max({i, 0}); l < min({(j) + 1, N}); ++l) {

for (int k = 0; k < N; ++k) {

for (int s = max({j, 0}); s < min({(k) + 1, N}); ++s) {

for (int t = max({k, 0}); t < N; ++t) {







E[i][j][k][l][s][t] += E[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int j = 0; j < N; ++j) {

for (int s = max({j, 0}); s < N; ++s) {

for (int l = max({i, 0}); l < min({(j) + 1, N}); ++l) {

for (int k = 0; k < N; ++k) {

for (int t = max({s, 0}); t < min({(k) + 1, N}); ++t) {







E[i][j][k][l][s][t] += E[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int j = 0; j < N; ++j) {

for (int l = max({i, 0}); l < min({(j) + 1, N}); ++l) {

for (int k = 0; k < N; ++k) {

for (int s = max({k, 0}); s < N; ++s) {

for (int t = max({j, 0}); t < min({(k) + 1, N}); ++t) {







E[i][j][k][l][s][t] += E[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int j = 0; j < N; ++j) {

for (int l = max({i, 0}); l < min({(j) + 1, N}); ++l) {

for (int k = 0; k < N; ++k) {

for (int s = 0; s < min({(k) + 1, N}); ++s) {

for (int t = max({j, 0}); t < min({(s) + 1, N}); ++t) {







E[i][j][k][l][s][t] += E[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int j = 0; j < N; ++j) {

for (int s = max({j, 0}); s < N; ++s) {

for (int k = 0; k < min({(j) + 1, N}); ++k) {

for (int t = max({s, 0}); t < N; ++t) {

for (int l = max({i, 0}); l < min({(k) + 1, N}); ++l) {







E[i][j][k][l][s][t] += E[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int j = 0; j < N; ++j) {

for (int k = 0; k < min({(j) + 1, N}); ++k) {

for (int l = max({i, 0}); l < min({(k) + 1, N}); ++l) {

for (int s = 0; s < N; ++s) {

for (int t = max({j, 0}); t < min({(s) + 1, N}); ++t) {







E[i][j][k][l][s][t] += E[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int j = 0; j < N; ++j) {

for (int t = max({j, 0}); t < N; ++t) {

for (int k = 0; k < N; ++k) {

for (int s = max({k, 0}); s < min({(j) + 1, N}); ++s) {

for (int l = max({i, 0}); l < min({(k) + 1, N}); ++l) {







E[i][j][k][l][s][t] += E[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int j = 0; j < N; ++j) {

for (int k = 0; k < N; ++k) {

for (int s = max({k, 0}); s < N; ++s) {

for (int l = max({i, 0}); l < min({(k) + 1, N}); ++l) {

for (int t = max({s, 0}); t < min({(j) + 1, N}); ++t) {







E[i][j][k][l][s][t] += E[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int j = 0; j < N; ++j) {

for (int s = max({j, 0}); s < N; ++s) {

for (int k = 0; k < N; ++k) {

for (int t = max({k, 0}); t < min({(j) + 1, N}); ++t) {

for (int l = max({i, 0}); l < min({(k) + 1, N}); ++l) {







E[i][j][k][l][s][t] += E[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int j = 0; j < N; ++j) {

for (int s = 0; s < min({(j) + 1, N}); ++s) {

for (int k = 0; k < N; ++k) {

for (int t = max({k, 0}); t < min({(s) + 1, N}); ++t) {

for (int l = max({i, 0}); l < min({(k) + 1, N}); ++l) {







E[i][j][k][l][s][t] += E[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int l = max({i, 0}); l < N; ++l) {

for (int j = 0; j < N; ++j) {

for (int s = max({l, 0}); s < min({(j) + 1, N}); ++s) {

for (int k = max({j, 0}); k < N; ++k) {

for (int t = max({k, 0}); t < N; ++t) {







E[i][j][k][l][s][t] += E[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int l = max({i, 0}); l < N; ++l) {

for (int j = 0; j < N; ++j) {

for (int s = max({l, 0}); s < min({(j) + 1, N}); ++s) {

for (int k = 0; k < N; ++k) {

for (int t = max({j, 0}); t < min({(k) + 1, N}); ++t) {







E[i][j][k][l][s][t] += E[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int l = max({i, 0}); l < N; ++l) {

for (int j = 0; j < N; ++j) {

for (int t = max({j, 0}); t < N; ++t) {

for (int k = 0; k < min({(j) + 1, N}); ++k) {

for (int s = max({l, 0}); s < min({(k) + 1, N}); ++s) {







E[i][j][k][l][s][t] += E[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int l = max({i, 0}); l < N; ++l) {

for (int j = 0; j < N; ++j) {

for (int k = 0; k < N; ++k) {

for (int s = max({l, 0}); s < min({(k) + 1, N}); ++s) {

for (int t = max({k, 0}); t < min({(j) + 1, N}); ++t) {







E[i][j][k][l][s][t] += E[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int l = max({i, 0}); l < N; ++l) {

for (int s = max({l, 0}); s < N; ++s) {

for (int j = 0; j < N; ++j) {

for (int t = max({s, 0}); t < min({(j) + 1, N}); ++t) {

for (int k = max({j, 0}); k < N; ++k) {







E[i][j][k][l][s][t] += E[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int l = max({i, 0}); l < N; ++l) {

for (int s = max({l, 0}); s < N; ++s) {

for (int j = 0; j < N; ++j) {

for (int k = 0; k < min({(j) + 1, N}); ++k) {

for (int t = max({s, 0}); t < min({(k) + 1, N}); ++t) {







E[i][j][k][l][s][t] += E[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int l = max({i, 0}); l < N; ++l) {

for (int j = 0; j < N; ++j) {

for (int t = max({l, 0}); t < min({(j) + 1, N}); ++t) {

for (int k = max({j, 0}); k < N; ++k) {

for (int s = max({k, 0}); s < N; ++s) {







E[i][j][k][l][s][t] += E[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int l = max({i, 0}); l < N; ++l) {

for (int j = 0; j < N; ++j) {

for (int t = max({l, 0}); t < min({(j) + 1, N}); ++t) {

for (int k = 0; k < N; ++k) {

for (int s = max({j, 0}); s < min({(k) + 1, N}); ++s) {







E[i][j][k][l][s][t] += E[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int l = max({i, 0}); l < N; ++l) {

for (int j = 0; j < N; ++j) {

for (int s = max({j, 0}); s < N; ++s) {

for (int k = 0; k < min({(j) + 1, N}); ++k) {

for (int t = max({l, 0}); t < min({(k) + 1, N}); ++t) {







E[i][j][k][l][s][t] += E[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int l = max({i, 0}); l < N; ++l) {

for (int j = 0; j < N; ++j) {

for (int k = 0; k < N; ++k) {

for (int s = max({k, 0}); s < min({(j) + 1, N}); ++s) {

for (int t = max({l, 0}); t < min({(k) + 1, N}); ++t) {







E[i][j][k][l][s][t] += E[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int l = max({i, 0}); l < N; ++l) {

for (int j = 0; j < N; ++j) {

for (int s = 0; s < min({(j) + 1, N}); ++s) {

for (int k = max({j, 0}); k < N; ++k) {

for (int t = max({l, 0}); t < min({(s) + 1, N}); ++t) {







E[i][j][k][l][s][t] += E[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int l = max({i, 0}); l < N; ++l) {

for (int j = 0; j < N; ++j) {

for (int k = 0; k < min({(j) + 1, N}); ++k) {

for (int s = 0; s < min({(k) + 1, N}); ++s) {

for (int t = max({l, 0}); t < min({(s) + 1, N}); ++t) {







E[i][j][k][l][s][t] += E[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int j = 0; j < N; ++j) {

for (int s = max({i, 0}); s < min({(j) + 1, N}); ++s) {

for (int k = max({j, 0}); k < N; ++k) {

for (int l = max({k, 0}); l < N; ++l) {

for (int t = max({l, 0}); t < N; ++t) {







E[i][j][k][l][s][t] += E[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int j = 0; j < N; ++j) {

for (int s = max({i, 0}); s < min({(j) + 1, N}); ++s) {

for (int k = max({j, 0}); k < N; ++k) {

for (int l = 0; l < N; ++l) {

for (int t = max({k, 0}); t < min({(l) + 1, N}); ++t) {







E[i][j][k][l][s][t] += E[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int j = 0; j < N; ++j) {

for (int s = max({i, 0}); s < min({(j) + 1, N}); ++s) {

for (int k = 0; k < N; ++k) {

for (int t = max({k, 0}); t < N; ++t) {

for (int l = max({j, 0}); l < min({(k) + 1, N}); ++l) {







E[i][j][k][l][s][t] += E[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int j = 0; j < N; ++j) {

for (int s = max({i, 0}); s < min({(j) + 1, N}); ++s) {

for (int l = max({j, 0}); l < N; ++l) {

for (int k = 0; k < N; ++k) {

for (int t = max({l, 0}); t < min({(k) + 1, N}); ++t) {







E[i][j][k][l][s][t] += E[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int j = 0; j < N; ++j) {

for (int s = max({i, 0}); s < min({(j) + 1, N}); ++s) {

for (int k = 0; k < N; ++k) {

for (int t = max({j, 0}); t < min({(k) + 1, N}); ++t) {

for (int l = max({k, 0}); l < N; ++l) {







E[i][j][k][l][s][t] += E[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int j = 0; j < N; ++j) {

for (int s = max({i, 0}); s < min({(j) + 1, N}); ++s) {

for (int k = 0; k < N; ++k) {

for (int l = 0; l < min({(k) + 1, N}); ++l) {

for (int t = max({j, 0}); t < min({(l) + 1, N}); ++t) {







E[i][j][k][l][s][t] += E[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int j = 0; j < N; ++j) {

for (int l = max({j, 0}); l < N; ++l) {

for (int k = 0; k < min({(j) + 1, N}); ++k) {

for (int t = max({l, 0}); t < N; ++t) {

for (int s = max({i, 0}); s < min({(k) + 1, N}); ++s) {







E[i][j][k][l][s][t] += E[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int j = 0; j < N; ++j) {

for (int k = 0; k < min({(j) + 1, N}); ++k) {

for (int s = max({i, 0}); s < min({(k) + 1, N}); ++s) {

for (int l = 0; l < N; ++l) {

for (int t = max({j, 0}); t < min({(l) + 1, N}); ++t) {







E[i][j][k][l][s][t] += E[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int j = 0; j < N; ++j) {

for (int t = max({j, 0}); t < N; ++t) {

for (int k = 0; k < N; ++k) {

for (int s = max({i, 0}); s < min({(k) + 1, N}); ++s) {

for (int l = max({k, 0}); l < min({(j) + 1, N}); ++l) {







E[i][j][k][l][s][t] += E[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int j = 0; j < N; ++j) {

for (int k = 0; k < N; ++k) {

for (int s = max({i, 0}); s < min({(k) + 1, N}); ++s) {

for (int l = max({k, 0}); l < N; ++l) {

for (int t = max({l, 0}); t < min({(j) + 1, N}); ++t) {







E[i][j][k][l][s][t] += E[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int j = 0; j < N; ++j) {

for (int l = max({j, 0}); l < N; ++l) {

for (int k = 0; k < N; ++k) {

for (int s = max({i, 0}); s < min({(k) + 1, N}); ++s) {

for (int t = max({k, 0}); t < min({(j) + 1, N}); ++t) {







E[i][j][k][l][s][t] += E[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int j = 0; j < N; ++j) {

for (int l = 0; l < min({(j) + 1, N}); ++l) {

for (int k = 0; k < N; ++k) {

for (int s = max({i, 0}); s < min({(k) + 1, N}); ++s) {

for (int t = max({k, 0}); t < min({(l) + 1, N}); ++t) {







E[i][j][k][l][s][t] += E[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int j = 0; j < N; ++j) {

for (int l = 0; l < min({(j) + 1, N}); ++l) {

for (int k = max({j, 0}); k < N; ++k) {

for (int s = max({i, 0}); s < min({(l) + 1, N}); ++s) {

for (int t = max({k, 0}); t < N; ++t) {







E[i][j][k][l][s][t] += E[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int j = 0; j < N; ++j) {

for (int l = 0; l < min({(j) + 1, N}); ++l) {

for (int s = max({i, 0}); s < min({(l) + 1, N}); ++s) {

for (int k = 0; k < N; ++k) {

for (int t = max({j, 0}); t < min({(k) + 1, N}); ++t) {







E[i][j][k][l][s][t] += E[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int j = 0; j < N; ++j) {

for (int t = max({j, 0}); t < N; ++t) {

for (int k = 0; k < min({(j) + 1, N}); ++k) {

for (int l = 0; l < min({(k) + 1, N}); ++l) {

for (int s = max({i, 0}); s < min({(l) + 1, N}); ++s) {







E[i][j][k][l][s][t] += E[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int j = 0; j < N; ++j) {

for (int k = 0; k < N; ++k) {

for (int t = max({k, 0}); t < min({(j) + 1, N}); ++t) {

for (int l = 0; l < min({(k) + 1, N}); ++l) {

for (int s = max({i, 0}); s < min({(l) + 1, N}); ++s) {







E[i][j][k][l][s][t] += E[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int j = 0; j < N; ++j) {

for (int k = max({j, 0}); k < N; ++k) {

for (int l = 0; l < N; ++l) {

for (int s = max({i, 0}); s < min({(l) + 1, N}); ++s) {

for (int t = max({l, 0}); t < min({(j) + 1, N}); ++t) {







E[i][j][k][l][s][t] += E[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int j = 0; j < N; ++j) {

for (int k = 0; k < min({(j) + 1, N}); ++k) {

for (int l = 0; l < N; ++l) {

for (int s = max({i, 0}); s < min({(l) + 1, N}); ++s) {

for (int t = max({l, 0}); t < min({(k) + 1, N}); ++t) {







E[i][j][k][l][s][t] += E[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int s = max({i, 0}); s < N; ++s) {

for (int j = 0; j < N; ++j) {

for (int t = max({s, 0}); t < min({(j) + 1, N}); ++t) {

for (int k = max({j, 0}); k < N; ++k) {

for (int l = max({k, 0}); l < N; ++l) {







E[i][j][k][l][s][t] += E[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int s = max({i, 0}); s < N; ++s) {

for (int j = 0; j < N; ++j) {

for (int t = max({s, 0}); t < min({(j) + 1, N}); ++t) {

for (int k = 0; k < N; ++k) {

for (int l = max({j, 0}); l < min({(k) + 1, N}); ++l) {







E[i][j][k][l][s][t] += E[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int s = max({i, 0}); s < N; ++s) {

for (int j = 0; j < N; ++j) {

for (int l = max({j, 0}); l < N; ++l) {

for (int k = 0; k < min({(j) + 1, N}); ++k) {

for (int t = max({s, 0}); t < min({(k) + 1, N}); ++t) {







E[i][j][k][l][s][t] += E[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int s = max({i, 0}); s < N; ++s) {

for (int j = 0; j < N; ++j) {

for (int k = 0; k < N; ++k) {

for (int t = max({s, 0}); t < min({(k) + 1, N}); ++t) {

for (int l = max({k, 0}); l < min({(j) + 1, N}); ++l) {







E[i][j][k][l][s][t] += E[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int s = max({i, 0}); s < N; ++s) {

for (int j = 0; j < N; ++j) {

for (int l = 0; l < min({(j) + 1, N}); ++l) {

for (int k = max({j, 0}); k < N; ++k) {

for (int t = max({s, 0}); t < min({(l) + 1, N}); ++t) {







E[i][j][k][l][s][t] += E[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int s = max({i, 0}); s < N; ++s) {

for (int j = 0; j < N; ++j) {

for (int k = 0; k < min({(j) + 1, N}); ++k) {

for (int l = 0; l < min({(k) + 1, N}); ++l) {

for (int t = max({s, 0}); t < min({(l) + 1, N}); ++t) {







E[i][j][k][l][s][t] += E[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int j = 0; j < N; ++j) {

for (int t = max({i, 0}); t < min({(j) + 1, N}); ++t) {

for (int k = max({j, 0}); k < N; ++k) {

for (int l = max({k, 0}); l < N; ++l) {

for (int s = max({l, 0}); s < N; ++s) {







E[i][j][k][l][s][t] += E[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int j = 0; j < N; ++j) {

for (int t = max({i, 0}); t < min({(j) + 1, N}); ++t) {

for (int k = max({j, 0}); k < N; ++k) {

for (int l = 0; l < N; ++l) {

for (int s = max({k, 0}); s < min({(l) + 1, N}); ++s) {







E[i][j][k][l][s][t] += E[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int j = 0; j < N; ++j) {

for (int t = max({i, 0}); t < min({(j) + 1, N}); ++t) {

for (int k = 0; k < N; ++k) {

for (int s = max({k, 0}); s < N; ++s) {

for (int l = max({j, 0}); l < min({(k) + 1, N}); ++l) {







E[i][j][k][l][s][t] += E[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int j = 0; j < N; ++j) {

for (int t = max({i, 0}); t < min({(j) + 1, N}); ++t) {

for (int l = max({j, 0}); l < N; ++l) {

for (int k = 0; k < N; ++k) {

for (int s = max({l, 0}); s < min({(k) + 1, N}); ++s) {







E[i][j][k][l][s][t] += E[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int j = 0; j < N; ++j) {

for (int t = max({i, 0}); t < min({(j) + 1, N}); ++t) {

for (int k = 0; k < N; ++k) {

for (int s = max({j, 0}); s < min({(k) + 1, N}); ++s) {

for (int l = max({k, 0}); l < N; ++l) {







E[i][j][k][l][s][t] += E[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int j = 0; j < N; ++j) {

for (int t = max({i, 0}); t < min({(j) + 1, N}); ++t) {

for (int k = 0; k < N; ++k) {

for (int l = 0; l < min({(k) + 1, N}); ++l) {

for (int s = max({j, 0}); s < min({(l) + 1, N}); ++s) {







E[i][j][k][l][s][t] += E[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int j = 0; j < N; ++j) {

for (int l = max({j, 0}); l < N; ++l) {

for (int k = 0; k < min({(j) + 1, N}); ++k) {

for (int s = max({l, 0}); s < N; ++s) {

for (int t = max({i, 0}); t < min({(k) + 1, N}); ++t) {







E[i][j][k][l][s][t] += E[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int j = 0; j < N; ++j) {

for (int k = 0; k < min({(j) + 1, N}); ++k) {

for (int t = max({i, 0}); t < min({(k) + 1, N}); ++t) {

for (int l = 0; l < N; ++l) {

for (int s = max({j, 0}); s < min({(l) + 1, N}); ++s) {







E[i][j][k][l][s][t] += E[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int j = 0; j < N; ++j) {

for (int s = max({j, 0}); s < N; ++s) {

for (int k = 0; k < N; ++k) {

for (int t = max({i, 0}); t < min({(k) + 1, N}); ++t) {

for (int l = max({k, 0}); l < min({(j) + 1, N}); ++l) {







E[i][j][k][l][s][t] += E[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int j = 0; j < N; ++j) {

for (int k = 0; k < N; ++k) {

for (int t = max({i, 0}); t < min({(k) + 1, N}); ++t) {

for (int l = max({k, 0}); l < N; ++l) {

for (int s = max({l, 0}); s < min({(j) + 1, N}); ++s) {







E[i][j][k][l][s][t] += E[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int j = 0; j < N; ++j) {

for (int l = max({j, 0}); l < N; ++l) {

for (int k = 0; k < N; ++k) {

for (int s = max({k, 0}); s < min({(j) + 1, N}); ++s) {

for (int t = max({i, 0}); t < min({(k) + 1, N}); ++t) {







E[i][j][k][l][s][t] += E[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int j = 0; j < N; ++j) {

for (int l = 0; l < min({(j) + 1, N}); ++l) {

for (int k = 0; k < N; ++k) {

for (int s = max({k, 0}); s < min({(l) + 1, N}); ++s) {

for (int t = max({i, 0}); t < min({(k) + 1, N}); ++t) {







E[i][j][k][l][s][t] += E[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int j = 0; j < N; ++j) {

for (int l = 0; l < min({(j) + 1, N}); ++l) {

for (int k = max({j, 0}); k < N; ++k) {

for (int t = max({i, 0}); t < min({(l) + 1, N}); ++t) {

for (int s = max({k, 0}); s < N; ++s) {







E[i][j][k][l][s][t] += E[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int j = 0; j < N; ++j) {

for (int l = 0; l < min({(j) + 1, N}); ++l) {

for (int t = max({i, 0}); t < min({(l) + 1, N}); ++t) {

for (int k = 0; k < N; ++k) {

for (int s = max({j, 0}); s < min({(k) + 1, N}); ++s) {







E[i][j][k][l][s][t] += E[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int j = 0; j < N; ++j) {

for (int s = max({j, 0}); s < N; ++s) {

for (int k = 0; k < min({(j) + 1, N}); ++k) {

for (int l = 0; l < min({(k) + 1, N}); ++l) {

for (int t = max({i, 0}); t < min({(l) + 1, N}); ++t) {







E[i][j][k][l][s][t] += E[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int j = 0; j < N; ++j) {

for (int k = 0; k < N; ++k) {

for (int s = max({k, 0}); s < min({(j) + 1, N}); ++s) {

for (int l = 0; l < min({(k) + 1, N}); ++l) {

for (int t = max({i, 0}); t < min({(l) + 1, N}); ++t) {







E[i][j][k][l][s][t] += E[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int j = 0; j < N; ++j) {

for (int k = max({j, 0}); k < N; ++k) {

for (int l = 0; l < N; ++l) {

for (int s = max({l, 0}); s < min({(j) + 1, N}); ++s) {

for (int t = max({i, 0}); t < min({(l) + 1, N}); ++t) {







E[i][j][k][l][s][t] += E[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int j = 0; j < N; ++j) {

for (int k = 0; k < min({(j) + 1, N}); ++k) {

for (int l = 0; l < N; ++l) {

for (int s = max({l, 0}); s < min({(k) + 1, N}); ++s) {

for (int t = max({i, 0}); t < min({(l) + 1, N}); ++t) {







E[i][j][k][l][s][t] += E[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int j = 0; j < N; ++j) {

for (int s = 0; s < min({(j) + 1, N}); ++s) {

for (int k = max({j, 0}); k < N; ++k) {

for (int t = max({i, 0}); t < min({(s) + 1, N}); ++t) {

for (int l = max({k, 0}); l < N; ++l) {







E[i][j][k][l][s][t] += E[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int j = 0; j < N; ++j) {

for (int s = 0; s < min({(j) + 1, N}); ++s) {

for (int t = max({i, 0}); t < min({(s) + 1, N}); ++t) {

for (int k = 0; k < N; ++k) {

for (int l = max({j, 0}); l < min({(k) + 1, N}); ++l) {







E[i][j][k][l][s][t] += E[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int j = 0; j < N; ++j) {

for (int l = max({j, 0}); l < N; ++l) {

for (int k = 0; k < min({(j) + 1, N}); ++k) {

for (int s = 0; s < min({(k) + 1, N}); ++s) {

for (int t = max({i, 0}); t < min({(s) + 1, N}); ++t) {







E[i][j][k][l][s][t] += E[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int j = 0; j < N; ++j) {

for (int k = 0; k < N; ++k) {

for (int s = 0; s < min({(k) + 1, N}); ++s) {

for (int l = max({k, 0}); l < min({(j) + 1, N}); ++l) {

for (int t = max({i, 0}); t < min({(s) + 1, N}); ++t) {







E[i][j][k][l][s][t] += E[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int j = 0; j < N; ++j) {

for (int l = 0; l < min({(j) + 1, N}); ++l) {

for (int k = max({j, 0}); k < N; ++k) {

for (int s = 0; s < min({(l) + 1, N}); ++s) {

for (int t = max({i, 0}); t < min({(s) + 1, N}); ++t) {







E[i][j][k][l][s][t] += E[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int j = 0; j < N; ++j) {

for (int k = 0; k < min({(j) + 1, N}); ++k) {

for (int l = 0; l < min({(k) + 1, N}); ++l) {

for (int s = 0; s < min({(l) + 1, N}); ++s) {

for (int t = max({i, 0}); t < min({(s) + 1, N}); ++t) {







E[i][j][k][l][s][t] += E[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int j = 0; j < min({i, N}); ++j) {



F[i][j] += F[ip][jp];
}
}
for (int i = 0; i < N; ++i) {

for (int j = 0; j < min({(i) + 1, N}); ++j) {

for (int k = max({i, 0}); k < N; ++k) {




G[i][j][k] += G[ip][jp][kp];
}
}
}
for (int i = 0; i < N; ++i) {

for (int j = 0; j < min({(i) + 1, N}); ++j) {

for (int k = 0; k < min({(j) + 1, N}); ++k) {




G[i][j][k] += G[ip][jp][kp];
}
}
}
for (int i = 0; i < N; ++i) {

for (int j = max({i, 0}); j < N; ++j) {

for (int k = 0; k < min({(i) + 1, N}); ++k) {




G[i][j][k] += G[ip][jp][kp];
}
}
}
for (int i = 0; i < N; ++i) {

for (int j = max({i, 0}); j < N; ++j) {

for (int k = max({j, 0}); k < N; ++k) {




G[i][j][k] += G[ip][jp][kp];
}
}
}
for (int i = 0; i < N; ++i) {

for (int j = 0; j < N; ++j) {

for (int k = max({i, 0}); k < min({(j) + 1, N}); ++k) {




G[i][j][k] += G[ip][jp][kp];
}
}
}
for (int i = 0; i < N; ++i) {

for (int l = max({i, 0}); l < N; ++l) {

for (int j = 0; j < N; ++j) {

for (int k = max({j, 0}); k < min({(i) + 1, N}); ++k) {





H[i][j][k][l] += H[ip][jp][kp][lp];
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int j = 0; j < N; ++j) {

for (int k = 0; k < min({(i) + 1, N}); ++k) {

for (int l = max({j, 0}); l < min({(k) + 1, N}); ++l) {





H[i][j][k][l] += H[ip][jp][kp][lp];
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int j = 0; j < N; ++j) {

for (int k = max({i, 0}); k < N; ++k) {

for (int l = max({j, 0}); l < min({(i) + 1, N}); ++l) {





H[i][j][k][l] += H[ip][jp][kp][lp];
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int j = 0; j < min({(i) + 1, N}); ++j) {

for (int k = max({i, 0}); k < N; ++k) {

for (int l = max({k, 0}); l < N; ++l) {





H[i][j][k][l] += H[ip][jp][kp][lp];
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int j = 0; j < min({(i) + 1, N}); ++j) {

for (int k = 0; k < N; ++k) {

for (int l = max({i, 0}); l < min({(k) + 1, N}); ++l) {





H[i][j][k][l] += H[ip][jp][kp][lp];
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int j = 0; j < N; ++j) {

for (int l = max({j, 0}); l < min({(i) + 1, N}); ++l) {

for (int k = 0; k < min({(j) + 1, N}); ++k) {





H[i][j][k][l] += H[ip][jp][kp][lp];
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int l = max({i, 0}); l < N; ++l) {

for (int j = 0; j < min({(i) + 1, N}); ++j) {

for (int k = 0; k < min({(j) + 1, N}); ++k) {





H[i][j][k][l] += H[ip][jp][kp][lp];
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int j = 0; j < min({(i) + 1, N}); ++j) {

for (int k = 0; k < N; ++k) {

for (int l = max({k, 0}); l < min({(j) + 1, N}); ++l) {





H[i][j][k][l] += H[ip][jp][kp][lp];
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int j = max({i, 0}); j < N; ++j) {

for (int k = 0; k < N; ++k) {

for (int l = max({k, 0}); l < min({(i) + 1, N}); ++l) {





H[i][j][k][l] += H[ip][jp][kp][lp];
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int j = max({i, 0}); j < N; ++j) {

for (int k = 0; k < min({(i) + 1, N}); ++k) {

for (int l = max({j, 0}); l < N; ++l) {





H[i][j][k][l] += H[ip][jp][kp][lp];
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int j = 0; j < N; ++j) {

for (int k = 0; k < min({(i) + 1, N}); ++k) {

for (int l = max({i, 0}); l < min({(j) + 1, N}); ++l) {





H[i][j][k][l] += H[ip][jp][kp][lp];
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int j = 0; j < N; ++j) {

for (int l = 0; l < min({(j) + 1, N}); ++l) {

for (int k = max({j, 0}); k < min({(i) + 1, N}); ++k) {





H[i][j][k][l] += H[ip][jp][kp][lp];
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int j = 0; j < min({(i) + 1, N}); ++j) {

for (int k = max({i, 0}); k < N; ++k) {

for (int l = 0; l < min({(j) + 1, N}); ++l) {





H[i][j][k][l] += H[ip][jp][kp][lp];
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int j = 0; j < min({(i) + 1, N}); ++j) {

for (int k = 0; k < min({(j) + 1, N}); ++k) {

for (int l = 0; l < min({(k) + 1, N}); ++l) {





H[i][j][k][l] += H[ip][jp][kp][lp];
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int j = max({i, 0}); j < N; ++j) {

for (int k = 0; k < min({(i) + 1, N}); ++k) {

for (int l = 0; l < min({(k) + 1, N}); ++l) {





H[i][j][k][l] += H[ip][jp][kp][lp];
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int l = 0; l < min({(i) + 1, N}); ++l) {

for (int j = max({i, 0}); j < N; ++j) {

for (int k = max({j, 0}); k < N; ++k) {





H[i][j][k][l] += H[ip][jp][kp][lp];
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int l = 0; l < min({(i) + 1, N}); ++l) {

for (int j = 0; j < N; ++j) {

for (int k = max({i, 0}); k < min({(j) + 1, N}); ++k) {





H[i][j][k][l] += H[ip][jp][kp][lp];
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int j = max({i, 0}); j < N; ++j) {

for (int k = max({j, 0}); k < N; ++k) {

for (int l = max({k, 0}); l < N; ++l) {





H[i][j][k][l] += H[ip][jp][kp][lp];
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int j = max({i, 0}); j < N; ++j) {

for (int k = 0; k < N; ++k) {

for (int l = max({j, 0}); l < min({(k) + 1, N}); ++l) {





H[i][j][k][l] += H[ip][jp][kp][lp];
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int j = 0; j < N; ++j) {

for (int l = max({j, 0}); l < N; ++l) {

for (int k = max({i, 0}); k < min({(j) + 1, N}); ++k) {





H[i][j][k][l] += H[ip][jp][kp][lp];
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int j = 0; j < N; ++j) {

for (int k = max({i, 0}); k < N; ++k) {

for (int l = max({k, 0}); l < min({(j) + 1, N}); ++l) {





H[i][j][k][l] += H[ip][jp][kp][lp];
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int j = 0; j < N; ++j) {

for (int l = max({i, 0}); l < min({(j) + 1, N}); ++l) {

for (int k = max({j, 0}); k < N; ++k) {





H[i][j][k][l] += H[ip][jp][kp][lp];
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int j = 0; j < N; ++j) {

for (int k = 0; k < min({(j) + 1, N}); ++k) {

for (int l = max({i, 0}); l < min({(k) + 1, N}); ++l) {





H[i][j][k][l] += H[ip][jp][kp][lp];
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int s = max({i, 0}); s < N; ++s) {

for (int j = 0; j < N; ++j) {

for (int k = max({j, 0}); k < N; ++k) {

for (int l = max({k, 0}); l < min({(i) + 1, N}); ++l) {






I[i][j][k][l][s] += I[ip][jp][kp][lp][sp];
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int l = 0; l < min({(i) + 1, N}); ++l) {

for (int j = 0; j < N; ++j) {

for (int k = max({j, 0}); k < N; ++k) {

for (int s = max({k, 0}); s < min({(l) + 1, N}); ++s) {






I[i][j][k][l][s] += I[ip][jp][kp][lp][sp];
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int l = max({i, 0}); l < N; ++l) {

for (int j = 0; j < N; ++j) {

for (int k = max({j, 0}); k < N; ++k) {

for (int s = max({k, 0}); s < min({(i) + 1, N}); ++s) {






I[i][j][k][l][s] += I[ip][jp][kp][lp][sp];
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int l = max({i, 0}); l < N; ++l) {

for (int s = max({l, 0}); s < N; ++s) {

for (int j = 0; j < N; ++j) {

for (int k = max({j, 0}); k < min({(i) + 1, N}); ++k) {






I[i][j][k][l][s] += I[ip][jp][kp][lp][sp];
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int j = 0; j < N; ++j) {

for (int k = max({j, 0}); k < min({(i) + 1, N}); ++k) {

for (int l = 0; l < N; ++l) {

for (int s = max({i, 0}); s < min({(l) + 1, N}); ++s) {






I[i][j][k][l][s] += I[ip][jp][kp][lp][sp];
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int j = 0; j < N; ++j) {

for (int k = 0; k < N; ++k) {

for (int s = max({k, 0}); s < min({(i) + 1, N}); ++s) {

for (int l = max({j, 0}); l < min({(k) + 1, N}); ++l) {






I[i][j][k][l][s] += I[ip][jp][kp][lp][sp];
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int s = max({i, 0}); s < N; ++s) {

for (int k = 0; k < min({(i) + 1, N}); ++k) {

for (int j = 0; j < N; ++j) {

for (int l = max({j, 0}); l < min({(k) + 1, N}); ++l) {






I[i][j][k][l][s] += I[ip][jp][kp][lp][sp];
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int j = 0; j < N; ++j) {

for (int k = 0; k < min({(i) + 1, N}); ++k) {

for (int l = max({j, 0}); l < N; ++l) {

for (int s = max({l, 0}); s < min({(k) + 1, N}); ++s) {






I[i][j][k][l][s] += I[ip][jp][kp][lp][sp];
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int j = 0; j < N; ++j) {

for (int k = max({i, 0}); k < N; ++k) {

for (int l = max({j, 0}); l < N; ++l) {

for (int s = max({l, 0}); s < min({(i) + 1, N}); ++s) {






I[i][j][k][l][s] += I[ip][jp][kp][lp][sp];
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int j = 0; j < N; ++j) {

for (int k = max({i, 0}); k < N; ++k) {

for (int l = max({j, 0}); l < min({(i) + 1, N}); ++l) {

for (int s = max({k, 0}); s < N; ++s) {






I[i][j][k][l][s] += I[ip][jp][kp][lp][sp];
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int j = 0; j < N; ++j) {

for (int l = max({j, 0}); l < min({(i) + 1, N}); ++l) {

for (int k = 0; k < N; ++k) {

for (int s = max({i, 0}); s < min({(k) + 1, N}); ++s) {






I[i][j][k][l][s] += I[ip][jp][kp][lp][sp];
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int j = 0; j < N; ++j) {

for (int k = 0; k < N; ++k) {

for (int s = max({j, 0}); s < min({(k) + 1, N}); ++s) {

for (int l = max({k, 0}); l < min({(i) + 1, N}); ++l) {






I[i][j][k][l][s] += I[ip][jp][kp][lp][sp];
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int l = max({i, 0}); l < N; ++l) {

for (int k = 0; k < min({(i) + 1, N}); ++k) {

for (int j = 0; j < N; ++j) {

for (int s = max({j, 0}); s < min({(k) + 1, N}); ++s) {






I[i][j][k][l][s] += I[ip][jp][kp][lp][sp];
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int j = 0; j < N; ++j) {

for (int k = 0; k < min({(i) + 1, N}); ++k) {

for (int l = 0; l < min({(k) + 1, N}); ++l) {

for (int s = max({j, 0}); s < min({(l) + 1, N}); ++s) {






I[i][j][k][l][s] += I[ip][jp][kp][lp][sp];
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int l = 0; l < min({(i) + 1, N}); ++l) {

for (int k = max({i, 0}); k < N; ++k) {

for (int j = 0; j < N; ++j) {

for (int s = max({j, 0}); s < min({(l) + 1, N}); ++s) {






I[i][j][k][l][s] += I[ip][jp][kp][lp][sp];
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int j = 0; j < N; ++j) {

for (int k = max({i, 0}); k < N; ++k) {

for (int s = max({j, 0}); s < min({(i) + 1, N}); ++s) {

for (int l = max({k, 0}); l < N; ++l) {






I[i][j][k][l][s] += I[ip][jp][kp][lp][sp];
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int j = 0; j < N; ++j) {

for (int s = max({j, 0}); s < min({(i) + 1, N}); ++s) {

for (int k = 0; k < N; ++k) {

for (int l = max({i, 0}); l < min({(k) + 1, N}); ++l) {






I[i][j][k][l][s] += I[ip][jp][kp][lp][sp];
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int j = 0; j < min({(i) + 1, N}); ++j) {

for (int k = max({i, 0}); k < N; ++k) {

for (int l = max({k, 0}); l < N; ++l) {

for (int s = max({l, 0}); s < N; ++s) {






I[i][j][k][l][s] += I[ip][jp][kp][lp][sp];
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int j = 0; j < min({(i) + 1, N}); ++j) {

for (int k = max({i, 0}); k < N; ++k) {

for (int l = 0; l < N; ++l) {

for (int s = max({k, 0}); s < min({(l) + 1, N}); ++s) {






I[i][j][k][l][s] += I[ip][jp][kp][lp][sp];
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int j = 0; j < min({(i) + 1, N}); ++j) {

for (int k = 0; k < N; ++k) {

for (int s = max({k, 0}); s < N; ++s) {

for (int l = max({i, 0}); l < min({(k) + 1, N}); ++l) {






I[i][j][k][l][s] += I[ip][jp][kp][lp][sp];
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int l = max({i, 0}); l < N; ++l) {

for (int j = 0; j < min({(i) + 1, N}); ++j) {

for (int k = 0; k < N; ++k) {

for (int s = max({l, 0}); s < min({(k) + 1, N}); ++s) {






I[i][j][k][l][s] += I[ip][jp][kp][lp][sp];
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int j = 0; j < min({(i) + 1, N}); ++j) {

for (int k = 0; k < N; ++k) {

for (int s = max({i, 0}); s < min({(k) + 1, N}); ++s) {

for (int l = max({k, 0}); l < N; ++l) {






I[i][j][k][l][s] += I[ip][jp][kp][lp][sp];
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int j = 0; j < min({(i) + 1, N}); ++j) {

for (int k = 0; k < N; ++k) {

for (int l = 0; l < min({(k) + 1, N}); ++l) {

for (int s = max({i, 0}); s < min({(l) + 1, N}); ++s) {






I[i][j][k][l][s] += I[ip][jp][kp][lp][sp];
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int j = 0; j < N; ++j) {

for (int l = max({j, 0}); l < N; ++l) {

for (int k = 0; k < min({(j) + 1, N}); ++k) {

for (int s = max({l, 0}); s < min({(i) + 1, N}); ++s) {






I[i][j][k][l][s] += I[ip][jp][kp][lp][sp];
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int s = max({i, 0}); s < N; ++s) {

for (int j = 0; j < N; ++j) {

for (int l = max({j, 0}); l < min({(i) + 1, N}); ++l) {

for (int k = 0; k < min({(j) + 1, N}); ++k) {






I[i][j][k][l][s] += I[ip][jp][kp][lp][sp];
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int l = 0; l < min({(i) + 1, N}); ++l) {

for (int j = 0; j < N; ++j) {

for (int s = max({j, 0}); s < min({(l) + 1, N}); ++s) {

for (int k = 0; k < min({(j) + 1, N}); ++k) {






I[i][j][k][l][s] += I[ip][jp][kp][lp][sp];
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int l = max({i, 0}); l < N; ++l) {

for (int j = 0; j < N; ++j) {

for (int s = max({j, 0}); s < min({(i) + 1, N}); ++s) {

for (int k = 0; k < min({(j) + 1, N}); ++k) {






I[i][j][k][l][s] += I[ip][jp][kp][lp][sp];
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int l = max({i, 0}); l < N; ++l) {

for (int j = 0; j < min({(i) + 1, N}); ++j) {

for (int s = max({l, 0}); s < N; ++s) {

for (int k = 0; k < min({(j) + 1, N}); ++k) {






I[i][j][k][l][s] += I[ip][jp][kp][lp][sp];
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int j = 0; j < min({(i) + 1, N}); ++j) {

for (int k = 0; k < min({(j) + 1, N}); ++k) {

for (int l = 0; l < N; ++l) {

for (int s = max({i, 0}); s < min({(l) + 1, N}); ++s) {






I[i][j][k][l][s] += I[ip][jp][kp][lp][sp];
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int j = 0; j < N; ++j) {

for (int s = max({j, 0}); s < min({(i) + 1, N}); ++s) {

for (int k = 0; k < N; ++k) {

for (int l = max({k, 0}); l < min({(j) + 1, N}); ++l) {






I[i][j][k][l][s] += I[ip][jp][kp][lp][sp];
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int s = max({i, 0}); s < N; ++s) {

for (int j = 0; j < min({(i) + 1, N}); ++j) {

for (int k = 0; k < N; ++k) {

for (int l = max({k, 0}); l < min({(j) + 1, N}); ++l) {






I[i][j][k][l][s] += I[ip][jp][kp][lp][sp];
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int j = 0; j < min({(i) + 1, N}); ++j) {

for (int k = 0; k < N; ++k) {

for (int l = max({k, 0}); l < N; ++l) {

for (int s = max({l, 0}); s < min({(j) + 1, N}); ++s) {






I[i][j][k][l][s] += I[ip][jp][kp][lp][sp];
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int j = max({i, 0}); j < N; ++j) {

for (int k = 0; k < N; ++k) {

for (int l = max({k, 0}); l < N; ++l) {

for (int s = max({l, 0}); s < min({(i) + 1, N}); ++s) {






I[i][j][k][l][s] += I[ip][jp][kp][lp][sp];
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int j = max({i, 0}); j < N; ++j) {

for (int s = max({j, 0}); s < N; ++s) {

for (int k = 0; k < N; ++k) {

for (int l = max({k, 0}); l < min({(i) + 1, N}); ++l) {






I[i][j][k][l][s] += I[ip][jp][kp][lp][sp];
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int j = 0; j < N; ++j) {

for (int s = max({i, 0}); s < min({(j) + 1, N}); ++s) {

for (int k = 0; k < N; ++k) {

for (int l = max({k, 0}); l < min({(i) + 1, N}); ++l) {






I[i][j][k][l][s] += I[ip][jp][kp][lp][sp];
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int j = 0; j < N; ++j) {

for (int l = max({j, 0}); l < min({(i) + 1, N}); ++l) {

for (int k = 0; k < N; ++k) {

for (int s = max({k, 0}); s < min({(j) + 1, N}); ++s) {






I[i][j][k][l][s] += I[ip][jp][kp][lp][sp];
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int l = max({i, 0}); l < N; ++l) {

for (int j = 0; j < min({(i) + 1, N}); ++j) {

for (int k = 0; k < N; ++k) {

for (int s = max({k, 0}); s < min({(j) + 1, N}); ++s) {






I[i][j][k][l][s] += I[ip][jp][kp][lp][sp];
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int j = 0; j < min({(i) + 1, N}); ++j) {

for (int l = 0; l < min({(j) + 1, N}); ++l) {

for (int k = 0; k < N; ++k) {

for (int s = max({k, 0}); s < min({(l) + 1, N}); ++s) {






I[i][j][k][l][s] += I[ip][jp][kp][lp][sp];
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int l = 0; l < min({(i) + 1, N}); ++l) {

for (int j = max({i, 0}); j < N; ++j) {

for (int k = 0; k < N; ++k) {

for (int s = max({k, 0}); s < min({(l) + 1, N}); ++s) {






I[i][j][k][l][s] += I[ip][jp][kp][lp][sp];
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int j = max({i, 0}); j < N; ++j) {

for (int l = max({j, 0}); l < N; ++l) {

for (int k = 0; k < N; ++k) {

for (int s = max({k, 0}); s < min({(i) + 1, N}); ++s) {






I[i][j][k][l][s] += I[ip][jp][kp][lp][sp];
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int j = 0; j < N; ++j) {

for (int l = max({i, 0}); l < min({(j) + 1, N}); ++l) {

for (int k = 0; k < N; ++k) {

for (int s = max({k, 0}); s < min({(i) + 1, N}); ++s) {






I[i][j][k][l][s] += I[ip][jp][kp][lp][sp];
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int j = max({i, 0}); j < N; ++j) {

for (int k = 0; k < min({(i) + 1, N}); ++k) {

for (int l = max({j, 0}); l < N; ++l) {

for (int s = max({l, 0}); s < N; ++s) {






I[i][j][k][l][s] += I[ip][jp][kp][lp][sp];
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int j = max({i, 0}); j < N; ++j) {

for (int k = 0; k < min({(i) + 1, N}); ++k) {

for (int l = 0; l < N; ++l) {

for (int s = max({j, 0}); s < min({(l) + 1, N}); ++s) {






I[i][j][k][l][s] += I[ip][jp][kp][lp][sp];
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int j = 0; j < N; ++j) {

for (int k = 0; k < min({(i) + 1, N}); ++k) {

for (int s = max({j, 0}); s < N; ++s) {

for (int l = max({i, 0}); l < min({(j) + 1, N}); ++l) {






I[i][j][k][l][s] += I[ip][jp][kp][lp][sp];
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int l = max({i, 0}); l < N; ++l) {

for (int k = 0; k < min({(i) + 1, N}); ++k) {

for (int j = 0; j < N; ++j) {

for (int s = max({l, 0}); s < min({(j) + 1, N}); ++s) {






I[i][j][k][l][s] += I[ip][jp][kp][lp][sp];
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int j = 0; j < N; ++j) {

for (int k = 0; k < min({(i) + 1, N}); ++k) {

for (int s = max({i, 0}); s < min({(j) + 1, N}); ++s) {

for (int l = max({j, 0}); l < N; ++l) {






I[i][j][k][l][s] += I[ip][jp][kp][lp][sp];
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int j = 0; j < N; ++j) {

for (int k = 0; k < min({(i) + 1, N}); ++k) {

for (int l = 0; l < min({(j) + 1, N}); ++l) {

for (int s = max({i, 0}); s < min({(l) + 1, N}); ++s) {






I[i][j][k][l][s] += I[ip][jp][kp][lp][sp];
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int j = 0; j < N; ++j) {

for (int l = 0; l < min({(j) + 1, N}); ++l) {

for (int k = max({j, 0}); k < N; ++k) {

for (int s = max({k, 0}); s < min({(i) + 1, N}); ++s) {






I[i][j][k][l][s] += I[ip][jp][kp][lp][sp];
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int s = max({i, 0}); s < N; ++s) {

for (int j = 0; j < N; ++j) {

for (int l = 0; l < min({(j) + 1, N}); ++l) {

for (int k = max({j, 0}); k < min({(i) + 1, N}); ++k) {






I[i][j][k][l][s] += I[ip][jp][kp][lp][sp];
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int j = 0; j < N; ++j) {

for (int k = 0; k < min({(i) + 1, N}); ++k) {

for (int l = 0; l < min({(j) + 1, N}); ++l) {

for (int s = max({j, 0}); s < min({(k) + 1, N}); ++s) {






I[i][j][k][l][s] += I[ip][jp][kp][lp][sp];
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int j = 0; j < N; ++j) {

for (int k = max({i, 0}); k < N; ++k) {

for (int s = max({j, 0}); s < min({(i) + 1, N}); ++s) {

for (int l = 0; l < min({(j) + 1, N}); ++l) {






I[i][j][k][l][s] += I[ip][jp][kp][lp][sp];
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int j = 0; j < min({(i) + 1, N}); ++j) {

for (int k = max({i, 0}); k < N; ++k) {

for (int l = 0; l < min({(j) + 1, N}); ++l) {

for (int s = max({k, 0}); s < N; ++s) {






I[i][j][k][l][s] += I[ip][jp][kp][lp][sp];
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int j = 0; j < min({(i) + 1, N}); ++j) {

for (int l = 0; l < min({(j) + 1, N}); ++l) {

for (int k = 0; k < N; ++k) {

for (int s = max({i, 0}); s < min({(k) + 1, N}); ++s) {






I[i][j][k][l][s] += I[ip][jp][kp][lp][sp];
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int j = 0; j < N; ++j) {

for (int s = max({j, 0}); s < min({(i) + 1, N}); ++s) {

for (int k = 0; k < min({(j) + 1, N}); ++k) {

for (int l = 0; l < min({(k) + 1, N}); ++l) {






I[i][j][k][l][s] += I[ip][jp][kp][lp][sp];
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int s = max({i, 0}); s < N; ++s) {

for (int j = 0; j < min({(i) + 1, N}); ++j) {

for (int k = 0; k < min({(j) + 1, N}); ++k) {

for (int l = 0; l < min({(k) + 1, N}); ++l) {






I[i][j][k][l][s] += I[ip][jp][kp][lp][sp];
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int j = 0; j < min({(i) + 1, N}); ++j) {

for (int k = 0; k < N; ++k) {

for (int s = max({k, 0}); s < min({(j) + 1, N}); ++s) {

for (int l = 0; l < min({(k) + 1, N}); ++l) {






I[i][j][k][l][s] += I[ip][jp][kp][lp][sp];
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int j = max({i, 0}); j < N; ++j) {

for (int k = 0; k < N; ++k) {

for (int s = max({k, 0}); s < min({(i) + 1, N}); ++s) {

for (int l = 0; l < min({(k) + 1, N}); ++l) {






I[i][j][k][l][s] += I[ip][jp][kp][lp][sp];
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int j = max({i, 0}); j < N; ++j) {

for (int k = 0; k < min({(i) + 1, N}); ++k) {

for (int s = max({j, 0}); s < N; ++s) {

for (int l = 0; l < min({(k) + 1, N}); ++l) {






I[i][j][k][l][s] += I[ip][jp][kp][lp][sp];
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int j = 0; j < N; ++j) {

for (int k = 0; k < min({(i) + 1, N}); ++k) {

for (int s = max({i, 0}); s < min({(j) + 1, N}); ++s) {

for (int l = 0; l < min({(k) + 1, N}); ++l) {






I[i][j][k][l][s] += I[ip][jp][kp][lp][sp];
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int j = 0; j < N; ++j) {

for (int k = max({j, 0}); k < min({(i) + 1, N}); ++k) {

for (int l = 0; l < N; ++l) {

for (int s = max({l, 0}); s < min({(j) + 1, N}); ++s) {






I[i][j][k][l][s] += I[ip][jp][kp][lp][sp];
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int j = 0; j < min({(i) + 1, N}); ++j) {

for (int k = max({i, 0}); k < N; ++k) {

for (int l = 0; l < N; ++l) {

for (int s = max({l, 0}); s < min({(j) + 1, N}); ++s) {






I[i][j][k][l][s] += I[ip][jp][kp][lp][sp];
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int j = 0; j < min({(i) + 1, N}); ++j) {

for (int k = 0; k < min({(j) + 1, N}); ++k) {

for (int l = 0; l < N; ++l) {

for (int s = max({l, 0}); s < min({(k) + 1, N}); ++s) {






I[i][j][k][l][s] += I[ip][jp][kp][lp][sp];
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int j = max({i, 0}); j < N; ++j) {

for (int k = 0; k < min({(i) + 1, N}); ++k) {

for (int l = 0; l < N; ++l) {

for (int s = max({l, 0}); s < min({(k) + 1, N}); ++s) {






I[i][j][k][l][s] += I[ip][jp][kp][lp][sp];
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int j = max({i, 0}); j < N; ++j) {

for (int k = max({j, 0}); k < N; ++k) {

for (int l = 0; l < N; ++l) {

for (int s = max({l, 0}); s < min({(i) + 1, N}); ++s) {






I[i][j][k][l][s] += I[ip][jp][kp][lp][sp];
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int j = 0; j < N; ++j) {

for (int k = max({i, 0}); k < min({(j) + 1, N}); ++k) {

for (int l = 0; l < N; ++l) {

for (int s = max({l, 0}); s < min({(i) + 1, N}); ++s) {






I[i][j][k][l][s] += I[ip][jp][kp][lp][sp];
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int l = 0; l < min({(i) + 1, N}); ++l) {

for (int j = max({i, 0}); j < N; ++j) {

for (int k = max({j, 0}); k < N; ++k) {

for (int s = max({k, 0}); s < N; ++s) {






I[i][j][k][l][s] += I[ip][jp][kp][lp][sp];
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int l = 0; l < min({(i) + 1, N}); ++l) {

for (int j = max({i, 0}); j < N; ++j) {

for (int k = 0; k < N; ++k) {

for (int s = max({j, 0}); s < min({(k) + 1, N}); ++s) {






I[i][j][k][l][s] += I[ip][jp][kp][lp][sp];
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int l = 0; l < min({(i) + 1, N}); ++l) {

for (int j = 0; j < N; ++j) {

for (int s = max({j, 0}); s < N; ++s) {

for (int k = max({i, 0}); k < min({(j) + 1, N}); ++k) {






I[i][j][k][l][s] += I[ip][jp][kp][lp][sp];
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int l = 0; l < min({(i) + 1, N}); ++l) {

for (int k = max({i, 0}); k < N; ++k) {

for (int j = 0; j < N; ++j) {

for (int s = max({k, 0}); s < min({(j) + 1, N}); ++s) {






I[i][j][k][l][s] += I[ip][jp][kp][lp][sp];
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int l = 0; l < min({(i) + 1, N}); ++l) {

for (int j = 0; j < N; ++j) {

for (int s = max({i, 0}); s < min({(j) + 1, N}); ++s) {

for (int k = max({j, 0}); k < N; ++k) {






I[i][j][k][l][s] += I[ip][jp][kp][lp][sp];
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int l = 0; l < min({(i) + 1, N}); ++l) {

for (int j = 0; j < N; ++j) {

for (int k = 0; k < min({(j) + 1, N}); ++k) {

for (int s = max({i, 0}); s < min({(k) + 1, N}); ++s) {






I[i][j][k][l][s] += I[ip][jp][kp][lp][sp];
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int j = 0; j < N; ++j) {

for (int s = 0; s < min({(j) + 1, N}); ++s) {

for (int k = max({j, 0}); k < N; ++k) {

for (int l = max({k, 0}); l < min({(i) + 1, N}); ++l) {






I[i][j][k][l][s] += I[ip][jp][kp][lp][sp];
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int l = max({i, 0}); l < N; ++l) {

for (int j = 0; j < N; ++j) {

for (int s = 0; s < min({(j) + 1, N}); ++s) {

for (int k = max({j, 0}); k < min({(i) + 1, N}); ++k) {






I[i][j][k][l][s] += I[ip][jp][kp][lp][sp];
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int j = 0; j < N; ++j) {

for (int k = 0; k < min({(i) + 1, N}); ++k) {

for (int s = 0; s < min({(j) + 1, N}); ++s) {

for (int l = max({j, 0}); l < min({(k) + 1, N}); ++l) {






I[i][j][k][l][s] += I[ip][jp][kp][lp][sp];
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int j = 0; j < N; ++j) {

for (int k = max({i, 0}); k < N; ++k) {

for (int s = 0; s < min({(j) + 1, N}); ++s) {

for (int l = max({j, 0}); l < min({(i) + 1, N}); ++l) {






I[i][j][k][l][s] += I[ip][jp][kp][lp][sp];
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int j = 0; j < min({(i) + 1, N}); ++j) {

for (int k = max({i, 0}); k < N; ++k) {

for (int s = 0; s < min({(j) + 1, N}); ++s) {

for (int l = max({k, 0}); l < N; ++l) {






I[i][j][k][l][s] += I[ip][jp][kp][lp][sp];
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int j = 0; j < min({(i) + 1, N}); ++j) {

for (int s = 0; s < min({(j) + 1, N}); ++s) {

for (int k = 0; k < N; ++k) {

for (int l = max({i, 0}); l < min({(k) + 1, N}); ++l) {






I[i][j][k][l][s] += I[ip][jp][kp][lp][sp];
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int j = 0; j < N; ++j) {

for (int l = max({j, 0}); l < min({(i) + 1, N}); ++l) {

for (int k = 0; k < min({(j) + 1, N}); ++k) {

for (int s = 0; s < min({(k) + 1, N}); ++s) {






I[i][j][k][l][s] += I[ip][jp][kp][lp][sp];
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int l = max({i, 0}); l < N; ++l) {

for (int j = 0; j < min({(i) + 1, N}); ++j) {

for (int k = 0; k < min({(j) + 1, N}); ++k) {

for (int s = 0; s < min({(k) + 1, N}); ++s) {






I[i][j][k][l][s] += I[ip][jp][kp][lp][sp];
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int j = 0; j < min({(i) + 1, N}); ++j) {

for (int k = 0; k < N; ++k) {

for (int s = 0; s < min({(k) + 1, N}); ++s) {

for (int l = max({k, 0}); l < min({(j) + 1, N}); ++l) {






I[i][j][k][l][s] += I[ip][jp][kp][lp][sp];
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int j = max({i, 0}); j < N; ++j) {

for (int k = 0; k < N; ++k) {

for (int s = 0; s < min({(k) + 1, N}); ++s) {

for (int l = max({k, 0}); l < min({(i) + 1, N}); ++l) {






I[i][j][k][l][s] += I[ip][jp][kp][lp][sp];
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int j = max({i, 0}); j < N; ++j) {

for (int k = 0; k < min({(i) + 1, N}); ++k) {

for (int l = max({j, 0}); l < N; ++l) {

for (int s = 0; s < min({(k) + 1, N}); ++s) {






I[i][j][k][l][s] += I[ip][jp][kp][lp][sp];
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int j = 0; j < N; ++j) {

for (int k = 0; k < min({(i) + 1, N}); ++k) {

for (int l = max({i, 0}); l < min({(j) + 1, N}); ++l) {

for (int s = 0; s < min({(k) + 1, N}); ++s) {






I[i][j][k][l][s] += I[ip][jp][kp][lp][sp];
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int j = 0; j < N; ++j) {

for (int l = 0; l < min({(j) + 1, N}); ++l) {

for (int k = max({j, 0}); k < min({(i) + 1, N}); ++k) {

for (int s = 0; s < min({(l) + 1, N}); ++s) {






I[i][j][k][l][s] += I[ip][jp][kp][lp][sp];
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int j = 0; j < min({(i) + 1, N}); ++j) {

for (int k = max({i, 0}); k < N; ++k) {

for (int l = 0; l < min({(j) + 1, N}); ++l) {

for (int s = 0; s < min({(l) + 1, N}); ++s) {






I[i][j][k][l][s] += I[ip][jp][kp][lp][sp];
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int j = 0; j < min({(i) + 1, N}); ++j) {

for (int k = 0; k < min({(j) + 1, N}); ++k) {

for (int l = 0; l < min({(k) + 1, N}); ++l) {

for (int s = 0; s < min({(l) + 1, N}); ++s) {






I[i][j][k][l][s] += I[ip][jp][kp][lp][sp];
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int j = max({i, 0}); j < N; ++j) {

for (int k = 0; k < min({(i) + 1, N}); ++k) {

for (int l = 0; l < min({(k) + 1, N}); ++l) {

for (int s = 0; s < min({(l) + 1, N}); ++s) {






I[i][j][k][l][s] += I[ip][jp][kp][lp][sp];
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int l = 0; l < min({(i) + 1, N}); ++l) {

for (int j = max({i, 0}); j < N; ++j) {

for (int s = 0; s < min({(l) + 1, N}); ++s) {

for (int k = max({j, 0}); k < N; ++k) {






I[i][j][k][l][s] += I[ip][jp][kp][lp][sp];
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int l = 0; l < min({(i) + 1, N}); ++l) {

for (int s = 0; s < min({(l) + 1, N}); ++s) {

for (int j = 0; j < N; ++j) {

for (int k = max({i, 0}); k < min({(j) + 1, N}); ++k) {






I[i][j][k][l][s] += I[ip][jp][kp][lp][sp];
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int s = 0; s < min({(i) + 1, N}); ++s) {

for (int j = max({i, 0}); j < N; ++j) {

for (int k = max({j, 0}); k < N; ++k) {

for (int l = max({k, 0}); l < N; ++l) {






I[i][j][k][l][s] += I[ip][jp][kp][lp][sp];
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int s = 0; s < min({(i) + 1, N}); ++s) {

for (int j = max({i, 0}); j < N; ++j) {

for (int k = 0; k < N; ++k) {

for (int l = max({j, 0}); l < min({(k) + 1, N}); ++l) {






I[i][j][k][l][s] += I[ip][jp][kp][lp][sp];
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int s = 0; s < min({(i) + 1, N}); ++s) {

for (int j = 0; j < N; ++j) {

for (int l = max({j, 0}); l < N; ++l) {

for (int k = max({i, 0}); k < min({(j) + 1, N}); ++k) {






I[i][j][k][l][s] += I[ip][jp][kp][lp][sp];
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int s = 0; s < min({(i) + 1, N}); ++s) {

for (int k = max({i, 0}); k < N; ++k) {

for (int j = 0; j < N; ++j) {

for (int l = max({k, 0}); l < min({(j) + 1, N}); ++l) {






I[i][j][k][l][s] += I[ip][jp][kp][lp][sp];
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int s = 0; s < min({(i) + 1, N}); ++s) {

for (int j = 0; j < N; ++j) {

for (int l = max({i, 0}); l < min({(j) + 1, N}); ++l) {

for (int k = max({j, 0}); k < N; ++k) {






I[i][j][k][l][s] += I[ip][jp][kp][lp][sp];
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int s = 0; s < min({(i) + 1, N}); ++s) {

for (int j = 0; j < N; ++j) {

for (int k = 0; k < min({(j) + 1, N}); ++k) {

for (int l = max({i, 0}); l < min({(k) + 1, N}); ++l) {






I[i][j][k][l][s] += I[ip][jp][kp][lp][sp];
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int j = max({i, 0}); j < N; ++j) {

for (int k = max({j, 0}); k < N; ++k) {

for (int l = max({k, 0}); l < N; ++l) {

for (int s = max({l, 0}); s < N; ++s) {






I[i][j][k][l][s] += I[ip][jp][kp][lp][sp];
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int j = max({i, 0}); j < N; ++j) {

for (int k = max({j, 0}); k < N; ++k) {

for (int l = 0; l < N; ++l) {

for (int s = max({k, 0}); s < min({(l) + 1, N}); ++s) {






I[i][j][k][l][s] += I[ip][jp][kp][lp][sp];
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int j = max({i, 0}); j < N; ++j) {

for (int k = 0; k < N; ++k) {

for (int s = max({k, 0}); s < N; ++s) {

for (int l = max({j, 0}); l < min({(k) + 1, N}); ++l) {






I[i][j][k][l][s] += I[ip][jp][kp][lp][sp];
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int j = max({i, 0}); j < N; ++j) {

for (int l = max({j, 0}); l < N; ++l) {

for (int k = 0; k < N; ++k) {

for (int s = max({l, 0}); s < min({(k) + 1, N}); ++s) {






I[i][j][k][l][s] += I[ip][jp][kp][lp][sp];
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int j = max({i, 0}); j < N; ++j) {

for (int k = 0; k < N; ++k) {

for (int s = max({j, 0}); s < min({(k) + 1, N}); ++s) {

for (int l = max({k, 0}); l < N; ++l) {






I[i][j][k][l][s] += I[ip][jp][kp][lp][sp];
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int j = max({i, 0}); j < N; ++j) {

for (int k = 0; k < N; ++k) {

for (int l = 0; l < min({(k) + 1, N}); ++l) {

for (int s = max({j, 0}); s < min({(l) + 1, N}); ++s) {






I[i][j][k][l][s] += I[ip][jp][kp][lp][sp];
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int j = 0; j < N; ++j) {

for (int l = max({j, 0}); l < N; ++l) {

for (int k = max({i, 0}); k < min({(j) + 1, N}); ++k) {

for (int s = max({l, 0}); s < N; ++s) {






I[i][j][k][l][s] += I[ip][jp][kp][lp][sp];
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int j = 0; j < N; ++j) {

for (int k = max({i, 0}); k < min({(j) + 1, N}); ++k) {

for (int l = 0; l < N; ++l) {

for (int s = max({j, 0}); s < min({(l) + 1, N}); ++s) {






I[i][j][k][l][s] += I[ip][jp][kp][lp][sp];
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int j = 0; j < N; ++j) {

for (int k = max({i, 0}); k < N; ++k) {

for (int s = max({j, 0}); s < N; ++s) {

for (int l = max({k, 0}); l < min({(j) + 1, N}); ++l) {






I[i][j][k][l][s] += I[ip][jp][kp][lp][sp];
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int j = 0; j < N; ++j) {

for (int k = max({i, 0}); k < N; ++k) {

for (int l = max({k, 0}); l < N; ++l) {

for (int s = max({l, 0}); s < min({(j) + 1, N}); ++s) {






I[i][j][k][l][s] += I[ip][jp][kp][lp][sp];
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int j = 0; j < N; ++j) {

for (int k = max({i, 0}); k < N; ++k) {

for (int l = max({j, 0}); l < N; ++l) {

for (int s = max({k, 0}); s < min({(j) + 1, N}); ++s) {






I[i][j][k][l][s] += I[ip][jp][kp][lp][sp];
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int j = 0; j < N; ++j) {

for (int k = max({i, 0}); k < N; ++k) {

for (int l = 0; l < min({(j) + 1, N}); ++l) {

for (int s = max({k, 0}); s < min({(l) + 1, N}); ++s) {






I[i][j][k][l][s] += I[ip][jp][kp][lp][sp];
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int j = 0; j < N; ++j) {

for (int l = max({i, 0}); l < min({(j) + 1, N}); ++l) {

for (int k = max({j, 0}); k < N; ++k) {

for (int s = max({k, 0}); s < N; ++s) {






I[i][j][k][l][s] += I[ip][jp][kp][lp][sp];
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int j = 0; j < N; ++j) {

for (int l = max({i, 0}); l < min({(j) + 1, N}); ++l) {

for (int k = 0; k < N; ++k) {

for (int s = max({j, 0}); s < min({(k) + 1, N}); ++s) {






I[i][j][k][l][s] += I[ip][jp][kp][lp][sp];
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int j = 0; j < N; ++j) {

for (int s = max({j, 0}); s < N; ++s) {

for (int k = 0; k < min({(j) + 1, N}); ++k) {

for (int l = max({i, 0}); l < min({(k) + 1, N}); ++l) {






I[i][j][k][l][s] += I[ip][jp][kp][lp][sp];
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int j = 0; j < N; ++j) {

for (int k = 0; k < N; ++k) {

for (int s = max({k, 0}); s < min({(j) + 1, N}); ++s) {

for (int l = max({i, 0}); l < min({(k) + 1, N}); ++l) {






I[i][j][k][l][s] += I[ip][jp][kp][lp][sp];
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int l = max({i, 0}); l < N; ++l) {

for (int j = 0; j < N; ++j) {

for (int s = max({l, 0}); s < min({(j) + 1, N}); ++s) {

for (int k = max({j, 0}); k < N; ++k) {






I[i][j][k][l][s] += I[ip][jp][kp][lp][sp];
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int l = max({i, 0}); l < N; ++l) {

for (int j = 0; j < N; ++j) {

for (int k = 0; k < min({(j) + 1, N}); ++k) {

for (int s = max({l, 0}); s < min({(k) + 1, N}); ++s) {






I[i][j][k][l][s] += I[ip][jp][kp][lp][sp];
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int j = 0; j < N; ++j) {

for (int s = max({i, 0}); s < min({(j) + 1, N}); ++s) {

for (int k = max({j, 0}); k < N; ++k) {

for (int l = max({k, 0}); l < N; ++l) {






I[i][j][k][l][s] += I[ip][jp][kp][lp][sp];
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int j = 0; j < N; ++j) {

for (int s = max({i, 0}); s < min({(j) + 1, N}); ++s) {

for (int k = 0; k < N; ++k) {

for (int l = max({j, 0}); l < min({(k) + 1, N}); ++l) {






I[i][j][k][l][s] += I[ip][jp][kp][lp][sp];
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int j = 0; j < N; ++j) {

for (int l = max({j, 0}); l < N; ++l) {

for (int k = 0; k < min({(j) + 1, N}); ++k) {

for (int s = max({i, 0}); s < min({(k) + 1, N}); ++s) {






I[i][j][k][l][s] += I[ip][jp][kp][lp][sp];
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int j = 0; j < N; ++j) {

for (int k = 0; k < N; ++k) {

for (int s = max({i, 0}); s < min({(k) + 1, N}); ++s) {

for (int l = max({k, 0}); l < min({(j) + 1, N}); ++l) {






I[i][j][k][l][s] += I[ip][jp][kp][lp][sp];
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int j = 0; j < N; ++j) {

for (int l = 0; l < min({(j) + 1, N}); ++l) {

for (int k = max({j, 0}); k < N; ++k) {

for (int s = max({i, 0}); s < min({(l) + 1, N}); ++s) {






I[i][j][k][l][s] += I[ip][jp][kp][lp][sp];
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int j = 0; j < N; ++j) {

for (int k = 0; k < min({(j) + 1, N}); ++k) {

for (int l = 0; l < min({(k) + 1, N}); ++l) {

for (int s = max({i, 0}); s < min({(l) + 1, N}); ++s) {






I[i][j][k][l][s] += I[ip][jp][kp][lp][sp];
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int t = max({i, 0}); t < N; ++t) {

for (int j = 0; j < N; ++j) {

for (int k = max({j, 0}); k < N; ++k) {

for (int l = max({k, 0}); l < N; ++l) {

for (int s = max({l, 0}); s < min({(i) + 1, N}); ++s) {







J[i][j][k][l][s][t] += J[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int s = 0; s < min({(i) + 1, N}); ++s) {

for (int j = 0; j < N; ++j) {

for (int k = max({j, 0}); k < N; ++k) {

for (int l = max({k, 0}); l < N; ++l) {

for (int t = max({l, 0}); t < min({(s) + 1, N}); ++t) {







J[i][j][k][l][s][t] += J[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int s = max({i, 0}); s < N; ++s) {

for (int j = 0; j < N; ++j) {

for (int k = max({j, 0}); k < N; ++k) {

for (int l = max({k, 0}); l < N; ++l) {

for (int t = max({l, 0}); t < min({(i) + 1, N}); ++t) {







J[i][j][k][l][s][t] += J[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int s = max({i, 0}); s < N; ++s) {

for (int t = max({s, 0}); t < N; ++t) {

for (int j = 0; j < N; ++j) {

for (int k = max({j, 0}); k < N; ++k) {

for (int l = max({k, 0}); l < min({(i) + 1, N}); ++l) {







J[i][j][k][l][s][t] += J[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int j = 0; j < N; ++j) {

for (int k = max({j, 0}); k < N; ++k) {

for (int l = max({k, 0}); l < min({(i) + 1, N}); ++l) {

for (int s = 0; s < N; ++s) {

for (int t = max({i, 0}); t < min({(s) + 1, N}); ++t) {







J[i][j][k][l][s][t] += J[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int j = 0; j < N; ++j) {

for (int k = max({j, 0}); k < N; ++k) {

for (int l = 0; l < N; ++l) {

for (int s = max({k, 0}); s < min({(l) + 1, N}); ++s) {

for (int t = max({l, 0}); t < min({(i) + 1, N}); ++t) {







J[i][j][k][l][s][t] += J[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int t = max({i, 0}); t < N; ++t) {

for (int l = 0; l < min({(i) + 1, N}); ++l) {

for (int j = 0; j < N; ++j) {

for (int k = max({j, 0}); k < N; ++k) {

for (int s = max({k, 0}); s < min({(l) + 1, N}); ++s) {







J[i][j][k][l][s][t] += J[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int l = 0; l < min({(i) + 1, N}); ++l) {

for (int j = 0; j < N; ++j) {

for (int k = max({j, 0}); k < N; ++k) {

for (int s = max({k, 0}); s < N; ++s) {

for (int t = max({s, 0}); t < min({(l) + 1, N}); ++t) {







J[i][j][k][l][s][t] += J[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int l = max({i, 0}); l < N; ++l) {

for (int j = 0; j < N; ++j) {

for (int k = max({j, 0}); k < N; ++k) {

for (int s = max({k, 0}); s < N; ++s) {

for (int t = max({s, 0}); t < min({(i) + 1, N}); ++t) {







J[i][j][k][l][s][t] += J[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int l = max({i, 0}); l < N; ++l) {

for (int t = max({l, 0}); t < N; ++t) {

for (int j = 0; j < N; ++j) {

for (int k = max({j, 0}); k < N; ++k) {

for (int s = max({k, 0}); s < min({(i) + 1, N}); ++s) {







J[i][j][k][l][s][t] += J[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int j = 0; j < N; ++j) {

for (int k = max({j, 0}); k < N; ++k) {

for (int s = max({k, 0}); s < min({(i) + 1, N}); ++s) {

for (int l = 0; l < N; ++l) {

for (int t = max({i, 0}); t < min({(l) + 1, N}); ++t) {







J[i][j][k][l][s][t] += J[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int j = 0; j < N; ++j) {

for (int k = max({j, 0}); k < N; ++k) {

for (int l = 0; l < N; ++l) {

for (int s = max({l, 0}); s < min({(i) + 1, N}); ++s) {

for (int t = max({k, 0}); t < min({(l) + 1, N}); ++t) {







J[i][j][k][l][s][t] += J[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int s = max({i, 0}); s < N; ++s) {

for (int l = 0; l < min({(i) + 1, N}); ++l) {

for (int j = 0; j < N; ++j) {

for (int k = max({j, 0}); k < N; ++k) {

for (int t = max({k, 0}); t < min({(l) + 1, N}); ++t) {







J[i][j][k][l][s][t] += J[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int l = 0; l < min({(i) + 1, N}); ++l) {

for (int s = 0; s < min({(l) + 1, N}); ++s) {

for (int j = 0; j < N; ++j) {

for (int k = max({j, 0}); k < N; ++k) {

for (int t = max({k, 0}); t < min({(s) + 1, N}); ++t) {







J[i][j][k][l][s][t] += J[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int s = 0; s < min({(i) + 1, N}); ++s) {

for (int l = max({i, 0}); l < N; ++l) {

for (int j = 0; j < N; ++j) {

for (int k = max({j, 0}); k < N; ++k) {

for (int t = max({k, 0}); t < min({(s) + 1, N}); ++t) {







J[i][j][k][l][s][t] += J[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int l = max({i, 0}); l < N; ++l) {

for (int s = max({l, 0}); s < N; ++s) {

for (int j = 0; j < N; ++j) {

for (int k = max({j, 0}); k < N; ++k) {

for (int t = max({k, 0}); t < min({(i) + 1, N}); ++t) {







J[i][j][k][l][s][t] += J[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int j = 0; j < N; ++j) {

for (int k = max({j, 0}); k < N; ++k) {

for (int t = max({k, 0}); t < min({(i) + 1, N}); ++t) {

for (int l = 0; l < N; ++l) {

for (int s = max({i, 0}); s < min({(l) + 1, N}); ++s) {







J[i][j][k][l][s][t] += J[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int l = max({i, 0}); l < N; ++l) {

for (int s = max({l, 0}); s < N; ++s) {

for (int t = max({s, 0}); t < N; ++t) {

for (int j = 0; j < N; ++j) {

for (int k = max({j, 0}); k < min({(i) + 1, N}); ++k) {







J[i][j][k][l][s][t] += J[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int l = max({i, 0}); l < N; ++l) {

for (int j = 0; j < N; ++j) {

for (int k = max({j, 0}); k < min({(i) + 1, N}); ++k) {

for (int s = 0; s < N; ++s) {

for (int t = max({l, 0}); t < min({(s) + 1, N}); ++t) {







J[i][j][k][l][s][t] += J[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int j = 0; j < N; ++j) {

for (int k = max({j, 0}); k < min({(i) + 1, N}); ++k) {

for (int l = 0; l < N; ++l) {

for (int s = max({i, 0}); s < min({(l) + 1, N}); ++s) {

for (int t = max({l, 0}); t < N; ++t) {







J[i][j][k][l][s][t] += J[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int s = max({i, 0}); s < N; ++s) {

for (int j = 0; j < N; ++j) {

for (int k = max({j, 0}); k < min({(i) + 1, N}); ++k) {

for (int l = 0; l < N; ++l) {

for (int t = max({s, 0}); t < min({(l) + 1, N}); ++t) {







J[i][j][k][l][s][t] += J[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int j = 0; j < N; ++j) {

for (int k = max({j, 0}); k < min({(i) + 1, N}); ++k) {

for (int l = 0; l < N; ++l) {

for (int s = max({l, 0}); s < N; ++s) {

for (int t = max({i, 0}); t < min({(l) + 1, N}); ++t) {







J[i][j][k][l][s][t] += J[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int j = 0; j < N; ++j) {

for (int k = max({j, 0}); k < min({(i) + 1, N}); ++k) {

for (int l = 0; l < N; ++l) {

for (int s = 0; s < min({(l) + 1, N}); ++s) {

for (int t = max({i, 0}); t < min({(s) + 1, N}); ++t) {







J[i][j][k][l][s][t] += J[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int j = 0; j < N; ++j) {

for (int k = 0; k < N; ++k) {

for (int s = max({k, 0}); s < N; ++s) {

for (int l = max({j, 0}); l < min({(k) + 1, N}); ++l) {

for (int t = max({s, 0}); t < min({(i) + 1, N}); ++t) {







J[i][j][k][l][s][t] += J[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int t = max({i, 0}); t < N; ++t) {

for (int j = 0; j < N; ++j) {

for (int k = 0; k < N; ++k) {

for (int s = max({k, 0}); s < min({(i) + 1, N}); ++s) {

for (int l = max({j, 0}); l < min({(k) + 1, N}); ++l) {







J[i][j][k][l][s][t] += J[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int s = 0; s < min({(i) + 1, N}); ++s) {

for (int j = 0; j < N; ++j) {

for (int k = 0; k < N; ++k) {

for (int t = max({k, 0}); t < min({(s) + 1, N}); ++t) {

for (int l = max({j, 0}); l < min({(k) + 1, N}); ++l) {







J[i][j][k][l][s][t] += J[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int s = max({i, 0}); s < N; ++s) {

for (int j = 0; j < N; ++j) {

for (int k = 0; k < N; ++k) {

for (int t = max({k, 0}); t < min({(i) + 1, N}); ++t) {

for (int l = max({j, 0}); l < min({(k) + 1, N}); ++l) {







J[i][j][k][l][s][t] += J[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int s = max({i, 0}); s < N; ++s) {

for (int k = 0; k < min({(i) + 1, N}); ++k) {

for (int t = max({s, 0}); t < N; ++t) {

for (int j = 0; j < N; ++j) {

for (int l = max({j, 0}); l < min({(k) + 1, N}); ++l) {







J[i][j][k][l][s][t] += J[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int j = 0; j < N; ++j) {

for (int k = 0; k < min({(i) + 1, N}); ++k) {

for (int l = max({j, 0}); l < min({(k) + 1, N}); ++l) {

for (int s = 0; s < N; ++s) {

for (int t = max({i, 0}); t < min({(s) + 1, N}); ++t) {







J[i][j][k][l][s][t] += J[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int j = 0; j < N; ++j) {

for (int l = max({j, 0}); l < N; ++l) {

for (int k = 0; k < N; ++k) {

for (int s = max({l, 0}); s < min({(k) + 1, N}); ++s) {

for (int t = max({k, 0}); t < min({(i) + 1, N}); ++t) {







J[i][j][k][l][s][t] += J[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int t = max({i, 0}); t < N; ++t) {

for (int k = 0; k < min({(i) + 1, N}); ++k) {

for (int j = 0; j < N; ++j) {

for (int l = max({j, 0}); l < N; ++l) {

for (int s = max({l, 0}); s < min({(k) + 1, N}); ++s) {







J[i][j][k][l][s][t] += J[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int j = 0; j < N; ++j) {

for (int k = 0; k < min({(i) + 1, N}); ++k) {

for (int l = max({j, 0}); l < N; ++l) {

for (int s = max({l, 0}); s < N; ++s) {

for (int t = max({s, 0}); t < min({(k) + 1, N}); ++t) {







J[i][j][k][l][s][t] += J[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int j = 0; j < N; ++j) {

for (int k = max({i, 0}); k < N; ++k) {

for (int l = max({j, 0}); l < N; ++l) {

for (int s = max({l, 0}); s < N; ++s) {

for (int t = max({s, 0}); t < min({(i) + 1, N}); ++t) {







J[i][j][k][l][s][t] += J[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int j = 0; j < N; ++j) {

for (int k = max({i, 0}); k < N; ++k) {

for (int l = max({j, 0}); l < N; ++l) {

for (int t = max({k, 0}); t < N; ++t) {

for (int s = max({l, 0}); s < min({(i) + 1, N}); ++s) {







J[i][j][k][l][s][t] += J[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int j = 0; j < N; ++j) {

for (int l = max({j, 0}); l < N; ++l) {

for (int s = max({l, 0}); s < min({(i) + 1, N}); ++s) {

for (int k = 0; k < N; ++k) {

for (int t = max({i, 0}); t < min({(k) + 1, N}); ++t) {







J[i][j][k][l][s][t] += J[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int j = 0; j < N; ++j) {

for (int l = max({j, 0}); l < N; ++l) {

for (int k = 0; k < N; ++k) {

for (int s = max({k, 0}); s < min({(i) + 1, N}); ++s) {

for (int t = max({l, 0}); t < min({(k) + 1, N}); ++t) {







J[i][j][k][l][s][t] += J[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int s = max({i, 0}); s < N; ++s) {

for (int k = 0; k < min({(i) + 1, N}); ++k) {

for (int j = 0; j < N; ++j) {

for (int l = max({j, 0}); l < N; ++l) {

for (int t = max({l, 0}); t < min({(k) + 1, N}); ++t) {







J[i][j][k][l][s][t] += J[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int j = 0; j < N; ++j) {

for (int k = 0; k < min({(i) + 1, N}); ++k) {

for (int l = max({j, 0}); l < N; ++l) {

for (int s = 0; s < min({(k) + 1, N}); ++s) {

for (int t = max({l, 0}); t < min({(s) + 1, N}); ++t) {







J[i][j][k][l][s][t] += J[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int s = 0; s < min({(i) + 1, N}); ++s) {

for (int k = max({i, 0}); k < N; ++k) {

for (int j = 0; j < N; ++j) {

for (int l = max({j, 0}); l < N; ++l) {

for (int t = max({l, 0}); t < min({(s) + 1, N}); ++t) {







J[i][j][k][l][s][t] += J[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int j = 0; j < N; ++j) {

for (int k = max({i, 0}); k < N; ++k) {

for (int l = max({j, 0}); l < N; ++l) {

for (int s = max({k, 0}); s < N; ++s) {

for (int t = max({l, 0}); t < min({(i) + 1, N}); ++t) {







J[i][j][k][l][s][t] += J[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int j = 0; j < N; ++j) {

for (int l = max({j, 0}); l < N; ++l) {

for (int t = max({l, 0}); t < min({(i) + 1, N}); ++t) {

for (int k = 0; k < N; ++k) {

for (int s = max({i, 0}); s < min({(k) + 1, N}); ++s) {







J[i][j][k][l][s][t] += J[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int j = 0; j < N; ++j) {

for (int k = max({i, 0}); k < N; ++k) {

for (int l = max({j, 0}); l < min({(i) + 1, N}); ++l) {

for (int s = max({k, 0}); s < N; ++s) {

for (int t = max({s, 0}); t < N; ++t) {







J[i][j][k][l][s][t] += J[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int j = 0; j < N; ++j) {

for (int k = max({i, 0}); k < N; ++k) {

for (int l = max({j, 0}); l < min({(i) + 1, N}); ++l) {

for (int s = 0; s < N; ++s) {

for (int t = max({k, 0}); t < min({(s) + 1, N}); ++t) {







J[i][j][k][l][s][t] += J[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int j = 0; j < N; ++j) {

for (int l = max({j, 0}); l < min({(i) + 1, N}); ++l) {

for (int k = 0; k < N; ++k) {

for (int s = max({i, 0}); s < min({(k) + 1, N}); ++s) {

for (int t = max({k, 0}); t < N; ++t) {







J[i][j][k][l][s][t] += J[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int s = max({i, 0}); s < N; ++s) {

for (int j = 0; j < N; ++j) {

for (int l = max({j, 0}); l < min({(i) + 1, N}); ++l) {

for (int k = 0; k < N; ++k) {

for (int t = max({s, 0}); t < min({(k) + 1, N}); ++t) {







J[i][j][k][l][s][t] += J[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int j = 0; j < N; ++j) {

for (int l = max({j, 0}); l < min({(i) + 1, N}); ++l) {

for (int k = 0; k < N; ++k) {

for (int s = max({k, 0}); s < N; ++s) {

for (int t = max({i, 0}); t < min({(k) + 1, N}); ++t) {







J[i][j][k][l][s][t] += J[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int j = 0; j < N; ++j) {

for (int l = max({j, 0}); l < min({(i) + 1, N}); ++l) {

for (int k = 0; k < N; ++k) {

for (int s = 0; s < min({(k) + 1, N}); ++s) {

for (int t = max({i, 0}); t < min({(s) + 1, N}); ++t) {







J[i][j][k][l][s][t] += J[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int j = 0; j < N; ++j) {

for (int k = 0; k < N; ++k) {

for (int s = max({j, 0}); s < min({(k) + 1, N}); ++s) {

for (int l = max({k, 0}); l < N; ++l) {

for (int t = max({l, 0}); t < min({(i) + 1, N}); ++t) {







J[i][j][k][l][s][t] += J[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int t = max({i, 0}); t < N; ++t) {

for (int j = 0; j < N; ++j) {

for (int k = 0; k < N; ++k) {

for (int s = max({j, 0}); s < min({(k) + 1, N}); ++s) {

for (int l = max({k, 0}); l < min({(i) + 1, N}); ++l) {







J[i][j][k][l][s][t] += J[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int l = 0; l < min({(i) + 1, N}); ++l) {

for (int j = 0; j < N; ++j) {

for (int k = 0; k < N; ++k) {

for (int s = max({j, 0}); s < min({(k) + 1, N}); ++s) {

for (int t = max({k, 0}); t < min({(l) + 1, N}); ++t) {







J[i][j][k][l][s][t] += J[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int l = max({i, 0}); l < N; ++l) {

for (int j = 0; j < N; ++j) {

for (int k = 0; k < N; ++k) {

for (int s = max({j, 0}); s < min({(k) + 1, N}); ++s) {

for (int t = max({k, 0}); t < min({(i) + 1, N}); ++t) {







J[i][j][k][l][s][t] += J[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int l = max({i, 0}); l < N; ++l) {

for (int k = 0; k < min({(i) + 1, N}); ++k) {

for (int t = max({l, 0}); t < N; ++t) {

for (int j = 0; j < N; ++j) {

for (int s = max({j, 0}); s < min({(k) + 1, N}); ++s) {







J[i][j][k][l][s][t] += J[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int j = 0; j < N; ++j) {

for (int k = 0; k < min({(i) + 1, N}); ++k) {

for (int s = max({j, 0}); s < min({(k) + 1, N}); ++s) {

for (int l = 0; l < N; ++l) {

for (int t = max({i, 0}); t < min({(l) + 1, N}); ++t) {







J[i][j][k][l][s][t] += J[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int j = 0; j < N; ++j) {

for (int k = 0; k < N; ++k) {

for (int t = max({k, 0}); t < min({(i) + 1, N}); ++t) {

for (int l = 0; l < min({(k) + 1, N}); ++l) {

for (int s = max({j, 0}); s < min({(l) + 1, N}); ++s) {







J[i][j][k][l][s][t] += J[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int t = max({i, 0}); t < N; ++t) {

for (int k = 0; k < min({(i) + 1, N}); ++k) {

for (int l = 0; l < min({(k) + 1, N}); ++l) {

for (int j = 0; j < N; ++j) {

for (int s = max({j, 0}); s < min({(l) + 1, N}); ++s) {







J[i][j][k][l][s][t] += J[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int j = 0; j < N; ++j) {

for (int k = 0; k < min({(i) + 1, N}); ++k) {

for (int l = 0; l < N; ++l) {

for (int s = max({j, 0}); s < min({(l) + 1, N}); ++s) {

for (int t = max({l, 0}); t < min({(k) + 1, N}); ++t) {







J[i][j][k][l][s][t] += J[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int j = 0; j < N; ++j) {

for (int k = max({i, 0}); k < N; ++k) {

for (int l = 0; l < N; ++l) {

for (int s = max({j, 0}); s < min({(l) + 1, N}); ++s) {

for (int t = max({l, 0}); t < min({(i) + 1, N}); ++t) {







J[i][j][k][l][s][t] += J[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int l = 0; l < min({(i) + 1, N}); ++l) {

for (int k = max({i, 0}); k < N; ++k) {

for (int t = max({k, 0}); t < N; ++t) {

for (int j = 0; j < N; ++j) {

for (int s = max({j, 0}); s < min({(l) + 1, N}); ++s) {







J[i][j][k][l][s][t] += J[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int l = 0; l < min({(i) + 1, N}); ++l) {

for (int j = 0; j < N; ++j) {

for (int s = max({j, 0}); s < min({(l) + 1, N}); ++s) {

for (int k = 0; k < N; ++k) {

for (int t = max({i, 0}); t < min({(k) + 1, N}); ++t) {







J[i][j][k][l][s][t] += J[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int j = 0; j < N; ++j) {

for (int s = max({j, 0}); s < N; ++s) {

for (int k = 0; k < N; ++k) {

for (int t = max({s, 0}); t < min({(k) + 1, N}); ++t) {

for (int l = max({k, 0}); l < min({(i) + 1, N}); ++l) {







J[i][j][k][l][s][t] += J[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int l = max({i, 0}); l < N; ++l) {

for (int k = 0; k < min({(i) + 1, N}); ++k) {

for (int j = 0; j < N; ++j) {

for (int s = max({j, 0}); s < N; ++s) {

for (int t = max({s, 0}); t < min({(k) + 1, N}); ++t) {







J[i][j][k][l][s][t] += J[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int j = 0; j < N; ++j) {

for (int k = 0; k < min({(i) + 1, N}); ++k) {

for (int s = max({j, 0}); s < N; ++s) {

for (int l = 0; l < min({(k) + 1, N}); ++l) {

for (int t = max({s, 0}); t < min({(l) + 1, N}); ++t) {







J[i][j][k][l][s][t] += J[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int l = 0; l < min({(i) + 1, N}); ++l) {

for (int k = max({i, 0}); k < N; ++k) {

for (int j = 0; j < N; ++j) {

for (int s = max({j, 0}); s < N; ++s) {

for (int t = max({s, 0}); t < min({(l) + 1, N}); ++t) {







J[i][j][k][l][s][t] += J[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int j = 0; j < N; ++j) {

for (int k = max({i, 0}); k < N; ++k) {

for (int s = max({j, 0}); s < N; ++s) {

for (int l = max({k, 0}); l < N; ++l) {

for (int t = max({s, 0}); t < min({(i) + 1, N}); ++t) {







J[i][j][k][l][s][t] += J[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int j = 0; j < N; ++j) {

for (int s = max({j, 0}); s < N; ++s) {

for (int t = max({s, 0}); t < min({(i) + 1, N}); ++t) {

for (int k = 0; k < N; ++k) {

for (int l = max({i, 0}); l < min({(k) + 1, N}); ++l) {







J[i][j][k][l][s][t] += J[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int j = 0; j < N; ++j) {

for (int k = max({i, 0}); k < N; ++k) {

for (int s = max({j, 0}); s < min({(i) + 1, N}); ++s) {

for (int l = max({k, 0}); l < N; ++l) {

for (int t = max({l, 0}); t < N; ++t) {







J[i][j][k][l][s][t] += J[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int j = 0; j < N; ++j) {

for (int k = max({i, 0}); k < N; ++k) {

for (int s = max({j, 0}); s < min({(i) + 1, N}); ++s) {

for (int l = 0; l < N; ++l) {

for (int t = max({k, 0}); t < min({(l) + 1, N}); ++t) {







J[i][j][k][l][s][t] += J[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int j = 0; j < N; ++j) {

for (int s = max({j, 0}); s < min({(i) + 1, N}); ++s) {

for (int k = 0; k < N; ++k) {

for (int t = max({k, 0}); t < N; ++t) {

for (int l = max({i, 0}); l < min({(k) + 1, N}); ++l) {







J[i][j][k][l][s][t] += J[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int l = max({i, 0}); l < N; ++l) {

for (int j = 0; j < N; ++j) {

for (int s = max({j, 0}); s < min({(i) + 1, N}); ++s) {

for (int k = 0; k < N; ++k) {

for (int t = max({l, 0}); t < min({(k) + 1, N}); ++t) {







J[i][j][k][l][s][t] += J[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int j = 0; j < N; ++j) {

for (int s = max({j, 0}); s < min({(i) + 1, N}); ++s) {

for (int k = 0; k < N; ++k) {

for (int t = max({i, 0}); t < min({(k) + 1, N}); ++t) {

for (int l = max({k, 0}); l < N; ++l) {







J[i][j][k][l][s][t] += J[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int j = 0; j < N; ++j) {

for (int s = max({j, 0}); s < min({(i) + 1, N}); ++s) {

for (int k = 0; k < N; ++k) {

for (int l = 0; l < min({(k) + 1, N}); ++l) {

for (int t = max({i, 0}); t < min({(l) + 1, N}); ++t) {







J[i][j][k][l][s][t] += J[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int j = 0; j < N; ++j) {

for (int k = 0; k < N; ++k) {

for (int t = max({j, 0}); t < min({(k) + 1, N}); ++t) {

for (int l = max({k, 0}); l < N; ++l) {

for (int s = max({l, 0}); s < min({(i) + 1, N}); ++s) {







J[i][j][k][l][s][t] += J[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int s = max({i, 0}); s < N; ++s) {

for (int j = 0; j < N; ++j) {

for (int k = 0; k < N; ++k) {

for (int t = max({j, 0}); t < min({(k) + 1, N}); ++t) {

for (int l = max({k, 0}); l < min({(i) + 1, N}); ++l) {







J[i][j][k][l][s][t] += J[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int l = 0; l < min({(i) + 1, N}); ++l) {

for (int j = 0; j < N; ++j) {

for (int k = 0; k < N; ++k) {

for (int s = max({k, 0}); s < min({(l) + 1, N}); ++s) {

for (int t = max({j, 0}); t < min({(k) + 1, N}); ++t) {







J[i][j][k][l][s][t] += J[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int l = max({i, 0}); l < N; ++l) {

for (int j = 0; j < N; ++j) {

for (int k = 0; k < N; ++k) {

for (int s = max({k, 0}); s < min({(i) + 1, N}); ++s) {

for (int t = max({j, 0}); t < min({(k) + 1, N}); ++t) {







J[i][j][k][l][s][t] += J[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int l = max({i, 0}); l < N; ++l) {

for (int k = 0; k < min({(i) + 1, N}); ++k) {

for (int s = max({l, 0}); s < N; ++s) {

for (int j = 0; j < N; ++j) {

for (int t = max({j, 0}); t < min({(k) + 1, N}); ++t) {







J[i][j][k][l][s][t] += J[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int j = 0; j < N; ++j) {

for (int k = 0; k < min({(i) + 1, N}); ++k) {

for (int t = max({j, 0}); t < min({(k) + 1, N}); ++t) {

for (int l = 0; l < N; ++l) {

for (int s = max({i, 0}); s < min({(l) + 1, N}); ++s) {







J[i][j][k][l][s][t] += J[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int j = 0; j < N; ++j) {

for (int k = 0; k < N; ++k) {

for (int s = max({k, 0}); s < min({(i) + 1, N}); ++s) {

for (int l = 0; l < min({(k) + 1, N}); ++l) {

for (int t = max({j, 0}); t < min({(l) + 1, N}); ++t) {







J[i][j][k][l][s][t] += J[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int s = max({i, 0}); s < N; ++s) {

for (int k = 0; k < min({(i) + 1, N}); ++k) {

for (int l = 0; l < min({(k) + 1, N}); ++l) {

for (int j = 0; j < N; ++j) {

for (int t = max({j, 0}); t < min({(l) + 1, N}); ++t) {







J[i][j][k][l][s][t] += J[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int j = 0; j < N; ++j) {

for (int k = 0; k < min({(i) + 1, N}); ++k) {

for (int l = 0; l < N; ++l) {

for (int s = max({l, 0}); s < min({(k) + 1, N}); ++s) {

for (int t = max({j, 0}); t < min({(l) + 1, N}); ++t) {







J[i][j][k][l][s][t] += J[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int j = 0; j < N; ++j) {

for (int k = max({i, 0}); k < N; ++k) {

for (int l = 0; l < N; ++l) {

for (int s = max({l, 0}); s < min({(i) + 1, N}); ++s) {

for (int t = max({j, 0}); t < min({(l) + 1, N}); ++t) {







J[i][j][k][l][s][t] += J[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int l = 0; l < min({(i) + 1, N}); ++l) {

for (int k = max({i, 0}); k < N; ++k) {

for (int s = max({k, 0}); s < N; ++s) {

for (int j = 0; j < N; ++j) {

for (int t = max({j, 0}); t < min({(l) + 1, N}); ++t) {







J[i][j][k][l][s][t] += J[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int l = 0; l < min({(i) + 1, N}); ++l) {

for (int j = 0; j < N; ++j) {

for (int t = max({j, 0}); t < min({(l) + 1, N}); ++t) {

for (int k = 0; k < N; ++k) {

for (int s = max({i, 0}); s < min({(k) + 1, N}); ++s) {







J[i][j][k][l][s][t] += J[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int j = 0; j < N; ++j) {

for (int k = 0; k < N; ++k) {

for (int s = 0; s < min({(k) + 1, N}); ++s) {

for (int l = max({k, 0}); l < min({(i) + 1, N}); ++l) {

for (int t = max({j, 0}); t < min({(s) + 1, N}); ++t) {







J[i][j][k][l][s][t] += J[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int l = max({i, 0}); l < N; ++l) {

for (int k = 0; k < min({(i) + 1, N}); ++k) {

for (int s = 0; s < min({(k) + 1, N}); ++s) {

for (int j = 0; j < N; ++j) {

for (int t = max({j, 0}); t < min({(s) + 1, N}); ++t) {







J[i][j][k][l][s][t] += J[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int j = 0; j < N; ++j) {

for (int k = 0; k < min({(i) + 1, N}); ++k) {

for (int l = 0; l < min({(k) + 1, N}); ++l) {

for (int s = 0; s < min({(l) + 1, N}); ++s) {

for (int t = max({j, 0}); t < min({(s) + 1, N}); ++t) {







J[i][j][k][l][s][t] += J[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int l = 0; l < min({(i) + 1, N}); ++l) {

for (int k = max({i, 0}); k < N; ++k) {

for (int s = 0; s < min({(l) + 1, N}); ++s) {

for (int j = 0; j < N; ++j) {

for (int t = max({j, 0}); t < min({(s) + 1, N}); ++t) {







J[i][j][k][l][s][t] += J[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int s = 0; s < min({(i) + 1, N}); ++s) {

for (int k = max({i, 0}); k < N; ++k) {

for (int l = max({k, 0}); l < N; ++l) {

for (int j = 0; j < N; ++j) {

for (int t = max({j, 0}); t < min({(s) + 1, N}); ++t) {







J[i][j][k][l][s][t] += J[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int s = 0; s < min({(i) + 1, N}); ++s) {

for (int j = 0; j < N; ++j) {

for (int t = max({j, 0}); t < min({(s) + 1, N}); ++t) {

for (int k = 0; k < N; ++k) {

for (int l = max({i, 0}); l < min({(k) + 1, N}); ++l) {







J[i][j][k][l][s][t] += J[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int j = 0; j < N; ++j) {

for (int k = max({i, 0}); k < N; ++k) {

for (int t = max({j, 0}); t < min({(i) + 1, N}); ++t) {

for (int l = max({k, 0}); l < N; ++l) {

for (int s = max({l, 0}); s < N; ++s) {







J[i][j][k][l][s][t] += J[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int j = 0; j < N; ++j) {

for (int k = max({i, 0}); k < N; ++k) {

for (int t = max({j, 0}); t < min({(i) + 1, N}); ++t) {

for (int l = 0; l < N; ++l) {

for (int s = max({k, 0}); s < min({(l) + 1, N}); ++s) {







J[i][j][k][l][s][t] += J[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int j = 0; j < N; ++j) {

for (int t = max({j, 0}); t < min({(i) + 1, N}); ++t) {

for (int k = 0; k < N; ++k) {

for (int s = max({k, 0}); s < N; ++s) {

for (int l = max({i, 0}); l < min({(k) + 1, N}); ++l) {







J[i][j][k][l][s][t] += J[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int l = max({i, 0}); l < N; ++l) {

for (int j = 0; j < N; ++j) {

for (int t = max({j, 0}); t < min({(i) + 1, N}); ++t) {

for (int k = 0; k < N; ++k) {

for (int s = max({l, 0}); s < min({(k) + 1, N}); ++s) {







J[i][j][k][l][s][t] += J[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int j = 0; j < N; ++j) {

for (int t = max({j, 0}); t < min({(i) + 1, N}); ++t) {

for (int k = 0; k < N; ++k) {

for (int s = max({i, 0}); s < min({(k) + 1, N}); ++s) {

for (int l = max({k, 0}); l < N; ++l) {







J[i][j][k][l][s][t] += J[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int j = 0; j < N; ++j) {

for (int t = max({j, 0}); t < min({(i) + 1, N}); ++t) {

for (int k = 0; k < N; ++k) {

for (int l = 0; l < min({(k) + 1, N}); ++l) {

for (int s = max({i, 0}); s < min({(l) + 1, N}); ++s) {







J[i][j][k][l][s][t] += J[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int j = 0; j < min({(i) + 1, N}); ++j) {

for (int k = max({i, 0}); k < N; ++k) {

for (int l = max({k, 0}); l < N; ++l) {

for (int s = max({l, 0}); s < N; ++s) {

for (int t = max({s, 0}); t < N; ++t) {







J[i][j][k][l][s][t] += J[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int j = 0; j < min({(i) + 1, N}); ++j) {

for (int k = max({i, 0}); k < N; ++k) {

for (int l = max({k, 0}); l < N; ++l) {

for (int s = 0; s < N; ++s) {

for (int t = max({l, 0}); t < min({(s) + 1, N}); ++t) {







J[i][j][k][l][s][t] += J[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int j = 0; j < min({(i) + 1, N}); ++j) {

for (int k = max({i, 0}); k < N; ++k) {

for (int l = 0; l < N; ++l) {

for (int s = max({k, 0}); s < min({(l) + 1, N}); ++s) {

for (int t = max({l, 0}); t < N; ++t) {







J[i][j][k][l][s][t] += J[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int j = 0; j < min({(i) + 1, N}); ++j) {

for (int k = max({i, 0}); k < N; ++k) {

for (int s = max({k, 0}); s < N; ++s) {

for (int l = 0; l < N; ++l) {

for (int t = max({s, 0}); t < min({(l) + 1, N}); ++t) {







J[i][j][k][l][s][t] += J[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int j = 0; j < min({(i) + 1, N}); ++j) {

for (int k = max({i, 0}); k < N; ++k) {

for (int l = 0; l < N; ++l) {

for (int s = max({l, 0}); s < N; ++s) {

for (int t = max({k, 0}); t < min({(l) + 1, N}); ++t) {







J[i][j][k][l][s][t] += J[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int j = 0; j < min({(i) + 1, N}); ++j) {

for (int k = max({i, 0}); k < N; ++k) {

for (int l = 0; l < N; ++l) {

for (int s = 0; s < min({(l) + 1, N}); ++s) {

for (int t = max({k, 0}); t < min({(s) + 1, N}); ++t) {







J[i][j][k][l][s][t] += J[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int j = 0; j < min({(i) + 1, N}); ++j) {

for (int k = 0; k < N; ++k) {

for (int s = max({k, 0}); s < N; ++s) {

for (int l = max({i, 0}); l < min({(k) + 1, N}); ++l) {

for (int t = max({s, 0}); t < N; ++t) {







J[i][j][k][l][s][t] += J[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int j = 0; j < min({(i) + 1, N}); ++j) {

for (int k = 0; k < N; ++k) {

for (int l = max({i, 0}); l < min({(k) + 1, N}); ++l) {

for (int s = 0; s < N; ++s) {

for (int t = max({k, 0}); t < min({(s) + 1, N}); ++t) {







J[i][j][k][l][s][t] += J[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int l = max({i, 0}); l < N; ++l) {

for (int j = 0; j < min({(i) + 1, N}); ++j) {

for (int k = 0; k < N; ++k) {

for (int s = max({l, 0}); s < min({(k) + 1, N}); ++s) {

for (int t = max({k, 0}); t < N; ++t) {







J[i][j][k][l][s][t] += J[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int l = max({i, 0}); l < N; ++l) {

for (int j = 0; j < min({(i) + 1, N}); ++j) {

for (int s = max({l, 0}); s < N; ++s) {

for (int k = 0; k < N; ++k) {

for (int t = max({s, 0}); t < min({(k) + 1, N}); ++t) {







J[i][j][k][l][s][t] += J[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int l = max({i, 0}); l < N; ++l) {

for (int j = 0; j < min({(i) + 1, N}); ++j) {

for (int k = 0; k < N; ++k) {

for (int s = max({k, 0}); s < N; ++s) {

for (int t = max({l, 0}); t < min({(k) + 1, N}); ++t) {







J[i][j][k][l][s][t] += J[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int l = max({i, 0}); l < N; ++l) {

for (int j = 0; j < min({(i) + 1, N}); ++j) {

for (int k = 0; k < N; ++k) {

for (int s = 0; s < min({(k) + 1, N}); ++s) {

for (int t = max({l, 0}); t < min({(s) + 1, N}); ++t) {







J[i][j][k][l][s][t] += J[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int j = 0; j < min({(i) + 1, N}); ++j) {

for (int k = 0; k < N; ++k) {

for (int s = max({i, 0}); s < min({(k) + 1, N}); ++s) {

for (int l = max({k, 0}); l < N; ++l) {

for (int t = max({l, 0}); t < N; ++t) {







J[i][j][k][l][s][t] += J[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int j = 0; j < min({(i) + 1, N}); ++j) {

for (int k = 0; k < N; ++k) {

for (int s = max({i, 0}); s < min({(k) + 1, N}); ++s) {

for (int l = 0; l < N; ++l) {

for (int t = max({k, 0}); t < min({(l) + 1, N}); ++t) {







J[i][j][k][l][s][t] += J[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int j = 0; j < min({(i) + 1, N}); ++j) {

for (int k = 0; k < N; ++k) {

for (int t = max({k, 0}); t < N; ++t) {

for (int l = 0; l < min({(k) + 1, N}); ++l) {

for (int s = max({i, 0}); s < min({(l) + 1, N}); ++s) {







J[i][j][k][l][s][t] += J[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int j = 0; j < min({(i) + 1, N}); ++j) {

for (int k = 0; k < N; ++k) {

for (int l = 0; l < N; ++l) {

for (int s = max({i, 0}); s < min({(l) + 1, N}); ++s) {

for (int t = max({l, 0}); t < min({(k) + 1, N}); ++t) {







J[i][j][k][l][s][t] += J[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int s = max({i, 0}); s < N; ++s) {

for (int j = 0; j < min({(i) + 1, N}); ++j) {

for (int k = 0; k < N; ++k) {

for (int t = max({s, 0}); t < min({(k) + 1, N}); ++t) {

for (int l = max({k, 0}); l < N; ++l) {







J[i][j][k][l][s][t] += J[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int s = max({i, 0}); s < N; ++s) {

for (int j = 0; j < min({(i) + 1, N}); ++j) {

for (int k = 0; k < N; ++k) {

for (int l = 0; l < min({(k) + 1, N}); ++l) {

for (int t = max({s, 0}); t < min({(l) + 1, N}); ++t) {







J[i][j][k][l][s][t] += J[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int j = 0; j < min({(i) + 1, N}); ++j) {

for (int k = 0; k < N; ++k) {

for (int t = max({i, 0}); t < min({(k) + 1, N}); ++t) {

for (int l = max({k, 0}); l < N; ++l) {

for (int s = max({l, 0}); s < N; ++s) {







J[i][j][k][l][s][t] += J[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int j = 0; j < min({(i) + 1, N}); ++j) {

for (int k = 0; k < N; ++k) {

for (int t = max({i, 0}); t < min({(k) + 1, N}); ++t) {

for (int l = 0; l < N; ++l) {

for (int s = max({k, 0}); s < min({(l) + 1, N}); ++s) {







J[i][j][k][l][s][t] += J[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int j = 0; j < min({(i) + 1, N}); ++j) {

for (int k = 0; k < N; ++k) {

for (int s = max({k, 0}); s < N; ++s) {

for (int l = 0; l < min({(k) + 1, N}); ++l) {

for (int t = max({i, 0}); t < min({(l) + 1, N}); ++t) {







J[i][j][k][l][s][t] += J[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int j = 0; j < min({(i) + 1, N}); ++j) {

for (int k = 0; k < N; ++k) {

for (int l = 0; l < N; ++l) {

for (int s = max({l, 0}); s < min({(k) + 1, N}); ++s) {

for (int t = max({i, 0}); t < min({(l) + 1, N}); ++t) {







J[i][j][k][l][s][t] += J[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int j = 0; j < min({(i) + 1, N}); ++j) {

for (int k = 0; k < N; ++k) {

for (int s = 0; s < min({(k) + 1, N}); ++s) {

for (int l = max({k, 0}); l < N; ++l) {

for (int t = max({i, 0}); t < min({(s) + 1, N}); ++t) {







J[i][j][k][l][s][t] += J[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int j = 0; j < min({(i) + 1, N}); ++j) {

for (int k = 0; k < N; ++k) {

for (int l = 0; l < min({(k) + 1, N}); ++l) {

for (int s = 0; s < min({(l) + 1, N}); ++s) {

for (int t = max({i, 0}); t < min({(s) + 1, N}); ++t) {







J[i][j][k][l][s][t] += J[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int j = 0; j < N; ++j) {

for (int l = max({j, 0}); l < N; ++l) {

for (int k = 0; k < min({(j) + 1, N}); ++k) {

for (int s = max({l, 0}); s < N; ++s) {

for (int t = max({s, 0}); t < min({(i) + 1, N}); ++t) {







J[i][j][k][l][s][t] += J[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int t = max({i, 0}); t < N; ++t) {

for (int j = 0; j < N; ++j) {

for (int l = max({j, 0}); l < N; ++l) {

for (int k = 0; k < min({(j) + 1, N}); ++k) {

for (int s = max({l, 0}); s < min({(i) + 1, N}); ++s) {







J[i][j][k][l][s][t] += J[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int s = 0; s < min({(i) + 1, N}); ++s) {

for (int j = 0; j < N; ++j) {

for (int l = max({j, 0}); l < N; ++l) {

for (int k = 0; k < min({(j) + 1, N}); ++k) {

for (int t = max({l, 0}); t < min({(s) + 1, N}); ++t) {







J[i][j][k][l][s][t] += J[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int s = max({i, 0}); s < N; ++s) {

for (int j = 0; j < N; ++j) {

for (int l = max({j, 0}); l < N; ++l) {

for (int k = 0; k < min({(j) + 1, N}); ++k) {

for (int t = max({l, 0}); t < min({(i) + 1, N}); ++t) {







J[i][j][k][l][s][t] += J[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int s = max({i, 0}); s < N; ++s) {

for (int t = max({s, 0}); t < N; ++t) {

for (int j = 0; j < N; ++j) {

for (int l = max({j, 0}); l < min({(i) + 1, N}); ++l) {

for (int k = 0; k < min({(j) + 1, N}); ++k) {







J[i][j][k][l][s][t] += J[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int j = 0; j < N; ++j) {

for (int l = max({j, 0}); l < min({(i) + 1, N}); ++l) {

for (int k = 0; k < min({(j) + 1, N}); ++k) {

for (int s = 0; s < N; ++s) {

for (int t = max({i, 0}); t < min({(s) + 1, N}); ++t) {







J[i][j][k][l][s][t] += J[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int j = 0; j < N; ++j) {

for (int k = 0; k < min({(j) + 1, N}); ++k) {

for (int l = 0; l < N; ++l) {

for (int s = max({j, 0}); s < min({(l) + 1, N}); ++s) {

for (int t = max({l, 0}); t < min({(i) + 1, N}); ++t) {







J[i][j][k][l][s][t] += J[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int t = max({i, 0}); t < N; ++t) {

for (int l = 0; l < min({(i) + 1, N}); ++l) {

for (int j = 0; j < N; ++j) {

for (int s = max({j, 0}); s < min({(l) + 1, N}); ++s) {

for (int k = 0; k < min({(j) + 1, N}); ++k) {







J[i][j][k][l][s][t] += J[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int l = 0; l < min({(i) + 1, N}); ++l) {

for (int j = 0; j < N; ++j) {

for (int s = max({j, 0}); s < N; ++s) {

for (int k = 0; k < min({(j) + 1, N}); ++k) {

for (int t = max({s, 0}); t < min({(l) + 1, N}); ++t) {







J[i][j][k][l][s][t] += J[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int l = max({i, 0}); l < N; ++l) {

for (int j = 0; j < N; ++j) {

for (int s = max({j, 0}); s < N; ++s) {

for (int k = 0; k < min({(j) + 1, N}); ++k) {

for (int t = max({s, 0}); t < min({(i) + 1, N}); ++t) {







J[i][j][k][l][s][t] += J[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int l = max({i, 0}); l < N; ++l) {

for (int t = max({l, 0}); t < N; ++t) {

for (int j = 0; j < N; ++j) {

for (int s = max({j, 0}); s < min({(i) + 1, N}); ++s) {

for (int k = 0; k < min({(j) + 1, N}); ++k) {







J[i][j][k][l][s][t] += J[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int j = 0; j < N; ++j) {

for (int s = max({j, 0}); s < min({(i) + 1, N}); ++s) {

for (int k = 0; k < min({(j) + 1, N}); ++k) {

for (int l = 0; l < N; ++l) {

for (int t = max({i, 0}); t < min({(l) + 1, N}); ++t) {







J[i][j][k][l][s][t] += J[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int j = 0; j < N; ++j) {

for (int k = 0; k < min({(j) + 1, N}); ++k) {

for (int l = 0; l < N; ++l) {

for (int s = max({l, 0}); s < min({(i) + 1, N}); ++s) {

for (int t = max({j, 0}); t < min({(l) + 1, N}); ++t) {







J[i][j][k][l][s][t] += J[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int s = max({i, 0}); s < N; ++s) {

for (int l = 0; l < min({(i) + 1, N}); ++l) {

for (int j = 0; j < N; ++j) {

for (int t = max({j, 0}); t < min({(l) + 1, N}); ++t) {

for (int k = 0; k < min({(j) + 1, N}); ++k) {







J[i][j][k][l][s][t] += J[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int l = 0; l < min({(i) + 1, N}); ++l) {

for (int s = 0; s < min({(l) + 1, N}); ++s) {

for (int j = 0; j < N; ++j) {

for (int t = max({j, 0}); t < min({(s) + 1, N}); ++t) {

for (int k = 0; k < min({(j) + 1, N}); ++k) {







J[i][j][k][l][s][t] += J[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int s = 0; s < min({(i) + 1, N}); ++s) {

for (int l = max({i, 0}); l < N; ++l) {

for (int j = 0; j < N; ++j) {

for (int t = max({j, 0}); t < min({(s) + 1, N}); ++t) {

for (int k = 0; k < min({(j) + 1, N}); ++k) {







J[i][j][k][l][s][t] += J[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int l = max({i, 0}); l < N; ++l) {

for (int s = max({l, 0}); s < N; ++s) {

for (int j = 0; j < N; ++j) {

for (int t = max({j, 0}); t < min({(i) + 1, N}); ++t) {

for (int k = 0; k < min({(j) + 1, N}); ++k) {







J[i][j][k][l][s][t] += J[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int j = 0; j < N; ++j) {

for (int t = max({j, 0}); t < min({(i) + 1, N}); ++t) {

for (int k = 0; k < min({(j) + 1, N}); ++k) {

for (int l = 0; l < N; ++l) {

for (int s = max({i, 0}); s < min({(l) + 1, N}); ++s) {







J[i][j][k][l][s][t] += J[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int l = max({i, 0}); l < N; ++l) {

for (int j = 0; j < min({(i) + 1, N}); ++j) {

for (int s = max({l, 0}); s < N; ++s) {

for (int k = 0; k < min({(j) + 1, N}); ++k) {

for (int t = max({s, 0}); t < N; ++t) {







J[i][j][k][l][s][t] += J[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int l = max({i, 0}); l < N; ++l) {

for (int j = 0; j < min({(i) + 1, N}); ++j) {

for (int k = 0; k < min({(j) + 1, N}); ++k) {

for (int s = 0; s < N; ++s) {

for (int t = max({l, 0}); t < min({(s) + 1, N}); ++t) {







J[i][j][k][l][s][t] += J[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int j = 0; j < min({(i) + 1, N}); ++j) {

for (int k = 0; k < min({(j) + 1, N}); ++k) {

for (int l = 0; l < N; ++l) {

for (int s = max({i, 0}); s < min({(l) + 1, N}); ++s) {

for (int t = max({l, 0}); t < N; ++t) {







J[i][j][k][l][s][t] += J[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int s = max({i, 0}); s < N; ++s) {

for (int j = 0; j < min({(i) + 1, N}); ++j) {

for (int k = 0; k < min({(j) + 1, N}); ++k) {

for (int l = 0; l < N; ++l) {

for (int t = max({s, 0}); t < min({(l) + 1, N}); ++t) {







J[i][j][k][l][s][t] += J[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int j = 0; j < min({(i) + 1, N}); ++j) {

for (int k = 0; k < min({(j) + 1, N}); ++k) {

for (int l = 0; l < N; ++l) {

for (int s = max({l, 0}); s < N; ++s) {

for (int t = max({i, 0}); t < min({(l) + 1, N}); ++t) {







J[i][j][k][l][s][t] += J[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int j = 0; j < min({(i) + 1, N}); ++j) {

for (int k = 0; k < min({(j) + 1, N}); ++k) {

for (int l = 0; l < N; ++l) {

for (int s = 0; s < min({(l) + 1, N}); ++s) {

for (int t = max({i, 0}); t < min({(s) + 1, N}); ++t) {







J[i][j][k][l][s][t] += J[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int j = 0; j < N; ++j) {

for (int s = max({j, 0}); s < N; ++s) {

for (int t = max({s, 0}); t < min({(i) + 1, N}); ++t) {

for (int k = 0; k < N; ++k) {

for (int l = max({k, 0}); l < min({(j) + 1, N}); ++l) {







J[i][j][k][l][s][t] += J[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int t = max({i, 0}); t < N; ++t) {

for (int j = 0; j < N; ++j) {

for (int s = max({j, 0}); s < min({(i) + 1, N}); ++s) {

for (int k = 0; k < N; ++k) {

for (int l = max({k, 0}); l < min({(j) + 1, N}); ++l) {







J[i][j][k][l][s][t] += J[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int s = 0; s < min({(i) + 1, N}); ++s) {

for (int j = 0; j < N; ++j) {

for (int t = max({j, 0}); t < min({(s) + 1, N}); ++t) {

for (int k = 0; k < N; ++k) {

for (int l = max({k, 0}); l < min({(j) + 1, N}); ++l) {







J[i][j][k][l][s][t] += J[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int s = max({i, 0}); s < N; ++s) {

for (int j = 0; j < N; ++j) {

for (int t = max({j, 0}); t < min({(i) + 1, N}); ++t) {

for (int k = 0; k < N; ++k) {

for (int l = max({k, 0}); l < min({(j) + 1, N}); ++l) {







J[i][j][k][l][s][t] += J[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int s = max({i, 0}); s < N; ++s) {

for (int j = 0; j < min({(i) + 1, N}); ++j) {

for (int t = max({s, 0}); t < N; ++t) {

for (int k = 0; k < N; ++k) {

for (int l = max({k, 0}); l < min({(j) + 1, N}); ++l) {







J[i][j][k][l][s][t] += J[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int j = 0; j < min({(i) + 1, N}); ++j) {

for (int k = 0; k < N; ++k) {

for (int l = max({k, 0}); l < min({(j) + 1, N}); ++l) {

for (int s = 0; s < N; ++s) {

for (int t = max({i, 0}); t < min({(s) + 1, N}); ++t) {







J[i][j][k][l][s][t] += J[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int j = 0; j < N; ++j) {

for (int t = max({j, 0}); t < min({(i) + 1, N}); ++t) {

for (int k = 0; k < N; ++k) {

for (int l = max({k, 0}); l < N; ++l) {

for (int s = max({l, 0}); s < min({(j) + 1, N}); ++s) {







J[i][j][k][l][s][t] += J[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int t = max({i, 0}); t < N; ++t) {

for (int j = 0; j < min({(i) + 1, N}); ++j) {

for (int k = 0; k < N; ++k) {

for (int l = max({k, 0}); l < N; ++l) {

for (int s = max({l, 0}); s < min({(j) + 1, N}); ++s) {







J[i][j][k][l][s][t] += J[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int j = 0; j < min({(i) + 1, N}); ++j) {

for (int k = 0; k < N; ++k) {

for (int l = max({k, 0}); l < N; ++l) {

for (int s = max({l, 0}); s < N; ++s) {

for (int t = max({s, 0}); t < min({(j) + 1, N}); ++t) {







J[i][j][k][l][s][t] += J[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int j = max({i, 0}); j < N; ++j) {

for (int k = 0; k < N; ++k) {

for (int l = max({k, 0}); l < N; ++l) {

for (int s = max({l, 0}); s < N; ++s) {

for (int t = max({s, 0}); t < min({(i) + 1, N}); ++t) {







J[i][j][k][l][s][t] += J[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int j = max({i, 0}); j < N; ++j) {

for (int t = max({j, 0}); t < N; ++t) {

for (int k = 0; k < N; ++k) {

for (int l = max({k, 0}); l < N; ++l) {

for (int s = max({l, 0}); s < min({(i) + 1, N}); ++s) {







J[i][j][k][l][s][t] += J[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int j = 0; j < N; ++j) {

for (int t = max({i, 0}); t < min({(j) + 1, N}); ++t) {

for (int k = 0; k < N; ++k) {

for (int l = max({k, 0}); l < N; ++l) {

for (int s = max({l, 0}); s < min({(i) + 1, N}); ++s) {







J[i][j][k][l][s][t] += J[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int j = 0; j < N; ++j) {

for (int s = max({j, 0}); s < min({(i) + 1, N}); ++s) {

for (int k = 0; k < N; ++k) {

for (int l = max({k, 0}); l < N; ++l) {

for (int t = max({l, 0}); t < min({(j) + 1, N}); ++t) {







J[i][j][k][l][s][t] += J[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int s = max({i, 0}); s < N; ++s) {

for (int j = 0; j < min({(i) + 1, N}); ++j) {

for (int k = 0; k < N; ++k) {

for (int l = max({k, 0}); l < N; ++l) {

for (int t = max({l, 0}); t < min({(j) + 1, N}); ++t) {







J[i][j][k][l][s][t] += J[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int j = 0; j < min({(i) + 1, N}); ++j) {

for (int s = 0; s < min({(j) + 1, N}); ++s) {

for (int k = 0; k < N; ++k) {

for (int l = max({k, 0}); l < N; ++l) {

for (int t = max({l, 0}); t < min({(s) + 1, N}); ++t) {







J[i][j][k][l][s][t] += J[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int s = 0; s < min({(i) + 1, N}); ++s) {

for (int j = max({i, 0}); j < N; ++j) {

for (int k = 0; k < N; ++k) {

for (int l = max({k, 0}); l < N; ++l) {

for (int t = max({l, 0}); t < min({(s) + 1, N}); ++t) {







J[i][j][k][l][s][t] += J[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int j = max({i, 0}); j < N; ++j) {

for (int s = max({j, 0}); s < N; ++s) {

for (int k = 0; k < N; ++k) {

for (int l = max({k, 0}); l < N; ++l) {

for (int t = max({l, 0}); t < min({(i) + 1, N}); ++t) {







J[i][j][k][l][s][t] += J[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int j = 0; j < N; ++j) {

for (int s = max({i, 0}); s < min({(j) + 1, N}); ++s) {

for (int k = 0; k < N; ++k) {

for (int l = max({k, 0}); l < N; ++l) {

for (int t = max({l, 0}); t < min({(i) + 1, N}); ++t) {







J[i][j][k][l][s][t] += J[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int j = max({i, 0}); j < N; ++j) {

for (int s = max({j, 0}); s < N; ++s) {

for (int t = max({s, 0}); t < N; ++t) {

for (int k = 0; k < N; ++k) {

for (int l = max({k, 0}); l < min({(i) + 1, N}); ++l) {







J[i][j][k][l][s][t] += J[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int j = max({i, 0}); j < N; ++j) {

for (int k = 0; k < N; ++k) {

for (int l = max({k, 0}); l < min({(i) + 1, N}); ++l) {

for (int s = 0; s < N; ++s) {

for (int t = max({j, 0}); t < min({(s) + 1, N}); ++t) {







J[i][j][k][l][s][t] += J[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int j = 0; j < N; ++j) {

for (int s = max({i, 0}); s < min({(j) + 1, N}); ++s) {

for (int t = max({j, 0}); t < N; ++t) {

for (int k = 0; k < N; ++k) {

for (int l = max({k, 0}); l < min({(i) + 1, N}); ++l) {







J[i][j][k][l][s][t] += J[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int s = max({i, 0}); s < N; ++s) {

for (int j = 0; j < N; ++j) {

for (int t = max({s, 0}); t < min({(j) + 1, N}); ++t) {

for (int k = 0; k < N; ++k) {

for (int l = max({k, 0}); l < min({(i) + 1, N}); ++l) {







J[i][j][k][l][s][t] += J[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int j = 0; j < N; ++j) {

for (int s = max({j, 0}); s < N; ++s) {

for (int t = max({i, 0}); t < min({(j) + 1, N}); ++t) {

for (int k = 0; k < N; ++k) {

for (int l = max({k, 0}); l < min({(i) + 1, N}); ++l) {







J[i][j][k][l][s][t] += J[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int j = 0; j < N; ++j) {

for (int s = 0; s < min({(j) + 1, N}); ++s) {

for (int t = max({i, 0}); t < min({(s) + 1, N}); ++t) {

for (int k = 0; k < N; ++k) {

for (int l = max({k, 0}); l < min({(i) + 1, N}); ++l) {







J[i][j][k][l][s][t] += J[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int j = 0; j < N; ++j) {

for (int l = max({j, 0}); l < N; ++l) {

for (int t = max({l, 0}); t < min({(i) + 1, N}); ++t) {

for (int k = 0; k < N; ++k) {

for (int s = max({k, 0}); s < min({(j) + 1, N}); ++s) {







J[i][j][k][l][s][t] += J[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int t = max({i, 0}); t < N; ++t) {

for (int j = 0; j < N; ++j) {

for (int l = max({j, 0}); l < min({(i) + 1, N}); ++l) {

for (int k = 0; k < N; ++k) {

for (int s = max({k, 0}); s < min({(j) + 1, N}); ++s) {







J[i][j][k][l][s][t] += J[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int l = 0; l < min({(i) + 1, N}); ++l) {

for (int j = 0; j < N; ++j) {

for (int t = max({j, 0}); t < min({(l) + 1, N}); ++t) {

for (int k = 0; k < N; ++k) {

for (int s = max({k, 0}); s < min({(j) + 1, N}); ++s) {







J[i][j][k][l][s][t] += J[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int l = max({i, 0}); l < N; ++l) {

for (int j = 0; j < N; ++j) {

for (int t = max({j, 0}); t < min({(i) + 1, N}); ++t) {

for (int k = 0; k < N; ++k) {

for (int s = max({k, 0}); s < min({(j) + 1, N}); ++s) {







J[i][j][k][l][s][t] += J[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int l = max({i, 0}); l < N; ++l) {

for (int j = 0; j < min({(i) + 1, N}); ++j) {

for (int t = max({l, 0}); t < N; ++t) {

for (int k = 0; k < N; ++k) {

for (int s = max({k, 0}); s < min({(j) + 1, N}); ++s) {







J[i][j][k][l][s][t] += J[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int j = 0; j < min({(i) + 1, N}); ++j) {

for (int k = 0; k < N; ++k) {

for (int s = max({k, 0}); s < min({(j) + 1, N}); ++s) {

for (int l = 0; l < N; ++l) {

for (int t = max({i, 0}); t < min({(l) + 1, N}); ++t) {







J[i][j][k][l][s][t] += J[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int j = 0; j < N; ++j) {

for (int t = max({j, 0}); t < min({(i) + 1, N}); ++t) {

for (int l = 0; l < min({(j) + 1, N}); ++l) {

for (int k = 0; k < N; ++k) {

for (int s = max({k, 0}); s < min({(l) + 1, N}); ++s) {







J[i][j][k][l][s][t] += J[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int t = max({i, 0}); t < N; ++t) {

for (int j = 0; j < min({(i) + 1, N}); ++j) {

for (int l = 0; l < min({(j) + 1, N}); ++l) {

for (int k = 0; k < N; ++k) {

for (int s = max({k, 0}); s < min({(l) + 1, N}); ++s) {







J[i][j][k][l][s][t] += J[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int j = 0; j < min({(i) + 1, N}); ++j) {

for (int k = 0; k < N; ++k) {

for (int l = 0; l < N; ++l) {

for (int s = max({k, 0}); s < min({(l) + 1, N}); ++s) {

for (int t = max({l, 0}); t < min({(j) + 1, N}); ++t) {







J[i][j][k][l][s][t] += J[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int j = max({i, 0}); j < N; ++j) {

for (int k = 0; k < N; ++k) {

for (int l = 0; l < N; ++l) {

for (int s = max({k, 0}); s < min({(l) + 1, N}); ++s) {

for (int t = max({l, 0}); t < min({(i) + 1, N}); ++t) {







J[i][j][k][l][s][t] += J[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int l = 0; l < min({(i) + 1, N}); ++l) {

for (int j = max({i, 0}); j < N; ++j) {

for (int t = max({j, 0}); t < N; ++t) {

for (int k = 0; k < N; ++k) {

for (int s = max({k, 0}); s < min({(l) + 1, N}); ++s) {







J[i][j][k][l][s][t] += J[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int l = 0; l < min({(i) + 1, N}); ++l) {

for (int j = 0; j < N; ++j) {

for (int t = max({i, 0}); t < min({(j) + 1, N}); ++t) {

for (int k = 0; k < N; ++k) {

for (int s = max({k, 0}); s < min({(l) + 1, N}); ++s) {







J[i][j][k][l][s][t] += J[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int j = 0; j < N; ++j) {

for (int l = max({j, 0}); l < min({(i) + 1, N}); ++l) {

for (int k = 0; k < N; ++k) {

for (int s = max({k, 0}); s < N; ++s) {

for (int t = max({s, 0}); t < min({(j) + 1, N}); ++t) {







J[i][j][k][l][s][t] += J[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int l = max({i, 0}); l < N; ++l) {

for (int j = 0; j < min({(i) + 1, N}); ++j) {

for (int k = 0; k < N; ++k) {

for (int s = max({k, 0}); s < N; ++s) {

for (int t = max({s, 0}); t < min({(j) + 1, N}); ++t) {







J[i][j][k][l][s][t] += J[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int j = 0; j < min({(i) + 1, N}); ++j) {

for (int l = 0; l < min({(j) + 1, N}); ++l) {

for (int k = 0; k < N; ++k) {

for (int s = max({k, 0}); s < N; ++s) {

for (int t = max({s, 0}); t < min({(l) + 1, N}); ++t) {







J[i][j][k][l][s][t] += J[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int l = 0; l < min({(i) + 1, N}); ++l) {

for (int j = max({i, 0}); j < N; ++j) {

for (int k = 0; k < N; ++k) {

for (int s = max({k, 0}); s < N; ++s) {

for (int t = max({s, 0}); t < min({(l) + 1, N}); ++t) {







J[i][j][k][l][s][t] += J[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int j = max({i, 0}); j < N; ++j) {

for (int l = max({j, 0}); l < N; ++l) {

for (int k = 0; k < N; ++k) {

for (int s = max({k, 0}); s < N; ++s) {

for (int t = max({s, 0}); t < min({(i) + 1, N}); ++t) {







J[i][j][k][l][s][t] += J[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int j = 0; j < N; ++j) {

for (int l = max({i, 0}); l < min({(j) + 1, N}); ++l) {

for (int k = 0; k < N; ++k) {

for (int s = max({k, 0}); s < N; ++s) {

for (int t = max({s, 0}); t < min({(i) + 1, N}); ++t) {







J[i][j][k][l][s][t] += J[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int j = max({i, 0}); j < N; ++j) {

for (int l = max({j, 0}); l < N; ++l) {

for (int t = max({l, 0}); t < N; ++t) {

for (int k = 0; k < N; ++k) {

for (int s = max({k, 0}); s < min({(i) + 1, N}); ++s) {







J[i][j][k][l][s][t] += J[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int j = max({i, 0}); j < N; ++j) {

for (int k = 0; k < N; ++k) {

for (int s = max({k, 0}); s < min({(i) + 1, N}); ++s) {

for (int l = 0; l < N; ++l) {

for (int t = max({j, 0}); t < min({(l) + 1, N}); ++t) {







J[i][j][k][l][s][t] += J[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int j = 0; j < N; ++j) {

for (int t = max({j, 0}); t < N; ++t) {

for (int l = max({i, 0}); l < min({(j) + 1, N}); ++l) {

for (int k = 0; k < N; ++k) {

for (int s = max({k, 0}); s < min({(i) + 1, N}); ++s) {







J[i][j][k][l][s][t] += J[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int l = max({i, 0}); l < N; ++l) {

for (int j = 0; j < N; ++j) {

for (int t = max({l, 0}); t < min({(j) + 1, N}); ++t) {

for (int k = 0; k < N; ++k) {

for (int s = max({k, 0}); s < min({(i) + 1, N}); ++s) {







J[i][j][k][l][s][t] += J[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int j = 0; j < N; ++j) {

for (int t = max({i, 0}); t < min({(j) + 1, N}); ++t) {

for (int l = max({j, 0}); l < N; ++l) {

for (int k = 0; k < N; ++k) {

for (int s = max({k, 0}); s < min({(i) + 1, N}); ++s) {







J[i][j][k][l][s][t] += J[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int j = 0; j < N; ++j) {

for (int l = 0; l < min({(j) + 1, N}); ++l) {

for (int t = max({i, 0}); t < min({(l) + 1, N}); ++t) {

for (int k = 0; k < N; ++k) {

for (int s = max({k, 0}); s < min({(i) + 1, N}); ++s) {







J[i][j][k][l][s][t] += J[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int j = 0; j < N; ++j) {

for (int l = max({j, 0}); l < N; ++l) {

for (int s = max({l, 0}); s < min({(i) + 1, N}); ++s) {

for (int k = 0; k < N; ++k) {

for (int t = max({k, 0}); t < min({(j) + 1, N}); ++t) {







J[i][j][k][l][s][t] += J[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int s = max({i, 0}); s < N; ++s) {

for (int j = 0; j < N; ++j) {

for (int l = max({j, 0}); l < min({(i) + 1, N}); ++l) {

for (int k = 0; k < N; ++k) {

for (int t = max({k, 0}); t < min({(j) + 1, N}); ++t) {







J[i][j][k][l][s][t] += J[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int l = 0; l < min({(i) + 1, N}); ++l) {

for (int j = 0; j < N; ++j) {

for (int s = max({j, 0}); s < min({(l) + 1, N}); ++s) {

for (int k = 0; k < N; ++k) {

for (int t = max({k, 0}); t < min({(j) + 1, N}); ++t) {







J[i][j][k][l][s][t] += J[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int l = max({i, 0}); l < N; ++l) {

for (int j = 0; j < N; ++j) {

for (int s = max({j, 0}); s < min({(i) + 1, N}); ++s) {

for (int k = 0; k < N; ++k) {

for (int t = max({k, 0}); t < min({(j) + 1, N}); ++t) {







J[i][j][k][l][s][t] += J[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int l = max({i, 0}); l < N; ++l) {

for (int j = 0; j < min({(i) + 1, N}); ++j) {

for (int s = max({l, 0}); s < N; ++s) {

for (int k = 0; k < N; ++k) {

for (int t = max({k, 0}); t < min({(j) + 1, N}); ++t) {







J[i][j][k][l][s][t] += J[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int j = 0; j < min({(i) + 1, N}); ++j) {

for (int k = 0; k < N; ++k) {

for (int t = max({k, 0}); t < min({(j) + 1, N}); ++t) {

for (int l = 0; l < N; ++l) {

for (int s = max({i, 0}); s < min({(l) + 1, N}); ++s) {







J[i][j][k][l][s][t] += J[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int j = 0; j < N; ++j) {

for (int s = max({j, 0}); s < min({(i) + 1, N}); ++s) {

for (int l = 0; l < min({(j) + 1, N}); ++l) {

for (int k = 0; k < N; ++k) {

for (int t = max({k, 0}); t < min({(l) + 1, N}); ++t) {







J[i][j][k][l][s][t] += J[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int s = max({i, 0}); s < N; ++s) {

for (int j = 0; j < min({(i) + 1, N}); ++j) {

for (int l = 0; l < min({(j) + 1, N}); ++l) {

for (int k = 0; k < N; ++k) {

for (int t = max({k, 0}); t < min({(l) + 1, N}); ++t) {







J[i][j][k][l][s][t] += J[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int j = 0; j < min({(i) + 1, N}); ++j) {

for (int k = 0; k < N; ++k) {

for (int l = 0; l < N; ++l) {

for (int s = max({l, 0}); s < min({(j) + 1, N}); ++s) {

for (int t = max({k, 0}); t < min({(l) + 1, N}); ++t) {







J[i][j][k][l][s][t] += J[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int j = max({i, 0}); j < N; ++j) {

for (int k = 0; k < N; ++k) {

for (int l = 0; l < N; ++l) {

for (int s = max({l, 0}); s < min({(i) + 1, N}); ++s) {

for (int t = max({k, 0}); t < min({(l) + 1, N}); ++t) {







J[i][j][k][l][s][t] += J[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int l = 0; l < min({(i) + 1, N}); ++l) {

for (int j = max({i, 0}); j < N; ++j) {

for (int s = max({j, 0}); s < N; ++s) {

for (int k = 0; k < N; ++k) {

for (int t = max({k, 0}); t < min({(l) + 1, N}); ++t) {







J[i][j][k][l][s][t] += J[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int l = 0; l < min({(i) + 1, N}); ++l) {

for (int j = 0; j < N; ++j) {

for (int s = max({i, 0}); s < min({(j) + 1, N}); ++s) {

for (int k = 0; k < N; ++k) {

for (int t = max({k, 0}); t < min({(l) + 1, N}); ++t) {







J[i][j][k][l][s][t] += J[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int j = 0; j < N; ++j) {

for (int s = 0; s < min({(j) + 1, N}); ++s) {

for (int l = max({j, 0}); l < min({(i) + 1, N}); ++l) {

for (int k = 0; k < N; ++k) {

for (int t = max({k, 0}); t < min({(s) + 1, N}); ++t) {







J[i][j][k][l][s][t] += J[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int l = max({i, 0}); l < N; ++l) {

for (int j = 0; j < min({(i) + 1, N}); ++j) {

for (int s = 0; s < min({(j) + 1, N}); ++s) {

for (int k = 0; k < N; ++k) {

for (int t = max({k, 0}); t < min({(s) + 1, N}); ++t) {







J[i][j][k][l][s][t] += J[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int j = 0; j < min({(i) + 1, N}); ++j) {

for (int l = 0; l < min({(j) + 1, N}); ++l) {

for (int s = 0; s < min({(l) + 1, N}); ++s) {

for (int k = 0; k < N; ++k) {

for (int t = max({k, 0}); t < min({(s) + 1, N}); ++t) {







J[i][j][k][l][s][t] += J[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int l = 0; l < min({(i) + 1, N}); ++l) {

for (int j = max({i, 0}); j < N; ++j) {

for (int s = 0; s < min({(l) + 1, N}); ++s) {

for (int k = 0; k < N; ++k) {

for (int t = max({k, 0}); t < min({(s) + 1, N}); ++t) {







J[i][j][k][l][s][t] += J[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int s = 0; s < min({(i) + 1, N}); ++s) {

for (int j = max({i, 0}); j < N; ++j) {

for (int l = max({j, 0}); l < N; ++l) {

for (int k = 0; k < N; ++k) {

for (int t = max({k, 0}); t < min({(s) + 1, N}); ++t) {







J[i][j][k][l][s][t] += J[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int s = 0; s < min({(i) + 1, N}); ++s) {

for (int j = 0; j < N; ++j) {

for (int l = max({i, 0}); l < min({(j) + 1, N}); ++l) {

for (int k = 0; k < N; ++k) {

for (int t = max({k, 0}); t < min({(s) + 1, N}); ++t) {







J[i][j][k][l][s][t] += J[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int j = max({i, 0}); j < N; ++j) {

for (int l = max({j, 0}); l < N; ++l) {

for (int s = max({l, 0}); s < N; ++s) {

for (int k = 0; k < N; ++k) {

for (int t = max({k, 0}); t < min({(i) + 1, N}); ++t) {







J[i][j][k][l][s][t] += J[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int j = max({i, 0}); j < N; ++j) {

for (int k = 0; k < N; ++k) {

for (int t = max({k, 0}); t < min({(i) + 1, N}); ++t) {

for (int l = 0; l < N; ++l) {

for (int s = max({j, 0}); s < min({(l) + 1, N}); ++s) {







J[i][j][k][l][s][t] += J[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int j = 0; j < N; ++j) {

for (int s = max({j, 0}); s < N; ++s) {

for (int l = max({i, 0}); l < min({(j) + 1, N}); ++l) {

for (int k = 0; k < N; ++k) {

for (int t = max({k, 0}); t < min({(i) + 1, N}); ++t) {







J[i][j][k][l][s][t] += J[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int l = max({i, 0}); l < N; ++l) {

for (int j = 0; j < N; ++j) {

for (int s = max({l, 0}); s < min({(j) + 1, N}); ++s) {

for (int k = 0; k < N; ++k) {

for (int t = max({k, 0}); t < min({(i) + 1, N}); ++t) {







J[i][j][k][l][s][t] += J[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int j = 0; j < N; ++j) {

for (int s = max({i, 0}); s < min({(j) + 1, N}); ++s) {

for (int l = max({j, 0}); l < N; ++l) {

for (int k = 0; k < N; ++k) {

for (int t = max({k, 0}); t < min({(i) + 1, N}); ++t) {







J[i][j][k][l][s][t] += J[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int j = 0; j < N; ++j) {

for (int l = 0; l < min({(j) + 1, N}); ++l) {

for (int s = max({i, 0}); s < min({(l) + 1, N}); ++s) {

for (int k = 0; k < N; ++k) {

for (int t = max({k, 0}); t < min({(i) + 1, N}); ++t) {







J[i][j][k][l][s][t] += J[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int j = max({i, 0}); j < N; ++j) {

for (int k = 0; k < min({(i) + 1, N}); ++k) {

for (int l = max({j, 0}); l < N; ++l) {

for (int s = max({l, 0}); s < N; ++s) {

for (int t = max({s, 0}); t < N; ++t) {







J[i][j][k][l][s][t] += J[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int j = max({i, 0}); j < N; ++j) {

for (int k = 0; k < min({(i) + 1, N}); ++k) {

for (int l = max({j, 0}); l < N; ++l) {

for (int s = 0; s < N; ++s) {

for (int t = max({l, 0}); t < min({(s) + 1, N}); ++t) {







J[i][j][k][l][s][t] += J[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int j = max({i, 0}); j < N; ++j) {

for (int k = 0; k < min({(i) + 1, N}); ++k) {

for (int l = 0; l < N; ++l) {

for (int s = max({j, 0}); s < min({(l) + 1, N}); ++s) {

for (int t = max({l, 0}); t < N; ++t) {







J[i][j][k][l][s][t] += J[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int j = max({i, 0}); j < N; ++j) {

for (int k = 0; k < min({(i) + 1, N}); ++k) {

for (int s = max({j, 0}); s < N; ++s) {

for (int l = 0; l < N; ++l) {

for (int t = max({s, 0}); t < min({(l) + 1, N}); ++t) {







J[i][j][k][l][s][t] += J[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int j = max({i, 0}); j < N; ++j) {

for (int k = 0; k < min({(i) + 1, N}); ++k) {

for (int l = 0; l < N; ++l) {

for (int s = max({l, 0}); s < N; ++s) {

for (int t = max({j, 0}); t < min({(l) + 1, N}); ++t) {







J[i][j][k][l][s][t] += J[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int j = max({i, 0}); j < N; ++j) {

for (int k = 0; k < min({(i) + 1, N}); ++k) {

for (int l = 0; l < N; ++l) {

for (int s = 0; s < min({(l) + 1, N}); ++s) {

for (int t = max({j, 0}); t < min({(s) + 1, N}); ++t) {







J[i][j][k][l][s][t] += J[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int j = 0; j < N; ++j) {

for (int k = 0; k < min({(i) + 1, N}); ++k) {

for (int s = max({j, 0}); s < N; ++s) {

for (int l = max({i, 0}); l < min({(j) + 1, N}); ++l) {

for (int t = max({s, 0}); t < N; ++t) {







J[i][j][k][l][s][t] += J[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int j = 0; j < N; ++j) {

for (int k = 0; k < min({(i) + 1, N}); ++k) {

for (int l = max({i, 0}); l < min({(j) + 1, N}); ++l) {

for (int s = 0; s < N; ++s) {

for (int t = max({j, 0}); t < min({(s) + 1, N}); ++t) {







J[i][j][k][l][s][t] += J[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int l = max({i, 0}); l < N; ++l) {

for (int k = 0; k < min({(i) + 1, N}); ++k) {

for (int j = 0; j < N; ++j) {

for (int s = max({l, 0}); s < min({(j) + 1, N}); ++s) {

for (int t = max({j, 0}); t < N; ++t) {







J[i][j][k][l][s][t] += J[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int l = max({i, 0}); l < N; ++l) {

for (int k = 0; k < min({(i) + 1, N}); ++k) {

for (int s = max({l, 0}); s < N; ++s) {

for (int j = 0; j < N; ++j) {

for (int t = max({s, 0}); t < min({(j) + 1, N}); ++t) {







J[i][j][k][l][s][t] += J[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int l = max({i, 0}); l < N; ++l) {

for (int k = 0; k < min({(i) + 1, N}); ++k) {

for (int j = 0; j < N; ++j) {

for (int s = max({j, 0}); s < N; ++s) {

for (int t = max({l, 0}); t < min({(j) + 1, N}); ++t) {







J[i][j][k][l][s][t] += J[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int l = max({i, 0}); l < N; ++l) {

for (int k = 0; k < min({(i) + 1, N}); ++k) {

for (int j = 0; j < N; ++j) {

for (int s = 0; s < min({(j) + 1, N}); ++s) {

for (int t = max({l, 0}); t < min({(s) + 1, N}); ++t) {







J[i][j][k][l][s][t] += J[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int j = 0; j < N; ++j) {

for (int k = 0; k < min({(i) + 1, N}); ++k) {

for (int s = max({i, 0}); s < min({(j) + 1, N}); ++s) {

for (int l = max({j, 0}); l < N; ++l) {

for (int t = max({l, 0}); t < N; ++t) {







J[i][j][k][l][s][t] += J[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int j = 0; j < N; ++j) {

for (int k = 0; k < min({(i) + 1, N}); ++k) {

for (int s = max({i, 0}); s < min({(j) + 1, N}); ++s) {

for (int l = 0; l < N; ++l) {

for (int t = max({j, 0}); t < min({(l) + 1, N}); ++t) {







J[i][j][k][l][s][t] += J[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int j = 0; j < N; ++j) {

for (int k = 0; k < min({(i) + 1, N}); ++k) {

for (int t = max({j, 0}); t < N; ++t) {

for (int l = 0; l < min({(j) + 1, N}); ++l) {

for (int s = max({i, 0}); s < min({(l) + 1, N}); ++s) {







J[i][j][k][l][s][t] += J[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int j = 0; j < N; ++j) {

for (int k = 0; k < min({(i) + 1, N}); ++k) {

for (int l = 0; l < N; ++l) {

for (int s = max({i, 0}); s < min({(l) + 1, N}); ++s) {

for (int t = max({l, 0}); t < min({(j) + 1, N}); ++t) {







J[i][j][k][l][s][t] += J[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int s = max({i, 0}); s < N; ++s) {

for (int k = 0; k < min({(i) + 1, N}); ++k) {

for (int j = 0; j < N; ++j) {

for (int t = max({s, 0}); t < min({(j) + 1, N}); ++t) {

for (int l = max({j, 0}); l < N; ++l) {







J[i][j][k][l][s][t] += J[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int s = max({i, 0}); s < N; ++s) {

for (int k = 0; k < min({(i) + 1, N}); ++k) {

for (int j = 0; j < N; ++j) {

for (int l = 0; l < min({(j) + 1, N}); ++l) {

for (int t = max({s, 0}); t < min({(l) + 1, N}); ++t) {







J[i][j][k][l][s][t] += J[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int j = 0; j < N; ++j) {

for (int k = 0; k < min({(i) + 1, N}); ++k) {

for (int t = max({i, 0}); t < min({(j) + 1, N}); ++t) {

for (int l = max({j, 0}); l < N; ++l) {

for (int s = max({l, 0}); s < N; ++s) {







J[i][j][k][l][s][t] += J[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int j = 0; j < N; ++j) {

for (int k = 0; k < min({(i) + 1, N}); ++k) {

for (int t = max({i, 0}); t < min({(j) + 1, N}); ++t) {

for (int l = 0; l < N; ++l) {

for (int s = max({j, 0}); s < min({(l) + 1, N}); ++s) {







J[i][j][k][l][s][t] += J[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int j = 0; j < N; ++j) {

for (int k = 0; k < min({(i) + 1, N}); ++k) {

for (int s = max({j, 0}); s < N; ++s) {

for (int l = 0; l < min({(j) + 1, N}); ++l) {

for (int t = max({i, 0}); t < min({(l) + 1, N}); ++t) {







J[i][j][k][l][s][t] += J[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int j = 0; j < N; ++j) {

for (int k = 0; k < min({(i) + 1, N}); ++k) {

for (int l = 0; l < N; ++l) {

for (int s = max({l, 0}); s < min({(j) + 1, N}); ++s) {

for (int t = max({i, 0}); t < min({(l) + 1, N}); ++t) {







J[i][j][k][l][s][t] += J[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int j = 0; j < N; ++j) {

for (int k = 0; k < min({(i) + 1, N}); ++k) {

for (int s = 0; s < min({(j) + 1, N}); ++s) {

for (int l = max({j, 0}); l < N; ++l) {

for (int t = max({i, 0}); t < min({(s) + 1, N}); ++t) {







J[i][j][k][l][s][t] += J[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int j = 0; j < N; ++j) {

for (int k = 0; k < min({(i) + 1, N}); ++k) {

for (int l = 0; l < min({(j) + 1, N}); ++l) {

for (int s = 0; s < min({(l) + 1, N}); ++s) {

for (int t = max({i, 0}); t < min({(s) + 1, N}); ++t) {







J[i][j][k][l][s][t] += J[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int j = 0; j < N; ++j) {

for (int l = 0; l < min({(j) + 1, N}); ++l) {

for (int k = max({j, 0}); k < N; ++k) {

for (int s = max({k, 0}); s < N; ++s) {

for (int t = max({s, 0}); t < min({(i) + 1, N}); ++t) {







J[i][j][k][l][s][t] += J[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int t = max({i, 0}); t < N; ++t) {

for (int j = 0; j < N; ++j) {

for (int l = 0; l < min({(j) + 1, N}); ++l) {

for (int k = max({j, 0}); k < N; ++k) {

for (int s = max({k, 0}); s < min({(i) + 1, N}); ++s) {







J[i][j][k][l][s][t] += J[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int s = 0; s < min({(i) + 1, N}); ++s) {

for (int j = 0; j < N; ++j) {

for (int l = 0; l < min({(j) + 1, N}); ++l) {

for (int k = max({j, 0}); k < N; ++k) {

for (int t = max({k, 0}); t < min({(s) + 1, N}); ++t) {







J[i][j][k][l][s][t] += J[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int s = max({i, 0}); s < N; ++s) {

for (int j = 0; j < N; ++j) {

for (int l = 0; l < min({(j) + 1, N}); ++l) {

for (int k = max({j, 0}); k < N; ++k) {

for (int t = max({k, 0}); t < min({(i) + 1, N}); ++t) {







J[i][j][k][l][s][t] += J[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int s = max({i, 0}); s < N; ++s) {

for (int t = max({s, 0}); t < N; ++t) {

for (int j = 0; j < N; ++j) {

for (int l = 0; l < min({(j) + 1, N}); ++l) {

for (int k = max({j, 0}); k < min({(i) + 1, N}); ++k) {







J[i][j][k][l][s][t] += J[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int j = 0; j < N; ++j) {

for (int l = 0; l < min({(j) + 1, N}); ++l) {

for (int k = max({j, 0}); k < min({(i) + 1, N}); ++k) {

for (int s = 0; s < N; ++s) {

for (int t = max({i, 0}); t < min({(s) + 1, N}); ++t) {







J[i][j][k][l][s][t] += J[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int j = 0; j < N; ++j) {

for (int l = 0; l < min({(j) + 1, N}); ++l) {

for (int k = 0; k < N; ++k) {

for (int s = max({j, 0}); s < min({(k) + 1, N}); ++s) {

for (int t = max({k, 0}); t < min({(i) + 1, N}); ++t) {







J[i][j][k][l][s][t] += J[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int t = max({i, 0}); t < N; ++t) {

for (int k = 0; k < min({(i) + 1, N}); ++k) {

for (int j = 0; j < N; ++j) {

for (int s = max({j, 0}); s < min({(k) + 1, N}); ++s) {

for (int l = 0; l < min({(j) + 1, N}); ++l) {







J[i][j][k][l][s][t] += J[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int j = 0; j < N; ++j) {

for (int k = 0; k < min({(i) + 1, N}); ++k) {

for (int s = max({j, 0}); s < N; ++s) {

for (int l = 0; l < min({(j) + 1, N}); ++l) {

for (int t = max({s, 0}); t < min({(k) + 1, N}); ++t) {







J[i][j][k][l][s][t] += J[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int j = 0; j < N; ++j) {

for (int k = max({i, 0}); k < N; ++k) {

for (int s = max({j, 0}); s < N; ++s) {

for (int l = 0; l < min({(j) + 1, N}); ++l) {

for (int t = max({s, 0}); t < min({(i) + 1, N}); ++t) {







J[i][j][k][l][s][t] += J[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int j = 0; j < N; ++j) {

for (int k = max({i, 0}); k < N; ++k) {

for (int s = max({j, 0}); s < min({(i) + 1, N}); ++s) {

for (int l = 0; l < min({(j) + 1, N}); ++l) {

for (int t = max({k, 0}); t < N; ++t) {







J[i][j][k][l][s][t] += J[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int j = 0; j < N; ++j) {

for (int s = max({j, 0}); s < min({(i) + 1, N}); ++s) {

for (int l = 0; l < min({(j) + 1, N}); ++l) {

for (int k = 0; k < N; ++k) {

for (int t = max({i, 0}); t < min({(k) + 1, N}); ++t) {







J[i][j][k][l][s][t] += J[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int j = 0; j < N; ++j) {

for (int l = 0; l < min({(j) + 1, N}); ++l) {

for (int k = 0; k < N; ++k) {

for (int s = max({k, 0}); s < min({(i) + 1, N}); ++s) {

for (int t = max({j, 0}); t < min({(k) + 1, N}); ++t) {







J[i][j][k][l][s][t] += J[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int s = max({i, 0}); s < N; ++s) {

for (int k = 0; k < min({(i) + 1, N}); ++k) {

for (int j = 0; j < N; ++j) {

for (int t = max({j, 0}); t < min({(k) + 1, N}); ++t) {

for (int l = 0; l < min({(j) + 1, N}); ++l) {







J[i][j][k][l][s][t] += J[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int j = 0; j < N; ++j) {

for (int k = 0; k < min({(i) + 1, N}); ++k) {

for (int l = 0; l < min({(j) + 1, N}); ++l) {

for (int s = 0; s < min({(k) + 1, N}); ++s) {

for (int t = max({j, 0}); t < min({(s) + 1, N}); ++t) {







J[i][j][k][l][s][t] += J[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int s = 0; s < min({(i) + 1, N}); ++s) {

for (int k = max({i, 0}); k < N; ++k) {

for (int j = 0; j < N; ++j) {

for (int t = max({j, 0}); t < min({(s) + 1, N}); ++t) {

for (int l = 0; l < min({(j) + 1, N}); ++l) {







J[i][j][k][l][s][t] += J[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int j = 0; j < N; ++j) {

for (int k = max({i, 0}); k < N; ++k) {

for (int t = max({j, 0}); t < min({(i) + 1, N}); ++t) {

for (int l = 0; l < min({(j) + 1, N}); ++l) {

for (int s = max({k, 0}); s < N; ++s) {







J[i][j][k][l][s][t] += J[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int j = 0; j < N; ++j) {

for (int t = max({j, 0}); t < min({(i) + 1, N}); ++t) {

for (int l = 0; l < min({(j) + 1, N}); ++l) {

for (int k = 0; k < N; ++k) {

for (int s = max({i, 0}); s < min({(k) + 1, N}); ++s) {







J[i][j][k][l][s][t] += J[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int j = 0; j < min({(i) + 1, N}); ++j) {

for (int k = max({i, 0}); k < N; ++k) {

for (int l = 0; l < min({(j) + 1, N}); ++l) {

for (int s = max({k, 0}); s < N; ++s) {

for (int t = max({s, 0}); t < N; ++t) {







J[i][j][k][l][s][t] += J[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int j = 0; j < min({(i) + 1, N}); ++j) {

for (int k = max({i, 0}); k < N; ++k) {

for (int l = 0; l < min({(j) + 1, N}); ++l) {

for (int s = 0; s < N; ++s) {

for (int t = max({k, 0}); t < min({(s) + 1, N}); ++t) {







J[i][j][k][l][s][t] += J[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int j = 0; j < min({(i) + 1, N}); ++j) {

for (int l = 0; l < min({(j) + 1, N}); ++l) {

for (int k = 0; k < N; ++k) {

for (int s = max({i, 0}); s < min({(k) + 1, N}); ++s) {

for (int t = max({k, 0}); t < N; ++t) {







J[i][j][k][l][s][t] += J[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int s = max({i, 0}); s < N; ++s) {

for (int j = 0; j < min({(i) + 1, N}); ++j) {

for (int l = 0; l < min({(j) + 1, N}); ++l) {

for (int k = 0; k < N; ++k) {

for (int t = max({s, 0}); t < min({(k) + 1, N}); ++t) {







J[i][j][k][l][s][t] += J[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int j = 0; j < min({(i) + 1, N}); ++j) {

for (int l = 0; l < min({(j) + 1, N}); ++l) {

for (int k = 0; k < N; ++k) {

for (int s = max({k, 0}); s < N; ++s) {

for (int t = max({i, 0}); t < min({(k) + 1, N}); ++t) {







J[i][j][k][l][s][t] += J[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int j = 0; j < min({(i) + 1, N}); ++j) {

for (int l = 0; l < min({(j) + 1, N}); ++l) {

for (int k = 0; k < N; ++k) {

for (int s = 0; s < min({(k) + 1, N}); ++s) {

for (int t = max({i, 0}); t < min({(s) + 1, N}); ++t) {







J[i][j][k][l][s][t] += J[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int j = 0; j < N; ++j) {

for (int s = max({j, 0}); s < N; ++s) {

for (int k = 0; k < min({(j) + 1, N}); ++k) {

for (int t = max({s, 0}); t < min({(i) + 1, N}); ++t) {

for (int l = 0; l < min({(k) + 1, N}); ++l) {







J[i][j][k][l][s][t] += J[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int t = max({i, 0}); t < N; ++t) {

for (int j = 0; j < N; ++j) {

for (int s = max({j, 0}); s < min({(i) + 1, N}); ++s) {

for (int k = 0; k < min({(j) + 1, N}); ++k) {

for (int l = 0; l < min({(k) + 1, N}); ++l) {







J[i][j][k][l][s][t] += J[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int s = 0; s < min({(i) + 1, N}); ++s) {

for (int j = 0; j < N; ++j) {

for (int t = max({j, 0}); t < min({(s) + 1, N}); ++t) {

for (int k = 0; k < min({(j) + 1, N}); ++k) {

for (int l = 0; l < min({(k) + 1, N}); ++l) {







J[i][j][k][l][s][t] += J[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int s = max({i, 0}); s < N; ++s) {

for (int j = 0; j < N; ++j) {

for (int t = max({j, 0}); t < min({(i) + 1, N}); ++t) {

for (int k = 0; k < min({(j) + 1, N}); ++k) {

for (int l = 0; l < min({(k) + 1, N}); ++l) {







J[i][j][k][l][s][t] += J[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int s = max({i, 0}); s < N; ++s) {

for (int j = 0; j < min({(i) + 1, N}); ++j) {

for (int t = max({s, 0}); t < N; ++t) {

for (int k = 0; k < min({(j) + 1, N}); ++k) {

for (int l = 0; l < min({(k) + 1, N}); ++l) {







J[i][j][k][l][s][t] += J[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int j = 0; j < min({(i) + 1, N}); ++j) {

for (int k = 0; k < min({(j) + 1, N}); ++k) {

for (int l = 0; l < min({(k) + 1, N}); ++l) {

for (int s = 0; s < N; ++s) {

for (int t = max({i, 0}); t < min({(s) + 1, N}); ++t) {







J[i][j][k][l][s][t] += J[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int j = 0; j < N; ++j) {

for (int t = max({j, 0}); t < min({(i) + 1, N}); ++t) {

for (int k = 0; k < N; ++k) {

for (int s = max({k, 0}); s < min({(j) + 1, N}); ++s) {

for (int l = 0; l < min({(k) + 1, N}); ++l) {







J[i][j][k][l][s][t] += J[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int t = max({i, 0}); t < N; ++t) {

for (int j = 0; j < min({(i) + 1, N}); ++j) {

for (int k = 0; k < N; ++k) {

for (int s = max({k, 0}); s < min({(j) + 1, N}); ++s) {

for (int l = 0; l < min({(k) + 1, N}); ++l) {







J[i][j][k][l][s][t] += J[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int j = 0; j < min({(i) + 1, N}); ++j) {

for (int k = 0; k < N; ++k) {

for (int s = max({k, 0}); s < N; ++s) {

for (int l = 0; l < min({(k) + 1, N}); ++l) {

for (int t = max({s, 0}); t < min({(j) + 1, N}); ++t) {







J[i][j][k][l][s][t] += J[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int j = max({i, 0}); j < N; ++j) {

for (int k = 0; k < N; ++k) {

for (int s = max({k, 0}); s < N; ++s) {

for (int l = 0; l < min({(k) + 1, N}); ++l) {

for (int t = max({s, 0}); t < min({(i) + 1, N}); ++t) {







J[i][j][k][l][s][t] += J[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int j = max({i, 0}); j < N; ++j) {

for (int t = max({j, 0}); t < N; ++t) {

for (int k = 0; k < N; ++k) {

for (int s = max({k, 0}); s < min({(i) + 1, N}); ++s) {

for (int l = 0; l < min({(k) + 1, N}); ++l) {







J[i][j][k][l][s][t] += J[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int j = 0; j < N; ++j) {

for (int t = max({i, 0}); t < min({(j) + 1, N}); ++t) {

for (int k = 0; k < N; ++k) {

for (int s = max({k, 0}); s < min({(i) + 1, N}); ++s) {

for (int l = 0; l < min({(k) + 1, N}); ++l) {







J[i][j][k][l][s][t] += J[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int j = 0; j < N; ++j) {

for (int s = max({j, 0}); s < min({(i) + 1, N}); ++s) {

for (int k = 0; k < N; ++k) {

for (int t = max({k, 0}); t < min({(j) + 1, N}); ++t) {

for (int l = 0; l < min({(k) + 1, N}); ++l) {







J[i][j][k][l][s][t] += J[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int s = max({i, 0}); s < N; ++s) {

for (int j = 0; j < min({(i) + 1, N}); ++j) {

for (int k = 0; k < N; ++k) {

for (int t = max({k, 0}); t < min({(j) + 1, N}); ++t) {

for (int l = 0; l < min({(k) + 1, N}); ++l) {







J[i][j][k][l][s][t] += J[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int j = 0; j < min({(i) + 1, N}); ++j) {

for (int s = 0; s < min({(j) + 1, N}); ++s) {

for (int k = 0; k < N; ++k) {

for (int t = max({k, 0}); t < min({(s) + 1, N}); ++t) {

for (int l = 0; l < min({(k) + 1, N}); ++l) {







J[i][j][k][l][s][t] += J[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int s = 0; s < min({(i) + 1, N}); ++s) {

for (int j = max({i, 0}); j < N; ++j) {

for (int k = 0; k < N; ++k) {

for (int t = max({k, 0}); t < min({(s) + 1, N}); ++t) {

for (int l = 0; l < min({(k) + 1, N}); ++l) {







J[i][j][k][l][s][t] += J[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int j = max({i, 0}); j < N; ++j) {

for (int s = max({j, 0}); s < N; ++s) {

for (int k = 0; k < N; ++k) {

for (int t = max({k, 0}); t < min({(i) + 1, N}); ++t) {

for (int l = 0; l < min({(k) + 1, N}); ++l) {







J[i][j][k][l][s][t] += J[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int j = 0; j < N; ++j) {

for (int s = max({i, 0}); s < min({(j) + 1, N}); ++s) {

for (int k = 0; k < N; ++k) {

for (int t = max({k, 0}); t < min({(i) + 1, N}); ++t) {

for (int l = 0; l < min({(k) + 1, N}); ++l) {







J[i][j][k][l][s][t] += J[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int j = max({i, 0}); j < N; ++j) {

for (int k = 0; k < min({(i) + 1, N}); ++k) {

for (int s = max({j, 0}); s < N; ++s) {

for (int l = 0; l < min({(k) + 1, N}); ++l) {

for (int t = max({s, 0}); t < N; ++t) {







J[i][j][k][l][s][t] += J[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int j = max({i, 0}); j < N; ++j) {

for (int k = 0; k < min({(i) + 1, N}); ++k) {

for (int l = 0; l < min({(k) + 1, N}); ++l) {

for (int s = 0; s < N; ++s) {

for (int t = max({j, 0}); t < min({(s) + 1, N}); ++t) {







J[i][j][k][l][s][t] += J[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int j = 0; j < N; ++j) {

for (int k = 0; k < min({(i) + 1, N}); ++k) {

for (int s = max({i, 0}); s < min({(j) + 1, N}); ++s) {

for (int t = max({j, 0}); t < N; ++t) {

for (int l = 0; l < min({(k) + 1, N}); ++l) {







J[i][j][k][l][s][t] += J[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int s = max({i, 0}); s < N; ++s) {

for (int k = 0; k < min({(i) + 1, N}); ++k) {

for (int l = 0; l < min({(k) + 1, N}); ++l) {

for (int j = 0; j < N; ++j) {

for (int t = max({s, 0}); t < min({(j) + 1, N}); ++t) {







J[i][j][k][l][s][t] += J[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int j = 0; j < N; ++j) {

for (int k = 0; k < min({(i) + 1, N}); ++k) {

for (int s = max({j, 0}); s < N; ++s) {

for (int t = max({i, 0}); t < min({(j) + 1, N}); ++t) {

for (int l = 0; l < min({(k) + 1, N}); ++l) {







J[i][j][k][l][s][t] += J[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int j = 0; j < N; ++j) {

for (int k = 0; k < min({(i) + 1, N}); ++k) {

for (int s = 0; s < min({(j) + 1, N}); ++s) {

for (int l = 0; l < min({(k) + 1, N}); ++l) {

for (int t = max({i, 0}); t < min({(s) + 1, N}); ++t) {







J[i][j][k][l][s][t] += J[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int j = 0; j < N; ++j) {

for (int k = max({j, 0}); k < N; ++k) {

for (int t = max({k, 0}); t < min({(i) + 1, N}); ++t) {

for (int l = 0; l < N; ++l) {

for (int s = max({l, 0}); s < min({(j) + 1, N}); ++s) {







J[i][j][k][l][s][t] += J[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int t = max({i, 0}); t < N; ++t) {

for (int j = 0; j < N; ++j) {

for (int k = max({j, 0}); k < min({(i) + 1, N}); ++k) {

for (int l = 0; l < N; ++l) {

for (int s = max({l, 0}); s < min({(j) + 1, N}); ++s) {







J[i][j][k][l][s][t] += J[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int j = 0; j < N; ++j) {

for (int k = 0; k < min({(i) + 1, N}); ++k) {

for (int t = max({j, 0}); t < min({(k) + 1, N}); ++t) {

for (int l = 0; l < N; ++l) {

for (int s = max({l, 0}); s < min({(j) + 1, N}); ++s) {







J[i][j][k][l][s][t] += J[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int j = 0; j < N; ++j) {

for (int k = max({i, 0}); k < N; ++k) {

for (int t = max({j, 0}); t < min({(i) + 1, N}); ++t) {

for (int l = 0; l < N; ++l) {

for (int s = max({l, 0}); s < min({(j) + 1, N}); ++s) {







J[i][j][k][l][s][t] += J[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int j = 0; j < min({(i) + 1, N}); ++j) {

for (int k = max({i, 0}); k < N; ++k) {

for (int t = max({k, 0}); t < N; ++t) {

for (int l = 0; l < N; ++l) {

for (int s = max({l, 0}); s < min({(j) + 1, N}); ++s) {







J[i][j][k][l][s][t] += J[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int j = 0; j < min({(i) + 1, N}); ++j) {

for (int k = 0; k < N; ++k) {

for (int t = max({i, 0}); t < min({(k) + 1, N}); ++t) {

for (int l = 0; l < N; ++l) {

for (int s = max({l, 0}); s < min({(j) + 1, N}); ++s) {







J[i][j][k][l][s][t] += J[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int j = 0; j < N; ++j) {

for (int t = max({j, 0}); t < min({(i) + 1, N}); ++t) {

for (int k = 0; k < min({(j) + 1, N}); ++k) {

for (int l = 0; l < N; ++l) {

for (int s = max({l, 0}); s < min({(k) + 1, N}); ++s) {







J[i][j][k][l][s][t] += J[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int t = max({i, 0}); t < N; ++t) {

for (int j = 0; j < min({(i) + 1, N}); ++j) {

for (int k = 0; k < min({(j) + 1, N}); ++k) {

for (int l = 0; l < N; ++l) {

for (int s = max({l, 0}); s < min({(k) + 1, N}); ++s) {







J[i][j][k][l][s][t] += J[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int j = 0; j < min({(i) + 1, N}); ++j) {

for (int k = 0; k < N; ++k) {

for (int t = max({k, 0}); t < min({(j) + 1, N}); ++t) {

for (int l = 0; l < N; ++l) {

for (int s = max({l, 0}); s < min({(k) + 1, N}); ++s) {







J[i][j][k][l][s][t] += J[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int j = max({i, 0}); j < N; ++j) {

for (int k = 0; k < N; ++k) {

for (int t = max({k, 0}); t < min({(i) + 1, N}); ++t) {

for (int l = 0; l < N; ++l) {

for (int s = max({l, 0}); s < min({(k) + 1, N}); ++s) {







J[i][j][k][l][s][t] += J[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int j = max({i, 0}); j < N; ++j) {

for (int k = 0; k < min({(i) + 1, N}); ++k) {

for (int t = max({j, 0}); t < N; ++t) {

for (int l = 0; l < N; ++l) {

for (int s = max({l, 0}); s < min({(k) + 1, N}); ++s) {







J[i][j][k][l][s][t] += J[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int j = 0; j < N; ++j) {

for (int k = 0; k < min({(i) + 1, N}); ++k) {

for (int t = max({i, 0}); t < min({(j) + 1, N}); ++t) {

for (int l = 0; l < N; ++l) {

for (int s = max({l, 0}); s < min({(k) + 1, N}); ++s) {







J[i][j][k][l][s][t] += J[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int j = 0; j < N; ++j) {

for (int k = max({j, 0}); k < min({(i) + 1, N}); ++k) {

for (int l = 0; l < N; ++l) {

for (int s = max({l, 0}); s < N; ++s) {

for (int t = max({s, 0}); t < min({(j) + 1, N}); ++t) {







J[i][j][k][l][s][t] += J[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int j = 0; j < min({(i) + 1, N}); ++j) {

for (int k = max({i, 0}); k < N; ++k) {

for (int l = 0; l < N; ++l) {

for (int s = max({l, 0}); s < N; ++s) {

for (int t = max({s, 0}); t < min({(j) + 1, N}); ++t) {







J[i][j][k][l][s][t] += J[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int j = 0; j < min({(i) + 1, N}); ++j) {

for (int k = 0; k < min({(j) + 1, N}); ++k) {

for (int l = 0; l < N; ++l) {

for (int s = max({l, 0}); s < N; ++s) {

for (int t = max({s, 0}); t < min({(k) + 1, N}); ++t) {







J[i][j][k][l][s][t] += J[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int j = max({i, 0}); j < N; ++j) {

for (int k = 0; k < min({(i) + 1, N}); ++k) {

for (int l = 0; l < N; ++l) {

for (int s = max({l, 0}); s < N; ++s) {

for (int t = max({s, 0}); t < min({(k) + 1, N}); ++t) {







J[i][j][k][l][s][t] += J[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int j = max({i, 0}); j < N; ++j) {

for (int k = max({j, 0}); k < N; ++k) {

for (int l = 0; l < N; ++l) {

for (int s = max({l, 0}); s < N; ++s) {

for (int t = max({s, 0}); t < min({(i) + 1, N}); ++t) {







J[i][j][k][l][s][t] += J[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int j = 0; j < N; ++j) {

for (int k = max({i, 0}); k < min({(j) + 1, N}); ++k) {

for (int l = 0; l < N; ++l) {

for (int s = max({l, 0}); s < N; ++s) {

for (int t = max({s, 0}); t < min({(i) + 1, N}); ++t) {







J[i][j][k][l][s][t] += J[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int j = max({i, 0}); j < N; ++j) {

for (int k = max({j, 0}); k < N; ++k) {

for (int t = max({k, 0}); t < N; ++t) {

for (int l = 0; l < N; ++l) {

for (int s = max({l, 0}); s < min({(i) + 1, N}); ++s) {







J[i][j][k][l][s][t] += J[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int j = max({i, 0}); j < N; ++j) {

for (int k = 0; k < N; ++k) {

for (int t = max({j, 0}); t < min({(k) + 1, N}); ++t) {

for (int l = 0; l < N; ++l) {

for (int s = max({l, 0}); s < min({(i) + 1, N}); ++s) {







J[i][j][k][l][s][t] += J[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int j = 0; j < N; ++j) {

for (int t = max({j, 0}); t < N; ++t) {

for (int k = max({i, 0}); k < min({(j) + 1, N}); ++k) {

for (int l = 0; l < N; ++l) {

for (int s = max({l, 0}); s < min({(i) + 1, N}); ++s) {







J[i][j][k][l][s][t] += J[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int j = 0; j < N; ++j) {

for (int k = max({i, 0}); k < N; ++k) {

for (int t = max({k, 0}); t < min({(j) + 1, N}); ++t) {

for (int l = 0; l < N; ++l) {

for (int s = max({l, 0}); s < min({(i) + 1, N}); ++s) {







J[i][j][k][l][s][t] += J[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int j = 0; j < N; ++j) {

for (int t = max({i, 0}); t < min({(j) + 1, N}); ++t) {

for (int k = max({j, 0}); k < N; ++k) {

for (int l = 0; l < N; ++l) {

for (int s = max({l, 0}); s < min({(i) + 1, N}); ++s) {







J[i][j][k][l][s][t] += J[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int j = 0; j < N; ++j) {

for (int k = 0; k < min({(j) + 1, N}); ++k) {

for (int t = max({i, 0}); t < min({(k) + 1, N}); ++t) {

for (int l = 0; l < N; ++l) {

for (int s = max({l, 0}); s < min({(i) + 1, N}); ++s) {







J[i][j][k][l][s][t] += J[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int j = 0; j < N; ++j) {

for (int k = max({j, 0}); k < N; ++k) {

for (int s = max({k, 0}); s < min({(i) + 1, N}); ++s) {

for (int l = 0; l < N; ++l) {

for (int t = max({l, 0}); t < min({(j) + 1, N}); ++t) {







J[i][j][k][l][s][t] += J[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int s = max({i, 0}); s < N; ++s) {

for (int j = 0; j < N; ++j) {

for (int k = max({j, 0}); k < min({(i) + 1, N}); ++k) {

for (int l = 0; l < N; ++l) {

for (int t = max({l, 0}); t < min({(j) + 1, N}); ++t) {







J[i][j][k][l][s][t] += J[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int j = 0; j < N; ++j) {

for (int k = 0; k < min({(i) + 1, N}); ++k) {

for (int s = max({j, 0}); s < min({(k) + 1, N}); ++s) {

for (int l = 0; l < N; ++l) {

for (int t = max({l, 0}); t < min({(j) + 1, N}); ++t) {







J[i][j][k][l][s][t] += J[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int j = 0; j < N; ++j) {

for (int k = max({i, 0}); k < N; ++k) {

for (int s = max({j, 0}); s < min({(i) + 1, N}); ++s) {

for (int l = 0; l < N; ++l) {

for (int t = max({l, 0}); t < min({(j) + 1, N}); ++t) {







J[i][j][k][l][s][t] += J[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int j = 0; j < min({(i) + 1, N}); ++j) {

for (int k = max({i, 0}); k < N; ++k) {

for (int s = max({k, 0}); s < N; ++s) {

for (int l = 0; l < N; ++l) {

for (int t = max({l, 0}); t < min({(j) + 1, N}); ++t) {







J[i][j][k][l][s][t] += J[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int j = 0; j < min({(i) + 1, N}); ++j) {

for (int k = 0; k < N; ++k) {

for (int s = max({i, 0}); s < min({(k) + 1, N}); ++s) {

for (int l = 0; l < N; ++l) {

for (int t = max({l, 0}); t < min({(j) + 1, N}); ++t) {







J[i][j][k][l][s][t] += J[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int j = 0; j < N; ++j) {

for (int s = max({j, 0}); s < min({(i) + 1, N}); ++s) {

for (int k = 0; k < min({(j) + 1, N}); ++k) {

for (int l = 0; l < N; ++l) {

for (int t = max({l, 0}); t < min({(k) + 1, N}); ++t) {







J[i][j][k][l][s][t] += J[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int s = max({i, 0}); s < N; ++s) {

for (int j = 0; j < min({(i) + 1, N}); ++j) {

for (int k = 0; k < min({(j) + 1, N}); ++k) {

for (int l = 0; l < N; ++l) {

for (int t = max({l, 0}); t < min({(k) + 1, N}); ++t) {







J[i][j][k][l][s][t] += J[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int j = 0; j < min({(i) + 1, N}); ++j) {

for (int k = 0; k < N; ++k) {

for (int s = max({k, 0}); s < min({(j) + 1, N}); ++s) {

for (int l = 0; l < N; ++l) {

for (int t = max({l, 0}); t < min({(k) + 1, N}); ++t) {







J[i][j][k][l][s][t] += J[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int j = max({i, 0}); j < N; ++j) {

for (int k = 0; k < N; ++k) {

for (int s = max({k, 0}); s < min({(i) + 1, N}); ++s) {

for (int l = 0; l < N; ++l) {

for (int t = max({l, 0}); t < min({(k) + 1, N}); ++t) {







J[i][j][k][l][s][t] += J[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int j = max({i, 0}); j < N; ++j) {

for (int k = 0; k < min({(i) + 1, N}); ++k) {

for (int s = max({j, 0}); s < N; ++s) {

for (int l = 0; l < N; ++l) {

for (int t = max({l, 0}); t < min({(k) + 1, N}); ++t) {







J[i][j][k][l][s][t] += J[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int j = 0; j < N; ++j) {

for (int k = 0; k < min({(i) + 1, N}); ++k) {

for (int s = max({i, 0}); s < min({(j) + 1, N}); ++s) {

for (int l = 0; l < N; ++l) {

for (int t = max({l, 0}); t < min({(k) + 1, N}); ++t) {







J[i][j][k][l][s][t] += J[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int j = 0; j < N; ++j) {

for (int s = 0; s < min({(j) + 1, N}); ++s) {

for (int k = max({j, 0}); k < min({(i) + 1, N}); ++k) {

for (int l = 0; l < N; ++l) {

for (int t = max({l, 0}); t < min({(s) + 1, N}); ++t) {







J[i][j][k][l][s][t] += J[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int j = 0; j < min({(i) + 1, N}); ++j) {

for (int k = max({i, 0}); k < N; ++k) {

for (int s = 0; s < min({(j) + 1, N}); ++s) {

for (int l = 0; l < N; ++l) {

for (int t = max({l, 0}); t < min({(s) + 1, N}); ++t) {







J[i][j][k][l][s][t] += J[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int j = 0; j < min({(i) + 1, N}); ++j) {

for (int k = 0; k < min({(j) + 1, N}); ++k) {

for (int s = 0; s < min({(k) + 1, N}); ++s) {

for (int l = 0; l < N; ++l) {

for (int t = max({l, 0}); t < min({(s) + 1, N}); ++t) {







J[i][j][k][l][s][t] += J[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int j = max({i, 0}); j < N; ++j) {

for (int k = 0; k < min({(i) + 1, N}); ++k) {

for (int s = 0; s < min({(k) + 1, N}); ++s) {

for (int l = 0; l < N; ++l) {

for (int t = max({l, 0}); t < min({(s) + 1, N}); ++t) {







J[i][j][k][l][s][t] += J[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int s = 0; s < min({(i) + 1, N}); ++s) {

for (int j = max({i, 0}); j < N; ++j) {

for (int k = max({j, 0}); k < N; ++k) {

for (int l = 0; l < N; ++l) {

for (int t = max({l, 0}); t < min({(s) + 1, N}); ++t) {







J[i][j][k][l][s][t] += J[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int s = 0; s < min({(i) + 1, N}); ++s) {

for (int j = 0; j < N; ++j) {

for (int k = max({i, 0}); k < min({(j) + 1, N}); ++k) {

for (int l = 0; l < N; ++l) {

for (int t = max({l, 0}); t < min({(s) + 1, N}); ++t) {







J[i][j][k][l][s][t] += J[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int j = max({i, 0}); j < N; ++j) {

for (int k = max({j, 0}); k < N; ++k) {

for (int s = max({k, 0}); s < N; ++s) {

for (int l = 0; l < N; ++l) {

for (int t = max({l, 0}); t < min({(i) + 1, N}); ++t) {







J[i][j][k][l][s][t] += J[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int j = max({i, 0}); j < N; ++j) {

for (int k = 0; k < N; ++k) {

for (int s = max({j, 0}); s < min({(k) + 1, N}); ++s) {

for (int l = 0; l < N; ++l) {

for (int t = max({l, 0}); t < min({(i) + 1, N}); ++t) {







J[i][j][k][l][s][t] += J[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int j = 0; j < N; ++j) {

for (int s = max({j, 0}); s < N; ++s) {

for (int k = max({i, 0}); k < min({(j) + 1, N}); ++k) {

for (int l = 0; l < N; ++l) {

for (int t = max({l, 0}); t < min({(i) + 1, N}); ++t) {







J[i][j][k][l][s][t] += J[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int j = 0; j < N; ++j) {

for (int k = max({i, 0}); k < N; ++k) {

for (int s = max({k, 0}); s < min({(j) + 1, N}); ++s) {

for (int l = 0; l < N; ++l) {

for (int t = max({l, 0}); t < min({(i) + 1, N}); ++t) {







J[i][j][k][l][s][t] += J[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int j = 0; j < N; ++j) {

for (int s = max({i, 0}); s < min({(j) + 1, N}); ++s) {

for (int k = max({j, 0}); k < N; ++k) {

for (int l = 0; l < N; ++l) {

for (int t = max({l, 0}); t < min({(i) + 1, N}); ++t) {







J[i][j][k][l][s][t] += J[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int j = 0; j < N; ++j) {

for (int k = 0; k < min({(j) + 1, N}); ++k) {

for (int s = max({i, 0}); s < min({(k) + 1, N}); ++s) {

for (int l = 0; l < N; ++l) {

for (int t = max({l, 0}); t < min({(i) + 1, N}); ++t) {







J[i][j][k][l][s][t] += J[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int l = 0; l < min({(i) + 1, N}); ++l) {

for (int j = max({i, 0}); j < N; ++j) {

for (int k = max({j, 0}); k < N; ++k) {

for (int s = max({k, 0}); s < N; ++s) {

for (int t = max({s, 0}); t < N; ++t) {







J[i][j][k][l][s][t] += J[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int l = 0; l < min({(i) + 1, N}); ++l) {

for (int j = max({i, 0}); j < N; ++j) {

for (int k = max({j, 0}); k < N; ++k) {

for (int s = 0; s < N; ++s) {

for (int t = max({k, 0}); t < min({(s) + 1, N}); ++t) {







J[i][j][k][l][s][t] += J[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int l = 0; l < min({(i) + 1, N}); ++l) {

for (int j = max({i, 0}); j < N; ++j) {

for (int k = 0; k < N; ++k) {

for (int s = max({j, 0}); s < min({(k) + 1, N}); ++s) {

for (int t = max({k, 0}); t < N; ++t) {







J[i][j][k][l][s][t] += J[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int l = 0; l < min({(i) + 1, N}); ++l) {

for (int j = max({i, 0}); j < N; ++j) {

for (int s = max({j, 0}); s < N; ++s) {

for (int k = 0; k < N; ++k) {

for (int t = max({s, 0}); t < min({(k) + 1, N}); ++t) {







J[i][j][k][l][s][t] += J[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int l = 0; l < min({(i) + 1, N}); ++l) {

for (int j = max({i, 0}); j < N; ++j) {

for (int k = 0; k < N; ++k) {

for (int s = max({k, 0}); s < N; ++s) {

for (int t = max({j, 0}); t < min({(k) + 1, N}); ++t) {







J[i][j][k][l][s][t] += J[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int l = 0; l < min({(i) + 1, N}); ++l) {

for (int j = max({i, 0}); j < N; ++j) {

for (int k = 0; k < N; ++k) {

for (int s = 0; s < min({(k) + 1, N}); ++s) {

for (int t = max({j, 0}); t < min({(s) + 1, N}); ++t) {







J[i][j][k][l][s][t] += J[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int l = 0; l < min({(i) + 1, N}); ++l) {

for (int j = 0; j < N; ++j) {

for (int s = max({j, 0}); s < N; ++s) {

for (int k = max({i, 0}); k < min({(j) + 1, N}); ++k) {

for (int t = max({s, 0}); t < N; ++t) {







J[i][j][k][l][s][t] += J[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int l = 0; l < min({(i) + 1, N}); ++l) {

for (int j = 0; j < N; ++j) {

for (int k = max({i, 0}); k < min({(j) + 1, N}); ++k) {

for (int s = 0; s < N; ++s) {

for (int t = max({j, 0}); t < min({(s) + 1, N}); ++t) {







J[i][j][k][l][s][t] += J[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int l = 0; l < min({(i) + 1, N}); ++l) {

for (int k = max({i, 0}); k < N; ++k) {

for (int j = 0; j < N; ++j) {

for (int s = max({k, 0}); s < min({(j) + 1, N}); ++s) {

for (int t = max({j, 0}); t < N; ++t) {







J[i][j][k][l][s][t] += J[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int l = 0; l < min({(i) + 1, N}); ++l) {

for (int k = max({i, 0}); k < N; ++k) {

for (int s = max({k, 0}); s < N; ++s) {

for (int j = 0; j < N; ++j) {

for (int t = max({s, 0}); t < min({(j) + 1, N}); ++t) {







J[i][j][k][l][s][t] += J[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int l = 0; l < min({(i) + 1, N}); ++l) {

for (int k = max({i, 0}); k < N; ++k) {

for (int j = 0; j < N; ++j) {

for (int s = max({j, 0}); s < N; ++s) {

for (int t = max({k, 0}); t < min({(j) + 1, N}); ++t) {







J[i][j][k][l][s][t] += J[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int l = 0; l < min({(i) + 1, N}); ++l) {

for (int k = max({i, 0}); k < N; ++k) {

for (int j = 0; j < N; ++j) {

for (int s = 0; s < min({(j) + 1, N}); ++s) {

for (int t = max({k, 0}); t < min({(s) + 1, N}); ++t) {







J[i][j][k][l][s][t] += J[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int l = 0; l < min({(i) + 1, N}); ++l) {

for (int j = 0; j < N; ++j) {

for (int s = max({i, 0}); s < min({(j) + 1, N}); ++s) {

for (int k = max({j, 0}); k < N; ++k) {

for (int t = max({k, 0}); t < N; ++t) {







J[i][j][k][l][s][t] += J[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int l = 0; l < min({(i) + 1, N}); ++l) {

for (int j = 0; j < N; ++j) {

for (int s = max({i, 0}); s < min({(j) + 1, N}); ++s) {

for (int k = 0; k < N; ++k) {

for (int t = max({j, 0}); t < min({(k) + 1, N}); ++t) {







J[i][j][k][l][s][t] += J[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int l = 0; l < min({(i) + 1, N}); ++l) {

for (int j = 0; j < N; ++j) {

for (int t = max({j, 0}); t < N; ++t) {

for (int k = 0; k < min({(j) + 1, N}); ++k) {

for (int s = max({i, 0}); s < min({(k) + 1, N}); ++s) {







J[i][j][k][l][s][t] += J[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int l = 0; l < min({(i) + 1, N}); ++l) {

for (int j = 0; j < N; ++j) {

for (int k = 0; k < N; ++k) {

for (int s = max({i, 0}); s < min({(k) + 1, N}); ++s) {

for (int t = max({k, 0}); t < min({(j) + 1, N}); ++t) {







J[i][j][k][l][s][t] += J[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int s = max({i, 0}); s < N; ++s) {

for (int l = 0; l < min({(i) + 1, N}); ++l) {

for (int j = 0; j < N; ++j) {

for (int t = max({s, 0}); t < min({(j) + 1, N}); ++t) {

for (int k = max({j, 0}); k < N; ++k) {







J[i][j][k][l][s][t] += J[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int s = max({i, 0}); s < N; ++s) {

for (int l = 0; l < min({(i) + 1, N}); ++l) {

for (int j = 0; j < N; ++j) {

for (int k = 0; k < min({(j) + 1, N}); ++k) {

for (int t = max({s, 0}); t < min({(k) + 1, N}); ++t) {







J[i][j][k][l][s][t] += J[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int l = 0; l < min({(i) + 1, N}); ++l) {

for (int j = 0; j < N; ++j) {

for (int t = max({i, 0}); t < min({(j) + 1, N}); ++t) {

for (int k = max({j, 0}); k < N; ++k) {

for (int s = max({k, 0}); s < N; ++s) {







J[i][j][k][l][s][t] += J[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int l = 0; l < min({(i) + 1, N}); ++l) {

for (int j = 0; j < N; ++j) {

for (int t = max({i, 0}); t < min({(j) + 1, N}); ++t) {

for (int k = 0; k < N; ++k) {

for (int s = max({j, 0}); s < min({(k) + 1, N}); ++s) {







J[i][j][k][l][s][t] += J[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int l = 0; l < min({(i) + 1, N}); ++l) {

for (int j = 0; j < N; ++j) {

for (int s = max({j, 0}); s < N; ++s) {

for (int k = 0; k < min({(j) + 1, N}); ++k) {

for (int t = max({i, 0}); t < min({(k) + 1, N}); ++t) {







J[i][j][k][l][s][t] += J[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int l = 0; l < min({(i) + 1, N}); ++l) {

for (int j = 0; j < N; ++j) {

for (int k = 0; k < N; ++k) {

for (int s = max({k, 0}); s < min({(j) + 1, N}); ++s) {

for (int t = max({i, 0}); t < min({(k) + 1, N}); ++t) {







J[i][j][k][l][s][t] += J[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int l = 0; l < min({(i) + 1, N}); ++l) {

for (int j = 0; j < N; ++j) {

for (int s = 0; s < min({(j) + 1, N}); ++s) {

for (int k = max({j, 0}); k < N; ++k) {

for (int t = max({i, 0}); t < min({(s) + 1, N}); ++t) {







J[i][j][k][l][s][t] += J[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int l = 0; l < min({(i) + 1, N}); ++l) {

for (int j = 0; j < N; ++j) {

for (int k = 0; k < min({(j) + 1, N}); ++k) {

for (int s = 0; s < min({(k) + 1, N}); ++s) {

for (int t = max({i, 0}); t < min({(s) + 1, N}); ++t) {







J[i][j][k][l][s][t] += J[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int j = 0; j < N; ++j) {

for (int s = 0; s < min({(j) + 1, N}); ++s) {

for (int k = max({j, 0}); k < N; ++k) {

for (int l = max({k, 0}); l < N; ++l) {

for (int t = max({l, 0}); t < min({(i) + 1, N}); ++t) {







J[i][j][k][l][s][t] += J[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int t = max({i, 0}); t < N; ++t) {

for (int j = 0; j < N; ++j) {

for (int s = 0; s < min({(j) + 1, N}); ++s) {

for (int k = max({j, 0}); k < N; ++k) {

for (int l = max({k, 0}); l < min({(i) + 1, N}); ++l) {







J[i][j][k][l][s][t] += J[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int l = 0; l < min({(i) + 1, N}); ++l) {

for (int j = 0; j < N; ++j) {

for (int s = 0; s < min({(j) + 1, N}); ++s) {

for (int k = max({j, 0}); k < N; ++k) {

for (int t = max({k, 0}); t < min({(l) + 1, N}); ++t) {







J[i][j][k][l][s][t] += J[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int l = max({i, 0}); l < N; ++l) {

for (int j = 0; j < N; ++j) {

for (int s = 0; s < min({(j) + 1, N}); ++s) {

for (int k = max({j, 0}); k < N; ++k) {

for (int t = max({k, 0}); t < min({(i) + 1, N}); ++t) {







J[i][j][k][l][s][t] += J[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int l = max({i, 0}); l < N; ++l) {

for (int t = max({l, 0}); t < N; ++t) {

for (int j = 0; j < N; ++j) {

for (int s = 0; s < min({(j) + 1, N}); ++s) {

for (int k = max({j, 0}); k < min({(i) + 1, N}); ++k) {







J[i][j][k][l][s][t] += J[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int j = 0; j < N; ++j) {

for (int s = 0; s < min({(j) + 1, N}); ++s) {

for (int k = max({j, 0}); k < min({(i) + 1, N}); ++k) {

for (int l = 0; l < N; ++l) {

for (int t = max({i, 0}); t < min({(l) + 1, N}); ++t) {







J[i][j][k][l][s][t] += J[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int j = 0; j < N; ++j) {

for (int s = 0; s < min({(j) + 1, N}); ++s) {

for (int k = 0; k < N; ++k) {

for (int t = max({k, 0}); t < min({(i) + 1, N}); ++t) {

for (int l = max({j, 0}); l < min({(k) + 1, N}); ++l) {







J[i][j][k][l][s][t] += J[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int t = max({i, 0}); t < N; ++t) {

for (int k = 0; k < min({(i) + 1, N}); ++k) {

for (int j = 0; j < N; ++j) {

for (int s = 0; s < min({(j) + 1, N}); ++s) {

for (int l = max({j, 0}); l < min({(k) + 1, N}); ++l) {







J[i][j][k][l][s][t] += J[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int j = 0; j < N; ++j) {

for (int k = 0; k < min({(i) + 1, N}); ++k) {

for (int s = 0; s < min({(j) + 1, N}); ++s) {

for (int l = max({j, 0}); l < N; ++l) {

for (int t = max({l, 0}); t < min({(k) + 1, N}); ++t) {







J[i][j][k][l][s][t] += J[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int j = 0; j < N; ++j) {

for (int k = max({i, 0}); k < N; ++k) {

for (int s = 0; s < min({(j) + 1, N}); ++s) {

for (int l = max({j, 0}); l < N; ++l) {

for (int t = max({l, 0}); t < min({(i) + 1, N}); ++t) {







J[i][j][k][l][s][t] += J[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int j = 0; j < N; ++j) {

for (int k = max({i, 0}); k < N; ++k) {

for (int s = 0; s < min({(j) + 1, N}); ++s) {

for (int l = max({j, 0}); l < min({(i) + 1, N}); ++l) {

for (int t = max({k, 0}); t < N; ++t) {







J[i][j][k][l][s][t] += J[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int j = 0; j < N; ++j) {

for (int s = 0; s < min({(j) + 1, N}); ++s) {

for (int l = max({j, 0}); l < min({(i) + 1, N}); ++l) {

for (int k = 0; k < N; ++k) {

for (int t = max({i, 0}); t < min({(k) + 1, N}); ++t) {







J[i][j][k][l][s][t] += J[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int j = 0; j < N; ++j) {

for (int s = 0; s < min({(j) + 1, N}); ++s) {

for (int k = 0; k < N; ++k) {

for (int t = max({j, 0}); t < min({(k) + 1, N}); ++t) {

for (int l = max({k, 0}); l < min({(i) + 1, N}); ++l) {







J[i][j][k][l][s][t] += J[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int l = max({i, 0}); l < N; ++l) {

for (int k = 0; k < min({(i) + 1, N}); ++k) {

for (int j = 0; j < N; ++j) {

for (int s = 0; s < min({(j) + 1, N}); ++s) {

for (int t = max({j, 0}); t < min({(k) + 1, N}); ++t) {







J[i][j][k][l][s][t] += J[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int j = 0; j < N; ++j) {

for (int k = 0; k < min({(i) + 1, N}); ++k) {

for (int s = 0; s < min({(j) + 1, N}); ++s) {

for (int l = 0; l < min({(k) + 1, N}); ++l) {

for (int t = max({j, 0}); t < min({(l) + 1, N}); ++t) {







J[i][j][k][l][s][t] += J[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int l = 0; l < min({(i) + 1, N}); ++l) {

for (int k = max({i, 0}); k < N; ++k) {

for (int j = 0; j < N; ++j) {

for (int s = 0; s < min({(j) + 1, N}); ++s) {

for (int t = max({j, 0}); t < min({(l) + 1, N}); ++t) {







J[i][j][k][l][s][t] += J[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int j = 0; j < N; ++j) {

for (int k = max({i, 0}); k < N; ++k) {

for (int s = 0; s < min({(j) + 1, N}); ++s) {

for (int t = max({j, 0}); t < min({(i) + 1, N}); ++t) {

for (int l = max({k, 0}); l < N; ++l) {







J[i][j][k][l][s][t] += J[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int j = 0; j < N; ++j) {

for (int s = 0; s < min({(j) + 1, N}); ++s) {

for (int t = max({j, 0}); t < min({(i) + 1, N}); ++t) {

for (int k = 0; k < N; ++k) {

for (int l = max({i, 0}); l < min({(k) + 1, N}); ++l) {







J[i][j][k][l][s][t] += J[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int j = 0; j < min({(i) + 1, N}); ++j) {

for (int k = max({i, 0}); k < N; ++k) {

for (int s = 0; s < min({(j) + 1, N}); ++s) {

for (int l = max({k, 0}); l < N; ++l) {

for (int t = max({l, 0}); t < N; ++t) {







J[i][j][k][l][s][t] += J[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int j = 0; j < min({(i) + 1, N}); ++j) {

for (int k = max({i, 0}); k < N; ++k) {

for (int s = 0; s < min({(j) + 1, N}); ++s) {

for (int l = 0; l < N; ++l) {

for (int t = max({k, 0}); t < min({(l) + 1, N}); ++t) {







J[i][j][k][l][s][t] += J[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int j = 0; j < min({(i) + 1, N}); ++j) {

for (int s = 0; s < min({(j) + 1, N}); ++s) {

for (int k = 0; k < N; ++k) {

for (int t = max({k, 0}); t < N; ++t) {

for (int l = max({i, 0}); l < min({(k) + 1, N}); ++l) {







J[i][j][k][l][s][t] += J[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int l = max({i, 0}); l < N; ++l) {

for (int j = 0; j < min({(i) + 1, N}); ++j) {

for (int s = 0; s < min({(j) + 1, N}); ++s) {

for (int k = 0; k < N; ++k) {

for (int t = max({l, 0}); t < min({(k) + 1, N}); ++t) {







J[i][j][k][l][s][t] += J[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int j = 0; j < min({(i) + 1, N}); ++j) {

for (int s = 0; s < min({(j) + 1, N}); ++s) {

for (int k = 0; k < N; ++k) {

for (int t = max({i, 0}); t < min({(k) + 1, N}); ++t) {

for (int l = max({k, 0}); l < N; ++l) {







J[i][j][k][l][s][t] += J[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int j = 0; j < min({(i) + 1, N}); ++j) {

for (int s = 0; s < min({(j) + 1, N}); ++s) {

for (int k = 0; k < N; ++k) {

for (int l = 0; l < min({(k) + 1, N}); ++l) {

for (int t = max({i, 0}); t < min({(l) + 1, N}); ++t) {







J[i][j][k][l][s][t] += J[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int j = 0; j < N; ++j) {

for (int l = max({j, 0}); l < N; ++l) {

for (int k = 0; k < min({(j) + 1, N}); ++k) {

for (int t = max({l, 0}); t < min({(i) + 1, N}); ++t) {

for (int s = 0; s < min({(k) + 1, N}); ++s) {







J[i][j][k][l][s][t] += J[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int t = max({i, 0}); t < N; ++t) {

for (int j = 0; j < N; ++j) {

for (int l = max({j, 0}); l < min({(i) + 1, N}); ++l) {

for (int k = 0; k < min({(j) + 1, N}); ++k) {

for (int s = 0; s < min({(k) + 1, N}); ++s) {







J[i][j][k][l][s][t] += J[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int l = 0; l < min({(i) + 1, N}); ++l) {

for (int j = 0; j < N; ++j) {

for (int t = max({j, 0}); t < min({(l) + 1, N}); ++t) {

for (int k = 0; k < min({(j) + 1, N}); ++k) {

for (int s = 0; s < min({(k) + 1, N}); ++s) {







J[i][j][k][l][s][t] += J[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int l = max({i, 0}); l < N; ++l) {

for (int j = 0; j < N; ++j) {

for (int t = max({j, 0}); t < min({(i) + 1, N}); ++t) {

for (int k = 0; k < min({(j) + 1, N}); ++k) {

for (int s = 0; s < min({(k) + 1, N}); ++s) {







J[i][j][k][l][s][t] += J[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int l = max({i, 0}); l < N; ++l) {

for (int j = 0; j < min({(i) + 1, N}); ++j) {

for (int t = max({l, 0}); t < N; ++t) {

for (int k = 0; k < min({(j) + 1, N}); ++k) {

for (int s = 0; s < min({(k) + 1, N}); ++s) {







J[i][j][k][l][s][t] += J[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int j = 0; j < min({(i) + 1, N}); ++j) {

for (int k = 0; k < min({(j) + 1, N}); ++k) {

for (int s = 0; s < min({(k) + 1, N}); ++s) {

for (int l = 0; l < N; ++l) {

for (int t = max({i, 0}); t < min({(l) + 1, N}); ++t) {







J[i][j][k][l][s][t] += J[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int j = 0; j < N; ++j) {

for (int t = max({j, 0}); t < min({(i) + 1, N}); ++t) {

for (int k = 0; k < N; ++k) {

for (int s = 0; s < min({(k) + 1, N}); ++s) {

for (int l = max({k, 0}); l < min({(j) + 1, N}); ++l) {







J[i][j][k][l][s][t] += J[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int t = max({i, 0}); t < N; ++t) {

for (int j = 0; j < min({(i) + 1, N}); ++j) {

for (int k = 0; k < N; ++k) {

for (int s = 0; s < min({(k) + 1, N}); ++s) {

for (int l = max({k, 0}); l < min({(j) + 1, N}); ++l) {







J[i][j][k][l][s][t] += J[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int j = 0; j < min({(i) + 1, N}); ++j) {

for (int k = 0; k < N; ++k) {

for (int s = 0; s < min({(k) + 1, N}); ++s) {

for (int l = max({k, 0}); l < N; ++l) {

for (int t = max({l, 0}); t < min({(j) + 1, N}); ++t) {







J[i][j][k][l][s][t] += J[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int j = max({i, 0}); j < N; ++j) {

for (int k = 0; k < N; ++k) {

for (int s = 0; s < min({(k) + 1, N}); ++s) {

for (int l = max({k, 0}); l < N; ++l) {

for (int t = max({l, 0}); t < min({(i) + 1, N}); ++t) {







J[i][j][k][l][s][t] += J[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int j = max({i, 0}); j < N; ++j) {

for (int t = max({j, 0}); t < N; ++t) {

for (int k = 0; k < N; ++k) {

for (int s = 0; s < min({(k) + 1, N}); ++s) {

for (int l = max({k, 0}); l < min({(i) + 1, N}); ++l) {







J[i][j][k][l][s][t] += J[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int j = 0; j < N; ++j) {

for (int t = max({i, 0}); t < min({(j) + 1, N}); ++t) {

for (int k = 0; k < N; ++k) {

for (int s = 0; s < min({(k) + 1, N}); ++s) {

for (int l = max({k, 0}); l < min({(i) + 1, N}); ++l) {







J[i][j][k][l][s][t] += J[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int j = 0; j < N; ++j) {

for (int l = max({j, 0}); l < min({(i) + 1, N}); ++l) {

for (int k = 0; k < N; ++k) {

for (int s = 0; s < min({(k) + 1, N}); ++s) {

for (int t = max({k, 0}); t < min({(j) + 1, N}); ++t) {







J[i][j][k][l][s][t] += J[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int l = max({i, 0}); l < N; ++l) {

for (int j = 0; j < min({(i) + 1, N}); ++j) {

for (int k = 0; k < N; ++k) {

for (int s = 0; s < min({(k) + 1, N}); ++s) {

for (int t = max({k, 0}); t < min({(j) + 1, N}); ++t) {







J[i][j][k][l][s][t] += J[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int j = 0; j < min({(i) + 1, N}); ++j) {

for (int l = 0; l < min({(j) + 1, N}); ++l) {

for (int k = 0; k < N; ++k) {

for (int s = 0; s < min({(k) + 1, N}); ++s) {

for (int t = max({k, 0}); t < min({(l) + 1, N}); ++t) {







J[i][j][k][l][s][t] += J[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int l = 0; l < min({(i) + 1, N}); ++l) {

for (int j = max({i, 0}); j < N; ++j) {

for (int k = 0; k < N; ++k) {

for (int s = 0; s < min({(k) + 1, N}); ++s) {

for (int t = max({k, 0}); t < min({(l) + 1, N}); ++t) {







J[i][j][k][l][s][t] += J[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int j = max({i, 0}); j < N; ++j) {

for (int l = max({j, 0}); l < N; ++l) {

for (int k = 0; k < N; ++k) {

for (int s = 0; s < min({(k) + 1, N}); ++s) {

for (int t = max({k, 0}); t < min({(i) + 1, N}); ++t) {







J[i][j][k][l][s][t] += J[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int j = 0; j < N; ++j) {

for (int l = max({i, 0}); l < min({(j) + 1, N}); ++l) {

for (int k = 0; k < N; ++k) {

for (int s = 0; s < min({(k) + 1, N}); ++s) {

for (int t = max({k, 0}); t < min({(i) + 1, N}); ++t) {







J[i][j][k][l][s][t] += J[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int j = max({i, 0}); j < N; ++j) {

for (int k = 0; k < min({(i) + 1, N}); ++k) {

for (int l = max({j, 0}); l < N; ++l) {

for (int s = 0; s < min({(k) + 1, N}); ++s) {

for (int t = max({l, 0}); t < N; ++t) {







J[i][j][k][l][s][t] += J[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int j = max({i, 0}); j < N; ++j) {

for (int k = 0; k < min({(i) + 1, N}); ++k) {

for (int s = 0; s < min({(k) + 1, N}); ++s) {

for (int l = 0; l < N; ++l) {

for (int t = max({j, 0}); t < min({(l) + 1, N}); ++t) {







J[i][j][k][l][s][t] += J[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int j = 0; j < N; ++j) {

for (int k = 0; k < min({(i) + 1, N}); ++k) {

for (int t = max({j, 0}); t < N; ++t) {

for (int l = max({i, 0}); l < min({(j) + 1, N}); ++l) {

for (int s = 0; s < min({(k) + 1, N}); ++s) {







J[i][j][k][l][s][t] += J[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int l = max({i, 0}); l < N; ++l) {

for (int k = 0; k < min({(i) + 1, N}); ++k) {

for (int s = 0; s < min({(k) + 1, N}); ++s) {

for (int j = 0; j < N; ++j) {

for (int t = max({l, 0}); t < min({(j) + 1, N}); ++t) {







J[i][j][k][l][s][t] += J[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int j = 0; j < N; ++j) {

for (int k = 0; k < min({(i) + 1, N}); ++k) {

for (int t = max({i, 0}); t < min({(j) + 1, N}); ++t) {

for (int l = max({j, 0}); l < N; ++l) {

for (int s = 0; s < min({(k) + 1, N}); ++s) {







J[i][j][k][l][s][t] += J[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int j = 0; j < N; ++j) {

for (int k = 0; k < min({(i) + 1, N}); ++k) {

for (int l = 0; l < min({(j) + 1, N}); ++l) {

for (int s = 0; s < min({(k) + 1, N}); ++s) {

for (int t = max({i, 0}); t < min({(l) + 1, N}); ++t) {







J[i][j][k][l][s][t] += J[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int j = 0; j < N; ++j) {

for (int l = 0; l < min({(j) + 1, N}); ++l) {

for (int k = max({j, 0}); k < N; ++k) {

for (int s = 0; s < min({(l) + 1, N}); ++s) {

for (int t = max({k, 0}); t < min({(i) + 1, N}); ++t) {







J[i][j][k][l][s][t] += J[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int t = max({i, 0}); t < N; ++t) {

for (int j = 0; j < N; ++j) {

for (int l = 0; l < min({(j) + 1, N}); ++l) {

for (int k = max({j, 0}); k < min({(i) + 1, N}); ++k) {

for (int s = 0; s < min({(l) + 1, N}); ++s) {







J[i][j][k][l][s][t] += J[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int j = 0; j < N; ++j) {

for (int k = 0; k < min({(i) + 1, N}); ++k) {

for (int l = 0; l < min({(j) + 1, N}); ++l) {

for (int t = max({j, 0}); t < min({(k) + 1, N}); ++t) {

for (int s = 0; s < min({(l) + 1, N}); ++s) {







J[i][j][k][l][s][t] += J[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int j = 0; j < N; ++j) {

for (int k = max({i, 0}); k < N; ++k) {

for (int t = max({j, 0}); t < min({(i) + 1, N}); ++t) {

for (int l = 0; l < min({(j) + 1, N}); ++l) {

for (int s = 0; s < min({(l) + 1, N}); ++s) {







J[i][j][k][l][s][t] += J[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int j = 0; j < min({(i) + 1, N}); ++j) {

for (int k = max({i, 0}); k < N; ++k) {

for (int l = 0; l < min({(j) + 1, N}); ++l) {

for (int t = max({k, 0}); t < N; ++t) {

for (int s = 0; s < min({(l) + 1, N}); ++s) {







J[i][j][k][l][s][t] += J[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int j = 0; j < min({(i) + 1, N}); ++j) {

for (int l = 0; l < min({(j) + 1, N}); ++l) {

for (int s = 0; s < min({(l) + 1, N}); ++s) {

for (int k = 0; k < N; ++k) {

for (int t = max({i, 0}); t < min({(k) + 1, N}); ++t) {







J[i][j][k][l][s][t] += J[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int j = 0; j < N; ++j) {

for (int t = max({j, 0}); t < min({(i) + 1, N}); ++t) {

for (int k = 0; k < min({(j) + 1, N}); ++k) {

for (int l = 0; l < min({(k) + 1, N}); ++l) {

for (int s = 0; s < min({(l) + 1, N}); ++s) {







J[i][j][k][l][s][t] += J[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int t = max({i, 0}); t < N; ++t) {

for (int j = 0; j < min({(i) + 1, N}); ++j) {

for (int k = 0; k < min({(j) + 1, N}); ++k) {

for (int l = 0; l < min({(k) + 1, N}); ++l) {

for (int s = 0; s < min({(l) + 1, N}); ++s) {







J[i][j][k][l][s][t] += J[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int j = 0; j < min({(i) + 1, N}); ++j) {

for (int k = 0; k < N; ++k) {

for (int t = max({k, 0}); t < min({(j) + 1, N}); ++t) {

for (int l = 0; l < min({(k) + 1, N}); ++l) {

for (int s = 0; s < min({(l) + 1, N}); ++s) {







J[i][j][k][l][s][t] += J[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int j = max({i, 0}); j < N; ++j) {

for (int k = 0; k < N; ++k) {

for (int t = max({k, 0}); t < min({(i) + 1, N}); ++t) {

for (int l = 0; l < min({(k) + 1, N}); ++l) {

for (int s = 0; s < min({(l) + 1, N}); ++s) {







J[i][j][k][l][s][t] += J[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int j = max({i, 0}); j < N; ++j) {

for (int k = 0; k < min({(i) + 1, N}); ++k) {

for (int t = max({j, 0}); t < N; ++t) {

for (int l = 0; l < min({(k) + 1, N}); ++l) {

for (int s = 0; s < min({(l) + 1, N}); ++s) {







J[i][j][k][l][s][t] += J[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int j = 0; j < N; ++j) {

for (int k = 0; k < min({(i) + 1, N}); ++k) {

for (int t = max({i, 0}); t < min({(j) + 1, N}); ++t) {

for (int l = 0; l < min({(k) + 1, N}); ++l) {

for (int s = 0; s < min({(l) + 1, N}); ++s) {







J[i][j][k][l][s][t] += J[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int j = 0; j < N; ++j) {

for (int k = max({j, 0}); k < min({(i) + 1, N}); ++k) {

for (int l = 0; l < N; ++l) {

for (int s = 0; s < min({(l) + 1, N}); ++s) {

for (int t = max({l, 0}); t < min({(j) + 1, N}); ++t) {







J[i][j][k][l][s][t] += J[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int j = 0; j < min({(i) + 1, N}); ++j) {

for (int k = max({i, 0}); k < N; ++k) {

for (int l = 0; l < N; ++l) {

for (int s = 0; s < min({(l) + 1, N}); ++s) {

for (int t = max({l, 0}); t < min({(j) + 1, N}); ++t) {







J[i][j][k][l][s][t] += J[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int j = 0; j < min({(i) + 1, N}); ++j) {

for (int k = 0; k < min({(j) + 1, N}); ++k) {

for (int l = 0; l < N; ++l) {

for (int s = 0; s < min({(l) + 1, N}); ++s) {

for (int t = max({l, 0}); t < min({(k) + 1, N}); ++t) {







J[i][j][k][l][s][t] += J[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int j = max({i, 0}); j < N; ++j) {

for (int k = 0; k < min({(i) + 1, N}); ++k) {

for (int l = 0; l < N; ++l) {

for (int s = 0; s < min({(l) + 1, N}); ++s) {

for (int t = max({l, 0}); t < min({(k) + 1, N}); ++t) {







J[i][j][k][l][s][t] += J[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int j = max({i, 0}); j < N; ++j) {

for (int k = max({j, 0}); k < N; ++k) {

for (int l = 0; l < N; ++l) {

for (int s = 0; s < min({(l) + 1, N}); ++s) {

for (int t = max({l, 0}); t < min({(i) + 1, N}); ++t) {







J[i][j][k][l][s][t] += J[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int j = 0; j < N; ++j) {

for (int k = max({i, 0}); k < min({(j) + 1, N}); ++k) {

for (int l = 0; l < N; ++l) {

for (int s = 0; s < min({(l) + 1, N}); ++s) {

for (int t = max({l, 0}); t < min({(i) + 1, N}); ++t) {







J[i][j][k][l][s][t] += J[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int l = 0; l < min({(i) + 1, N}); ++l) {

for (int j = max({i, 0}); j < N; ++j) {

for (int s = 0; s < min({(l) + 1, N}); ++s) {

for (int k = max({j, 0}); k < N; ++k) {

for (int t = max({k, 0}); t < N; ++t) {







J[i][j][k][l][s][t] += J[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int l = 0; l < min({(i) + 1, N}); ++l) {

for (int j = max({i, 0}); j < N; ++j) {

for (int s = 0; s < min({(l) + 1, N}); ++s) {

for (int k = 0; k < N; ++k) {

for (int t = max({j, 0}); t < min({(k) + 1, N}); ++t) {







J[i][j][k][l][s][t] += J[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int l = 0; l < min({(i) + 1, N}); ++l) {

for (int s = 0; s < min({(l) + 1, N}); ++s) {

for (int j = 0; j < N; ++j) {

for (int t = max({j, 0}); t < N; ++t) {

for (int k = max({i, 0}); k < min({(j) + 1, N}); ++k) {







J[i][j][k][l][s][t] += J[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int l = 0; l < min({(i) + 1, N}); ++l) {

for (int k = max({i, 0}); k < N; ++k) {

for (int s = 0; s < min({(l) + 1, N}); ++s) {

for (int j = 0; j < N; ++j) {

for (int t = max({k, 0}); t < min({(j) + 1, N}); ++t) {







J[i][j][k][l][s][t] += J[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int l = 0; l < min({(i) + 1, N}); ++l) {

for (int s = 0; s < min({(l) + 1, N}); ++s) {

for (int j = 0; j < N; ++j) {

for (int t = max({i, 0}); t < min({(j) + 1, N}); ++t) {

for (int k = max({j, 0}); k < N; ++k) {







J[i][j][k][l][s][t] += J[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int l = 0; l < min({(i) + 1, N}); ++l) {

for (int s = 0; s < min({(l) + 1, N}); ++s) {

for (int j = 0; j < N; ++j) {

for (int k = 0; k < min({(j) + 1, N}); ++k) {

for (int t = max({i, 0}); t < min({(k) + 1, N}); ++t) {







J[i][j][k][l][s][t] += J[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int j = 0; j < N; ++j) {

for (int k = max({j, 0}); k < N; ++k) {

for (int l = max({k, 0}); l < min({(i) + 1, N}); ++l) {

for (int s = 0; s < N; ++s) {

for (int t = max({s, 0}); t < min({(j) + 1, N}); ++t) {







J[i][j][k][l][s][t] += J[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int l = max({i, 0}); l < N; ++l) {

for (int j = 0; j < N; ++j) {

for (int k = max({j, 0}); k < min({(i) + 1, N}); ++k) {

for (int s = 0; s < N; ++s) {

for (int t = max({s, 0}); t < min({(j) + 1, N}); ++t) {







J[i][j][k][l][s][t] += J[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int j = 0; j < N; ++j) {

for (int k = 0; k < min({(i) + 1, N}); ++k) {

for (int l = max({j, 0}); l < min({(k) + 1, N}); ++l) {

for (int s = 0; s < N; ++s) {

for (int t = max({s, 0}); t < min({(j) + 1, N}); ++t) {







J[i][j][k][l][s][t] += J[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int j = 0; j < N; ++j) {

for (int k = max({i, 0}); k < N; ++k) {

for (int l = max({j, 0}); l < min({(i) + 1, N}); ++l) {

for (int s = 0; s < N; ++s) {

for (int t = max({s, 0}); t < min({(j) + 1, N}); ++t) {







J[i][j][k][l][s][t] += J[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int j = 0; j < min({(i) + 1, N}); ++j) {

for (int k = max({i, 0}); k < N; ++k) {

for (int l = max({k, 0}); l < N; ++l) {

for (int s = 0; s < N; ++s) {

for (int t = max({s, 0}); t < min({(j) + 1, N}); ++t) {







J[i][j][k][l][s][t] += J[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int j = 0; j < min({(i) + 1, N}); ++j) {

for (int k = 0; k < N; ++k) {

for (int l = max({i, 0}); l < min({(k) + 1, N}); ++l) {

for (int s = 0; s < N; ++s) {

for (int t = max({s, 0}); t < min({(j) + 1, N}); ++t) {







J[i][j][k][l][s][t] += J[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int j = 0; j < N; ++j) {

for (int l = max({j, 0}); l < min({(i) + 1, N}); ++l) {

for (int k = 0; k < min({(j) + 1, N}); ++k) {

for (int s = 0; s < N; ++s) {

for (int t = max({s, 0}); t < min({(k) + 1, N}); ++t) {







J[i][j][k][l][s][t] += J[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int l = max({i, 0}); l < N; ++l) {

for (int j = 0; j < min({(i) + 1, N}); ++j) {

for (int k = 0; k < min({(j) + 1, N}); ++k) {

for (int s = 0; s < N; ++s) {

for (int t = max({s, 0}); t < min({(k) + 1, N}); ++t) {







J[i][j][k][l][s][t] += J[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int j = 0; j < min({(i) + 1, N}); ++j) {

for (int k = 0; k < N; ++k) {

for (int l = max({k, 0}); l < min({(j) + 1, N}); ++l) {

for (int s = 0; s < N; ++s) {

for (int t = max({s, 0}); t < min({(k) + 1, N}); ++t) {







J[i][j][k][l][s][t] += J[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int j = max({i, 0}); j < N; ++j) {

for (int k = 0; k < N; ++k) {

for (int l = max({k, 0}); l < min({(i) + 1, N}); ++l) {

for (int s = 0; s < N; ++s) {

for (int t = max({s, 0}); t < min({(k) + 1, N}); ++t) {







J[i][j][k][l][s][t] += J[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int j = max({i, 0}); j < N; ++j) {

for (int k = 0; k < min({(i) + 1, N}); ++k) {

for (int l = max({j, 0}); l < N; ++l) {

for (int s = 0; s < N; ++s) {

for (int t = max({s, 0}); t < min({(k) + 1, N}); ++t) {







J[i][j][k][l][s][t] += J[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int j = 0; j < N; ++j) {

for (int k = 0; k < min({(i) + 1, N}); ++k) {

for (int l = max({i, 0}); l < min({(j) + 1, N}); ++l) {

for (int s = 0; s < N; ++s) {

for (int t = max({s, 0}); t < min({(k) + 1, N}); ++t) {







J[i][j][k][l][s][t] += J[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int j = 0; j < N; ++j) {

for (int l = 0; l < min({(j) + 1, N}); ++l) {

for (int k = max({j, 0}); k < min({(i) + 1, N}); ++k) {

for (int s = 0; s < N; ++s) {

for (int t = max({s, 0}); t < min({(l) + 1, N}); ++t) {







J[i][j][k][l][s][t] += J[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int j = 0; j < min({(i) + 1, N}); ++j) {

for (int k = max({i, 0}); k < N; ++k) {

for (int l = 0; l < min({(j) + 1, N}); ++l) {

for (int s = 0; s < N; ++s) {

for (int t = max({s, 0}); t < min({(l) + 1, N}); ++t) {







J[i][j][k][l][s][t] += J[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int j = 0; j < min({(i) + 1, N}); ++j) {

for (int k = 0; k < min({(j) + 1, N}); ++k) {

for (int l = 0; l < min({(k) + 1, N}); ++l) {

for (int s = 0; s < N; ++s) {

for (int t = max({s, 0}); t < min({(l) + 1, N}); ++t) {







J[i][j][k][l][s][t] += J[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int j = max({i, 0}); j < N; ++j) {

for (int k = 0; k < min({(i) + 1, N}); ++k) {

for (int l = 0; l < min({(k) + 1, N}); ++l) {

for (int s = 0; s < N; ++s) {

for (int t = max({s, 0}); t < min({(l) + 1, N}); ++t) {







J[i][j][k][l][s][t] += J[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int l = 0; l < min({(i) + 1, N}); ++l) {

for (int j = max({i, 0}); j < N; ++j) {

for (int k = max({j, 0}); k < N; ++k) {

for (int s = 0; s < N; ++s) {

for (int t = max({s, 0}); t < min({(l) + 1, N}); ++t) {







J[i][j][k][l][s][t] += J[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int l = 0; l < min({(i) + 1, N}); ++l) {

for (int j = 0; j < N; ++j) {

for (int k = max({i, 0}); k < min({(j) + 1, N}); ++k) {

for (int s = 0; s < N; ++s) {

for (int t = max({s, 0}); t < min({(l) + 1, N}); ++t) {







J[i][j][k][l][s][t] += J[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int j = max({i, 0}); j < N; ++j) {

for (int k = max({j, 0}); k < N; ++k) {

for (int l = max({k, 0}); l < N; ++l) {

for (int s = 0; s < N; ++s) {

for (int t = max({s, 0}); t < min({(i) + 1, N}); ++t) {







J[i][j][k][l][s][t] += J[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int j = max({i, 0}); j < N; ++j) {

for (int k = 0; k < N; ++k) {

for (int l = max({j, 0}); l < min({(k) + 1, N}); ++l) {

for (int s = 0; s < N; ++s) {

for (int t = max({s, 0}); t < min({(i) + 1, N}); ++t) {







J[i][j][k][l][s][t] += J[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int j = 0; j < N; ++j) {

for (int l = max({j, 0}); l < N; ++l) {

for (int k = max({i, 0}); k < min({(j) + 1, N}); ++k) {

for (int s = 0; s < N; ++s) {

for (int t = max({s, 0}); t < min({(i) + 1, N}); ++t) {







J[i][j][k][l][s][t] += J[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int j = 0; j < N; ++j) {

for (int k = max({i, 0}); k < N; ++k) {

for (int l = max({k, 0}); l < min({(j) + 1, N}); ++l) {

for (int s = 0; s < N; ++s) {

for (int t = max({s, 0}); t < min({(i) + 1, N}); ++t) {







J[i][j][k][l][s][t] += J[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int j = 0; j < N; ++j) {

for (int l = max({i, 0}); l < min({(j) + 1, N}); ++l) {

for (int k = max({j, 0}); k < N; ++k) {

for (int s = 0; s < N; ++s) {

for (int t = max({s, 0}); t < min({(i) + 1, N}); ++t) {







J[i][j][k][l][s][t] += J[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int j = 0; j < N; ++j) {

for (int k = 0; k < min({(j) + 1, N}); ++k) {

for (int l = max({i, 0}); l < min({(k) + 1, N}); ++l) {

for (int s = 0; s < N; ++s) {

for (int t = max({s, 0}); t < min({(i) + 1, N}); ++t) {







J[i][j][k][l][s][t] += J[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int s = 0; s < min({(i) + 1, N}); ++s) {

for (int j = max({i, 0}); j < N; ++j) {

for (int k = max({j, 0}); k < N; ++k) {

for (int l = max({k, 0}); l < N; ++l) {

for (int t = max({l, 0}); t < N; ++t) {







J[i][j][k][l][s][t] += J[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int s = 0; s < min({(i) + 1, N}); ++s) {

for (int j = max({i, 0}); j < N; ++j) {

for (int k = max({j, 0}); k < N; ++k) {

for (int l = 0; l < N; ++l) {

for (int t = max({k, 0}); t < min({(l) + 1, N}); ++t) {







J[i][j][k][l][s][t] += J[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int s = 0; s < min({(i) + 1, N}); ++s) {

for (int j = max({i, 0}); j < N; ++j) {

for (int k = 0; k < N; ++k) {

for (int t = max({k, 0}); t < N; ++t) {

for (int l = max({j, 0}); l < min({(k) + 1, N}); ++l) {







J[i][j][k][l][s][t] += J[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int s = 0; s < min({(i) + 1, N}); ++s) {

for (int j = max({i, 0}); j < N; ++j) {

for (int l = max({j, 0}); l < N; ++l) {

for (int k = 0; k < N; ++k) {

for (int t = max({l, 0}); t < min({(k) + 1, N}); ++t) {







J[i][j][k][l][s][t] += J[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int s = 0; s < min({(i) + 1, N}); ++s) {

for (int j = max({i, 0}); j < N; ++j) {

for (int k = 0; k < N; ++k) {

for (int t = max({j, 0}); t < min({(k) + 1, N}); ++t) {

for (int l = max({k, 0}); l < N; ++l) {







J[i][j][k][l][s][t] += J[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int s = 0; s < min({(i) + 1, N}); ++s) {

for (int j = max({i, 0}); j < N; ++j) {

for (int k = 0; k < N; ++k) {

for (int l = 0; l < min({(k) + 1, N}); ++l) {

for (int t = max({j, 0}); t < min({(l) + 1, N}); ++t) {







J[i][j][k][l][s][t] += J[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int s = 0; s < min({(i) + 1, N}); ++s) {

for (int j = 0; j < N; ++j) {

for (int l = max({j, 0}); l < N; ++l) {

for (int k = max({i, 0}); k < min({(j) + 1, N}); ++k) {

for (int t = max({l, 0}); t < N; ++t) {







J[i][j][k][l][s][t] += J[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int s = 0; s < min({(i) + 1, N}); ++s) {

for (int j = 0; j < N; ++j) {

for (int k = max({i, 0}); k < min({(j) + 1, N}); ++k) {

for (int l = 0; l < N; ++l) {

for (int t = max({j, 0}); t < min({(l) + 1, N}); ++t) {







J[i][j][k][l][s][t] += J[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int s = 0; s < min({(i) + 1, N}); ++s) {

for (int k = max({i, 0}); k < N; ++k) {

for (int j = 0; j < N; ++j) {

for (int t = max({j, 0}); t < N; ++t) {

for (int l = max({k, 0}); l < min({(j) + 1, N}); ++l) {







J[i][j][k][l][s][t] += J[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int s = 0; s < min({(i) + 1, N}); ++s) {

for (int k = max({i, 0}); k < N; ++k) {

for (int l = max({k, 0}); l < N; ++l) {

for (int j = 0; j < N; ++j) {

for (int t = max({l, 0}); t < min({(j) + 1, N}); ++t) {







J[i][j][k][l][s][t] += J[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int s = 0; s < min({(i) + 1, N}); ++s) {

for (int k = max({i, 0}); k < N; ++k) {

for (int j = 0; j < N; ++j) {

for (int t = max({k, 0}); t < min({(j) + 1, N}); ++t) {

for (int l = max({j, 0}); l < N; ++l) {







J[i][j][k][l][s][t] += J[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int s = 0; s < min({(i) + 1, N}); ++s) {

for (int k = max({i, 0}); k < N; ++k) {

for (int j = 0; j < N; ++j) {

for (int l = 0; l < min({(j) + 1, N}); ++l) {

for (int t = max({k, 0}); t < min({(l) + 1, N}); ++t) {







J[i][j][k][l][s][t] += J[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int s = 0; s < min({(i) + 1, N}); ++s) {

for (int j = 0; j < N; ++j) {

for (int l = max({i, 0}); l < min({(j) + 1, N}); ++l) {

for (int k = max({j, 0}); k < N; ++k) {

for (int t = max({k, 0}); t < N; ++t) {







J[i][j][k][l][s][t] += J[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int s = 0; s < min({(i) + 1, N}); ++s) {

for (int j = 0; j < N; ++j) {

for (int l = max({i, 0}); l < min({(j) + 1, N}); ++l) {

for (int k = 0; k < N; ++k) {

for (int t = max({j, 0}); t < min({(k) + 1, N}); ++t) {







J[i][j][k][l][s][t] += J[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int s = 0; s < min({(i) + 1, N}); ++s) {

for (int j = 0; j < N; ++j) {

for (int t = max({j, 0}); t < N; ++t) {

for (int k = 0; k < min({(j) + 1, N}); ++k) {

for (int l = max({i, 0}); l < min({(k) + 1, N}); ++l) {







J[i][j][k][l][s][t] += J[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int s = 0; s < min({(i) + 1, N}); ++s) {

for (int j = 0; j < N; ++j) {

for (int k = 0; k < N; ++k) {

for (int t = max({k, 0}); t < min({(j) + 1, N}); ++t) {

for (int l = max({i, 0}); l < min({(k) + 1, N}); ++l) {







J[i][j][k][l][s][t] += J[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int s = 0; s < min({(i) + 1, N}); ++s) {

for (int l = max({i, 0}); l < N; ++l) {

for (int j = 0; j < N; ++j) {

for (int t = max({l, 0}); t < min({(j) + 1, N}); ++t) {

for (int k = max({j, 0}); k < N; ++k) {







J[i][j][k][l][s][t] += J[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int s = 0; s < min({(i) + 1, N}); ++s) {

for (int l = max({i, 0}); l < N; ++l) {

for (int j = 0; j < N; ++j) {

for (int k = 0; k < min({(j) + 1, N}); ++k) {

for (int t = max({l, 0}); t < min({(k) + 1, N}); ++t) {







J[i][j][k][l][s][t] += J[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int s = 0; s < min({(i) + 1, N}); ++s) {

for (int j = 0; j < N; ++j) {

for (int t = max({i, 0}); t < min({(j) + 1, N}); ++t) {

for (int k = max({j, 0}); k < N; ++k) {

for (int l = max({k, 0}); l < N; ++l) {







J[i][j][k][l][s][t] += J[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int s = 0; s < min({(i) + 1, N}); ++s) {

for (int j = 0; j < N; ++j) {

for (int t = max({i, 0}); t < min({(j) + 1, N}); ++t) {

for (int k = 0; k < N; ++k) {

for (int l = max({j, 0}); l < min({(k) + 1, N}); ++l) {







J[i][j][k][l][s][t] += J[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int s = 0; s < min({(i) + 1, N}); ++s) {

for (int j = 0; j < N; ++j) {

for (int l = max({j, 0}); l < N; ++l) {

for (int k = 0; k < min({(j) + 1, N}); ++k) {

for (int t = max({i, 0}); t < min({(k) + 1, N}); ++t) {







J[i][j][k][l][s][t] += J[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int s = 0; s < min({(i) + 1, N}); ++s) {

for (int j = 0; j < N; ++j) {

for (int k = 0; k < N; ++k) {

for (int t = max({i, 0}); t < min({(k) + 1, N}); ++t) {

for (int l = max({k, 0}); l < min({(j) + 1, N}); ++l) {







J[i][j][k][l][s][t] += J[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int s = 0; s < min({(i) + 1, N}); ++s) {

for (int j = 0; j < N; ++j) {

for (int l = 0; l < min({(j) + 1, N}); ++l) {

for (int k = max({j, 0}); k < N; ++k) {

for (int t = max({i, 0}); t < min({(l) + 1, N}); ++t) {







J[i][j][k][l][s][t] += J[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int s = 0; s < min({(i) + 1, N}); ++s) {

for (int j = 0; j < N; ++j) {

for (int k = 0; k < min({(j) + 1, N}); ++k) {

for (int l = 0; l < min({(k) + 1, N}); ++l) {

for (int t = max({i, 0}); t < min({(l) + 1, N}); ++t) {







J[i][j][k][l][s][t] += J[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int j = 0; j < N; ++j) {

for (int t = 0; t < min({(j) + 1, N}); ++t) {

for (int k = max({j, 0}); k < N; ++k) {

for (int l = max({k, 0}); l < N; ++l) {

for (int s = max({l, 0}); s < min({(i) + 1, N}); ++s) {







J[i][j][k][l][s][t] += J[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int s = max({i, 0}); s < N; ++s) {

for (int j = 0; j < N; ++j) {

for (int t = 0; t < min({(j) + 1, N}); ++t) {

for (int k = max({j, 0}); k < N; ++k) {

for (int l = max({k, 0}); l < min({(i) + 1, N}); ++l) {







J[i][j][k][l][s][t] += J[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int l = 0; l < min({(i) + 1, N}); ++l) {

for (int j = 0; j < N; ++j) {

for (int t = 0; t < min({(j) + 1, N}); ++t) {

for (int k = max({j, 0}); k < N; ++k) {

for (int s = max({k, 0}); s < min({(l) + 1, N}); ++s) {







J[i][j][k][l][s][t] += J[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int l = max({i, 0}); l < N; ++l) {

for (int j = 0; j < N; ++j) {

for (int t = 0; t < min({(j) + 1, N}); ++t) {

for (int k = max({j, 0}); k < N; ++k) {

for (int s = max({k, 0}); s < min({(i) + 1, N}); ++s) {







J[i][j][k][l][s][t] += J[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int l = max({i, 0}); l < N; ++l) {

for (int s = max({l, 0}); s < N; ++s) {

for (int j = 0; j < N; ++j) {

for (int t = 0; t < min({(j) + 1, N}); ++t) {

for (int k = max({j, 0}); k < min({(i) + 1, N}); ++k) {







J[i][j][k][l][s][t] += J[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int j = 0; j < N; ++j) {

for (int t = 0; t < min({(j) + 1, N}); ++t) {

for (int k = max({j, 0}); k < min({(i) + 1, N}); ++k) {

for (int l = 0; l < N; ++l) {

for (int s = max({i, 0}); s < min({(l) + 1, N}); ++s) {







J[i][j][k][l][s][t] += J[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int j = 0; j < N; ++j) {

for (int t = 0; t < min({(j) + 1, N}); ++t) {

for (int k = 0; k < N; ++k) {

for (int s = max({k, 0}); s < min({(i) + 1, N}); ++s) {

for (int l = max({j, 0}); l < min({(k) + 1, N}); ++l) {







J[i][j][k][l][s][t] += J[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int s = max({i, 0}); s < N; ++s) {

for (int k = 0; k < min({(i) + 1, N}); ++k) {

for (int j = 0; j < N; ++j) {

for (int t = 0; t < min({(j) + 1, N}); ++t) {

for (int l = max({j, 0}); l < min({(k) + 1, N}); ++l) {







J[i][j][k][l][s][t] += J[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int j = 0; j < N; ++j) {

for (int k = 0; k < min({(i) + 1, N}); ++k) {

for (int t = 0; t < min({(j) + 1, N}); ++t) {

for (int l = max({j, 0}); l < N; ++l) {

for (int s = max({l, 0}); s < min({(k) + 1, N}); ++s) {







J[i][j][k][l][s][t] += J[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int j = 0; j < N; ++j) {

for (int k = max({i, 0}); k < N; ++k) {

for (int t = 0; t < min({(j) + 1, N}); ++t) {

for (int l = max({j, 0}); l < N; ++l) {

for (int s = max({l, 0}); s < min({(i) + 1, N}); ++s) {







J[i][j][k][l][s][t] += J[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int j = 0; j < N; ++j) {

for (int k = max({i, 0}); k < N; ++k) {

for (int t = 0; t < min({(j) + 1, N}); ++t) {

for (int l = max({j, 0}); l < min({(i) + 1, N}); ++l) {

for (int s = max({k, 0}); s < N; ++s) {







J[i][j][k][l][s][t] += J[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int j = 0; j < N; ++j) {

for (int t = 0; t < min({(j) + 1, N}); ++t) {

for (int l = max({j, 0}); l < min({(i) + 1, N}); ++l) {

for (int k = 0; k < N; ++k) {

for (int s = max({i, 0}); s < min({(k) + 1, N}); ++s) {







J[i][j][k][l][s][t] += J[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int j = 0; j < N; ++j) {

for (int t = 0; t < min({(j) + 1, N}); ++t) {

for (int k = 0; k < N; ++k) {

for (int s = max({j, 0}); s < min({(k) + 1, N}); ++s) {

for (int l = max({k, 0}); l < min({(i) + 1, N}); ++l) {







J[i][j][k][l][s][t] += J[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int l = max({i, 0}); l < N; ++l) {

for (int k = 0; k < min({(i) + 1, N}); ++k) {

for (int j = 0; j < N; ++j) {

for (int s = max({j, 0}); s < min({(k) + 1, N}); ++s) {

for (int t = 0; t < min({(j) + 1, N}); ++t) {







J[i][j][k][l][s][t] += J[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int j = 0; j < N; ++j) {

for (int k = 0; k < min({(i) + 1, N}); ++k) {

for (int t = 0; t < min({(j) + 1, N}); ++t) {

for (int l = 0; l < min({(k) + 1, N}); ++l) {

for (int s = max({j, 0}); s < min({(l) + 1, N}); ++s) {







J[i][j][k][l][s][t] += J[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int l = 0; l < min({(i) + 1, N}); ++l) {

for (int k = max({i, 0}); k < N; ++k) {

for (int j = 0; j < N; ++j) {

for (int s = max({j, 0}); s < min({(l) + 1, N}); ++s) {

for (int t = 0; t < min({(j) + 1, N}); ++t) {







J[i][j][k][l][s][t] += J[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int j = 0; j < N; ++j) {

for (int k = max({i, 0}); k < N; ++k) {

for (int s = max({j, 0}); s < min({(i) + 1, N}); ++s) {

for (int t = 0; t < min({(j) + 1, N}); ++t) {

for (int l = max({k, 0}); l < N; ++l) {







J[i][j][k][l][s][t] += J[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int j = 0; j < N; ++j) {

for (int s = max({j, 0}); s < min({(i) + 1, N}); ++s) {

for (int t = 0; t < min({(j) + 1, N}); ++t) {

for (int k = 0; k < N; ++k) {

for (int l = max({i, 0}); l < min({(k) + 1, N}); ++l) {







J[i][j][k][l][s][t] += J[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int j = 0; j < min({(i) + 1, N}); ++j) {

for (int k = max({i, 0}); k < N; ++k) {

for (int t = 0; t < min({(j) + 1, N}); ++t) {

for (int l = max({k, 0}); l < N; ++l) {

for (int s = max({l, 0}); s < N; ++s) {







J[i][j][k][l][s][t] += J[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int j = 0; j < min({(i) + 1, N}); ++j) {

for (int k = max({i, 0}); k < N; ++k) {

for (int t = 0; t < min({(j) + 1, N}); ++t) {

for (int l = 0; l < N; ++l) {

for (int s = max({k, 0}); s < min({(l) + 1, N}); ++s) {







J[i][j][k][l][s][t] += J[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int j = 0; j < min({(i) + 1, N}); ++j) {

for (int t = 0; t < min({(j) + 1, N}); ++t) {

for (int k = 0; k < N; ++k) {

for (int s = max({k, 0}); s < N; ++s) {

for (int l = max({i, 0}); l < min({(k) + 1, N}); ++l) {







J[i][j][k][l][s][t] += J[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int l = max({i, 0}); l < N; ++l) {

for (int j = 0; j < min({(i) + 1, N}); ++j) {

for (int t = 0; t < min({(j) + 1, N}); ++t) {

for (int k = 0; k < N; ++k) {

for (int s = max({l, 0}); s < min({(k) + 1, N}); ++s) {







J[i][j][k][l][s][t] += J[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int j = 0; j < min({(i) + 1, N}); ++j) {

for (int t = 0; t < min({(j) + 1, N}); ++t) {

for (int k = 0; k < N; ++k) {

for (int s = max({i, 0}); s < min({(k) + 1, N}); ++s) {

for (int l = max({k, 0}); l < N; ++l) {







J[i][j][k][l][s][t] += J[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int j = 0; j < min({(i) + 1, N}); ++j) {

for (int t = 0; t < min({(j) + 1, N}); ++t) {

for (int k = 0; k < N; ++k) {

for (int l = 0; l < min({(k) + 1, N}); ++l) {

for (int s = max({i, 0}); s < min({(l) + 1, N}); ++s) {







J[i][j][k][l][s][t] += J[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int j = 0; j < N; ++j) {

for (int l = max({j, 0}); l < N; ++l) {

for (int k = 0; k < min({(j) + 1, N}); ++k) {

for (int s = max({l, 0}); s < min({(i) + 1, N}); ++s) {

for (int t = 0; t < min({(k) + 1, N}); ++t) {







J[i][j][k][l][s][t] += J[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int s = max({i, 0}); s < N; ++s) {

for (int j = 0; j < N; ++j) {

for (int l = max({j, 0}); l < min({(i) + 1, N}); ++l) {

for (int k = 0; k < min({(j) + 1, N}); ++k) {

for (int t = 0; t < min({(k) + 1, N}); ++t) {







J[i][j][k][l][s][t] += J[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int l = 0; l < min({(i) + 1, N}); ++l) {

for (int j = 0; j < N; ++j) {

for (int s = max({j, 0}); s < min({(l) + 1, N}); ++s) {

for (int k = 0; k < min({(j) + 1, N}); ++k) {

for (int t = 0; t < min({(k) + 1, N}); ++t) {







J[i][j][k][l][s][t] += J[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int l = max({i, 0}); l < N; ++l) {

for (int j = 0; j < N; ++j) {

for (int s = max({j, 0}); s < min({(i) + 1, N}); ++s) {

for (int k = 0; k < min({(j) + 1, N}); ++k) {

for (int t = 0; t < min({(k) + 1, N}); ++t) {







J[i][j][k][l][s][t] += J[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int l = max({i, 0}); l < N; ++l) {

for (int j = 0; j < min({(i) + 1, N}); ++j) {

for (int s = max({l, 0}); s < N; ++s) {

for (int k = 0; k < min({(j) + 1, N}); ++k) {

for (int t = 0; t < min({(k) + 1, N}); ++t) {







J[i][j][k][l][s][t] += J[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int j = 0; j < min({(i) + 1, N}); ++j) {

for (int k = 0; k < min({(j) + 1, N}); ++k) {

for (int t = 0; t < min({(k) + 1, N}); ++t) {

for (int l = 0; l < N; ++l) {

for (int s = max({i, 0}); s < min({(l) + 1, N}); ++s) {







J[i][j][k][l][s][t] += J[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int j = 0; j < N; ++j) {

for (int s = max({j, 0}); s < min({(i) + 1, N}); ++s) {

for (int k = 0; k < N; ++k) {

for (int t = 0; t < min({(k) + 1, N}); ++t) {

for (int l = max({k, 0}); l < min({(j) + 1, N}); ++l) {







J[i][j][k][l][s][t] += J[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int s = max({i, 0}); s < N; ++s) {

for (int j = 0; j < min({(i) + 1, N}); ++j) {

for (int k = 0; k < N; ++k) {

for (int t = 0; t < min({(k) + 1, N}); ++t) {

for (int l = max({k, 0}); l < min({(j) + 1, N}); ++l) {







J[i][j][k][l][s][t] += J[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int j = 0; j < min({(i) + 1, N}); ++j) {

for (int k = 0; k < N; ++k) {

for (int t = 0; t < min({(k) + 1, N}); ++t) {

for (int l = max({k, 0}); l < N; ++l) {

for (int s = max({l, 0}); s < min({(j) + 1, N}); ++s) {







J[i][j][k][l][s][t] += J[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int j = max({i, 0}); j < N; ++j) {

for (int k = 0; k < N; ++k) {

for (int t = 0; t < min({(k) + 1, N}); ++t) {

for (int l = max({k, 0}); l < N; ++l) {

for (int s = max({l, 0}); s < min({(i) + 1, N}); ++s) {







J[i][j][k][l][s][t] += J[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int j = max({i, 0}); j < N; ++j) {

for (int s = max({j, 0}); s < N; ++s) {

for (int k = 0; k < N; ++k) {

for (int t = 0; t < min({(k) + 1, N}); ++t) {

for (int l = max({k, 0}); l < min({(i) + 1, N}); ++l) {







J[i][j][k][l][s][t] += J[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int j = 0; j < N; ++j) {

for (int s = max({i, 0}); s < min({(j) + 1, N}); ++s) {

for (int k = 0; k < N; ++k) {

for (int t = 0; t < min({(k) + 1, N}); ++t) {

for (int l = max({k, 0}); l < min({(i) + 1, N}); ++l) {







J[i][j][k][l][s][t] += J[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int j = 0; j < N; ++j) {

for (int l = max({j, 0}); l < min({(i) + 1, N}); ++l) {

for (int k = 0; k < N; ++k) {

for (int s = max({k, 0}); s < min({(j) + 1, N}); ++s) {

for (int t = 0; t < min({(k) + 1, N}); ++t) {







J[i][j][k][l][s][t] += J[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int l = max({i, 0}); l < N; ++l) {

for (int j = 0; j < min({(i) + 1, N}); ++j) {

for (int k = 0; k < N; ++k) {

for (int s = max({k, 0}); s < min({(j) + 1, N}); ++s) {

for (int t = 0; t < min({(k) + 1, N}); ++t) {







J[i][j][k][l][s][t] += J[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int j = 0; j < min({(i) + 1, N}); ++j) {

for (int l = 0; l < min({(j) + 1, N}); ++l) {

for (int k = 0; k < N; ++k) {

for (int s = max({k, 0}); s < min({(l) + 1, N}); ++s) {

for (int t = 0; t < min({(k) + 1, N}); ++t) {







J[i][j][k][l][s][t] += J[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int l = 0; l < min({(i) + 1, N}); ++l) {

for (int j = max({i, 0}); j < N; ++j) {

for (int k = 0; k < N; ++k) {

for (int s = max({k, 0}); s < min({(l) + 1, N}); ++s) {

for (int t = 0; t < min({(k) + 1, N}); ++t) {







J[i][j][k][l][s][t] += J[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int j = max({i, 0}); j < N; ++j) {

for (int l = max({j, 0}); l < N; ++l) {

for (int k = 0; k < N; ++k) {

for (int s = max({k, 0}); s < min({(i) + 1, N}); ++s) {

for (int t = 0; t < min({(k) + 1, N}); ++t) {







J[i][j][k][l][s][t] += J[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int j = 0; j < N; ++j) {

for (int l = max({i, 0}); l < min({(j) + 1, N}); ++l) {

for (int k = 0; k < N; ++k) {

for (int s = max({k, 0}); s < min({(i) + 1, N}); ++s) {

for (int t = 0; t < min({(k) + 1, N}); ++t) {







J[i][j][k][l][s][t] += J[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int j = max({i, 0}); j < N; ++j) {

for (int k = 0; k < min({(i) + 1, N}); ++k) {

for (int l = max({j, 0}); l < N; ++l) {

for (int t = 0; t < min({(k) + 1, N}); ++t) {

for (int s = max({l, 0}); s < N; ++s) {







J[i][j][k][l][s][t] += J[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int j = max({i, 0}); j < N; ++j) {

for (int k = 0; k < min({(i) + 1, N}); ++k) {

for (int t = 0; t < min({(k) + 1, N}); ++t) {

for (int l = 0; l < N; ++l) {

for (int s = max({j, 0}); s < min({(l) + 1, N}); ++s) {







J[i][j][k][l][s][t] += J[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int j = 0; j < N; ++j) {

for (int k = 0; k < min({(i) + 1, N}); ++k) {

for (int s = max({j, 0}); s < N; ++s) {

for (int l = max({i, 0}); l < min({(j) + 1, N}); ++l) {

for (int t = 0; t < min({(k) + 1, N}); ++t) {







J[i][j][k][l][s][t] += J[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int l = max({i, 0}); l < N; ++l) {

for (int k = 0; k < min({(i) + 1, N}); ++k) {

for (int t = 0; t < min({(k) + 1, N}); ++t) {

for (int j = 0; j < N; ++j) {

for (int s = max({l, 0}); s < min({(j) + 1, N}); ++s) {







J[i][j][k][l][s][t] += J[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int j = 0; j < N; ++j) {

for (int k = 0; k < min({(i) + 1, N}); ++k) {

for (int s = max({i, 0}); s < min({(j) + 1, N}); ++s) {

for (int l = max({j, 0}); l < N; ++l) {

for (int t = 0; t < min({(k) + 1, N}); ++t) {







J[i][j][k][l][s][t] += J[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int j = 0; j < N; ++j) {

for (int k = 0; k < min({(i) + 1, N}); ++k) {

for (int l = 0; l < min({(j) + 1, N}); ++l) {

for (int t = 0; t < min({(k) + 1, N}); ++t) {

for (int s = max({i, 0}); s < min({(l) + 1, N}); ++s) {







J[i][j][k][l][s][t] += J[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int j = 0; j < N; ++j) {

for (int l = 0; l < min({(j) + 1, N}); ++l) {

for (int k = max({j, 0}); k < N; ++k) {

for (int t = 0; t < min({(l) + 1, N}); ++t) {

for (int s = max({k, 0}); s < min({(i) + 1, N}); ++s) {







J[i][j][k][l][s][t] += J[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int s = max({i, 0}); s < N; ++s) {

for (int j = 0; j < N; ++j) {

for (int l = 0; l < min({(j) + 1, N}); ++l) {

for (int k = max({j, 0}); k < min({(i) + 1, N}); ++k) {

for (int t = 0; t < min({(l) + 1, N}); ++t) {







J[i][j][k][l][s][t] += J[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int j = 0; j < N; ++j) {

for (int k = 0; k < min({(i) + 1, N}); ++k) {

for (int l = 0; l < min({(j) + 1, N}); ++l) {

for (int s = max({j, 0}); s < min({(k) + 1, N}); ++s) {

for (int t = 0; t < min({(l) + 1, N}); ++t) {







J[i][j][k][l][s][t] += J[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int j = 0; j < N; ++j) {

for (int k = max({i, 0}); k < N; ++k) {

for (int s = max({j, 0}); s < min({(i) + 1, N}); ++s) {

for (int l = 0; l < min({(j) + 1, N}); ++l) {

for (int t = 0; t < min({(l) + 1, N}); ++t) {







J[i][j][k][l][s][t] += J[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int j = 0; j < min({(i) + 1, N}); ++j) {

for (int k = max({i, 0}); k < N; ++k) {

for (int l = 0; l < min({(j) + 1, N}); ++l) {

for (int s = max({k, 0}); s < N; ++s) {

for (int t = 0; t < min({(l) + 1, N}); ++t) {







J[i][j][k][l][s][t] += J[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int j = 0; j < min({(i) + 1, N}); ++j) {

for (int l = 0; l < min({(j) + 1, N}); ++l) {

for (int t = 0; t < min({(l) + 1, N}); ++t) {

for (int k = 0; k < N; ++k) {

for (int s = max({i, 0}); s < min({(k) + 1, N}); ++s) {







J[i][j][k][l][s][t] += J[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int j = 0; j < N; ++j) {

for (int s = max({j, 0}); s < min({(i) + 1, N}); ++s) {

for (int k = 0; k < min({(j) + 1, N}); ++k) {

for (int l = 0; l < min({(k) + 1, N}); ++l) {

for (int t = 0; t < min({(l) + 1, N}); ++t) {







J[i][j][k][l][s][t] += J[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int s = max({i, 0}); s < N; ++s) {

for (int j = 0; j < min({(i) + 1, N}); ++j) {

for (int k = 0; k < min({(j) + 1, N}); ++k) {

for (int l = 0; l < min({(k) + 1, N}); ++l) {

for (int t = 0; t < min({(l) + 1, N}); ++t) {







J[i][j][k][l][s][t] += J[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int j = 0; j < min({(i) + 1, N}); ++j) {

for (int k = 0; k < N; ++k) {

for (int s = max({k, 0}); s < min({(j) + 1, N}); ++s) {

for (int l = 0; l < min({(k) + 1, N}); ++l) {

for (int t = 0; t < min({(l) + 1, N}); ++t) {







J[i][j][k][l][s][t] += J[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int j = max({i, 0}); j < N; ++j) {

for (int k = 0; k < N; ++k) {

for (int s = max({k, 0}); s < min({(i) + 1, N}); ++s) {

for (int l = 0; l < min({(k) + 1, N}); ++l) {

for (int t = 0; t < min({(l) + 1, N}); ++t) {







J[i][j][k][l][s][t] += J[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int j = max({i, 0}); j < N; ++j) {

for (int k = 0; k < min({(i) + 1, N}); ++k) {

for (int s = max({j, 0}); s < N; ++s) {

for (int l = 0; l < min({(k) + 1, N}); ++l) {

for (int t = 0; t < min({(l) + 1, N}); ++t) {







J[i][j][k][l][s][t] += J[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int j = 0; j < N; ++j) {

for (int k = 0; k < min({(i) + 1, N}); ++k) {

for (int s = max({i, 0}); s < min({(j) + 1, N}); ++s) {

for (int l = 0; l < min({(k) + 1, N}); ++l) {

for (int t = 0; t < min({(l) + 1, N}); ++t) {







J[i][j][k][l][s][t] += J[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int j = 0; j < N; ++j) {

for (int k = max({j, 0}); k < min({(i) + 1, N}); ++k) {

for (int l = 0; l < N; ++l) {

for (int s = max({l, 0}); s < min({(j) + 1, N}); ++s) {

for (int t = 0; t < min({(l) + 1, N}); ++t) {







J[i][j][k][l][s][t] += J[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int j = 0; j < min({(i) + 1, N}); ++j) {

for (int k = max({i, 0}); k < N; ++k) {

for (int l = 0; l < N; ++l) {

for (int s = max({l, 0}); s < min({(j) + 1, N}); ++s) {

for (int t = 0; t < min({(l) + 1, N}); ++t) {







J[i][j][k][l][s][t] += J[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int j = 0; j < min({(i) + 1, N}); ++j) {

for (int k = 0; k < min({(j) + 1, N}); ++k) {

for (int l = 0; l < N; ++l) {

for (int s = max({l, 0}); s < min({(k) + 1, N}); ++s) {

for (int t = 0; t < min({(l) + 1, N}); ++t) {







J[i][j][k][l][s][t] += J[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int j = max({i, 0}); j < N; ++j) {

for (int k = 0; k < min({(i) + 1, N}); ++k) {

for (int l = 0; l < N; ++l) {

for (int s = max({l, 0}); s < min({(k) + 1, N}); ++s) {

for (int t = 0; t < min({(l) + 1, N}); ++t) {







J[i][j][k][l][s][t] += J[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int j = max({i, 0}); j < N; ++j) {

for (int k = max({j, 0}); k < N; ++k) {

for (int l = 0; l < N; ++l) {

for (int s = max({l, 0}); s < min({(i) + 1, N}); ++s) {

for (int t = 0; t < min({(l) + 1, N}); ++t) {







J[i][j][k][l][s][t] += J[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int j = 0; j < N; ++j) {

for (int k = max({i, 0}); k < min({(j) + 1, N}); ++k) {

for (int l = 0; l < N; ++l) {

for (int s = max({l, 0}); s < min({(i) + 1, N}); ++s) {

for (int t = 0; t < min({(l) + 1, N}); ++t) {







J[i][j][k][l][s][t] += J[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int l = 0; l < min({(i) + 1, N}); ++l) {

for (int j = max({i, 0}); j < N; ++j) {

for (int t = 0; t < min({(l) + 1, N}); ++t) {

for (int k = max({j, 0}); k < N; ++k) {

for (int s = max({k, 0}); s < N; ++s) {







J[i][j][k][l][s][t] += J[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int l = 0; l < min({(i) + 1, N}); ++l) {

for (int j = max({i, 0}); j < N; ++j) {

for (int t = 0; t < min({(l) + 1, N}); ++t) {

for (int k = 0; k < N; ++k) {

for (int s = max({j, 0}); s < min({(k) + 1, N}); ++s) {







J[i][j][k][l][s][t] += J[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int l = 0; l < min({(i) + 1, N}); ++l) {

for (int t = 0; t < min({(l) + 1, N}); ++t) {

for (int j = 0; j < N; ++j) {

for (int s = max({j, 0}); s < N; ++s) {

for (int k = max({i, 0}); k < min({(j) + 1, N}); ++k) {







J[i][j][k][l][s][t] += J[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int l = 0; l < min({(i) + 1, N}); ++l) {

for (int k = max({i, 0}); k < N; ++k) {

for (int t = 0; t < min({(l) + 1, N}); ++t) {

for (int j = 0; j < N; ++j) {

for (int s = max({k, 0}); s < min({(j) + 1, N}); ++s) {







J[i][j][k][l][s][t] += J[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int l = 0; l < min({(i) + 1, N}); ++l) {

for (int t = 0; t < min({(l) + 1, N}); ++t) {

for (int j = 0; j < N; ++j) {

for (int s = max({i, 0}); s < min({(j) + 1, N}); ++s) {

for (int k = max({j, 0}); k < N; ++k) {







J[i][j][k][l][s][t] += J[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int l = 0; l < min({(i) + 1, N}); ++l) {

for (int t = 0; t < min({(l) + 1, N}); ++t) {

for (int j = 0; j < N; ++j) {

for (int k = 0; k < min({(j) + 1, N}); ++k) {

for (int s = max({i, 0}); s < min({(k) + 1, N}); ++s) {







J[i][j][k][l][s][t] += J[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int j = 0; j < N; ++j) {

for (int s = 0; s < min({(j) + 1, N}); ++s) {

for (int k = max({j, 0}); k < N; ++k) {

for (int t = 0; t < min({(s) + 1, N}); ++t) {

for (int l = max({k, 0}); l < min({(i) + 1, N}); ++l) {







J[i][j][k][l][s][t] += J[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int l = max({i, 0}); l < N; ++l) {

for (int j = 0; j < N; ++j) {

for (int s = 0; s < min({(j) + 1, N}); ++s) {

for (int k = max({j, 0}); k < min({(i) + 1, N}); ++k) {

for (int t = 0; t < min({(s) + 1, N}); ++t) {







J[i][j][k][l][s][t] += J[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int j = 0; j < N; ++j) {

for (int k = 0; k < min({(i) + 1, N}); ++k) {

for (int s = 0; s < min({(j) + 1, N}); ++s) {

for (int l = max({j, 0}); l < min({(k) + 1, N}); ++l) {

for (int t = 0; t < min({(s) + 1, N}); ++t) {







J[i][j][k][l][s][t] += J[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int j = 0; j < N; ++j) {

for (int k = max({i, 0}); k < N; ++k) {

for (int s = 0; s < min({(j) + 1, N}); ++s) {

for (int l = max({j, 0}); l < min({(i) + 1, N}); ++l) {

for (int t = 0; t < min({(s) + 1, N}); ++t) {







J[i][j][k][l][s][t] += J[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int j = 0; j < min({(i) + 1, N}); ++j) {

for (int k = max({i, 0}); k < N; ++k) {

for (int s = 0; s < min({(j) + 1, N}); ++s) {

for (int l = max({k, 0}); l < N; ++l) {

for (int t = 0; t < min({(s) + 1, N}); ++t) {







J[i][j][k][l][s][t] += J[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int j = 0; j < min({(i) + 1, N}); ++j) {

for (int s = 0; s < min({(j) + 1, N}); ++s) {

for (int t = 0; t < min({(s) + 1, N}); ++t) {

for (int k = 0; k < N; ++k) {

for (int l = max({i, 0}); l < min({(k) + 1, N}); ++l) {







J[i][j][k][l][s][t] += J[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int j = 0; j < N; ++j) {

for (int l = max({j, 0}); l < min({(i) + 1, N}); ++l) {

for (int k = 0; k < min({(j) + 1, N}); ++k) {

for (int s = 0; s < min({(k) + 1, N}); ++s) {

for (int t = 0; t < min({(s) + 1, N}); ++t) {







J[i][j][k][l][s][t] += J[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int l = max({i, 0}); l < N; ++l) {

for (int j = 0; j < min({(i) + 1, N}); ++j) {

for (int k = 0; k < min({(j) + 1, N}); ++k) {

for (int s = 0; s < min({(k) + 1, N}); ++s) {

for (int t = 0; t < min({(s) + 1, N}); ++t) {







J[i][j][k][l][s][t] += J[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int j = 0; j < min({(i) + 1, N}); ++j) {

for (int k = 0; k < N; ++k) {

for (int s = 0; s < min({(k) + 1, N}); ++s) {

for (int l = max({k, 0}); l < min({(j) + 1, N}); ++l) {

for (int t = 0; t < min({(s) + 1, N}); ++t) {







J[i][j][k][l][s][t] += J[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int j = max({i, 0}); j < N; ++j) {

for (int k = 0; k < N; ++k) {

for (int s = 0; s < min({(k) + 1, N}); ++s) {

for (int l = max({k, 0}); l < min({(i) + 1, N}); ++l) {

for (int t = 0; t < min({(s) + 1, N}); ++t) {







J[i][j][k][l][s][t] += J[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int j = max({i, 0}); j < N; ++j) {

for (int k = 0; k < min({(i) + 1, N}); ++k) {

for (int l = max({j, 0}); l < N; ++l) {

for (int s = 0; s < min({(k) + 1, N}); ++s) {

for (int t = 0; t < min({(s) + 1, N}); ++t) {







J[i][j][k][l][s][t] += J[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int j = 0; j < N; ++j) {

for (int k = 0; k < min({(i) + 1, N}); ++k) {

for (int l = max({i, 0}); l < min({(j) + 1, N}); ++l) {

for (int s = 0; s < min({(k) + 1, N}); ++s) {

for (int t = 0; t < min({(s) + 1, N}); ++t) {







J[i][j][k][l][s][t] += J[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int j = 0; j < N; ++j) {

for (int l = 0; l < min({(j) + 1, N}); ++l) {

for (int k = max({j, 0}); k < min({(i) + 1, N}); ++k) {

for (int s = 0; s < min({(l) + 1, N}); ++s) {

for (int t = 0; t < min({(s) + 1, N}); ++t) {







J[i][j][k][l][s][t] += J[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int j = 0; j < min({(i) + 1, N}); ++j) {

for (int k = max({i, 0}); k < N; ++k) {

for (int l = 0; l < min({(j) + 1, N}); ++l) {

for (int s = 0; s < min({(l) + 1, N}); ++s) {

for (int t = 0; t < min({(s) + 1, N}); ++t) {







J[i][j][k][l][s][t] += J[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int j = 0; j < min({(i) + 1, N}); ++j) {

for (int k = 0; k < min({(j) + 1, N}); ++k) {

for (int l = 0; l < min({(k) + 1, N}); ++l) {

for (int s = 0; s < min({(l) + 1, N}); ++s) {

for (int t = 0; t < min({(s) + 1, N}); ++t) {







J[i][j][k][l][s][t] += J[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int j = max({i, 0}); j < N; ++j) {

for (int k = 0; k < min({(i) + 1, N}); ++k) {

for (int l = 0; l < min({(k) + 1, N}); ++l) {

for (int s = 0; s < min({(l) + 1, N}); ++s) {

for (int t = 0; t < min({(s) + 1, N}); ++t) {







J[i][j][k][l][s][t] += J[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int l = 0; l < min({(i) + 1, N}); ++l) {

for (int j = max({i, 0}); j < N; ++j) {

for (int s = 0; s < min({(l) + 1, N}); ++s) {

for (int k = max({j, 0}); k < N; ++k) {

for (int t = 0; t < min({(s) + 1, N}); ++t) {







J[i][j][k][l][s][t] += J[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int l = 0; l < min({(i) + 1, N}); ++l) {

for (int s = 0; s < min({(l) + 1, N}); ++s) {

for (int t = 0; t < min({(s) + 1, N}); ++t) {

for (int j = 0; j < N; ++j) {

for (int k = max({i, 0}); k < min({(j) + 1, N}); ++k) {







J[i][j][k][l][s][t] += J[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int s = 0; s < min({(i) + 1, N}); ++s) {

for (int j = max({i, 0}); j < N; ++j) {

for (int t = 0; t < min({(s) + 1, N}); ++t) {

for (int k = max({j, 0}); k < N; ++k) {

for (int l = max({k, 0}); l < N; ++l) {







J[i][j][k][l][s][t] += J[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int s = 0; s < min({(i) + 1, N}); ++s) {

for (int j = max({i, 0}); j < N; ++j) {

for (int t = 0; t < min({(s) + 1, N}); ++t) {

for (int k = 0; k < N; ++k) {

for (int l = max({j, 0}); l < min({(k) + 1, N}); ++l) {







J[i][j][k][l][s][t] += J[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int s = 0; s < min({(i) + 1, N}); ++s) {

for (int t = 0; t < min({(s) + 1, N}); ++t) {

for (int j = 0; j < N; ++j) {

for (int l = max({j, 0}); l < N; ++l) {

for (int k = max({i, 0}); k < min({(j) + 1, N}); ++k) {







J[i][j][k][l][s][t] += J[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int s = 0; s < min({(i) + 1, N}); ++s) {

for (int k = max({i, 0}); k < N; ++k) {

for (int t = 0; t < min({(s) + 1, N}); ++t) {

for (int j = 0; j < N; ++j) {

for (int l = max({k, 0}); l < min({(j) + 1, N}); ++l) {







J[i][j][k][l][s][t] += J[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int s = 0; s < min({(i) + 1, N}); ++s) {

for (int t = 0; t < min({(s) + 1, N}); ++t) {

for (int j = 0; j < N; ++j) {

for (int l = max({i, 0}); l < min({(j) + 1, N}); ++l) {

for (int k = max({j, 0}); k < N; ++k) {







J[i][j][k][l][s][t] += J[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int s = 0; s < min({(i) + 1, N}); ++s) {

for (int t = 0; t < min({(s) + 1, N}); ++t) {

for (int j = 0; j < N; ++j) {

for (int k = 0; k < min({(j) + 1, N}); ++k) {

for (int l = max({i, 0}); l < min({(k) + 1, N}); ++l) {







J[i][j][k][l][s][t] += J[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int t = 0; t < min({(i) + 1, N}); ++t) {

for (int j = max({i, 0}); j < N; ++j) {

for (int k = max({j, 0}); k < N; ++k) {

for (int l = max({k, 0}); l < N; ++l) {

for (int s = max({l, 0}); s < N; ++s) {







J[i][j][k][l][s][t] += J[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int t = 0; t < min({(i) + 1, N}); ++t) {

for (int j = max({i, 0}); j < N; ++j) {

for (int k = max({j, 0}); k < N; ++k) {

for (int l = 0; l < N; ++l) {

for (int s = max({k, 0}); s < min({(l) + 1, N}); ++s) {







J[i][j][k][l][s][t] += J[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int t = 0; t < min({(i) + 1, N}); ++t) {

for (int j = max({i, 0}); j < N; ++j) {

for (int k = 0; k < N; ++k) {

for (int s = max({k, 0}); s < N; ++s) {

for (int l = max({j, 0}); l < min({(k) + 1, N}); ++l) {







J[i][j][k][l][s][t] += J[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int t = 0; t < min({(i) + 1, N}); ++t) {

for (int j = max({i, 0}); j < N; ++j) {

for (int l = max({j, 0}); l < N; ++l) {

for (int k = 0; k < N; ++k) {

for (int s = max({l, 0}); s < min({(k) + 1, N}); ++s) {







J[i][j][k][l][s][t] += J[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int t = 0; t < min({(i) + 1, N}); ++t) {

for (int j = max({i, 0}); j < N; ++j) {

for (int k = 0; k < N; ++k) {

for (int s = max({j, 0}); s < min({(k) + 1, N}); ++s) {

for (int l = max({k, 0}); l < N; ++l) {







J[i][j][k][l][s][t] += J[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int t = 0; t < min({(i) + 1, N}); ++t) {

for (int j = max({i, 0}); j < N; ++j) {

for (int k = 0; k < N; ++k) {

for (int l = 0; l < min({(k) + 1, N}); ++l) {

for (int s = max({j, 0}); s < min({(l) + 1, N}); ++s) {







J[i][j][k][l][s][t] += J[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int t = 0; t < min({(i) + 1, N}); ++t) {

for (int j = 0; j < N; ++j) {

for (int l = max({j, 0}); l < N; ++l) {

for (int k = max({i, 0}); k < min({(j) + 1, N}); ++k) {

for (int s = max({l, 0}); s < N; ++s) {







J[i][j][k][l][s][t] += J[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int t = 0; t < min({(i) + 1, N}); ++t) {

for (int j = 0; j < N; ++j) {

for (int k = max({i, 0}); k < min({(j) + 1, N}); ++k) {

for (int l = 0; l < N; ++l) {

for (int s = max({j, 0}); s < min({(l) + 1, N}); ++s) {







J[i][j][k][l][s][t] += J[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int t = 0; t < min({(i) + 1, N}); ++t) {

for (int k = max({i, 0}); k < N; ++k) {

for (int j = 0; j < N; ++j) {

for (int s = max({j, 0}); s < N; ++s) {

for (int l = max({k, 0}); l < min({(j) + 1, N}); ++l) {







J[i][j][k][l][s][t] += J[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int t = 0; t < min({(i) + 1, N}); ++t) {

for (int k = max({i, 0}); k < N; ++k) {

for (int l = max({k, 0}); l < N; ++l) {

for (int j = 0; j < N; ++j) {

for (int s = max({l, 0}); s < min({(j) + 1, N}); ++s) {







J[i][j][k][l][s][t] += J[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int t = 0; t < min({(i) + 1, N}); ++t) {

for (int k = max({i, 0}); k < N; ++k) {

for (int j = 0; j < N; ++j) {

for (int s = max({k, 0}); s < min({(j) + 1, N}); ++s) {

for (int l = max({j, 0}); l < N; ++l) {







J[i][j][k][l][s][t] += J[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int t = 0; t < min({(i) + 1, N}); ++t) {

for (int k = max({i, 0}); k < N; ++k) {

for (int j = 0; j < N; ++j) {

for (int l = 0; l < min({(j) + 1, N}); ++l) {

for (int s = max({k, 0}); s < min({(l) + 1, N}); ++s) {







J[i][j][k][l][s][t] += J[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int t = 0; t < min({(i) + 1, N}); ++t) {

for (int j = 0; j < N; ++j) {

for (int l = max({i, 0}); l < min({(j) + 1, N}); ++l) {

for (int k = max({j, 0}); k < N; ++k) {

for (int s = max({k, 0}); s < N; ++s) {







J[i][j][k][l][s][t] += J[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int t = 0; t < min({(i) + 1, N}); ++t) {

for (int j = 0; j < N; ++j) {

for (int l = max({i, 0}); l < min({(j) + 1, N}); ++l) {

for (int k = 0; k < N; ++k) {

for (int s = max({j, 0}); s < min({(k) + 1, N}); ++s) {







J[i][j][k][l][s][t] += J[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int t = 0; t < min({(i) + 1, N}); ++t) {

for (int j = 0; j < N; ++j) {

for (int s = max({j, 0}); s < N; ++s) {

for (int k = 0; k < min({(j) + 1, N}); ++k) {

for (int l = max({i, 0}); l < min({(k) + 1, N}); ++l) {







J[i][j][k][l][s][t] += J[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int t = 0; t < min({(i) + 1, N}); ++t) {

for (int j = 0; j < N; ++j) {

for (int k = 0; k < N; ++k) {

for (int s = max({k, 0}); s < min({(j) + 1, N}); ++s) {

for (int l = max({i, 0}); l < min({(k) + 1, N}); ++l) {







J[i][j][k][l][s][t] += J[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int t = 0; t < min({(i) + 1, N}); ++t) {

for (int l = max({i, 0}); l < N; ++l) {

for (int j = 0; j < N; ++j) {

for (int s = max({l, 0}); s < min({(j) + 1, N}); ++s) {

for (int k = max({j, 0}); k < N; ++k) {







J[i][j][k][l][s][t] += J[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int t = 0; t < min({(i) + 1, N}); ++t) {

for (int l = max({i, 0}); l < N; ++l) {

for (int j = 0; j < N; ++j) {

for (int k = 0; k < min({(j) + 1, N}); ++k) {

for (int s = max({l, 0}); s < min({(k) + 1, N}); ++s) {







J[i][j][k][l][s][t] += J[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int t = 0; t < min({(i) + 1, N}); ++t) {

for (int j = 0; j < N; ++j) {

for (int s = max({i, 0}); s < min({(j) + 1, N}); ++s) {

for (int k = max({j, 0}); k < N; ++k) {

for (int l = max({k, 0}); l < N; ++l) {







J[i][j][k][l][s][t] += J[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int t = 0; t < min({(i) + 1, N}); ++t) {

for (int j = 0; j < N; ++j) {

for (int s = max({i, 0}); s < min({(j) + 1, N}); ++s) {

for (int k = 0; k < N; ++k) {

for (int l = max({j, 0}); l < min({(k) + 1, N}); ++l) {







J[i][j][k][l][s][t] += J[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int t = 0; t < min({(i) + 1, N}); ++t) {

for (int j = 0; j < N; ++j) {

for (int l = max({j, 0}); l < N; ++l) {

for (int k = 0; k < min({(j) + 1, N}); ++k) {

for (int s = max({i, 0}); s < min({(k) + 1, N}); ++s) {







J[i][j][k][l][s][t] += J[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int t = 0; t < min({(i) + 1, N}); ++t) {

for (int j = 0; j < N; ++j) {

for (int k = 0; k < N; ++k) {

for (int s = max({i, 0}); s < min({(k) + 1, N}); ++s) {

for (int l = max({k, 0}); l < min({(j) + 1, N}); ++l) {







J[i][j][k][l][s][t] += J[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int t = 0; t < min({(i) + 1, N}); ++t) {

for (int j = 0; j < N; ++j) {

for (int l = 0; l < min({(j) + 1, N}); ++l) {

for (int k = max({j, 0}); k < N; ++k) {

for (int s = max({i, 0}); s < min({(l) + 1, N}); ++s) {







J[i][j][k][l][s][t] += J[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int t = 0; t < min({(i) + 1, N}); ++t) {

for (int j = 0; j < N; ++j) {

for (int k = 0; k < min({(j) + 1, N}); ++k) {

for (int l = 0; l < min({(k) + 1, N}); ++l) {

for (int s = max({i, 0}); s < min({(l) + 1, N}); ++s) {







J[i][j][k][l][s][t] += J[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int j = max({i, 0}); j < N; ++j) {

for (int k = max({j, 0}); k < N; ++k) {

for (int l = max({k, 0}); l < N; ++l) {

for (int s = max({l, 0}); s < N; ++s) {

for (int t = max({s, 0}); t < N; ++t) {







J[i][j][k][l][s][t] += J[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int j = max({i, 0}); j < N; ++j) {

for (int k = max({j, 0}); k < N; ++k) {

for (int l = max({k, 0}); l < N; ++l) {

for (int s = 0; s < N; ++s) {

for (int t = max({l, 0}); t < min({(s) + 1, N}); ++t) {







J[i][j][k][l][s][t] += J[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int j = max({i, 0}); j < N; ++j) {

for (int k = max({j, 0}); k < N; ++k) {

for (int l = 0; l < N; ++l) {

for (int s = max({k, 0}); s < min({(l) + 1, N}); ++s) {

for (int t = max({l, 0}); t < N; ++t) {







J[i][j][k][l][s][t] += J[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int j = max({i, 0}); j < N; ++j) {

for (int k = max({j, 0}); k < N; ++k) {

for (int s = max({k, 0}); s < N; ++s) {

for (int l = 0; l < N; ++l) {

for (int t = max({s, 0}); t < min({(l) + 1, N}); ++t) {







J[i][j][k][l][s][t] += J[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int j = max({i, 0}); j < N; ++j) {

for (int k = max({j, 0}); k < N; ++k) {

for (int l = 0; l < N; ++l) {

for (int s = max({l, 0}); s < N; ++s) {

for (int t = max({k, 0}); t < min({(l) + 1, N}); ++t) {







J[i][j][k][l][s][t] += J[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int j = max({i, 0}); j < N; ++j) {

for (int k = max({j, 0}); k < N; ++k) {

for (int l = 0; l < N; ++l) {

for (int s = 0; s < min({(l) + 1, N}); ++s) {

for (int t = max({k, 0}); t < min({(s) + 1, N}); ++t) {







J[i][j][k][l][s][t] += J[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int j = max({i, 0}); j < N; ++j) {

for (int k = 0; k < N; ++k) {

for (int s = max({k, 0}); s < N; ++s) {

for (int l = max({j, 0}); l < min({(k) + 1, N}); ++l) {

for (int t = max({s, 0}); t < N; ++t) {







J[i][j][k][l][s][t] += J[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int j = max({i, 0}); j < N; ++j) {

for (int k = 0; k < N; ++k) {

for (int l = max({j, 0}); l < min({(k) + 1, N}); ++l) {

for (int s = 0; s < N; ++s) {

for (int t = max({k, 0}); t < min({(s) + 1, N}); ++t) {







J[i][j][k][l][s][t] += J[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int j = max({i, 0}); j < N; ++j) {

for (int l = max({j, 0}); l < N; ++l) {

for (int k = 0; k < N; ++k) {

for (int s = max({l, 0}); s < min({(k) + 1, N}); ++s) {

for (int t = max({k, 0}); t < N; ++t) {







J[i][j][k][l][s][t] += J[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int j = max({i, 0}); j < N; ++j) {

for (int l = max({j, 0}); l < N; ++l) {

for (int s = max({l, 0}); s < N; ++s) {

for (int k = 0; k < N; ++k) {

for (int t = max({s, 0}); t < min({(k) + 1, N}); ++t) {







J[i][j][k][l][s][t] += J[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int j = max({i, 0}); j < N; ++j) {

for (int l = max({j, 0}); l < N; ++l) {

for (int k = 0; k < N; ++k) {

for (int s = max({k, 0}); s < N; ++s) {

for (int t = max({l, 0}); t < min({(k) + 1, N}); ++t) {







J[i][j][k][l][s][t] += J[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int j = max({i, 0}); j < N; ++j) {

for (int l = max({j, 0}); l < N; ++l) {

for (int k = 0; k < N; ++k) {

for (int s = 0; s < min({(k) + 1, N}); ++s) {

for (int t = max({l, 0}); t < min({(s) + 1, N}); ++t) {







J[i][j][k][l][s][t] += J[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int j = max({i, 0}); j < N; ++j) {

for (int k = 0; k < N; ++k) {

for (int s = max({j, 0}); s < min({(k) + 1, N}); ++s) {

for (int l = max({k, 0}); l < N; ++l) {

for (int t = max({l, 0}); t < N; ++t) {







J[i][j][k][l][s][t] += J[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int j = max({i, 0}); j < N; ++j) {

for (int k = 0; k < N; ++k) {

for (int s = max({j, 0}); s < min({(k) + 1, N}); ++s) {

for (int l = 0; l < N; ++l) {

for (int t = max({k, 0}); t < min({(l) + 1, N}); ++t) {







J[i][j][k][l][s][t] += J[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int j = max({i, 0}); j < N; ++j) {

for (int k = 0; k < N; ++k) {

for (int t = max({k, 0}); t < N; ++t) {

for (int l = 0; l < min({(k) + 1, N}); ++l) {

for (int s = max({j, 0}); s < min({(l) + 1, N}); ++s) {







J[i][j][k][l][s][t] += J[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int j = max({i, 0}); j < N; ++j) {

for (int k = 0; k < N; ++k) {

for (int l = 0; l < N; ++l) {

for (int s = max({j, 0}); s < min({(l) + 1, N}); ++s) {

for (int t = max({l, 0}); t < min({(k) + 1, N}); ++t) {







J[i][j][k][l][s][t] += J[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int j = max({i, 0}); j < N; ++j) {

for (int s = max({j, 0}); s < N; ++s) {

for (int k = 0; k < N; ++k) {

for (int t = max({s, 0}); t < min({(k) + 1, N}); ++t) {

for (int l = max({k, 0}); l < N; ++l) {







J[i][j][k][l][s][t] += J[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int j = max({i, 0}); j < N; ++j) {

for (int s = max({j, 0}); s < N; ++s) {

for (int k = 0; k < N; ++k) {

for (int l = 0; l < min({(k) + 1, N}); ++l) {

for (int t = max({s, 0}); t < min({(l) + 1, N}); ++t) {







J[i][j][k][l][s][t] += J[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int j = max({i, 0}); j < N; ++j) {

for (int k = 0; k < N; ++k) {

for (int t = max({j, 0}); t < min({(k) + 1, N}); ++t) {

for (int l = max({k, 0}); l < N; ++l) {

for (int s = max({l, 0}); s < N; ++s) {







J[i][j][k][l][s][t] += J[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int j = max({i, 0}); j < N; ++j) {

for (int k = 0; k < N; ++k) {

for (int t = max({j, 0}); t < min({(k) + 1, N}); ++t) {

for (int l = 0; l < N; ++l) {

for (int s = max({k, 0}); s < min({(l) + 1, N}); ++s) {







J[i][j][k][l][s][t] += J[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int j = max({i, 0}); j < N; ++j) {

for (int k = 0; k < N; ++k) {

for (int s = max({k, 0}); s < N; ++s) {

for (int l = 0; l < min({(k) + 1, N}); ++l) {

for (int t = max({j, 0}); t < min({(l) + 1, N}); ++t) {







J[i][j][k][l][s][t] += J[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int j = max({i, 0}); j < N; ++j) {

for (int k = 0; k < N; ++k) {

for (int l = 0; l < N; ++l) {

for (int s = max({l, 0}); s < min({(k) + 1, N}); ++s) {

for (int t = max({j, 0}); t < min({(l) + 1, N}); ++t) {







J[i][j][k][l][s][t] += J[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int j = max({i, 0}); j < N; ++j) {

for (int k = 0; k < N; ++k) {

for (int s = 0; s < min({(k) + 1, N}); ++s) {

for (int l = max({k, 0}); l < N; ++l) {

for (int t = max({j, 0}); t < min({(s) + 1, N}); ++t) {







J[i][j][k][l][s][t] += J[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int j = max({i, 0}); j < N; ++j) {

for (int k = 0; k < N; ++k) {

for (int l = 0; l < min({(k) + 1, N}); ++l) {

for (int s = 0; s < min({(l) + 1, N}); ++s) {

for (int t = max({j, 0}); t < min({(s) + 1, N}); ++t) {







J[i][j][k][l][s][t] += J[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int j = 0; j < N; ++j) {

for (int l = max({j, 0}); l < N; ++l) {

for (int k = max({i, 0}); k < min({(j) + 1, N}); ++k) {

for (int s = max({l, 0}); s < N; ++s) {

for (int t = max({s, 0}); t < N; ++t) {







J[i][j][k][l][s][t] += J[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int j = 0; j < N; ++j) {

for (int l = max({j, 0}); l < N; ++l) {

for (int k = max({i, 0}); k < min({(j) + 1, N}); ++k) {

for (int s = 0; s < N; ++s) {

for (int t = max({l, 0}); t < min({(s) + 1, N}); ++t) {







J[i][j][k][l][s][t] += J[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int j = 0; j < N; ++j) {

for (int k = max({i, 0}); k < min({(j) + 1, N}); ++k) {

for (int l = 0; l < N; ++l) {

for (int s = max({j, 0}); s < min({(l) + 1, N}); ++s) {

for (int t = max({l, 0}); t < N; ++t) {







J[i][j][k][l][s][t] += J[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int j = 0; j < N; ++j) {

for (int s = max({j, 0}); s < N; ++s) {

for (int k = max({i, 0}); k < min({(j) + 1, N}); ++k) {

for (int l = 0; l < N; ++l) {

for (int t = max({s, 0}); t < min({(l) + 1, N}); ++t) {







J[i][j][k][l][s][t] += J[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int j = 0; j < N; ++j) {

for (int k = max({i, 0}); k < min({(j) + 1, N}); ++k) {

for (int l = 0; l < N; ++l) {

for (int s = max({l, 0}); s < N; ++s) {

for (int t = max({j, 0}); t < min({(l) + 1, N}); ++t) {







J[i][j][k][l][s][t] += J[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int j = 0; j < N; ++j) {

for (int k = max({i, 0}); k < min({(j) + 1, N}); ++k) {

for (int l = 0; l < N; ++l) {

for (int s = 0; s < min({(l) + 1, N}); ++s) {

for (int t = max({j, 0}); t < min({(s) + 1, N}); ++t) {







J[i][j][k][l][s][t] += J[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int j = 0; j < N; ++j) {

for (int k = max({i, 0}); k < N; ++k) {

for (int s = max({j, 0}); s < N; ++s) {

for (int l = max({k, 0}); l < min({(j) + 1, N}); ++l) {

for (int t = max({s, 0}); t < N; ++t) {







J[i][j][k][l][s][t] += J[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int j = 0; j < N; ++j) {

for (int k = max({i, 0}); k < N; ++k) {

for (int l = max({k, 0}); l < min({(j) + 1, N}); ++l) {

for (int s = 0; s < N; ++s) {

for (int t = max({j, 0}); t < min({(s) + 1, N}); ++t) {







J[i][j][k][l][s][t] += J[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int j = 0; j < N; ++j) {

for (int k = max({i, 0}); k < N; ++k) {

for (int t = max({j, 0}); t < N; ++t) {

for (int l = max({k, 0}); l < N; ++l) {

for (int s = max({l, 0}); s < min({(j) + 1, N}); ++s) {







J[i][j][k][l][s][t] += J[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int j = 0; j < N; ++j) {

for (int k = max({i, 0}); k < N; ++k) {

for (int l = max({k, 0}); l < N; ++l) {

for (int s = max({l, 0}); s < N; ++s) {

for (int t = max({s, 0}); t < min({(j) + 1, N}); ++t) {







J[i][j][k][l][s][t] += J[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int j = 0; j < N; ++j) {

for (int k = max({i, 0}); k < N; ++k) {

for (int s = max({j, 0}); s < N; ++s) {

for (int l = max({k, 0}); l < N; ++l) {

for (int t = max({l, 0}); t < min({(j) + 1, N}); ++t) {







J[i][j][k][l][s][t] += J[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int j = 0; j < N; ++j) {

for (int k = max({i, 0}); k < N; ++k) {

for (int s = 0; s < min({(j) + 1, N}); ++s) {

for (int l = max({k, 0}); l < N; ++l) {

for (int t = max({l, 0}); t < min({(s) + 1, N}); ++t) {







J[i][j][k][l][s][t] += J[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int j = 0; j < N; ++j) {

for (int k = max({i, 0}); k < N; ++k) {

for (int l = max({j, 0}); l < N; ++l) {

for (int s = max({k, 0}); s < min({(j) + 1, N}); ++s) {

for (int t = max({l, 0}); t < N; ++t) {







J[i][j][k][l][s][t] += J[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int j = 0; j < N; ++j) {

for (int k = max({i, 0}); k < N; ++k) {

for (int s = max({k, 0}); s < min({(j) + 1, N}); ++s) {

for (int l = 0; l < N; ++l) {

for (int t = max({j, 0}); t < min({(l) + 1, N}); ++t) {







J[i][j][k][l][s][t] += J[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int j = 0; j < N; ++j) {

for (int k = max({i, 0}); k < N; ++k) {

for (int t = max({j, 0}); t < N; ++t) {

for (int l = 0; l < min({(j) + 1, N}); ++l) {

for (int s = max({k, 0}); s < min({(l) + 1, N}); ++s) {







J[i][j][k][l][s][t] += J[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int j = 0; j < N; ++j) {

for (int k = max({i, 0}); k < N; ++k) {

for (int l = 0; l < N; ++l) {

for (int s = max({k, 0}); s < min({(l) + 1, N}); ++s) {

for (int t = max({l, 0}); t < min({(j) + 1, N}); ++t) {







J[i][j][k][l][s][t] += J[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int j = 0; j < N; ++j) {

for (int k = max({i, 0}); k < N; ++k) {

for (int l = max({j, 0}); l < N; ++l) {

for (int s = max({k, 0}); s < N; ++s) {

for (int t = max({s, 0}); t < min({(j) + 1, N}); ++t) {







J[i][j][k][l][s][t] += J[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int j = 0; j < N; ++j) {

for (int k = max({i, 0}); k < N; ++k) {

for (int l = 0; l < min({(j) + 1, N}); ++l) {

for (int s = max({k, 0}); s < N; ++s) {

for (int t = max({s, 0}); t < min({(l) + 1, N}); ++t) {







J[i][j][k][l][s][t] += J[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int j = 0; j < N; ++j) {

for (int k = max({i, 0}); k < N; ++k) {

for (int l = max({j, 0}); l < N; ++l) {

for (int t = max({k, 0}); t < min({(j) + 1, N}); ++t) {

for (int s = max({l, 0}); s < N; ++s) {







J[i][j][k][l][s][t] += J[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int j = 0; j < N; ++j) {

for (int k = max({i, 0}); k < N; ++k) {

for (int t = max({k, 0}); t < min({(j) + 1, N}); ++t) {

for (int l = 0; l < N; ++l) {

for (int s = max({j, 0}); s < min({(l) + 1, N}); ++s) {







J[i][j][k][l][s][t] += J[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int j = 0; j < N; ++j) {

for (int k = max({i, 0}); k < N; ++k) {

for (int s = max({j, 0}); s < N; ++s) {

for (int l = 0; l < min({(j) + 1, N}); ++l) {

for (int t = max({k, 0}); t < min({(l) + 1, N}); ++t) {







J[i][j][k][l][s][t] += J[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int j = 0; j < N; ++j) {

for (int k = max({i, 0}); k < N; ++k) {

for (int l = 0; l < N; ++l) {

for (int s = max({l, 0}); s < min({(j) + 1, N}); ++s) {

for (int t = max({k, 0}); t < min({(l) + 1, N}); ++t) {







J[i][j][k][l][s][t] += J[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int j = 0; j < N; ++j) {

for (int k = max({i, 0}); k < N; ++k) {

for (int s = 0; s < min({(j) + 1, N}); ++s) {

for (int l = max({j, 0}); l < N; ++l) {

for (int t = max({k, 0}); t < min({(s) + 1, N}); ++t) {







J[i][j][k][l][s][t] += J[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int j = 0; j < N; ++j) {

for (int k = max({i, 0}); k < N; ++k) {

for (int l = 0; l < min({(j) + 1, N}); ++l) {

for (int s = 0; s < min({(l) + 1, N}); ++s) {

for (int t = max({k, 0}); t < min({(s) + 1, N}); ++t) {







J[i][j][k][l][s][t] += J[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int j = 0; j < N; ++j) {

for (int l = max({i, 0}); l < min({(j) + 1, N}); ++l) {

for (int k = max({j, 0}); k < N; ++k) {

for (int s = max({k, 0}); s < N; ++s) {

for (int t = max({s, 0}); t < N; ++t) {







J[i][j][k][l][s][t] += J[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int j = 0; j < N; ++j) {

for (int l = max({i, 0}); l < min({(j) + 1, N}); ++l) {

for (int k = max({j, 0}); k < N; ++k) {

for (int s = 0; s < N; ++s) {

for (int t = max({k, 0}); t < min({(s) + 1, N}); ++t) {







J[i][j][k][l][s][t] += J[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int j = 0; j < N; ++j) {

for (int l = max({i, 0}); l < min({(j) + 1, N}); ++l) {

for (int k = 0; k < N; ++k) {

for (int s = max({j, 0}); s < min({(k) + 1, N}); ++s) {

for (int t = max({k, 0}); t < N; ++t) {







J[i][j][k][l][s][t] += J[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int j = 0; j < N; ++j) {

for (int s = max({j, 0}); s < N; ++s) {

for (int l = max({i, 0}); l < min({(j) + 1, N}); ++l) {

for (int k = 0; k < N; ++k) {

for (int t = max({s, 0}); t < min({(k) + 1, N}); ++t) {







J[i][j][k][l][s][t] += J[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int j = 0; j < N; ++j) {

for (int l = max({i, 0}); l < min({(j) + 1, N}); ++l) {

for (int k = 0; k < N; ++k) {

for (int s = max({k, 0}); s < N; ++s) {

for (int t = max({j, 0}); t < min({(k) + 1, N}); ++t) {







J[i][j][k][l][s][t] += J[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int j = 0; j < N; ++j) {

for (int l = max({i, 0}); l < min({(j) + 1, N}); ++l) {

for (int k = 0; k < N; ++k) {

for (int s = 0; s < min({(k) + 1, N}); ++s) {

for (int t = max({j, 0}); t < min({(s) + 1, N}); ++t) {







J[i][j][k][l][s][t] += J[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int j = 0; j < N; ++j) {

for (int s = max({j, 0}); s < N; ++s) {

for (int k = 0; k < min({(j) + 1, N}); ++k) {

for (int t = max({s, 0}); t < N; ++t) {

for (int l = max({i, 0}); l < min({(k) + 1, N}); ++l) {







J[i][j][k][l][s][t] += J[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int j = 0; j < N; ++j) {

for (int k = 0; k < min({(j) + 1, N}); ++k) {

for (int l = max({i, 0}); l < min({(k) + 1, N}); ++l) {

for (int s = 0; s < N; ++s) {

for (int t = max({j, 0}); t < min({(s) + 1, N}); ++t) {







J[i][j][k][l][s][t] += J[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int j = 0; j < N; ++j) {

for (int t = max({j, 0}); t < N; ++t) {

for (int k = 0; k < N; ++k) {

for (int s = max({k, 0}); s < min({(j) + 1, N}); ++s) {

for (int l = max({i, 0}); l < min({(k) + 1, N}); ++l) {







J[i][j][k][l][s][t] += J[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int j = 0; j < N; ++j) {

for (int k = 0; k < N; ++k) {

for (int s = max({k, 0}); s < N; ++s) {

for (int l = max({i, 0}); l < min({(k) + 1, N}); ++l) {

for (int t = max({s, 0}); t < min({(j) + 1, N}); ++t) {







J[i][j][k][l][s][t] += J[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int j = 0; j < N; ++j) {

for (int s = max({j, 0}); s < N; ++s) {

for (int k = 0; k < N; ++k) {

for (int t = max({k, 0}); t < min({(j) + 1, N}); ++t) {

for (int l = max({i, 0}); l < min({(k) + 1, N}); ++l) {







J[i][j][k][l][s][t] += J[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int j = 0; j < N; ++j) {

for (int s = 0; s < min({(j) + 1, N}); ++s) {

for (int k = 0; k < N; ++k) {

for (int t = max({k, 0}); t < min({(s) + 1, N}); ++t) {

for (int l = max({i, 0}); l < min({(k) + 1, N}); ++l) {







J[i][j][k][l][s][t] += J[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int l = max({i, 0}); l < N; ++l) {

for (int j = 0; j < N; ++j) {

for (int s = max({l, 0}); s < min({(j) + 1, N}); ++s) {

for (int k = max({j, 0}); k < N; ++k) {

for (int t = max({k, 0}); t < N; ++t) {







J[i][j][k][l][s][t] += J[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int l = max({i, 0}); l < N; ++l) {

for (int j = 0; j < N; ++j) {

for (int s = max({l, 0}); s < min({(j) + 1, N}); ++s) {

for (int k = 0; k < N; ++k) {

for (int t = max({j, 0}); t < min({(k) + 1, N}); ++t) {







J[i][j][k][l][s][t] += J[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int l = max({i, 0}); l < N; ++l) {

for (int j = 0; j < N; ++j) {

for (int t = max({j, 0}); t < N; ++t) {

for (int k = 0; k < min({(j) + 1, N}); ++k) {

for (int s = max({l, 0}); s < min({(k) + 1, N}); ++s) {







J[i][j][k][l][s][t] += J[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int l = max({i, 0}); l < N; ++l) {

for (int j = 0; j < N; ++j) {

for (int k = 0; k < N; ++k) {

for (int s = max({l, 0}); s < min({(k) + 1, N}); ++s) {

for (int t = max({k, 0}); t < min({(j) + 1, N}); ++t) {







J[i][j][k][l][s][t] += J[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int l = max({i, 0}); l < N; ++l) {

for (int s = max({l, 0}); s < N; ++s) {

for (int j = 0; j < N; ++j) {

for (int t = max({s, 0}); t < min({(j) + 1, N}); ++t) {

for (int k = max({j, 0}); k < N; ++k) {







J[i][j][k][l][s][t] += J[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int l = max({i, 0}); l < N; ++l) {

for (int s = max({l, 0}); s < N; ++s) {

for (int j = 0; j < N; ++j) {

for (int k = 0; k < min({(j) + 1, N}); ++k) {

for (int t = max({s, 0}); t < min({(k) + 1, N}); ++t) {







J[i][j][k][l][s][t] += J[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int l = max({i, 0}); l < N; ++l) {

for (int j = 0; j < N; ++j) {

for (int t = max({l, 0}); t < min({(j) + 1, N}); ++t) {

for (int k = max({j, 0}); k < N; ++k) {

for (int s = max({k, 0}); s < N; ++s) {







J[i][j][k][l][s][t] += J[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int l = max({i, 0}); l < N; ++l) {

for (int j = 0; j < N; ++j) {

for (int t = max({l, 0}); t < min({(j) + 1, N}); ++t) {

for (int k = 0; k < N; ++k) {

for (int s = max({j, 0}); s < min({(k) + 1, N}); ++s) {







J[i][j][k][l][s][t] += J[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int l = max({i, 0}); l < N; ++l) {

for (int j = 0; j < N; ++j) {

for (int s = max({j, 0}); s < N; ++s) {

for (int k = 0; k < min({(j) + 1, N}); ++k) {

for (int t = max({l, 0}); t < min({(k) + 1, N}); ++t) {







J[i][j][k][l][s][t] += J[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int l = max({i, 0}); l < N; ++l) {

for (int j = 0; j < N; ++j) {

for (int k = 0; k < N; ++k) {

for (int s = max({k, 0}); s < min({(j) + 1, N}); ++s) {

for (int t = max({l, 0}); t < min({(k) + 1, N}); ++t) {







J[i][j][k][l][s][t] += J[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int l = max({i, 0}); l < N; ++l) {

for (int j = 0; j < N; ++j) {

for (int s = 0; s < min({(j) + 1, N}); ++s) {

for (int k = max({j, 0}); k < N; ++k) {

for (int t = max({l, 0}); t < min({(s) + 1, N}); ++t) {







J[i][j][k][l][s][t] += J[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int l = max({i, 0}); l < N; ++l) {

for (int j = 0; j < N; ++j) {

for (int k = 0; k < min({(j) + 1, N}); ++k) {

for (int s = 0; s < min({(k) + 1, N}); ++s) {

for (int t = max({l, 0}); t < min({(s) + 1, N}); ++t) {







J[i][j][k][l][s][t] += J[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int j = 0; j < N; ++j) {

for (int s = max({i, 0}); s < min({(j) + 1, N}); ++s) {

for (int k = max({j, 0}); k < N; ++k) {

for (int l = max({k, 0}); l < N; ++l) {

for (int t = max({l, 0}); t < N; ++t) {







J[i][j][k][l][s][t] += J[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int j = 0; j < N; ++j) {

for (int s = max({i, 0}); s < min({(j) + 1, N}); ++s) {

for (int k = max({j, 0}); k < N; ++k) {

for (int l = 0; l < N; ++l) {

for (int t = max({k, 0}); t < min({(l) + 1, N}); ++t) {







J[i][j][k][l][s][t] += J[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int j = 0; j < N; ++j) {

for (int s = max({i, 0}); s < min({(j) + 1, N}); ++s) {

for (int k = 0; k < N; ++k) {

for (int t = max({k, 0}); t < N; ++t) {

for (int l = max({j, 0}); l < min({(k) + 1, N}); ++l) {







J[i][j][k][l][s][t] += J[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int j = 0; j < N; ++j) {

for (int s = max({i, 0}); s < min({(j) + 1, N}); ++s) {

for (int l = max({j, 0}); l < N; ++l) {

for (int k = 0; k < N; ++k) {

for (int t = max({l, 0}); t < min({(k) + 1, N}); ++t) {







J[i][j][k][l][s][t] += J[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int j = 0; j < N; ++j) {

for (int s = max({i, 0}); s < min({(j) + 1, N}); ++s) {

for (int k = 0; k < N; ++k) {

for (int t = max({j, 0}); t < min({(k) + 1, N}); ++t) {

for (int l = max({k, 0}); l < N; ++l) {







J[i][j][k][l][s][t] += J[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int j = 0; j < N; ++j) {

for (int s = max({i, 0}); s < min({(j) + 1, N}); ++s) {

for (int k = 0; k < N; ++k) {

for (int l = 0; l < min({(k) + 1, N}); ++l) {

for (int t = max({j, 0}); t < min({(l) + 1, N}); ++t) {







J[i][j][k][l][s][t] += J[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int j = 0; j < N; ++j) {

for (int l = max({j, 0}); l < N; ++l) {

for (int k = 0; k < min({(j) + 1, N}); ++k) {

for (int t = max({l, 0}); t < N; ++t) {

for (int s = max({i, 0}); s < min({(k) + 1, N}); ++s) {







J[i][j][k][l][s][t] += J[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int j = 0; j < N; ++j) {

for (int k = 0; k < min({(j) + 1, N}); ++k) {

for (int s = max({i, 0}); s < min({(k) + 1, N}); ++s) {

for (int l = 0; l < N; ++l) {

for (int t = max({j, 0}); t < min({(l) + 1, N}); ++t) {







J[i][j][k][l][s][t] += J[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int j = 0; j < N; ++j) {

for (int t = max({j, 0}); t < N; ++t) {

for (int k = 0; k < N; ++k) {

for (int s = max({i, 0}); s < min({(k) + 1, N}); ++s) {

for (int l = max({k, 0}); l < min({(j) + 1, N}); ++l) {







J[i][j][k][l][s][t] += J[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int j = 0; j < N; ++j) {

for (int k = 0; k < N; ++k) {

for (int s = max({i, 0}); s < min({(k) + 1, N}); ++s) {

for (int l = max({k, 0}); l < N; ++l) {

for (int t = max({l, 0}); t < min({(j) + 1, N}); ++t) {







J[i][j][k][l][s][t] += J[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int j = 0; j < N; ++j) {

for (int l = max({j, 0}); l < N; ++l) {

for (int k = 0; k < N; ++k) {

for (int s = max({i, 0}); s < min({(k) + 1, N}); ++s) {

for (int t = max({k, 0}); t < min({(j) + 1, N}); ++t) {







J[i][j][k][l][s][t] += J[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int j = 0; j < N; ++j) {

for (int l = 0; l < min({(j) + 1, N}); ++l) {

for (int k = 0; k < N; ++k) {

for (int s = max({i, 0}); s < min({(k) + 1, N}); ++s) {

for (int t = max({k, 0}); t < min({(l) + 1, N}); ++t) {







J[i][j][k][l][s][t] += J[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int j = 0; j < N; ++j) {

for (int l = 0; l < min({(j) + 1, N}); ++l) {

for (int k = max({j, 0}); k < N; ++k) {

for (int s = max({i, 0}); s < min({(l) + 1, N}); ++s) {

for (int t = max({k, 0}); t < N; ++t) {







J[i][j][k][l][s][t] += J[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int j = 0; j < N; ++j) {

for (int l = 0; l < min({(j) + 1, N}); ++l) {

for (int s = max({i, 0}); s < min({(l) + 1, N}); ++s) {

for (int k = 0; k < N; ++k) {

for (int t = max({j, 0}); t < min({(k) + 1, N}); ++t) {







J[i][j][k][l][s][t] += J[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int j = 0; j < N; ++j) {

for (int t = max({j, 0}); t < N; ++t) {

for (int k = 0; k < min({(j) + 1, N}); ++k) {

for (int l = 0; l < min({(k) + 1, N}); ++l) {

for (int s = max({i, 0}); s < min({(l) + 1, N}); ++s) {







J[i][j][k][l][s][t] += J[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int j = 0; j < N; ++j) {

for (int k = 0; k < N; ++k) {

for (int t = max({k, 0}); t < min({(j) + 1, N}); ++t) {

for (int l = 0; l < min({(k) + 1, N}); ++l) {

for (int s = max({i, 0}); s < min({(l) + 1, N}); ++s) {







J[i][j][k][l][s][t] += J[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int j = 0; j < N; ++j) {

for (int k = max({j, 0}); k < N; ++k) {

for (int l = 0; l < N; ++l) {

for (int s = max({i, 0}); s < min({(l) + 1, N}); ++s) {

for (int t = max({l, 0}); t < min({(j) + 1, N}); ++t) {







J[i][j][k][l][s][t] += J[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int j = 0; j < N; ++j) {

for (int k = 0; k < min({(j) + 1, N}); ++k) {

for (int l = 0; l < N; ++l) {

for (int s = max({i, 0}); s < min({(l) + 1, N}); ++s) {

for (int t = max({l, 0}); t < min({(k) + 1, N}); ++t) {







J[i][j][k][l][s][t] += J[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int s = max({i, 0}); s < N; ++s) {

for (int j = 0; j < N; ++j) {

for (int t = max({s, 0}); t < min({(j) + 1, N}); ++t) {

for (int k = max({j, 0}); k < N; ++k) {

for (int l = max({k, 0}); l < N; ++l) {







J[i][j][k][l][s][t] += J[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int s = max({i, 0}); s < N; ++s) {

for (int j = 0; j < N; ++j) {

for (int t = max({s, 0}); t < min({(j) + 1, N}); ++t) {

for (int k = 0; k < N; ++k) {

for (int l = max({j, 0}); l < min({(k) + 1, N}); ++l) {







J[i][j][k][l][s][t] += J[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int s = max({i, 0}); s < N; ++s) {

for (int j = 0; j < N; ++j) {

for (int l = max({j, 0}); l < N; ++l) {

for (int k = 0; k < min({(j) + 1, N}); ++k) {

for (int t = max({s, 0}); t < min({(k) + 1, N}); ++t) {







J[i][j][k][l][s][t] += J[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int s = max({i, 0}); s < N; ++s) {

for (int j = 0; j < N; ++j) {

for (int k = 0; k < N; ++k) {

for (int t = max({s, 0}); t < min({(k) + 1, N}); ++t) {

for (int l = max({k, 0}); l < min({(j) + 1, N}); ++l) {







J[i][j][k][l][s][t] += J[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int s = max({i, 0}); s < N; ++s) {

for (int j = 0; j < N; ++j) {

for (int l = 0; l < min({(j) + 1, N}); ++l) {

for (int k = max({j, 0}); k < N; ++k) {

for (int t = max({s, 0}); t < min({(l) + 1, N}); ++t) {







J[i][j][k][l][s][t] += J[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int s = max({i, 0}); s < N; ++s) {

for (int j = 0; j < N; ++j) {

for (int k = 0; k < min({(j) + 1, N}); ++k) {

for (int l = 0; l < min({(k) + 1, N}); ++l) {

for (int t = max({s, 0}); t < min({(l) + 1, N}); ++t) {







J[i][j][k][l][s][t] += J[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int j = 0; j < N; ++j) {

for (int t = max({i, 0}); t < min({(j) + 1, N}); ++t) {

for (int k = max({j, 0}); k < N; ++k) {

for (int l = max({k, 0}); l < N; ++l) {

for (int s = max({l, 0}); s < N; ++s) {







J[i][j][k][l][s][t] += J[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int j = 0; j < N; ++j) {

for (int t = max({i, 0}); t < min({(j) + 1, N}); ++t) {

for (int k = max({j, 0}); k < N; ++k) {

for (int l = 0; l < N; ++l) {

for (int s = max({k, 0}); s < min({(l) + 1, N}); ++s) {







J[i][j][k][l][s][t] += J[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int j = 0; j < N; ++j) {

for (int t = max({i, 0}); t < min({(j) + 1, N}); ++t) {

for (int k = 0; k < N; ++k) {

for (int s = max({k, 0}); s < N; ++s) {

for (int l = max({j, 0}); l < min({(k) + 1, N}); ++l) {







J[i][j][k][l][s][t] += J[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int j = 0; j < N; ++j) {

for (int t = max({i, 0}); t < min({(j) + 1, N}); ++t) {

for (int l = max({j, 0}); l < N; ++l) {

for (int k = 0; k < N; ++k) {

for (int s = max({l, 0}); s < min({(k) + 1, N}); ++s) {







J[i][j][k][l][s][t] += J[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int j = 0; j < N; ++j) {

for (int t = max({i, 0}); t < min({(j) + 1, N}); ++t) {

for (int k = 0; k < N; ++k) {

for (int s = max({j, 0}); s < min({(k) + 1, N}); ++s) {

for (int l = max({k, 0}); l < N; ++l) {







J[i][j][k][l][s][t] += J[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int j = 0; j < N; ++j) {

for (int t = max({i, 0}); t < min({(j) + 1, N}); ++t) {

for (int k = 0; k < N; ++k) {

for (int l = 0; l < min({(k) + 1, N}); ++l) {

for (int s = max({j, 0}); s < min({(l) + 1, N}); ++s) {







J[i][j][k][l][s][t] += J[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int j = 0; j < N; ++j) {

for (int l = max({j, 0}); l < N; ++l) {

for (int k = 0; k < min({(j) + 1, N}); ++k) {

for (int s = max({l, 0}); s < N; ++s) {

for (int t = max({i, 0}); t < min({(k) + 1, N}); ++t) {







J[i][j][k][l][s][t] += J[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int j = 0; j < N; ++j) {

for (int k = 0; k < min({(j) + 1, N}); ++k) {

for (int t = max({i, 0}); t < min({(k) + 1, N}); ++t) {

for (int l = 0; l < N; ++l) {

for (int s = max({j, 0}); s < min({(l) + 1, N}); ++s) {







J[i][j][k][l][s][t] += J[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int j = 0; j < N; ++j) {

for (int s = max({j, 0}); s < N; ++s) {

for (int k = 0; k < N; ++k) {

for (int t = max({i, 0}); t < min({(k) + 1, N}); ++t) {

for (int l = max({k, 0}); l < min({(j) + 1, N}); ++l) {







J[i][j][k][l][s][t] += J[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int j = 0; j < N; ++j) {

for (int k = 0; k < N; ++k) {

for (int t = max({i, 0}); t < min({(k) + 1, N}); ++t) {

for (int l = max({k, 0}); l < N; ++l) {

for (int s = max({l, 0}); s < min({(j) + 1, N}); ++s) {







J[i][j][k][l][s][t] += J[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int j = 0; j < N; ++j) {

for (int l = max({j, 0}); l < N; ++l) {

for (int k = 0; k < N; ++k) {

for (int s = max({k, 0}); s < min({(j) + 1, N}); ++s) {

for (int t = max({i, 0}); t < min({(k) + 1, N}); ++t) {







J[i][j][k][l][s][t] += J[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int j = 0; j < N; ++j) {

for (int l = 0; l < min({(j) + 1, N}); ++l) {

for (int k = 0; k < N; ++k) {

for (int s = max({k, 0}); s < min({(l) + 1, N}); ++s) {

for (int t = max({i, 0}); t < min({(k) + 1, N}); ++t) {







J[i][j][k][l][s][t] += J[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int j = 0; j < N; ++j) {

for (int l = 0; l < min({(j) + 1, N}); ++l) {

for (int k = max({j, 0}); k < N; ++k) {

for (int t = max({i, 0}); t < min({(l) + 1, N}); ++t) {

for (int s = max({k, 0}); s < N; ++s) {







J[i][j][k][l][s][t] += J[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int j = 0; j < N; ++j) {

for (int l = 0; l < min({(j) + 1, N}); ++l) {

for (int t = max({i, 0}); t < min({(l) + 1, N}); ++t) {

for (int k = 0; k < N; ++k) {

for (int s = max({j, 0}); s < min({(k) + 1, N}); ++s) {







J[i][j][k][l][s][t] += J[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int j = 0; j < N; ++j) {

for (int s = max({j, 0}); s < N; ++s) {

for (int k = 0; k < min({(j) + 1, N}); ++k) {

for (int l = 0; l < min({(k) + 1, N}); ++l) {

for (int t = max({i, 0}); t < min({(l) + 1, N}); ++t) {







J[i][j][k][l][s][t] += J[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int j = 0; j < N; ++j) {

for (int k = 0; k < N; ++k) {

for (int s = max({k, 0}); s < min({(j) + 1, N}); ++s) {

for (int l = 0; l < min({(k) + 1, N}); ++l) {

for (int t = max({i, 0}); t < min({(l) + 1, N}); ++t) {







J[i][j][k][l][s][t] += J[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int j = 0; j < N; ++j) {

for (int k = max({j, 0}); k < N; ++k) {

for (int l = 0; l < N; ++l) {

for (int s = max({l, 0}); s < min({(j) + 1, N}); ++s) {

for (int t = max({i, 0}); t < min({(l) + 1, N}); ++t) {







J[i][j][k][l][s][t] += J[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int j = 0; j < N; ++j) {

for (int k = 0; k < min({(j) + 1, N}); ++k) {

for (int l = 0; l < N; ++l) {

for (int s = max({l, 0}); s < min({(k) + 1, N}); ++s) {

for (int t = max({i, 0}); t < min({(l) + 1, N}); ++t) {







J[i][j][k][l][s][t] += J[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int j = 0; j < N; ++j) {

for (int s = 0; s < min({(j) + 1, N}); ++s) {

for (int k = max({j, 0}); k < N; ++k) {

for (int t = max({i, 0}); t < min({(s) + 1, N}); ++t) {

for (int l = max({k, 0}); l < N; ++l) {







J[i][j][k][l][s][t] += J[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int j = 0; j < N; ++j) {

for (int s = 0; s < min({(j) + 1, N}); ++s) {

for (int t = max({i, 0}); t < min({(s) + 1, N}); ++t) {

for (int k = 0; k < N; ++k) {

for (int l = max({j, 0}); l < min({(k) + 1, N}); ++l) {







J[i][j][k][l][s][t] += J[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int j = 0; j < N; ++j) {

for (int l = max({j, 0}); l < N; ++l) {

for (int k = 0; k < min({(j) + 1, N}); ++k) {

for (int s = 0; s < min({(k) + 1, N}); ++s) {

for (int t = max({i, 0}); t < min({(s) + 1, N}); ++t) {







J[i][j][k][l][s][t] += J[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int j = 0; j < N; ++j) {

for (int k = 0; k < N; ++k) {

for (int s = 0; s < min({(k) + 1, N}); ++s) {

for (int l = max({k, 0}); l < min({(j) + 1, N}); ++l) {

for (int t = max({i, 0}); t < min({(s) + 1, N}); ++t) {







J[i][j][k][l][s][t] += J[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int j = 0; j < N; ++j) {

for (int l = 0; l < min({(j) + 1, N}); ++l) {

for (int k = max({j, 0}); k < N; ++k) {

for (int s = 0; s < min({(l) + 1, N}); ++s) {

for (int t = max({i, 0}); t < min({(s) + 1, N}); ++t) {







J[i][j][k][l][s][t] += J[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int j = 0; j < N; ++j) {

for (int k = 0; k < min({(j) + 1, N}); ++k) {

for (int l = 0; l < min({(k) + 1, N}); ++l) {

for (int s = 0; s < min({(l) + 1, N}); ++s) {

for (int t = max({i, 0}); t < min({(s) + 1, N}); ++t) {







J[i][j][k][l][s][t] += J[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int j = 0; j < min({i, N}); ++j) {



K[i][j] += K[ip][jp];
}
}
for (int i = 0; i < N; ++i) {

for (int j = 0; j < min({(i) + 1, N}); ++j) {

for (int k = max({i, 0}); k < N; ++k) {




L[i][j][k] += L[ip][jp][kp];
}
}
}
for (int i = 0; i < N; ++i) {

for (int j = 0; j < min({(i) + 1, N}); ++j) {

for (int k = 0; k < min({(j) + 1, N}); ++k) {




L[i][j][k] += L[ip][jp][kp];
}
}
}
for (int i = 0; i < N; ++i) {

for (int j = max({i, 0}); j < N; ++j) {

for (int k = 0; k < min({(i) + 1, N}); ++k) {




L[i][j][k] += L[ip][jp][kp];
}
}
}
for (int i = 0; i < N; ++i) {

for (int j = max({i, 0}); j < N; ++j) {

for (int k = max({j, 0}); k < N; ++k) {




L[i][j][k] += L[ip][jp][kp];
}
}
}
for (int i = 0; i < N; ++i) {

for (int j = 0; j < N; ++j) {

for (int k = max({i, 0}); k < min({(j) + 1, N}); ++k) {




L[i][j][k] += L[ip][jp][kp];
}
}
}
for (int i = 0; i < N; ++i) {

for (int l = max({i, 0}); l < N; ++l) {

for (int j = 0; j < N; ++j) {

for (int k = max({j, 0}); k < min({(i) + 1, N}); ++k) {





M[i][j][k][l] += M[ip][jp][kp][lp];
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int j = 0; j < N; ++j) {

for (int k = 0; k < min({(i) + 1, N}); ++k) {

for (int l = max({j, 0}); l < min({(k) + 1, N}); ++l) {





M[i][j][k][l] += M[ip][jp][kp][lp];
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int j = 0; j < N; ++j) {

for (int k = max({i, 0}); k < N; ++k) {

for (int l = max({j, 0}); l < min({(i) + 1, N}); ++l) {





M[i][j][k][l] += M[ip][jp][kp][lp];
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int j = 0; j < min({(i) + 1, N}); ++j) {

for (int k = max({i, 0}); k < N; ++k) {

for (int l = max({k, 0}); l < N; ++l) {





M[i][j][k][l] += M[ip][jp][kp][lp];
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int j = 0; j < min({(i) + 1, N}); ++j) {

for (int k = 0; k < N; ++k) {

for (int l = max({i, 0}); l < min({(k) + 1, N}); ++l) {





M[i][j][k][l] += M[ip][jp][kp][lp];
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int j = 0; j < N; ++j) {

for (int l = max({j, 0}); l < min({(i) + 1, N}); ++l) {

for (int k = 0; k < min({(j) + 1, N}); ++k) {





M[i][j][k][l] += M[ip][jp][kp][lp];
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int l = max({i, 0}); l < N; ++l) {

for (int j = 0; j < min({(i) + 1, N}); ++j) {

for (int k = 0; k < min({(j) + 1, N}); ++k) {





M[i][j][k][l] += M[ip][jp][kp][lp];
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int j = 0; j < min({(i) + 1, N}); ++j) {

for (int k = 0; k < N; ++k) {

for (int l = max({k, 0}); l < min({(j) + 1, N}); ++l) {





M[i][j][k][l] += M[ip][jp][kp][lp];
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int j = max({i, 0}); j < N; ++j) {

for (int k = 0; k < N; ++k) {

for (int l = max({k, 0}); l < min({(i) + 1, N}); ++l) {





M[i][j][k][l] += M[ip][jp][kp][lp];
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int j = max({i, 0}); j < N; ++j) {

for (int k = 0; k < min({(i) + 1, N}); ++k) {

for (int l = max({j, 0}); l < N; ++l) {





M[i][j][k][l] += M[ip][jp][kp][lp];
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int j = 0; j < N; ++j) {

for (int k = 0; k < min({(i) + 1, N}); ++k) {

for (int l = max({i, 0}); l < min({(j) + 1, N}); ++l) {





M[i][j][k][l] += M[ip][jp][kp][lp];
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int j = 0; j < N; ++j) {

for (int l = 0; l < min({(j) + 1, N}); ++l) {

for (int k = max({j, 0}); k < min({(i) + 1, N}); ++k) {





M[i][j][k][l] += M[ip][jp][kp][lp];
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int j = 0; j < min({(i) + 1, N}); ++j) {

for (int k = max({i, 0}); k < N; ++k) {

for (int l = 0; l < min({(j) + 1, N}); ++l) {





M[i][j][k][l] += M[ip][jp][kp][lp];
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int j = 0; j < min({(i) + 1, N}); ++j) {

for (int k = 0; k < min({(j) + 1, N}); ++k) {

for (int l = 0; l < min({(k) + 1, N}); ++l) {





M[i][j][k][l] += M[ip][jp][kp][lp];
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int j = max({i, 0}); j < N; ++j) {

for (int k = 0; k < min({(i) + 1, N}); ++k) {

for (int l = 0; l < min({(k) + 1, N}); ++l) {





M[i][j][k][l] += M[ip][jp][kp][lp];
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int l = 0; l < min({(i) + 1, N}); ++l) {

for (int j = max({i, 0}); j < N; ++j) {

for (int k = max({j, 0}); k < N; ++k) {





M[i][j][k][l] += M[ip][jp][kp][lp];
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int l = 0; l < min({(i) + 1, N}); ++l) {

for (int j = 0; j < N; ++j) {

for (int k = max({i, 0}); k < min({(j) + 1, N}); ++k) {





M[i][j][k][l] += M[ip][jp][kp][lp];
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int j = max({i, 0}); j < N; ++j) {

for (int k = max({j, 0}); k < N; ++k) {

for (int l = max({k, 0}); l < N; ++l) {





M[i][j][k][l] += M[ip][jp][kp][lp];
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int j = max({i, 0}); j < N; ++j) {

for (int k = 0; k < N; ++k) {

for (int l = max({j, 0}); l < min({(k) + 1, N}); ++l) {





M[i][j][k][l] += M[ip][jp][kp][lp];
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int j = 0; j < N; ++j) {

for (int l = max({j, 0}); l < N; ++l) {

for (int k = max({i, 0}); k < min({(j) + 1, N}); ++k) {





M[i][j][k][l] += M[ip][jp][kp][lp];
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int j = 0; j < N; ++j) {

for (int k = max({i, 0}); k < N; ++k) {

for (int l = max({k, 0}); l < min({(j) + 1, N}); ++l) {





M[i][j][k][l] += M[ip][jp][kp][lp];
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int j = 0; j < N; ++j) {

for (int l = max({i, 0}); l < min({(j) + 1, N}); ++l) {

for (int k = max({j, 0}); k < N; ++k) {





M[i][j][k][l] += M[ip][jp][kp][lp];
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int j = 0; j < N; ++j) {

for (int k = 0; k < min({(j) + 1, N}); ++k) {

for (int l = max({i, 0}); l < min({(k) + 1, N}); ++l) {





M[i][j][k][l] += M[ip][jp][kp][lp];
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int s = max({i, 0}); s < N; ++s) {

for (int j = 0; j < N; ++j) {

for (int k = max({j, 0}); k < N; ++k) {

for (int l = max({k, 0}); l < min({(i) + 1, N}); ++l) {






P[i][j][k][l][s] += P[ip][jp][kp][lp][sp];
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int l = 0; l < min({(i) + 1, N}); ++l) {

for (int j = 0; j < N; ++j) {

for (int k = max({j, 0}); k < N; ++k) {

for (int s = max({k, 0}); s < min({(l) + 1, N}); ++s) {






P[i][j][k][l][s] += P[ip][jp][kp][lp][sp];
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int l = max({i, 0}); l < N; ++l) {

for (int j = 0; j < N; ++j) {

for (int k = max({j, 0}); k < N; ++k) {

for (int s = max({k, 0}); s < min({(i) + 1, N}); ++s) {






P[i][j][k][l][s] += P[ip][jp][kp][lp][sp];
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int l = max({i, 0}); l < N; ++l) {

for (int s = max({l, 0}); s < N; ++s) {

for (int j = 0; j < N; ++j) {

for (int k = max({j, 0}); k < min({(i) + 1, N}); ++k) {






P[i][j][k][l][s] += P[ip][jp][kp][lp][sp];
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int j = 0; j < N; ++j) {

for (int k = max({j, 0}); k < min({(i) + 1, N}); ++k) {

for (int l = 0; l < N; ++l) {

for (int s = max({i, 0}); s < min({(l) + 1, N}); ++s) {






P[i][j][k][l][s] += P[ip][jp][kp][lp][sp];
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int j = 0; j < N; ++j) {

for (int k = 0; k < N; ++k) {

for (int s = max({k, 0}); s < min({(i) + 1, N}); ++s) {

for (int l = max({j, 0}); l < min({(k) + 1, N}); ++l) {






P[i][j][k][l][s] += P[ip][jp][kp][lp][sp];
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int s = max({i, 0}); s < N; ++s) {

for (int k = 0; k < min({(i) + 1, N}); ++k) {

for (int j = 0; j < N; ++j) {

for (int l = max({j, 0}); l < min({(k) + 1, N}); ++l) {






P[i][j][k][l][s] += P[ip][jp][kp][lp][sp];
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int j = 0; j < N; ++j) {

for (int k = 0; k < min({(i) + 1, N}); ++k) {

for (int l = max({j, 0}); l < N; ++l) {

for (int s = max({l, 0}); s < min({(k) + 1, N}); ++s) {






P[i][j][k][l][s] += P[ip][jp][kp][lp][sp];
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int j = 0; j < N; ++j) {

for (int k = max({i, 0}); k < N; ++k) {

for (int l = max({j, 0}); l < N; ++l) {

for (int s = max({l, 0}); s < min({(i) + 1, N}); ++s) {






P[i][j][k][l][s] += P[ip][jp][kp][lp][sp];
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int j = 0; j < N; ++j) {

for (int k = max({i, 0}); k < N; ++k) {

for (int l = max({j, 0}); l < min({(i) + 1, N}); ++l) {

for (int s = max({k, 0}); s < N; ++s) {






P[i][j][k][l][s] += P[ip][jp][kp][lp][sp];
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int j = 0; j < N; ++j) {

for (int l = max({j, 0}); l < min({(i) + 1, N}); ++l) {

for (int k = 0; k < N; ++k) {

for (int s = max({i, 0}); s < min({(k) + 1, N}); ++s) {






P[i][j][k][l][s] += P[ip][jp][kp][lp][sp];
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int j = 0; j < N; ++j) {

for (int k = 0; k < N; ++k) {

for (int s = max({j, 0}); s < min({(k) + 1, N}); ++s) {

for (int l = max({k, 0}); l < min({(i) + 1, N}); ++l) {






P[i][j][k][l][s] += P[ip][jp][kp][lp][sp];
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int l = max({i, 0}); l < N; ++l) {

for (int k = 0; k < min({(i) + 1, N}); ++k) {

for (int j = 0; j < N; ++j) {

for (int s = max({j, 0}); s < min({(k) + 1, N}); ++s) {






P[i][j][k][l][s] += P[ip][jp][kp][lp][sp];
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int j = 0; j < N; ++j) {

for (int k = 0; k < min({(i) + 1, N}); ++k) {

for (int l = 0; l < min({(k) + 1, N}); ++l) {

for (int s = max({j, 0}); s < min({(l) + 1, N}); ++s) {






P[i][j][k][l][s] += P[ip][jp][kp][lp][sp];
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int l = 0; l < min({(i) + 1, N}); ++l) {

for (int k = max({i, 0}); k < N; ++k) {

for (int j = 0; j < N; ++j) {

for (int s = max({j, 0}); s < min({(l) + 1, N}); ++s) {






P[i][j][k][l][s] += P[ip][jp][kp][lp][sp];
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int j = 0; j < N; ++j) {

for (int k = max({i, 0}); k < N; ++k) {

for (int s = max({j, 0}); s < min({(i) + 1, N}); ++s) {

for (int l = max({k, 0}); l < N; ++l) {






P[i][j][k][l][s] += P[ip][jp][kp][lp][sp];
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int j = 0; j < N; ++j) {

for (int s = max({j, 0}); s < min({(i) + 1, N}); ++s) {

for (int k = 0; k < N; ++k) {

for (int l = max({i, 0}); l < min({(k) + 1, N}); ++l) {






P[i][j][k][l][s] += P[ip][jp][kp][lp][sp];
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int j = 0; j < min({(i) + 1, N}); ++j) {

for (int k = max({i, 0}); k < N; ++k) {

for (int l = max({k, 0}); l < N; ++l) {

for (int s = max({l, 0}); s < N; ++s) {






P[i][j][k][l][s] += P[ip][jp][kp][lp][sp];
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int j = 0; j < min({(i) + 1, N}); ++j) {

for (int k = max({i, 0}); k < N; ++k) {

for (int l = 0; l < N; ++l) {

for (int s = max({k, 0}); s < min({(l) + 1, N}); ++s) {






P[i][j][k][l][s] += P[ip][jp][kp][lp][sp];
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int j = 0; j < min({(i) + 1, N}); ++j) {

for (int k = 0; k < N; ++k) {

for (int s = max({k, 0}); s < N; ++s) {

for (int l = max({i, 0}); l < min({(k) + 1, N}); ++l) {






P[i][j][k][l][s] += P[ip][jp][kp][lp][sp];
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int l = max({i, 0}); l < N; ++l) {

for (int j = 0; j < min({(i) + 1, N}); ++j) {

for (int k = 0; k < N; ++k) {

for (int s = max({l, 0}); s < min({(k) + 1, N}); ++s) {






P[i][j][k][l][s] += P[ip][jp][kp][lp][sp];
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int j = 0; j < min({(i) + 1, N}); ++j) {

for (int k = 0; k < N; ++k) {

for (int s = max({i, 0}); s < min({(k) + 1, N}); ++s) {

for (int l = max({k, 0}); l < N; ++l) {






P[i][j][k][l][s] += P[ip][jp][kp][lp][sp];
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int j = 0; j < min({(i) + 1, N}); ++j) {

for (int k = 0; k < N; ++k) {

for (int l = 0; l < min({(k) + 1, N}); ++l) {

for (int s = max({i, 0}); s < min({(l) + 1, N}); ++s) {






P[i][j][k][l][s] += P[ip][jp][kp][lp][sp];
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int j = 0; j < N; ++j) {

for (int l = max({j, 0}); l < N; ++l) {

for (int k = 0; k < min({(j) + 1, N}); ++k) {

for (int s = max({l, 0}); s < min({(i) + 1, N}); ++s) {






P[i][j][k][l][s] += P[ip][jp][kp][lp][sp];
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int s = max({i, 0}); s < N; ++s) {

for (int j = 0; j < N; ++j) {

for (int l = max({j, 0}); l < min({(i) + 1, N}); ++l) {

for (int k = 0; k < min({(j) + 1, N}); ++k) {






P[i][j][k][l][s] += P[ip][jp][kp][lp][sp];
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int l = 0; l < min({(i) + 1, N}); ++l) {

for (int j = 0; j < N; ++j) {

for (int s = max({j, 0}); s < min({(l) + 1, N}); ++s) {

for (int k = 0; k < min({(j) + 1, N}); ++k) {






P[i][j][k][l][s] += P[ip][jp][kp][lp][sp];
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int l = max({i, 0}); l < N; ++l) {

for (int j = 0; j < N; ++j) {

for (int s = max({j, 0}); s < min({(i) + 1, N}); ++s) {

for (int k = 0; k < min({(j) + 1, N}); ++k) {






P[i][j][k][l][s] += P[ip][jp][kp][lp][sp];
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int l = max({i, 0}); l < N; ++l) {

for (int j = 0; j < min({(i) + 1, N}); ++j) {

for (int s = max({l, 0}); s < N; ++s) {

for (int k = 0; k < min({(j) + 1, N}); ++k) {






P[i][j][k][l][s] += P[ip][jp][kp][lp][sp];
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int j = 0; j < min({(i) + 1, N}); ++j) {

for (int k = 0; k < min({(j) + 1, N}); ++k) {

for (int l = 0; l < N; ++l) {

for (int s = max({i, 0}); s < min({(l) + 1, N}); ++s) {






P[i][j][k][l][s] += P[ip][jp][kp][lp][sp];
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int j = 0; j < N; ++j) {

for (int s = max({j, 0}); s < min({(i) + 1, N}); ++s) {

for (int k = 0; k < N; ++k) {

for (int l = max({k, 0}); l < min({(j) + 1, N}); ++l) {






P[i][j][k][l][s] += P[ip][jp][kp][lp][sp];
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int s = max({i, 0}); s < N; ++s) {

for (int j = 0; j < min({(i) + 1, N}); ++j) {

for (int k = 0; k < N; ++k) {

for (int l = max({k, 0}); l < min({(j) + 1, N}); ++l) {






P[i][j][k][l][s] += P[ip][jp][kp][lp][sp];
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int j = 0; j < min({(i) + 1, N}); ++j) {

for (int k = 0; k < N; ++k) {

for (int l = max({k, 0}); l < N; ++l) {

for (int s = max({l, 0}); s < min({(j) + 1, N}); ++s) {






P[i][j][k][l][s] += P[ip][jp][kp][lp][sp];
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int j = max({i, 0}); j < N; ++j) {

for (int k = 0; k < N; ++k) {

for (int l = max({k, 0}); l < N; ++l) {

for (int s = max({l, 0}); s < min({(i) + 1, N}); ++s) {






P[i][j][k][l][s] += P[ip][jp][kp][lp][sp];
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int j = max({i, 0}); j < N; ++j) {

for (int s = max({j, 0}); s < N; ++s) {

for (int k = 0; k < N; ++k) {

for (int l = max({k, 0}); l < min({(i) + 1, N}); ++l) {






P[i][j][k][l][s] += P[ip][jp][kp][lp][sp];
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int j = 0; j < N; ++j) {

for (int s = max({i, 0}); s < min({(j) + 1, N}); ++s) {

for (int k = 0; k < N; ++k) {

for (int l = max({k, 0}); l < min({(i) + 1, N}); ++l) {






P[i][j][k][l][s] += P[ip][jp][kp][lp][sp];
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int j = 0; j < N; ++j) {

for (int l = max({j, 0}); l < min({(i) + 1, N}); ++l) {

for (int k = 0; k < N; ++k) {

for (int s = max({k, 0}); s < min({(j) + 1, N}); ++s) {






P[i][j][k][l][s] += P[ip][jp][kp][lp][sp];
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int l = max({i, 0}); l < N; ++l) {

for (int j = 0; j < min({(i) + 1, N}); ++j) {

for (int k = 0; k < N; ++k) {

for (int s = max({k, 0}); s < min({(j) + 1, N}); ++s) {






P[i][j][k][l][s] += P[ip][jp][kp][lp][sp];
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int j = 0; j < min({(i) + 1, N}); ++j) {

for (int l = 0; l < min({(j) + 1, N}); ++l) {

for (int k = 0; k < N; ++k) {

for (int s = max({k, 0}); s < min({(l) + 1, N}); ++s) {






P[i][j][k][l][s] += P[ip][jp][kp][lp][sp];
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int l = 0; l < min({(i) + 1, N}); ++l) {

for (int j = max({i, 0}); j < N; ++j) {

for (int k = 0; k < N; ++k) {

for (int s = max({k, 0}); s < min({(l) + 1, N}); ++s) {






P[i][j][k][l][s] += P[ip][jp][kp][lp][sp];
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int j = max({i, 0}); j < N; ++j) {

for (int l = max({j, 0}); l < N; ++l) {

for (int k = 0; k < N; ++k) {

for (int s = max({k, 0}); s < min({(i) + 1, N}); ++s) {






P[i][j][k][l][s] += P[ip][jp][kp][lp][sp];
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int j = 0; j < N; ++j) {

for (int l = max({i, 0}); l < min({(j) + 1, N}); ++l) {

for (int k = 0; k < N; ++k) {

for (int s = max({k, 0}); s < min({(i) + 1, N}); ++s) {






P[i][j][k][l][s] += P[ip][jp][kp][lp][sp];
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int j = max({i, 0}); j < N; ++j) {

for (int k = 0; k < min({(i) + 1, N}); ++k) {

for (int l = max({j, 0}); l < N; ++l) {

for (int s = max({l, 0}); s < N; ++s) {






P[i][j][k][l][s] += P[ip][jp][kp][lp][sp];
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int j = max({i, 0}); j < N; ++j) {

for (int k = 0; k < min({(i) + 1, N}); ++k) {

for (int l = 0; l < N; ++l) {

for (int s = max({j, 0}); s < min({(l) + 1, N}); ++s) {






P[i][j][k][l][s] += P[ip][jp][kp][lp][sp];
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int j = 0; j < N; ++j) {

for (int k = 0; k < min({(i) + 1, N}); ++k) {

for (int s = max({j, 0}); s < N; ++s) {

for (int l = max({i, 0}); l < min({(j) + 1, N}); ++l) {






P[i][j][k][l][s] += P[ip][jp][kp][lp][sp];
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int l = max({i, 0}); l < N; ++l) {

for (int k = 0; k < min({(i) + 1, N}); ++k) {

for (int j = 0; j < N; ++j) {

for (int s = max({l, 0}); s < min({(j) + 1, N}); ++s) {






P[i][j][k][l][s] += P[ip][jp][kp][lp][sp];
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int j = 0; j < N; ++j) {

for (int k = 0; k < min({(i) + 1, N}); ++k) {

for (int s = max({i, 0}); s < min({(j) + 1, N}); ++s) {

for (int l = max({j, 0}); l < N; ++l) {






P[i][j][k][l][s] += P[ip][jp][kp][lp][sp];
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int j = 0; j < N; ++j) {

for (int k = 0; k < min({(i) + 1, N}); ++k) {

for (int l = 0; l < min({(j) + 1, N}); ++l) {

for (int s = max({i, 0}); s < min({(l) + 1, N}); ++s) {






P[i][j][k][l][s] += P[ip][jp][kp][lp][sp];
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int j = 0; j < N; ++j) {

for (int l = 0; l < min({(j) + 1, N}); ++l) {

for (int k = max({j, 0}); k < N; ++k) {

for (int s = max({k, 0}); s < min({(i) + 1, N}); ++s) {






P[i][j][k][l][s] += P[ip][jp][kp][lp][sp];
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int s = max({i, 0}); s < N; ++s) {

for (int j = 0; j < N; ++j) {

for (int l = 0; l < min({(j) + 1, N}); ++l) {

for (int k = max({j, 0}); k < min({(i) + 1, N}); ++k) {






P[i][j][k][l][s] += P[ip][jp][kp][lp][sp];
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int j = 0; j < N; ++j) {

for (int k = 0; k < min({(i) + 1, N}); ++k) {

for (int l = 0; l < min({(j) + 1, N}); ++l) {

for (int s = max({j, 0}); s < min({(k) + 1, N}); ++s) {






P[i][j][k][l][s] += P[ip][jp][kp][lp][sp];
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int j = 0; j < N; ++j) {

for (int k = max({i, 0}); k < N; ++k) {

for (int s = max({j, 0}); s < min({(i) + 1, N}); ++s) {

for (int l = 0; l < min({(j) + 1, N}); ++l) {






P[i][j][k][l][s] += P[ip][jp][kp][lp][sp];
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int j = 0; j < min({(i) + 1, N}); ++j) {

for (int k = max({i, 0}); k < N; ++k) {

for (int l = 0; l < min({(j) + 1, N}); ++l) {

for (int s = max({k, 0}); s < N; ++s) {






P[i][j][k][l][s] += P[ip][jp][kp][lp][sp];
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int j = 0; j < min({(i) + 1, N}); ++j) {

for (int l = 0; l < min({(j) + 1, N}); ++l) {

for (int k = 0; k < N; ++k) {

for (int s = max({i, 0}); s < min({(k) + 1, N}); ++s) {






P[i][j][k][l][s] += P[ip][jp][kp][lp][sp];
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int j = 0; j < N; ++j) {

for (int s = max({j, 0}); s < min({(i) + 1, N}); ++s) {

for (int k = 0; k < min({(j) + 1, N}); ++k) {

for (int l = 0; l < min({(k) + 1, N}); ++l) {






P[i][j][k][l][s] += P[ip][jp][kp][lp][sp];
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int s = max({i, 0}); s < N; ++s) {

for (int j = 0; j < min({(i) + 1, N}); ++j) {

for (int k = 0; k < min({(j) + 1, N}); ++k) {

for (int l = 0; l < min({(k) + 1, N}); ++l) {






P[i][j][k][l][s] += P[ip][jp][kp][lp][sp];
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int j = 0; j < min({(i) + 1, N}); ++j) {

for (int k = 0; k < N; ++k) {

for (int s = max({k, 0}); s < min({(j) + 1, N}); ++s) {

for (int l = 0; l < min({(k) + 1, N}); ++l) {






P[i][j][k][l][s] += P[ip][jp][kp][lp][sp];
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int j = max({i, 0}); j < N; ++j) {

for (int k = 0; k < N; ++k) {

for (int s = max({k, 0}); s < min({(i) + 1, N}); ++s) {

for (int l = 0; l < min({(k) + 1, N}); ++l) {






P[i][j][k][l][s] += P[ip][jp][kp][lp][sp];
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int j = max({i, 0}); j < N; ++j) {

for (int k = 0; k < min({(i) + 1, N}); ++k) {

for (int s = max({j, 0}); s < N; ++s) {

for (int l = 0; l < min({(k) + 1, N}); ++l) {






P[i][j][k][l][s] += P[ip][jp][kp][lp][sp];
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int j = 0; j < N; ++j) {

for (int k = 0; k < min({(i) + 1, N}); ++k) {

for (int s = max({i, 0}); s < min({(j) + 1, N}); ++s) {

for (int l = 0; l < min({(k) + 1, N}); ++l) {






P[i][j][k][l][s] += P[ip][jp][kp][lp][sp];
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int j = 0; j < N; ++j) {

for (int k = max({j, 0}); k < min({(i) + 1, N}); ++k) {

for (int l = 0; l < N; ++l) {

for (int s = max({l, 0}); s < min({(j) + 1, N}); ++s) {






P[i][j][k][l][s] += P[ip][jp][kp][lp][sp];
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int j = 0; j < min({(i) + 1, N}); ++j) {

for (int k = max({i, 0}); k < N; ++k) {

for (int l = 0; l < N; ++l) {

for (int s = max({l, 0}); s < min({(j) + 1, N}); ++s) {






P[i][j][k][l][s] += P[ip][jp][kp][lp][sp];
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int j = 0; j < min({(i) + 1, N}); ++j) {

for (int k = 0; k < min({(j) + 1, N}); ++k) {

for (int l = 0; l < N; ++l) {

for (int s = max({l, 0}); s < min({(k) + 1, N}); ++s) {






P[i][j][k][l][s] += P[ip][jp][kp][lp][sp];
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int j = max({i, 0}); j < N; ++j) {

for (int k = 0; k < min({(i) + 1, N}); ++k) {

for (int l = 0; l < N; ++l) {

for (int s = max({l, 0}); s < min({(k) + 1, N}); ++s) {






P[i][j][k][l][s] += P[ip][jp][kp][lp][sp];
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int j = max({i, 0}); j < N; ++j) {

for (int k = max({j, 0}); k < N; ++k) {

for (int l = 0; l < N; ++l) {

for (int s = max({l, 0}); s < min({(i) + 1, N}); ++s) {






P[i][j][k][l][s] += P[ip][jp][kp][lp][sp];
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int j = 0; j < N; ++j) {

for (int k = max({i, 0}); k < min({(j) + 1, N}); ++k) {

for (int l = 0; l < N; ++l) {

for (int s = max({l, 0}); s < min({(i) + 1, N}); ++s) {






P[i][j][k][l][s] += P[ip][jp][kp][lp][sp];
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int l = 0; l < min({(i) + 1, N}); ++l) {

for (int j = max({i, 0}); j < N; ++j) {

for (int k = max({j, 0}); k < N; ++k) {

for (int s = max({k, 0}); s < N; ++s) {






P[i][j][k][l][s] += P[ip][jp][kp][lp][sp];
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int l = 0; l < min({(i) + 1, N}); ++l) {

for (int j = max({i, 0}); j < N; ++j) {

for (int k = 0; k < N; ++k) {

for (int s = max({j, 0}); s < min({(k) + 1, N}); ++s) {






P[i][j][k][l][s] += P[ip][jp][kp][lp][sp];
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int l = 0; l < min({(i) + 1, N}); ++l) {

for (int j = 0; j < N; ++j) {

for (int s = max({j, 0}); s < N; ++s) {

for (int k = max({i, 0}); k < min({(j) + 1, N}); ++k) {






P[i][j][k][l][s] += P[ip][jp][kp][lp][sp];
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int l = 0; l < min({(i) + 1, N}); ++l) {

for (int k = max({i, 0}); k < N; ++k) {

for (int j = 0; j < N; ++j) {

for (int s = max({k, 0}); s < min({(j) + 1, N}); ++s) {






P[i][j][k][l][s] += P[ip][jp][kp][lp][sp];
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int l = 0; l < min({(i) + 1, N}); ++l) {

for (int j = 0; j < N; ++j) {

for (int s = max({i, 0}); s < min({(j) + 1, N}); ++s) {

for (int k = max({j, 0}); k < N; ++k) {






P[i][j][k][l][s] += P[ip][jp][kp][lp][sp];
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int l = 0; l < min({(i) + 1, N}); ++l) {

for (int j = 0; j < N; ++j) {

for (int k = 0; k < min({(j) + 1, N}); ++k) {

for (int s = max({i, 0}); s < min({(k) + 1, N}); ++s) {






P[i][j][k][l][s] += P[ip][jp][kp][lp][sp];
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int j = 0; j < N; ++j) {

for (int s = 0; s < min({(j) + 1, N}); ++s) {

for (int k = max({j, 0}); k < N; ++k) {

for (int l = max({k, 0}); l < min({(i) + 1, N}); ++l) {






P[i][j][k][l][s] += P[ip][jp][kp][lp][sp];
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int l = max({i, 0}); l < N; ++l) {

for (int j = 0; j < N; ++j) {

for (int s = 0; s < min({(j) + 1, N}); ++s) {

for (int k = max({j, 0}); k < min({(i) + 1, N}); ++k) {






P[i][j][k][l][s] += P[ip][jp][kp][lp][sp];
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int j = 0; j < N; ++j) {

for (int k = 0; k < min({(i) + 1, N}); ++k) {

for (int s = 0; s < min({(j) + 1, N}); ++s) {

for (int l = max({j, 0}); l < min({(k) + 1, N}); ++l) {






P[i][j][k][l][s] += P[ip][jp][kp][lp][sp];
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int j = 0; j < N; ++j) {

for (int k = max({i, 0}); k < N; ++k) {

for (int s = 0; s < min({(j) + 1, N}); ++s) {

for (int l = max({j, 0}); l < min({(i) + 1, N}); ++l) {






P[i][j][k][l][s] += P[ip][jp][kp][lp][sp];
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int j = 0; j < min({(i) + 1, N}); ++j) {

for (int k = max({i, 0}); k < N; ++k) {

for (int s = 0; s < min({(j) + 1, N}); ++s) {

for (int l = max({k, 0}); l < N; ++l) {






P[i][j][k][l][s] += P[ip][jp][kp][lp][sp];
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int j = 0; j < min({(i) + 1, N}); ++j) {

for (int s = 0; s < min({(j) + 1, N}); ++s) {

for (int k = 0; k < N; ++k) {

for (int l = max({i, 0}); l < min({(k) + 1, N}); ++l) {






P[i][j][k][l][s] += P[ip][jp][kp][lp][sp];
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int j = 0; j < N; ++j) {

for (int l = max({j, 0}); l < min({(i) + 1, N}); ++l) {

for (int k = 0; k < min({(j) + 1, N}); ++k) {

for (int s = 0; s < min({(k) + 1, N}); ++s) {






P[i][j][k][l][s] += P[ip][jp][kp][lp][sp];
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int l = max({i, 0}); l < N; ++l) {

for (int j = 0; j < min({(i) + 1, N}); ++j) {

for (int k = 0; k < min({(j) + 1, N}); ++k) {

for (int s = 0; s < min({(k) + 1, N}); ++s) {






P[i][j][k][l][s] += P[ip][jp][kp][lp][sp];
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int j = 0; j < min({(i) + 1, N}); ++j) {

for (int k = 0; k < N; ++k) {

for (int s = 0; s < min({(k) + 1, N}); ++s) {

for (int l = max({k, 0}); l < min({(j) + 1, N}); ++l) {






P[i][j][k][l][s] += P[ip][jp][kp][lp][sp];
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int j = max({i, 0}); j < N; ++j) {

for (int k = 0; k < N; ++k) {

for (int s = 0; s < min({(k) + 1, N}); ++s) {

for (int l = max({k, 0}); l < min({(i) + 1, N}); ++l) {






P[i][j][k][l][s] += P[ip][jp][kp][lp][sp];
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int j = max({i, 0}); j < N; ++j) {

for (int k = 0; k < min({(i) + 1, N}); ++k) {

for (int l = max({j, 0}); l < N; ++l) {

for (int s = 0; s < min({(k) + 1, N}); ++s) {






P[i][j][k][l][s] += P[ip][jp][kp][lp][sp];
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int j = 0; j < N; ++j) {

for (int k = 0; k < min({(i) + 1, N}); ++k) {

for (int l = max({i, 0}); l < min({(j) + 1, N}); ++l) {

for (int s = 0; s < min({(k) + 1, N}); ++s) {






P[i][j][k][l][s] += P[ip][jp][kp][lp][sp];
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int j = 0; j < N; ++j) {

for (int l = 0; l < min({(j) + 1, N}); ++l) {

for (int k = max({j, 0}); k < min({(i) + 1, N}); ++k) {

for (int s = 0; s < min({(l) + 1, N}); ++s) {






P[i][j][k][l][s] += P[ip][jp][kp][lp][sp];
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int j = 0; j < min({(i) + 1, N}); ++j) {

for (int k = max({i, 0}); k < N; ++k) {

for (int l = 0; l < min({(j) + 1, N}); ++l) {

for (int s = 0; s < min({(l) + 1, N}); ++s) {






P[i][j][k][l][s] += P[ip][jp][kp][lp][sp];
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int j = 0; j < min({(i) + 1, N}); ++j) {

for (int k = 0; k < min({(j) + 1, N}); ++k) {

for (int l = 0; l < min({(k) + 1, N}); ++l) {

for (int s = 0; s < min({(l) + 1, N}); ++s) {






P[i][j][k][l][s] += P[ip][jp][kp][lp][sp];
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int j = max({i, 0}); j < N; ++j) {

for (int k = 0; k < min({(i) + 1, N}); ++k) {

for (int l = 0; l < min({(k) + 1, N}); ++l) {

for (int s = 0; s < min({(l) + 1, N}); ++s) {






P[i][j][k][l][s] += P[ip][jp][kp][lp][sp];
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int l = 0; l < min({(i) + 1, N}); ++l) {

for (int j = max({i, 0}); j < N; ++j) {

for (int s = 0; s < min({(l) + 1, N}); ++s) {

for (int k = max({j, 0}); k < N; ++k) {






P[i][j][k][l][s] += P[ip][jp][kp][lp][sp];
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int l = 0; l < min({(i) + 1, N}); ++l) {

for (int s = 0; s < min({(l) + 1, N}); ++s) {

for (int j = 0; j < N; ++j) {

for (int k = max({i, 0}); k < min({(j) + 1, N}); ++k) {






P[i][j][k][l][s] += P[ip][jp][kp][lp][sp];
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int s = 0; s < min({(i) + 1, N}); ++s) {

for (int j = max({i, 0}); j < N; ++j) {

for (int k = max({j, 0}); k < N; ++k) {

for (int l = max({k, 0}); l < N; ++l) {






P[i][j][k][l][s] += P[ip][jp][kp][lp][sp];
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int s = 0; s < min({(i) + 1, N}); ++s) {

for (int j = max({i, 0}); j < N; ++j) {

for (int k = 0; k < N; ++k) {

for (int l = max({j, 0}); l < min({(k) + 1, N}); ++l) {






P[i][j][k][l][s] += P[ip][jp][kp][lp][sp];
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int s = 0; s < min({(i) + 1, N}); ++s) {

for (int j = 0; j < N; ++j) {

for (int l = max({j, 0}); l < N; ++l) {

for (int k = max({i, 0}); k < min({(j) + 1, N}); ++k) {






P[i][j][k][l][s] += P[ip][jp][kp][lp][sp];
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int s = 0; s < min({(i) + 1, N}); ++s) {

for (int k = max({i, 0}); k < N; ++k) {

for (int j = 0; j < N; ++j) {

for (int l = max({k, 0}); l < min({(j) + 1, N}); ++l) {






P[i][j][k][l][s] += P[ip][jp][kp][lp][sp];
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int s = 0; s < min({(i) + 1, N}); ++s) {

for (int j = 0; j < N; ++j) {

for (int l = max({i, 0}); l < min({(j) + 1, N}); ++l) {

for (int k = max({j, 0}); k < N; ++k) {






P[i][j][k][l][s] += P[ip][jp][kp][lp][sp];
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int s = 0; s < min({(i) + 1, N}); ++s) {

for (int j = 0; j < N; ++j) {

for (int k = 0; k < min({(j) + 1, N}); ++k) {

for (int l = max({i, 0}); l < min({(k) + 1, N}); ++l) {






P[i][j][k][l][s] += P[ip][jp][kp][lp][sp];
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int j = max({i, 0}); j < N; ++j) {

for (int k = max({j, 0}); k < N; ++k) {

for (int l = max({k, 0}); l < N; ++l) {

for (int s = max({l, 0}); s < N; ++s) {






P[i][j][k][l][s] += P[ip][jp][kp][lp][sp];
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int j = max({i, 0}); j < N; ++j) {

for (int k = max({j, 0}); k < N; ++k) {

for (int l = 0; l < N; ++l) {

for (int s = max({k, 0}); s < min({(l) + 1, N}); ++s) {






P[i][j][k][l][s] += P[ip][jp][kp][lp][sp];
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int j = max({i, 0}); j < N; ++j) {

for (int k = 0; k < N; ++k) {

for (int s = max({k, 0}); s < N; ++s) {

for (int l = max({j, 0}); l < min({(k) + 1, N}); ++l) {






P[i][j][k][l][s] += P[ip][jp][kp][lp][sp];
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int j = max({i, 0}); j < N; ++j) {

for (int l = max({j, 0}); l < N; ++l) {

for (int k = 0; k < N; ++k) {

for (int s = max({l, 0}); s < min({(k) + 1, N}); ++s) {






P[i][j][k][l][s] += P[ip][jp][kp][lp][sp];
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int j = max({i, 0}); j < N; ++j) {

for (int k = 0; k < N; ++k) {

for (int s = max({j, 0}); s < min({(k) + 1, N}); ++s) {

for (int l = max({k, 0}); l < N; ++l) {






P[i][j][k][l][s] += P[ip][jp][kp][lp][sp];
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int j = max({i, 0}); j < N; ++j) {

for (int k = 0; k < N; ++k) {

for (int l = 0; l < min({(k) + 1, N}); ++l) {

for (int s = max({j, 0}); s < min({(l) + 1, N}); ++s) {






P[i][j][k][l][s] += P[ip][jp][kp][lp][sp];
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int j = 0; j < N; ++j) {

for (int l = max({j, 0}); l < N; ++l) {

for (int k = max({i, 0}); k < min({(j) + 1, N}); ++k) {

for (int s = max({l, 0}); s < N; ++s) {






P[i][j][k][l][s] += P[ip][jp][kp][lp][sp];
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int j = 0; j < N; ++j) {

for (int k = max({i, 0}); k < min({(j) + 1, N}); ++k) {

for (int l = 0; l < N; ++l) {

for (int s = max({j, 0}); s < min({(l) + 1, N}); ++s) {






P[i][j][k][l][s] += P[ip][jp][kp][lp][sp];
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int j = 0; j < N; ++j) {

for (int k = max({i, 0}); k < N; ++k) {

for (int s = max({j, 0}); s < N; ++s) {

for (int l = max({k, 0}); l < min({(j) + 1, N}); ++l) {






P[i][j][k][l][s] += P[ip][jp][kp][lp][sp];
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int j = 0; j < N; ++j) {

for (int k = max({i, 0}); k < N; ++k) {

for (int l = max({k, 0}); l < N; ++l) {

for (int s = max({l, 0}); s < min({(j) + 1, N}); ++s) {






P[i][j][k][l][s] += P[ip][jp][kp][lp][sp];
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int j = 0; j < N; ++j) {

for (int k = max({i, 0}); k < N; ++k) {

for (int l = max({j, 0}); l < N; ++l) {

for (int s = max({k, 0}); s < min({(j) + 1, N}); ++s) {






P[i][j][k][l][s] += P[ip][jp][kp][lp][sp];
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int j = 0; j < N; ++j) {

for (int k = max({i, 0}); k < N; ++k) {

for (int l = 0; l < min({(j) + 1, N}); ++l) {

for (int s = max({k, 0}); s < min({(l) + 1, N}); ++s) {






P[i][j][k][l][s] += P[ip][jp][kp][lp][sp];
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int j = 0; j < N; ++j) {

for (int l = max({i, 0}); l < min({(j) + 1, N}); ++l) {

for (int k = max({j, 0}); k < N; ++k) {

for (int s = max({k, 0}); s < N; ++s) {






P[i][j][k][l][s] += P[ip][jp][kp][lp][sp];
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int j = 0; j < N; ++j) {

for (int l = max({i, 0}); l < min({(j) + 1, N}); ++l) {

for (int k = 0; k < N; ++k) {

for (int s = max({j, 0}); s < min({(k) + 1, N}); ++s) {






P[i][j][k][l][s] += P[ip][jp][kp][lp][sp];
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int j = 0; j < N; ++j) {

for (int s = max({j, 0}); s < N; ++s) {

for (int k = 0; k < min({(j) + 1, N}); ++k) {

for (int l = max({i, 0}); l < min({(k) + 1, N}); ++l) {






P[i][j][k][l][s] += P[ip][jp][kp][lp][sp];
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int j = 0; j < N; ++j) {

for (int k = 0; k < N; ++k) {

for (int s = max({k, 0}); s < min({(j) + 1, N}); ++s) {

for (int l = max({i, 0}); l < min({(k) + 1, N}); ++l) {






P[i][j][k][l][s] += P[ip][jp][kp][lp][sp];
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int l = max({i, 0}); l < N; ++l) {

for (int j = 0; j < N; ++j) {

for (int s = max({l, 0}); s < min({(j) + 1, N}); ++s) {

for (int k = max({j, 0}); k < N; ++k) {






P[i][j][k][l][s] += P[ip][jp][kp][lp][sp];
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int l = max({i, 0}); l < N; ++l) {

for (int j = 0; j < N; ++j) {

for (int k = 0; k < min({(j) + 1, N}); ++k) {

for (int s = max({l, 0}); s < min({(k) + 1, N}); ++s) {






P[i][j][k][l][s] += P[ip][jp][kp][lp][sp];
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int j = 0; j < N; ++j) {

for (int s = max({i, 0}); s < min({(j) + 1, N}); ++s) {

for (int k = max({j, 0}); k < N; ++k) {

for (int l = max({k, 0}); l < N; ++l) {






P[i][j][k][l][s] += P[ip][jp][kp][lp][sp];
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int j = 0; j < N; ++j) {

for (int s = max({i, 0}); s < min({(j) + 1, N}); ++s) {

for (int k = 0; k < N; ++k) {

for (int l = max({j, 0}); l < min({(k) + 1, N}); ++l) {






P[i][j][k][l][s] += P[ip][jp][kp][lp][sp];
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int j = 0; j < N; ++j) {

for (int l = max({j, 0}); l < N; ++l) {

for (int k = 0; k < min({(j) + 1, N}); ++k) {

for (int s = max({i, 0}); s < min({(k) + 1, N}); ++s) {






P[i][j][k][l][s] += P[ip][jp][kp][lp][sp];
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int j = 0; j < N; ++j) {

for (int k = 0; k < N; ++k) {

for (int s = max({i, 0}); s < min({(k) + 1, N}); ++s) {

for (int l = max({k, 0}); l < min({(j) + 1, N}); ++l) {






P[i][j][k][l][s] += P[ip][jp][kp][lp][sp];
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int j = 0; j < N; ++j) {

for (int l = 0; l < min({(j) + 1, N}); ++l) {

for (int k = max({j, 0}); k < N; ++k) {

for (int s = max({i, 0}); s < min({(l) + 1, N}); ++s) {






P[i][j][k][l][s] += P[ip][jp][kp][lp][sp];
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int j = 0; j < N; ++j) {

for (int k = 0; k < min({(j) + 1, N}); ++k) {

for (int l = 0; l < min({(k) + 1, N}); ++l) {

for (int s = max({i, 0}); s < min({(l) + 1, N}); ++s) {






P[i][j][k][l][s] += P[ip][jp][kp][lp][sp];
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int t = max({i, 0}); t < N; ++t) {

for (int j = 0; j < N; ++j) {

for (int k = max({j, 0}); k < N; ++k) {

for (int l = max({k, 0}); l < N; ++l) {

for (int s = max({l, 0}); s < min({(i) + 1, N}); ++s) {







O[i][j][k][l][s][t] += O[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int s = 0; s < min({(i) + 1, N}); ++s) {

for (int j = 0; j < N; ++j) {

for (int k = max({j, 0}); k < N; ++k) {

for (int l = max({k, 0}); l < N; ++l) {

for (int t = max({l, 0}); t < min({(s) + 1, N}); ++t) {







O[i][j][k][l][s][t] += O[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int s = max({i, 0}); s < N; ++s) {

for (int j = 0; j < N; ++j) {

for (int k = max({j, 0}); k < N; ++k) {

for (int l = max({k, 0}); l < N; ++l) {

for (int t = max({l, 0}); t < min({(i) + 1, N}); ++t) {







O[i][j][k][l][s][t] += O[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int s = max({i, 0}); s < N; ++s) {

for (int t = max({s, 0}); t < N; ++t) {

for (int j = 0; j < N; ++j) {

for (int k = max({j, 0}); k < N; ++k) {

for (int l = max({k, 0}); l < min({(i) + 1, N}); ++l) {







O[i][j][k][l][s][t] += O[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int j = 0; j < N; ++j) {

for (int k = max({j, 0}); k < N; ++k) {

for (int l = max({k, 0}); l < min({(i) + 1, N}); ++l) {

for (int s = 0; s < N; ++s) {

for (int t = max({i, 0}); t < min({(s) + 1, N}); ++t) {







O[i][j][k][l][s][t] += O[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int j = 0; j < N; ++j) {

for (int k = max({j, 0}); k < N; ++k) {

for (int l = 0; l < N; ++l) {

for (int s = max({k, 0}); s < min({(l) + 1, N}); ++s) {

for (int t = max({l, 0}); t < min({(i) + 1, N}); ++t) {







O[i][j][k][l][s][t] += O[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int t = max({i, 0}); t < N; ++t) {

for (int l = 0; l < min({(i) + 1, N}); ++l) {

for (int j = 0; j < N; ++j) {

for (int k = max({j, 0}); k < N; ++k) {

for (int s = max({k, 0}); s < min({(l) + 1, N}); ++s) {







O[i][j][k][l][s][t] += O[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int l = 0; l < min({(i) + 1, N}); ++l) {

for (int j = 0; j < N; ++j) {

for (int k = max({j, 0}); k < N; ++k) {

for (int s = max({k, 0}); s < N; ++s) {

for (int t = max({s, 0}); t < min({(l) + 1, N}); ++t) {







O[i][j][k][l][s][t] += O[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int l = max({i, 0}); l < N; ++l) {

for (int j = 0; j < N; ++j) {

for (int k = max({j, 0}); k < N; ++k) {

for (int s = max({k, 0}); s < N; ++s) {

for (int t = max({s, 0}); t < min({(i) + 1, N}); ++t) {







O[i][j][k][l][s][t] += O[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int l = max({i, 0}); l < N; ++l) {

for (int t = max({l, 0}); t < N; ++t) {

for (int j = 0; j < N; ++j) {

for (int k = max({j, 0}); k < N; ++k) {

for (int s = max({k, 0}); s < min({(i) + 1, N}); ++s) {







O[i][j][k][l][s][t] += O[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int j = 0; j < N; ++j) {

for (int k = max({j, 0}); k < N; ++k) {

for (int s = max({k, 0}); s < min({(i) + 1, N}); ++s) {

for (int l = 0; l < N; ++l) {

for (int t = max({i, 0}); t < min({(l) + 1, N}); ++t) {







O[i][j][k][l][s][t] += O[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int j = 0; j < N; ++j) {

for (int k = max({j, 0}); k < N; ++k) {

for (int l = 0; l < N; ++l) {

for (int s = max({l, 0}); s < min({(i) + 1, N}); ++s) {

for (int t = max({k, 0}); t < min({(l) + 1, N}); ++t) {







O[i][j][k][l][s][t] += O[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int s = max({i, 0}); s < N; ++s) {

for (int l = 0; l < min({(i) + 1, N}); ++l) {

for (int j = 0; j < N; ++j) {

for (int k = max({j, 0}); k < N; ++k) {

for (int t = max({k, 0}); t < min({(l) + 1, N}); ++t) {







O[i][j][k][l][s][t] += O[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int l = 0; l < min({(i) + 1, N}); ++l) {

for (int s = 0; s < min({(l) + 1, N}); ++s) {

for (int j = 0; j < N; ++j) {

for (int k = max({j, 0}); k < N; ++k) {

for (int t = max({k, 0}); t < min({(s) + 1, N}); ++t) {







O[i][j][k][l][s][t] += O[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int s = 0; s < min({(i) + 1, N}); ++s) {

for (int l = max({i, 0}); l < N; ++l) {

for (int j = 0; j < N; ++j) {

for (int k = max({j, 0}); k < N; ++k) {

for (int t = max({k, 0}); t < min({(s) + 1, N}); ++t) {







O[i][j][k][l][s][t] += O[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int l = max({i, 0}); l < N; ++l) {

for (int s = max({l, 0}); s < N; ++s) {

for (int j = 0; j < N; ++j) {

for (int k = max({j, 0}); k < N; ++k) {

for (int t = max({k, 0}); t < min({(i) + 1, N}); ++t) {







O[i][j][k][l][s][t] += O[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int j = 0; j < N; ++j) {

for (int k = max({j, 0}); k < N; ++k) {

for (int t = max({k, 0}); t < min({(i) + 1, N}); ++t) {

for (int l = 0; l < N; ++l) {

for (int s = max({i, 0}); s < min({(l) + 1, N}); ++s) {







O[i][j][k][l][s][t] += O[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int l = max({i, 0}); l < N; ++l) {

for (int s = max({l, 0}); s < N; ++s) {

for (int t = max({s, 0}); t < N; ++t) {

for (int j = 0; j < N; ++j) {

for (int k = max({j, 0}); k < min({(i) + 1, N}); ++k) {







O[i][j][k][l][s][t] += O[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int l = max({i, 0}); l < N; ++l) {

for (int j = 0; j < N; ++j) {

for (int k = max({j, 0}); k < min({(i) + 1, N}); ++k) {

for (int s = 0; s < N; ++s) {

for (int t = max({l, 0}); t < min({(s) + 1, N}); ++t) {







O[i][j][k][l][s][t] += O[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int j = 0; j < N; ++j) {

for (int k = max({j, 0}); k < min({(i) + 1, N}); ++k) {

for (int l = 0; l < N; ++l) {

for (int s = max({i, 0}); s < min({(l) + 1, N}); ++s) {

for (int t = max({l, 0}); t < N; ++t) {







O[i][j][k][l][s][t] += O[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int s = max({i, 0}); s < N; ++s) {

for (int j = 0; j < N; ++j) {

for (int k = max({j, 0}); k < min({(i) + 1, N}); ++k) {

for (int l = 0; l < N; ++l) {

for (int t = max({s, 0}); t < min({(l) + 1, N}); ++t) {







O[i][j][k][l][s][t] += O[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int j = 0; j < N; ++j) {

for (int k = max({j, 0}); k < min({(i) + 1, N}); ++k) {

for (int l = 0; l < N; ++l) {

for (int s = max({l, 0}); s < N; ++s) {

for (int t = max({i, 0}); t < min({(l) + 1, N}); ++t) {







O[i][j][k][l][s][t] += O[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int j = 0; j < N; ++j) {

for (int k = max({j, 0}); k < min({(i) + 1, N}); ++k) {

for (int l = 0; l < N; ++l) {

for (int s = 0; s < min({(l) + 1, N}); ++s) {

for (int t = max({i, 0}); t < min({(s) + 1, N}); ++t) {







O[i][j][k][l][s][t] += O[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int j = 0; j < N; ++j) {

for (int k = 0; k < N; ++k) {

for (int s = max({k, 0}); s < N; ++s) {

for (int l = max({j, 0}); l < min({(k) + 1, N}); ++l) {

for (int t = max({s, 0}); t < min({(i) + 1, N}); ++t) {







O[i][j][k][l][s][t] += O[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int t = max({i, 0}); t < N; ++t) {

for (int j = 0; j < N; ++j) {

for (int k = 0; k < N; ++k) {

for (int s = max({k, 0}); s < min({(i) + 1, N}); ++s) {

for (int l = max({j, 0}); l < min({(k) + 1, N}); ++l) {







O[i][j][k][l][s][t] += O[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int s = 0; s < min({(i) + 1, N}); ++s) {

for (int j = 0; j < N; ++j) {

for (int k = 0; k < N; ++k) {

for (int t = max({k, 0}); t < min({(s) + 1, N}); ++t) {

for (int l = max({j, 0}); l < min({(k) + 1, N}); ++l) {







O[i][j][k][l][s][t] += O[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int s = max({i, 0}); s < N; ++s) {

for (int j = 0; j < N; ++j) {

for (int k = 0; k < N; ++k) {

for (int t = max({k, 0}); t < min({(i) + 1, N}); ++t) {

for (int l = max({j, 0}); l < min({(k) + 1, N}); ++l) {







O[i][j][k][l][s][t] += O[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int s = max({i, 0}); s < N; ++s) {

for (int k = 0; k < min({(i) + 1, N}); ++k) {

for (int t = max({s, 0}); t < N; ++t) {

for (int j = 0; j < N; ++j) {

for (int l = max({j, 0}); l < min({(k) + 1, N}); ++l) {







O[i][j][k][l][s][t] += O[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int j = 0; j < N; ++j) {

for (int k = 0; k < min({(i) + 1, N}); ++k) {

for (int l = max({j, 0}); l < min({(k) + 1, N}); ++l) {

for (int s = 0; s < N; ++s) {

for (int t = max({i, 0}); t < min({(s) + 1, N}); ++t) {







O[i][j][k][l][s][t] += O[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int j = 0; j < N; ++j) {

for (int l = max({j, 0}); l < N; ++l) {

for (int k = 0; k < N; ++k) {

for (int s = max({l, 0}); s < min({(k) + 1, N}); ++s) {

for (int t = max({k, 0}); t < min({(i) + 1, N}); ++t) {







O[i][j][k][l][s][t] += O[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int t = max({i, 0}); t < N; ++t) {

for (int k = 0; k < min({(i) + 1, N}); ++k) {

for (int j = 0; j < N; ++j) {

for (int l = max({j, 0}); l < N; ++l) {

for (int s = max({l, 0}); s < min({(k) + 1, N}); ++s) {







O[i][j][k][l][s][t] += O[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int j = 0; j < N; ++j) {

for (int k = 0; k < min({(i) + 1, N}); ++k) {

for (int l = max({j, 0}); l < N; ++l) {

for (int s = max({l, 0}); s < N; ++s) {

for (int t = max({s, 0}); t < min({(k) + 1, N}); ++t) {







O[i][j][k][l][s][t] += O[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int j = 0; j < N; ++j) {

for (int k = max({i, 0}); k < N; ++k) {

for (int l = max({j, 0}); l < N; ++l) {

for (int s = max({l, 0}); s < N; ++s) {

for (int t = max({s, 0}); t < min({(i) + 1, N}); ++t) {







O[i][j][k][l][s][t] += O[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int j = 0; j < N; ++j) {

for (int k = max({i, 0}); k < N; ++k) {

for (int l = max({j, 0}); l < N; ++l) {

for (int t = max({k, 0}); t < N; ++t) {

for (int s = max({l, 0}); s < min({(i) + 1, N}); ++s) {







O[i][j][k][l][s][t] += O[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int j = 0; j < N; ++j) {

for (int l = max({j, 0}); l < N; ++l) {

for (int s = max({l, 0}); s < min({(i) + 1, N}); ++s) {

for (int k = 0; k < N; ++k) {

for (int t = max({i, 0}); t < min({(k) + 1, N}); ++t) {







O[i][j][k][l][s][t] += O[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int j = 0; j < N; ++j) {

for (int l = max({j, 0}); l < N; ++l) {

for (int k = 0; k < N; ++k) {

for (int s = max({k, 0}); s < min({(i) + 1, N}); ++s) {

for (int t = max({l, 0}); t < min({(k) + 1, N}); ++t) {







O[i][j][k][l][s][t] += O[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int s = max({i, 0}); s < N; ++s) {

for (int k = 0; k < min({(i) + 1, N}); ++k) {

for (int j = 0; j < N; ++j) {

for (int l = max({j, 0}); l < N; ++l) {

for (int t = max({l, 0}); t < min({(k) + 1, N}); ++t) {







O[i][j][k][l][s][t] += O[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int j = 0; j < N; ++j) {

for (int k = 0; k < min({(i) + 1, N}); ++k) {

for (int l = max({j, 0}); l < N; ++l) {

for (int s = 0; s < min({(k) + 1, N}); ++s) {

for (int t = max({l, 0}); t < min({(s) + 1, N}); ++t) {







O[i][j][k][l][s][t] += O[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int s = 0; s < min({(i) + 1, N}); ++s) {

for (int k = max({i, 0}); k < N; ++k) {

for (int j = 0; j < N; ++j) {

for (int l = max({j, 0}); l < N; ++l) {

for (int t = max({l, 0}); t < min({(s) + 1, N}); ++t) {







O[i][j][k][l][s][t] += O[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int j = 0; j < N; ++j) {

for (int k = max({i, 0}); k < N; ++k) {

for (int l = max({j, 0}); l < N; ++l) {

for (int s = max({k, 0}); s < N; ++s) {

for (int t = max({l, 0}); t < min({(i) + 1, N}); ++t) {







O[i][j][k][l][s][t] += O[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int j = 0; j < N; ++j) {

for (int l = max({j, 0}); l < N; ++l) {

for (int t = max({l, 0}); t < min({(i) + 1, N}); ++t) {

for (int k = 0; k < N; ++k) {

for (int s = max({i, 0}); s < min({(k) + 1, N}); ++s) {







O[i][j][k][l][s][t] += O[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int j = 0; j < N; ++j) {

for (int k = max({i, 0}); k < N; ++k) {

for (int l = max({j, 0}); l < min({(i) + 1, N}); ++l) {

for (int s = max({k, 0}); s < N; ++s) {

for (int t = max({s, 0}); t < N; ++t) {







O[i][j][k][l][s][t] += O[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int j = 0; j < N; ++j) {

for (int k = max({i, 0}); k < N; ++k) {

for (int l = max({j, 0}); l < min({(i) + 1, N}); ++l) {

for (int s = 0; s < N; ++s) {

for (int t = max({k, 0}); t < min({(s) + 1, N}); ++t) {







O[i][j][k][l][s][t] += O[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int j = 0; j < N; ++j) {

for (int l = max({j, 0}); l < min({(i) + 1, N}); ++l) {

for (int k = 0; k < N; ++k) {

for (int s = max({i, 0}); s < min({(k) + 1, N}); ++s) {

for (int t = max({k, 0}); t < N; ++t) {







O[i][j][k][l][s][t] += O[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int s = max({i, 0}); s < N; ++s) {

for (int j = 0; j < N; ++j) {

for (int l = max({j, 0}); l < min({(i) + 1, N}); ++l) {

for (int k = 0; k < N; ++k) {

for (int t = max({s, 0}); t < min({(k) + 1, N}); ++t) {







O[i][j][k][l][s][t] += O[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int j = 0; j < N; ++j) {

for (int l = max({j, 0}); l < min({(i) + 1, N}); ++l) {

for (int k = 0; k < N; ++k) {

for (int s = max({k, 0}); s < N; ++s) {

for (int t = max({i, 0}); t < min({(k) + 1, N}); ++t) {







O[i][j][k][l][s][t] += O[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int j = 0; j < N; ++j) {

for (int l = max({j, 0}); l < min({(i) + 1, N}); ++l) {

for (int k = 0; k < N; ++k) {

for (int s = 0; s < min({(k) + 1, N}); ++s) {

for (int t = max({i, 0}); t < min({(s) + 1, N}); ++t) {







O[i][j][k][l][s][t] += O[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int j = 0; j < N; ++j) {

for (int k = 0; k < N; ++k) {

for (int s = max({j, 0}); s < min({(k) + 1, N}); ++s) {

for (int l = max({k, 0}); l < N; ++l) {

for (int t = max({l, 0}); t < min({(i) + 1, N}); ++t) {







O[i][j][k][l][s][t] += O[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int t = max({i, 0}); t < N; ++t) {

for (int j = 0; j < N; ++j) {

for (int k = 0; k < N; ++k) {

for (int s = max({j, 0}); s < min({(k) + 1, N}); ++s) {

for (int l = max({k, 0}); l < min({(i) + 1, N}); ++l) {







O[i][j][k][l][s][t] += O[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int l = 0; l < min({(i) + 1, N}); ++l) {

for (int j = 0; j < N; ++j) {

for (int k = 0; k < N; ++k) {

for (int s = max({j, 0}); s < min({(k) + 1, N}); ++s) {

for (int t = max({k, 0}); t < min({(l) + 1, N}); ++t) {







O[i][j][k][l][s][t] += O[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int l = max({i, 0}); l < N; ++l) {

for (int j = 0; j < N; ++j) {

for (int k = 0; k < N; ++k) {

for (int s = max({j, 0}); s < min({(k) + 1, N}); ++s) {

for (int t = max({k, 0}); t < min({(i) + 1, N}); ++t) {







O[i][j][k][l][s][t] += O[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int l = max({i, 0}); l < N; ++l) {

for (int k = 0; k < min({(i) + 1, N}); ++k) {

for (int t = max({l, 0}); t < N; ++t) {

for (int j = 0; j < N; ++j) {

for (int s = max({j, 0}); s < min({(k) + 1, N}); ++s) {







O[i][j][k][l][s][t] += O[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int j = 0; j < N; ++j) {

for (int k = 0; k < min({(i) + 1, N}); ++k) {

for (int s = max({j, 0}); s < min({(k) + 1, N}); ++s) {

for (int l = 0; l < N; ++l) {

for (int t = max({i, 0}); t < min({(l) + 1, N}); ++t) {







O[i][j][k][l][s][t] += O[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int j = 0; j < N; ++j) {

for (int k = 0; k < N; ++k) {

for (int t = max({k, 0}); t < min({(i) + 1, N}); ++t) {

for (int l = 0; l < min({(k) + 1, N}); ++l) {

for (int s = max({j, 0}); s < min({(l) + 1, N}); ++s) {







O[i][j][k][l][s][t] += O[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int t = max({i, 0}); t < N; ++t) {

for (int k = 0; k < min({(i) + 1, N}); ++k) {

for (int l = 0; l < min({(k) + 1, N}); ++l) {

for (int j = 0; j < N; ++j) {

for (int s = max({j, 0}); s < min({(l) + 1, N}); ++s) {







O[i][j][k][l][s][t] += O[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int j = 0; j < N; ++j) {

for (int k = 0; k < min({(i) + 1, N}); ++k) {

for (int l = 0; l < N; ++l) {

for (int s = max({j, 0}); s < min({(l) + 1, N}); ++s) {

for (int t = max({l, 0}); t < min({(k) + 1, N}); ++t) {







O[i][j][k][l][s][t] += O[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int j = 0; j < N; ++j) {

for (int k = max({i, 0}); k < N; ++k) {

for (int l = 0; l < N; ++l) {

for (int s = max({j, 0}); s < min({(l) + 1, N}); ++s) {

for (int t = max({l, 0}); t < min({(i) + 1, N}); ++t) {







O[i][j][k][l][s][t] += O[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int l = 0; l < min({(i) + 1, N}); ++l) {

for (int k = max({i, 0}); k < N; ++k) {

for (int t = max({k, 0}); t < N; ++t) {

for (int j = 0; j < N; ++j) {

for (int s = max({j, 0}); s < min({(l) + 1, N}); ++s) {







O[i][j][k][l][s][t] += O[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int l = 0; l < min({(i) + 1, N}); ++l) {

for (int j = 0; j < N; ++j) {

for (int s = max({j, 0}); s < min({(l) + 1, N}); ++s) {

for (int k = 0; k < N; ++k) {

for (int t = max({i, 0}); t < min({(k) + 1, N}); ++t) {







O[i][j][k][l][s][t] += O[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int j = 0; j < N; ++j) {

for (int s = max({j, 0}); s < N; ++s) {

for (int k = 0; k < N; ++k) {

for (int t = max({s, 0}); t < min({(k) + 1, N}); ++t) {

for (int l = max({k, 0}); l < min({(i) + 1, N}); ++l) {







O[i][j][k][l][s][t] += O[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int l = max({i, 0}); l < N; ++l) {

for (int k = 0; k < min({(i) + 1, N}); ++k) {

for (int j = 0; j < N; ++j) {

for (int s = max({j, 0}); s < N; ++s) {

for (int t = max({s, 0}); t < min({(k) + 1, N}); ++t) {







O[i][j][k][l][s][t] += O[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int j = 0; j < N; ++j) {

for (int k = 0; k < min({(i) + 1, N}); ++k) {

for (int s = max({j, 0}); s < N; ++s) {

for (int l = 0; l < min({(k) + 1, N}); ++l) {

for (int t = max({s, 0}); t < min({(l) + 1, N}); ++t) {







O[i][j][k][l][s][t] += O[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int l = 0; l < min({(i) + 1, N}); ++l) {

for (int k = max({i, 0}); k < N; ++k) {

for (int j = 0; j < N; ++j) {

for (int s = max({j, 0}); s < N; ++s) {

for (int t = max({s, 0}); t < min({(l) + 1, N}); ++t) {







O[i][j][k][l][s][t] += O[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int j = 0; j < N; ++j) {

for (int k = max({i, 0}); k < N; ++k) {

for (int s = max({j, 0}); s < N; ++s) {

for (int l = max({k, 0}); l < N; ++l) {

for (int t = max({s, 0}); t < min({(i) + 1, N}); ++t) {







O[i][j][k][l][s][t] += O[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int j = 0; j < N; ++j) {

for (int s = max({j, 0}); s < N; ++s) {

for (int t = max({s, 0}); t < min({(i) + 1, N}); ++t) {

for (int k = 0; k < N; ++k) {

for (int l = max({i, 0}); l < min({(k) + 1, N}); ++l) {







O[i][j][k][l][s][t] += O[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int j = 0; j < N; ++j) {

for (int k = max({i, 0}); k < N; ++k) {

for (int s = max({j, 0}); s < min({(i) + 1, N}); ++s) {

for (int l = max({k, 0}); l < N; ++l) {

for (int t = max({l, 0}); t < N; ++t) {







O[i][j][k][l][s][t] += O[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int j = 0; j < N; ++j) {

for (int k = max({i, 0}); k < N; ++k) {

for (int s = max({j, 0}); s < min({(i) + 1, N}); ++s) {

for (int l = 0; l < N; ++l) {

for (int t = max({k, 0}); t < min({(l) + 1, N}); ++t) {







O[i][j][k][l][s][t] += O[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int j = 0; j < N; ++j) {

for (int s = max({j, 0}); s < min({(i) + 1, N}); ++s) {

for (int k = 0; k < N; ++k) {

for (int t = max({k, 0}); t < N; ++t) {

for (int l = max({i, 0}); l < min({(k) + 1, N}); ++l) {







O[i][j][k][l][s][t] += O[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int l = max({i, 0}); l < N; ++l) {

for (int j = 0; j < N; ++j) {

for (int s = max({j, 0}); s < min({(i) + 1, N}); ++s) {

for (int k = 0; k < N; ++k) {

for (int t = max({l, 0}); t < min({(k) + 1, N}); ++t) {







O[i][j][k][l][s][t] += O[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int j = 0; j < N; ++j) {

for (int s = max({j, 0}); s < min({(i) + 1, N}); ++s) {

for (int k = 0; k < N; ++k) {

for (int t = max({i, 0}); t < min({(k) + 1, N}); ++t) {

for (int l = max({k, 0}); l < N; ++l) {







O[i][j][k][l][s][t] += O[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int j = 0; j < N; ++j) {

for (int s = max({j, 0}); s < min({(i) + 1, N}); ++s) {

for (int k = 0; k < N; ++k) {

for (int l = 0; l < min({(k) + 1, N}); ++l) {

for (int t = max({i, 0}); t < min({(l) + 1, N}); ++t) {







O[i][j][k][l][s][t] += O[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int j = 0; j < N; ++j) {

for (int k = 0; k < N; ++k) {

for (int t = max({j, 0}); t < min({(k) + 1, N}); ++t) {

for (int l = max({k, 0}); l < N; ++l) {

for (int s = max({l, 0}); s < min({(i) + 1, N}); ++s) {







O[i][j][k][l][s][t] += O[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int s = max({i, 0}); s < N; ++s) {

for (int j = 0; j < N; ++j) {

for (int k = 0; k < N; ++k) {

for (int t = max({j, 0}); t < min({(k) + 1, N}); ++t) {

for (int l = max({k, 0}); l < min({(i) + 1, N}); ++l) {







O[i][j][k][l][s][t] += O[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int l = 0; l < min({(i) + 1, N}); ++l) {

for (int j = 0; j < N; ++j) {

for (int k = 0; k < N; ++k) {

for (int s = max({k, 0}); s < min({(l) + 1, N}); ++s) {

for (int t = max({j, 0}); t < min({(k) + 1, N}); ++t) {







O[i][j][k][l][s][t] += O[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int l = max({i, 0}); l < N; ++l) {

for (int j = 0; j < N; ++j) {

for (int k = 0; k < N; ++k) {

for (int s = max({k, 0}); s < min({(i) + 1, N}); ++s) {

for (int t = max({j, 0}); t < min({(k) + 1, N}); ++t) {







O[i][j][k][l][s][t] += O[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int l = max({i, 0}); l < N; ++l) {

for (int k = 0; k < min({(i) + 1, N}); ++k) {

for (int s = max({l, 0}); s < N; ++s) {

for (int j = 0; j < N; ++j) {

for (int t = max({j, 0}); t < min({(k) + 1, N}); ++t) {







O[i][j][k][l][s][t] += O[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int j = 0; j < N; ++j) {

for (int k = 0; k < min({(i) + 1, N}); ++k) {

for (int t = max({j, 0}); t < min({(k) + 1, N}); ++t) {

for (int l = 0; l < N; ++l) {

for (int s = max({i, 0}); s < min({(l) + 1, N}); ++s) {







O[i][j][k][l][s][t] += O[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int j = 0; j < N; ++j) {

for (int k = 0; k < N; ++k) {

for (int s = max({k, 0}); s < min({(i) + 1, N}); ++s) {

for (int l = 0; l < min({(k) + 1, N}); ++l) {

for (int t = max({j, 0}); t < min({(l) + 1, N}); ++t) {







O[i][j][k][l][s][t] += O[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int s = max({i, 0}); s < N; ++s) {

for (int k = 0; k < min({(i) + 1, N}); ++k) {

for (int l = 0; l < min({(k) + 1, N}); ++l) {

for (int j = 0; j < N; ++j) {

for (int t = max({j, 0}); t < min({(l) + 1, N}); ++t) {







O[i][j][k][l][s][t] += O[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int j = 0; j < N; ++j) {

for (int k = 0; k < min({(i) + 1, N}); ++k) {

for (int l = 0; l < N; ++l) {

for (int s = max({l, 0}); s < min({(k) + 1, N}); ++s) {

for (int t = max({j, 0}); t < min({(l) + 1, N}); ++t) {







O[i][j][k][l][s][t] += O[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int j = 0; j < N; ++j) {

for (int k = max({i, 0}); k < N; ++k) {

for (int l = 0; l < N; ++l) {

for (int s = max({l, 0}); s < min({(i) + 1, N}); ++s) {

for (int t = max({j, 0}); t < min({(l) + 1, N}); ++t) {







O[i][j][k][l][s][t] += O[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int l = 0; l < min({(i) + 1, N}); ++l) {

for (int k = max({i, 0}); k < N; ++k) {

for (int s = max({k, 0}); s < N; ++s) {

for (int j = 0; j < N; ++j) {

for (int t = max({j, 0}); t < min({(l) + 1, N}); ++t) {







O[i][j][k][l][s][t] += O[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int l = 0; l < min({(i) + 1, N}); ++l) {

for (int j = 0; j < N; ++j) {

for (int t = max({j, 0}); t < min({(l) + 1, N}); ++t) {

for (int k = 0; k < N; ++k) {

for (int s = max({i, 0}); s < min({(k) + 1, N}); ++s) {







O[i][j][k][l][s][t] += O[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int j = 0; j < N; ++j) {

for (int k = 0; k < N; ++k) {

for (int s = 0; s < min({(k) + 1, N}); ++s) {

for (int l = max({k, 0}); l < min({(i) + 1, N}); ++l) {

for (int t = max({j, 0}); t < min({(s) + 1, N}); ++t) {







O[i][j][k][l][s][t] += O[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int l = max({i, 0}); l < N; ++l) {

for (int k = 0; k < min({(i) + 1, N}); ++k) {

for (int s = 0; s < min({(k) + 1, N}); ++s) {

for (int j = 0; j < N; ++j) {

for (int t = max({j, 0}); t < min({(s) + 1, N}); ++t) {







O[i][j][k][l][s][t] += O[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int j = 0; j < N; ++j) {

for (int k = 0; k < min({(i) + 1, N}); ++k) {

for (int l = 0; l < min({(k) + 1, N}); ++l) {

for (int s = 0; s < min({(l) + 1, N}); ++s) {

for (int t = max({j, 0}); t < min({(s) + 1, N}); ++t) {







O[i][j][k][l][s][t] += O[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int l = 0; l < min({(i) + 1, N}); ++l) {

for (int k = max({i, 0}); k < N; ++k) {

for (int s = 0; s < min({(l) + 1, N}); ++s) {

for (int j = 0; j < N; ++j) {

for (int t = max({j, 0}); t < min({(s) + 1, N}); ++t) {







O[i][j][k][l][s][t] += O[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int s = 0; s < min({(i) + 1, N}); ++s) {

for (int k = max({i, 0}); k < N; ++k) {

for (int l = max({k, 0}); l < N; ++l) {

for (int j = 0; j < N; ++j) {

for (int t = max({j, 0}); t < min({(s) + 1, N}); ++t) {







O[i][j][k][l][s][t] += O[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int s = 0; s < min({(i) + 1, N}); ++s) {

for (int j = 0; j < N; ++j) {

for (int t = max({j, 0}); t < min({(s) + 1, N}); ++t) {

for (int k = 0; k < N; ++k) {

for (int l = max({i, 0}); l < min({(k) + 1, N}); ++l) {







O[i][j][k][l][s][t] += O[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int j = 0; j < N; ++j) {

for (int k = max({i, 0}); k < N; ++k) {

for (int t = max({j, 0}); t < min({(i) + 1, N}); ++t) {

for (int l = max({k, 0}); l < N; ++l) {

for (int s = max({l, 0}); s < N; ++s) {







O[i][j][k][l][s][t] += O[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int j = 0; j < N; ++j) {

for (int k = max({i, 0}); k < N; ++k) {

for (int t = max({j, 0}); t < min({(i) + 1, N}); ++t) {

for (int l = 0; l < N; ++l) {

for (int s = max({k, 0}); s < min({(l) + 1, N}); ++s) {







O[i][j][k][l][s][t] += O[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int j = 0; j < N; ++j) {

for (int t = max({j, 0}); t < min({(i) + 1, N}); ++t) {

for (int k = 0; k < N; ++k) {

for (int s = max({k, 0}); s < N; ++s) {

for (int l = max({i, 0}); l < min({(k) + 1, N}); ++l) {







O[i][j][k][l][s][t] += O[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int l = max({i, 0}); l < N; ++l) {

for (int j = 0; j < N; ++j) {

for (int t = max({j, 0}); t < min({(i) + 1, N}); ++t) {

for (int k = 0; k < N; ++k) {

for (int s = max({l, 0}); s < min({(k) + 1, N}); ++s) {







O[i][j][k][l][s][t] += O[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int j = 0; j < N; ++j) {

for (int t = max({j, 0}); t < min({(i) + 1, N}); ++t) {

for (int k = 0; k < N; ++k) {

for (int s = max({i, 0}); s < min({(k) + 1, N}); ++s) {

for (int l = max({k, 0}); l < N; ++l) {







O[i][j][k][l][s][t] += O[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int j = 0; j < N; ++j) {

for (int t = max({j, 0}); t < min({(i) + 1, N}); ++t) {

for (int k = 0; k < N; ++k) {

for (int l = 0; l < min({(k) + 1, N}); ++l) {

for (int s = max({i, 0}); s < min({(l) + 1, N}); ++s) {







O[i][j][k][l][s][t] += O[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int j = 0; j < min({(i) + 1, N}); ++j) {

for (int k = max({i, 0}); k < N; ++k) {

for (int l = max({k, 0}); l < N; ++l) {

for (int s = max({l, 0}); s < N; ++s) {

for (int t = max({s, 0}); t < N; ++t) {







O[i][j][k][l][s][t] += O[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int j = 0; j < min({(i) + 1, N}); ++j) {

for (int k = max({i, 0}); k < N; ++k) {

for (int l = max({k, 0}); l < N; ++l) {

for (int s = 0; s < N; ++s) {

for (int t = max({l, 0}); t < min({(s) + 1, N}); ++t) {







O[i][j][k][l][s][t] += O[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int j = 0; j < min({(i) + 1, N}); ++j) {

for (int k = max({i, 0}); k < N; ++k) {

for (int l = 0; l < N; ++l) {

for (int s = max({k, 0}); s < min({(l) + 1, N}); ++s) {

for (int t = max({l, 0}); t < N; ++t) {







O[i][j][k][l][s][t] += O[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int j = 0; j < min({(i) + 1, N}); ++j) {

for (int k = max({i, 0}); k < N; ++k) {

for (int s = max({k, 0}); s < N; ++s) {

for (int l = 0; l < N; ++l) {

for (int t = max({s, 0}); t < min({(l) + 1, N}); ++t) {







O[i][j][k][l][s][t] += O[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int j = 0; j < min({(i) + 1, N}); ++j) {

for (int k = max({i, 0}); k < N; ++k) {

for (int l = 0; l < N; ++l) {

for (int s = max({l, 0}); s < N; ++s) {

for (int t = max({k, 0}); t < min({(l) + 1, N}); ++t) {







O[i][j][k][l][s][t] += O[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int j = 0; j < min({(i) + 1, N}); ++j) {

for (int k = max({i, 0}); k < N; ++k) {

for (int l = 0; l < N; ++l) {

for (int s = 0; s < min({(l) + 1, N}); ++s) {

for (int t = max({k, 0}); t < min({(s) + 1, N}); ++t) {







O[i][j][k][l][s][t] += O[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int j = 0; j < min({(i) + 1, N}); ++j) {

for (int k = 0; k < N; ++k) {

for (int s = max({k, 0}); s < N; ++s) {

for (int l = max({i, 0}); l < min({(k) + 1, N}); ++l) {

for (int t = max({s, 0}); t < N; ++t) {







O[i][j][k][l][s][t] += O[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int j = 0; j < min({(i) + 1, N}); ++j) {

for (int k = 0; k < N; ++k) {

for (int l = max({i, 0}); l < min({(k) + 1, N}); ++l) {

for (int s = 0; s < N; ++s) {

for (int t = max({k, 0}); t < min({(s) + 1, N}); ++t) {







O[i][j][k][l][s][t] += O[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int l = max({i, 0}); l < N; ++l) {

for (int j = 0; j < min({(i) + 1, N}); ++j) {

for (int k = 0; k < N; ++k) {

for (int s = max({l, 0}); s < min({(k) + 1, N}); ++s) {

for (int t = max({k, 0}); t < N; ++t) {







O[i][j][k][l][s][t] += O[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int l = max({i, 0}); l < N; ++l) {

for (int j = 0; j < min({(i) + 1, N}); ++j) {

for (int s = max({l, 0}); s < N; ++s) {

for (int k = 0; k < N; ++k) {

for (int t = max({s, 0}); t < min({(k) + 1, N}); ++t) {







O[i][j][k][l][s][t] += O[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int l = max({i, 0}); l < N; ++l) {

for (int j = 0; j < min({(i) + 1, N}); ++j) {

for (int k = 0; k < N; ++k) {

for (int s = max({k, 0}); s < N; ++s) {

for (int t = max({l, 0}); t < min({(k) + 1, N}); ++t) {







O[i][j][k][l][s][t] += O[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int l = max({i, 0}); l < N; ++l) {

for (int j = 0; j < min({(i) + 1, N}); ++j) {

for (int k = 0; k < N; ++k) {

for (int s = 0; s < min({(k) + 1, N}); ++s) {

for (int t = max({l, 0}); t < min({(s) + 1, N}); ++t) {







O[i][j][k][l][s][t] += O[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int j = 0; j < min({(i) + 1, N}); ++j) {

for (int k = 0; k < N; ++k) {

for (int s = max({i, 0}); s < min({(k) + 1, N}); ++s) {

for (int l = max({k, 0}); l < N; ++l) {

for (int t = max({l, 0}); t < N; ++t) {







O[i][j][k][l][s][t] += O[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int j = 0; j < min({(i) + 1, N}); ++j) {

for (int k = 0; k < N; ++k) {

for (int s = max({i, 0}); s < min({(k) + 1, N}); ++s) {

for (int l = 0; l < N; ++l) {

for (int t = max({k, 0}); t < min({(l) + 1, N}); ++t) {







O[i][j][k][l][s][t] += O[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int j = 0; j < min({(i) + 1, N}); ++j) {

for (int k = 0; k < N; ++k) {

for (int t = max({k, 0}); t < N; ++t) {

for (int l = 0; l < min({(k) + 1, N}); ++l) {

for (int s = max({i, 0}); s < min({(l) + 1, N}); ++s) {







O[i][j][k][l][s][t] += O[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int j = 0; j < min({(i) + 1, N}); ++j) {

for (int k = 0; k < N; ++k) {

for (int l = 0; l < N; ++l) {

for (int s = max({i, 0}); s < min({(l) + 1, N}); ++s) {

for (int t = max({l, 0}); t < min({(k) + 1, N}); ++t) {







O[i][j][k][l][s][t] += O[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int s = max({i, 0}); s < N; ++s) {

for (int j = 0; j < min({(i) + 1, N}); ++j) {

for (int k = 0; k < N; ++k) {

for (int t = max({s, 0}); t < min({(k) + 1, N}); ++t) {

for (int l = max({k, 0}); l < N; ++l) {







O[i][j][k][l][s][t] += O[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int s = max({i, 0}); s < N; ++s) {

for (int j = 0; j < min({(i) + 1, N}); ++j) {

for (int k = 0; k < N; ++k) {

for (int l = 0; l < min({(k) + 1, N}); ++l) {

for (int t = max({s, 0}); t < min({(l) + 1, N}); ++t) {







O[i][j][k][l][s][t] += O[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int j = 0; j < min({(i) + 1, N}); ++j) {

for (int k = 0; k < N; ++k) {

for (int t = max({i, 0}); t < min({(k) + 1, N}); ++t) {

for (int l = max({k, 0}); l < N; ++l) {

for (int s = max({l, 0}); s < N; ++s) {







O[i][j][k][l][s][t] += O[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int j = 0; j < min({(i) + 1, N}); ++j) {

for (int k = 0; k < N; ++k) {

for (int t = max({i, 0}); t < min({(k) + 1, N}); ++t) {

for (int l = 0; l < N; ++l) {

for (int s = max({k, 0}); s < min({(l) + 1, N}); ++s) {







O[i][j][k][l][s][t] += O[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int j = 0; j < min({(i) + 1, N}); ++j) {

for (int k = 0; k < N; ++k) {

for (int s = max({k, 0}); s < N; ++s) {

for (int l = 0; l < min({(k) + 1, N}); ++l) {

for (int t = max({i, 0}); t < min({(l) + 1, N}); ++t) {







O[i][j][k][l][s][t] += O[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int j = 0; j < min({(i) + 1, N}); ++j) {

for (int k = 0; k < N; ++k) {

for (int l = 0; l < N; ++l) {

for (int s = max({l, 0}); s < min({(k) + 1, N}); ++s) {

for (int t = max({i, 0}); t < min({(l) + 1, N}); ++t) {







O[i][j][k][l][s][t] += O[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int j = 0; j < min({(i) + 1, N}); ++j) {

for (int k = 0; k < N; ++k) {

for (int s = 0; s < min({(k) + 1, N}); ++s) {

for (int l = max({k, 0}); l < N; ++l) {

for (int t = max({i, 0}); t < min({(s) + 1, N}); ++t) {







O[i][j][k][l][s][t] += O[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int j = 0; j < min({(i) + 1, N}); ++j) {

for (int k = 0; k < N; ++k) {

for (int l = 0; l < min({(k) + 1, N}); ++l) {

for (int s = 0; s < min({(l) + 1, N}); ++s) {

for (int t = max({i, 0}); t < min({(s) + 1, N}); ++t) {







O[i][j][k][l][s][t] += O[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int j = 0; j < N; ++j) {

for (int l = max({j, 0}); l < N; ++l) {

for (int k = 0; k < min({(j) + 1, N}); ++k) {

for (int s = max({l, 0}); s < N; ++s) {

for (int t = max({s, 0}); t < min({(i) + 1, N}); ++t) {







O[i][j][k][l][s][t] += O[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int t = max({i, 0}); t < N; ++t) {

for (int j = 0; j < N; ++j) {

for (int l = max({j, 0}); l < N; ++l) {

for (int k = 0; k < min({(j) + 1, N}); ++k) {

for (int s = max({l, 0}); s < min({(i) + 1, N}); ++s) {







O[i][j][k][l][s][t] += O[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int s = 0; s < min({(i) + 1, N}); ++s) {

for (int j = 0; j < N; ++j) {

for (int l = max({j, 0}); l < N; ++l) {

for (int k = 0; k < min({(j) + 1, N}); ++k) {

for (int t = max({l, 0}); t < min({(s) + 1, N}); ++t) {







O[i][j][k][l][s][t] += O[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int s = max({i, 0}); s < N; ++s) {

for (int j = 0; j < N; ++j) {

for (int l = max({j, 0}); l < N; ++l) {

for (int k = 0; k < min({(j) + 1, N}); ++k) {

for (int t = max({l, 0}); t < min({(i) + 1, N}); ++t) {







O[i][j][k][l][s][t] += O[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int s = max({i, 0}); s < N; ++s) {

for (int t = max({s, 0}); t < N; ++t) {

for (int j = 0; j < N; ++j) {

for (int l = max({j, 0}); l < min({(i) + 1, N}); ++l) {

for (int k = 0; k < min({(j) + 1, N}); ++k) {







O[i][j][k][l][s][t] += O[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int j = 0; j < N; ++j) {

for (int l = max({j, 0}); l < min({(i) + 1, N}); ++l) {

for (int k = 0; k < min({(j) + 1, N}); ++k) {

for (int s = 0; s < N; ++s) {

for (int t = max({i, 0}); t < min({(s) + 1, N}); ++t) {







O[i][j][k][l][s][t] += O[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int j = 0; j < N; ++j) {

for (int k = 0; k < min({(j) + 1, N}); ++k) {

for (int l = 0; l < N; ++l) {

for (int s = max({j, 0}); s < min({(l) + 1, N}); ++s) {

for (int t = max({l, 0}); t < min({(i) + 1, N}); ++t) {







O[i][j][k][l][s][t] += O[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int t = max({i, 0}); t < N; ++t) {

for (int l = 0; l < min({(i) + 1, N}); ++l) {

for (int j = 0; j < N; ++j) {

for (int s = max({j, 0}); s < min({(l) + 1, N}); ++s) {

for (int k = 0; k < min({(j) + 1, N}); ++k) {







O[i][j][k][l][s][t] += O[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int l = 0; l < min({(i) + 1, N}); ++l) {

for (int j = 0; j < N; ++j) {

for (int s = max({j, 0}); s < N; ++s) {

for (int k = 0; k < min({(j) + 1, N}); ++k) {

for (int t = max({s, 0}); t < min({(l) + 1, N}); ++t) {







O[i][j][k][l][s][t] += O[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int l = max({i, 0}); l < N; ++l) {

for (int j = 0; j < N; ++j) {

for (int s = max({j, 0}); s < N; ++s) {

for (int k = 0; k < min({(j) + 1, N}); ++k) {

for (int t = max({s, 0}); t < min({(i) + 1, N}); ++t) {







O[i][j][k][l][s][t] += O[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int l = max({i, 0}); l < N; ++l) {

for (int t = max({l, 0}); t < N; ++t) {

for (int j = 0; j < N; ++j) {

for (int s = max({j, 0}); s < min({(i) + 1, N}); ++s) {

for (int k = 0; k < min({(j) + 1, N}); ++k) {







O[i][j][k][l][s][t] += O[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int j = 0; j < N; ++j) {

for (int s = max({j, 0}); s < min({(i) + 1, N}); ++s) {

for (int k = 0; k < min({(j) + 1, N}); ++k) {

for (int l = 0; l < N; ++l) {

for (int t = max({i, 0}); t < min({(l) + 1, N}); ++t) {







O[i][j][k][l][s][t] += O[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int j = 0; j < N; ++j) {

for (int k = 0; k < min({(j) + 1, N}); ++k) {

for (int l = 0; l < N; ++l) {

for (int s = max({l, 0}); s < min({(i) + 1, N}); ++s) {

for (int t = max({j, 0}); t < min({(l) + 1, N}); ++t) {







O[i][j][k][l][s][t] += O[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int s = max({i, 0}); s < N; ++s) {

for (int l = 0; l < min({(i) + 1, N}); ++l) {

for (int j = 0; j < N; ++j) {

for (int t = max({j, 0}); t < min({(l) + 1, N}); ++t) {

for (int k = 0; k < min({(j) + 1, N}); ++k) {







O[i][j][k][l][s][t] += O[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int l = 0; l < min({(i) + 1, N}); ++l) {

for (int s = 0; s < min({(l) + 1, N}); ++s) {

for (int j = 0; j < N; ++j) {

for (int t = max({j, 0}); t < min({(s) + 1, N}); ++t) {

for (int k = 0; k < min({(j) + 1, N}); ++k) {







O[i][j][k][l][s][t] += O[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int s = 0; s < min({(i) + 1, N}); ++s) {

for (int l = max({i, 0}); l < N; ++l) {

for (int j = 0; j < N; ++j) {

for (int t = max({j, 0}); t < min({(s) + 1, N}); ++t) {

for (int k = 0; k < min({(j) + 1, N}); ++k) {







O[i][j][k][l][s][t] += O[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int l = max({i, 0}); l < N; ++l) {

for (int s = max({l, 0}); s < N; ++s) {

for (int j = 0; j < N; ++j) {

for (int t = max({j, 0}); t < min({(i) + 1, N}); ++t) {

for (int k = 0; k < min({(j) + 1, N}); ++k) {







O[i][j][k][l][s][t] += O[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int j = 0; j < N; ++j) {

for (int t = max({j, 0}); t < min({(i) + 1, N}); ++t) {

for (int k = 0; k < min({(j) + 1, N}); ++k) {

for (int l = 0; l < N; ++l) {

for (int s = max({i, 0}); s < min({(l) + 1, N}); ++s) {







O[i][j][k][l][s][t] += O[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int l = max({i, 0}); l < N; ++l) {

for (int j = 0; j < min({(i) + 1, N}); ++j) {

for (int s = max({l, 0}); s < N; ++s) {

for (int k = 0; k < min({(j) + 1, N}); ++k) {

for (int t = max({s, 0}); t < N; ++t) {







O[i][j][k][l][s][t] += O[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int l = max({i, 0}); l < N; ++l) {

for (int j = 0; j < min({(i) + 1, N}); ++j) {

for (int k = 0; k < min({(j) + 1, N}); ++k) {

for (int s = 0; s < N; ++s) {

for (int t = max({l, 0}); t < min({(s) + 1, N}); ++t) {







O[i][j][k][l][s][t] += O[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int j = 0; j < min({(i) + 1, N}); ++j) {

for (int k = 0; k < min({(j) + 1, N}); ++k) {

for (int l = 0; l < N; ++l) {

for (int s = max({i, 0}); s < min({(l) + 1, N}); ++s) {

for (int t = max({l, 0}); t < N; ++t) {







O[i][j][k][l][s][t] += O[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int s = max({i, 0}); s < N; ++s) {

for (int j = 0; j < min({(i) + 1, N}); ++j) {

for (int k = 0; k < min({(j) + 1, N}); ++k) {

for (int l = 0; l < N; ++l) {

for (int t = max({s, 0}); t < min({(l) + 1, N}); ++t) {







O[i][j][k][l][s][t] += O[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int j = 0; j < min({(i) + 1, N}); ++j) {

for (int k = 0; k < min({(j) + 1, N}); ++k) {

for (int l = 0; l < N; ++l) {

for (int s = max({l, 0}); s < N; ++s) {

for (int t = max({i, 0}); t < min({(l) + 1, N}); ++t) {







O[i][j][k][l][s][t] += O[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int j = 0; j < min({(i) + 1, N}); ++j) {

for (int k = 0; k < min({(j) + 1, N}); ++k) {

for (int l = 0; l < N; ++l) {

for (int s = 0; s < min({(l) + 1, N}); ++s) {

for (int t = max({i, 0}); t < min({(s) + 1, N}); ++t) {







O[i][j][k][l][s][t] += O[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int j = 0; j < N; ++j) {

for (int s = max({j, 0}); s < N; ++s) {

for (int t = max({s, 0}); t < min({(i) + 1, N}); ++t) {

for (int k = 0; k < N; ++k) {

for (int l = max({k, 0}); l < min({(j) + 1, N}); ++l) {







O[i][j][k][l][s][t] += O[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int t = max({i, 0}); t < N; ++t) {

for (int j = 0; j < N; ++j) {

for (int s = max({j, 0}); s < min({(i) + 1, N}); ++s) {

for (int k = 0; k < N; ++k) {

for (int l = max({k, 0}); l < min({(j) + 1, N}); ++l) {







O[i][j][k][l][s][t] += O[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int s = 0; s < min({(i) + 1, N}); ++s) {

for (int j = 0; j < N; ++j) {

for (int t = max({j, 0}); t < min({(s) + 1, N}); ++t) {

for (int k = 0; k < N; ++k) {

for (int l = max({k, 0}); l < min({(j) + 1, N}); ++l) {







O[i][j][k][l][s][t] += O[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int s = max({i, 0}); s < N; ++s) {

for (int j = 0; j < N; ++j) {

for (int t = max({j, 0}); t < min({(i) + 1, N}); ++t) {

for (int k = 0; k < N; ++k) {

for (int l = max({k, 0}); l < min({(j) + 1, N}); ++l) {







O[i][j][k][l][s][t] += O[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int s = max({i, 0}); s < N; ++s) {

for (int j = 0; j < min({(i) + 1, N}); ++j) {

for (int t = max({s, 0}); t < N; ++t) {

for (int k = 0; k < N; ++k) {

for (int l = max({k, 0}); l < min({(j) + 1, N}); ++l) {







O[i][j][k][l][s][t] += O[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int j = 0; j < min({(i) + 1, N}); ++j) {

for (int k = 0; k < N; ++k) {

for (int l = max({k, 0}); l < min({(j) + 1, N}); ++l) {

for (int s = 0; s < N; ++s) {

for (int t = max({i, 0}); t < min({(s) + 1, N}); ++t) {







O[i][j][k][l][s][t] += O[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int j = 0; j < N; ++j) {

for (int t = max({j, 0}); t < min({(i) + 1, N}); ++t) {

for (int k = 0; k < N; ++k) {

for (int l = max({k, 0}); l < N; ++l) {

for (int s = max({l, 0}); s < min({(j) + 1, N}); ++s) {







O[i][j][k][l][s][t] += O[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int t = max({i, 0}); t < N; ++t) {

for (int j = 0; j < min({(i) + 1, N}); ++j) {

for (int k = 0; k < N; ++k) {

for (int l = max({k, 0}); l < N; ++l) {

for (int s = max({l, 0}); s < min({(j) + 1, N}); ++s) {







O[i][j][k][l][s][t] += O[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int j = 0; j < min({(i) + 1, N}); ++j) {

for (int k = 0; k < N; ++k) {

for (int l = max({k, 0}); l < N; ++l) {

for (int s = max({l, 0}); s < N; ++s) {

for (int t = max({s, 0}); t < min({(j) + 1, N}); ++t) {







O[i][j][k][l][s][t] += O[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int j = max({i, 0}); j < N; ++j) {

for (int k = 0; k < N; ++k) {

for (int l = max({k, 0}); l < N; ++l) {

for (int s = max({l, 0}); s < N; ++s) {

for (int t = max({s, 0}); t < min({(i) + 1, N}); ++t) {







O[i][j][k][l][s][t] += O[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int j = max({i, 0}); j < N; ++j) {

for (int t = max({j, 0}); t < N; ++t) {

for (int k = 0; k < N; ++k) {

for (int l = max({k, 0}); l < N; ++l) {

for (int s = max({l, 0}); s < min({(i) + 1, N}); ++s) {







O[i][j][k][l][s][t] += O[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int j = 0; j < N; ++j) {

for (int t = max({i, 0}); t < min({(j) + 1, N}); ++t) {

for (int k = 0; k < N; ++k) {

for (int l = max({k, 0}); l < N; ++l) {

for (int s = max({l, 0}); s < min({(i) + 1, N}); ++s) {







O[i][j][k][l][s][t] += O[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int j = 0; j < N; ++j) {

for (int s = max({j, 0}); s < min({(i) + 1, N}); ++s) {

for (int k = 0; k < N; ++k) {

for (int l = max({k, 0}); l < N; ++l) {

for (int t = max({l, 0}); t < min({(j) + 1, N}); ++t) {







O[i][j][k][l][s][t] += O[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int s = max({i, 0}); s < N; ++s) {

for (int j = 0; j < min({(i) + 1, N}); ++j) {

for (int k = 0; k < N; ++k) {

for (int l = max({k, 0}); l < N; ++l) {

for (int t = max({l, 0}); t < min({(j) + 1, N}); ++t) {







O[i][j][k][l][s][t] += O[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int j = 0; j < min({(i) + 1, N}); ++j) {

for (int s = 0; s < min({(j) + 1, N}); ++s) {

for (int k = 0; k < N; ++k) {

for (int l = max({k, 0}); l < N; ++l) {

for (int t = max({l, 0}); t < min({(s) + 1, N}); ++t) {







O[i][j][k][l][s][t] += O[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int s = 0; s < min({(i) + 1, N}); ++s) {

for (int j = max({i, 0}); j < N; ++j) {

for (int k = 0; k < N; ++k) {

for (int l = max({k, 0}); l < N; ++l) {

for (int t = max({l, 0}); t < min({(s) + 1, N}); ++t) {







O[i][j][k][l][s][t] += O[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int j = max({i, 0}); j < N; ++j) {

for (int s = max({j, 0}); s < N; ++s) {

for (int k = 0; k < N; ++k) {

for (int l = max({k, 0}); l < N; ++l) {

for (int t = max({l, 0}); t < min({(i) + 1, N}); ++t) {







O[i][j][k][l][s][t] += O[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int j = 0; j < N; ++j) {

for (int s = max({i, 0}); s < min({(j) + 1, N}); ++s) {

for (int k = 0; k < N; ++k) {

for (int l = max({k, 0}); l < N; ++l) {

for (int t = max({l, 0}); t < min({(i) + 1, N}); ++t) {







O[i][j][k][l][s][t] += O[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int j = max({i, 0}); j < N; ++j) {

for (int s = max({j, 0}); s < N; ++s) {

for (int t = max({s, 0}); t < N; ++t) {

for (int k = 0; k < N; ++k) {

for (int l = max({k, 0}); l < min({(i) + 1, N}); ++l) {







O[i][j][k][l][s][t] += O[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int j = max({i, 0}); j < N; ++j) {

for (int k = 0; k < N; ++k) {

for (int l = max({k, 0}); l < min({(i) + 1, N}); ++l) {

for (int s = 0; s < N; ++s) {

for (int t = max({j, 0}); t < min({(s) + 1, N}); ++t) {







O[i][j][k][l][s][t] += O[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int j = 0; j < N; ++j) {

for (int s = max({i, 0}); s < min({(j) + 1, N}); ++s) {

for (int t = max({j, 0}); t < N; ++t) {

for (int k = 0; k < N; ++k) {

for (int l = max({k, 0}); l < min({(i) + 1, N}); ++l) {







O[i][j][k][l][s][t] += O[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int s = max({i, 0}); s < N; ++s) {

for (int j = 0; j < N; ++j) {

for (int t = max({s, 0}); t < min({(j) + 1, N}); ++t) {

for (int k = 0; k < N; ++k) {

for (int l = max({k, 0}); l < min({(i) + 1, N}); ++l) {







O[i][j][k][l][s][t] += O[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int j = 0; j < N; ++j) {

for (int s = max({j, 0}); s < N; ++s) {

for (int t = max({i, 0}); t < min({(j) + 1, N}); ++t) {

for (int k = 0; k < N; ++k) {

for (int l = max({k, 0}); l < min({(i) + 1, N}); ++l) {







O[i][j][k][l][s][t] += O[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int j = 0; j < N; ++j) {

for (int s = 0; s < min({(j) + 1, N}); ++s) {

for (int t = max({i, 0}); t < min({(s) + 1, N}); ++t) {

for (int k = 0; k < N; ++k) {

for (int l = max({k, 0}); l < min({(i) + 1, N}); ++l) {







O[i][j][k][l][s][t] += O[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int j = 0; j < N; ++j) {

for (int l = max({j, 0}); l < N; ++l) {

for (int t = max({l, 0}); t < min({(i) + 1, N}); ++t) {

for (int k = 0; k < N; ++k) {

for (int s = max({k, 0}); s < min({(j) + 1, N}); ++s) {







O[i][j][k][l][s][t] += O[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int t = max({i, 0}); t < N; ++t) {

for (int j = 0; j < N; ++j) {

for (int l = max({j, 0}); l < min({(i) + 1, N}); ++l) {

for (int k = 0; k < N; ++k) {

for (int s = max({k, 0}); s < min({(j) + 1, N}); ++s) {







O[i][j][k][l][s][t] += O[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int l = 0; l < min({(i) + 1, N}); ++l) {

for (int j = 0; j < N; ++j) {

for (int t = max({j, 0}); t < min({(l) + 1, N}); ++t) {

for (int k = 0; k < N; ++k) {

for (int s = max({k, 0}); s < min({(j) + 1, N}); ++s) {







O[i][j][k][l][s][t] += O[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int l = max({i, 0}); l < N; ++l) {

for (int j = 0; j < N; ++j) {

for (int t = max({j, 0}); t < min({(i) + 1, N}); ++t) {

for (int k = 0; k < N; ++k) {

for (int s = max({k, 0}); s < min({(j) + 1, N}); ++s) {







O[i][j][k][l][s][t] += O[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int l = max({i, 0}); l < N; ++l) {

for (int j = 0; j < min({(i) + 1, N}); ++j) {

for (int t = max({l, 0}); t < N; ++t) {

for (int k = 0; k < N; ++k) {

for (int s = max({k, 0}); s < min({(j) + 1, N}); ++s) {







O[i][j][k][l][s][t] += O[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int j = 0; j < min({(i) + 1, N}); ++j) {

for (int k = 0; k < N; ++k) {

for (int s = max({k, 0}); s < min({(j) + 1, N}); ++s) {

for (int l = 0; l < N; ++l) {

for (int t = max({i, 0}); t < min({(l) + 1, N}); ++t) {







O[i][j][k][l][s][t] += O[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int j = 0; j < N; ++j) {

for (int t = max({j, 0}); t < min({(i) + 1, N}); ++t) {

for (int l = 0; l < min({(j) + 1, N}); ++l) {

for (int k = 0; k < N; ++k) {

for (int s = max({k, 0}); s < min({(l) + 1, N}); ++s) {







O[i][j][k][l][s][t] += O[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int t = max({i, 0}); t < N; ++t) {

for (int j = 0; j < min({(i) + 1, N}); ++j) {

for (int l = 0; l < min({(j) + 1, N}); ++l) {

for (int k = 0; k < N; ++k) {

for (int s = max({k, 0}); s < min({(l) + 1, N}); ++s) {







O[i][j][k][l][s][t] += O[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int j = 0; j < min({(i) + 1, N}); ++j) {

for (int k = 0; k < N; ++k) {

for (int l = 0; l < N; ++l) {

for (int s = max({k, 0}); s < min({(l) + 1, N}); ++s) {

for (int t = max({l, 0}); t < min({(j) + 1, N}); ++t) {







O[i][j][k][l][s][t] += O[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int j = max({i, 0}); j < N; ++j) {

for (int k = 0; k < N; ++k) {

for (int l = 0; l < N; ++l) {

for (int s = max({k, 0}); s < min({(l) + 1, N}); ++s) {

for (int t = max({l, 0}); t < min({(i) + 1, N}); ++t) {







O[i][j][k][l][s][t] += O[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int l = 0; l < min({(i) + 1, N}); ++l) {

for (int j = max({i, 0}); j < N; ++j) {

for (int t = max({j, 0}); t < N; ++t) {

for (int k = 0; k < N; ++k) {

for (int s = max({k, 0}); s < min({(l) + 1, N}); ++s) {







O[i][j][k][l][s][t] += O[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int l = 0; l < min({(i) + 1, N}); ++l) {

for (int j = 0; j < N; ++j) {

for (int t = max({i, 0}); t < min({(j) + 1, N}); ++t) {

for (int k = 0; k < N; ++k) {

for (int s = max({k, 0}); s < min({(l) + 1, N}); ++s) {







O[i][j][k][l][s][t] += O[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int j = 0; j < N; ++j) {

for (int l = max({j, 0}); l < min({(i) + 1, N}); ++l) {

for (int k = 0; k < N; ++k) {

for (int s = max({k, 0}); s < N; ++s) {

for (int t = max({s, 0}); t < min({(j) + 1, N}); ++t) {







O[i][j][k][l][s][t] += O[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int l = max({i, 0}); l < N; ++l) {

for (int j = 0; j < min({(i) + 1, N}); ++j) {

for (int k = 0; k < N; ++k) {

for (int s = max({k, 0}); s < N; ++s) {

for (int t = max({s, 0}); t < min({(j) + 1, N}); ++t) {







O[i][j][k][l][s][t] += O[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int j = 0; j < min({(i) + 1, N}); ++j) {

for (int l = 0; l < min({(j) + 1, N}); ++l) {

for (int k = 0; k < N; ++k) {

for (int s = max({k, 0}); s < N; ++s) {

for (int t = max({s, 0}); t < min({(l) + 1, N}); ++t) {







O[i][j][k][l][s][t] += O[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int l = 0; l < min({(i) + 1, N}); ++l) {

for (int j = max({i, 0}); j < N; ++j) {

for (int k = 0; k < N; ++k) {

for (int s = max({k, 0}); s < N; ++s) {

for (int t = max({s, 0}); t < min({(l) + 1, N}); ++t) {







O[i][j][k][l][s][t] += O[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int j = max({i, 0}); j < N; ++j) {

for (int l = max({j, 0}); l < N; ++l) {

for (int k = 0; k < N; ++k) {

for (int s = max({k, 0}); s < N; ++s) {

for (int t = max({s, 0}); t < min({(i) + 1, N}); ++t) {







O[i][j][k][l][s][t] += O[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int j = 0; j < N; ++j) {

for (int l = max({i, 0}); l < min({(j) + 1, N}); ++l) {

for (int k = 0; k < N; ++k) {

for (int s = max({k, 0}); s < N; ++s) {

for (int t = max({s, 0}); t < min({(i) + 1, N}); ++t) {







O[i][j][k][l][s][t] += O[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int j = max({i, 0}); j < N; ++j) {

for (int l = max({j, 0}); l < N; ++l) {

for (int t = max({l, 0}); t < N; ++t) {

for (int k = 0; k < N; ++k) {

for (int s = max({k, 0}); s < min({(i) + 1, N}); ++s) {







O[i][j][k][l][s][t] += O[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int j = max({i, 0}); j < N; ++j) {

for (int k = 0; k < N; ++k) {

for (int s = max({k, 0}); s < min({(i) + 1, N}); ++s) {

for (int l = 0; l < N; ++l) {

for (int t = max({j, 0}); t < min({(l) + 1, N}); ++t) {







O[i][j][k][l][s][t] += O[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int j = 0; j < N; ++j) {

for (int t = max({j, 0}); t < N; ++t) {

for (int l = max({i, 0}); l < min({(j) + 1, N}); ++l) {

for (int k = 0; k < N; ++k) {

for (int s = max({k, 0}); s < min({(i) + 1, N}); ++s) {







O[i][j][k][l][s][t] += O[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int l = max({i, 0}); l < N; ++l) {

for (int j = 0; j < N; ++j) {

for (int t = max({l, 0}); t < min({(j) + 1, N}); ++t) {

for (int k = 0; k < N; ++k) {

for (int s = max({k, 0}); s < min({(i) + 1, N}); ++s) {







O[i][j][k][l][s][t] += O[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int j = 0; j < N; ++j) {

for (int t = max({i, 0}); t < min({(j) + 1, N}); ++t) {

for (int l = max({j, 0}); l < N; ++l) {

for (int k = 0; k < N; ++k) {

for (int s = max({k, 0}); s < min({(i) + 1, N}); ++s) {







O[i][j][k][l][s][t] += O[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int j = 0; j < N; ++j) {

for (int l = 0; l < min({(j) + 1, N}); ++l) {

for (int t = max({i, 0}); t < min({(l) + 1, N}); ++t) {

for (int k = 0; k < N; ++k) {

for (int s = max({k, 0}); s < min({(i) + 1, N}); ++s) {







O[i][j][k][l][s][t] += O[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int j = 0; j < N; ++j) {

for (int l = max({j, 0}); l < N; ++l) {

for (int s = max({l, 0}); s < min({(i) + 1, N}); ++s) {

for (int k = 0; k < N; ++k) {

for (int t = max({k, 0}); t < min({(j) + 1, N}); ++t) {







O[i][j][k][l][s][t] += O[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int s = max({i, 0}); s < N; ++s) {

for (int j = 0; j < N; ++j) {

for (int l = max({j, 0}); l < min({(i) + 1, N}); ++l) {

for (int k = 0; k < N; ++k) {

for (int t = max({k, 0}); t < min({(j) + 1, N}); ++t) {







O[i][j][k][l][s][t] += O[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int l = 0; l < min({(i) + 1, N}); ++l) {

for (int j = 0; j < N; ++j) {

for (int s = max({j, 0}); s < min({(l) + 1, N}); ++s) {

for (int k = 0; k < N; ++k) {

for (int t = max({k, 0}); t < min({(j) + 1, N}); ++t) {







O[i][j][k][l][s][t] += O[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int l = max({i, 0}); l < N; ++l) {

for (int j = 0; j < N; ++j) {

for (int s = max({j, 0}); s < min({(i) + 1, N}); ++s) {

for (int k = 0; k < N; ++k) {

for (int t = max({k, 0}); t < min({(j) + 1, N}); ++t) {







O[i][j][k][l][s][t] += O[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int l = max({i, 0}); l < N; ++l) {

for (int j = 0; j < min({(i) + 1, N}); ++j) {

for (int s = max({l, 0}); s < N; ++s) {

for (int k = 0; k < N; ++k) {

for (int t = max({k, 0}); t < min({(j) + 1, N}); ++t) {







O[i][j][k][l][s][t] += O[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int j = 0; j < min({(i) + 1, N}); ++j) {

for (int k = 0; k < N; ++k) {

for (int t = max({k, 0}); t < min({(j) + 1, N}); ++t) {

for (int l = 0; l < N; ++l) {

for (int s = max({i, 0}); s < min({(l) + 1, N}); ++s) {







O[i][j][k][l][s][t] += O[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int j = 0; j < N; ++j) {

for (int s = max({j, 0}); s < min({(i) + 1, N}); ++s) {

for (int l = 0; l < min({(j) + 1, N}); ++l) {

for (int k = 0; k < N; ++k) {

for (int t = max({k, 0}); t < min({(l) + 1, N}); ++t) {







O[i][j][k][l][s][t] += O[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int s = max({i, 0}); s < N; ++s) {

for (int j = 0; j < min({(i) + 1, N}); ++j) {

for (int l = 0; l < min({(j) + 1, N}); ++l) {

for (int k = 0; k < N; ++k) {

for (int t = max({k, 0}); t < min({(l) + 1, N}); ++t) {







O[i][j][k][l][s][t] += O[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int j = 0; j < min({(i) + 1, N}); ++j) {

for (int k = 0; k < N; ++k) {

for (int l = 0; l < N; ++l) {

for (int s = max({l, 0}); s < min({(j) + 1, N}); ++s) {

for (int t = max({k, 0}); t < min({(l) + 1, N}); ++t) {







O[i][j][k][l][s][t] += O[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int j = max({i, 0}); j < N; ++j) {

for (int k = 0; k < N; ++k) {

for (int l = 0; l < N; ++l) {

for (int s = max({l, 0}); s < min({(i) + 1, N}); ++s) {

for (int t = max({k, 0}); t < min({(l) + 1, N}); ++t) {







O[i][j][k][l][s][t] += O[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int l = 0; l < min({(i) + 1, N}); ++l) {

for (int j = max({i, 0}); j < N; ++j) {

for (int s = max({j, 0}); s < N; ++s) {

for (int k = 0; k < N; ++k) {

for (int t = max({k, 0}); t < min({(l) + 1, N}); ++t) {







O[i][j][k][l][s][t] += O[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int l = 0; l < min({(i) + 1, N}); ++l) {

for (int j = 0; j < N; ++j) {

for (int s = max({i, 0}); s < min({(j) + 1, N}); ++s) {

for (int k = 0; k < N; ++k) {

for (int t = max({k, 0}); t < min({(l) + 1, N}); ++t) {







O[i][j][k][l][s][t] += O[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int j = 0; j < N; ++j) {

for (int s = 0; s < min({(j) + 1, N}); ++s) {

for (int l = max({j, 0}); l < min({(i) + 1, N}); ++l) {

for (int k = 0; k < N; ++k) {

for (int t = max({k, 0}); t < min({(s) + 1, N}); ++t) {







O[i][j][k][l][s][t] += O[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int l = max({i, 0}); l < N; ++l) {

for (int j = 0; j < min({(i) + 1, N}); ++j) {

for (int s = 0; s < min({(j) + 1, N}); ++s) {

for (int k = 0; k < N; ++k) {

for (int t = max({k, 0}); t < min({(s) + 1, N}); ++t) {







O[i][j][k][l][s][t] += O[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int j = 0; j < min({(i) + 1, N}); ++j) {

for (int l = 0; l < min({(j) + 1, N}); ++l) {

for (int s = 0; s < min({(l) + 1, N}); ++s) {

for (int k = 0; k < N; ++k) {

for (int t = max({k, 0}); t < min({(s) + 1, N}); ++t) {







O[i][j][k][l][s][t] += O[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int l = 0; l < min({(i) + 1, N}); ++l) {

for (int j = max({i, 0}); j < N; ++j) {

for (int s = 0; s < min({(l) + 1, N}); ++s) {

for (int k = 0; k < N; ++k) {

for (int t = max({k, 0}); t < min({(s) + 1, N}); ++t) {







O[i][j][k][l][s][t] += O[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int s = 0; s < min({(i) + 1, N}); ++s) {

for (int j = max({i, 0}); j < N; ++j) {

for (int l = max({j, 0}); l < N; ++l) {

for (int k = 0; k < N; ++k) {

for (int t = max({k, 0}); t < min({(s) + 1, N}); ++t) {







O[i][j][k][l][s][t] += O[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int s = 0; s < min({(i) + 1, N}); ++s) {

for (int j = 0; j < N; ++j) {

for (int l = max({i, 0}); l < min({(j) + 1, N}); ++l) {

for (int k = 0; k < N; ++k) {

for (int t = max({k, 0}); t < min({(s) + 1, N}); ++t) {







O[i][j][k][l][s][t] += O[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int j = max({i, 0}); j < N; ++j) {

for (int l = max({j, 0}); l < N; ++l) {

for (int s = max({l, 0}); s < N; ++s) {

for (int k = 0; k < N; ++k) {

for (int t = max({k, 0}); t < min({(i) + 1, N}); ++t) {







O[i][j][k][l][s][t] += O[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int j = max({i, 0}); j < N; ++j) {

for (int k = 0; k < N; ++k) {

for (int t = max({k, 0}); t < min({(i) + 1, N}); ++t) {

for (int l = 0; l < N; ++l) {

for (int s = max({j, 0}); s < min({(l) + 1, N}); ++s) {







O[i][j][k][l][s][t] += O[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int j = 0; j < N; ++j) {

for (int s = max({j, 0}); s < N; ++s) {

for (int l = max({i, 0}); l < min({(j) + 1, N}); ++l) {

for (int k = 0; k < N; ++k) {

for (int t = max({k, 0}); t < min({(i) + 1, N}); ++t) {







O[i][j][k][l][s][t] += O[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int l = max({i, 0}); l < N; ++l) {

for (int j = 0; j < N; ++j) {

for (int s = max({l, 0}); s < min({(j) + 1, N}); ++s) {

for (int k = 0; k < N; ++k) {

for (int t = max({k, 0}); t < min({(i) + 1, N}); ++t) {







O[i][j][k][l][s][t] += O[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int j = 0; j < N; ++j) {

for (int s = max({i, 0}); s < min({(j) + 1, N}); ++s) {

for (int l = max({j, 0}); l < N; ++l) {

for (int k = 0; k < N; ++k) {

for (int t = max({k, 0}); t < min({(i) + 1, N}); ++t) {







O[i][j][k][l][s][t] += O[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int j = 0; j < N; ++j) {

for (int l = 0; l < min({(j) + 1, N}); ++l) {

for (int s = max({i, 0}); s < min({(l) + 1, N}); ++s) {

for (int k = 0; k < N; ++k) {

for (int t = max({k, 0}); t < min({(i) + 1, N}); ++t) {







O[i][j][k][l][s][t] += O[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int j = max({i, 0}); j < N; ++j) {

for (int k = 0; k < min({(i) + 1, N}); ++k) {

for (int l = max({j, 0}); l < N; ++l) {

for (int s = max({l, 0}); s < N; ++s) {

for (int t = max({s, 0}); t < N; ++t) {







O[i][j][k][l][s][t] += O[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int j = max({i, 0}); j < N; ++j) {

for (int k = 0; k < min({(i) + 1, N}); ++k) {

for (int l = max({j, 0}); l < N; ++l) {

for (int s = 0; s < N; ++s) {

for (int t = max({l, 0}); t < min({(s) + 1, N}); ++t) {







O[i][j][k][l][s][t] += O[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int j = max({i, 0}); j < N; ++j) {

for (int k = 0; k < min({(i) + 1, N}); ++k) {

for (int l = 0; l < N; ++l) {

for (int s = max({j, 0}); s < min({(l) + 1, N}); ++s) {

for (int t = max({l, 0}); t < N; ++t) {







O[i][j][k][l][s][t] += O[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int j = max({i, 0}); j < N; ++j) {

for (int k = 0; k < min({(i) + 1, N}); ++k) {

for (int s = max({j, 0}); s < N; ++s) {

for (int l = 0; l < N; ++l) {

for (int t = max({s, 0}); t < min({(l) + 1, N}); ++t) {







O[i][j][k][l][s][t] += O[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int j = max({i, 0}); j < N; ++j) {

for (int k = 0; k < min({(i) + 1, N}); ++k) {

for (int l = 0; l < N; ++l) {

for (int s = max({l, 0}); s < N; ++s) {

for (int t = max({j, 0}); t < min({(l) + 1, N}); ++t) {







O[i][j][k][l][s][t] += O[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int j = max({i, 0}); j < N; ++j) {

for (int k = 0; k < min({(i) + 1, N}); ++k) {

for (int l = 0; l < N; ++l) {

for (int s = 0; s < min({(l) + 1, N}); ++s) {

for (int t = max({j, 0}); t < min({(s) + 1, N}); ++t) {







O[i][j][k][l][s][t] += O[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int j = 0; j < N; ++j) {

for (int k = 0; k < min({(i) + 1, N}); ++k) {

for (int s = max({j, 0}); s < N; ++s) {

for (int l = max({i, 0}); l < min({(j) + 1, N}); ++l) {

for (int t = max({s, 0}); t < N; ++t) {







O[i][j][k][l][s][t] += O[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int j = 0; j < N; ++j) {

for (int k = 0; k < min({(i) + 1, N}); ++k) {

for (int l = max({i, 0}); l < min({(j) + 1, N}); ++l) {

for (int s = 0; s < N; ++s) {

for (int t = max({j, 0}); t < min({(s) + 1, N}); ++t) {







O[i][j][k][l][s][t] += O[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int l = max({i, 0}); l < N; ++l) {

for (int k = 0; k < min({(i) + 1, N}); ++k) {

for (int j = 0; j < N; ++j) {

for (int s = max({l, 0}); s < min({(j) + 1, N}); ++s) {

for (int t = max({j, 0}); t < N; ++t) {







O[i][j][k][l][s][t] += O[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int l = max({i, 0}); l < N; ++l) {

for (int k = 0; k < min({(i) + 1, N}); ++k) {

for (int s = max({l, 0}); s < N; ++s) {

for (int j = 0; j < N; ++j) {

for (int t = max({s, 0}); t < min({(j) + 1, N}); ++t) {







O[i][j][k][l][s][t] += O[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int l = max({i, 0}); l < N; ++l) {

for (int k = 0; k < min({(i) + 1, N}); ++k) {

for (int j = 0; j < N; ++j) {

for (int s = max({j, 0}); s < N; ++s) {

for (int t = max({l, 0}); t < min({(j) + 1, N}); ++t) {







O[i][j][k][l][s][t] += O[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int l = max({i, 0}); l < N; ++l) {

for (int k = 0; k < min({(i) + 1, N}); ++k) {

for (int j = 0; j < N; ++j) {

for (int s = 0; s < min({(j) + 1, N}); ++s) {

for (int t = max({l, 0}); t < min({(s) + 1, N}); ++t) {







O[i][j][k][l][s][t] += O[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int j = 0; j < N; ++j) {

for (int k = 0; k < min({(i) + 1, N}); ++k) {

for (int s = max({i, 0}); s < min({(j) + 1, N}); ++s) {

for (int l = max({j, 0}); l < N; ++l) {

for (int t = max({l, 0}); t < N; ++t) {







O[i][j][k][l][s][t] += O[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int j = 0; j < N; ++j) {

for (int k = 0; k < min({(i) + 1, N}); ++k) {

for (int s = max({i, 0}); s < min({(j) + 1, N}); ++s) {

for (int l = 0; l < N; ++l) {

for (int t = max({j, 0}); t < min({(l) + 1, N}); ++t) {







O[i][j][k][l][s][t] += O[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int j = 0; j < N; ++j) {

for (int k = 0; k < min({(i) + 1, N}); ++k) {

for (int t = max({j, 0}); t < N; ++t) {

for (int l = 0; l < min({(j) + 1, N}); ++l) {

for (int s = max({i, 0}); s < min({(l) + 1, N}); ++s) {







O[i][j][k][l][s][t] += O[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int j = 0; j < N; ++j) {

for (int k = 0; k < min({(i) + 1, N}); ++k) {

for (int l = 0; l < N; ++l) {

for (int s = max({i, 0}); s < min({(l) + 1, N}); ++s) {

for (int t = max({l, 0}); t < min({(j) + 1, N}); ++t) {







O[i][j][k][l][s][t] += O[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int s = max({i, 0}); s < N; ++s) {

for (int k = 0; k < min({(i) + 1, N}); ++k) {

for (int j = 0; j < N; ++j) {

for (int t = max({s, 0}); t < min({(j) + 1, N}); ++t) {

for (int l = max({j, 0}); l < N; ++l) {







O[i][j][k][l][s][t] += O[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int s = max({i, 0}); s < N; ++s) {

for (int k = 0; k < min({(i) + 1, N}); ++k) {

for (int j = 0; j < N; ++j) {

for (int l = 0; l < min({(j) + 1, N}); ++l) {

for (int t = max({s, 0}); t < min({(l) + 1, N}); ++t) {







O[i][j][k][l][s][t] += O[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int j = 0; j < N; ++j) {

for (int k = 0; k < min({(i) + 1, N}); ++k) {

for (int t = max({i, 0}); t < min({(j) + 1, N}); ++t) {

for (int l = max({j, 0}); l < N; ++l) {

for (int s = max({l, 0}); s < N; ++s) {







O[i][j][k][l][s][t] += O[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int j = 0; j < N; ++j) {

for (int k = 0; k < min({(i) + 1, N}); ++k) {

for (int t = max({i, 0}); t < min({(j) + 1, N}); ++t) {

for (int l = 0; l < N; ++l) {

for (int s = max({j, 0}); s < min({(l) + 1, N}); ++s) {







O[i][j][k][l][s][t] += O[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int j = 0; j < N; ++j) {

for (int k = 0; k < min({(i) + 1, N}); ++k) {

for (int s = max({j, 0}); s < N; ++s) {

for (int l = 0; l < min({(j) + 1, N}); ++l) {

for (int t = max({i, 0}); t < min({(l) + 1, N}); ++t) {







O[i][j][k][l][s][t] += O[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int j = 0; j < N; ++j) {

for (int k = 0; k < min({(i) + 1, N}); ++k) {

for (int l = 0; l < N; ++l) {

for (int s = max({l, 0}); s < min({(j) + 1, N}); ++s) {

for (int t = max({i, 0}); t < min({(l) + 1, N}); ++t) {







O[i][j][k][l][s][t] += O[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int j = 0; j < N; ++j) {

for (int k = 0; k < min({(i) + 1, N}); ++k) {

for (int s = 0; s < min({(j) + 1, N}); ++s) {

for (int l = max({j, 0}); l < N; ++l) {

for (int t = max({i, 0}); t < min({(s) + 1, N}); ++t) {







O[i][j][k][l][s][t] += O[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int j = 0; j < N; ++j) {

for (int k = 0; k < min({(i) + 1, N}); ++k) {

for (int l = 0; l < min({(j) + 1, N}); ++l) {

for (int s = 0; s < min({(l) + 1, N}); ++s) {

for (int t = max({i, 0}); t < min({(s) + 1, N}); ++t) {







O[i][j][k][l][s][t] += O[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int j = 0; j < N; ++j) {

for (int l = 0; l < min({(j) + 1, N}); ++l) {

for (int k = max({j, 0}); k < N; ++k) {

for (int s = max({k, 0}); s < N; ++s) {

for (int t = max({s, 0}); t < min({(i) + 1, N}); ++t) {







O[i][j][k][l][s][t] += O[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int t = max({i, 0}); t < N; ++t) {

for (int j = 0; j < N; ++j) {

for (int l = 0; l < min({(j) + 1, N}); ++l) {

for (int k = max({j, 0}); k < N; ++k) {

for (int s = max({k, 0}); s < min({(i) + 1, N}); ++s) {







O[i][j][k][l][s][t] += O[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int s = 0; s < min({(i) + 1, N}); ++s) {

for (int j = 0; j < N; ++j) {

for (int l = 0; l < min({(j) + 1, N}); ++l) {

for (int k = max({j, 0}); k < N; ++k) {

for (int t = max({k, 0}); t < min({(s) + 1, N}); ++t) {







O[i][j][k][l][s][t] += O[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int s = max({i, 0}); s < N; ++s) {

for (int j = 0; j < N; ++j) {

for (int l = 0; l < min({(j) + 1, N}); ++l) {

for (int k = max({j, 0}); k < N; ++k) {

for (int t = max({k, 0}); t < min({(i) + 1, N}); ++t) {







O[i][j][k][l][s][t] += O[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int s = max({i, 0}); s < N; ++s) {

for (int t = max({s, 0}); t < N; ++t) {

for (int j = 0; j < N; ++j) {

for (int l = 0; l < min({(j) + 1, N}); ++l) {

for (int k = max({j, 0}); k < min({(i) + 1, N}); ++k) {







O[i][j][k][l][s][t] += O[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int j = 0; j < N; ++j) {

for (int l = 0; l < min({(j) + 1, N}); ++l) {

for (int k = max({j, 0}); k < min({(i) + 1, N}); ++k) {

for (int s = 0; s < N; ++s) {

for (int t = max({i, 0}); t < min({(s) + 1, N}); ++t) {







O[i][j][k][l][s][t] += O[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int j = 0; j < N; ++j) {

for (int l = 0; l < min({(j) + 1, N}); ++l) {

for (int k = 0; k < N; ++k) {

for (int s = max({j, 0}); s < min({(k) + 1, N}); ++s) {

for (int t = max({k, 0}); t < min({(i) + 1, N}); ++t) {







O[i][j][k][l][s][t] += O[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int t = max({i, 0}); t < N; ++t) {

for (int k = 0; k < min({(i) + 1, N}); ++k) {

for (int j = 0; j < N; ++j) {

for (int s = max({j, 0}); s < min({(k) + 1, N}); ++s) {

for (int l = 0; l < min({(j) + 1, N}); ++l) {







O[i][j][k][l][s][t] += O[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int j = 0; j < N; ++j) {

for (int k = 0; k < min({(i) + 1, N}); ++k) {

for (int s = max({j, 0}); s < N; ++s) {

for (int l = 0; l < min({(j) + 1, N}); ++l) {

for (int t = max({s, 0}); t < min({(k) + 1, N}); ++t) {







O[i][j][k][l][s][t] += O[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int j = 0; j < N; ++j) {

for (int k = max({i, 0}); k < N; ++k) {

for (int s = max({j, 0}); s < N; ++s) {

for (int l = 0; l < min({(j) + 1, N}); ++l) {

for (int t = max({s, 0}); t < min({(i) + 1, N}); ++t) {







O[i][j][k][l][s][t] += O[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int j = 0; j < N; ++j) {

for (int k = max({i, 0}); k < N; ++k) {

for (int s = max({j, 0}); s < min({(i) + 1, N}); ++s) {

for (int l = 0; l < min({(j) + 1, N}); ++l) {

for (int t = max({k, 0}); t < N; ++t) {







O[i][j][k][l][s][t] += O[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int j = 0; j < N; ++j) {

for (int s = max({j, 0}); s < min({(i) + 1, N}); ++s) {

for (int l = 0; l < min({(j) + 1, N}); ++l) {

for (int k = 0; k < N; ++k) {

for (int t = max({i, 0}); t < min({(k) + 1, N}); ++t) {







O[i][j][k][l][s][t] += O[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int j = 0; j < N; ++j) {

for (int l = 0; l < min({(j) + 1, N}); ++l) {

for (int k = 0; k < N; ++k) {

for (int s = max({k, 0}); s < min({(i) + 1, N}); ++s) {

for (int t = max({j, 0}); t < min({(k) + 1, N}); ++t) {







O[i][j][k][l][s][t] += O[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int s = max({i, 0}); s < N; ++s) {

for (int k = 0; k < min({(i) + 1, N}); ++k) {

for (int j = 0; j < N; ++j) {

for (int t = max({j, 0}); t < min({(k) + 1, N}); ++t) {

for (int l = 0; l < min({(j) + 1, N}); ++l) {







O[i][j][k][l][s][t] += O[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int j = 0; j < N; ++j) {

for (int k = 0; k < min({(i) + 1, N}); ++k) {

for (int l = 0; l < min({(j) + 1, N}); ++l) {

for (int s = 0; s < min({(k) + 1, N}); ++s) {

for (int t = max({j, 0}); t < min({(s) + 1, N}); ++t) {







O[i][j][k][l][s][t] += O[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int s = 0; s < min({(i) + 1, N}); ++s) {

for (int k = max({i, 0}); k < N; ++k) {

for (int j = 0; j < N; ++j) {

for (int t = max({j, 0}); t < min({(s) + 1, N}); ++t) {

for (int l = 0; l < min({(j) + 1, N}); ++l) {







O[i][j][k][l][s][t] += O[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int j = 0; j < N; ++j) {

for (int k = max({i, 0}); k < N; ++k) {

for (int t = max({j, 0}); t < min({(i) + 1, N}); ++t) {

for (int l = 0; l < min({(j) + 1, N}); ++l) {

for (int s = max({k, 0}); s < N; ++s) {







O[i][j][k][l][s][t] += O[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int j = 0; j < N; ++j) {

for (int t = max({j, 0}); t < min({(i) + 1, N}); ++t) {

for (int l = 0; l < min({(j) + 1, N}); ++l) {

for (int k = 0; k < N; ++k) {

for (int s = max({i, 0}); s < min({(k) + 1, N}); ++s) {







O[i][j][k][l][s][t] += O[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int j = 0; j < min({(i) + 1, N}); ++j) {

for (int k = max({i, 0}); k < N; ++k) {

for (int l = 0; l < min({(j) + 1, N}); ++l) {

for (int s = max({k, 0}); s < N; ++s) {

for (int t = max({s, 0}); t < N; ++t) {







O[i][j][k][l][s][t] += O[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int j = 0; j < min({(i) + 1, N}); ++j) {

for (int k = max({i, 0}); k < N; ++k) {

for (int l = 0; l < min({(j) + 1, N}); ++l) {

for (int s = 0; s < N; ++s) {

for (int t = max({k, 0}); t < min({(s) + 1, N}); ++t) {







O[i][j][k][l][s][t] += O[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int j = 0; j < min({(i) + 1, N}); ++j) {

for (int l = 0; l < min({(j) + 1, N}); ++l) {

for (int k = 0; k < N; ++k) {

for (int s = max({i, 0}); s < min({(k) + 1, N}); ++s) {

for (int t = max({k, 0}); t < N; ++t) {







O[i][j][k][l][s][t] += O[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int s = max({i, 0}); s < N; ++s) {

for (int j = 0; j < min({(i) + 1, N}); ++j) {

for (int l = 0; l < min({(j) + 1, N}); ++l) {

for (int k = 0; k < N; ++k) {

for (int t = max({s, 0}); t < min({(k) + 1, N}); ++t) {







O[i][j][k][l][s][t] += O[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int j = 0; j < min({(i) + 1, N}); ++j) {

for (int l = 0; l < min({(j) + 1, N}); ++l) {

for (int k = 0; k < N; ++k) {

for (int s = max({k, 0}); s < N; ++s) {

for (int t = max({i, 0}); t < min({(k) + 1, N}); ++t) {







O[i][j][k][l][s][t] += O[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int j = 0; j < min({(i) + 1, N}); ++j) {

for (int l = 0; l < min({(j) + 1, N}); ++l) {

for (int k = 0; k < N; ++k) {

for (int s = 0; s < min({(k) + 1, N}); ++s) {

for (int t = max({i, 0}); t < min({(s) + 1, N}); ++t) {







O[i][j][k][l][s][t] += O[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int j = 0; j < N; ++j) {

for (int s = max({j, 0}); s < N; ++s) {

for (int k = 0; k < min({(j) + 1, N}); ++k) {

for (int t = max({s, 0}); t < min({(i) + 1, N}); ++t) {

for (int l = 0; l < min({(k) + 1, N}); ++l) {







O[i][j][k][l][s][t] += O[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int t = max({i, 0}); t < N; ++t) {

for (int j = 0; j < N; ++j) {

for (int s = max({j, 0}); s < min({(i) + 1, N}); ++s) {

for (int k = 0; k < min({(j) + 1, N}); ++k) {

for (int l = 0; l < min({(k) + 1, N}); ++l) {







O[i][j][k][l][s][t] += O[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int s = 0; s < min({(i) + 1, N}); ++s) {

for (int j = 0; j < N; ++j) {

for (int t = max({j, 0}); t < min({(s) + 1, N}); ++t) {

for (int k = 0; k < min({(j) + 1, N}); ++k) {

for (int l = 0; l < min({(k) + 1, N}); ++l) {







O[i][j][k][l][s][t] += O[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int s = max({i, 0}); s < N; ++s) {

for (int j = 0; j < N; ++j) {

for (int t = max({j, 0}); t < min({(i) + 1, N}); ++t) {

for (int k = 0; k < min({(j) + 1, N}); ++k) {

for (int l = 0; l < min({(k) + 1, N}); ++l) {







O[i][j][k][l][s][t] += O[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int s = max({i, 0}); s < N; ++s) {

for (int j = 0; j < min({(i) + 1, N}); ++j) {

for (int t = max({s, 0}); t < N; ++t) {

for (int k = 0; k < min({(j) + 1, N}); ++k) {

for (int l = 0; l < min({(k) + 1, N}); ++l) {







O[i][j][k][l][s][t] += O[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int j = 0; j < min({(i) + 1, N}); ++j) {

for (int k = 0; k < min({(j) + 1, N}); ++k) {

for (int l = 0; l < min({(k) + 1, N}); ++l) {

for (int s = 0; s < N; ++s) {

for (int t = max({i, 0}); t < min({(s) + 1, N}); ++t) {







O[i][j][k][l][s][t] += O[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int j = 0; j < N; ++j) {

for (int t = max({j, 0}); t < min({(i) + 1, N}); ++t) {

for (int k = 0; k < N; ++k) {

for (int s = max({k, 0}); s < min({(j) + 1, N}); ++s) {

for (int l = 0; l < min({(k) + 1, N}); ++l) {







O[i][j][k][l][s][t] += O[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int t = max({i, 0}); t < N; ++t) {

for (int j = 0; j < min({(i) + 1, N}); ++j) {

for (int k = 0; k < N; ++k) {

for (int s = max({k, 0}); s < min({(j) + 1, N}); ++s) {

for (int l = 0; l < min({(k) + 1, N}); ++l) {







O[i][j][k][l][s][t] += O[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int j = 0; j < min({(i) + 1, N}); ++j) {

for (int k = 0; k < N; ++k) {

for (int s = max({k, 0}); s < N; ++s) {

for (int l = 0; l < min({(k) + 1, N}); ++l) {

for (int t = max({s, 0}); t < min({(j) + 1, N}); ++t) {







O[i][j][k][l][s][t] += O[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int j = max({i, 0}); j < N; ++j) {

for (int k = 0; k < N; ++k) {

for (int s = max({k, 0}); s < N; ++s) {

for (int l = 0; l < min({(k) + 1, N}); ++l) {

for (int t = max({s, 0}); t < min({(i) + 1, N}); ++t) {







O[i][j][k][l][s][t] += O[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int j = max({i, 0}); j < N; ++j) {

for (int t = max({j, 0}); t < N; ++t) {

for (int k = 0; k < N; ++k) {

for (int s = max({k, 0}); s < min({(i) + 1, N}); ++s) {

for (int l = 0; l < min({(k) + 1, N}); ++l) {







O[i][j][k][l][s][t] += O[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int j = 0; j < N; ++j) {

for (int t = max({i, 0}); t < min({(j) + 1, N}); ++t) {

for (int k = 0; k < N; ++k) {

for (int s = max({k, 0}); s < min({(i) + 1, N}); ++s) {

for (int l = 0; l < min({(k) + 1, N}); ++l) {







O[i][j][k][l][s][t] += O[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int j = 0; j < N; ++j) {

for (int s = max({j, 0}); s < min({(i) + 1, N}); ++s) {

for (int k = 0; k < N; ++k) {

for (int t = max({k, 0}); t < min({(j) + 1, N}); ++t) {

for (int l = 0; l < min({(k) + 1, N}); ++l) {







O[i][j][k][l][s][t] += O[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int s = max({i, 0}); s < N; ++s) {

for (int j = 0; j < min({(i) + 1, N}); ++j) {

for (int k = 0; k < N; ++k) {

for (int t = max({k, 0}); t < min({(j) + 1, N}); ++t) {

for (int l = 0; l < min({(k) + 1, N}); ++l) {







O[i][j][k][l][s][t] += O[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int j = 0; j < min({(i) + 1, N}); ++j) {

for (int s = 0; s < min({(j) + 1, N}); ++s) {

for (int k = 0; k < N; ++k) {

for (int t = max({k, 0}); t < min({(s) + 1, N}); ++t) {

for (int l = 0; l < min({(k) + 1, N}); ++l) {







O[i][j][k][l][s][t] += O[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int s = 0; s < min({(i) + 1, N}); ++s) {

for (int j = max({i, 0}); j < N; ++j) {

for (int k = 0; k < N; ++k) {

for (int t = max({k, 0}); t < min({(s) + 1, N}); ++t) {

for (int l = 0; l < min({(k) + 1, N}); ++l) {







O[i][j][k][l][s][t] += O[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int j = max({i, 0}); j < N; ++j) {

for (int s = max({j, 0}); s < N; ++s) {

for (int k = 0; k < N; ++k) {

for (int t = max({k, 0}); t < min({(i) + 1, N}); ++t) {

for (int l = 0; l < min({(k) + 1, N}); ++l) {







O[i][j][k][l][s][t] += O[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int j = 0; j < N; ++j) {

for (int s = max({i, 0}); s < min({(j) + 1, N}); ++s) {

for (int k = 0; k < N; ++k) {

for (int t = max({k, 0}); t < min({(i) + 1, N}); ++t) {

for (int l = 0; l < min({(k) + 1, N}); ++l) {







O[i][j][k][l][s][t] += O[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int j = max({i, 0}); j < N; ++j) {

for (int k = 0; k < min({(i) + 1, N}); ++k) {

for (int s = max({j, 0}); s < N; ++s) {

for (int l = 0; l < min({(k) + 1, N}); ++l) {

for (int t = max({s, 0}); t < N; ++t) {







O[i][j][k][l][s][t] += O[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int j = max({i, 0}); j < N; ++j) {

for (int k = 0; k < min({(i) + 1, N}); ++k) {

for (int l = 0; l < min({(k) + 1, N}); ++l) {

for (int s = 0; s < N; ++s) {

for (int t = max({j, 0}); t < min({(s) + 1, N}); ++t) {







O[i][j][k][l][s][t] += O[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int j = 0; j < N; ++j) {

for (int k = 0; k < min({(i) + 1, N}); ++k) {

for (int s = max({i, 0}); s < min({(j) + 1, N}); ++s) {

for (int t = max({j, 0}); t < N; ++t) {

for (int l = 0; l < min({(k) + 1, N}); ++l) {







O[i][j][k][l][s][t] += O[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int s = max({i, 0}); s < N; ++s) {

for (int k = 0; k < min({(i) + 1, N}); ++k) {

for (int l = 0; l < min({(k) + 1, N}); ++l) {

for (int j = 0; j < N; ++j) {

for (int t = max({s, 0}); t < min({(j) + 1, N}); ++t) {







O[i][j][k][l][s][t] += O[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int j = 0; j < N; ++j) {

for (int k = 0; k < min({(i) + 1, N}); ++k) {

for (int s = max({j, 0}); s < N; ++s) {

for (int t = max({i, 0}); t < min({(j) + 1, N}); ++t) {

for (int l = 0; l < min({(k) + 1, N}); ++l) {







O[i][j][k][l][s][t] += O[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int j = 0; j < N; ++j) {

for (int k = 0; k < min({(i) + 1, N}); ++k) {

for (int s = 0; s < min({(j) + 1, N}); ++s) {

for (int l = 0; l < min({(k) + 1, N}); ++l) {

for (int t = max({i, 0}); t < min({(s) + 1, N}); ++t) {







O[i][j][k][l][s][t] += O[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int j = 0; j < N; ++j) {

for (int k = max({j, 0}); k < N; ++k) {

for (int t = max({k, 0}); t < min({(i) + 1, N}); ++t) {

for (int l = 0; l < N; ++l) {

for (int s = max({l, 0}); s < min({(j) + 1, N}); ++s) {







O[i][j][k][l][s][t] += O[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int t = max({i, 0}); t < N; ++t) {

for (int j = 0; j < N; ++j) {

for (int k = max({j, 0}); k < min({(i) + 1, N}); ++k) {

for (int l = 0; l < N; ++l) {

for (int s = max({l, 0}); s < min({(j) + 1, N}); ++s) {







O[i][j][k][l][s][t] += O[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int j = 0; j < N; ++j) {

for (int k = 0; k < min({(i) + 1, N}); ++k) {

for (int t = max({j, 0}); t < min({(k) + 1, N}); ++t) {

for (int l = 0; l < N; ++l) {

for (int s = max({l, 0}); s < min({(j) + 1, N}); ++s) {







O[i][j][k][l][s][t] += O[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int j = 0; j < N; ++j) {

for (int k = max({i, 0}); k < N; ++k) {

for (int t = max({j, 0}); t < min({(i) + 1, N}); ++t) {

for (int l = 0; l < N; ++l) {

for (int s = max({l, 0}); s < min({(j) + 1, N}); ++s) {







O[i][j][k][l][s][t] += O[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int j = 0; j < min({(i) + 1, N}); ++j) {

for (int k = max({i, 0}); k < N; ++k) {

for (int t = max({k, 0}); t < N; ++t) {

for (int l = 0; l < N; ++l) {

for (int s = max({l, 0}); s < min({(j) + 1, N}); ++s) {







O[i][j][k][l][s][t] += O[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int j = 0; j < min({(i) + 1, N}); ++j) {

for (int k = 0; k < N; ++k) {

for (int t = max({i, 0}); t < min({(k) + 1, N}); ++t) {

for (int l = 0; l < N; ++l) {

for (int s = max({l, 0}); s < min({(j) + 1, N}); ++s) {







O[i][j][k][l][s][t] += O[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int j = 0; j < N; ++j) {

for (int t = max({j, 0}); t < min({(i) + 1, N}); ++t) {

for (int k = 0; k < min({(j) + 1, N}); ++k) {

for (int l = 0; l < N; ++l) {

for (int s = max({l, 0}); s < min({(k) + 1, N}); ++s) {







O[i][j][k][l][s][t] += O[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int t = max({i, 0}); t < N; ++t) {

for (int j = 0; j < min({(i) + 1, N}); ++j) {

for (int k = 0; k < min({(j) + 1, N}); ++k) {

for (int l = 0; l < N; ++l) {

for (int s = max({l, 0}); s < min({(k) + 1, N}); ++s) {







O[i][j][k][l][s][t] += O[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int j = 0; j < min({(i) + 1, N}); ++j) {

for (int k = 0; k < N; ++k) {

for (int t = max({k, 0}); t < min({(j) + 1, N}); ++t) {

for (int l = 0; l < N; ++l) {

for (int s = max({l, 0}); s < min({(k) + 1, N}); ++s) {







O[i][j][k][l][s][t] += O[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int j = max({i, 0}); j < N; ++j) {

for (int k = 0; k < N; ++k) {

for (int t = max({k, 0}); t < min({(i) + 1, N}); ++t) {

for (int l = 0; l < N; ++l) {

for (int s = max({l, 0}); s < min({(k) + 1, N}); ++s) {







O[i][j][k][l][s][t] += O[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int j = max({i, 0}); j < N; ++j) {

for (int k = 0; k < min({(i) + 1, N}); ++k) {

for (int t = max({j, 0}); t < N; ++t) {

for (int l = 0; l < N; ++l) {

for (int s = max({l, 0}); s < min({(k) + 1, N}); ++s) {







O[i][j][k][l][s][t] += O[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int j = 0; j < N; ++j) {

for (int k = 0; k < min({(i) + 1, N}); ++k) {

for (int t = max({i, 0}); t < min({(j) + 1, N}); ++t) {

for (int l = 0; l < N; ++l) {

for (int s = max({l, 0}); s < min({(k) + 1, N}); ++s) {







O[i][j][k][l][s][t] += O[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int j = 0; j < N; ++j) {

for (int k = max({j, 0}); k < min({(i) + 1, N}); ++k) {

for (int l = 0; l < N; ++l) {

for (int s = max({l, 0}); s < N; ++s) {

for (int t = max({s, 0}); t < min({(j) + 1, N}); ++t) {







O[i][j][k][l][s][t] += O[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int j = 0; j < min({(i) + 1, N}); ++j) {

for (int k = max({i, 0}); k < N; ++k) {

for (int l = 0; l < N; ++l) {

for (int s = max({l, 0}); s < N; ++s) {

for (int t = max({s, 0}); t < min({(j) + 1, N}); ++t) {







O[i][j][k][l][s][t] += O[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int j = 0; j < min({(i) + 1, N}); ++j) {

for (int k = 0; k < min({(j) + 1, N}); ++k) {

for (int l = 0; l < N; ++l) {

for (int s = max({l, 0}); s < N; ++s) {

for (int t = max({s, 0}); t < min({(k) + 1, N}); ++t) {







O[i][j][k][l][s][t] += O[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int j = max({i, 0}); j < N; ++j) {

for (int k = 0; k < min({(i) + 1, N}); ++k) {

for (int l = 0; l < N; ++l) {

for (int s = max({l, 0}); s < N; ++s) {

for (int t = max({s, 0}); t < min({(k) + 1, N}); ++t) {







O[i][j][k][l][s][t] += O[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int j = max({i, 0}); j < N; ++j) {

for (int k = max({j, 0}); k < N; ++k) {

for (int l = 0; l < N; ++l) {

for (int s = max({l, 0}); s < N; ++s) {

for (int t = max({s, 0}); t < min({(i) + 1, N}); ++t) {







O[i][j][k][l][s][t] += O[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int j = 0; j < N; ++j) {

for (int k = max({i, 0}); k < min({(j) + 1, N}); ++k) {

for (int l = 0; l < N; ++l) {

for (int s = max({l, 0}); s < N; ++s) {

for (int t = max({s, 0}); t < min({(i) + 1, N}); ++t) {







O[i][j][k][l][s][t] += O[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int j = max({i, 0}); j < N; ++j) {

for (int k = max({j, 0}); k < N; ++k) {

for (int t = max({k, 0}); t < N; ++t) {

for (int l = 0; l < N; ++l) {

for (int s = max({l, 0}); s < min({(i) + 1, N}); ++s) {







O[i][j][k][l][s][t] += O[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int j = max({i, 0}); j < N; ++j) {

for (int k = 0; k < N; ++k) {

for (int t = max({j, 0}); t < min({(k) + 1, N}); ++t) {

for (int l = 0; l < N; ++l) {

for (int s = max({l, 0}); s < min({(i) + 1, N}); ++s) {







O[i][j][k][l][s][t] += O[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int j = 0; j < N; ++j) {

for (int t = max({j, 0}); t < N; ++t) {

for (int k = max({i, 0}); k < min({(j) + 1, N}); ++k) {

for (int l = 0; l < N; ++l) {

for (int s = max({l, 0}); s < min({(i) + 1, N}); ++s) {







O[i][j][k][l][s][t] += O[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int j = 0; j < N; ++j) {

for (int k = max({i, 0}); k < N; ++k) {

for (int t = max({k, 0}); t < min({(j) + 1, N}); ++t) {

for (int l = 0; l < N; ++l) {

for (int s = max({l, 0}); s < min({(i) + 1, N}); ++s) {







O[i][j][k][l][s][t] += O[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int j = 0; j < N; ++j) {

for (int t = max({i, 0}); t < min({(j) + 1, N}); ++t) {

for (int k = max({j, 0}); k < N; ++k) {

for (int l = 0; l < N; ++l) {

for (int s = max({l, 0}); s < min({(i) + 1, N}); ++s) {







O[i][j][k][l][s][t] += O[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int j = 0; j < N; ++j) {

for (int k = 0; k < min({(j) + 1, N}); ++k) {

for (int t = max({i, 0}); t < min({(k) + 1, N}); ++t) {

for (int l = 0; l < N; ++l) {

for (int s = max({l, 0}); s < min({(i) + 1, N}); ++s) {







O[i][j][k][l][s][t] += O[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int j = 0; j < N; ++j) {

for (int k = max({j, 0}); k < N; ++k) {

for (int s = max({k, 0}); s < min({(i) + 1, N}); ++s) {

for (int l = 0; l < N; ++l) {

for (int t = max({l, 0}); t < min({(j) + 1, N}); ++t) {







O[i][j][k][l][s][t] += O[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int s = max({i, 0}); s < N; ++s) {

for (int j = 0; j < N; ++j) {

for (int k = max({j, 0}); k < min({(i) + 1, N}); ++k) {

for (int l = 0; l < N; ++l) {

for (int t = max({l, 0}); t < min({(j) + 1, N}); ++t) {







O[i][j][k][l][s][t] += O[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int j = 0; j < N; ++j) {

for (int k = 0; k < min({(i) + 1, N}); ++k) {

for (int s = max({j, 0}); s < min({(k) + 1, N}); ++s) {

for (int l = 0; l < N; ++l) {

for (int t = max({l, 0}); t < min({(j) + 1, N}); ++t) {







O[i][j][k][l][s][t] += O[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int j = 0; j < N; ++j) {

for (int k = max({i, 0}); k < N; ++k) {

for (int s = max({j, 0}); s < min({(i) + 1, N}); ++s) {

for (int l = 0; l < N; ++l) {

for (int t = max({l, 0}); t < min({(j) + 1, N}); ++t) {







O[i][j][k][l][s][t] += O[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int j = 0; j < min({(i) + 1, N}); ++j) {

for (int k = max({i, 0}); k < N; ++k) {

for (int s = max({k, 0}); s < N; ++s) {

for (int l = 0; l < N; ++l) {

for (int t = max({l, 0}); t < min({(j) + 1, N}); ++t) {







O[i][j][k][l][s][t] += O[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int j = 0; j < min({(i) + 1, N}); ++j) {

for (int k = 0; k < N; ++k) {

for (int s = max({i, 0}); s < min({(k) + 1, N}); ++s) {

for (int l = 0; l < N; ++l) {

for (int t = max({l, 0}); t < min({(j) + 1, N}); ++t) {







O[i][j][k][l][s][t] += O[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int j = 0; j < N; ++j) {

for (int s = max({j, 0}); s < min({(i) + 1, N}); ++s) {

for (int k = 0; k < min({(j) + 1, N}); ++k) {

for (int l = 0; l < N; ++l) {

for (int t = max({l, 0}); t < min({(k) + 1, N}); ++t) {







O[i][j][k][l][s][t] += O[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int s = max({i, 0}); s < N; ++s) {

for (int j = 0; j < min({(i) + 1, N}); ++j) {

for (int k = 0; k < min({(j) + 1, N}); ++k) {

for (int l = 0; l < N; ++l) {

for (int t = max({l, 0}); t < min({(k) + 1, N}); ++t) {







O[i][j][k][l][s][t] += O[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int j = 0; j < min({(i) + 1, N}); ++j) {

for (int k = 0; k < N; ++k) {

for (int s = max({k, 0}); s < min({(j) + 1, N}); ++s) {

for (int l = 0; l < N; ++l) {

for (int t = max({l, 0}); t < min({(k) + 1, N}); ++t) {







O[i][j][k][l][s][t] += O[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int j = max({i, 0}); j < N; ++j) {

for (int k = 0; k < N; ++k) {

for (int s = max({k, 0}); s < min({(i) + 1, N}); ++s) {

for (int l = 0; l < N; ++l) {

for (int t = max({l, 0}); t < min({(k) + 1, N}); ++t) {







O[i][j][k][l][s][t] += O[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int j = max({i, 0}); j < N; ++j) {

for (int k = 0; k < min({(i) + 1, N}); ++k) {

for (int s = max({j, 0}); s < N; ++s) {

for (int l = 0; l < N; ++l) {

for (int t = max({l, 0}); t < min({(k) + 1, N}); ++t) {







O[i][j][k][l][s][t] += O[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int j = 0; j < N; ++j) {

for (int k = 0; k < min({(i) + 1, N}); ++k) {

for (int s = max({i, 0}); s < min({(j) + 1, N}); ++s) {

for (int l = 0; l < N; ++l) {

for (int t = max({l, 0}); t < min({(k) + 1, N}); ++t) {







O[i][j][k][l][s][t] += O[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int j = 0; j < N; ++j) {

for (int s = 0; s < min({(j) + 1, N}); ++s) {

for (int k = max({j, 0}); k < min({(i) + 1, N}); ++k) {

for (int l = 0; l < N; ++l) {

for (int t = max({l, 0}); t < min({(s) + 1, N}); ++t) {







O[i][j][k][l][s][t] += O[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int j = 0; j < min({(i) + 1, N}); ++j) {

for (int k = max({i, 0}); k < N; ++k) {

for (int s = 0; s < min({(j) + 1, N}); ++s) {

for (int l = 0; l < N; ++l) {

for (int t = max({l, 0}); t < min({(s) + 1, N}); ++t) {







O[i][j][k][l][s][t] += O[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int j = 0; j < min({(i) + 1, N}); ++j) {

for (int k = 0; k < min({(j) + 1, N}); ++k) {

for (int s = 0; s < min({(k) + 1, N}); ++s) {

for (int l = 0; l < N; ++l) {

for (int t = max({l, 0}); t < min({(s) + 1, N}); ++t) {







O[i][j][k][l][s][t] += O[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int j = max({i, 0}); j < N; ++j) {

for (int k = 0; k < min({(i) + 1, N}); ++k) {

for (int s = 0; s < min({(k) + 1, N}); ++s) {

for (int l = 0; l < N; ++l) {

for (int t = max({l, 0}); t < min({(s) + 1, N}); ++t) {







O[i][j][k][l][s][t] += O[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int s = 0; s < min({(i) + 1, N}); ++s) {

for (int j = max({i, 0}); j < N; ++j) {

for (int k = max({j, 0}); k < N; ++k) {

for (int l = 0; l < N; ++l) {

for (int t = max({l, 0}); t < min({(s) + 1, N}); ++t) {







O[i][j][k][l][s][t] += O[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int s = 0; s < min({(i) + 1, N}); ++s) {

for (int j = 0; j < N; ++j) {

for (int k = max({i, 0}); k < min({(j) + 1, N}); ++k) {

for (int l = 0; l < N; ++l) {

for (int t = max({l, 0}); t < min({(s) + 1, N}); ++t) {







O[i][j][k][l][s][t] += O[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int j = max({i, 0}); j < N; ++j) {

for (int k = max({j, 0}); k < N; ++k) {

for (int s = max({k, 0}); s < N; ++s) {

for (int l = 0; l < N; ++l) {

for (int t = max({l, 0}); t < min({(i) + 1, N}); ++t) {







O[i][j][k][l][s][t] += O[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int j = max({i, 0}); j < N; ++j) {

for (int k = 0; k < N; ++k) {

for (int s = max({j, 0}); s < min({(k) + 1, N}); ++s) {

for (int l = 0; l < N; ++l) {

for (int t = max({l, 0}); t < min({(i) + 1, N}); ++t) {







O[i][j][k][l][s][t] += O[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int j = 0; j < N; ++j) {

for (int s = max({j, 0}); s < N; ++s) {

for (int k = max({i, 0}); k < min({(j) + 1, N}); ++k) {

for (int l = 0; l < N; ++l) {

for (int t = max({l, 0}); t < min({(i) + 1, N}); ++t) {







O[i][j][k][l][s][t] += O[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int j = 0; j < N; ++j) {

for (int k = max({i, 0}); k < N; ++k) {

for (int s = max({k, 0}); s < min({(j) + 1, N}); ++s) {

for (int l = 0; l < N; ++l) {

for (int t = max({l, 0}); t < min({(i) + 1, N}); ++t) {







O[i][j][k][l][s][t] += O[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int j = 0; j < N; ++j) {

for (int s = max({i, 0}); s < min({(j) + 1, N}); ++s) {

for (int k = max({j, 0}); k < N; ++k) {

for (int l = 0; l < N; ++l) {

for (int t = max({l, 0}); t < min({(i) + 1, N}); ++t) {







O[i][j][k][l][s][t] += O[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int j = 0; j < N; ++j) {

for (int k = 0; k < min({(j) + 1, N}); ++k) {

for (int s = max({i, 0}); s < min({(k) + 1, N}); ++s) {

for (int l = 0; l < N; ++l) {

for (int t = max({l, 0}); t < min({(i) + 1, N}); ++t) {







O[i][j][k][l][s][t] += O[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int l = 0; l < min({(i) + 1, N}); ++l) {

for (int j = max({i, 0}); j < N; ++j) {

for (int k = max({j, 0}); k < N; ++k) {

for (int s = max({k, 0}); s < N; ++s) {

for (int t = max({s, 0}); t < N; ++t) {







O[i][j][k][l][s][t] += O[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int l = 0; l < min({(i) + 1, N}); ++l) {

for (int j = max({i, 0}); j < N; ++j) {

for (int k = max({j, 0}); k < N; ++k) {

for (int s = 0; s < N; ++s) {

for (int t = max({k, 0}); t < min({(s) + 1, N}); ++t) {







O[i][j][k][l][s][t] += O[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int l = 0; l < min({(i) + 1, N}); ++l) {

for (int j = max({i, 0}); j < N; ++j) {

for (int k = 0; k < N; ++k) {

for (int s = max({j, 0}); s < min({(k) + 1, N}); ++s) {

for (int t = max({k, 0}); t < N; ++t) {







O[i][j][k][l][s][t] += O[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int l = 0; l < min({(i) + 1, N}); ++l) {

for (int j = max({i, 0}); j < N; ++j) {

for (int s = max({j, 0}); s < N; ++s) {

for (int k = 0; k < N; ++k) {

for (int t = max({s, 0}); t < min({(k) + 1, N}); ++t) {







O[i][j][k][l][s][t] += O[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int l = 0; l < min({(i) + 1, N}); ++l) {

for (int j = max({i, 0}); j < N; ++j) {

for (int k = 0; k < N; ++k) {

for (int s = max({k, 0}); s < N; ++s) {

for (int t = max({j, 0}); t < min({(k) + 1, N}); ++t) {







O[i][j][k][l][s][t] += O[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int l = 0; l < min({(i) + 1, N}); ++l) {

for (int j = max({i, 0}); j < N; ++j) {

for (int k = 0; k < N; ++k) {

for (int s = 0; s < min({(k) + 1, N}); ++s) {

for (int t = max({j, 0}); t < min({(s) + 1, N}); ++t) {







O[i][j][k][l][s][t] += O[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int l = 0; l < min({(i) + 1, N}); ++l) {

for (int j = 0; j < N; ++j) {

for (int s = max({j, 0}); s < N; ++s) {

for (int k = max({i, 0}); k < min({(j) + 1, N}); ++k) {

for (int t = max({s, 0}); t < N; ++t) {







O[i][j][k][l][s][t] += O[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int l = 0; l < min({(i) + 1, N}); ++l) {

for (int j = 0; j < N; ++j) {

for (int k = max({i, 0}); k < min({(j) + 1, N}); ++k) {

for (int s = 0; s < N; ++s) {

for (int t = max({j, 0}); t < min({(s) + 1, N}); ++t) {







O[i][j][k][l][s][t] += O[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int l = 0; l < min({(i) + 1, N}); ++l) {

for (int k = max({i, 0}); k < N; ++k) {

for (int j = 0; j < N; ++j) {

for (int s = max({k, 0}); s < min({(j) + 1, N}); ++s) {

for (int t = max({j, 0}); t < N; ++t) {







O[i][j][k][l][s][t] += O[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int l = 0; l < min({(i) + 1, N}); ++l) {

for (int k = max({i, 0}); k < N; ++k) {

for (int s = max({k, 0}); s < N; ++s) {

for (int j = 0; j < N; ++j) {

for (int t = max({s, 0}); t < min({(j) + 1, N}); ++t) {







O[i][j][k][l][s][t] += O[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int l = 0; l < min({(i) + 1, N}); ++l) {

for (int k = max({i, 0}); k < N; ++k) {

for (int j = 0; j < N; ++j) {

for (int s = max({j, 0}); s < N; ++s) {

for (int t = max({k, 0}); t < min({(j) + 1, N}); ++t) {







O[i][j][k][l][s][t] += O[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int l = 0; l < min({(i) + 1, N}); ++l) {

for (int k = max({i, 0}); k < N; ++k) {

for (int j = 0; j < N; ++j) {

for (int s = 0; s < min({(j) + 1, N}); ++s) {

for (int t = max({k, 0}); t < min({(s) + 1, N}); ++t) {







O[i][j][k][l][s][t] += O[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int l = 0; l < min({(i) + 1, N}); ++l) {

for (int j = 0; j < N; ++j) {

for (int s = max({i, 0}); s < min({(j) + 1, N}); ++s) {

for (int k = max({j, 0}); k < N; ++k) {

for (int t = max({k, 0}); t < N; ++t) {







O[i][j][k][l][s][t] += O[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int l = 0; l < min({(i) + 1, N}); ++l) {

for (int j = 0; j < N; ++j) {

for (int s = max({i, 0}); s < min({(j) + 1, N}); ++s) {

for (int k = 0; k < N; ++k) {

for (int t = max({j, 0}); t < min({(k) + 1, N}); ++t) {







O[i][j][k][l][s][t] += O[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int l = 0; l < min({(i) + 1, N}); ++l) {

for (int j = 0; j < N; ++j) {

for (int t = max({j, 0}); t < N; ++t) {

for (int k = 0; k < min({(j) + 1, N}); ++k) {

for (int s = max({i, 0}); s < min({(k) + 1, N}); ++s) {







O[i][j][k][l][s][t] += O[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int l = 0; l < min({(i) + 1, N}); ++l) {

for (int j = 0; j < N; ++j) {

for (int k = 0; k < N; ++k) {

for (int s = max({i, 0}); s < min({(k) + 1, N}); ++s) {

for (int t = max({k, 0}); t < min({(j) + 1, N}); ++t) {







O[i][j][k][l][s][t] += O[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int s = max({i, 0}); s < N; ++s) {

for (int l = 0; l < min({(i) + 1, N}); ++l) {

for (int j = 0; j < N; ++j) {

for (int t = max({s, 0}); t < min({(j) + 1, N}); ++t) {

for (int k = max({j, 0}); k < N; ++k) {







O[i][j][k][l][s][t] += O[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int s = max({i, 0}); s < N; ++s) {

for (int l = 0; l < min({(i) + 1, N}); ++l) {

for (int j = 0; j < N; ++j) {

for (int k = 0; k < min({(j) + 1, N}); ++k) {

for (int t = max({s, 0}); t < min({(k) + 1, N}); ++t) {







O[i][j][k][l][s][t] += O[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int l = 0; l < min({(i) + 1, N}); ++l) {

for (int j = 0; j < N; ++j) {

for (int t = max({i, 0}); t < min({(j) + 1, N}); ++t) {

for (int k = max({j, 0}); k < N; ++k) {

for (int s = max({k, 0}); s < N; ++s) {







O[i][j][k][l][s][t] += O[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int l = 0; l < min({(i) + 1, N}); ++l) {

for (int j = 0; j < N; ++j) {

for (int t = max({i, 0}); t < min({(j) + 1, N}); ++t) {

for (int k = 0; k < N; ++k) {

for (int s = max({j, 0}); s < min({(k) + 1, N}); ++s) {







O[i][j][k][l][s][t] += O[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int l = 0; l < min({(i) + 1, N}); ++l) {

for (int j = 0; j < N; ++j) {

for (int s = max({j, 0}); s < N; ++s) {

for (int k = 0; k < min({(j) + 1, N}); ++k) {

for (int t = max({i, 0}); t < min({(k) + 1, N}); ++t) {







O[i][j][k][l][s][t] += O[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int l = 0; l < min({(i) + 1, N}); ++l) {

for (int j = 0; j < N; ++j) {

for (int k = 0; k < N; ++k) {

for (int s = max({k, 0}); s < min({(j) + 1, N}); ++s) {

for (int t = max({i, 0}); t < min({(k) + 1, N}); ++t) {







O[i][j][k][l][s][t] += O[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int l = 0; l < min({(i) + 1, N}); ++l) {

for (int j = 0; j < N; ++j) {

for (int s = 0; s < min({(j) + 1, N}); ++s) {

for (int k = max({j, 0}); k < N; ++k) {

for (int t = max({i, 0}); t < min({(s) + 1, N}); ++t) {







O[i][j][k][l][s][t] += O[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int l = 0; l < min({(i) + 1, N}); ++l) {

for (int j = 0; j < N; ++j) {

for (int k = 0; k < min({(j) + 1, N}); ++k) {

for (int s = 0; s < min({(k) + 1, N}); ++s) {

for (int t = max({i, 0}); t < min({(s) + 1, N}); ++t) {







O[i][j][k][l][s][t] += O[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int j = 0; j < N; ++j) {

for (int s = 0; s < min({(j) + 1, N}); ++s) {

for (int k = max({j, 0}); k < N; ++k) {

for (int l = max({k, 0}); l < N; ++l) {

for (int t = max({l, 0}); t < min({(i) + 1, N}); ++t) {







O[i][j][k][l][s][t] += O[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int t = max({i, 0}); t < N; ++t) {

for (int j = 0; j < N; ++j) {

for (int s = 0; s < min({(j) + 1, N}); ++s) {

for (int k = max({j, 0}); k < N; ++k) {

for (int l = max({k, 0}); l < min({(i) + 1, N}); ++l) {







O[i][j][k][l][s][t] += O[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int l = 0; l < min({(i) + 1, N}); ++l) {

for (int j = 0; j < N; ++j) {

for (int s = 0; s < min({(j) + 1, N}); ++s) {

for (int k = max({j, 0}); k < N; ++k) {

for (int t = max({k, 0}); t < min({(l) + 1, N}); ++t) {







O[i][j][k][l][s][t] += O[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int l = max({i, 0}); l < N; ++l) {

for (int j = 0; j < N; ++j) {

for (int s = 0; s < min({(j) + 1, N}); ++s) {

for (int k = max({j, 0}); k < N; ++k) {

for (int t = max({k, 0}); t < min({(i) + 1, N}); ++t) {







O[i][j][k][l][s][t] += O[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int l = max({i, 0}); l < N; ++l) {

for (int t = max({l, 0}); t < N; ++t) {

for (int j = 0; j < N; ++j) {

for (int s = 0; s < min({(j) + 1, N}); ++s) {

for (int k = max({j, 0}); k < min({(i) + 1, N}); ++k) {







O[i][j][k][l][s][t] += O[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int j = 0; j < N; ++j) {

for (int s = 0; s < min({(j) + 1, N}); ++s) {

for (int k = max({j, 0}); k < min({(i) + 1, N}); ++k) {

for (int l = 0; l < N; ++l) {

for (int t = max({i, 0}); t < min({(l) + 1, N}); ++t) {







O[i][j][k][l][s][t] += O[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int j = 0; j < N; ++j) {

for (int s = 0; s < min({(j) + 1, N}); ++s) {

for (int k = 0; k < N; ++k) {

for (int t = max({k, 0}); t < min({(i) + 1, N}); ++t) {

for (int l = max({j, 0}); l < min({(k) + 1, N}); ++l) {







O[i][j][k][l][s][t] += O[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int t = max({i, 0}); t < N; ++t) {

for (int k = 0; k < min({(i) + 1, N}); ++k) {

for (int j = 0; j < N; ++j) {

for (int s = 0; s < min({(j) + 1, N}); ++s) {

for (int l = max({j, 0}); l < min({(k) + 1, N}); ++l) {







O[i][j][k][l][s][t] += O[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int j = 0; j < N; ++j) {

for (int k = 0; k < min({(i) + 1, N}); ++k) {

for (int s = 0; s < min({(j) + 1, N}); ++s) {

for (int l = max({j, 0}); l < N; ++l) {

for (int t = max({l, 0}); t < min({(k) + 1, N}); ++t) {







O[i][j][k][l][s][t] += O[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int j = 0; j < N; ++j) {

for (int k = max({i, 0}); k < N; ++k) {

for (int s = 0; s < min({(j) + 1, N}); ++s) {

for (int l = max({j, 0}); l < N; ++l) {

for (int t = max({l, 0}); t < min({(i) + 1, N}); ++t) {







O[i][j][k][l][s][t] += O[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int j = 0; j < N; ++j) {

for (int k = max({i, 0}); k < N; ++k) {

for (int s = 0; s < min({(j) + 1, N}); ++s) {

for (int l = max({j, 0}); l < min({(i) + 1, N}); ++l) {

for (int t = max({k, 0}); t < N; ++t) {







O[i][j][k][l][s][t] += O[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int j = 0; j < N; ++j) {

for (int s = 0; s < min({(j) + 1, N}); ++s) {

for (int l = max({j, 0}); l < min({(i) + 1, N}); ++l) {

for (int k = 0; k < N; ++k) {

for (int t = max({i, 0}); t < min({(k) + 1, N}); ++t) {







O[i][j][k][l][s][t] += O[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int j = 0; j < N; ++j) {

for (int s = 0; s < min({(j) + 1, N}); ++s) {

for (int k = 0; k < N; ++k) {

for (int t = max({j, 0}); t < min({(k) + 1, N}); ++t) {

for (int l = max({k, 0}); l < min({(i) + 1, N}); ++l) {







O[i][j][k][l][s][t] += O[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int l = max({i, 0}); l < N; ++l) {

for (int k = 0; k < min({(i) + 1, N}); ++k) {

for (int j = 0; j < N; ++j) {

for (int s = 0; s < min({(j) + 1, N}); ++s) {

for (int t = max({j, 0}); t < min({(k) + 1, N}); ++t) {







O[i][j][k][l][s][t] += O[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int j = 0; j < N; ++j) {

for (int k = 0; k < min({(i) + 1, N}); ++k) {

for (int s = 0; s < min({(j) + 1, N}); ++s) {

for (int l = 0; l < min({(k) + 1, N}); ++l) {

for (int t = max({j, 0}); t < min({(l) + 1, N}); ++t) {







O[i][j][k][l][s][t] += O[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int l = 0; l < min({(i) + 1, N}); ++l) {

for (int k = max({i, 0}); k < N; ++k) {

for (int j = 0; j < N; ++j) {

for (int s = 0; s < min({(j) + 1, N}); ++s) {

for (int t = max({j, 0}); t < min({(l) + 1, N}); ++t) {







O[i][j][k][l][s][t] += O[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int j = 0; j < N; ++j) {

for (int k = max({i, 0}); k < N; ++k) {

for (int s = 0; s < min({(j) + 1, N}); ++s) {

for (int t = max({j, 0}); t < min({(i) + 1, N}); ++t) {

for (int l = max({k, 0}); l < N; ++l) {







O[i][j][k][l][s][t] += O[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int j = 0; j < N; ++j) {

for (int s = 0; s < min({(j) + 1, N}); ++s) {

for (int t = max({j, 0}); t < min({(i) + 1, N}); ++t) {

for (int k = 0; k < N; ++k) {

for (int l = max({i, 0}); l < min({(k) + 1, N}); ++l) {







O[i][j][k][l][s][t] += O[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int j = 0; j < min({(i) + 1, N}); ++j) {

for (int k = max({i, 0}); k < N; ++k) {

for (int s = 0; s < min({(j) + 1, N}); ++s) {

for (int l = max({k, 0}); l < N; ++l) {

for (int t = max({l, 0}); t < N; ++t) {







O[i][j][k][l][s][t] += O[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int j = 0; j < min({(i) + 1, N}); ++j) {

for (int k = max({i, 0}); k < N; ++k) {

for (int s = 0; s < min({(j) + 1, N}); ++s) {

for (int l = 0; l < N; ++l) {

for (int t = max({k, 0}); t < min({(l) + 1, N}); ++t) {







O[i][j][k][l][s][t] += O[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int j = 0; j < min({(i) + 1, N}); ++j) {

for (int s = 0; s < min({(j) + 1, N}); ++s) {

for (int k = 0; k < N; ++k) {

for (int t = max({k, 0}); t < N; ++t) {

for (int l = max({i, 0}); l < min({(k) + 1, N}); ++l) {







O[i][j][k][l][s][t] += O[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int l = max({i, 0}); l < N; ++l) {

for (int j = 0; j < min({(i) + 1, N}); ++j) {

for (int s = 0; s < min({(j) + 1, N}); ++s) {

for (int k = 0; k < N; ++k) {

for (int t = max({l, 0}); t < min({(k) + 1, N}); ++t) {







O[i][j][k][l][s][t] += O[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int j = 0; j < min({(i) + 1, N}); ++j) {

for (int s = 0; s < min({(j) + 1, N}); ++s) {

for (int k = 0; k < N; ++k) {

for (int t = max({i, 0}); t < min({(k) + 1, N}); ++t) {

for (int l = max({k, 0}); l < N; ++l) {







O[i][j][k][l][s][t] += O[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int j = 0; j < min({(i) + 1, N}); ++j) {

for (int s = 0; s < min({(j) + 1, N}); ++s) {

for (int k = 0; k < N; ++k) {

for (int l = 0; l < min({(k) + 1, N}); ++l) {

for (int t = max({i, 0}); t < min({(l) + 1, N}); ++t) {







O[i][j][k][l][s][t] += O[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int j = 0; j < N; ++j) {

for (int l = max({j, 0}); l < N; ++l) {

for (int k = 0; k < min({(j) + 1, N}); ++k) {

for (int t = max({l, 0}); t < min({(i) + 1, N}); ++t) {

for (int s = 0; s < min({(k) + 1, N}); ++s) {







O[i][j][k][l][s][t] += O[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int t = max({i, 0}); t < N; ++t) {

for (int j = 0; j < N; ++j) {

for (int l = max({j, 0}); l < min({(i) + 1, N}); ++l) {

for (int k = 0; k < min({(j) + 1, N}); ++k) {

for (int s = 0; s < min({(k) + 1, N}); ++s) {







O[i][j][k][l][s][t] += O[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int l = 0; l < min({(i) + 1, N}); ++l) {

for (int j = 0; j < N; ++j) {

for (int t = max({j, 0}); t < min({(l) + 1, N}); ++t) {

for (int k = 0; k < min({(j) + 1, N}); ++k) {

for (int s = 0; s < min({(k) + 1, N}); ++s) {







O[i][j][k][l][s][t] += O[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int l = max({i, 0}); l < N; ++l) {

for (int j = 0; j < N; ++j) {

for (int t = max({j, 0}); t < min({(i) + 1, N}); ++t) {

for (int k = 0; k < min({(j) + 1, N}); ++k) {

for (int s = 0; s < min({(k) + 1, N}); ++s) {







O[i][j][k][l][s][t] += O[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int l = max({i, 0}); l < N; ++l) {

for (int j = 0; j < min({(i) + 1, N}); ++j) {

for (int t = max({l, 0}); t < N; ++t) {

for (int k = 0; k < min({(j) + 1, N}); ++k) {

for (int s = 0; s < min({(k) + 1, N}); ++s) {







O[i][j][k][l][s][t] += O[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int j = 0; j < min({(i) + 1, N}); ++j) {

for (int k = 0; k < min({(j) + 1, N}); ++k) {

for (int s = 0; s < min({(k) + 1, N}); ++s) {

for (int l = 0; l < N; ++l) {

for (int t = max({i, 0}); t < min({(l) + 1, N}); ++t) {







O[i][j][k][l][s][t] += O[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int j = 0; j < N; ++j) {

for (int t = max({j, 0}); t < min({(i) + 1, N}); ++t) {

for (int k = 0; k < N; ++k) {

for (int s = 0; s < min({(k) + 1, N}); ++s) {

for (int l = max({k, 0}); l < min({(j) + 1, N}); ++l) {







O[i][j][k][l][s][t] += O[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int t = max({i, 0}); t < N; ++t) {

for (int j = 0; j < min({(i) + 1, N}); ++j) {

for (int k = 0; k < N; ++k) {

for (int s = 0; s < min({(k) + 1, N}); ++s) {

for (int l = max({k, 0}); l < min({(j) + 1, N}); ++l) {







O[i][j][k][l][s][t] += O[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int j = 0; j < min({(i) + 1, N}); ++j) {

for (int k = 0; k < N; ++k) {

for (int s = 0; s < min({(k) + 1, N}); ++s) {

for (int l = max({k, 0}); l < N; ++l) {

for (int t = max({l, 0}); t < min({(j) + 1, N}); ++t) {







O[i][j][k][l][s][t] += O[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int j = max({i, 0}); j < N; ++j) {

for (int k = 0; k < N; ++k) {

for (int s = 0; s < min({(k) + 1, N}); ++s) {

for (int l = max({k, 0}); l < N; ++l) {

for (int t = max({l, 0}); t < min({(i) + 1, N}); ++t) {







O[i][j][k][l][s][t] += O[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int j = max({i, 0}); j < N; ++j) {

for (int t = max({j, 0}); t < N; ++t) {

for (int k = 0; k < N; ++k) {

for (int s = 0; s < min({(k) + 1, N}); ++s) {

for (int l = max({k, 0}); l < min({(i) + 1, N}); ++l) {







O[i][j][k][l][s][t] += O[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int j = 0; j < N; ++j) {

for (int t = max({i, 0}); t < min({(j) + 1, N}); ++t) {

for (int k = 0; k < N; ++k) {

for (int s = 0; s < min({(k) + 1, N}); ++s) {

for (int l = max({k, 0}); l < min({(i) + 1, N}); ++l) {







O[i][j][k][l][s][t] += O[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int j = 0; j < N; ++j) {

for (int l = max({j, 0}); l < min({(i) + 1, N}); ++l) {

for (int k = 0; k < N; ++k) {

for (int s = 0; s < min({(k) + 1, N}); ++s) {

for (int t = max({k, 0}); t < min({(j) + 1, N}); ++t) {







O[i][j][k][l][s][t] += O[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int l = max({i, 0}); l < N; ++l) {

for (int j = 0; j < min({(i) + 1, N}); ++j) {

for (int k = 0; k < N; ++k) {

for (int s = 0; s < min({(k) + 1, N}); ++s) {

for (int t = max({k, 0}); t < min({(j) + 1, N}); ++t) {







O[i][j][k][l][s][t] += O[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int j = 0; j < min({(i) + 1, N}); ++j) {

for (int l = 0; l < min({(j) + 1, N}); ++l) {

for (int k = 0; k < N; ++k) {

for (int s = 0; s < min({(k) + 1, N}); ++s) {

for (int t = max({k, 0}); t < min({(l) + 1, N}); ++t) {







O[i][j][k][l][s][t] += O[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int l = 0; l < min({(i) + 1, N}); ++l) {

for (int j = max({i, 0}); j < N; ++j) {

for (int k = 0; k < N; ++k) {

for (int s = 0; s < min({(k) + 1, N}); ++s) {

for (int t = max({k, 0}); t < min({(l) + 1, N}); ++t) {







O[i][j][k][l][s][t] += O[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int j = max({i, 0}); j < N; ++j) {

for (int l = max({j, 0}); l < N; ++l) {

for (int k = 0; k < N; ++k) {

for (int s = 0; s < min({(k) + 1, N}); ++s) {

for (int t = max({k, 0}); t < min({(i) + 1, N}); ++t) {







O[i][j][k][l][s][t] += O[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int j = 0; j < N; ++j) {

for (int l = max({i, 0}); l < min({(j) + 1, N}); ++l) {

for (int k = 0; k < N; ++k) {

for (int s = 0; s < min({(k) + 1, N}); ++s) {

for (int t = max({k, 0}); t < min({(i) + 1, N}); ++t) {







O[i][j][k][l][s][t] += O[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int j = max({i, 0}); j < N; ++j) {

for (int k = 0; k < min({(i) + 1, N}); ++k) {

for (int l = max({j, 0}); l < N; ++l) {

for (int s = 0; s < min({(k) + 1, N}); ++s) {

for (int t = max({l, 0}); t < N; ++t) {







O[i][j][k][l][s][t] += O[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int j = max({i, 0}); j < N; ++j) {

for (int k = 0; k < min({(i) + 1, N}); ++k) {

for (int s = 0; s < min({(k) + 1, N}); ++s) {

for (int l = 0; l < N; ++l) {

for (int t = max({j, 0}); t < min({(l) + 1, N}); ++t) {







O[i][j][k][l][s][t] += O[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int j = 0; j < N; ++j) {

for (int k = 0; k < min({(i) + 1, N}); ++k) {

for (int t = max({j, 0}); t < N; ++t) {

for (int l = max({i, 0}); l < min({(j) + 1, N}); ++l) {

for (int s = 0; s < min({(k) + 1, N}); ++s) {







O[i][j][k][l][s][t] += O[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int l = max({i, 0}); l < N; ++l) {

for (int k = 0; k < min({(i) + 1, N}); ++k) {

for (int s = 0; s < min({(k) + 1, N}); ++s) {

for (int j = 0; j < N; ++j) {

for (int t = max({l, 0}); t < min({(j) + 1, N}); ++t) {







O[i][j][k][l][s][t] += O[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int j = 0; j < N; ++j) {

for (int k = 0; k < min({(i) + 1, N}); ++k) {

for (int t = max({i, 0}); t < min({(j) + 1, N}); ++t) {

for (int l = max({j, 0}); l < N; ++l) {

for (int s = 0; s < min({(k) + 1, N}); ++s) {







O[i][j][k][l][s][t] += O[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int j = 0; j < N; ++j) {

for (int k = 0; k < min({(i) + 1, N}); ++k) {

for (int l = 0; l < min({(j) + 1, N}); ++l) {

for (int s = 0; s < min({(k) + 1, N}); ++s) {

for (int t = max({i, 0}); t < min({(l) + 1, N}); ++t) {







O[i][j][k][l][s][t] += O[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int j = 0; j < N; ++j) {

for (int l = 0; l < min({(j) + 1, N}); ++l) {

for (int k = max({j, 0}); k < N; ++k) {

for (int s = 0; s < min({(l) + 1, N}); ++s) {

for (int t = max({k, 0}); t < min({(i) + 1, N}); ++t) {







O[i][j][k][l][s][t] += O[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int t = max({i, 0}); t < N; ++t) {

for (int j = 0; j < N; ++j) {

for (int l = 0; l < min({(j) + 1, N}); ++l) {

for (int k = max({j, 0}); k < min({(i) + 1, N}); ++k) {

for (int s = 0; s < min({(l) + 1, N}); ++s) {







O[i][j][k][l][s][t] += O[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int j = 0; j < N; ++j) {

for (int k = 0; k < min({(i) + 1, N}); ++k) {

for (int l = 0; l < min({(j) + 1, N}); ++l) {

for (int t = max({j, 0}); t < min({(k) + 1, N}); ++t) {

for (int s = 0; s < min({(l) + 1, N}); ++s) {







O[i][j][k][l][s][t] += O[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int j = 0; j < N; ++j) {

for (int k = max({i, 0}); k < N; ++k) {

for (int t = max({j, 0}); t < min({(i) + 1, N}); ++t) {

for (int l = 0; l < min({(j) + 1, N}); ++l) {

for (int s = 0; s < min({(l) + 1, N}); ++s) {







O[i][j][k][l][s][t] += O[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int j = 0; j < min({(i) + 1, N}); ++j) {

for (int k = max({i, 0}); k < N; ++k) {

for (int l = 0; l < min({(j) + 1, N}); ++l) {

for (int t = max({k, 0}); t < N; ++t) {

for (int s = 0; s < min({(l) + 1, N}); ++s) {







O[i][j][k][l][s][t] += O[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int j = 0; j < min({(i) + 1, N}); ++j) {

for (int l = 0; l < min({(j) + 1, N}); ++l) {

for (int s = 0; s < min({(l) + 1, N}); ++s) {

for (int k = 0; k < N; ++k) {

for (int t = max({i, 0}); t < min({(k) + 1, N}); ++t) {







O[i][j][k][l][s][t] += O[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int j = 0; j < N; ++j) {

for (int t = max({j, 0}); t < min({(i) + 1, N}); ++t) {

for (int k = 0; k < min({(j) + 1, N}); ++k) {

for (int l = 0; l < min({(k) + 1, N}); ++l) {

for (int s = 0; s < min({(l) + 1, N}); ++s) {







O[i][j][k][l][s][t] += O[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int t = max({i, 0}); t < N; ++t) {

for (int j = 0; j < min({(i) + 1, N}); ++j) {

for (int k = 0; k < min({(j) + 1, N}); ++k) {

for (int l = 0; l < min({(k) + 1, N}); ++l) {

for (int s = 0; s < min({(l) + 1, N}); ++s) {







O[i][j][k][l][s][t] += O[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int j = 0; j < min({(i) + 1, N}); ++j) {

for (int k = 0; k < N; ++k) {

for (int t = max({k, 0}); t < min({(j) + 1, N}); ++t) {

for (int l = 0; l < min({(k) + 1, N}); ++l) {

for (int s = 0; s < min({(l) + 1, N}); ++s) {







O[i][j][k][l][s][t] += O[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int j = max({i, 0}); j < N; ++j) {

for (int k = 0; k < N; ++k) {

for (int t = max({k, 0}); t < min({(i) + 1, N}); ++t) {

for (int l = 0; l < min({(k) + 1, N}); ++l) {

for (int s = 0; s < min({(l) + 1, N}); ++s) {







O[i][j][k][l][s][t] += O[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int j = max({i, 0}); j < N; ++j) {

for (int k = 0; k < min({(i) + 1, N}); ++k) {

for (int t = max({j, 0}); t < N; ++t) {

for (int l = 0; l < min({(k) + 1, N}); ++l) {

for (int s = 0; s < min({(l) + 1, N}); ++s) {







O[i][j][k][l][s][t] += O[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int j = 0; j < N; ++j) {

for (int k = 0; k < min({(i) + 1, N}); ++k) {

for (int t = max({i, 0}); t < min({(j) + 1, N}); ++t) {

for (int l = 0; l < min({(k) + 1, N}); ++l) {

for (int s = 0; s < min({(l) + 1, N}); ++s) {







O[i][j][k][l][s][t] += O[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int j = 0; j < N; ++j) {

for (int k = max({j, 0}); k < min({(i) + 1, N}); ++k) {

for (int l = 0; l < N; ++l) {

for (int s = 0; s < min({(l) + 1, N}); ++s) {

for (int t = max({l, 0}); t < min({(j) + 1, N}); ++t) {







O[i][j][k][l][s][t] += O[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int j = 0; j < min({(i) + 1, N}); ++j) {

for (int k = max({i, 0}); k < N; ++k) {

for (int l = 0; l < N; ++l) {

for (int s = 0; s < min({(l) + 1, N}); ++s) {

for (int t = max({l, 0}); t < min({(j) + 1, N}); ++t) {







O[i][j][k][l][s][t] += O[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int j = 0; j < min({(i) + 1, N}); ++j) {

for (int k = 0; k < min({(j) + 1, N}); ++k) {

for (int l = 0; l < N; ++l) {

for (int s = 0; s < min({(l) + 1, N}); ++s) {

for (int t = max({l, 0}); t < min({(k) + 1, N}); ++t) {







O[i][j][k][l][s][t] += O[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int j = max({i, 0}); j < N; ++j) {

for (int k = 0; k < min({(i) + 1, N}); ++k) {

for (int l = 0; l < N; ++l) {

for (int s = 0; s < min({(l) + 1, N}); ++s) {

for (int t = max({l, 0}); t < min({(k) + 1, N}); ++t) {







O[i][j][k][l][s][t] += O[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int j = max({i, 0}); j < N; ++j) {

for (int k = max({j, 0}); k < N; ++k) {

for (int l = 0; l < N; ++l) {

for (int s = 0; s < min({(l) + 1, N}); ++s) {

for (int t = max({l, 0}); t < min({(i) + 1, N}); ++t) {







O[i][j][k][l][s][t] += O[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int j = 0; j < N; ++j) {

for (int k = max({i, 0}); k < min({(j) + 1, N}); ++k) {

for (int l = 0; l < N; ++l) {

for (int s = 0; s < min({(l) + 1, N}); ++s) {

for (int t = max({l, 0}); t < min({(i) + 1, N}); ++t) {







O[i][j][k][l][s][t] += O[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int l = 0; l < min({(i) + 1, N}); ++l) {

for (int j = max({i, 0}); j < N; ++j) {

for (int s = 0; s < min({(l) + 1, N}); ++s) {

for (int k = max({j, 0}); k < N; ++k) {

for (int t = max({k, 0}); t < N; ++t) {







O[i][j][k][l][s][t] += O[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int l = 0; l < min({(i) + 1, N}); ++l) {

for (int j = max({i, 0}); j < N; ++j) {

for (int s = 0; s < min({(l) + 1, N}); ++s) {

for (int k = 0; k < N; ++k) {

for (int t = max({j, 0}); t < min({(k) + 1, N}); ++t) {







O[i][j][k][l][s][t] += O[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int l = 0; l < min({(i) + 1, N}); ++l) {

for (int s = 0; s < min({(l) + 1, N}); ++s) {

for (int j = 0; j < N; ++j) {

for (int t = max({j, 0}); t < N; ++t) {

for (int k = max({i, 0}); k < min({(j) + 1, N}); ++k) {







O[i][j][k][l][s][t] += O[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int l = 0; l < min({(i) + 1, N}); ++l) {

for (int k = max({i, 0}); k < N; ++k) {

for (int s = 0; s < min({(l) + 1, N}); ++s) {

for (int j = 0; j < N; ++j) {

for (int t = max({k, 0}); t < min({(j) + 1, N}); ++t) {







O[i][j][k][l][s][t] += O[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int l = 0; l < min({(i) + 1, N}); ++l) {

for (int s = 0; s < min({(l) + 1, N}); ++s) {

for (int j = 0; j < N; ++j) {

for (int t = max({i, 0}); t < min({(j) + 1, N}); ++t) {

for (int k = max({j, 0}); k < N; ++k) {







O[i][j][k][l][s][t] += O[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int l = 0; l < min({(i) + 1, N}); ++l) {

for (int s = 0; s < min({(l) + 1, N}); ++s) {

for (int j = 0; j < N; ++j) {

for (int k = 0; k < min({(j) + 1, N}); ++k) {

for (int t = max({i, 0}); t < min({(k) + 1, N}); ++t) {







O[i][j][k][l][s][t] += O[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int j = 0; j < N; ++j) {

for (int k = max({j, 0}); k < N; ++k) {

for (int l = max({k, 0}); l < min({(i) + 1, N}); ++l) {

for (int s = 0; s < N; ++s) {

for (int t = max({s, 0}); t < min({(j) + 1, N}); ++t) {







O[i][j][k][l][s][t] += O[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int l = max({i, 0}); l < N; ++l) {

for (int j = 0; j < N; ++j) {

for (int k = max({j, 0}); k < min({(i) + 1, N}); ++k) {

for (int s = 0; s < N; ++s) {

for (int t = max({s, 0}); t < min({(j) + 1, N}); ++t) {







O[i][j][k][l][s][t] += O[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int j = 0; j < N; ++j) {

for (int k = 0; k < min({(i) + 1, N}); ++k) {

for (int l = max({j, 0}); l < min({(k) + 1, N}); ++l) {

for (int s = 0; s < N; ++s) {

for (int t = max({s, 0}); t < min({(j) + 1, N}); ++t) {







O[i][j][k][l][s][t] += O[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int j = 0; j < N; ++j) {

for (int k = max({i, 0}); k < N; ++k) {

for (int l = max({j, 0}); l < min({(i) + 1, N}); ++l) {

for (int s = 0; s < N; ++s) {

for (int t = max({s, 0}); t < min({(j) + 1, N}); ++t) {







O[i][j][k][l][s][t] += O[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int j = 0; j < min({(i) + 1, N}); ++j) {

for (int k = max({i, 0}); k < N; ++k) {

for (int l = max({k, 0}); l < N; ++l) {

for (int s = 0; s < N; ++s) {

for (int t = max({s, 0}); t < min({(j) + 1, N}); ++t) {







O[i][j][k][l][s][t] += O[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int j = 0; j < min({(i) + 1, N}); ++j) {

for (int k = 0; k < N; ++k) {

for (int l = max({i, 0}); l < min({(k) + 1, N}); ++l) {

for (int s = 0; s < N; ++s) {

for (int t = max({s, 0}); t < min({(j) + 1, N}); ++t) {







O[i][j][k][l][s][t] += O[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int j = 0; j < N; ++j) {

for (int l = max({j, 0}); l < min({(i) + 1, N}); ++l) {

for (int k = 0; k < min({(j) + 1, N}); ++k) {

for (int s = 0; s < N; ++s) {

for (int t = max({s, 0}); t < min({(k) + 1, N}); ++t) {







O[i][j][k][l][s][t] += O[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int l = max({i, 0}); l < N; ++l) {

for (int j = 0; j < min({(i) + 1, N}); ++j) {

for (int k = 0; k < min({(j) + 1, N}); ++k) {

for (int s = 0; s < N; ++s) {

for (int t = max({s, 0}); t < min({(k) + 1, N}); ++t) {







O[i][j][k][l][s][t] += O[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int j = 0; j < min({(i) + 1, N}); ++j) {

for (int k = 0; k < N; ++k) {

for (int l = max({k, 0}); l < min({(j) + 1, N}); ++l) {

for (int s = 0; s < N; ++s) {

for (int t = max({s, 0}); t < min({(k) + 1, N}); ++t) {







O[i][j][k][l][s][t] += O[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int j = max({i, 0}); j < N; ++j) {

for (int k = 0; k < N; ++k) {

for (int l = max({k, 0}); l < min({(i) + 1, N}); ++l) {

for (int s = 0; s < N; ++s) {

for (int t = max({s, 0}); t < min({(k) + 1, N}); ++t) {







O[i][j][k][l][s][t] += O[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int j = max({i, 0}); j < N; ++j) {

for (int k = 0; k < min({(i) + 1, N}); ++k) {

for (int l = max({j, 0}); l < N; ++l) {

for (int s = 0; s < N; ++s) {

for (int t = max({s, 0}); t < min({(k) + 1, N}); ++t) {







O[i][j][k][l][s][t] += O[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int j = 0; j < N; ++j) {

for (int k = 0; k < min({(i) + 1, N}); ++k) {

for (int l = max({i, 0}); l < min({(j) + 1, N}); ++l) {

for (int s = 0; s < N; ++s) {

for (int t = max({s, 0}); t < min({(k) + 1, N}); ++t) {







O[i][j][k][l][s][t] += O[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int j = 0; j < N; ++j) {

for (int l = 0; l < min({(j) + 1, N}); ++l) {

for (int k = max({j, 0}); k < min({(i) + 1, N}); ++k) {

for (int s = 0; s < N; ++s) {

for (int t = max({s, 0}); t < min({(l) + 1, N}); ++t) {







O[i][j][k][l][s][t] += O[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int j = 0; j < min({(i) + 1, N}); ++j) {

for (int k = max({i, 0}); k < N; ++k) {

for (int l = 0; l < min({(j) + 1, N}); ++l) {

for (int s = 0; s < N; ++s) {

for (int t = max({s, 0}); t < min({(l) + 1, N}); ++t) {







O[i][j][k][l][s][t] += O[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int j = 0; j < min({(i) + 1, N}); ++j) {

for (int k = 0; k < min({(j) + 1, N}); ++k) {

for (int l = 0; l < min({(k) + 1, N}); ++l) {

for (int s = 0; s < N; ++s) {

for (int t = max({s, 0}); t < min({(l) + 1, N}); ++t) {







O[i][j][k][l][s][t] += O[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int j = max({i, 0}); j < N; ++j) {

for (int k = 0; k < min({(i) + 1, N}); ++k) {

for (int l = 0; l < min({(k) + 1, N}); ++l) {

for (int s = 0; s < N; ++s) {

for (int t = max({s, 0}); t < min({(l) + 1, N}); ++t) {







O[i][j][k][l][s][t] += O[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int l = 0; l < min({(i) + 1, N}); ++l) {

for (int j = max({i, 0}); j < N; ++j) {

for (int k = max({j, 0}); k < N; ++k) {

for (int s = 0; s < N; ++s) {

for (int t = max({s, 0}); t < min({(l) + 1, N}); ++t) {







O[i][j][k][l][s][t] += O[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int l = 0; l < min({(i) + 1, N}); ++l) {

for (int j = 0; j < N; ++j) {

for (int k = max({i, 0}); k < min({(j) + 1, N}); ++k) {

for (int s = 0; s < N; ++s) {

for (int t = max({s, 0}); t < min({(l) + 1, N}); ++t) {







O[i][j][k][l][s][t] += O[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int j = max({i, 0}); j < N; ++j) {

for (int k = max({j, 0}); k < N; ++k) {

for (int l = max({k, 0}); l < N; ++l) {

for (int s = 0; s < N; ++s) {

for (int t = max({s, 0}); t < min({(i) + 1, N}); ++t) {







O[i][j][k][l][s][t] += O[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int j = max({i, 0}); j < N; ++j) {

for (int k = 0; k < N; ++k) {

for (int l = max({j, 0}); l < min({(k) + 1, N}); ++l) {

for (int s = 0; s < N; ++s) {

for (int t = max({s, 0}); t < min({(i) + 1, N}); ++t) {







O[i][j][k][l][s][t] += O[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int j = 0; j < N; ++j) {

for (int l = max({j, 0}); l < N; ++l) {

for (int k = max({i, 0}); k < min({(j) + 1, N}); ++k) {

for (int s = 0; s < N; ++s) {

for (int t = max({s, 0}); t < min({(i) + 1, N}); ++t) {







O[i][j][k][l][s][t] += O[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int j = 0; j < N; ++j) {

for (int k = max({i, 0}); k < N; ++k) {

for (int l = max({k, 0}); l < min({(j) + 1, N}); ++l) {

for (int s = 0; s < N; ++s) {

for (int t = max({s, 0}); t < min({(i) + 1, N}); ++t) {







O[i][j][k][l][s][t] += O[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int j = 0; j < N; ++j) {

for (int l = max({i, 0}); l < min({(j) + 1, N}); ++l) {

for (int k = max({j, 0}); k < N; ++k) {

for (int s = 0; s < N; ++s) {

for (int t = max({s, 0}); t < min({(i) + 1, N}); ++t) {







O[i][j][k][l][s][t] += O[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int j = 0; j < N; ++j) {

for (int k = 0; k < min({(j) + 1, N}); ++k) {

for (int l = max({i, 0}); l < min({(k) + 1, N}); ++l) {

for (int s = 0; s < N; ++s) {

for (int t = max({s, 0}); t < min({(i) + 1, N}); ++t) {







O[i][j][k][l][s][t] += O[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int s = 0; s < min({(i) + 1, N}); ++s) {

for (int j = max({i, 0}); j < N; ++j) {

for (int k = max({j, 0}); k < N; ++k) {

for (int l = max({k, 0}); l < N; ++l) {

for (int t = max({l, 0}); t < N; ++t) {







O[i][j][k][l][s][t] += O[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int s = 0; s < min({(i) + 1, N}); ++s) {

for (int j = max({i, 0}); j < N; ++j) {

for (int k = max({j, 0}); k < N; ++k) {

for (int l = 0; l < N; ++l) {

for (int t = max({k, 0}); t < min({(l) + 1, N}); ++t) {







O[i][j][k][l][s][t] += O[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int s = 0; s < min({(i) + 1, N}); ++s) {

for (int j = max({i, 0}); j < N; ++j) {

for (int k = 0; k < N; ++k) {

for (int t = max({k, 0}); t < N; ++t) {

for (int l = max({j, 0}); l < min({(k) + 1, N}); ++l) {







O[i][j][k][l][s][t] += O[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int s = 0; s < min({(i) + 1, N}); ++s) {

for (int j = max({i, 0}); j < N; ++j) {

for (int l = max({j, 0}); l < N; ++l) {

for (int k = 0; k < N; ++k) {

for (int t = max({l, 0}); t < min({(k) + 1, N}); ++t) {







O[i][j][k][l][s][t] += O[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int s = 0; s < min({(i) + 1, N}); ++s) {

for (int j = max({i, 0}); j < N; ++j) {

for (int k = 0; k < N; ++k) {

for (int t = max({j, 0}); t < min({(k) + 1, N}); ++t) {

for (int l = max({k, 0}); l < N; ++l) {







O[i][j][k][l][s][t] += O[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int s = 0; s < min({(i) + 1, N}); ++s) {

for (int j = max({i, 0}); j < N; ++j) {

for (int k = 0; k < N; ++k) {

for (int l = 0; l < min({(k) + 1, N}); ++l) {

for (int t = max({j, 0}); t < min({(l) + 1, N}); ++t) {







O[i][j][k][l][s][t] += O[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int s = 0; s < min({(i) + 1, N}); ++s) {

for (int j = 0; j < N; ++j) {

for (int l = max({j, 0}); l < N; ++l) {

for (int k = max({i, 0}); k < min({(j) + 1, N}); ++k) {

for (int t = max({l, 0}); t < N; ++t) {







O[i][j][k][l][s][t] += O[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int s = 0; s < min({(i) + 1, N}); ++s) {

for (int j = 0; j < N; ++j) {

for (int k = max({i, 0}); k < min({(j) + 1, N}); ++k) {

for (int l = 0; l < N; ++l) {

for (int t = max({j, 0}); t < min({(l) + 1, N}); ++t) {







O[i][j][k][l][s][t] += O[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int s = 0; s < min({(i) + 1, N}); ++s) {

for (int k = max({i, 0}); k < N; ++k) {

for (int j = 0; j < N; ++j) {

for (int t = max({j, 0}); t < N; ++t) {

for (int l = max({k, 0}); l < min({(j) + 1, N}); ++l) {







O[i][j][k][l][s][t] += O[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int s = 0; s < min({(i) + 1, N}); ++s) {

for (int k = max({i, 0}); k < N; ++k) {

for (int l = max({k, 0}); l < N; ++l) {

for (int j = 0; j < N; ++j) {

for (int t = max({l, 0}); t < min({(j) + 1, N}); ++t) {







O[i][j][k][l][s][t] += O[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int s = 0; s < min({(i) + 1, N}); ++s) {

for (int k = max({i, 0}); k < N; ++k) {

for (int j = 0; j < N; ++j) {

for (int t = max({k, 0}); t < min({(j) + 1, N}); ++t) {

for (int l = max({j, 0}); l < N; ++l) {







O[i][j][k][l][s][t] += O[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int s = 0; s < min({(i) + 1, N}); ++s) {

for (int k = max({i, 0}); k < N; ++k) {

for (int j = 0; j < N; ++j) {

for (int l = 0; l < min({(j) + 1, N}); ++l) {

for (int t = max({k, 0}); t < min({(l) + 1, N}); ++t) {







O[i][j][k][l][s][t] += O[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int s = 0; s < min({(i) + 1, N}); ++s) {

for (int j = 0; j < N; ++j) {

for (int l = max({i, 0}); l < min({(j) + 1, N}); ++l) {

for (int k = max({j, 0}); k < N; ++k) {

for (int t = max({k, 0}); t < N; ++t) {







O[i][j][k][l][s][t] += O[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int s = 0; s < min({(i) + 1, N}); ++s) {

for (int j = 0; j < N; ++j) {

for (int l = max({i, 0}); l < min({(j) + 1, N}); ++l) {

for (int k = 0; k < N; ++k) {

for (int t = max({j, 0}); t < min({(k) + 1, N}); ++t) {







O[i][j][k][l][s][t] += O[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int s = 0; s < min({(i) + 1, N}); ++s) {

for (int j = 0; j < N; ++j) {

for (int t = max({j, 0}); t < N; ++t) {

for (int k = 0; k < min({(j) + 1, N}); ++k) {

for (int l = max({i, 0}); l < min({(k) + 1, N}); ++l) {







O[i][j][k][l][s][t] += O[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int s = 0; s < min({(i) + 1, N}); ++s) {

for (int j = 0; j < N; ++j) {

for (int k = 0; k < N; ++k) {

for (int t = max({k, 0}); t < min({(j) + 1, N}); ++t) {

for (int l = max({i, 0}); l < min({(k) + 1, N}); ++l) {







O[i][j][k][l][s][t] += O[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int s = 0; s < min({(i) + 1, N}); ++s) {

for (int l = max({i, 0}); l < N; ++l) {

for (int j = 0; j < N; ++j) {

for (int t = max({l, 0}); t < min({(j) + 1, N}); ++t) {

for (int k = max({j, 0}); k < N; ++k) {







O[i][j][k][l][s][t] += O[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int s = 0; s < min({(i) + 1, N}); ++s) {

for (int l = max({i, 0}); l < N; ++l) {

for (int j = 0; j < N; ++j) {

for (int k = 0; k < min({(j) + 1, N}); ++k) {

for (int t = max({l, 0}); t < min({(k) + 1, N}); ++t) {







O[i][j][k][l][s][t] += O[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int s = 0; s < min({(i) + 1, N}); ++s) {

for (int j = 0; j < N; ++j) {

for (int t = max({i, 0}); t < min({(j) + 1, N}); ++t) {

for (int k = max({j, 0}); k < N; ++k) {

for (int l = max({k, 0}); l < N; ++l) {







O[i][j][k][l][s][t] += O[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int s = 0; s < min({(i) + 1, N}); ++s) {

for (int j = 0; j < N; ++j) {

for (int t = max({i, 0}); t < min({(j) + 1, N}); ++t) {

for (int k = 0; k < N; ++k) {

for (int l = max({j, 0}); l < min({(k) + 1, N}); ++l) {







O[i][j][k][l][s][t] += O[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int s = 0; s < min({(i) + 1, N}); ++s) {

for (int j = 0; j < N; ++j) {

for (int l = max({j, 0}); l < N; ++l) {

for (int k = 0; k < min({(j) + 1, N}); ++k) {

for (int t = max({i, 0}); t < min({(k) + 1, N}); ++t) {







O[i][j][k][l][s][t] += O[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int s = 0; s < min({(i) + 1, N}); ++s) {

for (int j = 0; j < N; ++j) {

for (int k = 0; k < N; ++k) {

for (int t = max({i, 0}); t < min({(k) + 1, N}); ++t) {

for (int l = max({k, 0}); l < min({(j) + 1, N}); ++l) {







O[i][j][k][l][s][t] += O[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int s = 0; s < min({(i) + 1, N}); ++s) {

for (int j = 0; j < N; ++j) {

for (int l = 0; l < min({(j) + 1, N}); ++l) {

for (int k = max({j, 0}); k < N; ++k) {

for (int t = max({i, 0}); t < min({(l) + 1, N}); ++t) {







O[i][j][k][l][s][t] += O[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int s = 0; s < min({(i) + 1, N}); ++s) {

for (int j = 0; j < N; ++j) {

for (int k = 0; k < min({(j) + 1, N}); ++k) {

for (int l = 0; l < min({(k) + 1, N}); ++l) {

for (int t = max({i, 0}); t < min({(l) + 1, N}); ++t) {







O[i][j][k][l][s][t] += O[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int j = 0; j < N; ++j) {

for (int t = 0; t < min({(j) + 1, N}); ++t) {

for (int k = max({j, 0}); k < N; ++k) {

for (int l = max({k, 0}); l < N; ++l) {

for (int s = max({l, 0}); s < min({(i) + 1, N}); ++s) {







O[i][j][k][l][s][t] += O[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int s = max({i, 0}); s < N; ++s) {

for (int j = 0; j < N; ++j) {

for (int t = 0; t < min({(j) + 1, N}); ++t) {

for (int k = max({j, 0}); k < N; ++k) {

for (int l = max({k, 0}); l < min({(i) + 1, N}); ++l) {







O[i][j][k][l][s][t] += O[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int l = 0; l < min({(i) + 1, N}); ++l) {

for (int j = 0; j < N; ++j) {

for (int t = 0; t < min({(j) + 1, N}); ++t) {

for (int k = max({j, 0}); k < N; ++k) {

for (int s = max({k, 0}); s < min({(l) + 1, N}); ++s) {







O[i][j][k][l][s][t] += O[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int l = max({i, 0}); l < N; ++l) {

for (int j = 0; j < N; ++j) {

for (int t = 0; t < min({(j) + 1, N}); ++t) {

for (int k = max({j, 0}); k < N; ++k) {

for (int s = max({k, 0}); s < min({(i) + 1, N}); ++s) {







O[i][j][k][l][s][t] += O[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int l = max({i, 0}); l < N; ++l) {

for (int s = max({l, 0}); s < N; ++s) {

for (int j = 0; j < N; ++j) {

for (int t = 0; t < min({(j) + 1, N}); ++t) {

for (int k = max({j, 0}); k < min({(i) + 1, N}); ++k) {







O[i][j][k][l][s][t] += O[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int j = 0; j < N; ++j) {

for (int t = 0; t < min({(j) + 1, N}); ++t) {

for (int k = max({j, 0}); k < min({(i) + 1, N}); ++k) {

for (int l = 0; l < N; ++l) {

for (int s = max({i, 0}); s < min({(l) + 1, N}); ++s) {







O[i][j][k][l][s][t] += O[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int j = 0; j < N; ++j) {

for (int t = 0; t < min({(j) + 1, N}); ++t) {

for (int k = 0; k < N; ++k) {

for (int s = max({k, 0}); s < min({(i) + 1, N}); ++s) {

for (int l = max({j, 0}); l < min({(k) + 1, N}); ++l) {







O[i][j][k][l][s][t] += O[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int s = max({i, 0}); s < N; ++s) {

for (int k = 0; k < min({(i) + 1, N}); ++k) {

for (int j = 0; j < N; ++j) {

for (int t = 0; t < min({(j) + 1, N}); ++t) {

for (int l = max({j, 0}); l < min({(k) + 1, N}); ++l) {







O[i][j][k][l][s][t] += O[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int j = 0; j < N; ++j) {

for (int k = 0; k < min({(i) + 1, N}); ++k) {

for (int t = 0; t < min({(j) + 1, N}); ++t) {

for (int l = max({j, 0}); l < N; ++l) {

for (int s = max({l, 0}); s < min({(k) + 1, N}); ++s) {







O[i][j][k][l][s][t] += O[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int j = 0; j < N; ++j) {

for (int k = max({i, 0}); k < N; ++k) {

for (int t = 0; t < min({(j) + 1, N}); ++t) {

for (int l = max({j, 0}); l < N; ++l) {

for (int s = max({l, 0}); s < min({(i) + 1, N}); ++s) {







O[i][j][k][l][s][t] += O[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int j = 0; j < N; ++j) {

for (int k = max({i, 0}); k < N; ++k) {

for (int t = 0; t < min({(j) + 1, N}); ++t) {

for (int l = max({j, 0}); l < min({(i) + 1, N}); ++l) {

for (int s = max({k, 0}); s < N; ++s) {







O[i][j][k][l][s][t] += O[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int j = 0; j < N; ++j) {

for (int t = 0; t < min({(j) + 1, N}); ++t) {

for (int l = max({j, 0}); l < min({(i) + 1, N}); ++l) {

for (int k = 0; k < N; ++k) {

for (int s = max({i, 0}); s < min({(k) + 1, N}); ++s) {







O[i][j][k][l][s][t] += O[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int j = 0; j < N; ++j) {

for (int t = 0; t < min({(j) + 1, N}); ++t) {

for (int k = 0; k < N; ++k) {

for (int s = max({j, 0}); s < min({(k) + 1, N}); ++s) {

for (int l = max({k, 0}); l < min({(i) + 1, N}); ++l) {







O[i][j][k][l][s][t] += O[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int l = max({i, 0}); l < N; ++l) {

for (int k = 0; k < min({(i) + 1, N}); ++k) {

for (int j = 0; j < N; ++j) {

for (int s = max({j, 0}); s < min({(k) + 1, N}); ++s) {

for (int t = 0; t < min({(j) + 1, N}); ++t) {







O[i][j][k][l][s][t] += O[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int j = 0; j < N; ++j) {

for (int k = 0; k < min({(i) + 1, N}); ++k) {

for (int t = 0; t < min({(j) + 1, N}); ++t) {

for (int l = 0; l < min({(k) + 1, N}); ++l) {

for (int s = max({j, 0}); s < min({(l) + 1, N}); ++s) {







O[i][j][k][l][s][t] += O[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int l = 0; l < min({(i) + 1, N}); ++l) {

for (int k = max({i, 0}); k < N; ++k) {

for (int j = 0; j < N; ++j) {

for (int s = max({j, 0}); s < min({(l) + 1, N}); ++s) {

for (int t = 0; t < min({(j) + 1, N}); ++t) {







O[i][j][k][l][s][t] += O[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int j = 0; j < N; ++j) {

for (int k = max({i, 0}); k < N; ++k) {

for (int s = max({j, 0}); s < min({(i) + 1, N}); ++s) {

for (int t = 0; t < min({(j) + 1, N}); ++t) {

for (int l = max({k, 0}); l < N; ++l) {







O[i][j][k][l][s][t] += O[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int j = 0; j < N; ++j) {

for (int s = max({j, 0}); s < min({(i) + 1, N}); ++s) {

for (int t = 0; t < min({(j) + 1, N}); ++t) {

for (int k = 0; k < N; ++k) {

for (int l = max({i, 0}); l < min({(k) + 1, N}); ++l) {







O[i][j][k][l][s][t] += O[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int j = 0; j < min({(i) + 1, N}); ++j) {

for (int k = max({i, 0}); k < N; ++k) {

for (int t = 0; t < min({(j) + 1, N}); ++t) {

for (int l = max({k, 0}); l < N; ++l) {

for (int s = max({l, 0}); s < N; ++s) {







O[i][j][k][l][s][t] += O[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int j = 0; j < min({(i) + 1, N}); ++j) {

for (int k = max({i, 0}); k < N; ++k) {

for (int t = 0; t < min({(j) + 1, N}); ++t) {

for (int l = 0; l < N; ++l) {

for (int s = max({k, 0}); s < min({(l) + 1, N}); ++s) {







O[i][j][k][l][s][t] += O[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int j = 0; j < min({(i) + 1, N}); ++j) {

for (int t = 0; t < min({(j) + 1, N}); ++t) {

for (int k = 0; k < N; ++k) {

for (int s = max({k, 0}); s < N; ++s) {

for (int l = max({i, 0}); l < min({(k) + 1, N}); ++l) {







O[i][j][k][l][s][t] += O[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int l = max({i, 0}); l < N; ++l) {

for (int j = 0; j < min({(i) + 1, N}); ++j) {

for (int t = 0; t < min({(j) + 1, N}); ++t) {

for (int k = 0; k < N; ++k) {

for (int s = max({l, 0}); s < min({(k) + 1, N}); ++s) {







O[i][j][k][l][s][t] += O[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int j = 0; j < min({(i) + 1, N}); ++j) {

for (int t = 0; t < min({(j) + 1, N}); ++t) {

for (int k = 0; k < N; ++k) {

for (int s = max({i, 0}); s < min({(k) + 1, N}); ++s) {

for (int l = max({k, 0}); l < N; ++l) {







O[i][j][k][l][s][t] += O[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int j = 0; j < min({(i) + 1, N}); ++j) {

for (int t = 0; t < min({(j) + 1, N}); ++t) {

for (int k = 0; k < N; ++k) {

for (int l = 0; l < min({(k) + 1, N}); ++l) {

for (int s = max({i, 0}); s < min({(l) + 1, N}); ++s) {







O[i][j][k][l][s][t] += O[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int j = 0; j < N; ++j) {

for (int l = max({j, 0}); l < N; ++l) {

for (int k = 0; k < min({(j) + 1, N}); ++k) {

for (int s = max({l, 0}); s < min({(i) + 1, N}); ++s) {

for (int t = 0; t < min({(k) + 1, N}); ++t) {







O[i][j][k][l][s][t] += O[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int s = max({i, 0}); s < N; ++s) {

for (int j = 0; j < N; ++j) {

for (int l = max({j, 0}); l < min({(i) + 1, N}); ++l) {

for (int k = 0; k < min({(j) + 1, N}); ++k) {

for (int t = 0; t < min({(k) + 1, N}); ++t) {







O[i][j][k][l][s][t] += O[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int l = 0; l < min({(i) + 1, N}); ++l) {

for (int j = 0; j < N; ++j) {

for (int s = max({j, 0}); s < min({(l) + 1, N}); ++s) {

for (int k = 0; k < min({(j) + 1, N}); ++k) {

for (int t = 0; t < min({(k) + 1, N}); ++t) {







O[i][j][k][l][s][t] += O[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int l = max({i, 0}); l < N; ++l) {

for (int j = 0; j < N; ++j) {

for (int s = max({j, 0}); s < min({(i) + 1, N}); ++s) {

for (int k = 0; k < min({(j) + 1, N}); ++k) {

for (int t = 0; t < min({(k) + 1, N}); ++t) {







O[i][j][k][l][s][t] += O[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int l = max({i, 0}); l < N; ++l) {

for (int j = 0; j < min({(i) + 1, N}); ++j) {

for (int s = max({l, 0}); s < N; ++s) {

for (int k = 0; k < min({(j) + 1, N}); ++k) {

for (int t = 0; t < min({(k) + 1, N}); ++t) {







O[i][j][k][l][s][t] += O[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int j = 0; j < min({(i) + 1, N}); ++j) {

for (int k = 0; k < min({(j) + 1, N}); ++k) {

for (int t = 0; t < min({(k) + 1, N}); ++t) {

for (int l = 0; l < N; ++l) {

for (int s = max({i, 0}); s < min({(l) + 1, N}); ++s) {







O[i][j][k][l][s][t] += O[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int j = 0; j < N; ++j) {

for (int s = max({j, 0}); s < min({(i) + 1, N}); ++s) {

for (int k = 0; k < N; ++k) {

for (int t = 0; t < min({(k) + 1, N}); ++t) {

for (int l = max({k, 0}); l < min({(j) + 1, N}); ++l) {







O[i][j][k][l][s][t] += O[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int s = max({i, 0}); s < N; ++s) {

for (int j = 0; j < min({(i) + 1, N}); ++j) {

for (int k = 0; k < N; ++k) {

for (int t = 0; t < min({(k) + 1, N}); ++t) {

for (int l = max({k, 0}); l < min({(j) + 1, N}); ++l) {







O[i][j][k][l][s][t] += O[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int j = 0; j < min({(i) + 1, N}); ++j) {

for (int k = 0; k < N; ++k) {

for (int t = 0; t < min({(k) + 1, N}); ++t) {

for (int l = max({k, 0}); l < N; ++l) {

for (int s = max({l, 0}); s < min({(j) + 1, N}); ++s) {







O[i][j][k][l][s][t] += O[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int j = max({i, 0}); j < N; ++j) {

for (int k = 0; k < N; ++k) {

for (int t = 0; t < min({(k) + 1, N}); ++t) {

for (int l = max({k, 0}); l < N; ++l) {

for (int s = max({l, 0}); s < min({(i) + 1, N}); ++s) {







O[i][j][k][l][s][t] += O[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int j = max({i, 0}); j < N; ++j) {

for (int s = max({j, 0}); s < N; ++s) {

for (int k = 0; k < N; ++k) {

for (int t = 0; t < min({(k) + 1, N}); ++t) {

for (int l = max({k, 0}); l < min({(i) + 1, N}); ++l) {







O[i][j][k][l][s][t] += O[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int j = 0; j < N; ++j) {

for (int s = max({i, 0}); s < min({(j) + 1, N}); ++s) {

for (int k = 0; k < N; ++k) {

for (int t = 0; t < min({(k) + 1, N}); ++t) {

for (int l = max({k, 0}); l < min({(i) + 1, N}); ++l) {







O[i][j][k][l][s][t] += O[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int j = 0; j < N; ++j) {

for (int l = max({j, 0}); l < min({(i) + 1, N}); ++l) {

for (int k = 0; k < N; ++k) {

for (int s = max({k, 0}); s < min({(j) + 1, N}); ++s) {

for (int t = 0; t < min({(k) + 1, N}); ++t) {







O[i][j][k][l][s][t] += O[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int l = max({i, 0}); l < N; ++l) {

for (int j = 0; j < min({(i) + 1, N}); ++j) {

for (int k = 0; k < N; ++k) {

for (int s = max({k, 0}); s < min({(j) + 1, N}); ++s) {

for (int t = 0; t < min({(k) + 1, N}); ++t) {







O[i][j][k][l][s][t] += O[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int j = 0; j < min({(i) + 1, N}); ++j) {

for (int l = 0; l < min({(j) + 1, N}); ++l) {

for (int k = 0; k < N; ++k) {

for (int s = max({k, 0}); s < min({(l) + 1, N}); ++s) {

for (int t = 0; t < min({(k) + 1, N}); ++t) {







O[i][j][k][l][s][t] += O[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int l = 0; l < min({(i) + 1, N}); ++l) {

for (int j = max({i, 0}); j < N; ++j) {

for (int k = 0; k < N; ++k) {

for (int s = max({k, 0}); s < min({(l) + 1, N}); ++s) {

for (int t = 0; t < min({(k) + 1, N}); ++t) {







O[i][j][k][l][s][t] += O[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int j = max({i, 0}); j < N; ++j) {

for (int l = max({j, 0}); l < N; ++l) {

for (int k = 0; k < N; ++k) {

for (int s = max({k, 0}); s < min({(i) + 1, N}); ++s) {

for (int t = 0; t < min({(k) + 1, N}); ++t) {







O[i][j][k][l][s][t] += O[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int j = 0; j < N; ++j) {

for (int l = max({i, 0}); l < min({(j) + 1, N}); ++l) {

for (int k = 0; k < N; ++k) {

for (int s = max({k, 0}); s < min({(i) + 1, N}); ++s) {

for (int t = 0; t < min({(k) + 1, N}); ++t) {







O[i][j][k][l][s][t] += O[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int j = max({i, 0}); j < N; ++j) {

for (int k = 0; k < min({(i) + 1, N}); ++k) {

for (int l = max({j, 0}); l < N; ++l) {

for (int t = 0; t < min({(k) + 1, N}); ++t) {

for (int s = max({l, 0}); s < N; ++s) {







O[i][j][k][l][s][t] += O[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int j = max({i, 0}); j < N; ++j) {

for (int k = 0; k < min({(i) + 1, N}); ++k) {

for (int t = 0; t < min({(k) + 1, N}); ++t) {

for (int l = 0; l < N; ++l) {

for (int s = max({j, 0}); s < min({(l) + 1, N}); ++s) {







O[i][j][k][l][s][t] += O[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int j = 0; j < N; ++j) {

for (int k = 0; k < min({(i) + 1, N}); ++k) {

for (int s = max({j, 0}); s < N; ++s) {

for (int l = max({i, 0}); l < min({(j) + 1, N}); ++l) {

for (int t = 0; t < min({(k) + 1, N}); ++t) {







O[i][j][k][l][s][t] += O[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int l = max({i, 0}); l < N; ++l) {

for (int k = 0; k < min({(i) + 1, N}); ++k) {

for (int t = 0; t < min({(k) + 1, N}); ++t) {

for (int j = 0; j < N; ++j) {

for (int s = max({l, 0}); s < min({(j) + 1, N}); ++s) {







O[i][j][k][l][s][t] += O[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int j = 0; j < N; ++j) {

for (int k = 0; k < min({(i) + 1, N}); ++k) {

for (int s = max({i, 0}); s < min({(j) + 1, N}); ++s) {

for (int l = max({j, 0}); l < N; ++l) {

for (int t = 0; t < min({(k) + 1, N}); ++t) {







O[i][j][k][l][s][t] += O[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int j = 0; j < N; ++j) {

for (int k = 0; k < min({(i) + 1, N}); ++k) {

for (int l = 0; l < min({(j) + 1, N}); ++l) {

for (int t = 0; t < min({(k) + 1, N}); ++t) {

for (int s = max({i, 0}); s < min({(l) + 1, N}); ++s) {







O[i][j][k][l][s][t] += O[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int j = 0; j < N; ++j) {

for (int l = 0; l < min({(j) + 1, N}); ++l) {

for (int k = max({j, 0}); k < N; ++k) {

for (int t = 0; t < min({(l) + 1, N}); ++t) {

for (int s = max({k, 0}); s < min({(i) + 1, N}); ++s) {







O[i][j][k][l][s][t] += O[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int s = max({i, 0}); s < N; ++s) {

for (int j = 0; j < N; ++j) {

for (int l = 0; l < min({(j) + 1, N}); ++l) {

for (int k = max({j, 0}); k < min({(i) + 1, N}); ++k) {

for (int t = 0; t < min({(l) + 1, N}); ++t) {







O[i][j][k][l][s][t] += O[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int j = 0; j < N; ++j) {

for (int k = 0; k < min({(i) + 1, N}); ++k) {

for (int l = 0; l < min({(j) + 1, N}); ++l) {

for (int s = max({j, 0}); s < min({(k) + 1, N}); ++s) {

for (int t = 0; t < min({(l) + 1, N}); ++t) {







O[i][j][k][l][s][t] += O[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int j = 0; j < N; ++j) {

for (int k = max({i, 0}); k < N; ++k) {

for (int s = max({j, 0}); s < min({(i) + 1, N}); ++s) {

for (int l = 0; l < min({(j) + 1, N}); ++l) {

for (int t = 0; t < min({(l) + 1, N}); ++t) {







O[i][j][k][l][s][t] += O[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int j = 0; j < min({(i) + 1, N}); ++j) {

for (int k = max({i, 0}); k < N; ++k) {

for (int l = 0; l < min({(j) + 1, N}); ++l) {

for (int s = max({k, 0}); s < N; ++s) {

for (int t = 0; t < min({(l) + 1, N}); ++t) {







O[i][j][k][l][s][t] += O[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int j = 0; j < min({(i) + 1, N}); ++j) {

for (int l = 0; l < min({(j) + 1, N}); ++l) {

for (int t = 0; t < min({(l) + 1, N}); ++t) {

for (int k = 0; k < N; ++k) {

for (int s = max({i, 0}); s < min({(k) + 1, N}); ++s) {







O[i][j][k][l][s][t] += O[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int j = 0; j < N; ++j) {

for (int s = max({j, 0}); s < min({(i) + 1, N}); ++s) {

for (int k = 0; k < min({(j) + 1, N}); ++k) {

for (int l = 0; l < min({(k) + 1, N}); ++l) {

for (int t = 0; t < min({(l) + 1, N}); ++t) {







O[i][j][k][l][s][t] += O[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int s = max({i, 0}); s < N; ++s) {

for (int j = 0; j < min({(i) + 1, N}); ++j) {

for (int k = 0; k < min({(j) + 1, N}); ++k) {

for (int l = 0; l < min({(k) + 1, N}); ++l) {

for (int t = 0; t < min({(l) + 1, N}); ++t) {







O[i][j][k][l][s][t] += O[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int j = 0; j < min({(i) + 1, N}); ++j) {

for (int k = 0; k < N; ++k) {

for (int s = max({k, 0}); s < min({(j) + 1, N}); ++s) {

for (int l = 0; l < min({(k) + 1, N}); ++l) {

for (int t = 0; t < min({(l) + 1, N}); ++t) {







O[i][j][k][l][s][t] += O[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int j = max({i, 0}); j < N; ++j) {

for (int k = 0; k < N; ++k) {

for (int s = max({k, 0}); s < min({(i) + 1, N}); ++s) {

for (int l = 0; l < min({(k) + 1, N}); ++l) {

for (int t = 0; t < min({(l) + 1, N}); ++t) {







O[i][j][k][l][s][t] += O[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int j = max({i, 0}); j < N; ++j) {

for (int k = 0; k < min({(i) + 1, N}); ++k) {

for (int s = max({j, 0}); s < N; ++s) {

for (int l = 0; l < min({(k) + 1, N}); ++l) {

for (int t = 0; t < min({(l) + 1, N}); ++t) {







O[i][j][k][l][s][t] += O[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int j = 0; j < N; ++j) {

for (int k = 0; k < min({(i) + 1, N}); ++k) {

for (int s = max({i, 0}); s < min({(j) + 1, N}); ++s) {

for (int l = 0; l < min({(k) + 1, N}); ++l) {

for (int t = 0; t < min({(l) + 1, N}); ++t) {







O[i][j][k][l][s][t] += O[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int j = 0; j < N; ++j) {

for (int k = max({j, 0}); k < min({(i) + 1, N}); ++k) {

for (int l = 0; l < N; ++l) {

for (int s = max({l, 0}); s < min({(j) + 1, N}); ++s) {

for (int t = 0; t < min({(l) + 1, N}); ++t) {







O[i][j][k][l][s][t] += O[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int j = 0; j < min({(i) + 1, N}); ++j) {

for (int k = max({i, 0}); k < N; ++k) {

for (int l = 0; l < N; ++l) {

for (int s = max({l, 0}); s < min({(j) + 1, N}); ++s) {

for (int t = 0; t < min({(l) + 1, N}); ++t) {







O[i][j][k][l][s][t] += O[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int j = 0; j < min({(i) + 1, N}); ++j) {

for (int k = 0; k < min({(j) + 1, N}); ++k) {

for (int l = 0; l < N; ++l) {

for (int s = max({l, 0}); s < min({(k) + 1, N}); ++s) {

for (int t = 0; t < min({(l) + 1, N}); ++t) {







O[i][j][k][l][s][t] += O[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int j = max({i, 0}); j < N; ++j) {

for (int k = 0; k < min({(i) + 1, N}); ++k) {

for (int l = 0; l < N; ++l) {

for (int s = max({l, 0}); s < min({(k) + 1, N}); ++s) {

for (int t = 0; t < min({(l) + 1, N}); ++t) {







O[i][j][k][l][s][t] += O[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int j = max({i, 0}); j < N; ++j) {

for (int k = max({j, 0}); k < N; ++k) {

for (int l = 0; l < N; ++l) {

for (int s = max({l, 0}); s < min({(i) + 1, N}); ++s) {

for (int t = 0; t < min({(l) + 1, N}); ++t) {







O[i][j][k][l][s][t] += O[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int j = 0; j < N; ++j) {

for (int k = max({i, 0}); k < min({(j) + 1, N}); ++k) {

for (int l = 0; l < N; ++l) {

for (int s = max({l, 0}); s < min({(i) + 1, N}); ++s) {

for (int t = 0; t < min({(l) + 1, N}); ++t) {







O[i][j][k][l][s][t] += O[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int l = 0; l < min({(i) + 1, N}); ++l) {

for (int j = max({i, 0}); j < N; ++j) {

for (int t = 0; t < min({(l) + 1, N}); ++t) {

for (int k = max({j, 0}); k < N; ++k) {

for (int s = max({k, 0}); s < N; ++s) {







O[i][j][k][l][s][t] += O[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int l = 0; l < min({(i) + 1, N}); ++l) {

for (int j = max({i, 0}); j < N; ++j) {

for (int t = 0; t < min({(l) + 1, N}); ++t) {

for (int k = 0; k < N; ++k) {

for (int s = max({j, 0}); s < min({(k) + 1, N}); ++s) {







O[i][j][k][l][s][t] += O[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int l = 0; l < min({(i) + 1, N}); ++l) {

for (int t = 0; t < min({(l) + 1, N}); ++t) {

for (int j = 0; j < N; ++j) {

for (int s = max({j, 0}); s < N; ++s) {

for (int k = max({i, 0}); k < min({(j) + 1, N}); ++k) {







O[i][j][k][l][s][t] += O[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int l = 0; l < min({(i) + 1, N}); ++l) {

for (int k = max({i, 0}); k < N; ++k) {

for (int t = 0; t < min({(l) + 1, N}); ++t) {

for (int j = 0; j < N; ++j) {

for (int s = max({k, 0}); s < min({(j) + 1, N}); ++s) {







O[i][j][k][l][s][t] += O[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int l = 0; l < min({(i) + 1, N}); ++l) {

for (int t = 0; t < min({(l) + 1, N}); ++t) {

for (int j = 0; j < N; ++j) {

for (int s = max({i, 0}); s < min({(j) + 1, N}); ++s) {

for (int k = max({j, 0}); k < N; ++k) {







O[i][j][k][l][s][t] += O[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int l = 0; l < min({(i) + 1, N}); ++l) {

for (int t = 0; t < min({(l) + 1, N}); ++t) {

for (int j = 0; j < N; ++j) {

for (int k = 0; k < min({(j) + 1, N}); ++k) {

for (int s = max({i, 0}); s < min({(k) + 1, N}); ++s) {







O[i][j][k][l][s][t] += O[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int j = 0; j < N; ++j) {

for (int s = 0; s < min({(j) + 1, N}); ++s) {

for (int k = max({j, 0}); k < N; ++k) {

for (int t = 0; t < min({(s) + 1, N}); ++t) {

for (int l = max({k, 0}); l < min({(i) + 1, N}); ++l) {







O[i][j][k][l][s][t] += O[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int l = max({i, 0}); l < N; ++l) {

for (int j = 0; j < N; ++j) {

for (int s = 0; s < min({(j) + 1, N}); ++s) {

for (int k = max({j, 0}); k < min({(i) + 1, N}); ++k) {

for (int t = 0; t < min({(s) + 1, N}); ++t) {







O[i][j][k][l][s][t] += O[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int j = 0; j < N; ++j) {

for (int k = 0; k < min({(i) + 1, N}); ++k) {

for (int s = 0; s < min({(j) + 1, N}); ++s) {

for (int l = max({j, 0}); l < min({(k) + 1, N}); ++l) {

for (int t = 0; t < min({(s) + 1, N}); ++t) {







O[i][j][k][l][s][t] += O[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int j = 0; j < N; ++j) {

for (int k = max({i, 0}); k < N; ++k) {

for (int s = 0; s < min({(j) + 1, N}); ++s) {

for (int l = max({j, 0}); l < min({(i) + 1, N}); ++l) {

for (int t = 0; t < min({(s) + 1, N}); ++t) {







O[i][j][k][l][s][t] += O[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int j = 0; j < min({(i) + 1, N}); ++j) {

for (int k = max({i, 0}); k < N; ++k) {

for (int s = 0; s < min({(j) + 1, N}); ++s) {

for (int l = max({k, 0}); l < N; ++l) {

for (int t = 0; t < min({(s) + 1, N}); ++t) {







O[i][j][k][l][s][t] += O[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int j = 0; j < min({(i) + 1, N}); ++j) {

for (int s = 0; s < min({(j) + 1, N}); ++s) {

for (int t = 0; t < min({(s) + 1, N}); ++t) {

for (int k = 0; k < N; ++k) {

for (int l = max({i, 0}); l < min({(k) + 1, N}); ++l) {







O[i][j][k][l][s][t] += O[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int j = 0; j < N; ++j) {

for (int l = max({j, 0}); l < min({(i) + 1, N}); ++l) {

for (int k = 0; k < min({(j) + 1, N}); ++k) {

for (int s = 0; s < min({(k) + 1, N}); ++s) {

for (int t = 0; t < min({(s) + 1, N}); ++t) {







O[i][j][k][l][s][t] += O[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int l = max({i, 0}); l < N; ++l) {

for (int j = 0; j < min({(i) + 1, N}); ++j) {

for (int k = 0; k < min({(j) + 1, N}); ++k) {

for (int s = 0; s < min({(k) + 1, N}); ++s) {

for (int t = 0; t < min({(s) + 1, N}); ++t) {







O[i][j][k][l][s][t] += O[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int j = 0; j < min({(i) + 1, N}); ++j) {

for (int k = 0; k < N; ++k) {

for (int s = 0; s < min({(k) + 1, N}); ++s) {

for (int l = max({k, 0}); l < min({(j) + 1, N}); ++l) {

for (int t = 0; t < min({(s) + 1, N}); ++t) {







O[i][j][k][l][s][t] += O[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int j = max({i, 0}); j < N; ++j) {

for (int k = 0; k < N; ++k) {

for (int s = 0; s < min({(k) + 1, N}); ++s) {

for (int l = max({k, 0}); l < min({(i) + 1, N}); ++l) {

for (int t = 0; t < min({(s) + 1, N}); ++t) {







O[i][j][k][l][s][t] += O[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int j = max({i, 0}); j < N; ++j) {

for (int k = 0; k < min({(i) + 1, N}); ++k) {

for (int l = max({j, 0}); l < N; ++l) {

for (int s = 0; s < min({(k) + 1, N}); ++s) {

for (int t = 0; t < min({(s) + 1, N}); ++t) {







O[i][j][k][l][s][t] += O[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int j = 0; j < N; ++j) {

for (int k = 0; k < min({(i) + 1, N}); ++k) {

for (int l = max({i, 0}); l < min({(j) + 1, N}); ++l) {

for (int s = 0; s < min({(k) + 1, N}); ++s) {

for (int t = 0; t < min({(s) + 1, N}); ++t) {







O[i][j][k][l][s][t] += O[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int j = 0; j < N; ++j) {

for (int l = 0; l < min({(j) + 1, N}); ++l) {

for (int k = max({j, 0}); k < min({(i) + 1, N}); ++k) {

for (int s = 0; s < min({(l) + 1, N}); ++s) {

for (int t = 0; t < min({(s) + 1, N}); ++t) {







O[i][j][k][l][s][t] += O[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int j = 0; j < min({(i) + 1, N}); ++j) {

for (int k = max({i, 0}); k < N; ++k) {

for (int l = 0; l < min({(j) + 1, N}); ++l) {

for (int s = 0; s < min({(l) + 1, N}); ++s) {

for (int t = 0; t < min({(s) + 1, N}); ++t) {







O[i][j][k][l][s][t] += O[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int j = 0; j < min({(i) + 1, N}); ++j) {

for (int k = 0; k < min({(j) + 1, N}); ++k) {

for (int l = 0; l < min({(k) + 1, N}); ++l) {

for (int s = 0; s < min({(l) + 1, N}); ++s) {

for (int t = 0; t < min({(s) + 1, N}); ++t) {







O[i][j][k][l][s][t] += O[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int j = max({i, 0}); j < N; ++j) {

for (int k = 0; k < min({(i) + 1, N}); ++k) {

for (int l = 0; l < min({(k) + 1, N}); ++l) {

for (int s = 0; s < min({(l) + 1, N}); ++s) {

for (int t = 0; t < min({(s) + 1, N}); ++t) {







O[i][j][k][l][s][t] += O[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int l = 0; l < min({(i) + 1, N}); ++l) {

for (int j = max({i, 0}); j < N; ++j) {

for (int s = 0; s < min({(l) + 1, N}); ++s) {

for (int k = max({j, 0}); k < N; ++k) {

for (int t = 0; t < min({(s) + 1, N}); ++t) {







O[i][j][k][l][s][t] += O[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int l = 0; l < min({(i) + 1, N}); ++l) {

for (int s = 0; s < min({(l) + 1, N}); ++s) {

for (int t = 0; t < min({(s) + 1, N}); ++t) {

for (int j = 0; j < N; ++j) {

for (int k = max({i, 0}); k < min({(j) + 1, N}); ++k) {







O[i][j][k][l][s][t] += O[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int s = 0; s < min({(i) + 1, N}); ++s) {

for (int j = max({i, 0}); j < N; ++j) {

for (int t = 0; t < min({(s) + 1, N}); ++t) {

for (int k = max({j, 0}); k < N; ++k) {

for (int l = max({k, 0}); l < N; ++l) {







O[i][j][k][l][s][t] += O[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int s = 0; s < min({(i) + 1, N}); ++s) {

for (int j = max({i, 0}); j < N; ++j) {

for (int t = 0; t < min({(s) + 1, N}); ++t) {

for (int k = 0; k < N; ++k) {

for (int l = max({j, 0}); l < min({(k) + 1, N}); ++l) {







O[i][j][k][l][s][t] += O[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int s = 0; s < min({(i) + 1, N}); ++s) {

for (int t = 0; t < min({(s) + 1, N}); ++t) {

for (int j = 0; j < N; ++j) {

for (int l = max({j, 0}); l < N; ++l) {

for (int k = max({i, 0}); k < min({(j) + 1, N}); ++k) {







O[i][j][k][l][s][t] += O[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int s = 0; s < min({(i) + 1, N}); ++s) {

for (int k = max({i, 0}); k < N; ++k) {

for (int t = 0; t < min({(s) + 1, N}); ++t) {

for (int j = 0; j < N; ++j) {

for (int l = max({k, 0}); l < min({(j) + 1, N}); ++l) {







O[i][j][k][l][s][t] += O[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int s = 0; s < min({(i) + 1, N}); ++s) {

for (int t = 0; t < min({(s) + 1, N}); ++t) {

for (int j = 0; j < N; ++j) {

for (int l = max({i, 0}); l < min({(j) + 1, N}); ++l) {

for (int k = max({j, 0}); k < N; ++k) {







O[i][j][k][l][s][t] += O[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int s = 0; s < min({(i) + 1, N}); ++s) {

for (int t = 0; t < min({(s) + 1, N}); ++t) {

for (int j = 0; j < N; ++j) {

for (int k = 0; k < min({(j) + 1, N}); ++k) {

for (int l = max({i, 0}); l < min({(k) + 1, N}); ++l) {







O[i][j][k][l][s][t] += O[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int t = 0; t < min({(i) + 1, N}); ++t) {

for (int j = max({i, 0}); j < N; ++j) {

for (int k = max({j, 0}); k < N; ++k) {

for (int l = max({k, 0}); l < N; ++l) {

for (int s = max({l, 0}); s < N; ++s) {







O[i][j][k][l][s][t] += O[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int t = 0; t < min({(i) + 1, N}); ++t) {

for (int j = max({i, 0}); j < N; ++j) {

for (int k = max({j, 0}); k < N; ++k) {

for (int l = 0; l < N; ++l) {

for (int s = max({k, 0}); s < min({(l) + 1, N}); ++s) {







O[i][j][k][l][s][t] += O[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int t = 0; t < min({(i) + 1, N}); ++t) {

for (int j = max({i, 0}); j < N; ++j) {

for (int k = 0; k < N; ++k) {

for (int s = max({k, 0}); s < N; ++s) {

for (int l = max({j, 0}); l < min({(k) + 1, N}); ++l) {







O[i][j][k][l][s][t] += O[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int t = 0; t < min({(i) + 1, N}); ++t) {

for (int j = max({i, 0}); j < N; ++j) {

for (int l = max({j, 0}); l < N; ++l) {

for (int k = 0; k < N; ++k) {

for (int s = max({l, 0}); s < min({(k) + 1, N}); ++s) {







O[i][j][k][l][s][t] += O[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int t = 0; t < min({(i) + 1, N}); ++t) {

for (int j = max({i, 0}); j < N; ++j) {

for (int k = 0; k < N; ++k) {

for (int s = max({j, 0}); s < min({(k) + 1, N}); ++s) {

for (int l = max({k, 0}); l < N; ++l) {







O[i][j][k][l][s][t] += O[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int t = 0; t < min({(i) + 1, N}); ++t) {

for (int j = max({i, 0}); j < N; ++j) {

for (int k = 0; k < N; ++k) {

for (int l = 0; l < min({(k) + 1, N}); ++l) {

for (int s = max({j, 0}); s < min({(l) + 1, N}); ++s) {







O[i][j][k][l][s][t] += O[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int t = 0; t < min({(i) + 1, N}); ++t) {

for (int j = 0; j < N; ++j) {

for (int l = max({j, 0}); l < N; ++l) {

for (int k = max({i, 0}); k < min({(j) + 1, N}); ++k) {

for (int s = max({l, 0}); s < N; ++s) {







O[i][j][k][l][s][t] += O[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int t = 0; t < min({(i) + 1, N}); ++t) {

for (int j = 0; j < N; ++j) {

for (int k = max({i, 0}); k < min({(j) + 1, N}); ++k) {

for (int l = 0; l < N; ++l) {

for (int s = max({j, 0}); s < min({(l) + 1, N}); ++s) {







O[i][j][k][l][s][t] += O[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int t = 0; t < min({(i) + 1, N}); ++t) {

for (int k = max({i, 0}); k < N; ++k) {

for (int j = 0; j < N; ++j) {

for (int s = max({j, 0}); s < N; ++s) {

for (int l = max({k, 0}); l < min({(j) + 1, N}); ++l) {







O[i][j][k][l][s][t] += O[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int t = 0; t < min({(i) + 1, N}); ++t) {

for (int k = max({i, 0}); k < N; ++k) {

for (int l = max({k, 0}); l < N; ++l) {

for (int j = 0; j < N; ++j) {

for (int s = max({l, 0}); s < min({(j) + 1, N}); ++s) {







O[i][j][k][l][s][t] += O[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int t = 0; t < min({(i) + 1, N}); ++t) {

for (int k = max({i, 0}); k < N; ++k) {

for (int j = 0; j < N; ++j) {

for (int s = max({k, 0}); s < min({(j) + 1, N}); ++s) {

for (int l = max({j, 0}); l < N; ++l) {







O[i][j][k][l][s][t] += O[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int t = 0; t < min({(i) + 1, N}); ++t) {

for (int k = max({i, 0}); k < N; ++k) {

for (int j = 0; j < N; ++j) {

for (int l = 0; l < min({(j) + 1, N}); ++l) {

for (int s = max({k, 0}); s < min({(l) + 1, N}); ++s) {







O[i][j][k][l][s][t] += O[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int t = 0; t < min({(i) + 1, N}); ++t) {

for (int j = 0; j < N; ++j) {

for (int l = max({i, 0}); l < min({(j) + 1, N}); ++l) {

for (int k = max({j, 0}); k < N; ++k) {

for (int s = max({k, 0}); s < N; ++s) {







O[i][j][k][l][s][t] += O[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int t = 0; t < min({(i) + 1, N}); ++t) {

for (int j = 0; j < N; ++j) {

for (int l = max({i, 0}); l < min({(j) + 1, N}); ++l) {

for (int k = 0; k < N; ++k) {

for (int s = max({j, 0}); s < min({(k) + 1, N}); ++s) {







O[i][j][k][l][s][t] += O[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int t = 0; t < min({(i) + 1, N}); ++t) {

for (int j = 0; j < N; ++j) {

for (int s = max({j, 0}); s < N; ++s) {

for (int k = 0; k < min({(j) + 1, N}); ++k) {

for (int l = max({i, 0}); l < min({(k) + 1, N}); ++l) {







O[i][j][k][l][s][t] += O[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int t = 0; t < min({(i) + 1, N}); ++t) {

for (int j = 0; j < N; ++j) {

for (int k = 0; k < N; ++k) {

for (int s = max({k, 0}); s < min({(j) + 1, N}); ++s) {

for (int l = max({i, 0}); l < min({(k) + 1, N}); ++l) {







O[i][j][k][l][s][t] += O[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int t = 0; t < min({(i) + 1, N}); ++t) {

for (int l = max({i, 0}); l < N; ++l) {

for (int j = 0; j < N; ++j) {

for (int s = max({l, 0}); s < min({(j) + 1, N}); ++s) {

for (int k = max({j, 0}); k < N; ++k) {







O[i][j][k][l][s][t] += O[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int t = 0; t < min({(i) + 1, N}); ++t) {

for (int l = max({i, 0}); l < N; ++l) {

for (int j = 0; j < N; ++j) {

for (int k = 0; k < min({(j) + 1, N}); ++k) {

for (int s = max({l, 0}); s < min({(k) + 1, N}); ++s) {







O[i][j][k][l][s][t] += O[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int t = 0; t < min({(i) + 1, N}); ++t) {

for (int j = 0; j < N; ++j) {

for (int s = max({i, 0}); s < min({(j) + 1, N}); ++s) {

for (int k = max({j, 0}); k < N; ++k) {

for (int l = max({k, 0}); l < N; ++l) {







O[i][j][k][l][s][t] += O[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int t = 0; t < min({(i) + 1, N}); ++t) {

for (int j = 0; j < N; ++j) {

for (int s = max({i, 0}); s < min({(j) + 1, N}); ++s) {

for (int k = 0; k < N; ++k) {

for (int l = max({j, 0}); l < min({(k) + 1, N}); ++l) {







O[i][j][k][l][s][t] += O[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int t = 0; t < min({(i) + 1, N}); ++t) {

for (int j = 0; j < N; ++j) {

for (int l = max({j, 0}); l < N; ++l) {

for (int k = 0; k < min({(j) + 1, N}); ++k) {

for (int s = max({i, 0}); s < min({(k) + 1, N}); ++s) {







O[i][j][k][l][s][t] += O[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int t = 0; t < min({(i) + 1, N}); ++t) {

for (int j = 0; j < N; ++j) {

for (int k = 0; k < N; ++k) {

for (int s = max({i, 0}); s < min({(k) + 1, N}); ++s) {

for (int l = max({k, 0}); l < min({(j) + 1, N}); ++l) {







O[i][j][k][l][s][t] += O[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int t = 0; t < min({(i) + 1, N}); ++t) {

for (int j = 0; j < N; ++j) {

for (int l = 0; l < min({(j) + 1, N}); ++l) {

for (int k = max({j, 0}); k < N; ++k) {

for (int s = max({i, 0}); s < min({(l) + 1, N}); ++s) {







O[i][j][k][l][s][t] += O[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int t = 0; t < min({(i) + 1, N}); ++t) {

for (int j = 0; j < N; ++j) {

for (int k = 0; k < min({(j) + 1, N}); ++k) {

for (int l = 0; l < min({(k) + 1, N}); ++l) {

for (int s = max({i, 0}); s < min({(l) + 1, N}); ++s) {







O[i][j][k][l][s][t] += O[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int j = max({i, 0}); j < N; ++j) {

for (int k = max({j, 0}); k < N; ++k) {

for (int l = max({k, 0}); l < N; ++l) {

for (int s = max({l, 0}); s < N; ++s) {

for (int t = max({s, 0}); t < N; ++t) {







O[i][j][k][l][s][t] += O[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int j = max({i, 0}); j < N; ++j) {

for (int k = max({j, 0}); k < N; ++k) {

for (int l = max({k, 0}); l < N; ++l) {

for (int s = 0; s < N; ++s) {

for (int t = max({l, 0}); t < min({(s) + 1, N}); ++t) {







O[i][j][k][l][s][t] += O[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int j = max({i, 0}); j < N; ++j) {

for (int k = max({j, 0}); k < N; ++k) {

for (int l = 0; l < N; ++l) {

for (int s = max({k, 0}); s < min({(l) + 1, N}); ++s) {

for (int t = max({l, 0}); t < N; ++t) {







O[i][j][k][l][s][t] += O[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int j = max({i, 0}); j < N; ++j) {

for (int k = max({j, 0}); k < N; ++k) {

for (int s = max({k, 0}); s < N; ++s) {

for (int l = 0; l < N; ++l) {

for (int t = max({s, 0}); t < min({(l) + 1, N}); ++t) {







O[i][j][k][l][s][t] += O[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int j = max({i, 0}); j < N; ++j) {

for (int k = max({j, 0}); k < N; ++k) {

for (int l = 0; l < N; ++l) {

for (int s = max({l, 0}); s < N; ++s) {

for (int t = max({k, 0}); t < min({(l) + 1, N}); ++t) {







O[i][j][k][l][s][t] += O[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int j = max({i, 0}); j < N; ++j) {

for (int k = max({j, 0}); k < N; ++k) {

for (int l = 0; l < N; ++l) {

for (int s = 0; s < min({(l) + 1, N}); ++s) {

for (int t = max({k, 0}); t < min({(s) + 1, N}); ++t) {







O[i][j][k][l][s][t] += O[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int j = max({i, 0}); j < N; ++j) {

for (int k = 0; k < N; ++k) {

for (int s = max({k, 0}); s < N; ++s) {

for (int l = max({j, 0}); l < min({(k) + 1, N}); ++l) {

for (int t = max({s, 0}); t < N; ++t) {







O[i][j][k][l][s][t] += O[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int j = max({i, 0}); j < N; ++j) {

for (int k = 0; k < N; ++k) {

for (int l = max({j, 0}); l < min({(k) + 1, N}); ++l) {

for (int s = 0; s < N; ++s) {

for (int t = max({k, 0}); t < min({(s) + 1, N}); ++t) {







O[i][j][k][l][s][t] += O[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int j = max({i, 0}); j < N; ++j) {

for (int l = max({j, 0}); l < N; ++l) {

for (int k = 0; k < N; ++k) {

for (int s = max({l, 0}); s < min({(k) + 1, N}); ++s) {

for (int t = max({k, 0}); t < N; ++t) {







O[i][j][k][l][s][t] += O[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int j = max({i, 0}); j < N; ++j) {

for (int l = max({j, 0}); l < N; ++l) {

for (int s = max({l, 0}); s < N; ++s) {

for (int k = 0; k < N; ++k) {

for (int t = max({s, 0}); t < min({(k) + 1, N}); ++t) {







O[i][j][k][l][s][t] += O[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int j = max({i, 0}); j < N; ++j) {

for (int l = max({j, 0}); l < N; ++l) {

for (int k = 0; k < N; ++k) {

for (int s = max({k, 0}); s < N; ++s) {

for (int t = max({l, 0}); t < min({(k) + 1, N}); ++t) {







O[i][j][k][l][s][t] += O[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int j = max({i, 0}); j < N; ++j) {

for (int l = max({j, 0}); l < N; ++l) {

for (int k = 0; k < N; ++k) {

for (int s = 0; s < min({(k) + 1, N}); ++s) {

for (int t = max({l, 0}); t < min({(s) + 1, N}); ++t) {







O[i][j][k][l][s][t] += O[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int j = max({i, 0}); j < N; ++j) {

for (int k = 0; k < N; ++k) {

for (int s = max({j, 0}); s < min({(k) + 1, N}); ++s) {

for (int l = max({k, 0}); l < N; ++l) {

for (int t = max({l, 0}); t < N; ++t) {







O[i][j][k][l][s][t] += O[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int j = max({i, 0}); j < N; ++j) {

for (int k = 0; k < N; ++k) {

for (int s = max({j, 0}); s < min({(k) + 1, N}); ++s) {

for (int l = 0; l < N; ++l) {

for (int t = max({k, 0}); t < min({(l) + 1, N}); ++t) {







O[i][j][k][l][s][t] += O[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int j = max({i, 0}); j < N; ++j) {

for (int k = 0; k < N; ++k) {

for (int t = max({k, 0}); t < N; ++t) {

for (int l = 0; l < min({(k) + 1, N}); ++l) {

for (int s = max({j, 0}); s < min({(l) + 1, N}); ++s) {







O[i][j][k][l][s][t] += O[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int j = max({i, 0}); j < N; ++j) {

for (int k = 0; k < N; ++k) {

for (int l = 0; l < N; ++l) {

for (int s = max({j, 0}); s < min({(l) + 1, N}); ++s) {

for (int t = max({l, 0}); t < min({(k) + 1, N}); ++t) {







O[i][j][k][l][s][t] += O[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int j = max({i, 0}); j < N; ++j) {

for (int s = max({j, 0}); s < N; ++s) {

for (int k = 0; k < N; ++k) {

for (int t = max({s, 0}); t < min({(k) + 1, N}); ++t) {

for (int l = max({k, 0}); l < N; ++l) {







O[i][j][k][l][s][t] += O[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int j = max({i, 0}); j < N; ++j) {

for (int s = max({j, 0}); s < N; ++s) {

for (int k = 0; k < N; ++k) {

for (int l = 0; l < min({(k) + 1, N}); ++l) {

for (int t = max({s, 0}); t < min({(l) + 1, N}); ++t) {







O[i][j][k][l][s][t] += O[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int j = max({i, 0}); j < N; ++j) {

for (int k = 0; k < N; ++k) {

for (int t = max({j, 0}); t < min({(k) + 1, N}); ++t) {

for (int l = max({k, 0}); l < N; ++l) {

for (int s = max({l, 0}); s < N; ++s) {







O[i][j][k][l][s][t] += O[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int j = max({i, 0}); j < N; ++j) {

for (int k = 0; k < N; ++k) {

for (int t = max({j, 0}); t < min({(k) + 1, N}); ++t) {

for (int l = 0; l < N; ++l) {

for (int s = max({k, 0}); s < min({(l) + 1, N}); ++s) {







O[i][j][k][l][s][t] += O[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int j = max({i, 0}); j < N; ++j) {

for (int k = 0; k < N; ++k) {

for (int s = max({k, 0}); s < N; ++s) {

for (int l = 0; l < min({(k) + 1, N}); ++l) {

for (int t = max({j, 0}); t < min({(l) + 1, N}); ++t) {







O[i][j][k][l][s][t] += O[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int j = max({i, 0}); j < N; ++j) {

for (int k = 0; k < N; ++k) {

for (int l = 0; l < N; ++l) {

for (int s = max({l, 0}); s < min({(k) + 1, N}); ++s) {

for (int t = max({j, 0}); t < min({(l) + 1, N}); ++t) {







O[i][j][k][l][s][t] += O[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int j = max({i, 0}); j < N; ++j) {

for (int k = 0; k < N; ++k) {

for (int s = 0; s < min({(k) + 1, N}); ++s) {

for (int l = max({k, 0}); l < N; ++l) {

for (int t = max({j, 0}); t < min({(s) + 1, N}); ++t) {







O[i][j][k][l][s][t] += O[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int j = max({i, 0}); j < N; ++j) {

for (int k = 0; k < N; ++k) {

for (int l = 0; l < min({(k) + 1, N}); ++l) {

for (int s = 0; s < min({(l) + 1, N}); ++s) {

for (int t = max({j, 0}); t < min({(s) + 1, N}); ++t) {







O[i][j][k][l][s][t] += O[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int j = 0; j < N; ++j) {

for (int l = max({j, 0}); l < N; ++l) {

for (int k = max({i, 0}); k < min({(j) + 1, N}); ++k) {

for (int s = max({l, 0}); s < N; ++s) {

for (int t = max({s, 0}); t < N; ++t) {







O[i][j][k][l][s][t] += O[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int j = 0; j < N; ++j) {

for (int l = max({j, 0}); l < N; ++l) {

for (int k = max({i, 0}); k < min({(j) + 1, N}); ++k) {

for (int s = 0; s < N; ++s) {

for (int t = max({l, 0}); t < min({(s) + 1, N}); ++t) {







O[i][j][k][l][s][t] += O[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int j = 0; j < N; ++j) {

for (int k = max({i, 0}); k < min({(j) + 1, N}); ++k) {

for (int l = 0; l < N; ++l) {

for (int s = max({j, 0}); s < min({(l) + 1, N}); ++s) {

for (int t = max({l, 0}); t < N; ++t) {







O[i][j][k][l][s][t] += O[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int j = 0; j < N; ++j) {

for (int s = max({j, 0}); s < N; ++s) {

for (int k = max({i, 0}); k < min({(j) + 1, N}); ++k) {

for (int l = 0; l < N; ++l) {

for (int t = max({s, 0}); t < min({(l) + 1, N}); ++t) {







O[i][j][k][l][s][t] += O[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int j = 0; j < N; ++j) {

for (int k = max({i, 0}); k < min({(j) + 1, N}); ++k) {

for (int l = 0; l < N; ++l) {

for (int s = max({l, 0}); s < N; ++s) {

for (int t = max({j, 0}); t < min({(l) + 1, N}); ++t) {







O[i][j][k][l][s][t] += O[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int j = 0; j < N; ++j) {

for (int k = max({i, 0}); k < min({(j) + 1, N}); ++k) {

for (int l = 0; l < N; ++l) {

for (int s = 0; s < min({(l) + 1, N}); ++s) {

for (int t = max({j, 0}); t < min({(s) + 1, N}); ++t) {







O[i][j][k][l][s][t] += O[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int j = 0; j < N; ++j) {

for (int k = max({i, 0}); k < N; ++k) {

for (int s = max({j, 0}); s < N; ++s) {

for (int l = max({k, 0}); l < min({(j) + 1, N}); ++l) {

for (int t = max({s, 0}); t < N; ++t) {







O[i][j][k][l][s][t] += O[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int j = 0; j < N; ++j) {

for (int k = max({i, 0}); k < N; ++k) {

for (int l = max({k, 0}); l < min({(j) + 1, N}); ++l) {

for (int s = 0; s < N; ++s) {

for (int t = max({j, 0}); t < min({(s) + 1, N}); ++t) {







O[i][j][k][l][s][t] += O[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int j = 0; j < N; ++j) {

for (int k = max({i, 0}); k < N; ++k) {

for (int t = max({j, 0}); t < N; ++t) {

for (int l = max({k, 0}); l < N; ++l) {

for (int s = max({l, 0}); s < min({(j) + 1, N}); ++s) {







O[i][j][k][l][s][t] += O[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int j = 0; j < N; ++j) {

for (int k = max({i, 0}); k < N; ++k) {

for (int l = max({k, 0}); l < N; ++l) {

for (int s = max({l, 0}); s < N; ++s) {

for (int t = max({s, 0}); t < min({(j) + 1, N}); ++t) {







O[i][j][k][l][s][t] += O[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int j = 0; j < N; ++j) {

for (int k = max({i, 0}); k < N; ++k) {

for (int s = max({j, 0}); s < N; ++s) {

for (int l = max({k, 0}); l < N; ++l) {

for (int t = max({l, 0}); t < min({(j) + 1, N}); ++t) {







O[i][j][k][l][s][t] += O[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int j = 0; j < N; ++j) {

for (int k = max({i, 0}); k < N; ++k) {

for (int s = 0; s < min({(j) + 1, N}); ++s) {

for (int l = max({k, 0}); l < N; ++l) {

for (int t = max({l, 0}); t < min({(s) + 1, N}); ++t) {







O[i][j][k][l][s][t] += O[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int j = 0; j < N; ++j) {

for (int k = max({i, 0}); k < N; ++k) {

for (int l = max({j, 0}); l < N; ++l) {

for (int s = max({k, 0}); s < min({(j) + 1, N}); ++s) {

for (int t = max({l, 0}); t < N; ++t) {







O[i][j][k][l][s][t] += O[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int j = 0; j < N; ++j) {

for (int k = max({i, 0}); k < N; ++k) {

for (int s = max({k, 0}); s < min({(j) + 1, N}); ++s) {

for (int l = 0; l < N; ++l) {

for (int t = max({j, 0}); t < min({(l) + 1, N}); ++t) {







O[i][j][k][l][s][t] += O[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int j = 0; j < N; ++j) {

for (int k = max({i, 0}); k < N; ++k) {

for (int t = max({j, 0}); t < N; ++t) {

for (int l = 0; l < min({(j) + 1, N}); ++l) {

for (int s = max({k, 0}); s < min({(l) + 1, N}); ++s) {







O[i][j][k][l][s][t] += O[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int j = 0; j < N; ++j) {

for (int k = max({i, 0}); k < N; ++k) {

for (int l = 0; l < N; ++l) {

for (int s = max({k, 0}); s < min({(l) + 1, N}); ++s) {

for (int t = max({l, 0}); t < min({(j) + 1, N}); ++t) {







O[i][j][k][l][s][t] += O[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int j = 0; j < N; ++j) {

for (int k = max({i, 0}); k < N; ++k) {

for (int l = max({j, 0}); l < N; ++l) {

for (int s = max({k, 0}); s < N; ++s) {

for (int t = max({s, 0}); t < min({(j) + 1, N}); ++t) {







O[i][j][k][l][s][t] += O[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int j = 0; j < N; ++j) {

for (int k = max({i, 0}); k < N; ++k) {

for (int l = 0; l < min({(j) + 1, N}); ++l) {

for (int s = max({k, 0}); s < N; ++s) {

for (int t = max({s, 0}); t < min({(l) + 1, N}); ++t) {







O[i][j][k][l][s][t] += O[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int j = 0; j < N; ++j) {

for (int k = max({i, 0}); k < N; ++k) {

for (int l = max({j, 0}); l < N; ++l) {

for (int t = max({k, 0}); t < min({(j) + 1, N}); ++t) {

for (int s = max({l, 0}); s < N; ++s) {







O[i][j][k][l][s][t] += O[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int j = 0; j < N; ++j) {

for (int k = max({i, 0}); k < N; ++k) {

for (int t = max({k, 0}); t < min({(j) + 1, N}); ++t) {

for (int l = 0; l < N; ++l) {

for (int s = max({j, 0}); s < min({(l) + 1, N}); ++s) {







O[i][j][k][l][s][t] += O[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int j = 0; j < N; ++j) {

for (int k = max({i, 0}); k < N; ++k) {

for (int s = max({j, 0}); s < N; ++s) {

for (int l = 0; l < min({(j) + 1, N}); ++l) {

for (int t = max({k, 0}); t < min({(l) + 1, N}); ++t) {







O[i][j][k][l][s][t] += O[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int j = 0; j < N; ++j) {

for (int k = max({i, 0}); k < N; ++k) {

for (int l = 0; l < N; ++l) {

for (int s = max({l, 0}); s < min({(j) + 1, N}); ++s) {

for (int t = max({k, 0}); t < min({(l) + 1, N}); ++t) {







O[i][j][k][l][s][t] += O[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int j = 0; j < N; ++j) {

for (int k = max({i, 0}); k < N; ++k) {

for (int s = 0; s < min({(j) + 1, N}); ++s) {

for (int l = max({j, 0}); l < N; ++l) {

for (int t = max({k, 0}); t < min({(s) + 1, N}); ++t) {







O[i][j][k][l][s][t] += O[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int j = 0; j < N; ++j) {

for (int k = max({i, 0}); k < N; ++k) {

for (int l = 0; l < min({(j) + 1, N}); ++l) {

for (int s = 0; s < min({(l) + 1, N}); ++s) {

for (int t = max({k, 0}); t < min({(s) + 1, N}); ++t) {







O[i][j][k][l][s][t] += O[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int j = 0; j < N; ++j) {

for (int l = max({i, 0}); l < min({(j) + 1, N}); ++l) {

for (int k = max({j, 0}); k < N; ++k) {

for (int s = max({k, 0}); s < N; ++s) {

for (int t = max({s, 0}); t < N; ++t) {







O[i][j][k][l][s][t] += O[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int j = 0; j < N; ++j) {

for (int l = max({i, 0}); l < min({(j) + 1, N}); ++l) {

for (int k = max({j, 0}); k < N; ++k) {

for (int s = 0; s < N; ++s) {

for (int t = max({k, 0}); t < min({(s) + 1, N}); ++t) {







O[i][j][k][l][s][t] += O[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int j = 0; j < N; ++j) {

for (int l = max({i, 0}); l < min({(j) + 1, N}); ++l) {

for (int k = 0; k < N; ++k) {

for (int s = max({j, 0}); s < min({(k) + 1, N}); ++s) {

for (int t = max({k, 0}); t < N; ++t) {







O[i][j][k][l][s][t] += O[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int j = 0; j < N; ++j) {

for (int s = max({j, 0}); s < N; ++s) {

for (int l = max({i, 0}); l < min({(j) + 1, N}); ++l) {

for (int k = 0; k < N; ++k) {

for (int t = max({s, 0}); t < min({(k) + 1, N}); ++t) {







O[i][j][k][l][s][t] += O[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int j = 0; j < N; ++j) {

for (int l = max({i, 0}); l < min({(j) + 1, N}); ++l) {

for (int k = 0; k < N; ++k) {

for (int s = max({k, 0}); s < N; ++s) {

for (int t = max({j, 0}); t < min({(k) + 1, N}); ++t) {







O[i][j][k][l][s][t] += O[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int j = 0; j < N; ++j) {

for (int l = max({i, 0}); l < min({(j) + 1, N}); ++l) {

for (int k = 0; k < N; ++k) {

for (int s = 0; s < min({(k) + 1, N}); ++s) {

for (int t = max({j, 0}); t < min({(s) + 1, N}); ++t) {







O[i][j][k][l][s][t] += O[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int j = 0; j < N; ++j) {

for (int s = max({j, 0}); s < N; ++s) {

for (int k = 0; k < min({(j) + 1, N}); ++k) {

for (int t = max({s, 0}); t < N; ++t) {

for (int l = max({i, 0}); l < min({(k) + 1, N}); ++l) {







O[i][j][k][l][s][t] += O[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int j = 0; j < N; ++j) {

for (int k = 0; k < min({(j) + 1, N}); ++k) {

for (int l = max({i, 0}); l < min({(k) + 1, N}); ++l) {

for (int s = 0; s < N; ++s) {

for (int t = max({j, 0}); t < min({(s) + 1, N}); ++t) {







O[i][j][k][l][s][t] += O[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int j = 0; j < N; ++j) {

for (int t = max({j, 0}); t < N; ++t) {

for (int k = 0; k < N; ++k) {

for (int s = max({k, 0}); s < min({(j) + 1, N}); ++s) {

for (int l = max({i, 0}); l < min({(k) + 1, N}); ++l) {







O[i][j][k][l][s][t] += O[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int j = 0; j < N; ++j) {

for (int k = 0; k < N; ++k) {

for (int s = max({k, 0}); s < N; ++s) {

for (int l = max({i, 0}); l < min({(k) + 1, N}); ++l) {

for (int t = max({s, 0}); t < min({(j) + 1, N}); ++t) {







O[i][j][k][l][s][t] += O[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int j = 0; j < N; ++j) {

for (int s = max({j, 0}); s < N; ++s) {

for (int k = 0; k < N; ++k) {

for (int t = max({k, 0}); t < min({(j) + 1, N}); ++t) {

for (int l = max({i, 0}); l < min({(k) + 1, N}); ++l) {







O[i][j][k][l][s][t] += O[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int j = 0; j < N; ++j) {

for (int s = 0; s < min({(j) + 1, N}); ++s) {

for (int k = 0; k < N; ++k) {

for (int t = max({k, 0}); t < min({(s) + 1, N}); ++t) {

for (int l = max({i, 0}); l < min({(k) + 1, N}); ++l) {







O[i][j][k][l][s][t] += O[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int l = max({i, 0}); l < N; ++l) {

for (int j = 0; j < N; ++j) {

for (int s = max({l, 0}); s < min({(j) + 1, N}); ++s) {

for (int k = max({j, 0}); k < N; ++k) {

for (int t = max({k, 0}); t < N; ++t) {







O[i][j][k][l][s][t] += O[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int l = max({i, 0}); l < N; ++l) {

for (int j = 0; j < N; ++j) {

for (int s = max({l, 0}); s < min({(j) + 1, N}); ++s) {

for (int k = 0; k < N; ++k) {

for (int t = max({j, 0}); t < min({(k) + 1, N}); ++t) {







O[i][j][k][l][s][t] += O[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int l = max({i, 0}); l < N; ++l) {

for (int j = 0; j < N; ++j) {

for (int t = max({j, 0}); t < N; ++t) {

for (int k = 0; k < min({(j) + 1, N}); ++k) {

for (int s = max({l, 0}); s < min({(k) + 1, N}); ++s) {







O[i][j][k][l][s][t] += O[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int l = max({i, 0}); l < N; ++l) {

for (int j = 0; j < N; ++j) {

for (int k = 0; k < N; ++k) {

for (int s = max({l, 0}); s < min({(k) + 1, N}); ++s) {

for (int t = max({k, 0}); t < min({(j) + 1, N}); ++t) {







O[i][j][k][l][s][t] += O[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int l = max({i, 0}); l < N; ++l) {

for (int s = max({l, 0}); s < N; ++s) {

for (int j = 0; j < N; ++j) {

for (int t = max({s, 0}); t < min({(j) + 1, N}); ++t) {

for (int k = max({j, 0}); k < N; ++k) {







O[i][j][k][l][s][t] += O[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int l = max({i, 0}); l < N; ++l) {

for (int s = max({l, 0}); s < N; ++s) {

for (int j = 0; j < N; ++j) {

for (int k = 0; k < min({(j) + 1, N}); ++k) {

for (int t = max({s, 0}); t < min({(k) + 1, N}); ++t) {







O[i][j][k][l][s][t] += O[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int l = max({i, 0}); l < N; ++l) {

for (int j = 0; j < N; ++j) {

for (int t = max({l, 0}); t < min({(j) + 1, N}); ++t) {

for (int k = max({j, 0}); k < N; ++k) {

for (int s = max({k, 0}); s < N; ++s) {







O[i][j][k][l][s][t] += O[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int l = max({i, 0}); l < N; ++l) {

for (int j = 0; j < N; ++j) {

for (int t = max({l, 0}); t < min({(j) + 1, N}); ++t) {

for (int k = 0; k < N; ++k) {

for (int s = max({j, 0}); s < min({(k) + 1, N}); ++s) {







O[i][j][k][l][s][t] += O[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int l = max({i, 0}); l < N; ++l) {

for (int j = 0; j < N; ++j) {

for (int s = max({j, 0}); s < N; ++s) {

for (int k = 0; k < min({(j) + 1, N}); ++k) {

for (int t = max({l, 0}); t < min({(k) + 1, N}); ++t) {







O[i][j][k][l][s][t] += O[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int l = max({i, 0}); l < N; ++l) {

for (int j = 0; j < N; ++j) {

for (int k = 0; k < N; ++k) {

for (int s = max({k, 0}); s < min({(j) + 1, N}); ++s) {

for (int t = max({l, 0}); t < min({(k) + 1, N}); ++t) {







O[i][j][k][l][s][t] += O[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int l = max({i, 0}); l < N; ++l) {

for (int j = 0; j < N; ++j) {

for (int s = 0; s < min({(j) + 1, N}); ++s) {

for (int k = max({j, 0}); k < N; ++k) {

for (int t = max({l, 0}); t < min({(s) + 1, N}); ++t) {







O[i][j][k][l][s][t] += O[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int l = max({i, 0}); l < N; ++l) {

for (int j = 0; j < N; ++j) {

for (int k = 0; k < min({(j) + 1, N}); ++k) {

for (int s = 0; s < min({(k) + 1, N}); ++s) {

for (int t = max({l, 0}); t < min({(s) + 1, N}); ++t) {







O[i][j][k][l][s][t] += O[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int j = 0; j < N; ++j) {

for (int s = max({i, 0}); s < min({(j) + 1, N}); ++s) {

for (int k = max({j, 0}); k < N; ++k) {

for (int l = max({k, 0}); l < N; ++l) {

for (int t = max({l, 0}); t < N; ++t) {







O[i][j][k][l][s][t] += O[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int j = 0; j < N; ++j) {

for (int s = max({i, 0}); s < min({(j) + 1, N}); ++s) {

for (int k = max({j, 0}); k < N; ++k) {

for (int l = 0; l < N; ++l) {

for (int t = max({k, 0}); t < min({(l) + 1, N}); ++t) {







O[i][j][k][l][s][t] += O[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int j = 0; j < N; ++j) {

for (int s = max({i, 0}); s < min({(j) + 1, N}); ++s) {

for (int k = 0; k < N; ++k) {

for (int t = max({k, 0}); t < N; ++t) {

for (int l = max({j, 0}); l < min({(k) + 1, N}); ++l) {







O[i][j][k][l][s][t] += O[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int j = 0; j < N; ++j) {

for (int s = max({i, 0}); s < min({(j) + 1, N}); ++s) {

for (int l = max({j, 0}); l < N; ++l) {

for (int k = 0; k < N; ++k) {

for (int t = max({l, 0}); t < min({(k) + 1, N}); ++t) {







O[i][j][k][l][s][t] += O[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int j = 0; j < N; ++j) {

for (int s = max({i, 0}); s < min({(j) + 1, N}); ++s) {

for (int k = 0; k < N; ++k) {

for (int t = max({j, 0}); t < min({(k) + 1, N}); ++t) {

for (int l = max({k, 0}); l < N; ++l) {







O[i][j][k][l][s][t] += O[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int j = 0; j < N; ++j) {

for (int s = max({i, 0}); s < min({(j) + 1, N}); ++s) {

for (int k = 0; k < N; ++k) {

for (int l = 0; l < min({(k) + 1, N}); ++l) {

for (int t = max({j, 0}); t < min({(l) + 1, N}); ++t) {







O[i][j][k][l][s][t] += O[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int j = 0; j < N; ++j) {

for (int l = max({j, 0}); l < N; ++l) {

for (int k = 0; k < min({(j) + 1, N}); ++k) {

for (int t = max({l, 0}); t < N; ++t) {

for (int s = max({i, 0}); s < min({(k) + 1, N}); ++s) {







O[i][j][k][l][s][t] += O[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int j = 0; j < N; ++j) {

for (int k = 0; k < min({(j) + 1, N}); ++k) {

for (int s = max({i, 0}); s < min({(k) + 1, N}); ++s) {

for (int l = 0; l < N; ++l) {

for (int t = max({j, 0}); t < min({(l) + 1, N}); ++t) {







O[i][j][k][l][s][t] += O[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int j = 0; j < N; ++j) {

for (int t = max({j, 0}); t < N; ++t) {

for (int k = 0; k < N; ++k) {

for (int s = max({i, 0}); s < min({(k) + 1, N}); ++s) {

for (int l = max({k, 0}); l < min({(j) + 1, N}); ++l) {







O[i][j][k][l][s][t] += O[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int j = 0; j < N; ++j) {

for (int k = 0; k < N; ++k) {

for (int s = max({i, 0}); s < min({(k) + 1, N}); ++s) {

for (int l = max({k, 0}); l < N; ++l) {

for (int t = max({l, 0}); t < min({(j) + 1, N}); ++t) {







O[i][j][k][l][s][t] += O[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int j = 0; j < N; ++j) {

for (int l = max({j, 0}); l < N; ++l) {

for (int k = 0; k < N; ++k) {

for (int s = max({i, 0}); s < min({(k) + 1, N}); ++s) {

for (int t = max({k, 0}); t < min({(j) + 1, N}); ++t) {







O[i][j][k][l][s][t] += O[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int j = 0; j < N; ++j) {

for (int l = 0; l < min({(j) + 1, N}); ++l) {

for (int k = 0; k < N; ++k) {

for (int s = max({i, 0}); s < min({(k) + 1, N}); ++s) {

for (int t = max({k, 0}); t < min({(l) + 1, N}); ++t) {







O[i][j][k][l][s][t] += O[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int j = 0; j < N; ++j) {

for (int l = 0; l < min({(j) + 1, N}); ++l) {

for (int k = max({j, 0}); k < N; ++k) {

for (int s = max({i, 0}); s < min({(l) + 1, N}); ++s) {

for (int t = max({k, 0}); t < N; ++t) {







O[i][j][k][l][s][t] += O[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int j = 0; j < N; ++j) {

for (int l = 0; l < min({(j) + 1, N}); ++l) {

for (int s = max({i, 0}); s < min({(l) + 1, N}); ++s) {

for (int k = 0; k < N; ++k) {

for (int t = max({j, 0}); t < min({(k) + 1, N}); ++t) {







O[i][j][k][l][s][t] += O[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int j = 0; j < N; ++j) {

for (int t = max({j, 0}); t < N; ++t) {

for (int k = 0; k < min({(j) + 1, N}); ++k) {

for (int l = 0; l < min({(k) + 1, N}); ++l) {

for (int s = max({i, 0}); s < min({(l) + 1, N}); ++s) {







O[i][j][k][l][s][t] += O[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int j = 0; j < N; ++j) {

for (int k = 0; k < N; ++k) {

for (int t = max({k, 0}); t < min({(j) + 1, N}); ++t) {

for (int l = 0; l < min({(k) + 1, N}); ++l) {

for (int s = max({i, 0}); s < min({(l) + 1, N}); ++s) {







O[i][j][k][l][s][t] += O[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int j = 0; j < N; ++j) {

for (int k = max({j, 0}); k < N; ++k) {

for (int l = 0; l < N; ++l) {

for (int s = max({i, 0}); s < min({(l) + 1, N}); ++s) {

for (int t = max({l, 0}); t < min({(j) + 1, N}); ++t) {







O[i][j][k][l][s][t] += O[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int j = 0; j < N; ++j) {

for (int k = 0; k < min({(j) + 1, N}); ++k) {

for (int l = 0; l < N; ++l) {

for (int s = max({i, 0}); s < min({(l) + 1, N}); ++s) {

for (int t = max({l, 0}); t < min({(k) + 1, N}); ++t) {







O[i][j][k][l][s][t] += O[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int s = max({i, 0}); s < N; ++s) {

for (int j = 0; j < N; ++j) {

for (int t = max({s, 0}); t < min({(j) + 1, N}); ++t) {

for (int k = max({j, 0}); k < N; ++k) {

for (int l = max({k, 0}); l < N; ++l) {







O[i][j][k][l][s][t] += O[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int s = max({i, 0}); s < N; ++s) {

for (int j = 0; j < N; ++j) {

for (int t = max({s, 0}); t < min({(j) + 1, N}); ++t) {

for (int k = 0; k < N; ++k) {

for (int l = max({j, 0}); l < min({(k) + 1, N}); ++l) {







O[i][j][k][l][s][t] += O[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int s = max({i, 0}); s < N; ++s) {

for (int j = 0; j < N; ++j) {

for (int l = max({j, 0}); l < N; ++l) {

for (int k = 0; k < min({(j) + 1, N}); ++k) {

for (int t = max({s, 0}); t < min({(k) + 1, N}); ++t) {







O[i][j][k][l][s][t] += O[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int s = max({i, 0}); s < N; ++s) {

for (int j = 0; j < N; ++j) {

for (int k = 0; k < N; ++k) {

for (int t = max({s, 0}); t < min({(k) + 1, N}); ++t) {

for (int l = max({k, 0}); l < min({(j) + 1, N}); ++l) {







O[i][j][k][l][s][t] += O[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int s = max({i, 0}); s < N; ++s) {

for (int j = 0; j < N; ++j) {

for (int l = 0; l < min({(j) + 1, N}); ++l) {

for (int k = max({j, 0}); k < N; ++k) {

for (int t = max({s, 0}); t < min({(l) + 1, N}); ++t) {







O[i][j][k][l][s][t] += O[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int s = max({i, 0}); s < N; ++s) {

for (int j = 0; j < N; ++j) {

for (int k = 0; k < min({(j) + 1, N}); ++k) {

for (int l = 0; l < min({(k) + 1, N}); ++l) {

for (int t = max({s, 0}); t < min({(l) + 1, N}); ++t) {







O[i][j][k][l][s][t] += O[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int j = 0; j < N; ++j) {

for (int t = max({i, 0}); t < min({(j) + 1, N}); ++t) {

for (int k = max({j, 0}); k < N; ++k) {

for (int l = max({k, 0}); l < N; ++l) {

for (int s = max({l, 0}); s < N; ++s) {







O[i][j][k][l][s][t] += O[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int j = 0; j < N; ++j) {

for (int t = max({i, 0}); t < min({(j) + 1, N}); ++t) {

for (int k = max({j, 0}); k < N; ++k) {

for (int l = 0; l < N; ++l) {

for (int s = max({k, 0}); s < min({(l) + 1, N}); ++s) {







O[i][j][k][l][s][t] += O[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int j = 0; j < N; ++j) {

for (int t = max({i, 0}); t < min({(j) + 1, N}); ++t) {

for (int k = 0; k < N; ++k) {

for (int s = max({k, 0}); s < N; ++s) {

for (int l = max({j, 0}); l < min({(k) + 1, N}); ++l) {







O[i][j][k][l][s][t] += O[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int j = 0; j < N; ++j) {

for (int t = max({i, 0}); t < min({(j) + 1, N}); ++t) {

for (int l = max({j, 0}); l < N; ++l) {

for (int k = 0; k < N; ++k) {

for (int s = max({l, 0}); s < min({(k) + 1, N}); ++s) {







O[i][j][k][l][s][t] += O[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int j = 0; j < N; ++j) {

for (int t = max({i, 0}); t < min({(j) + 1, N}); ++t) {

for (int k = 0; k < N; ++k) {

for (int s = max({j, 0}); s < min({(k) + 1, N}); ++s) {

for (int l = max({k, 0}); l < N; ++l) {







O[i][j][k][l][s][t] += O[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int j = 0; j < N; ++j) {

for (int t = max({i, 0}); t < min({(j) + 1, N}); ++t) {

for (int k = 0; k < N; ++k) {

for (int l = 0; l < min({(k) + 1, N}); ++l) {

for (int s = max({j, 0}); s < min({(l) + 1, N}); ++s) {







O[i][j][k][l][s][t] += O[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int j = 0; j < N; ++j) {

for (int l = max({j, 0}); l < N; ++l) {

for (int k = 0; k < min({(j) + 1, N}); ++k) {

for (int s = max({l, 0}); s < N; ++s) {

for (int t = max({i, 0}); t < min({(k) + 1, N}); ++t) {







O[i][j][k][l][s][t] += O[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int j = 0; j < N; ++j) {

for (int k = 0; k < min({(j) + 1, N}); ++k) {

for (int t = max({i, 0}); t < min({(k) + 1, N}); ++t) {

for (int l = 0; l < N; ++l) {

for (int s = max({j, 0}); s < min({(l) + 1, N}); ++s) {







O[i][j][k][l][s][t] += O[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int j = 0; j < N; ++j) {

for (int s = max({j, 0}); s < N; ++s) {

for (int k = 0; k < N; ++k) {

for (int t = max({i, 0}); t < min({(k) + 1, N}); ++t) {

for (int l = max({k, 0}); l < min({(j) + 1, N}); ++l) {







O[i][j][k][l][s][t] += O[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int j = 0; j < N; ++j) {

for (int k = 0; k < N; ++k) {

for (int t = max({i, 0}); t < min({(k) + 1, N}); ++t) {

for (int l = max({k, 0}); l < N; ++l) {

for (int s = max({l, 0}); s < min({(j) + 1, N}); ++s) {







O[i][j][k][l][s][t] += O[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int j = 0; j < N; ++j) {

for (int l = max({j, 0}); l < N; ++l) {

for (int k = 0; k < N; ++k) {

for (int s = max({k, 0}); s < min({(j) + 1, N}); ++s) {

for (int t = max({i, 0}); t < min({(k) + 1, N}); ++t) {







O[i][j][k][l][s][t] += O[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int j = 0; j < N; ++j) {

for (int l = 0; l < min({(j) + 1, N}); ++l) {

for (int k = 0; k < N; ++k) {

for (int s = max({k, 0}); s < min({(l) + 1, N}); ++s) {

for (int t = max({i, 0}); t < min({(k) + 1, N}); ++t) {







O[i][j][k][l][s][t] += O[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int j = 0; j < N; ++j) {

for (int l = 0; l < min({(j) + 1, N}); ++l) {

for (int k = max({j, 0}); k < N; ++k) {

for (int t = max({i, 0}); t < min({(l) + 1, N}); ++t) {

for (int s = max({k, 0}); s < N; ++s) {







O[i][j][k][l][s][t] += O[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int j = 0; j < N; ++j) {

for (int l = 0; l < min({(j) + 1, N}); ++l) {

for (int t = max({i, 0}); t < min({(l) + 1, N}); ++t) {

for (int k = 0; k < N; ++k) {

for (int s = max({j, 0}); s < min({(k) + 1, N}); ++s) {







O[i][j][k][l][s][t] += O[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int j = 0; j < N; ++j) {

for (int s = max({j, 0}); s < N; ++s) {

for (int k = 0; k < min({(j) + 1, N}); ++k) {

for (int l = 0; l < min({(k) + 1, N}); ++l) {

for (int t = max({i, 0}); t < min({(l) + 1, N}); ++t) {







O[i][j][k][l][s][t] += O[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int j = 0; j < N; ++j) {

for (int k = 0; k < N; ++k) {

for (int s = max({k, 0}); s < min({(j) + 1, N}); ++s) {

for (int l = 0; l < min({(k) + 1, N}); ++l) {

for (int t = max({i, 0}); t < min({(l) + 1, N}); ++t) {







O[i][j][k][l][s][t] += O[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int j = 0; j < N; ++j) {

for (int k = max({j, 0}); k < N; ++k) {

for (int l = 0; l < N; ++l) {

for (int s = max({l, 0}); s < min({(j) + 1, N}); ++s) {

for (int t = max({i, 0}); t < min({(l) + 1, N}); ++t) {







O[i][j][k][l][s][t] += O[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int j = 0; j < N; ++j) {

for (int k = 0; k < min({(j) + 1, N}); ++k) {

for (int l = 0; l < N; ++l) {

for (int s = max({l, 0}); s < min({(k) + 1, N}); ++s) {

for (int t = max({i, 0}); t < min({(l) + 1, N}); ++t) {







O[i][j][k][l][s][t] += O[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int j = 0; j < N; ++j) {

for (int s = 0; s < min({(j) + 1, N}); ++s) {

for (int k = max({j, 0}); k < N; ++k) {

for (int t = max({i, 0}); t < min({(s) + 1, N}); ++t) {

for (int l = max({k, 0}); l < N; ++l) {







O[i][j][k][l][s][t] += O[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int j = 0; j < N; ++j) {

for (int s = 0; s < min({(j) + 1, N}); ++s) {

for (int t = max({i, 0}); t < min({(s) + 1, N}); ++t) {

for (int k = 0; k < N; ++k) {

for (int l = max({j, 0}); l < min({(k) + 1, N}); ++l) {







O[i][j][k][l][s][t] += O[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int j = 0; j < N; ++j) {

for (int l = max({j, 0}); l < N; ++l) {

for (int k = 0; k < min({(j) + 1, N}); ++k) {

for (int s = 0; s < min({(k) + 1, N}); ++s) {

for (int t = max({i, 0}); t < min({(s) + 1, N}); ++t) {







O[i][j][k][l][s][t] += O[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int j = 0; j < N; ++j) {

for (int k = 0; k < N; ++k) {

for (int s = 0; s < min({(k) + 1, N}); ++s) {

for (int l = max({k, 0}); l < min({(j) + 1, N}); ++l) {

for (int t = max({i, 0}); t < min({(s) + 1, N}); ++t) {







O[i][j][k][l][s][t] += O[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int j = 0; j < N; ++j) {

for (int l = 0; l < min({(j) + 1, N}); ++l) {

for (int k = max({j, 0}); k < N; ++k) {

for (int s = 0; s < min({(l) + 1, N}); ++s) {

for (int t = max({i, 0}); t < min({(s) + 1, N}); ++t) {







O[i][j][k][l][s][t] += O[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int j = 0; j < N; ++j) {

for (int k = 0; k < min({(j) + 1, N}); ++k) {

for (int l = 0; l < min({(k) + 1, N}); ++l) {

for (int s = 0; s < min({(l) + 1, N}); ++s) {

for (int t = max({i, 0}); t < min({(s) + 1, N}); ++t) {







O[i][j][k][l][s][t] += O[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
end_reconstruction = duration_cast<microseconds>(system_clock::now().time_since_epoch()).count();
time_reconstruction = end_reconstruction - start_reconstruction;
cout << time_reconstruction << endl;

}