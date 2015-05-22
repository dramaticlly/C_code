all: reverse.c
	gcc -Wall reverse.c -o reverse
clean:
	rm -f *.o reverse
	echo CLEAN DONE
