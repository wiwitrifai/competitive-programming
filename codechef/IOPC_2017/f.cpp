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
  int nn = fa.size();
  vcd res = fft(fa);
  for(int i = 0; i<nn; i++) {
    res[i] /= nn;
  }
  reverse(res.begin() + 1, res.end());
  return res;
}
const int N = 1e5 + 6;
double q[N];
int main() {
  int n;
  scanf("%d", &n);
  int nn = 4 * n;
  int k = 1;
  while (k < nn) k <<= 1;
  vcd a(k);
  vcd b(k);
  for (int i = 0; i < k; i++)
    a[i] = b[i] = 0;
  for (int i = 0; i < n; i++)
    scanf("%lf", q+i), a[i] = q[i];
  for (int i = -n; i <= n; i++)
    if (i < 0)
      b[i+n] = (double)-50.0/i/i;
    else if (i == 0)
      b[i+n] = 0;
    else
      b[i+n] = (double)50.0/i/i;
  a = fft(a);
  b = fft(b);
  for (int i = 0; i < k; i++) {
    a[i] *= b[i];
  }
  a = inv_fft(a);
  for (int i = 0; i < n; i++)
    printf("%.9lf\n", q[i] * a[n+i].real());
  return 0;
}