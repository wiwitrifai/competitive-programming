#include <bits/stdc++.h>

using namespace std;

bool check_win(long long s, long long e, bool odd, bool even) {
  long long r = e, l = e / 2 + 1;
  while (s < l) {
    long long nr = l-1, nl = nr / 2 + 1;
    bool nodd = false, neven = false;
    if (nr & 1) {
      nodd = !even;
      neven = !nodd;
    } else {
      neven = !odd;
      nodd = !neven;
    }
    if (!even) {
      nodd = neven = true;
    }
    even = neven;
    odd = nodd;
    l = nl;
    r = nr;
  }
  return (s & 1) ? odd : even;
}

int main() {
  int t;
  scanf("%d", &t);
  bool win = false, lose = true;
  while (t--) {
    long long s, e;
    scanf("%lld %lld", &s, &e);
    bool canwin = false, canlose = false;
    bool res1 = check_win(s, e, (e & 1) != 1, (e & 1) != 0);
    if (res1) {
      canwin |= lose;
    } else {
      canwin |= win;
    }
    bool res2 = check_win(s, e, true, true);
    if (res2) {
      canlose |= lose;
    } else {
      canlose |= win;
    }
    win = canwin;
    lose = canlose;
  }
  printf("%d %d\n", (int)win, (int)lose);
  return 0;
}
