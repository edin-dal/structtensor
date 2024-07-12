
#include <iostream>
#include <random>
#include <algorithm>
#include <chrono>

using namespace std;
using namespace std::chrono;

extern "C"
void fn(double ** B, double * f, double * A, double ** C, int N) {


long time_computation = 0, start_computation, end_computation;
start_computation = duration_cast<microseconds>(system_clock::now().time_since_epoch()).count();
for (int i = 0; i < N; ++i) {

for (int j = max({i, 0}); j < N; ++j) {

B[i][j] = (f[i] * f[j]);
}
}
for (int i = 0; i < N; ++i) {

for (int j = max({i, 0}); j < N; ++j) {

A[i] = (f[i] * f[j]);
}
}
for (int i = 0; i < N; ++i) {

for (int j = 0; j < min({i, N, (i) + 1}); ++j) {

A[i] += (f[j] * f[i]);
}
}
for (int i = 0; i < N; ++i) {

for (int i3 = max({i, 0}); i3 < N; ++i3) {

for (int j = max({i, 0}); j < N; ++j) {

for (int i4 = max({j, 0}); i4 < N; ++i4) {

C[i][j] = (1. / f[i] * 1. / f[i3] * 1. / f[j] * 1. / f[i4]);
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int i3 = max({i, 0}); i3 < N; ++i3) {

for (int j = max({i, 0}); j < N; ++j) {

for (int i4 = 0; i4 < min({j, N, (j) + 1}); ++i4) {

C[i][j] += (1. / f[i] * 1. / f[i3] * 1. / f[i4] * 1. / f[j]);
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int i3 = 0; i3 < min({i, N, (i) + 1}); ++i3) {

for (int j = max({i, 0}); j < N; ++j) {

for (int i4 = max({j, 0}); i4 < N; ++i4) {

C[i][j] += (1. / f[i3] * 1. / f[i] * 1. / f[j] * 1. / f[i4]);
}
}
}
}
for (int i = 0; i < N; ++i) {

for (int i3 = 0; i3 < min({i, N, (i) + 1}); ++i3) {

for (int j = max({i, 0}); j < N; ++j) {

for (int i4 = 0; i4 < min({j, N, (j) + 1}); ++i4) {

C[i][j] += (1. / f[i3] * 1. / f[i] * 1. / f[i4] * 1. / f[j]);
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
B[i][j] = B[ip][jp];
}
}

for (int i = 0; i < N; ++i) {

int jp = i;
for (int j = 0; j < min({i, N}); ++j) {

int ip = j;
C[i][j] = C[ip][jp];
}
}
end_reconstruction = duration_cast<microseconds>(system_clock::now().time_since_epoch()).count();
time_reconstruction = end_reconstruction - start_reconstruction;
cout << time_reconstruction << endl;

}