#include <assert.h>
#include <stdio.h>
#include "../app/hardware.h"
#include "../app/timer.h"

/* Liste des prototypes*/
void testProcesseurs();

int main(void)
{
	testProcesseurs();
	return 0;
}

void testProcesseurs()
{
  puts("L: Debut du test testProcesseurs");
  long long test_time;
  test_time= time_start();
	
	// Tests
	printf("Nb : processeurs : %d\n",ObtenirNombreProcesseurs());
	printf("Nb : threads : %d\n",ObtenirNombreThreads());
	printf("T: %lld\n", time_end(test_time));
	puts("L: Fin du test testProcesseurs");
	puts("");
}
