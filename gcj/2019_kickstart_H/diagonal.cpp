#include <bits/stdc++.h>

using namespace std;

const int N = 212;

int n;
char s[N][N];

void read_input() {
  scanf("%d", &n);
  for (int i = 0; i < n; ++i)
    scanf("%s", s[i]);
}

void solve() {
  int cnt[2], tot[2];
  cnt[0] = cnt[1] = 0;
  tot[0] = tot[1] = 0;
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < n; ++j)
      s[i][j] = s[i][j] == '#';
  }
  for (int i = 0; i < n; ++i) {
    if (s[i][i] == 0) {
      int r = i, c = i;
      while (r >= 0 && c < n) {
        s[r][c] ^= 1;
        --r, ++c;
      }
      r = i+1, c = i-1;
      while (r < n && c >= 0) {
        s[r][c] ^= 1;
        ++r, --c;
      }
      ++cnt[0];
    }
    ++tot[0];
  }
  for (int i = 0; i < n-1; ++i) {
    if (s[i][i+1] == 0) {
      int r = i, c = i+1;
      while (r >= 0 && c < n) {
        s[r][c] ^= 1;
        --r, ++c;
      }
      r = i+1, c = i;
      while (r < n && c >= 0) {
        s[r][c] ^= 1;
        ++r, --c;
      }
      ++cnt[1];
    }
    ++tot[1];
  }

  for (int i = 0; i < n; ++i) {
    if (s[i][n-1-i] == 0) {
      ++cnt[(n-1) & 1];
    }
    ++tot[(n-1) & 1];
  }
  for (int i = 0; i < n-1; ++i) {
    if (s[i][n-2-i] == 0) {
      ++cnt[n & 1];
    }
    ++tot[n & 1];
  }
  int ans = min(cnt[0], tot[0] - cnt[0]) + min(cnt[1], tot[1] - cnt[1]);
  printf("%d\n", ans);
}

int main() {
#ifdef LOCAL
  time_t starttime = clock();
#endif
  int tt;
  scanf("%d", &tt);
  for (int tc = 1; tc <= tt; tc++) {
    printf("Case #%d: ", tc);
    read_input();
    solve();
#ifdef LOCAL
    cerr << "~ TC#" << tc << " done! execution time: " <<
      (double)(clock()-starttime) / CLOCKS_PER_SEC << " s" << endl;
#endif
  }
  return 0;
}
