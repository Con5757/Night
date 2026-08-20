#ifndef TOKENIZER_H
#define TOKENIZER_H

// token structs

typedef enum {
    // file structure
    TOKEN_RIGHT_PARAN, 
    TOKEN_LEFT_PARAN,

    TOKEN_RIGHT_SQUARE_PARAN,
    TOKEN_LEFT_SQUARE_PARAN,

    TOKEN_RIGHT_CURLY_PARAN,
    TOKEN_LEFT_CURLY_PARAN,

    TOKEN_STRING_WRAP, // ""
    TOKEN_CHAR_WRAP, // ''

    // period
    TOKEN_PERIOD,

    // operators
    TOKEN_ADD,
    TOKEN_SUB,
    TOKEN_MULTI,
    TOKEN_DIV,

    TOKEN_EXPONENT, // **
    TOKEN_MODULO,

    TOKEN_GREATER_THAN, // >
    TOKEN_GREATER_THAN_OR_EQUAL, // >=
    TOKEN_LESS_THAN, // <
    TOKEN_LESS_THAN_OR_EQUAL, // <=

    TOKEN_EQUAL, // =
    TOKEN_NOT_EQUAL, // !=

    // logical
    TOKEN_AND,
    TOKEN_OR,
    TOKEN_XOR,

    TOKEN_NAND,
    TOKEN_NOR,
    TOKEN_XNOR,

    // boolean
    TOKEN_TRUE, // 1
    TOKEN_FALSE, // 0

    TOKEN_BOOLEAN_TRUE,
    TOKEN_BOOLEAN_FALSE,

    // pointers
    TOKEN_REF_SINGLE_PTR,
    TOKEN_REF_DOUBLE_PTR,
    TOKEN_REF_MULTI_PTR,

    TOKEN_DREF_SINGLE_PTR,
    TOKEN_DREF_DOUBLE_PTR,
    TOKEN_DREF_MULTI_PTR, 

    // loops
    TOKEN_DURING,
    TOKEN_REPEAT,

    TOKEN_COMMA,

    // variable
    TOKEN_VARIABLE,

    // number
    /* 
    this can get thrown in a helper func cus its 
    gonna be clunky to throw the nums in the same lexer func
    */
    TOKEN_NUMBER, 

    // import
    TOKEN_USING,
    TOKEN_BOOLEAN,
    TOKEN_TERMINAL,
    TOKEN_FILE,
    TOKEN_CCP,

    // function
    TOKEN_FUNC,
    TOKEN_MAIN,
    TOKEN_SEND,
    TOKEN_KILL,

    // conditional
    TOKEN_SWITCH,
    TOKEN_ARG,
    TOKEN_END,

    TOKEN_ATTEMPT,
    TOKEN_INCASE,

    TOKEN_IF,
    TOKEN_ELIF,
    TOKEN_ELSE,

    // datatypes
    TOKEN_INT,
    TOKEN_DEC,
    TOKEN_STR,
    TOKEN_NIL,
    TOKEN_QCCP,

    // terminal keywords
    TOKEN_TERMINAL_NEWLINE,
    TOKEN_TERMINAL_IN,
    TOKEN_TERMINAL_OUT,

    // file
    TOKEN_READ,
    TOKEN_WRITE,

    // newline
    NEWLINE

} TokenType;

typedef struct {
    TokenType type;
    char value;
} Token;

// tokenize

Token* lexer(const char* contents, int* tokenCount);
    
#endif