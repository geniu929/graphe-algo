/*Iacobciuc Eugen & Ismail MOUMNI*/
#include "graphe.h"
#include <stdio.h>	/* pour printf() */
#include <stdlib.h>	/* pour rand() */

/* Initialisation d'un graphe nor */ 

graphe *initialiser_nor(){

graphe *g_nor=malloc(sizeof(graphe));
int a,b,n;
	n=8;
	for (a=0;a<n;a++){
		for (b=0;b<n;b++){
		g_nor-> adj[a][b]=0;	
		}
	}
	g_nor->m=19;
	g_nor->n=8;
	g_nor->is_or=0;
	g_nor->p=1;
	g_nor->boucle=1;
		g_nor-> adj[0][0]=1;

	g_nor-> adj[0][1]=1;
	g_nor-> adj[1][0]=1;

	g_nor-> adj[7][0]=1;
	g_nor-> adj[0][7]=1;

	g_nor-> adj[0][2]=1;
	g_nor-> adj[2][0]=1;

	g_nor-> adj[1][4]=1;
	g_nor-> adj[4][1]=1;

	g_nor-> adj[1][7]=1;
	g_nor-> adj[7][1]=1;

	g_nor-> adj[2][6]=1;
	g_nor-> adj[6][2]=1;

	g_nor-> adj[2][0]=1;
	g_nor-> adj[0][2]=1;

	g_nor-> adj[2][5]=1;
	g_nor-> adj[5][2]=1;

	g_nor-> adj[4][1]=1;
	g_nor-> adj[1][4]=1;

	g_nor-> adj[4][5]=1;
	g_nor-> adj[5][4]=1;	

	g_nor-> adj[5][2]=1;
	g_nor-> adj[2][5]=1;

	g_nor-> adj[5][7]=1;
	g_nor-> adj[7][5]=1;
	
	g_nor-> adj[7][0]=1;
	g_nor-> adj[7][1]=1;
return g_nor;
}
/* initailisation d'un graphe orienté */

graphe *initialiser_or(){

	graphe *g_or=malloc(sizeof(graphe));
	int a,b,n;
	n=8;
	for (a=0;a<n;a++){
		for (b=0;b<n;b++){
		g_or-> adj[a][b]=0;	
		}
	}
	g_or->m=12;
	g_or->n=8;
	g_or->is_or=1;
	g_or->p=1;
	g_or->boucle=1;
	g_or-> adj[0][0]=1;
	g_or-> adj[0][1]=1;
	g_or-> adj[0][7]=1;
	g_or-> adj[0][2]=1;
	
	g_or-> adj[1][4]=1;
	g_or-> adj[1][7]=1;
	g_or-> adj[2][6]=2;
	g_or-> adj[4][5]=1;
	
	g_or-> adj[5][2]=1;
	g_or-> adj[5][7]=1;
	g_or-> adj[7][5]=1;
	g_or-> adj[7][6]=1;

return g_or;
}

/* initialisation du graphe */
graphe_t * init_graphe(){
	graphe_t * g = malloc(sizeof (graphe_t)); 
	g->n=0; 
	g->is_or=0; 
	g->succ= malloc(sizeof (int)); 	
	g->nb_succ=0; 
	g->pos_debut=malloc(sizeof (int));
	g->pos_fin=malloc(sizeof (int));  
	return g;
	free(g->succ);
	free(g->pos_debut);
	free(g->pos_fin);
	free(g);
	
		}


/* transforme un graphe décrit à partir de la matrice d'adjacence à un graphe de liste de succ */
graphe_t * graphe_1_to_succ(graphe* g){
	graphe_t * t= malloc(sizeof(graphe_t));
	 
	t->n= graphe_succ_get_n(g);
	t->is_or= graphe_succ_est_oriente(g);
	t->nb_succ=graphe_succ_nb_succ(g);
	t->succ=liste_succ(g);
	t->pos_debut= pos_debut(g); 
	t->pos_fin= pos_fin(g);	
	return t;
	free(t->succ);
	free(t->pos_debut);
	free(t->pos_fin);
	free(t);
	
}
/* renvoie la liste pos_debut */
int * pos_debut(graphe * g){
	int a,b,c,d,x;
	int * list_succ= malloc (sizeof (int));
	int * liste_debut= malloc (sizeof (int));
	list_succ=liste_succ(g);
	a=0;
	d=0;
	while(a<g->n){
		for(b=0;b<g->n;b++){
		 	if((graphe_succ_est_successeur(g,a,b))==1){
				for(c=0;c<graphe_succ_nb_succ(g);c++){
					if (list_succ[c]==b){
						liste_debut[d]=c;
						for(x=0;x<=c;x++)
							list_succ[x]=-1;										
						d++;
						a++;
					break;
					}		
				}		
				break;					
			}
			else if(((graphe_succ_est_successeur(g,a,b))==0)&&(b==g->n-1)){
				liste_debut[d]=graphe_succ_nb_succ(g);
				d++;
				a++;						
			}
		}	
	}					
	return liste_debut;	
	free(list_succ);
	free(liste_debut);	
}

