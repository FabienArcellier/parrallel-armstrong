#include <assert.h>
#include <stdio.h>
#include "../app/mathematique.h"
#include "../app/tacheCombinaisonEstNombreArmstrong.h"
#include "../app/timer.h"

/* Liste des prototypes*/
void testCombinaisonEstNombreArmstrong_Clone();
void testCombinaisonEstNombreArmstrong_Executer371();

int main(void)
{
  testCombinaisonEstNombreArmstrong_Clone();
  testCombinaisonEstNombreArmstrong_Executer371();
  return 0;
}

void testCombinaisonEstNombreArmstrong_Clone()
{
  puts("Debut testCombinaisonEstNombreArmstrong_Clone");
  
  char combinaison[3] = {1, 2, 3};
  char combinaison2[3] = {1, 2, 4};
  TacheCombinaisonEstNombreArmstrong *tache1, *tache2;
  
  CachePuissance10 * cachePuissance10;
  cachePuissance10 = InitCachePuissance10(5);
	
  CachePuissanceDigit *cachePuissanceDigit;
  cachePuissanceDigit = InitCachePuissanceDigit(1, 5);
  
  long long test_time_init;
  test_time_init = time_start();
  
  tache1 = TacheCombinaisonEstNombreArmstrong_Init(3, 200, 400, cachePuissanceDigit, cachePuissance10);
  TacheCombinaisonEstNombreArmstrong_SetCombinaison(tache1, combinaison);
  
  
  
  printf("T: Init : %lld\n", time_end(test_time_init));
  
  long long test_time_clone;
  test_time_clone= time_start();
  
  tache2 = TacheCombinaisonEstNombreArmstrong_Clone(tache1);
  TacheCombinaisonEstNombreArmstrong_SetCombinaison(tache2, combinaison2);
  
  printf("T: Clone : %lld\n", time_end(test_time_clone));
  
  assert((tache1 -> combinaison)[1] == 2);
  assert((tache1 -> combinaison)[2] == 3);
  assert((tache1 -> combinaison)[1] == 2);
  assert((tache2 -> combinaison)[2] == 4);
  
  
  TacheCombinaisonEstNombreArmstrong_Detruire(tache1);
  TacheCombinaisonEstNombreArmstrong_Detruire(tache2);
  
  puts("Fin testCombinaisonEstNombreArmstrong_Clone");
  puts("");
}

void testCombinaisonEstNombreArmstrong_Executer371()
{
	puts("Debut testCombinaisonEstNombreArmstrong_Executer371");
	  
  CachePuissance10 *cachePuissance10;
  cachePuissance10 = InitCachePuissance10(19);
	
  CachePuissanceDigit *cachePuissanceDigit;
  cachePuissanceDigit = InitCachePuissanceDigit(1, 19);

  char combinaison[3] = {1, 7, 3};
  char combinaison2[19] = {3,2,8,9,5,8,2,9,8,4,4,4,3,1,8,7,0,3,2};
  char combinaison3[2] = {3,2};
  
  TacheCombinaisonEstNombreArmstrong *tache1, *tache2, *tache3;
  
  tache1 = TacheCombinaisonEstNombreArmstrong_Init(3, 300, 1000, cachePuissanceDigit, cachePuissance10);
  tache2 = TacheCombinaisonEstNombreArmstrong_Init(19, 1, 4000000000000000000LL, cachePuissanceDigit, cachePuissance10);
  tache3 = TacheCombinaisonEstNombreArmstrong_Init(2, 31, 34, cachePuissanceDigit, cachePuissance10);
  
  long long test_time;
  
  // Test1
  TacheCombinaisonEstNombreArmstrong_SetCombinaison(tache1, combinaison);
  test_time = time_start();
  TacheCombinaisonEstNombreArmstrong_Executer(tache1);
  printf("T: 371 : %lld\n", time_end(test_time));
  assert(tache1 -> resultat == 371);
  
  // Test2
  TacheCombinaisonEstNombreArmstrong_SetCombinaison(tache2, combinaison2);
  
  test_time = time_start();
  TacheCombinaisonEstNombreArmstrong_Executer(tache2);
  //printf("D: tache2 -> result %lld\n", tache2 -> resultat);
  printf("T: 3289582984443187032 : %lld\n", time_end(test_time));
  assert(tache2 -> resultat == 3289582984443187032LLU);
  
  // Test3
  TacheCombinaisonEstNombreArmstrong_SetCombinaison(tache3, combinaison3);
  
  test_time = time_start();
  TacheCombinaisonEstNombreArmstrong_Executer(tache3);
  printf("T: 23 : %lld\n", time_end(test_time));
  assert(tache3 -> resultat == -1);
     
 	TacheCombinaisonEstNombreArmstrong_Detruire(tache1);  
 	TacheCombinaisonEstNombreArmstrong_Detruire(tache2);  
 	TacheCombinaisonEstNombreArmstrong_Detruire(tache3);  
}
