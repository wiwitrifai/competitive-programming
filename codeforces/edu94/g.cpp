#include <bits/stdc++.h>

using namespace std;

const int N = 3e5 + 5, mod = 998244353;

long long powmod(long long b, long long p) {
  long long r = 1;
  for (; p; p >>= 1, b = b * b % mod)
    if (p & 1)
      r = r * b % mod;
  return r;
}

long long fac[N], inv[N];

long long C(int n, int k) {
  if (k < 0 || n < k)
    return 0;
  return (fac[n] * inv[k] % mod) * inv[n-k] % mod;
}

int add[N], a[N], b[N], l[N], r[N];

int presum[42];
vector<pair<int, int>> que[N];
bool used[N];

void solve() {
  fac[0] = inv[0] = 1;
  for (int i = 1; i < N; ++i) {
    fac[i] = fac[i-1] * i % mod;
  }
  inv[N-1] = powmod(fac[N-1], mod - 2);
  for (int i = N-2; i > 0; --i) {
    inv[i] = inv[i+1] * (i+1LL) % mod;
  }
  int n, m;
  scanf("%d %d", &n, &m);
  for (int i = 0; i < n; ++i) {
    scanf("%d %d", l+i, r+i);
    --l[i];
    ++add[l[i]+1];
    --add[r[i]+1];
  }
  for (int i = 0; i < m; ++i) {
    scanf("%d %d", a+i, b+i);
    --a[i], --b[i];
  }
  long long ans = 0;
  int nmask = 1 << m;
  for (int mask = 0; mask < nmask; ++mask) {
    int lef = 0, rig = n;
    int cnt = 0;
    for (int i = 0; i < m; ++i) {
      if ((mask & (1 << i)) == 0) continue;
      lef = max(lef, max(l[a[i]], l[b[i]]));
      rig = min(rig, min(r[a[i]], r[b[i]]));
      cnt += !used[a[i]];
      cnt += !used[b[i]];
      used[a[i]] = used[b[i]] = true;
    }
    if (lef < rig) {
      que[lef].emplace_back(cnt, (__builtin_popcount(mask) & 1) ? +1 : -1);
      que[rig].emplace_back(cnt, (__builtin_popcount(mask) & 1) ? -1 : 1);
    }
    for (int i = 0; i < m; ++i) {
      if ((mask & (1 << i)) == 0) continue;
      used[a[i]] = used[b[i]] = false;
    }
  }
  for (int i = 1; i <= n; ++i) {
    add[i] += add[i-1];
    int now = add[i];
    for (int j = 0; j <= 2 * m; ++j) {
      presum[j] += C(now-j, i-j);
      if (presum[j] >= mod)
        presum[j] -= mod;
    }
    for (auto it : que[i]) {
      ans = (ans + it.second * presum[it.first]);
      if (ans < 0)
        ans += mod;
      if (ans >= mod)
        ans -= mod;
    }
  }
  ans %= mod;
  if (ans < 0)
    ans += mod;
  printf("%lld\n", ans);
}

int main() {
  int tc = 1;
  // scanf("%d", &tc);
  while (tc--) {
    solve();
  }
  return 0;
}
