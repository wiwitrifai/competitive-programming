// still TLE
#include <bits/stdc++.h>

using namespace std;
const long double PI = acos(-1);

struct point {
  int x, y;
  point(int x = 0, int y = 0) : x(x), y(y) {}
  bool operator<(point p) {
    long long crs = 1LL * x * p.y - 1LL * y * p.x;
    return crs == 0 ? x < p.x : crs > 0;
  }
};

int main() {
  int n, m;
  scanf("%d %d", &n, &m);
  int q;
  scanf("%d", &q);
  while (q--) {
    long long c;
    scanf("%lld", &c);
    if (c < m) {
      printf("%d %d\n", 1, 1+c);
      continue;
    }
    else if (c > 1LL * (n) * (m-1))  {
      c -= 1LL * n * (m-1);
      printf("%d %d\n", 1 + c, 1);
      continue;
    }
    vector<point> vp;
    long long tot = 1;
    if (1LL * n * m < 100000) {
      for (int i = 1; i < m; ++i) {
        for (int j = 0; j < n; ++j)
          vp.push_back(point(i, j));
      }
    }
    else {
      long double le = 0, ri = PI/2;
      for (int i = 0; i < 100; ++i) {
        long double mid = (le +ri)/ 2;
        long double y = sin(mid), x = cos(mid);
        x *= m;
        y *= m;
        long double area = x * y * 0.5;
        if (y > n) {
          y = (y * n / m);
          x = (x * n / m);
          area = (m-x) * n + (y * x * 0.5);
        }
        if (area < c)
          le = mid;
        else
          ri = mid;
      }
      long double x = cos((le+ri)*0.5), y = cos((le+ri)*0.5);
      point cur(m-1, y);
      for (int i = 1; i < m; ++i) {
        long long z = 1LL * y * i / x;
        if (z >= n) {
          tot += n;
          continue;
        }
        point now(i, z);
        while (now.x * y - now.y * x > 0) ++now.y;
        tot += now.y;
        for (int j = 0; j < 3; ++j) {
          if (now.y >= n) break;
          vp.push_back(now);
          ++now.y;
        }
      }
    }
    sort(vp.begin(), vp.end());
    printf("%d %d\n", vp[c-tot].y+1, vp[c-tot].x+1);
  }
  return 0;
}