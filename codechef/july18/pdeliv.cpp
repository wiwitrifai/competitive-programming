#include <bits/stdc++.h>

using namespace std;

const int N = 2e5 + 5;
const long long inf = 9e18;

struct line {
  long long m, c; // y = m x + c
  line(long long m = 0, long long c = 0) : m(m), c(c) {}
  long long get(long long x) {
    return m * x + c;
  }
  bool operator<(const line & l) const {
    return m == l.m ? c < l.c : m > l.m;
  }
};

bool bad(line p, line q, line r) {
  return (long double)1.0 * (p.c - q.c) * (r.m - q.m) >= (long double)1.0 * (q.c - r.c) * (q.m - p.m);
}

vector<line> hull[N << 2];
long long s[N], p[N];
int n, m;

void add(vector<line>& cur, line l) {
  if (cur.size() > 0)
    assert(cur.back().m >= l.m);
  if (cur.size() > 0 && cur.back().m == l.m) {
    assert(cur.back().c < l.c);
    return;
  }
  int sz;
  while ((sz = cur.size()) > 1 && bad(cur[sz-2], cur[sz-1], l))
    cur.pop_back();
  cur.push_back(l);
}

void build(int id = 1, int l = 0, int r = n) {
  if (r-l < 2) {
    hull[id].push_back(line(-2LL * s[l], 1LL * s[l] * s[l] + p[l]));
    return;
  }
  int mid = (l + r) >> 1, il = id << 1, ir = il | 1;
  build(il, l, mid);
  build(ir, mid, r);
  int ll = 0, rr = 0;
  while (ll < hull[il].size() && rr < hull[ir].size()) {
    line now;
    if (hull[il][ll] < hull[ir][rr])
      now = hull[il][ll++];
    else
      now = hull[ir][rr++];
    add(hull[id], now);
  }
  while (ll < hull[il].size())
    add(hull[id], hull[il][ll++]);
  while (rr < hull[ir].size())
    add(hull[id], hull[ir][rr++]);
}

long long get(int x, int y, int c, int id = 1, int l = 0, int r = n) {
  if (x >= r || l >= y) return inf;
  if (x <= l && r <= y) {
    int lo = 0, hi = (int)hull[id].size()-1;
    while (lo < hi) {
      int mid = (lo + hi) >> 1;
      if (hull[id][mid].get(c) > hull[id][mid+1].get(c))
        lo = mid + 1;
      else
        hi = mid;
    }
    return hull[id][lo].get(c);
  }
  int mid = (l + r) >> 1, il = id << 1, ir = il | 1;
  return min(get(x, y, c, il, l, mid), get(x, y, c, ir, mid, r));
}

int main() {
  scanf("%d %d", &n, &m);
  for (int i = 0; i < n; ++i)
    scanf("%lld %lld", s+i, p+i);
  build();
  while (m--) {
    long long c;
    int k;
    scanf("%lld %d", &c, &k);
    vector<int> d;
    while (k--) {
      int x;
      scanf("%d", &x); --x;
      d.push_back(x);
    }
    d.push_back(n);
    sort(d.begin(), d.end());
    int now = 0;
    long long ans = inf;
    for (int x : d) {
      if (now < x)
        ans = min(ans, get(now, x, c));
      now = x+1;
    }
    ans += 1LL * c * c;
    printf("%lld\n", ans);
  }
  return 0;
}