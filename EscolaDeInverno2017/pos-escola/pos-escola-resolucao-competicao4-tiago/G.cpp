#include <bits/stdc++.h>

using namespace std;

int T, n, c;
int x[100005];

bool ok(int dist) {
    int cows = 1;
    int last = x[0];

    for(int i=1; i<n; i++) {
        if (x[i] - last >= dist) {
            cows++;
            last = x[i];
            if (cows == c) return true;
        }
    }

    return false;
}

int main(){

	scanf("%d", &T);
	while(T--) {
        scanf("%d%d", &n, &c);
        for(int i=0; i<n; i++) scanf("%d", &x[i]);
        sort(x, x+n);

        int lo=1, mid, hi=x[n-1];
        while(hi-lo > 1) {
            mid = (hi+lo)/2;
            if (ok(mid)) lo = mid;
            else hi = mid;
        }
        if (ok(lo)) printf("%d\n", lo);
        else printf("%d\n", hi);
	}

	return 0;
}

