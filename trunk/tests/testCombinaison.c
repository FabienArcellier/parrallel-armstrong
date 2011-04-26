#include <assert.h>
#include <stdio.h>
#include "../app/combinaison.h"
#include "../app/timer.h"

/* Liste des prototypes*/
void TestConvertirNombreVersTableauDigit();
void TestConvertirTableauDigitVersNombre();
void TestCompare2TableauxDigit();
void TestIncrementerTableauxDigit();
void TestIncrementerTableauxDigitCombinaisonUnique();
void testNombreCombinaison();
void TestConvertirTexteVersTableauDigit();
void TestGetOrdreMinimumCombinaison();
void TestObtenirValeurMaximumCombinaison();

int main(void)
{
	TestConvertirNombreVersTableauDigit();
	TestConvertirTableauDigitVersNombre();
	TestCompare2TableauxDigit();
	TestIncrementerTableauxDigit();
	TestIncrementerTableauxDigitCombinaisonUnique();
	testNombreCombinaison();
	TestConvertirTexteVersTableauDigit();
	TestGetOrdreMinimumCombinaison();
	TestObtenirValeurMaximumCombinaison();
	
	return 0;
}

void TestConvertirNombreVersTableauDigit()
{
	puts("L: Debut du test TestConvertirNombreVersTableauDigit");
	long long test_time;
	test_time= time_start();
	long nombre1 = 371;
	char tableauDigit1[5];
	
	ConvertirNombreVersTableauDigit(tableauDigit1, nombre1, 5);
	
	assert(tableauDigit1[0] == 1);
	assert(tableauDigit1[1] == 7);
	assert(tableauDigit1[2] == 3);
	assert(tableauDigit1[3] == 0);
	assert(tableauDigit1[4] == 0);
	printf("T: %lld\n", time_end(test_time));
	puts("L: Fin du test TestConvertirNombreVersTableauDigit");
	puts("");
}

void TestConvertirTableauDigitVersNombre()
{
	puts("L: Debut du test TestConvertirTableauDigitVersNombre");
	
	CachePuissance10 * cachePuissance10;
	cachePuissance10 = InitCachePuissance10(5);
	
	long long test_time;
	test_time= time_start();
	
	char tableauDigit1[5] = {1,7,3,0,0};
	long long resultat = 0;
	resultat = ConvertirTableauDigitVersNombre(tableauDigit1, 5, cachePuissance10);
	assert(resultat == 371);
	
	char tableauDigit2[5] = {1,7,3,2,1};
	resultat = 0;
	resultat = ConvertirTableauDigitVersNombre(tableauDigit2, 5, cachePuissance10);
	assert(resultat == 12371);
	
	printf("T: %lld\n", time_end(test_time));
	puts("L: Fin du test TestConvertirTableauDigitVersNombre");
	puts("");
}

void TestCompare2TableauxDigit()
{
	puts("L: Debut du test TestCompare2TableauxDigit");
	long long test_time;
	test_time= time_start();
	
	char tableauDigit1[5] = {1,7,3,0,0};
	char tableauDigit2[5] = {2,7,3,0,0};
	
	assert(Compare2TableauxDigit(tableauDigit1, tableauDigit2, 5) == -1);
	assert(Compare2TableauxDigit(tableauDigit2, tableauDigit1, 5) == 1);
	assert(Compare2TableauxDigit(tableauDigit1, tableauDigit1, 5) == 0);
	
	printf("T: %lld\n", time_end(test_time));
	puts("L: Fin du test TestCompare2TableauxDigit");
	puts("");
}

