#include <stdlib.h>
#include <stdio.h>
#include "funciones.h"


void guardarLiberarN(){
    int n;
    printf("¿Cuantos numeros desea guardar?");
    scanf("%d", &n);

    int* numeros = (int*) malloc (n*sizeof(int)); // Esto vive en el stack, cuando se acaba el metodo se elimina automaticamente


    int array[n]; // Esto vive en el heap. Perdura aunque se acabe el metodo y puedes retornarlo.

    
    for (int i = 0; i < n; i++)
    {
        printf("Introduce el numero %d", i+1);
        scanf("%d", &array[i]);    
    }
    

    printf("Numeros introducidos");
     for (int i = 0; i < n; i++)
    {
        printf("%d", array[i]);
    }
}

int* crearArray(int n){
    int* numeros = (int*) malloc (n*sizeof(int));
    if (numeros == NULL) {
        return NULL;
    }

    for (int i = 0; i < n; i++) {
        numeros[i] = i + 1;
    }

    return numeros; //1º dir del array

}

int* duplicarArray(int* array, int n){

    int* arrayD = (int*) malloc (n*sizeof(int));
    if (arrayD == NULL) {
        return NULL;
    }

    for (int i = 0; i < n; i++)
    {
        arrayD[i] =  array[i]*2;
    }
    
    return arrayD;

}