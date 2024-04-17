
#include <iostream>
#include <random>
#include <algorithm>
#include <chrono>

using namespace std;
using namespace std::chrono;

int main(int argc, char **argv){
    srand(0);

    int W = atoi(argv[1]);

    
    double **L = new double*[W];
    for (size_t i = 0; i < W; ++i) {
        L[i] = new double[W];
        for (size_t j = 0; j < W; ++j) {
            L[i][j] = (double) 0;
        }
    }
    for(size_t i = 0; i < W; ++i) {
        L[0][i] = (double) (rand() % 1000000) / 1e6;
    }
    for(size_t i = 1; i < W; ++i) {
        L[i][i - 1] = (double) (rand() % 1000000) / 1e6;
    }


    double *N = new double[W];
    for(size_t j = 0; j < W; ++j){
        N[j] = (double) (rand() % 1000000) / 1e6;
    }

    double *M = new double[W];
    for (size_t i = 0; i < W; ++i) {
        M[i] = (double) 0;
    }

    long time = 0, start, end;
    start = duration_cast<microseconds>(system_clock::now().time_since_epoch()).count();



int i = 0;
if (0 < W) {
double tmp = 0.0;

auto &cm1 = L[i];

for (int j = 0; j < W; ++j) {


tmp += (cm1[j] * N[j]);
}
M[i] += tmp;
}



for (int i = 1; i < W; ++i) {
double tmp = 0.0;

auto &cm2 = L[i];




tmp += (cm2[(i - 1)] * N[(i - 1)]);
M[i] += tmp;
}

    end = duration_cast<microseconds>(system_clock::now().time_since_epoch()).count();
    time += end - start;

    cerr << M[W - 1] << "\n";
    cout<<time;

    
    for(size_t i = 0; i < W; ++i){
        delete[] L[i];
    }
    delete[] L;

    delete[] N;
    delete[] M;
    return 0;
}
