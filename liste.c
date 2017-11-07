#include "liste.h"
#include <stdlib.h>
#include <string.h>

void initialiserListe(liste_t * pliste) {
	pliste->tete = NULL;
}

void inserer(liste_t * pliste, cellule_t * pcell) {
	if (pliste->tete != NULL) {
		pcell->succ = pliste->tete;
		pcell->pred = NULL;
		pliste->tete->pred = pcell;
		pliste->tete = pcell;
	} else {
		pcell->succ = pcell->pred = NULL;
		pliste->tete = pcell;
	}
}

cellule_t * rechercher(liste_t * pliste, char * mot) {
	cellule_t * pcell = NULL;
	pcell = pliste->tete;
	while (strcmp(mot, pcell->mot) != 0) {
		if (pcell->succ != NULL) {
			pcell = pcell->succ;
		} else
			return NULL;
	}
	return pcell;
}

void supprimer(liste_t * pliste, cellule_t * pcell) {
	cellule_t * ptemp;
	ptemp = pliste->tete;
	while (ptemp != pcell) {
		ptemp = ptemp->succ;
	}
	if (ptemp->succ == NULL && ptemp->pred != NULL) { //En fin de liste
		ptemp->pred->succ = NULL;
		free(ptemp);
	} else if (ptemp->pred == NULL && ptemp->succ != NULL) { //Tête de liste
		pliste->tete = ptemp->succ;
		ptemp->succ->pred = NULL;
		free(ptemp);
	} else if (ptemp->succ != NULL && ptemp->pred != NULL) { //Dans liste
		ptemp->pred->succ = ptemp->succ;
		ptemp->succ->pred = ptemp->pred;
		free(ptemp);
	} else { // Si seul
		pliste->tete = NULL;
		free(ptemp);
	}
}

void detruireListe(liste_t * pliste) {
	//Pointeurs pour parcourir la liste et mémoriser "celui à détruire"
	cellule_t * ptemp = NULL, *pdel = NULL;
	if (pliste != NULL) {
		ptemp = pliste->tete;
		while (ptemp != NULL) {
			pdel = ptemp;
			ptemp = ptemp->succ;
			//free(pdel); //Attention, fonctionne seulement si cellule alloué dynamiquement
		}
	}
}