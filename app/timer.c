/*! \file CalculArmstrong.c
	\author Maxime RIVIERE
*/

#include "timer.h"



/*! \brief Renvoi le temps initial d'exécution du programme
*/
long long time_start(void)
{
  struct timeval tv;
  struct timezone tz;
  long long time_depart;
  gettimeofday(&tv, &tz);
  time_depart = tv.tv_sec * 1000000L + tv.tv_usec;
  return time_depart;

}

/*! \brief Retourne le temps d'exécution du programme
  Récupére en entrée le temps lors du démarrage du programme, récupére le temps à l'éxecution 
  de la fonction et fais la différence.
*/
long long time_end(long long time_depart)
{
  long long diff_time, time_fin;
  struct timeval tv;
  struct timezone tz;
  gettimeofday(&tv, &tz);
  time_fin = tv.tv_sec * 1000000L +  tv.tv_usec;
  diff_time = time_fin - time_depart;
  return diff_time;
}

