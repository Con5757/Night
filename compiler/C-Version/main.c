#include <stdio.h>
#include <stdlib.h>

#include "headers/fileRead.h"
#include "headers/tokenizer.h"

int main() {
    char fileName[64];
    printf("file: ");
    scanf("%s", fileName);

//--
    Token token;

    char *script = readFile(fileName);
    Token *tokens = lex(script);

    return 0;
}