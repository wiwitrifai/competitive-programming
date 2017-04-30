#include <bits/stdc++.h>

using namespace std;

/***************** FFT dengan complex ******************/
typedef complex<double> cd;
typedef vector< cd > vcd;

// asumsi ukuran as = 2^k, dengan k bilangan bulat positif
vcd root[20];
vcd fft(const vcd &as) {
  int n = (int)as.size();
  int k = 0;
  while((1<<k) < n) k++;
  vector< int > r(n);
  r[0] = 0;
  int h = -1;
  for(int i = 1; i<n; i++) {
    if((i & (i-1)) == 0)
      h++;
    r[i] = r[i ^ (1 << h)];
    r[i] |= (1<<(k-h-1));
  }

  vcd cur(n);
  for(int i = 0; i<n; i++)
    cur[i] = as[r[i]];

  for(int len = 1; len < n; len <<= 1 ) {
    vcd ncur(n);
    int step = n/(len << 1);
    for(int pdest = 0; pdest <n;) {
      for(int i = 0; i<len; i++) {
        cd val = root[k][i*step]*cur[pdest + len];
        ncur[pdest] = cur[pdest] + val;
        ncur[pdest + len] = cur[pdest] - val;
        pdest++;
      }
      pdest += len;
    }
    cur.swap(ncur);
  }
  return cur;
}

vcd inv_fft(const vcd& fa) {
  vcd res = fft(fa);
  for(int i = 0; i<res.size(); i++) {
    res[i] /= res.size();
  }
  reverse(res.begin() + 1, res.end());
  return res;
}

const int N = 1e5 + 5, M = 1e4 + 4;
vector < int > g[N];
int cnt[N], ans[N], w[N], sz[N], to[N], val[N], lv[N], n;
bool live[N];
void gs(int v, int par = -1) {
  sz[v] = 1;
  to[v] = -1;
  for (int u : g[v]) if (u != par && live[u]) {
    gs(u, v), sz[v] += sz[u];
    if (to[v] == -1 || sz[u] > sz[to[v]])
      to[v] = u;
  }
}
int gc(int v, int par = -1, int depth = 0) {
  if (!live[v]) return 0;
  int ret = depth+1;
  cnt[depth]++;
  for (int u : g[v]) if (u != par && live[u])
    ret = max(ret, gc(u, v, depth+1));
  return ret;
}
void add(int v, int par = -1, int depth = 0) {
  if (!live[v]) return;
  ans[v] += val[depth];
  for (int u : g[v]) if (u != par && live[u])
    add(u, v, depth+1);
}
vcd pc;
vcd pw[20];
int getval(int v, int off = 0) {
  int d = gc(v, -1, off);
  int szp = 1, ver = 0;
  int nw = min(n, 2 * d);
  while (szp < d + nw) szp <<= 1, ver++;
  pc.resize(szp);
  for (int i = 0; i < d; i++) pc[i] = cnt[d-1-i];
  for (int i = d; i < szp; i++) pc[i] = 0;
  pc = fft(pc);
  for (int i = 0; i < szp; i++)
    pc[i] *= pw[ver][i];
  pc = inv_fft(pc);
  for (int i = 0; i < d; i++) val[i] = (int)(pc[i+d-1].real() + 0.5);
  return d;
}
void solve(int v) {
  gs(v);
  int tot = sz[v];
  while (to[v] != -1 && 2 * sz[to[v]] > tot) v = to[v];
  int d = getval(v);
  add(v);
  for (int i = 0; i < d; i++) cnt[i] = val[i] = 0;
  live[v] = 0;
  for (int u : g[v]) if (live[u]) {
    d = getval(u, 1);
    for (int i = 0; i < d; i++) {
      val[i] = -val[i];
    }
    add(u, v, 1);
    for (int i = 0; i < d; i++) cnt[i] = val[i] = 0;
  }
  for (int u : g[v]) if (live[u])
    solve(u);
}

int main() {
  for (int j = 0; j < 20; j++) {
    n = 1<<j;
    root[j].resize(1<<j);
    for(int i = 0; i<n; i++) {
      double ang = 2.0*M_PI*i/n;
      root[j][i] = cd(cos(ang), sin(ang));
    }
  }
  scanf("%d", &n);
  for (int i = 0; i < n; i++)
    scanf("%d", w+i);
  for (int i = 0; i < 20; i++) {
    pw[i].resize(1 << i);
    int nw = min(1<<i, n);
    for (int j = 0; j < nw; j++)
      pw[i][j] = w[j]; 
    for (int j = nw; j < (1<<i); j++)
      pw[i][j] = 0;
    pw[i] = fft(pw[i]);
  }
  for (int i = 1; i < n; i++) {
    int u, v;
    scanf("%d %d", &u, &v);
    u--; v--;
    g[u].push_back(v);
    g[v].push_back(u);
  }
  fill(live, live+n, true);
  fill(ans, ans+n, 0);
  solve(0);
  for (int i = 0; i < n; i++)
    printf("%d ", ans[i]);
  printf("\n");
  return 0;
}