#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int key;
    struct Node* next;
} Node;

Node* createNode(int key) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->key = key;
    newNode->next = NULL;
    return newNode;
}

void freeList(Node* head) {
    while (head != NULL) {
        Node* temp = head;
        head = head->next;
        free(temp);
    }
}

int hashFunction(int key, int M) {
    return (key % M);
}

void insert(Node** hashTable, int key, int M) {
    int index = hashFunction(key, M);
    Node* newNode = createNode(key);

    if (hashTable[index] == NULL) {
        hashTable[index] = newNode;
    } else {
        Node* temp = hashTable[index];
        while (temp->next != NULL) {
            temp = temp->next;
        }
        temp->next = newNode;
    }
}

void printHashTable(Node** hashTable, int M) {
    for (int i = 0; i < M; i++) {
        printf("%d -> ", i);
        Node* current = hashTable[i];
        while (current != NULL) {
            printf("%d -> ", current->key);
            current = current->next;
        }
        printf("\\\n");
    }
}

int main() {
    int N;
    scanf("%d", &N);

    for (int i = 0; i < N; i++) {
        int M, C;
        scanf("%d %d", &M, &C);

        Node** hashTable = (Node**)malloc(M * sizeof(Node*));
        for (int j = 0; j < M; j++) {
            hashTable[j] = NULL;
        }

        for (int j = 0; j < C; j++) {
            int key;
            scanf("%d", &key);
            insert(hashTable, key, M);
        }

        printHashTable(hashTable, M);
        printf("\n");

        for (int j = 0; j < M; j++) {
            freeList(hashTable[j]);
        }
        free(hashTable);
    }

    return 0;
}
