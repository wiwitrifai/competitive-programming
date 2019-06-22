#include <bits/stdc++.h>

using namespace std;

const int N = 5e5 + 5;

long long dp[N];
long long ans = 0;
int n;

vector<int> g[N];
int sz[N];

void get_sz(int v, int par = -1) {
  sz[v] = 1;
  for (int u : g[v]) {
    if (u == par) continue;
    get_sz(u, v);
    sz[v] += sz[u];
  }
}

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
    // if find minimum value then change the comparation
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
      // this to find biggest
      if(hull[m].get(x) <= hull[m+1].get(x))
        l = m+1;
      else
        r = m;
    }
    return hull[l].get(x);
  }
};

convex_hull_trick * cht[N];


void dfs(int v, int par = -1) {
  dp[v] = 1LL * (n - sz[v]) * sz[v];
  sort(g[v].begin(), g[v].end(), [](int a, int b) {
    return sz[a] > sz[b];
  });
  cht[v] = new convex_hull_trick((int)g[v].size());
  for (int u : g[v]) {
    if (u == par) continue;
    dfs(u, v);
    ans = max(ans, dp[u] + 1LL * (n - sz[u]) * sz[u]);
    int s = sz[v] - sz[u];
    dp[v] = max(dp[v], dp[u] + 1LL * (n - s) * s);

    if (cht[v]->size > 0) {
      ans = max(ans, cht[v]->query(sz[u]) - 1LL * sz[u] * sz[u] + dp[u]);
    }
    long long m = n - 2LL * sz[u], c = dp[u] + 1LL * (n - sz[u]) * sz[u];
    cht[v]->add({m, c});
  }
}

int main() {
  scanf("%d", &n);
  for (int i = 1; i < n; ++i){
    int u, v;
    scanf("%d %d", &u, &v);
    --u, --v;
    g[u].push_back(v);
    g[v].push_back(u);
  }
  get_sz(0, -1);
  dfs(0, -1);
  ans += 1LL * n * (n-1);
  ans /= 2;
  printf("%lld\n", ans);
  return 0;
}
