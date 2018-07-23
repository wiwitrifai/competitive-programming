#include <bits/stdc++.h>

using namespace std;

const int N = 1e5 + 5, mod = 1e9 + 7, S = int(sqrt(mod) + 1.5);
const long double PI = acos(-1);

long long powmod(long long b, long long p) {
  long long r = 1;
  for (; p; p >>= 1, b = b * b % mod)
    if (p & 1)
      r = r * b % mod;
  return r;
}

/***************** FFT dengan complex ******************/
typedef complex<double> cd;
typedef vector< cd > vcd;

const int LG = 20;

vcd root[N];

// asumsi ukuran as = 2^k, dengan k bilangan bulat positif
vcd fft(int lg, const vcd &as) {
  int n = 1 << lg;
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

vcd inv_fft(int lg, const vcd& fa) {
  vcd res = fft(lg, fa);
  int nn = 1 << lg;
  for(int i = 0; i<nn; i++) {
    res[i] /= nn;
  }
  reverse(res.begin() + 1, res.end());
  return res;
}

vector<int> multiply(vector<int> & a, vector<int> & b) {
  int n = a.size() + b.size();
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
    res[i] = int(va[i].real() + 0.5);
  return res;
}

vector<int> multiplymod(vector<int> & a, vector<int> & b) {
  vector<int> a1(a.size()), a2(a.size()), b1(b.size()), b2(b.size());
  for (int i = 0; i < a.size(); ++i) {
    a1[i] = a[i]/S;
    a2[i] = a[i] - a1[i] * S;
  }
  for (int i = 0; i < b.size(); ++i) {
    b1[i] = b[i]/S;
    b2[i] = b[i] - b1[i] * S;
  }
  vector<int> res11 = multiply(a1, b1);
  vector<int> res12 = multiply(a1, b2);
  vector<int> res21 = multiply(a2, b1);
  vector<int> res22 = multiply(a2, b2);
  int n = res11.size();
  for (int i = 0; i < n; ++i) {
    int now = ((1LL * res11[i] * S + 1LL * (res12[i] + res21[i])) * S + res22[i]) % mod;
    if (now < 0) now += mod;
    res11[i] = now;
  }
  return res11;
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

long long C(int n, int k) {
  if (k < 0 || n < k) return 0;
  return (fac[n] * inv[k] % mod) * inv[n-k] % mod;
}

int dfs(int v, int par = -1, int lv = 0) {
  int siz = 1;
  for (int u : g[v]) if (u != par && live[u]) {
    siz += dfs(u, v, lv+1);
  }
  sumAtLv[lv] += siz;
  return siz;
}

vector<int> dp[N], sum[N], cnt[N];

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

void add(vector<int> & a, vector<int> b) {
  if (a.size() < b.size()) a.resize(b.size());
  for (int i = 0; i < b.size(); ++i) {
    a[i] += b[i];
    if (a[i] >= mod) a[i] -= mod;
  }
}

int centroid(int v) {
  getSz(v);
  int tot = sz[v];
  while (big[v] != -1 && 2 * sz[big[v]] >= tot) v = big[v];
  live[v] = 0;
  dp[v].resize(1);
  sum[v].resize(1);
  cnt[v].resize(1);
  dp[v][0] = sum[v][0] = cnt[v][0] = 1;
  int now = 1;
  for (int u : g[v]) if (live[u]) {
    int c = centroid(u);
    int s = dfs(u);
    vector<int> vs(s);
    for (int i = 0; i < s; ++i)
      vs[s-1-i] = sumAtLv[i], sumAtLv[i] = 0;
    generatePlusOne(vs);
    for (int i = 0; i < s; ++i) {
      cnt[c][i] = C(s-1, i);
      if (cnt[c][i] >= mod) cnt[c][i] -= mod;
      sum[c][i] = (1LL * (s+1) * cnt[c][i] - vs[i]) % mod;
      if (sum[c][i] < 0) sum[c][i] += mod;
    }
    sum[c][0] = s;
    dp[c].push_back(0);
    sum[c].push_back(0);
    cnt[c].push_back(0);
    for (int i = s; i > 0; --i) {
      dp[c][i] += dp[c][i-1];
      if (dp[c][i] >= mod) dp[c][i] -= mod;
      cnt[c][i] += cnt[c][i-1];
      if (cnt[c][i] >= mod) cnt[c][i] -= mod;
    }
    vector<int> t1, t2, t3;
    t3 = multiplymod(sum[v], sum[c]);
    for (int i = 0; i < t3.size(); ++i) {
      t3[i] += t3[i];
      if (t3[i] >= mod) t3[i] -= mod;
    }
    add(t3, multiplymod(dp[v], cnt[c]));
    add(t3, multiplymod(cnt[v], dp[c]));
    t2 = multiplymod(sum[v], cnt[c]);
    add(t2, multiplymod(cnt[v], sum[c]));
    t1 = multiplymod(cnt[v], cnt[c]);
    dp[v].swap(t3);
    sum[v].swap(t2);
    cnt[v].swap(t1);
  }
  live[v] = 1;
  return v;
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
      double ang = 2.0*PI*j/n;
      root[i][j] = cd(cos(ang), sin(ang));
    }
  }
  int n;
  scanf("%d", &n);
  for (int i = 1; i < n; ++i) {
    int u, v;
    scanf("%d %d", &u, &v);
    --u, --v;
    g[u].push_back(v);
    g[v].push_back(u);
  }
  fill(live, live+n, 1);
  int central = centroid(0);
  int mul = 1;
  for (int i = 0; i < n; ++i) {
    printf("%d%c", 1LL * dp[central][i] * mul % mod, i == n-1 ? '\n' : ' ');
    mul = (1LL * mul * powmod(n-1-i, mod-2)) % mod;
    mul = (1LL * mul * (i+1)) % mod;
  }
  return 0;
}