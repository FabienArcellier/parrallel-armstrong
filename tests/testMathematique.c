#include <stdio.h>
#include "../app/mathematique.h"
#include "../app/timer.h"


/* Liste des prototypes */
void TestFactoriel();

int main(void)
{
  TestFactoriel();
  
  return 0;
}

void TestFactoriel()
{
  puts("L: Debut du test TestFactoriel");

  assert(factoriel(0) == 1);
  assert(factoriel(1) == 1);
  assert(factoriel(2) == 2);
  
  long long test_time;
  test_time= time_start();
  
  assert(factoriel(9) == 362880);
  
  printf("T: %lld\n", time_end(test_time));
  puts("L: Fin du test TestFactoriel");
  puts("");
}

