
#include <iostream>
#include <random>
#include <algorithm>
#include <chrono>

using namespace std;
using namespace std::chrono;

int main(int argc, char **argv){
    srand(0);

    int M = atoi(argv[1]), N = atoi(argv[2]);

    
    double *H = new double[M];
    for(size_t i = 0; i < M; ++i) {
        H[i] = (double) (rand() % 1000000) / 1e6;
    }


    double *X = new double[N];
    for(size_t j = 0; j < N; ++j){
        X[j] = (double) (rand() % 1000000) / 1e6;
    }

    double *Y = new double[N];
    for (size_t i = 0; i < N; ++i) {
        Y[i] = (double) 0;
    }

    long time = 0, start, end;
    start = duration_cast<microseconds>(system_clock::now().time_since_epoch()).count();




auto &cm1 = X[0];

for (int i = 0; i < std::min({M, N}); ++i) {


Y[i] += (H[i] * cm1);
}


for (int j = 1; j < N; ++j) {

auto &cm2 = X[j];

for (int s = j; s < j + M; ++s) {

int i = (s % N);

Y[i] += (H[(s - j)] * cm2);
}
}

    end = duration_cast<microseconds>(system_clock::now().time_since_epoch()).count();
    time += end - start;

    cerr << Y[N - 1] << "\n";
    cout<<time;

    
    delete[] H;
    delete[] X;
    delete[] Y;
    return 0;
}
