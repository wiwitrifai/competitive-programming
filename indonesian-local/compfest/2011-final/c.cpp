#include <bits/stdc++.h>

using namespace std;

const int N = 1024;

int up[N+N], down[N + N];
int p[N][N], n, m;

int main() {
  int t;
  scanf("%d", &t);
  while (t--) {
    memset(up, 0, sizeof up);
    memset(down, 0, sizeof down);
    scanf("%d %d", &n, &m);
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < m; j++) {
        scanf("%d", p[i]+j);
        up[i+j] += p[i][j];
        down[i+N-j] += p[i][j];
      }
    }
    int ans = 0;
    for (int i = 0; i < n; i++)
      for (int j = 0; j < m; j++) {
        ans = max(ans, up[i+j] + down[i+N-j] - 2 * p[i][j]);
      }
    printf("%d\n", ans);
  }
  return 0;
}