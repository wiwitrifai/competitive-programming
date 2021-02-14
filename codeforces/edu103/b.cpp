#include <bits/stdc++.h>

using namespace std;

void solve() {
  int n, k;
  scanf("%d %d", &n, &k);
  vector<long long> p(n);
  for (int i = 0; i < n; ++i) {
    scanf("%lld", &p[i]);
  }
  long long low = 0, hig = 1e13;
  while (low < hig) {
    long long mid = (low + hig) >> 1;
    long long cur = mid + p[0];
    bool ok = true;
    for (int i = 1; i < n; ++i) {
      if (p[i] * 100LL > k * cur) {
        ok = false;
        break;
      }
      cur += p[i];
    }
    if (ok) {
      hig = mid;
    } else {
      low = mid + 1;
    }
  }
  printf("%lld\n", low);
}

int main() {
  int tc;
  scanf("%d", &tc);
  while (tc--) {
    solve();
  }
  return 0;
}
