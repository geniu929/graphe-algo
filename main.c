/*Iacobciuc Eugen & Ismail MOUMNI*/
#include "graphe.h"
#include <stdio.h>	/* pour printf() */
#include <stdlib.h>	/* pour rand() */


int main()
{
	
	
	
	
	graphe_t *g_or= malloc(sizeof(graphe_t));
	graphe_t *g_nor= malloc(sizeof(graphe_t));
	graphe_afficher(initialiser_or());
	//graphe_afficher(initialiser_nor());
	g_or=graphe_1_to_succ(initialiser_or());
	//g_nor=graphe_1_to_succ(initialiser_nor());
	
	
	afficher_graphe(g_or);
	

	return EXIT_SUCCESS;

}

