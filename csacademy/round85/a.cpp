#include <bits/stdc++.h>

using namespace std;

const int N = 105;

int ada[N];

int main() {
  int n, q, x;
  scanf("%d %d %d", &n, &q, &x);
  ada[x] = 1;
  for (int i = 0; i < q; ++i) {
    int u, v;
    scanf("%d %d", &u, &v);
    swap(ada[u], ada[v]);
  }
  int ans = -1;
  for (int i = 1; i <= n; ++i)
    if (ada[i])
      ans = i;
  printf("%d\n", ans);
  return 0;
}