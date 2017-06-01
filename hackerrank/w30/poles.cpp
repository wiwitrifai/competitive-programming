#include <bits/stdc++.h>

using namespace std;

const int N = 5050;
const long long inf = 5e18 + 8;
struct line {
  long long a, b;
  line(long long a = 0, long long b = 0) : a(a), b(b) {
  }
  long long get(long long x) {
    return a*x + b;
  }
  long double getd(long double x) {
    return x * a + b;
  }
};

struct convex_hull_trick {
  line * hull;
  int size;
  long long off;
  convex_hull_trick(int sz) : size(0), off(0) {
    hull = new line[sz+1];
  }
  bool isbad(line prev, line cur, line next) {
    return (double)(prev.b - cur.b) * (next.a - cur.a) >= (double)(cur.b - next.b) * (cur.a - prev.a);
  }
  void add(line nl) {
    hull[size++] = nl;
    while(size > 2 && isbad(hull[size-3], hull[size-2], hull[size-1]))
      hull[size-2] = nl, size--;
  }

  long long query(long long x) {
    int l, r;
    l = 0; r = size-1;
    while(l < r) {
      int m = (l + r) >> 1;
      if(hull[m].get(x) + off >= hull[m+1].get(x) + off)
        l = m+1;
      else
        r = m;
    }
    if (l >= size)
      return inf;
    return hull[l].get(x) + off;
  }
};
int x[N], w[N];
long long dp[2][N];

int main() {
  int n, k;
  scanf("%d %d", &n, &k);
  for (int i = 0; i < n; i++) {
    scanf("%d %d", x+i, w+i);
  }
  int c = 0, b = 1;
  for (int i = 0; i < n; i++) {
    dp[c][i] = i ? dp[c][i-1] + 1LL * (x[i]-x[0]) * w[i] : 0;
  }
  k--;
  while (k--) {
    swap(c, b);
    convex_hull_trick hull(n+1);
    hull.off = 0;
    long long sw = 0;
    for (int i = 0; i < n; i++) {
      sw += w[i];
      hull.off += 1LL * w[i] * x[i];
      if (i > 0 && dp[b][i-1] < inf) {
        line now(-x[i], 1LL * x[i] * sw - hull.off + dp[b][i-1]);
        hull.add(now);
      }
      dp[c][i] = hull.query(sw);
    }
  }
  printf("%lld\n", dp[c][n-1]);

  return 0;
}