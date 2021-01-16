#include <bits/stdc++.h>

using namespace std;

void solve() {
  int n, m;
  scanf("%d %d", &n, &m);
  vector<int> to(n, -1), from(n, -1);
  for (int i = 0; i < m; ++i) {
    int x, y;
    scanf("%d %d", &x, &y);
    --x, --y;
    to[x] = y;
    from[y] = x;
  }
  for (int i = 0; i < n; ++i) {
    if (to[i] == i) {
      to[i] = from[i] = -1;
    }
  }
  int ans = 0;
  for (int i = 0; i < n; ++i) {
    if (from[i] != -1 || to[i] == -1 || to[i] == i) continue;
    int now = i;
    int cnt = 0;
    while (now != -1) {
      ++cnt;
      int nxt = to[now];
      to[now] = from[now] = -1;
      now = nxt;
    }
    ans += cnt-1;
  }
  for (int i = 0; i < n; ++i) {
    if (to[i] == -1 || to[i] == i) continue;
    int now = i;
    int cnt = 0;
    while (now != -1) {
      ++cnt;
      int nxt = to[now];
      to[now] = from[now] = -1;
      now = nxt;
    }
    ans += cnt;
  }
  printf("%d\n", ans);
}

int main() {
  int tc;
  scanf("%d", &tc);
  while (tc--) {
    solve();
  }
  return 0;
}
