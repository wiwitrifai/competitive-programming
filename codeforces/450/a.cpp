#include <bits/stdc++.h>

using namespace std;

int main() {
  int n;
  scanf("%d", &n);
  int le = 0, ri = 0;
  for (int i = 0; i < n; ++i) {
    int x;
    scanf("%d %*d", &x);
    if (x < 0)
      le++;
    else
      ri++;
  }
  if (min(le, ri) <= 1) {
    puts("Yes");
  }
  else
    puts("No");
  return 0;
}