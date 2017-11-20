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
    int ansa = 0, ansb = 0;
    for (int i = 0, r = 0; i < n; i++) {
      if (s[i] == '.') continue;
      if (s[i] == 'A') ansa++;
      if (s[i] == 'B') ansb++;
      r = max(i+1, r);
      while (r < n && s[r] == '.') r++;
      if (s[i] == s[r]) {
        if (s[i] == 'A')
          ansa += r - i - 1;
        else if (s[i] == 'B')
          ansb += r - i - 1;
      }
    }
    printf("%d %d\n", ansa, ansb);
  }
  return 0;
}