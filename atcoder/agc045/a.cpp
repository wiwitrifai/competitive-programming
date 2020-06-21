#include <bits/stdc++.h>

using namespace std;

const int N = 212, B = 61;

char s[N];

long long val[B];

int main() {
  int t;
  scanf("%d", &t);
  while (t--) {
    int n;
    scanf("%d", &n);
    vector<long long> a(n);
    for (int i = 0; i < n; ++i)
      scanf("%lld", &a[i]);
    scanf("%s", s);
    if (s[n-1] == '1') {
      puts("1");
      continue;
    }
    memset(val, 0, sizeof val);
    bool ok = true;
    for (int i = n-1; i >= 0; --i) {
      if (s[i] == '0') {
        long long x = a[i];
        for (int j = B-1; j >= 0; --j) {
          if (((x >> j) & 1) == 0) continue;
          if (val[j] == 0) continue;
          x ^= val[j];
        }
        if (x) {
          int pos = 63 - __builtin_clzll(x);
          val[pos] = x;
          for (int j = 0; j < B; ++j) {
            if (j == pos) continue;
            if ((val[j] >> pos) & 1) {
              val[j] ^= x;
            }
          }
        }
      } else {
        long long x = a[i];
        for (int j = B-1; j >= 0; --j) {
          x = min(x, x^val[j]);
        }
        if (x) {
          ok = false;
          break;
        }
      }
    }
    puts(ok ? "0" : "1");
  }
  return 0;
}
