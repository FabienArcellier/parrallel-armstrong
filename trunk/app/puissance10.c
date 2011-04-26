/*! \file puissance10.c
	\author Fabien Arcellier
*/
#include "puissance10.h"

/* \brief Initialise le cache en calculant les valeurs de 10^0 à 10^n
  
  Remplit un tableau permettant de garder en cache les valeurs pour
  les puissances de 10. On économise ainsi de nombreux cycles processeurs

*/
CachePuissance10 * InitCachePuissance10(unsigned char borne_superieure)
{
  // Pré condition
  assert(borne_superieure <= PUISSANCE10_EXPOSANT_LIMIT);
  CachePuissance10 * cache = (CachePuissance10 *) malloc(sizeof(CachePuissance10));
  
	
  cache -> borne_superieure = borne_superieure;
  cache -> cache = (long long *) malloc(sizeof(long long)*(borne_superieure + 1));

  int i = 0;
  for(i = 0; i <= borne_superieure; i++)
  {
    (cache -> cache)[i] = pow_long(10, i);
  }

  return cache;
}


/*! \brief Clone le cache dans une nouvelle structure de donnée
*/
CachePuissance10 * CloneCachePuissance10(CachePuissance10 *cache)
{
    CachePuissance10 * cache_clone = (CachePuissance10 *) malloc(sizeof(CachePuissance10));
    cache_clone -> borne_superieure = cache -> borne_superieure;
    cache_clone -> cache = (long long *) malloc(sizeof(long long)*(cache -> borne_superieure + 1));
    memcpy(cache_clone -> cache, cache -> cache, sizeof(long long)*(cache -> borne_superieure + 1));
    
    return cache_clone;
}


/* \brief Retourne la puissance de 10 recherchée depuis le cache

	retourne -1 si dépassement de capacité
*/
long long inline GetPuissance10(CachePuissance10 *cache, unsigned char exposant)
{
  //Pre condition
  assert(cache -> borne_superieure >= exposant);
  
	long long result = 0;
	if (exposant > PUISSANCE10_EXPOSANT_LIMIT)
	{
		result = -1;
	}
	else
	{
		result = (cache -> cache)[exposant];
	}

  //Post condition
  assert(result != 0);
  return result;
}

/* \brief Renvoie 1 si la puissance de 10 demandé est au dela de la capacite technique
	du long long
*/
int inline Puissance10_EstOverflow(CachePuissance10 *cache, unsigned char exposant)
{
	//Traitement
	return (exposant > cache -> borne_superieure || exposant >= PUISSANCE10_EXPOSANT_LIMIT);	
}

/*! \brief Destructeur du cache
  Désalloue la mémoire dynamique utilisée pour construire le tableau
  de cache
*/
void DetruireCachePuissance10(CachePuissance10 *cache)
{
  free(cache -> cache);
  free(cache);
}
