#include <bits/stdc++.h>

using namespace std;

const int N = 1024;
char s[N][10];
int main() {
  int n;
  scanf("%d", &n);
  bool found = false;
  for (int i = 0; i < n; i++) {
    scanf("%s", s[i]);
  }
  for (int i = 0; i < n; i++) {
    if (s[i][0] == 'O' && s[i][1] == 'O') {
      s[i][0] = s[i][1] = '+';
      found = true;
      break;
    }
    else if (s[i][3] == 'O' && s[i][4] == 'O') {
      s[i][3] = s[i][4] = '+';
      found = true;
      break;
    }
  }
  if (found) {
    puts("YES");
    for (int i = 0; i < n; i++)
      printf("%s\n", s[i]);
  }
  else
    puts("NO");

  return 0;
}