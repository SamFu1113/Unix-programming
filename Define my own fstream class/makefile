default:mainprog

main.o: main.cpp
	g++ -c  main.cpp

myfstream.o: myfstream.cpp
	g++ -c  myfstream.cpp

lib_functions.a: myfstream.o
	ar -r lib_functions.a myfstream.o

mainprog: lib_functions.a main.o
	g++ main.o lib_functions.a -o mainprog

clean:
	rm -f *.o
	rm -f mainprog
	rm -f lib_functions.a
	rm -f overload.txt write.txt
