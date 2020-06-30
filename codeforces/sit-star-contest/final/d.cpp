#include <bits/stdc++.h>

using namespace std;

int main() {
  int n, k;
  scanf("%d %d", &n, &k);
  vector<pair<int, int>> skis(n);
  for (int i = 0; i < n; ++i) {
    int s;
    scanf("%d", &s);
    skis[i] = {s, i+1};
  }
  sort(skis.begin(), skis.end());
  vector<pair<int, int>> ans;
  for (int i = 0; i+1 < n; ++i) {
    if (skis[i+1].first - skis[i].first <= k) {
      ans.emplace_back(skis[i].second, skis[i+1].second);
      ++i;
    }
  }
  printf("%d\n", (int)ans.size());
  for (auto it : ans) {
    if (it.first > it.second)
      swap(it.first, it.second);
    printf("%d %d\n", it.first, it.second);
  }
  return 0;
}
