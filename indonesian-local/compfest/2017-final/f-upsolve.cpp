/**
 * Upsolve after contest
 * Author  : Wiwit Rifa'i
 * Problem : F - Pasti menang!
 * Status  : ?
 */

#include <bits/stdc++.h>

using namespace std;

const int N = 1e5 + 5, M = 512, mod = 1e9 + 8;

struct dp {
  int k;
  long long v[M];
  dp() {
    k = 0;
    memset(v, 0, sizeof v);
  }
  dp operator+(const dp& other) const {
    dp res;
    res.k = k + other.k;
    for (int i = 0; i < M; i++) {
      res.v[i] = 0;
      for (int j = 0; j < M; j++) {
        res.v[i] += v[j] * other.v[i^j] % mod;
        if (res.v[i] >= mod)
          res.v[i] -= mod;
      }
    }
    return res;
  }
  dp operator*(int mul) const {
    dp res;
    res.v[0] = 1;
    for (dp base = *this; mul; mul >>= 1, base = base + base) {
      if (mul & 1)
        res = res + base;
    }
    return res;
  }
};
vector<int> g[N];
int grund[N];

int main() {
  int t;
  scanf("%d", &t);
  while (t--) {
    int n, m, k;
    scanf("%d %d %d", &n, &m, &k);
    for (int i = 0; i < n; i++)
      g[i].clear();
    for (int i = 0; i < m; i++) {
      int u, v;
      scanf("%d %d", &u, &v);
      u--; v--;
      g[u].push_back(v);
    }
    dp val;
    for (int i = 0; i < n; i++) {
      grund[i] = 0;
      set<int> st;
      for (int u : g[i])
        st.insert(grund[u]);
      for (int x : st)
        grund[i] += grund[i] == x;
      val.v[grund[i]]++;
    }
    val.k = 1;
    val = val * k;
    long long ans = 0;
    for (int i = 1; i < M; i++)
      ans = (ans + val.v[i]) % mod;
    if (ans < 0)
      ans += mod;
    printf("%lld\n", ans);
  }
  return 0;
}