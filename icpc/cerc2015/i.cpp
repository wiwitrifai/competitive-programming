#include <bits/stdc++.h>

using namespace std;

struct point {
  int x, y;
  point(double x = 0, double y = 0) : x(x), y(y) {}
};

struct line { double a, b, c; };

void pointToLine(point p1, point p2, line * l) {
  if (p1.x == p2.x)
    l->a = 1.0, l->b = 0.0, l->c = -p1.x;
  else {
    l->a = -(double)(p1.y - p2.y) / (p1.x - p2.x);
    l->b = 1.0;
    l->c = -(double)(l->a * p1.x) - (l->b * p1.y);
  }
}

const int N = 505;
vector<pair<int, double> > cir[N];
int n, m;

double dist2(point p, line l) {
  double res = l.a * p.x + l.b * p.y + l.c;
  return res * res / (l.a * l.a + l.b * l.b);
}

int main() {
  scanf("%d", &n);
  for (int i = 0; i < n; i++) {
    int x, y;
    double r;
    scanf("%d %d %lf", &x, &y, &r);
    cir[x].push_back({y, r * r});
  }
  for (int i = 0; i < N; i++)
    sort(cir[i].begin(), cir[i].end());
  scanf("%d", &m);
  while (m--) {
    point a, b;
    scanf("%d %d %d %d", &a.x, &a.y, &b.x, &b.y);
    line l;
    if (a.x > b.x)
      swap(a, b);
    pointToLine(a, b, &l);
    int ans = 0;
    int miy = a.y, may = b.y;
    if (miy > may)
      swap(miy, may);
    for (int i = a.x; i <= b.x; i++) {
      double y = a.x == b.x ? min(a.y, b.y) : - (l.a * i + l.c)/l.b;
      auto it = lower_bound(cir[i].begin(), cir[i].end(), make_pair((int)y, (double)-1.0));
      auto it2 = it;
      while (it != cir[i].end()) {
        // cerr << i << " " << it->first << " " << dist2(point(i, it->first), l) << endl;
        double d = dist2(point(i, it->first), l);
        if (it->first > y + 3 && d > 1)
          break;
        if (it->first <= may && it->first >= miy && d < it->second)
          ans++;
        it++;
      }
      if (it2 != cir[i].begin()) {
        it2--;
        while (1) {
          // cerr << i << " " << it->first << " " << dist2(point(i, it->first), l) << endl;
          double d = dist2(point(i, it2->first), l);
          if (it2->first < y - 3 && d > 1)
            break;
          if (it2->first <= may && it2->first >= miy && d < it2->second)
            ans++;
          if (it2 == cir[i].begin())
            break;
          it2--;
        }
      }
    }
    printf("%d\n", ans);
  }
  return 0;
}