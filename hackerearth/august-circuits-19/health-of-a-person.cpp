#include <bits/stdc++.h>

using namespace std;

int main() {
  int t;
  scanf("%d", &t);
  while (t--) {
    int n, m;
    scanf("%d %d", &n, &m);
    vector<int> a(n), ans(n, -1);
    for (int i = 0; i < n; ++i) {
      scanf("%d", &a[i]);
    }
    for (int i = 0; i < m; ++i) {
      int b;
      scanf("%d", &b);
      for (int j = i; j < n; j += i+1) {
        if (ans[j] >= 0) continue;
        if (b >= a[j])
          ans[j] = i+1;
      }
    }
    for (int i = 0; i < n; ++i)
      printf("%d\n", ans[i]);
  }
  return 0;
}
