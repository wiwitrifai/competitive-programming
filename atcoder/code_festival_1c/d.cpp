#include <bits/stdc++.h>

using namespace std;

const int N = 1e6 + 5, inf = 1e8;

char s[N];

map<int, int> dp;

int main() {
  scanf("%s", s);
  int n = strlen(s);
  int now = 0, ans;
  for (int i = 0; i < n; i++) {
    int c = s[i] -'a';
    now ^= 1 << c;
    ans = inf;
    if (__builtin_popcount(now) <= 1)
      ans = 1;
    for (int j = 0; j < 26; j++) {
      int b = now ^ (1 << j);
      auto bef = dp.find(b);
      if (bef != dp.end()) {
        ans = min(ans, bef->second + 1);
      }
    }
    auto it = dp.find(now);
    if (it != dp.end())
      ans = min(ans, it->second+1);
    int cur = ans;
    if (it != dp.end())
      cur = min(cur, it->second);
    if (cur < inf)
      dp[now] = cur;
  }
  printf("%d\n", ans);
  return 0;
}