#include <bits/stdc++.h>

using namespace std;

const int LG = 20;
const int N = 1 << (LG-1), mod = 1e9 + 7, S = int(sqrt(mod) + 2);
const long double PI = acos(-1);

long long powmod(long long b, long long p) {
  long long r = 1;
  for (; p; p >>= 1, b = b * b % mod)
    if (p & 1)
      r = r * b % mod;
  return r;
}

/***************** FFT dengan complex ******************/


int tmpa[800001], tmpb[800001];
int ww[800001];

int pa[800001], pb[800001];
int pc[800001][3];
int Inv[3][3];

const int magic[3] = {1004535809, 998244353, 104857601};

char str[100001];
const int Mod = mod;

int mypow(int x, int y, int p) {
  int sum = 1;
  for (; y; y >>= 1) {
    if (y & 1) sum = 1LL * sum * x % p;
    x = 1LL * x * x % p;
  }
  return sum;
}

struct Unknown {
  int wn[25], P, G;
  void set(int x, int y) {
    P = x, G = y;
    for (int i = 1; i <= 23; i ++)
      wn[i] = mypow(G, (P - 1) / (1 << i), P);
  }
  void change(int* y, int len) {
    for (int i = 1, j = len / 2; i < len - 1; i ++) {
      if (i < j) swap(y[i], y[j]);
      int k = len / 2;
      for (; j >= k; j -= k, k /= 2);
      j += k;
    }
  }
  void NTT(int *y, int len, int on) {
    change(y, len);
    for (int h = 2, id = 1; h <= len; h <<= 1, ++ id) {
      ww[0] = 1;
      for (int i = 1; i < (h >> 1); i ++) ww[i] = 1LL * ww[i - 1] * wn[id] % P;
      for (int j = 0; j < len; j += h)
        for (int k = j; k < j + (h >> 1); k ++) {
          int u = y[k], t = 1LL * y[k + (h >> 1)] * ww[k - j] % P;
          y[k] = (u + t) % P, y[k + (h >> 1)] = (u - t + P) % P;
        }
    }
    if (on == -1) {
      for (int i = 1; i < len / 2; i ++) swap(y[i], y[len - i]);
      int inv = mypow(len, P - 2, P);
      for (int i = 0; i < len; i ++)
        y[i] = 1LL * y[i] * inv % P;
    }
  }
  void mul(int* A, int* B, int len) {
    NTT(A, len, 1);  NTT(B, len, 1);
    for (int i = 0; i < len; i ++)
      A[i] = 1LL * A[i] * B[i] % P;
    NTT(A, len, -1);
  }
};
Unknown ntt[2];

int CRT(int *a)
{
  int x[3];
  for (int i = 0; i < 2; i ++)
  {
    x[i] = a[i];
    for (int j = 0; j < i; j ++)
    {
      int t = (x[i] - x[j] + magic[i]) % magic[i];
      if (t < 0) t += magic[i];
      x[i] = 1LL * t * Inv[j][i] % magic[i];
    }
  }
  int sum = 1, ret = x[0] % Mod;
  for (int i = 1; i < 2; i ++)
  {
    sum = 1LL * sum * magic[i - 1] % Mod;
    ret += 1LL * x[i] * sum % Mod;
    if(ret >= Mod) ret -= Mod;
  }
  return ret;
}

void multiply(int* a, int* b, int* c, int len)
{
  for (int i = 0; i < 2; i ++)
  {
    for (int j = 0; j < len; j ++)
      pa[j] = a[j], pb[j] = b[j];
    ntt[i].mul(pa, pb, len);
    for (int j = 0; j < len; j ++)
      pc[j][i] = pa[j];
  }
  for (int i = 0; i < len; i ++) c[i] = CRT(pc[i]);
}

void Prepare()
{
  for (int i = 0; i < 2; i ++) ntt[i].set(magic[i], 3);
  for (int i = 0; i < 2; i ++)
    for (int j = i + 1; j < 2; j ++)
      Inv[i][j] = mypow(magic[i], magic[j] - 2, magic[j]);
}

