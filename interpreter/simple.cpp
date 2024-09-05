#ifndef SIMPLE_H
#define SIMPLE_H

enum simple { // format: '// [keyword used] [enum index]'
    PROGRAM, // program 0
    NAME, // [name] 1
    ASSIGN, // = 2
    SEMICOLON, // ; 3
    PRINT, // out 4
    IF, // if 5
    ELSE, // else 6
    WHILE, // while 7
    LPAREN, // ( 8
    RPAREN, // ) 9
    LCURL, // { 10
    RCURL, // } 11
    NOT, // ! 12
    OR, // | 13
    AND, // & 14
    EQUAL, // == 15
    LESS, // < 16
    ADD, // + 17
    SUBTRACT, // - 18
    MULTIPLY, // * 19
    DIVIDE, // / 20
    NUMBER, // [number] 21
    NUM, // num 22
    EOS // [n/a] 23
};

#endif