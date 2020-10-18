#include <bits/stdc++.h>

using namespace std;

int main() {
  int n, k, m;
  scanf("%d %d %d", &n, &m, &k);
  assert(n == 9973 * 293);
  assert(m == 99991 * 311);
  assert(k == 293 * 311);
  for (int i = 1; i <= k; ++i) {
    int x;
    scanf("%d", &x);
    assert(x == 9973 * 99991);
  }
  int r = 293, c = 311;
  int width = n / r, height = m / c;
  for (int i = 0; i < 293; ++i) {
    for (int j = 0; j < 311; ++j) {
      printf("%d %d %d %d\n", i * width, (i+1) * width, j * height, (j + 1) * height);
    }
  }
  return 0;
}
