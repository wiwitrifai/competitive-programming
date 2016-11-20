#include <bits/stdc++.h>

using namespace std;
const int N = 1e6 + 9;
char a[N];

int main() {
  freopen("boysgirls.in", "r", stdin);
  freopen("boysgirls.out", "w", stdout);

  int n, x, y;
  scanf("%d %d %d", &n, &x, &y);
  swap(x, y);
  x = n-x; y = n-y;
  if (((x + y) & 1) != (n & 1)) {
    puts("Impossible");
    return 0;
  }
  if ((x+y) > n) {
    puts("Impossible");
    return 0;
  }
  if ((x+y) == n) {
    if (x == y) {
      for (int i = 0; i < x; i++)
        printf("BG");
      printf("\n");
      return 0;
    }
    else if (x == 0) {
      for (int i = 0; i < n; i++)
        printf("G");
      printf("\n");
      return 0;
    } 
    else if (y == 0) {
      for (int i = 0; i < n; i++)
        printf("B");
      printf("\n");
      return 0;
    }
    else {
      puts("Impossible");
      return 0;
    }
  }
  if (n & 1) {
    int now = 0, cnt = 0;
    for (int i = 0; i <= x; i++) {
      a[now] = 'B';
      now = (now + 2) % n;
      cnt++;
    }
    for (int i = 0; i <= y; i++) {
      a[now] = 'G';
      now = (now + 2) % n;
      cnt++;
    }
    char c = 'B';
    while (cnt < n) {
      a[now] = c;
      now = (now + 2) % n;
      c = 'B'+ 'G' - c;
      cnt++;
    }
    a[n] = '\0';
    printf("%s\n", a);
  }
  else {
    if (x == n/2-1 && y == n/2-1) {
      puts("Impossible");
      return 0;
    }
    int xx = min(x, n/2), yy = 0;
    while ((x - xx + y - yy > n/2 || ((xx + yy) & 1) != ((n/2) & 1)) && y > yy) 
      yy++;
    while (((xx + yy) & 1) != ((n/2) & 1) && xx > 0) xx--;
    if (((xx+yy) & 1) != ((n/2)&1)) {
      puts("Impossible");
      return 0;
    }
    int now = 0;
    if (xx)
      for (int i = 0; i <= xx; i++) if (now < n) {
        a[now] = 'B';
        now += 2;
      }
    for (int j = 0; j <= yy; j++) if (now < n) {
      a[now] = 'G';
      now += 2;
    }
    char c = 'B';
    while (now < n) {
      a[now] = c;
      c = 'B' + 'G' - c;
      now += 2;
    }
    xx = x-xx; yy = y - yy;
    now = 1;
    if (xx)
      for (int i = 0; i <= xx; i++) if (now < n) {
        a[now] = 'B';
        now += 2;
      }
    for (int j = 0; j <= yy; j++) if (now < n) {
      a[now] = 'G';
      now += 2;
    }
    c = 'B';
    while (now < n) {
      a[now] = c;
      c = 'B' + 'G' - c;
      now += 2;
    }
    a[n] = '\0';
    printf("%s\n", a);
  }
  return 0;
}