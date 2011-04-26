Main: clean init puissance10.o puissanceDigit.o main.o
	cc -Wall -o AfficherNombresArmstrong puissanceDigit.o puissance10.o main.o
	
main.o: ./main.c
	cc -Wall -O2 -c ./main.c

puissance10.o: ./puissance10.c ./puissance10.h
	cc -Wall -O2 -c ./puissance10.c
	
puissanceDigit.o: ./puissanceDigit.c ./puissanceDigit.h
	cc -Wall -O2 -c ./puissanceDigit.c
	
clean:
	-rm *.o
	-rm -R ../../../build/*
	-rmdir ../../../build
	
init:
	-mkdir ../../../build
	-mkdir ../../../build/help
