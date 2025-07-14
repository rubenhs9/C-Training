#include <stdlib.h>
#include <stdio.h>
#include "funciones.h"

int main(){

   //reservarNEnteros();
   //guardarLiberarN();
/* 
   int n = 5;

   int* numeros = crearArray(n);

   if (numeros == NULL)
   {
    printf("Error al reservar memoria");
    return 1;
   }
   
   printf("Contenido del array:\n");
    for (int i = 0; i < n; i++) {
        printf("%d ", numeros[i]);
    }
    printf("\n");

    // Libera la memoria
    free(numeros);
    return 0; */

    int n = 5;
    int* array = (int*) malloc(n * sizeof(int));
    if (array == NULL) {
        printf("Error al reservar memoria.\n");
        return 1;
    }

    // Inicializar array original
    for (int i = 0; i < n; i++) {
        array[i] = i + 1;
    }

    int* duplicado = duplicarArray(array, n);
    if (duplicado == NULL) {
        printf("Error al reservar memoria para duplicado.\n");
        free(array);
        return 1;
    }
     
    printf("Array Original");
    for (int i = 0; i < n; i++)
    {
        printf("\n%d", array[i]);
    }
    
    printf("\nArray Duplicado");
    for (int i = 0; i < n; i++)
    {
        printf("\n%d", duplicado[i]);
    }
    free(array);

}
