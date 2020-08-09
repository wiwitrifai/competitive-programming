#include <bits/stdc++.h>

using namespace std;

const int N = 121;

char s[N][N];

void solve() {
  int n, m;
  scanf("%d %d", &n, &m);
  int ans = 0;
  for (int i = 0; i < n; ++i) {
    scanf("%s", s[i]);
    if (i == n-1) {
      for (int j = 0; j < m-1; ++j)
        ans += s[i][j] == 'D';
    } else {
      ans += s[i][m-1] == 'R';
    }
  }
  printf("%d\n", ans);
}

int main() {
  int tc = 1;
  scanf("%d", &tc);
  while (tc--) {
    solve();
  }
  return 0;
}
