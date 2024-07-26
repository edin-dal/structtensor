
#include <iostream>
#include <random>
#include <algorithm>
#include <chrono>

using namespace std;
using namespace std::chrono;

extern "C"
void fn(double ** B2, double *** B, double *** A, double *** C, int N, int M, int P, int I) {

{
for (int j = 0; j < N; ++j) {

for (int k = 0; k < P; ++k) {

int i = I;
if (i >= 0 && i < M) {
B2[j][k] += B[i][j][k];
}
}
}
}
long time_computation = 0, start_computation, end_computation;
start_computation = duration_cast<microseconds>(system_clock::now().time_since_epoch()).count();
{
int i = I;
if (i >= 0 && i < M) {
for (int j = 0; j < N; ++j) {

for (int k = 0; k < P; ++k) {

A[i][j][k] += (B2[j][k] * C[i][j][k]);
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