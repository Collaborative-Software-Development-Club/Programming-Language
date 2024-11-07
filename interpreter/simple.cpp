#ifndef SIMPLE_H
#define SIMPLE_H

enum simple {
    PROGRAM, // memorandum   0
    NAME, // designation     1
    ASSIGN, // designate     2
    SEMICOLON, // .          3
    PRINT, // etch           4
    IF, // presuming         5
    ELSE, // lest            6
    WHILE, // midst          7
    LPAREN, // (             8
    RPAREN, // )             9
    LCURL, // {              10
    RCURL, // }              11
    NOT, // nay              12
    OR, // disjunction       13
    AND, // moreover         14
    EQUAL, // commensurate   15
    LESS, // beneath         16
    ADD, // replenish        17
    SUBTRACT, // diminish    18
    MULTIPLY, // mushroom    19
    DIVIDE, // dichotomize   20
    NUMBER, // [number]      21
    //(stand-in, will be replaced with roman numerals later)
    NUM, // tally            22
    EOS // conclusion        23
};

#endif