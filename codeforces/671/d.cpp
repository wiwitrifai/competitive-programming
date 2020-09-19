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
  vector<int> b = a;
  int j = 0;
  for (int i = 1; i < n; i += 2)
    b[i] = a[j++];
  int r = n-1;
  if (r & 1)
    --r;
  int last = n-1;
  for (int i = 0; i <= r; i += 2) {
    while (i < r && a[j] <= b[i+1]) {
      b[r] = a[last];
      r -= 2;
      --last;
    }
    if (i <= r) {
      b[i] = a[j++];
    }
  }
  int ans = 0;
  for (int i = 1; i + 1 < n; ++i)
    ans += b[i-1] > b[i] && b[i] < b[i+1];
  printf("%d\n", ans);
  for (int i = 0; i < n; ++i)
    printf("%d%c", b[i], i + 1 == n ? '\n' : ' ');
}

int main() {
  int tc = 1;
  // scanf("%d", &tc);
  while (tc--) {
    solve();
  }
  return 0;
}
