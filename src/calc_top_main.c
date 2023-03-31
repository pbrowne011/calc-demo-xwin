#include <stdint.h>

#include "calc.h"
#include "calc_top.h"

FD_calc_top *fd_calc_top;  // <ESH> moved to global

union u_reg r_display;

int
main( int    argc,
      char * argv[ ] )
{
  //    FD_calc_top *fd_calc_top;  <ESH> moved to global

    fl_initialize( &argc, argv, 0, 0, 0 );
    fd_calc_top = create_form_calc_top( );

    /* Fill-in form initialization code */

    /* Show the first form */

    fl_show_form( fd_calc_top->calc_top, FL_PLACE_CENTERFREE, FL_FULLBORDER, "calc_top" );

    fl_do_forms( );

    if ( fl_form_is_visible( fd_calc_top->calc_top ) )
        fl_hide_form( fd_calc_top->calc_top );
    fl_free( fd_calc_top );
    fl_finish( );

    return 0;
}
