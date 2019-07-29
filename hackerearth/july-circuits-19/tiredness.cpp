#include <bits/stdc++.h>

using namespace std;

struct point {
  int x, y;
  point(int x = 0, int y = 0) : x(x), y(y) {};
  bool operator==(point p) const { return x == p.x && y == p.y; }
  bool operator<(point p) const { return y == p.y ? x < p.x : y < p.y; }
  void read() {
    scanf("%d %d", &x, &y);
  }
};

ostream& operator<<(ostream& os, point p) {
  return os << "(" << p.x << "," << p.y << ")";
}

long long dist(point a, point b) {
  return abs(a.x - b.x) + abs(a.y - b.y);
}

point nearest(point p, point recA, point recB) {
  vector<point> candidate;
  if (recA.x <= p.x && p.x <= recB.x && recA.y <= p.y && p.y <= recB.y)
    return p;
  if (recA.x <= p.x && p.x <= recB.x) {
    candidate.push_back(point(p.x, recA.y));
    candidate.push_back(point(p.x, recB.y));
  }
  if (recA.y <= p.y && p.y <= recB.y) {
    candidate.push_back(point(recA.x, p.y));
    candidate.push_back(point(recB.x, p.y));
  }
  candidate.push_back(recA);
  candidate.push_back(recB);
  candidate.push_back(point(recA.x, recB.y));
  candidate.push_back(point(recB.x, recA.y));
  point ret = candidate[0];
  long long best = dist(ret, p);
  for (point c : candidate) {
    long long cur = dist(c, p);
    if (cur < best) {
      best = cur;
      ret = c;
    }
  }
  return ret;
}
vector<tuple<int, point, point>> newpaths;

void set_path(int id, tuple<int, point, point> entry) {
  if (id >= (int)newpaths.size())
    newpaths.push_back(entry);
  else
    newpaths[id] = entry;
}

int main() {
  auto startclock = clock();
  int n, d;
  scanf("%d %d", &n, &d);
  vector<tuple<int, point, point>> canopies(n+1);
  for (int i = 0; i <= n; ++i) {
    point a, b;
    int cost;
    a.read();
    b.read();
    if (i) {
      if (a.x > b.x)
        swap(a.x, b.x);
      if (a.y > b.y)
        swap(a.y, b.y);
    }
    scanf("%d", &cost);
    canopies[i] = make_tuple(cost, a, b);
  }
  vector<tuple<int, point, point>> paths;
  paths.emplace_back(canopies[0]);
  vector<int> ids(n);
  iota(ids.begin(), ids.end(), 1);
  sort(ids.begin(), ids.end(), [&](int l, int r) {
    return get<0>(canopies[l]) < get<0>(canopies[r]);
  });
  get<0>(paths[0]) = 0;
  long long cur = dist(get<1>(canopies[0]), get<2>(canopies[0])) * get<0>(canopies[0]) + d;
  for (int i : ids) {
    if ((double)(clock() - startclock) / CLOCKS_PER_SEC > 4.8)
      break;
    int cost;
    point a, b;
    tie(cost, a, b) = canopies[i];
    int iter = 0;
    int sz = (int)paths.size();
    for (auto & path : paths) {
      point p, q;
      int c;
      tie(c, p, q) = path;
      int id = c;
      c = get<0>(canopies[c]);
      long long changes = - (1LL * dist(p, q) * c + d);
      point f = nearest(p, a, b), g = nearest(q, a, b);
      changes += (dist(p, f) + dist(g, q)) * cost + dist(f, g) * c + d;
      int cnt = 0;
      if (!(f == p))
        changes += d, ++cnt;
      if (!(g == q))
        changes += d, ++cnt;
      if (changes < 0 && sz + cnt <= int(1e5)) {
        if (!(f == p))
          set_path(iter++, make_tuple(id, p, f));
        set_path(iter++, make_tuple(i, f, g));
        if (!(g == q))
          set_path(iter++, make_tuple(id, g, q));
        cur += changes;
        sz += cnt;
      }
      else
        set_path(iter++, path);
    }
    int pos = 0;
    cur = 0;
    for (int j = 0; j < iter;) {
      int k = j, can = get<0>(newpaths[j]);
      while (k < iter && get<0>(newpaths[k]) == can) ++k;
      point a = get<1>(newpaths[j]), b = get<2>(newpaths[k-1]);
      if (paths.size() <= pos) {
        paths.emplace_back(can, a, b);
      }
      else
        paths[pos] = make_tuple(can, a, b);
      ++pos;
      cur += dist(a, b) * get<0>(canopies[can]) + d;
      j = k;
    }
    if (paths.size() > pos)
      paths.resize(pos);
  }
  printf("%d\n", (int)paths.size());
  for (auto & path : paths) {
    point p, q;
    int c;
    tie(c, p, q) = path;
    printf("%d %d %d %d %d\n", p.x, p.y, q.x, q.y, c);
  }
  return 0;
}
