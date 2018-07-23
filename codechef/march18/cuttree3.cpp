#include <bits/stdc++.h>

using namespace std;

const int N = 4e5 + 5, mod = 1e9 + 7, S = int(sqrt(mod) + 2);
const long double PI = acos(-1);

long long powmod(long long b, long long p) {
  long long r = 1;
  for (; p; p >>= 1, b = b * b % mod)
    if (p & 1)
      r = r * b % mod;
  return r;
}

/***************** FFT dengan complex ******************/
typedef complex<long double> cd;
typedef vector< cd > vcd;

const int LG = 20;

vcd root[N];

vcd fft(int lg, const vcd &as) {
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
        cd val = root[lg][i*step]*cur[pdest + len];
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

vcd inv_fft(int lg, vcd& res) {
  res = fft(lg, res);
  int nn = res.size();
  for(int i = 0; i<nn; i++) {
    res[i] /= nn;
  }
  reverse(res.begin() + 1, res.end());
  return res;
}

vector<int> multiply(vector<int> & a, vector<int> & b) {
  int n = (int)a.size() + (int)b.size()-1;
  int lg = 31 - __builtin_clz(n);
  if (n & (n-1)) ++lg;
  n = 1 << lg;
  vcd va(n, 0), vb(n, 0);
  for (int i = 0; i < a.size(); ++i)
    va[i] = a[i];
  for (int i = 0; i < b.size(); ++i)
    vb[i] = b[i];
  va = fft(lg, va);
  vb = fft(lg, vb);
  for (int i = 0; i < n; ++i)
    va[i] *= vb[i];
  va = inv_fft(lg, va);
  vector<int> res(a.size() + b.size() - 1);
  for (int i = 0; i < res.size(); ++i)
    res[i] = (long long)(va[i].real() + 0.5) % mod;
  return res;
}

vcd combine(int n, vcd & a, vcd & b) {
  vcd ret(n, 0);
  cd imag = cd(0, 1);
  for (int i = 0; i < a.size(); ++i)
    ret[i] += a[i];
  for (int i = 0; i < b.size(); ++i)
    ret[i] += imag * b[i];
  return ret;
}

void decompose(vcd & v, vcd & a, vcd & b) {
  int n = v.size();
  cd duai = cd(0, 2), dua = 2;
  a[0] = (v[0]+conj(v[0]))/dua;
  b[0] = (v[0]-conj(v[0]))/duai;
  for (int i = 1; i < n; ++i) {
    a[i] = (v[i] + conj(v[n-i])) / dua;
    b[i] = (v[i] - conj(v[n-i])) / duai;
  }
}

vector<int> multiplymod(vector<int> & a, vector<int> & b) {
  vcd a1(a.size()), a2(a.size()), b1(b.size()), b2(b.size());
  for (int i = 0; i < a.size(); ++i) {
    a1[i] = a[i] / S;
    a2[i] = a[i] % S;
  }
  for (int i = 0; i < b.size(); ++i) {
    b1[i] = b[i] / S;
    b2[i] = b[i] % S;
  }
  int n = a.size() + b.size() - 1;
  int lg = 31 - __builtin_clz(n);
  if (n & (n-1)) ++lg;
  n = 1 << lg;
  vcd x(n, 0), y(n, 0);
  x = combine(n, a1, a2);
  y = combine(n, b1, b2);
  x = fft(lg, x);
  y = fft(lg, y);
  a1.resize(n); a2.resize(n);
  b1.resize(n); b2.resize(n);
  decompose(x, a1, a2);
  decompose(y, b1, b2);
  vcd res11(n), res12(n), res21(n), res22(n);
  for (int i = 0; i < n; ++i) {
    res11[i] = a1[i] * b1[i];
    res12[i] = a1[i] * b2[i];
    res21[i] = a2[i] * b1[i];
    res22[i] = a2[i] * b2[i];
  }
  x = combine(n, res11, res12);
  y = combine(n, res21, res22);
  inv_fft(lg, x);
  inv_fft(lg, y);
  for (int i = 0; i < n; ++i) {
    res11[i] = x[i].real();
    res12[i] = x[i].imag();
    res21[i] = y[i].real();
    res22[i] = y[i].imag();
  }
  vector<int> ret(a.size() + b.size()-1);
  for (int i = 0; i < ret.size(); ++i) {
    int val11 = (long long)(res11[i].real()+0.5) % mod;
    int val12 = (long long)(res12[i].real()+0.5) % mod;
    int val21 = (long long)(res21[i].real()+0.5) % mod;
    int val22 = (long long)(res22[i].real()+0.5) % mod;
    long long now = (1LL * val11 * S + 1LL * (val12 + val21)) % mod;
    now = (now * S + val22) % mod;
    if (now < 0) now += mod;
    ret[i] = now;
  }
  return ret;
}

vector<int> g[N];
int live[N], sz[N], big[N], lv[N];

int getSz(int u, int par = -1) {
  sz[u] = 1;
  big[u] = -1;
  for (int v : g[u]) if (v != par && live[v]) {
    getSz(v, u);
    sz[u] += sz[v];
    if (big[u] == -1 || sz[big[u]] < sz[v])
      big[u] = v;
  }
}

long long sumAtLv[N], fac[N], inv[N];
long long ans[N];
long long productAtDistance[N], cumulative[N];

long long C(int n, int k) {
  if (k < 0 || n < k) return 0;
  return (fac[n] * inv[k] % mod) * inv[n-k] % mod;
}

int dfs(int v, int par = -1, int lv = 1) {
  int siz = 1;
  for (int u : g[v]) if (u != par && live[u])
    siz += dfs(u, v, lv+1);
  sumAtLv[lv] += siz;
  if (sumAtLv[lv] >= mod) sumAtLv[lv] -= mod;
  return siz;
}

int dfs2(int v, int val, int par = -1, int lv = 1) {
  int siz = 1;
  for (int u : g[v]) if (u != par && live[u])
    siz += dfs2(u, val, v, lv+1);
  productAtDistance[lv] = (productAtDistance[lv] + 2LL * val * siz) % mod;
  return siz;
}

void generatePlusOne(vector<int> &vs) {
  if (vs.size() <= 1) return;
  int mid = vs.size()/2;
  vector<int> a(mid), b(vs.size() - mid), c(mid+1);
  for (int i = 0; i < mid; ++i)
    a[i] = vs[i];
  for (int i = mid; i < vs.size(); ++i)
    b[i-mid] = vs[i];
  for (int i = 0; i <= mid; ++i)
    c[i] = C(mid, i);
  generatePlusOne(a);
  generatePlusOne(b);
  b = multiplymod(b, c);
  fill(vs.begin(), vs.end(), 0);
  for (int i = 0; i < a.size(); ++i) {
    vs[i] = a[i];
  }
  for (int j = 0; j < b.size(); ++j) {
    vs[j] += b[j];
    if (vs[j] >= mod) vs[j] -= mod;
  }
}

void generatePlusOne1(vector<int> & vs) {
  for (int i = 0; i < vs.size(); ++i) {
    long long now = 0;
    for (int j = i; j < vs.size(); ++j) {
      now = (now + vs[j] * C(j, i)) % mod;
    }
    vs[i] = now;
  }
}

void add(vector<int> & a, vector<int> b) {
  if (a.size() < b.size()) a.resize(b.size());
  for (int i = 0; i < b.size(); ++i) {
    a[i] += b[i];
    if (a[i] >= mod) a[i] -= mod;
  }
}

void centroid(int v) {
  getSz(v);
  int tot = sz[v];
  while (big[v] != -1 && 2 * sz[big[v]] >= tot) v = big[v];
  live[v] = 0;
  fill(cumulative, cumulative+tot+1, 0);
  for (int u : g[v]) if (live[u]) {
    int s = dfs(u, v);
    dfs2(u, tot-s, v);
    vector<int> vs(s+1);
    for (int i = 0; i <= s; ++i) {
      sumAtLv[i] %= mod;
      if (sumAtLv[i] < 0) sumAtLv[i] += mod;
      vs[i] = sumAtLv[i];
      cumulative[i] += sumAtLv[i];
      if (cumulative[i] >= mod) cumulative[i] -= mod;
      sumAtLv[i] = 0;
    }
    vector<int> res = multiplymod(vs, vs);
    for (int i = 0; i < res.size(); ++i) {
      productAtDistance[i] -= res[i];
      if (productAtDistance[i] < 0) productAtDistance[i] += mod;
    }
  }
  vector<int> vs(tot+1);
  for (int i = 0; i <= tot; ++i)
    vs[i] = cumulative[i];
  vector<int> res = multiplymod(vs, vs);
  for (int i = 0; i < res.size(); ++i) {
    productAtDistance[i] = (productAtDistance[i] + res[i]) % mod;
    if (productAtDistance[i] < 0) productAtDistance[i] += mod;
  }
  for (int u : g[v]) if (live[u])
    centroid(u);
}

int dfs3(int v, int val, int par = -1, int lv = 0) {
  int siz = 1;
  for (int u : g[v]) if (u != par) {
    siz += dfs3(u, val, v, lv+1);
  }
  productAtDistance[lv] = (productAtDistance[lv] + 1LL * val * siz) % mod;
  return siz;
}


void testMultiply() {
  srand(time(0));
  int n = 2, m = 2;
  vector<int> a(n), b(m);
  for (int i = 0; i < n; ++i) {
    a[i] = rand() % 10;
    cerr << a[i] << " ";
  }
  cerr << endl;
  for (int i = 0; i < m; ++i) {
    b[i] = rand() % 10;
    cerr << b[i] << " ";
  }
  cerr << endl;
  vector<int> res = multiplymod(a, b);
  for (int x : res)
    cerr << x << " ";
  cerr << endl;
  vector<int> res2(n+m-1, 0);
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < m; ++j) {
      res2[i+j] = (res2[i+j] + 1LL * a[i] * b[j]) % mod;
    }
  }
  assert(res2.size() == res.size());
  for (int i = 0; i < res2.size(); ++i) {
    // res[i] %= mod;
    // if (res[i] < 0) res[i] += mod;
    cerr << res[i] << " = " << res2[i] << endl;
    assert((res[i] % mod) == res2[i]);
  }
  cerr << "done" << endl;
}

