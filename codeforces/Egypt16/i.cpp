#include <bits/stdc++.h>

using namespace std;

const double eps = 1e-12;

int main() {
  freopen("walk.in", "r", stdin);
  int t;
  scanf("%d", &t);
  while (t--) {
    int n;
    int m;
    scanf("%d %d", &n, &m);
    vector< pair<double, int > > ev;
    for (int i = 0; i < n; i++) {
      int x, y, r;
      scanf("%d %d %d", &x, &y, &r);
      if (y < 0)
        y = -y;
      if (y + r > m)
        continue;
      double lo = sqrt(1LL * (m-r) * (m-r) - 1LL * y * y);
      ev.push_back({x-lo-eps, r});
      ev.push_back({x+lo+eps, -r});
    }
    sort(ev.begin(), ev.end());
    long long ans = 0, sum = 0;
    for (int i = 0; i < ev.size(); i++) {
      sum += ev[i].second;
      ans = max(ans, sum);
    }
    printf("%lld\n", ans);
  }
  return 0;
}