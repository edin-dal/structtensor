
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
  double ***cont_degree3 = new double**[CONT_SZ];
  double ***other_cont_degree3 = new double**[CONT_SZ];
  double ***r_cont_degree3 = new double**[CONT_SZ];
  double ****cont_degree4 = new double***[CONT_SZ];
  double ****other_cont_degree4 = new double***[CONT_SZ];
  double ****r_cont_degree4 = new double***[CONT_SZ];
  double *****cont_degree5 = new double****[CONT_SZ];
  double *****other_cont_degree5 = new double****[CONT_SZ];
  double *****r_cont_degree5 = new double****[CONT_SZ];
  double ******cont_degree6 = new double*****[CONT_SZ];
  double ******other_cont_degree6 = new double*****[CONT_SZ];
  double ******r_cont_degree6 = new double*****[CONT_SZ];
  for (int i = 0; i < CONT_SZ; i++) {
    cont_degree2[i] = new double[CONT_SZ];
    other_cont_degree2[i] = new double[CONT_SZ];
    r_cont_degree2[i] = new double[CONT_SZ];
    cont_degree3[i] = new double*[CONT_SZ];
    other_cont_degree3[i] = new double*[CONT_SZ];
    r_cont_degree3[i] = new double*[CONT_SZ];
    cont_degree4[i] = new double**[CONT_SZ];
    other_cont_degree4[i] = new double**[CONT_SZ];
    r_cont_degree4[i] = new double**[CONT_SZ];
    cont_degree5[i] = new double***[CONT_SZ];
    other_cont_degree5[i] = new double***[CONT_SZ];
    r_cont_degree5[i] = new double***[CONT_SZ];
    cont_degree6[i] = new double****[CONT_SZ];
    other_cont_degree6[i] = new double****[CONT_SZ];
    r_cont_degree6[i] = new double****[CONT_SZ];
    for (int j = 0; j < CONT_SZ; j++) {
      cont_degree2[i][j] = 0;
      other_cont_degree2[i][j] = 0;
      r_cont_degree2[i][j] = 0;
      cont_degree3[i][j] = new double[CONT_SZ];
      other_cont_degree3[i][j] = new double[CONT_SZ];
      r_cont_degree3[i][j] = new double[CONT_SZ];
      cont_degree4[i][j] = new double*[CONT_SZ];
      other_cont_degree4[i][j] = new double*[CONT_SZ];
      r_cont_degree4[i][j] = new double*[CONT_SZ];
      cont_degree5[i][j] = new double**[CONT_SZ];
      other_cont_degree5[i][j] = new double**[CONT_SZ];
      r_cont_degree5[i][j] = new double**[CONT_SZ];
      cont_degree6[i][j] = new double***[CONT_SZ];
      other_cont_degree6[i][j] = new double***[CONT_SZ];
      r_cont_degree6[i][j] = new double***[CONT_SZ];
      for (int k = 0; k < CONT_SZ; k++) {
        cont_degree3[i][j][k] = 0;
        other_cont_degree3[i][j][k] = 0;
        r_cont_degree3[i][j][k] = 0;
        cont_degree4[i][j][k] = new double[CONT_SZ];
        other_cont_degree4[i][j][k] = new double[CONT_SZ];
        r_cont_degree4[i][j][k] = new double[CONT_SZ];
        cont_degree5[i][j][k] = new double*[CONT_SZ];
        other_cont_degree5[i][j][k] = new double*[CONT_SZ];
        r_cont_degree5[i][j][k] = new double*[CONT_SZ];
        cont_degree6[i][j][k] = new double**[CONT_SZ];
        other_cont_degree6[i][j][k] = new double**[CONT_SZ];
        r_cont_degree6[i][j][k] = new double**[CONT_SZ];
        for (int l = 0; l < CONT_SZ; l++) {
          cont_degree4[i][j][k][l] = 0;
          other_cont_degree4[i][j][k][l] = 0;
          r_cont_degree4[i][j][k][l] = 0;
          cont_degree5[i][j][k][l] = new double[CONT_SZ];
          other_cont_degree5[i][j][k][l] = new double[CONT_SZ];
          r_cont_degree5[i][j][k][l] = new double[CONT_SZ];
          cont_degree6[i][j][k][l] = new double*[CONT_SZ];
          other_cont_degree6[i][j][k][l] = new double*[CONT_SZ];
          r_cont_degree6[i][j][k][l] = new double*[CONT_SZ];
          for (int p = 0; p < CONT_SZ; p++) {
            cont_degree5[i][j][k][l][p] = 0;
            other_cont_degree5[i][j][k][l][p] = 0;
            r_cont_degree5[i][j][k][l][p] = 0;
            cont_degree6[i][j][k][l][p] = new double[CONT_SZ];
            other_cont_degree6[i][j][k][l][p] = new double[CONT_SZ];
            r_cont_degree6[i][j][k][l][p] = new double[CONT_SZ];
            for (int q = 0; q < CONT_SZ; q++) {
              cont_degree6[i][j][k][l][p][q] = 0;
              other_cont_degree6[i][j][k][l][p][q] = 0;
              r_cont_degree6[i][j][k][l][p][q] = 0;
            }
          }
        }
      }
    }
  }
  for (int i = 0; i < CONT_SZ; i++) {
      cont_sum1[i] = (double) (rand() % 1000000) / 1e6;
      other_cont_sum1[i] = (double) (rand() % 1000000) / 1e6;
  }




