
#include <iostream>
#include <random>
#include <algorithm>
#include <chrono>

using namespace std;
using namespace std::chrono;

int main(int argc, char **argv){
    srand(0);

    int M = atoi(argv[1]),N = atoi(argv[2]), P = atoi(argv[3]), Q = atoi(argv[4]);
    int J = atoi(argv[5]);
    
     /*
        M : third dimension (k vec) in B,   --> rows in A 
        N : first dimension (i vec) in B,   --> rows in C
        P : second dimension (j vec) in B,  --> rows in D

        Q : columns  in C, D, and A 

        A(i, j) = B(i,k,l),C(k,j),D(l,j)
    */

    double  ***B = new double**[M];
    for(size_t i = 0; i < M; ++i){
        B[i] = new double*[N];
        for(size_t k = 0; k < N; ++k){
            B[i][k] = new double[P];
            for(size_t l =0; l< P; ++l){
                B[i][k][l] = (double) (rand() % 1000000) / 1e6;
            }
        }
    }

    double  **C = new double*[N];
    for(size_t k = 0; k < N; ++k){
        C[k] = new double[Q];
        for(size_t j = 0; j < Q; ++j){
            C[k][j] = (double) (rand() % 1000000) / 1e6;
        }
    }


    double  **D = new double*[P];
    for(size_t l = 0; l < P; ++l){
        D[l] = new double[Q];
        for(size_t j = 0; j < Q; j++){
            D[l][j] = (double) (rand() % 1000000) / 1e6;
        }
    }

    double  **A = new double*[M];
    for(size_t i = 0; i < M; ++i){
        A[i] = new double[Q];
        for(size_t j = 0; j < Q; ++j){
            A[i][j] = (double) 0;
        }
    }

    long time = 0, start, end;
    start = duration_cast<microseconds>(system_clock::now().time_since_epoch()).count();



for (int i = 0; i < M; ++i) {
int j = J;
if (j < Q) {
for (int k = 0; k < N; ++k) {
for (int l = 0; l < P; ++l) {
A[i][j] += ((B[i][k][l] * C[k][j] * D[l][j]));
}
}
}
}


    end = duration_cast<microseconds>(system_clock::now().time_since_epoch()).count();
    time += end - start;

    cerr << A[M - 1][Q - 1] << "\n";
    cout<<time;
   


    for(size_t i = 0; i < P; i++){
        for(size_t j = 0; j < N; j++){
            delete[] B[i][j];
        }
        delete[] B[i];

    }
    delete[] B;
    
    for(size_t i = 0; i < N; i++){
        delete[] C[i];
    }
    delete[] C;

    for(size_t i = 0; i < P; i++){
        delete[] D[i];
    }
    delete[] D;

    for(size_t i = 0; i < M; i++){
        delete[] A[i];
    }
    delete[] A;
    return 0; 
}
