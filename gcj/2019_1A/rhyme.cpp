#include <bits/stdc++.h>

using namespace std;

const int N = 1024, K = 55;

char s[N][K];
int len[N], ma[N];
int g[N][N];
bool used[N];
queue<pair<int, int> > pairs[K];

void solve(int tc) {
  int n;
  scanf("%d", &n);
  for (int i = 0; i < n; ++i) {
    scanf("%s", s[i]);
    len[i] = strlen(s[i]);
    ma[i] = len[i];
  }
  for (int i = 0; i < K; ++i) {
    while (!pairs[i].empty())
      pairs[i].pop();
  }
  for (int i = 0; i < n; ++i) {
    for (int j = i+1; j < n; ++j) {
      int now = 0;
      while (now < len[i] && now < len[j] && s[i][len[i]-now-1] == s[j][len[j]-now-1]) ++now;
      g[i][j] = g[j][i] = now;
      if (now > 0)
        pairs[now].emplace(i, j);
    }
    g[i][i] = 0;
  }
  memset(used, 0, sizeof used);
  int ans = 0;
  for (int x = K-1; x > 0; --x) {
    while (!pairs[x].empty()) {
      int u, v;
      tie(u, v) = pairs[x].front();
      pairs[x].pop();
      if (used[u] || used[v]) continue;
      if (ma[u] < x || ma[v] < x) {
        int d = min(x, min(ma[u], ma[v]));
        pairs[d].emplace(u, v);
        continue;
      }
      used[u] = 1;
      used[v] = 1;
      ans += 2;
      for (int i = 0; i < n; ++i) {
        if (used[i]) continue;
        if (g[i][u] >= x || g[i][v] >= x) {
          ma[i] = min(ma[i], x-1);
        }
      }
    }
  }
  printf("Case #%d: %d\n", tc, ans);
}

int main() {
  time_t startt = clock();
  int tt;
  scanf("%d", &tt);
  for (int tc = 1; tc <= tt; tc++) {
    solve(tc);
    cerr << "~ #" << tc << " done! time : " << (double)(clock()-startt)/CLOCKS_PER_SEC << " s" << endl;
  }
  return 0;
}
