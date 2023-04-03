
#include <iostream>
#include <random>
#include <algorithm>
#include <chrono>

using namespace std;
using namespace std::chrono;

int main(int argc, char **argv){
    srand(0);

    int M = atoi(argv[1]),N = atoi(argv[2]), Q = atoi(argv[3]), P = atoi(argv[4]);
    
    
     /*
        M : third dimension in B, A (i)    
        N : rows in B, A (j)
        Q : columns in B, columns in C (l)

        P : rows  in C (k)

        A(i, j,k) = B(i,j,l),C(k,l)
    */

    
    double *B = new double[((N + 1) * N / 2 - (N - M + 1) * (N - M) / 2) * Q];
    for (size_t i = 0; i < M; ++i) {
      for (size_t j = i; j < N; ++j) {
        for(size_t l = 0; l < Q; ++l) {
          B[(i * N + j - ((i + 1) * i / 2)) * Q + l] = (double) (rand() % 1000000) / 1e6;
        }
      }
    }


    double  **C = new double*[P];
    for(size_t k = 0; k < P; ++k){
        C[k] = new double[Q];
        for(size_t l = 0; l < Q; ++l){
            C[k][l] = (double) (rand() % 1000000) / 1e6;
        }
    }


    double  ***A = new double**[M];
    for(size_t i = 0; i < M; ++i){
        A[i] = new double*[N];
        for(size_t j = 0; j < N; ++j){
            A[i][j] = new double[P];
            for(size_t k =0; k < P; ++k){
                A[i][j][k] = (double) 0;
            }
        }
    }

    long time = 0, start, end;
    start = duration_cast<microseconds>(system_clock::now().time_since_epoch()).count();



for (int i = 0; i < M; ++i) {
auto &cm1 = A[i];


for (int j = i; j < N; ++j) {
auto &cm2 = cm1[j];


for (int k = 0; k < P; ++k) {
double tmp = 0.0;

auto &cm3 = C[k];

for (int l = 0; l < Q; ++l) {


tmp += (B[(((((i * N) + j) - ((i * (i + 1)) / 2)) * Q) + l)] * cm3[l]);
}
cm2[k] += tmp;
}
}
}


  end = duration_cast<microseconds>(system_clock::now().time_since_epoch()).count();
    time += end - start;

    cerr << A[M - 1][N - 1][P - 1] << "\n";
    cout << time;
    
    delete[] B;

    for(size_t k = 0; k < P; ++k){
        delete[] C[k];
    }
    delete[] C;

    for(size_t i = 0; i < M; ++i){
        for(size_t j = 0; j < N; ++j){
            delete[] A[i][j];
        }
        delete[] A[i];
    }
    delete[] A;
    
    return 0; 
}