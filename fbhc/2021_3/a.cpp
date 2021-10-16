#include <bits/stdc++.h>

using namespace std;

const int mod = 1e9 + 7;

struct Dsu {
  vector<int> p;
  Dsu(int _n) : p(_n, -1) {
  }
  int find(int x) { return p[x] < 0 ? x : p[x] = find(p[x]); }

  long long merge(int u, int v) {
    u = find(u);
    v = find(v);
    if (u == v)
      return 0;
    if (u > v)
      swap(u, v);
    long long ret = (1LL * p[u] * p[v]) % mod;
    p[v] += p[u];
    p[u] = v;
    return ret;
  }
};

void solve() {
  int n, m;
  cin >> n >> m;
  Dsu dsu(n);
  long long ans = 1;
  long long cur = 1LL * n * (n-1) / 2 % mod;
  for (int i = 0; i < m; ++i) {
    int u, v;
    cin >> u >> v;
    --u, --v;
    if (u > v)
      swap(u, v);
    u = dsu.find(u);
    while (u < v) {
      cur = (cur + dsu.merge(u, u+1)) % mod;
      u = dsu.find(u);
    }
    ans = (ans * cur) % mod;
  }
  ans %= mod;
  if (ans < 0)
    ans += mod;
  cout << ans << endl;
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
