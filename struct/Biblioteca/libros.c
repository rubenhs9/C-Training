#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#include "libros.h"


Libro* registrarLibros(int* n){
    printf("¿Cuantos libros va a registrar ?");
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

        printf("Año: ");
        scanf("%d", &libros[i].anio);
        getchar();
    }

    return libros;
}

void mostrarLibrosRecientes(Libro* libros, int n){
    printf("\nLibros posteriores al año 2000:\n");
    int encontrados = 0;
    for(int i=0;i<n;i++){
        if(libros[i].anio>2000){
            printf("%d| %s (%d) - %s\n", i+1 ,libros[i].titulo, libros[i].anio, libros[i].autor);
            encontrados++;
        }
   }
    if (encontrados == 0) {
        printf("Ningún libro registrado es posterior al año 2000.\n");
    }
}

void eliminarLibro(Libro* libros, int* n) {
    //Funcion sin realloc
    if (*n == 0) {
        printf("No hay libros para borrar.\n");
        return;
    }

    mostrarLibrosRecientes(libros, *n);

    int opcion;
    printf("Selecciona el número del libro que deseas borrar: ");
    scanf("%d", &opcion);

    if (opcion < 1 || opcion > *n) {
        printf("Opción inválida.\n");
        return;
    }

    int pos = opcion - 1;

    if (pos == *n - 1) {
        (*n)--;
    } else {
        for (int i = pos; i < *n - 1; i++) {
            libros[i] = libros[i + 1];
        }
        (*n)--;
    }

    printf("Libro eliminado correctamente.\n");

    mostrarLibrosRecientes(libros, *n);


    return;
}
