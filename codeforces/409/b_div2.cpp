#include <bits/stdc++.h>

using namespace std;

const int N = 105;
char x[N], y[N];

int main() {
  scanf("%s %s", x, y);
  int n = strlen(x), m = strlen(y);
  bool ok = 1;
  if (n != m) ok = 0;
  if (ok)
    for (int i = 0; i < n; i++) {
      if (y[i] > x[i])
        ok = 0;
    }
  if (ok)
    printf("%s\n", y);
  else
    puts("-1");
  return 0;
}