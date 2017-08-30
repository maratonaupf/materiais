#include <stdio.h>
#include <vector>
#include <algorithm>
#define pb push_back
#define lli long long int
using namespace std;

/* Exemplo de LCA Em O<NlogN, LogN>, solucao do problema "URI - 1135 - Colônia de Formigas" */

const int MAXN = (int)1e5 + 5;
const int MAX_LOG = 20;

vector <int> g[MAXN];
vector <lli> w[MAXN];

int par[MAXN][MAX_LOG]; // par[x][i] = ancestral de x de distancia 2^i
lli d[MAXN]; // d[x] = distancia da raiz ate o no x
int depth[MAXN]; // depth[x] = profundidade do no x

void DFS(int node, int h, lli dist, int p = -1) {
    par[node][0] = p;
    depth[node] = h;
    d[node] = dist;

    for (int i = 1; i < MAX_LOG; i++) {
        par[node][i] = -1;
        int aux = par[node][i - 1];
        if (aux != -1) {
            par[node][i] = par[aux][i - 1];
        }
    }

    for (int i = 0; i < (int)g[node].size(); i++) {
        int viz = g[node][i];
        if (viz != p) {
            DFS(viz, h + 1, dist + w[node][i], node);
        }
    }
    return;
}

int get_lca(int x, int y) {
    if (depth[x] < depth[y]) {
        swap(x, y);
    }

    for (int i = MAX_LOG - 1; i >= 0; i--) {
        if (par[x][i] != -1 && depth[par[x][i]] >= depth[y]) {
            x = par[x][i];
        }
    }

    if (x == y) {
        return x;
    }

    for (int i = MAX_LOG - 1; i >= 0; i--) {
        if (par[x][i] != par[y][i]) {
            x = par[x][i];
            y = par[y][i];
        }
    }
    return par[x][0];
}

int main(void) {
    int n;
    int a, l;
    int s, t;
    int q;

    while(scanf(" %d", &n) && n) {
        for (int i = 0; i < n; i++) {
            g[i].clear();
            w[i].clear();
        }
        for (int i = 1; i < n; i++) {
            scanf(" %d %d", &a, &l);
            g[a].pb(i);
            w[a].pb(l);
            g[i].pb(a);
            w[i].pb(l);
        }

        DFS(0, 0, 0);
        scanf(" %d", &q);
        for (int i = 0; i < q; i++) {
            if (i != 0) {
                printf(" ");
            }
            scanf(" %d %d", &s, &t);
            int lca = get_lca(s, t);
            lli res = d[s] + d[t] - 2 * d[lca];
            printf("%lld", res);
        }
        printf("\n");
    }
    return 0;
}
