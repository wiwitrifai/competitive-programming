#include <bits/stdc++.h>

using namespace std;

char s[100];

int main() {
  scanf("%s", s);
  int n = strlen(s);
  while (n > 0 && s[n-1] == '0') n--;
  bool ok = 1;
  for (int i = 0, j = n-1; i < j; i++, j--)
    ok &= s[i] == s[j];
  puts(ok ? "YES" : "NO");
  return 0;
}