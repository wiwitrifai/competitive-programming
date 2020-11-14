#include <bits/stdc++.h>

using namespace std;

void solve() {
  int n;
  scanf("%d", &n);
  vector<int> b(n);
  for (int i = 0; i < n; ++i) {
    scanf("%d", &b[i]);
  }
  bool ok = false;
  sort(b.begin(), b.end());
  for (int i = 0; i + 1 < n; ++i) {
    ok |= b[i] == b[i+1];
  }
  puts(ok ? "YES" : "NO");
}

int main() {
  int tc = 1;
  scanf("%d", &tc);
  while (tc--) {
    solve();
  }
  return 0;
}
