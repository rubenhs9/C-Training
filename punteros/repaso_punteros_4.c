#include <stdlib.h>
#include "funciones.h"

void mostrarArray(int *arr, int tam){
    int *p = arr;
    for(int i = 0; i < 4; i++) {
        printf("\n%d", *p);
        p++;
    }
}

void doblar(int *arr, int tam) {

    int *p = arr;
    for (int i = 0; i < tam; i++) {
//  printf("%d\n", *p*3); Asi no se modifica el valor del array, solo multiplicas el valor original por 3
        *p *= 3; //Asi si modificamos el contenido del array.
        p++;
    }
}

void copiarArray (int *arr1, int *arr2, int tam){
    int *p = arr1;
    int *p2 = arr2;


    printf("Segundo Array:\n");
    for(int i=0;i<tam;i++){
        *p2 = *p;
        printf("%d\n",*p2);
        p++;
        p2++;
    }

    p = arr1; // Volvemos a apuntar al primer elemento del array para que no aparezca la garbage de la memoria.
    printf("Primer Array:\n");
    for(int k=0;k<tam;k++){
        printf("%d\n",*p);
        p++;
    }


    printf("Datos copiados correctamente");
}


