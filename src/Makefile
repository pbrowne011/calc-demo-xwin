all: calc

clean:
	rm -f *.o *~ calc

calc: calc_top.o calc_top_cb.o calc_top_main.o
	cc -o calc *.o -lforms
