#include <bits/stdc++.h>

using namespace std;

const int N = 3003, mod = 1e9 + 7;

int ans[N][N];

int main() {
  ans[0][0] = 1;
  for (int i = 0; i + 1 < N; i++) {
    for (int j = 0; j <= i; j++) {
      int ajeg = 2 * j, olih = i+1 - ajeg;
      if (olih < 0) continue;
      ans[i+1][j] = (ans[i+1][j] + 1LL * ajeg * ans[i][j]) % mod;
      ans[i+1][j+1] = (ans[i+1][j+1] + 1LL * olih * ans[i][j]) % mod;
    }
    for (int j = 1; j <= i; j++) {
      ans[i][j] += ans[i][j-1];
      if (ans[i][j] >= mod) ans[i][j] -= mod;
    }
  } 
  int q;
  scanf("%d", &q);
  for (int i = 0; i < q; ++i) {
    int a, b;
    scanf("%d %d", &a, &b);
    printf("%d\n", ans[a][a-b]);
  }
  return 0;
}