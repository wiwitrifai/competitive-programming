#include <bits/stdc++.h>

using namespace std;

int main() {
  int n, m;
  scanf("%d %d", &n, &m);
  int chest_odd = 0, key_odd = 0;
  for (int i = 0; i < n; ++i) {
    int x;
    scanf("%d", &x);
    chest_odd += x & 1;
  }
  for (int i = 0; i < m; ++i) {
    int x;
    scanf("%d", &x);
    key_odd += x & 1;
  }
  int ans = min(chest_odd, m - key_odd) + min(n - chest_odd, key_odd);
  printf("%d\n", ans);
  return 0;
}
