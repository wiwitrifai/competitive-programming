#include <bits/stdc++.h>

using namespace std;

set<int> p3, p2;
const int inf = 1e9;

int x[55];
int g[55][55];
int din[55];

int gcd(int a, int b) {
  return a ? gcd(b % a, a) : b;
}

int cmp(int a, int b) {
  int d = gcd(a, b);
  a /= d;
  b /= d;
  if (a == 1 && b == 1) {
    puts("-1");
    exit(0);
  }
  if (a != 1 && !p2.count(a) && !p3.count(a)) {
    puts("-1");
    exit(0);
  }
  if (b != 1 && !p2.count(b) && !p3.count(b)) {
    puts("-1");
    exit(0);
  }
  if (p2.count(a) || p3.count(b))
    return 1;
  return 0;
}

int ans[55];

int main() {
  for (long long i = 2; i <= inf; i *= 2)
    p2.insert(i);
  for (long long i = 3; i <= inf; i *= 3)
    p3.insert(i);
  int n, a, b;
  scanf("%d %d %d", &n, &a, &b);
  for (int i = 0; i < n; ++i)
    scanf("%d", x+i);
  x[n] = a;
  x[n+1] = b;
  n += 2;
  for (int i = 0; i < n; ++i) {
    for (int j = i+1; j < n; ++j) {
      int cek = cmp(x[i], x[j]);
      if (cek)
        g[i][j] = 1;
      else
        g[j][i] = 1;
    }
  }
  memset(ans, -1, sizeof ans);
  for (int i = 0; i < n; ++i) {
    din[i] = 0;
    for (int j = 0; j < n; ++j)
      din[i] += g[j][i];
    ans[din[i]] = x[i];
  }
  sort(din, din+n);
  bool ok = (ans[0] == a) && (ans[n-1] == b);
  for (int i = 0; i < n; ++i)
    ok &= din[i] == i;
  if (!ok) {
    puts("-1");
    return 0;
  }
  printf("%d", ans[0]);
  for (int i = 1; i < n; ++i) {
    int d = gcd(ans[i-1], ans[i]);
    int a = ans[i-1]/d, b = ans[i]/d;
    int now = ans[i-1];
    assert(a == 1 || p2.count(a));
    assert(b == 1 || p3.count(b));
    while (a > 1) {
      a /= 2;
      now /= 2;
      printf(" %d", now);
    }
    while (b > 1) {
      b /= 3;
      now *= 3;
      printf(" %d", now);
    }
  }
  printf("\n");
  return 0;
}