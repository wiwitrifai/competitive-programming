#include <bits/stdc++.h>

using namespace std;

const int N = 100;

char s[N], t[N];

int main() {
  scanf("%s %s", s, t);
  int n = strlen(s);
  int m = strlen(t);
  bool ok = 1;
  for (int i = 0; i + m <= n; ++i) {
    bool found = 1;
    for (int j = 0; j < m; ++j) {
      if (s[i+j] != t[j]) {
        found = 0;
      }
    }
    if (found)
      ok = 0;
  }
  if (ok) {
    puts("YA");
    printf("%s\n", s);
  }
  else
    puts("TIDAK");
  return 0;
}