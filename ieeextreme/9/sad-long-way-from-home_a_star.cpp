/**
 *  Accepted
 */
#include <bits/stdc++.h>
using namespace std;

const int N = 21;
const int inf = 1e7;
int d[N][N];
vector< int > adj[N];

int n, a[N], b[N];

struct state {
  int pos[15];
  int hh;
  state() {
  }
  int& operator[] (int id) {
      return pos[id];
  }
  const int operator[] (int id) const {
      return pos[id];
  }
  int h() {
      int ret = 0;
      for (int i = 0; i < n; i++)
          ret += d[a[i]][pos[i]];
      return ret;
  }
  bool operator<(const state st) const {
      for (int i = 0; i < n; i++)
          if (st[i] != pos[i])
            return pos[i] < st[i];
      return false;
  }
  bool operator<( state st) {
      for (int i = 0; i < n; i++)
          if (st[i] != pos[i])
            return pos[i] < st[i];
      return false;
  }
  void print() {
      for (int i = 0; i < n; i++) 
        cerr << pos[i];
      cerr << endl;
  }
};
bool used[N];

int main() {
    int t;
    scanf("%d", &t);
    while (t--)  {
        scanf("%d", &n);
        state noww;
        for (int i = 0; i < n; i++) {
            scanf("%d %d", a+i, b+i);
            noww[i] = b[i];
        }
        int m;
        scanf("%d", &m);
        for (int i = 0; i < N; i++)
            for (int j = 0; j < N; j++)
                d[i][j] = (i == j) ? 0 : inf;
        for (int i = 0; i < N; i++)
            adj[i].clear();
        for (int i = 0; i < m; i++) {
            int u, v;
            scanf("%d %d", &u, &v);
            d[u][v] = 1;
            d[v][u] = 1;
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < N; j++) {
                for (int k = 0; k < N; k++) {
                    d[j][k] = min(d[j][k], d[j][i] + d[i][k]);
                }
            }
        }
        set < pair<int, state > > st;
        noww.hh = noww.h();
        st.insert(make_pair(noww.hh, noww));
        int ans = -1;
        while (!st.empty()) {
            auto it = st.begin();
            state now = it->second;
            int hh = now.hh;
            int g = it->first - hh;
            if (hh == 0) {
                ans = g;
                break;
            }
            st.erase(it);
            memset(used, 0, sizeof used);
            for (int i = 0; i < n; i++) if (now[i])
                used[now[i]] = true;
            for (int i = 0; i < n; i++) {
                int cur = now[i];
                for (int j : adj[cur]) if (!used[j]) {
                    now[i] = j;
                    now.hh = hh - d[a[i]][cur] + d[a[i]][j];
                    st.insert(make_pair(g + 1 + now.hh, now));
                    now[i] = cur;
                }
            }
        }
        printf("%d\n", ans);
    }
    return 0;
}