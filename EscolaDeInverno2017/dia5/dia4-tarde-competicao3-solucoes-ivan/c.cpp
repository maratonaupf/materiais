#include <stdio.h>
#include <algorithm>
using namespace std;

int v[15];
int x[10];

int main(void) {
    int t;

    scanf(" %d", &t);
    for (int caso = 1; caso <= t; caso++) {
        for (int i = 0; i < 10; i++) {
            scanf(" %d", &v[i]);
        }
        sort(v, v + 10);
        int a = v[0];
        int b = v[1];
        int c = v[8];
        int d = v[9];
        int e = 0;
        for (int i = 0; i < 10; i++) {
            e += v[i];
        }
        e /= 4;
        x[4] = e - c - a;
        x[5] = d - x[4];
        x[3] = c - x[5];
        x[1] = b - x[3];
        x[2] = a - x[1];
        printf("Case %d:", caso);
        for (int i = 1; i <= 5; i++) {
            printf(" %d", x[i]);
        }
        printf("\n");
    }
    return 0;
}
