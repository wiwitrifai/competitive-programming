#include <bits/stdc++.h>

using namespace std;

int n, m, a[1000];

int main() {
  scanf("%d %d", &n, &m);
  for (int i = 0; i < n; i++)
    scanf("%d", a+i);
  int tot = 0;
  for (int i = 1; i < n; i++) {
    int d = m - a[i] - a[i-1];
    if (d < 0)
      d = 0;
    a[i] += d;
    tot += d;
  }
  printf("%d\n", tot);
  for (int i = 0; i < n; i++)
    printf("%d ", a[i]);
  printf("\n");

  return 0;
}