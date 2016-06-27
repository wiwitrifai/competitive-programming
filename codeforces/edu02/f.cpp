#include <bits/stdc++.h>

using namespace std;

const int N = 1e5 + 5, M = 1e3 + 3;

pair<int, int> ed[N];
vector< int > to[M<<1];
int col[M<<1][M], ans[N];
int a, b, m;
int main() {
  scanf("%d%d%d", &a, &b, &m);
  for(int i = 0; i<m; i++) {
    int u, v;
    scanf("%d%d", &u, &v);
    --u;
    v = a+v-1;
    ed[i] = make_pair(u, v);
    to[u].push_back(i);
    to[v].push_back(i);
  }
  for(int i = 0; i<m; i++) if(ans[i] == 0) {
    ans[i] = 
  }

  

  return 0;
}