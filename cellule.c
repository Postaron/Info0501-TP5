#include "cellule.h"
#include <stdlib.h>
#include <string.h>

void initialiserCellule(cellule_t ** cell, char * mot) {
	(*cell)->succ = (*cell)->pred = NULL;
	strcpy((*cell)->mot, mot);
}

void detruireCellule(cellule_t ** dead) {
	(*dead)->pred = (*dead)->succ = NULL;
	free(*dead);
}
