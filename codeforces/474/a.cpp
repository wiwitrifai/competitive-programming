#include <bits/stdc++.h>

using namespace std;

const int N = 1e5 + 5;

char s[N];

int main() {
  scanf("%s", s);
  int len = strlen(s);
  int i = 0;
  int a = 0, b = 0, c = 0;
  while (i < len && s[i] == 'a') ++i, ++a;
  while (i < len && s[i] == 'b') ++i, ++b;
  while (i < len && s[i] == 'c') ++i, ++c;
  if (i != len || (c != a && c != b) || a == 0 || b == 0)
    puts("NO");
  else puts("YES");
  return 0;
}