#include <bits/stdc++.h>

using namespace std;

const int N = 1e6 + 6, mod = 1e9 + 7;

vector<int> g[N];

int main() {
  int n;
  scanf("%d", &n);
  for (int i = 1; i < n; ++i) {
    int u, v;
    scanf("%d %d", &u, &v); --u, --v;
    g[u].push_back(v);
    g[v].push_back(u);
  }
  long long ans = 0;
  for (int i = 0; i < n; ++i) {
    if (g[i].size() < 4) continue;
    int child = g[i].size();
    long long one = 0;
    long long now = 0;
    for (int u : g[i]) {
      int deg = (int)g[u].size()-1;
      long long val = 1LL * deg * (deg - 1) / 2;
      val %= mod;
      now = (now + one * val) % mod;
      one += val;
      if (one >= mod) one -= mod;
    }
    int sisa = child - 2;
    long long pilih = 1LL * sisa * (sisa - 1) / 2;
    pilih %= mod;
    ans = (ans + now * pilih) % mod;
  }
  if (ans < 0) ans += mod;
  printf("%lld\n", ans);

  return 0;
}