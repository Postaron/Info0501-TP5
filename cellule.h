#ifndef CELLULE_H_
#define CELLULE_H_
#define TAILLE_MAX_MOT 26

typedef struct cellule_type {
	struct cellule_type * pred;
	struct cellule_type * succ;
	//char * mot;
	char mot[TAILLE_MAX_MOT + 1];
} cellule_t;

void initialiserCellule(cellule_t ** cell, char * mot); //Valide
void detruireCellule(cellule_t ** dead); //Valide ?

#endif /* CELLULE_H_ */
