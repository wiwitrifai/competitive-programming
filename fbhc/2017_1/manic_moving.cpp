#include <bits/stdc++.h>

using namespace std;

const int N = 102, K = 5005;
const long long inf = 1e16;
long long g[N][N];
int s[K], d[K];
long long dp[K][N][3];

int main() {
  time_t start_t = clock();
  cerr << "START!" << endl;
  int t;
  scanf("%d", &t);
  for (int tc = 1; tc <= t; tc++) {
    int n, m, k;
    scanf("%d %d %d", &n, &m, &k);
    for (int i = 0; i < n; i++)
      for (int j = 0; j < n; j++)
        g[i][j] = i == j ? 0 : inf;
    for (int i = 0; i < m; i++) {
      int u, v, w;
      scanf("%d %d %d", &u, &v, &w);
      u--; v--;
      if (g[u][v] > w) {
        g[u][v] = g[v][u] = w;
      }
    }
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < n; j++) {
        for (int kk = 0; kk < n; kk++) {
          g[j][kk] = min(g[j][kk], g[j][i]+g[i][kk]);
        }
      }
    }
    // for (int i = 0; i < n; i++) {
    //   for (int j = 0; j < n; j++)
    //     cerr << g[i][j] << " ";
    //   cerr << endl;
    // }
    for (int i = 1; i <= k; i++) {
      scanf("%d %d", s+i, d+i);
      s[i]--; d[i]--;
    }
    for (int i = 0; i <= k; i++)
      for (int j = 0; j <= n; j++)
        dp[i][j][0] = dp[i][j][1] = dp[i][j][2] = inf;
    set< pair< pair<long long, int>, pair< int, int > > > st;
    dp[0][0][0] = 0;
    st.insert(make_pair(make_pair(0, 0), make_pair(0, 0)));
    long long ans = -1;
    while (!st.empty()) {
      auto it = st.begin();
      long long dist = it->first.first, prog = it->first.second, pos = it->second.first, fill = it->second.second;
      // cerr << dist << " " << prog << " " << pos << " " << fill << endl;
      if (prog == k && fill == 0) {
        ans = dist;
        // break;
      }
      st.erase(it);
      // loading
      if (prog < k && fill < 2) {
        long long & cur = dp[prog+1][s[prog+1]][fill+1];
        if (cur > dist + g[pos][s[prog+1]]) {
          st.erase(make_pair(make_pair(cur, prog+1), make_pair(s[prog+1], fill+1)));
          cur = dist + g[pos][s[prog+1]];
          st.insert(make_pair(make_pair(cur, prog+1), make_pair(s[prog+1], fill+1)));
        }
      }
      // unloading
      if (fill == 2) {
        long long & cur = dp[prog][d[prog-1]][fill-1];
        if (cur > dist + g[pos][d[prog-1]]) {
          st.erase(make_pair(make_pair(cur, prog), make_pair(d[prog-1], fill-1)));
          cur = dist + g[pos][d[prog-1]];
          st.insert(make_pair(make_pair(cur, prog), make_pair(d[prog-1], fill-1)));
        }
      }
      if (fill == 1) {
        long long & cur = dp[prog][d[prog]][fill-1];
        if (cur > dist + g[pos][d[prog]]) {
          st.erase(make_pair(make_pair(cur, prog), make_pair(d[prog], fill-1)));
          cur = dist + g[pos][d[prog]];
          st.insert(make_pair(make_pair(cur, prog), make_pair(d[prog], fill-1)));
        }
      }
    }  
    printf("Case #%d: %d\n", tc, ans);
    cerr << "TC #"<< tc << " : done! time: " << (double)(clock()-start_t) * 1000 / CLOCKS_PER_SEC << " ms" << endl;
  }
  return 0;
}