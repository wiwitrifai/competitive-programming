#include <bits/stdc++.h>

using namespace std;

long long shift[66];
long long pw[66];

int main() {
  pw[0] = 1;
  for (int i = 1; i < 66; ++i)
    pw[i] = pw[i-1] * 2;
  int q;
  scanf("%d", &q);
  while (q--) {
    int t;
    long long x, k;
    scanf("%d %lld", &t, &x);
    if (t == 3) {
      int lv = 0;
      while ((1LL << (lv+1)) <= x) ++lv;
      x %= pw[lv];
      x = (x + shift[lv]) % (pw[lv]);
      if (x < 0) x += pw[lv];
      while (lv >= 0) {
        long long res = ((x + pw[lv] - shift[lv]) % pw[lv]);
        if (res < 0) res += pw[lv];
        printf("%lld", res + pw[lv]);
        if (lv) printf(" ");
        --lv; x >>= 1;
      }
      printf("\n");
    }
    else {
      scanf("%lld", &k);
      int lv = 0;
      while ((1LL << (lv+1)) <= x) ++lv;
      k %= pw[lv];
      k = (pw[lv] + k) % pw[lv];
      if (t == 1)
        shift[lv] = (shift[lv] + k) % pw[lv];
      else {
        for (int i = lv; i < 62; ++i) {
          k %= pw[i];
          shift[i] = (shift[i] + k) % pw[i];
          // cerr << i << " shif " <<  shift[i] << endl;
          k <<= 1;
        }
      }
    }
  }
  return 0;
}