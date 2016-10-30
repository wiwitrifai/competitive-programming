#include <bits/stdc++.h>

using namespace std;

const int N = 1e5 + 5, inf = 1e9, LN = 17;
int sum[N << 2], suml[N << 2], sumr[N << 2], best[N << 2], n, aa[N];
void build(int id = 1, int l = 0, int r = n) {
  if (r-l < 2) {
    sum[id] = suml[id] = sumr[id] = aa[l];
    best[id] = aa[l];
    return;
  }
  int mid = (l + r) >> 1, il = id << 1, ir = il | 1;
  build(il, l, mid);
  build(ir, mid, r);
  sum[id] = sum[il] + sum[ir];
  suml[id] = max(suml[il], sum[il] + suml[ir]);
  sumr[id] = max(sumr[ir], sum[ir] + sumr[il]);
  best[id] = max(max(best[il], best[ir]), suml[ir] + sumr[il]);
}

pair<pair<int, int>, pair<int, int> > get(int x, int y, int id = 1, int l = 0, int r = n) {
  if (x >= r || y <= l) return {{-inf, -inf}, {-inf, -inf}};
  if (x <= l && r <= y) return {{best[id], sum[id]}, {suml[id], sumr[id]}};
  int mid = (l + r) >> 1, il = id << 1, ir = il | 1;
  auto res1 = get(x, y, il, l, mid);
  auto res2 = get(x, y, ir, mid, r);
  if (res1.first.first == -inf)
    return res2;
  if (res2.first.first == -inf)
    return res1;
  pair< pair<int, int>, pair<int, int> > ret;
  ret.first.first = max(max(res1.first.first, res2.first.first), res1.second.second + res2.second.first);
  ret.first.second = res1.first.second + res2.first.second;
  ret.second.first = max(res1.second.first, res1.first.second + res2.second.first);
  ret.second.second = max(res2.second.second, res2.first.second + res1.second.second);
  return ret;
}
int stl[LN][N], str[LN][N];

int get_sparse(int x, int y, int sparse_table[LN][N]) {
  int ans = inf;
  if (y >= n) {
    y = n-1;
    ans = 0;
  }
  if (x < 0) {
    x = 0;
    ans = 0;
  }
  if (x > y)
    return 0;
  int len = y - x + 1;
  int llen = 31 - __builtin_clz(len);
  assert(x + (1<<llen) -1 <= y);
  return min(ans, min(sparse_table[llen][x], sparse_table[llen][y - (1<<llen) + 1]));
}


int main() {
  int t;
  scanf("%d", &t);
  while (t--) {
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
      scanf("%d", aa+i);
    int sum = 0;
    for (int i = 0; i < n; i++) {
      sum += aa[i];
      stl[0][i] = sum;
    }
    sum = 0;
    for (int i = n-1; i >= 0; i--) {
      sum += aa[i];
      str[0][i] = sum;
    }
    for (int i = 0; i+1 < LN; i++) {
      int len = 1<<(i);
      for (int j = 0; j <= n - 2 * len; j++) {
        stl[i+1][j] = min(stl[i][j], stl[i][j+len]);
        str[i+1][j] = min(str[i][j], str[i][j+len]);
      }
    }
    build();
    int m;
    scanf("%d", &m);
    while (m--) {
      int x, y, a, b;
      scanf("%d %d %d %d", &x, &y, &a, &b);
      x--; y--; a--; b--;
      if (y < a)
        printf("%d\n", sum - get_sparse(x-1, y-1, stl) - get_sparse(a+1, b+1, str));
      else {
        int ans = get(a, y+1).first.first;
        ans = max(ans, sum - min(get_sparse(x-1, y-1, stl) + get_sparse(y+1, b+1, str), get_sparse(x-1, a-1, stl) + get_sparse(a+1, b+1, str)));
        printf("%d\n", ans);
      }
    }
  }
  return 0;
}