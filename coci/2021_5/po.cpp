#include <bits/stdc++.h>

using namespace std;

int main() {
  int n;
  scanf("%d", &n);
  vector<int> a(n, 0);
  for (int i = 0; i < n; ++i) {
    scanf("%d", &a[i]);
  }
  int ans = 0;
  vector<int> b(1, 0);
  for (int i = 0; i < n; ++i) {
    while (!b.empty() && b.back() > a[i]) {
      ++ans;
      b.pop_back();
    }
    if (b.empty() || b.back() != a[i]) {
      b.push_back(a[i]);
    }
  }
  ans += b.size() - 1;
  printf("%d\n", ans);
  return 0;
}
