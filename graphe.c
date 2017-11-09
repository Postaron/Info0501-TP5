#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "graphe.h"
#include "cellule.h"
#include "outilsListe.h"

void creerListesAdjacences(graphe_t * grapĥ) {
	FILE * file = NULL;
	int indice = 0, donnee = 0;
	char buffer[27]; // buffer suffisamment grand
	file = fopen("graphe1.txt", "r");
	if (file == NULL) {
		fprintf(stderr, "Ouverture du fichier impossible\n");
		exit(EXIT_FAILURE);
	}

	while (fscanf(file, "%s", buffer), !feof(file)) {
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
			while (fscanf(file, "%s", buffer), strcmp(buffer, "finDefAretes")
					!= 0) { //Nouvelle condition
				/*
				 * Non testé
				 * Bon avec nouvelle condition ?
				 */
				indice = atoi(buffer);
				fscanf(file, "%s", buffer);
				donnee = atoi(buffer);
				inserer(grapĥ->adj[indice][0], initialiserCellule(donnee));
				if (grapĥ->oriente) {
					inserer(grapĥ->adj[donnee][0], initialiserCellule(indice));
				}
			}
		}
	}
	fclose(file); //Normalement c'est bon cette ligne
}

void afficherListesAdjacences(graphe_t * graph) {
	int i;
	for (i = 0; i < graph->nSommets; ++i) {
		afficherListe(graph->adj[i]);
	}
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
