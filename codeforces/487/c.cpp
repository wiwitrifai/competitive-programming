#include <bits/stdc++.h>

using namespace std;

const int N = 105;

char s[N][N];

void isi(int row, char c) {
  for (int i = 0; i < 50; ++i)
    s[row][i] = c;
}
int main() {
  int a, b, c, d;
  scanf("%d %d %d %d", &a, &b, &c, &d);
  --a; --b;
  int n = 0;
  isi(n++, 'A');
  isi(n++, 'A');
  isi(n++, 'A');
  int now = 0;
  while (b + c + d > 0) {
    if (now >= 50) {
      isi(n++, 'A');
      isi(n++, 'A');
      now = 0;
    }
    if (b > 0)
      s[n-2][now] = 'B', --b;
    else if (c > 0)
      s[n-2][now] = 'C', --c;
    else if (d > 0)
      s[n-2][now] = 'D', --d;
    now += 2;
  }
  isi(n++, 'B');
  isi(n++, 'B');
  isi(n++, 'B');
  now = 0;
  while (a > 0) {
    if (now >= 50) {
      isi(n++, 'B');
      isi(n++, 'B');
      now = 0;
    }
    s[n-2][now] = 'A', --a;
    now += 2;
  }
  printf("%d %d\n", n, 50);
  for (int i = 0; i < n; ++i) {
    s[i][50] = 0;
    printf("%s\n", s[i]);
  }
  return 0;
}