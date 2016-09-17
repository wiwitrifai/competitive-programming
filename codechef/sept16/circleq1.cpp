#include <bits/stdc++.h>

using namespace std;

const int R = 55, N = 5e4 + 5, M = 1e5 + 5;
const int HI = 1e7;
const double PI = acos(-1);
const double inf = 1e17;

double circ[R][R][R];
int up[R][R], upp[R][R];
double ans[M];
int aa[M], bb[M], cc[M], dd[M];
pair< pair<int, int>, int > circle[N];
vector< pair<pair < int, double >, int > > intesect[N];

double integral(double x, double r) {
  return (double)0.5 * (sqrt(r * r - x * x) * x + r * r * asin(x/r)); 
}

struct seg_tree {
  int n;
  double sum[N << 2];
  seg_tree(int n) : n(n) {
    build();
  }
  void build(int id = 1, int l = 0, int r = -1) {
    if (r == -1) r = this->n;
    if (r-l < 2) {
      sum[id] = 0;
      return;
    }
    int mid = (l + r) >> 1, il = id << 1, ir = il | 1;
    build(il, l, mid);
    build(ir, mid, r);
    sum[id] = sum[il] + sum[ir];
  }

  void update(int x, double add) {
    int id = 1, l = 0,  r = this->n;
    while (l + 1 < r) {
      sum[id] += add;
      // cerr << l << " " << r << " " << sum[id] << endl;
      int mid = (l + r) >> 1;
      id <<= 1;
      if (x < mid)
        r = mid;
      else {
        l = mid;
        id |= 1;
      }
    }
    sum[id] += add;
    // cerr << l << " " << r << " " << sum[id] << endl;
  }

  double get(int x, int y, int id = 1, int l = 0, int r = -1) {
    if (r == -1) r = this->n;
    if (x >= r || y <= l ) return 0;
    if (x <= l && r <= y) {
      // cerr << l << " get " <<r  << " " << sum[id] << endl;
      return sum[id];
    }
    int mid = (l + r) >> 1, il = id << 1, ir = il | 1;
    return get(x, y, il, l, mid) + get(x, y, ir, mid, r);
  }
};

double getIntersect(int y, int x) {
  cerr << "gei " << y << " " << x;
  int id = upper_bound(intesect[y].begin(), intesect[y].end(), make_pair(make_pair(x, inf), N)) - intesect[y].begin() - 1;
  if (id < 0) {
    cerr << 0 << endl;
    return 0;
  }
  int xxx = intesect[y][id].first.first;
  double ret = intesect[y][id].first.second;
  id = intesect[y][id].second;
  int xx = circle[id].first.first, yy = circle[id].first.second, r = circle[id].second;
  long long dx = x - xx, dy = y - yy, dr = r;
  if (x >= xx) {
    x -= xx;
    for (int i = r-1; i >= -r; i--) {
      int j = i < 0 ? - i - 1 : i;
      if (i+yy < y)
        break;
      if (j < r && x < r)
        ret -= circ[r][j][x];
    }
  }
  else {
    x = xx-x;
    for (int i = r-1; i >= -r; i--) {
      int j = i < 0 ? - i - 1 : i;
      if (i+yy < y)
        break;
      if (j < r && x < r)
        ret -= 2 * circ[r][j][0] - circ[r][j][x];
    }
  }
  cerr << " " << ret << endl;
  return ret;
}


double getIntersect2(int x, int y) {
  cerr << "getI2 " << x << " " << y;
  int id = upper_bound(intesect[x].begin(), intesect[x].end(), make_pair(make_pair(-y, inf), N)) - intesect[x].begin() - 1;
  if (id < 0) {
    cerr << -y << endl;
    return 0;
  }
  // cerr << id << endl;
  int yyy = -intesect[x][id].first.first;
  double ret = intesect[x][id].first.second;
  int it = intesect[x][id].second;
  int xx = circle[it].first.first, yy = circle[it].first.second, r = circle[it].second;
  if (y <= yy - r || (y < yy - (yyy - yy) && x <= xx)) {
    cerr << ret << " " << id << endl;
    return ret;
  }
  id--;
  if (id < 0) {
    cerr << ret << endl;
    return 0;
  }
  ret = intesect[x][id].first.second;
  cerr << ret << endl;
  return ret;
  // if (y <= yy) {
  //   y = yy-y;
  //   for (int i = -r+1; i < r; i++) {
  //     int j = i <= 0 ? - i : i-1;
  //     if (i+x > x)
  //       break;
  //     ret -= circ[r][j][y];
  //   }
  // }
  // else {
  //   y -= yy;
  //   for (int i = -r+1; i < r; i++) {
  //     int j = i <= 0 ? - i : i - 1;
  //     if (i+xx > x)
  //       break;
  //     ret -= 2 * circ[r][j][0] - circ[r][j][y];
  //   }
  // }
  cerr << ret << endl;
  return ret;
}


