#include <stdio.h>
#include <string.h>
#define MAXN 180
#define MOD 1000000007

int f[15];
int w[15];
int mat[MAXN][MAXN];
int aux[MAXN][MAXN];
int r[MAXN][MAXN];
int n, m, h, s, e, mf, mw;

int get_id(int node, int i, int j) {
    if (i >= mf || j >= mw) {
        return -1;
    }
    return (mf * mw) * node + mw * i + j;
}

void add_edge(int a, int b) {
    int x, y;

    for (int i = 0; i < mf; i++) {
        for (int j = 0; j < mw; j++) {
            x = get_id(a, i, j);
            if (f[b] == 1 && w[b] == 1) {
                y = get_id(b, 0, 0);
            } else if (f[b] == 1 && w[b] == 0) {
                y = get_id(b, 0, j + 1);
            } else if (f[b] == 0 && w[b] == 1) {
                y = get_id(b, i + 1, 0);
            } else {
                y = get_id(b, i + 1, j + 1);
            }
            if (y != -1) {
                mat[x][y] += 1;
            }
        }
    }
    return;
}

void multiply(int r[MAXN][MAXN], int a[MAXN][MAXN], int b[MAXN][MAXN], int n) {
    memset(aux, 0, sizeof(aux));

    for (int k = 0; k < n; k++) {
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                aux[i][j] += (1LL * a[i][k] * b[k][j]) % MOD;
                aux[i][j] %= MOD;
            }
        }
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            r[i][j] = aux[i][j];
        }
    }
    return;
}

void fast_pow(int r[MAXN][MAXN], int base[MAXN][MAXN], int p, int n) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            r[i][j] = 0;
        }
        r[i][i] = 1;
    }

    while(p > 0) {
        if (p & 1) {
            multiply(r, r, base, n);
        }
        multiply(base, base, base, n);
        p /= 2;
    }
    return;
}

int main(void) {
    int a, b;
    int idx;

    scanf(" %d %d %d %d %d %d %d", &n, &m, &h, &s, &e, &mf, &mw);
    s--;
    e--;

    for (int i = 0; i < n; i++) {
        scanf(" %d %d %*d", &f[i], &w[i]);
    }

    memset(mat, 0, sizeof(mat));
    for (int i = 0; i < m; i++) {
        scanf(" %d %d", &a, &b);
        a--;
        b--;
        add_edge(a, b);
        add_edge(b, a);
    }

    idx = get_id(e, 0, 0);
    for (int j = 0; j < n * mf * mw; j++) {
        mat[n * mf * mw][j] = mat[idx][j];
    }
    mat[n * mf * mw][n * mf * mw] = 1;

    fast_pow(r, mat, h, n * mf * mw + 1);

    /*for (int i = 0; i <= n * mf * mw; i++) {
        for (int j = 0; j <= n * mf * mw; j++) {
            printf("%1d ", r[i][j]);
        }
        printf("\n");
    }
    printf("\n"); */

    printf("%d\n", r[n * mf * mw][get_id(s, 0, 0)]);

    return 0;
}
