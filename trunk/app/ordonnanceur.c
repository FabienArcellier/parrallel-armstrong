#include "ordonnanceur.h"

/*! \brief Initialise une instance de l'ordonnanceur
*/
Ordonnanceur *Ordonnanceur_Init(char * combinaison_borne_inferieure, 
																				char * combinaison_borne_superieure,
																				int nombre_chiffre_borne_inferieure,
																				int nombre_chiffre_borne_superieure,
																				CachePuissance10 *cachePuissance10,
																				CachePuissanceDigit *cachePuissanceDigit
																			)
{
	Ordonnanceur *ordonnanceur = (Ordonnanceur *) malloc(sizeof(Ordonnanceur));
	
	ordonnanceur -> nombre_processeurs = ObtenirNombreProcesseurs();
	ordonnanceur -> borne_inferieure = ConvertirTableauDigitVersNombre(combinaison_borne_inferieure, nombre_chiffre_borne_inferieure, cachePuissance10);
	ordonnanceur -> borne_superieure = ConvertirTableauDigitVersNombre(combinaison_borne_superieure, nombre_chiffre_borne_superieure, cachePuissance10);
	ordonnanceur -> nombre_chiffre_borne_inferieure = nombre_chiffre_borne_inferieure;
	ordonnanceur -> nombre_chiffre_borne_superieure = nombre_chiffre_borne_superieure;
	ordonnanceur -> cachePuissanceDigit = cachePuissanceDigit;
	ordonnanceur -> cachePuissance10 = cachePuissance10;
	return ordonnanceur;
}

/*! \brief Demande a l'ordonnanceur de commencer le dispatch des taches
*/
void Ordonnanceur_Start(Ordonnanceur *ordonnanceur)
{
	assert(ordonnanceur -> borne_inferieure <= ordonnanceur -> borne_superieure);
	assert(ordonnanceur -> nombre_chiffre_borne_inferieure <= ordonnanceur -> nombre_chiffre_borne_superieure);
	
	long long i = 0, nb_combinaison_max = 0;
	nb_combinaison_max = nombreCombinaisonsDunNombreDigit(ordonnanceur -> nombre_chiffre_borne_superieure);
	
	// Réservation de l'espace mémoire pour les permutations et construction de la combinaison initiale
	char * permutations = (char *) malloc(sizeof(char) * ordonnanceur -> nombre_chiffre_borne_superieure * nb_combinaison_max);
	char * combinaison = (char *) malloc(sizeof(char) * ordonnanceur -> nombre_chiffre_borne_superieure);
	for (i = 0; i <= ordonnanceur -> nombre_chiffre_borne_superieure; i++)
	{
		combinaison[i] = 0;
	}

	//printf("D: nb_combinaison_max : %lld\n", nb_combinaison_max);
	for (i = 0; i < nb_combinaison_max - 2; i++)
	{
		IncrementerTableauxDigitCombinaisonUnique(combinaison, ordonnanceur -> nombre_chiffre_borne_superieure);		
		memcpy(&(permutations[i * ordonnanceur -> nombre_chiffre_borne_superieure]), combinaison, sizeof(char) * ordonnanceur -> nombre_chiffre_borne_superieure);
	}
	
	#pragma omp parallel for num_threads((ordonnanceur -> nombre_processeurs)*2) schedule(static) default(none) shared(nb_combinaison_max, permutations) firstprivate(ordonnanceur)
	for (i = 0; i < nb_combinaison_max; i++)
	{
		int j = 0, nombre_chiffre_minimum = 0;
		long long valeurArmstrong = 0;
		
// 		printf("D: combinaison_for : %lld \n", ConvertirTableauDigitVersNombre(combinaison_for, ordonnanceur -> nombre_chiffre_borne_superieure, ordonnanceur -> cachePuissance10));
// 		printf("D: borne_inferieure : %d\n", borne_inferieure);
// 		printf("D: borne_superieure : %d\n", borne_superieure);
// 		puts("");
		
		nombre_chiffre_minimum = GetOrdreMinimumCombinaison(&(permutations[i * ordonnanceur -> nombre_chiffre_borne_superieure]), ordonnanceur -> nombre_chiffre_borne_superieure);
		// printf("D: ordre_finale : %d\n", ordre_finale);
		for (j = nombre_chiffre_minimum; j <= ordonnanceur -> nombre_chiffre_borne_superieure; j++)
		{
			valeurArmstrong = CalculNombreArmstrong(&(permutations[i * ordonnanceur -> nombre_chiffre_borne_superieure]), j, ordonnanceur -> cachePuissanceDigit);
 			// printf("D: ordre : %d\n", j);
 			// printf("D: valeurArmstrong : %lld\n", valeurArmstrong);
			// printf("D : condition overflow : %d\n", Puissance10_EstOverflow(ordonnanceur -> cachePuissance10, j) == 1);
			
			if (j != 0 &&
				(Puissance10_EstOverflow(ordonnanceur -> cachePuissance10, j) == 1 || valeurArmstrong < GetPuissance10(ordonnanceur -> cachePuissance10, j)) &&
				valeurArmstrong >= GetPuissance10(ordonnanceur -> cachePuissance10, j - 1) &&
				valeurArmstrong <= ordonnanceur -> borne_superieure &&
				valeurArmstrong >= ordonnanceur -> borne_inferieure &&
				EstUnNombreArmstrong(&(permutations[i * ordonnanceur -> nombre_chiffre_borne_superieure]), valeurArmstrong, j, ordonnanceur -> cachePuissance10))
			{
				printf("NA: %lld\n", valeurArmstrong);
			}
		}
	}
}

/*! \brief Detruit une instance de l'ordonnanceur
*/
void inline Ordonnanceur_Detruire(Ordonnanceur *ordonnanceur)
{
	free(ordonnanceur);
}
