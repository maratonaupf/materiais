#include <bits/stdc++.h>

#define int long long

using namespace std;

int f[20];

struct frac{
    int num;
    int den;
};

frac M[20][20];

frac soma(frac a, frac b) {
    //if (a.den==0 || b.den==0) exit(0);
    int mdc = __gcd(a.den, b.den);
    int mmc = (a.den/mdc) * b.den;
    int num = (mmc/a.den) * a.num + (mmc/b.den) * b.num;
    frac ret;
    ret.num = num;
    ret.den = mmc;
    return ret;
}

frac multiplica(frac a, frac b) {
    frac ret;
    ret.num = a.num*b.num;
    ret.den = a.den*b.den;
    return ret;
}

frac inverte(frac a) {
    frac ret;
    ret.num = a.den;
    ret.den = a.num;
    return ret;
}

frac simplifica(frac a) {
    if (a.num == 0) {
        a.den = 1;
        return a;
    }

    int mdc = __gcd(a.num, a.den);
    a.num /= mdc;
    a.den /= mdc;

    if (a.den < 0) {
        a.num *= -1;
        a.den *= -1;
    }

    return a;
}

main() {
    int m, n;
    frac coef;

    while(scanf("%lld%lld", &m, &n) && (m||n)) {
        for(int i=0; i<m+n; i++) scanf("%lld", &f[i]);
        memset(M, 0, sizeof(M));

        for(int i=0; i<20; i++)
            for(int j=0; j<20; j++)
                M[i][j].num = 0, M[i][j].den = 1;

        for(int i=0; i<m+n; i++) {
            for(int j=0; j<min(n,i+1); j++)
                {M[i][j].num = f[i - j]; M[i][j].den = 1;}
            if (i < m) {
                M[i][n+i].num = -1;
                M[i][n+i].den = 1;
            }
        }
        M[m+n-1][m+n].num = 1;
        M[m+n-1][m+n].den = 1;

        for(int i=0; i<m+n; i++) {
            if (M[i][i].num == 0) {
                //troca linhas
                for(int j=i+1; j<m+n; j++) {
                    if (M[j][i].num == 0) continue;
                    for(int k=0; k<m+n+1; k++)
                        swap(M[i][k], M[j][k]);
                    break;
                }
            }

            for(int j=0; j<m+n; j++) {
                if (j == i) continue;
                coef = multiplica(M[j][i], inverte(M[i][i]));
                coef.num = -coef.num;

                for(int k=0; k<m+n+1; k++) {
                    M[j][k] = soma(M[j][k], multiplica(M[i][k], coef));
                    M[j][k] = simplifica(M[j][k]);
                }
            }
        }

        for(int i=0; i<m+n; i++) {
            M[i][m+n] = multiplica(M[i][m+n], inverte(M[i][i]));
            M[i][m+n] = simplifica(M[i][m+n]);
        }

        bool zero = true;
        for(int i=n; i<m+n; i++) {
            if (M[i][m+n].num == 0) continue;
            zero = false;
            if (M[i][m+n].den != 1) printf("(%lld/%lld,%lld) ", M[i][m+n].num, M[i][m+n].den, i-n);
            else printf("(%lld,%lld) ", M[i][m+n].num, i-n);
        }
        if (zero) printf("(0,0)");
        printf("\n");

        zero = true;
        for(int i=0; i<n; i++) {
            if (M[i][m+n].num == 0) continue;
            zero = false;
            if (M[i][m+n].den != 1) printf("(%lld/%lld,%lld) ", M[i][m+n].num, M[i][m+n].den, i);
            else printf("(%lld,%lld) ", M[i][m+n].num, i);
        }
        if (zero) printf("(0,0)");
        printf("\n\n");
    }

    return 0;
}
