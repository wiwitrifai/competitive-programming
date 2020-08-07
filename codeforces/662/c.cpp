#include <bits/stdc++.h>

using namespace std;

void solve() {
  int n;
  scanf("%d", &n);
  map<int, int> cnt;
  for (int i = 0; i < n; ++i) {
    int a;
    scanf("%d", &a);
    ++cnt[a];
  }
  int maxi = 0, mcnt = 0;
  for (auto it : cnt) {
    if (it.second > maxi) {
      maxi = it.second;
      mcnt = 1;
    } else if (it.second == maxi) {
      ++mcnt;
    }
  }
  int ans = mcnt - 1;
  int rest = n - maxi * mcnt;
  ans += rest / (maxi - 1);
  printf("%d\n", ans);
}

int main() {
  int tc = 1;
  scanf("%d", &tc);
  while (tc--) {
    solve();
  }
  return 0;
}
