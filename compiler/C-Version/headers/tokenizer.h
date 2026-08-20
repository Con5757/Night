#ifndef TOKENIZER_H
#define TOKENIZER_H

// token structs

typedef enum {
    TOKEN_VARIABLE,

    // import
    TOKEN_USING

} TokenType;

typedef struct {
    TokenType type;
    char value;
} Token;

// tokenize

Token* lexer(const char* contents, int* tokenCount);
    
#endif