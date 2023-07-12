
#include <array>
#include <iostream>
#include <algorithm>
#include <chrono>

using namespace std;
using namespace std::chrono;

int main(int argc, char **argv){
    
    srand(0);
    int M = atoi(argv[1]), N = atoi(argv[2]), P = atoi(argv[3]);
    
    
    /*
        M : third dimension (i) in B, C, A
        N : first dimension (j) in B, C, A
        P : second dimension (k) in B, C, A

        A(i,j,k) = B(i,j,k),C(i,j,k)
    */

    
    double *B = new double[M * P];
    for (size_t i = 0; i < M; ++i){
      
        for(size_t k =0; k< P; ++k){
          B[i * P + k] = (double) (rand() % 1000000) / 1e6;
        }
      }


    double  ***C = new double**[M];
    for(size_t i = 0; i < M; ++i){
        C[i] = new double*[N];
        for(size_t j = 0; j < N; ++j){
            C[i][j] = new double[P];
            for(size_t k =0; k< P; ++k){
                C[i][j][k] = (double) (rand() % 1000000) / 1e6;
            }
        }
    }

    double  ***A = new double**[M];
    for(size_t i = 0; i < M; ++i){
        A[i] = new double*[N];
        for(size_t j = 0; j < N; ++j){
            A[i][j] = new double[P];
            for(size_t k =0; k < P; ++k){
                (double) 0;
            }
        }
    }

    long time = 0, start, end;
    start = duration_cast<microseconds>(system_clock::now().time_since_epoch()).count();



for (int i = 0; i < std::min({M, N}); ++i) {
auto &cm1 = A[i];

auto &cm2 = C[i];


auto &cm3 = cm1[i];

auto &cm4 = cm2[i];

for (int k = 0; k < P; ++k) {


cm3[k] += (B[((i * P) + k)] * cm4[k]);
}
}


    end = duration_cast<microseconds>(system_clock::now().time_since_epoch()).count();
    time += end - start;
    
    cerr << A[M - 1][N - 1][P - 1] << "\n";
    cout<<time;

    
    delete[] B;

    for(size_t i = 0; i < M; ++i){
        for(size_t j = 0; j < N; ++j){
            delete[] C[i][j];
        }
        delete[] C[i];
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
