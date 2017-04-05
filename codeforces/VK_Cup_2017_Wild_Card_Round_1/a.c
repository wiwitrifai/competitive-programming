#include "stdio.h"


const int N = 2e5 + 5;

int n;
long long a, b;
char s[200100];
int p, c, i, j;
long long ans, cur;

int main() {
  scanf("%d %I64d %I64d", &n, &a, &b);
  scanf("%s", s);
  p = c = 0;
  for (i = 0; i < n; i++) {
    p += s[i] == '1';
    c += s[i] == '0';
  }
  ans = -1;
  for (i = 1; i <= p; i++) {
    cur = a * i;
    long long x = (n-i)/i, z = (n-i) % i;
    cur += x * x * b * (i-z);
    x++;
    cur += x * x * b * z;
    if (ans == -1 || ans > cur)
      ans = cur;
  }
  printf("%I64d\n", ans);
  return 0;
}