#include <bits/stdc++.h>

using namespace std;

const int N = 2e5 + 5, S = N * 55, mod = 1e9 + 7, inf = mod;

#define MM 2305842993ll // MM = 2^61/mod
inline int rem(long long a){return a-mod*((a>>29)*MM>>32);}

long long powmod(long long b, long long p) {
  long long r = 1;
  for (; p; p >>= 1, b = rem(b * b))
    if (p & 1)
      r = rem(r * b);
  return r;
}

long long geo(long long a, long long r, int n) {
  if (r == 1)
    return rem(1LL * a * n);
  long long ret = rem(a * (powmod(r, n) - 1));
  ret = rem((ret * powmod(r - 1, mod-2)));
  if (ret < 0) ret += mod;
  return ret;
}

long long geo_art(long long x, int n) {
  if (x == 1) {
    return rem((1LL * (n + 1) * n / 2));
  }
  long long xn = powmod(x, n);
  long long atas = rem((rem(rem(n * xn) * x) - (n+1) * xn + 1));
  long long bawah = rem((x - 1) * (x - 1));
  atas = rem(atas * powmod(bawah, mod-2));
  if (atas < 0) atas += mod;
  return atas;
}

long long calc(int x, int k, int d, int p, int n) {
  long long rol = geo(powmod(x, k), x, p);
  long long xp = powmod(x, p);
  long long wkx = rem(1LL * (d-1) * geo(1, xp, n));
  long long asd = geo_art(xp, n);
  long long ret = (rol * (wkx + asd)) % mod;
  if (ret < 0) ret += mod;
  return ret;
}

vector<int> g[N];
int lv[N], st[N], en[N], cntr = 0, euler[N];

struct Entry {
  int mins, add;
  Entry(int mins = inf, int add = 0) : mins(mins), add(add) {}
  Entry operator+(Entry x) {
    if (mins == x.mins)
      return Entry(mins, add + x.add);
    else if (mins < x.mins)
      return *this;
    return x;
  }
  void update(int m, int a) {
    mins = m;
    add = a;
  }
} entry[S];

int L[S], R[S], nodes;
int n, root[N];

int build(int v, int l = 0, int r = n) {
  int id = nodes++;
  entry[id].update(v, 0);
  if (r-l < 2) {
    return id;
  }
  int mid = (l + r) >> 1;
  L[id] = build(v, l, mid);
  R[id] = build(v, mid, r);
  entry[id] = entry[L[id]] + entry[R[id]];
  return id;
}

int update(int ID, int x, int v, int l = 0, int r = n) {
  int id = nodes++;
  if (r-l < 2) {
    int child = g[euler[x]].size();
    if (euler[x]) --child;
    --child;
    entry[id].update(v, child);
    return id;
  }
  int mid = (l + r) >> 1;
  L[id] = L[ID];
  R[id] = R[ID];
  if (x < mid)
    L[id] = update(L[ID], x, v, l, mid);
  else
    R[id] = update(R[ID], x, v, mid, r);
  entry[id] = entry[L[id]] + entry[R[id]];
  return id;
}

Entry get(int id, int x, int y, int l = 0, int r = n) {
  if (x >= r || l >= y) return Entry();
  if (x <= l && r <= y) {
    return entry[id];
  }
  int mid = (l + r) >> 1;
  return get(L[id], x, y, l, mid) + get(R[id], x, y, mid, r);
}

void dfs(int v, int par = -1) {
  lv[v] = par == -1 ? 0 : lv[par] + 1;
  euler[cntr] = v;
  st[v] = cntr++;
  for (int u : g[v]) {
    if (u == par) continue;
    dfs(u, v);
  }
  en[v] = cntr;
}

int main() {
  int t;
  scanf("%d", &t);
  while (t--) {
    int q;
    scanf("%d %d", &n, &q);
    for (int i = 0; i < n; ++i) {
      g[i].clear();
    }
    for (int i = 1; i < n; ++i) {
      int u, v;
      scanf("%d %d", &u, &v);
      --u, --v;
      g[u].push_back(v);
      g[v].push_back(u);
    }
    cntr = 0;
    dfs(0);
    int diameter = 0;
    for (int i = 0; i < n; ++i)
      diameter = max(diameter, lv[i]);
    nodes = 0;
    int last_root = build(diameter);
    fill(root, root+n+1, last_root);
    vector<int> id;
    for (int i = 0; i < n; ++i) {
      int child = g[i].size();
      if (i) --child;
      if (child > 1)
        id.push_back(i);
    }
    sort(id.begin(), id.end(), [](int x, int y) {
      return lv[x] > lv[y];
    });
    for (int d = diameter, i = 0; d >= 0; --d) {
      root[d] = last_root;
      while (i < id.size() && lv[id[i]] == d) {
        int v = id[i];
        assert(lv[v] == d);
        root[d] = update(root[d], st[v], lv[v]);
        ++i;
      }
      last_root = root[d];
    }
    int ans = 0;
    while (q--) {
      int v, y;
      scanf("%d %d", &v, &y);
#ifndef LOCAL
      v ^= ans;
      y ^= ans;
#endif
      --v;
      int l = st[v], r = en[v];
      ans = 0;
      int offset = lv[v], cur = lv[v], cnt = 1, pos = 0;
      while (cur <= diameter) {
        Entry res = get(root[cur], l, r);
        
        ans += calc(y, pos, cur - offset, cnt, res.mins - cur + 1);
        if (ans >= mod) ans -= mod;

        pos += cnt * (res.mins - cur + 1);
        cur = res.mins + 1;
        cnt += res.add;
      }
      ans %= mod;
      if (ans < 0) ans += mod;
      printf("%d\n", ans);
    }
  }
  return 0;
}