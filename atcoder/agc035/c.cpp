#include <bits/stdc++.h>

using namespace std;

int main() {
  int n;
  scanf("%d", &n);
  if (n <= 2) {
    puts("No");
    return 0;
  }
  int dua = 1;
  while ((dua << 1) <= n+1) dua <<= 1;
  if (n == dua) {
    puts("No");
    return 0;
  }
  puts("Yes");
  for (int i = 1; i + 1 < dua; ++i) {
    printf("%d %d\n", i, i+1);
    printf("%d %d\n", n + i, n + i + 1);
  }
  printf("%d %d\n", dua-1, n+1);
  if (dua > n) {
    return 0;
  }
  int cnt = n - dua + 1;
  int k = n;
  if (cnt & 1)
    --k;
  for (int i = dua; i + 1 <= k; ++i) {
    printf("%d %d\n", i, i+1);
    printf("%d %d\n", n + i, n + i + 1);
  }
  int val = 0;
  for (int i = dua; i <= k; ++i)
    val ^= i;
  int last = val;
  if (val == 0) {
    printf("%d %d\n", k, 1);
    printf("%d %d\n", dua-1, n + dua);
    last = dua-1;
  }
  else {
    printf("%d %d\n", k, n + val);
    printf("%d %d\n", n + val, n + dua);
    last = n + val;
  }
  if (k < n) {
    printf("%d %d\n", n+dua, n);
    int cur = n^dua;
    int v = last;
    while (v <= 2*n) {
      int cost = v;
      if (cost > n)
        cost -= n;
      cur ^= cost;
      if (cur == 0)
        break;
      ++v;
      if (v == dua)
        v = n+1;
    }
    if (v > 2 * n) {
      cur = n^dua;
      v = last;
      while (v > 0) {
        int cost = v;
        if (cost > n)
          cost -= n;
        cur ^= cost;
        if (cur == 0)
          break;
        --v;
        if (v == n)
          v = dua-1;
      }
    }
    assert(cur == 0);
    printf("%d %d\n", v, 2 * n);
  }
  return 0;
}
