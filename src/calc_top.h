/* Header file generated by fdesign on Fri Mar 31 15:33:35 2023 */

#ifndef FD_calc_top_h_
#define FD_calc_top_h_

#include <forms.h>

/* Callbacks, globals and object handlers */

void cb_digit( FL_OBJECT *, long );
void cb_arith( FL_OBJECT *, long );
void cb_stack( FL_OBJECT *, long );
void cb_mode( FL_OBJECT *, long );


/* Forms and Objects */

typedef struct {
    FL_FORM   * calc_top;
    void      * vdata;
    char      * cdata;
    long        ldata;
    FL_OBJECT * reg_Y;
    FL_OBJECT * d1;
    FL_OBJECT * d2;
    FL_OBJECT * d3;
    FL_OBJECT * sub;
    FL_OBJECT * add;
    FL_OBJECT * mul;
    FL_OBJECT * div;
    FL_OBJECT * d_0;
    FL_OBJECT * enter;
    FL_OBJECT * d4;
    FL_OBJECT * d5;
    FL_OBJECT * d6;
    FL_OBJECT * d7;
    FL_OBJECT * d8;
    FL_OBJECT * d9;
    FL_OBJECT * reg_X;
    FL_OBJECT * g_radix;
    FL_OBJECT * pb_dec;
    FL_OBJECT * pb_hex;
    FL_OBJECT * pb_bin;
    FL_OBJECT * g_wsize;
    FL_OBJECT * pb_32;
    FL_OBJECT * pb_64;
    FL_OBJECT * pb_8;
    FL_OBJECT * pb_16;
    FL_OBJECT * lab_signed;
    FL_OBJECT * d_A;
    FL_OBJECT * d_B;
    FL_OBJECT * d_C;
    FL_OBJECT * d_D;
    FL_OBJECT * d_E;
    FL_OBJECT * d_F;
    FL_OBJECT * b_drop;
    FL_OBJECT * reg_Z;
    FL_OBJECT * reg_T;
} FD_calc_top;

FD_calc_top * create_form_calc_top( void );

#endif /* FD_calc_top_h_ */
