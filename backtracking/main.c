#include <stdio.h>
#include <stdlib.h>
#include "funciones.h"

int main(){

    int iOrigen = 0;
    int jOrigen = 0; 
    int iDestino = 3;
    int jDestino = 3;

    int matriz[4][4] = {
        {0,0,0,0},
        {1,0,1,0},
        {1,0,0,0}, 
        {0,1,1,0}
    };

    int resultado = contarCaminos(matriz,0,0,3,3);
    printf("El numero de caminos que hay es: %d\n", resultado);

    return 0;


}    