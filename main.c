#include <stdio.h>
#include <stdlib.h>

#include "algo_parcours.h"
#include "graphe.h"

void menu(char *nomFichierTexte, int sommetOrigine, int sommetFin);

/**
 * arguments : nom_texte sommet_origine_parcours sommet_à_atteindre_avec_PL_ou_PP
 */
int main(int argc, char *argv[])
{
	int sommetOrigine, sommetFin;
	if (argc != 4)
	{
		fprintf(stderr, "Erreur, 4 arguments requis.\n");
		exit(EXIT_FAILURE);
	}
	sommetOrigine = atoi(argv[2]), sommetFin = atoi(argv[3]);
	menu(argv[1], sommetOrigine, sommetFin);
	return EXIT_SUCCESS;
}

void menu(char *nomFichierTexte, int sommetOrigine, int sommetFin)
{
	char reponse[] =
	{ 0, 0, 0 };
	graphe_t *graphe = creerGraphe(nomFichierTexte);

	while (reponse[0] != '5')
	{
		puts("MENU\n");
		puts(
				"1. Afficher les listes adjacences\t2. Afficher les matrices adjacences");
		puts("3. Parcours en largeur\t4. Parcours en profondeur récursif");
		puts("5. Quitter");
		fgets(reponse, 2, stdin);
		switch (reponse[0])
		{
		case '1':
			afficherListesAdjacences(graphe);
			break;
		case '2':
			afficherMatriceAdjacences(graphe);
			break;
		case '3':
			parcoursLargeur(graphe, sommetOrigine, sommetFin);
			break;
		case '4':
			parcoursProfondeurRecursif(graphe);
			break;
		case '5':
			puts("Vous quittez le programme.");
			break;
		default:
			puts(
					"Veuillez rentrer un des chiffres possibles pour une réponse !");
			break;
		}
	}
	puts("Destruction du graphe");
	detruireGraphe(graphe);
}
