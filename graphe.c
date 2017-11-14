#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>
#include "graphe.h"
#include "cellule.h"
#include "outilsListe.h"
#include "file.h"

void creerListesAdjacences(graphe_t *graph)
{
	FILE *file = NULL;
	int indice = 0, donnee = 0;
	char buffer[27]; // buffer suffisamment grand
	file = fopen("graphe1.txt", "r");
	if (file == NULL)
	{
		fprintf(stderr, "Ouverture du fichier impossible\n");
		exit(EXIT_FAILURE);
	}

	while (fscanf(file, "%s", buffer), !feof(file))
	{
		if (strcmp(buffer, "nSommets") == 0)
		{
			fscanf(file, "%d", &graph->nSommets);
			graph->adj = (liste_t **)malloc(
				graph->nSommets * sizeof(liste_t *));
			//Créer tableau de listes adjacences
			for (int i = 0; i < graph->nSommets; ++i)
			{
				graph->adj[i] = initialiserListe();
			}
		}
		else if (strcmp(buffer, "oriente") == 0)
		{
			fscanf(file, "%d", &graph->oriente);
		}
		else if (strcmp(buffer, "value") == 0)
		{
			fscanf(file, "%d", &graph->value);
		}
		else if (strcmp(buffer, "complet") == 0)
		{
			fscanf(file, "%d", &graph->complet);
		}
		else if (strcmp(buffer, "debutDefAretes") == 0)
		{
			while (fscanf(file, "%s", buffer), strcmp(buffer, "finDefAretes") != 0)
			{
				indice = atoi(buffer);
				fscanf(file, "%s", buffer);
				donnee = atoi(buffer);
				inserer(&graph->adj[indice][0], initialiserCellule(donnee));
				if (!graph->oriente)
				{
					inserer(&graph->adj[donnee][0], initialiserCellule(indice));
				}
			}
		}
	}
	fclose(file);
}

void afficherListesAdjacences(graphe_t *graph)
{
	int i;
	for (i = 0; i < graph->nSommets; ++i)
	{
		printf("(%d)\t", i);
		afficherListe(&graph->adj[i][0]);
		printf("\n");
	}
}

void creerMatriceAdjacences(graphe_t *graph)
{
	FILE *file = NULL;
	int indice = 0, donnee = 0;
	char buffer[27]; //suffisamment grand
	file = fopen("graphe1.txt", "r");
	if (file == NULL)
	{
		fprintf(stderr, "Ouverture du fichier impossible\n");
		exit(EXIT_FAILURE);
	}
	while (fscanf(file, "%s", buffer), !feof(file))
	{
		if (strcmp(buffer, "nSommets") == 0)
		{
			fscanf(file, "%d", &graph->nSommets);
			graph->matrice_adj = (int **)malloc(
				sizeof(int *) * graph->nSommets);
			//Créer tableau de listes adjacences
			for (int i = 0; i < graph->nSommets; ++i)
			{
				graph->matrice_adj[i] = (int *)malloc(
					sizeof(int) * graph->nSommets);
			}
			for (int i = 0; i < graph->nSommets; ++i)
			{
				for (int j = 0; j < graph->nSommets; ++j)
				{
					graph->matrice_adj[i][j] = 0;
				}
			}
		}
		else if (strcmp(buffer, "oriente") == 0)
		{
			fscanf(file, "%d", &graph->oriente);
		}
		else if (strcmp(buffer, "value") == 0)
		{
			fscanf(file, "%d", &graph->value);
		}
		else if (strcmp(buffer, "complet") == 0)
		{
			fscanf(file, "%d", &graph->complet);
		}
		else if (strcmp(buffer, "debutDefAretes") == 0)
		{
			while (fscanf(file, "%s", buffer), strcmp(buffer, "finDefAretes") != 0)
			{
				indice = atoi(buffer);
				fscanf(file, "%s", buffer);
				donnee = atoi(buffer);
				graph->matrice_adj[indice][donnee] = 1;
				if (!graph->oriente)
				{
					graph->matrice_adj[donnee][indice] = 1;
				}
			}
		}
	}
}

void afficherMatriceAdjacences(graphe_t *graph)
{
	for (int i = 0; i < graph->nSommets; ++i)
	{
		for (int j = 0; j < graph->nSommets; ++j)
		{
			printf("%d\t", graph->matrice_adj[i][j]);
		}
		printf("\n");
	}
}

graphe_t *creerGraphe(int choice)
{ // choice = 1 : liste ; matrice
	graphe_t *graph = NULL;
	graph = malloc(sizeof(graphe_t));
	if (choice)
	{
		creerListesAdjacences(graph);
	}
	else
	{
		creerMatriceAdjacences(graph);
	}
	return graph;
}

void detruireGraphe(graphe_t *graph)
{
	if (graph->adj != NULL)
	{
		for (int i = 0; i < graph->nSommets; ++i)
		{
			detruireListe(&graph->adj[i][0]);
		}
		free(graph->adj);
	}
	else if (graph->matrice_adj != NULL)
	{
		for (int i = 0; i < graph->nSommets; ++i)
		{
			free(graph->matrice_adj[i]);
		}
		free(graph->matrice_adj);
		graph->matrice_adj = NULL;
	}
	free(graph);
}

void parcoursLargeur(graphe_t *graph)
{
	int couleur[graph->nSommets];
	int distance[graph->nSommets];
	liste_t *pere[graph->nSommets];
	file_t *queue = creerFile(12);
	for (int i = 0; i < graph->nSommets; ++i)
	{
		couleur[i] = BLANC;
		distance[i] = INT_MAX;
		pere[i] = NULL;
	}
	couleur[0] = GRIS;
	distance[0] = 0;
	pere[0] = NULL;
	enfile(queue, graph->adj[0]);
	while (!file_isEmpty(queue))
	{
		liste_t *u = front(queue);
		cellule_t *cell;
		for (cell = u->tete; cell != NULL; cell = cell->succ)
		{
			if (couleur[cell->value] == BLANC)
			{
				couleur[cell->value] = GRIS;
				distance[cell->value] = distance[u->tete->value] + 1;
				pere[cell->value] = u;
				enfile(queue, graph->adj[cell->value]);
				defile(queue);
			}
		}
		couleur[u->tete->value] = NOIR;
	}
}
