/*
This solution is actually wrong, here is the generator (in python) which will make this solution wrong:

h = 10 ** 9
n = 10 ** 5
d = [i+100000 for i in range(n)]
s = 10 ** 9
print(h, n)
print(*d)
print(s)
for i in range(n // 2):
    print(d[i], d[n-1-i], 1, 0)
for i in range(n // 2, n):
    print(d[i - (i - n // 2 + 2)], d[i], 1, 0)
print(n // 2)

I was so lucky that this solution passed all the tests during the contest :p
*/

#include <bits/stdc++.h>

using namespace std;

const int N = 1e5 + 5;

typedef long long ll;
const ll is_query = -(1LL<<62);
struct Line {
    ll m, b;
    mutable function<const Line*()> succ;
    bool operator<(const Line& rhs) const {
        if (rhs.b != is_query) return m > rhs.m; // max: reverse it
        const Line* s = succ();
        if (!s) return 0;
        ll x = rhs.m;
        return b - s->b > (s->m - m) * x; // max: reverse it
    }
};
struct HullDynamic : public multiset<Line> { // will maintain lower hull for minimum
    bool bad(iterator y) {
        auto z = next(y);
        if (y == begin()) {
            if (z == end()) return 0;
            return y->m == z->m && y->b >= z->b; // max: reverse it
        }
        auto x = prev(y);
        if (z == end()) return y->m == x->m && y->b >= x->b; // max: reverse it
        return (long double)(x->b - y->b)*(z->m - y->m) >= (long double)(y->b - z->b)*(y->m - x->m); // beware overflow!
    }
    void insert_line(ll m, ll b) {
        auto y = insert({ m, b });
        y->succ = [=] { return next(y) == end() ? 0 : &*next(y); };
        if (bad(y)) { erase(y); return; }
        while (next(y) != end() && bad(next(y))) erase(next(y));
        while (y != begin() && bad(prev(y))) erase(prev(y));
    }
    ll eval(ll x) {
        auto l = *lower_bound((Line) { x, is_query });
        return l.m * x + l.b;
    }
};


int h, n;
long long d[N];
long long s;
long long a[N], b[N];
long long t[N], q[N];
int x;
long long ans[N];

void dncL(int l, int r) {
  if (r-l < 2) {
    int id = upper_bound(d, d+n, a[l]) - d;
    if (id > 0) {
      --id;
      int i = l;
      ans[id] = min(ans[id], ans[i] + q[i] + abs(d[i] - a[i]) * t[i] + s * abs(a[i] - d[id]));
    }
    return;
  }
  int mid = (l + r) >> 1;
  dncL(mid, r);
  for (int i = r-2; i >= l; --i) {
    ans[i] = min(ans[i], ans[i+1] + s * abs(d[i+1] - d[i]));
  }
  vector<pair<int, int>> jump;
  for (int i = mid; i < r; ++i) {
    if (a[i] < d[mid]) {
      jump.emplace_back(a[i], i);
    }
  }
  sort(jump.begin(), jump.end());
  HullDynamic hull;
  for (int i = l, j = 0; i < mid; ++i) {
    while (j < (int)jump.size() && jump[j].first <= d[i]) {
      int id = jump[j].second;
      hull.insert_line(-t[id], ans[id] + q[id] + 1LL * d[id] * t[id]);
      ++j;
    }
    if (hull.empty()) continue;
    ans[i] = min(ans[i], hull.eval(d[i]));
  }
  for (int i = r-2; i >= l; --i) {
    ans[i] = min(ans[i], ans[i+1] + s * abs(d[i+1] - d[i]));
  }
  dncL(l, mid);
}

void dncR(int l, int r) {
  if (r-l < 2) {
    int id = lower_bound(d, d+n, b[l]) - d;
    if (id < n) {
      ans[id] = min(ans[id], ans[l] + q[l] + abs(b[l] - d[l]) * t[l] + s * abs(d[id] - b[l]));
    }
    return;
  }
  int mid = (l + r) >> 1;
  dncR(l, mid);
  for (int i = l+1; i < r; ++i) {
    ans[i] = min(ans[i], ans[i-1] + s * abs(d[i] - d[i-1]));
  }
  vector<pair<int, int>> jump;
  for (int i = l; i < mid; ++i) {
    if (b[i] >= d[mid]) {
      jump.emplace_back(b[i], i);
    }
  }
  sort(jump.begin(), jump.end());
  reverse(jump.begin(), jump.end());
  HullDynamic hull;
  for (int i = r-1, j = 0; i >= mid; --i) {
    while (j < (int)jump.size() && jump[j].first >= d[i]) {
      int id = jump[j].second;
      hull.insert_line(t[id], ans[id] + q[id] - 1LL * d[id] * t[id]);
      ++j;
    }
    if (hull.empty()) continue;
    ans[i] = min(ans[i], hull.eval(d[i]));
  }
  for (int i = mid+1; i < r; ++i) {
    ans[i] = min(ans[i], ans[i-1] + s * abs(d[i] - d[i-1]));
  }
  dncR(mid, r);
}

int main() {
  scanf("%d %d", &h, &n);
  for (int i = 0; i < n; ++i)
    scanf("%lld", d+i);
  scanf("%lld", &s);
  for (int i = 0; i < n; ++i) {
    scanf("%lld %lld %lld %lld", a+i, b+i, t+i, q+i);
  }
  scanf("%d", &x);
  --x;
  for (int i = 0; i < n; ++i) {
    ans[i] = abs(d[x] - d[i]) * s;
  }
  for (int i = 0; i < 100; ++i) {
    dncL(0, n);
    dncR(0, n);
    dncL(0, n);
    dncR(0, n);
    dncL(0, n);
  }
  for (int i = 0; i < n; ++i) {
    printf("%lld\n", ans[i]);
  }
  return 0;
}
