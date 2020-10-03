#include <bits/stdc++.h>

using namespace std;

int main() {
  int n;
  scanf("%d", &n);
  vector<int> a(n);
  for (int i = 0; i < n; ++i)
    scanf("%d", &a[i]);
  int ans = 0;
  for (int i = 30; i >= 0; --i) {
    int cur = ans | (1 << i);
    int cnt = 0;
    for (int j = 0; j < n; ++j) {
      cnt += (cur & a[j]) == cur;
    }
    if (cnt >= 2)
      ans = cur;
  }
  printf("%d\n", ans);
  return 0;
}
