#include <iostream>
#include <string.h>
#include <stdlib.h>
#include <stdio.h>

using namespace std;

void Crear_Matriz(int** Matriz){
    int valor;
    for(int i=0;i<107;i++){
        for(int j=0;j<107;j++){
            if(i == 0 or i==27 or i==48 or i==70 or i==74 or i==100){//Evita Conecciones entre diferentes Lineas
                if(j-i==1){
                    Matriz[i][j]=1;
                }else{
                    Matriz[i][j]=0;
                }
            }else if(i == 26 or i==47 or i==69 or i==73 or i==99 or i==106){//Evita Conecciones entre diferentes Lineas
                if(i-j==1){
                    Matriz[i][j]=1;
                }else{
                    Matriz[i][j]=0;
                }
            }else if(0<i<26){//Conectando estaciones de Linea 1
                if((j-i==1) or (i-j==1)){
                    //cout << "hola";
                    Matriz[i][j]=1;
                }else{
                    Matriz[i][j]=0;
                }

            }else if(27<i<47){//Conectando estaciones de Linea 2
                if((j-i==1) or (i-j==1)){
                    Matriz[i][j]=1;
                }else{
                    Matriz[i][j]=0;
                }
            }else if((48<i<69) ){//Conectando estaciones de Linea 4
                if((j-i==1) or (i-j==1)){
                    Matriz[i][j]=1;
                }else{
                    Matriz[i][j]=0;
                }
            }else if((70<i<73) ){//Conectando estaciones de Linea 4A
                if((j-i==1) or (i-j==1)){
                    Matriz[i][j]=1;
                }else{
                    Matriz[i][j]=0;
                }
            }else if((74<i<99) ){//Conectando estaciones de linea 5
                if((j-i==1) or (i-j==1)){
                    Matriz[i][j]=1;
                }else{
                    Matriz[i][j]=0;
                }
            }else if((100<i<106) ){//Conectando estaciones de Linea 6
                if((j-i==1) or (i-j==1)){
                    Matriz[i][j]=1;
                }else{
                    Matriz[i][j]=0;
                }
            }else{
                Matriz[i][j]=0;
            }
        }
    }


    for(int i=0;i<107;i++){
        for(int j=0;j<107;j++){
            if((i==0 and j==81) or (j==0 and i==81)){//Uniendo San Pablo con Pudahuel
                Matriz[i][j]=1;
            }else if((i==0 and j==82) or (j==0 and i==82)){//Uniendo San Pablo con Lo Prado
                Matriz[i][j]=1;
            }else if((i==10 and j==35) or (j==10 and i==35)){//Uniendo Los Heroes con Santa Ana
                Matriz[i][j]=1;
            }else if((i==10 and j==36) or (j==10 and i==36)){//Uniendo Los Heroe con Toesca
                Matriz[i][j]=1;
            }else if((i==15 and j==88) or (j==15 and i==88)){//Uniendo Baquedano con Bellas Artes
                Matriz[i][j]=1;
            }else if((i==15 and j==89) or (j==15 and i==89)){//Uniendo Baquedano con Parque Bustamante
                Matriz[i][j]=1;
            }else if((i==19 and j==106) or (j==19 and i==106)){//Uniendo Los Leones con Ines de Suarez
                Matriz[i][j]=1;
            }else if((i==20 and j==48) or (j==20 and i==48)){//Uniendo Tobalaba con Cristobal Colon
                Matriz[i][j]=1;
            }else if((i==35 and j==86) or (j==35 and i==86)){//Uniendo Santa Ana con Cumming
                Matriz[i][j]=1;
            }else if((i==35 and j==87) or (j==35 and i==87)){//Uniendo Santa Ana con Plaza de Armas
                Matriz[i][j]=1;
            }else if((i==39 and j==102) or (j==39 and i==102)){//Uniendo Franklin con Presidente Pedro Aguirre Cerda
                Matriz[i][j]=1;
            }else if((i==39 and j==103) or (j==39 and i==103)){//Uniendo Franklin con Bio Bio
                Matriz[i][j]=1;
            }else if((i==47 and j==73) or (j==47 and i==73)){//Uniendo La Cisterna con San Ramon
                Matriz[i][j]=1;
            }else if((i==59 and j==70) or (j==59 and i==70)){//Uniendo Vicuna Mackenna con Santa Julia
                Matriz[i][j]=1;
            }else if((i==60 and j==99) or (j==60 and i==99)){//Uniendo Vicente Valdes con Bellavista de La Florida
                Matriz[i][j]=1;
            }else if((i==92 and j==103) or (j==92 and i==103)){//Uniendo Nuble con Bio Bio
                Matriz[i][j]=1;
            }else if((i==92 and j==104) or (j==92 and i==104)){//Uniendo Nuble con Estadio Nacional
                Matriz[i][j]=1;
            }else if((i==88 and j==89) or (j==88 and i==89)){//Separando estaciones contiguas qeu no se conectan como Bellas artes y Busta
                Matriz[i][j]=0;
            }else if((i==81 and j==82) or (j==81 and i==82)){// Separando Pudahuel y Lo Prado
                Matriz[i][j]=0;
            }else if((i==35 and j==36) or (j==35 and i==36)){//Separando Santa Ana y Toesca
                Matriz[i][j]=0;
            }else if((i==86 and j==87) or (j==86 and i==87)){//Separando Cumming y Plaza de Armas
                Matriz[i][j]=0;
            }else if((i==102 and j==103) or (j==102 and i==103)){//Separando Presidente Pedro Aguirre Cerda y Bio Bio
                Matriz[i][j]=0;
            }else if((i==103 and j==104) or (j==103 and i==104)){//Separando Bio Bio y Estadio Nacional
                Matriz[i][j]=0;
            }
        }
    }

}


void Mostrar_Matriz(int** Matriz){
    for(int i=0;i<70;i++){
        for(int j=0;j<70;j++){
            cout << Matriz[i][j];
        }
        cout << endl;
    }
}


