#include <bits/stdc++.h>

using namespace std;

const int N = 101, M = 1001;

char s[N][M];

int main() {
  int t;
  scanf("%d", &t);
  while (t--) {
    int n, m, x, y;
    scanf("%d %d %d %d", &n, &m, &x, &y);
    y = min(y, x * 2);
    for (int i = 0; i < n; ++i) {
      scanf("%s", s[i]);
    }
    long long ans = 0;
    for (int i = 0; i < n; ++i) {
      for (int j = 0; j < m; ++j) {
        if (s[i][j] != '.') continue;
        if (j + 1 < m && s[i][j+1] == '.') {
          ans += y;
          s[i][j+1] = '*';
        } else {
          ans += x;
        }
        s[i][j] = '*';
      }
    }
    printf("%lld\n", ans);
  }
  return 0;
}
