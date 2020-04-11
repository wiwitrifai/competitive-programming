#include <bits/stdc++.h>

using namespace std;

int main() {
  int t;
  scanf("%d", &t);
  while (t--) {
    int n, x;
    scanf("%d %d", &n, &x);
    vector<int> a(n);
    for (int i = 0; i < n; ++i) {
      scanf("%d", &a[i]);
    }
    sort(a.begin(), a.end());
    int ans = 0;
    long long sum = 0;
    for (int i = n-1; i >= 0; --i) {
      sum += a[i];
      if (sum < (n - i) * 1LL * x) {
        break;
      }
      ++ans;
    }
    printf("%d\n", ans);
  }
  return 0;
}
