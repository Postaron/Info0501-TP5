#ifndef GRAPHE_H_
#define GRAPHE_H_

typedef struct {
	int nSommets; // nombre de sommet
	int oriente; //oriente : 1 ; sinon 0
	int value; //évalué : 1 ; sinon 0
	int complet; //complet : 1 ; sinon 0

} graphe_t;

#endif /* GRAPHE_H_ */
