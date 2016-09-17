#include <bits/stdc++.h>

using namespace std;

char s[100005];
int main() {
  int t;
  scanf("%d", &t);
  while (t--) {
    scanf("%s", s);
    int n = strlen(s);
    bool ok = true;
    for (int i = 0; i < n - i; i++) {
      if (s[i] == '.' && s[n-i-1] == '.')
        s[i] = s[n-i-1] = 'a';
      else if (s[i] == '.')
        s[i] = s[n-i-1];
      else if (s[n-i-1] == '.')
        s[n-i-1] = s[i];
      else
        ok &= (s[i] == s[n-i-1]);
    }
    if (ok)
      printf("%s\n", s);
    else
      puts("-1");
  }

  return 0;
}