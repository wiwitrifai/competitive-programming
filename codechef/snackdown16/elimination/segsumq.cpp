#include <bits/stdc++.h>

using namespace std;

const int N = 1e6 + 6;
const long long inf = 1e18;
struct line {
  long long a, b, get(long long x) {
    return a*x + b;
  }
  long double getd(long double x) {
    return x * a + b;
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

  long long query(long long c, long long d) {
    long double x = (long double) c / d;
    int l, r;
    l = 0; r = size-1;
    while(l < r) {
      int m = (l + r) >> 1;
      if(hull[m].getd(x) <= hull[m+1].getd(x))
        l = m+1;
      else
        r = m;
    }
    return hull[l].a * c + hull[l].b * d;
  }
};
int n, q, a[N];

convex_hull_trick * hull[N<<2];
long long aa[N<<2];
void build(int id = 1, int l = 0, int r = n) {
  hull[id] = new convex_hull_trick(r-l);
  aa[id] = 0;
  if(r-l < 2)
    return;
  int mid = (l + r) >> 1, il = id<<1, ir = il|1;
  build(il, l, mid);
  build(ir, mid, r);
}
void add(int v, line ln, int id = 1, int l = 0, int r = n) {
  hull[id]->add(ln);
  aa[id] = max(aa[id], ln.a);
  if(r-l < 2)
    return;
  int mid = (l + r) >> 1, il = id<<1, ir = il|1;
  if(v < mid)
    add(v, ln, il, l, mid);
  else
    add(v, ln, ir, mid, r);
}
long long get(int x, int y, long long c, long long d, int id = 1, int l = 0, int r = n) {
  if(r <= x || l >= y)
    return -inf;
  if(x <= l && r <= y) {
    cerr << id << " " << (d == 0 ? c * aa[id] : hull[id]->query(c, d)) << endl; 
    return d == 0 ? c * aa[id] : hull[id]->query(c, d);
  }
  int mid = (l + r) >> 1, il = id<<1, ir = il|1;
  return max(get(x, y, c, d, il, l, mid), get(x, y, c, d, ir, mid, r));
}

int main() {
  scanf("%d", &n);
  for(int i = 0; i<n; i++) {
    scanf("%d", a+i);
  }
  convex_hull_trick hull(n);
  build();
  for(int i = 0; i<n; i++) {
    int b;
    scanf("%d", &b);
    add(i, (line){a[i], -b});
  }
  scanf("%d", &q);
  while(q--) {
    int l, r, c, d;
    scanf("%d%d%d%d", &l, &r, &c, &d);
    l--;
    long long ans = max(0LL, get(l, r, c, d));
    printf("%lld\n", ans);
  }
}