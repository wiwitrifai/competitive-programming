#include <bits/stdc++.h>

using namespace std;

const long double pi = acos(-1), eps = 1e-12;

struct point {
  int x[5];
  point(){}
  long double operator*(point b) {
    long double ret = 0;
    for (int i = 0; i < 5; i++)
      ret += (long double)x[i] * b.x[i];
    return ret;
  }
  point operator-(point b) {
    point c;
    for (int i = 0; i < 5; i++)
      c.x[i] = x[i] - b.x[i];
    return c;
  }
};
long double dist(point a) {
  return sqrt(a * a);
}

bool cek(point a, point b, point c) {
  point pb = b - a, pc = c-a;
  long double val = (long double)(pb * pc) / dist(pb) / dist(pc);
  return (fabs(val) < eps) || val < 0;
}
const int N  = 1024;
point p[N];

int main() {
  int n;
  scanf("%d", &n);
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < 5; j++)
      scanf("%d", &p[i].x[j]);
  }
  vector<int> ans;
  for (int i = 0; i < n; i++) {
    bool ok = 1;
    for (int j = 0; j < n && ok; j++) {
      if (i == j) continue;
      for (int k = j+1; k < n && ok; k++) {
        if (k == i || k == j) continue;
        ok &= cek(p[i], p[j], p[k]);
      }
    }
    if (ok)
      ans.push_back(i+1);
  }
  printf("%d\n", ans.size());
  for (int x : ans)
    printf("%d\n", x);
  return 0;
}