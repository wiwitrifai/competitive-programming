#include <bits/stdc++.h>

using namespace std;

const int N = 1e5 + 5;

int last[N];
int bef[N], from[N];

int main() {
  int m, a, b;
  scanf("%d %d %d", &m, &a, &b);
  int n = max(a, b);
  priority_queue<int> pq;
  pq.push(0);
  memset(last, -1, sizeof last);
  while (!pq.empty()) {
    int v = pq.top();
    pq.pop();
    int r = v % b;
    // cerr << v << " " << r << endl;
    if (last[r] != -1) continue;
    queue<int> que;
    for (int x = r; x < n && x <= v; x += b) {
      if (last[x] != -1) continue;
      last[x] = v;
      que.push(x);
    }
    vector<int> nodes;
    while (!que.empty()) {
      int u = que.front(); que.pop();
      nodes.push_back(u);
      last[u] = v;
      int x = u + a;
      if (x < n && x <= v && last[x] == -1) {
        last[x] = v;
        que.push(x);
      }
      x -= b;
      if (u+a <= v && x >= 0 && x < n && last[x] == -1) {
        last[x] = v;
        que.push(x);
      }
      x = u - b;
      if (x >= 0 && x < n && last[x] == -1) {
        last[x] = v;
        que.push(x);
      }
    }
    for (int u : nodes) {
      if (u > v) continue;
      int d = (v - u) / a;
      while (d * a + u <= v) {
        ++d;
      }
      // cerr << u << " " << v << " to " << d * a + u << endl;
      pq.push(d * a + u);
    }
  }
  // cerr << " done " << endl;
  vector<pair<int, int> > events;
  for (int i = 0; i < n; ++i) {
    if (last[i] == -1) continue;
    events.emplace_back(last[i], i);
  }
  sort(events.begin(), events.end());
  fill(bef, bef+a, m+1);
  fill(from, from+n, m+1);
  long long ans = 0;
  // cerr << n << endl;
  for (auto it : events) {
    int r = it.second % a;
    // cerr << it.first << " " << it.second << " " << ans << endl;
    if (from[r] <= it.second) continue;
    int now = it.first, v = it.second;
    if (now > m) continue;
    int til = min(now+1, from[r]);
    int go = ((til - r) / a) * a + r;
    while (go < til) go += a;
    while (go >= til) go -= a;
    if (go >= v) {
      ans += 1LL * ((go - v) / a + 1) * (m+1 - now);
    }
    v = go + a;
    if (v < from[r]) {
      go = ((from[r] - r) / a) * a + r;
      while (go < from[r]) go += a;
      while (go >= from[r]) go -= a;
      if (v <= go) {
        // cerr << ans << endl;
        int cnt = (go - v) / a + 1;
        ans += 1LL * (m + 1) * cnt;
        long long sum = 1LL * (v + go) * cnt / 2;
        ans -= sum;
        // cerr << ans << endl;
      }
    }
    from[r] = it.second;
  }
  printf("%lld\n", ans);
  return 0;
}
