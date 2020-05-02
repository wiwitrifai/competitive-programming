#include <bits/stdc++.h>

using namespace std;

int val[5][5] = {
{1, 1, 1, 0, 0},
{1, 1, 1, 0, 0},
{1, 1, 0, 0, 0},
{0, 0, 0, 0, 0},
{0, 0, 0, 0, 0}};

int solve(long long x, long long y, long long pw, int ori) {
  if (pw == 1) {
    if (ori) return 0;
    return (x == 1) && (y == 1);
  }
  pw /= 2;
  if (val[(x+pw-1)/pw][(y+pw-1)/pw])
    return solve(x, y, pw, ori);
  if (val[((4 * pw - x)+pw-1)/pw][(y+pw-1)/pw])
    return solve(y, 4 * pw - x, pw, (ori+1) % 4);
  if (val[(x+pw-1)/pw][(4 * pw - y +pw-1)/pw])
    return solve(4 * pw - y, x, pw, (ori+3) % 4);
  return solve(x-pw, y-pw, pw, ori);
}

int main() {
  int q;
  scanf("%d", &q);
  while (q--) {
    long long x, y;
    scanf("%lld %lld", &x, &y);
    long long pw = 1;
    while (pw <= max(x, y)) pw *= 2;
    printf("%lld\n", x + y + 2LL * solve(x, y, pw, 0));
  }
  return 0;
}
