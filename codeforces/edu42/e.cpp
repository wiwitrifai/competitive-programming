#include <bits/stdc++.h>

using namespace std;

const int N = 1e6 + 5;

long long x[N];
char c[N];

int main() {
  int n;
  scanf("%d", &n);
  vector<int> v[2];
  int last = -1;
  long long ans = 0;
  for (int i = 0; i < n; ++i) {
    scanf("%lld %c", x+i, c+i);
    if (c[i] == 'P') {
      if (last == -1) {
        for (int j = 0; j < 2; ++j)
          if (v[j].size() > 0)
            ans += x[i] - x[v[j][0]];
      }
      else {
        long long cur = x[i] - x[last];
        for (int j = 0; j < 2; ++j) {
          if (v[j].empty()) continue;
          long long longest = max(x[v[j][0]] - x[last], x[i] - x[v[j].back()]);
          for (int k = 0; k+1 < v[j].size(); ++k)
            longest = max(longest, x[v[j][k+1]] - x[v[j][k]]);
          cur += x[i] - x[last] - longest;
        }
        ans += min(cur, 2LL * (x[i] - x[last]));
      }
      last = i;
      for (int j = 0; j < 2; ++j)
        v[j].clear();
    }
    else if (c[i] == 'R'){
      v[0].push_back(i);
    }
    else {
      v[1].push_back(i);
    }
  }
  for (int j = 0; j < 2; ++j) {
    if (v[j].empty()) continue;
    if (last == -1)
      ans += x[v[j].back()] - x[v[j][0]];
    else
      ans += x[v[j].back()] - x[last];
  }
  printf("%lld\n", ans);
  return 0;
}