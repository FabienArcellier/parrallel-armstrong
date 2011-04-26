/*! \file timer.h
	\author Maxime RIVIERE
*/

#ifndef GUARD_TIMER_H
#define GUARD_TIMER_H

#include <stdlib.h>
#include <math.h>
#include <assert.h>
#include <sys/time.h>
#include <time.h>

/*! \brief Fonctions de calculs du temps d'exécution du programme

  Vous devez éviter de manipuler directement une instance de ce type la.
  Utilisez les fonctions ci-dessous.
*/


/*! \brief Renvoi le temps initial d'exécution du programme
*/
long long time_start(void);

/*! \brief Retourne le temps total d'exécution du programme
*/
long long time_end(long long time_depart);

#endif
