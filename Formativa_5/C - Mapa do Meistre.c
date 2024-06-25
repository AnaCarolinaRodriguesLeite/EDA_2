#include <stdio.h>
#include <stdbool.h>

#define MAX 100

typedef struct {
    int x, y;
} Ponto;

int largura, altura;
char mapa[MAX][MAX];
bool visitado[MAX][MAX];

bool bfs(int inicioX, int inicioY) {
    Ponto fila[MAX * MAX];
    int frente = 0, traseira = 0;

    fila[traseira++] = (Ponto){inicioX, inicioY};
    visitado[inicioY][inicioX] = true;

    while (frente < traseira) {
        Ponto atual = fila[frente++];

        if (mapa[atual.y][atual.x] == '*') {
            return true;
        }

        int direcoes[4][2] = { {0, 1}, {0, -1}, {1, 0}, {-1, 0} };
        char movimentos[4] = { '>', '<', 'v', '^' };

        for (int i = 0; i < 4; i++) {
            int novoX = atual.x + direcoes[i][0];
            int novoY = atual.y + direcoes[i][1];

            if (novoX >= 0 && novoX < largura && novoY >= 0 && novoY < altura && !visitado[novoY][novoX]) {
                if (mapa[atual.y][atual.x] == movimentos[i] || mapa[atual.y][atual.x] == '.') {
                    fila[traseira++] = (Ponto){novoX, novoY};
                    visitado[novoY][novoX] = true;
                }
            }
        }
    }
    return false;
}

int main() {
    scanf("%d", &largura);
    scanf("%d", &altura);

    for (int i = 0; i < altura; i++) {
        scanf("%s", mapa[i]);
    }

    for (int i = 0; i < altura; i++) {
        for (int j = 0; j < largura; j++) {
            visitado[i][j] = false;
        }
    }

    if (bfs(0, 0)) {
        printf("*\n");
    } else {
        printf("!\n");
    }

    return 0;
}
