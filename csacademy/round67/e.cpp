#include <bits/stdc++.h>

using namespace std;

const int N = 1 << 16, M = 1 << 8;

int cnt[M][M][9];
int ans[17];

int main() {
  int n, m;
  scanf("%d %d", &n, &m);
  int mid = (m + 1) / 2, mid2 = m - mid;
  int full = (1 << mid) - 1;
  int full2 = (1 << mid2) - 1;
  while (n--) {
    int x;
    scanf("%d", &x);
    int up = x >> mid, down = x & full;
    for (int i = 0; i <= m; ++i)
      ans[i] = 0;
    for (int i = 0; i <= full2; ++i) {
      int cur = __builtin_popcount(i ^ up);
      for (int j = 0; j <= mid; ++j)
        ans[cur+j] += cnt[i][down][j];
    }
    for (int i = 0; i <= m; ++i)
      printf("%d%c", ans[i], i == m ? '\n' : ' ');
    for (int i = 0; i <= full; ++i) {
      ++cnt[up][i][__builtin_popcount(i^down)];
    }
  }
  return 0;
}