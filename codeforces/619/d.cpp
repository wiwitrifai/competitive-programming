#include <bits/stdc++.h>

using namespace std;

int main() {
  int n, m, k;
  scanf("%d %d %d", &n, &m, &k);
  int tot = 4 * n * m - 2 * n - 2 * m;
  if (k > tot) {
    puts("NO");
    return 0;
  }
  vector<pair<int, string>> moves;
  if (m == 1) {
    moves.emplace_back(n-1, "D");
    moves.emplace_back(n-1, "U");
  }
  else {
    moves.emplace_back(m-1, "R");
    moves.emplace_back(m-1, "L");
    for (int i = 0; i + 1 < n; ++i) {
      moves.emplace_back(m-1, "DRU");
      moves.emplace_back(1, "D");
      moves.emplace_back(m-1, "L");
    }
    moves.emplace_back(n-1, "U");
  }
  vector<pair<int, string>> ans;
  for (auto it : moves) {
    if (k == 0)
      break;
    int len = it.second.size();
    int c = min(k / len, it.first);
    int sisa = it.first - c;
    k -= len * c;
    if (c > 0)
      ans.emplace_back(c, it.second);
    if (sisa > 0 && k > 0) {
      int r = min(k, (int)it.second.size());
      ans.emplace_back(1, it.second.substr(0, r));
      k -= r;
    }
  }
  puts("YES");
  printf("%d\n", (int)ans.size());
  for (auto it : ans) {
    printf("%d %s\n", it.first, it.second.c_str());
  }
  return 0;
}
