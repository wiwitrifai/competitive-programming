// by wiwit
#include <bits/stdc++.h>

using namespace std;

struct point {
  int x, y;
  void swap() {
    ::swap(x, y);
  }
};

vector<pair<point, point> > solve(int a, int b, int n) {
  if (a < b) {
    vector<pair<point, point> > res = solve(b, a, n);
    for (auto & it : res) {
      swap(it.first, it.second);
      it.first.swap();
      it.second.swap();
    }
    return res;
  }
  int x = n-1, y = min(n-1, b);
  vector<pair<point, point> > res;
  res.emplace_back((point){x-n+1, y-n+1}, (point){x, y});
  while (x < a || y < b) {
    int dx = a-x, dy = b-y;
    if (dx > dy) {
      int addy = max(min(dy, n-1), 0);
      point v = {x+1, y+addy-n+1};
      point h = {v.x+n-1, v.y+n-1};
      res.emplace_back(v, h);
      x += n;
      y += addy;
    }
    else {
      int addx = max(min(dx, n-1), 0);
      point h = {x+addx-n+1, y+1};
      point v = {h.x+n-1, h.y+n-1};
      res.emplace_back(v, h);
      x += addx;
      y += n;
    }
  }
  return res;
}

int main() {
  int n;
  scanf("%d", &n);
  for (int i = 0; i < n; ++i) {
    int a, b, n;
    scanf("%d %d %d", &a, &b, &n);
    vector<pair<point, point> > ans = solve(abs(a), abs(b), n);
    printf("%d\n", ans.size());
    int sa = a < 0 ? -1 : 1, sb = b < 0 ? -1 : 1;
    for (auto  it : ans) {
      point v = it.first;
      point h = it.second;
      v.x *= sa;
      h.x *= sa;
      v.y *= sb;
      h.y *= sb;
      printf("%d %d %d %d\n", v.x, v.y, h.x, h.y);
    }
  }  

  return 0;
}