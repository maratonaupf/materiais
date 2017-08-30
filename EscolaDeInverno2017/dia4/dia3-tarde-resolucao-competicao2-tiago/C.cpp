#include <bits/stdc++.h>
#define INF 0x3f3f3f3f

using namespace std;

typedef long long ll;

int n, k;
pair<ll, ll> v[1024];
ll sumW[1024], sumXW[1024];

ll dp[1024][1024];

int hullSize, hullPtr;
struct line {
    // y = m*x + n

    ll m, n;

    line(){}
    line(ll _m, ll _n):
        m(_m), n(_n){}

} hull[1024];

ll y(int idx, ll x) {
    return hull[idx].m*x + hull[idx].n;
}

double intersection(line t, line r) {
    double num = double(r.n - t.n);
    double den = double(t.m - r.m);
    return num / den;
}

void insert_line(line l) {
    while(hullSize >= 2 && ( intersection(l, hull[hullSize-2]) < intersection(hull[hullSize-1], hull[hullSize-2]) ) ) {
        if (hullPtr == hullSize - 1) hullPtr--;
        hullSize--;
    }

    hull[ hullSize++ ] = l;
}

ll minimize(ll x) {
    while(hullPtr+1 < hullSize && y(hullPtr, x) > y(hullPtr+1, x)) hullPtr++;
    return y(hullPtr, x);
}

int main() {
    while(scanf("%d%d", &n, &k)!=EOF) {
        for(int i=0; i<n; i++) scanf("%lld%lld", &v[i].first, &v[i].second);

        sumW[0] = ll(v[0].second);
        sumXW[0] = ll(v[0].first)*ll(v[0].second);
        for(int i=1; i<n; i++) {
            sumW[i] = sumW[i-1] + ll(v[i].second);
            sumXW[i] = sumXW[i-1] + ll(v[i].first)*ll(v[i].second);
        }

        memset(dp, INF, sizeof(dp));

        for(int i=0; i<n; i++)
            dp[1][i] = v[i].first*sumW[i] - sumXW[i];

        for(int i=2; i<=k; i++) {
            hullSize = hullPtr = 0;
            for(int j=i-1; j<n; j++) {
                insert_line( line(-sumW[j-1], dp[i-1][j-1] + sumXW[j-1]) );
                dp[i][j] = minimize( v[j].first ) + v[j].first*sumW[j] - sumXW[j];

                // the loop below is substituted by the convex hull trick
                //
                // for(int p=0; p<j; p++) {
                //     dp[i][j] = min(dp[i][j], dp[i-1][p] + v[j].first*(sumW[j] - sumW[p]) - sumXW[j] + sumXW[p]);
                // }
            }
        }

        printf("%lld\n", dp[k][n-1]);
    }

	return 0;
}
