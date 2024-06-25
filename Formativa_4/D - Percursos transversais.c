#include <stdio.h>
#include <string.h>

void findPostOrder(char* inOrder, char* preOrder, int n) {
    if (n <= 0) return;

    char root = preOrder[0];

    int rootIndex = 0;
    while (rootIndex < n && inOrder[rootIndex] != root) {
        rootIndex++;
    }

    findPostOrder(inOrder, preOrder + 1, rootIndex);
    findPostOrder(inOrder + rootIndex + 1, preOrder + rootIndex + 1, n - rootIndex - 1);
    printf("%c", root);
}

int main() {
    int C;
    scanf("%d", &C);

    while (C--) {
        int N;
        char preOrder[53], inOrder[53];
        scanf("%d %s %s", &N, preOrder, inOrder);

        findPostOrder(inOrder, preOrder, N);
        printf("\n");
    }

    return 0;
}
