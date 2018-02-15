#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
const ll is_query = -(1LL<<62);
struct Line {
    ll m, b;
    mutable function<const Line*()> succ;
    bool operator<(const Line& rhs) const {
        if (rhs.b != is_query) return m > rhs.m;
        const Line* s = succ();
        if (!s) return 0;
        ll x = rhs.m;
        return b - s->b > (s->m - m) * x;
    }
};
struct HullDynamic : public multiset<Line> { // will maintain upper hull for maximum
    bool bad(iterator y) {
        auto z = next(y);
        if (y == begin()) {
            if (z == end()) return 0;
            return y->m == z->m && y->b >= z->b;
        }
        auto x = prev(y);
        if (z == end()) return y->m == x->m && y->b >= x->b;
        return (long double)(x->b - y->b)*(z->m - y->m) >= (long double)(y->b - z->b)*(y->m - x->m);
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
const int N = 1e5 + 5;
HullDynamic * hd[N];

int a[N], b[N];
long long ans[N];
vector<int> g[N];

void dfs(int v, int par = -1) {
  int bg = -1;
  for (int u : g[v]) if (u != par) {
    dfs(u, v);
    if (bg == -1 || hd[u]->size() > hd[bg]->size())
      bg = u;
  }
  if (bg == -1)
    hd[v] = new HullDynamic();
  else
    hd[v] = hd[bg];
  for (int u : g[v]) if (u != par && u != bg) {
    for (Line l : *hd[u])
      hd[v]->insert_line(l.m, l.b);
  }
  ans[v] = 0;
  if (hd[v]->size() > 0)
    ans[v] = hd[v]->eval(a[v]);
  hd[v]->insert_line(b[v], ans[v]);
}

int main() {
  int n;
  scanf("%d", &n);
  for (int i = 0; i < n; ++i)
    scanf("%d", a+i);
  for (int i = 0; i < n; ++i)
    scanf("%d", b+i);
  for (int i = 1; i < n; ++i) {
    int u, v;
    scanf("%d %d", &u, &v);
    --u, --v;
    g[u].push_back(v);
    g[v].push_back(u);
  }
  dfs(0);
  for (int i = 0; i < n; ++i) {
    printf("%I64d%c", ans[i], (i == n-1) ? '\n' : ' ');
  }
  return 0;
}