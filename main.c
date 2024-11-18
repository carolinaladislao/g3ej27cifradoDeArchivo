//EJERCICIO 27
// Escriba un programa que cifre simétricamente el contenido de un archivo
#include <stdio.h>
#include <stdlib.h>
#include "utils.h"

int main() {
    const char *archivoOriginal = "entrada.txt";
    const char *archivoCifrado = "cifrado.txt";
    const char *clave = "miClaveSecreta"; // Clave de cifrado

    int n = cifrarXOR(archivoOriginal, archivoCifrado, clave);


    if (n == 0){
        printf("Archivo cifrado exitosamente en '%s'.\n", archivoCifrado);
    }else{
        printf("No se pudo cifrar el archivo\n");
    }


    return 0;
}
