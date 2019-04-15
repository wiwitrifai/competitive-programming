#include <bits/stdc++.h>

using namespace std;

const int N = 1024;

int vis[N], deliver[N];

int main() {
  int n, m;
  scanf("%d %d", &n, &m);
  for (int i = 0; i < m; ++i) {
    int x;
    scanf("%d", &x);
    x %= n;
    deliver[x] = 1;
  }
  int ans = n + 1;
  for (int x = 1; x < n; ++x) {
    memset(vis, 0, sizeof vis);
    int cnt = m, cur = 0, now = 1;
    while (!vis[now] && cnt > 0) {
      ++cur;
      vis[now] = 1;
      if (deliver[now]) {
        --cnt;
      }
      now = (now + x) % n;
    }
    if (cnt == 0) {
      ans = min(ans, cur);
    }
  }
  printf("%d\n", ans);
  return 0;
}
