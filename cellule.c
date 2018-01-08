#include "cellule.h"
#include <stdlib.h>

cellule_t *initialiserCellule(int noeud)
{
	cellule_t *cell = NULL;
	cell = (cellule_t*) malloc(sizeof(cellule_t));
	cell->succ = cell->pred = NULL;
	cell->noeud = noeud;
	return cell;
}

void detruireCellule(cellule_t **dead)
{
	(*dead)->pred = (*dead)->succ = NULL;
	free(*dead);
	*dead = NULL;
}
