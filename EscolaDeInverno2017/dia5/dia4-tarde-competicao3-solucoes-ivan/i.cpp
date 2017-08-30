#include <stdio.h>
#include <vector>
#include <algorithm>
#define pb push_back
#define MAXN 100005
#define MAX_LOG 18
using namespace std;

vector <int> g[MAXN];
vector <int> g2[MAXN];
vector <int> w[MAXN];
int p[MAXN][MAX_LOG];
int h[MAXN];
int tin[MAXN];
int low[MAXN];
int used[MAXN];
int timer;

void DFS(int node, int par = -1) {
    used[node] = 1;
    tin[node] = low[node] = timer++;

    for (int i = 0; i < (int)g[node].size(); i++) {
        int viz = g[node][i];
        if (viz != par) {
            if (used[viz]) {
                low[node] = min(low[node], tin[viz]);
            } else {
                g2[node].pb(viz);
                DFS(viz, node);
                low[node] = min(low[node], low[viz]);
                if (low[viz] > tin[node]) {
                    w[node].pb(1);
                } else {
                    w[node].pb(0);
                }
            }
        }
    }
    return;
}

void DFS2(int node, int dep, int par = -1) {
    h[node] = dep;
    p[node][0] = par;

    for (int i = 1; i < MAX_LOG; i++) {
        p[node][i] = -1;
        if (p[node][i - 1] != -1) {
            p[node][i] = p[p[node][i - 1]][i - 1];
        }
    }
    for (int i = 0; i < (int)g2[node].size(); i++) {
        int viz = g2[node][i];
        if (viz != par) {
            DFS2(viz, dep + w[node][i], node);
        }
    }
    return;
}

int LCA(int x, int y) {
    if (h[x] < h[y]) {
        swap(x, y);
    }
    for (int i = MAX_LOG - 1; i >= 0; i--) {
        if (p[x][i] != -1 && h[p[x][i]] >= h[y]) {
            x = p[x][i];
        }
    }
    if (x == y) {
        return x;
    }
    for (int i = MAX_LOG - 1; i >= 0; i--) {
        if (p[x][i] != p[y][i]) {
            x = p[x][i];
            y = p[y][i];
        }
    }
    return p[x][0];
}

int main(void) {
    int t;
    int n, r;
    int q;
    int a, b;

    scanf(" %d", &t);
    for (int caso = 1; caso <= t; caso++) {
        scanf(" %d %d", &n, &r);
        for (int i = 1; i <= n; i++) {
            g[i].clear();
            w[i].clear();
            g2[i].clear();
            used[i] = 0;
        }
        for (int i = 0; i < r; i++) {
            scanf(" %d %d", &a, &b);
            g[a].pb(b);
            g[b].pb(a);
        }
        DFS(1);
        timer = 0;
        DFS2(1, 0);

        printf("Case %d:\n", caso);
        scanf(" %d", &q);
        while(q--) {
            scanf(" %d %d", &a, &b);
            int lca = LCA(a, b);
            int r = h[a] + h[b] - 2 * h[lca];
            printf("%d\n", r);
        }
    }
    return 0;
}
