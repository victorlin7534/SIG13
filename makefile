default: signal.o
	gcc -o test signal.o
signal.o: signal.c
	gcc -c signal.c
run:
	./test
clean:
	rm -f *txt test* *.o *.out *exe 
