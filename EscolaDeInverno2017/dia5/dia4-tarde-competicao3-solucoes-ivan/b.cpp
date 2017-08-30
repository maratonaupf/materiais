#include <stdio.h>
#include <vector>
#include <algorithm>
#define pb push_back
#define MAXN 1005
using namespace std;

vector <int> g[MAXN];
int used[MAXN];
int mt[MAXN];
int match;
//

int kuhn(int node) {
    if (used[node]) {
        return 0;
    }
    used[node] = 1;

    for (int i = 0; i < (int)g[node].size(); i++) {
        int viz = g[node][i];
        if (mt[viz] == -1 || kuhn(mt[viz])) {
            mt[viz] = node;
            return 1;
        }
    }
    return 0;
}

int main(void) {
    int n;
    int k;
    int x;

    scanf(" %d", &n);
    for (int i = 0; i < n; i++) {
        mt[i] = -1;
        scanf(" %d", &k);
        while(k--) {
            scanf(" %d", &x);
            g[i].pb(x);
        }
    }
    match = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            used[j] = 0;
        }
        if (kuhn(i)) {
            match++;
        }
    }
    printf("%d\n", n - match);
    return 0;
}
