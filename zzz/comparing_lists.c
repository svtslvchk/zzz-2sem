#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct Node Node;

struct Node {
    int value;
    Node *next;
};

Node *init(int value) {
    Node *list = (Node *)malloc(sizeof(Node));
    list->value = value;
    list->next = NULL;
}

void append(Node *arr, int value) {
    Node *node = init(value);
    if (arr == NULL) {
        arr = node;
    } else {
        Node *current = arr;
        while (current->next != NULL) {
            current = current->next;
        }

        current->next = node;
    }
}

int sizeList(Node *arr) {
    int k = 0;
    if (arr == NULL) {
        return k;
    } else {
        Node *current = arr;
        k++;
        while (current->next != NULL) {
            k++;
            current = current->next;
        }

        return k;
    }
}

void printList(Node *arr) {
    if (arr == NULL) {
        printf("list is empty\n");
        return;
    }

    Node *current = arr;
    while (current != NULL) {
        printf("%d ", current->value);
        current = current->next;
    }

    printf("\n");
}

bool compare(Node *a, Node *b) {
    int sa = sizeList(a);
    int sb = sizeList(b);
    if (sa != sb) {
        return false;
    }

    int i = 0;
    while (i < sa) {
        if (a->value != b->value) {
            return false;
        }

        a = a->next;
        b = b->next;
        i++;
    }

    return true;
}


int main() {
    Node *a = init(1);
    append(a, 3);
    printList(a);
    Node *b = init(1);
    append(b, 3);
    printList(b);
    bool f = compare(a, b);
    if (f) {
        printf("TOP!!!\n");
    } else {
        printf("zhopa\n");
    }
}