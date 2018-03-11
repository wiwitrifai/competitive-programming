#include <bits/stdc++.h>

using namespace std;

const int N = 100;

int a[N][N];

int main() {
  int n, m;
  scanf("%d %d", &n, &m);
  // for (int i = 0; i < n; ++i) {
  //   for (int j = 0; j < m; ++j) {
  //     for (int k = -1; k <= 1; ++k)
  //       for (int l = -1; l <= 1; ++l) {
  //         int x = i+k, y = j+l;
  //         if (min(x, y) < 0 || x >= n || y >= m) continue;
  //         a[x][y] ^= 1;
  //       }
  //   }
  // }
  // for (int i = 0; i < n; ++i) {
  //   for (int j = 0; j < m; ++j)
  //     cerr << a[i][j];
  //   cerr << endl;
  // }
  if (n > m) swap(n, m);
  if (n == 1 && m == 1) {
    puts("1");
    return 0;
  }
  if (n == 1)
    printf("%d\n", max(m-2, 0));
  else {
    long long ans = 1LL * n * m - n * 2 - m * 2 + 4;
    cout << ans << endl;
  }
  return 0;
}