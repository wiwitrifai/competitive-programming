#include <bits/stdc++.h>

using namespace std;

char s[500];
char y[] = "YAKI";

int main() {
  scanf("%s", s);
  int n = strlen(s);
  bool ok = 1;
  for (int i = 0; i < 4; i++)
    ok &= y[i] == s[i];
  puts(ok ? "Yes" : "No"); 
  return 0;
}