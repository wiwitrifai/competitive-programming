#include <bits/stdc++.h>

using namespace std;

const int N = 202;

bool mark[N];
int match[N], matched[N];

vector<int> adj[N];

bool dfs(int v){// v is in X, it reaturns true if and only if there is an augmenting path starting from v
  if(mark[v])
    return false;
  mark[v] = true;
  for(auto &u : adj[v])
    if(match[u] == -1 or dfs(match[u])) // match[i] = the vertex i is matched with in the current matching, initially -1
      return matched[v] = u, match[u] = v, true;
  return false;
}
bool ok[N];

int main() {
  int n;
  scanf("%d%*c", &n);
  for (int i = 0; i < n; i++) {
    memset(ok, 0, sizeof ok);
    string s;
    getline(cin, s);
    stringstream ss(s);
    int x;
    ok[i] = 1;
    while (ss >> x) {
      ok[x] = 1;
    }
    for (int j = 0; j < n; j++)
      if (!ok[j])
        adj[i].push_back(j);
  }

  memset(matched, -1, sizeof matched);
  memset(match, -1, sizeof match);
  // But there is a faster way:
  while(true){
    memset(mark, false, sizeof mark);
    bool fnd = false;
    for(int i = 0;i < n;i ++) if(matched[i] == -1 && !mark[i])
      fnd |= dfs(i);
    if(!fnd)
      break;
  }
  int ans = 0;
  for (int i = 0; i < n; i++) {
    ans += matched[i] == -1;
  }
  printf("%d\n", ans);
  return 0;
}