#include <bits/stdc++.h>

using namespace std;

const int S = 101, N = 1e4 + 4;
const long long inf = 1LL << 62;

struct Line {
  long long m, c;
  Line(long long m = 0, c = 0) : m(m), c(c) {}
  long long get(long long x) {
    return x * m + c;
  }
};

bool bad(Line a, Line b, Line c) {
  return (b.c - a.c) * (b.m - c.m) >= (c.c - b.c) * (a.m - b.m);
}

struct Bucket {
  Line l[S];
  vector<Line> hull;
  bool active[S];
  int ptr;
  Bucket() {
    memset(active, 0, sizeof active);
    ptr = 0;
    hull.clear();
  }
  void process() {
    hull.clear();
    ptr = 0;
    for (int i = 0; i < S; ++i) {
      if (!active[i]) continue;
      int sz;
      while ((sz = hull.size()) >= 2 && bad(hull[sz-2], hull[sz-1], l[i]))
        hull.pop_back();
      hull.push_back(l[i]);
    }
  }
  long long get(long long x) {
    if (hull.empty())
      return inf;
    while (ptr + 1 < hull.size() && hull[ptr].get(x) >= hull[ptr+1].get(x)) ++ptr;
    return hull[ptr].get(x);
  }
  void remove(int x) {
    if (!active[x]) return;
    active[x] = 0;
    process();
  }
  void add(int x, line ln) {
    active[x] = 1;
    l[x] = ln;
    process();
  }
};

Bucket buck[N / S + 2];
int x[N], y[N];

long long get_min(int l, int r, long long x) {
  long long ret = inf;
  for (int i = 0; i <= r; i += S) {
    if (i+S <= l) continue;
    if (l <= i && i+S-1 <= r) {
      ret = min(ret, buck[i/S].get(x));
    }
    else {
      for (int j = max(0, l-i); j <= min(S-1, r-i); ++j)
        ret = min(ret, buck[i/S].l[j].get(x));
    }
  }
  return ret;
}

int R[N], L[N];

int main() {
  int n, h, a, b;
  scanf("%d %d %d %d", &n, &h, &a, &b);
  for (int i = 0; i < n; ++i) {
    scanf("%d %d", x+i, y+i);
  }
  for (int i = 0; i < n; ++i) {
    for (int j = i+1, k = i; j < n; ++j) {
    }
  }
  buck[0].add(0, line(-2LL * b * x[0], 1LL * b * x[0] * x[0] + 1LL * a * (h - y[0])));
  long long ans = inf;
  for (int i = 1; i < n; ++i) {
    long long res = get_min(;
  }
  return 0;
}
