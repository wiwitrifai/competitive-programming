#include <bits/stdc++.h>

using namespace std;

const int mod = 1e9 + 7;


long long powmod(long long b, long long e) {
  long long r = 1;
  for (; e; e >>= 1, b = b * b % mod)
    if (e & 1)
      r = r * b % mod;
  return r;
}


const int N = 1e6 + 6;

long long fac[N], inv[N];
long long f[N];

long long P(int n, int k) {
  if (k < 0 || n < k)
    return 0;
  return fac[n] * inv[n-k] % mod;
}


int cnt[27][55];

char buffer[101];

void solve() {
  int n;
  scanf("%d", &n);
  vector<int> w(n);
  for (int i = 0; i < n; ++i)
    scanf("%d", &w[i]);
  int d;
  scanf("%d", &d);
  memset(cnt, 0, sizeof cnt);
  vector<string> vs(d);
  for (int i = 0; i < d; ++i) {
    scanf("%s", buffer);
    vs[i] = buffer;
    ++cnt[buffer[0]-'a'][vs[i].size()];
  }
  vector<pair<int, int>> vc(n);
  long long ans = 0;
  for (string & s : vs) {
    if ((int)s.size() != n) continue;
    --cnt[s[0]-'a'][s.size()];
    for (int i = 0; i < n; ++i) {
      vc[i] = {s[i]-'a', w[i]};
    }
    sort(vc.begin(), vc.end());
    long long cur = 1;
    for (int i = 0; i < n; ) {
      int j = i+1;
      while (j < n && vc[j] == vc[i]) {
        ++j;
      }
      cur = (cur * P(cnt[vc[i].first][vc[i].second], j-i)) % mod;
      i = j;
    }
    ans += cur;
    if (ans >= mod)
      ans -= mod;
    ++cnt[s[0]-'a'][s.size()];
  }
  ans %= mod;
  if (ans < 0)
    ans += mod;
  printf("%lld\n", ans);
}

int main() {
  fac[0] = inv[0] = 1;
  for (int i = 1; i < N; ++i) {
    fac[i] = fac[i-1] * i % mod;
  }
  inv[N-1] = powmod(fac[N-1], mod - 2);
  for (int i = N-2; i > 0; --i) {
    inv[i] = inv[i+1] * (i+1) % mod;
  }
  int tc = 1;
  scanf("%d", &tc);
  while (tc--) {
    solve();
  }
  return 0;
}