for (int x0 = 0; x0 < CONT_SZ; ++x0) {
auto &cm9 = cont_degree2[x0];

auto &cm10 = cont_sum1[x0];

for (int x1 = x0; x1 < CONT_SZ; ++x1) {


cm9[x1] = (cm10 * cont_sum1[x1]);
}
}



for (int x0 = 0; x0 < CONT_SZ; ++x0) {
auto &cm12 = cont_degree3[x0];

auto &cm13 = cont_sum1[x0];

for (int x1 = x0; x1 < CONT_SZ; ++x1) {
auto &cm14 = cm12[x1];

auto &cm15 = cont_sum1[x1];

for (int x2 = x1; x2 < CONT_SZ; ++x2) {


cm14[x2] = (cm13 * cm15 * cont_sum1[x2]);
}
}
}



for (int x0 = 0; x0 < CONT_SZ; ++x0) {
auto &cm17 = cont_degree4[x0];

auto &cm18 = cont_sum1[x0];

for (int x1 = x0; x1 < CONT_SZ; ++x1) {
auto &cm19 = cm17[x1];

auto &cm20 = cont_sum1[x1];

for (int x2 = x1; x2 < CONT_SZ; ++x2) {
auto &cm21 = cm19[x2];

auto &cm22 = cont_sum1[x2];

for (int x3 = x2; x3 < CONT_SZ; ++x3) {


cm21[x3] = (cm18 * cm20 * cm22 * cont_sum1[x3]);
}
}
}
}



for (int x0 = 0; x0 < CONT_SZ; ++x0) {
auto &cm24 = cont_degree5[x0];

auto &cm25 = cont_sum1[x0];

for (int x1 = x0; x1 < CONT_SZ; ++x1) {
auto &cm26 = cm24[x1];

auto &cm27 = cont_sum1[x1];

for (int x2 = x1; x2 < CONT_SZ; ++x2) {
auto &cm28 = cm26[x2];

auto &cm29 = cont_sum1[x2];

for (int x3 = x2; x3 < CONT_SZ; ++x3) {
auto &cm30 = cm28[x3];

auto &cm31 = cont_sum1[x3];

for (int x4 = x3; x4 < CONT_SZ; ++x4) {


cm30[x4] = (cm25 * cm27 * cm29 * cm31 * cont_sum1[x4]);
}
}
}
}
}



