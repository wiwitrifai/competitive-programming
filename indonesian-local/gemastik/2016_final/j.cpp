#include <bits/stdc++.h>

using namespace std;

const int N = 1e5 + 5;

struct point {
  long long x, y;
  point(long long x = 0, long long y = 0) : x(x), y(y) {};
  bool operator<(const point & b) const {
    if (x != b.x)
      return x > b.x;
    return y > b.y;
  }
  point operator-(const point & b) const {
    return point(x - b.x, y - b.y);
  }
  long long operator*(const point & b) const {
    return x * b.y - y * b.x;
  }
};
point p[N];
int a[N], k[N];
int m = 0;
int n;
point uh[N];
long long bit[N];
void upd(int x, long long v) {
  for (; x; x -= x&-x)
    bit[x] += v;
}
long long get(int x) {
  long long r = 0;
  for (; x < N; x += x&-x)
    r += bit[x];
  return r;
}
long long ans[N];


int main() {
  int t;
  scanf("%d", &t);
  while (t--) {
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
      int x, y;
      scanf("%d %d", &x, &y);
      p[i] = point(x, y);
    }
    int q;
    scanf("%d", &q);
    vector<pair<int, int> > e;
    for (int i = 0; i < q; i++)
      scanf("%d %d", a+i, k+i), e.emplace_back(a[i], i);
    sort(e.begin(), e.end());
    reverse(e.begin(), e.end());
    sort(p, p+n);
    fill(bit, bit + N, 0);
    m = 0;
    for (int i = 0, j = 0; i < e.size(); i++) {
      while (j < n && p[j].x >= e[i].first) {
        while (m >= 2 && (uh[m-2]-uh[m-1]) * (p[j] - uh[m-1]) > 0) {
          m--;
          upd(m, -(uh[m-1] * uh[m]));
        }
        uh[m] = p[j];
        if (m > 0)
          upd(m, uh[m-1] * uh[m]);
        m++;
        j++;
      }
      int id = e[i].second;
      int c = min(k[id], m);
      long long area = uh[m-1] * uh[m-c] + get(m-c+1);
      ans[id] = abs(area);
    }
    for (int i = 0; i < q; i++)
      printf("%lld.%d\n", ans[i]/2, 5 * (ans[i] & 1));
  }
  return 0;
}