#include <bits/stdc++.h>

using namespace std;


int main() {
  int n, k, b;
  scanf("%d %d", &n, &k);
  int sum = 0;
  for (int i = 0; i < n; i++) {
    int c;
    scanf("%d", &c);
    if (i != k)
      sum += c;
  }
  scanf("%d", &b);
  sum /= 2;
  if (b == sum) {
    puts("Bon Appetit");
  }
  else {
    printf("%d\n", b - sum);
  }
  return 0;
}