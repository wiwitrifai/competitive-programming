#include <bits/stdc++.h>

using namespace std;

const int N = 1e6 + 6;

int p[N], b[N];

int vis[N];

int main() {
  int n;
  scanf("%d", &n);
  for (int i = 0; i < n; i++) {
    scanf("%d", p+i);
    p[i]--;
  }
  int tot = 0;
  for (int i = 0; i < n; i++) {
    scanf("%d", b+i);
    tot ^= b[i];
  }
  int ans = 0;
  for (int i = 0; i < n; i++) if (!vis[i]) {
    int now = i;
    while (!vis[now]) {
      vis[now] = 1;
      now = p[now];
    }
    ans++;
  }
  if (ans == 1) ans = 0;
  if (!tot) ans++;
  printf("%d\n", ans);
  return 0;
}