#include <bits/stdc++.h>

using namespace std;

const int N = 2e6 +5;

int cnt[N];

int main() {
  int n, k;
  scanf("%d %d", &n, &k);
  for (int i = 0; i < n; i++) {
    int x;
    scanf("%d", &x);
    cnt[x]++;
  }
  sort(cnt, cnt + n + 1);
  reverse(cnt, cnt + n + 1);
  int ans = 0;
  for (int i = k; i <= n; i++)
    ans += cnt[i];
  printf("%d\n", ans);
  return 0;
}