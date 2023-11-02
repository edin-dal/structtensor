
#include <array>
#include <iostream>
#include <algorithm>
#include <chrono>

using namespace std;
using namespace std::chrono;

int main(int argc, char **argv){
    
    srand(0);
    int M = atoi(argv[1]), N = atoi(argv[2]);
    
    /*
        M : first dimension (i) in A, B
        N : second dimension (j) in B, C

        A(i) = B(i,j),C(j)
    */

    
    double *B = new double[M * (M + 1) / 2];
    for (size_t i = 0; i < M; ++i){
      for(size_t j = i; j < N; ++j){
        B[i * M + j - (i * (i + 1) / 2)] = (double) (rand() % 1000000) / 1e6;
      }
    }


    double  *C = new double[N];
    for(size_t i = 0; i < N; ++i){
        C[i] = (double) (rand() % 1000000) / 1e6;
    }

    double  *A = new double[M];
    for(size_t i = 0; i < M; ++i){
        A[i] = (double) 0;
    }

    long time = 0, start, end;
    start = duration_cast<microseconds>(system_clock::now().time_since_epoch()).count();




for (int i = 0; i < M; ++i) {
double tmp = 0.0;


for (int j = i; j < N; ++j) {


tmp += (B[(((i * M) + j) - ((i * (i + 1)) / 2))] * C[j]);
}
A[i] += tmp;
}


    end = duration_cast<microseconds>(system_clock::now().time_since_epoch()).count();
    time += end - start;
    
    cerr << A[M - 1] << "\n";
    cout<<time;

    
    delete[] B;
    delete[] C;
    delete[] A;

    return 0; 
}
