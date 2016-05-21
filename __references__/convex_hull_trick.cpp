#include <bits/stdc++.h>

using namespace std;
struct line {
  long long a, b, get(long long x) {
    return a*x + b;
  }
};

struct convex_hull_trick {
  line * hull;
  int size;
  convex_hull_trick(int sz) : size(0) {
    hull = new line[sz+1];
  }
  bool isbad(line prev, line cur, line next) {
    return (prev.b - cur.b) * (next.a - cur.a) >= (cur.b - next.b) * (cur.a - prev.a);
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
      if(hull[m].get(x) <= hull[m+1].get(x))
        l = m+1;
      else
        r = m;
    }
    return hull[l].get(x);
  }
};
const int N = 2e5 + 5;
long long sum[N];
int a[N];

int main() {
  int n;
  scanf("%d", &n);
  long long ans = 0, add = 0;
  sum[0] = 0;
  for(int i = 1; i<=n; i++) {
    scanf("%d", a+i);
    sum[i] = sum[i-1] + a[i];
    ans += a[i] * (long long)i;
  }
  convex_hull_trick hull(n);
  hull.size = 0;
  for(int i = 1; i <= n; i++) {
    hull.add((line){i, -sum[i-1]});
    add = max(add, hull.query(a[i]) + sum[i-1] - a[i]*(long long)i);
  }
  hull.size = 0;
  for(int i = n; i > 0;  i--) {
    hull.add((line){-i, -sum[i]});
    add = max(add, hull.query(-a[i]) + sum[i] - a[i]*(long long)i);
  }
  cout << ans + add << endl;
  return 0;
}