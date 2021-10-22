#include <bits/stdc++.h>


using namespace std;

void solve() {
  int n;
  cin >> n;
  vector<int> b(n);
  for (int i = 0; i < n; ++i) {
    cin >> b[i];
  }
  vector<int> ids(n);
  iota(ids.begin(), ids.end(), 0);
  sort(ids.begin(), ids.end(), [&](int l, int r) {
    return b[l] < b[r];
  });
  int last = 0;
  vector<int> ans(n, 0);
  for (int i : ids) {
    ans[i] = last % b[i];
    if (last == ans[i])
      ++last;
  }
  for (int i = 0; i < n; ++i) {
    cout << ans[i] << (i+1 == n ? '\n' : ' ');
  }
}

int main() {
  int tc;
  cin >> tc;
  while (tc--) {
    solve();
  }
  return 0;
}
