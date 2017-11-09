#include "outilsListe.h"
#include <stdio.h>
#include <stdlib.h>

void afficherListe(liste_t * pliste) {
	cellule_t * ptemp;
	ptemp = pliste->tete;
	do {
		puts(ptemp->value);
		if (ptemp->succ != NULL) {
			ptemp = ptemp->succ;
		} else {
			ptemp = NULL;
		}
	} while (ptemp != NULL);
}
