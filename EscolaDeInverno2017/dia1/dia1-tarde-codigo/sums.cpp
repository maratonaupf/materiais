#include <stdio.h>
#include <queue>
#define MAXN 50005
#define INF 0x3f3f3f3f
using namespace std;

/* Solucao do problema SUMS da POI  http://main.edu.pl/en/archive/oi/10/sum */

int v[MAXN];
int d[MAXN];

int main(void) {
    int n;
    int k;
    int b;
    priority_queue <pair <int, int> > pq;

    scanf(" %d", &n);
    for (int i = 0; i < n; i++) {
        scanf(" %d", &v[i]);
    }
    d[0] = 0;
    for (int i = 1; i < v[0]; i++) {
        d[i] = INF;
    }
    pq.push(make_pair(0, 0));
    while(!pq.empty()) {
        int cost = pq.top().first;
        int next = pq.top().second;
        pq.pop();

        if (d[next] < cost) {
            continue;
        }
        for (int i = 1; i < n; i++) {
            int viz = (next + v[i]) % v[0];
            if (d[viz] > d[next] + v[i]) {
                d[viz] = d[next] + v[i];
                pq.push(make_pair(-d[viz], viz));
            }
        }
    }
    scanf(" %d", &k);
    while(k--) {
        scanf(" %d", &b);
        if (d[b % v[0]] <= b) {
            printf("TAK\n");
        } else {
            printf("NIE\n");
        }
    }
    return 0;
}
