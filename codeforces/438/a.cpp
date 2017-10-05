
#include <bits/stdc++.h>

using namespace std;

const int N = 1e3 + 5;
char s[N][4];
char p[4];

int main() {
  int n;
  scanf("%s %d", p, &n);
  bool ok = 0;
  for (int i = 0; i < n; i++) {
    scanf("%s", s[i]);
    if (s[i][0] == p[0] && s[i][1] == p[1])
      ok = 1;
  }
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      if (s[i][1] == p[0] && s[j][0] == p[1])
        ok = 1;
    }
  }
  puts(ok ? "YES" : "NO");
  return 0;
}