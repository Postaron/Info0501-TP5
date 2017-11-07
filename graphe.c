#include "graphe.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void creerListesAdjacences(graphe_t * grapĥ) {
	FILE * file = NULL;
	char buffer[27]; // buffer suffisamment grand
	file = fopen("graphe1.txt", "r");
	if (file == NULL) {
		fprintf(stderr, "Ouverture du fichier impossible\n");
		exit(EXIT_FAILURE);
	}

	while (!feof(file)) {
		fscanf(file, "%s", buffer);
		if (strcmp(buffer, "nSommets") == 0) {
			fscanf(file, "%d", grapĥ->nSommets);
			grapĥ->adj = (liste_t **) malloc(
					grapĥ->nSommets * sizeof(liste_t *));
			//Créer tableau de listes adjacences
			for (int i = 0; i < grapĥ->nSommets; ++i) {
				grapĥ->adj[i] = initialiserListe();
			}
		} else if (strcmp(buffer, "oriente") == 0) {
			fscanf(file, "%d", grapĥ->oriente);
		} else if (strcmp(buffer, "value") == 0) {
			fscanf(file, "%d", grapĥ->value);
		} else if (strcmp(buffer, "complet") == 0) {
			fscanf(file, "%d", grapĥ->complet);
		} else if (strcmp(buffer, "debutDefAretes") == 0) {
			while (strcmp(buffer, "finDefAretes") != 0) {
				//TODO finir ça
			}
		}
	}
}

void afficherListesAdjacences(graphe_t * graph) {

}

void creerMatriceAdjacences(graphe_t * grapĥ) {

}

void afficherMatriceAdjacences(graphe_t * graph) {

}

graphe_t * creerGraphe(int choice) { // choice = 1 : liste ; matrice
	graphe_t* graph = NULL;
	graph = malloc(sizeof(graphe_t));
	if (choice) {
		creerListesAdjacences(graph);
	} else {
		creerMatriceAdjacences(graph);
	}
	return graph;
}

void detruireGraphe(graphe_t * graph) {

}
