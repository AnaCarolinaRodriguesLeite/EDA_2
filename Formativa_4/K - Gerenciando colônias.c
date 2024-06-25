#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define RED 1
#define BLACK 0

typedef struct Node {
    int key;
    char food[11];
    int color;
    struct Node *left, *right;
} Node;

Node* newNode(int key, char *food, int color) {
    Node *node = (Node*)malloc(sizeof(Node));
    node->key = key;
    strcpy(node->food, food);
    node->color = color;
    node->left = node->right = NULL;
    return node;
}

int isRed(Node *node) {
    return node != NULL && node->color == RED;
}

Node* rotateLeft(Node *h) {
    Node *x = h->right;
    h->right = x->left;
    x->left = h;
    x->color = h->color;
    h->color = RED;
    return x;
}

Node* rotateRight(Node *h) {
    Node *x = h->left;
    h->left = x->right;
    x->right = h;
    x->color = h->color;
    h->color = RED;
    return x;
}

void flipColors(Node *h) {
    h->color = RED;
    h->left->color = BLACK;
    h->right->color = BLACK;
}

Node* balance(Node *h) {
    if (isRed(h->right)) h = rotateLeft(h);
    if (isRed(h->left) && isRed(h->left->left)) h = rotateRight(h);
    if (isRed(h->left) && isRed(h->right)) flipColors(h);
    return h;
}

Node* insert(Node *h, int key, char *food, int *duplicate) {
    if (h == NULL) return newNode(key, food, RED);

    if (key < h->key) {
        h->left = insert(h->left, key, food, duplicate);
    } else if (key > h->key) {
        h->right = insert(h->right, key, food, duplicate);
    } else {
        if (strcmp(h->food, food) == 0) {
            *duplicate = 1;
        } else {
            h->right = insert(h->right, key, food, duplicate);
        }
    }

    if (isRed(h->right) && !isRed(h->left)) h = rotateLeft(h);
    if (isRed(h->left) && isRed(h->left->left)) h = rotateRight(h);
    if (isRed(h->left) && isRed(h->right)) flipColors(h);

    return h;
}

Node* insertRoot(Node *h, int key, char *food, int *duplicate) {
    h = insert(h, key, food, duplicate);
    h->color = BLACK;
    return h;
}

int main() {
    Node *root = NULL;
    char line[100];
    int key;
    char food[11];

    while (scanf("%d %s", &key, food) != EOF) {
        int duplicate = 0;
        root = insertRoot(root, key, food, &duplicate);
        if (duplicate) {
            printf("%d\n", key);
        }
    }

    return 0;
}