#include <bits/stdc++.h>

using namespace std;

const int mod = 998244353, N = 3e5 + 5;

long long fact[N];

template<class T>
long long calc(vector<T> v) {
  int cnt = 0;
  T last = v[0];
  long long ans = 1;
  for (int i = 0; i < (int)v.size(); ++i) {
    if (last != v[i]) {
      ans = ans * fact[cnt] % mod;
      cnt = 0;
      last = v[i];
    }
    ++cnt;
  }
  ans = ans * fact[cnt] % mod;
  if (ans < 0)
    ans += mod;
  return ans;
}

int main() {
  fact[0] = 1;
  for (int i = 1; i < N; ++i) {
    fact[i] = 1LL * i * fact[i-1] % mod;
  }
  int n;
  scanf("%d", &n);
  vector<int> a(n), b(n);
  vector<pair<int, int>> s(n);
  for (int i = 0; i < n; ++i) {
    scanf("%d %d", &a[i], &b[i]);
    s[i] = {a[i], b[i]};
  }
  sort(a.begin(), a.end());
  sort(b.begin(), b.end());
  sort(s.begin(), s.end());
  long long ans = fact[n] - calc(a) - calc(b);
  bool ok = 1;
  for (int i = 0; i + 1 < n; ++i) {
    if (s[i].second > s[i+1].second) {
      ok = 0;
    }
  }
  if (ok)
    ans += calc(s);
  ans %= mod;
  if (ans < 0)
    ans += mod;
  printf("%lld\n", ans);
  return 0;
}
