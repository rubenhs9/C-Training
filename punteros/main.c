#include <stdio.h>
#include <stdlib.h>
#include "funciones.h"

int main(){
    //PASAR PUNTEROS A FUNCIONES
    int datos[] = {1,2,3,4};
    int datos2[4];
//    mostrarArray(datos, 4);
//    doblar(datos, 4);
    copiarArray(datos, datos2, 4);
    doblar(datos,4);
    mostrarArray(datos,4);
    return 0;


    /*
    Realmente cuando creamos un array, la variable numeros es un puntero al primer
    elemento (&numero[0])
    */
//    int numeros[] = {10,20,30,40};

    //printf("%d\n", numeros[2]); // usando �ndices: 30
    //printf("%d\n", *(numeros+2)); // usando punteros: 30

    //Recorrer array con punteros
//    for(int i = 0; i<4;i++){
//        printf("%d\n", *(numeros + i));
//    }

    //O como hemos visto en otros ej.
//    int *p = numeros;
//        for (int i = 0; i < 4; i++) {
//            printf("%d\n", *(p + i));
//        }

    // Mas eficiente aun
//    int *p = numeros;
//    for(int i = 0; i < 4; i++) {
//        printf("%d\n", *p);
//        p++;  // Aqu� solo incrementas el puntero una vez, sin c�lculo adicional
//    }

    /*
    �Por que es mas eficiente utilizar punteros en vez de indices?
    Internamente numeros[i] se traduce a *(numeros + i).
    Si ya tenemos un puntero que vamos moviendo (p++), te ahorras el calculo del desplazamiento
    por cada iteraci�n.
    */



}
