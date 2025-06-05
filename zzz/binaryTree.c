#include <stdio.h>
#include <stdlib.h>

typedef struct Node Node;

struct Node {
    char key;
    Node *l;
    Node *r;
};

Node *buildTree(int n) {
    if (n == 0) {
        return NULL;
    }
    Node *node = (Node *)malloc(sizeof(Node));
    int nl = n / 2;
    int nr = n - nl - 1;

    scanf("%d", &node->key);
    node->l = buildTree(nl);
    node->r = buildTree(nr);

    return node;
}

void printTree(Node *node, int h) {
    if (node) {
        printTree(node->l, h + 1);
        for (int i = 0; i < h; i++) {
            printf("    ");
        }
        printf("%d\n", node->key);
        printTree(node->r, h + 1);
    }
}

int main() {
    Node *node;
    int n;
    scanf("%d", &n);
    node = buildTree(n);
    printTree(node, 0);
    return 0;
}