#include <bits/stdc++.h>

using namespace std;

const int N = 55;
const long long inf = 1e18;

long long dp[N][2][N][N];

vector<int> g[N];
int a[N], b[N], c[N], n;
int crime[N];

void dfs(int v, int pe = -1) {
  for (int e : g[v]) if (e != pe) {
    int u = v ^ a[e] ^ b[e];
    dfs(u, e);
    crime[v] += crime[u];
  }
}

long long tmp[N];

void go(int e, int d, int sisa, int depan) {
  long long & ret = dp[e][d][sisa][depan];
  if (ret != -1) return;
  if (sisa == 0) {
    ret = 0;
    return;
  }
  if (depan == 0) {
    ret = inf;
    return;
  }
  int v = d ? b[e] : a[e];
  if (g[v].size() == 1) {
    sisa -= depan;
    if (sisa == 0)
      ret = 0;
    else {
      go(e, d^1, sisa, sisa);
      ret = c[e] + dp[e][d^1][sisa][sisa];
    }
  }
  else {
    for (int f : g[v]) if (f != e) {
      for (int j = 0; j <= depan; j++)
        go(f, a[f] == v, sisa, j);
    }
    tmp[0] = inf;
    for (int i = 1; i <= depan; i++)
      tmp[i] = 0;
    for (int f : g[v]) if (f != e) {
      for (int j = depan; j > 0; j--) {
        for (int k = 1; k <= j; k++)
          tmp[j] = max(tmp[j], min(c[f] + dp[f][(a[f] == v)][sisa][k], tmp[j-k]));
      }
    }
    ret = tmp[depan];
  }
}

int main() {
  memset(dp, -1, sizeof dp);
  scanf("%d", &n);
  for (int i = 0; i < n-1; i++) {
    scanf("%d %d %d", a+i, b+i, c+i);
    a[i]--; b[i]--;
    g[a[i]].push_back(i);
    g[b[i]].push_back(i);
  }
  int s, m;
  scanf("%d %d", &s, &m);
  s--;
  for (int i = 0; i < m; i++) {
    int x;
    scanf("%d", &x);
    x--;
    crime[x]++;
  }
  dfs(s);
  long long ans = inf;
  for (int e : g[s]) {
    int v = s ^ a[e] ^ b[e];
    go(e, (a[e] == s), m, crime[v]);
    ans = min(c[e] + dp[e][a[e] == s][m][crime[v]], ans);
  }
  cout << ans << endl;
  return 0;
}