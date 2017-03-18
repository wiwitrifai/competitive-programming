#include <bits/stdc++.h>

using namespace std;

const int N = 5050;

int a[N], n, k;
bool dl[N][N], dr[N][N];

int main() {
  memset(dl, 0, sizeof dl);
  memset(dr, 0, sizeof dr);
  scanf("%d %d", &n, &k);
  for (int i = 0; i < n; i++)
    scanf("%d", a+i);
  dl[0][0] = 1;
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < k; j++) if (dl[i][j]) {
      dl[i+1][j] = 1;
      if (j + a[i] < k)
        dl[i+1][j+a[i]] = 1;
    }
  }
  dr[n-1][0] = 1;
  for (int i = n-1; i > 0; i--) {
    for (int j = 0; j < k; j++) if (dr[i][j]) {
      dr[i-1][j] = 1;
      if (j + a[i] < k)
        dr[i-1][j+a[i]] = 1;
    }
  }
  int ans = 0;
  for (int i = 0; i < n; i++) {
    int it = k-1;
    bool ok = 1;
    for (int j = 0; j < k; j++) if (dl[i][j]) {
      it = min(it, k-1-j);
      while (it >= 0 && !dr[i][it]) it--;
      if (it >= 0 && it + j < k && it + j + a[i] >= k) {
        ok = 0;
        break;
      }
    }
    ans += ok;
  }
  printf("%d\n", ans);
  return 0;
}