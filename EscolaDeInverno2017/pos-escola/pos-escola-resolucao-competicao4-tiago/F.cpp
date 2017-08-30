#include <bits/stdc++.h>

using namespace std;

typedef vector<int> vi;

int dx[] = {-2, -2, -1, -1, 1, 1, 2, 2};
int dy[] = {-1, 1, -2, 2, -2, 2, -1, 1};
int knightMove(int pos, int i) {
    pos--;
    int x = pos/8 + dx[i];
    int y = pos%8 + dy[i];
    if (x<0 || x>7 || y<0 || y>7) return -1;
    else return x*8 + y + 1;
}

int bfs(vi v) {

    queue<vi> q;
    q.push(v);

    map<vi, int> dist;
    dist[v] = 1;

    while(!q.empty()) {
        v = q.front(); q.pop();
        int curDist = dist[v];

        for(int i=0; i<8; i++) {
            bool valid = true;
            vi u = v;
            u[0] = knightMove(v[0], i);
            if (u[0] == -1) continue;

            for(int j=64; j>56 && valid; j--) {
                if (u[j]) {
                    if (u[0] == j) u[j] = 0;
                    else valid = false;
                }
            }

            for(int j=56; j>0 && valid; j--) {
                if (u[j] && j!=u[0]) u[j+8] = 1;
                u[j] = 0;
            }

            if (valid && dist[u] == 0) {
                dist[u] = curDist + 1;
                q.push(u);
            }
        }
    }

    int ans = 10;
    v.assign(65,0);
    for(int i=1; i<=64; i++) {
        v[0] = i;
        if (dist[v] == 0) continue;
        else ans = min(ans, dist[v] - 1);
    }

    return ans;
}

int main() {

    int p;
    while(scanf("%d", &p) && p) {
        vi v; v.assign(65,0);
        for(int i=0; i<p; i++) {
            int pos;
            scanf("%d", &pos);
            v[pos]=1;
        }
        scanf("%d", &v[0]);

        int ans = bfs(v);
        if (ans < 10) printf("%d\n", ans);
        else puts("impossible");
    }

    return 0;
}
