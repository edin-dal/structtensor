
#include <iostream>
#include <random>
#include <algorithm>
#include <chrono>

using namespace std;
using namespace std::chrono;

extern "C"
void fn(double * A, double *** B, double ** D, double ** C, int N) {


long time_computation = 0, start_computation, end_computation;
start_computation = duration_cast<microseconds>(system_clock::now().time_since_epoch()).count();

for (int j = 0; j < N; ++j) {
int i = j;
for (int k = 0; k < N; ++k) {

A[i] += B[j][j][k];
}
}

for (int i5 = 0; i5 < N; ++i5) {
int i = i5;

for (int i7 = 0; i7 < N; ++i7) {
int k = i7;
for (int i6 = 0; i6 < N; ++i6) {

for (int i8 = 0; i8 < N; ++i8) {

D[i][k] += (B[i5][i5][i6] * 1. / B[i7][i7][i8]);
}
}
}
}

for (int i13 = 0; i13 < N; ++i13) {
int i = i13;

for (int i14 = 0; i14 < N; ++i14) {

for (int i15 = max({i13, 0}); i15 < N; ++i15) {
int j = i15;
for (int i16 = 0; i16 < N; ++i16) {

C[i][j] += (1. / B[i13][i13][i14] * 1. / B[i15][i15][i16]);
}
}
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

}