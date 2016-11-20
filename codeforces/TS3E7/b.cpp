#include <bits/stdc++.h>

using namespace std;

const int N = 200;

char s[N];

int main() {
  int t;
  scanf("%d", &t);
  while (t--) {
    scanf("%s", s);
    int n = strlen(s);
    if (n == 1)
      puts("YES");
    else if (n & (n-1))
      puts("NO");
    else {
      bool ok = true;
      for (int i = 0; i < n; i += 2) {
        ok &= (s[i] == 'P' || s[i+1] == 'P');
      }
      puts(ok ? "YES" : "NO");
    }
  }
  return 0;
}