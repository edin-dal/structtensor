
#include <iostream>
#include <random>
#include <algorithm>
#include <chrono>

using namespace std;
using namespace std::chrono;

int main(int argc, char **argv){
    srand(0);


const int N = atoi(argv[1]);
double *B = new double[N];
for (size_t i = 0; i < N; ++i) {
int flag1 = 0 <= i && N > i;
if (flag1) {
B[i] = (double) (rand() % 1000000) / 1e6;
} else {
B[i] = 0.0;
}
}
double *A = new double[N];
for (size_t i = 0; i < N; ++i) {
A[i] = 0.0;
}

long time_computation = 0, start_computation, end_computation;
start_computation = duration_cast<microseconds>(system_clock::now().time_since_epoch()).count();
for (int i = 0; i < N; ++i) {

A[i] = (1. / N * B[i]);
}
end_computation = duration_cast<microseconds>(system_clock::now().time_since_epoch()).count();
time_computation = end_computation - start_computation;
cout << time_computation << endl;
long time_reconstruction = 0, start_reconstruction, end_reconstruction;
start_reconstruction = duration_cast<microseconds>(system_clock::now().time_since_epoch()).count();

end_reconstruction = duration_cast<microseconds>(system_clock::now().time_since_epoch()).count();
time_reconstruction = end_reconstruction - start_reconstruction;
cout << time_reconstruction << endl;
cerr << A[0] << endl;
cerr << B[0] << endl;
cerr << N << endl;
delete[] A;
delete[] B;
return 0;
}