#include <bits/stdc++.h>

using namespace std;

typedef pair<int, int> point;

const int N = 1024;
point a[N], b[N];

bool cek(point p, point q) {
  return p.first < q.first && p.second < q.second;
}
int match[N], matched[N];
bool mark[N];
vector<int> g[N];

// The code below finds a augmenting path:
bool dfs(int v){// v is in X, it reaturns true if and only if there is an augmenting path starting from v
  if(mark[v])
    return false;
  mark[v] = true;
  for(auto &u : g[v])
    if(match[u] == -1 or dfs(match[u])) // match[i] = the vertex i is matched with in the current matching, initially -1
      return matched[v] = u, match[u] = v, true;
  return false;
}

int main() {
  int n;
  scanf("%d", &n);
  for (int i = 0; i < n; ++i) {
    int x, y;
    scanf("%d %d", &x, &y);
    a[i] = {x, y};
  }
  for (int i = 0; i < n; ++i) {
    int x, y;
    scanf("%d %d", &x, &y);
    b[i] = {x, y};
  }
  for (int i = 0; i < n; ++i)
    for (int j = 0; j < n; ++j)
      if (cek(a[i], b[j]))
        g[i].push_back(j);
  int ans = 0;
  memset(matched, -1, sizeof matched);
  memset(match, -1, sizeof match);
  while(true){
    memset(mark, false, sizeof mark);
    bool fnd = false;
    for(int i = 0; i < n; ++i) if(matched[i] == -1 && !mark[i])
      fnd |= dfs(i);
    if(!fnd)
      break;
  }
  for (int i = 0; i < n; ++i)
    ans += match[i] != -1;
  printf("%d\n", ans);
  return 0;
}