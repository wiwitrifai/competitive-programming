#include <bits/stdc++.h>


using namespace std;

const int N = 1e6 + 5;
const double eps = 1e-9;

struct point {
  int x, y;
  point(int x = 0, int y = 0) : x(x), y(y) {}

};
long long cross(point a, point b, point c) {
  return 1LL * (a.x - b.x) * (c.y - b.y) - 1LL * (a.y - b.y) * (c.x - b.x);
}

int q[N], id[N], ans[N];

int main() {
  int n;
  vector<point> hull;
  vector<double> muncul;
  scanf("%d", &n);
  for (int i = 0; i < n; i++) {
    point p;
    p.x = i+1;
    scanf("%d", &p.y);
    if (hull.empty())
      muncul.push_back(0.0);
    else {
      int l = 0, r = (int)hull.size()-1;
      while (l < r) {
        int m = (l + r) >> 1;
        if (cross(hull[m], hull[m+1], p) <= 0)
          r = m;
        else
          l = m+1;
      }
      double h = (double)(hull[l].y - p.y) * p.x / (p.x - hull[l].x) + (double)p.y;
      muncul.push_back(h);
    }
    int s;
    while ((s = hull.size()) > 1 && cross(hull[s-2], hull[s-1], p) <= 0) hull.pop_back();
    hull.push_back(p);
  }
  sort(muncul.begin(), muncul.end());
  int m;
  scanf("%d", &m);
  for (int i = 0; i < m; i++) {
    scanf("%d", q+i);
    id[i] = i;
  }
  sort(id, id+m, [](int le, int ri) { return q[le] < q[ri]; });
  for (int i = 0, j = 0; i < m; i++) {
    while (j < n && muncul[j] + eps < q[id[i]]) j++;
    ans[id[i]] = j;
  }
  for (int i = 0; i < m; i++)
    printf("%d\n", ans[i]);
  return 0;
}