#include <bits/stdc++.h>

using namespace std;

const int N = 1e5 + 5;
const long long inf = 1e18;

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
struct HullDynamic : public multiset<Line> {
    bool bad(iterator y) {
        auto z = next(y);
        if (y == begin()) {
            if (z == end()) return 0;
            return y->m == z->m && y->b >= z->b;
        }
        auto x = prev(y);
        if (z == end()) return y->m == x->m && y->b >= x->b;
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

int n;
long long c;
vector<int> g[N];
int sz[N], big[N];
long long val[N], offset[N], dp[N];

vector<HullDynamic *> hull;

void dfs(int v) {
  sz[v] = 1;
  big[v] = -1;
  dp[v] = 0;
  for (int u : g[v]) {
    val[u] += val[v];
    dfs(u);
    sz[v] += sz[u];
    if (big[v] < 0 || sz[big[v]] < sz[u])
      big[v] = u;
    dp[v] += dp[u];
  }
  if (big[v] == -1) {
    hull[v] = new HullDynamic();
    hull[v]->insert_line(- 2LL * val[v], val[v] * val[v]);
    dp[v] = c;
    offset[v] = 0;
    return;
  }
  offset[v] = offset[big[v]] + dp[v] - dp[big[v]];
  hull[v] = hull[big[v]];
  hull[v]->insert_line(- 2LL * val[v], val[v] * val[v] + dp[v] - offset[v]);
  for (int u : g[v]) {
    if (u == big[v]) {
      continue;
    }
    long long cur = offset[u] - offset[v] + dp[v] - dp[u];
    for (auto & l : *hull[u]) {
      hull[v]->insert_line(l.m, l.b + cur);
    }
  }
  dp[v] = hull[v]->eval(val[v]) + val[v] * val[v] + c + offset[v];
}


int main() {
  scanf("%d %lld", &n, &c);
  for (int i = 1; i < n; ++i) {
    int p;
    scanf("%d %lld", &p, val + i);
    --p;
    g[p].push_back(i);
  }
  hull.resize(n);
  dfs(0);
  printf("%lld\n", dp[0]);
  return 0;
}
