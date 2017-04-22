#include <bits/stdc++.h>

using namespace std;

const int N = 12505, mod = 1e9 + 7;

int val[N];

int mul[N], inv[N];
long long powmod(long long b, long long p) {
  long long ret = 1;
  for (; p; p>>=1, b = b*b % mod)
    if (p&1) ret=ret*b % mod;
  return ret;
}

int main() {
  val[0] = 1;
  for (int i = 1; i < N; i++) {
    int to = N-i;
    for (int j = 0; j < to; j++) {
      val[j+i] += val[j];
      if (val[j+i] >= mod)
        val[j+i] -= mod;
    }
  }
  mul[0] = inv[0] = 1;
  for (int i = 1; i < N; i++) {
    mul[i] = (1LL * val[i] * mul[i-1]) % mod; 
    inv[i] = powmod(mul[i], mod-2);
  }
  int t;
  scanf("%d", &t);
  while (t--) {
    int n, m;
    scanf("%d %d", &n, &m);
    printf("%lld\n", (1LL * mul[n+m-1] * inv[m-1]) % mod);
  }
  return 0;
}