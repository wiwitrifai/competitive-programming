#include <bits/stdc++.h>

using namespace std;

char s[55];

int main() {
  int t;
  scanf("%d", &t);
  while (t--) {
    int n, m;
    scanf("%d %d", &n, &m);
    scanf("%s", s);
    int x, y, xl, xh, yl, yh;
    x = y = 0;
    xl = xh = yl = yh = 0;
    int len = strlen(s);
    for (int i = 0; i < len; i++) {
      if (s[i] == 'U')
        y++;
      else if (s[i] == 'D')
        y--;
      else if (s[i] == 'L')
        x--;
      else
        x++;
      xl = min(xl, x);
      xh = max(xh, x);
      yl = min(yl, y);
      yh = max(yh, y);
    }
    puts(((xh-xl+1 > m) || (yh-yl+1 > n)) ? "unsafe" : "safe");
  }

  return 0;
}