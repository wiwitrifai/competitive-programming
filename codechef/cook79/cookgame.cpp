#include <bits/stdc++.h>

using namespace std;

const int N = 1e6 + 5;
const int mod = 1e9 + 7;
long long powmod(long long b, long long p) {
  long long ret = 1;
  for (; p; p >>= 1, b = (b * b) % mod)
    if (p&1) ret = (ret * b) % mod;
  return ret;
}

int a[N];

int main() {
  int t;
  scanf("%d", &t);
  while (t--) {
    int n;
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
      scanf("%d", a+i);
    }
    int now = 0;
    long long ans = 1;
    for (int i = n-1; i >= 0; i--, now = max(now-1, 0)) {
      if (a[i] != -1) {
        if (now <= 0)
          now = a[i];
        else
          if (now != a[i]) {
            ans = 0;
            break;
          }
      }
      else {
        if (now > 0)
          a[i] = now;
        else {
          if (i > 0)
            ans = (ans + ans) % mod;
        }
      }
    }
    if (a[0] != -1 && a[0] != 1)
      ans = 0; 
    printf("%lld\n", ans);
  }
  return 0;
}