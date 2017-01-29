#include <bits/stdc++.h>

using namespace std;

const int N = 2020;
const int mod = 1e9 + 7;

long long C[N][N];

char s[2][N];

int main() {
  int t = 1;
  // scanf("%d", &t);
  memset(C, 0, sizeof C);
  for (int i = 0; i < N; i++) {
    C[i][0] = C[i][i] = 1;
    for (int j = 1; j < i; j++)
      C[i][j] = (C[i-1][j-1] + C[i-1][j]) % mod;
  }
  while (t--) {
    // cerr << t << endl;
  int k, n;
  scanf("%s", s[1]);
  scanf("%s", s[0]);
  scanf("%d", &k);
  if (k == 0) {
    long long ans = 0;
    n = strlen(s[0]);
    int f = 0;
    while (f < n && s[0][f] == '0') f++;
    ans += max(n-f, 0);
    ans %= mod;
    f = 0;
    n = strlen(s[1]);
    while (f < n && s[1][f] == '0') f++;
    ans -= max(n-f, 0);
    f++;
    while (f < n && s[1][f] == '0') f++;
    if (f >= n)
      ans++;
    ans %= mod;
    if (ans < 0)
      ans += mod;
    printf("%lld\n", ans);
    continue;
  }
  k--;
  n = strlen(s[0]);
  int f = 0;
  while (f < n && s[0][f] == '0') f++;
  long long ans = 0;
  int kk = k;
  for (int j = kk+2; j < n-f; j++) {
    ans = (ans + 1LL * C[j-2][kk] * (n-f-j)) % mod;
  }
  // cerr << ans << " ";
  for (int i = f+1; i < n; i++) {
    if (kk < 0)
      break;
    if (s[0][i] == '1') {
      if (kk > 0)
        for (int j = kk; j < n-i; j++) {
          ans += C[j-1][kk-1];
          ans %= mod;
        }
      if (s[0][i-1] == '1' && kk == 0)
        ans++;
    }
    else kk--;
    // cerr << ans << " ";
  }
  // cerr << ans << endl;
  n = strlen(s[1]);
  f = 0;
  while (f < n && s[1][f] == '0') f++;
  kk = k;
  for (int j = kk+2; j < n-f; j++) {
    ans = (ans - (1LL * C[j-2][kk] * (n-f-j) % mod)) % mod;
    if (ans < 0)
      ans += mod;
  }
  // cerr << ans << " ";
  for (int i = f+1; i < n; i++) {
    if (kk < 0)
      break;
    if (s[1][i] == '1') {
      if (kk > 0)
        for (int j = kk; j < n-i; j++) {
          ans -= C[j-1][kk-1];
          ans %= mod;
        }
      if (s[1][i-1] == '1' && kk == 0)
        ans--;
    }
    else kk--;
    // cerr << ans << " ";
  }
  // cerr << ans << endl;
  int l = 0, r = strlen(s[0])-1;
  while (l <= r && s[0][l] == '0') l++;
  while (l <= r && s[0][r] == '0') r--;
  int cnt = 0;
  for (int i = l; i <= r; i++)
    cnt += s[0][i] == '0';
  if (cnt == k && l != r)
    ans++;
  ans %= mod;
  if (ans < 0)
    ans += mod;
  printf("%lld\n", ans);
}
  return 0;
}