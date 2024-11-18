//
// Created by Carol on 13/11/2024.
//

#include "utils.h"
#include <stdio.h>
#include <string.h>
// Función para cifrar/descifrar el contenido usando XOR

int cifrarXOR(const char *input, const char *output, const char *key) {
    FILE *archivoOriginal = fopen(input, "rb"); // Abrir archivo original en modo lectura binaria
    FILE *archivoCifrado = fopen(output, "wb"); // Abrir archivo de salida en modo escritura binaria

    if (archivoOriginal== NULL || archivoCifrado == NULL) {
        perror("Error al abrir los archivos");
        if (archivoOriginal != NULL) fclose(archivoOriginal);
        if (archivoCifrado != NULL) fclose(archivoCifrado);
        return -1;
    }

    size_t keyLength = strlen(key);
    int i = 0; // Índice para recorrer la clave
    int c;

    // Leer el archivo byte por byte
    while ((c = fgetc(archivoOriginal)) != EOF) {
        // Aplicar XOR con la clave
        char cifrado = c ^ key[i % keyLength];
        fputc(cifrado, archivoCifrado);
        i++;
    }

    fclose(archivoOriginal);
    fclose(archivoCifrado);

    return 0; //exito
}
