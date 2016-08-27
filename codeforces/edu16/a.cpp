#include <bits/stdc++.h>

using namespace std;

int main() {
  char s[5];
  scanf("%s", s);
  int a = s[0]-'a', b = s[1]-'1';
  a = min(a, 7-a);
  b = min(b, 7-b);
  if (a == 0 && b == 0)
    puts("3");
  else if (a == 0 || b == 0)
    puts("5");
  else
    puts("8");
  return 0;
}