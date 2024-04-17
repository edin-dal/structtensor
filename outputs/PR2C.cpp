
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
  double ***cont_degree3 = new double**[CONT_SZ];
  double ****cont_degree4 = new double***[CONT_SZ];
  for (int i = 0; i < CONT_SZ; i++) {
    cont_degree2[i] = new double[CONT_SZ];
    cont_degree3[i] = new double*[CONT_SZ];
    cont_degree4[i] = new double**[CONT_SZ];
    for (int j = 0; j < CONT_SZ; j++) {
      cont_degree2[i][j] = 0;
      cont_degree3[i][j] = new double[CONT_SZ];
      cont_degree4[i][j] = new double*[CONT_SZ];
      for (int k = 0; k < CONT_SZ; k++) {
        cont_degree3[i][j][k] = 0;
        cont_degree4[i][j][k] = new double[CONT_SZ];
        for (int l = 0; l < CONT_SZ; l++) {
          cont_degree4[i][j][k][l] = 0;
        }
      }
    }
  }
  for (int i = 0; i < CONT_SZ; i++) {
    cont_sum1[i] = (double) (rand() % 1000000) / 1e6;
  }
  long start = duration_cast<microseconds>(system_clock::now().time_since_epoch()).count();





for (int x0 = 0; x0 < CONT_SZ; ++x0) {
auto &cm3 = cont_degree2[x0];

auto &cm4 = cont_sum1[x0];

for (int x1 = x0; x1 < CONT_SZ; ++x1) {


cm3[x1] = (cont_sum1[x1] * cm4);
}
}




for (int x0 = 0; x0 < CONT_SZ; ++x0) {
auto &cm8 = cont_degree3[x0];

auto &cm9 = cont_sum1[x0];

for (int x1 = x0; x1 < CONT_SZ; ++x1) {
auto &cm10 = cm8[x1];

auto &cm11 = cont_sum1[x1];

for (int x2 = x1; x2 < CONT_SZ; ++x2) {


cm10[x2] = (cm9 * cm11 * cont_sum1[x2]);
}
}
}




for (int x0 = 0; x0 < CONT_SZ; ++x0) {
auto &cm33 = cont_degree4[x0];

auto &cm34 = cont_sum1[x0];

for (int x1 = x0; x1 < CONT_SZ; ++x1) {
auto &cm35 = cm33[x1];

auto &cm36 = cont_sum1[x1];

for (int x2 = x1; x2 < CONT_SZ; ++x2) {
auto &cm37 = cm35[x2];

auto &cm38 = cont_sum1[x2];

for (int x3 = x2; x3 < CONT_SZ; ++x3) {


cm37[x3] = (cont_sum1[x3] * cm34 * cm36 * cm38);
}
}
}
}


  long end = duration_cast<microseconds>(system_clock::now().time_since_epoch()).count();
  cerr << cont_degree2[CONT_SZ - 1][CONT_SZ - 1] << " " << cont_degree3[CONT_SZ - 1][CONT_SZ - 1][CONT_SZ - 1] << " " << cont_degree4[CONT_SZ - 1][CONT_SZ - 1][CONT_SZ - 1][CONT_SZ - 1] << endl;
  delete[] cont_sum1;
  for (int i = 0; i < CONT_SZ; i++) {
    for (int j = 0; j < CONT_SZ; j++) {
      for (int k = 0; k < CONT_SZ; k++) {
        delete[] cont_degree4[i][j][k];
      }
      delete[] cont_degree3[i][j];
      delete[] cont_degree4[i][j];
    }
    delete[] cont_degree2[i];
    delete[] cont_degree3[i];
    delete[] cont_degree4[i];
  }
  delete[] cont_degree2;
  delete[] cont_degree3;
  delete[] cont_degree4;
  cout << end - start << endl;
  return 0;
}
