#include <bits/stdc++.h>

using namespace std;

const int N = 1e5 + 5, ITER = 100;
const double inf = 1e9;

int n;
struct line {
  long long a, b, c;
  line() {}
  double getx(double y) {
    return -(double)(b * y + c)/(double)a; 
  }
  double gety(double x) {
    return -(double)(a * x + c)/(double)b; 
  }
};
line l[N];
int pos[N], id[N];

bool cmp(int le, int ri) {
  return l[le].a * l[ri].b > l[le].b * l[ri].a;
}

pair<double, int> vs[N];

int bit[N];

int get(int x) {
  int ret = 0;
  for (; x; x -= x&-x)
    ret += bit[x];
  return ret;
}
void upd(int x, int v) {
  for (; x <= n; x += x&-x)
    bit[x] += v;
}

double solve() {
  sort(id, id + n, cmp);
  for (int i = 0; i < n; i++)
    pos[id[i]] = i;
  double le = -inf, ri = inf;
  long long all = 1LL * n * (n - 1) / 2;
  for (int iter = 0; iter < ITER; iter++) {
    double mid = (le + ri) / 2.0;
    for (int i = 0; i < n; i++) {
      vs[i] = make_pair(l[i].gety(mid), i);
    }
    sort(vs, vs+n);
    fill(bit, bit+n+1, 0);
    long long cnt = 0;
    // for (int i = 0; i < n; i++)
    //   cerr << id[i] << " ";
    // cerr << " ? " << endl;
    for (int i = 0; i < n; i++) {
      // cerr << vs[i].second << " ";
      cnt += get(pos[vs[i].second] + 1);
      upd(pos[vs[i].second] + 1, 1);
    }
    // cerr << " " << cnt << endl;
    if (cnt * 2 >= all)
      ri = mid;
    else
      le = mid;
  }
  return le;
}

int main() {
  scanf("%d", &n);
  for (int i = 0; i < n; i++) {
    scanf("%lld %lld %lld", &l[i].a, &l[i].b, &l[i].c);
    l[i].c *= -1;
    if (l[i].b < 0) {
      l[i].a *= -1;
      l[i].b *= -1;
      l[i].c *= -1;
    }
    id[i] = i;
  }
  double x = solve();
  for (int i = 0; i < n; i++) { 
    swap(l[i].a, l[i].b);
    if (l[i].b < 0) {
      l[i].a *= -1;
      l[i].b *= -1;
      l[i].c *= -1;
    }
    id[i] = i;
  }
  double y = solve();
  printf("%.20lf %.20lf\n", x, y);
  return 0;
}