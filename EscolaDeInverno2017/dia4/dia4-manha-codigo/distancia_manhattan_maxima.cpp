#include <stdio.h>
#include <algorithm>
using namespace std;

/* Exemplo de calculo de distancia maxima entre pontos
    considerando distancia do tipo manhatann
    solucao do problema "codeforces 366E - Dima and Magic Guitar" */

const int MAX_K = 10;
const int INF = 0x3f3f3f3f;

int v[MAX_K][1 << 2];

int comp(int mask) {
    return ((1 << 2) - 1) ^ mask;
}

int solve(int x, int y) {
    int aux = 0;
    for (int mask = 0; mask < 1 << 2; mask++) {
        aux = max(aux, v[x][mask] + v[y][comp(mask)]);
    }
    return aux;
}

int get_val(int i, int j, int mask) {
    if (mask & 1) {
        j *= -1;
    }
    if ((mask >> 1) & 1) {
        i *= -1;
    }
    return i + j;
}

int main(void) {
    int n, m, k, s;
    int x, y;

    for (int i = 0; i < MAX_K; i++) {
        for (int j = 0; j < 1 << 2; j++) {
            v[i][j] = -INF;
        }
    }

    scanf(" %d %d %d %d", &n, &m, &k, &s);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            scanf(" %d", &x);
            for (int mask = 0; mask < 1 << 2; mask++) {
                int aux = get_val(i, j, mask);
                v[x][mask] = max(v[x][mask], aux);
            }
        }
    }

    int res = 0;
    scanf(" %d", &x);
    while(s-- > 1) {
        scanf(" %d", &y);
        res = max(res, solve(x, y));
        x = y;
    }
    printf("%d\n", res);
    return 0;
}
