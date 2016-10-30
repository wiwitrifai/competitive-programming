#include <bits/stdc++.h>

using namespace std;

long long a[4][4];

int main() {
  int t;
  scanf("%d", &t);
  while (t--) {
    for (int i = 0; i < 3; i++)
      for (int j = 0; j < 3; j++)
        scanf("%lld", a[i]+j);
    long long ans = 0;
    for (int i = 0; i < 3; i++) {
      long long sumr = 0, sumc = 0;
      for (int j = 0; j < 3; j++) {
        sumr += a[i][j];
        sumc += a[j][i];
      }
      if ((sumc & 1) == 0)
        sumc--;
      if ((sumr & 1) == 0)
        sumr--;
      ans = max(ans, max(sumc, sumr));
    }
    printf("%lld\n", ans);
  }
  return 0;
}