int main() {
  fac[0] = inv[0] = 1;
  for (int i = 1; i < N; ++i) {
    fac[i] = fac[i-1] * i % mod;
    inv[i] = powmod(fac[i], mod-2);
  }
  for (int i = 0; i < LG; ++i) {
    int n = 1 << i;
    root[i].resize(n);
    for(int j = 0; j < n; ++j) {
      long double ang = 2.0*PI*j/n;
      root[i][j] = cd(cos(ang), sin(ang));
    }
  }
  // testMultiply();
  int n;
  scanf("%d", &n);
  for (int i = 1; i < n; ++i) {
    int u, v;
    scanf("%d %d", &u, &v);
    --u, --v;
    g[u].push_back(v);
    g[v].push_back(u);
  }
  int nn = 1LL * n * n % mod;
  for (int i = 0; i < n; ++i) {
    long long cur = nn * (i+1) % mod;
    ans[i] = cur * 1LL * C(n-1, i) % mod;
  }
  long long sum = 2LL * nn * (n-1) % mod;
  sum = (mod - sum) % mod;
  fill(live, live+n, 1);
  getSz(0);
  if (sum < 0) sum += mod;
  for (int i = 1; i < n; ++i) {
    long long cur = 1LL * sz[i] * sz[i] + 1LL * (n-sz[i]) * (n-sz[i]);
    cur %= mod;
    sum += cur;
    if (sum >= mod) sum -= mod;
  }
  for (int i = 1; i < n; ++i) {
    ans[i] = (ans[i] + sum * C(n-2, i-1)) % mod;
    if (ans[i] < 0) ans[i] += mod;
  }
  fill(live, live+n, 1);
  centroid(0);
  // for (int i = 0; i < n; ++i) {
  //   getSz(i);
  //   for (int u : g[i]) {
  //     dfs3(u, n-sz[u], i, 1);
  //   }
  // }
  vector<int> vs(n-2);
  for (int i = 2; i < n; ++i) {
    vs[n-1-i] = productAtDistance[i] % mod;
  }
  generatePlusOne(vs);
  for (int i = 0; i < vs.size(); ++i) {
    ans[i+2] = (ans[i+2] + vs[i]) % mod;
    if (ans[i+2] < 0) ans[i+2] += mod;
  }
  int mul = 1;
  for (int i = 0; i < n; ++i) {
    printf("%d%c", 1LL * ans[i] * mul % mod, i == n-1 ? '\n' : ' ');
    mul = (1LL * mul * powmod(n-1-i, mod-2)) % mod;
    mul = (1LL * mul * (i+1)) % mod;
  }
  return 0;
}