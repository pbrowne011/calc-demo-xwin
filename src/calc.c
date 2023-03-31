#include "calc.h"
#include <inttypes.h>


char *format_for_display( union u_reg r_format) {
  
  printf("radix: %d  wsize: %d  sign: %d\n", radix, wsize, sign);

  static char buff[70];

  // ugly nested switch for now
  switch( radix) {
  case 2:
    switch( wsize) {
    case 8:			/* print 8 bit binary */
      sp_bin( buff, sizeof(buff), 1, r_format.u64);
      break;
    case 16:
      sp_bin( buff, sizeof(buff), 2, r_format.u64);
      break;
    case 32:
      sp_bin( buff, sizeof(buff), 4, r_format.u64);
      break;
    case 64:
      sp_bin( buff, sizeof(buff), 8, r_format.u64);
      break;
    default:
      printf("ERROR!  wsize = %d\n", wsize);
    }
    break;
  case 10:
    switch( wsize) {
    case 8:
      if( sign)
	snprintf( buff, sizeof(buff), "%" PRId8, (int8_t)r_format.u8);
      else
	snprintf( buff, sizeof(buff), "%" PRIu8, r_format.u8);
      break;
    case 16:
      if( sign)
	snprintf( buff, sizeof(buff), "%" PRId16, (int16_t)r_format.u16);
      else
	snprintf( buff, sizeof(buff), "%" PRIu16, r_format.u16);
      break;
    case 32:
      if( sign)
	snprintf( buff, sizeof(buff), "%" PRId32, (int32_t)r_format.u32);
      else
	snprintf( buff, sizeof(buff), "%" PRIu32, r_format.u32);
      break;
    case 64:
      if( sign)
	snprintf( buff, sizeof(buff), "%" PRId64, (int64_t)r_format.u64);
      else
	snprintf( buff, sizeof(buff), "%" PRIu64, r_format.u64);
      break;
    default:
      printf("ERROR!  wsize = %d\n", wsize);
    }
    break;
  case 16:
    switch( wsize) {
    case 8:
      snprintf( buff, sizeof(buff), "%" PRIx8, r_format.u8);
      break;
    case 16:
      snprintf( buff, sizeof(buff), "%" PRIx16, r_format.u16);
      break;
    case 32:
      snprintf( buff, sizeof(buff), "%" PRIx32, r_format.u32);
      break;
    case 64:
      snprintf( buff, sizeof(buff), "%" PRIx64, r_format.u64);
      break;
    default:
      printf("ERROR!  wsize = %d\n", wsize);
    }
    break;
  default:
    break;
  }

  return buff;
}


// update display from r_display
// use radix, wsize, sign
void calc_update_display() {

  fl_set_object_label( fd_calc_top->reg_X, format_for_display( r_x));
  fl_set_object_label( fd_calc_top->reg_Y, format_for_display( r_y));
  fl_set_object_label( fd_calc_top->reg_Z, format_for_display( r_z));
  fl_set_object_label( fd_calc_top->reg_T, format_for_display( r_t));
  
}


// binary print byte
char *sp_byt( char *s, uint8_t v) {
  for( int i=0, b=0x80; i++, b>>=1; i<8)
    *s++ = ((v & b) ? '1' : '0');
  return s;
}

void sp_bin( char *s, int siz, int nb, uint64_t v) {
  char *p = s;
  uint8_t b;

  // loop over nb bytes
  for( int i=0; i<nb; i++) {
    // extract byte to print
    b = (v >> 8*(nb-i-1));
    p = sp_byt( p, b);
    if( i != nb-1)
      *p++ = '.';
  }
  *p++ = '\0';
}


// push stack up, duplicating X
void stack_up() {
  for( int i=STACK_SIZE-1; i>0; i--)
    r_stack[i] = r_stack[i-1];
}

// roll stack down, copying X to T
void stack_down() {
  r_temp = r_display; /* save X */
  for( int i=0; i<STACK_SIZE-1; i++)
    r_stack[i] = r_stack[i+1];
  r_t = r_temp;
}

// change word size
// if increasing and in signed mode, sign-extend
// keep track of old size
void set_new_word_size( int size_code)
{
  static int old_size = DEF_SIZE;
  int new_size;

  switch( size_code) {
  case M_64:
    new_size = 64;
    break;
  case M_32:
    new_size = 32;
    break;
  case M_16:
    new_size = 16;
    break;
  case M_8:
    new_size = 8;
    break;
  default:
    printf("ERROR!  size code: %d should be between %d and %d (inclusive)\n",
	   size_code, M_64, M_8);
  }

  printf("Set word size (old=%d new=%d)\n", old_size, new_size);
  
  wsize = new_size;

  // sign-extend all stack regs to 64 bits if word size larger
  if( (new_size > old_size) && sign) {
    for( int i=0; i<STACK_SIZE; i++)
      r_stack[i].u64 = sign_extend( r_stack[i].u64, old_size);
  }

  // mask high bits if word size smaller
  if( new_size < old_size) {
    for( int i=0; i<STACK_SIZE; i++)
      r_stack[i].u64 = mask_bits( r_stack[i].u64, new_size);
  }

  old_size = wsize;
}

//
// sign-extend from value v interpreted as int8/16/32/64 to 64 bits
//
uint64_t sign_extend( uint64_t v, int siz) {

  printf("Sign extend 0x%" PRIx64 " from %d bits\n", v, siz);

  int64_t r = v;
  
  if( siz < 64) {
    for( int i=siz; i<64; i++) {
      printf(" bit %d test: %d\n", i, (v & (1LL << (siz-1))) != 0);
      if( v & (1LL << (siz-1)))
	r |= 1LL << i;
    }
  }

  return r;
}



//
// zero bits above siz
//
uint64_t mask_bits( uint64_t v, int siz) {

  uint64_t r = v;
  
  switch( siz) {
  case 32:
    r &= 0xffffffff;
    break;
  case 16:
    r &= 0xffff;
    break;
  case 8:
    r &= 0xff;
    break;
  default:
  }

  return r;
}
