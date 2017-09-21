#include <bits/stdc++.h>

using namespace std;

int main() {
  int n;
  scanf("%d", &n);
  int odd = 0, even = 0;
  for (int i = 0; i < n; i++) {
    int x;
    scanf("%d", &x);
    if (x & 1)
      odd++;
    else
      even++;
  }
  printf("%d\n", even * odd);
  return 0;
}