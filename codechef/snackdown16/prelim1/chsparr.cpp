#include <bits/stdc++.h>

using namespace std;
const int mod = 1e9 + 7;
const int N = 1e5 + 5;
long long val[50];
int a[N], n, m;

long long get(long long x) {
  if(x == 0)
    return 0;
  long long ret = a[0];
  x--;
  long long sz = 1LL<<m, last = 0;
  for(int i = 1; i<n; i++)
    if(x >= sz) {
      ret += (val[m] * (a[i-1] + a[i])) % mod;
      ret -= a[i-1];
      ret %= mod;
      if(ret < 0)
        ret += mod;
      x -= sz;
      last = i;
    }
    else
      break;
  if(last >= n-1)
    return ret;
  long long l = a[last], r = a[last+1];
  for(int i = m-1; i>=0; i--) {
    if((1LL<<i) <= x) {
      ret += (val[i] * (l + l + r)) % mod;
      ret -= l;
      ret %= mod;
      if(ret < 0)
        ret += mod;
      x -= 1LL<<i;
      l = (l + r) % mod;
    }
    else
      r = (l + r) % mod;
  }
  return ret;
}
int main() {
  val[0] = 1;
  for(int i = 1; i<50; i++) {
    val[i] = (3*val[i-1] - 1) % mod;
    if(val[i] < 0)
      val[i] += mod;
  }
  int t;
  scanf("%d", &t);
  while(t--) {
    long long x, y;
    scanf("%d%d%lld%lld", &n, &m, &x, &y);
    for(int i = 0; i<n; i++)
      scanf("%d", a+i);
    long long ans = get(y) - get(x-1);
    ans %= mod;
    if(ans < 0)
      ans += mod;
    printf("%lld\n", ans);
  }
  return 0;
}