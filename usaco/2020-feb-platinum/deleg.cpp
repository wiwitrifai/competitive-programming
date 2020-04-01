#include <bits/stdc++.h>

using namespace std;

vector<vector<int>> g;
vector<vector<int>> paths;

int solve(int v, int len, int par = -1) {
  paths[v].clear();
  for (int u : g[v]) {
    if (u == par) continue;
    int res = solve(u, len, v) + 1;
    if (res <= 0)
      return -1;
    paths[v].push_back(res);
  }
  sort(paths[v].begin(), paths[v].end());
  set<pair<int, int>> st;
  for (int i = 0; i < (int)paths[v].size(); ++i)
    st.insert(make_pair(paths[v][i], i));
  pair<int, int> ret = {0, 0};
  int single = 0;
  for (int i = 0; i < (int)paths[v].size(); ++i) {
    pair<int, int> now = {paths[v][i], i};
    auto it = st.find(now);
    if (it == st.end()) continue;
    st.erase(it);
    if (now.first >= len) {
      single = max(now.first, single);
      continue;
    }
    int sisa = len - now.first;
    it = st.lower_bound({sisa, -1});
    if (it == st.end()) {
      if (ret.first)
        return -1;
      ret = now;
      continue;
    }
    if (it->first >= len) {
      single = max(single, now.first);
    }
    st.erase(it);
  }
  return ret.first == 0 ? single : ret.first;
}

int main() {
  const string problem_name = "deleg";
  freopen((problem_name + ".in").c_str(), "r", stdin);
  freopen((problem_name + ".out").c_str(), "w", stdout);

  int n;
  scanf("%d", &n);
  g.resize(n);
  paths.resize(n);
  for (int i = 0; i < n-1; ++i) {
    int u, v;
    scanf("%d %d", &u, &v);
    --u, --v;
    g[u].push_back(v);
    g[v].push_back(u);
  }

  int root = -1;
  for (int i = n-1; i >= 0; --i)
    if (g[i].size() <= 1)
      root = i;
  int low = 0, hig = n-1;
  while (low < hig) {
    int mid = (low + hig + 1) / 2;
    int res = solve(root, mid);
    if (res >= mid)
      low = mid;
    else
      hig = mid-1;
  }
  printf("%d\n", low);

  fclose(stdin);
  fclose(stdout);
  return 0;
}
