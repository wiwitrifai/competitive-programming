#include <bits/stdc++.h>

using namespace std;

long long n, m;
int a[100];
vector< int > adj[100];
int sz[100], to[100];
bool die[100];
void getsz(int v, int p = -1) {
  sz[v] = 1;
  to[v] = -1;
  for (int u : adj[v]) if (u != p && !die[u]) {
    getsz(u, v);
    sz[v] += sz[u];
    if (to[v] == -1 || sz[to[v]] < sz[u])
      to[v] = u;
  }
}

bool cek(int v) {
  getsz(v);
  int s = sz[v];
  int batas = sz[v]/2;
  while (to[v] != -1 && sz[to[v]] > batas) v = to[v];
  if (to[v] != -1 && sz[to[v]] == s - sz[to[v]])
    return false;
  die[v] = 1;
  for (int u : adj[v]) if (!die[u])
    if (!cek(u))
      return false;
  return true;
}

long long solve(int d) {
  if (d == n) {
    for (int i = 0; i < n; i++) {
      adj[i].clear();
      die[i] = 0;
    }
    for (int i = 1; i < n; i++) {
      adj[i].push_back(a[i]);
      adj[a[i]].push_back(i);
    }
    getsz(0);
    if (sz[0] < n)
      return 0;
    bool ret = cek(0);
    return ret;
  }
  long long ret = 0;
  for (int i = 0; i < n; i++) {
    if (i == d)
      continue;
    a[d] = i;
    ret += solve(d+1);
  }
  return ret;
}

int main() {
  cin >> n;
  a[0] = -1;
  printf("%lld\n", solve(1));
  return 0;
}