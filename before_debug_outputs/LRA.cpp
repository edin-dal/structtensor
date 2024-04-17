
#include <iostream>
#include <random>
#include <algorithm>
#include <chrono>
#include <vector>
#include <array>
#include <ctime>

using namespace std::chrono;
using namespace std;

int main(int argc, char *argv[]) {
  int CONT_SZ = stoi(argv[1]);    
  srand(0);
  double *cont_sum1 = new double[CONT_SZ];
  double *other_cont_sum1 = new double[CONT_SZ];
  double **cont_degree2 = new double*[CONT_SZ];
  double **other_cont_degree2 = new double*[CONT_SZ];
  double **r_cont_degree2 = new double*[CONT_SZ];
  for (int i = 0; i < CONT_SZ; i++) {
    cont_degree2[i] = new double[CONT_SZ];
    other_cont_degree2[i] = new double[CONT_SZ];
    r_cont_degree2[i] = new double[CONT_SZ];
    for (int j = 0; j < CONT_SZ; j++) {
      cont_degree2[i][j] = 0;
      other_cont_degree2[i][j] = 0;
      r_cont_degree2[i][j] = 0;
    }
  }
  for (int i = 0; i < CONT_SZ; i++) {
    cont_sum1[i] = (double) (rand() % 1000000) / 1e6;
    other_cont_sum1[i] = (double) (rand() % 1000000) / 1e6;
  }




for (int x0 = 0; x0 < CONT_SZ; ++x0) {
auto &cm1 = cont_degree2[x0];

auto &cm2 = cont_sum1[x0];

for (int x1 = x0; x1 < CONT_SZ; ++x1) {


cm1[x1] = (cm2 * cont_sum1[x1]);
}
}




for (int x0 = 0; x0 < CONT_SZ; ++x0) {
auto &cm3 = other_cont_degree2[x0];

auto &cm4 = other_cont_sum1[x0];

for (int x1 = x0; x1 < CONT_SZ; ++x1) {


cm3[x1] = (cm4 * other_cont_sum1[x1]);
}
}

  long start = duration_cast<microseconds>(system_clock::now().time_since_epoch()).count();



for (int x0 = 0; x0 < CONT_SZ; ++x0) {
auto &cm5 = r_cont_degree2[x0];

auto &cm6 = cont_degree2[x0];
auto &cm7 = other_cont_degree2[x0];

for (int x1 = x0; x1 < CONT_SZ; ++x1) {
double tmp = 0.0;



tmp += (cm6[x1]);

tmp += (cm7[x1]);

cm5[x1] += tmp;
}
}


  long end = duration_cast<microseconds>(system_clock::now().time_since_epoch()).count();
  cerr << r_cont_degree2[CONT_SZ - 1][CONT_SZ - 1] << endl;
  delete[] cont_sum1;
  delete[] other_cont_sum1;
  for (int i = 0; i < CONT_SZ; i++) {
    delete[] cont_degree2[i];
    delete[] other_cont_degree2[i];
    delete[] r_cont_degree2[i];
  }
  delete[] cont_degree2;
  delete[] other_cont_degree2;
  delete[] r_cont_degree2;
  cout << end - start << endl;
  return 0;
}
