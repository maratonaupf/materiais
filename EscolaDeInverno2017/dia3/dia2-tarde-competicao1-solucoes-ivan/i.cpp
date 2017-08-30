#include <stdio.h>
#include <vector>
#include <algorithm>
#define pb push_back
using namespace std;

struct spell {
    int a;
    int b;
    int idx;

    spell() {}
    spell(int a, int b, int idx):a(a), b(b), idx(idx) {}

    bool operator <(const spell &x) {
        return a < x.a || (a == x.a && b < x.b);
    }
};

const int INF = 0x3f3f3f3f;

vector <spell> v;
vector <spell> s;
vector <int> pos;

int search(int low, int high, int val) {
    int best = -1;
    while(low <= high) {
        int mid = (low + high) / 2;
        if (pos[mid] > val) {
            best = mid;
            high = mid - 1;
        } else {
            low = mid + 1;
        }
    }
    return best;
}

int solve(spell &x, spell &y) {
    int low = x.a;
    int high = x.b;
    int best = x.b;
    while(low <= high) {
        int mid = (low + high) / 2;
        if (1LL * (x.b - mid) * (y.b - y.a) > 1LL * (y.b - mid) * (x.b - x.a)) {
            low = mid + 1;
        } else {
            best = mid;
            high = mid - 1;
        }
    }
    return best;
}

int is_better(spell &x, spell &y, spell &z) {
    int p1 = solve(x, y);
    int p2 = solve(y, z);

    if (p2 <= p1) {
        return 1;
    }
    return 0;
}

int main(void) {
    int n, m;
    int a, b;
    int x;

    scanf(" %d", &n);
    for (int i = 1; i <= n; i++) {
        scanf(" %d %d", &a, &b);
        v.pb(spell(a, b, i));
    }

    sort(v.begin(), v.end());
    s.pb(v.back());
    for (int i = (int)v.size() - 2; i >= 0; i--) {
        spell aux = s.back();
        if (v[i].a < aux.a && v[i].b > aux.b) {
            s.pb(v[i]);
        }
    }

    v.clear();
    v.pb(s[0]);
    for (int i = 1; i < (int)s.size(); i++) {
        while((int)v.size() >= 2 && is_better(v[(int)v.size() - 2], v[(int)v.size() - 1], s[i])) {
            v.pop_back();
        }
        v.pb(s[i]);
    }

    for (int i = 1; i < (int)v.size(); i++) {
        pos.pb(solve(v[i - 1], v[i]));
    }
    pos.pb(INF);

    scanf(" %d", &m);
    for (int i = 0; i < m; i++) {
        if (i != 0) {
            printf(" ");
        }
        scanf(" %d", &x);
        if (x <= v[0].a) {
            printf("%d", v[0].idx);
        } else {
            int p = search(0, (int)v.size() - 1, x);
            printf("%d", v[p].idx);
        }
    }
    printf("\n");
    return 0;
}
