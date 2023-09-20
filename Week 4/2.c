#include <stdio.h>

void Elimination(int n, float mat[][n + 1]) {
    int i, j, k;
    float factor, sum;

    for (i = 0; i < n; i++) {
        for (j = i + 1; j < n; j++) {
            factor = mat[j][i] / mat[i][i];
            for (k = i; k <= n; k++) {
                mat[j][k] -= factor * mat[i][k];
            }
        }
    }

    float x[n];
    x[n - 1] = mat[n - 1][n] / mat[n - 1][n - 1];

    for (i = n - 2; i >= 0; i--) {
        sum = 0;
        for (j = i + 1; j < n; j++) {
            sum += mat[i][j] * x[j];
        }
        x[i] = (mat[i][n] - sum) / mat[i][i];
    }

    printf("Solution:\n");
    for (i = 0; i < n; i++) {
        printf("x%d = %.1f\n", i, x[i]);
    }
}

int main() {
    int n;
    printf("Enter No. Of Linear Equations: ");
    scanf("%d", &n);

    float mat[n][n + 1];

    printf("Enter The Elements Of The Augmented Matrix:\n");
    for (int i = 0; i < n; i++) {
        for (int j = 0; j <= n; j++) {
            scanf("%f", &mat[i][j]);
        }
    }

    Elimination(n, mat);

    return 0;
}
