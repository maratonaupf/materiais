#include <stdio.h>
#define MAXN 105
#define MOD 10000

/* Exemplo de exponenciacao rapida de matrizes para resolucao
        de recorrencias lineares, solucao do problema
        "URI - 1713 - Teletransporte"
*/

int mat[MAXN][MAXN];
int r[MAXN][MAXN];
int aux[MAXN][MAXN];

void multiply(int a[MAXN][MAXN], int b[MAXN][MAXN], int c[MAXN][MAXN], int n) {
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            aux[i][j] = 0;
        }
    }
    for (int k = 1; k <= n; k++) {
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= n; j++) {
                aux[i][j] += b[i][k] * c[k][j];
                aux[i][j] %= MOD;
            }
        }
    }
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            a[i][j] = aux[i][j];
        }
    }
    return;
}

void fast_exp(int p, int n) {
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            r[i][j] = 0;
        }
        r[i][i] = 1;
    }

    while(p > 0) {
        if (p & 1) {
            multiply(r, r, mat, n);
        }
        multiply(mat, mat, mat, n);
        p /= 2;
    }
    return;
}

int main(void) {
    int n, l;
    int s, t;
    int x;

    while(scanf(" %d %d", &n, &l) != EOF) {
        scanf(" %d %d", &s, &t);
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= n; j++) {
                mat[i][j] = 0;
            }
            for (int j = 0; j < 4; j++) {
                scanf(" %d", &x);
                mat[i][x]++;
            }
        }
        fast_exp(l, n);
        printf("%d\n", r[s][t]);
    }
    return 0;
}
