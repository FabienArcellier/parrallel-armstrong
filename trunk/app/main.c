#include "main.h"

/*! \brief Point d'entrée du programme
 * 
 * Codes d'erreur :
 * - 1 : Le nombre d'arguments est incorrect
 * - 2 : le format des nombres en entrée est incorrect
 * - 4 : La borne inferieure est superieure a la borne superieure
*/
int main(int argc, char *argv[])
{
	// omp_set_num_threads(4);
	long long time_zero = time_start();
	int i = 0;
	
	if (argc != 3)
	{
		afficher_aide_longueur_argument_incorrect();
		return 1;
	}
	
	char borne_inferieure[20], borne_superieure[20];
	for(i = 0; i < 20; i++)
	{
		borne_inferieure[i] = 0;
		borne_superieure[i] = 0;
	}
	
	int code1 = ConvertirTexteVersTableauDigit(borne_inferieure, argv[1]);
	int code2 = ConvertirTexteVersTableauDigit(borne_superieure, argv[2]);
	
	if (code1 == 1 || code2 == 1)
	{
		afficher_aide_format_nombre_incorrecte();
		return 2;
	}
	
	int borne_inferieure_longueur = strlen(argv[1]);
	int borne_superieure_longueur = strlen(argv[2]);
	
	// printf("D: borne_superieure_longueur %d\n", borne_superieure_longueur);
	
	// Initialiser le cache des puissances de 10
	CachePuissance10 *cachePuissance10;
	cachePuissance10 = InitCachePuissance10(borne_superieure_longueur);
	
	// Initialiser de le cache des puissances_digit
	CachePuissanceDigit *cachePuissanceDigit;
	cachePuissanceDigit = InitCachePuissanceDigit(borne_inferieure_longueur, borne_superieure_longueur);
	
	// Si le premier argument est superieur au deuxieme argument, afficher_aide_nombre_incoherent
	if (borne_inferieure_longueur > borne_superieure_longueur || Compare2TableauxDigit(borne_inferieure, borne_superieure, borne_superieure_longueur) == 1)
	{
		afficher_aide_nombre_incoherent(
		ConvertirTableauDigitVersNombre(borne_inferieure, borne_inferieure_longueur, cachePuissance10), 
		ConvertirTableauDigitVersNombre(borne_superieure, borne_superieure_longueur, cachePuissance10));
		return 4;
	}
	
	//printf("D: Borne inferieure : %lld\n", ConvertirTableauDigitVersNombre(borne_inferieure, borne_inferieure_longueur, &cachePuissance10));
	//printf("D: Borne superieure : %lld\n", ConvertirTableauDigitVersNombre(borne_superieure, borne_superieure_longueur, &cachePuissance10));
	
	Ordonnanceur *ordonnanceur = Ordonnanceur_Init(
		borne_inferieure,
		borne_superieure,
		borne_inferieure_longueur,
		borne_superieure_longueur,
		cachePuissance10,
		cachePuissanceDigit);
	
	Ordonnanceur_Start(ordonnanceur);
	
	Ordonnanceur_Detruire(ordonnanceur);
	DetruireCachePuissanceDigit(cachePuissanceDigit);
	DetruireCachePuissance10(cachePuissance10);
	
	printf("T: Temps total : %lld\n", time_end(time_zero));
	return 0;
}

/*! \brief Affiche l'aide de la ligne de commande dans le terminal
 */
void afficher_aide()
{
	puts("");
	puts("Usage : ./Smallbrain borne_inferieure borne_superieure");
	puts("");
	puts("Smallbrain est un programme pour calculer les smallbrains,");
	puts("aussi appellé nombres d'armstrong ou nombres narcissiques.");
	puts("Un smallbrain est nombre de la valeur est égale à la somme des chiffres");
	puts("de celui ci chacun eleve a la puissance correspondant au nombre de chiffres");
	puts("");
	puts("e.g : 371 est un smallbrain car 3^3 + 7^3 + 1^3 = 371");
	puts("");
	puts("Arguments:");
	puts("	borne_inferieure : Nombre entier ou l'on commence la recherche ");
	puts("		compris entre [1;9223372036854775807]");
	puts("	borne_superieure : Nombre entier ou l'on termine la recherche");
	puts("		compris entre [1;9223372036854775807]");
	puts("");
	puts("Remarques");
	puts("	- borne_inferieure doit etre inferieur ou egal a borne_superieure");
	puts("	- les nombres s'écrivent avec leur forme pleine 567, 456.");
	puts("	- N'utilisez pas de notation scientifique 1.5E23");
	puts("");
	puts("");
}

/*! \brief Affiche une information supplémentaire dans le cas ou le format d'un des nombres est invalide
 */
void afficher_aide_format_nombre_incorrecte()
{
	puts("");
	puts("ERREUR :");
	puts("- le format de nombre que vous avez utilise n'est pas correcte");
	afficher_aide();
}

/*! \brief Affiche une information supplémentaire dans le cas ou le format d'un des nombres est invalide
 */
void afficher_aide_nombre_incoherent(long long borne_inferieure, long long borne_superieure)
{
	puts("");
	puts("ERREUR :");
	printf("	la borne inferieure (%lld) est superieure a la borne superieure (%lld)\n\n", borne_inferieure, borne_superieure);
	afficher_aide();
}

/*! \brief Informe l'utilisateur que sa ligne d'argument est trop longue
 */
void afficher_aide_longueur_argument_incorrect()
{
	puts("");
	puts("ERREUR :");
	puts("	Vous devez avoir 2 arguments");
	puts("");
	afficher_aide();
}
