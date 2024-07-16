
#include <iostream>
#include <random>
#include <algorithm>
#include <chrono>

using namespace std;
using namespace std::chrono;

extern "C"
void fn(double ***** A, double * t, double * f, int N) {


long time_computation = 0, start_computation, end_computation;
start_computation = duration_cast<microseconds>(system_clock::now().time_since_epoch()).count();
for (int i = 0; i < N; ++i) {

for (int j = 0; j < min({(i) + 1, N}); ++j) {

for (int k = 0; k < N; ++k) {

for (int l = max({k, 0}); l < N; ++l) {

for (int r = max({l, 0}); r < N; ++r) {

A[i][j][k][l][r] += (f[j] * f[i] * t[k] * t[l] * t[r]);
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
for (int j = max({(i) + 1, 0}); j < N; ++j) {

int ip = j;
for (int k = 0; k < N; ++k) {

for (int r = 0; r < min({k, N}); ++r) {

for (int l = max({k, 0}); l < N; ++l) {

int lp = k;
int kp = r;
int rp = l;
A[i][j][k][l][r] = A[ip][jp][kp][lp][rp];
}
}
}
}
}
for (int i = 0; i < N; ++i) {

int jp = i;
for (int j = max({(i) + 1, 0}); j < N; ++j) {

int ip = j;
for (int k = 0; k < N; ++k) {

for (int l = 0; l < N; ++l) {

int kp = k;
for (int r = max({k, 0}); r < min({l, N}); ++r) {

int rp = l;
int lp = r;
A[i][j][k][l][r] = A[ip][jp][kp][lp][rp];
}
}
}
}
}
for (int i = 0; i < N; ++i) {

int jp = i;
for (int j = max({(i) + 1, 0}); j < N; ++j) {

int ip = j;
for (int k = 0; k < N; ++k) {

for (int l = 0; l < N; ++l) {

int rp = k;
for (int r = max({l, 0}); r < min({k, N}); ++r) {

int kp = l;
int lp = r;
A[i][j][k][l][r] = A[ip][jp][kp][lp][rp];
}
}
}
}
}
for (int i = 0; i < N; ++i) {

int jp = i;
for (int j = max({(i) + 1, 0}); j < N; ++j) {

int ip = j;
for (int k = 0; k < N; ++k) {

for (int l = 0; l < min({k, N}); ++l) {

int rp = k;
for (int r = 0; r < min({l, N}); ++r) {

int lp = l;
int kp = r;
A[i][j][k][l][r] = A[ip][jp][kp][lp][rp];
}
}
}
}
}
for (int i = 0; i < N; ++i) {

int jp = i;
for (int j = max({(i) + 1, 0}); j < N; ++j) {

int ip = j;
for (int k = 0; k < N; ++k) {

for (int r = max({k, 0}); r < N; ++r) {

for (int l = 0; l < min({k, N}); ++l) {

int lp = k;
int rp = r;
int kp = l;
A[i][j][k][l][r] = A[ip][jp][kp][lp][rp];
}
}
}
}
}
for (int i = 0; i < N; ++i) {

int ip = i;
for (int j = 0; j < min({(i) + 1, N}); ++j) {

int jp = j;
for (int k = 0; k < N; ++k) {

for (int r = 0; r < min({k, N}); ++r) {

for (int l = max({k, 0}); l < N; ++l) {

int lp = k;
int kp = r;
int rp = l;
A[i][j][k][l][r] = A[ip][jp][kp][lp][rp];
}
}
}
}
}
for (int i = 0; i < N; ++i) {

int ip = i;
for (int j = 0; j < min({(i) + 1, N}); ++j) {

int jp = j;
for (int k = 0; k < N; ++k) {

for (int l = 0; l < N; ++l) {

int kp = k;
for (int r = max({k, 0}); r < min({l, N}); ++r) {

int rp = l;
int lp = r;
A[i][j][k][l][r] = A[ip][jp][kp][lp][rp];
}
}
}
}
}
for (int i = 0; i < N; ++i) {

int ip = i;
for (int j = 0; j < min({(i) + 1, N}); ++j) {

int jp = j;
for (int k = 0; k < N; ++k) {

for (int l = 0; l < N; ++l) {

int rp = k;
for (int r = max({l, 0}); r < min({k, N}); ++r) {

int kp = l;
int lp = r;
A[i][j][k][l][r] = A[ip][jp][kp][lp][rp];
}
}
}
}
}
for (int i = 0; i < N; ++i) {

int ip = i;
for (int j = 0; j < min({(i) + 1, N}); ++j) {

int jp = j;
for (int k = 0; k < N; ++k) {

for (int l = 0; l < min({k, N}); ++l) {

int rp = k;
for (int r = 0; r < min({l, N}); ++r) {

int lp = l;
int kp = r;
A[i][j][k][l][r] = A[ip][jp][kp][lp][rp];
}
}
}
}
}
for (int i = 0; i < N; ++i) {

int ip = i;
for (int j = 0; j < min({(i) + 1, N}); ++j) {

int jp = j;
for (int k = 0; k < N; ++k) {

for (int r = max({k, 0}); r < N; ++r) {

for (int l = 0; l < min({k, N}); ++l) {

int lp = k;
int rp = r;
int kp = l;
A[i][j][k][l][r] = A[ip][jp][kp][lp][rp];
}
}
}
}
}
for (int i = 0; i < N; ++i) {

int jp = i;
for (int j = max({(i) + 1, 0}); j < N; ++j) {

int ip = j;
for (int k = 0; k < N; ++k) {

for (int l = max({k, 0}); l < N; ++l) {

int kp = k;
for (int r = max({l, 0}); r < N; ++r) {

int lp = l;
int rp = r;
A[i][j][k][l][r] = A[ip][jp][kp][lp][rp];
}
}
}
}
}
end_reconstruction = duration_cast<microseconds>(system_clock::now().time_since_epoch()).count();
time_reconstruction = end_reconstruction - start_reconstruction;
cout << time_reconstruction << endl;

}