
#include <iostream>
#include <random>
#include <algorithm>
#include <chrono>

using namespace std;
using namespace std::chrono;

int main(int argc, char **argv){
    srand(0);

    int W = atoi(argv[1]);

    
    double *L1 = new double[W];
    double *L2 = new double[W - 1];
    for(size_t i = 0; i < W; ++i) {
        L1[i] = (double) (rand() % 1000000) / 1e6;
    }
    for(size_t i = 0; i < W - 1; ++i) {
        L2[i] = (double) (rand() % 1000000) / 1e6;
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
double tmp = 0.0;


for (int j = 0; j < W; ++j) {


tmp += (L1[i] * N[j]);
}
M[i] += tmp;


for (int i = 1; i < W; ++i) {
double tmp = 0.0;





tmp += (L2[(i - 1)] * N[(i - 1)]);
M[i] += tmp;
}

    end = duration_cast<microseconds>(system_clock::now().time_since_epoch()).count();
    time += end - start;

    cerr << M[W - 1] << "\n";
    cout<<time;

    
    delete[] L1;
    delete[] L2; 

    delete[] N;
    delete[] M;
    return 0;
}
