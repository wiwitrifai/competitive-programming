#include <bits/stdc++.h>

using namespace std;

const int N = 55;
char s[N];

int main() {
  scanf("%s", s);
  int n = strlen(s);
  bool ok = 0;
  for (int i = 0; i + 1 < n; i++)
    if (s[i] == 'A' && s[i+1] == 'C')
      ok = 1;
  puts(ok ? "Yes" : "No");
  return 0;
}