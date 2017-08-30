#include <stdio.h>
#include <algorithm>
using namespace std;

const int MAXN = 205;
const int INF = 0x3f3f3f3f;

int dp[MAXN][MAXN];
int b[MAXN];

int solve(int l, int r) {
    if (l > r) {
        return 0;
    }
    if (dp[l][r] != -1) {
        return dp[l][r];
    }

    int aux = INF;
    int cost = b[l - 1] + b[r + 1];
    for (int i = l; i <= r; i++) {
        aux = min(aux, cost + solve(l, i - 1) + solve(i + 1, r));
    }
    dp[l][r] = aux;
    return aux;
}


int main(void) {
    int t;
    int n;
    int a;

    scanf(" %d", &t);
    for (int caso = 1; caso <= t; caso++) {
        scanf(" %d", &n);

        int res = 0;
        for (int i = 1; i <= n; i++) {
            scanf(" %d", &a);
            res += a;
        }
        b[0] = b[n + 1] = 0;
        for (int i = 1; i <= n; i++) {
            scanf(" %d", &b[i]);
        }

        for (int i = 1; i <= n; i++) {
            for (int j = i; j <= n; j++) {
                dp[i][j] = -1;
            }
        }
        res += solve(1, n);
        printf("Case #%d: %d\n", caso, res);
    }
    return 0;
}
