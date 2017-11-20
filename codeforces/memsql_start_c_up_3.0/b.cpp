#include <bits/stdc++.h>

using namespace std;

const int N = 1e5 + 5;

int n, s, a[N], b[N], c[N];

int main() {
  scanf("%d %d", &n, &s);
  long long ans = 0, tot = 0;
  vector<pair<long long, long long > > ch;
  for (int i = 0; i < n; i++) {
    scanf("%d %d %d", c+i, a+i, b+i);
    tot += c[i];
    ans += 1LL * c[i] * a[i];
    ch.emplace_back(b[i]-a[i], c[i]);
  }
  long long le = 0, ri = ((tot + s - 1)/ s);
  ri *= s;
  ri -= tot;
  long long cur = ans;
  sort(ch.begin(), ch.end());
  while (ch.size() > 0) {
    long long rem = max(ch.back().second/s, 1LL) * s;
    ri -= rem;
    le += rem;
    while (le > 0 && ch.size() > 0 && ch.back().first > 0) {
      long long mi = min(le, (long long)ch.back().second);
      cur += 1LL * mi * ch.back().first;
      le -= mi;
      ri += mi;
      ch.back().second -= mi;
      if (ch.back().second == 0) ch.pop_back();
    }
    while (ri < 0 && ch.size() > 0) {
      long long mi = min(-ri, (long long)ch.back().second);
      cur += 1LL * mi * ch.back().first;
      le -= mi;
      ri += mi;
      ch.back().second -= mi;
      if (ch.back().second == 0) ch.pop_back();
    }
    if (le >= 0 && ri >= 0)
      ans = max(ans, cur);
  }
  cout << ans << endl;
  return 0;
}