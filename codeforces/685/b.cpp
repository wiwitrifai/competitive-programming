#include <bits/stdc++.h>

using namespace std;

const int N = 212;

char s[N];
int cnt[N][2];

void solve() {
  int n, q;
  scanf("%d %d", &n, &q);
  scanf("%s", s);
  cnt[0][0] = cnt[0][1] = 0;
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < 2; ++j)
      cnt[i+1][j] = cnt[i][j];
    s[i] -= '0';
    ++cnt[i+1][s[i]];
  }
  while (q--) {
    int l, r;
    scanf("%d %d", &l, &r);
    --l, --r;
    bool ada = ((cnt[l][s[l]] - cnt[0][s[l]]) >= 1) || ((cnt[n][s[r]] - cnt[r+1][s[r]]) >= 1);
    puts(ada ? "YES" : "NO");
  }
}

int main() {
  int tc = 1;
  scanf("%d", &tc);
  while (tc--) {
    solve();
  }
  return 0;
}
