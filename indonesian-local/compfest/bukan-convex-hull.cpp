#include <bits/stdc++.h>

using namespace std;

const int N = 1e5 + 5;

pair<int, int > p[N];
int ya[N], yb[N];

int main() {
  int t;
  scanf("%d", &t);
  while (t--) {
    int n;
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
      int x, y;
      scanf("%d %d", &x, &y);
      p[i] = {x, y};
    }
    sort(p, p+n);
    long long ans = 0;
    int big = 0;
    for (int i = 0; i < n; i++)
      if (p[big].second < p[i].second)
        big = i;
    int cur = p[0].second;
    for (int i = 0; i <= big; i++) {
      cur = max(p[i].second, cur);
      ya[i] = cur;
    }
    cur = p[n-1].second;
    for (int i = n-1; i > big; i--) {
      cur = max(p[i].second, cur);
      if (i)
        ya[i-1] = cur;
    }

    for (int i = 0; i < n; i++)
      if (p[big].second > p[i].second)
        big = i;
    cur = p[0].second;
    for (int i = 0; i <= big; i++) {
      cur = min(p[i].second, cur);
      yb[i] = cur;
    }
    cur = p[n-1].second;
    for (int i = n-1; i > big; i--) {
      cur = min(p[i].second, cur);
      if (i)
        yb[i-1] = cur;
    }
    for (int i = 0; i < n-1; i++) {
      ans += 1LL * (ya[i] - yb[i]) * (p[i+1].first - p[i].first);
    }
    printf("%lld\n", ans);
  }
  return 0;
}