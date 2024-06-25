#include <stdio.h>
int main() {
    int linhas, colunas, x_mic, y_mic, n_movimentos;
    scanf("%d %d", &linhas, &colunas);
    scanf("%d %d", &x_mic, &y_mic);
    scanf("%d", &n_movimentos);
    int minutos_de_conversa = 0;
    int x_homem = 0, y_homem = 0;
    for (int i = 0; i < n_movimentos; ++i) {
        int movimento;
        
        scanf("%d", &movimento);
        if (movimento == 1) {
            y_homem++;
        } else if (movimento == 2) {
            y_homem--;
        } else if (movimento == 3) {
            x_homem++;
        } else if (movimento == 4) {
            x_homem--;
        }
        if (x_homem >= x_mic - 1 && x_homem <= x_mic + 1 && y_homem >= y_mic - 1 && y_homem <= y_mic + 1) {
            minutos_de_conversa++;
        }
    }
    printf("%d\n", minutos_de_conversa);
    return 0;
}
