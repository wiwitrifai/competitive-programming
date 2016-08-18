#include <bits/stdc++.h>

using namespace std;

const int N = 1e6 + 6;

int main() {
  int n, m, ans;
  ans = 0;
  scanf("%d%d", &n, &m);
  for(int i = 0; i<n; i++) {
    int now, x;
    scanf("%d", &now);
    for(int j = 1; j<m; j++) {
      scanf("%d", &x);
      now = min(now, x);
    }
    ans = max(now, ans);
  }
  cout << ans << "\n";

  return 0;
}