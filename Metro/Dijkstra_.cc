
#include <iostream>
#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include <mpi.h>

#include "Header.h"



using namespace std;

/* Calcula el coste minimo de alcanzar un nodo final 'b'
 * grafo no dirigido con N nodos, a partir del nodo inicial 'a',
 * dada su matriz de adyacencia A */
void dijkstra( int N, int **A, int a, int b ,string L[106],int argc,char *argv[]) {

   label_t *Labels;
   int i, i0, j, peso;
   int *ruta;		/* array de nodos de la ruta minima */
   /* Crea din'amicamente el arreglo de etiquetas de nodo */
   if ( ( Labels = new label_t[N] ) == NULL ){return;}
   /* nodo inicial 'a' entre 0 y N - 1 */
   if ( a < 0 || a > N - 1 ) return;
   /* nodo final 'a' entre 0 y N - 1 */
   if ( b < 0 || b > N - 1 ) return;
   /* inicializar las etiquetas de nodo */
    int n=107,myid, numprocs;
    double mypi;
    //MPI_Status status;

    MPI_Init(&argc,&argv);
    MPI_Comm_size(MPI_COMM_WORLD, &numprocs);
    MPI_Comm_rank(MPI_COMM_WORLD, &myid);
    // El proceso 0 envía el número de intervalos
    // al resto de los procesos
    MPI_Bcast(&n, 1, MPI_INT, 0, MPI_COMM_WORLD);

   for ( i = myid; i < n; i+=numprocs ) {
      Labels[i].nro = i;
      if ( i != a ) {
         Labels[i].prev = -1;	/* a'un no se ha definido predecesor */
         Labels[i].peso = -1;	/* infinito */
         Labels[i].marca = 0;
      }
      else {
         Labels[i].prev = -1;	/* a'un no se ha definido predecesor */
         Labels[i].peso = 0;		/* coste del nodo inicial a s'i mismo es cero */
         Labels[i].marca = 0;
      }
   }
   printf("\nProceso:%d  \n", myid);
   MPI_Finalize();
   /* continuamos este ciclo mientras existan nodos no marcados */
   while ( 1 ) {
      /* busca entre todos los nodos no marcados el de menor peso, descartando los
       * de peso infinito (-1) */
      peso = -1;
      i0 = -1;
      for ( i = 0; i < N; i++ ) {
         if ( Labels[i].marca == 0 && Labels[i].peso >= 0 )
            if ( peso == -1 ) {
               peso = Labels[i].peso;
               i0 = i;
            }
            else if ( Labels[i].peso <= peso ) {
               peso = Labels[i].peso;
               i0 = i;
            }
      }
      if ( i0 == -1 ) {	/* termina si no encuentra */
         //cout << "Ya no quedan nodos por analizar." << endl;
         break;
      }
      //cout << "*** Analizando nodo " << i0 << " ***" << endl;

      /* actualiza el peso de todos los sucesores (si los hay) del nodo
       * encontrado y luego se~nala dicho nodo como marcado */
       int cont=0;
      for ( i = 0; i < N; i++ ) {
         if ( A[i0][i] > 0 ) {
            /* si el coste acumulado sumado al coste del enlace del nodo i0 al nodo i
             * es menor al coste del nodo i (o si el coste del nodo i es infinito),
             * debemos actualizar */
            if ( Labels[i].peso == -1 || Labels[i0].peso + A[i0][i] < Labels[i].peso ) {
               if ( Labels[i0].peso + A[i0][i] < Labels[i].peso )
                  cout << "   [ mejorando coste de estacion " << L[i] << " ]" << endl;
               Labels[i].peso = Labels[i0].peso + A[i0][i];
               Labels[i].prev = i0;
               cout << "   coste desde " << L[a] << " hasta " << L[i] << ": " << Labels[i].peso << endl;
            }
         }

      }
      Labels[i0].marca = 1;
      //cout << "   [ nodo " << i0 << " marcado ]" << endl;

      /* para verificar, imprime los costes calculados hasta el momento */
      /*for ( i = 0; i < N; i++ ) {
         cout << i << ": [";
         if ( Labels[i].peso == -1 ) cout << "Inf";
         else cout << Labels[i].peso;
         cout << ", " << Labels[i].prev ;
         if ( Labels[i].marca == 1 ) cout <<  ", x]" << endl;
         else cout << "]" << endl;
      }
      cout << endl;
*/
      /* pausa (opcional) */
      //cout << "presione ENTER para continuar ...";
      //cin.get();
   }

   /* Ruta desde el nodo 'a' hasta el nodo 'b' */
   int longitud = 2;
   i = b;
   while ( ( i = Labels[i].prev ) != a ) longitud++;	/* primero estimamos la longitud de la ruta */
   if ( ( ruta = new int[longitud] ) == NULL ) return;

   ruta[longitud - 1] = b;		/* luego rellenamos */
   i = b;
   j = 0;
   for ( j = 1; j < longitud; j++ ) {
      i = Labels[i].prev;
      ruta[longitud - j - 1] = i;
   }

   cout << "================================================================" << endl;
   cout << endl << "Ruta mas economica entre: " << L[a] << " y " << L[b] << ":" << endl << endl;
   for ( i = 0; i < longitud; i++ ) {
      cout << L[ruta[i]];
      if ( i < longitud - 1 ) cout << " - ";
   }
   cout << endl << endl << "Numero de estaciones: " << Labels[b].peso << endl << endl;

   delete ruta;
   delete [] Labels;
}