for (int x0 = 0; x0 < CONT_SZ; ++x0) {
auto &cm33 = cont_degree6[x0];

auto &cm34 = cont_sum1[x0];

for (int x1 = x0; x1 < CONT_SZ; ++x1) {
auto &cm35 = cm33[x1];

auto &cm36 = cont_sum1[x1];

for (int x2 = x1; x2 < CONT_SZ; ++x2) {
auto &cm37 = cm35[x2];

auto &cm38 = cont_sum1[x2];

for (int x3 = x2; x3 < CONT_SZ; ++x3) {
auto &cm39 = cm37[x3];

auto &cm40 = cont_sum1[x3];

for (int x4 = x3; x4 < CONT_SZ; ++x4) {
auto &cm41 = cm39[x4];

auto &cm42 = cont_sum1[x4];

for (int x5 = x4; x5 < CONT_SZ; ++x5) {


cm41[x5] = (cm34 * cm36 * cm38 * cm40 * cm42 * cont_sum1[x5]);
}
}
}
}
}
}




for (int x0 = 0; x0 < CONT_SZ; ++x0) {
auto &cm43 = other_cont_degree2[x0];

auto &cm44 = other_cont_sum1[x0];

for (int x1 = x0; x1 < CONT_SZ; ++x1) {


cm43[x1] = (cm44 * other_cont_sum1[x1]);
}
}



for (int x0 = 0; x0 < CONT_SZ; ++x0) {
auto &cm46 = other_cont_degree3[x0];

auto &cm47 = other_cont_sum1[x0];

for (int x1 = x0; x1 < CONT_SZ; ++x1) {
auto &cm48 = cm46[x1];

auto &cm49 = other_cont_sum1[x1];

for (int x2 = x1; x2 < CONT_SZ; ++x2) {


cm48[x2] = (cm47 * cm49 * other_cont_sum1[x2]);
}
}
}



for (int x0 = 0; x0 < CONT_SZ; ++x0) {
auto &cm51 = other_cont_degree4[x0];

auto &cm52 = other_cont_sum1[x0];

for (int x1 = x0; x1 < CONT_SZ; ++x1) {
auto &cm53 = cm51[x1];

auto &cm54 = other_cont_sum1[x1];

for (int x2 = x1; x2 < CONT_SZ; ++x2) {
auto &cm55 = cm53[x2];

auto &cm56 = other_cont_sum1[x2];

for (int x3 = x2; x3 < CONT_SZ; ++x3) {


cm55[x3] = (cm52 * cm54 * cm56 * other_cont_sum1[x3]);
}
}
}
}



for (int x0 = 0; x0 < CONT_SZ; ++x0) {
auto &cm58 = other_cont_degree5[x0];

auto &cm59 = other_cont_sum1[x0];

for (int x1 = x0; x1 < CONT_SZ; ++x1) {
auto &cm60 = cm58[x1];

auto &cm61 = other_cont_sum1[x1];

for (int x2 = x1; x2 < CONT_SZ; ++x2) {
auto &cm62 = cm60[x2];

auto &cm63 = other_cont_sum1[x2];

for (int x3 = x2; x3 < CONT_SZ; ++x3) {
auto &cm64 = cm62[x3];

auto &cm65 = other_cont_sum1[x3];

for (int x4 = x3; x4 < CONT_SZ; ++x4) {


cm64[x4] = (cm59 * cm61 * cm63 * cm65 * other_cont_sum1[x4]);
}
}
}
}
}



for (int x0 = 0; x0 < CONT_SZ; ++x0) {
auto &cm67 = other_cont_degree6[x0];

auto &cm68 = other_cont_sum1[x0];

for (int x1 = x0; x1 < CONT_SZ; ++x1) {
auto &cm69 = cm67[x1];

auto &cm70 = other_cont_sum1[x1];

for (int x2 = x1; x2 < CONT_SZ; ++x2) {
auto &cm71 = cm69[x2];

auto &cm72 = other_cont_sum1[x2];

for (int x3 = x2; x3 < CONT_SZ; ++x3) {
auto &cm73 = cm71[x3];

auto &cm74 = other_cont_sum1[x3];

for (int x4 = x3; x4 < CONT_SZ; ++x4) {
auto &cm75 = cm73[x4];

auto &cm76 = other_cont_sum1[x4];

for (int x5 = x4; x5 < CONT_SZ; ++x5) {


cm75[x5] = (cm68 * cm70 * cm72 * cm74 * cm76 * other_cont_sum1[x5]);
}
}
}
}
}
}

  long start = duration_cast<microseconds>(system_clock::now().time_since_epoch()).count();



