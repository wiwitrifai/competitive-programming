#include <bits/stdc++.h>

using namespace std;

struct point {
  long long x, y;
  int id;
  point() {
  }
  point(long long x, long long y, int id) : x(x), y(y), id(id) {
  }
  bool operator< (point p) {
    if (x != p.x)
      return x < p.x;
    return y < p.y;
  }
};

long long dir(point p, point q, point r) {
  return (r.x - p.x) * (q.y - p.y) - (r.y - p.y) * (q.x - p.x);
}

long long sq(long long x, long long y) {
  return x * x + y * y;
}

const int N = 750005;

int n, x[N], y[N];
long long ans[N];
point p[N];

int main() {
  scanf("%d", &n);
  for (int i = 0; i < n; i++) {
    scanf("%d %d", x+i, y+i);
  }
  int m = n;
  while (m > 0) {
    for (int i = 0; i < m; i++) {
      p[i] = point((long long )x[i], (long long)y[i], i);
    }
    sort(p, p+m);
    vector< point > U, L;
    long long dist = 0;
    int id = 0;
    for (int i = 0; i < m; i++) {
      while (U.size() > 1 && dir(U[(int)U.size() - 2], U.back(), p[i]) <= 0) U.pop_back();
      while (L.size() > 1 && dir(L[(int)L.size() - 2], L.back(), p[i]) >= 0) L.pop_back();
      U.push_back(p[i]);
      L.push_back(p[i]);
    }
    int i = 0, j = (int)L.size() - 1;
    while (i < U.size() && j >= 0) {
      long long now = sq(U[i].x - L[j].x, U[i].y - L[j].y);
      if (now > dist) {
        dist = now;
        id = max(U[i].id, L[j].id);
      }
      else if (now == dist) {
        id = max(id, max(U[i].id, L[j].id));
      }
      
      if (i == (int)U.size() - 1) 
        j--;
      else if (j == 0)
        i++;
      else if ((U[i+1].y - U[i].y) * (L[j].x - L[j-1].x)
       > (U[i+1].x - U[i].x) * (L[j].y - L[j-1].y))
        i++;
      else
        j--;
    }
    for (i = id; i < m; i++)
      ans[i] = dist;
    m = id;
  }
  for (int i = 0; i < n; i++)
    printf("%lld\n", ans[i]);

  return 0;
}