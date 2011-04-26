#include <assert.h>
#include <stdio.h>
#include "../app/timer.h"
#include "../app/combinaison.h"

#define VALEUR_DEBUT {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0}
#define ORDRE 19

// #define VALEUR_DEBUT {0,0,0}
// #define ORDRE 3

int main()
{
	long long compteur_armstrong_a_calculer = 0;
	char combinaison[ORDRE] = VALEUR_DEBUT;
	
	CachePuissance10 * cachePuissance10;
	cachePuissance10 = InitCachePuissance10(ORDRE);
	
	puts("L: Debut du test spikeCompterPermutationUnique");
	
	long long test_time;
  test_time= time_start();
	
	while(IncrementerTableauxDigitCombinaisonUnique(combinaison, ORDRE) != 1)
	{
		// printf("D: tableau : %lld\n", ConvertirTableauDigitVersNombre(combinaison, 3, &cachePuissance10));
		compteur_armstrong_a_calculer++;
	}
	
	printf("T: %lld\n", time_end(test_time));
	
	printf("Nombre de nombre a calculer : %lld\n", compteur_armstrong_a_calculer);
	
	puts("L: Fin du test spikeCompterPermutationUnique");
	
	return 0;
}
