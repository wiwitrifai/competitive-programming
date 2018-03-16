#include <bits/stdc++.h>

using namespace std;

const int N = 2020;

int a[N][N], b[N][N];
long long sum[N][N];
struct hashh {
  int p, q, mod;
  long long pp[N], qq[N];
  hashh(int p, int q, int mod) : p(p), q(q), mod(mod) {
    pp[0] = qq[0] = 1;
    for (int i = 1; i < N; ++i) {
      pp[i] = pp[i-1] * p % mod;
      qq[i] = qq[i-1] * q % mod;
    }  
  }
  vector<int> calc(int  x[N][N], int n, int m, int k) {
    for (int i = 0; i < n; ++i) {
      for (int j = 0; j < m; ++j) {
        sum[i][j] = x[i][j];
        if (i > 0)
          sum[i][j] += sum[i-1][j] * p % mod;
        if (j > 0)
          sum[i][j] += sum[i][j-1] * q % mod;
        if (i > 0 && j > 0)
          sum[i][j] -= (sum[i-1][j-1] * (1LL * p * q % mod)) % mod;
        sum[i][j] %= mod;
        if (sum[i][j] < 0) sum[i][j] += mod;
      }
    }
    long long pq = 1LL * pp[k] * qq[k] % mod;
    vector<int> ret;
    for (int i = 0; i + k <= n; ++i) {
      for (int j = 0; j + k <= m; ++j) {
        long long cur = sum[i+k-1][j+k-1];
        if (i > 0)
          cur -= sum[i-1][j+k-1] * pp[k] % mod;
        if (j > 0)
          cur -= sum[i+k-1][j-1] * qq[k] % mod;
        if (i > 0 && j > 0) {
          cur += sum[i-1][j-1] * pq % mod;
        }
        cur %= mod;
        if (cur < 0) cur += mod;
        ret.push_back(cur);
      }
    }
    return ret;
  }
};

hashh * h[3];
vector<int> res[3];
vector<pair<int, int> > get(int x[N][N], int n, int m, int k) {
  vector<pair<int, int> > ret;
  for (int i = 0; i < 2; ++i) {
    res[i] = h[i]->calc(x, n, m, k);
  }
  int sz = res[0].size();
  for (int i = 0; i < sz; ++i) {
    pair<int, int> cur = make_pair(res[0][i], res[1][i]);
    ret.push_back(cur);
  }
  return ret;
}

int main() {
  h[0] = new hashh(29, 59, 1e9 + 7);
  h[1] = new hashh(73, 101, 1e9 + 9);
  // h[2] = new hashh(43, 39, 1e9 + 87);
  int na, ma, nb, mb, k;
  scanf("%d %d %d %d %d", &na, &ma, &nb, &mb, &k);
  for (int i = 0; i < na; ++i) {
    for (int j = 0; j < ma; ++j)
      scanf("%d", a[i]+j);
  }
  for (int i = 0; i < nb; ++i) {
    for (int j = 0; j < mb; ++j)
      scanf("%d", b[i]+j);
  }
  vector<pair<int, int> > ra = get(a, na, ma, k), rb = get(b, nb, mb, k);
  sort(ra.begin(), ra.end());
  sort(rb.begin(), rb.end());
  // cerr << ra.size() << " " << rb.size() << endl;
  long long ans = 0;
  for (int i = 0, l = 0, r = 0; i < ra.size(); ++i) {
    while (l < rb.size() && rb[l] < ra[i]) ++l;
    while (r < rb.size() && rb[r] <= ra[i]) ++r;
    ans += r-l;
  }
  printf("%lld\n", ans);
  return 0;
}