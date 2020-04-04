#include <bits/stdc++.h>

using namespace std;

const int N = 22, mod = 1e9 + 7;

int cnt[N][N * N];

void add(int & var, int val) {
  var += val;
  if (var >= mod)
    var -= mod;
}

int main() {
  cnt[0][0] = 1;
  for (int i = 0; i+1 < N; ++i) {
    for (int j = 0; j < N * N; ++j) {
      if (cnt[i][j] == 0) continue;
      for (int k = 0; k <= 9; ++k) {
        add(cnt[i+1][j+k], cnt[i][j]);
      }
    }
  }
  int q;
  scanf("%d", &q);
  while (q--) {
    long long s;
    scanf("%lld", &s);
    int len = 1;
    long long now = 1;
    long long ans = 0;
    while (now <= s) {
      long long d = s / now;
      if ((s % now) == 0 && d <= len * 9) {
        ans = (ans + cnt[len][d]) % mod;
      }
      now = now * 10 + 1;
      ++len;
    }
    printf("%lld\n", ans);
  }
  return 0;
}
