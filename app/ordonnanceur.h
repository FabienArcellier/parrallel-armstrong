#include <assert.h>
#include <omp.h>
#include "hardware.h"
#include "puissanceDigit.h"
#include "puissance10.h"
#include "combinaison.h"
#include "CalculArmstrong.h"

typedef struct ordonnanceur
{
	int nombre_processeurs;
	long long borne_inferieure;
	long long borne_superieure;
	int nombre_chiffre_borne_inferieure;
	int nombre_chiffre_borne_superieure;
	CachePuissanceDigit *cachePuissanceDigit;
  CachePuissance10 *cachePuissance10;
} Ordonnanceur;

/*! \brief Initialise une instance de l'ordonnanceur
 */
Ordonnanceur *Ordonnanceur_Init(char * combinaison_borne_inferieure, 
																				char * combinaison_borne_superieure,
																				int nombre_chiffre_borne_inferieure,
																				int nombre_chiffre_borne_superieure,
																				CachePuissance10 *cachePuissance10,
																				CachePuissanceDigit *cachePuissanceDigit
 																			);

/*! \brief Demande a l'ordonnanceur de commencer le dispatch des taches
 */
void Ordonnanceur_Start(Ordonnanceur *ordonnanceur);

/*! \brief Detruit une instance de l'ordonnanceur
 */
void inline Ordonnanceur_Detruire(Ordonnanceur *ordonnanceur);
