#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

typedef struct Node Node;

struct Node {
    Node *child;
    Node *bro;
    int value;
};

Node *init(int value) {
    Node *node = (Node *)malloc(sizeof(Node));
    node->bro = NULL;
    node->child = NULL;
    node->value = value;
    return node;
}

void push(Node *parent, int value) {
    Node *newNode = (Node *)malloc(sizeof(Node));
    newNode->bro = NULL;
    newNode->child = NULL;
    newNode->value = value;
    
    if (parent->child == NULL) {
        parent->child = newNode;
    } else {
        Node *current = parent->child;
        while (current->bro != NULL) {
            current = current->bro;
        }
        current->bro = newNode;
    }
}
void printTree(Node *node, int level) {
    if (node == NULL) {
        return;
    }

    for (int i = 0; i < level; ++i) {
        printf("\t");
    }

    printf("%d\n", node->value);
    printTree(node->child, level + 1);
    printTree(node->bro, level);
}

void printTreeR(Node *node) {
    printTree(node, 0);
}

int dfs(Node *node) {
    if (node == NULL) {
        return 0;
    }

    int mx = 0;
    Node *current = node->child;
    while (current != NULL) {
        int d = dfs(current);
        if (d > mx) {
            mx = d;
        }

        current = current->bro;
    }

    return mx + 1;
}

int main() {
    Node *root = init(5);
    push(root, 3);
    push(root, 7);
    push(root->child, 2);  
    push(root->child, 8);  
    printTreeR(root);

    printf("Глубина дерева: %d\n", dfs(root));  
    return 0;
}