int multiplymod(int n, int * a, int m, int * b, int * res) {
  int s = (n + m - 1);
  int lg = 31- __builtin_clz(s);
  if (s & (s-1)) ++lg;
  int len = 1 << lg;
  fill(b+m, b+len, 0);
  fill(a+n, a+len, 0);
  multiply(a, b, res, len);
  return s;
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

int sumAtLv[N], cumulative[N];
long long fac[N], inv[N];
long long ans[N];
long long productAtDistance[N];

long long C(int n, int k) {
  if (k < 0 || n < k) return 0;
  return (fac[n] * inv[k] % mod) * inv[n-k] % mod;
}

int mlv = 0;
int dfs(int v, int par = -1, int lv = 1) {
  mlv = max(mlv, lv);
  int siz = 1;
  for (int u : g[v]) if (u != par && live[u])
    siz += dfs(u, v, lv+1);
  sumAtLv[lv] += siz;
  if (sumAtLv[lv] >= mod) sumAtLv[lv] -= mod;
  return siz;
}

int dfs2(int v, int val, int par = -1, int lv = 1) {
  mlv = max(mlv, lv);
  int siz = 1;
  for (int u : g[v]) if (u != par && live[u])
    siz += dfs2(u, val, v, lv+1);
  productAtDistance[lv] = (productAtDistance[lv] + 2LL * val * siz) % mod;
  return siz;
}

int c[N], bb[N];

void generatePlusOne(int l, int r, int * vs) {
  if (r - l < 2) return;
  int mid = (l + r) >> 1;
  generatePlusOne(l, mid, vs);
  generatePlusOne(mid, r, vs);
  for (int i = 0; i <= mid-l; ++i)
    c[i] = C(mid, i);
  for (int i = 0; i < r-mid; ++i)
    bb[i] = vs[mid+i], vs[mid+i] = 0;
  multiplymod(r-mid, bb, mid-l+1, c, bb);
  for (int j = l; j < r; ++j) {
    vs[j] += bb[j-l];
    if (vs[j] >= mod) vs[j] -= mod;
  }
}

int vs[N];

void centroid(int v) {
  getSz(v);
  int tot = sz[v];
  while (big[v] != -1 && 2 * sz[big[v]] >= tot) v = big[v];
  live[v] = 0;
  fill(cumulative, cumulative+tot+1, 0);
  mlv = 0;
  for (int u : g[v]) if (live[u]) {
    int lastmlv = mlv;
    mlv = 0;
    int s = dfs(u, v);
    dfs2(u, tot-s, v);
    for (int i = 0; i <= s; ++i) {
      if (sumAtLv[i] < 0) sumAtLv[i] += mod;
      vs[i] = sumAtLv[i];
    }
    int res = multiplymod(mlv+1, sumAtLv, mlv+1, sumAtLv, vs);
    for (int i = 0; i < res; ++i) {
      productAtDistance[i] -= vs[i];
      if (productAtDistance[i] < 0) productAtDistance[i] += mod;
    }
    for (int i = 0; i <= s; ++i) {
      cumulative[i] += sumAtLv[i];
      if (cumulative[i] >= mod) cumulative[i] -= mod;
      sumAtLv[i] = 0;
    }
    mlv = max(mlv, lastmlv);
  }
  int res = multiplymod(mlv+1, cumulative, mlv+1, cumulative, vs);
  for (int i = 0; i < res; ++i) {
    productAtDistance[i] = (productAtDistance[i] + vs[i]);
    if (productAtDistance[i] > 0) productAtDistance[i] -= mod;
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


// void testMultiply() {
//   srand(time(0));
//   int n = 2, m = 2;
//   vector<int> a(n), b(m);
//   for (int i = 0; i < n; ++i) {
//     a[i] = rand() % 10;
//     cerr << a[i] << " ";
//   }
//   cerr << endl;
//   for (int i = 0; i < m; ++i) {
//     b[i] = rand() % 10;
//     cerr << b[i] << " ";
//   }
//   cerr << endl;
//   vector<int> res = multiplymod(a, b);
//   for (int x : res)
//     cerr << x << " ";
//   cerr << endl;
//   vector<int> res2(n+m-1, 0);
//   for (int i = 0; i < n; ++i) {
//     for (int j = 0; j < m; ++j) {
//       res2[i+j] = (res2[i+j] + 1LL * a[i] * b[j]) % mod;
//     }
//   }
//   assert(res2.size() == res.size());
//   for (int i = 0; i < res2.size(); ++i) {
//     // res[i] %= mod;
//     // if (res[i] < 0) res[i] += mod;
//     cerr << res[i] << " = " << res2[i] << endl;
//     assert((res[i] % mod) == res2[i]);
//   }
//   cerr << "done" << endl;
// }

int main() {
  fac[0] = inv[0] = 1;
  for (int i = 1; i < N; ++i) {
    fac[i] = fac[i-1] * i % mod;
    inv[i] = powmod(fac[i], mod-2);
  }
  Prepare();
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
  // centroid(0);
  for (int i = 0; i < n; ++i) {
    getSz(i);
    for (int u : g[i]) {
      dfs3(u, n-sz[u], i, 1);
    }
  }
  fill(vs, vs + n-2, 0);
  for (int i = 2; i < n; ++i) {
    vs[n-1-i] = productAtDistance[i] % mod;
  }
  generatePlusOne(0, n-2, vs);
  for (int i = 0; i < n-2; ++i) {
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