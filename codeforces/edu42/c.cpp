#include <bits/stdc++.h>

using namespace std;

vector<int> d;

int main() {
  int n;
  scanf("%d", &n);
  while (n) {
    d.push_back(n % 10); n /= 10;
  }
  reverse(d.begin(), d.end());
  int m = d.size();
  int ans = m;
  int nmask = 1 << m;
  for (int i = 1; i < nmask; ++i) {
    bool ok = 1;
    vector<int> now;
    for (int j = 0; j < m; ++j)
      if (i & (1 << j))
        now.push_back(d[j]);
    if (now[0] == 0) continue;
    int val = 0;
    for (int x : now)
      val = val * 10 + x;
    int s = sqrt(val);
    s = max(s, 0);
    while (1LL * s * s > val) --s;
    while (1LL * s * s < val) ++s;
    if (1LL * s * s == val) {
      ans = min(ans, m - (int)now.size());
    }
  }
  if (ans >= m)
    ans = -1;
  printf("%d\n", ans);
  return 0;
}