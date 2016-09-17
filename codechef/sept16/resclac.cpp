#include <bits/stdc++.h>

using namespace std;

const int N = 1e5 + 5;

int a[10];

int main() {
  int t;
  scanf("%d", &t);
  while (t--) {
    int n;
    scanf("%d", &n);
    int ans = 0, cnt = -1;
    for (int i = 1; i <= n; i++) {
      int k;
      scanf("%d", &k);
      memset(a, 0, sizeof a);
      int tmp = k;
      while (k--) {
        int x;
        scanf("%d", &x);
        a[x]++;
      }
      int df = 4, sub = 0;
      sort(a + 1, a + 7);
      for (int j = 1; j <= 3; j++) {
        a[j] -= sub;
        tmp += df * a[j];
        sub += a[j];
        df >>= 1;
      }
      if (tmp >  cnt) {
        ans = i;
        cnt = tmp;
      }
      else if (tmp == cnt) {
        ans = 0;
      }
    }
    if (ans == 0)
      puts("tie");
    else if (ans == 1)
      puts("chef");
    else
      printf("%d\n", ans);
  }
  return 0;
}