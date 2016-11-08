#include <bits/stdc++.h>

using namespace std;

const int N = 105;
const double inf = 1e16;

int n, k[N], id[N];
long long l, u;
long long w[N], h[N], d[N];
double dp[N];

int main() {
  freopen("street.in", "r", stdin);
  int t;
  scanf("%d", &t);
  while (t--) {
    scanf("%d %lld %lld", &n, &l, &u);
    for (int i = 0; i< n; i++) {
      scanf("%lld %lld %lld %d", h+i, w+i, d+i, k+i);
      id[i] = i;
    }
    sort(id, id+n, [](int a, int b) {
      return d[a] < d[b];
    });
    double ans = inf;
    for (int a = 0; a < n; a++) {
      int i = id[a];
      dp[i] = d[i];
      for (int b = 0; b < a; b++) {
        int j = id[b];
        double add = inf;
        if (k[i] == k[j])
          add = d[i] - d[j] - h[j];
        else {
          if (w[i] + w[j] >= u)
            add = min(add, double(max(0LL, d[i] - d[j] - h[j])));
          if (d[j] + h[j] >= d[i])
            add = min(add, double(max(0LL, u - w[i] - w[j])));
          add = min(add, hypot(d[i] - d[j] - h[j], u - w[i] - w[j]));
        }
        dp[i] = min(dp[i], dp[j] + add);
      }
      ans = min(ans, dp[i] + max(l - d[i] - h[i], 0LL));
    }
    printf("%.6lf\n", ans);
  }
  return 0;
}