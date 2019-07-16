#include <bits/stdc++.h>

using namespace std;

const int N = 2018;
const long long inf = 1e18;
const long long inf2 = 2e9 + 7;
long long a[N], b[N];
int x[N];

void read(int n, long long * res) {
  for (int i = 0; i < n; ++i) {
    scanf("%d", x+i);
  }
  for (int i = 0; i < n; ++i) {
    long long sum = 0;
    for (int j = i; j < n; ++j) {
      sum += x[j];
      res[j-i+1] = min(res[j-i+1], sum);
    }
  }
  res[0] = 0;
}

long long mul(long long x, long long y) {
  if (x >= inf2 || y >= inf2)
    return inf2;
  return x * y;
}

int main() {
  int n, m;
  scanf("%d %d", &n, &m);
  fill(a, a+n+1, inf);
  fill(b, b+m+1, inf);
  read(n, a);
  read(m, b);
  int ans = 0;
  int z;
  scanf("%d", &z);
  for (int i = 1; i <= n; ++i) {
    for (int j = 1; j <= m; ++j) {
      if (mul(a[i], b[j]) <= z)
        ans = max(ans, i * j);
    }
  }
  printf("%d\n", ans);
  return 0;
}