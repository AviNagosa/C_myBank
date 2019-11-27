all: libmyBank.a mains
myBanks: libmyBank.a
mains: main.o libmyBank.a
	gcc -Wall -g -o mains main.o libmyBank.a
libmyBank.a: myBank.o
	ar rc libmyBank.a myBank.o
myBank.o: myBank.c myBank.h
	gcc -Wall -g -c myBank.c
main.o: main.c myBank.h
	gcc -Wall -g -c main.c
.PHONY: clean
clean:
	rm -f *.o *.a *.so mains



