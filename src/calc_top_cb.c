#include <stdio.h>

#include "calc_top.h"
#include "calc.h"

/* Callbacks and freeobj handles for form calc_top */

/***************************************
 ***************************************/

void cb_mode( FL_OBJECT * ob,
         long        data )
{
    /* Fill-in code for callback here */
  printf("cb_mode: %ld\n", data);
  switch( data) {
  case M_SIG:
    sign ^= 1;
    break;
  case M_HEX:
    radix = 16;
    break;
  case M_DEC:
    radix = 10;
    break;
  case M_BIN:
    radix = 2;
    break;
  case M_64:
    wsize = 64;
    break;
  case M_32:
    wsize = 32;
    break;
  case M_16:
    wsize = 16;
    break;
  case M_8:
    wsize = 8;
    break;
  default:
    printf("Unknown mode %ld\n", data);

  }

  calc_update_display();  
}

/***************************************
 ***************************************/

void cb_digit( FL_OBJECT * ob,
         long        data )
{
  FD_calc_top *f;		/* GLOBAL struct pointer */
  char str[10];

  f = fd_calc_top;

  // handle one digit, ignore wordsize for now
  r_display.u64 = (r_display.u64 * radix) + data;

  calc_update_display();
}


/***************************************
 ***************************************/

void cb_arith( FL_OBJECT * ob,
         long        data )
{
    /* Fill-in code for callback here */
  printf("cb_arith: %ld\n", data);

  calc_update_display();
}


/***************************************
 ***************************************/

void cb_enter( FL_OBJECT * ob,
         long        data )
{
    /* Fill-in code for callback here */
  printf("cb_enter: %ld\n", data);

  r_display.u64 = 0;

  calc_update_display();
}




