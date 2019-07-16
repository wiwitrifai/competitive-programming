#include <bits/stdc++.h>

using namespace std;

const int N = 1e6 + 5;

char s[N];
int id[N];

vector<pair<int, int>> pos[N];
int cnt[N];

int main() {
  int n;
  scanf("%d", &n);
  for (int i = 0; i < n; ++i) {
    scanf(" %c%d", s+i, id+i);
    pos[id[i]].emplace_back(i, s[i] == 's' ? +1 : -1);
  }
  for (int d = 1; d < N; ++d) {
    if (pos[d].empty()) continue;
    vector<int> val;
    int tot = 0;
    for (auto it : pos[d])
      tot += it.second;
    if (tot != 0) continue;
    int sum = 0;
    deque<int> dq;
    int sz = pos[d].size();
    for (int i = 0; i < 2 * sz-1; ++i) {
      while (!dq.empty() && dq.front() <= i - sz) dq.pop_front();
      sum += pos[d][i % sz].second;
      val.push_back(sum);
      while (!dq.empty() && val[dq.back()] >= sum) dq.pop_back();
      dq.push_back(i);
      if (i < sz-1) continue;
      int offs = i-sz >= 0 ? val[i-sz] : 0;
      if (val[dq.front()] - offs >= 0) {
        int l = pos[d][i % sz].first, r = pos[d][(i+1) % sz].first;
        assert(l != r);
        if (l < r)
          ++cnt[r], --cnt[l];
        else {
          ++cnt[r];
          ++cnt[n-1];
          --cnt[l];
        }
      }
    }
  }
  int ans = n-1;
  for (int i = n-2; i >= 0; --i) {
    cnt[i] += cnt[i+1];
    if (cnt[ans] <= cnt[i])
      ans = i;
  }
  printf("%d %d\n", ans+1, cnt[ans]);
  return 0;
}