/* renvoie la liste pos fin d'après le sommaire */
int * pos_fin(graphe * g){
	int a,b,c,d,x;
	int * list_succ= malloc (sizeof (int));
	int * liste_fin= malloc (sizeof (int));
	list_succ=liste_succ(g);
	a=0;
	d=0;
	
	while(a<g->n){
		for(b=g->n-1;b>=0;b--){
		 	if((graphe_succ_est_successeur(g,a,b))==1){
				for(c=0;c<graphe_succ_nb_succ(g);c++){
					if (list_succ[c]==b){
						liste_fin[d]=c;
						for(x=c;x>=0;x--)
							list_succ[x]=-1;
						d++;
						a++;
					break;
					}		
				}		
				break;					
			}
			else if(((graphe_succ_est_successeur(g,a,b))==0)&&(b==0)){
				liste_fin[d]=-1;
				d++;
				a++;						
			}
		}
	}						
	return liste_fin;	
	free(list_succ);
	free(liste_fin);

}
	



/* renvoie le nombre de sommet du graphe */

int graphe_succ_get_n (graphe* g){
	return g->n;
}
/* renvoie si le graphe est orienté ou non */
int graphe_succ_est_oriente (graphe* g){
	return g->is_or;
}
/*renvoie la nombre des succ dans le graphe g*/
int graphe_succ_nb_succ (graphe* g){
	int z=0;
	int a,b;
		for (a=0; a < g->n; a++){ 
			for (b=0; b < g->n; b++){			
				if (g->adj[a][b]!=0){
					z++;			
					}
						}
				}
		return z;
}

/*Fonction qui renvoie la liste des succ du graphe, elle parcourt la liste d'adjacence du graphe[a][b] et récupère b si adj[a][b] = 1.
Condition d'arrêt a = nombre de sommets*/
int * liste_succ (graphe* g){
	
	int *tab=NULL;
	int a,b;
	int e=0;
	tab=malloc(sizeof(int));		
		for (a=0;a<g->n;a++){ 
			for (b=0;b < g->n;b++){			
				if(g->adj[a][b]!=0){
		
					tab[e] = b;
					e++;
				
			    	 }
			    	
		         }
		}
	
	return tab;
free(tab);
	
}


/* teste si b est succ de a */
int graphe_succ_est_successeur (graphe* g,int a,int b){
	if (g-> adj[a][b] != 0)	
		return 1;
	else 
		return 0;
}
/* degre sortant de sommet a */
int graphe_succ_degree_sortant (graphe* g, int a){
	int x;
	int e=0;
		for (x=1; x <= g->n; x++){ 		
			if (g->adj[a][x]!=0){
			e++;}
			}

return e;
}

/* degre entrant de sommet a */
int graphe_succ_degree_entrant (graphe* g, int a){
	int x;
	int e=0;
		for (x=1; x <= g->n; x++){ 		
			if (g->adj[x][a]!=0){
			e++;}
			}
		return e;
}
/* affichage du graphe */
void afficher_graphe(graphe_t * t){
	int a,b,c=0;
	//int matr[t->n][t->n];
	printf("nombre de sommets : %d \n",t->n);
	printf("\n");
	printf("\n");
	printf("nombre de succsesseurs: %d \n",t->nb_succ);
	printf("\n");
	printf("\n");
	printf("graphe orienté 1 ou non O: %d \n",t->is_or);
	printf("\n");
	printf("tableau des succsesseurs :");
	printf("\n");
		for (a=0;a<t->nb_succ;a++){
			printf("%d  ",t->succ[a]); 
			}
	
	printf("\n");
	printf("position de debut :");	
	printf("\n");
		for (a=0;a<t->n;a++){
			printf("%d  ",t->pos_debut[a]); 
		}

	printf("\n");
	printf("positiion de fin :");
	printf("\n");	
		for (a=0;a< t->n;a++){
			printf("%d  ",t->pos_fin[a]); 
		}
	printf("\n");
	/*
	
	for(a=0;a<t->n;a++){
		for(b=0;b<t->n;b++){
		matr[a][b]=0;
		}
	}
	
	
	for(a=0;a<t->n;a++){
		for(b=0;b<t->n;b++){
		if(a=t->pos_deb[c])
		
		}
	}
	*/
	
	
}

















