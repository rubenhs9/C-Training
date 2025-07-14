#include <stdlib.h>
#include <stdio.h>
#include "funciones.h"



void reservarNEnteros(){
    int n;
    printf("¿Cuantos numeros quieres guardar de manera dinamica ");
    scanf("%d", &n);

    int* numeros = (int*) malloc(n*sizeof(int));

    if (numeros == NULL)
    {
        printf("Error al reservar memoria");
        return;
    }


    for (int i = 0; i < n; i++)
    {
        printf("Introduce numero %d: ", i + 1);
        scanf("%d", &numeros[i]);

    }

    printf("Numeros introducidos: ");
    for (int i = 0; i < n; i++)
    {
        printf("%d", numeros[i]);
    }
    printf("\n");

    free(numeros);
      
}
