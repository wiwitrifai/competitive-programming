#include <bits/stdc++.h>

using namespace std;

const int M = 1e4 + 4, N = 4004, inf = 1e9 + 7;

int p[N];

int find(int x) {
  return p[x] < 0 ? x : p[x] = find(p[x]);
}

void merge(int u, int v) {
  u = find(u);
  v = find(v);
  if (u == v)
    return;
  if (-p[u] > -p[v])
    swap(u, v);
  p[v] += p[u];
  p[u] = v;
}
int n, m;
int x[M], y[M], col[N];
int dp[N][N];

void read_input() {
  scanf("%d %d", &n, &m);
  for (int i = 0; i < m; ++i) {
    scanf("%d %d", x+i, y+i);
    --x[i], --y[i];
  }
}

void solve() {
  fill(p, p+n, -1);
  for (int i = 0; i < m; ++i) {
    int l = x[i], r = y[i];
    while (l < r) {
      merge(l, r);
      ++l;
      --r;
    }
  }
  vector<pair<int, int>> ids;
  int tot = 0;
  for (int i = 0; i < n; ++i)
    if (p[i] < 0) {
      ids.emplace_back(-p[i], i);
      tot += -p[i];
    }
  assert(tot == n);
  for (int i = 0; i <= (int)ids.size(); ++i)
    for (int j = 0; j <= n; ++j)
      dp[i][j] = -1;
  dp[0][0] = 0;
  for (int i = 0; i < (int)ids.size(); ++i) {
    int now = ids[i].first;
    for (int j = 0; j <= n; ++j) {
      if (dp[i][j] == -1) continue;
      dp[i+1][j] = 0;
      if (j + now <= n) {
        dp[i+1][j+now] = 1;
      }
    }
  }
  int best = -1;
  int sz = ids.size();
  for (int i = 0; i <= n; ++i) {
    if (dp[sz][i] == -1) continue;
    if (best == -1 || abs(n-2*best) > abs(n-2*i))
      best = i;
  }
  assert(best != -1);
  int res  = abs(n - 2 * best);

  for (int i = sz; i > 0; --i) {
    int v = ids[i-1].second, w = ids[i-1].first;
    col[v] = dp[i][best];
    if (dp[i][best])
      best -= w;
  }
  assert(best == 0);
  int sum = 0;
  for (int i = 0; i < n; ++i) {
    printf("%d", col[find(i)]);
    sum += col[find(i)];
  }
  assert(abs(n-2*sum) == res);
  printf("\n");
}

int main(int argc, char * argv[]) {
  clock_t starttime = clock();
  int seed = time(0);
  if (argc >= 2) {
    seed = atoi(argv[1]);
  }
  cerr << "random seed\t= " << seed << endl;
  srand(seed);

  int tt;
  scanf("%d", &tt);
  for (int tc = 1; tc <= tt; ++tc) {
    printf("Case #%d: ", tc);
    read_input();
    solve();
    fflush(stdout);
    cerr << "~ TC#" << tc << " done! execution time : " <<
      (double)(clock() - starttime) / CLOCKS_PER_SEC << " s " << endl;
  }
  return 0;
}
