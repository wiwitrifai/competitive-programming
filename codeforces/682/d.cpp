#include <bits/stdc++.h>

using namespace std;

void solve() {
  int n;
  scanf("%d", &n);
  vector<int> a(n);
  for (int i = 0; i < n; ++i) {
    scanf("%d", &a[i]);
  }
  vector<tuple<int, int, int>> ans;
  if ((n & 1) == 0) {
    int all = 0;
    for (int x : a)
      all ^= x;
    if (all != 0) {
      puts("NO");
      return;
    }
  }
  for (int i = 0; i + 2 < n; i += 2) {
    ans.emplace_back(i, i+1, i+2);
    a[i] = a[i+1] = a[i+2] = a[i] ^ a[i+1] ^ a[i+2];
  }
  for (int i = 0; i + 2 < n; i += 2) {
    if (a[i] == a[n-1]) continue;
    ans.emplace_back(i, i+1, n-1);
  }
  puts("YES");
  printf("%d\n", (int)ans.size());
  for (auto & it : ans) {
    int i, j, k;
    tie(i, j, k) = it;
    printf("%d %d %d\n", i+1, j+1, k+1);
  }
}

int main() {
  int tc = 1;
  // scanf("%d", &tc);
  while (tc--) {
    solve();
  }
  return 0;
}
