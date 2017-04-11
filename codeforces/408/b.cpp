#include <bits/stdc++.h>

using namespace std;

const int N = 1e6 + 56;

int hole[N];

int main() {
  int n, m, k;
  scanf("%d %d %d", &n, &m, &k);
  for (int i = 0; i < m; i++) {
    int h;
    scanf("%d", &h);
    hole[h] = 1;
  }
  int now = 1;
  for (int i = 0; i < k; i++) {
    int u, v;
    scanf("%d %d", &u, &v);
    if (!hole[now]) {
      if (u == now)
        now = v;
      else if (v == now)
        now = u;
    }
  }
  printf("%d\n", now);

  return 0;
}