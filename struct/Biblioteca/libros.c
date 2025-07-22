#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#include "libros.h"


void registrarLibros(Libro** libros, int* n){
    int nuevos;
    printf("¿Cuantos libros va a registrar ?");
    scanf("%d", &nuevos);
    getchar();

    Libro* temp = realloc(*libros, (*n + nuevos) * sizeof(Libro));
    if(temp == NULL){
        printf("Error al reservar memoria.\n");
        return;
    }

    *libros = temp;

    for(int i=0;i<nuevos;i++){
        printf("\nLibro %d\n", *n + 1);

        printf("Título: ");
        fgets((*libros)[*n].titulo, sizeof((*libros)[*n].titulo), stdin);
        (*libros)[*n].titulo[strcspn((*libros)[*n].titulo, "\n")] = 0;

        printf("Autor: ");
        fgets((*libros)[*n].autor, sizeof((*libros)[*n].autor), stdin);
        (*libros)[*n].autor[strcspn((*libros)[*n].autor, "\n")] = 0;

        printf("Año: ");
        scanf("%d", &(*libros)[*n].anio);
        getchar();

        (*n)++;
    }

}

void mostrarLibrosRecientes(Libro* libros, int n){

    if (n == 0) {
        printf("Ningún libro registrado.\n");
    }

    for(int i=0;i<n;i++){
        printf("%d| %s (%d) - %s\n", i+1 ,libros[i].titulo, libros[i].anio, libros[i].autor);

    }

}

void eliminarLibro(Libro** libros, int* n) {

    if (*n == 0) {
        printf("No hay libros para borrar.\n");
        return;
    }

    mostrarLibrosRecientes(*libros, *n);

    int opcion;
    printf("Selecciona el número del libro que deseas borrar: ");
    scanf("%d", &opcion);

    if (opcion < 1 || opcion > *n) {
        printf("Opción inválida.\n");
        return;
    }

    int pos = opcion - 1;
    //Funcion con realloc (RECOMENDADO), dado que reajusta el espacio en memoria, no solo borra el valor como se hace sin realloc. Mas óptimo
    if (pos == *n - 1) {
        (*n)--;
    } else {
        for (int i = pos; i < *n - 1; i++) {
            (*libros)[i] = (*libros)[i + 1];
        }
        (*n)--;
    }

    //Aqui debemos de hacer realloc para redimensionar la memoria y hacer que nuestro programa ocupe menos.
    if (*n > 0) {
        Libro* temp = realloc(*libros, (*n) * sizeof(Libro));
        if (temp == NULL) {
            printf("Error al reducir memoria. Se mantiene el bloque original.\n");
            return;
        }
        *libros = temp;
    } else {
        free(*libros);
        *libros = NULL;
    }

    //Funcion sin realloc, si se quiere hacer asi, se debe de pasar por parametro -> Libro** libros,
                                                                                //dado que queremos modificar el puntero de otro metodo
//    if (pos == *n - 1) {
//        (*n)--;
//    } else {
//        for (int i = pos; i < *n - 1; i++) {
//            libros[i] = libros[i + 1];
//        }
//        (*n)--;
//    }

    printf("Libro eliminado correctamente.\n");

    mostrarLibrosRecientes(*libros, *n);


    return;
}
