#include <bits/stdc++.h>

using namespace std;

const int N = 20;

int g[N][N], used[N];
long long ans;
int n;

void dfs(int v = 0, int cnt = 0, int ma = 0, int sum = 0) {
  if (v == n) {
    if (cnt < 3 || 2 * ma >= sum)
      return;
    ++ans;
    return;
  }
  if (used[v]) {
    dfs(v+1, cnt, ma, sum);
    return;
  }
  for (int i = v+1; i < n; ++i) {
    if (used[i] || g[v][i] == 0) continue;
    used[i] = 1;
    dfs(v+1, cnt+1, max(ma, g[v][i]), sum + g[v][i]);
    used[i] = 0;
  }
  dfs(v+1, cnt, ma, sum);
}

void solve() {
  scanf("%d", &n);
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < n; ++j)
      scanf("%d", g[i]+j);
  }
  ans = 0;
  memset(used, 0, sizeof used);
  dfs();
  printf("%lld\n", ans);
}

int main() {
  time_t startt = clock();
  int tt;
  scanf("%d", &tt);
  for (int tc = 1; tc <= tt; tc++) {
    printf("Case #%d: ", tc);
    solve();
    cerr << "~ #" << tc << " done! time : " << (double)(clock()-startt) * 1000/CLOCKS_PER_SEC << " ms" << endl;
  }
  return 0;
}