#include <bits/stdc++.h>

using namespace std;

const int N = 2e5 + 5;
int p[N];

int find(int x) {
  return p[x] < 0 ? x : p[x] = find(p[x]);
}

long long sum[N], last[N];
bool merge(int u, int v, int w) {
  if ((u = find(u)) == (v = find(v))) {
    last[u] = max(last[u], (long long)w);
    return false;
  }
  if (last[u] > 0 && last[v] > 0) return false;
  p[u] = v;
  last[v] = max(last[v], last[u]);
  sum[v] += sum[u] + w;
  return true;
}

pair<int, pair<int, int> > vp[N];
int n, m;

int main() {
  memset(p, -1, sizeof p);
  scanf("%d %d", &n, &m);
  for (int i = 0; i < m; i++) {
    int a, b, w;
    scanf("%d %d %d", &a, &b, &w);
    vp[i] = {w, {a, b}};
  }
  sort(vp, vp+m);
  bool ok = 1;
  for (int i = m-1; i >= 0; i--) {
    int u = vp[i].second.first, v = vp[i].second.second;
    int w = vp[i].first;
    merge(u, v, w);
  }
  long long ans = 0;
  for (int i = 0; i <= n; i++) if (p[i] == -1)
    ans += sum[i] + last[i];
  cout << ans << endl;
  return 0;
}