#include <bits/stdc++.h>

using namespace std;

const int N = 2019, inf = 1e8;

char s[N];
int lef[N][N], rig[N][N];

void upd(int & var, int val) {
  if (var > val)
    var = val;
}


void solve() {
  int n;
  scanf("%d", &n);
  scanf("%s", s);
  if (n < 2) {
    puts("-1");
    return;
  }
  lef[0][0] = 1;
  for (int i = 0; i <= n; ++i) {
    fill(lef[i], lef[i]+n+1, inf);
    fill(rig[i], rig[i]+n+1, inf);
  }
  lef[0][0] = 0;
  rig[n][0] = 0;
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j <= i; ++j) {
      if (lef[i][j] >= inf) continue;
      upd(lef[i+1][j+1], lef[i][j] + (s[i] == '0'));
      if (i+2 <= n)
        upd(lef[i+2][j+1], lef[i][j] + (s[i] == '1') + (s[i+1] == '0'));
    }
  }
  for (int i = n; i > 0; --i) {
    for (int j = 0; j <= n; ++j) {
      if (rig[i][j] >= inf) continue;
      upd(rig[i-1][j+1], rig[i][j] + (s[i-1] == '0'));
      if (i-2 >= 0) {
        upd(rig[i-2][j+1], rig[i][j] + (s[i-1] == '1') + (s[i-2] == '0'));
      }
    }
  }
  int ans = inf;
  int one = 0;
  for (int i = 0; i < n; ++i)
    one += s[i] == '1';
  for (int i = 0; i + 1 < n; ++i) {
    for (int j = 0; j <= one; ++j) {
      ans = min(ans, lef[i][j] + rig[i+2][one-j] + (s[i] == '1') + (s[i+1] == '1'));
    }
  }
  if (ans >= inf)
    ans = -1;
  else
    ans /= 2;
  printf("%d\n", ans);
}

int main() {
  int tt;
  scanf("%d", &tt);
  for (int tc = 1; tc <= tt; ++tc) {
    printf("Case #%d: ", tc);
    solve();
  }
  return 0;
}
