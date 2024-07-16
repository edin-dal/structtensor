
#include <iostream>
#include <random>
#include <algorithm>
#include <chrono>

using namespace std;
using namespace std::chrono;

extern "C"
void fn(double ** A, double ** B, double & f, int N) {


long time_computation = 0, start_computation, end_computation;
start_computation = duration_cast<microseconds>(system_clock::now().time_since_epoch()).count();
for (int i = 0; i < N; ++i) {

for (int j = 0; j < N; ++j) {

A[i][j] += (1. / f * 1. / -5.123 * 1. / B[i][j]);
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