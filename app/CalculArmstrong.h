/*! \file CalculArmstrong.h
	\author Maxime RIVIERE
*/

#include <stdlib.h>
#include <math.h>
#include <assert.h>
#include "../app/puissanceDigit.h"
#include "../app/combinaison.h"
#include "../app/puissance10.h"

#ifndef CALCUL_ARMSTRONG_H
#define CALCUL_ARMSTRONG_H

/*! \brief Fonctions de calculs et de vérification des nombres d'Armstrong

  Vous devez éviter de manipuler directement une instance de ce type la.
  Utilisez les fonctions ci-dessous.
*/
typedef enum {FALSE, TRUE} bool;

typedef struct tache_nombre_armstrong
{
	char *Combinatoire;
	char *Test_variable;
	CachePuissance10 *cache_puissance_10;
} Tache_Nombre_Armstrong;

/*! \brief Calcule le nombre (potentiellement d'Armstrong) à l'aide d'une combinaison fournie en paramètre et retourne le nombre calculé
*/
long long CalculNombreArmstrong(char *Combinaison,int size,CachePuissanceDigit *cache);

/* \brief Retourne vrai ou faux selon que le nombre est d'Armstrong ou pas
*/
bool EstUnNombreArmstrong(char *Combinaison,long long NbTeste, int size,CachePuissance10 *cache_puissance_10);


/* \brief Initialise le tableau de test pour la vérification d'Armstrong
*/
void init_comparedigit(char *Test_variable,int size);

/* \brief Vérifie si la case en cours de vérification a déjà été utilisée
*/
bool used_comparedigit(char *Test_variable,int j,int size);


/* \brief Défini une case du tableau de la Combinaison comme utilisé lors de la vérification
*/
void add_comparedigit(char *Test_variable,int j);

/* \brief Instancie un nouvel objet Tache_Nombre_Armstrong
*/
Tache_Nombre_Armstrong * InitialiserTacheArmstrong(int size,CachePuissance10 *cache_puissance_10);

/* \brief Libere la mémoire d'un objet Tache_Nombre_Armstrong
*/
void DetruireTacheNombreArmstrong(Tache_Nombre_Armstrong * TacheCombinaison);

#endif
