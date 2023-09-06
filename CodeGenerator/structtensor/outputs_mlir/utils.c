#include <stdio.h>
#include<sys/time.h>
#include<stdint.h>
#include <time.h>

typedef int64_t i64;

void print_i32(int n) {
    printf("%d\n", n);
}

void print_i64(i64 n) {
    printf("%ld\n", n);
}

void print_f64_cerr(double n) {
    fprintf(stderr, "%f\n", n);
}

i64 timer() {
  // return epoch in us
  struct timespec t;
  clock_gettime(CLOCK_MONOTONIC, &t);
  return (t.tv_sec) * (i64) 1000000 + (t.tv_nsec / 1000);
}

i64 timer_elapsed(i64 start) {
  // return elapsed time
  i64 end = timer();
  return end - start;
}
