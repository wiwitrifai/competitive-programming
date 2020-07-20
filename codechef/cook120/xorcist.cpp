#include <bits/stdc++.h>

using namespace std;

const int N = 5e5 + 5;

int f[N][30], s[N][30];
int zero[N];

void solve() {
  int n, q;
  scanf("%d %d", &n, &q);
  for (int i = 0; i < n; ++i) {
    int x;
    scanf("%d", &x);
    int last = -1;
    for (int j = 0; j < 30; ++j) {
      f[i+1][j] = f[i][j];
      s[i+1][j] = s[i][j];
    }
    zero[i+1] = zero[i];
    for (int j = 0; j < 30; ++j) {
      if (x & (1 << j)) {
        if (last != -1) {
          ++s[i+1][last];
        }
        last = j;
      }
    }
    if (last != -1) {
      ++f[i+1][last];
    } else {
      ++zero[i+1];
    }
  }
  for (int i = 0; i < q; ++i) {
    int l, r;
    scanf("%d %d", &l, &r);
    --l;
    int len = r - l;
    int cnt = zero[r] - zero[l];
    long long ans = 1LL * cnt * (len - cnt);
    ans += 1LL * cnt * cnt;
    for (int j = 0; j < 30; ++j) {
      ans += 1LL * (f[r][j] - f[l][j]) * (s[r][j] - s[l][j]);
    }
    printf("%lld\n", ans);
  }
}

int main() {
  int tc = 1;
  scanf("%d", &tc);
  while (tc--) {
    solve();
  }
  return 0;
}
