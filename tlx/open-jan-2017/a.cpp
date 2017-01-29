#include <bits/stdc++.h>

using namespace std;

int main() {
  int n;
  scanf("%d", &n);
  int ans = 0, cnt = 0, now = 0;
  for (int i = 0; i < n; i++) {
    int m, k;
    scanf("%d %d", &m, &k);
    cnt++;
    ans = max(ans, cnt);
    now -= k;
    if (!now)
      cnt = 0;
    now += m;
  }
  ans = max(ans, cnt);
  printf("%d\n", ans * 10);
  return 0;
}