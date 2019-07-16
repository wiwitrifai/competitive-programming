#include <bits/stdc++.h>

using namespace std;

const int N = 1024;

int c[N][N];

int cnt[N], pr[N * N];

int main() {
  int n;
  scanf("%d", &n);
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < n; ++j) {
      scanf("%d", c[i]+j);
    }
  }
  for (int i = 2; i < N; ++i) {
    if (pr[i]) continue;
    for (int j = i; j < N * N; j += i)
      if (pr[j] == 0)
        pr[j] = i; 
  }
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < n; ++j) {
      if (i == n-1 && j == n-1) continue;
      int now = c[i][j];
      while (now > 1) {
        int p = pr[now];
        ++cnt[p];
        now /= p;
      }
    }
  }
  int ans = 1;
  for (int i = 1; i < N; ++i) {
    if (cnt[i] % n) {
      int pw = n - (cnt[i] % n);
      while (pw--) {
        ans *= i;
      }
    }
  }
  printf("%d\n", ans);
  return 0;
}
