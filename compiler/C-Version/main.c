#include <stdio.h>
#include <stdlib.h>

#include "headers/fileRead.h"
#include "headers/tokenizer.h"

int main() {
    char fileName[64];
    printf("file: ");
    scanf("%s", fileName);

    char *script = readFile(fileName);
    characterizeScript(script);

    return 0;
}