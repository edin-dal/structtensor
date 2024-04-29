
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

double **F = new double*[N];
for (size_t i = 0; i < N; ++i) {
F[i] = new double[N];
for (size_t j = 0; j < N; ++j) {
int flag7 = 0 <= i && N > i && 0 <= j && N > j;
if (flag7) {
F[i][j] = (double) 1.0;
} else {
F[i][j] = 0.0;
}
}
}

double *g = new double[N];
for (size_t i = 0; i < N; ++i) {
int flag8 = 0 <= i && N > i;
if (flag8) {
g[i] = (double) 1.0;
} else {
g[i] = 0.0;
}
}

double ***G = new double**[N];
for (size_t i = 0; i < N; ++i) {
G[i] = new double*[N];
for (size_t j = 0; j < N; ++j) {
G[i][j] = new double[N];
for (size_t k = 0; k < N; ++k) {
int flag9 = 0 <= i && N > i && 0 <= j && N > j && 0 <= k && N > k;
if (flag9) {
G[i][j][k] = (double) 1.0;
} else {
G[i][j][k] = 0.0;
}
}
}
}

double ****H = new double***[N];
for (size_t i = 0; i < N; ++i) {
H[i] = new double**[N];
for (size_t j = 0; j < N; ++j) {
H[i][j] = new double*[N];
for (size_t k = 0; k < N; ++k) {
H[i][j][k] = new double[N];
for (size_t l = 0; l < N; ++l) {
int flag10 = 0 <= i && N > i && 0 <= j && N > j && 0 <= k && N > k && 0 <= l && N > l;
if (flag10) {
H[i][j][k][l] = (double) 1.0;
} else {
H[i][j][k][l] = 0.0;
}
}
}
}
}

double *****I = new double****[N];
for (size_t i = 0; i < N; ++i) {
I[i] = new double***[N];
for (size_t j = 0; j < N; ++j) {
I[i][j] = new double**[N];
for (size_t k = 0; k < N; ++k) {
I[i][j][k] = new double*[N];
for (size_t l = 0; l < N; ++l) {
I[i][j][k][l] = new double[N];
for (size_t s = 0; s < N; ++s) {
int flag11 = 0 <= i && N > i && 0 <= j && N > j && 0 <= k && N > k && 0 <= l && N > l && 0 <= s && N > s;
if (flag11) {
I[i][j][k][l][s] = (double) 1.0;
} else {
I[i][j][k][l][s] = 0.0;
}
}
}
}
}
}

double ******J = new double*****[N];
for (size_t i = 0; i < N; ++i) {
J[i] = new double****[N];
for (size_t j = 0; j < N; ++j) {
J[i][j] = new double***[N];
for (size_t k = 0; k < N; ++k) {
J[i][j][k] = new double**[N];
for (size_t l = 0; l < N; ++l) {
J[i][j][k][l] = new double*[N];
for (size_t s = 0; s < N; ++s) {
J[i][j][k][l][s] = new double[N];
for (size_t t = 0; t < N; ++t) {
int flag12 = 0 <= i && N > i && 0 <= j && N > j && 0 <= k && N > k && 0 <= l && N > l && 0 <= s && N > s && 0 <= t && N > t;
if (flag12) {
J[i][j][k][l][s][t] = (double) 1.0;
} else {
J[i][j][k][l][s][t] = 0.0;
}
}
}
}
}
}
}

double **K = new double*[N];
for (size_t i = 0; i < N; ++i) {
K[i] = new double[N];
for (size_t j = 0; j < N; ++j) {
int flag13 = 0 <= i && N > i && 0 <= j && N > j;
if (flag13) {
K[i][j] = (double) 1.0;
} else {
K[i][j] = 0.0;
}
}
}

double ***L = new double**[N];
for (size_t i = 0; i < N; ++i) {
L[i] = new double*[N];
for (size_t j = 0; j < N; ++j) {
L[i][j] = new double[N];
for (size_t k = 0; k < N; ++k) {
int flag14 = 0 <= i && N > i && 0 <= j && N > j && 0 <= k && N > k;
if (flag14) {
L[i][j][k] = (double) 1.0;
} else {
L[i][j][k] = 0.0;
}
}
}
}

double ****M = new double***[N];
for (size_t i = 0; i < N; ++i) {
M[i] = new double**[N];
for (size_t j = 0; j < N; ++j) {
M[i][j] = new double*[N];
for (size_t k = 0; k < N; ++k) {
M[i][j][k] = new double[N];
for (size_t l = 0; l < N; ++l) {
int flag15 = 0 <= i && N > i && 0 <= j && N > j && 0 <= k && N > k && 0 <= l && N > l;
if (flag15) {
M[i][j][k][l] = (double) 1.0;
} else {
M[i][j][k][l] = 0.0;
}
}
}
}
}

