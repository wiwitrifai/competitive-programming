#include <bits/stdc++.h>

using namespace std;

char s[100024];

int main() {
  int t;
  scanf("%d", &t);
  while (t--) {
    scanf("%s", s);
    int n = strlen(s);
    int a = 0;
    for (int i = 0; i < n; i++)
      a += (s[i] == '1');
    puts((a == 1 || a == n-1) ? "Yes" : "No");
  }
  return 0;
}