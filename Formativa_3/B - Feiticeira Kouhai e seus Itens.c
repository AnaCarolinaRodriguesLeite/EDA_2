#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    long long key;
    long long value;
    struct Node* next;
} Node;

unsigned int hashFunction(long long key, int tableSize) {
    return (unsigned int)((key % tableSize + tableSize) % tableSize);
}

void insert(Node** table, int tableSize, long long key, long long value) {
    unsigned int index = hashFunction(key, tableSize);
    Node* current = table[index];
    
    while (current != NULL) {
        if (current->key == key) {
            current->value += value;
            if (current->value <= 0) {
                current->value = 0;
            }
            return;
        }
        current = current->next;
    }

    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->key = key;
    newNode->value = value > 0 ? value : 0;
    newNode->next = table[index];
    table[index] = newNode;
}

long long totalItems(Node** table, int tableSize) {
    long long total = 0;
    for (int i = 0; i < tableSize; i++) {
        Node* current = table[i];
        while (current != NULL) {
            total += current->value;
            current = current->next;
        }
    }
    return total;
}

void freeTable(Node** table, int tableSize) {
    for (int i = 0; i < tableSize; i++) {
        Node* current = table[i];
        while (current != NULL) {
            Node* toFree = current;
            current = current->next;
            free(toFree);
        }
    }
}

int main() {
    int N;
    scanf("%d", &N);

    int tableSize = 100003;
    Node** table = (Node**)calloc(tableSize, sizeof(Node*));
    
    if (table == NULL) {
        return 1;
    }

    for (int i = 0; i < N; i++) {
        long long K, Q;
        scanf("%lld %lld", &K, &Q);
        insert(table, tableSize, K, Q);
    }

    long long result = totalItems(table, tableSize);
    printf("%lld\n", result);

    freeTable(table, tableSize);
    free(table);
    return 0;
}
