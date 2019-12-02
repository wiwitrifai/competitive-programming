#include <bits/stdc++.h>

using namespace std;

const int N = 1024;

int cnt[256];
char s[N * N];
char ans[N][N];

int main() {
  int n, l, k;
  scanf("%d %d %d", &n, &l, &k);
  scanf("%s", s);
  for (int i = 0; i < n * l; ++i) {
    ++cnt[(int)s[i]];
  }
  int now = 'a', from = 0;
  for (int i = 0; i < l; ++i) {
    for (int j = from; j < k; ++j) {
      while (cnt[now] <= 0) ++now;
      ans[j][i] = now;
      --cnt[now];
    }
    while (ans[from][i] != ans[k-1][i]) ++from;
  }
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < l; ++j) {
      if (ans[i][j]) continue;
      while (cnt[now] <= 0) ++now;
      ans[i][j] = now;
      --cnt[now];
    }
  }
  for (int i = 0; i < n; ++i) {
    ans[i][l] = 0;
    printf("%s\n", ans[i]);
  }
  return 0;
}
