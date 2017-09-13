#include <bits/stdc++.h>

using namespace std;

int cnt[10], d[10];
int need[10];
char s[1020];

int main() {
  scanf("%s", s);
  int n = strlen(s);
  memset(cnt, 0, sizeof cnt);
  for (int i = 0; i < n; i++)
    cnt[s[i]-'0']++;
  if (n <= 3) {
    sort(s, s+n);
    int ans = 1111;
    do {
      if (s[0] == '0') continue;
      int now = 0;
      for (int i = 0; i < n; i++)
        now = now * 10 + s[i] - '0';
      if (now % 8) continue;
      ans = min(ans, now);
    } while (next_permutation(s, s+n));
    if (ans >= 1000)
      ans = -1;
    printf("%d\n", ans);
  }
  else {
    int ans = -1, back = -1;
    for (int i = 0; i < 1000; i++) {
      if (i % 8) continue;
      memset(need, 0, sizeof need);
      for (int j = 0, x = i; j < 3; j++, x /= 10) {
        need[x % 10]++;
        d[j] = x % 10;
      }
      bool ok = 1;
      int nz = 0;
      for (int j = 0; j < 10; j++) {
        if (need[j] > cnt[j]) ok = 0;
        if (j)
          nz += cnt[j] - need[j];
      }
      ok &= nz > 0;
      if (!ok) continue;
      sort(d, d+3);
      int cur = 0;
      for (int j = 0; j < 3; j++)
        cur = cur * 10 + d[j];
      if (back < cur) {
        ans = i;
        back = cur;
      }
    }
    if (ans == -1)
      printf("%d\n", ans);
    else {
      for (int j = 0, x = ans; j < 3; j++, x /= 10) {
        cnt[x % 10]--;
      }
      for (int i = 1; i < 10; i++) if (cnt[i]) {
        printf("%d", i);
        cnt[i]--;
        break;
      }
      for (int i = 0; i < 10; i++) {
        while (cnt[i] > 0) {
          printf("%d", i);
          cnt[i]--;
        }
      }
      printf("%03d\n", ans);
    }
  }
  return 0;
}