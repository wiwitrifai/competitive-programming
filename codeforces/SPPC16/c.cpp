#include <bits/stdc++.h>

using namespace std;

/***************** FFT dengan complex ******************/
typedef complex<double> cd;
typedef vector< cd > vcd;
const double M_PI = acos(-1);

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
const int N = 5e5 + 6;
int a[N], t[N];

int main() {
  int n, p;
  string s;
  
  scanf("%d%d", &n, &p);
  cin >> s;
  
  for (int i = 0; i < n; ++i) {
    if (s[i] == 'B') a[i] = 0;
    if (s[i] == 'R') a[i] = 1;
    if (s[i] == 'Y') a[i] = 2;
  }
  
  int sz = 1;
  while (sz < n * 2) sz <<= 1;
  sz <<= 1;
  for (int c = 0; c < 3; c++) {
    vcd x, y;
    x.assign(sz, 0);
    y.assign(sz, 0);
    int cnt = 0;
    for (int i = 0; i < n; i++) {
      x[i] = a[i] == c;
      cnt += a[i] == c;
      y[n-1-i] = y[n-1-i+n] = a[i] == c;
    }
    vcd vx = fft(x), vy = fft(y);
    for (int i = 0; i < sz; i++)
      vx[i] *= vy[i];
    x = inv_fft(vx);
    for (int i = 0; i < n; i++) {
      t[i] += max(cnt - int (x[i + n-1].real() + 0.5), 0);
    }
  }
  vector< pair< int, int> > shift;
  for (int i = 1; i < n; i++) {
    shift.emplace_back(t[i], i);
  }
  sort(shift.begin(), shift.end());
  int val = shift[p-1].first;
  int ans = n;
  for (int i = 0; i < shift.size(); i++)
    if (shift[i].first == val)
      ans = min(ans, shift[i].second);
  printf("%d\n", ans);

  return 0;
}