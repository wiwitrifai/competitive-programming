#include <bits/stdc++.h>

using namespace std;

const int N = 1e5 + 5;

void solve() {
  int n;
  scanf("%d", &n);
  vector<int> w(n), deg(n, 0);
  long long ans = 0;
  for (int i = 0; i < n; ++i)
    scanf("%d", &w[i]), ans += w[i];
  for (int i = 0; i < n-1; ++i) {
    int u, v;
    scanf("%d %d", &u, &v);
    --u, --v;
    ++deg[u];
    ++deg[v];
  }
  vector<int> id(n);
  iota(id.begin(), id.end(), 0);
  sort(id.begin(), id.end(), [&](int l, int r) {
    return w[l] > w[r];
  });
  for (int i = 0, j = 0; i < n-1; ++i) {
    printf("%lld%c", ans, i == n-2 ? '\n' : ' ');
    if (i < n-2) {
      while (j < n && deg[id[j]] <= 1) ++j;
      ans += w[id[j]];
      --deg[id[j]];
    }
  }
}

int main() {
  int tc = 1;
  scanf("%d", &tc);
  while (tc--) {
    solve();
  }
  return 0;
}
