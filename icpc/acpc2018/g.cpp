#include <bits/stdc++.h>

using namespace std;

void open_file(string filename) {
#ifndef LOCAL
  freopen(filename.c_str(), "r", stdin);
#endif
}

void close_file() {
#ifndef LOCAL
  fclose(stdin);
#endif
}

const int N = 1e5 + 5, LG = 20;

int gcd(int a, int b) {
  return a ? gcd(b % a, a) : b;
}

int sp[LG][N];
int get_gcd(int l, int r) {
  int len = r - l;
  int lg = 31 - __builtin_clz(len);
  return gcd(sp[lg][l], sp[lg][r-(1 << lg)]);
}

int a[N];

struct Event {
  int d, l, r, til, id;
  bool operator<(Event e) {
    if (d != e.d)
      return d < e.d;
    if (l != e.l)
      return l > e.l;
    if (id != e.id)
      return id < e.id;
    return r < e.r;
  }
};

int n, q;
long long sum[N << 2], la[N << 2];

void build(int id = 1, int l = 0, int r = n) {
  sum[id] = la[id] = 0;
  if (r-l < 2) {
    return;
  }
  int mid = (l + r) >> 1, il = id << 1, ir = il | 1;
  build(il, l, mid);
  build(ir, mid, r);
}

void upd(int id, int l, int r, long long va) {
  int len = r-l;
  sum[id] += va * len;
  la[id] += va;
}

void push(int id, int l, int r) {
  if (la[id] == 0) return;
  int il = id << 1, ir = il | 1, mid = (l + r) >> 1;
  upd(il, l, mid, la[id]);
  upd(ir, mid, r, la[id]);
  la[id] = 0;
}

void update(int x, int y, int v, int id = 1, int l = 0, int r = n) {
  if (x >= r || l >= y) return;
  if (x <= l && r <= y) {
    upd(id, l, r, v);
    return;
  }
  int mid = (l + r) >> 1, il = id << 1, ir = il | 1;
  push(id, l, r);
  update(x, y, v, il, l, mid);
  update(x, y, v, ir, mid, r);
  sum[id] = sum[il] + sum[ir];
}

long long get(int x, int y, int id = 1, int l = 0, int r = n) {
  if (x >= r || l >= y) return 0;
  if (x <= l && r <= y)
    return sum[id];
  int mid = (l + r) >> 1, il = id << 1, ir = il | 1;
  push(id, l, r);
  return get(x, y, il, l, mid) + get(x, y, ir, mid, r);  
}


long long ans[N];

int main() {
  open_file("gcdrng.in");
  int t;
  scanf("%d", &t);
  while (t--) {
    scanf("%d %d", &n, &q);
    for (int i = 0; i < n; ++i)
      scanf("%d", a+i), sp[0][i] = a[i];
    for (int i = 0; i + 1 < LG; ++i) {
      for (int j = 0; j + (1 << (i+1)) <= n; ++j)
        sp[i+1][j] = gcd(sp[i][j], sp[i][j+(1 << i)]);
    }
    vector<Event> ve;
    for (int i = 0; i < n; ++i) {
      int lo = i;
      while (lo < n) {
        int from = lo;
        int g = get_gcd(i, lo+1);
        int ri = n;
        while (lo < ri) {
          int mid = (lo + ri + 1) >> 1;
          if (get_gcd(i, mid) == g)
            lo = mid;
          else
            ri = mid-1;
        }
        ve.push_back((Event){g, i, from, lo, -1});
      }
    }
    for (int i = 0; i < q; ++i) {
      int l, r, d;
      scanf("%d %d %d", &l, &r, &d);
      --l;
      ve.push_back((Event){d, l, r, -1, i});
    }
    sort(ve.begin(), ve.end());
    int now = -1;
    build();
    for (int i = 0, j = 0; i < ve.size(); ++i) {
      if (now != ve[i].d) {
        while (j < i) {
          if (ve[j].id < 0) {
            update(ve[j].r, ve[j].til, -1);
          }
          ++j; 
        }
        now = ve[i].d;
      }
      if (ve[i].id < 0)
        update(ve[i].r, ve[i].til, +1);
      else {
        ans[ve[i].id] = get(ve[i].l, ve[i].r);
      }
    }
    for (int i = 0; i < q; ++i)
      printf("%lld\n", ans[i]);
  }
  close_file();
  return 0;
}