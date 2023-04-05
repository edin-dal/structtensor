
#include <iostream>
#include <random>
#include <algorithm>
#include <chrono>

using namespace std;
using namespace std::chrono;

int main(int argc, char **argv){
    srand(0);

    int M = atoi(argv[1]), N = atoi(argv[2]);

    double **H = new double*[M + N - 1];
    for(size_t i = 0; i < M + N - 1; ++i){
        H[i] = new double[N];
        for(size_t j = 0; j < N; ++j){
            if (j == 0)
                H[i][j] = (double) (rand() % 1000000) / 1e6;
            else if (j <= i && i < M + j) 
                H[i][j] = H[i - j][0];
            else 
                H[i][j] = (double) 0;
        }
    }

    double *X = new double[N];
    for(size_t j = 0; j < N; ++j){
        X[j] = (double) (rand() % 1000000) / 1e6;
    }

    double *Y = new double[M + N - 1];
    for (size_t i = 0; i < M + N - 1; ++i) {
        Y[i] = (double) 0;
    }

    long time = 0, start, end;
    start = duration_cast<microseconds>(system_clock::now().time_since_epoch()).count();




auto &cm1 = X[0];

for (int i = 0; i < std::min({M, ((M + N) - 1)}); ++i) {


Y[i] += (H[i][0] * cm1);
}


for (int j = 1; j < N; ++j) {

auto &cm2 = X[j];

for (int i = j; i < std::min({((M + N) - 1), (j + M)}); ++i) {


Y[i] += (H[i - j][0] * cm2);
}
}

    end = duration_cast<microseconds>(system_clock::now().time_since_epoch()).count();
    time += end - start;

    cerr << Y[M + N - 2] << "\n";
    cout<<time;

    for(size_t i = 0; i < M + N - 1; ++i){
        delete[] H[i];
    }
    delete[] H;
    delete[] X;
    delete[] Y;
    return 0;
}
