#include <bits/stdc++.h>

using namespace std;

const int N = 1e5 + 5;

char a[N], b[N];

int main() {
  scanf("%s %s", a, b);
  int n = strlen(a), m = strlen(b);
  int j = 0;
  char last = 0;
  int ans = 1;
  for (int i = 0; i < n; i++) {
    if (a[i] != last) {
      while(j < m && last == b[j]) j++;
      last = b[j];
    }
    if (a[i] != b[j] || j >= m) {
      ans = 0;
      break;
    }
    last = b[j];
    j++;
  }
  while (j < m && last == b[j]) j++;
  if (j < m)
    ans = 0;
  printf("%d\n", ans);
  return 0;
}