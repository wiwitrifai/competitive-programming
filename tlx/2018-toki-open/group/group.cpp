#include "group.h"

#include <bits/stdc++.h>

using namespace std;

const int inf = 2e9 + 7;
#define x first
#define y second
typedef pair<int, int> point;
vector<point > vp;

int dist(point a, point b) {
  return abs(a.x - b.x) + abs(a.y - b.y);
}

bool can(int d) {
  int n = vp.size();
  for (int i = 0; i < n; ++i) {
    for (int j = i+1; j < n; ++j) {
      if (dist(vp[i], vp[j]) <= d) continue;
      for (int k = j+1; k < n; ++k) {
        if (dist(vp[k], vp[i]) <= d || dist(vp[k], vp[j]) <= d) continue;
        return false;
      }
    }
  }
  return true;
}

int calc(vector<point> & p) {
  int ans = 0;
  for (int i = 0; i < p.size(); ++i) {
    for (int j = i+1; j < p.size(); ++j) {
      ans = max(ans, dist(p[i], p[j]));
    }
  }
  return ans;
}

int solve() {
  int mi = inf;
  int n = vp.size(), nmask = 1 << n;
  for (int mask = 0; mask < nmask; ++mask) {
    vector<point> a, b;
    for (int i = 0; i < n; ++i) if (mask & (1 << i))
      a.push_back(vp[i]);
    else
      b.push_back(vp[i]);
    mi = min(mi, max(calc(a), calc(b)));
  }
  return mi;
}

int getMinimumDelay(int N, std::vector<int> X, std::vector<int> Y) {
  int le = 0, ri = inf;
  vp.clear();
  for (int i = 0; i < N; ++i) {
    vp.emplace_back(X[i], Y[i]);
  }
  return solve();
}
