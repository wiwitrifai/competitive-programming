#include <bits/stdc++.h>

using namespace std;

const int N = 1e6 + 6;

char s[N];

int main() {
  int t;
  scanf("%d", &t);
  while (t--) {
    scanf("%s", s);
    int n = strlen(s);
    int open = 0, close = 0;
    bool found = 0;
    for (int i = n-1; i >= 0; i--) {
      if (s[i] == '(')
        open++;
      else
        close++;
      if (i < n-1 && s[i] == '(' && s[i+1] == ')' && close > open) {
        found = 1;
        swap(s[i], s[i+1]);
        close--; open--;
        for (int j = i + 2; j < n; j++) {
          if (open)
            s[j] = '(', open--;
          else
            s[j] = ')';
        }
        break;
      }
    }
    if (found)
      printf("%s\n", s);
    else
      puts("TIDAK ADA");
  }
  return 0;
}