#include <bits/stdc++.h>

using namespace std;

const int N = 303;

int x[N], y[N], w[N], n, m;

int main() {
  scanf("%d %d", &n, &m);
  for (int i = 0; i < m; i++) {
    scanf("%d %d %d", x+i, y+i, w+i);
  }
  int ans = 0;
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      int cur = 0;
      for (int k = 0; k < m; k++) {
        int d = max(abs(x[k] - i), abs(y[k] - j));
        cur += max(w[k]-d, 0);
      }
      ans = max(ans, cur);
    }
  }
  printf("%d\n", ans);
  return 0;
}
