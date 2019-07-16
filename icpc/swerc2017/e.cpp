#include <bits/stdc++.h>

using namespace std;

const int N = 3e4 + 5, inf = 1e9;

vector<tuple<int, int, int> > g[N];
pair<int, int> d[N];
int din[N];
char s[N];

int dp[2][N];

int main() {
  int b, n;
  scanf("%d %d", &b, &n);
  map<string, int> mp;
  int nodes = 0;
  for (int i = 0; i < n; ++i) {
    scanf("%s", s);
    int u, v;
    auto it = mp.find(s);
    if (it == mp.end())
      mp[s] = u = nodes++;
    else
      u = it->second;
    scanf("%s", s);
    it = mp.find(s);
    if (it == mp.end())
      mp[s] = v = nodes++;
    else
      v = it->second;
    int a, b;
    scanf("%*s %d %d", &a, &b);
    b *= -1;
    g[v].emplace_back(u, a, b);
    ++din[u];
  }
  priority_queue<tuple<int, int, int> > pq;
  for (int i = 0; i < nodes; ++i) {
    if (din[i] == 0)
      pq.push(make_tuple(0, 0, i)), d[i] = {0, 0};
    else
      d[i] = {inf, inf};
  }
  while (!pq.empty()) {
    int a, b, v;
    tie(a, b, v) = pq.top(); pq.pop();
    a = -a, b = -b;
    if (d[v] != make_pair(a, b)) continue;
    for (auto it : g[v]) {
      int u, ca, cb;
      tie(u, ca, cb) = it;
      int aa = a + ca, bb = b + cb;
      if (d[u] > make_pair(aa, bb)) {
        d[u] = make_pair(aa, bb);
        pq.emplace(-aa, -bb, u);
      }
    }
  }
  int c = 0;
  for (int i = 0; i <= b; ++i)
    dp[c][i] = 0;
  int bef = 1;
  for (int i = 0; i < nodes; ++i) {
    swap(c, bef);
    int cost = min(d[i].first, b + 1), pres = -d[i].second;
    for (int j = 0; j < cost; ++j) {
      dp[c][j] = dp[bef][j];
    }
    for (int j = cost; j <= b; ++j) {
      dp[c][j] = max(dp[bef][j], dp[bef][j-cost] + pres);
    }
  }
  pair<int, int> ans = {inf, inf};
  for (int i = 0; i <= b; ++i)
    ans = min(ans, make_pair(-dp[c][i], i));
  printf("%d\n%d\n", -ans.first, ans.second);
  return 0;
}
