#include <bits/stdc++.h>

using namespace std;

struct point {
  int x, y;
  point (int x = 0, int y = 0) : x(x), y(y) {}
  point operator+(point p) { return point(x + p.x, y + p.y); }
  bool operator<(point p) { return x == p.x ? y < p.y : x < p.x; }
  bool operator==(point p) { return x == p.x && y == p.y; }
};

const int N = 1024;

point p[N], q[N];

point read() {
  int x, y;
  scanf("%d %d", &x, &y);
  return point(x, y);
}


int main() {
  int n;
  scanf("%d", &n);
  for (int i = 0; i < n; ++i) {
    p[i] = read();
  }
  for (int i = 0; i < n; ++i)
    q[i] = read();
  vector<point> vp;
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < n; ++j) {
      vp.push_back(p[i] + q[j]);
    }
  }
  sort(vp.begin(), vp.end());
  point last = vp[0];
  int cnt = 0;
  point ans;
  for (int i = 0; i < vp.size(); ++i) {
    if (!(vp[i] == last))
      last = vp[i], cnt = 0;
    ++cnt;
    if (cnt == n) {
      ans = last;
      break;
    }
  }
  printf("%d %d\n", ans.x, ans.y);


  return 0;
}