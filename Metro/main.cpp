#include <iostream>
#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include <mpi.h>


#include "Header.h"


using namespace std;

string L1[]={"San Pablo","Neptuno","Pajaritos","Las Rejas","Ecuador","San Alberto Hurtado","Universidad de Santiago"
            ,"Estacion Central","Union Latinoamericana","Republica","Los Heroes","La Moneda","Universidad de Chile"
            ,"Santa Lucia","Universidad Catolica","Baquedano","Salvador","Manuel Montt","Pedro de Valdivia"
            ,"Los Leones","Tobalaba","El Golf","Alcantara","Escuela Militar","Manquehue","Hernando de Magallanes"
            ,"Los Dominicos","Vespucio Norte","Zapadores","Dorsal","Einstein","Cementerios"
            ,"Cerro Blanco","Patronato","Puente Cal y Canto","Santa Ana","Toesca","Parque OHiggins","Rondizzoni"
            ,"Franklin","El Llano","San Miguel","Lo Vial","Departamental","Ciudad del Nino","Lo Ovalle","El Parron"
            ,"La Cisterna","Cristobal Colon","Francisco Bilbao","Principe de Gales","Simon Bolivar","Plaza Egana"
            ,"Los Orientales","Grecia","Los Precidentes","Quilin","Las Torres","Macul","Vicuña Mackenna"
            ,"Vicente Valdes","Rojas Magallanes","Trinidad","San Jose de la Estrella","Los Quillayes","Elisa Correa"
            ,"Hospital Sotero del Rio","Protectora de la Infancia","Las Mercedes","Plaza de Puente Alto"
            ,"Santa Julia","La Granja","Santa Rosa","San Ramon","Plaza de Maipu","Santiago Bueras","Del Sol"
            ,"Monte Tabor","Las Parcelas","Laguna Sur","Barrancas","Pudahuel","Lo Prado","Blanqueado"
            ,"Gruta de Lourdes","Quinta Normal","Cumming","Plaza de Armas","Bellas Artes","Parque Bustamante"
            ,"Santa Isabel","Irarrazaval","Nuble","Rodrigo de Araya","Carlos Valdovinos","Camino Agricola"
            ,"San Joaquin","Pedrero","Mirador","Bellavista de La Florida","Cerrillos","Lo Valledor"
            ,"Presidente Pedro Aguirre Cerda","Bio Bio","Estadio Nacional","Nunoa","Ines de Suares"};

string Estaciones_Codigo[]={"SP","NP","PJ","LR","EC","AH","US","EL","LA","RP","LH","LM","CH","SL","UC","BA","SA","MM"
                        ,"PV","LE","TB","GO","AL","EM","MQ","HM","LD","AV","ZA","DO","EI","CE","CB","PT","CA","AN"
                        ,"TO","PQ","RO","FR","LL","SM","LV","DE","CN","LO","EP","LC","COL","BIL","PDG","SBO","PEG"
                        ,"LOR","RGR","LPR","RQU","LTO","MAC","VMA","VVA","RMA","TRI","SJE","LQU","ECO","HSR","PIN"
                        ,"LME","PPA","SJU","LGR","SRO","SRA","PM","SB","DS","MT","LP","LS","BR","PU","PR","BL","GL"
                        ,"QN","RC","PZ","BE","PB","SI","IR","NU","RA","CV","AG","SJ","PE","MA","LF","CER","LVA","PAC"
                        ,"BIO","ENS","NUO","ISU"};

void Crear_Matriz(int** Matriz);
void Mostrar_Matriz(int** Matriz);
void dijkstra( int N, int **A, int a, int b,string L[106],int argc,char *argv[] );

#include <iostream>
#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include <mpi.h>
#include <cstring>

#include "Header.h"


using namespace std;

