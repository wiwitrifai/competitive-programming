#include <bits/stdc++.h>

using namespace std;

const int N = 1e3 + 5;
int match[N], matched[N];
bool mark[N];
vector<int> adj[N];

// The code below finds a augmenting path:
bool dfs(int v){// v is in X, it reaturns true if and only if there is an augmenting path starting from v
  if(mark[v])
    return false;
  mark[v] = true;
  for(auto &u : adj[v])
    if(match[u] == -1 or dfs(match[u])) // match[i] = the vertex i is matched with in the current matching, initially -1
      return matched[v] = u, match[u] = v, true;
  return false;
}

int main() {
  int n;
  // An easy way to solve the problem is:
  for(int i = 0;i < n;i ++)if(matched[i] == -1){
    memset(mark, false, sizeof mark);
    dfs(i);
  }
  

  // But there is a faster way:
  while(true){
    memset(mark, false, sizeof mark);
    bool fnd = false;
    for(int i = 0;i < n;i ++) if(matched[i] == -1 && !mark[i])
      fnd |= dfs(i);
    if(!fnd)
      break;
  }
}