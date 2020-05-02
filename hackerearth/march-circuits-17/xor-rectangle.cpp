#include <bits/stdc++.h>

using namespace std;

const int N = 1e6 + 7;

int bit[20][N];
int a[N], n, q, xl, xr, yl, yr;

int main() {
  scanf("%d", &n);
  for (int i = 0; i < n; i++) {
    scanf("%d", a+i);
    for (int j = 0; j < 20; j++)
      bit[j][i+1] = bit[j][i] + ((a[i] & (1<<j)) ? 1 : 0);
  }
  scanf("%d", &q);
  while (q--) {
    scanf("%d %d %d %d", &xl, &yl, &xr, &yr);
    xl--; yl--;
    long long ans = 0;
    for (int i = 0; i < 20; i++) {
      long long onex = bit[i][xr]-bit[i][xl], oney = bit[i][yr]-bit[i][yl],
      zerox = xr-xl-onex, zeroy = yr-yl-oney;
      ans += (onex * zeroy + oney * zerox) << i;
    }
    printf("%lld\n", ans);
  }

  return 0;
}