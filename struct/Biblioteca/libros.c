#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#include "libros.h"


Libro* registrarLibros(int* n){
    printf("�Cuantos libros va a registrar ?");
    scanf("%d", n);
    getchar();

    Libro* libros = (Libro*) malloc((*n)*sizeof(Libro));
    if(libros == NULL){
        printf("Error al reservar memoria.\n");
        return NULL;
    }

    for(int i=0;i<*n;i++){
        printf("Libro %d\n", i + 1);

        printf("Titulo: ");
        fgets(libros[i].titulo, sizeof(libros[i].titulo),stdin);
        libros[i].titulo[strcspn(libros[i].titulo, "\n")] = 0;

        printf("Autor: ");
        fgets(libros[i].autor, sizeof(libros[i].autor),stdin);
        libros[i].autor[strcspn(libros[i].autor, "\n")] = 0;

        printf("A�o: ");
        scanf("%d", &libros[i].anio);
        getchar();
    }

    return libros;
}

void mostrarLibrosRecientes(Libro* libros, int n){
    printf("\nLibros posteriores al a�o 2000:\n");
    int encontrados = 0;
    for(int i=0;i<n;i++){
        if(libros[i].anio>2000){
            printf("%d| %s (%d) - %s\n", i+1 ,libros[i].titulo, libros[i].anio, libros[i].autor);
            encontrados++;
        }
   }
    if (encontrados == 0) {
        printf("Ning�n libro registrado es posterior al a�o 2000.\n");
    }
}
