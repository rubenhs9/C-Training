#ifndef FUNCIONES_H
#define FUNCIONES_H

#define FILA 4
#define COLUMNA 4

int realizarCaminoCorto(int m[FILA][COLUMNA], int fila, int columna,int iOrigen, int iDestino, int jOrigen, int jDestino);
int contarCaminos(int matriz[FILA][COLUMNA], int i, int j, int iDest, int jDest);
int calcularZonaConectadas0(int m[FILA][COLUMNA], int filas, int columnas);
int contarIslas(char mapa[FILA][COLUMNA], int filas, int columnas);

#endif