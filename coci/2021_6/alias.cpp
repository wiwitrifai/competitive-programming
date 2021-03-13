#include <bits/stdc++.h>

using namespace std;

vector<vector<pair<int, int>>> g;

map<string, int> words;

int get_id(const string& s) {
  auto it = words.find(s);
  int ret = words.size();
  if (it == words.end()) {
    words[s] = ret;
  } else {
    ret = it->second;
  }
  return ret;
}

int main() {
  int n, m;
  cin >> n >> m;
  g.resize(n);
  for (int i = 0; i < m; ++i) {
    string x, y;
    int t;
    cin >> x >> y >> t;
    g[get_id(x)].emplace_back(get_id(y), t);
  }
  int q;
  cin >> q;
  vector<long long> dist;
  const long long inf = 1e18;
  while (q--) {
    string a, b;
    cin >> a >> b;
    int s = get_id(a), t = get_id(b);
    dist.assign(n, inf);
    dist[s] = 0;
    priority_queue<pair<long long, int>> pq;
    pq.emplace(0, s);
    while (!pq.empty()) {
      long long d;
      int v;
      tie(d, v) = pq.top();
      pq.pop();
      d = -d;
      if (dist[v] != d) continue;
      for (auto& e : g[v]) {
        int u = e.first;
        if (dist[u] > d + e.second) {
          dist[u] = d + e.second;
          pq.emplace(-dist[u], u);
        }
      }
    }
    if (dist[t] >= inf)
      puts("Roger");
    else
      printf("%lld\n", dist[t]);
  }
  return 0;
}
