/**
 * @file exercise_05_string_pointer_traversal.c
 * @brief Exercise 5 - Character string traversal with pointers.
 *
 * @details Walks through a character string with a pointer and prints each character,
 * its ASCII code and its memory address.
 *
 
 * @author Andres Benitez
 * @date 2026-09-30
 */
#include <stdio.h>

int main(void) {
    char text[] = "Hola OpenMP";
    char *ptr = text;

    printf("Cadena: \"%s\"\n", text);
    printf("%-10s %-10s %s\n", "Caracter", "Codigo", "Direccion");
    while (*ptr != '\0') {
        printf("'%c'        %-10d %p\n", *ptr, *ptr, (void *)ptr);
        ptr++;
    }
    return 0;
}