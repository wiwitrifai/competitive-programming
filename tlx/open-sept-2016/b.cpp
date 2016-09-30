#include <bits/stdc++.h>

using namespace std;

const int N = 5e4 + 5, B = pow(N, 2.0 / 3.0);

int n;
vector< int > adj[N];
int a[N], l[N], r[N], val[N], cnt[N], cntr, ans[N];
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
void dfs(int v) {
  a[cntr] = val[v];
  l[v] = cntr++;
  for (int u : adj[v]) {
    dfs(u);
  }
  r[v] = cntr-1;
}

int ty[N], x[N], y[N], w[N];
int le = 0, ri = -1, up = -1;
long long cur;

void add(int vv) {
  cur += 2 * cnt[vv] + 1;
  cnt[vv]++;
}
void del(int vv) {
  cnt[vv]--;
  cur -= 2 * cnt[vv] + 1;  
}
void change(int z, int vv) {
  int id = l[z];
  if (vv == a[id])
    return;
  if (le <= z && z <= ri) {
    add(vv);
    del(a[id]);
  }
  a[id] = vv;
}
int main() {
  scanf("%d", &n);
  for (int i = 1; i < n; i++) {
    int p;
    scanf("%d", &p);
    adj[p-1].push_back(i);
  }
  for (int i = 0; i < n; i++) {
    scanf("%d", val+i);
    val[i]--;
  }
  cntr = 0;
  dfs(0);
  int q;
  scanf("%d", &q);
  for (int i = 0; i < q; i++) {
    scanf("%d %d", ty+i, x+i);
    x[i]--;
    if (ty[i]) {
      scanf("%d", y+i);
      y[i]--;
      w[i] = val[x[i]];
      val[x[i]] = y[i];
    }
    else
      query.push_back({i, {l[x[i]], r[x[i]]}});
  }
  sort(query.begin(), query.end(), cek);
  le = 0; ri = -1, up = -1;
  cur = 0;
  memset(cnt, 0, sizeof cnt);
  for (int i = 0; i < query.size(); i++) {
    int uu = query[i].first, ll = query[i].second.first, rr = query[i].second.second;
    while (up < uu) {
      up++;
      if (ty[up]) {
        change(x[up], y[up]);
      }
    }
    while (up > uu) {
      if (ty[up]) {
        change(x[up], w[up]);
      }
      up--;
    }
    while (ri < rr) {
      ri++;
      add(a[ri]);
    }
    while (ri > rr) {
      del(a[ri]);
      ri--;
    }
    while (le > ll) {
      le--;
      add(a[le]);
    }
    while (le < ll) {
      del(a[le]);
      le++;
    }
    ans[uu] = cur;
  }
  for (int i = 0; i < q; i++) if (ty[i] == 0)
    printf("%lld\n", ans[i]);
  return 0;
}