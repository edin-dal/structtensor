
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

    double  ***B = new double**[M];
    for(size_t i = 0; i < M; ++i){
        B[i] = new double*[N];
        for(size_t j = 0; j < N; ++j){
            B[i][j] = new double[Q];
            for(size_t l =0; l< Q; ++l){
                if (i == j){
                    B[i][j][l] = (double) (rand() % 1000000) / 1e6;
                }
                else{
                    B[i][j][l] = (double) 0;
                }
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



for (int i = 0; i < std::min({M, N}); ++i) {
auto &cm1 = A[i];

auto &cm2 = B[i];


auto &cm3 = cm1[i];

auto &cm4 = cm2[i];

for (int k = 0; k < P; ++k) {
double tmp = 0.0;

auto &cm5 = C[k];

for (int l = 0; l < Q; ++l) {


tmp += ((cm4[l] * cm5[l]));
}
cm3[k] += tmp;
}
}


  end = duration_cast<microseconds>(system_clock::now().time_since_epoch()).count();
    time += end - start;

    cerr << A[M - 1][N - 1][P - 1] << "\n";
    cout << time;
   
    for(size_t i = 0; i < M; ++i){
        for(size_t j = 0; j < N; ++j){
            delete[] B[i][j];
        }
        delete[] B[i];
    }
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
