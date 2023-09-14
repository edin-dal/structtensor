
#include <stdlib.h>
#include <stdio.h>
#include <time.h>

// call this function to start a nanosecond-resolution timer
struct timespec timer_start(){
  struct timespec start_time;
  clock_gettime(CLOCK_PROCESS_CPUTIME_ID, &start_time);
  return start_time;
}

// call this function to end a timer, returning nanoseconds elapsed as a long
long timer_end(struct timespec start_time){
  struct timespec end_time;
  clock_gettime(CLOCK_PROCESS_CPUTIME_ID, &end_time);
  long diffInNanos = (end_time.tv_sec - start_time.tv_sec) * (long)1e9 + (end_time.tv_nsec - start_time.tv_nsec);
  return diffInNanos / 1000;
}

int main(int argc, char **argv){
  srand(0);

const int M = atoi(argv[1]);
const int N = atoi(argv[2]);
const int P = atoi(argv[3]);
const int Q = atoi(argv[4]);
const int I = atoi(argv[5]);
const int J = atoi(argv[6]);

double (*B) = malloc(sizeof(double) * N * P);
for (size_t i0 = 0; i0 < N; ++i0) {
for (size_t i1 = 0; i1 < P; ++i1) {
if (1) {
B[i0 * P + i1] = (double) (rand() % 1000000) / 1e6;
} else {
B[i0 * P + i1] = 0.0;
}
}
}

double (*C)[Q] = malloc(sizeof(double) * N * Q);
for (size_t i0 = 0; i0 < N; ++i0) {
for (size_t i1 = 0; i1 < Q; ++i1) {
if (1) {
C[i0][i1] = (double) (rand() % 1000000) / 1e6;
} else {
C[i0][i1] = 0.0;
}
}
}

double (*D) = malloc(sizeof(double) * P);
for (size_t i0 = 0; i0 < P; ++i0) {
if (1) {
D[i0] = (double) (rand() % 1000000) / 1e6;
} else {
D[i0] = 0.0;
}
}

double (*A)[Q] = malloc(sizeof(double) * M * Q);
for (size_t i0 = 0; i0 < M; ++i0) {
for (size_t i1 = 0; i1 < Q; ++i1) {
if (0) {
A[i0][i1] = (double) (rand() % 1000000) / 1e6;
} else {
A[i0][i1] = 0.0;
}
}
}

struct timespec start = timer_start();



int i = I;
if (i < M) {
double *cm2 = A[i];


int j = J;
if (j < Q) {
double tmp = 0.0;


for (int k = 0; k < N; ++k) {

double *cm3 = C[k];

for (int l = 0; l < P; ++l) {


tmp += (cm3[j] * B[((k * P) + l)] * D[l]);
}
}
cm2[j] += tmp;
}
}

long time = timer_end(start);
printf("%ld\n", time);

fprintf(stderr, "%f\n", A[M - 1][Q - 1]);
free(A);
free(B);
free(C);
free(D);

return 0;
}