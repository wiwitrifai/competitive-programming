#include <bits/stdc++.h>

using namespace std;

const int N = 5e5 + 5, S = sqrt(N);

int small[S][S];
int cnt[N];

int main() {
  int q;
  scanf("%d", &q);
  for (int i = 0; i < q; ++i) {
    int t, x, y;
    scanf("%d %d %d", &t, &x, &y);
    if (t == 1) {
      cnt[x] += y;
      for (int mod = 1; mod < S; ++mod)
        small[mod][x % mod] += y;
    }
    else {
      if (x < S) {
        printf("%d\n", small[x][y]);
      }
      else {
        int ans = 0;
        while (y < N) {
          ans += cnt[y];
          y += x;
        }
        printf("%d\n", ans);
      }
    }
  }

  return 0;
}
