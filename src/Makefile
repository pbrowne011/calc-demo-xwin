all: calc

# include needed for OS-X
CFLAGS = -I/usr/X11/include

#CFLAGS = -DDEBUG

clean:
	rm -f *.o *~ calc

calc_top.o: calc_top.c calc_top.h

calc_top_cb.o: calc_top_cb.c calc.h calc_top.h int_limits.h

calc_top_main.o: calc_top.h calc.h

calc.o: calc.c calc.h int_limits.h

calc: calc_top.o calc_top_cb.o calc_top_main.o calc.o
	cc -o calc $^ -lforms
