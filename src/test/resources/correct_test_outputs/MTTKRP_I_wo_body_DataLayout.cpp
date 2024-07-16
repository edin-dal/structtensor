
#include <iostream>
#include <random>
#include <algorithm>
#include <chrono>

using namespace std;
using namespace std::chrono;

extern "C"
void fn(double ** B2, double *** B, double ** A, double ** C, double ** D, int M, int N, int P, int Q, int I) {

for (int k = 0; k < N; ++k) {

for (int l = 0; l < P; ++l) {

int i = I;
if (i >= 0 && i < M) {
B2[k][l] += B[i][k][l];
}
}
}
long time_computation = 0, start_computation, end_computation;
start_computation = duration_cast<microseconds>(system_clock::now().time_since_epoch()).count();
int i = I;
for (int j = 0; j < Q; ++j) {

for (int k = 0; k < N; ++k) {

for (int l = 0; l < P; ++l) {

A[i][j] += (B2[k][l] * C[k][j] * D[l][j]);
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