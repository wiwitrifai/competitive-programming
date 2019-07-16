#include <bits/stdc++.h>

using namespace std;

const int N = 1e6 + 6;

int ans[N];

int main() {
  for (int i = 1, j = 1; i < N; ++i) {
    int x = i, last = 0;
    bool ok = 1;
    while (x) {
      int d = x % 10; x /= 10;
      ok &= d != 4;
      ok &= last != 3 || d != 1;
      last = d;
    }
    if (ok)
      ans[i] = j++;
    else
      ans[i] = -1;
  }
  int t;
  scanf("%d", &t);
  while (t--) {
    int n;
    scanf("%d", &n);
    for (int i = 0; i < n; ++i) {
      int a;
      scanf("%d", &a);
      printf("%d%c", ans[a], i == n-1 ? '\n' : ' ');
    }
  }
  return 0;
}