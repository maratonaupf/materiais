#include <stdio.h>
#include <vector>
#include <set>
#define pb push_back
#define MAXN 10005
using namespace std;

struct pt {
    int x;
    int y;
    int idx;

    pt() {}
    pt(int x, int y, int idx):x(x), y(y), idx(idx) {}
};

vector <pt> v;
int used[MAXN];
set <pt> tree;

bool operator <(const pt &a, const pt &b) {
    return a.x < b.x || a.x == b.x && a.y < b.y || a.x == b.x && a.y < b.y && a.idx < b.idx;
}

void DFS(int pos) {
    used[pos] = 1;
    int x = v[pos].x;
    int y = v[pos].y;
    int idx = v[pos].idx;
    tree.erase(pt(x, y, idx));

    for (int i = -1; i <= 1; i++) {
        for (int j = -1; j <= 1; j++) {
            set<pt>::iterator it = tree.lower_bound(pt(x + i, y + j, 0));
            int nx = (*it).x;
            int ny = (*it).y;
            if (nx != x + i || ny != y + j) {
                continue;
            }
            if (it != tree.end() && !used[(*it).idx]) {
                DFS((*it).idx);
            }
        }
    }
    return;
}

int main(void) {
    int t;
    int n;
    int x, y;

    scanf(" %d", &t);
    for (int caso = 1; caso <= t; caso++) {
        scanf(" %d", &n);
        v.clear();
        tree = set<pt>();

        for (int i = 0; i < n; i++) {
            scanf(" %d %d", &x, &y);
            v.pb(pt(x, y, i));
            tree.insert(pt(x, y, i));
            used[i] = 0;
        }

        int r = 0;
        for (int i = 0; i < n; i++) {
            if (!used[i]) {
                r++;
                DFS(i);
            }
        }
        printf("Case %d: %d\n", caso, r);
    }
    return 0;
}
