#include <bits/stdc++.h>

using namespace std;

const double eps = 1e-9;
const double PI = acos(-1);

struct point
{
  double x, y;
  point (double x = 0, double y = 0) : x(x), y(y) {
  }
};

///// Find two center of same size circle from its intersection and their radius
bool circle2PtsRad(point p1, point p2, double r, point *c, point * d) { // answer at *c
  double d2 = (p1.x - p2.x) * (p1.x - p2.x) + (p1.y - p2.y)*(p1.y - p2.y);
  double det = r * r / d2 - 0.25;
  if(det<0.0) return false;
  double h = sqrt(det);
  c->x = (p1.x + p2.x) * 0.5 + (p1.y-p2.y)*h;
  c->y = (p1.y + p2.y) * 0.5 + (p2.x-p1.x)*h;
  d->x = (p1.x + p2.x) * 0.5 - (p1.y-p2.y)*h;
  d->y = (p1.y + p2.y) * 0.5 - (p2.x-p1.x)*h;
  return true;
}

double cross(point a, point b, point c) {
  return (a.x-b.x) * (c.y-b.y) - (a.y-b.y)*(c.x-b.x);
}

double dist(point a, point b) {
  return hypot(a.x - b.x, a.y - b.y);
}

double area(point a, point b, point c) {
  double ret = cross(a, point(), b) + cross(b, point(), c) + cross(c, point(), a);
  if (ret < 0) ret = -ret;
  return ret/2;
}

const int N = 55;

point p[N];
pair< long long, long long > pp[N];
int inside[N];
int n;
long long len;
int cnt[2][N];
vector< long long > vy;

int calc() {
  int ret[2];
  ret[0] = ret[1] = 0;
  int last = 0;
  memset(cnt, 0, sizeof cnt);
  for (int i = 0; i < n; i++) {
    while (last < i) {
      if (pp[last].first + len < pp[i].first) {
        int id = inside[last];
        for (int j = 0; j < vy.size(); j++)
          if (vy[j] <= pp[last].second && pp[last].second <= vy[j]+len)
            cnt[id][j]--;
        last++;
      }
      else
        break;
    }
    int id = inside[i];
    for (int j = 0; j < vy.size(); j++)
      if (vy[j] <= pp[i].second && pp[i].second <= vy[j]+len) {
        cnt[id][j]++;
        if (ret[id] < cnt[id][j])
          ret[id] = cnt[id][j];
      }
    }
    return ret[0] + ret[1];
  }

int main() {
  time_t start_t = clock();
  cerr << "START!" << endl;
  int t;
  scanf("%d", &t);
  for (int tc = 1; tc <= t; tc++) {
    int ans = 0;
    scanf("%d %lld", &n, &len);
    vy.clear();
    for (int i = 0; i < n; i++) {
      long long xx, yy;
      scanf("%lld %lld", &xx, &yy);
      pp[i] = make_pair(xx, yy);
      vy.push_back(yy);
    }
    sort(vy.begin(), vy.end());
    vy.erase(unique(vy.begin(), vy.end()), vy.end());
    sort(pp, pp+n);
    for (int i = 0; i < n; i++)
      p[i] = point(pp[i].first, pp[i].second);
    for (int a = 0; a < n; a++) {
      for (int i = 0; i < n; i++)
        inside[i] = (i != a);
      ans = max(ans, calc());
      for (int b = a+1; b < n; b++) {
        if (dist(p[a], p[b]) < eps)
          continue;
        point mid((p[a].x + p[b].x)/2, (p[a].y+p[b].y)/2);
        double rmid = dist(p[a], p[b])/2;
        for (int j = 0; j < n; j++) {
          inside[j] = (dist(mid, p[j]) <= rmid + eps);
        }
        ans = max(ans, calc());
        for (int c = b+1; c < n; c++) {
          double luas = area(p[a], p[b], p[c]);
          if (fabs(luas) < eps)
            continue;
          double r = dist(p[a], p[b]) * dist(p[a], p[c]) * dist(p[b], p[c]) / (4 * luas);
          point cntr, c1, c2;
          if (!circle2PtsRad(p[a], p[b], r, &c1, &c2))
            continue;
          if (dist(c1, p[c]) < dist(c2, p[c]))
            cntr = c1;
          else
            cntr = c2;
          // r = dist(cntr, p[c]);
          // cerr << dist(p[c], c1) << " " << r << " ";
          // cerr << dist(p[c], c2) << endl;
          // assert(fabs(dist(p[c], cntr) - r) <= eps);
          for (int i = 0; i < n; i++) {
            inside[i] = (dist(cntr, p[i]) <= r + eps);
          }
          ans = max(ans, calc());
        }
      }
    }
    printf("Case #%d: %d\n", tc, ans);
    cerr << "TC #"<< tc << " : done! time: " << (double)(clock()-start_t) * 1000 / CLOCKS_PER_SEC << " ms" << endl;
  }
  return 0;
}