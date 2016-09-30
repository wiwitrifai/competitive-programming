#include <bits/stdc++.h>

using namespace std;

int m, p[13];
int a, b, c;

int main() {
  scanf("%d", &m);
  for (int i = 0; i < 12; i++)
    scanf("%d", p+i);
  c = 0;
  for (int i = 0; i < 12; i++) {
    for (int j = i+1; j < 12; j++) if (p[i] < p[j]) {
      int now = m/p[i];
      int pnow = now * (p[j] - p[i]);
      if (pnow > c || (c == pnow && p[i] < p[a])) {
        c = pnow;
        a = i;
        b = j;
      }
    }
  }
  if (c) {
    printf("%d %d %d\n", a+1, b+1, c);
  }
  else
    puts("IMPOSSIBLE");
  return 0;
}