
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
  double **cont_degree2 = new double*[CONT_SZ];
  for (int i = 0; i < CONT_SZ; i++) {
    cont_degree2[i] = new double[CONT_SZ];
    for (int j = 0; j < CONT_SZ; j++) {
      cont_degree2[i][j] = 0;
    }
  }
  for (int i = 0; i < CONT_SZ; i++) {
    cont_sum1[i] = (double) (rand() % 1000000) / 1e6;
  }
  long start = duration_cast<microseconds>(system_clock::now().time_since_epoch()).count();




for (int x0 = 0; x0 < CONT_SZ; ++x0) {
for (int x1 = x0; x1 < CONT_SZ; ++x1) {
cont_degree2[x0][x1] = ((cont_sum1[x0] * cont_sum1[x1]));
}
}


  long end = duration_cast<microseconds>(system_clock::now().time_since_epoch()).count();
  cerr << cont_degree2[CONT_SZ - 1][CONT_SZ - 1] << endl;
  delete[] cont_sum1;
  for (int i = 0; i < CONT_SZ; i++) {
    delete[] cont_degree2[i];
  }
  delete[] cont_degree2;
  cout << end - start << endl;
  return 0;
}
