// O(N sqrt(N))

#include <bits/stdc++.h>

using namespace std;

void solve() {
  int n, m;
  cin >> n >> m;
  auto enc = [&](int r, int c) {
    return r * 3 + c;
  };
  vector<vector<int>> a(n, vector<int>(3));
  vector<int> b(n * 3);
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < 3; ++j) {
      cin >> a[i][j];
      b[enc(i, j)] = a[i][j];
    }
  }
  vector<int> from(m), to(m);
  vector<int> lim(m);
  for (int i = 0; i < m; ++i) {
    int r, c;
    cin >> r >> c;
    --r, --c;
    from[i] = enc(r, c);
    cin >> r >> c;
    --r, --c;
    to[i] = enc(r, c);
    cin >> lim[i];
  }
  vector<int> ids(m);
  vector<int> gids(n * 3);
  iota(ids.begin(), ids.end(), 0);
  iota(gids.begin(), gids.end(), 0);
  sort(ids.begin(), ids.end(), [&](int lef, int rig) {
    return lim[lef] < lim[rig];
  });
  sort(gids.begin(), gids.end(), [&](int lef, int rig) {
    return b[lef] < b[rig];
  });
  const int MAGIC = max(2 * (int)sqrt(n)+1, 2);
  vector<int> specials;
  vector<int> isspecials(n * 3, 0);
  for (int i = 0; i < n; i += MAGIC) {
    for (int j = 0; j < 3; ++j) {
      int v = enc(i, j);
      isspecials[v] = 1;
      specials.push_back(v);
    }
  }
  vector<int> dist(n * 3);
  vector<vector<int>> g(n * 3);
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < 3; ++j) {
      int now = enc(i, j);
      if (j + 1 < 3) {
        int nxt = enc(i, j+1);
        g[now].push_back(nxt);
        g[nxt].push_back(now);
      }
      if (i + 1 < n) {
        int nxt = enc(i+1, j);
        g[now].push_back(nxt);
        g[nxt].push_back(now);
      }
    }
  }
  const int inf = 1e9 + 7;
  vector<map<int, int>> gs(n * 3);
  auto bfs = [&](int v, int lower, int upper, int val) {
    fill(dist.begin() + lower, dist.begin() + upper + 1, inf);
    queue<int> que;
    que.push(v);
    dist[v] = 0;
    while (!que.empty()) {
      int u = que.front();
      if (isspecials[u]) {
        auto it = gs[v].find(u);
        if (it == gs[v].end())
          gs[v][u] = dist[u];
        else
          it->second = min(it->second, dist[u]);
      }
      que.pop();
      for (int z : g[u]) {
        if (z < lower || z > upper) continue;
        if (dist[z] != inf) continue;
        if (b[z] > val) continue;
        dist[z] = dist[u] + 1;
        que.push(z);
      }
    }
  };
  auto dijkstra = [&](int v, int t, int lower, int upper, int lower2, int upper2, int val) {
    // cerr << " dijkstra " << v << " " << t << " " << val << " lower " << lower << " " << upper << " upper " << lower2 << " " << upper2 << endl;
    for (int x : specials) {
      dist[x] = inf;
    }
    fill(dist.begin() + lower, dist.begin() + upper+1, inf);
    fill(dist.begin() + lower2, dist.begin() + upper2+1, inf);
    priority_queue<pair<int, int>> pq;
    pq.emplace(0, v);
    dist[v] = 0;
    auto check = [&](int x) {
      return (lower <= x && x <= upper) || (lower2 <= x && x <= upper2);
    };
    while (!pq.empty()) {
      int w, u;
      tie(w, u) = pq.top();
      pq.pop();
      w = -w;
      if (dist[u] != w) continue;
      // cerr << u << " : " << w << endl;
      if (u == t) {
        // cerr << " result : " << w << endl;
        return w;
      }
      for (int z : g[u]) {
        if (!check(z)) continue;
        if (b[z] > val) continue;
        if (dist[z] > w + 1) {
          dist[z] = w + 1;
          pq.emplace(-dist[z], z);
        }
      }
      if (isspecials[u]) {
        for (auto & e : gs[u]) {
          int z, x;
          tie(z, x) = e;
          if (b[z] > val) continue;
          if (dist[z] > w + x) {
            // cerr << u << " to " << z << " " << w << " + " << x << endl;
            dist[z] = w + x;
            pq.emplace(-dist[z], z);
          }
        }
      }
    }
    return inf;
  };
  auto find_bound = [&](int pos) {
    int r = pos / 3;
    int lower = r / MAGIC, upper = lower + 2;
    // cerr << lower << " " << upper << " " << n << endl;
    if (isspecials[pos]) {
      --lower;
    }
    lower *= 3 * MAGIC;
    upper *= 3 * MAGIC;
    lower = max(lower, 0);
    upper = min(upper, 3 * n - 1);
    // cerr << " bound " << pos << " " << lower << " " << upper << endl;
    return make_pair(lower, upper);
  };
  const int mod = 1e9 + 7;
  long long ans = 1;
  auto it = gids.begin();
  for (auto x : ids) {
    int val = lim[x];
    while (it != gids.end() && b[*it] <= val) {
      int pos = *it;
      auto [lower, upper] = find_bound(pos);
      auto it2 = lower_bound(specials.begin(), specials.end(), lower);
      while (it2 != specials.end() && *it2 <= upper) {
        bfs(*it2, lower, upper, val);
        ++it2;
      }
      ++it;
    }
    auto bound1 = find_bound(from[x]);
    auto bound2 = find_bound(to[x]);
    // cerr << x << endl;
    int res = dijkstra(from[x], to[x], bound1.first, bound1.second, bound2.first, bound2.second, val);
    if (res < inf) {
      ans = ans * res % mod;
    }
  }
  cout << ans << endl;
}

int main(int argc, char * argv[]) {
  clock_t starttime = clock();
  int seed = time(0);
  if (argc >= 2) {
    seed = atoi(argv[1]);
  }
  cerr << "random seed\t= " << seed << endl;
  srand(seed);

  int tt;
  scanf("%d", &tt);
  for (int tc = 1; tc <= tt; ++tc) {
    printf("Case #%d: ", tc);
    solve();
    fflush(stdout);
    cerr << "~ TC#" << tc << " done! execution time : " <<
      (double)(clock() - starttime) / CLOCKS_PER_SEC << " s " << endl;
  }
  return 0;
}
