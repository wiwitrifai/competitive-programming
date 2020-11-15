#include <bits/stdc++.h>

using namespace std;

vector<tuple<int, int, int, int>> chips;
int a, b, c, m;
vector<tuple<int, int, int, int, int, int>> answer;

void solvez(int l, int r, int xl, int xr, int yl, int yr) {
  int zl = 1;
  for (int i = l; i < r;) {
    int zr = get<2>(chips[i]);
    int from = i;
    while (i < r && get<2>(chips[i]) == zr) ++i;
    if (i == r)
      zr = c;
    assert(from + 1 == i);
    answer[get<3>(chips[from])] = make_tuple(xl, yl, zl, xr, yr, zr);
    zl = zr + 1;
  }
}

void solvey(int l, int r, int xl, int xr) {
  int yl = 1;
  for (int i = l; i < r;) {
    int yr = get<1>(chips[i]);
    int from = i;
    while (i < r && get<1>(chips[i]) == yr) ++i;
    if (i == r)
      yr = b;
    solvez(from, i, xl, xr, yl, yr);
    yl = yr + 1;
  }
}

void solvex(int l, int r) {
  int xl = 1;
  for (int i = l; i < r;) {
    int xr = get<0>(chips[i]);
    int from = i;
    while (i < r && get<0>(chips[i]) == xr) ++i;
    if (i == r)
      xr = a;
    solvey(from, i, xl, xr);
    xl = xr + 1;
  }
}

int main() {
  scanf("%d", &a);
  while (a != -1) {
    scanf("%d %d %d", &b, &c, &m);
    chips.resize(m);
    answer.resize(m);
    for (int i = 0; i < m; ++i) {
      int x, y, z;
      scanf("%d %d %d", &x, &y, &z);
      chips[i] = make_tuple(x, y, z, i);
    }
    sort(chips.begin(), chips.end());
    puts("YES");
    solvex(0, m);
    for (auto & ans : answer) {
      int xl, yl, zl, xr, yr, zr;
      tie(xl, yl, zl, xr, yr, zr) = ans;
      printf("%d %d %d %d %d %d\n", xl, yl, zl, xr, yr, zr);
    }
    scanf("%d", &a);
  }

  return 0;
}
