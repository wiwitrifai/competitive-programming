#include <bits/stdc++.h>

using namespace std;

const int N = 1e5 + 5, X = 1e9;

int cnt[N];
long long f[N];

int main() {
  int t;
  scanf("%d", &t);
  for (int i = 2; i < N; ++i) {
    f[i] = f[i-1] + 1LL * (i-1) * i / 2;
  }
  while (t--) {
    int n;
    scanf("%d", &n);
    int len = 1;
    while (f[len+1] <= n) ++len;
    cnt[1] = 0;
    for (int i = len; i > 1; --i) {
      cnt[i] = 0;
      while (n >= f[i]) {
        n -= f[i];
        ++cnt[i];
      }
    }
    int tot = len * 2;
    for (int i = 1; i <= len; ++i) {
      printf("13");
      for (int j = 0; j < cnt[i]; ++j)
        printf("7");
      tot += cnt[i];
    }
    printf("\n");
  }
  return 0;
}
