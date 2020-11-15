#include <bits/stdc++.h>

using namespace std;

typedef long long LD;

inline bool eq(LD x, LD y) { return x == y; }
inline bool le(LD x, LD y) { return x <= y; }
inline bool lt(LD x, LD y) { return x < y; }
inline int sign(LD x) { return eq(x, 0) ? 0 : (x < 0 ? -1 : 1); }

struct point {
  LD x, y;
  point(LD _x = 0, LD _y = 0) : x(_x), y(_y) {}
  point operator+(point p) { return point(x+p.x, y+p.y); }
  point operator-(point p) { return point(x-p.x, y-p.y); }
  point operator*(LD s) { return point(x * s, y * s); }
  point operator/(LD s) { return point(x / s, y / s); }
  LD operator*(point p) { return x * p.x + y * p.y; }
  LD operator%(point p) { return x * p.y - y * p.x; }
  LD norm2() { return *this * *this; }
  bool operator<(point p) const { return eq(y, p.y) ? x < p.x : y < p.y; }
  bool operator==(point p) { return eq(x, p.x) && eq(y, p.y); }
};

ostream& operator<<(ostream & os, point p) {
  return os << "(" << p.x << ", " << p.y << ")";
}

// 1 : ccw, -1 : cw, 0 : colinear
int ccw(point a, point b, point c) {
  return sign((b-a) % (c-b));
}

void solve() {
  int n;
  scanf("%d", &n);
  vector<point> vp;
  for (int i = 0; i < n; ++i) {
    int x, y;
    scanf("%d %d", &x, &y);
    vp.push_back(point(x, y));
  }
  vector<int> adjh(n, -1), adjv(n, -1);
  vector<int> idv(n), idh(n);
  iota(idv.begin(), idv.end(), 0);
  iota(idh.begin(), idh.end(), 0);
  sort(idv.begin(), idv.end(), [&](int l, int r) {
    return point(vp[l].y, vp[l].x) < point(vp[r].y, vp[r].x);
  });
  sort(idh.begin(), idh.end(), [&](int l, int r) {
    return vp[l] < vp[r];
  });
  for (int i = 0; i < n; ) {
    int j = i+1;
    while (j < n && vp[idv[i]].x == vp[idv[j]].x) {
      ++j;
    }
    if ((j-i) & 1) {
      puts("NO");
      return;
    }
    while (i < j) {
      int u = idv[i], v = idv[i+1];
      adjv[u] = v;
      adjv[v] = u;
      i += 2;
    }
  }
  for (int i = 0; i < n; ) {
    int j = i+1;
    while (j < n && vp[idh[i]].y == vp[idh[j]].y) {
      ++j;
    }
    if ((j-i) & 1) {
      puts("NO");
      return;
    }
    while (i < j) {
      int u = idh[i], v = idh[i+1];
      adjh[u] = v;
      adjh[v] = u;
      i += 2;
    }
  }
  vector<bool> vis(n, false);
  int v = 0, pre = adjv[v];
  while (!vis[v]) {
    vis[v] = true;
    int tmp = v;
    v = pre ^ adjv[v] ^ adjh[v];
    pre = tmp;
  }
  for (int i = 0; i < n; ++i) {
    if (!vis[i]) {
      puts("NO");
      return;
    }
  }
  vector<tuple<int, int, int, int>> events;
  for (int i = 0; i < n; ++i) {
    if (i < adjv[i]) {
      int u = adjv[i];
      int low = vp[i].y, hig = vp[u].y;
      if (low > hig)
        swap(low, hig);
      events.emplace_back(vp[i].x, 0, low, hig);
    }
    if (i < adjh[i]) {
      int u = adjh[i];
      int low = vp[i].x, hig = vp[u].x;
      if (low > hig)
        swap(low, hig);
      events.emplace_back(low, +1, vp[i].y, 0);
      events.emplace_back(hig, -1, vp[i].y, 0);
    }
  }
  set<int> st;
  sort(events.begin(), events.end());
  for (auto & it : events) {
    int x, op, low, hig;
    tie(x, op, low, hig) = it;
    if (op == 0) {
      if (st.lower_bound(low) != st.upper_bound(hig)) {
        puts("NO");
        return;
      }
    } else if (op < 0) {
      st.erase(low);
    } else {
      st.insert(low);
    }
  }
  puts("YES");
}

int main() {
  int tc = 1;
  scanf("%d", &tc);
  while (tc--) {
    solve();
  }
  return 0;
}
