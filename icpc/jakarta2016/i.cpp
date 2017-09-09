/**
 *  ACM ICPC Regional Jakarta 2016 - I : Peculiar Microwave
 */

#include <bits/stdc++.h>

using namespace std;

const int N = 1e6 + 4;

bool vis[N];
int n, p[N];

int main() {
  int tt;
  scanf("%d", &tt);
  for (int tc = 1; tc <= tt; tc++) {
    int n, e;
    scanf("%d %d", &n, &e);
    for (int i = 0; i < n; i++)
      scanf("%d", p+i);
    sort(p, p+n);
    n = unique(p, p+n) - p;
    int ans = 0;
    if (n == 1) {
      ans = (e + p[0] - 1) / p[0] * p[0] - e;
    }
    else {
      int ma = p[0] * p[1];
      if (e >= ma)
        ans = 0;
      else {
        fill(vis, vis+ma, 0);
        vis[0] = 1;
        for (int i = 0; i <= ma; i++) if (vis[i]) {
          if (i >= e) {
            ans = i-e;
            break;
          }
          for (int j = 0; j < n && i+p[j] <= ma; j++)
            vis[i+p[j]] = 1;
        }
      }
    }
    printf("Case #%d: %d\n", tc, ans);
  }
  return 0;
}