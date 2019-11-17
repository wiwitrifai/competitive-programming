#include <bits/stdc++.h>

using namespace std;

const int N = 1e5 + 5;

int h[N];
long long y[N];

int main() {
  int n, k;
  scanf("%d %d", &n, &k);
  for (int i = 0; i <= n; ++i)
    scanf("%d", h+i);
  while (k--) {
    double g;
    scanf("%lf", &g);
    int ig = int(g * 10 + 0.5);
    for (int i = 0; i <= n; ++i)
      y[i] = h[i] - 1LL * ig * i;
    vector<pair<long long, int>> lef;
    lef.emplace_back(-y[0], 0);
    double ans = -1;
    for (int i = 1; i <= n; ++i) {
      int p = lower_bound(lef.begin(), lef.end(), make_pair(-y[i], -1)) - lef.begin();
      if (p < (int)lef.size()) {
        p = lef[p].second;
        if (p == 0) {
          ans = max(ans, (double)i);
        }
        else {
          long long now = h[i] - 1LL * ig * (i-p);
          long long up = abs(h[p] - now), down = abs(now - ig - h[p-1]);
          ans = max(ans, (i - p) + (double) up / (up + down));
        }
      }
      if (-lef.back().first > y[i])
        lef.emplace_back(-y[i], i);
    }
    vector<pair<long long, int>> rig;
    rig.emplace_back(y[n], n);
    for (int i = n-1; i >= 0; --i) {
      int p = lower_bound(rig.begin(), rig.end(), make_pair(y[i], -1)) - rig.begin();
      if (p < (int)rig.size()) {
        p = rig[p].second;
        if (p == n) {
          ans = max(ans, (double)(n-i));
        }
        else {
          long long now = h[i] + 1LL * ig * (p - i);
          long long up = abs(h[p] - now), down = abs(now + ig - h[p+1]);
          ans = max(ans, (p - i) + (double)up / (up + down));          
        }
      }
      if (rig.back().first < y[i])
        rig.emplace_back(y[i], i);
    }
    if (ans < 0) {
      puts("impossible");
      continue;
    }
    printf("%.9lf\n", ans);
  }
  return 0;
}
