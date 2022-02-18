/*Iacobciuc Eugen & Ismail MOUMNI*/
#include "graphe-1.h"

#define N 100	/* nombre maximal de sommets dans un graphe */

struct graphe_succ{

	int n; /* nombre de sommets du graphe*/
	int is_or; /* orienté 1 non orienté 0*/
	int *succ; /* tablea de succ*/	
	int nb_succ; /* nombre de succ*/
	int *pos_debut; /* tableau d'indice du premier succ*/
	int *pos_fin; /* tableau d'indice du dernier succ*/
		};
typedef struct graphe_succ graphe_t;

graphe_t * graphe_1_to_succ(graphe* g);		/* Création d'un graphe à partir d'une variable de type graphe*/

graphe_t * init_graphe();

int graphe_succ_get_n (graphe* g);	/* graphe  à partir de liste de succedeurs*/
	
int graphe_succ_est_oriente (graphe* g);

int graphe_succ_nb_succ (graphe* g);

int * liste_succ (graphe* g);

int graphe_succ_est_successeur (graphe* g,int a,int b);

int graphe_succ_degree_sortant (graphe* g,int a);

int graphe_succ_degree_entrant (graphe* g,int a);

int * pos_debut(graphe * g);

int * pos_fin(graphe * g);

void afficher_graphe(graphe_t * t);

graphe *initialiser_nor();

graphe *initialiser_or();
