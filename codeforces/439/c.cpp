#include <bits/stdc++.h>

using namespace std;

const int N = 5e3 + 4, mod = 998244353;

long long C[N][N], fac[N];

long long calc(int a, int b) {
  if (a > b)
    swap(a, b);
  long long ret = 0;
  for (int i = 0; i <= a; i++) {
    ret = (ret + (C[a][i] * C[b][i] % mod) * fac[i]) % mod;
  }
  return ret;
}

int main() {
  fac[0] = C[0][0] = 1;
  for (int i = 1; i < N; i++) {
    fac[i] = fac[i-1] * i % mod;
    C[i][0] = C[i][i] = 1;
    for (int j = 1; j < i; j++)
      C[i][j] = (C[i-1][j-1] + C[i-1][j]) % mod;
  }
  int a, b, c;
  scanf("%d %d %d", &a, &b, &c);
  long long ans = ((calc(a, b) * calc(b, c) % mod) * calc(a, c)) % mod;
  ans %= mod;
  if (ans < 0)
    ans += mod;
  cout << ans << endl;
  return 0;
}