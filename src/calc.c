#include "calc.h"
#include <inttypes.h>

// update display from r_display
// use radix, wsize, sign
void calc_update_display() {

  printf("radix: %d  wsize: %d  sign: %d\n", radix, wsize, sign);

  char buff[70];

  // ugly nested switch for now
  switch( radix) {
  case 2:
    switch( wsize) {
    case 8:			/* print 8 bit binary */
      sp_bin( buff, sizeof(buff), 1, r_display.u64);
      break;
    case 16:
      sp_bin( buff, sizeof(buff), 2, r_display.u64);
      break;
    case 32:
      sp_bin( buff, sizeof(buff), 4, r_display.u64);
      break;
    case 64:
      sp_bin( buff, sizeof(buff), 8, r_display.u64);
      break;
    default:
      printf("ERROR!  wsize = %d\n", wsize);
    }
    break;
  case 10:
    switch( wsize) {
    case 8:
      if( sign)
	snprintf( buff, sizeof(buff), "%" PRId8, (int8_t)r_display.u8);
      else
	snprintf( buff, sizeof(buff), "%" PRIu8, r_display.u8);
      break;
    case 16:
      if( sign)
	snprintf( buff, sizeof(buff), "%" PRId16, (int16_t)r_display.u16);
      else
	snprintf( buff, sizeof(buff), "%" PRIu16, r_display.u16);
      break;
    case 32:
      if( sign)
	snprintf( buff, sizeof(buff), "%" PRId32, (int32_t)r_display.u32);
      else
	snprintf( buff, sizeof(buff), "%" PRIu32, r_display.u32);
      break;
    case 64:
      if( sign)
	snprintf( buff, sizeof(buff), "%" PRId64, (int64_t)r_display.u64);
      else
	snprintf( buff, sizeof(buff), "%" PRIu64, r_display.u64);
      break;
    default:
      printf("ERROR!  wsize = %d\n", wsize);
    }
    break;
  case 16:
    switch( wsize) {
    case 8:
      snprintf( buff, sizeof(buff), "%" PRIx8, r_display.u8);
      break;
    case 16:
      snprintf( buff, sizeof(buff), "%" PRIx16, r_display.u16);
      break;
    case 32:
      snprintf( buff, sizeof(buff), "%" PRIx32, r_display.u32);
      break;
    case 64:
      snprintf( buff, sizeof(buff), "%" PRIx64, r_display.u64);
      break;
    default:
      printf("ERROR!  wsize = %d\n", wsize);
    }
    break;
  default:
    break;
  }

  
  fl_set_object_label( fd_calc_top->display, buff);
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
