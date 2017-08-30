#include <stdio.h>
#include <algorithm>
#define MAX 400000
using namespace std;

int a[200000];
int b[200000];

int pat[400000];
int text[400000];

int fail[MAX];
int lena, lenb;
int sim;

void buildFail(void) {
    int j = fail[0] = -1;

    for (int i = 1; i <= lenb; i++) {
        while(j >= 0 && pat[j] != pat[i - 1]) {
            j = fail[j];
        }
        fail[i] = ++j;
    }
}

void kmp(void) {
    buildFail();

    for (int i = 0, k = 0; i < lena; i++) {
        while(k >= 0 && pat[k] != text[i]) {
            k = fail[k];
        }
        if (++k >= lenb) {
            sim = 1;
            k = fail[k];
            break;
        }
    }
}


int main(void) {
    int n;

    int i;

    scanf(" %d", &n);

    for (i = 0; i < n; i++) {
        scanf(" %d", &a[i]);
    }
    for (i = 0; i < n; i++) {
        scanf(" %d", &b[i]);
    }

    sort(a, a + n);
    sort(b, b + n);

    lenb = 0;
    for (i = 1; i < n; i++) {
        pat[lenb++] = a[i] - a[i - 1];
    }

    lena = 0;
    for (i = 1; i < n; i++) {
        text[lena++] = b[i] - b[i - 1];
    }

    text[lena++] = 360000 + (b[0] - b[n - 1]);
    for (i = 1; i < n; i++) {
        text[lena++] = b[i] - b[i - 1];
    }

    /*printf("txt\n");
    for (i = 0; i < lena; i++) {
        printf("%d\n", text[i]);
    }
    printf("pat\n");
    for (i = 0; i < lenb; i++) {
        printf("%d\n", pat[i]);
    } */

    sim = 0;
    kmp();

    if (sim) {
        printf("possible\n");
    } else {
        printf("impossible\n");
    }

    return 0;
}
