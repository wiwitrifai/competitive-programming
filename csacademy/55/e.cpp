#include <bits/stdc++.h>

using namespace std;

const int N = 1e5 + 5, MAGIC = 450, LG = 18;

int lv[N], col[N];
vector<int> g[N];
int n, m;
int euler[N << 1], sp[LG][N << 1], cntr, pos[N];
void pre(int v, int par = -1) {
  pos[v] = cntr;
  euler[cntr++] = v;
  for (int u : g[v]) {
    if (u == par) continue;
    lv[u] = lv[v] + 1;
    pre(u, v);
    euler[cntr++] = v;
  }
}
int get(int l, int r) {
  int len = r-l+1;
  int lg = 31-__builtin_clz(len);
  int le = sp[lg][l], ri = sp[lg][r-(1<<lg)+1];
  return lv[le] < lv[ri] ? le : ri;
}

int dist(int u, int v) {
  if (pos[u] > pos[v]) swap(u, v);
  int lca = get(pos[u], pos[v]);
  return lv[u] + lv[v] - 2 * lv[lca];
}
int x[N], t[N], sz[N][2];
long long val[N][2];
void dfs(int v, int par = -1) {
  sz[v][0] = sz[v][1] = 0;
  sz[v][col[v]]++;
  val[v][0] = val[v][1] = 0;
  for (int u : g[v]) {
    if (u == par) continue;
    dfs(u, v);
    sz[v][0] += sz[u][0];
    sz[v][1] += sz[u][1];
    val[v][0] += val[u][0] + sz[u][0];
    val[v][1] += val[u][1] + sz[u][1];
  }
}

void dfs2(int v, int par = -1) {
  for (int u : g[v]) {
    if (u == par) continue;
    val[u][0] = val[v][0] + sz[0][0] - 2 * sz[u][0];
    val[u][1] = val[v][1] + sz[0][1] - 2 * sz[u][1];
    dfs2(u, v);
  }
}


int main() {
  scanf("%d %d", &n, &m);
  for (int i = 0; i < n; i++) {
    scanf("%d", col+i);
  }
  for (int i = 1; i < n; i++) {
    int u, v;
    scanf("%d %d", &u, &v);
    u--; v--;
    g[u].push_back(v);
    g[v].push_back(u);
  }
  lv[0] = 0;
  pre(0);
  for (int i = 0; i < cntr; i++) {
    sp[0][i] = euler[i];
  }
  for (int i = 0; i + 1 < LG; i++) {
    for (int j = 0; j + (1 << (i+1)) <= cntr; j++) {
      int le = sp[i][j], ri = sp[i][j+(1<<i)];
      sp[i+1][j] = lv[le] < lv[ri] ? le : ri;
    }
  }
  for (int i = 0; i < m; i++) {
    scanf("%d %d", t+i, x+i);
    x[i]--;
  }
  for (int i = 0; i < m; i += MAGIC) {
    dfs(0);
    dfs2(0);
    int up = min(m, i+MAGIC);
    set<int> st;
    for (int j = i; j < up; j++) {
      if (t[j] == 1) {
        if (st.count(x[j]))
          st.erase(x[j]);
        else
          st.insert(x[j]);
      }
      else {
        int cnow = col[x[j]];
        if (st.count(x[j]))
          cnow ^= 1;
        long long ans = val[x[j]][cnow];
        for (int u : st) {
          if (u == x[j]) continue;
          if (col[u] == cnow)
            ans -= dist(x[j], u);
          else
            ans += dist(x[j], u);
        }
        printf("%lld\n", ans);
      }
    }
    for (int u : st)
      col[u] ^= 1;
  }
  return 0;
}