
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
double **B = new double*[N];
for (size_t i = 0; i < N; ++i) {
B[i] = new double[N];

for (size_t j = 0; j < N; ++j) {
B[i][j] = 0.0;
}
}
double **C = new double*[N];
for (size_t i = 0; i < N; ++i) {
C[i] = new double[N];

for (size_t j = 0; j < N; ++j) {
C[i][j] = 0.0;
}
}

long time_computation = 0, start_computation, end_computation;
start_computation = duration_cast<microseconds>(system_clock::now().time_since_epoch()).count();
{
for (int i = 0; i < N; ++i) {

for (int j = max({i, 0}); j < N; ++j) {

A[i][j] += (f[i] * f[j]);
}
}
}
{
for (int i = 0; i < N; ++i) {

for (int j = max({i, 0}); j < N; ++j) {

B[i][j] += (g[i] * g[j]);
}
}
}
{
for (int i = 0; i < N; ++i) {

for (int j = max({i, 0}); j < N; ++j) {

C[i][j] += (f[i] * f[j]);
}
}
}
{
for (int i = 0; i < N; ++i) {

for (int j = max({i, 0}); j < N; ++j) {

C[i][j] += (g[i] * g[j]);
}
}
}
end_computation = duration_cast<microseconds>(system_clock::now().time_since_epoch()).count();
time_computation = end_computation - start_computation;
cout << time_computation << endl;
long time_reconstruction = 0, start_reconstruction, end_reconstruction;
start_reconstruction = duration_cast<microseconds>(system_clock::now().time_since_epoch()).count();
{
for (int i = 0; i < N; ++i) {

int jp = i;
for (int j = 0; j < min({i, N}); ++j) {

int ip = j;
A[i][j] = A[ip][jp];
}
}
}
{
for (int i = 0; i < N; ++i) {

int jp = i;
for (int j = 0; j < min({i, N}); ++j) {

int ip = j;
B[i][j] = B[ip][jp];
}
}
}
{
for (int i = 0; i < N; ++i) {

int jp = i;
for (int j = 0; j < min({i, N}); ++j) {

int ip = j;
C[i][j] = C[ip][jp];
}
}
}
end_reconstruction = duration_cast<microseconds>(system_clock::now().time_since_epoch()).count();
time_reconstruction = end_reconstruction - start_reconstruction;
cout << time_reconstruction << endl;
cerr << A[0][0] << endl;
cerr << f[0] << endl;
cerr << B[0][0] << endl;
cerr << g[0] << endl;
cerr << C[0][0] << endl;
for (size_t i0 = 0; i0 < N; ++i0) {delete[] A[i0];
}delete[] A;
delete[] f;
for (size_t i0 = 0; i0 < N; ++i0) {delete[] B[i0];
}delete[] B;
delete[] g;
for (size_t i0 = 0; i0 < N; ++i0) {delete[] C[i0];
}delete[] C;
return 0;
}