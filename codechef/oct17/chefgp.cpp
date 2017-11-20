#include <bits/stdc++.h>

using namespace std;

const int N = 1e5 + 5;

char s[N];

int fa[N], fb[N];

void printa(int x, char a) {
  if (x == 0)
    printf("*");
  else
    while (x-- > 0)
      printf("%c", a);
}

int main() {
  int t;
  scanf("%d", &t);
  while (t--) {
    scanf("%s", s);
    int a = 0, b = 0, n = strlen(s), x, y;
    scanf("%d %d", &x, &y);
    for (int i = 0; i < n; i++) {
      a += s[i] == 'a';
      b += s[i] == 'b';
    }
    int ga = (a + x - 1) / x, gb = (b + y - 1) / y;
    if (ga < gb)
      ga = gb-1;
    if (gb < ga)
      gb = ga-1;
    for (int i = 0; i < ga; i++) {
      fa[i] = min(1, a);
      a -= fa[i];
    }
    for (int i = 0; i < ga; i++) {
      a += fa[i];
      fa[i] = min(a, x);
      a -= fa[i];
    }
    for (int i = 0; i < gb; i++) {
      fb[i] = min(1, b);
      b -= fb[i];
    }
    for (int i = 0; i < gb; i++) {
      b += fb[i];
      fb[i] = min(b, y);
      b -= fb[i];
    }
    if (ga >= gb) {
      for (int i = 0; i < ga; i++) {
        printa(fa[i], 'a');
        if (i < gb) {
          printa(fb[i], 'b');
        }
      }
    }
    else {
      for (int i = 0; i < gb; i++) {
        printa(fb[i], 'b');
        if (i < ga) {
          printa(fa[i], 'a');
        }
      }
    }
    printf("\n");
  }
  return 0;
}