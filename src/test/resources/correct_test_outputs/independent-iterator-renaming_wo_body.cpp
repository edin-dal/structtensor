
#include <iostream>
#include <random>
#include <algorithm>
#include <chrono>

using namespace std;
using namespace std::chrono;

extern "C"
void fn(double * f, double * t, double **** C, int N) {


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
C[i][j][k][l] = C[ip][jp][kp][lp];
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
C[i][j][k][l] = C[ip][jp][kp][lp];
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
C[i][j][k][l] = C[ip][jp][kp][lp];
}
}
}
}
end_reconstruction = duration_cast<microseconds>(system_clock::now().time_since_epoch()).count();
time_reconstruction = end_reconstruction - start_reconstruction;
cout << time_reconstruction << endl;

}