#include <bits/stdc++.h>

using namespace std;

const int N = 2e5 + 5;

char s[N], t[N];

int main() {
  scanf("%s", s);
  int n = strlen(s);
  int m = 0;
  for (int i = 0; i < n; ++i) {
    if (s[i] == 'a') continue;
    t[m++] = s[i];
  }
  if (m & 1) {
    puts(":(");
    return 0;
  }
  for (int i = 0; i < m/2; ++i) {
    if (t[i] != t[m/2 + i]) {
      puts(":(");
      return 0;
    }
  }
  m /= 2;
  for (int i = 0; i < m; ++i) {
    if (s[n-m+i] != t[i]) {
      puts(":(");
      return 0;
    }
  }
  s[n-m] = '\0';
  printf("%s\n", s);
  return 0;
}
