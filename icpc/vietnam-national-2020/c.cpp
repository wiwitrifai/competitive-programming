#include <bits/stdc++.h>

using namespace std;

int main() {
  int n, k;
  scanf("%d %d", &n, &k);
  vector<pair<int, int>> best[2];
  for (int g = 1; g <= n; ++g) {
    vector<int> s;
    int now = n;
    while (now > 0) {
      s.emplace_back(min(g, now));
      now -= s.back();
    }
    int offset = 0;
    vector<pair<int, int>> ans[2];
    for (int x : s) {
      for (int i = 0; i+1 < x; ++i) {
        ans[0].emplace_back(offset+i, offset+i+1);
      }
      offset += x;
    }
    offset = 0;
    for (int i = 0; i + 1 < (int)s.size(); ++i) {
      for (int j = 0; j < min(s[i], s[i+1]); ++j) {
        ans[1].emplace_back(offset + j, offset + s[i] + j);
      }
      offset += s[i];
    }
    if (min(best[0].size(), best[1].size()) < min(ans[0].size(), ans[1].size())) {
      best[0] = ans[0];
      best[1] = ans[1];
    }
  }
  if (k > (int)min(best[0].size(), best[1].size())) {
    puts("NO");
    return 0;
  }
  puts("YES");
  for (int i = 0; i < 2; ++i) {
    best[i].resize(k);
    for (auto & e : best[i]) {
      printf("%d %d\n", e.first + 1, e.second + 1);
    }
  }
  return 0;
}
