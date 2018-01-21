#include <bits/stdc++.h>

using namespace std;

int main() {
  int x, h, m;
  scanf("%d %d %d", &x, &h, &m);
  int now = h * 60 + m;
  int mod = 24 * 60;
  if (now < 0) now += mod;
  int y = 0;
  while (1) {
    int hh = now/60, mm = now % 60;
    if ((hh % 10 == 7) || (mm % 10 == 7) || (hh/10 == 7) || (mm/10 == 7)) {
      printf("%d\n", y);
      return 0;
    }
    ++y;
    now -= x;
    now %= mod;
    if (now < 0) now += mod;
  }
  return 0;
}