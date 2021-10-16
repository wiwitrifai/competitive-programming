#include <bits/stdc++.h>

using namespace std;

/***************** FFT dengan complex ******************/
typedef complex<double> cd;
typedef vector< cd > vcd;

// asumsi ukuran as = 2^k, dengan k bilangan bulat positif
vcd fft(const vcd &as) {
  int n = (int)as.size();
  int k = 0;
  while((1<<k) < n) k++;
  assert(n == (1 << k));
  vector< int > r(n);
  r[0] = 0;
  int h = -1;
  for(int i = 1; i<n; i++) {
    if((i & (i-1)) == 0)
      h++;
    r[i] = r[i ^ (1 << h)];
    r[i] |= (1<<(k-h-1));
  }
  vcd root(n);
  for(int i = 0; i<n; i++) {
    double ang = 2.0*M_PI*i/n;
    root[i] = cd(cos(ang), sin(ang));
  }

  vcd cur(n);
  for(int i = 0; i<n; i++)
    cur[i] = as[r[i]];

  for(int len = 1; len < n; len <<= 1 ) {
    vcd ncur(n);
    int step = n/(len << 1);
    for(int pdest = 0; pdest <n;) {
      for(int i = 0; i<len; i++) {
        cd val = root[i*step]*cur[pdest + len];
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
  int n = fa.size();
  vcd res = fft(fa);
  for(int i = 0; i < n; i++) {
    res[i] /= n;
  }
  reverse(res.begin() + 1, res.end());
  return res;
}

int C(int n, int k) {
  return n == 0 ? 1 : ((k & 1) <= (n & 1)) * C(n >> 1, k >> 1);
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  int n, x;
  cin >> n >> x;
  vector<int> a(n);
  for (int i = 0; i < n; ++i) {
    cin >> a[i];
  }
  int len = n + x;
  int pw = 1;
  while (pw < len) pw <<= 1;
  len = pw;
  vcd c(len, 0), bits(len);
  for (int i = 0; i <= x; ++i) {
    c[i] = C(x, i);
  }
  for (int i = x+1; i < len; ++i)
    c[i] = 0;
  c = fft(c);
  vector<int> ans(n - x, 0);
  for (int i = 0; i <= 29; ++i) {
    bits.resize(len);
    for (int j = 0; j < n; ++j) {
      bits[j] = (a[j] >> i) & 1;
    }
    for (int j = n; j < len; ++j)
      bits[j] = 0;
    bits = fft(bits);
    for (int j = 0; j < len; ++j) {
      bits[j] = bits[j] * c[j];
    }
    bits = inv_fft(bits);
    for (int j = 0; j < n - x; ++j) {
      int id = n * i + x + j;
      int v = int(floor(bits[id].real() + 0.5)) & 1;
      if (v & 1)
        ans[j] |= 1 << i;
    }
  }
  for (int i = 0; i < n - x; ++i) {
    cout << ans[i] << ((i + 1 == n-x) ? '\n' : ' ');
  }
  return 0;
}
