#include <bits/stdc++.h>

using namespace std;

void solve() {
  int n, x;
  scanf("%d %d", &n, &x);
  int last = n, sum = 0, ans = -1;
  for (int i = 0; i < n; ++i) {
    int a;
    scanf("%d", &a);
    sum += a;
    sum %= x;
    if (sum) {
      ans = max(ans, i+1);
      last = min(last, i);
    }
    else {
      ans = max(ans, i - last);
    }
  }
  printf("%d\n", ans);
}

int main() {
  int t;
  scanf("%d", &t);
  while (t--) {
    solve();
  }
  return 0;
}
