#include <bits/stdc++.h>

using namespace std;

vector<vector<int>> matrix;
vector<int> match, matched;
vector<bool> vis;
bool dfs(int v) {
  if (vis[v])
    return false;
  vis[v] = 1;
  for (int u = 0; u < (int)matrix.size(); ++u) {
    if (matrix[v][u] != 0) continue;
    if (matched[u] == -1 || dfs(matched[u])) {
      match[v] = u;
      matched[u] = v;
      return true;
    }
  }
  return false;
}

void matching(int val) {
  int n = matrix.size();
  match.assign(n, -1);
  matched.assign(n, -1);
  vis.assign(n, false);
  for (int i = 0; i < n; ++i) {
    assert(match[i] == -1);
    if (matrix[i][i] == val) {
      match[i] = i;
      matched[i] = i;
    }
  }

  while (1) {
    bool changed = 0;
    for (int i = 0; i < n; ++i)
      vis[i] = matrix[i][i] == val;
    for (int i = 0; i < n; ++i) {
      if (match[i] != -1) continue;
      changed |= dfs(i);
    }
    if (!changed)
      break;
  }

  for (int i = 0; i < n; ++i) {
    assert(match[i] != -1);
    int u = match[i];
    assert(matrix[i][u] == 0 || matrix[i][u] == val);
    matrix[i][u] = val;
  }
}

void solve() {
  int n, k;
  scanf("%d %d", &n, &k);
  matrix.assign(n, vector<int>(n, 0));
  for (int i = 0; i < n; ++i)
    matrix[i][i] = k / n;
  if (k % n) {
    if (n == 3 || k == n+1 || k == n * n - 1) {
      puts("IMPOSSIBLE");
      return;
    }
    int r = k % n;
    for (int i = 0; i < r; ++i)
      ++matrix[i][i];
    if (r == 1) {
      ++matrix[1][1];
      --matrix[2][2];
    }
    else if (r == n-1) {
      --matrix[n-2][n-2];
      ++matrix[0][0];
    }
  }
  vector<pair<int, int>> cnt;
  for (int i = 1; i <= n; ++i) {
    int c = 0;
    for (int j = 0; j < n; ++j)
      c += matrix[j][j] == i;
    cnt.emplace_back(c, i);
  }
  sort(cnt.begin(), cnt.end());
  reverse(cnt.begin(), cnt.end());
  for (auto it : cnt) {
    matching(it.second);
  }
  puts("POSSIBLE");
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < n; ++j)
      printf("%d%c", matrix[i][j], j + 1 == n ? '\n' : ' ');
  }
}

int main() {
#ifdef LOCAL
  time_t starttime = clock();
#endif
  int tt;
  scanf("%d", &tt);
  for (int tc = 1; tc <= tt; tc++) {
    printf("Case #%d: ", tc);
    solve();
#ifdef LOCAL
    cerr << "~ TC#" << tc << " done! execution time: " <<
      (double)(clock()-starttime) / CLOCKS_PER_SEC << " s" << endl;
#endif
  }
  return 0;
}
