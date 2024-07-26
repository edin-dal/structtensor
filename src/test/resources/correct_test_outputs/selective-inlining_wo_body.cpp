
#include <iostream>
#include <random>
#include <algorithm>
#include <chrono>

using namespace std;
using namespace std::chrono;

extern "C"
void fn(double ** covar, double * f, double * dw, double * w, int M) {


long time_computation = 0, start_computation, end_computation;
start_computation = duration_cast<microseconds>(system_clock::now().time_since_epoch()).count();
{
for (int i = 0; i < M; ++i) {

for (int j = max({i, 0}); j < M; ++j) {

covar[i][j] += (f[i] * f[j]);
}
}
}
{
for (int i = 0; i < M; ++i) {

for (int j = max({i, 0}); j < M; ++j) {

dw[i] += (covar[i][j] * w[j]);
}
}
}
{
for (int i = 0; i < M; ++i) {

for (int j = 0; j < min({i, M, (i) + 1}); ++j) {

dw[i] += (w[j] * covar[j][i]);
}
}
}
end_computation = duration_cast<microseconds>(system_clock::now().time_since_epoch()).count();
time_computation = end_computation - start_computation;
cout << time_computation << endl;
long time_reconstruction = 0, start_reconstruction, end_reconstruction;
start_reconstruction = duration_cast<microseconds>(system_clock::now().time_since_epoch()).count();
{
for (int i = 0; i < M; ++i) {

int jp = i;
for (int j = 0; j < min({i, M}); ++j) {

int ip = j;
covar[i][j] = covar[ip][jp];
}
}
}

end_reconstruction = duration_cast<microseconds>(system_clock::now().time_since_epoch()).count();
time_reconstruction = end_reconstruction - start_reconstruction;
cout << time_reconstruction << endl;

}