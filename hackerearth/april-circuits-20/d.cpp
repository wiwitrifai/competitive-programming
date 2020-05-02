#include <bits/stdc++.h>

using namespace std;

int main() {
  int n, m;
  scanf("%d %d", &n, &m);
  vector<int> a(n), b(m);
  for (int i = 0; i < n; ++i) {
    scanf("%d", &a[i]);
  }
  for (int i = 0; i < m; ++i) {
    scanf("%d", &b[i]);
  }
  sort(a.begin(), a.end());
  sort(b.begin(), b.end());
  int lo = 1, hi = n+1;
  while (lo < hi) {
    int mid = (lo + hi) >> 1;
    int ia = 0;
    for (int x : b) {
      int cnt = mid;
      while (ia < n && cnt > 0 && a[ia] <= x) {
        ++ia;
        --cnt;
      }
    }
    if (ia < n)
      lo = mid + 1;
    else
      hi = mid;
  }
  if (hi > n)
    hi = 0;
  printf("%d", hi * 2 - 1);
  return 0;
}