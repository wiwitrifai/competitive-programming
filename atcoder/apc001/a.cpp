#include <bits/stdc++.h>

using namespace std;

int main() {
  int x, y;
  scanf("%d %d", &x, &y);
  if ((x % y) == 0)
    puts("-1");
  else {
    printf("%d\n", x);
  }

  return 0;
}