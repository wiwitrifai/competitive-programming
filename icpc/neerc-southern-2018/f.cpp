#include <bits/stdc++.h>

using namespace std;

const int N = 4e5 + 5;

long long a[4][N];
int cnt[4];

char str[4];

int main() {
  int n;
  scanf("%d", &n);
  memset(cnt, 0, sizeof cnt);
  for (int i = 0; i < n; ++i) {
    int x;
    scanf("%s %d", str, &x);
    int now = (str[0]-'0') * 2 + str[1] - '0';
    a[now][cnt[now]++] = x;
  }
  for (int i = 0; i < 4; ++i) {
    sort(a[i], a[i]+cnt[i]);
    reverse(a[i], a[i]+cnt[i]);
    long long sum = 0;
    for (int j = 0; j < cnt[i]; ++j) {
      int cur = a[i][j];
      a[i][j] = sum;
      sum += cur;
    }
    a[i][cnt[i]] = sum;
  }
  long long ans = 0;
  for (int d = min(cnt[0], cnt[3]); d >= 0; --d) {
    long long cur = a[3][cnt[3]] + a[0][d];
    int diff = cnt[3] - d;
    int l = cnt[1], r = cnt[2];
    r = min(r, l+diff);
    l = min(l, r+diff);
    cur += a[1][l] + a[2][r];
    ans = max(ans, cur);
  }
  printf("%lld\n", ans);
  return 0;
}