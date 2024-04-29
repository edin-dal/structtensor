
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

double **D = new double*[N];
for (size_t i = 0; i < N; ++i) {
D[i] = new double[N];
for (size_t j = 0; j < N; ++j) {
int flag5 = 0 <= i && N > i && 0 <= j && N > j;
if (flag5) {
D[i][j] = (double) 1.0;
} else {
D[i][j] = 0.0;
}
}
}

double *g = new double[N];
for (size_t i = 0; i < N; ++i) {
int flag6 = 0 <= i && N > i;
if (flag6) {
g[i] = (double) 1.0;
} else {
g[i] = 0.0;
}
}

double ***E = new double**[N];
for (size_t i = 0; i < N; ++i) {
E[i] = new double*[N];
for (size_t j = 0; j < N; ++j) {
E[i][j] = new double[N];
for (size_t k = 0; k < N; ++k) {
int flag7 = 0 <= i && N > i && 0 <= j && N > j && 0 <= k && N > k;
if (flag7) {
E[i][j][k] = (double) 1.0;
} else {
E[i][j][k] = 0.0;
}
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
int flag8 = 0 <= i && N > i && 0 <= j && N > j && 0 <= k && N > k && 0 <= l && N > l;
if (flag8) {
F[i][j][k][l] = (double) 1.0;
} else {
F[i][j][k][l] = 0.0;
}
}
}
}
}

double **H = new double*[N];
for (size_t i = 0; i < N; ++i) {
H[i] = new double[N];
for (size_t j = 0; j < N; ++j) {
int flag9 = 0 <= i && N > i && 0 <= j && N > j;
if (flag9) {
H[i][j] = (double) 1.0;
} else {
H[i][j] = 0.0;
}
}
}

double ***I = new double**[N];
for (size_t i = 0; i < N; ++i) {
I[i] = new double*[N];
for (size_t j = 0; j < N; ++j) {
I[i][j] = new double[N];
for (size_t k = 0; k < N; ++k) {
int flag10 = 0 <= i && N > i && 0 <= j && N > j && 0 <= k && N > k;
if (flag10) {
I[i][j][k] = (double) 1.0;
} else {
I[i][j][k] = 0.0;
}
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
int flag11 = 0 <= i && N > i && 0 <= j && N > j && 0 <= k && N > k && 0 <= l && N > l;
if (flag11) {
J[i][j][k][l] = (double) 1.0;
} else {
J[i][j][k][l] = 0.0;
}
}
}
}
}

long time = 0, start, end;
start = duration_cast<microseconds>(system_clock::now().time_since_epoch()).count();



for (int i = 0; i < N; ++i) {
auto &cm12 = A[i];

auto &cm13 = f[i];

for (int j = i; j < N; ++j) {


cm12[j] += (f[j] * cm13);
}
}




for (int i = 0; i < N; ++i) {
auto &cm16 = B[i];

auto &cm17 = f[i];

for (int j = 0; j < N; ++j) {
auto &cm18 = cm16[j];

auto &cm19 = f[j];

for (int k = j; k < std::min({N, (i + 1)}); ++k) {


cm18[k] += (f[k] * cm19 * cm17);
}
}
}




for (int i = 0; i < N; ++i) {
auto &cm40 = C[i];

auto &cm41 = f[i];

for (int j = 0; j < N; ++j) {
auto &cm42 = cm40[j];

auto &cm43 = f[j];

for (int k = j; k < N; ++k) {
auto &cm44 = cm42[k];

auto &cm45 = f[k];

for (int l = k; l < std::min({N, (i + 1)}); ++l) {


cm44[l] += (cm45 * cm41 * f[l] * cm43);
}
}
}
}




for (int i = 0; i < N; ++i) {
auto &cm184 = D[i];

auto &cm185 = g[i];

for (int j = i; j < N; ++j) {


cm184[j] += (cm185 * g[j]);
}
}




