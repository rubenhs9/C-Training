#include <stdlib.h>
#include <stdio.h>
#include "funciones.h"



void identificarZona(int mapa[FILA][COLUMNA], int filas, int columnas, int i, int j);
int calcularZonaConectadas0(int m[FILA][COLUMNA], int filas, int columnas);


int calcularZonaConectadas0(int m[FILA][COLUMNA], int filas, int columnas){

    int sector = 0;
    for(int i=0;i<filas;i++){

        for(int j=0;j<columnas;j++){
            if(m[i][j] == 0){
                sector += 1;
                identificarZona(m,filas,columnas,i,j);
            }
        }
    }

    return sector;
}

void identificarZona(int m[FILA][COLUMNA], int filas, int columnas, int i, int j){
    if(i<0 || i >=filas || j<0 || j>= columnas){
        return;
    }

    if(m[i][j] != 0){
        return;
    }

    m[i][j] = -1;

    identificarZona(m,filas,columnas,i-1,j); //arriba
    identificarZona(m,filas,columnas,i+1,j); //abajo
    identificarZona(m,filas,columnas,i,j-1);//izquierda
    identificarZona(m,filas,columnas,i,j+1); //derecha
}

