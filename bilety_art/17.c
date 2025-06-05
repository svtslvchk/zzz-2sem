// k-ая компонента двоичного дерева в концевом порядке обхода O(n)
#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

typedef struct Node Node;

struct Node {
    int value;
    Node *l;
    Node *r;
};

Node *createNode(int value) {
    Node *newNode = (Node *)malloc(sizeof(Node));
    newNode->value = value;
    newNode->l = NULL;
    newNode->r = NULL;
    return newNode;
}

void postorder(Node *node, int k, int *count, Node **res) {
    if (!node) {
        return;
    }

    postorder(node->l, k, count, res);
    postorder(node->r, k, count, res);

    (*count)++;
    if (*count == k) {
        *res = node;
        return;
    }
}

Node *search(Node *node, int k) {

    int count = 0;
    Node *res = NULL;
    postorder(node, k, &count, &res);
    return res;
}

int main() {
    int k;
    scanf("%d", &k);
    Node *node = createNode(3);
    node->l = createNode(15);
    node->r = createNode(90);
    node->l->l = createNode(105);
    Node *r = search(node, k);
    if (r) {
        printf("%d\n", r->value);
    } else {
        printf("GOVNO");
    }

    return 0;
}