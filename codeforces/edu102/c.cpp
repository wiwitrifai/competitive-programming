#include <bits/stdc++.h>

using namespace std;

void solve() {
  int n, k;
  scanf("%d %d", &n, &k);
  vector<int> a(k);
  iota(a.begin(), a.end(), 1);
  int d = n - k;
  int offset = k - (d+1);
  reverse(a.begin() + offset, a.end());
  for (int i = 0; i < k; ++i)
    printf("%d%c", a[i], i+1 == k ? '\n' : ' ');
}

int main() {
  int tc;
  scanf("%d", &tc);
  while (tc--) {
    solve();
  }
  return 0;
}
