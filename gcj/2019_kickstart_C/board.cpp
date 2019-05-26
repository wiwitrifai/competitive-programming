#include <bits/stdc++.h>

using namespace std;

const int N = 333;

int b[N][N];
int cnt[N];

void solve(int tc) {
  int r, c, k;
  scanf("%d %d %d", &r, &c, &k);
  for (int i = 0; i < r; ++i) {
    for (int j = 0; j < c; ++j)
      scanf("%d", b[i]+j);
  }
  int ans = 0;
  for (int f = 0; f < c; ++f) {
    for (int i = 0; i < r; ++i) {
      int j = f;
      int ma = b[i][f], mi = b[i][f];
      while (j < c && max(ma, b[i][j]) - min(mi, b[i][j]) <= k) {
        ma = max(ma, b[i][j]);
        mi = min(mi, b[i][j]);
        ++j;
      }
      cnt[i] = j-f;
    }
    for (int i = 0; i < r; ++i) {
      int mi = cnt[i];
      for (int j = i; j < r; ++j) {
        mi = min(mi, cnt[j]);
        ans = max(ans, mi * (j - i + 1));
      }
    }
  }
  printf("Case #%d: %d\n", tc, ans);
}

int main() {
  time_t startt = clock();
  int tt;
  scanf("%d", &tt);
  for (int tc = 1; tc <= tt; tc++) {
    solve(tc);
    cerr << "~ #" << tc << " done! time : " << (double)(clock()-startt)/CLOCKS_PER_SEC << " s" << endl;
  }
  return 0;
}
