#include <bits/stdc++.h>

using namespace std;

const int mod = 1e9 + 7, N = 505;

long long fix[N][N], up[N][N];

long long sup(int n, int k) {
  if (n == 0) return 1;
  if (k <= 0) return 0;
  long long & ret = up[n][k];
  if (ret != -1)
    return ret;
  n--;
  ret = 0;
  for (int i = 0; i <= n; i++) {
    ret = (ret + sup(i, k-1) * sup(n-i, k-1)) % mod;
  }
  return ret;
}
long long sfix(int n, int k) {
  if (n == 0) return k == 0;
  if (k <= 0 || (n < k)) return 0;
  long long & ret = fix[n][k];
  if (ret != -1)
    return ret;
  n--;
  ret = 0;
  for (int i = 0; i <= n; i++) {
    if (k >= 2) {
      ret = (ret + 2LL * sfix(i, k-1) * sup(n-i, k-2)) % mod;
      // cerr << n+1 << " " << k << " " << i << " " << n-i << " " << ret << endl;
      // cerr << sfix(i, k-1) << " " << sup(n-i, k-2) << endl;
    }
    ret = (ret + sfix(i, k-1) * sfix(n-i, k-1)) % mod;
  }
  // cerr << "fix " << n+1 << " " << k << " " << ret << endl;
  return ret;
}

int main() {
  memset(fix, -1, sizeof fix);
  memset(up, -1, sizeof up);
  int n, k;
  scanf("%d %d", &n, &k);
  cout << sfix(n, k) << endl;
  return 0;
}