#include <assert.h>
#include <stdio.h>
#include "../app/NombreCombinaison.h"
#include "../app/timer.h"

/* Liste des prototypes*/
void testNombreCombinaison();

int main(void)
{
	testNombreCombinaison();
	return 0;
}

void testNombreCombinaison()
{
  puts("L: Debut du test testNombreCombinaison");
  long long test_time;
  test_time= time_start();
	
	// Tests
	assert(nombreCombinaisonsDunNombreDigit(0) == 0);
	assert(nombreCombinaisonsDunNombreDigit(1)  == 10);
	assert(nombreCombinaisonsDunNombreDigit(4) == 715);
	assert(nombreCombinaisonsDunNombreDigit(17) == 3124550);
	
	
	printf("T: %lld\n", time_end(test_time));
	puts("L: Fin du test testNombreCombinaison");
	puts("");
}
