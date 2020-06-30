#include <bits/stdc++.h>

using namespace std;

int main() {
  int t;
  scanf("%d", &t);
  while (t--) {
    int n;
    scanf("%d", &n);
    vector<int> a(2 * n);
    vector<int> id[2];
    for (int i = 0; i < 2 * n; ++i) {
      scanf("%d", &a[i]);
      id[a[i] & 1].push_back(i);
    }
    vector<pair<int, int>> ans;
    for (int i = 0; i < 2; ++i) {
      for (int j = 0; j + 1 < (int)id[i].size(); j += 2) {
        ans.emplace_back(id[i][j], id[i][j+1]);
      }
    }
    if ((int)ans.size() >= n)
      ans.resize(n-1);
    assert((int)ans.size() == n-1);
    for (auto it : ans) {
      printf("%d %d\n", it.first + 1, it.second + 1);
    }
  }
  return 0;
}
