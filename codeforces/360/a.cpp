#include <bits/stdc++.h>

using namespace std;

const int N = 1e5 + 5;

int n, m, color[N];
vector< int > adj[N];

int main() {
  scanf("%d%d", &n, &m);
  for(int i = 0; i<m; i++) {
    int u, v;
    scanf("%d%d", &u, &v);
    adj[--u].push_back(--v);
    adj[v].push_back(u);
  }
  memset(color, -1, sizeof color);
  bool isbi = true;
  for(int i = 0; i<n; i++) if(color[i] == -1 && isbi) {
    queue<int > q;
    q.push(i);
    color[i] = 0;
    while(!q.empty() && isbi) {
      int u = q.front();
      q.pop();
      for(int v : adj[u]) {
        if(color[v] == -1) {
          color[v] = 1 - color[u];
          q.push(v);
        }
        else if(color[v] == color[u]) {
          isbi = false;
          break;
        }
      }
    }
  }
  if(isbi) {
    int cnt = 0;
    for(int i = 0; i<n; i++)
      if(color[i] == 0)
        cnt++;
    printf("%d\n", cnt);
    for(int i = 0; i<n; i++)
      if(color[i] == 0)
        printf("%d ", i+1);
    printf("\n%d\n", n-cnt);
    for(int i = 0; i<n; i++)
      if(color[i] == 1)
        printf("%d ", i+1);
    printf("\n");
  } 
  else {
    puts("-1");
  }

  return 0;
}