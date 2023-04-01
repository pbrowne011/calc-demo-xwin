#include <stdio.h>

#include "calc_top.h"
#include "calc.h"

/* Callbacks and freeobj handles for form calc_top */

/***************************************
 ***************************************/

void cb_mode( FL_OBJECT * ob,
         long        data )
{

  // switch modes
#ifdef DEBUG
  printf("cb_mode: %ld\n", data);
#endif
  
  push = 1;

  switch( data) {

  // toggle signed mode
  case M_SIG:
    sign ^= 1;
    break;

  // set the radix
  case M_HEX:
    radix = 16;
    break;
  case M_DEC:
    radix = 10;
    break;
  case M_BIN:
    radix = 2;
    break;

  // change word size, deal with sign extend etc
  // operate on entire stack
  case M_64:
  case M_32:
  case M_16:
  case M_8:
#ifdef DEBUG
    printf("Set word size code: %ld\n", data);
#endif
    set_new_word_size( data);
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

  if( push) {
    push = 0;
    stack_up();
    r_display.u64 = 0;
  }

  // handle one digit, ignore wordsize for now
  if( data < radix)
    r_display.u64 = (r_display.u64 * radix) + data;

  calc_update_display();
}


/***************************************
 ***************************************/

void cb_arith( FL_OBJECT * ob,
         long        data )
{
    /* Fill-in code for callback here */
#ifdef DEBUG
  printf("cb_arith: %ld\n", data);
#endif
  push = 1;

  switch( data) {
  case A_CLR:
    r_display.u64 = 0;
    break;
  case A_SUB:
    r_y.u64 -= r_x.u64;
    stack_down_copy();
    break;
  case A_ADD:
    r_y.u64 += r_x.u64;
    stack_down_copy();
    break;
  case A_MUL:
    r_y.u64 *= r_x.u64;
    stack_down_copy();
    break;
  case A_DIV:
    r_y.u64 /= r_x.u64;
    stack_down_copy();
    break;
  }

  calc_update_display();
}


/***************************************
 ***************************************/

void cb_stack( FL_OBJECT * ob,
         long        data )
{
    /* Fill-in code for callback here */
  push = 0;
  
#ifdef DEBUG
  printf("cb_stack: %ld\n", data);
#endif
  switch( data) {
  case S_DROP:			/* roll-down */
    stack_down();
    break;
  case S_PUSH:			/* ENTER */
    stack_up();
    r_x.u64 = 0;
    break;
  case S_SWAP:			/* X/Y */
    r_temp = r_x;
    r_x = r_y;
    r_y = r_temp;
    break;
  }

  calc_update_display();
}





