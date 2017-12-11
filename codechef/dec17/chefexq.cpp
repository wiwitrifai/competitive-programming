#include <bits/stdc++.h>

using namespace std;

const int N = 1e5 + 5, MAGIC = 432, SZ = N / MAGIC + 5;

map<int, int> cnt[SZ];
int a[N], all[SZ];

int main() {
  int n, q;
  scanf("%d %d", &n, &q);
  for (int i = 0; i < n; i++)
    scanf("%d", a+i);
  int nogroup = n / MAGIC + 1;
  for (int ng = 0; ng < nogroup; ++ng) {
    cnt[ng].clear();
    int until = min((ng + 1) * MAGIC, n);
    int now = 0;
    for (int i = ng * MAGIC; i < until; ++i) {
      now ^= a[i];
      cnt[ng][now]++;
    }
    all[ng] = now;
  }
  while (q--) {
    int t, x, y;
    scanf("%d %d %d", &t, &x, &y);
    x--;
    if (t == 1) {
      a[x] = y;
      int ng = x/MAGIC;
      cnt[ng].clear();
      int until = min((ng + 1) * MAGIC, n);
      int now = 0;
      for (int i = ng * MAGIC; i < until; ++i) {
        now ^= a[i];
        cnt[ng][now]++;
      }
      all[ng] = now;
    }
    else {
      int ans = 0, now = y;
      int ng = x/MAGIC;
      for (int i = 0; i < ng; ++i) {
        auto it = cnt[i].find(now);
        if (it != cnt[i].end())
          ans += it->second;
        now ^= all[i];
      }
      for (int i = ng * MAGIC; i <= x; i++) {
        now ^= a[i];
        if (now == 0)
          ans++;
      }
      printf("%d\n", ans);
    }
  }
  return 0;
}