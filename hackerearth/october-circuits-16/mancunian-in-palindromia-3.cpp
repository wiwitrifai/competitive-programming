#include <bits/stdc++.h>

using namespace std;

char s[55];

int main() {
  int n, l;
  scanf("%d %d", &n, &l);
  int ans = 0;
  while (n--) {
    scanf("%s", s);
    bool ispal = true;
    l = strlen(s);
    for (int k = 0; k < l-k-1; k++) if (s[k] != s[l-k-1]) {
      ispal = false;
      break;
    }
    for (int i = 0; i < l && !ispal; i++) {
      for (int j = i+1; j < l && !ispal; j++) {
        reverse(s+i, s+j+1);
        ispal = true;
        for (int k = 0; k < l-k-1; k++) if (s[k] != s[l-k-1]) {
          ispal = false;
          break;
        }
        for (int x = j+1; x < l && !ispal; x++) {
          for (int y = x+1; y < l && !ispal; y++) {
            reverse(s+x, s+y+1);
            ispal = true;
            for (int k = 0; k < l-k-1; k++) if (s[k] != s[l-k-1]) {
              ispal = false;
              break;
            }
            reverse(s+x, s+y+1);
          }
        }
        reverse(s+i, s+j+1);

      }
    }
    ans += ispal;
  }
  printf("%d\n", ans);
  return 0;
}