#include <stdlib.h>
#include <stdio.h>
#define FILA 4
#define COLUMNA 4

int realizarCaminoCorto(int m[FILA][COLUMNA], int fila, int columna,int iOrigen, int iDestino, int jOrigen, int jDestino);
static void comprobarCaminos(int m[FILA][COLUMNA], int fila, int columna,int i, int j,int iDestino,int jDestino, int pasos);

int minPasos;

int realizarCaminoCorto(int m[FILA][COLUMNA], int fila, int columna,int iOrigen, int iDestino, int jOrigen, int jDestino){
    minPasos = 9999;
    
    comprobarCaminos(m, fila, columna, iOrigen, jOrigen, iDestino, jDestino, 0);
    return minPasos;
}

static void comprobarCaminos(int m[FILA][COLUMNA], int fila, int columna,int i, int j,int iDestino,int jDestino, int pasos){
    
    if (i < 0 || i >= fila || j < 0 || j >= columna)
    {
        return;
    }

    if (m[i][j] != 0)
    {
        return;
    }

    
    if (i == iDestino && j == jDestino) {
        if (pasos < minPasos) {
            minPasos = pasos;
        }
        return;
    }

    m[i][j] = 2;

    pasos++;

    comprobarCaminos(m,fila,columna,i+1,j,iDestino,jDestino,pasos); //abajo
    comprobarCaminos(m,fila,columna,i-1,j,iDestino,jDestino,pasos); //arriba
    comprobarCaminos(m,fila,columna,i,j-1,iDestino,jDestino,pasos); //izquierda
    comprobarCaminos(m,fila,columna,i,j+1,iDestino,jDestino,pasos); //derecha
   
    printf("Saliendo de (%d,%d), restaurando a 0\n", i, j);
    m[i][j] = 0;
    printf("Saliendo de (%d,%d), restaurando a 0\n", i, j);
}