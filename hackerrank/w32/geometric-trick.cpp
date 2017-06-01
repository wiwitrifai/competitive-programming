#include <bits/stdc++.h>

using namespace std;

const int N = 1e6 + 5;

char s[N];
bitset< N > isprim;
vector< long long > f[N];
int n;

int main() {
  scanf("%d", &n);
  scanf("%s", s+1);
  n += 1;
  for (int i = 1; i < n; i++) {
    f[i].clear();
    if (s[i] == 'b')
      f[i].push_back(1);
  }
  isprim.set();
  for (int i = 2; i < n; i++) if (isprim[i]) {
    for (int j = i; j < n; j += i) {
      isprim[j] = 0;
      int now = j, m = 0;
      while ((now % i) == 0) now /= i, m++;
      m *= 2;
      int sz = f[j].size();
      for (int k = 0; k < sz; k++) {
        long long cur = f[j][k];
        for (int z = 0; z < m; z++) {
          cur *= i;
          if (cur >= n) break;
          f[j].push_back(cur);
        }
      }
    }
  }
  long long ans = 0;
  for (int i = 1; i < n; i++) if (s[i] == 'b') {
    for (long long x : f[i]) {
      if (x >= n) continue;
      long long y = 1LL * i * i / x;
      if (y >= n) continue;
      if (s[x] == 'a' && s[y] == 'c')
        ans++;
    }
  }
  printf("%lld\n", ans);
  return 0;
}