#include <stdio.h>
#include <iostream>
#include <string.h>
#include <set>
#include <string>
#define MAX_LEN 10
using namespace std;

char a[MAX_LEN];
char b[MAX_LEN];
int n, m;
set <string> tree;

void solve(int x, int y, string r) {
    if (x >= n && y >= m) {
        tree.insert(r);
        return;
    }

    if (x < n) {
        solve(x + 1, y, r + a[x]);
    }
    if (y < m) {
        solve(x, y + 1, r + b[y]);
    }
    return;
}

int main(void) {
    int t;

    scanf(" %d", &t);
    while(t--) {
        tree.clear();
        scanf(" %s %s", a, b);
        n = strlen(a);
        m = strlen(b);
        solve(0, 0, "");

        for (set<string>::iterator it = tree.begin(); it != tree.end(); it++) {
            cout << (*it) << endl;
        }
        printf("\n");
    }
    return 0;
}
