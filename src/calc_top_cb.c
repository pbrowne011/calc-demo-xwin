#include <stdio.h>

#include "calc_top.h"

extern FD_calc_top *fd_calc_top;  // <ESH> moved to global

/* Callbacks and freeobj handles for form calc_top */

/***************************************
 ***************************************/

void cb_digit( FL_OBJECT * ob,
         long        data )
{
  FD_calc_top *f;		/* GLOBAL struct pointer */
  char str[10];

  f = fd_calc_top;

  snprintf( str, sizeof(str), "%ld", data);

  // set display to digit for now for testing
  fl_set_object_label( f->display, str);
}


/***************************************
 ***************************************/

void cb_arith( FL_OBJECT * ob,
         long        data )
{
    /* Fill-in code for callback here */
}


/***************************************
 ***************************************/

void cb_enter( FL_OBJECT * ob,
         long        data )
{
    /* Fill-in code for callback here */
}




