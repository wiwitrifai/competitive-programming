#include <bits/stdc++.h>

using namespace std;

void solve() {
  int n;
  scanf("%d", &n);
  vector<int> a(n);
  for (int i = 0; i < n; ++i) {
    scanf("%d", &a[i]);
  }
  sort(a.begin(), a.end());
  if (n > 1)
    reverse(a.begin() + 1, a.end());
  for (int i = 0; i < n; ++i)
    printf("%d%c", a[i], i+1 == n ? '\n' : ' ');
}

int main() {
  int tc = 1;
  // scanf("%d", &tc);
  while (tc--) {
    solve();
  }
  return 0;
}
