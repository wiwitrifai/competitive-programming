#include <bits/stdc++.h>

using namespace std;

const int N = 3e5 + 6;
char s[N];
char h[] = "happiness";

int main() {
  scanf("%s", s);
  int n = strlen(s), m = strlen(h);
  int ans = 0, ans2 = 0, cnt = 0;
  for (int i = 0; i + m <= n; i++) {
    bool ok = 1;
    for (int j = 0; j < m; j++) {
      if (s[i+j] != h[j]) {
        ok = 0;
        break;
      } 
    }
    if (ok) {
      if (cnt)
        ans2 = i+1;
      else
        ans = i;
      cnt++;
    }
  }
  if (cnt <= 2) {
    puts("YES");
    if (cnt == 0) {
      for (int i = 0; i+1 < n; i++) {
        swap(s[i], s[i+1]);
        bool ok = 1;
        for (int j = max(0, i-m+1); j <= min(i+1, n-m); j++) {
          ok = 0;
          for (int z = 0; z < m; z++)
            if (s[j+z] != h[z]) {
              ok = 1;
              break;
            }
          if (!ok)
            break;
        }
        if (ok) {
          ans = i, ans2 = i+1;
          break;
        }
      }
    }
    else if (cnt == 1) {
      ans2 = ans + 1;
    }
    printf("%d %d\n", ans+1, ans2+1);
  }
  else
    puts("NO");
  return 0;
}