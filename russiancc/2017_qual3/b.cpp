#include <bits/stdc++.h>

using namespace std;

const int N = 1e5 + 5;
pair<long long, long long> hr[N];
long long h, a;
bool cmp(pair<long long, long long> le, pair<long long, long long> ri) {
  return le.second * ((le.first + a - 1)/a) > ri.second * ((ri.first + a - 1)/a);
}
long long win[N];

int main() {
  int t;
  scanf("%d", &t);
  while (t--) {
    int n;
    scanf("%d %lld %lld", &n, &h, &a);
    for (int i = 0; i < n; ++i) {
      scanf("%lld %lld", &hr[i].first, &hr[i].second);
    }
    sort(hr, hr+n, cmp);
    long long now = 0;
    for (int i = n-1; i >= 0; i--) {
      int rec = (hr[i].first + a - 1)/a - 1;
      now = max(now, hr[i].second * rec);
      win[i] = now;
    }
    int ans = 0;
    for (int i = 0; i < n; i++) {
      if (h <= win[i]) break;
      long long rec = (hr[i].first + a - 1)/a;
      long long aa = hr[i].second;
      long long w = (h + aa - 1) / aa;
      if (w <= rec)
        break;
      h -= aa * rec;
      ans++;
    }
    if (ans >= n)
      ans = -1;
    printf("%d\n", ans);
  }
  return 0;
}