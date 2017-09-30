#include <bits/stdc++.h>

using namespace std;

const int N = 55, inf = 1e9 + 8, mod = 1e9 + 7, M = 5e6 + 6;

int r, c, n;
int d[N][N], g[N][N];
int b[N][N], dx[] = {-1, 0, 1, 0}, dy[] = {0, -1, 0, 1};
pair<int, int > pos[N];
int dp[N][N];
int dp2[M];

void upd(int &le, int ri) {
  le += ri;
  if (le >= mod)
    le -= mod;
}

int main() {
  int t;
  scanf("%d", &t);
  while (t--) {
    scanf("%d %d %d", &r, &c, &n);
    for (int i = 0; i < r; i++) {
      for (int j = 0; j < c; j++) {
        scanf("%d", g[i]+j);
        if (g[i][j] < 0) {
          pos[-g[i][j]] = make_pair(i, j);
          g[i][j] = 0;
        }
      }
    }
    vector<int> val;
    for (int s = 0; s < c; s++) {
      for (int i = 0; i < r; i++) {
        for (int j = 0; j < c; j++)
          d[i][j] = inf;
      }
      d[0][s] = 1;
      set<pair<int, pair<int, int> > > st;
      st.insert(make_pair(0, make_pair(0, s)));
      while (!st.empty()) {
        auto it = st.begin();
        int x = it->second.first, y = it->second.second;
        st.erase(it);
        for (int i = 0; i < 4; i++) {
          int xx = x + dx[i], yy = y + dy[i];
          if (xx < 0 || xx >= r || yy < 0 || yy >= c) continue;
          int nd = d[x][y] + 1 + abs(max(g[x][y], 0) - max(g[xx][yy], 0));
          if (d[xx][yy] > nd) {
            st.erase(make_pair(d[xx][yy], make_pair(xx, yy)));
            d[xx][yy] = nd;
            st.insert(make_pair(d[xx][yy], make_pair(xx, yy)));
          }
        }
      }
      for (int i = 1; i <= n; i++) {
        b[i-1][s] = d[pos[i].first][pos[i].second];
        val.push_back(b[i-1][s]);
      }
    }
    sort(val.begin(), val.end());
    val.erase(unique(val.begin(), val.end()), val.end());
    for (int id = 0; id < val.size(); id++) {
      for (int i = 0; i <= n; i++)
        for (int j = 0; j <= c; j++)
          dp[i][j] = 0;
      dp[0][0] = 1;
      for (int i = 0; i < n; i++) {
        for (int j = 0; j < c; j++) {
          if (b[i][j] <= val[id])
            upd(dp[i+1][j+1], dp[i][j]);
          upd(dp[i][j+1], dp[i][j]); 
        }
      }
      dp2[id] = 0;
      for (int i = 0; i <= c; i++)
        upd(dp2[id], dp[n][i]);
    }
    int sum = 0;
    long long ans = 0;
    for (int i = 0; i < val.size(); i++) {
      dp2[i] = (dp2[i] - sum) % mod;
      if (dp2[i] < 0) dp2[i] += mod;
      ans = (ans + 1LL * dp2[i] * val[i]) % mod;
      sum = (sum + dp2[i]) % mod;
    }
    if (ans < 0)
      ans += mod;
    printf("%lld\n", ans);
  }
  return 0;
}