#include <bits/stdc++.h>

using namespace std;

const int N = 107;

char s[N][N];
int a[N], len[N];
bool del[N];

char ans[N];

int main() {
  int n, m;
  scanf("%d %d", &n, &m);
  for (int i = 0; i < n; i++) {
    scanf("%s", s[i]);
    len[i] = strlen(s[i]);
  }
  int slen = -1;
  for (int i = 0; i < m; i++) {
    scanf("%d", a+i), a[i]--; 
    del[a[i]] = 1;
    if (slen == -1)
      slen = len[a[i]];
    if (slen != len[a[i]])
      slen = -2;
  }
  if (slen < 0) {
    puts("No");
    return 0;
  }
  memset(ans, 0, sizeof ans);
  for (int i = 0; i < slen; i++) {
    char now = 0;
    for (int j = 0; j < m; j++) {
      if (!now)
        now = s[a[j]][i];
      if (now != s[a[j]][i]) {
        now = 0;
        break;
      }
    }
    ans[i] = now ? now : '?';
  }
  bool ok = true;
  for (int i = 0; i < n; i++) if (!del[i]) {
    if (len[i] != slen)
      continue;
    bool match = true;
    for (int j = 0; j < slen; j++) {
      if (ans[j] == '?')
        continue;
      match &= ans[j] == s[i][j];
    }
    if (match) {
      ok = false;
      break;
    }
  }
  if (ok) {
    puts("Yes");
    printf("%s\n", ans);
  }
  else
    puts("No");
  return 0;
}