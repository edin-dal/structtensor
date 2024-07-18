
#include <iostream>
#include <random>
#include <algorithm>
#include <chrono>

using namespace std;
using namespace std::chrono;

extern "C"
void fn(double ** covar, double ** X, double * w, double * y, double * DW, int N, int P) {


long time_computation = 0, start_computation, end_computation;
start_computation = duration_cast<microseconds>(system_clock::now().time_since_epoch()).count();
for (int i = 0; i < P; ++i) {

for (int k = 0; k < min({(i) + 1, P}); ++k) {

for (int j = 0; j < N; ++j) {

covar[i][k] += (X[j][k] * X[j][i]);
}
}
}
for (int i = 0; i < P; ++i) {

for (int i19 = 0; i19 < min({(i) + 1, P}); ++i19) {

DW[i] += (covar[i][i19] * w[i]);
}
}
for (int i = 0; i < P; ++i) {

for (int i19 = max({(i) + 1, 0, i}); i19 < P; ++i19) {

DW[i] += (w[i] * covar[i19][i]);
}
}
for (int i = 0; i < P; ++i) {

for (int i20 = 0; i20 < N; ++i20) {

DW[i] += (X[i20][i] * y[i20]);
}
}
end_computation = duration_cast<microseconds>(system_clock::now().time_since_epoch()).count();
time_computation = end_computation - start_computation;
cout << time_computation << endl;
long time_reconstruction = 0, start_reconstruction, end_reconstruction;
start_reconstruction = duration_cast<microseconds>(system_clock::now().time_since_epoch()).count();
for (int i = 0; i < P; ++i) {

int kp = i;
for (int k = max({(i) + 1, 0}); k < P; ++k) {

int ip = k;
covar[i][k] = covar[ip][kp];
}
}

end_reconstruction = duration_cast<microseconds>(system_clock::now().time_since_epoch()).count();
time_reconstruction = end_reconstruction - start_reconstruction;
cout << time_reconstruction << endl;

}