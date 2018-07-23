#include <bits/stdc++.h>

using namespace std;

const int N = 2e5 + 5;

int p[N], w[N], n, maks[N], vis[N], cyc[N];

int main() {
  scanf("%d", &n);
  for (int i = 0; i < n; ++i)
    scanf("%d", p+i), --p[i];
  long long sum = 0, all = 0;
  for (int i = 0; i < n; ++i)
    scanf("%d", w+i), all += w[i];
  int last = 1;
  int cnt = 0;
  for (int i = 0; i < n; ++i) {
    if (vis[i]) continue;
    ++cnt;
    int v = i;
    int start = last;
    while (!vis[v]) {
      vis[v] = last++;
      v = p[v];
    }
    if (vis[v] < start) continue;
    int u = v;
    while (!cyc[u]) {
      cyc[u] = 1;
      u = p[u];
    }
  }
  if (cnt == 1) {
    bool cek = 1;
    for (int i = 0; i < n; ++i)
      cek &= cyc[i];
    if (cek) {
      puts("0");
      return 0;
    }
  }
  for (int i = 0; i < n; ++i) {
    if (cyc[i]) continue;
    maks[p[i]] = max(maks[p[i]], w[i]);
  }
  for (int i = 0; i < n; ++i) {
    if (cyc[i]) {
      if (vis[i] == -1) continue;
      int kurang = w[i] - maks[p[i]];
      sum += max(w[i], maks[p[i]]);
      vis[i] = -1;
      int v = p[i];
      while (vis[v] != -1) {
        vis[v] = -1;
        kurang = min(kurang, w[v] - maks[p[v]]);
        sum += max(w[v], maks[p[v]]);
        v = p[v];
      }
      if (kurang > 0)
        sum -= kurang;
    }
    else
      sum += maks[i];
  }
  printf("%lld\n", all - sum);
  return 0;
}