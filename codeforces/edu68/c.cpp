#include <bits/stdc++.h>

using namespace std;

const int N = 105;

char s[N], t[N], p[N];
int cnt[26];

int main() {
  int q;
  scanf("%d", &q);
  while (q--) {
    scanf("%s %s %s", s, t, p);
    memset(cnt, 0, sizeof cnt);
    int len = strlen(p);
    for (int i = 0; i < len; ++i)
      cnt[p[i]-'a']++;
    len = strlen(t);
    int n = strlen(s);
    int j = 0;
    bool ok = 1;
    for (int i = 0; i < len; ++i) {
      if (j < n && s[j] == t[i]) {
        ++j;
        continue;
      }
      int c = t[i] - 'a';
      if (cnt[c] <= 0) {
        ok = 0;
        break;
      }
      --cnt[c];
    }
    ok &= j == n;
    puts(ok ? "YES" : "NO");
  }
  return 0;
}
