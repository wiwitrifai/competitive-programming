#include <bits/stdc++.h>

using namespace std;

const int N = 1e6 + 6, mod = 1e9 + 7;

vector<int> g[N];
vector<long long> * one[N];
vector<long long> * zero[N];
int off[N];
int cnt[N];

int sz[N], n, lv[N];

long long powmod(long long b, long long p) {
  long long r = 1;
  for (; p; p >>= 1, b = b * b % mod)
    if (p & 1) r = r * b % mod;
  return r;
}

inline void getSize(int v) {
  sz[v] = 1;
  cnt[lv[v]]++;
  for (int u : g[v])
    lv[u] = lv[v] + 1, getSize(u), sz[v] += sz[u];
}

long long dua[N];

void dfs(int v) {
  int bg = -1;
  for (int u : g[v]) {
    if (bg == -1 || sz[bg] < sz[u])
      bg = u;
  }
  if (bg == -1) {
    (*one[v])[off[v]]++;
    (*one[v])[off[v]] %= mod;
    return;
  }
  for (int u : g[v]) if (u != bg) {
    off[u] = 0;
    one[u] = new vector<long long>(sz[u], 0LL);
    zero[u] = new vector<long long>(sz[u], 1LL);
    dfs(u);
  }
  one[bg] = one[v];
  zero[bg] = zero[v];
  off[bg] = off[v] + 1;
  dfs(bg);
  vector<long long> & curo = *one[v];
  vector<long long> & curz = *zero[v];
  curo[off[v]]++;
  curo[off[v]] %= mod;
  int til = 0;
  for (int u : g[v]) if (u != bg) {
    til = max(til, sz[u]);
    for (int i = 0, j = off[v] + 1; i < sz[u]; ++i, ++j) {
      long long vo = (1LL * curz[j] * (*one[u])[i] + 1LL * curo[j] * (*zero[u])[i]) % mod;
      long long vz = (1LL * (*zero[u])[i] * curz[j]) % mod;
      dua[i] = (dua[i] * ((*one[u])[i] + (*zero[u])[i]) + (*one[u])[i] * 1LL * (*one[v])[j]) % mod;
      curo[j] = vo;
      curz[j] = vz;
    }
  }
  for (int i = 0, j = off[v]+1; i < til; ++i, ++j) {
    curz[j] += dua[i];
    curz[j] %= mod;
    dua[i] = 0;
  }
}

int main() {
  scanf("%d", &n);
  for (int i = 1; i <= n; ++i) {
    int p;
    scanf("%d", &p);
    g[p].push_back(i);
  }
  n++;
  lv[0] = 0;
  getSize(0);
  int u = 0;
  off[u] = 0;
  one[u] = new vector<long long>(sz[u], 0LL);
  zero[u] = new vector<long long>(sz[u], 1LL);
  dfs(0);
  long long ans = 0;
  for (int i = 0; i < sz[0]; ++i) {
    ans = (ans + powmod(2, n-cnt[i]) * 1LL * (*one[0])[i]) % mod;
  }
  if (ans < 0) ans += mod;
  cout << ans << endl;
  return 0;
}