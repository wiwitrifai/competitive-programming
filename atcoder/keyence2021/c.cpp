#include <bits/stdc++.h>

using namespace std;

const int N = 5005, mod = 998244353;

char buff[10];
char s[N][N];

long long dp[2][N];
long long up[N], lef[2][N];

void upd(long long & var, long long val) {
  var += val;
  if (var >= mod)
    var -= mod;
}

int main() {
  int h, w, k;
  scanf("%d %d %d", &h, &w, &k);
  vector<tuple<int, int, char>> fixed;
  for (int i = 0; i < k; ++i) {
    int r, c;
    scanf("%d %d %s", &r, &c, buff);
    --r, --c;
    fixed.emplace_back(r, c, buff[0]);
  }
  sort(fixed.begin(), fixed.end());
  int cur = 0, nxt = 1;
  fill(dp[0], dp[0] + w, 0);
  fill(dp[1], dp[1] + w, 0);
  dp[nxt][0] = 1;
  int it = 0, it2 = 0;
  fill(up, up+w+1, 1);
  lef[nxt][0] = 1;
  for (int i = 0; i < w; ++i) {
    if (it2 < k && get<0>(fixed[it2]) == 0 && get<1>(fixed[it2]) == i) {
      lef[nxt][i+1] = lef[nxt][i];
      ++it2;
    } else {
      lef[nxt][i+1] = lef[nxt][i] * 3LL % mod;
    }
  }
  for (int r = 0; r < h; ++r) {
    swap(cur, nxt);
    fill(dp[nxt], dp[nxt] + w, 0);
    lef[nxt][0] = 1;
    for (int i = 0; i < w; ++i) {
      if (it2 < k && get<0>(fixed[it2]) == r+1 && get<1>(fixed[it2]) == i) {
        lef[nxt][i+1] = lef[nxt][i];
        ++it2;
      } else {
        lef[nxt][i+1] = lef[nxt][i] * 3LL % mod;
      }
    }
    for (int c = 0; c < w; ++c) {
      char val = '.';
      if (it < k && get<0>(fixed[it]) == r && get<1>(fixed[it]) == c) {
        val = get<2>(fixed[it]);
        ++it;
      }
      if (r + 1 < h) {
        long long cost = (val == '.' ? 2 : (val == 'R' ? 0 : 1));
        upd(dp[nxt][c], cost * dp[cur][c] * lef[nxt][c] % mod);
      }
      if (c + 1 < w) {
        long long cost = (val == '.' ? 2 : (val == 'D' ? 0 : 1));
        upd(dp[cur][c+1], cost * dp[cur][c] * up[c+1] % mod);
      }
      if (val == '.') {
        up[c] = up[c] * 3LL % mod;
      }
    }
  }
  long long ans = dp[cur][w-1] % mod;
  if (k == 0 || (get<0>(fixed[k-1]) != h-1 || get<1>(fixed[k-1]) != w-1))
    ans = ans * 3LL % mod;
  if (ans < 0)
    ans += mod;
  printf("%lld\n", ans);
  return 0;
}
