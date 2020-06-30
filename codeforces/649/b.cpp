#include <bits/stdc++.h>

using namespace std;

void solve() {
  int n;
  scanf("%d", &n);
  vector<int> a(n);
  for (int i = 0; i < n; ++i) {
    scanf("%d", &a[i]);
  }
  vector<int> ans(1, a[0]);
  for (int i = 1; i < n-1; ++i) {
    if (a[i-1] < a[i] && a[i] < a[i+1]) continue;
    if (a[i-1] > a[i] && a[i] > a[i+1]) continue;
    ans.emplace_back(a[i]);
  }
  ans.push_back(a[n-1]);
  printf("%d\n", (int)ans.size());
  for (int i = 0; i < (int)ans.size(); ++i) {
    printf("%d%c", ans[i], i+1 == (int)ans.size() ? '\n' : ' ');
  }
}

int main() {
  int t;
  scanf("%d", &t);
  while (t--) {
    solve();
  }
  return 0;
}
