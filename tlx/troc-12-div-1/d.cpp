#include <bits/stdc++.h>

using namespace std;

const int inf = 1e9 + 7, LG = 30, N = 1e5 + 5;

int all[LG][N];

int main() {
  int a, b, ka, kb, la, lb;
  scanf("%d %d %d %d %d %d", &a, &b, &ka, &kb, &la, &lb);
  int ab = a * b;
  for (int i = 0; i < ab; ++i) {
    if ((i % a) == ka) {
      all[0][i] = la;
    }
    else if ((i % b) == kb) {
      all[0][i] = lb;
    }
    else
      all[0][i] = 1;
  }
  for (int i = 0; i + 1 < LG; ++i) {
    for (int j = 0; j < ab; ++j) {
      int now = j - all[i][j];
      now %= ab;
      if (now < 0)
        now += ab;
      all[i+1][j] = min(all[i][now] + all[i][j], inf);
    }
  }
  auto get = [&](int low, int x) {
    int r = x % ab;
    int cnt = 0;
    for (int i = LG-1; i >= 0; --i) {
      if (x - low >= all[i][r]) {
        x -= all[i][r];
        r = x % ab;
        cnt += 1 << i;
      }
    }
    return make_pair(x, cnt);
  };
  int q;
  scanf("%d", &q);
  while (q--) {
    int x, y;
    scanf("%d %d", &x, &y);
    auto resx = get(1, x);
    auto resy = get(1, y);
    if (resx.first != resy.first) {
      puts("-1");
      continue;
    }
    if (resx.second < resy.second) {
      swap(x, y);
      swap(resx, resy);
    }
    int d = resx.second - resy.second;
    if (d > 0) {
      for (int i = 0; i < LG; ++i) {
        if (d & (1 << i)) {
          x -= all[i][x % ab];
        }
      }
    }
    if (x == y) {
      printf("%d\n", x);
      continue;
    }
    for (int i = LG-1; i >= 0; --i) {
      int xx = x - all[i][x % ab];
      int yy = y - all[i][y % ab];
      if (xx > 0 && yy > 0 && xx != yy) {
        x = xx;
        y = yy;
      }
    }
    assert(x != y);
    x -= all[0][x % ab];
    y -= all[0][y % ab];
    printf("%d\n", x);
  }
  return 0;
}