for (int x0 = 0; x0 < CONT_SZ; ++x0) {
auto &cm77 = r_cont_degree2[x0];

auto &cm78 = cont_degree2[x0];
auto &cm79 = other_cont_degree2[x0];

for (int x1 = x0; x1 < CONT_SZ; ++x1) {
double tmp = 0.0;



tmp += (cm78[x1]);

tmp += (cm79[x1]);

cm77[x1] += tmp;
}
}



for (int x0 = 0; x0 < CONT_SZ; ++x0) {
auto &cm80 = r_cont_degree3[x0];

auto &cm81 = cont_degree3[x0];
auto &cm82 = other_cont_degree3[x0];

for (int x1 = x0; x1 < CONT_SZ; ++x1) {
auto &cm83 = cm80[x1];

auto &cm84 = cm81[x1];
auto &cm85 = cm82[x1];

for (int x2 = x1; x2 < CONT_SZ; ++x2) {
double tmp = 0.0;



tmp += (cm84[x2]);

tmp += (cm85[x2]);

cm83[x2] += tmp;
}
}
}



for (int x0 = 0; x0 < CONT_SZ; ++x0) {
auto &cm86 = r_cont_degree4[x0];

auto &cm87 = cont_degree4[x0];
auto &cm88 = other_cont_degree4[x0];

for (int x1 = x0; x1 < CONT_SZ; ++x1) {
auto &cm89 = cm86[x1];

auto &cm90 = cm87[x1];
auto &cm91 = cm88[x1];

for (int x2 = x1; x2 < CONT_SZ; ++x2) {
auto &cm92 = cm89[x2];

auto &cm93 = cm90[x2];
auto &cm94 = cm91[x2];

for (int x3 = x2; x3 < CONT_SZ; ++x3) {
double tmp = 0.0;



tmp += (cm93[x3]);

tmp += (cm94[x3]);

cm92[x3] += tmp;
}
}
}
}



for (int x0 = 0; x0 < CONT_SZ; ++x0) {
auto &cm95 = r_cont_degree5[x0];

auto &cm96 = cont_degree5[x0];
auto &cm97 = other_cont_degree5[x0];

for (int x1 = x0; x1 < CONT_SZ; ++x1) {
auto &cm98 = cm95[x1];

auto &cm99 = cm96[x1];
auto &cm100 = cm97[x1];

for (int x2 = x1; x2 < CONT_SZ; ++x2) {
auto &cm101 = cm98[x2];

auto &cm102 = cm99[x2];
auto &cm103 = cm100[x2];

for (int x3 = x2; x3 < CONT_SZ; ++x3) {
auto &cm104 = cm101[x3];

auto &cm105 = cm102[x3];
auto &cm106 = cm103[x3];

for (int x4 = x3; x4 < CONT_SZ; ++x4) {
double tmp = 0.0;



tmp += (cm105[x4]);

tmp += (cm106[x4]);

cm104[x4] += tmp;
}
}
}
}
}



