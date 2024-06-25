#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
  int value;
  struct Node *left;
  struct Node *right;
} Node;

Node *newNode(int value) {
  Node *node = (Node *)malloc(sizeof(Node));
  node->value = value;
  node->left = NULL;
  node->right = NULL;
  return node;
}

int height(Node *node) {
  if (node == NULL) {
    return 0;
  } else {
    int leftHeight = height(node->left);
    int rightHeight = height(node->right);
    if (leftHeight > rightHeight) {
      return leftHeight + 1;
    } else {
      return rightHeight + 1;
    }
  }
}

int isBalanced(Node *node) {
  if (node == NULL) {
    return 1;
  }

  int leftBalanced = isBalanced(node->left);
  int rightBalanced = isBalanced(node->right);

  int leftHeight = height(node->left);
  int rightHeight = height(node->right);

  int diff = abs(leftHeight - rightHeight);

  return leftBalanced && rightBalanced && diff <= 1;
}

int main() {
  int n;
  scanf("%d", &n);

  int parents[n];
  for (int i = 1; i < n; i++) {
    scanf("%d", &parents[i]);
    parents[i]--;
  }

  Node *tree[n];
  for (int i = 0; i < n; i++) {
    tree[i] = newNode(i + 1);
  }

  for (int i = 1; i < n; i++) {
    int parent = parents[i];
    if (tree[parent]->left == NULL) {
      tree[parent]->left = tree[i];
    } else {
      tree[parent]->right = tree[i];
    }
  }

  if (isBalanced(tree[0])) {
    printf("Sim\n");
  } else {
    printf("Nao\n");
  }

  return 0;
}
