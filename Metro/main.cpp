#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

using namespace std;
string L6[] ={"LEN","ISU","NUO","ESN","NUB","BIO","FRA"
            ,"PAC","LVA","CER"};

string L5[] ={"VV","LF","MA","PE","SJ","AG"
            ,"CV","RA","NUB","IR","SI","PB"
            ,"BQ","BE","PZ","NA","RC","QN","GL"
            ,"BL","PR","SO","PU","BR","LS","LP"
            ,"MT","DS","SB","PM"};

string L4A[]={"LCI","SRA","SRO","LGR","SJU","VIM"};

string L4[] = {"PPA","PIN","LME","HSR"
            ,"ECO","LQU","SJE","TRI","RMA","VV"
            ,"VIM","MAC","LTO","RQU","LPR","RGR","LOR"
            ,"PEG","SBO","PDG","BIL","COL","TOB"};

string L2[] ={"LCI","EP","LO","CN","DE","LV","SN"
            ,"LL","FRA","RO","PQ","TO","HE","NA"
            ,"CA","PT","CB","CE","EI","DO","ZA"
            ,"AV"};

 string L1[] ={"LD","HM","MQ","EM","AL","GO"
            ,"TOB","LEN","PV","MM","SA","BQ"
            ,"UC","SL","CH","LM","HE","RP"
            ,"LA","EL","US","AH","EC"
            ,"LR","PJ","NP","SO"};


string Combi6[] = {"LEN","NUB","FRA"};
string Combi5[] = {"VV","NUB","BQ","NA","SO"};
string Combi4A[] = {"LCI","VIM"};
string Combi4[] = {"VV","VIM","TOB"};
string Combi2[] = {"LCI","FRA","HE","NA"};
string Combi1[] = {"TOB","LEN","BQ","HE","SO"};

/*
string Combi6[] = {0,4,6};
string Combi5[] = {0,8,12,15,21};
string Combi4A[] = {0,5};
string Combi4[] = {9,10,22};
string Combi2[] = {0,8,12,13};
string Combi1[] = {6,7,11,16,26};
*/
string Inicio,Destino, comando;
int FinL6=10,FinL5=30,FinL4A=6,FinL4=23,FinL2=22,FinL1=27;

typedef struct _nodo {
   int valor;
   struct _nodo *siguiente;
} tipoNodo;




typedef tipoNodo *pNodo;
typedef tipoNodo *Lista;

/* Funciones con listas: */
void Insertar(Lista *l, int v);
void Borrar(Lista *l, int v);

int ListaVacia(Lista l);
int buscarInicio(Lista l,string linea[]);
int buscarFin(Lista l,string linea[]);
int busca(Lista l,string linea[],string palabra);

void BorrarLista(Lista *);
void MostrarLista(Lista l,int inicio,int fin,string linea[]);

