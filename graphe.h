#ifndef GRAPHE_H_
#define GRAPHE_H_
#include "liste.h"
#define BLANC 0x01
#define GRIS 0x02
#define NOIR 0x03

typedef struct
{
	int nSommets;	  // nombre de sommet
	int oriente;	   //oriente : 1 ; sinon 0
	int value;		   //évalué : 1 ; sinon 0
	int complet;	   //complet : 1 ; sinon 0
	liste_t **adj;	 //Pointeur de tableau de pointeur de liste_t :D
	int **matrice_adj; //Matrice adjacence, toujours carrée
} graphe_t;

//Valide
void creerListesAdjacences(graphe_t *graph);
//Valide
void afficherListesAdjacences(graphe_t *graph);
void creerMatriceAdjacences(graphe_t *graph);
void afficherMatriceAdjacences(graphe_t *graph);
graphe_t *creerGraphe(int choice); // choice = 1 : liste ; matrice
void detruireGraphe(graphe_t *graph);
void parcoursLargeur(graphe_t *graph);

#endif /* GRAPHE_H_ */
