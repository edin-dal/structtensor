
#include <iostream>
#include <random>
#include <algorithm>
#include <chrono>

using namespace std;
using namespace std::chrono;

int main(int argc, char **argv){
    srand(0);


const int N = atoi(argv[1]);

double **A = new double*[N];
for (size_t i = 0; i < N; ++i) {
A[i] = new double[N];
for (size_t j = 0; j < N; ++j) {
int flag1 = 0 <= i && N > i && 0 <= j && N > j;
if (flag1) {
A[i][j] = (double) 1.0;
} else {
A[i][j] = 0.0;
}
}
}

double *f = new double[N];
for (size_t i = 0; i < N; ++i) {
int flag2 = 0 <= i && N > i;
if (flag2) {
f[i] = (double) 1.0;
} else {
f[i] = 0.0;
}
}

double ***B = new double**[N];
for (size_t i = 0; i < N; ++i) {
B[i] = new double*[N];
for (size_t j = 0; j < N; ++j) {
B[i][j] = new double[N];
for (size_t k = 0; k < N; ++k) {
int flag3 = 0 <= i && N > i && 0 <= j && N > j && 0 <= k && N > k;
if (flag3) {
B[i][j][k] = (double) 1.0;
} else {
B[i][j][k] = 0.0;
}
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
int flag4 = 0 <= i && N > i && 0 <= j && N > j && 0 <= k && N > k && 0 <= l && N > l;
if (flag4) {
C[i][j][k][l] = (double) 1.0;
} else {
C[i][j][k][l] = 0.0;
}
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
int flag5 = 0 <= i && N > i && 0 <= j && N > j && 0 <= k && N > k && 0 <= l && N > l && 0 <= s && N > s;
if (flag5) {
D[i][j][k][l][s] = (double) 1.0;
} else {
D[i][j][k][l][s] = 0.0;
}
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
int flag6 = 0 <= i && N > i && 0 <= j && N > j && 0 <= k && N > k && 0 <= l && N > l && 0 <= s && N > s && 0 <= t && N > t;
if (flag6) {
E[i][j][k][l][s][t] = (double) 1.0;
} else {
E[i][j][k][l][s][t] = 0.0;
}
}
}
}
}
}
}

long time = 0, start, end;
start = duration_cast<microseconds>(system_clock::now().time_since_epoch()).count();



for (int i = 0; i < N; ++i) {
auto &cm7 = A[i];

auto &cm8 = f[i];

for (int j = i; j < N; ++j) {


cm7[j] += (f[j] * cm8);
}
}




for (int i = 0; i < N; ++i) {
auto &cm11 = B[i];

auto &cm12 = f[i];

for (int j = 0; j < N; ++j) {
auto &cm13 = cm11[j];

auto &cm14 = f[j];

for (int k = j; k < std::min({N, (i + 1)}); ++k) {


cm13[k] += (f[k] * cm14 * cm12);
}
}
}




for (int i = 0; i < N; ++i) {
auto &cm35 = C[i];

auto &cm36 = f[i];

for (int j = 0; j < N; ++j) {
auto &cm37 = cm35[j];

auto &cm38 = f[j];

for (int k = j; k < N; ++k) {
auto &cm39 = cm37[k];

auto &cm40 = f[k];

for (int l = k; l < std::min({N, (i + 1)}); ++l) {


cm39[l] += (cm40 * cm36 * f[l] * cm38);
}
}
}
}




for (int i = 0; i < N; ++i) {
auto &cm179 = D[i];

auto &cm180 = f[i];

for (int j = 0; j < N; ++j) {
auto &cm181 = cm179[j];

auto &cm182 = f[j];

for (int k = j; k < N; ++k) {
auto &cm183 = cm181[k];

auto &cm184 = f[k];

for (int l = k; l < N; ++l) {
auto &cm185 = cm183[l];

auto &cm186 = f[l];

for (int s = l; s < std::min({N, (i + 1)}); ++s) {


cm185[s] += (cm184 * cm180 * cm186 * cm182 * f[s]);
}
}
}
}
}




for (int i = 0; i < N; ++i) {
auto &cm1139 = E[i];

auto &cm1140 = f[i];

for (int j = 0; j < N; ++j) {
auto &cm1141 = cm1139[j];

auto &cm1142 = f[j];

for (int k = j; k < N; ++k) {
auto &cm1143 = cm1141[k];

auto &cm1144 = f[k];

for (int l = k; l < N; ++l) {
auto &cm1145 = cm1143[l];

auto &cm1146 = f[l];

for (int s = l; s < N; ++s) {
auto &cm1147 = cm1145[s];

auto &cm1148 = f[s];

for (int t = s; t < std::min({N, (i + 1)}); ++t) {


cm1147[t] += (cm1144 * f[t] * cm1146 * cm1142 * cm1140 * cm1148);
}
}
}
}
}
}

end = duration_cast<microseconds>(system_clock::now().time_since_epoch()).count();
time = end - start;
cout << time << endl;
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
for (size_t i0 = 0; i0 < N; ++i0) {
delete[] A[i0];
}
delete[] A;
delete[] f;
for (size_t i0 = 0; i0 < N; ++i0) {
for (size_t i1 = 0; i1 < N; ++i1) {
delete[] B[i0][i1];
}
delete[] B[i0];
}
delete[] B;
for (size_t i0 = 0; i0 < N; ++i0) {
for (size_t i1 = 0; i1 < N; ++i1) {
for (size_t i2 = 0; i2 < N; ++i2) {
delete[] C[i0][i1][i2];
}
delete[] C[i0][i1];
}
delete[] C[i0];
}
delete[] C;
for (size_t i0 = 0; i0 < N; ++i0) {
for (size_t i1 = 0; i1 < N; ++i1) {
for (size_t i2 = 0; i2 < N; ++i2) {
for (size_t i3 = 0; i3 < N; ++i3) {
delete[] D[i0][i1][i2][i3];
}
delete[] D[i0][i1][i2];
}
delete[] D[i0][i1];
}
delete[] D[i0];
}
delete[] D;
for (size_t i0 = 0; i0 < N; ++i0) {
for (size_t i1 = 0; i1 < N; ++i1) {
for (size_t i2 = 0; i2 < N; ++i2) {
for (size_t i3 = 0; i3 < N; ++i3) {
for (size_t i4 = 0; i4 < N; ++i4) {
delete[] E[i0][i1][i2][i3][i4];
}
delete[] E[i0][i1][i2][i3];
}
delete[] E[i0][i1][i2];
}
delete[] E[i0][i1];
}
delete[] E[i0];
}
delete[] E;
return 0;
}