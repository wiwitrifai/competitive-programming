#include <bits/stdc++.h>

using namespace std;

const int N = 1e5 + 5;

char s[N];

int main() {
  int t;
  scanf("%d", &t);
  while (t--) {
    scanf("%s", s);
    int n = strlen(s);
    int f = n, e = -1;
    for (int i = 0; i < n; i++)
      if (s[i] == '1')
        f = min(f, i), e = max(e, i);
    if (f > e)
      puts("NO");
    else {
      bool ok = 1;
      for (int i = f; i <= e; i++) if (s[i] != '1')
        ok = 0;
      puts(ok ? "YES" : "NO");
    }
  }
  return 0;
}