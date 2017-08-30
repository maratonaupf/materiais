#include <bits/stdc++.h>

char s[10005], t[10005];
int dp[10005];

int solve(int n) {
    if (n <= 0) return 0;
    if (dp[n] != -1) return dp[n];

    bool reached[300];
    memset(reached, false, sizeof(reached));
    for(int i=0; i<n; i++) {
        reached[solve(i-2) ^ solve(n-i-3)] = true;
    }

    for(int i=0; ; i++) {
        if (!reached[i]) return dp[n] = i;
    }
}

int main() {
    memset(dp, -1, sizeof(dp));

    int n;
    while(1) {
        scanf("%d", &n); if (!n) break;
        scanf("%s", s); strcpy(t, s);
        int len=strlen(s), hole=0, nim=0;
        for(int i=0; i<n; i++) {
            if (i!=n-1 && s[i]==s[i+1] && s[i]=='X') nim = 1;
            if (i<n-2 && s[i]==s[i+2] && s[i]=='X') nim = 1;
            if (s[i] == 'X') {
                for(int j=i-2; j<=i+2; j++) {
                    if (j>=0 && j<n) t[j] = 'X';
                }
            }
        }
        if (nim) {
            puts("S");
            continue;
        }
        for(int i=0; i<n; i++) {
            if (t[i]=='.') hole++;
            else {
                nim ^= solve(hole);
                hole = 0;
            }
        }
        nim ^= solve(hole);

        puts(nim?"S":"N");
    }

    return 0;
}