int main() {
  for (int r = 1; r < R; r++) {
    double all = 0;
    for (int i = 0; i < r; i++) {
      int j = 0;
      for (j = 0; j < r; j++) {
        if (i * i + j * j >= r * r)
          break;
        if ((i + 1) * (i + 1) + (j + 1) * (j + 1) <= r * r) {
          up[r][i] = j;
          all += 1.0;
          circ[r][i][j] = 1.0;
        }
        else {
          double xx = (double) sqrt(r * r - (j + 1) * (j + 1));
          xx = max(xx, (double)i);
          double x2 = min((double) sqrt(r * r - j * j), (double)i+1);;
          circ[r][i][j] = xx - i + integral(x2, r) - integral(xx, r) - (x2- xx) * j;
          all += circ[r][i][j];
          upp[r][i] = j;
        }
      }
      for (int j = r-1; j >0; j--)
        circ[r][i][j-1] += circ[r][i][j]; 
    }
  }
  int n, m;
  scanf("%d %d", &n, &m);
  for (int i = 0; i < n; i++) {
    int x, y, r;
    scanf("%d %d %d", &x, &y, &r);
    circle[i] = {{x, y}, r};
  }
  vector< pair<int, int > > ev;
  for (int i = 0; i < m; i++) {
    scanf("%d %d %d %d", aa+i, bb+i, cc+i, dd+i);
    ans[i] = 0;
    ev.push_back({aa[i], -i-1});
    ev.push_back({cc[i], i+1});
  }
  sort(ev.begin(), ev.end());
  sort(circle, circle+n, [](pair<pair<int, int >, int > pp, pair< pair<int, int>, int > qq) {
    return pp.first.first + pp.second < qq.first.first + qq.second;
  });
  int last = -1, id = 0;
  seg_tree seg(N);
  for (int i = 0; i < n; i++) {
    if (last != circle[i].first.first + circle[i].second) {
      last = circle[i].first.first + circle[i].second;
      // cerr << last << " last" << endl;
      while (id < ev.size() && ev[id].first < last) {
        int iv = ev[id].second;
        id++;
        if (iv < 0) {
          iv *= -1;
          iv--;
          ans[iv] -= seg.get(bb[iv], dd[iv]);
        }
        else {
          iv--;
          ans[iv] += seg.get(bb[iv], dd[iv]);
        }
        // cerr << ev[id-1].first << " " <<  iv << " " << bb[iv] << " " << dd[iv] << " " << ans[iv] << endl;
      }
    }
    // cerr << PI * circle[i].second * circle[i].second << endl;
    seg.update(circle[i].first.second - circle[i].second, PI * circle[i].second * circle[i].second);
    // cerr << circle[i].first.second - circle[i].second << endl;
  }
  while (id < ev.size()) {
    int iv = ev[id].second;
    id++;
    if (iv < 0) {
      iv *= -1;
      iv--;
      ans[iv] -= seg.get(bb[iv], dd[iv]);
    }
    else {
      iv--;
      ans[iv] += seg.get(bb[iv], dd[iv]);
    }
    // cerr << iv << " " << ans[iv] << endl;
  }
  // for (int i = 0; i < m; i++) {
  //   cerr << "tmp " << i << " " << ans[i] << endl;
  // }
  // cerr << "first stage" << endl;
  // intersect horizontal
  for (int i = 0; i < n; i++) {
    int x = circle[i].first.first, y = circle[i].first.second, r = circle[i].second;
    double now = 0;
    for (int j = r-1; j > -r; j--) {
      int iid = j < 0 ? -j-1 : j;
      now += 2 * circ[r][iid][0];
      cerr << y + j  << " " << now << endl;
      if (y + j >= 0 && y + j < N)
        intesect[y+j].push_back({{x - upp[r][iid], now}, i});
    }
  }
  for (int i = 0; i < N; i++) {
    sort(intesect[i].begin(), intesect[i].end());
    double now = 0;
    for (int j = 0; j < intesect[i].size(); j++) {
      now += intesect[i][j].first.second;
      intesect[i][j].first.second = now;
    }
  }
  for (int i = 0; i < m; i++) {
    ans[i] += getIntersect(bb[i], cc[i]) - getIntersect(bb[i], aa[i]) - getIntersect(dd[i], cc[i]) + getIntersect(dd[i], aa[i]);
    cerr << endl << " ans " << ans[i] << endl;
  }
  for (int i = 0; i < N; i++)
    intesect[i].clear();

  // cerr << "second stage" << endl;
  // intersect vertical
  for (int i = 0; i < n; i++) {
    // cerr << i << endl;
    int x = circle[i].first.first, y = circle[i].first.second, r = circle[i].second;
    double now = 0;
    for (int j = -r+1; j < r; j++) {
      int iid = j <= 0 ? -j : j-1;
      now += 2 * circ[r][iid][0];
      if (x + j >= 0 && x + j < N)
        intesect[x+j].push_back({{-(y + upp[r][iid]), now}, i});
    }
  }
  // cerr << "world" << endl;
  for (int i = 0; i < N; i++) {
    sort(intesect[i].begin(), intesect[i].end());
    double now = 0;
    for (int j = 0; j < intesect[i].size(); j++) {
      now += intesect[i][j].first.second;
      intesect[i][j].first.second = now;
    }
  }
  // cerr << "halo" << endl;
  for (int i = 0; i < m; i++) {
    ans[i] += getIntersect2(cc[i], bb[i]) - getIntersect2(cc[i], dd[i]) - getIntersect2(aa[i], bb[i]) + getIntersect2(aa[i], dd[i]);
    cerr << endl << " ans " << ans[i] << endl;
  }
  // cerr << "finish stage" << endl;
  for (int i = 0; i < m; i++)
    printf("%.7lf\n", ans[i]);
  return 0;
}