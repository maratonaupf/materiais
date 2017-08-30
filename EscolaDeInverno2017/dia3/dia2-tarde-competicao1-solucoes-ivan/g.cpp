#include <stdio.h>
#include <algorithm>
using namespace std;

/* Basta contarmos quantas vezes aparece cada letra na palavra inteira e fazermos algumas
	divisoes, tomando cuidado pois o ultimo 'n' de uma palavra pode ser usado como
	primeiro 'n' de uma outra */

char s[105];

int main(void) {
	int n, i, e, t;
	n = i = e = t = 0;
	scanf(" %s", s);
	for (int k = 0; s[k] != '\0'; k++) {
		if (s[k] == 'n') {
			n++;
		} else if (s[k] == 'i') {
			i++;
		} else if (s[k] == 'e') {
			e++;
		} else if (s[k] == 't') {
			t++;
		}
	}

	n--;
	int res = max(0, min(n / 2, min(i, min(e / 3, t))));
	printf("%d\n", res);
	return 0;
}
