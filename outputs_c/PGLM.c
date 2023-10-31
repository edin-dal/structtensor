
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

const int W = atoi(argv[1]);

double (*A) = malloc(sizeof(double) * W);
for (size_t i = 0; i < W; ++i) {
int flag1 = 0;
if (flag1) {
A[i] = (double) (rand() % 1000000) / 1e6;
} else {
A[i] = 0.0;
}
}

double (*B)[W] = malloc(sizeof(double) * W * W);
for (size_t i = 0; i < W; ++i) {
for (size_t j = 0; j < W; ++j) {
int flag2 = 0 <= i && W > i && 0 <= j && W > j && 0 <= i && W > i && (0 + 1) > i && 0 <= j && W > j || 0 <= i && W > i && 0 <= j && W > j && 1 <= i && W > i && (i - 1) == j;
if (flag2) {
B[i][j] = (double) (rand() % 1000000) / 1e6;
} else {
B[i][j] = 0.0;
}
}
}

double (*C) = malloc(sizeof(double) * W);
for (size_t j = 0; j < W; ++j) {
int flag3 = 0 <= j && W > j;
if (flag3) {
C[j] = (double) (rand() % 1000000) / 1e6;
} else {
C[j] = 0.0;
}
}


auto computation_start = duration_cast<microseconds>(system_clock::now().time_since_epoch()).count();

{
  for (int i = 0; i < W; i += 1)
    A[0] += B[0][i] * C[i];
  for (int i = 0; i < W - 1; i += 1)
    A[i + 1] += B[i + 1][i] * C[i];
}

auto computation_end = duration_cast<microseconds>(system_clock::now().time_since_epoch()).count();
auto computation_time = computation_end - computation_start;
std::cout << "computation: " << computation_time << "\n";




free(A);
free(B);
free(C);
return 0;
}