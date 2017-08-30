#include <stdio.h>
#define MAX(A,B) ((A) > (B)) ? (A) : (B)

int q[1005];
int g[1005][1005];
int nadj[1005];
int dp[1005];
int order[1005];
int out[1005];

int pilha[1005];
int top;

void push(int a) {
    pilha[++top] = a;
}

int pop(void) {
    return pilha[top--];
}

int main(void) {
    int n;
    int m;
    int k;

    int i, j;
    int x;
    int next;
    int viz;
    int max;

    scanf(" %d", &n);

    while(n) {
        for (i = 1; i <= n; i++) {
            out[i] = 0;
            dp[i] = 0;
        }
        for (i = 1; i <= n; i++) {
            nadj[i] = 0;

            scanf(" %d %d", &q[i], &m);

            for (j = 0; j < m; j++) {
                scanf(" %d", &x);
                g[i][nadj[i]++] = x;
                out[x]++;
            }
        }

        top = -1;
        for (i = 1; i <= n; i++) {
            if (out[i] == 0) {
                push(i);
            }
        }

        k = 1;
        while(top != -1) {
            next = pop();
            order[k++] = next;

            for (i = 0; i < nadj[next]; i++) {
                viz = g[next][i];
                out[viz]--;
                if (out[viz] == 0) {
                    push(viz);
                }
            }
        }

        for (i = 1; i <= n; i++) {
            next = order[i];
            dp[next] += q[next];
            for (j = 0; j < nadj[next]; j++) {
                viz = g[next][j];
                dp[viz] = MAX(dp[viz], dp[next]);
            }
        }

        max = 0;
        for (i = 1; i <= n; i++) {
            if (dp[i] > max) {
                max = dp[i];
            }
        }

        printf("%d\n", max);

        scanf(" %d", &n);
    }
    return 0;
}
