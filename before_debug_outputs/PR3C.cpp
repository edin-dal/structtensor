
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
  double *****cont_degree5 = new double****[CONT_SZ];
  double ******cont_degree6 = new double*****[CONT_SZ];
  for (int i = 0; i < CONT_SZ; i++) {
    cont_degree2[i] = new double[CONT_SZ];
    cont_degree3[i] = new double*[CONT_SZ];
    cont_degree4[i] = new double**[CONT_SZ];
    cont_degree5[i] = new double***[CONT_SZ];
    cont_degree6[i] = new double****[CONT_SZ];
    for (int j = 0; j < CONT_SZ; j++) {
      cont_degree2[i][j] = 0;
      cont_degree3[i][j] = new double[CONT_SZ];
      cont_degree4[i][j] = new double*[CONT_SZ];
      cont_degree5[i][j] = new double**[CONT_SZ];
      cont_degree6[i][j] = new double***[CONT_SZ];
      for (int k = 0; k < CONT_SZ; k++) {
        cont_degree3[i][j][k] = 0;
        cont_degree4[i][j][k] = new double[CONT_SZ];
        cont_degree5[i][j][k] = new double*[CONT_SZ];
        cont_degree6[i][j][k] = new double**[CONT_SZ];
        for (int l = 0; l < CONT_SZ; l++) {
          cont_degree4[i][j][k][l] = 0;
          cont_degree5[i][j][k][l] = new double[CONT_SZ];
          cont_degree6[i][j][k][l] = new double*[CONT_SZ];
          for (int p = 0; p < CONT_SZ; p++) {
            cont_degree5[i][j][k][l][p] = 0;
            cont_degree6[i][j][k][l][p] = new double[CONT_SZ];
            for (int q = 0; q < CONT_SZ; q++) {
              cont_degree6[i][j][k][l][p][q] = 0;
            }
          }
        }
      }
    }
  }
  for (int i = 0; i < CONT_SZ; i++) {
      cont_sum1[i] = (double) (rand() % 1000000) / 1e6;
  }
  long start = duration_cast<microseconds>(system_clock::now().time_since_epoch()).count();




for (int x0 = 0; x0 < CONT_SZ; ++x0) {
auto &cm5 = cont_degree2[x0];

auto &cm6 = cont_sum1[x0];

for (int x1 = x0; x1 < CONT_SZ; ++x1) {


cm5[x1] = (cm6 * cont_sum1[x1]);
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
auto &cm13 = cont_degree4[x0];

auto &cm14 = cont_sum1[x0];

for (int x1 = x0; x1 < CONT_SZ; ++x1) {
auto &cm15 = cm13[x1];

auto &cm16 = cont_sum1[x1];

for (int x2 = x1; x2 < CONT_SZ; ++x2) {
auto &cm17 = cm15[x2];

auto &cm18 = cont_sum1[x2];

for (int x3 = x2; x3 < CONT_SZ; ++x3) {


cm17[x3] = (cm14 * cm16 * cm18 * cont_sum1[x3]);
}
}
}
}



for (int x0 = 0; x0 < CONT_SZ; ++x0) {
auto &cm20 = cont_degree5[x0];

auto &cm21 = cont_sum1[x0];

for (int x1 = x0; x1 < CONT_SZ; ++x1) {
auto &cm22 = cm20[x1];

auto &cm23 = cont_sum1[x1];

for (int x2 = x1; x2 < CONT_SZ; ++x2) {
auto &cm24 = cm22[x2];

auto &cm25 = cont_sum1[x2];

for (int x3 = x2; x3 < CONT_SZ; ++x3) {
auto &cm26 = cm24[x3];

auto &cm27 = cont_sum1[x3];

for (int x4 = x3; x4 < CONT_SZ; ++x4) {


cm26[x4] = (cm21 * cm23 * cm25 * cm27 * cont_sum1[x4]);
}
}
}
}
}



for (int x0 = 0; x0 < CONT_SZ; ++x0) {
auto &cm29 = cont_degree6[x0];

auto &cm30 = cont_sum1[x0];

for (int x1 = x0; x1 < CONT_SZ; ++x1) {
auto &cm31 = cm29[x1];

auto &cm32 = cont_sum1[x1];

for (int x2 = x1; x2 < CONT_SZ; ++x2) {
auto &cm33 = cm31[x2];

auto &cm34 = cont_sum1[x2];

for (int x3 = x2; x3 < CONT_SZ; ++x3) {
auto &cm35 = cm33[x3];

auto &cm36 = cont_sum1[x3];

for (int x4 = x3; x4 < CONT_SZ; ++x4) {
auto &cm37 = cm35[x4];

auto &cm38 = cont_sum1[x4];

for (int x5 = x4; x5 < CONT_SZ; ++x5) {


cm37[x5] = (cm30 * cm32 * cm34 * cm36 * cm38 * cont_sum1[x5]);
}
}
}
}
}
}


  long end = duration_cast<microseconds>(system_clock::now().time_since_epoch()).count();
  cerr << cont_degree2[CONT_SZ - 1][CONT_SZ - 1] << " " << cont_degree3[CONT_SZ - 1][CONT_SZ - 1][CONT_SZ - 1] << " " << cont_degree4[CONT_SZ - 1][CONT_SZ - 1][CONT_SZ - 1][CONT_SZ - 1] << " " << cont_degree5[CONT_SZ - 1][CONT_SZ - 1][CONT_SZ - 1][CONT_SZ - 1][CONT_SZ - 1] << " " << cont_degree6[CONT_SZ - 1][CONT_SZ - 1][CONT_SZ - 1][CONT_SZ - 1][CONT_SZ - 1][CONT_SZ - 1] << endl;
  delete[] cont_sum1;
  for (int i = 0; i < CONT_SZ; i++) {
      for (int j = 0; j < CONT_SZ; j++) {
          for (int k = 0; k < CONT_SZ; k++) {
              for (int l = 0; l < CONT_SZ; l++) {
                  for (int p = 0; p < CONT_SZ; p++) {
                      delete[] cont_degree6[i][j][k][l][p];
                  }
                  delete[] cont_degree5[i][j][k][l];
                  delete[] cont_degree6[i][j][k][l];
              }
              delete[] cont_degree4[i][j][k];
              delete[] cont_degree5[i][j][k];
              delete[] cont_degree6[i][j][k];
          }
          delete[] cont_degree3[i][j];
          delete[] cont_degree4[i][j];
          delete[] cont_degree5[i][j];
          delete[] cont_degree6[i][j];
      }
      delete[] cont_degree2[i];
      delete[] cont_degree3[i];
      delete[] cont_degree4[i];
      delete[] cont_degree5[i];
      delete[] cont_degree6[i];
  }
  delete[] cont_degree2;
  delete[] cont_degree3;
  delete[] cont_degree4;
  delete[] cont_degree5;
  delete[] cont_degree6;
  cout << end - start << endl;
  return 0;
}
