#include <stdio.h>
#include <vector>
#include <algorithm>
#include <math.h>
#define pb push_back
using namespace std;

/* Exemplo de calculo de convex hull, solucao do problema
    "SPOJBR - CERCAMG - Cercadinho de Plantas" */

struct pt {
    int x;
    int y;

    pt() {}
    pt(int x, int y):x(x), y(y) {}
};

bool operator <(const pt &a, const pt &b) {
    return a.x < b.x || (a.x == b.x && a.y < b.y);
}

bool ccw(pt &a, pt &b, pt &c) {
    return a.x * (b.y - c.y) + b.x * (c.y - a.y) + c.x * (a.y - b.y) > 0;
}

bool cw(pt &a, pt &b, pt &c) {
    return a.x * (b.y - c.y) + b.x * (c.y - a.y) + c.x * (a.y - b.y) < 0;
}

double dist(pt &a, pt &b) {
    int dx = a.x - b.x;
    int dy = a.y - b.y;
    return sqrt(dx * dx + dy * dy);
}

double convex_hull(vector <pt> &v) {
    vector <pt> up;
    vector <pt> down;

    sort(v.begin(), v.end());
    up.pb(v[0]);
    down.pb(v[0]);
    for (int i = 1; i < (int)v.size(); i++) {
        while(up.size() >= 2 && !cw(up[up.size() - 2], up[up.size() - 1], v[i])) {
            up.pop_back();
        }
        while(down.size() >= 2 && !ccw(down[down.size() - 2], down[down.size() - 1], v[i])) {
            down.pop_back();
        }
        up.pb(v[i]);
        down.pb(v[i]);
    }

    for (int i = down.size() - 2; i > 0; i--) {
        up.pb(down[i]);
    }
    double res = 0;
    int n = up.size();
    //printf("n = %d\n", n);
    for (int i = 0; i < n; i++) {
        res += dist(up[i], up[(i + 1) % n]);
        //printf("dist = %lf\n", dist(up[i], up[(i + 1) % n]));
    }
    return res;
}

int main(void) {
    int a, d;
    int x, y;
    vector <pt> v;

    while(scanf(" %d %d", &a, &d) != EOF) {
        v.clear();
        for (int i = 0; i < a; i++) {
            scanf(" %d %d", &x, &y);
            v.pb(pt(x, y));
        }

        double res = convex_hull(v);
        printf("%.2lf\n", res);
    }
    return 0;
}
