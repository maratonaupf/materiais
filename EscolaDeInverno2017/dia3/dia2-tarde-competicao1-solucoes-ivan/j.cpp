#include <stdio.h>
#include <algorithm>
#define lli long long int
#define MAXN 1000005
using namespace std;

int v[MAXN];

int main(void) {
    int t;
    int n, k;

    scanf(" %d", &t);
    while(t--) {
        scanf(" %d %d", &n, &k);
        int maxi = 0;
        for (int i = 0; i < n; i++) {
            scanf(" %d", &v[i]);
            maxi = max(maxi, v[i]);
        }

        lli low = 0;
        lli high = 1LL * maxi * n;
        lli best = -1;
        while(low <= high) {
            lli mid = (low + high) / 2;
            int used = 1;
            int maxi = 0;
            int counter = 0;
            for (int i = 0; i < n; i++) {
                maxi = max(maxi, v[i]);
                if (1LL * (counter + 1) * maxi <= mid) {
                    counter++;
                } else {
                    if (counter == 0) {
                        used = k + 1;
                        break;
                    } else {
                        i--;
                        used++;
                        maxi = 0;
                        counter = 0;
                    }
                }
            }
            if (used <= k) {
                best = mid;
                high = mid - 1;
            } else {
                low = mid + 1;
            }
        }
        printf("%lld\n", best);
    }
    return 0;
}
