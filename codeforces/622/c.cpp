#include <bits/stdc++.h>

using namespace std;

int n;
vector<int> m, ans;
vector<long long> cnt;

int main() {
  scanf("%d", &n);
  m.resize(n);
  for (int i = 0; i < n; ++i) {
    scanf("%d", &m[i]);
  }
  vector<pair<int, int>> inc;
  cnt.assign(n, 0);
  ans.assign(n, 0);
  inc.emplace_back(0, -1);
  long long sum = 0;
  for (int i = 0; i < n; ++i) {
    while (!inc.empty() && inc.back().first >= m[i]) {
      int last = inc.back().first, from = inc.back().second;
      inc.pop_back();
      sum -= 1LL * last * (from - inc.back().second);
    }
    sum += 1LL * m[i] * (i - inc.back().second);
    inc.emplace_back(m[i], i);
    cnt[i] = sum;
  }
  inc.clear();
  inc.emplace_back(0, n);
  sum = 0;
  for (int i = n-1; i >= 0; --i) {
    while (!inc.empty() && inc.back().first >= m[i]) {
      int last = inc.back().first, from = inc.back().second;
      inc.pop_back();
      sum -= 1LL * last * (inc.back().second - from);
    }
    sum += 1LL * m[i] * (inc.back().second - i);
    inc.emplace_back(m[i], i);
    cnt[i] += sum;
  }
  long long best = 0;
  int mid = 0;
  for (int i = 0; i < n; ++i) {
    long long now = cnt[i] - m[i];
    if (best < now) {
      best = now;
      mid = i;
    }
  }
  ans[mid] = m[mid];
  for (int i = mid-1; i >= 0; --i) {
    ans[i] = min(ans[i+1], m[i]);
  }
  for (int i = mid+1; i < n; ++i) {
    ans[i] = min(ans[i-1], m[i]);
  }
  for (int i = 0; i < n; ++i) {
    printf("%d%c", ans[i], i+1 == n ? '\n' : ' ');
  }
  return 0;
}
