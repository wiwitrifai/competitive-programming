#include <bits/stdc++.h>

using namespace std;

const int N = 1e5 + 5;

vector<int> g[N];

int col[N];
void get(int v, int par, int res[N][2]) {
  res[v][0] = res[v][1] = 0;
  ++res[v][col[v]];
  for (int u : g[v]) {
    if (u == par) continue;
    get(u, v, res);
    res[v][0] += res[u][0];
    res[v][1] += res[u][1];
  }
}

void color(int v, int c, int par) {
  col[v] = c;
  for (int u : g[v]) {
    if (u == par) continue;
    color(u, c^1, v);
  }
}

int ori[N][2], cnt[2][N][2];

const long long inf = 1e18;
char s[N];

void solve() {
  int n;
  scanf("%d", &n);
  for (int i = 0; i < n; ++i)
    g[i].clear();
  for (int i = 0; i < n-1; ++i) {
    int x, y;
    scanf("%d %d", &x, &y);
    --x, --y;
    g[x].push_back(y);
    g[y].push_back(x);
  }
  scanf("%s", s);
  for (int i = 0; i < n; ++i)
    col[i] = s[i] - '0';
  long long ans = inf;
  get(0, 0, ori);
  for (int c = 0; c < 2; ++c) {
    color(0, c, 0);
    get(0, 0, cnt[c]);
    if (ori[0][0] == cnt[c][0][0] && ori[0][1] == cnt[c][0][1]) {
      long long cur = 0;
      for (int i = 0; i < n; ++i) {
        cur += abs(cnt[c][i][0] - ori[i][0]);
      }
      ans = min(ans, cur);
    }
  }

  if (ans >= inf)
    ans = -1;
  printf("%lld\n", ans);
}

int main() {
  int tc;
  scanf("%d", &tc);
  while (tc--) {
    solve();
  }
  return 0;
}