int main() {
    Lista Linea6 = NULL;
    Lista Linea5 = NULL;
    Lista Linea4A = NULL;
    Lista Linea4 = NULL;
    Lista Linea2 = NULL;
    Lista Linea1 = NULL;
    Lista Camino = NULL;
    Lista CaminoAux = NULL;
    pNodo p;
    int i=0,tiempo=0;

    while(i<FinL6){
        Insertar(&Linea6,i);
        i++;
    }
    i=0;

    while(i<FinL5){
        Insertar(&Linea5,i);
        i++;
    }
    i=0;

    while(i<FinL4A){
        Insertar(&Linea4A,i);
        i++;
    }
    i=0;

    while(i<FinL4){
        Insertar(&Linea4,i);
        i++;
    }
    i=0;

    while(i<FinL2){
        Insertar(&Linea2,i);
        i++;
    }
    i=0;

    while(i<FinL1){
        Insertar(&Linea1,i);
        i++;
    }
    //MostrarLista(Linea1);
    cout << "Ingrese comando, (-f, inicio, destino) o (-v)"
    getline(cin, comando)
    getline(cin, Inicio)
    getline(cin, Destino)

    if (comando=="-v"){
        cout << "Fabian Araya,      Nelson Roa,         Felipe Reyes" << endl; 
    }
    else{
    int in =0,fn=0;
    /*cout << "Indique La estacion de inicio" << endl;
    getline(cin,Inicio);
    cout << "Indique la estacion de destino" << endl;
    getline(cin,Destino);*/
    i=0;

    if(buscarInicio(Linea6,L6)!=-1 and (buscarFin(Linea6,L6)!=-1)){//desde L6 hasta L6
        if(buscarInicio(Linea6,L6)>buscarFin(Linea6,L6)){
            cout << "El numero de estaciones a recorrer es: " << buscarInicio(Linea6,L6)-buscarFin(Linea6,L6) << endl;
            MostrarLista(Linea6,buscarFin(Linea6,L6),buscarInicio(Linea6,L6),L6);
        }else{
            cout << "El numero de estaciones a recorrer es: " << buscarFin(Linea6,L6)-buscarInicio(Linea6,L6) << endl;
            MostrarLista(Linea6,buscarInicio(Linea6,L6),buscarFin(Linea6,L6),L6);
        }
    }else if(buscarInicio(Linea5,L5)!=-1 and (buscarFin(Linea5,L5)!=-1)){//desde L5 hasta L5
        if(buscarInicio(Linea5,L5)>buscarFin(Linea5,L5)){
            cout << "El numero de estaciones a recorrer es: " << buscarInicio(Linea5,L5)-buscarFin(Linea5,L5) << endl;
            MostrarLista(Linea5,buscarFin(Linea5,L5),buscarInicio(Linea5,L5),L5);
        }else{
            cout << "El numero de estaciones a recorrer es: " << buscarFin(Linea5,L5)-buscarInicio(Linea5,L5) << endl;
            MostrarLista(Linea5,buscarInicio(Linea5,L5),buscarFin(Linea5,L5),L5);
        }
    }else if(buscarInicio(Linea4A,L4A)!=-1 and buscarFin(Linea4A,L4A)!=-1){//desde L4A hasta L4A
        if(buscarInicio(Linea4A,L4A)>buscarFin(Linea4A,L4A)!=(-1)){
            cout << "El numero de estaciones a recorrer es: " << buscarInicio(Linea4A,L4A)-buscarFin(Linea4A,L4A) << endl;
            MostrarLista(Linea4A,buscarFin(Linea4A,L4A),buscarInicio(Linea4A,L4A),L4A);
        }else{
            cout << "El numero de estaciones a recorrer es: " << buscarFin(Linea4A,L4A)-buscarInicio(Linea4A,L4A) << endl;
            MostrarLista(Linea4A,buscarInicio(Linea4A,L4A),buscarFin(Linea4A,L4A),L4A);
        }
    }else if(buscarInicio(Linea4,L4)!=(-1) and buscarFin(Linea4,L4)!=(-1)){//desde L4 hasta L4
        if(buscarInicio(Linea4,L4)>buscarFin(Linea4,L4)!=-1){
            cout << "El numero de estaciones a recorrer es: " << buscarInicio(Linea4,L4)-buscarFin(Linea4,L4) << endl;
            MostrarLista(Linea4,buscarFin(Linea4,L4),buscarInicio(Linea4,L4),L4);
        }else{
            cout << "El numero de estaciones a recorrer es: " << buscarFin(Linea4,L4)-buscarInicio(Linea4,L4) << endl;
            MostrarLista(Linea4,buscarInicio(Linea4,L4),buscarFin(Linea4,L4),L4);
        }
    }else if(buscarInicio(Linea2,L2)!=(-1) and buscarFin(Linea2,L2)!=(-1)){//desde L2 hasta L2
        if(buscarInicio(Linea2,L2)>buscarFin(Linea2,L2)!=(-1)){
            cout << "El numero de estaciones a recorrer es: " << buscarInicio(Linea2,L2)-buscarFin(Linea2,L2) << endl;
            MostrarLista(Linea2,buscarFin(Linea2,L2),buscarInicio(Linea2,L2),L2);
        }else{
            cout << "El numero de estaciones a recorrer es: " << buscarFin(Linea2,L2)-buscarInicio(Linea2,L2) << endl;
            MostrarLista(Linea2,buscarInicio(Linea2,L2),buscarFin(Linea2,L2),L2);
        }
    }else if(buscarInicio(Linea1,L1)!=(-1) and buscarFin(Linea1,L1)!=(-1)){//desde L1 hasta L1
        if(buscarInicio(Linea1,L1)>buscarFin(Linea1,L1)!=(-1)){
            cout << "El numero de estaciones a recorrer es: " << buscarInicio(Linea1,L1)-buscarFin(Linea1,L1) << endl;
            MostrarLista(Linea1,buscarFin(Linea1,L1),buscarInicio(Linea1,L1),L1);
        }else{
            cout << "El numero de estaciones a recorrer es: " << buscarFin(Linea1,L1)-buscarInicio(Linea1,L1) << endl;
            MostrarLista(Linea1,buscarInicio(Linea1,L1),buscarFin(Linea1,L1),L1);
        }
    }else if (buscarInicio(Linea1,L1)!=(-1) and buscarFin(Linea2,L2)!=(-1)){//desde L1 hasta L2


        for(int x=0; x<5; x++){
            string aux1=Combi1[x];
            for(int y=0; y<4; y++){
                string aux2=Combi2[y];

                if(aux1==aux2){//Si existe combinacion entre L1 y L2(arreglar el caso de dos combinaciones)


                    if((busca(Linea1,L1,Combi1[x])) < buscarInicio(Linea1,L1) ){
                        MostrarLista(Linea1,busca(Linea1,L1,Combi1[x]),buscarInicio(Linea1,L1),L1);
                        if(buscarFin(Linea2,L2)>busca(Linea2,L2,Combi2[y])){
                            MostrarLista(Linea2,busca(Linea2,L2,Combi2[y]),buscarFin(Linea2,L2),L2);
                        }else{
                            MostrarLista(Linea2,buscarFin(Linea2,L2),busca(Linea2,L2,Combi2[y]),L2);
                        }
                    }else{
                        MostrarLista(Linea1,buscarInicio(Linea1,L1),busca(Linea1,L1,Combi1[x]),L1);
                        if(buscarFin(Linea2,L2)>busca(Linea2,L2,Combi2[y])){
                            MostrarLista(Linea2,buscarFin(Linea2,L2),busca(Linea2,L2,Combi2[y]),L2);
                        }else{
                            MostrarLista(Linea2,busca(Linea2,L2,Combi2[y]),buscarFin(Linea2,L2),L2);
                        }
                    }
                }
            }
        }
    }else if (buscarInicio(Linea1,L1)!=-1 and buscarFin(Linea4,L4)!=-1){//desde L1 hasta L4
        for(int x=0; x<5; x++){
            string aux1=Combi1[x];
            for(int y=0; y<3; y++){
                string aux2=Combi4[y];

                if(aux1==aux2){//Si existe combinacion entre L1 y L2(arreglar el caso de dos combinaciones)


                    if((busca(Linea1,L1,Combi1[x])) <= buscarInicio(Linea1,L1) ){

                        MostrarLista(Linea1,busca(Linea1,L1,Combi1[x]),buscarInicio(Linea1,L1),L1);
                        if(buscarFin(Linea4,L4)>busca(Linea4,L4,Combi4[y])){
                            MostrarLista(Linea4,busca(Linea4,L4,Combi4[y]),buscarFin(Linea4,L4),L4);
                        }else{
                            MostrarLista(Linea4,buscarFin(Linea4,L4),busca(Linea4,L4,Combi4[y]),L4);
                        }
                    }else{
                        //cout<< aux1<< endl;
                        MostrarLista(Linea1,buscarInicio(Linea1,L1),busca(Linea1,L1,Combi1[x]),L1);
                        //cout<<buscarFin(Linea4,L4)<<"---"<<Combi4[y]<<busca(Linea4,L4,Combi4[y]) << endl;
                        if(buscarFin(Linea4,L4)<busca(Linea4,L4,Combi4[y])){
                            MostrarLista(Linea4,buscarFin(Linea4,L4),busca(Linea4,L4,Combi4[y]),L4);
                        }else{
                            MostrarLista(Linea4,busca(Linea4,L4,Combi4[y]),buscarFin(Linea4,L4),L4);
                        }
                    }
                }
            }
        }

    }else if (buscarInicio(Linea1,L1)!=-1 and buscarFin(Linea5,L5)!=-1){//desde L1 hasta L5
            for(int x=0; x<5; x++){
            string aux1=Combi1[x];
            for(int y=0; y<5; y++){
                string aux2=Combi5[y];

                if(aux1==aux2){//Si existe combinacion entre L1 y L5(arreglar el caso de dos combinaciones)


                    if((busca(Linea1,L1,Combi1[x])) <= buscarInicio(Linea1,L1) ){

                        MostrarLista(Linea1,busca(Linea1,L1,Combi1[x]),buscarInicio(Linea1,L1),L1);
                        if(buscarFin(Linea5,L5)>busca(Linea5,L5,Combi5[y])){
                            MostrarLista(Linea5,busca(Linea5,L5,Combi5[y]),buscarFin(Linea5,L5),L5);
                        }else{
                            MostrarLista(Linea5,buscarFin(Linea5,L5),busca(Linea5,L5,Combi5[y]),L5);
                        }
                    }else{
                        //cout<< aux1<< endl;
                        MostrarLista(Linea1,buscarInicio(Linea1,L1),busca(Linea1,L1,Combi1[x]),L1);
                        //cout<<buscarFin(Linea5,L5)<<"---"<<Combi5[y]<<busca(Linea5,L5,Combi5[y]) << endl;
                        if(buscarFin(Linea5,L5)<busca(Linea5,L5,Combi5[y])){
                            MostrarLista(Linea5,buscarFin(Linea5,L5),busca(Linea5,L5,Combi5[y]),L5);
                        }else{
                            MostrarLista(Linea5,busca(Linea5,L5,Combi5[y]),buscarFin(Linea5,L5),L5);
                        }
                    }
                }
            }
        }

    }else if (buscarInicio(Linea1,L1)!=-1 and buscarFin(Linea6,L6)!=-1){//desde L1 hasta L6
            for(int x=0; x<5; x++){
            string aux1=Combi1[x];
            for(int y=0; y<3; y++){
                string aux2=Combi6[y];
                //cout<<aux1<<"--"<<aux2<<endl;
                if(aux1==aux2){//Si existe combinacion entre L1 y L6(arreglar el caso de dos combinaciones)

                    //cout<<buscarInicio(Linea1,L1)<<"---"<<busca(Linea1,L1,Combi1[x]) << endl;
                    if((busca(Linea1,L1,Combi1[x])) <= buscarInicio(Linea1,L1) ){

                        MostrarLista(Linea1,busca(Linea1,L1,Combi1[x]),buscarInicio(Linea1,L1),L1);
                        if(buscarFin(Linea6,L6)>busca(Linea6,L6,Combi6[y])){
                            MostrarLista(Linea6,busca(Linea6,L6,Combi6[y]),buscarFin(Linea6,L6),L6);
                        }else{
                            MostrarLista(Linea6,buscarFin(Linea6,L6),busca(Linea6,L6,Combi6[y]),L6);
                        }
                    }else{
                        //cout<< aux1<< endl;
                        MostrarLista(Linea1,buscarInicio(Linea1,L1),busca(Linea1,L1,Combi1[x]),L1);
                        //cout<<buscarFin(Linea6,L6)<<"---"<<Combi6[y]<<busca(Linea6,L6,Combi6[y]) << endl;
                        if(buscarFin(Linea6,L6)<busca(Linea6,L6,Combi6[y])){
                            MostrarLista(Linea6,buscarFin(Linea6,L6),busca(Linea6,L6,Combi6[y]),L6);
                        }else{
                            MostrarLista(Linea6,busca(Linea6,L6,Combi6[y]),buscarFin(Linea6,L6),L6);
                        }
                    }
                }
            }
        }

    }else if (buscarInicio(Linea1,L1)!=-1 and buscarFin(Linea4A,L4A)!=-1){//desde L1 hasta L4A(En Proceso)
            if(buscarFin(Linea2,L2)){}

    }else if (buscarInicio(Linea2,L2)!=-1 and buscarFin(Linea4A,L4A)!=-1){//desde L2 hasta L4A(En Proceso)

            for(int x=0; x<4; x++){
            string aux1=Combi2[x];
            for(int y=0; y<2; y++){
                string aux2=Combi4A[y];
                //cout<<aux2<<"--"<<aux1<<endl;

                if(aux1==aux2){//Si existe combinacion entre L1 y L6(arreglar el caso de dos combinaciones)
                    //cout<<"hola"<<endl;
                    //cout<<buscarInicio(Linea1,L1)<<"---"<<busca(Linea1,L1,Combi1[x]) << endl;
                    if((busca(Linea2,L2,Combi2[x])) <= buscarInicio(Linea2,L2) ){

                        MostrarLista(Linea2,busca(Linea2,L2,Combi2[x]),buscarInicio(Linea2,L2),L2);
                        if(buscarFin(Linea4A,L4A)>busca(Linea4A,L4A,Combi4A[y])){
                            MostrarLista(Linea4A,busca(Linea4A,L4A,Combi4A[y]),buscarFin(Linea4A,L4A),L4A);
                        }else{
                            MostrarLista(Linea4A,buscarFin(Linea4A,L4A),busca(Linea4A,L4A,Combi4A[y]),L4A);
                        }
                    }else{
                        //cout<< aux1<< endl;
                        MostrarLista(Linea2,buscarInicio(Linea2,L2),busca(Linea2,L2,Combi2[x]),L2);
                        //cout<<buscarFin(Linea6,L6)<<"---"<<Combi6[y]<<busca(Linea6,L6,Combi6[y]) << endl;
                        if(buscarFin(Linea4A,L4A)<busca(Linea4A,L4A,Combi4A[y])){
                            MostrarLista(Linea4A,buscarFin(Linea4A,L4A),busca(Linea4A,L4A,Combi4A[y]),L4A);
                        }else{
                            MostrarLista(Linea4A,busca(Linea4A,L4A,Combi4A[y]),buscarFin(Linea4A,L4A),L4A);
                        }
                    }
                }
            }
        }

    }else if (buscarInicio(Linea2,L2)!=-1 and buscarFin(Linea4,L4)!=-1){//desde L2 hasta L4(En Proceso)
            if(buscarFin(Linea2,L2)){}

    }else if (buscarInicio(Linea2,L2)!=-1 and buscarFin(Linea5,L5)!=-1){//desde L2 hasta L5(En Proceso)(cASO DE DOS COMBINACIONES)
            for(int x=0; x<4; x++){
            string aux1=Combi2[x];
            for(int y=0; y<5; y++){
                string aux2=Combi5[y];
                //cout<<aux1<<"--"<<aux2<<endl;
                if(aux1==aux2){//Si existe combinacion entre L1 y L6(arreglar el caso de dos combinaciones)

                    //cout<<buscarInicio(Linea1,L1)<<"---"<<busca(Linea1,L1,Combi1[x]) << endl;
                    if((busca(Linea2,L2,Combi2[x])) <= buscarInicio(Linea2,L2) ){

                        MostrarLista(Linea2,busca(Linea2,L2,Combi2[x]),buscarInicio(Linea2,L2),L2);
                        if(buscarFin(Linea5,L5)>busca(Linea5,L5,Combi5[y])){
                            MostrarLista(Linea5,busca(Linea5,L5,Combi5[y]),buscarFin(Linea5,L5),L5);
                        }else{
                            MostrarLista(Linea5,buscarFin(Linea5,L5),busca(Linea5,L5,Combi5[y]),L5);
                        }
                    }else{
                        //cout<< aux1<< endl;
                        MostrarLista(Linea2,buscarInicio(Linea2,L2),busca(Linea2,L2,Combi2[x]),L2);
                        //cout<<buscarFin(Linea6,L6)<<"---"<<Combi6[y]<<busca(Linea6,L6,Combi6[y]) << endl;
                        if(buscarFin(Linea5,L5)<busca(Linea5,L5,Combi5[y])){
                            MostrarLista(Linea5,buscarFin(Linea5,L5),busca(Linea5,L5,Combi5[y]),L5);
                        }else{
                            MostrarLista(Linea5,busca(Linea5,L5,Combi5[y]),buscarFin(Linea5,L5),L5);
                        }
                    }
                }
            }
        }

    }else if (buscarInicio(Linea2,L2)!=-1 and buscarFin(Linea6,L6)!=-1){//desde L2 hasta L6(En Proceso)
            for(int x=0; x<4; x++){
            string aux1=Combi2[x];
            for(int y=0; y<3; y++){
                string aux2=Combi6[y];
                //cout<<aux1<<"--"<<aux2<<endl;
                if(aux1==aux2){//Si existe combinacion entre L1 y L6(arreglar el caso de dos combinaciones)

                    //cout<<buscarInicio(Linea1,L1)<<"---"<<busca(Linea1,L1,Combi1[x]) << endl;
                    if((busca(Linea2,L2,Combi2[x])) <= buscarInicio(Linea2,L2) ){

                        MostrarLista(Linea2,busca(Linea2,L2,Combi2[x]),buscarInicio(Linea2,L2),L2);
                        if(buscarFin(Linea6,L6)>busca(Linea6,L6,Combi6[y])){
                            MostrarLista(Linea6,busca(Linea6,L6,Combi6[y]),buscarFin(Linea6,L6),L6);
                        }else{
                            MostrarLista(Linea6,buscarFin(Linea6,L6),busca(Linea6,L6,Combi6[y]),L6);
                        }
                    }else{
                        //cout<< aux1<< endl;
                        MostrarLista(Linea2,buscarInicio(Linea2,L2),busca(Linea2,L2,Combi2[x]),L2);
                        //cout<<buscarFin(Linea6,L6)<<"---"<<Combi6[y]<<busca(Linea6,L6,Combi6[y]) << endl;
                        if(buscarFin(Linea6,L6)<busca(Linea6,L6,Combi6[y])){
                            MostrarLista(Linea6,buscarFin(Linea6,L6),busca(Linea6,L6,Combi6[y]),L6);
                        }else{
                            MostrarLista(Linea6,busca(Linea6,L6,Combi6[y]),buscarFin(Linea6,L6),L6);
                        }
                    }
                }
            }
        }

    }else if (buscarInicio(Linea2,L2)!=-1 and buscarFin(Linea1,L1)==-1){//desde L2 hasta L1(En Proceso)
            for(int x=0; x<4; x++){
            string aux1=Combi2[x];
            for(int y=0; y<5; y++){
                string aux2=Combi1[y];
                //cout<<aux1<<"--"<<aux2<<endl;
                if(aux1==aux2){//Si existe combinacion entre L1 y L6(arreglar el caso de dos combinaciones)

                    //cout<<buscarInicio(Linea1,L1)<<"---"<<busca(Linea1,L1,Combi1[x]) << endl;
                    if((busca(Linea2,L2,Combi2[x])) <= buscarInicio(Linea2,L2) ){

                        MostrarLista(Linea2,busca(Linea2,L2,Combi2[x]),buscarInicio(Linea2,L2),L2);
                        if(buscarFin(Linea1,L1)>busca(Linea1,L1,Combi1[y])){
                            MostrarLista(Linea1,busca(Linea1,L1,Combi1[y]),buscarFin(Linea1,L1),L1);
                        }else{
                            MostrarLista(Linea1,buscarFin(Linea1,L1),busca(Linea1,L1,Combi1[y]),L1);
                        }
                    }else{
                        //cout<< aux1<< endl;
                        MostrarLista(Linea2,buscarInicio(Linea2,L2),busca(Linea2,L2,Combi2[x]),L2);
                        //cout<<buscarFin(Linea6,L6)<<"---"<<Combi6[y]<<busca(Linea6,L6,Combi6[y]) << endl;
                        if(buscarFin(Linea1,L1)<busca(Linea1,L1,Combi1[y])){
                            MostrarLista(Linea1,buscarFin(Linea1,L1),busca(Linea1,L1,Combi1[y]),L1);
                        }else{
                            MostrarLista(Linea1,busca(Linea1,L1,Combi1[y]),buscarFin(Linea1,L1),L1);
                        }
                    }
                }
            }
        }

    }else if (buscarInicio(Linea4,L4)!=-1 and buscarFin(Linea1,L1)!=-1){//desde L4 hasta L1(En Proceso)
            for(int x=0; x<3; x++){
            string aux1=Combi4[x];
            for(int y=0; y<5; y++){
                string aux2=Combi1[y];
                //cout<<aux1<<"--"<<aux2<<endl;
                if(aux1==aux2){//Si existe combinacion entre L1 y L6(arreglar el caso de dos combinaciones)

                    //cout<<buscarInicio(Linea1,L1)<<"---"<<busca(Linea1,L1,Combi1[x]) << endl;
                    if((busca(Linea4,L4,Combi4[x])) <= buscarInicio(Linea4,L4) ){

                        MostrarLista(Linea4,busca(Linea4,L4,Combi4[x]),buscarInicio(Linea4,L4),L4);
                        if(buscarFin(Linea1,L1)>busca(Linea1,L1,Combi1[y])){
                            MostrarLista(Linea1,busca(Linea1,L1,Combi1[y]),buscarFin(Linea1,L1),L1);
                        }else{
                            MostrarLista(Linea1,buscarFin(Linea1,L1),busca(Linea1,L1,Combi1[y]),L1);
                        }
                    }else{
                        //cout<< aux1<< endl;
                        MostrarLista(Linea4,buscarInicio(Linea4,L4),busca(Linea4,L4,Combi4[x]),L4);
                        //cout<<buscarFin(Linea6,L6)<<"---"<<Combi6[y]<<busca(Linea6,L6,Combi6[y]) << endl;
                        if(buscarFin(Linea1,L1)<busca(Linea1,L1,Combi1[y])){
                            MostrarLista(Linea1,buscarFin(Linea1,L1),busca(Linea1,L1,Combi1[y]),L1);
                        }else{
                            MostrarLista(Linea1,busca(Linea1,L1,Combi1[y]),buscarFin(Linea1,L1),L1);
                        }
                    }
                }
            }
        }


    }else if (buscarInicio(Linea4,L4)!=-1 and buscarFin(Linea2,L2)!=-1){//combinacion L4 con la L2
            for(int x=0; x<3; x++){
            string aux1=Combi4[x];
            for(int y=0; y<4; y++){
                string aux2=Combi2[y];

                if(aux1==aux2){//Si existe combinacion entre L1 y L2(arreglar el caso de dos combinaciones)


                    if((busca(Linea4,L4,Combi4[x])) < buscarInicio(Linea4,L4) ){
                        MostrarLista(Linea4,busca(Linea4,L4,Combi4[x]),buscarInicio(Linea4,L4),L4);
                        if(buscarFin(Linea2,L2)>busca(Linea2,L2,Combi2[y])){
                            MostrarLista(Linea2,busca(Linea2,L2,Combi2[y]),buscarFin(Linea2,L2),L2);
                        }else{
                            MostrarLista(Linea2,buscarFin(Linea2,L2),busca(Linea2,L2,Combi2[y]),L2);
                        }
                    }else{
                        MostrarLista(Linea4,buscarInicio(Linea4,L4),busca(Linea4,L4,Combi4[x]),L4);
                        if(buscarFin(Linea2,L2)>busca(Linea2,L2,Combi2[y])){
                            MostrarLista(Linea2,buscarFin(Linea2,L2),busca(Linea2,L2,Combi2[y]),L2);
                        }else{
                            MostrarLista(Linea2,busca(Linea2,L2,Combi2[y]),buscarFin(Linea2,L2),L2);
                        }
                    }
                }
            }
        }

    }else if (buscarInicio(Linea4,L4)!=-1 and buscarFin(Linea4A,L4A)!=-1){//COMBINACION L4 CON L4A
            for(int x=0; x<3; x++){
            string aux1=Combi4[x];
            for(int y=0; y<2; y++){
                string aux2=Combi4A[y];

                if(aux1==aux2){//Si existe combinacion entre L1 y L2(arreglar el caso de dos combinaciones)


                    if((busca(Linea4,L4,Combi4[x])) < buscarInicio(Linea4,L4) ){

                        MostrarLista(Linea4,busca(Linea4,L4,Combi4[x]),buscarInicio(Linea4,L4),L4);
                         //cout << Combi4A[y] <<busca(Linea4A,L4A,Combi4A[y])<<endl;
                        if(buscarFin(Linea4A,L4A)>busca(Linea4A,L4A,Combi4A[y])){
                            MostrarLista(Linea4A,busca(Linea4A,L4A,Combi4A[y]),buscarFin(Linea4A,L4A),L4A);
                        }else{
                            MostrarLista(Linea4A,buscarFin(Linea4A,L4A),busca(Linea4A,L4A,Combi4A[y]),L4A);
                        }
                    }else{
                        MostrarLista(Linea4,buscarInicio(Linea4,L4),busca(Linea4,L4,Combi4[x]),L4);
                        if(buscarFin(Linea4A,L4A)>=busca(Linea4A,L4A,Combi4A[y])){
                            MostrarLista(Linea4A,buscarFin(Linea4A,L4A),busca(Linea4A,L4A,Combi4A[y]),L4A);
                        }else{
                            MostrarLista(Linea4A,busca(Linea4A,L4A,Combi4A[y]),buscarFin(Linea4A,L4A),L4A);
                        }
                    }
                }
            }
        }

    }else if (buscarInicio(Linea4,L4)!=-1 and buscarFin(Linea5,L5)!=-1){//COMBINACION L4 CON L5
            for(int x=0; x<3; x++){
            string aux1=Combi4[x];
            for(int y=0; y<5; y++){
                string aux2=Combi5[y];

                if(aux1==aux2){//Si existe combinacion entre L1 y L5(arreglar el caso de dos combinaciones)


                    if((busca(Linea4,L4,Combi4[x])) <= buscarInicio(Linea4,L4) ){

                        MostrarLista(Linea4,busca(Linea4,L4,Combi4[x]),buscarInicio(Linea4,L4),L4);
                        if(buscarFin(Linea5,L5)>busca(Linea5,L5,Combi5[y])){
                            MostrarLista(Linea5,busca(Linea5,L5,Combi5[y]),buscarFin(Linea5,L5),L5);
                        }else{
                            MostrarLista(Linea5,buscarFin(Linea5,L5),busca(Linea5,L5,Combi5[y]),L5);
                        }
                    }else{
                        //cout<< aux1<< endl;
                        MostrarLista(Linea4,buscarInicio(Linea4,L4),busca(Linea4,L4,Combi4[x]),L4);
                        //cout<<buscarFin(Linea5,L5)<<"---"<<Combi5[y]<<busca(Linea5,L5,Combi5[y]) << endl;
                        if(buscarFin(Linea5,L5)<busca(Linea5,L5,Combi5[y])){
                            MostrarLista(Linea5,buscarFin(Linea5,L5),busca(Linea5,L5,Combi5[y]),L5);
                        }else{
                            MostrarLista(Linea5,busca(Linea5,L5,Combi5[y]),buscarFin(Linea5,L5),L5);
                        }
                    }
                }
            }
        }

    }else if (buscarInicio(Linea4,L4)!=-1 and buscarFin(Linea6,L6)!=-1){//Combinacion L4 con L6(Falta)
            if(buscarFin(Linea2,L2)){}

    }else if (buscarInicio(Linea4A,L4A)!=-1 and buscarFin(Linea1,L1)!=-1){//Combinacion L4A con L1
            if(buscarFin(Linea2,L2)){}

    }else if (buscarInicio(Linea4A,L4A)!=-1 and buscarFin(Linea2,L2)!=-1){//Combinacion L4A con L2
            for(int x=0; x<2; x++){
            string aux1=Combi4A[x];
            for(int y=0; y<4; y++){
                string aux2=Combi2[y];

                if(aux1==aux2){//Si existe combinacion entre L1 y L2(arreglar el caso de dos combinaciones)


                    if((busca(Linea4A,L4A,Combi4A[x])) < buscarInicio(Linea4A,L4A) ){
                        MostrarLista(Linea4A,busca(Linea4A,L4A,Combi4A[x]),buscarInicio(Linea4A,L4A),L4A);
                        if(buscarFin(Linea2,L2)>busca(Linea2,L2,Combi2[y])){
                            MostrarLista(Linea2,busca(Linea2,L2,Combi2[y]),buscarFin(Linea2,L2),L2);
                        }else{
                            MostrarLista(Linea2,buscarFin(Linea2,L2),busca(Linea2,L2,Combi2[y]),L2);
                        }
                    }else{
                        MostrarLista(Linea4A,buscarInicio(Linea4A,L4A),busca(Linea4A,L4A,Combi4A[x]),L4A);
                        if(buscarFin(Linea2,L2)>busca(Linea2,L2,Combi2[y])){
                            MostrarLista(Linea2,buscarFin(Linea2,L2),busca(Linea2,L2,Combi2[y]),L2);
                        }else{
                            MostrarLista(Linea2,busca(Linea2,L2,Combi2[y]),buscarFin(Linea2,L2),L2);
                        }
                    }
                }
            }
        }

    }else if (buscarInicio(Linea4A,L4A)!=-1 and buscarFin(Linea4,L4)!=-1){//Combinacion L4A con L4
            for(int x=0; x<2; x++){
            string aux1=Combi4A[x];
            for(int y=0; y<3; y++){
                string aux2=Combi4[y];

                if(aux1==aux2){//Si existe combinacion entre L1 y L2(arreglar el caso de dos combinaciones)


                    if((busca(Linea4A,L4A,Combi4A[x])) <= buscarInicio(Linea4A,L4A) ){

                        MostrarLista(Linea4A,busca(Linea4A,L4A,Combi4A[x]),buscarInicio(Linea4A,L4A),L4A);
                        if(buscarFin(Linea4,L4)>busca(Linea4,L4,Combi4[y])){
                            MostrarLista(Linea4,busca(Linea4,L4,Combi4[y]),buscarFin(Linea4,L4),L4);
                        }else{
                            MostrarLista(Linea4,buscarFin(Linea4,L4),busca(Linea4,L4,Combi4[y]),L4);
                        }
                    }else{
                        //cout<< aux1<< endl;
                        MostrarLista(Linea4A,buscarInicio(Linea4A,L4A),busca(Linea4A,L4A,Combi4A[x]),L4A);
                        //cout<<buscarFin(Linea4,L4)<<"---"<<Combi4[y]<<busca(Linea4,L4,Combi4[y]) << endl;
                        if(buscarFin(Linea4,L4)<busca(Linea4,L4,Combi4[y])){
                            MostrarLista(Linea4,buscarFin(Linea4,L4),busca(Linea4,L4,Combi4[y]),L4);
                        }else{
                            MostrarLista(Linea4,busca(Linea4,L4,Combi4[y]),buscarFin(Linea4,L4),L4);
                        }
                    }
                }
            }
        }

    }else if (buscarInicio(Linea2,L2)!=-1 and buscarFin(Linea4,L4)!=-1){//Combinacion L4A con L5
            if(buscarFin(Linea2,L2)){}

    }else if (buscarInicio(Linea2,L2)!=-1 and buscarFin(Linea4,L4)!=-1){//Combinacion L4A con L6
            if(buscarFin(Linea2,L2)){}

    }else if (buscarInicio(Linea5,L5)!=-1 and buscarFin(Linea1,L1)!=-1){//Combinacion L5 con L1
            for(int x=0; x<5; x++){
            string aux1=Combi5[x];
            for(int y=0; y<5; y++){
                string aux2=Combi1[y];
                //cout<<aux1<<"--"<<aux2<<endl;
                if(aux1==aux2){//Si existe combinacion entre L1 y L6(arreglar el caso de dos combinaciones)

                    //cout<<buscarInicio(Linea1,L1)<<"---"<<busca(Linea1,L1,Combi1[x]) << endl;
                    if((busca(Linea5,L5,Combi5[x])) <= buscarInicio(Linea5,L5) ){

                        MostrarLista(Linea5,busca(Linea5,L5,Combi5[x]),buscarInicio(Linea5,L5),L5);
                        if(buscarFin(Linea1,L1)>busca(Linea1,L1,Combi1[y])){
                            MostrarLista(Linea1,busca(Linea1,L1,Combi1[y]),buscarFin(Linea1,L1),L1);
                        }else{
                            MostrarLista(Linea1,buscarFin(Linea1,L1),busca(Linea1,L1,Combi1[y]),L1);
                        }
                    }else{
                        //cout<< aux1<< endl;
                        MostrarLista(Linea5,buscarInicio(Linea5,L5),busca(Linea5,L5,Combi5[x]),L5);
                        //cout<<buscarFin(Linea6,L6)<<"---"<<Combi6[y]<<busca(Linea6,L6,Combi6[y]) << endl;
                        if(buscarFin(Linea1,L1)<busca(Linea1,L1,Combi1[y])){
                            MostrarLista(Linea1,buscarFin(Linea1,L1),busca(Linea1,L1,Combi1[y]),L1);
                        }else{
                            MostrarLista(Linea1,busca(Linea1,L1,Combi1[y]),buscarFin(Linea1,L1),L1);
                        }
                    }
                }
            }
        }

    }else if (buscarInicio(Linea5,L5)!=-1 and buscarFin(Linea2,L2)!=-1){//cOMBINACION L5 CON L2
            for(int x=0; x<5; x++){
            string aux1=Combi5[x];
            for(int y=0; y<3; y++){
                string aux2=Combi2[y];

                if(aux1==aux2){//Si existe combinacion entre L1 y L2(arreglar el caso de dos combinaciones)


                    if((busca(Linea5,L5,Combi5[x])) < buscarInicio(Linea5,L5) ){
                        MostrarLista(Linea5,busca(Linea5,L5,Combi5[x]),buscarInicio(Linea5,L5),L5);
                        if(buscarFin(Linea2,L2)>busca(Linea2,L2,Combi2[y])){
                            MostrarLista(Linea2,busca(Linea2,L2,Combi2[y]),buscarFin(Linea2,L2),L2);
                        }else{
                            MostrarLista(Linea2,buscarFin(Linea2,L2),busca(Linea2,L2,Combi2[y]),L2);
                        }
                    }else{
                        MostrarLista(Linea5,buscarInicio(Linea5,L5),busca(Linea5,L5,Combi5[x]),L5);
                        if(buscarFin(Linea2,L2)>busca(Linea2,L2,Combi2[y])){
                            MostrarLista(Linea2,buscarFin(Linea2,L2),busca(Linea2,L2,Combi2[y]),L2);
                        }else{
                            MostrarLista(Linea2,busca(Linea2,L2,Combi2[y]),buscarFin(Linea2,L2),L2);
                        }
                    }
                }
            }
        }

    }else if (buscarInicio(Linea5,L5)!=-1 and buscarFin(Linea4,L4)!=-1){//cOMBINACION L5 CON L4
            for(int x=0; x<5; x++){
            string aux1=Combi5[x];
            for(int y=0; y<3; y++){
                string aux2=Combi4[y];

                if(aux1==aux2){//Si existe combinacion entre L1 y L2(arreglar el caso de dos combinaciones)


                    if((busca(Linea5,L5,Combi5[x])) <= buscarInicio(Linea5,L5) ){

                        MostrarLista(Linea5,busca(Linea5,L5,Combi5[x]),buscarInicio(Linea5,L5),L5);
                        if(buscarFin(Linea4,L4)>busca(Linea4,L4,Combi4[y])){
                            MostrarLista(Linea4,busca(Linea4,L4,Combi4[y]),buscarFin(Linea4,L4),L4);
                        }else{
                            MostrarLista(Linea4,buscarFin(Linea4,L4),busca(Linea4,L4,Combi4[y]),L4);
                        }
                    }else{
                        //cout<< aux1<< endl;
                        MostrarLista(Linea5,buscarInicio(Linea5,L5),busca(Linea5,L5,Combi5[x]),L5);
                        //cout<<buscarFin(Linea4,L4)<<"---"<<Combi4[y]<<busca(Linea4,L4,Combi4[y]) << endl;
                        if(buscarFin(Linea4,L4)<busca(Linea4,L4,Combi4[y])){
                            MostrarLista(Linea4,buscarFin(Linea4,L4),busca(Linea4,L4,Combi4[y]),L4);
                        }else{
                            MostrarLista(Linea4,busca(Linea4,L4,Combi4[y]),buscarFin(Linea4,L4),L4);
                        }
                    }
                }
            }
        }

    }else if (buscarInicio(Linea2,L2)!=-1 and buscarFin(Linea4,L4)!=-1){//cOMBINACION L5 CON L4A
            if(buscarFin(Linea2,L2)){}

    }else if (buscarInicio(Linea5,L5)!=-1 and buscarFin(Linea6,L6)!=-1){//cOMBINACION L5 CON L6
            for(int x=0; x<5; x++){
            string aux1=Combi5[x];
            for(int y=0; y<3; y++){
                string aux2=Combi6[y];
                //cout<<aux1<<"--"<<aux2<<endl;
                if(aux1==aux2){//Si existe combinacion entre L1 y L6(arreglar el caso de dos combinaciones)

                    //cout<<buscarInicio(Linea1,L1)<<"---"<<busca(Linea1,L1,Combi1[x]) << endl;
                    if((busca(Linea5,L5,Combi5[x])) <= buscarInicio(Linea5,L5) ){

                        MostrarLista(Linea5,busca(Linea5,L5,Combi5[x]),buscarInicio(Linea5,L5),L5);
                        if(buscarFin(Linea6,L6)>busca(Linea6,L6,Combi6[y])){
                            MostrarLista(Linea6,busca(Linea6,L6,Combi6[y]),buscarFin(Linea6,L6),L6);
                        }else{
                            MostrarLista(Linea6,buscarFin(Linea6,L6),busca(Linea6,L6,Combi6[y]),L6);
                        }
                    }else{
                        //cout<< aux1<< endl;
                        MostrarLista(Linea5,buscarInicio(Linea5,L5),busca(Linea5,L5,Combi5[x]),L5);
                        //cout<<buscarFin(Linea6,L6)<<"---"<<Combi6[y]<<busca(Linea6,L6,Combi6[y]) << endl;
                        if(buscarFin(Linea6,L6)<busca(Linea6,L6,Combi6[y])){
                            MostrarLista(Linea6,buscarFin(Linea6,L6),busca(Linea6,L6,Combi6[y]),L6);
                        }else{
                            MostrarLista(Linea6,busca(Linea6,L6,Combi6[y]),buscarFin(Linea6,L6),L6);
                        }
                    }
                }
            }
        }

    }else if (buscarInicio(Linea6,L6)!=-1 and buscarFin(Linea1,L1)!=-1){//cOMBINACION L6 CON L1
            for(int x=0; x<3; x++){
            string aux1=Combi6[x];
            for(int y=0; y<5; y++){
                string aux2=Combi1[y];
                //cout<<aux1<<"--"<<aux2<<endl;
                if(aux1==aux2){//Si existe combinacion entre L1 y L6(arreglar el caso de dos combinaciones)

                    //cout<<buscarInicio(Linea1,L1)<<"---"<<busca(Linea1,L1,Combi1[x]) << endl;
                    if((busca(Linea6,L6,Combi6[x])) <= buscarInicio(Linea6,L6) ){

                        MostrarLista(Linea6,busca(Linea6,L6,Combi6[x]),buscarInicio(Linea6,L6),L6);
                        if(buscarFin(Linea1,L1)>busca(Linea1,L1,Combi1[y])){
                            MostrarLista(Linea1,busca(Linea1,L1,Combi1[y]),buscarFin(Linea1,L1),L1);
                        }else{
                            MostrarLista(Linea1,buscarFin(Linea1,L1),busca(Linea1,L1,Combi1[y]),L1);
                        }
                    }else{
                        //cout<< aux1<< endl;
                        MostrarLista(Linea6,buscarInicio(Linea6,L6),busca(Linea6,L6,Combi6[x]),L6);
                        //cout<<buscarFin(Linea6,L6)<<"---"<<Combi6[y]<<busca(Linea6,L6,Combi6[y]) << endl;
                        if(buscarFin(Linea1,L1)<busca(Linea1,L1,Combi1[y])){
                            MostrarLista(Linea1,buscarFin(Linea1,L1),busca(Linea1,L1,Combi1[y]),L1);
                        }else{
                            MostrarLista(Linea1,busca(Linea1,L1,Combi1[y]),buscarFin(Linea1,L1),L1);
                        }
                    }
                }
            }
        }

    }else if (buscarInicio(Linea6,L6)!=-1 and buscarFin(Linea2,L2)!=-1){//cOMBINACION L6 CON L2
            for(int x=0; x<3; x++){
            string aux1=Combi6[x];
            for(int y=0; y<4; y++){
                string aux2=Combi2[y];

                if(aux1==aux2){//Si existe combinacion entre L1 y L2(arreglar el caso de dos combinaciones)


                    if((busca(Linea6,L6,Combi6[x])) < buscarInicio(Linea6,L6) ){
                        MostrarLista(Linea6,busca(Linea6,L6,Combi6[x]),buscarInicio(Linea6,L6),L6);
                        if(buscarFin(Linea2,L2)>busca(Linea2,L2,Combi2[y])){
                            MostrarLista(Linea2,busca(Linea2,L2,Combi2[y]),buscarFin(Linea2,L2),L2);
                        }else{
                            MostrarLista(Linea2,buscarFin(Linea2,L2),busca(Linea2,L2,Combi2[y]),L2);
                        }
                    }else{
                        MostrarLista(Linea6,buscarInicio(Linea6,L6),busca(Linea6,L6,Combi6[x]),L6);
                        if(buscarFin(Linea2,L2)>busca(Linea2,L2,Combi2[y])){
                            MostrarLista(Linea2,buscarFin(Linea2,L2),busca(Linea2,L2,Combi2[y]),L2);
                        }else{
                            MostrarLista(Linea2,busca(Linea2,L2,Combi2[y]),buscarFin(Linea2,L2),L2);
                        }
                    }
                }
            }
        }

    }else if (buscarInicio(Linea6,L6)!=-1 and buscarFin(Linea4,L4)!=-1){//cOMBINACION L6 CON L4
            for(int x=0; x<3; x++){
            string aux1=Combi6[x];
            for(int y=0; y<3; y++){
                string aux2=Combi4[y];

                if(aux1==aux2){//Si existe combinacion entre L1 y L2(arreglar el caso de dos combinaciones)


                    if((busca(Linea6,L6,Combi6[x])) <= buscarInicio(Linea6,L6) ){

                        MostrarLista(Linea6,busca(Linea6,L6,Combi6[x]),buscarInicio(Linea6,L6),L6);
                        if(buscarFin(Linea4,L4)>busca(Linea4,L4,Combi4[y])){
                            MostrarLista(Linea4,busca(Linea4,L4,Combi4[y]),buscarFin(Linea4,L4),L4);
                        }else{
                            MostrarLista(Linea4,buscarFin(Linea4,L4),busca(Linea4,L4,Combi4[y]),L4);
                        }
                    }else{
                        //cout<< aux1<< endl;
                        MostrarLista(Linea6,buscarInicio(Linea6,L6),busca(Linea6,L6,Combi6[x]),L6);
                        //cout<<buscarFin(Linea4,L4)<<"---"<<Combi4[y]<<busca(Linea4,L4,Combi4[y]) << endl;
                        if(buscarFin(Linea4,L4)<busca(Linea4,L4,Combi4[y])){
                            MostrarLista(Linea4,buscarFin(Linea4,L4),busca(Linea4,L4,Combi4[y]),L4);
                        }else{
                            MostrarLista(Linea4,busca(Linea4,L4,Combi4[y]),buscarFin(Linea4,L4),L4);
                        }
                    }
                }
            }
        }

    }else if (buscarInicio(Linea2,L2)!=-1 and buscarFin(Linea4,L4)!=-1){//cOMBINACION L6 CON L4A
            if(buscarFin(Linea2,L2)){}

    }else if (buscarInicio(Linea6,L6)!=-1 and buscarFin(Linea5,L5)!=-1){//cOMBINACION L6 CON L5
            for(int x=0; x<3; x++){
            string aux1=Combi6[x];
            for(int y=0; y<5; y++){
                string aux2=Combi5[y];

                if(aux1==aux2){//Si existe combinacion entre L1 y L5(arreglar el caso de dos combinaciones)


                    if((busca(Linea6,L6,Combi6[x])) <= buscarInicio(Linea6,L6) ){

                        MostrarLista(Linea6,busca(Linea6,L6,Combi6[x]),buscarInicio(Linea6,L6),L6);
                        if(buscarFin(Linea5,L5)>busca(Linea5,L5,Combi5[y])){
                            MostrarLista(Linea5,busca(Linea5,L5,Combi5[y]),buscarFin(Linea5,L5),L5);
                        }else{
                            MostrarLista(Linea5,buscarFin(Linea5,L5),busca(Linea5,L5,Combi5[y]),L5);
                        }
                    }else{
                        //cout<< aux1<< endl;
                        MostrarLista(Linea6,buscarInicio(Linea6,L6),busca(Linea6,L6,Combi6[x]),L6);
                        //cout<<buscarFin(Linea5,L5)<<"---"<<Combi5[y]<<busca(Linea5,L5,Combi5[y]) << endl;
                        if(buscarFin(Linea5,L5)<busca(Linea5,L5,Combi5[y])){
                            MostrarLista(Linea5,buscarFin(Linea5,L5),busca(Linea5,L5,Combi5[y]),L5);
                        }else{
                            MostrarLista(Linea5,busca(Linea5,L5,Combi5[y]),buscarFin(Linea5,L5),L5);
                        }
                    }
                }
            }
        }

    }
   return 0;}
}
int busca(Lista lista,string linea[100],string palabra){
    pNodo nodo = lista;

    if(ListaVacia(lista)) printf("Lista vacía\n");
    else {
        while(nodo) {
            string aux=linea[nodo->valor];
            //cout << aux << palabra << endl;
            if(aux==palabra){
                return nodo->valor;
            }else{
                nodo = nodo->siguiente;
            }

        }
        return -1;
   }
}


