#include <bits/stdc++.h>

using namespace std;

const int mod = 1e9 + 7;

long long powmod(long long b, long long p) {
  long long r = 1;
  for (; p; p >>= 1, b = b * b % mod)
    if (p & 1)
      r = r * b % mod;
    return r;
}
const int N = 1024;
long long C[N][N];

int main() {
  for (int i = 0; i < N; i++) {
    C[i][0] = C[i][i] = 1;
    for (int j = 1; j < i; j++)
      C[i][j] = (C[i-1][j-1] + C[i-1][j]) % mod;
  }
  int n;
  scanf("%d", &n);
  long long ans = 0;
  for (int i = 0; i <= n; i += 2) {
    ans = (ans + C[n][i] * powmod(2, n - i)) % mod;
  }
  if (ans < 0) ans += mod;
  cout << ans << endl;
  return 0;
}