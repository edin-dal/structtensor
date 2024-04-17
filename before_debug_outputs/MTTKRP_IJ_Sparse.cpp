
#include <iostream>
#include <random>
#include <algorithm>
#include <chrono>

using namespace std;
using namespace std::chrono;

int main(int argc, char **argv){
    srand(0);

    int M = atoi(argv[1]),N = atoi(argv[2]), P = atoi(argv[3]), Q = atoi(argv[4]);
    int I = atoi(argv[5]), J = atoi(argv[6]);
    
     /*
        M : third dimension (k vec) in B,   --> rows in A 
        N : first dimension (i vec) in B,   --> rows in C
        P : second dimension (j vec) in B,  --> rows in D

        Q : columns  in C, D, and A 

        A(i, j) = B(i,k,l),C(k,j),D(l,j)
    */


    
    double *B = new double[N * P];
    for (size_t k = 0; k < N; ++k){
        for (size_t l = 0; l < P; ++l){
            B[k * P + l] = (double) (rand() % 1000000) / 1e6;
        }
    }


    double  **C = new double*[N];
    for(size_t k = 0; k < N; ++k){
        C[k] = new double[Q];
        for(size_t j = 0; j < Q; ++j){
            C[k][j] = (double) (rand() % 1000000) / 1e6;
        }
    }

    
    double *D = new double[P];
    for (size_t l = 0; l < P; ++l){
        D[l] = (double) (rand() % 1000000) / 1e6;
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



int i = I;
if (i < M) {
auto &cm2 = A[i];


int j = J;
if (j < Q) {
double tmp = 0.0;


for (int k = 0; k < N; ++k) {

auto &cm3 = C[k];

for (int l = 0; l < P; ++l) {


tmp += (B[((k * P) + l)] * cm3[j] * D[l]);
}
}
cm2[j] += tmp;
}
}


    end = duration_cast<microseconds>(system_clock::now().time_since_epoch()).count();
    time += end - start;

    cerr << A[M - 1][Q - 1] << "\n";
    cout<<time;
   

    
    delete[] B;
    
    for(size_t i = 0; i < N; i++){
        delete[] C[i];
    }
    delete[] C;

    
    delete[] D;

    for(size_t i = 0; i < M; i++){
        delete[] A[i];
    }
    delete[] A;
    return 0; 
}
