#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

typedef struct Node Node;

struct Node {
    int value;
    Node *l;
    Node *r;
};

Node* buildTree(int n) {
    if (!n) {
        return NULL;
    }

    Node *node = (Node *)malloc(sizeof(Node));

    int nl = n / 2;
    int nr = n - nl - 1;

    scanf("%d", &node->value);
    node->l = buildTree(nl);
    node->r = buildTree(nr);

    return node;
}

void printTree(Node *node, int d) {
    if (!node) {
        return;
    }

    printTree(node->r, d + 1);

    for (int i = 0; i < d; i++) {
        printf("    ");
    }

    printf("%d\n", node->value);

    printTree(node->l, d + 1);
}

int main() {
    int n;
    scanf("%d", &n);
    Node *root = buildTree(n);
    printTree(root, 0);
}