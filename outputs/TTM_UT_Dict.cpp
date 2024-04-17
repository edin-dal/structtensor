
#include <iostream>
#include <random>
#include <algorithm>
#include <chrono>
#include <unordered_map>
#include <tuple>
#include "robin_hood.h"

template<class K, class V> using dict_type = robin_hood::unordered_map<K, V>;

namespace std{
    namespace
    {

        // Code from boost
        // Reciprocal of the golden ratio helps spread entropy
        //     and handles duplicates.
        // See Mike Seymour in magic-numbers-in-boosthash-combine:
        //     http://stackoverflow.com/questions/4948780

        template <class T>
        inline void hash_combine(std::size_t& seed, T const& v)
        {
            seed ^= std::hash<T>()(v) + 0x9e3779b9 + (seed<<6) + (seed>>2);
        }

        // Recursive template code derived from Matthieu M.
        template <class Tuple, size_t Index = std::tuple_size<Tuple>::value - 1>
        struct HashValueImpl
        {
          static void apply(size_t& seed, Tuple const& tuple)
          {
            HashValueImpl<Tuple, Index-1>::apply(seed, tuple);
            hash_combine(seed, std::get<Index>(tuple));
          }
        };

        template <class Tuple>
        struct HashValueImpl<Tuple,0>
        {
          static void apply(size_t& seed, Tuple const& tuple)
          {
            hash_combine(seed, std::get<0>(tuple));
          }
        };
    }

    template <typename ... TT>
    struct hash<std::tuple<TT...>> 
    {
        size_t
        operator()(std::tuple<TT...> const& tt) const
        {                                              
            size_t seed = 0;                             
            HashValueImpl<std::tuple<TT...> >::apply(seed, tt);    
            return seed;                                 
        }                                              

    };
}

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

    // unordered_map<int, unordered_map<int, unordered_map<int, double>>> B;
    dict_type<tuple<int, int, int>, double> B;
    for(size_t i = 0; i < M; ++i){
        for(size_t j = 0; j < N; ++j){
            for(size_t l =0; l< Q; ++l){
                if (i <= j){
                    B[make_tuple(i, j, l)] = (double) (rand() % 1000000) / 1e6;
                }
                else{
                    B[make_tuple(i, j, l)] = (double) 0;
                }
            }
        }
    }

    // unordered_map<int, unordered_map<int, double>> C;
    dict_type<tuple<int, int>, double> C;
    for(size_t k = 0; k < P; ++k){
        for(size_t l = 0; l < Q; ++l){
            C[make_tuple(k, l)] = (double) (rand() % 1000000) / 1e6;
        }
    }


    // unordered_map<int, unordered_map<int, unordered_map<int, double>>> A;
    dict_type<tuple<int, int, int>, double> A;
    for(size_t i = 0; i < M; ++i){
        for(size_t j = 0; j < N; ++j){
            for(size_t k =0; k < P; ++k){
                A[make_tuple(i, j, k)] = (double) 0;
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

tmp += B[make_tuple(i, j, l)] * C[make_tuple(k, l)];
// tmp += ((cm4[l] * cm5[l]));
}
A[make_tuple(i, j, k)] += tmp;
// cm3[k] += tmp;
}
}
}


  end = duration_cast<microseconds>(system_clock::now().time_since_epoch()).count();
    time += end - start;

    cerr << A[make_tuple(M - 1, N - 1, P - 1)] << "\n";
    cout << time;
    
    return 0; 
}
