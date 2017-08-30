#include <stdio.h>

int main(void) {
    int l, r;

    scanf(" %d %d", &l, &r);
    if (l == r) {
        printf("%d\n", l);
    } else {
        printf("2\n");
    }
}
