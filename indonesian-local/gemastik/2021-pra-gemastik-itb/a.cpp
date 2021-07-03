#include <bits/stdc++.h>


using namespace std;

int main() {
  int n;
  scanf("%d", &n);
  vector<int> a(n);
  for (int i = 0; i < n; ++i) {
    scanf("%d", &a[i]);
  }
  sort(a.begin(), a.end());
  if (n > 6) {
    for (int i = 0; i < 3; ++i) {
      a[3 + i] = a[n-1-i];
    }
    a.resize(6);
    n = 6;
  }
  long long smallest = 0, largest = 0;
  bool first = true;
  int nmask = 1 << n;
  for (int mask = 0; mask < nmask; ++mask) {
    if (__builtin_popcount(mask) != 3) continue;
    long long cur = 1;
    for (int i = 0; i < n; ++i) {
      if (mask & (1 << i)) {
        cur *= a[i];
      }
    }
    if (first) {
      smallest = largest = cur;
      first = false;
    } else {
      smallest = min(smallest, cur);
      largest = max(largest, cur);
    }
  }
  printf("%lld %lld\n", largest, smallest);
  return 0;
}
