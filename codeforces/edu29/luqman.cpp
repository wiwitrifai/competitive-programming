#include <bits/stdc++.h>

using namespace std;

const int N = 55;

int a[N];

int main() {
  int n;
  scanf("%d", &n);
  for (int i = 0; i < 2 * n; i++) scanf("%d", a + i);
  int ans = 1e9;
  for (int i = 0; i < 2 * n; i++) {
    for (int j = i + 1; j < 2 * n; j++) {
      vector<int> p;
      for (int k = 0; k < 2 * n; k++) {
        if (i == k || j == k) continue;
        p.push_back(a[k]);
      }
      sort(p.begin(), p.end());
      int cur = 0;
      for (int k = 0; k < p.size(); k += 2) {
        cur += p[k + 1] - p[k];
      }
      ans = min(ans, cur);
    }
  }
  cout << ans << endl;
  return 0;
}