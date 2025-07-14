#include <stdio.h>
#include <stdlib.h>

#include "libros.h"

int main()
{
    int n;
    printf("¿Cuantos libros va a registrar ?");
    scanf("%d", &n);
    getchar();

    Libro* libros = (Libro*) malloc(n*sizeof(Libro));
    if(libros == NULL){
        printf("Error al reservar memoria.\n");
        return 1;
    }

    registrarLibros(libros, n);
    mostrarLibrosRecientes(libros, n);

    free(libros);
    return 0;
}
