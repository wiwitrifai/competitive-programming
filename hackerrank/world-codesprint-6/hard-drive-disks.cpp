#include <bits/stdc++.h>

using namespace std;

const int N = 1e6 + 5;
const long long inf = 1e17;

long long dp[N];
pair<int, int> hd[N];
long long ad[N], ac[N], ae[N];

int main() {
  int n, k;
  scanf("%d %d", &n, &k);
  k--;
  vector< long long > p;
  long long ans = 0;
  for (int i = 0; i < n; i++) {
    int a, b;
    scanf("%d %d", &a, &b);
    if (a > b)
      swap(a, b);
    hd[i] = {a, b};
    ans += b-a;
    p.push_back(a);
    p.push_back(b);
  }
  sort(p.begin(), p.end());
  p.erase(unique(p.begin(), p.end()), p.end());
  for (int i = 0; i < n; i++) {
    hd[i].first = lower_bound(p.begin(), p.end(), hd[i].first) - p.begin();
    hd[i].second = lower_bound(p.begin(), p.end(), hd[i].second) - p.begin();
  }
  sort(hd, hd + n);
  for (int i = 0; i <= k; i++)
    dp[i] = 0;
  int id = 0;
  long long sum = 0, mul = 0;
  for (int i = 1; i < p.size(); i++) {
    // cerr << i << " " << p[i] << endl;
    while (id < n && hd[id].first < i) {
      ae[hd[id].second]++;
      id++;
    }
    mul += ae[i];
    sum += mul * (p[i] - p[i-1]);
    dp[i * (k+1)] = sum;
    // cerr << sum ;
    for (int h = 0; h < k; h++) {
      // cerr << " h " << h << endl;
      long long &dpnow = dp[i * (k + 1) + h + 1];
      dpnow = inf;
      long long now = 0, add = 0;
      int d = id-1;
      for (int j = i-1; j >= 0; j--) {
        while (d >= 0 && hd[d].first > j) {
          if (d >= 0 && hd[d].second < i) {
            long long ma = p[hd[d].first] - p[i] + p[hd[d].second];
            int it = upper_bound(p.begin(), p.end(),  ma) - p.begin() - 1;
            if (it >= 0) {
              ad[it]--;
              ac[it] += p[it] - ma;
            }
            add++;
          }
          d--;
        }
        now += add  * (p[j+1] - p[j]) + ac[j];
        add += ad[j];
        // cerr << i << " " << j << " " << h << " " << now << endl;
        dpnow = min(dpnow, dp[j * (k+1) + h] + now);
      }
      for (int j = 0; j <= id; j++)
        ad[j] = ac[j] = 0;
      // cerr << " " << dpnow ;
    }
    // cerr << endl;
  }
  long long add = inf, cnt = 0, now = 0;
  id = n-1;
  for (int i = (int) p.size() - 1; i > 0; i--) {
    while (id >= 0 && i < hd[id].first) {
      id--;
      cnt++;
    }
    if (i < p.size())
      now += cnt * (p[i+1] - p[i]);
    for (int j = 0; j <= k; j++)
      add = min(add, dp[i * (k+1) + j] + now);
    // cerr << i << " " << add << endl;
  }
  // cerr << ans << " " << 2 * add << endl;
  printf("%lld\n", ans + add * 2);
  return 0;
}