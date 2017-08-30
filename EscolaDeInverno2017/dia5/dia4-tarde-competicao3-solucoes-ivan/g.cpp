#include <stdio.h>
#include <algorithm>
using namespace std;

int main(void) {
    int a, b;

    scanf(" %d %d", &a, &b);
    printf("%d\n", max(a, b));
    return 0;
}
