#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct Node Node;

struct Node {
    Node *child;
    Node *bro;
    int value;
};

void push(Node *parent, int value) {
    Node *node = (Node *)malloc(sizeof(Node));
    node->value = value;
    node->bro = NULL;
    node->child = NULL;
    if (parent->child == NULL) {
        parent->child = node;
    } else {
        Node *current = parent->child;
        while (current->bro != NULL) {
            current = current->bro;
        }

        current->bro = node;
    }
}

void destroy(Node *node) {
    if (node == NULL) {
        return;
    }

    destroy(node->child);
    destroy(node->bro);
    free(node);
}

int getNodeDegree(Node* node) {
    if (node == NULL) {
        return 0;
    }

    Node *current = node->child;
    int k = 0;
    while (current != NULL) {
        k++;
        current = current->bro;
    }

    return k;
}

int getTreeDegree(Node* node) {
    if (node == NULL) {
        return 0;
    }

    int mx = getNodeDegree(node);
    Node* current = node->child;
    while (current != NULL) {
        int childDegree = getTreeDegree(current);
        if (childDegree > mx) {
            mx = childDegree;
        }

        current = current->bro;
    }
    
    return mx;
}