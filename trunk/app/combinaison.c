/*! \file combinaison.c
    \author Fabien Arcellier
*/
#include "combinaison.h"

/*! \brief Convertir un nombre en tableau de digit de longueur n

Convertit le nombre 371 en [1,7,3] si [longueur = 3]
Le nombre de poids fort est à la fin du tableau.

Le résultat est placé dans TableauDigit. La réservation de la mémoire est a
la charge de l'appellant.
*/
void ConvertirNombreVersTableauDigit(char * TableauDigit, long long nombre, int longueur)
{
  // Pré conditions
  
  // Traitement
  int i = 0;
  // printf("D: nombre : %lld\n", nombre);
  for(i = 0; nombre != 0; i++, nombre /= 10)
  {
    TableauDigit[i] = nombre % 10;
  }
  for(;i < longueur; i++)
  {
    TableauDigit[i] = 0;
  }
  
  // Post conditions
  // printf("D: i : %d, longueur : %d", i, longueur);
  assert(i == longueur);
  
  return;
}

/*! \brief Convertir un tableau de digit de longueur n en nombre

TODO : Parallélisable mais peu intéressant dans un premier temps
*/
long long ConvertirTableauDigitVersNombre(char * TableauDigit, int borne_superieure, CachePuissance10 *cache)
{
  // Traitement
  int i = 0;
  long long result = 0;
  for(i = 0; i < borne_superieure; i++)
  {
    result = result + TableauDigit[i] * GetPuissance10(cache, i);
  }
  
  // Post conditions
  assert(result >= 0);
  //assert(result < pow_long(10,borne_superieure));
  
  return result;
}

/*! \brief Calculer la valeur minimum d'une combinaison
 */
long long inline ObtenirValeurMinimumCombinaison(char * TableauDigit, int borne_superieure, CachePuissance10 *cache) 
{
	return ConvertirTableauDigitVersNombre(TableauDigit, borne_superieure, cache);
}

/*! \brief Calculer la valeur maximum d'une combinaison
 */
long long ObtenirValeurMaximumCombinaison(char * TableauDigit, int borne_superieure, CachePuissance10 *cache)
{
	// Traitement
  int i = 0;
  long long result = 0;
	int nombre_zero;
	for(nombre_zero = 0; nombre_zero < borne_superieure && TableauDigit[nombre_zero] == 0; nombre_zero++);
  for(; i < borne_superieure; i++)
  {
    result = result + TableauDigit[borne_superieure - 1 - i] * GetPuissance10(cache, borne_superieure - 1 - i + nombre_zero);
  }
  
  // Post conditions
  assert(result >= 0);
  //assert(result < pow_long(10,borne_superieure));
  
  return result;
}

/*! \brief Convertit un texte (argument en ligne de commande en Combinaison)

Par exemple, 3,2,1,\0 devient 1,2,3

Retourne un code :
- 0 : succès de l'operation
- 1 : le format des nombres en entrée est incorrect

longueur est un pointeur de sortie qui correspond a l'ordre du tableau convertit
*/
int ConvertirTexteVersTableauDigit(char * TableauDigit, char * texte)
{
	int longueur = strlen(texte);
	int i = 0;
	int code = 0;
	// On vient permuter les donnees et on retire le \0 (3,2,1,\0 devient 1,2,3)
	for (i = 0; i < (longueur / 2 + longueur % 2); i++)
	{
		if (texte[i] < '0' || texte[i] > '9')
		{
			code = 1;
			break;
		}
		
		char stockage_tmp = texte[i] - '0';
		TableauDigit[i] = texte[longueur - i - 1] - '0';
		TableauDigit[longueur - i - 1] = stockage_tmp;
	}
	
	return code;
}

/*! \brief Compare 2 tableaux de digit de longueur n

Retourne 1 si TableauDigit1 > à TableauDigit2, 0 si TableauDigit1 = TableauDigit2, sinon -1
*/
int Compare2TableauxDigit(char * TableauDigit1, char * TableauDigit2, char borne_superieure)
{

  // Traitement
  int i = 0;
  int resultat_comparaison = 0;
  for(i = borne_superieure - 1; i >= 0; i--)
  {
    if(TableauDigit1[i] > TableauDigit2[i])
    {
      resultat_comparaison = 1;
      break;
    }
    if(TableauDigit1[i] < TableauDigit2[i])
    {
      resultat_comparaison = -1;
      break;
    }
  }
  
  // Post conditions
  assert(resultat_comparaison >= -1);
  assert(resultat_comparaison <= 1);
  
  return resultat_comparaison;
}

