
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
double *****D = new double****[N];
for (size_t i = 0; i < N; ++i) {
D[i] = new double***[N];

for (size_t j = 0; j < N; ++j) {
D[i][j] = new double**[N];

for (size_t k = 0; k < N; ++k) {
D[i][j][k] = new double*[N];

for (size_t l = 0; l < N; ++l) {
D[i][j][k][l] = new double[N];

for (size_t s = 0; s < N; ++s) {
D[i][j][k][l][s] = 0.0;
}
}
}
}
}
double ******E = new double*****[N];
for (size_t i = 0; i < N; ++i) {
E[i] = new double****[N];

for (size_t j = 0; j < N; ++j) {
E[i][j] = new double***[N];

for (size_t k = 0; k < N; ++k) {
E[i][j][k] = new double**[N];

for (size_t l = 0; l < N; ++l) {
E[i][j][k][l] = new double*[N];

for (size_t s = 0; s < N; ++s) {
E[i][j][k][l][s] = new double[N];

for (size_t t = 0; t < N; ++t) {
E[i][j][k][l][s][t] = 0.0;
}
}
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
end_reconstruction = duration_cast<microseconds>(system_clock::now().time_since_epoch()).count();
time_reconstruction = end_reconstruction - start_reconstruction;
cout << time_reconstruction << endl;
cerr << A[0][0] << endl;
cerr << f[0] << endl;
cerr << f[0] << endl;
cerr << B[0][0][0] << endl;
cerr << f[0] << endl;
cerr << C[0][0][0][0] << endl;
cerr << f[0] << endl;
cerr << D[0][0][0][0][0] << endl;
cerr << f[0] << endl;
cerr << E[0][0][0][0][0][0] << endl;
cerr << f[0] << endl;
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
for (size_t i0 = 0; i0 < N; ++i0) {
for (size_t i1 = 0; i1 < N; ++i1) {
for (size_t i2 = 0; i2 < N; ++i2) {
for (size_t i3 = 0; i3 < N; ++i3) {delete[] D[i0][i1][i2][i3];
}
delete[] D[i0][i1][i2];
}
delete[] D[i0][i1];
}
delete[] D[i0];
}delete[] D;
for (size_t i0 = 0; i0 < N; ++i0) {
for (size_t i1 = 0; i1 < N; ++i1) {
for (size_t i2 = 0; i2 < N; ++i2) {
for (size_t i3 = 0; i3 < N; ++i3) {
for (size_t i4 = 0; i4 < N; ++i4) {delete[] E[i0][i1][i2][i3][i4];
}
delete[] E[i0][i1][i2][i3];
}
delete[] E[i0][i1][i2];
}
delete[] E[i0][i1];
}
delete[] E[i0];
}delete[] E;
return 0;
}