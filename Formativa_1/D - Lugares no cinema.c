#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX 500
int main() {
    int n, m, i, j, count = 0;
    char cinema[20][25];
    char input[MAX][3];
    scanf("%d %d", &n, &m);
    // Inicializar o cinema como vazio
    for (i = 0; i < n; i++) {
        for (j = 0; j < m; j++) {
            cinema[i][j] = '-';
        }
    }
    while (count < n * m) {
        scanf("%s", input[count]);
        // Converter a entrada para linha e coluna
        i = input[count][0] - 'A'; // Letra da fileira
        j = atoi(input[count] + 1) - 1; // Número do lugar
        // Marcar o assento como ocupado
        cinema[i][j] = 'X';
        count++;
    }
    printf("  ");
    for (i = 1; i <= m; i++) {
        printf("%02d ", i);
    }
    printf("\n");
    for (i = n - 1; i >= 0; i--) {
        printf("%c ", 'A' + i);
        for (j = 0; j < m; j++) {
            if (cinema[i][j] == 'X') {
                printf("XX ");
            } else {
                printf("-- ");
            }
        }
        printf("\n");
    }
    return 0;
}