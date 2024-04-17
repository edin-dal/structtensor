
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
      for (int k = 0; k < CONT_SZ; k++) {
        cont_degree3[i][j][k] = 0;
        other_cont_degree3[i][j][k] = 0;
        r_cont_degree3[i][j][k] = 0;
        cont_degree4[i][j][k] = new double[CONT_SZ];
        other_cont_degree4[i][j][k] = new double[CONT_SZ];
        r_cont_degree4[i][j][k] = new double[CONT_SZ];
        for (int l = 0; l < CONT_SZ; l++) {
          cont_degree4[i][j][k][l] = 0;
          other_cont_degree4[i][j][k][l] = 0;
          r_cont_degree4[i][j][k][l] = 0;
        }
      }
    }
  }
  for (int i = 0; i < CONT_SZ; i++) {
    cont_sum1[i] = (double) (rand() % 1000000) / 1e6;
    other_cont_sum1[i] = (double) (rand() % 1000000) / 1e6;
  }




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
auto &cm19 = other_cont_degree2[x0];

auto &cm20 = other_cont_sum1[x0];

for (int x1 = x0; x1 < CONT_SZ; ++x1) {


cm19[x1] = (cm20 * other_cont_sum1[x1]);
}
}



for (int x0 = 0; x0 < CONT_SZ; ++x0) {
auto &cm22 = other_cont_degree3[x0];

auto &cm23 = other_cont_sum1[x0];

for (int x1 = x0; x1 < CONT_SZ; ++x1) {
auto &cm24 = cm22[x1];

auto &cm25 = other_cont_sum1[x1];

for (int x2 = x1; x2 < CONT_SZ; ++x2) {


cm24[x2] = (cm23 * cm25 * other_cont_sum1[x2]);
}
}
}



for (int x0 = 0; x0 < CONT_SZ; ++x0) {
auto &cm27 = other_cont_degree4[x0];

auto &cm28 = other_cont_sum1[x0];

for (int x1 = x0; x1 < CONT_SZ; ++x1) {
auto &cm29 = cm27[x1];

auto &cm30 = other_cont_sum1[x1];

for (int x2 = x1; x2 < CONT_SZ; ++x2) {
auto &cm31 = cm29[x2];

auto &cm32 = other_cont_sum1[x2];

for (int x3 = x2; x3 < CONT_SZ; ++x3) {


cm31[x3] = (cm28 * cm30 * cm32 * other_cont_sum1[x3]);
}
}
}
}

  long start = duration_cast<microseconds>(system_clock::now().time_since_epoch()).count();



for (int x0 = 0; x0 < CONT_SZ; ++x0) {
auto &cm33 = r_cont_degree2[x0];

auto &cm34 = cont_degree2[x0];
auto &cm35 = other_cont_degree2[x0];

for (int x1 = x0; x1 < CONT_SZ; ++x1) {
double tmp = 0.0;



tmp += (cm34[x1]);

tmp += (cm35[x1]);

cm33[x1] += tmp;
}
}



for (int x0 = 0; x0 < CONT_SZ; ++x0) {
auto &cm36 = r_cont_degree3[x0];

auto &cm37 = cont_degree3[x0];
auto &cm38 = other_cont_degree3[x0];

for (int x1 = x0; x1 < CONT_SZ; ++x1) {
auto &cm39 = cm36[x1];

auto &cm40 = cm37[x1];
auto &cm41 = cm38[x1];

for (int x2 = x1; x2 < CONT_SZ; ++x2) {
double tmp = 0.0;



tmp += (cm40[x2]);

tmp += (cm41[x2]);

cm39[x2] += tmp;
}
}
}



for (int x0 = 0; x0 < CONT_SZ; ++x0) {
auto &cm42 = r_cont_degree4[x0];

auto &cm43 = cont_degree4[x0];
auto &cm44 = other_cont_degree4[x0];

for (int x1 = x0; x1 < CONT_SZ; ++x1) {
auto &cm45 = cm42[x1];

auto &cm46 = cm43[x1];
auto &cm47 = cm44[x1];

for (int x2 = x1; x2 < CONT_SZ; ++x2) {
auto &cm48 = cm45[x2];

auto &cm49 = cm46[x2];
auto &cm50 = cm47[x2];

for (int x3 = x2; x3 < CONT_SZ; ++x3) {
double tmp = 0.0;



tmp += (cm49[x3]);

tmp += (cm50[x3]);

cm48[x3] += tmp;
}
}
}
}


  long end = duration_cast<microseconds>(system_clock::now().time_since_epoch()).count();
  cerr << r_cont_degree2[CONT_SZ - 1][CONT_SZ - 1] << " " << r_cont_degree3[CONT_SZ - 1][CONT_SZ - 1][CONT_SZ - 1] << " " << r_cont_degree4[CONT_SZ - 1][CONT_SZ - 1][CONT_SZ - 1][CONT_SZ - 1] << endl;
  delete[] cont_sum1;
  delete[] other_cont_sum1;
  for (int i = 0; i < CONT_SZ; i++) {
    for (int j = 0; j < CONT_SZ; j++) {
      for (int k = 0; k < CONT_SZ; k++) {
        delete[] cont_degree4[i][j][k];
        delete[] other_cont_degree4[i][j][k];
        delete[] r_cont_degree4[i][j][k];
      }
      delete[] cont_degree3[i][j];
      delete[] other_cont_degree3[i][j];
      delete[] r_cont_degree3[i][j];
      delete[] cont_degree4[i][j];
      delete[] other_cont_degree4[i][j];
      delete[] r_cont_degree4[i][j];
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
  cout << end - start << endl;
  return 0;
}
