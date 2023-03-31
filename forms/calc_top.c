/* Form definition file generated by fdesign on Fri Mar 31 09:27:01 2023 */

#include <stdlib.h>
#include "calc_top.h"



/***************************************
 ***************************************/

FD_calc_top *
create_form_calc_top( void )
{
    FL_OBJECT *obj;
    FD_calc_top *fdui = ( FD_calc_top * ) fl_malloc( sizeof *fdui );

    fdui->vdata = fdui->cdata = NULL;
    fdui->ldata = 0;

    fdui->calc_top = fl_bgn_form( FL_NO_BOX, 608, 558 );

    obj = fl_add_box( FL_FLAT_BOX, 0, 0, 608, 558, "" );

    obj = fl_add_box( FL_UP_BOX, 90, 90, 150, 20, "" );
    fl_set_object_color( obj, FL_WHITE, FL_COL1 );

    fdui->d1 = obj = fl_add_button( FL_NORMAL_BUTTON, 140, 240, 40, 30, "1" );
    fl_set_button_shortcut( obj, "1", 1 );
    fl_set_object_color( obj, FL_BLACK, FL_COL1 );
    fl_set_object_lcolor( obj, FL_WHITE );
    fl_set_object_callback( obj, cb_digit, 1 );

    fdui->d2 = obj = fl_add_button( FL_NORMAL_BUTTON, 180, 240, 40, 30, "2" );
    fl_set_button_shortcut( obj, "2", 1 );
    fl_set_object_color( obj, FL_BLACK, FL_COL1 );
    fl_set_object_lcolor( obj, FL_WHITE );
    fl_set_object_callback( obj, cb_digit, 2 );

    fdui->d3 = obj = fl_add_button( FL_NORMAL_BUTTON, 220, 240, 40, 30, "3" );
    fl_set_button_shortcut( obj, "3", 1 );
    fl_set_object_color( obj, FL_BLACK, FL_COL1 );
    fl_set_object_lcolor( obj, FL_WHITE );
    fl_set_object_callback( obj, cb_digit, 3 );

    fdui->sub = obj = fl_add_button( FL_NORMAL_BUTTON, 90, 180, 40, 30, "-" );
    fl_set_object_color( obj, FL_BLACK, FL_COL1 );
    fl_set_object_lcolor( obj, FL_WHITE );
    fl_set_object_callback( obj, cb_arith, 1 );

    fdui->add = obj = fl_add_button( FL_NORMAL_BUTTON, 90, 210, 40, 30, "+" );
    fl_set_object_color( obj, FL_BLACK, FL_COL1 );
    fl_set_object_lcolor( obj, FL_WHITE );
    fl_set_object_callback( obj, cb_arith, 2 );

    fdui->mul = obj = fl_add_button( FL_NORMAL_BUTTON, 90, 240, 40, 30, "X" );
    fl_set_object_color( obj, FL_BLACK, FL_COL1 );
    fl_set_object_lcolor( obj, FL_WHITE );
    fl_set_object_callback( obj, cb_arith, 3 );

    fdui->div = obj = fl_add_button( FL_NORMAL_BUTTON, 90, 270, 40, 30, "/" );
    fl_set_object_color( obj, FL_BLACK, FL_COL1 );
    fl_set_object_lcolor( obj, FL_WHITE );
    fl_set_object_callback( obj, cb_arith, 4 );

    obj = fl_add_button( FL_NORMAL_BUTTON, 140, 270, 40, 30, "0" );
    fl_set_object_color( obj, FL_BLACK, FL_COL1 );
    fl_set_object_lcolor( obj, FL_WHITE );
    fl_set_object_callback( obj, cb_digit, 0 );

    fdui->enter = obj = fl_add_button( FL_NORMAL_BUTTON, 90, 140, 70, 30, "Enter^" );
    fl_set_object_color( obj, FL_BLACK, FL_COL1 );
    fl_set_object_lcolor( obj, FL_WHITE );
    fl_set_object_lsize( obj, FL_NORMAL_SIZE );
    fl_set_object_lstyle( obj, FL_BOLD_STYLE + FL_SHADOW_STYLE );
    fl_set_object_callback( obj, cb_enter, 0 );

    fdui->d4 = obj = fl_add_button( FL_NORMAL_BUTTON, 140, 210, 40, 30, "4" );
    fl_set_object_color( obj, FL_BLACK, FL_COL1 );
    fl_set_object_lcolor( obj, FL_WHITE );
    fl_set_object_callback( obj, cb_digit, 4 );

    fdui->d5 = obj = fl_add_button( FL_NORMAL_BUTTON, 180, 210, 40, 30, "5" );
    fl_set_object_color( obj, FL_BLACK, FL_COL1 );
    fl_set_object_lcolor( obj, FL_WHITE );
    fl_set_object_callback( obj, cb_digit, 5 );

    fdui->d6 = obj = fl_add_button( FL_NORMAL_BUTTON, 220, 210, 40, 30, "6" );
    fl_set_object_color( obj, FL_BLACK, FL_COL1 );
    fl_set_object_lcolor( obj, FL_WHITE );
    fl_set_object_callback( obj, cb_digit, 6 );

    fdui->d7 = obj = fl_add_button( FL_NORMAL_BUTTON, 140, 180, 40, 30, "7" );
    fl_set_object_color( obj, FL_BLACK, FL_COL1 );
    fl_set_object_lcolor( obj, FL_WHITE );
    fl_set_object_callback( obj, cb_digit, 7 );

    fdui->d8 = obj = fl_add_button( FL_NORMAL_BUTTON, 180, 180, 40, 30, "8" );
    fl_set_object_color( obj, FL_BLACK, FL_COL1 );
    fl_set_object_lcolor( obj, FL_WHITE );
    fl_set_object_callback( obj, cb_digit, 8 );

    fdui->d9 = obj = fl_add_button( FL_NORMAL_BUTTON, 220, 180, 40, 30, "9" );
    fl_set_object_color( obj, FL_BLACK, FL_COL1 );
    fl_set_object_lcolor( obj, FL_WHITE );
    fl_set_object_callback( obj, cb_digit, 9 );

    fdui->display = obj = fl_add_text( FL_NORMAL_TEXT, 90, 40, 180, 50, "text" );
    fl_set_object_color( obj, FL_WHITE, FL_MCOL );
    fl_set_object_lcolor( obj, FL_RED );

    obj = fl_add_box( FL_UP_BOX, 90, 110, 190, 20, "" );
    fl_set_object_color( obj, FL_WHITE, FL_COL1 );

    fdui->g_radix = fl_bgn_group( );

    fdui->pb_dec = obj = fl_add_checkbutton( FL_RADIO_BUTTON, 140, 90, 50, 20, "DEC" );
    fl_set_object_color( obj, FL_WHITE, FL_DARKMAGENTA );
    fl_set_object_callback( obj, cb_mode, 2 );
    fl_set_button( obj, 1 );

    fdui->pb_hex = obj = fl_add_checkbutton( FL_RADIO_BUTTON, 90, 90, 50, 20, "HEX" );
    fl_set_object_color( obj, FL_WHITE, FL_DARKMAGENTA );
    fl_set_object_callback( obj, cb_mode, 1 );

    fdui->pb_bin = obj = fl_add_checkbutton( FL_RADIO_BUTTON, 190, 90, 50, 20, "BIN" );
    fl_set_object_color( obj, FL_WHITE, FL_DARKMAGENTA );
    fl_set_object_callback( obj, cb_mode, 3 );

    fl_end_group( );

    fdui->g_wsize = fl_bgn_group( );

    fdui->pb_32 = obj = fl_add_checkbutton( FL_RADIO_BUTTON, 140, 110, 50, 20, "32" );
    fl_set_object_color( obj, FL_WHITE, FL_DARKMAGENTA );
    fl_set_object_callback( obj, cb_mode, 5 );
    fl_set_button( obj, 1 );

    fdui->pb_64 = obj = fl_add_checkbutton( FL_RADIO_BUTTON, 90, 110, 50, 20, "64" );
    fl_set_object_color( obj, FL_WHITE, FL_DARKMAGENTA );
    fl_set_object_callback( obj, cb_mode, 4 );

    fdui->pb_8 = obj = fl_add_checkbutton( FL_RADIO_BUTTON, 240, 110, 50, 20, "8" );
    fl_set_object_color( obj, FL_WHITE, FL_DARKMAGENTA );
    fl_set_object_callback( obj, cb_mode, 7 );

    fl_end_group( );

    fdui->pb_16 = obj = fl_add_checkbutton( FL_RADIO_BUTTON, 190, 110, 50, 20, "16" );
    fl_set_object_color( obj, FL_WHITE, FL_DARKMAGENTA );
    fl_set_object_callback( obj, cb_mode, 6 );

    fl_end_form( );

    fdui->calc_top->fdui = fdui;

    return fdui;
}
