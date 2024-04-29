
#include <iostream>
#include <random>
#include <algorithm>
#include <chrono>

using namespace std;
using namespace std::chrono;

int main(int argc, char **argv){
    srand(0);


const int N = atoi(argv[1]);

double **A = new double*[N];
for (size_t i = 0; i < N; ++i) {
A[i] = new double[N];
for (size_t j = 0; j < N; ++j) {
int flag1 = 0 <= i && N > i && 0 <= j && N > j;
if (flag1) {
A[i][j] = (double) 1.0;
} else {
A[i][j] = 0.0;
}
}
}

double *f = new double[N];
for (size_t i = 0; i < N; ++i) {
int flag2 = 0 <= i && N > i;
if (flag2) {
f[i] = (double) 1.0;
} else {
f[i] = 0.0;
}
}

long time = 0, start, end;
start = duration_cast<microseconds>(system_clock::now().time_since_epoch()).count();



for (int i = 0; i < N; ++i) {
auto &cm3 = A[i];

auto &cm4 = f[i];

for (int j = i; j < N; ++j) {


cm3[j] += (f[j] * cm4);
}
}

end = duration_cast<microseconds>(system_clock::now().time_since_epoch()).count();
time = end - start;
cout << time << endl;
cerr << A[0][0] << endl;
cerr << f[0] << endl;
cerr << f[0] << endl;
for (size_t i0 = 0; i0 < N; ++i0) {
delete[] A[i0];
}
delete[] A;
delete[] f;
return 0;
}