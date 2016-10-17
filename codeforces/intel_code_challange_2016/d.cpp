#include <bits/stdc++.h>

using namespace std;

const int N = 1e5 + 6;

char s[N];
int m, cnt[256];

int main() {
  scanf("%d %s", &m, s);
  int n = strlen(s);
  for (int i = 0; i < n; i++) {
    cnt[s[i]]++;
  }
  m--;
  char ans = 'a';
  int occ = 0, last = -1;
  while (ans <= 'z') {
    int less = 0, eq = 0;
    bool ok = true;
    occ = 0;
    for (int i = 0; i < n; i++) {
      if (s[i] == ans) {
        eq++;
        last = i;
      }
      else if (s[i] < ans)
        less++;
      if (i >= m) {
        if (!less) {
          if (eq) {
            occ++;
            eq--;
            less++;
            s[last]--;
          }
          else {
            ok = false;
            break;
          }
        }
      }
      if (i >= m) {
        if (s[i-m] == ans)
          eq--;
        else if (s[i-m] < ans)
          less--;
      }
    }
    if (ok) {
      break;
    }
    ans++;
  }
  for (char i = 'a'; i < ans; i++) {
    for (int j = 0; j < cnt[i]; j++)
      printf("%c", i);
  }
  if (ans <= 'z') {
    for (int j = 0; j < occ; j++)
      printf("%c", ans);
  }
  printf("\n");
  return 0;
}