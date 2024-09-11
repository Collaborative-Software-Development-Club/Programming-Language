#ifndef SIMPLE_H
#define SIMPLE_H

enum simple {
    PROGRAM,
    NAME,
    ASSIGN,
    SEMICOLON,
    PRINT,
    IF,
    ELIF,
    ELSE,
    WHILE,
    LPAREN,
    RPAREN,
    LCURL,
    RCURL,
    NOT,
    OR,
    AND,
    EQUAL,
    NOTEQUAL,
    LT,
    GT,
    LTE,
    GTE,
    ADD,
    SUBTRACT,
    MULTIPLY,
    DIVIDE,
    POWER,
    MOD,
    NUMBER, // this is for the variable
    NUM, // this is for keywords like int
    EOS
};

#endif