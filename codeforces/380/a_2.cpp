#include <bits/stdc++.h>

using namespace std;

char s[105];

int main() {
  int n;
  scanf("%d %s", &n, s);
  int state = 0;
  for (int i = 0; i < n; i++) {
    if (state == 1) {
      if (s[i] == 'g' && s[i+1] == 'o') {
        i++;
      }
      else
        state = 0;
    }
    if (state == 0) {
      if (s[i] == 'o' && s[i+1] == 'g' && s[i+2] == 'o') {
        state = 1;
        printf("***");
        i += 2;
      }
    }
    if (!state)
      printf("%c", s[i]);
  }
  printf("\n");
  return 0;
}