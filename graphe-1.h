/*Iacobciuc Eugen & Ismail MOUMNI*/
/* 
	graphe-1.h : représentation des graphes par leur matrice d'adjacence 
*/

#define N 100	/* nombre maximal de sommets dans un graphe */

/* ______________________________________ Structure de données
*/

/* Graphe par matrice d'adjacence 
	- graphe orienté : la somme des coefficients de A(G) est égale au nombre des arcs du graphe
	- graphe non orienté : la somme des coefficients non diagonaux de A(G) + 2 fois la somme des coefficients diagonaux de A(G) = 2 |E|
*/
struct s_graphe {
	int n;				/* nombre de sommets du graphes (doit être compris entre 1 et N) => V = {0 ,..., n -1} */
	int m;				/* nombre d'arêtes du graphes (entier naturel) */
	int adj[N][N];		/* matrice d'adjacence du graphe (doit être cohérente avec m et is_or) : seules les lignes et colonnes d'indice 0 à n -1 sont à lire */
	int is_or;			/* 1 si le graphe est orienté et 0 sinon */
	int p;				/* nombre maximal de liens pouvant exister entre 2 sommets */
	int boucle;			/* 1 si les boucles sont autorisées et 0 sinon */
};

typedef struct s_graphe graphe;

/* ______________________________________ Fonctions de manipulation
*/

/* initialisation d'un graphe par tirage aléatoire de ses arêtes ou arcs
	Pré-conditions : 
	- g adresse d'une variable graphe
	- un appel à srand() a préalablement été fait
	Post-conditions :
	- les champs g->n, g->is_or, g->p, g-> boucle sont initialisés aux valeurs passées en paramètre
	- le champ g->adj est mis à jour par tirage aléatoire
	- le champ g->m est mis à jour en conséquence
*/
void graphe_generer(graphe* g, int n, int is_or, int p, int boucle);

/* adjacence
	Pré-conditions : 
	- g adresse d'une variable graphe
	- 0 <= u, v < g->n
	Cette fonction renvoie 1 si les sommets u et v sont liés par une arête ou un arc au moins, 0 sinon
*/
int graphe_adjacents(graphe* g, int u, int v);

/* successeur
	Pré-conditions : 
	- g adresse d'une variable graphe
	- 0 <= u, v < g->n
	Cette fonction renvoie 1 si le graphe est orienté et contient un arc (u, v) au moins, ou le graphe est non orienté et contient une arête {u, v} au moins ; 
		elle renvoie 0 sinon
*/
int graphe_successeur(graphe* g, int u, int v);

/* predecesseur
	Pré-conditions : 
	- g adresse d'une variable graphe
	- 0 <= u, v <= g->n
	Cette fonction renvoie 1 si le graphe est orienté et contient un arc (v, u) au moins, ou le graphe est non orienté et contient une arête {u, v} au moins ; 
		elle renvoie 0 sinon
*/
int graphe_predecesseur(graphe* g, int u, int v);

/* degre
	Pré-conditions : 
	- g adresse d'une variable graphe
	- 0 <= v < g->n
	Cette fonction renvoie le degre du sommet v
*/
int graphe_degre(graphe* g, int v);

/* degre sortant
	Pré-conditions : 
	- g adresse d'une variable graphe
	- 0 <= v < g->n
	Cette fonction renvoie le degre sortant du sommet v si le graphe est orienté, son degre sinon
*/
int graphe_degre_sortant(graphe* g, int v);

/* degre entrant
	Pré-conditions : 
	- g adresse d'une variable graphe
	- 0 <= v < g->n
	Cette fonction renvoie le degre entrant du sommet v si le graphe est orienté, son degre sinon
*/
int graphe_degre_entrant(graphe* g, int v);

/* affichage d'un graphe
	Pré-condition : g adresse d'une variable graphe
*/
void graphe_afficher(graphe* g);

