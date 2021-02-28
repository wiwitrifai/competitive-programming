#include <bits/stdc++.h>

using namespace std;

int main() {
  int n;
  scanf("%d", &n);
  vector<pair<int, int>> cnt(n);
  for (int i = 0; i < n; ++i) {
    scanf("%d", &cnt[i].first);
  }
  int maxi = 0;
  for (int i = 0; i < n; ++i) {
    scanf("%d", &cnt[i].second);
    maxi = max(maxi, cnt[i].first + cnt[i].second);
  }
  sort(cnt.begin(), cnt.end());
  int add = 0;
  priority_queue<int> pq;
  for (int i = 0, last = 0; i < n || !pq.empty();) {
    if (pq.empty() || (i < n && cnt[i].first <= last)) {
      last = max(last, cnt[i].first);
      pq.push(-(maxi-cnt[i].second));
      ++i;
    } else {
      int earliest = -pq.top();
      pq.pop();
      if (last > earliest)
        add = max(add, last - earliest);
      ++last;
    }
  }
  long long ans = 1LL * n * (maxi + add);
  for (int i = 0; i < n; ++i) {
    ans -= cnt[i].first + cnt[i].second;
  }
  printf("%lld\n", ans);
  return 0;
}
