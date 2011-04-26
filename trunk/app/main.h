#include <stdio.h>
#include <string.h>
#include "timer.h"
#include "combinaison.h"
#include "puissanceDigit.h"
#include "puissance10.h"
#include "ordonnanceur.h"


/*! \brief Affiche l'aide de la ligne de commande dans le terminal
 */
void afficher_aide();

/*! \brief Affiche une information supplémentaire dans le cas ou le format d'un des nombres est invalide
 */
void afficher_aide_nombre_incoherent(long long borne_inferieure, long long borne_superieure);

/*! \brief Affiche une information supplémentaire dans le cas ou le format d'un des nombres est invalide
 */
void afficher_aide_format_nombre_incorrecte();

/*! \brief Informe l'utilisateur que sa ligne d'argument est trop longue
 */
void afficher_aide_longueur_argument_incorrect();
