#include <stdio.h>
#include <ctype.h>

typedef enum {
    TOKEN_INT,
    TOKEN_PLUS,
    TOKEN_EOF
} TokenType;

typedef struct {
    TokenType type;
    char value;
} Token;

Token* lexer(const char* contents, int* tokenCount);