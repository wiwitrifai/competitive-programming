#include <bits/stdc++.h>

using namespace std;

int main() {
  int n;
  scanf("%d", &n);
  vector<long long> a(n);
  vector<int> val(n, 0);
  vector<vector<int>> deg(n);
  for (int i = 0; i < n; ++i) {
    scanf("%lld", &a[i]);
    deg[i].assign(3, 0);
  }
  for (int i = 0; i < n; ++i) {
    for (int j = i+1; j < n; ++j) {
      if (a[j] % a[i]) continue;
      val[j] = max(val[j], val[i]+1);
      assert(val[j] < 64);
    }
  }
  for (int i = 0; i < n; ++i) {
    int now = val[i];
    for (int j = 0; j < 3; ++j) {
      deg[i][j] = now % 4;
      now /= 4;
    }
  }
  vector<vector<int>> g(n, vector<int>(n, -1));
  for (int i = 1; i < n; ++i) {
    for (int j = 0; j < i; ++j) {
      int ans = -1;
      if (a[i] % a[j])
        ans = 1;
      else {
        for (int k = 0; k < 3; ++k) {
          if (deg[j][k] < deg[i][k]) {
            ans = k;
          }
        }
        assert(ans != -1);
        ++ans;
      }
      printf("%d%c", ans, j+1 == i ? '\n' : ' ');
    }
  }
  return 0;
}
