#include <bits/stdc++.h>

using namespace std;

const long long inf = 2e18 + 5;

long long pow2(int p) {
  if (p < 0) return 0;
  if (p >= 62)
    return inf;
  long long ret = 1LL << p;
  return min(ret, inf);
}
long long mul(long long a, long long b) {
  if (a == 0) return 0;
  long long c = (inf + a - 1) / a;
  if (c <= b)
    return inf;
  return min(a * b, inf);
}

long long calc(int a, int b, int p, int q, bool genap, bool ganjil) {
  if (genap && ganjil) {
    long long ret = mul(pow2(p+q), pow2(b-q)-1) + pow2(a+q);
    if (ret > inf) ret = inf;
    return ret;
  }
  else if (genap)
    return pow2(p+b);
  else if (ganjil)
    return pow2(q+a);
  else
    return 0;
}
const int N = 1e5 + 5;
char s[N];

int main() {
  int tt;
  scanf("%d", &tt);
  for (int tc = 1; tc <= tt; tc++) {
    printf("Case #%d: ", tc);
    int n;
    long long k;
    scanf("%d %lld", &n, &k);
    int a = (n+1)/2, b = n - a, p = (a+1)/2, q = (b + 1) / 2;
    bool genap = 1, ganjil = 1;
    if (calc(a, b, p, q, genap, ganjil) < k) {
      puts("NOT FOUND!");
      continue;
    }
    int lgenap = (n+1)/2, lganjil = n - lgenap;
    for (int i = 0; i < n; i++) {
      bool fixed = 0, bgenap = genap, bganjil = ganjil;
      s[i] = '0';
      if ((i & 1) == 0) {
        int now = i/2, rev = lgenap - 1 - now;
        if (rev < now) {
          if (s[rev * 2] == '1')
            bgenap = 0;
        }
        a--;
        p = max(0, p-1);
      }
      else {
        int now = i/2, rev = lganjil - 1 - now;
        if (rev < now) {
          if (s[rev * 2 + 1] == '1')
            bganjil = 0;
        }
        b--;
        q = max(0, q-1);
      }
      if (!bgenap && !bganjil)
        s[i] = '1';
      long long now = calc(a, b, p, q, bgenap, bganjil);
      //cerr << s[i] << " " << now << " " << k << " " << a << b << p << q << bgenap << bganjil << endl;
      //cerr << i << " " << now << endl;
      if (s[i] == '0' && now < k)
        s[i] = '1';
      if (s[i] == '1')
        k -= now;
      if (i & 1) {
        int now = i/2, rev = lganjil - 1 - now;
        if (rev < now)
          ganjil &= s[i] == s[2 * rev + 1];
      }
      else {
        int now = i/2, rev = lgenap - 1 - now;
        if (rev < now)
          genap &= s[i] == s[2 * rev];        
      }
    }
    s[n] = 0;
    printf("%s\n", s);
  }
  return 0;
}