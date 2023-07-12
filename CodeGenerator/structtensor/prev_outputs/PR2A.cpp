
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
for (int x1 = x0; x1 < CONT_SZ; ++x1) {
cont_degree2[x0][x1] = ((cont_sum1[x0] * cont_sum1[x1]));
}
}



for (int x0 = 0; x0 < CONT_SZ; ++x0) {
for (int x1 = x0; x1 < CONT_SZ; ++x1) {
for (int x2 = x1; x2 < CONT_SZ; ++x2) {
cont_degree3[x0][x1][x2] = ((cont_sum1[x0] * cont_sum1[x1] * cont_sum1[x2]));
}
}
}



for (int x0 = 0; x0 < CONT_SZ; ++x0) {
for (int x1 = x0; x1 < CONT_SZ; ++x1) {
for (int x2 = x1; x2 < CONT_SZ; ++x2) {
for (int x3 = x2; x3 < CONT_SZ; ++x3) {
cont_degree4[x0][x1][x2][x3] = ((cont_sum1[x0] * cont_sum1[x1] * cont_sum1[x2] * cont_sum1[x3]));
}
}
}
}




for (int x0 = 0; x0 < CONT_SZ; ++x0) {
for (int x1 = x0; x1 < CONT_SZ; ++x1) {
other_cont_degree2[x0][x1] = ((other_cont_sum1[x0] * other_cont_sum1[x1]));
}
}



for (int x0 = 0; x0 < CONT_SZ; ++x0) {
for (int x1 = x0; x1 < CONT_SZ; ++x1) {
for (int x2 = x1; x2 < CONT_SZ; ++x2) {
other_cont_degree3[x0][x1][x2] = ((other_cont_sum1[x0] * other_cont_sum1[x1] * other_cont_sum1[x2]));
}
}
}



for (int x0 = 0; x0 < CONT_SZ; ++x0) {
for (int x1 = x0; x1 < CONT_SZ; ++x1) {
for (int x2 = x1; x2 < CONT_SZ; ++x2) {
for (int x3 = x2; x3 < CONT_SZ; ++x3) {
other_cont_degree4[x0][x1][x2][x3] = ((other_cont_sum1[x0] * other_cont_sum1[x1] * other_cont_sum1[x2] * other_cont_sum1[x3]));
}
}
}
}

  long start = duration_cast<microseconds>(system_clock::now().time_since_epoch()).count();



for (int x0 = 0; x0 < CONT_SZ; ++x0) {
for (int x1 = x0; x1 < CONT_SZ; ++x1) {

r_cont_degree2[x0][x1] += (cont_degree2[x0][x1]);

r_cont_degree2[x0][x1] += (other_cont_degree2[x0][x1]);

}
}



for (int x0 = 0; x0 < CONT_SZ; ++x0) {
for (int x1 = x0; x1 < CONT_SZ; ++x1) {
for (int x2 = x1; x2 < CONT_SZ; ++x2) {

r_cont_degree3[x0][x1][x2] += (cont_degree3[x0][x1][x2]);

r_cont_degree3[x0][x1][x2] += (other_cont_degree3[x0][x1][x2]);

}
}
}



for (int x0 = 0; x0 < CONT_SZ; ++x0) {
for (int x1 = x0; x1 < CONT_SZ; ++x1) {
for (int x2 = x1; x2 < CONT_SZ; ++x2) {
for (int x3 = x2; x3 < CONT_SZ; ++x3) {

r_cont_degree4[x0][x1][x2][x3] += (cont_degree4[x0][x1][x2][x3]);

r_cont_degree4[x0][x1][x2][x3] += (other_cont_degree4[x0][x1][x2][x3]);

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
