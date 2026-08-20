#include <stdlib.h>
#include <stdio.h>

#include "../headers/fileRead.h"

char* readFile(const char *filePath) {
    FILE *file = fopen(filePath, "rb");
    if (file == NULL) {
        printf("unable to open file");
        return NULL;
    }

    fseek(file, 0, SEEK_END);
    long fileSize = ftell(file);
    rewind(file);

    char *script = malloc(fileSize + 1);
    if (script == NULL) {
        printf("malloc failed");
        fclose(file);
        return NULL;
    }

    size_t bytesRead = fread(script, 1, fileSize, file);
    script[bytesRead] = '\0';

    fclose(file);
    return script;
}