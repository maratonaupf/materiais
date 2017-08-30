#include <bits/stdc++.h>

using namespace std;

bool hole[1000005];

int main() {
    int n, m, k, u, v, h;
    scanf("%d%d%d", &n, &m, &k);

    int ans = 1e9;
    for(int i=1; i<=m; i++) {
        scanf("%d", &h);
        hole[h] = true;
    }

    int cur = 1;
    for(int i=1; i<=k; i++) {
        scanf("%d %d", &u, &v);

        if (hole[cur]) break;

        if (cur == u) cur = v;
        else if (cur == v) cur = u;

        if (hole[cur]) break;
    }

    printf("%d\n", cur);

    return 0;
}
