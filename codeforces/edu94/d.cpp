#include <bits/stdc++.h>

using namespace std;

const int N = 3030;

int lef[N][N];
int cnt[N], rig[N][N];
int a[N];

void solve() {
  int n;
  scanf("%d", &n);
  for (int i = 0; i < n; ++i) {
    scanf("%d", a+i);
    --a[i];
  }

  for (int i = 0; i < n; ++i)
    for (int j = 0; j < n; ++j)
      lef[i][j] = 0;
  for (int i = 0; i < n; ++i)
    for (int j = 0; j < n; ++j)
      rig[i][j] = 0;
  fill(cnt, cnt+n+1, 0);
  for (int i = n-1; i >= 0; --i) {
    for (int j = 0; j < n; ++j)
      rig[i][j] = rig[i+1][j];
    if (i+1 < n)
      ++rig[i][a[i+1]];
  }
  long long ans = 0;
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < n; ++j) {
      ans += 1LL * rig[i][j] * lef[a[i]][j];
    }
    for (int j = 0; j < n; ++j) {
      lef[j][a[i]] += cnt[j];
    }
    ++cnt[a[i]];
  }
  printf("%lld\n", ans);
}

int main() {
  int tc = 1;
  scanf("%d", &tc);
  while (tc--) {
    solve();
  }
  return 0;
}
