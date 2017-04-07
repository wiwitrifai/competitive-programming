#include <bits/stdc++.h>

using namespace std;

int m[111][111], n, a[111];
int gcd(int x, int y) {
  return x ? gcd(y % x, x) : y;
}

int main() {
  scanf("%d", &n);
  for (int i = 0; i < n; i++) {
    int now = 0;
    for (int j = 0; j < n; j++)
      scanf("%d", m[i]+j), now = gcd(now, m[i][j]);
    a[i] = now;
  }
  int g = 0;
  for (int i = 0; i < n; i++) {
    g = gcd(g, a[i]);
  }
  int d = 1;
  for (; d * d < g; d++);
  for (int i = 0; i < n; i++) {
    a[i] /= d;
    printf("%d%c", a[i], i == n-1 ? '\n' : ' ');
  } 
  return 0;
}