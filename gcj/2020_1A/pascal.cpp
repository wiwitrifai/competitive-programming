#include <bits/stdc++.h>

using namespace std;

void solve() {
  int n;
  scanf("%d", &n);
  if (n <= 100) {
    for (int i = 1; i <= n; ++i) {
      printf("%d 1\n", i);
    }
    return;
  }
  int x = n - 30;
  bool left = true;
  printf("1 1\n");
  --n;
  for (int i = 1; i <= 30; ++i) {
    if ((x >> i) & 1) {
      if (left) {
        for (int j = 1; j <= i+1; ++j) {
          printf("%d %d\n", i+1, j);
        }
      }
      else {
        for (int j = i+1; j > 0; --j) {
          printf("%d %d\n", i+1, j);
        }
      }
      left = !left;
      n -= (1 << i);
    }
    else {
      --n;
      printf("%d %d\n", i+1, left ? 1 : i+1);
    }
  }
  int now = 32;
  while (n > 0) {
    printf("%d %d\n", now, left ? 1 : now);
    --n;
    ++now;
  }
}

int main() {
#ifdef LOCAL
  time_t starttime = clock();
#endif
  int tt;
  scanf("%d", &tt);
  for (int tc = 1; tc <= tt; tc++) {
    printf("Case #%d:\n", tc);
    solve();
#ifdef LOCAL
    cerr << "~ TC#" << tc << " done! execution time: " <<
      (double)(clock()-starttime) / CLOCKS_PER_SEC << " s" << endl;
#endif
  }
  return 0;
}