int buscarInicio(Lista lista,string linea[100]){
    pNodo nodo = lista;

    if(ListaVacia(lista)) printf("Lista vacía\n");
    else {
        while(nodo) {
            string aux=linea[nodo->valor];
            //cout << aux << Inicio << endl;
            if(aux==Inicio){
                return nodo->valor;
            }else{
                nodo = nodo->siguiente;
            }

        }
        return -1;
   }
}
int buscarCamino(Lista lista,string linea[50],int prueba){
    pNodo nodo = lista;
    if(ListaVacia(lista)) printf("Lista vacía\n");
    else {
        while(nodo) {
            string aux=linea[nodo->valor];
            nodo = nodo->siguiente;
        }
        return -1;
   }
}


int buscarFin(Lista lista,string linea[50]){
    pNodo nodo = lista;
    if(ListaVacia(lista)) printf("Lista vacía\n");
    else {
        while(nodo) {
                string aux=linea[nodo->valor];
                //cout << aux << Destino << endl;
            if(aux==Destino){
                return nodo->valor;
            }else{
               nodo = nodo->siguiente;
            }

        }
        return -1;
   }
}



void Insertar(Lista *lista, int v) {
   pNodo nuevo, anterior;

   /* Crear un nodo nuevo */
   nuevo = (pNodo)malloc(sizeof(tipoNodo));
   nuevo->valor = v;

   /* Si la lista está vacía */
   if(ListaVacia(*lista) || (*lista)->valor > v) {
      /* Añadimos la lista a continuación del nuevo nodo */
      nuevo->siguiente = *lista;
      /* Ahora, el comienzo de nuestra lista es en nuevo nodo */
      *lista = nuevo;
   } else {
      /* Buscar el nodo de valor menor a v */
      anterior = *lista;
      /* Avanzamos hasta el último elemento o hasta que el siguiente tenga
         un valor mayor que v */
      while(anterior->siguiente && anterior->siguiente->valor <= v)
         anterior = anterior->siguiente;
      /* Insertamos el nuevo nodo después del nodo anterior */
      nuevo->siguiente = anterior->siguiente;
      anterior->siguiente = nuevo;
   }
}

