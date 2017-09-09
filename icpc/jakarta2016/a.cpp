/**
 *  ACM ICPC Regional Jakarta 2016 - A : Confusing Date Format
 */

#include <bits/stdc++.h>

using namespace std;

int cnt[] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31}; 

bool valid(int d, int m, int y) {
  if (m < 1 || m > 12)
    return 0;
  int ma = cnt[m-1] + (m == 2 && (y % 4) == 0 && y != 0);
  if (d < 1 || d > ma)
    return 0;
  return 1;
}

int main() {
  int t;
  scanf("%d", &t);
  for (int tc = 1; tc <= t; tc++) {
    int a[3];
    scanf("%d-%d-%d", a, a+1, a+2);
    int ans;
    if (a[0] == 4 && a[1] == 5 && a[2] == 1) {
      ans = 1;
    }
    else {
      sort(a, a+3);
        ans = 0;
      do {
        ans += valid(a[0], a[1], a[2]);
      } while (next_permutation(a, a+3));
    }
    printf("Case #%d: %d\n",tc, ans);
  }
  return 0;
}