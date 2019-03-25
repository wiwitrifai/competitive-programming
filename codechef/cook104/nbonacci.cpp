#include <bits/stdc++.h>

using namespace std;

const int N = 1e5 + 5;

int f[N];
int s[N];

void solve() {
  int n, q;
  scanf("%d %d", &n, &q);
  f[n] = 0;
  for (int i = 0; i < n; ++i) {
    scanf("%d", f+i);
    f[n] ^= f[i];
  }
  for (int i = 0, now = 0; i <= n; ++i) {
    now ^= f[i];
    s[i] = now;
  }
  for (int i = 0; i < q; ++i) {
    int k;
    scanf("%d", &k);
    int w = k / (n + 1);
    k %= n+1;
    int ans = 0;
    if (w & 1)
      ans ^= s[n];
    if (k)
      ans ^= s[k-1];
    printf("%d\n", ans);
  }
}

int main() {
  int tt = 1;
  // scanf("%d", &tt);
  while (tt--) {
    solve();
  }
  return 0;
}
