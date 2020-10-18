#include <bits/stdc++.h>

using namespace std;

int main() {
  int n, k, m;
  scanf("%d %d %d", &n, &m, &k);
  assert(n == 99999);
  assert(m == 50000);
  assert(k == 99999);
  for (int i = 1; i <= k; ++i) {
    int x;
    scanf("%d", &x);
    assert(x == i);
  }
  for (int i = 1; i <= 49999; ++i) {
    printf("%d %d %d %d\n", 0, i, i, i+1);
  }
  for (int i = 1; i <= 49999; ++i) {
    int len = 49999 + i;
    printf("%d %d %d %d\n", n-len, n, m-i, m-i+1);
  }
  printf("%d %d %d %d\n", 0, n, 0, 1);
  return 0;
}
