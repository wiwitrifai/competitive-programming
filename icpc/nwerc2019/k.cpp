#include <bits/stdc++.h>

using namespace std;

const int N = 555;

int s, d, t, n;
int l[N], r[N];

int main() {
  scanf("%d %d %d %d", &s, &d, &t, &n);
  vector<long long> nodes;
  nodes.push_back(0);
  nodes.push_back(s);
  vector<int> cand;
  cand.push_back(0);
  for (int i = 0; i < n; ++i) {
    scanf("%d %d", l+i, r+i);
    nodes.push_back(l[i]);
    nodes.push_back(r[i]);
    cand.push_back(max(r[i] - d, 0));
    cand.push_back(l[i]);
    cand.push_back(r[i]);
  }
  cand.push_back(max(0, s-d));
  for (int pos : cand) {
    int last = n-1;
    while (last >= 0 && l[last] >= pos) --last;
    int j = last+1;
    if (last >= 0)
      pos = max(pos, r[last]);
    nodes.push_back(pos);
    while (last < n) {
      pos += d;
      while (j < n && r[j] <= pos) ++j;
      if (j < n && l[j] < pos && pos < r[j])
        break;
      nodes.push_back(min(pos, s));
      if (last == j) {
        pos += 1LL * d * (max(l[j] - pos, 0) / d);
        nodes.push_back(min(pos, s));
      }
      else
        last = j;
    }
  }
  for (int i = 0; i < n; ++i) {
    int pos = l[i] + d;
    if (pos > s) continue;
    bool ok = 1;
    for (int j = 0; j < n; ++j) {
      ok &= pos <= l[j] || pos >= r[j];
    }
    if (ok)
      nodes.push_back(pos);
  }
  sort(nodes.begin(), nodes.end());
  nodes.erase(unique(nodes.begin(), nodes.end()), nodes.end());
  vector<long long> dp(nodes.size(), 1e17);
  dp[0] = 0;
  deque<int> dq;
  for (int i = 0, j = -1; i < (int)nodes.size(); ++i) {
    while (!dq.empty() && nodes[dq.back()] < nodes[i] - d)
      dq.pop_back();
    if (!dq.empty())
      dp[i] = min(dp[i], dp[dq.back()] + t);
    while (j+1 < n && r[j+1] <= nodes[i]) ++j;
    for (int k = i-1; k >= 0; --k) {
      if (j >= 0 && nodes[k] < r[j]) break;
      long long len = nodes[i] - nodes[k], w = len / d;
      len -= 1LL * w * d;
      if (len > t)
        len = t;
      dp[i] = min(dp[i], dp[k] + 1LL * w * min(t, d) + len);
    }
    while (!dq.empty() && dp[dq.front()] >= dp[i])
      dq.pop_front();
    dq.push_front(i);
  }
  printf("%lld\n", dp.back());
  return 0;
}
