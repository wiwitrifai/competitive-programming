#include <bits/stdc++.h>

using namespace std;

const int N = 2018;

char s[N];

int main() {
  int n, p;
  scanf("%d %d %s", &n, &p, s);
  for (int i = 0; i < n; ++i) {
    if (s[i] != '.') continue;
    if (i >= p) {
      s[i] = '1' + '0' - s[i-p];
    }
    if (i+p < n) {
      if (s[i+p] != '.') {
        s[i] = '1' + '0' - s[i+p];        
      }
    }
    if (s[i] == '.') s[i] = '0';
  }
  bool ok = 0;
  for (int i = p; i < n; ++i)
    if (s[i-p] != s[i])
      ok = 1;
  if (ok)
    printf("%s\n", s);
  else
    puts("No");
  return 0;
}