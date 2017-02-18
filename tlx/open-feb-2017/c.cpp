#include <bits/stdc++.h>

using namespace std;

const int N = 1e5 + 6, mod = 1e9 + 7;

long long bit[N];
int m;
void upd(int x, long long val) {
  for (; x <= m; x += x&(-x))
    bit[x] = (bit[x] + mod + val) % mod; 
}
long long get(int x) {
  long long ret = 0;
  for (; x; x -= x&(-x))
    ret = (ret + mod + bit[x]) % mod;
  return ret;
}
long long powmod(long long b, long long p) {
  long long ret = 1;
  for (; p; p >>= 1, b = (b * b) % mod)
    if (p &1) ret =(ret * b) % mod;
  return ret;
}
int a[N];
int cnt[N];

int main() {
  int n;
  scanf("%d", &n);
  m = n;
  vector< int > v;
  for (int i = 0;i < n; i++) {
    scanf("%d", a+i);
    v.push_back(a[i]);
  }
  sort(v.begin(), v.end());
  v.erase(unique(v.begin(), v.end()), v.end());
  for (int i = 0; i < n; i++)
    a[i] = lower_bound(v.begin(), v.end(), a[i]) - v.begin() + 1;
  for (int i = 0; i <= n; i++)
    bit[i] = 0;
  for (int i = 0; i < n; i++) {
    upd(a[i], get(a[i]) + 1);
  }
  long long ans = n + powmod(2, n) - 1 - get(n);
  for (int i = 0; i <= n; i++) {
    bit[i] = 0;
  }
  for (int i = n-1; i >= 0; i--) {
    upd(a[i], get(a[i]) + 1);
  }
  ans -= get(n);
  ans %= mod;
  if (ans < 0)
    ans += mod;
  for (int i = 0; i < n; i++)
    cnt[a[i]]++;
  for (int i = 0; i <= n; i++)
    ans = (ans + powmod(2, cnt[i]) - cnt[i] - 1) % mod;
  printf("%lld\n", ans);
  return 0;
} 