
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

for (int s = max({i, 0}); s < N; ++s) {

for (int j = 0; j < N; ++j) {

for (int k = max({j, 0}); k < N; ++k) {

for (int l = max({k, 0}); l < min({(i) + 1, N}); ++l) {

P[i][j][k][l][s] += I[s][j][k][l][i];
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

P[i][j][k][l][s] += I[i][j][k][s][l];
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

P[i][j][k][l][s] += I[s][j][k][i][l];
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

P[i][j][k][l][s] += I[l][j][k][s][i];
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

P[i][j][k][l][s] += I[l][j][k][i][s];
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

P[i][j][k][l][s] += I[i][j][l][k][s];
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

P[i][j][k][l][s] += I[s][j][l][k][i];
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

P[i][j][k][l][s] += I[i][j][s][k][l];
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

P[i][j][k][l][s] += I[s][j][i][k][l];
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

P[i][j][k][l][s] += I[l][j][s][k][i];
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

P[i][j][k][l][s] += I[l][j][i][k][s];
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

P[i][j][k][l][s] += I[i][j][l][s][k];
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

P[i][j][k][l][s] += I[s][j][l][i][k];
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

P[i][j][k][l][s] += I[i][j][s][l][k];
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

P[i][j][k][l][s] += I[s][j][i][l][k];
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

P[i][j][k][l][s] += I[l][j][s][i][k];
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

P[i][j][k][l][s] += I[l][j][i][s][k];
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

P[i][j][k][l][s] += I[k][j][l][s][i];
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

P[i][j][k][l][s] += I[k][j][l][i][s];
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

P[i][j][k][l][s] += I[k][j][s][l][i];
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

P[i][j][k][l][s] += I[k][j][i][l][s];
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

P[i][j][k][l][s] += I[k][j][s][i][l];
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

P[i][j][k][l][s] += I[k][j][i][s][l];
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

P[i][j][k][l][s] += I[i][k][j][l][s];
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

P[i][j][k][l][s] += I[s][k][j][l][i];
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

P[i][j][k][l][s] += I[i][k][j][s][l];
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

P[i][j][k][l][s] += I[s][k][j][i][l];
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

P[i][j][k][l][s] += I[l][k][j][s][i];
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

P[i][j][k][l][s] += I[l][k][j][i][s];
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

P[i][j][k][l][s] += I[i][l][j][k][s];
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

P[i][j][k][l][s] += I[s][l][j][k][i];
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

P[i][j][k][l][s] += I[i][s][j][k][l];
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

P[i][j][k][l][s] += I[s][i][j][k][l];
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

P[i][j][k][l][s] += I[l][s][j][k][i];
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

P[i][j][k][l][s] += I[l][i][j][k][s];
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

P[i][j][k][l][s] += I[i][l][j][s][k];
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

P[i][j][k][l][s] += I[s][l][j][i][k];
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

P[i][j][k][l][s] += I[i][s][j][l][k];
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

P[i][j][k][l][s] += I[s][i][j][l][k];
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

P[i][j][k][l][s] += I[l][s][j][i][k];
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

P[i][j][k][l][s] += I[l][i][j][s][k];
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

P[i][j][k][l][s] += I[k][l][j][s][i];
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

P[i][j][k][l][s] += I[k][l][j][i][s];
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

P[i][j][k][l][s] += I[k][s][j][l][i];
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

P[i][j][k][l][s] += I[k][i][j][l][s];
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

P[i][j][k][l][s] += I[k][s][j][i][l];
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

P[i][j][k][l][s] += I[k][i][j][s][l];
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

P[i][j][k][l][s] += I[i][k][l][j][s];
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

P[i][j][k][l][s] += I[s][k][l][j][i];
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

P[i][j][k][l][s] += I[i][k][s][j][l];
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

P[i][j][k][l][s] += I[s][k][i][j][l];
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

P[i][j][k][l][s] += I[l][k][s][j][i];
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

P[i][j][k][l][s] += I[l][k][i][j][s];
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

P[i][j][k][l][s] += I[i][l][k][j][s];
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

P[i][j][k][l][s] += I[s][l][k][j][i];
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

P[i][j][k][l][s] += I[i][s][k][j][l];
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

P[i][j][k][l][s] += I[s][i][k][j][l];
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

P[i][j][k][l][s] += I[l][s][k][j][i];
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

P[i][j][k][l][s] += I[l][i][k][j][s];
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

P[i][j][k][l][s] += I[i][l][s][j][k];
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

P[i][j][k][l][s] += I[s][l][i][j][k];
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

P[i][j][k][l][s] += I[i][s][l][j][k];
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

P[i][j][k][l][s] += I[s][i][l][j][k];
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

P[i][j][k][l][s] += I[l][s][i][j][k];
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

P[i][j][k][l][s] += I[l][i][s][j][k];
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

P[i][j][k][l][s] += I[k][l][s][j][i];
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

P[i][j][k][l][s] += I[k][l][i][j][s];
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

P[i][j][k][l][s] += I[k][s][l][j][i];
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

P[i][j][k][l][s] += I[k][i][l][j][s];
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

P[i][j][k][l][s] += I[k][s][i][j][l];
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

P[i][j][k][l][s] += I[k][i][s][j][l];
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

P[i][j][k][l][s] += I[i][k][l][s][j];
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

P[i][j][k][l][s] += I[s][k][l][i][j];
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

P[i][j][k][l][s] += I[i][k][s][l][j];
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

P[i][j][k][l][s] += I[s][k][i][l][j];
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

P[i][j][k][l][s] += I[l][k][s][i][j];
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

P[i][j][k][l][s] += I[l][k][i][s][j];
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

P[i][j][k][l][s] += I[i][l][k][s][j];
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

P[i][j][k][l][s] += I[s][l][k][i][j];
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

P[i][j][k][l][s] += I[i][s][k][l][j];
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

P[i][j][k][l][s] += I[s][i][k][l][j];
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

P[i][j][k][l][s] += I[l][s][k][i][j];
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

P[i][j][k][l][s] += I[l][i][k][s][j];
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

P[i][j][k][l][s] += I[i][l][s][k][j];
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

P[i][j][k][l][s] += I[s][l][i][k][j];
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

P[i][j][k][l][s] += I[i][s][l][k][j];
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

P[i][j][k][l][s] += I[s][i][l][k][j];
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

P[i][j][k][l][s] += I[l][s][i][k][j];
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

P[i][j][k][l][s] += I[l][i][s][k][j];
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

P[i][j][k][l][s] += I[k][l][s][i][j];
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

P[i][j][k][l][s] += I[k][l][i][s][j];
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

P[i][j][k][l][s] += I[k][s][l][i][j];
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

P[i][j][k][l][s] += I[k][i][l][s][j];
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

P[i][j][k][l][s] += I[k][s][i][l][j];
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

P[i][j][k][l][s] += I[k][i][s][l][j];
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

P[i][j][k][l][s] += I[j][k][l][s][i];
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

P[i][j][k][l][s] += I[j][k][l][i][s];
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

P[i][j][k][l][s] += I[j][k][s][l][i];
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

P[i][j][k][l][s] += I[j][k][i][l][s];
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

P[i][j][k][l][s] += I[j][k][s][i][l];
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

P[i][j][k][l][s] += I[j][k][i][s][l];
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

P[i][j][k][l][s] += I[j][l][k][s][i];
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

P[i][j][k][l][s] += I[j][l][k][i][s];
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

P[i][j][k][l][s] += I[j][s][k][l][i];
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

P[i][j][k][l][s] += I[j][i][k][l][s];
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

P[i][j][k][l][s] += I[j][s][k][i][l];
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

P[i][j][k][l][s] += I[j][i][k][s][l];
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

P[i][j][k][l][s] += I[j][l][s][k][i];
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

P[i][j][k][l][s] += I[j][l][i][k][s];
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

P[i][j][k][l][s] += I[j][s][l][k][i];
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

P[i][j][k][l][s] += I[j][i][l][k][s];
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

P[i][j][k][l][s] += I[j][s][i][k][l];
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

P[i][j][k][l][s] += I[j][i][s][k][l];
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

P[i][j][k][l][s] += I[j][l][s][i][k];
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

P[i][j][k][l][s] += I[j][l][i][s][k];
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

P[i][j][k][l][s] += I[j][s][l][i][k];
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

P[i][j][k][l][s] += I[j][i][l][s][k];
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

P[i][j][k][l][s] += I[j][s][i][l][k];
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

P[i][j][k][l][s] += I[j][i][s][l][k];
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
for (int i = 0; i < N; ++i) {

for (int t = max({i, 0}); t < N; ++t) {

for (int j = 0; j < N; ++j) {

for (int k = max({j, 0}); k < N; ++k) {

for (int l = max({k, 0}); l < N; ++l) {

for (int s = max({l, 0}); s < min({(i) + 1, N}); ++s) {

O[i][j][k][l][s][t] += E[t][j][k][l][s][i];
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

O[i][j][k][l][s][t] += E[i][j][k][l][t][s];
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

O[i][j][k][l][s][t] += E[t][j][k][l][i][s];
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

O[i][j][k][l][s][t] += E[s][j][k][l][t][i];
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

O[i][j][k][l][s][t] += E[s][j][k][l][i][t];
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

O[i][j][k][l][s][t] += E[i][j][k][s][l][t];
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

O[i][j][k][l][s][t] += E[t][j][k][s][l][i];
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

O[i][j][k][l][s][t] += E[i][j][k][t][l][s];
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

O[i][j][k][l][s][t] += E[t][j][k][i][l][s];
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

O[i][j][k][l][s][t] += E[s][j][k][t][l][i];
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

O[i][j][k][l][s][t] += E[s][j][k][i][l][t];
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

O[i][j][k][l][s][t] += E[i][j][k][s][t][l];
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

O[i][j][k][l][s][t] += E[t][j][k][s][i][l];
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

O[i][j][k][l][s][t] += E[i][j][k][t][s][l];
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

O[i][j][k][l][s][t] += E[t][j][k][i][s][l];
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

O[i][j][k][l][s][t] += E[s][j][k][t][i][l];
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

O[i][j][k][l][s][t] += E[s][j][k][i][t][l];
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

O[i][j][k][l][s][t] += E[l][j][k][s][t][i];
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

O[i][j][k][l][s][t] += E[l][j][k][s][i][t];
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

O[i][j][k][l][s][t] += E[l][j][k][t][s][i];
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

O[i][j][k][l][s][t] += E[l][j][k][i][s][t];
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

O[i][j][k][l][s][t] += E[l][j][k][t][i][s];
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

O[i][j][k][l][s][t] += E[l][j][k][i][t][s];
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

O[i][j][k][l][s][t] += E[i][j][l][k][s][t];
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

O[i][j][k][l][s][t] += E[t][j][l][k][s][i];
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

O[i][j][k][l][s][t] += E[i][j][l][k][t][s];
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

O[i][j][k][l][s][t] += E[t][j][l][k][i][s];
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

O[i][j][k][l][s][t] += E[s][j][l][k][t][i];
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

O[i][j][k][l][s][t] += E[s][j][l][k][i][t];
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

O[i][j][k][l][s][t] += E[i][j][s][k][l][t];
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

O[i][j][k][l][s][t] += E[t][j][s][k][l][i];
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

O[i][j][k][l][s][t] += E[i][j][t][k][l][s];
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

O[i][j][k][l][s][t] += E[t][j][i][k][l][s];
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

O[i][j][k][l][s][t] += E[s][j][t][k][l][i];
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

O[i][j][k][l][s][t] += E[s][j][i][k][l][t];
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

O[i][j][k][l][s][t] += E[i][j][s][k][t][l];
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

O[i][j][k][l][s][t] += E[t][j][s][k][i][l];
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

O[i][j][k][l][s][t] += E[i][j][t][k][s][l];
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

O[i][j][k][l][s][t] += E[t][j][i][k][s][l];
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

O[i][j][k][l][s][t] += E[s][j][t][k][i][l];
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

O[i][j][k][l][s][t] += E[s][j][i][k][t][l];
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

O[i][j][k][l][s][t] += E[l][j][s][k][t][i];
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

O[i][j][k][l][s][t] += E[l][j][s][k][i][t];
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

O[i][j][k][l][s][t] += E[l][j][t][k][s][i];
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

O[i][j][k][l][s][t] += E[l][j][i][k][s][t];
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

O[i][j][k][l][s][t] += E[l][j][t][k][i][s];
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

O[i][j][k][l][s][t] += E[l][j][i][k][t][s];
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

O[i][j][k][l][s][t] += E[i][j][l][s][k][t];
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

O[i][j][k][l][s][t] += E[t][j][l][s][k][i];
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

O[i][j][k][l][s][t] += E[i][j][l][t][k][s];
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

O[i][j][k][l][s][t] += E[t][j][l][i][k][s];
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

O[i][j][k][l][s][t] += E[s][j][l][t][k][i];
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

O[i][j][k][l][s][t] += E[s][j][l][i][k][t];
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

O[i][j][k][l][s][t] += E[i][j][s][l][k][t];
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

O[i][j][k][l][s][t] += E[t][j][s][l][k][i];
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

O[i][j][k][l][s][t] += E[i][j][t][l][k][s];
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

O[i][j][k][l][s][t] += E[t][j][i][l][k][s];
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

O[i][j][k][l][s][t] += E[s][j][t][l][k][i];
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

O[i][j][k][l][s][t] += E[s][j][i][l][k][t];
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

O[i][j][k][l][s][t] += E[i][j][s][t][k][l];
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

O[i][j][k][l][s][t] += E[t][j][s][i][k][l];
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

O[i][j][k][l][s][t] += E[i][j][t][s][k][l];
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

O[i][j][k][l][s][t] += E[t][j][i][s][k][l];
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

O[i][j][k][l][s][t] += E[s][j][t][i][k][l];
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

O[i][j][k][l][s][t] += E[s][j][i][t][k][l];
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

O[i][j][k][l][s][t] += E[l][j][s][t][k][i];
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

O[i][j][k][l][s][t] += E[l][j][s][i][k][t];
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

O[i][j][k][l][s][t] += E[l][j][t][s][k][i];
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

O[i][j][k][l][s][t] += E[l][j][i][s][k][t];
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

O[i][j][k][l][s][t] += E[l][j][t][i][k][s];
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

O[i][j][k][l][s][t] += E[l][j][i][t][k][s];
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

O[i][j][k][l][s][t] += E[i][j][l][s][t][k];
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

O[i][j][k][l][s][t] += E[t][j][l][s][i][k];
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

O[i][j][k][l][s][t] += E[i][j][l][t][s][k];
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

O[i][j][k][l][s][t] += E[t][j][l][i][s][k];
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

O[i][j][k][l][s][t] += E[s][j][l][t][i][k];
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

O[i][j][k][l][s][t] += E[s][j][l][i][t][k];
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

O[i][j][k][l][s][t] += E[i][j][s][l][t][k];
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

O[i][j][k][l][s][t] += E[t][j][s][l][i][k];
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

O[i][j][k][l][s][t] += E[i][j][t][l][s][k];
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

O[i][j][k][l][s][t] += E[t][j][i][l][s][k];
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

O[i][j][k][l][s][t] += E[s][j][t][l][i][k];
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

O[i][j][k][l][s][t] += E[s][j][i][l][t][k];
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

O[i][j][k][l][s][t] += E[i][j][s][t][l][k];
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

O[i][j][k][l][s][t] += E[t][j][s][i][l][k];
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

O[i][j][k][l][s][t] += E[i][j][t][s][l][k];
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

O[i][j][k][l][s][t] += E[t][j][i][s][l][k];
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

O[i][j][k][l][s][t] += E[s][j][t][i][l][k];
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

O[i][j][k][l][s][t] += E[s][j][i][t][l][k];
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

O[i][j][k][l][s][t] += E[l][j][s][t][i][k];
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

O[i][j][k][l][s][t] += E[l][j][s][i][t][k];
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

O[i][j][k][l][s][t] += E[l][j][t][s][i][k];
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

O[i][j][k][l][s][t] += E[l][j][i][s][t][k];
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

O[i][j][k][l][s][t] += E[l][j][t][i][s][k];
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

O[i][j][k][l][s][t] += E[l][j][i][t][s][k];
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

O[i][j][k][l][s][t] += E[k][j][l][s][t][i];
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

O[i][j][k][l][s][t] += E[k][j][l][s][i][t];
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

O[i][j][k][l][s][t] += E[k][j][l][t][s][i];
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

O[i][j][k][l][s][t] += E[k][j][l][i][s][t];
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

O[i][j][k][l][s][t] += E[k][j][l][t][i][s];
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

O[i][j][k][l][s][t] += E[k][j][l][i][t][s];
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

O[i][j][k][l][s][t] += E[k][j][s][l][t][i];
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

O[i][j][k][l][s][t] += E[k][j][s][l][i][t];
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

O[i][j][k][l][s][t] += E[k][j][t][l][s][i];
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

O[i][j][k][l][s][t] += E[k][j][i][l][s][t];
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

O[i][j][k][l][s][t] += E[k][j][t][l][i][s];
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

O[i][j][k][l][s][t] += E[k][j][i][l][t][s];
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

O[i][j][k][l][s][t] += E[k][j][s][t][l][i];
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

O[i][j][k][l][s][t] += E[k][j][s][i][l][t];
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

O[i][j][k][l][s][t] += E[k][j][t][s][l][i];
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

O[i][j][k][l][s][t] += E[k][j][i][s][l][t];
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

O[i][j][k][l][s][t] += E[k][j][t][i][l][s];
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

O[i][j][k][l][s][t] += E[k][j][i][t][l][s];
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

O[i][j][k][l][s][t] += E[k][j][s][t][i][l];
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

O[i][j][k][l][s][t] += E[k][j][s][i][t][l];
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

O[i][j][k][l][s][t] += E[k][j][t][s][i][l];
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

O[i][j][k][l][s][t] += E[k][j][i][s][t][l];
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

O[i][j][k][l][s][t] += E[k][j][t][i][s][l];
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

O[i][j][k][l][s][t] += E[k][j][i][t][s][l];
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

O[i][j][k][l][s][t] += E[i][k][j][l][s][t];
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

O[i][j][k][l][s][t] += E[t][k][j][l][s][i];
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

O[i][j][k][l][s][t] += E[i][k][j][l][t][s];
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

O[i][j][k][l][s][t] += E[t][k][j][l][i][s];
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

O[i][j][k][l][s][t] += E[s][k][j][l][t][i];
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

O[i][j][k][l][s][t] += E[s][k][j][l][i][t];
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

O[i][j][k][l][s][t] += E[i][k][j][s][l][t];
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

O[i][j][k][l][s][t] += E[t][k][j][s][l][i];
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

O[i][j][k][l][s][t] += E[i][k][j][t][l][s];
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

O[i][j][k][l][s][t] += E[t][k][j][i][l][s];
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

O[i][j][k][l][s][t] += E[s][k][j][t][l][i];
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

O[i][j][k][l][s][t] += E[s][k][j][i][l][t];
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

O[i][j][k][l][s][t] += E[i][k][j][s][t][l];
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

O[i][j][k][l][s][t] += E[t][k][j][s][i][l];
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

O[i][j][k][l][s][t] += E[i][k][j][t][s][l];
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

O[i][j][k][l][s][t] += E[t][k][j][i][s][l];
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

O[i][j][k][l][s][t] += E[s][k][j][t][i][l];
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

O[i][j][k][l][s][t] += E[s][k][j][i][t][l];
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

O[i][j][k][l][s][t] += E[l][k][j][s][t][i];
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

O[i][j][k][l][s][t] += E[l][k][j][s][i][t];
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

O[i][j][k][l][s][t] += E[l][k][j][t][s][i];
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

O[i][j][k][l][s][t] += E[l][k][j][i][s][t];
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

O[i][j][k][l][s][t] += E[l][k][j][t][i][s];
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

O[i][j][k][l][s][t] += E[l][k][j][i][t][s];
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

O[i][j][k][l][s][t] += E[i][l][j][k][s][t];
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

O[i][j][k][l][s][t] += E[t][l][j][k][s][i];
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

O[i][j][k][l][s][t] += E[i][l][j][k][t][s];
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

O[i][j][k][l][s][t] += E[t][l][j][k][i][s];
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

O[i][j][k][l][s][t] += E[s][l][j][k][t][i];
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

O[i][j][k][l][s][t] += E[s][l][j][k][i][t];
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

O[i][j][k][l][s][t] += E[i][s][j][k][l][t];
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

O[i][j][k][l][s][t] += E[t][s][j][k][l][i];
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

O[i][j][k][l][s][t] += E[i][t][j][k][l][s];
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

O[i][j][k][l][s][t] += E[t][i][j][k][l][s];
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

O[i][j][k][l][s][t] += E[s][t][j][k][l][i];
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

O[i][j][k][l][s][t] += E[s][i][j][k][l][t];
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

O[i][j][k][l][s][t] += E[i][s][j][k][t][l];
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

O[i][j][k][l][s][t] += E[t][s][j][k][i][l];
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

O[i][j][k][l][s][t] += E[i][t][j][k][s][l];
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

O[i][j][k][l][s][t] += E[t][i][j][k][s][l];
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

O[i][j][k][l][s][t] += E[s][t][j][k][i][l];
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

O[i][j][k][l][s][t] += E[s][i][j][k][t][l];
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

O[i][j][k][l][s][t] += E[l][s][j][k][t][i];
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

O[i][j][k][l][s][t] += E[l][s][j][k][i][t];
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

O[i][j][k][l][s][t] += E[l][t][j][k][s][i];
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

O[i][j][k][l][s][t] += E[l][i][j][k][s][t];
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

O[i][j][k][l][s][t] += E[l][t][j][k][i][s];
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

O[i][j][k][l][s][t] += E[l][i][j][k][t][s];
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

O[i][j][k][l][s][t] += E[i][l][j][s][k][t];
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

O[i][j][k][l][s][t] += E[t][l][j][s][k][i];
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

O[i][j][k][l][s][t] += E[i][l][j][t][k][s];
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

O[i][j][k][l][s][t] += E[t][l][j][i][k][s];
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

O[i][j][k][l][s][t] += E[s][l][j][t][k][i];
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

O[i][j][k][l][s][t] += E[s][l][j][i][k][t];
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

O[i][j][k][l][s][t] += E[i][s][j][l][k][t];
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

O[i][j][k][l][s][t] += E[t][s][j][l][k][i];
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

O[i][j][k][l][s][t] += E[i][t][j][l][k][s];
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

O[i][j][k][l][s][t] += E[t][i][j][l][k][s];
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

O[i][j][k][l][s][t] += E[s][t][j][l][k][i];
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

O[i][j][k][l][s][t] += E[s][i][j][l][k][t];
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

O[i][j][k][l][s][t] += E[i][s][j][t][k][l];
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

O[i][j][k][l][s][t] += E[t][s][j][i][k][l];
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

O[i][j][k][l][s][t] += E[i][t][j][s][k][l];
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

O[i][j][k][l][s][t] += E[t][i][j][s][k][l];
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

O[i][j][k][l][s][t] += E[s][t][j][i][k][l];
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

O[i][j][k][l][s][t] += E[s][i][j][t][k][l];
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

O[i][j][k][l][s][t] += E[l][s][j][t][k][i];
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

O[i][j][k][l][s][t] += E[l][s][j][i][k][t];
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

O[i][j][k][l][s][t] += E[l][t][j][s][k][i];
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

O[i][j][k][l][s][t] += E[l][i][j][s][k][t];
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

O[i][j][k][l][s][t] += E[l][t][j][i][k][s];
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

O[i][j][k][l][s][t] += E[l][i][j][t][k][s];
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

O[i][j][k][l][s][t] += E[i][l][j][s][t][k];
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

O[i][j][k][l][s][t] += E[t][l][j][s][i][k];
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

O[i][j][k][l][s][t] += E[i][l][j][t][s][k];
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

O[i][j][k][l][s][t] += E[t][l][j][i][s][k];
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

O[i][j][k][l][s][t] += E[s][l][j][t][i][k];
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

O[i][j][k][l][s][t] += E[s][l][j][i][t][k];
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

O[i][j][k][l][s][t] += E[i][s][j][l][t][k];
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

O[i][j][k][l][s][t] += E[t][s][j][l][i][k];
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

O[i][j][k][l][s][t] += E[i][t][j][l][s][k];
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

O[i][j][k][l][s][t] += E[t][i][j][l][s][k];
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

O[i][j][k][l][s][t] += E[s][t][j][l][i][k];
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

O[i][j][k][l][s][t] += E[s][i][j][l][t][k];
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

O[i][j][k][l][s][t] += E[i][s][j][t][l][k];
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

O[i][j][k][l][s][t] += E[t][s][j][i][l][k];
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

O[i][j][k][l][s][t] += E[i][t][j][s][l][k];
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

O[i][j][k][l][s][t] += E[t][i][j][s][l][k];
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

O[i][j][k][l][s][t] += E[s][t][j][i][l][k];
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

O[i][j][k][l][s][t] += E[s][i][j][t][l][k];
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

O[i][j][k][l][s][t] += E[l][s][j][t][i][k];
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

O[i][j][k][l][s][t] += E[l][s][j][i][t][k];
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

O[i][j][k][l][s][t] += E[l][t][j][s][i][k];
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

O[i][j][k][l][s][t] += E[l][i][j][s][t][k];
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

O[i][j][k][l][s][t] += E[l][t][j][i][s][k];
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

O[i][j][k][l][s][t] += E[l][i][j][t][s][k];
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

O[i][j][k][l][s][t] += E[k][l][j][s][t][i];
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

O[i][j][k][l][s][t] += E[k][l][j][s][i][t];
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

O[i][j][k][l][s][t] += E[k][l][j][t][s][i];
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

O[i][j][k][l][s][t] += E[k][l][j][i][s][t];
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

O[i][j][k][l][s][t] += E[k][l][j][t][i][s];
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

O[i][j][k][l][s][t] += E[k][l][j][i][t][s];
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

O[i][j][k][l][s][t] += E[k][s][j][l][t][i];
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

O[i][j][k][l][s][t] += E[k][s][j][l][i][t];
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

O[i][j][k][l][s][t] += E[k][t][j][l][s][i];
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

O[i][j][k][l][s][t] += E[k][i][j][l][s][t];
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

O[i][j][k][l][s][t] += E[k][t][j][l][i][s];
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

O[i][j][k][l][s][t] += E[k][i][j][l][t][s];
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

O[i][j][k][l][s][t] += E[k][s][j][t][l][i];
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

O[i][j][k][l][s][t] += E[k][s][j][i][l][t];
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

O[i][j][k][l][s][t] += E[k][t][j][s][l][i];
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

O[i][j][k][l][s][t] += E[k][i][j][s][l][t];
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

O[i][j][k][l][s][t] += E[k][t][j][i][l][s];
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

O[i][j][k][l][s][t] += E[k][i][j][t][l][s];
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

O[i][j][k][l][s][t] += E[k][s][j][t][i][l];
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

O[i][j][k][l][s][t] += E[k][s][j][i][t][l];
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

O[i][j][k][l][s][t] += E[k][t][j][s][i][l];
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

O[i][j][k][l][s][t] += E[k][i][j][s][t][l];
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

O[i][j][k][l][s][t] += E[k][t][j][i][s][l];
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

O[i][j][k][l][s][t] += E[k][i][j][t][s][l];
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

O[i][j][k][l][s][t] += E[i][k][l][j][s][t];
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

O[i][j][k][l][s][t] += E[t][k][l][j][s][i];
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

O[i][j][k][l][s][t] += E[i][k][l][j][t][s];
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

O[i][j][k][l][s][t] += E[t][k][l][j][i][s];
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

O[i][j][k][l][s][t] += E[s][k][l][j][t][i];
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

O[i][j][k][l][s][t] += E[s][k][l][j][i][t];
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

O[i][j][k][l][s][t] += E[i][k][s][j][l][t];
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

O[i][j][k][l][s][t] += E[t][k][s][j][l][i];
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

O[i][j][k][l][s][t] += E[i][k][t][j][l][s];
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

O[i][j][k][l][s][t] += E[t][k][i][j][l][s];
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

O[i][j][k][l][s][t] += E[s][k][t][j][l][i];
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

O[i][j][k][l][s][t] += E[s][k][i][j][l][t];
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

O[i][j][k][l][s][t] += E[i][k][s][j][t][l];
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

O[i][j][k][l][s][t] += E[t][k][s][j][i][l];
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

O[i][j][k][l][s][t] += E[i][k][t][j][s][l];
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

O[i][j][k][l][s][t] += E[t][k][i][j][s][l];
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

O[i][j][k][l][s][t] += E[s][k][t][j][i][l];
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

O[i][j][k][l][s][t] += E[s][k][i][j][t][l];
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

O[i][j][k][l][s][t] += E[l][k][s][j][t][i];
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

O[i][j][k][l][s][t] += E[l][k][s][j][i][t];
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

O[i][j][k][l][s][t] += E[l][k][t][j][s][i];
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

O[i][j][k][l][s][t] += E[l][k][i][j][s][t];
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

O[i][j][k][l][s][t] += E[l][k][t][j][i][s];
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

O[i][j][k][l][s][t] += E[l][k][i][j][t][s];
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

O[i][j][k][l][s][t] += E[i][l][k][j][s][t];
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

O[i][j][k][l][s][t] += E[t][l][k][j][s][i];
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

O[i][j][k][l][s][t] += E[i][l][k][j][t][s];
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

O[i][j][k][l][s][t] += E[t][l][k][j][i][s];
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

O[i][j][k][l][s][t] += E[s][l][k][j][t][i];
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

O[i][j][k][l][s][t] += E[s][l][k][j][i][t];
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

O[i][j][k][l][s][t] += E[i][s][k][j][l][t];
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

O[i][j][k][l][s][t] += E[t][s][k][j][l][i];
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

O[i][j][k][l][s][t] += E[i][t][k][j][l][s];
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

O[i][j][k][l][s][t] += E[t][i][k][j][l][s];
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

O[i][j][k][l][s][t] += E[s][t][k][j][l][i];
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

O[i][j][k][l][s][t] += E[s][i][k][j][l][t];
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

O[i][j][k][l][s][t] += E[i][s][k][j][t][l];
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

O[i][j][k][l][s][t] += E[t][s][k][j][i][l];
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

O[i][j][k][l][s][t] += E[i][t][k][j][s][l];
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

O[i][j][k][l][s][t] += E[t][i][k][j][s][l];
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

O[i][j][k][l][s][t] += E[s][t][k][j][i][l];
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

O[i][j][k][l][s][t] += E[s][i][k][j][t][l];
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

O[i][j][k][l][s][t] += E[l][s][k][j][t][i];
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

O[i][j][k][l][s][t] += E[l][s][k][j][i][t];
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

O[i][j][k][l][s][t] += E[l][t][k][j][s][i];
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

O[i][j][k][l][s][t] += E[l][i][k][j][s][t];
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

O[i][j][k][l][s][t] += E[l][t][k][j][i][s];
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

O[i][j][k][l][s][t] += E[l][i][k][j][t][s];
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

O[i][j][k][l][s][t] += E[i][l][s][j][k][t];
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

O[i][j][k][l][s][t] += E[t][l][s][j][k][i];
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

O[i][j][k][l][s][t] += E[i][l][t][j][k][s];
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

O[i][j][k][l][s][t] += E[t][l][i][j][k][s];
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

O[i][j][k][l][s][t] += E[s][l][t][j][k][i];
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

O[i][j][k][l][s][t] += E[s][l][i][j][k][t];
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

O[i][j][k][l][s][t] += E[i][s][l][j][k][t];
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

O[i][j][k][l][s][t] += E[t][s][l][j][k][i];
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

O[i][j][k][l][s][t] += E[i][t][l][j][k][s];
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

O[i][j][k][l][s][t] += E[t][i][l][j][k][s];
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

O[i][j][k][l][s][t] += E[s][t][l][j][k][i];
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

O[i][j][k][l][s][t] += E[s][i][l][j][k][t];
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

O[i][j][k][l][s][t] += E[i][s][t][j][k][l];
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

O[i][j][k][l][s][t] += E[t][s][i][j][k][l];
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

O[i][j][k][l][s][t] += E[i][t][s][j][k][l];
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

O[i][j][k][l][s][t] += E[t][i][s][j][k][l];
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

O[i][j][k][l][s][t] += E[s][t][i][j][k][l];
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

O[i][j][k][l][s][t] += E[s][i][t][j][k][l];
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

O[i][j][k][l][s][t] += E[l][s][t][j][k][i];
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

O[i][j][k][l][s][t] += E[l][s][i][j][k][t];
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

O[i][j][k][l][s][t] += E[l][t][s][j][k][i];
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

O[i][j][k][l][s][t] += E[l][i][s][j][k][t];
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

O[i][j][k][l][s][t] += E[l][t][i][j][k][s];
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

O[i][j][k][l][s][t] += E[l][i][t][j][k][s];
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

O[i][j][k][l][s][t] += E[i][l][s][j][t][k];
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

O[i][j][k][l][s][t] += E[t][l][s][j][i][k];
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

O[i][j][k][l][s][t] += E[i][l][t][j][s][k];
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

O[i][j][k][l][s][t] += E[t][l][i][j][s][k];
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

O[i][j][k][l][s][t] += E[s][l][t][j][i][k];
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

O[i][j][k][l][s][t] += E[s][l][i][j][t][k];
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

O[i][j][k][l][s][t] += E[i][s][l][j][t][k];
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

O[i][j][k][l][s][t] += E[t][s][l][j][i][k];
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

O[i][j][k][l][s][t] += E[i][t][l][j][s][k];
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

O[i][j][k][l][s][t] += E[t][i][l][j][s][k];
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

O[i][j][k][l][s][t] += E[s][t][l][j][i][k];
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

O[i][j][k][l][s][t] += E[s][i][l][j][t][k];
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

O[i][j][k][l][s][t] += E[i][s][t][j][l][k];
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

O[i][j][k][l][s][t] += E[t][s][i][j][l][k];
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

O[i][j][k][l][s][t] += E[i][t][s][j][l][k];
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

O[i][j][k][l][s][t] += E[t][i][s][j][l][k];
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

O[i][j][k][l][s][t] += E[s][t][i][j][l][k];
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

O[i][j][k][l][s][t] += E[s][i][t][j][l][k];
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

O[i][j][k][l][s][t] += E[l][s][t][j][i][k];
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

O[i][j][k][l][s][t] += E[l][s][i][j][t][k];
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

O[i][j][k][l][s][t] += E[l][t][s][j][i][k];
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

O[i][j][k][l][s][t] += E[l][i][s][j][t][k];
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

O[i][j][k][l][s][t] += E[l][t][i][j][s][k];
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

O[i][j][k][l][s][t] += E[l][i][t][j][s][k];
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

O[i][j][k][l][s][t] += E[k][l][s][j][t][i];
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

O[i][j][k][l][s][t] += E[k][l][s][j][i][t];
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

O[i][j][k][l][s][t] += E[k][l][t][j][s][i];
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

O[i][j][k][l][s][t] += E[k][l][i][j][s][t];
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

O[i][j][k][l][s][t] += E[k][l][t][j][i][s];
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

O[i][j][k][l][s][t] += E[k][l][i][j][t][s];
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

O[i][j][k][l][s][t] += E[k][s][l][j][t][i];
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

O[i][j][k][l][s][t] += E[k][s][l][j][i][t];
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

O[i][j][k][l][s][t] += E[k][t][l][j][s][i];
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

O[i][j][k][l][s][t] += E[k][i][l][j][s][t];
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

O[i][j][k][l][s][t] += E[k][t][l][j][i][s];
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

O[i][j][k][l][s][t] += E[k][i][l][j][t][s];
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

O[i][j][k][l][s][t] += E[k][s][t][j][l][i];
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

O[i][j][k][l][s][t] += E[k][s][i][j][l][t];
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

O[i][j][k][l][s][t] += E[k][t][s][j][l][i];
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

O[i][j][k][l][s][t] += E[k][i][s][j][l][t];
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

O[i][j][k][l][s][t] += E[k][t][i][j][l][s];
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

O[i][j][k][l][s][t] += E[k][i][t][j][l][s];
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

O[i][j][k][l][s][t] += E[k][s][t][j][i][l];
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

O[i][j][k][l][s][t] += E[k][s][i][j][t][l];
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

O[i][j][k][l][s][t] += E[k][t][s][j][i][l];
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

O[i][j][k][l][s][t] += E[k][i][s][j][t][l];
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

O[i][j][k][l][s][t] += E[k][t][i][j][s][l];
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

O[i][j][k][l][s][t] += E[k][i][t][j][s][l];
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

O[i][j][k][l][s][t] += E[i][k][l][s][j][t];
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

O[i][j][k][l][s][t] += E[t][k][l][s][j][i];
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

O[i][j][k][l][s][t] += E[i][k][l][t][j][s];
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

O[i][j][k][l][s][t] += E[t][k][l][i][j][s];
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

O[i][j][k][l][s][t] += E[s][k][l][t][j][i];
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

O[i][j][k][l][s][t] += E[s][k][l][i][j][t];
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

O[i][j][k][l][s][t] += E[i][k][s][l][j][t];
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

O[i][j][k][l][s][t] += E[t][k][s][l][j][i];
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

O[i][j][k][l][s][t] += E[i][k][t][l][j][s];
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

O[i][j][k][l][s][t] += E[t][k][i][l][j][s];
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

O[i][j][k][l][s][t] += E[s][k][t][l][j][i];
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

O[i][j][k][l][s][t] += E[s][k][i][l][j][t];
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

O[i][j][k][l][s][t] += E[i][k][s][t][j][l];
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

O[i][j][k][l][s][t] += E[t][k][s][i][j][l];
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

O[i][j][k][l][s][t] += E[i][k][t][s][j][l];
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

O[i][j][k][l][s][t] += E[t][k][i][s][j][l];
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

O[i][j][k][l][s][t] += E[s][k][t][i][j][l];
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

O[i][j][k][l][s][t] += E[s][k][i][t][j][l];
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

O[i][j][k][l][s][t] += E[l][k][s][t][j][i];
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

O[i][j][k][l][s][t] += E[l][k][s][i][j][t];
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

O[i][j][k][l][s][t] += E[l][k][t][s][j][i];
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

O[i][j][k][l][s][t] += E[l][k][i][s][j][t];
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

O[i][j][k][l][s][t] += E[l][k][t][i][j][s];
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

O[i][j][k][l][s][t] += E[l][k][i][t][j][s];
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

O[i][j][k][l][s][t] += E[i][l][k][s][j][t];
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

O[i][j][k][l][s][t] += E[t][l][k][s][j][i];
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

O[i][j][k][l][s][t] += E[i][l][k][t][j][s];
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

O[i][j][k][l][s][t] += E[t][l][k][i][j][s];
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

O[i][j][k][l][s][t] += E[s][l][k][t][j][i];
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

O[i][j][k][l][s][t] += E[s][l][k][i][j][t];
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

O[i][j][k][l][s][t] += E[i][s][k][l][j][t];
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

O[i][j][k][l][s][t] += E[t][s][k][l][j][i];
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

O[i][j][k][l][s][t] += E[i][t][k][l][j][s];
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

O[i][j][k][l][s][t] += E[t][i][k][l][j][s];
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

O[i][j][k][l][s][t] += E[s][t][k][l][j][i];
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

O[i][j][k][l][s][t] += E[s][i][k][l][j][t];
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

O[i][j][k][l][s][t] += E[i][s][k][t][j][l];
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

O[i][j][k][l][s][t] += E[t][s][k][i][j][l];
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

O[i][j][k][l][s][t] += E[i][t][k][s][j][l];
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

O[i][j][k][l][s][t] += E[t][i][k][s][j][l];
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

O[i][j][k][l][s][t] += E[s][t][k][i][j][l];
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

O[i][j][k][l][s][t] += E[s][i][k][t][j][l];
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

O[i][j][k][l][s][t] += E[l][s][k][t][j][i];
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

O[i][j][k][l][s][t] += E[l][s][k][i][j][t];
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

O[i][j][k][l][s][t] += E[l][t][k][s][j][i];
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

O[i][j][k][l][s][t] += E[l][i][k][s][j][t];
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

O[i][j][k][l][s][t] += E[l][t][k][i][j][s];
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

O[i][j][k][l][s][t] += E[l][i][k][t][j][s];
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

O[i][j][k][l][s][t] += E[i][l][s][k][j][t];
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

O[i][j][k][l][s][t] += E[t][l][s][k][j][i];
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

O[i][j][k][l][s][t] += E[i][l][t][k][j][s];
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

O[i][j][k][l][s][t] += E[t][l][i][k][j][s];
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

O[i][j][k][l][s][t] += E[s][l][t][k][j][i];
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

O[i][j][k][l][s][t] += E[s][l][i][k][j][t];
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

O[i][j][k][l][s][t] += E[i][s][l][k][j][t];
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

O[i][j][k][l][s][t] += E[t][s][l][k][j][i];
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

O[i][j][k][l][s][t] += E[i][t][l][k][j][s];
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

O[i][j][k][l][s][t] += E[t][i][l][k][j][s];
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

O[i][j][k][l][s][t] += E[s][t][l][k][j][i];
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

O[i][j][k][l][s][t] += E[s][i][l][k][j][t];
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

O[i][j][k][l][s][t] += E[i][s][t][k][j][l];
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

O[i][j][k][l][s][t] += E[t][s][i][k][j][l];
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

O[i][j][k][l][s][t] += E[i][t][s][k][j][l];
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

O[i][j][k][l][s][t] += E[t][i][s][k][j][l];
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

O[i][j][k][l][s][t] += E[s][t][i][k][j][l];
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

O[i][j][k][l][s][t] += E[s][i][t][k][j][l];
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

O[i][j][k][l][s][t] += E[l][s][t][k][j][i];
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

O[i][j][k][l][s][t] += E[l][s][i][k][j][t];
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

O[i][j][k][l][s][t] += E[l][t][s][k][j][i];
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

O[i][j][k][l][s][t] += E[l][i][s][k][j][t];
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

O[i][j][k][l][s][t] += E[l][t][i][k][j][s];
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

O[i][j][k][l][s][t] += E[l][i][t][k][j][s];
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

O[i][j][k][l][s][t] += E[i][l][s][t][j][k];
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

O[i][j][k][l][s][t] += E[t][l][s][i][j][k];
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

O[i][j][k][l][s][t] += E[i][l][t][s][j][k];
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

O[i][j][k][l][s][t] += E[t][l][i][s][j][k];
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

O[i][j][k][l][s][t] += E[s][l][t][i][j][k];
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

O[i][j][k][l][s][t] += E[s][l][i][t][j][k];
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

O[i][j][k][l][s][t] += E[i][s][l][t][j][k];
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

O[i][j][k][l][s][t] += E[t][s][l][i][j][k];
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

O[i][j][k][l][s][t] += E[i][t][l][s][j][k];
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

O[i][j][k][l][s][t] += E[t][i][l][s][j][k];
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

O[i][j][k][l][s][t] += E[s][t][l][i][j][k];
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

O[i][j][k][l][s][t] += E[s][i][l][t][j][k];
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

O[i][j][k][l][s][t] += E[i][s][t][l][j][k];
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

O[i][j][k][l][s][t] += E[t][s][i][l][j][k];
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

O[i][j][k][l][s][t] += E[i][t][s][l][j][k];
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

O[i][j][k][l][s][t] += E[t][i][s][l][j][k];
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

O[i][j][k][l][s][t] += E[s][t][i][l][j][k];
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

O[i][j][k][l][s][t] += E[s][i][t][l][j][k];
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

O[i][j][k][l][s][t] += E[l][s][t][i][j][k];
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

O[i][j][k][l][s][t] += E[l][s][i][t][j][k];
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

O[i][j][k][l][s][t] += E[l][t][s][i][j][k];
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

O[i][j][k][l][s][t] += E[l][i][s][t][j][k];
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

O[i][j][k][l][s][t] += E[l][t][i][s][j][k];
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

O[i][j][k][l][s][t] += E[l][i][t][s][j][k];
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

O[i][j][k][l][s][t] += E[k][l][s][t][j][i];
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

O[i][j][k][l][s][t] += E[k][l][s][i][j][t];
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

O[i][j][k][l][s][t] += E[k][l][t][s][j][i];
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

O[i][j][k][l][s][t] += E[k][l][i][s][j][t];
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

O[i][j][k][l][s][t] += E[k][l][t][i][j][s];
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

O[i][j][k][l][s][t] += E[k][l][i][t][j][s];
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

O[i][j][k][l][s][t] += E[k][s][l][t][j][i];
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

O[i][j][k][l][s][t] += E[k][s][l][i][j][t];
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

O[i][j][k][l][s][t] += E[k][t][l][s][j][i];
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

O[i][j][k][l][s][t] += E[k][i][l][s][j][t];
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

O[i][j][k][l][s][t] += E[k][t][l][i][j][s];
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

O[i][j][k][l][s][t] += E[k][i][l][t][j][s];
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

O[i][j][k][l][s][t] += E[k][s][t][l][j][i];
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

O[i][j][k][l][s][t] += E[k][s][i][l][j][t];
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

O[i][j][k][l][s][t] += E[k][t][s][l][j][i];
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

O[i][j][k][l][s][t] += E[k][i][s][l][j][t];
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

O[i][j][k][l][s][t] += E[k][t][i][l][j][s];
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

O[i][j][k][l][s][t] += E[k][i][t][l][j][s];
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

O[i][j][k][l][s][t] += E[k][s][t][i][j][l];
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

O[i][j][k][l][s][t] += E[k][s][i][t][j][l];
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

O[i][j][k][l][s][t] += E[k][t][s][i][j][l];
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

O[i][j][k][l][s][t] += E[k][i][s][t][j][l];
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

O[i][j][k][l][s][t] += E[k][t][i][s][j][l];
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

O[i][j][k][l][s][t] += E[k][i][t][s][j][l];
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

O[i][j][k][l][s][t] += E[i][k][l][s][t][j];
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

O[i][j][k][l][s][t] += E[t][k][l][s][i][j];
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

O[i][j][k][l][s][t] += E[i][k][l][t][s][j];
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

O[i][j][k][l][s][t] += E[t][k][l][i][s][j];
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

O[i][j][k][l][s][t] += E[s][k][l][t][i][j];
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

O[i][j][k][l][s][t] += E[s][k][l][i][t][j];
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

O[i][j][k][l][s][t] += E[i][k][s][l][t][j];
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

O[i][j][k][l][s][t] += E[t][k][s][l][i][j];
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

O[i][j][k][l][s][t] += E[i][k][t][l][s][j];
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

O[i][j][k][l][s][t] += E[t][k][i][l][s][j];
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

O[i][j][k][l][s][t] += E[s][k][t][l][i][j];
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

O[i][j][k][l][s][t] += E[s][k][i][l][t][j];
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

O[i][j][k][l][s][t] += E[i][k][s][t][l][j];
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

O[i][j][k][l][s][t] += E[t][k][s][i][l][j];
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

O[i][j][k][l][s][t] += E[i][k][t][s][l][j];
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

O[i][j][k][l][s][t] += E[t][k][i][s][l][j];
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

O[i][j][k][l][s][t] += E[s][k][t][i][l][j];
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

O[i][j][k][l][s][t] += E[s][k][i][t][l][j];
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

O[i][j][k][l][s][t] += E[l][k][s][t][i][j];
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

O[i][j][k][l][s][t] += E[l][k][s][i][t][j];
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

O[i][j][k][l][s][t] += E[l][k][t][s][i][j];
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

O[i][j][k][l][s][t] += E[l][k][i][s][t][j];
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

O[i][j][k][l][s][t] += E[l][k][t][i][s][j];
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

O[i][j][k][l][s][t] += E[l][k][i][t][s][j];
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

O[i][j][k][l][s][t] += E[i][l][k][s][t][j];
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

O[i][j][k][l][s][t] += E[t][l][k][s][i][j];
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

O[i][j][k][l][s][t] += E[i][l][k][t][s][j];
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

O[i][j][k][l][s][t] += E[t][l][k][i][s][j];
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

O[i][j][k][l][s][t] += E[s][l][k][t][i][j];
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

O[i][j][k][l][s][t] += E[s][l][k][i][t][j];
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

O[i][j][k][l][s][t] += E[i][s][k][l][t][j];
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

O[i][j][k][l][s][t] += E[t][s][k][l][i][j];
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

O[i][j][k][l][s][t] += E[i][t][k][l][s][j];
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

O[i][j][k][l][s][t] += E[t][i][k][l][s][j];
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

O[i][j][k][l][s][t] += E[s][t][k][l][i][j];
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

O[i][j][k][l][s][t] += E[s][i][k][l][t][j];
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

O[i][j][k][l][s][t] += E[i][s][k][t][l][j];
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

O[i][j][k][l][s][t] += E[t][s][k][i][l][j];
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

O[i][j][k][l][s][t] += E[i][t][k][s][l][j];
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

O[i][j][k][l][s][t] += E[t][i][k][s][l][j];
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

O[i][j][k][l][s][t] += E[s][t][k][i][l][j];
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

O[i][j][k][l][s][t] += E[s][i][k][t][l][j];
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

O[i][j][k][l][s][t] += E[l][s][k][t][i][j];
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

O[i][j][k][l][s][t] += E[l][s][k][i][t][j];
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

O[i][j][k][l][s][t] += E[l][t][k][s][i][j];
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

O[i][j][k][l][s][t] += E[l][i][k][s][t][j];
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

O[i][j][k][l][s][t] += E[l][t][k][i][s][j];
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

O[i][j][k][l][s][t] += E[l][i][k][t][s][j];
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

O[i][j][k][l][s][t] += E[i][l][s][k][t][j];
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

O[i][j][k][l][s][t] += E[t][l][s][k][i][j];
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

O[i][j][k][l][s][t] += E[i][l][t][k][s][j];
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

O[i][j][k][l][s][t] += E[t][l][i][k][s][j];
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

O[i][j][k][l][s][t] += E[s][l][t][k][i][j];
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

O[i][j][k][l][s][t] += E[s][l][i][k][t][j];
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

O[i][j][k][l][s][t] += E[i][s][l][k][t][j];
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

O[i][j][k][l][s][t] += E[t][s][l][k][i][j];
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

O[i][j][k][l][s][t] += E[i][t][l][k][s][j];
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

O[i][j][k][l][s][t] += E[t][i][l][k][s][j];
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

O[i][j][k][l][s][t] += E[s][t][l][k][i][j];
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

O[i][j][k][l][s][t] += E[s][i][l][k][t][j];
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

O[i][j][k][l][s][t] += E[i][s][t][k][l][j];
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

O[i][j][k][l][s][t] += E[t][s][i][k][l][j];
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

O[i][j][k][l][s][t] += E[i][t][s][k][l][j];
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

O[i][j][k][l][s][t] += E[t][i][s][k][l][j];
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

O[i][j][k][l][s][t] += E[s][t][i][k][l][j];
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

O[i][j][k][l][s][t] += E[s][i][t][k][l][j];
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

O[i][j][k][l][s][t] += E[l][s][t][k][i][j];
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

O[i][j][k][l][s][t] += E[l][s][i][k][t][j];
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

O[i][j][k][l][s][t] += E[l][t][s][k][i][j];
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

O[i][j][k][l][s][t] += E[l][i][s][k][t][j];
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

O[i][j][k][l][s][t] += E[l][t][i][k][s][j];
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

O[i][j][k][l][s][t] += E[l][i][t][k][s][j];
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

O[i][j][k][l][s][t] += E[i][l][s][t][k][j];
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

O[i][j][k][l][s][t] += E[t][l][s][i][k][j];
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

O[i][j][k][l][s][t] += E[i][l][t][s][k][j];
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

O[i][j][k][l][s][t] += E[t][l][i][s][k][j];
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

O[i][j][k][l][s][t] += E[s][l][t][i][k][j];
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

O[i][j][k][l][s][t] += E[s][l][i][t][k][j];
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

O[i][j][k][l][s][t] += E[i][s][l][t][k][j];
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

O[i][j][k][l][s][t] += E[t][s][l][i][k][j];
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

O[i][j][k][l][s][t] += E[i][t][l][s][k][j];
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

O[i][j][k][l][s][t] += E[t][i][l][s][k][j];
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

O[i][j][k][l][s][t] += E[s][t][l][i][k][j];
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

O[i][j][k][l][s][t] += E[s][i][l][t][k][j];
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

O[i][j][k][l][s][t] += E[i][s][t][l][k][j];
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

O[i][j][k][l][s][t] += E[t][s][i][l][k][j];
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

O[i][j][k][l][s][t] += E[i][t][s][l][k][j];
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

O[i][j][k][l][s][t] += E[t][i][s][l][k][j];
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

O[i][j][k][l][s][t] += E[s][t][i][l][k][j];
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

O[i][j][k][l][s][t] += E[s][i][t][l][k][j];
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

O[i][j][k][l][s][t] += E[l][s][t][i][k][j];
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

O[i][j][k][l][s][t] += E[l][s][i][t][k][j];
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

O[i][j][k][l][s][t] += E[l][t][s][i][k][j];
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

O[i][j][k][l][s][t] += E[l][i][s][t][k][j];
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

O[i][j][k][l][s][t] += E[l][t][i][s][k][j];
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

O[i][j][k][l][s][t] += E[l][i][t][s][k][j];
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

O[i][j][k][l][s][t] += E[k][l][s][t][i][j];
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

O[i][j][k][l][s][t] += E[k][l][s][i][t][j];
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

O[i][j][k][l][s][t] += E[k][l][t][s][i][j];
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

O[i][j][k][l][s][t] += E[k][l][i][s][t][j];
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

O[i][j][k][l][s][t] += E[k][l][t][i][s][j];
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

O[i][j][k][l][s][t] += E[k][l][i][t][s][j];
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

O[i][j][k][l][s][t] += E[k][s][l][t][i][j];
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

O[i][j][k][l][s][t] += E[k][s][l][i][t][j];
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

O[i][j][k][l][s][t] += E[k][t][l][s][i][j];
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

O[i][j][k][l][s][t] += E[k][i][l][s][t][j];
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

O[i][j][k][l][s][t] += E[k][t][l][i][s][j];
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

O[i][j][k][l][s][t] += E[k][i][l][t][s][j];
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

O[i][j][k][l][s][t] += E[k][s][t][l][i][j];
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

O[i][j][k][l][s][t] += E[k][s][i][l][t][j];
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

O[i][j][k][l][s][t] += E[k][t][s][l][i][j];
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

O[i][j][k][l][s][t] += E[k][i][s][l][t][j];
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

O[i][j][k][l][s][t] += E[k][t][i][l][s][j];
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

O[i][j][k][l][s][t] += E[k][i][t][l][s][j];
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

O[i][j][k][l][s][t] += E[k][s][t][i][l][j];
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

O[i][j][k][l][s][t] += E[k][s][i][t][l][j];
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

O[i][j][k][l][s][t] += E[k][t][s][i][l][j];
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

O[i][j][k][l][s][t] += E[k][i][s][t][l][j];
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

O[i][j][k][l][s][t] += E[k][t][i][s][l][j];
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

O[i][j][k][l][s][t] += E[k][i][t][s][l][j];
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

O[i][j][k][l][s][t] += E[j][k][l][s][t][i];
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

O[i][j][k][l][s][t] += E[j][k][l][s][i][t];
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

O[i][j][k][l][s][t] += E[j][k][l][t][s][i];
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

O[i][j][k][l][s][t] += E[j][k][l][i][s][t];
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

O[i][j][k][l][s][t] += E[j][k][l][t][i][s];
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

O[i][j][k][l][s][t] += E[j][k][l][i][t][s];
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

O[i][j][k][l][s][t] += E[j][k][s][l][t][i];
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

O[i][j][k][l][s][t] += E[j][k][s][l][i][t];
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

O[i][j][k][l][s][t] += E[j][k][t][l][s][i];
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

O[i][j][k][l][s][t] += E[j][k][i][l][s][t];
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

O[i][j][k][l][s][t] += E[j][k][t][l][i][s];
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

O[i][j][k][l][s][t] += E[j][k][i][l][t][s];
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

O[i][j][k][l][s][t] += E[j][k][s][t][l][i];
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

O[i][j][k][l][s][t] += E[j][k][s][i][l][t];
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

O[i][j][k][l][s][t] += E[j][k][t][s][l][i];
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

O[i][j][k][l][s][t] += E[j][k][i][s][l][t];
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

O[i][j][k][l][s][t] += E[j][k][t][i][l][s];
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

O[i][j][k][l][s][t] += E[j][k][i][t][l][s];
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

O[i][j][k][l][s][t] += E[j][k][s][t][i][l];
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

O[i][j][k][l][s][t] += E[j][k][s][i][t][l];
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

O[i][j][k][l][s][t] += E[j][k][t][s][i][l];
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

O[i][j][k][l][s][t] += E[j][k][i][s][t][l];
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

O[i][j][k][l][s][t] += E[j][k][t][i][s][l];
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

O[i][j][k][l][s][t] += E[j][k][i][t][s][l];
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

O[i][j][k][l][s][t] += E[j][l][k][s][t][i];
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

O[i][j][k][l][s][t] += E[j][l][k][s][i][t];
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

O[i][j][k][l][s][t] += E[j][l][k][t][s][i];
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

O[i][j][k][l][s][t] += E[j][l][k][i][s][t];
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

O[i][j][k][l][s][t] += E[j][l][k][t][i][s];
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

O[i][j][k][l][s][t] += E[j][l][k][i][t][s];
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

O[i][j][k][l][s][t] += E[j][s][k][l][t][i];
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

O[i][j][k][l][s][t] += E[j][s][k][l][i][t];
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

O[i][j][k][l][s][t] += E[j][t][k][l][s][i];
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

O[i][j][k][l][s][t] += E[j][i][k][l][s][t];
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

O[i][j][k][l][s][t] += E[j][t][k][l][i][s];
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

O[i][j][k][l][s][t] += E[j][i][k][l][t][s];
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

O[i][j][k][l][s][t] += E[j][s][k][t][l][i];
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

O[i][j][k][l][s][t] += E[j][s][k][i][l][t];
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

O[i][j][k][l][s][t] += E[j][t][k][s][l][i];
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

O[i][j][k][l][s][t] += E[j][i][k][s][l][t];
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

O[i][j][k][l][s][t] += E[j][t][k][i][l][s];
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

O[i][j][k][l][s][t] += E[j][i][k][t][l][s];
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

O[i][j][k][l][s][t] += E[j][s][k][t][i][l];
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

O[i][j][k][l][s][t] += E[j][s][k][i][t][l];
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

O[i][j][k][l][s][t] += E[j][t][k][s][i][l];
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

O[i][j][k][l][s][t] += E[j][i][k][s][t][l];
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

O[i][j][k][l][s][t] += E[j][t][k][i][s][l];
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

O[i][j][k][l][s][t] += E[j][i][k][t][s][l];
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

O[i][j][k][l][s][t] += E[j][l][s][k][t][i];
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

O[i][j][k][l][s][t] += E[j][l][s][k][i][t];
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

O[i][j][k][l][s][t] += E[j][l][t][k][s][i];
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

O[i][j][k][l][s][t] += E[j][l][i][k][s][t];
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

O[i][j][k][l][s][t] += E[j][l][t][k][i][s];
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

O[i][j][k][l][s][t] += E[j][l][i][k][t][s];
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

O[i][j][k][l][s][t] += E[j][s][l][k][t][i];
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

O[i][j][k][l][s][t] += E[j][s][l][k][i][t];
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

O[i][j][k][l][s][t] += E[j][t][l][k][s][i];
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

O[i][j][k][l][s][t] += E[j][i][l][k][s][t];
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

O[i][j][k][l][s][t] += E[j][t][l][k][i][s];
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

O[i][j][k][l][s][t] += E[j][i][l][k][t][s];
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

O[i][j][k][l][s][t] += E[j][s][t][k][l][i];
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

O[i][j][k][l][s][t] += E[j][s][i][k][l][t];
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

O[i][j][k][l][s][t] += E[j][t][s][k][l][i];
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

O[i][j][k][l][s][t] += E[j][i][s][k][l][t];
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

O[i][j][k][l][s][t] += E[j][t][i][k][l][s];
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

O[i][j][k][l][s][t] += E[j][i][t][k][l][s];
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

O[i][j][k][l][s][t] += E[j][s][t][k][i][l];
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

O[i][j][k][l][s][t] += E[j][s][i][k][t][l];
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

O[i][j][k][l][s][t] += E[j][t][s][k][i][l];
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

O[i][j][k][l][s][t] += E[j][i][s][k][t][l];
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

O[i][j][k][l][s][t] += E[j][t][i][k][s][l];
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

O[i][j][k][l][s][t] += E[j][i][t][k][s][l];
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

O[i][j][k][l][s][t] += E[j][l][s][t][k][i];
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

O[i][j][k][l][s][t] += E[j][l][s][i][k][t];
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

O[i][j][k][l][s][t] += E[j][l][t][s][k][i];
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

O[i][j][k][l][s][t] += E[j][l][i][s][k][t];
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

O[i][j][k][l][s][t] += E[j][l][t][i][k][s];
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

O[i][j][k][l][s][t] += E[j][l][i][t][k][s];
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

O[i][j][k][l][s][t] += E[j][s][l][t][k][i];
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

O[i][j][k][l][s][t] += E[j][s][l][i][k][t];
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

O[i][j][k][l][s][t] += E[j][t][l][s][k][i];
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

O[i][j][k][l][s][t] += E[j][i][l][s][k][t];
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

O[i][j][k][l][s][t] += E[j][t][l][i][k][s];
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

O[i][j][k][l][s][t] += E[j][i][l][t][k][s];
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

O[i][j][k][l][s][t] += E[j][s][t][l][k][i];
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

O[i][j][k][l][s][t] += E[j][s][i][l][k][t];
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

O[i][j][k][l][s][t] += E[j][t][s][l][k][i];
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

O[i][j][k][l][s][t] += E[j][i][s][l][k][t];
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

O[i][j][k][l][s][t] += E[j][t][i][l][k][s];
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

O[i][j][k][l][s][t] += E[j][i][t][l][k][s];
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

O[i][j][k][l][s][t] += E[j][s][t][i][k][l];
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

O[i][j][k][l][s][t] += E[j][s][i][t][k][l];
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

O[i][j][k][l][s][t] += E[j][t][s][i][k][l];
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

O[i][j][k][l][s][t] += E[j][i][s][t][k][l];
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

O[i][j][k][l][s][t] += E[j][t][i][s][k][l];
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

O[i][j][k][l][s][t] += E[j][i][t][s][k][l];
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

O[i][j][k][l][s][t] += E[j][l][s][t][i][k];
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

O[i][j][k][l][s][t] += E[j][l][s][i][t][k];
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

O[i][j][k][l][s][t] += E[j][l][t][s][i][k];
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

O[i][j][k][l][s][t] += E[j][l][i][s][t][k];
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

O[i][j][k][l][s][t] += E[j][l][t][i][s][k];
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

O[i][j][k][l][s][t] += E[j][l][i][t][s][k];
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

O[i][j][k][l][s][t] += E[j][s][l][t][i][k];
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

O[i][j][k][l][s][t] += E[j][s][l][i][t][k];
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

O[i][j][k][l][s][t] += E[j][t][l][s][i][k];
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

O[i][j][k][l][s][t] += E[j][i][l][s][t][k];
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

O[i][j][k][l][s][t] += E[j][t][l][i][s][k];
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

O[i][j][k][l][s][t] += E[j][i][l][t][s][k];
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

O[i][j][k][l][s][t] += E[j][s][t][l][i][k];
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

O[i][j][k][l][s][t] += E[j][s][i][l][t][k];
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

O[i][j][k][l][s][t] += E[j][t][s][l][i][k];
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

O[i][j][k][l][s][t] += E[j][i][s][l][t][k];
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

O[i][j][k][l][s][t] += E[j][t][i][l][s][k];
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

O[i][j][k][l][s][t] += E[j][i][t][l][s][k];
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

O[i][j][k][l][s][t] += E[j][s][t][i][l][k];
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

O[i][j][k][l][s][t] += E[j][s][i][t][l][k];
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

O[i][j][k][l][s][t] += E[j][t][s][i][l][k];
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

O[i][j][k][l][s][t] += E[j][i][s][t][l][k];
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

O[i][j][k][l][s][t] += E[j][t][i][s][l][k];
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

O[i][j][k][l][s][t] += E[j][i][t][s][l][k];
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

for (int s = max({i, 0}); s < N; ++s) {

int sp = i;
int ip = s;
for (int j = 0; j < N; ++j) {

int jp = j;
for (int k = max({j, 0}); k < N; ++k) {

for (int l = max({k, 0}); l < min({(i) + 1, N}); ++l) {

int kp = k;
int lp = l;
D[i][j][k][l][s] += D[ip][jp][kp][lp][sp];
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int l = 0; l < min({(i) + 1, N}); ++l) {

int ip = i;
int sp = l;
for (int j = 0; j < N; ++j) {

int jp = j;
for (int k = max({j, 0}); k < N; ++k) {

for (int s = max({k, 0}); s < min({(l) + 1, N}); ++s) {

int kp = k;
int lp = s;
D[i][j][k][l][s] += D[ip][jp][kp][lp][sp];
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int l = max({i, 0}); l < N; ++l) {

int lp = i;
int sp = l;
for (int j = 0; j < N; ++j) {

int jp = j;
for (int k = max({j, 0}); k < N; ++k) {

for (int s = max({k, 0}); s < min({(i) + 1, N}); ++s) {

int kp = k;
int ip = s;
D[i][j][k][l][s] += D[ip][jp][kp][lp][sp];
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int l = max({i, 0}); l < N; ++l) {

int sp = i;
for (int s = max({l, 0}); s < N; ++s) {

int ip = l;
int lp = s;
for (int j = 0; j < N; ++j) {

int jp = j;
for (int k = max({j, 0}); k < min({(i) + 1, N}); ++k) {

int kp = k;
D[i][j][k][l][s] += D[ip][jp][kp][lp][sp];
}
}
}
}
}
for (int i = 0; i < N; ++i) {

int lp = i;
for (int j = 0; j < N; ++j) {

int jp = j;
for (int k = max({j, 0}); k < min({(i) + 1, N}); ++k) {

for (int l = 0; l < N; ++l) {

int kp = k;
for (int s = max({i, 0}); s < min({(l) + 1, N}); ++s) {

int ip = l;
int sp = s;
D[i][j][k][l][s] += D[ip][jp][kp][lp][sp];
}
}
}
}
}
for (int i = 0; i < N; ++i) {

int ip = i;
for (int j = 0; j < N; ++j) {

int jp = j;
for (int k = 0; k < N; ++k) {

for (int s = max({k, 0}); s < min({(i) + 1, N}); ++s) {

for (int l = max({j, 0}); l < min({(k) + 1, N}); ++l) {

int lp = k;
int sp = s;
int kp = l;
D[i][j][k][l][s] += D[ip][jp][kp][lp][sp];
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int s = max({i, 0}); s < N; ++s) {

int sp = i;
for (int k = 0; k < min({(i) + 1, N}); ++k) {

int ip = s;
int lp = k;
for (int j = 0; j < N; ++j) {

for (int l = max({j, 0}); l < min({(k) + 1, N}); ++l) {

int jp = j;
int kp = l;
D[i][j][k][l][s] += D[ip][jp][kp][lp][sp];
}
}
}
}
}
for (int i = 0; i < N; ++i) {

int ip = i;
for (int k = 0; k < min({(i) + 1, N}); ++k) {

int lp = k;
for (int j = 0; j < N; ++j) {

for (int l = max({j, 0}); l < N; ++l) {

int jp = j;
for (int s = max({l, 0}); s < min({(k) + 1, N}); ++s) {

int sp = l;
int kp = s;
D[i][j][k][l][s] += D[ip][jp][kp][lp][sp];
}
}
}
}
}
for (int i = 0; i < N; ++i) {

int kp = i;
for (int k = max({i, 0}); k < N; ++k) {

int lp = k;
for (int j = 0; j < N; ++j) {

for (int l = max({j, 0}); l < N; ++l) {

int jp = j;
for (int s = max({l, 0}); s < min({(i) + 1, N}); ++s) {

int sp = l;
int ip = s;
D[i][j][k][l][s] += D[ip][jp][kp][lp][sp];
}
}
}
}
}
for (int i = 0; i < N; ++i) {

int sp = i;
for (int k = max({i, 0}); k < N; ++k) {

for (int s = max({k, 0}); s < N; ++s) {

int lp = k;
int kp = s;
for (int j = 0; j < N; ++j) {

for (int l = max({j, 0}); l < min({(i) + 1, N}); ++l) {

int jp = j;
int ip = l;
D[i][j][k][l][s] += D[ip][jp][kp][lp][sp];
}
}
}
}
}
for (int i = 0; i < N; ++i) {

int kp = i;
for (int j = 0; j < N; ++j) {

for (int l = max({j, 0}); l < min({(i) + 1, N}); ++l) {

int jp = j;
int ip = l;
for (int k = 0; k < N; ++k) {

for (int s = max({i, 0}); s < min({(k) + 1, N}); ++s) {

int lp = k;
int sp = s;
D[i][j][k][l][s] += D[ip][jp][kp][lp][sp];
}
}
}
}
}
for (int i = 0; i < N; ++i) {

int ip = i;
for (int j = 0; j < N; ++j) {

int jp = j;
for (int k = 0; k < N; ++k) {

for (int s = max({j, 0}); s < min({(k) + 1, N}); ++s) {

for (int l = max({k, 0}); l < min({(i) + 1, N}); ++l) {

int sp = k;
int lp = s;
int kp = l;
D[i][j][k][l][s] += D[ip][jp][kp][lp][sp];
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int l = max({i, 0}); l < N; ++l) {

int lp = i;
for (int k = 0; k < min({(i) + 1, N}); ++k) {

int kp = l;
int sp = k;
for (int j = 0; j < N; ++j) {

for (int s = max({j, 0}); s < min({(k) + 1, N}); ++s) {

int jp = j;
int ip = s;
D[i][j][k][l][s] += D[ip][jp][kp][lp][sp];
}
}
}
}
}
for (int i = 0; i < N; ++i) {

int ip = i;
for (int k = 0; k < min({(i) + 1, N}); ++k) {

for (int l = 0; l < min({(k) + 1, N}); ++l) {

int sp = k;
int lp = l;
for (int j = 0; j < N; ++j) {

for (int s = max({j, 0}); s < min({(l) + 1, N}); ++s) {

int jp = j;
int kp = s;
D[i][j][k][l][s] += D[ip][jp][kp][lp][sp];
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int l = 0; l < min({(i) + 1, N}); ++l) {

int kp = i;
for (int k = max({i, 0}); k < N; ++k) {

int lp = l;
int sp = k;
for (int j = 0; j < N; ++j) {

for (int s = max({j, 0}); s < min({(l) + 1, N}); ++s) {

int jp = j;
int ip = s;
D[i][j][k][l][s] += D[ip][jp][kp][lp][sp];
}
}
}
}
}
for (int i = 0; i < N; ++i) {

int lp = i;
for (int k = max({i, 0}); k < N; ++k) {

for (int l = max({k, 0}); l < N; ++l) {

int sp = k;
int ip = l;
for (int j = 0; j < N; ++j) {

for (int s = max({j, 0}); s < min({(i) + 1, N}); ++s) {

int jp = j;
int kp = s;
D[i][j][k][l][s] += D[ip][jp][kp][lp][sp];
}
}
}
}
}
for (int i = 0; i < N; ++i) {

int kp = i;
for (int j = 0; j < N; ++j) {

for (int s = max({j, 0}); s < min({(i) + 1, N}); ++s) {

int jp = j;
int lp = s;
for (int k = 0; k < N; ++k) {

for (int l = max({i, 0}); l < min({(k) + 1, N}); ++l) {

int sp = k;
int ip = l;
D[i][j][k][l][s] += D[ip][jp][kp][lp][sp];
}
}
}
}
}
for (int i = 0; i < N; ++i) {

int sp = i;
for (int j = 0; j < min({(i) + 1, N}); ++j) {

for (int k = max({i, 0}); k < N; ++k) {

int jp = j;
for (int l = max({k, 0}); l < N; ++l) {

int ip = k;
for (int s = max({l, 0}); s < N; ++s) {

int kp = l;
int lp = s;
D[i][j][k][l][s] += D[ip][jp][kp][lp][sp];
}
}
}
}
}
for (int i = 0; i < N; ++i) {

int lp = i;
for (int j = 0; j < min({(i) + 1, N}); ++j) {

for (int k = max({i, 0}); k < N; ++k) {

int jp = j;
int ip = k;
for (int l = 0; l < N; ++l) {

for (int s = max({k, 0}); s < min({(l) + 1, N}); ++s) {

int kp = l;
int sp = s;
D[i][j][k][l][s] += D[ip][jp][kp][lp][sp];
}
}
}
}
}
for (int i = 0; i < N; ++i) {

int sp = i;
for (int j = 0; j < min({(i) + 1, N}); ++j) {

int jp = j;
for (int k = 0; k < N; ++k) {

for (int s = max({k, 0}); s < N; ++s) {

for (int l = max({i, 0}); l < min({(k) + 1, N}); ++l) {

int ip = k;
int kp = s;
int lp = l;
D[i][j][k][l][s] += D[ip][jp][kp][lp][sp];
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int l = max({i, 0}); l < N; ++l) {

int kp = i;
for (int j = 0; j < min({(i) + 1, N}); ++j) {

int lp = l;
int jp = j;
for (int k = 0; k < N; ++k) {

for (int s = max({l, 0}); s < min({(k) + 1, N}); ++s) {

int ip = k;
int sp = s;
D[i][j][k][l][s] += D[ip][jp][kp][lp][sp];
}
}
}
}
}
for (int i = 0; i < N; ++i) {

int lp = i;
for (int j = 0; j < min({(i) + 1, N}); ++j) {

int jp = j;
for (int k = 0; k < N; ++k) {

for (int s = max({i, 0}); s < min({(k) + 1, N}); ++s) {

for (int l = max({k, 0}); l < N; ++l) {

int ip = k;
int kp = s;
int sp = l;
D[i][j][k][l][s] += D[ip][jp][kp][lp][sp];
}
}
}
}
}
for (int i = 0; i < N; ++i) {

int kp = i;
for (int j = 0; j < min({(i) + 1, N}); ++j) {

int jp = j;
for (int k = 0; k < N; ++k) {

for (int l = 0; l < min({(k) + 1, N}); ++l) {

int ip = k;
for (int s = max({i, 0}); s < min({(l) + 1, N}); ++s) {

int sp = l;
int lp = s;
D[i][j][k][l][s] += D[ip][jp][kp][lp][sp];
}
}
}
}
}
for (int i = 0; i < N; ++i) {

int ip = i;
for (int j = 0; j < N; ++j) {

for (int l = max({j, 0}); l < N; ++l) {

int kp = j;
for (int k = 0; k < min({(j) + 1, N}); ++k) {

for (int s = max({l, 0}); s < min({(i) + 1, N}); ++s) {

int lp = l;
int jp = k;
int sp = s;
D[i][j][k][l][s] += D[ip][jp][kp][lp][sp];
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int s = max({i, 0}); s < N; ++s) {

int sp = i;
int ip = s;
for (int j = 0; j < N; ++j) {

for (int l = max({j, 0}); l < min({(i) + 1, N}); ++l) {

int kp = j;
for (int k = 0; k < min({(j) + 1, N}); ++k) {

int lp = l;
int jp = k;
D[i][j][k][l][s] += D[ip][jp][kp][lp][sp];
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int l = 0; l < min({(i) + 1, N}); ++l) {

int ip = i;
int sp = l;
for (int j = 0; j < N; ++j) {

for (int s = max({j, 0}); s < min({(l) + 1, N}); ++s) {

int kp = j;
for (int k = 0; k < min({(j) + 1, N}); ++k) {

int lp = s;
int jp = k;
D[i][j][k][l][s] += D[ip][jp][kp][lp][sp];
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int l = max({i, 0}); l < N; ++l) {

int lp = i;
int sp = l;
for (int j = 0; j < N; ++j) {

for (int s = max({j, 0}); s < min({(i) + 1, N}); ++s) {

int kp = j;
for (int k = 0; k < min({(j) + 1, N}); ++k) {

int ip = s;
int jp = k;
D[i][j][k][l][s] += D[ip][jp][kp][lp][sp];
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int l = max({i, 0}); l < N; ++l) {

int sp = i;
for (int j = 0; j < min({(i) + 1, N}); ++j) {

for (int s = max({l, 0}); s < N; ++s) {

int ip = l;
int kp = j;
for (int k = 0; k < min({(j) + 1, N}); ++k) {

int lp = s;
int jp = k;
D[i][j][k][l][s] += D[ip][jp][kp][lp][sp];
}
}
}
}
}
for (int i = 0; i < N; ++i) {

int lp = i;
for (int j = 0; j < min({(i) + 1, N}); ++j) {

int kp = j;
for (int k = 0; k < min({(j) + 1, N}); ++k) {

for (int l = 0; l < N; ++l) {

int jp = k;
for (int s = max({i, 0}); s < min({(l) + 1, N}); ++s) {

int ip = l;
int sp = s;
D[i][j][k][l][s] += D[ip][jp][kp][lp][sp];
}
}
}
}
}
for (int i = 0; i < N; ++i) {

int ip = i;
for (int j = 0; j < N; ++j) {

for (int s = max({j, 0}); s < min({(i) + 1, N}); ++s) {

int kp = j;
int sp = s;
for (int k = 0; k < N; ++k) {

for (int l = max({k, 0}); l < min({(j) + 1, N}); ++l) {

int lp = k;
int jp = l;
D[i][j][k][l][s] += D[ip][jp][kp][lp][sp];
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int s = max({i, 0}); s < N; ++s) {

int sp = i;
for (int j = 0; j < min({(i) + 1, N}); ++j) {

int ip = s;
int kp = j;
for (int k = 0; k < N; ++k) {

for (int l = max({k, 0}); l < min({(j) + 1, N}); ++l) {

int lp = k;
int jp = l;
D[i][j][k][l][s] += D[ip][jp][kp][lp][sp];
}
}
}
}
}
for (int i = 0; i < N; ++i) {

int ip = i;
for (int j = 0; j < min({(i) + 1, N}); ++j) {

int kp = j;
for (int k = 0; k < N; ++k) {

for (int l = max({k, 0}); l < N; ++l) {

int lp = k;
for (int s = max({l, 0}); s < min({(j) + 1, N}); ++s) {

int sp = l;
int jp = s;
D[i][j][k][l][s] += D[ip][jp][kp][lp][sp];
}
}
}
}
}
for (int i = 0; i < N; ++i) {

int jp = i;
for (int j = max({i, 0}); j < N; ++j) {

int kp = j;
for (int k = 0; k < N; ++k) {

for (int l = max({k, 0}); l < N; ++l) {

int lp = k;
for (int s = max({l, 0}); s < min({(i) + 1, N}); ++s) {

int sp = l;
int ip = s;
D[i][j][k][l][s] += D[ip][jp][kp][lp][sp];
}
}
}
}
}
for (int i = 0; i < N; ++i) {

int sp = i;
for (int j = max({i, 0}); j < N; ++j) {

for (int s = max({j, 0}); s < N; ++s) {

int kp = j;
int jp = s;
for (int k = 0; k < N; ++k) {

for (int l = max({k, 0}); l < min({(i) + 1, N}); ++l) {

int lp = k;
int ip = l;
D[i][j][k][l][s] += D[ip][jp][kp][lp][sp];
}
}
}
}
}
for (int i = 0; i < N; ++i) {

int jp = i;
for (int j = 0; j < N; ++j) {

for (int s = max({i, 0}); s < min({(j) + 1, N}); ++s) {

int kp = j;
int sp = s;
for (int k = 0; k < N; ++k) {

for (int l = max({k, 0}); l < min({(i) + 1, N}); ++l) {

int lp = k;
int ip = l;
D[i][j][k][l][s] += D[ip][jp][kp][lp][sp];
}
}
}
}
}
for (int i = 0; i < N; ++i) {

int ip = i;
for (int j = 0; j < N; ++j) {

for (int l = max({j, 0}); l < min({(i) + 1, N}); ++l) {

int kp = j;
int jp = l;
for (int k = 0; k < N; ++k) {

for (int s = max({k, 0}); s < min({(j) + 1, N}); ++s) {

int sp = k;
int lp = s;
D[i][j][k][l][s] += D[ip][jp][kp][lp][sp];
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int l = max({i, 0}); l < N; ++l) {

int lp = i;
for (int j = 0; j < min({(i) + 1, N}); ++j) {

int jp = l;
int kp = j;
for (int k = 0; k < N; ++k) {

for (int s = max({k, 0}); s < min({(j) + 1, N}); ++s) {

int sp = k;
int ip = s;
D[i][j][k][l][s] += D[ip][jp][kp][lp][sp];
}
}
}
}
}
for (int i = 0; i < N; ++i) {

int ip = i;
for (int j = 0; j < min({(i) + 1, N}); ++j) {

for (int l = 0; l < min({(j) + 1, N}); ++l) {

int kp = j;
int lp = l;
for (int k = 0; k < N; ++k) {

for (int s = max({k, 0}); s < min({(l) + 1, N}); ++s) {

int sp = k;
int jp = s;
D[i][j][k][l][s] += D[ip][jp][kp][lp][sp];
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int l = 0; l < min({(i) + 1, N}); ++l) {

int jp = i;
for (int j = max({i, 0}); j < N; ++j) {

int lp = l;
int kp = j;
for (int k = 0; k < N; ++k) {

for (int s = max({k, 0}); s < min({(l) + 1, N}); ++s) {

int sp = k;
int ip = s;
D[i][j][k][l][s] += D[ip][jp][kp][lp][sp];
}
}
}
}
}
for (int i = 0; i < N; ++i) {

int lp = i;
for (int j = max({i, 0}); j < N; ++j) {

for (int l = max({j, 0}); l < N; ++l) {

int kp = j;
int ip = l;
for (int k = 0; k < N; ++k) {

for (int s = max({k, 0}); s < min({(i) + 1, N}); ++s) {

int sp = k;
int jp = s;
D[i][j][k][l][s] += D[ip][jp][kp][lp][sp];
}
}
}
}
}
for (int i = 0; i < N; ++i) {

int jp = i;
for (int j = 0; j < N; ++j) {

for (int l = max({i, 0}); l < min({(j) + 1, N}); ++l) {

int kp = j;
int ip = l;
for (int k = 0; k < N; ++k) {

for (int s = max({k, 0}); s < min({(i) + 1, N}); ++s) {

int sp = k;
int lp = s;
D[i][j][k][l][s] += D[ip][jp][kp][lp][sp];
}
}
}
}
}
for (int i = 0; i < N; ++i) {

int sp = i;
for (int j = max({i, 0}); j < N; ++j) {

for (int k = 0; k < min({(i) + 1, N}); ++k) {

for (int l = max({j, 0}); l < N; ++l) {

int kp = j;
int ip = k;
for (int s = max({l, 0}); s < N; ++s) {

int jp = l;
int lp = s;
D[i][j][k][l][s] += D[ip][jp][kp][lp][sp];
}
}
}
}
}
for (int i = 0; i < N; ++i) {

int lp = i;
for (int j = max({i, 0}); j < N; ++j) {

for (int k = 0; k < min({(i) + 1, N}); ++k) {

int kp = j;
int ip = k;
for (int l = 0; l < N; ++l) {

for (int s = max({j, 0}); s < min({(l) + 1, N}); ++s) {

int jp = l;
int sp = s;
D[i][j][k][l][s] += D[ip][jp][kp][lp][sp];
}
}
}
}
}
for (int i = 0; i < N; ++i) {

int sp = i;
for (int k = 0; k < min({(i) + 1, N}); ++k) {

int ip = k;
for (int j = 0; j < N; ++j) {

for (int s = max({j, 0}); s < N; ++s) {

for (int l = max({i, 0}); l < min({(j) + 1, N}); ++l) {

int kp = j;
int jp = s;
int lp = l;
D[i][j][k][l][s] += D[ip][jp][kp][lp][sp];
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int l = max({i, 0}); l < N; ++l) {

int jp = i;
for (int k = 0; k < min({(i) + 1, N}); ++k) {

int lp = l;
int ip = k;
for (int j = 0; j < N; ++j) {

for (int s = max({l, 0}); s < min({(j) + 1, N}); ++s) {

int kp = j;
int sp = s;
D[i][j][k][l][s] += D[ip][jp][kp][lp][sp];
}
}
}
}
}
for (int i = 0; i < N; ++i) {

int lp = i;
for (int k = 0; k < min({(i) + 1, N}); ++k) {

int ip = k;
for (int j = 0; j < N; ++j) {

for (int s = max({i, 0}); s < min({(j) + 1, N}); ++s) {

for (int l = max({j, 0}); l < N; ++l) {

int kp = j;
int jp = s;
int sp = l;
D[i][j][k][l][s] += D[ip][jp][kp][lp][sp];
}
}
}
}
}
for (int i = 0; i < N; ++i) {

int jp = i;
for (int k = 0; k < min({(i) + 1, N}); ++k) {

int ip = k;
for (int j = 0; j < N; ++j) {

for (int l = 0; l < min({(j) + 1, N}); ++l) {

int kp = j;
for (int s = max({i, 0}); s < min({(l) + 1, N}); ++s) {

int sp = l;
int lp = s;
D[i][j][k][l][s] += D[ip][jp][kp][lp][sp];
}
}
}
}
}
for (int i = 0; i < N; ++i) {

int ip = i;
for (int j = 0; j < N; ++j) {

for (int l = 0; l < min({(j) + 1, N}); ++l) {

int lp = j;
for (int k = max({j, 0}); k < N; ++k) {

int kp = l;
for (int s = max({k, 0}); s < min({(i) + 1, N}); ++s) {

int jp = k;
int sp = s;
D[i][j][k][l][s] += D[ip][jp][kp][lp][sp];
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int s = max({i, 0}); s < N; ++s) {

int sp = i;
int ip = s;
for (int j = 0; j < N; ++j) {

for (int l = 0; l < min({(j) + 1, N}); ++l) {

int lp = j;
for (int k = max({j, 0}); k < min({(i) + 1, N}); ++k) {

int kp = l;
int jp = k;
D[i][j][k][l][s] += D[ip][jp][kp][lp][sp];
}
}
}
}
}
for (int i = 0; i < N; ++i) {

int ip = i;
for (int k = 0; k < min({(i) + 1, N}); ++k) {

int jp = k;
for (int j = 0; j < N; ++j) {

for (int s = max({j, 0}); s < min({(k) + 1, N}); ++s) {

for (int l = 0; l < min({(j) + 1, N}); ++l) {

int lp = j;
int kp = s;
int sp = l;
D[i][j][k][l][s] += D[ip][jp][kp][lp][sp];
}
}
}
}
}
for (int i = 0; i < N; ++i) {

int kp = i;
for (int k = max({i, 0}); k < N; ++k) {

int jp = k;
for (int j = 0; j < N; ++j) {

for (int s = max({j, 0}); s < min({(i) + 1, N}); ++s) {

for (int l = 0; l < min({(j) + 1, N}); ++l) {

int lp = j;
int ip = s;
int sp = l;
D[i][j][k][l][s] += D[ip][jp][kp][lp][sp];
}
}
}
}
}
for (int i = 0; i < N; ++i) {

int sp = i;
for (int j = 0; j < min({(i) + 1, N}); ++j) {

for (int k = max({i, 0}); k < N; ++k) {

for (int l = 0; l < min({(j) + 1, N}); ++l) {

int lp = j;
for (int s = max({k, 0}); s < N; ++s) {

int jp = k;
int ip = l;
int kp = s;
D[i][j][k][l][s] += D[ip][jp][kp][lp][sp];
}
}
}
}
}
for (int i = 0; i < N; ++i) {

int kp = i;
for (int j = 0; j < min({(i) + 1, N}); ++j) {

for (int l = 0; l < min({(j) + 1, N}); ++l) {

int lp = j;
int ip = l;
for (int k = 0; k < N; ++k) {

for (int s = max({i, 0}); s < min({(k) + 1, N}); ++s) {

int jp = k;
int sp = s;
D[i][j][k][l][s] += D[ip][jp][kp][lp][sp];
}
}
}
}
}
for (int i = 0; i < N; ++i) {

int ip = i;
for (int j = 0; j < N; ++j) {

for (int s = max({j, 0}); s < min({(i) + 1, N}); ++s) {

int lp = j;
for (int k = 0; k < min({(j) + 1, N}); ++k) {

int sp = s;
for (int l = 0; l < min({(k) + 1, N}); ++l) {

int kp = k;
int jp = l;
D[i][j][k][l][s] += D[ip][jp][kp][lp][sp];
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int s = max({i, 0}); s < N; ++s) {

int sp = i;
for (int j = 0; j < min({(i) + 1, N}); ++j) {

int ip = s;
int lp = j;
for (int k = 0; k < min({(j) + 1, N}); ++k) {

for (int l = 0; l < min({(k) + 1, N}); ++l) {

int kp = k;
int jp = l;
D[i][j][k][l][s] += D[ip][jp][kp][lp][sp];
}
}
}
}
}
for (int i = 0; i < N; ++i) {

int ip = i;
for (int j = 0; j < min({(i) + 1, N}); ++j) {

int lp = j;
for (int k = 0; k < N; ++k) {

for (int s = max({k, 0}); s < min({(j) + 1, N}); ++s) {

for (int l = 0; l < min({(k) + 1, N}); ++l) {

int kp = k;
int jp = s;
int sp = l;
D[i][j][k][l][s] += D[ip][jp][kp][lp][sp];
}
}
}
}
}
for (int i = 0; i < N; ++i) {

int jp = i;
for (int j = max({i, 0}); j < N; ++j) {

int lp = j;
for (int k = 0; k < N; ++k) {

for (int s = max({k, 0}); s < min({(i) + 1, N}); ++s) {

for (int l = 0; l < min({(k) + 1, N}); ++l) {

int kp = k;
int ip = s;
int sp = l;
D[i][j][k][l][s] += D[ip][jp][kp][lp][sp];
}
}
}
}
}
for (int i = 0; i < N; ++i) {

int sp = i;
for (int j = max({i, 0}); j < N; ++j) {

for (int k = 0; k < min({(i) + 1, N}); ++k) {

for (int s = max({j, 0}); s < N; ++s) {

int lp = j;
for (int l = 0; l < min({(k) + 1, N}); ++l) {

int kp = k;
int jp = s;
int ip = l;
D[i][j][k][l][s] += D[ip][jp][kp][lp][sp];
}
}
}
}
}
for (int i = 0; i < N; ++i) {

int jp = i;
for (int k = 0; k < min({(i) + 1, N}); ++k) {

for (int l = 0; l < min({(k) + 1, N}); ++l) {

int kp = k;
int ip = l;
for (int j = 0; j < N; ++j) {

for (int s = max({i, 0}); s < min({(j) + 1, N}); ++s) {

int lp = j;
int sp = s;
D[i][j][k][l][s] += D[ip][jp][kp][lp][sp];
}
}
}
}
}
for (int i = 0; i < N; ++i) {

int ip = i;
for (int j = 0; j < N; ++j) {

int lp = j;
for (int k = max({j, 0}); k < min({(i) + 1, N}); ++k) {

for (int l = 0; l < N; ++l) {

int sp = k;
for (int s = max({l, 0}); s < min({(j) + 1, N}); ++s) {

int jp = l;
int kp = s;
D[i][j][k][l][s] += D[ip][jp][kp][lp][sp];
}
}
}
}
}
for (int i = 0; i < N; ++i) {

int kp = i;
for (int j = 0; j < min({(i) + 1, N}); ++j) {

for (int k = max({i, 0}); k < N; ++k) {

int lp = j;
int sp = k;
for (int l = 0; l < N; ++l) {

for (int s = max({l, 0}); s < min({(j) + 1, N}); ++s) {

int jp = l;
int ip = s;
D[i][j][k][l][s] += D[ip][jp][kp][lp][sp];
}
}
}
}
}
for (int i = 0; i < N; ++i) {

int ip = i;
for (int j = 0; j < min({(i) + 1, N}); ++j) {

int lp = j;
for (int k = 0; k < min({(j) + 1, N}); ++k) {

for (int l = 0; l < N; ++l) {

int sp = k;
for (int s = max({l, 0}); s < min({(k) + 1, N}); ++s) {

int kp = l;
int jp = s;
D[i][j][k][l][s] += D[ip][jp][kp][lp][sp];
}
}
}
}
}
for (int i = 0; i < N; ++i) {

int jp = i;
for (int j = max({i, 0}); j < N; ++j) {

for (int k = 0; k < min({(i) + 1, N}); ++k) {

int lp = j;
int sp = k;
for (int l = 0; l < N; ++l) {

for (int s = max({l, 0}); s < min({(k) + 1, N}); ++s) {

int kp = l;
int ip = s;
D[i][j][k][l][s] += D[ip][jp][kp][lp][sp];
}
}
}
}
}
for (int i = 0; i < N; ++i) {

int kp = i;
for (int j = max({i, 0}); j < N; ++j) {

int lp = j;
for (int k = max({j, 0}); k < N; ++k) {

for (int l = 0; l < N; ++l) {

int sp = k;
for (int s = max({l, 0}); s < min({(i) + 1, N}); ++s) {

int ip = l;
int jp = s;
D[i][j][k][l][s] += D[ip][jp][kp][lp][sp];
}
}
}
}
}
for (int i = 0; i < N; ++i) {

int jp = i;
for (int j = 0; j < N; ++j) {

int lp = j;
for (int k = max({i, 0}); k < min({(j) + 1, N}); ++k) {

for (int l = 0; l < N; ++l) {

int sp = k;
for (int s = max({l, 0}); s < min({(i) + 1, N}); ++s) {

int ip = l;
int kp = s;
D[i][j][k][l][s] += D[ip][jp][kp][lp][sp];
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int l = 0; l < min({(i) + 1, N}); ++l) {

int sp = i;
for (int j = max({i, 0}); j < N; ++j) {

int jp = l;
int lp = j;
for (int k = max({j, 0}); k < N; ++k) {

for (int s = max({k, 0}); s < N; ++s) {

int ip = k;
int kp = s;
D[i][j][k][l][s] += D[ip][jp][kp][lp][sp];
}
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
for (int k = 0; k < N; ++k) {

for (int s = max({j, 0}); s < min({(k) + 1, N}); ++s) {

int ip = k;
int sp = s;
D[i][j][k][l][s] += D[ip][jp][kp][lp][sp];
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int l = 0; l < min({(i) + 1, N}); ++l) {

int sp = i;
int kp = l;
for (int j = 0; j < N; ++j) {

for (int s = max({j, 0}); s < N; ++s) {

int lp = j;
for (int k = max({i, 0}); k < min({(j) + 1, N}); ++k) {

int jp = s;
int ip = k;
D[i][j][k][l][s] += D[ip][jp][kp][lp][sp];
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int l = 0; l < min({(i) + 1, N}); ++l) {

int jp = i;
for (int k = max({i, 0}); k < N; ++k) {

int kp = l;
int ip = k;
for (int j = 0; j < N; ++j) {

for (int s = max({k, 0}); s < min({(j) + 1, N}); ++s) {

int lp = j;
int sp = s;
D[i][j][k][l][s] += D[ip][jp][kp][lp][sp];
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int l = 0; l < min({(i) + 1, N}); ++l) {

int kp = i;
int sp = l;
for (int j = 0; j < N; ++j) {

for (int s = max({i, 0}); s < min({(j) + 1, N}); ++s) {

int lp = j;
for (int k = max({j, 0}); k < N; ++k) {

int jp = s;
int ip = k;
D[i][j][k][l][s] += D[ip][jp][kp][lp][sp];
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int l = 0; l < min({(i) + 1, N}); ++l) {

int jp = i;
int sp = l;
for (int j = 0; j < N; ++j) {

int lp = j;
for (int k = 0; k < min({(j) + 1, N}); ++k) {

for (int s = max({i, 0}); s < min({(k) + 1, N}); ++s) {

int ip = k;
int kp = s;
D[i][j][k][l][s] += D[ip][jp][kp][lp][sp];
}
}
}
}
}
for (int i = 0; i < N; ++i) {

int ip = i;
for (int j = 0; j < N; ++j) {

for (int s = 0; s < min({(j) + 1, N}); ++s) {

int sp = j;
for (int k = max({j, 0}); k < N; ++k) {

int lp = s;
for (int l = max({k, 0}); l < min({(i) + 1, N}); ++l) {

int jp = k;
int kp = l;
D[i][j][k][l][s] += D[ip][jp][kp][lp][sp];
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int l = max({i, 0}); l < N; ++l) {

int lp = i;
int kp = l;
for (int j = 0; j < N; ++j) {

for (int s = 0; s < min({(j) + 1, N}); ++s) {

int sp = j;
for (int k = max({j, 0}); k < min({(i) + 1, N}); ++k) {

int ip = s;
int jp = k;
D[i][j][k][l][s] += D[ip][jp][kp][lp][sp];
}
}
}
}
}
for (int i = 0; i < N; ++i) {

int ip = i;
for (int k = 0; k < min({(i) + 1, N}); ++k) {

int jp = k;
for (int j = 0; j < N; ++j) {

for (int s = 0; s < min({(j) + 1, N}); ++s) {

for (int l = max({j, 0}); l < min({(k) + 1, N}); ++l) {

int sp = j;
int kp = s;
int lp = l;
D[i][j][k][l][s] += D[ip][jp][kp][lp][sp];
}
}
}
}
}
for (int i = 0; i < N; ++i) {

int kp = i;
for (int k = max({i, 0}); k < N; ++k) {

int jp = k;
for (int j = 0; j < N; ++j) {

for (int s = 0; s < min({(j) + 1, N}); ++s) {

for (int l = max({j, 0}); l < min({(i) + 1, N}); ++l) {

int sp = j;
int ip = s;
int lp = l;
D[i][j][k][l][s] += D[ip][jp][kp][lp][sp];
}
}
}
}
}
for (int i = 0; i < N; ++i) {

int lp = i;
for (int j = 0; j < min({(i) + 1, N}); ++j) {

for (int k = max({i, 0}); k < N; ++k) {

for (int s = 0; s < min({(j) + 1, N}); ++s) {

int sp = j;
for (int l = max({k, 0}); l < N; ++l) {

int jp = k;
int kp = s;
int ip = l;
D[i][j][k][l][s] += D[ip][jp][kp][lp][sp];
}
}
}
}
}
for (int i = 0; i < N; ++i) {

int kp = i;
for (int j = 0; j < min({(i) + 1, N}); ++j) {

for (int s = 0; s < min({(j) + 1, N}); ++s) {

int sp = j;
int lp = s;
for (int k = 0; k < N; ++k) {

for (int l = max({i, 0}); l < min({(k) + 1, N}); ++l) {

int jp = k;
int ip = l;
D[i][j][k][l][s] += D[ip][jp][kp][lp][sp];
}
}
}
}
}
for (int i = 0; i < N; ++i) {

int ip = i;
for (int j = 0; j < N; ++j) {

for (int l = max({j, 0}); l < min({(i) + 1, N}); ++l) {

int sp = j;
for (int k = 0; k < min({(j) + 1, N}); ++k) {

int jp = l;
for (int s = 0; s < min({(k) + 1, N}); ++s) {

int kp = k;
int lp = s;
D[i][j][k][l][s] += D[ip][jp][kp][lp][sp];
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int l = max({i, 0}); l < N; ++l) {

int lp = i;
for (int j = 0; j < min({(i) + 1, N}); ++j) {

int jp = l;
int sp = j;
for (int k = 0; k < min({(j) + 1, N}); ++k) {

for (int s = 0; s < min({(k) + 1, N}); ++s) {

int kp = k;
int ip = s;
D[i][j][k][l][s] += D[ip][jp][kp][lp][sp];
}
}
}
}
}
for (int i = 0; i < N; ++i) {

int ip = i;
for (int j = 0; j < min({(i) + 1, N}); ++j) {

int sp = j;
for (int k = 0; k < N; ++k) {

for (int s = 0; s < min({(k) + 1, N}); ++s) {

for (int l = max({k, 0}); l < min({(j) + 1, N}); ++l) {

int kp = k;
int jp = s;
int lp = l;
D[i][j][k][l][s] += D[ip][jp][kp][lp][sp];
}
}
}
}
}
for (int i = 0; i < N; ++i) {

int jp = i;
for (int j = max({i, 0}); j < N; ++j) {

int sp = j;
for (int k = 0; k < N; ++k) {

for (int s = 0; s < min({(k) + 1, N}); ++s) {

for (int l = max({k, 0}); l < min({(i) + 1, N}); ++l) {

int kp = k;
int ip = s;
int lp = l;
D[i][j][k][l][s] += D[ip][jp][kp][lp][sp];
}
}
}
}
}
for (int i = 0; i < N; ++i) {

int lp = i;
for (int j = max({i, 0}); j < N; ++j) {

for (int k = 0; k < min({(i) + 1, N}); ++k) {

for (int l = max({j, 0}); l < N; ++l) {

int sp = j;
for (int s = 0; s < min({(k) + 1, N}); ++s) {

int kp = k;
int ip = l;
int jp = s;
D[i][j][k][l][s] += D[ip][jp][kp][lp][sp];
}
}
}
}
}
for (int i = 0; i < N; ++i) {

int jp = i;
for (int k = 0; k < min({(i) + 1, N}); ++k) {

for (int s = 0; s < min({(k) + 1, N}); ++s) {

int kp = k;
int lp = s;
for (int j = 0; j < N; ++j) {

for (int l = max({i, 0}); l < min({(j) + 1, N}); ++l) {

int sp = j;
int ip = l;
D[i][j][k][l][s] += D[ip][jp][kp][lp][sp];
}
}
}
}
}
for (int i = 0; i < N; ++i) {

int ip = i;
for (int j = 0; j < N; ++j) {

for (int l = 0; l < min({(j) + 1, N}); ++l) {

int sp = j;
for (int k = max({j, 0}); k < min({(i) + 1, N}); ++k) {

for (int s = 0; s < min({(l) + 1, N}); ++s) {

int jp = l;
int lp = k;
int kp = s;
D[i][j][k][l][s] += D[ip][jp][kp][lp][sp];
}
}
}
}
}
for (int i = 0; i < N; ++i) {

int kp = i;
for (int j = 0; j < min({(i) + 1, N}); ++j) {

for (int k = max({i, 0}); k < N; ++k) {

for (int l = 0; l < min({(j) + 1, N}); ++l) {

int sp = j;
int lp = k;
for (int s = 0; s < min({(l) + 1, N}); ++s) {

int jp = l;
int ip = s;
D[i][j][k][l][s] += D[ip][jp][kp][lp][sp];
}
}
}
}
}
for (int i = 0; i < N; ++i) {

int ip = i;
for (int j = 0; j < min({(i) + 1, N}); ++j) {

int sp = j;
for (int k = 0; k < min({(j) + 1, N}); ++k) {

for (int l = 0; l < min({(k) + 1, N}); ++l) {

int lp = k;
for (int s = 0; s < min({(l) + 1, N}); ++s) {

int kp = l;
int jp = s;
D[i][j][k][l][s] += D[ip][jp][kp][lp][sp];
}
}
}
}
}
for (int i = 0; i < N; ++i) {

int jp = i;
for (int j = max({i, 0}); j < N; ++j) {

for (int k = 0; k < min({(i) + 1, N}); ++k) {

int sp = j;
for (int l = 0; l < min({(k) + 1, N}); ++l) {

int lp = k;
for (int s = 0; s < min({(l) + 1, N}); ++s) {

int kp = l;
int ip = s;
D[i][j][k][l][s] += D[ip][jp][kp][lp][sp];
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int l = 0; l < min({(i) + 1, N}); ++l) {

int kp = i;
for (int j = max({i, 0}); j < N; ++j) {

for (int s = 0; s < min({(l) + 1, N}); ++s) {

int ip = l;
int sp = j;
for (int k = max({j, 0}); k < N; ++k) {

int jp = s;
int lp = k;
D[i][j][k][l][s] += D[ip][jp][kp][lp][sp];
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int l = 0; l < min({(i) + 1, N}); ++l) {

int jp = i;
for (int s = 0; s < min({(l) + 1, N}); ++s) {

int ip = l;
int kp = s;
for (int j = 0; j < N; ++j) {

int sp = j;
for (int k = max({i, 0}); k < min({(j) + 1, N}); ++k) {

int lp = k;
D[i][j][k][l][s] += D[ip][jp][kp][lp][sp];
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int s = 0; s < min({(i) + 1, N}); ++s) {

int lp = i;
for (int j = max({i, 0}); j < N; ++j) {

int kp = s;
int sp = j;
for (int k = max({j, 0}); k < N; ++k) {

for (int l = max({k, 0}); l < N; ++l) {

int ip = k;
int jp = l;
D[i][j][k][l][s] += D[ip][jp][kp][lp][sp];
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int s = 0; s < min({(i) + 1, N}); ++s) {

int kp = i;
for (int j = max({i, 0}); j < N; ++j) {

int lp = s;
int sp = j;
for (int k = 0; k < N; ++k) {

for (int l = max({j, 0}); l < min({(k) + 1, N}); ++l) {

int ip = k;
int jp = l;
D[i][j][k][l][s] += D[ip][jp][kp][lp][sp];
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int s = 0; s < min({(i) + 1, N}); ++s) {

int lp = i;
int jp = s;
for (int j = 0; j < N; ++j) {

for (int l = max({j, 0}); l < N; ++l) {

int sp = j;
for (int k = max({i, 0}); k < min({(j) + 1, N}); ++k) {

int kp = l;
int ip = k;
D[i][j][k][l][s] += D[ip][jp][kp][lp][sp];
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int s = 0; s < min({(i) + 1, N}); ++s) {

int jp = i;
for (int k = max({i, 0}); k < N; ++k) {

int lp = s;
int ip = k;
for (int j = 0; j < N; ++j) {

for (int l = max({k, 0}); l < min({(j) + 1, N}); ++l) {

int sp = j;
int kp = l;
D[i][j][k][l][s] += D[ip][jp][kp][lp][sp];
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int s = 0; s < min({(i) + 1, N}); ++s) {

int kp = i;
int jp = s;
for (int j = 0; j < N; ++j) {

for (int l = max({i, 0}); l < min({(j) + 1, N}); ++l) {

int sp = j;
for (int k = max({j, 0}); k < N; ++k) {

int lp = l;
int ip = k;
D[i][j][k][l][s] += D[ip][jp][kp][lp][sp];
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int s = 0; s < min({(i) + 1, N}); ++s) {

int jp = i;
int kp = s;
for (int j = 0; j < N; ++j) {

int sp = j;
for (int k = 0; k < min({(j) + 1, N}); ++k) {

for (int l = max({i, 0}); l < min({(k) + 1, N}); ++l) {

int ip = k;
int lp = l;
D[i][j][k][l][s] += D[ip][jp][kp][lp][sp];
}
}
}
}
}
for (int i = 0; i < N; ++i) {

int sp = i;
for (int j = max({i, 0}); j < N; ++j) {

int ip = j;
for (int k = max({j, 0}); k < N; ++k) {

for (int l = max({k, 0}); l < N; ++l) {

int jp = k;
for (int s = max({l, 0}); s < N; ++s) {

int kp = l;
int lp = s;
D[i][j][k][l][s] += D[ip][jp][kp][lp][sp];
}
}
}
}
}
for (int i = 0; i < N; ++i) {

int lp = i;
for (int j = max({i, 0}); j < N; ++j) {

int ip = j;
for (int k = max({j, 0}); k < N; ++k) {

for (int l = 0; l < N; ++l) {

int jp = k;
for (int s = max({k, 0}); s < min({(l) + 1, N}); ++s) {

int kp = l;
int sp = s;
D[i][j][k][l][s] += D[ip][jp][kp][lp][sp];
}
}
}
}
}
for (int i = 0; i < N; ++i) {

int sp = i;
for (int j = max({i, 0}); j < N; ++j) {

int ip = j;
for (int k = 0; k < N; ++k) {

for (int s = max({k, 0}); s < N; ++s) {

for (int l = max({j, 0}); l < min({(k) + 1, N}); ++l) {

int jp = k;
int kp = s;
int lp = l;
D[i][j][k][l][s] += D[ip][jp][kp][lp][sp];
}
}
}
}
}
for (int i = 0; i < N; ++i) {

int kp = i;
for (int j = max({i, 0}); j < N; ++j) {

for (int l = max({j, 0}); l < N; ++l) {

int ip = j;
int lp = l;
for (int k = 0; k < N; ++k) {

for (int s = max({l, 0}); s < min({(k) + 1, N}); ++s) {

int jp = k;
int sp = s;
D[i][j][k][l][s] += D[ip][jp][kp][lp][sp];
}
}
}
}
}
for (int i = 0; i < N; ++i) {

int lp = i;
for (int j = max({i, 0}); j < N; ++j) {

int ip = j;
for (int k = 0; k < N; ++k) {

for (int s = max({j, 0}); s < min({(k) + 1, N}); ++s) {

for (int l = max({k, 0}); l < N; ++l) {

int jp = k;
int kp = s;
int sp = l;
D[i][j][k][l][s] += D[ip][jp][kp][lp][sp];
}
}
}
}
}
for (int i = 0; i < N; ++i) {

int kp = i;
for (int j = max({i, 0}); j < N; ++j) {

int ip = j;
for (int k = 0; k < N; ++k) {

for (int l = 0; l < min({(k) + 1, N}); ++l) {

int jp = k;
for (int s = max({j, 0}); s < min({(l) + 1, N}); ++s) {

int sp = l;
int lp = s;
D[i][j][k][l][s] += D[ip][jp][kp][lp][sp];
}
}
}
}
}
for (int i = 0; i < N; ++i) {

int sp = i;
for (int j = 0; j < N; ++j) {

for (int l = max({j, 0}); l < N; ++l) {

int ip = j;
for (int k = max({i, 0}); k < min({(j) + 1, N}); ++k) {

for (int s = max({l, 0}); s < N; ++s) {

int jp = l;
int kp = k;
int lp = s;
D[i][j][k][l][s] += D[ip][jp][kp][lp][sp];
}
}
}
}
}
for (int i = 0; i < N; ++i) {

int lp = i;
for (int j = 0; j < N; ++j) {

int ip = j;
for (int k = max({i, 0}); k < min({(j) + 1, N}); ++k) {

for (int l = 0; l < N; ++l) {

int kp = k;
for (int s = max({j, 0}); s < min({(l) + 1, N}); ++s) {

int jp = l;
int sp = s;
D[i][j][k][l][s] += D[ip][jp][kp][lp][sp];
}
}
}
}
}
for (int i = 0; i < N; ++i) {

int sp = i;
for (int k = max({i, 0}); k < N; ++k) {

int kp = k;
for (int j = 0; j < N; ++j) {

for (int s = max({j, 0}); s < N; ++s) {

for (int l = max({k, 0}); l < min({(j) + 1, N}); ++l) {

int ip = j;
int jp = s;
int lp = l;
D[i][j][k][l][s] += D[ip][jp][kp][lp][sp];
}
}
}
}
}
for (int i = 0; i < N; ++i) {

int jp = i;
for (int k = max({i, 0}); k < N; ++k) {

for (int l = max({k, 0}); l < N; ++l) {

int kp = k;
int lp = l;
for (int j = 0; j < N; ++j) {

for (int s = max({l, 0}); s < min({(j) + 1, N}); ++s) {

int ip = j;
int sp = s;
D[i][j][k][l][s] += D[ip][jp][kp][lp][sp];
}
}
}
}
}
for (int i = 0; i < N; ++i) {

int lp = i;
for (int k = max({i, 0}); k < N; ++k) {

int kp = k;
for (int j = 0; j < N; ++j) {

for (int s = max({k, 0}); s < min({(j) + 1, N}); ++s) {

for (int l = max({j, 0}); l < N; ++l) {

int ip = j;
int jp = s;
int sp = l;
D[i][j][k][l][s] += D[ip][jp][kp][lp][sp];
}
}
}
}
}
for (int i = 0; i < N; ++i) {

int jp = i;
for (int k = max({i, 0}); k < N; ++k) {

int kp = k;
for (int j = 0; j < N; ++j) {

for (int l = 0; l < min({(j) + 1, N}); ++l) {

int ip = j;
for (int s = max({k, 0}); s < min({(l) + 1, N}); ++s) {

int sp = l;
int lp = s;
D[i][j][k][l][s] += D[ip][jp][kp][lp][sp];
}
}
}
}
}
for (int i = 0; i < N; ++i) {

int sp = i;
for (int j = 0; j < N; ++j) {

for (int l = max({i, 0}); l < min({(j) + 1, N}); ++l) {

int ip = j;
for (int k = max({j, 0}); k < N; ++k) {

int jp = l;
for (int s = max({k, 0}); s < N; ++s) {

int lp = k;
int kp = s;
D[i][j][k][l][s] += D[ip][jp][kp][lp][sp];
}
}
}
}
}
for (int i = 0; i < N; ++i) {

int kp = i;
for (int j = 0; j < N; ++j) {

for (int l = max({i, 0}); l < min({(j) + 1, N}); ++l) {

int ip = j;
int jp = l;
for (int k = 0; k < N; ++k) {

for (int s = max({j, 0}); s < min({(k) + 1, N}); ++s) {

int lp = k;
int sp = s;
D[i][j][k][l][s] += D[ip][jp][kp][lp][sp];
}
}
}
}
}
for (int i = 0; i < N; ++i) {

int sp = i;
for (int j = 0; j < N; ++j) {

for (int s = max({j, 0}); s < N; ++s) {

int ip = j;
for (int k = 0; k < min({(j) + 1, N}); ++k) {

int jp = s;
for (int l = max({i, 0}); l < min({(k) + 1, N}); ++l) {

int lp = k;
int kp = l;
D[i][j][k][l][s] += D[ip][jp][kp][lp][sp];
}
}
}
}
}
for (int i = 0; i < N; ++i) {

int jp = i;
for (int j = 0; j < N; ++j) {

int ip = j;
for (int k = 0; k < N; ++k) {

for (int s = max({k, 0}); s < min({(j) + 1, N}); ++s) {

for (int l = max({i, 0}); l < min({(k) + 1, N}); ++l) {

int lp = k;
int sp = s;
int kp = l;
D[i][j][k][l][s] += D[ip][jp][kp][lp][sp];
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int l = max({i, 0}); l < N; ++l) {

int kp = i;
int sp = l;
for (int j = 0; j < N; ++j) {

for (int s = max({l, 0}); s < min({(j) + 1, N}); ++s) {

int ip = j;
for (int k = max({j, 0}); k < N; ++k) {

int jp = s;
int lp = k;
D[i][j][k][l][s] += D[ip][jp][kp][lp][sp];
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int l = max({i, 0}); l < N; ++l) {

int jp = i;
int sp = l;
for (int j = 0; j < N; ++j) {

int ip = j;
for (int k = 0; k < min({(j) + 1, N}); ++k) {

for (int s = max({l, 0}); s < min({(k) + 1, N}); ++s) {

int lp = k;
int kp = s;
D[i][j][k][l][s] += D[ip][jp][kp][lp][sp];
}
}
}
}
}
for (int i = 0; i < N; ++i) {

int lp = i;
for (int j = 0; j < N; ++j) {

for (int s = max({i, 0}); s < min({(j) + 1, N}); ++s) {

int ip = j;
for (int k = max({j, 0}); k < N; ++k) {

int kp = s;
for (int l = max({k, 0}); l < N; ++l) {

int sp = k;
int jp = l;
D[i][j][k][l][s] += D[ip][jp][kp][lp][sp];
}
}
}
}
}
for (int i = 0; i < N; ++i) {

int kp = i;
for (int j = 0; j < N; ++j) {

for (int s = max({i, 0}); s < min({(j) + 1, N}); ++s) {

int ip = j;
int lp = s;
for (int k = 0; k < N; ++k) {

for (int l = max({j, 0}); l < min({(k) + 1, N}); ++l) {

int sp = k;
int jp = l;
D[i][j][k][l][s] += D[ip][jp][kp][lp][sp];
}
}
}
}
}
for (int i = 0; i < N; ++i) {

int lp = i;
for (int j = 0; j < N; ++j) {

for (int l = max({j, 0}); l < N; ++l) {

int ip = j;
for (int k = 0; k < min({(j) + 1, N}); ++k) {

int kp = l;
for (int s = max({i, 0}); s < min({(k) + 1, N}); ++s) {

int sp = k;
int jp = s;
D[i][j][k][l][s] += D[ip][jp][kp][lp][sp];
}
}
}
}
}
for (int i = 0; i < N; ++i) {

int jp = i;
for (int j = 0; j < N; ++j) {

int ip = j;
for (int k = 0; k < N; ++k) {

for (int s = max({i, 0}); s < min({(k) + 1, N}); ++s) {

for (int l = max({k, 0}); l < min({(j) + 1, N}); ++l) {

int sp = k;
int lp = s;
int kp = l;
D[i][j][k][l][s] += D[ip][jp][kp][lp][sp];
}
}
}
}
}
for (int i = 0; i < N; ++i) {

int kp = i;
for (int j = 0; j < N; ++j) {

for (int l = 0; l < min({(j) + 1, N}); ++l) {

int ip = j;
for (int k = max({j, 0}); k < N; ++k) {

for (int s = max({i, 0}); s < min({(l) + 1, N}); ++s) {

int lp = l;
int sp = k;
int jp = s;
D[i][j][k][l][s] += D[ip][jp][kp][lp][sp];
}
}
}
}
}
for (int i = 0; i < N; ++i) {

int jp = i;
for (int j = 0; j < N; ++j) {

int ip = j;
for (int k = 0; k < min({(j) + 1, N}); ++k) {

for (int l = 0; l < min({(k) + 1, N}); ++l) {

int sp = k;
for (int s = max({i, 0}); s < min({(l) + 1, N}); ++s) {

int lp = l;
int kp = s;
D[i][j][k][l][s] += D[ip][jp][kp][lp][sp];
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int t = max({i, 0}); t < N; ++t) {

int tp = i;
int ip = t;
for (int j = 0; j < N; ++j) {

int jp = j;
for (int k = max({j, 0}); k < N; ++k) {

for (int l = max({k, 0}); l < N; ++l) {

int kp = k;
for (int s = max({l, 0}); s < min({(i) + 1, N}); ++s) {

int lp = l;
int sp = s;
E[i][j][k][l][s][t] += E[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int s = 0; s < min({(i) + 1, N}); ++s) {

int ip = i;
int tp = s;
for (int j = 0; j < N; ++j) {

int jp = j;
for (int k = max({j, 0}); k < N; ++k) {

for (int l = max({k, 0}); l < N; ++l) {

int kp = k;
for (int t = max({l, 0}); t < min({(s) + 1, N}); ++t) {

int lp = l;
int sp = t;
E[i][j][k][l][s][t] += E[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int s = max({i, 0}); s < N; ++s) {

int sp = i;
int tp = s;
for (int j = 0; j < N; ++j) {

int jp = j;
for (int k = max({j, 0}); k < N; ++k) {

for (int l = max({k, 0}); l < N; ++l) {

int kp = k;
for (int t = max({l, 0}); t < min({(i) + 1, N}); ++t) {

int lp = l;
int ip = t;
E[i][j][k][l][s][t] += E[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int s = max({i, 0}); s < N; ++s) {

int tp = i;
for (int t = max({s, 0}); t < N; ++t) {

int ip = s;
int sp = t;
for (int j = 0; j < N; ++j) {

int jp = j;
for (int k = max({j, 0}); k < N; ++k) {

for (int l = max({k, 0}); l < min({(i) + 1, N}); ++l) {

int kp = k;
int lp = l;
E[i][j][k][l][s][t] += E[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

int sp = i;
for (int j = 0; j < N; ++j) {

int jp = j;
for (int k = max({j, 0}); k < N; ++k) {

for (int l = max({k, 0}); l < min({(i) + 1, N}); ++l) {

int kp = k;
int lp = l;
for (int s = 0; s < N; ++s) {

for (int t = max({i, 0}); t < min({(s) + 1, N}); ++t) {

int ip = s;
int tp = t;
E[i][j][k][l][s][t] += E[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

int ip = i;
for (int j = 0; j < N; ++j) {

int jp = j;
for (int k = max({j, 0}); k < N; ++k) {

for (int l = 0; l < N; ++l) {

int kp = k;
for (int s = max({k, 0}); s < min({(l) + 1, N}); ++s) {

for (int t = max({l, 0}); t < min({(i) + 1, N}); ++t) {

int sp = l;
int lp = s;
int tp = t;
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

int tp = i;
int ip = t;
int sp = l;
for (int j = 0; j < N; ++j) {

int jp = j;
for (int k = max({j, 0}); k < N; ++k) {

for (int s = max({k, 0}); s < min({(l) + 1, N}); ++s) {

int kp = k;
int lp = s;
E[i][j][k][l][s][t] += E[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int l = 0; l < min({(i) + 1, N}); ++l) {

int ip = i;
int sp = l;
for (int j = 0; j < N; ++j) {

int jp = j;
for (int k = max({j, 0}); k < N; ++k) {

for (int s = max({k, 0}); s < N; ++s) {

int kp = k;
for (int t = max({s, 0}); t < min({(l) + 1, N}); ++t) {

int tp = s;
int lp = t;
E[i][j][k][l][s][t] += E[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int l = max({i, 0}); l < N; ++l) {

int lp = i;
int sp = l;
for (int j = 0; j < N; ++j) {

int jp = j;
for (int k = max({j, 0}); k < N; ++k) {

for (int s = max({k, 0}); s < N; ++s) {

int kp = k;
for (int t = max({s, 0}); t < min({(i) + 1, N}); ++t) {

int tp = s;
int ip = t;
E[i][j][k][l][s][t] += E[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int l = max({i, 0}); l < N; ++l) {

int tp = i;
for (int t = max({l, 0}); t < N; ++t) {

int sp = l;
int lp = t;
for (int j = 0; j < N; ++j) {

int jp = j;
for (int k = max({j, 0}); k < N; ++k) {

for (int s = max({k, 0}); s < min({(i) + 1, N}); ++s) {

int kp = k;
int ip = s;
E[i][j][k][l][s][t] += E[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

int lp = i;
for (int j = 0; j < N; ++j) {

int jp = j;
for (int k = max({j, 0}); k < N; ++k) {

for (int s = max({k, 0}); s < min({(i) + 1, N}); ++s) {

int kp = k;
int ip = s;
for (int l = 0; l < N; ++l) {

for (int t = max({i, 0}); t < min({(l) + 1, N}); ++t) {

int sp = l;
int tp = t;
E[i][j][k][l][s][t] += E[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

int ip = i;
for (int j = 0; j < N; ++j) {

int jp = j;
for (int k = max({j, 0}); k < N; ++k) {

for (int l = 0; l < N; ++l) {

int kp = k;
for (int s = max({l, 0}); s < min({(i) + 1, N}); ++s) {

for (int t = max({k, 0}); t < min({(l) + 1, N}); ++t) {

int tp = l;
int lp = s;
int sp = t;
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

int sp = i;
int lp = s;
int tp = l;
for (int j = 0; j < N; ++j) {

int jp = j;
for (int k = max({j, 0}); k < N; ++k) {

for (int t = max({k, 0}); t < min({(l) + 1, N}); ++t) {

int kp = k;
int ip = t;
E[i][j][k][l][s][t] += E[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int l = 0; l < min({(i) + 1, N}); ++l) {

int ip = i;
for (int s = 0; s < min({(l) + 1, N}); ++s) {

int tp = l;
int sp = s;
for (int j = 0; j < N; ++j) {

int jp = j;
for (int k = max({j, 0}); k < N; ++k) {

for (int t = max({k, 0}); t < min({(s) + 1, N}); ++t) {

int kp = k;
int lp = t;
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

int lp = i;
int sp = s;
int tp = l;
for (int j = 0; j < N; ++j) {

int jp = j;
for (int k = max({j, 0}); k < N; ++k) {

for (int t = max({k, 0}); t < min({(s) + 1, N}); ++t) {

int kp = k;
int ip = t;
E[i][j][k][l][s][t] += E[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int l = max({i, 0}); l < N; ++l) {

int sp = i;
for (int s = max({l, 0}); s < N; ++s) {

int tp = l;
int ip = s;
for (int j = 0; j < N; ++j) {

int jp = j;
for (int k = max({j, 0}); k < N; ++k) {

for (int t = max({k, 0}); t < min({(i) + 1, N}); ++t) {

int kp = k;
int lp = t;
E[i][j][k][l][s][t] += E[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

int lp = i;
for (int j = 0; j < N; ++j) {

int jp = j;
for (int k = max({j, 0}); k < N; ++k) {

for (int t = max({k, 0}); t < min({(i) + 1, N}); ++t) {

int kp = k;
int sp = t;
for (int l = 0; l < N; ++l) {

for (int s = max({i, 0}); s < min({(l) + 1, N}); ++s) {

int tp = l;
int ip = s;
E[i][j][k][l][s][t] += E[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int l = max({i, 0}); l < N; ++l) {

int tp = i;
for (int s = max({l, 0}); s < N; ++s) {

int ip = l;
for (int t = max({s, 0}); t < N; ++t) {

int lp = s;
int sp = t;
for (int j = 0; j < N; ++j) {

int jp = j;
for (int k = max({j, 0}); k < min({(i) + 1, N}); ++k) {

int kp = k;
E[i][j][k][l][s][t] += E[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int l = max({i, 0}); l < N; ++l) {

int sp = i;
int ip = l;
for (int j = 0; j < N; ++j) {

int jp = j;
for (int k = max({j, 0}); k < min({(i) + 1, N}); ++k) {

int kp = k;
for (int s = 0; s < N; ++s) {

for (int t = max({l, 0}); t < min({(s) + 1, N}); ++t) {

int lp = s;
int tp = t;
E[i][j][k][l][s][t] += E[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int j = 0; j < N; ++j) {

int tp = i;
int jp = j;
for (int k = max({j, 0}); k < min({(i) + 1, N}); ++k) {

for (int l = 0; l < N; ++l) {

int kp = k;
for (int s = max({i, 0}); s < min({(l) + 1, N}); ++s) {

for (int t = max({l, 0}); t < N; ++t) {

int ip = l;
int sp = s;
int lp = t;
E[i][j][k][l][s][t] += E[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int s = max({i, 0}); s < N; ++s) {

int lp = i;
int sp = s;
for (int j = 0; j < N; ++j) {

int jp = j;
for (int k = max({j, 0}); k < min({(i) + 1, N}); ++k) {

for (int l = 0; l < N; ++l) {

int kp = k;
for (int t = max({s, 0}); t < min({(l) + 1, N}); ++t) {

int ip = l;
int tp = t;
E[i][j][k][l][s][t] += E[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

int sp = i;
for (int j = 0; j < N; ++j) {

int jp = j;
for (int k = max({j, 0}); k < min({(i) + 1, N}); ++k) {

for (int l = 0; l < N; ++l) {

int kp = k;
for (int s = max({l, 0}); s < N; ++s) {

for (int t = max({i, 0}); t < min({(l) + 1, N}); ++t) {

int ip = l;
int tp = s;
int lp = t;
E[i][j][k][l][s][t] += E[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

int lp = i;
for (int j = 0; j < N; ++j) {

int jp = j;
for (int k = max({j, 0}); k < min({(i) + 1, N}); ++k) {

for (int l = 0; l < N; ++l) {

int kp = k;
for (int s = 0; s < min({(l) + 1, N}); ++s) {

int ip = l;
for (int t = max({i, 0}); t < min({(s) + 1, N}); ++t) {

int tp = s;
int sp = t;
E[i][j][k][l][s][t] += E[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

int ip = i;
for (int j = 0; j < N; ++j) {

int jp = j;
for (int k = 0; k < N; ++k) {

for (int s = max({k, 0}); s < N; ++s) {

for (int l = max({j, 0}); l < min({(k) + 1, N}); ++l) {

int lp = k;
for (int t = max({s, 0}); t < min({(i) + 1, N}); ++t) {

int sp = s;
int kp = l;
int tp = t;
E[i][j][k][l][s][t] += E[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int t = max({i, 0}); t < N; ++t) {

int tp = i;
int ip = t;
for (int j = 0; j < N; ++j) {

int jp = j;
for (int k = 0; k < N; ++k) {

for (int s = max({k, 0}); s < min({(i) + 1, N}); ++s) {

for (int l = max({j, 0}); l < min({(k) + 1, N}); ++l) {

int lp = k;
int sp = s;
int kp = l;
E[i][j][k][l][s][t] += E[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int s = 0; s < min({(i) + 1, N}); ++s) {

int ip = i;
int tp = s;
for (int j = 0; j < N; ++j) {

int jp = j;
for (int k = 0; k < N; ++k) {

for (int t = max({k, 0}); t < min({(s) + 1, N}); ++t) {

for (int l = max({j, 0}); l < min({(k) + 1, N}); ++l) {

int lp = k;
int sp = t;
int kp = l;
E[i][j][k][l][s][t] += E[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int s = max({i, 0}); s < N; ++s) {

int sp = i;
int tp = s;
for (int j = 0; j < N; ++j) {

int jp = j;
for (int k = 0; k < N; ++k) {

for (int t = max({k, 0}); t < min({(i) + 1, N}); ++t) {

for (int l = max({j, 0}); l < min({(k) + 1, N}); ++l) {

int lp = k;
int ip = t;
int kp = l;
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

int tp = i;
for (int t = max({s, 0}); t < N; ++t) {

int ip = s;
int lp = k;
int sp = t;
for (int j = 0; j < N; ++j) {

for (int l = max({j, 0}); l < min({(k) + 1, N}); ++l) {

int jp = j;
int kp = l;
E[i][j][k][l][s][t] += E[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

int sp = i;
for (int k = 0; k < min({(i) + 1, N}); ++k) {

int lp = k;
for (int j = 0; j < N; ++j) {

for (int l = max({j, 0}); l < min({(k) + 1, N}); ++l) {

int jp = j;
int kp = l;
for (int s = 0; s < N; ++s) {

for (int t = max({i, 0}); t < min({(s) + 1, N}); ++t) {

int ip = s;
int tp = t;
E[i][j][k][l][s][t] += E[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

int ip = i;
for (int j = 0; j < N; ++j) {

for (int l = max({j, 0}); l < N; ++l) {

int jp = j;
int sp = l;
for (int k = 0; k < N; ++k) {

for (int s = max({l, 0}); s < min({(k) + 1, N}); ++s) {

for (int t = max({k, 0}); t < min({(i) + 1, N}); ++t) {

int lp = k;
int kp = s;
int tp = t;
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

int tp = i;
int ip = t;
int lp = k;
for (int j = 0; j < N; ++j) {

for (int l = max({j, 0}); l < N; ++l) {

int jp = j;
for (int s = max({l, 0}); s < min({(k) + 1, N}); ++s) {

int sp = l;
int kp = s;
E[i][j][k][l][s][t] += E[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

int ip = i;
for (int k = 0; k < min({(i) + 1, N}); ++k) {

int lp = k;
for (int j = 0; j < N; ++j) {

for (int l = max({j, 0}); l < N; ++l) {

int jp = j;
for (int s = max({l, 0}); s < N; ++s) {

int sp = l;
for (int t = max({s, 0}); t < min({(k) + 1, N}); ++t) {

int tp = s;
int kp = t;
E[i][j][k][l][s][t] += E[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

int kp = i;
for (int k = max({i, 0}); k < N; ++k) {

int lp = k;
for (int j = 0; j < N; ++j) {

for (int l = max({j, 0}); l < N; ++l) {

int jp = j;
for (int s = max({l, 0}); s < N; ++s) {

int sp = l;
for (int t = max({s, 0}); t < min({(i) + 1, N}); ++t) {

int tp = s;
int ip = t;
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

int tp = i;
for (int l = max({j, 0}); l < N; ++l) {

int jp = j;
for (int t = max({k, 0}); t < N; ++t) {

int lp = k;
for (int s = max({l, 0}); s < min({(i) + 1, N}); ++s) {

int sp = l;
int kp = t;
int ip = s;
E[i][j][k][l][s][t] += E[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

int kp = i;
for (int j = 0; j < N; ++j) {

for (int l = max({j, 0}); l < N; ++l) {

int jp = j;
for (int s = max({l, 0}); s < min({(i) + 1, N}); ++s) {

int sp = l;
int ip = s;
for (int k = 0; k < N; ++k) {

for (int t = max({i, 0}); t < min({(k) + 1, N}); ++t) {

int lp = k;
int tp = t;
E[i][j][k][l][s][t] += E[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

int ip = i;
for (int j = 0; j < N; ++j) {

for (int l = max({j, 0}); l < N; ++l) {

int jp = j;
int tp = l;
for (int k = 0; k < N; ++k) {

for (int s = max({k, 0}); s < min({(i) + 1, N}); ++s) {

for (int t = max({l, 0}); t < min({(k) + 1, N}); ++t) {

int lp = k;
int kp = s;
int sp = t;
E[i][j][k][l][s][t] += E[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int s = max({i, 0}); s < N; ++s) {

int sp = i;
for (int k = 0; k < min({(i) + 1, N}); ++k) {

int kp = s;
int lp = k;
for (int j = 0; j < N; ++j) {

for (int l = max({j, 0}); l < N; ++l) {

int jp = j;
for (int t = max({l, 0}); t < min({(k) + 1, N}); ++t) {

int tp = l;
int ip = t;
E[i][j][k][l][s][t] += E[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

int ip = i;
for (int k = 0; k < min({(i) + 1, N}); ++k) {

for (int s = 0; s < min({(k) + 1, N}); ++s) {

int lp = k;
int sp = s;
for (int j = 0; j < N; ++j) {

for (int l = max({j, 0}); l < N; ++l) {

int jp = j;
for (int t = max({l, 0}); t < min({(s) + 1, N}); ++t) {

int tp = l;
int kp = t;
E[i][j][k][l][s][t] += E[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int s = 0; s < min({(i) + 1, N}); ++s) {

int kp = i;
for (int k = max({i, 0}); k < N; ++k) {

int sp = s;
int lp = k;
for (int j = 0; j < N; ++j) {

for (int l = max({j, 0}); l < N; ++l) {

int jp = j;
for (int t = max({l, 0}); t < min({(s) + 1, N}); ++t) {

int tp = l;
int ip = t;
E[i][j][k][l][s][t] += E[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

int sp = i;
for (int k = max({i, 0}); k < N; ++k) {

for (int s = max({k, 0}); s < N; ++s) {

int lp = k;
int ip = s;
for (int j = 0; j < N; ++j) {

for (int l = max({j, 0}); l < N; ++l) {

int jp = j;
for (int t = max({l, 0}); t < min({(i) + 1, N}); ++t) {

int tp = l;
int kp = t;
E[i][j][k][l][s][t] += E[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

int kp = i;
for (int j = 0; j < N; ++j) {

for (int l = max({j, 0}); l < N; ++l) {

int jp = j;
for (int t = max({l, 0}); t < min({(i) + 1, N}); ++t) {

int tp = l;
int sp = t;
for (int k = 0; k < N; ++k) {

for (int s = max({i, 0}); s < min({(k) + 1, N}); ++s) {

int lp = k;
int ip = s;
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

int tp = i;
for (int l = max({j, 0}); l < min({(i) + 1, N}); ++l) {

int jp = j;
for (int s = max({k, 0}); s < N; ++s) {

int lp = k;
int ip = l;
for (int t = max({s, 0}); t < N; ++t) {

int kp = s;
int sp = t;
E[i][j][k][l][s][t] += E[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

int sp = i;
for (int k = max({i, 0}); k < N; ++k) {

int lp = k;
for (int j = 0; j < N; ++j) {

for (int l = max({j, 0}); l < min({(i) + 1, N}); ++l) {

int jp = j;
int ip = l;
for (int s = 0; s < N; ++s) {

for (int t = max({k, 0}); t < min({(s) + 1, N}); ++t) {

int kp = s;
int tp = t;
E[i][j][k][l][s][t] += E[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int j = 0; j < N; ++j) {

int tp = i;
for (int l = max({j, 0}); l < min({(i) + 1, N}); ++l) {

int jp = j;
int ip = l;
for (int k = 0; k < N; ++k) {

for (int s = max({i, 0}); s < min({(k) + 1, N}); ++s) {

for (int t = max({k, 0}); t < N; ++t) {

int lp = k;
int sp = s;
int kp = t;
E[i][j][k][l][s][t] += E[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int s = max({i, 0}); s < N; ++s) {

int kp = i;
int sp = s;
for (int j = 0; j < N; ++j) {

for (int l = max({j, 0}); l < min({(i) + 1, N}); ++l) {

int jp = j;
int ip = l;
for (int k = 0; k < N; ++k) {

for (int t = max({s, 0}); t < min({(k) + 1, N}); ++t) {

int lp = k;
int tp = t;
E[i][j][k][l][s][t] += E[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

int sp = i;
for (int j = 0; j < N; ++j) {

for (int l = max({j, 0}); l < min({(i) + 1, N}); ++l) {

int jp = j;
int ip = l;
for (int k = 0; k < N; ++k) {

for (int s = max({k, 0}); s < N; ++s) {

for (int t = max({i, 0}); t < min({(k) + 1, N}); ++t) {

int lp = k;
int tp = s;
int kp = t;
E[i][j][k][l][s][t] += E[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

int kp = i;
for (int j = 0; j < N; ++j) {

for (int l = max({j, 0}); l < min({(i) + 1, N}); ++l) {

int jp = j;
int ip = l;
for (int k = 0; k < N; ++k) {

for (int s = 0; s < min({(k) + 1, N}); ++s) {

int lp = k;
for (int t = max({i, 0}); t < min({(s) + 1, N}); ++t) {

int tp = s;
int sp = t;
E[i][j][k][l][s][t] += E[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

int ip = i;
for (int j = 0; j < N; ++j) {

int jp = j;
for (int k = 0; k < N; ++k) {

for (int s = max({j, 0}); s < min({(k) + 1, N}); ++s) {

for (int l = max({k, 0}); l < N; ++l) {

int sp = k;
int lp = s;
for (int t = max({l, 0}); t < min({(i) + 1, N}); ++t) {

int kp = l;
int tp = t;
E[i][j][k][l][s][t] += E[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int t = max({i, 0}); t < N; ++t) {

int tp = i;
int ip = t;
for (int j = 0; j < N; ++j) {

int jp = j;
for (int k = 0; k < N; ++k) {

for (int s = max({j, 0}); s < min({(k) + 1, N}); ++s) {

for (int l = max({k, 0}); l < min({(i) + 1, N}); ++l) {

int sp = k;
int lp = s;
int kp = l;
E[i][j][k][l][s][t] += E[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int l = 0; l < min({(i) + 1, N}); ++l) {

int ip = i;
int kp = l;
for (int j = 0; j < N; ++j) {

int jp = j;
for (int k = 0; k < N; ++k) {

for (int s = max({j, 0}); s < min({(k) + 1, N}); ++s) {

for (int t = max({k, 0}); t < min({(l) + 1, N}); ++t) {

int sp = k;
int tp = s;
int lp = t;
E[i][j][k][l][s][t] += E[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int l = max({i, 0}); l < N; ++l) {

int lp = i;
int kp = l;
for (int j = 0; j < N; ++j) {

int jp = j;
for (int k = 0; k < N; ++k) {

for (int s = max({j, 0}); s < min({(k) + 1, N}); ++s) {

for (int t = max({k, 0}); t < min({(i) + 1, N}); ++t) {

int sp = k;
int tp = s;
int ip = t;
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

int tp = i;
for (int t = max({l, 0}); t < N; ++t) {

int kp = l;
int sp = k;
int lp = t;
for (int j = 0; j < N; ++j) {

for (int s = max({j, 0}); s < min({(k) + 1, N}); ++s) {

int jp = j;
int ip = s;
E[i][j][k][l][s][t] += E[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

int lp = i;
for (int k = 0; k < min({(i) + 1, N}); ++k) {

int sp = k;
for (int j = 0; j < N; ++j) {

for (int s = max({j, 0}); s < min({(k) + 1, N}); ++s) {

int jp = j;
int ip = s;
for (int l = 0; l < N; ++l) {

for (int t = max({i, 0}); t < min({(l) + 1, N}); ++t) {

int kp = l;
int tp = t;
E[i][j][k][l][s][t] += E[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

int ip = i;
for (int j = 0; j < N; ++j) {

int jp = j;
for (int k = 0; k < N; ++k) {

for (int t = max({k, 0}); t < min({(i) + 1, N}); ++t) {

for (int l = 0; l < min({(k) + 1, N}); ++l) {

int sp = k;
int tp = t;
for (int s = max({j, 0}); s < min({(l) + 1, N}); ++s) {

int lp = l;
int kp = s;
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

int tp = i;
int ip = t;
for (int l = 0; l < min({(k) + 1, N}); ++l) {

int sp = k;
int lp = l;
for (int j = 0; j < N; ++j) {

for (int s = max({j, 0}); s < min({(l) + 1, N}); ++s) {

int jp = j;
int kp = s;
E[i][j][k][l][s][t] += E[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

int ip = i;
for (int k = 0; k < min({(i) + 1, N}); ++k) {

int sp = k;
for (int j = 0; j < N; ++j) {

int jp = j;
for (int l = 0; l < N; ++l) {

for (int s = max({j, 0}); s < min({(l) + 1, N}); ++s) {

for (int t = max({l, 0}); t < min({(k) + 1, N}); ++t) {

int lp = l;
int tp = s;
int kp = t;
E[i][j][k][l][s][t] += E[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

int kp = i;
for (int k = max({i, 0}); k < N; ++k) {

int sp = k;
for (int j = 0; j < N; ++j) {

int jp = j;
for (int l = 0; l < N; ++l) {

for (int s = max({j, 0}); s < min({(l) + 1, N}); ++s) {

for (int t = max({l, 0}); t < min({(i) + 1, N}); ++t) {

int lp = l;
int tp = s;
int ip = t;
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

int tp = i;
int lp = l;
for (int t = max({k, 0}); t < N; ++t) {

int sp = k;
int kp = t;
for (int j = 0; j < N; ++j) {

for (int s = max({j, 0}); s < min({(l) + 1, N}); ++s) {

int jp = j;
int ip = s;
E[i][j][k][l][s][t] += E[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int l = 0; l < min({(i) + 1, N}); ++l) {

int kp = i;
int lp = l;
for (int j = 0; j < N; ++j) {

for (int s = max({j, 0}); s < min({(l) + 1, N}); ++s) {

int jp = j;
int ip = s;
for (int k = 0; k < N; ++k) {

for (int t = max({i, 0}); t < min({(k) + 1, N}); ++t) {

int sp = k;
int tp = t;
E[i][j][k][l][s][t] += E[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

int ip = i;
for (int j = 0; j < N; ++j) {

for (int s = max({j, 0}); s < N; ++s) {

int jp = j;
int kp = s;
for (int k = 0; k < N; ++k) {

for (int t = max({s, 0}); t < min({(k) + 1, N}); ++t) {

for (int l = max({k, 0}); l < min({(i) + 1, N}); ++l) {

int sp = k;
int lp = t;
int tp = l;
E[i][j][k][l][s][t] += E[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int l = max({i, 0}); l < N; ++l) {

int lp = i;
for (int k = 0; k < min({(i) + 1, N}); ++k) {

int tp = l;
int sp = k;
for (int j = 0; j < N; ++j) {

for (int s = max({j, 0}); s < N; ++s) {

int jp = j;
for (int t = max({s, 0}); t < min({(k) + 1, N}); ++t) {

int kp = s;
int ip = t;
E[i][j][k][l][s][t] += E[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

int ip = i;
for (int k = 0; k < min({(i) + 1, N}); ++k) {

for (int l = 0; l < min({(k) + 1, N}); ++l) {

int sp = k;
int tp = l;
for (int j = 0; j < N; ++j) {

for (int s = max({j, 0}); s < N; ++s) {

int jp = j;
for (int t = max({s, 0}); t < min({(l) + 1, N}); ++t) {

int lp = s;
int kp = t;
E[i][j][k][l][s][t] += E[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int l = 0; l < min({(i) + 1, N}); ++l) {

int kp = i;
for (int k = max({i, 0}); k < N; ++k) {

int tp = l;
int sp = k;
for (int j = 0; j < N; ++j) {

for (int s = max({j, 0}); s < N; ++s) {

int jp = j;
for (int t = max({s, 0}); t < min({(l) + 1, N}); ++t) {

int lp = s;
int ip = t;
E[i][j][k][l][s][t] += E[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

int lp = i;
for (int k = max({i, 0}); k < N; ++k) {

for (int l = max({k, 0}); l < N; ++l) {

int sp = k;
int tp = l;
for (int j = 0; j < N; ++j) {

for (int s = max({j, 0}); s < N; ++s) {

int jp = j;
for (int t = max({s, 0}); t < min({(i) + 1, N}); ++t) {

int ip = s;
int kp = t;
E[i][j][k][l][s][t] += E[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

int kp = i;
for (int j = 0; j < N; ++j) {

for (int s = max({j, 0}); s < N; ++s) {

int jp = j;
for (int t = max({s, 0}); t < min({(i) + 1, N}); ++t) {

int ip = s;
int lp = t;
for (int k = 0; k < N; ++k) {

for (int l = max({i, 0}); l < min({(k) + 1, N}); ++l) {

int sp = k;
int tp = l;
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

int tp = i;
for (int s = max({j, 0}); s < min({(i) + 1, N}); ++s) {

int jp = j;
for (int l = max({k, 0}); l < N; ++l) {

int sp = k;
int kp = s;
for (int t = max({l, 0}); t < N; ++t) {

int ip = l;
int lp = t;
E[i][j][k][l][s][t] += E[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

int lp = i;
for (int k = max({i, 0}); k < N; ++k) {

int sp = k;
for (int j = 0; j < N; ++j) {

for (int s = max({j, 0}); s < min({(i) + 1, N}); ++s) {

int jp = j;
int kp = s;
for (int l = 0; l < N; ++l) {

for (int t = max({k, 0}); t < min({(l) + 1, N}); ++t) {

int ip = l;
int tp = t;
E[i][j][k][l][s][t] += E[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int j = 0; j < N; ++j) {

int tp = i;
for (int s = max({j, 0}); s < min({(i) + 1, N}); ++s) {

int jp = j;
int lp = s;
for (int k = 0; k < N; ++k) {

for (int t = max({k, 0}); t < N; ++t) {

for (int l = max({i, 0}); l < min({(k) + 1, N}); ++l) {

int sp = k;
int kp = t;
int ip = l;
E[i][j][k][l][s][t] += E[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int l = max({i, 0}); l < N; ++l) {

int kp = i;
int ip = l;
for (int j = 0; j < N; ++j) {

for (int s = max({j, 0}); s < min({(i) + 1, N}); ++s) {

int jp = j;
int lp = s;
for (int k = 0; k < N; ++k) {

for (int t = max({l, 0}); t < min({(k) + 1, N}); ++t) {

int sp = k;
int tp = t;
E[i][j][k][l][s][t] += E[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

int lp = i;
for (int j = 0; j < N; ++j) {

for (int s = max({j, 0}); s < min({(i) + 1, N}); ++s) {

int jp = j;
int tp = s;
for (int k = 0; k < N; ++k) {

for (int t = max({i, 0}); t < min({(k) + 1, N}); ++t) {

for (int l = max({k, 0}); l < N; ++l) {

int sp = k;
int kp = t;
int ip = l;
E[i][j][k][l][s][t] += E[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

int kp = i;
for (int j = 0; j < N; ++j) {

for (int s = max({j, 0}); s < min({(i) + 1, N}); ++s) {

int jp = j;
int tp = s;
for (int k = 0; k < N; ++k) {

for (int l = 0; l < min({(k) + 1, N}); ++l) {

int sp = k;
for (int t = max({i, 0}); t < min({(l) + 1, N}); ++t) {

int ip = l;
int lp = t;
E[i][j][k][l][s][t] += E[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

int ip = i;
for (int j = 0; j < N; ++j) {

int jp = j;
for (int k = 0; k < N; ++k) {

for (int t = max({j, 0}); t < min({(k) + 1, N}); ++t) {

for (int l = max({k, 0}); l < N; ++l) {

int tp = k;
int sp = t;
for (int s = max({l, 0}); s < min({(i) + 1, N}); ++s) {

int kp = l;
int lp = s;
E[i][j][k][l][s][t] += E[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int s = max({i, 0}); s < N; ++s) {

int sp = i;
int lp = s;
for (int j = 0; j < N; ++j) {

int jp = j;
for (int k = 0; k < N; ++k) {

for (int t = max({j, 0}); t < min({(k) + 1, N}); ++t) {

for (int l = max({k, 0}); l < min({(i) + 1, N}); ++l) {

int tp = k;
int ip = t;
int kp = l;
E[i][j][k][l][s][t] += E[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int l = 0; l < min({(i) + 1, N}); ++l) {

int ip = i;
int kp = l;
for (int j = 0; j < N; ++j) {

int jp = j;
for (int k = 0; k < N; ++k) {

for (int s = max({k, 0}); s < min({(l) + 1, N}); ++s) {

for (int t = max({j, 0}); t < min({(k) + 1, N}); ++t) {

int tp = k;
int sp = s;
int lp = t;
E[i][j][k][l][s][t] += E[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int l = max({i, 0}); l < N; ++l) {

int lp = i;
int kp = l;
for (int j = 0; j < N; ++j) {

int jp = j;
for (int k = 0; k < N; ++k) {

for (int s = max({k, 0}); s < min({(i) + 1, N}); ++s) {

for (int t = max({j, 0}); t < min({(k) + 1, N}); ++t) {

int tp = k;
int sp = s;
int ip = t;
E[i][j][k][l][s][t] += E[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int l = max({i, 0}); l < N; ++l) {

int sp = i;
for (int k = 0; k < min({(i) + 1, N}); ++k) {

for (int s = max({l, 0}); s < N; ++s) {

int kp = l;
int tp = k;
int ip = s;
for (int j = 0; j < N; ++j) {

for (int t = max({j, 0}); t < min({(k) + 1, N}); ++t) {

int jp = j;
int lp = t;
E[i][j][k][l][s][t] += E[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

int lp = i;
for (int k = 0; k < min({(i) + 1, N}); ++k) {

for (int j = 0; j < N; ++j) {

int tp = k;
for (int t = max({j, 0}); t < min({(k) + 1, N}); ++t) {

int jp = j;
int sp = t;
for (int l = 0; l < N; ++l) {

for (int s = max({i, 0}); s < min({(l) + 1, N}); ++s) {

int kp = l;
int ip = s;
E[i][j][k][l][s][t] += E[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

int ip = i;
for (int j = 0; j < N; ++j) {

int jp = j;
for (int k = 0; k < N; ++k) {

for (int s = max({k, 0}); s < min({(i) + 1, N}); ++s) {

for (int l = 0; l < min({(k) + 1, N}); ++l) {

int tp = k;
int kp = s;
for (int t = max({j, 0}); t < min({(l) + 1, N}); ++t) {

int lp = l;
int sp = t;
E[i][j][k][l][s][t] += E[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int s = max({i, 0}); s < N; ++s) {

int sp = i;
for (int k = 0; k < min({(i) + 1, N}); ++k) {

int kp = s;
for (int l = 0; l < min({(k) + 1, N}); ++l) {

int tp = k;
int lp = l;
for (int j = 0; j < N; ++j) {

for (int t = max({j, 0}); t < min({(l) + 1, N}); ++t) {

int jp = j;
int ip = t;
E[i][j][k][l][s][t] += E[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

int ip = i;
for (int k = 0; k < min({(i) + 1, N}); ++k) {

for (int j = 0; j < N; ++j) {

int tp = k;
int jp = j;
for (int l = 0; l < N; ++l) {

for (int s = max({l, 0}); s < min({(k) + 1, N}); ++s) {

for (int t = max({j, 0}); t < min({(l) + 1, N}); ++t) {

int lp = l;
int sp = s;
int kp = t;
E[i][j][k][l][s][t] += E[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

int kp = i;
for (int k = max({i, 0}); k < N; ++k) {

for (int j = 0; j < N; ++j) {

int tp = k;
int jp = j;
for (int l = 0; l < N; ++l) {

for (int s = max({l, 0}); s < min({(i) + 1, N}); ++s) {

for (int t = max({j, 0}); t < min({(l) + 1, N}); ++t) {

int lp = l;
int sp = s;
int ip = t;
E[i][j][k][l][s][t] += E[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int l = 0; l < min({(i) + 1, N}); ++l) {

int sp = i;
for (int k = max({i, 0}); k < N; ++k) {

int lp = l;
for (int s = max({k, 0}); s < N; ++s) {

int tp = k;
int ip = s;
for (int j = 0; j < N; ++j) {

for (int t = max({j, 0}); t < min({(l) + 1, N}); ++t) {

int jp = j;
int kp = t;
E[i][j][k][l][s][t] += E[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int l = 0; l < min({(i) + 1, N}); ++l) {

int kp = i;
int lp = l;
for (int j = 0; j < N; ++j) {

for (int t = max({j, 0}); t < min({(l) + 1, N}); ++t) {

int jp = j;
int sp = t;
for (int k = 0; k < N; ++k) {

for (int s = max({i, 0}); s < min({(k) + 1, N}); ++s) {

int tp = k;
int ip = s;
E[i][j][k][l][s][t] += E[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

int ip = i;
for (int j = 0; j < N; ++j) {

int jp = j;
for (int k = 0; k < N; ++k) {

for (int s = 0; s < min({(k) + 1, N}); ++s) {

for (int l = max({k, 0}); l < min({(i) + 1, N}); ++l) {

int tp = k;
for (int t = max({j, 0}); t < min({(s) + 1, N}); ++t) {

int kp = s;
int sp = l;
int lp = t;
E[i][j][k][l][s][t] += E[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int l = max({i, 0}); l < N; ++l) {

int lp = i;
for (int k = 0; k < min({(i) + 1, N}); ++k) {

int sp = l;
for (int s = 0; s < min({(k) + 1, N}); ++s) {

int tp = k;
int kp = s;
for (int j = 0; j < N; ++j) {

for (int t = max({j, 0}); t < min({(s) + 1, N}); ++t) {

int jp = j;
int ip = t;
E[i][j][k][l][s][t] += E[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

int ip = i;
for (int k = 0; k < min({(i) + 1, N}); ++k) {

for (int l = 0; l < min({(k) + 1, N}); ++l) {

int tp = k;
for (int s = 0; s < min({(l) + 1, N}); ++s) {

int sp = l;
int lp = s;
for (int j = 0; j < N; ++j) {

for (int t = max({j, 0}); t < min({(s) + 1, N}); ++t) {

int jp = j;
int kp = t;
E[i][j][k][l][s][t] += E[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int l = 0; l < min({(i) + 1, N}); ++l) {

int kp = i;
for (int k = max({i, 0}); k < N; ++k) {

for (int s = 0; s < min({(l) + 1, N}); ++s) {

int sp = l;
int tp = k;
int lp = s;
for (int j = 0; j < N; ++j) {

for (int t = max({j, 0}); t < min({(s) + 1, N}); ++t) {

int jp = j;
int ip = t;
E[i][j][k][l][s][t] += E[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int s = 0; s < min({(i) + 1, N}); ++s) {

int lp = i;
for (int k = max({i, 0}); k < N; ++k) {

int ip = s;
for (int l = max({k, 0}); l < N; ++l) {

int tp = k;
int sp = l;
for (int j = 0; j < N; ++j) {

for (int t = max({j, 0}); t < min({(s) + 1, N}); ++t) {

int jp = j;
int kp = t;
E[i][j][k][l][s][t] += E[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int s = 0; s < min({(i) + 1, N}); ++s) {

int kp = i;
int ip = s;
for (int j = 0; j < N; ++j) {

for (int t = max({j, 0}); t < min({(s) + 1, N}); ++t) {

int jp = j;
int lp = t;
for (int k = 0; k < N; ++k) {

for (int l = max({i, 0}); l < min({(k) + 1, N}); ++l) {

int tp = k;
int sp = l;
E[i][j][k][l][s][t] += E[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

int sp = i;
for (int k = max({i, 0}); k < N; ++k) {

for (int l = max({k, 0}); l < N; ++l) {

int tp = k;
for (int s = max({l, 0}); s < N; ++s) {

int ip = l;
int kp = s;
for (int j = 0; j < N; ++j) {

for (int t = max({j, 0}); t < min({(i) + 1, N}); ++t) {

int jp = j;
int lp = t;
E[i][j][k][l][s][t] += E[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

int lp = i;
for (int k = max({i, 0}); k < N; ++k) {

for (int j = 0; j < N; ++j) {

int tp = k;
for (int t = max({j, 0}); t < min({(i) + 1, N}); ++t) {

int jp = j;
int sp = t;
for (int l = 0; l < N; ++l) {

for (int s = max({k, 0}); s < min({(l) + 1, N}); ++s) {

int ip = l;
int kp = s;
E[i][j][k][l][s][t] += E[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

int sp = i;
for (int j = 0; j < N; ++j) {

for (int t = max({j, 0}); t < min({(i) + 1, N}); ++t) {

int jp = j;
int kp = t;
for (int k = 0; k < N; ++k) {

for (int s = max({k, 0}); s < N; ++s) {

for (int l = max({i, 0}); l < min({(k) + 1, N}); ++l) {

int tp = k;
int lp = s;
int ip = l;
E[i][j][k][l][s][t] += E[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int l = max({i, 0}); l < N; ++l) {

int kp = i;
int ip = l;
for (int j = 0; j < N; ++j) {

for (int t = max({j, 0}); t < min({(i) + 1, N}); ++t) {

int jp = j;
int sp = t;
for (int k = 0; k < N; ++k) {

for (int s = max({l, 0}); s < min({(k) + 1, N}); ++s) {

int tp = k;
int lp = s;
E[i][j][k][l][s][t] += E[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

int lp = i;
for (int j = 0; j < N; ++j) {

for (int t = max({j, 0}); t < min({(i) + 1, N}); ++t) {

int jp = j;
int kp = t;
for (int k = 0; k < N; ++k) {

for (int s = max({i, 0}); s < min({(k) + 1, N}); ++s) {

for (int l = max({k, 0}); l < N; ++l) {

int tp = k;
int sp = s;
int ip = l;
E[i][j][k][l][s][t] += E[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

int kp = i;
for (int j = 0; j < N; ++j) {

for (int t = max({j, 0}); t < min({(i) + 1, N}); ++t) {

int jp = j;
int lp = t;
for (int k = 0; k < N; ++k) {

for (int l = 0; l < min({(k) + 1, N}); ++l) {

int tp = k;
for (int s = max({i, 0}); s < min({(l) + 1, N}); ++s) {

int ip = l;
int sp = s;
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

int tp = i;
int jp = j;
for (int l = max({k, 0}); l < N; ++l) {

int ip = k;
for (int s = max({l, 0}); s < N; ++s) {

int kp = l;
for (int t = max({s, 0}); t < N; ++t) {

int lp = s;
int sp = t;
E[i][j][k][l][s][t] += E[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

int sp = i;
for (int j = 0; j < min({(i) + 1, N}); ++j) {

for (int k = max({i, 0}); k < N; ++k) {

int jp = j;
for (int l = max({k, 0}); l < N; ++l) {

int ip = k;
int kp = l;
for (int s = 0; s < N; ++s) {

for (int t = max({l, 0}); t < min({(s) + 1, N}); ++t) {

int lp = s;
int tp = t;
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

int tp = i;
int jp = j;
int ip = k;
for (int l = 0; l < N; ++l) {

for (int s = max({k, 0}); s < min({(l) + 1, N}); ++s) {

for (int t = max({l, 0}); t < N; ++t) {

int kp = l;
int sp = s;
int lp = t;
E[i][j][k][l][s][t] += E[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

int lp = i;
for (int j = 0; j < min({(i) + 1, N}); ++j) {

for (int k = max({i, 0}); k < N; ++k) {

int jp = j;
for (int s = max({k, 0}); s < N; ++s) {

int ip = k;
int sp = s;
for (int l = 0; l < N; ++l) {

for (int t = max({s, 0}); t < min({(l) + 1, N}); ++t) {

int kp = l;
int tp = t;
E[i][j][k][l][s][t] += E[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

int sp = i;
for (int j = 0; j < min({(i) + 1, N}); ++j) {

for (int k = max({i, 0}); k < N; ++k) {

int jp = j;
int ip = k;
for (int l = 0; l < N; ++l) {

for (int s = max({l, 0}); s < N; ++s) {

for (int t = max({k, 0}); t < min({(l) + 1, N}); ++t) {

int kp = l;
int tp = s;
int lp = t;
E[i][j][k][l][s][t] += E[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

int lp = i;
for (int j = 0; j < min({(i) + 1, N}); ++j) {

for (int k = max({i, 0}); k < N; ++k) {

int jp = j;
int ip = k;
for (int l = 0; l < N; ++l) {

for (int s = 0; s < min({(l) + 1, N}); ++s) {

int kp = l;
for (int t = max({k, 0}); t < min({(s) + 1, N}); ++t) {

int tp = s;
int sp = t;
E[i][j][k][l][s][t] += E[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int j = 0; j < min({(i) + 1, N}); ++j) {

int tp = i;
int jp = j;
for (int k = 0; k < N; ++k) {

for (int s = max({k, 0}); s < N; ++s) {

for (int l = max({i, 0}); l < min({(k) + 1, N}); ++l) {

int ip = k;
for (int t = max({s, 0}); t < N; ++t) {

int kp = s;
int lp = l;
int sp = t;
E[i][j][k][l][s][t] += E[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

int sp = i;
for (int j = 0; j < min({(i) + 1, N}); ++j) {

int jp = j;
for (int k = 0; k < N; ++k) {

for (int l = max({i, 0}); l < min({(k) + 1, N}); ++l) {

int ip = k;
int lp = l;
for (int s = 0; s < N; ++s) {

for (int t = max({k, 0}); t < min({(s) + 1, N}); ++t) {

int kp = s;
int tp = t;
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

int tp = i;
int lp = l;
int jp = j;
for (int k = 0; k < N; ++k) {

for (int s = max({l, 0}); s < min({(k) + 1, N}); ++s) {

for (int t = max({k, 0}); t < N; ++t) {

int ip = k;
int sp = s;
int kp = t;
E[i][j][k][l][s][t] += E[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int l = max({i, 0}); l < N; ++l) {

int kp = i;
for (int j = 0; j < min({(i) + 1, N}); ++j) {

for (int s = max({l, 0}); s < N; ++s) {

int lp = l;
int jp = j;
int sp = s;
for (int k = 0; k < N; ++k) {

for (int t = max({s, 0}); t < min({(k) + 1, N}); ++t) {

int ip = k;
int tp = t;
E[i][j][k][l][s][t] += E[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int l = max({i, 0}); l < N; ++l) {

int sp = i;
for (int j = 0; j < min({(i) + 1, N}); ++j) {

int lp = l;
int jp = j;
for (int k = 0; k < N; ++k) {

for (int s = max({k, 0}); s < N; ++s) {

for (int t = max({l, 0}); t < min({(k) + 1, N}); ++t) {

int ip = k;
int tp = s;
int kp = t;
E[i][j][k][l][s][t] += E[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int l = max({i, 0}); l < N; ++l) {

int kp = i;
for (int j = 0; j < min({(i) + 1, N}); ++j) {

int lp = l;
int jp = j;
for (int k = 0; k < N; ++k) {

for (int s = 0; s < min({(k) + 1, N}); ++s) {

int ip = k;
for (int t = max({l, 0}); t < min({(s) + 1, N}); ++t) {

int tp = s;
int sp = t;
E[i][j][k][l][s][t] += E[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int j = 0; j < min({(i) + 1, N}); ++j) {

int tp = i;
int jp = j;
for (int k = 0; k < N; ++k) {

for (int s = max({i, 0}); s < min({(k) + 1, N}); ++s) {

for (int l = max({k, 0}); l < N; ++l) {

int ip = k;
int kp = s;
for (int t = max({l, 0}); t < N; ++t) {

int sp = l;
int lp = t;
E[i][j][k][l][s][t] += E[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

int lp = i;
for (int j = 0; j < min({(i) + 1, N}); ++j) {

int jp = j;
for (int k = 0; k < N; ++k) {

for (int s = max({i, 0}); s < min({(k) + 1, N}); ++s) {

int ip = k;
int kp = s;
for (int l = 0; l < N; ++l) {

for (int t = max({k, 0}); t < min({(l) + 1, N}); ++t) {

int sp = l;
int tp = t;
E[i][j][k][l][s][t] += E[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int j = 0; j < min({(i) + 1, N}); ++j) {

int tp = i;
int jp = j;
for (int k = 0; k < N; ++k) {

for (int t = max({k, 0}); t < N; ++t) {

for (int l = 0; l < min({(k) + 1, N}); ++l) {

int ip = k;
int kp = t;
for (int s = max({i, 0}); s < min({(l) + 1, N}); ++s) {

int sp = l;
int lp = s;
E[i][j][k][l][s][t] += E[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

int kp = i;
for (int j = 0; j < min({(i) + 1, N}); ++j) {

int jp = j;
for (int k = 0; k < N; ++k) {

for (int l = 0; l < N; ++l) {

int ip = k;
for (int s = max({i, 0}); s < min({(l) + 1, N}); ++s) {

for (int t = max({l, 0}); t < min({(k) + 1, N}); ++t) {

int sp = l;
int lp = s;
int tp = t;
E[i][j][k][l][s][t] += E[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int s = max({i, 0}); s < N; ++s) {

int lp = i;
for (int j = 0; j < min({(i) + 1, N}); ++j) {

int tp = s;
int jp = j;
for (int k = 0; k < N; ++k) {

for (int t = max({s, 0}); t < min({(k) + 1, N}); ++t) {

for (int l = max({k, 0}); l < N; ++l) {

int ip = k;
int kp = t;
int sp = l;
E[i][j][k][l][s][t] += E[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int s = max({i, 0}); s < N; ++s) {

int kp = i;
for (int j = 0; j < min({(i) + 1, N}); ++j) {

int tp = s;
int jp = j;
for (int k = 0; k < N; ++k) {

for (int l = 0; l < min({(k) + 1, N}); ++l) {

int ip = k;
for (int t = max({s, 0}); t < min({(l) + 1, N}); ++t) {

int sp = l;
int lp = t;
E[i][j][k][l][s][t] += E[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

int sp = i;
for (int j = 0; j < min({(i) + 1, N}); ++j) {

int jp = j;
for (int k = 0; k < N; ++k) {

for (int t = max({i, 0}); t < min({(k) + 1, N}); ++t) {

for (int l = max({k, 0}); l < N; ++l) {

int ip = k;
int lp = t;
for (int s = max({l, 0}); s < N; ++s) {

int tp = l;
int kp = s;
E[i][j][k][l][s][t] += E[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

int lp = i;
for (int j = 0; j < min({(i) + 1, N}); ++j) {

int jp = j;
for (int k = 0; k < N; ++k) {

for (int t = max({i, 0}); t < min({(k) + 1, N}); ++t) {

int ip = k;
int sp = t;
for (int l = 0; l < N; ++l) {

for (int s = max({k, 0}); s < min({(l) + 1, N}); ++s) {

int tp = l;
int kp = s;
E[i][j][k][l][s][t] += E[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

int sp = i;
for (int j = 0; j < min({(i) + 1, N}); ++j) {

int jp = j;
for (int k = 0; k < N; ++k) {

for (int s = max({k, 0}); s < N; ++s) {

for (int l = 0; l < min({(k) + 1, N}); ++l) {

int ip = k;
int lp = s;
for (int t = max({i, 0}); t < min({(l) + 1, N}); ++t) {

int tp = l;
int kp = t;
E[i][j][k][l][s][t] += E[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

int kp = i;
for (int j = 0; j < min({(i) + 1, N}); ++j) {

int jp = j;
for (int k = 0; k < N; ++k) {

for (int l = 0; l < N; ++l) {

int ip = k;
for (int s = max({l, 0}); s < min({(k) + 1, N}); ++s) {

for (int t = max({i, 0}); t < min({(l) + 1, N}); ++t) {

int tp = l;
int lp = s;
int sp = t;
E[i][j][k][l][s][t] += E[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

int lp = i;
for (int j = 0; j < min({(i) + 1, N}); ++j) {

int jp = j;
for (int k = 0; k < N; ++k) {

for (int s = 0; s < min({(k) + 1, N}); ++s) {

for (int l = max({k, 0}); l < N; ++l) {

int ip = k;
for (int t = max({i, 0}); t < min({(s) + 1, N}); ++t) {

int sp = s;
int tp = l;
int kp = t;
E[i][j][k][l][s][t] += E[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

int kp = i;
for (int j = 0; j < min({(i) + 1, N}); ++j) {

int jp = j;
for (int k = 0; k < N; ++k) {

for (int l = 0; l < min({(k) + 1, N}); ++l) {

int ip = k;
for (int s = 0; s < min({(l) + 1, N}); ++s) {

int tp = l;
for (int t = max({i, 0}); t < min({(s) + 1, N}); ++t) {

int sp = s;
int lp = t;
E[i][j][k][l][s][t] += E[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

int ip = i;
for (int j = 0; j < N; ++j) {

for (int l = max({j, 0}); l < N; ++l) {

int kp = j;
for (int k = 0; k < min({(j) + 1, N}); ++k) {

for (int s = max({l, 0}); s < N; ++s) {

int lp = l;
int jp = k;
for (int t = max({s, 0}); t < min({(i) + 1, N}); ++t) {

int sp = s;
int tp = t;
E[i][j][k][l][s][t] += E[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int t = max({i, 0}); t < N; ++t) {

int tp = i;
int ip = t;
for (int j = 0; j < N; ++j) {

for (int l = max({j, 0}); l < N; ++l) {

int kp = j;
for (int k = 0; k < min({(j) + 1, N}); ++k) {

for (int s = max({l, 0}); s < min({(i) + 1, N}); ++s) {

int lp = l;
int jp = k;
int sp = s;
E[i][j][k][l][s][t] += E[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int s = 0; s < min({(i) + 1, N}); ++s) {

int ip = i;
int tp = s;
for (int j = 0; j < N; ++j) {

for (int l = max({j, 0}); l < N; ++l) {

int kp = j;
for (int k = 0; k < min({(j) + 1, N}); ++k) {

for (int t = max({l, 0}); t < min({(s) + 1, N}); ++t) {

int lp = l;
int jp = k;
int sp = t;
E[i][j][k][l][s][t] += E[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int s = max({i, 0}); s < N; ++s) {

int sp = i;
int tp = s;
for (int j = 0; j < N; ++j) {

for (int l = max({j, 0}); l < N; ++l) {

int kp = j;
for (int k = 0; k < min({(j) + 1, N}); ++k) {

for (int t = max({l, 0}); t < min({(i) + 1, N}); ++t) {

int lp = l;
int jp = k;
int ip = t;
E[i][j][k][l][s][t] += E[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int s = max({i, 0}); s < N; ++s) {

int tp = i;
for (int t = max({s, 0}); t < N; ++t) {

int ip = s;
int sp = t;
for (int j = 0; j < N; ++j) {

for (int l = max({j, 0}); l < min({(i) + 1, N}); ++l) {

int kp = j;
for (int k = 0; k < min({(j) + 1, N}); ++k) {

int lp = l;
int jp = k;
E[i][j][k][l][s][t] += E[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

int sp = i;
for (int j = 0; j < N; ++j) {

for (int l = max({j, 0}); l < min({(i) + 1, N}); ++l) {

int kp = j;
for (int k = 0; k < min({(j) + 1, N}); ++k) {

int lp = l;
int jp = k;
for (int s = 0; s < N; ++s) {

for (int t = max({i, 0}); t < min({(s) + 1, N}); ++t) {

int ip = s;
int tp = t;
E[i][j][k][l][s][t] += E[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

int ip = i;
for (int j = 0; j < N; ++j) {

int kp = j;
for (int k = 0; k < min({(j) + 1, N}); ++k) {

for (int l = 0; l < N; ++l) {

int jp = k;
for (int s = max({j, 0}); s < min({(l) + 1, N}); ++s) {

for (int t = max({l, 0}); t < min({(i) + 1, N}); ++t) {

int sp = l;
int lp = s;
int tp = t;
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

int tp = i;
int ip = t;
int sp = l;
for (int j = 0; j < N; ++j) {

for (int s = max({j, 0}); s < min({(l) + 1, N}); ++s) {

int kp = j;
for (int k = 0; k < min({(j) + 1, N}); ++k) {

int lp = s;
int jp = k;
E[i][j][k][l][s][t] += E[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int l = 0; l < min({(i) + 1, N}); ++l) {

int ip = i;
int sp = l;
for (int j = 0; j < N; ++j) {

for (int s = max({j, 0}); s < N; ++s) {

int kp = j;
for (int k = 0; k < min({(j) + 1, N}); ++k) {

for (int t = max({s, 0}); t < min({(l) + 1, N}); ++t) {

int tp = s;
int jp = k;
int lp = t;
E[i][j][k][l][s][t] += E[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int l = max({i, 0}); l < N; ++l) {

int lp = i;
int sp = l;
for (int j = 0; j < N; ++j) {

for (int s = max({j, 0}); s < N; ++s) {

int kp = j;
for (int k = 0; k < min({(j) + 1, N}); ++k) {

for (int t = max({s, 0}); t < min({(i) + 1, N}); ++t) {

int tp = s;
int jp = k;
int ip = t;
E[i][j][k][l][s][t] += E[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int l = max({i, 0}); l < N; ++l) {

int tp = i;
for (int t = max({l, 0}); t < N; ++t) {

int sp = l;
int lp = t;
for (int j = 0; j < N; ++j) {

for (int s = max({j, 0}); s < min({(i) + 1, N}); ++s) {

int kp = j;
for (int k = 0; k < min({(j) + 1, N}); ++k) {

int ip = s;
int jp = k;
E[i][j][k][l][s][t] += E[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

int lp = i;
for (int j = 0; j < N; ++j) {

for (int s = max({j, 0}); s < min({(i) + 1, N}); ++s) {

int kp = j;
for (int k = 0; k < min({(j) + 1, N}); ++k) {

int ip = s;
int jp = k;
for (int l = 0; l < N; ++l) {

for (int t = max({i, 0}); t < min({(l) + 1, N}); ++t) {

int sp = l;
int tp = t;
E[i][j][k][l][s][t] += E[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

int ip = i;
for (int j = 0; j < N; ++j) {

int kp = j;
for (int k = 0; k < min({(j) + 1, N}); ++k) {

for (int l = 0; l < N; ++l) {

int jp = k;
for (int s = max({l, 0}); s < min({(i) + 1, N}); ++s) {

for (int t = max({j, 0}); t < min({(l) + 1, N}); ++t) {

int tp = l;
int lp = s;
int sp = t;
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

int sp = i;
int lp = s;
int tp = l;
for (int j = 0; j < N; ++j) {

for (int t = max({j, 0}); t < min({(l) + 1, N}); ++t) {

int kp = j;
for (int k = 0; k < min({(j) + 1, N}); ++k) {

int ip = t;
int jp = k;
E[i][j][k][l][s][t] += E[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int l = 0; l < min({(i) + 1, N}); ++l) {

int ip = i;
for (int s = 0; s < min({(l) + 1, N}); ++s) {

int tp = l;
int sp = s;
for (int j = 0; j < N; ++j) {

for (int t = max({j, 0}); t < min({(s) + 1, N}); ++t) {

int kp = j;
for (int k = 0; k < min({(j) + 1, N}); ++k) {

int lp = t;
int jp = k;
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

int lp = i;
int sp = s;
int tp = l;
for (int j = 0; j < N; ++j) {

for (int t = max({j, 0}); t < min({(s) + 1, N}); ++t) {

int kp = j;
for (int k = 0; k < min({(j) + 1, N}); ++k) {

int ip = t;
int jp = k;
E[i][j][k][l][s][t] += E[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int l = max({i, 0}); l < N; ++l) {

int sp = i;
for (int s = max({l, 0}); s < N; ++s) {

int tp = l;
int ip = s;
for (int j = 0; j < N; ++j) {

for (int t = max({j, 0}); t < min({(i) + 1, N}); ++t) {

int kp = j;
for (int k = 0; k < min({(j) + 1, N}); ++k) {

int lp = t;
int jp = k;
E[i][j][k][l][s][t] += E[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

int lp = i;
for (int j = 0; j < N; ++j) {

for (int t = max({j, 0}); t < min({(i) + 1, N}); ++t) {

int kp = j;
for (int k = 0; k < min({(j) + 1, N}); ++k) {

int sp = t;
int jp = k;
for (int l = 0; l < N; ++l) {

for (int s = max({i, 0}); s < min({(l) + 1, N}); ++s) {

int tp = l;
int ip = s;
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

int tp = i;
for (int s = max({l, 0}); s < N; ++s) {

int ip = l;
int kp = j;
for (int k = 0; k < min({(j) + 1, N}); ++k) {

for (int t = max({s, 0}); t < N; ++t) {

int lp = s;
int jp = k;
int sp = t;
E[i][j][k][l][s][t] += E[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int l = max({i, 0}); l < N; ++l) {

int sp = i;
for (int j = 0; j < min({(i) + 1, N}); ++j) {

int ip = l;
int kp = j;
for (int k = 0; k < min({(j) + 1, N}); ++k) {

int jp = k;
for (int s = 0; s < N; ++s) {

for (int t = max({l, 0}); t < min({(s) + 1, N}); ++t) {

int lp = s;
int tp = t;
E[i][j][k][l][s][t] += E[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int j = 0; j < min({(i) + 1, N}); ++j) {

int tp = i;
int kp = j;
for (int k = 0; k < min({(j) + 1, N}); ++k) {

for (int l = 0; l < N; ++l) {

int jp = k;
for (int s = max({i, 0}); s < min({(l) + 1, N}); ++s) {

for (int t = max({l, 0}); t < N; ++t) {

int ip = l;
int sp = s;
int lp = t;
E[i][j][k][l][s][t] += E[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int s = max({i, 0}); s < N; ++s) {

int lp = i;
for (int j = 0; j < min({(i) + 1, N}); ++j) {

int sp = s;
int kp = j;
for (int k = 0; k < min({(j) + 1, N}); ++k) {

for (int l = 0; l < N; ++l) {

int jp = k;
for (int t = max({s, 0}); t < min({(l) + 1, N}); ++t) {

int ip = l;
int tp = t;
E[i][j][k][l][s][t] += E[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

int sp = i;
for (int j = 0; j < min({(i) + 1, N}); ++j) {

int kp = j;
for (int k = 0; k < min({(j) + 1, N}); ++k) {

for (int l = 0; l < N; ++l) {

int jp = k;
for (int s = max({l, 0}); s < N; ++s) {

for (int t = max({i, 0}); t < min({(l) + 1, N}); ++t) {

int ip = l;
int tp = s;
int lp = t;
E[i][j][k][l][s][t] += E[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

int lp = i;
for (int j = 0; j < min({(i) + 1, N}); ++j) {

int kp = j;
for (int k = 0; k < min({(j) + 1, N}); ++k) {

for (int l = 0; l < N; ++l) {

int jp = k;
for (int s = 0; s < min({(l) + 1, N}); ++s) {

int ip = l;
for (int t = max({i, 0}); t < min({(s) + 1, N}); ++t) {

int tp = s;
int sp = t;
E[i][j][k][l][s][t] += E[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

int ip = i;
for (int j = 0; j < N; ++j) {

for (int s = max({j, 0}); s < N; ++s) {

int kp = j;
for (int t = max({s, 0}); t < min({(i) + 1, N}); ++t) {

int sp = s;
int tp = t;
for (int k = 0; k < N; ++k) {

for (int l = max({k, 0}); l < min({(j) + 1, N}); ++l) {

int lp = k;
int jp = l;
E[i][j][k][l][s][t] += E[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int t = max({i, 0}); t < N; ++t) {

int tp = i;
int ip = t;
for (int j = 0; j < N; ++j) {

for (int s = max({j, 0}); s < min({(i) + 1, N}); ++s) {

int kp = j;
int sp = s;
for (int k = 0; k < N; ++k) {

for (int l = max({k, 0}); l < min({(j) + 1, N}); ++l) {

int lp = k;
int jp = l;
E[i][j][k][l][s][t] += E[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int s = 0; s < min({(i) + 1, N}); ++s) {

int ip = i;
int tp = s;
for (int j = 0; j < N; ++j) {

for (int t = max({j, 0}); t < min({(s) + 1, N}); ++t) {

int kp = j;
int sp = t;
for (int k = 0; k < N; ++k) {

for (int l = max({k, 0}); l < min({(j) + 1, N}); ++l) {

int lp = k;
int jp = l;
E[i][j][k][l][s][t] += E[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int s = max({i, 0}); s < N; ++s) {

int sp = i;
int tp = s;
for (int j = 0; j < N; ++j) {

for (int t = max({j, 0}); t < min({(i) + 1, N}); ++t) {

int kp = j;
int ip = t;
for (int k = 0; k < N; ++k) {

for (int l = max({k, 0}); l < min({(j) + 1, N}); ++l) {

int lp = k;
int jp = l;
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

int tp = i;
for (int t = max({s, 0}); t < N; ++t) {

int ip = s;
int kp = j;
int sp = t;
for (int k = 0; k < N; ++k) {

for (int l = max({k, 0}); l < min({(j) + 1, N}); ++l) {

int lp = k;
int jp = l;
E[i][j][k][l][s][t] += E[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

int sp = i;
for (int j = 0; j < min({(i) + 1, N}); ++j) {

int kp = j;
for (int k = 0; k < N; ++k) {

for (int l = max({k, 0}); l < min({(j) + 1, N}); ++l) {

int lp = k;
int jp = l;
for (int s = 0; s < N; ++s) {

for (int t = max({i, 0}); t < min({(s) + 1, N}); ++t) {

int ip = s;
int tp = t;
E[i][j][k][l][s][t] += E[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

int ip = i;
for (int j = 0; j < N; ++j) {

for (int t = max({j, 0}); t < min({(i) + 1, N}); ++t) {

int kp = j;
int tp = t;
for (int k = 0; k < N; ++k) {

for (int l = max({k, 0}); l < N; ++l) {

int lp = k;
for (int s = max({l, 0}); s < min({(j) + 1, N}); ++s) {

int sp = l;
int jp = s;
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

int tp = i;
int ip = t;
int kp = j;
for (int k = 0; k < N; ++k) {

for (int l = max({k, 0}); l < N; ++l) {

int lp = k;
for (int s = max({l, 0}); s < min({(j) + 1, N}); ++s) {

int sp = l;
int jp = s;
E[i][j][k][l][s][t] += E[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

int ip = i;
for (int j = 0; j < min({(i) + 1, N}); ++j) {

int kp = j;
for (int k = 0; k < N; ++k) {

for (int l = max({k, 0}); l < N; ++l) {

int lp = k;
for (int s = max({l, 0}); s < N; ++s) {

int sp = l;
for (int t = max({s, 0}); t < min({(j) + 1, N}); ++t) {

int tp = s;
int jp = t;
E[i][j][k][l][s][t] += E[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

int jp = i;
for (int j = max({i, 0}); j < N; ++j) {

int kp = j;
for (int k = 0; k < N; ++k) {

for (int l = max({k, 0}); l < N; ++l) {

int lp = k;
for (int s = max({l, 0}); s < N; ++s) {

int sp = l;
for (int t = max({s, 0}); t < min({(i) + 1, N}); ++t) {

int tp = s;
int ip = t;
E[i][j][k][l][s][t] += E[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int j = max({i, 0}); j < N; ++j) {

int tp = i;
for (int t = max({j, 0}); t < N; ++t) {

int kp = j;
int jp = t;
for (int k = 0; k < N; ++k) {

for (int l = max({k, 0}); l < N; ++l) {

int lp = k;
for (int s = max({l, 0}); s < min({(i) + 1, N}); ++s) {

int sp = l;
int ip = s;
E[i][j][k][l][s][t] += E[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

int jp = i;
for (int j = 0; j < N; ++j) {

for (int t = max({i, 0}); t < min({(j) + 1, N}); ++t) {

int kp = j;
int tp = t;
for (int k = 0; k < N; ++k) {

for (int l = max({k, 0}); l < N; ++l) {

int lp = k;
for (int s = max({l, 0}); s < min({(i) + 1, N}); ++s) {

int sp = l;
int ip = s;
E[i][j][k][l][s][t] += E[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

int ip = i;
for (int j = 0; j < N; ++j) {

for (int s = max({j, 0}); s < min({(i) + 1, N}); ++s) {

int kp = j;
int jp = s;
for (int k = 0; k < N; ++k) {

for (int l = max({k, 0}); l < N; ++l) {

int lp = k;
for (int t = max({l, 0}); t < min({(j) + 1, N}); ++t) {

int tp = l;
int sp = t;
E[i][j][k][l][s][t] += E[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int s = max({i, 0}); s < N; ++s) {

int sp = i;
for (int j = 0; j < min({(i) + 1, N}); ++j) {

int jp = s;
int kp = j;
for (int k = 0; k < N; ++k) {

for (int l = max({k, 0}); l < N; ++l) {

int lp = k;
for (int t = max({l, 0}); t < min({(j) + 1, N}); ++t) {

int tp = l;
int ip = t;
E[i][j][k][l][s][t] += E[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

int ip = i;
for (int j = 0; j < min({(i) + 1, N}); ++j) {

for (int s = 0; s < min({(j) + 1, N}); ++s) {

int kp = j;
int sp = s;
for (int k = 0; k < N; ++k) {

for (int l = max({k, 0}); l < N; ++l) {

int lp = k;
for (int t = max({l, 0}); t < min({(s) + 1, N}); ++t) {

int tp = l;
int jp = t;
E[i][j][k][l][s][t] += E[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int s = 0; s < min({(i) + 1, N}); ++s) {

int jp = i;
for (int j = max({i, 0}); j < N; ++j) {

int sp = s;
int kp = j;
for (int k = 0; k < N; ++k) {

for (int l = max({k, 0}); l < N; ++l) {

int lp = k;
for (int t = max({l, 0}); t < min({(s) + 1, N}); ++t) {

int tp = l;
int ip = t;
E[i][j][k][l][s][t] += E[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

int sp = i;
for (int j = max({i, 0}); j < N; ++j) {

for (int s = max({j, 0}); s < N; ++s) {

int kp = j;
int ip = s;
for (int k = 0; k < N; ++k) {

for (int l = max({k, 0}); l < N; ++l) {

int lp = k;
for (int t = max({l, 0}); t < min({(i) + 1, N}); ++t) {

int tp = l;
int jp = t;
E[i][j][k][l][s][t] += E[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

int jp = i;
for (int j = 0; j < N; ++j) {

for (int s = max({i, 0}); s < min({(j) + 1, N}); ++s) {

int kp = j;
int ip = s;
for (int k = 0; k < N; ++k) {

for (int l = max({k, 0}); l < N; ++l) {

int lp = k;
for (int t = max({l, 0}); t < min({(i) + 1, N}); ++t) {

int tp = l;
int sp = t;
E[i][j][k][l][s][t] += E[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int j = max({i, 0}); j < N; ++j) {

int tp = i;
for (int s = max({j, 0}); s < N; ++s) {

int kp = j;
for (int t = max({s, 0}); t < N; ++t) {

int jp = s;
int sp = t;
for (int k = 0; k < N; ++k) {

for (int l = max({k, 0}); l < min({(i) + 1, N}); ++l) {

int lp = k;
int ip = l;
E[i][j][k][l][s][t] += E[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

int sp = i;
for (int j = max({i, 0}); j < N; ++j) {

int kp = j;
for (int k = 0; k < N; ++k) {

for (int l = max({k, 0}); l < min({(i) + 1, N}); ++l) {

int lp = k;
int ip = l;
for (int s = 0; s < N; ++s) {

for (int t = max({j, 0}); t < min({(s) + 1, N}); ++t) {

int jp = s;
int tp = t;
E[i][j][k][l][s][t] += E[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int j = 0; j < N; ++j) {

int tp = i;
for (int s = max({i, 0}); s < min({(j) + 1, N}); ++s) {

for (int t = max({j, 0}); t < N; ++t) {

int kp = j;
int sp = s;
int jp = t;
for (int k = 0; k < N; ++k) {

for (int l = max({k, 0}); l < min({(i) + 1, N}); ++l) {

int lp = k;
int ip = l;
E[i][j][k][l][s][t] += E[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int s = max({i, 0}); s < N; ++s) {

int jp = i;
int sp = s;
for (int j = 0; j < N; ++j) {

for (int t = max({s, 0}); t < min({(j) + 1, N}); ++t) {

int kp = j;
int tp = t;
for (int k = 0; k < N; ++k) {

for (int l = max({k, 0}); l < min({(i) + 1, N}); ++l) {

int lp = k;
int ip = l;
E[i][j][k][l][s][t] += E[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

int sp = i;
for (int j = 0; j < N; ++j) {

for (int s = max({j, 0}); s < N; ++s) {

for (int t = max({i, 0}); t < min({(j) + 1, N}); ++t) {

int kp = j;
int tp = s;
int jp = t;
for (int k = 0; k < N; ++k) {

for (int l = max({k, 0}); l < min({(i) + 1, N}); ++l) {

int lp = k;
int ip = l;
E[i][j][k][l][s][t] += E[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

int jp = i;
for (int j = 0; j < N; ++j) {

for (int s = 0; s < min({(j) + 1, N}); ++s) {

int kp = j;
for (int t = max({i, 0}); t < min({(s) + 1, N}); ++t) {

int tp = s;
int sp = t;
for (int k = 0; k < N; ++k) {

for (int l = max({k, 0}); l < min({(i) + 1, N}); ++l) {

int lp = k;
int ip = l;
E[i][j][k][l][s][t] += E[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

int ip = i;
for (int j = 0; j < N; ++j) {

for (int l = max({j, 0}); l < N; ++l) {

int kp = j;
for (int t = max({l, 0}); t < min({(i) + 1, N}); ++t) {

int jp = l;
int tp = t;
for (int k = 0; k < N; ++k) {

for (int s = max({k, 0}); s < min({(j) + 1, N}); ++s) {

int sp = k;
int lp = s;
E[i][j][k][l][s][t] += E[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int t = max({i, 0}); t < N; ++t) {

int tp = i;
int ip = t;
for (int j = 0; j < N; ++j) {

for (int l = max({j, 0}); l < min({(i) + 1, N}); ++l) {

int kp = j;
int jp = l;
for (int k = 0; k < N; ++k) {

for (int s = max({k, 0}); s < min({(j) + 1, N}); ++s) {

int sp = k;
int lp = s;
E[i][j][k][l][s][t] += E[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int l = 0; l < min({(i) + 1, N}); ++l) {

int ip = i;
int jp = l;
for (int j = 0; j < N; ++j) {

for (int t = max({j, 0}); t < min({(l) + 1, N}); ++t) {

int kp = j;
int lp = t;
for (int k = 0; k < N; ++k) {

for (int s = max({k, 0}); s < min({(j) + 1, N}); ++s) {

int sp = k;
int tp = s;
E[i][j][k][l][s][t] += E[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int l = max({i, 0}); l < N; ++l) {

int lp = i;
int jp = l;
for (int j = 0; j < N; ++j) {

for (int t = max({j, 0}); t < min({(i) + 1, N}); ++t) {

int kp = j;
int ip = t;
for (int k = 0; k < N; ++k) {

for (int s = max({k, 0}); s < min({(j) + 1, N}); ++s) {

int sp = k;
int tp = s;
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

int tp = i;
for (int t = max({l, 0}); t < N; ++t) {

int jp = l;
int kp = j;
int lp = t;
for (int k = 0; k < N; ++k) {

for (int s = max({k, 0}); s < min({(j) + 1, N}); ++s) {

int sp = k;
int ip = s;
E[i][j][k][l][s][t] += E[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

int lp = i;
for (int j = 0; j < min({(i) + 1, N}); ++j) {

int kp = j;
for (int k = 0; k < N; ++k) {

for (int s = max({k, 0}); s < min({(j) + 1, N}); ++s) {

int sp = k;
int ip = s;
for (int l = 0; l < N; ++l) {

for (int t = max({i, 0}); t < min({(l) + 1, N}); ++t) {

int jp = l;
int tp = t;
E[i][j][k][l][s][t] += E[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

int ip = i;
for (int j = 0; j < N; ++j) {

for (int t = max({j, 0}); t < min({(i) + 1, N}); ++t) {

for (int l = 0; l < min({(j) + 1, N}); ++l) {

int kp = j;
int tp = t;
int lp = l;
for (int k = 0; k < N; ++k) {

for (int s = max({k, 0}); s < min({(l) + 1, N}); ++s) {

int sp = k;
int jp = s;
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

int tp = i;
int ip = t;
for (int l = 0; l < min({(j) + 1, N}); ++l) {

int kp = j;
int lp = l;
for (int k = 0; k < N; ++k) {

for (int s = max({k, 0}); s < min({(l) + 1, N}); ++s) {

int sp = k;
int jp = s;
E[i][j][k][l][s][t] += E[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

int ip = i;
for (int j = 0; j < min({(i) + 1, N}); ++j) {

int kp = j;
for (int k = 0; k < N; ++k) {

for (int l = 0; l < N; ++l) {

int sp = k;
for (int s = max({k, 0}); s < min({(l) + 1, N}); ++s) {

for (int t = max({l, 0}); t < min({(j) + 1, N}); ++t) {

int lp = l;
int tp = s;
int jp = t;
E[i][j][k][l][s][t] += E[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

int jp = i;
for (int j = max({i, 0}); j < N; ++j) {

int kp = j;
for (int k = 0; k < N; ++k) {

for (int l = 0; l < N; ++l) {

int sp = k;
for (int s = max({k, 0}); s < min({(l) + 1, N}); ++s) {

for (int t = max({l, 0}); t < min({(i) + 1, N}); ++t) {

int lp = l;
int tp = s;
int ip = t;
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

int tp = i;
int lp = l;
for (int t = max({j, 0}); t < N; ++t) {

int kp = j;
int jp = t;
for (int k = 0; k < N; ++k) {

for (int s = max({k, 0}); s < min({(l) + 1, N}); ++s) {

int sp = k;
int ip = s;
E[i][j][k][l][s][t] += E[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int l = 0; l < min({(i) + 1, N}); ++l) {

int jp = i;
int lp = l;
for (int j = 0; j < N; ++j) {

for (int t = max({i, 0}); t < min({(j) + 1, N}); ++t) {

int kp = j;
int tp = t;
for (int k = 0; k < N; ++k) {

for (int s = max({k, 0}); s < min({(l) + 1, N}); ++s) {

int sp = k;
int ip = s;
E[i][j][k][l][s][t] += E[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

int ip = i;
for (int j = 0; j < N; ++j) {

for (int l = max({j, 0}); l < min({(i) + 1, N}); ++l) {

int kp = j;
int tp = l;
for (int k = 0; k < N; ++k) {

for (int s = max({k, 0}); s < N; ++s) {

int sp = k;
for (int t = max({s, 0}); t < min({(j) + 1, N}); ++t) {

int jp = s;
int lp = t;
E[i][j][k][l][s][t] += E[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int l = max({i, 0}); l < N; ++l) {

int lp = i;
for (int j = 0; j < min({(i) + 1, N}); ++j) {

int tp = l;
int kp = j;
for (int k = 0; k < N; ++k) {

for (int s = max({k, 0}); s < N; ++s) {

int sp = k;
for (int t = max({s, 0}); t < min({(j) + 1, N}); ++t) {

int jp = s;
int ip = t;
E[i][j][k][l][s][t] += E[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

int ip = i;
for (int j = 0; j < min({(i) + 1, N}); ++j) {

for (int l = 0; l < min({(j) + 1, N}); ++l) {

int kp = j;
int tp = l;
for (int k = 0; k < N; ++k) {

for (int s = max({k, 0}); s < N; ++s) {

int sp = k;
for (int t = max({s, 0}); t < min({(l) + 1, N}); ++t) {

int lp = s;
int jp = t;
E[i][j][k][l][s][t] += E[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int l = 0; l < min({(i) + 1, N}); ++l) {

int jp = i;
for (int j = max({i, 0}); j < N; ++j) {

int tp = l;
int kp = j;
for (int k = 0; k < N; ++k) {

for (int s = max({k, 0}); s < N; ++s) {

int sp = k;
for (int t = max({s, 0}); t < min({(l) + 1, N}); ++t) {

int lp = s;
int ip = t;
E[i][j][k][l][s][t] += E[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

int lp = i;
for (int j = max({i, 0}); j < N; ++j) {

for (int l = max({j, 0}); l < N; ++l) {

int kp = j;
int tp = l;
for (int k = 0; k < N; ++k) {

for (int s = max({k, 0}); s < N; ++s) {

int sp = k;
for (int t = max({s, 0}); t < min({(i) + 1, N}); ++t) {

int ip = s;
int jp = t;
E[i][j][k][l][s][t] += E[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

int jp = i;
for (int j = 0; j < N; ++j) {

for (int l = max({i, 0}); l < min({(j) + 1, N}); ++l) {

int kp = j;
int tp = l;
for (int k = 0; k < N; ++k) {

for (int s = max({k, 0}); s < N; ++s) {

int sp = k;
for (int t = max({s, 0}); t < min({(i) + 1, N}); ++t) {

int ip = s;
int lp = t;
E[i][j][k][l][s][t] += E[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int j = max({i, 0}); j < N; ++j) {

int tp = i;
for (int l = max({j, 0}); l < N; ++l) {

int kp = j;
for (int t = max({l, 0}); t < N; ++t) {

int ip = l;
int lp = t;
for (int k = 0; k < N; ++k) {

for (int s = max({k, 0}); s < min({(i) + 1, N}); ++s) {

int sp = k;
int jp = s;
E[i][j][k][l][s][t] += E[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

int lp = i;
for (int j = max({i, 0}); j < N; ++j) {

int kp = j;
for (int k = 0; k < N; ++k) {

for (int s = max({k, 0}); s < min({(i) + 1, N}); ++s) {

int sp = k;
int jp = s;
for (int l = 0; l < N; ++l) {

for (int t = max({j, 0}); t < min({(l) + 1, N}); ++t) {

int ip = l;
int tp = t;
E[i][j][k][l][s][t] += E[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int j = 0; j < N; ++j) {

int tp = i;
for (int t = max({j, 0}); t < N; ++t) {

for (int l = max({i, 0}); l < min({(j) + 1, N}); ++l) {

int kp = j;
int jp = t;
int ip = l;
for (int k = 0; k < N; ++k) {

for (int s = max({k, 0}); s < min({(i) + 1, N}); ++s) {

int sp = k;
int lp = s;
E[i][j][k][l][s][t] += E[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int l = max({i, 0}); l < N; ++l) {

int jp = i;
int ip = l;
for (int j = 0; j < N; ++j) {

for (int t = max({l, 0}); t < min({(j) + 1, N}); ++t) {

int kp = j;
int tp = t;
for (int k = 0; k < N; ++k) {

for (int s = max({k, 0}); s < min({(i) + 1, N}); ++s) {

int sp = k;
int lp = s;
E[i][j][k][l][s][t] += E[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

int lp = i;
for (int j = 0; j < N; ++j) {

for (int t = max({i, 0}); t < min({(j) + 1, N}); ++t) {

for (int l = max({j, 0}); l < N; ++l) {

int kp = j;
int jp = t;
int ip = l;
for (int k = 0; k < N; ++k) {

for (int s = max({k, 0}); s < min({(i) + 1, N}); ++s) {

int sp = k;
int tp = s;
E[i][j][k][l][s][t] += E[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

int jp = i;
for (int j = 0; j < N; ++j) {

for (int l = 0; l < min({(j) + 1, N}); ++l) {

int kp = j;
for (int t = max({i, 0}); t < min({(l) + 1, N}); ++t) {

int ip = l;
int lp = t;
for (int k = 0; k < N; ++k) {

for (int s = max({k, 0}); s < min({(i) + 1, N}); ++s) {

int sp = k;
int tp = s;
E[i][j][k][l][s][t] += E[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

int ip = i;
for (int j = 0; j < N; ++j) {

for (int l = max({j, 0}); l < N; ++l) {

int kp = j;
for (int s = max({l, 0}); s < min({(i) + 1, N}); ++s) {

int jp = l;
int lp = s;
for (int k = 0; k < N; ++k) {

for (int t = max({k, 0}); t < min({(j) + 1, N}); ++t) {

int tp = k;
int sp = t;
E[i][j][k][l][s][t] += E[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int s = max({i, 0}); s < N; ++s) {

int sp = i;
int lp = s;
for (int j = 0; j < N; ++j) {

for (int l = max({j, 0}); l < min({(i) + 1, N}); ++l) {

int kp = j;
int jp = l;
for (int k = 0; k < N; ++k) {

for (int t = max({k, 0}); t < min({(j) + 1, N}); ++t) {

int tp = k;
int ip = t;
E[i][j][k][l][s][t] += E[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int l = 0; l < min({(i) + 1, N}); ++l) {

int ip = i;
int jp = l;
for (int j = 0; j < N; ++j) {

for (int s = max({j, 0}); s < min({(l) + 1, N}); ++s) {

int kp = j;
int sp = s;
for (int k = 0; k < N; ++k) {

for (int t = max({k, 0}); t < min({(j) + 1, N}); ++t) {

int tp = k;
int lp = t;
E[i][j][k][l][s][t] += E[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int l = max({i, 0}); l < N; ++l) {

int lp = i;
int jp = l;
for (int j = 0; j < N; ++j) {

for (int s = max({j, 0}); s < min({(i) + 1, N}); ++s) {

int kp = j;
int sp = s;
for (int k = 0; k < N; ++k) {

for (int t = max({k, 0}); t < min({(j) + 1, N}); ++t) {

int tp = k;
int ip = t;
E[i][j][k][l][s][t] += E[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int l = max({i, 0}); l < N; ++l) {

int sp = i;
for (int j = 0; j < min({(i) + 1, N}); ++j) {

for (int s = max({l, 0}); s < N; ++s) {

int jp = l;
int kp = j;
int ip = s;
for (int k = 0; k < N; ++k) {

for (int t = max({k, 0}); t < min({(j) + 1, N}); ++t) {

int tp = k;
int lp = t;
E[i][j][k][l][s][t] += E[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

int lp = i;
for (int j = 0; j < min({(i) + 1, N}); ++j) {

int kp = j;
for (int k = 0; k < N; ++k) {

for (int t = max({k, 0}); t < min({(j) + 1, N}); ++t) {

int tp = k;
int sp = t;
for (int l = 0; l < N; ++l) {

for (int s = max({i, 0}); s < min({(l) + 1, N}); ++s) {

int jp = l;
int ip = s;
E[i][j][k][l][s][t] += E[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

int ip = i;
for (int j = 0; j < N; ++j) {

for (int s = max({j, 0}); s < min({(i) + 1, N}); ++s) {

for (int l = 0; l < min({(j) + 1, N}); ++l) {

int kp = j;
int jp = s;
int lp = l;
for (int k = 0; k < N; ++k) {

for (int t = max({k, 0}); t < min({(l) + 1, N}); ++t) {

int tp = k;
int sp = t;
E[i][j][k][l][s][t] += E[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int s = max({i, 0}); s < N; ++s) {

int sp = i;
for (int j = 0; j < min({(i) + 1, N}); ++j) {

int jp = s;
for (int l = 0; l < min({(j) + 1, N}); ++l) {

int kp = j;
int lp = l;
for (int k = 0; k < N; ++k) {

for (int t = max({k, 0}); t < min({(l) + 1, N}); ++t) {

int tp = k;
int ip = t;
E[i][j][k][l][s][t] += E[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

int ip = i;
for (int j = 0; j < min({(i) + 1, N}); ++j) {

int kp = j;
for (int k = 0; k < N; ++k) {

for (int l = 0; l < N; ++l) {

int tp = k;
for (int s = max({l, 0}); s < min({(j) + 1, N}); ++s) {

for (int t = max({k, 0}); t < min({(l) + 1, N}); ++t) {

int lp = l;
int sp = s;
int jp = t;
E[i][j][k][l][s][t] += E[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

int jp = i;
for (int j = max({i, 0}); j < N; ++j) {

int kp = j;
for (int k = 0; k < N; ++k) {

for (int l = 0; l < N; ++l) {

int tp = k;
for (int s = max({l, 0}); s < min({(i) + 1, N}); ++s) {

for (int t = max({k, 0}); t < min({(l) + 1, N}); ++t) {

int lp = l;
int sp = s;
int ip = t;
E[i][j][k][l][s][t] += E[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int l = 0; l < min({(i) + 1, N}); ++l) {

int sp = i;
for (int j = max({i, 0}); j < N; ++j) {

int lp = l;
for (int s = max({j, 0}); s < N; ++s) {

int kp = j;
int ip = s;
for (int k = 0; k < N; ++k) {

for (int t = max({k, 0}); t < min({(l) + 1, N}); ++t) {

int tp = k;
int jp = t;
E[i][j][k][l][s][t] += E[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int l = 0; l < min({(i) + 1, N}); ++l) {

int jp = i;
int lp = l;
for (int j = 0; j < N; ++j) {

for (int s = max({i, 0}); s < min({(j) + 1, N}); ++s) {

int kp = j;
int ip = s;
for (int k = 0; k < N; ++k) {

for (int t = max({k, 0}); t < min({(l) + 1, N}); ++t) {

int tp = k;
int sp = t;
E[i][j][k][l][s][t] += E[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

int ip = i;
for (int j = 0; j < N; ++j) {

for (int s = 0; s < min({(j) + 1, N}); ++s) {

for (int l = max({j, 0}); l < min({(i) + 1, N}); ++l) {

int kp = j;
int jp = s;
int sp = l;
for (int k = 0; k < N; ++k) {

for (int t = max({k, 0}); t < min({(s) + 1, N}); ++t) {

int tp = k;
int lp = t;
E[i][j][k][l][s][t] += E[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int l = max({i, 0}); l < N; ++l) {

int lp = i;
for (int j = 0; j < min({(i) + 1, N}); ++j) {

int sp = l;
for (int s = 0; s < min({(j) + 1, N}); ++s) {

int kp = j;
int jp = s;
for (int k = 0; k < N; ++k) {

for (int t = max({k, 0}); t < min({(s) + 1, N}); ++t) {

int tp = k;
int ip = t;
E[i][j][k][l][s][t] += E[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

int ip = i;
for (int j = 0; j < min({(i) + 1, N}); ++j) {

for (int l = 0; l < min({(j) + 1, N}); ++l) {

int kp = j;
for (int s = 0; s < min({(l) + 1, N}); ++s) {

int sp = l;
int lp = s;
for (int k = 0; k < N; ++k) {

for (int t = max({k, 0}); t < min({(s) + 1, N}); ++t) {

int tp = k;
int jp = t;
E[i][j][k][l][s][t] += E[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int l = 0; l < min({(i) + 1, N}); ++l) {

int jp = i;
for (int j = max({i, 0}); j < N; ++j) {

for (int s = 0; s < min({(l) + 1, N}); ++s) {

int sp = l;
int kp = j;
int lp = s;
for (int k = 0; k < N; ++k) {

for (int t = max({k, 0}); t < min({(s) + 1, N}); ++t) {

int tp = k;
int ip = t;
E[i][j][k][l][s][t] += E[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int s = 0; s < min({(i) + 1, N}); ++s) {

int lp = i;
for (int j = max({i, 0}); j < N; ++j) {

int ip = s;
for (int l = max({j, 0}); l < N; ++l) {

int kp = j;
int sp = l;
for (int k = 0; k < N; ++k) {

for (int t = max({k, 0}); t < min({(s) + 1, N}); ++t) {

int tp = k;
int jp = t;
E[i][j][k][l][s][t] += E[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int s = 0; s < min({(i) + 1, N}); ++s) {

int jp = i;
int ip = s;
for (int j = 0; j < N; ++j) {

for (int l = max({i, 0}); l < min({(j) + 1, N}); ++l) {

int kp = j;
int sp = l;
for (int k = 0; k < N; ++k) {

for (int t = max({k, 0}); t < min({(s) + 1, N}); ++t) {

int tp = k;
int lp = t;
E[i][j][k][l][s][t] += E[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

int sp = i;
for (int j = max({i, 0}); j < N; ++j) {

for (int l = max({j, 0}); l < N; ++l) {

int kp = j;
for (int s = max({l, 0}); s < N; ++s) {

int ip = l;
int jp = s;
for (int k = 0; k < N; ++k) {

for (int t = max({k, 0}); t < min({(i) + 1, N}); ++t) {

int tp = k;
int lp = t;
E[i][j][k][l][s][t] += E[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

int lp = i;
for (int j = max({i, 0}); j < N; ++j) {

int kp = j;
for (int k = 0; k < N; ++k) {

for (int t = max({k, 0}); t < min({(i) + 1, N}); ++t) {

int tp = k;
int sp = t;
for (int l = 0; l < N; ++l) {

for (int s = max({j, 0}); s < min({(l) + 1, N}); ++s) {

int ip = l;
int jp = s;
E[i][j][k][l][s][t] += E[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

int sp = i;
for (int j = 0; j < N; ++j) {

for (int s = max({j, 0}); s < N; ++s) {

for (int l = max({i, 0}); l < min({(j) + 1, N}); ++l) {

int kp = j;
int lp = s;
int ip = l;
for (int k = 0; k < N; ++k) {

for (int t = max({k, 0}); t < min({(i) + 1, N}); ++t) {

int tp = k;
int jp = t;
E[i][j][k][l][s][t] += E[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int l = max({i, 0}); l < N; ++l) {

int jp = i;
int ip = l;
for (int j = 0; j < N; ++j) {

for (int s = max({l, 0}); s < min({(j) + 1, N}); ++s) {

int kp = j;
int lp = s;
for (int k = 0; k < N; ++k) {

for (int t = max({k, 0}); t < min({(i) + 1, N}); ++t) {

int tp = k;
int sp = t;
E[i][j][k][l][s][t] += E[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

int lp = i;
for (int j = 0; j < N; ++j) {

for (int s = max({i, 0}); s < min({(j) + 1, N}); ++s) {

for (int l = max({j, 0}); l < N; ++l) {

int kp = j;
int sp = s;
int ip = l;
for (int k = 0; k < N; ++k) {

for (int t = max({k, 0}); t < min({(i) + 1, N}); ++t) {

int tp = k;
int jp = t;
E[i][j][k][l][s][t] += E[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

int jp = i;
for (int j = 0; j < N; ++j) {

for (int l = 0; l < min({(j) + 1, N}); ++l) {

int kp = j;
for (int s = max({i, 0}); s < min({(l) + 1, N}); ++s) {

int ip = l;
int sp = s;
for (int k = 0; k < N; ++k) {

for (int t = max({k, 0}); t < min({(i) + 1, N}); ++t) {

int tp = k;
int lp = t;
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

int tp = i;
for (int l = max({j, 0}); l < N; ++l) {

int kp = j;
int ip = k;
for (int s = max({l, 0}); s < N; ++s) {

int jp = l;
for (int t = max({s, 0}); t < N; ++t) {

int lp = s;
int sp = t;
E[i][j][k][l][s][t] += E[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

int sp = i;
for (int j = max({i, 0}); j < N; ++j) {

for (int k = 0; k < min({(i) + 1, N}); ++k) {

for (int l = max({j, 0}); l < N; ++l) {

int kp = j;
int ip = k;
int jp = l;
for (int s = 0; s < N; ++s) {

for (int t = max({l, 0}); t < min({(s) + 1, N}); ++t) {

int lp = s;
int tp = t;
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

int tp = i;
int kp = j;
int ip = k;
for (int l = 0; l < N; ++l) {

for (int s = max({j, 0}); s < min({(l) + 1, N}); ++s) {

for (int t = max({l, 0}); t < N; ++t) {

int jp = l;
int sp = s;
int lp = t;
E[i][j][k][l][s][t] += E[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

int lp = i;
for (int j = max({i, 0}); j < N; ++j) {

for (int k = 0; k < min({(i) + 1, N}); ++k) {

for (int s = max({j, 0}); s < N; ++s) {

int kp = j;
int ip = k;
int sp = s;
for (int l = 0; l < N; ++l) {

for (int t = max({s, 0}); t < min({(l) + 1, N}); ++t) {

int jp = l;
int tp = t;
E[i][j][k][l][s][t] += E[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

int sp = i;
for (int j = max({i, 0}); j < N; ++j) {

for (int k = 0; k < min({(i) + 1, N}); ++k) {

int kp = j;
int ip = k;
for (int l = 0; l < N; ++l) {

for (int s = max({l, 0}); s < N; ++s) {

for (int t = max({j, 0}); t < min({(l) + 1, N}); ++t) {

int jp = l;
int tp = s;
int lp = t;
E[i][j][k][l][s][t] += E[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

int lp = i;
for (int j = max({i, 0}); j < N; ++j) {

for (int k = 0; k < min({(i) + 1, N}); ++k) {

int kp = j;
int ip = k;
for (int l = 0; l < N; ++l) {

for (int s = 0; s < min({(l) + 1, N}); ++s) {

int jp = l;
for (int t = max({j, 0}); t < min({(s) + 1, N}); ++t) {

int tp = s;
int sp = t;
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

int tp = i;
for (int s = max({j, 0}); s < N; ++s) {

for (int l = max({i, 0}); l < min({(j) + 1, N}); ++l) {

int kp = j;
int ip = k;
for (int t = max({s, 0}); t < N; ++t) {

int jp = s;
int lp = l;
int sp = t;
E[i][j][k][l][s][t] += E[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

int sp = i;
for (int k = 0; k < min({(i) + 1, N}); ++k) {

int ip = k;
for (int j = 0; j < N; ++j) {

for (int l = max({i, 0}); l < min({(j) + 1, N}); ++l) {

int kp = j;
int lp = l;
for (int s = 0; s < N; ++s) {

for (int t = max({j, 0}); t < min({(s) + 1, N}); ++t) {

int jp = s;
int tp = t;
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

int tp = i;
int lp = l;
int ip = k;
for (int j = 0; j < N; ++j) {

for (int s = max({l, 0}); s < min({(j) + 1, N}); ++s) {

for (int t = max({j, 0}); t < N; ++t) {

int kp = j;
int sp = s;
int jp = t;
E[i][j][k][l][s][t] += E[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int l = max({i, 0}); l < N; ++l) {

int jp = i;
for (int k = 0; k < min({(i) + 1, N}); ++k) {

for (int s = max({l, 0}); s < N; ++s) {

int lp = l;
int ip = k;
int sp = s;
for (int j = 0; j < N; ++j) {

for (int t = max({s, 0}); t < min({(j) + 1, N}); ++t) {

int kp = j;
int tp = t;
E[i][j][k][l][s][t] += E[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int l = max({i, 0}); l < N; ++l) {

int sp = i;
for (int k = 0; k < min({(i) + 1, N}); ++k) {

int lp = l;
int ip = k;
for (int j = 0; j < N; ++j) {

for (int s = max({j, 0}); s < N; ++s) {

for (int t = max({l, 0}); t < min({(j) + 1, N}); ++t) {

int kp = j;
int tp = s;
int jp = t;
E[i][j][k][l][s][t] += E[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int l = max({i, 0}); l < N; ++l) {

int jp = i;
for (int k = 0; k < min({(i) + 1, N}); ++k) {

int lp = l;
int ip = k;
for (int j = 0; j < N; ++j) {

for (int s = 0; s < min({(j) + 1, N}); ++s) {

int kp = j;
for (int t = max({l, 0}); t < min({(s) + 1, N}); ++t) {

int tp = s;
int sp = t;
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

int tp = i;
for (int s = max({i, 0}); s < min({(j) + 1, N}); ++s) {

for (int l = max({j, 0}); l < N; ++l) {

int kp = j;
int ip = k;
int jp = s;
for (int t = max({l, 0}); t < N; ++t) {

int sp = l;
int lp = t;
E[i][j][k][l][s][t] += E[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

int lp = i;
for (int k = 0; k < min({(i) + 1, N}); ++k) {

int ip = k;
for (int j = 0; j < N; ++j) {

for (int s = max({i, 0}); s < min({(j) + 1, N}); ++s) {

int kp = j;
int jp = s;
for (int l = 0; l < N; ++l) {

for (int t = max({j, 0}); t < min({(l) + 1, N}); ++t) {

int sp = l;
int tp = t;
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

int tp = i;
for (int t = max({j, 0}); t < N; ++t) {

for (int l = 0; l < min({(j) + 1, N}); ++l) {

int kp = j;
int ip = k;
int jp = t;
for (int s = max({i, 0}); s < min({(l) + 1, N}); ++s) {

int sp = l;
int lp = s;
E[i][j][k][l][s][t] += E[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

int jp = i;
for (int k = 0; k < min({(i) + 1, N}); ++k) {

int ip = k;
for (int j = 0; j < N; ++j) {

int kp = j;
for (int l = 0; l < N; ++l) {

for (int s = max({i, 0}); s < min({(l) + 1, N}); ++s) {

for (int t = max({l, 0}); t < min({(j) + 1, N}); ++t) {

int sp = l;
int lp = s;
int tp = t;
E[i][j][k][l][s][t] += E[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int s = max({i, 0}); s < N; ++s) {

int lp = i;
for (int k = 0; k < min({(i) + 1, N}); ++k) {

int tp = s;
int ip = k;
for (int j = 0; j < N; ++j) {

for (int t = max({s, 0}); t < min({(j) + 1, N}); ++t) {

for (int l = max({j, 0}); l < N; ++l) {

int kp = j;
int jp = t;
int sp = l;
E[i][j][k][l][s][t] += E[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int s = max({i, 0}); s < N; ++s) {

int jp = i;
for (int k = 0; k < min({(i) + 1, N}); ++k) {

int tp = s;
int ip = k;
for (int j = 0; j < N; ++j) {

for (int l = 0; l < min({(j) + 1, N}); ++l) {

int kp = j;
for (int t = max({s, 0}); t < min({(l) + 1, N}); ++t) {

int sp = l;
int lp = t;
E[i][j][k][l][s][t] += E[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

int sp = i;
for (int k = 0; k < min({(i) + 1, N}); ++k) {

int ip = k;
for (int j = 0; j < N; ++j) {

for (int t = max({i, 0}); t < min({(j) + 1, N}); ++t) {

for (int l = max({j, 0}); l < N; ++l) {

int kp = j;
int lp = t;
for (int s = max({l, 0}); s < N; ++s) {

int tp = l;
int jp = s;
E[i][j][k][l][s][t] += E[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

int lp = i;
for (int k = 0; k < min({(i) + 1, N}); ++k) {

int ip = k;
for (int j = 0; j < N; ++j) {

for (int t = max({i, 0}); t < min({(j) + 1, N}); ++t) {

int kp = j;
int sp = t;
for (int l = 0; l < N; ++l) {

for (int s = max({j, 0}); s < min({(l) + 1, N}); ++s) {

int tp = l;
int jp = s;
E[i][j][k][l][s][t] += E[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

int sp = i;
for (int k = 0; k < min({(i) + 1, N}); ++k) {

int ip = k;
for (int j = 0; j < N; ++j) {

for (int s = max({j, 0}); s < N; ++s) {

for (int l = 0; l < min({(j) + 1, N}); ++l) {

int kp = j;
int lp = s;
for (int t = max({i, 0}); t < min({(l) + 1, N}); ++t) {

int tp = l;
int jp = t;
E[i][j][k][l][s][t] += E[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

int jp = i;
for (int k = 0; k < min({(i) + 1, N}); ++k) {

int ip = k;
for (int j = 0; j < N; ++j) {

int kp = j;
for (int l = 0; l < N; ++l) {

for (int s = max({l, 0}); s < min({(j) + 1, N}); ++s) {

for (int t = max({i, 0}); t < min({(l) + 1, N}); ++t) {

int tp = l;
int lp = s;
int sp = t;
E[i][j][k][l][s][t] += E[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

int lp = i;
for (int k = 0; k < min({(i) + 1, N}); ++k) {

int ip = k;
for (int j = 0; j < N; ++j) {

for (int s = 0; s < min({(j) + 1, N}); ++s) {

for (int l = max({j, 0}); l < N; ++l) {

int kp = j;
for (int t = max({i, 0}); t < min({(s) + 1, N}); ++t) {

int sp = s;
int tp = l;
int jp = t;
E[i][j][k][l][s][t] += E[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

int jp = i;
for (int k = 0; k < min({(i) + 1, N}); ++k) {

int ip = k;
for (int j = 0; j < N; ++j) {

for (int l = 0; l < min({(j) + 1, N}); ++l) {

int kp = j;
for (int s = 0; s < min({(l) + 1, N}); ++s) {

int tp = l;
for (int t = max({i, 0}); t < min({(s) + 1, N}); ++t) {

int sp = s;
int lp = t;
E[i][j][k][l][s][t] += E[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

int ip = i;
for (int j = 0; j < N; ++j) {

for (int l = 0; l < min({(j) + 1, N}); ++l) {

int lp = j;
for (int k = max({j, 0}); k < N; ++k) {

int kp = l;
for (int s = max({k, 0}); s < N; ++s) {

int jp = k;
for (int t = max({s, 0}); t < min({(i) + 1, N}); ++t) {

int sp = s;
int tp = t;
E[i][j][k][l][s][t] += E[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int t = max({i, 0}); t < N; ++t) {

int tp = i;
int ip = t;
for (int j = 0; j < N; ++j) {

for (int l = 0; l < min({(j) + 1, N}); ++l) {

int lp = j;
for (int k = max({j, 0}); k < N; ++k) {

int kp = l;
for (int s = max({k, 0}); s < min({(i) + 1, N}); ++s) {

int jp = k;
int sp = s;
E[i][j][k][l][s][t] += E[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int s = 0; s < min({(i) + 1, N}); ++s) {

int ip = i;
int tp = s;
for (int j = 0; j < N; ++j) {

for (int l = 0; l < min({(j) + 1, N}); ++l) {

int lp = j;
for (int k = max({j, 0}); k < N; ++k) {

int kp = l;
for (int t = max({k, 0}); t < min({(s) + 1, N}); ++t) {

int jp = k;
int sp = t;
E[i][j][k][l][s][t] += E[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int s = max({i, 0}); s < N; ++s) {

int sp = i;
int tp = s;
for (int j = 0; j < N; ++j) {

for (int l = 0; l < min({(j) + 1, N}); ++l) {

int lp = j;
for (int k = max({j, 0}); k < N; ++k) {

int kp = l;
for (int t = max({k, 0}); t < min({(i) + 1, N}); ++t) {

int jp = k;
int ip = t;
E[i][j][k][l][s][t] += E[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int s = max({i, 0}); s < N; ++s) {

int tp = i;
for (int t = max({s, 0}); t < N; ++t) {

int ip = s;
int sp = t;
for (int j = 0; j < N; ++j) {

for (int l = 0; l < min({(j) + 1, N}); ++l) {

int lp = j;
for (int k = max({j, 0}); k < min({(i) + 1, N}); ++k) {

int kp = l;
int jp = k;
E[i][j][k][l][s][t] += E[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

int sp = i;
for (int j = 0; j < N; ++j) {

for (int l = 0; l < min({(j) + 1, N}); ++l) {

int lp = j;
for (int k = max({j, 0}); k < min({(i) + 1, N}); ++k) {

int kp = l;
int jp = k;
for (int s = 0; s < N; ++s) {

for (int t = max({i, 0}); t < min({(s) + 1, N}); ++t) {

int ip = s;
int tp = t;
E[i][j][k][l][s][t] += E[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

int ip = i;
for (int j = 0; j < N; ++j) {

for (int l = 0; l < min({(j) + 1, N}); ++l) {

int lp = j;
int sp = l;
for (int k = 0; k < N; ++k) {

for (int s = max({j, 0}); s < min({(k) + 1, N}); ++s) {

for (int t = max({k, 0}); t < min({(i) + 1, N}); ++t) {

int jp = k;
int kp = s;
int tp = t;
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

int tp = i;
int ip = t;
int jp = k;
for (int j = 0; j < N; ++j) {

for (int s = max({j, 0}); s < min({(k) + 1, N}); ++s) {

for (int l = 0; l < min({(j) + 1, N}); ++l) {

int lp = j;
int kp = s;
int sp = l;
E[i][j][k][l][s][t] += E[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

int ip = i;
for (int k = 0; k < min({(i) + 1, N}); ++k) {

int jp = k;
for (int j = 0; j < N; ++j) {

for (int s = max({j, 0}); s < N; ++s) {

for (int l = 0; l < min({(j) + 1, N}); ++l) {

int lp = j;
for (int t = max({s, 0}); t < min({(k) + 1, N}); ++t) {

int tp = s;
int sp = l;
int kp = t;
E[i][j][k][l][s][t] += E[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

int kp = i;
for (int k = max({i, 0}); k < N; ++k) {

int jp = k;
for (int j = 0; j < N; ++j) {

for (int s = max({j, 0}); s < N; ++s) {

for (int l = 0; l < min({(j) + 1, N}); ++l) {

int lp = j;
for (int t = max({s, 0}); t < min({(i) + 1, N}); ++t) {

int tp = s;
int sp = l;
int ip = t;
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

int tp = i;
for (int s = max({j, 0}); s < min({(i) + 1, N}); ++s) {

for (int l = 0; l < min({(j) + 1, N}); ++l) {

int lp = j;
for (int t = max({k, 0}); t < N; ++t) {

int jp = k;
int ip = s;
int sp = l;
int kp = t;
E[i][j][k][l][s][t] += E[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

int kp = i;
for (int j = 0; j < N; ++j) {

for (int s = max({j, 0}); s < min({(i) + 1, N}); ++s) {

for (int l = 0; l < min({(j) + 1, N}); ++l) {

int lp = j;
int ip = s;
int sp = l;
for (int k = 0; k < N; ++k) {

for (int t = max({i, 0}); t < min({(k) + 1, N}); ++t) {

int jp = k;
int tp = t;
E[i][j][k][l][s][t] += E[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

int ip = i;
for (int j = 0; j < N; ++j) {

for (int l = 0; l < min({(j) + 1, N}); ++l) {

int lp = j;
int tp = l;
for (int k = 0; k < N; ++k) {

for (int s = max({k, 0}); s < min({(i) + 1, N}); ++s) {

for (int t = max({j, 0}); t < min({(k) + 1, N}); ++t) {

int jp = k;
int kp = s;
int sp = t;
E[i][j][k][l][s][t] += E[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int s = max({i, 0}); s < N; ++s) {

int sp = i;
for (int k = 0; k < min({(i) + 1, N}); ++k) {

int kp = s;
int jp = k;
for (int j = 0; j < N; ++j) {

for (int t = max({j, 0}); t < min({(k) + 1, N}); ++t) {

for (int l = 0; l < min({(j) + 1, N}); ++l) {

int lp = j;
int ip = t;
int tp = l;
E[i][j][k][l][s][t] += E[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

int ip = i;
for (int k = 0; k < min({(i) + 1, N}); ++k) {

for (int s = 0; s < min({(k) + 1, N}); ++s) {

int jp = k;
int sp = s;
for (int j = 0; j < N; ++j) {

for (int t = max({j, 0}); t < min({(s) + 1, N}); ++t) {

for (int l = 0; l < min({(j) + 1, N}); ++l) {

int lp = j;
int kp = t;
int tp = l;
E[i][j][k][l][s][t] += E[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int s = 0; s < min({(i) + 1, N}); ++s) {

int kp = i;
for (int k = max({i, 0}); k < N; ++k) {

int sp = s;
int jp = k;
for (int j = 0; j < N; ++j) {

for (int t = max({j, 0}); t < min({(s) + 1, N}); ++t) {

for (int l = 0; l < min({(j) + 1, N}); ++l) {

int lp = j;
int ip = t;
int tp = l;
E[i][j][k][l][s][t] += E[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

int sp = i;
for (int k = max({i, 0}); k < N; ++k) {

for (int s = max({k, 0}); s < N; ++s) {

int jp = k;
int ip = s;
for (int j = 0; j < N; ++j) {

for (int t = max({j, 0}); t < min({(i) + 1, N}); ++t) {

for (int l = 0; l < min({(j) + 1, N}); ++l) {

int lp = j;
int kp = t;
int tp = l;
E[i][j][k][l][s][t] += E[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

int kp = i;
for (int j = 0; j < N; ++j) {

for (int t = max({j, 0}); t < min({(i) + 1, N}); ++t) {

for (int l = 0; l < min({(j) + 1, N}); ++l) {

int lp = j;
int sp = t;
int tp = l;
for (int k = 0; k < N; ++k) {

for (int s = max({i, 0}); s < min({(k) + 1, N}); ++s) {

int jp = k;
int ip = s;
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

int tp = i;
for (int l = 0; l < min({(j) + 1, N}); ++l) {

int lp = j;
for (int s = max({k, 0}); s < N; ++s) {

int jp = k;
int ip = l;
for (int t = max({s, 0}); t < N; ++t) {

int kp = s;
int sp = t;
E[i][j][k][l][s][t] += E[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

int sp = i;
for (int j = 0; j < min({(i) + 1, N}); ++j) {

for (int k = max({i, 0}); k < N; ++k) {

for (int l = 0; l < min({(j) + 1, N}); ++l) {

int lp = j;
int jp = k;
int ip = l;
for (int s = 0; s < N; ++s) {

for (int t = max({k, 0}); t < min({(s) + 1, N}); ++t) {

int kp = s;
int tp = t;
E[i][j][k][l][s][t] += E[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int j = 0; j < min({(i) + 1, N}); ++j) {

int tp = i;
for (int l = 0; l < min({(j) + 1, N}); ++l) {

int lp = j;
int ip = l;
for (int k = 0; k < N; ++k) {

for (int s = max({i, 0}); s < min({(k) + 1, N}); ++s) {

for (int t = max({k, 0}); t < N; ++t) {

int jp = k;
int sp = s;
int kp = t;
E[i][j][k][l][s][t] += E[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int s = max({i, 0}); s < N; ++s) {

int kp = i;
for (int j = 0; j < min({(i) + 1, N}); ++j) {

int sp = s;
for (int l = 0; l < min({(j) + 1, N}); ++l) {

int lp = j;
int ip = l;
for (int k = 0; k < N; ++k) {

for (int t = max({s, 0}); t < min({(k) + 1, N}); ++t) {

int jp = k;
int tp = t;
E[i][j][k][l][s][t] += E[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

int sp = i;
for (int j = 0; j < min({(i) + 1, N}); ++j) {

for (int l = 0; l < min({(j) + 1, N}); ++l) {

int lp = j;
int ip = l;
for (int k = 0; k < N; ++k) {

for (int s = max({k, 0}); s < N; ++s) {

for (int t = max({i, 0}); t < min({(k) + 1, N}); ++t) {

int jp = k;
int tp = s;
int kp = t;
E[i][j][k][l][s][t] += E[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

int kp = i;
for (int j = 0; j < min({(i) + 1, N}); ++j) {

for (int l = 0; l < min({(j) + 1, N}); ++l) {

int lp = j;
int ip = l;
for (int k = 0; k < N; ++k) {

for (int s = 0; s < min({(k) + 1, N}); ++s) {

int jp = k;
for (int t = max({i, 0}); t < min({(s) + 1, N}); ++t) {

int tp = s;
int sp = t;
E[i][j][k][l][s][t] += E[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

int ip = i;
for (int j = 0; j < N; ++j) {

for (int s = max({j, 0}); s < N; ++s) {

int lp = j;
for (int k = 0; k < min({(j) + 1, N}); ++k) {

for (int t = max({s, 0}); t < min({(i) + 1, N}); ++t) {

int sp = s;
for (int l = 0; l < min({(k) + 1, N}); ++l) {

int kp = k;
int tp = t;
int jp = l;
E[i][j][k][l][s][t] += E[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int t = max({i, 0}); t < N; ++t) {

int tp = i;
int ip = t;
for (int j = 0; j < N; ++j) {

for (int s = max({j, 0}); s < min({(i) + 1, N}); ++s) {

int lp = j;
for (int k = 0; k < min({(j) + 1, N}); ++k) {

int sp = s;
for (int l = 0; l < min({(k) + 1, N}); ++l) {

int kp = k;
int jp = l;
E[i][j][k][l][s][t] += E[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int s = 0; s < min({(i) + 1, N}); ++s) {

int ip = i;
int tp = s;
for (int j = 0; j < N; ++j) {

for (int t = max({j, 0}); t < min({(s) + 1, N}); ++t) {

int lp = j;
for (int k = 0; k < min({(j) + 1, N}); ++k) {

int sp = t;
for (int l = 0; l < min({(k) + 1, N}); ++l) {

int kp = k;
int jp = l;
E[i][j][k][l][s][t] += E[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int s = max({i, 0}); s < N; ++s) {

int sp = i;
int tp = s;
for (int j = 0; j < N; ++j) {

for (int t = max({j, 0}); t < min({(i) + 1, N}); ++t) {

int lp = j;
for (int k = 0; k < min({(j) + 1, N}); ++k) {

int ip = t;
for (int l = 0; l < min({(k) + 1, N}); ++l) {

int kp = k;
int jp = l;
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

int tp = i;
for (int t = max({s, 0}); t < N; ++t) {

int ip = s;
int lp = j;
for (int k = 0; k < min({(j) + 1, N}); ++k) {

int sp = t;
for (int l = 0; l < min({(k) + 1, N}); ++l) {

int kp = k;
int jp = l;
E[i][j][k][l][s][t] += E[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

int sp = i;
for (int j = 0; j < min({(i) + 1, N}); ++j) {

int lp = j;
for (int k = 0; k < min({(j) + 1, N}); ++k) {

for (int l = 0; l < min({(k) + 1, N}); ++l) {

int kp = k;
int jp = l;
for (int s = 0; s < N; ++s) {

for (int t = max({i, 0}); t < min({(s) + 1, N}); ++t) {

int ip = s;
int tp = t;
E[i][j][k][l][s][t] += E[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

int ip = i;
for (int j = 0; j < N; ++j) {

for (int t = max({j, 0}); t < min({(i) + 1, N}); ++t) {

int lp = j;
int tp = t;
for (int k = 0; k < N; ++k) {

for (int s = max({k, 0}); s < min({(j) + 1, N}); ++s) {

for (int l = 0; l < min({(k) + 1, N}); ++l) {

int kp = k;
int jp = s;
int sp = l;
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

int tp = i;
int ip = t;
int lp = j;
for (int k = 0; k < N; ++k) {

for (int s = max({k, 0}); s < min({(j) + 1, N}); ++s) {

for (int l = 0; l < min({(k) + 1, N}); ++l) {

int kp = k;
int jp = s;
int sp = l;
E[i][j][k][l][s][t] += E[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

int ip = i;
for (int j = 0; j < min({(i) + 1, N}); ++j) {

int lp = j;
for (int k = 0; k < N; ++k) {

for (int s = max({k, 0}); s < N; ++s) {

for (int l = 0; l < min({(k) + 1, N}); ++l) {

int kp = k;
for (int t = max({s, 0}); t < min({(j) + 1, N}); ++t) {

int tp = s;
int sp = l;
int jp = t;
E[i][j][k][l][s][t] += E[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

int jp = i;
for (int j = max({i, 0}); j < N; ++j) {

int lp = j;
for (int k = 0; k < N; ++k) {

for (int s = max({k, 0}); s < N; ++s) {

for (int l = 0; l < min({(k) + 1, N}); ++l) {

int kp = k;
for (int t = max({s, 0}); t < min({(i) + 1, N}); ++t) {

int tp = s;
int sp = l;
int ip = t;
E[i][j][k][l][s][t] += E[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int j = max({i, 0}); j < N; ++j) {

int tp = i;
for (int t = max({j, 0}); t < N; ++t) {

int lp = j;
int jp = t;
for (int k = 0; k < N; ++k) {

for (int s = max({k, 0}); s < min({(i) + 1, N}); ++s) {

for (int l = 0; l < min({(k) + 1, N}); ++l) {

int kp = k;
int ip = s;
int sp = l;
E[i][j][k][l][s][t] += E[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

int jp = i;
for (int j = 0; j < N; ++j) {

for (int t = max({i, 0}); t < min({(j) + 1, N}); ++t) {

int lp = j;
int tp = t;
for (int k = 0; k < N; ++k) {

for (int s = max({k, 0}); s < min({(i) + 1, N}); ++s) {

for (int l = 0; l < min({(k) + 1, N}); ++l) {

int kp = k;
int ip = s;
int sp = l;
E[i][j][k][l][s][t] += E[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

int ip = i;
for (int j = 0; j < N; ++j) {

for (int s = max({j, 0}); s < min({(i) + 1, N}); ++s) {

int lp = j;
int jp = s;
for (int k = 0; k < N; ++k) {

for (int t = max({k, 0}); t < min({(j) + 1, N}); ++t) {

for (int l = 0; l < min({(k) + 1, N}); ++l) {

int kp = k;
int sp = t;
int tp = l;
E[i][j][k][l][s][t] += E[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int s = max({i, 0}); s < N; ++s) {

int sp = i;
for (int j = 0; j < min({(i) + 1, N}); ++j) {

int jp = s;
int lp = j;
for (int k = 0; k < N; ++k) {

for (int t = max({k, 0}); t < min({(j) + 1, N}); ++t) {

for (int l = 0; l < min({(k) + 1, N}); ++l) {

int kp = k;
int ip = t;
int tp = l;
E[i][j][k][l][s][t] += E[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

int ip = i;
for (int j = 0; j < min({(i) + 1, N}); ++j) {

for (int s = 0; s < min({(j) + 1, N}); ++s) {

int lp = j;
int sp = s;
for (int k = 0; k < N; ++k) {

for (int t = max({k, 0}); t < min({(s) + 1, N}); ++t) {

for (int l = 0; l < min({(k) + 1, N}); ++l) {

int kp = k;
int jp = t;
int tp = l;
E[i][j][k][l][s][t] += E[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int s = 0; s < min({(i) + 1, N}); ++s) {

int jp = i;
for (int j = max({i, 0}); j < N; ++j) {

int sp = s;
int lp = j;
for (int k = 0; k < N; ++k) {

for (int t = max({k, 0}); t < min({(s) + 1, N}); ++t) {

for (int l = 0; l < min({(k) + 1, N}); ++l) {

int kp = k;
int ip = t;
int tp = l;
E[i][j][k][l][s][t] += E[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

int sp = i;
for (int j = max({i, 0}); j < N; ++j) {

for (int s = max({j, 0}); s < N; ++s) {

int lp = j;
int ip = s;
for (int k = 0; k < N; ++k) {

for (int t = max({k, 0}); t < min({(i) + 1, N}); ++t) {

for (int l = 0; l < min({(k) + 1, N}); ++l) {

int kp = k;
int jp = t;
int tp = l;
E[i][j][k][l][s][t] += E[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

int jp = i;
for (int j = 0; j < N; ++j) {

for (int s = max({i, 0}); s < min({(j) + 1, N}); ++s) {

int lp = j;
int ip = s;
for (int k = 0; k < N; ++k) {

for (int t = max({k, 0}); t < min({(i) + 1, N}); ++t) {

for (int l = 0; l < min({(k) + 1, N}); ++l) {

int kp = k;
int sp = t;
int tp = l;
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

int tp = i;
for (int s = max({j, 0}); s < N; ++s) {

int lp = j;
for (int l = 0; l < min({(k) + 1, N}); ++l) {

int kp = k;
for (int t = max({s, 0}); t < N; ++t) {

int jp = s;
int ip = l;
int sp = t;
E[i][j][k][l][s][t] += E[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

int sp = i;
for (int j = max({i, 0}); j < N; ++j) {

for (int k = 0; k < min({(i) + 1, N}); ++k) {

int lp = j;
for (int l = 0; l < min({(k) + 1, N}); ++l) {

int kp = k;
int ip = l;
for (int s = 0; s < N; ++s) {

for (int t = max({j, 0}); t < min({(s) + 1, N}); ++t) {

int jp = s;
int tp = t;
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

int tp = i;
for (int s = max({i, 0}); s < min({(j) + 1, N}); ++s) {

for (int t = max({j, 0}); t < N; ++t) {

int lp = j;
for (int l = 0; l < min({(k) + 1, N}); ++l) {

int kp = k;
int sp = s;
int jp = t;
int ip = l;
E[i][j][k][l][s][t] += E[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int s = max({i, 0}); s < N; ++s) {

int jp = i;
for (int k = 0; k < min({(i) + 1, N}); ++k) {

int sp = s;
for (int l = 0; l < min({(k) + 1, N}); ++l) {

int kp = k;
int ip = l;
for (int j = 0; j < N; ++j) {

for (int t = max({s, 0}); t < min({(j) + 1, N}); ++t) {

int lp = j;
int tp = t;
E[i][j][k][l][s][t] += E[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

int sp = i;
for (int k = 0; k < min({(i) + 1, N}); ++k) {

for (int l = 0; l < min({(k) + 1, N}); ++l) {

int kp = k;
int ip = l;
for (int j = 0; j < N; ++j) {

for (int s = max({j, 0}); s < N; ++s) {

for (int t = max({i, 0}); t < min({(j) + 1, N}); ++t) {

int lp = j;
int tp = s;
int jp = t;
E[i][j][k][l][s][t] += E[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

int jp = i;
for (int k = 0; k < min({(i) + 1, N}); ++k) {

for (int l = 0; l < min({(k) + 1, N}); ++l) {

int kp = k;
int ip = l;
for (int j = 0; j < N; ++j) {

for (int s = 0; s < min({(j) + 1, N}); ++s) {

int lp = j;
for (int t = max({i, 0}); t < min({(s) + 1, N}); ++t) {

int tp = s;
int sp = t;
E[i][j][k][l][s][t] += E[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

int ip = i;
for (int j = 0; j < N; ++j) {

int lp = j;
for (int k = max({j, 0}); k < N; ++k) {

for (int t = max({k, 0}); t < min({(i) + 1, N}); ++t) {

int sp = k;
int tp = t;
for (int l = 0; l < N; ++l) {

for (int s = max({l, 0}); s < min({(j) + 1, N}); ++s) {

int jp = l;
int kp = s;
E[i][j][k][l][s][t] += E[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int t = max({i, 0}); t < N; ++t) {

int tp = i;
int ip = t;
for (int j = 0; j < N; ++j) {

int lp = j;
for (int k = max({j, 0}); k < min({(i) + 1, N}); ++k) {

for (int l = 0; l < N; ++l) {

int sp = k;
for (int s = max({l, 0}); s < min({(j) + 1, N}); ++s) {

int jp = l;
int kp = s;
E[i][j][k][l][s][t] += E[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

int ip = i;
for (int k = 0; k < min({(i) + 1, N}); ++k) {

int sp = k;
for (int j = 0; j < N; ++j) {

for (int t = max({j, 0}); t < min({(k) + 1, N}); ++t) {

int lp = j;
int kp = t;
for (int l = 0; l < N; ++l) {

for (int s = max({l, 0}); s < min({(j) + 1, N}); ++s) {

int jp = l;
int tp = s;
E[i][j][k][l][s][t] += E[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

int kp = i;
for (int k = max({i, 0}); k < N; ++k) {

int sp = k;
for (int j = 0; j < N; ++j) {

for (int t = max({j, 0}); t < min({(i) + 1, N}); ++t) {

int lp = j;
int ip = t;
for (int l = 0; l < N; ++l) {

for (int s = max({l, 0}); s < min({(j) + 1, N}); ++s) {

int jp = l;
int tp = s;
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

int tp = i;
int lp = j;
for (int t = max({k, 0}); t < N; ++t) {

int sp = k;
int kp = t;
for (int l = 0; l < N; ++l) {

for (int s = max({l, 0}); s < min({(j) + 1, N}); ++s) {

int jp = l;
int ip = s;
E[i][j][k][l][s][t] += E[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

int kp = i;
for (int j = 0; j < min({(i) + 1, N}); ++j) {

int lp = j;
for (int k = 0; k < N; ++k) {

for (int t = max({i, 0}); t < min({(k) + 1, N}); ++t) {

int sp = k;
int tp = t;
for (int l = 0; l < N; ++l) {

for (int s = max({l, 0}); s < min({(j) + 1, N}); ++s) {

int jp = l;
int ip = s;
E[i][j][k][l][s][t] += E[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

int ip = i;
for (int j = 0; j < N; ++j) {

for (int t = max({j, 0}); t < min({(i) + 1, N}); ++t) {

int lp = j;
for (int k = 0; k < min({(j) + 1, N}); ++k) {

int tp = t;
int sp = k;
for (int l = 0; l < N; ++l) {

for (int s = max({l, 0}); s < min({(k) + 1, N}); ++s) {

int kp = l;
int jp = s;
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

int tp = i;
int ip = t;
int lp = j;
for (int k = 0; k < min({(j) + 1, N}); ++k) {

for (int l = 0; l < N; ++l) {

int sp = k;
for (int s = max({l, 0}); s < min({(k) + 1, N}); ++s) {

int kp = l;
int jp = s;
E[i][j][k][l][s][t] += E[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

int ip = i;
for (int j = 0; j < min({(i) + 1, N}); ++j) {

int lp = j;
for (int k = 0; k < N; ++k) {

for (int t = max({k, 0}); t < min({(j) + 1, N}); ++t) {

int sp = k;
int jp = t;
for (int l = 0; l < N; ++l) {

for (int s = max({l, 0}); s < min({(k) + 1, N}); ++s) {

int kp = l;
int tp = s;
E[i][j][k][l][s][t] += E[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

int jp = i;
for (int j = max({i, 0}); j < N; ++j) {

int lp = j;
for (int k = 0; k < N; ++k) {

for (int t = max({k, 0}); t < min({(i) + 1, N}); ++t) {

int sp = k;
int ip = t;
for (int l = 0; l < N; ++l) {

for (int s = max({l, 0}); s < min({(k) + 1, N}); ++s) {

int kp = l;
int tp = s;
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

int tp = i;
for (int t = max({j, 0}); t < N; ++t) {

int lp = j;
int sp = k;
int jp = t;
for (int l = 0; l < N; ++l) {

for (int s = max({l, 0}); s < min({(k) + 1, N}); ++s) {

int kp = l;
int ip = s;
E[i][j][k][l][s][t] += E[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

int jp = i;
for (int k = 0; k < min({(i) + 1, N}); ++k) {

int sp = k;
for (int j = 0; j < N; ++j) {

for (int t = max({i, 0}); t < min({(j) + 1, N}); ++t) {

int lp = j;
int tp = t;
for (int l = 0; l < N; ++l) {

for (int s = max({l, 0}); s < min({(k) + 1, N}); ++s) {

int kp = l;
int ip = s;
E[i][j][k][l][s][t] += E[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

int ip = i;
for (int j = 0; j < N; ++j) {

int lp = j;
for (int k = max({j, 0}); k < min({(i) + 1, N}); ++k) {

for (int l = 0; l < N; ++l) {

int sp = k;
for (int s = max({l, 0}); s < N; ++s) {

int tp = l;
for (int t = max({s, 0}); t < min({(j) + 1, N}); ++t) {

int jp = s;
int kp = t;
E[i][j][k][l][s][t] += E[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

int kp = i;
for (int j = 0; j < min({(i) + 1, N}); ++j) {

for (int k = max({i, 0}); k < N; ++k) {

int lp = j;
int sp = k;
for (int l = 0; l < N; ++l) {

for (int s = max({l, 0}); s < N; ++s) {

int tp = l;
for (int t = max({s, 0}); t < min({(j) + 1, N}); ++t) {

int jp = s;
int ip = t;
E[i][j][k][l][s][t] += E[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

int ip = i;
for (int j = 0; j < min({(i) + 1, N}); ++j) {

int lp = j;
for (int k = 0; k < min({(j) + 1, N}); ++k) {

for (int l = 0; l < N; ++l) {

int sp = k;
for (int s = max({l, 0}); s < N; ++s) {

int tp = l;
for (int t = max({s, 0}); t < min({(k) + 1, N}); ++t) {

int kp = s;
int jp = t;
E[i][j][k][l][s][t] += E[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

int jp = i;
for (int j = max({i, 0}); j < N; ++j) {

for (int k = 0; k < min({(i) + 1, N}); ++k) {

int lp = j;
int sp = k;
for (int l = 0; l < N; ++l) {

for (int s = max({l, 0}); s < N; ++s) {

int tp = l;
for (int t = max({s, 0}); t < min({(k) + 1, N}); ++t) {

int kp = s;
int ip = t;
E[i][j][k][l][s][t] += E[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

int kp = i;
for (int j = max({i, 0}); j < N; ++j) {

int lp = j;
for (int k = max({j, 0}); k < N; ++k) {

for (int l = 0; l < N; ++l) {

int sp = k;
for (int s = max({l, 0}); s < N; ++s) {

int tp = l;
for (int t = max({s, 0}); t < min({(i) + 1, N}); ++t) {

int ip = s;
int jp = t;
E[i][j][k][l][s][t] += E[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

int jp = i;
for (int j = 0; j < N; ++j) {

int lp = j;
for (int k = max({i, 0}); k < min({(j) + 1, N}); ++k) {

for (int l = 0; l < N; ++l) {

int sp = k;
for (int s = max({l, 0}); s < N; ++s) {

int tp = l;
for (int t = max({s, 0}); t < min({(i) + 1, N}); ++t) {

int ip = s;
int kp = t;
E[i][j][k][l][s][t] += E[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int j = max({i, 0}); j < N; ++j) {

int tp = i;
int lp = j;
for (int k = max({j, 0}); k < N; ++k) {

for (int t = max({k, 0}); t < N; ++t) {

int sp = k;
int kp = t;
for (int l = 0; l < N; ++l) {

for (int s = max({l, 0}); s < min({(i) + 1, N}); ++s) {

int ip = l;
int jp = s;
E[i][j][k][l][s][t] += E[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

int kp = i;
for (int j = max({i, 0}); j < N; ++j) {

int lp = j;
for (int k = 0; k < N; ++k) {

for (int t = max({j, 0}); t < min({(k) + 1, N}); ++t) {

int sp = k;
int tp = t;
for (int l = 0; l < N; ++l) {

for (int s = max({l, 0}); s < min({(i) + 1, N}); ++s) {

int ip = l;
int jp = s;
E[i][j][k][l][s][t] += E[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int j = 0; j < N; ++j) {

int tp = i;
for (int t = max({j, 0}); t < N; ++t) {

int lp = j;
for (int k = max({i, 0}); k < min({(j) + 1, N}); ++k) {

int jp = t;
int sp = k;
for (int l = 0; l < N; ++l) {

for (int s = max({l, 0}); s < min({(i) + 1, N}); ++s) {

int ip = l;
int kp = s;
E[i][j][k][l][s][t] += E[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

int jp = i;
for (int k = max({i, 0}); k < N; ++k) {

int sp = k;
for (int j = 0; j < N; ++j) {

for (int t = max({k, 0}); t < min({(j) + 1, N}); ++t) {

int lp = j;
int tp = t;
for (int l = 0; l < N; ++l) {

for (int s = max({l, 0}); s < min({(i) + 1, N}); ++s) {

int ip = l;
int kp = s;
E[i][j][k][l][s][t] += E[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

int kp = i;
for (int j = 0; j < N; ++j) {

for (int t = max({i, 0}); t < min({(j) + 1, N}); ++t) {

int lp = j;
for (int k = max({j, 0}); k < N; ++k) {

int jp = t;
int sp = k;
for (int l = 0; l < N; ++l) {

for (int s = max({l, 0}); s < min({(i) + 1, N}); ++s) {

int ip = l;
int tp = s;
E[i][j][k][l][s][t] += E[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

int jp = i;
for (int j = 0; j < N; ++j) {

int lp = j;
for (int k = 0; k < min({(j) + 1, N}); ++k) {

for (int t = max({i, 0}); t < min({(k) + 1, N}); ++t) {

int sp = k;
int kp = t;
for (int l = 0; l < N; ++l) {

for (int s = max({l, 0}); s < min({(i) + 1, N}); ++s) {

int ip = l;
int tp = s;
E[i][j][k][l][s][t] += E[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

int ip = i;
for (int j = 0; j < N; ++j) {

int lp = j;
for (int k = max({j, 0}); k < N; ++k) {

for (int s = max({k, 0}); s < min({(i) + 1, N}); ++s) {

int tp = k;
int kp = s;
for (int l = 0; l < N; ++l) {

for (int t = max({l, 0}); t < min({(j) + 1, N}); ++t) {

int jp = l;
int sp = t;
E[i][j][k][l][s][t] += E[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int s = max({i, 0}); s < N; ++s) {

int sp = i;
int kp = s;
for (int j = 0; j < N; ++j) {

int lp = j;
for (int k = max({j, 0}); k < min({(i) + 1, N}); ++k) {

for (int l = 0; l < N; ++l) {

int tp = k;
for (int t = max({l, 0}); t < min({(j) + 1, N}); ++t) {

int jp = l;
int ip = t;
E[i][j][k][l][s][t] += E[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

int ip = i;
for (int k = 0; k < min({(i) + 1, N}); ++k) {

for (int j = 0; j < N; ++j) {

int tp = k;
for (int s = max({j, 0}); s < min({(k) + 1, N}); ++s) {

int lp = j;
int sp = s;
for (int l = 0; l < N; ++l) {

for (int t = max({l, 0}); t < min({(j) + 1, N}); ++t) {

int jp = l;
int kp = t;
E[i][j][k][l][s][t] += E[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

int kp = i;
for (int k = max({i, 0}); k < N; ++k) {

for (int j = 0; j < N; ++j) {

int tp = k;
for (int s = max({j, 0}); s < min({(i) + 1, N}); ++s) {

int lp = j;
int sp = s;
for (int l = 0; l < N; ++l) {

for (int t = max({l, 0}); t < min({(j) + 1, N}); ++t) {

int jp = l;
int ip = t;
E[i][j][k][l][s][t] += E[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

int sp = i;
for (int j = 0; j < min({(i) + 1, N}); ++j) {

for (int k = max({i, 0}); k < N; ++k) {

int lp = j;
for (int s = max({k, 0}); s < N; ++s) {

int tp = k;
int ip = s;
for (int l = 0; l < N; ++l) {

for (int t = max({l, 0}); t < min({(j) + 1, N}); ++t) {

int jp = l;
int kp = t;
E[i][j][k][l][s][t] += E[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

int kp = i;
for (int j = 0; j < min({(i) + 1, N}); ++j) {

int lp = j;
for (int k = 0; k < N; ++k) {

for (int s = max({i, 0}); s < min({(k) + 1, N}); ++s) {

int tp = k;
int ip = s;
for (int l = 0; l < N; ++l) {

for (int t = max({l, 0}); t < min({(j) + 1, N}); ++t) {

int jp = l;
int sp = t;
E[i][j][k][l][s][t] += E[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

int ip = i;
for (int j = 0; j < N; ++j) {

for (int s = max({j, 0}); s < min({(i) + 1, N}); ++s) {

int lp = j;
for (int k = 0; k < min({(j) + 1, N}); ++k) {

int jp = s;
int tp = k;
for (int l = 0; l < N; ++l) {

for (int t = max({l, 0}); t < min({(k) + 1, N}); ++t) {

int kp = l;
int sp = t;
E[i][j][k][l][s][t] += E[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int s = max({i, 0}); s < N; ++s) {

int sp = i;
for (int j = 0; j < min({(i) + 1, N}); ++j) {

int jp = s;
int lp = j;
for (int k = 0; k < min({(j) + 1, N}); ++k) {

for (int l = 0; l < N; ++l) {

int tp = k;
for (int t = max({l, 0}); t < min({(k) + 1, N}); ++t) {

int kp = l;
int ip = t;
E[i][j][k][l][s][t] += E[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

int ip = i;
for (int j = 0; j < min({(i) + 1, N}); ++j) {

int lp = j;
for (int k = 0; k < N; ++k) {

for (int s = max({k, 0}); s < min({(j) + 1, N}); ++s) {

int tp = k;
int sp = s;
for (int l = 0; l < N; ++l) {

for (int t = max({l, 0}); t < min({(k) + 1, N}); ++t) {

int kp = l;
int jp = t;
E[i][j][k][l][s][t] += E[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

int jp = i;
for (int j = max({i, 0}); j < N; ++j) {

int lp = j;
for (int k = 0; k < N; ++k) {

for (int s = max({k, 0}); s < min({(i) + 1, N}); ++s) {

int tp = k;
int sp = s;
for (int l = 0; l < N; ++l) {

for (int t = max({l, 0}); t < min({(k) + 1, N}); ++t) {

int kp = l;
int ip = t;
E[i][j][k][l][s][t] += E[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

int sp = i;
for (int j = max({i, 0}); j < N; ++j) {

for (int k = 0; k < min({(i) + 1, N}); ++k) {

for (int s = max({j, 0}); s < N; ++s) {

int lp = j;
int tp = k;
int ip = s;
for (int l = 0; l < N; ++l) {

for (int t = max({l, 0}); t < min({(k) + 1, N}); ++t) {

int kp = l;
int jp = t;
E[i][j][k][l][s][t] += E[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

int jp = i;
for (int k = 0; k < min({(i) + 1, N}); ++k) {

for (int j = 0; j < N; ++j) {

int tp = k;
for (int s = max({i, 0}); s < min({(j) + 1, N}); ++s) {

int lp = j;
int ip = s;
for (int l = 0; l < N; ++l) {

for (int t = max({l, 0}); t < min({(k) + 1, N}); ++t) {

int kp = l;
int sp = t;
E[i][j][k][l][s][t] += E[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

int ip = i;
for (int j = 0; j < N; ++j) {

for (int s = 0; s < min({(j) + 1, N}); ++s) {

int lp = j;
for (int k = max({j, 0}); k < min({(i) + 1, N}); ++k) {

int jp = s;
int tp = k;
for (int l = 0; l < N; ++l) {

for (int t = max({l, 0}); t < min({(s) + 1, N}); ++t) {

int sp = l;
int kp = t;
E[i][j][k][l][s][t] += E[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

int kp = i;
for (int j = 0; j < min({(i) + 1, N}); ++j) {

for (int k = max({i, 0}); k < N; ++k) {

for (int s = 0; s < min({(j) + 1, N}); ++s) {

int lp = j;
int tp = k;
int jp = s;
for (int l = 0; l < N; ++l) {

for (int t = max({l, 0}); t < min({(s) + 1, N}); ++t) {

int sp = l;
int ip = t;
E[i][j][k][l][s][t] += E[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

int ip = i;
for (int j = 0; j < min({(i) + 1, N}); ++j) {

int lp = j;
for (int k = 0; k < min({(j) + 1, N}); ++k) {

for (int s = 0; s < min({(k) + 1, N}); ++s) {

int tp = k;
int kp = s;
for (int l = 0; l < N; ++l) {

for (int t = max({l, 0}); t < min({(s) + 1, N}); ++t) {

int sp = l;
int jp = t;
E[i][j][k][l][s][t] += E[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

int jp = i;
for (int j = max({i, 0}); j < N; ++j) {

for (int k = 0; k < min({(i) + 1, N}); ++k) {

int lp = j;
for (int s = 0; s < min({(k) + 1, N}); ++s) {

int tp = k;
int kp = s;
for (int l = 0; l < N; ++l) {

for (int t = max({l, 0}); t < min({(s) + 1, N}); ++t) {

int sp = l;
int ip = t;
E[i][j][k][l][s][t] += E[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int s = 0; s < min({(i) + 1, N}); ++s) {

int kp = i;
for (int j = max({i, 0}); j < N; ++j) {

int ip = s;
int lp = j;
for (int k = max({j, 0}); k < N; ++k) {

for (int l = 0; l < N; ++l) {

int tp = k;
for (int t = max({l, 0}); t < min({(s) + 1, N}); ++t) {

int sp = l;
int jp = t;
E[i][j][k][l][s][t] += E[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int s = 0; s < min({(i) + 1, N}); ++s) {

int jp = i;
int ip = s;
for (int j = 0; j < N; ++j) {

int lp = j;
for (int k = max({i, 0}); k < min({(j) + 1, N}); ++k) {

for (int l = 0; l < N; ++l) {

int tp = k;
for (int t = max({l, 0}); t < min({(s) + 1, N}); ++t) {

int sp = l;
int kp = t;
E[i][j][k][l][s][t] += E[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

int sp = i;
for (int j = max({i, 0}); j < N; ++j) {

int lp = j;
for (int k = max({j, 0}); k < N; ++k) {

for (int s = max({k, 0}); s < N; ++s) {

int tp = k;
int jp = s;
for (int l = 0; l < N; ++l) {

for (int t = max({l, 0}); t < min({(i) + 1, N}); ++t) {

int ip = l;
int kp = t;
E[i][j][k][l][s][t] += E[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

int kp = i;
for (int j = max({i, 0}); j < N; ++j) {

int lp = j;
for (int k = 0; k < N; ++k) {

for (int s = max({j, 0}); s < min({(k) + 1, N}); ++s) {

int tp = k;
int jp = s;
for (int l = 0; l < N; ++l) {

for (int t = max({l, 0}); t < min({(i) + 1, N}); ++t) {

int ip = l;
int sp = t;
E[i][j][k][l][s][t] += E[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

int sp = i;
for (int j = 0; j < N; ++j) {

for (int s = max({j, 0}); s < N; ++s) {

int lp = j;
for (int k = max({i, 0}); k < min({(j) + 1, N}); ++k) {

int kp = s;
int tp = k;
for (int l = 0; l < N; ++l) {

for (int t = max({l, 0}); t < min({(i) + 1, N}); ++t) {

int ip = l;
int jp = t;
E[i][j][k][l][s][t] += E[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

int jp = i;
for (int k = max({i, 0}); k < N; ++k) {

for (int j = 0; j < N; ++j) {

int tp = k;
for (int s = max({k, 0}); s < min({(j) + 1, N}); ++s) {

int lp = j;
int kp = s;
for (int l = 0; l < N; ++l) {

for (int t = max({l, 0}); t < min({(i) + 1, N}); ++t) {

int ip = l;
int sp = t;
E[i][j][k][l][s][t] += E[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

int kp = i;
for (int j = 0; j < N; ++j) {

for (int s = max({i, 0}); s < min({(j) + 1, N}); ++s) {

int lp = j;
for (int k = max({j, 0}); k < N; ++k) {

int sp = s;
int tp = k;
for (int l = 0; l < N; ++l) {

for (int t = max({l, 0}); t < min({(i) + 1, N}); ++t) {

int ip = l;
int jp = t;
E[i][j][k][l][s][t] += E[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

int jp = i;
for (int j = 0; j < N; ++j) {

int lp = j;
for (int k = 0; k < min({(j) + 1, N}); ++k) {

for (int s = max({i, 0}); s < min({(k) + 1, N}); ++s) {

int tp = k;
int sp = s;
for (int l = 0; l < N; ++l) {

for (int t = max({l, 0}); t < min({(i) + 1, N}); ++t) {

int ip = l;
int kp = t;
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

int tp = i;
int jp = l;
int lp = j;
for (int k = max({j, 0}); k < N; ++k) {

for (int s = max({k, 0}); s < N; ++s) {

int ip = k;
for (int t = max({s, 0}); t < N; ++t) {

int kp = s;
int sp = t;
E[i][j][k][l][s][t] += E[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int l = 0; l < min({(i) + 1, N}); ++l) {

int sp = i;
for (int j = max({i, 0}); j < N; ++j) {

int jp = l;
int lp = j;
for (int k = max({j, 0}); k < N; ++k) {

int ip = k;
for (int s = 0; s < N; ++s) {

for (int t = max({k, 0}); t < min({(s) + 1, N}); ++t) {

int kp = s;
int tp = t;
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

int tp = i;
int jp = l;
int lp = j;
for (int k = 0; k < N; ++k) {

for (int s = max({j, 0}); s < min({(k) + 1, N}); ++s) {

for (int t = max({k, 0}); t < N; ++t) {

int ip = k;
int sp = s;
int kp = t;
E[i][j][k][l][s][t] += E[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int l = 0; l < min({(i) + 1, N}); ++l) {

int kp = i;
for (int j = max({i, 0}); j < N; ++j) {

int jp = l;
for (int s = max({j, 0}); s < N; ++s) {

int lp = j;
int sp = s;
for (int k = 0; k < N; ++k) {

for (int t = max({s, 0}); t < min({(k) + 1, N}); ++t) {

int ip = k;
int tp = t;
E[i][j][k][l][s][t] += E[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int l = 0; l < min({(i) + 1, N}); ++l) {

int sp = i;
for (int j = max({i, 0}); j < N; ++j) {

int jp = l;
int lp = j;
for (int k = 0; k < N; ++k) {

for (int s = max({k, 0}); s < N; ++s) {

for (int t = max({j, 0}); t < min({(k) + 1, N}); ++t) {

int ip = k;
int tp = s;
int kp = t;
E[i][j][k][l][s][t] += E[ip][jp][kp][lp][sp][tp];
}
}
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
for (int k = 0; k < N; ++k) {

for (int s = 0; s < min({(k) + 1, N}); ++s) {

int ip = k;
for (int t = max({j, 0}); t < min({(s) + 1, N}); ++t) {

int tp = s;
int sp = t;
E[i][j][k][l][s][t] += E[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int l = 0; l < min({(i) + 1, N}); ++l) {

int tp = i;
int kp = l;
for (int j = 0; j < N; ++j) {

for (int s = max({j, 0}); s < N; ++s) {

int lp = j;
for (int k = max({i, 0}); k < min({(j) + 1, N}); ++k) {

for (int t = max({s, 0}); t < N; ++t) {

int jp = s;
int ip = k;
int sp = t;
E[i][j][k][l][s][t] += E[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int l = 0; l < min({(i) + 1, N}); ++l) {

int sp = i;
int kp = l;
for (int j = 0; j < N; ++j) {

int lp = j;
for (int k = max({i, 0}); k < min({(j) + 1, N}); ++k) {

int ip = k;
for (int s = 0; s < N; ++s) {

for (int t = max({j, 0}); t < min({(s) + 1, N}); ++t) {

int jp = s;
int tp = t;
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

int tp = i;
int kp = l;
int ip = k;
for (int j = 0; j < N; ++j) {

for (int s = max({k, 0}); s < min({(j) + 1, N}); ++s) {

for (int t = max({j, 0}); t < N; ++t) {

int lp = j;
int sp = s;
int jp = t;
E[i][j][k][l][s][t] += E[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int l = 0; l < min({(i) + 1, N}); ++l) {

int jp = i;
for (int k = max({i, 0}); k < N; ++k) {

int kp = l;
for (int s = max({k, 0}); s < N; ++s) {

int ip = k;
int sp = s;
for (int j = 0; j < N; ++j) {

for (int t = max({s, 0}); t < min({(j) + 1, N}); ++t) {

int lp = j;
int tp = t;
E[i][j][k][l][s][t] += E[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int l = 0; l < min({(i) + 1, N}); ++l) {

int sp = i;
for (int k = max({i, 0}); k < N; ++k) {

int kp = l;
int ip = k;
for (int j = 0; j < N; ++j) {

for (int s = max({j, 0}); s < N; ++s) {

for (int t = max({k, 0}); t < min({(j) + 1, N}); ++t) {

int lp = j;
int tp = s;
int jp = t;
E[i][j][k][l][s][t] += E[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int l = 0; l < min({(i) + 1, N}); ++l) {

int jp = i;
for (int k = max({i, 0}); k < N; ++k) {

int kp = l;
int ip = k;
for (int j = 0; j < N; ++j) {

for (int s = 0; s < min({(j) + 1, N}); ++s) {

int lp = j;
for (int t = max({k, 0}); t < min({(s) + 1, N}); ++t) {

int tp = s;
int sp = t;
E[i][j][k][l][s][t] += E[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int l = 0; l < min({(i) + 1, N}); ++l) {

int tp = i;
int sp = l;
for (int j = 0; j < N; ++j) {

for (int s = max({i, 0}); s < min({(j) + 1, N}); ++s) {

int lp = j;
for (int k = max({j, 0}); k < N; ++k) {

int jp = s;
for (int t = max({k, 0}); t < N; ++t) {

int ip = k;
int kp = t;
E[i][j][k][l][s][t] += E[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int l = 0; l < min({(i) + 1, N}); ++l) {

int kp = i;
int sp = l;
for (int j = 0; j < N; ++j) {

for (int s = max({i, 0}); s < min({(j) + 1, N}); ++s) {

int lp = j;
int jp = s;
for (int k = 0; k < N; ++k) {

for (int t = max({j, 0}); t < min({(k) + 1, N}); ++t) {

int ip = k;
int tp = t;
E[i][j][k][l][s][t] += E[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int l = 0; l < min({(i) + 1, N}); ++l) {

int tp = i;
int sp = l;
for (int j = 0; j < N; ++j) {

for (int t = max({j, 0}); t < N; ++t) {

int lp = j;
for (int k = 0; k < min({(j) + 1, N}); ++k) {

int jp = t;
for (int s = max({i, 0}); s < min({(k) + 1, N}); ++s) {

int ip = k;
int kp = s;
E[i][j][k][l][s][t] += E[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int l = 0; l < min({(i) + 1, N}); ++l) {

int jp = i;
int sp = l;
for (int j = 0; j < N; ++j) {

int lp = j;
for (int k = 0; k < N; ++k) {

for (int s = max({i, 0}); s < min({(k) + 1, N}); ++s) {

for (int t = max({k, 0}); t < min({(j) + 1, N}); ++t) {

int ip = k;
int kp = s;
int tp = t;
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

int kp = i;
int tp = s;
int sp = l;
for (int j = 0; j < N; ++j) {

for (int t = max({s, 0}); t < min({(j) + 1, N}); ++t) {

int lp = j;
for (int k = max({j, 0}); k < N; ++k) {

int jp = t;
int ip = k;
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

int jp = i;
int tp = s;
int sp = l;
for (int j = 0; j < N; ++j) {

int lp = j;
for (int k = 0; k < min({(j) + 1, N}); ++k) {

for (int t = max({s, 0}); t < min({(k) + 1, N}); ++t) {

int ip = k;
int kp = t;
E[i][j][k][l][s][t] += E[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int l = 0; l < min({(i) + 1, N}); ++l) {

int sp = i;
int tp = l;
for (int j = 0; j < N; ++j) {

for (int t = max({i, 0}); t < min({(j) + 1, N}); ++t) {

int lp = j;
for (int k = max({j, 0}); k < N; ++k) {

int kp = t;
for (int s = max({k, 0}); s < N; ++s) {

int ip = k;
int jp = s;
E[i][j][k][l][s][t] += E[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int l = 0; l < min({(i) + 1, N}); ++l) {

int kp = i;
int tp = l;
for (int j = 0; j < N; ++j) {

for (int t = max({i, 0}); t < min({(j) + 1, N}); ++t) {

int lp = j;
int sp = t;
for (int k = 0; k < N; ++k) {

for (int s = max({j, 0}); s < min({(k) + 1, N}); ++s) {

int ip = k;
int jp = s;
E[i][j][k][l][s][t] += E[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int l = 0; l < min({(i) + 1, N}); ++l) {

int sp = i;
int tp = l;
for (int j = 0; j < N; ++j) {

for (int s = max({j, 0}); s < N; ++s) {

int lp = j;
for (int k = 0; k < min({(j) + 1, N}); ++k) {

int kp = s;
for (int t = max({i, 0}); t < min({(k) + 1, N}); ++t) {

int ip = k;
int jp = t;
E[i][j][k][l][s][t] += E[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int l = 0; l < min({(i) + 1, N}); ++l) {

int jp = i;
int tp = l;
for (int j = 0; j < N; ++j) {

int lp = j;
for (int k = 0; k < N; ++k) {

for (int s = max({k, 0}); s < min({(j) + 1, N}); ++s) {

for (int t = max({i, 0}); t < min({(k) + 1, N}); ++t) {

int ip = k;
int kp = s;
int sp = t;
E[i][j][k][l][s][t] += E[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int l = 0; l < min({(i) + 1, N}); ++l) {

int kp = i;
int tp = l;
for (int j = 0; j < N; ++j) {

for (int s = 0; s < min({(j) + 1, N}); ++s) {

int lp = j;
for (int k = max({j, 0}); k < N; ++k) {

for (int t = max({i, 0}); t < min({(s) + 1, N}); ++t) {

int sp = s;
int ip = k;
int jp = t;
E[i][j][k][l][s][t] += E[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int l = 0; l < min({(i) + 1, N}); ++l) {

int jp = i;
int tp = l;
for (int j = 0; j < N; ++j) {

int lp = j;
for (int k = 0; k < min({(j) + 1, N}); ++k) {

for (int s = 0; s < min({(k) + 1, N}); ++s) {

int ip = k;
for (int t = max({i, 0}); t < min({(s) + 1, N}); ++t) {

int sp = s;
int kp = t;
E[i][j][k][l][s][t] += E[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

int ip = i;
for (int j = 0; j < N; ++j) {

for (int s = 0; s < min({(j) + 1, N}); ++s) {

int sp = j;
for (int k = max({j, 0}); k < N; ++k) {

int lp = s;
for (int l = max({k, 0}); l < N; ++l) {

int jp = k;
for (int t = max({l, 0}); t < min({(i) + 1, N}); ++t) {

int kp = l;
int tp = t;
E[i][j][k][l][s][t] += E[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int t = max({i, 0}); t < N; ++t) {

int tp = i;
int ip = t;
for (int j = 0; j < N; ++j) {

for (int s = 0; s < min({(j) + 1, N}); ++s) {

int sp = j;
for (int k = max({j, 0}); k < N; ++k) {

int lp = s;
for (int l = max({k, 0}); l < min({(i) + 1, N}); ++l) {

int jp = k;
int kp = l;
E[i][j][k][l][s][t] += E[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int l = 0; l < min({(i) + 1, N}); ++l) {

int ip = i;
int kp = l;
for (int j = 0; j < N; ++j) {

for (int s = 0; s < min({(j) + 1, N}); ++s) {

int sp = j;
for (int k = max({j, 0}); k < N; ++k) {

int tp = s;
for (int t = max({k, 0}); t < min({(l) + 1, N}); ++t) {

int jp = k;
int lp = t;
E[i][j][k][l][s][t] += E[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int l = max({i, 0}); l < N; ++l) {

int lp = i;
int kp = l;
for (int j = 0; j < N; ++j) {

for (int s = 0; s < min({(j) + 1, N}); ++s) {

int sp = j;
for (int k = max({j, 0}); k < N; ++k) {

int tp = s;
for (int t = max({k, 0}); t < min({(i) + 1, N}); ++t) {

int jp = k;
int ip = t;
E[i][j][k][l][s][t] += E[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int l = max({i, 0}); l < N; ++l) {

int tp = i;
for (int t = max({l, 0}); t < N; ++t) {

int kp = l;
int lp = t;
for (int j = 0; j < N; ++j) {

for (int s = 0; s < min({(j) + 1, N}); ++s) {

int sp = j;
for (int k = max({j, 0}); k < min({(i) + 1, N}); ++k) {

int ip = s;
int jp = k;
E[i][j][k][l][s][t] += E[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

int lp = i;
for (int j = 0; j < N; ++j) {

for (int s = 0; s < min({(j) + 1, N}); ++s) {

int sp = j;
for (int k = max({j, 0}); k < min({(i) + 1, N}); ++k) {

int ip = s;
int jp = k;
for (int l = 0; l < N; ++l) {

for (int t = max({i, 0}); t < min({(l) + 1, N}); ++t) {

int kp = l;
int tp = t;
E[i][j][k][l][s][t] += E[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

int ip = i;
for (int j = 0; j < N; ++j) {

for (int s = 0; s < min({(j) + 1, N}); ++s) {

int sp = j;
int kp = s;
for (int k = 0; k < N; ++k) {

for (int t = max({k, 0}); t < min({(i) + 1, N}); ++t) {

for (int l = max({j, 0}); l < min({(k) + 1, N}); ++l) {

int jp = k;
int tp = t;
int lp = l;
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

int tp = i;
int ip = t;
int jp = k;
for (int j = 0; j < N; ++j) {

for (int s = 0; s < min({(j) + 1, N}); ++s) {

for (int l = max({j, 0}); l < min({(k) + 1, N}); ++l) {

int sp = j;
int kp = s;
int lp = l;
E[i][j][k][l][s][t] += E[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

int ip = i;
for (int k = 0; k < min({(i) + 1, N}); ++k) {

int jp = k;
for (int j = 0; j < N; ++j) {

for (int s = 0; s < min({(j) + 1, N}); ++s) {

for (int l = max({j, 0}); l < N; ++l) {

int sp = j;
int tp = s;
for (int t = max({l, 0}); t < min({(k) + 1, N}); ++t) {

int lp = l;
int kp = t;
E[i][j][k][l][s][t] += E[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

int kp = i;
for (int k = max({i, 0}); k < N; ++k) {

int jp = k;
for (int j = 0; j < N; ++j) {

for (int s = 0; s < min({(j) + 1, N}); ++s) {

for (int l = max({j, 0}); l < N; ++l) {

int sp = j;
int tp = s;
for (int t = max({l, 0}); t < min({(i) + 1, N}); ++t) {

int lp = l;
int ip = t;
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

int tp = i;
for (int s = 0; s < min({(j) + 1, N}); ++s) {

for (int l = max({j, 0}); l < min({(i) + 1, N}); ++l) {

int sp = j;
for (int t = max({k, 0}); t < N; ++t) {

int jp = k;
int ip = s;
int lp = l;
int kp = t;
E[i][j][k][l][s][t] += E[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

int kp = i;
for (int j = 0; j < N; ++j) {

for (int s = 0; s < min({(j) + 1, N}); ++s) {

for (int l = max({j, 0}); l < min({(i) + 1, N}); ++l) {

int sp = j;
int ip = s;
int lp = l;
for (int k = 0; k < N; ++k) {

for (int t = max({i, 0}); t < min({(k) + 1, N}); ++t) {

int jp = k;
int tp = t;
E[i][j][k][l][s][t] += E[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

int ip = i;
for (int j = 0; j < N; ++j) {

for (int s = 0; s < min({(j) + 1, N}); ++s) {

int sp = j;
int kp = s;
for (int k = 0; k < N; ++k) {

for (int t = max({j, 0}); t < min({(k) + 1, N}); ++t) {

for (int l = max({k, 0}); l < min({(i) + 1, N}); ++l) {

int jp = k;
int lp = t;
int tp = l;
E[i][j][k][l][s][t] += E[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int l = max({i, 0}); l < N; ++l) {

int lp = i;
for (int k = 0; k < min({(i) + 1, N}); ++k) {

int tp = l;
int jp = k;
for (int j = 0; j < N; ++j) {

for (int s = 0; s < min({(j) + 1, N}); ++s) {

for (int t = max({j, 0}); t < min({(k) + 1, N}); ++t) {

int sp = j;
int kp = s;
int ip = t;
E[i][j][k][l][s][t] += E[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

int ip = i;
for (int k = 0; k < min({(i) + 1, N}); ++k) {

for (int l = 0; l < min({(k) + 1, N}); ++l) {

int jp = k;
int tp = l;
for (int j = 0; j < N; ++j) {

for (int s = 0; s < min({(j) + 1, N}); ++s) {

for (int t = max({j, 0}); t < min({(l) + 1, N}); ++t) {

int sp = j;
int lp = s;
int kp = t;
E[i][j][k][l][s][t] += E[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int l = 0; l < min({(i) + 1, N}); ++l) {

int kp = i;
for (int k = max({i, 0}); k < N; ++k) {

int tp = l;
int jp = k;
for (int j = 0; j < N; ++j) {

for (int s = 0; s < min({(j) + 1, N}); ++s) {

for (int t = max({j, 0}); t < min({(l) + 1, N}); ++t) {

int sp = j;
int lp = s;
int ip = t;
E[i][j][k][l][s][t] += E[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

int lp = i;
for (int k = max({i, 0}); k < N; ++k) {

for (int l = max({k, 0}); l < N; ++l) {

int jp = k;
int tp = l;
for (int j = 0; j < N; ++j) {

for (int s = 0; s < min({(j) + 1, N}); ++s) {

for (int t = max({j, 0}); t < min({(i) + 1, N}); ++t) {

int sp = j;
int ip = s;
int kp = t;
E[i][j][k][l][s][t] += E[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

int kp = i;
for (int j = 0; j < N; ++j) {

for (int s = 0; s < min({(j) + 1, N}); ++s) {

for (int t = max({j, 0}); t < min({(i) + 1, N}); ++t) {

int sp = j;
int ip = s;
int lp = t;
for (int k = 0; k < N; ++k) {

for (int l = max({i, 0}); l < min({(k) + 1, N}); ++l) {

int jp = k;
int tp = l;
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

int tp = i;
for (int s = 0; s < min({(j) + 1, N}); ++s) {

int sp = j;
for (int l = max({k, 0}); l < N; ++l) {

int jp = k;
int kp = s;
for (int t = max({l, 0}); t < N; ++t) {

int ip = l;
int lp = t;
E[i][j][k][l][s][t] += E[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

int lp = i;
for (int j = 0; j < min({(i) + 1, N}); ++j) {

for (int k = max({i, 0}); k < N; ++k) {

for (int s = 0; s < min({(j) + 1, N}); ++s) {

int sp = j;
int jp = k;
int kp = s;
for (int l = 0; l < N; ++l) {

for (int t = max({k, 0}); t < min({(l) + 1, N}); ++t) {

int ip = l;
int tp = t;
E[i][j][k][l][s][t] += E[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int j = 0; j < min({(i) + 1, N}); ++j) {

int tp = i;
for (int s = 0; s < min({(j) + 1, N}); ++s) {

int sp = j;
int lp = s;
for (int k = 0; k < N; ++k) {

for (int t = max({k, 0}); t < N; ++t) {

for (int l = max({i, 0}); l < min({(k) + 1, N}); ++l) {

int jp = k;
int kp = t;
int ip = l;
E[i][j][k][l][s][t] += E[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int l = max({i, 0}); l < N; ++l) {

int kp = i;
for (int j = 0; j < min({(i) + 1, N}); ++j) {

int ip = l;
for (int s = 0; s < min({(j) + 1, N}); ++s) {

int sp = j;
int lp = s;
for (int k = 0; k < N; ++k) {

for (int t = max({l, 0}); t < min({(k) + 1, N}); ++t) {

int jp = k;
int tp = t;
E[i][j][k][l][s][t] += E[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

int lp = i;
for (int j = 0; j < min({(i) + 1, N}); ++j) {

for (int s = 0; s < min({(j) + 1, N}); ++s) {

int sp = j;
int tp = s;
for (int k = 0; k < N; ++k) {

for (int t = max({i, 0}); t < min({(k) + 1, N}); ++t) {

for (int l = max({k, 0}); l < N; ++l) {

int jp = k;
int kp = t;
int ip = l;
E[i][j][k][l][s][t] += E[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

int kp = i;
for (int j = 0; j < min({(i) + 1, N}); ++j) {

for (int s = 0; s < min({(j) + 1, N}); ++s) {

int sp = j;
int tp = s;
for (int k = 0; k < N; ++k) {

for (int l = 0; l < min({(k) + 1, N}); ++l) {

int jp = k;
for (int t = max({i, 0}); t < min({(l) + 1, N}); ++t) {

int ip = l;
int lp = t;
E[i][j][k][l][s][t] += E[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

int ip = i;
for (int j = 0; j < N; ++j) {

for (int l = max({j, 0}); l < N; ++l) {

int sp = j;
for (int k = 0; k < min({(j) + 1, N}); ++k) {

for (int t = max({l, 0}); t < min({(i) + 1, N}); ++t) {

int jp = l;
for (int s = 0; s < min({(k) + 1, N}); ++s) {

int kp = k;
int tp = t;
int lp = s;
E[i][j][k][l][s][t] += E[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int t = max({i, 0}); t < N; ++t) {

int tp = i;
int ip = t;
for (int j = 0; j < N; ++j) {

for (int l = max({j, 0}); l < min({(i) + 1, N}); ++l) {

int sp = j;
for (int k = 0; k < min({(j) + 1, N}); ++k) {

int jp = l;
for (int s = 0; s < min({(k) + 1, N}); ++s) {

int kp = k;
int lp = s;
E[i][j][k][l][s][t] += E[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int l = 0; l < min({(i) + 1, N}); ++l) {

int ip = i;
int jp = l;
for (int j = 0; j < N; ++j) {

for (int t = max({j, 0}); t < min({(l) + 1, N}); ++t) {

int sp = j;
for (int k = 0; k < min({(j) + 1, N}); ++k) {

int lp = t;
for (int s = 0; s < min({(k) + 1, N}); ++s) {

int kp = k;
int tp = s;
E[i][j][k][l][s][t] += E[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int l = max({i, 0}); l < N; ++l) {

int lp = i;
int jp = l;
for (int j = 0; j < N; ++j) {

for (int t = max({j, 0}); t < min({(i) + 1, N}); ++t) {

int sp = j;
for (int k = 0; k < min({(j) + 1, N}); ++k) {

int ip = t;
for (int s = 0; s < min({(k) + 1, N}); ++s) {

int kp = k;
int tp = s;
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

int tp = i;
for (int t = max({l, 0}); t < N; ++t) {

int jp = l;
int sp = j;
for (int k = 0; k < min({(j) + 1, N}); ++k) {

int lp = t;
for (int s = 0; s < min({(k) + 1, N}); ++s) {

int kp = k;
int ip = s;
E[i][j][k][l][s][t] += E[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

int lp = i;
for (int j = 0; j < min({(i) + 1, N}); ++j) {

int sp = j;
for (int k = 0; k < min({(j) + 1, N}); ++k) {

for (int s = 0; s < min({(k) + 1, N}); ++s) {

int kp = k;
int ip = s;
for (int l = 0; l < N; ++l) {

for (int t = max({i, 0}); t < min({(l) + 1, N}); ++t) {

int jp = l;
int tp = t;
E[i][j][k][l][s][t] += E[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

int ip = i;
for (int j = 0; j < N; ++j) {

for (int t = max({j, 0}); t < min({(i) + 1, N}); ++t) {

int sp = j;
int tp = t;
for (int k = 0; k < N; ++k) {

for (int s = 0; s < min({(k) + 1, N}); ++s) {

for (int l = max({k, 0}); l < min({(j) + 1, N}); ++l) {

int kp = k;
int jp = s;
int lp = l;
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

int tp = i;
int ip = t;
int sp = j;
for (int k = 0; k < N; ++k) {

for (int s = 0; s < min({(k) + 1, N}); ++s) {

for (int l = max({k, 0}); l < min({(j) + 1, N}); ++l) {

int kp = k;
int jp = s;
int lp = l;
E[i][j][k][l][s][t] += E[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

int ip = i;
for (int j = 0; j < min({(i) + 1, N}); ++j) {

int sp = j;
for (int k = 0; k < N; ++k) {

for (int s = 0; s < min({(k) + 1, N}); ++s) {

for (int l = max({k, 0}); l < N; ++l) {

int kp = k;
int tp = s;
for (int t = max({l, 0}); t < min({(j) + 1, N}); ++t) {

int lp = l;
int jp = t;
E[i][j][k][l][s][t] += E[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

int jp = i;
for (int j = max({i, 0}); j < N; ++j) {

int sp = j;
for (int k = 0; k < N; ++k) {

for (int s = 0; s < min({(k) + 1, N}); ++s) {

for (int l = max({k, 0}); l < N; ++l) {

int kp = k;
int tp = s;
for (int t = max({l, 0}); t < min({(i) + 1, N}); ++t) {

int lp = l;
int ip = t;
E[i][j][k][l][s][t] += E[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int j = max({i, 0}); j < N; ++j) {

int tp = i;
for (int t = max({j, 0}); t < N; ++t) {

int sp = j;
int jp = t;
for (int k = 0; k < N; ++k) {

for (int s = 0; s < min({(k) + 1, N}); ++s) {

for (int l = max({k, 0}); l < min({(i) + 1, N}); ++l) {

int kp = k;
int ip = s;
int lp = l;
E[i][j][k][l][s][t] += E[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

int jp = i;
for (int j = 0; j < N; ++j) {

for (int t = max({i, 0}); t < min({(j) + 1, N}); ++t) {

int sp = j;
int tp = t;
for (int k = 0; k < N; ++k) {

for (int s = 0; s < min({(k) + 1, N}); ++s) {

for (int l = max({k, 0}); l < min({(i) + 1, N}); ++l) {

int kp = k;
int ip = s;
int lp = l;
E[i][j][k][l][s][t] += E[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

int ip = i;
for (int j = 0; j < N; ++j) {

for (int l = max({j, 0}); l < min({(i) + 1, N}); ++l) {

int sp = j;
int tp = l;
for (int k = 0; k < N; ++k) {

for (int s = 0; s < min({(k) + 1, N}); ++s) {

for (int t = max({k, 0}); t < min({(j) + 1, N}); ++t) {

int kp = k;
int jp = s;
int lp = t;
E[i][j][k][l][s][t] += E[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int l = max({i, 0}); l < N; ++l) {

int lp = i;
for (int j = 0; j < min({(i) + 1, N}); ++j) {

int tp = l;
int sp = j;
for (int k = 0; k < N; ++k) {

for (int s = 0; s < min({(k) + 1, N}); ++s) {

for (int t = max({k, 0}); t < min({(j) + 1, N}); ++t) {

int kp = k;
int jp = s;
int ip = t;
E[i][j][k][l][s][t] += E[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

int ip = i;
for (int j = 0; j < min({(i) + 1, N}); ++j) {

for (int l = 0; l < min({(j) + 1, N}); ++l) {

int sp = j;
int tp = l;
for (int k = 0; k < N; ++k) {

for (int s = 0; s < min({(k) + 1, N}); ++s) {

for (int t = max({k, 0}); t < min({(l) + 1, N}); ++t) {

int kp = k;
int lp = s;
int jp = t;
E[i][j][k][l][s][t] += E[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int l = 0; l < min({(i) + 1, N}); ++l) {

int jp = i;
for (int j = max({i, 0}); j < N; ++j) {

int tp = l;
int sp = j;
for (int k = 0; k < N; ++k) {

for (int s = 0; s < min({(k) + 1, N}); ++s) {

for (int t = max({k, 0}); t < min({(l) + 1, N}); ++t) {

int kp = k;
int lp = s;
int ip = t;
E[i][j][k][l][s][t] += E[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

int lp = i;
for (int j = max({i, 0}); j < N; ++j) {

for (int l = max({j, 0}); l < N; ++l) {

int sp = j;
int tp = l;
for (int k = 0; k < N; ++k) {

for (int s = 0; s < min({(k) + 1, N}); ++s) {

for (int t = max({k, 0}); t < min({(i) + 1, N}); ++t) {

int kp = k;
int ip = s;
int jp = t;
E[i][j][k][l][s][t] += E[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

int jp = i;
for (int j = 0; j < N; ++j) {

for (int l = max({i, 0}); l < min({(j) + 1, N}); ++l) {

int sp = j;
int tp = l;
for (int k = 0; k < N; ++k) {

for (int s = 0; s < min({(k) + 1, N}); ++s) {

for (int t = max({k, 0}); t < min({(i) + 1, N}); ++t) {

int kp = k;
int ip = s;
int lp = t;
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

int tp = i;
for (int l = max({j, 0}); l < N; ++l) {

int sp = j;
for (int s = 0; s < min({(k) + 1, N}); ++s) {

int kp = k;
for (int t = max({l, 0}); t < N; ++t) {

int ip = l;
int jp = s;
int lp = t;
E[i][j][k][l][s][t] += E[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

int lp = i;
for (int j = max({i, 0}); j < N; ++j) {

for (int k = 0; k < min({(i) + 1, N}); ++k) {

int sp = j;
for (int s = 0; s < min({(k) + 1, N}); ++s) {

int kp = k;
int jp = s;
for (int l = 0; l < N; ++l) {

for (int t = max({j, 0}); t < min({(l) + 1, N}); ++t) {

int ip = l;
int tp = t;
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

int tp = i;
for (int t = max({j, 0}); t < N; ++t) {

for (int l = max({i, 0}); l < min({(j) + 1, N}); ++l) {

int sp = j;
for (int s = 0; s < min({(k) + 1, N}); ++s) {

int kp = k;
int jp = t;
int ip = l;
int lp = s;
E[i][j][k][l][s][t] += E[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int l = max({i, 0}); l < N; ++l) {

int jp = i;
for (int k = 0; k < min({(i) + 1, N}); ++k) {

int ip = l;
for (int s = 0; s < min({(k) + 1, N}); ++s) {

int kp = k;
int lp = s;
for (int j = 0; j < N; ++j) {

for (int t = max({l, 0}); t < min({(j) + 1, N}); ++t) {

int sp = j;
int tp = t;
E[i][j][k][l][s][t] += E[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

int lp = i;
for (int k = 0; k < min({(i) + 1, N}); ++k) {

for (int s = 0; s < min({(k) + 1, N}); ++s) {

int kp = k;
int tp = s;
for (int j = 0; j < N; ++j) {

for (int t = max({i, 0}); t < min({(j) + 1, N}); ++t) {

for (int l = max({j, 0}); l < N; ++l) {

int sp = j;
int jp = t;
int ip = l;
E[i][j][k][l][s][t] += E[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

int jp = i;
for (int k = 0; k < min({(i) + 1, N}); ++k) {

for (int s = 0; s < min({(k) + 1, N}); ++s) {

int kp = k;
int tp = s;
for (int j = 0; j < N; ++j) {

for (int l = 0; l < min({(j) + 1, N}); ++l) {

int sp = j;
for (int t = max({i, 0}); t < min({(l) + 1, N}); ++t) {

int ip = l;
int lp = t;
E[i][j][k][l][s][t] += E[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

int ip = i;
for (int j = 0; j < N; ++j) {

for (int l = 0; l < min({(j) + 1, N}); ++l) {

int sp = j;
for (int k = max({j, 0}); k < N; ++k) {

for (int s = 0; s < min({(l) + 1, N}); ++s) {

int jp = l;
for (int t = max({k, 0}); t < min({(i) + 1, N}); ++t) {

int lp = k;
int kp = s;
int tp = t;
E[i][j][k][l][s][t] += E[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int t = max({i, 0}); t < N; ++t) {

int tp = i;
int ip = t;
for (int j = 0; j < N; ++j) {

for (int l = 0; l < min({(j) + 1, N}); ++l) {

int sp = j;
for (int k = max({j, 0}); k < min({(i) + 1, N}); ++k) {

for (int s = 0; s < min({(l) + 1, N}); ++s) {

int jp = l;
int lp = k;
int kp = s;
E[i][j][k][l][s][t] += E[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

int ip = i;
for (int k = 0; k < min({(i) + 1, N}); ++k) {

int lp = k;
for (int j = 0; j < N; ++j) {

for (int t = max({j, 0}); t < min({(k) + 1, N}); ++t) {

for (int l = 0; l < min({(j) + 1, N}); ++l) {

int sp = j;
int kp = t;
for (int s = 0; s < min({(l) + 1, N}); ++s) {

int jp = l;
int tp = s;
E[i][j][k][l][s][t] += E[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

int kp = i;
for (int k = max({i, 0}); k < N; ++k) {

int lp = k;
for (int j = 0; j < N; ++j) {

for (int t = max({j, 0}); t < min({(i) + 1, N}); ++t) {

for (int l = 0; l < min({(j) + 1, N}); ++l) {

int sp = j;
int ip = t;
for (int s = 0; s < min({(l) + 1, N}); ++s) {

int jp = l;
int tp = s;
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

int tp = i;
for (int l = 0; l < min({(j) + 1, N}); ++l) {

int sp = j;
for (int t = max({k, 0}); t < N; ++t) {

int lp = k;
for (int s = 0; s < min({(l) + 1, N}); ++s) {

int jp = l;
int kp = t;
int ip = s;
E[i][j][k][l][s][t] += E[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

int kp = i;
for (int j = 0; j < min({(i) + 1, N}); ++j) {

for (int l = 0; l < min({(j) + 1, N}); ++l) {

int sp = j;
for (int s = 0; s < min({(l) + 1, N}); ++s) {

int jp = l;
int ip = s;
for (int k = 0; k < N; ++k) {

for (int t = max({i, 0}); t < min({(k) + 1, N}); ++t) {

int lp = k;
int tp = t;
E[i][j][k][l][s][t] += E[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

int ip = i;
for (int j = 0; j < N; ++j) {

for (int t = max({j, 0}); t < min({(i) + 1, N}); ++t) {

int sp = j;
for (int k = 0; k < min({(j) + 1, N}); ++k) {

int tp = t;
for (int l = 0; l < min({(k) + 1, N}); ++l) {

int lp = k;
for (int s = 0; s < min({(l) + 1, N}); ++s) {

int kp = l;
int jp = s;
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

int tp = i;
int ip = t;
int sp = j;
for (int k = 0; k < min({(j) + 1, N}); ++k) {

for (int l = 0; l < min({(k) + 1, N}); ++l) {

int lp = k;
for (int s = 0; s < min({(l) + 1, N}); ++s) {

int kp = l;
int jp = s;
E[i][j][k][l][s][t] += E[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

int ip = i;
for (int j = 0; j < min({(i) + 1, N}); ++j) {

int sp = j;
for (int k = 0; k < N; ++k) {

for (int t = max({k, 0}); t < min({(j) + 1, N}); ++t) {

for (int l = 0; l < min({(k) + 1, N}); ++l) {

int lp = k;
int jp = t;
for (int s = 0; s < min({(l) + 1, N}); ++s) {

int kp = l;
int tp = s;
E[i][j][k][l][s][t] += E[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

int jp = i;
for (int j = max({i, 0}); j < N; ++j) {

int sp = j;
for (int k = 0; k < N; ++k) {

for (int t = max({k, 0}); t < min({(i) + 1, N}); ++t) {

for (int l = 0; l < min({(k) + 1, N}); ++l) {

int lp = k;
int ip = t;
for (int s = 0; s < min({(l) + 1, N}); ++s) {

int kp = l;
int tp = s;
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

int tp = i;
for (int t = max({j, 0}); t < N; ++t) {

int sp = j;
for (int l = 0; l < min({(k) + 1, N}); ++l) {

int lp = k;
int jp = t;
for (int s = 0; s < min({(l) + 1, N}); ++s) {

int kp = l;
int ip = s;
E[i][j][k][l][s][t] += E[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

int jp = i;
for (int k = 0; k < min({(i) + 1, N}); ++k) {

for (int l = 0; l < min({(k) + 1, N}); ++l) {

int lp = k;
for (int s = 0; s < min({(l) + 1, N}); ++s) {

int kp = l;
int ip = s;
for (int j = 0; j < N; ++j) {

for (int t = max({i, 0}); t < min({(j) + 1, N}); ++t) {

int sp = j;
int tp = t;
E[i][j][k][l][s][t] += E[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

int ip = i;
for (int j = 0; j < N; ++j) {

int sp = j;
for (int k = max({j, 0}); k < min({(i) + 1, N}); ++k) {

for (int l = 0; l < N; ++l) {

int lp = k;
for (int s = 0; s < min({(l) + 1, N}); ++s) {

for (int t = max({l, 0}); t < min({(j) + 1, N}); ++t) {

int tp = l;
int jp = s;
int kp = t;
E[i][j][k][l][s][t] += E[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

int kp = i;
for (int j = 0; j < min({(i) + 1, N}); ++j) {

for (int k = max({i, 0}); k < N; ++k) {

int sp = j;
int lp = k;
for (int l = 0; l < N; ++l) {

for (int s = 0; s < min({(l) + 1, N}); ++s) {

for (int t = max({l, 0}); t < min({(j) + 1, N}); ++t) {

int tp = l;
int jp = s;
int ip = t;
E[i][j][k][l][s][t] += E[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

int ip = i;
for (int j = 0; j < min({(i) + 1, N}); ++j) {

int sp = j;
for (int k = 0; k < min({(j) + 1, N}); ++k) {

for (int l = 0; l < N; ++l) {

int lp = k;
for (int s = 0; s < min({(l) + 1, N}); ++s) {

for (int t = max({l, 0}); t < min({(k) + 1, N}); ++t) {

int tp = l;
int kp = s;
int jp = t;
E[i][j][k][l][s][t] += E[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

int jp = i;
for (int j = max({i, 0}); j < N; ++j) {

for (int k = 0; k < min({(i) + 1, N}); ++k) {

int sp = j;
int lp = k;
for (int l = 0; l < N; ++l) {

for (int s = 0; s < min({(l) + 1, N}); ++s) {

for (int t = max({l, 0}); t < min({(k) + 1, N}); ++t) {

int tp = l;
int kp = s;
int ip = t;
E[i][j][k][l][s][t] += E[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

int kp = i;
for (int j = max({i, 0}); j < N; ++j) {

int sp = j;
for (int k = max({j, 0}); k < N; ++k) {

for (int l = 0; l < N; ++l) {

int lp = k;
for (int s = 0; s < min({(l) + 1, N}); ++s) {

for (int t = max({l, 0}); t < min({(i) + 1, N}); ++t) {

int tp = l;
int ip = s;
int jp = t;
E[i][j][k][l][s][t] += E[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

int jp = i;
for (int j = 0; j < N; ++j) {

int sp = j;
for (int k = max({i, 0}); k < min({(j) + 1, N}); ++k) {

for (int l = 0; l < N; ++l) {

int lp = k;
for (int s = 0; s < min({(l) + 1, N}); ++s) {

for (int t = max({l, 0}); t < min({(i) + 1, N}); ++t) {

int tp = l;
int ip = s;
int kp = t;
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

int tp = i;
for (int s = 0; s < min({(l) + 1, N}); ++s) {

int ip = l;
int sp = j;
for (int k = max({j, 0}); k < N; ++k) {

int jp = s;
for (int t = max({k, 0}); t < N; ++t) {

int lp = k;
int kp = t;
E[i][j][k][l][s][t] += E[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int l = 0; l < min({(i) + 1, N}); ++l) {

int kp = i;
for (int j = max({i, 0}); j < N; ++j) {

for (int s = 0; s < min({(l) + 1, N}); ++s) {

int ip = l;
int sp = j;
int jp = s;
for (int k = 0; k < N; ++k) {

for (int t = max({j, 0}); t < min({(k) + 1, N}); ++t) {

int lp = k;
int tp = t;
E[i][j][k][l][s][t] += E[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int l = 0; l < min({(i) + 1, N}); ++l) {

int tp = i;
for (int s = 0; s < min({(l) + 1, N}); ++s) {

int ip = l;
int kp = s;
for (int j = 0; j < N; ++j) {

for (int t = max({j, 0}); t < N; ++t) {

int sp = j;
for (int k = max({i, 0}); k < min({(j) + 1, N}); ++k) {

int jp = t;
int lp = k;
E[i][j][k][l][s][t] += E[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int l = 0; l < min({(i) + 1, N}); ++l) {

int jp = i;
for (int k = max({i, 0}); k < N; ++k) {

for (int s = 0; s < min({(l) + 1, N}); ++s) {

int ip = l;
int lp = k;
int kp = s;
for (int j = 0; j < N; ++j) {

for (int t = max({k, 0}); t < min({(j) + 1, N}); ++t) {

int sp = j;
int tp = t;
E[i][j][k][l][s][t] += E[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int l = 0; l < min({(i) + 1, N}); ++l) {

int kp = i;
for (int s = 0; s < min({(l) + 1, N}); ++s) {

int ip = l;
int tp = s;
for (int j = 0; j < N; ++j) {

for (int t = max({i, 0}); t < min({(j) + 1, N}); ++t) {

int sp = j;
for (int k = max({j, 0}); k < N; ++k) {

int jp = t;
int lp = k;
E[i][j][k][l][s][t] += E[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int l = 0; l < min({(i) + 1, N}); ++l) {

int jp = i;
for (int s = 0; s < min({(l) + 1, N}); ++s) {

int ip = l;
int tp = s;
for (int j = 0; j < N; ++j) {

int sp = j;
for (int k = 0; k < min({(j) + 1, N}); ++k) {

for (int t = max({i, 0}); t < min({(k) + 1, N}); ++t) {

int lp = k;
int kp = t;
E[i][j][k][l][s][t] += E[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

int ip = i;
for (int j = 0; j < N; ++j) {

int sp = j;
for (int k = max({j, 0}); k < N; ++k) {

for (int l = max({k, 0}); l < min({(i) + 1, N}); ++l) {

int tp = k;
int jp = l;
for (int s = 0; s < N; ++s) {

for (int t = max({s, 0}); t < min({(j) + 1, N}); ++t) {

int kp = s;
int lp = t;
E[i][j][k][l][s][t] += E[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int l = max({i, 0}); l < N; ++l) {

int lp = i;
int jp = l;
for (int j = 0; j < N; ++j) {

int sp = j;
for (int k = max({j, 0}); k < min({(i) + 1, N}); ++k) {

int tp = k;
for (int s = 0; s < N; ++s) {

for (int t = max({s, 0}); t < min({(j) + 1, N}); ++t) {

int kp = s;
int ip = t;
E[i][j][k][l][s][t] += E[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

int ip = i;
for (int k = 0; k < min({(i) + 1, N}); ++k) {

for (int j = 0; j < N; ++j) {

int tp = k;
for (int l = max({j, 0}); l < min({(k) + 1, N}); ++l) {

int sp = j;
int jp = l;
for (int s = 0; s < N; ++s) {

for (int t = max({s, 0}); t < min({(j) + 1, N}); ++t) {

int lp = s;
int kp = t;
E[i][j][k][l][s][t] += E[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

int kp = i;
for (int k = max({i, 0}); k < N; ++k) {

for (int j = 0; j < N; ++j) {

int tp = k;
for (int l = max({j, 0}); l < min({(i) + 1, N}); ++l) {

int sp = j;
int jp = l;
for (int s = 0; s < N; ++s) {

for (int t = max({s, 0}); t < min({(j) + 1, N}); ++t) {

int lp = s;
int ip = t;
E[i][j][k][l][s][t] += E[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

int lp = i;
for (int j = 0; j < min({(i) + 1, N}); ++j) {

for (int k = max({i, 0}); k < N; ++k) {

int sp = j;
for (int l = max({k, 0}); l < N; ++l) {

int tp = k;
int jp = l;
for (int s = 0; s < N; ++s) {

for (int t = max({s, 0}); t < min({(j) + 1, N}); ++t) {

int ip = s;
int kp = t;
E[i][j][k][l][s][t] += E[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

int kp = i;
for (int j = 0; j < min({(i) + 1, N}); ++j) {

int sp = j;
for (int k = 0; k < N; ++k) {

for (int l = max({i, 0}); l < min({(k) + 1, N}); ++l) {

int tp = k;
int jp = l;
for (int s = 0; s < N; ++s) {

for (int t = max({s, 0}); t < min({(j) + 1, N}); ++t) {

int ip = s;
int lp = t;
E[i][j][k][l][s][t] += E[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

int ip = i;
for (int j = 0; j < N; ++j) {

for (int l = max({j, 0}); l < min({(i) + 1, N}); ++l) {

int sp = j;
for (int k = 0; k < min({(j) + 1, N}); ++k) {

int kp = l;
int tp = k;
for (int s = 0; s < N; ++s) {

for (int t = max({s, 0}); t < min({(k) + 1, N}); ++t) {

int jp = s;
int lp = t;
E[i][j][k][l][s][t] += E[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int l = max({i, 0}); l < N; ++l) {

int lp = i;
for (int j = 0; j < min({(i) + 1, N}); ++j) {

int kp = l;
int sp = j;
for (int k = 0; k < min({(j) + 1, N}); ++k) {

int tp = k;
for (int s = 0; s < N; ++s) {

for (int t = max({s, 0}); t < min({(k) + 1, N}); ++t) {

int jp = s;
int ip = t;
E[i][j][k][l][s][t] += E[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

int ip = i;
for (int j = 0; j < min({(i) + 1, N}); ++j) {

int sp = j;
for (int k = 0; k < N; ++k) {

for (int l = max({k, 0}); l < min({(j) + 1, N}); ++l) {

int tp = k;
int kp = l;
for (int s = 0; s < N; ++s) {

for (int t = max({s, 0}); t < min({(k) + 1, N}); ++t) {

int lp = s;
int jp = t;
E[i][j][k][l][s][t] += E[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

int jp = i;
for (int j = max({i, 0}); j < N; ++j) {

int sp = j;
for (int k = 0; k < N; ++k) {

for (int l = max({k, 0}); l < min({(i) + 1, N}); ++l) {

int tp = k;
int kp = l;
for (int s = 0; s < N; ++s) {

for (int t = max({s, 0}); t < min({(k) + 1, N}); ++t) {

int lp = s;
int ip = t;
E[i][j][k][l][s][t] += E[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

int lp = i;
for (int j = max({i, 0}); j < N; ++j) {

for (int k = 0; k < min({(i) + 1, N}); ++k) {

for (int l = max({j, 0}); l < N; ++l) {

int sp = j;
int tp = k;
int kp = l;
for (int s = 0; s < N; ++s) {

for (int t = max({s, 0}); t < min({(k) + 1, N}); ++t) {

int ip = s;
int jp = t;
E[i][j][k][l][s][t] += E[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

int jp = i;
for (int k = 0; k < min({(i) + 1, N}); ++k) {

for (int j = 0; j < N; ++j) {

int tp = k;
for (int l = max({i, 0}); l < min({(j) + 1, N}); ++l) {

int sp = j;
int kp = l;
for (int s = 0; s < N; ++s) {

for (int t = max({s, 0}); t < min({(k) + 1, N}); ++t) {

int ip = s;
int lp = t;
E[i][j][k][l][s][t] += E[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

int ip = i;
for (int j = 0; j < N; ++j) {

for (int l = 0; l < min({(j) + 1, N}); ++l) {

int sp = j;
for (int k = max({j, 0}); k < min({(i) + 1, N}); ++k) {

int lp = l;
int tp = k;
for (int s = 0; s < N; ++s) {

for (int t = max({s, 0}); t < min({(l) + 1, N}); ++t) {

int jp = s;
int kp = t;
E[i][j][k][l][s][t] += E[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

int kp = i;
for (int j = 0; j < min({(i) + 1, N}); ++j) {

for (int k = max({i, 0}); k < N; ++k) {

for (int l = 0; l < min({(j) + 1, N}); ++l) {

int sp = j;
int tp = k;
int lp = l;
for (int s = 0; s < N; ++s) {

for (int t = max({s, 0}); t < min({(l) + 1, N}); ++t) {

int jp = s;
int ip = t;
E[i][j][k][l][s][t] += E[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

int ip = i;
for (int j = 0; j < min({(i) + 1, N}); ++j) {

int sp = j;
for (int k = 0; k < min({(j) + 1, N}); ++k) {

for (int l = 0; l < min({(k) + 1, N}); ++l) {

int tp = k;
int lp = l;
for (int s = 0; s < N; ++s) {

for (int t = max({s, 0}); t < min({(l) + 1, N}); ++t) {

int kp = s;
int jp = t;
E[i][j][k][l][s][t] += E[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

int jp = i;
for (int j = max({i, 0}); j < N; ++j) {

for (int k = 0; k < min({(i) + 1, N}); ++k) {

int sp = j;
for (int l = 0; l < min({(k) + 1, N}); ++l) {

int tp = k;
int lp = l;
for (int s = 0; s < N; ++s) {

for (int t = max({s, 0}); t < min({(l) + 1, N}); ++t) {

int kp = s;
int ip = t;
E[i][j][k][l][s][t] += E[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int l = 0; l < min({(i) + 1, N}); ++l) {

int kp = i;
for (int j = max({i, 0}); j < N; ++j) {

int lp = l;
int sp = j;
for (int k = max({j, 0}); k < N; ++k) {

int tp = k;
for (int s = 0; s < N; ++s) {

for (int t = max({s, 0}); t < min({(l) + 1, N}); ++t) {

int ip = s;
int jp = t;
E[i][j][k][l][s][t] += E[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int l = 0; l < min({(i) + 1, N}); ++l) {

int jp = i;
int lp = l;
for (int j = 0; j < N; ++j) {

int sp = j;
for (int k = max({i, 0}); k < min({(j) + 1, N}); ++k) {

int tp = k;
for (int s = 0; s < N; ++s) {

for (int t = max({s, 0}); t < min({(l) + 1, N}); ++t) {

int ip = s;
int kp = t;
E[i][j][k][l][s][t] += E[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

int lp = i;
for (int j = max({i, 0}); j < N; ++j) {

int sp = j;
for (int k = max({j, 0}); k < N; ++k) {

for (int l = max({k, 0}); l < N; ++l) {

int tp = k;
int ip = l;
for (int s = 0; s < N; ++s) {

for (int t = max({s, 0}); t < min({(i) + 1, N}); ++t) {

int jp = s;
int kp = t;
E[i][j][k][l][s][t] += E[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

int kp = i;
for (int j = max({i, 0}); j < N; ++j) {

int sp = j;
for (int k = 0; k < N; ++k) {

for (int l = max({j, 0}); l < min({(k) + 1, N}); ++l) {

int tp = k;
int ip = l;
for (int s = 0; s < N; ++s) {

for (int t = max({s, 0}); t < min({(i) + 1, N}); ++t) {

int jp = s;
int lp = t;
E[i][j][k][l][s][t] += E[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

int lp = i;
for (int j = 0; j < N; ++j) {

for (int l = max({j, 0}); l < N; ++l) {

int sp = j;
for (int k = max({i, 0}); k < min({(j) + 1, N}); ++k) {

int ip = l;
int tp = k;
for (int s = 0; s < N; ++s) {

for (int t = max({s, 0}); t < min({(i) + 1, N}); ++t) {

int kp = s;
int jp = t;
E[i][j][k][l][s][t] += E[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

int jp = i;
for (int k = max({i, 0}); k < N; ++k) {

for (int j = 0; j < N; ++j) {

int tp = k;
for (int l = max({k, 0}); l < min({(j) + 1, N}); ++l) {

int sp = j;
int ip = l;
for (int s = 0; s < N; ++s) {

for (int t = max({s, 0}); t < min({(i) + 1, N}); ++t) {

int kp = s;
int lp = t;
E[i][j][k][l][s][t] += E[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

int kp = i;
for (int j = 0; j < N; ++j) {

for (int l = max({i, 0}); l < min({(j) + 1, N}); ++l) {

int sp = j;
for (int k = max({j, 0}); k < N; ++k) {

int ip = l;
int tp = k;
for (int s = 0; s < N; ++s) {

for (int t = max({s, 0}); t < min({(i) + 1, N}); ++t) {

int lp = s;
int jp = t;
E[i][j][k][l][s][t] += E[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

int jp = i;
for (int j = 0; j < N; ++j) {

int sp = j;
for (int k = 0; k < min({(j) + 1, N}); ++k) {

for (int l = max({i, 0}); l < min({(k) + 1, N}); ++l) {

int tp = k;
int ip = l;
for (int s = 0; s < N; ++s) {

for (int t = max({s, 0}); t < min({(i) + 1, N}); ++t) {

int lp = s;
int kp = t;
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

int tp = i;
int kp = s;
int sp = j;
for (int k = max({j, 0}); k < N; ++k) {

for (int l = max({k, 0}); l < N; ++l) {

int ip = k;
for (int t = max({l, 0}); t < N; ++t) {

int jp = l;
int lp = t;
E[i][j][k][l][s][t] += E[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int s = 0; s < min({(i) + 1, N}); ++s) {

int lp = i;
for (int j = max({i, 0}); j < N; ++j) {

int kp = s;
int sp = j;
for (int k = max({j, 0}); k < N; ++k) {

for (int l = 0; l < N; ++l) {

int ip = k;
for (int t = max({k, 0}); t < min({(l) + 1, N}); ++t) {

int jp = l;
int tp = t;
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

int tp = i;
int lp = s;
int sp = j;
for (int k = 0; k < N; ++k) {

for (int t = max({k, 0}); t < N; ++t) {

for (int l = max({j, 0}); l < min({(k) + 1, N}); ++l) {

int ip = k;
int kp = t;
int jp = l;
E[i][j][k][l][s][t] += E[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int s = 0; s < min({(i) + 1, N}); ++s) {

int kp = i;
for (int j = max({i, 0}); j < N; ++j) {

int lp = s;
for (int l = max({j, 0}); l < N; ++l) {

int sp = j;
int jp = l;
for (int k = 0; k < N; ++k) {

for (int t = max({l, 0}); t < min({(k) + 1, N}); ++t) {

int ip = k;
int tp = t;
E[i][j][k][l][s][t] += E[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int s = 0; s < min({(i) + 1, N}); ++s) {

int lp = i;
for (int j = max({i, 0}); j < N; ++j) {

int tp = s;
int sp = j;
for (int k = 0; k < N; ++k) {

for (int t = max({j, 0}); t < min({(k) + 1, N}); ++t) {

for (int l = max({k, 0}); l < N; ++l) {

int ip = k;
int kp = t;
int jp = l;
E[i][j][k][l][s][t] += E[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int s = 0; s < min({(i) + 1, N}); ++s) {

int kp = i;
for (int j = max({i, 0}); j < N; ++j) {

int tp = s;
int sp = j;
for (int k = 0; k < N; ++k) {

for (int l = 0; l < min({(k) + 1, N}); ++l) {

int ip = k;
for (int t = max({j, 0}); t < min({(l) + 1, N}); ++t) {

int jp = l;
int lp = t;
E[i][j][k][l][s][t] += E[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int s = 0; s < min({(i) + 1, N}); ++s) {

int tp = i;
int jp = s;
for (int j = 0; j < N; ++j) {

for (int l = max({j, 0}); l < N; ++l) {

int sp = j;
for (int k = max({i, 0}); k < min({(j) + 1, N}); ++k) {

for (int t = max({l, 0}); t < N; ++t) {

int kp = l;
int ip = k;
int lp = t;
E[i][j][k][l][s][t] += E[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int s = 0; s < min({(i) + 1, N}); ++s) {

int lp = i;
int jp = s;
for (int j = 0; j < N; ++j) {

int sp = j;
for (int k = max({i, 0}); k < min({(j) + 1, N}); ++k) {

for (int l = 0; l < N; ++l) {

int ip = k;
for (int t = max({j, 0}); t < min({(l) + 1, N}); ++t) {

int kp = l;
int tp = t;
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

int tp = i;
int lp = s;
int ip = k;
for (int j = 0; j < N; ++j) {

for (int t = max({j, 0}); t < N; ++t) {

for (int l = max({k, 0}); l < min({(j) + 1, N}); ++l) {

int sp = j;
int jp = t;
int kp = l;
E[i][j][k][l][s][t] += E[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int s = 0; s < min({(i) + 1, N}); ++s) {

int jp = i;
for (int k = max({i, 0}); k < N; ++k) {

int lp = s;
for (int l = max({k, 0}); l < N; ++l) {

int ip = k;
int kp = l;
for (int j = 0; j < N; ++j) {

for (int t = max({l, 0}); t < min({(j) + 1, N}); ++t) {

int sp = j;
int tp = t;
E[i][j][k][l][s][t] += E[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int s = 0; s < min({(i) + 1, N}); ++s) {

int lp = i;
for (int k = max({i, 0}); k < N; ++k) {

int tp = s;
int ip = k;
for (int j = 0; j < N; ++j) {

for (int t = max({k, 0}); t < min({(j) + 1, N}); ++t) {

for (int l = max({j, 0}); l < N; ++l) {

int sp = j;
int jp = t;
int kp = l;
E[i][j][k][l][s][t] += E[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int s = 0; s < min({(i) + 1, N}); ++s) {

int jp = i;
for (int k = max({i, 0}); k < N; ++k) {

int tp = s;
int ip = k;
for (int j = 0; j < N; ++j) {

for (int l = 0; l < min({(j) + 1, N}); ++l) {

int sp = j;
for (int t = max({k, 0}); t < min({(l) + 1, N}); ++t) {

int kp = l;
int lp = t;
E[i][j][k][l][s][t] += E[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int s = 0; s < min({(i) + 1, N}); ++s) {

int tp = i;
int jp = s;
for (int j = 0; j < N; ++j) {

for (int l = max({i, 0}); l < min({(j) + 1, N}); ++l) {

int sp = j;
for (int k = max({j, 0}); k < N; ++k) {

int lp = l;
for (int t = max({k, 0}); t < N; ++t) {

int ip = k;
int kp = t;
E[i][j][k][l][s][t] += E[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int s = 0; s < min({(i) + 1, N}); ++s) {

int kp = i;
int jp = s;
for (int j = 0; j < N; ++j) {

for (int l = max({i, 0}); l < min({(j) + 1, N}); ++l) {

int sp = j;
int lp = l;
for (int k = 0; k < N; ++k) {

for (int t = max({j, 0}); t < min({(k) + 1, N}); ++t) {

int ip = k;
int tp = t;
E[i][j][k][l][s][t] += E[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int s = 0; s < min({(i) + 1, N}); ++s) {

int tp = i;
int kp = s;
for (int j = 0; j < N; ++j) {

for (int t = max({j, 0}); t < N; ++t) {

int sp = j;
for (int k = 0; k < min({(j) + 1, N}); ++k) {

int jp = t;
for (int l = max({i, 0}); l < min({(k) + 1, N}); ++l) {

int ip = k;
int lp = l;
E[i][j][k][l][s][t] += E[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int s = 0; s < min({(i) + 1, N}); ++s) {

int jp = i;
int kp = s;
for (int j = 0; j < N; ++j) {

int sp = j;
for (int k = 0; k < N; ++k) {

for (int t = max({k, 0}); t < min({(j) + 1, N}); ++t) {

for (int l = max({i, 0}); l < min({(k) + 1, N}); ++l) {

int ip = k;
int tp = t;
int lp = l;
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

int kp = i;
int tp = s;
int lp = l;
for (int j = 0; j < N; ++j) {

for (int t = max({l, 0}); t < min({(j) + 1, N}); ++t) {

int sp = j;
for (int k = max({j, 0}); k < N; ++k) {

int jp = t;
int ip = k;
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

int jp = i;
int tp = s;
int lp = l;
for (int j = 0; j < N; ++j) {

int sp = j;
for (int k = 0; k < min({(j) + 1, N}); ++k) {

for (int t = max({l, 0}); t < min({(k) + 1, N}); ++t) {

int ip = k;
int kp = t;
E[i][j][k][l][s][t] += E[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int s = 0; s < min({(i) + 1, N}); ++s) {

int lp = i;
int jp = s;
for (int j = 0; j < N; ++j) {

for (int t = max({i, 0}); t < min({(j) + 1, N}); ++t) {

int sp = j;
for (int k = max({j, 0}); k < N; ++k) {

int kp = t;
for (int l = max({k, 0}); l < N; ++l) {

int ip = k;
int tp = l;
E[i][j][k][l][s][t] += E[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int s = 0; s < min({(i) + 1, N}); ++s) {

int kp = i;
int jp = s;
for (int j = 0; j < N; ++j) {

for (int t = max({i, 0}); t < min({(j) + 1, N}); ++t) {

int sp = j;
int lp = t;
for (int k = 0; k < N; ++k) {

for (int l = max({j, 0}); l < min({(k) + 1, N}); ++l) {

int ip = k;
int tp = l;
E[i][j][k][l][s][t] += E[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int s = 0; s < min({(i) + 1, N}); ++s) {

int lp = i;
int kp = s;
for (int j = 0; j < N; ++j) {

for (int l = max({j, 0}); l < N; ++l) {

int sp = j;
for (int k = 0; k < min({(j) + 1, N}); ++k) {

int tp = l;
for (int t = max({i, 0}); t < min({(k) + 1, N}); ++t) {

int ip = k;
int jp = t;
E[i][j][k][l][s][t] += E[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int s = 0; s < min({(i) + 1, N}); ++s) {

int jp = i;
int kp = s;
for (int j = 0; j < N; ++j) {

int sp = j;
for (int k = 0; k < N; ++k) {

for (int t = max({i, 0}); t < min({(k) + 1, N}); ++t) {

for (int l = max({k, 0}); l < min({(j) + 1, N}); ++l) {

int ip = k;
int lp = t;
int tp = l;
E[i][j][k][l][s][t] += E[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int s = 0; s < min({(i) + 1, N}); ++s) {

int kp = i;
int lp = s;
for (int j = 0; j < N; ++j) {

for (int l = 0; l < min({(j) + 1, N}); ++l) {

int sp = j;
for (int k = max({j, 0}); k < N; ++k) {

for (int t = max({i, 0}); t < min({(l) + 1, N}); ++t) {

int tp = l;
int ip = k;
int jp = t;
E[i][j][k][l][s][t] += E[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int s = 0; s < min({(i) + 1, N}); ++s) {

int jp = i;
int lp = s;
for (int j = 0; j < N; ++j) {

int sp = j;
for (int k = 0; k < min({(j) + 1, N}); ++k) {

for (int l = 0; l < min({(k) + 1, N}); ++l) {

int ip = k;
for (int t = max({i, 0}); t < min({(l) + 1, N}); ++t) {

int tp = l;
int kp = t;
E[i][j][k][l][s][t] += E[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

int ip = i;
for (int j = 0; j < N; ++j) {

for (int t = 0; t < min({(j) + 1, N}); ++t) {

for (int k = max({j, 0}); k < N; ++k) {

int tp = j;
int sp = t;
for (int l = max({k, 0}); l < N; ++l) {

int jp = k;
for (int s = max({l, 0}); s < min({(i) + 1, N}); ++s) {

int kp = l;
int lp = s;
E[i][j][k][l][s][t] += E[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int s = max({i, 0}); s < N; ++s) {

int sp = i;
int lp = s;
for (int j = 0; j < N; ++j) {

for (int t = 0; t < min({(j) + 1, N}); ++t) {

for (int k = max({j, 0}); k < N; ++k) {

int tp = j;
int ip = t;
for (int l = max({k, 0}); l < min({(i) + 1, N}); ++l) {

int jp = k;
int kp = l;
E[i][j][k][l][s][t] += E[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int l = 0; l < min({(i) + 1, N}); ++l) {

int ip = i;
int kp = l;
for (int j = 0; j < N; ++j) {

for (int t = 0; t < min({(j) + 1, N}); ++t) {

for (int k = max({j, 0}); k < N; ++k) {

int tp = j;
int lp = t;
for (int s = max({k, 0}); s < min({(l) + 1, N}); ++s) {

int jp = k;
int sp = s;
E[i][j][k][l][s][t] += E[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int l = max({i, 0}); l < N; ++l) {

int lp = i;
int kp = l;
for (int j = 0; j < N; ++j) {

for (int t = 0; t < min({(j) + 1, N}); ++t) {

for (int k = max({j, 0}); k < N; ++k) {

int tp = j;
int ip = t;
for (int s = max({k, 0}); s < min({(i) + 1, N}); ++s) {

int jp = k;
int sp = s;
E[i][j][k][l][s][t] += E[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int l = max({i, 0}); l < N; ++l) {

int sp = i;
for (int s = max({l, 0}); s < N; ++s) {

int kp = l;
int ip = s;
for (int j = 0; j < N; ++j) {

for (int t = 0; t < min({(j) + 1, N}); ++t) {

for (int k = max({j, 0}); k < min({(i) + 1, N}); ++k) {

int tp = j;
int lp = t;
int jp = k;
E[i][j][k][l][s][t] += E[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

int lp = i;
for (int j = 0; j < N; ++j) {

for (int t = 0; t < min({(j) + 1, N}); ++t) {

for (int k = max({j, 0}); k < min({(i) + 1, N}); ++k) {

int tp = j;
int sp = t;
int jp = k;
for (int l = 0; l < N; ++l) {

for (int s = max({i, 0}); s < min({(l) + 1, N}); ++s) {

int kp = l;
int ip = s;
E[i][j][k][l][s][t] += E[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

int ip = i;
for (int j = 0; j < N; ++j) {

for (int t = 0; t < min({(j) + 1, N}); ++t) {

int tp = j;
int sp = t;
for (int k = 0; k < N; ++k) {

for (int s = max({k, 0}); s < min({(i) + 1, N}); ++s) {

for (int l = max({j, 0}); l < min({(k) + 1, N}); ++l) {

int jp = k;
int kp = s;
int lp = l;
E[i][j][k][l][s][t] += E[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int s = max({i, 0}); s < N; ++s) {

int sp = i;
for (int k = 0; k < min({(i) + 1, N}); ++k) {

int kp = s;
int jp = k;
for (int j = 0; j < N; ++j) {

for (int t = 0; t < min({(j) + 1, N}); ++t) {

for (int l = max({j, 0}); l < min({(k) + 1, N}); ++l) {

int tp = j;
int ip = t;
int lp = l;
E[i][j][k][l][s][t] += E[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

int ip = i;
for (int k = 0; k < min({(i) + 1, N}); ++k) {

int jp = k;
for (int j = 0; j < N; ++j) {

for (int t = 0; t < min({(j) + 1, N}); ++t) {

for (int l = max({j, 0}); l < N; ++l) {

int tp = j;
int kp = t;
for (int s = max({l, 0}); s < min({(k) + 1, N}); ++s) {

int lp = l;
int sp = s;
E[i][j][k][l][s][t] += E[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

int kp = i;
for (int k = max({i, 0}); k < N; ++k) {

int jp = k;
for (int j = 0; j < N; ++j) {

for (int t = 0; t < min({(j) + 1, N}); ++t) {

for (int l = max({j, 0}); l < N; ++l) {

int tp = j;
int ip = t;
for (int s = max({l, 0}); s < min({(i) + 1, N}); ++s) {

int lp = l;
int sp = s;
E[i][j][k][l][s][t] += E[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

int sp = i;
for (int k = max({i, 0}); k < N; ++k) {

for (int s = max({k, 0}); s < N; ++s) {

int jp = k;
int ip = s;
for (int j = 0; j < N; ++j) {

for (int t = 0; t < min({(j) + 1, N}); ++t) {

for (int l = max({j, 0}); l < min({(i) + 1, N}); ++l) {

int tp = j;
int kp = t;
int lp = l;
E[i][j][k][l][s][t] += E[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

int kp = i;
for (int j = 0; j < N; ++j) {

for (int t = 0; t < min({(j) + 1, N}); ++t) {

for (int l = max({j, 0}); l < min({(i) + 1, N}); ++l) {

int tp = j;
int sp = t;
int lp = l;
for (int k = 0; k < N; ++k) {

for (int s = max({i, 0}); s < min({(k) + 1, N}); ++s) {

int jp = k;
int ip = s;
E[i][j][k][l][s][t] += E[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

int ip = i;
for (int j = 0; j < N; ++j) {

for (int t = 0; t < min({(j) + 1, N}); ++t) {

int tp = j;
int lp = t;
for (int k = 0; k < N; ++k) {

for (int s = max({j, 0}); s < min({(k) + 1, N}); ++s) {

for (int l = max({k, 0}); l < min({(i) + 1, N}); ++l) {

int jp = k;
int kp = s;
int sp = l;
E[i][j][k][l][s][t] += E[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int l = max({i, 0}); l < N; ++l) {

int lp = i;
for (int k = 0; k < min({(i) + 1, N}); ++k) {

int sp = l;
int jp = k;
for (int j = 0; j < N; ++j) {

for (int s = max({j, 0}); s < min({(k) + 1, N}); ++s) {

for (int t = 0; t < min({(j) + 1, N}); ++t) {

int tp = j;
int kp = s;
int ip = t;
E[i][j][k][l][s][t] += E[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

int ip = i;
for (int k = 0; k < min({(i) + 1, N}); ++k) {

for (int l = 0; l < min({(k) + 1, N}); ++l) {

int jp = k;
int sp = l;
for (int j = 0; j < N; ++j) {

for (int s = max({j, 0}); s < min({(l) + 1, N}); ++s) {

for (int t = 0; t < min({(j) + 1, N}); ++t) {

int tp = j;
int lp = s;
int kp = t;
E[i][j][k][l][s][t] += E[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int l = 0; l < min({(i) + 1, N}); ++l) {

int kp = i;
for (int k = max({i, 0}); k < N; ++k) {

int sp = l;
int jp = k;
for (int j = 0; j < N; ++j) {

for (int s = max({j, 0}); s < min({(l) + 1, N}); ++s) {

for (int t = 0; t < min({(j) + 1, N}); ++t) {

int tp = j;
int lp = s;
int ip = t;
E[i][j][k][l][s][t] += E[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

int lp = i;
for (int k = max({i, 0}); k < N; ++k) {

for (int l = max({k, 0}); l < N; ++l) {

int jp = k;
int sp = l;
for (int j = 0; j < N; ++j) {

for (int s = max({j, 0}); s < min({(i) + 1, N}); ++s) {

for (int t = 0; t < min({(j) + 1, N}); ++t) {

int tp = j;
int ip = s;
int kp = t;
E[i][j][k][l][s][t] += E[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

int kp = i;
for (int j = 0; j < N; ++j) {

for (int s = max({j, 0}); s < min({(i) + 1, N}); ++s) {

for (int t = 0; t < min({(j) + 1, N}); ++t) {

int tp = j;
int ip = s;
int lp = t;
for (int k = 0; k < N; ++k) {

for (int l = max({i, 0}); l < min({(k) + 1, N}); ++l) {

int jp = k;
int sp = l;
E[i][j][k][l][s][t] += E[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

int sp = i;
for (int j = 0; j < min({(i) + 1, N}); ++j) {

for (int k = max({i, 0}); k < N; ++k) {

for (int t = 0; t < min({(j) + 1, N}); ++t) {

int tp = j;
for (int l = max({k, 0}); l < N; ++l) {

int jp = k;
int lp = t;
for (int s = max({l, 0}); s < N; ++s) {

int ip = l;
int kp = s;
E[i][j][k][l][s][t] += E[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

int lp = i;
for (int j = 0; j < min({(i) + 1, N}); ++j) {

for (int k = max({i, 0}); k < N; ++k) {

for (int t = 0; t < min({(j) + 1, N}); ++t) {

int tp = j;
int jp = k;
int sp = t;
for (int l = 0; l < N; ++l) {

for (int s = max({k, 0}); s < min({(l) + 1, N}); ++s) {

int ip = l;
int kp = s;
E[i][j][k][l][s][t] += E[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

int sp = i;
for (int j = 0; j < min({(i) + 1, N}); ++j) {

for (int t = 0; t < min({(j) + 1, N}); ++t) {

int tp = j;
int kp = t;
for (int k = 0; k < N; ++k) {

for (int s = max({k, 0}); s < N; ++s) {

for (int l = max({i, 0}); l < min({(k) + 1, N}); ++l) {

int jp = k;
int lp = s;
int ip = l;
E[i][j][k][l][s][t] += E[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int l = max({i, 0}); l < N; ++l) {

int kp = i;
for (int j = 0; j < min({(i) + 1, N}); ++j) {

int ip = l;
for (int t = 0; t < min({(j) + 1, N}); ++t) {

int tp = j;
int sp = t;
for (int k = 0; k < N; ++k) {

for (int s = max({l, 0}); s < min({(k) + 1, N}); ++s) {

int jp = k;
int lp = s;
E[i][j][k][l][s][t] += E[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

int lp = i;
for (int j = 0; j < min({(i) + 1, N}); ++j) {

for (int t = 0; t < min({(j) + 1, N}); ++t) {

int tp = j;
int kp = t;
for (int k = 0; k < N; ++k) {

for (int s = max({i, 0}); s < min({(k) + 1, N}); ++s) {

for (int l = max({k, 0}); l < N; ++l) {

int jp = k;
int sp = s;
int ip = l;
E[i][j][k][l][s][t] += E[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

int kp = i;
for (int j = 0; j < min({(i) + 1, N}); ++j) {

for (int t = 0; t < min({(j) + 1, N}); ++t) {

int tp = j;
int lp = t;
for (int k = 0; k < N; ++k) {

for (int l = 0; l < min({(k) + 1, N}); ++l) {

int jp = k;
for (int s = max({i, 0}); s < min({(l) + 1, N}); ++s) {

int ip = l;
int sp = s;
E[i][j][k][l][s][t] += E[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

int ip = i;
for (int j = 0; j < N; ++j) {

for (int l = max({j, 0}); l < N; ++l) {

for (int k = 0; k < min({(j) + 1, N}); ++k) {

int tp = j;
for (int s = max({l, 0}); s < min({(i) + 1, N}); ++s) {

int jp = l;
for (int t = 0; t < min({(k) + 1, N}); ++t) {

int kp = k;
int lp = s;
int sp = t;
E[i][j][k][l][s][t] += E[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int s = max({i, 0}); s < N; ++s) {

int sp = i;
int lp = s;
for (int j = 0; j < N; ++j) {

for (int l = max({j, 0}); l < min({(i) + 1, N}); ++l) {

for (int k = 0; k < min({(j) + 1, N}); ++k) {

int tp = j;
int jp = l;
for (int t = 0; t < min({(k) + 1, N}); ++t) {

int kp = k;
int ip = t;
E[i][j][k][l][s][t] += E[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int l = 0; l < min({(i) + 1, N}); ++l) {

int ip = i;
int jp = l;
for (int j = 0; j < N; ++j) {

for (int s = max({j, 0}); s < min({(l) + 1, N}); ++s) {

for (int k = 0; k < min({(j) + 1, N}); ++k) {

int tp = j;
int sp = s;
for (int t = 0; t < min({(k) + 1, N}); ++t) {

int kp = k;
int lp = t;
E[i][j][k][l][s][t] += E[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int l = max({i, 0}); l < N; ++l) {

int lp = i;
int jp = l;
for (int j = 0; j < N; ++j) {

for (int s = max({j, 0}); s < min({(i) + 1, N}); ++s) {

for (int k = 0; k < min({(j) + 1, N}); ++k) {

int tp = j;
int sp = s;
for (int t = 0; t < min({(k) + 1, N}); ++t) {

int kp = k;
int ip = t;
E[i][j][k][l][s][t] += E[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int l = max({i, 0}); l < N; ++l) {

int sp = i;
for (int j = 0; j < min({(i) + 1, N}); ++j) {

for (int s = max({l, 0}); s < N; ++s) {

int jp = l;
for (int k = 0; k < min({(j) + 1, N}); ++k) {

int tp = j;
int ip = s;
for (int t = 0; t < min({(k) + 1, N}); ++t) {

int kp = k;
int lp = t;
E[i][j][k][l][s][t] += E[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

int lp = i;
for (int j = 0; j < min({(i) + 1, N}); ++j) {

for (int k = 0; k < min({(j) + 1, N}); ++k) {

int tp = j;
for (int t = 0; t < min({(k) + 1, N}); ++t) {

int kp = k;
int sp = t;
for (int l = 0; l < N; ++l) {

for (int s = max({i, 0}); s < min({(l) + 1, N}); ++s) {

int jp = l;
int ip = s;
E[i][j][k][l][s][t] += E[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

int ip = i;
for (int j = 0; j < N; ++j) {

for (int s = max({j, 0}); s < min({(i) + 1, N}); ++s) {

int tp = j;
int jp = s;
for (int k = 0; k < N; ++k) {

for (int t = 0; t < min({(k) + 1, N}); ++t) {

for (int l = max({k, 0}); l < min({(j) + 1, N}); ++l) {

int kp = k;
int sp = t;
int lp = l;
E[i][j][k][l][s][t] += E[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int s = max({i, 0}); s < N; ++s) {

int sp = i;
for (int j = 0; j < min({(i) + 1, N}); ++j) {

int jp = s;
int tp = j;
for (int k = 0; k < N; ++k) {

for (int t = 0; t < min({(k) + 1, N}); ++t) {

for (int l = max({k, 0}); l < min({(j) + 1, N}); ++l) {

int kp = k;
int ip = t;
int lp = l;
E[i][j][k][l][s][t] += E[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

int ip = i;
for (int j = 0; j < min({(i) + 1, N}); ++j) {

for (int k = 0; k < N; ++k) {

int tp = j;
for (int t = 0; t < min({(k) + 1, N}); ++t) {

for (int l = max({k, 0}); l < N; ++l) {

int kp = k;
int jp = t;
for (int s = max({l, 0}); s < min({(j) + 1, N}); ++s) {

int lp = l;
int sp = s;
E[i][j][k][l][s][t] += E[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

int jp = i;
for (int j = max({i, 0}); j < N; ++j) {

for (int k = 0; k < N; ++k) {

int tp = j;
for (int t = 0; t < min({(k) + 1, N}); ++t) {

for (int l = max({k, 0}); l < N; ++l) {

int kp = k;
int ip = t;
for (int s = max({l, 0}); s < min({(i) + 1, N}); ++s) {

int lp = l;
int sp = s;
E[i][j][k][l][s][t] += E[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

int sp = i;
for (int j = max({i, 0}); j < N; ++j) {

for (int s = max({j, 0}); s < N; ++s) {

int tp = j;
int ip = s;
for (int k = 0; k < N; ++k) {

for (int t = 0; t < min({(k) + 1, N}); ++t) {

for (int l = max({k, 0}); l < min({(i) + 1, N}); ++l) {

int kp = k;
int jp = t;
int lp = l;
E[i][j][k][l][s][t] += E[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

int jp = i;
for (int j = 0; j < N; ++j) {

for (int s = max({i, 0}); s < min({(j) + 1, N}); ++s) {

int tp = j;
int ip = s;
for (int k = 0; k < N; ++k) {

for (int t = 0; t < min({(k) + 1, N}); ++t) {

for (int l = max({k, 0}); l < min({(i) + 1, N}); ++l) {

int kp = k;
int sp = t;
int lp = l;
E[i][j][k][l][s][t] += E[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

int ip = i;
for (int j = 0; j < N; ++j) {

for (int l = max({j, 0}); l < min({(i) + 1, N}); ++l) {

int tp = j;
int sp = l;
for (int k = 0; k < N; ++k) {

for (int s = max({k, 0}); s < min({(j) + 1, N}); ++s) {

for (int t = 0; t < min({(k) + 1, N}); ++t) {

int kp = k;
int jp = s;
int lp = t;
E[i][j][k][l][s][t] += E[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int l = max({i, 0}); l < N; ++l) {

int lp = i;
for (int j = 0; j < min({(i) + 1, N}); ++j) {

int sp = l;
int tp = j;
for (int k = 0; k < N; ++k) {

for (int s = max({k, 0}); s < min({(j) + 1, N}); ++s) {

for (int t = 0; t < min({(k) + 1, N}); ++t) {

int kp = k;
int jp = s;
int ip = t;
E[i][j][k][l][s][t] += E[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

int ip = i;
for (int j = 0; j < min({(i) + 1, N}); ++j) {

for (int l = 0; l < min({(j) + 1, N}); ++l) {

int tp = j;
int sp = l;
for (int k = 0; k < N; ++k) {

for (int s = max({k, 0}); s < min({(l) + 1, N}); ++s) {

for (int t = 0; t < min({(k) + 1, N}); ++t) {

int kp = k;
int lp = s;
int jp = t;
E[i][j][k][l][s][t] += E[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int l = 0; l < min({(i) + 1, N}); ++l) {

int jp = i;
for (int j = max({i, 0}); j < N; ++j) {

int sp = l;
int tp = j;
for (int k = 0; k < N; ++k) {

for (int s = max({k, 0}); s < min({(l) + 1, N}); ++s) {

for (int t = 0; t < min({(k) + 1, N}); ++t) {

int kp = k;
int lp = s;
int ip = t;
E[i][j][k][l][s][t] += E[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

int lp = i;
for (int j = max({i, 0}); j < N; ++j) {

for (int l = max({j, 0}); l < N; ++l) {

int tp = j;
int sp = l;
for (int k = 0; k < N; ++k) {

for (int s = max({k, 0}); s < min({(i) + 1, N}); ++s) {

for (int t = 0; t < min({(k) + 1, N}); ++t) {

int kp = k;
int ip = s;
int jp = t;
E[i][j][k][l][s][t] += E[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

int jp = i;
for (int j = 0; j < N; ++j) {

for (int l = max({i, 0}); l < min({(j) + 1, N}); ++l) {

int tp = j;
int sp = l;
for (int k = 0; k < N; ++k) {

for (int s = max({k, 0}); s < min({(i) + 1, N}); ++s) {

for (int t = 0; t < min({(k) + 1, N}); ++t) {

int kp = k;
int ip = s;
int lp = t;
E[i][j][k][l][s][t] += E[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

int sp = i;
for (int j = max({i, 0}); j < N; ++j) {

for (int k = 0; k < min({(i) + 1, N}); ++k) {

for (int l = max({j, 0}); l < N; ++l) {

int tp = j;
for (int t = 0; t < min({(k) + 1, N}); ++t) {

int kp = k;
for (int s = max({l, 0}); s < N; ++s) {

int ip = l;
int lp = t;
int jp = s;
E[i][j][k][l][s][t] += E[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

int lp = i;
for (int j = max({i, 0}); j < N; ++j) {

for (int k = 0; k < min({(i) + 1, N}); ++k) {

int tp = j;
for (int t = 0; t < min({(k) + 1, N}); ++t) {

int kp = k;
int sp = t;
for (int l = 0; l < N; ++l) {

for (int s = max({j, 0}); s < min({(l) + 1, N}); ++s) {

int ip = l;
int jp = s;
E[i][j][k][l][s][t] += E[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

int sp = i;
for (int k = 0; k < min({(i) + 1, N}); ++k) {

for (int t = 0; t < min({(k) + 1, N}); ++t) {

int kp = k;
int jp = t;
for (int j = 0; j < N; ++j) {

for (int s = max({j, 0}); s < N; ++s) {

for (int l = max({i, 0}); l < min({(j) + 1, N}); ++l) {

int tp = j;
int lp = s;
int ip = l;
E[i][j][k][l][s][t] += E[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int l = max({i, 0}); l < N; ++l) {

int jp = i;
for (int k = 0; k < min({(i) + 1, N}); ++k) {

int ip = l;
for (int t = 0; t < min({(k) + 1, N}); ++t) {

int kp = k;
int sp = t;
for (int j = 0; j < N; ++j) {

for (int s = max({l, 0}); s < min({(j) + 1, N}); ++s) {

int tp = j;
int lp = s;
E[i][j][k][l][s][t] += E[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

int lp = i;
for (int k = 0; k < min({(i) + 1, N}); ++k) {

for (int t = 0; t < min({(k) + 1, N}); ++t) {

int kp = k;
int jp = t;
for (int j = 0; j < N; ++j) {

for (int s = max({i, 0}); s < min({(j) + 1, N}); ++s) {

for (int l = max({j, 0}); l < N; ++l) {

int tp = j;
int sp = s;
int ip = l;
E[i][j][k][l][s][t] += E[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

int jp = i;
for (int k = 0; k < min({(i) + 1, N}); ++k) {

for (int t = 0; t < min({(k) + 1, N}); ++t) {

int kp = k;
int lp = t;
for (int j = 0; j < N; ++j) {

for (int l = 0; l < min({(j) + 1, N}); ++l) {

int tp = j;
for (int s = max({i, 0}); s < min({(l) + 1, N}); ++s) {

int ip = l;
int sp = s;
E[i][j][k][l][s][t] += E[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

int ip = i;
for (int j = 0; j < N; ++j) {

for (int l = 0; l < min({(j) + 1, N}); ++l) {

for (int k = max({j, 0}); k < N; ++k) {

int tp = j;
for (int t = 0; t < min({(l) + 1, N}); ++t) {

int jp = l;
for (int s = max({k, 0}); s < min({(i) + 1, N}); ++s) {

int lp = k;
int sp = t;
int kp = s;
E[i][j][k][l][s][t] += E[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int s = max({i, 0}); s < N; ++s) {

int sp = i;
int kp = s;
for (int j = 0; j < N; ++j) {

for (int l = 0; l < min({(j) + 1, N}); ++l) {

for (int k = max({j, 0}); k < min({(i) + 1, N}); ++k) {

int tp = j;
for (int t = 0; t < min({(l) + 1, N}); ++t) {

int jp = l;
int lp = k;
int ip = t;
E[i][j][k][l][s][t] += E[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

int ip = i;
for (int k = 0; k < min({(i) + 1, N}); ++k) {

int lp = k;
for (int j = 0; j < N; ++j) {

for (int s = max({j, 0}); s < min({(k) + 1, N}); ++s) {

for (int l = 0; l < min({(j) + 1, N}); ++l) {

int tp = j;
int sp = s;
for (int t = 0; t < min({(l) + 1, N}); ++t) {

int jp = l;
int kp = t;
E[i][j][k][l][s][t] += E[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

int kp = i;
for (int k = max({i, 0}); k < N; ++k) {

int lp = k;
for (int j = 0; j < N; ++j) {

for (int s = max({j, 0}); s < min({(i) + 1, N}); ++s) {

for (int l = 0; l < min({(j) + 1, N}); ++l) {

int tp = j;
int sp = s;
for (int t = 0; t < min({(l) + 1, N}); ++t) {

int jp = l;
int ip = t;
E[i][j][k][l][s][t] += E[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

int sp = i;
for (int j = 0; j < min({(i) + 1, N}); ++j) {

for (int k = max({i, 0}); k < N; ++k) {

for (int l = 0; l < min({(j) + 1, N}); ++l) {

int tp = j;
for (int s = max({k, 0}); s < N; ++s) {

int lp = k;
for (int t = 0; t < min({(l) + 1, N}); ++t) {

int jp = l;
int ip = s;
int kp = t;
E[i][j][k][l][s][t] += E[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

int kp = i;
for (int j = 0; j < min({(i) + 1, N}); ++j) {

for (int l = 0; l < min({(j) + 1, N}); ++l) {

int tp = j;
for (int t = 0; t < min({(l) + 1, N}); ++t) {

int jp = l;
int sp = t;
for (int k = 0; k < N; ++k) {

for (int s = max({i, 0}); s < min({(k) + 1, N}); ++s) {

int lp = k;
int ip = s;
E[i][j][k][l][s][t] += E[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

int ip = i;
for (int j = 0; j < N; ++j) {

for (int s = max({j, 0}); s < min({(i) + 1, N}); ++s) {

for (int k = 0; k < min({(j) + 1, N}); ++k) {

int tp = j;
int jp = s;
for (int l = 0; l < min({(k) + 1, N}); ++l) {

int lp = k;
for (int t = 0; t < min({(l) + 1, N}); ++t) {

int kp = l;
int sp = t;
E[i][j][k][l][s][t] += E[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int s = max({i, 0}); s < N; ++s) {

int sp = i;
for (int j = 0; j < min({(i) + 1, N}); ++j) {

int jp = s;
for (int k = 0; k < min({(j) + 1, N}); ++k) {

int tp = j;
for (int l = 0; l < min({(k) + 1, N}); ++l) {

int lp = k;
for (int t = 0; t < min({(l) + 1, N}); ++t) {

int kp = l;
int ip = t;
E[i][j][k][l][s][t] += E[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

int ip = i;
for (int j = 0; j < min({(i) + 1, N}); ++j) {

for (int k = 0; k < N; ++k) {

int tp = j;
for (int s = max({k, 0}); s < min({(j) + 1, N}); ++s) {

for (int l = 0; l < min({(k) + 1, N}); ++l) {

int lp = k;
int sp = s;
for (int t = 0; t < min({(l) + 1, N}); ++t) {

int kp = l;
int jp = t;
E[i][j][k][l][s][t] += E[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

int jp = i;
for (int j = max({i, 0}); j < N; ++j) {

for (int k = 0; k < N; ++k) {

int tp = j;
for (int s = max({k, 0}); s < min({(i) + 1, N}); ++s) {

for (int l = 0; l < min({(k) + 1, N}); ++l) {

int lp = k;
int sp = s;
for (int t = 0; t < min({(l) + 1, N}); ++t) {

int kp = l;
int ip = t;
E[i][j][k][l][s][t] += E[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

int sp = i;
for (int j = max({i, 0}); j < N; ++j) {

for (int k = 0; k < min({(i) + 1, N}); ++k) {

for (int s = max({j, 0}); s < N; ++s) {

int tp = j;
for (int l = 0; l < min({(k) + 1, N}); ++l) {

int lp = k;
int ip = s;
for (int t = 0; t < min({(l) + 1, N}); ++t) {

int kp = l;
int jp = t;
E[i][j][k][l][s][t] += E[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

int jp = i;
for (int k = 0; k < min({(i) + 1, N}); ++k) {

for (int l = 0; l < min({(k) + 1, N}); ++l) {

int lp = k;
for (int t = 0; t < min({(l) + 1, N}); ++t) {

int kp = l;
int sp = t;
for (int j = 0; j < N; ++j) {

for (int s = max({i, 0}); s < min({(j) + 1, N}); ++s) {

int tp = j;
int ip = s;
E[i][j][k][l][s][t] += E[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

int ip = i;
for (int j = 0; j < N; ++j) {

for (int k = max({j, 0}); k < min({(i) + 1, N}); ++k) {

int tp = j;
int lp = k;
for (int l = 0; l < N; ++l) {

for (int s = max({l, 0}); s < min({(j) + 1, N}); ++s) {

for (int t = 0; t < min({(l) + 1, N}); ++t) {

int sp = l;
int jp = s;
int kp = t;
E[i][j][k][l][s][t] += E[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

int kp = i;
for (int j = 0; j < min({(i) + 1, N}); ++j) {

for (int k = max({i, 0}); k < N; ++k) {

int tp = j;
int lp = k;
for (int l = 0; l < N; ++l) {

for (int s = max({l, 0}); s < min({(j) + 1, N}); ++s) {

for (int t = 0; t < min({(l) + 1, N}); ++t) {

int sp = l;
int jp = s;
int ip = t;
E[i][j][k][l][s][t] += E[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

int ip = i;
for (int j = 0; j < min({(i) + 1, N}); ++j) {

for (int k = 0; k < min({(j) + 1, N}); ++k) {

int tp = j;
int lp = k;
for (int l = 0; l < N; ++l) {

for (int s = max({l, 0}); s < min({(k) + 1, N}); ++s) {

for (int t = 0; t < min({(l) + 1, N}); ++t) {

int sp = l;
int kp = s;
int jp = t;
E[i][j][k][l][s][t] += E[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

int jp = i;
for (int j = max({i, 0}); j < N; ++j) {

for (int k = 0; k < min({(i) + 1, N}); ++k) {

int tp = j;
int lp = k;
for (int l = 0; l < N; ++l) {

for (int s = max({l, 0}); s < min({(k) + 1, N}); ++s) {

for (int t = 0; t < min({(l) + 1, N}); ++t) {

int sp = l;
int kp = s;
int ip = t;
E[i][j][k][l][s][t] += E[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

int kp = i;
for (int j = max({i, 0}); j < N; ++j) {

for (int k = max({j, 0}); k < N; ++k) {

int tp = j;
int lp = k;
for (int l = 0; l < N; ++l) {

for (int s = max({l, 0}); s < min({(i) + 1, N}); ++s) {

for (int t = 0; t < min({(l) + 1, N}); ++t) {

int sp = l;
int ip = s;
int jp = t;
E[i][j][k][l][s][t] += E[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

int jp = i;
for (int j = 0; j < N; ++j) {

for (int k = max({i, 0}); k < min({(j) + 1, N}); ++k) {

int tp = j;
int lp = k;
for (int l = 0; l < N; ++l) {

for (int s = max({l, 0}); s < min({(i) + 1, N}); ++s) {

for (int t = 0; t < min({(l) + 1, N}); ++t) {

int sp = l;
int ip = s;
int kp = t;
E[i][j][k][l][s][t] += E[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int l = 0; l < min({(i) + 1, N}); ++l) {

int sp = i;
for (int j = max({i, 0}); j < N; ++j) {

for (int t = 0; t < min({(l) + 1, N}); ++t) {

int ip = l;
for (int k = max({j, 0}); k < N; ++k) {

int tp = j;
int kp = t;
for (int s = max({k, 0}); s < N; ++s) {

int lp = k;
int jp = s;
E[i][j][k][l][s][t] += E[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int l = 0; l < min({(i) + 1, N}); ++l) {

int kp = i;
for (int j = max({i, 0}); j < N; ++j) {

for (int t = 0; t < min({(l) + 1, N}); ++t) {

int ip = l;
int tp = j;
int sp = t;
for (int k = 0; k < N; ++k) {

for (int s = max({j, 0}); s < min({(k) + 1, N}); ++s) {

int lp = k;
int jp = s;
E[i][j][k][l][s][t] += E[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int l = 0; l < min({(i) + 1, N}); ++l) {

int sp = i;
for (int t = 0; t < min({(l) + 1, N}); ++t) {

int ip = l;
int jp = t;
for (int j = 0; j < N; ++j) {

for (int s = max({j, 0}); s < N; ++s) {

for (int k = max({i, 0}); k < min({(j) + 1, N}); ++k) {

int tp = j;
int kp = s;
int lp = k;
E[i][j][k][l][s][t] += E[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int l = 0; l < min({(i) + 1, N}); ++l) {

int jp = i;
for (int k = max({i, 0}); k < N; ++k) {

for (int t = 0; t < min({(l) + 1, N}); ++t) {

int ip = l;
int lp = k;
int sp = t;
for (int j = 0; j < N; ++j) {

for (int s = max({k, 0}); s < min({(j) + 1, N}); ++s) {

int tp = j;
int kp = s;
E[i][j][k][l][s][t] += E[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int l = 0; l < min({(i) + 1, N}); ++l) {

int kp = i;
for (int t = 0; t < min({(l) + 1, N}); ++t) {

int ip = l;
int jp = t;
for (int j = 0; j < N; ++j) {

for (int s = max({i, 0}); s < min({(j) + 1, N}); ++s) {

for (int k = max({j, 0}); k < N; ++k) {

int tp = j;
int sp = s;
int lp = k;
E[i][j][k][l][s][t] += E[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int l = 0; l < min({(i) + 1, N}); ++l) {

int jp = i;
for (int t = 0; t < min({(l) + 1, N}); ++t) {

int ip = l;
int kp = t;
for (int j = 0; j < N; ++j) {

for (int k = 0; k < min({(j) + 1, N}); ++k) {

int tp = j;
for (int s = max({i, 0}); s < min({(k) + 1, N}); ++s) {

int lp = k;
int sp = s;
E[i][j][k][l][s][t] += E[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

int ip = i;
for (int j = 0; j < N; ++j) {

for (int s = 0; s < min({(j) + 1, N}); ++s) {

for (int k = max({j, 0}); k < N; ++k) {

int tp = j;
for (int t = 0; t < min({(s) + 1, N}); ++t) {

int kp = s;
for (int l = max({k, 0}); l < min({(i) + 1, N}); ++l) {

int sp = k;
int lp = t;
int jp = l;
E[i][j][k][l][s][t] += E[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int l = max({i, 0}); l < N; ++l) {

int lp = i;
int jp = l;
for (int j = 0; j < N; ++j) {

for (int s = 0; s < min({(j) + 1, N}); ++s) {

for (int k = max({j, 0}); k < min({(i) + 1, N}); ++k) {

int tp = j;
for (int t = 0; t < min({(s) + 1, N}); ++t) {

int kp = s;
int sp = k;
int ip = t;
E[i][j][k][l][s][t] += E[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

int ip = i;
for (int k = 0; k < min({(i) + 1, N}); ++k) {

int sp = k;
for (int j = 0; j < N; ++j) {

for (int s = 0; s < min({(j) + 1, N}); ++s) {

for (int l = max({j, 0}); l < min({(k) + 1, N}); ++l) {

int tp = j;
for (int t = 0; t < min({(s) + 1, N}); ++t) {

int lp = s;
int jp = l;
int kp = t;
E[i][j][k][l][s][t] += E[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

int kp = i;
for (int k = max({i, 0}); k < N; ++k) {

int sp = k;
for (int j = 0; j < N; ++j) {

for (int s = 0; s < min({(j) + 1, N}); ++s) {

for (int l = max({j, 0}); l < min({(i) + 1, N}); ++l) {

int tp = j;
for (int t = 0; t < min({(s) + 1, N}); ++t) {

int lp = s;
int jp = l;
int ip = t;
E[i][j][k][l][s][t] += E[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

int lp = i;
for (int j = 0; j < min({(i) + 1, N}); ++j) {

for (int k = max({i, 0}); k < N; ++k) {

for (int s = 0; s < min({(j) + 1, N}); ++s) {

int tp = j;
for (int l = max({k, 0}); l < N; ++l) {

int sp = k;
for (int t = 0; t < min({(s) + 1, N}); ++t) {

int ip = s;
int jp = l;
int kp = t;
E[i][j][k][l][s][t] += E[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

int kp = i;
for (int j = 0; j < min({(i) + 1, N}); ++j) {

for (int s = 0; s < min({(j) + 1, N}); ++s) {

int tp = j;
for (int t = 0; t < min({(s) + 1, N}); ++t) {

int ip = s;
int lp = t;
for (int k = 0; k < N; ++k) {

for (int l = max({i, 0}); l < min({(k) + 1, N}); ++l) {

int sp = k;
int jp = l;
E[i][j][k][l][s][t] += E[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

int ip = i;
for (int j = 0; j < N; ++j) {

for (int l = max({j, 0}); l < min({(i) + 1, N}); ++l) {

for (int k = 0; k < min({(j) + 1, N}); ++k) {

int tp = j;
int kp = l;
for (int s = 0; s < min({(k) + 1, N}); ++s) {

int sp = k;
for (int t = 0; t < min({(s) + 1, N}); ++t) {

int jp = s;
int lp = t;
E[i][j][k][l][s][t] += E[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int l = max({i, 0}); l < N; ++l) {

int lp = i;
for (int j = 0; j < min({(i) + 1, N}); ++j) {

int kp = l;
for (int k = 0; k < min({(j) + 1, N}); ++k) {

int tp = j;
for (int s = 0; s < min({(k) + 1, N}); ++s) {

int sp = k;
for (int t = 0; t < min({(s) + 1, N}); ++t) {

int jp = s;
int ip = t;
E[i][j][k][l][s][t] += E[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

int ip = i;
for (int j = 0; j < min({(i) + 1, N}); ++j) {

for (int k = 0; k < N; ++k) {

int tp = j;
for (int s = 0; s < min({(k) + 1, N}); ++s) {

for (int l = max({k, 0}); l < min({(j) + 1, N}); ++l) {

int sp = k;
for (int t = 0; t < min({(s) + 1, N}); ++t) {

int lp = s;
int kp = l;
int jp = t;
E[i][j][k][l][s][t] += E[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

int jp = i;
for (int j = max({i, 0}); j < N; ++j) {

for (int k = 0; k < N; ++k) {

int tp = j;
for (int s = 0; s < min({(k) + 1, N}); ++s) {

for (int l = max({k, 0}); l < min({(i) + 1, N}); ++l) {

int sp = k;
for (int t = 0; t < min({(s) + 1, N}); ++t) {

int lp = s;
int kp = l;
int ip = t;
E[i][j][k][l][s][t] += E[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

int lp = i;
for (int j = max({i, 0}); j < N; ++j) {

for (int k = 0; k < min({(i) + 1, N}); ++k) {

for (int l = max({j, 0}); l < N; ++l) {

int tp = j;
for (int s = 0; s < min({(k) + 1, N}); ++s) {

int sp = k;
int kp = l;
for (int t = 0; t < min({(s) + 1, N}); ++t) {

int ip = s;
int jp = t;
E[i][j][k][l][s][t] += E[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

int jp = i;
for (int k = 0; k < min({(i) + 1, N}); ++k) {

for (int s = 0; s < min({(k) + 1, N}); ++s) {

int sp = k;
for (int t = 0; t < min({(s) + 1, N}); ++t) {

int ip = s;
int lp = t;
for (int j = 0; j < N; ++j) {

for (int l = max({i, 0}); l < min({(j) + 1, N}); ++l) {

int tp = j;
int kp = l;
E[i][j][k][l][s][t] += E[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

int ip = i;
for (int j = 0; j < N; ++j) {

for (int l = 0; l < min({(j) + 1, N}); ++l) {

for (int k = max({j, 0}); k < min({(i) + 1, N}); ++k) {

int tp = j;
for (int s = 0; s < min({(l) + 1, N}); ++s) {

int lp = l;
int sp = k;
for (int t = 0; t < min({(s) + 1, N}); ++t) {

int jp = s;
int kp = t;
E[i][j][k][l][s][t] += E[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

int kp = i;
for (int j = 0; j < min({(i) + 1, N}); ++j) {

for (int k = max({i, 0}); k < N; ++k) {

for (int l = 0; l < min({(j) + 1, N}); ++l) {

int tp = j;
int sp = k;
for (int s = 0; s < min({(l) + 1, N}); ++s) {

int lp = l;
for (int t = 0; t < min({(s) + 1, N}); ++t) {

int jp = s;
int ip = t;
E[i][j][k][l][s][t] += E[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

int ip = i;
for (int j = 0; j < min({(i) + 1, N}); ++j) {

for (int k = 0; k < min({(j) + 1, N}); ++k) {

int tp = j;
for (int l = 0; l < min({(k) + 1, N}); ++l) {

int sp = k;
for (int s = 0; s < min({(l) + 1, N}); ++s) {

int lp = l;
for (int t = 0; t < min({(s) + 1, N}); ++t) {

int kp = s;
int jp = t;
E[i][j][k][l][s][t] += E[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

int jp = i;
for (int j = max({i, 0}); j < N; ++j) {

for (int k = 0; k < min({(i) + 1, N}); ++k) {

int tp = j;
for (int l = 0; l < min({(k) + 1, N}); ++l) {

int sp = k;
for (int s = 0; s < min({(l) + 1, N}); ++s) {

int lp = l;
for (int t = 0; t < min({(s) + 1, N}); ++t) {

int kp = s;
int ip = t;
E[i][j][k][l][s][t] += E[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int l = 0; l < min({(i) + 1, N}); ++l) {

int kp = i;
for (int j = max({i, 0}); j < N; ++j) {

for (int s = 0; s < min({(l) + 1, N}); ++s) {

int lp = l;
for (int k = max({j, 0}); k < N; ++k) {

int tp = j;
for (int t = 0; t < min({(s) + 1, N}); ++t) {

int ip = s;
int sp = k;
int jp = t;
E[i][j][k][l][s][t] += E[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int l = 0; l < min({(i) + 1, N}); ++l) {

int jp = i;
for (int s = 0; s < min({(l) + 1, N}); ++s) {

int lp = l;
for (int t = 0; t < min({(s) + 1, N}); ++t) {

int ip = s;
int kp = t;
for (int j = 0; j < N; ++j) {

for (int k = max({i, 0}); k < min({(j) + 1, N}); ++k) {

int tp = j;
int sp = k;
E[i][j][k][l][s][t] += E[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int s = 0; s < min({(i) + 1, N}); ++s) {

int lp = i;
for (int j = max({i, 0}); j < N; ++j) {

for (int t = 0; t < min({(s) + 1, N}); ++t) {

int jp = s;
for (int k = max({j, 0}); k < N; ++k) {

int tp = j;
int kp = t;
for (int l = max({k, 0}); l < N; ++l) {

int sp = k;
int ip = l;
E[i][j][k][l][s][t] += E[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int s = 0; s < min({(i) + 1, N}); ++s) {

int kp = i;
for (int j = max({i, 0}); j < N; ++j) {

for (int t = 0; t < min({(s) + 1, N}); ++t) {

int jp = s;
int tp = j;
int lp = t;
for (int k = 0; k < N; ++k) {

for (int l = max({j, 0}); l < min({(k) + 1, N}); ++l) {

int sp = k;
int ip = l;
E[i][j][k][l][s][t] += E[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int s = 0; s < min({(i) + 1, N}); ++s) {

int lp = i;
for (int t = 0; t < min({(s) + 1, N}); ++t) {

int kp = s;
int jp = t;
for (int j = 0; j < N; ++j) {

for (int l = max({j, 0}); l < N; ++l) {

for (int k = max({i, 0}); k < min({(j) + 1, N}); ++k) {

int tp = j;
int ip = l;
int sp = k;
E[i][j][k][l][s][t] += E[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int s = 0; s < min({(i) + 1, N}); ++s) {

int jp = i;
for (int k = max({i, 0}); k < N; ++k) {

for (int t = 0; t < min({(s) + 1, N}); ++t) {

int kp = s;
int sp = k;
int lp = t;
for (int j = 0; j < N; ++j) {

for (int l = max({k, 0}); l < min({(j) + 1, N}); ++l) {

int tp = j;
int ip = l;
E[i][j][k][l][s][t] += E[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int s = 0; s < min({(i) + 1, N}); ++s) {

int kp = i;
for (int t = 0; t < min({(s) + 1, N}); ++t) {

int lp = s;
int jp = t;
for (int j = 0; j < N; ++j) {

for (int l = max({i, 0}); l < min({(j) + 1, N}); ++l) {

for (int k = max({j, 0}); k < N; ++k) {

int tp = j;
int ip = l;
int sp = k;
E[i][j][k][l][s][t] += E[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int s = 0; s < min({(i) + 1, N}); ++s) {

int jp = i;
for (int t = 0; t < min({(s) + 1, N}); ++t) {

int lp = s;
int kp = t;
for (int j = 0; j < N; ++j) {

for (int k = 0; k < min({(j) + 1, N}); ++k) {

int tp = j;
for (int l = max({i, 0}); l < min({(k) + 1, N}); ++l) {

int sp = k;
int ip = l;
E[i][j][k][l][s][t] += E[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int t = 0; t < min({(i) + 1, N}); ++t) {

int sp = i;
for (int j = max({i, 0}); j < N; ++j) {

int lp = t;
for (int k = max({j, 0}); k < N; ++k) {

int tp = j;
for (int l = max({k, 0}); l < N; ++l) {

int ip = k;
for (int s = max({l, 0}); s < N; ++s) {

int jp = l;
int kp = s;
E[i][j][k][l][s][t] += E[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int t = 0; t < min({(i) + 1, N}); ++t) {

int lp = i;
for (int j = max({i, 0}); j < N; ++j) {

int sp = t;
for (int k = max({j, 0}); k < N; ++k) {

int tp = j;
int ip = k;
for (int l = 0; l < N; ++l) {

for (int s = max({k, 0}); s < min({(l) + 1, N}); ++s) {

int jp = l;
int kp = s;
E[i][j][k][l][s][t] += E[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int t = 0; t < min({(i) + 1, N}); ++t) {

int sp = i;
for (int j = max({i, 0}); j < N; ++j) {

int kp = t;
int tp = j;
for (int k = 0; k < N; ++k) {

for (int s = max({k, 0}); s < N; ++s) {

for (int l = max({j, 0}); l < min({(k) + 1, N}); ++l) {

int ip = k;
int lp = s;
int jp = l;
E[i][j][k][l][s][t] += E[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int t = 0; t < min({(i) + 1, N}); ++t) {

int kp = i;
for (int j = max({i, 0}); j < N; ++j) {

int sp = t;
for (int l = max({j, 0}); l < N; ++l) {

int tp = j;
int jp = l;
for (int k = 0; k < N; ++k) {

for (int s = max({l, 0}); s < min({(k) + 1, N}); ++s) {

int ip = k;
int lp = s;
E[i][j][k][l][s][t] += E[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int t = 0; t < min({(i) + 1, N}); ++t) {

int lp = i;
for (int j = max({i, 0}); j < N; ++j) {

int kp = t;
int tp = j;
for (int k = 0; k < N; ++k) {

for (int s = max({j, 0}); s < min({(k) + 1, N}); ++s) {

for (int l = max({k, 0}); l < N; ++l) {

int ip = k;
int sp = s;
int jp = l;
E[i][j][k][l][s][t] += E[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int t = 0; t < min({(i) + 1, N}); ++t) {

int kp = i;
for (int j = max({i, 0}); j < N; ++j) {

int lp = t;
int tp = j;
for (int k = 0; k < N; ++k) {

for (int l = 0; l < min({(k) + 1, N}); ++l) {

int ip = k;
for (int s = max({j, 0}); s < min({(l) + 1, N}); ++s) {

int jp = l;
int sp = s;
E[i][j][k][l][s][t] += E[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int t = 0; t < min({(i) + 1, N}); ++t) {

int sp = i;
int lp = t;
for (int j = 0; j < N; ++j) {

for (int l = max({j, 0}); l < N; ++l) {

for (int k = max({i, 0}); k < min({(j) + 1, N}); ++k) {

int tp = j;
for (int s = max({l, 0}); s < N; ++s) {

int kp = l;
int ip = k;
int jp = s;
E[i][j][k][l][s][t] += E[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int t = 0; t < min({(i) + 1, N}); ++t) {

int lp = i;
int sp = t;
for (int j = 0; j < N; ++j) {

for (int k = max({i, 0}); k < min({(j) + 1, N}); ++k) {

int tp = j;
int ip = k;
for (int l = 0; l < N; ++l) {

for (int s = max({j, 0}); s < min({(l) + 1, N}); ++s) {

int kp = l;
int jp = s;
E[i][j][k][l][s][t] += E[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int t = 0; t < min({(i) + 1, N}); ++t) {

int sp = i;
for (int k = max({i, 0}); k < N; ++k) {

int jp = t;
int ip = k;
for (int j = 0; j < N; ++j) {

for (int s = max({j, 0}); s < N; ++s) {

for (int l = max({k, 0}); l < min({(j) + 1, N}); ++l) {

int tp = j;
int lp = s;
int kp = l;
E[i][j][k][l][s][t] += E[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int t = 0; t < min({(i) + 1, N}); ++t) {

int jp = i;
for (int k = max({i, 0}); k < N; ++k) {

int sp = t;
for (int l = max({k, 0}); l < N; ++l) {

int ip = k;
int kp = l;
for (int j = 0; j < N; ++j) {

for (int s = max({l, 0}); s < min({(j) + 1, N}); ++s) {

int tp = j;
int lp = s;
E[i][j][k][l][s][t] += E[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int t = 0; t < min({(i) + 1, N}); ++t) {

int lp = i;
for (int k = max({i, 0}); k < N; ++k) {

int jp = t;
int ip = k;
for (int j = 0; j < N; ++j) {

for (int s = max({k, 0}); s < min({(j) + 1, N}); ++s) {

for (int l = max({j, 0}); l < N; ++l) {

int tp = j;
int sp = s;
int kp = l;
E[i][j][k][l][s][t] += E[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int t = 0; t < min({(i) + 1, N}); ++t) {

int jp = i;
for (int k = max({i, 0}); k < N; ++k) {

int lp = t;
int ip = k;
for (int j = 0; j < N; ++j) {

for (int l = 0; l < min({(j) + 1, N}); ++l) {

int tp = j;
for (int s = max({k, 0}); s < min({(l) + 1, N}); ++s) {

int kp = l;
int sp = s;
E[i][j][k][l][s][t] += E[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int t = 0; t < min({(i) + 1, N}); ++t) {

int sp = i;
int kp = t;
for (int j = 0; j < N; ++j) {

for (int l = max({i, 0}); l < min({(j) + 1, N}); ++l) {

for (int k = max({j, 0}); k < N; ++k) {

int tp = j;
int lp = l;
for (int s = max({k, 0}); s < N; ++s) {

int ip = k;
int jp = s;
E[i][j][k][l][s][t] += E[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int t = 0; t < min({(i) + 1, N}); ++t) {

int kp = i;
int sp = t;
for (int j = 0; j < N; ++j) {

for (int l = max({i, 0}); l < min({(j) + 1, N}); ++l) {

int tp = j;
int lp = l;
for (int k = 0; k < N; ++k) {

for (int s = max({j, 0}); s < min({(k) + 1, N}); ++s) {

int ip = k;
int jp = s;
E[i][j][k][l][s][t] += E[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int t = 0; t < min({(i) + 1, N}); ++t) {

int sp = i;
int jp = t;
for (int j = 0; j < N; ++j) {

for (int s = max({j, 0}); s < N; ++s) {

for (int k = 0; k < min({(j) + 1, N}); ++k) {

int tp = j;
int kp = s;
for (int l = max({i, 0}); l < min({(k) + 1, N}); ++l) {

int ip = k;
int lp = l;
E[i][j][k][l][s][t] += E[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int t = 0; t < min({(i) + 1, N}); ++t) {

int jp = i;
int sp = t;
for (int j = 0; j < N; ++j) {

for (int k = 0; k < N; ++k) {

int tp = j;
for (int s = max({k, 0}); s < min({(j) + 1, N}); ++s) {

for (int l = max({i, 0}); l < min({(k) + 1, N}); ++l) {

int ip = k;
int kp = s;
int lp = l;
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

int kp = i;
int jp = t;
int lp = l;
for (int j = 0; j < N; ++j) {

for (int s = max({l, 0}); s < min({(j) + 1, N}); ++s) {

for (int k = max({j, 0}); k < N; ++k) {

int tp = j;
int sp = s;
int ip = k;
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

int jp = i;
int kp = t;
int lp = l;
for (int j = 0; j < N; ++j) {

for (int k = 0; k < min({(j) + 1, N}); ++k) {

int tp = j;
for (int s = max({l, 0}); s < min({(k) + 1, N}); ++s) {

int ip = k;
int sp = s;
E[i][j][k][l][s][t] += E[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int t = 0; t < min({(i) + 1, N}); ++t) {

int lp = i;
int kp = t;
for (int j = 0; j < N; ++j) {

for (int s = max({i, 0}); s < min({(j) + 1, N}); ++s) {

for (int k = max({j, 0}); k < N; ++k) {

int tp = j;
int jp = s;
for (int l = max({k, 0}); l < N; ++l) {

int ip = k;
int sp = l;
E[i][j][k][l][s][t] += E[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int t = 0; t < min({(i) + 1, N}); ++t) {

int kp = i;
int lp = t;
for (int j = 0; j < N; ++j) {

for (int s = max({i, 0}); s < min({(j) + 1, N}); ++s) {

int tp = j;
int jp = s;
for (int k = 0; k < N; ++k) {

for (int l = max({j, 0}); l < min({(k) + 1, N}); ++l) {

int ip = k;
int sp = l;
E[i][j][k][l][s][t] += E[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int t = 0; t < min({(i) + 1, N}); ++t) {

int lp = i;
int jp = t;
for (int j = 0; j < N; ++j) {

for (int l = max({j, 0}); l < N; ++l) {

for (int k = 0; k < min({(j) + 1, N}); ++k) {

int tp = j;
int sp = l;
for (int s = max({i, 0}); s < min({(k) + 1, N}); ++s) {

int ip = k;
int kp = s;
E[i][j][k][l][s][t] += E[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int t = 0; t < min({(i) + 1, N}); ++t) {

int jp = i;
int lp = t;
for (int j = 0; j < N; ++j) {

for (int k = 0; k < N; ++k) {

int tp = j;
for (int s = max({i, 0}); s < min({(k) + 1, N}); ++s) {

for (int l = max({k, 0}); l < min({(j) + 1, N}); ++l) {

int ip = k;
int kp = s;
int sp = l;
E[i][j][k][l][s][t] += E[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int t = 0; t < min({(i) + 1, N}); ++t) {

int kp = i;
int jp = t;
for (int j = 0; j < N; ++j) {

for (int l = 0; l < min({(j) + 1, N}); ++l) {

for (int k = max({j, 0}); k < N; ++k) {

int tp = j;
for (int s = max({i, 0}); s < min({(l) + 1, N}); ++s) {

int sp = l;
int ip = k;
int lp = s;
E[i][j][k][l][s][t] += E[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int t = 0; t < min({(i) + 1, N}); ++t) {

int jp = i;
int kp = t;
for (int j = 0; j < N; ++j) {

for (int k = 0; k < min({(j) + 1, N}); ++k) {

int tp = j;
for (int l = 0; l < min({(k) + 1, N}); ++l) {

int ip = k;
for (int s = max({i, 0}); s < min({(l) + 1, N}); ++s) {

int sp = l;
int lp = s;
E[i][j][k][l][s][t] += E[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int j = max({i, 0}); j < N; ++j) {

int tp = i;
int ip = j;
for (int k = max({j, 0}); k < N; ++k) {

for (int l = max({k, 0}); l < N; ++l) {

int jp = k;
for (int s = max({l, 0}); s < N; ++s) {

int kp = l;
for (int t = max({s, 0}); t < N; ++t) {

int lp = s;
int sp = t;
E[i][j][k][l][s][t] += E[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

int sp = i;
for (int j = max({i, 0}); j < N; ++j) {

int ip = j;
for (int k = max({j, 0}); k < N; ++k) {

for (int l = max({k, 0}); l < N; ++l) {

int jp = k;
int kp = l;
for (int s = 0; s < N; ++s) {

for (int t = max({l, 0}); t < min({(s) + 1, N}); ++t) {

int lp = s;
int tp = t;
E[i][j][k][l][s][t] += E[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int j = max({i, 0}); j < N; ++j) {

int tp = i;
int ip = j;
for (int k = max({j, 0}); k < N; ++k) {

for (int l = 0; l < N; ++l) {

int jp = k;
for (int s = max({k, 0}); s < min({(l) + 1, N}); ++s) {

for (int t = max({l, 0}); t < N; ++t) {

int kp = l;
int sp = s;
int lp = t;
E[i][j][k][l][s][t] += E[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

int lp = i;
for (int j = max({i, 0}); j < N; ++j) {

int ip = j;
for (int k = max({j, 0}); k < N; ++k) {

for (int s = max({k, 0}); s < N; ++s) {

int jp = k;
int sp = s;
for (int l = 0; l < N; ++l) {

for (int t = max({s, 0}); t < min({(l) + 1, N}); ++t) {

int kp = l;
int tp = t;
E[i][j][k][l][s][t] += E[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

int sp = i;
for (int j = max({i, 0}); j < N; ++j) {

int ip = j;
for (int k = max({j, 0}); k < N; ++k) {

for (int l = 0; l < N; ++l) {

int jp = k;
for (int s = max({l, 0}); s < N; ++s) {

for (int t = max({k, 0}); t < min({(l) + 1, N}); ++t) {

int kp = l;
int tp = s;
int lp = t;
E[i][j][k][l][s][t] += E[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

int lp = i;
for (int j = max({i, 0}); j < N; ++j) {

int ip = j;
for (int k = max({j, 0}); k < N; ++k) {

for (int l = 0; l < N; ++l) {

int jp = k;
for (int s = 0; s < min({(l) + 1, N}); ++s) {

int kp = l;
for (int t = max({k, 0}); t < min({(s) + 1, N}); ++t) {

int tp = s;
int sp = t;
E[i][j][k][l][s][t] += E[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int j = max({i, 0}); j < N; ++j) {

int tp = i;
int ip = j;
for (int k = 0; k < N; ++k) {

for (int s = max({k, 0}); s < N; ++s) {

for (int l = max({j, 0}); l < min({(k) + 1, N}); ++l) {

int jp = k;
for (int t = max({s, 0}); t < N; ++t) {

int kp = s;
int lp = l;
int sp = t;
E[i][j][k][l][s][t] += E[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

int sp = i;
for (int j = max({i, 0}); j < N; ++j) {

int ip = j;
for (int k = 0; k < N; ++k) {

for (int l = max({j, 0}); l < min({(k) + 1, N}); ++l) {

int jp = k;
int lp = l;
for (int s = 0; s < N; ++s) {

for (int t = max({k, 0}); t < min({(s) + 1, N}); ++t) {

int kp = s;
int tp = t;
E[i][j][k][l][s][t] += E[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int j = max({i, 0}); j < N; ++j) {

int tp = i;
for (int l = max({j, 0}); l < N; ++l) {

int ip = j;
int lp = l;
for (int k = 0; k < N; ++k) {

for (int s = max({l, 0}); s < min({(k) + 1, N}); ++s) {

for (int t = max({k, 0}); t < N; ++t) {

int jp = k;
int sp = s;
int kp = t;
E[i][j][k][l][s][t] += E[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

int kp = i;
for (int j = max({i, 0}); j < N; ++j) {

for (int l = max({j, 0}); l < N; ++l) {

int ip = j;
for (int s = max({l, 0}); s < N; ++s) {

int lp = l;
int sp = s;
for (int k = 0; k < N; ++k) {

for (int t = max({s, 0}); t < min({(k) + 1, N}); ++t) {

int jp = k;
int tp = t;
E[i][j][k][l][s][t] += E[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

int sp = i;
for (int j = max({i, 0}); j < N; ++j) {

for (int l = max({j, 0}); l < N; ++l) {

int ip = j;
int lp = l;
for (int k = 0; k < N; ++k) {

for (int s = max({k, 0}); s < N; ++s) {

for (int t = max({l, 0}); t < min({(k) + 1, N}); ++t) {

int jp = k;
int tp = s;
int kp = t;
E[i][j][k][l][s][t] += E[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

int kp = i;
for (int j = max({i, 0}); j < N; ++j) {

for (int l = max({j, 0}); l < N; ++l) {

int ip = j;
int lp = l;
for (int k = 0; k < N; ++k) {

for (int s = 0; s < min({(k) + 1, N}); ++s) {

int jp = k;
for (int t = max({l, 0}); t < min({(s) + 1, N}); ++t) {

int tp = s;
int sp = t;
E[i][j][k][l][s][t] += E[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int j = max({i, 0}); j < N; ++j) {

int tp = i;
int ip = j;
for (int k = 0; k < N; ++k) {

for (int s = max({j, 0}); s < min({(k) + 1, N}); ++s) {

for (int l = max({k, 0}); l < N; ++l) {

int jp = k;
int kp = s;
for (int t = max({l, 0}); t < N; ++t) {

int sp = l;
int lp = t;
E[i][j][k][l][s][t] += E[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

int lp = i;
for (int j = max({i, 0}); j < N; ++j) {

int ip = j;
for (int k = 0; k < N; ++k) {

for (int s = max({j, 0}); s < min({(k) + 1, N}); ++s) {

int jp = k;
int kp = s;
for (int l = 0; l < N; ++l) {

for (int t = max({k, 0}); t < min({(l) + 1, N}); ++t) {

int sp = l;
int tp = t;
E[i][j][k][l][s][t] += E[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int j = max({i, 0}); j < N; ++j) {

int tp = i;
int ip = j;
for (int k = 0; k < N; ++k) {

for (int t = max({k, 0}); t < N; ++t) {

for (int l = 0; l < min({(k) + 1, N}); ++l) {

int jp = k;
int kp = t;
for (int s = max({j, 0}); s < min({(l) + 1, N}); ++s) {

int sp = l;
int lp = s;
E[i][j][k][l][s][t] += E[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

int kp = i;
for (int j = max({i, 0}); j < N; ++j) {

int ip = j;
for (int k = 0; k < N; ++k) {

for (int l = 0; l < N; ++l) {

int jp = k;
for (int s = max({j, 0}); s < min({(l) + 1, N}); ++s) {

for (int t = max({l, 0}); t < min({(k) + 1, N}); ++t) {

int sp = l;
int lp = s;
int tp = t;
E[i][j][k][l][s][t] += E[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

int lp = i;
for (int j = max({i, 0}); j < N; ++j) {

for (int s = max({j, 0}); s < N; ++s) {

int ip = j;
int tp = s;
for (int k = 0; k < N; ++k) {

for (int t = max({s, 0}); t < min({(k) + 1, N}); ++t) {

for (int l = max({k, 0}); l < N; ++l) {

int jp = k;
int kp = t;
int sp = l;
E[i][j][k][l][s][t] += E[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

int kp = i;
for (int j = max({i, 0}); j < N; ++j) {

for (int s = max({j, 0}); s < N; ++s) {

int ip = j;
int tp = s;
for (int k = 0; k < N; ++k) {

for (int l = 0; l < min({(k) + 1, N}); ++l) {

int jp = k;
for (int t = max({s, 0}); t < min({(l) + 1, N}); ++t) {

int sp = l;
int lp = t;
E[i][j][k][l][s][t] += E[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

int sp = i;
for (int j = max({i, 0}); j < N; ++j) {

int ip = j;
for (int k = 0; k < N; ++k) {

for (int t = max({j, 0}); t < min({(k) + 1, N}); ++t) {

for (int l = max({k, 0}); l < N; ++l) {

int jp = k;
int lp = t;
for (int s = max({l, 0}); s < N; ++s) {

int tp = l;
int kp = s;
E[i][j][k][l][s][t] += E[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

int lp = i;
for (int j = max({i, 0}); j < N; ++j) {

int ip = j;
for (int k = 0; k < N; ++k) {

for (int t = max({j, 0}); t < min({(k) + 1, N}); ++t) {

int jp = k;
int sp = t;
for (int l = 0; l < N; ++l) {

for (int s = max({k, 0}); s < min({(l) + 1, N}); ++s) {

int tp = l;
int kp = s;
E[i][j][k][l][s][t] += E[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

int sp = i;
for (int j = max({i, 0}); j < N; ++j) {

int ip = j;
for (int k = 0; k < N; ++k) {

for (int s = max({k, 0}); s < N; ++s) {

for (int l = 0; l < min({(k) + 1, N}); ++l) {

int jp = k;
int lp = s;
for (int t = max({j, 0}); t < min({(l) + 1, N}); ++t) {

int tp = l;
int kp = t;
E[i][j][k][l][s][t] += E[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

int kp = i;
for (int j = max({i, 0}); j < N; ++j) {

int ip = j;
for (int k = 0; k < N; ++k) {

for (int l = 0; l < N; ++l) {

int jp = k;
for (int s = max({l, 0}); s < min({(k) + 1, N}); ++s) {

for (int t = max({j, 0}); t < min({(l) + 1, N}); ++t) {

int tp = l;
int lp = s;
int sp = t;
E[i][j][k][l][s][t] += E[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

int lp = i;
for (int j = max({i, 0}); j < N; ++j) {

int ip = j;
for (int k = 0; k < N; ++k) {

for (int s = 0; s < min({(k) + 1, N}); ++s) {

for (int l = max({k, 0}); l < N; ++l) {

int jp = k;
for (int t = max({j, 0}); t < min({(s) + 1, N}); ++t) {

int sp = s;
int tp = l;
int kp = t;
E[i][j][k][l][s][t] += E[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

int kp = i;
for (int j = max({i, 0}); j < N; ++j) {

int ip = j;
for (int k = 0; k < N; ++k) {

for (int l = 0; l < min({(k) + 1, N}); ++l) {

int jp = k;
for (int s = 0; s < min({(l) + 1, N}); ++s) {

int tp = l;
for (int t = max({j, 0}); t < min({(s) + 1, N}); ++t) {

int sp = s;
int lp = t;
E[i][j][k][l][s][t] += E[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int j = 0; j < N; ++j) {

int tp = i;
for (int l = max({j, 0}); l < N; ++l) {

int ip = j;
for (int k = max({i, 0}); k < min({(j) + 1, N}); ++k) {

for (int s = max({l, 0}); s < N; ++s) {

int jp = l;
int kp = k;
for (int t = max({s, 0}); t < N; ++t) {

int lp = s;
int sp = t;
E[i][j][k][l][s][t] += E[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

int sp = i;
for (int j = 0; j < N; ++j) {

for (int l = max({j, 0}); l < N; ++l) {

int ip = j;
for (int k = max({i, 0}); k < min({(j) + 1, N}); ++k) {

int jp = l;
int kp = k;
for (int s = 0; s < N; ++s) {

for (int t = max({l, 0}); t < min({(s) + 1, N}); ++t) {

int lp = s;
int tp = t;
E[i][j][k][l][s][t] += E[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int j = 0; j < N; ++j) {

int tp = i;
int ip = j;
for (int k = max({i, 0}); k < min({(j) + 1, N}); ++k) {

for (int l = 0; l < N; ++l) {

int kp = k;
for (int s = max({j, 0}); s < min({(l) + 1, N}); ++s) {

for (int t = max({l, 0}); t < N; ++t) {

int jp = l;
int sp = s;
int lp = t;
E[i][j][k][l][s][t] += E[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

int lp = i;
for (int j = 0; j < N; ++j) {

for (int s = max({j, 0}); s < N; ++s) {

int ip = j;
for (int k = max({i, 0}); k < min({(j) + 1, N}); ++k) {

int sp = s;
int kp = k;
for (int l = 0; l < N; ++l) {

for (int t = max({s, 0}); t < min({(l) + 1, N}); ++t) {

int jp = l;
int tp = t;
E[i][j][k][l][s][t] += E[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

int sp = i;
for (int j = 0; j < N; ++j) {

int ip = j;
for (int k = max({i, 0}); k < min({(j) + 1, N}); ++k) {

for (int l = 0; l < N; ++l) {

int kp = k;
for (int s = max({l, 0}); s < N; ++s) {

for (int t = max({j, 0}); t < min({(l) + 1, N}); ++t) {

int jp = l;
int tp = s;
int lp = t;
E[i][j][k][l][s][t] += E[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

int lp = i;
for (int j = 0; j < N; ++j) {

int ip = j;
for (int k = max({i, 0}); k < min({(j) + 1, N}); ++k) {

for (int l = 0; l < N; ++l) {

int kp = k;
for (int s = 0; s < min({(l) + 1, N}); ++s) {

int jp = l;
for (int t = max({j, 0}); t < min({(s) + 1, N}); ++t) {

int tp = s;
int sp = t;
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

int tp = i;
for (int s = max({j, 0}); s < N; ++s) {

int ip = j;
for (int l = max({k, 0}); l < min({(j) + 1, N}); ++l) {

int kp = k;
for (int t = max({s, 0}); t < N; ++t) {

int jp = s;
int lp = l;
int sp = t;
E[i][j][k][l][s][t] += E[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

int sp = i;
for (int k = max({i, 0}); k < N; ++k) {

int kp = k;
for (int j = 0; j < N; ++j) {

for (int l = max({k, 0}); l < min({(j) + 1, N}); ++l) {

int ip = j;
int lp = l;
for (int s = 0; s < N; ++s) {

for (int t = max({j, 0}); t < min({(s) + 1, N}); ++t) {

int jp = s;
int tp = t;
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

int tp = i;
for (int t = max({j, 0}); t < N; ++t) {

int ip = j;
for (int l = max({k, 0}); l < N; ++l) {

int kp = k;
int jp = t;
for (int s = max({l, 0}); s < min({(j) + 1, N}); ++s) {

int lp = l;
int sp = s;
E[i][j][k][l][s][t] += E[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

int jp = i;
for (int k = max({i, 0}); k < N; ++k) {

for (int l = max({k, 0}); l < N; ++l) {

int kp = k;
for (int s = max({l, 0}); s < N; ++s) {

int lp = l;
int sp = s;
for (int j = 0; j < N; ++j) {

for (int t = max({s, 0}); t < min({(j) + 1, N}); ++t) {

int ip = j;
int tp = t;
E[i][j][k][l][s][t] += E[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

int sp = i;
for (int k = max({i, 0}); k < N; ++k) {

for (int l = max({k, 0}); l < N; ++l) {

int kp = k;
int lp = l;
for (int j = 0; j < N; ++j) {

for (int s = max({j, 0}); s < N; ++s) {

for (int t = max({l, 0}); t < min({(j) + 1, N}); ++t) {

int ip = j;
int tp = s;
int jp = t;
E[i][j][k][l][s][t] += E[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

int jp = i;
for (int k = max({i, 0}); k < N; ++k) {

for (int l = max({k, 0}); l < N; ++l) {

int kp = k;
int lp = l;
for (int j = 0; j < N; ++j) {

for (int s = 0; s < min({(j) + 1, N}); ++s) {

int ip = j;
for (int t = max({l, 0}); t < min({(s) + 1, N}); ++t) {

int tp = s;
int sp = t;
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

int tp = i;
for (int l = max({j, 0}); l < N; ++l) {

int ip = j;
for (int s = max({k, 0}); s < min({(j) + 1, N}); ++s) {

int kp = k;
for (int t = max({l, 0}); t < N; ++t) {

int sp = l;
int jp = s;
int lp = t;
E[i][j][k][l][s][t] += E[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

int lp = i;
for (int k = max({i, 0}); k < N; ++k) {

int kp = k;
for (int j = 0; j < N; ++j) {

for (int s = max({k, 0}); s < min({(j) + 1, N}); ++s) {

int ip = j;
int jp = s;
for (int l = 0; l < N; ++l) {

for (int t = max({j, 0}); t < min({(l) + 1, N}); ++t) {

int sp = l;
int tp = t;
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

int tp = i;
for (int t = max({j, 0}); t < N; ++t) {

for (int l = 0; l < min({(j) + 1, N}); ++l) {

int ip = j;
int kp = k;
int jp = t;
for (int s = max({k, 0}); s < min({(l) + 1, N}); ++s) {

int sp = l;
int lp = s;
E[i][j][k][l][s][t] += E[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

int jp = i;
for (int k = max({i, 0}); k < N; ++k) {

int kp = k;
for (int j = 0; j < N; ++j) {

int ip = j;
for (int l = 0; l < N; ++l) {

for (int s = max({k, 0}); s < min({(l) + 1, N}); ++s) {

for (int t = max({l, 0}); t < min({(j) + 1, N}); ++t) {

int sp = l;
int lp = s;
int tp = t;
E[i][j][k][l][s][t] += E[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

int lp = i;
for (int k = max({i, 0}); k < N; ++k) {

for (int s = max({k, 0}); s < N; ++s) {

int kp = k;
int tp = s;
for (int j = 0; j < N; ++j) {

for (int t = max({s, 0}); t < min({(j) + 1, N}); ++t) {

for (int l = max({j, 0}); l < N; ++l) {

int ip = j;
int jp = t;
int sp = l;
E[i][j][k][l][s][t] += E[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

int jp = i;
for (int k = max({i, 0}); k < N; ++k) {

for (int s = max({k, 0}); s < N; ++s) {

int kp = k;
int tp = s;
for (int j = 0; j < N; ++j) {

for (int l = 0; l < min({(j) + 1, N}); ++l) {

int ip = j;
for (int t = max({s, 0}); t < min({(l) + 1, N}); ++t) {

int sp = l;
int lp = t;
E[i][j][k][l][s][t] += E[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

int sp = i;
for (int k = max({i, 0}); k < N; ++k) {

int kp = k;
for (int j = 0; j < N; ++j) {

for (int t = max({k, 0}); t < min({(j) + 1, N}); ++t) {

for (int l = max({j, 0}); l < N; ++l) {

int ip = j;
int lp = t;
for (int s = max({l, 0}); s < N; ++s) {

int tp = l;
int jp = s;
E[i][j][k][l][s][t] += E[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

int lp = i;
for (int k = max({i, 0}); k < N; ++k) {

int kp = k;
for (int j = 0; j < N; ++j) {

for (int t = max({k, 0}); t < min({(j) + 1, N}); ++t) {

int ip = j;
int sp = t;
for (int l = 0; l < N; ++l) {

for (int s = max({j, 0}); s < min({(l) + 1, N}); ++s) {

int tp = l;
int jp = s;
E[i][j][k][l][s][t] += E[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

int sp = i;
for (int k = max({i, 0}); k < N; ++k) {

int kp = k;
for (int j = 0; j < N; ++j) {

for (int s = max({j, 0}); s < N; ++s) {

for (int l = 0; l < min({(j) + 1, N}); ++l) {

int ip = j;
int lp = s;
for (int t = max({k, 0}); t < min({(l) + 1, N}); ++t) {

int tp = l;
int jp = t;
E[i][j][k][l][s][t] += E[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

int jp = i;
for (int k = max({i, 0}); k < N; ++k) {

int kp = k;
for (int j = 0; j < N; ++j) {

int ip = j;
for (int l = 0; l < N; ++l) {

for (int s = max({l, 0}); s < min({(j) + 1, N}); ++s) {

for (int t = max({k, 0}); t < min({(l) + 1, N}); ++t) {

int tp = l;
int lp = s;
int sp = t;
E[i][j][k][l][s][t] += E[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

int lp = i;
for (int k = max({i, 0}); k < N; ++k) {

int kp = k;
for (int j = 0; j < N; ++j) {

for (int s = 0; s < min({(j) + 1, N}); ++s) {

for (int l = max({j, 0}); l < N; ++l) {

int ip = j;
for (int t = max({k, 0}); t < min({(s) + 1, N}); ++t) {

int sp = s;
int tp = l;
int jp = t;
E[i][j][k][l][s][t] += E[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

int jp = i;
for (int k = max({i, 0}); k < N; ++k) {

int kp = k;
for (int j = 0; j < N; ++j) {

for (int l = 0; l < min({(j) + 1, N}); ++l) {

int ip = j;
for (int s = 0; s < min({(l) + 1, N}); ++s) {

int tp = l;
for (int t = max({k, 0}); t < min({(s) + 1, N}); ++t) {

int sp = s;
int lp = t;
E[i][j][k][l][s][t] += E[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int j = 0; j < N; ++j) {

int tp = i;
for (int l = max({i, 0}); l < min({(j) + 1, N}); ++l) {

int ip = j;
for (int k = max({j, 0}); k < N; ++k) {

int jp = l;
for (int s = max({k, 0}); s < N; ++s) {

int lp = k;
for (int t = max({s, 0}); t < N; ++t) {

int kp = s;
int sp = t;
E[i][j][k][l][s][t] += E[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

int sp = i;
for (int j = 0; j < N; ++j) {

for (int l = max({i, 0}); l < min({(j) + 1, N}); ++l) {

int ip = j;
for (int k = max({j, 0}); k < N; ++k) {

int jp = l;
int lp = k;
for (int s = 0; s < N; ++s) {

for (int t = max({k, 0}); t < min({(s) + 1, N}); ++t) {

int kp = s;
int tp = t;
E[i][j][k][l][s][t] += E[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int j = 0; j < N; ++j) {

int tp = i;
for (int l = max({i, 0}); l < min({(j) + 1, N}); ++l) {

int ip = j;
int jp = l;
for (int k = 0; k < N; ++k) {

for (int s = max({j, 0}); s < min({(k) + 1, N}); ++s) {

for (int t = max({k, 0}); t < N; ++t) {

int lp = k;
int sp = s;
int kp = t;
E[i][j][k][l][s][t] += E[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

int kp = i;
for (int j = 0; j < N; ++j) {

for (int s = max({j, 0}); s < N; ++s) {

for (int l = max({i, 0}); l < min({(j) + 1, N}); ++l) {

int ip = j;
int sp = s;
int jp = l;
for (int k = 0; k < N; ++k) {

for (int t = max({s, 0}); t < min({(k) + 1, N}); ++t) {

int lp = k;
int tp = t;
E[i][j][k][l][s][t] += E[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

int sp = i;
for (int j = 0; j < N; ++j) {

for (int l = max({i, 0}); l < min({(j) + 1, N}); ++l) {

int ip = j;
int jp = l;
for (int k = 0; k < N; ++k) {

for (int s = max({k, 0}); s < N; ++s) {

for (int t = max({j, 0}); t < min({(k) + 1, N}); ++t) {

int lp = k;
int tp = s;
int kp = t;
E[i][j][k][l][s][t] += E[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

int kp = i;
for (int j = 0; j < N; ++j) {

for (int l = max({i, 0}); l < min({(j) + 1, N}); ++l) {

int ip = j;
int jp = l;
for (int k = 0; k < N; ++k) {

for (int s = 0; s < min({(k) + 1, N}); ++s) {

int lp = k;
for (int t = max({j, 0}); t < min({(s) + 1, N}); ++t) {

int tp = s;
int sp = t;
E[i][j][k][l][s][t] += E[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int j = 0; j < N; ++j) {

int tp = i;
for (int s = max({j, 0}); s < N; ++s) {

int ip = j;
for (int k = 0; k < min({(j) + 1, N}); ++k) {

for (int t = max({s, 0}); t < N; ++t) {

int jp = s;
for (int l = max({i, 0}); l < min({(k) + 1, N}); ++l) {

int lp = k;
int sp = t;
int kp = l;
E[i][j][k][l][s][t] += E[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

int sp = i;
for (int j = 0; j < N; ++j) {

int ip = j;
for (int k = 0; k < min({(j) + 1, N}); ++k) {

for (int l = max({i, 0}); l < min({(k) + 1, N}); ++l) {

int lp = k;
int kp = l;
for (int s = 0; s < N; ++s) {

for (int t = max({j, 0}); t < min({(s) + 1, N}); ++t) {

int jp = s;
int tp = t;
E[i][j][k][l][s][t] += E[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int j = 0; j < N; ++j) {

int tp = i;
for (int t = max({j, 0}); t < N; ++t) {

int ip = j;
int jp = t;
for (int k = 0; k < N; ++k) {

for (int s = max({k, 0}); s < min({(j) + 1, N}); ++s) {

for (int l = max({i, 0}); l < min({(k) + 1, N}); ++l) {

int lp = k;
int sp = s;
int kp = l;
E[i][j][k][l][s][t] += E[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

int jp = i;
for (int j = 0; j < N; ++j) {

int ip = j;
for (int k = 0; k < N; ++k) {

for (int s = max({k, 0}); s < N; ++s) {

for (int l = max({i, 0}); l < min({(k) + 1, N}); ++l) {

int lp = k;
for (int t = max({s, 0}); t < min({(j) + 1, N}); ++t) {

int sp = s;
int kp = l;
int tp = t;
E[i][j][k][l][s][t] += E[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

int sp = i;
for (int j = 0; j < N; ++j) {

for (int s = max({j, 0}); s < N; ++s) {

int ip = j;
int tp = s;
for (int k = 0; k < N; ++k) {

for (int t = max({k, 0}); t < min({(j) + 1, N}); ++t) {

for (int l = max({i, 0}); l < min({(k) + 1, N}); ++l) {

int lp = k;
int jp = t;
int kp = l;
E[i][j][k][l][s][t] += E[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

int jp = i;
for (int j = 0; j < N; ++j) {

for (int s = 0; s < min({(j) + 1, N}); ++s) {

int ip = j;
int tp = s;
for (int k = 0; k < N; ++k) {

for (int t = max({k, 0}); t < min({(s) + 1, N}); ++t) {

for (int l = max({i, 0}); l < min({(k) + 1, N}); ++l) {

int lp = k;
int sp = t;
int kp = l;
E[i][j][k][l][s][t] += E[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int l = max({i, 0}); l < N; ++l) {

int tp = i;
int sp = l;
for (int j = 0; j < N; ++j) {

for (int s = max({l, 0}); s < min({(j) + 1, N}); ++s) {

int ip = j;
for (int k = max({j, 0}); k < N; ++k) {

int jp = s;
for (int t = max({k, 0}); t < N; ++t) {

int lp = k;
int kp = t;
E[i][j][k][l][s][t] += E[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int l = max({i, 0}); l < N; ++l) {

int kp = i;
int sp = l;
for (int j = 0; j < N; ++j) {

for (int s = max({l, 0}); s < min({(j) + 1, N}); ++s) {

int ip = j;
int jp = s;
for (int k = 0; k < N; ++k) {

for (int t = max({j, 0}); t < min({(k) + 1, N}); ++t) {

int lp = k;
int tp = t;
E[i][j][k][l][s][t] += E[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int l = max({i, 0}); l < N; ++l) {

int tp = i;
int sp = l;
for (int j = 0; j < N; ++j) {

for (int t = max({j, 0}); t < N; ++t) {

int ip = j;
for (int k = 0; k < min({(j) + 1, N}); ++k) {

int jp = t;
for (int s = max({l, 0}); s < min({(k) + 1, N}); ++s) {

int lp = k;
int kp = s;
E[i][j][k][l][s][t] += E[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int l = max({i, 0}); l < N; ++l) {

int jp = i;
int sp = l;
for (int j = 0; j < N; ++j) {

int ip = j;
for (int k = 0; k < N; ++k) {

for (int s = max({l, 0}); s < min({(k) + 1, N}); ++s) {

for (int t = max({k, 0}); t < min({(j) + 1, N}); ++t) {

int lp = k;
int kp = s;
int tp = t;
E[i][j][k][l][s][t] += E[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int l = max({i, 0}); l < N; ++l) {

int kp = i;
for (int s = max({l, 0}); s < N; ++s) {

int sp = l;
int tp = s;
for (int j = 0; j < N; ++j) {

for (int t = max({s, 0}); t < min({(j) + 1, N}); ++t) {

int ip = j;
for (int k = max({j, 0}); k < N; ++k) {

int jp = t;
int lp = k;
E[i][j][k][l][s][t] += E[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int l = max({i, 0}); l < N; ++l) {

int jp = i;
for (int s = max({l, 0}); s < N; ++s) {

int sp = l;
int tp = s;
for (int j = 0; j < N; ++j) {

int ip = j;
for (int k = 0; k < min({(j) + 1, N}); ++k) {

for (int t = max({s, 0}); t < min({(k) + 1, N}); ++t) {

int lp = k;
int kp = t;
E[i][j][k][l][s][t] += E[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int l = max({i, 0}); l < N; ++l) {

int sp = i;
int tp = l;
for (int j = 0; j < N; ++j) {

for (int t = max({l, 0}); t < min({(j) + 1, N}); ++t) {

int ip = j;
for (int k = max({j, 0}); k < N; ++k) {

int kp = t;
for (int s = max({k, 0}); s < N; ++s) {

int lp = k;
int jp = s;
E[i][j][k][l][s][t] += E[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int l = max({i, 0}); l < N; ++l) {

int kp = i;
int tp = l;
for (int j = 0; j < N; ++j) {

for (int t = max({l, 0}); t < min({(j) + 1, N}); ++t) {

int ip = j;
int sp = t;
for (int k = 0; k < N; ++k) {

for (int s = max({j, 0}); s < min({(k) + 1, N}); ++s) {

int lp = k;
int jp = s;
E[i][j][k][l][s][t] += E[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int l = max({i, 0}); l < N; ++l) {

int sp = i;
int tp = l;
for (int j = 0; j < N; ++j) {

for (int s = max({j, 0}); s < N; ++s) {

int ip = j;
for (int k = 0; k < min({(j) + 1, N}); ++k) {

int kp = s;
for (int t = max({l, 0}); t < min({(k) + 1, N}); ++t) {

int lp = k;
int jp = t;
E[i][j][k][l][s][t] += E[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int l = max({i, 0}); l < N; ++l) {

int jp = i;
int tp = l;
for (int j = 0; j < N; ++j) {

int ip = j;
for (int k = 0; k < N; ++k) {

for (int s = max({k, 0}); s < min({(j) + 1, N}); ++s) {

for (int t = max({l, 0}); t < min({(k) + 1, N}); ++t) {

int lp = k;
int kp = s;
int sp = t;
E[i][j][k][l][s][t] += E[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int l = max({i, 0}); l < N; ++l) {

int kp = i;
int tp = l;
for (int j = 0; j < N; ++j) {

for (int s = 0; s < min({(j) + 1, N}); ++s) {

int ip = j;
for (int k = max({j, 0}); k < N; ++k) {

for (int t = max({l, 0}); t < min({(s) + 1, N}); ++t) {

int sp = s;
int lp = k;
int jp = t;
E[i][j][k][l][s][t] += E[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int l = max({i, 0}); l < N; ++l) {

int jp = i;
int tp = l;
for (int j = 0; j < N; ++j) {

int ip = j;
for (int k = 0; k < min({(j) + 1, N}); ++k) {

for (int s = 0; s < min({(k) + 1, N}); ++s) {

int lp = k;
for (int t = max({l, 0}); t < min({(s) + 1, N}); ++t) {

int sp = s;
int kp = t;
E[i][j][k][l][s][t] += E[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int j = 0; j < N; ++j) {

int tp = i;
for (int s = max({i, 0}); s < min({(j) + 1, N}); ++s) {

int ip = j;
for (int k = max({j, 0}); k < N; ++k) {

int kp = s;
for (int l = max({k, 0}); l < N; ++l) {

int sp = k;
for (int t = max({l, 0}); t < N; ++t) {

int jp = l;
int lp = t;
E[i][j][k][l][s][t] += E[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

int lp = i;
for (int j = 0; j < N; ++j) {

for (int s = max({i, 0}); s < min({(j) + 1, N}); ++s) {

int ip = j;
for (int k = max({j, 0}); k < N; ++k) {

int kp = s;
int sp = k;
for (int l = 0; l < N; ++l) {

for (int t = max({k, 0}); t < min({(l) + 1, N}); ++t) {

int jp = l;
int tp = t;
E[i][j][k][l][s][t] += E[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int j = 0; j < N; ++j) {

int tp = i;
for (int s = max({i, 0}); s < min({(j) + 1, N}); ++s) {

int ip = j;
int lp = s;
for (int k = 0; k < N; ++k) {

for (int t = max({k, 0}); t < N; ++t) {

for (int l = max({j, 0}); l < min({(k) + 1, N}); ++l) {

int sp = k;
int kp = t;
int jp = l;
E[i][j][k][l][s][t] += E[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

int kp = i;
for (int j = 0; j < N; ++j) {

for (int s = max({i, 0}); s < min({(j) + 1, N}); ++s) {

for (int l = max({j, 0}); l < N; ++l) {

int ip = j;
int lp = s;
int jp = l;
for (int k = 0; k < N; ++k) {

for (int t = max({l, 0}); t < min({(k) + 1, N}); ++t) {

int sp = k;
int tp = t;
E[i][j][k][l][s][t] += E[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

int lp = i;
for (int j = 0; j < N; ++j) {

for (int s = max({i, 0}); s < min({(j) + 1, N}); ++s) {

int ip = j;
int tp = s;
for (int k = 0; k < N; ++k) {

for (int t = max({j, 0}); t < min({(k) + 1, N}); ++t) {

for (int l = max({k, 0}); l < N; ++l) {

int sp = k;
int kp = t;
int jp = l;
E[i][j][k][l][s][t] += E[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

int kp = i;
for (int j = 0; j < N; ++j) {

for (int s = max({i, 0}); s < min({(j) + 1, N}); ++s) {

int ip = j;
int tp = s;
for (int k = 0; k < N; ++k) {

for (int l = 0; l < min({(k) + 1, N}); ++l) {

int sp = k;
for (int t = max({j, 0}); t < min({(l) + 1, N}); ++t) {

int jp = l;
int lp = t;
E[i][j][k][l][s][t] += E[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int j = 0; j < N; ++j) {

int tp = i;
for (int l = max({j, 0}); l < N; ++l) {

int ip = j;
for (int k = 0; k < min({(j) + 1, N}); ++k) {

for (int t = max({l, 0}); t < N; ++t) {

int kp = l;
for (int s = max({i, 0}); s < min({(k) + 1, N}); ++s) {

int sp = k;
int lp = t;
int jp = s;
E[i][j][k][l][s][t] += E[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

int lp = i;
for (int j = 0; j < N; ++j) {

int ip = j;
for (int k = 0; k < min({(j) + 1, N}); ++k) {

for (int s = max({i, 0}); s < min({(k) + 1, N}); ++s) {

int sp = k;
int jp = s;
for (int l = 0; l < N; ++l) {

for (int t = max({j, 0}); t < min({(l) + 1, N}); ++t) {

int kp = l;
int tp = t;
E[i][j][k][l][s][t] += E[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int j = 0; j < N; ++j) {

int tp = i;
for (int t = max({j, 0}); t < N; ++t) {

int ip = j;
int jp = t;
for (int k = 0; k < N; ++k) {

for (int s = max({i, 0}); s < min({(k) + 1, N}); ++s) {

for (int l = max({k, 0}); l < min({(j) + 1, N}); ++l) {

int sp = k;
int lp = s;
int kp = l;
E[i][j][k][l][s][t] += E[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

int jp = i;
for (int j = 0; j < N; ++j) {

int ip = j;
for (int k = 0; k < N; ++k) {

for (int s = max({i, 0}); s < min({(k) + 1, N}); ++s) {

for (int l = max({k, 0}); l < N; ++l) {

int sp = k;
int lp = s;
for (int t = max({l, 0}); t < min({(j) + 1, N}); ++t) {

int kp = l;
int tp = t;
E[i][j][k][l][s][t] += E[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

int lp = i;
for (int j = 0; j < N; ++j) {

for (int l = max({j, 0}); l < N; ++l) {

int ip = j;
int kp = l;
for (int k = 0; k < N; ++k) {

for (int s = max({i, 0}); s < min({(k) + 1, N}); ++s) {

for (int t = max({k, 0}); t < min({(j) + 1, N}); ++t) {

int sp = k;
int tp = s;
int jp = t;
E[i][j][k][l][s][t] += E[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

int jp = i;
for (int j = 0; j < N; ++j) {

for (int l = 0; l < min({(j) + 1, N}); ++l) {

int ip = j;
int kp = l;
for (int k = 0; k < N; ++k) {

for (int s = max({i, 0}); s < min({(k) + 1, N}); ++s) {

for (int t = max({k, 0}); t < min({(l) + 1, N}); ++t) {

int sp = k;
int tp = s;
int lp = t;
E[i][j][k][l][s][t] += E[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int j = 0; j < N; ++j) {

int tp = i;
for (int l = 0; l < min({(j) + 1, N}); ++l) {

int ip = j;
for (int k = max({j, 0}); k < N; ++k) {

for (int s = max({i, 0}); s < min({(l) + 1, N}); ++s) {

int lp = l;
for (int t = max({k, 0}); t < N; ++t) {

int sp = k;
int jp = s;
int kp = t;
E[i][j][k][l][s][t] += E[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

int kp = i;
for (int j = 0; j < N; ++j) {

for (int l = 0; l < min({(j) + 1, N}); ++l) {

int ip = j;
for (int s = max({i, 0}); s < min({(l) + 1, N}); ++s) {

int lp = l;
int jp = s;
for (int k = 0; k < N; ++k) {

for (int t = max({j, 0}); t < min({(k) + 1, N}); ++t) {

int sp = k;
int tp = t;
E[i][j][k][l][s][t] += E[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int j = 0; j < N; ++j) {

int tp = i;
for (int t = max({j, 0}); t < N; ++t) {

int ip = j;
for (int k = 0; k < min({(j) + 1, N}); ++k) {

int jp = t;
for (int l = 0; l < min({(k) + 1, N}); ++l) {

int sp = k;
for (int s = max({i, 0}); s < min({(l) + 1, N}); ++s) {

int lp = l;
int kp = s;
E[i][j][k][l][s][t] += E[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

int jp = i;
for (int j = 0; j < N; ++j) {

int ip = j;
for (int k = 0; k < N; ++k) {

for (int t = max({k, 0}); t < min({(j) + 1, N}); ++t) {

for (int l = 0; l < min({(k) + 1, N}); ++l) {

int sp = k;
int tp = t;
for (int s = max({i, 0}); s < min({(l) + 1, N}); ++s) {

int lp = l;
int kp = s;
E[i][j][k][l][s][t] += E[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

int kp = i;
for (int j = 0; j < N; ++j) {

int ip = j;
for (int k = max({j, 0}); k < N; ++k) {

for (int l = 0; l < N; ++l) {

int sp = k;
for (int s = max({i, 0}); s < min({(l) + 1, N}); ++s) {

for (int t = max({l, 0}); t < min({(j) + 1, N}); ++t) {

int lp = l;
int tp = s;
int jp = t;
E[i][j][k][l][s][t] += E[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

int jp = i;
for (int j = 0; j < N; ++j) {

int ip = j;
for (int k = 0; k < min({(j) + 1, N}); ++k) {

for (int l = 0; l < N; ++l) {

int sp = k;
for (int s = max({i, 0}); s < min({(l) + 1, N}); ++s) {

for (int t = max({l, 0}); t < min({(k) + 1, N}); ++t) {

int lp = l;
int tp = s;
int kp = t;
E[i][j][k][l][s][t] += E[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int s = max({i, 0}); s < N; ++s) {

int lp = i;
int jp = s;
for (int j = 0; j < N; ++j) {

for (int t = max({s, 0}); t < min({(j) + 1, N}); ++t) {

int ip = j;
for (int k = max({j, 0}); k < N; ++k) {

int kp = t;
for (int l = max({k, 0}); l < N; ++l) {

int sp = k;
int tp = l;
E[i][j][k][l][s][t] += E[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int s = max({i, 0}); s < N; ++s) {

int kp = i;
int jp = s;
for (int j = 0; j < N; ++j) {

for (int t = max({s, 0}); t < min({(j) + 1, N}); ++t) {

int ip = j;
int lp = t;
for (int k = 0; k < N; ++k) {

for (int l = max({j, 0}); l < min({(k) + 1, N}); ++l) {

int sp = k;
int tp = l;
E[i][j][k][l][s][t] += E[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int s = max({i, 0}); s < N; ++s) {

int lp = i;
int kp = s;
for (int j = 0; j < N; ++j) {

for (int l = max({j, 0}); l < N; ++l) {

int ip = j;
for (int k = 0; k < min({(j) + 1, N}); ++k) {

int tp = l;
for (int t = max({s, 0}); t < min({(k) + 1, N}); ++t) {

int sp = k;
int jp = t;
E[i][j][k][l][s][t] += E[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int s = max({i, 0}); s < N; ++s) {

int jp = i;
int kp = s;
for (int j = 0; j < N; ++j) {

int ip = j;
for (int k = 0; k < N; ++k) {

for (int t = max({s, 0}); t < min({(k) + 1, N}); ++t) {

for (int l = max({k, 0}); l < min({(j) + 1, N}); ++l) {

int sp = k;
int lp = t;
int tp = l;
E[i][j][k][l][s][t] += E[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int s = max({i, 0}); s < N; ++s) {

int kp = i;
int lp = s;
for (int j = 0; j < N; ++j) {

for (int l = 0; l < min({(j) + 1, N}); ++l) {

int ip = j;
for (int k = max({j, 0}); k < N; ++k) {

for (int t = max({s, 0}); t < min({(l) + 1, N}); ++t) {

int tp = l;
int sp = k;
int jp = t;
E[i][j][k][l][s][t] += E[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int s = max({i, 0}); s < N; ++s) {

int jp = i;
int lp = s;
for (int j = 0; j < N; ++j) {

int ip = j;
for (int k = 0; k < min({(j) + 1, N}); ++k) {

for (int l = 0; l < min({(k) + 1, N}); ++l) {

int sp = k;
for (int t = max({s, 0}); t < min({(l) + 1, N}); ++t) {

int tp = l;
int kp = t;
E[i][j][k][l][s][t] += E[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

int sp = i;
for (int j = 0; j < N; ++j) {

for (int t = max({i, 0}); t < min({(j) + 1, N}); ++t) {

int ip = j;
for (int k = max({j, 0}); k < N; ++k) {

int lp = t;
for (int l = max({k, 0}); l < N; ++l) {

int tp = k;
for (int s = max({l, 0}); s < N; ++s) {

int jp = l;
int kp = s;
E[i][j][k][l][s][t] += E[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

int lp = i;
for (int j = 0; j < N; ++j) {

for (int t = max({i, 0}); t < min({(j) + 1, N}); ++t) {

int ip = j;
for (int k = max({j, 0}); k < N; ++k) {

int sp = t;
int tp = k;
for (int l = 0; l < N; ++l) {

for (int s = max({k, 0}); s < min({(l) + 1, N}); ++s) {

int jp = l;
int kp = s;
E[i][j][k][l][s][t] += E[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

int sp = i;
for (int j = 0; j < N; ++j) {

for (int t = max({i, 0}); t < min({(j) + 1, N}); ++t) {

int ip = j;
int kp = t;
for (int k = 0; k < N; ++k) {

for (int s = max({k, 0}); s < N; ++s) {

for (int l = max({j, 0}); l < min({(k) + 1, N}); ++l) {

int tp = k;
int lp = s;
int jp = l;
E[i][j][k][l][s][t] += E[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

int kp = i;
for (int j = 0; j < N; ++j) {

for (int t = max({i, 0}); t < min({(j) + 1, N}); ++t) {

for (int l = max({j, 0}); l < N; ++l) {

int ip = j;
int sp = t;
int jp = l;
for (int k = 0; k < N; ++k) {

for (int s = max({l, 0}); s < min({(k) + 1, N}); ++s) {

int tp = k;
int lp = s;
E[i][j][k][l][s][t] += E[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

int lp = i;
for (int j = 0; j < N; ++j) {

for (int t = max({i, 0}); t < min({(j) + 1, N}); ++t) {

int ip = j;
int kp = t;
for (int k = 0; k < N; ++k) {

for (int s = max({j, 0}); s < min({(k) + 1, N}); ++s) {

for (int l = max({k, 0}); l < N; ++l) {

int tp = k;
int sp = s;
int jp = l;
E[i][j][k][l][s][t] += E[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

int kp = i;
for (int j = 0; j < N; ++j) {

for (int t = max({i, 0}); t < min({(j) + 1, N}); ++t) {

int ip = j;
int lp = t;
for (int k = 0; k < N; ++k) {

for (int l = 0; l < min({(k) + 1, N}); ++l) {

int tp = k;
for (int s = max({j, 0}); s < min({(l) + 1, N}); ++s) {

int jp = l;
int sp = s;
E[i][j][k][l][s][t] += E[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

int sp = i;
for (int j = 0; j < N; ++j) {

for (int l = max({j, 0}); l < N; ++l) {

int ip = j;
for (int k = 0; k < min({(j) + 1, N}); ++k) {

for (int s = max({l, 0}); s < N; ++s) {

int kp = l;
for (int t = max({i, 0}); t < min({(k) + 1, N}); ++t) {

int tp = k;
int jp = s;
int lp = t;
E[i][j][k][l][s][t] += E[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

int lp = i;
for (int j = 0; j < N; ++j) {

int ip = j;
for (int k = 0; k < min({(j) + 1, N}); ++k) {

for (int t = max({i, 0}); t < min({(k) + 1, N}); ++t) {

int tp = k;
int sp = t;
for (int l = 0; l < N; ++l) {

for (int s = max({j, 0}); s < min({(l) + 1, N}); ++s) {

int kp = l;
int jp = s;
E[i][j][k][l][s][t] += E[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

int sp = i;
for (int j = 0; j < N; ++j) {

for (int s = max({j, 0}); s < N; ++s) {

int ip = j;
int lp = s;
for (int k = 0; k < N; ++k) {

for (int t = max({i, 0}); t < min({(k) + 1, N}); ++t) {

for (int l = max({k, 0}); l < min({(j) + 1, N}); ++l) {

int tp = k;
int jp = t;
int kp = l;
E[i][j][k][l][s][t] += E[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

int jp = i;
for (int j = 0; j < N; ++j) {

int ip = j;
for (int k = 0; k < N; ++k) {

for (int t = max({i, 0}); t < min({(k) + 1, N}); ++t) {

for (int l = max({k, 0}); l < N; ++l) {

int tp = k;
int sp = t;
for (int s = max({l, 0}); s < min({(j) + 1, N}); ++s) {

int kp = l;
int lp = s;
E[i][j][k][l][s][t] += E[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

int lp = i;
for (int j = 0; j < N; ++j) {

for (int l = max({j, 0}); l < N; ++l) {

int ip = j;
int kp = l;
for (int k = 0; k < N; ++k) {

for (int s = max({k, 0}); s < min({(j) + 1, N}); ++s) {

for (int t = max({i, 0}); t < min({(k) + 1, N}); ++t) {

int tp = k;
int sp = s;
int jp = t;
E[i][j][k][l][s][t] += E[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

int jp = i;
for (int j = 0; j < N; ++j) {

for (int l = 0; l < min({(j) + 1, N}); ++l) {

int ip = j;
int kp = l;
for (int k = 0; k < N; ++k) {

for (int s = max({k, 0}); s < min({(l) + 1, N}); ++s) {

for (int t = max({i, 0}); t < min({(k) + 1, N}); ++t) {

int tp = k;
int sp = s;
int lp = t;
E[i][j][k][l][s][t] += E[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

int sp = i;
for (int j = 0; j < N; ++j) {

for (int l = 0; l < min({(j) + 1, N}); ++l) {

int ip = j;
for (int k = max({j, 0}); k < N; ++k) {

for (int t = max({i, 0}); t < min({(l) + 1, N}); ++t) {

int lp = l;
for (int s = max({k, 0}); s < N; ++s) {

int tp = k;
int kp = t;
int jp = s;
E[i][j][k][l][s][t] += E[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

int kp = i;
for (int j = 0; j < N; ++j) {

for (int l = 0; l < min({(j) + 1, N}); ++l) {

int ip = j;
for (int t = max({i, 0}); t < min({(l) + 1, N}); ++t) {

int lp = l;
int sp = t;
for (int k = 0; k < N; ++k) {

for (int s = max({j, 0}); s < min({(k) + 1, N}); ++s) {

int tp = k;
int jp = s;
E[i][j][k][l][s][t] += E[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

int sp = i;
for (int j = 0; j < N; ++j) {

for (int s = max({j, 0}); s < N; ++s) {

int ip = j;
for (int k = 0; k < min({(j) + 1, N}); ++k) {

int kp = s;
for (int l = 0; l < min({(k) + 1, N}); ++l) {

int tp = k;
for (int t = max({i, 0}); t < min({(l) + 1, N}); ++t) {

int lp = l;
int jp = t;
E[i][j][k][l][s][t] += E[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

int jp = i;
for (int j = 0; j < N; ++j) {

int ip = j;
for (int k = 0; k < N; ++k) {

for (int s = max({k, 0}); s < min({(j) + 1, N}); ++s) {

for (int l = 0; l < min({(k) + 1, N}); ++l) {

int tp = k;
int kp = s;
for (int t = max({i, 0}); t < min({(l) + 1, N}); ++t) {

int lp = l;
int sp = t;
E[i][j][k][l][s][t] += E[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

int kp = i;
for (int j = 0; j < N; ++j) {

int ip = j;
for (int k = max({j, 0}); k < N; ++k) {

for (int l = 0; l < N; ++l) {

int tp = k;
for (int s = max({l, 0}); s < min({(j) + 1, N}); ++s) {

for (int t = max({i, 0}); t < min({(l) + 1, N}); ++t) {

int lp = l;
int sp = s;
int jp = t;
E[i][j][k][l][s][t] += E[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

int jp = i;
for (int j = 0; j < N; ++j) {

int ip = j;
for (int k = 0; k < min({(j) + 1, N}); ++k) {

for (int l = 0; l < N; ++l) {

int tp = k;
for (int s = max({l, 0}); s < min({(k) + 1, N}); ++s) {

for (int t = max({i, 0}); t < min({(l) + 1, N}); ++t) {

int lp = l;
int sp = s;
int kp = t;
E[i][j][k][l][s][t] += E[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

int lp = i;
for (int j = 0; j < N; ++j) {

for (int s = 0; s < min({(j) + 1, N}); ++s) {

int ip = j;
for (int k = max({j, 0}); k < N; ++k) {

for (int t = max({i, 0}); t < min({(s) + 1, N}); ++t) {

int jp = s;
for (int l = max({k, 0}); l < N; ++l) {

int tp = k;
int kp = t;
int sp = l;
E[i][j][k][l][s][t] += E[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

int kp = i;
for (int j = 0; j < N; ++j) {

for (int s = 0; s < min({(j) + 1, N}); ++s) {

int ip = j;
for (int t = max({i, 0}); t < min({(s) + 1, N}); ++t) {

int jp = s;
int lp = t;
for (int k = 0; k < N; ++k) {

for (int l = max({j, 0}); l < min({(k) + 1, N}); ++l) {

int tp = k;
int sp = l;
E[i][j][k][l][s][t] += E[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

int lp = i;
for (int j = 0; j < N; ++j) {

for (int l = max({j, 0}); l < N; ++l) {

int ip = j;
for (int k = 0; k < min({(j) + 1, N}); ++k) {

int sp = l;
for (int s = 0; s < min({(k) + 1, N}); ++s) {

int tp = k;
for (int t = max({i, 0}); t < min({(s) + 1, N}); ++t) {

int kp = s;
int jp = t;
E[i][j][k][l][s][t] += E[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

int jp = i;
for (int j = 0; j < N; ++j) {

int ip = j;
for (int k = 0; k < N; ++k) {

for (int s = 0; s < min({(k) + 1, N}); ++s) {

for (int l = max({k, 0}); l < min({(j) + 1, N}); ++l) {

int tp = k;
for (int t = max({i, 0}); t < min({(s) + 1, N}); ++t) {

int kp = s;
int sp = l;
int lp = t;
E[i][j][k][l][s][t] += E[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

int kp = i;
for (int j = 0; j < N; ++j) {

for (int l = 0; l < min({(j) + 1, N}); ++l) {

int ip = j;
for (int k = max({j, 0}); k < N; ++k) {

for (int s = 0; s < min({(l) + 1, N}); ++s) {

int sp = l;
int tp = k;
for (int t = max({i, 0}); t < min({(s) + 1, N}); ++t) {

int lp = s;
int jp = t;
E[i][j][k][l][s][t] += E[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

int jp = i;
for (int j = 0; j < N; ++j) {

int ip = j;
for (int k = 0; k < min({(j) + 1, N}); ++k) {

for (int l = 0; l < min({(k) + 1, N}); ++l) {

int tp = k;
for (int s = 0; s < min({(l) + 1, N}); ++s) {

int sp = l;
for (int t = max({i, 0}); t < min({(s) + 1, N}); ++t) {

int lp = s;
int kp = t;
E[i][j][k][l][s][t] += E[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

int jp = i;
for (int j = 0; j < min({i, N}); ++j) {

int ip = j;
F[i][j] += F[ip][jp];
}
}
for (int i = 0; i < N; ++i) {

int kp = i;
for (int j = 0; j < min({(i) + 1, N}); ++j) {

for (int k = max({i, 0}); k < N; ++k) {

int jp = j;
int ip = k;
G[i][j][k] += G[ip][jp][kp];
}
}
}
for (int i = 0; i < N; ++i) {

int ip = i;
for (int j = 0; j < min({(i) + 1, N}); ++j) {

int kp = j;
for (int k = 0; k < min({(j) + 1, N}); ++k) {

int jp = k;
G[i][j][k] += G[ip][jp][kp];
}
}
}
for (int i = 0; i < N; ++i) {

int jp = i;
for (int j = max({i, 0}); j < N; ++j) {

for (int k = 0; k < min({(i) + 1, N}); ++k) {

int kp = j;
int ip = k;
G[i][j][k] += G[ip][jp][kp];
}
}
}
for (int i = 0; i < N; ++i) {

int kp = i;
for (int j = max({i, 0}); j < N; ++j) {

int ip = j;
for (int k = max({j, 0}); k < N; ++k) {

int jp = k;
G[i][j][k] += G[ip][jp][kp];
}
}
}
for (int i = 0; i < N; ++i) {

int jp = i;
for (int j = 0; j < N; ++j) {

int ip = j;
for (int k = max({i, 0}); k < min({(j) + 1, N}); ++k) {

int kp = k;
G[i][j][k] += G[ip][jp][kp];
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
H[i][j][k][l] += H[ip][jp][kp][lp];
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
H[i][j][k][l] += H[ip][jp][kp][lp];
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
H[i][j][k][l] += H[ip][jp][kp][lp];
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
H[i][j][k][l] += H[ip][jp][kp][lp];
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
H[i][j][k][l] += H[ip][jp][kp][lp];
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
H[i][j][k][l] += H[ip][jp][kp][lp];
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
H[i][j][k][l] += H[ip][jp][kp][lp];
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
H[i][j][k][l] += H[ip][jp][kp][lp];
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
H[i][j][k][l] += H[ip][jp][kp][lp];
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
H[i][j][k][l] += H[ip][jp][kp][lp];
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
H[i][j][k][l] += H[ip][jp][kp][lp];
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
H[i][j][k][l] += H[ip][jp][kp][lp];
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
H[i][j][k][l] += H[ip][jp][kp][lp];
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
H[i][j][k][l] += H[ip][jp][kp][lp];
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
H[i][j][k][l] += H[ip][jp][kp][lp];
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
H[i][j][k][l] += H[ip][jp][kp][lp];
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
H[i][j][k][l] += H[ip][jp][kp][lp];
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
H[i][j][k][l] += H[ip][jp][kp][lp];
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
H[i][j][k][l] += H[ip][jp][kp][lp];
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
H[i][j][k][l] += H[ip][jp][kp][lp];
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
H[i][j][k][l] += H[ip][jp][kp][lp];
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
H[i][j][k][l] += H[ip][jp][kp][lp];
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
H[i][j][k][l] += H[ip][jp][kp][lp];
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int s = max({i, 0}); s < N; ++s) {

int sp = i;
int ip = s;
for (int j = 0; j < N; ++j) {

int jp = j;
for (int k = max({j, 0}); k < N; ++k) {

for (int l = max({k, 0}); l < min({(i) + 1, N}); ++l) {

int kp = k;
int lp = l;
I[i][j][k][l][s] += I[ip][jp][kp][lp][sp];
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int l = 0; l < min({(i) + 1, N}); ++l) {

int ip = i;
int sp = l;
for (int j = 0; j < N; ++j) {

int jp = j;
for (int k = max({j, 0}); k < N; ++k) {

for (int s = max({k, 0}); s < min({(l) + 1, N}); ++s) {

int kp = k;
int lp = s;
I[i][j][k][l][s] += I[ip][jp][kp][lp][sp];
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int l = max({i, 0}); l < N; ++l) {

int lp = i;
int sp = l;
for (int j = 0; j < N; ++j) {

int jp = j;
for (int k = max({j, 0}); k < N; ++k) {

for (int s = max({k, 0}); s < min({(i) + 1, N}); ++s) {

int kp = k;
int ip = s;
I[i][j][k][l][s] += I[ip][jp][kp][lp][sp];
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int l = max({i, 0}); l < N; ++l) {

int sp = i;
for (int s = max({l, 0}); s < N; ++s) {

int ip = l;
int lp = s;
for (int j = 0; j < N; ++j) {

int jp = j;
for (int k = max({j, 0}); k < min({(i) + 1, N}); ++k) {

int kp = k;
I[i][j][k][l][s] += I[ip][jp][kp][lp][sp];
}
}
}
}
}
for (int i = 0; i < N; ++i) {

int lp = i;
for (int j = 0; j < N; ++j) {

int jp = j;
for (int k = max({j, 0}); k < min({(i) + 1, N}); ++k) {

for (int l = 0; l < N; ++l) {

int kp = k;
for (int s = max({i, 0}); s < min({(l) + 1, N}); ++s) {

int ip = l;
int sp = s;
I[i][j][k][l][s] += I[ip][jp][kp][lp][sp];
}
}
}
}
}
for (int i = 0; i < N; ++i) {

int ip = i;
for (int j = 0; j < N; ++j) {

int jp = j;
for (int k = 0; k < N; ++k) {

for (int s = max({k, 0}); s < min({(i) + 1, N}); ++s) {

for (int l = max({j, 0}); l < min({(k) + 1, N}); ++l) {

int lp = k;
int sp = s;
int kp = l;
I[i][j][k][l][s] += I[ip][jp][kp][lp][sp];
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int s = max({i, 0}); s < N; ++s) {

int sp = i;
for (int k = 0; k < min({(i) + 1, N}); ++k) {

int ip = s;
int lp = k;
for (int j = 0; j < N; ++j) {

for (int l = max({j, 0}); l < min({(k) + 1, N}); ++l) {

int jp = j;
int kp = l;
I[i][j][k][l][s] += I[ip][jp][kp][lp][sp];
}
}
}
}
}
for (int i = 0; i < N; ++i) {

int ip = i;
for (int k = 0; k < min({(i) + 1, N}); ++k) {

int lp = k;
for (int j = 0; j < N; ++j) {

for (int l = max({j, 0}); l < N; ++l) {

int jp = j;
for (int s = max({l, 0}); s < min({(k) + 1, N}); ++s) {

int sp = l;
int kp = s;
I[i][j][k][l][s] += I[ip][jp][kp][lp][sp];
}
}
}
}
}
for (int i = 0; i < N; ++i) {

int kp = i;
for (int k = max({i, 0}); k < N; ++k) {

int lp = k;
for (int j = 0; j < N; ++j) {

for (int l = max({j, 0}); l < N; ++l) {

int jp = j;
for (int s = max({l, 0}); s < min({(i) + 1, N}); ++s) {

int sp = l;
int ip = s;
I[i][j][k][l][s] += I[ip][jp][kp][lp][sp];
}
}
}
}
}
for (int i = 0; i < N; ++i) {

int sp = i;
for (int k = max({i, 0}); k < N; ++k) {

for (int s = max({k, 0}); s < N; ++s) {

int lp = k;
int kp = s;
for (int j = 0; j < N; ++j) {

for (int l = max({j, 0}); l < min({(i) + 1, N}); ++l) {

int jp = j;
int ip = l;
I[i][j][k][l][s] += I[ip][jp][kp][lp][sp];
}
}
}
}
}
for (int i = 0; i < N; ++i) {

int kp = i;
for (int j = 0; j < N; ++j) {

for (int l = max({j, 0}); l < min({(i) + 1, N}); ++l) {

int jp = j;
int ip = l;
for (int k = 0; k < N; ++k) {

for (int s = max({i, 0}); s < min({(k) + 1, N}); ++s) {

int lp = k;
int sp = s;
I[i][j][k][l][s] += I[ip][jp][kp][lp][sp];
}
}
}
}
}
for (int i = 0; i < N; ++i) {

int ip = i;
for (int j = 0; j < N; ++j) {

int jp = j;
for (int k = 0; k < N; ++k) {

for (int s = max({j, 0}); s < min({(k) + 1, N}); ++s) {

for (int l = max({k, 0}); l < min({(i) + 1, N}); ++l) {

int sp = k;
int lp = s;
int kp = l;
I[i][j][k][l][s] += I[ip][jp][kp][lp][sp];
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int l = max({i, 0}); l < N; ++l) {

int lp = i;
for (int k = 0; k < min({(i) + 1, N}); ++k) {

int kp = l;
int sp = k;
for (int j = 0; j < N; ++j) {

for (int s = max({j, 0}); s < min({(k) + 1, N}); ++s) {

int jp = j;
int ip = s;
I[i][j][k][l][s] += I[ip][jp][kp][lp][sp];
}
}
}
}
}
for (int i = 0; i < N; ++i) {

int ip = i;
for (int k = 0; k < min({(i) + 1, N}); ++k) {

for (int l = 0; l < min({(k) + 1, N}); ++l) {

int sp = k;
int lp = l;
for (int j = 0; j < N; ++j) {

for (int s = max({j, 0}); s < min({(l) + 1, N}); ++s) {

int jp = j;
int kp = s;
I[i][j][k][l][s] += I[ip][jp][kp][lp][sp];
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int l = 0; l < min({(i) + 1, N}); ++l) {

int kp = i;
for (int k = max({i, 0}); k < N; ++k) {

int lp = l;
int sp = k;
for (int j = 0; j < N; ++j) {

for (int s = max({j, 0}); s < min({(l) + 1, N}); ++s) {

int jp = j;
int ip = s;
I[i][j][k][l][s] += I[ip][jp][kp][lp][sp];
}
}
}
}
}
for (int i = 0; i < N; ++i) {

int lp = i;
for (int k = max({i, 0}); k < N; ++k) {

for (int l = max({k, 0}); l < N; ++l) {

int sp = k;
int ip = l;
for (int j = 0; j < N; ++j) {

for (int s = max({j, 0}); s < min({(i) + 1, N}); ++s) {

int jp = j;
int kp = s;
I[i][j][k][l][s] += I[ip][jp][kp][lp][sp];
}
}
}
}
}
for (int i = 0; i < N; ++i) {

int kp = i;
for (int j = 0; j < N; ++j) {

for (int s = max({j, 0}); s < min({(i) + 1, N}); ++s) {

int jp = j;
int lp = s;
for (int k = 0; k < N; ++k) {

for (int l = max({i, 0}); l < min({(k) + 1, N}); ++l) {

int sp = k;
int ip = l;
I[i][j][k][l][s] += I[ip][jp][kp][lp][sp];
}
}
}
}
}
for (int i = 0; i < N; ++i) {

int sp = i;
for (int j = 0; j < min({(i) + 1, N}); ++j) {

for (int k = max({i, 0}); k < N; ++k) {

int jp = j;
for (int l = max({k, 0}); l < N; ++l) {

int ip = k;
for (int s = max({l, 0}); s < N; ++s) {

int kp = l;
int lp = s;
I[i][j][k][l][s] += I[ip][jp][kp][lp][sp];
}
}
}
}
}
for (int i = 0; i < N; ++i) {

int lp = i;
for (int j = 0; j < min({(i) + 1, N}); ++j) {

for (int k = max({i, 0}); k < N; ++k) {

int jp = j;
int ip = k;
for (int l = 0; l < N; ++l) {

for (int s = max({k, 0}); s < min({(l) + 1, N}); ++s) {

int kp = l;
int sp = s;
I[i][j][k][l][s] += I[ip][jp][kp][lp][sp];
}
}
}
}
}
for (int i = 0; i < N; ++i) {

int sp = i;
for (int j = 0; j < min({(i) + 1, N}); ++j) {

int jp = j;
for (int k = 0; k < N; ++k) {

for (int s = max({k, 0}); s < N; ++s) {

for (int l = max({i, 0}); l < min({(k) + 1, N}); ++l) {

int ip = k;
int kp = s;
int lp = l;
I[i][j][k][l][s] += I[ip][jp][kp][lp][sp];
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int l = max({i, 0}); l < N; ++l) {

int kp = i;
for (int j = 0; j < min({(i) + 1, N}); ++j) {

int lp = l;
int jp = j;
for (int k = 0; k < N; ++k) {

for (int s = max({l, 0}); s < min({(k) + 1, N}); ++s) {

int ip = k;
int sp = s;
I[i][j][k][l][s] += I[ip][jp][kp][lp][sp];
}
}
}
}
}
for (int i = 0; i < N; ++i) {

int lp = i;
for (int j = 0; j < min({(i) + 1, N}); ++j) {

int jp = j;
for (int k = 0; k < N; ++k) {

for (int s = max({i, 0}); s < min({(k) + 1, N}); ++s) {

for (int l = max({k, 0}); l < N; ++l) {

int ip = k;
int kp = s;
int sp = l;
I[i][j][k][l][s] += I[ip][jp][kp][lp][sp];
}
}
}
}
}
for (int i = 0; i < N; ++i) {

int kp = i;
for (int j = 0; j < min({(i) + 1, N}); ++j) {

int jp = j;
for (int k = 0; k < N; ++k) {

for (int l = 0; l < min({(k) + 1, N}); ++l) {

int ip = k;
for (int s = max({i, 0}); s < min({(l) + 1, N}); ++s) {

int sp = l;
int lp = s;
I[i][j][k][l][s] += I[ip][jp][kp][lp][sp];
}
}
}
}
}
for (int i = 0; i < N; ++i) {

int ip = i;
for (int j = 0; j < N; ++j) {

for (int l = max({j, 0}); l < N; ++l) {

int kp = j;
for (int k = 0; k < min({(j) + 1, N}); ++k) {

for (int s = max({l, 0}); s < min({(i) + 1, N}); ++s) {

int lp = l;
int jp = k;
int sp = s;
I[i][j][k][l][s] += I[ip][jp][kp][lp][sp];
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int s = max({i, 0}); s < N; ++s) {

int sp = i;
int ip = s;
for (int j = 0; j < N; ++j) {

for (int l = max({j, 0}); l < min({(i) + 1, N}); ++l) {

int kp = j;
for (int k = 0; k < min({(j) + 1, N}); ++k) {

int lp = l;
int jp = k;
I[i][j][k][l][s] += I[ip][jp][kp][lp][sp];
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int l = 0; l < min({(i) + 1, N}); ++l) {

int ip = i;
int sp = l;
for (int j = 0; j < N; ++j) {

for (int s = max({j, 0}); s < min({(l) + 1, N}); ++s) {

int kp = j;
for (int k = 0; k < min({(j) + 1, N}); ++k) {

int lp = s;
int jp = k;
I[i][j][k][l][s] += I[ip][jp][kp][lp][sp];
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int l = max({i, 0}); l < N; ++l) {

int lp = i;
int sp = l;
for (int j = 0; j < N; ++j) {

for (int s = max({j, 0}); s < min({(i) + 1, N}); ++s) {

int kp = j;
for (int k = 0; k < min({(j) + 1, N}); ++k) {

int ip = s;
int jp = k;
I[i][j][k][l][s] += I[ip][jp][kp][lp][sp];
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int l = max({i, 0}); l < N; ++l) {

int sp = i;
for (int j = 0; j < min({(i) + 1, N}); ++j) {

for (int s = max({l, 0}); s < N; ++s) {

int ip = l;
int kp = j;
for (int k = 0; k < min({(j) + 1, N}); ++k) {

int lp = s;
int jp = k;
I[i][j][k][l][s] += I[ip][jp][kp][lp][sp];
}
}
}
}
}
for (int i = 0; i < N; ++i) {

int lp = i;
for (int j = 0; j < min({(i) + 1, N}); ++j) {

int kp = j;
for (int k = 0; k < min({(j) + 1, N}); ++k) {

for (int l = 0; l < N; ++l) {

int jp = k;
for (int s = max({i, 0}); s < min({(l) + 1, N}); ++s) {

int ip = l;
int sp = s;
I[i][j][k][l][s] += I[ip][jp][kp][lp][sp];
}
}
}
}
}
for (int i = 0; i < N; ++i) {

int ip = i;
for (int j = 0; j < N; ++j) {

for (int s = max({j, 0}); s < min({(i) + 1, N}); ++s) {

int kp = j;
int sp = s;
for (int k = 0; k < N; ++k) {

for (int l = max({k, 0}); l < min({(j) + 1, N}); ++l) {

int lp = k;
int jp = l;
I[i][j][k][l][s] += I[ip][jp][kp][lp][sp];
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int s = max({i, 0}); s < N; ++s) {

int sp = i;
for (int j = 0; j < min({(i) + 1, N}); ++j) {

int ip = s;
int kp = j;
for (int k = 0; k < N; ++k) {

for (int l = max({k, 0}); l < min({(j) + 1, N}); ++l) {

int lp = k;
int jp = l;
I[i][j][k][l][s] += I[ip][jp][kp][lp][sp];
}
}
}
}
}
for (int i = 0; i < N; ++i) {

int ip = i;
for (int j = 0; j < min({(i) + 1, N}); ++j) {

int kp = j;
for (int k = 0; k < N; ++k) {

for (int l = max({k, 0}); l < N; ++l) {

int lp = k;
for (int s = max({l, 0}); s < min({(j) + 1, N}); ++s) {

int sp = l;
int jp = s;
I[i][j][k][l][s] += I[ip][jp][kp][lp][sp];
}
}
}
}
}
for (int i = 0; i < N; ++i) {

int jp = i;
for (int j = max({i, 0}); j < N; ++j) {

int kp = j;
for (int k = 0; k < N; ++k) {

for (int l = max({k, 0}); l < N; ++l) {

int lp = k;
for (int s = max({l, 0}); s < min({(i) + 1, N}); ++s) {

int sp = l;
int ip = s;
I[i][j][k][l][s] += I[ip][jp][kp][lp][sp];
}
}
}
}
}
for (int i = 0; i < N; ++i) {

int sp = i;
for (int j = max({i, 0}); j < N; ++j) {

for (int s = max({j, 0}); s < N; ++s) {

int kp = j;
int jp = s;
for (int k = 0; k < N; ++k) {

for (int l = max({k, 0}); l < min({(i) + 1, N}); ++l) {

int lp = k;
int ip = l;
I[i][j][k][l][s] += I[ip][jp][kp][lp][sp];
}
}
}
}
}
for (int i = 0; i < N; ++i) {

int jp = i;
for (int j = 0; j < N; ++j) {

for (int s = max({i, 0}); s < min({(j) + 1, N}); ++s) {

int kp = j;
int sp = s;
for (int k = 0; k < N; ++k) {

for (int l = max({k, 0}); l < min({(i) + 1, N}); ++l) {

int lp = k;
int ip = l;
I[i][j][k][l][s] += I[ip][jp][kp][lp][sp];
}
}
}
}
}
for (int i = 0; i < N; ++i) {

int ip = i;
for (int j = 0; j < N; ++j) {

for (int l = max({j, 0}); l < min({(i) + 1, N}); ++l) {

int kp = j;
int jp = l;
for (int k = 0; k < N; ++k) {

for (int s = max({k, 0}); s < min({(j) + 1, N}); ++s) {

int sp = k;
int lp = s;
I[i][j][k][l][s] += I[ip][jp][kp][lp][sp];
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int l = max({i, 0}); l < N; ++l) {

int lp = i;
for (int j = 0; j < min({(i) + 1, N}); ++j) {

int jp = l;
int kp = j;
for (int k = 0; k < N; ++k) {

for (int s = max({k, 0}); s < min({(j) + 1, N}); ++s) {

int sp = k;
int ip = s;
I[i][j][k][l][s] += I[ip][jp][kp][lp][sp];
}
}
}
}
}
for (int i = 0; i < N; ++i) {

int ip = i;
for (int j = 0; j < min({(i) + 1, N}); ++j) {

for (int l = 0; l < min({(j) + 1, N}); ++l) {

int kp = j;
int lp = l;
for (int k = 0; k < N; ++k) {

for (int s = max({k, 0}); s < min({(l) + 1, N}); ++s) {

int sp = k;
int jp = s;
I[i][j][k][l][s] += I[ip][jp][kp][lp][sp];
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int l = 0; l < min({(i) + 1, N}); ++l) {

int jp = i;
for (int j = max({i, 0}); j < N; ++j) {

int lp = l;
int kp = j;
for (int k = 0; k < N; ++k) {

for (int s = max({k, 0}); s < min({(l) + 1, N}); ++s) {

int sp = k;
int ip = s;
I[i][j][k][l][s] += I[ip][jp][kp][lp][sp];
}
}
}
}
}
for (int i = 0; i < N; ++i) {

int lp = i;
for (int j = max({i, 0}); j < N; ++j) {

for (int l = max({j, 0}); l < N; ++l) {

int kp = j;
int ip = l;
for (int k = 0; k < N; ++k) {

for (int s = max({k, 0}); s < min({(i) + 1, N}); ++s) {

int sp = k;
int jp = s;
I[i][j][k][l][s] += I[ip][jp][kp][lp][sp];
}
}
}
}
}
for (int i = 0; i < N; ++i) {

int jp = i;
for (int j = 0; j < N; ++j) {

for (int l = max({i, 0}); l < min({(j) + 1, N}); ++l) {

int kp = j;
int ip = l;
for (int k = 0; k < N; ++k) {

for (int s = max({k, 0}); s < min({(i) + 1, N}); ++s) {

int sp = k;
int lp = s;
I[i][j][k][l][s] += I[ip][jp][kp][lp][sp];
}
}
}
}
}
for (int i = 0; i < N; ++i) {

int sp = i;
for (int j = max({i, 0}); j < N; ++j) {

for (int k = 0; k < min({(i) + 1, N}); ++k) {

for (int l = max({j, 0}); l < N; ++l) {

int kp = j;
int ip = k;
for (int s = max({l, 0}); s < N; ++s) {

int jp = l;
int lp = s;
I[i][j][k][l][s] += I[ip][jp][kp][lp][sp];
}
}
}
}
}
for (int i = 0; i < N; ++i) {

int lp = i;
for (int j = max({i, 0}); j < N; ++j) {

for (int k = 0; k < min({(i) + 1, N}); ++k) {

int kp = j;
int ip = k;
for (int l = 0; l < N; ++l) {

for (int s = max({j, 0}); s < min({(l) + 1, N}); ++s) {

int jp = l;
int sp = s;
I[i][j][k][l][s] += I[ip][jp][kp][lp][sp];
}
}
}
}
}
for (int i = 0; i < N; ++i) {

int sp = i;
for (int k = 0; k < min({(i) + 1, N}); ++k) {

int ip = k;
for (int j = 0; j < N; ++j) {

for (int s = max({j, 0}); s < N; ++s) {

for (int l = max({i, 0}); l < min({(j) + 1, N}); ++l) {

int kp = j;
int jp = s;
int lp = l;
I[i][j][k][l][s] += I[ip][jp][kp][lp][sp];
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int l = max({i, 0}); l < N; ++l) {

int jp = i;
for (int k = 0; k < min({(i) + 1, N}); ++k) {

int lp = l;
int ip = k;
for (int j = 0; j < N; ++j) {

for (int s = max({l, 0}); s < min({(j) + 1, N}); ++s) {

int kp = j;
int sp = s;
I[i][j][k][l][s] += I[ip][jp][kp][lp][sp];
}
}
}
}
}
for (int i = 0; i < N; ++i) {

int lp = i;
for (int k = 0; k < min({(i) + 1, N}); ++k) {

int ip = k;
for (int j = 0; j < N; ++j) {

for (int s = max({i, 0}); s < min({(j) + 1, N}); ++s) {

for (int l = max({j, 0}); l < N; ++l) {

int kp = j;
int jp = s;
int sp = l;
I[i][j][k][l][s] += I[ip][jp][kp][lp][sp];
}
}
}
}
}
for (int i = 0; i < N; ++i) {

int jp = i;
for (int k = 0; k < min({(i) + 1, N}); ++k) {

int ip = k;
for (int j = 0; j < N; ++j) {

for (int l = 0; l < min({(j) + 1, N}); ++l) {

int kp = j;
for (int s = max({i, 0}); s < min({(l) + 1, N}); ++s) {

int sp = l;
int lp = s;
I[i][j][k][l][s] += I[ip][jp][kp][lp][sp];
}
}
}
}
}
for (int i = 0; i < N; ++i) {

int ip = i;
for (int j = 0; j < N; ++j) {

for (int l = 0; l < min({(j) + 1, N}); ++l) {

int lp = j;
for (int k = max({j, 0}); k < N; ++k) {

int kp = l;
for (int s = max({k, 0}); s < min({(i) + 1, N}); ++s) {

int jp = k;
int sp = s;
I[i][j][k][l][s] += I[ip][jp][kp][lp][sp];
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int s = max({i, 0}); s < N; ++s) {

int sp = i;
int ip = s;
for (int j = 0; j < N; ++j) {

for (int l = 0; l < min({(j) + 1, N}); ++l) {

int lp = j;
for (int k = max({j, 0}); k < min({(i) + 1, N}); ++k) {

int kp = l;
int jp = k;
I[i][j][k][l][s] += I[ip][jp][kp][lp][sp];
}
}
}
}
}
for (int i = 0; i < N; ++i) {

int ip = i;
for (int k = 0; k < min({(i) + 1, N}); ++k) {

int jp = k;
for (int j = 0; j < N; ++j) {

for (int s = max({j, 0}); s < min({(k) + 1, N}); ++s) {

for (int l = 0; l < min({(j) + 1, N}); ++l) {

int lp = j;
int kp = s;
int sp = l;
I[i][j][k][l][s] += I[ip][jp][kp][lp][sp];
}
}
}
}
}
for (int i = 0; i < N; ++i) {

int kp = i;
for (int k = max({i, 0}); k < N; ++k) {

int jp = k;
for (int j = 0; j < N; ++j) {

for (int s = max({j, 0}); s < min({(i) + 1, N}); ++s) {

for (int l = 0; l < min({(j) + 1, N}); ++l) {

int lp = j;
int ip = s;
int sp = l;
I[i][j][k][l][s] += I[ip][jp][kp][lp][sp];
}
}
}
}
}
for (int i = 0; i < N; ++i) {

int sp = i;
for (int j = 0; j < min({(i) + 1, N}); ++j) {

for (int k = max({i, 0}); k < N; ++k) {

for (int l = 0; l < min({(j) + 1, N}); ++l) {

int lp = j;
for (int s = max({k, 0}); s < N; ++s) {

int jp = k;
int ip = l;
int kp = s;
I[i][j][k][l][s] += I[ip][jp][kp][lp][sp];
}
}
}
}
}
for (int i = 0; i < N; ++i) {

int kp = i;
for (int j = 0; j < min({(i) + 1, N}); ++j) {

for (int l = 0; l < min({(j) + 1, N}); ++l) {

int lp = j;
int ip = l;
for (int k = 0; k < N; ++k) {

for (int s = max({i, 0}); s < min({(k) + 1, N}); ++s) {

int jp = k;
int sp = s;
I[i][j][k][l][s] += I[ip][jp][kp][lp][sp];
}
}
}
}
}
for (int i = 0; i < N; ++i) {

int ip = i;
for (int j = 0; j < N; ++j) {

for (int s = max({j, 0}); s < min({(i) + 1, N}); ++s) {

int lp = j;
for (int k = 0; k < min({(j) + 1, N}); ++k) {

int sp = s;
for (int l = 0; l < min({(k) + 1, N}); ++l) {

int kp = k;
int jp = l;
I[i][j][k][l][s] += I[ip][jp][kp][lp][sp];
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int s = max({i, 0}); s < N; ++s) {

int sp = i;
for (int j = 0; j < min({(i) + 1, N}); ++j) {

int ip = s;
int lp = j;
for (int k = 0; k < min({(j) + 1, N}); ++k) {

for (int l = 0; l < min({(k) + 1, N}); ++l) {

int kp = k;
int jp = l;
I[i][j][k][l][s] += I[ip][jp][kp][lp][sp];
}
}
}
}
}
for (int i = 0; i < N; ++i) {

int ip = i;
for (int j = 0; j < min({(i) + 1, N}); ++j) {

int lp = j;
for (int k = 0; k < N; ++k) {

for (int s = max({k, 0}); s < min({(j) + 1, N}); ++s) {

for (int l = 0; l < min({(k) + 1, N}); ++l) {

int kp = k;
int jp = s;
int sp = l;
I[i][j][k][l][s] += I[ip][jp][kp][lp][sp];
}
}
}
}
}
for (int i = 0; i < N; ++i) {

int jp = i;
for (int j = max({i, 0}); j < N; ++j) {

int lp = j;
for (int k = 0; k < N; ++k) {

for (int s = max({k, 0}); s < min({(i) + 1, N}); ++s) {

for (int l = 0; l < min({(k) + 1, N}); ++l) {

int kp = k;
int ip = s;
int sp = l;
I[i][j][k][l][s] += I[ip][jp][kp][lp][sp];
}
}
}
}
}
for (int i = 0; i < N; ++i) {

int sp = i;
for (int j = max({i, 0}); j < N; ++j) {

for (int k = 0; k < min({(i) + 1, N}); ++k) {

for (int s = max({j, 0}); s < N; ++s) {

int lp = j;
for (int l = 0; l < min({(k) + 1, N}); ++l) {

int kp = k;
int jp = s;
int ip = l;
I[i][j][k][l][s] += I[ip][jp][kp][lp][sp];
}
}
}
}
}
for (int i = 0; i < N; ++i) {

int jp = i;
for (int k = 0; k < min({(i) + 1, N}); ++k) {

for (int l = 0; l < min({(k) + 1, N}); ++l) {

int kp = k;
int ip = l;
for (int j = 0; j < N; ++j) {

for (int s = max({i, 0}); s < min({(j) + 1, N}); ++s) {

int lp = j;
int sp = s;
I[i][j][k][l][s] += I[ip][jp][kp][lp][sp];
}
}
}
}
}
for (int i = 0; i < N; ++i) {

int ip = i;
for (int j = 0; j < N; ++j) {

int lp = j;
for (int k = max({j, 0}); k < min({(i) + 1, N}); ++k) {

for (int l = 0; l < N; ++l) {

int sp = k;
for (int s = max({l, 0}); s < min({(j) + 1, N}); ++s) {

int jp = l;
int kp = s;
I[i][j][k][l][s] += I[ip][jp][kp][lp][sp];
}
}
}
}
}
for (int i = 0; i < N; ++i) {

int kp = i;
for (int j = 0; j < min({(i) + 1, N}); ++j) {

for (int k = max({i, 0}); k < N; ++k) {

int lp = j;
int sp = k;
for (int l = 0; l < N; ++l) {

for (int s = max({l, 0}); s < min({(j) + 1, N}); ++s) {

int jp = l;
int ip = s;
I[i][j][k][l][s] += I[ip][jp][kp][lp][sp];
}
}
}
}
}
for (int i = 0; i < N; ++i) {

int ip = i;
for (int j = 0; j < min({(i) + 1, N}); ++j) {

int lp = j;
for (int k = 0; k < min({(j) + 1, N}); ++k) {

for (int l = 0; l < N; ++l) {

int sp = k;
for (int s = max({l, 0}); s < min({(k) + 1, N}); ++s) {

int kp = l;
int jp = s;
I[i][j][k][l][s] += I[ip][jp][kp][lp][sp];
}
}
}
}
}
for (int i = 0; i < N; ++i) {

int jp = i;
for (int j = max({i, 0}); j < N; ++j) {

for (int k = 0; k < min({(i) + 1, N}); ++k) {

int lp = j;
int sp = k;
for (int l = 0; l < N; ++l) {

for (int s = max({l, 0}); s < min({(k) + 1, N}); ++s) {

int kp = l;
int ip = s;
I[i][j][k][l][s] += I[ip][jp][kp][lp][sp];
}
}
}
}
}
for (int i = 0; i < N; ++i) {

int kp = i;
for (int j = max({i, 0}); j < N; ++j) {

int lp = j;
for (int k = max({j, 0}); k < N; ++k) {

for (int l = 0; l < N; ++l) {

int sp = k;
for (int s = max({l, 0}); s < min({(i) + 1, N}); ++s) {

int ip = l;
int jp = s;
I[i][j][k][l][s] += I[ip][jp][kp][lp][sp];
}
}
}
}
}
for (int i = 0; i < N; ++i) {

int jp = i;
for (int j = 0; j < N; ++j) {

int lp = j;
for (int k = max({i, 0}); k < min({(j) + 1, N}); ++k) {

for (int l = 0; l < N; ++l) {

int sp = k;
for (int s = max({l, 0}); s < min({(i) + 1, N}); ++s) {

int ip = l;
int kp = s;
I[i][j][k][l][s] += I[ip][jp][kp][lp][sp];
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int l = 0; l < min({(i) + 1, N}); ++l) {

int sp = i;
for (int j = max({i, 0}); j < N; ++j) {

int jp = l;
int lp = j;
for (int k = max({j, 0}); k < N; ++k) {

for (int s = max({k, 0}); s < N; ++s) {

int ip = k;
int kp = s;
I[i][j][k][l][s] += I[ip][jp][kp][lp][sp];
}
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
for (int k = 0; k < N; ++k) {

for (int s = max({j, 0}); s < min({(k) + 1, N}); ++s) {

int ip = k;
int sp = s;
I[i][j][k][l][s] += I[ip][jp][kp][lp][sp];
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int l = 0; l < min({(i) + 1, N}); ++l) {

int sp = i;
int kp = l;
for (int j = 0; j < N; ++j) {

for (int s = max({j, 0}); s < N; ++s) {

int lp = j;
for (int k = max({i, 0}); k < min({(j) + 1, N}); ++k) {

int jp = s;
int ip = k;
I[i][j][k][l][s] += I[ip][jp][kp][lp][sp];
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int l = 0; l < min({(i) + 1, N}); ++l) {

int jp = i;
for (int k = max({i, 0}); k < N; ++k) {

int kp = l;
int ip = k;
for (int j = 0; j < N; ++j) {

for (int s = max({k, 0}); s < min({(j) + 1, N}); ++s) {

int lp = j;
int sp = s;
I[i][j][k][l][s] += I[ip][jp][kp][lp][sp];
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int l = 0; l < min({(i) + 1, N}); ++l) {

int kp = i;
int sp = l;
for (int j = 0; j < N; ++j) {

for (int s = max({i, 0}); s < min({(j) + 1, N}); ++s) {

int lp = j;
for (int k = max({j, 0}); k < N; ++k) {

int jp = s;
int ip = k;
I[i][j][k][l][s] += I[ip][jp][kp][lp][sp];
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int l = 0; l < min({(i) + 1, N}); ++l) {

int jp = i;
int sp = l;
for (int j = 0; j < N; ++j) {

int lp = j;
for (int k = 0; k < min({(j) + 1, N}); ++k) {

for (int s = max({i, 0}); s < min({(k) + 1, N}); ++s) {

int ip = k;
int kp = s;
I[i][j][k][l][s] += I[ip][jp][kp][lp][sp];
}
}
}
}
}
for (int i = 0; i < N; ++i) {

int ip = i;
for (int j = 0; j < N; ++j) {

for (int s = 0; s < min({(j) + 1, N}); ++s) {

int sp = j;
for (int k = max({j, 0}); k < N; ++k) {

int lp = s;
for (int l = max({k, 0}); l < min({(i) + 1, N}); ++l) {

int jp = k;
int kp = l;
I[i][j][k][l][s] += I[ip][jp][kp][lp][sp];
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int l = max({i, 0}); l < N; ++l) {

int lp = i;
int kp = l;
for (int j = 0; j < N; ++j) {

for (int s = 0; s < min({(j) + 1, N}); ++s) {

int sp = j;
for (int k = max({j, 0}); k < min({(i) + 1, N}); ++k) {

int ip = s;
int jp = k;
I[i][j][k][l][s] += I[ip][jp][kp][lp][sp];
}
}
}
}
}
for (int i = 0; i < N; ++i) {

int ip = i;
for (int k = 0; k < min({(i) + 1, N}); ++k) {

int jp = k;
for (int j = 0; j < N; ++j) {

for (int s = 0; s < min({(j) + 1, N}); ++s) {

for (int l = max({j, 0}); l < min({(k) + 1, N}); ++l) {

int sp = j;
int kp = s;
int lp = l;
I[i][j][k][l][s] += I[ip][jp][kp][lp][sp];
}
}
}
}
}
for (int i = 0; i < N; ++i) {

int kp = i;
for (int k = max({i, 0}); k < N; ++k) {

int jp = k;
for (int j = 0; j < N; ++j) {

for (int s = 0; s < min({(j) + 1, N}); ++s) {

for (int l = max({j, 0}); l < min({(i) + 1, N}); ++l) {

int sp = j;
int ip = s;
int lp = l;
I[i][j][k][l][s] += I[ip][jp][kp][lp][sp];
}
}
}
}
}
for (int i = 0; i < N; ++i) {

int lp = i;
for (int j = 0; j < min({(i) + 1, N}); ++j) {

for (int k = max({i, 0}); k < N; ++k) {

for (int s = 0; s < min({(j) + 1, N}); ++s) {

int sp = j;
for (int l = max({k, 0}); l < N; ++l) {

int jp = k;
int kp = s;
int ip = l;
I[i][j][k][l][s] += I[ip][jp][kp][lp][sp];
}
}
}
}
}
for (int i = 0; i < N; ++i) {

int kp = i;
for (int j = 0; j < min({(i) + 1, N}); ++j) {

for (int s = 0; s < min({(j) + 1, N}); ++s) {

int sp = j;
int lp = s;
for (int k = 0; k < N; ++k) {

for (int l = max({i, 0}); l < min({(k) + 1, N}); ++l) {

int jp = k;
int ip = l;
I[i][j][k][l][s] += I[ip][jp][kp][lp][sp];
}
}
}
}
}
for (int i = 0; i < N; ++i) {

int ip = i;
for (int j = 0; j < N; ++j) {

for (int l = max({j, 0}); l < min({(i) + 1, N}); ++l) {

int sp = j;
for (int k = 0; k < min({(j) + 1, N}); ++k) {

int jp = l;
for (int s = 0; s < min({(k) + 1, N}); ++s) {

int kp = k;
int lp = s;
I[i][j][k][l][s] += I[ip][jp][kp][lp][sp];
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int l = max({i, 0}); l < N; ++l) {

int lp = i;
for (int j = 0; j < min({(i) + 1, N}); ++j) {

int jp = l;
int sp = j;
for (int k = 0; k < min({(j) + 1, N}); ++k) {

for (int s = 0; s < min({(k) + 1, N}); ++s) {

int kp = k;
int ip = s;
I[i][j][k][l][s] += I[ip][jp][kp][lp][sp];
}
}
}
}
}
for (int i = 0; i < N; ++i) {

int ip = i;
for (int j = 0; j < min({(i) + 1, N}); ++j) {

int sp = j;
for (int k = 0; k < N; ++k) {

for (int s = 0; s < min({(k) + 1, N}); ++s) {

for (int l = max({k, 0}); l < min({(j) + 1, N}); ++l) {

int kp = k;
int jp = s;
int lp = l;
I[i][j][k][l][s] += I[ip][jp][kp][lp][sp];
}
}
}
}
}
for (int i = 0; i < N; ++i) {

int jp = i;
for (int j = max({i, 0}); j < N; ++j) {

int sp = j;
for (int k = 0; k < N; ++k) {

for (int s = 0; s < min({(k) + 1, N}); ++s) {

for (int l = max({k, 0}); l < min({(i) + 1, N}); ++l) {

int kp = k;
int ip = s;
int lp = l;
I[i][j][k][l][s] += I[ip][jp][kp][lp][sp];
}
}
}
}
}
for (int i = 0; i < N; ++i) {

int lp = i;
for (int j = max({i, 0}); j < N; ++j) {

for (int k = 0; k < min({(i) + 1, N}); ++k) {

for (int l = max({j, 0}); l < N; ++l) {

int sp = j;
for (int s = 0; s < min({(k) + 1, N}); ++s) {

int kp = k;
int ip = l;
int jp = s;
I[i][j][k][l][s] += I[ip][jp][kp][lp][sp];
}
}
}
}
}
for (int i = 0; i < N; ++i) {

int jp = i;
for (int k = 0; k < min({(i) + 1, N}); ++k) {

for (int s = 0; s < min({(k) + 1, N}); ++s) {

int kp = k;
int lp = s;
for (int j = 0; j < N; ++j) {

for (int l = max({i, 0}); l < min({(j) + 1, N}); ++l) {

int sp = j;
int ip = l;
I[i][j][k][l][s] += I[ip][jp][kp][lp][sp];
}
}
}
}
}
for (int i = 0; i < N; ++i) {

int ip = i;
for (int j = 0; j < N; ++j) {

for (int l = 0; l < min({(j) + 1, N}); ++l) {

int sp = j;
for (int k = max({j, 0}); k < min({(i) + 1, N}); ++k) {

for (int s = 0; s < min({(l) + 1, N}); ++s) {

int jp = l;
int lp = k;
int kp = s;
I[i][j][k][l][s] += I[ip][jp][kp][lp][sp];
}
}
}
}
}
for (int i = 0; i < N; ++i) {

int kp = i;
for (int j = 0; j < min({(i) + 1, N}); ++j) {

for (int k = max({i, 0}); k < N; ++k) {

for (int l = 0; l < min({(j) + 1, N}); ++l) {

int sp = j;
int lp = k;
for (int s = 0; s < min({(l) + 1, N}); ++s) {

int jp = l;
int ip = s;
I[i][j][k][l][s] += I[ip][jp][kp][lp][sp];
}
}
}
}
}
for (int i = 0; i < N; ++i) {

int ip = i;
for (int j = 0; j < min({(i) + 1, N}); ++j) {

int sp = j;
for (int k = 0; k < min({(j) + 1, N}); ++k) {

for (int l = 0; l < min({(k) + 1, N}); ++l) {

int lp = k;
for (int s = 0; s < min({(l) + 1, N}); ++s) {

int kp = l;
int jp = s;
I[i][j][k][l][s] += I[ip][jp][kp][lp][sp];
}
}
}
}
}
for (int i = 0; i < N; ++i) {

int jp = i;
for (int j = max({i, 0}); j < N; ++j) {

for (int k = 0; k < min({(i) + 1, N}); ++k) {

int sp = j;
for (int l = 0; l < min({(k) + 1, N}); ++l) {

int lp = k;
for (int s = 0; s < min({(l) + 1, N}); ++s) {

int kp = l;
int ip = s;
I[i][j][k][l][s] += I[ip][jp][kp][lp][sp];
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int l = 0; l < min({(i) + 1, N}); ++l) {

int kp = i;
for (int j = max({i, 0}); j < N; ++j) {

for (int s = 0; s < min({(l) + 1, N}); ++s) {

int ip = l;
int sp = j;
for (int k = max({j, 0}); k < N; ++k) {

int jp = s;
int lp = k;
I[i][j][k][l][s] += I[ip][jp][kp][lp][sp];
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int l = 0; l < min({(i) + 1, N}); ++l) {

int jp = i;
for (int s = 0; s < min({(l) + 1, N}); ++s) {

int ip = l;
int kp = s;
for (int j = 0; j < N; ++j) {

int sp = j;
for (int k = max({i, 0}); k < min({(j) + 1, N}); ++k) {

int lp = k;
I[i][j][k][l][s] += I[ip][jp][kp][lp][sp];
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int s = 0; s < min({(i) + 1, N}); ++s) {

int lp = i;
for (int j = max({i, 0}); j < N; ++j) {

int kp = s;
int sp = j;
for (int k = max({j, 0}); k < N; ++k) {

for (int l = max({k, 0}); l < N; ++l) {

int ip = k;
int jp = l;
I[i][j][k][l][s] += I[ip][jp][kp][lp][sp];
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int s = 0; s < min({(i) + 1, N}); ++s) {

int kp = i;
for (int j = max({i, 0}); j < N; ++j) {

int lp = s;
int sp = j;
for (int k = 0; k < N; ++k) {

for (int l = max({j, 0}); l < min({(k) + 1, N}); ++l) {

int ip = k;
int jp = l;
I[i][j][k][l][s] += I[ip][jp][kp][lp][sp];
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int s = 0; s < min({(i) + 1, N}); ++s) {

int lp = i;
int jp = s;
for (int j = 0; j < N; ++j) {

for (int l = max({j, 0}); l < N; ++l) {

int sp = j;
for (int k = max({i, 0}); k < min({(j) + 1, N}); ++k) {

int kp = l;
int ip = k;
I[i][j][k][l][s] += I[ip][jp][kp][lp][sp];
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int s = 0; s < min({(i) + 1, N}); ++s) {

int jp = i;
for (int k = max({i, 0}); k < N; ++k) {

int lp = s;
int ip = k;
for (int j = 0; j < N; ++j) {

for (int l = max({k, 0}); l < min({(j) + 1, N}); ++l) {

int sp = j;
int kp = l;
I[i][j][k][l][s] += I[ip][jp][kp][lp][sp];
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int s = 0; s < min({(i) + 1, N}); ++s) {

int kp = i;
int jp = s;
for (int j = 0; j < N; ++j) {

for (int l = max({i, 0}); l < min({(j) + 1, N}); ++l) {

int sp = j;
for (int k = max({j, 0}); k < N; ++k) {

int lp = l;
int ip = k;
I[i][j][k][l][s] += I[ip][jp][kp][lp][sp];
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int s = 0; s < min({(i) + 1, N}); ++s) {

int jp = i;
int kp = s;
for (int j = 0; j < N; ++j) {

int sp = j;
for (int k = 0; k < min({(j) + 1, N}); ++k) {

for (int l = max({i, 0}); l < min({(k) + 1, N}); ++l) {

int ip = k;
int lp = l;
I[i][j][k][l][s] += I[ip][jp][kp][lp][sp];
}
}
}
}
}
for (int i = 0; i < N; ++i) {

int sp = i;
for (int j = max({i, 0}); j < N; ++j) {

int ip = j;
for (int k = max({j, 0}); k < N; ++k) {

for (int l = max({k, 0}); l < N; ++l) {

int jp = k;
for (int s = max({l, 0}); s < N; ++s) {

int kp = l;
int lp = s;
I[i][j][k][l][s] += I[ip][jp][kp][lp][sp];
}
}
}
}
}
for (int i = 0; i < N; ++i) {

int lp = i;
for (int j = max({i, 0}); j < N; ++j) {

int ip = j;
for (int k = max({j, 0}); k < N; ++k) {

for (int l = 0; l < N; ++l) {

int jp = k;
for (int s = max({k, 0}); s < min({(l) + 1, N}); ++s) {

int kp = l;
int sp = s;
I[i][j][k][l][s] += I[ip][jp][kp][lp][sp];
}
}
}
}
}
for (int i = 0; i < N; ++i) {

int sp = i;
for (int j = max({i, 0}); j < N; ++j) {

int ip = j;
for (int k = 0; k < N; ++k) {

for (int s = max({k, 0}); s < N; ++s) {

for (int l = max({j, 0}); l < min({(k) + 1, N}); ++l) {

int jp = k;
int kp = s;
int lp = l;
I[i][j][k][l][s] += I[ip][jp][kp][lp][sp];
}
}
}
}
}
for (int i = 0; i < N; ++i) {

int kp = i;
for (int j = max({i, 0}); j < N; ++j) {

for (int l = max({j, 0}); l < N; ++l) {

int ip = j;
int lp = l;
for (int k = 0; k < N; ++k) {

for (int s = max({l, 0}); s < min({(k) + 1, N}); ++s) {

int jp = k;
int sp = s;
I[i][j][k][l][s] += I[ip][jp][kp][lp][sp];
}
}
}
}
}
for (int i = 0; i < N; ++i) {

int lp = i;
for (int j = max({i, 0}); j < N; ++j) {

int ip = j;
for (int k = 0; k < N; ++k) {

for (int s = max({j, 0}); s < min({(k) + 1, N}); ++s) {

for (int l = max({k, 0}); l < N; ++l) {

int jp = k;
int kp = s;
int sp = l;
I[i][j][k][l][s] += I[ip][jp][kp][lp][sp];
}
}
}
}
}
for (int i = 0; i < N; ++i) {

int kp = i;
for (int j = max({i, 0}); j < N; ++j) {

int ip = j;
for (int k = 0; k < N; ++k) {

for (int l = 0; l < min({(k) + 1, N}); ++l) {

int jp = k;
for (int s = max({j, 0}); s < min({(l) + 1, N}); ++s) {

int sp = l;
int lp = s;
I[i][j][k][l][s] += I[ip][jp][kp][lp][sp];
}
}
}
}
}
for (int i = 0; i < N; ++i) {

int sp = i;
for (int j = 0; j < N; ++j) {

for (int l = max({j, 0}); l < N; ++l) {

int ip = j;
for (int k = max({i, 0}); k < min({(j) + 1, N}); ++k) {

for (int s = max({l, 0}); s < N; ++s) {

int jp = l;
int kp = k;
int lp = s;
I[i][j][k][l][s] += I[ip][jp][kp][lp][sp];
}
}
}
}
}
for (int i = 0; i < N; ++i) {

int lp = i;
for (int j = 0; j < N; ++j) {

int ip = j;
for (int k = max({i, 0}); k < min({(j) + 1, N}); ++k) {

for (int l = 0; l < N; ++l) {

int kp = k;
for (int s = max({j, 0}); s < min({(l) + 1, N}); ++s) {

int jp = l;
int sp = s;
I[i][j][k][l][s] += I[ip][jp][kp][lp][sp];
}
}
}
}
}
for (int i = 0; i < N; ++i) {

int sp = i;
for (int k = max({i, 0}); k < N; ++k) {

int kp = k;
for (int j = 0; j < N; ++j) {

for (int s = max({j, 0}); s < N; ++s) {

for (int l = max({k, 0}); l < min({(j) + 1, N}); ++l) {

int ip = j;
int jp = s;
int lp = l;
I[i][j][k][l][s] += I[ip][jp][kp][lp][sp];
}
}
}
}
}
for (int i = 0; i < N; ++i) {

int jp = i;
for (int k = max({i, 0}); k < N; ++k) {

for (int l = max({k, 0}); l < N; ++l) {

int kp = k;
int lp = l;
for (int j = 0; j < N; ++j) {

for (int s = max({l, 0}); s < min({(j) + 1, N}); ++s) {

int ip = j;
int sp = s;
I[i][j][k][l][s] += I[ip][jp][kp][lp][sp];
}
}
}
}
}
for (int i = 0; i < N; ++i) {

int lp = i;
for (int k = max({i, 0}); k < N; ++k) {

int kp = k;
for (int j = 0; j < N; ++j) {

for (int s = max({k, 0}); s < min({(j) + 1, N}); ++s) {

for (int l = max({j, 0}); l < N; ++l) {

int ip = j;
int jp = s;
int sp = l;
I[i][j][k][l][s] += I[ip][jp][kp][lp][sp];
}
}
}
}
}
for (int i = 0; i < N; ++i) {

int jp = i;
for (int k = max({i, 0}); k < N; ++k) {

int kp = k;
for (int j = 0; j < N; ++j) {

for (int l = 0; l < min({(j) + 1, N}); ++l) {

int ip = j;
for (int s = max({k, 0}); s < min({(l) + 1, N}); ++s) {

int sp = l;
int lp = s;
I[i][j][k][l][s] += I[ip][jp][kp][lp][sp];
}
}
}
}
}
for (int i = 0; i < N; ++i) {

int sp = i;
for (int j = 0; j < N; ++j) {

for (int l = max({i, 0}); l < min({(j) + 1, N}); ++l) {

int ip = j;
for (int k = max({j, 0}); k < N; ++k) {

int jp = l;
for (int s = max({k, 0}); s < N; ++s) {

int lp = k;
int kp = s;
I[i][j][k][l][s] += I[ip][jp][kp][lp][sp];
}
}
}
}
}
for (int i = 0; i < N; ++i) {

int kp = i;
for (int j = 0; j < N; ++j) {

for (int l = max({i, 0}); l < min({(j) + 1, N}); ++l) {

int ip = j;
int jp = l;
for (int k = 0; k < N; ++k) {

for (int s = max({j, 0}); s < min({(k) + 1, N}); ++s) {

int lp = k;
int sp = s;
I[i][j][k][l][s] += I[ip][jp][kp][lp][sp];
}
}
}
}
}
for (int i = 0; i < N; ++i) {

int sp = i;
for (int j = 0; j < N; ++j) {

for (int s = max({j, 0}); s < N; ++s) {

int ip = j;
for (int k = 0; k < min({(j) + 1, N}); ++k) {

int jp = s;
for (int l = max({i, 0}); l < min({(k) + 1, N}); ++l) {

int lp = k;
int kp = l;
I[i][j][k][l][s] += I[ip][jp][kp][lp][sp];
}
}
}
}
}
for (int i = 0; i < N; ++i) {

int jp = i;
for (int j = 0; j < N; ++j) {

int ip = j;
for (int k = 0; k < N; ++k) {

for (int s = max({k, 0}); s < min({(j) + 1, N}); ++s) {

for (int l = max({i, 0}); l < min({(k) + 1, N}); ++l) {

int lp = k;
int sp = s;
int kp = l;
I[i][j][k][l][s] += I[ip][jp][kp][lp][sp];
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int l = max({i, 0}); l < N; ++l) {

int kp = i;
int sp = l;
for (int j = 0; j < N; ++j) {

for (int s = max({l, 0}); s < min({(j) + 1, N}); ++s) {

int ip = j;
for (int k = max({j, 0}); k < N; ++k) {

int jp = s;
int lp = k;
I[i][j][k][l][s] += I[ip][jp][kp][lp][sp];
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int l = max({i, 0}); l < N; ++l) {

int jp = i;
int sp = l;
for (int j = 0; j < N; ++j) {

int ip = j;
for (int k = 0; k < min({(j) + 1, N}); ++k) {

for (int s = max({l, 0}); s < min({(k) + 1, N}); ++s) {

int lp = k;
int kp = s;
I[i][j][k][l][s] += I[ip][jp][kp][lp][sp];
}
}
}
}
}
for (int i = 0; i < N; ++i) {

int lp = i;
for (int j = 0; j < N; ++j) {

for (int s = max({i, 0}); s < min({(j) + 1, N}); ++s) {

int ip = j;
for (int k = max({j, 0}); k < N; ++k) {

int kp = s;
for (int l = max({k, 0}); l < N; ++l) {

int sp = k;
int jp = l;
I[i][j][k][l][s] += I[ip][jp][kp][lp][sp];
}
}
}
}
}
for (int i = 0; i < N; ++i) {

int kp = i;
for (int j = 0; j < N; ++j) {

for (int s = max({i, 0}); s < min({(j) + 1, N}); ++s) {

int ip = j;
int lp = s;
for (int k = 0; k < N; ++k) {

for (int l = max({j, 0}); l < min({(k) + 1, N}); ++l) {

int sp = k;
int jp = l;
I[i][j][k][l][s] += I[ip][jp][kp][lp][sp];
}
}
}
}
}
for (int i = 0; i < N; ++i) {

int lp = i;
for (int j = 0; j < N; ++j) {

for (int l = max({j, 0}); l < N; ++l) {

int ip = j;
for (int k = 0; k < min({(j) + 1, N}); ++k) {

int kp = l;
for (int s = max({i, 0}); s < min({(k) + 1, N}); ++s) {

int sp = k;
int jp = s;
I[i][j][k][l][s] += I[ip][jp][kp][lp][sp];
}
}
}
}
}
for (int i = 0; i < N; ++i) {

int jp = i;
for (int j = 0; j < N; ++j) {

int ip = j;
for (int k = 0; k < N; ++k) {

for (int s = max({i, 0}); s < min({(k) + 1, N}); ++s) {

for (int l = max({k, 0}); l < min({(j) + 1, N}); ++l) {

int sp = k;
int lp = s;
int kp = l;
I[i][j][k][l][s] += I[ip][jp][kp][lp][sp];
}
}
}
}
}
for (int i = 0; i < N; ++i) {

int kp = i;
for (int j = 0; j < N; ++j) {

for (int l = 0; l < min({(j) + 1, N}); ++l) {

int ip = j;
for (int k = max({j, 0}); k < N; ++k) {

for (int s = max({i, 0}); s < min({(l) + 1, N}); ++s) {

int lp = l;
int sp = k;
int jp = s;
I[i][j][k][l][s] += I[ip][jp][kp][lp][sp];
}
}
}
}
}
for (int i = 0; i < N; ++i) {

int jp = i;
for (int j = 0; j < N; ++j) {

int ip = j;
for (int k = 0; k < min({(j) + 1, N}); ++k) {

for (int l = 0; l < min({(k) + 1, N}); ++l) {

int sp = k;
for (int s = max({i, 0}); s < min({(l) + 1, N}); ++s) {

int lp = l;
int kp = s;
I[i][j][k][l][s] += I[ip][jp][kp][lp][sp];
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int t = max({i, 0}); t < N; ++t) {

int tp = i;
int ip = t;
for (int j = 0; j < N; ++j) {

int jp = j;
for (int k = max({j, 0}); k < N; ++k) {

for (int l = max({k, 0}); l < N; ++l) {

int kp = k;
for (int s = max({l, 0}); s < min({(i) + 1, N}); ++s) {

int lp = l;
int sp = s;
J[i][j][k][l][s][t] += J[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int s = 0; s < min({(i) + 1, N}); ++s) {

int ip = i;
int tp = s;
for (int j = 0; j < N; ++j) {

int jp = j;
for (int k = max({j, 0}); k < N; ++k) {

for (int l = max({k, 0}); l < N; ++l) {

int kp = k;
for (int t = max({l, 0}); t < min({(s) + 1, N}); ++t) {

int lp = l;
int sp = t;
J[i][j][k][l][s][t] += J[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int s = max({i, 0}); s < N; ++s) {

int sp = i;
int tp = s;
for (int j = 0; j < N; ++j) {

int jp = j;
for (int k = max({j, 0}); k < N; ++k) {

for (int l = max({k, 0}); l < N; ++l) {

int kp = k;
for (int t = max({l, 0}); t < min({(i) + 1, N}); ++t) {

int lp = l;
int ip = t;
J[i][j][k][l][s][t] += J[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int s = max({i, 0}); s < N; ++s) {

int tp = i;
for (int t = max({s, 0}); t < N; ++t) {

int ip = s;
int sp = t;
for (int j = 0; j < N; ++j) {

int jp = j;
for (int k = max({j, 0}); k < N; ++k) {

for (int l = max({k, 0}); l < min({(i) + 1, N}); ++l) {

int kp = k;
int lp = l;
J[i][j][k][l][s][t] += J[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

int sp = i;
for (int j = 0; j < N; ++j) {

int jp = j;
for (int k = max({j, 0}); k < N; ++k) {

for (int l = max({k, 0}); l < min({(i) + 1, N}); ++l) {

int kp = k;
int lp = l;
for (int s = 0; s < N; ++s) {

for (int t = max({i, 0}); t < min({(s) + 1, N}); ++t) {

int ip = s;
int tp = t;
J[i][j][k][l][s][t] += J[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

int ip = i;
for (int j = 0; j < N; ++j) {

int jp = j;
for (int k = max({j, 0}); k < N; ++k) {

for (int l = 0; l < N; ++l) {

int kp = k;
for (int s = max({k, 0}); s < min({(l) + 1, N}); ++s) {

for (int t = max({l, 0}); t < min({(i) + 1, N}); ++t) {

int sp = l;
int lp = s;
int tp = t;
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

int tp = i;
int ip = t;
int sp = l;
for (int j = 0; j < N; ++j) {

int jp = j;
for (int k = max({j, 0}); k < N; ++k) {

for (int s = max({k, 0}); s < min({(l) + 1, N}); ++s) {

int kp = k;
int lp = s;
J[i][j][k][l][s][t] += J[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int l = 0; l < min({(i) + 1, N}); ++l) {

int ip = i;
int sp = l;
for (int j = 0; j < N; ++j) {

int jp = j;
for (int k = max({j, 0}); k < N; ++k) {

for (int s = max({k, 0}); s < N; ++s) {

int kp = k;
for (int t = max({s, 0}); t < min({(l) + 1, N}); ++t) {

int tp = s;
int lp = t;
J[i][j][k][l][s][t] += J[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int l = max({i, 0}); l < N; ++l) {

int lp = i;
int sp = l;
for (int j = 0; j < N; ++j) {

int jp = j;
for (int k = max({j, 0}); k < N; ++k) {

for (int s = max({k, 0}); s < N; ++s) {

int kp = k;
for (int t = max({s, 0}); t < min({(i) + 1, N}); ++t) {

int tp = s;
int ip = t;
J[i][j][k][l][s][t] += J[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int l = max({i, 0}); l < N; ++l) {

int tp = i;
for (int t = max({l, 0}); t < N; ++t) {

int sp = l;
int lp = t;
for (int j = 0; j < N; ++j) {

int jp = j;
for (int k = max({j, 0}); k < N; ++k) {

for (int s = max({k, 0}); s < min({(i) + 1, N}); ++s) {

int kp = k;
int ip = s;
J[i][j][k][l][s][t] += J[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

int lp = i;
for (int j = 0; j < N; ++j) {

int jp = j;
for (int k = max({j, 0}); k < N; ++k) {

for (int s = max({k, 0}); s < min({(i) + 1, N}); ++s) {

int kp = k;
int ip = s;
for (int l = 0; l < N; ++l) {

for (int t = max({i, 0}); t < min({(l) + 1, N}); ++t) {

int sp = l;
int tp = t;
J[i][j][k][l][s][t] += J[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

int ip = i;
for (int j = 0; j < N; ++j) {

int jp = j;
for (int k = max({j, 0}); k < N; ++k) {

for (int l = 0; l < N; ++l) {

int kp = k;
for (int s = max({l, 0}); s < min({(i) + 1, N}); ++s) {

for (int t = max({k, 0}); t < min({(l) + 1, N}); ++t) {

int tp = l;
int lp = s;
int sp = t;
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

int sp = i;
int lp = s;
int tp = l;
for (int j = 0; j < N; ++j) {

int jp = j;
for (int k = max({j, 0}); k < N; ++k) {

for (int t = max({k, 0}); t < min({(l) + 1, N}); ++t) {

int kp = k;
int ip = t;
J[i][j][k][l][s][t] += J[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int l = 0; l < min({(i) + 1, N}); ++l) {

int ip = i;
for (int s = 0; s < min({(l) + 1, N}); ++s) {

int tp = l;
int sp = s;
for (int j = 0; j < N; ++j) {

int jp = j;
for (int k = max({j, 0}); k < N; ++k) {

for (int t = max({k, 0}); t < min({(s) + 1, N}); ++t) {

int kp = k;
int lp = t;
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

int lp = i;
int sp = s;
int tp = l;
for (int j = 0; j < N; ++j) {

int jp = j;
for (int k = max({j, 0}); k < N; ++k) {

for (int t = max({k, 0}); t < min({(s) + 1, N}); ++t) {

int kp = k;
int ip = t;
J[i][j][k][l][s][t] += J[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int l = max({i, 0}); l < N; ++l) {

int sp = i;
for (int s = max({l, 0}); s < N; ++s) {

int tp = l;
int ip = s;
for (int j = 0; j < N; ++j) {

int jp = j;
for (int k = max({j, 0}); k < N; ++k) {

for (int t = max({k, 0}); t < min({(i) + 1, N}); ++t) {

int kp = k;
int lp = t;
J[i][j][k][l][s][t] += J[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

int lp = i;
for (int j = 0; j < N; ++j) {

int jp = j;
for (int k = max({j, 0}); k < N; ++k) {

for (int t = max({k, 0}); t < min({(i) + 1, N}); ++t) {

int kp = k;
int sp = t;
for (int l = 0; l < N; ++l) {

for (int s = max({i, 0}); s < min({(l) + 1, N}); ++s) {

int tp = l;
int ip = s;
J[i][j][k][l][s][t] += J[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int l = max({i, 0}); l < N; ++l) {

int tp = i;
for (int s = max({l, 0}); s < N; ++s) {

int ip = l;
for (int t = max({s, 0}); t < N; ++t) {

int lp = s;
int sp = t;
for (int j = 0; j < N; ++j) {

int jp = j;
for (int k = max({j, 0}); k < min({(i) + 1, N}); ++k) {

int kp = k;
J[i][j][k][l][s][t] += J[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int l = max({i, 0}); l < N; ++l) {

int sp = i;
int ip = l;
for (int j = 0; j < N; ++j) {

int jp = j;
for (int k = max({j, 0}); k < min({(i) + 1, N}); ++k) {

int kp = k;
for (int s = 0; s < N; ++s) {

for (int t = max({l, 0}); t < min({(s) + 1, N}); ++t) {

int lp = s;
int tp = t;
J[i][j][k][l][s][t] += J[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int j = 0; j < N; ++j) {

int tp = i;
int jp = j;
for (int k = max({j, 0}); k < min({(i) + 1, N}); ++k) {

for (int l = 0; l < N; ++l) {

int kp = k;
for (int s = max({i, 0}); s < min({(l) + 1, N}); ++s) {

for (int t = max({l, 0}); t < N; ++t) {

int ip = l;
int sp = s;
int lp = t;
J[i][j][k][l][s][t] += J[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int s = max({i, 0}); s < N; ++s) {

int lp = i;
int sp = s;
for (int j = 0; j < N; ++j) {

int jp = j;
for (int k = max({j, 0}); k < min({(i) + 1, N}); ++k) {

for (int l = 0; l < N; ++l) {

int kp = k;
for (int t = max({s, 0}); t < min({(l) + 1, N}); ++t) {

int ip = l;
int tp = t;
J[i][j][k][l][s][t] += J[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

int sp = i;
for (int j = 0; j < N; ++j) {

int jp = j;
for (int k = max({j, 0}); k < min({(i) + 1, N}); ++k) {

for (int l = 0; l < N; ++l) {

int kp = k;
for (int s = max({l, 0}); s < N; ++s) {

for (int t = max({i, 0}); t < min({(l) + 1, N}); ++t) {

int ip = l;
int tp = s;
int lp = t;
J[i][j][k][l][s][t] += J[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

int lp = i;
for (int j = 0; j < N; ++j) {

int jp = j;
for (int k = max({j, 0}); k < min({(i) + 1, N}); ++k) {

for (int l = 0; l < N; ++l) {

int kp = k;
for (int s = 0; s < min({(l) + 1, N}); ++s) {

int ip = l;
for (int t = max({i, 0}); t < min({(s) + 1, N}); ++t) {

int tp = s;
int sp = t;
J[i][j][k][l][s][t] += J[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

int ip = i;
for (int j = 0; j < N; ++j) {

int jp = j;
for (int k = 0; k < N; ++k) {

for (int s = max({k, 0}); s < N; ++s) {

for (int l = max({j, 0}); l < min({(k) + 1, N}); ++l) {

int lp = k;
for (int t = max({s, 0}); t < min({(i) + 1, N}); ++t) {

int sp = s;
int kp = l;
int tp = t;
J[i][j][k][l][s][t] += J[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int t = max({i, 0}); t < N; ++t) {

int tp = i;
int ip = t;
for (int j = 0; j < N; ++j) {

int jp = j;
for (int k = 0; k < N; ++k) {

for (int s = max({k, 0}); s < min({(i) + 1, N}); ++s) {

for (int l = max({j, 0}); l < min({(k) + 1, N}); ++l) {

int lp = k;
int sp = s;
int kp = l;
J[i][j][k][l][s][t] += J[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int s = 0; s < min({(i) + 1, N}); ++s) {

int ip = i;
int tp = s;
for (int j = 0; j < N; ++j) {

int jp = j;
for (int k = 0; k < N; ++k) {

for (int t = max({k, 0}); t < min({(s) + 1, N}); ++t) {

for (int l = max({j, 0}); l < min({(k) + 1, N}); ++l) {

int lp = k;
int sp = t;
int kp = l;
J[i][j][k][l][s][t] += J[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int s = max({i, 0}); s < N; ++s) {

int sp = i;
int tp = s;
for (int j = 0; j < N; ++j) {

int jp = j;
for (int k = 0; k < N; ++k) {

for (int t = max({k, 0}); t < min({(i) + 1, N}); ++t) {

for (int l = max({j, 0}); l < min({(k) + 1, N}); ++l) {

int lp = k;
int ip = t;
int kp = l;
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

int tp = i;
for (int t = max({s, 0}); t < N; ++t) {

int ip = s;
int lp = k;
int sp = t;
for (int j = 0; j < N; ++j) {

for (int l = max({j, 0}); l < min({(k) + 1, N}); ++l) {

int jp = j;
int kp = l;
J[i][j][k][l][s][t] += J[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

int sp = i;
for (int k = 0; k < min({(i) + 1, N}); ++k) {

int lp = k;
for (int j = 0; j < N; ++j) {

for (int l = max({j, 0}); l < min({(k) + 1, N}); ++l) {

int jp = j;
int kp = l;
for (int s = 0; s < N; ++s) {

for (int t = max({i, 0}); t < min({(s) + 1, N}); ++t) {

int ip = s;
int tp = t;
J[i][j][k][l][s][t] += J[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

int ip = i;
for (int j = 0; j < N; ++j) {

for (int l = max({j, 0}); l < N; ++l) {

int jp = j;
int sp = l;
for (int k = 0; k < N; ++k) {

for (int s = max({l, 0}); s < min({(k) + 1, N}); ++s) {

for (int t = max({k, 0}); t < min({(i) + 1, N}); ++t) {

int lp = k;
int kp = s;
int tp = t;
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

int tp = i;
int ip = t;
int lp = k;
for (int j = 0; j < N; ++j) {

for (int l = max({j, 0}); l < N; ++l) {

int jp = j;
for (int s = max({l, 0}); s < min({(k) + 1, N}); ++s) {

int sp = l;
int kp = s;
J[i][j][k][l][s][t] += J[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

int ip = i;
for (int k = 0; k < min({(i) + 1, N}); ++k) {

int lp = k;
for (int j = 0; j < N; ++j) {

for (int l = max({j, 0}); l < N; ++l) {

int jp = j;
for (int s = max({l, 0}); s < N; ++s) {

int sp = l;
for (int t = max({s, 0}); t < min({(k) + 1, N}); ++t) {

int tp = s;
int kp = t;
J[i][j][k][l][s][t] += J[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

int kp = i;
for (int k = max({i, 0}); k < N; ++k) {

int lp = k;
for (int j = 0; j < N; ++j) {

for (int l = max({j, 0}); l < N; ++l) {

int jp = j;
for (int s = max({l, 0}); s < N; ++s) {

int sp = l;
for (int t = max({s, 0}); t < min({(i) + 1, N}); ++t) {

int tp = s;
int ip = t;
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

int tp = i;
for (int l = max({j, 0}); l < N; ++l) {

int jp = j;
for (int t = max({k, 0}); t < N; ++t) {

int lp = k;
for (int s = max({l, 0}); s < min({(i) + 1, N}); ++s) {

int sp = l;
int kp = t;
int ip = s;
J[i][j][k][l][s][t] += J[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

int kp = i;
for (int j = 0; j < N; ++j) {

for (int l = max({j, 0}); l < N; ++l) {

int jp = j;
for (int s = max({l, 0}); s < min({(i) + 1, N}); ++s) {

int sp = l;
int ip = s;
for (int k = 0; k < N; ++k) {

for (int t = max({i, 0}); t < min({(k) + 1, N}); ++t) {

int lp = k;
int tp = t;
J[i][j][k][l][s][t] += J[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

int ip = i;
for (int j = 0; j < N; ++j) {

for (int l = max({j, 0}); l < N; ++l) {

int jp = j;
int tp = l;
for (int k = 0; k < N; ++k) {

for (int s = max({k, 0}); s < min({(i) + 1, N}); ++s) {

for (int t = max({l, 0}); t < min({(k) + 1, N}); ++t) {

int lp = k;
int kp = s;
int sp = t;
J[i][j][k][l][s][t] += J[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int s = max({i, 0}); s < N; ++s) {

int sp = i;
for (int k = 0; k < min({(i) + 1, N}); ++k) {

int kp = s;
int lp = k;
for (int j = 0; j < N; ++j) {

for (int l = max({j, 0}); l < N; ++l) {

int jp = j;
for (int t = max({l, 0}); t < min({(k) + 1, N}); ++t) {

int tp = l;
int ip = t;
J[i][j][k][l][s][t] += J[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

int ip = i;
for (int k = 0; k < min({(i) + 1, N}); ++k) {

for (int s = 0; s < min({(k) + 1, N}); ++s) {

int lp = k;
int sp = s;
for (int j = 0; j < N; ++j) {

for (int l = max({j, 0}); l < N; ++l) {

int jp = j;
for (int t = max({l, 0}); t < min({(s) + 1, N}); ++t) {

int tp = l;
int kp = t;
J[i][j][k][l][s][t] += J[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int s = 0; s < min({(i) + 1, N}); ++s) {

int kp = i;
for (int k = max({i, 0}); k < N; ++k) {

int sp = s;
int lp = k;
for (int j = 0; j < N; ++j) {

for (int l = max({j, 0}); l < N; ++l) {

int jp = j;
for (int t = max({l, 0}); t < min({(s) + 1, N}); ++t) {

int tp = l;
int ip = t;
J[i][j][k][l][s][t] += J[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

int sp = i;
for (int k = max({i, 0}); k < N; ++k) {

for (int s = max({k, 0}); s < N; ++s) {

int lp = k;
int ip = s;
for (int j = 0; j < N; ++j) {

for (int l = max({j, 0}); l < N; ++l) {

int jp = j;
for (int t = max({l, 0}); t < min({(i) + 1, N}); ++t) {

int tp = l;
int kp = t;
J[i][j][k][l][s][t] += J[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

int kp = i;
for (int j = 0; j < N; ++j) {

for (int l = max({j, 0}); l < N; ++l) {

int jp = j;
for (int t = max({l, 0}); t < min({(i) + 1, N}); ++t) {

int tp = l;
int sp = t;
for (int k = 0; k < N; ++k) {

for (int s = max({i, 0}); s < min({(k) + 1, N}); ++s) {

int lp = k;
int ip = s;
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

int tp = i;
for (int l = max({j, 0}); l < min({(i) + 1, N}); ++l) {

int jp = j;
for (int s = max({k, 0}); s < N; ++s) {

int lp = k;
int ip = l;
for (int t = max({s, 0}); t < N; ++t) {

int kp = s;
int sp = t;
J[i][j][k][l][s][t] += J[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

int sp = i;
for (int k = max({i, 0}); k < N; ++k) {

int lp = k;
for (int j = 0; j < N; ++j) {

for (int l = max({j, 0}); l < min({(i) + 1, N}); ++l) {

int jp = j;
int ip = l;
for (int s = 0; s < N; ++s) {

for (int t = max({k, 0}); t < min({(s) + 1, N}); ++t) {

int kp = s;
int tp = t;
J[i][j][k][l][s][t] += J[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int j = 0; j < N; ++j) {

int tp = i;
for (int l = max({j, 0}); l < min({(i) + 1, N}); ++l) {

int jp = j;
int ip = l;
for (int k = 0; k < N; ++k) {

for (int s = max({i, 0}); s < min({(k) + 1, N}); ++s) {

for (int t = max({k, 0}); t < N; ++t) {

int lp = k;
int sp = s;
int kp = t;
J[i][j][k][l][s][t] += J[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int s = max({i, 0}); s < N; ++s) {

int kp = i;
int sp = s;
for (int j = 0; j < N; ++j) {

for (int l = max({j, 0}); l < min({(i) + 1, N}); ++l) {

int jp = j;
int ip = l;
for (int k = 0; k < N; ++k) {

for (int t = max({s, 0}); t < min({(k) + 1, N}); ++t) {

int lp = k;
int tp = t;
J[i][j][k][l][s][t] += J[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

int sp = i;
for (int j = 0; j < N; ++j) {

for (int l = max({j, 0}); l < min({(i) + 1, N}); ++l) {

int jp = j;
int ip = l;
for (int k = 0; k < N; ++k) {

for (int s = max({k, 0}); s < N; ++s) {

for (int t = max({i, 0}); t < min({(k) + 1, N}); ++t) {

int lp = k;
int tp = s;
int kp = t;
J[i][j][k][l][s][t] += J[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

int kp = i;
for (int j = 0; j < N; ++j) {

for (int l = max({j, 0}); l < min({(i) + 1, N}); ++l) {

int jp = j;
int ip = l;
for (int k = 0; k < N; ++k) {

for (int s = 0; s < min({(k) + 1, N}); ++s) {

int lp = k;
for (int t = max({i, 0}); t < min({(s) + 1, N}); ++t) {

int tp = s;
int sp = t;
J[i][j][k][l][s][t] += J[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

int ip = i;
for (int j = 0; j < N; ++j) {

int jp = j;
for (int k = 0; k < N; ++k) {

for (int s = max({j, 0}); s < min({(k) + 1, N}); ++s) {

for (int l = max({k, 0}); l < N; ++l) {

int sp = k;
int lp = s;
for (int t = max({l, 0}); t < min({(i) + 1, N}); ++t) {

int kp = l;
int tp = t;
J[i][j][k][l][s][t] += J[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int t = max({i, 0}); t < N; ++t) {

int tp = i;
int ip = t;
for (int j = 0; j < N; ++j) {

int jp = j;
for (int k = 0; k < N; ++k) {

for (int s = max({j, 0}); s < min({(k) + 1, N}); ++s) {

for (int l = max({k, 0}); l < min({(i) + 1, N}); ++l) {

int sp = k;
int lp = s;
int kp = l;
J[i][j][k][l][s][t] += J[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int l = 0; l < min({(i) + 1, N}); ++l) {

int ip = i;
int kp = l;
for (int j = 0; j < N; ++j) {

int jp = j;
for (int k = 0; k < N; ++k) {

for (int s = max({j, 0}); s < min({(k) + 1, N}); ++s) {

for (int t = max({k, 0}); t < min({(l) + 1, N}); ++t) {

int sp = k;
int tp = s;
int lp = t;
J[i][j][k][l][s][t] += J[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int l = max({i, 0}); l < N; ++l) {

int lp = i;
int kp = l;
for (int j = 0; j < N; ++j) {

int jp = j;
for (int k = 0; k < N; ++k) {

for (int s = max({j, 0}); s < min({(k) + 1, N}); ++s) {

for (int t = max({k, 0}); t < min({(i) + 1, N}); ++t) {

int sp = k;
int tp = s;
int ip = t;
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

int tp = i;
for (int t = max({l, 0}); t < N; ++t) {

int kp = l;
int sp = k;
int lp = t;
for (int j = 0; j < N; ++j) {

for (int s = max({j, 0}); s < min({(k) + 1, N}); ++s) {

int jp = j;
int ip = s;
J[i][j][k][l][s][t] += J[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

int lp = i;
for (int k = 0; k < min({(i) + 1, N}); ++k) {

int sp = k;
for (int j = 0; j < N; ++j) {

for (int s = max({j, 0}); s < min({(k) + 1, N}); ++s) {

int jp = j;
int ip = s;
for (int l = 0; l < N; ++l) {

for (int t = max({i, 0}); t < min({(l) + 1, N}); ++t) {

int kp = l;
int tp = t;
J[i][j][k][l][s][t] += J[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

int ip = i;
for (int j = 0; j < N; ++j) {

int jp = j;
for (int k = 0; k < N; ++k) {

for (int t = max({k, 0}); t < min({(i) + 1, N}); ++t) {

for (int l = 0; l < min({(k) + 1, N}); ++l) {

int sp = k;
int tp = t;
for (int s = max({j, 0}); s < min({(l) + 1, N}); ++s) {

int lp = l;
int kp = s;
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

int tp = i;
int ip = t;
for (int l = 0; l < min({(k) + 1, N}); ++l) {

int sp = k;
int lp = l;
for (int j = 0; j < N; ++j) {

for (int s = max({j, 0}); s < min({(l) + 1, N}); ++s) {

int jp = j;
int kp = s;
J[i][j][k][l][s][t] += J[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

int ip = i;
for (int k = 0; k < min({(i) + 1, N}); ++k) {

int sp = k;
for (int j = 0; j < N; ++j) {

int jp = j;
for (int l = 0; l < N; ++l) {

for (int s = max({j, 0}); s < min({(l) + 1, N}); ++s) {

for (int t = max({l, 0}); t < min({(k) + 1, N}); ++t) {

int lp = l;
int tp = s;
int kp = t;
J[i][j][k][l][s][t] += J[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

int kp = i;
for (int k = max({i, 0}); k < N; ++k) {

int sp = k;
for (int j = 0; j < N; ++j) {

int jp = j;
for (int l = 0; l < N; ++l) {

for (int s = max({j, 0}); s < min({(l) + 1, N}); ++s) {

for (int t = max({l, 0}); t < min({(i) + 1, N}); ++t) {

int lp = l;
int tp = s;
int ip = t;
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

int tp = i;
int lp = l;
for (int t = max({k, 0}); t < N; ++t) {

int sp = k;
int kp = t;
for (int j = 0; j < N; ++j) {

for (int s = max({j, 0}); s < min({(l) + 1, N}); ++s) {

int jp = j;
int ip = s;
J[i][j][k][l][s][t] += J[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int l = 0; l < min({(i) + 1, N}); ++l) {

int kp = i;
int lp = l;
for (int j = 0; j < N; ++j) {

for (int s = max({j, 0}); s < min({(l) + 1, N}); ++s) {

int jp = j;
int ip = s;
for (int k = 0; k < N; ++k) {

for (int t = max({i, 0}); t < min({(k) + 1, N}); ++t) {

int sp = k;
int tp = t;
J[i][j][k][l][s][t] += J[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

int ip = i;
for (int j = 0; j < N; ++j) {

for (int s = max({j, 0}); s < N; ++s) {

int jp = j;
int kp = s;
for (int k = 0; k < N; ++k) {

for (int t = max({s, 0}); t < min({(k) + 1, N}); ++t) {

for (int l = max({k, 0}); l < min({(i) + 1, N}); ++l) {

int sp = k;
int lp = t;
int tp = l;
J[i][j][k][l][s][t] += J[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int l = max({i, 0}); l < N; ++l) {

int lp = i;
for (int k = 0; k < min({(i) + 1, N}); ++k) {

int tp = l;
int sp = k;
for (int j = 0; j < N; ++j) {

for (int s = max({j, 0}); s < N; ++s) {

int jp = j;
for (int t = max({s, 0}); t < min({(k) + 1, N}); ++t) {

int kp = s;
int ip = t;
J[i][j][k][l][s][t] += J[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

int ip = i;
for (int k = 0; k < min({(i) + 1, N}); ++k) {

for (int l = 0; l < min({(k) + 1, N}); ++l) {

int sp = k;
int tp = l;
for (int j = 0; j < N; ++j) {

for (int s = max({j, 0}); s < N; ++s) {

int jp = j;
for (int t = max({s, 0}); t < min({(l) + 1, N}); ++t) {

int lp = s;
int kp = t;
J[i][j][k][l][s][t] += J[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int l = 0; l < min({(i) + 1, N}); ++l) {

int kp = i;
for (int k = max({i, 0}); k < N; ++k) {

int tp = l;
int sp = k;
for (int j = 0; j < N; ++j) {

for (int s = max({j, 0}); s < N; ++s) {

int jp = j;
for (int t = max({s, 0}); t < min({(l) + 1, N}); ++t) {

int lp = s;
int ip = t;
J[i][j][k][l][s][t] += J[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

int lp = i;
for (int k = max({i, 0}); k < N; ++k) {

for (int l = max({k, 0}); l < N; ++l) {

int sp = k;
int tp = l;
for (int j = 0; j < N; ++j) {

for (int s = max({j, 0}); s < N; ++s) {

int jp = j;
for (int t = max({s, 0}); t < min({(i) + 1, N}); ++t) {

int ip = s;
int kp = t;
J[i][j][k][l][s][t] += J[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

int kp = i;
for (int j = 0; j < N; ++j) {

for (int s = max({j, 0}); s < N; ++s) {

int jp = j;
for (int t = max({s, 0}); t < min({(i) + 1, N}); ++t) {

int ip = s;
int lp = t;
for (int k = 0; k < N; ++k) {

for (int l = max({i, 0}); l < min({(k) + 1, N}); ++l) {

int sp = k;
int tp = l;
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

int tp = i;
for (int s = max({j, 0}); s < min({(i) + 1, N}); ++s) {

int jp = j;
for (int l = max({k, 0}); l < N; ++l) {

int sp = k;
int kp = s;
for (int t = max({l, 0}); t < N; ++t) {

int ip = l;
int lp = t;
J[i][j][k][l][s][t] += J[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

int lp = i;
for (int k = max({i, 0}); k < N; ++k) {

int sp = k;
for (int j = 0; j < N; ++j) {

for (int s = max({j, 0}); s < min({(i) + 1, N}); ++s) {

int jp = j;
int kp = s;
for (int l = 0; l < N; ++l) {

for (int t = max({k, 0}); t < min({(l) + 1, N}); ++t) {

int ip = l;
int tp = t;
J[i][j][k][l][s][t] += J[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int j = 0; j < N; ++j) {

int tp = i;
for (int s = max({j, 0}); s < min({(i) + 1, N}); ++s) {

int jp = j;
int lp = s;
for (int k = 0; k < N; ++k) {

for (int t = max({k, 0}); t < N; ++t) {

for (int l = max({i, 0}); l < min({(k) + 1, N}); ++l) {

int sp = k;
int kp = t;
int ip = l;
J[i][j][k][l][s][t] += J[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int l = max({i, 0}); l < N; ++l) {

int kp = i;
int ip = l;
for (int j = 0; j < N; ++j) {

for (int s = max({j, 0}); s < min({(i) + 1, N}); ++s) {

int jp = j;
int lp = s;
for (int k = 0; k < N; ++k) {

for (int t = max({l, 0}); t < min({(k) + 1, N}); ++t) {

int sp = k;
int tp = t;
J[i][j][k][l][s][t] += J[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

int lp = i;
for (int j = 0; j < N; ++j) {

for (int s = max({j, 0}); s < min({(i) + 1, N}); ++s) {

int jp = j;
int tp = s;
for (int k = 0; k < N; ++k) {

for (int t = max({i, 0}); t < min({(k) + 1, N}); ++t) {

for (int l = max({k, 0}); l < N; ++l) {

int sp = k;
int kp = t;
int ip = l;
J[i][j][k][l][s][t] += J[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

int kp = i;
for (int j = 0; j < N; ++j) {

for (int s = max({j, 0}); s < min({(i) + 1, N}); ++s) {

int jp = j;
int tp = s;
for (int k = 0; k < N; ++k) {

for (int l = 0; l < min({(k) + 1, N}); ++l) {

int sp = k;
for (int t = max({i, 0}); t < min({(l) + 1, N}); ++t) {

int ip = l;
int lp = t;
J[i][j][k][l][s][t] += J[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

int ip = i;
for (int j = 0; j < N; ++j) {

int jp = j;
for (int k = 0; k < N; ++k) {

for (int t = max({j, 0}); t < min({(k) + 1, N}); ++t) {

for (int l = max({k, 0}); l < N; ++l) {

int tp = k;
int sp = t;
for (int s = max({l, 0}); s < min({(i) + 1, N}); ++s) {

int kp = l;
int lp = s;
J[i][j][k][l][s][t] += J[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int s = max({i, 0}); s < N; ++s) {

int sp = i;
int lp = s;
for (int j = 0; j < N; ++j) {

int jp = j;
for (int k = 0; k < N; ++k) {

for (int t = max({j, 0}); t < min({(k) + 1, N}); ++t) {

for (int l = max({k, 0}); l < min({(i) + 1, N}); ++l) {

int tp = k;
int ip = t;
int kp = l;
J[i][j][k][l][s][t] += J[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int l = 0; l < min({(i) + 1, N}); ++l) {

int ip = i;
int kp = l;
for (int j = 0; j < N; ++j) {

int jp = j;
for (int k = 0; k < N; ++k) {

for (int s = max({k, 0}); s < min({(l) + 1, N}); ++s) {

for (int t = max({j, 0}); t < min({(k) + 1, N}); ++t) {

int tp = k;
int sp = s;
int lp = t;
J[i][j][k][l][s][t] += J[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int l = max({i, 0}); l < N; ++l) {

int lp = i;
int kp = l;
for (int j = 0; j < N; ++j) {

int jp = j;
for (int k = 0; k < N; ++k) {

for (int s = max({k, 0}); s < min({(i) + 1, N}); ++s) {

for (int t = max({j, 0}); t < min({(k) + 1, N}); ++t) {

int tp = k;
int sp = s;
int ip = t;
J[i][j][k][l][s][t] += J[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int l = max({i, 0}); l < N; ++l) {

int sp = i;
for (int k = 0; k < min({(i) + 1, N}); ++k) {

for (int s = max({l, 0}); s < N; ++s) {

int kp = l;
int tp = k;
int ip = s;
for (int j = 0; j < N; ++j) {

for (int t = max({j, 0}); t < min({(k) + 1, N}); ++t) {

int jp = j;
int lp = t;
J[i][j][k][l][s][t] += J[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

int lp = i;
for (int k = 0; k < min({(i) + 1, N}); ++k) {

for (int j = 0; j < N; ++j) {

int tp = k;
for (int t = max({j, 0}); t < min({(k) + 1, N}); ++t) {

int jp = j;
int sp = t;
for (int l = 0; l < N; ++l) {

for (int s = max({i, 0}); s < min({(l) + 1, N}); ++s) {

int kp = l;
int ip = s;
J[i][j][k][l][s][t] += J[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

int ip = i;
for (int j = 0; j < N; ++j) {

int jp = j;
for (int k = 0; k < N; ++k) {

for (int s = max({k, 0}); s < min({(i) + 1, N}); ++s) {

for (int l = 0; l < min({(k) + 1, N}); ++l) {

int tp = k;
int kp = s;
for (int t = max({j, 0}); t < min({(l) + 1, N}); ++t) {

int lp = l;
int sp = t;
J[i][j][k][l][s][t] += J[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int s = max({i, 0}); s < N; ++s) {

int sp = i;
for (int k = 0; k < min({(i) + 1, N}); ++k) {

int kp = s;
for (int l = 0; l < min({(k) + 1, N}); ++l) {

int tp = k;
int lp = l;
for (int j = 0; j < N; ++j) {

for (int t = max({j, 0}); t < min({(l) + 1, N}); ++t) {

int jp = j;
int ip = t;
J[i][j][k][l][s][t] += J[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

int ip = i;
for (int k = 0; k < min({(i) + 1, N}); ++k) {

for (int j = 0; j < N; ++j) {

int tp = k;
int jp = j;
for (int l = 0; l < N; ++l) {

for (int s = max({l, 0}); s < min({(k) + 1, N}); ++s) {

for (int t = max({j, 0}); t < min({(l) + 1, N}); ++t) {

int lp = l;
int sp = s;
int kp = t;
J[i][j][k][l][s][t] += J[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

int kp = i;
for (int k = max({i, 0}); k < N; ++k) {

for (int j = 0; j < N; ++j) {

int tp = k;
int jp = j;
for (int l = 0; l < N; ++l) {

for (int s = max({l, 0}); s < min({(i) + 1, N}); ++s) {

for (int t = max({j, 0}); t < min({(l) + 1, N}); ++t) {

int lp = l;
int sp = s;
int ip = t;
J[i][j][k][l][s][t] += J[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int l = 0; l < min({(i) + 1, N}); ++l) {

int sp = i;
for (int k = max({i, 0}); k < N; ++k) {

int lp = l;
for (int s = max({k, 0}); s < N; ++s) {

int tp = k;
int ip = s;
for (int j = 0; j < N; ++j) {

for (int t = max({j, 0}); t < min({(l) + 1, N}); ++t) {

int jp = j;
int kp = t;
J[i][j][k][l][s][t] += J[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int l = 0; l < min({(i) + 1, N}); ++l) {

int kp = i;
int lp = l;
for (int j = 0; j < N; ++j) {

for (int t = max({j, 0}); t < min({(l) + 1, N}); ++t) {

int jp = j;
int sp = t;
for (int k = 0; k < N; ++k) {

for (int s = max({i, 0}); s < min({(k) + 1, N}); ++s) {

int tp = k;
int ip = s;
J[i][j][k][l][s][t] += J[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

int ip = i;
for (int j = 0; j < N; ++j) {

int jp = j;
for (int k = 0; k < N; ++k) {

for (int s = 0; s < min({(k) + 1, N}); ++s) {

for (int l = max({k, 0}); l < min({(i) + 1, N}); ++l) {

int tp = k;
for (int t = max({j, 0}); t < min({(s) + 1, N}); ++t) {

int kp = s;
int sp = l;
int lp = t;
J[i][j][k][l][s][t] += J[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int l = max({i, 0}); l < N; ++l) {

int lp = i;
for (int k = 0; k < min({(i) + 1, N}); ++k) {

int sp = l;
for (int s = 0; s < min({(k) + 1, N}); ++s) {

int tp = k;
int kp = s;
for (int j = 0; j < N; ++j) {

for (int t = max({j, 0}); t < min({(s) + 1, N}); ++t) {

int jp = j;
int ip = t;
J[i][j][k][l][s][t] += J[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

int ip = i;
for (int k = 0; k < min({(i) + 1, N}); ++k) {

for (int l = 0; l < min({(k) + 1, N}); ++l) {

int tp = k;
for (int s = 0; s < min({(l) + 1, N}); ++s) {

int sp = l;
int lp = s;
for (int j = 0; j < N; ++j) {

for (int t = max({j, 0}); t < min({(s) + 1, N}); ++t) {

int jp = j;
int kp = t;
J[i][j][k][l][s][t] += J[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int l = 0; l < min({(i) + 1, N}); ++l) {

int kp = i;
for (int k = max({i, 0}); k < N; ++k) {

for (int s = 0; s < min({(l) + 1, N}); ++s) {

int sp = l;
int tp = k;
int lp = s;
for (int j = 0; j < N; ++j) {

for (int t = max({j, 0}); t < min({(s) + 1, N}); ++t) {

int jp = j;
int ip = t;
J[i][j][k][l][s][t] += J[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int s = 0; s < min({(i) + 1, N}); ++s) {

int lp = i;
for (int k = max({i, 0}); k < N; ++k) {

int ip = s;
for (int l = max({k, 0}); l < N; ++l) {

int tp = k;
int sp = l;
for (int j = 0; j < N; ++j) {

for (int t = max({j, 0}); t < min({(s) + 1, N}); ++t) {

int jp = j;
int kp = t;
J[i][j][k][l][s][t] += J[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int s = 0; s < min({(i) + 1, N}); ++s) {

int kp = i;
int ip = s;
for (int j = 0; j < N; ++j) {

for (int t = max({j, 0}); t < min({(s) + 1, N}); ++t) {

int jp = j;
int lp = t;
for (int k = 0; k < N; ++k) {

for (int l = max({i, 0}); l < min({(k) + 1, N}); ++l) {

int tp = k;
int sp = l;
J[i][j][k][l][s][t] += J[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

int sp = i;
for (int k = max({i, 0}); k < N; ++k) {

for (int l = max({k, 0}); l < N; ++l) {

int tp = k;
for (int s = max({l, 0}); s < N; ++s) {

int ip = l;
int kp = s;
for (int j = 0; j < N; ++j) {

for (int t = max({j, 0}); t < min({(i) + 1, N}); ++t) {

int jp = j;
int lp = t;
J[i][j][k][l][s][t] += J[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

int lp = i;
for (int k = max({i, 0}); k < N; ++k) {

for (int j = 0; j < N; ++j) {

int tp = k;
for (int t = max({j, 0}); t < min({(i) + 1, N}); ++t) {

int jp = j;
int sp = t;
for (int l = 0; l < N; ++l) {

for (int s = max({k, 0}); s < min({(l) + 1, N}); ++s) {

int ip = l;
int kp = s;
J[i][j][k][l][s][t] += J[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

int sp = i;
for (int j = 0; j < N; ++j) {

for (int t = max({j, 0}); t < min({(i) + 1, N}); ++t) {

int jp = j;
int kp = t;
for (int k = 0; k < N; ++k) {

for (int s = max({k, 0}); s < N; ++s) {

for (int l = max({i, 0}); l < min({(k) + 1, N}); ++l) {

int tp = k;
int lp = s;
int ip = l;
J[i][j][k][l][s][t] += J[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int l = max({i, 0}); l < N; ++l) {

int kp = i;
int ip = l;
for (int j = 0; j < N; ++j) {

for (int t = max({j, 0}); t < min({(i) + 1, N}); ++t) {

int jp = j;
int sp = t;
for (int k = 0; k < N; ++k) {

for (int s = max({l, 0}); s < min({(k) + 1, N}); ++s) {

int tp = k;
int lp = s;
J[i][j][k][l][s][t] += J[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

int lp = i;
for (int j = 0; j < N; ++j) {

for (int t = max({j, 0}); t < min({(i) + 1, N}); ++t) {

int jp = j;
int kp = t;
for (int k = 0; k < N; ++k) {

for (int s = max({i, 0}); s < min({(k) + 1, N}); ++s) {

for (int l = max({k, 0}); l < N; ++l) {

int tp = k;
int sp = s;
int ip = l;
J[i][j][k][l][s][t] += J[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

int kp = i;
for (int j = 0; j < N; ++j) {

for (int t = max({j, 0}); t < min({(i) + 1, N}); ++t) {

int jp = j;
int lp = t;
for (int k = 0; k < N; ++k) {

for (int l = 0; l < min({(k) + 1, N}); ++l) {

int tp = k;
for (int s = max({i, 0}); s < min({(l) + 1, N}); ++s) {

int ip = l;
int sp = s;
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

int tp = i;
int jp = j;
for (int l = max({k, 0}); l < N; ++l) {

int ip = k;
for (int s = max({l, 0}); s < N; ++s) {

int kp = l;
for (int t = max({s, 0}); t < N; ++t) {

int lp = s;
int sp = t;
J[i][j][k][l][s][t] += J[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

int sp = i;
for (int j = 0; j < min({(i) + 1, N}); ++j) {

for (int k = max({i, 0}); k < N; ++k) {

int jp = j;
for (int l = max({k, 0}); l < N; ++l) {

int ip = k;
int kp = l;
for (int s = 0; s < N; ++s) {

for (int t = max({l, 0}); t < min({(s) + 1, N}); ++t) {

int lp = s;
int tp = t;
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

int tp = i;
int jp = j;
int ip = k;
for (int l = 0; l < N; ++l) {

for (int s = max({k, 0}); s < min({(l) + 1, N}); ++s) {

for (int t = max({l, 0}); t < N; ++t) {

int kp = l;
int sp = s;
int lp = t;
J[i][j][k][l][s][t] += J[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

int lp = i;
for (int j = 0; j < min({(i) + 1, N}); ++j) {

for (int k = max({i, 0}); k < N; ++k) {

int jp = j;
for (int s = max({k, 0}); s < N; ++s) {

int ip = k;
int sp = s;
for (int l = 0; l < N; ++l) {

for (int t = max({s, 0}); t < min({(l) + 1, N}); ++t) {

int kp = l;
int tp = t;
J[i][j][k][l][s][t] += J[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

int sp = i;
for (int j = 0; j < min({(i) + 1, N}); ++j) {

for (int k = max({i, 0}); k < N; ++k) {

int jp = j;
int ip = k;
for (int l = 0; l < N; ++l) {

for (int s = max({l, 0}); s < N; ++s) {

for (int t = max({k, 0}); t < min({(l) + 1, N}); ++t) {

int kp = l;
int tp = s;
int lp = t;
J[i][j][k][l][s][t] += J[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

int lp = i;
for (int j = 0; j < min({(i) + 1, N}); ++j) {

for (int k = max({i, 0}); k < N; ++k) {

int jp = j;
int ip = k;
for (int l = 0; l < N; ++l) {

for (int s = 0; s < min({(l) + 1, N}); ++s) {

int kp = l;
for (int t = max({k, 0}); t < min({(s) + 1, N}); ++t) {

int tp = s;
int sp = t;
J[i][j][k][l][s][t] += J[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int j = 0; j < min({(i) + 1, N}); ++j) {

int tp = i;
int jp = j;
for (int k = 0; k < N; ++k) {

for (int s = max({k, 0}); s < N; ++s) {

for (int l = max({i, 0}); l < min({(k) + 1, N}); ++l) {

int ip = k;
for (int t = max({s, 0}); t < N; ++t) {

int kp = s;
int lp = l;
int sp = t;
J[i][j][k][l][s][t] += J[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

int sp = i;
for (int j = 0; j < min({(i) + 1, N}); ++j) {

int jp = j;
for (int k = 0; k < N; ++k) {

for (int l = max({i, 0}); l < min({(k) + 1, N}); ++l) {

int ip = k;
int lp = l;
for (int s = 0; s < N; ++s) {

for (int t = max({k, 0}); t < min({(s) + 1, N}); ++t) {

int kp = s;
int tp = t;
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

int tp = i;
int lp = l;
int jp = j;
for (int k = 0; k < N; ++k) {

for (int s = max({l, 0}); s < min({(k) + 1, N}); ++s) {

for (int t = max({k, 0}); t < N; ++t) {

int ip = k;
int sp = s;
int kp = t;
J[i][j][k][l][s][t] += J[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int l = max({i, 0}); l < N; ++l) {

int kp = i;
for (int j = 0; j < min({(i) + 1, N}); ++j) {

for (int s = max({l, 0}); s < N; ++s) {

int lp = l;
int jp = j;
int sp = s;
for (int k = 0; k < N; ++k) {

for (int t = max({s, 0}); t < min({(k) + 1, N}); ++t) {

int ip = k;
int tp = t;
J[i][j][k][l][s][t] += J[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int l = max({i, 0}); l < N; ++l) {

int sp = i;
for (int j = 0; j < min({(i) + 1, N}); ++j) {

int lp = l;
int jp = j;
for (int k = 0; k < N; ++k) {

for (int s = max({k, 0}); s < N; ++s) {

for (int t = max({l, 0}); t < min({(k) + 1, N}); ++t) {

int ip = k;
int tp = s;
int kp = t;
J[i][j][k][l][s][t] += J[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int l = max({i, 0}); l < N; ++l) {

int kp = i;
for (int j = 0; j < min({(i) + 1, N}); ++j) {

int lp = l;
int jp = j;
for (int k = 0; k < N; ++k) {

for (int s = 0; s < min({(k) + 1, N}); ++s) {

int ip = k;
for (int t = max({l, 0}); t < min({(s) + 1, N}); ++t) {

int tp = s;
int sp = t;
J[i][j][k][l][s][t] += J[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int j = 0; j < min({(i) + 1, N}); ++j) {

int tp = i;
int jp = j;
for (int k = 0; k < N; ++k) {

for (int s = max({i, 0}); s < min({(k) + 1, N}); ++s) {

for (int l = max({k, 0}); l < N; ++l) {

int ip = k;
int kp = s;
for (int t = max({l, 0}); t < N; ++t) {

int sp = l;
int lp = t;
J[i][j][k][l][s][t] += J[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

int lp = i;
for (int j = 0; j < min({(i) + 1, N}); ++j) {

int jp = j;
for (int k = 0; k < N; ++k) {

for (int s = max({i, 0}); s < min({(k) + 1, N}); ++s) {

int ip = k;
int kp = s;
for (int l = 0; l < N; ++l) {

for (int t = max({k, 0}); t < min({(l) + 1, N}); ++t) {

int sp = l;
int tp = t;
J[i][j][k][l][s][t] += J[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int j = 0; j < min({(i) + 1, N}); ++j) {

int tp = i;
int jp = j;
for (int k = 0; k < N; ++k) {

for (int t = max({k, 0}); t < N; ++t) {

for (int l = 0; l < min({(k) + 1, N}); ++l) {

int ip = k;
int kp = t;
for (int s = max({i, 0}); s < min({(l) + 1, N}); ++s) {

int sp = l;
int lp = s;
J[i][j][k][l][s][t] += J[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

int kp = i;
for (int j = 0; j < min({(i) + 1, N}); ++j) {

int jp = j;
for (int k = 0; k < N; ++k) {

for (int l = 0; l < N; ++l) {

int ip = k;
for (int s = max({i, 0}); s < min({(l) + 1, N}); ++s) {

for (int t = max({l, 0}); t < min({(k) + 1, N}); ++t) {

int sp = l;
int lp = s;
int tp = t;
J[i][j][k][l][s][t] += J[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int s = max({i, 0}); s < N; ++s) {

int lp = i;
for (int j = 0; j < min({(i) + 1, N}); ++j) {

int tp = s;
int jp = j;
for (int k = 0; k < N; ++k) {

for (int t = max({s, 0}); t < min({(k) + 1, N}); ++t) {

for (int l = max({k, 0}); l < N; ++l) {

int ip = k;
int kp = t;
int sp = l;
J[i][j][k][l][s][t] += J[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int s = max({i, 0}); s < N; ++s) {

int kp = i;
for (int j = 0; j < min({(i) + 1, N}); ++j) {

int tp = s;
int jp = j;
for (int k = 0; k < N; ++k) {

for (int l = 0; l < min({(k) + 1, N}); ++l) {

int ip = k;
for (int t = max({s, 0}); t < min({(l) + 1, N}); ++t) {

int sp = l;
int lp = t;
J[i][j][k][l][s][t] += J[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

int sp = i;
for (int j = 0; j < min({(i) + 1, N}); ++j) {

int jp = j;
for (int k = 0; k < N; ++k) {

for (int t = max({i, 0}); t < min({(k) + 1, N}); ++t) {

for (int l = max({k, 0}); l < N; ++l) {

int ip = k;
int lp = t;
for (int s = max({l, 0}); s < N; ++s) {

int tp = l;
int kp = s;
J[i][j][k][l][s][t] += J[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

int lp = i;
for (int j = 0; j < min({(i) + 1, N}); ++j) {

int jp = j;
for (int k = 0; k < N; ++k) {

for (int t = max({i, 0}); t < min({(k) + 1, N}); ++t) {

int ip = k;
int sp = t;
for (int l = 0; l < N; ++l) {

for (int s = max({k, 0}); s < min({(l) + 1, N}); ++s) {

int tp = l;
int kp = s;
J[i][j][k][l][s][t] += J[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

int sp = i;
for (int j = 0; j < min({(i) + 1, N}); ++j) {

int jp = j;
for (int k = 0; k < N; ++k) {

for (int s = max({k, 0}); s < N; ++s) {

for (int l = 0; l < min({(k) + 1, N}); ++l) {

int ip = k;
int lp = s;
for (int t = max({i, 0}); t < min({(l) + 1, N}); ++t) {

int tp = l;
int kp = t;
J[i][j][k][l][s][t] += J[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

int kp = i;
for (int j = 0; j < min({(i) + 1, N}); ++j) {

int jp = j;
for (int k = 0; k < N; ++k) {

for (int l = 0; l < N; ++l) {

int ip = k;
for (int s = max({l, 0}); s < min({(k) + 1, N}); ++s) {

for (int t = max({i, 0}); t < min({(l) + 1, N}); ++t) {

int tp = l;
int lp = s;
int sp = t;
J[i][j][k][l][s][t] += J[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

int lp = i;
for (int j = 0; j < min({(i) + 1, N}); ++j) {

int jp = j;
for (int k = 0; k < N; ++k) {

for (int s = 0; s < min({(k) + 1, N}); ++s) {

for (int l = max({k, 0}); l < N; ++l) {

int ip = k;
for (int t = max({i, 0}); t < min({(s) + 1, N}); ++t) {

int sp = s;
int tp = l;
int kp = t;
J[i][j][k][l][s][t] += J[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

int kp = i;
for (int j = 0; j < min({(i) + 1, N}); ++j) {

int jp = j;
for (int k = 0; k < N; ++k) {

for (int l = 0; l < min({(k) + 1, N}); ++l) {

int ip = k;
for (int s = 0; s < min({(l) + 1, N}); ++s) {

int tp = l;
for (int t = max({i, 0}); t < min({(s) + 1, N}); ++t) {

int sp = s;
int lp = t;
J[i][j][k][l][s][t] += J[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

int ip = i;
for (int j = 0; j < N; ++j) {

for (int l = max({j, 0}); l < N; ++l) {

int kp = j;
for (int k = 0; k < min({(j) + 1, N}); ++k) {

for (int s = max({l, 0}); s < N; ++s) {

int lp = l;
int jp = k;
for (int t = max({s, 0}); t < min({(i) + 1, N}); ++t) {

int sp = s;
int tp = t;
J[i][j][k][l][s][t] += J[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int t = max({i, 0}); t < N; ++t) {

int tp = i;
int ip = t;
for (int j = 0; j < N; ++j) {

for (int l = max({j, 0}); l < N; ++l) {

int kp = j;
for (int k = 0; k < min({(j) + 1, N}); ++k) {

for (int s = max({l, 0}); s < min({(i) + 1, N}); ++s) {

int lp = l;
int jp = k;
int sp = s;
J[i][j][k][l][s][t] += J[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int s = 0; s < min({(i) + 1, N}); ++s) {

int ip = i;
int tp = s;
for (int j = 0; j < N; ++j) {

for (int l = max({j, 0}); l < N; ++l) {

int kp = j;
for (int k = 0; k < min({(j) + 1, N}); ++k) {

for (int t = max({l, 0}); t < min({(s) + 1, N}); ++t) {

int lp = l;
int jp = k;
int sp = t;
J[i][j][k][l][s][t] += J[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int s = max({i, 0}); s < N; ++s) {

int sp = i;
int tp = s;
for (int j = 0; j < N; ++j) {

for (int l = max({j, 0}); l < N; ++l) {

int kp = j;
for (int k = 0; k < min({(j) + 1, N}); ++k) {

for (int t = max({l, 0}); t < min({(i) + 1, N}); ++t) {

int lp = l;
int jp = k;
int ip = t;
J[i][j][k][l][s][t] += J[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int s = max({i, 0}); s < N; ++s) {

int tp = i;
for (int t = max({s, 0}); t < N; ++t) {

int ip = s;
int sp = t;
for (int j = 0; j < N; ++j) {

for (int l = max({j, 0}); l < min({(i) + 1, N}); ++l) {

int kp = j;
for (int k = 0; k < min({(j) + 1, N}); ++k) {

int lp = l;
int jp = k;
J[i][j][k][l][s][t] += J[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

int sp = i;
for (int j = 0; j < N; ++j) {

for (int l = max({j, 0}); l < min({(i) + 1, N}); ++l) {

int kp = j;
for (int k = 0; k < min({(j) + 1, N}); ++k) {

int lp = l;
int jp = k;
for (int s = 0; s < N; ++s) {

for (int t = max({i, 0}); t < min({(s) + 1, N}); ++t) {

int ip = s;
int tp = t;
J[i][j][k][l][s][t] += J[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

int ip = i;
for (int j = 0; j < N; ++j) {

int kp = j;
for (int k = 0; k < min({(j) + 1, N}); ++k) {

for (int l = 0; l < N; ++l) {

int jp = k;
for (int s = max({j, 0}); s < min({(l) + 1, N}); ++s) {

for (int t = max({l, 0}); t < min({(i) + 1, N}); ++t) {

int sp = l;
int lp = s;
int tp = t;
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

int tp = i;
int ip = t;
int sp = l;
for (int j = 0; j < N; ++j) {

for (int s = max({j, 0}); s < min({(l) + 1, N}); ++s) {

int kp = j;
for (int k = 0; k < min({(j) + 1, N}); ++k) {

int lp = s;
int jp = k;
J[i][j][k][l][s][t] += J[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int l = 0; l < min({(i) + 1, N}); ++l) {

int ip = i;
int sp = l;
for (int j = 0; j < N; ++j) {

for (int s = max({j, 0}); s < N; ++s) {

int kp = j;
for (int k = 0; k < min({(j) + 1, N}); ++k) {

for (int t = max({s, 0}); t < min({(l) + 1, N}); ++t) {

int tp = s;
int jp = k;
int lp = t;
J[i][j][k][l][s][t] += J[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int l = max({i, 0}); l < N; ++l) {

int lp = i;
int sp = l;
for (int j = 0; j < N; ++j) {

for (int s = max({j, 0}); s < N; ++s) {

int kp = j;
for (int k = 0; k < min({(j) + 1, N}); ++k) {

for (int t = max({s, 0}); t < min({(i) + 1, N}); ++t) {

int tp = s;
int jp = k;
int ip = t;
J[i][j][k][l][s][t] += J[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int l = max({i, 0}); l < N; ++l) {

int tp = i;
for (int t = max({l, 0}); t < N; ++t) {

int sp = l;
int lp = t;
for (int j = 0; j < N; ++j) {

for (int s = max({j, 0}); s < min({(i) + 1, N}); ++s) {

int kp = j;
for (int k = 0; k < min({(j) + 1, N}); ++k) {

int ip = s;
int jp = k;
J[i][j][k][l][s][t] += J[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

int lp = i;
for (int j = 0; j < N; ++j) {

for (int s = max({j, 0}); s < min({(i) + 1, N}); ++s) {

int kp = j;
for (int k = 0; k < min({(j) + 1, N}); ++k) {

int ip = s;
int jp = k;
for (int l = 0; l < N; ++l) {

for (int t = max({i, 0}); t < min({(l) + 1, N}); ++t) {

int sp = l;
int tp = t;
J[i][j][k][l][s][t] += J[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

int ip = i;
for (int j = 0; j < N; ++j) {

int kp = j;
for (int k = 0; k < min({(j) + 1, N}); ++k) {

for (int l = 0; l < N; ++l) {

int jp = k;
for (int s = max({l, 0}); s < min({(i) + 1, N}); ++s) {

for (int t = max({j, 0}); t < min({(l) + 1, N}); ++t) {

int tp = l;
int lp = s;
int sp = t;
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

int sp = i;
int lp = s;
int tp = l;
for (int j = 0; j < N; ++j) {

for (int t = max({j, 0}); t < min({(l) + 1, N}); ++t) {

int kp = j;
for (int k = 0; k < min({(j) + 1, N}); ++k) {

int ip = t;
int jp = k;
J[i][j][k][l][s][t] += J[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int l = 0; l < min({(i) + 1, N}); ++l) {

int ip = i;
for (int s = 0; s < min({(l) + 1, N}); ++s) {

int tp = l;
int sp = s;
for (int j = 0; j < N; ++j) {

for (int t = max({j, 0}); t < min({(s) + 1, N}); ++t) {

int kp = j;
for (int k = 0; k < min({(j) + 1, N}); ++k) {

int lp = t;
int jp = k;
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

int lp = i;
int sp = s;
int tp = l;
for (int j = 0; j < N; ++j) {

for (int t = max({j, 0}); t < min({(s) + 1, N}); ++t) {

int kp = j;
for (int k = 0; k < min({(j) + 1, N}); ++k) {

int ip = t;
int jp = k;
J[i][j][k][l][s][t] += J[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int l = max({i, 0}); l < N; ++l) {

int sp = i;
for (int s = max({l, 0}); s < N; ++s) {

int tp = l;
int ip = s;
for (int j = 0; j < N; ++j) {

for (int t = max({j, 0}); t < min({(i) + 1, N}); ++t) {

int kp = j;
for (int k = 0; k < min({(j) + 1, N}); ++k) {

int lp = t;
int jp = k;
J[i][j][k][l][s][t] += J[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

int lp = i;
for (int j = 0; j < N; ++j) {

for (int t = max({j, 0}); t < min({(i) + 1, N}); ++t) {

int kp = j;
for (int k = 0; k < min({(j) + 1, N}); ++k) {

int sp = t;
int jp = k;
for (int l = 0; l < N; ++l) {

for (int s = max({i, 0}); s < min({(l) + 1, N}); ++s) {

int tp = l;
int ip = s;
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

int tp = i;
for (int s = max({l, 0}); s < N; ++s) {

int ip = l;
int kp = j;
for (int k = 0; k < min({(j) + 1, N}); ++k) {

for (int t = max({s, 0}); t < N; ++t) {

int lp = s;
int jp = k;
int sp = t;
J[i][j][k][l][s][t] += J[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int l = max({i, 0}); l < N; ++l) {

int sp = i;
for (int j = 0; j < min({(i) + 1, N}); ++j) {

int ip = l;
int kp = j;
for (int k = 0; k < min({(j) + 1, N}); ++k) {

int jp = k;
for (int s = 0; s < N; ++s) {

for (int t = max({l, 0}); t < min({(s) + 1, N}); ++t) {

int lp = s;
int tp = t;
J[i][j][k][l][s][t] += J[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int j = 0; j < min({(i) + 1, N}); ++j) {

int tp = i;
int kp = j;
for (int k = 0; k < min({(j) + 1, N}); ++k) {

for (int l = 0; l < N; ++l) {

int jp = k;
for (int s = max({i, 0}); s < min({(l) + 1, N}); ++s) {

for (int t = max({l, 0}); t < N; ++t) {

int ip = l;
int sp = s;
int lp = t;
J[i][j][k][l][s][t] += J[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int s = max({i, 0}); s < N; ++s) {

int lp = i;
for (int j = 0; j < min({(i) + 1, N}); ++j) {

int sp = s;
int kp = j;
for (int k = 0; k < min({(j) + 1, N}); ++k) {

for (int l = 0; l < N; ++l) {

int jp = k;
for (int t = max({s, 0}); t < min({(l) + 1, N}); ++t) {

int ip = l;
int tp = t;
J[i][j][k][l][s][t] += J[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

int sp = i;
for (int j = 0; j < min({(i) + 1, N}); ++j) {

int kp = j;
for (int k = 0; k < min({(j) + 1, N}); ++k) {

for (int l = 0; l < N; ++l) {

int jp = k;
for (int s = max({l, 0}); s < N; ++s) {

for (int t = max({i, 0}); t < min({(l) + 1, N}); ++t) {

int ip = l;
int tp = s;
int lp = t;
J[i][j][k][l][s][t] += J[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

int lp = i;
for (int j = 0; j < min({(i) + 1, N}); ++j) {

int kp = j;
for (int k = 0; k < min({(j) + 1, N}); ++k) {

for (int l = 0; l < N; ++l) {

int jp = k;
for (int s = 0; s < min({(l) + 1, N}); ++s) {

int ip = l;
for (int t = max({i, 0}); t < min({(s) + 1, N}); ++t) {

int tp = s;
int sp = t;
J[i][j][k][l][s][t] += J[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

int ip = i;
for (int j = 0; j < N; ++j) {

for (int s = max({j, 0}); s < N; ++s) {

int kp = j;
for (int t = max({s, 0}); t < min({(i) + 1, N}); ++t) {

int sp = s;
int tp = t;
for (int k = 0; k < N; ++k) {

for (int l = max({k, 0}); l < min({(j) + 1, N}); ++l) {

int lp = k;
int jp = l;
J[i][j][k][l][s][t] += J[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int t = max({i, 0}); t < N; ++t) {

int tp = i;
int ip = t;
for (int j = 0; j < N; ++j) {

for (int s = max({j, 0}); s < min({(i) + 1, N}); ++s) {

int kp = j;
int sp = s;
for (int k = 0; k < N; ++k) {

for (int l = max({k, 0}); l < min({(j) + 1, N}); ++l) {

int lp = k;
int jp = l;
J[i][j][k][l][s][t] += J[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int s = 0; s < min({(i) + 1, N}); ++s) {

int ip = i;
int tp = s;
for (int j = 0; j < N; ++j) {

for (int t = max({j, 0}); t < min({(s) + 1, N}); ++t) {

int kp = j;
int sp = t;
for (int k = 0; k < N; ++k) {

for (int l = max({k, 0}); l < min({(j) + 1, N}); ++l) {

int lp = k;
int jp = l;
J[i][j][k][l][s][t] += J[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int s = max({i, 0}); s < N; ++s) {

int sp = i;
int tp = s;
for (int j = 0; j < N; ++j) {

for (int t = max({j, 0}); t < min({(i) + 1, N}); ++t) {

int kp = j;
int ip = t;
for (int k = 0; k < N; ++k) {

for (int l = max({k, 0}); l < min({(j) + 1, N}); ++l) {

int lp = k;
int jp = l;
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

int tp = i;
for (int t = max({s, 0}); t < N; ++t) {

int ip = s;
int kp = j;
int sp = t;
for (int k = 0; k < N; ++k) {

for (int l = max({k, 0}); l < min({(j) + 1, N}); ++l) {

int lp = k;
int jp = l;
J[i][j][k][l][s][t] += J[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

int sp = i;
for (int j = 0; j < min({(i) + 1, N}); ++j) {

int kp = j;
for (int k = 0; k < N; ++k) {

for (int l = max({k, 0}); l < min({(j) + 1, N}); ++l) {

int lp = k;
int jp = l;
for (int s = 0; s < N; ++s) {

for (int t = max({i, 0}); t < min({(s) + 1, N}); ++t) {

int ip = s;
int tp = t;
J[i][j][k][l][s][t] += J[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

int ip = i;
for (int j = 0; j < N; ++j) {

for (int t = max({j, 0}); t < min({(i) + 1, N}); ++t) {

int kp = j;
int tp = t;
for (int k = 0; k < N; ++k) {

for (int l = max({k, 0}); l < N; ++l) {

int lp = k;
for (int s = max({l, 0}); s < min({(j) + 1, N}); ++s) {

int sp = l;
int jp = s;
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

int tp = i;
int ip = t;
int kp = j;
for (int k = 0; k < N; ++k) {

for (int l = max({k, 0}); l < N; ++l) {

int lp = k;
for (int s = max({l, 0}); s < min({(j) + 1, N}); ++s) {

int sp = l;
int jp = s;
J[i][j][k][l][s][t] += J[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

int ip = i;
for (int j = 0; j < min({(i) + 1, N}); ++j) {

int kp = j;
for (int k = 0; k < N; ++k) {

for (int l = max({k, 0}); l < N; ++l) {

int lp = k;
for (int s = max({l, 0}); s < N; ++s) {

int sp = l;
for (int t = max({s, 0}); t < min({(j) + 1, N}); ++t) {

int tp = s;
int jp = t;
J[i][j][k][l][s][t] += J[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

int jp = i;
for (int j = max({i, 0}); j < N; ++j) {

int kp = j;
for (int k = 0; k < N; ++k) {

for (int l = max({k, 0}); l < N; ++l) {

int lp = k;
for (int s = max({l, 0}); s < N; ++s) {

int sp = l;
for (int t = max({s, 0}); t < min({(i) + 1, N}); ++t) {

int tp = s;
int ip = t;
J[i][j][k][l][s][t] += J[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int j = max({i, 0}); j < N; ++j) {

int tp = i;
for (int t = max({j, 0}); t < N; ++t) {

int kp = j;
int jp = t;
for (int k = 0; k < N; ++k) {

for (int l = max({k, 0}); l < N; ++l) {

int lp = k;
for (int s = max({l, 0}); s < min({(i) + 1, N}); ++s) {

int sp = l;
int ip = s;
J[i][j][k][l][s][t] += J[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

int jp = i;
for (int j = 0; j < N; ++j) {

for (int t = max({i, 0}); t < min({(j) + 1, N}); ++t) {

int kp = j;
int tp = t;
for (int k = 0; k < N; ++k) {

for (int l = max({k, 0}); l < N; ++l) {

int lp = k;
for (int s = max({l, 0}); s < min({(i) + 1, N}); ++s) {

int sp = l;
int ip = s;
J[i][j][k][l][s][t] += J[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

int ip = i;
for (int j = 0; j < N; ++j) {

for (int s = max({j, 0}); s < min({(i) + 1, N}); ++s) {

int kp = j;
int jp = s;
for (int k = 0; k < N; ++k) {

for (int l = max({k, 0}); l < N; ++l) {

int lp = k;
for (int t = max({l, 0}); t < min({(j) + 1, N}); ++t) {

int tp = l;
int sp = t;
J[i][j][k][l][s][t] += J[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int s = max({i, 0}); s < N; ++s) {

int sp = i;
for (int j = 0; j < min({(i) + 1, N}); ++j) {

int jp = s;
int kp = j;
for (int k = 0; k < N; ++k) {

for (int l = max({k, 0}); l < N; ++l) {

int lp = k;
for (int t = max({l, 0}); t < min({(j) + 1, N}); ++t) {

int tp = l;
int ip = t;
J[i][j][k][l][s][t] += J[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

int ip = i;
for (int j = 0; j < min({(i) + 1, N}); ++j) {

for (int s = 0; s < min({(j) + 1, N}); ++s) {

int kp = j;
int sp = s;
for (int k = 0; k < N; ++k) {

for (int l = max({k, 0}); l < N; ++l) {

int lp = k;
for (int t = max({l, 0}); t < min({(s) + 1, N}); ++t) {

int tp = l;
int jp = t;
J[i][j][k][l][s][t] += J[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int s = 0; s < min({(i) + 1, N}); ++s) {

int jp = i;
for (int j = max({i, 0}); j < N; ++j) {

int sp = s;
int kp = j;
for (int k = 0; k < N; ++k) {

for (int l = max({k, 0}); l < N; ++l) {

int lp = k;
for (int t = max({l, 0}); t < min({(s) + 1, N}); ++t) {

int tp = l;
int ip = t;
J[i][j][k][l][s][t] += J[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

int sp = i;
for (int j = max({i, 0}); j < N; ++j) {

for (int s = max({j, 0}); s < N; ++s) {

int kp = j;
int ip = s;
for (int k = 0; k < N; ++k) {

for (int l = max({k, 0}); l < N; ++l) {

int lp = k;
for (int t = max({l, 0}); t < min({(i) + 1, N}); ++t) {

int tp = l;
int jp = t;
J[i][j][k][l][s][t] += J[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

int jp = i;
for (int j = 0; j < N; ++j) {

for (int s = max({i, 0}); s < min({(j) + 1, N}); ++s) {

int kp = j;
int ip = s;
for (int k = 0; k < N; ++k) {

for (int l = max({k, 0}); l < N; ++l) {

int lp = k;
for (int t = max({l, 0}); t < min({(i) + 1, N}); ++t) {

int tp = l;
int sp = t;
J[i][j][k][l][s][t] += J[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int j = max({i, 0}); j < N; ++j) {

int tp = i;
for (int s = max({j, 0}); s < N; ++s) {

int kp = j;
for (int t = max({s, 0}); t < N; ++t) {

int jp = s;
int sp = t;
for (int k = 0; k < N; ++k) {

for (int l = max({k, 0}); l < min({(i) + 1, N}); ++l) {

int lp = k;
int ip = l;
J[i][j][k][l][s][t] += J[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

int sp = i;
for (int j = max({i, 0}); j < N; ++j) {

int kp = j;
for (int k = 0; k < N; ++k) {

for (int l = max({k, 0}); l < min({(i) + 1, N}); ++l) {

int lp = k;
int ip = l;
for (int s = 0; s < N; ++s) {

for (int t = max({j, 0}); t < min({(s) + 1, N}); ++t) {

int jp = s;
int tp = t;
J[i][j][k][l][s][t] += J[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int j = 0; j < N; ++j) {

int tp = i;
for (int s = max({i, 0}); s < min({(j) + 1, N}); ++s) {

for (int t = max({j, 0}); t < N; ++t) {

int kp = j;
int sp = s;
int jp = t;
for (int k = 0; k < N; ++k) {

for (int l = max({k, 0}); l < min({(i) + 1, N}); ++l) {

int lp = k;
int ip = l;
J[i][j][k][l][s][t] += J[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int s = max({i, 0}); s < N; ++s) {

int jp = i;
int sp = s;
for (int j = 0; j < N; ++j) {

for (int t = max({s, 0}); t < min({(j) + 1, N}); ++t) {

int kp = j;
int tp = t;
for (int k = 0; k < N; ++k) {

for (int l = max({k, 0}); l < min({(i) + 1, N}); ++l) {

int lp = k;
int ip = l;
J[i][j][k][l][s][t] += J[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

int sp = i;
for (int j = 0; j < N; ++j) {

for (int s = max({j, 0}); s < N; ++s) {

for (int t = max({i, 0}); t < min({(j) + 1, N}); ++t) {

int kp = j;
int tp = s;
int jp = t;
for (int k = 0; k < N; ++k) {

for (int l = max({k, 0}); l < min({(i) + 1, N}); ++l) {

int lp = k;
int ip = l;
J[i][j][k][l][s][t] += J[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

int jp = i;
for (int j = 0; j < N; ++j) {

for (int s = 0; s < min({(j) + 1, N}); ++s) {

int kp = j;
for (int t = max({i, 0}); t < min({(s) + 1, N}); ++t) {

int tp = s;
int sp = t;
for (int k = 0; k < N; ++k) {

for (int l = max({k, 0}); l < min({(i) + 1, N}); ++l) {

int lp = k;
int ip = l;
J[i][j][k][l][s][t] += J[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

int ip = i;
for (int j = 0; j < N; ++j) {

for (int l = max({j, 0}); l < N; ++l) {

int kp = j;
for (int t = max({l, 0}); t < min({(i) + 1, N}); ++t) {

int jp = l;
int tp = t;
for (int k = 0; k < N; ++k) {

for (int s = max({k, 0}); s < min({(j) + 1, N}); ++s) {

int sp = k;
int lp = s;
J[i][j][k][l][s][t] += J[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int t = max({i, 0}); t < N; ++t) {

int tp = i;
int ip = t;
for (int j = 0; j < N; ++j) {

for (int l = max({j, 0}); l < min({(i) + 1, N}); ++l) {

int kp = j;
int jp = l;
for (int k = 0; k < N; ++k) {

for (int s = max({k, 0}); s < min({(j) + 1, N}); ++s) {

int sp = k;
int lp = s;
J[i][j][k][l][s][t] += J[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int l = 0; l < min({(i) + 1, N}); ++l) {

int ip = i;
int jp = l;
for (int j = 0; j < N; ++j) {

for (int t = max({j, 0}); t < min({(l) + 1, N}); ++t) {

int kp = j;
int lp = t;
for (int k = 0; k < N; ++k) {

for (int s = max({k, 0}); s < min({(j) + 1, N}); ++s) {

int sp = k;
int tp = s;
J[i][j][k][l][s][t] += J[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int l = max({i, 0}); l < N; ++l) {

int lp = i;
int jp = l;
for (int j = 0; j < N; ++j) {

for (int t = max({j, 0}); t < min({(i) + 1, N}); ++t) {

int kp = j;
int ip = t;
for (int k = 0; k < N; ++k) {

for (int s = max({k, 0}); s < min({(j) + 1, N}); ++s) {

int sp = k;
int tp = s;
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

int tp = i;
for (int t = max({l, 0}); t < N; ++t) {

int jp = l;
int kp = j;
int lp = t;
for (int k = 0; k < N; ++k) {

for (int s = max({k, 0}); s < min({(j) + 1, N}); ++s) {

int sp = k;
int ip = s;
J[i][j][k][l][s][t] += J[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

int lp = i;
for (int j = 0; j < min({(i) + 1, N}); ++j) {

int kp = j;
for (int k = 0; k < N; ++k) {

for (int s = max({k, 0}); s < min({(j) + 1, N}); ++s) {

int sp = k;
int ip = s;
for (int l = 0; l < N; ++l) {

for (int t = max({i, 0}); t < min({(l) + 1, N}); ++t) {

int jp = l;
int tp = t;
J[i][j][k][l][s][t] += J[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

int ip = i;
for (int j = 0; j < N; ++j) {

for (int t = max({j, 0}); t < min({(i) + 1, N}); ++t) {

for (int l = 0; l < min({(j) + 1, N}); ++l) {

int kp = j;
int tp = t;
int lp = l;
for (int k = 0; k < N; ++k) {

for (int s = max({k, 0}); s < min({(l) + 1, N}); ++s) {

int sp = k;
int jp = s;
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

int tp = i;
int ip = t;
for (int l = 0; l < min({(j) + 1, N}); ++l) {

int kp = j;
int lp = l;
for (int k = 0; k < N; ++k) {

for (int s = max({k, 0}); s < min({(l) + 1, N}); ++s) {

int sp = k;
int jp = s;
J[i][j][k][l][s][t] += J[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

int ip = i;
for (int j = 0; j < min({(i) + 1, N}); ++j) {

int kp = j;
for (int k = 0; k < N; ++k) {

for (int l = 0; l < N; ++l) {

int sp = k;
for (int s = max({k, 0}); s < min({(l) + 1, N}); ++s) {

for (int t = max({l, 0}); t < min({(j) + 1, N}); ++t) {

int lp = l;
int tp = s;
int jp = t;
J[i][j][k][l][s][t] += J[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

int jp = i;
for (int j = max({i, 0}); j < N; ++j) {

int kp = j;
for (int k = 0; k < N; ++k) {

for (int l = 0; l < N; ++l) {

int sp = k;
for (int s = max({k, 0}); s < min({(l) + 1, N}); ++s) {

for (int t = max({l, 0}); t < min({(i) + 1, N}); ++t) {

int lp = l;
int tp = s;
int ip = t;
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

int tp = i;
int lp = l;
for (int t = max({j, 0}); t < N; ++t) {

int kp = j;
int jp = t;
for (int k = 0; k < N; ++k) {

for (int s = max({k, 0}); s < min({(l) + 1, N}); ++s) {

int sp = k;
int ip = s;
J[i][j][k][l][s][t] += J[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int l = 0; l < min({(i) + 1, N}); ++l) {

int jp = i;
int lp = l;
for (int j = 0; j < N; ++j) {

for (int t = max({i, 0}); t < min({(j) + 1, N}); ++t) {

int kp = j;
int tp = t;
for (int k = 0; k < N; ++k) {

for (int s = max({k, 0}); s < min({(l) + 1, N}); ++s) {

int sp = k;
int ip = s;
J[i][j][k][l][s][t] += J[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

int ip = i;
for (int j = 0; j < N; ++j) {

for (int l = max({j, 0}); l < min({(i) + 1, N}); ++l) {

int kp = j;
int tp = l;
for (int k = 0; k < N; ++k) {

for (int s = max({k, 0}); s < N; ++s) {

int sp = k;
for (int t = max({s, 0}); t < min({(j) + 1, N}); ++t) {

int jp = s;
int lp = t;
J[i][j][k][l][s][t] += J[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int l = max({i, 0}); l < N; ++l) {

int lp = i;
for (int j = 0; j < min({(i) + 1, N}); ++j) {

int tp = l;
int kp = j;
for (int k = 0; k < N; ++k) {

for (int s = max({k, 0}); s < N; ++s) {

int sp = k;
for (int t = max({s, 0}); t < min({(j) + 1, N}); ++t) {

int jp = s;
int ip = t;
J[i][j][k][l][s][t] += J[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

int ip = i;
for (int j = 0; j < min({(i) + 1, N}); ++j) {

for (int l = 0; l < min({(j) + 1, N}); ++l) {

int kp = j;
int tp = l;
for (int k = 0; k < N; ++k) {

for (int s = max({k, 0}); s < N; ++s) {

int sp = k;
for (int t = max({s, 0}); t < min({(l) + 1, N}); ++t) {

int lp = s;
int jp = t;
J[i][j][k][l][s][t] += J[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int l = 0; l < min({(i) + 1, N}); ++l) {

int jp = i;
for (int j = max({i, 0}); j < N; ++j) {

int tp = l;
int kp = j;
for (int k = 0; k < N; ++k) {

for (int s = max({k, 0}); s < N; ++s) {

int sp = k;
for (int t = max({s, 0}); t < min({(l) + 1, N}); ++t) {

int lp = s;
int ip = t;
J[i][j][k][l][s][t] += J[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

int lp = i;
for (int j = max({i, 0}); j < N; ++j) {

for (int l = max({j, 0}); l < N; ++l) {

int kp = j;
int tp = l;
for (int k = 0; k < N; ++k) {

for (int s = max({k, 0}); s < N; ++s) {

int sp = k;
for (int t = max({s, 0}); t < min({(i) + 1, N}); ++t) {

int ip = s;
int jp = t;
J[i][j][k][l][s][t] += J[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

int jp = i;
for (int j = 0; j < N; ++j) {

for (int l = max({i, 0}); l < min({(j) + 1, N}); ++l) {

int kp = j;
int tp = l;
for (int k = 0; k < N; ++k) {

for (int s = max({k, 0}); s < N; ++s) {

int sp = k;
for (int t = max({s, 0}); t < min({(i) + 1, N}); ++t) {

int ip = s;
int lp = t;
J[i][j][k][l][s][t] += J[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int j = max({i, 0}); j < N; ++j) {

int tp = i;
for (int l = max({j, 0}); l < N; ++l) {

int kp = j;
for (int t = max({l, 0}); t < N; ++t) {

int ip = l;
int lp = t;
for (int k = 0; k < N; ++k) {

for (int s = max({k, 0}); s < min({(i) + 1, N}); ++s) {

int sp = k;
int jp = s;
J[i][j][k][l][s][t] += J[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

int lp = i;
for (int j = max({i, 0}); j < N; ++j) {

int kp = j;
for (int k = 0; k < N; ++k) {

for (int s = max({k, 0}); s < min({(i) + 1, N}); ++s) {

int sp = k;
int jp = s;
for (int l = 0; l < N; ++l) {

for (int t = max({j, 0}); t < min({(l) + 1, N}); ++t) {

int ip = l;
int tp = t;
J[i][j][k][l][s][t] += J[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int j = 0; j < N; ++j) {

int tp = i;
for (int t = max({j, 0}); t < N; ++t) {

for (int l = max({i, 0}); l < min({(j) + 1, N}); ++l) {

int kp = j;
int jp = t;
int ip = l;
for (int k = 0; k < N; ++k) {

for (int s = max({k, 0}); s < min({(i) + 1, N}); ++s) {

int sp = k;
int lp = s;
J[i][j][k][l][s][t] += J[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int l = max({i, 0}); l < N; ++l) {

int jp = i;
int ip = l;
for (int j = 0; j < N; ++j) {

for (int t = max({l, 0}); t < min({(j) + 1, N}); ++t) {

int kp = j;
int tp = t;
for (int k = 0; k < N; ++k) {

for (int s = max({k, 0}); s < min({(i) + 1, N}); ++s) {

int sp = k;
int lp = s;
J[i][j][k][l][s][t] += J[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

int lp = i;
for (int j = 0; j < N; ++j) {

for (int t = max({i, 0}); t < min({(j) + 1, N}); ++t) {

for (int l = max({j, 0}); l < N; ++l) {

int kp = j;
int jp = t;
int ip = l;
for (int k = 0; k < N; ++k) {

for (int s = max({k, 0}); s < min({(i) + 1, N}); ++s) {

int sp = k;
int tp = s;
J[i][j][k][l][s][t] += J[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

int jp = i;
for (int j = 0; j < N; ++j) {

for (int l = 0; l < min({(j) + 1, N}); ++l) {

int kp = j;
for (int t = max({i, 0}); t < min({(l) + 1, N}); ++t) {

int ip = l;
int lp = t;
for (int k = 0; k < N; ++k) {

for (int s = max({k, 0}); s < min({(i) + 1, N}); ++s) {

int sp = k;
int tp = s;
J[i][j][k][l][s][t] += J[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

int ip = i;
for (int j = 0; j < N; ++j) {

for (int l = max({j, 0}); l < N; ++l) {

int kp = j;
for (int s = max({l, 0}); s < min({(i) + 1, N}); ++s) {

int jp = l;
int lp = s;
for (int k = 0; k < N; ++k) {

for (int t = max({k, 0}); t < min({(j) + 1, N}); ++t) {

int tp = k;
int sp = t;
J[i][j][k][l][s][t] += J[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int s = max({i, 0}); s < N; ++s) {

int sp = i;
int lp = s;
for (int j = 0; j < N; ++j) {

for (int l = max({j, 0}); l < min({(i) + 1, N}); ++l) {

int kp = j;
int jp = l;
for (int k = 0; k < N; ++k) {

for (int t = max({k, 0}); t < min({(j) + 1, N}); ++t) {

int tp = k;
int ip = t;
J[i][j][k][l][s][t] += J[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int l = 0; l < min({(i) + 1, N}); ++l) {

int ip = i;
int jp = l;
for (int j = 0; j < N; ++j) {

for (int s = max({j, 0}); s < min({(l) + 1, N}); ++s) {

int kp = j;
int sp = s;
for (int k = 0; k < N; ++k) {

for (int t = max({k, 0}); t < min({(j) + 1, N}); ++t) {

int tp = k;
int lp = t;
J[i][j][k][l][s][t] += J[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int l = max({i, 0}); l < N; ++l) {

int lp = i;
int jp = l;
for (int j = 0; j < N; ++j) {

for (int s = max({j, 0}); s < min({(i) + 1, N}); ++s) {

int kp = j;
int sp = s;
for (int k = 0; k < N; ++k) {

for (int t = max({k, 0}); t < min({(j) + 1, N}); ++t) {

int tp = k;
int ip = t;
J[i][j][k][l][s][t] += J[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int l = max({i, 0}); l < N; ++l) {

int sp = i;
for (int j = 0; j < min({(i) + 1, N}); ++j) {

for (int s = max({l, 0}); s < N; ++s) {

int jp = l;
int kp = j;
int ip = s;
for (int k = 0; k < N; ++k) {

for (int t = max({k, 0}); t < min({(j) + 1, N}); ++t) {

int tp = k;
int lp = t;
J[i][j][k][l][s][t] += J[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

int lp = i;
for (int j = 0; j < min({(i) + 1, N}); ++j) {

int kp = j;
for (int k = 0; k < N; ++k) {

for (int t = max({k, 0}); t < min({(j) + 1, N}); ++t) {

int tp = k;
int sp = t;
for (int l = 0; l < N; ++l) {

for (int s = max({i, 0}); s < min({(l) + 1, N}); ++s) {

int jp = l;
int ip = s;
J[i][j][k][l][s][t] += J[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

int ip = i;
for (int j = 0; j < N; ++j) {

for (int s = max({j, 0}); s < min({(i) + 1, N}); ++s) {

for (int l = 0; l < min({(j) + 1, N}); ++l) {

int kp = j;
int jp = s;
int lp = l;
for (int k = 0; k < N; ++k) {

for (int t = max({k, 0}); t < min({(l) + 1, N}); ++t) {

int tp = k;
int sp = t;
J[i][j][k][l][s][t] += J[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int s = max({i, 0}); s < N; ++s) {

int sp = i;
for (int j = 0; j < min({(i) + 1, N}); ++j) {

int jp = s;
for (int l = 0; l < min({(j) + 1, N}); ++l) {

int kp = j;
int lp = l;
for (int k = 0; k < N; ++k) {

for (int t = max({k, 0}); t < min({(l) + 1, N}); ++t) {

int tp = k;
int ip = t;
J[i][j][k][l][s][t] += J[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

int ip = i;
for (int j = 0; j < min({(i) + 1, N}); ++j) {

int kp = j;
for (int k = 0; k < N; ++k) {

for (int l = 0; l < N; ++l) {

int tp = k;
for (int s = max({l, 0}); s < min({(j) + 1, N}); ++s) {

for (int t = max({k, 0}); t < min({(l) + 1, N}); ++t) {

int lp = l;
int sp = s;
int jp = t;
J[i][j][k][l][s][t] += J[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

int jp = i;
for (int j = max({i, 0}); j < N; ++j) {

int kp = j;
for (int k = 0; k < N; ++k) {

for (int l = 0; l < N; ++l) {

int tp = k;
for (int s = max({l, 0}); s < min({(i) + 1, N}); ++s) {

for (int t = max({k, 0}); t < min({(l) + 1, N}); ++t) {

int lp = l;
int sp = s;
int ip = t;
J[i][j][k][l][s][t] += J[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int l = 0; l < min({(i) + 1, N}); ++l) {

int sp = i;
for (int j = max({i, 0}); j < N; ++j) {

int lp = l;
for (int s = max({j, 0}); s < N; ++s) {

int kp = j;
int ip = s;
for (int k = 0; k < N; ++k) {

for (int t = max({k, 0}); t < min({(l) + 1, N}); ++t) {

int tp = k;
int jp = t;
J[i][j][k][l][s][t] += J[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int l = 0; l < min({(i) + 1, N}); ++l) {

int jp = i;
int lp = l;
for (int j = 0; j < N; ++j) {

for (int s = max({i, 0}); s < min({(j) + 1, N}); ++s) {

int kp = j;
int ip = s;
for (int k = 0; k < N; ++k) {

for (int t = max({k, 0}); t < min({(l) + 1, N}); ++t) {

int tp = k;
int sp = t;
J[i][j][k][l][s][t] += J[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

int ip = i;
for (int j = 0; j < N; ++j) {

for (int s = 0; s < min({(j) + 1, N}); ++s) {

for (int l = max({j, 0}); l < min({(i) + 1, N}); ++l) {

int kp = j;
int jp = s;
int sp = l;
for (int k = 0; k < N; ++k) {

for (int t = max({k, 0}); t < min({(s) + 1, N}); ++t) {

int tp = k;
int lp = t;
J[i][j][k][l][s][t] += J[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int l = max({i, 0}); l < N; ++l) {

int lp = i;
for (int j = 0; j < min({(i) + 1, N}); ++j) {

int sp = l;
for (int s = 0; s < min({(j) + 1, N}); ++s) {

int kp = j;
int jp = s;
for (int k = 0; k < N; ++k) {

for (int t = max({k, 0}); t < min({(s) + 1, N}); ++t) {

int tp = k;
int ip = t;
J[i][j][k][l][s][t] += J[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

int ip = i;
for (int j = 0; j < min({(i) + 1, N}); ++j) {

for (int l = 0; l < min({(j) + 1, N}); ++l) {

int kp = j;
for (int s = 0; s < min({(l) + 1, N}); ++s) {

int sp = l;
int lp = s;
for (int k = 0; k < N; ++k) {

for (int t = max({k, 0}); t < min({(s) + 1, N}); ++t) {

int tp = k;
int jp = t;
J[i][j][k][l][s][t] += J[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int l = 0; l < min({(i) + 1, N}); ++l) {

int jp = i;
for (int j = max({i, 0}); j < N; ++j) {

for (int s = 0; s < min({(l) + 1, N}); ++s) {

int sp = l;
int kp = j;
int lp = s;
for (int k = 0; k < N; ++k) {

for (int t = max({k, 0}); t < min({(s) + 1, N}); ++t) {

int tp = k;
int ip = t;
J[i][j][k][l][s][t] += J[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int s = 0; s < min({(i) + 1, N}); ++s) {

int lp = i;
for (int j = max({i, 0}); j < N; ++j) {

int ip = s;
for (int l = max({j, 0}); l < N; ++l) {

int kp = j;
int sp = l;
for (int k = 0; k < N; ++k) {

for (int t = max({k, 0}); t < min({(s) + 1, N}); ++t) {

int tp = k;
int jp = t;
J[i][j][k][l][s][t] += J[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int s = 0; s < min({(i) + 1, N}); ++s) {

int jp = i;
int ip = s;
for (int j = 0; j < N; ++j) {

for (int l = max({i, 0}); l < min({(j) + 1, N}); ++l) {

int kp = j;
int sp = l;
for (int k = 0; k < N; ++k) {

for (int t = max({k, 0}); t < min({(s) + 1, N}); ++t) {

int tp = k;
int lp = t;
J[i][j][k][l][s][t] += J[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

int sp = i;
for (int j = max({i, 0}); j < N; ++j) {

for (int l = max({j, 0}); l < N; ++l) {

int kp = j;
for (int s = max({l, 0}); s < N; ++s) {

int ip = l;
int jp = s;
for (int k = 0; k < N; ++k) {

for (int t = max({k, 0}); t < min({(i) + 1, N}); ++t) {

int tp = k;
int lp = t;
J[i][j][k][l][s][t] += J[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

int lp = i;
for (int j = max({i, 0}); j < N; ++j) {

int kp = j;
for (int k = 0; k < N; ++k) {

for (int t = max({k, 0}); t < min({(i) + 1, N}); ++t) {

int tp = k;
int sp = t;
for (int l = 0; l < N; ++l) {

for (int s = max({j, 0}); s < min({(l) + 1, N}); ++s) {

int ip = l;
int jp = s;
J[i][j][k][l][s][t] += J[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

int sp = i;
for (int j = 0; j < N; ++j) {

for (int s = max({j, 0}); s < N; ++s) {

for (int l = max({i, 0}); l < min({(j) + 1, N}); ++l) {

int kp = j;
int lp = s;
int ip = l;
for (int k = 0; k < N; ++k) {

for (int t = max({k, 0}); t < min({(i) + 1, N}); ++t) {

int tp = k;
int jp = t;
J[i][j][k][l][s][t] += J[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int l = max({i, 0}); l < N; ++l) {

int jp = i;
int ip = l;
for (int j = 0; j < N; ++j) {

for (int s = max({l, 0}); s < min({(j) + 1, N}); ++s) {

int kp = j;
int lp = s;
for (int k = 0; k < N; ++k) {

for (int t = max({k, 0}); t < min({(i) + 1, N}); ++t) {

int tp = k;
int sp = t;
J[i][j][k][l][s][t] += J[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

int lp = i;
for (int j = 0; j < N; ++j) {

for (int s = max({i, 0}); s < min({(j) + 1, N}); ++s) {

for (int l = max({j, 0}); l < N; ++l) {

int kp = j;
int sp = s;
int ip = l;
for (int k = 0; k < N; ++k) {

for (int t = max({k, 0}); t < min({(i) + 1, N}); ++t) {

int tp = k;
int jp = t;
J[i][j][k][l][s][t] += J[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

int jp = i;
for (int j = 0; j < N; ++j) {

for (int l = 0; l < min({(j) + 1, N}); ++l) {

int kp = j;
for (int s = max({i, 0}); s < min({(l) + 1, N}); ++s) {

int ip = l;
int sp = s;
for (int k = 0; k < N; ++k) {

for (int t = max({k, 0}); t < min({(i) + 1, N}); ++t) {

int tp = k;
int lp = t;
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

int tp = i;
for (int l = max({j, 0}); l < N; ++l) {

int kp = j;
int ip = k;
for (int s = max({l, 0}); s < N; ++s) {

int jp = l;
for (int t = max({s, 0}); t < N; ++t) {

int lp = s;
int sp = t;
J[i][j][k][l][s][t] += J[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

int sp = i;
for (int j = max({i, 0}); j < N; ++j) {

for (int k = 0; k < min({(i) + 1, N}); ++k) {

for (int l = max({j, 0}); l < N; ++l) {

int kp = j;
int ip = k;
int jp = l;
for (int s = 0; s < N; ++s) {

for (int t = max({l, 0}); t < min({(s) + 1, N}); ++t) {

int lp = s;
int tp = t;
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

int tp = i;
int kp = j;
int ip = k;
for (int l = 0; l < N; ++l) {

for (int s = max({j, 0}); s < min({(l) + 1, N}); ++s) {

for (int t = max({l, 0}); t < N; ++t) {

int jp = l;
int sp = s;
int lp = t;
J[i][j][k][l][s][t] += J[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

int lp = i;
for (int j = max({i, 0}); j < N; ++j) {

for (int k = 0; k < min({(i) + 1, N}); ++k) {

for (int s = max({j, 0}); s < N; ++s) {

int kp = j;
int ip = k;
int sp = s;
for (int l = 0; l < N; ++l) {

for (int t = max({s, 0}); t < min({(l) + 1, N}); ++t) {

int jp = l;
int tp = t;
J[i][j][k][l][s][t] += J[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

int sp = i;
for (int j = max({i, 0}); j < N; ++j) {

for (int k = 0; k < min({(i) + 1, N}); ++k) {

int kp = j;
int ip = k;
for (int l = 0; l < N; ++l) {

for (int s = max({l, 0}); s < N; ++s) {

for (int t = max({j, 0}); t < min({(l) + 1, N}); ++t) {

int jp = l;
int tp = s;
int lp = t;
J[i][j][k][l][s][t] += J[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

int lp = i;
for (int j = max({i, 0}); j < N; ++j) {

for (int k = 0; k < min({(i) + 1, N}); ++k) {

int kp = j;
int ip = k;
for (int l = 0; l < N; ++l) {

for (int s = 0; s < min({(l) + 1, N}); ++s) {

int jp = l;
for (int t = max({j, 0}); t < min({(s) + 1, N}); ++t) {

int tp = s;
int sp = t;
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

int tp = i;
for (int s = max({j, 0}); s < N; ++s) {

for (int l = max({i, 0}); l < min({(j) + 1, N}); ++l) {

int kp = j;
int ip = k;
for (int t = max({s, 0}); t < N; ++t) {

int jp = s;
int lp = l;
int sp = t;
J[i][j][k][l][s][t] += J[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

int sp = i;
for (int k = 0; k < min({(i) + 1, N}); ++k) {

int ip = k;
for (int j = 0; j < N; ++j) {

for (int l = max({i, 0}); l < min({(j) + 1, N}); ++l) {

int kp = j;
int lp = l;
for (int s = 0; s < N; ++s) {

for (int t = max({j, 0}); t < min({(s) + 1, N}); ++t) {

int jp = s;
int tp = t;
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

int tp = i;
int lp = l;
int ip = k;
for (int j = 0; j < N; ++j) {

for (int s = max({l, 0}); s < min({(j) + 1, N}); ++s) {

for (int t = max({j, 0}); t < N; ++t) {

int kp = j;
int sp = s;
int jp = t;
J[i][j][k][l][s][t] += J[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int l = max({i, 0}); l < N; ++l) {

int jp = i;
for (int k = 0; k < min({(i) + 1, N}); ++k) {

for (int s = max({l, 0}); s < N; ++s) {

int lp = l;
int ip = k;
int sp = s;
for (int j = 0; j < N; ++j) {

for (int t = max({s, 0}); t < min({(j) + 1, N}); ++t) {

int kp = j;
int tp = t;
J[i][j][k][l][s][t] += J[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int l = max({i, 0}); l < N; ++l) {

int sp = i;
for (int k = 0; k < min({(i) + 1, N}); ++k) {

int lp = l;
int ip = k;
for (int j = 0; j < N; ++j) {

for (int s = max({j, 0}); s < N; ++s) {

for (int t = max({l, 0}); t < min({(j) + 1, N}); ++t) {

int kp = j;
int tp = s;
int jp = t;
J[i][j][k][l][s][t] += J[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int l = max({i, 0}); l < N; ++l) {

int jp = i;
for (int k = 0; k < min({(i) + 1, N}); ++k) {

int lp = l;
int ip = k;
for (int j = 0; j < N; ++j) {

for (int s = 0; s < min({(j) + 1, N}); ++s) {

int kp = j;
for (int t = max({l, 0}); t < min({(s) + 1, N}); ++t) {

int tp = s;
int sp = t;
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

int tp = i;
for (int s = max({i, 0}); s < min({(j) + 1, N}); ++s) {

for (int l = max({j, 0}); l < N; ++l) {

int kp = j;
int ip = k;
int jp = s;
for (int t = max({l, 0}); t < N; ++t) {

int sp = l;
int lp = t;
J[i][j][k][l][s][t] += J[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

int lp = i;
for (int k = 0; k < min({(i) + 1, N}); ++k) {

int ip = k;
for (int j = 0; j < N; ++j) {

for (int s = max({i, 0}); s < min({(j) + 1, N}); ++s) {

int kp = j;
int jp = s;
for (int l = 0; l < N; ++l) {

for (int t = max({j, 0}); t < min({(l) + 1, N}); ++t) {

int sp = l;
int tp = t;
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

int tp = i;
for (int t = max({j, 0}); t < N; ++t) {

for (int l = 0; l < min({(j) + 1, N}); ++l) {

int kp = j;
int ip = k;
int jp = t;
for (int s = max({i, 0}); s < min({(l) + 1, N}); ++s) {

int sp = l;
int lp = s;
J[i][j][k][l][s][t] += J[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

int jp = i;
for (int k = 0; k < min({(i) + 1, N}); ++k) {

int ip = k;
for (int j = 0; j < N; ++j) {

int kp = j;
for (int l = 0; l < N; ++l) {

for (int s = max({i, 0}); s < min({(l) + 1, N}); ++s) {

for (int t = max({l, 0}); t < min({(j) + 1, N}); ++t) {

int sp = l;
int lp = s;
int tp = t;
J[i][j][k][l][s][t] += J[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int s = max({i, 0}); s < N; ++s) {

int lp = i;
for (int k = 0; k < min({(i) + 1, N}); ++k) {

int tp = s;
int ip = k;
for (int j = 0; j < N; ++j) {

for (int t = max({s, 0}); t < min({(j) + 1, N}); ++t) {

for (int l = max({j, 0}); l < N; ++l) {

int kp = j;
int jp = t;
int sp = l;
J[i][j][k][l][s][t] += J[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int s = max({i, 0}); s < N; ++s) {

int jp = i;
for (int k = 0; k < min({(i) + 1, N}); ++k) {

int tp = s;
int ip = k;
for (int j = 0; j < N; ++j) {

for (int l = 0; l < min({(j) + 1, N}); ++l) {

int kp = j;
for (int t = max({s, 0}); t < min({(l) + 1, N}); ++t) {

int sp = l;
int lp = t;
J[i][j][k][l][s][t] += J[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

int sp = i;
for (int k = 0; k < min({(i) + 1, N}); ++k) {

int ip = k;
for (int j = 0; j < N; ++j) {

for (int t = max({i, 0}); t < min({(j) + 1, N}); ++t) {

for (int l = max({j, 0}); l < N; ++l) {

int kp = j;
int lp = t;
for (int s = max({l, 0}); s < N; ++s) {

int tp = l;
int jp = s;
J[i][j][k][l][s][t] += J[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

int lp = i;
for (int k = 0; k < min({(i) + 1, N}); ++k) {

int ip = k;
for (int j = 0; j < N; ++j) {

for (int t = max({i, 0}); t < min({(j) + 1, N}); ++t) {

int kp = j;
int sp = t;
for (int l = 0; l < N; ++l) {

for (int s = max({j, 0}); s < min({(l) + 1, N}); ++s) {

int tp = l;
int jp = s;
J[i][j][k][l][s][t] += J[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

int sp = i;
for (int k = 0; k < min({(i) + 1, N}); ++k) {

int ip = k;
for (int j = 0; j < N; ++j) {

for (int s = max({j, 0}); s < N; ++s) {

for (int l = 0; l < min({(j) + 1, N}); ++l) {

int kp = j;
int lp = s;
for (int t = max({i, 0}); t < min({(l) + 1, N}); ++t) {

int tp = l;
int jp = t;
J[i][j][k][l][s][t] += J[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

int jp = i;
for (int k = 0; k < min({(i) + 1, N}); ++k) {

int ip = k;
for (int j = 0; j < N; ++j) {

int kp = j;
for (int l = 0; l < N; ++l) {

for (int s = max({l, 0}); s < min({(j) + 1, N}); ++s) {

for (int t = max({i, 0}); t < min({(l) + 1, N}); ++t) {

int tp = l;
int lp = s;
int sp = t;
J[i][j][k][l][s][t] += J[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

int lp = i;
for (int k = 0; k < min({(i) + 1, N}); ++k) {

int ip = k;
for (int j = 0; j < N; ++j) {

for (int s = 0; s < min({(j) + 1, N}); ++s) {

for (int l = max({j, 0}); l < N; ++l) {

int kp = j;
for (int t = max({i, 0}); t < min({(s) + 1, N}); ++t) {

int sp = s;
int tp = l;
int jp = t;
J[i][j][k][l][s][t] += J[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

int jp = i;
for (int k = 0; k < min({(i) + 1, N}); ++k) {

int ip = k;
for (int j = 0; j < N; ++j) {

for (int l = 0; l < min({(j) + 1, N}); ++l) {

int kp = j;
for (int s = 0; s < min({(l) + 1, N}); ++s) {

int tp = l;
for (int t = max({i, 0}); t < min({(s) + 1, N}); ++t) {

int sp = s;
int lp = t;
J[i][j][k][l][s][t] += J[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

int ip = i;
for (int j = 0; j < N; ++j) {

for (int l = 0; l < min({(j) + 1, N}); ++l) {

int lp = j;
for (int k = max({j, 0}); k < N; ++k) {

int kp = l;
for (int s = max({k, 0}); s < N; ++s) {

int jp = k;
for (int t = max({s, 0}); t < min({(i) + 1, N}); ++t) {

int sp = s;
int tp = t;
J[i][j][k][l][s][t] += J[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int t = max({i, 0}); t < N; ++t) {

int tp = i;
int ip = t;
for (int j = 0; j < N; ++j) {

for (int l = 0; l < min({(j) + 1, N}); ++l) {

int lp = j;
for (int k = max({j, 0}); k < N; ++k) {

int kp = l;
for (int s = max({k, 0}); s < min({(i) + 1, N}); ++s) {

int jp = k;
int sp = s;
J[i][j][k][l][s][t] += J[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int s = 0; s < min({(i) + 1, N}); ++s) {

int ip = i;
int tp = s;
for (int j = 0; j < N; ++j) {

for (int l = 0; l < min({(j) + 1, N}); ++l) {

int lp = j;
for (int k = max({j, 0}); k < N; ++k) {

int kp = l;
for (int t = max({k, 0}); t < min({(s) + 1, N}); ++t) {

int jp = k;
int sp = t;
J[i][j][k][l][s][t] += J[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int s = max({i, 0}); s < N; ++s) {

int sp = i;
int tp = s;
for (int j = 0; j < N; ++j) {

for (int l = 0; l < min({(j) + 1, N}); ++l) {

int lp = j;
for (int k = max({j, 0}); k < N; ++k) {

int kp = l;
for (int t = max({k, 0}); t < min({(i) + 1, N}); ++t) {

int jp = k;
int ip = t;
J[i][j][k][l][s][t] += J[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int s = max({i, 0}); s < N; ++s) {

int tp = i;
for (int t = max({s, 0}); t < N; ++t) {

int ip = s;
int sp = t;
for (int j = 0; j < N; ++j) {

for (int l = 0; l < min({(j) + 1, N}); ++l) {

int lp = j;
for (int k = max({j, 0}); k < min({(i) + 1, N}); ++k) {

int kp = l;
int jp = k;
J[i][j][k][l][s][t] += J[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

int sp = i;
for (int j = 0; j < N; ++j) {

for (int l = 0; l < min({(j) + 1, N}); ++l) {

int lp = j;
for (int k = max({j, 0}); k < min({(i) + 1, N}); ++k) {

int kp = l;
int jp = k;
for (int s = 0; s < N; ++s) {

for (int t = max({i, 0}); t < min({(s) + 1, N}); ++t) {

int ip = s;
int tp = t;
J[i][j][k][l][s][t] += J[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

int ip = i;
for (int j = 0; j < N; ++j) {

for (int l = 0; l < min({(j) + 1, N}); ++l) {

int lp = j;
int sp = l;
for (int k = 0; k < N; ++k) {

for (int s = max({j, 0}); s < min({(k) + 1, N}); ++s) {

for (int t = max({k, 0}); t < min({(i) + 1, N}); ++t) {

int jp = k;
int kp = s;
int tp = t;
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

int tp = i;
int ip = t;
int jp = k;
for (int j = 0; j < N; ++j) {

for (int s = max({j, 0}); s < min({(k) + 1, N}); ++s) {

for (int l = 0; l < min({(j) + 1, N}); ++l) {

int lp = j;
int kp = s;
int sp = l;
J[i][j][k][l][s][t] += J[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

int ip = i;
for (int k = 0; k < min({(i) + 1, N}); ++k) {

int jp = k;
for (int j = 0; j < N; ++j) {

for (int s = max({j, 0}); s < N; ++s) {

for (int l = 0; l < min({(j) + 1, N}); ++l) {

int lp = j;
for (int t = max({s, 0}); t < min({(k) + 1, N}); ++t) {

int tp = s;
int sp = l;
int kp = t;
J[i][j][k][l][s][t] += J[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

int kp = i;
for (int k = max({i, 0}); k < N; ++k) {

int jp = k;
for (int j = 0; j < N; ++j) {

for (int s = max({j, 0}); s < N; ++s) {

for (int l = 0; l < min({(j) + 1, N}); ++l) {

int lp = j;
for (int t = max({s, 0}); t < min({(i) + 1, N}); ++t) {

int tp = s;
int sp = l;
int ip = t;
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

int tp = i;
for (int s = max({j, 0}); s < min({(i) + 1, N}); ++s) {

for (int l = 0; l < min({(j) + 1, N}); ++l) {

int lp = j;
for (int t = max({k, 0}); t < N; ++t) {

int jp = k;
int ip = s;
int sp = l;
int kp = t;
J[i][j][k][l][s][t] += J[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

int kp = i;
for (int j = 0; j < N; ++j) {

for (int s = max({j, 0}); s < min({(i) + 1, N}); ++s) {

for (int l = 0; l < min({(j) + 1, N}); ++l) {

int lp = j;
int ip = s;
int sp = l;
for (int k = 0; k < N; ++k) {

for (int t = max({i, 0}); t < min({(k) + 1, N}); ++t) {

int jp = k;
int tp = t;
J[i][j][k][l][s][t] += J[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

int ip = i;
for (int j = 0; j < N; ++j) {

for (int l = 0; l < min({(j) + 1, N}); ++l) {

int lp = j;
int tp = l;
for (int k = 0; k < N; ++k) {

for (int s = max({k, 0}); s < min({(i) + 1, N}); ++s) {

for (int t = max({j, 0}); t < min({(k) + 1, N}); ++t) {

int jp = k;
int kp = s;
int sp = t;
J[i][j][k][l][s][t] += J[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int s = max({i, 0}); s < N; ++s) {

int sp = i;
for (int k = 0; k < min({(i) + 1, N}); ++k) {

int kp = s;
int jp = k;
for (int j = 0; j < N; ++j) {

for (int t = max({j, 0}); t < min({(k) + 1, N}); ++t) {

for (int l = 0; l < min({(j) + 1, N}); ++l) {

int lp = j;
int ip = t;
int tp = l;
J[i][j][k][l][s][t] += J[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

int ip = i;
for (int k = 0; k < min({(i) + 1, N}); ++k) {

for (int s = 0; s < min({(k) + 1, N}); ++s) {

int jp = k;
int sp = s;
for (int j = 0; j < N; ++j) {

for (int t = max({j, 0}); t < min({(s) + 1, N}); ++t) {

for (int l = 0; l < min({(j) + 1, N}); ++l) {

int lp = j;
int kp = t;
int tp = l;
J[i][j][k][l][s][t] += J[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int s = 0; s < min({(i) + 1, N}); ++s) {

int kp = i;
for (int k = max({i, 0}); k < N; ++k) {

int sp = s;
int jp = k;
for (int j = 0; j < N; ++j) {

for (int t = max({j, 0}); t < min({(s) + 1, N}); ++t) {

for (int l = 0; l < min({(j) + 1, N}); ++l) {

int lp = j;
int ip = t;
int tp = l;
J[i][j][k][l][s][t] += J[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

int sp = i;
for (int k = max({i, 0}); k < N; ++k) {

for (int s = max({k, 0}); s < N; ++s) {

int jp = k;
int ip = s;
for (int j = 0; j < N; ++j) {

for (int t = max({j, 0}); t < min({(i) + 1, N}); ++t) {

for (int l = 0; l < min({(j) + 1, N}); ++l) {

int lp = j;
int kp = t;
int tp = l;
J[i][j][k][l][s][t] += J[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

int kp = i;
for (int j = 0; j < N; ++j) {

for (int t = max({j, 0}); t < min({(i) + 1, N}); ++t) {

for (int l = 0; l < min({(j) + 1, N}); ++l) {

int lp = j;
int sp = t;
int tp = l;
for (int k = 0; k < N; ++k) {

for (int s = max({i, 0}); s < min({(k) + 1, N}); ++s) {

int jp = k;
int ip = s;
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

int tp = i;
for (int l = 0; l < min({(j) + 1, N}); ++l) {

int lp = j;
for (int s = max({k, 0}); s < N; ++s) {

int jp = k;
int ip = l;
for (int t = max({s, 0}); t < N; ++t) {

int kp = s;
int sp = t;
J[i][j][k][l][s][t] += J[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

int sp = i;
for (int j = 0; j < min({(i) + 1, N}); ++j) {

for (int k = max({i, 0}); k < N; ++k) {

for (int l = 0; l < min({(j) + 1, N}); ++l) {

int lp = j;
int jp = k;
int ip = l;
for (int s = 0; s < N; ++s) {

for (int t = max({k, 0}); t < min({(s) + 1, N}); ++t) {

int kp = s;
int tp = t;
J[i][j][k][l][s][t] += J[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int j = 0; j < min({(i) + 1, N}); ++j) {

int tp = i;
for (int l = 0; l < min({(j) + 1, N}); ++l) {

int lp = j;
int ip = l;
for (int k = 0; k < N; ++k) {

for (int s = max({i, 0}); s < min({(k) + 1, N}); ++s) {

for (int t = max({k, 0}); t < N; ++t) {

int jp = k;
int sp = s;
int kp = t;
J[i][j][k][l][s][t] += J[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int s = max({i, 0}); s < N; ++s) {

int kp = i;
for (int j = 0; j < min({(i) + 1, N}); ++j) {

int sp = s;
for (int l = 0; l < min({(j) + 1, N}); ++l) {

int lp = j;
int ip = l;
for (int k = 0; k < N; ++k) {

for (int t = max({s, 0}); t < min({(k) + 1, N}); ++t) {

int jp = k;
int tp = t;
J[i][j][k][l][s][t] += J[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

int sp = i;
for (int j = 0; j < min({(i) + 1, N}); ++j) {

for (int l = 0; l < min({(j) + 1, N}); ++l) {

int lp = j;
int ip = l;
for (int k = 0; k < N; ++k) {

for (int s = max({k, 0}); s < N; ++s) {

for (int t = max({i, 0}); t < min({(k) + 1, N}); ++t) {

int jp = k;
int tp = s;
int kp = t;
J[i][j][k][l][s][t] += J[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

int kp = i;
for (int j = 0; j < min({(i) + 1, N}); ++j) {

for (int l = 0; l < min({(j) + 1, N}); ++l) {

int lp = j;
int ip = l;
for (int k = 0; k < N; ++k) {

for (int s = 0; s < min({(k) + 1, N}); ++s) {

int jp = k;
for (int t = max({i, 0}); t < min({(s) + 1, N}); ++t) {

int tp = s;
int sp = t;
J[i][j][k][l][s][t] += J[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

int ip = i;
for (int j = 0; j < N; ++j) {

for (int s = max({j, 0}); s < N; ++s) {

int lp = j;
for (int k = 0; k < min({(j) + 1, N}); ++k) {

for (int t = max({s, 0}); t < min({(i) + 1, N}); ++t) {

int sp = s;
for (int l = 0; l < min({(k) + 1, N}); ++l) {

int kp = k;
int tp = t;
int jp = l;
J[i][j][k][l][s][t] += J[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int t = max({i, 0}); t < N; ++t) {

int tp = i;
int ip = t;
for (int j = 0; j < N; ++j) {

for (int s = max({j, 0}); s < min({(i) + 1, N}); ++s) {

int lp = j;
for (int k = 0; k < min({(j) + 1, N}); ++k) {

int sp = s;
for (int l = 0; l < min({(k) + 1, N}); ++l) {

int kp = k;
int jp = l;
J[i][j][k][l][s][t] += J[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int s = 0; s < min({(i) + 1, N}); ++s) {

int ip = i;
int tp = s;
for (int j = 0; j < N; ++j) {

for (int t = max({j, 0}); t < min({(s) + 1, N}); ++t) {

int lp = j;
for (int k = 0; k < min({(j) + 1, N}); ++k) {

int sp = t;
for (int l = 0; l < min({(k) + 1, N}); ++l) {

int kp = k;
int jp = l;
J[i][j][k][l][s][t] += J[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int s = max({i, 0}); s < N; ++s) {

int sp = i;
int tp = s;
for (int j = 0; j < N; ++j) {

for (int t = max({j, 0}); t < min({(i) + 1, N}); ++t) {

int lp = j;
for (int k = 0; k < min({(j) + 1, N}); ++k) {

int ip = t;
for (int l = 0; l < min({(k) + 1, N}); ++l) {

int kp = k;
int jp = l;
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

int tp = i;
for (int t = max({s, 0}); t < N; ++t) {

int ip = s;
int lp = j;
for (int k = 0; k < min({(j) + 1, N}); ++k) {

int sp = t;
for (int l = 0; l < min({(k) + 1, N}); ++l) {

int kp = k;
int jp = l;
J[i][j][k][l][s][t] += J[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

int sp = i;
for (int j = 0; j < min({(i) + 1, N}); ++j) {

int lp = j;
for (int k = 0; k < min({(j) + 1, N}); ++k) {

for (int l = 0; l < min({(k) + 1, N}); ++l) {

int kp = k;
int jp = l;
for (int s = 0; s < N; ++s) {

for (int t = max({i, 0}); t < min({(s) + 1, N}); ++t) {

int ip = s;
int tp = t;
J[i][j][k][l][s][t] += J[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

int ip = i;
for (int j = 0; j < N; ++j) {

for (int t = max({j, 0}); t < min({(i) + 1, N}); ++t) {

int lp = j;
int tp = t;
for (int k = 0; k < N; ++k) {

for (int s = max({k, 0}); s < min({(j) + 1, N}); ++s) {

for (int l = 0; l < min({(k) + 1, N}); ++l) {

int kp = k;
int jp = s;
int sp = l;
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

int tp = i;
int ip = t;
int lp = j;
for (int k = 0; k < N; ++k) {

for (int s = max({k, 0}); s < min({(j) + 1, N}); ++s) {

for (int l = 0; l < min({(k) + 1, N}); ++l) {

int kp = k;
int jp = s;
int sp = l;
J[i][j][k][l][s][t] += J[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

int ip = i;
for (int j = 0; j < min({(i) + 1, N}); ++j) {

int lp = j;
for (int k = 0; k < N; ++k) {

for (int s = max({k, 0}); s < N; ++s) {

for (int l = 0; l < min({(k) + 1, N}); ++l) {

int kp = k;
for (int t = max({s, 0}); t < min({(j) + 1, N}); ++t) {

int tp = s;
int sp = l;
int jp = t;
J[i][j][k][l][s][t] += J[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

int jp = i;
for (int j = max({i, 0}); j < N; ++j) {

int lp = j;
for (int k = 0; k < N; ++k) {

for (int s = max({k, 0}); s < N; ++s) {

for (int l = 0; l < min({(k) + 1, N}); ++l) {

int kp = k;
for (int t = max({s, 0}); t < min({(i) + 1, N}); ++t) {

int tp = s;
int sp = l;
int ip = t;
J[i][j][k][l][s][t] += J[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int j = max({i, 0}); j < N; ++j) {

int tp = i;
for (int t = max({j, 0}); t < N; ++t) {

int lp = j;
int jp = t;
for (int k = 0; k < N; ++k) {

for (int s = max({k, 0}); s < min({(i) + 1, N}); ++s) {

for (int l = 0; l < min({(k) + 1, N}); ++l) {

int kp = k;
int ip = s;
int sp = l;
J[i][j][k][l][s][t] += J[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

int jp = i;
for (int j = 0; j < N; ++j) {

for (int t = max({i, 0}); t < min({(j) + 1, N}); ++t) {

int lp = j;
int tp = t;
for (int k = 0; k < N; ++k) {

for (int s = max({k, 0}); s < min({(i) + 1, N}); ++s) {

for (int l = 0; l < min({(k) + 1, N}); ++l) {

int kp = k;
int ip = s;
int sp = l;
J[i][j][k][l][s][t] += J[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

int ip = i;
for (int j = 0; j < N; ++j) {

for (int s = max({j, 0}); s < min({(i) + 1, N}); ++s) {

int lp = j;
int jp = s;
for (int k = 0; k < N; ++k) {

for (int t = max({k, 0}); t < min({(j) + 1, N}); ++t) {

for (int l = 0; l < min({(k) + 1, N}); ++l) {

int kp = k;
int sp = t;
int tp = l;
J[i][j][k][l][s][t] += J[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int s = max({i, 0}); s < N; ++s) {

int sp = i;
for (int j = 0; j < min({(i) + 1, N}); ++j) {

int jp = s;
int lp = j;
for (int k = 0; k < N; ++k) {

for (int t = max({k, 0}); t < min({(j) + 1, N}); ++t) {

for (int l = 0; l < min({(k) + 1, N}); ++l) {

int kp = k;
int ip = t;
int tp = l;
J[i][j][k][l][s][t] += J[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

int ip = i;
for (int j = 0; j < min({(i) + 1, N}); ++j) {

for (int s = 0; s < min({(j) + 1, N}); ++s) {

int lp = j;
int sp = s;
for (int k = 0; k < N; ++k) {

for (int t = max({k, 0}); t < min({(s) + 1, N}); ++t) {

for (int l = 0; l < min({(k) + 1, N}); ++l) {

int kp = k;
int jp = t;
int tp = l;
J[i][j][k][l][s][t] += J[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int s = 0; s < min({(i) + 1, N}); ++s) {

int jp = i;
for (int j = max({i, 0}); j < N; ++j) {

int sp = s;
int lp = j;
for (int k = 0; k < N; ++k) {

for (int t = max({k, 0}); t < min({(s) + 1, N}); ++t) {

for (int l = 0; l < min({(k) + 1, N}); ++l) {

int kp = k;
int ip = t;
int tp = l;
J[i][j][k][l][s][t] += J[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

int sp = i;
for (int j = max({i, 0}); j < N; ++j) {

for (int s = max({j, 0}); s < N; ++s) {

int lp = j;
int ip = s;
for (int k = 0; k < N; ++k) {

for (int t = max({k, 0}); t < min({(i) + 1, N}); ++t) {

for (int l = 0; l < min({(k) + 1, N}); ++l) {

int kp = k;
int jp = t;
int tp = l;
J[i][j][k][l][s][t] += J[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

int jp = i;
for (int j = 0; j < N; ++j) {

for (int s = max({i, 0}); s < min({(j) + 1, N}); ++s) {

int lp = j;
int ip = s;
for (int k = 0; k < N; ++k) {

for (int t = max({k, 0}); t < min({(i) + 1, N}); ++t) {

for (int l = 0; l < min({(k) + 1, N}); ++l) {

int kp = k;
int sp = t;
int tp = l;
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

int tp = i;
for (int s = max({j, 0}); s < N; ++s) {

int lp = j;
for (int l = 0; l < min({(k) + 1, N}); ++l) {

int kp = k;
for (int t = max({s, 0}); t < N; ++t) {

int jp = s;
int ip = l;
int sp = t;
J[i][j][k][l][s][t] += J[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

int sp = i;
for (int j = max({i, 0}); j < N; ++j) {

for (int k = 0; k < min({(i) + 1, N}); ++k) {

int lp = j;
for (int l = 0; l < min({(k) + 1, N}); ++l) {

int kp = k;
int ip = l;
for (int s = 0; s < N; ++s) {

for (int t = max({j, 0}); t < min({(s) + 1, N}); ++t) {

int jp = s;
int tp = t;
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

int tp = i;
for (int s = max({i, 0}); s < min({(j) + 1, N}); ++s) {

for (int t = max({j, 0}); t < N; ++t) {

int lp = j;
for (int l = 0; l < min({(k) + 1, N}); ++l) {

int kp = k;
int sp = s;
int jp = t;
int ip = l;
J[i][j][k][l][s][t] += J[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int s = max({i, 0}); s < N; ++s) {

int jp = i;
for (int k = 0; k < min({(i) + 1, N}); ++k) {

int sp = s;
for (int l = 0; l < min({(k) + 1, N}); ++l) {

int kp = k;
int ip = l;
for (int j = 0; j < N; ++j) {

for (int t = max({s, 0}); t < min({(j) + 1, N}); ++t) {

int lp = j;
int tp = t;
J[i][j][k][l][s][t] += J[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

int sp = i;
for (int k = 0; k < min({(i) + 1, N}); ++k) {

for (int l = 0; l < min({(k) + 1, N}); ++l) {

int kp = k;
int ip = l;
for (int j = 0; j < N; ++j) {

for (int s = max({j, 0}); s < N; ++s) {

for (int t = max({i, 0}); t < min({(j) + 1, N}); ++t) {

int lp = j;
int tp = s;
int jp = t;
J[i][j][k][l][s][t] += J[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

int jp = i;
for (int k = 0; k < min({(i) + 1, N}); ++k) {

for (int l = 0; l < min({(k) + 1, N}); ++l) {

int kp = k;
int ip = l;
for (int j = 0; j < N; ++j) {

for (int s = 0; s < min({(j) + 1, N}); ++s) {

int lp = j;
for (int t = max({i, 0}); t < min({(s) + 1, N}); ++t) {

int tp = s;
int sp = t;
J[i][j][k][l][s][t] += J[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

int ip = i;
for (int j = 0; j < N; ++j) {

int lp = j;
for (int k = max({j, 0}); k < N; ++k) {

for (int t = max({k, 0}); t < min({(i) + 1, N}); ++t) {

int sp = k;
int tp = t;
for (int l = 0; l < N; ++l) {

for (int s = max({l, 0}); s < min({(j) + 1, N}); ++s) {

int jp = l;
int kp = s;
J[i][j][k][l][s][t] += J[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int t = max({i, 0}); t < N; ++t) {

int tp = i;
int ip = t;
for (int j = 0; j < N; ++j) {

int lp = j;
for (int k = max({j, 0}); k < min({(i) + 1, N}); ++k) {

for (int l = 0; l < N; ++l) {

int sp = k;
for (int s = max({l, 0}); s < min({(j) + 1, N}); ++s) {

int jp = l;
int kp = s;
J[i][j][k][l][s][t] += J[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

int ip = i;
for (int k = 0; k < min({(i) + 1, N}); ++k) {

int sp = k;
for (int j = 0; j < N; ++j) {

for (int t = max({j, 0}); t < min({(k) + 1, N}); ++t) {

int lp = j;
int kp = t;
for (int l = 0; l < N; ++l) {

for (int s = max({l, 0}); s < min({(j) + 1, N}); ++s) {

int jp = l;
int tp = s;
J[i][j][k][l][s][t] += J[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

int kp = i;
for (int k = max({i, 0}); k < N; ++k) {

int sp = k;
for (int j = 0; j < N; ++j) {

for (int t = max({j, 0}); t < min({(i) + 1, N}); ++t) {

int lp = j;
int ip = t;
for (int l = 0; l < N; ++l) {

for (int s = max({l, 0}); s < min({(j) + 1, N}); ++s) {

int jp = l;
int tp = s;
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

int tp = i;
int lp = j;
for (int t = max({k, 0}); t < N; ++t) {

int sp = k;
int kp = t;
for (int l = 0; l < N; ++l) {

for (int s = max({l, 0}); s < min({(j) + 1, N}); ++s) {

int jp = l;
int ip = s;
J[i][j][k][l][s][t] += J[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

int kp = i;
for (int j = 0; j < min({(i) + 1, N}); ++j) {

int lp = j;
for (int k = 0; k < N; ++k) {

for (int t = max({i, 0}); t < min({(k) + 1, N}); ++t) {

int sp = k;
int tp = t;
for (int l = 0; l < N; ++l) {

for (int s = max({l, 0}); s < min({(j) + 1, N}); ++s) {

int jp = l;
int ip = s;
J[i][j][k][l][s][t] += J[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

int ip = i;
for (int j = 0; j < N; ++j) {

for (int t = max({j, 0}); t < min({(i) + 1, N}); ++t) {

int lp = j;
for (int k = 0; k < min({(j) + 1, N}); ++k) {

int tp = t;
int sp = k;
for (int l = 0; l < N; ++l) {

for (int s = max({l, 0}); s < min({(k) + 1, N}); ++s) {

int kp = l;
int jp = s;
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

int tp = i;
int ip = t;
int lp = j;
for (int k = 0; k < min({(j) + 1, N}); ++k) {

for (int l = 0; l < N; ++l) {

int sp = k;
for (int s = max({l, 0}); s < min({(k) + 1, N}); ++s) {

int kp = l;
int jp = s;
J[i][j][k][l][s][t] += J[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

int ip = i;
for (int j = 0; j < min({(i) + 1, N}); ++j) {

int lp = j;
for (int k = 0; k < N; ++k) {

for (int t = max({k, 0}); t < min({(j) + 1, N}); ++t) {

int sp = k;
int jp = t;
for (int l = 0; l < N; ++l) {

for (int s = max({l, 0}); s < min({(k) + 1, N}); ++s) {

int kp = l;
int tp = s;
J[i][j][k][l][s][t] += J[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

int jp = i;
for (int j = max({i, 0}); j < N; ++j) {

int lp = j;
for (int k = 0; k < N; ++k) {

for (int t = max({k, 0}); t < min({(i) + 1, N}); ++t) {

int sp = k;
int ip = t;
for (int l = 0; l < N; ++l) {

for (int s = max({l, 0}); s < min({(k) + 1, N}); ++s) {

int kp = l;
int tp = s;
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

int tp = i;
for (int t = max({j, 0}); t < N; ++t) {

int lp = j;
int sp = k;
int jp = t;
for (int l = 0; l < N; ++l) {

for (int s = max({l, 0}); s < min({(k) + 1, N}); ++s) {

int kp = l;
int ip = s;
J[i][j][k][l][s][t] += J[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

int jp = i;
for (int k = 0; k < min({(i) + 1, N}); ++k) {

int sp = k;
for (int j = 0; j < N; ++j) {

for (int t = max({i, 0}); t < min({(j) + 1, N}); ++t) {

int lp = j;
int tp = t;
for (int l = 0; l < N; ++l) {

for (int s = max({l, 0}); s < min({(k) + 1, N}); ++s) {

int kp = l;
int ip = s;
J[i][j][k][l][s][t] += J[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

int ip = i;
for (int j = 0; j < N; ++j) {

int lp = j;
for (int k = max({j, 0}); k < min({(i) + 1, N}); ++k) {

for (int l = 0; l < N; ++l) {

int sp = k;
for (int s = max({l, 0}); s < N; ++s) {

int tp = l;
for (int t = max({s, 0}); t < min({(j) + 1, N}); ++t) {

int jp = s;
int kp = t;
J[i][j][k][l][s][t] += J[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

int kp = i;
for (int j = 0; j < min({(i) + 1, N}); ++j) {

for (int k = max({i, 0}); k < N; ++k) {

int lp = j;
int sp = k;
for (int l = 0; l < N; ++l) {

for (int s = max({l, 0}); s < N; ++s) {

int tp = l;
for (int t = max({s, 0}); t < min({(j) + 1, N}); ++t) {

int jp = s;
int ip = t;
J[i][j][k][l][s][t] += J[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

int ip = i;
for (int j = 0; j < min({(i) + 1, N}); ++j) {

int lp = j;
for (int k = 0; k < min({(j) + 1, N}); ++k) {

for (int l = 0; l < N; ++l) {

int sp = k;
for (int s = max({l, 0}); s < N; ++s) {

int tp = l;
for (int t = max({s, 0}); t < min({(k) + 1, N}); ++t) {

int kp = s;
int jp = t;
J[i][j][k][l][s][t] += J[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

int jp = i;
for (int j = max({i, 0}); j < N; ++j) {

for (int k = 0; k < min({(i) + 1, N}); ++k) {

int lp = j;
int sp = k;
for (int l = 0; l < N; ++l) {

for (int s = max({l, 0}); s < N; ++s) {

int tp = l;
for (int t = max({s, 0}); t < min({(k) + 1, N}); ++t) {

int kp = s;
int ip = t;
J[i][j][k][l][s][t] += J[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

int kp = i;
for (int j = max({i, 0}); j < N; ++j) {

int lp = j;
for (int k = max({j, 0}); k < N; ++k) {

for (int l = 0; l < N; ++l) {

int sp = k;
for (int s = max({l, 0}); s < N; ++s) {

int tp = l;
for (int t = max({s, 0}); t < min({(i) + 1, N}); ++t) {

int ip = s;
int jp = t;
J[i][j][k][l][s][t] += J[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

int jp = i;
for (int j = 0; j < N; ++j) {

int lp = j;
for (int k = max({i, 0}); k < min({(j) + 1, N}); ++k) {

for (int l = 0; l < N; ++l) {

int sp = k;
for (int s = max({l, 0}); s < N; ++s) {

int tp = l;
for (int t = max({s, 0}); t < min({(i) + 1, N}); ++t) {

int ip = s;
int kp = t;
J[i][j][k][l][s][t] += J[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int j = max({i, 0}); j < N; ++j) {

int tp = i;
int lp = j;
for (int k = max({j, 0}); k < N; ++k) {

for (int t = max({k, 0}); t < N; ++t) {

int sp = k;
int kp = t;
for (int l = 0; l < N; ++l) {

for (int s = max({l, 0}); s < min({(i) + 1, N}); ++s) {

int ip = l;
int jp = s;
J[i][j][k][l][s][t] += J[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

int kp = i;
for (int j = max({i, 0}); j < N; ++j) {

int lp = j;
for (int k = 0; k < N; ++k) {

for (int t = max({j, 0}); t < min({(k) + 1, N}); ++t) {

int sp = k;
int tp = t;
for (int l = 0; l < N; ++l) {

for (int s = max({l, 0}); s < min({(i) + 1, N}); ++s) {

int ip = l;
int jp = s;
J[i][j][k][l][s][t] += J[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int j = 0; j < N; ++j) {

int tp = i;
for (int t = max({j, 0}); t < N; ++t) {

int lp = j;
for (int k = max({i, 0}); k < min({(j) + 1, N}); ++k) {

int jp = t;
int sp = k;
for (int l = 0; l < N; ++l) {

for (int s = max({l, 0}); s < min({(i) + 1, N}); ++s) {

int ip = l;
int kp = s;
J[i][j][k][l][s][t] += J[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

int jp = i;
for (int k = max({i, 0}); k < N; ++k) {

int sp = k;
for (int j = 0; j < N; ++j) {

for (int t = max({k, 0}); t < min({(j) + 1, N}); ++t) {

int lp = j;
int tp = t;
for (int l = 0; l < N; ++l) {

for (int s = max({l, 0}); s < min({(i) + 1, N}); ++s) {

int ip = l;
int kp = s;
J[i][j][k][l][s][t] += J[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

int kp = i;
for (int j = 0; j < N; ++j) {

for (int t = max({i, 0}); t < min({(j) + 1, N}); ++t) {

int lp = j;
for (int k = max({j, 0}); k < N; ++k) {

int jp = t;
int sp = k;
for (int l = 0; l < N; ++l) {

for (int s = max({l, 0}); s < min({(i) + 1, N}); ++s) {

int ip = l;
int tp = s;
J[i][j][k][l][s][t] += J[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

int jp = i;
for (int j = 0; j < N; ++j) {

int lp = j;
for (int k = 0; k < min({(j) + 1, N}); ++k) {

for (int t = max({i, 0}); t < min({(k) + 1, N}); ++t) {

int sp = k;
int kp = t;
for (int l = 0; l < N; ++l) {

for (int s = max({l, 0}); s < min({(i) + 1, N}); ++s) {

int ip = l;
int tp = s;
J[i][j][k][l][s][t] += J[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

int ip = i;
for (int j = 0; j < N; ++j) {

int lp = j;
for (int k = max({j, 0}); k < N; ++k) {

for (int s = max({k, 0}); s < min({(i) + 1, N}); ++s) {

int tp = k;
int kp = s;
for (int l = 0; l < N; ++l) {

for (int t = max({l, 0}); t < min({(j) + 1, N}); ++t) {

int jp = l;
int sp = t;
J[i][j][k][l][s][t] += J[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int s = max({i, 0}); s < N; ++s) {

int sp = i;
int kp = s;
for (int j = 0; j < N; ++j) {

int lp = j;
for (int k = max({j, 0}); k < min({(i) + 1, N}); ++k) {

for (int l = 0; l < N; ++l) {

int tp = k;
for (int t = max({l, 0}); t < min({(j) + 1, N}); ++t) {

int jp = l;
int ip = t;
J[i][j][k][l][s][t] += J[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

int ip = i;
for (int k = 0; k < min({(i) + 1, N}); ++k) {

for (int j = 0; j < N; ++j) {

int tp = k;
for (int s = max({j, 0}); s < min({(k) + 1, N}); ++s) {

int lp = j;
int sp = s;
for (int l = 0; l < N; ++l) {

for (int t = max({l, 0}); t < min({(j) + 1, N}); ++t) {

int jp = l;
int kp = t;
J[i][j][k][l][s][t] += J[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

int kp = i;
for (int k = max({i, 0}); k < N; ++k) {

for (int j = 0; j < N; ++j) {

int tp = k;
for (int s = max({j, 0}); s < min({(i) + 1, N}); ++s) {

int lp = j;
int sp = s;
for (int l = 0; l < N; ++l) {

for (int t = max({l, 0}); t < min({(j) + 1, N}); ++t) {

int jp = l;
int ip = t;
J[i][j][k][l][s][t] += J[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

int sp = i;
for (int j = 0; j < min({(i) + 1, N}); ++j) {

for (int k = max({i, 0}); k < N; ++k) {

int lp = j;
for (int s = max({k, 0}); s < N; ++s) {

int tp = k;
int ip = s;
for (int l = 0; l < N; ++l) {

for (int t = max({l, 0}); t < min({(j) + 1, N}); ++t) {

int jp = l;
int kp = t;
J[i][j][k][l][s][t] += J[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

int kp = i;
for (int j = 0; j < min({(i) + 1, N}); ++j) {

int lp = j;
for (int k = 0; k < N; ++k) {

for (int s = max({i, 0}); s < min({(k) + 1, N}); ++s) {

int tp = k;
int ip = s;
for (int l = 0; l < N; ++l) {

for (int t = max({l, 0}); t < min({(j) + 1, N}); ++t) {

int jp = l;
int sp = t;
J[i][j][k][l][s][t] += J[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

int ip = i;
for (int j = 0; j < N; ++j) {

for (int s = max({j, 0}); s < min({(i) + 1, N}); ++s) {

int lp = j;
for (int k = 0; k < min({(j) + 1, N}); ++k) {

int jp = s;
int tp = k;
for (int l = 0; l < N; ++l) {

for (int t = max({l, 0}); t < min({(k) + 1, N}); ++t) {

int kp = l;
int sp = t;
J[i][j][k][l][s][t] += J[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int s = max({i, 0}); s < N; ++s) {

int sp = i;
for (int j = 0; j < min({(i) + 1, N}); ++j) {

int jp = s;
int lp = j;
for (int k = 0; k < min({(j) + 1, N}); ++k) {

for (int l = 0; l < N; ++l) {

int tp = k;
for (int t = max({l, 0}); t < min({(k) + 1, N}); ++t) {

int kp = l;
int ip = t;
J[i][j][k][l][s][t] += J[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

int ip = i;
for (int j = 0; j < min({(i) + 1, N}); ++j) {

int lp = j;
for (int k = 0; k < N; ++k) {

for (int s = max({k, 0}); s < min({(j) + 1, N}); ++s) {

int tp = k;
int sp = s;
for (int l = 0; l < N; ++l) {

for (int t = max({l, 0}); t < min({(k) + 1, N}); ++t) {

int kp = l;
int jp = t;
J[i][j][k][l][s][t] += J[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

int jp = i;
for (int j = max({i, 0}); j < N; ++j) {

int lp = j;
for (int k = 0; k < N; ++k) {

for (int s = max({k, 0}); s < min({(i) + 1, N}); ++s) {

int tp = k;
int sp = s;
for (int l = 0; l < N; ++l) {

for (int t = max({l, 0}); t < min({(k) + 1, N}); ++t) {

int kp = l;
int ip = t;
J[i][j][k][l][s][t] += J[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

int sp = i;
for (int j = max({i, 0}); j < N; ++j) {

for (int k = 0; k < min({(i) + 1, N}); ++k) {

for (int s = max({j, 0}); s < N; ++s) {

int lp = j;
int tp = k;
int ip = s;
for (int l = 0; l < N; ++l) {

for (int t = max({l, 0}); t < min({(k) + 1, N}); ++t) {

int kp = l;
int jp = t;
J[i][j][k][l][s][t] += J[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

int jp = i;
for (int k = 0; k < min({(i) + 1, N}); ++k) {

for (int j = 0; j < N; ++j) {

int tp = k;
for (int s = max({i, 0}); s < min({(j) + 1, N}); ++s) {

int lp = j;
int ip = s;
for (int l = 0; l < N; ++l) {

for (int t = max({l, 0}); t < min({(k) + 1, N}); ++t) {

int kp = l;
int sp = t;
J[i][j][k][l][s][t] += J[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

int ip = i;
for (int j = 0; j < N; ++j) {

for (int s = 0; s < min({(j) + 1, N}); ++s) {

int lp = j;
for (int k = max({j, 0}); k < min({(i) + 1, N}); ++k) {

int jp = s;
int tp = k;
for (int l = 0; l < N; ++l) {

for (int t = max({l, 0}); t < min({(s) + 1, N}); ++t) {

int sp = l;
int kp = t;
J[i][j][k][l][s][t] += J[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

int kp = i;
for (int j = 0; j < min({(i) + 1, N}); ++j) {

for (int k = max({i, 0}); k < N; ++k) {

for (int s = 0; s < min({(j) + 1, N}); ++s) {

int lp = j;
int tp = k;
int jp = s;
for (int l = 0; l < N; ++l) {

for (int t = max({l, 0}); t < min({(s) + 1, N}); ++t) {

int sp = l;
int ip = t;
J[i][j][k][l][s][t] += J[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

int ip = i;
for (int j = 0; j < min({(i) + 1, N}); ++j) {

int lp = j;
for (int k = 0; k < min({(j) + 1, N}); ++k) {

for (int s = 0; s < min({(k) + 1, N}); ++s) {

int tp = k;
int kp = s;
for (int l = 0; l < N; ++l) {

for (int t = max({l, 0}); t < min({(s) + 1, N}); ++t) {

int sp = l;
int jp = t;
J[i][j][k][l][s][t] += J[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

int jp = i;
for (int j = max({i, 0}); j < N; ++j) {

for (int k = 0; k < min({(i) + 1, N}); ++k) {

int lp = j;
for (int s = 0; s < min({(k) + 1, N}); ++s) {

int tp = k;
int kp = s;
for (int l = 0; l < N; ++l) {

for (int t = max({l, 0}); t < min({(s) + 1, N}); ++t) {

int sp = l;
int ip = t;
J[i][j][k][l][s][t] += J[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int s = 0; s < min({(i) + 1, N}); ++s) {

int kp = i;
for (int j = max({i, 0}); j < N; ++j) {

int ip = s;
int lp = j;
for (int k = max({j, 0}); k < N; ++k) {

for (int l = 0; l < N; ++l) {

int tp = k;
for (int t = max({l, 0}); t < min({(s) + 1, N}); ++t) {

int sp = l;
int jp = t;
J[i][j][k][l][s][t] += J[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int s = 0; s < min({(i) + 1, N}); ++s) {

int jp = i;
int ip = s;
for (int j = 0; j < N; ++j) {

int lp = j;
for (int k = max({i, 0}); k < min({(j) + 1, N}); ++k) {

for (int l = 0; l < N; ++l) {

int tp = k;
for (int t = max({l, 0}); t < min({(s) + 1, N}); ++t) {

int sp = l;
int kp = t;
J[i][j][k][l][s][t] += J[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

int sp = i;
for (int j = max({i, 0}); j < N; ++j) {

int lp = j;
for (int k = max({j, 0}); k < N; ++k) {

for (int s = max({k, 0}); s < N; ++s) {

int tp = k;
int jp = s;
for (int l = 0; l < N; ++l) {

for (int t = max({l, 0}); t < min({(i) + 1, N}); ++t) {

int ip = l;
int kp = t;
J[i][j][k][l][s][t] += J[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

int kp = i;
for (int j = max({i, 0}); j < N; ++j) {

int lp = j;
for (int k = 0; k < N; ++k) {

for (int s = max({j, 0}); s < min({(k) + 1, N}); ++s) {

int tp = k;
int jp = s;
for (int l = 0; l < N; ++l) {

for (int t = max({l, 0}); t < min({(i) + 1, N}); ++t) {

int ip = l;
int sp = t;
J[i][j][k][l][s][t] += J[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

int sp = i;
for (int j = 0; j < N; ++j) {

for (int s = max({j, 0}); s < N; ++s) {

int lp = j;
for (int k = max({i, 0}); k < min({(j) + 1, N}); ++k) {

int kp = s;
int tp = k;
for (int l = 0; l < N; ++l) {

for (int t = max({l, 0}); t < min({(i) + 1, N}); ++t) {

int ip = l;
int jp = t;
J[i][j][k][l][s][t] += J[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

int jp = i;
for (int k = max({i, 0}); k < N; ++k) {

for (int j = 0; j < N; ++j) {

int tp = k;
for (int s = max({k, 0}); s < min({(j) + 1, N}); ++s) {

int lp = j;
int kp = s;
for (int l = 0; l < N; ++l) {

for (int t = max({l, 0}); t < min({(i) + 1, N}); ++t) {

int ip = l;
int sp = t;
J[i][j][k][l][s][t] += J[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

int kp = i;
for (int j = 0; j < N; ++j) {

for (int s = max({i, 0}); s < min({(j) + 1, N}); ++s) {

int lp = j;
for (int k = max({j, 0}); k < N; ++k) {

int sp = s;
int tp = k;
for (int l = 0; l < N; ++l) {

for (int t = max({l, 0}); t < min({(i) + 1, N}); ++t) {

int ip = l;
int jp = t;
J[i][j][k][l][s][t] += J[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

int jp = i;
for (int j = 0; j < N; ++j) {

int lp = j;
for (int k = 0; k < min({(j) + 1, N}); ++k) {

for (int s = max({i, 0}); s < min({(k) + 1, N}); ++s) {

int tp = k;
int sp = s;
for (int l = 0; l < N; ++l) {

for (int t = max({l, 0}); t < min({(i) + 1, N}); ++t) {

int ip = l;
int kp = t;
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

int tp = i;
int jp = l;
int lp = j;
for (int k = max({j, 0}); k < N; ++k) {

for (int s = max({k, 0}); s < N; ++s) {

int ip = k;
for (int t = max({s, 0}); t < N; ++t) {

int kp = s;
int sp = t;
J[i][j][k][l][s][t] += J[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int l = 0; l < min({(i) + 1, N}); ++l) {

int sp = i;
for (int j = max({i, 0}); j < N; ++j) {

int jp = l;
int lp = j;
for (int k = max({j, 0}); k < N; ++k) {

int ip = k;
for (int s = 0; s < N; ++s) {

for (int t = max({k, 0}); t < min({(s) + 1, N}); ++t) {

int kp = s;
int tp = t;
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

int tp = i;
int jp = l;
int lp = j;
for (int k = 0; k < N; ++k) {

for (int s = max({j, 0}); s < min({(k) + 1, N}); ++s) {

for (int t = max({k, 0}); t < N; ++t) {

int ip = k;
int sp = s;
int kp = t;
J[i][j][k][l][s][t] += J[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int l = 0; l < min({(i) + 1, N}); ++l) {

int kp = i;
for (int j = max({i, 0}); j < N; ++j) {

int jp = l;
for (int s = max({j, 0}); s < N; ++s) {

int lp = j;
int sp = s;
for (int k = 0; k < N; ++k) {

for (int t = max({s, 0}); t < min({(k) + 1, N}); ++t) {

int ip = k;
int tp = t;
J[i][j][k][l][s][t] += J[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int l = 0; l < min({(i) + 1, N}); ++l) {

int sp = i;
for (int j = max({i, 0}); j < N; ++j) {

int jp = l;
int lp = j;
for (int k = 0; k < N; ++k) {

for (int s = max({k, 0}); s < N; ++s) {

for (int t = max({j, 0}); t < min({(k) + 1, N}); ++t) {

int ip = k;
int tp = s;
int kp = t;
J[i][j][k][l][s][t] += J[ip][jp][kp][lp][sp][tp];
}
}
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
for (int k = 0; k < N; ++k) {

for (int s = 0; s < min({(k) + 1, N}); ++s) {

int ip = k;
for (int t = max({j, 0}); t < min({(s) + 1, N}); ++t) {

int tp = s;
int sp = t;
J[i][j][k][l][s][t] += J[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int l = 0; l < min({(i) + 1, N}); ++l) {

int tp = i;
int kp = l;
for (int j = 0; j < N; ++j) {

for (int s = max({j, 0}); s < N; ++s) {

int lp = j;
for (int k = max({i, 0}); k < min({(j) + 1, N}); ++k) {

for (int t = max({s, 0}); t < N; ++t) {

int jp = s;
int ip = k;
int sp = t;
J[i][j][k][l][s][t] += J[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int l = 0; l < min({(i) + 1, N}); ++l) {

int sp = i;
int kp = l;
for (int j = 0; j < N; ++j) {

int lp = j;
for (int k = max({i, 0}); k < min({(j) + 1, N}); ++k) {

int ip = k;
for (int s = 0; s < N; ++s) {

for (int t = max({j, 0}); t < min({(s) + 1, N}); ++t) {

int jp = s;
int tp = t;
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

int tp = i;
int kp = l;
int ip = k;
for (int j = 0; j < N; ++j) {

for (int s = max({k, 0}); s < min({(j) + 1, N}); ++s) {

for (int t = max({j, 0}); t < N; ++t) {

int lp = j;
int sp = s;
int jp = t;
J[i][j][k][l][s][t] += J[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int l = 0; l < min({(i) + 1, N}); ++l) {

int jp = i;
for (int k = max({i, 0}); k < N; ++k) {

int kp = l;
for (int s = max({k, 0}); s < N; ++s) {

int ip = k;
int sp = s;
for (int j = 0; j < N; ++j) {

for (int t = max({s, 0}); t < min({(j) + 1, N}); ++t) {

int lp = j;
int tp = t;
J[i][j][k][l][s][t] += J[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int l = 0; l < min({(i) + 1, N}); ++l) {

int sp = i;
for (int k = max({i, 0}); k < N; ++k) {

int kp = l;
int ip = k;
for (int j = 0; j < N; ++j) {

for (int s = max({j, 0}); s < N; ++s) {

for (int t = max({k, 0}); t < min({(j) + 1, N}); ++t) {

int lp = j;
int tp = s;
int jp = t;
J[i][j][k][l][s][t] += J[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int l = 0; l < min({(i) + 1, N}); ++l) {

int jp = i;
for (int k = max({i, 0}); k < N; ++k) {

int kp = l;
int ip = k;
for (int j = 0; j < N; ++j) {

for (int s = 0; s < min({(j) + 1, N}); ++s) {

int lp = j;
for (int t = max({k, 0}); t < min({(s) + 1, N}); ++t) {

int tp = s;
int sp = t;
J[i][j][k][l][s][t] += J[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int l = 0; l < min({(i) + 1, N}); ++l) {

int tp = i;
int sp = l;
for (int j = 0; j < N; ++j) {

for (int s = max({i, 0}); s < min({(j) + 1, N}); ++s) {

int lp = j;
for (int k = max({j, 0}); k < N; ++k) {

int jp = s;
for (int t = max({k, 0}); t < N; ++t) {

int ip = k;
int kp = t;
J[i][j][k][l][s][t] += J[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int l = 0; l < min({(i) + 1, N}); ++l) {

int kp = i;
int sp = l;
for (int j = 0; j < N; ++j) {

for (int s = max({i, 0}); s < min({(j) + 1, N}); ++s) {

int lp = j;
int jp = s;
for (int k = 0; k < N; ++k) {

for (int t = max({j, 0}); t < min({(k) + 1, N}); ++t) {

int ip = k;
int tp = t;
J[i][j][k][l][s][t] += J[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int l = 0; l < min({(i) + 1, N}); ++l) {

int tp = i;
int sp = l;
for (int j = 0; j < N; ++j) {

for (int t = max({j, 0}); t < N; ++t) {

int lp = j;
for (int k = 0; k < min({(j) + 1, N}); ++k) {

int jp = t;
for (int s = max({i, 0}); s < min({(k) + 1, N}); ++s) {

int ip = k;
int kp = s;
J[i][j][k][l][s][t] += J[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int l = 0; l < min({(i) + 1, N}); ++l) {

int jp = i;
int sp = l;
for (int j = 0; j < N; ++j) {

int lp = j;
for (int k = 0; k < N; ++k) {

for (int s = max({i, 0}); s < min({(k) + 1, N}); ++s) {

for (int t = max({k, 0}); t < min({(j) + 1, N}); ++t) {

int ip = k;
int kp = s;
int tp = t;
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

int kp = i;
int tp = s;
int sp = l;
for (int j = 0; j < N; ++j) {

for (int t = max({s, 0}); t < min({(j) + 1, N}); ++t) {

int lp = j;
for (int k = max({j, 0}); k < N; ++k) {

int jp = t;
int ip = k;
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

int jp = i;
int tp = s;
int sp = l;
for (int j = 0; j < N; ++j) {

int lp = j;
for (int k = 0; k < min({(j) + 1, N}); ++k) {

for (int t = max({s, 0}); t < min({(k) + 1, N}); ++t) {

int ip = k;
int kp = t;
J[i][j][k][l][s][t] += J[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int l = 0; l < min({(i) + 1, N}); ++l) {

int sp = i;
int tp = l;
for (int j = 0; j < N; ++j) {

for (int t = max({i, 0}); t < min({(j) + 1, N}); ++t) {

int lp = j;
for (int k = max({j, 0}); k < N; ++k) {

int kp = t;
for (int s = max({k, 0}); s < N; ++s) {

int ip = k;
int jp = s;
J[i][j][k][l][s][t] += J[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int l = 0; l < min({(i) + 1, N}); ++l) {

int kp = i;
int tp = l;
for (int j = 0; j < N; ++j) {

for (int t = max({i, 0}); t < min({(j) + 1, N}); ++t) {

int lp = j;
int sp = t;
for (int k = 0; k < N; ++k) {

for (int s = max({j, 0}); s < min({(k) + 1, N}); ++s) {

int ip = k;
int jp = s;
J[i][j][k][l][s][t] += J[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int l = 0; l < min({(i) + 1, N}); ++l) {

int sp = i;
int tp = l;
for (int j = 0; j < N; ++j) {

for (int s = max({j, 0}); s < N; ++s) {

int lp = j;
for (int k = 0; k < min({(j) + 1, N}); ++k) {

int kp = s;
for (int t = max({i, 0}); t < min({(k) + 1, N}); ++t) {

int ip = k;
int jp = t;
J[i][j][k][l][s][t] += J[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int l = 0; l < min({(i) + 1, N}); ++l) {

int jp = i;
int tp = l;
for (int j = 0; j < N; ++j) {

int lp = j;
for (int k = 0; k < N; ++k) {

for (int s = max({k, 0}); s < min({(j) + 1, N}); ++s) {

for (int t = max({i, 0}); t < min({(k) + 1, N}); ++t) {

int ip = k;
int kp = s;
int sp = t;
J[i][j][k][l][s][t] += J[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int l = 0; l < min({(i) + 1, N}); ++l) {

int kp = i;
int tp = l;
for (int j = 0; j < N; ++j) {

for (int s = 0; s < min({(j) + 1, N}); ++s) {

int lp = j;
for (int k = max({j, 0}); k < N; ++k) {

for (int t = max({i, 0}); t < min({(s) + 1, N}); ++t) {

int sp = s;
int ip = k;
int jp = t;
J[i][j][k][l][s][t] += J[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int l = 0; l < min({(i) + 1, N}); ++l) {

int jp = i;
int tp = l;
for (int j = 0; j < N; ++j) {

int lp = j;
for (int k = 0; k < min({(j) + 1, N}); ++k) {

for (int s = 0; s < min({(k) + 1, N}); ++s) {

int ip = k;
for (int t = max({i, 0}); t < min({(s) + 1, N}); ++t) {

int sp = s;
int kp = t;
J[i][j][k][l][s][t] += J[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

int ip = i;
for (int j = 0; j < N; ++j) {

for (int s = 0; s < min({(j) + 1, N}); ++s) {

int sp = j;
for (int k = max({j, 0}); k < N; ++k) {

int lp = s;
for (int l = max({k, 0}); l < N; ++l) {

int jp = k;
for (int t = max({l, 0}); t < min({(i) + 1, N}); ++t) {

int kp = l;
int tp = t;
J[i][j][k][l][s][t] += J[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int t = max({i, 0}); t < N; ++t) {

int tp = i;
int ip = t;
for (int j = 0; j < N; ++j) {

for (int s = 0; s < min({(j) + 1, N}); ++s) {

int sp = j;
for (int k = max({j, 0}); k < N; ++k) {

int lp = s;
for (int l = max({k, 0}); l < min({(i) + 1, N}); ++l) {

int jp = k;
int kp = l;
J[i][j][k][l][s][t] += J[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int l = 0; l < min({(i) + 1, N}); ++l) {

int ip = i;
int kp = l;
for (int j = 0; j < N; ++j) {

for (int s = 0; s < min({(j) + 1, N}); ++s) {

int sp = j;
for (int k = max({j, 0}); k < N; ++k) {

int tp = s;
for (int t = max({k, 0}); t < min({(l) + 1, N}); ++t) {

int jp = k;
int lp = t;
J[i][j][k][l][s][t] += J[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int l = max({i, 0}); l < N; ++l) {

int lp = i;
int kp = l;
for (int j = 0; j < N; ++j) {

for (int s = 0; s < min({(j) + 1, N}); ++s) {

int sp = j;
for (int k = max({j, 0}); k < N; ++k) {

int tp = s;
for (int t = max({k, 0}); t < min({(i) + 1, N}); ++t) {

int jp = k;
int ip = t;
J[i][j][k][l][s][t] += J[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int l = max({i, 0}); l < N; ++l) {

int tp = i;
for (int t = max({l, 0}); t < N; ++t) {

int kp = l;
int lp = t;
for (int j = 0; j < N; ++j) {

for (int s = 0; s < min({(j) + 1, N}); ++s) {

int sp = j;
for (int k = max({j, 0}); k < min({(i) + 1, N}); ++k) {

int ip = s;
int jp = k;
J[i][j][k][l][s][t] += J[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

int lp = i;
for (int j = 0; j < N; ++j) {

for (int s = 0; s < min({(j) + 1, N}); ++s) {

int sp = j;
for (int k = max({j, 0}); k < min({(i) + 1, N}); ++k) {

int ip = s;
int jp = k;
for (int l = 0; l < N; ++l) {

for (int t = max({i, 0}); t < min({(l) + 1, N}); ++t) {

int kp = l;
int tp = t;
J[i][j][k][l][s][t] += J[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

int ip = i;
for (int j = 0; j < N; ++j) {

for (int s = 0; s < min({(j) + 1, N}); ++s) {

int sp = j;
int kp = s;
for (int k = 0; k < N; ++k) {

for (int t = max({k, 0}); t < min({(i) + 1, N}); ++t) {

for (int l = max({j, 0}); l < min({(k) + 1, N}); ++l) {

int jp = k;
int tp = t;
int lp = l;
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

int tp = i;
int ip = t;
int jp = k;
for (int j = 0; j < N; ++j) {

for (int s = 0; s < min({(j) + 1, N}); ++s) {

for (int l = max({j, 0}); l < min({(k) + 1, N}); ++l) {

int sp = j;
int kp = s;
int lp = l;
J[i][j][k][l][s][t] += J[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

int ip = i;
for (int k = 0; k < min({(i) + 1, N}); ++k) {

int jp = k;
for (int j = 0; j < N; ++j) {

for (int s = 0; s < min({(j) + 1, N}); ++s) {

for (int l = max({j, 0}); l < N; ++l) {

int sp = j;
int tp = s;
for (int t = max({l, 0}); t < min({(k) + 1, N}); ++t) {

int lp = l;
int kp = t;
J[i][j][k][l][s][t] += J[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

int kp = i;
for (int k = max({i, 0}); k < N; ++k) {

int jp = k;
for (int j = 0; j < N; ++j) {

for (int s = 0; s < min({(j) + 1, N}); ++s) {

for (int l = max({j, 0}); l < N; ++l) {

int sp = j;
int tp = s;
for (int t = max({l, 0}); t < min({(i) + 1, N}); ++t) {

int lp = l;
int ip = t;
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

int tp = i;
for (int s = 0; s < min({(j) + 1, N}); ++s) {

for (int l = max({j, 0}); l < min({(i) + 1, N}); ++l) {

int sp = j;
for (int t = max({k, 0}); t < N; ++t) {

int jp = k;
int ip = s;
int lp = l;
int kp = t;
J[i][j][k][l][s][t] += J[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

int kp = i;
for (int j = 0; j < N; ++j) {

for (int s = 0; s < min({(j) + 1, N}); ++s) {

for (int l = max({j, 0}); l < min({(i) + 1, N}); ++l) {

int sp = j;
int ip = s;
int lp = l;
for (int k = 0; k < N; ++k) {

for (int t = max({i, 0}); t < min({(k) + 1, N}); ++t) {

int jp = k;
int tp = t;
J[i][j][k][l][s][t] += J[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

int ip = i;
for (int j = 0; j < N; ++j) {

for (int s = 0; s < min({(j) + 1, N}); ++s) {

int sp = j;
int kp = s;
for (int k = 0; k < N; ++k) {

for (int t = max({j, 0}); t < min({(k) + 1, N}); ++t) {

for (int l = max({k, 0}); l < min({(i) + 1, N}); ++l) {

int jp = k;
int lp = t;
int tp = l;
J[i][j][k][l][s][t] += J[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int l = max({i, 0}); l < N; ++l) {

int lp = i;
for (int k = 0; k < min({(i) + 1, N}); ++k) {

int tp = l;
int jp = k;
for (int j = 0; j < N; ++j) {

for (int s = 0; s < min({(j) + 1, N}); ++s) {

for (int t = max({j, 0}); t < min({(k) + 1, N}); ++t) {

int sp = j;
int kp = s;
int ip = t;
J[i][j][k][l][s][t] += J[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

int ip = i;
for (int k = 0; k < min({(i) + 1, N}); ++k) {

for (int l = 0; l < min({(k) + 1, N}); ++l) {

int jp = k;
int tp = l;
for (int j = 0; j < N; ++j) {

for (int s = 0; s < min({(j) + 1, N}); ++s) {

for (int t = max({j, 0}); t < min({(l) + 1, N}); ++t) {

int sp = j;
int lp = s;
int kp = t;
J[i][j][k][l][s][t] += J[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int l = 0; l < min({(i) + 1, N}); ++l) {

int kp = i;
for (int k = max({i, 0}); k < N; ++k) {

int tp = l;
int jp = k;
for (int j = 0; j < N; ++j) {

for (int s = 0; s < min({(j) + 1, N}); ++s) {

for (int t = max({j, 0}); t < min({(l) + 1, N}); ++t) {

int sp = j;
int lp = s;
int ip = t;
J[i][j][k][l][s][t] += J[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

int lp = i;
for (int k = max({i, 0}); k < N; ++k) {

for (int l = max({k, 0}); l < N; ++l) {

int jp = k;
int tp = l;
for (int j = 0; j < N; ++j) {

for (int s = 0; s < min({(j) + 1, N}); ++s) {

for (int t = max({j, 0}); t < min({(i) + 1, N}); ++t) {

int sp = j;
int ip = s;
int kp = t;
J[i][j][k][l][s][t] += J[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

int kp = i;
for (int j = 0; j < N; ++j) {

for (int s = 0; s < min({(j) + 1, N}); ++s) {

for (int t = max({j, 0}); t < min({(i) + 1, N}); ++t) {

int sp = j;
int ip = s;
int lp = t;
for (int k = 0; k < N; ++k) {

for (int l = max({i, 0}); l < min({(k) + 1, N}); ++l) {

int jp = k;
int tp = l;
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

int tp = i;
for (int s = 0; s < min({(j) + 1, N}); ++s) {

int sp = j;
for (int l = max({k, 0}); l < N; ++l) {

int jp = k;
int kp = s;
for (int t = max({l, 0}); t < N; ++t) {

int ip = l;
int lp = t;
J[i][j][k][l][s][t] += J[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

int lp = i;
for (int j = 0; j < min({(i) + 1, N}); ++j) {

for (int k = max({i, 0}); k < N; ++k) {

for (int s = 0; s < min({(j) + 1, N}); ++s) {

int sp = j;
int jp = k;
int kp = s;
for (int l = 0; l < N; ++l) {

for (int t = max({k, 0}); t < min({(l) + 1, N}); ++t) {

int ip = l;
int tp = t;
J[i][j][k][l][s][t] += J[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int j = 0; j < min({(i) + 1, N}); ++j) {

int tp = i;
for (int s = 0; s < min({(j) + 1, N}); ++s) {

int sp = j;
int lp = s;
for (int k = 0; k < N; ++k) {

for (int t = max({k, 0}); t < N; ++t) {

for (int l = max({i, 0}); l < min({(k) + 1, N}); ++l) {

int jp = k;
int kp = t;
int ip = l;
J[i][j][k][l][s][t] += J[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int l = max({i, 0}); l < N; ++l) {

int kp = i;
for (int j = 0; j < min({(i) + 1, N}); ++j) {

int ip = l;
for (int s = 0; s < min({(j) + 1, N}); ++s) {

int sp = j;
int lp = s;
for (int k = 0; k < N; ++k) {

for (int t = max({l, 0}); t < min({(k) + 1, N}); ++t) {

int jp = k;
int tp = t;
J[i][j][k][l][s][t] += J[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

int lp = i;
for (int j = 0; j < min({(i) + 1, N}); ++j) {

for (int s = 0; s < min({(j) + 1, N}); ++s) {

int sp = j;
int tp = s;
for (int k = 0; k < N; ++k) {

for (int t = max({i, 0}); t < min({(k) + 1, N}); ++t) {

for (int l = max({k, 0}); l < N; ++l) {

int jp = k;
int kp = t;
int ip = l;
J[i][j][k][l][s][t] += J[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

int kp = i;
for (int j = 0; j < min({(i) + 1, N}); ++j) {

for (int s = 0; s < min({(j) + 1, N}); ++s) {

int sp = j;
int tp = s;
for (int k = 0; k < N; ++k) {

for (int l = 0; l < min({(k) + 1, N}); ++l) {

int jp = k;
for (int t = max({i, 0}); t < min({(l) + 1, N}); ++t) {

int ip = l;
int lp = t;
J[i][j][k][l][s][t] += J[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

int ip = i;
for (int j = 0; j < N; ++j) {

for (int l = max({j, 0}); l < N; ++l) {

int sp = j;
for (int k = 0; k < min({(j) + 1, N}); ++k) {

for (int t = max({l, 0}); t < min({(i) + 1, N}); ++t) {

int jp = l;
for (int s = 0; s < min({(k) + 1, N}); ++s) {

int kp = k;
int tp = t;
int lp = s;
J[i][j][k][l][s][t] += J[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int t = max({i, 0}); t < N; ++t) {

int tp = i;
int ip = t;
for (int j = 0; j < N; ++j) {

for (int l = max({j, 0}); l < min({(i) + 1, N}); ++l) {

int sp = j;
for (int k = 0; k < min({(j) + 1, N}); ++k) {

int jp = l;
for (int s = 0; s < min({(k) + 1, N}); ++s) {

int kp = k;
int lp = s;
J[i][j][k][l][s][t] += J[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int l = 0; l < min({(i) + 1, N}); ++l) {

int ip = i;
int jp = l;
for (int j = 0; j < N; ++j) {

for (int t = max({j, 0}); t < min({(l) + 1, N}); ++t) {

int sp = j;
for (int k = 0; k < min({(j) + 1, N}); ++k) {

int lp = t;
for (int s = 0; s < min({(k) + 1, N}); ++s) {

int kp = k;
int tp = s;
J[i][j][k][l][s][t] += J[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int l = max({i, 0}); l < N; ++l) {

int lp = i;
int jp = l;
for (int j = 0; j < N; ++j) {

for (int t = max({j, 0}); t < min({(i) + 1, N}); ++t) {

int sp = j;
for (int k = 0; k < min({(j) + 1, N}); ++k) {

int ip = t;
for (int s = 0; s < min({(k) + 1, N}); ++s) {

int kp = k;
int tp = s;
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

int tp = i;
for (int t = max({l, 0}); t < N; ++t) {

int jp = l;
int sp = j;
for (int k = 0; k < min({(j) + 1, N}); ++k) {

int lp = t;
for (int s = 0; s < min({(k) + 1, N}); ++s) {

int kp = k;
int ip = s;
J[i][j][k][l][s][t] += J[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

int lp = i;
for (int j = 0; j < min({(i) + 1, N}); ++j) {

int sp = j;
for (int k = 0; k < min({(j) + 1, N}); ++k) {

for (int s = 0; s < min({(k) + 1, N}); ++s) {

int kp = k;
int ip = s;
for (int l = 0; l < N; ++l) {

for (int t = max({i, 0}); t < min({(l) + 1, N}); ++t) {

int jp = l;
int tp = t;
J[i][j][k][l][s][t] += J[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

int ip = i;
for (int j = 0; j < N; ++j) {

for (int t = max({j, 0}); t < min({(i) + 1, N}); ++t) {

int sp = j;
int tp = t;
for (int k = 0; k < N; ++k) {

for (int s = 0; s < min({(k) + 1, N}); ++s) {

for (int l = max({k, 0}); l < min({(j) + 1, N}); ++l) {

int kp = k;
int jp = s;
int lp = l;
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

int tp = i;
int ip = t;
int sp = j;
for (int k = 0; k < N; ++k) {

for (int s = 0; s < min({(k) + 1, N}); ++s) {

for (int l = max({k, 0}); l < min({(j) + 1, N}); ++l) {

int kp = k;
int jp = s;
int lp = l;
J[i][j][k][l][s][t] += J[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

int ip = i;
for (int j = 0; j < min({(i) + 1, N}); ++j) {

int sp = j;
for (int k = 0; k < N; ++k) {

for (int s = 0; s < min({(k) + 1, N}); ++s) {

for (int l = max({k, 0}); l < N; ++l) {

int kp = k;
int tp = s;
for (int t = max({l, 0}); t < min({(j) + 1, N}); ++t) {

int lp = l;
int jp = t;
J[i][j][k][l][s][t] += J[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

int jp = i;
for (int j = max({i, 0}); j < N; ++j) {

int sp = j;
for (int k = 0; k < N; ++k) {

for (int s = 0; s < min({(k) + 1, N}); ++s) {

for (int l = max({k, 0}); l < N; ++l) {

int kp = k;
int tp = s;
for (int t = max({l, 0}); t < min({(i) + 1, N}); ++t) {

int lp = l;
int ip = t;
J[i][j][k][l][s][t] += J[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int j = max({i, 0}); j < N; ++j) {

int tp = i;
for (int t = max({j, 0}); t < N; ++t) {

int sp = j;
int jp = t;
for (int k = 0; k < N; ++k) {

for (int s = 0; s < min({(k) + 1, N}); ++s) {

for (int l = max({k, 0}); l < min({(i) + 1, N}); ++l) {

int kp = k;
int ip = s;
int lp = l;
J[i][j][k][l][s][t] += J[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

int jp = i;
for (int j = 0; j < N; ++j) {

for (int t = max({i, 0}); t < min({(j) + 1, N}); ++t) {

int sp = j;
int tp = t;
for (int k = 0; k < N; ++k) {

for (int s = 0; s < min({(k) + 1, N}); ++s) {

for (int l = max({k, 0}); l < min({(i) + 1, N}); ++l) {

int kp = k;
int ip = s;
int lp = l;
J[i][j][k][l][s][t] += J[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

int ip = i;
for (int j = 0; j < N; ++j) {

for (int l = max({j, 0}); l < min({(i) + 1, N}); ++l) {

int sp = j;
int tp = l;
for (int k = 0; k < N; ++k) {

for (int s = 0; s < min({(k) + 1, N}); ++s) {

for (int t = max({k, 0}); t < min({(j) + 1, N}); ++t) {

int kp = k;
int jp = s;
int lp = t;
J[i][j][k][l][s][t] += J[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int l = max({i, 0}); l < N; ++l) {

int lp = i;
for (int j = 0; j < min({(i) + 1, N}); ++j) {

int tp = l;
int sp = j;
for (int k = 0; k < N; ++k) {

for (int s = 0; s < min({(k) + 1, N}); ++s) {

for (int t = max({k, 0}); t < min({(j) + 1, N}); ++t) {

int kp = k;
int jp = s;
int ip = t;
J[i][j][k][l][s][t] += J[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

int ip = i;
for (int j = 0; j < min({(i) + 1, N}); ++j) {

for (int l = 0; l < min({(j) + 1, N}); ++l) {

int sp = j;
int tp = l;
for (int k = 0; k < N; ++k) {

for (int s = 0; s < min({(k) + 1, N}); ++s) {

for (int t = max({k, 0}); t < min({(l) + 1, N}); ++t) {

int kp = k;
int lp = s;
int jp = t;
J[i][j][k][l][s][t] += J[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int l = 0; l < min({(i) + 1, N}); ++l) {

int jp = i;
for (int j = max({i, 0}); j < N; ++j) {

int tp = l;
int sp = j;
for (int k = 0; k < N; ++k) {

for (int s = 0; s < min({(k) + 1, N}); ++s) {

for (int t = max({k, 0}); t < min({(l) + 1, N}); ++t) {

int kp = k;
int lp = s;
int ip = t;
J[i][j][k][l][s][t] += J[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

int lp = i;
for (int j = max({i, 0}); j < N; ++j) {

for (int l = max({j, 0}); l < N; ++l) {

int sp = j;
int tp = l;
for (int k = 0; k < N; ++k) {

for (int s = 0; s < min({(k) + 1, N}); ++s) {

for (int t = max({k, 0}); t < min({(i) + 1, N}); ++t) {

int kp = k;
int ip = s;
int jp = t;
J[i][j][k][l][s][t] += J[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

int jp = i;
for (int j = 0; j < N; ++j) {

for (int l = max({i, 0}); l < min({(j) + 1, N}); ++l) {

int sp = j;
int tp = l;
for (int k = 0; k < N; ++k) {

for (int s = 0; s < min({(k) + 1, N}); ++s) {

for (int t = max({k, 0}); t < min({(i) + 1, N}); ++t) {

int kp = k;
int ip = s;
int lp = t;
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

int tp = i;
for (int l = max({j, 0}); l < N; ++l) {

int sp = j;
for (int s = 0; s < min({(k) + 1, N}); ++s) {

int kp = k;
for (int t = max({l, 0}); t < N; ++t) {

int ip = l;
int jp = s;
int lp = t;
J[i][j][k][l][s][t] += J[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

int lp = i;
for (int j = max({i, 0}); j < N; ++j) {

for (int k = 0; k < min({(i) + 1, N}); ++k) {

int sp = j;
for (int s = 0; s < min({(k) + 1, N}); ++s) {

int kp = k;
int jp = s;
for (int l = 0; l < N; ++l) {

for (int t = max({j, 0}); t < min({(l) + 1, N}); ++t) {

int ip = l;
int tp = t;
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

int tp = i;
for (int t = max({j, 0}); t < N; ++t) {

for (int l = max({i, 0}); l < min({(j) + 1, N}); ++l) {

int sp = j;
for (int s = 0; s < min({(k) + 1, N}); ++s) {

int kp = k;
int jp = t;
int ip = l;
int lp = s;
J[i][j][k][l][s][t] += J[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int l = max({i, 0}); l < N; ++l) {

int jp = i;
for (int k = 0; k < min({(i) + 1, N}); ++k) {

int ip = l;
for (int s = 0; s < min({(k) + 1, N}); ++s) {

int kp = k;
int lp = s;
for (int j = 0; j < N; ++j) {

for (int t = max({l, 0}); t < min({(j) + 1, N}); ++t) {

int sp = j;
int tp = t;
J[i][j][k][l][s][t] += J[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

int lp = i;
for (int k = 0; k < min({(i) + 1, N}); ++k) {

for (int s = 0; s < min({(k) + 1, N}); ++s) {

int kp = k;
int tp = s;
for (int j = 0; j < N; ++j) {

for (int t = max({i, 0}); t < min({(j) + 1, N}); ++t) {

for (int l = max({j, 0}); l < N; ++l) {

int sp = j;
int jp = t;
int ip = l;
J[i][j][k][l][s][t] += J[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

int jp = i;
for (int k = 0; k < min({(i) + 1, N}); ++k) {

for (int s = 0; s < min({(k) + 1, N}); ++s) {

int kp = k;
int tp = s;
for (int j = 0; j < N; ++j) {

for (int l = 0; l < min({(j) + 1, N}); ++l) {

int sp = j;
for (int t = max({i, 0}); t < min({(l) + 1, N}); ++t) {

int ip = l;
int lp = t;
J[i][j][k][l][s][t] += J[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

int ip = i;
for (int j = 0; j < N; ++j) {

for (int l = 0; l < min({(j) + 1, N}); ++l) {

int sp = j;
for (int k = max({j, 0}); k < N; ++k) {

for (int s = 0; s < min({(l) + 1, N}); ++s) {

int jp = l;
for (int t = max({k, 0}); t < min({(i) + 1, N}); ++t) {

int lp = k;
int kp = s;
int tp = t;
J[i][j][k][l][s][t] += J[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int t = max({i, 0}); t < N; ++t) {

int tp = i;
int ip = t;
for (int j = 0; j < N; ++j) {

for (int l = 0; l < min({(j) + 1, N}); ++l) {

int sp = j;
for (int k = max({j, 0}); k < min({(i) + 1, N}); ++k) {

for (int s = 0; s < min({(l) + 1, N}); ++s) {

int jp = l;
int lp = k;
int kp = s;
J[i][j][k][l][s][t] += J[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

int ip = i;
for (int k = 0; k < min({(i) + 1, N}); ++k) {

int lp = k;
for (int j = 0; j < N; ++j) {

for (int t = max({j, 0}); t < min({(k) + 1, N}); ++t) {

for (int l = 0; l < min({(j) + 1, N}); ++l) {

int sp = j;
int kp = t;
for (int s = 0; s < min({(l) + 1, N}); ++s) {

int jp = l;
int tp = s;
J[i][j][k][l][s][t] += J[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

int kp = i;
for (int k = max({i, 0}); k < N; ++k) {

int lp = k;
for (int j = 0; j < N; ++j) {

for (int t = max({j, 0}); t < min({(i) + 1, N}); ++t) {

for (int l = 0; l < min({(j) + 1, N}); ++l) {

int sp = j;
int ip = t;
for (int s = 0; s < min({(l) + 1, N}); ++s) {

int jp = l;
int tp = s;
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

int tp = i;
for (int l = 0; l < min({(j) + 1, N}); ++l) {

int sp = j;
for (int t = max({k, 0}); t < N; ++t) {

int lp = k;
for (int s = 0; s < min({(l) + 1, N}); ++s) {

int jp = l;
int kp = t;
int ip = s;
J[i][j][k][l][s][t] += J[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

int kp = i;
for (int j = 0; j < min({(i) + 1, N}); ++j) {

for (int l = 0; l < min({(j) + 1, N}); ++l) {

int sp = j;
for (int s = 0; s < min({(l) + 1, N}); ++s) {

int jp = l;
int ip = s;
for (int k = 0; k < N; ++k) {

for (int t = max({i, 0}); t < min({(k) + 1, N}); ++t) {

int lp = k;
int tp = t;
J[i][j][k][l][s][t] += J[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

int ip = i;
for (int j = 0; j < N; ++j) {

for (int t = max({j, 0}); t < min({(i) + 1, N}); ++t) {

int sp = j;
for (int k = 0; k < min({(j) + 1, N}); ++k) {

int tp = t;
for (int l = 0; l < min({(k) + 1, N}); ++l) {

int lp = k;
for (int s = 0; s < min({(l) + 1, N}); ++s) {

int kp = l;
int jp = s;
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

int tp = i;
int ip = t;
int sp = j;
for (int k = 0; k < min({(j) + 1, N}); ++k) {

for (int l = 0; l < min({(k) + 1, N}); ++l) {

int lp = k;
for (int s = 0; s < min({(l) + 1, N}); ++s) {

int kp = l;
int jp = s;
J[i][j][k][l][s][t] += J[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

int ip = i;
for (int j = 0; j < min({(i) + 1, N}); ++j) {

int sp = j;
for (int k = 0; k < N; ++k) {

for (int t = max({k, 0}); t < min({(j) + 1, N}); ++t) {

for (int l = 0; l < min({(k) + 1, N}); ++l) {

int lp = k;
int jp = t;
for (int s = 0; s < min({(l) + 1, N}); ++s) {

int kp = l;
int tp = s;
J[i][j][k][l][s][t] += J[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

int jp = i;
for (int j = max({i, 0}); j < N; ++j) {

int sp = j;
for (int k = 0; k < N; ++k) {

for (int t = max({k, 0}); t < min({(i) + 1, N}); ++t) {

for (int l = 0; l < min({(k) + 1, N}); ++l) {

int lp = k;
int ip = t;
for (int s = 0; s < min({(l) + 1, N}); ++s) {

int kp = l;
int tp = s;
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

int tp = i;
for (int t = max({j, 0}); t < N; ++t) {

int sp = j;
for (int l = 0; l < min({(k) + 1, N}); ++l) {

int lp = k;
int jp = t;
for (int s = 0; s < min({(l) + 1, N}); ++s) {

int kp = l;
int ip = s;
J[i][j][k][l][s][t] += J[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

int jp = i;
for (int k = 0; k < min({(i) + 1, N}); ++k) {

for (int l = 0; l < min({(k) + 1, N}); ++l) {

int lp = k;
for (int s = 0; s < min({(l) + 1, N}); ++s) {

int kp = l;
int ip = s;
for (int j = 0; j < N; ++j) {

for (int t = max({i, 0}); t < min({(j) + 1, N}); ++t) {

int sp = j;
int tp = t;
J[i][j][k][l][s][t] += J[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

int ip = i;
for (int j = 0; j < N; ++j) {

int sp = j;
for (int k = max({j, 0}); k < min({(i) + 1, N}); ++k) {

for (int l = 0; l < N; ++l) {

int lp = k;
for (int s = 0; s < min({(l) + 1, N}); ++s) {

for (int t = max({l, 0}); t < min({(j) + 1, N}); ++t) {

int tp = l;
int jp = s;
int kp = t;
J[i][j][k][l][s][t] += J[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

int kp = i;
for (int j = 0; j < min({(i) + 1, N}); ++j) {

for (int k = max({i, 0}); k < N; ++k) {

int sp = j;
int lp = k;
for (int l = 0; l < N; ++l) {

for (int s = 0; s < min({(l) + 1, N}); ++s) {

for (int t = max({l, 0}); t < min({(j) + 1, N}); ++t) {

int tp = l;
int jp = s;
int ip = t;
J[i][j][k][l][s][t] += J[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

int ip = i;
for (int j = 0; j < min({(i) + 1, N}); ++j) {

int sp = j;
for (int k = 0; k < min({(j) + 1, N}); ++k) {

for (int l = 0; l < N; ++l) {

int lp = k;
for (int s = 0; s < min({(l) + 1, N}); ++s) {

for (int t = max({l, 0}); t < min({(k) + 1, N}); ++t) {

int tp = l;
int kp = s;
int jp = t;
J[i][j][k][l][s][t] += J[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

int jp = i;
for (int j = max({i, 0}); j < N; ++j) {

for (int k = 0; k < min({(i) + 1, N}); ++k) {

int sp = j;
int lp = k;
for (int l = 0; l < N; ++l) {

for (int s = 0; s < min({(l) + 1, N}); ++s) {

for (int t = max({l, 0}); t < min({(k) + 1, N}); ++t) {

int tp = l;
int kp = s;
int ip = t;
J[i][j][k][l][s][t] += J[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

int kp = i;
for (int j = max({i, 0}); j < N; ++j) {

int sp = j;
for (int k = max({j, 0}); k < N; ++k) {

for (int l = 0; l < N; ++l) {

int lp = k;
for (int s = 0; s < min({(l) + 1, N}); ++s) {

for (int t = max({l, 0}); t < min({(i) + 1, N}); ++t) {

int tp = l;
int ip = s;
int jp = t;
J[i][j][k][l][s][t] += J[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

int jp = i;
for (int j = 0; j < N; ++j) {

int sp = j;
for (int k = max({i, 0}); k < min({(j) + 1, N}); ++k) {

for (int l = 0; l < N; ++l) {

int lp = k;
for (int s = 0; s < min({(l) + 1, N}); ++s) {

for (int t = max({l, 0}); t < min({(i) + 1, N}); ++t) {

int tp = l;
int ip = s;
int kp = t;
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

int tp = i;
for (int s = 0; s < min({(l) + 1, N}); ++s) {

int ip = l;
int sp = j;
for (int k = max({j, 0}); k < N; ++k) {

int jp = s;
for (int t = max({k, 0}); t < N; ++t) {

int lp = k;
int kp = t;
J[i][j][k][l][s][t] += J[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int l = 0; l < min({(i) + 1, N}); ++l) {

int kp = i;
for (int j = max({i, 0}); j < N; ++j) {

for (int s = 0; s < min({(l) + 1, N}); ++s) {

int ip = l;
int sp = j;
int jp = s;
for (int k = 0; k < N; ++k) {

for (int t = max({j, 0}); t < min({(k) + 1, N}); ++t) {

int lp = k;
int tp = t;
J[i][j][k][l][s][t] += J[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int l = 0; l < min({(i) + 1, N}); ++l) {

int tp = i;
for (int s = 0; s < min({(l) + 1, N}); ++s) {

int ip = l;
int kp = s;
for (int j = 0; j < N; ++j) {

for (int t = max({j, 0}); t < N; ++t) {

int sp = j;
for (int k = max({i, 0}); k < min({(j) + 1, N}); ++k) {

int jp = t;
int lp = k;
J[i][j][k][l][s][t] += J[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int l = 0; l < min({(i) + 1, N}); ++l) {

int jp = i;
for (int k = max({i, 0}); k < N; ++k) {

for (int s = 0; s < min({(l) + 1, N}); ++s) {

int ip = l;
int lp = k;
int kp = s;
for (int j = 0; j < N; ++j) {

for (int t = max({k, 0}); t < min({(j) + 1, N}); ++t) {

int sp = j;
int tp = t;
J[i][j][k][l][s][t] += J[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int l = 0; l < min({(i) + 1, N}); ++l) {

int kp = i;
for (int s = 0; s < min({(l) + 1, N}); ++s) {

int ip = l;
int tp = s;
for (int j = 0; j < N; ++j) {

for (int t = max({i, 0}); t < min({(j) + 1, N}); ++t) {

int sp = j;
for (int k = max({j, 0}); k < N; ++k) {

int jp = t;
int lp = k;
J[i][j][k][l][s][t] += J[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int l = 0; l < min({(i) + 1, N}); ++l) {

int jp = i;
for (int s = 0; s < min({(l) + 1, N}); ++s) {

int ip = l;
int tp = s;
for (int j = 0; j < N; ++j) {

int sp = j;
for (int k = 0; k < min({(j) + 1, N}); ++k) {

for (int t = max({i, 0}); t < min({(k) + 1, N}); ++t) {

int lp = k;
int kp = t;
J[i][j][k][l][s][t] += J[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

int ip = i;
for (int j = 0; j < N; ++j) {

int sp = j;
for (int k = max({j, 0}); k < N; ++k) {

for (int l = max({k, 0}); l < min({(i) + 1, N}); ++l) {

int tp = k;
int jp = l;
for (int s = 0; s < N; ++s) {

for (int t = max({s, 0}); t < min({(j) + 1, N}); ++t) {

int kp = s;
int lp = t;
J[i][j][k][l][s][t] += J[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int l = max({i, 0}); l < N; ++l) {

int lp = i;
int jp = l;
for (int j = 0; j < N; ++j) {

int sp = j;
for (int k = max({j, 0}); k < min({(i) + 1, N}); ++k) {

int tp = k;
for (int s = 0; s < N; ++s) {

for (int t = max({s, 0}); t < min({(j) + 1, N}); ++t) {

int kp = s;
int ip = t;
J[i][j][k][l][s][t] += J[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

int ip = i;
for (int k = 0; k < min({(i) + 1, N}); ++k) {

for (int j = 0; j < N; ++j) {

int tp = k;
for (int l = max({j, 0}); l < min({(k) + 1, N}); ++l) {

int sp = j;
int jp = l;
for (int s = 0; s < N; ++s) {

for (int t = max({s, 0}); t < min({(j) + 1, N}); ++t) {

int lp = s;
int kp = t;
J[i][j][k][l][s][t] += J[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

int kp = i;
for (int k = max({i, 0}); k < N; ++k) {

for (int j = 0; j < N; ++j) {

int tp = k;
for (int l = max({j, 0}); l < min({(i) + 1, N}); ++l) {

int sp = j;
int jp = l;
for (int s = 0; s < N; ++s) {

for (int t = max({s, 0}); t < min({(j) + 1, N}); ++t) {

int lp = s;
int ip = t;
J[i][j][k][l][s][t] += J[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

int lp = i;
for (int j = 0; j < min({(i) + 1, N}); ++j) {

for (int k = max({i, 0}); k < N; ++k) {

int sp = j;
for (int l = max({k, 0}); l < N; ++l) {

int tp = k;
int jp = l;
for (int s = 0; s < N; ++s) {

for (int t = max({s, 0}); t < min({(j) + 1, N}); ++t) {

int ip = s;
int kp = t;
J[i][j][k][l][s][t] += J[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

int kp = i;
for (int j = 0; j < min({(i) + 1, N}); ++j) {

int sp = j;
for (int k = 0; k < N; ++k) {

for (int l = max({i, 0}); l < min({(k) + 1, N}); ++l) {

int tp = k;
int jp = l;
for (int s = 0; s < N; ++s) {

for (int t = max({s, 0}); t < min({(j) + 1, N}); ++t) {

int ip = s;
int lp = t;
J[i][j][k][l][s][t] += J[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

int ip = i;
for (int j = 0; j < N; ++j) {

for (int l = max({j, 0}); l < min({(i) + 1, N}); ++l) {

int sp = j;
for (int k = 0; k < min({(j) + 1, N}); ++k) {

int kp = l;
int tp = k;
for (int s = 0; s < N; ++s) {

for (int t = max({s, 0}); t < min({(k) + 1, N}); ++t) {

int jp = s;
int lp = t;
J[i][j][k][l][s][t] += J[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int l = max({i, 0}); l < N; ++l) {

int lp = i;
for (int j = 0; j < min({(i) + 1, N}); ++j) {

int kp = l;
int sp = j;
for (int k = 0; k < min({(j) + 1, N}); ++k) {

int tp = k;
for (int s = 0; s < N; ++s) {

for (int t = max({s, 0}); t < min({(k) + 1, N}); ++t) {

int jp = s;
int ip = t;
J[i][j][k][l][s][t] += J[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

int ip = i;
for (int j = 0; j < min({(i) + 1, N}); ++j) {

int sp = j;
for (int k = 0; k < N; ++k) {

for (int l = max({k, 0}); l < min({(j) + 1, N}); ++l) {

int tp = k;
int kp = l;
for (int s = 0; s < N; ++s) {

for (int t = max({s, 0}); t < min({(k) + 1, N}); ++t) {

int lp = s;
int jp = t;
J[i][j][k][l][s][t] += J[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

int jp = i;
for (int j = max({i, 0}); j < N; ++j) {

int sp = j;
for (int k = 0; k < N; ++k) {

for (int l = max({k, 0}); l < min({(i) + 1, N}); ++l) {

int tp = k;
int kp = l;
for (int s = 0; s < N; ++s) {

for (int t = max({s, 0}); t < min({(k) + 1, N}); ++t) {

int lp = s;
int ip = t;
J[i][j][k][l][s][t] += J[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

int lp = i;
for (int j = max({i, 0}); j < N; ++j) {

for (int k = 0; k < min({(i) + 1, N}); ++k) {

for (int l = max({j, 0}); l < N; ++l) {

int sp = j;
int tp = k;
int kp = l;
for (int s = 0; s < N; ++s) {

for (int t = max({s, 0}); t < min({(k) + 1, N}); ++t) {

int ip = s;
int jp = t;
J[i][j][k][l][s][t] += J[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

int jp = i;
for (int k = 0; k < min({(i) + 1, N}); ++k) {

for (int j = 0; j < N; ++j) {

int tp = k;
for (int l = max({i, 0}); l < min({(j) + 1, N}); ++l) {

int sp = j;
int kp = l;
for (int s = 0; s < N; ++s) {

for (int t = max({s, 0}); t < min({(k) + 1, N}); ++t) {

int ip = s;
int lp = t;
J[i][j][k][l][s][t] += J[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

int ip = i;
for (int j = 0; j < N; ++j) {

for (int l = 0; l < min({(j) + 1, N}); ++l) {

int sp = j;
for (int k = max({j, 0}); k < min({(i) + 1, N}); ++k) {

int lp = l;
int tp = k;
for (int s = 0; s < N; ++s) {

for (int t = max({s, 0}); t < min({(l) + 1, N}); ++t) {

int jp = s;
int kp = t;
J[i][j][k][l][s][t] += J[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

int kp = i;
for (int j = 0; j < min({(i) + 1, N}); ++j) {

for (int k = max({i, 0}); k < N; ++k) {

for (int l = 0; l < min({(j) + 1, N}); ++l) {

int sp = j;
int tp = k;
int lp = l;
for (int s = 0; s < N; ++s) {

for (int t = max({s, 0}); t < min({(l) + 1, N}); ++t) {

int jp = s;
int ip = t;
J[i][j][k][l][s][t] += J[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

int ip = i;
for (int j = 0; j < min({(i) + 1, N}); ++j) {

int sp = j;
for (int k = 0; k < min({(j) + 1, N}); ++k) {

for (int l = 0; l < min({(k) + 1, N}); ++l) {

int tp = k;
int lp = l;
for (int s = 0; s < N; ++s) {

for (int t = max({s, 0}); t < min({(l) + 1, N}); ++t) {

int kp = s;
int jp = t;
J[i][j][k][l][s][t] += J[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

int jp = i;
for (int j = max({i, 0}); j < N; ++j) {

for (int k = 0; k < min({(i) + 1, N}); ++k) {

int sp = j;
for (int l = 0; l < min({(k) + 1, N}); ++l) {

int tp = k;
int lp = l;
for (int s = 0; s < N; ++s) {

for (int t = max({s, 0}); t < min({(l) + 1, N}); ++t) {

int kp = s;
int ip = t;
J[i][j][k][l][s][t] += J[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int l = 0; l < min({(i) + 1, N}); ++l) {

int kp = i;
for (int j = max({i, 0}); j < N; ++j) {

int lp = l;
int sp = j;
for (int k = max({j, 0}); k < N; ++k) {

int tp = k;
for (int s = 0; s < N; ++s) {

for (int t = max({s, 0}); t < min({(l) + 1, N}); ++t) {

int ip = s;
int jp = t;
J[i][j][k][l][s][t] += J[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int l = 0; l < min({(i) + 1, N}); ++l) {

int jp = i;
int lp = l;
for (int j = 0; j < N; ++j) {

int sp = j;
for (int k = max({i, 0}); k < min({(j) + 1, N}); ++k) {

int tp = k;
for (int s = 0; s < N; ++s) {

for (int t = max({s, 0}); t < min({(l) + 1, N}); ++t) {

int ip = s;
int kp = t;
J[i][j][k][l][s][t] += J[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

int lp = i;
for (int j = max({i, 0}); j < N; ++j) {

int sp = j;
for (int k = max({j, 0}); k < N; ++k) {

for (int l = max({k, 0}); l < N; ++l) {

int tp = k;
int ip = l;
for (int s = 0; s < N; ++s) {

for (int t = max({s, 0}); t < min({(i) + 1, N}); ++t) {

int jp = s;
int kp = t;
J[i][j][k][l][s][t] += J[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

int kp = i;
for (int j = max({i, 0}); j < N; ++j) {

int sp = j;
for (int k = 0; k < N; ++k) {

for (int l = max({j, 0}); l < min({(k) + 1, N}); ++l) {

int tp = k;
int ip = l;
for (int s = 0; s < N; ++s) {

for (int t = max({s, 0}); t < min({(i) + 1, N}); ++t) {

int jp = s;
int lp = t;
J[i][j][k][l][s][t] += J[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

int lp = i;
for (int j = 0; j < N; ++j) {

for (int l = max({j, 0}); l < N; ++l) {

int sp = j;
for (int k = max({i, 0}); k < min({(j) + 1, N}); ++k) {

int ip = l;
int tp = k;
for (int s = 0; s < N; ++s) {

for (int t = max({s, 0}); t < min({(i) + 1, N}); ++t) {

int kp = s;
int jp = t;
J[i][j][k][l][s][t] += J[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

int jp = i;
for (int k = max({i, 0}); k < N; ++k) {

for (int j = 0; j < N; ++j) {

int tp = k;
for (int l = max({k, 0}); l < min({(j) + 1, N}); ++l) {

int sp = j;
int ip = l;
for (int s = 0; s < N; ++s) {

for (int t = max({s, 0}); t < min({(i) + 1, N}); ++t) {

int kp = s;
int lp = t;
J[i][j][k][l][s][t] += J[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

int kp = i;
for (int j = 0; j < N; ++j) {

for (int l = max({i, 0}); l < min({(j) + 1, N}); ++l) {

int sp = j;
for (int k = max({j, 0}); k < N; ++k) {

int ip = l;
int tp = k;
for (int s = 0; s < N; ++s) {

for (int t = max({s, 0}); t < min({(i) + 1, N}); ++t) {

int lp = s;
int jp = t;
J[i][j][k][l][s][t] += J[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

int jp = i;
for (int j = 0; j < N; ++j) {

int sp = j;
for (int k = 0; k < min({(j) + 1, N}); ++k) {

for (int l = max({i, 0}); l < min({(k) + 1, N}); ++l) {

int tp = k;
int ip = l;
for (int s = 0; s < N; ++s) {

for (int t = max({s, 0}); t < min({(i) + 1, N}); ++t) {

int lp = s;
int kp = t;
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

int tp = i;
int kp = s;
int sp = j;
for (int k = max({j, 0}); k < N; ++k) {

for (int l = max({k, 0}); l < N; ++l) {

int ip = k;
for (int t = max({l, 0}); t < N; ++t) {

int jp = l;
int lp = t;
J[i][j][k][l][s][t] += J[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int s = 0; s < min({(i) + 1, N}); ++s) {

int lp = i;
for (int j = max({i, 0}); j < N; ++j) {

int kp = s;
int sp = j;
for (int k = max({j, 0}); k < N; ++k) {

for (int l = 0; l < N; ++l) {

int ip = k;
for (int t = max({k, 0}); t < min({(l) + 1, N}); ++t) {

int jp = l;
int tp = t;
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

int tp = i;
int lp = s;
int sp = j;
for (int k = 0; k < N; ++k) {

for (int t = max({k, 0}); t < N; ++t) {

for (int l = max({j, 0}); l < min({(k) + 1, N}); ++l) {

int ip = k;
int kp = t;
int jp = l;
J[i][j][k][l][s][t] += J[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int s = 0; s < min({(i) + 1, N}); ++s) {

int kp = i;
for (int j = max({i, 0}); j < N; ++j) {

int lp = s;
for (int l = max({j, 0}); l < N; ++l) {

int sp = j;
int jp = l;
for (int k = 0; k < N; ++k) {

for (int t = max({l, 0}); t < min({(k) + 1, N}); ++t) {

int ip = k;
int tp = t;
J[i][j][k][l][s][t] += J[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int s = 0; s < min({(i) + 1, N}); ++s) {

int lp = i;
for (int j = max({i, 0}); j < N; ++j) {

int tp = s;
int sp = j;
for (int k = 0; k < N; ++k) {

for (int t = max({j, 0}); t < min({(k) + 1, N}); ++t) {

for (int l = max({k, 0}); l < N; ++l) {

int ip = k;
int kp = t;
int jp = l;
J[i][j][k][l][s][t] += J[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int s = 0; s < min({(i) + 1, N}); ++s) {

int kp = i;
for (int j = max({i, 0}); j < N; ++j) {

int tp = s;
int sp = j;
for (int k = 0; k < N; ++k) {

for (int l = 0; l < min({(k) + 1, N}); ++l) {

int ip = k;
for (int t = max({j, 0}); t < min({(l) + 1, N}); ++t) {

int jp = l;
int lp = t;
J[i][j][k][l][s][t] += J[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int s = 0; s < min({(i) + 1, N}); ++s) {

int tp = i;
int jp = s;
for (int j = 0; j < N; ++j) {

for (int l = max({j, 0}); l < N; ++l) {

int sp = j;
for (int k = max({i, 0}); k < min({(j) + 1, N}); ++k) {

for (int t = max({l, 0}); t < N; ++t) {

int kp = l;
int ip = k;
int lp = t;
J[i][j][k][l][s][t] += J[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int s = 0; s < min({(i) + 1, N}); ++s) {

int lp = i;
int jp = s;
for (int j = 0; j < N; ++j) {

int sp = j;
for (int k = max({i, 0}); k < min({(j) + 1, N}); ++k) {

for (int l = 0; l < N; ++l) {

int ip = k;
for (int t = max({j, 0}); t < min({(l) + 1, N}); ++t) {

int kp = l;
int tp = t;
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

int tp = i;
int lp = s;
int ip = k;
for (int j = 0; j < N; ++j) {

for (int t = max({j, 0}); t < N; ++t) {

for (int l = max({k, 0}); l < min({(j) + 1, N}); ++l) {

int sp = j;
int jp = t;
int kp = l;
J[i][j][k][l][s][t] += J[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int s = 0; s < min({(i) + 1, N}); ++s) {

int jp = i;
for (int k = max({i, 0}); k < N; ++k) {

int lp = s;
for (int l = max({k, 0}); l < N; ++l) {

int ip = k;
int kp = l;
for (int j = 0; j < N; ++j) {

for (int t = max({l, 0}); t < min({(j) + 1, N}); ++t) {

int sp = j;
int tp = t;
J[i][j][k][l][s][t] += J[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int s = 0; s < min({(i) + 1, N}); ++s) {

int lp = i;
for (int k = max({i, 0}); k < N; ++k) {

int tp = s;
int ip = k;
for (int j = 0; j < N; ++j) {

for (int t = max({k, 0}); t < min({(j) + 1, N}); ++t) {

for (int l = max({j, 0}); l < N; ++l) {

int sp = j;
int jp = t;
int kp = l;
J[i][j][k][l][s][t] += J[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int s = 0; s < min({(i) + 1, N}); ++s) {

int jp = i;
for (int k = max({i, 0}); k < N; ++k) {

int tp = s;
int ip = k;
for (int j = 0; j < N; ++j) {

for (int l = 0; l < min({(j) + 1, N}); ++l) {

int sp = j;
for (int t = max({k, 0}); t < min({(l) + 1, N}); ++t) {

int kp = l;
int lp = t;
J[i][j][k][l][s][t] += J[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int s = 0; s < min({(i) + 1, N}); ++s) {

int tp = i;
int jp = s;
for (int j = 0; j < N; ++j) {

for (int l = max({i, 0}); l < min({(j) + 1, N}); ++l) {

int sp = j;
for (int k = max({j, 0}); k < N; ++k) {

int lp = l;
for (int t = max({k, 0}); t < N; ++t) {

int ip = k;
int kp = t;
J[i][j][k][l][s][t] += J[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int s = 0; s < min({(i) + 1, N}); ++s) {

int kp = i;
int jp = s;
for (int j = 0; j < N; ++j) {

for (int l = max({i, 0}); l < min({(j) + 1, N}); ++l) {

int sp = j;
int lp = l;
for (int k = 0; k < N; ++k) {

for (int t = max({j, 0}); t < min({(k) + 1, N}); ++t) {

int ip = k;
int tp = t;
J[i][j][k][l][s][t] += J[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int s = 0; s < min({(i) + 1, N}); ++s) {

int tp = i;
int kp = s;
for (int j = 0; j < N; ++j) {

for (int t = max({j, 0}); t < N; ++t) {

int sp = j;
for (int k = 0; k < min({(j) + 1, N}); ++k) {

int jp = t;
for (int l = max({i, 0}); l < min({(k) + 1, N}); ++l) {

int ip = k;
int lp = l;
J[i][j][k][l][s][t] += J[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int s = 0; s < min({(i) + 1, N}); ++s) {

int jp = i;
int kp = s;
for (int j = 0; j < N; ++j) {

int sp = j;
for (int k = 0; k < N; ++k) {

for (int t = max({k, 0}); t < min({(j) + 1, N}); ++t) {

for (int l = max({i, 0}); l < min({(k) + 1, N}); ++l) {

int ip = k;
int tp = t;
int lp = l;
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

int kp = i;
int tp = s;
int lp = l;
for (int j = 0; j < N; ++j) {

for (int t = max({l, 0}); t < min({(j) + 1, N}); ++t) {

int sp = j;
for (int k = max({j, 0}); k < N; ++k) {

int jp = t;
int ip = k;
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

int jp = i;
int tp = s;
int lp = l;
for (int j = 0; j < N; ++j) {

int sp = j;
for (int k = 0; k < min({(j) + 1, N}); ++k) {

for (int t = max({l, 0}); t < min({(k) + 1, N}); ++t) {

int ip = k;
int kp = t;
J[i][j][k][l][s][t] += J[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int s = 0; s < min({(i) + 1, N}); ++s) {

int lp = i;
int jp = s;
for (int j = 0; j < N; ++j) {

for (int t = max({i, 0}); t < min({(j) + 1, N}); ++t) {

int sp = j;
for (int k = max({j, 0}); k < N; ++k) {

int kp = t;
for (int l = max({k, 0}); l < N; ++l) {

int ip = k;
int tp = l;
J[i][j][k][l][s][t] += J[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int s = 0; s < min({(i) + 1, N}); ++s) {

int kp = i;
int jp = s;
for (int j = 0; j < N; ++j) {

for (int t = max({i, 0}); t < min({(j) + 1, N}); ++t) {

int sp = j;
int lp = t;
for (int k = 0; k < N; ++k) {

for (int l = max({j, 0}); l < min({(k) + 1, N}); ++l) {

int ip = k;
int tp = l;
J[i][j][k][l][s][t] += J[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int s = 0; s < min({(i) + 1, N}); ++s) {

int lp = i;
int kp = s;
for (int j = 0; j < N; ++j) {

for (int l = max({j, 0}); l < N; ++l) {

int sp = j;
for (int k = 0; k < min({(j) + 1, N}); ++k) {

int tp = l;
for (int t = max({i, 0}); t < min({(k) + 1, N}); ++t) {

int ip = k;
int jp = t;
J[i][j][k][l][s][t] += J[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int s = 0; s < min({(i) + 1, N}); ++s) {

int jp = i;
int kp = s;
for (int j = 0; j < N; ++j) {

int sp = j;
for (int k = 0; k < N; ++k) {

for (int t = max({i, 0}); t < min({(k) + 1, N}); ++t) {

for (int l = max({k, 0}); l < min({(j) + 1, N}); ++l) {

int ip = k;
int lp = t;
int tp = l;
J[i][j][k][l][s][t] += J[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int s = 0; s < min({(i) + 1, N}); ++s) {

int kp = i;
int lp = s;
for (int j = 0; j < N; ++j) {

for (int l = 0; l < min({(j) + 1, N}); ++l) {

int sp = j;
for (int k = max({j, 0}); k < N; ++k) {

for (int t = max({i, 0}); t < min({(l) + 1, N}); ++t) {

int tp = l;
int ip = k;
int jp = t;
J[i][j][k][l][s][t] += J[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int s = 0; s < min({(i) + 1, N}); ++s) {

int jp = i;
int lp = s;
for (int j = 0; j < N; ++j) {

int sp = j;
for (int k = 0; k < min({(j) + 1, N}); ++k) {

for (int l = 0; l < min({(k) + 1, N}); ++l) {

int ip = k;
for (int t = max({i, 0}); t < min({(l) + 1, N}); ++t) {

int tp = l;
int kp = t;
J[i][j][k][l][s][t] += J[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

int ip = i;
for (int j = 0; j < N; ++j) {

for (int t = 0; t < min({(j) + 1, N}); ++t) {

for (int k = max({j, 0}); k < N; ++k) {

int tp = j;
int sp = t;
for (int l = max({k, 0}); l < N; ++l) {

int jp = k;
for (int s = max({l, 0}); s < min({(i) + 1, N}); ++s) {

int kp = l;
int lp = s;
J[i][j][k][l][s][t] += J[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int s = max({i, 0}); s < N; ++s) {

int sp = i;
int lp = s;
for (int j = 0; j < N; ++j) {

for (int t = 0; t < min({(j) + 1, N}); ++t) {

for (int k = max({j, 0}); k < N; ++k) {

int tp = j;
int ip = t;
for (int l = max({k, 0}); l < min({(i) + 1, N}); ++l) {

int jp = k;
int kp = l;
J[i][j][k][l][s][t] += J[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int l = 0; l < min({(i) + 1, N}); ++l) {

int ip = i;
int kp = l;
for (int j = 0; j < N; ++j) {

for (int t = 0; t < min({(j) + 1, N}); ++t) {

for (int k = max({j, 0}); k < N; ++k) {

int tp = j;
int lp = t;
for (int s = max({k, 0}); s < min({(l) + 1, N}); ++s) {

int jp = k;
int sp = s;
J[i][j][k][l][s][t] += J[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int l = max({i, 0}); l < N; ++l) {

int lp = i;
int kp = l;
for (int j = 0; j < N; ++j) {

for (int t = 0; t < min({(j) + 1, N}); ++t) {

for (int k = max({j, 0}); k < N; ++k) {

int tp = j;
int ip = t;
for (int s = max({k, 0}); s < min({(i) + 1, N}); ++s) {

int jp = k;
int sp = s;
J[i][j][k][l][s][t] += J[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int l = max({i, 0}); l < N; ++l) {

int sp = i;
for (int s = max({l, 0}); s < N; ++s) {

int kp = l;
int ip = s;
for (int j = 0; j < N; ++j) {

for (int t = 0; t < min({(j) + 1, N}); ++t) {

for (int k = max({j, 0}); k < min({(i) + 1, N}); ++k) {

int tp = j;
int lp = t;
int jp = k;
J[i][j][k][l][s][t] += J[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

int lp = i;
for (int j = 0; j < N; ++j) {

for (int t = 0; t < min({(j) + 1, N}); ++t) {

for (int k = max({j, 0}); k < min({(i) + 1, N}); ++k) {

int tp = j;
int sp = t;
int jp = k;
for (int l = 0; l < N; ++l) {

for (int s = max({i, 0}); s < min({(l) + 1, N}); ++s) {

int kp = l;
int ip = s;
J[i][j][k][l][s][t] += J[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

int ip = i;
for (int j = 0; j < N; ++j) {

for (int t = 0; t < min({(j) + 1, N}); ++t) {

int tp = j;
int sp = t;
for (int k = 0; k < N; ++k) {

for (int s = max({k, 0}); s < min({(i) + 1, N}); ++s) {

for (int l = max({j, 0}); l < min({(k) + 1, N}); ++l) {

int jp = k;
int kp = s;
int lp = l;
J[i][j][k][l][s][t] += J[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int s = max({i, 0}); s < N; ++s) {

int sp = i;
for (int k = 0; k < min({(i) + 1, N}); ++k) {

int kp = s;
int jp = k;
for (int j = 0; j < N; ++j) {

for (int t = 0; t < min({(j) + 1, N}); ++t) {

for (int l = max({j, 0}); l < min({(k) + 1, N}); ++l) {

int tp = j;
int ip = t;
int lp = l;
J[i][j][k][l][s][t] += J[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

int ip = i;
for (int k = 0; k < min({(i) + 1, N}); ++k) {

int jp = k;
for (int j = 0; j < N; ++j) {

for (int t = 0; t < min({(j) + 1, N}); ++t) {

for (int l = max({j, 0}); l < N; ++l) {

int tp = j;
int kp = t;
for (int s = max({l, 0}); s < min({(k) + 1, N}); ++s) {

int lp = l;
int sp = s;
J[i][j][k][l][s][t] += J[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

int kp = i;
for (int k = max({i, 0}); k < N; ++k) {

int jp = k;
for (int j = 0; j < N; ++j) {

for (int t = 0; t < min({(j) + 1, N}); ++t) {

for (int l = max({j, 0}); l < N; ++l) {

int tp = j;
int ip = t;
for (int s = max({l, 0}); s < min({(i) + 1, N}); ++s) {

int lp = l;
int sp = s;
J[i][j][k][l][s][t] += J[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

int sp = i;
for (int k = max({i, 0}); k < N; ++k) {

for (int s = max({k, 0}); s < N; ++s) {

int jp = k;
int ip = s;
for (int j = 0; j < N; ++j) {

for (int t = 0; t < min({(j) + 1, N}); ++t) {

for (int l = max({j, 0}); l < min({(i) + 1, N}); ++l) {

int tp = j;
int kp = t;
int lp = l;
J[i][j][k][l][s][t] += J[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

int kp = i;
for (int j = 0; j < N; ++j) {

for (int t = 0; t < min({(j) + 1, N}); ++t) {

for (int l = max({j, 0}); l < min({(i) + 1, N}); ++l) {

int tp = j;
int sp = t;
int lp = l;
for (int k = 0; k < N; ++k) {

for (int s = max({i, 0}); s < min({(k) + 1, N}); ++s) {

int jp = k;
int ip = s;
J[i][j][k][l][s][t] += J[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

int ip = i;
for (int j = 0; j < N; ++j) {

for (int t = 0; t < min({(j) + 1, N}); ++t) {

int tp = j;
int lp = t;
for (int k = 0; k < N; ++k) {

for (int s = max({j, 0}); s < min({(k) + 1, N}); ++s) {

for (int l = max({k, 0}); l < min({(i) + 1, N}); ++l) {

int jp = k;
int kp = s;
int sp = l;
J[i][j][k][l][s][t] += J[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int l = max({i, 0}); l < N; ++l) {

int lp = i;
for (int k = 0; k < min({(i) + 1, N}); ++k) {

int sp = l;
int jp = k;
for (int j = 0; j < N; ++j) {

for (int s = max({j, 0}); s < min({(k) + 1, N}); ++s) {

for (int t = 0; t < min({(j) + 1, N}); ++t) {

int tp = j;
int kp = s;
int ip = t;
J[i][j][k][l][s][t] += J[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

int ip = i;
for (int k = 0; k < min({(i) + 1, N}); ++k) {

for (int l = 0; l < min({(k) + 1, N}); ++l) {

int jp = k;
int sp = l;
for (int j = 0; j < N; ++j) {

for (int s = max({j, 0}); s < min({(l) + 1, N}); ++s) {

for (int t = 0; t < min({(j) + 1, N}); ++t) {

int tp = j;
int lp = s;
int kp = t;
J[i][j][k][l][s][t] += J[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int l = 0; l < min({(i) + 1, N}); ++l) {

int kp = i;
for (int k = max({i, 0}); k < N; ++k) {

int sp = l;
int jp = k;
for (int j = 0; j < N; ++j) {

for (int s = max({j, 0}); s < min({(l) + 1, N}); ++s) {

for (int t = 0; t < min({(j) + 1, N}); ++t) {

int tp = j;
int lp = s;
int ip = t;
J[i][j][k][l][s][t] += J[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

int lp = i;
for (int k = max({i, 0}); k < N; ++k) {

for (int l = max({k, 0}); l < N; ++l) {

int jp = k;
int sp = l;
for (int j = 0; j < N; ++j) {

for (int s = max({j, 0}); s < min({(i) + 1, N}); ++s) {

for (int t = 0; t < min({(j) + 1, N}); ++t) {

int tp = j;
int ip = s;
int kp = t;
J[i][j][k][l][s][t] += J[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

int kp = i;
for (int j = 0; j < N; ++j) {

for (int s = max({j, 0}); s < min({(i) + 1, N}); ++s) {

for (int t = 0; t < min({(j) + 1, N}); ++t) {

int tp = j;
int ip = s;
int lp = t;
for (int k = 0; k < N; ++k) {

for (int l = max({i, 0}); l < min({(k) + 1, N}); ++l) {

int jp = k;
int sp = l;
J[i][j][k][l][s][t] += J[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

int sp = i;
for (int j = 0; j < min({(i) + 1, N}); ++j) {

for (int k = max({i, 0}); k < N; ++k) {

for (int t = 0; t < min({(j) + 1, N}); ++t) {

int tp = j;
for (int l = max({k, 0}); l < N; ++l) {

int jp = k;
int lp = t;
for (int s = max({l, 0}); s < N; ++s) {

int ip = l;
int kp = s;
J[i][j][k][l][s][t] += J[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

int lp = i;
for (int j = 0; j < min({(i) + 1, N}); ++j) {

for (int k = max({i, 0}); k < N; ++k) {

for (int t = 0; t < min({(j) + 1, N}); ++t) {

int tp = j;
int jp = k;
int sp = t;
for (int l = 0; l < N; ++l) {

for (int s = max({k, 0}); s < min({(l) + 1, N}); ++s) {

int ip = l;
int kp = s;
J[i][j][k][l][s][t] += J[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

int sp = i;
for (int j = 0; j < min({(i) + 1, N}); ++j) {

for (int t = 0; t < min({(j) + 1, N}); ++t) {

int tp = j;
int kp = t;
for (int k = 0; k < N; ++k) {

for (int s = max({k, 0}); s < N; ++s) {

for (int l = max({i, 0}); l < min({(k) + 1, N}); ++l) {

int jp = k;
int lp = s;
int ip = l;
J[i][j][k][l][s][t] += J[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int l = max({i, 0}); l < N; ++l) {

int kp = i;
for (int j = 0; j < min({(i) + 1, N}); ++j) {

int ip = l;
for (int t = 0; t < min({(j) + 1, N}); ++t) {

int tp = j;
int sp = t;
for (int k = 0; k < N; ++k) {

for (int s = max({l, 0}); s < min({(k) + 1, N}); ++s) {

int jp = k;
int lp = s;
J[i][j][k][l][s][t] += J[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

int lp = i;
for (int j = 0; j < min({(i) + 1, N}); ++j) {

for (int t = 0; t < min({(j) + 1, N}); ++t) {

int tp = j;
int kp = t;
for (int k = 0; k < N; ++k) {

for (int s = max({i, 0}); s < min({(k) + 1, N}); ++s) {

for (int l = max({k, 0}); l < N; ++l) {

int jp = k;
int sp = s;
int ip = l;
J[i][j][k][l][s][t] += J[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

int kp = i;
for (int j = 0; j < min({(i) + 1, N}); ++j) {

for (int t = 0; t < min({(j) + 1, N}); ++t) {

int tp = j;
int lp = t;
for (int k = 0; k < N; ++k) {

for (int l = 0; l < min({(k) + 1, N}); ++l) {

int jp = k;
for (int s = max({i, 0}); s < min({(l) + 1, N}); ++s) {

int ip = l;
int sp = s;
J[i][j][k][l][s][t] += J[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

int ip = i;
for (int j = 0; j < N; ++j) {

for (int l = max({j, 0}); l < N; ++l) {

for (int k = 0; k < min({(j) + 1, N}); ++k) {

int tp = j;
for (int s = max({l, 0}); s < min({(i) + 1, N}); ++s) {

int jp = l;
for (int t = 0; t < min({(k) + 1, N}); ++t) {

int kp = k;
int lp = s;
int sp = t;
J[i][j][k][l][s][t] += J[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int s = max({i, 0}); s < N; ++s) {

int sp = i;
int lp = s;
for (int j = 0; j < N; ++j) {

for (int l = max({j, 0}); l < min({(i) + 1, N}); ++l) {

for (int k = 0; k < min({(j) + 1, N}); ++k) {

int tp = j;
int jp = l;
for (int t = 0; t < min({(k) + 1, N}); ++t) {

int kp = k;
int ip = t;
J[i][j][k][l][s][t] += J[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int l = 0; l < min({(i) + 1, N}); ++l) {

int ip = i;
int jp = l;
for (int j = 0; j < N; ++j) {

for (int s = max({j, 0}); s < min({(l) + 1, N}); ++s) {

for (int k = 0; k < min({(j) + 1, N}); ++k) {

int tp = j;
int sp = s;
for (int t = 0; t < min({(k) + 1, N}); ++t) {

int kp = k;
int lp = t;
J[i][j][k][l][s][t] += J[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int l = max({i, 0}); l < N; ++l) {

int lp = i;
int jp = l;
for (int j = 0; j < N; ++j) {

for (int s = max({j, 0}); s < min({(i) + 1, N}); ++s) {

for (int k = 0; k < min({(j) + 1, N}); ++k) {

int tp = j;
int sp = s;
for (int t = 0; t < min({(k) + 1, N}); ++t) {

int kp = k;
int ip = t;
J[i][j][k][l][s][t] += J[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int l = max({i, 0}); l < N; ++l) {

int sp = i;
for (int j = 0; j < min({(i) + 1, N}); ++j) {

for (int s = max({l, 0}); s < N; ++s) {

int jp = l;
for (int k = 0; k < min({(j) + 1, N}); ++k) {

int tp = j;
int ip = s;
for (int t = 0; t < min({(k) + 1, N}); ++t) {

int kp = k;
int lp = t;
J[i][j][k][l][s][t] += J[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

int lp = i;
for (int j = 0; j < min({(i) + 1, N}); ++j) {

for (int k = 0; k < min({(j) + 1, N}); ++k) {

int tp = j;
for (int t = 0; t < min({(k) + 1, N}); ++t) {

int kp = k;
int sp = t;
for (int l = 0; l < N; ++l) {

for (int s = max({i, 0}); s < min({(l) + 1, N}); ++s) {

int jp = l;
int ip = s;
J[i][j][k][l][s][t] += J[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

int ip = i;
for (int j = 0; j < N; ++j) {

for (int s = max({j, 0}); s < min({(i) + 1, N}); ++s) {

int tp = j;
int jp = s;
for (int k = 0; k < N; ++k) {

for (int t = 0; t < min({(k) + 1, N}); ++t) {

for (int l = max({k, 0}); l < min({(j) + 1, N}); ++l) {

int kp = k;
int sp = t;
int lp = l;
J[i][j][k][l][s][t] += J[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int s = max({i, 0}); s < N; ++s) {

int sp = i;
for (int j = 0; j < min({(i) + 1, N}); ++j) {

int jp = s;
int tp = j;
for (int k = 0; k < N; ++k) {

for (int t = 0; t < min({(k) + 1, N}); ++t) {

for (int l = max({k, 0}); l < min({(j) + 1, N}); ++l) {

int kp = k;
int ip = t;
int lp = l;
J[i][j][k][l][s][t] += J[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

int ip = i;
for (int j = 0; j < min({(i) + 1, N}); ++j) {

for (int k = 0; k < N; ++k) {

int tp = j;
for (int t = 0; t < min({(k) + 1, N}); ++t) {

for (int l = max({k, 0}); l < N; ++l) {

int kp = k;
int jp = t;
for (int s = max({l, 0}); s < min({(j) + 1, N}); ++s) {

int lp = l;
int sp = s;
J[i][j][k][l][s][t] += J[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

int jp = i;
for (int j = max({i, 0}); j < N; ++j) {

for (int k = 0; k < N; ++k) {

int tp = j;
for (int t = 0; t < min({(k) + 1, N}); ++t) {

for (int l = max({k, 0}); l < N; ++l) {

int kp = k;
int ip = t;
for (int s = max({l, 0}); s < min({(i) + 1, N}); ++s) {

int lp = l;
int sp = s;
J[i][j][k][l][s][t] += J[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

int sp = i;
for (int j = max({i, 0}); j < N; ++j) {

for (int s = max({j, 0}); s < N; ++s) {

int tp = j;
int ip = s;
for (int k = 0; k < N; ++k) {

for (int t = 0; t < min({(k) + 1, N}); ++t) {

for (int l = max({k, 0}); l < min({(i) + 1, N}); ++l) {

int kp = k;
int jp = t;
int lp = l;
J[i][j][k][l][s][t] += J[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

int jp = i;
for (int j = 0; j < N; ++j) {

for (int s = max({i, 0}); s < min({(j) + 1, N}); ++s) {

int tp = j;
int ip = s;
for (int k = 0; k < N; ++k) {

for (int t = 0; t < min({(k) + 1, N}); ++t) {

for (int l = max({k, 0}); l < min({(i) + 1, N}); ++l) {

int kp = k;
int sp = t;
int lp = l;
J[i][j][k][l][s][t] += J[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

int ip = i;
for (int j = 0; j < N; ++j) {

for (int l = max({j, 0}); l < min({(i) + 1, N}); ++l) {

int tp = j;
int sp = l;
for (int k = 0; k < N; ++k) {

for (int s = max({k, 0}); s < min({(j) + 1, N}); ++s) {

for (int t = 0; t < min({(k) + 1, N}); ++t) {

int kp = k;
int jp = s;
int lp = t;
J[i][j][k][l][s][t] += J[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int l = max({i, 0}); l < N; ++l) {

int lp = i;
for (int j = 0; j < min({(i) + 1, N}); ++j) {

int sp = l;
int tp = j;
for (int k = 0; k < N; ++k) {

for (int s = max({k, 0}); s < min({(j) + 1, N}); ++s) {

for (int t = 0; t < min({(k) + 1, N}); ++t) {

int kp = k;
int jp = s;
int ip = t;
J[i][j][k][l][s][t] += J[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

int ip = i;
for (int j = 0; j < min({(i) + 1, N}); ++j) {

for (int l = 0; l < min({(j) + 1, N}); ++l) {

int tp = j;
int sp = l;
for (int k = 0; k < N; ++k) {

for (int s = max({k, 0}); s < min({(l) + 1, N}); ++s) {

for (int t = 0; t < min({(k) + 1, N}); ++t) {

int kp = k;
int lp = s;
int jp = t;
J[i][j][k][l][s][t] += J[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int l = 0; l < min({(i) + 1, N}); ++l) {

int jp = i;
for (int j = max({i, 0}); j < N; ++j) {

int sp = l;
int tp = j;
for (int k = 0; k < N; ++k) {

for (int s = max({k, 0}); s < min({(l) + 1, N}); ++s) {

for (int t = 0; t < min({(k) + 1, N}); ++t) {

int kp = k;
int lp = s;
int ip = t;
J[i][j][k][l][s][t] += J[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

int lp = i;
for (int j = max({i, 0}); j < N; ++j) {

for (int l = max({j, 0}); l < N; ++l) {

int tp = j;
int sp = l;
for (int k = 0; k < N; ++k) {

for (int s = max({k, 0}); s < min({(i) + 1, N}); ++s) {

for (int t = 0; t < min({(k) + 1, N}); ++t) {

int kp = k;
int ip = s;
int jp = t;
J[i][j][k][l][s][t] += J[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

int jp = i;
for (int j = 0; j < N; ++j) {

for (int l = max({i, 0}); l < min({(j) + 1, N}); ++l) {

int tp = j;
int sp = l;
for (int k = 0; k < N; ++k) {

for (int s = max({k, 0}); s < min({(i) + 1, N}); ++s) {

for (int t = 0; t < min({(k) + 1, N}); ++t) {

int kp = k;
int ip = s;
int lp = t;
J[i][j][k][l][s][t] += J[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

int sp = i;
for (int j = max({i, 0}); j < N; ++j) {

for (int k = 0; k < min({(i) + 1, N}); ++k) {

for (int l = max({j, 0}); l < N; ++l) {

int tp = j;
for (int t = 0; t < min({(k) + 1, N}); ++t) {

int kp = k;
for (int s = max({l, 0}); s < N; ++s) {

int ip = l;
int lp = t;
int jp = s;
J[i][j][k][l][s][t] += J[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

int lp = i;
for (int j = max({i, 0}); j < N; ++j) {

for (int k = 0; k < min({(i) + 1, N}); ++k) {

int tp = j;
for (int t = 0; t < min({(k) + 1, N}); ++t) {

int kp = k;
int sp = t;
for (int l = 0; l < N; ++l) {

for (int s = max({j, 0}); s < min({(l) + 1, N}); ++s) {

int ip = l;
int jp = s;
J[i][j][k][l][s][t] += J[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

int sp = i;
for (int k = 0; k < min({(i) + 1, N}); ++k) {

for (int t = 0; t < min({(k) + 1, N}); ++t) {

int kp = k;
int jp = t;
for (int j = 0; j < N; ++j) {

for (int s = max({j, 0}); s < N; ++s) {

for (int l = max({i, 0}); l < min({(j) + 1, N}); ++l) {

int tp = j;
int lp = s;
int ip = l;
J[i][j][k][l][s][t] += J[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int l = max({i, 0}); l < N; ++l) {

int jp = i;
for (int k = 0; k < min({(i) + 1, N}); ++k) {

int ip = l;
for (int t = 0; t < min({(k) + 1, N}); ++t) {

int kp = k;
int sp = t;
for (int j = 0; j < N; ++j) {

for (int s = max({l, 0}); s < min({(j) + 1, N}); ++s) {

int tp = j;
int lp = s;
J[i][j][k][l][s][t] += J[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

int lp = i;
for (int k = 0; k < min({(i) + 1, N}); ++k) {

for (int t = 0; t < min({(k) + 1, N}); ++t) {

int kp = k;
int jp = t;
for (int j = 0; j < N; ++j) {

for (int s = max({i, 0}); s < min({(j) + 1, N}); ++s) {

for (int l = max({j, 0}); l < N; ++l) {

int tp = j;
int sp = s;
int ip = l;
J[i][j][k][l][s][t] += J[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

int jp = i;
for (int k = 0; k < min({(i) + 1, N}); ++k) {

for (int t = 0; t < min({(k) + 1, N}); ++t) {

int kp = k;
int lp = t;
for (int j = 0; j < N; ++j) {

for (int l = 0; l < min({(j) + 1, N}); ++l) {

int tp = j;
for (int s = max({i, 0}); s < min({(l) + 1, N}); ++s) {

int ip = l;
int sp = s;
J[i][j][k][l][s][t] += J[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

int ip = i;
for (int j = 0; j < N; ++j) {

for (int l = 0; l < min({(j) + 1, N}); ++l) {

for (int k = max({j, 0}); k < N; ++k) {

int tp = j;
for (int t = 0; t < min({(l) + 1, N}); ++t) {

int jp = l;
for (int s = max({k, 0}); s < min({(i) + 1, N}); ++s) {

int lp = k;
int sp = t;
int kp = s;
J[i][j][k][l][s][t] += J[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int s = max({i, 0}); s < N; ++s) {

int sp = i;
int kp = s;
for (int j = 0; j < N; ++j) {

for (int l = 0; l < min({(j) + 1, N}); ++l) {

for (int k = max({j, 0}); k < min({(i) + 1, N}); ++k) {

int tp = j;
for (int t = 0; t < min({(l) + 1, N}); ++t) {

int jp = l;
int lp = k;
int ip = t;
J[i][j][k][l][s][t] += J[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

int ip = i;
for (int k = 0; k < min({(i) + 1, N}); ++k) {

int lp = k;
for (int j = 0; j < N; ++j) {

for (int s = max({j, 0}); s < min({(k) + 1, N}); ++s) {

for (int l = 0; l < min({(j) + 1, N}); ++l) {

int tp = j;
int sp = s;
for (int t = 0; t < min({(l) + 1, N}); ++t) {

int jp = l;
int kp = t;
J[i][j][k][l][s][t] += J[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

int kp = i;
for (int k = max({i, 0}); k < N; ++k) {

int lp = k;
for (int j = 0; j < N; ++j) {

for (int s = max({j, 0}); s < min({(i) + 1, N}); ++s) {

for (int l = 0; l < min({(j) + 1, N}); ++l) {

int tp = j;
int sp = s;
for (int t = 0; t < min({(l) + 1, N}); ++t) {

int jp = l;
int ip = t;
J[i][j][k][l][s][t] += J[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

int sp = i;
for (int j = 0; j < min({(i) + 1, N}); ++j) {

for (int k = max({i, 0}); k < N; ++k) {

for (int l = 0; l < min({(j) + 1, N}); ++l) {

int tp = j;
for (int s = max({k, 0}); s < N; ++s) {

int lp = k;
for (int t = 0; t < min({(l) + 1, N}); ++t) {

int jp = l;
int ip = s;
int kp = t;
J[i][j][k][l][s][t] += J[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

int kp = i;
for (int j = 0; j < min({(i) + 1, N}); ++j) {

for (int l = 0; l < min({(j) + 1, N}); ++l) {

int tp = j;
for (int t = 0; t < min({(l) + 1, N}); ++t) {

int jp = l;
int sp = t;
for (int k = 0; k < N; ++k) {

for (int s = max({i, 0}); s < min({(k) + 1, N}); ++s) {

int lp = k;
int ip = s;
J[i][j][k][l][s][t] += J[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

int ip = i;
for (int j = 0; j < N; ++j) {

for (int s = max({j, 0}); s < min({(i) + 1, N}); ++s) {

for (int k = 0; k < min({(j) + 1, N}); ++k) {

int tp = j;
int jp = s;
for (int l = 0; l < min({(k) + 1, N}); ++l) {

int lp = k;
for (int t = 0; t < min({(l) + 1, N}); ++t) {

int kp = l;
int sp = t;
J[i][j][k][l][s][t] += J[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int s = max({i, 0}); s < N; ++s) {

int sp = i;
for (int j = 0; j < min({(i) + 1, N}); ++j) {

int jp = s;
for (int k = 0; k < min({(j) + 1, N}); ++k) {

int tp = j;
for (int l = 0; l < min({(k) + 1, N}); ++l) {

int lp = k;
for (int t = 0; t < min({(l) + 1, N}); ++t) {

int kp = l;
int ip = t;
J[i][j][k][l][s][t] += J[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

int ip = i;
for (int j = 0; j < min({(i) + 1, N}); ++j) {

for (int k = 0; k < N; ++k) {

int tp = j;
for (int s = max({k, 0}); s < min({(j) + 1, N}); ++s) {

for (int l = 0; l < min({(k) + 1, N}); ++l) {

int lp = k;
int sp = s;
for (int t = 0; t < min({(l) + 1, N}); ++t) {

int kp = l;
int jp = t;
J[i][j][k][l][s][t] += J[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

int jp = i;
for (int j = max({i, 0}); j < N; ++j) {

for (int k = 0; k < N; ++k) {

int tp = j;
for (int s = max({k, 0}); s < min({(i) + 1, N}); ++s) {

for (int l = 0; l < min({(k) + 1, N}); ++l) {

int lp = k;
int sp = s;
for (int t = 0; t < min({(l) + 1, N}); ++t) {

int kp = l;
int ip = t;
J[i][j][k][l][s][t] += J[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

int sp = i;
for (int j = max({i, 0}); j < N; ++j) {

for (int k = 0; k < min({(i) + 1, N}); ++k) {

for (int s = max({j, 0}); s < N; ++s) {

int tp = j;
for (int l = 0; l < min({(k) + 1, N}); ++l) {

int lp = k;
int ip = s;
for (int t = 0; t < min({(l) + 1, N}); ++t) {

int kp = l;
int jp = t;
J[i][j][k][l][s][t] += J[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

int jp = i;
for (int k = 0; k < min({(i) + 1, N}); ++k) {

for (int l = 0; l < min({(k) + 1, N}); ++l) {

int lp = k;
for (int t = 0; t < min({(l) + 1, N}); ++t) {

int kp = l;
int sp = t;
for (int j = 0; j < N; ++j) {

for (int s = max({i, 0}); s < min({(j) + 1, N}); ++s) {

int tp = j;
int ip = s;
J[i][j][k][l][s][t] += J[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

int ip = i;
for (int j = 0; j < N; ++j) {

for (int k = max({j, 0}); k < min({(i) + 1, N}); ++k) {

int tp = j;
int lp = k;
for (int l = 0; l < N; ++l) {

for (int s = max({l, 0}); s < min({(j) + 1, N}); ++s) {

for (int t = 0; t < min({(l) + 1, N}); ++t) {

int sp = l;
int jp = s;
int kp = t;
J[i][j][k][l][s][t] += J[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

int kp = i;
for (int j = 0; j < min({(i) + 1, N}); ++j) {

for (int k = max({i, 0}); k < N; ++k) {

int tp = j;
int lp = k;
for (int l = 0; l < N; ++l) {

for (int s = max({l, 0}); s < min({(j) + 1, N}); ++s) {

for (int t = 0; t < min({(l) + 1, N}); ++t) {

int sp = l;
int jp = s;
int ip = t;
J[i][j][k][l][s][t] += J[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

int ip = i;
for (int j = 0; j < min({(i) + 1, N}); ++j) {

for (int k = 0; k < min({(j) + 1, N}); ++k) {

int tp = j;
int lp = k;
for (int l = 0; l < N; ++l) {

for (int s = max({l, 0}); s < min({(k) + 1, N}); ++s) {

for (int t = 0; t < min({(l) + 1, N}); ++t) {

int sp = l;
int kp = s;
int jp = t;
J[i][j][k][l][s][t] += J[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

int jp = i;
for (int j = max({i, 0}); j < N; ++j) {

for (int k = 0; k < min({(i) + 1, N}); ++k) {

int tp = j;
int lp = k;
for (int l = 0; l < N; ++l) {

for (int s = max({l, 0}); s < min({(k) + 1, N}); ++s) {

for (int t = 0; t < min({(l) + 1, N}); ++t) {

int sp = l;
int kp = s;
int ip = t;
J[i][j][k][l][s][t] += J[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

int kp = i;
for (int j = max({i, 0}); j < N; ++j) {

for (int k = max({j, 0}); k < N; ++k) {

int tp = j;
int lp = k;
for (int l = 0; l < N; ++l) {

for (int s = max({l, 0}); s < min({(i) + 1, N}); ++s) {

for (int t = 0; t < min({(l) + 1, N}); ++t) {

int sp = l;
int ip = s;
int jp = t;
J[i][j][k][l][s][t] += J[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

int jp = i;
for (int j = 0; j < N; ++j) {

for (int k = max({i, 0}); k < min({(j) + 1, N}); ++k) {

int tp = j;
int lp = k;
for (int l = 0; l < N; ++l) {

for (int s = max({l, 0}); s < min({(i) + 1, N}); ++s) {

for (int t = 0; t < min({(l) + 1, N}); ++t) {

int sp = l;
int ip = s;
int kp = t;
J[i][j][k][l][s][t] += J[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int l = 0; l < min({(i) + 1, N}); ++l) {

int sp = i;
for (int j = max({i, 0}); j < N; ++j) {

for (int t = 0; t < min({(l) + 1, N}); ++t) {

int ip = l;
for (int k = max({j, 0}); k < N; ++k) {

int tp = j;
int kp = t;
for (int s = max({k, 0}); s < N; ++s) {

int lp = k;
int jp = s;
J[i][j][k][l][s][t] += J[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int l = 0; l < min({(i) + 1, N}); ++l) {

int kp = i;
for (int j = max({i, 0}); j < N; ++j) {

for (int t = 0; t < min({(l) + 1, N}); ++t) {

int ip = l;
int tp = j;
int sp = t;
for (int k = 0; k < N; ++k) {

for (int s = max({j, 0}); s < min({(k) + 1, N}); ++s) {

int lp = k;
int jp = s;
J[i][j][k][l][s][t] += J[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int l = 0; l < min({(i) + 1, N}); ++l) {

int sp = i;
for (int t = 0; t < min({(l) + 1, N}); ++t) {

int ip = l;
int jp = t;
for (int j = 0; j < N; ++j) {

for (int s = max({j, 0}); s < N; ++s) {

for (int k = max({i, 0}); k < min({(j) + 1, N}); ++k) {

int tp = j;
int kp = s;
int lp = k;
J[i][j][k][l][s][t] += J[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int l = 0; l < min({(i) + 1, N}); ++l) {

int jp = i;
for (int k = max({i, 0}); k < N; ++k) {

for (int t = 0; t < min({(l) + 1, N}); ++t) {

int ip = l;
int lp = k;
int sp = t;
for (int j = 0; j < N; ++j) {

for (int s = max({k, 0}); s < min({(j) + 1, N}); ++s) {

int tp = j;
int kp = s;
J[i][j][k][l][s][t] += J[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int l = 0; l < min({(i) + 1, N}); ++l) {

int kp = i;
for (int t = 0; t < min({(l) + 1, N}); ++t) {

int ip = l;
int jp = t;
for (int j = 0; j < N; ++j) {

for (int s = max({i, 0}); s < min({(j) + 1, N}); ++s) {

for (int k = max({j, 0}); k < N; ++k) {

int tp = j;
int sp = s;
int lp = k;
J[i][j][k][l][s][t] += J[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int l = 0; l < min({(i) + 1, N}); ++l) {

int jp = i;
for (int t = 0; t < min({(l) + 1, N}); ++t) {

int ip = l;
int kp = t;
for (int j = 0; j < N; ++j) {

for (int k = 0; k < min({(j) + 1, N}); ++k) {

int tp = j;
for (int s = max({i, 0}); s < min({(k) + 1, N}); ++s) {

int lp = k;
int sp = s;
J[i][j][k][l][s][t] += J[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

int ip = i;
for (int j = 0; j < N; ++j) {

for (int s = 0; s < min({(j) + 1, N}); ++s) {

for (int k = max({j, 0}); k < N; ++k) {

int tp = j;
for (int t = 0; t < min({(s) + 1, N}); ++t) {

int kp = s;
for (int l = max({k, 0}); l < min({(i) + 1, N}); ++l) {

int sp = k;
int lp = t;
int jp = l;
J[i][j][k][l][s][t] += J[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int l = max({i, 0}); l < N; ++l) {

int lp = i;
int jp = l;
for (int j = 0; j < N; ++j) {

for (int s = 0; s < min({(j) + 1, N}); ++s) {

for (int k = max({j, 0}); k < min({(i) + 1, N}); ++k) {

int tp = j;
for (int t = 0; t < min({(s) + 1, N}); ++t) {

int kp = s;
int sp = k;
int ip = t;
J[i][j][k][l][s][t] += J[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

int ip = i;
for (int k = 0; k < min({(i) + 1, N}); ++k) {

int sp = k;
for (int j = 0; j < N; ++j) {

for (int s = 0; s < min({(j) + 1, N}); ++s) {

for (int l = max({j, 0}); l < min({(k) + 1, N}); ++l) {

int tp = j;
for (int t = 0; t < min({(s) + 1, N}); ++t) {

int lp = s;
int jp = l;
int kp = t;
J[i][j][k][l][s][t] += J[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

int kp = i;
for (int k = max({i, 0}); k < N; ++k) {

int sp = k;
for (int j = 0; j < N; ++j) {

for (int s = 0; s < min({(j) + 1, N}); ++s) {

for (int l = max({j, 0}); l < min({(i) + 1, N}); ++l) {

int tp = j;
for (int t = 0; t < min({(s) + 1, N}); ++t) {

int lp = s;
int jp = l;
int ip = t;
J[i][j][k][l][s][t] += J[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

int lp = i;
for (int j = 0; j < min({(i) + 1, N}); ++j) {

for (int k = max({i, 0}); k < N; ++k) {

for (int s = 0; s < min({(j) + 1, N}); ++s) {

int tp = j;
for (int l = max({k, 0}); l < N; ++l) {

int sp = k;
for (int t = 0; t < min({(s) + 1, N}); ++t) {

int ip = s;
int jp = l;
int kp = t;
J[i][j][k][l][s][t] += J[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

int kp = i;
for (int j = 0; j < min({(i) + 1, N}); ++j) {

for (int s = 0; s < min({(j) + 1, N}); ++s) {

int tp = j;
for (int t = 0; t < min({(s) + 1, N}); ++t) {

int ip = s;
int lp = t;
for (int k = 0; k < N; ++k) {

for (int l = max({i, 0}); l < min({(k) + 1, N}); ++l) {

int sp = k;
int jp = l;
J[i][j][k][l][s][t] += J[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

int ip = i;
for (int j = 0; j < N; ++j) {

for (int l = max({j, 0}); l < min({(i) + 1, N}); ++l) {

for (int k = 0; k < min({(j) + 1, N}); ++k) {

int tp = j;
int kp = l;
for (int s = 0; s < min({(k) + 1, N}); ++s) {

int sp = k;
for (int t = 0; t < min({(s) + 1, N}); ++t) {

int jp = s;
int lp = t;
J[i][j][k][l][s][t] += J[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int l = max({i, 0}); l < N; ++l) {

int lp = i;
for (int j = 0; j < min({(i) + 1, N}); ++j) {

int kp = l;
for (int k = 0; k < min({(j) + 1, N}); ++k) {

int tp = j;
for (int s = 0; s < min({(k) + 1, N}); ++s) {

int sp = k;
for (int t = 0; t < min({(s) + 1, N}); ++t) {

int jp = s;
int ip = t;
J[i][j][k][l][s][t] += J[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

int ip = i;
for (int j = 0; j < min({(i) + 1, N}); ++j) {

for (int k = 0; k < N; ++k) {

int tp = j;
for (int s = 0; s < min({(k) + 1, N}); ++s) {

for (int l = max({k, 0}); l < min({(j) + 1, N}); ++l) {

int sp = k;
for (int t = 0; t < min({(s) + 1, N}); ++t) {

int lp = s;
int kp = l;
int jp = t;
J[i][j][k][l][s][t] += J[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

int jp = i;
for (int j = max({i, 0}); j < N; ++j) {

for (int k = 0; k < N; ++k) {

int tp = j;
for (int s = 0; s < min({(k) + 1, N}); ++s) {

for (int l = max({k, 0}); l < min({(i) + 1, N}); ++l) {

int sp = k;
for (int t = 0; t < min({(s) + 1, N}); ++t) {

int lp = s;
int kp = l;
int ip = t;
J[i][j][k][l][s][t] += J[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

int lp = i;
for (int j = max({i, 0}); j < N; ++j) {

for (int k = 0; k < min({(i) + 1, N}); ++k) {

for (int l = max({j, 0}); l < N; ++l) {

int tp = j;
for (int s = 0; s < min({(k) + 1, N}); ++s) {

int sp = k;
int kp = l;
for (int t = 0; t < min({(s) + 1, N}); ++t) {

int ip = s;
int jp = t;
J[i][j][k][l][s][t] += J[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

int jp = i;
for (int k = 0; k < min({(i) + 1, N}); ++k) {

for (int s = 0; s < min({(k) + 1, N}); ++s) {

int sp = k;
for (int t = 0; t < min({(s) + 1, N}); ++t) {

int ip = s;
int lp = t;
for (int j = 0; j < N; ++j) {

for (int l = max({i, 0}); l < min({(j) + 1, N}); ++l) {

int tp = j;
int kp = l;
J[i][j][k][l][s][t] += J[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

int ip = i;
for (int j = 0; j < N; ++j) {

for (int l = 0; l < min({(j) + 1, N}); ++l) {

for (int k = max({j, 0}); k < min({(i) + 1, N}); ++k) {

int tp = j;
for (int s = 0; s < min({(l) + 1, N}); ++s) {

int lp = l;
int sp = k;
for (int t = 0; t < min({(s) + 1, N}); ++t) {

int jp = s;
int kp = t;
J[i][j][k][l][s][t] += J[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

int kp = i;
for (int j = 0; j < min({(i) + 1, N}); ++j) {

for (int k = max({i, 0}); k < N; ++k) {

for (int l = 0; l < min({(j) + 1, N}); ++l) {

int tp = j;
int sp = k;
for (int s = 0; s < min({(l) + 1, N}); ++s) {

int lp = l;
for (int t = 0; t < min({(s) + 1, N}); ++t) {

int jp = s;
int ip = t;
J[i][j][k][l][s][t] += J[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

int ip = i;
for (int j = 0; j < min({(i) + 1, N}); ++j) {

for (int k = 0; k < min({(j) + 1, N}); ++k) {

int tp = j;
for (int l = 0; l < min({(k) + 1, N}); ++l) {

int sp = k;
for (int s = 0; s < min({(l) + 1, N}); ++s) {

int lp = l;
for (int t = 0; t < min({(s) + 1, N}); ++t) {

int kp = s;
int jp = t;
J[i][j][k][l][s][t] += J[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

int jp = i;
for (int j = max({i, 0}); j < N; ++j) {

for (int k = 0; k < min({(i) + 1, N}); ++k) {

int tp = j;
for (int l = 0; l < min({(k) + 1, N}); ++l) {

int sp = k;
for (int s = 0; s < min({(l) + 1, N}); ++s) {

int lp = l;
for (int t = 0; t < min({(s) + 1, N}); ++t) {

int kp = s;
int ip = t;
J[i][j][k][l][s][t] += J[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int l = 0; l < min({(i) + 1, N}); ++l) {

int kp = i;
for (int j = max({i, 0}); j < N; ++j) {

for (int s = 0; s < min({(l) + 1, N}); ++s) {

int lp = l;
for (int k = max({j, 0}); k < N; ++k) {

int tp = j;
for (int t = 0; t < min({(s) + 1, N}); ++t) {

int ip = s;
int sp = k;
int jp = t;
J[i][j][k][l][s][t] += J[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int l = 0; l < min({(i) + 1, N}); ++l) {

int jp = i;
for (int s = 0; s < min({(l) + 1, N}); ++s) {

int lp = l;
for (int t = 0; t < min({(s) + 1, N}); ++t) {

int ip = s;
int kp = t;
for (int j = 0; j < N; ++j) {

for (int k = max({i, 0}); k < min({(j) + 1, N}); ++k) {

int tp = j;
int sp = k;
J[i][j][k][l][s][t] += J[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int s = 0; s < min({(i) + 1, N}); ++s) {

int lp = i;
for (int j = max({i, 0}); j < N; ++j) {

for (int t = 0; t < min({(s) + 1, N}); ++t) {

int jp = s;
for (int k = max({j, 0}); k < N; ++k) {

int tp = j;
int kp = t;
for (int l = max({k, 0}); l < N; ++l) {

int sp = k;
int ip = l;
J[i][j][k][l][s][t] += J[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int s = 0; s < min({(i) + 1, N}); ++s) {

int kp = i;
for (int j = max({i, 0}); j < N; ++j) {

for (int t = 0; t < min({(s) + 1, N}); ++t) {

int jp = s;
int tp = j;
int lp = t;
for (int k = 0; k < N; ++k) {

for (int l = max({j, 0}); l < min({(k) + 1, N}); ++l) {

int sp = k;
int ip = l;
J[i][j][k][l][s][t] += J[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int s = 0; s < min({(i) + 1, N}); ++s) {

int lp = i;
for (int t = 0; t < min({(s) + 1, N}); ++t) {

int kp = s;
int jp = t;
for (int j = 0; j < N; ++j) {

for (int l = max({j, 0}); l < N; ++l) {

for (int k = max({i, 0}); k < min({(j) + 1, N}); ++k) {

int tp = j;
int ip = l;
int sp = k;
J[i][j][k][l][s][t] += J[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int s = 0; s < min({(i) + 1, N}); ++s) {

int jp = i;
for (int k = max({i, 0}); k < N; ++k) {

for (int t = 0; t < min({(s) + 1, N}); ++t) {

int kp = s;
int sp = k;
int lp = t;
for (int j = 0; j < N; ++j) {

for (int l = max({k, 0}); l < min({(j) + 1, N}); ++l) {

int tp = j;
int ip = l;
J[i][j][k][l][s][t] += J[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int s = 0; s < min({(i) + 1, N}); ++s) {

int kp = i;
for (int t = 0; t < min({(s) + 1, N}); ++t) {

int lp = s;
int jp = t;
for (int j = 0; j < N; ++j) {

for (int l = max({i, 0}); l < min({(j) + 1, N}); ++l) {

for (int k = max({j, 0}); k < N; ++k) {

int tp = j;
int ip = l;
int sp = k;
J[i][j][k][l][s][t] += J[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int s = 0; s < min({(i) + 1, N}); ++s) {

int jp = i;
for (int t = 0; t < min({(s) + 1, N}); ++t) {

int lp = s;
int kp = t;
for (int j = 0; j < N; ++j) {

for (int k = 0; k < min({(j) + 1, N}); ++k) {

int tp = j;
for (int l = max({i, 0}); l < min({(k) + 1, N}); ++l) {

int sp = k;
int ip = l;
J[i][j][k][l][s][t] += J[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int t = 0; t < min({(i) + 1, N}); ++t) {

int sp = i;
for (int j = max({i, 0}); j < N; ++j) {

int lp = t;
for (int k = max({j, 0}); k < N; ++k) {

int tp = j;
for (int l = max({k, 0}); l < N; ++l) {

int ip = k;
for (int s = max({l, 0}); s < N; ++s) {

int jp = l;
int kp = s;
J[i][j][k][l][s][t] += J[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int t = 0; t < min({(i) + 1, N}); ++t) {

int lp = i;
for (int j = max({i, 0}); j < N; ++j) {

int sp = t;
for (int k = max({j, 0}); k < N; ++k) {

int tp = j;
int ip = k;
for (int l = 0; l < N; ++l) {

for (int s = max({k, 0}); s < min({(l) + 1, N}); ++s) {

int jp = l;
int kp = s;
J[i][j][k][l][s][t] += J[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int t = 0; t < min({(i) + 1, N}); ++t) {

int sp = i;
for (int j = max({i, 0}); j < N; ++j) {

int kp = t;
int tp = j;
for (int k = 0; k < N; ++k) {

for (int s = max({k, 0}); s < N; ++s) {

for (int l = max({j, 0}); l < min({(k) + 1, N}); ++l) {

int ip = k;
int lp = s;
int jp = l;
J[i][j][k][l][s][t] += J[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int t = 0; t < min({(i) + 1, N}); ++t) {

int kp = i;
for (int j = max({i, 0}); j < N; ++j) {

int sp = t;
for (int l = max({j, 0}); l < N; ++l) {

int tp = j;
int jp = l;
for (int k = 0; k < N; ++k) {

for (int s = max({l, 0}); s < min({(k) + 1, N}); ++s) {

int ip = k;
int lp = s;
J[i][j][k][l][s][t] += J[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int t = 0; t < min({(i) + 1, N}); ++t) {

int lp = i;
for (int j = max({i, 0}); j < N; ++j) {

int kp = t;
int tp = j;
for (int k = 0; k < N; ++k) {

for (int s = max({j, 0}); s < min({(k) + 1, N}); ++s) {

for (int l = max({k, 0}); l < N; ++l) {

int ip = k;
int sp = s;
int jp = l;
J[i][j][k][l][s][t] += J[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int t = 0; t < min({(i) + 1, N}); ++t) {

int kp = i;
for (int j = max({i, 0}); j < N; ++j) {

int lp = t;
int tp = j;
for (int k = 0; k < N; ++k) {

for (int l = 0; l < min({(k) + 1, N}); ++l) {

int ip = k;
for (int s = max({j, 0}); s < min({(l) + 1, N}); ++s) {

int jp = l;
int sp = s;
J[i][j][k][l][s][t] += J[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int t = 0; t < min({(i) + 1, N}); ++t) {

int sp = i;
int lp = t;
for (int j = 0; j < N; ++j) {

for (int l = max({j, 0}); l < N; ++l) {

for (int k = max({i, 0}); k < min({(j) + 1, N}); ++k) {

int tp = j;
for (int s = max({l, 0}); s < N; ++s) {

int kp = l;
int ip = k;
int jp = s;
J[i][j][k][l][s][t] += J[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int t = 0; t < min({(i) + 1, N}); ++t) {

int lp = i;
int sp = t;
for (int j = 0; j < N; ++j) {

for (int k = max({i, 0}); k < min({(j) + 1, N}); ++k) {

int tp = j;
int ip = k;
for (int l = 0; l < N; ++l) {

for (int s = max({j, 0}); s < min({(l) + 1, N}); ++s) {

int kp = l;
int jp = s;
J[i][j][k][l][s][t] += J[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int t = 0; t < min({(i) + 1, N}); ++t) {

int sp = i;
for (int k = max({i, 0}); k < N; ++k) {

int jp = t;
int ip = k;
for (int j = 0; j < N; ++j) {

for (int s = max({j, 0}); s < N; ++s) {

for (int l = max({k, 0}); l < min({(j) + 1, N}); ++l) {

int tp = j;
int lp = s;
int kp = l;
J[i][j][k][l][s][t] += J[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int t = 0; t < min({(i) + 1, N}); ++t) {

int jp = i;
for (int k = max({i, 0}); k < N; ++k) {

int sp = t;
for (int l = max({k, 0}); l < N; ++l) {

int ip = k;
int kp = l;
for (int j = 0; j < N; ++j) {

for (int s = max({l, 0}); s < min({(j) + 1, N}); ++s) {

int tp = j;
int lp = s;
J[i][j][k][l][s][t] += J[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int t = 0; t < min({(i) + 1, N}); ++t) {

int lp = i;
for (int k = max({i, 0}); k < N; ++k) {

int jp = t;
int ip = k;
for (int j = 0; j < N; ++j) {

for (int s = max({k, 0}); s < min({(j) + 1, N}); ++s) {

for (int l = max({j, 0}); l < N; ++l) {

int tp = j;
int sp = s;
int kp = l;
J[i][j][k][l][s][t] += J[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int t = 0; t < min({(i) + 1, N}); ++t) {

int jp = i;
for (int k = max({i, 0}); k < N; ++k) {

int lp = t;
int ip = k;
for (int j = 0; j < N; ++j) {

for (int l = 0; l < min({(j) + 1, N}); ++l) {

int tp = j;
for (int s = max({k, 0}); s < min({(l) + 1, N}); ++s) {

int kp = l;
int sp = s;
J[i][j][k][l][s][t] += J[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int t = 0; t < min({(i) + 1, N}); ++t) {

int sp = i;
int kp = t;
for (int j = 0; j < N; ++j) {

for (int l = max({i, 0}); l < min({(j) + 1, N}); ++l) {

for (int k = max({j, 0}); k < N; ++k) {

int tp = j;
int lp = l;
for (int s = max({k, 0}); s < N; ++s) {

int ip = k;
int jp = s;
J[i][j][k][l][s][t] += J[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int t = 0; t < min({(i) + 1, N}); ++t) {

int kp = i;
int sp = t;
for (int j = 0; j < N; ++j) {

for (int l = max({i, 0}); l < min({(j) + 1, N}); ++l) {

int tp = j;
int lp = l;
for (int k = 0; k < N; ++k) {

for (int s = max({j, 0}); s < min({(k) + 1, N}); ++s) {

int ip = k;
int jp = s;
J[i][j][k][l][s][t] += J[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int t = 0; t < min({(i) + 1, N}); ++t) {

int sp = i;
int jp = t;
for (int j = 0; j < N; ++j) {

for (int s = max({j, 0}); s < N; ++s) {

for (int k = 0; k < min({(j) + 1, N}); ++k) {

int tp = j;
int kp = s;
for (int l = max({i, 0}); l < min({(k) + 1, N}); ++l) {

int ip = k;
int lp = l;
J[i][j][k][l][s][t] += J[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int t = 0; t < min({(i) + 1, N}); ++t) {

int jp = i;
int sp = t;
for (int j = 0; j < N; ++j) {

for (int k = 0; k < N; ++k) {

int tp = j;
for (int s = max({k, 0}); s < min({(j) + 1, N}); ++s) {

for (int l = max({i, 0}); l < min({(k) + 1, N}); ++l) {

int ip = k;
int kp = s;
int lp = l;
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

int kp = i;
int jp = t;
int lp = l;
for (int j = 0; j < N; ++j) {

for (int s = max({l, 0}); s < min({(j) + 1, N}); ++s) {

for (int k = max({j, 0}); k < N; ++k) {

int tp = j;
int sp = s;
int ip = k;
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

int jp = i;
int kp = t;
int lp = l;
for (int j = 0; j < N; ++j) {

for (int k = 0; k < min({(j) + 1, N}); ++k) {

int tp = j;
for (int s = max({l, 0}); s < min({(k) + 1, N}); ++s) {

int ip = k;
int sp = s;
J[i][j][k][l][s][t] += J[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int t = 0; t < min({(i) + 1, N}); ++t) {

int lp = i;
int kp = t;
for (int j = 0; j < N; ++j) {

for (int s = max({i, 0}); s < min({(j) + 1, N}); ++s) {

for (int k = max({j, 0}); k < N; ++k) {

int tp = j;
int jp = s;
for (int l = max({k, 0}); l < N; ++l) {

int ip = k;
int sp = l;
J[i][j][k][l][s][t] += J[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int t = 0; t < min({(i) + 1, N}); ++t) {

int kp = i;
int lp = t;
for (int j = 0; j < N; ++j) {

for (int s = max({i, 0}); s < min({(j) + 1, N}); ++s) {

int tp = j;
int jp = s;
for (int k = 0; k < N; ++k) {

for (int l = max({j, 0}); l < min({(k) + 1, N}); ++l) {

int ip = k;
int sp = l;
J[i][j][k][l][s][t] += J[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int t = 0; t < min({(i) + 1, N}); ++t) {

int lp = i;
int jp = t;
for (int j = 0; j < N; ++j) {

for (int l = max({j, 0}); l < N; ++l) {

for (int k = 0; k < min({(j) + 1, N}); ++k) {

int tp = j;
int sp = l;
for (int s = max({i, 0}); s < min({(k) + 1, N}); ++s) {

int ip = k;
int kp = s;
J[i][j][k][l][s][t] += J[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int t = 0; t < min({(i) + 1, N}); ++t) {

int jp = i;
int lp = t;
for (int j = 0; j < N; ++j) {

for (int k = 0; k < N; ++k) {

int tp = j;
for (int s = max({i, 0}); s < min({(k) + 1, N}); ++s) {

for (int l = max({k, 0}); l < min({(j) + 1, N}); ++l) {

int ip = k;
int kp = s;
int sp = l;
J[i][j][k][l][s][t] += J[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int t = 0; t < min({(i) + 1, N}); ++t) {

int kp = i;
int jp = t;
for (int j = 0; j < N; ++j) {

for (int l = 0; l < min({(j) + 1, N}); ++l) {

for (int k = max({j, 0}); k < N; ++k) {

int tp = j;
for (int s = max({i, 0}); s < min({(l) + 1, N}); ++s) {

int sp = l;
int ip = k;
int lp = s;
J[i][j][k][l][s][t] += J[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int t = 0; t < min({(i) + 1, N}); ++t) {

int jp = i;
int kp = t;
for (int j = 0; j < N; ++j) {

for (int k = 0; k < min({(j) + 1, N}); ++k) {

int tp = j;
for (int l = 0; l < min({(k) + 1, N}); ++l) {

int ip = k;
for (int s = max({i, 0}); s < min({(l) + 1, N}); ++s) {

int sp = l;
int lp = s;
J[i][j][k][l][s][t] += J[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int j = max({i, 0}); j < N; ++j) {

int tp = i;
int ip = j;
for (int k = max({j, 0}); k < N; ++k) {

for (int l = max({k, 0}); l < N; ++l) {

int jp = k;
for (int s = max({l, 0}); s < N; ++s) {

int kp = l;
for (int t = max({s, 0}); t < N; ++t) {

int lp = s;
int sp = t;
J[i][j][k][l][s][t] += J[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

int sp = i;
for (int j = max({i, 0}); j < N; ++j) {

int ip = j;
for (int k = max({j, 0}); k < N; ++k) {

for (int l = max({k, 0}); l < N; ++l) {

int jp = k;
int kp = l;
for (int s = 0; s < N; ++s) {

for (int t = max({l, 0}); t < min({(s) + 1, N}); ++t) {

int lp = s;
int tp = t;
J[i][j][k][l][s][t] += J[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int j = max({i, 0}); j < N; ++j) {

int tp = i;
int ip = j;
for (int k = max({j, 0}); k < N; ++k) {

for (int l = 0; l < N; ++l) {

int jp = k;
for (int s = max({k, 0}); s < min({(l) + 1, N}); ++s) {

for (int t = max({l, 0}); t < N; ++t) {

int kp = l;
int sp = s;
int lp = t;
J[i][j][k][l][s][t] += J[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

int lp = i;
for (int j = max({i, 0}); j < N; ++j) {

int ip = j;
for (int k = max({j, 0}); k < N; ++k) {

for (int s = max({k, 0}); s < N; ++s) {

int jp = k;
int sp = s;
for (int l = 0; l < N; ++l) {

for (int t = max({s, 0}); t < min({(l) + 1, N}); ++t) {

int kp = l;
int tp = t;
J[i][j][k][l][s][t] += J[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

int sp = i;
for (int j = max({i, 0}); j < N; ++j) {

int ip = j;
for (int k = max({j, 0}); k < N; ++k) {

for (int l = 0; l < N; ++l) {

int jp = k;
for (int s = max({l, 0}); s < N; ++s) {

for (int t = max({k, 0}); t < min({(l) + 1, N}); ++t) {

int kp = l;
int tp = s;
int lp = t;
J[i][j][k][l][s][t] += J[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

int lp = i;
for (int j = max({i, 0}); j < N; ++j) {

int ip = j;
for (int k = max({j, 0}); k < N; ++k) {

for (int l = 0; l < N; ++l) {

int jp = k;
for (int s = 0; s < min({(l) + 1, N}); ++s) {

int kp = l;
for (int t = max({k, 0}); t < min({(s) + 1, N}); ++t) {

int tp = s;
int sp = t;
J[i][j][k][l][s][t] += J[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int j = max({i, 0}); j < N; ++j) {

int tp = i;
int ip = j;
for (int k = 0; k < N; ++k) {

for (int s = max({k, 0}); s < N; ++s) {

for (int l = max({j, 0}); l < min({(k) + 1, N}); ++l) {

int jp = k;
for (int t = max({s, 0}); t < N; ++t) {

int kp = s;
int lp = l;
int sp = t;
J[i][j][k][l][s][t] += J[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

int sp = i;
for (int j = max({i, 0}); j < N; ++j) {

int ip = j;
for (int k = 0; k < N; ++k) {

for (int l = max({j, 0}); l < min({(k) + 1, N}); ++l) {

int jp = k;
int lp = l;
for (int s = 0; s < N; ++s) {

for (int t = max({k, 0}); t < min({(s) + 1, N}); ++t) {

int kp = s;
int tp = t;
J[i][j][k][l][s][t] += J[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int j = max({i, 0}); j < N; ++j) {

int tp = i;
for (int l = max({j, 0}); l < N; ++l) {

int ip = j;
int lp = l;
for (int k = 0; k < N; ++k) {

for (int s = max({l, 0}); s < min({(k) + 1, N}); ++s) {

for (int t = max({k, 0}); t < N; ++t) {

int jp = k;
int sp = s;
int kp = t;
J[i][j][k][l][s][t] += J[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

int kp = i;
for (int j = max({i, 0}); j < N; ++j) {

for (int l = max({j, 0}); l < N; ++l) {

int ip = j;
for (int s = max({l, 0}); s < N; ++s) {

int lp = l;
int sp = s;
for (int k = 0; k < N; ++k) {

for (int t = max({s, 0}); t < min({(k) + 1, N}); ++t) {

int jp = k;
int tp = t;
J[i][j][k][l][s][t] += J[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

int sp = i;
for (int j = max({i, 0}); j < N; ++j) {

for (int l = max({j, 0}); l < N; ++l) {

int ip = j;
int lp = l;
for (int k = 0; k < N; ++k) {

for (int s = max({k, 0}); s < N; ++s) {

for (int t = max({l, 0}); t < min({(k) + 1, N}); ++t) {

int jp = k;
int tp = s;
int kp = t;
J[i][j][k][l][s][t] += J[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

int kp = i;
for (int j = max({i, 0}); j < N; ++j) {

for (int l = max({j, 0}); l < N; ++l) {

int ip = j;
int lp = l;
for (int k = 0; k < N; ++k) {

for (int s = 0; s < min({(k) + 1, N}); ++s) {

int jp = k;
for (int t = max({l, 0}); t < min({(s) + 1, N}); ++t) {

int tp = s;
int sp = t;
J[i][j][k][l][s][t] += J[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int j = max({i, 0}); j < N; ++j) {

int tp = i;
int ip = j;
for (int k = 0; k < N; ++k) {

for (int s = max({j, 0}); s < min({(k) + 1, N}); ++s) {

for (int l = max({k, 0}); l < N; ++l) {

int jp = k;
int kp = s;
for (int t = max({l, 0}); t < N; ++t) {

int sp = l;
int lp = t;
J[i][j][k][l][s][t] += J[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

int lp = i;
for (int j = max({i, 0}); j < N; ++j) {

int ip = j;
for (int k = 0; k < N; ++k) {

for (int s = max({j, 0}); s < min({(k) + 1, N}); ++s) {

int jp = k;
int kp = s;
for (int l = 0; l < N; ++l) {

for (int t = max({k, 0}); t < min({(l) + 1, N}); ++t) {

int sp = l;
int tp = t;
J[i][j][k][l][s][t] += J[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int j = max({i, 0}); j < N; ++j) {

int tp = i;
int ip = j;
for (int k = 0; k < N; ++k) {

for (int t = max({k, 0}); t < N; ++t) {

for (int l = 0; l < min({(k) + 1, N}); ++l) {

int jp = k;
int kp = t;
for (int s = max({j, 0}); s < min({(l) + 1, N}); ++s) {

int sp = l;
int lp = s;
J[i][j][k][l][s][t] += J[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

int kp = i;
for (int j = max({i, 0}); j < N; ++j) {

int ip = j;
for (int k = 0; k < N; ++k) {

for (int l = 0; l < N; ++l) {

int jp = k;
for (int s = max({j, 0}); s < min({(l) + 1, N}); ++s) {

for (int t = max({l, 0}); t < min({(k) + 1, N}); ++t) {

int sp = l;
int lp = s;
int tp = t;
J[i][j][k][l][s][t] += J[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

int lp = i;
for (int j = max({i, 0}); j < N; ++j) {

for (int s = max({j, 0}); s < N; ++s) {

int ip = j;
int tp = s;
for (int k = 0; k < N; ++k) {

for (int t = max({s, 0}); t < min({(k) + 1, N}); ++t) {

for (int l = max({k, 0}); l < N; ++l) {

int jp = k;
int kp = t;
int sp = l;
J[i][j][k][l][s][t] += J[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

int kp = i;
for (int j = max({i, 0}); j < N; ++j) {

for (int s = max({j, 0}); s < N; ++s) {

int ip = j;
int tp = s;
for (int k = 0; k < N; ++k) {

for (int l = 0; l < min({(k) + 1, N}); ++l) {

int jp = k;
for (int t = max({s, 0}); t < min({(l) + 1, N}); ++t) {

int sp = l;
int lp = t;
J[i][j][k][l][s][t] += J[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

int sp = i;
for (int j = max({i, 0}); j < N; ++j) {

int ip = j;
for (int k = 0; k < N; ++k) {

for (int t = max({j, 0}); t < min({(k) + 1, N}); ++t) {

for (int l = max({k, 0}); l < N; ++l) {

int jp = k;
int lp = t;
for (int s = max({l, 0}); s < N; ++s) {

int tp = l;
int kp = s;
J[i][j][k][l][s][t] += J[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

int lp = i;
for (int j = max({i, 0}); j < N; ++j) {

int ip = j;
for (int k = 0; k < N; ++k) {

for (int t = max({j, 0}); t < min({(k) + 1, N}); ++t) {

int jp = k;
int sp = t;
for (int l = 0; l < N; ++l) {

for (int s = max({k, 0}); s < min({(l) + 1, N}); ++s) {

int tp = l;
int kp = s;
J[i][j][k][l][s][t] += J[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

int sp = i;
for (int j = max({i, 0}); j < N; ++j) {

int ip = j;
for (int k = 0; k < N; ++k) {

for (int s = max({k, 0}); s < N; ++s) {

for (int l = 0; l < min({(k) + 1, N}); ++l) {

int jp = k;
int lp = s;
for (int t = max({j, 0}); t < min({(l) + 1, N}); ++t) {

int tp = l;
int kp = t;
J[i][j][k][l][s][t] += J[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

int kp = i;
for (int j = max({i, 0}); j < N; ++j) {

int ip = j;
for (int k = 0; k < N; ++k) {

for (int l = 0; l < N; ++l) {

int jp = k;
for (int s = max({l, 0}); s < min({(k) + 1, N}); ++s) {

for (int t = max({j, 0}); t < min({(l) + 1, N}); ++t) {

int tp = l;
int lp = s;
int sp = t;
J[i][j][k][l][s][t] += J[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

int lp = i;
for (int j = max({i, 0}); j < N; ++j) {

int ip = j;
for (int k = 0; k < N; ++k) {

for (int s = 0; s < min({(k) + 1, N}); ++s) {

for (int l = max({k, 0}); l < N; ++l) {

int jp = k;
for (int t = max({j, 0}); t < min({(s) + 1, N}); ++t) {

int sp = s;
int tp = l;
int kp = t;
J[i][j][k][l][s][t] += J[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

int kp = i;
for (int j = max({i, 0}); j < N; ++j) {

int ip = j;
for (int k = 0; k < N; ++k) {

for (int l = 0; l < min({(k) + 1, N}); ++l) {

int jp = k;
for (int s = 0; s < min({(l) + 1, N}); ++s) {

int tp = l;
for (int t = max({j, 0}); t < min({(s) + 1, N}); ++t) {

int sp = s;
int lp = t;
J[i][j][k][l][s][t] += J[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int j = 0; j < N; ++j) {

int tp = i;
for (int l = max({j, 0}); l < N; ++l) {

int ip = j;
for (int k = max({i, 0}); k < min({(j) + 1, N}); ++k) {

for (int s = max({l, 0}); s < N; ++s) {

int jp = l;
int kp = k;
for (int t = max({s, 0}); t < N; ++t) {

int lp = s;
int sp = t;
J[i][j][k][l][s][t] += J[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

int sp = i;
for (int j = 0; j < N; ++j) {

for (int l = max({j, 0}); l < N; ++l) {

int ip = j;
for (int k = max({i, 0}); k < min({(j) + 1, N}); ++k) {

int jp = l;
int kp = k;
for (int s = 0; s < N; ++s) {

for (int t = max({l, 0}); t < min({(s) + 1, N}); ++t) {

int lp = s;
int tp = t;
J[i][j][k][l][s][t] += J[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int j = 0; j < N; ++j) {

int tp = i;
int ip = j;
for (int k = max({i, 0}); k < min({(j) + 1, N}); ++k) {

for (int l = 0; l < N; ++l) {

int kp = k;
for (int s = max({j, 0}); s < min({(l) + 1, N}); ++s) {

for (int t = max({l, 0}); t < N; ++t) {

int jp = l;
int sp = s;
int lp = t;
J[i][j][k][l][s][t] += J[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

int lp = i;
for (int j = 0; j < N; ++j) {

for (int s = max({j, 0}); s < N; ++s) {

int ip = j;
for (int k = max({i, 0}); k < min({(j) + 1, N}); ++k) {

int sp = s;
int kp = k;
for (int l = 0; l < N; ++l) {

for (int t = max({s, 0}); t < min({(l) + 1, N}); ++t) {

int jp = l;
int tp = t;
J[i][j][k][l][s][t] += J[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

int sp = i;
for (int j = 0; j < N; ++j) {

int ip = j;
for (int k = max({i, 0}); k < min({(j) + 1, N}); ++k) {

for (int l = 0; l < N; ++l) {

int kp = k;
for (int s = max({l, 0}); s < N; ++s) {

for (int t = max({j, 0}); t < min({(l) + 1, N}); ++t) {

int jp = l;
int tp = s;
int lp = t;
J[i][j][k][l][s][t] += J[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

int lp = i;
for (int j = 0; j < N; ++j) {

int ip = j;
for (int k = max({i, 0}); k < min({(j) + 1, N}); ++k) {

for (int l = 0; l < N; ++l) {

int kp = k;
for (int s = 0; s < min({(l) + 1, N}); ++s) {

int jp = l;
for (int t = max({j, 0}); t < min({(s) + 1, N}); ++t) {

int tp = s;
int sp = t;
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

int tp = i;
for (int s = max({j, 0}); s < N; ++s) {

int ip = j;
for (int l = max({k, 0}); l < min({(j) + 1, N}); ++l) {

int kp = k;
for (int t = max({s, 0}); t < N; ++t) {

int jp = s;
int lp = l;
int sp = t;
J[i][j][k][l][s][t] += J[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

int sp = i;
for (int k = max({i, 0}); k < N; ++k) {

int kp = k;
for (int j = 0; j < N; ++j) {

for (int l = max({k, 0}); l < min({(j) + 1, N}); ++l) {

int ip = j;
int lp = l;
for (int s = 0; s < N; ++s) {

for (int t = max({j, 0}); t < min({(s) + 1, N}); ++t) {

int jp = s;
int tp = t;
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

int tp = i;
for (int t = max({j, 0}); t < N; ++t) {

int ip = j;
for (int l = max({k, 0}); l < N; ++l) {

int kp = k;
int jp = t;
for (int s = max({l, 0}); s < min({(j) + 1, N}); ++s) {

int lp = l;
int sp = s;
J[i][j][k][l][s][t] += J[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

int jp = i;
for (int k = max({i, 0}); k < N; ++k) {

for (int l = max({k, 0}); l < N; ++l) {

int kp = k;
for (int s = max({l, 0}); s < N; ++s) {

int lp = l;
int sp = s;
for (int j = 0; j < N; ++j) {

for (int t = max({s, 0}); t < min({(j) + 1, N}); ++t) {

int ip = j;
int tp = t;
J[i][j][k][l][s][t] += J[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

int sp = i;
for (int k = max({i, 0}); k < N; ++k) {

for (int l = max({k, 0}); l < N; ++l) {

int kp = k;
int lp = l;
for (int j = 0; j < N; ++j) {

for (int s = max({j, 0}); s < N; ++s) {

for (int t = max({l, 0}); t < min({(j) + 1, N}); ++t) {

int ip = j;
int tp = s;
int jp = t;
J[i][j][k][l][s][t] += J[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

int jp = i;
for (int k = max({i, 0}); k < N; ++k) {

for (int l = max({k, 0}); l < N; ++l) {

int kp = k;
int lp = l;
for (int j = 0; j < N; ++j) {

for (int s = 0; s < min({(j) + 1, N}); ++s) {

int ip = j;
for (int t = max({l, 0}); t < min({(s) + 1, N}); ++t) {

int tp = s;
int sp = t;
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

int tp = i;
for (int l = max({j, 0}); l < N; ++l) {

int ip = j;
for (int s = max({k, 0}); s < min({(j) + 1, N}); ++s) {

int kp = k;
for (int t = max({l, 0}); t < N; ++t) {

int sp = l;
int jp = s;
int lp = t;
J[i][j][k][l][s][t] += J[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

int lp = i;
for (int k = max({i, 0}); k < N; ++k) {

int kp = k;
for (int j = 0; j < N; ++j) {

for (int s = max({k, 0}); s < min({(j) + 1, N}); ++s) {

int ip = j;
int jp = s;
for (int l = 0; l < N; ++l) {

for (int t = max({j, 0}); t < min({(l) + 1, N}); ++t) {

int sp = l;
int tp = t;
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

int tp = i;
for (int t = max({j, 0}); t < N; ++t) {

for (int l = 0; l < min({(j) + 1, N}); ++l) {

int ip = j;
int kp = k;
int jp = t;
for (int s = max({k, 0}); s < min({(l) + 1, N}); ++s) {

int sp = l;
int lp = s;
J[i][j][k][l][s][t] += J[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

int jp = i;
for (int k = max({i, 0}); k < N; ++k) {

int kp = k;
for (int j = 0; j < N; ++j) {

int ip = j;
for (int l = 0; l < N; ++l) {

for (int s = max({k, 0}); s < min({(l) + 1, N}); ++s) {

for (int t = max({l, 0}); t < min({(j) + 1, N}); ++t) {

int sp = l;
int lp = s;
int tp = t;
J[i][j][k][l][s][t] += J[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

int lp = i;
for (int k = max({i, 0}); k < N; ++k) {

for (int s = max({k, 0}); s < N; ++s) {

int kp = k;
int tp = s;
for (int j = 0; j < N; ++j) {

for (int t = max({s, 0}); t < min({(j) + 1, N}); ++t) {

for (int l = max({j, 0}); l < N; ++l) {

int ip = j;
int jp = t;
int sp = l;
J[i][j][k][l][s][t] += J[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

int jp = i;
for (int k = max({i, 0}); k < N; ++k) {

for (int s = max({k, 0}); s < N; ++s) {

int kp = k;
int tp = s;
for (int j = 0; j < N; ++j) {

for (int l = 0; l < min({(j) + 1, N}); ++l) {

int ip = j;
for (int t = max({s, 0}); t < min({(l) + 1, N}); ++t) {

int sp = l;
int lp = t;
J[i][j][k][l][s][t] += J[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

int sp = i;
for (int k = max({i, 0}); k < N; ++k) {

int kp = k;
for (int j = 0; j < N; ++j) {

for (int t = max({k, 0}); t < min({(j) + 1, N}); ++t) {

for (int l = max({j, 0}); l < N; ++l) {

int ip = j;
int lp = t;
for (int s = max({l, 0}); s < N; ++s) {

int tp = l;
int jp = s;
J[i][j][k][l][s][t] += J[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

int lp = i;
for (int k = max({i, 0}); k < N; ++k) {

int kp = k;
for (int j = 0; j < N; ++j) {

for (int t = max({k, 0}); t < min({(j) + 1, N}); ++t) {

int ip = j;
int sp = t;
for (int l = 0; l < N; ++l) {

for (int s = max({j, 0}); s < min({(l) + 1, N}); ++s) {

int tp = l;
int jp = s;
J[i][j][k][l][s][t] += J[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

int sp = i;
for (int k = max({i, 0}); k < N; ++k) {

int kp = k;
for (int j = 0; j < N; ++j) {

for (int s = max({j, 0}); s < N; ++s) {

for (int l = 0; l < min({(j) + 1, N}); ++l) {

int ip = j;
int lp = s;
for (int t = max({k, 0}); t < min({(l) + 1, N}); ++t) {

int tp = l;
int jp = t;
J[i][j][k][l][s][t] += J[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

int jp = i;
for (int k = max({i, 0}); k < N; ++k) {

int kp = k;
for (int j = 0; j < N; ++j) {

int ip = j;
for (int l = 0; l < N; ++l) {

for (int s = max({l, 0}); s < min({(j) + 1, N}); ++s) {

for (int t = max({k, 0}); t < min({(l) + 1, N}); ++t) {

int tp = l;
int lp = s;
int sp = t;
J[i][j][k][l][s][t] += J[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

int lp = i;
for (int k = max({i, 0}); k < N; ++k) {

int kp = k;
for (int j = 0; j < N; ++j) {

for (int s = 0; s < min({(j) + 1, N}); ++s) {

for (int l = max({j, 0}); l < N; ++l) {

int ip = j;
for (int t = max({k, 0}); t < min({(s) + 1, N}); ++t) {

int sp = s;
int tp = l;
int jp = t;
J[i][j][k][l][s][t] += J[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

int jp = i;
for (int k = max({i, 0}); k < N; ++k) {

int kp = k;
for (int j = 0; j < N; ++j) {

for (int l = 0; l < min({(j) + 1, N}); ++l) {

int ip = j;
for (int s = 0; s < min({(l) + 1, N}); ++s) {

int tp = l;
for (int t = max({k, 0}); t < min({(s) + 1, N}); ++t) {

int sp = s;
int lp = t;
J[i][j][k][l][s][t] += J[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int j = 0; j < N; ++j) {

int tp = i;
for (int l = max({i, 0}); l < min({(j) + 1, N}); ++l) {

int ip = j;
for (int k = max({j, 0}); k < N; ++k) {

int jp = l;
for (int s = max({k, 0}); s < N; ++s) {

int lp = k;
for (int t = max({s, 0}); t < N; ++t) {

int kp = s;
int sp = t;
J[i][j][k][l][s][t] += J[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

int sp = i;
for (int j = 0; j < N; ++j) {

for (int l = max({i, 0}); l < min({(j) + 1, N}); ++l) {

int ip = j;
for (int k = max({j, 0}); k < N; ++k) {

int jp = l;
int lp = k;
for (int s = 0; s < N; ++s) {

for (int t = max({k, 0}); t < min({(s) + 1, N}); ++t) {

int kp = s;
int tp = t;
J[i][j][k][l][s][t] += J[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int j = 0; j < N; ++j) {

int tp = i;
for (int l = max({i, 0}); l < min({(j) + 1, N}); ++l) {

int ip = j;
int jp = l;
for (int k = 0; k < N; ++k) {

for (int s = max({j, 0}); s < min({(k) + 1, N}); ++s) {

for (int t = max({k, 0}); t < N; ++t) {

int lp = k;
int sp = s;
int kp = t;
J[i][j][k][l][s][t] += J[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

int kp = i;
for (int j = 0; j < N; ++j) {

for (int s = max({j, 0}); s < N; ++s) {

for (int l = max({i, 0}); l < min({(j) + 1, N}); ++l) {

int ip = j;
int sp = s;
int jp = l;
for (int k = 0; k < N; ++k) {

for (int t = max({s, 0}); t < min({(k) + 1, N}); ++t) {

int lp = k;
int tp = t;
J[i][j][k][l][s][t] += J[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

int sp = i;
for (int j = 0; j < N; ++j) {

for (int l = max({i, 0}); l < min({(j) + 1, N}); ++l) {

int ip = j;
int jp = l;
for (int k = 0; k < N; ++k) {

for (int s = max({k, 0}); s < N; ++s) {

for (int t = max({j, 0}); t < min({(k) + 1, N}); ++t) {

int lp = k;
int tp = s;
int kp = t;
J[i][j][k][l][s][t] += J[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

int kp = i;
for (int j = 0; j < N; ++j) {

for (int l = max({i, 0}); l < min({(j) + 1, N}); ++l) {

int ip = j;
int jp = l;
for (int k = 0; k < N; ++k) {

for (int s = 0; s < min({(k) + 1, N}); ++s) {

int lp = k;
for (int t = max({j, 0}); t < min({(s) + 1, N}); ++t) {

int tp = s;
int sp = t;
J[i][j][k][l][s][t] += J[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int j = 0; j < N; ++j) {

int tp = i;
for (int s = max({j, 0}); s < N; ++s) {

int ip = j;
for (int k = 0; k < min({(j) + 1, N}); ++k) {

for (int t = max({s, 0}); t < N; ++t) {

int jp = s;
for (int l = max({i, 0}); l < min({(k) + 1, N}); ++l) {

int lp = k;
int sp = t;
int kp = l;
J[i][j][k][l][s][t] += J[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

int sp = i;
for (int j = 0; j < N; ++j) {

int ip = j;
for (int k = 0; k < min({(j) + 1, N}); ++k) {

for (int l = max({i, 0}); l < min({(k) + 1, N}); ++l) {

int lp = k;
int kp = l;
for (int s = 0; s < N; ++s) {

for (int t = max({j, 0}); t < min({(s) + 1, N}); ++t) {

int jp = s;
int tp = t;
J[i][j][k][l][s][t] += J[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int j = 0; j < N; ++j) {

int tp = i;
for (int t = max({j, 0}); t < N; ++t) {

int ip = j;
int jp = t;
for (int k = 0; k < N; ++k) {

for (int s = max({k, 0}); s < min({(j) + 1, N}); ++s) {

for (int l = max({i, 0}); l < min({(k) + 1, N}); ++l) {

int lp = k;
int sp = s;
int kp = l;
J[i][j][k][l][s][t] += J[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

int jp = i;
for (int j = 0; j < N; ++j) {

int ip = j;
for (int k = 0; k < N; ++k) {

for (int s = max({k, 0}); s < N; ++s) {

for (int l = max({i, 0}); l < min({(k) + 1, N}); ++l) {

int lp = k;
for (int t = max({s, 0}); t < min({(j) + 1, N}); ++t) {

int sp = s;
int kp = l;
int tp = t;
J[i][j][k][l][s][t] += J[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

int sp = i;
for (int j = 0; j < N; ++j) {

for (int s = max({j, 0}); s < N; ++s) {

int ip = j;
int tp = s;
for (int k = 0; k < N; ++k) {

for (int t = max({k, 0}); t < min({(j) + 1, N}); ++t) {

for (int l = max({i, 0}); l < min({(k) + 1, N}); ++l) {

int lp = k;
int jp = t;
int kp = l;
J[i][j][k][l][s][t] += J[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

int jp = i;
for (int j = 0; j < N; ++j) {

for (int s = 0; s < min({(j) + 1, N}); ++s) {

int ip = j;
int tp = s;
for (int k = 0; k < N; ++k) {

for (int t = max({k, 0}); t < min({(s) + 1, N}); ++t) {

for (int l = max({i, 0}); l < min({(k) + 1, N}); ++l) {

int lp = k;
int sp = t;
int kp = l;
J[i][j][k][l][s][t] += J[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int l = max({i, 0}); l < N; ++l) {

int tp = i;
int sp = l;
for (int j = 0; j < N; ++j) {

for (int s = max({l, 0}); s < min({(j) + 1, N}); ++s) {

int ip = j;
for (int k = max({j, 0}); k < N; ++k) {

int jp = s;
for (int t = max({k, 0}); t < N; ++t) {

int lp = k;
int kp = t;
J[i][j][k][l][s][t] += J[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int l = max({i, 0}); l < N; ++l) {

int kp = i;
int sp = l;
for (int j = 0; j < N; ++j) {

for (int s = max({l, 0}); s < min({(j) + 1, N}); ++s) {

int ip = j;
int jp = s;
for (int k = 0; k < N; ++k) {

for (int t = max({j, 0}); t < min({(k) + 1, N}); ++t) {

int lp = k;
int tp = t;
J[i][j][k][l][s][t] += J[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int l = max({i, 0}); l < N; ++l) {

int tp = i;
int sp = l;
for (int j = 0; j < N; ++j) {

for (int t = max({j, 0}); t < N; ++t) {

int ip = j;
for (int k = 0; k < min({(j) + 1, N}); ++k) {

int jp = t;
for (int s = max({l, 0}); s < min({(k) + 1, N}); ++s) {

int lp = k;
int kp = s;
J[i][j][k][l][s][t] += J[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int l = max({i, 0}); l < N; ++l) {

int jp = i;
int sp = l;
for (int j = 0; j < N; ++j) {

int ip = j;
for (int k = 0; k < N; ++k) {

for (int s = max({l, 0}); s < min({(k) + 1, N}); ++s) {

for (int t = max({k, 0}); t < min({(j) + 1, N}); ++t) {

int lp = k;
int kp = s;
int tp = t;
J[i][j][k][l][s][t] += J[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int l = max({i, 0}); l < N; ++l) {

int kp = i;
for (int s = max({l, 0}); s < N; ++s) {

int sp = l;
int tp = s;
for (int j = 0; j < N; ++j) {

for (int t = max({s, 0}); t < min({(j) + 1, N}); ++t) {

int ip = j;
for (int k = max({j, 0}); k < N; ++k) {

int jp = t;
int lp = k;
J[i][j][k][l][s][t] += J[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int l = max({i, 0}); l < N; ++l) {

int jp = i;
for (int s = max({l, 0}); s < N; ++s) {

int sp = l;
int tp = s;
for (int j = 0; j < N; ++j) {

int ip = j;
for (int k = 0; k < min({(j) + 1, N}); ++k) {

for (int t = max({s, 0}); t < min({(k) + 1, N}); ++t) {

int lp = k;
int kp = t;
J[i][j][k][l][s][t] += J[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int l = max({i, 0}); l < N; ++l) {

int sp = i;
int tp = l;
for (int j = 0; j < N; ++j) {

for (int t = max({l, 0}); t < min({(j) + 1, N}); ++t) {

int ip = j;
for (int k = max({j, 0}); k < N; ++k) {

int kp = t;
for (int s = max({k, 0}); s < N; ++s) {

int lp = k;
int jp = s;
J[i][j][k][l][s][t] += J[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int l = max({i, 0}); l < N; ++l) {

int kp = i;
int tp = l;
for (int j = 0; j < N; ++j) {

for (int t = max({l, 0}); t < min({(j) + 1, N}); ++t) {

int ip = j;
int sp = t;
for (int k = 0; k < N; ++k) {

for (int s = max({j, 0}); s < min({(k) + 1, N}); ++s) {

int lp = k;
int jp = s;
J[i][j][k][l][s][t] += J[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int l = max({i, 0}); l < N; ++l) {

int sp = i;
int tp = l;
for (int j = 0; j < N; ++j) {

for (int s = max({j, 0}); s < N; ++s) {

int ip = j;
for (int k = 0; k < min({(j) + 1, N}); ++k) {

int kp = s;
for (int t = max({l, 0}); t < min({(k) + 1, N}); ++t) {

int lp = k;
int jp = t;
J[i][j][k][l][s][t] += J[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int l = max({i, 0}); l < N; ++l) {

int jp = i;
int tp = l;
for (int j = 0; j < N; ++j) {

int ip = j;
for (int k = 0; k < N; ++k) {

for (int s = max({k, 0}); s < min({(j) + 1, N}); ++s) {

for (int t = max({l, 0}); t < min({(k) + 1, N}); ++t) {

int lp = k;
int kp = s;
int sp = t;
J[i][j][k][l][s][t] += J[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int l = max({i, 0}); l < N; ++l) {

int kp = i;
int tp = l;
for (int j = 0; j < N; ++j) {

for (int s = 0; s < min({(j) + 1, N}); ++s) {

int ip = j;
for (int k = max({j, 0}); k < N; ++k) {

for (int t = max({l, 0}); t < min({(s) + 1, N}); ++t) {

int sp = s;
int lp = k;
int jp = t;
J[i][j][k][l][s][t] += J[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int l = max({i, 0}); l < N; ++l) {

int jp = i;
int tp = l;
for (int j = 0; j < N; ++j) {

int ip = j;
for (int k = 0; k < min({(j) + 1, N}); ++k) {

for (int s = 0; s < min({(k) + 1, N}); ++s) {

int lp = k;
for (int t = max({l, 0}); t < min({(s) + 1, N}); ++t) {

int sp = s;
int kp = t;
J[i][j][k][l][s][t] += J[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int j = 0; j < N; ++j) {

int tp = i;
for (int s = max({i, 0}); s < min({(j) + 1, N}); ++s) {

int ip = j;
for (int k = max({j, 0}); k < N; ++k) {

int kp = s;
for (int l = max({k, 0}); l < N; ++l) {

int sp = k;
for (int t = max({l, 0}); t < N; ++t) {

int jp = l;
int lp = t;
J[i][j][k][l][s][t] += J[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

int lp = i;
for (int j = 0; j < N; ++j) {

for (int s = max({i, 0}); s < min({(j) + 1, N}); ++s) {

int ip = j;
for (int k = max({j, 0}); k < N; ++k) {

int kp = s;
int sp = k;
for (int l = 0; l < N; ++l) {

for (int t = max({k, 0}); t < min({(l) + 1, N}); ++t) {

int jp = l;
int tp = t;
J[i][j][k][l][s][t] += J[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int j = 0; j < N; ++j) {

int tp = i;
for (int s = max({i, 0}); s < min({(j) + 1, N}); ++s) {

int ip = j;
int lp = s;
for (int k = 0; k < N; ++k) {

for (int t = max({k, 0}); t < N; ++t) {

for (int l = max({j, 0}); l < min({(k) + 1, N}); ++l) {

int sp = k;
int kp = t;
int jp = l;
J[i][j][k][l][s][t] += J[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

int kp = i;
for (int j = 0; j < N; ++j) {

for (int s = max({i, 0}); s < min({(j) + 1, N}); ++s) {

for (int l = max({j, 0}); l < N; ++l) {

int ip = j;
int lp = s;
int jp = l;
for (int k = 0; k < N; ++k) {

for (int t = max({l, 0}); t < min({(k) + 1, N}); ++t) {

int sp = k;
int tp = t;
J[i][j][k][l][s][t] += J[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

int lp = i;
for (int j = 0; j < N; ++j) {

for (int s = max({i, 0}); s < min({(j) + 1, N}); ++s) {

int ip = j;
int tp = s;
for (int k = 0; k < N; ++k) {

for (int t = max({j, 0}); t < min({(k) + 1, N}); ++t) {

for (int l = max({k, 0}); l < N; ++l) {

int sp = k;
int kp = t;
int jp = l;
J[i][j][k][l][s][t] += J[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

int kp = i;
for (int j = 0; j < N; ++j) {

for (int s = max({i, 0}); s < min({(j) + 1, N}); ++s) {

int ip = j;
int tp = s;
for (int k = 0; k < N; ++k) {

for (int l = 0; l < min({(k) + 1, N}); ++l) {

int sp = k;
for (int t = max({j, 0}); t < min({(l) + 1, N}); ++t) {

int jp = l;
int lp = t;
J[i][j][k][l][s][t] += J[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int j = 0; j < N; ++j) {

int tp = i;
for (int l = max({j, 0}); l < N; ++l) {

int ip = j;
for (int k = 0; k < min({(j) + 1, N}); ++k) {

for (int t = max({l, 0}); t < N; ++t) {

int kp = l;
for (int s = max({i, 0}); s < min({(k) + 1, N}); ++s) {

int sp = k;
int lp = t;
int jp = s;
J[i][j][k][l][s][t] += J[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

int lp = i;
for (int j = 0; j < N; ++j) {

int ip = j;
for (int k = 0; k < min({(j) + 1, N}); ++k) {

for (int s = max({i, 0}); s < min({(k) + 1, N}); ++s) {

int sp = k;
int jp = s;
for (int l = 0; l < N; ++l) {

for (int t = max({j, 0}); t < min({(l) + 1, N}); ++t) {

int kp = l;
int tp = t;
J[i][j][k][l][s][t] += J[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int j = 0; j < N; ++j) {

int tp = i;
for (int t = max({j, 0}); t < N; ++t) {

int ip = j;
int jp = t;
for (int k = 0; k < N; ++k) {

for (int s = max({i, 0}); s < min({(k) + 1, N}); ++s) {

for (int l = max({k, 0}); l < min({(j) + 1, N}); ++l) {

int sp = k;
int lp = s;
int kp = l;
J[i][j][k][l][s][t] += J[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

int jp = i;
for (int j = 0; j < N; ++j) {

int ip = j;
for (int k = 0; k < N; ++k) {

for (int s = max({i, 0}); s < min({(k) + 1, N}); ++s) {

for (int l = max({k, 0}); l < N; ++l) {

int sp = k;
int lp = s;
for (int t = max({l, 0}); t < min({(j) + 1, N}); ++t) {

int kp = l;
int tp = t;
J[i][j][k][l][s][t] += J[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

int lp = i;
for (int j = 0; j < N; ++j) {

for (int l = max({j, 0}); l < N; ++l) {

int ip = j;
int kp = l;
for (int k = 0; k < N; ++k) {

for (int s = max({i, 0}); s < min({(k) + 1, N}); ++s) {

for (int t = max({k, 0}); t < min({(j) + 1, N}); ++t) {

int sp = k;
int tp = s;
int jp = t;
J[i][j][k][l][s][t] += J[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

int jp = i;
for (int j = 0; j < N; ++j) {

for (int l = 0; l < min({(j) + 1, N}); ++l) {

int ip = j;
int kp = l;
for (int k = 0; k < N; ++k) {

for (int s = max({i, 0}); s < min({(k) + 1, N}); ++s) {

for (int t = max({k, 0}); t < min({(l) + 1, N}); ++t) {

int sp = k;
int tp = s;
int lp = t;
J[i][j][k][l][s][t] += J[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int j = 0; j < N; ++j) {

int tp = i;
for (int l = 0; l < min({(j) + 1, N}); ++l) {

int ip = j;
for (int k = max({j, 0}); k < N; ++k) {

for (int s = max({i, 0}); s < min({(l) + 1, N}); ++s) {

int lp = l;
for (int t = max({k, 0}); t < N; ++t) {

int sp = k;
int jp = s;
int kp = t;
J[i][j][k][l][s][t] += J[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

int kp = i;
for (int j = 0; j < N; ++j) {

for (int l = 0; l < min({(j) + 1, N}); ++l) {

int ip = j;
for (int s = max({i, 0}); s < min({(l) + 1, N}); ++s) {

int lp = l;
int jp = s;
for (int k = 0; k < N; ++k) {

for (int t = max({j, 0}); t < min({(k) + 1, N}); ++t) {

int sp = k;
int tp = t;
J[i][j][k][l][s][t] += J[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int j = 0; j < N; ++j) {

int tp = i;
for (int t = max({j, 0}); t < N; ++t) {

int ip = j;
for (int k = 0; k < min({(j) + 1, N}); ++k) {

int jp = t;
for (int l = 0; l < min({(k) + 1, N}); ++l) {

int sp = k;
for (int s = max({i, 0}); s < min({(l) + 1, N}); ++s) {

int lp = l;
int kp = s;
J[i][j][k][l][s][t] += J[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

int jp = i;
for (int j = 0; j < N; ++j) {

int ip = j;
for (int k = 0; k < N; ++k) {

for (int t = max({k, 0}); t < min({(j) + 1, N}); ++t) {

for (int l = 0; l < min({(k) + 1, N}); ++l) {

int sp = k;
int tp = t;
for (int s = max({i, 0}); s < min({(l) + 1, N}); ++s) {

int lp = l;
int kp = s;
J[i][j][k][l][s][t] += J[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

int kp = i;
for (int j = 0; j < N; ++j) {

int ip = j;
for (int k = max({j, 0}); k < N; ++k) {

for (int l = 0; l < N; ++l) {

int sp = k;
for (int s = max({i, 0}); s < min({(l) + 1, N}); ++s) {

for (int t = max({l, 0}); t < min({(j) + 1, N}); ++t) {

int lp = l;
int tp = s;
int jp = t;
J[i][j][k][l][s][t] += J[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

int jp = i;
for (int j = 0; j < N; ++j) {

int ip = j;
for (int k = 0; k < min({(j) + 1, N}); ++k) {

for (int l = 0; l < N; ++l) {

int sp = k;
for (int s = max({i, 0}); s < min({(l) + 1, N}); ++s) {

for (int t = max({l, 0}); t < min({(k) + 1, N}); ++t) {

int lp = l;
int tp = s;
int kp = t;
J[i][j][k][l][s][t] += J[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int s = max({i, 0}); s < N; ++s) {

int lp = i;
int jp = s;
for (int j = 0; j < N; ++j) {

for (int t = max({s, 0}); t < min({(j) + 1, N}); ++t) {

int ip = j;
for (int k = max({j, 0}); k < N; ++k) {

int kp = t;
for (int l = max({k, 0}); l < N; ++l) {

int sp = k;
int tp = l;
J[i][j][k][l][s][t] += J[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int s = max({i, 0}); s < N; ++s) {

int kp = i;
int jp = s;
for (int j = 0; j < N; ++j) {

for (int t = max({s, 0}); t < min({(j) + 1, N}); ++t) {

int ip = j;
int lp = t;
for (int k = 0; k < N; ++k) {

for (int l = max({j, 0}); l < min({(k) + 1, N}); ++l) {

int sp = k;
int tp = l;
J[i][j][k][l][s][t] += J[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int s = max({i, 0}); s < N; ++s) {

int lp = i;
int kp = s;
for (int j = 0; j < N; ++j) {

for (int l = max({j, 0}); l < N; ++l) {

int ip = j;
for (int k = 0; k < min({(j) + 1, N}); ++k) {

int tp = l;
for (int t = max({s, 0}); t < min({(k) + 1, N}); ++t) {

int sp = k;
int jp = t;
J[i][j][k][l][s][t] += J[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int s = max({i, 0}); s < N; ++s) {

int jp = i;
int kp = s;
for (int j = 0; j < N; ++j) {

int ip = j;
for (int k = 0; k < N; ++k) {

for (int t = max({s, 0}); t < min({(k) + 1, N}); ++t) {

for (int l = max({k, 0}); l < min({(j) + 1, N}); ++l) {

int sp = k;
int lp = t;
int tp = l;
J[i][j][k][l][s][t] += J[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int s = max({i, 0}); s < N; ++s) {

int kp = i;
int lp = s;
for (int j = 0; j < N; ++j) {

for (int l = 0; l < min({(j) + 1, N}); ++l) {

int ip = j;
for (int k = max({j, 0}); k < N; ++k) {

for (int t = max({s, 0}); t < min({(l) + 1, N}); ++t) {

int tp = l;
int sp = k;
int jp = t;
J[i][j][k][l][s][t] += J[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int s = max({i, 0}); s < N; ++s) {

int jp = i;
int lp = s;
for (int j = 0; j < N; ++j) {

int ip = j;
for (int k = 0; k < min({(j) + 1, N}); ++k) {

for (int l = 0; l < min({(k) + 1, N}); ++l) {

int sp = k;
for (int t = max({s, 0}); t < min({(l) + 1, N}); ++t) {

int tp = l;
int kp = t;
J[i][j][k][l][s][t] += J[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

int sp = i;
for (int j = 0; j < N; ++j) {

for (int t = max({i, 0}); t < min({(j) + 1, N}); ++t) {

int ip = j;
for (int k = max({j, 0}); k < N; ++k) {

int lp = t;
for (int l = max({k, 0}); l < N; ++l) {

int tp = k;
for (int s = max({l, 0}); s < N; ++s) {

int jp = l;
int kp = s;
J[i][j][k][l][s][t] += J[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

int lp = i;
for (int j = 0; j < N; ++j) {

for (int t = max({i, 0}); t < min({(j) + 1, N}); ++t) {

int ip = j;
for (int k = max({j, 0}); k < N; ++k) {

int sp = t;
int tp = k;
for (int l = 0; l < N; ++l) {

for (int s = max({k, 0}); s < min({(l) + 1, N}); ++s) {

int jp = l;
int kp = s;
J[i][j][k][l][s][t] += J[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

int sp = i;
for (int j = 0; j < N; ++j) {

for (int t = max({i, 0}); t < min({(j) + 1, N}); ++t) {

int ip = j;
int kp = t;
for (int k = 0; k < N; ++k) {

for (int s = max({k, 0}); s < N; ++s) {

for (int l = max({j, 0}); l < min({(k) + 1, N}); ++l) {

int tp = k;
int lp = s;
int jp = l;
J[i][j][k][l][s][t] += J[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

int kp = i;
for (int j = 0; j < N; ++j) {

for (int t = max({i, 0}); t < min({(j) + 1, N}); ++t) {

for (int l = max({j, 0}); l < N; ++l) {

int ip = j;
int sp = t;
int jp = l;
for (int k = 0; k < N; ++k) {

for (int s = max({l, 0}); s < min({(k) + 1, N}); ++s) {

int tp = k;
int lp = s;
J[i][j][k][l][s][t] += J[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

int lp = i;
for (int j = 0; j < N; ++j) {

for (int t = max({i, 0}); t < min({(j) + 1, N}); ++t) {

int ip = j;
int kp = t;
for (int k = 0; k < N; ++k) {

for (int s = max({j, 0}); s < min({(k) + 1, N}); ++s) {

for (int l = max({k, 0}); l < N; ++l) {

int tp = k;
int sp = s;
int jp = l;
J[i][j][k][l][s][t] += J[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

int kp = i;
for (int j = 0; j < N; ++j) {

for (int t = max({i, 0}); t < min({(j) + 1, N}); ++t) {

int ip = j;
int lp = t;
for (int k = 0; k < N; ++k) {

for (int l = 0; l < min({(k) + 1, N}); ++l) {

int tp = k;
for (int s = max({j, 0}); s < min({(l) + 1, N}); ++s) {

int jp = l;
int sp = s;
J[i][j][k][l][s][t] += J[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

int sp = i;
for (int j = 0; j < N; ++j) {

for (int l = max({j, 0}); l < N; ++l) {

int ip = j;
for (int k = 0; k < min({(j) + 1, N}); ++k) {

for (int s = max({l, 0}); s < N; ++s) {

int kp = l;
for (int t = max({i, 0}); t < min({(k) + 1, N}); ++t) {

int tp = k;
int jp = s;
int lp = t;
J[i][j][k][l][s][t] += J[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

int lp = i;
for (int j = 0; j < N; ++j) {

int ip = j;
for (int k = 0; k < min({(j) + 1, N}); ++k) {

for (int t = max({i, 0}); t < min({(k) + 1, N}); ++t) {

int tp = k;
int sp = t;
for (int l = 0; l < N; ++l) {

for (int s = max({j, 0}); s < min({(l) + 1, N}); ++s) {

int kp = l;
int jp = s;
J[i][j][k][l][s][t] += J[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

int sp = i;
for (int j = 0; j < N; ++j) {

for (int s = max({j, 0}); s < N; ++s) {

int ip = j;
int lp = s;
for (int k = 0; k < N; ++k) {

for (int t = max({i, 0}); t < min({(k) + 1, N}); ++t) {

for (int l = max({k, 0}); l < min({(j) + 1, N}); ++l) {

int tp = k;
int jp = t;
int kp = l;
J[i][j][k][l][s][t] += J[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

int jp = i;
for (int j = 0; j < N; ++j) {

int ip = j;
for (int k = 0; k < N; ++k) {

for (int t = max({i, 0}); t < min({(k) + 1, N}); ++t) {

for (int l = max({k, 0}); l < N; ++l) {

int tp = k;
int sp = t;
for (int s = max({l, 0}); s < min({(j) + 1, N}); ++s) {

int kp = l;
int lp = s;
J[i][j][k][l][s][t] += J[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

int lp = i;
for (int j = 0; j < N; ++j) {

for (int l = max({j, 0}); l < N; ++l) {

int ip = j;
int kp = l;
for (int k = 0; k < N; ++k) {

for (int s = max({k, 0}); s < min({(j) + 1, N}); ++s) {

for (int t = max({i, 0}); t < min({(k) + 1, N}); ++t) {

int tp = k;
int sp = s;
int jp = t;
J[i][j][k][l][s][t] += J[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

int jp = i;
for (int j = 0; j < N; ++j) {

for (int l = 0; l < min({(j) + 1, N}); ++l) {

int ip = j;
int kp = l;
for (int k = 0; k < N; ++k) {

for (int s = max({k, 0}); s < min({(l) + 1, N}); ++s) {

for (int t = max({i, 0}); t < min({(k) + 1, N}); ++t) {

int tp = k;
int sp = s;
int lp = t;
J[i][j][k][l][s][t] += J[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

int sp = i;
for (int j = 0; j < N; ++j) {

for (int l = 0; l < min({(j) + 1, N}); ++l) {

int ip = j;
for (int k = max({j, 0}); k < N; ++k) {

for (int t = max({i, 0}); t < min({(l) + 1, N}); ++t) {

int lp = l;
for (int s = max({k, 0}); s < N; ++s) {

int tp = k;
int kp = t;
int jp = s;
J[i][j][k][l][s][t] += J[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

int kp = i;
for (int j = 0; j < N; ++j) {

for (int l = 0; l < min({(j) + 1, N}); ++l) {

int ip = j;
for (int t = max({i, 0}); t < min({(l) + 1, N}); ++t) {

int lp = l;
int sp = t;
for (int k = 0; k < N; ++k) {

for (int s = max({j, 0}); s < min({(k) + 1, N}); ++s) {

int tp = k;
int jp = s;
J[i][j][k][l][s][t] += J[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

int sp = i;
for (int j = 0; j < N; ++j) {

for (int s = max({j, 0}); s < N; ++s) {

int ip = j;
for (int k = 0; k < min({(j) + 1, N}); ++k) {

int kp = s;
for (int l = 0; l < min({(k) + 1, N}); ++l) {

int tp = k;
for (int t = max({i, 0}); t < min({(l) + 1, N}); ++t) {

int lp = l;
int jp = t;
J[i][j][k][l][s][t] += J[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

int jp = i;
for (int j = 0; j < N; ++j) {

int ip = j;
for (int k = 0; k < N; ++k) {

for (int s = max({k, 0}); s < min({(j) + 1, N}); ++s) {

for (int l = 0; l < min({(k) + 1, N}); ++l) {

int tp = k;
int kp = s;
for (int t = max({i, 0}); t < min({(l) + 1, N}); ++t) {

int lp = l;
int sp = t;
J[i][j][k][l][s][t] += J[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

int kp = i;
for (int j = 0; j < N; ++j) {

int ip = j;
for (int k = max({j, 0}); k < N; ++k) {

for (int l = 0; l < N; ++l) {

int tp = k;
for (int s = max({l, 0}); s < min({(j) + 1, N}); ++s) {

for (int t = max({i, 0}); t < min({(l) + 1, N}); ++t) {

int lp = l;
int sp = s;
int jp = t;
J[i][j][k][l][s][t] += J[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

int jp = i;
for (int j = 0; j < N; ++j) {

int ip = j;
for (int k = 0; k < min({(j) + 1, N}); ++k) {

for (int l = 0; l < N; ++l) {

int tp = k;
for (int s = max({l, 0}); s < min({(k) + 1, N}); ++s) {

for (int t = max({i, 0}); t < min({(l) + 1, N}); ++t) {

int lp = l;
int sp = s;
int kp = t;
J[i][j][k][l][s][t] += J[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

int lp = i;
for (int j = 0; j < N; ++j) {

for (int s = 0; s < min({(j) + 1, N}); ++s) {

int ip = j;
for (int k = max({j, 0}); k < N; ++k) {

for (int t = max({i, 0}); t < min({(s) + 1, N}); ++t) {

int jp = s;
for (int l = max({k, 0}); l < N; ++l) {

int tp = k;
int kp = t;
int sp = l;
J[i][j][k][l][s][t] += J[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

int kp = i;
for (int j = 0; j < N; ++j) {

for (int s = 0; s < min({(j) + 1, N}); ++s) {

int ip = j;
for (int t = max({i, 0}); t < min({(s) + 1, N}); ++t) {

int jp = s;
int lp = t;
for (int k = 0; k < N; ++k) {

for (int l = max({j, 0}); l < min({(k) + 1, N}); ++l) {

int tp = k;
int sp = l;
J[i][j][k][l][s][t] += J[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

int lp = i;
for (int j = 0; j < N; ++j) {

for (int l = max({j, 0}); l < N; ++l) {

int ip = j;
for (int k = 0; k < min({(j) + 1, N}); ++k) {

int sp = l;
for (int s = 0; s < min({(k) + 1, N}); ++s) {

int tp = k;
for (int t = max({i, 0}); t < min({(s) + 1, N}); ++t) {

int kp = s;
int jp = t;
J[i][j][k][l][s][t] += J[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

int jp = i;
for (int j = 0; j < N; ++j) {

int ip = j;
for (int k = 0; k < N; ++k) {

for (int s = 0; s < min({(k) + 1, N}); ++s) {

for (int l = max({k, 0}); l < min({(j) + 1, N}); ++l) {

int tp = k;
for (int t = max({i, 0}); t < min({(s) + 1, N}); ++t) {

int kp = s;
int sp = l;
int lp = t;
J[i][j][k][l][s][t] += J[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

int kp = i;
for (int j = 0; j < N; ++j) {

for (int l = 0; l < min({(j) + 1, N}); ++l) {

int ip = j;
for (int k = max({j, 0}); k < N; ++k) {

for (int s = 0; s < min({(l) + 1, N}); ++s) {

int sp = l;
int tp = k;
for (int t = max({i, 0}); t < min({(s) + 1, N}); ++t) {

int lp = s;
int jp = t;
J[i][j][k][l][s][t] += J[ip][jp][kp][lp][sp][tp];
}
}
}
}
}
}
for (int i = 0; i < N; ++i) {

int jp = i;
for (int j = 0; j < N; ++j) {

int ip = j;
for (int k = 0; k < min({(j) + 1, N}); ++k) {

for (int l = 0; l < min({(k) + 1, N}); ++l) {

int tp = k;
for (int s = 0; s < min({(l) + 1, N}); ++s) {

int sp = l;
for (int t = max({i, 0}); t < min({(s) + 1, N}); ++t) {

int lp = s;
int kp = t;
J[i][j][k][l][s][t] += J[ip][jp][kp][lp][sp][tp];
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