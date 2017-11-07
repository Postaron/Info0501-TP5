#ifndef LISTE_H_
#define LISTE_H_
#include "cellule.h"

typedef struct {
	cellule_t * tete;
} liste_t;

void initialiserListe(liste_t * pliste); //Valide
void inserer(liste_t * pliste, cellule_t * pcell); //Valide
cellule_t * rechercher(liste_t * pliste, char * mot);
void supprimer(liste_t * pliste, cellule_t * pcell);
void detruireListe(liste_t * pliste);

#endif /* LISTE_H_ */
