#include <bits/stdc++.h>

using namespace std;

const int N = 2e5 + 5;

int a[N], b[N], pos[N], cnt[N];

int main() {
  int t = 1;
  while (t--) {
    int n;
    scanf("%d", &n);
    for (int i = 0; i < n; ++i) {
      scanf("%d", a+i);
      pos[a[i]] = i;
    }
    memset(cnt, 0, sizeof cnt);
    for (int i = 0; i < n; ++i) {
      scanf("%d", b+i);
      int rot = (pos[b[i]] - i) % n;
      if (rot < 0)
        rot += n;
      ++cnt[rot];
    }
    int ans = 1;
    for (int i = 0; i < n; ++i)
      ans = max(ans, cnt[i]);
    printf("%d\n", ans);
  }
  return 0;
}
