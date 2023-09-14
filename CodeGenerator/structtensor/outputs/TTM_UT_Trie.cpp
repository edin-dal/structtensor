
#include <iostream>
#include <random>
#include <algorithm>
#include <chrono>

using namespace std;
using namespace std::chrono;

typedef struct Val_type
{
    double val;
    Val_type(double val) : val(val) {}
} Val_type;

struct K_type
{
    int K_SIZE;
    Val_type** k;
    K_type(int K_SIZE): K_SIZE(K_SIZE) {
        k = new Val_type*[K_SIZE];
    }
};
typedef struct K_type K_type;

struct J_type
{
    int J_SIZE; int K_SIZE;
    K_type** j;
    J_type(int J_SIZE, int K_SIZE): J_SIZE(J_SIZE), K_SIZE(K_SIZE) {
        j = new K_type*[J_SIZE];
    }
};
typedef struct J_type J_type;

struct I_type
{
    int I_SIZE; int J_SIZE; int K_SIZE;
    J_type** i;
    I_type(int I_SIZE, int J_SIZE, int K_SIZE): I_SIZE(I_SIZE), J_SIZE(J_SIZE), K_SIZE(K_SIZE) {
        i = new J_type*[I_SIZE];
    }
};
typedef struct I_type I_type;

void insertKType(K_type *root, int k, double val, bool force = false)
{
    if (val == 0 && !force)
        return;
    if (!root->k[k])
        root->k[k] = new Val_type(val);
}

void insertJType(J_type *root, int j, int k, double val, int K_SIZE, bool force = false)
{
    if (val == 0 && !force)
        return;
    if (!root->j[j])
        root->j[j] = new K_type(K_SIZE);
    insertKType(root->j[j], k, val);
}

void insertIType(I_type *root, int i, int j, int k, double val, int J_SIZE, int K_SIZE, bool force = false)
{
    if (val == 0 && !force)
        return;
    if (!root->i[i])
        root->i[i] = new J_type(J_SIZE, K_SIZE);
    insertJType(root->i[i], j, k, val, K_SIZE);
}

double getKType(K_type *root, int k)
{
    if (!root->k[k])
        return 0;
    return root->k[k]->val;
}

double getJType(J_type *root, int j, int k)
{
    if (!root->j[j])
        return 0;
    return getKType(root->j[j], k);
}

double getIType(I_type *root, int i, int j, int k)
{
    if (!root->i[i])
        return 0;
    return getJType(root->i[i], j, k);
}

void insertNoCheckIType(I_type *root, int i, int j, int k, double val) {
    root->i[i]->j[j]->k[k]->val = val;
}

double getNoCheckIType(I_type *root, int i, int j, int k) {
    return root->i[i]->j[j]->k[k]->val;
}

double getNoCheckJType(J_type *root, int j, int k) {
    return root->j[j]->k[k]->val;
}


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

    // unordered_map<int, unordered_map<int, unordered_map<int, double>>> B;
    I_type* B = new I_type(M, N, Q);
    for(size_t i = 0; i < M; ++i){
        for(size_t j = 0; j < N; ++j){
            for(size_t l =0; l< Q; ++l){
                if (i <= j){
                    insertIType(B, i, j, l, (double) (rand() % 1000000) / 1e6, N, Q);
                }
                else{
                    insertIType(B, i, j, l, 0.0, N, Q);
                }
            }
        }
    }

    // unordered_map<int, unordered_map<int, double>> C;
    J_type* C = new J_type(P, Q);
    for(size_t k = 0; k < P; ++k){
        for(size_t l = 0; l < Q; ++l){
            insertJType(C, k, l, (double) (rand() % 1000000) / 1e6, Q);
        }
    }


    // unordered_map<int, unordered_map<int, unordered_map<int, double>>> A;
    I_type* A = new I_type(M, N, P);
    for(size_t i = 0; i < M; ++i){
        for(size_t j = i; j < N; ++j){
            for(size_t k =0; k < P; ++k){
                insertIType(A, i, j, k, 0.0, N, P, true);
            }
        }
    }

    long time = 0, start, end;
    start = duration_cast<microseconds>(system_clock::now().time_since_epoch()).count();



for (int i = 0; i < M; ++i) {
// auto &cm1 = A[i];

// auto &cm2 = B[i];

for (int j = i; j < N; ++j) {
// auto &cm3 = cm1[j];

// auto &cm4 = cm2[j];

for (int k = 0; k < P; ++k) {
double tmp = 0.0;

// auto &cm5 = C[k];

for (int l = 0; l < Q; ++l) {

tmp += getNoCheckIType(B, i, j, l) * getNoCheckJType(C, k, l);
// tmp += ((cm4[l] * cm5[l]));
}
insertNoCheckIType(A, i, j, k, tmp);
// cm3[k] += tmp;
}
}
}


  end = duration_cast<microseconds>(system_clock::now().time_since_epoch()).count();
    time += end - start;

    cerr << getIType(A, M - 1, N - 1, P - 1) << "\n";
    cout << time;
    
    return 0; 
}
