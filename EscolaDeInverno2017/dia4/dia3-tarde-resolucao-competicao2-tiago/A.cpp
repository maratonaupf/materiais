#include <bits/stdc++.h>

using namespace std;

int main() {
    int n, q;
    scanf("%d%d", &n, &q);

    vector<int> S, E;
    for(int i=0; i<n; i++) {
        int a, b, c, d;
        scanf("%d%d%d%d", &a, &b, &c, &d);
        S.push_back(min(a,c));
        E.push_back(max(a,c));
    }

    sort(S.begin(), S.end());
    sort(E.begin(), E.end());

    while(q--) {
        int a, b, ans=0;
        scanf("%d%d", &a, &b);

        ans += lower_bound(S.begin(), S.end(), a) - S.begin();
        ans += E.end() - upper_bound(E.begin(), E.end(), b);

        printf("%d\n", ans);
    }

    return 0;
}
