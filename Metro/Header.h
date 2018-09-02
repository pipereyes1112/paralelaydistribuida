#ifndef HEADER_H_
#define HEADER_H_

struct label {
   int nro;	/* numero del nodo */
   int prev;	/* nodo precedente (-1 para el nodo inicial )*/
   int peso;	/* peso o coste total de la trayectoria que
				 * conduce al nodo, i.e., el coste total desde
				 * el nodo inicial hasta el actual. Un valor
				 * de -1 denota el infinito */
   int marca;	/* si el nodo ha sido marcado o no */
};
typedef struct label label_t;

#endif // HEADER_H_
