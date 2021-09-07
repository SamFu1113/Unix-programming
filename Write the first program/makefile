
default: a.out

%.o: HW_01.h %.c
	gcc -I. -g -c $*.c

lib_mult.a:
	ar -rs $@ $^
	mult.o
a.out: main.o calculate.o lib_mult.a 
	gcc main.o calculate.o -L. -l_mult -o $@

clean:
	rm -f *.o a.out
