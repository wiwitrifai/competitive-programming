#include <bits/stdc++.h>

using namespace std;

const int N = 1e5 + 5, mod = 1e9 + 7;

int d[N];

int main() {
  int n, k;
  scanf("%d %d", &n, &k);
  for (int i = 1; i < n; i++) {
    int u, v;
    scanf("%d %d", &u, &v);
    d[u]++;
    d[v]++;
  }
  long long ans = k;
  for (int i = 1; i <= n; i++) {
    int now = k-1, ch = d[i];
    if (i != 1)
      now--, ch--;
    while (ch--) {
      ans = (ans * now--) % mod;
    }
  }
  printf("%lld\n", ans);
  return 0;
}