#include <bits/stdc++.h>

using namespace std;

int main() {
  int n;
  scanf("%d", &n);
  vector<int> a(n), bef(n);
  vector<vector<int>> pos(n, vector<int>());
  for (int i = 0; i < n; ++i) {
    scanf("%d", &a[i]);
    --a[i];
    if (pos[a[i]].empty())
      bef[i] = -1;
    else
      bef[i] = pos[a[i]].back();
    pos[a[i]].push_back(i);
  }
  vector<int> full(n, 0), partial(n, 0);
  for (int i = 0; i < n; ++i) {
    int now = a[i];
    int lef = pos[now][0], sz = pos[now].size(), rig = pos[now].back(), pre = bef[i];
    if (i) {
      full[i] = full[i-1];
    }
    if (i == rig) {
      full[i] = max(full[i], (lef == 0 ? 0 : full[lef-1]) + sz);
    }
    partial[i] = max(partial[i], (i ? full[i-1] : 0) + 1);
    if (pre != -1)
      partial[i] = max(partial[i], partial[pre] + 1);
  }
  int ans = max(*max_element(full.begin(), full.end()), *max_element(partial.begin(), partial.end()));
  printf("%d\n", n - ans);
  return 0;
}
