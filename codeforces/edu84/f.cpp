#include <bits/stdc++.h>

using namespace std;

const int mod = 998244353, N = 5e5 + 5;

int l[N], r[N], x[N];

vector<int> last[N];
int cnt[N], pre[N];

int main() {
  int n, k, m;
  scanf("%d %d %d", &n, &k, &m);
  for (int i = 0; i < m; ++i) {
    scanf("%d %d %d", l+i, r+i, x+i);
    last[r[i]].push_back(i);
  }
  int nbit = 1 << k;
  long long ans = 1;
  for (int bit = 1; bit < nbit; bit <<= 1) {
    fill(cnt, cnt+n+2, 0);
    for (int i = 0; i < m; ++i) {
      if (bit & x[i]) {
        ++cnt[l[i]];
        --cnt[r[i]+1];
      }
    }
    pre[0] = 1;
    int leftmost = 0;
    int cur = 0;
    for (int i = 1; i <= n; ++i) {
      int now = 0;
      cur += cnt[i];
      if (cur == 0) {
        now = pre[i-1] - (leftmost ? pre[leftmost-1] : 0);
        if (now < 0)
          now += mod;
      }
      pre[i] = now + pre[i-1];
      if (pre[i] >= mod)
        pre[i] -= mod;
      for (int id : last[i]) {
        if ((x[id] & bit) == 0) {
          leftmost = max(leftmost, l[id]);
        }
      }
    }
    int now = pre[n] - (leftmost ? pre[leftmost-1] : 0);
    if (now < 0)
      now += mod;
    ans = 1LL * ans * now % mod;
  }
  ans %= mod;
  if (ans < 0)
    ans += mod;
  printf("%lld\n", ans);
  return 0;
}