#include <bits/stdc++.h>

using namespace std;

int main() {
  int t;
  scanf("%d", &t);
  while (t--) {
    int a, b, c;
    scanf("%d %d %d", &a, &b, &c);
    if (a > c) swap(a, c);
    if (b > c) swap(b, c);
    int tot = a + b + c;
    if ((tot & 1) || (tot - c < c)) {
      puts("-1");
      continue;
    } 
    int x = c;
    int k = (a + b - c) / 2;
    printf("%d %d %d %d %d %d\n", 0, 0, x, 0, a-k, k);
  }
  return 0;
}