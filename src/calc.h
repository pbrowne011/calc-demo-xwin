#include "calc_top.h"

#include <stdint.h>

// mode callback args
#define M_SIG 0
#define M_HEX 1
#define M_DEC 2
#define M_BIN 3
#define M_64 4
#define M_32 5
#define M_16 6
#define M_8 7

// arith callback args
#define A_SUB 1
#define A_ADD 2
#define A_MUL 3
#define A_DIV 4

union u_reg {
  uint8_t u8;
  uint16_t u16;
  uint32_t u32;
  uint64_t u64;
};

#ifdef CALC_TOP_MAIN
#define alloc
#else
#define alloc extern
#endif

// global variables
alloc FD_calc_top *fd_calc_top;  // <ESH> moved to global
alloc union u_reg r_display;
alloc int radix;
alloc int wsize;
alloc int sign;

// functions

// update display from r_display
void calc_update_display();

// sprintf to binary nb bytes
void sp_bin( char *s, int siz, int nb, uint64_t v);
