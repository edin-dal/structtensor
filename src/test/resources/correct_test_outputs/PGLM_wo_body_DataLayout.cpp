
#include <iostream>
#include <random>
#include <algorithm>
#include <chrono>

using namespace std;
using namespace std::chrono;

extern "C"
void fn(double * B1, double ** B, double * B2, double * A, double * C, int W) {

for (int j = 0; j < W; ++j) {

int i = 0;
if (i >= 0 && i < W) {
B1[j] += B[i][j];
}
}
for (int i = max({1, 0}); i < W; ++i) {

int j = (i - 1);
if (j >= 0 && j < W) {
B2[j] += B[i][j];
}
}
long time_computation = 0, start_computation, end_computation;
start_computation = duration_cast<microseconds>(system_clock::now().time_since_epoch()).count();
int i = 0;
for (int i28 = 0; i28 < W; ++i28) {

A[i] += (B1[i28] * C[i28]);
}
for (int i = 1; i < W; ++i) {

int i29 = (i - 1);
if (i29 >= 0 && i29 < min({(W - 1), W})) {
A[i] += (B2[i29] * C[i29]);
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