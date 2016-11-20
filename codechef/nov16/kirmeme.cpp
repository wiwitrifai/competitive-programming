#include <bits/stdc++.h>

using namespace std;

const int N = 5e4 + 5;

vector< int > adj[N];
int a[N], n, l, r;
bool die[N];

struct fen {
  long long bit[N];
  int add[N], bg;
  void upd(int x, long long v) {
    add[x] += v;
    if (x > bg)
      bg = x;
  }
  void process() {
    long long now = 0;
    for (int i = bg+1; i >= 0; i--) {
      now += add[i];
      add[i] = 0;
      bit[i] += now;
    }
    bg = 0;
  }
  long long get(int x) {
    if (x < 0)
      x = 0;
    if (x >= N)
      x = N-1;
    return bit[x];
  }
};
fen ft[2];

int sz[N], to[N];
void getsz(int v, int p = -1) {
  sz[v] = 1;
  to[v] = -1;
  for (int u : adj[v]) if (!die[u] && u != p) {
    getsz(u, v);
    sz[v] += sz[u];
    if (to[v] == -1 || sz[to[v]] < sz[u])
      to[v] = u;
  }
}

void add(int v, int t, int val, int cur = 0, int p = -1) {
  ft[t].upd(cur, val);
  for (int u : adj[v]) if (u != p && !die[u]) {
    add(u, t, val, cur + (p != -1 && a[p] < a[v] && a[u] < a[v]), v);
  }
}
long long get(int v, int t, int cur, int p = -1) {
  long long ret = ft[0].get(l-cur) - ft[0].get(r-cur);
  if (t)
    ret += ft[1].get(l-cur-1) - ft[1].get(r-cur-1);
  else
    ret += ft[1].get(l-cur) - ft[1].get(r-cur);
  for (int u : adj[v]) if (u != p && !die[u]) {
    ret += get(u, t, cur + (p != -1 && a[p] < a[v] && a[u] < a[v]), v);
  }
  return ret;
}

long long solve(int v) {
  long long ret = 0;
  getsz(v);
  int mid = sz[v]/2;
  while (to[v] != -1 && sz[to[v]] > mid) v = to[v];

  for (int u : adj[v]) if (!die[u]) {
    ret += get(u, a[u] < a[v], 0, v);
    add(u, a[u] < a[v], 1, 0, v);
    ft[a[u] < a[v]].process();
  }
  ret += ft[0].get(l) - ft[0].get(r) + ft[1].get(l) - ft[1].get(r);

  for (int u : adj[v]) if (!die[u]) {
    add(u, a[u] < a[v], -1, 0, v);
    ft[a[u] < a[v]].process();
  }
  die[v] = 1;
  for (int u : adj[v]) if (!die[u]) {
    ret += solve(u);
  }
  return ret;
}


int main() {
  int t;
  scanf("%d", &t);
  while (t--) {
    scanf("%d %d %d", &n, &l, &r);
    r++;
    for (int i = 0; i < n; i++) {
      scanf("%d", a+i);
      adj[i].clear();
      die[i] = false;
    }
    for (int i = 1; i < n; i++) {
      int u, v;
      scanf("%d %d", &u, &v);
      u--; v--;
      adj[u].push_back(v);
      adj[v].push_back(u); 
    }
    memset(ft[0].bit, 0, sizeof ft[0].bit);
    memset(ft[1].bit, 0, sizeof ft[1].bit);
    ft[0].bg = ft[1].bg = 0;
    printf("%lld\n", solve(0));
  }

  return 0;
}