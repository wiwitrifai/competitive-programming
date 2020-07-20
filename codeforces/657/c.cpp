#include <bits/stdc++.h>

using namespace std;

void solve() {
  int n, m;
  scanf("%d %d", &n, &m);
  vector<pair<int, int>> flower(m), rev(m);
  for (int i = 0; i < m; ++i) {
    int a, b;
    scanf("%d %d", &a, &b);
    flower[i] = {a, b};
  }
  sort(flower.begin(), flower.end());
  for (int i = 0; i < m; ++i) {
    rev[i] = {flower[i].second, i};
  }
  sort(rev.begin(), rev.end());
  reverse(rev.begin(), rev.end());
  long long ans = 0;
  if (n <= m) {
    for (int i = 0; i < n; ++i)
      ans += flower[m-1-i].first;
  } else {
    for (int i = 0; i < m; ++i)
      ans += flower[i].first;
    ans += 1LL * (n - m) * rev[0].first;
  }
  long long sum = 0;
  for (int i = 0, j = m-1; i < m; ++i) {
    int b = rev[i].first;
    while (j >= 0 && m-j < n && flower[j].first >= b) {
      sum += flower[j].first;
      --j;
    }
    int sisa = n - (m-1-j);
    long long cur = sum;
    if (j >= rev[i].second) {
      cur += flower[rev[i].second].first;
      --sisa;
    }
    cur += 1LL * sisa * b;
    ans = max(ans, cur);
  }
  printf("%lld\n", ans);
}

int main() {
  int tc = 1;
  scanf("%d", &tc);
  while (tc--) {
    solve();
  }
  return 0;
}
