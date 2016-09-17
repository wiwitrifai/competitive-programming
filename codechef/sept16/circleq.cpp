#include <bits/stdc++.h>


using namespace std;

const int R = 55, N = 5e4 + 5, M = 1e5 + 5;
const int HI = 1e7;

double circ[R][R][R];
int up[R][R], upp[R][R];
double ans[M];

double integral(double x, double r) {
  return (double)0.5 * (sqrt(r * r - x * x) * x + r * r * asin(x/r)); 
}

vector< pair<int, double> > a[N];
struct seg_tree {
  vector< pair<int, double> > seg[N << 2];
  int n;
  seg_tree(int n) : n(n) {
    build();
  }
  void build(int id = 1, int l = 0, int r = -1) {
    seg[id].clear();
    if (r == -1) r = this->n;
    if (r-l < 2) {
      double now = 0;
      seg[id].push_back(make_pair(-1, 0));
      sort(a[l].begin(), a[l].end());
      for (int i = 0; i < a[l].size(); i++) {
        now += a[l][i].second;
        seg[id].push_back({a[l][i].first, now});
      }
      return;
    }
    int mid = (l + r) >> 1, il = id << 1, ir = il | 1;
    build(il, l, mid);
    build(ir, mid, r);
    int jl = 0, jr = 0;
    double nowl = 0, nowr;
    while (jl < seg[il].size() && jr < seg[ir].size()) {
      if (seg[il][jl].first == seg[ir][jr].first) {
        nowl = seg[il][jl].second;
        nowr = seg[ir][jr].second;
        seg[id].emplace_back(seg[il][jl].first, nowl + nowr);
        jl++; jr++;
      }
      else if (seg[il][jl].first < seg[ir][jr].first) {
        nowl = seg[il][jl].second;
        seg[id].emplace_back(seg[il][jl].first, nowl + nowr);
        jl++;
      }
      else {
        nowr = seg[ir][jr].second;
        seg[id].emplace_back(seg[ir][jr].first, nowl + nowr);
        jr++;
      }
    }
    while (jl < seg[il].size()) {
      nowl = seg[il][jl].second;
      seg[id].emplace_back(seg[il][jl].first, nowl + nowr);
      jl++;
    }
    while (jr < seg[ir].size()) {
      nowr = seg[ir][jr].second;
      seg[id].emplace_back(seg[ir][jr].first, nowl + nowr);
      jr++;
    }
  }
  double get(int x, int y, int ma, int id = 1, int l = 0, int r = -1) {
    if (r == -1) r = this->n;
    if (x >= r || y <= l) return 0;
    if (x <= l && r <= y) {
      int i = lower_bound(seg[id].begin(), seg[id].end(), make_pair(ma, (double)-1)) - seg[id].begin() - 1;
      return (i >= 0) ? seg[id][i].second : 0;
    }
    int mid = (l + r) >> 1, il = id << 1, ir = il | 1;
    return get(x, y, ma, il, l, mid) + get(x, y, ma, ir, mid, r);
  }
};

int aa[M], bb[M], cc[M], dd[M];
pair< pair<int, int>, int > circle[N];

int main() {
  // cerr << setprecision(17) << fixed;
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
    }
  }
  int n, m;
  scanf("%d %d", &n, &m);
  for (int i = 0; i < n; i++) {
    int x, y, r;
    scanf("%d %d %d", &x, &y, &r);
    circle[i] = {{x, y}, r};
  }
  for (int i = 0; i < m; i++) {
    scanf("%d %d %d %d", aa+i, bb+i, cc+i, dd+i);
    ans[i] = 0;
  }
  int cnt = 0;
  for (int last = 0; last < n; last++) { 
    for (int k = last; k < n; k++) {
      int x = circle[k].first.first, y = circle[k].first.second, r = circle[k].second;
      for (int i = 0; i < r; i++) {
        for (int j = 0; j <= upp[r][i]; j++) {
          int xx = i + x, yy;
          if (xx < N) {
            yy = y + j;
            if (yy < N) {
              a[xx].emplace_back(yy, circ[r][i][j]);
              cnt++;
            }
            yy = y - j - 1;
            if (yy >= 0) {
              a[xx].emplace_back(yy, circ[r][i][j]);
              cnt++;
            }
          }
          xx = x - i - 1;
          if (xx >= 0) {
            yy = y + j;
            if (yy < N) {
              a[xx].emplace_back(yy, circ[r][i][j]);
              cnt++;
            }
            yy = y - j - 1;
            if (yy >= 0) {
              a[xx].emplace_back(yy, circ[r][i][j]);
              cnt++;
            }
          }
        }
      }
      last = k;
      if (cnt >= HI) {
        cnt = 0;
        break;
      }
    }
    seg_tree st(N);
    for (int i = 0; i < m; i++) {
      ans[i] += st.get(aa[i], cc[i], dd[i]) - st.get(aa[i], cc[i], bb[i]);
    }
  }
  for (int i = 0; i < m; i++)
    printf("%.7lf\n", ans[i]);
  return 0;
}