#include <bits/stdc++.h>

using namespace std;

const int N = 1024;

long long gcd(long long x, long long y) {
  return x ? gcd(y % x, x) : y;
}
int n, m;
long long g[N];

int main() {
  scanf("%d", &n);
  for (int i = 0; i < n; i++) {
    g[i] = 0;
    int k;
    scanf("%d", &k);
    while (k--) {
      long long c;
      scanf("%lld", &c);
      g[i] = gcd(g[i], c);
    }
  }
  scanf("%d", &m);
  while (m--) {
    long long x;
    int y;
    scanf("%lld %d", &x, &y);
    y--;
    puts((x % g[y]) ? "Tidak" : "Ya");
  }
  return 0;
}