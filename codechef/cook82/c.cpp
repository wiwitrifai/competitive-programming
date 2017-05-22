#include <bits/stdc++.h>

using namespace std;

const int N = 1e6 + 6;

long long ans[N * 70];
int c = 0;
vector< long long > v[70];

int main() {
  int n, m;
  scanf("%d %d", &n, &m);
  for (int i = 0; i < n; i++) {
    long long x;
    scanf("%lld", &x);
    v[64-__builtin_clzll(x)].push_back(x);
  }
  c = 0;
  int l = 0;
  for (int i = 64; i >= 0; i--) {
    sort(v[i].begin(), v[i].end());
    reverse(v[i].begin(), v[i].end());
    int le = l, ri = c;
    for (long long x : v[i]) {
      while (le < ri && (ans[le]>>1) > x)
        ans[c++] = ans[le++]>>1;
      ans[c++] = x;
    }
    while (le < ri)
      ans[c++] = ans[le++]>>1;
    l = ri;
  }
  for (int i = 0; i < m; i++) {
    int x;
    scanf("%d", &x);
    if (x > c)
      puts("0");
    else
      printf("%lld\n", ans[x-1]);
  }
  return 0;
}