#include <stdio.h>
#include <vector>
#include <algorithm>
#define pb push_back
using namespace std;

int mat[5][5];
int row[5];
int col[5];
int used[20];
vector <int> v;
vector <pair <int, int> > f;

int check(void) {
    for (int i = 1; i < 4; i++) {
        if (row[i] != row[i - 1]) {
            return 0;
        }
        if (col[i] != col[i - 1]) {
            return 0;
        }
    }
    return row[0] == col[0];
}

int main(void) {
    int t;

    scanf(" %d", &t);
    for (int caso = 1; caso <= t; caso++) {
        printf("Case %d:\n", caso);
        v.clear();
        f.clear();
        for (int i = 0; i < 4; i++) {
            row[i] = col[i] = 0;
        }
        for (int i = 1; i <= 16; i++) {
            used[i] = 0;
        }
        for (int i = 0; i < 4; i++) {
            for (int j = 0; j < 4; j++) {
                scanf(" %d", &mat[i][j]);
                if (mat[i][j] != -1) {
                    used[mat[i][j]] = 1;
                    row[i] += mat[i][j];
                    col[j] += mat[i][j];
                } else {
                    f.pb(make_pair(i, j));
                }
            }
        }
        for (int i = 1; i <= 16; i++) {
            if (!used[i]) {
                v.pb(i);
            }
        }
        do {
            for (int i = 0; i < (int)v.size(); i++) {
                int x = f[i].first;
                int y = f[i].second;
                mat[x][y] = v[i];
                row[x] += v[i];
                col[y] += v[i];
            }
            if (check()) {
                break;
            }
            for (int i = 0; i < (int)v.size(); i++) {
                int x = f[i].first;
                int y = f[i].second;
                row[x] -= v[i];
                col[y] -= v[i];
            }
        } while(next_permutation(v.begin(), v.end()));

        for (int i = 0; i < 4; i++) {
            for (int j = 0; j < 4; j++) {
                if (j != 0) {
                    printf(" ");
                }
                printf("%d", mat[i][j]);
            }
            printf("\n");
        }
    }
    return 0;
}
