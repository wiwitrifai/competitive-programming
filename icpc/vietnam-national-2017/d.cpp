#include <bits/stdc++.h>

using namespace std;

const int N = 1024;

int d[N], t[N];

int main() {
  int n, m;
  scanf("%d", &n);
  for (int i = 0;i < n; ++i) {
    scanf("%d", d+i);
  }
  scanf("%d", &m);
  for (int i = 0; i < m; i++) {
    scanf("%d", t+i);
  }
  int cheap = 1e9;
  for (int i = 0; i < n; i++) {
    int k;
    scanf("%d", &k);
    while (k--) {
      int z;
      scanf("%d", &z);
      z--;
      cheap = min(cheap, d[i] + t[z]);
    }
  }
  int x;
  scanf("%d", &x);
  int ans = max(0, (x/cheap) - 1);
  printf("%d\n", ans);
  return 0;
}