#include <assert.h>
#include <stdio.h>
#include "../app/puissanceDigit.h"
#include "../app/timer.h"

/* Liste des prototypes*/
void testPuissanceDigitExposant5();
void testPuissanceDigitClone();

int main(void)
{
	testPuissanceDigitExposant5();
	testPuissanceDigitClone();
	return 0;
}

void testPuissanceDigitExposant5()
{	
	puts("L: Debut du test testPuissanceDigitExposant5");
	long long test_time;
  test_time= time_start();
  
	CachePuissanceDigit *cachePuissanceDigitExposant5;
	cachePuissanceDigitExposant5 = InitCachePuissanceDigit(0, 20);
	
	// Tests
	// printf("D: GetPuissanceDigit(&cachePuissanceDigitExposant5, 4, 3) = %ld\n",
	//	GetPuissanceDigit(&cachePuissanceDigitExposant5, 4, 3));
	assert(GetPuissanceDigit(cachePuissanceDigitExposant5, 4, 3) == 64);
	assert(GetPuissanceDigit(cachePuissanceDigitExposant5, 0, 3) == 0);
	assert(GetPuissanceDigit(cachePuissanceDigitExposant5, 0, 5) == 0);
	printf("D: 9^19 : %lld\n",GetPuissanceDigit(cachePuissanceDigitExposant5, 9, 19));
	assert(GetPuissanceDigit(cachePuissanceDigitExposant5, 9, 19) == 1350851717672992089LLU);
	
	DetruireCachePuissanceDigit(cachePuissanceDigitExposant5);
	
	printf("T: %lld\n", time_end(test_time));
	puts("L: Fin du test testPuissanceDigitExposant5");
	puts("");
}

void testPuissanceDigitClone()
{
  puts("L: Debut du test testPuissanceDigitClone");
  
	
  CachePuissanceDigit *cachePuissanceDigitExposant5, *cloneCache;
  cachePuissanceDigitExposant5 = InitCachePuissanceDigit(0, 20);
  
  long long test_time;
  test_time= time_start();
  cloneCache = CloneCachePuissanceDigit(cachePuissanceDigitExposant5);  
  
  // Tests
  assert(cloneCache -> cache != cachePuissanceDigitExposant5 -> cache);
  assert(GetPuissanceDigit(cachePuissanceDigitExposant5, 4, 3) == 64);
  assert(GetPuissanceDigit(cachePuissanceDigitExposant5, 0, 3) == 0);
  assert(GetPuissanceDigit(cachePuissanceDigitExposant5, 0, 5) == 0);
  
  DetruireCachePuissanceDigit(cloneCache);
  DetruireCachePuissanceDigit(cachePuissanceDigitExposant5);
  
  printf("T: %lld\n", time_end(test_time));
  puts("L: Fin du test testPuissanceDigitClone");
  puts("");
  
}
