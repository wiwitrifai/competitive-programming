#include <bits/stdc++.h>

using namespace std;

int main() {
  int t;
  scanf("%d", &t);
  while (t--) {
    int n, k;
    scanf("%d %d", &n, &k);
    vector<long long> cnt;
    for (int i = 0; i < n; ++i) {
      long long x;
      scanf("%lld", &x);
      int id = 0;
      while (x > 0) {
        while ((int)cnt.size() <= id)
          cnt.push_back(0);
        cnt[id] += x % k;
        x /= k;
        ++id;
      }
    }
    bool ok = 1;
    for (auto x : cnt) {
      ok &= x <= 1;
    }
    puts(ok ? "YES" : "NO");
  }
  return 0;
}