for (int i = 0; i < N; ++i) {
auto &cm188 = E[i];

auto &cm189 = g[i];

for (int j = 0; j < N; ++j) {
auto &cm190 = cm188[j];

auto &cm191 = g[j];

for (int k = j; k < std::min({N, (i + 1)}); ++k) {


cm190[k] += (cm189 * cm191 * g[k]);
}
}
}




for (int i = 0; i < N; ++i) {
auto &cm212 = F[i];

auto &cm213 = g[i];

for (int j = 0; j < N; ++j) {
auto &cm214 = cm212[j];

auto &cm215 = g[j];

for (int k = j; k < N; ++k) {
auto &cm216 = cm214[k];

auto &cm217 = g[k];

for (int l = k; l < std::min({N, (i + 1)}); ++l) {


cm216[l] += (g[l] * cm213 * cm215 * cm217);
}
}
}
}




for (int i = 0; i < N; ++i) {
auto &cm356 = H[i];

auto &cm357 = f[i];
auto &cm358 = g[i];

for (int j = i; j < N; ++j) {
double tmp = 0.0;



tmp += (f[j] * cm357);

tmp += (cm358 * g[j]);

cm356[j] += tmp;
}
}




for (int i = 0; i < N; ++i) {
auto &cm361 = I[i];

auto &cm362 = f[i];
auto &cm363 = g[i];

for (int j = 0; j < N; ++j) {
auto &cm364 = cm361[j];

auto &cm365 = f[j];
auto &cm366 = g[j];

for (int k = j; k < std::min({N, (i + 1)}); ++k) {
double tmp = 0.0;



tmp += (f[k] * cm365 * cm362);

tmp += (cm363 * cm366 * g[k]);

cm364[k] += tmp;
}
}
}




for (int i = 0; i < N; ++i) {
auto &cm387 = J[i];

auto &cm388 = f[i];
auto &cm389 = g[i];

for (int j = 0; j < N; ++j) {
auto &cm390 = cm387[j];

auto &cm391 = f[j];
auto &cm392 = g[j];

for (int k = j; k < N; ++k) {
auto &cm393 = cm390[k];

auto &cm394 = f[k];
auto &cm395 = g[k];

for (int l = k; l < std::min({N, (i + 1)}); ++l) {
double tmp = 0.0;



tmp += (cm394 * cm388 * f[l] * cm391);

tmp += (g[l] * cm389 * cm392 * cm395);

cm393[l] += tmp;
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
cerr << D[0][0] << endl;
cerr << g[0] << endl;
cerr << g[0] << endl;
cerr << E[0][0][0] << endl;
cerr << g[0] << endl;
cerr << F[0][0][0][0] << endl;
cerr << g[0] << endl;
cerr << H[0][0] << endl;
cerr << I[0][0][0] << endl;
cerr << J[0][0][0][0] << endl;
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
delete[] D[i0];
}
delete[] D;
delete[] g;
for (size_t i0 = 0; i0 < N; ++i0) {
for (size_t i1 = 0; i1 < N; ++i1) {
delete[] E[i0][i1];
}
delete[] E[i0];
}
delete[] E;
for (size_t i0 = 0; i0 < N; ++i0) {
for (size_t i1 = 0; i1 < N; ++i1) {
for (size_t i2 = 0; i2 < N; ++i2) {
delete[] F[i0][i1][i2];
}
delete[] F[i0][i1];
}
delete[] F[i0];
}
delete[] F;
for (size_t i0 = 0; i0 < N; ++i0) {
delete[] H[i0];
}
delete[] H;
for (size_t i0 = 0; i0 < N; ++i0) {
for (size_t i1 = 0; i1 < N; ++i1) {
delete[] I[i0][i1];
}
delete[] I[i0];
}
delete[] I;
for (size_t i0 = 0; i0 < N; ++i0) {
for (size_t i1 = 0; i1 < N; ++i1) {
for (size_t i2 = 0; i2 < N; ++i2) {
delete[] J[i0][i1][i2];
}
delete[] J[i0][i1];
}
delete[] J[i0];
}
delete[] J;
return 0;
}