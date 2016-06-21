#include <bits/stdc++.h>

using namespace std;
const int N = 1e5 + 2;
const int mod = 1e9 + 9, i2 = (mod+1)/2;
int a[N];
long long fac[N], inv[N], val[N];

long long powmod(long long base, long long pw) {
  long long ret = 1;
  while(pw) {
    if(pw & 1)
      ret = (ret * base) % mod;
    base = (base * base) % mod;
    pw >>= 1;
  }
  return ret;
}

int main() {
  fac[0] = 1;
  inv[0] = 1;
  for(int i = 1; i<N; i++) {
    fac[i] = (fac[i-1] * i) % mod;
    inv[i] = powmod(fac[i], mod-2);
  }
  val[0] = 1;
  val[1] = 1;
  for(int i = 2; i<N; i++) {
    val[i] = 0;
    for(int j = 1; j<i; j++) {
      long long cur = (inv[j-1] * inv[i-j-1]) % mod;
      cur = (cur * val[j]) % mod;
      cur = (cur * val[i-j]) % mod;
      val[i] = (val[i] + cur) % mod;
    }
    long long cur = (fac[i-2] * i) % mod;
    cur = (cur * i2) % mod;
    val[i] = (val[i] * cur) % mod;
  }
  int t;
  scanf("%d", &t);
  while(t--) {
    int n;
    scanf("%d", &n);
    for(int i = 0; i<n; i++) {
      scanf("%d", a+i);
      a[i]--;
    }
    long long ans = 1, com = 0;
    for(int i= 0; i<n; i++) if(a[i] >= 0) {
      com++;
      int now = a[i], cnt = 0;
      a[i] = -1;
      while(now >= 0) {
        cnt++;
        int bef = now;
        now = a[now];
        a[bef] = -1;
      }
      if(cnt == 1)
        continue;
      ans = (ans * val[cnt]) % mod;
      ans = (ans * inv[cnt-1]) % mod;
    }
    ans = (ans * fac[n-com] ) % mod;
    printf("%lld\n", ans);
  }
  return 0;
}