void Borrar(Lista *lista, int v) {
   pNodo anterior, nodo;

   nodo = *lista;
   anterior = NULL;
   while(nodo && nodo->valor < v) {
      anterior = nodo;
      nodo = nodo->siguiente;
   }
   if(!nodo || nodo->valor != v) return;
   else { /* Borrar el nodo */
      if(!anterior) /* Primer elemento */
         *lista = nodo->siguiente;
      else  /* un elemento cualquiera */
         anterior->siguiente = nodo->siguiente;
      free(nodo);
   }
}

int ListaVacia(Lista lista) {
   return (lista == NULL);
}

void BorrarLista(Lista *lista) {
   pNodo nodo;

   while(*lista) {
      nodo = *lista;
      *lista = nodo->siguiente;
      free(nodo);
   }
}

void MostrarLista(Lista lista,int inicio,int fin,string linea[50]) {
   pNodo nodo = lista;
   int var=100;
   if(ListaVacia(lista)) printf("Lista vacía\n");
   else {
      while(nodo) {
            if(inicio==nodo->valor){
                var=0;
            }
            if(var<=(fin-inicio)){
                cout << linea[nodo->valor]<<"->";
                var++;
            }
            nodo = nodo->siguiente;
     }
     printf("Destino\n");
   }
}
