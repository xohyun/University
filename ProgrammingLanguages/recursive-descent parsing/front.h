#ifndef FRONT_H
#define FRONT_H

/* Character classes */
#define LETTER 0
#define DIGIT 1
#define UNKNOWN 99

/* Token codes */
#define INT_LIT 10
#define IDENT 11
#define ASSIGN_OP 20
#define ADD_OP 21
#define SUB_OP 22
#define MULT_OP 23
#define DIV_OP 24
#define LEFT_PAREN 25
#define RIGHT_PAREN 26

//비교연산과 논리연산 token code 입력
#define EQUAL_TO_OP 30
#define NOT_EQUAL_TO_OP 31
#define LESS_OP 32
#define GREATER_OP 33

#define NOT_OP 50
#define LOGICAL_AND_OP 51
#define LOGICAL_OR_OP 52

int lex();

#endif