#include <bits/stdc++.h>

using namespace std;

const int N = 1e6 + 6, mod = 1e9 + 7;

int p[N], a[N], id[N], lef[N], rig[N];
bool vis[N];
long long sum[N];

int find(int x) {
  return p[x] < 0 ? x : p[x] = find(p[x]);
}

void merge(int u, int v) {
  if ((u = find(u)) == (v = find(v)))
    return;
  if (-p[u] < -p[v])
    swap(u, v);
  p[u] += p[v];
  sum[u] += sum[v];
  lef[u] = min(lef[u], lef[v]);
  rig[u] = max(rig[u], rig[v]);
  p[v] = u;
}


void solve(int tc) {
  int n;
  scanf("%d", &n);
  memset(p, -1, sizeof p);
  memset(sum, 0, sizeof sum);
  memset(vis, false, sizeof vis);
  for (int i = 1; i <= n; ++i) {
    scanf("%d", a+i);
    sum[i] = a[i];
    lef[i] = rig[i] = i;
    id[i] = i;
  }
  sort(id+1, id+n+1, [](int l, int r) {
    return a[l] < a[r];
  });
  long long ans = 0;
  for (int i = 1; i <= n; ++i) {
    int v = id[i];
    int cntl = 1, cntr = 1;
    if (v > 1 && vis[v-1]) {
      int u = find(v-1);
      cntl = -p[u] + 1;
    }
    if (v < n && vis[v+1]) {
      int u = find(v+1);
      cntr = -p[u] + 1;
    }
    if (v > 1 && vis[v-1]) {
      int u = find(v-1);
      long long cur = 1LL * a[v] * (-p[u]) - sum[u];
      cur %= mod;
      cur = cur * cntr % mod;
      ans = (ans + 1LL * (lef[u]-1) * cur) % mod;
    }
    if (v < n && vis[v+1]) {
      int u = find(v+1);
      long long cur = 1LL * a[v] * (-p[u]) - sum[u];
      cur %= mod;
      cur = cur * cntl % mod;
      ans = (ans + 1LL * (n - rig[u]) * cur) % mod;
    }
    if (v > 1 && vis[v-1])
      merge(v-1, v);
    if (v < n && vis[v+1])
      merge(v+1, v);
    vis[v] = 1;
  }
  ans %= mod;
  if (ans < 0)
    ans += mod;
  printf("Case #%d: %lld\n", tc, ans);
}

int main() {
  time_t startt = clock();
  int tt;
  scanf("%d", &tt);
  for (int tc = 1; tc <= tt; tc++) {
    solve(tc);
    cerr << "~ #" << tc << " done! time : " << (double)(clock()-startt)/CLOCKS_PER_SEC << " s" << endl;
  }
  return 0;
}
