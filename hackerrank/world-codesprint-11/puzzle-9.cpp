#include <bits/stdc++.h>

using namespace std;

const int N = 1505, M = 1024 * 4;

struct figure {
  vector< pair< int, int > > a;
  int r, c;
  figure() {}
  void rotate() {
    for (auto &it : a)
      it = make_pair(c-1-it.second, it.first);
    swap(r, c);
  }
};

figure fig[N];

bool a[155][155];
int bs[M + M][M + M];
int l, r, u, d, n, id[N];
time_t startt;

void solve_one() {  
  int c = 0, mc = 0;
  for (int i = 0; i < n; i++) {
    c = max(c, min(fig[i].r, fig[i].c));
    mc = max(mc, max(fig[i].r, fig[i].c));
  }
  int bc = c, rr = mc * n;
  while (c <= mc) {
    int cur = 0;
    for (int i = 0; i < n; i++) {
      int x = fig[i].c, y = fig[i].r;
      if (x > c) swap(x, y);
      if (y > x && y <= c)
        swap(x, y);
      cur += y;
    }
    if (cur < rr)
      bc = c, rr = cur;
    c++;
  }
  printf("%d %d\n", rr, bc);
  for (int i = 0; i < n; i++) {
    if (fig[i].c > bc || (fig[i].r > fig[i].c && fig[i].r <= bc))
      fig[i].rotate();
    memset(a, 0, sizeof a);
    for (auto it : fig[i].a)
      a[it.first][it.second] = 1;
    for (int x = 0; x < fig[i].r; x++) {
      for (int y = 0; y < bc; y++) {
        printf("%d ", a[x][y] ? i+1 : 0);
      }
      printf("\n");
    }
  }
}
bool cek(const figure & f, int offr, int offc) {
  for (auto it : f.a)
    if (bs[offr+it.first][offc+it.second]) return false;
  return true;
}
void mark(const figure & f, int offr, int offc, int val) {
  for (auto it : f.a)
    bs[offr+it.first][offc+it.second] = val;
}
bool solve_two() {
  for (int i = 0; i < n; i++)
    id[i] = i;
  sort(id, id+n, [](int le, int ri) {
    return fig[le].a.size() > fig[ri].a.size();
  });
  l = r = d = u = M;
  for (int i = 0; i < n; i++) {
    int now = id[i];
    vector< pair<int, pair< int, int > > > idx;
    for (int row = max(0, u-fig[now].r); row <= min(M+M-fig[now].r, d); row++) {
      for (int col = max(0, l-fig[now].c); col <= min(M+M-fig[now].c, r); col++) {
        int dr = max(row+fig[now].r, d) - min(row, u), dc = max(col+fig[now].c, r) - min(col, l);
        idx.push_back({dr * dc, {row, col}});
      }
    }
    sort(idx.begin(), idx.end());
    bool ok = 0;
    for (auto it : idx) {
      if (cek(fig[now], it.second.first, it.second.second)) {
        mark(fig[now], it.second.first, it.second.second, now+1);
        u = min(it.second.first, u);
        d = max(it.second.first+fig[now].r, d);
        l = min(it.second.second, l);
        r = max(it.second.second+fig[now].c, r);
        ok = 1;
        break;
      }
      if (((double)(clock()-startt) * 1000/CLOCKS_PER_SEC) > 1990) return false;
    }
    if (!ok) return false;
  }
  printf("%d %d\n", d-u, r-l);
  for (int i = u; i < d; i++) {
    for (int j = l; j < r; j++) {
      printf("%d ", bs[i][j]);
    }
    printf("\n");
  }
  return true;
}


bool solve_three() {
  for (int i = 0; i < n; i++)
    id[i] = i;
  sort(id, id+n, [](int le, int ri) {
    return fig[le].a.size() > fig[ri].a.size();
  });
  l = r = d = u = M;
  for (int i = 0; i < n; i++) {
    int now = id[i], offr = d, offc = r, rot = 0, sz = 1e9 + 7;
    bool ok = 0;
    for (int z = 0; z < 2; z++) {
      vector< pair<int, pair< int, int > > > idx;
      for (int row = max(0, u-fig[now].r); row <= min(M+M-fig[now].r, d); row++) {
        for (int col = max(0, l-fig[now].c); col <= min(M+M-fig[now].c, r); col++) {
          int dr = max(row+fig[now].r, d) - min(row, u), dc = max(col+fig[now].c, r) - min(col, l);
          idx.push_back({dr * dc, {row, col}});
        }
      }
      sort(idx.begin(), idx.end());
      figure opp = fig[now];
      opp.rotate();
      opp.rotate();
      for (auto it : idx) {
        if (cek(fig[now], it.second.first, it.second.second)) {
          if (sz > it.first) {
            sz = it.first;
            rot = z;
            offr = it.second.first;
            offc = it.second.second;
          }
          ok = 1;
          break;
        }
        if (cek(opp, it.second.first, it.second.second)) {
          if (sz > it.first) {
            sz = it.first;
            rot = 2 + z;
            offr = it.second.first;
            offc = it.second.second;
          }
          ok = 1;
          break;
        }
        if (((double)(clock()-startt) * 1000/CLOCKS_PER_SEC) > 1990) return false;
      }
      fig[now].rotate();
    }
    if (!ok) return false;
    rot = (rot + 2) % 4;
    while (rot > 0)
      fig[now].rotate(), rot--;
    mark(fig[now], offr, offc, now+1);
    u = min(offr, u);
    d = max(offr+fig[now].r, d);
    l = min(offc, l);
    r = max(offc+fig[now].c, r);
  }
  printf("%d %d\n", d-u, r-l);
  for (int i = u; i < d; i++) {
    for (int j = l; j < r; j++) {
      printf("%d ", bs[i][j]);
    }
    printf("\n");
  }
  return true;
}



int main() {
  startt = clock();
  scanf("%d", &n);
  int sum = 0;
  for (int i = 0; i < n; i++) {
    int m;
    scanf("%d", &m);
    fig[i].a.clear();
    fig[i].r = fig[i].c = 0;
    for (int j = 0; j < m; j++) {
      int x, y;
      scanf("%d %d", &x, &y);
      x--; y--;
      fig[i].a.emplace_back(x, y);
      fig[i].r = max(fig[i].r, x+1);
      fig[i].c = max(fig[i].c, y+1);
    }
    sum += m;
  }
  if (sum <= 7500) {
    assert(solve_three());
  }
  else {
    if (!solve_two())
      solve_one();
  }
  return 0;
}