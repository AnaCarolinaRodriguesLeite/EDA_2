#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Node {
    int colonia;
    char alimento[11];
    struct Node *next;
} Node;

typedef struct {
    int size;
    Node **table;
} HashTable;

unsigned int hash(int colonia, const char *alimento, int table_size) {
    unsigned int hash_val = 0;
    unsigned int alimento_len = strlen(alimento);
    for (int i = 0; i < alimento_len; i++) {
        hash_val = hash_val * 31 + alimento[i];
    }
    return (hash_val + colonia) % table_size;
}

HashTable *createHashTable(int size) {
    HashTable *hashTable = (HashTable *)malloc(sizeof(HashTable));
    hashTable->size = size;
    hashTable->table = (Node **)calloc(size, sizeof(Node *));
    return hashTable;
}

void insert(HashTable *hashTable, int colonia, const char *alimento) {
    unsigned int index = hash(colonia, alimento, hashTable->size);
    Node *new_node = (Node *)malloc(sizeof(Node));
    new_node->colonia = colonia;
    strcpy(new_node->alimento, alimento);
    new_node->next = hashTable->table[index];
    hashTable->table[index] = new_node;
}


int contains(HashTable *hashTable, int colonia, const char *alimento) {
    unsigned int index = hash(colonia, alimento, hashTable->size);
    Node *current = hashTable->table[index];
    while (current != NULL) {
        if (current->colonia == colonia && strcmp(current->alimento, alimento) == 0) {
            return 1;
        }
        current = current->next;
    }
    return 0;
}

int main() {
    HashTable *hashTable = createHashTable(1048576);

    int colonia;
    char alimento[11];
    while (scanf("%d %s", &colonia, alimento) != EOF) {
        if (contains(hashTable, colonia, alimento)) {
            printf("%d\n", colonia);
        } else {
            insert(hashTable, colonia, alimento);
        }
    }

    for (int i = 0; i < hashTable->size; i++) {
        Node *current = hashTable->table[i];
        while (current != NULL) {
            Node *temp = current;
            current = current->next;
            free(temp);
        }
    }
    free(hashTable->table);
    free(hashTable);

    return 0;
}
