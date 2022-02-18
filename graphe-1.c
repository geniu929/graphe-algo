/*Iacobciuc Eugen & Ismail MOUMNI*/
/* 
	graphe-1.c : représentation des graphes par leur matrice d'adjacence 
*/

#include "graphe-1.h"

#include <stdio.h>	/* pour printf() */
#include <stdlib.h>	/* pour rand() */

/* ______________________________________ Fonctions de manipulation
	Pré condition pour toutes :	
*/

/* initialisation d'un graphe par tirage aléatoire de ses arêtes ou arcs
*/
void graphe_generer(graphe* g, int n, int is_or, int p, int boucle)
{
	int u, v, mult, mult_uv;

	/* __ mise à jour des champs atomiques (sinon g->m) */
	g->n = n;
	g->is_or = is_or;
	g->p = p;
	g->boucle = boucle;

	/* __ mise à jour des aretes ou arcs */
	g->m = 0;

	/* parcours des couples (u, v) */
	for (u = 0 ; u <= g->n -1 ; u ++)
	{
		for (v = u ; v <= g->n -1 ; v ++)
		{
			/* si le graphe est sans boucle et v = u : on passe à la suite */
			if ((u == v) && (! g->boucle))
				continue;

			/* on tire au hasard la multiplicté de l'arête {u, v} et l'on met à jour g->m */
			mult = rand() % (g->p +1);		/* l'arête {u, v} peut apparaître 0 à g->p fois dans le graphe */
			g->m = g->m +mult;

			/* si v = u : il suffit de mettre à jour la matrice d'adjacence */
			if(u == v)
				g->adj[u][v] = mult;
			/* si v <> u et le graphe est orienté : les arêtes {u, v} doivent être réparties en arcs (u, v) et (v, u) avant de mettre à jour la matrice d'adjacence */
			else if(g->is_or)
			{
				mult_uv = rand() % (mult +1);	/* l'arc (u, v) peut apparaître 0 à mult fois dans le graphe */
				g->adj[u][v] = mult_uv;
				g->adj[v][u] = mult -mult_uv;
			}
			/* si v <> u et le graphe n'est pas orienté : il suffit de mettre à jour la matrice d'adjacence */
			else
			{
				g->adj[u][v] = mult;
				g->adj[v][u] = mult;
			}
		}
	}
}

/* affichage d'un graphe
*/
void graphe_afficher(graphe* g)
{
	int u, v;

	/* données générales */
	printf("%d-graphe %s %s d'ordre %d ayant les %d aretes suivantes:\n", g->p, (g->is_or ? "oriente" : "non oriente"), (g->boucle ? "" : "sans boucle"), g->n, g->m);
	
	/* détail des arêtes ou arcs */
	for (u = 0 ; u <= g->n -1 ; u ++)
		for (v = u ; v <= g->n -1 ; v ++)
		{
			/* on n'affiche que les arêtes existant en au moins 1 exemplaire */
			if(g->adj[u][v] +g->adj[v][u] > 0)
			{
				/* boucle */
				if(u == v)
					printf("\t %d boucles sur %d\n", g->adj[u][u], u);
				/* arc qui n'est pas une boucle */
				else if(g->is_or)
					printf("\t %d aretes {%d, %d} reparties en %d arcs (%d, %d) et %d arcs (%d, %d)\n", g->adj[u][v] +g->adj[v][u], u, v, g->adj[u][v], u, v, g->adj[v][u], v, u);
				/* arête non orientée qui n'est pas une boucle */
				else
					printf("\t %d aretes {%d, %d}\n", g->adj[u][v], u, v);
			}
		}
}

