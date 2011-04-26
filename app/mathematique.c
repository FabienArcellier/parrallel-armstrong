#include "mathematique.h"

/* \brief Calcul le factoriel d'un nombre <= 12 

Nous avons besoin de cette fonction pour calculer le nombre de permutation.
Etant donné que nous sommes en base 10, il y'a au plus dans n'importe quelle nombre
9! permutation possible.

TODO : Moyen d'optimiser mais peu employé
*/
int inline factoriel(int nombre)
{
  // Pré conditions
  assert(nombre <= 12);
  
  int i = 0;
  int resultat = 1;
  for(i = 1; i <= nombre; resultat = resultat * i, i++);
  
  // Post conditions
  assert(nombre <= 479001600);
  
  return resultat;
}



long long inline pow_long(int nombre, int exposant)
{
	int i=0;
	long long puissance=1;
	if(nombre != 0)
	{
		for(i=1;i<=exposant;i++)
		{			puissance=nombre*puissance;
		}
	}
	else puissance =0;
	return puissance;
}
