// прошивка дерева буллевского выражения (ДОДЕЛАТЬ!!!)
#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

typedef enum Type Type;
typedef union Value Value;
typedef struct Lexem Lexem;
typedef struct Node Node;

enum Type {
    OPERATOR, NUMBER
};

union Value {
    int number;
    char symbol;
};

struct Lexem {
    Type type;
    Value value;
};

struct Node {
    Lexem lex;
    Node *l;
    Node *r;
};