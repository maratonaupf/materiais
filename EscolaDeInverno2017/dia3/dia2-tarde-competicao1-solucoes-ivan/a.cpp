#include <stdio.h>
#include <stdlib.h>

int gcd(int a, int b) {
    if (!b) {
        return a;
    }
    return gcd(b, a % b);
}

int main(void) {
    int n, x;
    int d = 0;
    int a;

    scanf(" %d %d", &n, &x);
    x = abs(x);
    for (int i = 0; i < n; i++) {
        scanf(" %d", &a);
        d = gcd(d, a);
    }

    if (x == 0 || x % d == 0) {
        printf("YES\n");
    } else {
        printf("NO\n");
    }
    return 0;
}
