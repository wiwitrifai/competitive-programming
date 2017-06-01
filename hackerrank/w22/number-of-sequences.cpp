#include <bits/stdc++.h>

using namespace std;

const int mod = 1e9 + 7;
const int N = 1e5 + 5;

bitset< N > isprim;

int n, a[N];

int main() {
  isprim.set();
  isprim[1] = 0;
  for (int i = 2; i < N; i++) if(isprim[i]) {
    for(long long j = 1LL * i * i; j < N; j += i)
      isprim[j] = 0;
  }
  scanf("%d", &n);
  for (int i = 1; i <= n; i++) {
    scanf("%d", a+i);
  }
  for (int i = 1; i <= n; i++) if (a[i] == -1) {
      for (int j = i+i; j <= n; j += i)
        if (a[j] != -1) {
            a[i] = a[j] % i;
            break;
        }
  }
  long long ans = 1;
  for (int i = 1; i <= n; i++) {
    if (a[i] != -1) {
      for (int j = i + i; j <= n; j += i)
        if (a[j] != -1 && (a[j] % i) != a[i]) {
          ans = 0;
        }
    }
    if (isprim[i]) {
      long long  now = i, mul = 1;
      while (now <= n) {
        if (a[now] == -1)
          mul *= i;
        now *= i;
      }
      ans = (ans * mul) % mod;
    }
  }
  ans %= mod;
  if(ans < 0)
    ans += mod;
  printf("%lld\n", ans);
  return 0;
}