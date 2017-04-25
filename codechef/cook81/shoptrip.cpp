#include <bits/stdc++.h>

using namespace std;

const int N = 40;
double d[N][1 << 12];
bool vis[N][1 << 12];
double to[N][N];
int x[N], y[N];
int mask[N];
char s[N];

int main() {
  int t;
  scanf("%d", &t);
  while (t--) {
    int n, k;
    scanf("%d %d", &n, &k);
    x[0] = y[0] = 0;
    for (int i = 1; i <= n; i++) {
      scanf("%d %d", x+i, y+i);
    }
    int all = 0;
    mask[0] = 0;
    for (int i = 1; i <= n; i++) {
      scanf("%s", s);
      mask[i] = 0;
      for (int j = 0; j < k; j++)
        if (s[j] == '1')
          mask[i] |= 1<<j;
      all |= mask[i];
    }
    if (all != (1<<k)-1) {
      puts("-1");
      continue;
    }
    for (int i = 0; i <= n; i++) {
      for (int j = 0; j <= n; j++) {
        int dx = x[i] - x[j], dy = y[i] - y[j];
        to[i][j] = hypot(dx, dy);
      }
    }
    memset(vis, 0, sizeof vis);
    vis[0][0] = 1;
    d[0][0] = 0;
    set< pair< double, pair< int, int > > > st;
    st.insert(make_pair(0, make_pair(0, 0)));
    while (!st.empty()) {
      auto it = st.begin();
      double val = it->first;
      int v = it->second.first, m = it->second.second;
      st.erase(it);
      for (int i = 0; i <= n; i++) {
        int new_m = m | mask[i];
        if (!vis[i][new_m] || d[i][new_m] > val + to[v][i]) {
          vis[i][new_m] = 1;
          st.erase(make_pair(d[i][new_m], make_pair(i, new_m)));
          d[i][new_m] = val + to[v][i];
          st.insert(make_pair(d[i][new_m], make_pair(i, new_m)));
        }
      }
    }
    printf("%.15lf\n", d[0][(1<<k)-1]);
  }
  return 0;
}