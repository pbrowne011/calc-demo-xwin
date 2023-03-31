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
  printf("cb_mode: %ld\n", data);
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
    printf("Set word size code: %ld\n", data);
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

  switch( data) {
  case A_CLR:
    r_display.u64 = 0;
    break;
  case A_SUB:
  case A_ADD:
  case A_MUL:
  case A_DIV:
  }

  calc_update_display();
}


/***************************************
 ***************************************/

void cb_stack( FL_OBJECT * ob,
         long        data )
{
    /* Fill-in code for callback here */

  printf("cb_stack: %ld\n", data);
  switch( data) {
  case S_DROP:
    stack_down();
    break;
  case S_PUSH:
    stack_up();
    r_x.u64 = 0;
    break;
  }

  calc_update_display();
}





