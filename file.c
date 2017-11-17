#include "file.h"
#include <stdlib.h>
#include <limits.h>

file_t *creerFile(unsigned int capacite)
{
	file_t *queue = (file_t *)malloc(sizeof(file_t));
	queue->capacity = capacite;
	queue->front = queue->size = 0;
	queue->rear = capacite - 1;
	queue->array = (cellule_t **)malloc(queue->capacity * sizeof(cellule_t *));
	return queue;
}

void detruireFile(file_t *queue)
{
	free(queue->array);
	free(queue);
	queue = NULL;
}

int file_isFull(file_t *queue)
{
	return (queue->size == queue->capacity);
}

int file_isEmpty(file_t *queue)
{
	return (queue->size == 0);
}

void enfile(file_t *queue, cellule_t *item)
{
	if (file_isFull(queue))
		return;
	queue->rear = (queue->rear + 1) % queue->capacity;
	queue->array[queue->rear] = item;
	++(queue->size);
}

cellule_t *defile(file_t *queue)
{
	if (file_isEmpty(queue))
		return NULL;
	cellule_t *item = queue->array[queue->front];
	queue->front = (queue->front + 1) % queue->capacity;
	--(queue->size);
	return item;
}

cellule_t *front(file_t *queue)
{
	if (file_isEmpty(queue))
		return NULL;
	return queue->array[queue->front];
}

cellule_t *rear(file_t *queue)
{
	if (file_isEmpty(queue))
		return NULL;
	return queue->array[queue->rear];
}
