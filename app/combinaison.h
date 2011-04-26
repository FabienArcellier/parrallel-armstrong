/* \file combinatoire.h
  \author Fabien Arcellier
  \author Maxime Riviere
*/

#ifndef COMBINAISON_H
#define COMBINAISON_H

#include <math.h>
#include <assert.h>
#include "puissance10.h"

/*! \brief Convertir un nombre en tableau de digit de longueur n

Convertit le nombre 371 en [1,7,3] si [longueur = 3]
Le nombre de poids fort est à la fin du tableau.

Le résultat est placé dans TableauDigit. La réservation de la mémoire est a
la charge de l'appellant.
*/
void ConvertirNombreVersTableauDigit(char * TableauDigit, long long nombre, int longueur);

/*! \brief Convertir un tableau de digit de longueur n en nombre
*/
long long ConvertirTableauDigitVersNombre(char * TableauDigit, int borne_superieure, CachePuissance10 *cache);

/*! \brief Convertit un texte (argument en ligne de commande en Combinaison

Retourne un code :
- 0 : succès de l'operation
- 1 : le format des nombres en entrée est incorrect

longueur est un pointeur de sortie qui correspond a l'ordre du tableau convertit
*/
int ConvertirTexteVersTableauDigit(char * TableauDigit, char * texte);

/*! \brief Calculer la valeur minimum d'une combinaison
 */
long long inline ObtenirValeurMinimumCombinaison(char * TableauDigit, int borne_superieure, CachePuissance10 *cache);

/*! \brief Calculer la valeur maximum d'une combinaison
 */
long long ObtenirValeurMaximumCombinaison(char * TableauDigit, int borne_superieure, CachePuissance10 *cache);

/*! \brief Compare 2 tableaux de digit de longueur n

Retourne 1 si TableauDigit1 > à TableauDigit2, 0 si TableauDigit1 = TableauDigit2, sinon -1
*/
int Compare2TableauxDigit(char * TableauDigit1, char * TableauDigit2, char borne_superieure);

/*! \brief Incremente le tableau de 1

Retourne 1 si c'est la fin du tableau
*/
int IncrementerTableauxDigit(char *TableauDigit, char borne_superieure);

/*! \brief Incremente le tableau vers la prochaine combinaison unique

Définition d'une combinaison unique :
tab[0] >= tab[1], tab[1] >= tab[2], ..., tab[n-1] >= tab[n]

Retourne 1 si c'est la fin du tableau
*/
int IncrementerTableauxDigitCombinaisonUnique(char *TableauDigit, char borne_superieure);

/*! \brief Retourne l'ordre minimum d'une permutation passée en argument
	Par exemple : 0,0,1,2,3 a un ordre minimum de 3. le nombre minimum que l'on peut former
		a 3 chiffres.
*/
int GetOrdreMinimumCombinaison(char *combinaison, int longueur);

/*! \brief Calcule du nombre de combinaison à calculer pour un nombre de digit donné (objectif => choix entre itératif et en combinaison unique pour ordre de valeur min et ordre valeur max)
*/
int nombreCombinaisonsDunNombreDigit(int size);

/*! \brief Calcule du nombre maximum de combinaison à calculer pour un range donné
*/
int nombreCombinaisonsDunRange(int ordre_initial,int ordre_final);

#endif
