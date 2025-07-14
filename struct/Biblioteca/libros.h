#ifndef LIBROS_H
#define LIBROS_H

typedef struct {
    char titulo[100];
    char autor[100];
    int anio;
} Libro;

void registrarLibros(Libro* libros, int n);
void mostrarLibrosRecientes(Libro* libros, int n);

#endif
