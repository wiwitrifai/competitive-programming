#include <bits/stdc++.h>

using namespace std;

const int N = 1e5 + 5;

long long val[N];
int a[N];
vector<pair<int, int> > range[N];

int main() {
  for (int i = 1; i < N; ++i) {
    for (int j = 1; j <= i; ++j) {
      int b = i / j;
      range[i].emplace_back(j, b);
      j = i / b;
    }
    range[i].emplace_back(i+1, 0);
  }
  int t;
  scanf("%d", &t);
  while (t--) {
    int n, k;
    scanf("%d %d", &n, &k);
    fill(val, val+n+1, 0);
    for (int i = 0; i < n; ++i) {
      scanf("%d", a+i);
      int now = a[i], len = i+1;
      for (int j = 0; j + 1 < range[now].size(); ++j) {
        int from = range[now][j].first, to = range[now][j+1].first-1;
        int b = range[now][j].second;
        to = min(to, len);
        val[i - to + 1] += b;
        val[i - from + 2] -= b;
        if (to == len) break;
      }
    }
    int ans = n+1;
    for (int i = 0; i < n; ++i) {
      if (val[i] <= k) {
        ans = i+1;
        break;
      }
      val[i+1] += val[i];
    }
    printf("%d\n", ans);
  }
  return 0;
}