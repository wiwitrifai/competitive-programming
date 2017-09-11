#include <bits/stdc++.h>

using namespace std;

const int N = 1e5 + 5, mod = 1e9 + 7;

int n, m;

long long a[N], b[N];
int t[N], l[N], r[N];

int main() {
  int tt;
  scanf("%d", &tt);
  while (tt--) {
    scanf("%d %d", &n, &m);
    memset(a, 0, sizeof a);
    memset(b, 0, sizeof b);
    for (int i = 1; i <= m; i++) {
      scanf("%d %d %d", t+i, l+i, r+i);
    }
    long long cur = 1;
    for (int i = m; i > 0; i--) {
      cur = (cur + b[i]) % mod;
      if (t[i] == 2) {
        b[r[i]] = (b[r[i]] + cur) % mod;
        b[l[i]-1] = (b[l[i]-1] + mod - cur) % mod;
      }
      else {
        a[l[i]] = (a[l[i]] + cur) % mod;
        a[r[i]+1] = (a[r[i]+1] - cur) % mod;
      }
    }
    cur = 0;
    for (int i = 1; i <= n; i++) {
      cur = (a[i] + cur) % mod;
      if (cur < 0) cur += mod;
      printf("%lld%c", cur, i == n ? '\n' : ' ');
    }
  }
  return 0;
}