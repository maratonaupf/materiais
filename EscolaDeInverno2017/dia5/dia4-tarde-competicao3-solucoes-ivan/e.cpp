#include <stdio.h>
#include <vector>
#define pb push_back
#define MAXN 100005
#define INF 0x3f3f3f3f
using namespace std;

struct node {
    int mini[2];
    int next[2];

    node() {
        for (int i = 0; i < 2; i++) {
            next[i] = -1;
            mini[i] = INF;
        }
    }
};

vector <node> trie;

void insert(int x, int idx) {
    int pos = 0;

    for (int i = 31; i >= 0; i--) {
        int bit = (x >> i) & 1;
        if (trie[pos].next[bit] == -1) {
            trie[pos].next[bit] = (int)trie.size();
            trie.pb(node());
            trie[pos].mini[bit] = min(trie[pos].mini[bit], idx);
        }
        pos = trie[pos].next[bit];
    }
    return;
}

int query(int x) {
    int pos = 0;
    int r = 0;
    for (int i = 31; i >= 0; i--) {
        int bit = (x >> i) & 1;
        if (trie[pos].next[1 - bit] != -1) {
            r = trie[pos].mini[1 - bit];
            pos = trie[pos].next[1 - bit];
        } else {
            r = trie[pos].mini[bit];
            pos = trie[pos].next[bit];
        }
    }
    return r;
}

int main(void) {
    int t;
    int n, q;
    int x;

    scanf(" %d", &t);
    for (int caso = 1; caso <= t; caso++) {
        if (caso != 1) {
            printf("\n");
        }
        trie.clear();
        trie.pb(node()); // root
        scanf(" %d %d", &n, &q);
        for (int i = 1; i <= n; i++) {
            scanf(" %d", &x);
            insert(x, i);
        }
        while(q--) {
            scanf(" %d", &x);
            int r = query(x);
            printf("%d\n", r);
        }
    }
    return 0;
}
