#include <bits/stdc++.h>

using namespace std;


const int N = 1e6 + 6;
char s[N];

int main() {
  scanf("%s",s);
  int n = strlen(s);
  printf("%d\n", 2 * n - 1);
  for (int i = 1; i <= n; i++) {
    char c = s[i];
    s[i] = 0;
    printf("%s\n", s);
    s[i] = c;
  }
  for (int i = n-1; i > 0; i--) {
    char c = s[i];
    s[i] = 0;
    printf("%s\n", s);
    s[i] = c;
  } 

  return 0;
}