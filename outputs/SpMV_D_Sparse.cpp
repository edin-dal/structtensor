
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

    
    double *B = new double[M];
    for (size_t i = 0; i < M; ++i){
      
        B[i] = (double) (rand() % 1000000) / 1e6;
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




for (int i = 0; i < std::min({M, N}); ++i) {
double tmp = 0.0;





tmp += (B[i] * C[i]);
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
