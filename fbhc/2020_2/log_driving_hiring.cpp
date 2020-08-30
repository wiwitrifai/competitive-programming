#include <bits/stdc++.h>

using namespace std;


vector<int> read_sequence(int k, int n, long long d = -1, bool is_p = false) {
  vector<int> s(n);
  for (int i = 0; i < k; ++i)
    scanf("%d", &s[i]);
  long long a, b, c;
  scanf("%lld %lld %lld", &a, &b, &c);
  if (d == -1) {
    scanf("%lld", &d);
  }
  for (int i = k; i < n; ++i) {
    if (is_p)
      d = i;
    s[i] = ((a * s[i-2] + b * s[i-1] + c) % d) + 1;
  }
  return s;
}
typedef long long ll;
const ll is_query = -(1LL<<62);
struct Line {
    ll m, b;
    mutable function<const Line*()> succ;
    bool operator<(const Line& rhs) const {
        if (rhs.b != is_query) return m > rhs.m; // min: ok
        const Line* s = succ();
        if (!s) return 0;
        ll x = rhs.m;
        return b - s->b > (s->m - m) * x; // min: ok
    }
};
struct HullDynamic : public multiset<Line> { // ok
    bool bad(iterator y) {
        auto z = next(y);
        if (y == begin()) {
            if (z == end()) return 0;
            return y->m == z->m && y->b >= z->b; // min: ok
        }
        auto x = prev(y);
        if (z == end()) return y->m == x->m && y->b >= x->b; // min: ok
        return (__int128)(x->b - y->b)*(z->m - y->m) >= (__int128)(y->b - z->b)*(y->m - x->m); // beware overflow!
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

vector<vector<int>> child;
vector<vector<int>> queries;
vector<HullDynamic *> hull;

const int mod = 1e9 + 7;

void solve() {
  int n, m, k;
  scanf("%d %d %d", &n, &m, &k);
  vector<int> p = read_sequence(k, n, 1, true);
  vector<int> l = read_sequence(k, n);
  vector<int> h = read_sequence(k, n);
  vector<int> x = read_sequence(k, m, n);
  vector<int> y = read_sequence(k, m);
  queries.resize(n);
  child.resize(n);
  for (int i = 0; i < n; ++i) {
    child[i].clear();
    queries[i].clear();
  }
  for (int i = 1; i < n; ++i) {
    --p[i];
    child[p[i]].emplace_back(i);
  }
  for (int i = 0; i < m; ++i) {
    --x[i];
    queries[x[i]].push_back(y[i]);
  }
  hull.resize(n);
  vector<int> sz(n, 1);
  long long ret = 1;
  vector<long long> d(n, 0);
  for (int v = 1; v < n; ++v) {
    d[v] = d[p[v]] + l[v];
  }
  for (int v = n-1; v >= 0; --v) {
    sz[v] = 1;
    int biggest = -1;
    for (auto u : child[v]) {
      sz[v] += sz[u];
      if (biggest == -1 || sz[u] > sz[biggest])
        biggest = u;
    }
    if (biggest == -1) {
      hull[v] = new HullDynamic();
      hull[v]->insert_line(d[v], 0);
      continue;
    }
    hull[v] = hull[biggest];
    for (auto u : child[v]) {
      if (u == biggest)
        continue;
      for (const auto & line : *hull[u]) {
        hull[v]->insert_line(line.m, line.b);
      }
    }
    long long cur = -d[v] * h[v] + hull[v]->eval(h[v]);
    hull[v]->insert_line(d[v], cur);
    for (auto que : queries[v]) {
      long long now = hull[v]->eval(que) - d[v] * que + 1;
      now %= mod;
      ret = ret * now % mod;
    }
  }
  ret %= mod;
  if (ret < 0)
    ret += mod;
  printf("%lld\n", ret);
}

int main(int argc, char * argv[]) {
  clock_t starttime = clock();
  int seed = time(0);
  if (argc >= 2) {
    seed = atoi(argv[1]);
  }
  cerr << "random seed\t= " << seed << endl;
  srand(seed);

  int tt;
  scanf("%d", &tt);
  for (int tc = 1; tc <= tt; ++tc) {
    printf("Case #%d: ", tc);
    solve();
    fflush(stdout);
    cerr << "~ TC#" << tc << " done! execution time : " <<
      (double)(clock() - starttime) / CLOCKS_PER_SEC << " s " << endl;
  }
  return 0;
}
