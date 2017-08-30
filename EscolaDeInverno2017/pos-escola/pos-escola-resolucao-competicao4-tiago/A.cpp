#include <bits/stdc++.h>

using namespace std;

bool a[16];

int main() {

    char s[16];
    int n;

    scanf("%d %s", &n, s);
    for(int i=0; i<n; i++) a[ s[i]-'0' ] = true;

    if (!a[1] && !a[2] && !a[3]) puts("NO");
    else if (!a[1] && !a[4] && !a[7] && !a[0]) puts("NO");
    else if (!a[3] && !a[6] && !a[9] && !a[0]) puts("NO");
    else if (!a[7] && !a[0] && !a[9]) puts("NO");
    else puts("YES");

    return 0;
}
