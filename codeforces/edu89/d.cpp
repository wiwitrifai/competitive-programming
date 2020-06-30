#include <bits/stdc++.h>

using namespace std;

const int A = 1e7 + 5;

int pr[A];

int main() {
  for (int i = 2; i < A; ++i) {
    if (pr[i]) continue;
    for (int j = i; j < A; j += i) {
      if (pr[j] == 0)
        pr[j] = i;
    }
  }
  int n;
  scanf("%d", &n);
  vector<vector<int>> ans(2, vector<int>(n, -1));
  for (int i = 0; i < n; ++i) {
    int a;
    scanf("%d", &a);
    int p = pr[a];
    int pp = 1;
    while ((a % p) == 0) {
      pp *= p;
      a /= p;
    }
    if (a > 1 && pp > 1) {
      ans[0][i] = a;
      ans[1][i] = pp;
    }
  }
  for (int i = 0; i < 2; ++i) {
    for (int j = 0; j < n; ++j)
      printf("%d%c", ans[i][j], j+1 == n ? '\n' : ' ');
  }
  return 0;
}
