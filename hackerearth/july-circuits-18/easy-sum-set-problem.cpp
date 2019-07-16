#include <bits/stdc++.h>

using namespace std;

int main() {
  int n, m;
  set<int> a, c;
  scanf("%d", &n);
  for (int i = 0; i < n; ++i) {
    int x;
    scanf("%d", &x);
    a.insert(x);
  }
  scanf("%d", &m);
  for (int i = 0; i < m; ++i) {
    int x;
    scanf("%d", &x);
    c.insert(x);
  }
  set<int> b;
  for (int x = 1; x <= 100; ++x) {
    bool ok = 1;
    for (int xa : a)
      if (!c.count(xa + x)) {
        ok = 0;
        break;
      }
    if (ok)
      b.insert(x);
  }
  for (int x : b)
    printf("%d ", x);
  printf("\n");
  return 0;
}