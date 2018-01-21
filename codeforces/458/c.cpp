#include <bits/stdc++.h>

using namespace std;

const int N = 1e5 + 5, M = 2024, mod = 1e9 + 7;

int f[N];
char s[N];
long long C[M][M];


int main() {
  for (int i = 0; i < M; ++i) {
    C[i][0] = C[i][i] = 1;
    for (int j = 1; j < i; ++j) {
      C[i][j] = (C[i-1][j-1] + C[i-1][j]) % mod;
    }
  }
  f[0] = -1e9;
  f[1] = 0;
  for (int i = 2; i < N; ++i) {
    f[i] = f[__builtin_popcount(i)] + 1;
  }
  int k;
  scanf("%s %d", s, &k);
  int cnt = 0;
  long long ans = 0;
  int n = strlen(s);
  if (k == 0) {
    puts("1");
    return 0;
  }
  for (int i = 0; i < n; ++i) {
    if (s[i] == '1') {
      int sisa = n-i-1;
      for (int j = 0; j <= sisa; ++j) {
        if ((j + cnt) == 0) continue;
        if (f[j + cnt] + 1 == k) {
          ans += C[sisa][j];
          if (ans >= mod) ans -= mod;
        }
      }
      ++cnt;
    }
  }
  if (cnt > 0 && (f[cnt] + 1) == k)
    ++ans;
  if (k == 1)
    --ans;
  ans %= mod;
  if (ans < 0) ans += mod;
  cout << ans << endl;
  return 0;
}