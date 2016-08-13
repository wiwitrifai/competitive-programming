#include <bits/stdc++.h>

using namespace std;

const int N = 1e6 + 6;

int n, last[N], m, a[N];
int main() {
  scanf("%d %d", &n, &m);
  int cur = -1, id = 0;
  for (int i = 1; i <= n; i++) {
    scanf("%d", a+i);
    if (cur != a[i]) {
      id = i-1;
      cur = a[i];
    }
    last[i] = id;
  }
  while (m--) {
    int l, r, x;
    scanf("%d %d %d", &l, &r, &x);
    if (a[r] != x) {
      printf("%d\n", r);
    }
    else if (last[r] < l)
      printf("%d\n", -1);
    else
      printf("%d\n", last[r]);
  }
  return 0;
}