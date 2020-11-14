#include <bits/stdc++.h>

using namespace std;

void solve() {
  int n;
  scanf("%d", &n);
  vector<int> a(n);
  vector<long long> sum(n+1, 0);
  for (int i = 0; i < n; ++i) {
    scanf("%d", &a[i]);
    sum[i+1] = sum[i] + a[i];
  }
  set<pair<long long, int>> st;
  int ans = 0;
  vector<pair<int, int>> events;
  for (int i = 2; i < n; ++i) {
    if (sum[i] < a[i]) continue;
    int low = 0, hig = i-2;
    while (low < hig) {
      int mid = (low + hig + 1) >> 1;
      if ((sum[i] - sum[mid]) >= a[i]) {
        low = mid;
      } else {
        hig = mid - 1;
      }
    }
    events.emplace_back(low, i);
  }
  sort(events.begin(), events.end());
  int from = 0;
  for (auto & e : events) {
    while (from <= e.first) {
      st.insert(make_pair(sum[from+1] + a[from], from));
      ++from;
    }
    int id = e.second;
    for (auto it = st.lower_bound(make_pair(sum[id] - a[id], -1)); it != st.end(); ++it) {
      int l = it->second;
      if ((a[id]^a[l]) == (sum[id] - sum[l+1])) {
        ++ans;
      }
    }
  }
  printf("%d\n", ans);
}

int main() {
  int tc = 1;
  // scanf("%d", &tc);
  while (tc--) {
    solve();
  }
  return 0;
}
