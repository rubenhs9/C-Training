#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#include "libros.h"


void registrarLibros(Libro* libros, int n){
    for(int i=0;i<n;i++){
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
}

void mostrarLibrosRecientes(Libro* libros, int n){

    for(int i=0;i<n;i++){
        if(libros[i].anio>2000){
            printf("%s (%d) - %s\n", libros[i].titulo, libros[i].anio, libros[i].autor);
        }
   }

}
