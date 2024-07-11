
#include <iostream>
#include <random>
#include <algorithm>
#include <chrono>

using namespace std;
using namespace std::chrono;

int main(int argc, char **argv){
    srand(0);


const int N = atoi(argv[1]);
double *t = new double[N];
for (size_t j = 0; j < N; ++j) {
int flag1 = 0 <= j && N > j;
if (flag1) {
t[j] = (double) (rand() % 1000000) / 1e6;
} else {
t[j] = 0.0;
}
}
double s = (double) (rand() % 1000000) / 1e6;
double l = (double) (rand() % 1000000) / 1e6;
double q = (double) (rand() % 1000000) / 1e6;
double *f = new double[N];
for (size_t i = 0; i < N; ++i) {
int flag2 = 0 <= i && N > i;
if (flag2) {
f[i] = (double) (rand() % 1000000) / 1e6;
} else {
f[i] = 0.0;
}
}
double p = 0.0;
double *A = new double[N];
for (size_t i = 0; i < N; ++i) {
A[i] = 0.0;
}

long time_computation = 0, start_computation, end_computation;
start_computation = duration_cast<microseconds>(system_clock::now().time_since_epoch()).count();
for (int j = 0; j < N; ++j) {

p += (3 * q * l * s * 5.12 * -12 * t[j]);
}
for (int i = 0; i < N; ++i) {

for (int i10 = 0; i10 < N; ++i10) {

A[i] += (3 * q * l * s * 5.12 * -12 * t[i10] * f[i]);
}
}
end_computation = duration_cast<microseconds>(system_clock::now().time_since_epoch()).count();
time_computation = end_computation - start_computation;
cout << time_computation << endl;
long time_reconstruction = 0, start_reconstruction, end_reconstruction;
start_reconstruction = duration_cast<microseconds>(system_clock::now().time_since_epoch()).count();


end_reconstruction = duration_cast<microseconds>(system_clock::now().time_since_epoch()).count();
time_reconstruction = end_reconstruction - start_reconstruction;
cout << time_reconstruction << endl;
cerr << p << endl;
cerr << 5.12 << endl;
cerr << -12 << endl;
cerr << t[0] << endl;
cerr << s << endl;
cerr << l << endl;
cerr << q << endl;
cerr << 3 << endl;
cerr << A[0] << endl;
cerr << f[0] << endl;
delete[] t;
delete[] A;
delete[] f;
return 0;
}