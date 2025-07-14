#include <stdio.h>

int main() {
    int array[] = {3, 5, 4, 2, 5, 3, 4,7};
    int tam = sizeof(array) / sizeof(array[0]);
    
    for (int i = 0; i < tam; i++) {
        int repetido = 0;

        for (int j = 0; j < tam; j++) {
            if (i != j && array[i] == array[j]) {
                repetido = 1;
                break;
            }
        }

        if (!repetido) {
            printf("El numero que no esta duplicado es: %d\n", array[i]);
        }
    }

    
    return 0;
}
