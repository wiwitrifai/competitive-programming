#include <bits/stdc++.h>

using namespace std;

const int N = 1e6 + 5;

vector<pair<int, int>> edge[N];   // ke, id
vector<int> ans;

void dfs(int now, int st) {
  for (auto it : edge[now]) {
    if (it.second <= st) break;
    ans.push_back(it.first);
    if (ans.size() > N) break;
    dfs(it.first, it.second);
  }
}

int main() {
  int n, l, r;
  scanf("%d %d %d", &n, &l, &r);
  for (int i = 0; i < n; i++) {
    int u, v;
    scanf("%d %d", &u, &v);
    edge[u].emplace_back(v, i);
  }
  for (int i = 0; i < N; i++) reverse(edge[i].begin(), edge[i].end());
  ans.push_back(0);
  dfs(0, -1);
  for (int i = l; i < r; i++) printf("%d ", ans[i % ans.size()]);
  return 0;
}