#include <stdio.h>
#include <stdbool.h>
#include <stdbool.h>

typedef struct Node Node;

struct Node {
    int value;
    Node *l;
    Node *r;
};

void push(Node **node, int value);
Node* pop(Node *node);
Node* top(Node *node);