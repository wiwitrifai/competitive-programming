#include <bits/stdc++.h>

using namespace std;

int main() {
  int n;
  scanf("%d", &n);
  vector<int> d(n);
  vector<pair<int, int>> ans, dv(n);
  for (int i = 0; i < n; ++i) {
    scanf("%d", &d[i]);
    dv[i] = {d[i], i};
  }
  sort(dv.begin(), dv.end());
  if (dv[0].first != 0 || (n > 1 && dv[1].first == 0)) {
    puts("NO");
    return 0;
  }
  for (int i = 1, par = 0, cnt = 0; i < n; ++i) {
    while (par < i && (dv[par].first < dv[i].first - 1 || cnt >= 2)) {
      ++par;
      cnt = 0;
    }
    if (par == i || dv[par].first != dv[i].first - 1) {
      puts("NO");
      return 0;
    }
    ans.emplace_back(dv[par].second, dv[i].second);
    ++cnt;
  }
  if ((int)ans.size() != n-1) {
    puts("NO");
    return 0;
  }
  puts("YES");
  for (auto e : ans) {
    printf("%d %d\n", e.first+1, e.second+1);
  }
  return 0;
}
