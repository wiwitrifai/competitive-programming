#include <bits/stdc++.h>

using namespace std;


void solve() {
  int n;
  scanf("%d", &n);
  vector<int> ans(n);
  int now = n;
  queue<pair<int, int>> que;
  que.emplace(0, n);
  while (!que.empty()) {
    pair<int, int> cur = que.front();
    que.pop();
    int mid = (cur.first + cur.second) / 2;
    ans[mid] = now--;
    if (cur.first < mid)
      que.emplace(cur.first, mid);
    if (mid+1 < cur.second)
      que.emplace(mid+1, cur.second);
  }
  for (int i = 0; i < n; ++i)
    printf("%d%c", ans[i], i+1 == n ? '\n' : ' ');
}

int main() {
  int tc = 1;
  scanf("%d", &tc);
  while (tc--) {
    solve();
  }
  return 0;
}
