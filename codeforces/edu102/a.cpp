#include <bits/stdc++.h>

using namespace std;

void solve() {
  int n, d;
  scanf("%d %d", &n, &d);
  vector<int> a(n);
  for (int i = 0; i < n; ++i)
    scanf("%d", &a[i]);
  bool ok = *max_element(a.begin(), a.end()) <= d;
  for (int i = 0; i < n; ++i) {
    for (int j = i+1; j < n; ++j)
      if (a[i] + a[j] <= d)
        ok = true;
  }
  puts(ok ? "YES" : "NO");
}

int main() {
  int t;
  scanf("%d", &t);
  while (t--) {
    solve();
  }
  return 0;
}
