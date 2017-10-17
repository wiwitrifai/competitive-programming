#include <bits/stdc++.h>

using namespace std;

int mm[] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

bool isleap(int y) {
  if ((y % 400) == 0) return 1;
  if ((y % 100) == 0) return 0;
  return (y % 4) == 0;
}

int da, ma, db, mb, dc, mc;

bool isspecial(int t, int d, int m) {
  if ((t % 100) == 0)
    return 1;
  if (d == da && m == ma)
    return 1;
  if (d == db && m == mb)
    return 1;
  if (d == dc && m == mc)
    return 1;
  return 0;
}

int d, m, y;
void next() {
  int cnt = mm[m-1];
  if (m == 2 && isleap(y))
    cnt++;
  d++;
  if (d > cnt) {
    d = 1;
    m++;
    if (m > 12) {
      m = 1;
      y++;
    }
  }
}

int main() {
  scanf("%d/%d/%d", &d, &m, &y);
  dc = d;
  mc = m;
  scanf("%d/%d", &da, &ma);
  scanf("%d/%d", &db, &mb);
  int ans = 0;
  for (int i = 1; i <= 2048; i++) {
    next();
    ans += isspecial(i, d, m);
  }
  printf("%d\n", ans);
  return 0;
}