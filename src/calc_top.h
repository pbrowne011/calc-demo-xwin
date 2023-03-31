/* Header file generated by fdesign on Fri Mar 31 09:12:13 2023 */

#ifndef FD_calc_top_h_
#define FD_calc_top_h_

#include <forms.h>

/* Callbacks, globals and object handlers */

void cb_digit( FL_OBJECT *, long );
void cb_arith( FL_OBJECT *, long );
void cb_enter( FL_OBJECT *, long );
void cb_mode( FL_OBJECT *, long );


/* Forms and Objects */

typedef struct {
    FL_FORM   * calc_top;
    void      * vdata;
    char      * cdata;
    long        ldata;
    FL_OBJECT * d1;
    FL_OBJECT * d2;
    FL_OBJECT * d3;
    FL_OBJECT * sub;
    FL_OBJECT * add;
    FL_OBJECT * mul;
    FL_OBJECT * div;
    FL_OBJECT * enter;
    FL_OBJECT * d4;
    FL_OBJECT * d5;
    FL_OBJECT * d6;
    FL_OBJECT * d7;
    FL_OBJECT * d8;
    FL_OBJECT * d9;
    FL_OBJECT * display;
    FL_OBJECT * g_radix;
    FL_OBJECT * pb_dec;
    FL_OBJECT * pb_hex;
    FL_OBJECT * pb_bin;
    FL_OBJECT * g_wsize;
    FL_OBJECT * pb_32;
    FL_OBJECT * pb_64;
    FL_OBJECT * pb_8;
} FD_calc_top;

FD_calc_top * create_form_calc_top( void );

#endif /* FD_calc_top_h_ */