int main(int argc,char *argv[]){

    int** Metro;
    int filas = 107, columnas = 107;   /*Supongamos esos valores*/
    Metro = (int **)malloc(filas * sizeof(int *));

    for(int i = 0; i < columnas; i++){
        Metro[i] = (int *)malloc(columnas * sizeof(int));
    }
    int intento=0,j,k,s;
    char *ptr;
    char opcion[100];
    do{
        cout << "CONTROL COMPUTACION PARALELA Y DISTRIBUIDA" << endl;
        cout <<"============================================"<<endl;
        cout <<" Opcion 1 "<< endl;
        cout << " -f 'codigo estacion origen' 'codigo estacion destino', para calcular ruta minima entre dos estaciones"<<endl;
        cout << endl;
        cout << " Opcion 2" << endl;
        cout << " -v, que muestra los integrantes del grupo con sus datos" << endl;
        cout <<"============================================"<<endl;
        cout << endl;
        /*cout << " Opcion 3" << endl;
        cout << " -l, ver estaciones" << endl;
        cout <<"============================================"<<endl;
        cout << endl;
        cout << " Opcion 4" << endl;
        cout << " -s, Salir" << endl;
        cout <<"============================================"<<endl;
        cout << endl;*/
        cout << "Ingrese opcion bajo el formato especificado: ";
        cin.getline(opcion,100);

        //char* y=opcion;
        ptr = strtok(opcion," ");//argumentos: frase, caracter delimitador
        while(ptr != NULL)
        {
            //cout << ptr<<endl;
            string local=ptr;
            //cout << local << endl;
            //if(intento==)
            if(intento == 2)
                {
                    for(int i=0;i<107;i++)
                    {
                        cout << local<<"-"<<Estaciones_Codigo[i]<<"-"<<intento << endl;
                        if(local==Estaciones_Codigo[i] )
                            {
                                k=i;
                                intento++;
                            }
                    }
                    if (intento == 2) intento = 5;
                }else if(intento ==1)
                    {
                        for(int i=0;i<107;i++)
                            {

                                if(local==Estaciones_Codigo[i] )
                                    {
                                        intento++;
                                        j=i;
                                    }
                            }
                        if (intento ==1) intento = 5;
                    }else if(intento == 0)
            {
                if(local=="-s")
                    {
                        intento=-3;
                        break;
                    }
                else if(local=="-v")
                    {
                        intento=-1;
                        break;
                    }
                else if(local== "-l")
                    {
                        intento=-2;
                        break;
                    }
                else if(local== "-f")
                    {
                        intento++;
                    }else
                        {break;}
            }else break;
            ptr = strtok(NULL, " ");
            //intento++;
            //cout << ptr << endl;

        }

        if (intento == 3)
            {
                system("cls");
                Crear_Matriz(Metro);
                //Mostrar_Matriz(Metro);
                dijkstra(107,Metro,j,k,L1,argc,argv);//si cumple todos los requisitos entonces pasa a la ejecucucion
                system("pause");
                system("cls");
                break;



            }else if(intento == -1)
            {

            cout <<endl;
            cout << "Integrantes: " <<endl;
            cout << "- Felipe Reyes Gutierrez" << endl;
            cout << "- Fabian Araya Leon"<<endl;
            cout << "- Nelson Roa Inostroza" << endl;
            return 0;

            }else if(intento == 2)
            {
                cout << "La estacion de destino es incorrecta" << endl;
                intento=0;
                system("pause");
                system("cls");

        }else if(intento == 1){
            cout << "La estacion de partida es incorrecta" << endl;
            intento=0;
            system("pause");
            system("cls");

        }else if(intento == 0){
            cout << "La primera expresion es incorrecta" << endl;
            intento=0;
            system("pause");
            system("cls");
        }
        else if(intento == -2){
            intento=0;

        }else{
            cout << "Escriba un comando correcto" << endl;
            intento=0;

            system("pause");
            system("cls");
        }
        //system("pause");

        //system("cls");
    }while(s!=-3);
        //cout << "LA FRASE DESPUES: " << frase << endl;

    return 0;

}
