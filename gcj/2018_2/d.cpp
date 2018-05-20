#include <bits/stdc++.h>

using namespace std;

const int N = 22;

char s[N][N];
int vis[N][N], val[N][N], valid[N][N];
int n, m;
int dx[] = {-1, 0, 1, 0}, dy[] = {0, -1, 0, 1};
void dfs(int r, int c, int to) {
  if (r < 0 || r >= n || c < 0 || c >= m) return;
  if (!valid[r][c] || vis[r][c] == to) return;
  vis[r][c] = to;
  for (int i = 0; i < 4; ++i)
    dfs(r+dx[i], c+dy[i], to);
}

int cnt[N * N];

int calc() {
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < m; ++j) {
      valid[i][j] = 0;
      if (val[i][j] == 1 && s[i][j] == 'B')
        valid[i][j] = 1;
      else if (val[i][j] == 0 && s[i][j] == 'W')
        valid[i][j] = 1;
    }
  }
  memset(vis, 0, sizeof vis);
  int all = 1;
  for (int i = 0; i < n; ++i)
    for (int j = 0; j < m; ++j) if (vis[i][j] == 0) {
      dfs(i, j, all++);
    }
  memset(cnt, 0, sizeof cnt);
  for (int i = 0; i < n; ++i)
    for (int j = 0; j < m; ++j)
      ++cnt[vis[i][j]];
  int ans = 0;
  for (int i = 1; i < all; ++i)
    ans = max(ans, cnt[i]);
  return ans;
}

void solve(int tc) {
  printf("Case #%d: ", tc);
  int ans = 0;
  scanf("%d %d", &n, &m);
  for (int i = 0; i < n; ++i) {
    scanf("%s", s[i]);
  }
  vector<vector<int> > st;
  st.push_back(vector<int>({0, 0, 0, 0}));
  st.push_back(vector<int>({1, 1, 1, 1}));
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < m; ++j) {
      if (i > 0) {
        int a = s[i-1][j] == 'B', b = s[i][j] == 'B';
        st.push_back(vector<int>({a, a, b, b}));
      }
      if (j > 0) {
        int a = s[i][j-1] == 'B', b = s[i][j] == 'B';
        st.push_back(vector<int>({a, b, a, b}));
      }
      if (i > 0 && j > 0) {
        int a = s[i-1][j-1] == 'B', b = s[i-1][j] == 'B';
        int c = s[i][j-1] == 'B', d = s[i][j] == 'B';
        st.push_back(vector<int>({a, b, c, d}));
      }
    }
  }
  sort(st.begin(), st.end());
  st.erase(unique(st.begin(), st.end()), st.end());
  for (int k = 0; k < st.size(); ++k) {
    for (int a = 0; a <= n; ++a) {
      for (int b = 0; b <= m; ++b) {
        for (int i = 0; i < a; ++i) {
          for (int j = 0; j < b; ++j) {
            val[i][j] = st[k][0];
          }
        }
        for (int i = 0; i < a; ++i) {
          for (int j = b; j < m; ++j) {
            val[i][j] = st[k][1];
          }
        }
        for (int i = a; i < n; ++i) {
          for (int j = 0; j < b; ++j) {
            val[i][j] = st[k][2];
          }
        }
        for (int i = a; i < n; ++i) {
          for (int j = b; j < m; ++j) {
            val[i][j] = st[k][3];
          }
        }
        ans = max(ans, calc());
      }
    }
  }
  printf("%d\n", ans);
}

int main() {
  int tt;
  scanf("%d", &tt);
  for (int tc = 1; tc <= tt; ++tc) {
    solve(tc);
  }
  return 0;
}