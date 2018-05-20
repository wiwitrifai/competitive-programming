#include <bits/stdc++.h>

using namespace std;

const int N = 505;

int b[N], a[N];
char ans[N][N];

int main() {
  int tt;
  scanf("%d", &tt);
  for (int tc = 1; tc <= tt; ++tc) {
    printf("Case #%d: ", tc);
    int c;
    scanf("%d", &c);
    int sum = 0;
    for (int i = 0; i < c; ++i)
      scanf("%d", b+i), sum += b[i];
    if (sum != c || b[0] == 0 || b[c-1] == 0) {
      puts("IMPOSSIBLE");
      continue;
    }
    for (int i = 0, j = 0; i < c; ++i) {
      while (b[i] > 0) {
        a[j++] = i;
        --b[i];
      }
    }
    int ma = 0;
    for (int i = 0; i < c; ++i)
      ma = max(ma, abs(a[i]-i));
    ++ma;
    for (int j = 0; j < ma; ++j) {
      for (int i = 0; i < c; ++i)
        ans[j][i] = '.';
      ans[j][c] = '\0';
    }
    for (int i = 0; i < c; ++i) {
      if (a[i] < i) {
        for (int j = 0; j < abs(i-a[i]); ++j)
          ans[j][i-j] = '/';
      }
      else if (a[i] > i) {
        for (int j = 0; j < abs(i-a[i]); ++j)
          ans[j][i+j] = '\\';
      }
    }
    printf("%d\n", ma);
    for (int i = 0; i < ma; ++i)
      printf("%s\n", ans[i]);
  }
  return 0;
}