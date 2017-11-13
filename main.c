#include <stdio.h>
#include <stdlib.h>
#include "graphe.h"

int main(void) {
	graphe_t * graphe = creerGraphe(0), *graphe2 = creerGraphe(1);
	afficherListesAdjacences(graphe2);
	afficherMatriceAdjacences(graphe);
	detruireGraphe(graphe);
	detruireGraphe(graphe2);
	return EXIT_SUCCESS;
}
