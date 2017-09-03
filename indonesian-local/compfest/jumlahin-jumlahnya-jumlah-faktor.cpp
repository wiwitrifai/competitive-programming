#include <bits/stdc++.h>

using namespace std;

const int N = 50005, mod = 1e9 + 7;

long long cnt[N], f[N];
int pf[N];

int main() {
  for (int i = 2; i < N; i++) if (pf[i] == 0) {
    for (int j = i; j < N; j += i)
      if (pf[j] == 0)
        pf[j] = i;
  }
  f[1] = 1;
  for (int i = 2; i < N; i++) {
    int p = pf[i];
    int now = i;
    long long pp = p;
    while ((now % p) == 0) {
      pp *= p;
      now /= p;
    }
    f[i] = ((pp - 1) / (p-1)) * f[now];
    f[i] %= mod;
  }
  int a, b;
  scanf("%d %d", &a, &b);
  long long ans = 0;
  for (int i =  max(a, b); i >= 1; i--) {
    cnt[i] = 1LL * (a/i) * (b/i);
    for (int j = i+i; j < N; j += i)
      cnt[i] -= cnt[j];
    cnt[i] %= mod;
    f[i] %= mod;
    ans = (ans + cnt[i] * f[i]) % mod;
  }
  ans %= mod;
  if (ans < 0)
    ans += mod;
  cout << ans << endl;
  return 0;
}