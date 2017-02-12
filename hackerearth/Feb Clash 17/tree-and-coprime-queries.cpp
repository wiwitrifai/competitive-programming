#include <bits/stdc++.h>

using namespace std;

const int N = 2e5 + 5, B = pow(N, 2.0 / 3.0), LG = 18;
const int V = 5050;

int n;
vector< int > adj[N];
int a[N], l[N], r[N], sp[LG][N], val[N], tmp[N], cnt[V], cntr, lv[N], ppar[N];
long long ans[N];
bool used[N];
vector< pair<int, pair<int, int >> > query;

bool cek(pair<int, pair<int, int > > le, pair<int, pair<int,int> > ri) {
  int gl = le.first/B, gr = ri.first/B;
  if (gl == gr) {
    gl = le.second.first/B;
    gr = ri.second.first/B;
    if (gl == gr)
      return le.second.second < ri.second.second;
    else
      return gl < gr;
  }
  else 
    return gl < gr;
}
void dfs(int v, int par = 0) {
  ppar[v] = par;
  if (v == par)
    lv[v] = 0;
  else
    lv[v] = lv[par] + 1;
  a[cntr] = v;
  l[v] = cntr++;
  for (int u : adj[v]) if (u != par) {
    dfs(u, v);
  }
  r[v] = cntr;
  a[cntr++] = v;
}

int ty[N], x[N], y[N], z[N], w[N];
int le = 0, ri = -1, up = -1;

vector< int > fac[V];
int mul[V];

void add(int vv) {
  vv = val[vv];
  for (int f : fac[vv])
    cnt[f]++;
}
void del(int vv) {
  vv = val[vv];
  for (int f : fac[vv])
    cnt[f]--;  
}
void change(int z, int vv) {
  if (vv == val[z])
    return;
  if (used[z]) {
    del(z);
    val[z] = vv;
    add(z);
  }
  else
    val[z] = vv;
}
void togle(int v) {
  if (used[v])
    del(v);
  else
    add(v);
  used[v] = !used[v];
}
int lca(int u, int v) {
  int lhs = l[u], rhs = l[v];
  if (lhs > rhs)
    swap(lhs, rhs); 
  int len = rhs-lhs+1;
  int lg = 31 - __builtin_clz(len);
  lhs = sp[lg][lhs], rhs = sp[lg][rhs-(1<<lg)+1];
  if (lv[lhs] > lv[rhs])
    swap(lhs, rhs);
  return (l[lhs] > min(l[u], l[v]) || r[lhs] < max(r[u], r[v])) ? ppar[lhs] : lhs;
}

int main() {
  // Precompute
  mul[1] = 1;
  for (int i = 1; i < V; i++) {
    for (int j = i; j < V; j += i)
      fac[j].push_back(i);
    if (i == 1) continue;
    int now = i;
    now /= fac[i][1];
    if (now % fac[i][1])
      mul[i] = -mul[now];
    else
      mul[i] = 0;
  }
  mul[1] = 1;

  // Read input
  int q;
  scanf("%d", &n);
  scanf("%d", &q);
  for (int i = 0; i < n; i++) {
    scanf("%d", val+i);
    tmp[i] = val[i];
  }
  for (int i = 1; i < n; i++) {
    int u, v;
    scanf("%d %d", &u, &v);
    u--; v--;
    adj[u].push_back(v);
    adj[v].push_back(u);
  }
  for (int i = 0; i < q; i++) {
    scanf("%d %d %d", ty+i, x+i, y+i);
    x[i]--;
    if (ty[i]) {
      y[i]--;
      scanf("%d", z+i);
    }
  }

  // Flatten tree
  cntr = 0;
  dfs(0);
  assert(cntr == (n + n));

  // Build rmq for lca
  for (int i = 0; i < cntr; i++) {
    sp[0][i] = a[i];
  }
  for (int i = 0; i + 1 < LG; i++) {
    for (int j = 0; j + (1<<(i+1)) < cntr; j++) {
      int lhs = sp[i][j], rhs = sp[i][j+(1<<i)];
      sp[i+1][j] = lv[lhs] < lv[rhs] ? lhs : rhs;
    }
  }

  // Mo's Algorithm
  for (int i = 0; i < q; i++) {
    if (ty[i] == 0) {
      w[i] = tmp[x[i]];
      tmp[x[i]] = y[i];
    }
    else {
      if (l[x[i]] > l[y[i]])
        swap(x[i], y[i]);
      query.push_back({i, {l[x[i]], l[y[i]]}});
    }
  }
  sort(query.begin(), query.end(), cek);
  le = -1; ri = -1, up = -1;
  memset(cnt, 0, sizeof cnt);
  for (int i = 0; i < query.size(); i++) {
    int uu = query[i].first, ll = query[i].second.first, rr = query[i].second.second;
    while (up < uu) {
      up++;
      if (ty[up] == 0) {
        change(x[up], y[up]);
      }
    }
    while (up > uu) {
      if (ty[up] == 0) {
        change(x[up], w[up]);
      }
      up--;
    }
    while (ri < rr) {
      ri++;
      togle(a[ri]);
    }
    while (ri > rr) {
      togle(a[ri]);
      ri--;
    }
    while (le < ll) {
      le++;
      togle(a[le]);
    }
    while (le > ll) {
      togle(a[le]);
      le--;
    }
    int lc = lca(x[uu], y[uu]);
    add(lc);
    ans[uu] = 0;
    for (int f : fac[z[uu]])
      ans[uu] += mul[f] * cnt[f];
    del(lc);
  }
  for (int i = 0; i < q; i++) if (ty[i] == 1)
    printf("%lld\n", ans[i]);
  return 0;
}