#include <bits/stdc++.h>

using namespace std;

struct Dsu {
  vector<int> p;
  Dsu(int n) {
    p.assign(n, -1);
  }
  void reset() {
    fill(p.begin(), p.end(), -1);
  }
  int find(int x) {
    return p[x] < 0 ? x : p[x] = find(p[x]);
  }
  bool merge(int u, int v) {
    u = find(u);
    v = find(v);
    if (u == v)
      return false;
    if (-p[u] > -p[v])
      swap(u, v);
    p[v] += p[u];
    p[u] = v;
    return true;
  }
};

int main() {
  int n;
  scanf("%d", &n);
  vector<int> x(n), y(n);
  for (int i = 0; i < n; ++i) {
    scanf("%d %d", &x[i], &y[i]);
  }
  vector<int> dx = x, dy = y;
  sort(dx.begin(), dx.end());
  dx.erase(unique(dx.begin(), dx.end()), dx.end());
  sort(dy.begin(), dy.end());
  dy.erase(unique(dy.begin(), dy.end()), dy.end());
  vector<vector<int>> id(dx.size(), vector<int>(dy.size(), -1));
  for (int i = 0; i < n; ++i) {
    x[i] = lower_bound(dx.begin(), dx.end(), x[i]) - dx.begin();
    y[i] = lower_bound(dy.begin(), dy.end(), y[i]) - dy.begin();
    id[x[i]][y[i]] = i;
  }
  int sx = dx.size(), sy = dy.size();
  vector<vector<pair<int, int>>> near(sx * sy);
  auto encode = [&](int r, int c) { return r * sy + c; };
  for (int i = 0; i < sx; ++i) {
    int last = -1, jy = -1;
    for (int j = 0; j < sy; ++j) {
      int now = encode(i, j);
      if (last != -1) {
        near[now].emplace_back(last, abs(jy - dy[j]));
      }
      if (id[i][j] != -1) {
        last = id[i][j];
        jy = dy[j];
      }
    }
    last = -1, jy = -1;
    for (int j = sy - 1; j >= 0; --j) {
      int now = encode(i, j);
      if (last != -1) {
        near[now].emplace_back(last, abs(jy - dy[j]));
      }
      if (id[i][j] != -1) {
        last = id[i][j];
        jy = dy[j];
      }
    }
  }
  for (int j = 0; j < sy; ++j) {
    int last = -1, ix = -1;
    for (int i = 0; i < sx; ++i) {
      int now = encode(i, j);
      if (last != -1) {
        near[now].emplace_back(last, abs(ix - dx[i]));
      }
      if (id[i][j] != -1) {
        last = id[i][j];
        ix = dx[i];
      }
    }
    last = -1, ix = -1;
    for (int i = sx - 1; i >= 0; --i) {
      int now = encode(i, j);
      if (last != -1) {
        near[now].emplace_back(last, abs(ix - dx[i]));
      }
      if (id[i][j] != -1) {
        last = id[i][j];
        ix = dx[i];
      }
    }
  }
  Dsu dsu(n);
  const long long inf = 2e9 + 7;
  long long low = 0, hig = inf;
  vector<int> num(n);
  while (low < hig) {
    long long mid = (low + hig  ) >> 1;
    bool ok = false;
    dsu.reset();
    for (int i = 0; i < n; ++i) {
      int now = encode(x[i], y[i]);
      for (auto & e : near[now]) {
        if (e.second > mid) continue;
        dsu.merge(i, e.first);
      }
    }
    int cnt = 0;
    for (int i = 0; i < n && cnt <= 4; ++i) {
      if (dsu.find(i) == i) {
        num[i] = 1 << cnt++;
      }
    }
    if (cnt <= 1) {
      ok = true;
    } else if (cnt <= 4) {
      int all = (1 << cnt) - 1;
      if (cnt == 2) {
        for (int i = 0; i < n; ++i) {
          int now = encode(x[i], y[i]);
          for (auto & e : near[now]) {
            if (e.second > mid * 2 || dsu.find(i) == dsu.find(e.first)) continue;
            ok = true;
            break;
          }
        }
      }
      for (int i = 0; i < sx; ++i) {
        for (int j = 0; j < sy; ++j) {
          int mask = 0;
          int now = encode(i, j);
          for (auto & e : near[now]) {
            if (e.second > mid) continue;
            mask |= num[dsu.find(e.first)];
          }
          ok |= mask == all;
        }
      }
    }
    if (ok)
      hig = mid;
    else
      low = mid + 1;
  }
  if (low >= inf)
    low = -1;
  printf("%lld\n", low);
  return 0;
}
