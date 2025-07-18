#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#include "libros.h"


void crearMenu(){
    Libro* libros = NULL;
    int n = 0;
    int opcion;

    do {
        printf("\n--- Menú ---\n");
        printf("1. Registrar libros\n");
        printf("2. Mostrar libros recientes\n");
        printf("3. Eliminar libros \n");
        printf("4. Salir\n");
        printf("Seleccione una opción: ");
        scanf("%d", &opcion);
        getchar();

        switch (opcion) {
            case 1:

                registrarLibros(&libros, &n);
                break;

            case 2:
                if (libros == NULL || n == 0) {
                    printf("No hay libros registrados.\n");
                } else {
                    mostrarLibrosRecientes(libros, n);
                }
                break;

            case 3:
                if (libros == NULL || n == 0) {
                    printf("No hay libros registrados.\n");
                } else {
                    eliminarLibro(libros, &n);
                }
                break;


            case 4:
                printf("Saliendo...\n");
                break;

            default:
                printf("Opción inválida.\n");
        }

    } while (opcion != 4);

    free(libros);
}