void TestIncrementerTableauxDigit()
{
	puts("L: Debut du test TestIncrementerTableauxDigit");
	long long test_time;
	test_time= time_start();
	
	char tableauDigit1[5] = {0,0,0,0,0};
	char tableauDigit2[5] = {9,1,0,0,0};
	
	IncrementerTableauxDigit(tableauDigit1, 5);
	assert(tableauDigit1[0] == 1 &&
		tableauDigit1[1] == 0);
	
	IncrementerTableauxDigit(tableauDigit2, 5);
	assert(tableauDigit2[0] == 0 &&
		tableauDigit2[1] == 2 &&
		tableauDigit2[2] == 0);
	
	printf("T: %lld\n", time_end(test_time));
	puts("L: Fin du test TestIncrementerTableauxDigit");
	puts("");
}

void TestIncrementerTableauxDigitCombinaisonUnique()
{
	puts("L: Debut du test TestIncrementerTableauxDigit");
	
	CachePuissance10 * cachePuissance10;
	cachePuissance10 = InitCachePuissance10(5);
	
	long long test_time;
	test_time= time_start();
	
	char tableauDigit1[5] = {9,0,0,0,0};
	char tableauDigit2[5] = {8,9,9,0,0};
	
	IncrementerTableauxDigitCombinaisonUnique(tableauDigit1, 5);
	assert(tableauDigit1[0] == 1 &&
		tableauDigit1[1] == 1 &&
		tableauDigit1[2] == 0);
	
	IncrementerTableauxDigitCombinaisonUnique(tableauDigit2, 5);
	
	// printf("D: tableau : %lld\n", ConvertirTableauDigitVersNombre(tableauDigit2, 5, cachePuissance10));
	
	assert(tableauDigit2[0] == 9 &&
		tableauDigit2[1] == 9 &&
		tableauDigit2[2] == 9 &&
		tableauDigit2[3] == 0);
	
	printf("T: %lld\n", time_end(test_time));
	puts("L: Fin du test TestIncrementerTableauxDigit");
	puts("");
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

void TestConvertirTexteVersTableauDigit()
{
	puts("L: Debut du test TestConvertirTexteVersTableauDigit");
	long long test_time;
	test_time= time_start();
	
	char texte[4] = "371";
	char combinaison[20];
	int i = 0;
	
	for (i = 0; i < 20; i++)
	{
		combinaison[i] = 0;
	}
	
	int code = ConvertirTexteVersTableauDigit(combinaison, texte);
	assert(code == 0);
	assert(combinaison[0] == 1);
	assert(combinaison[1] == 7);
	assert(combinaison[2] == 3);
	assert(combinaison[3] == 0);
	
	printf("T: %lld\n", time_end(test_time));
	puts("L: Fin du test TestConvertirTexteVersTableauDigit");
	puts("");
}

void TestGetOrdreMinimumCombinaison()
{
	puts("L: Debut du test TestGetOrdreMinimumCombinaison");
	long long test_time;
	test_time= time_start();
	
	char combinaison[4] = {1,2,0,0};
	int ordre_minimum = GetOrdreMinimumCombinaison(combinaison, 4);
	assert(ordre_minimum == 2);
	
	printf("T: %lld\n", time_end(test_time));
	puts("L: Fin du test TestGetOrdreMinimumCombinaison");
	puts("");
}

void TestObtenirValeurMaximumCombinaison()
{
	puts("L: Debut du test TestObtenirValeurMaximumCombinaison");
	long long test_time;
	test_time= time_start();
	
	CachePuissance10 * cachePuissance10;
	cachePuissance10 = InitCachePuissance10(5);
	
	char combinaison[4] = {1,2,3,0};
	long long resultat1 = ObtenirValeurMaximumCombinaison(combinaison, 3, cachePuissance10);
	long long resultat2 = ObtenirValeurMaximumCombinaison(combinaison, 4, cachePuissance10);
	
	printf("D : resultat1 : %lld\n", resultat1);
	printf("D : resultat2 : %lld\n", resultat2);
	
	assert(resultat1 == 321);
	assert(resultat2 == 3210);
	
	printf("T: %lld\n", time_end(test_time));
	puts("L: Fin du test TestGetOrdreMinimumCombinaison");
	puts("");
}