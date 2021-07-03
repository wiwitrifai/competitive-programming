#include <bits/stdc++.h>

using namespace std;

int main() {
  int n;
  scanf("%d", &n);
  vector<int> p(n), a(n);
  for (int i = 0; i < n; ++i) {
    scanf("%d", &p[i]);
  }
  for (int i = 0; i < n; ++i) {
    scanf("%d", &a[i]);
    --a[i];
  }
  long long ans = 0;
  vector<int> vis(n, 0);
  for (int i = 0; i < n; ++i) {
    if (vis[i]) continue;
    int now = i;
    while (vis[now] == 0) {
      vis[now] = 1;
      now = a[now];
    }
    if (vis[now] == 1) {
      int cost = p[now];
      while (vis[now] != 2) {
        vis[now] = 2;
        cost = min(cost, p[now]);
        now = a[now];
      }
      ans += cost;
    }
    now = i;
    while (vis[now] != 2) {
      vis[now] = 2;
      now = a[now];
    }
  }
  printf("%lld\n", ans);
  return 0;
}
