#include <bits/stdc++.h>
#define INF 1e18
#define MAX 128

using namespace std;

typedef long long ll;

ll c[MAX], s[MAX];
ll dp[MAX][MAX];

ll sum(int i, int j) {
    return (s[j] - ((i==0)?0:s[i-1]) + 200) % 100;
}

ll solve(int i, int j) {
    if (i==j) return 0;
    if (dp[i][j] != -1) return dp[i][j];

    ll ans = INF;
    for(int k=i; k<j; k++) {
        ans = min(ans, solve(i,k) + solve(k+1,j) + sum(i,k)*sum(k+1,j));
    }

    return dp[i][j] = ans;
}

int main() {

    int n;
    while(scanf("%d", &n) != EOF) {
        for(int i=0; i<n; i++) scanf("%lld", &c[i]);
        s[0] = c[0]; for(int i=1; i<n; i++) s[i] = (s[i-1] + c[i]) % 100;
        memset(dp, -1, sizeof(dp));
        printf("%lld\n", solve(0, n-1));
    }

    return 0;
}
