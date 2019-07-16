#include <bits/stdc++.h>

using namespace std;

const int N = 1e5 + 5;

vector<int> g[N];
int p[N], lv[N], a[N], s[N];

int main() {
  int n;
  scanf("%d", &n);
  for (int i = 1; i < n; ++i) {
    scanf("%d", p+i);
    --p[i];
    g[p[i]].push_back(i);
  }
  for (int i = 0; i < n; ++i) {
    scanf("%d", s+i);
  }
  for (int i = n-1; i > 0; --i) {
    if (s[i] >= 0) continue;
    if (g[i].size() > 0)
      s[i] = s[g[i][0]];
    else
      s[i] = s[p[i]];
    for (int u : g[i])
      s[i] = min(s[i], s[u]);
  }
  a[0] = s[0];
  long long ans = a[0];
  for (int i = 1; i < n; ++i) {
    a[i] = s[i] - s[p[i]];
    if (a[i] < 0) {
      puts("-1");
      return 0;
    }
    ans += a[i];
  }
  printf("%lld\n", ans);
  return 0;
}