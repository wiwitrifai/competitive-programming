#include <bits/stdc++.h>

using namespace std;

const int N = 1 << 26;
int b[N];

int main() {
  int n, k = 0;
  scanf("%d", &n);
  for (int i = 0; i < n; i++) {
    int x;
    scanf("%d", &x);
    b[x] = 1;
    k = max(k, 32-__builtin_clz(x));
  }
  int kk = 1 << k;
  pair< int, int > best = {0, 0};
  for (int mask = 0; mask < kk; mask++) {
    if (b[mask]) {
      for (int c = b[mask]; c < kk; c <<= 1) {
        int nmask = c | mask;
        if (nmask == mask) continue;
        if (b[nmask] <= c)
          b[nmask] = c << 1;
      }
    }
    else {
      pair< int, int > now = {__builtin_popcount(mask), mask};
      if (best < now)
        best = now;
    }
  }
  printf("%d\n", (kk-1) ^ best.second);
  return 0;
}