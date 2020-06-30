#include <bits/stdc++.h>

using namespace std;

int main() {
  int n;
  scanf("%d", &n);
  vector<int> a(n);
  for (int i = 0; i < n; ++i) {
    scanf("%d", &a[i]);
  }
  sort(a.begin(), a.end());
  if (a[0] == a.back()) {
    puts("1");
  } else {
    bool ok = true;
    for (int i = 0; i + 1 < n; ++i)
      ok &= a[i] < a[i+1];
    int ans = max(n-1, 1);
    if (ok)
      ans = n;
    printf("%d\n", ans);
  }
  return 0;
}
