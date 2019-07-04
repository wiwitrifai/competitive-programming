#include <bits/stdc++.h>

using namespace std;

int ask(int r, int c) {
  printf("? %d %d\n", r, c);
  fflush(stdout);
  int d;
  scanf("%d", &d);
  return d;
}

void answer(int ra, int ca, int rb, int cb) {
  printf("! %d %d %d %d\n", ra, ca, rb, cb);
  fflush(stdout);
  exit(0);
}
int r, c, q;

bool valid(int rr, int cc) {
  return 1 <= rr && rr <= r && 1 <= cc && cc <= c;
}

int main() {
  scanf("%d %d %d", &r, &c, &q);
  int up_left = ask(1, 1);
  int up_right = ask(1, c);
  int down_left = ask(r, 1);
  int down_right = ask(r, c);
  if (((up_left + up_right - (c-1)) & 1) == 0 && ((down_left + down_right - (c-1)) & 1) == 0) {
    int ra = 1 + (up_left + up_right - (c-1)) / 2;
    int ca = 1 + (up_left - (ra - 1));
    int rb = r - (down_left + down_right - (c-1)) / 2;
    int cb = 1 + (down_left - (r - rb));
    if (valid(ra, ca) && valid(rb, cb) && ask(ra, ca) == 0) {
      answer(ra, ca, rb, cb);
    }
  }
  int ca = 1 + (up_left + down_left - (r-1)) / 2;
  int ra = 1 + (up_left - (ca - 1));
  int cb = c - (up_right + down_right - (r-1)) / 2;
  int rb = 1 + (up_right - (c - cb));
  answer(ra, ca, rb, cb);
  return 0;
}
