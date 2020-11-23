#include <bits/stdc++.h>

using namespace std;

int main() {
  int n, m;
  scanf("%d %d", &n, &m);
  vector<int> a(n);
  for (int i = 0; i < n; ++i) {
    scanf("%d", &a[i]);
  }
  sort(a.begin(), a.end());
  if (a[0] == a.back()) {
    puts("0");
    return 0;
  }
  int ans = a.back() - a[0];
  for (int i = 0; i + 1 < n; ++i) {
    ans = min(ans, m - (a[i+1] - a[i]));
  }
  printf("%d\n", ans);
  return 0;
}
