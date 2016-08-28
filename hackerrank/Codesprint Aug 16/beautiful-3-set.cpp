#include <bits/stdc++.h>

using namespace std;

int main() {
  int n;
  cin >> n;
  int k = (n + 2)/3;
  int r = (3 - (n % 3)) % 3;
  printf("%d\n", k * 2 + 1 - r);
  int now = k;
  for (int i = 0; i + now <= n; i++, now++) {
    printf("%d %d %d\n", i, now, n - i - now);
  }
  now = k+1;
  for (int i = 0; i + now <= n; i++, now++) {
    printf("%d %d %d\n", now, i, n - i - now);
  }

  return 0;
}