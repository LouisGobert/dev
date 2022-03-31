#include <stdio.h>

char* restoreString(char* s, int* indices, int indicesSize) {

    char* copy = malloc(sizeof(char) * (indicesSize + 1));
    // make a copy
    for (int i = 0; i < indicesSize; i++)
        copy[indices[i]] = s[i];

    copy[indicesSize] = '\0';
    return copy;

}



