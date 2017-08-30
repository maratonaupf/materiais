#include <stdio.h>
#include <algorithm>
using namespace std;

/* Existem varias solucoes. Uma possivel eh por programacao dinamica. Seja
	dp[x] = numero de cortes maximo sobrando uma fita de tamanho x. Entao a resposta
	sera dp[n]. Para cada estado da programacao dinamica tentamos fazer um corte e
	armazenamos o melhor.
	Outra solucao eh montar como um equaçao. Sejam x, y, z a quantidade de cortes de
	tamanhos a, b, c respectivamente. Entao devemos achar o maximo de x + y + z
	sujeito a
	a * x + b * y + c * z = n
	Como os limites sao pequenos, podemos iterar em x e y e achar z pela formula */

const int INF = ((int)1e9);
const int MAXN = 4005;
int dp[MAXN]; // tabela de programacao dinamica
int n, a, b, c;

int solve(int x) {
	if (x < 0) {
		return -INF;
	}
	if (x == 0) {
		return 0;
	}
	if (dp[x] != -1) {
		return dp[x];
	}
	int aux = -INF;
	aux = max(aux, 1 + solve(x - a));
	aux = max(aux, 1 + solve(x - b));
	aux = max(aux, 1 + solve(x - c));
	dp[x] = aux;
	return aux;
}

int main(void) {
	scanf(" %d %d %d %d", &n, &a, &b, &c);
	for (int i = 0; i <= n; i++) {
		dp[i] = -1; // valor de contorno indicando que nao computamos o valor
	}
	int res = solve(n);
	printf("%d\n", res);
	return 0;
}
