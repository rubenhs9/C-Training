#include <stdlib.h>
#include <stdio.h>
#include "funciones.h"

/*
Matriz de ejemplo:
{0, 0, 0},
{0, 1, 0},
{0, 0, 0}

Origen: (0, 0)
Destino: (2, 2)

*/

int contarCaminos(int matriz[FILA][COLUMNA], int i, int j, int iDest, int jDest){

    if (i < 0 || i >= FILA || j < 0 || j >= COLUMNA) return 0;
    if (matriz[i][j] != 0) return 0;

    if (i == iDest && j == jDest) return 1;

    matriz[i][j] = 2;

    int caminos = 0;
    caminos += contarCaminos(matriz, i + 1, j, iDest, jDest); // Abajo
    caminos += contarCaminos(matriz, i - 1, j, iDest, jDest); // Arriba
    caminos += contarCaminos(matriz, i, j + 1, iDest, jDest); // Derecha
    caminos += contarCaminos(matriz, i, j - 1, iDest, jDest); // Izquierda


    matriz[i][j] = 0;

    return caminos;
        
}




