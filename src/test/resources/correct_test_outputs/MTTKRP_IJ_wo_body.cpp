
#include <iostream>
#include <random>
#include <algorithm>
#include <chrono>

using namespace std;
using namespace std::chrono;
void fn(double ** A, double *** B, double ** C, double ** D, int M, int N, int P, int Q, int I, int J) {


long time_computation = 0, start_computation, end_computation;
start_computation = duration_cast<microseconds>(system_clock::now().time_since_epoch()).count();
int i = I;
if (i >= 0 && i < M) {
int j = J;
if (j >= 0 && j < Q) {
for (int k = 0; k < N; ++k) {

for (int l = 0; l < P; ++l) {

A[i][j] += (B[i][k][l] * C[k][j] * D[l][j]);
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