
#include <iostream>
#include <random>
#include <algorithm>
#include <chrono>

using namespace std;
using namespace std::chrono;

extern "C"
void fn(double ** B2, double *** B, double *** A, double ** C, int N, int M, int P, int Q) {

{
for (int l = 0; l < Q; ++l) {

for (int i = 0; i < M; ++i) {

for (int j = max({i, 0}); j < N; ++j) {

int s = (((N * i) + j) - ((i * (i + 1)) / 2));
B2[s][l] += B[i][j][l];
}
}
}
}
long time_computation = 0, start_computation, end_computation;
start_computation = duration_cast<microseconds>(system_clock::now().time_since_epoch()).count();
{
for (int i = 0; i < M; ++i) {

for (int j = 0; j < N; ++j) {

int s = (((N * i) + j) - ((i * (i + 1)) / 2));
if (s >= 0 && s < ((M * (N + 1)) / 2)) {
for (int k = 0; k < P; ++k) {

for (int l = 0; l < Q; ++l) {

A[i][j][k] += (B2[s][l] * C[k][l]);
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

end_reconstruction = duration_cast<microseconds>(system_clock::now().time_since_epoch()).count();
time_reconstruction = end_reconstruction - start_reconstruction;
cout << time_reconstruction << endl;

}