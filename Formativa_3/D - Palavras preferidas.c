#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_PALAVRAS 216
#define HASH_SIZE 100003

typedef struct VotoNode {
    char palavra[17];
    int votos;
    struct VotoNode *next;
} VotoNode;

VotoNode *tabela_hash[HASH_SIZE];

unsigned int hash(char *palavra) {
    unsigned int hash_val = 0;
    while (*palavra != '\0') {
        hash_val = (hash_val * 31 + *palavra) % HASH_SIZE;
        palavra++;
    }
    return hash_val;
}

void contarVoto(char *palavra) {
    unsigned int index = hash(palavra);
    VotoNode *node = tabela_hash[index];
    while (node != NULL) {
        if (strcmp(node->palavra, palavra) == 0) {
            node->votos++;
            return;
        }
        node = node->next;
    }
    VotoNode *new_node = (VotoNode *)malloc(sizeof(VotoNode));
    if (new_node == NULL) {
        exit(EXIT_FAILURE);
    }
    strcpy(new_node->palavra, palavra);
    new_node->votos = 1;
    new_node->next = tabela_hash[index];
    tabela_hash[index] = new_node;
}

void imprimirVotos(char *palavra) {
    unsigned int index = hash(palavra);
    VotoNode *node = tabela_hash[index];
    while (node != NULL) {
        if (strcmp(node->palavra, palavra) == 0) {
            printf("%d\n", node->votos);
            return;
        }
        node = node->next;
    }
    printf("0\n");
}

void resetarVotos(char *palavra) {
    unsigned int index = hash(palavra);
    VotoNode *node = tabela_hash[index];
    while (node != NULL) {
        if (strcmp(node->palavra, palavra) == 0) {
            node->votos = 0;
            return;
        }
        node = node->next;
    }
}

int main() {
    char comando[3], palavra[17];
    while (scanf("%s %s", comando, palavra) != EOF) {
        if (comando[0] == '1') {
            contarVoto(palavra);
        } else if (comando[0] == '2') {
            imprimirVotos(palavra);
        } else if (comando[0] == '3') {
            resetarVotos(palavra);
        }
    }
    for (int i = 0; i < HASH_SIZE; i++) {
        VotoNode *node = tabela_hash[i];
        while (node != NULL) {
            VotoNode *temp = node;
            node = node->next;
            free(temp);
        }
    }
    return 0;
}
