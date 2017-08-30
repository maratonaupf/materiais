#include <stdio.h>
#include <vector>
#include <algorithm>
#include <math.h>
#define pb push_back
#define PI acos(-1)
#define MAXN 200005
using namespace std;

struct pt {
    int x;
    int y;

    pt() {}
    pt (int x, int y):x(x), y(y) {}
};

vector <pt> v;
pt l[MAXN];
pt r[MAXN];

bool comp(const pt &a, const pt &b) {
    return a.x < b.x || (a.x == b.x && a.y < b.y);
}

int ccw(pt a, pt b, pt c) {
    return 1LL * a.x * (b.y - c.y) + 1LL * b.x * (c.y - a.y) + 1LL * c.x * (a.y - b.y) > 0;
}

int cw(pt a, pt b, pt c) {
     return 1LL * a.x * (b.y - c.y) + 1LL * b.x * (c.y - a.y) + 1LL * c.x * (a.y - b.y) < 0;
}

int main(void) {
    int n;
    int x, h;

    scanf(" %d", &n);
    for (int i = 0; i < n; i++) {
        scanf(" %d %d", &x, &h);
        v.pb(pt(x, h));
    }
    sort(v.begin(), v.end(), comp);

    // left
    vector <pt> up;
    up.pb(v[0]);
    l[0] = v[0];
    for (int i = 1; i < n; i++) {
        while((int)up.size() >= 2 && ccw(up[(int)up.size() - 2], up[(int)up.size() - 1], v[i])) {
            up.pop_back();
        }
        l[i] = up.back();
        up.pb(v[i]);
    }
    // right
    up.clear();
    up.pb(v[n - 1]);
    r[n - 1] = v[n - 1];
    for (int i = n - 2; i >= 0; i--) {
        while((int)up.size() >= 2 && cw(up[(int)up.size() - 2], up[(int)up.size() - 1], v[i])) {
            up.pop_back();
        }
        r[i] = up.back();
        up.pb(v[i]);
    }
    for (int i = 0; i < n; i++) {
        double theta = PI;
        if (l[i].y > v[i].y) {
            double alpha = atan((1.0 * v[i].y - l[i].y) / (v[i].x - l[i].x));
            theta -= fabs(alpha);
        }
        if (r[i].y > v[i].y) {
            double alpha = atan((1.0 * v[i].y - r[i].y) / (v[i].x - r[i].x));
            theta -= fabs(alpha);
        }
        printf("%.12lf\n", (theta * 12) / PI);
    }
    return 0;
}
