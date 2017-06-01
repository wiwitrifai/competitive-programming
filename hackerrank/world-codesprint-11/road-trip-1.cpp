#include <bits/stdc++.h>
using namespace std;

const int N = 2e5 + 5, MAGIC = 400, inf = 1e9 + 7;

int n, q;
int w[N];
int g[N], p[N];
long long ans[N];
vector< pair< pair< int, int >, int > > que;
long long solve_small(int x, int y, long long res = 0, long long f = 0, int pm = inf) {
  while (x < y) {
    f += g[x];
    pm = min(pm, p[x]);
    f -= w[x];
    x++;
    if (f < 0) {
      res += pm * -f;
      f = 0;
    }
  }
  return res;
}

bool cmp(pair< pair< int, int>, int > le, pair< pair< int, int>, int > ri) {
  int gl = le.first.second / MAGIC, gr = ri.first.second / MAGIC;
  if (gl == gr)
    return le.first.first > ri.first.first;
  return gl > gr;
}

int main() {
  scanf("%d %d", &n, &q);
  for (int i = 0; i < n-1; i++)
    scanf("%d", w+i);
  for (int i = 0; i < n; i++) {
    scanf("%d %d", g+i, p+i);
  }
  for (int i = 0; i < q; i++) {
    int x, y;
    scanf("%d %d", &x, &y);
    x--; y--;
    if (y - x <= MAGIC)
      ans[i] = solve_small(x, y);
    else
      que.push_back({{x, y}, i});
  }
  sort(que.begin(), que.end(), cmp);
  long long res = 0, f = 0;
  deque< pair< int, long long > > dq;
  int gg = -1, l = 0, pm;
  for (auto it : que) {
    int x = it.first.first, y = it.first.second, id = it.second;
    if (y / MAGIC != gg) {
      gg = y / MAGIC;
      l = gg * MAGIC;
      dq.clear();
      res = 0;
      f = 0;
      pm = inf;
    }
    while (l > x) {
      l--;
      pm = min(pm, p[l]);
      long long sisa = g[l] - w[l];
      while (sisa > 0 && !dq.empty()) {
        long long mm = min(sisa, dq.front().second);
        res -= mm * dq.front().first;
        sisa -= mm;
        dq.front().second -= mm;
        if (dq.front().second == 0)
          dq.pop_front();
      }
      while (!dq.empty()) {
        if (dq.front().first >= p[l]) {
          res -= dq.front().second * dq.front().first;
          sisa -= dq.front().second;
          dq.pop_front();
        }
        else
          break;
      }
      if (sisa < 0) {
        res += -sisa * p[l];
        dq.push_front(make_pair(p[l], -sisa));
      }
      else
        f += sisa;
    }
    ans[id] = solve_small(gg * MAGIC, y, res, f, pm);
  }
  for (int i = 0; i < q; i++)
    printf("%lld\n", ans[i]);
  return 0;
}
