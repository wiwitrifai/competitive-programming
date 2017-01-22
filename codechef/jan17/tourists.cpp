#include <bits/stdc++.h>

using namespace std;

const int N = 1e6 + 5;

vector < int > hamilton;
int p[N], din[N], used[N];
int a[N], b[N];
vector < pair<int, int> > adj[N];

void dfs(int v) {
  while (p[v] < adj[v].size()) {
    auto it = adj[v][p[v]++];
    if (used[it.second])
      continue;
    used[it.second] = 1;
    if (b[it.second] == v)
      swap(a[it.second], b[it.second]);
    dfs(it.first);
  }
  hamilton.push_back(v);
}

int main() {
  int n, m;
  scanf("%d %d", &n, &m);
  for (int i = 0; i < m; i++) {
    int u, v;
    scanf("%d %d", &u, &v);
    u--; v--;
    a[i] = u;
    b[i] = v;
    adj[u].push_back(make_pair(v, i));
    adj[v].push_back(make_pair(u, i));
  }
  for (int i = 0; i < n; i++) {
    if (adj[i].size() & 1) {
      puts("NO");
      return 0;
    }
    p[i] = 0;
  }
  dfs(0);
  if (hamilton.size() != m+1)
    puts("NO");
  else {
    puts("YES");
    for (int i = 0; i < m; i++) {
      printf("%d %d\n", a[i]+1, b[i]+1);
    }
  }
  return 0;
}