#include <stdio.h>
#include <stdlib.h>

int compare(const void *a, const void *b) {
    return (*(int*)a - *(int*)b);
}

int main() {
    int N, X;
    scanf("%d %d", &N, &X);

    int *Ta = (int*)malloc(N * sizeof(int));
    int *combined = (int*)malloc(N * sizeof(int));
    int combined_count = 0;

    for (int i = 0; i < N; i++) {
        scanf("%d", &Ta[i]);
    }

    qsort(Ta, N, sizeof(int), compare);
    int Tb_max = -1;

    while (N > 0) {
        int Ta_min = Ta[0];

        if (Tb_max != -1 && (Ta_min - Tb_max <= X && Ta_min - Tb_max > 0)) {
            combined[combined_count++] = Ta_min + Tb_max;
            for (int i = 1; i < N; i++) {
                Ta[i-1] = Ta[i];
            }
            N--;
            Tb_max = -1;
        } else {
            Tb_max = Ta_min;
            for (int i = 1; i < N; i++) {
                Ta[i-1] = Ta[i];
            }
            N--;
        }
        if (N > 0) {
          qsort(Ta, N, sizeof(int), compare);
        }
    }

    printf("%d\n", combined_count);
    if (combined_count > 0) {
        for (int i = 0; i < combined_count; i++) {
            printf("%d ", combined[i]);
        }
        printf("\n");
    }
    free(Ta);
    free(combined);
    return 0;
}
