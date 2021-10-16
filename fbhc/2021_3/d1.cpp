#include <bits/stdc++.h>

using namespace std;

struct Dsu {
  vector<int> p, flag;
  Dsu(int _n) : p(_n, -1), flag(_n, 0) {
  }
  int find(int x) { return p[x] < 0 ? x : p[x] = find(p[x]); }

  bool merge(int u, int v) {
    u = find(u);
    v = find(v);
    if (u == v)
      return false;
    if (-p[u] > -p[v])
      swap(u, v);
    flag[v] |= flag[u];
    p[v] += p[u];
    p[u] = v;
    return true;
  }
};

vector<int> dr = {-1, 0, 1, 0};
vector<int> dc = {0, -1, 0, 1};

void solve() {
  int n, m;
  cin >> n >> m;
  auto enc = [&](int r, int c) {
    return r * m + c;
  };
  auto dec = [&](int x) {
    int r = x / m, c = x - r * m;
    return make_pair(r, c);
  };
  vector<vector<int>> h(n, vector<int>(m));
  vector<vector<int>> s(n, vector<int>(m));
  vector<int> all;
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < m; ++j) {
      cin >> h[i][j];
      all.push_back(h[i][j]);
    }
  }
  vector<pair<int, int>> ids;
  vector<pair<int, int>> cand;
  int cnt = 0;
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < m; ++j) {
      cin >> s[i][j];
      all.push_back(s[i][j]);
      if (h[i][j] > s[i][j]) {
        ++cnt;
        cand.emplace_back(i, j);
      }
      ids.emplace_back(i, j);
    }
  }
  sort(all.begin(), all.end());
  all.erase(unique(all.begin(), all.end()), all.end());
  sort(ids.begin(), ids.end(), [&](pair<int, int>& le, pair<int, int>& ri) {
    return h[le.first][le.second] > h[ri.first][ri.second];
  });
  sort(cand.begin(), cand.end(), [&](pair<int, int>& le, pair<int, int>& ri) {
    return s[le.first][le.second] > s[ri.first][ri.second];
  });
  int tot = n * m;
  Dsu dsu(tot);
  int robot = 0;
  auto it1 = ids.begin();
  auto it2 = cand.begin();
  reverse(all.begin(), all.end());
  for (auto e : all) {
    while (it2 != cand.end() && s[it2->first][it2->second] == e) {
      int r, c;
      tie(r, c) = *it2;
      int now = enc(r, c);
      now = dsu.find(now);
      robot += !dsu.flag[now];
      dsu.flag[now] = 1;
      ++it2;
    }
    while (it1 != ids.end() && h[it1->first][it1->second] == e) {
      int r, c;
      tie(r, c) = *it1;
      int now = enc(r, c);
      for (int k = 0; k < 4; ++k) {
        int rx = r + dr[k], cx = c + dc[k];
        if (rx < 0 || rx >= n || cx < 0 || cx >= m) continue;
        if (h[rx][cx] < e) continue;
        dsu.merge(now, enc(rx, cx));
      }
      ++it1;
    }
  }
  cout << cnt << " " << robot << endl;
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
