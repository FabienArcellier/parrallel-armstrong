#include <assert.h>
#include <stdio.h>
#include "../app/timer.h"
#include "../app/fabriqueTacheCombinaisonEstNombreArmstrong.h"

/* Liste des prototypes */
void TestFabriqueTacheCombinaisonEstNombreArmstrong_ObtenirTache();

int main(void)
{
	TestFabriqueTacheCombinaisonEstNombreArmstrong_ObtenirTache();
	return 0;
}

void TestFabriqueTacheCombinaisonEstNombreArmstrong_ObtenirTache()
{
  CachePuissance10 * cachePuissance10;
  cachePuissance10 = InitCachePuissance10(19);

  CachePuissanceDigit *cachePuissanceDigit;
  cachePuissanceDigit = InitCachePuissanceDigit(1, 19);

  char borne_inferieure[20], borne_superieure[20]; 

  ConvertirNombreVersTableauDigit(borne_inferieure, 1, 20);
  ConvertirNombreVersTableauDigit(borne_superieure, 4611686018427387899LL, 20);

  long long test_time;
  test_time = time_start();

  FabriqueTacheCombinaisonEstNombreArmstrong *fabrique;
  fabrique = InitialiserFabriqueTacheCombinaisonEstNombreArmstrong(borne_inferieure, 
								    borne_superieure, 
								    1, 
								    20,
								    cachePuissanceDigit, 
								    cachePuissance10);

  int reste_des_taches = 1;

  do
  {
	  TacheCombinaisonEstNombreArmstrong *tache = NULL;
	  reste_des_taches = FabriqueTacheCombinaisonEstNombreArmstrong_ObtenirTacheSuivante(fabrique, &tache);
	  if (reste_des_taches == 1)
	  {
		  // printf("D: ordre_courant %d\n", tache -> ordre_courant);
		  // printf("D: %lld\n", ConvertirTableauDigitVersNombre(tache -> combinaison, tache -> ordre_courant, &cachePuissance10));
		  TacheCombinaisonEstNombreArmstrong_Executer(tache);
		  TacheCombinaisonEstNombreArmstrong_Detruire(tache);
	  }
  } while(reste_des_taches == 1);

  printf("T : %lld\n", time_end(test_time));

  return;
}
