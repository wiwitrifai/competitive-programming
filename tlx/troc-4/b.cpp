#include <bits/stdc++.h>

using namespace std;

int cnt[256], cnt2[256];

char key[] = "GKBGKB";
char s[55], t[55];

int main() {
  int n;
  scanf("%d", &n);
  scanf("%s %s", s, t);
  for (int i = 0; i < n; ++i)
    ++cnt[s[i]];
  for (int i = 0; i < n; ++i)
    ++cnt2[t[i]];
  int ans = 0;
  for (int i = 0; i < 3; ++i) {
    ans += min(cnt[key[i]], cnt2[key[i+1]]);
  }
  printf("%d\n", ans);
  return 0;
}