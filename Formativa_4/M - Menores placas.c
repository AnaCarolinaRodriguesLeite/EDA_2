#include <stdio.h>
#include <stdlib.h>

typedef struct AVLNode {
    int key;
    struct AVLNode *left;
    struct AVLNode *right;
    int height;
} AVLNode;

int height(AVLNode *N) {
    if (N == NULL)
        return 0;
    return N->height;
}

int max(int a, int b) {
    return (a > b) ? a : b;
}

AVLNode* newNode(int key) {
    AVLNode* node = (AVLNode*)malloc(sizeof(AVLNode));
    node->key = key;
    node->left = NULL;
    node->right = NULL;
    node->height = 1;
    return node;
}

AVLNode *rightRotate(AVLNode *y) {
    AVLNode *x = y->left;
    AVLNode *T2 = x->right;

    x->right = y;
    y->left = T2;

    y->height = max(height(y->left), height(y->right)) + 1;
    x->height = max(height(x->left), height(x->right)) + 1;

    return x;
}

AVLNode *leftRotate(AVLNode *x) {
    AVLNode *y = x->right;
    AVLNode *T2 = y->left;

    y->left = x;
    x->right = T2;

    x->height = max(height(x->left), height(x->right)) + 1;
    y->height = max(height(y->left), height(y->right)) + 1;

    return y;
}

int getBalance(AVLNode *N) {
    if (N == NULL)
        return 0;
    return height(N->left) - height(N->right);
}

AVLNode* insert(AVLNode* node, int key) {
    if (node == NULL)
        return newNode(key);

    if (key < node->key)
        node->left = insert(node->left, key);
    else if (key > node->key)
        node->right = insert(node->right, key);
    else
        return node;

    node->height = 1 + max(height(node->left), height(node->right));
    int balance = getBalance(node);

    if (balance > 1 && key < node->left->key)
        return rightRotate(node);

    if (balance < -1 && key > node->right->key)
        return leftRotate(node);

    if (balance > 1 && key > node->left->key) {
        node->left = leftRotate(node->left);
        return rightRotate(node);
    }
    if (balance < -1 && key < node->right->key) {
        node->right = rightRotate(node->right);
        return leftRotate(node);
    }

    return node;
}

AVLNode * minValueNode(AVLNode* node) {
    AVLNode* current = node;

    while (current->left != NULL)
        current = current->left;

    return current;
}

void inorderTraversal(AVLNode* root, int *arr, int *index, int N) {
    if (root == NULL || *index >= N)
        return;
    inorderTraversal(root->left, arr, index, N);

    if (*index < N) {
        arr[*index] = root->key;
        (*index)++;
    }
    inorderTraversal(root->right, arr, index, N);
}

int main() {
    AVLNode *root = NULL;
    int operation, value;

    while (scanf("%d", &operation) != EOF) {
        if (operation == 1) {
            scanf("%d", &value);
            root = insert(root, value);
        } else if (operation == 2) {
            scanf("%d", &value);
            int *result = (int *)malloc(value * sizeof(int));
            int index = 0;
            inorderTraversal(root, result, &index, value);

            for (int i = 0; i < value; i++) {
                if (i > 0) printf(" ");
                printf("%d", result[i]);
            }
            printf("\n");
            free(result);
        }
    }

    return 0;
}