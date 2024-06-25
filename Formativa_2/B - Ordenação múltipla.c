// #include <stdio.h>
// #include <stdlib.h>

// void merge(double *arr, int pos_member[][2], int l, int m, int r) {
//     int i, j, k;
//     int n1 = m - l + 1;
//     int n2 = r - m;
//     double L[n1], R[n2];
//     int Lpos_member[n1][2], Rpos_member[n2][2];

//     for (i = 0; i < n1; i++) {
//         L[i] = arr[l + i];
//         Lpos_member[i][0] = pos_member[l + i][0];
//         Lpos_member[i][1] = pos_member[l + i][1];
//     }
//     for (j = 0; j < n2; j++) {
//         R[j] = arr[m + 1 + j];
//         Rpos_member[j][0] = pos_member[m + 1 + j][0];
//         Rpos_member[j][1] = pos_member[m + 1 + j][1];
//     }

//     i = 0;
//     j = 0;
//     k = l;
//     while (i < n1 && j < n2) {
//         if (L[i] > R[j] || (L[i] == R[j] && (Lpos_member[i][0] < Rpos_member[j][0] || (Lpos_member[i][0] == Rpos_member[j][0] && Lpos_member[i][1] < Rpos_member[j][1])))) {
//             arr[k] = L[i];
//             pos_member[k][0] = Lpos_member[i][0];
//             pos_member[k][1] = Lpos_member[i][1];
//             i++;
//         } else {
//             arr[k] = R[j];
//             pos_member[k][0] = Rpos_member[j][0];
//             pos_member[k][1] = Rpos_member[j][1];
//             j++;
//         }
//         k++;
//     }

//     while (i < n1) {
//         arr[k] = L[i];
//         pos_member[k][0] = Lpos_member[i][0];
//         pos_member[k][1] = Lpos_member[i][1];
//         i++;
//         k++;
//     }

//     while (j < n2) {
//         arr[k] = R[j];
//         pos_member[k][0] = Rpos_member[j][0];
//         pos_member[k][1] = Rpos_member[j][1];
//         j++;
//         k++;
//     }
// }

// void mergeSort(double *arr, int pos_member[][2], int l, int r) {
//     if (l < r) {
//         int m = l + (r - l) / 2;

//         mergeSort(arr, pos_member, l, m);
//         mergeSort(arr, pos_member, m + 1, r);
//         merge(arr, pos_member, l, m, r);
//     }
// }

// int main() {
//     int T;
//     scanf("%d", &T);

//     while (T--) {
//         int n, m;
//         scanf("%d %d", &n, &m);

//         int total = n * m;
//         double arra[total];
//         int pos_member[total][2];

//         for (int i = 0; i < total; i++) {
//             scanf("%lf", &arra[i]);
//             pos_member[i][0] = i % n + 1;
//             pos_member[i][1] = i / n + 1;
//         }

//         mergeSort(arra, pos_member, 0, total - 1);

//         for (int i = 0; i < total; i++) {
//             printf("%d,%d ", pos_member[i][0], pos_member[i][1]);
//         }
//         printf("\n");
//     }

//     return 0;
// }


// #include <stdio.h>
// #include <stdlib.h>

// typedef struct {
//     double pontuacao;
//     int membro;
//     int problema;
// } Problema;

// int comparar_pontuacao(const void *a, const void *b) {
//     const Problema *p1 = a;
//     const Problema *p2 = b;
//     if (p1->pontuacao > p2->pontuacao) {
//         return -1;
//     } else if (p1->pontuacao < p2->pontuacao) {
//         return 1;
//     } else {
//         if (p1->membro < p2->membro) {
//             return -1;
//         } else if (p1->membro > p2->membro) {
//             return 1;
//         } else {
//             return p1->problema - p2->problema;
//         }
//     }
// }

// int main() {
//     int T;
//     scanf("%d", &T);

//     for (int t = 0; t < T; t++) {
//         int N, M;
//         scanf("%d %d", &N, &M);

//         double dificuldades[N][M];
//         double somaPontuacoes[M];
        
//         for (int j = 0; j < M; j++) {
//             somaPontuacoes[j] = 0;
//         }

//         for (int j = 0; j < M; j++) {
//             for (int i = 0; i < N; i++) {
//                 scanf("%lf", &dificuldades[i][j]);
//                 somaPontuacoes[j] += dificuldades[i][j];
//             }
//         }

//         Problema problemas[N * M];
//         int contador = 0;
//         for (int j = 0; j < M; j++) {
//             for (int i = 0; i < N; i++) {
//                 problemas[contador].pontuacao = somaPontuacoes[j];
//                 problemas[contador].membro = i + 1;
//                 problemas[contador].problema = j + 1;
//                 contador++;
//             }
//         }

//         qsort(problemas, N * M, sizeof(Problema), comparar_pontuacao);

//         for (int i = 0; i < N * M; i++) {
//             printf("%d,%d", problemas[i].membro, problemas[i].problema);
//             if (i < N * M - 1) {
//                 printf(" ");
//             }
//         }

//         printf("\n");
//     }

//     return 0;
// }


#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int participant;
    int issue;
    double score;
} Issue;

// Comparison function for qsort
int compare(const void *a, const void *b) {
    const Issue *p1 = (const Issue *)a;
    const Issue *p2 = (const Issue *)b;

    // First, sort by score in descending order
    if (p1->score != p2->score) {
        return (p2->score > p1->score) - (p2->score < p1->score);
    }
    // In case of tie in score, sort by participant number in ascending order
    else if (p1->participant != p2->participant) {
        return p1->participant - p2->participant;
    }
    // In case of tie in participant number, sort by issue number in ascending order
    else {
        return p1->issue - p2->issue;
    }
}

int main() {
    int T;
    scanf("%d", &T);

    while (T--) {
        int M, N;
        scanf("%d %d", &M, &N);

        Issue *issues = (Issue *)malloc(M * N * sizeof(Issue));

        // Reading participant scores
        for (int i = 0; i < M; i++) {
            for (int j = 0; j < N; j++) {
                double score;
                scanf("%lf", &score);

                issues[i * N + j].participant = i + 1;
                issues[i * N + j].issue = j + 1;
                issues[i * N + j].score = score;
            }
        }

        // Sorting the issues
        qsort(issues, M * N, sizeof(Issue), compare);

        // Printing the sorted issues
        for (int i = 0; i < M * N; i++) {
            printf("%d,%d", issues[i].participant, issues[i].issue);
            if (i < M * N - 1) {
                printf(" ");
            }
        }
        printf("\n");

        free(issues);
    }

    return 0;
}


