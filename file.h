#ifndef FILE_H_
#define FILE_H_

#include "liste.h"

typedef struct file
{
	int front, rear, size, capacity;
	liste_t **array;
} file_t;

file_t *creerFile(unsigned int capacite);
void detruireFile(file_t *queue);
int file_isFull(file_t *queue);
int file_isEmpty(file_t *queue);
void enfile(file_t *queue, liste_t *item);
liste_t *defile(file_t *queue);
liste_t *front(file_t *queue);
liste_t *rear(file_t *queue);

#endif /* FILE_H_ */
