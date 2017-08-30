#include <stdio.h>
#include <queue>
#define MAXN 105
#define INF 0x3f3f3f3f
using namespace std;

char grid[MAXN][MAXN];
int d1[MAXN][MAXN];
int d2[MAXN][MAXN];
queue <pair <int, int> > fila;

int dx[] = {0, 1, 0, -1};
int dy[] = {1, 0, -1, 0};

int is_in(int x, int y, int n, int m) {
	return x >= 0 && x < n && y >= 0 && y < m;
}

void BFS1(int n, int m) {
	while(!fila.empty()) {
		int x = fila.front().first;
		int y = fila.front().second;
		fila.pop();

		for (int i = 0; i < 4; i++) {
			int nx = x + dx[i];
			int ny = y + dy[i];
			if (is_in(nx, ny, n, m) && grid[nx][ny] != '#' && d1[nx][ny] > 1 + d1[x][y]) {
				d1[nx][ny] = 1 + d1[x][y];
				fila.push(make_pair(nx, ny));
			}
		}
	}
	return;
}

void BFS2(int sx, int sy, int n, int m) {
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			d2[i][j] = INF;
		}
	}
	d2[sx][sy] = 0;
	fila.push(make_pair(sx, sy));
	while(!fila.empty()) {
		int x = fila.front().first;
		int y = fila.front().second;
		fila.pop();

		for (int i = 0; i < 4; i++) {
			int nx = x + dx[i];
			int ny = y + dy[i];
			if (is_in(nx, ny, n, m) && grid[nx][ny] != '#' && d2[nx][ny] > 1 + d2[x][y]) {
				d2[nx][ny] = 1 + d2[x][y];
				fila.push(make_pair(nx, ny));
			}
		}
	}
	return;
}


int main(void) {
	int t;
	int n, m;
	int sx, sy;
	int fx, fy;

	scanf(" %d", &t);
	while(t--) {
		scanf(" %d %d", &n, &m);
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				d1[i][j] = INF;
			}
		}
		for (int i = 0; i < n; i++) {
			scanf(" %s", grid[i]);
			for (int j = 0; j < m; j++) {
				if (grid[i][j] == 'S') {
					sx = i;
					sy = j;
				} else if (grid[i][j] == 'X') {
					fx = i;
					fy = j;
				} else if (grid[i][j] == '*') {
					d1[i][j] = 0;
					fila.push(make_pair(i, j));
				}
			}
		}
		BFS1(n, m);
		BFS2(sx, sy, n, m);

		if (d1[fx][fy] <= d2[fx][fy]) {
			printf("no\n");
		} else {
			printf("yes\n");
		}
	}
	return 0;
}
