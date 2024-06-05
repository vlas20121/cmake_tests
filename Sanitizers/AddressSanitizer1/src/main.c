#include "asan-demo.h"

int main(void) {
  // 32-bit integer overflow
  int result = multiply(4000000, 4000000);
  printf(
    "4,000,000 x 4,000,000 -> %d (computed) vs. 16,000,000,000,000 "
    "(expected)\n", result
  );

  // Memory leak
  leaker();

  return 0;  
}
