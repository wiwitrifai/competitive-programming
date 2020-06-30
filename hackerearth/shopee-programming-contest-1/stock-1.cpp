#include <bits/stdc++.h>

using namespace std;

const int N = 1e5 + 5, inf = 1e9 + 7;

int stock[N], type[N], ancestor[N], qty[N], par[N];
long long mul[N];

int main() {
  int n;
  scanf("%d %d", &n, stock+1);
  type[1] = 2;
  for (int i = 2; i <= n; ++i) {
    scanf("%d %d %d", type+i, par+i, qty+i);
    int p = par[i];
    mul[i] = qty[i];
    ancestor[i] = par[i];
    if (type[p] != 2) {
      ancestor[i] = ancestor[p];
      mul[i] = min(mul[p] * qty[i], (long long)inf);
    }
    if (type[i] == 2) {
      scanf("%d", stock+i);
      int a = ancestor[i];
      stock[a] -= stock[i] * mul[i];
      stock[a] = max(stock[a], 0);
    }
  }
  for (int i = 1; i <= n; ++i) {
    if (type[i] == 1) {
      stock[i] = stock[par[i]] / qty[i];
    }
    printf("%d\n", stock[i]);
  }
  return 0;
}
