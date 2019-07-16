#include <bits/stdc++.h>

using namespace std;

int main() {
  int n, x, y;
  scanf("%d %d %d", &n, &x, &y);
  int sum = abs(x)+abs(y);
  if (sum > n) {
    puts("-1");
    return 0;
  }
  int a, b, c, d;
  a = b = c = d = 0;
  if (x < 0)
    d = -x;
  else
    b = x;
  if (y < 0)
    c = -y;
  else
    a = y;
  int sisa = n - sum;
  if (sisa & 1) {
    puts("-1");
    return 0;
  }
  sisa /= 2;
  a += sisa;
  c += sisa;
  printf("%d %d %d %d\n", a, b, c, d);
  return 0;
}
