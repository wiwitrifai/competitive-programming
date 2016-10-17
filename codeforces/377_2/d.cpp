#include <bits/stdc++.h>

using namespace std;

const int N = 1e5 + 5;

int n, m;
int d[N], a[N];
bool vis[N];

int main() {
  scanf("%d %d", &n, &m);
  long long sum = 0;
  for (int i = 0; i < n; i++)
    scanf("%d", d+i);
  for (int i = 1; i <= m; i++) {
    scanf("%d", a+i);
    sum += a[i];
  }
  int l = 0, r = n+1;
  while (l < r) {
    int mid = (l + r) >> 1;
    memset(vis, 0, sizeof vis);
    int cnt = 0;
    long long need = 0;
    for (int i = mid-1; i >= 0; i--) {
      if (d[i] && !vis[d[i]]) {
        need += a[d[i]];
        cnt++;
        vis[d[i]] = 1;
      }
      else {
        if (need)
          need--;
      }
    }
    if (need || cnt < m)
      l = mid + 1;
    else
      r = mid;
  }
  if (l > n)
    l = -1;
  printf("%d\n", l);
  return 0;
}