for (int x0 = 0; x0 < CONT_SZ; ++x0) {
auto &cm107 = r_cont_degree6[x0];

auto &cm108 = cont_degree6[x0];
auto &cm109 = other_cont_degree6[x0];

for (int x1 = x0; x1 < CONT_SZ; ++x1) {
auto &cm110 = cm107[x1];

auto &cm111 = cm108[x1];
auto &cm112 = cm109[x1];

for (int x2 = x1; x2 < CONT_SZ; ++x2) {
auto &cm113 = cm110[x2];

auto &cm114 = cm111[x2];
auto &cm115 = cm112[x2];

for (int x3 = x2; x3 < CONT_SZ; ++x3) {
auto &cm116 = cm113[x3];

auto &cm117 = cm114[x3];
auto &cm118 = cm115[x3];

for (int x4 = x3; x4 < CONT_SZ; ++x4) {
auto &cm119 = cm116[x4];

auto &cm120 = cm117[x4];
auto &cm121 = cm118[x4];

for (int x5 = x4; x5 < CONT_SZ; ++x5) {
double tmp = 0.0;



tmp += (cm120[x5]);

tmp += (cm121[x5]);

cm119[x5] += tmp;
}
}
}
}
}
}


  long end = duration_cast<microseconds>(system_clock::now().time_since_epoch()).count();
  cerr << r_cont_degree2[CONT_SZ - 1][CONT_SZ - 1] << " " << r_cont_degree3[CONT_SZ - 1][CONT_SZ - 1][CONT_SZ - 1] << " " << r_cont_degree4[CONT_SZ - 1][CONT_SZ - 1][CONT_SZ - 1][CONT_SZ - 1] << " " << r_cont_degree5[CONT_SZ - 1][CONT_SZ - 1][CONT_SZ - 1][CONT_SZ - 1][CONT_SZ - 1] << " " << r_cont_degree6[CONT_SZ - 1][CONT_SZ - 1][CONT_SZ - 1][CONT_SZ - 1][CONT_SZ - 1][CONT_SZ - 1] << endl;
  delete[] cont_sum1;
  delete[] other_cont_sum1;
  for (int i = 0; i < CONT_SZ; i++) {
      for (int j = 0; j < CONT_SZ; j++) {
          for (int k = 0; k < CONT_SZ; k++) {
              for (int l = 0; l < CONT_SZ; l++) {
                  for (int p = 0; p < CONT_SZ; p++) {
                      delete[] cont_degree6[i][j][k][l][p];
                      delete[] other_cont_degree6[i][j][k][l][p];
                      delete[] r_cont_degree6[i][j][k][l][p];
                  }
                  delete[] cont_degree5[i][j][k][l];
                  delete[] other_cont_degree5[i][j][k][l];
                  delete[] r_cont_degree5[i][j][k][l];
                  delete[] cont_degree6[i][j][k][l];
                  delete[] other_cont_degree6[i][j][k][l];
                  delete[] r_cont_degree6[i][j][k][l];
              }
              delete[] cont_degree4[i][j][k];
              delete[] other_cont_degree4[i][j][k];
              delete[] r_cont_degree4[i][j][k];
              delete[] cont_degree5[i][j][k];
              delete[] other_cont_degree5[i][j][k];
              delete[] r_cont_degree5[i][j][k];
              delete[] cont_degree6[i][j][k];
              delete[] other_cont_degree6[i][j][k];
              delete[] r_cont_degree6[i][j][k];
          }
          delete[] cont_degree3[i][j];
          delete[] other_cont_degree3[i][j];
          delete[] r_cont_degree3[i][j];
          delete[] cont_degree4[i][j];
          delete[] other_cont_degree4[i][j];
          delete[] r_cont_degree4[i][j];
          delete[] cont_degree5[i][j];
          delete[] other_cont_degree5[i][j];
          delete[] r_cont_degree5[i][j];
          delete[] cont_degree6[i][j];
          delete[] other_cont_degree6[i][j];
          delete[] r_cont_degree6[i][j];
      }
      delete[] cont_degree2[i];
      delete[] other_cont_degree2[i];
      delete[] r_cont_degree2[i];
      delete[] cont_degree3[i];
      delete[] other_cont_degree3[i];
      delete[] r_cont_degree3[i];
      delete[] cont_degree4[i];
      delete[] other_cont_degree4[i];
      delete[] r_cont_degree4[i];
      delete[] cont_degree5[i];
      delete[] other_cont_degree5[i];
      delete[] r_cont_degree5[i];
      delete[] cont_degree6[i];
      delete[] other_cont_degree6[i];
      delete[] r_cont_degree6[i];
  }
  delete[] cont_degree2;
  delete[] other_cont_degree2;
  delete[] r_cont_degree2;
  delete[] cont_degree3;
  delete[] other_cont_degree3;
  delete[] r_cont_degree3;
  delete[] cont_degree4;
  delete[] other_cont_degree4;
  delete[] r_cont_degree4;
  delete[] cont_degree5;
  delete[] other_cont_degree5;
  delete[] r_cont_degree5;
  delete[] cont_degree6;
  delete[] other_cont_degree6;
  delete[] r_cont_degree6;
  cout << end - start << endl;
  return 0;
}
