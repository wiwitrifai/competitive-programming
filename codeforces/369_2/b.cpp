#include <bits/stdc++.h>

using namespace std;

const int N = 505;

long long a[N][N];

int main() {
  int n;
  scanf("%d", &n);

  long long sum = 0, sub = 0;
  for (int i = 0; i < n; i++) {
    bool ok = true;
    long long now = 0;
    for (int j = 0; j < n; j++) {
      scanf("%I64d", a[i]+j);
      now += a[i][j];
      if (a[i][j] == 0) {
        ok = false;
      }
    }
    if (ok)
      sum = now;
    else
      sub = now;
  }
  if (n == 1) {
    puts("1");
    return 0;
  }
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) if (a[i][j] == 0) {
      a[i][j] = sum - sub;
    }
  }
  bool ok = (sum - sub) > 0;
  long long d1 = 0, d2 = 0;
  for (int i = 0; i < n; i++) {
    long long now = 0;
    for (int j = 0; j < n; j++) {
      now += a[i][j];
    }
    if (now != sum) {
      ok = false;
    }
    now = 0;
    for (int j = 0; j < n; j++) {
      now += a[j][i];
    }
    if (now != sum)
      ok = false;
    d1 += a[i][i];
    d2 += a[i][n-i-1];
  }
  if (d1 != sum || d2 != sum) {
    ok = false;
  }
  printf("%I64d\n", ok ? sum - sub : -1);
  return 0;
}