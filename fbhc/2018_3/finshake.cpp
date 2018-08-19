// fail
// belum penanganan overlap di satu titik

#include <bits/stdc++.h>

using namespace std;

const int N = 505, M = 55;

int n, m, w, h[N];
int cnt[N][N];
int dp[N * N][M], ids;
int l[N * N], r[N * N];
vector<int> bawah[N * N];
int temp[N];

void dfs(int id, int le = 0, int ri = n) {
  if (ri - le < 2) {
    for (int j = 0; j <= m; ++j) {
      int cur = j + cnt[le][ri-1];
      dp[id][j] = cur * (cur - 1) / 2;
    }
    return;
  }
  int mi = h[le];
  for (int i = le; i < ri; ++i) {
    mi = min(mi, h[i]);
  }
  int last = le;
  for (int i = le+1; i+1 < ri; ++i) {
    if (h[i] == mi) {
      bawah[id].push_back(ids);
      dfs(ids++, last, i+1);
      last = i;
    }
  }
  if (last < ri) {
    bawah[id].push_back(ids);
    dfs(ids++, last, ri);
  }
  for (int j = 0; j <= m; ++j) {
    int cur = cnt[le][ri-1] + j;
    dp[id][j] = cur * (cur - 1) / 2;
  }
  int cur = cnt[le][ri-1];
  for (auto it : bawah[id]) {
    for (int i = 0; i <= m; ++i) {
      temp[i] = dp[id][i];
      int ada = cur + i;
      if (ada > m) continue;
      for (int j = 0; j <= ada; ++j) {
        temp[i] = max(temp[i], dp[it][j] + dp[id][ada-j]);
      }
    }
    for (int i = 0; i <= m; ++i)
      dp[id][i] = temp[i];
  }
  cerr << " dfs " << le << " " << ri << " = ";
  cerr << cur << endl;
  for (int i = 0; i <= m; ++i) {
    cerr << le << " " << ri << " " << dp[id][i] << endl;
  }
}

void solve(int tc) {
  printf("Case #%d: ", tc);
  memset(cnt, 0, sizeof cnt);
  scanf("%d %d %d", &n, &m, &w);
  for (int i = 0; i < n; ++i)
    scanf("%d", h+i);
  for (int i = 0; i < m; ++i) {
    int p, jum;
    scanf("%d %d", &p, &jum);
    --p;
    int le = p, ri = p;
    while (le > 0) {
      if (h[le] + jum > w)
        --le;
      else
        break;
    }
    while (ri+1 < n) {
      if (h[ri] + jum > w)
        ++ri;
      else
        break;
    }
    cerr << le << " " << ri << endl;
    ++cnt[le][ri];
  }
  ids = 1;
  dfs(0, 0, n);
  for (int i = 0; i < ids; ++i) {
    bawah[i].clear();
  }
  int ans = dp[0][0];
  printf("%d\n", ans);
}

int main() {
  clock_t startt = clock();
  int tt;
  scanf("%d", &tt);
  for (int tc = 1; tc <= tt; ++tc) {
    solve(tc);
    fflush(stdout);
    cerr << " TC# " << tc << " done ! time : " << (double)(clock() - startt) / CLOCKS_PER_SEC << " s " << endl;
  }
  return 0;
}