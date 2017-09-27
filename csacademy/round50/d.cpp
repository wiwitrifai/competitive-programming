#include <bits/stdc++.h>

using namespace std;

const int N = 1e5 + 5;

int x[N], y[N];

int main() {
  int n, k;
  scanf("%d %d", &n, &k);
  for (int i = 0; i < n; i++) {
    int a, b;
    scanf("%d %d", &a, &b);
    x[b-1] = -a;
  }
  int m = 0;
  for (int i = 0; i < n; i++) {
    int id = upper_bound(y, y+m, x[i]) - y;
    y[id] = x[i];
    m += id == m;
  }
  printf("%d\n", m);
  return 0;
}