#include <stdio.h>
#include <algorithm>
#define MAXN 2005
#define INF 0x3f3f3f3f
using namespace std;

int v[MAXN];
int small[MAXN]; // index of next target if using small
int big[MAXN]; // index of next target if using big
int dp[MAXN][MAXN];
int n;

int solve(int pos, int maxi) {
	if (pos >= n) {
		return 0;
	}
	if (dp[pos][maxi] != -1) {
		return dp[pos][maxi];
	}
	int aux = 1 + solve(small[pos], maxi);
	if (maxi > 0) {
		aux = min(aux, solve(big[pos], maxi - 1));
	}
	dp[pos][maxi] = aux;
	return aux;
}


int main(void) {
	int t;
	int p, q;

	scanf(" %d", &t);
	while(t--) {
		scanf(" %d %d %d", &n, &p, &q);
		q = min(q, n);
		for (int i = 0; i < n; i++) {
			scanf(" %d", &v[i]);
		}
		sort(v, v + n);
		int low = 1;
		int high = INF;
		int best = INF;
		while(low <= high) {
			int mid = (low + high) / 2;
			for (int i = 0; i < n; i++) {
				int next = v[i] + mid - 1;
				small[i] = big[i] = n;
				for (int j = i; j < n; j++) {
					if (v[j] > next) {
						small[i] = j;
						break;
					}
				}
				next = v[i] + 2 * mid - 1;
				for (int j = i; j < n; j++) {
					if (v[j] > next) {
						big[i] = j;
						break;
					}
				}
			}

			for (int i = 0; i < n; i++) {
				for (int j = 0; j <= q; j++) {
					dp[i][j] = -1;
				}
			}
			int need = solve(0, q);
			if (need <= p) {
				best = mid;
				high = mid - 1;
			} else {
				low = mid + 1;
			}
		}
		printf("%d\n", best);
	}
	return 0;
}
