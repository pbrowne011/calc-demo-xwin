#include "int_limits.h"
#include <stdio.h>
#include <stdlib.h>

int main( int argc, char *argv[]) {

  int r = strtoul( argv[1], NULL, 0);

  uint64_t u;
  int64_t sp, sn;

  u = MAX_UNSIGNED(r);
  sp = MAX_SIGNED(r);
  sn = MIN_SIGNED(r);

  printf("%2d-bit unsigned max: %" PRIx64 "\n", r, u);
  printf("%2d-bit   signed max: %" PRIx64 "\n", r, sp);
  printf("%2d-bit   signed min: %" PRIx64 "\n", r, sn);
}
