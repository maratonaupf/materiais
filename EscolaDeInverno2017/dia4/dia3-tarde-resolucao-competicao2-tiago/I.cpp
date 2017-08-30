#include <bits/stdc++.h>

using namespace std;

int a[11234];
bool visited[11234];

vector< vector<int> > AdjList;

int cnt;
void dfs(int v) {
    visited[v] = true;
    if (a[v]) cnt++;

    for(int u: AdjList[v]) {
        if (!visited[u]) {
            dfs(u);
        }
    }
}

int main() {
    int L, B;
    scanf("%d%d", &L, &B);

    for(int i=1; i<=L; i++) scanf("%d", &a[i]);
    for(int i=1; i<=L; i++) {
        int x;
        scanf("%d", &x);
        a[i] ^= x;
    }

    AdjList.assign(L+1, vector<int>());
    while(B--) {
        int u, v;
        scanf("%d%d", &u, &v);
        AdjList[u].push_back(v);
        AdjList[v].push_back(u);
    }

    bool possible = true;
    for(int i=1; i<=L; i++) {
        if (!visited[i]) {
            cnt = 0;
            dfs(i);
            if (cnt&1) possible = false;
        }
    }

    puts(possible?"S":"N");

    return 0;
}
