#include "asan-demo.h"

int multiply(int a, int b) {
  return a * b;
}

void leaker(void) {
  void * buffer = malloc(256);
}
