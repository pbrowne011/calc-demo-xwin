#include <inttypes.h>
#include <stdio.h>
#include <stdlib.h>

//
// subtract the most-significant non-zero digit from v with radix
//
uint64_t delete_high_digit( uint64_t v, int radix)
{
  int nd = 0;
  uint64_t t = v;
  uint64_t s = 1;
  // find highest non-zero digit by successive division
  while( t > (uint64_t)radix) {
    nd++;
    t /= radix;
    s *= radix;
  }
  return v - (s*t);
}


int main( int argc, char *argv[]) {
  uint64_t v = strtoul( argv[1], NULL, 0);
  int radix = strtoul( argv[2], NULL, 0);
  
  uint64_t r = delete_high_digit( v, radix);
  printf("original: %" PRIu64 " result= %" PRIu64 "\n", v, r);
  printf("original: 0x%" PRIx64 "\n", v);
  printf("  result: 0x%" PRIx64 "\n", r);
}

