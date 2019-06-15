#include <bits/stdc++.h>

using namespace std;

const int N = 55;

int x[N], y[N];

int main() {
  int n;
  scanf("%d", &n);
  map<pair<int, int>, int> cnt;
  for (int i = 0; i < n; ++i) {
    scanf("%d %d", x+i, y+i);
  }
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < n; ++j) {
      if (i == j) continue;
      ++cnt[make_pair(x[i]-x[j], y[i]-y[j])];
    }
  }
  int ans = n;
  for (auto it : cnt) {
    ans = min(ans, n - it.second);
  }
  printf("%d\n", ans);
  return 0;
}
