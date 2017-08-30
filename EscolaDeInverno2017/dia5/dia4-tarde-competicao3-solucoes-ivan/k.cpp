#include <stdio.h>
#include <algorithm>
#define MAXN 100005
#define lli long long int
using namespace std;

int a[MAXN];
int b[MAXN];
int diff[MAXN];

int main(void) {
    int t;
    int n;

    scanf(" %d", &t);
    while(t--) {
        scanf(" %d", &n);
        for (int i = 0; i < n; i++) {
            scanf(" %d", &a[i]);
        }
        for (int i = 0; i < n; i++) {
            scanf(" %d", &b[i]);
            diff[i] = a[i] - b[i];
        }
        sort(diff, diff + n);
        reverse(diff, diff + n);
        lli sum = 0;
        int r = 0;
        for (int i = 0; i < n; i++) {
            if (sum + diff[i] >= 0) {
                r++;
                sum += diff[i];
            }
        }
        printf("%d\n", r);
    }
    return 0;
}
