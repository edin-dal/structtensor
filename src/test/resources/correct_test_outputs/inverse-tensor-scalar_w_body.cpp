
#include <iostream>
#include <random>
#include <algorithm>
#include <chrono>

using namespace std;
using namespace std::chrono;

int main(int argc, char **argv){
    srand(0);


const int N = atoi(argv[1]);
double **B = new double*[N];
for (size_t i = 0; i < N; ++i) {
B[i] = new double[N];

for (size_t j = 0; j < N; ++j) {
int flag1 = 0 <= i && N > i && 0 <= j && N > j;
if (flag1) {
B[i][j] = (double) (rand() % 1000000) / 1e6;
} else {
B[i][j] = 0.0;
}
}
}
double f = (double) (rand() % 1000000) / 1e6;
double **A = new double*[N];
for (size_t i = 0; i < N; ++i) {
A[i] = new double[N];

for (size_t j = 0; j < N; ++j) {
A[i][j] = 0.0;
}
}

long time_computation = 0, start_computation, end_computation;
start_computation = duration_cast<microseconds>(system_clock::now().time_since_epoch()).count();
for (int i = 0; i < N; ++i) {

for (int j = 0; j < N; ++j) {

A[i][j] = (1. / f * 1. / -5.123 * 1. / B[i][j]);
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
cerr << A[0][0] << endl;
cerr << B[0][0] << endl;
cerr << -5.123 << endl;
cerr << f << endl;
for (size_t i0 = 0; i0 < N; ++i0) {delete[] A[i0];
}delete[] A;
for (size_t i0 = 0; i0 < N; ++i0) {delete[] B[i0];
}delete[] B;
return 0;
}