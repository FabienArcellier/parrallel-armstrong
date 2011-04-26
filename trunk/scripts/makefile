LD_LIBRARY_PATH=/opt/mpfr/lib:/opt/gmp/lib:/opt/mpc/lib

GCC_VERSION=4.5.1
PREFIX=/opt/gcc/${GCC_VERSION}/bin
CC=${PREFIX}/gcc
#CFLAG=-Wall -lm -O3 -fopenmp
CFLAG=-Wall -lm -O3 -DNDEBUG=1 -fopenmp
LDFLAG=-Wall -lm -fopenmp

# CC=gcc
# CFLAG=-Wall -lm -O3 -fopenmp
# CFLAG=-Wall -lm -O3 -DNDEBUG=1 -fopenmp
# LDFLAG=-Wall -lm -fopenmp

# CC=icc
# CFLAG=-Werror-all -O3 -DNDEBUG=1 -openmp -axSSE2 -parallel
# LDFLAG=-Werror-all -openmp -axSSE2 -parallel

CPARALLEL= -pthread -ftree-parallelize-loops=40
PATH_BUILD=../build
PATH_APP=../app
PATH_TESTS=../tests


Production: clean init Smallbrain

Tests: clean init TestPuissance10 TestPuissanceDigit TestTacheCombinaisonEstNombreArmstrong TestCombinaison TestMathematique TestCalculArmstrong SpikeCompterPermutationUnique TestProcs

Smallbrain: timer.o mathematique.o puissance10.o puissanceDigit.o combinaison.o CalculArmstrong.o ordonnanceur.o main.o hardware.o
	$(CC) $(LDFLAG) -o $(PATH_BUILD)/$@ $^

TestCalculArmstrong: timer.o mathematique.o puissanceDigit.o combinaison.o puissance10.o CalculArmstrong.o testNbArmstrong.o
	$(CC) $(LDFLAG) -o $(PATH_BUILD)/$@ $^

SpikeCompterPermutationUnique: timer.o mathematique.o puissance10.o combinaison.o spikeCompterPermutationUnique.o
	$(CC) $(LDFLAG) -o $(PATH_BUILD)/$@ $^

TestMathematique: timer.o mathematique.o testMathematique.o
	$(CC) $(LDFLAG) -o $(PATH_BUILD)/$@ $^

TestCombinaison: timer.o mathematique.o puissance10.o combinaison.o testCombinaison.o 
	$(CC) $(LDFLAG) -o $(PATH_BUILD)/$@ $^ 

TestPuissance10: timer.o mathematique.o puissance10.o testPuissance10.o
	$(CC) $(LDFLAG) -o $(PATH_BUILD)/$@ $^

TestPuissanceDigit: timer.o mathematique.o puissanceDigit.o testPuissanceDigit.o
	$(CC) $(LDFLAG) -o $(PATH_BUILD)/$@ $^

TestProcs: timer.o hardware.o testProcesseurs.o
	$(CC) $(LDFLAG) -o $(PATH_BUILD)/$@ $^

main.o: $(PATH_APP)/main.c
	$(CC) $(CFLAG) -c $<

testNbArmstrong.o:  $(PATH_TESTS)/testNbArmstrong.c
	$(CC) $(CFLAG) -c $<

ordonnanceur.o: $(PATH_APP)/ordonnanceur.c $(PATH_APP)/ordonnanceur.h
	$(CC) $(CFLAG) -c  $<

CalculArmstrong.o:$(PATH_APP)/CalculArmstrong.c $(PATH_APP)/CalculArmstrong.h
	$(CC) $(CFLAG) -c $<
	
testCombinaison.o: $(PATH_TESTS)/testCombinaison.c
	$(CC) $(CFLAG) -c $<
	
spikeCompterPermutationUnique.o: $(PATH_TESTS)/spikeCompterPermutationUnique.c
	$(CC) $(CFLAG) -c $<

combinaison.o: $(PATH_APP)/combinaison.c $(PATH_APP)/combinaison.h
	$(CC) $(CFLAG) -c $<
	
testPuissance10.o: $(PATH_TESTS)/testPuissance10.c
	$(CC) $(CFLAG) -c $<

puissance10.o: $(PATH_APP)/puissance10.c $(PATH_APP)/puissance10.h
	$(CC) $(CFLAG) -c $<
	
testPuissanceDigit.o: $(PATH_TESTS)/testPuissanceDigit.c
	$(CC) $(CFLAG) -c $<
	
puissanceDigit.o: $(PATH_APP)/puissanceDigit.c $(PATH_APP)/puissanceDigit.h
	$(CC) $(CFLAG) -c $<
	
testMathematique.o: $(PATH_TESTS)/testMathematique.c
	$(CC) $(CFLAG) -c $<

mathematique.o: $(PATH_APP)/mathematique.c $(PATH_APP)/mathematique.h
	$(CC) $(CFLAG) -c $<

timer.o: $(PATH_APP)/timer.c $(PATH_APP)/timer.h
	$(CC) $(CFLAG) -c $<
	
hardware.o: $(PATH_APP)/hardware.c $(PATH_APP)/hardware.h
	$(CC) $(CFLAG) -c $<

testProcesseurs.o: $(PATH_TESTS)/testProcesseurs.c
	$(CC) $(CFLAG) -c $<

clean:
	-rm *.o
	-rm -R ../build/*
	-cp Exec.sh ../build/
	
init:
	-mkdir ../build
	-mkdir ../build/help
