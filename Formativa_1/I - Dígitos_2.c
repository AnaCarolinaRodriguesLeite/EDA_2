#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX_SIZE 10001

char* proxima_sequencia(char* s) {
    int tam = strlen(s);
    int i = tam - 1;
    int ok = 0;
    for (; i >= 0; i--) {
        if (s[i] == '9') {
            s[i] = '0';
        } else {
            s[i]++;
            ok = 1;
            break;
        }
    }
    if (!ok) {
        for (i = tam; i > 0; i--) {
            s[i] = s[i - 1];
        }
        s[0] = '1';
    }
    return s;
}
int main() {
    int n;
    char digitos[MAX_SIZE];
    scanf("%d", &n);
    scanf("%s", digitos);
    for (int tamanho = 1; tamanho <= n; tamanho++) {
        char ini[MAX_SIZE], busca[MAX_SIZE];
        strncpy(ini, digitos, tamanho);
        ini[tamanho] = '\0';
        strcpy(busca, ini);
        char atual[MAX_SIZE] = "";
        
        for (int i = 0; i < n; i++) {
            strncat(atual, &digitos[i], 1);
            if (strcmp(atual, busca) == 0) {
                atual[0] = '\0';
                proxima_sequencia(busca);
            }
        }
        if (atual[0] == '\0') {
            printf("%s\n", ini);
            return 0;
        }
    }
    return 0;
}