double *****P = new double****[N];
for (size_t i = 0; i < N; ++i) {
P[i] = new double***[N];
for (size_t j = 0; j < N; ++j) {
P[i][j] = new double**[N];
for (size_t k = 0; k < N; ++k) {
P[i][j][k] = new double*[N];
for (size_t l = 0; l < N; ++l) {
P[i][j][k][l] = new double[N];
for (size_t s = 0; s < N; ++s) {
int flag16 = 0 <= i && N > i && 0 <= j && N > j && 0 <= k && N > k && 0 <= l && N > l && 0 <= s && N > s;
if (flag16) {
P[i][j][k][l][s] = (double) 1.0;
} else {
P[i][j][k][l][s] = 0.0;
}
}
}
}
}
}

double ******O = new double*****[N];
for (size_t i = 0; i < N; ++i) {
O[i] = new double****[N];
for (size_t j = 0; j < N; ++j) {
O[i][j] = new double***[N];
for (size_t k = 0; k < N; ++k) {
O[i][j][k] = new double**[N];
for (size_t l = 0; l < N; ++l) {
O[i][j][k][l] = new double*[N];
for (size_t s = 0; s < N; ++s) {
O[i][j][k][l][s] = new double[N];
for (size_t t = 0; t < N; ++t) {
int flag17 = 0 <= i && N > i && 0 <= j && N > j && 0 <= k && N > k && 0 <= l && N > l && 0 <= s && N > s && 0 <= t && N > t;
if (flag17) {
O[i][j][k][l][s][t] = (double) 1.0;
} else {
O[i][j][k][l][s][t] = 0.0;
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
auto &cm18 = A[i];

auto &cm19 = f[i];

for (int j = i; j < N; ++j) {


cm18[j] += (f[j] * cm19);
}
}




for (int i = 0; i < N; ++i) {
auto &cm22 = B[i];

auto &cm23 = f[i];

for (int j = 0; j < N; ++j) {
auto &cm24 = cm22[j];

auto &cm25 = f[j];

for (int k = j; k < std::min({N, (i + 1)}); ++k) {


cm24[k] += (f[k] * cm25 * cm23);
}
}
}




for (int i = 0; i < N; ++i) {
auto &cm46 = C[i];

auto &cm47 = f[i];

for (int j = 0; j < N; ++j) {
auto &cm48 = cm46[j];

auto &cm49 = f[j];

for (int k = j; k < N; ++k) {
auto &cm50 = cm48[k];

auto &cm51 = f[k];

for (int l = k; l < std::min({N, (i + 1)}); ++l) {


cm50[l] += (cm51 * cm47 * f[l] * cm49);
}
}
}
}




for (int i = 0; i < N; ++i) {
auto &cm190 = D[i];

auto &cm191 = f[i];

for (int j = 0; j < N; ++j) {
auto &cm192 = cm190[j];

auto &cm193 = f[j];

for (int k = j; k < N; ++k) {
auto &cm194 = cm192[k];

auto &cm195 = f[k];

for (int l = k; l < N; ++l) {
auto &cm196 = cm194[l];

auto &cm197 = f[l];

for (int s = l; s < std::min({N, (i + 1)}); ++s) {


cm196[s] += (cm195 * cm191 * cm197 * cm193 * f[s]);
}
}
}
}
}




for (int i = 0; i < N; ++i) {
auto &cm1150 = E[i];

auto &cm1151 = f[i];

for (int j = 0; j < N; ++j) {
auto &cm1152 = cm1150[j];

auto &cm1153 = f[j];

for (int k = j; k < N; ++k) {
auto &cm1154 = cm1152[k];

auto &cm1155 = f[k];

for (int l = k; l < N; ++l) {
auto &cm1156 = cm1154[l];

auto &cm1157 = f[l];

for (int s = l; s < N; ++s) {
auto &cm1158 = cm1156[s];

auto &cm1159 = f[s];

for (int t = s; t < std::min({N, (i + 1)}); ++t) {


cm1158[t] += (cm1155 * f[t] * cm1157 * cm1153 * cm1151 * cm1159);
}
}
}
}
}
}




for (int i = 0; i < N; ++i) {
auto &cm8350 = F[i];

auto &cm8351 = g[i];

for (int j = i; j < N; ++j) {


cm8350[j] += (cm8351 * g[j]);
}
}




for (int i = 0; i < N; ++i) {
auto &cm8354 = G[i];

auto &cm8355 = g[i];

for (int j = 0; j < N; ++j) {
auto &cm8356 = cm8354[j];

auto &cm8357 = g[j];

for (int k = j; k < std::min({N, (i + 1)}); ++k) {


cm8356[k] += (cm8355 * cm8357 * g[k]);
}
}
}




for (int i = 0; i < N; ++i) {
auto &cm8378 = H[i];

auto &cm8379 = g[i];

for (int j = 0; j < N; ++j) {
auto &cm8380 = cm8378[j];

auto &cm8381 = g[j];

for (int k = j; k < N; ++k) {
auto &cm8382 = cm8380[k];

auto &cm8383 = g[k];

for (int l = k; l < std::min({N, (i + 1)}); ++l) {


cm8382[l] += (g[l] * cm8379 * cm8381 * cm8383);
}
}
}
}




for (int i = 0; i < N; ++i) {
auto &cm8522 = I[i];

auto &cm8523 = g[i];

for (int j = 0; j < N; ++j) {
auto &cm8524 = cm8522[j];

auto &cm8525 = g[j];

for (int k = j; k < N; ++k) {
auto &cm8526 = cm8524[k];

auto &cm8527 = g[k];

for (int l = k; l < N; ++l) {
auto &cm8528 = cm8526[l];

auto &cm8529 = g[l];

for (int s = l; s < std::min({N, (i + 1)}); ++s) {


cm8528[s] += (cm8529 * cm8523 * g[s] * cm8525 * cm8527);
}
}
}
}
}




for (int i = 0; i < N; ++i) {
auto &cm9482 = J[i];

auto &cm9483 = g[i];

for (int j = 0; j < N; ++j) {
auto &cm9484 = cm9482[j];

auto &cm9485 = g[j];

for (int k = j; k < N; ++k) {
auto &cm9486 = cm9484[k];

auto &cm9487 = g[k];

for (int l = k; l < N; ++l) {
auto &cm9488 = cm9486[l];

auto &cm9489 = g[l];

for (int s = l; s < N; ++s) {
auto &cm9490 = cm9488[s];

auto &cm9491 = g[s];

for (int t = s; t < std::min({N, (i + 1)}); ++t) {


cm9490[t] += (cm9489 * cm9483 * cm9491 * cm9485 * cm9487 * g[t]);
}
}
}
}
}
}




for (int i = 0; i < N; ++i) {
auto &cm16682 = K[i];

auto &cm16683 = f[i];
auto &cm16684 = g[i];

for (int j = i; j < N; ++j) {
double tmp = 0.0;



tmp += (f[j] * cm16683);

tmp += (cm16684 * g[j]);

cm16682[j] += tmp;
}
}




for (int i = 0; i < N; ++i) {
auto &cm16687 = L[i];

auto &cm16688 = f[i];
auto &cm16689 = g[i];

for (int j = 0; j < N; ++j) {
auto &cm16690 = cm16687[j];

auto &cm16691 = f[j];
auto &cm16692 = g[j];

for (int k = j; k < std::min({N, (i + 1)}); ++k) {
double tmp = 0.0;



tmp += (f[k] * cm16691 * cm16688);

tmp += (cm16689 * cm16692 * g[k]);

cm16690[k] += tmp;
}
}
}




for (int i = 0; i < N; ++i) {
auto &cm16713 = M[i];

auto &cm16714 = f[i];
auto &cm16715 = g[i];

for (int j = 0; j < N; ++j) {
auto &cm16716 = cm16713[j];

auto &cm16717 = f[j];
auto &cm16718 = g[j];

for (int k = j; k < N; ++k) {
auto &cm16719 = cm16716[k];

auto &cm16720 = f[k];
auto &cm16721 = g[k];

for (int l = k; l < std::min({N, (i + 1)}); ++l) {
double tmp = 0.0;



tmp += (cm16720 * cm16714 * f[l] * cm16717);

tmp += (g[l] * cm16715 * cm16718 * cm16721);

cm16719[l] += tmp;
}
}
}
}




for (int i = 0; i < N; ++i) {
auto &cm16860 = P[i];

auto &cm16861 = f[i];
auto &cm16862 = g[i];

for (int j = 0; j < N; ++j) {
auto &cm16863 = cm16860[j];

auto &cm16864 = f[j];
auto &cm16865 = g[j];

for (int k = j; k < N; ++k) {
auto &cm16866 = cm16863[k];

auto &cm16867 = f[k];
auto &cm16868 = g[k];

for (int l = k; l < N; ++l) {
auto &cm16869 = cm16866[l];

auto &cm16870 = f[l];
auto &cm16871 = g[l];

for (int s = l; s < std::min({N, (i + 1)}); ++s) {
double tmp = 0.0;



tmp += (cm16867 * cm16861 * cm16870 * cm16864 * f[s]);

tmp += (cm16871 * cm16862 * g[s] * cm16865 * cm16868);

cm16869[s] += tmp;
}
}
}
}
}




for (int i = 0; i < N; ++i) {
auto &cm17824 = O[i];

auto &cm17825 = f[i];
auto &cm17826 = g[i];

for (int j = 0; j < N; ++j) {
auto &cm17827 = cm17824[j];

auto &cm17828 = f[j];
auto &cm17829 = g[j];

for (int k = j; k < N; ++k) {
auto &cm17830 = cm17827[k];

auto &cm17831 = f[k];
auto &cm17832 = g[k];

for (int l = k; l < N; ++l) {
auto &cm17833 = cm17830[l];

auto &cm17834 = f[l];
auto &cm17835 = g[l];

for (int s = l; s < N; ++s) {
auto &cm17836 = cm17833[s];

auto &cm17837 = f[s];
auto &cm17838 = g[s];

for (int t = s; t < std::min({N, (i + 1)}); ++t) {
double tmp = 0.0;



tmp += (cm17831 * f[t] * cm17834 * cm17828 * cm17825 * cm17837);

tmp += (cm17835 * cm17826 * cm17838 * cm17829 * cm17832 * g[t]);

cm17836[t] += tmp;
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
cerr << F[0][0] << endl;
cerr << g[0] << endl;
cerr << g[0] << endl;
cerr << G[0][0][0] << endl;
cerr << g[0] << endl;
cerr << H[0][0][0][0] << endl;
cerr << g[0] << endl;
cerr << I[0][0][0][0][0] << endl;
cerr << g[0] << endl;
cerr << J[0][0][0][0][0][0] << endl;
cerr << g[0] << endl;
cerr << K[0][0] << endl;
cerr << L[0][0][0] << endl;
cerr << M[0][0][0][0] << endl;
cerr << P[0][0][0][0][0] << endl;
cerr << O[0][0][0][0][0][0] << endl;
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
for (size_t i0 = 0; i0 < N; ++i0) {
delete[] F[i0];
}
delete[] F;
delete[] g;
for (size_t i0 = 0; i0 < N; ++i0) {
for (size_t i1 = 0; i1 < N; ++i1) {
delete[] G[i0][i1];
}
delete[] G[i0];
}
delete[] G;
for (size_t i0 = 0; i0 < N; ++i0) {
for (size_t i1 = 0; i1 < N; ++i1) {
for (size_t i2 = 0; i2 < N; ++i2) {
delete[] H[i0][i1][i2];
}
delete[] H[i0][i1];
}
delete[] H[i0];
}
delete[] H;
for (size_t i0 = 0; i0 < N; ++i0) {
for (size_t i1 = 0; i1 < N; ++i1) {
for (size_t i2 = 0; i2 < N; ++i2) {
for (size_t i3 = 0; i3 < N; ++i3) {
delete[] I[i0][i1][i2][i3];
}
delete[] I[i0][i1][i2];
}
delete[] I[i0][i1];
}
delete[] I[i0];
}
delete[] I;
for (size_t i0 = 0; i0 < N; ++i0) {
for (size_t i1 = 0; i1 < N; ++i1) {
for (size_t i2 = 0; i2 < N; ++i2) {
for (size_t i3 = 0; i3 < N; ++i3) {
for (size_t i4 = 0; i4 < N; ++i4) {
delete[] J[i0][i1][i2][i3][i4];
}
delete[] J[i0][i1][i2][i3];
}
delete[] J[i0][i1][i2];
}
delete[] J[i0][i1];
}
delete[] J[i0];
}
delete[] J;
for (size_t i0 = 0; i0 < N; ++i0) {
delete[] K[i0];
}
delete[] K;
for (size_t i0 = 0; i0 < N; ++i0) {
for (size_t i1 = 0; i1 < N; ++i1) {
delete[] L[i0][i1];
}
delete[] L[i0];
}
delete[] L;
for (size_t i0 = 0; i0 < N; ++i0) {
for (size_t i1 = 0; i1 < N; ++i1) {
for (size_t i2 = 0; i2 < N; ++i2) {
delete[] M[i0][i1][i2];
}
delete[] M[i0][i1];
}
delete[] M[i0];
}
delete[] M;
for (size_t i0 = 0; i0 < N; ++i0) {
for (size_t i1 = 0; i1 < N; ++i1) {
for (size_t i2 = 0; i2 < N; ++i2) {
for (size_t i3 = 0; i3 < N; ++i3) {
delete[] P[i0][i1][i2][i3];
}
delete[] P[i0][i1][i2];
}
delete[] P[i0][i1];
}
delete[] P[i0];
}
delete[] P;
for (size_t i0 = 0; i0 < N; ++i0) {
for (size_t i1 = 0; i1 < N; ++i1) {
for (size_t i2 = 0; i2 < N; ++i2) {
for (size_t i3 = 0; i3 < N; ++i3) {
for (size_t i4 = 0; i4 < N; ++i4) {
delete[] O[i0][i1][i2][i3][i4];
}
delete[] O[i0][i1][i2][i3];
}
delete[] O[i0][i1][i2];
}
delete[] O[i0][i1];
}
delete[] O[i0];
}
delete[] O;
return 0;
}