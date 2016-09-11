#include <bits/stdc++.h>

using namespace std;

const int N = 1024;

char s[N<<1][N<<1];
char ss[N];
int no[N<<1][N<<1];
int match[N], match2[N];
bool mark[N];

vector< int > adj[N];

bool dfs(int v) {
  if (mark[v])
    return false;
  mark[v] = true;
  for (int u : adj[v]) {
    if (match[u] == -1 || dfs(match[u]))
      return match[u] = v, match2[v] = u, true;
  }
  return false;
}

int main() {
  int t;
  scanf("%d", &t);
  while (t--) {
    int h, v;
    scanf("%d %d", &h, &v);
    memset(no, 0, sizeof no);
    for (int i = 0; i < h; i++) {
      int x, y;
      scanf("%d %d %s", &x, &y, ss);
      int n = strlen(ss);
      for (int j = 0; j < n; j++) {
        no[y][x+j] = i + 1;
        s[y][x+j] = ss[j];
      }
    }
    for (int i = 0; i < v; i++) {
      int x, y;
      scanf("%d %d %s", &x, &y, ss);
      int n = strlen(ss);
      adj[i+1].clear();
      for (int j = 0; j < n; j++) {
        if (ss[j] != s[y+j][x] && no[y+j][x]) {
          adj[i+1].push_back(no[y+j][x]);
        }
      }
    }
    memset(match, -1, sizeof match);
    memset(match2, -1, sizeof match2);
    for (int i = 1; i <= v; i++) if (match2[i] == -1) {
      memset(mark, false, sizeof mark);
      dfs(i);
    }
    int ans = h + v;
    for (int i = 1; i <= h; i++)
      ans -= match[i] > -1;
    printf("%d\n", ans);
  }
  return 0;
}