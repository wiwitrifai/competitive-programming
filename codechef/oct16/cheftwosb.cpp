#include <bits/stdc++.h>

using namespace std;

char a[12], b[12];
bool vis[12];

int main() {
  int t;
  scanf("%d", &t);
  while (t--) {
    scanf("%s %s", a, b);
    int n = strlen(a);
    int ans = 0;
    for (int i = 0; i < (1<<n); i++) {
      for (int j = 0; j < n; j++) if (i & (1<<j))
        swap(a[j], b[j]);
      int now = 0;
      memset(vis, 0, sizeof vis);
      int cnt = 0;
      while (cnt < n) {
        vis[now] = 1;
        cnt++;
        int x = a[now]-'0';
        if (now-x>=0 && !vis[now-x]) {
          now -= x;
        }
        else if (now+x<n && !vis[now+x]) {
          now += x;
        }
        else
          break;
      }
      if (cnt < n || now != n-1) {
        for (int j = 0; j < n; j++) if (i & (1<<j))
          swap(a[j], b[j]);
        continue;
      }
      now = 0;
      memset(vis, 0, sizeof vis);
      cnt = 0;
      while (cnt < n) {
        vis[now] = 1;
        cnt++;
        int x = b[now]-'0';
        if (now-x>=0 && !vis[now-x]) {
          now -= x;
        }
        else if (now+x<n && !vis[now+x]) {
          now += x;
        }
        else
          break;
      }
      if (cnt < n || now != n-1) {
        for (int j = 0; j < n; j++) if (i & (1<<j))
          swap(a[j], b[j]);
        continue;
      }
      for (int j = 0; j < n; j++) if (i & (1<<j))
        swap(a[j], b[j]);
      ans++;
    }
    printf("%d\n", ans);
  }
  return 0;
}