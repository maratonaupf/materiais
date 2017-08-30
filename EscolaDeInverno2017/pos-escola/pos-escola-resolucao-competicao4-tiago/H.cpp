#include <bits/stdc++.h>

using namespace std;

int main() {

    int a, b, c=0, n, ans = 0;
    scanf("%d%d%d", &n, &a, &b);

    while(n--) {
        int t;
        scanf("%d", &t);
        if (t == 2) {
            if (b == 0) ans+=2;
            else b--;
        } else {
            if (a) a--;
            else if (b) {
                b--;
                c++;
            } else if (c) c--;
            else ans++;
        }
    }

    printf("%d\n", ans);

    return 0;
}
