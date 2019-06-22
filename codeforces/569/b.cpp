#include <bits/stdc++.h>

using namespace std;

int main() {
  int n, m;
  scanf("%d %d", &n, &m);
  vector<pair<int, int>> pairs;
  for (int i = 1; i <= n; ++i) {
    for (int j = 1; j <= m; ++j) {
      pairs.emplace_back(i, j);
    }
  }
  int l = 0, r = (int)pairs.size()-1;
  vector<pair<int, int> > ans;
  while (l <= r) {
    ans.push_back(pairs[l++]);
    if (l <= r) {
      ans.push_back(pairs[r--]);
    }
  }
  for (auto it : ans) {
    printf("%d %d\n", it.first, it.second);
  }
  return 0;
}
