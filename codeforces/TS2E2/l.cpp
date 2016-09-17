#include <bits/stdc++.h>

using namespace std;

int r[1024], b[1024], nr, nb;

int main() {
  int n;
  nr = nb = 0;
  scanf("%d", &n);
  for (int i = 0; i < n; i++) {
    int x;
    char c;
    scanf("%d%c", &x, &c);
    if (c == 'B')
      b[nb++] = x;
    else
      r[nr++] = x;
  }
  sort(b, b+nb);
  sort(r, r+nr);
  int ans = 0;
  while (nb > 0 && nr > 0) {
    nb--;
    nr--;
    ans += b[nb] + r[nr] - 2;
  }
  printf("%d\n", ans);

  return 0;
}