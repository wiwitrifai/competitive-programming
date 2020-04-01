#include <bits/stdc++.h>

using namespace std;

const int N = 1024, mod = 1e9 + 7;
int n, m;
int node(int r, int c) {
  return r * m + c;
}

char s[N][N];
int p[N * N];

int find(int x) {
  return p[x] < 0 ? x : p[x] = find(p[x]);
}

int dp[N * N];
bool merge(int x, int y) {
  x = find(x);
  y = find(y);
  if (x == y)
    return false;
  p[x] = y;
  return true;
}


int main() {
  freopen("cave.in", "r", stdin);
  freopen("cave.out", "w", stdout);
  scanf("%d %d", &n, &m);
  for (int i = 0; i < n; ++i)
    scanf("%s", s[i]);
  fill(dp, dp+n*m+1, 1);
  fill(p, p+n*m+1, -1);
  for (int i = n-2; i >= 0; --i) {
    for (int j = 0; j + 1 < m; ++j) {
      if (s[i][j] == '.' && s[i][j+1] == '.') {
        merge(node(i, j), node(i, j+1));
      }
    }
    set<int> st;
    for (int j = 0; j < m; ++j) {
      if (s[i+1][j] == '#') continue;
      st.insert(find(node(i+1, j)));
    }
    for (int j = 0; j < m; ++j) {
      if (s[i+1][j] == '#') continue;
      if (s[i][j] == '#') continue;
      merge(node(i+1, j), node(i, j));
    }
    for (int cur : st) {
      int up = find(cur);
      if (up == cur) continue;
      dp[up] = 1LL * dp[up] * (dp[cur] + 1LL) % mod;
      dp[cur] = 0;
    }
  }
  long long ans = 1;
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < m; ++j) {
      if (s[i][j] == '#') continue;
      if (find(node(i, j)) != node(i, j)) continue;
      ans = ans * (dp[node(i, j)] + 1LL) % mod;
    }
  }
  printf("%lld\n", ans);
  return 0;
}
