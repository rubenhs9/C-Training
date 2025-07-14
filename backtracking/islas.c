#include <stdlib.h>
#include "funciones.h"

void explorar(char mapa[FILA][COLUMNA], int filas, int columnas, int i, int j);
int contarIslas(char mapa[FILA][COLUMNA], int filas, int columnas){
    int contador = 0;

    for(int i=0;i<filas;i++){
        for(int j=0;j<columnas;j++){
            if(mapa[i][j] == '1'){
                contador += 1;
                explorar(mapa, filas, columnas, i, j);
            }
        }
    }

    return contador;

}


void explorar(char mapa[FILA][COLUMNA], int filas, int columnas, int i, int j){

    if (i < 0 || i >= filas || j < 0 || j >= columnas) {
        return;
    }

    if(mapa[i][j] != '1'){
        return;
    }

    mapa[i][j] = 'x';

    explorar(mapa,filas,columnas,i+1, j); //abajo
    explorar(mapa,filas,columnas,i-1, j); //arriba
    explorar(mapa,filas,columnas,i,j+1); //derecha
    explorar(mapa,filas,columnas,i,j-1); //izquierda
}

