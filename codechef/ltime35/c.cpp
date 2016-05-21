#include <bits/stdc++.h>

using namespace std;

const int N = 1e5 + 5;
int n, q;

int col[N];

int dfs(int v, int c, int mc, int bef = -1) {
  col[v] = c;
  c++;
  if(c <= mc) {
    if(v/2 > 0 && v/2 != bef)
      dfs(v/2, c, mc, v);
    if(v*2 <= n && v*2 != bef)
      dfs(v*2, c, mc, v);
    if(v*2+1 <= n && v*2+1 != bef)
      dfs(v*2+1, c, mc, v);
  }
}

set< int > ss;
void dfss(int v) {
  if(v > n)
    return;
  ss.insert(col[v]);
  dfss(v*2);
  dfss(v*2 + 1);
}

int main() {
  scanf("%d%d", &n, &q);
  while(q--) {
    int cmd, x, y;
    scanf("%d%d", &cmd, &x);
    if(cmd == 1) {
      scanf("%d", &y);
      dfs(x, 0, y);
    }
    else if(cmd == 2) {
      scanf("%d", &y);
      set< int > st;
      while(x != y) {
        if(x > y) {
          st.insert(col[x]);
          x >>= 1;
        }
        else {
          st.insert(col[y]);
          y >>= 1;
        }
      }
      st.insert(col[x]);
      st.erase(0);
      printf("%d\n", st.size());
    }
    else {
      ss.clear();
      dfss(x);
      ss.erase(0);
      printf("%d\n", ss.size());
    }
  }
  return 0;
}