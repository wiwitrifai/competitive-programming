#include <bits/stdc++.h>

using namespace std;

struct point {
  long double x, y, z;
  point(long double x = 0, long double y = 0, long double z = 0) : x(x), y(y), z(z){
  }
  point operator-(point b) {
    return point(x-b.x, y-b.y, z-b.z);
  }
  point operator+(point b) {
    return point(x+b.x, y+b.y, z+b.z);
  }
  long double norm() {
    return x * x + y * y + z * z;
  }
  point operator*(point b) {
    return point(y * b.z - z * b.y, z * b.x - x * b.z, x * b.y - y * b.x);
  }
  long double operator^(point b) {
    return x * b.x + y * b.y + z * b.z;
  }
  point scale(long double v) {
    return point(x * v, y * v, z * v);
  }
};

const int N = 5000;
point s[N];
long double ri[N], v[N];
int rem[N];
point b[N];

int main() {
  int n, m, r;
  scanf("%d %d %d", &n, &m, &r);
  int cnt = 0;
  while (n && m && r) {
    for (int i = 0; i < n; i++) {
      double x, y, z, w;
      scanf("%lf %lf %lf %lf", &x, &y, &z, &w);
      s[i] = point(x, y, z);
      ri[i] = w;
      ri[i] *= ri[i];
    }
    for (int i = 0; i < m; i++) {
      double x, y, z, w;
      scanf("%lf %lf %lf %lf", &x, &y, &z, &w);
      b[i] = point(x, y, z);
      v[i] = w;
    }
    double x, y, z;
    scanf("%lf %lf %lf", &x, &y, &z);
    point e(x, y, z);
    int ma = 1 << m;
    for (int i = 0; i < n; i++) {
      rem[i] = 0;
      for (int j = 0; j < m; j++) {
        long double dbs = (s[i] - b[j]).norm();
        long double des = (s[i] -e).norm();
        if (dbs < ri[i] && des < ri[i]) {
          continue;
        }
        if (dbs < ri[i] || des < ri[i]) {
          rem[i] |= 1 << j;
          continue;
        }        
        long double dot = (s[i] - e) ^ (b[j] - e);
        if (dot < 0) {
          continue;
        }
        long double dbe = sqrt((b[j] - e).norm());
        long double v = dot / dbe;
        if (v > dbe) {
          continue;
        }
        point now = e + (b[j] - e).scale(v / dbe);
        long double dist = (now - s[i]).norm();
        if (dist < ri[i])
          rem[i] |= 1 << j;
      }
/*      for (int j = 0; j < m; j++)
        cout << rem[i][j] << " | ";
      cout << endl; */
    }
    double ans = 0;
    for (int mask = 0; mask < ma; mask++) {
      int rr = r;
      for (int i = 0; i < n && rr >= 0; i++) {
        if (rem[i] & mask) rr--;
      }
//      cout << mask << " lho " << rr << endl;
      if (rr >= 0) {
        double now = 0;
        for (int i = 0; i < m; i++) if (mask & (1 << i)) {
          now += (double)v[i] / (b[i]-e).norm();
        }
        ans = max(ans, now);
      }
    }
    printf("%.10lf\n", ans);
    scanf("%d %d %d", &n, &m, &r);
  }
  return 0;
}