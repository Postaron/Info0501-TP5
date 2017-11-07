#ifndef GRAPHE_H_
#define GRAPHE_H_
#include "liste.h"

typedef struct {
	int nSommets; // nombre de sommet
	int oriente; //oriente : 1 ; sinon 0
	int value; //évalué : 1 ; sinon 0
	int complet; //complet : 1 ; sinon 0
	liste_t * adj; //Tableau de liste adjacence
} graphe_t;

void creerListesAdjacences();
void afficherListesAdjaceces(graphe_t * graph);
void creerMatriceAdjacences();
void afficherMatriceAdjacences(graphe_t * graph);
graphe_t * creerGraphe();
void detruireGraphe(graphe_t * graph);

#endif /* GRAPHE_H_ */
