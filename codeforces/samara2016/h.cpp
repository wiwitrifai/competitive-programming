#include <bits/stdc++.h>

using namespace std;

const int N = 5e5 + 5;

char s[N];

int main() {
  scanf("%s", s);
  int n = strlen(s);
  int a, b;
  a = 0; b = 0;
  for (int i = 0; i < n; i++) {
    a += s[i] == '(';
    b += s[i] == ')';
  }
  if (n & 1) {
    puts("Impossible");
    return 0;
  }
  else {
    for (int i = 0; i < n; i++) {
      if (s[i] == '?') {
        if (a < n/2) {
          s[i] = '(';
            a++;
        }
        else
          s[i] = ')';
      }
    }
  }
  int cnt = 0;
  for (int i = 0; i < n; i++) {
    if (s[i] == '(')
      cnt++;
    else
      cnt--;
    if (cnt < 0) {
      puts("Impossible");
      return 0;
    }
  } 
  printf("%s\n", s);
  return 0;
}