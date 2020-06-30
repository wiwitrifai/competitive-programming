#include <bits/stdc++.h>

using namespace std;

void solve() {
  int n;
  scanf("%d", &n);
  vector<int> a(n), b(n);
  for (int i = 0; i < n; ++i) {
    scanf("%d", &a[i]);
  }
  for (int i = 0; i < n; ++i) {
    scanf("%d", &b[i]);
  }
  auto calc = [&] (int x) {
    for (int i = 0; i < n-1; ++i) {
      int rem = max(a[i] - x, 0);
      x = b[i] - rem;
      if (x < 0)
        return -1;
    }
    return x;
  };
  int low = 0, hi = b[n-1];
  while (low < hi) {
    int mid = (low + hi) >> 1;
    int res = calc(mid);
    if (res < 0)
      low = mid + 1;
    else
      hi = mid;
  }
  int x = calc(low);
  puts((x < 0 || x + (b[n-1] - low) < a[n-1]) ? "NO" : "YES");
}

int main() {
  int t;
  scanf("%d", &t);
  while (t--) {
    solve();
  }
  return 0;
}