/*! \brief Incremente le tableau de 1

Retourne 1 si c'est la fin du tableau
*/
int IncrementerTableauxDigit(char *TableauDigit, char borne_superieure)
{
  int i = 0;
  int fin_tableau = 0;
  for(i = 0; i < borne_superieure; i++)
  {
    TableauDigit[i]++;
    if (TableauDigit[i] != 10)
    {
      break;
    }
    
    if(i != borne_superieure - 1)
    {
    	TableauDigit[i] = 0;
    }
    else
    {
    	fin_tableau = 1;
    }
  }
  
  return fin_tableau;
}

/*! \brief Incremente le tableau vers la prochaine combinaison unique

Définition d'une combinaison unique :
tab[0] >= tab[1], tab[1] >= tab[2], ..., tab[n-1] >= tab[n]

Retourne 1 si c'est la fin du tableau
*/
int IncrementerTableauxDigitCombinaisonUnique(char *TableauDigit, char borne_superieure)
{
  int i = 0;
  int profondeur = 0;
  int fin_tableau = 0;
  for(i = 0; i < borne_superieure; i++)
  {
    TableauDigit[i]++;
    if (TableauDigit[i] != 10)
    {
      break;
    }
    profondeur++;
  }
  
  for(i = 1; TableauDigit[borne_superieure - 1] < 10 && i <= profondeur; i++)
  {
  	TableauDigit[profondeur - i] = TableauDigit[profondeur];
  }
  
  if (TableauDigit[0] > 9)
 	{
 		fin_tableau = 1;
 	}
  
  return fin_tableau;
}

/*! \brief Retourne l'ordre minimum d'une permutation passée en argument
	Par exemple : 0,0,1,2,3 a un ordre minimum de 3. le nombre minimum que l'on peut former
		a 3 chiffres.
*/
int GetOrdreMinimumCombinaison(char *combinaison, int longueur)
{
	int i = 0;
	int ordre_minimum = 0;
	for(i = 0; i < longueur; i++)
	{
		if (combinaison[longueur - i - 1] != 0)
		{
			ordre_minimum = longueur - i;
			break;
		}
	}
	
	return ordre_minimum;
}

/*! \brief Calcule du nombre de combinaison à calculer pour un nombre de digit donné (objectif => choix entre itératif et en combinaison unique pour ordre de valeur min et ordre valeur max)
*/
int nombreCombinaisonsDunNombreDigit(int size)
{
	int i,ordre=0,tableau =2, resultat =0;
	int Tab_Calcul1[11], Tab_Calcul2[11];
	Tab_Calcul1[0]=0;
	Tab_Calcul2[0]=0;
	if(size==0)
	{
		return 0;
	}
	for(i=1;i<=10;i++)
	{
		Tab_Calcul1[i]=1;
	}
	ordre+=1;
	while(ordre<=size)
	{
		for(i=1;i<=10;i++)
		{
			Tab_Calcul2[i]=Tab_Calcul1[i]+Tab_Calcul2[i-1];
		}
		ordre+=1;
		if(ordre<=size)
		{
			for(i=1;i<=10;i++)
			{
				Tab_Calcul1[i]=Tab_Calcul2[i]+Tab_Calcul1[i-1];
			}
			ordre+=1;
		}
		else tableau=1;
	}
	if (tableau == 1)
	{
		for(i=1;i<=10;i++)
		{
			resultat = resultat +Tab_Calcul1[i];
		}
	}
	else
	{
		for(i=1;i<=10;i++)
		{
			resultat = resultat +Tab_Calcul2[i];
		}
	}
	return resultat;
}

/*! \brief Calcule du nombre maximum de combinaison a calculer pour un range donne
*/

int nombreCombinaisonsDunRange(int ordre_initial,int ordre_final)
{
	int i,ordre=0,resultat =0;
	int Tab_Calcul1[11], Tab_Calcul2[11];
	Tab_Calcul1[0]=0;
	Tab_Calcul2[0]=0;
	if(ordre_final==0)
	{
		return 0;
	}
	
	for(i=1;i<=10;i++)
	{
		Tab_Calcul1[i]=1;
	}
	if(ordre>=ordre_initial)
	{
		for(i=1;i<=10;i++)
			{
				resultat = resultat +Tab_Calcul1[i];
			}
	}
	ordre+=1;
	while(ordre<=ordre_final)
	{
		for(i=1;i<=10;i++)
		{
			Tab_Calcul2[i]=Tab_Calcul1[i]+Tab_Calcul2[i-1];
		}
		if(ordre>=ordre_initial)
		{
			for(i=1;i<=10;i++)
			{
				resultat = resultat +Tab_Calcul1[i];
			}
		}
		ordre+=1;
		if(ordre<=ordre_final)
		{
			for(i=1;i<=10;i++)
			{
				Tab_Calcul1[i]=Tab_Calcul2[i]+Tab_Calcul1[i-1];
			}
			ordre+=1;
			if(ordre>=ordre_initial)
			{
				for(i=1;i<=10;i++)
				{
					resultat = resultat +Tab_Calcul2[i];
				}
			
			}
		}
	}
	return resultat;
}
