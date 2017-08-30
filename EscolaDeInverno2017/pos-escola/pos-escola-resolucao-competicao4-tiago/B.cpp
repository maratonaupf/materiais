#include <cstdio>

/* Essa implementação resolve o problema com
 * uma BIT (Fenwick Tree). A consulta find(x)
 * nessa estrutura é equivalente a consultar
 * a soma dos elementos de um vetor entre as
 * posições 1 e x.
 */

int n;
int tree[(1<<18)+1];

int add(int ind) {
    while( ind <= n ) {
        tree[ind]++;
        ind += (ind & -ind);
    }
    return 0;
}

int find(int ind) {
    int s = 0;
    while(ind > 0) {
        s += tree[ind];
        ind -= (ind & -ind);
    }
    return s;
}

int main() {

    scanf("%d", &n);
    int val, r=0;
    for (int i=0; i<n; i++) {
        scanf("%d", &val);
        r+=(val-1-find(val));
        add(val);
    }
    printf("%d", r);
    return 0;
}
