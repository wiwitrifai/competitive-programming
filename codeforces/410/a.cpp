#include <bits/stdc++.h>

using namespace std;

char s[100];

int main() {
  scanf("%s", s);
  int n = strlen(s);
  bool ispal = 1;
  for (int i = 0; i < n; i++)
    if (s[i] != s[n-1-i])
      ispal = 0;
  if ((n & 1) && ispal) {
    puts("YES");
    return 0;
  }
  for (int i = 0; i < n; i++) {
    if (s[i] != s[n-1-i]) {
      char bef = s[i];
      s[i] = s[n-1-i];
      bool cek = 1;
      for (int j = 0; j < n;j++) {
        if (s[j] != s[n-1-j])
          cek = 0;
      }
      if (cek) {
        puts("YES");
        return 0;
      }
      s[i] = bef;
    }
  }
  puts("NO");
  return 0;
}