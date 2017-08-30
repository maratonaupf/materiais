#include <stdio.h>
#include <vector>
#include <queue>
#define INF 2000000000000LL
#define pb push_back
using namespace std;

/* Exemplo de uso de dijkstra, resolucao do problema "codeforces 20C - Dijkstra?" */

vector <int> g[100005];
vector <int> w[100005];

int pred[100005];
long long int d[100005];
int seq[100005];

priority_queue < pair <long long int, int> > pq;

int main(void) {
    int n, m;
    int x, y, z;
    int next;
    int viz;

    int i;
    int k;

    scanf(" %d %d", &n, &m);

    for (i = 0; i < m; i++) {
        scanf(" %d %d %d", &x, &y, &z);
        g[x].pb(y);
        w[x].pb(z);
        g[y].pb(x);
        w[y].pb(z);
    }

    for (i = 1; i <= n; i++) {
        d[i] = INF;
    }

    d[1] = 0;
    pred[1] = 1;
    pq.push(make_pair(0, 1));

    while(!pq.empty()) {
        long long int cost = -pq.top().first;
        next = pq.top().second;
        pq.pop();

        if (d[next] < cost) {
            continue;
        }

        for (i = 0; i < (int)g[next].size(); i++) {
            viz = g[next][i];
            if (d[next] + w[next][i] < d[viz]) {
                pred[viz] = next;
                d[viz] = d[next] + w[next][i];
                pq.push(make_pair(-d[viz], viz));
            }
        }
    }

    if (d[n] >= INF) {
        printf("-1\n");
    } else {
        k = 0;
        for (i = n; i != 1; i = pred[i]) {
            seq[k++] = i;
        }
        printf("1");
        for (i = k - 1; i >= 0; i--) {
            printf(" %d", seq[i]);
        }
        printf("\n");
    }

    return 0;
}
